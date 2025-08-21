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

#ifndef GPT_INIT_PBCFG_H
#define GPT_INIT_PBCFG_H

/**
*   @file           Gpt_PBcfg.h
*
*   @addtogroup     gpt Gpt Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GPT_VENDOR_ID_INIT_PBCFG_H                    43
#define GPT_AR_RELEASE_MAJOR_VERSION_INIT_PBCFG_H     4
#define GPT_AR_RELEASE_MINOR_VERSION_INIT_PBCFG_H     4
#define GPT_AR_RELEASE_REVISION_VERSION_INIT_PBCFG_H  0
#define GPT_SW_MAJOR_VERSION_INIT_PBCFG_H             1
#define GPT_SW_MINOR_VERSION_INIT_PBCFG_H             0
#define GPT_SW_PATCH_VERSION_INIT_PBCFG_H             1
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define GPT_CONFIG_INIT_PB \
      extern const Gpt_ConfigType Gpt_Config_Init;

#ifdef __cplusplus
}
#endif
/** @} */
#endif  /* GPT_Init_PBCFG_H */

