/*!
 * \file     PWBio.c
 * \brief    implements the functions of the PWBio sub-module
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/
#define PWBio_SUBMODULE

/* ---- Includes ---- */
#include "PWBio.h"
#include "Dio.h"
#include "Pwm.h"
#include "TYPedef.h"
#include "CST.h"
#include "COM.h"
#include "PAR.h"

/* ---- Defines ---- */
#define PWB_RELAY_OPEN_CMD 0x01
#define PWB_RELAY_CLOSE_CMD 0x02
#define PWB_RELAY_READ_CMD 0x03

/* ---- Global variables ---- */

/* ---- External functions ---- */

/* ---- Static variables ---- */

/* ---- Static functions ---- */

/*!     \brief Initialazing the PWBio subModule
 *       \param none
 *       \return none
 */
void PWBio_Init(void)
{
    PWBio_cmdResults.SwitchReadCmdResult = false;
    PWBio_LowerDutyCycleS2 = false;
    PWBio_LowerDutyCycleS3 = false;
}

/*!     \brief setting the switch of the commaded relay
 *       \param switchId : PWB_CdeSwitchIdE
 *       \return none
 */
void PWBio_SetCdeSwitch(PWB_CdeSwitchIdE switchId)
{
    uint32_t CdeS2Freq =
            PAR_paramConfig[PAR_LVRELAY_STEADY_FREQUENCY].realVal.unsignedVal;
    uint32_t CdeS3Freq =
            PAR_paramConfig[PAR_HVRELAY_STEADY_FREQUENCY].realVal.unsignedVal;
    switch (switchId)
    {
        case SwitchCdeS1:
            Dio_WriteChannel(DioConf_DioChannel_CdeS1, STD_HIGH); // writing High state to the pin
            break;
        case SwitchCdeS2:
            if (PWBio_LowerDutyCycleS2 == true)
            {
                Pwm_SetPeriodAndDuty(CdeS2, CdeS2Freq, PWM_40_DUTY_CYCLE); // switch 2 and 3 are commaded using a PWM signal
            }
            else
            {
                Pwm_SetPeriodAndDuty(CdeS2, CdeS2Freq, PWM_100_DUTY_CYCLE); // switch 2 and 3 are commaded using a PWM signal
            }
            break;
        case SwitchCdeS3:
            if (PWBio_LowerDutyCycleS3 == true)
            {
                Pwm_SetPeriodAndDuty(CdeS3, CdeS3Freq, PWM_40_DUTY_CYCLE); // switch 2 and 3 are commaded using a PWM signal 40 % Duty Cycle
            }
            else
            {
                Pwm_SetPeriodAndDuty(CdeS3, CdeS3Freq, PWM_100_DUTY_CYCLE); // switch 2 and 3 are commaded using a PWM signal 100% Duty Cycle
            }
            break;
        default:
            break;
    }
}

/*!     \brief unsetting the switch of the commaded relay
 *       \param switchId : PWB_CdeSwitchIdE
 *       \return none
 */
void PWBio_UnsetCdeSwitch(PWB_CdeSwitchIdE switchId)
{
    uint32_t CdeS2Freq =
            PAR_paramConfig[PAR_LVRELAY_STEADY_FREQUENCY].realVal.unsignedVal;
    uint32_t CdeS3Freq =
            PAR_paramConfig[PAR_HVRELAY_STEADY_FREQUENCY].realVal.unsignedVal;
    switch (switchId)
    {
        case SwitchCdeS1:
            Dio_WriteChannel(DioConf_DioChannel_CdeS1, STD_LOW); // writing LOW state to the pin
            break;
        case SwitchCdeS2:
            Pwm_SetPeriodAndDuty(CdeS2, CdeS2Freq, PWM_0_DUTY_CYCLE); // switch 2 and 3 are commaded using a PWM signal
            break;
        case SwitchCdeS3:
            Pwm_SetPeriodAndDuty(CdeS3, CdeS3Freq, PWM_0_DUTY_CYCLE); // switch 2 and 3 are commaded using a PWM signal
            break;
        default:
            break;
    }
    PWBio_LowerDutyCycleS2 = false;
    PWBio_LowerDutyCycleS3 = false;
}

/*!     \brief reading the switch of the commaded relay
 *       \param auxId : PWB_AuxSwitchIdE
 *       \return boolean
 */
boolean PWBio_ReadAuxSwitch(PWB_AuxSwitchIdE auxId)
{
    boolean result;
    switch (auxId)
    {
        case AuxS2:
            result = Dio_ReadChannel(DioConf_DioChannel_AuxS2); // reading the state of the input pin using the DIO driver
            break;
        case AuxS3:
            result = Dio_ReadChannel(DioConf_DioChannel_AuxS3);
            break;
        default:
            result = false;
            break;
    }
    return result;
}

/*!     \brief function to start the tests on CTBCbit
 *       \param none
 *       \return none
 */
void PWBio_RunTests(void)
{
// read the command from the com module and
    uint8_t relayId, relayCmd, auxSwitchId;
    relayId = COM_debugTestReq.relaySwitchId;
    auxSwitchId = (uint8_t) (relayId - 1); // we can not read the relay with ID 1, we substruct 1 to be able to use the PWB_AuxSwitchIdE
    relayCmd = COM_debugTestReq.relaySwitchCmd;
    PWBio_LowerDutyCycleS2 = false;
    PWBio_LowerDutyCycleS3 = false;
    switch (relayCmd)
    {
        case PWB_RELAY_OPEN_CMD:
            PWBio_UnsetCdeSwitch(relayId);
            break;
        case PWB_RELAY_CLOSE_CMD:
            PWBio_SetCdeSwitch(relayId);
            break;
        case PWB_RELAY_READ_CMD:
            PWBio_cmdResults.SwitchReadCmdResult = PWBio_ReadAuxSwitch(
                    auxSwitchId);
            break;
        default:
            // undefined Command do nothing
            break;
    }

}

/*!     \brief Deinitialization of PWBio Sub-Module
 *       \param none
 *       \return none
 */
void PWBio_Deinit(void)
{
    PWBio_cmdResults.SwitchReadCmdResult = false;
    PWBio_LowerDutyCycleS2 = false;
    PWBio_LowerDutyCycleS3 = false;
}
