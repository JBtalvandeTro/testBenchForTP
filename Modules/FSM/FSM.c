/*!
 * \file     FSM.c
 * \brief    Finite state machine module
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

/* ---- Includes ---- */
#define FSM_MODULE
#include "FSM.h"

/* ---- Defines ---- */

/* ---- Global variables ---- */

/* ---- External functions ---- */

/* ---- Static variables ---- */

/* ---- Static functions ---- */

/*!     \brief Initialization of FSM Module
 *       \param none
 *       \return none
 */
void FSM_Init(void)
{
    FSM_mode = FSM_MODE_INIT;

    FSM_errors.EnterMaintModeNotMet = false;
    FSM_errors.bbAuxInMaintMode = false;
    FSM_errors.autonomousBoostEnd = false;
    FSM_errors.autonomousBuckEnd = false;
    FSM_errors.failedPbit = false;
}

/*!     \brief Deinitialization of FSM Module
 *       \param none
 *       \return none
 */
void FSM_Deinit(void)
{
}
