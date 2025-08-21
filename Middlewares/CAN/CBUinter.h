/*!
 * \file     CBU_Internal.h
 * \brief    Secondary CAN Bus middleware header
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

#ifndef FILE_CBUINTER_H
#define FILE_CBUINTER_H

/* ---- Includes ---- */
#include "CST.h"
#include "CNV.h"
#include "TYPedef.h"

/* ---- Defines ---- */

/* ---- Global variables ---- */

/* ---- Global functions ---- */
/* -- TX -- */
void CBU_SendInternalControlRequestFrameCOMETiUnits(uint8_t powerCoreUnit);
void CBU_SendInternalModeRequestFrameCOMETiUnits(uint8_t powerCoreUnit);
void CBU_SendInternalErrorResetRequestFrameCOMETiUnits(uint8_t powerCoreUnit);
void CBU_SendInternalDisableAlarmsRequest(uint8_t powerCoreUnit, CNV_ErrorCritAndFuncMaskE errorCritMask, CNV_ErrorCritAndFuncMaskE errorFoncMask);

/* -- RX -- */
void CBU_GetInternalCurrentMeasuresFrameData(const uint8_t buffer[], uint16_t *iBus1, uint16_t *iBus2);
void CBU_GetInternalPowerMeasuresFrameData(const uint8_t buffer[], uint32_t *pBus1, uint32_t *pBus2);
void CBU_GetInternalTemperatureMeasuresFrameData(const uint8_t buffer[], uint8_t *temp1, uint8_t *temp2, uint8_t *temp3, uint8_t *temp4, uint8_t *temp5, uint8_t *temp6, uint8_t *temp7, uint8_t *temp8);
void CBU_GetInternalVoltageMeasuresFrameData(const uint8_t buffer[], uint16_t *vBus1, uint16_t *vBus2);
void CBU_GetInternalRegulationInfoFrameData(const uint8_t buffer[], uint8_t *softwareMode, uint32_t *setpoint, uint8_t *limitationType);
void CBU_GetInternalControlInfoFrameData(const uint8_t buffer[], uint8_t *regMode, uint8_t *regType, uint16_t *currentLimit);
void CBU_GetInternalErrorsFrameData(const uint8_t buffer[], uint32_t *criticalErrors, uint32_t *functionnalErrors);
void CBU_GetInternalWarningsFrameData(const uint8_t buffer[], uint32_t *warnings);

/* Internal funciton */
uint32_t CBU_GetPowerCoreUnitId(uint8_t powerCoreUnit);

#endif /* FILE CBU_INTERNAL_H */
