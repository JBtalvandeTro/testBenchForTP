/*!
 * \file     FSM_Update.c
 * \brief    Brief description of file content
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

/* ---- Includes ---- */
#include "Dio.h"
#include "FSM.h"
#include "FSMupdat.h"
#include "ACT.h"
#include "CTB.h"
#include "PWB.h"
#include "COM.h"
#include "Mcu.h"
#include "PAR.h"

/* ---- Defines ---- */

#define FSM_PBIT_TIMEOUT 5000U // 5s if the pbit over goes the 5s go to emergency

/* ---- Global variables ---- */

/* ---- External functions ---- */

/* ---- Static variables ---- */
static uint32_t fsm_pbit_timeout_counter = 0;

/* ---- Static functions ---- */
static void fsm_ManageInternalMode(void);
static FSM_ModesE fsm_CheckInitModeExit(void);
static FSM_ModesE fsm_CheckPBitModeExit(void);
static FSM_ModesE fsm_CheckStandbyModeExit(void);
static FSM_ModesE fsm_CheckBoostModeExit(void);
static FSM_ModesE fsm_CheckBuckModeExit(void);
static FSM_ModesE fsm_CheckEmergencyModeExit(void);
static FSM_ModesE fsm_CheckMaintenanceModeExit(void);
static FSM_ModesE fsm_CheckShutdownModeExit(void);
static FSM_ModesE fsm_CheckS3ModeExit(void);

/*!     \brief FSM Management functions
 *      \param none
 *      \return none
 */
void FSM_Update(void)
{
    fsm_ManageInternalMode();

    // error reset request
    if (COM_flags.moduleFlags.status.flags.errorResetRequest == true)
    {
        FSM_errors.EnterMaintModeNotMet = 0;
        FSM_errors.autonomousBoostEnd = 0;
        FSM_errors.autonomousBuckEnd = 0;
        FSM_errors.bbAuxInMaintMode = 0;
        FSM_errors.failedPbit = 0;
    }
}

/*!     \brief FSM Check Init Mode Exit function
 *      \param none
 *      \return new mode
 */
static FSM_ModesE fsm_CheckInitModeExit(void)
{
    FSM_ModesE tempMode;

    /* Check if all modules are correctly initialized */
    if (COM_flags.moduleFlags.status.flags.moduleInitialized == true)
    {
        tempMode = FSM_MODE_PBIT;
    }
    else
    {
        tempMode = FSM_MODE_EMERGENCY;
    }

    return (tempMode);
}

/*!     \brief FSM Check PBit Mode Exit function
 *      \param none
 *      \return new mode
 */
static FSM_ModesE fsm_CheckPBitModeExit(void)
{
    FSM_ModesE tempMode = FSM_MODE_PBIT;

    /* If in PBit, check that each module (CTB, PWB) is ok */
    if (CTB_Flags.status.flags.pbitDone == true
            && PWB_Flags.status.flags.pbitDone == true)
    {
        if (CTB_dsiState.EMERSTOP_DSI_State == false)
        {
            if (PWB_Flags.resultPBit == true && CTB_Flags.resultPBit == true)
            {
                tempMode = FSM_MODE_STANDBY; // if ok go to the STANDBY mode
                fsm_pbit_timeout_counter = 0;
                PWB_Flags.status.flags.pbitDone = false;
                CTB_Flags.status.flags.pbitDone = false;
                PWB_Flags.resultPBit = false;
                CTB_Flags.resultPBit = false;
            }
            else
            {
                tempMode = FSM_MODE_EMERGENCY; // if NOK go to EMERGENCY
                FSM_errors.failedPbit = true;
                fsm_pbit_timeout_counter = 0;
            }
        }
        else
        {

        }

    }

    if (fsm_pbit_timeout_counter < (FSM_PBIT_TIMEOUT - 1)) // TRO_50073_50147_001_TRS_0035: PBIT duration
    {
        fsm_pbit_timeout_counter++; // incrementing the timeout counter by 1ms each time we don't exit pbit mode
    }
    else
    {
        fsm_pbit_timeout_counter = 0;
    }

    if (CTB_dsiState.Maint_DSI_State == true)
    {
        // raise the error flag, you can't plug the maint connector while you are at pbit
        FSM_errors.EnterMaintModeNotMet = true;
    }
    else
    {
        FSM_errors.EnterMaintModeNotMet = false;
    }

    return (tempMode);
}

/*!     \brief FSM Check Standby Mode Exit function
 *      \param none
 *      \return new mode
 */
static FSM_ModesE fsm_CheckStandbyModeExit(void)
{
    FSM_ModesE tempMode = FSM_MODE_STANDBY;

    boolean ignoreBoost = false;

    if (PWB_measures.Hv_Voltage < 10) // check if VHV is less than 1V
    {
        // check if we have a S3 request TRUE
        if (COM_mode.S3ModeReq == true)
        {
            tempMode = FSM_MODE_S3MODE; // if yes go to S3 mode
        }
        else
        {
            tempMode = FSM_MODE_STANDBY; // if not stay in standby
        }
    }
    // check if we should ignore the BOOST cmd
    if (PWB_relayCurrentState.stateSwitchS3 == true)
    {
        ignoreBoost = true;
    }
    else
    {
        ignoreBoost = false;
    }

    // check if there is a request from the MTU BUCK or BOOST
    if (COM_flags.moduleFlags.status.flags.boostRequest == true
            && ignoreBoost == false)
    {
        // go to boost Mode
        tempMode = FSM_MODE_BOOST;
    }
    else
    {
        /* Nothing to do stay in StandBy */
    }
    if (COM_flags.moduleFlags.status.flags.buckRequest == true)
    {
        // go to buck mode
        tempMode = FSM_MODE_BUCK;
    }
    else
    {
        /* Nothing to do stay in StandBy */
    }

    // check if the MAINTENACE connector is plugged in
    if (CTB_dsiState.Maint_DSI_State == true)
    {
        tempMode = FSM_MODE_MAINTENANCE;
    }
    else
    {
        // Nothing to do stay in StandBy
    }

    // check if there is a Critical Fault : if yes go to EMERGENCY and Break from the function
    if (ACT_errors.fastPowerDown.all != 0)

    {
        tempMode = FSM_MODE_EMERGENCY;
    }
    else
    {
        /* Nothing to do stay in StandBy */
    }

    // check if there's an EMER_STOP
    if (CTB_dsiState.EMERSTOP_DSI_State == true)
    {
        Mcu_PerformReset();
    }
    else
    {

    }

    if ((PWB_Flags.faults.flags.powerSupplyDown == true)
            || (COM_flags.moduleFlags.status.flags.shutDownReq == true))
    {
        tempMode = FSM_MODE_SHUTDOWN;
    }
    else
    {
        //Nothing to do stay in EMERGENCY
    }

    return (tempMode);
}

/*!     \brief FSM Check Power On Mode Exit function
 *      \param none
 *      \return new mode
 */
static FSM_ModesE fsm_CheckBoostModeExit(void)
{
    FSM_ModesE tempMode = FSM_MODE_BOOST;

    if ((PWB_Flags.faults.flags.powerSupplyDown == true)
            || (COM_flags.moduleFlags.status.flags.shutDownReq == true))
    {
        tempMode = FSM_MODE_SHUTDOWN;
    }
    else
    {
        //Nothing to do stay in BOOST
    }

    if ((PWB_Flags.faults.flags.stopBoostConversion == true)
            && (ACT_errors.warningsMask.warningsFlags.autonomousBoostEnd == true)) // check if the warning is active and not masked
    {
        tempMode = FSM_MODE_STANDBY;
        FSM_errors.autonomousBoostEnd = true;
    }
    else
    {
        //Nothing to do stay in BOOST
        FSM_errors.autonomousBoostEnd = false;
    }

    // check there's a STOP or ShutDown Request
    if (COM_flags.moduleFlags.status.flags.stopRequest == true)
    {
        tempMode = FSM_MODE_STANDBY; // go to stand by
    }
    else
    {
        /* Nothing to do stay in BOOST */
    }
    // check for critical Errors
    if (ACT_errors.fastPowerDown.all != 0) // if there's any error go to emergency
    {
        tempMode = FSM_MODE_EMERGENCY;
    }
    // check for EMER_STOP
    if (CTB_dsiState.EMERSTOP_DSI_State == true)
    {
        Mcu_PerformReset();
    }
    else
    {
        /* Nothing to do stay in BOOST */
    }

    return (tempMode);
}

/*!     \brief FSM Check Running Mode Exit function
 *      \param none
 *      \return new mode
 */
static FSM_ModesE fsm_CheckBuckModeExit(void)
{
    FSM_ModesE tempMode = FSM_MODE_BUCK;

    if ((PWB_Flags.faults.flags.powerSupplyDown == true)
            || (COM_flags.moduleFlags.status.flags.shutDownReq == true))
    {
        tempMode = FSM_MODE_SHUTDOWN;
    }
    else
    {
        //Nothing to do stay in BUCK
    }

    if ((PWB_Flags.faults.flags.stopBuckConversion == true)
            && (ACT_errors.warningsMask.warningsFlags.autonomousBuckEnd == true)) // check if the warning is active and not masked
    {
        tempMode = FSM_MODE_STANDBY;
        FSM_errors.autonomousBuckEnd = true;
    }
    else
    {
        //Nothing to do stay in BUCK
        FSM_errors.autonomousBuckEnd = false;
    }

    // check there's a STOP or ShutDown Request
    if (COM_flags.moduleFlags.status.flags.stopRequest == true)
    {
        tempMode = FSM_MODE_STANDBY; // go to stand by
    }
    else
    {
        /* Nothing to do stay in BUCK */
    }
    // check for critical Errors
    if (ACT_errors.fastPowerDown.all != 0) // if there's any error go to emergency
    {
        tempMode = FSM_MODE_EMERGENCY;
    }
    // check for EMER_STOP
    if (CTB_dsiState.EMERSTOP_DSI_State == true)
    {
        Mcu_PerformReset();
    }
    else
    {
        /* Nothing to do stay in BUCK */
    }
    return (tempMode);
}

/*!     \brief FSM Check Settings Mode Exit function
 *      \param none
 *      \return new mode
 */
static FSM_ModesE fsm_CheckEmergencyModeExit(void)
{
    FSM_ModesE tempMode = FSM_MODE_EMERGENCY;

    if ((PWB_Flags.faults.flags.powerSupplyDown == true)
            || (COM_flags.moduleFlags.status.flags.shutDownReq == true))
    {
        tempMode = FSM_MODE_SHUTDOWN;
    }
    else
    {
        //Nothing to do stay in EMERGENCY
    }

    // check if there's a EMER_STOP
    if (CTB_dsiState.EMERSTOP_DSI_State == true)
    {
        Mcu_PerformReset();
    }
    else
    {
        //Nothing to do stay in EMERGENCY
    }
    // MaintenanceConnector plugged in
    if (CTB_dsiState.Maint_DSI_State == true)
    {
        tempMode = FSM_MODE_MAINTENANCE; // go to maintenance
    }
    else
    {
        //Nothing to do stay in EMERGENCY
    }

    // check we executed the ERROR rest and there's no Critical Errors.

    if (ACT_errors.fastPowerDown.all == 0)
    {
        tempMode = FSM_MODE_STANDBY;
    }
    else
    {
        /* Stay in Emergency Mode till all the errors are whiped out*/
    }

    return (tempMode);
}

/*!     \brief FSM Check Maintenance Mode Exit function
 *      \param none
 *      \return new mode
 */
static FSM_ModesE fsm_CheckMaintenanceModeExit(void)
{

    FSM_ModesE tempMode = FSM_MODE_MAINTENANCE;

    // MaintenanceConnector unplugged
    if (CTB_dsiState.Maint_DSI_State == false)
    {
        Mcu_PerformReset();
    }
    else
    {
        /* Nothing to do stay in MAINTENANCE */
    }

    if ((COM_flags.moduleFlags.status.flags.boostRequest == true)
            || (COM_flags.moduleFlags.status.flags.buckRequest == true))
    {
        // raise the error flag, you can't command the BB-AUX to go to boost or buck while in maintenance
        FSM_errors.bbAuxInMaintMode = true;
    }
    else
    {
        FSM_errors.bbAuxInMaintMode = false;
    }
    return (tempMode);
}

static FSM_ModesE fsm_CheckShutdownModeExit(void) //TRO_50073_50147_001_TRS_0031
{
    FSM_ModesE tempMode = FSM_MODE_SHUTDOWN;

    if (PWB_Flags.faults.flags.activityextensionTimerElapsed == true
            && PWB_Flags.faults.flags.powerSupplyDown == false)
    {
        tempMode = FSM_MODE_STANDBY;
    }
    else
    {
        tempMode = FSM_MODE_SHUTDOWN;
    }
    return (tempMode);
}

static FSM_ModesE fsm_CheckS3ModeExit(void)
{
    // check if S3 req is Flase
    FSM_ModesE tempMode = FSM_MODE_S3MODE;
    if (COM_mode.S3ModeReq == false)
    {
        tempMode = FSM_MODE_STANDBY; // if yes go back to standby
    }
    else
    {
        tempMode = FSM_MODE_S3MODE; // if not stay in S3
    }

    if ((PWB_Flags.faults.flags.powerSupplyDown == true)
            || (COM_flags.moduleFlags.status.flags.shutDownReq == true))
    {
        tempMode = FSM_MODE_SHUTDOWN; // if detected a shutdown
    }
    else
    {
        tempMode = FSM_MODE_S3MODE; // if not stay in S3
    }

    if (ACT_errors.fastPowerDown.all != 0) // if there's any error go to emergency
    {
        tempMode = FSM_MODE_EMERGENCY;
    }
    else
    {
        tempMode = FSM_MODE_S3MODE; // if not stay in S
    }

    if (CTB_dsiState.EMERSTOP_DSI_State == true)
    {
        Mcu_PerformReset();
    }
    else
    {
        //Nothing to do stay in S3 Mode
    }

    return (tempMode);
}

/*!     \brief FSM Manage internal Mode function
 *       \param none
 *       \return none
 */
static void fsm_ManageInternalMode(void)
{
    switch (FSM_mode)
    {
        case FSM_MODE_INIT:
            FSM_mode = fsm_CheckInitModeExit();
            break;
            /* Pbit sequence */
        case FSM_MODE_PBIT:
            FSM_mode = fsm_CheckPBitModeExit();
            break;
            /* Standby */
        case FSM_MODE_STANDBY:
            FSM_mode = fsm_CheckStandbyModeExit();
            break;
        case FSM_MODE_BUCK:
            FSM_mode = fsm_CheckBuckModeExit();
            break;
        case FSM_MODE_BOOST:
            FSM_mode = fsm_CheckBoostModeExit();
            break;
            /* Emergency */
        case FSM_MODE_EMERGENCY:
            FSM_mode = fsm_CheckEmergencyModeExit();
            break;
            /* Maintenance */
        case FSM_MODE_MAINTENANCE:
            FSM_mode = fsm_CheckMaintenanceModeExit();
            break;
        case FSM_MODE_SHUTDOWN:
            FSM_mode = fsm_CheckShutdownModeExit();
            break;
        case FSM_MODE_S3MODE:
            FSM_mode = fsm_CheckS3ModeExit();
            break;
        default:
            // handle the ERROR of no MODE to enter or to exit
            break;
    }
}
