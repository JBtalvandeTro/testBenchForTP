/*!
 * \file     CBU_Maintenance.h
 * \brief    Maintenance CAN Bus middleware header
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

#ifndef FILE_CBUMAINT_H
#define FILE_CBUMAINT_H

/* ---- Includes ---- */
#include "CST.h"
#include "TYPedef.h"

/* ---- Defines ---- */

/* ---- Global variables ---- */

/* ---- Global functions ---- */
/* -- TX -- */
void CBU_SendMaintenanceEquipmentTestResponse(void);
void CBU_SendMaintenanceParameterResponse(uint16_t paramId, uint32_t ParamValue, boolean status);

/* -- RX -- */
void CBU_GetMaintenanceEquipmentTestRequest(const uint8_t buffer[],  uint8_t *testCmd, uint8_t *muxAddress, uint8_t *measFormat,
                                            uint8_t *relaySwitchCmd, uint8_t *relaySwitchId,
                                            uint8_t *discreteIoCmd, uint8_t *discreteIoId,
                                            uint8_t *ledCmd, uint8_t *ledId, uint8_t *ledColor, uint8_t *ledBlinkFreq);
void CBU_GetMaintenanceParameterRequest(const uint8_t buffer[], uint8_t *reqType,
                                    uint16_t *id, uint32_t *value);

#endif /* FILE_CBU_MAINTENANCE_H */
