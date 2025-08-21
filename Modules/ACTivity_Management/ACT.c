/*!
 * \file     ACT.c
 * \brief    Brief description of file content
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

/* ---- Includes ---- */
#define ACT_MODULE
#include "ACT.h"

/* ---- Defines ---- */

/* ---- Global variables ---- */

/* ---- External functions ---- */

/* ---- Static variables ---- */

/* ---- Static functions ---- */

/*!     \brief Initialization of Activity Management Module
 *       \param none
 *       \return none
 */
void ACT_Init(void)
{
    /* Clear all flags */
    ACT_readyForLowPower = false;
    ACT_errors.fastPowerDown.all = 0;
    ACT_errors.slowPowerDown.all = 0;
    ACT_errors.warnings.all = 0;
    ACT_errors.origin.all = 0;
    ACT_errors.severity = 0;

    /* Allow all errors and warning flags */
    ACT_errors.fastPowerDownMask.all = UINT32_MAX;
    ACT_errors.slowPowerDownMask.all = UINT32_MAX;
    ACT_errors.warningsMask.all = UINT16_MAX;

}

/*!     \brief Deinitialization of Activity Management Module
 *       \param none
 *       \return none
 */
void ACT_Deinit(void)
{
    /* Clear all flags pointers */

    ACT_readyForLowPower = false;
    ACT_errors.fastPowerDown.all = 0;
    ACT_errors.slowPowerDown.all = 0;
    ACT_errors.warnings.all = 0;
    ACT_errors.origin.all = 0;
    ACT_errors.severity = 0;

    /* Allow all errors and warning flags */
    ACT_errors.fastPowerDownMask.all = UINT32_MAX;
    ACT_errors.slowPowerDownMask.all = UINT32_MAX;

}
