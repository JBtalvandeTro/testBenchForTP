/*!
 * \file     PAR_Checks.c
 * \brief    Brief description of file content
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

/* ---- Includes ---- */
#include "PAR.h"
#include "ACT.h"
#include "PARcheck.h"
#include "PARupdat.h"
/* ---- Defines ---- */

/* ---- Global variables ---- */

/* ---- External functions ---- */

/* ---- Static variables ---- */

/* ---- Static functions ---- */
static PAR_ErrorsE par_IsValidParamIndex(PAR_ParamE param);
static PAR_ErrorsE par_IsValidRange(PAR_ParamE param, PAR_ValueU paramValue);

/*LDRA_HEADER_END*/
/*!
 *   \brief Check the consistency of a parameter in accordance with the others and with range allowed
 *   \param param Parameter to check
 *   \param paramValue Value of the parameter to check
 *   \return PAR_ERROR_NO_ERROR if parameter value is consistent, another error code if not
 */
PAR_ErrorsE PAR_CheckIsValueAllowed(PAR_ParamE param, PAR_ValueU paramValue)
{
    PAR_ErrorsE error;

    /* Check if value is within range */
        error = par_IsValidRange(param, paramValue);

    return(error);
}

/*!     \brief Check if the access rights are the right ones
 *       \param param index and the current access right
 *       \return Errors
 */
PAR_ErrorsE PAR_IsValidAccess(PAR_ParamE param, PAR_AccessE access)
{
    PAR_ErrorsE error;
    PAR_AccessRightE paramAccessRights;
    boolean rejected;

    /* Check parameter exists */
    error = par_IsValidParamIndex(param);

    // Check that param exists
    if (error == PAR_ERROR_NO_ERROR)
    {
        if (access == PAR_READ)
        {
            paramAccessRights = PAR_paramConfig[param].readAccessRight;
        } // access == PAR_READ
        else
        {
            paramAccessRights = PAR_paramConfig[param].writeAccessRight;
        } // else

        switch(paramAccessRights)
        {
            // If no access allowed, rejected
            case PAR_ACCESSRIGHT_NO_ACCESS:
            rejected = true;
            break;

            // If no specific rights are needed, ok
            case PAR_ACCESSRIGHT_NO_PRIVILEDGE:
            rejected = false;
            break;

            // Check if customer level rights are given
            case PAR_ACCESSRIGHT_CUSTOMER:
            if((PAR_right != PAR_ACCESSRIGHT_CUSTOMER)
                    && (PAR_right != PAR_ACCESSRIGHT_SUPERUSER))
            {
                rejected = true;
            }
            else
            {
                rejected = false;
            }
            break;

            // Check if superuser level rights are given
            case PAR_ACCESSRIGHT_SUPERUSER:
            if(PAR_right != PAR_ACCESSRIGHT_SUPERUSER)
            {
                rejected = true;
            }
            else
            {
                rejected = false;
            }
            break;

            default:
            rejected = true;
            break;
        }

        if (rejected == false)
        {
            error = PAR_ERROR_NO_ERROR;
        } // paramAccessRights & accessRight
        else
        {
            if (access == PAR_READ)
            {
                error = PAR_ERROR_READ_ACCESS_DENIED;
            } // access == PAR_READ
            else
            {
                error = PAR_ERROR_WRITE_ACCESS_DENIED;
            } // else

        } // else
    }

    return error;
}

/*!     \brief Check if the value the user wants to write is in the range of the parameter
 *       \param param index and the value
 *       \return Errors
 */
static PAR_ErrorsE par_IsValidRange(PAR_ParamE param, PAR_ValueU paramValue)
{
    // Check parameter index
    PAR_ErrorsE error = par_IsValidParamIndex(param);

    // Check that the parameter exist
    if (error == PAR_ERROR_NO_ERROR)
    {
        // For each type, compare the min and max values with the parameter value :
        switch (PAR_paramConfig[param].type)
        {
            case PAR_TYPE_UNSIGNED_32:
            case PAR_TYPE_UNSIGNED_16:
            case PAR_TYPE_UNSIGNED_8:
            if ((paramValue.unsignedVal < PAR_paramConfig[param].min.unsignedVal) ||
                (paramValue.unsignedVal > PAR_paramConfig[param].max.unsignedVal))
            {
                error = PAR_ERROR_OUT_OF_RANGE;
            }
            break;

            case PAR_TYPE_SIGNED_32:
            case PAR_TYPE_SIGNED_16:
            case PAR_TYPE_SIGNED_8:
            if ((paramValue.signedVal < PAR_paramConfig[param].min.signedVal) ||
                (paramValue.signedVal > PAR_paramConfig[param].max.signedVal))
            {
                error = PAR_ERROR_OUT_OF_RANGE;
            }
            break;

            case PAR_TYPE_FLOAT:
            if ((paramValue.floatVal < PAR_paramConfig[param].min.floatVal) ||
                (paramValue.floatVal > PAR_paramConfig[param].max.floatVal))
            {
                error = PAR_ERROR_OUT_OF_RANGE;
            }
            break;
            default:
            error = PAR_ERROR_INTERNAL_ERROR;
            break;
        }
    }

    return error;
}


/*!     \brief Check if the param index is corresponding with an existing parameter
 *       \param param index
 *       \return Errors
 */
static PAR_ErrorsE par_IsValidParamIndex(PAR_ParamE param)
{
    PAR_ErrorsE error;

    if ( param < PAR_COUNT )
    {
        error = PAR_ERROR_NO_ERROR;
    }
    else
    {
        error = PAR_ERROR_WRONG_PARAM_INDEX;
    }

    return (error);
}
