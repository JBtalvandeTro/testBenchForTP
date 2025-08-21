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

#ifndef FTFC_FLS_IP_TYPES_H
#define FTFC_FLS_IP_TYPES_H

/**
*   @file Ftfc_Fls_Ip_Types.h
*
*   @addtogroup FTFC_FLS_IP FTFC IP Driver
*   @{
*/

/* implements Ftfc_Fls_Ip_Types.h_Artifact */

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "StandardTypes.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FTFC_FLS_IP_TYPES_VENDOR_ID                    43
#define FTFC_FLS_IP_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define FTFC_FLS_IP_TYPES_AR_RELEASE_MINOR_VERSION     4
#define FTFC_FLS_IP_TYPES_AR_RELEASE_REVISION_VERSION  0
#define FTFC_FLS_IP_TYPES_SW_MAJOR_VERSION             1
#define FTFC_FLS_IP_TYPES_SW_MINOR_VERSION             0
#define FTFC_FLS_IP_TYPES_SW_PATCH_VERSION             1


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StandardTypes.h file are of the same version */
    #if ((FTFC_FLS_IP_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (FTFC_FLS_IP_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)\
        )
        #error "AutoSar Version Numbers of Ftfc_Fls_Ip_Types.h and StandardTypes.h are different"
    #endif
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/**
 * @brief FCCOB commands IDs
 */
#define FLASH_CMD_PROGRAM_PHRASE                (0x07U)
#define FLASH_CMD_ERASE_SECTOR                  (0x09U)

/**
 * @brief  Program allignment
 */
#define FTFC_WRITE_DOUBLE_WORD     8U

/**
* @brief the number of bytes uses to compare (1 byte).
*
*/
#define FLS_SIZE_1BYTE      1U

/**
* @brief the number of bytes uses to compare (2 bytes).
*
*/
#define FLS_SIZE_2BYTE      2U

/**
* @brief the number of bytes uses to compare (4 bytes).
*
*/
#define FLS_SIZE_4BYTE      4U

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief          Return value of Fls handler function.
* @details        Fls_DsiHandler and Fls_MciHandler can return the following value:
*                 - FLS_UNHANDLED    Fls driver is not responsable for this situation
*                 - FLS_HANDLED_SKIP Fls driver is responsable for this exception and want to skip this job
*                 .
*/
typedef uint8 Fls_CompHandlerReturnType;

typedef const uint8 * Fls_InstructionAddressType;
typedef uint32 Fls_DataAddressType;
typedef uint32 Ftfc_Fls_Ip_AddressType;
typedef uint32 Ftfc_Fls_Ip_LengthType;

/**
* @brief          Detailed information on the exception.
* @details        The following information will be checked by the driver:
*                 - if there is a pending read, compare,
*                 - data_pt matches address currently accessed by pending flash read or flash compare job,
*                 - if the exception syndrome register indicates DSI or MCI reason,
*                 .
*
*/
typedef struct
{
    Fls_InstructionAddressType instruction_pt; /**< @brief pointer to the instruction that generated the ECC */
    Fls_DataAddressType        data_pt;        /**< @brief data address that caused the ECC error */
    uint32                     syndrome_u32;   /**< @brief details on the type of exception */
} Fls_ExceptionDetailsType;

/**
    @brief Enumeration of Blocks of memory flash .
*/
typedef enum
{
    FLS_CODE_BLOCK_0  = 0x00U,  /*!< code block number 0 */
    FLS_CODE_BLOCK_1  = 0x01U,  /*!< code block number 1 */
    FLS_CODE_BLOCK_2  = 0x02U,  /*!< code block number 2 */
    FLS_DATA_BLOCK    = 0x04U,  /*!< data block          */
    FLS_BLOCK_INVALID = 0xFFU   /*!< invalid block       */
} Ftfc_Fls_Ip_FlashBlocksNumberType;

/**
* @brief          Fls Start Flash Access Notification Pointer Type
* @details        Pointer type of Ftfc_StartFlashAccessNotifPtrType function
*
*/
typedef void (*Ftfc_StartFlashAccessNotifPtrType)(void);

/**
* @brief          Fls Finished Flash Access Notification Pointer Type
* @details        Pointer type of Ftfc_FinishedFlashAccessNotifPtrType function
*
*/
typedef void (*Ftfc_FinishedFlashAccessNotifPtrType)(void);

/*!
 * @brief Ftfc Configuration Structure
 *
 * Implements : Ftfc_ConfigType_Class
 */
typedef struct
{
    Ftfc_StartFlashAccessNotifPtrType       startFlashAccessNotifPtr;            /*!< Pointer to start flash access callout  */
    Ftfc_FinishedFlashAccessNotifPtrType    finishedFlashAccessNotifPtr;         /*!< Pointer to finish flash access callout */
} Ftfc_ConfigType;

/**
    @brief Enumeration of checking status errors or not.
*/
typedef enum
{
    STATUS_FTFC_FLS_IP_SUCCESS                   = 0x5AA5U,    /*!< Successful job */
    STATUS_FTFC_FLS_IP_BUSY                      = 0xE742U,    /*!< IP is performing an operation */
    STATUS_FTFC_FLS_IP_ERROR                     = 0x27E4U,    /*!< Error - general code */
    STATUS_FTFC_FLS_IP_ERROR_TIMEOUT             = 0x2BD4U,    /*!< Error - exceeded timeout */
    STATUS_FTFC_FLS_IP_ERROR_INPUT_PARAM         = 0x2DB4U,    /*!< Error - wrong input parameter */
    STATUS_FTFC_FLS_IP_ERROR_BLANK_CHECK         = 0x2E74U,    /*!< Error - selected memory area is not erased */
    STATUS_FTFC_FLS_IP_ERROR_PROGRAM_VERIFY      = 0x33CCU,    /*!< Error - selected memory area doesn't contain desired value */
    STATUS_FTFC_FLS_IP_ERROR_USER_TEST_BREAK_SBC = 0x35ACU,    /*!< Error - single bit correction */
    STATUS_FTFC_FLS_IP_ERROR_USER_TEST_BREAK_DBD = 0x366CU,    /*!< Error - double bit detection */
    STATUS_FTFC_FLS_IP_SECTOR_UNPROTECTED        = 0xFA22U,    /*!< Checked sector is unlocked */
    STATUS_FTFC_FLS_IP_SECTOR_PROTECTED          = 0xE8B8U     /*!< Checked sector is locked */
} Ftfc_Fls_Ip_StatusType;

#ifdef __cplusplus
}
#endif

/** @}*/
#endif /* FTFC_FLS_IP_TYPES_H */

