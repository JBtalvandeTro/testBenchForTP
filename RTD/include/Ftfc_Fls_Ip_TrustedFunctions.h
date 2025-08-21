/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : FTFC_FLS_IP IPV_QSPI
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

#ifndef FTFC_FLS_IP_TRUSTEDFUNCTIONS_H
#define FTFC_FLS_IP_TRUSTEDFUNCTIONS_H

/**
*   @file Ftfc_Ip_TrustedFunctions.h
*
*   @addtogroup FTFC_IP FTFC IP Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

#include "Ftfc_Fls_Ip_Types.h"
#include "Ftfc_Fls_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FTFC_FLS_IP_TRUSTEDFUNCTIONS_VENDOR_ID_H                       43
#define FTFC_FLS_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION_H        4
#define FTFC_FLS_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION_H        4
#define FTFC_FLS_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION_H     0
#define FTFC_FLS_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION_H                1
#define FTFC_FLS_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION_H                0
#define FTFC_FLS_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION_H                1


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Ftfc_Fls_Ip_Types.header file are of the same vendor */
#if (FTFC_FLS_IP_TYPES_VENDOR_ID != FTFC_FLS_IP_TRUSTEDFUNCTIONS_VENDOR_ID_H)
    #error "Ftfc_Ip_TrustedFunctions.h and Ftfc_Fls_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Ftfc_Fls_Ip_Types.header file are of the same Autosar version */
#if ((FTFC_FLS_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != FTFC_FLS_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION_H) || \
     (FTFC_FLS_IP_TYPES_AR_RELEASE_MINOR_VERSION    != FTFC_FLS_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION_H) || \
     (FTFC_FLS_IP_TYPES_AR_RELEASE_REVISION_VERSION != FTFC_FLS_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Ftfc_Ip_TrustedFunctions.h and Ftfc_Fls_Ip_Types.h are different"
#endif
/* Check if current file and Ftfc_Fls_Ip_Types.header file are of the same Software version */
#if ((FTFC_FLS_IP_TYPES_SW_MAJOR_VERSION != FTFC_FLS_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION_H) || \
     (FTFC_FLS_IP_TYPES_SW_MINOR_VERSION != FTFC_FLS_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION_H) || \
     (FTFC_FLS_IP_TYPES_SW_PATCH_VERSION != FTFC_FLS_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Ftfc_Ip_TrustedFunctions.h and Ftfc_Fls_Ip_Types.h are different"
#endif

/* Check if current file and Ftfc_Fls_Ip_Cfg.header file are of the same vendor */
#if (FTFC_FLS_IP_VENDOR_ID_CFG != FTFC_FLS_IP_TRUSTEDFUNCTIONS_VENDOR_ID_H)
    #error "Ftfc_Ip_TrustedFunctions.h and Ftfc_Fls_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Ftfc_Fls_Ip_Cfg.header file are of the same Autosar version */
#if ((FTFC_FLS_IP_AR_RELEASE_MAJOR_VERSION_CFG    != FTFC_FLS_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION_H) || \
     (FTFC_FLS_IP_AR_RELEASE_MINOR_VERSION_CFG    != FTFC_FLS_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION_H) || \
     (FTFC_FLS_IP_AR_RELEASE_REVISION_VERSION_CFG != FTFC_FLS_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Ftfc_Ip_TrustedFunctions.h and Ftfc_Fls_Ip_Cfg.h are different"
#endif
/* Check if current file and Ftfc_Fls_Ip_Cfg.header file are of the same Software version */
#if ((FTFC_FLS_IP_SW_MAJOR_VERSION_CFG != FTFC_FLS_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION_H) || \
     (FTFC_FLS_IP_SW_MINOR_VERSION_CFG != FTFC_FLS_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION_H) || \
     (FTFC_FLS_IP_SW_PATCH_VERSION_CFG != FTFC_FLS_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Ftfc_Ip_TrustedFunctions.h and Ftfc_Fls_Ip_Cfg.h are different"
#endif


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

#if (FTFC_FLS_IP_INVALID_PREBUF_FROM_RAM == STD_ON)
#define FLS_START_SEC_RAMCODE
#else
#define FLS_START_SEC_CODE
#endif
#include "Fls_MemMap.h"

/**
 * @brief        Invalidate prefetch buffer before reading to make sure that the driver always reads the new data from flash
 *
 * @param[in]    void
 * @retval       none
 *
 */
extern void Ftfc_Fls_Ip_InvalidPrefetchBuff_Ram(void);

#if (FTFC_FLS_IP_INVALID_PREBUF_FROM_RAM == STD_ON)
#define FLS_STOP_SEC_RAMCODE
#else
#define FLS_STOP_SEC_CODE
#endif
#include "Fls_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FTFC_FLS_IP_TRUSTEDFUNCTIONS_H */
