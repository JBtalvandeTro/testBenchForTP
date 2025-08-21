/*!
 * \file     CBUs.c
 * \brief    CAN Bus middleware main file
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

/* ---- Includes ---- */
#define CBU_MIDDLEWARE
#include "CBUs.h"
#include "CanIf_Can.h"
#include "CNV.h"

/* ---- Defines ---- */

/* ---- Global variables ---- */

/* ---- External functions ---- */

/* ---- Static variables ---- */

/* ---- Static functions ---- */
void CanIf_ControllerBusOff(uint8 ControllerId)
{
    /* If Control CAN */
    if (ControllerId == CBU_CONTROLCAN)
    {
        CBU_flags.status.canCComLost = true;
    }
    else if (ControllerId == CBU_INTERNALCAN)
    {
        CBU_flags.status.canIComLost = true;
    }
    else if (ControllerId == CBU_MAINTENANCECAN)
    {
        CBU_flags.status.canMComLost = true;
    }
    else
    {
        // Do nothing we only have 3 CAN controllers
    }
}

/*!     \brief Irq handler for Mode Indication - Defined by drivers CHECK MCAL definition
 *       \param none
 *       \return none
 */
void CanIf_ControllerModeIndication(uint8 ControllerId,
                                    Can_ControllerStateType ControllerMode)
{
    (void) ControllerId;
    (void) ControllerMode;
}

/*!     \brief Irq notification for Tx Confirmation
 *       \param none
 *       \return none
 */
void CanIf_TxConfirmation(PduIdType CanTxPduId)
{
    (void) CanTxPduId;
}

/*!     \brief Irq notification for Rx - Defined by drivers
 *      \param Mailbox which received the frame / PduInfoPtr which contains frame details
 *      \return none
 */
void CanIf_RxIndication(const Can_HwType *Mailbox,
                        const PduInfoType *PduInfoPtr)
{
    uint16_t index;

    /* Check if received frame is dedicated to us thanks to address */
    if (((CBU_framesStatus[Mailbox->Hoh].idController == CBU_CONTROLCAN)
            && (Mailbox->CanId & 0x03) == CBU_Address)
            || (CBU_framesStatus[Mailbox->Hoh].idController == CBU_INTERNALCAN)
            || (CBU_framesStatus[Mailbox->Hoh].idController
                    == CBU_MAINTENANCECAN))
    {
        /* Copy frame Length */
        CBU_framesStatus[Mailbox->Hoh].frameLength = PduInfoPtr->SduLength;

        /* Set frame status to pending */
        CBU_framesStatus[Mailbox->Hoh].isPending = true;

        /* Copy payload data into frame buffer */
        for (index = 0; index < CBU_framesStatus[Mailbox->Hoh].frameLength;
                index++)
        {
            CBU_framesStatus[Mailbox->Hoh].buffer[index] =
                    PduInfoPtr->SduDataPtr[index];
        }

        if (CBU_framesStatus[Mailbox->Hoh].idController == CBU_INTERNALCAN)
        { // getting the CAN ADD of the COMETi
            CBU_powerCoreAdd = Mailbox->CanId & 0xFF;
        }
        else
        {
            /* Nothing to do just continue */
        }
    }
    else
    {
        // Do Nothing
    }
}

/*!     \brief  Create PDU info
 *       \param  CAN controllerID
 */
void CBU_CreatePduInfo(Can_IdType id, PduIdType swPduHandle, uint8 length,
                       uint8 *sdu, Can_PduType *pduInfoPtr)
{
    pduInfoPtr->id = id;
    pduInfoPtr->swPduHandle = swPduHandle;
    pduInfoPtr->length = length;
    pduInfoPtr->sdu = sdu;
}

/*!     \brief CAN middleware init
 *       \param none
 *       \return none
 */
void CBU_Init(boolean cStart, boolean iStart, boolean mStart)
{
    uint8_t local_controller = 0;
    uint16_t mailbox;
    uint16_t hwObject;
    Can_ControllerStateType state;

    /* Clear flags */
    CBU_flags.all = 0;

    /* ------------- CAN Control ------------- */
    if (cStart == true)
    {
        state = CAN_CS_STARTED;
    }
    else
    {
        state = CAN_CS_STOPPED;
    }

    /* Configure active controllers : let default baudrate */
    if (Can_SetControllerMode(CBU_CONTROLCAN, state) == E_OK)
    {
        CBU_flags.status.canCInitialized = cStart;
        CBU_flags.status.middlewareInitialized = cStart;
    }

    /* ------------- CAN Internal ------------- */
    if (iStart == true)
    {
        state = CAN_CS_STARTED;
    }
    else
    {
        state = CAN_CS_STOPPED;
    }

    /* Configure active controllers : let default baudrate */
    if (Can_SetControllerMode(CBU_INTERNALCAN, state) == E_OK)
    {
        CBU_flags.status.canIInitialized = iStart;
        CBU_flags.status.middlewareInitialized = iStart;
    }

    /* ------------- CAN Maintenance ------------- */
    if (mStart == true)
    {
        state = CAN_CS_STARTED;
    }
    else
    {
        state = CAN_CS_STOPPED;
    }

    /* Configure active controllers : let default baudrate */
    if (Can_SetControllerMode(CBU_MAINTENANCECAN, state) == E_OK)
    {
        /* Middleware initialized */
        CBU_flags.status.canMInitialized = mStart;
        CBU_flags.status.middlewareInitialized = mStart;
    }

    for (local_controller = 0; local_controller < CBU_NBCAN; local_controller++)
    {
        /* Setup all frame structures thanks to generated resources */
        for (mailbox = 0;
                mailbox
                        < Can_Config_Init.Can_ppController[local_controller]->Can_u8HwObjectRefCount;
                mailbox++)
        {
            hwObject =
                    Can_Config_Init.Can_ppController[local_controller]->Can_ppHwObject[mailbox]->Can_HwObjectID;
            CBU_framesStatus[hwObject].idController = local_controller;
            CBU_framesStatus[hwObject].frameId =
                    Can_Config_Init.Can_ppController[local_controller]->Can_ppHwObject[mailbox]->Can_pHwFilterConfig->Can_u32HwFilterCode;
            CBU_framesStatus[hwObject].frameDir =
                    Can_Config_Init.Can_ppController[local_controller]->Can_ppHwObject[mailbox]->Can_HohType;
            CBU_framesStatus[hwObject].isPending = false;
            CBU_framesStatus[hwObject].frameLength = 0;
        }
    }

    CBU_Address = 0x00;
}

/*!     \brief CAN middleware deinit
 *       \param none
 *       \return none
 */
void CBU_Deinit(void)
{
    /* Check if all controllers have stopped */
    if (Can_SetControllerMode(CBU_CONTROLCAN, CAN_CS_STOPPED) == E_OK)
    {
        if (Can_SetControllerMode(CBU_INTERNALCAN, CAN_CS_STOPPED) == E_OK)
        {
            if (Can_SetControllerMode(CBU_MAINTENANCECAN,
                    CAN_CS_STOPPED) == E_OK)
            {
                /* Middleware uninitialized */
                CBU_flags.status.middlewareInitialized = false;
            }
        }
    }
}

/*!     \brief Check errors for each controllers
 *       \param CAN controllerID
 *       \return none
 */
void CBU_CheckErrors(void)
{
    Can_ErrorStateType errors[CBU_NBCAN] = { 0 };
    uint8_t local_controller;

    /* Check status for each controller */
    for (local_controller = 0; local_controller < CBU_NBCAN; local_controller++)
    {
        (void) Can_GetControllerErrorState(local_controller,
                &errors[local_controller]);
    }

    /* if Control is in BusOff */
    if (errors[CBU_CONTROLCAN] == CAN_ERRORSTATE_BUSOFF)
    {
        CBU_flags.status.canCComLost = true;
    }
    else
    {
        CBU_flags.status.canCComLost = false;
    }

    /* if Internal is in BusOff */
    if (errors[CBU_INTERNALCAN] == CAN_ERRORSTATE_BUSOFF)
    {
        CBU_flags.status.canIComLost = true;
    }
    else
    {
        CBU_flags.status.canIComLost = false;
    }

    /* if Maintenance is in BusOff */
    if (errors[CBU_MAINTENANCECAN] == CAN_ERRORSTATE_BUSOFF)
    {
        CBU_flags.status.canMComLost = true;
    }
    else
    {
        CBU_flags.status.canMComLost = false;
    }
}

/*!     \brief  Clear selected pending flag
 *       \param  Mailbox which shall be cleared
 *       \return none
 */
void CBU_ClearPendingFlag(uint16_t mailbox)
{
    CBU_framesStatus[mailbox].isPending = false;
}

/*!     \brief  Send Frame
 *       \param  mailbox and data
 *       \return none
 */
void CBU_SendFrame(Can_PduType pdu, uint8_t mailbox)
{
    (void) Can_Write(mailbox, &pdu);
}

/*!     \brief  CanIf_CurrentIcomConfiguration
 *       \param  mailbox and data
 *       \return none
 */
/*LDRA_INSPECTED 65 D <justification start> Function for future use <justification end> */
void CanIf_CurrentIcomConfiguration(uint8 ControllerId,
                                    IcomConfigIdType ConfigurationId,
                                    IcomSwitch_ErrorType Error)
{
    /* Prevent warnings about unused parameters */
    (void) ControllerId;
    (void) ConfigurationId;
    (void) Error;

    /* Nothing to do */
}

/*!     \brief  Set bitrate
 *       \param  canPort concerned ,the enumeration of the bitrate configuration and the desired state of the configured port
 *       \return none
 */
void CBU_SetBitrate(uint8_t canPort, uint16_t bitrate, uint32_t finalState)
{
    uint16_t bitrate_value = bitrate;
    Std_ReturnType ret;

    if (Can_Config_Init.Can_ppController != NULL)
    {
        const Can_ControllerConfigType *l_controller =
                Can_Config_Init.Can_ppController[canPort];

        // If the bitrate index is in the good range
        if (bitrate_value >= l_controller->Can_u16BaudrateConfigCount)
        {
            bitrate_value = CBU_BR_500KBPS; // Default value
        }

        if (Can_SetControllerMode(canPort, CAN_CS_STOPPED) == E_OK)
        {

            (void) Can_SetBaudrate(canPort, bitrate_value);
            /*LDRA_INSPECTED 91 D <justification start> ret Used to verify the state Can mode <justification end> */
            /*LDRA_INSPECTED 123 S <justification start> Explicit Conversion <justification end> */
            ret = Can_SetControllerMode(canPort,
                    (Can_ControllerStateType) finalState);

            switch (canPort)
            {
                case CBU_CONTROLCAN:
                    if ((ret == E_OK) && (finalState > 0))
                    {
                        CBU_flags.status.canCInitialized = true;
                    }
                    else
                    {
                        CBU_flags.status.canCInitialized = false;
                    }
                    break;

                case CBU_INTERNALCAN:
                    if ((ret == E_OK) && (finalState > 0))
                    {
                        CBU_flags.status.canIInitialized = true;
                    }
                    else
                    {
                        CBU_flags.status.canIInitialized = false;
                    }
                    break;

                case CBU_MAINTENANCECAN:
                    if ((ret == E_OK) && (finalState > 0))
                    {
                        CBU_flags.status.canMInitialized = true;
                    }
                    else
                    {
                        CBU_flags.status.canMInitialized = false;
                    }
                    break;

                default:
                    // Do nothing
                    break;
            }
        }
        else
        {
            // Do nothing
        }
    }
}

/*!     \brief  Check the length of used payload
 *       \param  frame length
 *       \return none
 */
uint8_t CBU_CheckLength(uint8_t length)
{
    uint8_t frameLength = 0;

    if (length <= 8)
    {
        frameLength = length;
    }
    else
    {
        if (length <= 12)
        {
            // In CASE FD CAN
        }
        else
        {
            if (length <= 16)
            {
                // In CASE FD CAN
            }
        }
    }

    return frameLength;
}

