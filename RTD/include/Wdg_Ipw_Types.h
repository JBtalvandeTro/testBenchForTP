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


#ifndef WDG_IPW_TYPES_H
#define WDG_IPW_TYPES_H

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
==================================================================================================*/
#include "Wdg_Ipw_Cfg_Defines.h"
#if (WDOG_IP_USED == STD_ON)
     #include "Wdog_Ip_Types.h"
#endif /*(WDOG_IP_USED == STD_ON)*/

#if (EWM_IP_USED == STD_ON)
     #include "Ewm_Ip_Types.h"
#endif /*(EWM_IP_USED == STD_ON)*/
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define WDG_IPW_TYPES_VENDOR_ID                    43
#define WDG_IPW_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define WDG_IPW_TYPES_AR_RELEASE_MINOR_VERSION     4
#define WDG_IPW_TYPES_AR_RELEASE_REVISION_VERSION  0
#define WDG_IPW_TYPES_SW_MAJOR_VERSION             1
#define WDG_IPW_TYPES_SW_MINOR_VERSION             0
#define WDG_IPW_TYPES_SW_PATCH_VERSION             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Wdg_Ipw_Cfg_Defines header file are of the same vendor */
#if (WDG_IPW_TYPES_VENDOR_ID != WDG_IPW_CFG_DEFINES_VENDOR_ID)
#error "Wdg_Ipw_Types.h and Wdg_Ipw_Cfg_Defines.h have different vendor ids"
#endif

/* Check if current file and Wdg_Ipw_Cfg_Defines header file are of the same Autosar version */
#if ((WDG_IPW_TYPES_AR_RELEASE_MAJOR_VERSION     != WDG_IPW_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_IPW_TYPES_AR_RELEASE_MINOR_VERSION     != WDG_IPW_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (WDG_IPW_TYPES_AR_RELEASE_REVISION_VERSION  != WDG_IPW_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Wdg_Ipw_Types.h and Wdg_Ipw_Cfg_Defines.h are different"
#endif

/* Check if current file and Wdg_Ipw_Cfg_Defines header file are of the same software version */
#if ((WDG_IPW_TYPES_SW_MAJOR_VERSION != WDG_IPW_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (WDG_IPW_TYPES_SW_MINOR_VERSION != WDG_IPW_CFG_DEFINES_SW_MINOR_VERSION) || \
     (WDG_IPW_TYPES_SW_PATCH_VERSION != WDG_IPW_CFG_DEFINES_SW_PATCH_VERSION))
#error "Software Version Numbers of Wdg_Ipw_Types.h and Wdg_Ipw_Cfg_Defines.h are different"
#endif

#if (WDOG_IP_USED == STD_ON)
     /* Check if current file and Wdog_Ip_Types header file are of the same vendor */
     #if (WDG_IPW_TYPES_VENDOR_ID != WDOG_IP_TYPES_VENDOR_ID)
     #error "Wdg_Ipw_Types.h and Wdog_Ip_Types.h have different vendor ids"
     #endif

     /* Check if current file and Wdog_Ip_Types header file are of the same Autosar version */
     #if ((WDG_IPW_TYPES_AR_RELEASE_MAJOR_VERSION     != WDOG_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
          (WDG_IPW_TYPES_AR_RELEASE_MINOR_VERSION     != WDOG_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
          (WDG_IPW_TYPES_AR_RELEASE_REVISION_VERSION  != WDOG_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AutoSar Version Numbers of Wdg_Ipw_Types.h and Wdog_Ip_Types.h are different"
     #endif

     /* Check if current file and Wdog_Ip_Types header file are of the same software version */
     #if ((WDG_IPW_TYPES_SW_MAJOR_VERSION != WDOG_IP_TYPES_SW_MAJOR_VERSION) || \
          (WDG_IPW_TYPES_SW_MINOR_VERSION != WDOG_IP_TYPES_SW_MINOR_VERSION) || \
          (WDG_IPW_TYPES_SW_PATCH_VERSION != WDOG_IP_TYPES_SW_PATCH_VERSION))
     #error "Software Version Numbers of Wdg_Ipw_Types.h and Wdog_Ip_Types.h are different"
     #endif
#endif /*(WDOG_IP_USED == STD_ON)*/

#if (EWM_IP_USED == STD_ON)
     /* Check if current file and Ewm_Ip_Types header file are of the same vendor */
     #if (WDG_IPW_TYPES_VENDOR_ID != EWM_IP_TYPES_VENDOR_ID)
     #error "Wdg_Ipw_Types.h and Ewm_Ip_Types.h have different vendor ids"
     #endif

     /* Check if current file and Ewm_Ip_Types header file are of the same Autosar version */
     #if ((WDG_IPW_TYPES_AR_RELEASE_MAJOR_VERSION     != EWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
          (WDG_IPW_TYPES_AR_RELEASE_MINOR_VERSION     != EWM_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
          (WDG_IPW_TYPES_AR_RELEASE_REVISION_VERSION  != EWM_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AutoSar Version Numbers of Wdg_Ipw_Types.h and Ewm_Ip_Types.h are different"
     #endif

     /* Check if current file and Ewm_Ip_Types header file are of the same software version */
     #if ((WDG_IPW_TYPES_SW_MAJOR_VERSION != EWM_IP_TYPES_SW_MAJOR_VERSION) || \
          (WDG_IPW_TYPES_SW_MINOR_VERSION != EWM_IP_TYPES_SW_MINOR_VERSION) || \
          (WDG_IPW_TYPES_SW_PATCH_VERSION != EWM_IP_TYPES_SW_PATCH_VERSION))
     #error "Software Version Numbers of Wdg_Ipw_Types.h and Ewm_Ip_Types.h are different"
     #endif
#endif /*(EWM_IP_USED == STD_ON)*/
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*< @brief The service id for the Wdg_Init function, used when using DET */
#define WDG_IPW_INIT_ID       0x00
/*< @brief Te service id for the Wdg_SetMode function, used when using DET */
#define WDG_IPW_SETMODE_ID    0x01

/*< @brief API service did not complete in time */
#define WDG_IPW_E_PARAM_TIMEOUT    0x13

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/**
* @brief          Wdg_Ipw_InstanceType.
* @details        Contains the information related to available Wdg Instances.
*/
typedef enum
{
    WDG_IPW_INSTANCE0 = 0x0U,
    WDG_IPW_INSTANCE1 = 0x1U
} Wdg_Ipw_InstanceType;

/**
* @brief          Wdg_Ipw_IpType.
* @details        Contains the Ip types available for Wdg.
*/
typedef enum
{
    WDG_IPW_WDOG_IP = 0x00,
    WDG_IPW_EWM_IP  = 0x01,
    WDG_IPW_UNINIT_IP = 0x02
} Wdg_Ipw_IpType;

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

typedef struct 
{
    const Wdg_Ipw_IpType eWdgIp;
#if (WDOG_IP_USED == STD_ON)
    const Wdog_Ip_ConfigType *pWdogConfig;
#endif /*(WDOG_IP_USED == STD_ON)*/
#if (EWM_IP_USED == STD_ON)
    const Ewm_Ip_ConfigType *pEwmConfig;
#endif /*(EWM_IP_USED == STD_ON)*/
} Wdg_Ipw_ConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /*WDG_IPW_TYPES_H*/
