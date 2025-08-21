/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : FLEXCAN
*   Dependencies         : 
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
*   @file    Can_PBcfg_Init.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Can - module interface
*   @details Configuration Structures for PostBuild
*
*   @addtogroup CAN_DRIVER
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.1, External identifiers shall be distinct.
* The used compilers use more than 31 chars for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.2, Identifiers declared in the same scope and name space shall be distinct.
* The used compilers use more than 31 chars for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.4, Macro identifiers shall be distinct.
* The used compilers use more than 31 chars for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.5, Identifiers shall be distinct from macro names.
* The used compilers use more than 31 chars for identifiers.
*
* @section Can_PBcfg_Init_c_REF_1
* Violates MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents
* of a header file being included more than once
* This violation is not fixed since the inclusion of <MA>_MemMap.h is as per AUTOSAR requirement [SWS_MemMap_00003].
*
* @section Can_PBcfg_Init_c_REF_2
* Violates MISRA 2012 Advisory Rule 20.1, #include directives should only be preceded by preprocessor directives or comments.
* AUTOSAR imposes the specification of the sections in which certain parts of the driver must be placed.
*
* @section Can_PBcfg_Init_c_REF_3
* Violates MISRA 2012 Advisory Rule 8.7, Function and objects should not be defined with external linkage if they
* are referenced in only one translation unit.
* This constant variable will be called by higher layer.
*
* @section Can_PBcfg_Init_c_REF_4
* Violates MISRA 2012 Advisory Rule 8.9, An object should be defined at block scope if identifier only appears in a single function.
* These objects are used when Precompile is supported.
*
* @section Can_PBcfg_Init_c_REF_5
* Violates MISRA 2012 Required Rule 8.4, A compatible declaration shall be visible when an object or function with external linkage is defined.
*
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Can.h"
#include "Can_Ipw_Types.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @file           Can_PBcfg_Init.c
*/
#define CAN_VENDOR_ID_PBCFG_Init_C                      43
#define CAN_AR_RELEASE_MAJOR_VERSION_PBCFG_Init_C       4
#define CAN_AR_RELEASE_MINOR_VERSION_PBCFG_Init_C       4
#define CAN_AR_RELEASE_REVISION_VERSION_PBCFG_Init_C    0
#define CAN_SW_MAJOR_VERSION_PBCFG_Init_C               1
#define CAN_SW_MINOR_VERSION_PBCFG_Init_C               0
#define CAN_SW_PATCH_VERSION_PBCFG_Init_C               1
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Can.h are of the same vendor */
#if (CAN_VENDOR_ID_PBCFG_Init_C != CAN_VENDOR_ID)
    #error "Can_PBcfg_Init.c and Can.h have different vendor ids"
#endif
/* Check if current file and Can.h are of the same Autosar version */
#if ((CAN_AR_RELEASE_MAJOR_VERSION_PBCFG_Init_C != CAN_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_AR_RELEASE_MINOR_VERSION_PBCFG_Init_C != CAN_AR_RELEASE_MINOR_VERSION) || \
     (CAN_AR_RELEASE_REVISION_VERSION_PBCFG_Init_C != CAN_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Can_PBcfg_Init.c and Can.h are different"
#endif
/* Check if current file and Can.h are of the same Software version */
#if ((CAN_SW_MAJOR_VERSION_PBCFG_Init_C != CAN_SW_MAJOR_VERSION) || \
     (CAN_SW_MINOR_VERSION_PBCFG_Init_C != CAN_SW_MINOR_VERSION) || \
     (CAN_SW_PATCH_VERSION_PBCFG_Init_C != CAN_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Can_PBcfg_Init.c and Can.h are different"
#endif

/* Check if current file and Can_Ipw_Types.h are of the same vendor */
#if (CAN_VENDOR_ID_PBCFG_Init_C != CAN_IPW_TYPES_VENDOR_ID_H)
    #error "Can_PBcfg_Init.c and Can_Ipw_Types.h have different vendor IDs"
#endif
/* Check if current file and Can_Ipw_Types.h are of the same Autosar version */
#if ((CAN_AR_RELEASE_MAJOR_VERSION_PBCFG_Init_C != CAN_IPW_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
    (CAN_AR_RELEASE_MINOR_VERSION_PBCFG_Init_C !=  CAN_IPW_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
    (CAN_AR_RELEASE_REVISION_VERSION_PBCFG_Init_C != CAN_IPW_TYPES_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Can_PBcfg_Init.c and Can_Ipw_Types.h are different"
#endif
/* Check if current file and Can_Ipw_Types.h are of the same software version */
#if ((CAN_SW_MAJOR_VERSION_PBCFG_Init_C != CAN_IPW_TYPES_SW_MAJOR_VERSION_H) || \
    (CAN_SW_MINOR_VERSION_PBCFG_Init_C != CAN_IPW_TYPES_SW_MINOR_VERSION_H) || \
    (CAN_SW_PATCH_VERSION_PBCFG_Init_C != CAN_IPW_TYPES_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Can_PBcfg_Init.c and Can_Ipw_Types.h are different"
#endif
/*==================================================================================================
*                                   GLOBAL VARIABLES
==================================================================================================*/
#if (CAN_FEATURE_HAS_DMA_ENABLE == STD_ON)
    /* CAN_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE */
    #define CAN_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #include "Can_MemMap.h"


    #define CAN_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #include "Can_MemMap.h"
    /* CAN_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE */
#endif /* (CAN_FEATURE_HAS_DMA_ENABLE == STD_ON) */
/*==================================================================================================
*                                   GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/
#define CAN_START_SEC_CODE
/* @violates @ref Can_PBcfg_Init_c_REF_1 MISRA 2012 Required Directive 4.10 */
#include "Can_MemMap.h"
extern void can_Error (void);
#if (CAN_TIMESTAMP_ENABLE == STD_ON)
#endif
#define CAN_STOP_SEC_CODE
/* @violates @ref Can_PBcfg_Init_c_REF_1 MISRA 2012 Required Directive 4.10 */
/* @violates @ref Can_PBcfg_Init_c_REF_2 MISRA 2012 Advisory Rule 20.1 */
#include "Can_MemMap.h"
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#define CAN_START_SEC_CONFIG_DATA_32
#include "Can_MemMap.h"

/**
*   @brief  Hardware Buffer Address of CanController_Primary
*/
static const uint32 Can_au32HwBufferAddr_Ctrl0[9U] =
{
    (FLEXCAN_0_BASE + (uint32)0x80U),
    (FLEXCAN_0_BASE + (uint32)0x90U),
    (FLEXCAN_0_BASE + (uint32)0xa0U),
    (FLEXCAN_0_BASE + (uint32)0xb0U),
    (FLEXCAN_0_BASE + (uint32)0xc0U),
    (FLEXCAN_0_BASE + (uint32)0xd0U),
    (FLEXCAN_0_BASE + (uint32)0xe0U),
    (FLEXCAN_0_BASE + (uint32)0xf0U),
    (FLEXCAN_0_BASE + (uint32)0x100U)
};
/**
*   @brief  Hardware Buffer Address of CanController_Internal
*/
static const uint32 Can_au32HwBufferAddr_Ctrl1[12U] =
{
    (FLEXCAN_1_BASE + (uint32)0x80U),
    (FLEXCAN_1_BASE + (uint32)0x90U),
    (FLEXCAN_1_BASE + (uint32)0xa0U),
    (FLEXCAN_1_BASE + (uint32)0xb0U),
    (FLEXCAN_1_BASE + (uint32)0xc0U),
    (FLEXCAN_1_BASE + (uint32)0xd0U),
    (FLEXCAN_1_BASE + (uint32)0xe0U),
    (FLEXCAN_1_BASE + (uint32)0xf0U),
    (FLEXCAN_1_BASE + (uint32)0x100U),
    (FLEXCAN_1_BASE + (uint32)0x110U),
    (FLEXCAN_1_BASE + (uint32)0x120U),
    (FLEXCAN_1_BASE + (uint32)0x130U)
};
/**
*   @brief  Hardware Buffer Address of CanController_Maint
*/
static const uint32 Can_au32HwBufferAddr_Ctrl2[4U] =
{
    (FLEXCAN_2_BASE + (uint32)0x80U),
    (FLEXCAN_2_BASE + (uint32)0x90U),
    (FLEXCAN_2_BASE + (uint32)0xa0U),
    (FLEXCAN_2_BASE + (uint32)0xb0U)
};

/**
*   @brief  Hardware Filter of Can_Internal_Frame_Rx_CurrentMeasures
*/
static const Can_HwFilterType Can_aHwFilter_Object0=
{
    (uint32)0x3300000U,
    (uint32)0xdfffff00U
};
/**
*   @brief  Hardware Filter of Can_Internal_Frame_Rx_PowerMeasures
*/
static const Can_HwFilterType Can_aHwFilter_Object1=
{
    (uint32)0x3d00000U,
    (uint32)0xdfffff00U
};
/**
*   @brief  Hardware Filter of Can_Internal_Frame_Rx_TempMeasures
*/
static const Can_HwFilterType Can_aHwFilter_Object2=
{
    (uint32)0x4700000U,
    (uint32)0xdfffff00U
};
/**
*   @brief  Hardware Filter of Can_Internal_Frame_Rx_VoltageMeasures
*/
static const Can_HwFilterType Can_aHwFilter_Object3=
{
    (uint32)0x4800000U,
    (uint32)0xdfffff00U
};
/**
*   @brief  Hardware Filter of Can_Internal_Frame_Rx_RegulationInfos
*/
static const Can_HwFilterType Can_aHwFilter_Object4=
{
    (uint32)0x6f00000U,
    (uint32)0xdfffff00U
};
/**
*   @brief  Hardware Filter of Can_Internal_Frame_Rx_ControlInfos
*/
static const Can_HwFilterType Can_aHwFilter_Object5=
{
    (uint32)0x7900000U,
    (uint32)0xdfffff00U
};
/**
*   @brief  Hardware Filter of Can_Internal_Frame_Rx_Errors
*/
static const Can_HwFilterType Can_aHwFilter_Object6=
{
    (uint32)0x1f00000U,
    (uint32)0xdfffff00U
};
/**
*   @brief  Hardware Filter of Can_Internal_Frame_Rx_Warnings
*/
static const Can_HwFilterType Can_aHwFilter_Object7=
{
    (uint32)0x5500000U,
    (uint32)0xdfffff00U
};
/**
*   @brief  Hardware Filter of Can_Control_Frame_Rx_Cmds
*/
static const Can_HwFilterType Can_aHwFilter_Object8=
{
    (uint32)0x414U,
    (uint32)0xc7c00000U
};
/**
*   @brief  Hardware Filter of Can_Control_Frame_Rx_ErrorResetReq
*/
static const Can_HwFilterType Can_aHwFilter_Object9=
{
    (uint32)0x44U,
    (uint32)0xc3c00000U
};
/**
*   @brief  Hardware Filter of Can_Maint_Frame_Rx_EquipmentTestReq
*/
static const Can_HwFilterType Can_aHwFilter_Object10=
{
    (uint32)0x8100000U,
    (uint32)0xcfffff00U
};
/**
*   @brief  Hardware Filter of Can_Maint_Frame_Rx_ParamterReq
*/
static const Can_HwFilterType Can_aHwFilter_Object11=
{
    (uint32)0x8300000U,
    (uint32)0xcfffff00U
};

#define CAN_STOP_SEC_CONFIG_DATA_32
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA_8
#include "Can_MemMap.h"

/**
*   @brief  Mapping Controller ID to Controller hardware offset
*/
static const uint8 Can_aCtrlOffsetToCtrlIDMap[CAN_HWCONTROLLER_SUPPORT]=
{
    (uint8)0U,
    (uint8)1U,
    (uint8)2U
};
/**
*   @brief  Mapping Controller ID to Hardware Object ID
*/
static const uint8 Can_aHwObjIDToCtrlIDMap[CAN_HWOBJECT_CONFIG_COUNT]=
{
    (uint8)1U,
    (uint8)1U,
    (uint8)1U,
    (uint8)1U,
    (uint8)1U,
    (uint8)1U,
    (uint8)1U,
    (uint8)1U,
    (uint8)0U,
    (uint8)0U,
    (uint8)2U,
    (uint8)2U,
    (uint8)1U,
    (uint8)1U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)0U,
    (uint8)1U,
    (uint8)2U,
    (uint8)2U,
    (uint8)1U
};

#define CAN_STOP_SEC_CONFIG_DATA_8
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Can_PBcfg_Init_c_REF_1 MISRA 2012 Required Directive 4.10 */
/* @violates @ref Can_PBcfg_Init_c_REF_2 MISRA 2012 Advisory Rule 20.1 */
#include "Can_MemMap.h"

/**
*   @brief  Can Hardware Object Config
*/
/* @violates @ref Can_PBcfg_Init_c_REF_5 MISRA 2012 Required Rule 8.4*/
static const Can_HwObjectConfigType Can_aHwObjectConfig[CAN_HWOBJECT_CONFIG_COUNT]=
{
    /* Can_Internal_Frame_Rx_CurrentMeasures of CanController_Internal */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)0U,
        /* Hardware Object handle type */
        CAN_RECEIVE,
        /* ID Message type */
        CAN_EXTENDED,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_aHwFilter_Object0,
        /* Message Buffer is Type */
        CAN_RX_NORMAL,
        /* Buffer Index in Message buffer ram */
        (uint8)0U,
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl1[0U]
        #if (CAN_TIMESTAMP_ENABLE == STD_ON)
        /* Time Stamp Enable */
        ,(boolean)FALSE
        #endif
    },
    /* Can_Internal_Frame_Rx_PowerMeasures of CanController_Internal */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)1U,
        /* Hardware Object handle type */
        CAN_RECEIVE,
        /* ID Message type */
        CAN_EXTENDED,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_aHwFilter_Object1,
        /* Message Buffer is Type */
        CAN_RX_NORMAL,
        /* Buffer Index in Message buffer ram */
        (uint8)1U,
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl1[1U]
        #if (CAN_TIMESTAMP_ENABLE == STD_ON)
        /* Time Stamp Enable */
        ,(boolean)FALSE
        #endif
    },
    /* Can_Internal_Frame_Rx_TempMeasures of CanController_Internal */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)2U,
        /* Hardware Object handle type */
        CAN_RECEIVE,
        /* ID Message type */
        CAN_EXTENDED,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_aHwFilter_Object2,
        /* Message Buffer is Type */
        CAN_RX_NORMAL,
        /* Buffer Index in Message buffer ram */
        (uint8)2U,
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl1[2U]
        #if (CAN_TIMESTAMP_ENABLE == STD_ON)
        /* Time Stamp Enable */
        ,(boolean)FALSE
        #endif
    },
    /* Can_Internal_Frame_Rx_VoltageMeasures of CanController_Internal */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)3U,
        /* Hardware Object handle type */
        CAN_RECEIVE,
        /* ID Message type */
        CAN_EXTENDED,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_aHwFilter_Object3,
        /* Message Buffer is Type */
        CAN_RX_NORMAL,
        /* Buffer Index in Message buffer ram */
        (uint8)3U,
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl1[3U]
        #if (CAN_TIMESTAMP_ENABLE == STD_ON)
        /* Time Stamp Enable */
        ,(boolean)FALSE
        #endif
    },
    /* Can_Internal_Frame_Rx_RegulationInfos of CanController_Internal */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)4U,
        /* Hardware Object handle type */
        CAN_RECEIVE,
        /* ID Message type */
        CAN_EXTENDED,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_aHwFilter_Object4,
        /* Message Buffer is Type */
        CAN_RX_NORMAL,
        /* Buffer Index in Message buffer ram */
        (uint8)4U,
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl1[4U]
        #if (CAN_TIMESTAMP_ENABLE == STD_ON)
        /* Time Stamp Enable */
        ,(boolean)FALSE
        #endif
    },
    /* Can_Internal_Frame_Rx_ControlInfos of CanController_Internal */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)5U,
        /* Hardware Object handle type */
        CAN_RECEIVE,
        /* ID Message type */
        CAN_EXTENDED,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_aHwFilter_Object5,
        /* Message Buffer is Type */
        CAN_RX_NORMAL,
        /* Buffer Index in Message buffer ram */
        (uint8)5U,
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl1[5U]
        #if (CAN_TIMESTAMP_ENABLE == STD_ON)
        /* Time Stamp Enable */
        ,(boolean)FALSE
        #endif
    },
    /* Can_Internal_Frame_Rx_Errors of CanController_Internal */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)6U,
        /* Hardware Object handle type */
        CAN_RECEIVE,
        /* ID Message type */
        CAN_EXTENDED,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_aHwFilter_Object6,
        /* Message Buffer is Type */
        CAN_RX_NORMAL,
        /* Buffer Index in Message buffer ram */
        (uint8)6U,
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl1[6U]
        #if (CAN_TIMESTAMP_ENABLE == STD_ON)
        /* Time Stamp Enable */
        ,(boolean)FALSE
        #endif
    },
    /* Can_Internal_Frame_Rx_Warnings of CanController_Internal */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)7U,
        /* Hardware Object handle type */
        CAN_RECEIVE,
        /* ID Message type */
        CAN_EXTENDED,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_aHwFilter_Object7,
        /* Message Buffer is Type */
        CAN_RX_NORMAL,
        /* Buffer Index in Message buffer ram */
        (uint8)7U,
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl1[7U]
        #if (CAN_TIMESTAMP_ENABLE == STD_ON)
        /* Time Stamp Enable */
        ,(boolean)FALSE
        #endif
    },
    /* Can_Control_Frame_Rx_Cmds of CanController_Primary */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)8U,
        /* Hardware Object handle type */
        CAN_RECEIVE,
        /* ID Message type */
        CAN_STANDARD,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_aHwFilter_Object8,
        /* Message Buffer is Type */
        CAN_RX_NORMAL,
        /* Buffer Index in Message buffer ram */
        (uint8)0U,
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl0[0U]
        #if (CAN_TIMESTAMP_ENABLE == STD_ON)
        /* Time Stamp Enable */
        ,(boolean)FALSE
        #endif
    },
    /* Can_Control_Frame_Rx_ErrorResetReq of CanController_Primary */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)9U,
        /* Hardware Object handle type */
        CAN_RECEIVE,
        /* ID Message type */
        CAN_STANDARD,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_aHwFilter_Object9,
        /* Message Buffer is Type */
        CAN_RX_NORMAL,
        /* Buffer Index in Message buffer ram */
        (uint8)1U,
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl0[1U]
        #if (CAN_TIMESTAMP_ENABLE == STD_ON)
        /* Time Stamp Enable */
        ,(boolean)FALSE
        #endif
    },
    /* Can_Maint_Frame_Rx_EquipmentTestReq of CanController_Maint */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)10U,
        /* Hardware Object handle type */
        CAN_RECEIVE,
        /* ID Message type */
        CAN_EXTENDED,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_aHwFilter_Object10,
        /* Message Buffer is Type */
        CAN_RX_NORMAL,
        /* Buffer Index in Message buffer ram */
        (uint8)0U,
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl2[0U]
        #if (CAN_TIMESTAMP_ENABLE == STD_ON)
        /* Time Stamp Enable */
        ,(boolean)FALSE
        #endif
    },
    /* Can_Maint_Frame_Rx_ParamterReq of CanController_Maint */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)11U,
        /* Hardware Object handle type */
        CAN_RECEIVE,
        /* ID Message type */
        CAN_EXTENDED,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)1U,
        /* Hw Filter Config */
        &Can_aHwFilter_Object11,
        /* Message Buffer is Type */
        CAN_RX_NORMAL,
        /* Buffer Index in Message buffer ram */
        (uint8)1U,
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl2[1U]
        #if (CAN_TIMESTAMP_ENABLE == STD_ON)
        /* Time Stamp Enable */
        ,(boolean)FALSE
        #endif
    },
    /* Can_Internal_Frame_Tx_ControlReq of CanController_Internal */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)12U,
        /* Hardware Object handle type */
        CAN_TRANSMIT,
        /* ID Message type */
        CAN_EXTENDED,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)0U,
        /* Hw Filter Config */
        NULL_PTR,
        /* Message Buffer is Type */
        CAN_TX_NORMAL,
        /* Buffer Index in Message buffer ram */
        (uint8)8U,
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl1[8U]
        #if (CAN_TIMESTAMP_ENABLE == STD_ON)
        /* Time Stamp Enable */
        ,(boolean)FALSE
        #endif
    },
    /* Can_Internal_Frame_Tx_ModeReq of CanController_Internal */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)13U,
        /* Hardware Object handle type */
        CAN_TRANSMIT,
        /* ID Message type */
        CAN_EXTENDED,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)0U,
        /* Hw Filter Config */
        NULL_PTR,
        /* Message Buffer is Type */
        CAN_TX_NORMAL,
        /* Buffer Index in Message buffer ram */
        (uint8)9U,
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl1[9U]
        #if (CAN_TIMESTAMP_ENABLE == STD_ON)
        /* Time Stamp Enable */
        ,(boolean)FALSE
        #endif
    },
    /* Can_Control_Frame_Tx_ControlStatus of CanController_Primary */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)14U,
        /* Hardware Object handle type */
        CAN_TRANSMIT,
        /* ID Message type */
        CAN_STANDARD,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)0U,
        /* Hw Filter Config */
        NULL_PTR,
        /* Message Buffer is Type */
        CAN_TX_NORMAL,
        /* Buffer Index in Message buffer ram */
        (uint8)2U,
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl0[2U]
        #if (CAN_TIMESTAMP_ENABLE == STD_ON)
        /* Time Stamp Enable */
        ,(boolean)FALSE
        #endif
    },
    /* Can_Control_Frame_Tx_CurrentMeasures of CanController_Primary */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)15U,
        /* Hardware Object handle type */
        CAN_TRANSMIT,
        /* ID Message type */
        CAN_STANDARD,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)0U,
        /* Hw Filter Config */
        NULL_PTR,
        /* Message Buffer is Type */
        CAN_TX_NORMAL,
        /* Buffer Index in Message buffer ram */
        (uint8)3U,
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl0[3U]
        #if (CAN_TIMESTAMP_ENABLE == STD_ON)
        /* Time Stamp Enable */
        ,(boolean)FALSE
        #endif
    },
    /* Can_Control_Frame_Tx_ErrorsWarnings of CanController_Primary */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)16U,
        /* Hardware Object handle type */
        CAN_TRANSMIT,
        /* ID Message type */
        CAN_STANDARD,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)0U,
        /* Hw Filter Config */
        NULL_PTR,
        /* Message Buffer is Type */
        CAN_TX_NORMAL,
        /* Buffer Index in Message buffer ram */
        (uint8)4U,
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl0[4U]
        #if (CAN_TIMESTAMP_ENABLE == STD_ON)
        /* Time Stamp Enable */
        ,(boolean)FALSE
        #endif
    },
    /* Can_Control_Frame_Tx_PbitResult of CanController_Primary */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)17U,
        /* Hardware Object handle type */
        CAN_TRANSMIT,
        /* ID Message type */
        CAN_STANDARD,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)0U,
        /* Hw Filter Config */
        NULL_PTR,
        /* Message Buffer is Type */
        CAN_TX_NORMAL,
        /* Buffer Index in Message buffer ram */
        (uint8)5U,
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl0[5U]
        #if (CAN_TIMESTAMP_ENABLE == STD_ON)
        /* Time Stamp Enable */
        ,(boolean)FALSE
        #endif
    },
    /* Can_Control_Frame_Tx_PowerMeasures of CanController_Primary */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)18U,
        /* Hardware Object handle type */
        CAN_TRANSMIT,
        /* ID Message type */
        CAN_STANDARD,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)0U,
        /* Hw Filter Config */
        NULL_PTR,
        /* Message Buffer is Type */
        CAN_TX_NORMAL,
        /* Buffer Index in Message buffer ram */
        (uint8)6U,
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl0[6U]
        #if (CAN_TIMESTAMP_ENABLE == STD_ON)
        /* Time Stamp Enable */
        ,(boolean)FALSE
        #endif
    },
    /* Can_Control_Frame_Tx_TempMeasures of CanController_Primary */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)19U,
        /* Hardware Object handle type */
        CAN_TRANSMIT,
        /* ID Message type */
        CAN_STANDARD,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)0U,
        /* Hw Filter Config */
        NULL_PTR,
        /* Message Buffer is Type */
        CAN_TX_NORMAL,
        /* Buffer Index in Message buffer ram */
        (uint8)7U,
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl0[7U]
        #if (CAN_TIMESTAMP_ENABLE == STD_ON)
        /* Time Stamp Enable */
        ,(boolean)FALSE
        #endif
    },
    /* Can_Control_Frame_Tx_VoltageMeasures of CanController_Primary */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)20U,
        /* Hardware Object handle type */
        CAN_TRANSMIT,
        /* ID Message type */
        CAN_STANDARD,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)0U,
        /* Hw Filter Config */
        NULL_PTR,
        /* Message Buffer is Type */
        CAN_TX_NORMAL,
        /* Buffer Index in Message buffer ram */
        (uint8)8U,
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl0[8U]
        #if (CAN_TIMESTAMP_ENABLE == STD_ON)
        /* Time Stamp Enable */
        ,(boolean)FALSE
        #endif
    },
    /* Can_Internal_Frame_Tx_ErrorResetReq of CanController_Internal */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)21U,
        /* Hardware Object handle type */
        CAN_TRANSMIT,
        /* ID Message type */
        CAN_EXTENDED,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)0U,
        /* Hw Filter Config */
        NULL_PTR,
        /* Message Buffer is Type */
        CAN_TX_NORMAL,
        /* Buffer Index in Message buffer ram */
        (uint8)10U,
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl1[10U]
        #if (CAN_TIMESTAMP_ENABLE == STD_ON)
        /* Time Stamp Enable */
        ,(boolean)FALSE
        #endif
    },
    /* Can_Maint_Frame_Tx_EquipmentTest of CanController_Maint */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)22U,
        /* Hardware Object handle type */
        CAN_TRANSMIT,
        /* ID Message type */
        CAN_EXTENDED,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)0U,
        /* Hw Filter Config */
        NULL_PTR,
        /* Message Buffer is Type */
        CAN_TX_NORMAL,
        /* Buffer Index in Message buffer ram */
        (uint8)2U,
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl2[2U]
        #if (CAN_TIMESTAMP_ENABLE == STD_ON)
        /* Time Stamp Enable */
        ,(boolean)FALSE
        #endif
    },
    /* Can_Maint_Frame_Tx_Paramter of CanController_Maint */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)23U,
        /* Hardware Object handle type */
        CAN_TRANSMIT,
        /* ID Message type */
        CAN_EXTENDED,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)0U,
        /* Hw Filter Config */
        NULL_PTR,
        /* Message Buffer is Type */
        CAN_TX_NORMAL,
        /* Buffer Index in Message buffer ram */
        (uint8)3U,
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl2[3U]
        #if (CAN_TIMESTAMP_ENABLE == STD_ON)
        /* Time Stamp Enable */
        ,(boolean)FALSE
        #endif
    },
    /* Can_Internal_Frame_Tx_DisableAlarmsRequest of CanController_Internal */
    {
        /* Hardware Object ID */
        (Can_HwHandleType)24U,
        /* Hardware Object handle type */
        CAN_TRANSMIT,
        /* ID Message type */
        CAN_EXTENDED,
        /* Object uses polling */
        (boolean)FALSE,
        /* Object enable trigger transmit */
        (boolean)FALSE,
        /* Number of Hw Object used in one Hoh */
        (uint8)1U,
        /* MainFunction RW period reference */
        (uint8)0xFFU,
        /* Data Payload length */
        (uint8)8U,
        /* Padding value */
        (uint8)0U,
        /* Hardware Filter Count */
        (uint8)0U,
        /* Hw Filter Config */
        NULL_PTR,
        /* Message Buffer is Type */
        CAN_TX_NORMAL,
        /* Buffer Index in Message buffer ram */
        (uint8)11U,
        /* Message buffer address */
        &Can_au32HwBufferAddr_Ctrl1[11U]
        #if (CAN_TIMESTAMP_ENABLE == STD_ON)
        /* Time Stamp Enable */
        ,(boolean)FALSE
        #endif
    }
};



/**
*   @brief  Can Baudrate Config of CanController_Primary
*/
static const Can_BaudrateConfigType Can_aBaudrateConfig_Ctrl0[1U]=
{
    { /* Start BaudConfig Struct 0 */
        /*Can_bEnhanceCBTEnable*/
        (boolean)FALSE,
        /* Tx Bit Rate Switch - Can_bBitRateSwitch */
        (boolean)FALSE,
        /* FD Enable - Can_bFDFrame*/
        (boolean)FALSE,
        /*Nominal Bit Rate - Can_TimeSegmentType Can_NominalBitRate*/
        {
            (uint8)3U,
            (uint8)7U,
            (uint8)2U,
            /* BaudratePrescaler -Can_u16Prescaler  */
            (uint16)9U,
        #if (CAN_DUAL_CLOCK_MODE == STD_ON)
            /* Alternative Baudrate Prescaler  Can_u16PrescalerAlternate*/
            (uint16)9U,
        #endif
            (uint8)0U
        },
        /* Data bit rate - Can_TimeSegmentType Can_DataBitRate */
        {
            (uint8)0U,
            (uint8)0U,
            (uint8)0U,
            (uint16)0U,
            #if (CAN_DUAL_CLOCK_MODE == STD_ON)
            (uint16)0U,
            #endif
            (uint8)0U
        },
        /* Tx Arbitration Start delay - Can_u8TxArbitrationStartDelay */
        (uint8)12U,
        /*Transmiter Delay Compensation Enable */
        (boolean)FALSE,
        /*Specifies the Transmiter Delay Compensation Offset - Can_u8TrcvDelayCompOffset */
        (uint8)0U
        } /* End BaudConfig Struct 0 */
};
/**
*   @brief  HwObjects pointer structure of CanController_Primary
*/
static const Can_HwObjectConfigType * const Can_apHwObject_Ctrl0[9U]=
{
    &Can_aHwObjectConfig[8U],
    &Can_aHwObjectConfig[9U],
    &Can_aHwObjectConfig[14U],
    &Can_aHwObjectConfig[15U],
    &Can_aHwObjectConfig[16U],
    &Can_aHwObjectConfig[17U],
    &Can_aHwObjectConfig[18U],
    &Can_aHwObjectConfig[19U],
    &Can_aHwObjectConfig[20U]
};

/**
*   @brief  Can Baudrate Config of CanController_Internal
*/
static const Can_BaudrateConfigType Can_aBaudrateConfig_Ctrl1[1U]=
{
    { /* Start BaudConfig Struct 0 */
        /*Can_bEnhanceCBTEnable*/
        (boolean)FALSE,
        /* Tx Bit Rate Switch - Can_bBitRateSwitch */
        (boolean)FALSE,
        /* FD Enable - Can_bFDFrame*/
        (boolean)FALSE,
        /*Nominal Bit Rate - Can_TimeSegmentType Can_NominalBitRate*/
        {
            (uint8)3U,
            (uint8)7U,
            (uint8)2U,
            /* BaudratePrescaler -Can_u16Prescaler  */
            (uint16)9U,
        #if (CAN_DUAL_CLOCK_MODE == STD_ON)
            /* Alternative Baudrate Prescaler  Can_u16PrescalerAlternate*/
            (uint16)9U,
        #endif
            (uint8)0U
        },
        /* Data bit rate - Can_TimeSegmentType Can_DataBitRate */
        {
            (uint8)0U,
            (uint8)0U,
            (uint8)0U,
            (uint16)0U,
            #if (CAN_DUAL_CLOCK_MODE == STD_ON)
            (uint16)0U,
            #endif
            (uint8)0U
        },
        /* Tx Arbitration Start delay - Can_u8TxArbitrationStartDelay */
        (uint8)12U,
        /*Transmiter Delay Compensation Enable */
        (boolean)FALSE,
        /*Specifies the Transmiter Delay Compensation Offset - Can_u8TrcvDelayCompOffset */
        (uint8)0U
        } /* End BaudConfig Struct 0 */
};
/**
*   @brief  HwObjects pointer structure of CanController_Internal
*/
static const Can_HwObjectConfigType * const Can_apHwObject_Ctrl1[12U]=
{
    &Can_aHwObjectConfig[0U],
    &Can_aHwObjectConfig[1U],
    &Can_aHwObjectConfig[2U],
    &Can_aHwObjectConfig[3U],
    &Can_aHwObjectConfig[4U],
    &Can_aHwObjectConfig[5U],
    &Can_aHwObjectConfig[6U],
    &Can_aHwObjectConfig[7U],
    &Can_aHwObjectConfig[12U],
    &Can_aHwObjectConfig[13U],
    &Can_aHwObjectConfig[21U],
    &Can_aHwObjectConfig[24U]
};

/**
*   @brief  Can Baudrate Config of CanController_Maint
*/
static const Can_BaudrateConfigType Can_aBaudrateConfig_Ctrl2[1U]=
{
    { /* Start BaudConfig Struct 0 */
        /*Can_bEnhanceCBTEnable*/
        (boolean)FALSE,
        /* Tx Bit Rate Switch - Can_bBitRateSwitch */
        (boolean)FALSE,
        /* FD Enable - Can_bFDFrame*/
        (boolean)FALSE,
        /*Nominal Bit Rate - Can_TimeSegmentType Can_NominalBitRate*/
        {
            (uint8)3U,
            (uint8)7U,
            (uint8)2U,
            /* BaudratePrescaler -Can_u16Prescaler  */
            (uint16)9U,
        #if (CAN_DUAL_CLOCK_MODE == STD_ON)
            /* Alternative Baudrate Prescaler  Can_u16PrescalerAlternate*/
            (uint16)9U,
        #endif
            (uint8)0U
        },
        /* Data bit rate - Can_TimeSegmentType Can_DataBitRate */
        {
            (uint8)0U,
            (uint8)0U,
            (uint8)0U,
            (uint16)0U,
            #if (CAN_DUAL_CLOCK_MODE == STD_ON)
            (uint16)0U,
            #endif
            (uint8)0U
        },
        /* Tx Arbitration Start delay - Can_u8TxArbitrationStartDelay */
        (uint8)12U,
        /*Transmiter Delay Compensation Enable */
        (boolean)FALSE,
        /*Specifies the Transmiter Delay Compensation Offset - Can_u8TrcvDelayCompOffset */
        (uint8)0U
        } /* End BaudConfig Struct 0 */
};
/**
*   @brief  HwObjects pointer structure of CanController_Maint
*/
static const Can_HwObjectConfigType * const Can_apHwObject_Ctrl2[4U]=
{
    &Can_aHwObjectConfig[10U],
    &Can_aHwObjectConfig[11U],
    &Can_aHwObjectConfig[22U],
    &Can_aHwObjectConfig[23U]
};

CAN_IPW_EXT
/**
*   @brief  Can Controller Config
*/
static const Can_ControllerConfigType Can_aControllerConfig[CAN_CONTROLLER_CONFIG_COUNT]=
{
    {   /* Start Generation of ControllerConfig_0 structure */
        /* Abstracted CanIf Controller ID */
        (uint8)0U,
        /* Controller ID */
        (uint8)0U,
        /* Controller Offset */
        (uint8)0U,
        /* Controller Base Address */
        FLEXCAN_0_BASE,
        /* Controller Activation */
        (boolean)TRUE,
        /* Bus Off uses polling */
        (boolean)FALSE,
    /* --- Default values when Legacy FIFO is not available --- */
    /* Global mask of Legacy FIFO */
    (uint32)0xFFFFFFFFU,
    /* ID Acceptance Mode */
    CAN_LEGACY_FIFO_FORMAT_A,
    /* Legacy FIFO Warning Notification */
    NULL_PTR,
    /* Legacy FIFO Overflow Notification */
    NULL_PTR,
    /* Enhanced FIFO Overflow Notification */
    NULL_PTR,
    #if (CAN_FEATURE_HAS_DMA_ENABLE == STD_ON)
    /* Enhance FIFO Dma Error Notification */
    NULL_PTR,
    /* DMA is not enabled */
    NULL_PTR,
    #endif /* (CAN_FEATURE_HAS_DMA_ENABLE == STD_ON) */
    /* Error interrupt enable */
    (boolean)TRUE,
    /* Error Notification */
    can_Error,
    /* Error FD Notification */
    NULL_PTR,
    /* Default Baudrate ID */
    (uint16)0U,
    /* Baudrate config Count*/
    (uint16)1U,
    /* Baudrate config Pointer Structure */
    Can_aBaudrateConfig_Ctrl0,
    /* Pointer to IPW structure to IP config */
    &CanIpwHwChannelConfig_Init0,
    /* Hw Object reference count */
    (uint8)9U,
    /* Pointer point to Group of Hw Object that refer to Controller */
        Can_apHwObject_Ctrl0
    },
    {   /* Start Generation of ControllerConfig_1 structure */
        /* Abstracted CanIf Controller ID */
        (uint8)2U,
        /* Controller ID */
        (uint8)1U,
        /* Controller Offset */
        (uint8)1U,
        /* Controller Base Address */
        FLEXCAN_1_BASE,
        /* Controller Activation */
        (boolean)TRUE,
        /* Bus Off uses polling */
        (boolean)FALSE,
    /* --- Default values when Legacy FIFO is not available --- */
    /* Global mask of Legacy FIFO */
    (uint32)0xFFFFFFFFU,
    /* ID Acceptance Mode */
    CAN_LEGACY_FIFO_FORMAT_A,
    /* Legacy FIFO Warning Notification */
    NULL_PTR,
    /* Legacy FIFO Overflow Notification */
    NULL_PTR,
    /* Enhanced FIFO Overflow Notification */
    NULL_PTR,
    #if (CAN_FEATURE_HAS_DMA_ENABLE == STD_ON)
    /* Enhance FIFO Dma Error Notification */
    NULL_PTR,
    /* DMA is not enabled */
    NULL_PTR,
    #endif /* (CAN_FEATURE_HAS_DMA_ENABLE == STD_ON) */
    /* Error interrupt enable */
    (boolean)FALSE,
    /* Error Notification */
    NULL_PTR,
    /* Error FD Notification */
    NULL_PTR,
    /* Default Baudrate ID */
    (uint16)0U,
    /* Baudrate config Count*/
    (uint16)1U,
    /* Baudrate config Pointer Structure */
    Can_aBaudrateConfig_Ctrl1,
    /* Pointer to IPW structure to IP config */
    &CanIpwHwChannelConfig_Init1,
    /* Hw Object reference count */
    (uint8)12U,
    /* Pointer point to Group of Hw Object that refer to Controller */
        Can_apHwObject_Ctrl1
    },
    {   /* Start Generation of ControllerConfig_2 structure */
        /* Abstracted CanIf Controller ID */
        (uint8)1U,
        /* Controller ID */
        (uint8)2U,
        /* Controller Offset */
        (uint8)2U,
        /* Controller Base Address */
        FLEXCAN_2_BASE,
        /* Controller Activation */
        (boolean)TRUE,
        /* Bus Off uses polling */
        (boolean)FALSE,
    /* --- Default values when Legacy FIFO is not available --- */
    /* Global mask of Legacy FIFO */
    (uint32)0xFFFFFFFFU,
    /* ID Acceptance Mode */
    CAN_LEGACY_FIFO_FORMAT_A,
    /* Legacy FIFO Warning Notification */
    NULL_PTR,
    /* Legacy FIFO Overflow Notification */
    NULL_PTR,
    /* Enhanced FIFO Overflow Notification */
    NULL_PTR,
    #if (CAN_FEATURE_HAS_DMA_ENABLE == STD_ON)
    /* Enhance FIFO Dma Error Notification */
    NULL_PTR,
    /* DMA is not enabled */
    NULL_PTR,
    #endif /* (CAN_FEATURE_HAS_DMA_ENABLE == STD_ON) */
    /* Error interrupt enable */
    (boolean)FALSE,
    /* Error Notification */
    NULL_PTR,
    /* Error FD Notification */
    NULL_PTR,
    /* Default Baudrate ID */
    (uint16)0U,
    /* Baudrate config Count*/
    (uint16)1U,
    /* Baudrate config Pointer Structure */
    Can_aBaudrateConfig_Ctrl2,
    /* Pointer to IPW structure to IP config */
    &CanIpwHwChannelConfig_Init2,
    /* Hw Object reference count */
    (uint8)4U,
    /* Pointer point to Group of Hw Object that refer to Controller */
        Can_apHwObject_Ctrl2
    }
};  /* End of generation Can_ControllerConfigType */


static const Can_ControllerConfigType * const Can_apController[CAN_CONTROLLER_CONFIG_COUNT]=
{
    &Can_aControllerConfig[0U],
    &Can_aControllerConfig[1U],
    &Can_aControllerConfig[2U]
};
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
/**
*   @brief  Top level structure contain all Can driver Config
*/
const Can_ConfigType Can_Config_Init =
{
    /* Configuration Core ID */
    (uint32)0U,
    /* The HTH first Index after HRH consecutive */
    (Can_HwHandleType)12U,
    /* Mapping Controller ID to Controller Hw Offset */
    Can_aCtrlOffsetToCtrlIDMap,
    /* Mapping Controller ID to Hardware Object ID */
    Can_aHwObjIDToCtrlIDMap,
    /* Pointer point to Can Hw Object Config */
    Can_aHwObjectConfig,
    /* Array of Pointer to Controller infomation have aligned by Controller ID */
    Can_apController
};

#define CAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Can_PBcfg_Init_c_REF_1 MISRA 2012 Required Directive 4.10 */
/* @violates @ref Can_PBcfg_Init_c_REF_2 MISRA 2012 Advisory Rule 20.1 */
#include "Can_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

