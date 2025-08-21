/*!
 * \file     CBU_Control.h
 * \brief    Control CAN Bus middleware header
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

#ifndef FILE_CBUCTRL_H
#define FILE_CBUCTRL_H

/* ---- Includes ---- */
#include "CST.h"
#include "TYPedef.h"

/* ---- Defines ---- */

/* ---- Global variables ---- */

/* ---- Global functions ---- */
/* -- TX -- */
void CBU_SendControlCurrentMeasuresFrame(void);
void CBU_SendControlPowerMeasuresFrame(void);
void CBU_SendControlTemperatureMeasuresFrame(void);
void CBU_SendControlVoltageMeasuresFrame(void);
void CBU_SendControlControlStatusFrame(void);
void CBU_SendControlErrorsWarningsFrame(void);
void CBU_SendControlPbitResultsFrame(void);

/* -- RX -- */
void CBU_GetControlPtcuCmdsFrameData(const uint8_t buffer[], uint8_t *bbauxCommand, uint32_t *setpointReq, uint16_t *currentLimitReq, boolean *s3Mode);

#endif /* FILE_CBU_CONTROL_H */
