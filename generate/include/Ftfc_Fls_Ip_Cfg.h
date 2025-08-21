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

#ifndef FTFC_FLS_IP_CFG_H
#define FTFC_FLS_IP_CFG_H

/**
*   @file Ftfc_Fls_Ip_Cfg.h
*
*   @addtogroup FLS
*   @{
*/

/* implements Ftfc_Fls_Ip_Cfg.h_Artifact */

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "OsIf.h"

#include "S32K148_FTFC.h"
#include "S32K148_MSCM.h"
#include "S32K148_SIM.h"

#include "Devassert.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FTFC_FLS_IP_VENDOR_ID_CFG                          43
#define FTFC_FLS_IP_AR_RELEASE_MAJOR_VERSION_CFG           4
#define FTFC_FLS_IP_AR_RELEASE_MINOR_VERSION_CFG           4
#define FTFC_FLS_IP_AR_RELEASE_REVISION_VERSION_CFG        0
#define FTFC_FLS_IP_SW_MAJOR_VERSION_CFG                   1
#define FTFC_FLS_IP_SW_MINOR_VERSION_CFG                   0
#define FTFC_FLS_IP_SW_PATCH_VERSION_CFG                   1


/*==================================================================================================
*                                 FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and OsIf.h header file are of the same Autosar version */
    #if ((FTFC_FLS_IP_AR_RELEASE_MAJOR_VERSION_CFG != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (FTFC_FLS_IP_AR_RELEASE_MINOR_VERSION_CFG != OSIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Ftfc_Fls_Ip_Cfg.h and OsIf.h are different"
    #endif
    /* Check if current file and Devassert.h header file are of the same Autosar version */
    #if ((FTFC_FLS_IP_AR_RELEASE_MAJOR_VERSION_CFG != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
         (FTFC_FLS_IP_AR_RELEASE_MINOR_VERSION_CFG != DEVASSERT_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Ftfc_Fls_Ip_Cfg.h and Devassert.h are different"
    #endif
#endif


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
#define FTFx_HARDWARE_TYPE                   FTFC_Type
#define FTFx_HARDWARE_UNIT                   IP_FTFC

#define FTFx_FPROT_COUNT                     FTFC_FPROT_COUNT
#define FTFx_FSTAT_CCIF_MASK                 FTFC_FSTAT_CCIF_MASK
#define FTFx_FSTAT_ACCERR_MASK               FTFC_FSTAT_ACCERR_MASK
#define FTFx_FSTAT_FPVIOL_MASK               FTFC_FSTAT_FPVIOL_MASK
#define FTFx_FSTAT_MGSTAT0_MASK              FTFC_FSTAT_MGSTAT0_MASK
#define FTFx_FSTAT_RDCOLERR_MASK             FTFC_FSTAT_RDCOLERR_MASK
#define FTFx_FERSTAT_DFDIF_MASK              FTFC_FERSTAT_DFDIF_MASK
#define FTFx_FCNFG_ERSSUSP_MASK              FTFC_FCNFG_ERSSUSP_MASK

#define FTFx_FSTAT_MGSTAT3_MASK              (0x00U)
#define FTFx_FSTAT_MGSTAT2_MASK              (0x00U)
#define FTFx_FSTAT_MGSTAT1_MASK              (0x00U)

/* Mask of FTFx IP-related error flags */
#define FTFx_ERR_FLAGS_MASK                  (FTFx_FSTAT_RDCOLERR_MASK | \
                                              FTFx_FSTAT_ACCERR_MASK   | \
                                              FTFx_FSTAT_FPVIOL_MASK   | \
                                              FTFx_FSTAT_MGSTAT3_MASK  | \
                                              FTFx_FSTAT_MGSTAT2_MASK  | \
                                              FTFx_FSTAT_MGSTAT1_MASK  | \
                                              FTFx_FSTAT_MGSTAT0_MASK)

#define FTFC_FLS_IP_INVALID_PREBUF_FROM_RAM  (STD_ON)

#define FTFC_FLS_IP_SYNCRONIZE_CACHE         (STD_ON)

#if (STD_ON == FTFC_FLS_IP_SYNCRONIZE_CACHE)
    #define FTFC_FLS_D_FLASH_CACHEABLE       (STD_OFF)
#endif

#define FTFC_IP_ENABLE_USER_MODE_SUPPORT     (STD_OFF)

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == FTFC_IP_ENABLE_USER_MODE_SUPPORT)
        #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Fls in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
    #endif
#endif

#define FTFC_TIMEOUT_SUPERVISION_ENABLED     (STD_ON)

#define FTFC_ERASE_VERIFICATION_ENABLED      (STD_ON)

#define FTFC_PROGRAM_VERIFICATION_ENABLED    (STD_ON)

#define FTFC_ERASED_VALUE                    (0xFFFFFFFFU)

#define FTFC_ECC_CHECK                       (STD_OFF)

#define FTFC_ECC_CHECK_BY_AUTOSAR_OS         (STD_OFF)

#if ( (FTFC_ECC_CHECK == STD_ON) || (FTFC_ECC_CHECK_BY_AUTOSAR_OS == STD_ON) )

/* Support for all the derivatives excepting the M0++ core missing some registers related to read syndrome(CFSR) and data address(BFAR) */
#define FTFC_ECC_SYNDROME_AND_DATA_ADDRESS_CHECK    (STD_ON)

#if (FTFC_ECC_SYNDROME_AND_DATA_ADDRESS_CHECK == STD_ON)
    #define FTFC_DSI_EXC_SYNDROME                   (0x00008200U)
#endif

/*Return value for Fls_DsiHandler and Fls_MciHandler*/
/**
*   Return value for Fls_DsiHandler and Fls_MciHandler.
*   module does not feel responsible (e.g. address does not belong to its current job,
*   there is no current pending read/compare job, the syndrome is different).
*
*/
#define FLS_UNHANDLED       (0U)
/**
*   Return value for Fls_DsiHandler and Fls_MciHandler.
*   module feels responsible, but wants to repeat the  causing instruction.
*   Maybe: it still uses information in MCM or ECSM module, but they are outdated
*   (e.g. due to an erroneous DMA transfer in the meantime)
*
*/
#define FLS_HANDLED_RETRY   (1U)
/**
*   Return value for Fls_DsiHandler and Fls_MciHandler.
*   module feels responsible, the current job is marked as failed,
*   processing may continue, skipping the causing instruction.
*
*/
#define FLS_HANDLED_SKIP    (2U)
/**
*   Return value for Fls_DsiHandler and Fls_MciHandler.
*   module  feels responsible, but the only reaction is to stop the system
*   (e.g.: try to shut-down in a quite safe way)
*
*/
#define FLS_HANDLED_STOP    (3U)
#endif  /* #if ( (FTFC_ECC_CHECK == STD_ON) || (FTFC_ECC_CHECK_BY_AUTOSAR_OS == STD_ON) ) */

/*! Enable development error check */
#define DEV_ASSERT_FTFC(x)                   DevAssert((x))

#define FTFC_TIMEOUT_TYPE                    (OSIF_COUNTER_DUMMY)

#if (STD_ON == FTFC_TIMEOUT_SUPERVISION_ENABLED)

#define FTFC_ASYNC_WRITE_TIMEOUT             (2147483647U)

#define FTFC_ASYNC_ERASE_TIMEOUT             (2147483647U)

#define FTFC_SYNC_WRITE_TIMEOUT              (2147483647U)

#define FTFC_SYNC_ERASE_TIMEOUT              (2147483647U)

#define FTFC_ABORT_TIMEOUT                   (32767U)

#endif  /*(STD_ON == FTFC_TIMEOUT_SUPERVISION_ENABLED)*/

/* Flash memory characteristics */
#define FTFC_P_FLASH_BASE_ADDR               (0x00000000UL)
#define FTFC_P_FLASH_SIZE                    (0x180000UL)
#define FTFC_P_FLASH_SECTOR_SIZE             (0x1000UL)

#define FTFC_D_FLASH_BASE_ADDR               (0x10000000UL)
#define FTFC_D_FLASH_SIZE                    (0x80000UL)
#define FTFC_D_FLASH_SECTOR_SIZE             (0x1000UL)

/* Valid P_FLASH address */
#define FTFC_ADDRESS_VALID_P_FLASH(addr)     ( (addr) < (FTFC_P_FLASH_BASE_ADDR + FTFC_P_FLASH_SIZE) )

/* Valid D_FLASH address */
#define FTFC_ADDRESS_VALID_D_FLASH(addr)     ( (FTFC_D_FLASH_BASE_ADDR <= (addr)) && ((addr) < (FTFC_D_FLASH_BASE_ADDR + FTFC_D_FLASH_SIZE)) )

/* Valid P_FLASH or D_FLASH address */
#define FTFC_ADDRESS_VALID(addr)             ( FTFC_ADDRESS_VALID_P_FLASH(addr) || FTFC_ADDRESS_VALID_D_FLASH(addr) )

/* Check if the address is sector alignment or not */
#define FTFC_SECTOR_ALIGNED(addr)            ( ((addr) & (FTFC_P_FLASH_SECTOR_SIZE - 1UL)) == 0UL )


/* FlexNVM Partition Code Ratios (DFLASH_EEPROM sizes in KB) - used for Program Partition Command */
#define FLASH_FLEXNVM_DFLASH_EEPROM_DEFAULT     (0x0FU)   /* Bit value:1111   Data flash (KByte):default*/
#if (0x8000UL == FTFC_D_FLASH_SIZE)
#define FLASH_FLEXNVM_DFLASH_EEPROM_32_0_V1     (0x00U)   /* Bit value:0000   Data flash (KByte):32 EEPROM backup (KByte):0 */
#define FLASH_FLEXNVM_DFLASH_EEPROM_0_32_V1     (0x03U)   /* Bit value:0011   Data flash (KByte):0  EEPROM backup (KByte):32 */
#define FLASH_FLEXNVM_DFLASH_EEPROM_0_32_V2     (0x08U)   /* Bit value:1000   Data flash (KByte):0  EEPROM backup (KByte):32 */
#define FLASH_FLEXNVM_DFLASH_EEPROM_8_24_V1     (0x09U)   /* Bit value:1001   Data flash (KByte):8  EEPROM backup (KByte):24 */
#define FLASH_FLEXNVM_DFLASH_EEPROM_32_0_V2     (0x0BU)   /* Bit value:1011   Data flash (KByte):32 EEPROM backup (KByte):0 */

#elif (0x10000UL == FTFC_D_FLASH_SIZE)
#define FLASH_FLEXNVM_DFLASH_EEPROM_64_0_V1     (0x00U)   /* Bit value:0000   Data flash (KByte):64 EEPROM backup (KByte):0 */
#define FLASH_FLEXNVM_DFLASH_EEPROM_32_32_V1    (0x03U)   /* Bit value:0011   Data flash (KByte):64 EEPROM backup (KByte):0 */
#define FLASH_FLEXNVM_DFLASH_EEPROM_0_64_V1     (0x04U)   /* Bit value:0100   Data flash (KByte):64 EEPROM backup (KByte):0 */
#define FLASH_FLEXNVM_DFLASH_EEPROM_0_64_V2     (0x08U)   /* Bit value:1000   Data flash (KByte):64 EEPROM backup (KByte):0 */
#define FLASH_FLEXNVM_DFLASH_EEPROM_16_48_V1    (0x0AU)   /* Bit value:1010   Data flash (KByte):64 EEPROM backup (KByte):0 */
#define FLASH_FLEXNVM_DFLASH_EEPROM_32_32_V2    (0x0BU)   /* Bit value:1011   Data flash (KByte):64 EEPROM backup (KByte):0 */
#define FLASH_FLEXNVM_DFLASH_EEPROM_64_0_V2     (0x0CU)   /* Bit value:1100   Data flash (KByte):64 EEPROM backup (KByte):0 */

#elif (0x80000UL == FTFC_D_FLASH_SIZE)
#define FLASH_FLEXNVM_DFLASH_EEPROM_512_0_V1    (0x00U)   /* Bit value:0000   Data flash (KByte):64 EEPROM backup (KByte):0 */
#define FLASH_FLEXNVM_DFLASH_EEPROM_448_64_V1   (0x04U)   /* Bit value:0100   Data flash (KByte):64 EEPROM backup (KByte):0 */
#define FLASH_FLEXNVM_DFLASH_EEPROM_512_0_V2    (0x0FU)   /* Bit value:1111   Data flash (KByte):64 EEPROM backup (KByte):0 */
#endif

/* Code block size (flash read partition size) */
#define FLS_P_BLOCK_SIZE                     (0x80000U)


/*==================================================================================================
                                 GLOBAL CONSTANT DECLARATIONS
==================================================================================================*/
#define FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"

extern const Ftfc_ConfigType FlsConfigSet_Init_InitCfg;

#define FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FTFC_FLS_IP_CFG_H */

