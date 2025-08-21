/*!
 * \file     SCH.c
 * \brief    SCHeduler module main file which manages task scheduling
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

/* ---- Includes ---- */
#include "ACT.h"
#include "ACTupdat.h"
#include "FSM.h"
#include "FSMupdat.h"
#include "Mcal.h"
#include "Mcu.h"
#include "Port.h"
#include "Gpt.h"
#include "Platform.h"
#include "COM.h"
#include "COMrx.h"
#include "COMtx.h"
#include "MPM.h"
#include "PAR.h"
#include "PARupdat.h"
#include "WDO.h"
#include "CTB.h"
#include "CTBPbit.h"
#include "CTBCbit.h"
#include "PWB.h"
#include "PWBCbit.h"
#include "PWBPbit.h"
#include "DBG.h"
#include "CNV.h"
#define SCH_MODULE
#include "SCH.h"
#include "CDD_Mcl.h"
#include "Spi.h"
#include "Can.h"
#include "Pwm.h"
#include "Mcl.h"
#include "CBUs.h"
#include "FLA.h"
#include "INI.h"
#include "Dio.h"

/* ---- Defines ---- */

/* ---- Global variables ---- */

/* ---- External functions ---- */
extern void sch_Interruption(void);
extern ISR(LPIT_0_CH_0_ISR);

/* ---- Static variables ---- */
static SCH_CountersStr sch_counters;
/*LDRA_INSPECTED 25 D <justification start> No change for future use <justification end> */
volatile uint32_t sch_mainLoopElapsedTimeUs;

/* ---- Static functions ---- */
static void sch_EnterLowPower(void);
static void sch_ExitLowPower(void);
static void sch_Run1msTasks(void);
static void sch_Run5msTasks(void);
static void sch_Run10msTasks(void);
static void sch_Run20msTasks(void);
static void sch_Run50msTasks(void);
static void sch_Run100msTasks(void);
static void sch_Run500msTasks(void);
static void sch_Run1sTasks(void);
static void sch_Run10sTasks(void);
static void sch_UpdateLoadMeasures(void);

/*LDRA_HEADER_END*/
/*!     \brief Initialization of CPU Clocks and Scheduler module
 *       \param none
 *       \return none
 */
void SCH_Init(void)
{
    static uint32_t SCH_lpit0Freq;
    /* INIT load values */
    SCH_MinLoad = 100;
    SCH_MaxLoad = 0;
    SCH_AverageLoad = 0;

    /* Install IRQ */
    (void) Platform_InstallIrqHandler(LPIT0_Ch0_IRQn, &LPIT_0_CH_0_ISR,
    NULL_PTR);

    /* Get LPIT0 Freq */
    SCH_lpit0Freq = Mcu_GetClockFrequency(LPIT0_CLK);

    /* Enable the GPT notification to get the event for each trig */
    Gpt_EnableNotification(0);

    /* Start the TMR with 1ms period */
    Gpt_StartTimer(0, (SCH_lpit0Freq / SCH_TICKS_PER_SECOND));

    sch_counters.count1ms = 0;
    sch_counters.count5ms = 0;
    sch_counters.count10ms = 0;
    sch_counters.count20ms = 0;
    sch_counters.count50ms = 0;
    sch_counters.count100ms = 0;
    sch_counters.count500ms = 0;
    sch_counters.count1s = 0;
    sch_counters.count10s = 0;
    /*LDRA_INSPECTED 337 S <justification start> declared in project properties <justification end> */
    /* Init WDO */
#ifndef NDEBUG_MODE
    WDO_Init(false); // init internal WDO
    WDO_Management(false, false);
    /* Use external WDO */
    WDO_Init(true); // init external WDO
    WDO_Management(true, true);
#else

#endif
}

/*!     \brief Deinitialization of Scheduler moduleb
 *       \param none
 *       \return none
 */
void SCH_Deinit(void)
{
    /* Disable the GPT notification to stop the Irq */
    Gpt_DisableNotification(0);

    sch_counters.count1ms = 0;
    sch_counters.count5ms = 0;
    sch_counters.count10ms = 0;
    sch_counters.count20ms = 0;
    sch_counters.count50ms = 0;
    sch_counters.count100ms = 0;
    sch_counters.count500ms = 0;
    sch_counters.count1s = 0;
    sch_counters.count10s = 0;
}

/*!     \brief Main scheduler task which refreshes the flags
 *       \param none
 *       \return none
 */
void SCH_MainLoop(void)
{

    /*----------------------------------------------------------------------
     * Every 1ms
     *--------------------------------------------------------------------*/
    if (sch_counters.count1ms >= SCH_CNT_1MS)
    {
        sch_Run1msTasks();
    }

    /*----------------------------------------------------------------------
     * Every 5ms
     *--------------------------------------------------------------------*/
    if (sch_counters.count5ms >= SCH_CNT_5MS)
    {
        sch_Run5msTasks();
    }

    /*----------------------------------------------------------------------
     * Every 10ms
     *--------------------------------------------------------------------*/
    if (sch_counters.count10ms >= SCH_CNT_10MS)
    {
        sch_Run10msTasks();
    }

    /*----------------------------------------------------------------------
     * Every 20ms
     *--------------------------------------------------------------------*/
    if (sch_counters.count20ms >= SCH_CNT_20MS)
    {
        sch_Run20msTasks();
    }

    /*----------------------------------------------------------------------
     * Every 50ms
     *--------------------------------------------------------------------*/
    if (sch_counters.count50ms >= SCH_CNT_50MS)
    {
        sch_Run50msTasks();
    }

    /*----------------------------------------------------------------------
     * Every 100ms
     *--------------------------------------------------------------------*/
    if (sch_counters.count100ms >= SCH_CNT_100MS)
    {
        sch_Run100msTasks();
    }

    /*----------------------------------------------------------------------
     * Every 500ms
     *--------------------------------------------------------------------*/
    if (sch_counters.count500ms >= SCH_CNT_500MS)
    {
        sch_Run500msTasks();
    }

    /*----------------------------------------------------------------------
     * Every 1s
     *--------------------------------------------------------------------*/
    if (sch_counters.count1s >= SCH_CNT_1S)
    {
        sch_Run1sTasks();
    }

    /*----------------------------------------------------------------------
     * Every 10s
     *--------------------------------------------------------------------*/
    if (sch_counters.count10s >= SCH_CNT_10S)
    {
        sch_Run10sTasks();
    }

    /* Update load measures */
    sch_UpdateLoadMeasures();
}

/*!     \brief Runs 1ms tasks
 *       \param none
 *       \return none
 */
static void sch_Run1msTasks(void)
{
    uint32_t localCnt1msCpy;

    /* CPU Load control */

    /* Copy timer 1ms to spend less time as possible into scheduler interrupt
     * and guarantee compliance for all timers */
    localCnt1msCpy = sch_counters.count1ms;
    sch_counters.count1ms = 0U;
    sch_counters.count5ms += localCnt1msCpy;
    sch_counters.count10ms += localCnt1msCpy;
    sch_counters.count20ms += localCnt1msCpy;
    sch_counters.count50ms += localCnt1msCpy;
    sch_counters.count100ms += localCnt1msCpy;
    sch_counters.count500ms += localCnt1msCpy;
    sch_counters.count1s += localCnt1msCpy;
    sch_counters.count10s += localCnt1msCpy;

    /* 1ms task */
    // Check if the bootflag has been set
    if (PAR_flags.moduleFlags.status.flags.rebootRequested == true)
    {
        // Reset the UC thanks to MCU MCAL
        Mcu_PerformReset();
    }
    else
    {
        /*LDRA_INSPECTED 337 S <justification start> declared in project properties <justification end> */
#if NDEBUG_MODE
        // Refresh the WDO
        WDO_Refresh(true);
#endif
    }

    PAR_Update();
    ACT_UpdateFaults();
    FSM_Update();
    PWB_Update();
    CTB_Update();
    DBG_Update();
    CNV_Update();
    COM_TxScheduledTasks();
}

/*!     \brief Runs 5ms tasks
 *       \param none
 *       \return none
 */
static void sch_Run5msTasks(void)
{
    sch_counters.count5ms = 0U;
}

/*!     \brief Runs 10ms tasks
 *       \param none
 *       \return none
 */
static void sch_Run10msTasks(void)
{

    sch_counters.count10ms = 0U;

    /* Check is Low Power is required and ready */
    if (ACT_readyForLowPower == true)
    {
        sch_EnterLowPower();
        sch_ExitLowPower();
    }
    MPM_Management();
    COM_RxTask();
}

/*!     \brief Runs 20ms tasks
 *       \param none
 *       \return none
 */
static void sch_Run20msTasks(void)
{
    sch_counters.count20ms = 0U;
    COM_TxRequestedTasks();
}

/*!     \brief Runs 50ms tasks
 *       \param none
 *       \return none
 */
static void sch_Run50msTasks(void)
{
    sch_counters.count50ms = 0U;
}

/*!     \brief Runs 100ms tasks
 *       \param none
 *       \return none
 */
static void sch_Run100msTasks(void)
{
    sch_counters.count100ms = 0U;
    CTBPbit_SetTimePeriod(); // this function marks the end of the waiting time to count the raising edge of the dsi signal

}

/*!     \brief Runs 500ms tasks
 *       \param none
 *       \return none
 */
static void sch_Run500msTasks(void)
{
    sch_counters.count500ms = 0U;
}

/*!     \brief Runs 1s tasks
 *       \param none
 *       \return none
 */
static void sch_Run1sTasks(void)
{

    sch_counters.count1s = 0U;

    // Call function that manages parameters saving
    PAR_SaveParametersInFlash();
}

/*!     \brief Runs 10s tasks
 *       \param none
 *       \return none
 */
static void sch_Run10sTasks(void)
{

    sch_counters.count10s = 0U;

}

/*!     \brief  Updates the max, min and average measures of CPU loads
 *       \param none
 *       \return none
 */
static void sch_UpdateLoadMeasures(void)
{
    uint32_t tempLoad;

    /* Calculate new load based on this elements :
     *  The load is in % unit
     *  The load is equal to total time passed in one loop divided by SCH_Tick period (1ms)
     *  10micro-seconds is used as unit of time for calculation
     */
    tempLoad = (uint32_t) ((100U * sch_mainLoopElapsedTimeUs) / 100UL);

    /* Limit to 100% if overload */
    if (tempLoad > 100U)
    {
        tempLoad = 100U;
    }

    /* Update min load */
    if (tempLoad < SCH_MinLoad)
    {
        SCH_MinLoad = (uint8_t) tempLoad;
    }

    /* Update max load */
    if (tempLoad > SCH_MaxLoad)
    {
        SCH_MaxLoad = (uint8_t) tempLoad;
    }

    SCH_AverageLoad = (uint8_t) tempLoad;
}

/*!     \brief Interruption of Scheduler module
 *       \param none
 *       \return none
 */
void sch_Interruption(void)
{
    /*! Counters increment */
    sch_counters.count1ms++;

    if (WDO_InternalStateFlag == true)
    {
        WDO_Refresh(false);
    }
    /* Refresh the External wdg */
    if (WDO_ExternalStateFlag == true)
    {
        WDO_Refresh(true);
    }
}

/*!     \brief Enter in Low power
 *       \param none
 *       \return none
 */
static void sch_EnterLowPower(void)
{
    /* Deinit Modules */
    ACT_Deinit();
    FSM_Deinit();
    MPM_Deinit();

    /* Deinit Middlewares */
    FLA_Deinit();
    /*LDRA_INSPECTED 337 S <justification start> declared in project properties <justification end> */
#ifndef NDEBUG_MODE
    /* Deinit WDO */
    WDO_Deinit(true);
#endif
    /* Deinit drivers */

    /*---- DeInitializes PWMs ----*/
    Pwm_DeInit();

    /*---- DeInitializes ICU ----*/

    /*---- DeInitializes SPI MCAL ----*/
    (void) Spi_DeInit();

    /*---- DeInitializes GPT_LPTMR MCAL ----*/
    Gpt_DeInit();

    /*---- DeInitializes MCL ----*/
    Mcl_DeInit();

    /* Mask all IRQs except CAN_WAKEUP */
    (void) Platform_SetIrq(CAN0_Error_IRQn, FALSE);
    (void) Platform_SetIrq(CAN0_ORed_0_15_MB_IRQn, TRUE);
    (void) Platform_SetIrq(CAN0_ORed_16_31_MB_IRQn, TRUE);
    (void) Platform_SetIrq(CAN1_Error_IRQn, FALSE);
    (void) Platform_SetIrq(CAN0_Wake_Up_IRQn, TRUE);
    (void) Platform_SetIrq(CAN1_ORed_0_15_MB_IRQn, FALSE);
    (void) Platform_SetIrq(CAN1_ORed_16_31_MB_IRQn, FALSE);

    (void) Platform_SetIrq(DMA0_IRQn, FALSE);
    (void) Platform_SetIrq(DMA1_IRQn, FALSE);
    (void) Platform_SetIrq(DMA2_IRQn, FALSE);
    (void) Platform_SetIrq(DMA3_IRQn, FALSE);

    (void) Platform_SetIrq(LPSPI0_IRQn, FALSE);
    (void) Platform_SetIrq(LPSPI1_IRQn, FALSE);
    (void) Platform_SetIrq(LPSPI2_IRQn, FALSE);
    (void) Platform_SetIrq(LPIT0_Ch0_IRQn, FALSE);
    (void) Platform_SetIrq(LPIT0_Ch1_IRQn, FALSE);
    (void) Platform_SetIrq(LPIT0_Ch2_IRQn, FALSE);

    Mcu_SetMode(McuModeSettingConf_SleepModeClock);
}

/*!     \brief Exit Low power mode
 *       \param none
 *       \return none
 */
static void sch_ExitLowPower(void)
{
    /* Init drivers */
    Mcu_SetMode(McuModeSettingConf_NormalClock);

    /*---- Initialize MCL ----*/
    Mcl_Init(&Mcl_Config_INIT);

    /*---- Initialize all pins using the Port driver ----*/
    Port_Init(&Port_Config_Init);

    /*---- Initialize Platform MCAL ----*/
    (void) Platform_Init(NULL_PTR);

    (void) Platform_SetIrq(CAN0_Error_IRQn, TRUE);
    (void) Platform_SetIrq(CAN0_ORed_0_15_MB_IRQn, TRUE);
    (void) Platform_SetIrq(CAN0_ORed_16_31_MB_IRQn, TRUE);
    (void) Platform_SetIrq(CAN1_Error_IRQn, TRUE);
    (void) Platform_SetIrq(CAN0_Wake_Up_IRQn, TRUE);
    (void) Platform_SetIrq(CAN1_ORed_0_15_MB_IRQn, TRUE);
    (void) Platform_SetIrq(CAN1_ORed_16_31_MB_IRQn, TRUE);

    (void) Platform_SetIrq(DMA0_IRQn, TRUE);
    (void) Platform_SetIrq(DMA1_IRQn, TRUE);
    (void) Platform_SetIrq(DMA2_IRQn, TRUE);
    (void) Platform_SetIrq(DMA3_IRQn, TRUE);

    (void) Platform_SetIrq(LPSPI0_IRQn, TRUE);
    (void) Platform_SetIrq(LPSPI1_IRQn, TRUE);

    (void) Platform_SetIrq(LPIT0_Ch1_IRQn, TRUE);
    (void) Platform_SetIrq(LPIT0_Ch2_IRQn, TRUE);

    /*---- Initialize GPT_LPTMR MCAL ----*/
    Gpt_Init(&Gpt_Config_Init);

    /*---- Initialize SPI MCAL ----*/
    Spi_Init(&Spi_Config_Init);
    /* Using interrupt in transfer */
    (void) Spi_SetAsyncMode(SPI_INTERRUPT_MODE);

    /*---- Initialize CAN MCAL ----*/
    Can_Init(&Can_Config_Init);

    /*---- Initializes ICU ----*/
    /* Configure the Icu channel mode. */

    /*---- Initialize PWMs with masked output ----*/
    /* Initializes PWM driver */
    Pwm_Init(&Pwm_Config_Init);

    /*---- Initializes CRC ----*/
    Crc_Init(&Crc_xConfigInit);

    INI_InitMiddlewares();
    INI_InitLibrairies();
    INI_InitModules();
}
