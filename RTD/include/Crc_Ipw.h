/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : 
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

/* Prevention from multiple including the same header */
#ifndef CRC_IPW_H
#define CRC_IPW_H

/**
*   @file    Crc_Ipw.h
*
*   @version 1.0.1
*
*   @brief   AUTOSAR Crc - Crc Ipw driver source file.
*   @details
*
*   @defgroup CRC_IPW_DRIVER CRC IPW Driver
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
#include "Crc_Ip.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @brief Parameters that shall be published within the Crc driver header file and also in the
*        module's description file.
*
*/
#define CRC_IPW_VENDOR_ID                    43
#define CRC_IPW_AR_RELEASE_MAJOR_VERSION     4
#define CRC_IPW_AR_RELEASE_MINOR_VERSION     4
#define CRC_IPW_AR_RELEASE_REVISION_VERSION  0
#define CRC_IPW_SW_MAJOR_VERSION             1
#define CRC_IPW_SW_MINOR_VERSION             0
#define CRC_IPW_SW_PATCH_VERSION             1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if the files Crc_Ipw.h and Crc_Ip.h are of the same version */
#if (CRC_IPW_VENDOR_ID != CRC_IP_VENDOR_ID)
    #error "Crc_Ipw.h and Crc_Ip.h have different vendor ids"
#endif

/* Check if Crc_Ipw.h and Crc_Ip.h are of the same Autosar version */
#if ((CRC_IPW_AR_RELEASE_MAJOR_VERSION    != CRC_IP_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_IPW_AR_RELEASE_MINOR_VERSION    != CRC_IP_AR_RELEASE_MINOR_VERSION) || \
     (CRC_IPW_AR_RELEASE_REVISION_VERSION != CRC_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Crc_Ipw.h and Crc_Ip.h are different"
#endif

/* Check if Crc_Ipw.h and Crc_Ip.h are of the same Software version */
#if ((CRC_IPW_SW_MAJOR_VERSION != CRC_IP_SW_MAJOR_VERSION) || \
     (CRC_IPW_SW_MINOR_VERSION != CRC_IP_SW_MINOR_VERSION) || \
     (CRC_IPW_SW_PATCH_VERSION != CRC_IP_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Crc_Ipw.h and Crc_Ip.h are different"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"

/**
 * @brief   This function initializes the CRC Driver in IPW Layer.
 * @details This service is a non-reentrant function that shall initialize the Crc driver.
 *          The user must make sure that the clock is enabled.
 *
 * @param[in] pxCrcIpInit     - Pointer to the Crc specific configuration structure that contains static configuration.
 *
 * @return void
 *
 * @api
 *
 **/
#define Crc_Ipw_Init(pxCrcIpInit) Crc_Ip_Init(pxCrcIpInit)


/**
 * @brief   This function initializes the CRC Channel configuration by logicChannel's info
 * @details This service is a reentrant function that shall initialize parameters list for the CRC Channel.
 *          The list is composed of an array of Crc Channel parameters settings.
 *
 * @param[in]  Channel             - Logic Channel Tag defined by the user.
 * @param[in]  pxChannelConfig     - Specifies the Logic Channel Config defined by the user
 *
 * @return void
 *
 * @api
 *
 **/
#define Crc_Ipw_SetChannelConfig(Channel, pxChannelConfig) Crc_Ip_SetChannelConfig(Channel, pxChannelConfig)


/**
 * @brief   This function shall start algorithm calculate CRC in IPW layer.
 * @details This service is a reentrant function that shall start the Channel to calculate the CRC using the configured algorithm.
 *
 * @param[in]  Channel          - Logic Channel Tag defined by the user..
 * @param[in]  *pCrcData        - Pointer to the Crc Data Input.
 * @param[in]  CrcLength        - Length of pCrcData block to be calculated in bytes.
 * @param[in]  CrcStartValue    - Start value (seed Value) when the algorithm starts.
 * @param[in]  IsFirstCall      - TRUE: ignore CrcStartValue the initialization value is known by the chosen algorithm.
 *                              - FALSE: initialization CrcStartValue is interpreted to be the return value of the previous function
 *
 * @return  Result of CRC calculated.
 *
 * @api
 *
 **/
#define Crc_Ipw_SetChannelCalculate(Channel, pCrcData, CrcLength, CrcStartValue, IsFirstCall) Crc_Ip_SetChannelCalculate(Channel, pCrcData, CrcLength, CrcStartValue, IsFirstCall)


/**
 * @brief   This function get result CRC after finish calculated in IPW Layer.
 * @details This service is a function that shall get result CRC Channel parameters list
 *
 * @param[in]  Channel      - Logic Channel Tag defined by the user.
 *
 * @return void
 *
 * @api
 *
 **/
#define Crc_Ipw_GetChannelResult(Channel) Crc_Ip_GetChannelResult(Channel)


#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CRC_IPW_H */
