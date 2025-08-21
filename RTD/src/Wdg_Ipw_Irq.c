/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : Wdog,Ewm
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : S32K1_RTD_1_0_1_D2202_ASR_REL_4_4_REV_0000_20220224
*
*   (c) Copyright 2020-2022 NXP Semiconductors
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
*   @file
*
*   @addtogroup Wdg
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Mcal.h"
#include "Wdg_Ipw_Cfg_Defines.h"
#include "OsIf.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define WDG_IPW_IRQ_VENDOR_ID_C                      43
#define WDG_IPW_IRQ_AR_RELEASE_MAJOR_VERSION_C       4
#define WDG_IPW_IRQ_AR_RELEASE_MINOR_VERSION_C       4
#define WDG_IPW_IRQ_AR_RELEASE_REVISION_VERSION_C    0
#define WDG_IPW_IRQ_SW_MAJOR_VERSION_C               1
#define WDG_IPW_IRQ_SW_MINOR_VERSION_C               0
#define WDG_IPW_IRQ_SW_PATCH_VERSION_C               1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Wdog_Ip_Cfg_Defines configuration header file are of the same vendor */
#if (WDG_IPW_IRQ_VENDOR_ID_C != WDG_IPW_CFG_DEFINES_VENDOR_ID)
#error "Wdog_Ip_Irq.c and Wdog_Ip_Cfg_Defines.h have different vendor ids"
#endif

#if ((WDG_IPW_IRQ_AR_RELEASE_MAJOR_VERSION_C    != WDG_IPW_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_IPW_IRQ_AR_RELEASE_MINOR_VERSION_C    != WDG_IPW_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (WDG_IPW_IRQ_AR_RELEASE_REVISION_VERSION_C != WDG_IPW_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Wdog_Ip_Irq.c and Wdog_Ip_Cfg_Defines.h are different"
#endif

#if ((WDG_IPW_IRQ_SW_MAJOR_VERSION_C != WDG_IPW_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (WDG_IPW_IRQ_SW_MINOR_VERSION_C != WDG_IPW_CFG_DEFINES_SW_MINOR_VERSION) || \
     (WDG_IPW_IRQ_SW_PATCH_VERSION_C != WDG_IPW_CFG_DEFINES_SW_PATCH_VERSION))
#error "Software Version Numbers of Wdog_Ip_Irq.c and Wdog_Ip_Cfg_Defines.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal header file are of the same Autosar version */
    #if ((WDG_IPW_IRQ_AR_RELEASE_MAJOR_VERSION_C    != MCAL_AR_RELEASE_MAJOR_VERSION) || \
        (WDG_IPW_IRQ_AR_RELEASE_MINOR_VERSION_C     != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Wdog_Ip_Irq.c and Mcal.h are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and OsIf header file are of the same Autosar version */
    #if ((WDG_IPW_IRQ_AR_RELEASE_MAJOR_VERSION_C    != OSIF_AR_RELEASE_MAJOR_VERSION) || \
        (WDG_IPW_IRQ_AR_RELEASE_MINOR_VERSION_C     != OSIF_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Wdog_Ipw_Irq.c and OsIf.h are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                    GLOBAL FUNCTIONS PROTOTYPES
==================================================================================================*/
#ifdef WDG_ROM
    #if (WDG_ROM == 1U)
        #define WDG_START_SEC_CODE
    #endif
#else
    #if (WDG_RAM == 0U)
        #define WDG_START_SEC_RAMCODE
    #endif
#endif

#include "Wdg_MemMap.h"
/* Common interrupt for Wdg IPS - EWM and WDOG */
#if ((WDG_IPW_ISR0_USED == STD_ON) || (WDG_IPW_ISR1_USED == STD_ON))
ISR(Wdg_Ipw_Isr);
#endif

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#if (WDG_IPW_ISR0_USED == STD_ON)
extern void Wdog_Ip_IrqHandler(uint8 Instance);
#endif

#if (WDG_IPW_ISR1_USED == STD_ON)
extern void Ewm_Ip_IrqHandler(uint8 Instance);
#endif

#if ((WDG_IPW_ISR0_USED == STD_ON) || (WDG_IPW_ISR1_USED == STD_ON))
/**
* @brief   Wdg_Ipw handler for timeout interrupt.
* @details This function implements the ISR occurring on a Wdg timeout.
*
* @isr
*
*/
ISR(Wdg_Ipw_Isr)
{
#if (WDG_IPW_ISR0_USED == STD_ON)
    Wdog_Ip_IrqHandler(0U);
#endif

#if (WDG_IPW_ISR1_USED == STD_ON)
    Ewm_Ip_IrqHandler(0U);
#endif

    EXIT_INTERRUPT();
}
#endif /* ((WDG_IPW_ISR0_USED == STD_ON) || (WDG_IPW_ISR1_USED == STD_ON)) */

#ifdef WDG_ROM
    #if (WDG_ROM == 1U)
        #define WDG_STOP_SEC_CODE
    #endif
#else
    #if (WDG_RAM == 0U)
        #define WDG_STOP_SEC_RAMCODE
    #endif
#endif

#include "Wdg_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
