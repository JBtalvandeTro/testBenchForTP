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

/**
*   @file Qspi_Ip_Init_PBcfg.c
*
*   @addtogroup FLS
*   @{
*/

/* implements Qspi_Ip_PBcfg.c_Artifact */

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Qspi_Ip_Types.h"
#include "Qspi_Ip_Features.h"
#include "Qspi_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_QSPI_IP_VENDOR_ID_CFG_C                      43
#define FLS_QSPI_IP_AR_RELEASE_MAJOR_VERSION_CFG_C       4
#define FLS_QSPI_IP_AR_RELEASE_MINOR_VERSION_CFG_C       4
#define FLS_QSPI_IP_AR_RELEASE_REVISION_VERSION_CFG_C    0
#define FLS_QSPI_IP_SW_MAJOR_VERSION_CFG_C               1
#define FLS_QSPI_IP_SW_MINOR_VERSION_CFG_C               0
#define FLS_QSPI_IP_SW_PATCH_VERSION_CFG_C               1


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Qspi_Ip_Types header file are of the same vendor */
#if (FLS_QSPI_IP_VENDOR_ID_CFG_C != FLS_QSPI_TYPES_VENDOR_ID)
    #error "Qspi_Ip_PBcfg.c and Qspi_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_Types header file are of the same Autosar version */
#if ((FLS_QSPI_IP_AR_RELEASE_MAJOR_VERSION_CFG_C    != FLS_QSPI_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_QSPI_IP_AR_RELEASE_MINOR_VERSION_CFG_C    != FLS_QSPI_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FLS_QSPI_IP_AR_RELEASE_REVISION_VERSION_CFG_C != FLS_QSPI_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Qspi_Ip_PBcfg.c and Qspi_Ip_Types.h are different"
#endif
/* Check if current file and Qspi_Ip_Types header file are of the same Software version */
#if ((FLS_QSPI_IP_SW_MAJOR_VERSION_CFG_C != FLS_QSPI_TYPES_SW_MAJOR_VERSION) || \
     (FLS_QSPI_IP_SW_MINOR_VERSION_CFG_C != FLS_QSPI_TYPES_SW_MINOR_VERSION) || \
     (FLS_QSPI_IP_SW_PATCH_VERSION_CFG_C != FLS_QSPI_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Qspi_Ip_PBcfg.c and Qspi_Ip_Types.h are different"
#endif

/* Check if current file and Qspi_Ip_Features header file are of the same vendor */
#if (FLS_QSPI_IP_VENDOR_ID_CFG_C != QSPI_IP_FEATURES_VENDOR_ID_CFG)
    #error "Qspi_Ip_PBcfg.c and Qspi_Ip_Features.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_Features header file are of the same Autosar version */
#if ((FLS_QSPI_IP_AR_RELEASE_MAJOR_VERSION_CFG_C    != QSPI_IP_FEATURES_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (FLS_QSPI_IP_AR_RELEASE_MINOR_VERSION_CFG_C    != QSPI_IP_FEATURES_AR_RELEASE_MINOR_VERSION_CFG) || \
     (FLS_QSPI_IP_AR_RELEASE_REVISION_VERSION_CFG_C != QSPI_IP_FEATURES_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Qspi_Ip_PBcfg.c and Qspi_Ip_Features.h are different"
#endif
/* Check if current file and Qspi_Ip_Features header file are of the same Software version */
#if ((FLS_QSPI_IP_SW_MAJOR_VERSION_CFG_C != QSPI_IP_FEATURES_SW_MAJOR_VERSION_CFG) || \
     (FLS_QSPI_IP_SW_MINOR_VERSION_CFG_C != QSPI_IP_FEATURES_SW_MINOR_VERSION_CFG) || \
     (FLS_QSPI_IP_SW_PATCH_VERSION_CFG_C != QSPI_IP_FEATURES_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Qspi_Ip_PBcfg.c and Qspi_Ip_Features.h are different"
#endif

/* Check if current file and Qspi_Ip_Cfg.h header file are of the same vendor */
#if (FLS_QSPI_IP_VENDOR_ID_CFG_C !=  QSPI_IP_VENDOR_ID_CFG)
    #error "Qspi_Ip_PBcfg.c and Qspi_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_Cfg.h header file are of the same Autosar version */
#if ((FLS_QSPI_IP_AR_RELEASE_MAJOR_VERSION_CFG_C    !=  QSPI_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (FLS_QSPI_IP_AR_RELEASE_MINOR_VERSION_CFG_C    !=  QSPI_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (FLS_QSPI_IP_AR_RELEASE_REVISION_VERSION_CFG_C !=  QSPI_IP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Qspi_Ip_PBcfg.c and Qspi_Ip_Cfg.h are different"
#endif
/* Check if current file and Qspi_Ip_Cfg.h header file are of the same Software version */
#if ((FLS_QSPI_IP_SW_MAJOR_VERSION_CFG_C !=  QSPI_IP_SW_MAJOR_VERSION_CFG) || \
     (FLS_QSPI_IP_SW_MINOR_VERSION_CFG_C !=  QSPI_IP_SW_MINOR_VERSION_CFG) || \
     (FLS_QSPI_IP_SW_PATCH_VERSION_CFG_C !=  QSPI_IP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Qspi_Ip_PBcfg.c and Qspi_Ip_Cfg.h are different"
#endif


/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/



#define FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"

/* External QSPI flash parameters. */






#define FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @}*/

