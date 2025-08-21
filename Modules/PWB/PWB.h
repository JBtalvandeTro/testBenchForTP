/*!
 * \file     PWB.h
 * \brief    declares the functions of the PWB module
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

#ifndef PWB_PWB_H_
#define PWB_PWB_H_

/* ---- Includes ---- */
#include "PWBio.h"
#include "PWBCbit.h"
#include "PWBPbit.h"

/* ---- Defines ---- */
typedef struct
{
    boolean overVolt :1;
    boolean relayCmdWarning :1;
    boolean hvRelayNok :1;
    boolean lvRelayNok :1;
    boolean hvVoltMeas :1;
    boolean lvVoltMeas :1;
    boolean overCurrent :1;
    boolean stopBuckConversion :1;
    boolean stopBoostConversion :1;
    boolean powerSupplyDown :1;
    boolean activityextensionTimerElapsed :1;
    boolean unavailableCometi :1;
    uint16_t reserved :4;
} PWB_FaultsStr;

typedef union
{
    PWB_FaultsStr flags;
    uint16_t all;
} PWB_FaultsU;

typedef struct
{
    boolean pbitDone :1;
    boolean prechargeDone :1;
    boolean prechargeAborted :1;
    uint8_t reserved :5;
} PWB_StatusStr;

typedef union
{
    PWB_StatusStr flags;
    uint8_t all;
} PWB_StatusU;

typedef struct
{
    boolean resultPBit;
    boolean resultCBit;
    PWB_FaultsU faults;
    PWB_StatusU status;
} PWB_FlagsStr;

typedef struct
{
    uint32_t Hv_Voltage;
    uint32_t Hv_Current;
    uint32_t Hv_Temp;
    uint32_t Lv_Voltage;
    uint32_t VHv_Cometi;
    uint32_t VLv_Cometi;
    uint32_t IHv_Cometi;
    uint32_t ILv_Cometi;
} PWB_MeasuresStr;

typedef struct
{
    boolean commandSwitchS1 :1;
    boolean commandSwitchS2 :1;
    boolean commandSwitchS3 :1;
} PWB_RelayCurrentCmdStr;

typedef struct
{
    boolean stateSwitchS2 :1;
    boolean stateSwitchS3 :1;
} PWB_RelayCurrentStateStr;

/* ---- Global variables ---- */
#ifndef PWB_MODULE
extern PWB_FlagsStr PWB_Flags;
extern PWB_MeasuresStr PWB_measures;
extern PWB_RelayCurrentCmdStr PWB_relayCurrentCmd;
extern PWB_RelayCurrentStateStr PWB_relayCurrentState;
extern uint8_t PWB_numberAvailableCOMETi;
#else
PWB_FlagsStr PWB_Flags;
PWB_MeasuresStr PWB_measures;
PWB_RelayCurrentCmdStr PWB_relayCurrentCmd;
PWB_RelayCurrentStateStr PWB_relayCurrentState;
uint8_t PWB_numberAvailableCOMETi;
#endif

/* ---- Global functions ---- */
void PWB_Init(void);
void PWB_Update(void);
void PWB_Deinit(void);

#endif /* PWB_PWB_H_ */
