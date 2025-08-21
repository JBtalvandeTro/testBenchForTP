/*!
 * \file     COM_Rx.c
 * \brief    File containing all functions needed toprocess the received frames
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

/* ---- Includes ---- */
#include "COM.h"
#include "COMrx.h"
#include "ACT.h"
#include "CBUs.h"
#include "CNV.h"
#include "DBG.h"

/* ---- Defines ---- */

/* ---- Global variables ---- */

/* ---- External functions ---- */

/* ---- Static variables ---- */

/* ---- Static functions ---- */
static void com_ReceivedManagement(void);
static void com_UpdateErrors(void);
static uint8_t com_GetFrameIndex(uint8_t controllerId, uint32_t frameId);
static void com_HandleMaintenanceEquipmentTestRequest(
        CBU_FrameStatusStr currentFrame);
static void com_HandleMaintenanceParameterRequest(
        CBU_FrameStatusStr currentFrame);
static void com_ControlReceivedManagement(CBU_FrameStatusStr currentFrame);
static void com_InternalReceivedManagement(CBU_FrameStatusStr currentFrame);
static void com_MaintenanceReceivedManagement(CBU_FrameStatusStr currentFrame);

/*LDRA_HEADER_END*/
/*!     \brief Periodic Rx Task
 *       \param none
 *       \return none
 */
void COM_RxTask(void)
{
    // Clear pending requests
    COM_flags.moduleFlags.status.flags.maintenanceRequestEnter = false;
    COM_flags.moduleFlags.status.flags.maintenanceRequestExit = false;
    COM_flags.moduleFlags.status.flags.settingRequestEnter = false;
    COM_flags.moduleFlags.status.flags.settingRequestExit = false;

    // Manage Rx
    com_ReceivedManagement();

    // Update errors
    com_UpdateErrors();
}

/*!     \brief Get frame before processing
 *       \param CAN controller ID, and frame ID
 *       \return frame index
 */
static uint8_t com_GetFrameIndex(uint8_t controllerId, uint32_t frameId)
{
    uint8_t frame;
    uint8_t index = 0;
    uint8_t ret = 0xFF;
    COM_FrameStr *framesTable = COM_framesControl;
    uint8_t framesCount;

    switch (controllerId)
    {
        case CBU_CONTROLCAN:
            framesTable = COM_framesControl;
            framesCount = (uint8_t) COM_FRAMES_CONTROL_COUNT;
            break;

        case CBU_INTERNALCAN:
            framesTable = COM_framesInternal;
            framesCount = (uint8_t) COM_FRAMES_INTERNAL_COUNT;
            break;

        case CBU_MAINTENANCECAN:
            framesTable = COM_framesMaintenance;
            framesCount = (uint8_t) COM_FRAMES_MAINTENANCE_COUNT;
            break;

        default:
            /* Set frames count to 0 to jump directly to return */
            framesCount = 0;
            break;
    }

    // Check all frames' id
    for (frame = 0; frame < framesCount; frame++)
    {
        // If the ID is corresponding to received one
        /* LDRA_INSPECTED 47 S <justification start> No bound exceeded <justification end> */
        if (framesTable[frame].id == frameId)
        {
            // Catch the frame
            ret = index;
        }
        else
        {
            index++;
        }
    }
    return ret;
}

/*!     \brief Update Errors flags for Error frame
 *       \param none
 *       \return none
 */
static void com_UpdateErrors(void)
{
    uint32_t timeoutControl;
    uint32_t timeoutInternal;

    timeoutControl = PAR_paramConfig[PAR_CONTROLCAN_TIMEOUT].realVal.unsignedVal
            * 100;
    timeoutInternal =
            PAR_paramConfig[PAR_INTERNALCAN_TIMEOUT].realVal.unsignedVal * 100;
    /* Clear all faults */
    if (COM_flags.moduleFlags.status.flags.errorResetRequest == true)
    {
        COM_flags.moduleFlags.faults.all = 0;
        COM_controlComLostCounter = 0;
        COM_internalComLostCounter = 0;
        CNV_powercoreUnitTable[0].comLostCounter = 0;
        CNV_powercoreUnitTable[1].comLostCounter = 0;
    }
    else
    {
        /* Nothing to do */
    }

    /* Check if the Control com lost counter is too high and if the controller is initialized / used */
    if ((CBU_flags.status.canCInitialized == true)
            && (((COM_controlComLostCounter >= timeoutControl)
                    && (timeoutControl != 0))
                    || (CBU_flags.status.canCComLost == true)))
    {
        COM_flags.moduleFlags.faults.flags.canCComLoss = true;
    }
    else
    {
        COM_flags.moduleFlags.faults.flags.canCComLoss = false;
    }

    /* Check if the Internal com lost counter is too high and if the controller is initialized / used */
    if ((CBU_flags.status.canIInitialized == true)
            && (((CNV_powercoreUnitTable[0].comLostCounter >= timeoutInternal)
                    && (timeoutInternal != 0))
                    || ((CNV_powercoreUnitTable[1].comLostCounter
                            >= timeoutInternal) && (timeoutInternal != 0))
                    || (CBU_flags.status.canIComLost == true)))
    {
        COM_flags.moduleFlags.faults.flags.canIComLoss = true;
    }
    else
    {
        COM_flags.moduleFlags.faults.flags.canIComLoss = false;
    }
}

/*!     \brief  Management function for received data for each controller
 *       \param none
 *       \return none
 */
static void com_ReceivedManagement(void)
{
    uint16_t mailbox;
    CBU_FrameStatusStr currentFrame;
    boolean frameReceivedCcontrol = false;
    boolean frameReceivedCinternalCOMETI1 = false;
    boolean frameReceivedCinternalCOMETI2 = false;

    /* For each configured mailbox */
    for (mailbox = 0; (Can_HwHandleType) mailbox < CBU_MAILBOXES_COUNT;
            mailbox++)
    {
        // Only check Receive frames
        if ((Can_Config_Init.Can_pHwObjectConfig[mailbox].Can_HohType
                == CAN_RECEIVE)
                && (CBU_framesStatus[mailbox].isPending == true))
        {
            /* Variable to simplify coding and comprehension */
            currentFrame = CBU_framesStatus[mailbox];

            switch (currentFrame.idController)
            {
                // When the frame has been received on Control
                case CBU_CONTROLCAN:
                    com_ControlReceivedManagement(currentFrame);
                    frameReceivedCcontrol = true;
                    break;

                    // When the frame has been received on Internal
                case CBU_INTERNALCAN:
                    com_InternalReceivedManagement(currentFrame);
                    uint8_t powercoreUnitAddress = CBU_powerCoreAdd;
                    uint8_t powercoreUnitIndex = CNV_getPowercoreUnitsIndex(
                            powercoreUnitAddress);
                    if (powercoreUnitIndex == 0x00)
                    {
                        frameReceivedCinternalCOMETI1 = true;
                    }
                    else if (powercoreUnitIndex == 0x01)
                    {
                        frameReceivedCinternalCOMETI2 = true;
                    }
                    break;
                    // When the frame has been received on Maintenance
                case CBU_MAINTENANCECAN:
                    com_MaintenanceReceivedManagement(currentFrame);
                    break;

                default:
                    // Do Nothing
                    break;
            }

            /* Clear pending flag */
            CBU_ClearPendingFlag(mailbox);
        }
    }

    // No frame received for CAN 1
    if (frameReceivedCcontrol == false)
    {
        COM_controlComLostCounter += 10U;
    }

    // No frame received for CAN 2
    if (frameReceivedCinternalCOMETI1 == false)
    {
        CNV_powercoreUnitTable[0].comLostCounter += 10U;
    }
    else
    {
        CNV_powercoreUnitTable[0].comLostCounter = 0;
    }

    if (frameReceivedCinternalCOMETI2 == false)
    {
        CNV_powercoreUnitTable[1].comLostCounter += 10U;
    }
    else
    {
        CNV_powercoreUnitTable[1].comLostCounter = 0;
    }
}

/*!     \brief  Management function for received data on Control controller
 *       \param received frame
 *       \return none
 */
static void com_ControlReceivedManagement(CBU_FrameStatusStr currentFrame)
{
    uint8_t frame;
    uint32_t lenghtFrame;
    uint32_t currentLenghtFrame;
    uint8_t order = 0;
    frame = com_GetFrameIndex(CBU_CONTROLCAN, currentFrame.frameId);

    // Reset Com Lost counter because a frame has been received
    COM_controlComLostCounter = 0;
    /* LDRA_INSPECTED 47 S <justification start> we return a exceeded value in case of inappropriate frame <justification end> */
    lenghtFrame = COM_framesControl[frame].FrameLenght;
    currentLenghtFrame = currentFrame.frameLength;

    if (currentLenghtFrame == lenghtFrame)
    {
        /* LDRA_INSPECTED 123 S <justification start> Explicit conversion <justification end> */
        switch ((COM_FramesControlNameE) frame)
        {
            case COM_FRAME_CONTROL_RX_PTCUCMDS:
                CBU_GetControlPtcuCmdsFrameData(currentFrame.buffer,
                        &COM_mode.bbauxCommand);
                switch (COM_mode.bbauxCommand)
                {
                    case COM_BBAUXCMD_BOOST:
                        COM_flags.moduleFlags.status.flags.boostRequest = true;
                        COM_flags.moduleFlags.status.flags.shutDownReq = false;
                        COM_flags.moduleFlags.status.flags.buckRequest = false;
                        COM_flags.moduleFlags.status.flags.stopRequest = false;
                        break;
                    case COM_BBAUXCMD_BUCK:
                        COM_flags.moduleFlags.status.flags.buckRequest = true;
                        COM_flags.moduleFlags.status.flags.shutDownReq = false;
                        COM_flags.moduleFlags.status.flags.boostRequest = false;
                        COM_flags.moduleFlags.status.flags.stopRequest = false;
                        break;
                    case COM_BBAUXCMD_STOP:
                        COM_flags.moduleFlags.status.flags.stopRequest = true;
                        COM_flags.moduleFlags.status.flags.shutDownReq = false;
                        COM_flags.moduleFlags.status.flags.buckRequest = false;
                        COM_flags.moduleFlags.status.flags.boostRequest = false;
                        break;
                    case COM_BBAUXCMD_SHUTDOWN:
                        COM_flags.moduleFlags.status.flags.shutDownReq = true;
                        COM_flags.moduleFlags.status.flags.stopRequest = false;
                        COM_flags.moduleFlags.status.flags.buckRequest = false;
                        COM_flags.moduleFlags.status.flags.boostRequest = false;
                        break;
                    default:
                        // Do Nothing
                        break;
                }
                break;

            case COM_FRAME_CONTROL_RX_ERRORRESETREQ:
                COM_flags.moduleFlags.status.flags.errorResetRequest = true;
                COM_flags.moduleFlags.faults.all = 0;
                COM_errorsAndWarnings.bbauxErrors = 0;
                COM_errorsAndWarnings.bbauxWarnings = 0;
                COM_errorsAndWarnings.powercoreErrors = 0;
                COM_errorsAndWarnings.powercoreWarnings = 0;
                break;

            default:
                // Do Nothing
                break;
        }
    }
}

/*!     \brief  Management function for received data on secondary controller
 *       \param received frame
 *       \return none
 */
static void com_InternalReceivedManagement(CBU_FrameStatusStr currentFrame)
{

    uint8_t frame;
    uint8_t powercoreUnitAddress;
    uint8_t powercoreUnitIndex;
    boolean frameReceivedUni = false;
    uint32_t lenghtFrame;
    uint32_t currentLenghtFrame;
    uint8_t order = 0;

    frame = com_GetFrameIndex(CBU_INTERNALCAN,
            currentFrame.frameId & 0xFFFFFF00); // Mask Powercore unit's Address in messageIds
    lenghtFrame = COM_framesInternal[frame].FrameLenght;
    currentLenghtFrame = currentFrame.frameLength;

    // Reset Com Lost counter because a frame has been received
    COM_internalComLostCounter = 0;
    powercoreUnitAddress = 0xFF;
    powercoreUnitIndex = 0xFF;

    if (currentLenghtFrame == lenghtFrame)
    {
        // Get Source Powercore unit (less significant byte of messageIds)
        powercoreUnitAddress = CBU_powerCoreAdd;
        powercoreUnitIndex = CNV_getPowercoreUnitsIndex(powercoreUnitAddress);

        COM_flags.moduleFlags.faults.flags.unkownCOMETi = false;

        if (powercoreUnitIndex != 0xFF)
        {
            /* LDRA_INSPECTED 123 S <justification start> Explicit conversion <justification end> */
            switch (frame)
            {
                case COM_FRAME_INTERNAL_RX_CURRENTMEAS:
                    CNV_GetInternalCurrentMeasuresFrame(currentFrame.buffer,
                            powercoreUnitIndex);
                    break;

                case COM_FRAME_INTERNAL_RX_POWERMEAS:
                    CNV_GetInternalPowerMeasuresFrame(currentFrame.buffer,
                            powercoreUnitIndex);
                    break;

                case COM_FRAME_INTERNAL_RX_TEMPERATUREMEAS:
                    CNV_GetInternalTemperatureMeasuresFrame(currentFrame.buffer,
                            powercoreUnitIndex);
                    break;

                case COM_FRAME_INTERNAL_RX_VOLTAGEMEAS:
                    CNV_GetInternalVoltageMeasuresFrame(currentFrame.buffer,
                            powercoreUnitIndex);
                    break;

                case COM_FRAME_INTERNAL_RX_REGULATIONINFO:
                    CNV_GetInternalRegulationInfoFrame(currentFrame.buffer,
                            powercoreUnitIndex);
                    break;

                case COM_FRAME_INTERNAL_RX_CONTROLINFO:
                    CNV_GetInternalControlInfoFrame(currentFrame.buffer,
                            powercoreUnitIndex);
                    break;

                case COM_FRAME_INTERNAL_RX_ERRORS:
                    CNV_GetInternalErrorsFrame(currentFrame.buffer,
                            powercoreUnitIndex);
                    break;

                case COM_FRAME_INTERNAL_RX_WARNINGS:
                    CNV_GetInternalWarningsFrame(currentFrame.buffer,
                            powercoreUnitIndex);
                    break;

                default:
                    // Do Nothing
                    break;
            }
        }
        else
        {
            COM_flags.moduleFlags.faults.flags.unkownCOMETi = true;
        }
    }
}

/*!     \brief  Management function for received data on maintenance controller
 *       \param received frame
 *       \return none
 */
static void com_MaintenanceReceivedManagement(CBU_FrameStatusStr currentFrame)
{

    uint8_t frame;
    frame = com_GetFrameIndex((uint8_t) CBU_MAINTENANCECAN,
            currentFrame.frameId);

    /* LDRA_INSPECTED 123 S <justification start> Explicit conversion <justification end> */
    switch ((COM_FramesMaintenanceNameE) frame)
    {
        case COM_FRAME_MAINTENANCE_RX_EQUIPTESTREQ:
            com_HandleMaintenanceEquipmentTestRequest(currentFrame);
            break;

        case COM_FRAME_MAINTENANCE_RX_PARAMETERREQ:
            // Manage parameter requests
            com_HandleMaintenanceParameterRequest(currentFrame);
            break;

        default:
            /* Nothing to do */
            break;
    }

}

/*!
 *      \brief Function in charge of Debug/Test requests on Maintenance CAN bus
 *      \param current request frame to process
 *      \return none
 */
static void com_HandleMaintenanceEquipmentTestRequest(
        CBU_FrameStatusStr currentFrame)
{
    uint8_t reqType = 0;

    /* If no request is in progress */
    if (DBG_Flags.proccesingFlags.processed == false)
    {
        CBU_GetMaintenanceEquipmentTestRequest(currentFrame.buffer, &reqType,
                &COM_debugTestReq.muxAddress, &COM_debugTestReq.measFormat,
                &COM_debugTestReq.relaySwitchCmd,
                &COM_debugTestReq.relaySwitchId,
                &COM_debugTestReq.discreteIoCmd, &COM_debugTestReq.discreteIoId,
                &COM_debugTestReq.ledCmd, &COM_debugTestReq.ledId,
                &COM_debugTestReq.ledColor, &COM_debugTestReq.ledBlinkFreq);

        /* What is the action requested */
        /* LDRA_INSPECTED 123 S <justification start> Explicit Conversion  <justification end> */
        switch ((COM_DebugTestReqTypeE) reqType)
        {
            case COM_DBG_REQ_RELAYSWITCH:
                COM_debugTestReq.relaySwitchTestRequest = true;
                break;

            case COM_DBG_REQ_HVMEASURES:
                COM_debugTestReq.hvMeasuresTestRequest = true;
                break;

            case COM_DBG_REQ_LVMEASURES:
                COM_debugTestReq.lvMeasuresTestRequest = true;
                break;

            case COM_DBG_REQ_DISCRETEIOS:
                COM_debugTestReq.discreteIosTestRequest = true;
                break;

            case COM_DBG_REQ_LEDS:
                COM_debugTestReq.ledsTestRequest = true;
                break;

                /* The action is incorrect, don't process it and clear everything. */
            default:
                COM_debugTestReq.relaySwitchTestRequest = false;
                COM_debugTestReq.hvMeasuresTestRequest = false;
                COM_debugTestReq.lvMeasuresTestRequest = false;
                COM_debugTestReq.discreteIosTestRequest = false;
                COM_debugTestReq.ledsTestRequest = false;
                break;
        }
    }
    else
    {
        /* Nothing to do */
    }
}

/*!
 *      \brief Function in charge of Parameter requests on Maintenance CAN bus
 *      \param current request frame to process
 *      \return none
 */
static void com_HandleMaintenanceParameterRequest(
        CBU_FrameStatusStr currentFrame)
{
    uint8_t reqType = 0;

    /* If no request is in progress */
    if (PAR_paramReq.processed == false)
    {
        CBU_GetMaintenanceParameterRequest(currentFrame.buffer, &reqType,
                &COM_paramReq.index, &COM_paramReq.value);

        /* What is the action requested */
        /* LDRA_INSPECTED 123 S <justification start> Explicit Conversion  <justification end> */
        switch ((COM_ParReqTypeE) reqType)
        {
            case COM_PAR_REQ_READ:
                COM_paramReq.readRequest = true;
                break;

            case COM_PAR_REQ_UPDATE:
                COM_paramReq.changeRequest = true;
                break;

            case COM_PAR_REQ_SAVE:
                COM_paramReq.saveRequest = true;
                break;
                /* The action is incorrect, don't process it and clear everything. */
            default:
                COM_paramReq.readRequest = false;
                COM_paramReq.changeRequest = false;
                COM_paramReq.saveRequest = false;
                break;
        }
    }
}
