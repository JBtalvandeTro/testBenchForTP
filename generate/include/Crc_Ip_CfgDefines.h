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

/* Prevention from multiple including the same header */
#ifndef CRC_IP_CFG_DEFINE_H
#define CRC_IP_CFG_DEFINE_H

/**
*   @file       Crc_Ip_CfgDefines.h
*   @implements Crc_Ip_CfgDefines.h_Artifact
*   @version    1.0.1
*
*   @brief      AUTOSAR Crc Post-Build(PB) configuration file code template.
*   @details    Code template for Post-Build(PB) configuration file generation.
*
*   @defgroup   CRC_CFG CRC Configuration
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
#include "StandardTypes.h"
#include "S32K148_CRC.h"
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CRC_IP_CFG_DEFINES_VENDOR_ID                       43
#define CRC_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION        4
#define CRC_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION        4
#define CRC_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION     0
#define CRC_IP_CFG_DEFINES_SW_MAJOR_VERSION                1
#define CRC_IP_CFG_DEFINES_SW_MINOR_VERSION                0
#define CRC_IP_CFG_DEFINES_SW_PATCH_VERSION                1

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Crc_Ip_CfgDefines.h file and StandardTypes.h header file are of the same Autosar version */
#if ((CRC_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of Crc_Ip_CfgDefines.h file and StandardTypes.h are different"
#endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/


/*! @brief  Enables or disables PRE-COMPILE SUPPORT. */
#define CRC_PRECOMPILE_SUPPORT                  (STD_ON)

/*! @brief  Error detect. */
#define CRC_DET_IS_AVAILABLE                 (STD_ON)
#define CRC_IP_DEV_ERROR_DETECT                 (STD_ON)
/*! @brief  Enables or disables User Mode use Register Protect. */
#define CRC_ENABLE_USER_MODE_SUPPORT         (STD_OFF)

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == CRC_ENABLE_USER_MODE_SUPPORT)
        #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running CRC in user mode, the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
    #endif /* (STD_ON == CRC_ENABLE_USER_MODE_SUPPORT) */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */

/*! @brief  DMA Supported. */
#define CRC_IP_DMA_IS_AVAILABLE                 (STD_OFF)

/*! @brief  Enables or disables Multicore feature. */
#define CRC_MULTICORE_SUPPORT_ENABLED        (STD_OFF)

/*! @brief  Enables or disables get Version Info. */
#define CRC_VERSION_INFO_API_ENABLE          (STD_OFF)

/*! @brief  Number of configured partitions. */
#define CRC_CORE_NOF_PARTITION               (1U)

/*! @brief  Core Default. */
#define CRC_CORE_DEFAULT                     (0U)

/*! @brief  Error detect. */
#define CRC_HW_INSTANCE_0                       ((uint8)0U)

/*! @brief  Hardware channel support. */
#define CRC_HW_CHANNEL_0                        ((uint8)0U)

/*! @brief  Number of channel support. */
#ifndef CRC_IP_CHANNEL_COUNT_U8
#define CRC_IP_CHANNEL_COUNT_U8                 ((uint8)1U)
#endif

/*! @brief  Detect Channel Invalid. */
#define CRC_IP_CHANNEL_INVALID_U32              ((uint32)0xFFFFFFFFU)

/*! @brief  Hardware Features. */
#define CRC_IP_HARDWARE_IS_AVAILABLE                      (STD_ON)
#define CRC_IP_HARDWARE_PROTOCOL_IS_AVAILABLE             (STD_OFF)
#define CRC_IP_HARDWARE_WIDTH_IS_AVAILABLE                (STD_ON)
#define CRC_IP_HARDWARE_POLYNOM_IS_AVAILABLE              (STD_ON)
#define CRC_IP_HARDWARE_INITIAL_SEED_VALUE_IS_AVAILABLE   (STD_ON)
#define CRC_IP_HARDWARE_WRITE_BIT_SWAP_IS_AVAILABLE       (STD_ON)
#define CRC_IP_HARDWARE_WRITE_BYTE_SWAP_IS_AVAILABLE      (STD_ON)
#define CRC_IP_HARDWARE_READ_BIT_SWAP_IS_AVAILABLE        (STD_ON)
#define CRC_IP_HARDWARE_READ_BYTE_SWAP_IS_AVAILABLE       (STD_ON)
#define CRC_IP_HARDWARE_INVERSE_BIT_IS_AVAILABLE          (STD_ON)

/*! @brief  Supported Hardware Protocols. */
#define CRC_IP_8BIT_SAE_J1850_HARDWARE_SUPPORTED          (STD_OFF)
#define CRC_IP_8BIT_H2F_HARDWARE_SUPPORTED                (STD_OFF)
#define CRC_IP_16BIT_CCITT_FALSE_HARDWARE_SUPPORTED       (STD_ON)
#define CRC_IP_16BIT_ARC_HARDWARE_SUPPORTED               (STD_ON)
#define CRC_IP_32BIT_ETHERNET_HARDWARE_SUPPORTED          (STD_ON)
#define CRC_IP_32BIT_E2E_P4_HARDWARE_SUPPORTED            (STD_ON)
#define CRC_IP_64BIT_ECMA_HARDWARE_SUPPORTED              (STD_OFF)

#define CRC_IP_8BIT_CUSTOM_HARDWARE_SUPPORTED             (STD_OFF)
#define CRC_IP_16BIT_CUSTOM_HARDWARE_SUPPORTED            (STD_ON)
#define CRC_IP_32BIT_CUSTOM_HARDWARE_SUPPORTED            (STD_ON)
#define CRC_IP_64BIT_CUSTOM_HARDWARE_SUPPORTED            (STD_OFF)
#define CRC_IP_WRITE_BIT_SWAP_INVERETED                    (STD_OFF)
/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CRC_IP_CFG_DEFINE_H */

