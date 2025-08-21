/*!
 * \file     INI.c
 * \brief    Initialization file which manages boot sequence of CPU
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

/* ---- Includes ---- */
#include "INI.h"
#include "SCH.h"

/* Modules */
#include "MPM.h"
#include "COM.h"
#include "FSM.h"
#include "CNV.h"
#include "CTB.h"
#include "PWB.h"
#include "DBG.h"
#include "FSMupdat.h"
#include "ACT.h"

/* Middlewares */
#include "CBUs.h"
#include "FLA.h"

/* Libraries */

/* Drivers */
#include "Mcal.h"
#include "Mcu.h"
#include "Mcl.h"
#include "Port.h"
#include "Platform.h"
#include "Gpt.h"
#include "Dio.h"
#include "Spi.h"
#include "Pwm.h"
#include "Can.h"
#include "Icu.h"
#include "CanIf.h"
#include "Crc.h"

/* ---- Defines ---- */

/* ---- Global variables ---- */

/* ---- External functions ---- */

/* ---- Static variables ---- */

/* ---- Static functions ---- */

/*LDRA_HEADER_END*/
/*!     \brief Initialization of all drivers
 *       \param none
 *       \return none
 */
void INI_InitDrivers(void)
{
    /*---- Initialize MCU / CLK MCAL ----*/
    Mcu_Init(&Mcu_Config_Init);
    (void) Mcu_InitClock(McuClockSettingConfig_0);
    /*LDRA_INSPECTED 28 D <justification start> Wait until the System PLL is locked  <justification end> */
    while (MCU_PLL_LOCKED != Mcu_GetPllStatus())
    {
        /* Busy wait until the System PLL is locked */
    }

    /* Manage the PLL presence / use or not */
#if (MCU_NO_PLL == STD_OFF)
    (void) Mcu_DistributePllClock();
#endif

    Mcu_SetMode(McuModeSettingConf_NormalClock);

    /*---- Initialize MCL ----*/
    Mcl_Init(&Mcl_Config_INIT);

    /*---- Initialize all pins using the Port driver ----*/
    Port_Init(&Port_Config_Init);

    /*---- Initialize Platform MCAL ----*/
    Platform_Init(NULL_PTR);

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
    Icu_Init(&Icu_Config_Init);

    /*---- Initialize PWMs with masked output ----*/
    /* Initializes PWM driver */
    Pwm_Init(&Pwm_Config_Init);

    /*---- Initializes CRC ----*/
    Crc_Init(&Crc_xConfigInit);

    /*---- Enable the Power ---- */
    Dio_WriteChannel(DioConf_DioChannel_EN_3V3_Power, STD_HIGH);

    Pwm_SetPeriodAndDuty(MCU_LED1, 0xEB51, PWM_50_DUTY_CYCLE);
    Pwm_SetPeriodAndDuty(MCU_LED2, 0xEB51, PWM_50_DUTY_CYCLE);
    Pwm_SetPeriodAndDuty(MCU_LED3, 0xEB51, PWM_50_DUTY_CYCLE);
    Pwm_SetPeriodAndDuty(MCU_LED4, 0xEB51, PWM_50_DUTY_CYCLE);
    Pwm_SetPeriodAndDuty(MCU_LED5, 0xEB51, PWM_50_DUTY_CYCLE);
    Pwm_SetPeriodAndDuty(MCU_LED6, 0xEB51, PWM_50_DUTY_CYCLE);

}

/*!     \brief Initialization of all middlewares
 *       \param none
 *       \return none
 */
void INI_InitMiddlewares(void)
{
    FLA_Init();
}

/*!     \brief Initialization of all librairies
 *       \param none
 *       \return none
 */
void INI_InitLibrairies(void)
{
}

/*!     \brief Initialization of all modules
 *       \param none
 *       \return none
 */
void INI_InitModules(void)
{
    /* Initializes ACT to set pointers on modules flags */
    ACT_Init();
    /* initializes all modules */
    PAR_Init();
    FSM_Init();
    MPM_Init();
    COM_Init();
    CNV_Init();
    CTB_Init();
    PWB_Init();
    DBG_Init();

    // Check if all modules are ok and leave INIT to PBIT
    FSM_Update();

    // Launch MCU_LEDS PWM to signal that Scheduler has been reached
    /* Set 2Hz 50% duty cycle pwm for STANDBY mode */

    Dio_WriteChannel(DioConf_DioChannel_EN_3V3_Power, STD_HIGH);

    Dio_WriteChannel(DioConf_DioChannel_DSI_EN1, STD_HIGH);
    Dio_WriteChannel(DioConf_DioChannel_DSI_EN2, STD_HIGH);
    Dio_WriteChannel(DioConf_DioChannel_DSI_EN3, STD_HIGH);
    Dio_WriteChannel(DioConf_DioChannel_DSI_EN4, STD_HIGH);
    Dio_WriteChannel(DioConf_DioChannel_DSI_EN5, STD_HIGH);
    Dio_WriteChannel(DioConf_DioChannel_DSI_EN6, STD_HIGH);

    Dio_WriteChannel(DioConf_DioChannel_DSO_28_EN, STD_HIGH);
    Dio_WriteChannel(DioConf_DioChannel_DSO_GND_EN, STD_HIGH);
}

/*!     \brief Deinitialization of all middlewares
 *       \param none
 *       \return none
 */
/*LDRA_INSPECTED 65 D <justification start> Deinit function - always present for maintenability  <justification end> */
void INI_DeinitDrivers(void)
{
    /* Nothing to do */
}

/*!     \brief Deinitialization of all middlewares
 *       \param none
 *       \return none
 */
void INI_DeinitMiddlewares(void)
{
    CBU_Deinit();
}

/*!     \brief Deinitialization of all librairies
 *       \param none
 *       \return none
 */
/*LDRA_INSPECTED 65 D <justification start> Deinit function - always present for maintenability  <justification end> */
void INI_DeinitLibrairies(void)
{
    /* Nothing to do */
}

/*!     \brief Deinitialization of all modules
 *       \param none
 *       \return none
 */
void INI_DeinitModules(void)
{
    FSM_Deinit();
    MPM_Deinit();
    CNV_Init();
    CNV_Deinit();
    SCH_Deinit();
    ACT_Deinit();
}
