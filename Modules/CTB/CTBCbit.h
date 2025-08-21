/*!
 * \file     CTBCbit.h
 * \brief    declaring the functions of the CTBCbit sub-module
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

#ifndef CTB_CTBCBIT_H_
#define CTB_CTBCBIT_H_

/* ---- Includes ---- */

#include "TYPedef.h"

/* ---- Defines ---- */

#define CTBCBIT_SETDSO_CMD 1U
#define CTBCBIT_UNSETDSO_CMD 2U
#define CTBCBIT_READDSO_CMD 3U

typedef enum
{
    HEALTH = 7,
    DSO_SPARE_1
} CTB_DSO_PinsE;

/* ---- Global variables ---- */

#ifndef CTBCbit_SubModule
extern boolean ctb_DSO_readResult;
#else
boolean ctb_DSO_readResult;
#endif

/* ---- Global functions ---- */

void CTBCbit_Init(void);
void CTBCbit_SetDSO(uint8_t pinId);
void CTBCbit_UnsetDSO(uint8_t pinId);
void CTBCbit_ReadDSO(uint8_t pinId);
void CTBCbit_Runtests(void);

void CTBCbit_Deinit(void);

#endif /* CTB_CTBCBIT_H_ */
