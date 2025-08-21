/*!
 * \file     COM.h
 * \brief    Brief description of file content
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

#ifndef FILE_COM_H
#define FILE_COM_H

/* ---- Includes ---- */
#include "COMrx.h"
#include "COMtx.h"
#include "TYPedef.h"
#include "CST.h"
#include "FSM.h"

/* ---- Defines ---- */
#define COM_TX_PERIODICITY  10 // ms

typedef enum
{
    COM_FRAME_DIR_RX = 0,
    COM_FRAME_DIR_TX
} COM_FrameDirE;

/**
 * \brief Classes of groups of Control Tx frames
 */
typedef enum
{
    COM_FRAME_GROUP_NONE = 0, /// Default value
    COM_FRAME_GROUP_PWR_MEAS, /// Power Measure Frames
    COM_FRAME_GROUP_TEMP_MEAS, /// Temperature Measure Frames
    COM_FRAME_GROUP_COMETI_1, /// COMETI 1 control frames
    COM_FRAME_GROUP_COMETI_2, /// COMETI 2 control frames
    COM_FRAME_GROUP_ALERT, /// Alerts Frames
    COM_FRAME_GROUP_STATUS, /// Status Frames
    COM_FRAME_GROUP_COUNT
} COM_FrameGroupE;

/**
 * \brief Classes of groups of Control Tx frames
 */
typedef enum
{
    COM_INTERNAL_FRAME_GROUP_NONE = 0, /// Default value
    COM_INTERNAL_FRAME_GROUP_CMD, /// Power Measure Frames
    COM_INTERNAL_FRAME_GROUP_CNTRL, /// Temperature Measure Frames
    COM_INTERNAL_FRAME_GROUP_COUNT
} COM_InternalFrameGroupE;

typedef enum
{
    COM_PAR_REQ_NOACTION = 0,
    COM_PAR_REQ_READ = 1,
    COM_PAR_REQ_UPDATE = 2,
    COM_PAR_REQ_SAVE = 3
} COM_ParReqTypeE;

typedef enum
{
    COM_DBG_REQ_NOACTION = 0,
    COM_DBG_REQ_RELAYSWITCH = 1,
    COM_DBG_REQ_HVMEASURES = 2,
    COM_DBG_REQ_LVMEASURES = 3,
    COM_DBG_REQ_DISCRETEIOS = 4,
    COM_DBG_REQ_LEDS = 5
} COM_DebugTestReqTypeE;

typedef enum
{
    COM_DBG_RELAYSWITCHCMD_NONE = 0,
    COM_DBG_RELAYSWITCHCMD_OPEN = 1,
    COM_DBG_RELAYSWITCHCMD_CLOSE = 2,
    COM_DBG_RELAYSWITCHCMD_READ = 3
} COM_DebugRelaySwitchCmdTypeE;

typedef enum
{
    COM_DBG_RELAYSWITCHID_NONE = 0,
    COM_DBG_RELAYSWITCHID_S1 = 1,
    COM_DBG_RELAYSWITCHID_S2 = 2,
    COM_DBG_RELAYSWITCHID_S3 = 3
} COM_DebugRelaySwitchIdTypeE;

typedef enum
{
    COM_DBG_RELAYSWITCHRES_NONE = 0,
    COM_DBG_RELAYSWITCHRES_OPENED = 1,
    COM_DBG_RELAYSWITCHRES_CLOSED = 2
} COM_DebugRelaySwitchResultTypeE;

typedef enum
{
    COM_DBG_MEASFORMAT_RAW = 0,
    COM_DBG_MEASFORMAT_HMI = 1
} COM_DebugMeasuresFormatTypeE;

typedef enum
{
    COM_DBG_DSIOCMD_NONE = 0,
    COM_DBG_DSIOCMD_SET = 1,
    COM_DBG_DSIOCMD_UNSET = 2,
    COM_DBG_DSIOCMD_READ = 3,
    COM_DBG_DSIOCMD_TEST = 4,
    COM_DBG_DSIOCMD_STOPTEST = 5
} COM_DebugDsioCmdTypeE;

typedef enum
{
    COM_DBG_DSIOID_NONE = 0,
    COM_DBG_DSIOID_DSI_HPP1 = 1,
    COM_DBG_DSIOID_DSI_HPP2 = 2,
    COM_DBG_DSIOID_DSI_SPARE1 = 3,
    COM_DBG_DSIOID_DSI_EMERSTOP = 4,
    COM_DBG_DSIOID_DSI_SPARE2 = 5,
    COM_DBG_DSIOID_DSI_SPAREINT = 6,
    COM_DBG_DSIOID_DSI_MAINT = 7,
    COM_DBG_DSIOID_DSO_HEALTH = 8,
    COM_DBG_DSIOID_DSO_SPARE28VINT = 9,
    COM_DBG_DSIOID_DSO_SPARE1 = 10,
    COM_DBG_DSIOID_DSO_SPAREINT = 11
} COM_DebugDsioIdTypeE;

typedef enum
{
    COM_DBG_DSIORES_NONE = 0,
    COM_DBG_DSIORES_OPENEDOK = 1,
    COM_DBG_DSIORES_CLOSEDFAILED = 2
} COM_DebugDsioResultTypeE;

typedef enum
{
    COM_DBG_LEDCMD_NONE = 0,
    COM_DBG_LEDCMD_ON = 1,
    COM_DBG_LEDCMD_OFF = 2,
    COM_DBG_LEDCMD_BLINK = 3
} COM_DebugLedCmdTypeE;

typedef enum
{
    COM_DBG_LEDID_NONE = 0,
    COM_DBG_LEDID_LED1 = 1,
    COM_DBG_LEDID_LED2 = 2,
    COM_DBG_LEDID_LED3 = 3
} COM_DebugLedIdTypeE;

typedef enum
{
    COM_DBG_LEDCOLOR_GREEN = 0,
    COM_DBG_LEDCOLOR_RED = 1
} COM_DebugLedColorTypeE;

typedef enum
{
    COM_FRAME_CONTROL_TX_CURRENTMEAS = 0,
    COM_FRAME_CONTROL_TX_POWERMEAS,
    COM_FRAME_CONTROL_TX_TEMPERATUREMEAS,
    COM_FRAME_CONTROL_TX_VOLTAGEMEAS,
    COM_FRAME_CONTROL_TX_CONTROLSTATUS,
    COM_FRAME_CONTROL_TX_ERRORSWARNINGS,
    COM_FRAME_CONTROL_TX_PBITRESULTS,
    COM_FRAME_CONTROL_RX_PTCUCMDS,
    COM_FRAME_CONTROL_RX_ERRORRESETREQ,
    COM_FRAMES_CONTROL_COUNT
} COM_FramesControlNameE;

typedef enum
{
    COM_FRAME_INTERNAL_TX_CONTROLREQCOMETI1 = 0,
    COM_FRAME_INTERNAL_TX_MODEREQCOMETI1,
    COM_FRAME_INTERNAL_TX_CONTROLREQCOMETI2,
    COM_FRAME_INTERNAL_TX_MODEREQCOMETI2,
    COM_FRAME_INTERNAL_TX_ERRORRESETREQCOMETI1,
    COM_FRAME_INTERNAL_TX_ERRORRESETREQCOMETI2,
    COM_FRAME_INTERNAL_RX_CURRENTMEAS,
    COM_FRAME_INTERNAL_RX_CURRENTMEASTEMP,
    COM_FRAME_INTERNAL_RX_POWERMEAS,
    COM_FRAME_INTERNAL_RX_TEMPERATUREMEAS,
    COM_FRAME_INTERNAL_RX_VOLTAGEMEAS,
    COM_FRAME_INTERNAL_RX_REGULATIONINFO,
    COM_FRAME_INTERNAL_RX_CONTROLINFO,
    COM_FRAME_INTERNAL_RX_ERRORS,
    COM_FRAME_INTERNAL_RX_WARNINGS,
    COM_FRAMES_INTERNAL_COUNT
} COM_FramesInternalNameE;

typedef enum
{
    COM_FRAME_MAINTENANCE_TX_EQUIPTESTRESP = 0,
    COM_FRAME_MAINTENANCE_TX_PARAMETERRESP,
    COM_FRAME_MAINTENANCE_RX_EQUIPTESTREQ,
    COM_FRAME_MAINTENANCE_RX_PARAMETERREQ,
    COM_FRAMES_MAINTENANCE_COUNT
} COM_FramesMaintenanceNameE;

typedef struct
{
    uint32_t id; // Frame ID
    COM_FrameDirE dir; // TX/RX
    COM_FrameGroupE group; // group for TX frames
    uint32_t offset; // Delay in ms for TX frames
    uint32_t FrameLenght; // Frame lenght
} COM_FrameStr;

/* All COM module fault flags */
typedef struct
{
    boolean moduleUninitialized :1;
    boolean middlewareUninitialized :1;
    boolean canCUninitialized :1;
    boolean canIUninitialized :1;
    boolean canMUninitialized :1;
    boolean pbitFault :1;
    boolean canCComLoss :1;
    boolean canIComLoss :1;
    boolean unkownCOMETi :1;
    uint16_t reserved :7;
} COM_FaultFlagsStr;

/* Union to read all fault flags as an uint16_t */
typedef union
{
    COM_FaultFlagsStr flags;
    uint16_t all;
} COM_FaultFlagsU;

/* All COM module status flags */
typedef struct
{
    boolean moduleInitialized :1;
    boolean middlewareInitialized :1;
    boolean canCInitialized :1;
    boolean canIInitialized :1;
    boolean canMInitialized :1;
    boolean pbitOk :1;
    boolean powerRequest :1;
    boolean settingRequestEnter :1;
    boolean settingRequestExit :1;
    boolean maintenanceRequestEnter :1;
    boolean maintenanceRequestExit :1;
    boolean errorResetRequest :1;
    boolean boostRequest :1;
    boolean buckRequest :1;
    boolean stopRequest :1;
    boolean shutDownReq :1;
    uint16_t reserved :5;
} COM_StatusFlagsStr;

/* Union to read all status flags as an uint16_t */
typedef union
{
    COM_StatusFlagsStr flags;
    uint16_t all;
} COM_StatusFlagsU;

/* Flag structure */
typedef struct
{
    COM_FaultFlagsU faults;
    COM_StatusFlagsU status;
} COM_FlagsStr;

/* Union to read all flags as an uint32_t */
typedef union
{
    COM_FlagsStr moduleFlags;
    uint32_t all;
} COM_FlagsU;

/* All COM module status flags related to Parameter management */
typedef struct
{
    boolean readRequest :1;
    boolean changeRequest :1;
    boolean saveRequest :1;
    uint16_t reserved :13;
    uint16_t index;
    uint32_t value;
} COM_ParamRequestStr;

/* All COM module status flags related to Debug/Test management */
typedef struct
{
    boolean relaySwitchTestRequest :1;
    boolean hvMeasuresTestRequest :1;
    boolean lvMeasuresTestRequest :1;
    boolean discreteIosTestRequest :1;
    boolean ledsTestRequest :1;
    uint32_t reserved :27;
    uint8_t muxAddress;
    uint8_t measFormat;
    uint8_t relaySwitchCmd;
    uint8_t relaySwitchId;
    uint8_t discreteIoCmd;
    uint8_t discreteIoId;
    uint8_t ledCmd;
    uint8_t ledId;
    uint8_t ledColor;
    uint8_t ledBlinkFreq;
    uint8_t relaySwitchResult;
    uint8_t discreteIosReadResult;
    uint8_t discreteIosPWMResult;
    uint32_t rawMeasure;
    uint32_t hmiMeasure;
} COM_DebugTestRequestStr;

typedef enum
{
    COM_SEVERITY_NONE = 0,
    COM_SEVERITY_WARNING = 1,
    COM_SEVERITY_OPERATING = 2,
    COM_SEVERITY_CRITICAL = 3
} COM_SeverityTypeE;

/* Faults structure */
typedef struct
{
    uint16_t bbauxErrors;
    uint16_t bbauxWarnings;
    uint16_t powercoreErrors;
    uint8_t powercoreWarnings;
    COM_SeverityTypeE severity;
    uint32_t faultOrigin;
    boolean hasNewValuesErr :1;
    boolean hasNewValuesWarn :1;
    uint32_t reserved :30;
} COM_ErrorsAndWarningsStr;

/* Power measures structure */
typedef struct
{
    uint16_t uBusHv;
    uint16_t uBusLv;
    uint16_t uBusHvAux;
    uint16_t iBusHv;
    uint16_t iBusLv;
    uint16_t reserved :16;
    uint32_t pBusHv;
    uint32_t pBusLv;
} COM_PowerMeasurementsStr;

typedef enum
{
    COM_TEMPNOTIF_NOMINAL = 0,
    COM_TEMPNOTIF_GENTLEWARN = 1,
    COM_TEMPNOTIF_URGENTWARN = 2,
    COM_TEMPNOTIF_CRITICALTEMP = 3
} COM_TempNotificationTypeE;

/* Temperature measures structure */
typedef struct
{
    uint8_t tempHvCoupler;
    uint8_t temp1Cometi;
    uint8_t temp2Cometi;
    COM_TempNotificationTypeE tempNotif;
} COM_TempMeasurementsStr;

typedef enum
{
    COM_LIMITATIONTYPE_NOLIMITATION = 0U,
    COM_LIMITATIONTYPE_TEMPERATURELIMITATION = 1U,
    COM_LIMITATIONTYPE_POWERLIMITATION = 2U,
    COM_LIMITATIONTYPE_POWERANDTEMP = 3U
} COM_LimitationTypeValuesE;

typedef enum
{
    COM_RELAYSTATUS_OPEN = 0U,
    COM_RELAYSTATUS_CLOSED = 1U
} COM_RelayStatusValuesE;

typedef enum
{
    COM_BUCKTYPE_NOINBUCK = 0U,
    COM_BUCKTYPE_CURRENTSOURCE = 1U,
    COM_BUCKTYPE_VOLTAGEREGULATION = 2U
} COM_BuckTypeValuesE;

/* Control Status info structure */
typedef struct
{
    uint32_t setpoint;
    uint16_t currentLimit;
    FSM_ModesE dcdcState;
    COM_LimitationTypeValuesE limitationType;
    COM_RelayStatusValuesE lvPrechargeStatus;
    COM_RelayStatusValuesE hvCouplerStatus1;
    COM_BuckTypeValuesE buckType;
    uint8_t powercoreUnitsNb;
    boolean emerstopStatus;
    boolean healthStatus;
    boolean hasNewValues;
} COM_ControlStatusInfoStr;

typedef enum
{
    COM_PBITSTATUS_NOTEXECUTED = 0U,
    COM_PBITSTATUS_INPROGRESS = 1U,
    COM_PBITSTATUS_PASS = 2U,
    COM_PBITSTATUS_FAIL = 3U
} COM_PbitStatusValuesE;

typedef enum
{
    COM_RELAYPBITSTATUS_NOTTESTED = 0U,
    COM_RELAYPBITSTATUS_PASS = 1U,
    COM_RELAYPBITSTATUS_FAIL = 2U
} COM_RelayPbitStatusValuesE;

/* Pbit Results info structure */
typedef struct
{
    uint32_t softwareVersion;
    COM_PbitStatusValuesE pbitStatus;
    COM_RelayPbitStatusValuesE lvPrechargeStatus;
    COM_RelayPbitStatusValuesE hvCouplerStatus;
    uint8_t dsioStatus;
} COM_PbitResultsInfoStr;

typedef enum
{
    COM_BBAUXCMD_NONE = 0,
    COM_BBAUXCMD_BOOST = 1,
    COM_BBAUXCMD_BUCK = 2,
    COM_BBAUXCMD_STOP = 3,
    COM_BBAUXCMD_SHUTDOWN = 4
} COM_BbauxCmdTypeE;

/**
 * \brief Rx data to send to ACT module
 */
typedef struct
{
    COM_BbauxCmdTypeE bbauxCommand;
    /// Regulation mode / way
    uint8_t mainMode;
    /// Regulation Type
    uint8_t regType;
    /// Setpoint
    uint32_t setpoint;
    /// Limite en courant - pour mode regulation en tension avec limite en courant
    uint16_t currentLimit;
    /// True if one of the limitation is active
    boolean limitationActive;
    /// Type of the limitation :
    uint8_t limitationType;
    /// Start order
    boolean startOrder;
    boolean startOrderValid;
} COM_BbauxModeStr;

/**
 * \brief Error masks
 */
typedef struct
{
    uint32_t error1Mask;
    uint32_t error2Mask;
} COM_ErrorMaskStr;

/* ---- Global variables ---- */
#ifndef COM_MODULE
extern COM_FlagsU COM_flags;
extern uint8_t COM_Address;
extern COM_ErrorsAndWarningsStr COM_errorsAndWarnings;
extern COM_PowerMeasurementsStr COM_powerMeasures;
extern COM_TempMeasurementsStr COM_tempMeasures;
extern COM_ControlStatusInfoStr COM_controlStatusInfo;
extern COM_PbitResultsInfoStr COM_pbitResultsInfo;
extern COM_FrameStr COM_framesControl[COM_FRAMES_CONTROL_COUNT];
extern COM_FrameStr COM_framesInternal[COM_FRAMES_INTERNAL_COUNT];
extern COM_FrameStr COM_framesMaintenance[COM_FRAMES_MAINTENANCE_COUNT];
extern uint32_t COM_controlComLostCounter;
extern uint32_t COM_internalComLostCounter;
extern COM_BbauxModeStr COM_mode;
extern COM_ParamRequestStr COM_paramReq;
extern COM_DebugTestRequestStr COM_debugTestReq;
extern COM_ErrorMaskStr COM_errorMasks;
extern uint32_t COM_txDelayCounterControl[COM_FRAME_GROUP_COUNT];
extern uint32_t COM_txDelayCounterInternal[COM_FRAME_GROUP_COUNT];
extern uint32_t COM_txPeriodControl[COM_FRAME_GROUP_COUNT];
extern uint32_t COM_txPeriodInternal[COM_FRAME_GROUP_COUNT];
#else
COM_FlagsU                  COM_flags;
uint8_t                     COM_Address;
COM_ErrorsAndWarningsStr    COM_errorsAndWarnings;
COM_PowerMeasurementsStr    COM_powerMeasures;
COM_TempMeasurementsStr     COM_tempMeasures;
COM_ControlStatusInfoStr    COM_controlStatusInfo;
COM_PbitResultsInfoStr      COM_pbitResultsInfo;
uint32_t                    COM_controlComLostCounter;
uint32_t                    COM_internalComLostCounter;
COM_BbauxModeStr            COM_mode;
COM_ParamRequestStr         COM_paramReq;
COM_DebugTestRequestStr     COM_debugTestReq;
COM_ErrorMaskStr            COM_errorMasks;
uint32_t                    COM_txDelayCounterControl[COM_FRAME_GROUP_COUNT];
uint32_t                    COM_txDelayCounterInternal[COM_FRAME_GROUP_COUNT];
uint32_t                    COM_txPeriodControl[COM_FRAME_GROUP_COUNT];
uint32_t                    COM_txPeriodInternal[COM_FRAME_GROUP_COUNT];
const COM_FrameStr          COM_framesControl[COM_FRAMES_CONTROL_COUNT] =
{/*                                                   Id         Frame Dir            Frame Group           Offset Length (Bytes)*/
    {/* COM_FRAME_CONTROL_TX_CURRENTMEAS */       0x00000514u, COM_FRAME_DIR_TX,  COM_FRAME_GROUP_PWR_MEAS,   0u,   4u},
    {/* COM_FRAME_CONTROL_TX_POWERMEAS */         0x00000554u, COM_FRAME_DIR_TX,  COM_FRAME_GROUP_PWR_MEAS,   1u,   8u},
    {/* COM_FRAME_CONTROL_TX_TEMPERATUREMEAS */   0x00000574u, COM_FRAME_DIR_TX,  COM_FRAME_GROUP_TEMP_MEAS,  2u,   4u},
    {/* COM_FRAME_CONTROL_TX_VOLTAGEMEAS */       0x00000534u, COM_FRAME_DIR_TX,  COM_FRAME_GROUP_PWR_MEAS,   3u,   6u},
    {/* COM_FRAME_CONTROL_TX_CONTROLSTATUS */     0x00000334u, COM_FRAME_DIR_TX,  COM_FRAME_GROUP_STATUS ,    4u,   8u},
    {/* COM_FRAME_CONTROL_TX_ERRORSWARNINGS */    0x00000114u, COM_FRAME_DIR_TX,  COM_FRAME_GROUP_ALERT ,     5u,   8u},
    {/* COM_FRAME_CONTROL_TX_PBITRESULTS */       0x00000314u, COM_FRAME_DIR_TX,  COM_FRAME_GROUP_STATUS ,     6u,   7u},
    {/* COM_FRAME_CONTROL_RX_PTCUCMDS */          0x00000414u, COM_FRAME_DIR_RX,  COM_FRAME_GROUP_NONE,       0u,   1u},
    {/* COM_FRAME_CONTROL_RX_ERRORRESETREQ */     0x00000044u, COM_FRAME_DIR_RX,  COM_FRAME_GROUP_NONE,       0u,   0u}
};

const COM_FrameStr          COM_framesInternal[COM_FRAMES_INTERNAL_COUNT] =
{/*                                                   Id         Frame Dir            Frame Group           Offset Length (Bytes)*/
    {/* COM_FRAME_INTERNAL_TX_CONTROLREQCOMETI1 */       0x00100001u, COM_FRAME_DIR_TX,  COM_FRAME_GROUP_COMETI_1,       0u,   7u},
    {/* COM_FRAME_INTERNAL_TX_MODEREQCOMETI1 */          0x00500001u, COM_FRAME_DIR_TX,  COM_FRAME_GROUP_COMETI_1,       1u,   2u},
    {/* COM_FRAME_INTERNAL_TX_CONTROLREQCOMETI2 */       0x00100002u, COM_FRAME_DIR_TX,  COM_FRAME_GROUP_COMETI_2,       2u,   7u},
    {/* COM_FRAME_INTERNAL_TX_MODEREQCOMETI2 */          0x00500002u, COM_FRAME_DIR_TX,  COM_FRAME_GROUP_COMETI_2,       3u,   2u},
    {/* COM_FRAME_INTERNAL_TX_ERRORRESETREQCOMETI1 */    0x05B00001u, COM_FRAME_DIR_TX,  COM_FRAME_GROUP_COMETI_1,       4u,   0u},
    {/* COM_FRAME_INTERNAL_TX_ERRORRESETREQCOEMTI2 */    0x05B00002u, COM_FRAME_DIR_TX,  COM_FRAME_GROUP_COMETI_2,       5u,   0u},
    {/* COM_FRAME_INTERNAL_RX_CURRENTMEAS */      0x03300000u, COM_FRAME_DIR_RX,  COM_FRAME_GROUP_NONE,       0u,   4u},
    {/* COM_FRAME_INTERNAL_RX_CURRENTMEAS */      0x03300002u, COM_FRAME_DIR_RX,  COM_FRAME_GROUP_NONE,       0u,   4u},
    {/* COM_FRAME_INTERNAL_RX_POWERMEAS */        0x03D00000u, COM_FRAME_DIR_RX,  COM_FRAME_GROUP_NONE,       0u,   8u},
    {/* COM_FRAME_INTERNAL_RX_TEMPERATUREMEAS */  0x04700000u, COM_FRAME_DIR_RX,  COM_FRAME_GROUP_NONE,       0u,   8u},
    {/* COM_FRAME_INTERNAL_RX_VOLTAGEMEAS */      0x04800000u, COM_FRAME_DIR_RX,  COM_FRAME_GROUP_NONE,       0u,   4u},
    {/* COM_FRAME_INTERNAL_RX_REGULATIONINFO */   0x06F00000u, COM_FRAME_DIR_RX,  COM_FRAME_GROUP_NONE,     0u,   6u},
    {/* COM_FRAME_INTERNAL_RX_CONTROLINFO */      0x07900000u, COM_FRAME_DIR_RX,  COM_FRAME_GROUP_NONE ,    0u,   4u},
    {/* COM_FRAME_INTERNAL_RX_ERRORS */           0x01F00000u, COM_FRAME_DIR_RX,  COM_FRAME_GROUP_NONE ,     0u,   8u},
    {/* COM_FRAME_INTERNAL_RX_WARNINGS */         0x05500000u, COM_FRAME_DIR_RX,  COM_FRAME_GROUP_NONE ,     0u,   4u}
};

const COM_FrameStr COM_framesMaintenance[COM_FRAMES_MAINTENANCE_COUNT] =
{/*                                                   Id         Frame Dir            Frame Group           Offset Length (Bytes)*/
    {/* COM_FRAME_MAINTENANCE_TX_EQUIPTESTRESP */ 0x08200000U, COM_FRAME_DIR_TX, COM_FRAME_GROUP_NONE ,       0U,   6u},
    {/* COM_FRAME_MAINTENANCE_TX_PARAMETERRESP */ 0x08400000U, COM_FRAME_DIR_TX, COM_FRAME_GROUP_NONE ,       2U,   7u},
    {/* COM_FRAME_MAINTENANCE_RX_EQUIPTESTREQ */  0x08100000U, COM_FRAME_DIR_RX, COM_FRAME_GROUP_NONE ,       0U,   5u},
    {/* COM_FRAME_MAINTENANCE_RX_PARAMETERREQ */  0x08300000U, COM_FRAME_DIR_RX, COM_FRAME_GROUP_NONE ,       0U,   7u}
};
#endif

/* ---- Global functions ---- */
void COM_Init(void);
void COM_Deinit(void);
void COM_UpdatePeriodParams(void);

#endif /* FILE_COM_H */
