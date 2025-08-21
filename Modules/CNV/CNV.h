/*!
 * \file     CNV.h
 * \brief    Brief description of file content
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

#ifndef FILE_CNV_H
#define FILE_CNV_H

/* ---- Includes ---- */
#include "TYPedef.h"
#include "CST.h"

/* ---- Defines ---- */
#define CNV_POWERCORE_UNITS_NB 2U

typedef enum
{
    START_BUCK_CONVERSION,
    START_BOOST_CONVERSION,
    STOP_CONVERSION
} CNV_ConversionCmd;

typedef enum
{
    CNV_SOFTWAREMODE_EMERGENCY = 0,
    CNV_SOFTWAREMODE_STANDBY = 1,
    CNV_SOFTWAREMODE_RUNNING = 2,
    CNV_SOFTWAREMODE_POWERDOWN = 3,
    CNV_SOFTWAREMODE_SETTINGS = 4, // impossible in BB-AUX case
    CNV_SOFTWAREMODE_MAINTENANCE = 5, // impossible in BB-AUX case
    CNV_SOFTWAREMODE_INIT = 0xFF
} CNV_SoftwareModesE;

typedef enum
{
    CNV_REGTYPE_NOT_SET = 0U,
    CNV_REGTYPE_VBUS2 = 1U,
    CNV_REGTYPE_VBUS1 = 2U,
    CNV_REGTYPE_IBUS2 = 3U,
    CNV_REGTYPE_IBUS1 = 4U,
    CNV_REGTYPE_PBUS2 = 5U,
    CNV_REGTYPE_PBUS1 = 6U,
    CNV_REGTYPE_VBUS2_ILIM = 7U,
    CNV_REGTYPE_VBUS1_ILIM = 8U,
    CNV_REGTYPE_COUNT,
} CNV_RegulationTypesE;

/// Control loop main modes
typedef enum
{
    CNV_REGMODE_NOT_SET = 0U,
    CNV_REGMODE_BUS1TOBUS2 = 1U,
    CNV_REGMODE_BUS2TOBUS1 = 2U,
    CNV_REGMODE_BIDIRECTIONAL = 3U,
    CNV_REGMODE_COUNT
} CNV_RegulationModesE;

// Error Reset Request for Each COMETi
typedef enum
{
    COMETi1_ErrorResetReq = 0U,
    COMETi2_ErrorResetReq
} CNV_ErrorResetRequestE;

// Error mask for critical and Functional error
typedef enum
{
    CNV_FONCTIONAL_ERROR_MASK_ALL_ERRORS   = 0x0000,
    CNV_CRITICAL_ERROR_MASK_ALL_ERRORS     = 0x0000,
    CNV_FUNCTIONAL_ERROR_MASK_VBUS1_MIN    = 0xFFFE,
    CNV_CRITICAL_ERROR_MASK_VBUS1_MINS     = 0xFFFE,
    CNV_FUNCTIONAL_ERROR_MASK_VBUS2_MIN    = 0xFFFB,
    CNV_CRITICAL_ERROR_MASK_VBUS2_MINS     = 0xFFFB,
    CNV_FUNCTIONAL_ERROR_UNMASK_ALL_ERRORS    = 0xFFFF,
    CNV_CRITICAL_ERROR_UNMASK_ALL_ERRORSS     = 0xFFFF
} CNV_ErrorCritAndFuncMaskE;

typedef enum
{
    CNV_LIMITATIONTYPE_NOLIMITATION = 0U,
    CNV_LIMITATIONTYPE_TEMPERATURELIMITATION = 1U,
    CNV_LIMITATIONTYPE_RAMPLIMITATION = 2U,
    CNV_LIMITATIONTYPE_POWERLIMITATION = 4U
} CNV_LimitationTypeValuesE;

// Types and Defines -----------------------------------------------------------

typedef struct
{
    boolean vbus1MinCritical :1;
    boolean vbus1MaxCritical :1;
    boolean vbus2MinCritical :1;
    boolean vbus2MaxCritical :1;
    boolean vbusAuxMinCritical :1;
    boolean vbusAuxMaxCritical :1;
    boolean iBus1Leg1MaxCritical :1;
    boolean iBus1Leg2MaxCritical :1;
    boolean iBus2Leg1MaxCritical :1;
    boolean iBus2Leg2MaxCritical :1;
    boolean parameters :1;
    boolean powerMap :1;
    boolean fpgaLost :1;
    boolean mcuClockUnsync :1;
    boolean fpgaClockUnsync :1;
    boolean servicePowerSupplyLostMcu :1;
    boolean servicePowerSupplyLostFpga :1;
    boolean inoperationalCurrentSensor :1;
    boolean inoperationalVoltageSensor :1;
    unsigned int reserved :13;
} CNV_CometiCriticalErrorStr; // COMETI Fast PowerDown Errors

typedef union
{
    CNV_CometiCriticalErrorStr flags;
    uint32_t value;
} CNV_CometiCriticalErrorU;

typedef struct
{
    boolean vbus1Min :1;
    boolean vbus1Max :1;
    boolean vbus2Min :1;
    boolean vbus2Max :1;
    boolean iBus1Leg1Max :1;
    boolean iBus1Leg2Max :1;
    boolean iBus2Leg1Max :1;
    boolean iBus2Leg2Max :1;
    boolean CoolantTempMinCritical :1;
    boolean CoolantTempMaxCritical :1;
    boolean ambientTempMinCritical :1;
    boolean ambientTempMaxCritical :1;
    boolean mosfetTempMaxCritical :1;
    boolean transformerTempMaxCritical :1;
    boolean selfTempMaxCritical :1;
    boolean selfBoostTempMaxCritical :1;
    boolean comIsLost :1;
    boolean unknownControlMode :1;
    boolean unknownControlType :1;
    boolean incompatibleCtrlModeType :1;
    boolean controlLoopNotSet :1;
    boolean inoperationalTemperatureSensor :1;
    unsigned int reserved :10;
} CNV_CometiFunctionalErrorStr; // COMETI Slow PowerDown Errors

typedef union
{
    CNV_CometiFunctionalErrorStr flags;
    uint32_t value;
} CNV_CometiFunctionalErrorU;

typedef struct
{
    boolean highOutCoolantTemp :1;
    boolean highInCoolantTemp :1;
    boolean highAmbientTemp :1;
    boolean highMosfetTemp :1;
    boolean highTransformerTemp :1;
    boolean highSelfTemp :1;
    boolean highCoolantDeltaTemp :1;
    boolean setPointUnreachableTooLow :1; // Should never happen in BB-AUX otherwise set componentSwWarning
    boolean setPointUnreachableTooHigh :1; // Should never happen in BB-AUX otherwise set componentSwWarning
    boolean controlTypeChangeNotAllowed :1; // Should never happen in BB-AUX otherwise set componentSwWarning
    boolean backupApplicationStarted :1;
    boolean backupParametersLoaded :1;
    unsigned int reserved :20;
} CNV_CometiWarningStr;

typedef union
{
    CNV_CometiWarningStr flags;
    uint32_t value;
} CNV_CometiWarningU;

/// Errors of the CNV Manager Library
typedef enum
{
    /// No error **MUST** be 0
    CNV_ERROR_NO_ERROR = 0U,
    /// The count of errors
    CNV_ERROR_COUNT
} CNV_ErrorsE;

/* Error flags of CNV module */
typedef struct
{
    boolean uBusHvMin :1;
    boolean uBusLvMin :1;
    boolean uBusHvMax :1;
    boolean uBusLvMax :1;
    boolean iBusHvMax :1;
    boolean iBusLvMax :1;
    boolean CoolantTempMinCritical :1;
    boolean CoolantTempMaxCritical :1;
    boolean ambientTempCritical :1;
    boolean otherTempCritical :1;
    boolean uBusHvMaxCritical :1;
    boolean uBusLvMaxCritical :1;
    boolean iBusHvMaxCritical :1;
    boolean iBusLvMaxCritical :1;
    boolean componentInternalError :1;
    boolean reserved :1;
} CNV_FaultFlagsStr; // Powercore Errors retained

/* Warning flags of CNV module */
typedef struct
{
    boolean outCoolantTemp :1;
    boolean inCoolantTemp :1;
    boolean ambientTemp :1;
    boolean mosfetTemp :1;
    boolean transformerTemp :1;
    boolean selfTemp :1;
    boolean coolantDeltaTemp :1;
    boolean componentSwWarn :1;
} CNV_WarnFlagsStr; // Powercore Warnings retained

/* Status flags of CNV module */
typedef struct
{
    boolean moduleInitialized :1;
    boolean comLost :1;
    boolean hasNewValuesErr :1; // useful ?
    boolean hasNewValuesWarn :1; // useful ?
    boolean no_stub_error_req :1;
    boolean boost_stub_error_req :1;
    boolean buck_stub_error_req :1;
    uint8_t reserved :1;
} CNV_StatusFlagsStr;

/* Flag unions to be able to check them in one instruction */
typedef union
{
    CNV_FaultFlagsStr flags;
    uint16_t all;
} CNV_FaultFlagsU;

typedef union
{
    CNV_WarnFlagsStr flags;
    uint8_t all;
} CNV_WarnFlagsU;

typedef union
{
    CNV_StatusFlagsStr flags;
    uint8_t all;
} CNV_StatusFlagsU;

/* Structure to unite Errors, Warnings and Status regs */
typedef struct
{
    CNV_FaultFlagsU faults; //16
    CNV_WarnFlagsU warns; //8
    CNV_StatusFlagsU status; //8
} CNV_FlagsStr;

/* Flag structures union to be able to check them in one instruction */
typedef union
{
    CNV_FlagsStr moduleFlags;
    uint32_t all;
} CNV_FlagsU;

/* Power measures structure */
typedef struct
{
    uint16_t vBus1;
    uint16_t vBus2;
    uint16_t iBus1;
    uint16_t iBus2;
    uint32_t pBus1;
    uint32_t pBus2;
} CNV_PowerMeasurementsStr;

/* Temp measures structure */
typedef struct
{
    uint8_t temp1; // Transformer1
    uint8_t temp2; // Transformer2
    uint8_t temp3; // SelfBoost1
    uint8_t temp4; // SelfBoost2
    uint8_t temp5; // SelfPSFB1
    uint8_t temp6; // SelfPSFB2
    uint8_t temp7; // MosfetBoost1
    uint8_t temp8; // MosfetBoost2
} CNV_TempMeasurementsStr;

/* Regulation info structure */ // Regrouper CNV_RegulationInfoStr et CNV_ControlInfoStr ???
typedef struct
{
    CNV_SoftwareModesE softMode;
    uint32_t setpoint;
    CNV_LimitationTypeValuesE limitationType;
    boolean hasNewValues; // useful ?
} CNV_RegulationInfoStr;

/* Control info structure */
typedef struct
{
    CNV_RegulationModesE regMode;
    CNV_RegulationTypesE regType;
    uint16_t currentLimit;
    boolean hasNewValues; // useful ?
} CNV_ControlInfoStr;

/* Mode info structure */
typedef struct
{
    CNV_RegulationModesE regMode;
    CNV_RegulationTypesE regType;
    uint32_t setpoint;
    uint16_t currentLimit;
    boolean startOrder;
} CNV_InternalRequestStr;

/* PowerCore Unit structure */
typedef struct
{
    uint8_t address;
    CNV_FlagsU flags;
    uint32_t comLostCounter;
    CNV_PowerMeasurementsStr powerMeas;
    CNV_TempMeasurementsStr tempMeas;
    CNV_RegulationInfoStr regulInfo;
    CNV_ControlInfoStr controlInfo;
    CNV_InternalRequestStr request;
} CNV_PowercoreUnitStr;

typedef enum
{
    CNV_BUCKTYPE_NOINBUCK = 0U,
    CNV_BUCKTYPE_CURRENTSOURCE = 1U,
    CNV_BUCKTYPE_VOLTAGEREGULATION = 2U
} CNV_BuckTypeValuesE;

typedef struct
{
    uint32_t setpointReq;
    uint16_t currentLimiteReq;
    boolean reqAccepted;
} CNV_RegulationReq;

/* ---- Global variables ---- */

#ifndef CNV_MODULE
extern CNV_FlagsU CNV_flags;
extern CNV_PowercoreUnitStr CNV_powercoreUnitTable[CNV_POWERCORE_UNITS_NB];
extern CNV_BuckTypeValuesE CNV_buckType;
extern CNV_RegulationReq CNV_regulationReq;
#else
CNV_FlagsU           CNV_flags;
CNV_PowercoreUnitStr CNV_powercoreUnitTable[CNV_POWERCORE_UNITS_NB];
CNV_BuckTypeValuesE CNV_buckType;
CNV_RegulationReq CNV_regulationReq;
#endif

/* ---- Global functions ---- */
/* -- Init -- */
void CNV_Init(void);
void CNV_Deinit(void);
/* -- TX -- */
void CNV_ManageInternalErrorResetRequestFrame(void);
/* -- RX -- */
void CNV_GetInternalCurrentMeasuresFrame(const uint8_t buffer[],
                                         uint8_t powercoreUnitIndex);
void CNV_GetInternalPowerMeasuresFrame(const uint8_t buffer[],
                                       uint8_t powercoreUnitIndex);
void CNV_GetInternalTemperatureMeasuresFrame(const uint8_t buffer[],
                                             uint8_t powercoreUnitIndex);
void CNV_GetInternalVoltageMeasuresFrame(const uint8_t buffer[],
                                         uint8_t powercoreUnitIndex);
void CNV_GetInternalRegulationInfoFrame(const uint8_t buffer[],
                                        uint8_t powercoreUnitIndex);
void CNV_GetInternalControlInfoFrame(const uint8_t buffer[],
                                     uint8_t powercoreUnitIndex);
void CNV_GetInternalErrorsFrame(const uint8_t buffer[],
                                uint8_t powercoreUnitIndex);
void CNV_GetInternalWarningsFrame(const uint8_t buffer[],
                                  uint8_t powercoreUnitIndex);
/* -- Other -- */
uint8_t CNV_getPowercoreUnitsIndex(uint8_t powercoreUnitAddress);
void CNV_updatePowercoreUnitsComlossCounter(uint8_t powercoreUnitIndex);
void CNV_Update(void);
#endif /* FILE_CNV_H */
