/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : Ftm Flexio
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

#ifndef FTM_PWM_IP_Init_PBCFG_H
#define FTM_PWM_IP_Init_PBCFG_H

/**
*   @file       Ftm_Pwm_Ip_PBcfg.h
*
*   @addtogroup ftm_pwm_ip Ftm Pwm IPL
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

#include "Ftm_Pwm_Ip_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FTM_PWM_IP_Init_PB_CFG_VENDOR_ID                       43
#define FTM_PWM_IP_Init_PB_CFG_AR_RELEASE_MAJOR_VERSION        4
#define FTM_PWM_IP_Init_PB_CFG_AR_RELEASE_MINOR_VERSION        4
#define FTM_PWM_IP_Init_PB_CFG_AR_RELEASE_REVISION_VERSION     0
#define FTM_PWM_IP_Init_PB_CFG_SW_MAJOR_VERSION                1
#define FTM_PWM_IP_Init_PB_CFG_SW_MINOR_VERSION                0
#define FTM_PWM_IP_Init_PB_CFG_SW_PATCH_VERSION                1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if header file and Ftm_Pwm_Ip_Types.h header file are of the same vendor */
#if (FTM_PWM_IP_Init_PB_CFG_VENDOR_ID != FTM_PWM_IP_TYPES_VENDOR_ID)
    #error "Vendor IDs of Ftm_Pwm_Ip_Init_PBcfg.h and Ftm_Pwm_Ip_Types.h are different."
#endif

/* Check if header file and Ftm_Pwm_Ip_Types.h header file are of the same AUTOSAR version */
#if ((FTM_PWM_IP_Init_PB_CFG_AR_RELEASE_MAJOR_VERSION    != FTM_PWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FTM_PWM_IP_Init_PB_CFG_AR_RELEASE_MINOR_VERSION    != FTM_PWM_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FTM_PWM_IP_Init_PB_CFG_AR_RELEASE_REVISION_VERSION != FTM_PWM_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Ftm_Pwm_Ip_Init_PBcfg.h and Ftm_Pwm_Ip_Types.h are different."
#endif

/* Check if header file and Ftm_Pwm_Ip_Types.h header file are of the same software version */
#if ((FTM_PWM_IP_Init_PB_CFG_SW_MAJOR_VERSION != FTM_PWM_IP_TYPES_SW_MAJOR_VERSION) || \
     (FTM_PWM_IP_Init_PB_CFG_SW_MINOR_VERSION != FTM_PWM_IP_TYPES_SW_MINOR_VERSION) || \
     (FTM_PWM_IP_Init_PB_CFG_SW_PATCH_VERSION != FTM_PWM_IP_TYPES_SW_PATCH_VERSION))
    #error "Software version numbers of Ftm_Pwm_Ip_Init_PBcfg.h and Ftm_Pwm_Ip_Types.h are different."
#endif


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/* Ftm instance index for configuration PwmFtmCh_1 */
#define FTM_PWM_IP_Init_I0_CH1_CFG      (0U)
/* Ftm instance index for configuration PwmFtmCh_0 */
#define FTM_PWM_IP_Init_I4_CH1_CFG      (4U)
/* Ftm instance index for configuration PwmFtmCh_1 */
#define FTM_PWM_IP_Init_I4_CH3_CFG      (4U)
/* Ftm instance index for configuration PwmFtmCh_2 */
#define FTM_PWM_IP_Init_I4_CH4_CFG      (4U)
/* Ftm instance index for configuration PwmFtmCh_3 */
#define FTM_PWM_IP_Init_I4_CH7_CFG      (4U)
/* Ftm instance index for configuration PwmFtmCh_4 */
#define FTM_PWM_IP_Init_I4_CH0_CFG      (4U)
/* Ftm instance index for configuration PwmFtmCh_0 */
#define FTM_PWM_IP_Init_I5_CH2_CFG      (5U)
/* Ftm instance index for configuration PwmFtmCh_1 */
#define FTM_PWM_IP_Init_I5_CH4_CFG      (5U)
/* Ftm instance index for configuration PwmFtmCh_2 */
#define FTM_PWM_IP_Init_I5_CH7_CFG      (5U)
/* Ftm instance index for configuration PwmFtmCh_0 */
#define FTM_PWM_IP_Init_I6_CH0_CFG      (6U)
/* Ftm instance index for configuration PwmFtmCh_1 */
#define FTM_PWM_IP_Init_I6_CH1_CFG      (6U)
/* Ftm instance index for configuration PwmFtmCh_2 */
#define FTM_PWM_IP_Init_I6_CH2_CFG      (6U)
/* Ftm instance index for configuration PwmFtmCh_0 */
#define FTM_PWM_IP_Init_I1_CH7_CFG      (1U)

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
#ifndef FTM_PWM_IP_PRECOMPILE_SUPPORT
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

/*================================================================================================*/
/* Ftm instance 0 User configuration structure */
extern const Ftm_Pwm_Ip_UserCfgType Ftm_Pwm_Ip_Init_UserCfg0;

/* Ftm instance 0 configuration structure */
extern const Ftm_Pwm_Ip_InstanceCfgType Ftm_Pwm_Ip_Init_InstCfg0;

/* Ftm instance 0 synchronization configuration structure */
extern const Ftm_Pwm_Ip_SyncCfgType Ftm_Pwm_Ip_Init_SyncCfg0;

/* Channel configurations for Ftm instance 0 */
/* Ftm channel 1 configuration */
extern const Ftm_Pwm_Ip_ChannelConfigType Ftm_Pwm_Ip_Init_I0_Ch1;

/*================================================================================================*/
/* Ftm instance 4 User configuration structure */
extern const Ftm_Pwm_Ip_UserCfgType Ftm_Pwm_Ip_Init_UserCfg4;

/* Ftm instance 4 configuration structure */
extern const Ftm_Pwm_Ip_InstanceCfgType Ftm_Pwm_Ip_Init_InstCfg4;

/* Ftm instance 4 synchronization configuration structure */
extern const Ftm_Pwm_Ip_SyncCfgType Ftm_Pwm_Ip_Init_SyncCfg4;

/* Channel configurations for Ftm instance 4 */
/* Ftm channel 1 configuration */
extern const Ftm_Pwm_Ip_ChannelConfigType Ftm_Pwm_Ip_Init_I4_Ch1;

/* Ftm channel 3 configuration */
extern const Ftm_Pwm_Ip_ChannelConfigType Ftm_Pwm_Ip_Init_I4_Ch3;

/* Ftm channel 4 configuration */
extern const Ftm_Pwm_Ip_ChannelConfigType Ftm_Pwm_Ip_Init_I4_Ch4;

/* Ftm channel 7 configuration */
extern const Ftm_Pwm_Ip_ChannelConfigType Ftm_Pwm_Ip_Init_I4_Ch7;

/* Ftm channel 0 configuration */
extern const Ftm_Pwm_Ip_ChannelConfigType Ftm_Pwm_Ip_Init_I4_Ch0;

/*================================================================================================*/
/* Ftm instance 5 User configuration structure */
extern const Ftm_Pwm_Ip_UserCfgType Ftm_Pwm_Ip_Init_UserCfg5;

/* Ftm instance 5 configuration structure */
extern const Ftm_Pwm_Ip_InstanceCfgType Ftm_Pwm_Ip_Init_InstCfg5;

/* Ftm instance 5 synchronization configuration structure */
extern const Ftm_Pwm_Ip_SyncCfgType Ftm_Pwm_Ip_Init_SyncCfg5;

/* Channel configurations for Ftm instance 5 */
/* Ftm channel 2 configuration */
extern const Ftm_Pwm_Ip_ChannelConfigType Ftm_Pwm_Ip_Init_I5_Ch2;

/* Ftm channel 4 configuration */
extern const Ftm_Pwm_Ip_ChannelConfigType Ftm_Pwm_Ip_Init_I5_Ch4;

/* Ftm channel 7 configuration */
extern const Ftm_Pwm_Ip_ChannelConfigType Ftm_Pwm_Ip_Init_I5_Ch7;

/*================================================================================================*/
/* Ftm instance 6 User configuration structure */
extern const Ftm_Pwm_Ip_UserCfgType Ftm_Pwm_Ip_Init_UserCfg6;

/* Ftm instance 6 configuration structure */
extern const Ftm_Pwm_Ip_InstanceCfgType Ftm_Pwm_Ip_Init_InstCfg6;

/* Ftm instance 6 synchronization configuration structure */
extern const Ftm_Pwm_Ip_SyncCfgType Ftm_Pwm_Ip_Init_SyncCfg6;

/* Channel configurations for Ftm instance 6 */
/* Ftm channel 0 configuration */
extern const Ftm_Pwm_Ip_ChannelConfigType Ftm_Pwm_Ip_Init_I6_Ch0;

/* Ftm channel 1 configuration */
extern const Ftm_Pwm_Ip_ChannelConfigType Ftm_Pwm_Ip_Init_I6_Ch1;

/* Ftm channel 2 configuration */
extern const Ftm_Pwm_Ip_ChannelConfigType Ftm_Pwm_Ip_Init_I6_Ch2;

/*================================================================================================*/
/* Ftm instance 1 User configuration structure */
extern const Ftm_Pwm_Ip_UserCfgType Ftm_Pwm_Ip_Init_UserCfg1;

/* Ftm instance 1 configuration structure */
extern const Ftm_Pwm_Ip_InstanceCfgType Ftm_Pwm_Ip_Init_InstCfg1;

/* Ftm instance 1 synchronization configuration structure */
extern const Ftm_Pwm_Ip_SyncCfgType Ftm_Pwm_Ip_Init_SyncCfg1;

/* Channel configurations for Ftm instance 1 */
/* Ftm channel 7 configuration */
extern const Ftm_Pwm_Ip_ChannelConfigType Ftm_Pwm_Ip_Init_I1_Ch7;


#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"
#endif  /* FTM_PWM_IP_PRECOMPILE_SUPPORT */


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FTM_PWM_IP_Init_PBCFG_H */

