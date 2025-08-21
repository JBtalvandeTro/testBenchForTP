/*!
 * \file     WDO.c
 * \brief    Watchdog middleware
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

/* ---- Includes ---- */
#define WDO_MIDDLEWARE
#include "WDO.h"
#include "Dio.h"
#include "Wdg_43_Instance0.h"

/* ---- Defines ---- */
#define WDO_OFF_MODE 0
#define WDO_ACTIVE_MODE 1

/* ---- Global variables ---- */

/* ---- External functions ---- */

/* ---- Static variables ---- */

/* ---- Static functions ---- */

/*LDRA_HEADER_END*/
/*!     \brief Init WDO middleware
 *       \param Choose if the WDO is external or internal
 *       \return none
 */
void WDO_Init(boolean external)
{
    if (external == true)
    {
        // Turn the external watchdog power down at init
        Dio_WriteChannel(DioConf_DioChannel_EN_WDG, false);
        Dio_WriteChannel(DioConf_DioChannel_OUT_WDG, false);
        WDO_ExternalStateFlag = WDO_ACTIVE_MODE;
    }
    else
    {
        // Turn the internal watchdog power down at init
        Wdg_43_Instance0_Init(&Wdg_Config_0_INIT);
        WDO_WindowCounter = 0U;
        WDO_InternalStateFlag = WDO_ACTIVE_MODE;
    }
}

/*!     \brief Deinit WDO middleware
 *       \param Choose if the WDO is external or internal
 *       \return none
 */
void WDO_Deinit(boolean external)
{
    if (external == true)
    {
        // External WDO
        Dio_WriteChannel(DioConf_DioChannel_EN_WDG, false);
        Dio_WriteChannel(DioConf_DioChannel_OUT_WDG, false);
        WDO_ExternalStateFlag = WDO_OFF_MODE;
    }
    else
    {
        // Internal WDO
        (void) Wdg_43_Instance0_SetMode(WDGIF_OFF_MODE);
        WDO_WindowCounter = 0U;
        WDO_InternalStateFlag = WDO_OFF_MODE;
    }
}

/*!     \brief Manage external WDO power supply to enable / disable the function
 *       \param enable
 *       \return none
 */
void WDO_Management(boolean enable, boolean external)
{
    if (external == true)
    {
        // If external
        Dio_WriteChannel(DioConf_DioChannel_EN_WDG, enable);
    }
    else
    {
        Wdg_43_Instance0_SetMode(WDGIF_SLOW_MODE);
    }
}

/*!     \brief Refresh the WDO
 *       \param none
 *       \return none
 */
void WDO_Refresh(boolean external)
{
    if (external == true)
    {
        // Reset the external WDO
        Dio_WriteChannel(DioConf_DioChannel_OUT_WDG, true);
        Dio_WriteChannel(DioConf_DioChannel_OUT_WDG, false);
    }
    else
    {
        if (WDO_WindowCounter >= 5U)
        {
            // Reset the internal WDO
            Wdg_43_Instance0_Service();
            WDO_WindowCounter = 0U;
        }
        else
        {
            WDO_WindowCounter++;
        }
    }
}
