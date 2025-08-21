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
#ifndef CDD_RM_IPW_H
#define CDD_RM_IPW_H

/**
*   @file CDD_Rm_Ipw.h
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
#include "CDD_Rm_Cfg.h"
#include "CDD_Rm_Ipw_Cfg.h"
#include "Mpu_Ip.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_IPW_VENDOR_ID                    43
#define RM_IPW_AR_RELEASE_MAJOR_VERSION     4
#define RM_IPW_AR_RELEASE_MINOR_VERSION     4
#define RM_IPW_AR_RELEASE_REVISION_VERSION  0
#define RM_IPW_SW_MAJOR_VERSION             1
#define RM_IPW_SW_MINOR_VERSION             0
#define RM_IPW_SW_PATCH_VERSION             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against CDD_Rm_Cfg.h */
#if (RM_IPW_VENDOR_ID != RM_CFG_VENDOR_ID)
    #error "CDD_Rm_Ipw.h and CDD_Rm_Cfg.h have different vendor ids"
#endif
#if ((RM_IPW_AR_RELEASE_MAJOR_VERSION    != RM_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (RM_IPW_AR_RELEASE_MINOR_VERSION    != RM_CFG_AR_RELEASE_MINOR_VERSION) || \
     (RM_IPW_AR_RELEASE_REVISION_VERSION != RM_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR Version Numbers of CDD_Rm_Ipw.h and CDD_Rm_Cfg.h are different"
#endif
#if ((RM_IPW_SW_MAJOR_VERSION != RM_CFG_SW_MAJOR_VERSION) || \
     (RM_IPW_SW_MINOR_VERSION != RM_CFG_SW_MINOR_VERSION) || \
     (RM_IPW_SW_PATCH_VERSION != RM_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm_Ipw.h and CDD_Rm_Cfg.h are different"
#endif

/* Checks against CDD_Rm_Ipw_Cfg.h */
#if (RM_IPW_VENDOR_ID != RM_IPW_CFG_VENDOR_ID)
    #error "CDD_Rm_Ipw.h and CDD_Rm_Ipw_Cfg.h have different vendor ids"
#endif
#if ((RM_IPW_AR_RELEASE_MAJOR_VERSION    != RM_IPW_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (RM_IPW_AR_RELEASE_MINOR_VERSION    != RM_IPW_CFG_AR_RELEASE_MINOR_VERSION) || \
     (RM_IPW_AR_RELEASE_REVISION_VERSION != RM_IPW_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR Version Numbers of CDD_Rm_Ipw.h and CDD_Rm_Ipw_Cfg.h are different"
#endif
#if ((RM_IPW_SW_MAJOR_VERSION != RM_IPW_CFG_SW_MAJOR_VERSION) || \
     (RM_IPW_SW_MINOR_VERSION != RM_IPW_CFG_SW_MINOR_VERSION) || \
     (RM_IPW_SW_PATCH_VERSION != RM_IPW_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm_Ipw.h and CDD_Rm_Ipw_Cfg.h are different"
#endif

/* Checks against Mpu_Ip.h */
#if (RM_IPW_VENDOR_ID != RM_MPU_IP_VENDOR_ID)
    #error "CDD_Rm_Ipw.h and Mpu_Ip.h have different vendor ids"
#endif
#if ((RM_IPW_AR_RELEASE_MAJOR_VERSION    != RM_MPU_IP_AR_RELEASE_MAJOR_VERSION) || \
     (RM_IPW_AR_RELEASE_MINOR_VERSION    != RM_MPU_IP_AR_RELEASE_MINOR_VERSION) || \
     (RM_IPW_AR_RELEASE_REVISION_VERSION != RM_MPU_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR Version Numbers of CDD_Rm_Ipw.h and Mpu_Ip.h are different"
#endif
#if ((RM_IPW_SW_MAJOR_VERSION != RM_MPU_IP_SW_MAJOR_VERSION) || \
     (RM_IPW_SW_MINOR_VERSION != RM_MPU_IP_SW_MINOR_VERSION) || \
     (RM_IPW_SW_PATCH_VERSION != RM_MPU_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of CDD_Rm_Ipw.h and Mpu_Ip.h are different"
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
typedef Mpu_Ip_RegionConfigType              Rm_Mpu_RegionConfigType;
typedef Mpu_Ip_UserAccessModeType            Rm_Mpu_UserAccessModeType;
typedef Mpu_Ip_SupervisorAccessModeType      Rm_Mpu_SupervisorAccessModeType;
typedef Mpu_Ip_ErrorDetailsType              Rm_Mpu_ErrorDetailsType;
typedef Mpu_Ip_MasterType                    Rm_Mpu_MasterType;

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
void Rm_Ipw_Mpu_Init(const Rm_Ipw_ConfigType * pIpwConfig);

/*
 * @brief         Configures the region selected by regionNumber with the data from pUserConfigPtr
 * @details       This function is Reentrant
 * @param[in]     regionNumber: Region to be modified .
 * @param[in]     pUserConfigPtr: pointer to the region configuration structure for MPU.
 * @return        void
 * @pre           None
 */
void Rm_Ipw_Mpu_SetRegionConfig(uint8 u8RegionNum, const Rm_Mpu_RegionConfigType * const pUserConfigPtr);

/*
 * @brief         Enables or disabled a specific region
 * @details       This function is Reentrant
 * @param[in]     u8RegionNum : Region to be modified
 * @param[in]     bEnable  : Specifies wheter the region is enabled or disabled
 * @return        void
 * @pre           None
 */
void Rm_Ipw_Mpu_EnableRegion(uint8 u8RegionNum, boolean bEnable);

/*
 * @brief         Modify the User access mode for a master to a specific region
 * @details       This function is Reentrant
 * @param[in]     u8RegionNum : Region to be modified
 * @param[in]     eMaster     : Master to be modified
 * @param[in]     eSupervisorMode : Specifies the new mode access in supervisor mode
 * @param[in]     eUserMode       : Specifies the new mode access in user mode
 * @return        void
 * @pre           None
 */
void Rm_Ipw_Mpu_SetAccessMode(uint8 u8RegionNum,
                              Rm_Mpu_MasterType eMaster,
                              Rm_Mpu_SupervisorAccessModeType eSupervisorMode,
                              Rm_Mpu_UserAccessModeType eUserMode
                             );

/*
 * @brief         Retrieve error details
 * @details       This function is Reentrant
 * @param[out]    pErrorDetails : Storage where the data will be saved
 * @return        boolean - TRUE if an error was present, FALSE otherwise
 * @pre           None
 */
boolean Rm_Ipw_Mpu_GetErrorDetails(Rm_Mpu_ErrorDetailsType * pErrorDetails);

#define RM_STOP_SEC_CODE
#include "Rm_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CDD_RM_IPW_H */
