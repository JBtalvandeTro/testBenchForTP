/*==================================================================================================
 *   Project              : RTD AUTOSAR 4.4
 *   Platform             : CORTEXM
 *   Peripheral           : 
 *   Dependencies         : none
 *
 *   Autosar Version      : 4.4.0
 *   Autosar Revision     : ASR_REL_4_4_REV_0000
 *   Autosar Conf.Variant :
 *   SW Version           : 1.0.0
 *   Build Version        : S32K1_RTD_1_0_0_ASR_REL_4_4_REV_0000_20210810
 *
 *   (c) Copyright 2020-2021 NXP Semiconductors
 *   All Rights Reserved.
 *
 *   NXP Confidential. This software is owned or controlled by NXP and may only be
 *   used strictly in accordance with the applicable license terms. By expressly
 *   accepting such terms or by downloading, installing, activating and/or otherwise
 *   using the software, you are agreeing that you have read, and that you agree to
 *   comply with and are bound by, such license terms. If you do not agree to be
 *   bound by the applicable license terms, then you may not retain, install,
 *   activate or otherwise use the software.
 ==================================================================================================*/

/**
 *   @file main.c
 *
 *   @addtogroup main_module main module documentation
 *   @{
 */
/* User inc */
#include "INI.h"
#include "CST.h"
#include "SCH.h"
#include "Port.h"
#include "Dio.h"
#include "Pwm.h"
/* LDRA_INSPECTED 293 S <justification start> Required for specific memory section placement <justification end> */
const uint32_t __attribute__((section (".appVersSec"))) appVers = CST_SW_VERSION;

/*LDRA_HEADER_END*/
/*!
 \brief The main function for the project.
 \details The startup initialization sequence is the following:
 * - startup asm routine
 * - main()
 */
int main(void)
{
#if 0
    /* Write your code here */

    /* Init phase */
    INI_InitDrivers();
    //INI_InitMiddlewares();
    //INI_InitLibrairies();
    //INI_InitModules();

    //Pwm_DeInit();
//    Spi_DeInit();
//    Pwm_SetPeriodAndDuty(MCU_LIFE, 0x2710, 0x0000);
//    Dio_WriteChannel(DioConf_DioChannel_MCU_FAULT, 0);

    volatile uint32_t delay = 55555; // 5ms
    volatile uint32_t delay1 = 555556; // 50ms
    volatile uint32_t delay2 = 55555;
    volatile uint32_t delay3 = 111111; // 10ms
    volatile uint32_t delay4 = 22222; // 2ms
    volatile uint32_t delay5 = 22222; // 2ms
    volatile uint32_t delay6 = 22222; // 2ms

    // Test MCU outputs
    Dio_WriteChannel(DioConf_DioChannel_EN_3V3_Power, STD_HIGH);

   // Dio_WriteChannel(DioConf_DioChannel_EN_CAN_MAINT, STD_HIGH);

    // Launch MCU_LED PWM to signal that Scheduler has been reached
    /* Set 2Hz 50% duty cycle pwm */
    Pwm_SetPeriodAndDuty(MCU_LED_1, 0xF424, PWM_50_DUTY_CYCLE);

    while(1)
    {
        __asm__ volatile("nop");
    }
#else
    /* Write your code here */

    /* Init phase */
    INI_InitDrivers();
    INI_InitMiddlewares();
    INI_InitLibrairies();
    INI_InitModules();

    /* Start the scheduling */
    SCH_Init();

    /* Main loop */
    /*LDRA_INSPECTED 28 D <justification start> Explicit while loop  <justification end> */
    while (1)
    {
        SCH_MainLoop();
    }
#endif
}

/** @} */
