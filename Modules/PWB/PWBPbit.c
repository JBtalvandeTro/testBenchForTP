/*!
 * \file     PWBPbit.c
 * \brief    implements the functions of the PWBPbit sub-module
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

/* ---- Includes ---- */
#include "PWBPbit.h"
#include "PWBio.h"

/* ---- Defines ---- */

/* ---- Global variables ---- */

/* ---- External functions ---- */

/* ---- Static variables ---- */

/* ---- Static functions ---- */

/*!     \brief Initialazing the PWBPbit subModule
 *       \param none
 *       \return none
 */
void PWBPbit_Init(void)
{
    /* Nothing to initialise */
}

/*!     \brief testing the temp consistency
 *       \param none
 *       \return boolean test result
 */
boolean PWBPbit_testTempConsis(void)
{
    return true; // TODO later when the temperature measures are calibrated
}

/*!     \brief testing the Hv Coupler relay
 *       \param none
 *       \return boolean test result
 */
boolean PWBPbit_testHvCouplerRelay(void)
{

    // opening the switch
    PWBio_UnsetCdeSwitch(AuxS3);
    boolean testResult = false;
    boolean currentStateS3 = !PWBio_ReadAuxSwitch(AuxS3);
    if (currentStateS3 == false) // the Relay should be open
    {
        // PWB Pbit is ok
        testResult = true;
    }
    else
    {
        testResult = false;
    }
    return testResult;
}

/*!     \brief testing the Lv precharge relay
 *       \param none
 *       \return boolean test result
 */
boolean PWBPbit_testLvPrechargeRelay(void)
{
    // opening the swtich
    PWBio_UnsetCdeSwitch(AuxS2);
    boolean testResult = false;
    boolean currentStateS2 = !PWBio_ReadAuxSwitch(AuxS2);
    if (currentStateS2 == false) // the Relay should be open
    {
        // PWB Pbit is ok
        testResult = true;
    }
    else
    {
        testResult = false;
    }
    return testResult;
}

/*!     \brief Initialazing the PWBPbit subModule
 *       \param none
 *       \return none
 */
void PWBPbit_Deinit(void)
{
    /* Nothing to initialise */
}
