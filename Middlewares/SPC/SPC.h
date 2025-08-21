/*!
 * \file     SPC.h
 * \brief    declares the functions of the SPC middleware
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

#ifndef SPC_SPC_H_
#define SPC_SPC_H_

/* ---- Includes ---- */
#include "TYPedef.h"

/* ---- Defines ---- */
#define SPC_BUFFER_SIZE 2U // the Resolution of the ADC is 12 bits so 2 uint8_t should be enough

typedef struct
{
    uint32_t HvVoltage;
    uint32_t HvCurrent;
    uint32_t HvTemperature;
    uint32_t LvVoltage;
}SPC_ReturnMeasures;

/* ---- Global variables ---- */
#ifndef SPC_Middleware
extern SPC_ReturnMeasures Spc_returnMeasures;
#else
SPC_ReturnMeasures Spc_returnMeasures;
#endif

/* ---- Global functions ---- */
void SPC_Init(void);
void SPC_GetLvVoltageMeasures(void);
void SPC_GetHvTemperaturesMeasures(void);
void SPC_GetHvVoltageMeasures(void);
void SPC_GetHvCurrentMeasures(void);
void SPC_Deinit(void);

#endif /* SPC_SPC_H_ */
