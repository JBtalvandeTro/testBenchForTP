/*!
 * \file     INI.h
 * \brief    Initialization header
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

#ifndef FILE_INI_H
#define FILE_INI_H

/* ---- Includes ---- */
#include "TYPedef.h"
#include "CST.h"

/* ---- Defines ---- */

/* ---- Global variables ---- */

/* ---- Global functions ---- */
void INI_InitDrivers(void);
void INI_InitMiddlewares(void);
void INI_InitLibrairies(void);
void INI_InitModules(void);
void INI_DeinitDrivers(void);
void INI_DeinitMiddlewares(void);
void INI_DeinitLibrairies(void);
void INI_DeinitModules(void);

#endif /* FILE_INI_H */
