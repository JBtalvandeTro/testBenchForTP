/*!
 * \file     PWB.c
 * \brief    implements the functions of the PWB module
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

/* ---- Includes ---- */
#define PWB_MODULE
#include "PWB.h"
#include "FSM.h"
#include "DBG.h"
#include "COM.h"
#include "PAR.h"
#include "SCH.h"
#include "CNV.h"
#include "Pwm.h"
/* ---- Defines ---- */
#define PWB_MAIN_TASK_PERIOD        5U
#define TIMER_TIMEOUT_50MS          10U
#define TIMER_TIMEOUT_S3_1S          200U
#define TIMER_TIMEOUT_PWM_S2_S3          1000U // 5S
#define PWB_MEASUREMENT_ARRAY_SIZE 30U
#define BBAUX_COMETi_MEAS_DELTA 20U // 2v

/* ---- Global variables ---- */

/* ---- External functions ---- */

/* ---- Static variables ---- */

static uint32_t pwb_taskCounter = 0;
static boolean startTimerSdeS1 = false;
static uint32_t timerSdeS1 = 0;
static uint32_t timerSdeS2 = 0;
static uint32_t timerSdeS3 = 0;
static uint32_t timerPwmS2 = 0;
static uint32_t timerPwmS3 = 0;
static uint32_t timerPrechargeAbort = 0;
static uint32_t buck_AutoStopTimer = 0;
static uint32_t psValidTimer = 0;

static uint32_t HvVoltageArray[PWB_MEASUREMENT_ARRAY_SIZE] = { 0 };
static uint32_t LvVoltageArray[PWB_MEASUREMENT_ARRAY_SIZE] = { 0 };
static uint32_t HvCurrentArray[PWB_MEASUREMENT_ARRAY_SIZE] = { 0 };
static uint32_t HvTempArray[PWB_MEASUREMENT_ARRAY_SIZE] = { 0 };

static uint32_t HvVoltageArrayIndex = 0;
static uint32_t LvVoltageArrayIndex = 0;
static uint32_t HvCurrentArrayIndex = 0;
static uint32_t HvTempArrayIndex = 0;

/* ---- Static functions ---- */
static void pwb_UpdateRelayResults(void);
static void pwb_UpdateMeasResults(void);
static void pwb_MaintManagement(void);
static void pwb_PbitManagement(void);
static void pwb_CbitManagement(void);
static void pwb_ControlManagement(void);
static void pwb_PilotSwitch1and2(void);
static boolean pwb_GetStateBattery(void);
static void pwb_prechargeExe(void);
static void pwb_prechargeWaiting(void);
static void pwb_PilotSwitch3(void);
static void pwb_PilotDutyCycleSwitch2And3(void);
static void pwb_CheckRelayConsitency(void);
static void pwb_CheckCometiUnits(void);
static void pwb_CheckVoltageConsistency(void);
static uint32_t pwb_CalculateMeasurementAverage(uint32_t *array, uint32_t size);

/*!     \brief Initialization of PWB Module
 *       \param none
 *       \return none
 */
void PWB_Init(void)
{
    // initialazing the  Sub-Modules
    PWBio_Init();
    PWBCbit_Init();
    PWBPbit_Init();
    PWB_Flags.resultCBit = false;
    PWB_Flags.resultPBit = false;
    PWB_Flags.faults.all = 0;
    PWB_Flags.status.all = 0;

    PWB_measures.VHv_Cometi = 0;
    PWB_measures.VLv_Cometi = 0;
    PWB_measures.Hv_Current = 0;
    PWB_measures.Hv_Temp = 0;
    PWB_measures.Hv_Voltage = 0;
    PWB_measures.Lv_Voltage = 0;

    PWB_relayCurrentCmd.commandSwitchS1 = false;
    PWB_relayCurrentCmd.commandSwitchS2 = false;
    PWB_relayCurrentCmd.commandSwitchS3 = false;

    PWB_relayCurrentState.stateSwitchS2 = false;
    PWB_relayCurrentState.stateSwitchS3 = false;

    PWB_numberAvailableCOMETi = 0;
}

/*!     \brief Periodical task which checks if an update has been requested, and if it's correct
 *       \param none
 *       \return none
 */
void PWB_Update(void)
{
    if (FSM_mode == FSM_MODE_MAINTENANCE)
    {
        pwb_MaintManagement();
    }
    else
    {
        if (FSM_mode == FSM_MODE_PBIT)
        {
            pwb_PbitManagement(); // in PBIT mode do Pbit operations
        }

        pwb_ControlManagement(); // in other modes do CBIT and Control operations
        pwb_CbitManagement();

        if (pwb_taskCounter <= (PWB_MAIN_TASK_PERIOD))
        {
            pwb_taskCounter++;
        }
        else
        {
            pwb_taskCounter = 0;
        }
    }

    // error reset request
    if (COM_flags.moduleFlags.status.flags.errorResetRequest == true)
    {
        PWB_Flags.faults.all = 0;
        PWB_Flags.status.flags.prechargeAborted = false;
    }

}

/*!     \brief Deinitialization of PWB Module
 *       \param none
 *       \return none
 */
void PWB_Deinit(void)
{
    PWBio_Deinit();
    PWBCbit_Deinit();
    PWBPbit_Deinit();
}

/*!     \brief updating the results of the tests or cmds to the COM module
 *       \param none
 *       \return none
 */
static void pwb_UpdateRelayResults(void)
{
    COM_debugTestReq.relaySwitchResult = !PWBio_cmdResults.SwitchReadCmdResult; // the relays are Active level low means that opened is High and Closed is LOW
}

/*!     \brief updating the results of the tests or cmds to the COM module
 *       \param none
 *       \return none
 */
static void pwb_UpdateMeasResults(void)
{
    COM_debugTestReq.hmiMeasure =
            (uint32_t) PWBCbit_cmdResults.ReadMeasResultHMI;
    COM_debugTestReq.rawMeasure = PWBCbit_cmdResults.ReadMeasResultRaw;
}

/*!     \brief MAINT operations
 *       \param none
 *       \return none
 */
static void pwb_MaintManagement(void)
{
    // execute the corresponding function based on the flag raised
    if (DBG_Flags.Reqflags.relaySwitchTest)
    {
        PWBio_RunTests();
        pwb_UpdateRelayResults(); // after executing the cmd we push the result to the COM maint management using this function
        DBG_Flags.Reqflags.relaySwitchTest = false;
    }
    if (DBG_Flags.Reqflags.HvMeasure)
    {
        PWBCbit_GetHvMeasures(COM_debugTestReq.muxAddress);
        pwb_UpdateMeasResults();
        DBG_Flags.Reqflags.HvMeasure = false;
    }
    if (DBG_Flags.Reqflags.LvMeasure)
    {
        PWBCbit_GetLvMeasures(COM_debugTestReq.muxAddress);
        pwb_UpdateMeasResults();
        DBG_Flags.Reqflags.LvMeasure = false;
    }
}

/*!     \brief Pbit operations
 *       \param none
 *       \return none
 */
static void pwb_PbitManagement(void) // Check the operations of the Pbit in the TRS
{
    // Run Pbit tests
    // command S3 => open => check if open
    // command S3 => close => chech if closed
    boolean testTempConsistency = PWBPbit_testTempConsis();
    boolean testHvCoupler = PWBPbit_testHvCouplerRelay();
    boolean testLvPrecharge = PWBPbit_testLvPrechargeRelay();
    if ((testHvCoupler == true) && (testLvPrecharge == true)
            && (testTempConsistency == true))
    {
        // PWB Pbit is ok
        PWB_Flags.resultPBit = true;
    }
    else
    {
        PWB_Flags.resultPBit = false;
        PWB_Flags.faults.flags.hvRelayNok = testHvCoupler;
        PWB_Flags.faults.flags.lvRelayNok = testLvPrecharge;
    }

    PWB_Flags.status.flags.pbitDone = true;
}

/*!     \brief Cbit operations
 *       \param none
 *       \return none
 */
static void pwb_CbitManagement(void)
{
    if (pwb_taskCounter == 0U) // Check over Current
    {
        uint32_t currentThreshold = 0;
        switch (FSM_mode)
        {
            case FSM_MODE_BOOST:
                currentThreshold =
                        PAR_paramConfig[PAR_BBAUX_BOOST_HV_OVERCURRENT_MAX].realVal.unsignedVal;
                break;
            case FSM_MODE_BUCK:
                currentThreshold =
                        PAR_paramConfig[PAR_BBAUX_BUCK_HV_OVERCURRENT_MAX].realVal.unsignedVal;

                break;
            default:
                break;
        }
        if (PWB_measures.Hv_Current > currentThreshold)
        {
            PWB_Flags.faults.flags.overCurrent = true;
        }
        else
        {
            PWB_Flags.faults.flags.overCurrent = false;
        }
    }

    else if (pwb_taskCounter == 1U)
    {
        // check over voltage HV
        uint32_t voltageThreshold = 0;
        switch (FSM_mode)
        {
            case FSM_MODE_BOOST:
                voltageThreshold =
                        PAR_paramConfig[PAR_BBAUX_BOOST_HV_OVERVOLTAGE_MAX].realVal.unsignedVal;
                break;
            case FSM_MODE_BUCK:
                voltageThreshold =
                        PAR_paramConfig[PAR_BBAUX_BUCK_HV_OVERVOLTAGE_MAX].realVal.unsignedVal;
                break;
            default:
                break;
        }
        if (PWB_measures.Hv_Voltage > voltageThreshold
                && ((FSM_mode == FSM_MODE_BOOST) || (FSM_mode == FSM_MODE_BUCK)))
        {
            PWB_Flags.faults.flags.overVolt = true;
        }
        else
        {
            PWB_Flags.faults.flags.overVolt = false;
        }
    }

    else if (pwb_taskCounter == 2U)
    {
        pwb_CheckCometiUnits();
        // check HV LV measurement consistency between SPI and COMETi
        // TODO : raise the fault flag if there is an overvoltage ignore 1 single different measure each time the error is reset
        pwb_CheckVoltageConsistency();
    }

    else if (pwb_taskCounter == 3U)
    {
        // check over voltage LV
        uint32_t voltageThreshold = 0;
        switch (FSM_mode)
        {
            case FSM_MODE_BOOST:
                voltageThreshold =
                        PAR_paramConfig[PAR_BBAUX_BOOST_LV_OVERVOLTAGE_MAX].realVal.unsignedVal;
                break;
            case FSM_MODE_BUCK:
                voltageThreshold =
                        PAR_paramConfig[PAR_BBAUX_BUCK_LV_OVERVOLTAGE_MAX].realVal.unsignedVal;
                break;
            default:
                break;
        }
        if (PWB_measures.Lv_Voltage > voltageThreshold
                && ((FSM_mode == FSM_MODE_BOOST) || (FSM_mode == FSM_MODE_BUCK)))
        {
            PWB_Flags.faults.flags.overVolt = true;
        }
        else
        {
            PWB_Flags.faults.flags.overVolt = false;
        }
    }
    else if (pwb_taskCounter == 4U) // TRS TRO_50073_50147_001_TRS_0070
    {
        pwb_CheckRelayConsitency();
    }
    else if (pwb_taskCounter == 5U)
    {
        PWBCBit_UpdatePsValidState();
        uint32_t parPsvalid_Timeout =
                PAR_paramConfig[PAR_ACTIVITY_EXTENSION_TIMER].realVal.unsignedVal;
        if (PWB_psValidState == false)
        {
            if (psValidTimer >= parPsvalid_Timeout)
            {
                PWB_Flags.faults.flags.powerSupplyDown = false; // TODO change later went the psvalid is tested
                PWB_Flags.faults.flags.activityextensionTimerElapsed = true;
            }
            else
            {
                psValidTimer = psValidTimer + 5; // gets exectued each 5ms
            }
        }
        else
        {
            PWB_Flags.faults.flags.powerSupplyDown = false;
            psValidTimer = 0;
        }
    }
    else
    {
    }
}

/*!     \brief Control operations
 *       \param none
 *       \return none
 */
static void pwb_ControlManagement(void)
{

    if (pwb_taskCounter == 0U)
    {
        PWBCbit_GetHvMeasures(Hv_Current_Meas_Mux);
        if (PWBCbit_cmdResults.ReadMeasResultHMI < 0)
        {
            HvCurrentArray[HvCurrentArrayIndex] = 0;
        }
        else
        {
            HvCurrentArray[HvCurrentArrayIndex] =
                    (uint32_t) PWBCbit_cmdResults.ReadMeasResultHMI;
        }

        if (HvCurrentArrayIndex == PWB_MEASUREMENT_ARRAY_SIZE - 1)
        {
            PWB_measures.Hv_Current = pwb_CalculateMeasurementAverage(
                    HvCurrentArray, PWB_MEASUREMENT_ARRAY_SIZE);
            HvCurrentArrayIndex = 0;
        }
        else
        {
            HvCurrentArrayIndex++;
        }
    }
    else if (pwb_taskCounter == 1U)
    {
        PWBCbit_GetHvMeasures(Hv_Voltage_Meas_Mux);
        HvVoltageArray[HvVoltageArrayIndex] =
                (uint32_t) PWBCbit_cmdResults.ReadMeasResultHMI;
        if (HvVoltageArrayIndex == PWB_MEASUREMENT_ARRAY_SIZE - 1)
        {
            PWB_measures.Hv_Voltage = pwb_CalculateMeasurementAverage(
                    HvVoltageArray, PWB_MEASUREMENT_ARRAY_SIZE);
            HvVoltageArrayIndex = 0;
        }
        else
        {
            HvVoltageArrayIndex++;
        }
    }
    else if (pwb_taskCounter == 2U)
    {
        PWBCbit_GetHvMeasures(Hv_Temp_Meas_Mux);
        if (PWBCbit_cmdResults.ReadMeasResultHMI < 0)
        {
            HvTempArray[HvTempArrayIndex] = 0;
        }
        else
        {
            HvTempArray[HvTempArrayIndex] =
                    (uint32_t) PWBCbit_cmdResults.ReadMeasResultHMI;
        }
        if (HvTempArrayIndex == PWB_MEASUREMENT_ARRAY_SIZE - 1)
        {
            PWB_measures.Hv_Temp = pwb_CalculateMeasurementAverage(HvTempArray,
            PWB_MEASUREMENT_ARRAY_SIZE);
            HvTempArrayIndex = 0;
        }
        else
        {
            HvTempArrayIndex++;
        }
    }
    else if (pwb_taskCounter == 3U)
    {
        PWBCbit_GetLvMeasures(Lv_Voltage_Meas_Mux);
        LvVoltageArray[LvVoltageArrayIndex] =
                (uint32_t) PWBCbit_cmdResults.ReadMeasResultHMI;
        if (LvVoltageArrayIndex == PWB_MEASUREMENT_ARRAY_SIZE - 1)
        {
            PWB_measures.Lv_Voltage = pwb_CalculateMeasurementAverage(
                    LvVoltageArray, PWB_MEASUREMENT_ARRAY_SIZE);
            LvVoltageArrayIndex = 0;
        }
        else
        {
            LvVoltageArrayIndex++;
        }
    }
    else if (pwb_taskCounter == 4U)
    {
        // read the measures from the COMETies
        PWB_measures.VLv_Cometi =
                (uint32_t) ((CNV_powercoreUnitTable[0].powerMeas.vBus2
                        + CNV_powercoreUnitTable[1].powerMeas.vBus2)
                        / CNV_POWERCORE_UNITS_NB);
        PWB_measures.VHv_Cometi =
                (uint32_t) ((CNV_powercoreUnitTable[0].powerMeas.vBus1
                        + CNV_powercoreUnitTable[1].powerMeas.vBus1)
                        / CNV_POWERCORE_UNITS_NB);
        PWB_measures.ILv_Cometi =
                (uint32_t) (CNV_powercoreUnitTable[0].powerMeas.iBus2
                        + CNV_powercoreUnitTable[1].powerMeas.iBus2);
        PWB_measures.IHv_Cometi =
                (uint32_t) (CNV_powercoreUnitTable[0].powerMeas.iBus1
                        + CNV_powercoreUnitTable[1].powerMeas.iBus1);

    }
    else if (pwb_taskCounter == 5U) // TRS TRO_50073_50147_001_TRS_0072 and TRO_50073_50147_001_TRS_0074
    {
        pwb_PilotSwitch1and2();
        pwb_PilotSwitch3();
        pwb_PilotDutyCycleSwitch2And3();
    }
}

/*!     \brief Control the Relay switchs
 *       \param none
 *       \return none
 */
static void pwb_PilotSwitch1and2(void) // TRO_50073_50147_001_TRS_0072
{
    boolean batteryPlugged = pwb_GetStateBattery(); // check if the battery is plugged

    uint32_t parPrechargeStopDelta = 0;
    parPrechargeStopDelta =
            PAR_paramConfig[PAR_LV_PRECHARGE_STOP_DELTA].realVal.unsignedVal;

    uint32_t tempVlvCometi = (uint32_t) PWB_measures.VLv_Cometi; // For info the VLv Cometi has already a 0.1 factor (*10) from COMETi units

    if (batteryPlugged == true
            && ((FSM_mode == FSM_MODE_BOOST) || (FSM_mode == FSM_MODE_BUCK))
            && (PWB_Flags.status.flags.prechargeAborted == false))
    {
        if ((PWB_measures.Lv_Voltage
                > (uint32_t) (tempVlvCometi - parPrechargeStopDelta)) // check if the voltage on the battery side is the same as the COEMTi side
                && (PWB_measures.Lv_Voltage
                        < (uint32_t) (tempVlvCometi + parPrechargeStopDelta)))
        {
            pwb_prechargeExe();
        }
        else
        {
            pwb_prechargeWaiting();
        }
    }
    else
    {
        if (FSM_mode == FSM_MODE_BUCK)
        {
            // close S2
            PWBio_SetCdeSwitch(SwitchCdeS2);
            PWB_relayCurrentCmd.commandSwitchS2 = true;
            PWBio_UnsetCdeSwitch(SwitchCdeS1);
            PWB_relayCurrentCmd.commandSwitchS1 = false;
            PWB_Flags.status.flags.prechargeDone = true;
        }
    }
}

static boolean pwb_GetStateBattery(void)
{
    uint32_t parPrechargeStartCondition = 0;
    parPrechargeStartCondition =
            PAR_paramConfig[PAR_LV_PRECHARGE_START_CONDITION].realVal.unsignedVal;

    if (PWB_measures.Lv_Voltage >= parPrechargeStartCondition) // check if the battery is plugged
    {
        return true;
    }
    else
    {
        return false;
    }
}

static void pwb_prechargeExe(void)
{

    if (timerSdeS2 >= TIMER_TIMEOUT_50MS) // wait 50ms
    {
        PWBio_SetCdeSwitch(SwitchCdeS2); // close S2
        PWB_relayCurrentCmd.commandSwitchS2 = true;
        timerSdeS2 = 0;
        startTimerSdeS1 = true;
    }
    else
    {
        timerSdeS2++;
    }
    if (startTimerSdeS1 == true) // check if we are ready to open the S1
    {
        if (timerSdeS1 >= TIMER_TIMEOUT_50MS) // wait 50ms
        {
            PWBio_UnsetCdeSwitch(SwitchCdeS1); // open S1
            PWB_relayCurrentCmd.commandSwitchS1 = false;
            PWB_Flags.status.flags.prechargeDone = true;
            timerSdeS1 = 0;
            startTimerSdeS1 = false;
        }
        else
        {
            timerSdeS1++;
        }
    }
    else
    {
        // do nothing wait for the S2 to be closed
    }
}

static void pwb_prechargeWaiting(void)
{
    // close S1
    PWBio_SetCdeSwitch(SwitchCdeS1);
    PWB_relayCurrentCmd.commandSwitchS1 = true;
    PWB_Flags.status.flags.prechargeDone = false;
    // check if we need to abort the precharge beceause the timer is done
    uint32_t timerParam =
            PAR_paramConfig[PAR_LV_PRECHARGE_DURATION_MAX].realVal.unsignedVal;
    if (timerPrechargeAbort >= timerParam)
    {
        PWB_Flags.status.flags.prechargeAborted = true;
        timerPrechargeAbort = 0;
    }
    else
    {
        timerPrechargeAbort++;
        PWB_Flags.status.flags.prechargeAborted = false;
    }
}
/*!     \brief Control the Relay switchs
 *       \param none
 *       \return none
 */
static void pwb_PilotSwitch3(void)
{
    uint32_t parHvBypassStartCondition = 0;
    parHvBypassStartCondition =
            PAR_paramConfig[PAR_HV_DIOD_BYPASS_START_CONDITION].realVal.unsignedVal;
    uint32_t parHvBypassStopCondition = 0;
    parHvBypassStopCondition =
            PAR_paramConfig[PAR_HV_DIOD_BYPASS_STOP_CONDITION].realVal.unsignedVal;

    if (FSM_mode == FSM_MODE_S3MODE)
    {
        // check if the S3 req is set to True
        if (COM_mode.S3ModeReq == true)
        {
            PWBio_SetCdeSwitch(SwitchCdeS3);
            PWB_relayCurrentCmd.commandSwitchS3 = true; // if yes close S3
        }
        else
        {
            PWBio_UnsetCdeSwitch(SwitchCdeS3);
            PWB_relayCurrentCmd.commandSwitchS3 = true;
        }
    }
    else
    {
        if ((PWB_measures.Hv_Voltage > parHvBypassStartCondition)
                && (FSM_mode != FSM_MODE_BOOST))
        {
            //start a timer
            if (timerSdeS3 >= TIMER_TIMEOUT_S3_1S)
            {
                // when time is out set the cde S3 to true
                PWBio_SetCdeSwitch(SwitchCdeS3);
                PWB_relayCurrentCmd.commandSwitchS3 = true;
                timerSdeS3 = 0;
            }
            else
            {
                timerSdeS3++;
            }
        }
        else
        {

        }
        if (PWB_measures.Hv_Voltage < parHvBypassStopCondition)
        {
            PWBio_UnsetCdeSwitch(SwitchCdeS3);
            PWB_relayCurrentCmd.commandSwitchS3 = false;
        }
        else
        {

        }
    }
}

static void pwb_PilotDutyCycleSwitch2And3(void)
{
    if (PWB_relayCurrentCmd.commandSwitchS3 == true)
    {
        if (timerPwmS3 >= TIMER_TIMEOUT_PWM_S2_S3)
        {
            PWBio_LowerDutyCycleS3 = true;
        }
        else
        {
            timerPwmS3++;
        }
    }
    else
    {
        PWBio_LowerDutyCycleS3 = false;
        timerPwmS3 = 0;
    }

    if (PWB_relayCurrentCmd.commandSwitchS2 == true)
    {
        if (timerPwmS2 >= TIMER_TIMEOUT_PWM_S2_S3)
        {
            PWBio_LowerDutyCycleS2 = true;
        }
        else
        {
            timerPwmS2++;
        }
    }
    else
    {
        PWBio_LowerDutyCycleS2 = false;
        timerPwmS2 = 0;
    }

}

static void pwb_CheckCometiUnits(void)
{
    // check for over current

    uint32_t currentThresholdLV = 0;
    uint32_t currentThresholdHV = 0;
    switch (FSM_mode)
    {
        case FSM_MODE_BOOST:
            currentThresholdLV =
                    PAR_paramConfig[PAR_COMETI_BOOST_LV_OVERCURRENT_MAX].realVal.unsignedVal;
            currentThresholdHV =
                    PAR_paramConfig[PAR_COMETI_BOOST_HV_OVERCURRENT_MAX].realVal.unsignedVal;
            break;
        case FSM_MODE_BUCK:
            currentThresholdLV =
                    PAR_paramConfig[PAR_COMETI_BUCK_LV_OVERCURRENT_MAX].realVal.unsignedVal;
            currentThresholdHV =
                    PAR_paramConfig[PAR_COMETI_BUCK_HV_OVERCURRENT_MAX].realVal.unsignedVal;
            break;
        default:
            break;
    }
    if ((PWB_measures.IHv_Cometi > currentThresholdHV)
            || (PWB_measures.ILv_Cometi > currentThresholdLV))
    {
        PWB_Flags.faults.flags.overCurrent = true;
    }
    else
    {
        PWB_Flags.faults.flags.overCurrent = false;
    }

    // check for availablity
    PWB_numberAvailableCOMETi = 0;
    if ((CNV_powercoreUnitTable[0].regulInfo.softMode
            == CNV_SOFTWAREMODE_STANDBY)
            || (CNV_powercoreUnitTable[0].regulInfo.softMode
                    == CNV_SOFTWAREMODE_RUNNING))
    {
        PWB_numberAvailableCOMETi++;
    }
    else
    {
    }
    if ((CNV_powercoreUnitTable[1].regulInfo.softMode
            == CNV_SOFTWAREMODE_STANDBY)
            || (CNV_powercoreUnitTable[1].regulInfo.softMode
                    == CNV_SOFTWAREMODE_RUNNING))
    {
        PWB_numberAvailableCOMETi++;
    }
    else
    {
    }

    if (PWB_numberAvailableCOMETi < 1)
    {
        PWB_Flags.faults.flags.unavailableCometi = true;
    }
    else
    {
        PWB_Flags.faults.flags.unavailableCometi = false;
    }
    // check for auto stop conversion

    if (FSM_mode == FSM_MODE_BOOST)
    {
        uint32_t boostEndDelta =
                PAR_paramConfig[PAR_BOOST_AUTONOMOUS_END_DELTA].realVal.unsignedVal;
        if (PWB_measures.Hv_Voltage > PWB_measures.VHv_Cometi + boostEndDelta)
        {
            PWB_Flags.faults.flags.stopBoostConversion = true;
        }
        else
        {
            PWB_Flags.faults.flags.stopBoostConversion = false;
        }
    }
    else
    {
        PWB_Flags.faults.flags.stopBoostConversion = false;
    }
    if (FSM_mode == FSM_MODE_BUCK)
    {
        uint32_t buckminVoltage =
                PAR_paramConfig[PAR_BUCK_CURRENTSOURCE_MINVOLTAGE].realVal.unsignedVal;
        uint32_t buckAutoEndTimeOut =
                PAR_paramConfig[PAR_BUCK_CURRENTSOURCE_MAXDURATION].realVal.unsignedVal;
        buckminVoltage = buckminVoltage * 10; // there's a factor 0.1 on the VLV COMETI so the BUCK min voltage shall be multiplied by 10
        if (PWB_measures.VLv_Cometi < buckminVoltage)
        {
            buck_AutoStopTimer += 5; // this function get exectuted each 5 ms
        }
        else
        {
            buck_AutoStopTimer = 0;
        }
        if (buck_AutoStopTimer >= buckAutoEndTimeOut)
        {
            PWB_Flags.faults.flags.stopBuckConversion = true;
        }
        else
        {
            PWB_Flags.faults.flags.stopBuckConversion = false;
        }

    }
    else
    {
        PWB_Flags.faults.flags.stopBuckConversion = false;
    }

}

static void pwb_CheckRelayConsitency(void)
{
// check Hv and Lv relay consistency
// raise the fault flag if there is a non working cmd
    PWB_relayCurrentState.stateSwitchS2 = !PWBio_ReadAuxSwitch(AuxS2);
    PWB_relayCurrentState.stateSwitchS3 = !PWBio_ReadAuxSwitch(AuxS3);
    if ((PWB_relayCurrentCmd.commandSwitchS2 == true)
            && (PWB_relayCurrentState.stateSwitchS2 == false))
    {
        PWB_Flags.faults.flags.lvRelayNok = true;
    }
    else if ((PWB_relayCurrentCmd.commandSwitchS2 == false)
            && (PWB_relayCurrentState.stateSwitchS2 == true))
    {
        PWB_Flags.faults.flags.relayCmdWarning = true;
    }
    else if (PWB_relayCurrentCmd.commandSwitchS2
            == PWB_relayCurrentState.stateSwitchS2)
    {
        PWB_Flags.faults.flags.relayCmdWarning = false;
    }

    if ((PWB_relayCurrentCmd.commandSwitchS3 == false)
            && (PWB_relayCurrentState.stateSwitchS3 == true))
    {
        if (FSM_mode == FSM_MODE_BOOST)
        {
            PWB_Flags.faults.flags.hvRelayNok = true;
        }
        else
        {
            PWB_Flags.faults.flags.relayCmdWarning = true;
        }
    }
    else if ((PWB_relayCurrentCmd.commandSwitchS3 == true)
            && (PWB_relayCurrentState.stateSwitchS3 == false))
    {
        PWB_Flags.faults.flags.relayCmdWarning = true;
    }
    else if (PWB_relayCurrentCmd.commandSwitchS3
            == PWB_relayCurrentState.stateSwitchS3)
    {
        PWB_Flags.faults.flags.relayCmdWarning = false;
    }
}

static void pwb_CheckVoltageConsistency(void) // TRO_50073_50147_001_TRS_0142 and TRO_50073_50147_001_TRS_0146
{
    if (PWB_Flags.status.flags.prechargeDone == true)
    {
        if ((PWB_measures.Lv_Voltage
                >= PWB_measures.VLv_Cometi + BBAUX_COMETi_MEAS_DELTA) // if there's too much diffrence between the VLV and LV+
                || (PWB_measures.Lv_Voltage
                        <= PWB_measures.VLv_Cometi - BBAUX_COMETi_MEAS_DELTA))
        {
            PWB_Flags.faults.flags.lvVoltMeas = true; // raise the flag
        }
        else
        {
            // do nothing wait for error reset request
        }
    }
    if ((FSM_mode == FSM_MODE_BUCK) && (PWB_measures.Hv_Current > 0))
    {
        if ((PWB_measures.Hv_Voltage
                >= PWB_measures.VHv_Cometi + BBAUX_COMETi_MEAS_DELTA)
                || (PWB_measures.Hv_Voltage
                        <= PWB_measures.VHv_Cometi - BBAUX_COMETi_MEAS_DELTA)) // if there's too much diffrence between the VHV and HV+
        {
            PWB_Flags.faults.flags.hvVoltMeas = true; // raise the flag
        }
        else
        {
            // do nothing wait for error reset request
        }
    }

}

static uint32_t pwb_CalculateMeasurementAverage(uint32_t *array, uint32_t size)
{
    if (array == NULL || size <= 0)
    {
        return 0; // Return 0 if the array is invalid or size is non-positive
    }

    int sum = 0;
    for (size_t i = 0; i < size; i++)
    {
        sum += array[i];
    }

    return (uint32_t) (sum / size); // Return the truncated average as an integer
}
