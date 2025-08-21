/*!
 * \file     ACT.h
 * \brief    Brief description of file content
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

#ifndef FILE_ACT_H
#define FILE_ACT_H

/* ---- Includes ---- */
#include "TYPedef.h"
#include "CST.h"
#include "COM.h"
#include "FSM.h"
#include "MPM.h"
#include "WDO.h"
#include "PAR.h"

/* ---- Defines ---- */

#define ACT_ERRORS_TIMEOUT 100U // 0.1s 100ms

typedef enum
{
    ACT_TEMPNOTIF_NOMINAL = 0,
    ACT_TEMPNOTIF_GENTLEWARN = 1,
    ACT_TEMPNOTIF_URGENTWARN = 2,
    ACT_TEMPNOTIF_CRITICALTEMP = 3
}ACT_TempSeverity;

typedef enum
{
    noErrorNorWarning = 0,
    Warning = 1,
    OperatingError = 2,
    CriticalError = 3
} ACT_errorSeverity;

typedef struct
{
    boolean powerCore1 :1;
    boolean powerCore2 :1;
    uint32_t reserved :30;
} ACT_errorOriginStr;

typedef union
{
    ACT_errorOriginStr originFlag;
    uint32_t all;
} ACT_errorOriginU;

typedef struct
{
    boolean controlCanLoss :1;
    boolean limitedCapacity :1;
    unsigned int reserved :30;
} ACT_SlowPowerDownSystemErrorStr;

typedef union
{
    /// The bit field of slow power down system errors
    ACT_SlowPowerDownSystemErrorStr error;
    /// Access the bit field as a whole
    uint32_t all;
} ACT_SlowPowerDownErrorsU;

typedef struct
{
    boolean internalWarning :1;
    boolean tempGentleReminder :1;
    boolean tempUrgentReminder :1;
    boolean maintenanceConditionNotMet :1;
    boolean backupApplicationStarted :1;
    boolean backupParametersLoaded :1;
    boolean unknownPowercoreUnit :1;
    boolean bbauxInMaintenanceMode :1;
    boolean noVoltageOnSourceSide :1;
    boolean relayCommandWarning :1;
    boolean hvVoltageMeas :1;
    boolean lvVoltageMeas :1;
    boolean autonomousBoostEnd :1;
    boolean autonomousBuckEnd :1;
    boolean regulationRequestNOK :1;
    unsigned int reserved :1;
} ACT_WarningStr;

typedef union
{
    /// The bit field of system warnings
    ACT_WarningStr warningsFlags;
    /// Access the bit field as a whole
    uint16_t all;
} ACT_WarningU;

typedef struct
{
    unsigned int reservedForSlowPowerDownErrors :2;
    boolean criticalCapacity :1;
    boolean overTemperature :1;
    boolean parameterError :1;
    boolean addressChanged :1;
    boolean hvCouplerNok :1;
    boolean LvPrechargeNok :1;
    boolean discreteIOsError :1;
    boolean hvVoltageMeas :1;
    boolean lvVoltageMeas :1;
    boolean overCurrent :1;
    boolean overVoltage :1;
    boolean prechargeError :1;
    unsigned int reserved :2;
} ACT_FastPowerDownErrorStr;

typedef union
{
    /// The bit field of fast power down errors
    ACT_FastPowerDownErrorStr error;
    /// Access the bit field as a whole
    uint16_t all;
} ACT_FastPowerDownErrorsU;

typedef struct
{
    boolean illegalModeChangeReq :1;
    boolean fsmUnknownState :1;
    unsigned int reserved :30;
} ACT_OutputSystemErrorStr;

typedef union
{
    /// The bit field of output system errors
    ACT_OutputSystemErrorStr error;
    /// Access the bit field as a whole
    uint32_t all;
} ACT_OutputSystemErrorU;

typedef struct
{
    ACT_SlowPowerDownErrorsU slowPowerDown;
    ACT_FastPowerDownErrorsU fastPowerDown;
    ACT_OutputSystemErrorU outputSystem;
    ACT_WarningU warnings;
    ACT_SlowPowerDownErrorsU slowPowerDownMask;
    ACT_FastPowerDownErrorsU fastPowerDownMask;
    ACT_OutputSystemErrorU outputSystemMask;
    ACT_WarningU warningsMask;
    ACT_errorSeverity severity;
    ACT_errorOriginU origin;
} ACT_SystemErrorsStr;

/* ---- Global variables ---- */
#ifndef ACT_MODULE
/* Structure of pointers to unions of other modules */
extern boolean ACT_readyForLowPower;
extern ACT_SystemErrorsStr ACT_errors;
extern ACT_TempSeverity ACT_tempSeverity;
#else
/* Structure of pointers to unions of other modules */
boolean             ACT_readyForLowPower;
ACT_SystemErrorsStr ACT_errors;
ACT_TempSeverity ACT_tempSeverity;
#endif

/* ---- Global functions ---- */
void ACT_Init(void);
void ACT_Deinit(void);

#endif /* FILE_ACT_H */
