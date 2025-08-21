/*!
 * \file     PAR_Checks.h
 * \brief    Brief description of file content
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

#ifndef FILE_PARCHECK_H
#define FILE_PARCHECK_H

/* ---- Includes ---- */
#include "TYPedef.h"
#include "CST.h"

/* ---- Defines ---- */

/* ---- Global variables ---- */

/* ---- Global functions ---- */
PAR_ErrorsE PAR_CheckIsValueAllowed(PAR_ParamE param, PAR_ValueU paramValue);
PAR_ErrorsE PAR_IsValidAccess(PAR_ParamE param, PAR_AccessE access);

#endif /* FILE_PAR_CHECKS_H */
