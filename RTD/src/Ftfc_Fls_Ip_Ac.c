/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : FTFC_FLS_IP IPV_QSPI
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
*   @file Ftfc_Fls_Ip_Ac.c
*
*   @addtogroup FTFC_FLS_IP FTFC IP Driver
*   @{
*/

/* implements Ftfc_Fls_Ip_Ac.c_Artifact */
#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Ftfc_Fls_Ip.h"
#include "Ftfc_Fls_Ip_Cfg.h"
#include "Ftfc_Fls_Ip_Ac.h"


/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FTFC_FLS_IP_AC_VENDOR_ID_C                      43
#define FTFC_FLS_IP_AC_AR_RELEASE_MAJOR_VERSION_C       4
#define FTFC_FLS_IP_AC_AR_RELEASE_MINOR_VERSION_C       4
#define FTFC_FLS_IP_AC_AR_RELEASE_REVISION_VERSION_C    0
#define FTFC_FLS_IP_AC_SW_MAJOR_VERSION_C               1
#define FTFC_FLS_IP_AC_SW_MINOR_VERSION_C               0
#define FTFC_FLS_IP_AC_SW_PATCH_VERSION_C               1


/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Ftfc_Fls_Ip header file are of the same vendor */
#if (FTFC_FLS_IP_AC_VENDOR_ID_C != FTFC_FLS_IP_VENDOR_ID_H)
    #error "Fls_Ac.c and Ftfc_Fls_Ip.h have different vendor ids"
#endif
/* Check if current file and Ftfc_Fls_Ip header file are of the same Autosar version */
#if ((FTFC_FLS_IP_AC_AR_RELEASE_MAJOR_VERSION_C    != FTFC_FLS_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (FTFC_FLS_IP_AC_AR_RELEASE_MINOR_VERSION_C    != FTFC_FLS_IP_AR_RELEASE_MINOR_VERSION_H) || \
     (FTFC_FLS_IP_AC_AR_RELEASE_REVISION_VERSION_C != FTFC_FLS_IP_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Ftfc_Fls_Ip_Ac.c and Ftfc_Fls_Ip.h are different"
#endif
/* Check if current file and Ftfc_Fls_Ip header file are of the same Software version */
#if ((FTFC_FLS_IP_AC_SW_MAJOR_VERSION_C != FTFC_FLS_IP_SW_MAJOR_VERSION_H) || \
     (FTFC_FLS_IP_AC_SW_MINOR_VERSION_C != FTFC_FLS_IP_SW_MINOR_VERSION_H) || \
     (FTFC_FLS_IP_AC_SW_PATCH_VERSION_C != FTFC_FLS_IP_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Ftfc_Fls_Ip_Ac.c and Ftfc_Fls_Ip.h are different"
#endif

/* Check if current file and Ftfc_Fls_Ip_Ac.h header file have the same Vendor ID */
#if (FTFC_FLS_IP_AC_VENDOR_ID_C != FTFC_FLS_IP_AC_VENDOR_ID_H)
    #error "Ftfc_Fls_Ip_Ac.c and Ftfc_Fls_Ip_Ac.h have different vendor ids"
#endif
/* Check if current file and Ftfc_Fls_Ip_Ac.h  header file are of the same Autosar version */
#if ((FTFC_FLS_IP_AC_AR_RELEASE_MAJOR_VERSION_C    != FTFC_FLS_IP_AC_AR_RELEASE_MAJOR_VERSION_H) || \
     (FTFC_FLS_IP_AC_AR_RELEASE_MINOR_VERSION_C    != FTFC_FLS_IP_AC_AR_RELEASE_MINOR_VERSION_H) || \
     (FTFC_FLS_IP_AC_AR_RELEASE_REVISION_VERSION_C != FTFC_FLS_IP_AC_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Ftfc_Fls_Ip_Ac.c and Ftfc_Fls_Ip_Ac.h are different"
#endif
/* Check if current file and Ftfc_Fls_Ip_Ac.h  header file are of the same Software version */
#if ((FTFC_FLS_IP_AC_SW_MAJOR_VERSION_C != FTFC_FLS_IP_AC_SW_MAJOR_VERSION_H) || \
     (FTFC_FLS_IP_AC_SW_MINOR_VERSION_C != FTFC_FLS_IP_AC_SW_MINOR_VERSION_H) || \
     (FTFC_FLS_IP_AC_SW_PATCH_VERSION_C != FTFC_FLS_IP_AC_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Ftfc_Fls_Ip_Ac.c and Ftfc_Fls_Ip_Ac.h are different"
#endif

/* Check if current file and Ftfc_Fls_Ip_Cfg header file have the same Vendor ID */
#if (FTFC_FLS_IP_AC_VENDOR_ID_C != FTFC_FLS_IP_VENDOR_ID_CFG)
    #error "Ftfc_Fls_Ip_Ac.c and Ftfc_Fls_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Ftfc_Fls_Ip_Cfg.h  header file are of the same Autosar version */
#if ((FTFC_FLS_IP_AC_AR_RELEASE_MAJOR_VERSION_C    != FTFC_FLS_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (FTFC_FLS_IP_AC_AR_RELEASE_MINOR_VERSION_C    != FTFC_FLS_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (FTFC_FLS_IP_AC_AR_RELEASE_REVISION_VERSION_C != FTFC_FLS_IP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Ftfc_Fls_Ip_Ac.c and Ftfc_Fls_Ip_Cfg.h are different"
#endif
/* Check if current file and Ftfc_Fls_Ip_Cfg.h  header file are of the same Software version */
#if ((FTFC_FLS_IP_AC_SW_MAJOR_VERSION_C != FTFC_FLS_IP_SW_MAJOR_VERSION_CFG) || \
     (FTFC_FLS_IP_AC_SW_MINOR_VERSION_C != FTFC_FLS_IP_SW_MINOR_VERSION_CFG) || \
     (FTFC_FLS_IP_AC_SW_PATCH_VERSION_C != FTFC_FLS_IP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Ftfc_Fls_Ip_Ac.c and Ftfc_Fls_Ip_Cfg.h are different"
#endif


/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                      GLOBAL FUNCTIONS
==================================================================================================*/
#define FLS_START_SEC_CODE_AC
#include "Fls_MemMap.h"

/* Position independent erase access code */
#if (FTFC_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
void Ftfc_Fls_Ip_AccessCode(void (*CallBack)( void ) )
{
    uint32 u32ValueTimeOut = Ftfc_Fls_Ip_u32TimeoutTicks;
    uint32 u32WaitedTicks;

    FTFx_BaseAddress->FSTAT = FTFx_FSTAT_CCIF_MASK;
    /* wait until operation finishes or write/erase timeout is reached */
    while ((0U == ((FTFx_BaseAddress->FSTAT) & FTFx_FSTAT_CCIF_MASK)) && (0U < u32ValueTimeOut))
    {
        u32ValueTimeOut--;
        if (NULL_PTR != CallBack)
        {
            CallBack();
        }
    }

    /* Update the timeout counter */
    u32WaitedTicks = Ftfc_Fls_Ip_u32TimeoutTicks - u32ValueTimeOut;
    Ftfc_Fls_Ip_u32ElapsedTicks += u32WaitedTicks;
    Ftfc_Fls_Ip_u32CurrentTicks += u32WaitedTicks;
}
#else

void Ftfc_Fls_Ip_AccessCode(void (*CallBack)( void ) )
{
    /* start internal erase/program sequence */
    FTFx_BaseAddress->FSTAT = FTFx_FSTAT_CCIF_MASK;
    /* wait until operation finishes or write/erase timeout is reached */
    while (0U == ((FTFx_BaseAddress->FSTAT) & FTFx_FSTAT_CCIF_MASK))
    {
        if (NULL_PTR != CallBack)
        {
            CallBack();
        }
    }
}
#endif /* FTFC_TIMEOUT_SUPERVISION_ENABLED == STD_ON */

/**
 * @brief    Stop of Fls section CODE_AC
 *
 */
#define FLS_STOP_SEC_CODE_AC
#include "Fls_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
