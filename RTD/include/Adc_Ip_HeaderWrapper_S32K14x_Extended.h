/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : ADC
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

#ifndef ADC_IP_HEADERWRAPPER_S32K14X_EXTENDED_H
#define ADC_IP_HEADERWRAPPER_S32K14X_EXTENDED_H

/**
*   @file
*
*   @addtogroup adc_ip Adc IPL
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/* Important Note: This file cannot be used independently.
*  It depends on platform header files to be included before including it */

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_IP_VENDOR_ID_HEADERWRAPPER_S32K14X_EXTENDED                      43
#define ADC_IP_AR_RELEASE_MAJOR_VERSION_HEADERWRAPPER_S32K14X_EXTENDED       4
#define ADC_IP_AR_RELEASE_MINOR_VERSION_HEADERWRAPPER_S32K14X_EXTENDED       4
#define ADC_IP_AR_RELEASE_REVISION_VERSION_HEADERWRAPPER_S32K14X_EXTENDED    0
#define ADC_IP_SW_MAJOR_VERSION_HEADERWRAPPER_S32K14X_EXTENDED               1
#define ADC_IP_SW_MINOR_VERSION_HEADERWRAPPER_S32K14X_EXTENDED               0
#define ADC_IP_SW_PATCH_VERSION_HEADERWRAPPER_S32K14X_EXTENDED               1

/*==================================================================================================
*                                     DEFINITIONS
==================================================================================================*/

/*
 * ADC_SC1ZZ_COUNT is the number of extended channels, there are 16 base
 * channels that are available on all K14X platforms, including this one
 */
#define ADC_MAX_CHAN_COUNT          (16u + ADC_SC1ZZ_COUNT)

/* Register access defines */
#define REG_ACCESS(reg, index)      (*(volatile uint32*)(&(((&(reg))[(index)]))))
#define REG_READ(reg, index)        (*(volatile const uint32*)(&(((&(reg))[(index)]))))

#define SC1(Base, RegIndex)         REG_ACCESS(Base->ASC1A, (RegIndex))
#define R(Base, RegIndex)           REG_READ(Base->ARA, (RegIndex))

#ifdef __cplusplus
}
#endif

/** @} */
#endif /* ADC_IP_HEADERWRAPPER_S32K14X_EXTENDED_H */
