/*!
 * \file     PWBCbit.h
 * \brief    declares the functions of the PWBCbit sub-module
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

#ifndef PWB_PWBCBIT_H_
#define PWB_PWBCBIT_H_

/* ---- Includes ---- */
#include "TYPedef.h"

/* ---- Defines ---- */
typedef enum
{
    Lv_Voltage_Meas_Mux = 0,
    Hv_Current_Meas_Mux = 0,
    Hv_Voltage_Meas_Mux = 1,
    Hv_Temp_Meas_Mux = 2
} PWB_MuxAddressE;

typedef struct
{
    uint16_t ReadMeasResultRaw;
    int32_t ReadMeasResultHMI;
} PWBCbit_CmdsResultsStr;

/* ---- Global variables ---- */
#ifndef PWBCBIT_SUBMODULE
extern PWBCbit_CmdsResultsStr PWBCbit_cmdResults;
extern boolean PWB_psValidState;
#else
PWBCbit_CmdsResultsStr PWBCbit_cmdResults;
boolean PWB_psValidState;
#endif

/* ---- Global functions ---- */
void PWBCbit_Init(void);

void PWBCbit_GetLvMeasures(uint8_t muxAdd);
void PWBCBit_UpdatePsValidState(void);
void PWBCbit_GetHvMeasures(uint8_t muxAdd);

void PWBCbit_Deinit(void);

#endif /* PWB_PWBCBIT_H_ */
