/*!
 * \file     CTBPbit.c
 * \brief    implements the functions of the CTBPbit sub-module
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

/* ---- Includes ---- */
#define CTBPbit_SUBMODULE

#include "CTBPbit.h"
#include "TYPedef.h"
#include "CST.h"
#include "Icu.h"
#include "Pwm.h"
#include "Platform.h"
#include "Gpt.h"
#include "Mcu.h"
#include "Dio.h"
#include "CTB_dsiodef.h"
#include "COM.h"

/* ---- Defines ---- */

#define MIN_EDGECOUNT 15U // the task is placed in the 100ms tasks
#define MAX_EDGECOUNT 17U
#define DSI_PBIT2_TIMER_CHANNEL_ID 1U

/* ---- Global variables ---- */

/* ---- External functions ---- */
extern ISR(LPIT_0_CH_1_ISR);
/* ---- Static variables ---- */

/* ---- Static functions ---- */
static void ctbPbit_CheckFrqDSI(void);


/*!     \brief Initialization of CTBPbit Sub-Module
 *       \param none
 *       \return none
 */
void CTBPbit_Init(void)
{
    uint32_t cpu_timerFreq166Hz;

    // enabling all the power supplies to the dsio
    Dio_WriteChannel(DioConf_DioChannel_DSI_EN1, STD_HIGH);
    Dio_WriteChannel(DioConf_DioChannel_DSI_EN2, STD_HIGH);
    Dio_WriteChannel(DioConf_DioChannel_DSI_EN3, STD_HIGH);
    Dio_WriteChannel(DioConf_DioChannel_DSI_EN4, STD_HIGH);
    Dio_WriteChannel(DioConf_DioChannel_DSI_EN5, STD_HIGH);
    Dio_WriteChannel(DioConf_DioChannel_DSI_EN6, STD_HIGH);

    /* Set up timer interrupt */
    (void) Platform_InstallIrqHandler(LPIT0_Ch1_IRQn, &LPIT_0_CH_1_ISR,
    NULL_PTR);

    /* Get timer frequency in 166Hz unit */
    cpu_timerFreq166Hz = 24096U; // number of ticks to get 6ms period
    /* Set count period to fit 6ms */
    Gpt_StartTimer(DSI_PBIT2_TIMER_CHANNEL_ID, cpu_timerFreq166Hz - 1U); // start the timer

//    // enable the ICU detections
    Icu_EnableEdgeDetection(DSI_CPU1);
    Icu_EnableNotification(DSI_CPU1);

    Icu_EnableEdgeCount(DSI_CPU2);
    Icu_EnableNotification(DSI_CPU2);

    Icu_EnableEdgeCount(DSI_CPU3);
    Icu_EnableNotification(DSI_CPU3);

    Icu_EnableEdgeDetection(DSI_CPU4);
    Icu_EnableNotification(DSI_CPU4);

    Icu_EnableEdgeDetection(DSI_CPU5);
    Icu_EnableNotification(DSI_CPU5);

    Icu_EnableEdgeDetection(DSI_CPU6);
    Icu_EnableNotification(DSI_CPU6);

    // reset the counter because the counter might take into considertation the raising edge in normal working mode (GPIO MODE)
    dsi1_edgeCounter = 0;
    dsi2_edgeCounter = 0;
    dsi3_edgeCounter = 0;
    dsi4_edgeCounter = 0;
    dsi5_edgeCounter = 0;
    dsi6_edgeCounter = 0;

    // initializing all the globale variables
    CTBPbit_Started = false;
    CTBPbit_TimePeriodEnded = false;

    ctb_DSI_readResult = false;

    ctb_DSI_TestResult.DSI_SPARE_1_TestResult = false;
    ctb_DSI_TestResult.DSI_SPARE_2_TestResult = false;
    ctb_DSI_TestResult.EMER_STOP_TestResult = false;
    ctb_DSI_TestResult.HPP_1_TestResult = false;
    ctb_DSI_TestResult.HPP_2_TestResult = false;
    ctb_DSI_TestResult.HPP_MAINT_TestResult = false;
    ctb_DSI_TestResult.reserved = 3;
}

/*!     \brief function to start the tests on CTBPbit tests
 *       \param none
 *       \return none
 */
void CTBPbit_RunTests(void)
{

    uint8_t pinId, pincmd;
    pinId = COM_debugTestReq.discreteIoId; // get the information needed from the COM module
    pincmd = COM_debugTestReq.discreteIoCmd;

    switch (pincmd)
    {
        // other cmd will be managed with the CTB_CBIT submodule (read DSO, set and unset DSO)
        case CTBPbit_READDSI_CMD:
            CTBPbit_ReadDSI(pinId); //execute the Read cmd
            break;
        case CTBPbit_START_CMD:
            ctbPbit_StartTestDSI(pinId); //execute the start PWM cmd
            break;
        case CTBPbit_STOP_CMD:
            ctbPbit_StopTestDSI(pinId); //execute the stop PWM cmd
            CTBPbit_Started = false;
            break;
        default:
            // Undefined Command do nothing
            break;
    }
}

/*!     \brief function to set the time period called at 100ms
 *       \param none
 *       \return none
 */

/* Explanation :
 *
 * time line |==========|========================|=========================================>
 *                     we start the test        after the time period ended
 *                     CTBPbit_Started = true   we see if we start then we are true\
 *                           in the time between
 *                           the CTBPbit_Started is true
 *                           but the time period isn't
 * */
void CTBPbit_SetTimePeriod(void)
{
    if (CTBPbit_Started) //if we started a PWM check
    {
        CTBPbit_TimePeriodEnded = true; //the 100ms time slot is done or undone
        ctbPbit_CheckFrqDSI(); // check the frq based on the 100ms time slot
    }
    else
    {
        /* Nothing to do just continue */
    }
}

/*!     \brief function to check if the frq read by the ICU is 166hz (TRS)
 *       \param dsiCpuPin : CTB_DSI_PinsE : to specify the pin to check
 *       \return boolean
 */
void ctbPbit_CheckFrqDSI(void)
{
    ctb_DSI_TestResult.HPP_MAINT_TestResult = ((dsi1_edgeCounter
            >= MIN_EDGECOUNT) && (dsi1_edgeCounter <= MAX_EDGECOUNT)); // check if the counter is within the boundries of 166Hz
    ctb_DSI_TestResult.HPP_1_TestResult = ((dsi5_edgeCounter >= MIN_EDGECOUNT) // for all the counters
    && (dsi5_edgeCounter <= MAX_EDGECOUNT));
    ctb_DSI_TestResult.HPP_2_TestResult = ((dsi6_edgeCounter >= MIN_EDGECOUNT)
            && (dsi6_edgeCounter <= MAX_EDGECOUNT));
    ctb_DSI_TestResult.EMER_STOP_TestResult = ((dsi4_edgeCounter
            >= MIN_EDGECOUNT) && (dsi4_edgeCounter <= MAX_EDGECOUNT));
    ctb_DSI_TestResult.DSI_SPARE_1_TestResult = ((dsi2_edgeCounter
            >= MIN_EDGECOUNT) && (dsi2_edgeCounter <= MAX_EDGECOUNT));
    ctb_DSI_TestResult.DSI_SPARE_2_TestResult = ((dsi3_edgeCounter
            >= MIN_EDGECOUNT) && (dsi3_edgeCounter <= MAX_EDGECOUNT));

    dsi1_edgeCounter = 0; // reset the counters
    dsi2_edgeCounter = 0;
    dsi3_edgeCounter = 0;
    dsi4_edgeCounter = 0;
    dsi5_edgeCounter = 0;
    dsi6_edgeCounter = 0;
}

/*!     \brief function to start sending the PWM on the Pbit pins
 *       \param dsiCpuPin : CTB_DSI_PinsE : to specify the pin to manage
 *       \return none
 */
void ctbPbit_StartTestDSI(CTB_DSI_PinsE dsiPin)
{
    //Switch case depending on DSI pin
    switch (dsiPin)
    {
        case HPP_1:
            Port_SetPinMode(DSI_PBIT5_PIN, DSI_PBIT5_PWM_MODE); // seting the Mode of the pin to PWM FTMx_CHy to be able to generate PWM
            Pwm_SetPeriodAndDuty(DSI_Pbit5, 0xEB51, PWM_50_DUTY_CYCLE); // starting the PWM with 166 Hz
            break;
        case HPP_2:
            Port_SetPinMode(DSI_PBIT6_PIN, DSI_PBIT6_PWM_MODE);
            Pwm_SetPeriodAndDuty(DSI_Pbit6, 0xEB51, PWM_50_DUTY_CYCLE);
            break;
        case EMER_STOP:
            Port_SetPinMode(DSI_PBIT4_PIN, DSI_PBIT4_PWM_MODE);
            Pwm_SetPeriodAndDuty(DSI_Pbit4, 0xEB51, PWM_50_DUTY_CYCLE);
            break;
        case DSI_SPARE_1:
            Gpt_EnableNotification(DSI_PBIT2_TIMER_CHANNEL_ID);
            break;
        case DSI_SPARE_2:
            Port_SetPinMode(DSI_PBIT3_PIN, DSI_PBIT3_PWM_MODE);
            Pwm_SetPeriodAndDuty(DSI_Pbit3, 0xEB51, PWM_50_DUTY_CYCLE);
            break;
        case HPP_MAINT:
            Port_SetPinMode(DSI_PBIT1_PIN, DSI_PBIT1_PWM_MODE);
            Pwm_SetPeriodAndDuty(DSI_Pbit1, 0xEB51, PWM_50_DUTY_CYCLE);
            break;
        default:
            // Undefined Pin do nothing // shall never happen
            break;
    }
    CTBPbit_Started = true; // set the flag, we start the PWM test
    CTBPbit_TimePeriodEnded = false; // we wait for the 100ms to end
}

/*!     \brief function to stop sending the PWM on the Pbit pins
 *       \param dsiCpuPin : CTB_DSI_PinsE : to specify the pin to manage
 *       \return none
 */
void ctbPbit_StopTestDSI(CTB_DSI_PinsE dsiPin)
{
    switch (dsiPin)
    {
        case HPP_1:
            Pwm_SetPeriodAndDuty(DSI_Pbit5, 0xEB51, PWM_0_DUTY_CYCLE); // stoping the PWM
            Port_SetPinMode(DSI_PBIT5_PIN, DSI_PBIT5_GPIO_MODE); // setting back the pin mode to GPIO
            break;
        case HPP_2:
            Pwm_SetPeriodAndDuty(DSI_Pbit6, 0xEB51, PWM_0_DUTY_CYCLE);
            Port_SetPinMode(DSI_PBIT6_PIN, DSI_PBIT6_GPIO_MODE);
            break;
        case EMER_STOP:
            Pwm_SetPeriodAndDuty(DSI_Pbit4, 0xEB51, PWM_0_DUTY_CYCLE);
            Port_SetPinMode(DSI_PBIT4_PIN, DSI_PBIT4_GPIO_MODE);
            break;
        case DSI_SPARE_1:
            Gpt_DisableNotification(DSI_PBIT2_TIMER_CHANNEL_ID);
            break;
        case DSI_SPARE_2:
            Pwm_SetPeriodAndDuty(DSI_Pbit3, 0xEB51, PWM_0_DUTY_CYCLE);
            Port_SetPinMode(DSI_PBIT3_PIN, DSI_PBIT3_GPIO_MODE);
            break;
        case HPP_MAINT:
            Pwm_SetPeriodAndDuty(DSI_Pbit1, 0xEB51, PWM_0_DUTY_CYCLE);
            Port_SetPinMode(DSI_PBIT1_PIN, DSI_PBIT1_GPIO_MODE);
            break;
        default:
            // Undefined Pin do nothing // shall never happen
            break;
    }
}

/*!     \brief function to read the state of the DSI_CPU pin
 *       \param dsiCpuPin : CTB_DSI_PinsE : to specify the pin to check
 *       \return none
 */
void CTBPbit_ReadDSI(CTB_DSI_PinsE dsiPin)
{
    switch (dsiPin)
    {
        case HPP_1:
            ctb_DSI_readResult = Dio_ReadChannel( // Read the DIO channel of the corresponding DSI pin
                    DioConf_DioChannel_DSI_CPU5);
            break;
        case HPP_2:
            ctb_DSI_readResult = Dio_ReadChannel(
            DioConf_DioChannel_DSI_CPU6);
            break;
        case EMER_STOP:
            ctb_DSI_readResult = Dio_ReadChannel(
            DioConf_DioChannel_DSI_CPU4);
            break;
        case DSI_SPARE_1:
            ctb_DSI_readResult = Dio_ReadChannel(
            DioConf_DioChannel_DSI_CPU2);
            break;
        case DSI_SPARE_2:
            ctb_DSI_readResult = Dio_ReadChannel(
            DioConf_DioChannel_DSI_CPU3);
            break;
        case HPP_MAINT:
            ctb_DSI_readResult = Dio_ReadChannel(
            DioConf_DioChannel_DSI_CPU1);
            break;
        default:
            // Undefined Pin do nothing // shall never happen
            break;
    }
}

/*!     \brief Deinitialization of CTBPbit Sub-Module
 *       \param none
 *       \return none
 */
void CTBPbit_Deinit(void)
{
    /* Nothing to do for now*/
}

/*!     \brief call back function for the ICU driver DSI_CPU1
 *       \param none
 *       \return none
 */
void ctb_dsicpu1_callback(void)
{
    dsi1_edgeCounter++;
}

/*!     \brief call back function for the ICU driver DSI_CPU2
 *       \param none
 *       \return none
 */
void ctb_dsicpu2_callback(void)
{
    dsi2_edgeCounter++;
}

/*!     \brief call back function for the ICU driver DSI_CPU3
 *       \param none
 *       \return none
 */
void ctb_dsicpu3_callback(void)
{
    dsi3_edgeCounter++;
    uint8_t i = 0;
    if(dsi3_edgeCounter == 18){
        i = 9;
    }
    else
    {
        i = 8;
    }
}

/*!     \brief call back function for the ICU driver DSI_CPU4
 *       \param none
 *       \return none
 */

void ctb_dsicpu4_callback(void)
{
    dsi4_edgeCounter++;
}

/*!     \brief call back function for the ICU driver DSI_CPU5
 *       \param none
 *       \return none
 */
void ctb_dsicpu5_callback(void)
{
    dsi5_edgeCounter++;
}

/*!     \brief call back function for the ICU driver DSI_CPU6
 *       \param none
 *       \return none
 */
void ctb_dsicpu6_callback(void)
{
    dsi6_edgeCounter++;
}

/*!     \brief call back function for the GPT driver DSI_CPU2
 *       \param none
 *       \return none
 */
void ctbPbit_DsiPbit2TimerCB(void)
{
    Dio_FlipChannel(DioConf_DioChannel_DSI_PBIT2);
}
