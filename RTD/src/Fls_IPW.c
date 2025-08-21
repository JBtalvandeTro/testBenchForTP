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
/*==================================================================================================
==================================================================================================*/

/**
*   @file Fls_IPW.c
*
*   @addtogroup FLS
*   @{
*/

/* implements Fls_IPW.c_Artifact */

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Fls.h"
#include "Fls_IPW.h"
#include "Det.h"
#if (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED)
#include "Ftfc_Fls_Ip.h"
#include "Ftfc_Fls_Ip_Ac.h"
#endif /* (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED) */
#if (STD_ON == FLS_QSPI_SECTORS_CONFIGURED)
#include "Qspi_Ip.h"
#endif /* (STD_ON == FLS_QSPI_SECTORS_CONFIGURED) */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_IPW_VENDOR_ID_C                           43
#define FLS_IPW_AR_RELEASE_MAJOR_VERSION_C            4
#define FLS_IPW_AR_RELEASE_MINOR_VERSION_C            4
#define FLS_IPW_AR_RELEASE_REVISION_VERSION_C         0
#define FLS_IPW_SW_MAJOR_VERSION_C                    1
#define FLS_IPW_SW_MINOR_VERSION_C                    0
#define FLS_IPW_SW_PATCH_VERSION_C                    1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fls header file are of the same vendor */
#if (FLS_IPW_VENDOR_ID_C != FLS_VENDOR_ID)
    #error "Fls_IPW.c and Fls.h have different vendor ids"
#endif
/* Check if current file and Fls header file are of the same Autosar version */
#if ((FLS_IPW_AR_RELEASE_MAJOR_VERSION_C    != FLS_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_IPW_AR_RELEASE_MINOR_VERSION_C    != FLS_AR_RELEASE_MINOR_VERSION) || \
     (FLS_IPW_AR_RELEASE_REVISION_VERSION_C != FLS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Fls_IPW.c and Fls.h are different"
#endif
/* Check if current file and Fls header file are of the same Software version */
#if ((FLS_IPW_SW_MAJOR_VERSION_C != FLS_SW_MAJOR_VERSION) || \
     (FLS_IPW_SW_MINOR_VERSION_C != FLS_SW_MINOR_VERSION) || \
     (FLS_IPW_SW_PATCH_VERSION_C != FLS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls_IPW.c and Fls.h are different"
#endif

/* Check if current file and Fls_IPW.h header file have the same Vendor ID */
#if (FLS_IPW_VENDOR_ID_C != FLS_IPW_VENDOR_ID_H)
    #error "Fls_IPW.c and Fls_IPW.h have different vendor ids"
#endif
/* Check if current file and Fls_IPW.h header file are of the same Autosar version */
#if ((FLS_IPW_AR_RELEASE_MAJOR_VERSION_C    != FLS_IPW_AR_RELEASE_MAJOR_VERSION_H) || \
     (FLS_IPW_AR_RELEASE_MINOR_VERSION_C    != FLS_IPW_AR_RELEASE_MINOR_VERSION_H) || \
     (FLS_IPW_AR_RELEASE_REVISION_VERSION_C != FLS_IPW_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Fls_IPW.c and Fls_IPW.h are different"
#endif
/* Check if current file and Fls_IPW.h header file are of the same Software version */
#if ((FLS_IPW_SW_MAJOR_VERSION_C != FLS_IPW_SW_MAJOR_VERSION_H) || \
     (FLS_IPW_SW_MINOR_VERSION_C != FLS_IPW_SW_MINOR_VERSION_H) || \
     (FLS_IPW_SW_PATCH_VERSION_C != FLS_IPW_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Fls_IPW.c and Fls_IPW.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Det header file are of the same Autosar version */
    #if ((FLS_IPW_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_IPW_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Fls_IPW.c and Det.h are different"
    #endif
#endif

#if (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED)
    /* Check if current file and Ftfc_Fls_Ip header file are of the same vendor */
    #if (FLS_IPW_VENDOR_ID_C != FTFC_FLS_IP_VENDOR_ID_H)
        #error "Fls_IPW.c and Ftfc_Fls_Ip.h have different vendor ids"
    #endif
    /* Check if current file and Ftfc_Fls_Ip header file are of the same Autosar version */
    #if ((FLS_IPW_AR_RELEASE_MAJOR_VERSION_C    != FTFC_FLS_IP_AR_RELEASE_MAJOR_VERSION_H) || \
            (FLS_IPW_AR_RELEASE_MINOR_VERSION_C    != FTFC_FLS_IP_AR_RELEASE_MINOR_VERSION_H) || \
            (FLS_IPW_AR_RELEASE_REVISION_VERSION_C != FTFC_FLS_IP_AR_RELEASE_REVISION_VERSION_H) \
        )
        #error "AutoSar Version Numbers of Fls_IPW.c and Ftfc_Fls_Ip.h are different"
    #endif
    /* Check if current file and Ftfc_Fls_Ip header file are of the same Software version */
    #if ((FLS_IPW_SW_MAJOR_VERSION_C != FTFC_FLS_IP_SW_MAJOR_VERSION_H) || \
         (FLS_IPW_SW_MINOR_VERSION_C != FTFC_FLS_IP_SW_MINOR_VERSION_H) || \
         (FLS_IPW_SW_PATCH_VERSION_C != FTFC_FLS_IP_SW_PATCH_VERSION_H) \
        )
        #error "Software Version Numbers of Fls_IPW.c and Ftfc_Fls_Ip.h are different"
    #endif

    /* Check if current file and Ftfc_Fls_Ip_Ac header file are of the same vendor */
    #if (FLS_IPW_VENDOR_ID_C != FTFC_FLS_IP_AC_VENDOR_ID_H)
        #error "Fls_IPW.c and Ftfc_Fls_Ip_Ac.h have different vendor ids"
    #endif
    /* Check if current file and Ftfc_Fls_Ip_Ac header file are of the same Autosar version */
    #if ((FLS_IPW_AR_RELEASE_MAJOR_VERSION_C    != FTFC_FLS_IP_AC_AR_RELEASE_MAJOR_VERSION_H) || \
            (FLS_IPW_AR_RELEASE_MINOR_VERSION_C    != FTFC_FLS_IP_AC_AR_RELEASE_MINOR_VERSION_H) || \
            (FLS_IPW_AR_RELEASE_REVISION_VERSION_C != FTFC_FLS_IP_AC_AR_RELEASE_REVISION_VERSION_H) \
        )
        #error "AutoSar Version Numbers of Fls_IPW.c and Ftfc_Fls_Ip_Ac.h are different"
    #endif
    /* Check if current file and Ftfc_Fls_Ip_Ac header file are of the same Software version */
    #if ((FLS_IPW_SW_MAJOR_VERSION_C != FTFC_FLS_IP_AC_SW_MAJOR_VERSION_H) || \
         (FLS_IPW_SW_MINOR_VERSION_C != FTFC_FLS_IP_AC_SW_MINOR_VERSION_H) || \
         (FLS_IPW_SW_PATCH_VERSION_C != FTFC_FLS_IP_AC_SW_PATCH_VERSION_H) \
        )
        #error "Software Version Numbers of Fls_IPW.c and Ftfc_Fls_Ip_Ac.h are different"
    #endif
#endif /* (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED) */

#if (STD_ON == FLS_QSPI_SECTORS_CONFIGURED)
    /* Check if current file and Fls_Qspi header file are of the same vendor */
    #if (FLS_IPW_VENDOR_ID_C != QSPI_IP_VENDOR_ID_H)
        #error "Fls_IPW.c and Fls_Qspi.h have different vendor ids"
    #endif
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
        /* Check if current file and Fls_Qspi header file are of the same Autosar version */
        #if ((FLS_IPW_AR_RELEASE_MAJOR_VERSION_C    != QSPI_IP_AR_RELEASE_MAJOR_VERSION_H) || \
             (FLS_IPW_AR_RELEASE_MINOR_VERSION_C    != QSPI_IP_AR_RELEASE_MINOR_VERSION_H) || \
             (FLS_IPW_AR_RELEASE_REVISION_VERSION_C != QSPI_IP_AR_RELEASE_REVISION_VERSION_H) \
            )
            #error "AutoSar Version Numbers of Fls_IPW.c and Fls_Qspi.h are different"
        #endif
    #endif
    /* Check if current file and Fls_Qspi header file are of the same Software version */
    #if ((FLS_IPW_SW_MAJOR_VERSION_C != QSPI_IP_SW_MAJOR_VERSION_H) || \
         (FLS_IPW_SW_MINOR_VERSION_C != QSPI_IP_SW_MINOR_VERSION_H) || \
         (FLS_IPW_SW_PATCH_VERSION_C != QSPI_IP_SW_PATCH_VERSION_H) \
        )
        #error "Software Version Numbers of Fls_IPW.c and Fls_Qspi.h are different"
    #endif
#endif /* (STD_ON == FLS_QSPI_SECTORS_CONFIGURED) */


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#if (STD_ON == FLS_AC_LOAD_ON_JOB_START)
    #ifdef MCAL_PLATFORM_ARM
        #define FLASH_ARM_FAR_CALL2THUMB_CODE_BIT0_U32 (0x00000001UL)
        /* Macro for Access Code Call. On ARM/Thumb, BLX instruction used by the compiler for calling a function
           pointed to by the pointer requires that LSB bit of the address is set to one if the called fcn is coded in Thumb. */
        #define FLASH_AC_CALL(ptr2fcn, ptr2fcnType) ((ptr2fcnType)(((uint32)(ptr2fcn)) | FLASH_ARM_FAR_CALL2THUMB_CODE_BIT0_U32))
    #else
        #define FLASH_AC_CALL(ptr2fcn, ptr2fcnType) (ptr2fcn)
    #endif /* MCAL_PLATFORM_ARM */
#endif /* FLS_AC_LOAD_ON_JOB_START */


/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#if (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED)
static Fls_LLDReturnType Fls_IPW_TranslateReturnCode(Ftfc_Fls_Ip_StatusType eReturnCode);
static void Fls_IPW_LLDMainFunctionFtfcJobs(void);
static inline void Fls_IPW_LLDMainFunctionFtfcJobs_CheckEraseStatus(Ftfc_Fls_Ip_StatusType status);
static inline void Fls_IPW_LLDMainFunctionFtfcJobs_CheckWriteStatus(Ftfc_Fls_Ip_StatusType status);
static inline Fls_LLDReturnType Fls_IPW_SectorEraseFtfcJobs(boolean bAsynch, Fls_AddressType u32SectorOffset);
static inline Fls_LLDReturnType Fls_IPW_SectorWriteFtfcJobs(const Fls_AddressType u32SectorOffset, const Fls_AddressType u32Length, const uint8 *pJobDataSrcPtr, const boolean bAsynch);
static inline void Fls_IPW_CallAccessCodeWrite(void);
static inline void Fls_IPW_CallAccessCodeErase(void);
#if (STD_ON == FLS_ECC_CHECK_BY_AUTOSAR_OS)
static Ftfc_Fls_Ip_StatusType Fls_IPW_CopyBlock(uint32 u32LogicalAddress, uint32 u32Length, uint8 *pDestAddressPtr, const uint8 *pSourceAddressPtr);
#endif /* STD_ON == FLS_ECC_CHECK_BY_AUTOSAR_OS */
#endif /* (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED) */

#if (STD_ON == FLS_QSPI_SECTORS_CONFIGURED)
static Fls_AddressType  Fls_IPW_ComputeWriteChunkSize(Fls_AddressType jobSize, Fls_AddressType baseAddr, Fls_AddressType pageSize, uint32 memAlignment);
static Fls_LLDReturnType Fls_IPW_SectorWriteChunk(const boolean bAsynch);
static void Fls_IPW_LLDMainFunctionQspiErase(uint32 flashInstance);
static void Fls_IPW_LLDMainFunctionQspiWrite(uint32 flashInstance);
static void Fls_IPW_LLDMainFunctionQspiJobs(void);
static inline Fls_LLDReturnType Fls_IPW_SectorEraseQspiJobs(boolean bAsynch, Fls_AddressType u32SectorOffset, const Fls_LengthType u32PhysicalSectorSize);
static inline Fls_LLDReturnType Fls_IPW_SectorWriteQspiJobs(const Fls_AddressType u32SectorOffset, const Fls_AddressType u32Length, const uint8 *pJobDataSrcPtr, const boolean bAsynch);
static Qspi_Ip_StatusType Fls_IPW_InitControllers(void);
static Qspi_Ip_StatusType Fls_IPW_InitMemories(void);
static boolean Fls_IPW_CheckDevicesId(void);
#endif /* (STD_ON == FLS_QSPI_SECTORS_CONFIGURED) */


/*==================================================================================================
                                 ENUM TYPEDEFS
==================================================================================================*/
#if (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED)
#if (STD_ON == FLS_ECC_CHECK_BY_AUTOSAR_OS)
/**
* @brief   Elements of read callout function
*/
typedef struct
{
    uint32             u32ReadStartAddress;    /**< @brief The start address of the memory area to be read/compare  */
    uint32             u32Length;              /**< @brief Number of bytes to read/compare                          */
    uint8              *pDataDest;             /**< @brief Pointer to target data buffer used to read to            */
    const uint8        *pDataSource;           /**< @brief Pointer to source data buffer used to compare            */
    Ftfc_Fls_Ip_StatusType  eStatus;           /**< @brief Status of the copy operation                             */
} Fls_CopyDescrType;
#endif /* STD_ON == FLS_ECC_CHECK_BY_AUTOSAR_OS */
#endif /* (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED) */

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
 *                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

#if (defined(FLS_DEVICES_USING_SFDP))
#if (FLS_DEVICES_USING_SFDP > 0)

#define FLS_QSPI_SFDP_LUT_SIZE               130U
#define FLS_QSPI_SFDP_INIT_OP_SIZE           (4U * 2U)    /* Double size for insert wait operations */

typedef struct
{
    Qspi_Ip_InstrOpType lutOps[FLS_QSPI_SFDP_LUT_SIZE];               /*!< Array for virtual LUT instructions       */
    Qspi_Ip_InitOperationType initOps[FLS_QSPI_SFDP_INIT_OP_SIZE];    /*!< Array for initial operations             */
    Qspi_Ip_MemoryConfigType sfdpCfg;                                 /*!< Flash device configuration structure     */
} Fls_Qspi_SfdpConfigType;
#endif
#endif


/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/
#if (FLS_QSPI_SECTORS_CONFIGURED == STD_ON)

#define FLS_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Fls_MemMap.h"

/* The external job start address */
static Fls_AddressType Fls_Qspi_u32ExtJobStartAddr;
/* The external job size */
static Fls_AddressType Fls_Qspi_u32ExtJobSize;
/* The external job current chunk size, for jobs which need to be split in chunks */
static Fls_AddressType Fls_Qspi_u32ExtJobChunkSize;
/* Source data buffer for the current write job. */
static const uint8 * Fls_Qspi_u32ExtJobBuffAddr;

#if (defined(FLS_DEVICES_USING_SFDP))
#if (FLS_DEVICES_USING_SFDP > 0)
/* Array of configurations for flash devices configured to use SFDP  */
static Fls_Qspi_SfdpConfigType Fls_Qspi_SfdpConfigs[FLS_DEVICES_USING_SFDP];
/* Configurations indexes for flash devices configured to use SFDP  */
static uint8 Fls_Qspi_SfdpConfigsIndex[QSPI_IP_MEM_INSTANCE_COUNT];
#endif
#endif

#define FLS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_CLEARED_32
#include "Fls_MemMap.h"

/* Counters for timeout detection */
static uint32  Fls_Qspi_u32ElapsedTicks;
static uint32  Fls_Qspi_u32TimeoutTicks;
static uint32  Fls_Qspi_u32CurrentTicks;

#define FLS_STOP_SEC_VAR_CLEARED_32
#include "Fls_MemMap.h"

#endif /* (STD_ON == FLS_QSPI_SECTORS_CONFIGURED) */


#if (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED)
#if (STD_ON == FLS_ECC_CHECK_BY_AUTOSAR_OS)
#define FLS_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Fls_MemMap.h"
/* The copy operation when read */
static Fls_CopyDescrType Fls_CopyDescr;
#define FLS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Fls_MemMap.h"
#endif /* STD_ON == FLS_ECC_CHECK_BY_AUTOSAR_OS */
#endif /* (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED) */

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
#if (STD_ON == FLS_QSPI_SECTORS_CONFIGURED)
/*
    Computes the size of the next chunk of a write job.
*/
static Fls_AddressType  Fls_IPW_ComputeWriteChunkSize(Fls_AddressType jobSize, Fls_AddressType baseAddr, Fls_AddressType pageSize, uint32 memAlignment)
{
    Fls_AddressType chunkSize;

    /* Reserve size in case writing from odd starting address */
    uint32 startAddrOffset  = baseAddr & (memAlignment - 1U);
    uint32 QspiMaxWriteSize = QSPI_IP_MAX_WRITE_SIZE - startAddrOffset;

    /* Check external device restrictions: chunkSize can not exceed the device page size */
    /* If address is not aligned, max. chunkSize is the amount left in the current page */
    chunkSize = pageSize - (baseAddr % pageSize);
    /* Check if chunk does not exceed IP driver capabilities */
    if (chunkSize > QspiMaxWriteSize)
    {
        chunkSize = QspiMaxWriteSize;
    }
    /* Check if entire job fits in current page */
    if (chunkSize > jobSize)
    {
        chunkSize = jobSize;
    }
    return chunkSize;
}

/**
* @brief          Writes a single data chunk.
* @details        This function initiates a write for a data chunk - amount of data than can be written in a single operation.
*/
static Fls_LLDReturnType Fls_IPW_SectorWriteChunk(const boolean bAsynch)
{
    Fls_LLDReturnType eLldRetVal = FLASH_E_FAILED;
    uint32 flashInstance;
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_SUCCESS;

    /* Get external flash instance */
    flashInstance = (*(Fls_pConfigPtr->pFlsQspiCfgConfig->u8SectFlashUnit))[Fls_u32JobSectorIt];

#if (FLS_ERASE_VERIFICATION_ENABLED == STD_ON)
    if (STATUS_QSPI_IP_SUCCESS != Qspi_Ip_EraseVerify(flashInstance, Fls_Qspi_u32ExtJobStartAddr, Fls_Qspi_u32ExtJobChunkSize))
    {
        (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_VERIFY_ERASE_FAILED);
        eLldRetVal = FLASH_E_FAILED;
    }
    else
    {
#endif /* (FLS_ERASE_VERIFICATION_ENABLED == STD_ON) */
        /* Call IP write routine. */
        if (STATUS_QSPI_IP_SUCCESS != Qspi_Ip_Program(flashInstance, Fls_Qspi_u32ExtJobStartAddr, Fls_Qspi_u32ExtJobBuffAddr, Fls_Qspi_u32ExtJobChunkSize))
        {
            eLldRetVal = FLASH_E_FAILED;
        }
        else
        {
            if ((boolean)FALSE == bAsynch) /*SYNC Mode*/
            {
                eLldRetVal = FLASH_E_OK;
                /* Wait for the write to finish. */
                do
                {
#if ( (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON))
                    Fls_Qspi_u32ElapsedTicks += OsIf_GetElapsed(&Fls_Qspi_u32CurrentTicks, (OsIf_CounterType)QSPI_IP_TIMEOUT_TYPE);
                    if (Fls_Qspi_u32ElapsedTicks >= Fls_Qspi_u32TimeoutTicks)
                    {
                        status = STATUS_QSPI_IP_TIMEOUT;
                        (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_TIMEOUT);
                        break;
                    }
                    else
                    {
                        ; /* Empty clause added to fulfill MISRA. */
                    }
#endif /* (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON) */
                    status = Qspi_Ip_GetMemoryStatus(flashInstance);
                }
                while (STATUS_QSPI_IP_BUSY == status);

                if (STATUS_QSPI_IP_SUCCESS != status)
                {
                    eLldRetVal = FLASH_E_FAILED;
                }
#if (FLS_WRITE_VERIFICATION_ENABLED == STD_ON)
                else if (STATUS_QSPI_IP_SUCCESS != Qspi_Ip_ProgramVerify(flashInstance, Fls_Qspi_u32ExtJobStartAddr, Fls_Qspi_u32ExtJobBuffAddr, Fls_Qspi_u32ExtJobChunkSize))
                {
                    (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_VERIFY_WRITE_FAILED);
                    eLldRetVal = FLASH_E_FAILED;
                }
#endif /* (FLS_WRITE_VERIFICATION_ENABLED == STD_ON) */
                else
                {
                    ; /* Empty clause added to fulfill MISRA. */
                }
            }
            else
            {
                /* Schedule async write job. */
                Fls_eLLDJobResult = MEMIF_JOB_PENDING;
                Fls_eLLDJob = FLASH_JOB_WRITE;
                eLldRetVal = FLASH_E_PENDING;
            }
        }
#if (FLS_ERASE_VERIFICATION_ENABLED == STD_ON)
    }
#endif /* (FLS_ERASE_VERIFICATION_ENABLED == STD_ON) */

    return eLldRetVal;
}

/*
 * Function Name : Fls_IPW_LLDMainFunctionQspiErase
 * Description   : Handles ASYNC QSPI erase
*/
static void Fls_IPW_LLDMainFunctionQspiErase(uint32 flashInstance)
{
#if (FLS_ERASE_VERIFICATION_ENABLED == STD_OFF)
    (void)flashInstance;
#else
    Fls_AddressType u32ChunkSize = FLS_MAX_ERASE_BLANK_CHECK;

    if (Fls_Qspi_u32ExtJobSize < FLS_MAX_ERASE_BLANK_CHECK)
    {
        u32ChunkSize = Fls_Qspi_u32ExtJobSize;
    }
    Fls_Qspi_u32ExtJobSize -= u32ChunkSize;
    /* Verify that the sector was successfully erased. */
    if (STATUS_QSPI_IP_SUCCESS != Qspi_Ip_EraseVerify(flashInstance, Fls_Qspi_u32ExtJobStartAddr, u32ChunkSize))
    {
        /* Error, the memory locations are not erased or there was an error when attempting to read it. */
        (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_VERIFY_ERASE_FAILED);
        Fls_eLLDJob = FLASH_JOB_NONE;
        Fls_eLLDJobResult = MEMIF_JOB_FAILED;
    }
    if ((Fls_Qspi_u32ExtJobSize == 0U) && (Fls_eLLDJob != FLASH_JOB_NONE))
#endif /* (FLS_ERASE_VERIFICATION_ENABLED == STD_ON) */
    {
        /* Erase operation succeeded */
        Fls_eLLDJob = FLASH_JOB_NONE;
        Fls_eLLDJobResult = MEMIF_JOB_OK;
        if ((Fls_u32JobAddrIt > ((*(Fls_pConfigPtr->paSectorEndAddr))[Fls_u32JobSectorIt])))
        {
            /* Move on to the next sector */
            Fls_u32JobSectorIt++;
        }
    }
}


/*
 * Function Name : Fls_IPW_GetExtFlashConfig
 * Description   : Gets the external flash configuration
*/
static const Qspi_Ip_MemoryConfigType * Fls_IPW_GetExtFlashConfig(uint32 flashInstance)
{
    const Qspi_Ip_MemoryConfigType *flashConfig = NULL_PTR;
    uint32 flashConfigNo;

    /* Get external flash configuration */
    flashConfigNo = (*(Fls_pConfigPtr->pFlsQspiCfgConfig->u8FlashConfig))[flashInstance];
    if (flashConfigNo != FLS_IPW_CFG_INVALID)
    {
        flashConfig = &((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paFlashCfg))[flashConfigNo]);
    }
#if (defined(FLS_DEVICES_USING_SFDP))
#if (FLS_DEVICES_USING_SFDP > 0)
    else
    {
        /* SFDP auto-filled configuration */
        flashConfigNo = Fls_Qspi_SfdpConfigsIndex[flashInstance];
        flashConfig = &(Fls_Qspi_SfdpConfigs[flashConfigNo].sfdpCfg);
    }
#endif
#endif
    return flashConfig;
}


/*
 * Function Name : Fls_IPW_LLDMainFunctionQspiWrite
 * Description   : Handles ASYNC QSPI write
*/
static void Fls_IPW_LLDMainFunctionQspiWrite(uint32 flashInstance)
{
    const Qspi_Ip_MemoryConfigType *flashConfig;
    Fls_LLDReturnType eLldRetVal = FLASH_E_FAILED;
    uint32 memAlignment;

#if (FLS_WRITE_VERIFICATION_ENABLED == STD_ON)
    if (STATUS_QSPI_IP_SUCCESS != Qspi_Ip_ProgramVerify(flashInstance, Fls_Qspi_u32ExtJobStartAddr, Fls_Qspi_u32ExtJobBuffAddr, Fls_Qspi_u32ExtJobChunkSize))
    {
        /* Error, the memory location was not programmed with the desired data. */
        (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_VERIFY_WRITE_FAILED);
        Fls_eLLDJob = FLASH_JOB_NONE;
        Fls_eLLDJobResult = MEMIF_JOB_FAILED;
    }
    else
#endif /* (FLS_WRITE_VERIFICATION_ENABLED == STD_ON) */
    {
        /* Chunk write succeeded, check if there are more chunks */
        if (Fls_Qspi_u32ExtJobSize == Fls_Qspi_u32ExtJobChunkSize)
        {
            /* This was the last chunk, operation is completed */
            Fls_eLLDJob = FLASH_JOB_NONE;
            Fls_eLLDJobResult = MEMIF_JOB_OK;
            /* For a Write Job in ASYNC mode check if Fls_u32JobSectorIt should be increased */
            if ((Fls_u32JobAddrIt > ((*(Fls_pConfigPtr->paSectorEndAddr))[Fls_u32JobSectorIt])))
            {
                /* Move on to the next sector */
                Fls_u32JobSectorIt++;
            }
        }
        else
        {
            /* Get external flash configuration */
            flashConfig = Fls_IPW_GetExtFlashConfig(flashInstance);
            /* Get memory alignement */
            memAlignment = (uint32)(((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paFlashConnectionCfg))[flashInstance]).memAlignment);

            /* Update job parameters */
            Fls_Qspi_u32ExtJobStartAddr += Fls_Qspi_u32ExtJobChunkSize;
            Fls_Qspi_u32ExtJobBuffAddr = &(Fls_Qspi_u32ExtJobBuffAddr[Fls_Qspi_u32ExtJobChunkSize]);
            Fls_Qspi_u32ExtJobSize -= Fls_Qspi_u32ExtJobChunkSize;
            Fls_Qspi_u32ExtJobChunkSize = Fls_IPW_ComputeWriteChunkSize(Fls_Qspi_u32ExtJobSize, Fls_Qspi_u32ExtJobStartAddr, flashConfig->pageSize, memAlignment);
            /* Launch async write of next chunk */
            eLldRetVal = Fls_IPW_SectorWriteChunk((boolean)TRUE);
            if (FLASH_E_FAILED == eLldRetVal)
            {
                /* Error, cannot launch write for next chunk */
                Fls_eLLDJob = FLASH_JOB_NONE;
                Fls_eLLDJobResult = MEMIF_JOB_FAILED;
            }
        }
    }
}

/*
 * Function Name : Fls_IPW_LLDMainFunctionQspiJobs
 * Description   : Handles ASYNC QSPI jobs
*/
static void Fls_IPW_LLDMainFunctionQspiJobs(void)
{
    Qspi_Ip_StatusType status;
    uint32 flashInstance;

    /* Get external flash instance */
    flashInstance = (*(Fls_pConfigPtr->pFlsQspiCfgConfig->u8SectFlashUnit))[Fls_u32JobSectorIt];

    status = Qspi_Ip_GetMemoryStatus(flashInstance);
    if (STATUS_QSPI_IP_BUSY != status)
    {
        if (STATUS_QSPI_IP_SUCCESS != status)
        {
            /* Error, unable to retrieve flash device status */
            if (FLASH_JOB_ERASE == Fls_eLLDJob)
            {
                (void)Det_ReportTransientFault((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_ERASE_FAILED);
            }
            else if (FLASH_JOB_WRITE == Fls_eLLDJob )
            {

                (void)Det_ReportTransientFault((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_WRITE_FAILED);
            }
            else
            {
                ; /* Do nothing - should not happen in Fully Trusted Environment;
                'else' clause added to fulfil MISRA Rule 14.10 */
            }

            Fls_eLLDJob = FLASH_JOB_NONE;
            Fls_eLLDJobResult = MEMIF_JOB_FAILED;
        }
        else
        {
            if (FLASH_JOB_ERASE == Fls_eLLDJob)
            {
                Fls_IPW_LLDMainFunctionQspiErase(flashInstance);
            }
            else if (FLASH_JOB_WRITE == Fls_eLLDJob )
            {
                Fls_IPW_LLDMainFunctionQspiWrite(flashInstance);
            }
            else
            {
                ; /* Do nothing - should not happen in Fully Trusted Environment;
                'else' clause added to fulfil MISRA Rule 14.10 */
            }
        }
    }   /* if (STATUS_QSPI_IP_BUSY != status ) */
    else
    {
        /* device busy, check timeout */
#if ( (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON))
        Fls_Qspi_u32ElapsedTicks += OsIf_GetElapsed(&Fls_Qspi_u32CurrentTicks, (OsIf_CounterType)QSPI_IP_TIMEOUT_TYPE);
        if (Fls_Qspi_u32ElapsedTicks >= Fls_Qspi_u32TimeoutTicks)
        {
            /* operation timed out */
            (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_TIMEOUT);

            if (FLASH_JOB_ERASE == Fls_eLLDJob)
            {
                (void)Det_ReportTransientFault((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_ERASE_FAILED);
            }
            else if (FLASH_JOB_WRITE == Fls_eLLDJob )
            {
                (void)Det_ReportTransientFault((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_WRITE_FAILED);
            }
            else
            {
                ; /* Do nothing - should not happen in Fully Trusted Environment;
                'else' clause added to fulfil MISRA Rule 14.10 */
            }

            Fls_eLLDJob = FLASH_JOB_NONE;
            Fls_eLLDJobResult = MEMIF_JOB_FAILED;
        }
#endif /* (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON) */
    }   /* if (STATUS_QSPI_IP_BUSY != status ) */
}


static inline Fls_LLDReturnType Fls_IPW_SectorEraseQspiJobs(boolean bAsynch, Fls_AddressType u32SectorOffset, const Fls_LengthType u32PhysicalSectorSize)
{
    Fls_LLDReturnType eLldRetVal = FLASH_E_FAILED;
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_SUCCESS;
    uint32 flashInstance;

    /* Get external flash instance */
    flashInstance = (*(Fls_pConfigPtr->pFlsQspiCfgConfig->u8SectFlashUnit))[Fls_u32JobSectorIt];
    /* Compute target address : sector start address */
    Fls_Qspi_u32ExtJobStartAddr = (*(Fls_pConfigPtr->paSectorHwAddress))[Fls_u32JobSectorIt] + u32SectorOffset;
    /* Record job size */
    Fls_Qspi_u32ExtJobSize = u32PhysicalSectorSize;

    /* Call IP routine to erase external sector. */
    if (STATUS_QSPI_IP_SUCCESS != Qspi_Ip_EraseBlock(flashInstance, Fls_Qspi_u32ExtJobStartAddr, Fls_Qspi_u32ExtJobSize))
    {
        eLldRetVal = FLASH_E_FAILED;
    }
    else
    {
#if ( (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON))
        /* Prepare timeout counter */
        Fls_Qspi_u32ElapsedTicks = 0U;
        Fls_Qspi_u32TimeoutTicks = OsIf_MicrosToTicks(((boolean)FALSE == bAsynch)?FLS_QSPI_SYNC_ERASE_TIMEOUT:FLS_QSPI_ASYNC_ERASE_TIMEOUT, (OsIf_CounterType)QSPI_IP_TIMEOUT_TYPE);
        Fls_Qspi_u32CurrentTicks = OsIf_GetCounter((OsIf_CounterType)QSPI_IP_TIMEOUT_TYPE);
#endif /* (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON) */
        if ((boolean)FALSE == bAsynch) /*SYNC Mode*/
        {
            eLldRetVal = FLASH_E_OK;
            /* Wait for the erase to finish. */
            do
            {
#if ( (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON))
                Fls_Qspi_u32ElapsedTicks += OsIf_GetElapsed(&Fls_Qspi_u32CurrentTicks, (OsIf_CounterType)QSPI_IP_TIMEOUT_TYPE);
                if (Fls_Qspi_u32ElapsedTicks >= Fls_Qspi_u32TimeoutTicks)
                {
                    status = STATUS_QSPI_IP_TIMEOUT;
                    (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_TIMEOUT);
                    break;
                }
#endif /* (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON) */
                status = Qspi_Ip_GetMemoryStatus(flashInstance);
            }
            while (STATUS_QSPI_IP_BUSY == status);

            if (STATUS_QSPI_IP_SUCCESS != status)
            {
                eLldRetVal = FLASH_E_FAILED;
            }
#if (FLS_ERASE_VERIFICATION_ENABLED == STD_ON)
            /* Verify that the sector was succesfully erased. */
            else if (STATUS_QSPI_IP_SUCCESS != Qspi_Ip_EraseVerify(flashInstance, Fls_Qspi_u32ExtJobStartAddr, Fls_Qspi_u32ExtJobSize))
            {
                (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_VERIFY_ERASE_FAILED);
                eLldRetVal = FLASH_E_FAILED;
            }
#endif
            else
            {
                ; /* Empty clause added to fulfill MISRA. */
            }
        }
        else
        {
            /* Schedule async erase job. */
            Fls_eLLDJobResult = MEMIF_JOB_PENDING;
            Fls_eLLDJob = FLASH_JOB_ERASE;
            eLldRetVal = FLASH_E_PENDING;
        }
    }

    return eLldRetVal;
}


static inline Fls_LLDReturnType Fls_IPW_SectorWriteQspiJobs(const Fls_AddressType u32SectorOffset,
                                                            const Fls_AddressType u32Length,
                                                            const uint8 *pJobDataSrcPtr,
                                                            const boolean bAsynch
                                                           )
{
    Fls_LLDReturnType eLldRetVal;
    const Qspi_Ip_MemoryConfigType *flashConfig;
    uint32 flashInstance;
    uint32 memAlignment;

    /* Get external flash instance */
    flashInstance = (*(Fls_pConfigPtr->pFlsQspiCfgConfig->u8SectFlashUnit))[Fls_u32JobSectorIt];
    /* Get external flash configuration */
    flashConfig = Fls_IPW_GetExtFlashConfig(flashInstance);
    /* Get memory alignement */
    memAlignment = (uint32)(((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paFlashConnectionCfg))[flashInstance]).memAlignment);

    /* Compute target address : sector address + offset */
    Fls_Qspi_u32ExtJobStartAddr = (*(Fls_pConfigPtr->paSectorHwAddress))[Fls_u32JobSectorIt] + u32SectorOffset;
    /* Record source pointer */
    Fls_Qspi_u32ExtJobBuffAddr = pJobDataSrcPtr;
    /* Record job size */
    Fls_Qspi_u32ExtJobSize = u32Length;
    /* Compute next chunk size - consider QSPI and external device restrictions */
    Fls_Qspi_u32ExtJobChunkSize = Fls_IPW_ComputeWriteChunkSize(Fls_Qspi_u32ExtJobSize, Fls_Qspi_u32ExtJobStartAddr, flashConfig->pageSize, memAlignment);

#if ( (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON))
    /* Prepare timeout counter */
    Fls_Qspi_u32ElapsedTicks = 0U;
    Fls_Qspi_u32TimeoutTicks = OsIf_MicrosToTicks(((boolean)FALSE == bAsynch)?FLS_QSPI_SYNC_WRITE_TIMEOUT:FLS_QSPI_ASYNC_WRITE_TIMEOUT, (OsIf_CounterType)QSPI_IP_TIMEOUT_TYPE);
    Fls_Qspi_u32CurrentTicks = OsIf_GetCounter((OsIf_CounterType)QSPI_IP_TIMEOUT_TYPE);
#endif /* (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON) */

    /* Write the first chunk */
    eLldRetVal = Fls_IPW_SectorWriteChunk(bAsynch);
    if ((boolean)FALSE == bAsynch)
    {    /* SYNC Mode - complete operation */
        while ((FLASH_E_OK == eLldRetVal) && (Fls_Qspi_u32ExtJobSize > Fls_Qspi_u32ExtJobChunkSize))
        {
            /* Update job parameters */
            Fls_Qspi_u32ExtJobStartAddr += Fls_Qspi_u32ExtJobChunkSize;
            Fls_Qspi_u32ExtJobBuffAddr = &(Fls_Qspi_u32ExtJobBuffAddr[Fls_Qspi_u32ExtJobChunkSize]);
            Fls_Qspi_u32ExtJobSize -= Fls_Qspi_u32ExtJobChunkSize;
            Fls_Qspi_u32ExtJobChunkSize = Fls_IPW_ComputeWriteChunkSize(Fls_Qspi_u32ExtJobSize, Fls_Qspi_u32ExtJobStartAddr, flashConfig->pageSize, memAlignment);
            /* Write current chunk */
            eLldRetVal = Fls_IPW_SectorWriteChunk(bAsynch);
        }
    }

    return eLldRetVal;
}


/*
 * Function Name : Fls_IPW_InitControllers
 * Description   : Initialize QSPI controllers
*/
static Qspi_Ip_StatusType Fls_IPW_InitControllers(void)
{
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_SUCCESS;
    uint8 config = 0U;
    uint8 cnt = 0U;

    for (cnt = 0U; cnt < Fls_pConfigPtr->pFlsQspiCfgConfig->u8QspiUnitsCount; cnt++)
    {
        /* Get configuration for current QSPI device */
        config = (*(Fls_pConfigPtr->pFlsQspiCfgConfig->u8QspiConfig))[cnt];
        if (config != FLS_IPW_CFG_INVALID)
        {
            /* Use configuration "config" to initialize QSPI controller "cnt" */
            status = Qspi_Ip_ControllerInit(cnt, &((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[config]));
            if (STATUS_QSPI_IP_SUCCESS != status)
            {
                break;
            }
        }
    }

    return status;
}

/*
 * Function Name : Fls_IPW_InitMemories
 * Description   : Initialize Qspi external flash devices
*/
static Qspi_Ip_StatusType Fls_IPW_InitMemories(void)
{
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_SUCCESS;
    uint8 config = 0U;
    uint8 cnt = 0U;
#if (defined(FLS_DEVICES_USING_SFDP))
#if (FLS_DEVICES_USING_SFDP > 0)
    Qspi_Ip_MemoryConfigType *flashCfg;
    /* Current SFDP configuration  */
    uint8 Fls_Qspi_SfdpConfigsCount = 0U;
#endif
#endif

    for (cnt = 0U; cnt < Fls_pConfigPtr->pFlsQspiCfgConfig->u8FlashUnitsCount; cnt++)
    {
        /* Get configuration for current QSPI device */
        config = (*(Fls_pConfigPtr->pFlsQspiCfgConfig->u8FlashConfig))[cnt];
        if (config != FLS_IPW_CFG_INVALID)
        {
            /* Use configuration "config" to initialize flash device "cnt" */
            status = Qspi_Ip_Init(cnt, &((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paFlashCfg))[config]), &((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paFlashConnectionCfg))[cnt]));
        }
#if (defined(FLS_DEVICES_USING_SFDP))
#if (FLS_DEVICES_USING_SFDP > 0)
        else
        {
            /* This device must auto-configure using SFDP */
            /* Prepare configuration structure, link lut and init operations arrays */
            flashCfg = &(Fls_Qspi_SfdpConfigs[Fls_Qspi_SfdpConfigsCount].sfdpCfg);
            flashCfg->lutSequences.opCount = FLS_QSPI_SFDP_LUT_SIZE;
            flashCfg->lutSequences.lutOps = Fls_Qspi_SfdpConfigs[Fls_Qspi_SfdpConfigsCount].lutOps;
            flashCfg->initConfiguration.opCount = FLS_QSPI_SFDP_INIT_OP_SIZE;
            flashCfg->initConfiguration.operations = Fls_Qspi_SfdpConfigs[Fls_Qspi_SfdpConfigsCount].initOps;
            status = Qspi_Ip_ReadSfdp(flashCfg, &((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paFlashConnectionCfg))[cnt]));
            if (STATUS_QSPI_IP_SUCCESS == status)
            {
                /* Qspi_Ip_ReadSfdp auto-filled configuration, use it to initialize flash device */
                status = Qspi_Ip_Init(cnt, flashCfg, &((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paFlashConnectionCfg))[cnt]));
            }
            /* Store index to allow configuration to be retrieved later */
            Fls_Qspi_SfdpConfigsIndex[cnt] = Fls_Qspi_SfdpConfigsCount;
            Fls_Qspi_SfdpConfigsCount++;
        }
#endif
#endif

        /* Configure the AHB reads for flash unit "cnt" */
        if ( (STATUS_QSPI_IP_SUCCESS == status) && ((boolean)TRUE == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paAHBReadCfg))[cnt]) )
        {
            status = Qspi_Ip_AhbReadEnable( ((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paFlashConnectionCfg))[cnt]).qspiInstance );
        }

        if (STATUS_QSPI_IP_SUCCESS != status)
        {
            break;
        }
    }

    return status;
}

/*
 * Function Name : Fls_IPW_CheckDevicesId
 * Description   : Check the identification of the external flash device against the configured one
*/
static boolean Fls_IPW_CheckDevicesId(void)
{
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_SUCCESS;
    boolean bRetVal = (boolean)TRUE;
    const Qspi_Ip_MemoryConfigType * pConfig;
    uint32 readId = 0U;
    uint8 cnt;

    for (cnt = 0U; cnt < Fls_pConfigPtr->pFlsQspiCfgConfig->u8FlashUnitsCount; cnt++)
    {
        /* Get configuration for current QSPI device */
        pConfig = Fls_IPW_GetExtFlashConfig(cnt);

        /* If enabled, check identification of the external flash device */
        if (QSPI_IP_LUT_INVALID != pConfig->readIdSettings.readIdLut)
        {
            status = Qspi_Ip_ReadId(cnt, (uint8 *)&readId);
            /* Compare current device's ID with the corresponding configuration */
            if ( (STATUS_QSPI_IP_SUCCESS != status) || (readId != pConfig->readIdSettings.readIdExpected) )
            {
                (void)Det_ReportTransientFault((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_INIT_ID, FLS_E_UNEXPECTED_FLASH_ID);
                bRetVal = (boolean)FALSE;
                break;
            }
        }
    }
    return bRetVal;
}

#endif /* (STD_ON == FLS_QSPI_SECTORS_CONFIGURED) */

/*
 * Function Name : Fls_IPW_Init
 * Description   : Initialize Fls module
 * @implements     Fls_IPW_Init_Activity
*/
void Fls_IPW_Init(void)
{
    Fls_eLLDJobResult = MEMIF_JOB_OK;
#if (FLS_QSPI_SECTORS_CONFIGURED == STD_ON)
    Qspi_Ip_StatusType status;
    boolean bCheckId = (boolean)FALSE;

    /* Initialize QSPI controllers */
    status = Fls_IPW_InitControllers();

    /* Initialize external flash devices */
    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        status = Fls_IPW_InitMemories();
    }

    /* Check the hardware ID of the external flash devices */
    if (STATUS_QSPI_IP_SUCCESS == status)
    {
        bCheckId = Fls_IPW_CheckDevicesId();
    }

    if ((boolean)TRUE == bCheckId)
    {
        Fls_eLLDJobResult = MEMIF_JOB_OK;
    }
    else
    {
        Fls_eLLDJobResult = MEMIF_JOB_FAILED;
    }
#endif /* (STD_ON == FLS_QSPI_SECTORS_CONFIGURED) */

#if (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED)
    if (MEMIF_JOB_OK == Fls_eLLDJobResult)
    {
       if (STATUS_FTFC_FLS_IP_SUCCESS == Ftfc_Fls_Ip_Init(Fls_pConfigPtr->pFlsInternalCfgConfig))
        {
            Fls_eLLDJobResult = MEMIF_JOB_OK;
        }
        else
        {
            Fls_eLLDJobResult = MEMIF_JOB_FAILED;
        }
    }
#endif /* (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED) */
    Fls_eLLDJob = FLASH_JOB_NONE;
}

/*
 * Function Name : Fls_IPW_AbortSuspended
 * Description   : Abort suspended Fls module
 * @implements     Fls_IPW_AbortSuspended_Activity
*/
void Fls_IPW_AbortSuspended(void)
{
#if (FLS_QSPI_SECTORS_CONFIGURED == STD_ON)
    Fls_HwChType eHwCh;
    Fls_SectorIndexType u32SectorIndexIter;
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_SUCCESS;
    uint32 flashInstance;
    uint32 controllerInstance;
    uint32 lastFlashInstance = FLS_DEVICE_INSTANCE_INVALID;

    for (u32SectorIndexIter = Fls_u32JobSectorIt; u32SectorIndexIter <= Fls_u32JobSectorEnd; u32SectorIndexIter++ )
    {
        /* Get channel type(INTERNAL, EXTERNAL_A1, A2,...) to determine the HW IP used(internal or external flash). */
        eHwCh = (*(Fls_pConfigPtr->paHwCh))[u32SectorIndexIter];
         /* Get external flash instance */
        flashInstance = (*(Fls_pConfigPtr->pFlsQspiCfgConfig->u8SectFlashUnit))[u32SectorIndexIter];

        /* Check if this channel already was checked before */
        if ( (FLS_CH_QSPI == eHwCh) && (flashInstance != lastFlashInstance) )
        {
            lastFlashInstance = flashInstance;
            /* Get controller instance */
            controllerInstance = ((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paFlashConnectionCfg))[flashInstance]).qspiInstance;

            /* Prepare timeout counter */
            Fls_Qspi_u32ElapsedTicks = 0U;
            Fls_Qspi_u32TimeoutTicks = OsIf_MicrosToTicks(QSPI_IP_CMD_COMPLETE_TIMEOUT, (OsIf_CounterType)QSPI_IP_TIMEOUT_TYPE);
            Fls_Qspi_u32CurrentTicks = OsIf_GetCounter((OsIf_CounterType)QSPI_IP_TIMEOUT_TYPE);
            /* Wait for the controller to become idle */
            do
            {
                /* Add Fault Injection point for FR_ILLINE flag */
                MCAL_FAULT_INJECTION_POINT(FLS_FIP_FR_ERROR_ABORTSUSPEND);

                status = Qspi_Ip_ControllerGetStatus(controllerInstance);
                Fls_Qspi_u32ElapsedTicks += OsIf_GetElapsed(&Fls_Qspi_u32CurrentTicks, (OsIf_CounterType)QSPI_IP_TIMEOUT_TYPE);
                if ((STATUS_QSPI_IP_BUSY == status) && (Fls_Qspi_u32ElapsedTicks >= Fls_Qspi_u32TimeoutTicks))
                {
                    status = STATUS_QSPI_IP_TIMEOUT;
                }
            }
            while (STATUS_QSPI_IP_BUSY == status);

            if (STATUS_QSPI_IP_SUCCESS == status)
            {
                /* Check that external memory is idle */
                if (STATUS_QSPI_IP_SUCCESS != Qspi_Ip_GetMemoryStatus(flashInstance))
                {
                    /* Reset external memory */
                    status = Qspi_Ip_Reset(flashInstance);
                }
            }

            if (STATUS_QSPI_IP_SUCCESS != status)
            {
                /*Exit for-loop*/
                Fls_eLLDJob = FLASH_JOB_NONE;
                Fls_eLLDJobResult = MEMIF_JOB_FAILED;
                break;
            }
        }
    }

#endif /* (STD_ON == FLS_QSPI_SECTORS_CONFIGURED) */
}

void Fls_IPW_ClearHVJob(void)
{
    /* Hardware did not support this feature */
}

#if (FLS_CANCEL_API == STD_ON )

/*
 * Function Name : Fls_IPW_Cancel
 * Description   : Cancel Fls module
 * @implements     Fls_IPW_Cancel_Activity
*/
void Fls_IPW_Cancel(void)
{
    Fls_HwChType eHwCh;

    /* Get channel type(INTERNAL, QSPI,...) to determine the HW IP used(internal or external flash). */
    eHwCh = (*(Fls_pConfigPtr->paHwCh))[Fls_u32JobSectorIt];

    if (MEMIF_JOB_PENDING == Fls_eLLDJobResult )
    {
#if (FLS_INTERNAL_SECTORS_CONFIGURED == STD_ON)
        if (FLS_CH_INTERN == eHwCh)
        {
            if (STATUS_FTFC_FLS_IP_SUCCESS == Ftfc_Fls_Ip_Abort())
            {
                /* Mark the job as canceled.*/
                Fls_eLLDJob = FLASH_JOB_NONE;
                Fls_eLLDJobResult = MEMIF_JOB_CANCELED;
            }
        }
#endif /* (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED) */

#if (STD_ON == FLS_QSPI_SECTORS_CONFIGURED)
        if (FLS_CH_QSPI == eHwCh)
        {
            /* Mark the job as canceled.*/
            Fls_eLLDJob = FLASH_JOB_NONE;
            Fls_eLLDJobResult = MEMIF_JOB_CANCELED;
        }
#endif /* (STD_ON == FLS_QSPI_SECTORS_CONFIGURED) */
    }
    else
    {
        /* no hardware job (asynchronous) is pending, do nothing */

        /* Mark the internal job as canceled.*/
        Fls_eLLDJob = FLASH_JOB_NONE;
        Fls_eLLDJobResult = MEMIF_JOB_CANCELED;
    }
}
#endif


/**
* @brief          Process ongoing erase or write hardware job.
* @details        In case Async Operation is ongoing this function will complete the following job:
*                 - Erase
*                 - Erase on Interleaved sectors
*                 - Write
*                 - Erase blank Check
*
* @note           Dem_ReportErrorStatus(Fls_pConfigPtr->Fls_E_EraseFailedCfg.id, DEM_EVENT_STATUS_FAILED)
*                 when erase operation failed due to hardware error.
*                 Dem_ReportErrorStatus(Fls_pConfigPtr->Fls_E_WriteFailedCfg.id, DEM_EVENT_STATUS_FAILED)
*                 when write operation failed due to hardware error
* @implements     Fls_IPW_LLDMainFunction_Activity
*/
void Fls_IPW_LLDMainFunction( void )
{
    Fls_HwChType eHwCh;

    /* Get channel type(INTERNAL, EXTERNAL_A1, A2,...) to determine the HW IP used(internal or external flash). */
    eHwCh = (*(Fls_pConfigPtr->paHwCh))[Fls_u32JobSectorIt];

    if (MEMIF_JOB_PENDING == Fls_eLLDJobResult)
    {
#if (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED)
        if (FLS_CH_INTERN == eHwCh)
        {
            Fls_IPW_LLDMainFunctionFtfcJobs();
        }
#endif /* (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED) */

#if (STD_ON == FLS_QSPI_SECTORS_CONFIGURED)
        if (FLS_CH_QSPI == eHwCh)
        {
            Fls_IPW_LLDMainFunctionQspiJobs();
        }
#endif /* (STD_ON == FLS_QSPI_SECTORS_CONFIGURED) */

    }   /* if (MEMIF_JOB_PENDING == Fls_eLLDJobResult) */
    else
    {
        /* no hardware job (asynchronous) is pending, do nothing */
    }
}


/**
* @brief          IP wrapper sector read function.
* @details        Route the read job to appropriate low level IP function.
* @implements     Fls_IPW_SectorRead_Activity
*/
Fls_LLDReturnType Fls_IPW_SectorRead(const Fls_AddressType u32SectorOffset,
                                     const Fls_AddressType u32Length,
                                     uint8 * pJobDataDestPtr,
                                     const uint8 *pJobDataSrcPtr
                                    )
{
    Fls_LLDReturnType eLldRetVal = FLASH_E_FAILED;
    Fls_HwChType eHwCh;
#if ( (FLS_COMPARE_API == STD_OFF) && (FLS_BLANK_CHECK_API == STD_OFF) )
    (void)pJobDataSrcPtr;
#endif  /* (( FLS_COMPARE_API == STD_ON ) || ( FLS_BLANK_CHECK_API == STD_ON )) */
#if (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED)
    Ftfc_Fls_Ip_StatusType eReturnCode = STATUS_FTFC_FLS_IP_ERROR;
    uint32 u32ReadStartAddress = 0U;
#endif /* #if (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED) */
#if (STD_ON == FLS_QSPI_SECTORS_CONFIGURED)
    Qspi_Ip_StatusType status = STATUS_QSPI_IP_SUCCESS;
    uint32 flashInstance;
    Fls_AddressType u32ReadAddr;
#endif /* #if (STD_ON == FLS_QSPI_SECTORS_CONFIGURED) */

    /* Get channel type(INTERNAL, QSPI,...) to determine the HW IP used(internal or external flash). */
    eHwCh = (*(Fls_pConfigPtr->paHwCh))[Fls_u32JobSectorIt];

    /* Decide the IP used: internal flash or external QSPI */
#if (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED)
    if (FLS_CH_INTERN == eHwCh)
    {
        /* Get the base address of the sector. */
        u32ReadStartAddress = (uint32)(*((*(Fls_pConfigPtr->pSectorList))[Fls_u32JobSectorIt])).pSectorStartAddressPtr;
        /* Add the offset */
        u32ReadStartAddress += u32SectorOffset;

        /* Decide whether the job is a Read, a compare, or a blank check. */
        if (NULL_PTR != pJobDataDestPtr)
        {
#if (STD_ON == FLS_ECC_CHECK_BY_AUTOSAR_OS)
            if ( NULL_PTR != Fls_pConfigPtr->FlsReadFunctionCallout )
            {
                /* Users will have to define Callout function to call Fls_ReadEachBlock to read data from memory */
                eReturnCode = Fls_IPW_CopyBlock(u32ReadStartAddress, u32Length, pJobDataDestPtr, NULL_PTR);
            }
            else
#endif /* STD_ON == FLS_ECC_CHECK_BY_AUTOSAR_OS */
            {
                eReturnCode = Ftfc_Fls_Ip_Read(u32ReadStartAddress, pJobDataDestPtr, u32Length);
            }
        }
#if (( FLS_COMPARE_API == STD_ON ) || ( FLS_BLANK_CHECK_API == STD_ON ))
        else
        {
#if (STD_ON == FLS_ECC_CHECK_BY_AUTOSAR_OS)
            if ( NULL_PTR != Fls_pConfigPtr->FlsReadFunctionCallout )
            {
                /* Users will have to define Callout function to call Fls_ReadEachBlock to read data from memory */
                eReturnCode = Fls_IPW_CopyBlock(u32ReadStartAddress, u32Length, NULL_PTR, pJobDataSrcPtr);
            }
            else
#endif /* STD_ON == FLS_ECC_CHECK_BY_AUTOSAR_OS */
            {
                eReturnCode = Ftfc_Fls_Ip_Compare(u32ReadStartAddress, pJobDataSrcPtr, u32Length);
            }
        }
#endif  /* (( FLS_COMPARE_API == STD_ON ) || ( FLS_BLANK_CHECK_API == STD_ON )) */

        eLldRetVal = Fls_IPW_TranslateReturnCode(eReturnCode);
    }
#endif /* (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED) */

#if (STD_ON == FLS_QSPI_SECTORS_CONFIGURED)
    if (FLS_CH_QSPI == eHwCh)
    {
        /* Get external flash instance */
        flashInstance = (*(Fls_pConfigPtr->pFlsQspiCfgConfig->u8SectFlashUnit))[Fls_u32JobSectorIt];
        /* Initialize job parameters */
        /* Compute target address : sector address + offset */
        u32ReadAddr = (*(Fls_pConfigPtr->paSectorHwAddress))[Fls_u32JobSectorIt] + u32SectorOffset;

        /* Fault Injection point for testing when read data is executing */
        MCAL_FAULT_INJECTION_POINT(FLS_FIP_FR_ERROR_DATA_IPREAD);

        /* Decide whether the job is a Read, a compare, or a blank check. */
        if (NULL_PTR != pJobDataDestPtr)
        {
            status = Qspi_Ip_Read(flashInstance, u32ReadAddr, pJobDataDestPtr, u32Length);
        }
#if ( FLS_COMPARE_API == STD_ON )
        else if (NULL_PTR != pJobDataSrcPtr)
        {
            status = Qspi_Ip_ProgramVerify(flashInstance, u32ReadAddr, pJobDataSrcPtr, u32Length);
        }
#endif /*#if ( FLS_COMPARE_API == STD_ON ) */
#if ( FLS_BLANK_CHECK_API == STD_ON )
        else
        {
            status = Qspi_Ip_EraseVerify(flashInstance, u32ReadAddr, u32Length);
        }
#endif /*#if ( FLS_BLANK_CHECK_API == STD_ON ) */
        (void)pJobDataSrcPtr;

        if (STATUS_QSPI_IP_SUCCESS != status)
        {
#if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
            /*check timeout after checking status fail*/
            if (STATUS_QSPI_IP_TIMEOUT == status)
            {
                (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_TIMEOUT);
            }
#endif /* (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON) */
#if ( FLS_COMPARE_API == STD_ON )
            if (STATUS_QSPI_IP_ERROR_PROGRAM_VERIFY == status)
            {
                eLldRetVal = FLASH_E_BLOCK_INCONSISTENT;
            }
            else
            {
                eLldRetVal = FLASH_E_FAILED;
            }
#else
            eLldRetVal = FLASH_E_FAILED;
#endif /*#if ( FLS_COMPARE_API == STD_ON ) */
        }
        else
        {
            eLldRetVal = FLASH_E_OK;
        }
    } /* FLS_CH_QSPI == eHwCh */
#endif /* (STD_ON == FLS_QSPI_SECTORS_CONFIGURED) */

    return eLldRetVal;
}

/**
* @brief          IP wrapper sector erase function.
* @details        Route the erase job to appropriate low level IP function.
* @implements     Fls_IPW_SectorErase_Activity
*/
Fls_LLDReturnType Fls_IPW_SectorErase(const Fls_AddressType u32SectorOffset,
                                      const Fls_LengthType u32PhysicalSectorSize,
                                      const boolean bAsynch
                                     )
{
    Fls_LLDReturnType eLldRetVal = FLASH_E_FAILED;
    Fls_HwChType eHwCh;

    /* Get channel type(INTERNAL, QSPI,...) to determine the HW IP used(internal or external flash). */
    eHwCh = (*(Fls_pConfigPtr->paHwCh))[Fls_u32JobSectorIt];

    /* Decide the IP used: internal flash or external QSPI */
#if (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED)
    if (FLS_CH_INTERN == eHwCh)
    {
        eLldRetVal = Fls_IPW_SectorEraseFtfcJobs(bAsynch, u32SectorOffset);
    }
#endif /* (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED) */


#if (STD_ON == FLS_QSPI_SECTORS_CONFIGURED)
    if (FLS_CH_QSPI == eHwCh)
    {
        eLldRetVal = Fls_IPW_SectorEraseQspiJobs(bAsynch, u32SectorOffset, u32PhysicalSectorSize);
    }
#else
    /*Fix warning: unused variable*/
    (void)u32PhysicalSectorSize;
#endif /* (STD_ON == FLS_QSPI_SECTORS_CONFIGURED) */

    return eLldRetVal;
}

/**
* @brief          IP wrapper sector write function.
* @details        Route the write job to appropriate low level IP function.
* @implements     Fls_IPW_SectorWrite_Activity
*/
Fls_LLDReturnType Fls_IPW_SectorWrite(const Fls_AddressType u32SectorOffset,
                                      const Fls_AddressType u32Length,
                                      const uint8 *pJobDataSrcPtr,
                                      const boolean bAsynch
                                     )
{
    Fls_LLDReturnType eLldRetVal = FLASH_E_FAILED;
    Fls_HwChType eHwCh;

    /* Get channel type(INTERNAL, QSPI,...) to determine the HW IP used(internal or external flash). */
    eHwCh = (*(Fls_pConfigPtr->paHwCh))[Fls_u32JobSectorIt];

    /* Decide the IP used: internal flash or external QSPI */
#if (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED)
    if (FLS_CH_INTERN == eHwCh)
    {
        eLldRetVal = Fls_IPW_SectorWriteFtfcJobs(u32SectorOffset, u32Length, pJobDataSrcPtr, bAsynch);
    }
#endif /* (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED) */


#if (STD_ON == FLS_QSPI_SECTORS_CONFIGURED)
    if (FLS_CH_QSPI == eHwCh)
    {
        eLldRetVal = Fls_IPW_SectorWriteQspiJobs(u32SectorOffset, u32Length, pJobDataSrcPtr, bAsynch);
    }
#endif /* (STD_ON == FLS_QSPI_SECTORS_CONFIGURED) */

    return eLldRetVal;
}

#if (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED)
static inline void Fls_IPW_LLDMainFunctionFtfcJobs_CheckEraseStatus(Ftfc_Fls_Ip_StatusType status)
{
    if (STATUS_FTFC_FLS_IP_BUSY != status)
    {
        /* Erase operation finished at IP level - successfully or with errors or timed out */
        if (STATUS_FTFC_FLS_IP_SUCCESS != status)
        {
            /* Sector lock was ok, but IP operation failed */
            Fls_eLLDJobResult = MEMIF_JOB_FAILED;
            (void)Det_ReportTransientFault((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_ERASE_FAILED);
            /* Report Runtime error when comparing is incorrect */
            if (STATUS_FTFC_FLS_IP_ERROR_BLANK_CHECK == status)
            {
                (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_VERIFY_ERASE_FAILED);
            }
        #if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
            /*check timeout after checking status fail*/
            else if (STATUS_FTFC_FLS_IP_ERROR_TIMEOUT == status)
            {
                (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_TIMEOUT);
            }
            else
            {
                /* Do nothing - blank statement added to fulfil MISRA Rule 15.7 */
            }
        #endif /* (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON) */
        }
        else
        {
            /* Everything was ok */
            Fls_eLLDJob = FLASH_JOB_NONE;
            Fls_eLLDJobResult = MEMIF_JOB_OK;
            if ((Fls_u32JobAddrIt > ((*(Fls_pConfigPtr->paSectorEndAddr))[Fls_u32JobSectorIt])))
            {
                /* Move on to the next sector */
                Fls_u32JobSectorIt++;
            }
        }
    }
}


static inline void Fls_IPW_LLDMainFunctionFtfcJobs_CheckWriteStatus(Ftfc_Fls_Ip_StatusType status)
{
    if (STATUS_FTFC_FLS_IP_BUSY != status)
    {
        /* Write operation finished at IP level - successfully or with errors or timed out */
        if (STATUS_FTFC_FLS_IP_SUCCESS != status)
        {
            /* IP operation failed */
            Fls_eLLDJobResult = MEMIF_JOB_FAILED;
            /* An error will be reported */
            (void)Det_ReportTransientFault((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_WRITE_FAILED);

            /* Report errors due to incorrect verifying writing */
            if (STATUS_FTFC_FLS_IP_ERROR_PROGRAM_VERIFY == status)
            {
                (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_VERIFY_WRITE_FAILED);
            }
        #if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
            /*check timeout after checking status fail*/
            else if (STATUS_FTFC_FLS_IP_ERROR_TIMEOUT == status)
            {
                (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_TIMEOUT);
            }
            else
            {
                /* Do nothing - blank statement added to fulfil MISRA Rule 15.7 */
            }
        #endif /* (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON) */
        }
        else
        {
            /* Everything was ok */
            Fls_eLLDJobResult = MEMIF_JOB_OK;
        }
    }
}


static void Fls_IPW_LLDMainFunctionFtfcJobs(void)
{
    Ftfc_Fls_Ip_StatusType eReturnCode = STATUS_FTFC_FLS_IP_ERROR;

    /* some hardware job (asynchronous) is pending */
    if (FLASH_JOB_ERASE == Fls_eLLDJob )
    {
        eReturnCode = Ftfc_Fls_Ip_SectorEraseStatus();

        Fls_IPW_LLDMainFunctionFtfcJobs_CheckEraseStatus(eReturnCode);
    }
    /* Write hardware job (asynchronous) is pending */
    else if (FLASH_JOB_WRITE == Fls_eLLDJob )
    {
        eReturnCode = Ftfc_Fls_Ip_WriteStatus();

        Fls_IPW_LLDMainFunctionFtfcJobs_CheckWriteStatus(eReturnCode);
    }
    else
    {
        /* Do nothing - should not happen in Fully Trusted Environment;
           'else' clause added to fulfil MISRA Rule 14.10 */
    }
}


static inline Fls_LLDReturnType Fls_IPW_SectorEraseFtfcJobs(boolean bAsynch, Fls_AddressType u32SectorOffset)
{
    Fls_LLDReturnType eLldRetVal = FLASH_E_FAILED;
    uint32 u32SectorStartAddress;
    Ftfc_Fls_Ip_StatusType eReturnCode = STATUS_FTFC_FLS_IP_ERROR;

    /* Get the base address of the sector. */
    u32SectorStartAddress = (uint32)(*((*(Fls_pConfigPtr->pSectorList))[Fls_u32JobSectorIt])).pSectorStartAddressPtr;

    /* set synch/Asynch at IP layer base on bAynch */
    Ftfc_Fls_Ip_SetAsyncMode(bAsynch);
    eReturnCode = Ftfc_Fls_Ip_SectorErase(u32SectorStartAddress + u32SectorOffset);

    if ((STATUS_FTFC_FLS_IP_SUCCESS == eReturnCode) && (FALSE == bAsynch))
    {
        Fls_IPW_CallAccessCodeErase();

        /* check status of erase hardware */
        eReturnCode = Ftfc_Fls_Ip_SectorEraseStatus();
        if (STATUS_FTFC_FLS_IP_SUCCESS != eReturnCode)
        {
            /* Sector lock was ok, but IP operation failed */
            Fls_eLLDJobResult = MEMIF_JOB_FAILED;
            eLldRetVal = Fls_IPW_TranslateReturnCode(eReturnCode);
        }
        else
        {
            /* Everything was ok */
            Fls_eLLDJobResult = MEMIF_JOB_OK;
            eLldRetVal = FLASH_E_OK;
        }
    }
    else
    {
        if (STATUS_FTFC_FLS_IP_SUCCESS != eReturnCode)
        {
            /* IP operation failed */
            Fls_eLLDJobResult = MEMIF_JOB_FAILED;
            eLldRetVal = Fls_IPW_TranslateReturnCode(eReturnCode);
        }
        else
        {
            eLldRetVal = FLASH_E_PENDING;
            Fls_eLLDJob = FLASH_JOB_ERASE;
            Fls_eLLDJobResult = MEMIF_JOB_PENDING;
        }
    }

#if ( (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON))
    /*check timeout after perform erase*/
    if (STATUS_FTFC_FLS_IP_ERROR_TIMEOUT == eReturnCode)
    {
        (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_TIMEOUT);
    }
#endif /* (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON) */

    return eLldRetVal;
}


static inline Fls_LLDReturnType Fls_IPW_SectorWriteFtfcJobs(const Fls_AddressType u32SectorOffset,
                                                            const Fls_AddressType u32Length,
                                                            const uint8 *pJobDataSrcPtr,
                                                            const boolean bAsynch
                                                           )
{
    Fls_LLDReturnType eLldRetVal = FLASH_E_FAILED;
    uint32 u32WriteStartAddress;
    Ftfc_Fls_Ip_StatusType eReturnCode;

    /* Get the base address of the sector. */
    u32WriteStartAddress = (uint32)(*((*(Fls_pConfigPtr->pSectorList))[Fls_u32JobSectorIt])).pSectorStartAddressPtr;
    /* Add the offset */
    u32WriteStartAddress += u32SectorOffset;

    /* set synch/Asynch at IP layer base on bAynch */
    Ftfc_Fls_Ip_SetAsyncMode(bAsynch);
    eReturnCode = Ftfc_Fls_Ip_Write(u32WriteStartAddress, pJobDataSrcPtr, u32Length);
    /* On sync */
    if ((STATUS_FTFC_FLS_IP_SUCCESS == eReturnCode) && (FALSE == bAsynch))
    {
        Fls_IPW_CallAccessCodeWrite();

        /* Check status of write hardware */
        eReturnCode = Ftfc_Fls_Ip_WriteStatus();
        if (STATUS_FTFC_FLS_IP_SUCCESS != eReturnCode)
        {
            /* IP operation failed */
            Fls_eLLDJobResult = MEMIF_JOB_FAILED;
            eLldRetVal = Fls_IPW_TranslateReturnCode(eReturnCode);
        }
        else
        {
            eLldRetVal = FLASH_E_OK;
        }
    }
    else
    {
        if (STATUS_FTFC_FLS_IP_SUCCESS != eReturnCode)
        {
            /* IP operation failed */
            Fls_eLLDJobResult = MEMIF_JOB_FAILED;
            eLldRetVal = Fls_IPW_TranslateReturnCode(eReturnCode);
        }
        else
        {
            eLldRetVal = FLASH_E_PENDING;
            Fls_eLLDJob = FLASH_JOB_WRITE;
            Fls_eLLDJobResult = MEMIF_JOB_PENDING;
        }
    }
#if ( (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON))
    /*check timeout after performing write*/
    if (STATUS_FTFC_FLS_IP_ERROR_TIMEOUT == eReturnCode)
    {
        (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_TIMEOUT);
    }
#endif /* (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON) */

    return eLldRetVal;
}

static inline void Fls_IPW_CallAccessCodeWrite(void)
{
#if ( STD_ON == FLS_AC_LOAD_ON_JOB_START )
    if (TRUE == Fls_bACloaded)
    {
        /* Sync mode - wait for IP to finish */
        FLASH_AC_CALL(Fls_pConfigPtr->acWritePtr, Fls_AcWritePtrType)(Fls_pConfigPtr->acCallBackPtr);
    }
    else
#endif /* STD_ON == FLS_AC_LOAD_ON_JOB_START */
    {
        Ftfc_Fls_Ip_AccessCode(Fls_pConfigPtr->acCallBackPtr);
    }
}


static inline void Fls_IPW_CallAccessCodeErase(void)
{
#if ( STD_ON == FLS_AC_LOAD_ON_JOB_START )
    if (TRUE == Fls_bACloaded)
    {
        /* Sync mode - wait for IP to finish */
        FLASH_AC_CALL(Fls_pConfigPtr->acErasePtr, Fls_AcErasePtrType)(Fls_pConfigPtr->acCallBackPtr);
    }
    else
#endif /* STD_ON == FLS_AC_LOAD_ON_JOB_START */
    {
        Ftfc_Fls_Ip_AccessCode(Fls_pConfigPtr->acCallBackPtr);
    }
}


static Fls_LLDReturnType Fls_IPW_TranslateReturnCode(Ftfc_Fls_Ip_StatusType eReturnCode)
{
    Fls_LLDReturnType eLldRetVal;

    /* Translate the return code from IPV to HLD */
    switch (eReturnCode)
    {
        case STATUS_FTFC_FLS_IP_SUCCESS:
            /* Operation succeeded */
            eLldRetVal = FLASH_E_OK;
            break;

        case STATUS_FTFC_FLS_IP_BUSY:
            /* Operation is pending */
            eLldRetVal = FLASH_E_PENDING;
            break;

        case STATUS_FTFC_FLS_IP_ERROR_BLANK_CHECK:
            /* Content of flash memory doesn't match with erased value */
            eLldRetVal = FLASH_E_BLOCK_INCONSISTENT;
            (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_VERIFY_ERASE_FAILED);
            break;

        case STATUS_FTFC_FLS_IP_ERROR_PROGRAM_VERIFY:
            /* Content of flash memory doesn't match with data buffer */
            eLldRetVal = FLASH_E_BLOCK_INCONSISTENT;
            (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_VERIFY_WRITE_FAILED);
            break;

        default:
            /* Operation failed due to hardware error */
            eLldRetVal = FLASH_E_FAILED;
            break;
    }

    return eLldRetVal;
}

#if ( (STD_ON == FLS_ECC_CHECK) || (STD_ON == FLS_ECC_CHECK_BY_AUTOSAR_OS) )
Fls_CompHandlerReturnType Fls_IPW_DsiHandler(const Fls_ExceptionDetailsType  *pExceptionDetailsPtr)
{
    Fls_CompHandlerReturnType eLldRetVal;

    #if ( FTFC_ECC_SYNDROME_AND_DATA_ADDRESS_CHECK == STD_ON )
    eLldRetVal = Ftfc_Fls_Ip_DsiHandler(pExceptionDetailsPtr);
    #else
    (void)pExceptionDetailsPtr;  /* Unused variable */
    eLldRetVal = Ftfc_Fls_Ip_DsiHandler();
    #endif

    return eLldRetVal;
}
#endif /* (STD_ON == FLS_ECC_CHECK) || (STD_ON == FLS_ECC_CHECK_BY_AUTOSAR_OS) */

#if (STD_ON == FLS_ECC_CHECK_BY_AUTOSAR_OS)
/**
 * Function Name : Fls_IPW_CopyBlock
 * Description   : Call the FlsReadFunctionCallout where user can schedule a task which performs the copy operation (Fls_ReadEachBlock)
 *
 */
static Ftfc_Fls_Ip_StatusType Fls_IPW_CopyBlock(uint32 u32LogicalAddress, uint32 u32Length, uint8 *pDestAddressPtr, const uint8 *pSourceAddressPtr)
{
    /* Prepare for the copy operation */
    Fls_CopyDescr.u32ReadStartAddress = u32LogicalAddress;
    Fls_CopyDescr.u32Length           = u32Length;
    Fls_CopyDescr.pDataDest           = pDestAddressPtr;
    Fls_CopyDescr.pDataSource         = pSourceAddressPtr;
    Fls_CopyDescr.eStatus             = STATUS_FTFC_FLS_IP_ERROR;

    /* This callout can schedule a task which performs the copy operation. The amount of data to copy (u32Length) can be arbitrarily long.
     * If the copy fails because of the expected exception, the task is forcibly terminated from the ProtectionHook().
     */
    Fls_pConfigPtr->FlsReadFunctionCallout();

    return Fls_CopyDescr.eStatus;
}

/**
 * Function Name : Fls_IPW_ReadEachBlock
 * Description   : Performs the actual copy operation.
 */
void Fls_IPW_ReadEachBlock(void)
{
    if (NULL_PTR != Fls_CopyDescr.pDataDest)
    {
        /* Read operation */
        Fls_CopyDescr.eStatus = Ftfc_Fls_Ip_Read(Fls_CopyDescr.u32ReadStartAddress, Fls_CopyDescr.pDataDest, Fls_CopyDescr.u32Length);
    }
    else
    {
        /* Compare operation */
        Fls_CopyDescr.eStatus = Ftfc_Fls_Ip_Compare(Fls_CopyDescr.u32ReadStartAddress, Fls_CopyDescr.pDataSource, Fls_CopyDescr.u32Length);
    }
}
#endif /* STD_ON == FLS_ECC_CHECK_BY_AUTOSAR_OS */

#endif /* (STD_ON == FLS_INTERNAL_SECTORS_CONFIGURED) */

#if ( STD_ON == FLS_AC_LOAD_ON_JOB_START )
Fls_BlockNumberOfSectorType Fls_IPW_GetBlockNumberFromAddress(Fls_AddressType targetAddress)
{
    /* Get block number from address  */
    return (Fls_BlockNumberOfSectorType)Ftfc_Fls_Ip_GetBlockNumberFromAddress((uint32)targetAddress);
}
#endif /* STD_ON == FLS_AC_LOAD_ON_JOB_START */

#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
