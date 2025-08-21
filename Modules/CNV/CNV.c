/*!
 * \file     CNV.c
 * \brief    Middleware layer dedicated to Powercore units Management
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

/* ---- Includes ---- */
#define CNV_MODULE
#include "CNV.h"
#include "CBUs.h"
#include "COM.h"
#include "PAR.h"
#include "PWB.h"
#include "CTB.h"
#include "FSM.h"
#include "PAR.h"
#include "CBUctrl.h"
#include "CBUinter.h"
#include "CBUmaint.h"

/* ---- Defines ---- */

#define CNV_TIMEOUT_COMETI_ERROR_RESET 100000U
#define BUCK_SETPOINT_REQ_MAX 32U
#define BUCK_SETPOINT_REQ_MIN 24U
#define BUCK_CURRENTLIMIT_REQ_MAX 357U
#define BUCK_CURRENTLIMIT_REQ_MIN 50U
/* ---- Global variables ---- */

/* ---- External functions ---- */

/* ---- Static variables ---- */

static boolean stopInconsistentCOMETi = false;

/* ---- Static functions ---- */
static void cnv_resetPowercoreUnit(uint8_t index);
static void cnv_StopPowercoreUnitCommand(void);
static uint32_t cnv_CalculateBoostCurrentLimit(void);
static void cnv_StartBoostPowercoreUnitCommand(void);
static void cnv_StartBuckPowercoreUnitCommand(void);
static void cnv_ChangePowercoreUnitsCommand(void);
static void cnv_CheckPowercoreUnitsCommand(void);
static void cnv_UpdateBuckType(void);
void cnv_GetRegulationReq(void);

static CNV_ErrorResetRequestE stateForErrorResetReq = COMETi1_ErrorResetReq; // Used to time out the sending of the error reset request
static uint32_t resetCOMETiErrorResetTimer = 0;

/*LDRA_HEADER_END*/

/*!     \brief   Initialization of CNV Management Module
 *       \param  none
 *       \return none
 */
void CNV_Init(void)
{
    uint8_t index;

    for (index = 0; index < CNV_POWERCORE_UNITS_NB; index++)
    {
        cnv_resetPowercoreUnit(index);
    }

    CNV_regulationReq.setpointReq = 0;
    CNV_regulationReq.reqAccepted = false;
    CNV_regulationReq.currentLimiteReq = 0;
}

/*!     \brief   Deinitialization of CNV Management Module
 *       \param  id + datas
 *       \return none
 */
void CNV_Deinit(void)
{
    uint8_t index;

    for (index = 0; index < CNV_POWERCORE_UNITS_NB; index++)
    {
        cnv_resetPowercoreUnit(index);
    }
}

/*!     \brief   Send Internal ErrorResetReques Frame
 *       \param  none
 *       \return none
 */

void CNV_ManageInternalErrorResetRequestFrame(void)
{
    boolean cometiHasError = false;
    if (CNV_powercoreUnitTable[0].flags.moduleFlags.faults.all != 0
            || CNV_powercoreUnitTable[1].flags.moduleFlags.faults.all != 0)
    {
        cometiHasError = true;
    }
    else
    {
        cometiHasError = false;
    }
    if (COM_flags.moduleFlags.status.flags.errorResetRequest == true
            || cometiHasError == true)
    {
        switch (stateForErrorResetReq)
        {
            case COMETi1_ErrorResetReq:
                CBU_SendInternalErrorResetRequestFrameCOMETiUnits(0); // in the first 1ms send the error reset request to the first COMETi
                stateForErrorResetReq = COMETi2_ErrorResetReq;
                break;
            case COMETi2_ErrorResetReq:
                CBU_SendInternalErrorResetRequestFrameCOMETiUnits(1); // in the second 1ms send the error reset request to the second COMETi
                stateForErrorResetReq = COMETi1_ErrorResetReq;
                COM_flags.moduleFlags.status.flags.errorResetRequest = false;
                break;
            default:
                break;
        }

        /*        if (resetCOMETiErrorResetTimer >= CNV_TIMEOUT_COMETI_ERROR_RESET)
         {
         CNV_powercoreUnitTable[0].flags.moduleFlags.faults.all = 0;
         CNV_powercoreUnitTable[1].flags.moduleFlags.faults.all = 0;
         CNV_powercoreUnitTable[0].flags.moduleFlags.warns.all = 0;
         CNV_powercoreUnitTable[1].flags.moduleFlags.warns.all = 0;
         resetCOMETiErrorResetTimer = 0;
         }
         else
         {
         resetCOMETiErrorResetTimer++;
         }*/

    }
    else
    {
        /* Nothing to do */
    }

}

/*!     \brief   Get Current Measures Frame Data
 *       \param  buffer + Powercore unit Index
 *       \return none
 */
void CNV_GetInternalCurrentMeasuresFrame(const uint8_t buffer[],
                                         uint8_t powercoreUnitIndex)
{

    CNV_powercoreUnitTable[powercoreUnitIndex].powerMeas.iBus1 = 0;
    CNV_powercoreUnitTable[powercoreUnitIndex].powerMeas.iBus2 = 0;
    CBU_GetInternalCurrentMeasuresFrameData(buffer,
            &CNV_powercoreUnitTable[powercoreUnitIndex].powerMeas.iBus1,
            &CNV_powercoreUnitTable[powercoreUnitIndex].powerMeas.iBus2);

}

/*!     \brief   Get Power Measures Frame Data
 *       \param  buffer + Powercore unit Index
 *       \return none
 */
void CNV_GetInternalPowerMeasuresFrame(const uint8_t buffer[],
                                       uint8_t powercoreUnitIndex)
{
    CNV_powercoreUnitTable[powercoreUnitIndex].powerMeas.pBus1 = 0;
    CNV_powercoreUnitTable[powercoreUnitIndex].powerMeas.pBus2 = 0;
    CBU_GetInternalPowerMeasuresFrameData(buffer,
            &CNV_powercoreUnitTable[powercoreUnitIndex].powerMeas.pBus1,
            &CNV_powercoreUnitTable[powercoreUnitIndex].powerMeas.pBus2);
}

/*!     \brief   Get Temperature Measures Frame Data
 *       \param  buffer + Powercore unit Index
 *       \return none
 */
void CNV_GetInternalTemperatureMeasuresFrame(const uint8_t buffer[],
                                             uint8_t powercoreUnitIndex)
{

    uint32_t temp1 = 0;
    uint32_t temp2 = 0;
    uint32_t temp3 = 0;
    uint32_t temp4 = 0;
    uint32_t temp5 = 0;
    uint32_t temp6 = 0;
    uint32_t temp7 = 0;
    uint32_t temp8 = 0;

    CBU_GetInternalTemperatureMeasuresFrameData(buffer, &temp1, &temp2, &temp3,
            &temp4, &temp5, &temp6, &temp7, &temp8);

    CNV_powercoreUnitTable[powercoreUnitIndex].tempMeas.temp1 = temp1 - 50; // the offset of the temperature check the COMETI DBC
    CNV_powercoreUnitTable[powercoreUnitIndex].tempMeas.temp2 = temp2 - 50;
    CNV_powercoreUnitTable[powercoreUnitIndex].tempMeas.temp3 = temp3 - 50;
    CNV_powercoreUnitTable[powercoreUnitIndex].tempMeas.temp4 = temp4 - 50;
    CNV_powercoreUnitTable[powercoreUnitIndex].tempMeas.temp5 = temp5 - 50;
    CNV_powercoreUnitTable[powercoreUnitIndex].tempMeas.temp6 = temp6 - 50;
    CNV_powercoreUnitTable[powercoreUnitIndex].tempMeas.temp7 = temp7 - 50;
    CNV_powercoreUnitTable[powercoreUnitIndex].tempMeas.temp8 = temp8 - 50;
}

/*!     \brief   Get Voltage Measures Frame Data
 *       \param  buffer + Powercore unit Index
 *       \return none
 */
void CNV_GetInternalVoltageMeasuresFrame(const uint8_t buffer[],
                                         uint8_t powercoreUnitIndex)
{
    CNV_powercoreUnitTable[powercoreUnitIndex].powerMeas.vBus1 = 0;
    CNV_powercoreUnitTable[powercoreUnitIndex].powerMeas.vBus2 = 0;
    CBU_GetInternalVoltageMeasuresFrameData(buffer,
            &CNV_powercoreUnitTable[powercoreUnitIndex].powerMeas.vBus1,
            &CNV_powercoreUnitTable[powercoreUnitIndex].powerMeas.vBus2);
}

/*!     \brief   Get Regulation Information Frame Data
 *       \param  buffer + Powercore unit Index
 *       \return none
 */
void CNV_GetInternalRegulationInfoFrame(const uint8_t buffer[],
                                        uint8_t powercoreUnitIndex)
{
    uint8_t softwaremode = 0;
    uint8_t limitationType = 0;

    CNV_powercoreUnitTable[powercoreUnitIndex].regulInfo.setpoint = 0;

    CBU_GetInternalRegulationInfoFrameData(buffer, &softwaremode,
            &CNV_powercoreUnitTable[powercoreUnitIndex].regulInfo.setpoint,
            &limitationType);

    CNV_powercoreUnitTable[powercoreUnitIndex].regulInfo.softMode =
            (CNV_SoftwareModesE) softwaremode;
    CNV_powercoreUnitTable[powercoreUnitIndex].regulInfo.limitationType =
            (CNV_LimitationTypeValuesE) limitationType;
}

/*!     \brief   Get Voltage Measures Frame Data
 *       \param  buffer + Powercore unit Index
 *       \return none
 */
void CNV_GetInternalControlInfoFrame(const uint8_t buffer[],
                                     uint8_t powercoreUnitIndex)
{
    uint8_t regMode = 0;
    uint8_t regType = 0;

    CNV_powercoreUnitTable[powercoreUnitIndex].controlInfo.currentLimit = 0;

    CBU_GetInternalControlInfoFrameData(buffer, &regMode, &regType,
            &CNV_powercoreUnitTable[powercoreUnitIndex].controlInfo.currentLimit);

    CNV_powercoreUnitTable[powercoreUnitIndex].controlInfo.regMode =
            (CNV_RegulationModesE) regMode;
    CNV_powercoreUnitTable[powercoreUnitIndex].controlInfo.regType =
            (CNV_RegulationTypesE) regType;

    cnv_CheckPowercoreUnitsCommand();
}

/*!     \brief   Get Errors Frame Data
 *       \param  buffer + Powercore unit Index
 *       \return none
 */
void CNV_GetInternalErrorsFrame(const uint8_t buffer[],
                                uint8_t powercoreUnitIndex)
{
    CNV_CometiCriticalErrorU cometiCriticalErrors;
    cometiCriticalErrors.value = 0;
    CNV_CometiFunctionalErrorU cometiFunctionalErrors;
    cometiFunctionalErrors.value = 0;

    CBU_GetInternalErrorsFrameData(buffer, &cometiCriticalErrors.value,
            &cometiFunctionalErrors.value);

    CNV_powercoreUnitTable[powercoreUnitIndex].flags.moduleFlags.faults.flags.uBusHvMin =
            cometiFunctionalErrors.flags.vbus1Min;
    CNV_powercoreUnitTable[powercoreUnitIndex].flags.moduleFlags.faults.flags.uBusLvMin =
            cometiFunctionalErrors.flags.vbus2Min;
    CNV_powercoreUnitTable[powercoreUnitIndex].flags.moduleFlags.faults.flags.uBusHvMax =
            cometiFunctionalErrors.flags.vbus1Max;
    CNV_powercoreUnitTable[powercoreUnitIndex].flags.moduleFlags.faults.flags.uBusLvMax =
            cometiFunctionalErrors.flags.vbus2Max;
    CNV_powercoreUnitTable[powercoreUnitIndex].flags.moduleFlags.faults.flags.iBusHvMax =
            cometiFunctionalErrors.flags.iBus1Leg1Max
                    | cometiFunctionalErrors.flags.iBus1Leg2Max;
    CNV_powercoreUnitTable[powercoreUnitIndex].flags.moduleFlags.faults.flags.iBusLvMax =
            cometiFunctionalErrors.flags.iBus2Leg1Max
                    | cometiFunctionalErrors.flags.iBus2Leg2Max;
    CNV_powercoreUnitTable[powercoreUnitIndex].flags.moduleFlags.faults.flags.CoolantTempMinCritical =
            cometiFunctionalErrors.flags.CoolantTempMinCritical;
    CNV_powercoreUnitTable[powercoreUnitIndex].flags.moduleFlags.faults.flags.CoolantTempMaxCritical =
            cometiFunctionalErrors.flags.CoolantTempMaxCritical;
    CNV_powercoreUnitTable[powercoreUnitIndex].flags.moduleFlags.faults.flags.ambientTempCritical =
            cometiFunctionalErrors.flags.ambientTempMinCritical
                    | cometiFunctionalErrors.flags.ambientTempMaxCritical;
    CNV_powercoreUnitTable[powercoreUnitIndex].flags.moduleFlags.faults.flags.otherTempCritical =
            cometiFunctionalErrors.flags.mosfetTempMaxCritical
                    | cometiFunctionalErrors.flags.transformerTempMaxCritical
                    | cometiFunctionalErrors.flags.selfTempMaxCritical;
    CNV_powercoreUnitTable[powercoreUnitIndex].flags.moduleFlags.faults.flags.uBusHvMaxCritical =
            cometiCriticalErrors.flags.vbus1MaxCritical;
    CNV_powercoreUnitTable[powercoreUnitIndex].flags.moduleFlags.faults.flags.uBusLvMaxCritical =
            cometiCriticalErrors.flags.vbus2MaxCritical;
    CNV_powercoreUnitTable[powercoreUnitIndex].flags.moduleFlags.faults.flags.iBusHvMaxCritical =
            cometiCriticalErrors.flags.iBus1Leg1MaxCritical
                    | cometiCriticalErrors.flags.iBus1Leg2MaxCritical;
    CNV_powercoreUnitTable[powercoreUnitIndex].flags.moduleFlags.faults.flags.iBusLvMaxCritical =
            cometiCriticalErrors.flags.iBus2Leg1MaxCritical
                    | cometiCriticalErrors.flags.iBus2Leg2MaxCritical;
    CNV_powercoreUnitTable[powercoreUnitIndex].flags.moduleFlags.faults.flags.componentInternalError =
            cometiCriticalErrors.flags.fpgaLost
                    | cometiCriticalErrors.flags.mcuClockUnsync
                    | cometiCriticalErrors.flags.fpgaClockUnsync
                    | cometiCriticalErrors.flags.servicePowerSupplyLostMcu
                    | cometiCriticalErrors.flags.servicePowerSupplyLostFpga
                    | cometiCriticalErrors.flags.inoperationalCurrentSensor
                    | cometiCriticalErrors.flags.inoperationalVoltageSensor
                    | cometiCriticalErrors.flags.powerMap
                    | cometiCriticalErrors.flags.parameters
                    | cometiFunctionalErrors.flags.unknownControlMode
                    | cometiFunctionalErrors.flags.unknownControlType
                    | cometiFunctionalErrors.flags.incompatibleCtrlModeType
                    | cometiFunctionalErrors.flags.inoperationalTemperatureSensor
                    | cometiFunctionalErrors.flags.controlLoopNotSet
                    | cometiFunctionalErrors.flags.comIsLost
                    | cometiCriticalErrors.flags.vbusAuxMaxCritical
                    | cometiCriticalErrors.flags.vbusAuxMinCritical;

    if (FSM_mode == FSM_MODE_STANDBY)
    {
        CNV_powercoreUnitTable[powercoreUnitIndex].flags.moduleFlags.faults.all =
                0; // ignore all the errors and warnings if we are in standby
    }
    else
    {
        // Do nothing take into consideration the errors
    }
}

/*!     \brief   Get Warnings Frame Data
 *       \param  buffer + Powercore unit Index
 *       \return none
 */
void CNV_GetInternalWarningsFrame(const uint8_t buffer[],
                                  uint8_t powercoreUnitIndex)
{
    CNV_CometiWarningU cometiWarnings;

    cometiWarnings.value = 0;

    CBU_GetInternalWarningsFrameData(buffer, &cometiWarnings.value);

    CNV_powercoreUnitTable[powercoreUnitIndex].flags.moduleFlags.warns.flags.outCoolantTemp =
            cometiWarnings.flags.highOutCoolantTemp;
    CNV_powercoreUnitTable[powercoreUnitIndex].flags.moduleFlags.warns.flags.inCoolantTemp =
            cometiWarnings.flags.highInCoolantTemp;
    CNV_powercoreUnitTable[powercoreUnitIndex].flags.moduleFlags.warns.flags.ambientTemp =
            cometiWarnings.flags.highAmbientTemp;
    CNV_powercoreUnitTable[powercoreUnitIndex].flags.moduleFlags.warns.flags.mosfetTemp =
            cometiWarnings.flags.highMosfetTemp;
    CNV_powercoreUnitTable[powercoreUnitIndex].flags.moduleFlags.warns.flags.transformerTemp =
            cometiWarnings.flags.highTransformerTemp;
    CNV_powercoreUnitTable[powercoreUnitIndex].flags.moduleFlags.warns.flags.selfTemp =
            cometiWarnings.flags.highSelfTemp;
    CNV_powercoreUnitTable[powercoreUnitIndex].flags.moduleFlags.warns.flags.coolantDeltaTemp =
            cometiWarnings.flags.highCoolantDeltaTemp;
    CNV_powercoreUnitTable[powercoreUnitIndex].flags.moduleFlags.warns.flags.componentSwWarn =
            cometiWarnings.flags.backupApplicationStarted
                    | cometiWarnings.flags.backupParametersLoaded
                    | cometiWarnings.flags.setPointUnreachableTooLow
                    | cometiWarnings.flags.setPointUnreachableTooHigh
                    | cometiWarnings.flags.controlTypeChangeNotAllowed;

    if (FSM_mode == FSM_MODE_STANDBY)
    {
        CNV_powercoreUnitTable[powercoreUnitIndex].flags.moduleFlags.warns.all =
                0; // ignore all the errors and warnings if we are in standby
    }
    else
    {
        // Do nothing take into consideration the errors
    }
}

/*!     \brief   Get Powercore unit's Index
 *       \param  powercoreUnitAddress
 *       \return powercoreUnitIndex (0xFF = no existing unit identified)
 */
uint8_t CNV_getPowercoreUnitsIndex(uint8_t powercoreUnitAddress)
{
    uint8_t index;
    uint8_t ret = 0;
    boolean found = false;

    for (index = 0; ((index <= CNV_POWERCORE_UNITS_NB) && !found); ++index)
    {
        if (CNV_powercoreUnitTable[index].address == powercoreUnitAddress)
        {
            found = true;
        }
    }

    if ((index) > CNV_POWERCORE_UNITS_NB)
    {
        ret = 0xFF;
    }
    else
    {
        ret = index - 1;
    }

    return (ret);
}

/*!     \brief   Update Comm Loss Counter for all Powercore units
 *       \param  powercoreUnitIndex (0xFF = no existing unit identified)
 *       \return none
 */
void CNV_updatePowercoreUnitsComlossCounter(uint8_t powercoreUnitIndex)
{
    uint8_t index;

    for (index = 0; index < CNV_POWERCORE_UNITS_NB; index++)
    {
        if (index == powercoreUnitIndex)
        {
            CNV_powercoreUnitTable[index].comLostCounter = 0;
        }
        else
        {
            CNV_powercoreUnitTable[index].comLostCounter += 10U;
        }
    }
}

/*!     \brief   update the stop order
 *       \param  none
 *       \return none
 */
static void cnv_StopPowercoreUnitCommand(void)
{
    CNV_powercoreUnitTable[0].request.startOrder = false;
    CNV_powercoreUnitTable[1].request.startOrder = false;
}

/*!     \brief   calculate the current limit for the COMETi units
 *       \param  none
 *       \return none
 */
static uint32_t cnv_CalculateBoostCurrentLimit(void)
{
    uint32_t boostCurrentLimitPAR =
            PAR_paramConfig[PAR_BOOST_CURRENT_LIMIT].realVal.unsignedVal;
    return boostCurrentLimitPAR / CNV_POWERCORE_UNITS_NB;
}

/*!     \brief   update the start BOOST order
 *       \param  none
 *       \return none
 */
static void cnv_StartBoostPowercoreUnitCommand(void)
{
    uint32_t setpointPAR =
            PAR_paramConfig[PAR_BOOST_VOLTAGE_SETPOINT].realVal.unsignedVal;

    uint32_t currentLimit = cnv_CalculateBoostCurrentLimit();

    CNV_powercoreUnitTable[0].request.startOrder = true;
    CNV_powercoreUnitTable[0].request.setpoint = setpointPAR;
    CNV_powercoreUnitTable[0].request.currentLimit = (uint16_t) currentLimit;
    CNV_powercoreUnitTable[0].request.regMode = CNV_REGMODE_BUS2TOBUS1;
    CNV_powercoreUnitTable[0].request.regType = CNV_REGTYPE_VBUS1_ILIM;

    CNV_powercoreUnitTable[1].request.startOrder = true;
    CNV_powercoreUnitTable[1].request.setpoint = setpointPAR;
    CNV_powercoreUnitTable[1].request.currentLimit = (uint16_t) currentLimit;
    CNV_powercoreUnitTable[1].request.regMode = CNV_REGMODE_BUS2TOBUS1;
    CNV_powercoreUnitTable[1].request.regType = CNV_REGTYPE_VBUS1;

    //Set the boost error stubing
    if ( (CNV_powercoreUnitTable[0].regulInfo.setpoint < CNV_powercoreUnitTable[0].request.setpoint)
            && (CNV_powercoreUnitTable[1].regulInfo.setpoint < CNV_powercoreUnitTable[1].request.setpoint) )
    {
        CNV_flags.moduleFlags.status.flags.boost_stub_error_req = 1;
        CNV_flags.moduleFlags.status.flags.no_stub_error_req = 0;
    }
    else
    {
        CNV_flags.moduleFlags.status.flags.boost_stub_error_req = 0;
        CNV_flags.moduleFlags.status.flags.no_stub_error_req = 1;
    }
}

/*!     \brief   update the start BUCK order
 *       \param  none
 *       \return none
 */
static void cnv_StartBuckPowercoreUnitCommand(void)
{
    uint32_t setpointPAR = (uint32_t) (CNV_regulationReq.setpointReq
            / CNV_POWERCORE_UNITS_NB);
    uint32_t buckCurrentLimitPAR =
            (uint32_t) (CNV_regulationReq.currentLimiteReq
                    / CNV_POWERCORE_UNITS_NB);

    CNV_powercoreUnitTable[0].request.startOrder = true;
    CNV_powercoreUnitTable[0].request.setpoint = setpointPAR;
    CNV_powercoreUnitTable[0].request.currentLimit =
            (uint16_t) buckCurrentLimitPAR;
    CNV_powercoreUnitTable[0].request.regMode = CNV_REGMODE_BUS1TOBUS2;
    CNV_powercoreUnitTable[0].request.regType = CNV_REGTYPE_VBUS2_ILIM;

    CNV_powercoreUnitTable[1].request.startOrder = true;
    CNV_powercoreUnitTable[1].request.setpoint = setpointPAR;
    CNV_powercoreUnitTable[1].request.currentLimit =
            (uint16_t) buckCurrentLimitPAR;
    CNV_powercoreUnitTable[1].request.regMode = CNV_REGMODE_BUS1TOBUS2;
    CNV_powercoreUnitTable[1].request.regType = CNV_REGTYPE_VBUS2_ILIM;

    //Set the buck error stubing
    if ( (CNV_powercoreUnitTable[0].regulInfo.setpoint < CNV_powercoreUnitTable[0].request.setpoint)
            && (CNV_powercoreUnitTable[1].regulInfo.setpoint < CNV_powercoreUnitTable[1].request.setpoint) )
    {
        CNV_flags.moduleFlags.status.flags.buck_stub_error_req = 1;
        CNV_flags.moduleFlags.status.flags.no_stub_error_req = 0;
    }
    else
    {
        CNV_flags.moduleFlags.status.flags.buck_stub_error_req = 0;
        CNV_flags.moduleFlags.status.flags.no_stub_error_req = 1;
    }
}

/*!     \brief   Change request for Powercore Units
 *       \param  none
 *       \return none
 */
void cnv_ChangePowercoreUnitsCommand(void)
{
    // check the TRS to know when to stop and start the COMETi
    // check what reg mode and control data to send
    if ((FSM_mode == FSM_MODE_BOOST
            && CNV_powercoreUnitTable[0].flags.moduleFlags.faults.all == 0
            && CNV_powercoreUnitTable[1].flags.moduleFlags.faults.all == 0)
            && ((PWB_Flags.status.flags.prechargeDone == true))) // check the state of the precharge
    {
        cnv_StartBoostPowercoreUnitCommand();
    }
    else if ((FSM_mode == FSM_MODE_BUCK)
            && ((PWB_Flags.status.flags.prechargeDone == true)) // check the state of the precharge
            && CNV_powercoreUnitTable[0].flags.moduleFlags.faults.all == 0
            && CNV_powercoreUnitTable[1].flags.moduleFlags.faults.all == 0)
    {
        cnv_StartBuckPowercoreUnitCommand();
    }
    else if (stopInconsistentCOMETi == true)
    {
        // any other mode keep sending stop command to the cometi units
        cnv_StopPowercoreUnitCommand();
    }
    else
    {
        cnv_StopPowercoreUnitCommand();
    }
}

static void cnv_CheckPowercoreUnitsCommand(void) // TRO_50073_50147_001_TRS_0009
{
    if (FSM_mode == FSM_MODE_BOOST)
    {
        if (CNV_powercoreUnitTable[0].controlInfo.regMode
                != CNV_REGMODE_BUS2TOBUS1
                || CNV_powercoreUnitTable[1].controlInfo.regMode
                        != CNV_REGMODE_BUS2TOBUS1)
        {
            stopInconsistentCOMETi = true;
        }
        else
        {
            stopInconsistentCOMETi = false;
        }
    }
    else if (FSM_mode == FSM_MODE_BUCK)
    {
        if (CNV_powercoreUnitTable[0].controlInfo.regMode
                != CNV_REGMODE_BUS1TOBUS2
                || CNV_powercoreUnitTable[1].controlInfo.regMode
                        != CNV_REGMODE_BUS1TOBUS2)
        {
            stopInconsistentCOMETi = true;
        }
        else
        {
            stopInconsistentCOMETi = false;
        }
    }
    else if (FSM_mode == FSM_MODE_STANDBY)
    {
        if (CNV_powercoreUnitTable[0].regulInfo.softMode
                == CNV_SOFTWAREMODE_RUNNING
                || CNV_powercoreUnitTable[1].regulInfo.softMode
                        == CNV_SOFTWAREMODE_RUNNING)
        {
            stopInconsistentCOMETi = true;
        }
        else
        {
            stopInconsistentCOMETi = false;
        }
    }
}

static void cnv_UpdateBuckType(void) //TRO_50073_50147_001_TRS_0150
{
    if (FSM_mode == FSM_MODE_BUCK)
    {
        uint16_t iBus2 = (uint16_t) (CNV_powercoreUnitTable[0].powerMeas.iBus2
                + CNV_powercoreUnitTable[1].powerMeas.iBus2);
        uint16_t vBus2 = (uint16_t) ((CNV_powercoreUnitTable[0].powerMeas.vBus2
                + CNV_powercoreUnitTable[1].powerMeas.vBus2)
                / CNV_POWERCORE_UNITS_NB);
        uint32_t par_Buck_CurrentLimit =
                CNV_regulationReq.currentLimiteReq;
        uint32_t par_Buck_VoltSetpoint =
                CNV_regulationReq.setpointReq;
        if (iBus2 >= par_Buck_CurrentLimit && vBus2 < par_Buck_VoltSetpoint)
        {
            CNV_buckType = CNV_BUCKTYPE_CURRENTSOURCE;
        }
        else
        {
            CNV_buckType = CNV_BUCKTYPE_VOLTAGEREGULATION;
        }
    }
    else
    {
        CNV_buckType = CNV_BUCKTYPE_NOINBUCK;
    }

}

void CNV_Update(void)
{
    cnv_GetRegulationReq();
    cnv_ChangePowercoreUnitsCommand();
    cnv_UpdateBuckType();
}
/*!     \brief   Get Current Measures Frame
 *       \param  powercoreUnitIndex
 *       \return none
 */
void cnv_resetPowercoreUnit(uint8_t index)
{
    CNV_powercoreUnitTable[index].address = (uint8_t) (index + 1);
    CNV_powercoreUnitTable[index].comLostCounter = 0;

    CNV_powercoreUnitTable[index].flags.all = 0;

    CNV_powercoreUnitTable[index].powerMeas.vBus1 = 0;
    CNV_powercoreUnitTable[index].powerMeas.vBus2 = 0;
    CNV_powercoreUnitTable[index].powerMeas.iBus1 = 0;
    CNV_powercoreUnitTable[index].powerMeas.iBus2 = 0;
    CNV_powercoreUnitTable[index].powerMeas.pBus1 = 0;
    CNV_powercoreUnitTable[index].powerMeas.pBus2 = 0;

    CNV_powercoreUnitTable[index].tempMeas.temp1 = 0;
    CNV_powercoreUnitTable[index].tempMeas.temp2 = 0;
    CNV_powercoreUnitTable[index].tempMeas.temp3 = 0;
    CNV_powercoreUnitTable[index].tempMeas.temp4 = 0;
    CNV_powercoreUnitTable[index].tempMeas.temp5 = 0;
    CNV_powercoreUnitTable[index].tempMeas.temp6 = 0;
    CNV_powercoreUnitTable[index].tempMeas.temp7 = 0;
    CNV_powercoreUnitTable[index].tempMeas.temp8 = 0;

    CNV_powercoreUnitTable[index].regulInfo.softMode = CNV_SOFTWAREMODE_INIT;
    CNV_powercoreUnitTable[index].regulInfo.setpoint = 0;
    CNV_powercoreUnitTable[index].regulInfo.limitationType =
            CNV_LIMITATIONTYPE_NOLIMITATION;
    CNV_powercoreUnitTable[index].regulInfo.hasNewValues = 0;

    CNV_powercoreUnitTable[index].controlInfo.regMode = CNV_REGMODE_NOT_SET;
    CNV_powercoreUnitTable[index].controlInfo.regType = CNV_REGTYPE_NOT_SET;
    CNV_powercoreUnitTable[index].controlInfo.currentLimit = 0;
    CNV_powercoreUnitTable[index].controlInfo.hasNewValues = 0;

    CNV_powercoreUnitTable[index].request.regMode = CNV_REGMODE_BUS1TOBUS2;
    CNV_powercoreUnitTable[index].request.regType = CNV_REGTYPE_VBUS2_ILIM;
    CNV_powercoreUnitTable[index].request.setpoint = 0;
    CNV_powercoreUnitTable[index].request.currentLimit = 0;
    CNV_powercoreUnitTable[index].request.startOrder = false;
}

void cnv_GetRegulationReq(void)
{
    if (COM_mode.bbauxCommand == COM_BBAUXCMD_BUCK)
    {
        uint32_t tempValueSetpoint = (uint32_t) COM_mode.setpoint / 10;
        uint32_t tempValueCurrentLimite = (uint32_t) COM_mode.currentLimit / 10;

        uint32_t defaultSetpoint =
                (uint32_t) PAR_paramConfig[PAR_BUCK_VOLTAGE_DEFAULT_SETPOINT].realVal.unsignedVal;
        uint32_t defaultCurrentLimit =
                (uint32_t) PAR_paramConfig[PAR_BUCK_DEFAULT_CURRENT_LIMIT].realVal.unsignedVal;

        if (((tempValueSetpoint <= BUCK_SETPOINT_REQ_MAX)
                && (tempValueSetpoint >= BUCK_SETPOINT_REQ_MIN)) && ((tempValueCurrentLimite <= BUCK_CURRENTLIMIT_REQ_MAX)
                        && (tempValueCurrentLimite >= BUCK_CURRENTLIMIT_REQ_MIN)))
        {
            CNV_regulationReq.setpointReq = tempValueSetpoint;
            CNV_regulationReq.currentLimiteReq =
                    (uint16_t) tempValueCurrentLimite;
            CNV_regulationReq.reqAccepted = true;
        }
        else
        {
            CNV_regulationReq.setpointReq = defaultSetpoint;
            CNV_regulationReq.currentLimiteReq = (uint16_t) defaultCurrentLimit;
            CNV_regulationReq.reqAccepted = false;
        }
    }
    else
    {
        CNV_regulationReq.reqAccepted = true;
    }
}
