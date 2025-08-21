/*!
 * \file     ACT_UpdateFaults.c
 * \brief    Brief description of file content
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

/* ---- Includes ---- */
#include "ACT.h"
#include "ACTupdat.h"
#include "CNV.h"
#include "CBUs.h"
#include "PAR.h"
#include "CTB.h"
#include "PWB.h"
#include "Dio.h"
/* ---- Defines ---- */

#define TEMP_HYSTERESIS 5U

static struct ACT_errorsTimeouts
{
    uint32_t overTemperature;
    uint32_t addressChanged;
    uint32_t hvRelayNok;
    uint32_t lvRelayNok;
    uint32_t discretIoError;
    uint32_t hvVoltMeas;
    uint32_t lvVoltMeas;
    uint32_t overCurrent;
    uint32_t overVolt;
    uint32_t relayCmdWarning;
} errorsTimeouts = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

/* ---- Global variables ---- */

/* ---- External functions ---- */

/* ---- Static variables ---- */

static ACT_TempSeverity cometi_severityLevel = ACT_TEMPNOTIF_NOMINAL;
static ACT_TempSeverity bbaux_severityLevel = ACT_TEMPNOTIF_NOMINAL;

/* ---- Static functions ---- */
static void act_UpdateMasks(void);
static void act_CheckCanLossErrors(void);
static void act_CheckAddressChanged(void);
static void act_CheckTemperture(void);
static ACT_TempSeverity act_evaluateTempSeverity(
        uint32_t temp, ACT_TempSeverity currentSeverity, uint32_t lowTheshold,
        uint32_t medTheshold, uint32_t highTheshold);
static void act_CheckUnkownCometiUnit(void);
static void act_CheckRelayCmd(void);
static void act_CheckRelayNokError(void);
static void act_CheckVoltageMeas(void);
static void act_CheckOverCurrent(void);
static void act_CheckDiscreteIOErrors(void);
static void act_CheckPrechargeError(void);
static void act_CheckParamError(void);
static void act_CheckOverVolt(void);
static void act_CheckAutoCnvEnd(void);
static void act_CheckRegulationRequestNok(void);
static void act_CheckMaintCondition(void);
static void act_CheckUnavailableCOMETi(void);
static void act_CheckWarnings(void);
static void act_CheckPowerCoreError(void);
static void act_CheckErrors(void);
static void act_UpdateFaultOrigin(void);
static void act_UpdateFaultSeverity(void);
static boolean act_UpdateErrorTimeOut(boolean errorFlag, uint32_t *errorTimeout);

/*!     \brief Periodic 1ms Task of Activity Management Module
 *       \param none
 *       \return none
 */
void ACT_UpdateFaults(void)
{

    /* If the error reset has been requested */
    /* Then reevaluate all the errors */
    if (COM_flags.moduleFlags.status.flags.errorResetRequest == true)
    {
        ACT_errors.fastPowerDown.all = 0;
        ACT_errors.slowPowerDown.all = 0;
        ACT_errors.warnings.all = 0;
    }
    else
    {
        // DO nothing all the errors must remain active until the error reset is requested
    }
    /* Update the Error and warning masks depending on COM request and FSM mode */
    act_UpdateMasks();
    // Check Errors and Warnings
    act_CheckWarnings();
    act_CheckErrors();
    // Checking the source of the Faults and their severity
    act_UpdateFaultOrigin();
    act_UpdateFaultSeverity();
}

/*!     \brief Update Masks depending on available data and FSM mode
 *       \param none
 *       \return none
 */
static void act_UpdateMasks(void)
{
    /* Apply user limitation after new config */

    /* Set the masks depending on current FSM state */
    if ((FSM_mode == FSM_MODE_INIT) || (FSM_mode == FSM_MODE_PBIT)
            || (FSM_mode == FSM_MODE_SHUTDOWN))
    {
        ACT_errors.fastPowerDownMask.all = 0;
        ACT_errors.slowPowerDownMask.all = 0;
        ACT_errors.warningsMask.all = 0;
    }
    else
    {
        uint32_t fastPowerDownMask =
                PAR_paramConfig[PAR_CRITICAL_ERRORS_MASK].realVal.unsignedVal;
        uint32_t slowPowerDownMask =
                PAR_paramConfig[PAR_OPERATING_ERRORS_MASK].realVal.unsignedVal;
        uint32_t warningsMask =
                PAR_paramConfig[PAR_WARNINGS_MASK].realVal.unsignedVal;
        ACT_errors.fastPowerDownMask.all = (uint16_t) fastPowerDownMask;
        ACT_errors.slowPowerDownMask.all = slowPowerDownMask;
        ACT_errors.warningsMask.all = (uint16_t) warningsMask;
    }
}

/*!     \brief Check Can Loss of Communication error
 *       \param none
 *       \return none
 */
static void act_CheckCanLossErrors(void)
{
    /* can loss error is raised when
     * canLoss is received from the COMETi means BB Aux can't send periodic msgs (should never happen)
     * internalCanLoss is detected means COMETi is not sending periodic msgs (should never happen)
     * controlCanLoss is detected means Supervisor is not sending periodic msgsACT_errors.fastPowerDown.error.limitedCapacity = COM_flags.moduleFlags.faults.flags.canCComLoss;
     */
    ACT_errors.slowPowerDown.error.controlCanLoss =
            COM_flags.moduleFlags.faults.flags.canCComLoss;
    ACT_errors.slowPowerDown.error.limitedCapacity |= // we do an Algorithmic Or beceause the Limited Capacity might have been actived already
            COM_flags.moduleFlags.faults.flags.canIComLoss;
}

/*!     \brief update the AddressChanged error
 *       \param none
 *       \return none
 */
static void act_CheckAddressChanged(void)
{
    if (CTB_Flags.faults.flags.addressChanged == true)
    {
        if (errorsTimeouts.addressChanged < ACT_ERRORS_TIMEOUT)
        {
            errorsTimeouts.addressChanged++;
        }
        else
        {
            // Nothing to do the timeout is reseted when the error is inactive
        }
    }
    else
    {
        errorsTimeouts.addressChanged = 0;
    }

    if (errorsTimeouts.addressChanged >= ACT_ERRORS_TIMEOUT)
    {
        ACT_errors.fastPowerDown.error.addressChanged = true;
    }
    else
    {
        // Nothing to do let the error active until there's an error reset request
    }
}

/*!     \brief update the temp errors and warnings
 *       \param none
 *       \return none
 */
static void act_CheckTemperture(void)
{
    // getting the parameters for the bb-aux and the cometi temp
    uint32_t bbAUX_low_Threshold =
            PAR_paramConfig[PAR_BBAUX_TEMP_THRESH_GENTLEWARN].realVal.unsignedVal;
    uint32_t bbAUX_med_Threshold =
            PAR_paramConfig[PAR_BBAUX_TEMP_THRESH_URGENTWARN].realVal.unsignedVal;
    uint32_t bbAUX_high_Threshold =
            PAR_paramConfig[PAR_BBAUX_TEMP_THRESH_CRITICALERR].realVal.unsignedVal;

    uint32_t powerCore_low_Threshold =
            PAR_paramConfig[PAR_POWERCORE_TEMP_THRESH_GENTLEWARN].realVal.unsignedVal;
    uint32_t powerCore_med_Threshold =
            PAR_paramConfig[PAR_POWERCORE_TEMP_THRESH_URGENTWARN].realVal.unsignedVal;
    uint32_t powerCore_high_Threshold =
            PAR_paramConfig[PAR_POWERCORE_TEMP_THRESH_CRITICALERR].realVal.unsignedVal;
    // getting the max cometi temp
    uint32_t maxAbmientTemp = 0;
    if (CNV_powercoreUnitTable[0].tempMeas.temp8
            > CNV_powercoreUnitTable[1].tempMeas.temp8)
    {
        maxAbmientTemp = CNV_powercoreUnitTable[0].tempMeas.temp8;
    }
    else
    {
        maxAbmientTemp = CNV_powercoreUnitTable[1].tempMeas.temp8;
    }
    // getting the severity on each temp
    bbaux_severityLevel = act_evaluateTempSeverity(PWB_measures.Hv_Temp,
            bbaux_severityLevel, bbAUX_low_Threshold, bbAUX_med_Threshold,
            bbAUX_high_Threshold);
    cometi_severityLevel = act_evaluateTempSeverity(maxAbmientTemp,
            cometi_severityLevel, powerCore_low_Threshold,
            powerCore_med_Threshold, powerCore_high_Threshold);
    // combine and get the final severity
    ACT_tempSeverity =
            (bbaux_severityLevel > cometi_severityLevel) ? bbaux_severityLevel :
                    cometi_severityLevel;
    // setting the warnings and the errors based on the final severity
    switch (ACT_tempSeverity)
    {
        case ACT_TEMPNOTIF_CRITICALTEMP:
            ACT_errors.fastPowerDown.error.overTemperature = true;
            ACT_errors.warnings.warningsFlags.tempUrgentReminder = false;
            ACT_errors.warnings.warningsFlags.tempGentleReminder = false;
            break;
        case ACT_TEMPNOTIF_URGENTWARN:
            ACT_errors.warnings.warningsFlags.tempUrgentReminder = true;
            ACT_errors.warnings.warningsFlags.tempGentleReminder = false;
            break;
        case ACT_TEMPNOTIF_GENTLEWARN:
            ACT_errors.warnings.warningsFlags.tempGentleReminder = true;
            ACT_errors.warnings.warningsFlags.tempUrgentReminder = false;
            break;
        default:
            ACT_errors.warnings.warningsFlags.tempUrgentReminder = false;
            ACT_errors.warnings.warningsFlags.tempGentleReminder = false;
            break;
    }
}

static ACT_TempSeverity act_evaluateTempSeverity(
        uint32_t temp, ACT_TempSeverity currentSeverity, uint32_t lowTheshold,
        uint32_t medTheshold, uint32_t highTheshold)
{
    ACT_TempSeverity returnValue = currentSeverity;
    switch (currentSeverity)
    {
        case ACT_TEMPNOTIF_NOMINAL:
            if (temp > lowTheshold)
            {
                returnValue = ACT_TEMPNOTIF_GENTLEWARN;
            }
            break;
        case ACT_TEMPNOTIF_GENTLEWARN:
            if (temp > medTheshold)
            {
                returnValue = ACT_TEMPNOTIF_URGENTWARN;
            }
            else if (temp < lowTheshold - TEMP_HYSTERESIS)
            {
                returnValue = ACT_TEMPNOTIF_NOMINAL;
            }
            break;
        case ACT_TEMPNOTIF_URGENTWARN:
            if (temp > highTheshold)
            {
                returnValue = ACT_TEMPNOTIF_CRITICALTEMP;
            }
            else if (temp < medTheshold - TEMP_HYSTERESIS)
            {
                returnValue = ACT_TEMPNOTIF_GENTLEWARN;
            }
            break;
        case ACT_TEMPNOTIF_CRITICALTEMP:
            if (temp < highTheshold - TEMP_HYSTERESIS)
            {
                returnValue = ACT_TEMPNOTIF_URGENTWARN;
            }
            break;
        default:
            break;
    }

    return returnValue;
}

/*!     \brief update the relay error
 *       \param none
 *       \return none
 */
static void act_CheckRelayNokError(void)
{
// get the error fromthe PWB flags

    if (PWB_Flags.faults.flags.hvRelayNok == true)
    {
        if (errorsTimeouts.hvRelayNok < ACT_ERRORS_TIMEOUT)
        {
            errorsTimeouts.hvRelayNok++;
        }
        else
        {
            // Nothing to do the timeout is reseted when the error is inactive
        }
    }
    else
    {
        errorsTimeouts.hvRelayNok = 0;
    }

    if (errorsTimeouts.hvRelayNok >= ACT_ERRORS_TIMEOUT)
    {
        ACT_errors.fastPowerDown.error.hvCouplerNok = true;
    }
    else
    {
        // Nothing to do let the error active until there's an error reset request
    }

    if (PWB_Flags.faults.flags.lvRelayNok == true)
    {
        if (errorsTimeouts.lvRelayNok < ACT_ERRORS_TIMEOUT)
        {
            errorsTimeouts.lvRelayNok++;
        }
        else
        {
            // Nothing to do the timeout is reseted when the error is inactive
        }
    }
    else
    {
        errorsTimeouts.lvRelayNok = 0;
    }

    if (errorsTimeouts.lvRelayNok >= ACT_ERRORS_TIMEOUT)
    {
        ACT_errors.fastPowerDown.error.LvPrechargeNok = true;
    }
    else
    {
        // Nothing to do let the error active until there's an error reset request
    }
}

/*!     \brief update the Voltage Meas error
 *       \param none
 *       \return none
 */
static void act_CheckVoltageMeas(void)
{

    if (PWB_Flags.faults.flags.hvVoltMeas == true)
    {
        if (errorsTimeouts.hvVoltMeas < ACT_ERRORS_TIMEOUT)
        {
            errorsTimeouts.hvVoltMeas++;
        }
        else
        {
            // Nothing to do the timeout is reseted when the error is inactive
        }
        ACT_errors.warnings.warningsFlags.hvVoltageMeas = true;
    }
    else
    {
        errorsTimeouts.hvVoltMeas = 0;
        ACT_errors.warnings.warningsFlags.hvVoltageMeas = false; // warnings are volatile
    }

    if (errorsTimeouts.hvVoltMeas >= ACT_ERRORS_TIMEOUT)
    {
        ACT_errors.fastPowerDown.error.hvVoltageMeas = true;
    }
    else
    {
        // Nothing to do let the error active until there's an error reset request
    }

    if (PWB_Flags.faults.flags.lvVoltMeas == true)
    {
        if (errorsTimeouts.lvVoltMeas < ACT_ERRORS_TIMEOUT)
        {
            errorsTimeouts.lvVoltMeas++;
        }
        else
        {
            // Nothing to do the timeout is reseted when the error is inactive
        }
        ACT_errors.warnings.warningsFlags.lvVoltageMeas = true; // raise the warning in the first wrong measurement TRO_50073_50147_001_TRS_0152
    }
    else
    {
        errorsTimeouts.lvVoltMeas = 0;
        ACT_errors.warnings.warningsFlags.lvVoltageMeas = false; // warnings are volatile
    }

    if (errorsTimeouts.lvVoltMeas >= ACT_ERRORS_TIMEOUT)
    {
        ACT_errors.fastPowerDown.error.lvVoltageMeas = true; // raise the error when the error is always active (there's many wrong measurments) TRO_50073_50147_001_TRS_0152
    }
    else
    {
        // Nothing to do let the error active until there's an error reset request
    }
}

/*!     \brief update the overCurrent error
 *       \param none
 *       \return none
 */
static void act_CheckOverCurrent(void)
{
    uint32_t overCurrentConfirmationTime =
            PAR_paramConfig[PAR_CURRENTMEAS_CONFIRMATION_TIME].realVal.unsignedVal;
    if (PWB_Flags.faults.flags.overCurrent == true)
    {
        if (errorsTimeouts.overCurrent < overCurrentConfirmationTime)
        {
            errorsTimeouts.overCurrent++;
        }
        else
        {
            // Nothing to do the timeout is reseted when the error is inactive
        }
    }
    else
    {
        errorsTimeouts.overCurrent = 0;
    }

    if (errorsTimeouts.overCurrent >= overCurrentConfirmationTime)
    {
        ACT_errors.fastPowerDown.error.overCurrent = true;
    }
    else
    {
        // Nothing to do let the error active until there's an error reset request
    }
}

/*!     \brief update the DSI DSO error
 *       \param none
 *       \return none
 */
static void act_CheckDiscreteIOErrors(void)
{
    if (CTB_Flags.faults.flags.discretIOError == true)
    {
        if (errorsTimeouts.discretIoError < ACT_ERRORS_TIMEOUT)
        {
            errorsTimeouts.discretIoError++;
        }
        else
        {
            // Nothing to do the timeout is reseted when the error is inactive
        }
    }
    else
    {
        errorsTimeouts.discretIoError = 0;
    }

    if (errorsTimeouts.discretIoError >= ACT_ERRORS_TIMEOUT)
    {
        ACT_errors.fastPowerDown.error.discreteIOsError = true;
    }
    else
    {
        // Nothing to do let the error active until there's an error reset request
    }
}

static void act_CheckPrechargeError(void)
{
    ACT_errors.fastPowerDown.error.prechargeError =
            PWB_Flags.status.flags.prechargeAborted;
}

static void act_CheckParamError(void)
{
    if (PAR_paramReq.lastError > 0)
    {
        ACT_errors.fastPowerDown.error.parameterError = true;
    }
    else
    {
        // do nothing critical error shall be assessed and reseted before clearing the flag
    }
}

/*!     \brief update the unknown COMETi error
 *       \param none
 *       \return none
 */
static void act_CheckUnkownCometiUnit(void)
{
    ACT_errors.warnings.warningsFlags.unknownPowercoreUnit =
            COM_flags.moduleFlags.faults.flags.unkownCOMETi;
}

/*!     \brief update the relay CMD error
 *       \param none
 *       \return none
 */
static void act_CheckRelayCmd(void)
{
    if (PWB_Flags.faults.flags.relayCmdWarning == true)
    {
        if (errorsTimeouts.relayCmdWarning < ACT_ERRORS_TIMEOUT)
        {
            errorsTimeouts.relayCmdWarning++;
        }
        else
        {
            // Nothing to do the timeout is reseted when the error is inactive
        }
    }
    else
    {
        errorsTimeouts.relayCmdWarning = 0;
    }

    if (errorsTimeouts.relayCmdWarning >= ACT_ERRORS_TIMEOUT)
    {
        ACT_errors.warnings.warningsFlags.relayCommandWarning = true;
    }
    else
    {
        // Nothing to do let the error active until there's an error reset request
    }
}

/*!     \brief update the Over Voltage error
 *       \param none
 *       \return none
 */
static void act_CheckOverVolt(void)
{
// get the error from the PWB flags
    uint32_t overVoltConfirmationTime =
            PAR_paramConfig[PAR_VOLTAGEMEAS_CONFIRMATION_TIME].realVal.unsignedVal;
    if (PWB_Flags.faults.flags.overVolt == true)
    {
        if (errorsTimeouts.overVolt < overVoltConfirmationTime) // check if we still in the timeout
        {
            errorsTimeouts.overVolt++;
        }
        else
        {
            // Nothing to do the timeout is reseted when the error is inactive
        }
    }
    else
    {
        errorsTimeouts.overVolt = 0; // reset the counter is there's no error
    }

    if (errorsTimeouts.overVolt >= overVoltConfirmationTime)
    {
        ACT_errors.fastPowerDown.error.overVoltage = true;
    }
    else
    {
        /* Nothing to do let the error be active until an error reset is requested */
    }

}

/*!     \brief update the Auto stop error
 *       \param none
 *       \return none
 */
static void act_CheckAutoCnvEnd(void)
{
    ACT_errors.warnings.warningsFlags.autonomousBoostEnd =
            FSM_errors.autonomousBoostEnd;
    ACT_errors.warnings.warningsFlags.autonomousBuckEnd =
            FSM_errors.autonomousBuckEnd;
}

static void act_CheckRegulationRequestNok(void)
{
    ACT_errors.warnings.warningsFlags.regulationRequestNOK = !CNV_regulationReq.reqAccepted;
}

/*!     \brief update the maintenance Condition error
 *       \param none
 *       \return none
 */
static void act_CheckMaintCondition(void)
{
    ACT_errors.warnings.warningsFlags.bbauxInMaintenanceMode =
            FSM_errors.bbAuxInMaintMode;
    ACT_errors.warnings.warningsFlags.maintenanceConditionNotMet =
            FSM_errors.EnterMaintModeNotMet;
}

static void act_CheckUnavailableCOMETi(void)
{
    ACT_errors.slowPowerDown.error.limitedCapacity =
            PWB_Flags.faults.flags.unavailableCometi;
}

/*!     \brief update the warnings
 *       \param none
 *       \return none
 */
static void act_CheckWarnings(void)
{
// check if there's any powercore warning and raise the internalWarnings flag
    boolean tempWarning = false;
    for (size_t index = 0; index < CNV_POWERCORE_UNITS_NB; index++)
    {
        tempWarning |=
                CNV_powercoreUnitTable[index].flags.moduleFlags.warns.all;
    }
    ACT_errors.warnings.warningsFlags.internalWarning = tempWarning;

    act_CheckTemperture();
    act_CheckMaintCondition();
    act_CheckUnkownCometiUnit();
    act_CheckRelayCmd();
    act_CheckOverVolt();
    act_CheckAutoCnvEnd();
    act_CheckRegulationRequestNok();
// Apply the warnings mask
    ACT_errors.warnings.all &= ACT_errors.warningsMask.all;
}

/*!     \brief update the errors and warnings of the COMETi units
 *       \param none
 *       \return none
 */
static void act_CheckPowerCoreError(void)
{
// check if there's any powercore error and raise the limitedCapacity flag
    boolean checkCriticalCapacity = false;
    boolean checkVoltageShourceSide = false;
    for (size_t index = 0; index < CNV_POWERCORE_UNITS_NB; index++)
    {
        if (CNV_powercoreUnitTable[index].flags.moduleFlags.faults.all > 3)
        {
            checkCriticalCapacity = true;
        }
        else if (CNV_powercoreUnitTable[index].flags.moduleFlags.faults.all
                != 0)
        {
            checkVoltageShourceSide = true;
        }
        else
        {
            // nothing there's no error in the power core
        }
    }
    if (checkCriticalCapacity == true)
    {
        ACT_errors.fastPowerDown.error.criticalCapacity = true;
    }
    else
    {
        // Nothing to do critical capacity stays up till it's reseted
    }

    ACT_errors.warnings.warningsFlags.noVoltageOnSourceSide =
            checkVoltageShourceSide; // warnings are volatile
}

/*!     \brief update the errors
 *       \param none
 *       \return none
 */
static void act_CheckErrors(void)
{
    act_CheckUnavailableCOMETi();
    act_CheckCanLossErrors();
    act_CheckPowerCoreError();
    act_CheckAddressChanged();
    act_CheckRelayNokError();
    act_CheckVoltageMeas();
    act_CheckOverCurrent();
    act_CheckDiscreteIOErrors();
    act_CheckPrechargeError();
    act_CheckParamError();

// Apply the error mask
    ACT_errors.slowPowerDown.all &= ACT_errors.slowPowerDownMask.all;
    ACT_errors.fastPowerDown.all &= ACT_errors.fastPowerDownMask.all;
    ACT_errors.warnings.all &= ACT_errors.warningsMask.all;
}

/*!     \brief update the errors and warnings origin (Which Cometi unit)
 *       \param none
 *       \return none
 */
static void act_UpdateFaultOrigin(void)
{

    if ((CNV_powercoreUnitTable[0].flags.moduleFlags.faults.all != 0)
            || (CNV_powercoreUnitTable[0].flags.moduleFlags.warns.all != 0))
    {
        ACT_errors.origin.originFlag.powerCore1 = true;
    }
    else
    {
        ACT_errors.origin.originFlag.powerCore1 = false;
    }

    if ((CNV_powercoreUnitTable[1].flags.moduleFlags.faults.all != 0)
            || (CNV_powercoreUnitTable[1].flags.moduleFlags.warns.all != 0))
    {
        ACT_errors.origin.originFlag.powerCore2 = true;
    }
    else
    {
        ACT_errors.origin.originFlag.powerCore2 = false;
    }
}

static void act_UpdateFaultSeverity(void)
{
    if (ACT_errors.fastPowerDown.all != 0)
    {
        ACT_errors.severity = CriticalError;
    }
    else if (ACT_errors.slowPowerDown.all != 0)
    {
        ACT_errors.severity = OperatingError;
    }
    else if (ACT_errors.warnings.all != 0)
    {
        ACT_errors.severity = Warning;
    }
    else
    {
        ACT_errors.severity = noErrorNorWarning;
    }
}
