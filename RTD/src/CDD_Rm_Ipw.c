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
*   @file CDD_Rm_Ipw.c
*
*   @addtogroup RM_MODULE
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
#include "CDD_Rm_Ipw.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_IPW_VENDOR_ID_C                      43
#define RM_IPW_AR_RELEASE_MAJOR_VERSION_C       4
#define RM_IPW_AR_RELEASE_MINOR_VERSION_C       4
#define RM_IPW_AR_RELEASE_REVISION_VERSION_C    0
#define RM_IPW_SW_MAJOR_VERSION_C               1
#define RM_IPW_SW_MINOR_VERSION_C               0
#define RM_IPW_SW_PATCH_VERSION_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* CCheck if current file and Mcal.h header file are of the same Autosar version */
    #if ((RM_IPW_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (RM_IPW_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of CDD_Rm_Ipw.h and Mcal.h are different"
    #endif
#endif

/* Checks against CDD_Rm_Ipw.h */
#if (RM_IPW_VENDOR_ID_C != RM_IPW_VENDOR_ID)
    #error "CDD_Rm_Ipw.c and CDD_Rm_Ipw.h have different vendor ids"
#endif
#if ((RM_IPW_AR_RELEASE_MAJOR_VERSION_C    != RM_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (RM_IPW_AR_RELEASE_MINOR_VERSION_C    != RM_IPW_AR_RELEASE_MINOR_VERSION) || \
     (RM_IPW_AR_RELEASE_REVISION_VERSION_C != RM_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR Version Numbers of CDD_Rm_Ipw.c and CDD_Rm_Ipw.h are different"
#endif
#if ((RM_IPW_SW_MAJOR_VERSION_C != RM_IPW_SW_MAJOR_VERSION) || \
     (RM_IPW_SW_MINOR_VERSION_C != RM_IPW_SW_MINOR_VERSION) || \
     (RM_IPW_SW_PATCH_VERSION_C != RM_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm_Ipw.c and CDD_Rm_Ipw.h are different"
#endif

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define RM_START_SEC_CODE
#include "Rm_MemMap.h"

/*
 * @brief         Initializes the Memory Protection Unit general parameters and
 *                region configurations
 * @details       This function is non-reentrant
 * @param[in]     pConfig: pointer to configuration structure for MPU.
 * @return        void
 * @pre           None
 */
void Rm_Ipw_Mpu_Init(const Rm_Ipw_ConfigType * pIpwConfig)
{
    Mpu_Ip_Init(pIpwConfig->Rm_Ipw_pMpuConfig);
}

/*
 * @brief         Configures the region selected by regionNumber with the data from pUserConfigPtr
 * @details       This function is Reentrant
 * @param[in]     regionNumber: Region to be modified .
 * @param[in]     pUserConfigPtr: pointer to the region configuration structure for MPU.
 * @return        void
 * @pre           None
 */
void Rm_Ipw_Mpu_SetRegionConfig(uint8 u8RegionNum, const Rm_Mpu_RegionConfigType * const pUserConfigPtr)
{
    Mpu_Ip_SetRegionConfig(u8RegionNum, pUserConfigPtr);
}

/*
 * @brief         Enables or disabled a specific region
 * @details       This function is Reentrant
 * @param[in]     u8RegionNum : Region to be modified
 * @param[in]     bEnable  : Specifies wheter the region is enabled or disabled
 * @return        void
 * @pre           None
 */
void Rm_Ipw_Mpu_EnableRegion(uint8 u8RegionNum, boolean bEnable)
{
    Mpu_Ip_EnableRegion(u8RegionNum, bEnable);
}

/*
 * @brief         Modify the User access mode for a master to a specific region
 * @details       This function is Reentrant
 * @param[in]     u8RegionNum : Region to be modified
 * @param[in]     eMaster     : Master to be modified
 * @param[in]     eMode       : Specifies the new mode access
 * @return        void
 * @pre           None
 */
void Rm_Ipw_Mpu_SetAccessMode(uint8 u8RegionNum,
                              Rm_Mpu_MasterType eMaster,
                              Rm_Mpu_SupervisorAccessModeType eSupervisorMode,
                              Rm_Mpu_UserAccessModeType eUserMode
                             )
{
    Mpu_Ip_SetAccessMode(u8RegionNum, eMaster, eSupervisorMode, eUserMode);
}

/*
 * @brief         Retrieve error details
 * @details       This function is Reentrant
 * @param[out]    pErrorDetails : Storage where the data will be saved
 * @return        boolean - TRUE if an error was present, FALSE otherwise
 * @pre           None
 */
boolean Rm_Ipw_Mpu_GetErrorDetails(Rm_Mpu_ErrorDetailsType * pErrorDetails)
{
    return Mpu_Ip_GetErrorDetails(pErrorDetails);
}

#define RM_STOP_SEC_CODE
#include "Rm_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
