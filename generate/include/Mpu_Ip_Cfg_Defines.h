/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : 
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

#ifndef MPU_IP_CFG_DEFINES_H
#define MPU_IP_CFG_DEFINES_H

/**
*   @file Mpu_Ip_CfgDefines.h
*
*   @addtogroup MPU_IP MPU IPV Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "StandardTypes.h"
#include "S32K148_MPU.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_MPU_IP_CFG_DEFINES_VENDOR_ID                    43
#define RM_MPU_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define RM_MPU_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION     4
#define RM_MPU_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define RM_MPU_IP_CFG_DEFINES_SW_MAJOR_VERSION             1
#define RM_MPU_IP_CFG_DEFINES_SW_MINOR_VERSION             0
#define RM_MPU_IP_CFG_DEFINES_SW_PATCH_VERSION             1


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /*  Check if current file and StandardTypes.h header file are of the same Autosar version */
    #if ((RM_MPU_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (RM_MPU_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "Autosar Version Numbers of Mpu_Ip_CfgDefines.h and StandardTypes.h are different"
    #endif
#endif

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/** @brief    Development error checking */
#define MPU_IP_DEV_ERROR_DETECT           (STD_OFF)

#define MPU_IP_EAR_EDR_COUNT_4            (4U)
#define MPU_IP_EAR_EDR_COUNT_5            (5U)

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* MPU_IP_CFG_DEFINES_H */

