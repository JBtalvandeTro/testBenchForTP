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
*   @file Fls_Init_PBcfg.c
*
*   @addtogroup FLS
*   @{
*/

/* implements Fls_PBcfg.c_Artifact */

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Fls.h"
#include "Qspi_Ip_Features.h"
#include "Qspi_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_VENDOR_ID_CFG_C                      43
#define FLS_AR_RELEASE_MAJOR_VERSION_CFG_C       4
#define FLS_AR_RELEASE_MINOR_VERSION_CFG_C       4
#define FLS_AR_RELEASE_REVISION_VERSION_CFG_C    0
#define FLS_SW_MAJOR_VERSION_CFG_C               1
#define FLS_SW_MINOR_VERSION_CFG_C               0
#define FLS_SW_PATCH_VERSION_CFG_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fls header file are of the same vendor */
#if (FLS_VENDOR_ID_CFG_C != FLS_VENDOR_ID)
    #error "Fls_PBcfg.c and Fls.h have different vendor ids"
#endif
/* Check if current file and Fls header file are of the same Autosar version */
#if ((FLS_AR_RELEASE_MAJOR_VERSION_CFG_C    != FLS_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_AR_RELEASE_MINOR_VERSION_CFG_C    != FLS_AR_RELEASE_MINOR_VERSION) || \
     (FLS_AR_RELEASE_REVISION_VERSION_CFG_C != FLS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Fls_PBcfg.c and Fls.h are different"
#endif
/* Check if current file and Fls header file are of the same Software version */
#if ((FLS_SW_MAJOR_VERSION_CFG_C != FLS_SW_MAJOR_VERSION) || \
     (FLS_SW_MINOR_VERSION_CFG_C != FLS_SW_MINOR_VERSION) || \
     (FLS_SW_PATCH_VERSION_CFG_C != FLS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls_PBcfg.c and Fls.h are different"
#endif

/* Check if current file and Qspi_Ip_Features header file are of the same vendor */
#if (FLS_VENDOR_ID_CFG_C != QSPI_IP_FEATURES_VENDOR_ID_CFG)
    #error "Fls_PBcfg.c and Qspi_Ip_Features.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_Features header file are of the same Autosar version */
#if ((FLS_AR_RELEASE_MAJOR_VERSION_CFG_C    != QSPI_IP_FEATURES_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (FLS_AR_RELEASE_MINOR_VERSION_CFG_C    != QSPI_IP_FEATURES_AR_RELEASE_MINOR_VERSION_CFG) || \
     (FLS_AR_RELEASE_REVISION_VERSION_CFG_C != QSPI_IP_FEATURES_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Fls_PBcfg.c and Qspi_Ip_Features.h are different"
#endif
/* Check if current file and Qspi_Ip_Features header file are of the same Software version */
#if ((FLS_SW_MAJOR_VERSION_CFG_C != QSPI_IP_FEATURES_SW_MAJOR_VERSION_CFG) || \
     (FLS_SW_MINOR_VERSION_CFG_C != QSPI_IP_FEATURES_SW_MINOR_VERSION_CFG) || \
     (FLS_SW_PATCH_VERSION_CFG_C != QSPI_IP_FEATURES_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Fls_PBcfg.c and Qspi_Ip_Features.h are different"
#endif

/* Check if current file and Qspi_Ip_Cfg header file are of the same vendor */
#if (FLS_VENDOR_ID_CFG_C != QSPI_IP_VENDOR_ID_CFG)
    #error "Fls_PBcfg.c and Qspi_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_Cfg header file are of the same Autosar version */
#if ((FLS_AR_RELEASE_MAJOR_VERSION_CFG_C    != QSPI_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (FLS_AR_RELEASE_MINOR_VERSION_CFG_C    != QSPI_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (FLS_AR_RELEASE_REVISION_VERSION_CFG_C != QSPI_IP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Fls_PBcfg.c and Qspi_Ip_Cfg.h are different"
#endif
/* Check if current file and Qspi_Ip_Cfg header file are of the same Software version */
#if ((FLS_SW_MAJOR_VERSION_CFG_C != QSPI_IP_SW_MAJOR_VERSION_CFG) || \
     (FLS_SW_MINOR_VERSION_CFG_C != QSPI_IP_SW_MINOR_VERSION_CFG) || \
     (FLS_SW_PATCH_VERSION_CFG_C != QSPI_IP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Fls_PBcfg.c and Qspi_Ip_Cfg.h are different"
#endif

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"

/* Declaration of Fls Access Code Pointer (_ERASE_FUNC_ADDRESS_)*/
extern void _ERASE_FUNC_ADDRESS_(void);


/* Declaration of Fls Access Code Pointer (_WRITE_FUNC_ADDRESS_)*/
extern void _WRITE_FUNC_ADDRESS_(void);

#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CONFIG_DATA_8
#include "Fls_MemMap.h"

/* aFlsSectorFlags */
static const uint8 FlsConfigSet_Init_aFlsSectorFlags[3U] =
{
    0U,  /* FlsSector_MainParams1 */
    0U,  /* FlsSector_MainParams2 */
    0U   /* FlsSector_BackupParams */
};

#define FLS_STOP_SEC_CONFIG_DATA_8
#include "Fls_MemMap.h"



#define FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"

/* aFlsSectorEndAddr */
static const Fls_AddressType FlsConfigSet_Init_aFlsSectorEndAddr[3U] =
{
    (Fls_AddressType)4095U,  /* FlsSector_MainParams1 */
    (Fls_AddressType)8191U,  /* FlsSector_MainParams2 */
    (Fls_AddressType)12287U   /* FlsSector_BackupParams */
};

/* paSectorSize */
static const Fls_LengthType FlsConfigSet_Init_aFlsSectorSize[3U] =
{
    (Fls_LengthType)4096U,  /* FlsSector_MainParams1 */
    (Fls_LengthType)4096U,  /* FlsSector_MainParams2 */
    (Fls_LengthType)4096U   /* FlsSector_BackupParams */
};

/* paSectorPageSize */
static const Fls_LengthType FlsConfigSet_Init_aFlsSectorPageSize[3U] =
{
    (Fls_LengthType)8U,  /* FlsSector_MainParams1 */
    (Fls_LengthType)8U,  /* FlsSector_MainParams2 */
    (Fls_LengthType)8U   /* FlsSector_BackupParams */
};

/* Info structure (reg prot, ecc trigger, etc) for each internal flash sector. */
static const Fls_Flash_InternalSectorInfoType FlsSector_MainParams1_FlsConfigSet_Init_sInternalSectorInfo =
{
    (FLS_PROGRAM_FLASH_BASE_ADDR + 0x100000UL),                      /* pSectorStartAddressPtr */
    384U                                                             /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_MainParams2_FlsConfigSet_Init_sInternalSectorInfo =
{
    (FLS_PROGRAM_FLASH_BASE_ADDR + 0x101000UL),                      /* pSectorStartAddressPtr */
    385U                                                             /* Sector location to calculate cfgCRC */
};

static const Fls_Flash_InternalSectorInfoType FlsSector_BackupParams_FlsConfigSet_Init_sInternalSectorInfo =
{
    (FLS_DATA_FLASH_BASE_ADDR + 0x07F000UL),                         /* pSectorStartAddressPtr */
    127U                                                             /* Sector location to calculate cfgCRC */
};


/* FLASH physical sectorization description */
static const Fls_Flash_InternalSectorInfoType * const FlsConfigSet_Init_aSectorList[3U] =
{
    &FlsSector_MainParams1_FlsConfigSet_Init_sInternalSectorInfo,  /* FLS_CODE_ARRAY_0_BLOCK_2_S256 */
    &FlsSector_MainParams2_FlsConfigSet_Init_sInternalSectorInfo,  /* FLS_CODE_ARRAY_0_BLOCK_2_S257 */
    &FlsSector_BackupParams_FlsConfigSet_Init_sInternalSectorInfo   /* FLS_DATA_ARRAY_0_BLOCK_3_S127 */
};

/* paHwCh */
static const Fls_HwChType FlsConfigSet_Init_paHwCh[3U] =
{
    FLS_CH_INTERN,  /* FlsSector_MainParams1 */
    FLS_CH_INTERN,  /* FlsSector_MainParams2 */
    FLS_CH_INTERN   /* FlsSector_BackupParams */
};

/* paSectorHwAddress */
static const Fls_AddressType FlsConfigSet_Init_paSectorHwAddress[3U] =
{
    (Fls_AddressType)0U,  /* FlsSector_MainParams1 */
    (Fls_AddressType)0U,  /* FlsSector_MainParams2 */
    (Fls_AddressType)0U   /* FlsSector_BackupParams */
};



/**
* @brief        Structure used to set function pointers notification, working mode
*/
/* Fls module initialization data (FlsConfigSet)*/
const Fls_ConfigType Fls_Config_Init =
{
    (Fls_AcErasePtrType)&_ERASE_FUNC_ADDRESS_,                       /* FlsAcErase */
    (Fls_AcWritePtrType)&_WRITE_FUNC_ADDRESS_,                       /* FlsAcWrite */
    NULL_PTR,                                                        /* FlsACCallback */
    NULL_PTR,                                                        /* FlsJobEndNotification */
    NULL_PTR,                                                        /* FlsJobErrorNotification */
    NULL_PTR,                                                        /* FlsReadFunctionCallout */
    MEMIF_MODE_SLOW,                                                 /* FlsDefaultMode */
    1024U,                                                           /* FlsMaxReadFastMode */
    512U,                                                            /* FlsMaxReadNormalMode */
    512U,                                                            /* FlsMaxWriteFastMode */
    512U,                                                            /* FlsMaxWriteNormalMode */
    3U,                                                              /* FlsSectorCount */
    &FlsConfigSet_Init_aFlsSectorEndAddr,                            /* (*paSectorEndAddr)[] */
    &FlsConfigSet_Init_aFlsSectorSize,                               /* (*paSectorSize)[] */
    &FlsConfigSet_Init_aSectorList,                                  /* (*pSectorList)[] */
    &FlsConfigSet_Init_aFlsSectorFlags,                              /* (*paSectorFlags)[] */
    &FlsConfigSet_Init_aFlsSectorPageSize,                           /* (*paSectorPageSize)[] */
    &FlsConfigSet_Init_paHwCh,                                       /* (*paHwCh)[] */
    &FlsConfigSet_Init_paSectorHwAddress,                            /* (*paSectorHwAddress)[] */
    NULL_PTR,                                                        /* FlsQspiConfig */
    &FlsConfigSet_Init_InitCfg,                                      /* FlsInternalConfig */
    58497U                                                           /* configCrc */
};


#define FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @}*/

