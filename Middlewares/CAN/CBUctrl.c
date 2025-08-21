/*!
 * \file     CBU_Control.c
 * \brief    Middleware layer dedicated to Control CAN bus
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

/* ---- Includes ---- */
#include "CBUctrl.h"
#include "COM.h"
#include "CBUs.h"
#include "ACT.h"

/* ---- Defines ---- */

/* ---- Global variables ---- */

/* ---- External functions ---- */

/* ---- Static variables ---- */

/* ---- Static functions ---- */

/*!     \brief   Send current measures frame
 *       \param  none
 *       \return none
 */
void CBU_SendControlCurrentMeasuresFrame(void)
{
    uint32_t id_value = COM_framesControl[COM_FRAME_CONTROL_TX_CURRENTMEAS].id;
    uint8_t buffer[64];
    uint8_t index = 0;
    Can_PduType local_pduInfo;
    uint16_t swPduHandle = 0; // No need to be changed
    //Fill the buffer
    CBU_SET_UINT16(buffer, index, COM_powerMeasures.iBusHv);
    index++;
    index++;

    CBU_SET_UINT16(buffer, index, COM_powerMeasures.iBusLv);
    index+=2U;

    // Compute ID depending on config
    id_value += (CBU_Address & 0x03);

    // Create pduInfo
    CBU_CreatePduInfo(id_value, swPduHandle, index, buffer, &local_pduInfo);

    // Send frame
    CBU_SendFrame(local_pduInfo, Can_Control_Frame_Tx_CurrentMeasures);
}

/*!     \brief   Send Measure 2 Frame
 *       \param  none
 *       \return none
 */
void CBU_SendControlPowerMeasuresFrame(void)
{
    uint32_t id_value = COM_framesControl[COM_FRAME_CONTROL_TX_POWERMEAS].id;
    uint8_t buffer[64];
    uint8_t index = 0;
    Can_PduType local_pduInfo;
    uint16_t swPduHandle = 0; // No need to be changed

    // Fill buffer
    CBU_SET_UINT32(buffer, (uint8_t) index, COM_powerMeasures.pBusHv);
    index += 4;

    CBU_SET_UINT32(buffer, (uint8_t) index, COM_powerMeasures.pBusLv);
    index += 4;

    // Compute ID depending on config
    id_value += (CBU_Address & 0x03);

    // Create pduInfo
    CBU_CreatePduInfo(id_value, swPduHandle, index, buffer, &local_pduInfo);

    // Send frame
    CBU_SendFrame(local_pduInfo, Can_Control_Frame_Tx_PowerMeasures);
}


/*!     \brief   Send Measure 3 Frame
 *       \param  none
 *       \return none
 */
void CBU_SendControlTemperatureMeasuresFrame(void)
{
    uint8_t buffer[64];

    uint32_t id_value = COM_framesControl[COM_FRAME_CONTROL_TX_TEMPERATUREMEAS].id;
    uint16_t swPduHandle = 0; // No need to be changed
    Can_PduType local_pduInfo;
    uint8_t index = 0;

    buffer[index++] = (uint8_t)(COM_tempMeasures.tempNotif & 0x03);
    buffer[index++] = (uint8_t)(COM_tempMeasures.temp1Cometi);
    buffer[index++] = (uint8_t)(COM_tempMeasures.temp2Cometi);
    buffer[index++] = (uint8_t)(COM_tempMeasures.tempHvCoupler);

    // Compute ID depending on config
    id_value += (CBU_Address & 0x03);

    // Create pduInfo
    CBU_CreatePduInfo(id_value, swPduHandle, index, buffer, &local_pduInfo);

    // Send frame
    CBU_SendFrame(local_pduInfo, Can_Control_Frame_Tx_TempMeasures);
}

/*!     \brief   Send Measure 4 Frame
 *       \param  none
 *       \return none
 */
void CBU_SendControlVoltageMeasuresFrame(void)
{
    uint32_t id_value = COM_framesControl[COM_FRAME_CONTROL_TX_VOLTAGEMEAS].id;
    uint8_t buffer[64];
    Can_PduType local_pduInfo;
    uint8_t index = 0;
    uint16_t swPduHandle = 0; // No need to be changed
    CBU_SET_UINT16(buffer, (uint8_t)index, COM_powerMeasures.uBusHv);
    index+=2U;

    CBU_SET_UINT16(buffer, (uint8_t)index, COM_powerMeasures.uBusLv);
    index+=2U;

    CBU_SET_UINT16(buffer, (uint8_t)index, COM_powerMeasures.uBusHvAux);
    index+=2U;

    // Compute ID depending on config
    id_value += (CBU_Address & 0x03);

    // Create pduInfo
    CBU_CreatePduInfo(id_value, swPduHandle, index, buffer, &local_pduInfo);

    // Send frame
    CBU_SendFrame(local_pduInfo, Can_Control_Frame_Tx_VoltageMeasures);
}

/*!     \brief   Send Control info Frame
 *       \param  none
 *       \return none
 */
void CBU_SendControlControlStatusFrame(void)
{
    uint32_t id_value = COM_framesControl[COM_FRAME_CONTROL_TX_CONTROLSTATUS].id;
    uint8_t buffer[64];
    Can_PduType local_pduInfo;
    uint8_t index = 0;
    uint16_t swPduHandle = 0; // No need to be changed
    CBU_SET_UINT32(buffer, (uint8_t) index, COM_controlStatusInfo.setpoint);
    index+=4U;

    buffer[index++] = (uint8_t)(COM_controlStatusInfo.currentLimit & 0xFF);
    buffer[index++] = (uint8_t)( ((COM_controlStatusInfo.currentLimit >> 8) & 0x0F)
                               + ((COM_controlStatusInfo.limitationType & 0x03) << 4)
                               + ((COM_controlStatusInfo.lvPrechargeStatus & 0x01) << 6)
                               + ((COM_controlStatusInfo.hvCouplerStatus1 & 0x01) << 7));
    buffer[index++] = (uint8_t)( (COM_controlStatusInfo.dcdcState & 0x0F) + ((COM_controlStatusInfo.buckType & 0x03) << 4)
                               + ((COM_controlStatusInfo.powercoreUnitsNb & 0x03) << 6));
    buffer[index++] = (uint8_t)( (COM_controlStatusInfo.emerstopStatus & 0x01)
                               + ((COM_controlStatusInfo.healthStatus & 0x01) << 1));

    // Compute ID depending on config
    id_value += (CBU_Address & 0x03);

    // Create pduInfo
    CBU_CreatePduInfo(id_value, swPduHandle, index, buffer, &local_pduInfo);

    // Send frame
    CBU_SendFrame(local_pduInfo, Can_Control_Frame_Tx_ControlStatus);
}

/*!     \brief   Send Error Frame
 *       \param  none
 *       \return none
 */
void CBU_SendControlErrorsWarningsFrame(void)
{
    uint32_t id_value = COM_framesControl[COM_FRAME_CONTROL_TX_ERRORSWARNINGS].id;
    uint8_t buffer[64];
    uint32_t index = 0;
    Can_PduType local_pduInfo;
    uint16_t swPduHandle = 0; // No need to be changed

    // Fill buffer
    CBU_SET_UINT16(buffer, (uint8_t)index, COM_errorsAndWarnings.bbauxErrors);
    index+=2U;

    CBU_SET_UINT16(buffer, (uint8_t)index, COM_errorsAndWarnings.bbauxWarnings);
    index+=2U;

    CBU_SET_UINT16(buffer, (uint8_t)index, COM_errorsAndWarnings.powercoreErrors);
    index+=2U;

    buffer[index++] = (uint8_t)(COM_errorsAndWarnings.powercoreWarnings);
    buffer[index++] = (uint8_t)( (COM_errorsAndWarnings.severity & 0x03)
                               + ((COM_errorsAndWarnings.faultOrigin & 0x03) << 2));

    // Compute ID depending on config
    id_value += (CBU_Address & 0x03);

    // Create pduInfo
    CBU_CreatePduInfo(id_value, swPduHandle, index, buffer, &local_pduInfo);

    // Send frame
    CBU_SendFrame(local_pduInfo, Can_Control_Frame_Tx_ErrorsWarnings);
}

/*!     \brief   Send
 *       \param  none
 *       \return none
 */
void CBU_SendControlPbitResultsFrame(void)
{
    uint32_t id_value = COM_framesControl[COM_FRAME_CONTROL_TX_PBITRESULTS].id;
    uint8_t buffer[64];
    uint8_t index = 0;
    Can_PduType local_pduInfo;
    uint16_t swPduHandle = 0; // No need to be changed

    // Fill buffer
    CBU_SET_UINT32(buffer, (uint8_t) index, COM_pbitResultsInfo.softwareVersion);
    index+=4U;

    buffer[index++] = (uint8_t)( (COM_pbitResultsInfo.pbitStatus & 0x03)
                               + ((COM_pbitResultsInfo.lvPrechargeStatus & 0x03) << 4)
                               + ((COM_pbitResultsInfo.hvCouplerStatus & 0x03) << 6));
    buffer[index++] = (uint8_t)(COM_pbitResultsInfo.dsioStatus);

    // Compute ID depending on config
    id_value += (CBU_Address & 0x03);

    // Create pduInfo
    CBU_CreatePduInfo(id_value, swPduHandle, index, buffer, &local_pduInfo);

    // Send frame
    CBU_SendFrame(local_pduInfo, Can_Control_Frame_Tx_PbitResult);
}

/*!     \brief   Get Control frame data
 *       \param  input : buffer pointer
 *               output : current limit pointer, setpoint pointer and start command pointer
 *       \return none
 */
void CBU_GetControlPtcuCmdsFrameData(const uint8_t buffer[], uint8_t *bbauxCommand, uint32_t *setpointReq, uint16_t *currentLimitReq, boolean *s3Mode)
{
    int8_t index = 0;
    *bbauxCommand = buffer[index] & 0x07;
    index++;
    *setpointReq = CBU_GET_UINT32(buffer,index);
    index += 4U; // 32 Bit
    *currentLimitReq = CBU_GET_UINT16(buffer,index);
    index += 2U;
    *s3Mode = buffer[index];
}

/*!     \brief   Unused for the moment
 *       \param  none
 *       \return none
 */
void CBU_GetErrorResetCmdFrameData(void)
{
    // Nothing to do the Error reset request frame has no PayLoad
    // For future Use in case
}

