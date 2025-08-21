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

#ifndef GPT_IPW_INIT_PBCFG_H
#define GPT_IPW_INIT_PBCFG_H

/**
*   @file           Gpt_Ipw_PBcfg.h
*
*   @internal
*   @addtogroup     gpt gpt_ipw
*
*   @{
*/
#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Gpt_Ipw.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GPT_IPW_VENDOR_ID_INIT_PBCFG_H                    43
#define GPT_IPW_AR_RELEASE_MAJOR_VERSION_INIT_PBCFG_H     4
#define GPT_IPW_AR_RELEASE_MINOR_VERSION_INIT_PBCFG_H     4
#define GPT_IPW_AR_RELEASE_REVISION_VERSION_INIT_PBCFG_H  0
#define GPT_IPW_SW_MAJOR_VERSION_INIT_PBCFG_H             1
#define GPT_IPW_SW_MINOR_VERSION_INIT_PBCFG_H             0
#define GPT_IPW_SW_PATCH_VERSION_INIT_PBCFG_H             1

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#if (GPT_IPW_VENDOR_ID_INIT_PBCFG_H != GPT_IPW_VENDOR_ID)
    #error "Gpt_Ipw_Init_PBcfg.h and Gpt_Ipw.h have different vendor ids"
#endif
/* Check if this header file and header file are of the same Autosar version */
#if ((GPT_IPW_AR_RELEASE_MAJOR_VERSION_INIT_PBCFG_H != GPT_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_IPW_AR_RELEASE_MINOR_VERSION_INIT_PBCFG_H != GPT_IPW_AR_RELEASE_MINOR_VERSION) || \
     (GPT_IPW_AR_RELEASE_REVISION_VERSION_INIT_PBCFG_H != GPT_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt_Ipw_Init_PBcfg.h and Gpt_Ipw.h are different"
#endif
/* Check if this header file and header file are of the same Software version */
#if ((GPT_IPW_SW_MAJOR_VERSION_INIT_PBCFG_H != GPT_IPW_SW_MAJOR_VERSION) || \
     (GPT_IPW_SW_MINOR_VERSION_INIT_PBCFG_H != GPT_IPW_SW_MINOR_VERSION) || \
     (GPT_IPW_SW_PATCH_VERSION_INIT_PBCFG_H != GPT_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt_Ipw_Init_PBcfg.h and Gpt_Ipw.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
/**
 * @brief   Gpt HwInstanceConfig configuration array
 */
extern Gpt_Ipw_HwInstanceConfigType Gpt_Ipw_HwInstanceConfig_PB_Init[1U];
/**
 * @brief   Gpt channels IP related configuration array
 */
extern Gpt_Ipw_HwChannelConfigType Gpt_Ipw_ChannelConfig_PB_Init[2U];
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
#endif /* GPT_IPW_PBCFG_H*/

