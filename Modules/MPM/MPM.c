/*!
 * \file     MPM.c
 * \brief    Brief description of file content
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

/* ---- Includes ---- */
#define MPM_MODULE

#include "MPM.h"
#include "ACT.h"
#include "Mcal.h"
#include "Mcu.h"
#include "Port.h"
#include "Platform.h"

/* ---- Defines ---- */

/* ---- Global variables ---- */

/* ---- External functions ---- */

/* ---- Static variables ---- */

/* ---- Static functions ---- */

/*LDRA_HEADER_END*/
/*!     \brief Initialization of CPU Config (mode, clocks) and Platform MCAL
 *       \param none
 *       \return none
 */
void MPM_Init(void)
{
    /* Clear all flags */
    MPM_flags.all = 0;
    MPM_lowVoltageFlag = false;

    MPM_flags.moduleFlags.status.flags.moduleInitialized = true;
}

/*!     \brief Periodic task for PLL check and LP mode call
 *       \param none
 *       \return none
 */
void MPM_Management(void)
{
    /* Check if PLL is used and is still locked */
    if (Mcu_GetPllStatus() != MCU_PLL_LOCKED)
    {
        MPM_flags.moduleFlags.faults.flags.mcu_PllUnlocked = 1;
    }
    else
    {
        MPM_flags.moduleFlags.faults.flags.mcu_PllUnlocked = 0;
    }
}

/*!     \brief Deinitialization of CPU Config (mode, clocks)
 *       \param none
 *       \return none
 */
void MPM_Deinit(void)
{
    MPM_flags.moduleFlags.status.flags.moduleInitialized = false;
}

