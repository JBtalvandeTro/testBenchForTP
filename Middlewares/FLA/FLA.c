/*!
 * \file     FLA.c
 * \brief    Internal Flash middleware source file.
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

/* ---- Includes ---- */
#include "FLA.h"
#include "SchM_Fls.h"
#include "Fls.h"
#include "S32K148_LMEM.h"

/* ---- Defines ---- */

///     \brief Internal Flash page size in bytes
#if 0
#define FLA_PAGE_SIZE_BYTES 8U
#endif

/*!
 *         \brief Flash memory parition type definition.
 *         \details A Flash partition is basically defined by a start and end address on the flash.
 *                  It corresponds to a Fls logical sector.
 * 
 */
typedef struct
{
    Fls_AddressType startAddress;
    Fls_AddressType endAddress;
} Fla_PartitionStr;

/* ---- Global variables ---- */

///  Boolean variable to indicate whether Internal Flash middleware is initialized.
boolean FLA_Initialized;

/* ---- External functions ---- */

/* ---- Static variables ---- */
///  Partitions table.
static Fla_PartitionStr fla_PartitionsTable[FLA_PARTITION_COUNT];

/* ---- Static functions ---- */
static FLA_StatusE fla_CheckPartitionId(FLA_PartitionIdE partition);
static FLA_StatusE fla_CheckAddressRange(FLA_PartitionIdE partition, uint32_t addressOffset, uint32_t size);
static FLA_StatusE fla_ExecuteJob(void);
static void fla_CacheSetup(void);

/*LDRA_HEADER_END*/
/*!      \brief     Inits Fla middleware.
 *       \details   This fucntion initializes the Fls driver and the partition table of Fla middleware.
                    If initialisation is succesfull (alternatively failed), this function sets the FLA_Initialized global 
                    variable to true (alternatively false).
 *       \param     None
 *       \return    None
 */
void FLA_Init(void)
{
    uint8_t i;
    MemIf_StatusType status;

    /*LDRA_INSPECTED 128 D <justification start> endAdresses verified before use <justification end> */
    const Fls_AddressType *endAdresses = *(Fls_Config_Init.paSectorEndAddr);

    FLA_Initialized = false;

    /* assert number of Fls logical sectors is the same Fla number of partitions */
    if (Fls_Config_Init.u32SectorCount == (Fls_SectorCountType)FLA_PARTITION_COUNT)
    {
        if(endAdresses != NULL)
        {
            fla_CacheSetup();

            /* init Fla partitions table*/
            fla_PartitionsTable[FLA_PARTITION_0].startAddress = 0U;
            /*LDRA_INSPECTED 436 S <justification start> endAddresses pointer table <justification end> */
            fla_PartitionsTable[FLA_PARTITION_0].endAddress = endAdresses[FLA_PARTITION_0];

            for (i = 1; i < (uint8_t)FLA_PARTITION_COUNT; i++)
            {
                /*LDRA_INSPECTED 436 S <justification start> endAddresses pointer table <justification end> */
                fla_PartitionsTable[i].startAddress = endAdresses[i - 1] + 1;
                /*LDRA_INSPECTED 436 S <justification start> endAddresses pointer table <justification end> */
                fla_PartitionsTable[i].endAddress = endAdresses[i];
            }

            /* Init Fls */
            Fls_Init(&Fls_Config_Init);

            /* check Fls status */
            status = Fls_GetStatus();

            if (status == MEMIF_IDLE)
            {
                /* set the value of FLA_Initialized */
                FLA_Initialized = true;
            }
        }

    }
    else
    {
        /* nothing to do, FLA uninitialized : FLA_Initialized = false */
    }
}

/*!      \brief     De-inits Flash driver
 *       \param     None
 *       \return    None
 */
void FLA_Deinit(void)
{
    FLA_Initialized = false;
}


/*!
 *         \brief Get flash memory partition size in bytes.
 * 
 *         \param partition : Partition ID
 *         \param size : Pointer to the size of the parition
 *         \return FLA_StatusE 
 */
FLA_StatusE Fla_GetPartitionSize(FLA_PartitionIdE partition, uint32_t *size)
{
    FLA_StatusE check = fla_CheckPartitionId(partition);

    if (check == FLA_OK)
    {
        *size = fla_PartitionsTable[partition].endAddress - fla_PartitionsTable[partition].startAddress + 1;
    }
    return check;
}

/*!
 *         \brief Erase flash memory parition
 * 
 *         \param partition : partition ID
 *         \return FLA_StatusE 
 */
FLA_StatusE FLA_Erase(FLA_PartitionIdE partition)
{
    FLA_StatusE retStatus;
    uint32_t startAdd;
    uint32_t size;
    Std_ReturnType status;
    FLA_StatusE check;

    retStatus = FLA_NOT_OK;

    /* check Fla initialization */
    if (FLA_Initialized == true)
    {
        check = fla_CheckPartitionId(partition);

        if (check == FLA_OK)
        {
            /* calculate start address and size for Fls_Erase function */
            startAdd = fla_PartitionsTable[partition].startAddress;
            size = fla_PartitionsTable[partition].endAddress - startAdd + 1;

            /* initiate Fls_erase Job */
            status = Fls_Erase(startAdd, size);

            /* if job initiated, then execute it */
            if (status == E_OK)
            {
                retStatus = fla_ExecuteJob();
            }
            else
            {
                /* Nothing to do, job not initiated : retStatus = FLA_NOT_OK*/
            }
        }
        else
        {
            /* Nothing to do, invalid partition : retStatus = FLA_NOT_OK*/
        }
    }

    else
    {
        /* nothing to do, Fla not initialized : retStatus = FLA_NOT_OK */
    }

    return retStatus;
}

/*!
 *         \brief Write bytes to partition
 * 
 *         \param partition : parition Id
 *         \param offset : offset address relative to the partition, should be 8-bytes aligned.
 *         \param dataBuffer : pointer to byte-array to write.
 *         \param size : size of the byte-array, should be 8-bytes aligned.
 *         \return FLA_StatusE 
 * 
 */
/*LDRA_INSPECTED 256 S <justification start> For clarity reasons, no changes to be made <justification end> */
FLA_StatusE FLA_Write(FLA_PartitionIdE partition, uint32_t offset, const uint8 *dataBuffer, uint32_t size)
{
    FLA_StatusE retStatus;
    uint32_t startAdd;
    Std_ReturnType status;

    retStatus = FLA_NOT_OK;

    /* check Fla initialisation */
    if (FLA_Initialized == true)
    {
        /* Check address and size range validity */
        if (fla_CheckAddressRange(partition, offset, size) == FLA_OK)
        {
            /* calculate start address for Fls_Write function */
            startAdd = fla_PartitionsTable[partition].startAddress + offset;

            /* initiate Fls_Write Job */
            status = Fls_Write(startAdd, dataBuffer, size);

            /* if job initiated, then execute it */
            if (status == E_OK)
            {
                retStatus = fla_ExecuteJob();
            }
            else
            {
                /* Nothing to do, job not initiated : retStatus = FLA_NOT_OK*/
            }
        }
        else
        {
            /* nothing to do, erroneous range : retStatus = FLA_NOT_OK */
        }
    }

    else
    {
        /* nothing to do, Fla not initialized : retStatus = FLA_NOT_OK */
    }

    return retStatus;
}

#if 0
/*!
 *         \brief Erase the whole flash partition and then write bytes into it.
 *         \details This function erases the whole partition and then write bytes into it starting 
 *                  from the first address of the partition. 
 * 
 *         \param partition : Partition ID
 *         \param dataBuffer : Pointer to data buffer
 *         \param size : size of data buffer, doesn't need to be 8-byte aligned. 
 *         \return FLA_StatusE 
 */
FLA_StatusE FLA_Program(FLA_PartitionIdE partition, uint8 *dataBuffer, uint32_t size)
{
    FLA_StatusE retStatus, tempStatus1, tempStatus2;
    uint8_t helperBuffer[FLA_PAGE_SIZE_BYTES] = {0};
    uint32_t alignedSize;
    uint32_t remainder;

    remainder = size % FLA_PAGE_SIZE_BYTES;
    alignedSize = size - remainder;

    /* partition is erased first */
    tempStatus1 = FLA_Erase(partition);

    /* if erase succeeded */
    if (tempStatus1 == FLA_OK)
    {

        tempStatus2 = FLA_OK;

        /* if size > 8, then alignedSize > 8 and alignedSize%8 == 0 */
        if (alignedSize > 0U)
        {
            /* write first part which is dataBuffer[0 : alignedSize] */
            tempStatus1 = FLA_Write(partition, 0U, dataBuffer, alignedSize);
        }
        else
        {
            /* Nothing to do */
        }

        /* if size is not 8 byte aligned, the 0 < remainder < 8 */
        if (remainder > 0U)
        {
            /* copy second part dataBuffer[alignedSize : size] into helperBuffer */
            for (uint32_t i = 0; i < remainder; i++)
            {
                helperBuffer[i] = dataBuffer[alignedSize + i];
            }

            /* write second part */
            tempStatus2 = FLA_Write(partition, alignedSize, helperBuffer, FLA_PAGE_SIZE_BYTES);
        }
        else
        {
            /* Nothing to do, no remainder */
        }

        /* check status for write operations */
        if ((tempStatus1 != FLA_OK) || (tempStatus2 != FLA_OK))
        {
            retStatus = FLA_NOT_OK;
        }
        else
        {
            retStatus = FLA_OK;
        }
    }
    else
    {
        /* erase failed */
        retStatus = FLA_NOT_OK;
    }

    return retStatus;
}
#endif

/*!
 *         \brief Read bytes from partition
 * 
 *         \param partition : parition Id
 *         \param offset : offset address relative to the partition.
 *         \param dataBuffer : pointer to byte array to write.
 *         \param size : size of the byte array.
 *         \return FLA_StatusE 
 * 
 */
/*LDRA_INSPECTED 120 D <justification start> Cannot modify in generated files <justification end> */
FLA_StatusE FLA_Read(FLA_PartitionIdE partition, uint32_t offset,
                     uint8 *dataBuffer, uint32_t size)
{
    FLA_StatusE retStatus;
    uint32_t startAdd;
    Std_ReturnType status;

    retStatus = FLA_NOT_OK;

    /* check Fla initialization */
    if (FLA_Initialized == true)
    {
        /* Check partition, address and size range validity */
        if (fla_CheckAddressRange(partition, offset, size) == FLA_OK)
        {
            /* calculate start address for Fls_Read function */
            startAdd = fla_PartitionsTable[partition].startAddress + offset;

            /* initiate Fls_Read Job */
            status = Fls_Read(startAdd, dataBuffer, size);

            /* if job initiated, then execute it */
            if (status == E_OK)
            {
                retStatus = fla_ExecuteJob();
            }
            else
            {
                /* Nothing to do, job not initiated : retStatus = FLA_NOT_OK*/
            }
        }
        else
        {
            /* nothing to do, erroneous range : retStatus = FLA_NOT_OK */
        }
    }

    else
    {
        /* nothing to do, Fla not initialized : retStatus = FLA_NOT_OK */
    }

    return retStatus;
}

/*!
 *         \brief Checks validity of partition ID.
 * 
 *         \param partition : Partition ID
 *         \return FLA_StatusE 
 */
static FLA_StatusE fla_CheckPartitionId(FLA_PartitionIdE partition)
{
    FLA_StatusE check = FLA_OK;

    if (partition >= FLA_PARTITION_COUNT)
    {
        check = FLA_NOT_OK;
    }

    return check;
}

/*!
 *         \brief Check if address offset and size makes a valied range within a partition.
 * 
 *         \param partition : Partition ID
 *         \param addressOffset : Address offset
 *         \param size : Number of bytes 
 *         \return FLA_StatusE 
 */
static FLA_StatusE fla_CheckAddressRange(FLA_PartitionIdE partition, uint32_t addressOffset, uint32_t size)
{
    FLA_StatusE check = FLA_OK;
    uint32_t startAdd;
    uint32_t endAdd;
    check = fla_CheckPartitionId(partition);
    if (check == FLA_NOT_OK)
    {
        /* nothing to do, jump to return : check  = FLA_NOT_OK */
    }
    else
    {
        startAdd = fla_PartitionsTable[partition].startAddress;
        endAdd = fla_PartitionsTable[partition].endAddress;

        if ((startAdd + addressOffset + size) > endAdd)
        {
            check = FLA_NOT_OK;
        }
        else
        {
            /* nothing to do */
        }
    }

    return check;
}

/*!      \brief Execute a pending Fls job synchronously.
 *       \details This function is to be called after initiating a Read or Write Job.
 *       It calls @Fls_MainFunction routine till no job is pending.
 *       \param None
 *       \return FLA_StatusE
 *       \retval FLA_OK : Job ended successfully.
 *       \retval FLA_NOT_OK : Job ended with error.
 */
static FLA_StatusE fla_ExecuteJob(void)
{
    FLA_StatusE retStatus;
    MemIf_StatusType memStatus;
    MemIf_JobResultType result;

    retStatus = FLA_NOT_OK;

    /* Execute Fls Main Function, while polling for flash status till it becomes IDLE */
    do
    {
        Fls_MainFunction();
        memStatus = Fls_GetStatus();
    }
    while (memStatus != MEMIF_IDLE);

    /* Check job status */
    result = Fls_GetJobResult();

    if (result == MEMIF_JOB_OK)
    {
        retStatus = FLA_OK;
    }
    else
    {
        retStatus = FLA_NOT_OK;
    }
    return retStatus;
}

/*!
 *         \brief Disable cache on R2 bank of the flash memory.
 * 
 */
/*LDRA_INSPECTED 65 D <justification start> Register update <justification end> */
static void fla_CacheSetup(void)
{
    /* Disable cache on R2 bank: as S32K148 FlexNVMs region is not cacheable */
    /*LDRA_INSPECTED 440 S <justification start> Due to register update <justification end> */
    IP_LMEM->PCCRMR &= (uint32_t)(~LMEM_PCCRMR_R2_MASK);
}
