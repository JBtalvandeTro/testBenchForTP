/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : Wdog,Ewm
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : S32K1_RTD_1_0_1_D2202_ASR_REL_4_4_REV_0000_20220224
*
*   (c) Copyright 2020-2022 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/


/**
* @file
*
* @addtogroup  Wdg
* @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Wdg_Cfg.h"
#include "Wdg_CfgExt.h"
#ifdef WDG_INSTANCE0
#if (WDG_INSTANCE0 == STD_ON)



/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define WDG_VENDOR_ID_INIT_PBCFG_C                         43
#define WDG_AR_RELEASE_MAJOR_VERSION_INIT_PBCFG_C          4
#define WDG_AR_RELEASE_MINOR_VERSION_INIT_PBCFG_C          4
#define WDG_AR_RELEASE_REVISION_VERSION_INIT_PBCFG_C       0
#define WDG_SW_MAJOR_VERSION_INIT_PBCFG_C                  1
#define WDG_SW_MINOR_VERSION_INIT_PBCFG_C                  0
#define WDG_SW_PATCH_VERSION_INIT_PBCFG_C                  1

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and WDG configuration header file are of the same vendor */
#if (WDG_VENDOR_ID_INIT_PBCFG_C != WDG_VENDOR_ID_CFG)
#error "Wdg_43_Instance0_INIT_PBcfg.c and Wdg_Cfg.h have different vendor ids"
#endif

/* Check if current file and Wdg_Cfg header file are of the same Autosar version */
#if ((WDG_AR_RELEASE_MAJOR_VERSION_INIT_PBCFG_C     != WDG_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (WDG_AR_RELEASE_MINOR_VERSION_INIT_PBCFG_C     != WDG_AR_RELEASE_MINOR_VERSION_CFG) || \
     (WDG_AR_RELEASE_REVISION_VERSION_INIT_PBCFG_C  != WDG_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Wdg_43_Instance0_INIT_PBcfg.c and Wdg_Cfg.h are different"
#endif

/* Check if current file and Wdg_Cfg header file are of the same software version */
#if ((WDG_SW_MAJOR_VERSION_INIT_PBCFG_C != WDG_SW_MAJOR_VERSION_CFG) || \
     (WDG_SW_MINOR_VERSION_INIT_PBCFG_C != WDG_SW_MINOR_VERSION_CFG) || \
     (WDG_SW_PATCH_VERSION_INIT_PBCFG_C != WDG_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Wdg_43_Instance0_INIT_PBcfg.c and Wdg_Cfg.h are different"
#endif

/* Check if current file and Wdg_CfgExt header file are of the same vendor */
#if (WDG_VENDOR_ID_INIT_PBCFG_C != WDG_VENDOR_ID_CFG_EXT)
#error "Wdg_43_Instance0_INIT_PBcfg.c and Wdg_CfgExt.h have different vendor ids"
#endif

#if ((WDG_AR_RELEASE_MAJOR_VERSION_INIT_PBCFG_C     != WDG_AR_RELEASE_MAJOR_VERSION_CFG_EXT) || \
     (WDG_AR_RELEASE_MINOR_VERSION_INIT_PBCFG_C     != WDG_AR_RELEASE_MINOR_VERSION_CFG_EXT) || \
     (WDG_AR_RELEASE_REVISION_VERSION_INIT_PBCFG_C  != WDG_AR_RELEASE_REVISION_VERSION_CFG_EXT))
#error "AutoSar Version Numbers of Wdg_43_Instance0_INIT_PBcfg.c and Wdg_CfgExt.h are different"
#endif

#if ((WDG_SW_MAJOR_VERSION_INIT_PBCFG_C != WDG_SW_MAJOR_VERSION_CFG_EXT) || \
     (WDG_SW_MINOR_VERSION_INIT_PBCFG_C != WDG_SW_MINOR_VERSION_CFG_EXT) || \
     (WDG_SW_PATCH_VERSION_INIT_PBCFG_C != WDG_SW_PATCH_VERSION_CFG_EXT))
#error "Software Version Numbers of Wdg_43_Instance0_INIT_PBcfg.c and Wdg_CfgExt.h are different"
#endif


/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/
#define WDG_START_SEC_CONFIG_DATA_UNSPECIFIED

#include "Wdg_MemMap.h"

static const Wdg_ModeType Wdg_OffModeSettings_0_INIT=
{
    (uint32) 0,
    &Wdg_Ipw_OffModeSettings_0_INIT
};
static const Wdg_ModeType Wdg_SlowModeSettings_0_INIT=
{
    (uint32) 0,
    &Wdg_Ipw_SlowModeSettings_0_INIT
};
static const Wdg_ModeType Wdg_FastModeSettings_0_INIT=
{
    (uint32) 0,
    &Wdg_Ipw_FastModeSettings_0_INIT
};

#define WDG_STOP_SEC_CONFIG_DATA_UNSPECIFIED

#include "Wdg_MemMap.h"

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                     GLOBAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/
#define WDG_START_SEC_CONFIG_DATA_UNSPECIFIED

#include "Wdg_MemMap.h"

const Wdg_ConfigType Wdg_Config_0_INIT = 
{
    WDGIF_SLOW_MODE,
    WDG_IPW_INSTANCE0,
#if (WDG_DIRECT_SERVICE == STD_OFF)
    NULL_PTR,
    NULL_PTR,
#endif
    {&Wdg_OffModeSettings_0_INIT, &Wdg_SlowModeSettings_0_INIT, &Wdg_FastModeSettings_0_INIT}
};

#define WDG_STOP_SEC_CONFIG_DATA_UNSPECIFIED

#include "Wdg_MemMap.h"
/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
    *                                      LOCAL FUNCTIONS
==================================================================================================*/

#endif /* #if (WDG_INSTANCE0 == STD_ON) */
#ifdef __cplusplus
}
#endif
#endif

/** @} */

