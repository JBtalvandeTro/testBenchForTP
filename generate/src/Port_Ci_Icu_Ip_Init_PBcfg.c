
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : Ftm Lpit Lptmr Port_Ci LpCmp
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
 *   @file          Port_Ci_Icu_Ip_PBCfg.c
 *   @implements    Icu_PBCfg.c_Artifact
 *   @version       1.0.1
 *
 *   @brief   AUTOSAR Icu - contains the data exported by the Icu module
 *   @details Contains the information that will be exported by the module, as requested by Autosar.
 *
 *   @addtogroup port_Ci_icu_ip PORT_CI IPL
 *   @{
 */
 


#ifdef __cplusplus
extern "C"{
#endif

 /*==================================================================================================
 *                                         INCLUDE FILES
 * 1) system and project includes
 * 2) needed interfaces from external units
 * 3) internal and external interfaces from this unit
 *================================================================================================*/
#include "StandardTypes.h"
#include "Port_Ci_Icu_Ip_Types.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/
#define PORT_CI_ICU_IP_INIT_PBCFG_VENDOR_ID_C                       43
#define PORT_CI_ICU_IP_INIT_PBCFG_AR_RELEASE_MAJOR_VERSION_C        4
#define PORT_CI_ICU_IP_INIT_PBCFG_AR_RELEASE_MINOR_VERSION_C        4
#define PORT_CI_ICU_IP_INIT_PBCFG_AR_RELEASE_REVISION_VERSION_C     0
#define PORT_CI_ICU_IP_INIT_PBCFG_SW_MAJOR_VERSION_C                1
#define PORT_CI_ICU_IP_INIT_PBCFG_SW_MINOR_VERSION_C                0
#define PORT_CI_ICU_IP_INIT_PBCFG_SW_PATCH_VERSION_C                1

/*==================================================================================================
 *                                      FILE VERSION CHECKS
 *================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and StandardTypes.h file are of the same Autosar version */
    #if ((PORT_CI_ICU_IP_INIT_PBCFG_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (PORT_CI_ICU_IP_INIT_PBCFG_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Port_Ci_Icu_Ip_INIT_PBcfg.c and StandardTypes.h are different"
    #endif
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (PORT_CI_ICU_IP_INIT_PBCFG_VENDOR_ID_C != PORT_CI_ICU_IP_TYPES_VENDOR_ID)
    #error "Port_Ci_Icu_Ip_INIT_PBcfg.c and Port_Ci_Icu_Ip_Types.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((PORT_CI_ICU_IP_INIT_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != PORT_CI_ICU_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PORT_CI_ICU_IP_INIT_PBCFG_AR_RELEASE_MINOR_VERSION_C    != PORT_CI_ICU_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PORT_CI_ICU_IP_INIT_PBCFG_AR_RELEASE_REVISION_VERSION_C != PORT_CI_ICU_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Port_Ci_Icu_Ip_INIT_PBcfg.c and Port_Ci_Icu_Ip_Types.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((PORT_CI_ICU_IP_INIT_PBCFG_SW_MAJOR_VERSION_C != PORT_CI_ICU_IP_TYPES_SW_MAJOR_VERSION) || \
     (PORT_CI_ICU_IP_INIT_PBCFG_SW_MINOR_VERSION_C != PORT_CI_ICU_IP_TYPES_SW_MINOR_VERSION) || \
     (PORT_CI_ICU_IP_INIT_PBCFG_SW_PATCH_VERSION_C != PORT_CI_ICU_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Port_Ci_Icu_Ip_INIT_PBcfg.c and Port_Ci_Icu_Ip_Types.h are different"
#endif

/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
 *================================================================================================*/

/*==================================================================================================
 *                                       LOCAL MACROS
 *================================================================================================*/

/*==================================================================================================
 *                                      LOCAL CONSTANTS
 *================================================================================================*/

/*==================================================================================================
 *                                       LOCAL VARIABLES
 *================================================================================================*/
 
/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
 *================================================================================================*/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

/** @brief Signature of report events interrupt function. */
extern void Icu_ReportEvents(uint16 Channel, boolean bOverflow);

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

/*==================================================================================================
 *                                       GLOBAL CONSTANTS
 *================================================================================================*/
#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"  
/*
 *  @brief    Init PORT_CI Channels Configuration
 */
const Port_Ci_Icu_Ip_ChannelConfigType Port_Ci_Icu_Ip_4_ChannelConfig_PB_Init[6U] =
{
    /** @brief IcuPortChannel_0 */
    {
        /** @brief Port_Ci HW Module and Channel used by the Icu channel */
        9U,
        /** @brief Port_CI Edge type*/
        PORT_CI_ICU_RISING_EDGE,
        /** @brief Callback Pointer */
        &Icu_ReportEvents,
        NULL_PTR,
        /** @brief Callback Param1*/
        0U
    }
    ,
    /** @brief IcuPortChannel_1 */
    {
        /** @brief Port_Ci HW Module and Channel used by the Icu channel */
        13U,
        /** @brief Port_CI Edge type*/
        PORT_CI_ICU_FALLING_EDGE,
        /** @brief Callback Pointer */
        &Icu_ReportEvents,
        NULL_PTR,
        /** @brief Callback Param1*/
        4U
    }
    ,
    /** @brief IcuPortChannel_2 */
    {
        /** @brief Port_Ci HW Module and Channel used by the Icu channel */
        27U,
        /** @brief Port_CI Edge type*/
        PORT_CI_ICU_FALLING_EDGE,
        /** @brief Callback Pointer */
        &Icu_ReportEvents,
        NULL_PTR,
        /** @brief Callback Param1*/
        5U
    }
    ,
    /** @brief IcuPortChannel_3 */
    {
        /** @brief Port_Ci HW Module and Channel used by the Icu channel */
        12U,
        /** @brief Port_CI Edge type*/
        PORT_CI_ICU_RISING_EDGE,
        /** @brief Callback Pointer */
        &Icu_ReportEvents,
        NULL_PTR,
        /** @brief Callback Param1*/
        3U
    }
    ,
    /** @brief IcuPortChannel_4 */
    {
        /** @brief Port_Ci HW Module and Channel used by the Icu channel */
        10U,
        /** @brief Port_CI Edge type*/
        PORT_CI_ICU_RISING_EDGE,
        /** @brief Callback Pointer */
        &Icu_ReportEvents,
        NULL_PTR,
        /** @brief Callback Param1*/
        1U
    }
    ,
    /** @brief IcuPortChannel_5 */
    {
        /** @brief Port_Ci HW Module and Channel used by the Icu channel */
        11U,
        /** @brief Port_CI Edge type*/
        PORT_CI_ICU_RISING_EDGE,
        /** @brief Callback Pointer */
        &Icu_ReportEvents,
        NULL_PTR,
        /** @brief Callback Param1*/
        2U
    }
    
};
/*
 *  @brief    Init Default PORT_CI IP Configuration
 */
const Port_Ci_Icu_Ip_ConfigType Port_Ci_Icu_Ip_4_Config_PB_Init = 
{
    /** @brief Number of Port_Ci channels in the Icu configuration */
    (uint8)6U,
    /** @brief Pointer to the array of Port_Ci channel configurations */
    &Port_Ci_Icu_Ip_4_ChannelConfig_PB_Init
};
#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"   
/*==================================================================================================
 *                                       GLOBAL VARIABLES
 *================================================================================================*/

/*==================================================================================================
 *                                   LOCAL FUNCTION PROTOTYPES
 *================================================================================================*/

/*==================================================================================================
 *                                       LOCAL FUNCTIONS
 *================================================================================================*/

#ifdef __cplusplus
}
#endif
/** @} */

