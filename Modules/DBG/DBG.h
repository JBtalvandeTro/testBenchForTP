/*!
 * \file     DBG.h
 * \brief    Brief description of file content
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

#ifndef FILE_DBG_H
#define FILE_DBG_H

/* ---- Includes ---- */
#include "TYPedef.h"
#include "CST.h"

/* ---- Defines ---- */
// Types and Defines -----------------------------------------------------------
typedef struct{
       boolean dsioTest :1;
       boolean ledCmd :1;
       boolean relaySwitchTest :1;
       boolean HvMeasure :1;
       boolean LvMeasure :1;
       uint16_t reserved :3;
} DBG_ReqFlagsStr;

typedef struct
{
    boolean processed :1; // this indicate that we are done executing the cmd
} DBG_ProcessingFlagsStr;

typedef union{
        DBG_ReqFlagsStr Reqflags;
        DBG_ProcessingFlagsStr proccesingFlags;
        uint8_t all;
}DBG_FlagsU;
/// Errors of the Debug/Test Manager Library
typedef enum
{
    /// No error **MUST** be 0
    DBG_ERROR_NO_ERROR = 0U,
    /// The count of errors
    DBG_ERROR_COUNT
} DBG_ErrorsE;

/* ---- Global variables ---- */

#ifndef DBG_MODULE
extern DBG_FlagsU DBG_Flags;
#else
DBG_FlagsU DBG_Flags;
#endif

/* ---- Global functions ---- */
void DBG_Init(void);
void DBG_Update(void);
void DBG_Deinit(void);

#endif /* FILE_DBG_H */
