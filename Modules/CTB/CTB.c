/*!
 * \file     CTB.c
 * \brief    implements the functions of the CTB module
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

/* ---- Includes ---- */
#define CTB_MODULE

#include "CTB.h"
#include "FSM.h"
#include "ACT.h"
#include "DBG.h"
#include "CTBPbit.h"
#include "CTBCbit.h"
#include "CTBio.h"
#include "COM.h"
#include "CBUs.h"
#include "Dio.h"
#include "Pwm.h"
#include "Port.h"

/* ---- Defines ---- */
#define CTB_MAIN_TASK_PERIOD 5U
#define PBIT_TIMING_ENDED 50U
#define DSI_CONFIRMATION_TIME 10U // * 5 = 50 ms
/* ---- Global variables ---- */

/* ---- External functions ---- */

/* ---- Static variables ---- */

static uint8_t ctb_taskCounter = 0;
static uint8_t pbit_timingCounter = 0;
static boolean pbitTestsEnded = false;

static struct CTB_DsiTimersStr
{
    uint32_t Maint_DSI_State;
    uint32_t EMERSTOP_DSI_State;
} ctb_DSIConfirmationTimers = { 0, 0, 0 };

static struct CTB_DsiCurrentStateStr
{
    boolean Maint_DSI_State;
    boolean EMERSTOP_DSI_State;
} ctb_DSICurrentStates = { 0, 0, 0 };

/* ---- Static functions ---- */
static void ctb_UpdateResults(void);
static void ctb_MaintManagement(void);
static void ctb_PbitManagement(void);
static void ctb_CbitManagement(void);
static void ctb_ControlManagement(void);

boolean CTB_Read_EMERSTOP(void);
boolean CTB_Read_Maint(void);
uint8_t CTB_Read_BbAuxAdd(void);

/*!     \brief Initialization of CTB Module
 *       \param none
 *       \return none
 */
void CTB_Init(void)
{
    // initialazing the  Sub-Modules
    CTBPbit_Init();
    CTBCbit_Init();
    CTBio_Init();

    CTB_dsiState.EMERSTOP_DSI_State = false;
    CTB_dsiState.Maint_DSI_State = false;
    CTB_dsiState.bbAux_Address = 0x0;

    CTB_Flags.resultCBit = false;
    CTB_Flags.resultPBit = false;
    CTB_Flags.faults.all = 0;
    CTB_Flags.dsiResults.all = 0;
    CTB_Flags.status.all = 0;
}

/*!     \brief Periodical task which checks if an update has been requested, and if it's correct
 *       \param none
 *       \return none
 */
void CTB_Update(void)
{
    switch (FSM_mode)
    {
        case FSM_MODE_MAINTENANCE:
            ctb_MaintManagement(); // do maint operations
            break;
        case FSM_MODE_PBIT:
            ctb_PbitManagement(); // do pbit
            break;
        default:
            break;
    }

    ctb_CbitManagement(); // do cbit and control
    ctb_ControlManagement();

    if (ctb_taskCounter < (CTB_MAIN_TASK_PERIOD - 1))
    {
        ctb_taskCounter++;
    }
    else
    {
        ctb_taskCounter = 0;
    }

    // error reset request
    if (COM_flags.moduleFlags.status.flags.errorResetRequest == true)
    {
        CTB_Flags.faults.all = 0;
    }

}

/*!     \brief CALLed Functiont to read the state of the EMERGENCY STOP DSI
 *       \param none
 *       \return boolean state of the DSI
 */
boolean CTB_Read_EMERSTOP(void)
{
    return Dio_ReadChannel(
    DioConf_DioChannel_DSI_CPU4);
}

/*!     \brief CALLed Functiont to read the state of the MAINTENANCE DSI
 *       \param none
 *       \return boolean state of the DSI
 */
boolean CTB_Read_Maint(void)
{
    return Dio_ReadChannel(
    DioConf_DioChannel_DSI_CPU1);
}

/*!     \brief CALLed Functiont to read the state of the MAINTENANCE DSI
 *       \param none
 *       \return boolean state of the DSI
 */
uint8_t CTB_Read_BbAuxAdd(void)
{
    CTBPbit_ReadDSI(HPP_1);
    boolean hpp1_state = ctb_DSI_readResult;
    CTBPbit_ReadDSI(HPP_2);
    boolean hpp2_state = ctb_DSI_readResult;
    // concatenate the two booleans to an uint8_t
    uint8_t returnValue = (uint8_t) ((uint8_t) hpp1_state << 0)
            | ((uint8_t) hpp2_state << 1);
    return returnValue;
}

/*!     \brief Deinitialization of CTB Module
 *       \param none
 *       \return none
 */
void CTB_Deinit(void)
{
    CTBPbit_Deinit();
    CTBCbit_Deinit();
    CTBio_Deinit();
}

/*!     \brief updating the results of the tests or cmds to the COM module
 *       \param none
 *       \return none
 */
static void ctb_UpdateResults(void)
{
    uint8_t pincmd = COM_debugTestReq.discreteIoCmd;
    uint8_t pinId = COM_debugTestReq.discreteIoId;

    boolean resultTemp;

    switch (pinId)
    // getting the result depending on the DSI pin tested
    {
        case HPP_1:
            resultTemp = ctb_DSI_TestResult.HPP_1_TestResult;
            break;
        case HPP_2:
            resultTemp = ctb_DSI_TestResult.HPP_2_TestResult;
            break;
        case EMER_STOP:
            resultTemp = ctb_DSI_TestResult.EMER_STOP_TestResult;
            break;
        case DSI_SPARE_1:
            resultTemp = ctb_DSI_TestResult.DSI_SPARE_1_TestResult;
            break;
        case DSI_SPARE_2:
            resultTemp = ctb_DSI_TestResult.DSI_SPARE_2_TestResult;
            break;
        case HPP_MAINT:
            resultTemp = ctb_DSI_TestResult.HPP_MAINT_TestResult;
            break;
        default:
            // Undefined Pin do nothing // Shall never happen
            break;
    }

    switch (pincmd)
    {
        case CTBPbit_STOP_CMD: // preparing the results to be sent on the CAN
            COM_debugTestReq.discreteIosPWMResult = resultTemp;
            break;
        case CTBPbit_READDSI_CMD:
            COM_debugTestReq.discreteIosReadResult = ctb_DSI_readResult;
            break;
        case CTBCBIT_READDSO_CMD:
            COM_debugTestReq.discreteIosReadResult = ctb_DSO_readResult;
            break;
        default:
            break;
    }
}

/*!     \brief maint operations
 *       \param none
 *       \return none
 */
static void ctb_MaintManagement(void)
{
    // check the DBG flags to start the tests needed.
    if (DBG_Flags.Reqflags.dsioTest == true)
    {
        CTBPbit_RunTests();
        CTBCbit_Runtests();
        ctb_UpdateResults();
        DBG_Flags.Reqflags.dsioTest = false;
    }
    if (DBG_Flags.Reqflags.ledCmd)
    {
        CTBio_RunTests();
        DBG_Flags.Reqflags.ledCmd = false;
    }
}

/*!     \brief Pbit operations
 *       \param none
 *       \return none
 */
static void ctb_PbitManagement(void)
{
    // execute the PBIT tests
    // update the Pbit flags

    if (pbitTestsEnded == true)
    {
        if (pbit_timingCounter >= PBIT_TIMING_ENDED)
        {
            CTB_Flags.status.flags.pbitDone = true;
            CTBPbit_Started = false;
            CTB_dsiState.bbAux_Address = CTB_Read_BbAuxAdd();
            COM_Address = CTB_dsiState.bbAux_Address;
            CBU_Address = CTB_dsiState.bbAux_Address;
            CTBCbit_SetDSO(HEALTH);
            CTB_dsoState.Health_State = true;
        }
        else
        {
            pbit_timingCounter++;
        }
    }
    else
    {
        if (CTBPbit_Started)
        {
            if (CTBPbit_TimePeriodEnded == true)
            {
                // get the results
                for (CTB_DSI_PinsE pin = HPP_1; pin <= DSI_Count; pin++)
                {
                    ctbPbit_StopTestDSI(pin);
                }
                if (ctb_DSI_TestResult.HPP_1_TestResult == true
                        && ctb_DSI_TestResult.HPP_2_TestResult == true
                        && ctb_DSI_TestResult.DSI_SPARE_1_TestResult == true
                        && ctb_DSI_TestResult.DSI_SPARE_2_TestResult == true
                        && ctb_DSI_TestResult.EMER_STOP_TestResult == true
                        && ctb_DSI_TestResult.HPP_MAINT_TestResult == true)
                {
                    // the pbit is successful
                    CTB_Flags.resultPBit = true;
                }
                else
                {
                    CTB_Flags.faults.flags.discretIOError = true;
                    CTB_Flags.resultPBit = false;

                }
                pbitTestsEnded = true;
                CTB_Flags.dsiResults.dsiTestResults = ctb_DSI_TestResult;
            }
            else
            {
                // Nothing to do wait for the Time period (100ms) to end
            }
        }
        else
        {
            for (CTB_DSI_PinsE pin = HPP_1; pin <= DSI_Count; pin++)
            {
                ctbPbit_StartTestDSI(pin);
            }
            pbitTestsEnded = false;
            pbit_timingCounter = 0;
        }

    }

}

/*!     \brief Cbit operations
 *       \param none
 *       \return none
 */
static void ctb_CbitManagement(void)
{
    // update all the state of the DSI

    if (ctb_taskCounter == 0U)
    {
        // nothing to do wait for Maint and EMERG to be read (empty 1ms for spare use)
    }

    else if (ctb_taskCounter == 1U)
    {
        // monitor own address consistency
        uint8_t oldAddress = COM_Address; // we read this address during the pbit it shouldn't change during normal functionning
        // comparing the states
        if (oldAddress != CTB_dsiState.bbAux_Address) // if there is any change raise the error
        {
            CTB_Flags.faults.flags.addressChanged = true;
        }
        else
        {
            CTB_Flags.faults.flags.addressChanged = false;
        }
    }

    else if (ctb_taskCounter == 2U)
    {
        // check if the cmd sent is corresponding to the state we read
        CTBCbit_ReadDSO(HEALTH);
        if (ctb_DSO_readResult != CTB_dsoState.Health_State)
        {
            CTB_Flags.faults.flags.discretIOError = true;
        }
        else
        {
            CTB_Flags.faults.flags.discretIOError = false;
        }
    }
}

static void ctb_ControlManagement(void)
{
    // this function contains all operations needed to control the behavior of the Control board
    // either with the FSM state or any CNV requests
    if (ctb_taskCounter == 0U)
    {
        ctb_DSICurrentStates.Maint_DSI_State = CTB_Read_Maint();
        ctb_DSICurrentStates.EMERSTOP_DSI_State = CTB_Read_EMERSTOP();

        if ((ctb_DSICurrentStates.EMERSTOP_DSI_State
                != CTB_dsiState.EMERSTOP_DSI_State)
                && (ctb_DSIConfirmationTimers.EMERSTOP_DSI_State
                        >= DSI_CONFIRMATION_TIME))
        {
            CTB_dsiState.EMERSTOP_DSI_State =
                    ctb_DSICurrentStates.EMERSTOP_DSI_State; // Confirmed
            ctb_DSIConfirmationTimers.EMERSTOP_DSI_State = 0;
        }
        else
        {
            ctb_DSIConfirmationTimers.EMERSTOP_DSI_State++;
        }

        if ((ctb_DSICurrentStates.Maint_DSI_State
                != CTB_dsiState.Maint_DSI_State)
                && (ctb_DSIConfirmationTimers.Maint_DSI_State
                        >= DSI_CONFIRMATION_TIME))
        {
            CTB_dsiState.Maint_DSI_State = ctb_DSICurrentStates.Maint_DSI_State; // Confirmed
            ctb_DSIConfirmationTimers.Maint_DSI_State = 0;
        }
        else
        {
            ctb_DSIConfirmationTimers.Maint_DSI_State++;
        }
    }

    else if (ctb_taskCounter == 1U)
    {
        CTB_dsiState.bbAux_Address = CTB_Read_BbAuxAdd();
    }

    else if (ctb_taskCounter == 2U)
    {
        // check when should i set or unset the Health DSO
        if (FSM_mode == FSM_MODE_MAINTENANCE)
        {
            CTB_dsoState.Health_State = COM_debugTestReq.discreteIoCmd; // if in MAINTENANCE MODE let the user control the Health DSO with the CAN Command
        }
        else
        {
            if (ACT_errors.fastPowerDown.all != 0 || FSM_mode == FSM_MODE_PBIT)
            {
                CTBCbit_UnsetDSO(HEALTH);
                CTB_dsoState.Health_State = false;
            }
            else if (FSM_mode == FSM_MODE_SHUTDOWN)
            {
                CTBCbit_SetDSO(HEALTH);
                CTB_dsoState.Health_State = true;
            }
            else
            {
                CTBCbit_SetDSO(HEALTH);
                CTB_dsoState.Health_State = true;
            }
        }
    }

    else if (ctb_taskCounter == 3U)
    {
        // Future use
    }

    else if (ctb_taskCounter == 4U)
    {
        // Future use
    }

    else if (ctb_taskCounter == 5U)
    {
        // Future use
    }

}

