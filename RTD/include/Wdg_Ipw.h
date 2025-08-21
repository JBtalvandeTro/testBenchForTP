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

#ifndef WDG_IPW_H
#define WDG_IPW_H

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
#include "Wdg_Ipw_Types.h"
#include "StandardTypes.h"
#if (WDOG_IP_USED == STD_ON)
    #include "Wdog_Ip.h"
#endif /*(WDOG_IP_USED == STD_ON)*/
#if (EWM_IP_USED == STD_ON)
    #include "Ewm_Ip.h"
#endif /*(EWM_IP_USED == STD_ON)*/
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define WDG_IPW_VENDOR_ID                    43
#define WDG_IPW_MODULE_ID                    102
#define WDG_IPW_AR_RELEASE_MAJOR_VERSION     4
#define WDG_IPW_AR_RELEASE_MINOR_VERSION     4
#define WDG_IPW_AR_RELEASE_REVISION_VERSION  0
#define WDG_IPW_SW_MAJOR_VERSION             1
#define WDG_IPW_SW_MINOR_VERSION             0
#define WDG_IPW_SW_PATCH_VERSION             1

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Wdg_Ipw_Types header file are of the same vendor */
#if (WDG_IPW_VENDOR_ID != WDG_IPW_TYPES_VENDOR_ID)
#error "Wdg_Ipw.h and Wdg_Ipw_Types.h have different vendor ids"
#endif

/* Check if current file and Wdg_Ipw_Types header file are of the same Autosar version */
#if ((WDG_IPW_AR_RELEASE_MAJOR_VERSION     != WDG_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_IPW_AR_RELEASE_MINOR_VERSION     != WDG_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (WDG_IPW_AR_RELEASE_REVISION_VERSION  != WDG_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Wdg_Ipw.h and Wdg_Ipw_Types.h are different"
#endif

/* Check if current file and Wdg_Ipw_Types header file are of the same software version */
#if ((WDG_IPW_SW_MAJOR_VERSION != WDG_IPW_TYPES_SW_MAJOR_VERSION) || \
     (WDG_IPW_SW_MINOR_VERSION != WDG_IPW_TYPES_SW_MINOR_VERSION) || \
     (WDG_IPW_SW_PATCH_VERSION != WDG_IPW_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Wdg_Ipw.h and Wdg_Ipw_Types.h are different"
#endif

#if (WDOG_IP_USED == STD_ON)
    /* Check if current file and Wdog_Ip header file are of the same vendor */
    #if (WDG_IPW_VENDOR_ID != WDOG_IP_VENDOR_ID)
    #error "Wdg_Ipw.h and Wdog_Ip.h have different vendor ids"
    #endif

    /* Check if current file and Wdog_Ip header file are of the same Autosar version */
    #if ((WDG_IPW_AR_RELEASE_MAJOR_VERSION     != WDOG_IP_AR_RELEASE_MAJOR_VERSION) || \
         (WDG_IPW_AR_RELEASE_MINOR_VERSION     != WDOG_IP_AR_RELEASE_MINOR_VERSION) || \
         (WDG_IPW_AR_RELEASE_REVISION_VERSION  != WDOG_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Wdg_Ipw.h and Wdog_Ip.h are different"
    #endif

    /* Check if current file and Wdog_Ip header file are of the same software version */
    #if ((WDG_IPW_SW_MAJOR_VERSION != WDOG_IP_SW_MAJOR_VERSION) || \
         (WDG_IPW_SW_MINOR_VERSION != WDOG_IP_SW_MINOR_VERSION) || \
         (WDG_IPW_SW_PATCH_VERSION != WDOG_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Wdg_Ipw.h and Wdog_Ip.h are different"
    #endif
#endif /*(WDOG_IP_USED == STD_ON)*/

#if (EWM_IP_USED == STD_ON)
    /* Check if current file and Ewm_Ip header file are of the same vendor */
    #if (WDG_IPW_VENDOR_ID != EWM_IP_VENDOR_ID)
    #error "Wdg_Ipw.h and Ewm_Ip.h have different vendor ids"
    #endif

    /* Check if current file and Ewm_Ip header file are of the same Autosar version */
    #if ((WDG_IPW_AR_RELEASE_MAJOR_VERSION     != EWM_IP_AR_RELEASE_MAJOR_VERSION) || \
         (WDG_IPW_AR_RELEASE_MINOR_VERSION     != EWM_IP_AR_RELEASE_MINOR_VERSION) || \
         (WDG_IPW_AR_RELEASE_REVISION_VERSION  != EWM_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Wdg_Ipw.h and Ewm_Ip.h are different"
    #endif

    /* Check if current file and Ewm_Ip header file are of the same software version */
    #if ((WDG_IPW_SW_MAJOR_VERSION != EWM_IP_SW_MAJOR_VERSION) || \
         (WDG_IPW_SW_MINOR_VERSION != EWM_IP_SW_MINOR_VERSION) || \
         (WDG_IPW_SW_PATCH_VERSION != EWM_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Wdg_Ipw.h and Ewm_Ip.h are different"
    #endif
#endif /*(EWM_IP_USED == STD_ON)*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StandardTypes header file are of the same Autosar version */
    #if ((WDG_IPW_AR_RELEASE_MAJOR_VERSION    != STD_AR_RELEASE_MAJOR_VERSION) || \
        (WDG_IPW_AR_RELEASE_MINOR_VERSION     != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Wdg_Ipw.h and StandardTypes.h are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef WDG_ROM
    #if (WDG_ROM == 1U)
        #define WDG_START_SEC_CODE
    #endif
#else
    #if (WDG_RAM == 0U)
        #define WDG_START_SEC_RAMCODE
    #endif
#endif

#include "Wdg_MemMap.h"

Std_ReturnType Wdg_Ipw_Init(Wdg_Ipw_InstanceType Instance, const Wdg_Ipw_ConfigType * const IpwConfig);

Std_ReturnType Wdg_Ipw_SetMode(Wdg_Ipw_InstanceType Instance, const Wdg_Ipw_ConfigType * const IpwConfig);

Std_ReturnType Wdg_Ipw_StartTimer(Wdg_Ipw_InstanceType Instance);

#if (WDG_IPW_DEINIT == STD_ON)
    Std_ReturnType Wdg_Ipw_StopTimer(Wdg_Ipw_InstanceType Instance);
#endif

void Wdg_Ipw_Service(Wdg_Ipw_InstanceType Instance);

#ifdef WDG_ROM
    #if (WDG_ROM == 1U)
        #define WDG_STOP_SEC_CODE
    #endif
#else
    #if (WDG_RAM == 0U)
        #define WDG_STOP_SEC_RAMCODE
    #endif
#endif

#include "Wdg_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /*WDG_IPW_H*/
