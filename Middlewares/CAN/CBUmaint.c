 /*!
 * \file     CBU_Maintenance.c
 * \brief    Middleware layer dedicated to maintenance CAN bus
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

/* ---- Includes ---- */
#include "CBUmaint.h"
#include "COM.h"
#include "CBUs.h"

/* ---- Defines ---- */

#define BUFFER_MAX_SIZE 64U

/* ---- Global variables ---- */

/* ---- External functions ---- */

/* ---- Static variables ---- */

/* ---- Static functions ---- */

/*LDRA_HEADER_END*/

/*!     \brief   Send Parameter Response Frame
 *       \param  id + datas
 *       \return none
 */
void CBU_SendMaintenanceEquipmentTestResponse()
{
    uint32_t id_value =
            COM_framesMaintenance[COM_FRAME_MAINTENANCE_TX_EQUIPTESTRESP].id
                    + CAN_EXTENDED_ID_U32;
    uint8_t buffer[BUFFER_MAX_SIZE];
    uint8_t index = 0;
    Can_PduType local_pduInfo;
    uint16_t swPduHandle = 0; // No need to be change


    if (COM_debugTestReq.measFormat == COM_DBG_MEASFORMAT_RAW)
    {
        CBU_SET_UINT32(buffer, index, COM_debugTestReq.rawMeasure); // return the format wanted by the user
    }
    else
    {
        CBU_SET_UINT32(buffer, index, COM_debugTestReq.hmiMeasure);
    }


    index += 4U; // incrementing the index by 4 the measurments occupy 4 bytes
    // formatting the buffer according to the DBC
    buffer[index++] = (uint8_t) (((COM_debugTestReq.discreteIoId & 0x0F) << 4) + ((COM_debugTestReq.discreteIosPWMResult & 0x03) << 2) + (COM_debugTestReq.discreteIosReadResult & 0x03));
    buffer[index++] = (uint8_t) (((COM_debugTestReq.relaySwitchId & 0x03) << 2) + (COM_debugTestReq.relaySwitchResult & 0x03));
    CBU_CreatePduInfo(id_value, swPduHandle, index, buffer, &local_pduInfo);

    CBU_SendFrame(local_pduInfo, Can_Maint_Frame_Tx_EquipmentTest);
}

/*!     \brief   Send Parameter Response Frame
 *       \param  id + datas
 *       \return none
 */
void CBU_SendMaintenanceParameterResponse(uint16_t paramId, uint32_t ParamValue,
                                          boolean status)
{
    uint32_t id_value =
            COM_framesMaintenance[COM_FRAME_MAINTENANCE_TX_PARAMETERRESP].id
                    + CAN_EXTENDED_ID_U32;
    uint8_t buffer[BUFFER_MAX_SIZE];
    uint8_t index = 0;
    Can_PduType local_pduInfo;
    uint16_t swPduHandle = 0; // No need to be change

    // formatting the buffer according to the DBC
    CBU_SET_UINT32(buffer, index, ParamValue);
    index += 4U;
    CBU_SET_UINT16(buffer, index, paramId);
    index += 2U;
    buffer[index++] = (uint8_t) status & 0x03;

    CBU_CreatePduInfo(id_value, swPduHandle, index, buffer, &local_pduInfo);

    CBU_SendFrame(local_pduInfo, Can_Maint_Frame_Tx_Paramter);
}

/*!     \brief   Get Equipment Test Request Frame
 *       \param  input : buffer pointer
 *               output : request type + request's parameters
 *       \return none
 */
void CBU_GetMaintenanceEquipmentTestRequest(const uint8_t buffer[],
                                            uint8_t *testCmd,
                                            uint8_t *muxAddress,
                                            uint8_t *measFormat,
                                            uint8_t *relaySwitchCmd,
                                            uint8_t *relaySwitchId,
                                            uint8_t *discreteIoCmd,
                                            uint8_t *discreteIoId,
                                            uint8_t *ledCmd, uint8_t *ledId,
                                            uint8_t *ledColor,
                                            uint8_t *ledBlinkFreq)
{
    uint8_t byte = 0;

    byte = buffer[0];
    *testCmd = byte & 0x0F; // reading the Test cmd from the Buffer

    byte >>= 4;
    *muxAddress = byte & 0x07; // reading the MuxAddress from the Buffer

    byte >>= 3;
    *measFormat = byte & 0x01; // reading the measFormat (RAW OR HMI) from the Buffer

    byte = buffer[1];
    *relaySwitchCmd = byte & 0x0F; // reading the relay Switch cmd from the Buffer

    byte >>= 4;
    *relaySwitchId = byte & 0x03; // reading the relay Switch Id from the Buffer

    byte = buffer[2];
    *discreteIoCmd = byte & 0x0F; // reading the DSIO cmd from the Buffer

    byte >>= 4;
    *discreteIoId = byte & 0x0F; // reading the DSIO Id from the Buffer

    *ledBlinkFreq = buffer[3]; // reading the Blink Freq from the Buffer Unused for the moment

    byte = buffer[4];
    *ledCmd = byte & 0x03; // reading the Led Cmd from the Buffer (ON/ OFF)

    byte >>= 2;
    *ledId = byte & 0x03; // reading the LED id from the Buffer

    byte >>= 2;
    *ledColor = byte & 0x01; // reading the Color of the led from the Buffer Unused for the moment
}

/*!     \brief   Get Parameter Request Frame
 *       \param  input : buffer pointer
 *               output : request type + request's parameters
 *       \return none
 */
void CBU_GetMaintenanceParameterRequest(const uint8_t buffer[],
                                        uint8_t *reqType, uint16_t *id,
                                        uint32_t *value)
{
    *value = CBU_GET_UINT32(buffer, 0); // reading the new value of the PAR from the Buffer Unused for the moment
    *id = CBU_GET_UINT16(buffer, 4); // reading the ID of the PAR from the Buffer Unused for the moment
    *reqType = buffer[6] & 0x03; // reading the request for the PAR from the Buffer Unused for the moment (update, save, read)
}
