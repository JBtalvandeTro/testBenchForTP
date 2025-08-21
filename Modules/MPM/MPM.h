/*!
 * \file     MPM.h
 * \brief    Brief description of file content
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

#ifndef FILE_MPM_H
#define FILE_MPM_H

/* ---- Includes ---- */
#include "Mcal.h"

/* ---- Defines ---- */
typedef struct
{
    boolean pbitFault :1;
    boolean mcu_PllUnlocked :1;
    boolean mcu_ClkOutOfRange :1;
    boolean mcu_LvdWarning :1;
    boolean mcu_LvdIrq :1;
    unsigned short reserved :11;
} MPM_FaultFlagsStr;

typedef struct
{
    boolean moduleInitialized :1;
    boolean pbitOk :1;
    unsigned short reserved :14;
} MPM_StatusFlagsStr;

typedef union
{
    MPM_FaultFlagsStr flags;
    uint16_t all;
} MPM_FaultFlagsU;

typedef union
{
    MPM_StatusFlagsStr flags;
    uint16_t all;
} MPM_StatusFlagsU;

typedef struct
{
    MPM_FaultFlagsU faults;
    MPM_StatusFlagsU status;
} MPM_FlagsStr;

typedef union
{
    MPM_FlagsStr moduleFlags;
    uint32_t all;
} MPM_FlagsU;

/* ---- Global variables ---- */
#ifndef MPM_MODULE
extern MPM_FlagsU MPM_flags;
extern boolean MPM_lowVoltageFlag;
#else
MPM_FlagsU MPM_flags;
boolean MPM_lowVoltageFlag;
#endif

/* ---- Global functions ---- */
void MPM_Init(void);
void MPM_Deinit(void);
void MPM_Management(void);

#endif /* FILE_MPM_H */
