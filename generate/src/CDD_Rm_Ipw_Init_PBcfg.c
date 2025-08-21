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

/**
*   @file CDD_Rm_Ipw_PBcfg.c
*
*   @addtogroup RM_MODULE RM Driver
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
#include "Mcal.h"
#include "Mpu_Ip.h"
#include "CDD_Rm_Ipw_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_IPW_PBCFG_INIT_VENDOR_ID_C                     43
#define RM_IPW_PBCFG_INIT_AR_RELEASE_MAJOR_VERSION_C      4
#define RM_IPW_PBCFG_INIT_AR_RELEASE_MINOR_VERSION_C      4
#define RM_IPW_PBCFG_INIT_AR_RELEASE_REVISION_VERSION_C   0
#define RM_IPW_PBCFG_INIT_SW_MAJOR_VERSION_C              1
#define RM_IPW_PBCFG_INIT_SW_MINOR_VERSION_C              0
#define RM_IPW_PBCFG_INIT_SW_PATCH_VERSION_C              1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /*  Check if current file and Mcal.h are of the same version */
    #if ((RM_IPW_PBCFG_INIT_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (RM_IPW_PBCFG_INIT_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AUTOSAR Version Numbers of CDD_Rm_Ipw_INIT_PBcfg.c and Mcal.h are different"
    #endif
#endif

/* Checks against CDD_Rm_Ipw_Cfg.h */
#if (RM_IPW_PBCFG_INIT_VENDOR_ID_C != RM_IPW_CFG_VENDOR_ID)
    #error "CDD_Rm_Ipw_INIT_PBcfg.c and CDD_Rm_Ipw_Cfg.h have different vendor ids"
#endif
#if ((RM_IPW_PBCFG_INIT_AR_RELEASE_MAJOR_VERSION_C    != RM_IPW_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (RM_IPW_PBCFG_INIT_AR_RELEASE_MINOR_VERSION_C    != RM_IPW_CFG_AR_RELEASE_MINOR_VERSION) || \
     (RM_IPW_PBCFG_INIT_AR_RELEASE_REVISION_VERSION_C != RM_IPW_CFG_AR_RELEASE_REVISION_VERSION)  \
    )
    #error "AUTOSAR Version Numbers of CDD_Rm_Ipw_INIT_PBcfg.c and CDD_Rm_Ipw_Cfg.h are different"
#endif
#if ((RM_IPW_PBCFG_INIT_SW_MAJOR_VERSION_C != RM_IPW_CFG_SW_MAJOR_VERSION) || \
     (RM_IPW_PBCFG_INIT_SW_MINOR_VERSION_C != RM_IPW_CFG_SW_MINOR_VERSION) || \
     (RM_IPW_PBCFG_INIT_SW_PATCH_VERSION_C != RM_IPW_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm_Ipw_INIT_PBcfg.c and CDD_Rm_Ipw_Cfg.h are different"
#endif

/* Checks against Mpu_Ip.h */
#if (RM_IPW_PBCFG_INIT_VENDOR_ID_C != RM_MPU_IP_VENDOR_ID)
    #error "CDD_Rm_Ipw_INIT_PBcfg.c and Mpu_Ip.h have different vendor ids"
#endif
#if ((RM_IPW_PBCFG_INIT_AR_RELEASE_MAJOR_VERSION_C    != RM_MPU_IP_AR_RELEASE_MAJOR_VERSION) || \
     (RM_IPW_PBCFG_INIT_AR_RELEASE_MINOR_VERSION_C    != RM_MPU_IP_AR_RELEASE_MINOR_VERSION) || \
     (RM_IPW_PBCFG_INIT_AR_RELEASE_REVISION_VERSION_C != RM_MPU_IP_AR_RELEASE_REVISION_VERSION)  \
    )
    #error "AUTOSAR Version Numbers of CDD_Rm_Ipw_INIT_PBcfg.c and Mpu_Ip.h are different"
#endif
#if ((RM_IPW_PBCFG_INIT_SW_MAJOR_VERSION_C != RM_MPU_IP_SW_MAJOR_VERSION) || \
     (RM_IPW_PBCFG_INIT_SW_MINOR_VERSION_C != RM_MPU_IP_SW_MINOR_VERSION) || \
     (RM_IPW_PBCFG_INIT_SW_PATCH_VERSION_C != RM_MPU_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm_Ipw_INIT_PBcfg.c and Mpu_Ip.h are different"
#endif

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define RM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"

const Rm_Ipw_ConfigType Rm_Ipw_Config_INIT =
{
    &Mpu_Config_INIT
};

#define RM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

