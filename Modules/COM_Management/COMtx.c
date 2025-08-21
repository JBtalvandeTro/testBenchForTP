/*!
 * \file     COM_Tx.c
 * \brief    Brief description of file content
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

/* ---- Includes ---- */
#include "CST.h"
#include "COM.h"
#include "COMtx.h"
#include "CBUs.h"
#include "ACT.h"
#include "CNV.h"
#include "DBG.h"
#include "FSM.h"
#include "CTB.h"
#include "PWB.h"

/* ---- Defines ---- */
#define COM_TX_TEMP_FRAME_OFFSET  ((uint8_t)50)

/* ---- Global variables ---- */

/* ---- External functions ---- */

/* ---- Static variables ---- */

/* ---- Static functions ---- */
static void com_ManageTx(void);
static void com_ManageControlTx(void);
static void com_ManageInternalTx(void);
static void com_ManageMaintenanceTx(void);
static void com_UpdateMeasures(void);
static void com_UpdatePbitResult(void);
static void com_ComposeCurrentMeasures(void);
static void com_ComposePowerMeasures(void);
static void com_ComposeTemperatureMeasures(void);
static void com_ComposeVoltageMeasures(void);
static void com_ComposeFaults(void);
static void com_ComposeControlStatusInfo(void);
static COM_LimitationTypeValuesE getLimitationType(void);
static boolean com_isControlFrameReadyToBeSent(COM_FramesControlNameE frame,
                                               boolean hasNewValues);
static boolean com_isInternalFrameReadyToBeSent(COM_FramesControlNameE frame,
                                                boolean hasNewValues);

/*LDRA_HEADER_END*/
/*!     \brief Periodic Task (update controller status + send frames)
 *       \param none
 *       \return none
 */
void COM_TxScheduledTasks(void)
{
    /* Update tx Data */
    com_UpdateMeasures();

    /* Update CBU status */
    CBU_CheckErrors();

    /* Update Pbit Results */
    com_UpdatePbitResult();

    // check if we need to send the error reset request to the COMETi units or not if yes we do it on 2ms time-span
    CNV_ManageInternalErrorResetRequestFrame();

    // Manage scheduled TX frames
    com_ManageTx();
}

/*!     \brief Task to send frames depending on the request
 *       \param none
 *       \return none
 */
void COM_TxRequestedTasks(void)
{
    boolean status = false;
    uint16_t parIndex = PAR_paramReq.index;
    uint32_t parValueLocal = PAR_paramReq.value.unsignedVal;
    uint32_t parReadValue = PAR_paramReq.readValue.unsignedVal;

    // Manage Equipment Test request
    if (DBG_Flags.proccesingFlags.processed == true)
    {

        if (FSM_mode == FSM_MODE_MAINTENANCE)
        {
            CBU_SendMaintenanceEquipmentTestResponse();
        }
        else
        {
            // DO not send any response
        }

        DBG_Flags.proccesingFlags.processed = false;

        if (COM_debugTestReq.relaySwitchTestRequest == (boolean) true)
        {
            COM_debugTestReq.relaySwitchTestRequest = false;
            PWBio_cmdResults.SwitchReadCmdResult = false;
        }

        if (COM_debugTestReq.hvMeasuresTestRequest == (boolean) true)
        {
            COM_debugTestReq.hvMeasuresTestRequest = false;
            PWBCbit_cmdResults.ReadMeasResultHMI = 0;
            PWBCbit_cmdResults.ReadMeasResultRaw = 0;
            COM_debugTestReq.hmiMeasure = 0;
            COM_debugTestReq.rawMeasure = 0;
        }

        if (COM_debugTestReq.lvMeasuresTestRequest == (boolean) true)
        {
            COM_debugTestReq.lvMeasuresTestRequest = false;
            PWBCbit_cmdResults.ReadMeasResultHMI = 0;
            PWBCbit_cmdResults.ReadMeasResultRaw = 0;
            COM_debugTestReq.hmiMeasure = 0;
            COM_debugTestReq.rawMeasure = 0;
        }

        if (COM_debugTestReq.discreteIosTestRequest == (boolean) true)
        {
            COM_debugTestReq.discreteIosTestRequest = false;
            // reset all the results
            ctb_DSI_TestResult.HPP_1_TestResult = false;
            ctb_DSI_TestResult.HPP_2_TestResult = false;
            ctb_DSI_TestResult.HPP_MAINT_TestResult = false;
            ctb_DSI_TestResult.DSI_SPARE_1_TestResult = false;
            ctb_DSI_TestResult.DSI_SPARE_2_TestResult = false;
            ctb_DSI_TestResult.EMER_STOP_TestResult = false;
        }

        if (COM_debugTestReq.ledsTestRequest == (boolean) true)
        {
            COM_debugTestReq.ledsTestRequest = false;
        }
    }

    // Manage Parameter request
    //Depends on ParRequest status in COM, PAR and DBG modules
    if (PAR_paramReq.lastError == PAR_ERROR_NO_ERROR)
    {
        status = true;
    }
    else
    {
        status = false;
    }

    if (PAR_paramReq.processed == (boolean) true)
    {
        // Manage Read request
        if (COM_paramReq.readRequest == (boolean) true)
        {
            CBU_SendMaintenanceParameterResponse(parIndex, parReadValue,
                    status);
            COM_paramReq.readRequest = false;
        }
        // Manage Update request
        else if (COM_paramReq.changeRequest == (boolean) true)
        {
            CBU_SendMaintenanceParameterResponse(parIndex, parValueLocal,
                    status);
            COM_paramReq.changeRequest = false;
        }
        // Manage Save request
        else if (COM_paramReq.saveRequest == (boolean) true)
        {

            CBU_SendMaintenanceParameterResponse(0xFFFF, 0, status);
            COM_paramReq.saveRequest = false;

        }
    }
}

/*!     \brief Frame transmission
 *       \param none
 *       \return none
 */
static void com_ManageTx(void)
{
    com_ManageControlTx();
    com_ManageInternalTx();
    com_ManageMaintenanceTx();

    COM_UpdatePeriodParams();

    if (FSM_mode == FSM_MODE_SHUTDOWN)
    {
        Can_SetControllerMode(CBU_CONTROLCAN, CAN_CS_STOPPED);
    }
    else
    {
        Can_SetControllerMode(CBU_CONTROLCAN, CAN_CS_STARTED);
    }
}

/*!     \brief Frame transmission function for Control CAN
 *       \param none
 *       \return none
 */
static void com_ManageControlTx(void)
{
    uint32_t i;

    /* Check if frame are ready to be sent before sending them */
    if (com_isControlFrameReadyToBeSent(COM_FRAME_CONTROL_TX_CURRENTMEAS,
    false))
    {
        CBU_SendControlCurrentMeasuresFrame();
    }

    if (com_isControlFrameReadyToBeSent(COM_FRAME_CONTROL_TX_POWERMEAS,
    false))
    {
        CBU_SendControlPowerMeasuresFrame();
    }

    if (com_isControlFrameReadyToBeSent(COM_FRAME_CONTROL_TX_TEMPERATUREMEAS,
    false))
    {
        CBU_SendControlTemperatureMeasuresFrame();
    }

    if (com_isControlFrameReadyToBeSent(COM_FRAME_CONTROL_TX_VOLTAGEMEAS,
    false))
    {
        CBU_SendControlVoltageMeasuresFrame();
    }

    if (com_isControlFrameReadyToBeSent(COM_FRAME_CONTROL_TX_CONTROLSTATUS,
            COM_controlStatusInfo.hasNewValues))
    {
        CBU_SendControlControlStatusFrame();
    }

    if (com_isControlFrameReadyToBeSent(COM_FRAME_CONTROL_TX_ERRORSWARNINGS,
            COM_errorsAndWarnings.hasNewValuesErr))
    {
        CBU_SendControlErrorsWarningsFrame();
    }

    if ((FSM_mode == FSM_MODE_PBIT)
            && com_isControlFrameReadyToBeSent(COM_FRAME_CONTROL_TX_PBITRESULTS,
            false))
    {
        CBU_SendControlPbitResultsFrame();
    }

    /* Update txDelayCounter for all frames groups */
    for (i = 0; i < ((uint32_t) COM_FRAME_GROUP_COUNT); i++)
    {
        /* Increment */
        COM_txDelayCounterControl[i]++;

        /* Reset if reached period */
        /*LDRA_INSPECTED 131 D <justification start> Min value is PAR_MIN_CAN_TX_PERIOD = 1 <justification end> */
        COM_txDelayCounterControl[i] %= COM_txPeriodControl[i];
    }
}

/*!     \brief Frame transmission function for Internal CAN
 *       \param none
 *       \return none
 */
/*LDRA_INSPECTED 65 D <justification start> Temporary <justification end> */
static void com_ManageInternalTx(void)
{
    uint32_t i;
    /* Check if framee are ready to be sent before sending them */
    if (com_isInternalFrameReadyToBeSent(
            COM_FRAME_INTERNAL_TX_CONTROLREQCOMETI1,
            false))
    {
        CBU_SendInternalControlRequestFrameCOMETiUnits(0);
    }
    if (com_isInternalFrameReadyToBeSent(
            COM_FRAME_INTERNAL_TX_CONTROLREQCOMETI2,
            false))
    {
        CBU_SendInternalControlRequestFrameCOMETiUnits(1);
    }
    if (com_isInternalFrameReadyToBeSent(COM_FRAME_INTERNAL_TX_MODEREQCOMETI1,
    false))
    {
        CBU_SendInternalModeRequestFrameCOMETiUnits(0);
    }
    if (com_isInternalFrameReadyToBeSent(COM_FRAME_INTERNAL_TX_MODEREQCOMETI2,
    false))
    {
        CBU_SendInternalModeRequestFrameCOMETiUnits(1);
    }
    /* Update txDelayCounter */
    /* Increment */
    /* Update txDelayCounter for all frames groups */
    for (i = 0; i < ((uint32_t) COM_FRAME_GROUP_COUNT); i++)
    {
        COM_txDelayCounterInternal[i]++;

        /* Reset if reached period */
        /*LDRA_INSPECTED 131 D <justification start> Min value is PAR_MIN_CAN_TX_PERIOD = 1 <justification end> */
        COM_txDelayCounterInternal[i] %= COM_txPeriodInternal[i];
    }
}

/*!     \brief Frame transmission function for Maintenance CAN
 *       \param none
 *       \return none
 */
/*LDRA_INSPECTED 256 S <justification start> For clarity reasons <justification end> */
static void com_ManageMaintenanceTx(void)
{
    // TODO : need to check if we reived a request and we executed and we are ready to send the reply
}

/*!     \brief Checks whether a Control Tx CAN frame is ready to be transmitted
 *       \param frame, hasNewValues
 *       \return boolean
 */
static boolean com_isControlFrameReadyToBeSent(COM_FramesControlNameE frame,
                                               boolean hasNewValues)
{
    boolean check = false;
    COM_FrameGroupE frameGroup;

    frameGroup = COM_framesControl[frame].group;

    if (frame < COM_FRAMES_CONTROL_COUNT)
    {
        /* If is Tx frame */
        if (COM_framesControl[frame].dir == COM_FRAME_DIR_TX)
        {
            switch (frameGroup)
            {
                case COM_FRAME_GROUP_PWR_MEAS:
                case COM_FRAME_GROUP_TEMP_MEAS:
                case COM_FRAME_GROUP_ALERT:
                case COM_FRAME_GROUP_STATUS:
                    /* Only send if period is not 0, and its modulo with txDelayCounter is equal
                     * to frame offset, otherwise check if the frame has new values */
                    if (COM_txPeriodControl[frameGroup] != 0U)
                    {
                        if (COM_txDelayCounterControl[frameGroup]
                                == COM_framesControl[frame].offset)
                        {
                            check = true;
                        }
                    }
                    else
                    {
                        check = hasNewValues;
                    }
                    break;

                default:
                    /* Nothing to do */
                    break;
            }
        }
        else
        {
            /* Nothing to do */
        }
    }

    return check;
}

/*!     \brief Checks whether a Control Tx CAN frame is ready to be transmitted
 *       \param frame, hasNewValues
 *       \return boolean
 */
static boolean com_isInternalFrameReadyToBeSent(COM_FramesControlNameE frame,
                                                boolean hasNewValues)
{
    boolean check = false;
    COM_FrameGroupE frameGroup;

    frameGroup = COM_framesInternal[frame].group;
    if ((COM_FramesInternalNameE) frame < COM_FRAMES_INTERNAL_COUNT)
    {
        /* If is Tx frame */
        if (COM_framesInternal[frame].dir == COM_FRAME_DIR_TX)
        {
            switch (frameGroup)
            {
                case COM_FRAME_GROUP_COMETI_1:
                case COM_FRAME_GROUP_COMETI_2:
                    /* Only send if period is not 0, and its modulo with txDelayCounter is equal
                     * to frame offset, otherwise check if the frame has new values */
                    if (COM_txPeriodInternal[frameGroup] != 0U)
                    {
                        if (COM_txDelayCounterInternal[frameGroup]
                                == COM_framesInternal[frame].offset)
                        {
                            check = true;
                        }
                    }
                    else
                    {
                        check = hasNewValues;
                    }
                    break;

                default:
                    /* Nothing to do */
                    break;
            }
        }
        else
        {
            /* Nothing to do */
        }
    }

    return check;
}

/*!     \brief Update COM module measures
 *       \param none
 *       \return none
 */
static void com_UpdateMeasures(void)
{
    /* Update all Tx Measures */
    com_ComposeCurrentMeasures();
    com_ComposePowerMeasures();
    com_ComposeTemperatureMeasures();
    com_ComposeVoltageMeasures();

    /* Update Tx errors and warnings*/
    com_ComposeFaults();

    /* Update tx Control Status info */
    com_ComposeControlStatusInfo();
}

static void com_UpdatePbitResult(void)
{
    COM_pbitResultsInfo.softwareVersion = PAR_paramConfig[PAR_SW_VERSION].realVal.unsignedVal;

    if (PWB_Flags.resultPBit == true && CTB_Flags.resultPBit == true)
    {
        COM_pbitResultsInfo.pbitStatus = COM_PBITSTATUS_PASS;
    }
    else
    {
        if (PWB_Flags.status.flags.pbitDone == false
                || CTB_Flags.status.flags.pbitDone == false)
        {
            COM_pbitResultsInfo.pbitStatus = COM_PBITSTATUS_INPROGRESS;
        }
        else if (PWB_Flags.status.flags.pbitDone == true
                && CTB_Flags.status.flags.pbitDone == true)
        {
            COM_pbitResultsInfo.pbitStatus = COM_PBITSTATUS_FAIL;
        }
        else
        {
            COM_pbitResultsInfo.pbitStatus = COM_PBITSTATUS_NOTEXECUTED;
        }

    }
    COM_pbitResultsInfo.hvCouplerStatus = !PWB_Flags.faults.flags.hvRelayNok;
    COM_pbitResultsInfo.lvPrechargeStatus = !PWB_Flags.faults.flags.lvRelayNok;
    COM_pbitResultsInfo.dsioStatus = ~CTB_Flags.dsiResults.all; // taking the Not of the result beceause std high means NOK
}

/*!     \brief Update COM module Tx current measures
 *       \param none
 *       \return none
 */
static void com_ComposeCurrentMeasures(void)
{

    uint32_t tempCurrentMeasure1 = 0;
    uint32_t tempCurrentMeasure2 = 0;

    const uint16_t currentOffset = INT16_MAX + 1U; // offset equals 3276

// Current measure definition in DBC: Factor = 0.1, Offset = -3276.8, Unit = 'A'
    tempCurrentMeasure1 += currentOffset; // adding the offset
    tempCurrentMeasure2 += currentOffset;

// adding the current measurement from the COMETi units
    for (size_t i = 0; i < CNV_POWERCORE_UNITS_NB; i++)
    {
        tempCurrentMeasure1 += CNV_powercoreUnitTable[i].powerMeas.iBus1;
        tempCurrentMeasure2 += CNV_powercoreUnitTable[i].powerMeas.iBus2;
    }
    uint32_t tempIBusHv = 0;
    tempIBusHv = PWB_measures.Hv_Current;
    tempIBusHv = (tempIBusHv * 10); // factor of the DBC 0.1

    COM_powerMeasures.iBusHv = (uint16_t) tempIBusHv;
    COM_powerMeasures.iBusLv = (uint16_t) tempCurrentMeasure2; // preparing the data to be sent
}

/*!     \brief Update COM module Tx power measures
 *       \param none
 *       \return none
 */
static void com_ComposePowerMeasures(void)
{
    uint32_t tempPowerMeasure1 = 0;
    uint32_t tempPowerMeasure2 = 0;

// get the power measures from the COMETi units
    for (size_t i = 0; i < CNV_POWERCORE_UNITS_NB; i++)
    {
        tempPowerMeasure1 += CNV_powercoreUnitTable[i].powerMeas.pBus1;
        tempPowerMeasure2 += CNV_powercoreUnitTable[i].powerMeas.pBus2;
    }

    COM_powerMeasures.pBusHv = tempPowerMeasure1;
    COM_powerMeasures.pBusLv = tempPowerMeasure2;
}

/*!     \brief Update COM module Tx temperature measures
 *       \param none
 *       \return none
 */
static void com_ComposeTemperatureMeasures(void)
{
    uint32_t tempTempCometi1 = 0;
    uint32_t tempTempCometi2 = 0;

    tempTempCometi1 = CNV_powercoreUnitTable[0].tempMeas.temp8; // taking the Ambient Temp
    tempTempCometi2 = CNV_powercoreUnitTable[1].tempMeas.temp8;
    uint32_t tempHvTemp = 0;
    tempHvTemp = (uint32_t) (PWB_measures.Hv_Temp + 50); // taking the offset of the DBC into consideration.

    COM_tempMeasures.tempHvCoupler = (uint8_t) tempHvTemp;
    COM_tempMeasures.temp1Cometi = (uint8_t) tempTempCometi1 + 50; // taking the offset of the dbc into consideration
    COM_tempMeasures.temp2Cometi = (uint8_t) tempTempCometi2 + 50; // taking the offset of the dbc into consideration
    COM_tempMeasures.tempNotif = ACT_tempSeverity;

}

/*!     \brief Update COM module Tx voltage measures
 *       \param none
 *       \return none
 */
static void com_ComposeVoltageMeasures(void)
{
    uint32_t tempVoltageMeas1 = 0;
    uint32_t tempVoltageMeas2 = 0;

// get the voltage measures from the COMETi units
    for (size_t i = 0; i < CNV_POWERCORE_UNITS_NB; i++)
    {
        tempVoltageMeas1 += CNV_powercoreUnitTable[i].powerMeas.vBus1;
        tempVoltageMeas2 += CNV_powercoreUnitTable[i].powerMeas.vBus2;
    }

// calculate the average
    tempVoltageMeas1 = tempVoltageMeas1 / CNV_POWERCORE_UNITS_NB;
    tempVoltageMeas2 = tempVoltageMeas2 / CNV_POWERCORE_UNITS_NB;

    COM_powerMeasures.uBusHv = (uint16_t) PWB_measures.Hv_Voltage * 10;
    COM_powerMeasures.uBusLv = (uint16_t) PWB_measures.Lv_Voltage * 10;
    COM_powerMeasures.uBusHvAux = (uint16_t) tempVoltageMeas1;
}

/*!     \brief Update COM module Tx erros and warnings
 *       \param none
 *       \return none
 */
static void com_ComposeFaults(void)
{

    COM_errorsAndWarnings.bbauxErrors = (uint16_t) (ACT_errors.fastPowerDown.all
            + ACT_errors.slowPowerDown.all);
    COM_errorsAndWarnings.bbauxWarnings = ACT_errors.warnings.all;
    COM_errorsAndWarnings.powercoreErrors =
            CNV_powercoreUnitTable[0].flags.moduleFlags.faults.all
                    | CNV_powercoreUnitTable[1].flags.moduleFlags.faults.all;
    COM_errorsAndWarnings.powercoreWarnings =
            CNV_powercoreUnitTable[0].flags.moduleFlags.warns.all
                    | CNV_powercoreUnitTable[1].flags.moduleFlags.warns.all;
    COM_errorsAndWarnings.faultOrigin = (uint32_t) ACT_errors.origin.all;
    COM_errorsAndWarnings.severity = ACT_errors.severity;
}

/*!     \brief Update Control information regul
 *       \param none
 *       \return none
 */
static void com_ComposeControlStatusInfo(void) // TODO : To be completed bucktype !!!
{
    uint32_t tempCurrentLimit = 0;

    uint32_t setpointPAR = 0;
    if (FSM_mode == FSM_MODE_BOOST)
    {
        setpointPAR =
                PAR_paramConfig[PAR_BOOST_VOLTAGE_SETPOINT].realVal.unsignedVal
                        * 10; // * 10 is foth the factor 0.1 in the DBC file

        tempCurrentLimit =
                PAR_paramConfig[PAR_BOOST_CURRENT_LIMIT].realVal.unsignedVal
                        * 10;
    }
    else if (FSM_mode == FSM_MODE_BUCK)
    {
        setpointPAR =
                PAR_paramConfig[PAR_BUCK_VOLTAGE_SETPOINT].realVal.unsignedVal
                        * 10;
        tempCurrentLimit =
                PAR_paramConfig[PAR_BUCK_CURRENT_LIMIT].realVal.unsignedVal
                        * 10;
    }

    COM_controlStatusInfo.currentLimit = (uint16_t) tempCurrentLimit;
    COM_controlStatusInfo.setpoint = setpointPAR;
    COM_controlStatusInfo.powercoreUnitsNb = PWB_numberAvailableCOMETi;
    COM_controlStatusInfo.lvPrechargeStatus =
            PWB_relayCurrentState.stateSwitchS2;
    COM_controlStatusInfo.hvCouplerStatus1 =
            PWB_relayCurrentState.stateSwitchS3;
    COM_controlStatusInfo.healthStatus = CTB_dsoState.Health_State;
    COM_controlStatusInfo.emerstopStatus = CTB_dsiState.EMERSTOP_DSI_State;
    COM_controlStatusInfo.dcdcState = FSM_mode;
    COM_controlStatusInfo.limitationType = getLimitationType();
    COM_controlStatusInfo.buckType = CNV_buckType;
}

static COM_LimitationTypeValuesE getLimitationType(void)
{
    CNV_LimitationTypeValuesE limitationTypeCOMETi1 = 0, limitationTypeCOMETi2 =
            0;
    COM_LimitationTypeValuesE returnVal = 0;

    limitationTypeCOMETi1 = CNV_powercoreUnitTable[0].regulInfo.limitationType;
    limitationTypeCOMETi2 = CNV_powercoreUnitTable[1].regulInfo.limitationType;

    if (limitationTypeCOMETi1 == CNV_LIMITATIONTYPE_TEMPERATURELIMITATION
            || limitationTypeCOMETi2
                    == CNV_LIMITATIONTYPE_TEMPERATURELIMITATION)
    {
        returnVal = COM_LIMITATIONTYPE_TEMPERATURELIMITATION;
    }

    if (limitationTypeCOMETi1 == CNV_LIMITATIONTYPE_POWERLIMITATION
            || limitationTypeCOMETi2 == CNV_LIMITATIONTYPE_POWERLIMITATION)
    {
        returnVal = COM_LIMITATIONTYPE_POWERLIMITATION;
    }

    if (limitationTypeCOMETi1 == CNV_LIMITATIONTYPE_TEMPERATURELIMITATION
            && limitationTypeCOMETi2 == CNV_LIMITATIONTYPE_POWERLIMITATION)
    {
        returnVal = COM_LIMITATIONTYPE_POWERANDTEMP;
    }

    if (limitationTypeCOMETi1 == CNV_LIMITATIONTYPE_POWERLIMITATION
            && limitationTypeCOMETi2
                    == CNV_LIMITATIONTYPE_TEMPERATURELIMITATION)
    {
        returnVal = COM_LIMITATIONTYPE_POWERANDTEMP;
    }

    if (limitationTypeCOMETi1 == CNV_LIMITATIONTYPE_NOLIMITATION
            && limitationTypeCOMETi2 == CNV_LIMITATIONTYPE_NOLIMITATION)
    {
        returnVal = COM_LIMITATIONTYPE_NOLIMITATION;
    }

    return returnVal;

}

