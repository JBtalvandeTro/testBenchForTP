/*==================================================================================================
* Project : RTD AUTOSAR 4.4
* Platform : CORTEXM
* Peripheral : Ftm_Srtc_Lptmr_LPit
* Dependencies : none
*
* Autosar Version : 4.4.0
* Autosar Revision : ASR_REL_4_4_REV_0000
* Autosar Conf.Variant :
* SW Version : 1.0.1
* Build Version : S32K1_RTD_1_0_1_D2202_ASR_REL_4_4_REV_0000_20220224
*
* (c) Copyright 2020-2022 NXP Semiconductors
* All Rights Reserved.
*
* NXP Confidential. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/


#ifndef LPTMR_GPT_IP_CFG_H
#define LPTMR_GPT_IP_CFG_H

/**
*   @file       Lptmr_Gpt_Ip_Cfg.h
*
*   @addtogroup LPTMR_GPT_IP Lptmr IPL
*
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
#include "Lptmr_Gpt_Ip_Init_PBcfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LPTMR_GPT_IP_VENDOR_ID_CFG                    43
#define LPTMR_GPT_IP_AR_RELEASE_MAJOR_VERSION_CFG     4
#define LPTMR_GPT_IP_AR_RELEASE_MINOR_VERSION_CFG     4
#define LPTMR_GPT_IP_AR_RELEASE_REVISION_VERSION_CFG  0
#define LPTMR_GPT_IP_SW_MAJOR_VERSION_CFG             1
#define LPTMR_GPT_IP_SW_MINOR_VERSION_CFG             0
#define LPTMR_GPT_IP_SW_PATCH_VERSION_CFG             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (LPTMR_GPT_IP_VENDOR_ID_CFG != LPTMR_GPT_IP_VENDOR_ID_INIT_PBCFG_H)
    #error "Lptmr_Gpt_Ip_Cfg.h and Lptmr_Gpt_Ip_Init_PBcfg.h have different vendor ids"
#endif
/* Check if this header file and header file are of the same Autosar version */
#if ((LPTMR_GPT_IP_AR_RELEASE_MAJOR_VERSION_CFG != LPTMR_GPT_IP_AR_RELEASE_MAJOR_VERSION_INIT_PBCFG_H) || \
     (LPTMR_GPT_IP_AR_RELEASE_MINOR_VERSION_CFG != LPTMR_GPT_IP_AR_RELEASE_MINOR_VERSION_INIT_PBCFG_H) || \
     (LPTMR_GPT_IP_AR_RELEASE_REVISION_VERSION_CFG != LPTMR_GPT_IP_AR_RELEASE_REVISION_VERSION_INIT_PBCFG_H) \
    )
    #error "AutoSar Version Numbers of Lptmr_Gpt_Ip_Cfg.h and Lptmr_Gpt_Ip_Init_PBcfg.h are different"
#endif
/* Check if this header file and header file are of the same Software version */
#if ((LPTMR_GPT_IP_SW_MAJOR_VERSION_CFG != LPTMR_GPT_IP_SW_MAJOR_VERSION_INIT_PBCFG_H) || \
     (LPTMR_GPT_IP_SW_MINOR_VERSION_CFG != LPTMR_GPT_IP_SW_MINOR_VERSION_INIT_PBCFG_H) || \
     (LPTMR_GPT_IP_SW_PATCH_VERSION_CFG != LPTMR_GPT_IP_SW_PATCH_VERSION_INIT_PBCFG_H) \
    )
    #error "Software Version Numbers of Lptmr_Gpt_Ip_Cfg.h and Lptmr_Gpt_Ip_Init_PBcfg.h are different"
#endif

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief Dev error detect switch
*/
#define LPTMR_GPT_IP_DEV_ERROR_DETECT     (STD_OFF)
/*================================================================================================*/
/**
* @brief    LPTMR_GPT_IP_ENABLE_USER_MODE_SUPPORT switch
* @details  Enable/disable support usermode. If this parameter has been configured to TRUE the driver code can be executed from both supervisor and user mode.
*/
#define LPTMR_GPT_IP_ENABLE_USER_MODE_SUPPORT     (STD_OFF)
/*================================================================================================*/
/**
* @brief    LPTMR_GPT_IP_STANDBY_WAKEUP_SUPPORT
* @details  StandBy Mode is not supported in this release
*/
#define LPTMR_GPT_IP_STANDBY_WAKEUP_SUPPORT     (STD_OFF)
/*================================================================================================*/

/*==================================================================================================
*                                             ENUMS
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

#ifdef __cplusplus
}
#endif

/** @} */
#endif  /* LPTMR_GPT_IP_CFG_H */

