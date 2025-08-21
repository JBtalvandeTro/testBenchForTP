/*!
 * \file     CBU_Internal.c
 * \brief    Middleware layer dedicated to internal CAN bus
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

/* ---- Includes ---- */
#include "CBUinter.h"
#include "COM.h"
#include "CBUs.h"
#include "CNV.h"
#include "FSM.h"
#include "PAR.h"
#include "PWB.h"

/* ---- Defines ---- */

/* ---- Global variables ---- */

/* ---- External functions ---- */

/* ---- Static variables ---- */
static uint32_t currentSetpoint[2] = {0,0}; // table for 2 cometi units

/* ---- Static functions ---- */

/*!     \brief   Send Internal Control Request Frame
 *       \param  index of Powercore unit
 *       \return none
 */
void CBU_SendInternalControlRequestFrameCOMETiUnits(uint8_t powerCoreUnit)
{
    uint32_t id_value = 0;
    if (powerCoreUnit == 0)
    {
        id_value =
                COM_framesInternal[COM_FRAME_INTERNAL_TX_CONTROLREQCOMETI1].id;
    }
    else if (powerCoreUnit == 1)
    {
        id_value =
                COM_framesInternal[COM_FRAME_INTERNAL_TX_CONTROLREQCOMETI2].id;
    }
    else
    {
        // Undefined COMETI unit
    }

    uint8_t buffer[64];
    Can_PduType local_pduInfo;
    uint16_t swPduHandle = 0; // No need to be changed
    uint8_t index = 0;

    uint32_t setpointTarget =
            CNV_powercoreUnitTable[powerCoreUnit].request.setpoint;
    uint32_t setpointRamp = 0;
    uint32_t currentStateOfCometi = 0;

    if (FSM_mode == FSM_MODE_BOOST)
    {
        currentStateOfCometi = (uint32_t) (PWB_measures.VHv_Cometi / 10); // the cometi units have a foctor of 10
        setpointRamp = PAR_paramConfig[PAR_BOOST_RAMP].realVal.unsignedVal;
        if (currentSetpoint[powerCoreUnit] < currentStateOfCometi)
        {
            currentSetpoint[powerCoreUnit] = currentStateOfCometi;
        }
        else
        {
            // do nothing we already requesting a higher value
        }
    }
    else if (FSM_mode == FSM_MODE_BUCK)
    {
        currentStateOfCometi = (uint32_t) (PWB_measures.VLv_Cometi / 10); // the cometi units have a foctor of 10
        setpointRamp = PAR_paramConfig[PAR_BUCK_RAMP].realVal.unsignedVal;
        if (currentSetpoint[powerCoreUnit] < currentStateOfCometi)
        {
            currentSetpoint[powerCoreUnit] = currentStateOfCometi;
        }
        else
        {
            // do nothing we already requesting a higher value
        }

    }
    else
    {
        setpointRamp = 0;
        currentSetpoint[powerCoreUnit] = 0;
    }

    if (currentSetpoint[powerCoreUnit] < setpointTarget)
    {
        currentSetpoint[powerCoreUnit] += setpointRamp;
    }
    else
    {
        /* we hit the target we shouldn't over go the setpoint */
        currentSetpoint[powerCoreUnit] = setpointTarget;
    }

    // preparing the buffer Check the DBC file
    buffer[index++] = CNV_powercoreUnitTable[powerCoreUnit].request.startOrder;
    CBU_SET_UINT32(buffer, index, currentSetpoint[powerCoreUnit] * 10); // *10 is for the factor in the DBC 0.1 //TODO refac : create a cte for the 10 dbc factor
    index += 4U;
    CBU_SET_UINT16(buffer, index,
            CNV_powercoreUnitTable[powerCoreUnit].request.currentLimit * 10); // *10 is for the factor in the DBC 0.1 //TODO refac : create a cte for the 10 dbc factor
    index += 2U;

    // Compute ID depending on config and target Powercore unit
    id_value += CAN_EXTENDED_ID_U32;

    // Create pduInfo
    CBU_CreatePduInfo(id_value, swPduHandle, index, buffer, &local_pduInfo);

    // Send frame
    CBU_SendFrame(local_pduInfo, Can_Internal_Frame_Tx_ControlReq);
}
/*!     \brief   Send Internal Mode Request Frame
 *       \param  index of Powercore unit
 *       \return none
 */
void CBU_SendInternalModeRequestFrameCOMETiUnits(uint8_t powerCoreUnit)
{
    uint32_t id_value = 0;
    if (powerCoreUnit == 0)
    {
        id_value = COM_framesInternal[COM_FRAME_INTERNAL_TX_MODEREQCOMETI1].id;
    }
    else if (powerCoreUnit == 1)
    {
        id_value = COM_framesInternal[COM_FRAME_INTERNAL_TX_MODEREQCOMETI2].id;
    }
    else
    {
        // Undefined COMETI unit
    }
    uint8_t buffer[64];
    Can_PduType local_pduInfo;
    uint16_t swPduHandle = 0; // No need to be changed
    uint8_t index = 0;

    buffer[index++] = CNV_powercoreUnitTable[powerCoreUnit].request.regMode;
    buffer[index++] = CNV_powercoreUnitTable[powerCoreUnit].request.regType;

    // Compute ID depending on config and target Powercore unit
    id_value += CAN_EXTENDED_ID_U32;

    // Create pduInfo
    CBU_CreatePduInfo(id_value, swPduHandle, index, buffer, &local_pduInfo);

    // Send frame
    CBU_SendFrame(local_pduInfo, Can_Internal_Frame_Tx_ModeReq);
}

/*!     \brief   Send Internal Error Reset Request Frame
 *       \param  index of Powercore unit
 *       \return none
 */
void CBU_SendInternalErrorResetRequestFrameCOMETiUnits(uint8_t powerCoreUnit)
{
    uint32_t id_value = 0;
    if (powerCoreUnit == 0)
    {
        id_value =
                COM_framesInternal[COM_FRAME_INTERNAL_TX_ERRORRESETREQCOMETI1].id;
    }
    else if (powerCoreUnit == 1)
    {
        id_value =
                COM_framesInternal[COM_FRAME_INTERNAL_TX_ERRORRESETREQCOMETI2].id;
    }
    else
    {
        // Undefined COMETI unit
    }

    uint8_t buffer[64];
    Can_PduType local_pduInfo;
    uint16_t swPduHandle = 0; // No need to be changed

    // Compute ID depending on config and target Powercore unit
    id_value += (CAN_EXTENDED_ID_U32);
    uint8_t length = 0; // the length of the error reset request is 0 check the DBC file

    // Create pduInfo
    CBU_CreatePduInfo(id_value, swPduHandle, length, buffer, &local_pduInfo);

    // Send frame
    CBU_SendFrame(local_pduInfo, Can_Internal_Frame_Tx_ErrorResetReq);
}
// TODO docme
/*!     \brief   Send Internal Error mask Frame to cometi unit
 *       \param  index of Powercore unit
 *       \return none
 */
void CBU_SendInternalDisableAlarmsRequest(uint8_t powerCoreUnit,
                                          CNV_ErrorCritAndFuncMaskE errorCritMask,
                                          CNV_ErrorCritAndFuncMaskE errorFoncMask)
{
    uint32_t id_value = CBU_GetPowerCoreUnitId(powerCoreUnit);

    // Buffer init
    uint8_t buffer[64];
    Can_PduType local_pduInfo;
    uint16_t swPduHandle = 0; // No need to be changed
    uint8_t index = 0;
    uint8_t maskSize = 4U;

    // Fill buffer
    buffer[index] = errorCritMask;
    index += maskSize;

    buffer[index] = errorFoncMask;
    index += maskSize;

    // Compute ID depending on config and target Powercore unit
    id_value += CAN_EXTENDED_ID_U32;

    // Create pduInfo
    CBU_CreatePduInfo(id_value, swPduHandle, index, buffer, &local_pduInfo);

    // Send frame
    CBU_SendFrame(local_pduInfo, Can_Internal_Frame_Tx_DisableAlarmsRequest);

}

/*!     \brief   Send current measures frame
 *       \param  none
 *       \return none
 */
void CBU_GetInternalCurrentMeasuresFrameData(const uint8_t buffer[],
                                             uint16_t *iBus1, uint16_t *iBus2)
{
    *iBus1 = CBU_GET_UINT16(buffer, 0);
    *iBus2 = CBU_GET_UINT16(buffer, 2);
}

/*!     \brief   Send Measure 2 Frame
 *       \param  none
 *       \return none
 */
void CBU_GetInternalPowerMeasuresFrameData(const uint8_t buffer[],
                                           uint32_t *pBus1, uint32_t *pBus2)
{
    *pBus1 = CBU_GET_UINT32(buffer, 4);
    *pBus2 = CBU_GET_UINT32(buffer, 0);
}

/*!     \brief   Send Measure 3 Frame
 *       \param  none
 *       \return none
 */
void CBU_GetInternalTemperatureMeasuresFrameData(const uint8_t buffer[],
                                                 uint8_t *temp1, uint8_t *temp2,
                                                 uint8_t *temp3, uint8_t *temp4,
                                                 uint8_t *temp5, uint8_t *temp6,
                                                 uint8_t *temp7, uint8_t *temp8)
{
    *temp1 = buffer[0];
    *temp2 = buffer[1];
    *temp3 = buffer[2];
    *temp4 = buffer[3];
    *temp5 = buffer[4];
    *temp6 = buffer[5];
    *temp7 = buffer[6];
    *temp8 = buffer[7];
}

/*!     \brief   Send Measure 4 Frame
 *       \param  none
 *       \return none
 */
void CBU_GetInternalVoltageMeasuresFrameData(const uint8_t buffer[],
                                             uint16_t *vBus1, uint16_t *vBus2)
{
    *vBus1 = CBU_GET_UINT16(buffer, 0);
    *vBus2 = CBU_GET_UINT16(buffer, 2);
}

/*!     \brief   Send Setpoint info Frame
 *       \param  none
 *       \return none
 */
void CBU_GetInternalRegulationInfoFrameData(const uint8_t buffer[],
                                            uint8_t *softwareMode,
                                            uint32_t *setpoint,
                                            uint8_t *limitationType)
{
    *softwareMode = buffer[0];
    *setpoint = CBU_GET_UINT32(buffer, 1);
    *limitationType = buffer[5];
}

/*!     \brief   Send Control info Frame
 *       \param  none
 *       \return none
 */
void CBU_GetInternalControlInfoFrameData(const uint8_t buffer[],
                                         uint8_t *regMode, uint8_t *regType,
                                         uint16_t *currentLimit)
{
    *regMode = buffer[0];
    *regType = buffer[1];
    *currentLimit = CBU_GET_UINT16(buffer, 2);
}

void CBU_GetInternalErrorsFrameData(const uint8_t buffer[],
                                    uint32_t *criticalErrors,
                                    uint32_t *functionnalErrors)
{
    *criticalErrors = CBU_GET_UINT32(buffer, 0);
    *functionnalErrors = CBU_GET_UINT32(buffer, 4);
}

/*!     \brief   Send Warning Frame
 *       \param  buffer for the frame
 *       \param  Warrning to send
 *       \return none
 */
void CBU_GetInternalWarningsFrameData(const uint8_t buffer[],
                                      uint32_t *warnings)
{
    *warnings = CBU_GET_UINT32(buffer, 0);
}

/*!     \brief   Get the Power core unit Id
 *       \param  powerCore unit nb
 *       \return Id of the power core unit
 */
uint32_t CBU_GetPowerCoreUnitId(uint8_t powerCoreUnit)
{
    if (powerCoreUnit == 0)
    {
        return COM_framesInternal[COM_FRAME_INTERNAL_TX_ERRORRESETREQCOMETI1].id;
    }
    else if (powerCoreUnit == 1)
    {
        return COM_framesInternal[COM_FRAME_INTERNAL_TX_ERRORRESETREQCOMETI2].id;
    }
    else
    {
        // Undefined COMETI unit
        return 0;
    }
}
