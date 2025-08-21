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

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Wdg_Ipw.h"
#include "Det.h"
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define WDG_IPW_VENDOR_ID_C                      43
#define WDG_IPW_AR_RELEASE_MAJOR_VERSION_C       4
#define WDG_IPW_AR_RELEASE_MINOR_VERSION_C       4
#define WDG_IPW_AR_RELEASE_REVISION_VERSION_C    0
#define WDG_IPW_SW_MAJOR_VERSION_C               1
#define WDG_IPW_SW_MINOR_VERSION_C               0
#define WDG_IPW_SW_PATCH_VERSION_C               1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Wdg_Ipw header file are of the same vendor */
#if (WDG_IPW_VENDOR_ID_C != WDG_IPW_VENDOR_ID)
    #error "Wdg_Ipw.c and Wdg_Ipw.h have different vendor ids"
#endif

#if ((WDG_IPW_AR_RELEASE_MAJOR_VERSION_C     != WDG_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_IPW_AR_RELEASE_MINOR_VERSION_C     != WDG_IPW_AR_RELEASE_MINOR_VERSION) || \
     (WDG_IPW_AR_RELEASE_REVISION_VERSION_C  != WDG_IPW_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Wdg_Ipw.c and Wdg_Ipw.h are different"
#endif

#if ((WDG_IPW_SW_MAJOR_VERSION_C != WDG_IPW_SW_MAJOR_VERSION) || \
     (WDG_IPW_SW_MINOR_VERSION_C != WDG_IPW_SW_MINOR_VERSION) || \
     (WDG_IPW_SW_PATCH_VERSION_C != WDG_IPW_SW_PATCH_VERSION))
#error "Software Version Numbers of Wdg_Ipw.c and Wdg_Ipw.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if current file and Det header file are of the same Autosar version */
#if ((WDG_IPW_AR_RELEASE_MAJOR_VERSION_C     != DET_AR_RELEASE_MAJOR_VERSION) || \
    (WDG_IPW_AR_RELEASE_MINOR_VERSION_C     != DET_AR_RELEASE_MINOR_VERSION))
#error "AutoSar Version Numbers of Wdg_Ipw.c and Det.h are different"
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
#define WDG_START_SEC_VAR_INIT_UNSPECIFIED

#include "Wdg_MemMap.h"

static Wdg_Ipw_IpType Wdg_Ipw_aeIp[2] = {WDG_IPW_UNINIT_IP, WDG_IPW_UNINIT_IP};

#define WDG_STOP_SEC_VAR_INIT_UNSPECIFIED

#include "Wdg_MemMap.h"

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
*                                        GLOBAL FUNCTIONS
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

Std_ReturnType Wdg_Ipw_Init(Wdg_Ipw_InstanceType Instance, const Wdg_Ipw_ConfigType * const IpwConfig)
{
    Std_ReturnType Ret = (Std_ReturnType) E_OK;
#if (WDOG_IP_USED == STD_ON)
    Wdog_Ip_StatusType RetIp = WDOG_IP_STATUS_SUCCESS;
#endif /*(WDOG_IP_USED == STD_ON)*/

    Wdg_Ipw_aeIp[Instance] = IpwConfig->eWdgIp;

    switch (IpwConfig->eWdgIp)
    {
#if (WDOG_IP_USED == STD_ON)
        case WDG_IPW_WDOG_IP:
            RetIp = Wdog_Ip_Init((uint8)Instance, IpwConfig->pWdogConfig);
            if (RetIp != WDOG_IP_STATUS_SUCCESS)
            {
                if (WDOG_IP_STATUS_TIMEOUT == RetIp)
                {
                    /* Raise a runtime det for Osif timeout expired*/
                    (void)Det_ReportRuntimeError((uint16)WDG_IPW_MODULE_ID, (uint8)Instance, (uint8)WDG_IPW_INIT_ID, (uint8)WDG_IPW_E_PARAM_TIMEOUT);
                }
                Ret = (Std_ReturnType) E_NOT_OK;
            }
            break;
#endif /*(WDOG_IP_USED == STD_ON)*/
#if (EWM_IP_USED == STD_ON)
        case WDG_IPW_EWM_IP:

            (void)Instance;
            if (Ewm_Ip_Init((uint8)0, IpwConfig->pEwmConfig) != EWM_IP_STATUS_SUCCESS)
            {
                Ret = (Std_ReturnType) E_NOT_OK;
            }
            break;
#endif /*(EWM_IP_USED == STD_ON)*/
        default:

            Ret = (Std_ReturnType) E_NOT_OK;
            break;
    }
    
    return Ret;
}

Std_ReturnType Wdg_Ipw_SetMode(Wdg_Ipw_InstanceType Instance, const Wdg_Ipw_ConfigType * const IpwConfig)
{
    Std_ReturnType Ret = (Std_ReturnType) E_OK;
#if (WDOG_IP_USED == STD_ON)
    Wdog_Ip_StatusType RetIp = WDOG_IP_STATUS_SUCCESS;
#endif /*(WDOG_IP_USED == STD_ON)*/

    Wdg_Ipw_aeIp[Instance] = IpwConfig->eWdgIp;
    
    switch (Wdg_Ipw_aeIp[Instance])
    {
#if (WDOG_IP_USED == STD_ON)
        case WDG_IPW_WDOG_IP:
            RetIp = Wdog_Ip_Config((uint8)Instance, IpwConfig->pWdogConfig);
            if (RetIp != WDOG_IP_STATUS_SUCCESS)
            {
                if (WDOG_IP_STATUS_TIMEOUT == RetIp)
                {
                    /* Raise a runtime det for Osif timeout expired*/
                    (void)Det_ReportRuntimeError((uint16)WDG_IPW_MODULE_ID, (uint8)Instance, (uint8)WDG_IPW_SETMODE_ID, (uint8)WDG_IPW_E_PARAM_TIMEOUT);
                }
                Ret = (Std_ReturnType) E_NOT_OK;
            }
            break;
#endif /*(WDOG_IP_USED == STD_ON)*/
#if (EWM_IP_USED == STD_ON)
        case WDG_IPW_EWM_IP:
            (void)IpwConfig;
            Ret = (Std_ReturnType) E_NOT_OK;
            break;
#endif /*(EWM_IP_USED == STD_ON)*/
        default:
            Ret = (Std_ReturnType) E_NOT_OK;
            break;
    }

    return Ret;
}

Std_ReturnType Wdg_Ipw_StartTimer(Wdg_Ipw_InstanceType Instance)
{
    Std_ReturnType Ret = (Std_ReturnType) E_OK;
#if (WDOG_IP_USED == STD_ON)
    Wdog_Ip_StatusType RetIp = WDOG_IP_STATUS_SUCCESS;
#endif /*(WDOG_IP_USED == STD_ON)*/

    switch (Wdg_Ipw_aeIp[Instance])
    {
#if (WDOG_IP_USED == STD_ON)
        case WDG_IPW_WDOG_IP:

            RetIp = Wdog_Ip_StartTimer((uint8)Instance);
            if (RetIp != WDOG_IP_STATUS_SUCCESS)
            {
                if (WDOG_IP_STATUS_TIMEOUT == RetIp)
                {
                    /* Raise a runtime det for Osif timeout expired*/
                    (void)Det_ReportRuntimeError((uint16)WDG_IPW_MODULE_ID, (uint8)Instance, (uint8)WDG_IPW_SETMODE_ID, (uint8)WDG_IPW_E_PARAM_TIMEOUT);
                }
                Ret = (Std_ReturnType) E_NOT_OK;
            }
            break;
#endif /*(WDOG_IP_USED == STD_ON)*/
#if (EWM_IP_USED == STD_ON)
        case WDG_IPW_EWM_IP:

            Ret = (Std_ReturnType) E_NOT_OK;

            break;
#endif /*(EWM_IP_USED == STD_ON)*/
        default:

            Ret = (Std_ReturnType) E_NOT_OK;
            break;
    }
    
    return Ret;
}

#if (WDG_IPW_DEINIT == STD_ON)
Std_ReturnType Wdg_Ipw_StopTimer(Wdg_Ipw_InstanceType Instance)
{
    Std_ReturnType Ret = (Std_ReturnType) E_OK;
#if (WDOG_IP_USED == STD_ON)
    Wdog_Ip_StatusType RetIp = WDOG_IP_STATUS_SUCCESS;
#endif /*(WDOG_IP_USED == STD_ON)*/

    switch (Wdg_Ipw_aeIp[Instance])
    {
#if (WDOG_IP_USED == STD_ON)
        case WDG_IPW_WDOG_IP:

            RetIp = Wdog_Ip_StopTimer((uint8)Instance);
            if (RetIp != WDOG_IP_STATUS_SUCCESS)
            {
                if (WDOG_IP_STATUS_TIMEOUT == RetIp)
                {
                    /* Raise a runtime det for Osif timeout expired*/
                    (void)Det_ReportRuntimeError((uint16)WDG_IPW_MODULE_ID, (uint8)Instance, (uint8)WDG_IPW_SETMODE_ID, (uint8)WDG_IPW_E_PARAM_TIMEOUT);
                }
                Ret = (Std_ReturnType) E_NOT_OK;
            }
            break;
#endif /*(WDOG_IP_USED == STD_ON)*/
#if (EWM_IP_USED == STD_ON)
        case WDG_IPW_EWM_IP:

            Ret = (Std_ReturnType) E_NOT_OK;

            break;
#endif /*(EWM_IP_USED == STD_ON)*/
        default:
            Ret = (Std_ReturnType) E_NOT_OK;
            break;
    }

    return Ret;
}
#endif

void Wdg_Ipw_Service(Wdg_Ipw_InstanceType Instance)
{

    switch (Wdg_Ipw_aeIp[Instance])
    {
#if (WDOG_IP_USED == STD_ON)
        case WDG_IPW_WDOG_IP:

            Wdog_Ip_Service((uint8)Instance);
            break;
#endif /*(WDOG_IP_USED == STD_ON)*/
#if (EWM_IP_USED == STD_ON)
        case WDG_IPW_EWM_IP:

            (void)Instance;
            Ewm_Ip_Service((uint8)0);
            break;
#endif /*(EWM_IP_USED == STD_ON)*/
        default:
            /* do nothing*/
            break;
    }
}

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

/** @} */
