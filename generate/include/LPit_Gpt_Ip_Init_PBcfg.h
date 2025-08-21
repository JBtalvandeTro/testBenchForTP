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

#ifndef LPIT_GPT_IP_INIT_PBCFG_H
#define LPIT_GPT_IP_INIT_PBCFG_H

/**
*   @file           LPit_Gpt_Ip_PBcfg.h
*
*   @addtogroup     lpit_ip LPit IPL
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
#include "LPit_Gpt_Ip_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* Inclusion of incompatible header files shall be avoided */
#define LPIT_GPT_IP_VENDOR_ID_INIT_PBCFG_H                        43
#define LPIT_GPT_IP_AR_RELEASE_MAJOR_VERSION_INIT_PBCFG_H         4
#define LPIT_GPT_IP_AR_RELEASE_MINOR_VERSION_INIT_PBCFG_H         4
#define LPIT_GPT_IP_AR_RELEASE_REVISION_VERSION_INIT_PBCFG_H      0
#define LPIT_GPT_IP_SW_MAJOR_VERSION_INIT_PBCFG_H                 1
#define LPIT_GPT_IP_SW_MINOR_VERSION_INIT_PBCFG_H                 0
#define LPIT_GPT_IP_SW_PATCH_VERSION_INIT_PBCFG_H                 1

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#if (LPIT_GPT_IP_VENDOR_ID_INIT_PBCFG_H != LPIT_GPT_IP_TYPES_VENDOR_ID)
    #error "LPit_Gpt_Ip_Init_PBcfg.h and LPit_Gpt_Ip_Types.h have different vendor ids"
#endif
/* Check if this header file and header file are of the same Autosar version */
#if ((LPIT_GPT_IP_AR_RELEASE_MAJOR_VERSION_INIT_PBCFG_H != LPIT_GPT_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (LPIT_GPT_IP_AR_RELEASE_MINOR_VERSION_INIT_PBCFG_H != LPIT_GPT_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (LPIT_GPT_IP_AR_RELEASE_REVISION_VERSION_INIT_PBCFG_H != LPIT_GPT_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of LPit_Gpt_Ip_Init_PBcfg.h and LPit_Gpt_Ip_Types.h are different"
#endif
/* Check if this header file and header file are of the same Software version */
#if ((LPIT_GPT_IP_SW_MAJOR_VERSION_INIT_PBCFG_H != LPIT_GPT_IP_TYPES_SW_MAJOR_VERSION) || \
     (LPIT_GPT_IP_SW_MINOR_VERSION_INIT_PBCFG_H != LPIT_GPT_IP_TYPES_SW_MINOR_VERSION) || \
     (LPIT_GPT_IP_SW_PATCH_VERSION_INIT_PBCFG_H != LPIT_GPT_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of LPit_Gpt_Ip_Init_PBcfg.h and LPit_Gpt_Ip_Types.h are different"
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

#define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"
extern const Lpit_Gpt_Ip_InstanceConfigType LPIT_0_InitConfig_PB_Init;
extern const Lpit_Gpt_Ip_ChannelConfigType LPIT_0_ChannelConfig_PB_Init[2U];
#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"



/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
#endif /* LPIT_GPT_IP_PBCFG_H*/

