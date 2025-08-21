/*!
 * \file     CTBio.c
 * \brief    implements the functions of the CTBio sub-module
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

/* ---- Includes ---- */
#include "Pwm.h"
#include "CTBio.h"
#include "CST.h"
#include "COM.h"
#include "FSM.h"
/* ---- Defines ---- */

#define LED1ID    1U
#define LED2ID    2U
#define LED3ID    3U

/* ---- Global variables ---- */

/* ---- External functions ---- */

/* ---- Static variables ---- */

/* ---- Static functions ---- */
static void ctbio_controlLED(uint8_t pinId, uint16_t state);

/*!     \brief initialization of the CTBio sub-module
 *       \param none
 *       \return none
 */
void CTBio_Init(void)
{
    /* Nothing to do for now*/
}

void CTBio_RunTests(void)
{
    CTBio_CmdLed(COM_debugTestReq.ledId, COM_debugTestReq.ledColor,
            COM_debugTestReq.ledCmd);
}
/*!     \brief command the state of a led
 *       \param ledid : uint8_t the id of the led
 *              ledcolor : uint8_t the color of the led
 *              state : the state to cmd the led to PWM, OFF, ON
 *       \return none
 */
void CTBio_CmdLed(uint8_t ledid, uint8_t ledcolor, CTBio_LedState state)
{
    switch (state)
    {
        case LedOff:
            ctbio_controlLED(ledid, PWM_0_DUTY_CYCLE);
            break;
        case LedOn:
            ctbio_controlLED(ledid, PWM_100_DUTY_CYCLE);
            break;
        case LedPWM:
            ctbio_controlLED(ledid, PWM_50_DUTY_CYCLE);
        default:
            /* Nothing to do */
            break;
    }
}

/*!     \brief command the state of a led
 *       \param none
 *       \return none
 */
void CTBio_SetLedToBBAuxState(void)
{
    switch (FSM_mode) {
        case FSM_MODE_STANDBY:
            Pwm_SetDutyCycle(MCU_LED1, PWM_100_DUTY_CYCLE);
            Pwm_SetDutyCycle(MCU_LED2, PWM_0_DUTY_CYCLE);
            Pwm_SetDutyCycle(MCU_LED3, PWM_100_DUTY_CYCLE);
            Pwm_SetDutyCycle(MCU_LED4, PWM_0_DUTY_CYCLE);
            Pwm_SetDutyCycle(MCU_LED5, PWM_100_DUTY_CYCLE);
            Pwm_SetDutyCycle(MCU_LED6, PWM_0_DUTY_CYCLE);
            break;
        case FSM_MODE_EMERGENCY:
            Pwm_SetDutyCycle(MCU_LED1, PWM_0_DUTY_CYCLE);
            Pwm_SetDutyCycle(MCU_LED2, PWM_100_DUTY_CYCLE);
            Pwm_SetDutyCycle(MCU_LED3, PWM_0_DUTY_CYCLE);
            Pwm_SetDutyCycle(MCU_LED4, PWM_100_DUTY_CYCLE);
            Pwm_SetDutyCycle(MCU_LED5, PWM_0_DUTY_CYCLE);
            Pwm_SetDutyCycle(MCU_LED6, PWM_100_DUTY_CYCLE);
            break;
        case FSM_MODE_PBIT:
            Pwm_SetDutyCycle(MCU_LED1, PWM_100_DUTY_CYCLE);
            Pwm_SetDutyCycle(MCU_LED2, PWM_100_DUTY_CYCLE);
            Pwm_SetDutyCycle(MCU_LED3, PWM_0_DUTY_CYCLE);
            Pwm_SetDutyCycle(MCU_LED4, PWM_0_DUTY_CYCLE);
            Pwm_SetDutyCycle(MCU_LED5, PWM_0_DUTY_CYCLE);
            Pwm_SetDutyCycle(MCU_LED6, PWM_0_DUTY_CYCLE);
            break;
        case FSM_MODE_BUCK:
            Pwm_SetDutyCycle(MCU_LED1, PWM_0_DUTY_CYCLE);
            Pwm_SetDutyCycle(MCU_LED2, PWM_0_DUTY_CYCLE);
            Pwm_SetDutyCycle(MCU_LED3, PWM_100_DUTY_CYCLE);
            Pwm_SetDutyCycle(MCU_LED4, PWM_100_DUTY_CYCLE);
            Pwm_SetDutyCycle(MCU_LED5, PWM_0_DUTY_CYCLE);
            Pwm_SetDutyCycle(MCU_LED6, PWM_0_DUTY_CYCLE);
            break;
        case FSM_MODE_BOOST:
            Pwm_SetDutyCycle(MCU_LED1, PWM_0_DUTY_CYCLE);
            Pwm_SetDutyCycle(MCU_LED2, PWM_0_DUTY_CYCLE);
            Pwm_SetDutyCycle(MCU_LED3, PWM_0_DUTY_CYCLE);
            Pwm_SetDutyCycle(MCU_LED4, PWM_0_DUTY_CYCLE);
            Pwm_SetDutyCycle(MCU_LED5, PWM_100_DUTY_CYCLE);
            Pwm_SetDutyCycle(MCU_LED6, PWM_100_DUTY_CYCLE);
            break;
        case FSM_MODE_SHUTDOWN:
            Pwm_SetDutyCycle(MCU_LED1, PWM_100_DUTY_CYCLE);
            Pwm_SetDutyCycle(MCU_LED2, PWM_100_DUTY_CYCLE);
            Pwm_SetDutyCycle(MCU_LED3, PWM_100_DUTY_CYCLE);
            Pwm_SetDutyCycle(MCU_LED4, PWM_100_DUTY_CYCLE);
            Pwm_SetDutyCycle(MCU_LED5, PWM_100_DUTY_CYCLE);
            Pwm_SetDutyCycle(MCU_LED6, PWM_100_DUTY_CYCLE);
            break;
        case FSM_MODE_MAINTENANCE:
            Pwm_SetDutyCycle(MCU_LED1, PWM_0_DUTY_CYCLE);
            Pwm_SetDutyCycle(MCU_LED2, PWM_0_DUTY_CYCLE);
            Pwm_SetDutyCycle(MCU_LED3, PWM_100_DUTY_CYCLE);
            Pwm_SetDutyCycle(MCU_LED4, PWM_100_DUTY_CYCLE);
            Pwm_SetDutyCycle(MCU_LED5, PWM_100_DUTY_CYCLE);
            Pwm_SetDutyCycle(MCU_LED6, PWM_100_DUTY_CYCLE);
            break;
        default:
            Pwm_SetDutyCycle(MCU_LED1, PWM_0_DUTY_CYCLE);
            Pwm_SetDutyCycle(MCU_LED2, PWM_0_DUTY_CYCLE);
            Pwm_SetDutyCycle(MCU_LED3, PWM_0_DUTY_CYCLE);
            Pwm_SetDutyCycle(MCU_LED4, PWM_0_DUTY_CYCLE);
            Pwm_SetDutyCycle(MCU_LED5, PWM_0_DUTY_CYCLE);
            Pwm_SetDutyCycle(MCU_LED6, PWM_0_DUTY_CYCLE);
            break;
    }
}

/*!     \brief deinitialization of the CTBio sub_module
 *       \param none
 *       \return none
 */
void CTBio_Deinit(void)
{
    /* Nothing to do for now*/
}

static void ctbio_controlLED(uint8_t pinId, uint16_t state)
{
    switch (pinId)
    {
        case LED1ID:
            Pwm_SetDutyCycle(MCU_LED1, state);
            Pwm_SetDutyCycle(MCU_LED2, state);
            break;
        case LED2ID:
            Pwm_SetDutyCycle(MCU_LED3, state);
            Pwm_SetDutyCycle(MCU_LED4, state);
            break;
        case LED3ID:
            Pwm_SetDutyCycle(MCU_LED5, state);
            Pwm_SetDutyCycle(MCU_LED6, state);
            break;
        default:
            break;
    }
}
