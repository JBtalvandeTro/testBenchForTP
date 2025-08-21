/*!
 * \file     PAR.c
 * \brief    PARameter Management module. Allows to update and save parameters
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

/* ---- Includes ---- */
#define PAR_MODULE
#include "PAR.h"
#include "PARupdat.h"
#include "PARcheck.h"
#include "ACT.h"
#include "FLA.h"
/* ---- Defines ---- */

/* ---- Global variables ---- */

/* ---- External functions ---- */
extern const uint32_t App_SwVersionRomStart;
extern const uint32_t App_BootVersionRomStart;

/* ---- Static variables ---- */

/* ---- Static functions ---- */
static FLA_PartitionIdE par_FetchActiveFlashPartition(void);

/*LDRA_HEADER_END*/
/*!     \brief Initialization of PARameter Management Module
 *       \param none
 *       \return none
 */
void PAR_Init(void)
{
    uint32_t index;
    PAR_ErrorsE error;
    uint16_t calcCrc;
    bool writeAtInit;
    bool flashUpToDate;

    /* Reset Data */
    PAR_paramReq.processed = false;
    PAR_paramReq.index = 0;
    PAR_flags.moduleFlags.faults.flags.flashValueError = false;
    writeAtInit = false;
    flashUpToDate = true;

    /* Fetch param active flash partition */
    PAR_currentFlashPartition = par_FetchActiveFlashPartition();

    if(PAR_currentFlashPartition < FLA_PARTITION_COUNT)
    {
        /* read all params values */
        (void)FLA_Read(PAR_currentFlashPartition, 0, (uint8_t*)PAR_ParamValues, 4U*PAR_TABLE_SIZE);

        /* calculate CRC */
        calcCrc = PAR_CalculateCRC((uint8_t*)PAR_ParamValues, 4U*PAR_CRC_INDEX);

        /* if a main partition is valid */
        if(calcCrc == (uint16_t)PAR_ParamValues[PAR_CRC_INDEX])
        {
            // First, update PAR_paramConfig[] array with PAR_ParamValues[] array
            for (index = 0; index < (uint32_t)PAR_COUNT; index++)
            {
                PAR_paramConfig[index].realVal.unsignedVal = PAR_ParamValues[index];
            }

            // Then, check consistency with PAR_paramConfig[) array updated
            // Both "for" loops are necessary - can't be optimized
            for (index = 0; index < (uint32_t)PAR_COUNT; index++)
            {
                /* Check if value is within range and consistency with other parameters */
                error = PAR_CheckIsValueAllowed(index, PAR_paramConfig[index].realVal);

                if (error == PAR_ERROR_NO_ERROR)
                {
                }
                else
                {
                    // Set the value to default
                    PAR_paramConfig[index].realVal = PAR_paramConfig[index].defaultVal;
                    PAR_ParamValues[index] = PAR_paramConfig[index].defaultVal.unsignedVal;
                    PAR_flags.moduleFlags.faults.flags.flashValueError = true;
                }
            }

            /* If parametres are correct */
            if (FALSE == PAR_flags.moduleFlags.faults.flags.flashValueError )
            {
                /* Check if Bootloader flag is APPLI_MODE */
                if (PAR_ParamValues[PAR_BOOT_FLAG] != (uint32_t)PAR_APPL_MODE )
                {
                    /* Update boot loader flag and number of writing cycle */
                    PAR_paramConfig[PAR_BOOT_FLAG].realVal.unsignedVal = (uint32_t)PAR_APPL_MODE;
                    PAR_ParamValues[PAR_BOOT_FLAG] = (uint32_t)PAR_APPL_MODE;

                    /* Set flag to write parameters in flash */
                    flashUpToDate = false;
                    writeAtInit = true;
                }
            }
        }
        else
        {
            /* Try load backup params */
            //TODO backup params instead of defaults
            for (index = 0; index < (uint32_t)PAR_COUNT; index++)
            {
                // Set default value
                PAR_paramConfig[index].realVal = PAR_paramConfig[index].defaultVal;
                PAR_ParamValues[index] = PAR_paramConfig[index].defaultVal.unsignedVal;
            }

            PAR_flags.moduleFlags.faults.flags.flashValueError = true;
        }
    }
    else
    {
        PAR_flags.moduleFlags.faults.flags.flashValueError = true;
        /* Try load backup params */
        //TODO backup params instead of defaults
        for (index = 0; index < (uint32_t)PAR_COUNT; index++)
        {
            // Set default value
            PAR_paramConfig[index].realVal = PAR_paramConfig[index].defaultVal;
            PAR_ParamValues[index] = PAR_paramConfig[index].defaultVal.unsignedVal;
        }
    }
    // Specific initialization of parameters
    PAR_paramConfig[PAR_SW_VERSION].realVal.unsignedVal = App_SwVersionRomStart;
    PAR_paramConfig[PAR_BOOTLOADER_VERSION].realVal.unsignedVal = App_BootVersionRomStart;

    PAR_writeAtInit = writeAtInit;
    PAR_flashUpToDate = flashUpToDate;
}


/*!     \brief Deinitialization of PARameter Management Module
 *       \param none
 *       \return none
 */
/*LDRA_INSPECTED 65 D <justification start> Deinit function - always present for maintenability <justification end> */
void PAR_Deinit(void)
{
    /* Nothing to do */
}

/*!     \brief Fetch the active flash partition for parameters
 *       \param none
 *       \return FLA_PartitionIdE
 */
static FLA_PartitionIdE par_FetchActiveFlashPartition(void)
{
    FLA_PartitionIdE partition;

    uint32_t specificWord1 = 0;
    uint32_t specificWord2 = 0;

    // read specific word from main partition 1
    (void)FLA_Read(PAR_MAIN_PARTITION1, 4U*PAR_SPECIFIC_WORD_INDEX,
            (uint8_t*) &specificWord1, 4U);

    // read specific word from main partition 2
    (void)FLA_Read(PAR_MAIN_PARTITION2, 4U*PAR_SPECIFIC_WORD_INDEX,
            (uint8_t*) &specificWord2, 4U);
            
    /*LDRA_INSPECTED 139 S <justification start> Ensure only one partition is active <justification end> */
    if (specificWord1 == PAR_SPECIFIC_WORD)
    {
        /*LDRA_INSPECTED 139 S <justification start> Ensure only one partition is active <justification end> */
        if (specificWord2 != PAR_SPECIFIC_WORD)
        {
            /* Main partition 1 is used */
            partition = PAR_MAIN_PARTITION1;
        }
        else
        {
            /* Unreachable case: both partitions can't be valid */
            partition = FLA_PARTITION_COUNT;
        }
    }
    /*LDRA_INSPECTED 139 S <justification start> Ensure only one partition is active <justification end> */
    else if (specificWord2 == PAR_SPECIFIC_WORD)
    {
        /* Main partition 2 is used */
        partition = PAR_MAIN_PARTITION2;
    }
    else
    {
        /* Unreachable case: error */
        partition = FLA_PARTITION_COUNT;
    }
    return partition;
}

/*!     \brief calculate crc16-ccitt-false for a given byte array
 *       \param data : pointer to byte array
 *       \param len : length of data array
 *       \param crc : pointer to crc16 variable
 *       \return none
 */
uint16_t PAR_CalculateCRC(const uint8_t *data, uint32_t len)
{
    static const Crc_ChannelConfigType par_crcConfig = { .Protocol = CRC_PROTOCOL_16BIT_CCITT_FALSE };

    uint16_t crc = 0;

    // Configure CRC HW
    Crc_SetChannelConfig(CRC_LOGIC_CHANNEL_0, &par_crcConfig);

    // Calculate CRC
    crc = (uint16_t) Crc_SetChannelCalculate(CRC_LOGIC_CHANNEL_0, data, len, 0U, true);

    return crc;
}
