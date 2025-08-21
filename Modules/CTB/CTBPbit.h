/*!
 * \file     CTBPbit.c
 * \brief    declares the functions of the CTBPbit sub-module
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

#ifndef CTB_CTBPBIT_H_
#define CTB_CTBPBIT_H_

/* ---- Includes ---- */

#include "TYPedef.h"

/* ---- Defines ---- */

#define CTBPbit_READDSI_CMD    0x4
#define CTBPbit_START_CMD   0x5
#define CTBPbit_STOP_CMD    0x6

typedef enum
{
    HPP_1 = 1,
    HPP_2,
    DSI_SPARE_1,
    EMER_STOP,
    DSI_SPARE_2,
    HPP_MAINT,
    DSI_Count
} CTB_DSI_PinsE;

typedef struct
{
    boolean HPP_1_TestResult :1;
    boolean HPP_2_TestResult :1;
    boolean EMER_STOP_TestResult :1;
    boolean DSI_SPARE_1_TestResult :1;
    boolean DSI_SPARE_2_TestResult :1;
    boolean HPP_MAINT_TestResult :1;
    uint8_t reserved :2;
} CTB_DSI_TestResultStr;

/* ---- Global variables ---- */
#ifndef CTBPbit_SUBMODULE
extern CTB_DSI_TestResultStr ctb_DSI_TestResult;
extern boolean ctb_DSI_readResult;
extern boolean CTBPbit_Started;
extern boolean CTBPbit_TimePeriodEnded;
extern uint32_t dsi1_edgeCounter;
extern uint32_t dsi2_edgeCounter;
extern uint32_t dsi3_edgeCounter;
extern uint32_t dsi4_edgeCounter;
extern uint32_t dsi5_edgeCounter;
extern uint32_t dsi6_edgeCounter;
#else
CTB_DSI_TestResultStr ctb_DSI_TestResult;
boolean ctb_DSI_readResult;
boolean CTBPbit_Started;
boolean CTBPbit_TimePeriodEnded;
uint32_t dsi1_edgeCounter;
uint32_t dsi2_edgeCounter;
uint32_t dsi3_edgeCounter;
uint32_t dsi4_edgeCounter;
uint32_t dsi5_edgeCounter;
uint32_t dsi6_edgeCounter;
#endif
/* ---- Global functions ---- */

void CTBPbit_Init(void);
void CTBPbit_RunTests(void);
void CTBPbit_ReadDSI(CTB_DSI_PinsE dsiPin);
void ctbPbit_StartTestDSI(CTB_DSI_PinsE dsiPin);
void ctbPbit_StopTestDSI(CTB_DSI_PinsE dsiPin);
void CTBPbit_SetTimePeriod(void);
void CTBPbit_Deinit(void);

#endif /* CTB_CTBPBIT_H_ */
