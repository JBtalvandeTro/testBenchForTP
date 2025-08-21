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
*   @file Ftfc_Fls_Ip.h
*
*   @addtogroup FTFC_FLS_IP FTFC IP Driver
*   @{
*/
/*================================================================================================*/

#ifndef FLS_FLASH_H
#define FLS_FLASH_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Ftfc_Fls_Ip_Types.h"
#include "Ftfc_Fls_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FTFC_FLS_IP_VENDOR_ID_H                       43
#define FTFC_FLS_IP_AR_RELEASE_MAJOR_VERSION_H        4
#define FTFC_FLS_IP_AR_RELEASE_MINOR_VERSION_H        4
#define FTFC_FLS_IP_AR_RELEASE_REVISION_VERSION_H     0
#define FTFC_FLS_IP_SW_MAJOR_VERSION_H                1
#define FTFC_FLS_IP_SW_MINOR_VERSION_H                0
#define FTFC_FLS_IP_SW_PATCH_VERSION_H                1

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Ftfc_Fls_Ip_Types header file are of the same vendor */
#if (FTFC_FLS_IP_TYPES_VENDOR_ID != FTFC_FLS_IP_VENDOR_ID_H)
    #error "Ftfc_Fls_Ip.h and Ftfc_Fls_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Ftfc_Fls_Ip_Types header file are of the same Autosar version */
#if ((FTFC_FLS_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != FTFC_FLS_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (FTFC_FLS_IP_TYPES_AR_RELEASE_MINOR_VERSION    != FTFC_FLS_IP_AR_RELEASE_MINOR_VERSION_H) || \
     (FTFC_FLS_IP_TYPES_AR_RELEASE_REVISION_VERSION != FTFC_FLS_IP_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Ftfc_Fls_Ip.h and Ftfc_Fls_Ip_Types.h are different"
#endif
/* Check if current file and Ftfc_Fls_Ip_Types header file are of the same Software version */
#if ((FTFC_FLS_IP_TYPES_SW_MAJOR_VERSION != FTFC_FLS_IP_SW_MAJOR_VERSION_H) || \
     (FTFC_FLS_IP_TYPES_SW_MINOR_VERSION != FTFC_FLS_IP_SW_MINOR_VERSION_H) || \
     (FTFC_FLS_IP_TYPES_SW_PATCH_VERSION != FTFC_FLS_IP_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Ftfc_Fls_Ip.h and Ftfc_Fls_Ip_Types.h are different"
#endif

/* Check if current file and Ftfc_Fls_Ip_Cfg header file are of the same vendor */
#if (FTFC_FLS_IP_VENDOR_ID_CFG != FTFC_FLS_IP_VENDOR_ID_H)
    #error "Ftfc_Fls_Ip.h and Ftfc_Fls_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Ftfc_Fls_Ip_Cfg header file are of the same Autosar version */
#if ((FTFC_FLS_IP_AR_RELEASE_MAJOR_VERSION_CFG    != FTFC_FLS_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (FTFC_FLS_IP_AR_RELEASE_MINOR_VERSION_CFG    != FTFC_FLS_IP_AR_RELEASE_MINOR_VERSION_H) || \
     (FTFC_FLS_IP_AR_RELEASE_REVISION_VERSION_CFG != FTFC_FLS_IP_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Ftfc_Fls_Ip.h and Ftfc_Fls_Ip_Cfg.h are different"
#endif
/* Check if current file and Ftfc_Fls_Ip_Cfg header file are of the same Software version */
#if ((FTFC_FLS_IP_SW_MAJOR_VERSION_CFG != FTFC_FLS_IP_SW_MAJOR_VERSION_H) || \
     (FTFC_FLS_IP_SW_MINOR_VERSION_CFG != FTFC_FLS_IP_SW_MINOR_VERSION_H) || \
     (FTFC_FLS_IP_SW_PATCH_VERSION_CFG != FTFC_FLS_IP_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Ftfc_Fls_Ip.h and Ftfc_Fls_Ip_Cfg.h are different"
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/



/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
#define FLS_START_SEC_VAR_CLEARED_32
#include "Fls_MemMap.h"

#if (STD_ON == FTFC_TIMEOUT_SUPERVISION_ENABLED)
extern uint32 Ftfc_Fls_Ip_u32ElapsedTicks;
extern uint32 Ftfc_Fls_Ip_u32TimeoutTicks;
extern uint32 Ftfc_Fls_Ip_u32CurrentTicks;
#endif

#define FLS_STOP_SEC_VAR_CLEARED_32
#include "Fls_MemMap.h"


#define FLS_START_SEC_CONST_UNSPECIFIED
#include "Fls_MemMap.h"

/* Base address for Flash Memory Module */
extern FTFx_HARDWARE_TYPE * const FTFx_BaseAddress;

#define FLS_STOP_SEC_CONST_UNSPECIFIED
#include "Fls_MemMap.h"


/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"

/**
 * @brief        Initializes the FTCF module
 *
 * @details      This function will initialize ftfc module and clear all error flags.
 *
 * @param[in]    Ftfc_Fls_Ip_pInitConfig   Pointer to the driver configuration structure.
 * @return       Ftfc_Fls_Ip_StatusType
 * @retval       STATUS_FTFC_FLS_IP_SUCCESS            Initialization is success
 * @retval       STATUS_FTFC_FLS_IP_ERROR_TIMEOUT      Errors Timeout because wait for the Done bit long time
 *
 */
Ftfc_Fls_Ip_StatusType Ftfc_Fls_Ip_Init(const Ftfc_ConfigType * Ftfc_Fls_Ip_pInitConfig);

/*!
 * @brief        Abort a program or erase operation
 *
 * @details      This function will abort a program or erase operation in user
 *               mode and clear all PGM, APGM, ERS, AERS, EHV, AEHV bits in MCR,AMCRS registers
 *
 * @return       Ftfc_Fls_Ip_StatusType
 * @retval       STATUS_FTFC_FLS_IP_SUCCESS : The operation is successful.
 * @retval       STATUS_FTFC_FLS_IP_ERROR_TIMEOUT: the operation error because wait for the Done bit long time
 *
 */
Ftfc_Fls_Ip_StatusType Ftfc_Fls_Ip_Abort(void);

/**
 * @brief        This function fills data to pDestAddressPtr
 *
 * @details      This function fills data to pDestAddressPtr with data from the specified address
 *
 * @param[in]    u32SrcAddress       The start address of the area to be read.
 * @param[in]    pDestAddressPtr     Pointer to the destination of the read.
 * @param[in]    u32Length           Read size
 *
 * @return       Ftfc_Fls_Ip_StatusType
 * @retval       STATUS_FTFC_FLS_IP_SUCCESS             Read performed successfully.
 * @retval       STATUS_FTFC_FLS_IP_ERROR_INPUT_PARAM   Input parameters are invalid.
 * @retval       STATUS_FTFC_FLS_IP_ERROR               There was an error while reading.
 *
 * @pre          The module has to be initialized and not busy.
 *
 */
Ftfc_Fls_Ip_StatusType Ftfc_Fls_Ip_Read(Ftfc_Fls_Ip_AddressType u32SrcAddress,
                                        uint8 *pDestAddressPtr,
                                        Ftfc_Fls_Ip_LengthType u32Length
                                       );
/**
 * @brief        Checks that there is the desired data at the specified address
 *
 * @details      Checks that there is the desired data at the specified address.
 *               If the compare is intented to be a blank check, the pSourceAddressPtr should be NULL.
 *
 * @param[in]    u32SrcAddress        The start address of the area to be checked.
 * @param[in]    pCompareAddressPtr   Pointer to the data expected to be read.
 * @param[in]    u32Length            Check size
 *
 * @return       Ftfc_Fls_Ip_StatusType
 * @retval       STATUS_FTFC_FLS_IP_SUCCESS               Read performed successfully.
 * @retval       STATUS_FTFC_FLS_IP_ERROR_INPUT_PARAM     Input parameters are invalid.
 * @retval       STATUS_FTFC_FLS_IP_ERROR                 There was an error while reading.
 * @retval       STATUS_FTFC_FLS_IP_ERROR_PROGRAM_VERIFY  The expected data was not found completely at the specified address
 *
 * @pre          The module has to be initialized and not busy.
 *
 */
Ftfc_Fls_Ip_StatusType Ftfc_Fls_Ip_Compare(Ftfc_Fls_Ip_AddressType u32SrcAddress,
                                           const uint8 * pCompareAddressPtr,
                                           Ftfc_Fls_Ip_LengthType u32Length
                                          );

/**
 * @brief         Get block number from target address
 *
 * @details       Get block number from target address
 *
 * @param[in]    u32TargetAddress   target address
 *
 * @return       Ftfc_Fls_Ip_GetBlockNumberFromAddress
 * @retval       The block number which contains the target address.
 *
 */
Ftfc_Fls_Ip_FlashBlocksNumberType Ftfc_Fls_Ip_GetBlockNumberFromAddress(uint32 u32TargetAddress);

/**
 * @brief         Accepts and erases a selected program flash or data flash sector if possible
 *
 * @details       Accepts an erase job over one of the sectors if possible.
 *                Starts the high voltage erase and then exits. The status of the hardware erase must
 *                be verified by calling asynchronously the Ftfc_Fls_Ip_SectorEraseStatus function.
 *                 The Ftfc_Fls_Ip_SectorErase function shall cover all the available sectors.
 *
 * @param[in]    u32SectorStartAddress   The start address of the sector to be erased.
 *
 * @return       Ftfc_Fls_Ip_StatusType
 * @retval       STATUS_FTFC_FLS_IP_SUCCESS             Hardware erase started successfully
 * @retval       STATUS_FTFC_FLS_IP_ERROR_INPUT_PARAM   The selected sector is out of bound
 * @retval       STATUS_FTFC_FLS_IP_ERROR               There is another job configured or in progress or
 *                                                 @p The sector is locked by another core or couldn't be unlocked.
 * @retval       STATUS_FTFC_FLS_IP_ERROR_TIMEOUT       The erase operation exceeded the timeout - Status value available only if the timeout feature is enabled
 *
 * @pre          The module has to be initialized.
 *
 */
Ftfc_Fls_Ip_StatusType Ftfc_Fls_Ip_SectorErase(uint32 u32SectorStartAddress);

/**
 * @brief         Checks the status of the hardware erase started by the Ftfc_Fls_Ip_SectorErase function.
 *
 * @details       Checks the status of the hardware erase started by the Ftfc_Fls_Ip_SectorErase function.
 *
 * @return       Ftfc_Fls_Ip_StatusType
 * @retval       STATUS_FTFC_FLS_IP_SUCCESS             Erase performed successfully
 * @retval       STATUS_Ftfc_Fls_Ip_BUSY                Hardware erase is still in progress
 * @retval       STATUS_FTFC_FLS_IP_ERROR               There was an error during the hardware erase.
 * @retval       STATUS_FTFC_FLS_IP_ERROR_TIMEOUT       The erase operation exceeded the timeout - Status value available only if the timeout feature is enabled.
 * @retval       STATUS_FTFC_FLS_IP_ERROR_BLANK_CHECK   The sector was not erased correctly - Status value available only if the blank check feature is enabled
 *
 * @pre          The module has to be initialized.
 *
 */
Ftfc_Fls_Ip_StatusType Ftfc_Fls_Ip_SectorEraseStatus(void);

/**
 * @brief         Writes data into the memory array using the main interface. Initiates the hardware write and then exits.
 *
 * @details       Writes data into the memory array using the main interface. Initiates the hardware write and then exits.
 *                the status of the hardware erase must be verified by calling asynchronously the Ftfc_Fls_Ip_WriteStatus function.
 *
 * @param[in]    u32DestAddress      The start address of the write, must be aligned with 8 bytes.
 * @param[in]    pSourceAddressPtr   Source program buffer address.
 * @param[in]    u32Length           Size in bytes of the flash region to be programed, must be aligned with 8 bytes and the maximum value is 128 bytes.
 *
 * @return       Ftfc_Fls_Ip_StatusType
 * @retval       STATUS_FTFC_FLS_IP_SUCCESS             Program performed successfully
 * @retval       STATUS_FTFC_FLS_IP_ERROR_INPUT_PARAM   The input parameters are invaid.
 * @retval       STATUS_FTFC_FLS_IP_ERROR               There is another job configured or in progress or
 *                                                 @p The sector is locked by another core or couldn't be unlocked.
 * @retval       STATUS_FTFC_FLS_IP_ERROR_TIMEOUT       The erase operation exceeded the timeout - Status value available only if the timeout feature is enabled
 *
 * @pre          The module has to be initialized.
 *
 */
Ftfc_Fls_Ip_StatusType Ftfc_Fls_Ip_Write(uint32 u32DestAddress,
                                         const uint8 *pSourceAddressPtr,
                                         uint32 u32Length
                                        );

/**
 * @brief         Checks the status of the hardware program started by the FTFC_Ip_Write function.
 *
 * @details       Checks the status of the hardware program started by the FTFC_Ip_Write function.
 *
 * @return       Ftfc_Fls_Ip_StatusType
 * @retval       STATUS_FTFC_FLS_IP_SUCCESS                Program performed successfully
 * @retval       STATUS_Ftfc_Fls_Ip_BUSY                   Hardware program is still in progress
 * @retval       STATUS_FTFC_FLS_IP_ERROR                  There was an error during the hardware program.
 * @retval       STATUS_FTFC_FLS_IP_ERROR_TIMEOUT          The program operation exceeded the timeout - Status value available only if the timeout feature is enabled.
 * @retval       STATUS_FTFC_FLS_IP_ERROR_PROGRAM_VERIFY   The data was not written corectly into the memory - Status available only of program verify feature is enabled
 *
 * @pre          The module has to be initialized.
 *
 */
Ftfc_Fls_Ip_StatusType Ftfc_Fls_Ip_WriteStatus(void);


#if ( (FTFC_ECC_CHECK == STD_ON) || (FTFC_ECC_CHECK_BY_AUTOSAR_OS == STD_ON) )
    #if ( FTFC_ECC_SYNDROME_AND_DATA_ADDRESS_CHECK == STD_ON )
    Fls_CompHandlerReturnType Ftfc_Fls_Ip_DsiHandler(const Fls_ExceptionDetailsType  *pExceptionDetailsPtr);
    #else
    Fls_CompHandlerReturnType Ftfc_Fls_Ip_DsiHandler(void);
    #endif
#endif /* ( (FTFC_ECC_CHECK == STD_ON) || (FTFC_ECC_CHECK_BY_AUTOSAR_OS == STD_ON) ) */


void Ftfc_Fls_Ip_SetAsyncMode(const boolean Async);


#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FTFC_FLS_IP_H */
