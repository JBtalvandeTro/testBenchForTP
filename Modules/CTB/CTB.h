/*!
 * \file     CTB.h
 * \brief    declares the functions of the CTB module
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

#ifndef CTB_CTB_H_
#define CTB_CTB_H_

/* ---- Includes ---- */
#include "CTBCbit.h"
#include "CTBPbit.h"

/* ---- Defines ---- */

typedef struct
{
    boolean addressChanged :1;
    boolean discretIOError :1;
    uint8_t reserved :6;
} CTB_FaultsStr;

typedef union
{
    CTB_FaultsStr flags;
    uint8_t all;
} CTB_FaultsU;

typedef struct
{
    boolean pbitDone :1;
    boolean stopConversion :1;
    uint8_t reserved :6;
} CTB_StatusStr;

typedef union
{
    CTB_StatusStr flags;
    uint8_t all;
} CTB_StatusU;

typedef union
{
    CTB_DSI_TestResultStr dsiTestResults;
    uint8_t all;
} CTB_DSIResultU;

typedef struct
{
    CTB_DSIResultU dsiResults;
    boolean resultPBit;
    boolean resultCBit;
    CTB_FaultsU faults;
    CTB_StatusU status;
} CTB_FlagsStr;

typedef struct
{
    boolean Maint_DSI_State :1;
    boolean EMERSTOP_DSI_State :1;
    uint8_t bbAux_Address;
} CTB_DsiStateStr;

typedef struct
{
    boolean Health_State :1;
    boolean DSO_Spare_State :1;
} CTB_DsoStateStr;

/* ---- Global variables ---- */

#ifndef CTB_MODULE
extern CTB_FlagsStr CTB_Flags;
extern CTB_DsiStateStr CTB_dsiState;
extern CTB_DsoStateStr CTB_dsoState;
#else
CTB_FlagsStr CTB_Flags;
CTB_DsiStateStr CTB_dsiState;
CTB_DsoStateStr CTB_dsoState;
#endif

/* ---- Global functions ---- */
void CTB_Init(void);
void CTB_Update(void);
void CTB_Deinit(void);

#endif /* CTB_CTB_H_ */
