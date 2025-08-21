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
*   @file       Crc_Ip_Cfg.c
*   @implements Crc_Ip_Cfg.c_Artifact
*   @version    1.0.1
*
*   @brief      AUTOSAR Crc Post-Build(PB) configuration file code template.
*   @details    Code template for Post-Build(PB) configuration file generation.
*
*   @addtogroup CRC_CFG
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
#include "Crc_Ip_Cfg.h"

/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
#define CRC_IP_CFG_VENDOR_ID_C                      43
#define CRC_IP_CFG_AR_RELEASE_MAJOR_VERSION_C       4
#define CRC_IP_CFG_AR_RELEASE_MINOR_VERSION_C       4
#define CRC_IP_CFG_AR_RELEASE_REVISION_VERSION_C    0
#define CRC_IP_CFG_SW_MAJOR_VERSION_C               1
#define CRC_IP_CFG_SW_MINOR_VERSION_C               0
#define CRC_IP_CFG_SW_PATCH_VERSION_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Crc header file are of the same vendor */
#if (CRC_IP_CFG_VENDOR_ID_C != CRC_IP_CFG_VENDOR_ID)
    #error "CRC_Ip_Cfg.c and CRC_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Crc header file are of the same Autosar version */
#if ((CRC_IP_CFG_AR_RELEASE_MAJOR_VERSION_C    != CRC_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_IP_CFG_AR_RELEASE_MINOR_VERSION_C    != CRC_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CRC_IP_CFG_AR_RELEASE_REVISION_VERSION_C != CRC_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CRC_Ip_Cfg.c and CRC_Ip_Cfg.h are different"
#endif
/* Check if current file and Crc header file are of the same Software version */
#if ((CRC_IP_CFG_SW_MAJOR_VERSION_C != CRC_IP_CFG_SW_MAJOR_VERSION) || \
     (CRC_IP_CFG_SW_MINOR_VERSION_C != CRC_IP_CFG_SW_MINOR_VERSION) || \
     (CRC_IP_CFG_SW_PATCH_VERSION_C != CRC_IP_CFG_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of CRC_Ip_Cfg.c and CRC_Ip_Cfg.h are different"
#endif


/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

#define CRC_START_SEC_VAR_INIT_UNSPECIFIED
#include "Crc_MemMap.h"
/**
* @brief  CRC Logic Channel 0 Configurations
**/
static Crc_Ip_LogicChannelConfigType LogicChannelCfg_0 =
{
    /* Crc_Ip_ProtocolType Protocol         */ CRC_PROTOCOL_8BIT_CUSTOM,
    /* uint64  PolynomialValue              */ 0x1DU,
    /* boolean WriteBitSwap                 */ FALSE,
    /* boolean WriteByteSwap                */ FALSE,
    /* boolean ReadBitSwap                  */ FALSE,
    /* boolean ReadByteSwap                 */ FALSE,
    /* boolean InverseEnable                */ TRUE
};
#define CRC_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Crc_MemMap.h"

#define CRC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Crc_MemMap.h"
/**
 * @brief  CRC Logic Channel Type 0 Configurations
 * */
static const Crc_Ip_LogicChannelType LogicChannelType_0 =
{
    /* uint8 CalculationType        */ CRC_IP_RUNTIME_CALCULATION,
    /* uint8 HwInstance             */ CRC_HW_INSTANCE_0,
    /* uint8 HwChannel              */ CRC_HW_CHANNEL_0,
    /* LogicChannelConfig           */ &LogicChannelCfg_0
};
#define CRC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Crc_MemMap.h"

#define CRC_START_SEC_VAR_INIT_UNSPECIFIED
#include "Crc_MemMap.h"
/**
* @brief  CRC Logic Channel 1 Configurations
**/
static Crc_Ip_LogicChannelConfigType LogicChannelCfg_1 =
{
    /* Crc_Ip_ProtocolType Protocol         */ CRC_PROTOCOL_16BIT_CUSTOM,
    /* uint64  PolynomialValue              */ 0x1021U,
    /* boolean WriteBitSwap                 */ FALSE,
    /* boolean WriteByteSwap                */ FALSE,
    /* boolean ReadBitSwap                  */ FALSE,
    /* boolean ReadByteSwap                 */ FALSE,
    /* boolean InverseEnable                */ FALSE
};
#define CRC_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Crc_MemMap.h"

#define CRC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Crc_MemMap.h"
/**
 * @brief  CRC Logic Channel Type 1 Configurations
 * */
static const Crc_Ip_LogicChannelType LogicChannelType_1 =
{
    /* uint8 CalculationType        */ CRC_IP_HARDWARE_CALCULATION,
    /* uint8 HwInstance             */ CRC_HW_INSTANCE_0,
    /* uint8 HwChannel              */ CRC_HW_CHANNEL_0,
    /* LogicChannelConfig           */ &LogicChannelCfg_1
};
#define CRC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Crc_MemMap.h"

#define CRC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Crc_MemMap.h"

/**
 * @brief  Crc Ip List Logic Channel Configuration
 * */
static const Crc_Ip_LogicChannelType * const paxLogicChannelConfig[] =
{
    &LogicChannelType_0,
    &LogicChannelType_1
};

/**
 * @brief  CRC IP Initialization Structure
 * */
const Crc_Ip_InitType CrcIp_xConfigInit =
{
    /* LogicChannelConfigList */ paxLogicChannelConfig
};

#define CRC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Crc_MemMap.h"

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

