/*!
 * \file     PAR_Update.c
 * \brief    Brief description of file content
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

/* ---- Includes ---- */
#include "PAR.h"
#include "PARenum.h"
#include "PARcheck.h"
#include "PARupdat.h"
#include "ACT.h"
#include "FLA.h"

/* ---- Defines ---- */

/* ---- Global variables ---- */

/* ---- External functions ---- */

/* ---- Static variables ---- */

/* ---- Static functions ---- */
static void par_UpdateAccessRight(void);
static PAR_ErrorsE par_ManageReadVal(uint16_t param);
static PAR_ErrorsE par_ManageWriteVal(uint16_t param, uint32_t value);

/*LDRA_HEADER_END*/
/*!     \brief Periodical task which checks if an update has been requested, and if it's correct
 *       \param none
 *       \return none
 */
void PAR_Update(void)
{
    /* Reset the Errors */

    if (COM_flags.moduleFlags.status.flags.errorResetRequest == true)
    {
        PAR_paramReq.lastError = PAR_ERROR_NO_ERROR;
    }
    else
    {
        // DO nothing all the errors must remain active until the error reset is requested
    }

    /* Verify the access rights */
    par_UpdateAccessRight();

    if ((COM_paramReq.readRequest == false)
            && (COM_paramReq.saveRequest == false)
            && (COM_paramReq.changeRequest == false))
    {
        PAR_paramReq.processed = false;
    }
    else
    {
        if (PAR_paramReq.processed == false)
        {
            // If a save has been requested and the flash is not up to date
            if (COM_paramReq.saveRequest == true)
            {
                if (PAR_flashUpToDate == false)
                {
                    // if not on dedicated modes to save the parameters
                    if ((PAR_right != PAR_ACCESSRIGHT_CUSTOMER)
                            && (PAR_right != PAR_ACCESSRIGHT_SUPERUSER))
                    {
                        // Consider the frame processed to ignore it
                        PAR_paramReq.processed = true;
                        PAR_paramReq.lastError = PAR_ERROR_WRITE_ACCESS_DENIED;
                    }
                    else
                    {
                        /* Nothing to do */
                        /* PAR_paramReq.processed will be updated when calling PAR_SaveParametersInFlash() function */
                    }
                }
                // flash is up to date consider request as proceeded succesfully
                else
                {
                    PAR_paramReq.processed = true;
                    PAR_paramReq.lastError = PAR_ERROR_WRITE_ACCESS_DENIED;
                }
            }
            else
            {
                PAR_paramReq.processed = true;
                PAR_paramReq.index = COM_paramReq.index;
                PAR_paramReq.value.unsignedVal = COM_paramReq.value;

                // Handle param write request
                if ((COM_paramReq.changeRequest == true)
                        && (COM_paramReq.readRequest == false)
                        /* If new value is equal to previous value, writing is not required */
                        && (COM_paramReq.value
                                != PAR_paramConfig[COM_paramReq.index].realVal.unsignedVal))
                {
                    // Write param and clear PAR_flashUpToDate flag
                    PAR_paramReq.lastError = par_ManageWriteVal(
                            COM_paramReq.index, COM_paramReq.value);

                    if (PAR_paramReq.lastError == PAR_ERROR_NO_ERROR)
                    {
                        PAR_flashUpToDate = false;
                    }
                }
                else
                {
                    // Handle param read request
                    if ((COM_paramReq.changeRequest == false)
                            && (COM_paramReq.readRequest == true))
                    {
                        // Read param
                        PAR_paramReq.lastError = par_ManageReadVal(
                                COM_paramReq.index);
                    }
                    else
                    {
                        // Do Nothing
                    }
                }
            }
        }
        else
        {
            // Do Nothing
        }
    }
}

/*!     \brief Param module write data in flash
 *       \param None
 *       \return None
 */
void PAR_SaveParametersInFlash(void)
{
    FLA_StatusE ret;
    FLA_PartitionIdE newActivePartition;

    /* If the flash must be updated and a save request is pending or a write at start is needed */
    if (((PAR_flashUpToDate == false)
            && ((COM_paramReq.saveRequest == true) || (PAR_writeAtInit == true))
            && (PAR_paramReq.processed == false)))
    {
        /*LDRA_INSPECTED 337 S <justification start> declared in project properties <justification end> */
        WDO_Deinit(true); // stop the external WDO
        WDO_Deinit(false);// stop the internal WDO

        /* set processed flag */
        PAR_paramReq.processed = true;

        /* check used partition */
        if (PAR_currentFlashPartition == PAR_MAIN_PARTITION1)
        {
            /* switch to main partition 2 */
            newActivePartition = PAR_MAIN_PARTITION2;
        }
        else
        {
            /* switch to main partition 1 */
            newActivePartition = PAR_MAIN_PARTITION1;
        }

        ret = FLA_Erase(newActivePartition);

        if (ret == FLA_OK)
        {
            /* Update PAR_PARAM_COUNT_WR_PARAM */
            if (PAR_paramConfig[PAR_COUNT_WR].realVal.unsignedVal < 0xFFFFFFFFU)
            {
                PAR_paramConfig[PAR_COUNT_WR].realVal.unsignedVal++;
                PAR_ParamValues[PAR_COUNT_WR] =
                        PAR_paramConfig[PAR_COUNT_WR].realVal.unsignedVal;
            }
            else
            {
                /* do nothing */
            }

            /* set specific word value */
            PAR_ParamValues[PAR_SPECIFIC_WORD_INDEX] = PAR_SPECIFIC_WORD;

            /* calculate CRC */
            PAR_ParamValues[PAR_CRC_INDEX] = PAR_CalculateCRC(
                    (uint8_t*) PAR_ParamValues, 4U * PAR_CRC_INDEX);

            /* Program partition */
            ret = FLA_Write(newActivePartition, 0, (uint8_t*) PAR_ParamValues,
                    4U * PAR_TABLE_SIZE);

            if (ret == FLA_OK)
            {
                /* erase old partition */
                ret = FLA_Erase(PAR_currentFlashPartition);

                /* Set active partition to new one */
                PAR_currentFlashPartition = newActivePartition;

                if (ret != FLA_OK)
                {
                    PAR_paramReq.lastError = PAR_ERROR_STATUS_FAIL_ERASE;
                }
                else
                {
                    /* set flash up to date */
                    PAR_flashUpToDate = true;

                    /* update error status to no error */
                    PAR_paramReq.lastError = PAR_ERROR_NO_ERROR;
                }
            }

            else
            {
                PAR_paramReq.lastError = PAR_ERROR_STATUS_FAIL_PROGRAM;
            }

        }
        else
        {
            PAR_paramReq.lastError = PAR_ERROR_STATUS_FAIL_ERASE;
        }
        /* clear parameter request error */

        // Manage Boot flag request
        if (PAR_paramConfig[PAR_BOOT_FLAG].realVal.unsignedVal
                == (uint32_t) PAR_BOOT_MODE)
        {
            PAR_flags.moduleFlags.status.flags.rebootRequested = true;
        }
        else
        {
            /* Do nothing */
        }
        /*LDRA_INSPECTED 337 S <justification start> declared in project properties <justification end> */
        /* Init WDO */
        WDO_Init(false); // init internal WDO
        WDO_Management(false, false);
        /* Use external WDO */
        WDO_Init(true); // init external WDO
        WDO_Management(true, true);
    }
}

/*!     \brief Update the access rights depending on the FSM
 *       \param none
 *       \return none
 */
static void par_UpdateAccessRight(void)
{
    switch (FSM_mode)
    {
        case FSM_MODE_MAINTENANCE:
            PAR_right = PAR_ACCESSRIGHT_SUPERUSER;
            break;
        default:
            PAR_right = PAR_ACCESSRIGHT_NO_PRIVILEDGE;
            break;
    }
}

/*!     \brief Periodical task which makes the read
 *      \param param: parameter index
 *      \return error code
 */
static PAR_ErrorsE par_ManageReadVal(uint16_t param)
{
    PAR_ErrorsE error = PAR_ERROR_NO_ERROR;

    // Validation of the read access right
    error = PAR_IsValidAccess(param, PAR_READ);

    // If no error => update value
    if (error == PAR_ERROR_NO_ERROR)
    {
        PAR_paramReq.readValue = PAR_paramConfig[param].realVal;
    }
    // Else return 0
    else
    {
        PAR_paramReq.readValue.unsignedVal = UINT32_MAX;
    }

    return error;
}

/*!     \brief Periodical task which checks if an update has been requested, and if it's correct
 *      \param param: parameter index
 *      \param value: value to write
 *      \return error code
 */
static PAR_ErrorsE par_ManageWriteVal(uint16_t param, uint32_t value)
{
    PAR_ErrorsE error;
    PAR_ValueU val;

    // Check the access is valid
    error = PAR_IsValidAccess(param, PAR_WRITE);

    // If access is valid, checks if data is correct
    if (error == PAR_ERROR_NO_ERROR)
    {
        val.signedVal = value;

        /* Check if value is within range and consistency with other parameters */
        error = PAR_CheckIsValueAllowed(param, val);

        if (error == PAR_ERROR_NO_ERROR)
        {
            PAR_paramReq.index = COM_paramReq.index;
            PAR_paramReq.value.signedVal = COM_paramReq.value;

            // Update parameter value :
            PAR_paramConfig[param].realVal = PAR_paramReq.value;
            PAR_ParamValues[param] = PAR_paramReq.value.signedVal;
        }
    }

    return error;
}
