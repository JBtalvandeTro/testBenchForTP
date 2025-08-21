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

#ifndef FTFC_FLS_IP_AC_H
#define FTFC_FLS_IP_AC_H

/**
*   @file Ftfc_Fls_Ip_Ac.h
*
*   @addtogroup FTFC_FLS_IP FTFC IP Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FTFC_FLS_IP_AC_VENDOR_ID_H                      43
#define FTFC_FLS_IP_AC_AR_RELEASE_MAJOR_VERSION_H       4
#define FTFC_FLS_IP_AC_AR_RELEASE_MINOR_VERSION_H       4
#define FTFC_FLS_IP_AC_AR_RELEASE_REVISION_VERSION_H    0
#define FTFC_FLS_IP_AC_SW_MAJOR_VERSION_H               1
#define FTFC_FLS_IP_AC_SW_MINOR_VERSION_H               0
#define FTFC_FLS_IP_AC_SW_PATCH_VERSION_H               1


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define FLS_START_SEC_CODE_AC
#include "Fls_MemMap.h"

#ifdef _LINARO_C_S32K1XX_
    void Ftfc_Fls_Ip_AccessCode(void (*CallBack)( void ) ) __attribute__ ((section (".acfls_code_rom")));
#else
    void Ftfc_Fls_Ip_AccessCode(void (*CallBack)( void ) );
#endif

#define FLS_STOP_SEC_CODE_AC
#include "Fls_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FTFC_FLS_IP_AC_H */
