/*!
 * \file     FSM.h
 * \brief    Brief description of file content
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

#ifndef FILE_FSM_H
#define FILE_FSM_H

/* ---- Includes ---- */
#include "TYPedef.h"
#include "CST.h"

/* ---- Defines ---- */
typedef enum
{
    FSM_MODE_INIT = 0,
    FSM_MODE_PBIT = 1,
    FSM_MODE_STANDBY = 2,
    FSM_MODE_BOOST = 3,
    FSM_MODE_BUCK = 4,
    FSM_MODE_SHUTDOWN = 5,
    FSM_MODE_EMERGENCY = 6,
    FSM_MODE_MAINTENANCE = 7,
    FSM_MODE_S3MODE = 8
} FSM_ModesE;

typedef struct
{
    boolean EnterMaintModeNotMet :1;
    boolean bbAuxInMaintMode :1;
    boolean autonomousBuckEnd :1;
    boolean autonomousBoostEnd :1;
    boolean failedPbit :1;
} FSM_ErrorsStr;

/* ---- Global variables ---- */
#ifndef FSM_MODULE
extern FSM_ModesE FSM_mode;
extern FSM_ErrorsStr FSM_errors;
#else
FSM_ModesE  FSM_mode;
FSM_ErrorsStr FSM_errors;
#endif

/* ---- Global functions ---- */
void FSM_Init(void);
void FSM_Deinit(void);

#endif /* FILE_FSM_H */
