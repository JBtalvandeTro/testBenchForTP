/*!
 * \file     WDO.h
 * \brief    Header of WDO middleware
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

#ifndef FILE_WDO_H
#define FILE_WDO_H

/* ---- Includes ---- */
#include "TYPedef.h"
#include "CST.h"

/* ---- Defines ---- */

/* ---- Global variables ---- */
#ifndef WDO_MIDDLEWARE
extern uint8_t      WDO_WindowCounter;
extern boolean      WDO_InternalStateFlag;
extern boolean      WDO_ExternalStateFlag;
#else
uint8_t             WDO_WindowCounter;
boolean             WDO_InternalStateFlag;
boolean             WDO_ExternalStateFlag;
#endif
/* ---- Global functions ---- */
void WDO_Init(boolean external);
void WDO_Deinit(boolean external);
void WDO_Management(boolean enable, boolean external);
void WDO_Refresh(boolean external);

#endif /* FILE_WDO_H */
