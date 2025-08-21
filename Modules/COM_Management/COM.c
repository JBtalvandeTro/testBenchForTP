/*!
 * \file     COM.c
 * \brief    Brief description of file content
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

/* ---- Includes ---- */
#define COM_MODULE
#include "FSM.h"
#include "COM.h"
#include "CBUs.h"
#include "ACT.h"
#include "Dio.h"
/* ---- Defines ---- */

/* ---- Global variables ---- */
#define CBU_BR_HALF_COUNTS ((uint8_t)CBU_BR_COUNTS / (uint8_t)2)

/* ---- External functions ---- */

/* ---- Static variables ---- */

/* ---- Static functions ---- */

/*LDRA_HEADER_END*/
/*!     \brief Initialization of COM Management Module
 *       \param none
 *       \return none
 */
/*LDRA_INSPECTED 256 S <justification start> No change for reasons of clarity <justification end> */
void COM_Init(void)
{
    uint32_t group;

    COM_errorMasks.error1Mask = 0xFFFFFFFFU;
    COM_errorMasks.error2Mask = 0xFFFFFFFFU;

    // Init CAN status : Enable control, internal and maintenance CANs
    CBU_Init(true, true, true);

    /* COM Tx period related variables */
    for (group = 0; group < ((uint32_t) COM_FRAME_GROUP_COUNT); group++)
    {
        COM_txDelayCounterControl[group] = 0;
        COM_txDelayCounterInternal[group] = 0;
    }
    COM_UpdatePeriodParams();

    /* Initialize all flags */
    COM_flags.all = 0;

    /* Initialize COM_mode */
    COM_mode.currentLimit = 0;
    COM_mode.limitationActive = 0;
    COM_mode.limitationType = 0;
    COM_mode.mainMode = 0;
    COM_mode.regType = 0;
    COM_mode.setpoint = 0;
    COM_mode.startOrder = false;
    COM_mode.startOrderValid = false;

    /* Initialize COM requests */
    COM_paramReq.readRequest = false;
    COM_paramReq.changeRequest = false;
    COM_paramReq.saveRequest = false;
    COM_paramReq.index = 0;
    COM_paramReq.value = 0;
    COM_debugTestReq.relaySwitchTestRequest = false;
    COM_debugTestReq.hvMeasuresTestRequest = false;
    COM_debugTestReq.lvMeasuresTestRequest = false;
    COM_debugTestReq.discreteIosTestRequest = false;
    COM_debugTestReq.ledsTestRequest = false;
    COM_debugTestReq.muxAddress = 0;
    COM_debugTestReq.measFormat = 0;
    COM_debugTestReq.relaySwitchCmd = 0;
    COM_debugTestReq.relaySwitchId = 0;
    COM_debugTestReq.discreteIoCmd = 0;
    COM_debugTestReq.discreteIoId = 0;
    COM_debugTestReq.ledCmd = 0;
    COM_debugTestReq.ledId = 0;
    COM_debugTestReq.ledColor = 0;
    COM_debugTestReq.ledBlinkFreq = 0;
    COM_debugTestReq.relaySwitchResult = 0;
    COM_debugTestReq.discreteIosReadResult = 0;
    COM_debugTestReq.discreteIosPWMResult = 0;
    COM_debugTestReq.rawMeasure = 0;
    COM_debugTestReq.hmiMeasure = 0;

    /* Set power measures to 0 */
    COM_powerMeasures.uBusHv = 0;
    COM_powerMeasures.uBusLv = 0;
    COM_powerMeasures.uBusHvAux = 0;
    COM_powerMeasures.iBusHv = 0;
    COM_powerMeasures.iBusLv = 0;
    COM_powerMeasures.pBusHv = 0;
    COM_powerMeasures.pBusLv = 0;

    /* Set temp measures to 0 */
    COM_tempMeasures.tempHvCoupler = 0;
    COM_tempMeasures.temp1Cometi = 0;
    COM_tempMeasures.temp2Cometi = 0;
    COM_tempMeasures.tempNotif = COM_TEMPNOTIF_NOMINAL;

    /* Set Control Status Info to 0 */
    COM_controlStatusInfo.setpoint = 0;
    COM_controlStatusInfo.currentLimit = 0;
    COM_controlStatusInfo.dcdcState = FSM_mode;
    COM_controlStatusInfo.limitationType = COM_LIMITATIONTYPE_NOLIMITATION;
    COM_controlStatusInfo.lvPrechargeStatus = COM_RELAYSTATUS_OPEN;
    COM_controlStatusInfo.hvCouplerStatus1 = COM_RELAYSTATUS_OPEN;
    COM_controlStatusInfo.buckType = COM_BUCKTYPE_NOINBUCK;
    COM_controlStatusInfo.powercoreUnitsNb = 0;
    COM_controlStatusInfo.emerstopStatus = false;
    COM_controlStatusInfo.healthStatus = false;
    COM_controlStatusInfo.hasNewValues = false;

    /* Set Pbit Results Info to 0 */
    COM_pbitResultsInfo.softwareVersion =
            (uint8_t) PAR_paramConfig[PAR_SW_VERSION].realVal.unsignedVal;
    ;
    COM_pbitResultsInfo.pbitStatus = COM_PBITSTATUS_NOTEXECUTED;
    COM_pbitResultsInfo.lvPrechargeStatus = COM_RELAYPBITSTATUS_NOTTESTED;
    COM_pbitResultsInfo.hvCouplerStatus = COM_RELAYPBITSTATUS_NOTTESTED;
    COM_pbitResultsInfo.dsioStatus = 0;

    COM_Address = 0x00; // this is just for the initialisation the COM_Address and the CBU_Adress will take the value from the Hpp1 and Hpp2 Pbit states
    // power up the CAN transceivers
    Dio_WriteChannel(DioConf_DioChannel_EN_3V3_Power, STD_HIGH);

    // Set CANs bitrate
    CBU_SetBitrate(CBU_CONTROLCAN, CBU_Address, true);
    CBU_SetBitrate(CBU_INTERNALCAN, CBU_Address, true);
    CBU_SetBitrate(CBU_MAINTENANCECAN, CBU_Address, true);

    /* Update flags thanks to CBU ones */
    COM_flags.moduleFlags.status.flags.canCInitialized =
            (boolean) CBU_flags.status.canCInitialized;
    COM_flags.moduleFlags.status.flags.canIInitialized =
            (boolean) CBU_flags.status.canIInitialized;
    COM_flags.moduleFlags.status.flags.canMInitialized =
            (boolean) CBU_flags.status.canMInitialized;
    COM_flags.moduleFlags.status.flags.middlewareInitialized =
            (boolean) CBU_flags.status.middlewareInitialized;

    COM_flags.moduleFlags.faults.flags.canCUninitialized =
            !(boolean) COM_flags.moduleFlags.status.flags.canCInitialized;
    COM_flags.moduleFlags.faults.flags.canIUninitialized =
            !(boolean) COM_flags.moduleFlags.status.flags.canIInitialized;
    COM_flags.moduleFlags.faults.flags.canMUninitialized =
            !(boolean) COM_flags.moduleFlags.status.flags.canMInitialized;
    COM_flags.moduleFlags.faults.flags.middlewareUninitialized =
            !(boolean) COM_flags.moduleFlags.status.flags.middlewareInitialized;
    COM_flags.moduleFlags.faults.flags.unkownCOMETi = 0; // Initialize the error flag to 0 until we detect the error

    // If no fault has been reported, the module is initialized
    if (COM_flags.moduleFlags.faults.all == 0)
    {
        COM_flags.moduleFlags.status.flags.moduleInitialized = true;
    }
    else
    {
        COM_flags.moduleFlags.status.flags.moduleInitialized = false;
    }
}

/*!     \brief Update transmission frame period
 *      \param none
 *      \return none
 */
void COM_UpdatePeriodParams(void)
{
    COM_txPeriodControl[COM_FRAME_GROUP_PWR_MEAS] =
            PAR_paramConfig[PAR_CAN_BASE_TX_PERIOD].realVal.unsignedVal
                    * PAR_paramConfig[PAR_COM_PWR_MEAS_FRAMES_PERIOD].realVal.unsignedVal
                    * COM_TX_PERIODICITY;

    COM_txPeriodControl[COM_FRAME_GROUP_TEMP_MEAS] =
            PAR_paramConfig[PAR_CAN_BASE_TX_PERIOD].realVal.unsignedVal
                    * PAR_paramConfig[PAR_COM_TEMP_MEAS_FRAMES_PERIOD].realVal.unsignedVal
                    * COM_TX_PERIODICITY;

    COM_txPeriodControl[COM_FRAME_GROUP_STATUS] =
            PAR_paramConfig[PAR_CAN_BASE_TX_PERIOD].realVal.unsignedVal
                    * PAR_paramConfig[PAR_COM_STATUS_FRAMES_PERIOD].realVal.unsignedVal
                    * COM_TX_PERIODICITY;

    COM_txPeriodControl[COM_FRAME_GROUP_ALERT] =
            PAR_paramConfig[PAR_CAN_BASE_TX_PERIOD].realVal.unsignedVal
                    * PAR_paramConfig[PAR_COM_ALERT_FRAMES_PERIOD].realVal.unsignedVal
                    * COM_TX_PERIODICITY;

    COM_txPeriodInternal[COM_FRAME_GROUP_COMETI_1] =
            PAR_paramConfig[PAR_CAN_BASE_TX_PERIOD].realVal.unsignedVal
                    * PAR_paramConfig[PAR_COM_INTERNAL_FRAMES_PERIOD].realVal.unsignedVal
                    * COM_TX_PERIODICITY;
    COM_txPeriodInternal[COM_FRAME_GROUP_COMETI_2] =
            PAR_paramConfig[PAR_CAN_BASE_TX_PERIOD].realVal.unsignedVal
                    * PAR_paramConfig[PAR_COM_INTERNAL_FRAMES_PERIOD].realVal.unsignedVal
                    * COM_TX_PERIODICITY;

}

/*!     \brief Deinitialization of COM Management Module
 *       \param none
 *       \return none
 */
void COM_Deinit(void)
{
    // Set the CAN_SLEEP signal to put the CAN transceiver in low power state
    //Dio_WriteChannel(DioConf_DioChannel_CAN_STANDBY, STD_HIGH);

    /* Set variables to default values */
    COM_flags.all = 0;
    COM_Address = 0;
}


void can_Error(void)
{
    // This is a Hardware fault reaction TBD
}
