/*!
 * \file     CTBCbit.c
 * \brief    declare the functions of the CTBio sub-module
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

#ifndef CTB_CTBIO_H_
#define CTB_CTBIO_H_

/* ---- Includes ---- */

/* ---- Defines ---- */
typedef enum
{
    LedOn = 1,
    LedOff,
    LedPWM
} CTBio_LedState;

/* ---- Global variables ---- */

/* ---- Global functions ---- */
void CTBio_Init(void);

void CTBio_RunTests(void);
void CTBio_CmdLed(uint8_t ledid, uint8_t ledcolor, CTBio_LedState state);
void CTBio_SetLedToBBAuxState(void);

void CTBio_Deinit(void);

#endif /* CTB_CTBIO_H_ */
