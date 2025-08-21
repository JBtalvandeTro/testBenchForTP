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


#ifndef WDG_IPW_CFG_DEFINES_H
#define WDG_IPW_CFG_DEFINES_H

/**
*   @file
*
*   @addtogroup  Wdg
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Wdog_Ip_Cfg_Defines.h"

/*==================================================================================================
                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define WDG_IPW_CFG_DEFINES_VENDOR_ID                    43
#define WDG_IPW_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define WDG_IPW_CFG_DEFINES_AR_RELEASE_MINOR_VERSION     4
#define WDG_IPW_CFG_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define WDG_IPW_CFG_DEFINES_SW_MAJOR_VERSION             1
#define WDG_IPW_CFG_DEFINES_SW_MINOR_VERSION             0
#define WDG_IPW_CFG_DEFINES_SW_PATCH_VERSION             1

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#if (WDG_IPW_CFG_DEFINES_VENDOR_ID != WDOG_IP_CFG_DEFINES_VENDOR_ID)
#error "Wdg_Ipw_Cfg_Defines.h and Wdog_Ip_Cfg_Defines.h have different vendor ids"
#endif

/* Check if current file and Wdog_Ip_Cfg_Defines header file are of the same Autosar version */
#if ((WDG_IPW_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION   != WDOG_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
    (WDG_IPW_CFG_DEFINES_AR_RELEASE_MINOR_VERSION    != WDOG_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
    (WDG_IPW_CFG_DEFINES_AR_RELEASE_REVISION_VERSION != WDOG_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION)) 
#error "AutoSar Version Numbers of Wdg_Ipw_Cfg_Defines.h and Wdog_Ip_Cfg_Defines.h are different" 
#endif

/* Check if current file and Wdog_Ip_Cfg_Defines header file are of the same software version */
 #if ((WDG_IPW_CFG_DEFINES_SW_MAJOR_VERSION != WDOG_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
    (WDG_IPW_CFG_DEFINES_SW_MINOR_VERSION  != WDOG_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
    (WDG_IPW_CFG_DEFINES_SW_PATCH_VERSION  != WDOG_IP_CFG_DEFINES_SW_PATCH_VERSION))
#error "Software Version Numbers of Wdg_Ipw_Cfg_Defines.h and Wdog_Ip_Cfg_Defines.h are different"
#endif



/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/**
  * @brief  This constant specifies if the instance of the WDG is selected or not
  */
#define WDG_IPW_ENABLE_INSTANCE0      (WDOG_IP_ENABLE)

/**
  * @brief  This constant specifies the hardware used or not.
  */
#define WDOG_IP_USED      (STD_ON)
#define EWM_IP_USED      (STD_OFF)

/**
* @brief  Compile switch to allow/forbid disabling the watchdog driver during runtime
*/
#define WDG_IPW_DEINIT    (WDOG_IP_DEINIT)


/**
* @brief  Defines indicating for which Wdg instances the ISR for is supported
*/
#define  WDG_IPW_ISR0_USED (WDOG_IP_ISR0_USED)
#define  WDG_IPW_ISR1_USED (STD_OFF)

/**
* @brief  Defines indicating for which Wdg instances the Direct Service Mode is supported
*/

#define WDG_IPW_ENABLE_DIRECT_SERVICE_INSTANCE0 (STD_ON)
#define WDG_IPW_ENABLE_DIRECT_SERVICE_INSTANCE1 (STD_OFF)
/**
* @brief This variable will indicate if the Wdg Direct Service feature is activated
*/
#define WDG_IPW_DIRECT_SERVICE (STD_ON)

/**
* @brief  These variables will indicate the Wdg Initial Timeout and Wdg Max Timeout parameters in miliseconds for Wdg module 0
*/
#define WDG_IPW_INSTANCE0_INITIAL_TIMEOUT_U16 ((uint16)0)
#define WDG_IPW_INSTANCE0_MAX_TIMEOUT_U16 ((uint16)12000)
/**
* @brief  This define will indicate if the "Fixed Execution" and "Incremental Execution" for Wdg instances is used
*/

#define WDG_IPW_SUPPORT_IACR  (STD_OFF)

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /*  WDG_IPW_CFG_DEFINES_H */

