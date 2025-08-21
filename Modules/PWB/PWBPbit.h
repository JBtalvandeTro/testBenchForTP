/*!
 * \file     PWBPbit.h
 * \brief    declares the functions of the PWBPbit sub-module
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/


#ifndef PWB_PWBPBIT_H_
#define PWB_PWBPBIT_H_

/* ---- Includes ---- */
#include "TYPedef.h"

/* ---- Defines ---- */

/* ---- Global variables ---- */

/* ---- Global functions ---- */

void PWBPbit_Init(void);

boolean PWBPbit_testTempConsis(void);
boolean PWBPbit_testHvCouplerRelay(void);
boolean PWBPbit_testLvPrechargeRelay(void);

void PWBPbit_Deinit(void);
#endif /* PWB_PWBPBIT_H_ */
