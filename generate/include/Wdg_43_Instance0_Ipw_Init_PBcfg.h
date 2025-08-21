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

#ifndef WDG_43_INSTANCE0_IPW_INIT_PBCFG_H
#define WDG_43_INSTANCE0_IPW_INIT_PBCFG_H

/**
*   @file
*
*   @addtogroup Wdg
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
* 4) user callback header files
==================================================================================================*/
#include "Wdg_Ipw_Types.h"
#include "Wdog_Ip_Init_PBcfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define WDG_43_INSTANCE0_IPW_VENDOR_ID_INIT_PBCFG                    43
#define WDG_43_INSTANCE0_IPW_AR_RELEASE_MAJOR_VERSION_INIT_PBCFG     4
#define WDG_43_INSTANCE0_IPW_AR_RELEASE_MINOR_VERSION_INIT_PBCFG     4
#define WDG_43_INSTANCE0_IPW_AR_RELEASE_REVISION_VERSION_INIT_PBCFG  0
#define WDG_43_INSTANCE0_IPW_SW_MAJOR_VERSION_INIT_PBCFG             1
#define WDG_43_INSTANCE0_IPW_SW_MINOR_VERSION_INIT_PBCFG             0
#define WDG_43_INSTANCE0_IPW_SW_PATCH_VERSION_INIT_PBCFG             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Wdg_Ipw_Types header file are of the same vendor */
#if (WDG_43_INSTANCE0_IPW_VENDOR_ID_INIT_PBCFG != WDG_IPW_TYPES_VENDOR_ID)
#error "Wdg_43_Instance0_Ipw_Init_PBcfg.h and Wdg_Ipw_Types.h have different vendor ids"
#endif

/* Check if current file and Wdg_Ipw_Types header file are of the same Autosar version */
#if ((WDG_43_INSTANCE0_IPW_AR_RELEASE_MAJOR_VERSION_INIT_PBCFG     != WDG_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_43_INSTANCE0_IPW_AR_RELEASE_MINOR_VERSION_INIT_PBCFG     != WDG_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (WDG_43_INSTANCE0_IPW_AR_RELEASE_REVISION_VERSION_INIT_PBCFG  != WDG_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Wdg_43_Instance0_Ipw_Init_PBcfg.h and Wdg_Ipw_Types.h are different"
#endif

/* Check if current file and Wdg_Ipw_Types header file are of the same software version */
#if ((WDG_43_INSTANCE0_IPW_SW_MAJOR_VERSION_INIT_PBCFG != WDG_IPW_TYPES_SW_MAJOR_VERSION) || \
     (WDG_43_INSTANCE0_IPW_SW_MINOR_VERSION_INIT_PBCFG != WDG_IPW_TYPES_SW_MINOR_VERSION) || \
     (WDG_43_INSTANCE0_IPW_SW_PATCH_VERSION_INIT_PBCFG != WDG_IPW_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Wdg_43_Instance0_Ipw_Init_PBcfg.h and Wdg_Ipw_Types.h are different"
#endif

/* Check if current file and Wdog_Ip_INIT_PBcfg header file are of the same vendor */
#if (WDG_43_INSTANCE0_IPW_VENDOR_ID_INIT_PBCFG != WDOG_IP_PBCFG_VENDOR_ID)
#error "Wdg_43_Instance0_Ipw_Init_PBcfg.h and Wdog_Ip_INIT_PBcfg.h have different vendor ids"
#endif

/* Check if current file and Wdog_Ip_INIT_PBcfg header file are of the same Autosar version */
#if ((WDG_43_INSTANCE0_IPW_AR_RELEASE_MAJOR_VERSION_INIT_PBCFG     != WDOG_IP_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_43_INSTANCE0_IPW_AR_RELEASE_MINOR_VERSION_INIT_PBCFG     != WDOG_IP_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (WDG_43_INSTANCE0_IPW_AR_RELEASE_REVISION_VERSION_INIT_PBCFG  != WDOG_IP_PBCFG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Wdg_43_Instance0_Ipw_Init_PBcfg.h and Wdog_Ip_INIT_PBcfg.h are different"
#endif

/* Check if current file and Wdog_Ip_INIT_PBcfg header file are of the same software version */
#if ((WDG_43_INSTANCE0_IPW_SW_MAJOR_VERSION_INIT_PBCFG != WDOG_IP_PBCFG_SW_MAJOR_VERSION) || \
     (WDG_43_INSTANCE0_IPW_SW_MINOR_VERSION_INIT_PBCFG != WDOG_IP_PBCFG_SW_MINOR_VERSION) || \
     (WDG_43_INSTANCE0_IPW_SW_PATCH_VERSION_INIT_PBCFG != WDOG_IP_PBCFG_SW_PATCH_VERSION))
#error "Software Version Numbers of Wdg_43_Instance0_Ipw_Init_PBcfg.h and Wdog_Ip_INIT_PBcfg.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                               STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define WDG_START_SEC_CONFIG_DATA_UNSPECIFIED

#include "Wdg_MemMap.h"

extern const Wdg_Ipw_ConfigType Wdg_Ipw_OffModeSettings_0_INIT;
extern const Wdg_Ipw_ConfigType Wdg_Ipw_SlowModeSettings_0_INIT;
extern const Wdg_Ipw_ConfigType Wdg_Ipw_FastModeSettings_0_INIT;

#define WDG_STOP_SEC_CONFIG_DATA_UNSPECIFIED

#include "Wdg_MemMap.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */


#endif /* WDG_43_INSTANCE0_INIT_IP_PBCFG_H */ 



