/*!
 * \file     SCH.h
 * \brief    SCHeduler module header
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

#ifndef FILE_SCH_H
#define FILE_SCH_H

/* ---- Includes ---- */
#include "PlatformTypes.h"

/* ---- Defines ---- */
// Scheduling counters
#define SCH_CNT_1MS     1
#define SCH_CNT_5MS     5
#define SCH_CNT_10MS    10
#define SCH_CNT_20MS    20
#define SCH_CNT_50MS    50
#define SCH_CNT_100MS   100
#define SCH_CNT_500MS   500
#define SCH_CNT_1S      1000
#define SCH_CNT_10S     10000

// Ticks per second
#define SCH_TICKS_PER_SECOND 1000

/// The structure of scheduler counters
typedef struct
{
    /// Scheduler 1ms counter
    uint32_t count1ms;
    /// Scheduler 5ms counter
    uint32_t count5ms;
    /// Scheduler 10ms counter
    uint32_t count10ms;
    /// Scheduler 20ms counter
    uint32_t count20ms;
    /// Scheduler 50ms counter
    uint32_t count50ms;
    /// Scheduler 100ms counter
    uint32_t count100ms;
    /// Scheduler 500ms counter
    uint32_t count500ms;
    /// Scheduler 1s counter
    uint32_t count1s;
    /// Scheduler 10s counter
    uint32_t count10s;
} SCH_CountersStr;

/* ---- Global variables ---- */
extern uint8_t SCH_MaxLoad;
extern uint8_t SCH_MinLoad;
extern uint8_t SCH_AverageLoad;


/* ---- Global functions ---- */
void SCH_Init(void);
void SCH_Deinit(void);
void SCH_MainLoop(void);

#ifdef SCH_MODULE

uint8_t SCH_MaxLoad;
uint8_t SCH_MinLoad;
uint8_t SCH_AverageLoad;

#endif

#endif /* FILE_SCH_H */
