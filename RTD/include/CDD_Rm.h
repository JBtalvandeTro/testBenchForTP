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
#ifndef CDD_RM_H
#define CDD_RM_H

/**
*   @file CDD_Rm.h
*
*   @addtogroup RM_MODULE RM Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "CDD_Rm_Cfg.h"
#include "CDD_Rm_Ipw.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_VENDOR_ID                       43
#define RM_MODULE_ID                       255
#define RM_AR_RELEASE_MAJOR_VERSION        4
#define RM_AR_RELEASE_MINOR_VERSION        4
#define RM_AR_RELEASE_REVISION_VERSION     0
#define RM_SW_MAJOR_VERSION                1
#define RM_SW_MINOR_VERSION                0
#define RM_SW_PATCH_VERSION                1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Mcal.h */
    #if ((RM_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (RM_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AUTOSAR Version Numbers of CDD_Rm.h and Mcal.h are different"
    #endif
#endif
/* Checks against CDD_Rm_Cfg.h */
#if (RM_VENDOR_ID != RM_CFG_VENDOR_ID)
    #error "CDD_Rm.h and CDD_Rm_Cfg.h have different vendor ids"
#endif
#if ((RM_AR_RELEASE_MAJOR_VERSION    != RM_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (RM_AR_RELEASE_MINOR_VERSION    != RM_CFG_AR_RELEASE_MINOR_VERSION) || \
     (RM_AR_RELEASE_REVISION_VERSION != RM_CFG_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of CDD_Rm.h and CDD_Rm_Cfg.h are different"
#endif
#if ((RM_SW_MAJOR_VERSION != RM_CFG_SW_MAJOR_VERSION) || \
     (RM_SW_MINOR_VERSION != RM_CFG_SW_MINOR_VERSION) || \
     (RM_SW_PATCH_VERSION != RM_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm.h and CDD_Rm_Cfg.h are different"
#endif
/* Checks against CDD_Rm_Ipw.h */
#if (RM_VENDOR_ID != RM_IPW_VENDOR_ID)
    #error "CDD_Rm.h and CDD_Rm_Ipw.h have different vendor ids"
#endif
#if ((RM_AR_RELEASE_MAJOR_VERSION    != RM_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (RM_AR_RELEASE_MINOR_VERSION    != RM_IPW_AR_RELEASE_MINOR_VERSION) || \
     (RM_AR_RELEASE_REVISION_VERSION != RM_IPW_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of CDD_Rm.h and CDD_Rm_Ipw.h are different"
#endif
#if ((RM_SW_MAJOR_VERSION != RM_IPW_SW_MAJOR_VERSION) || \
     (RM_SW_MINOR_VERSION != RM_IPW_SW_MINOR_VERSION) || \
     (RM_SW_PATCH_VERSION != RM_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm.h and CDD_Rm_Ipw.h are different"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/
#define RM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"

/**  Export RM configurations.*/
RM_CONFIG_EXT

#define RM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"

#if (RM_DEV_ERROR_DETECT == STD_ON)
    #define RM_INIT_ID_U8                               ((uint8)0x00U)
    #define RM_E_ALREADY_INITIALIZED_U8                 ((uint8)0x02U)
    #define RM_E_UNINIT_U8                              ((uint8)0x03U)
    #define RM_E_INIT_FAILED_U8                         ((uint8)0x04U)
#if (RM_GET_VERSION_INFO_API == STD_ON)
    #define RM_E_PARAM_POINTER                          ((uint8)0x05U)
    #define RM_GETVERSIONINFO_ID                        ((uint8)0x01U)
#endif  /* RM_GET_VERSION_INFO_API == STD_ON */

#endif  /* (RM_DEV_ERROR_DETECT == STD_ON) */


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
*                                      FUNCTION PROTOTYPES
==================================================================================================*/
#define RM_START_SEC_CODE
#include "Rm_MemMap.h"

/**
 * @brief          This function initializes the RM hardware components.
 * @details        This service is a non reentrant function used for driver initialization.
 *        The  Initialization function  shall initialize  all relevant  registers of  the configured
 *        hardware with the  values of the  structure referenced by  the parameter ConfigPtr.
 *        If  the  hardware  allows  for   only  one  usage   of  the  register,   the  driver module
 *        implementing that functionality is responsible for initializing the register.
 *        The initialization function of this module shall always have a pointer as a parameter, even
 *        though for Variant PC no configuration set shall be given.
 *        Instead a NULL pointer shall be passed to the initialization function.
 *
 * @param[in]         ConfigPtr        Pointer to a selected configuration structure.
 *
 * @return             void
 * @api
 *
 *
 */
void Rm_Init(Rm_ConfigType const * ConfigPtr);




#if (RM_ENABLE_MPU == STD_ON)
 /**
 * @brief         Configures the region selected by u8RegionNum with the data from pUserConfigPtr
 *
 * @details       This function is Reentrant
 *
 * @param[in]     u8RegionNum:    region number
 * @param[in]     pUserConfigPtr: pointer to the region configuration structure for MPU.
 * @return        void
 *
 * @api
 *
 * @pre
 *
 * */
void Rm_Mpu_SetRegionConfig(uint8 u8RegionNum, const Rm_Mpu_RegionConfigType * const pUserConfigPtr);

/**
 * @brief         Enables or disabled a specific region
 *
 * @details       This function is Reentrant
 *
 * @param[in]     u8Region : Region to be modified
 * @param[in]     bEnable  : Specifies whether the region is enabled or disabled
 * @return        void
 *
 * @api
 *
 * @pre
 *
 * */
void Rm_Mpu_EnableRegion(uint8 u8RegionNum, boolean bEnable);

/**
 * @brief         Modify the access mode for a master to a specific region
 *
 * @details       This function is Reentrant
 *
 * @param[in]     u8RegionNum     : Region to be modified
 * @param[in]     eSupervisorMode : Specifies the new mode access in supervisor mode
 * @param[in]     eUserMode       : Specifies the new mode access in user mode
 * @return        void
 *
 * @api
 *
 * @pre
 *
 * */
void Rm_Mpu_SetAccessMode(uint8 u8RegionNum,
                          Rm_Mpu_MasterType eMaster,
                          Rm_Mpu_SupervisorAccessModeType eSupervisorMode,
                          Rm_Mpu_UserAccessModeType eUserMode
                         );

/**
 * @brief         Retrieve error details
 *
 * @details       This function is Reentrant
 *
 * @param[out]    pErrorDetails : Storage where the data will be saved
 * @return        boolean - TRUE if an error was present, FALSE otherwise
 *
 * @api
 *
 * @pre
 *
 * */
Std_ReturnType Rm_Mpu_GetErrorDetails(Rm_Mpu_ErrorDetailsType * pErrorDetails);

#endif /* #if (STD_ON == RM_ENABLE_MPU)  */



#if (RM_GET_VERSION_INFO_API == STD_ON)
/**
 * @brief   This service returns the version information of this module.
 * @details This  service is Non reentrant and returns the version information of this module.
 *          The version information includes:
 *          - Module Id
 *          - Vendor Id
 *          - Vendor specific version numbers
 *          If source code for caller and callee of this function is available this function should
 *          be realized as a macro. The macro should be defined in the modules header file.
 *
 * @param[out]    versioninfo      Pointer to location to store version info
 *
 * @return void
 *
 * @api
 *
 * */
void Rm_GetVersionInfo(Std_VersionInfoType  * versioninfo);
#endif  /* RM_GET_VERSION_INFO_API == STD_ON */

#define RM_STOP_SEC_CODE
#include "Rm_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* RM_H */
