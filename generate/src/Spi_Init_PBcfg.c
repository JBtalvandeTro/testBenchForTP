/**   
*   @file    Spi_PBcfg.c
*   @implements Spi_PBcfg.c_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Spi - Post-Build(PB) configuration file code template.
*   @details Code template for Post-Build(PB) configuration file generation.
*
*   @addtogroup SPI_DRIVER_CONFIGURATION Spi Driver Configuration
*   @{
*/
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : LPSPI
*   Dependencies         : 
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

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Spi.h"
#include "Spi_Ipw_Init_PBcfg.h"

#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#include "Dem.h"
#endif

/*==================================================================================================
*                                    SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_INIT_MODULE_ID_PBCFG_C                        83
#define SPI_INIT_VENDOR_ID_PBCFG_C                        43
#define SPI_INIT_AR_RELEASE_MAJOR_VERSION_PBCFG_C         4
#define SPI_INIT_AR_RELEASE_MINOR_VERSION_PBCFG_C         4

#define SPI_INIT_AR_RELEASE_REVISION_VERSION_PBCFG_C      0
#define SPI_INIT_SW_MAJOR_VERSION_PBCFG_C                 1
#define SPI_INIT_SW_MINOR_VERSION_PBCFG_C                 0
#define SPI_INIT_SW_PATCH_VERSION_PBCFG_C                 1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and SPI header file are of the same vendor */
#if (SPI_INIT_VENDOR_ID_PBCFG_C != SPI_VENDOR_ID)
    #error "Spi_PBCfg.c and Spi.h have different vendor ids"
#endif
/* Check if current file and SPI header file are of the same Autosar version */
#if ((SPI_INIT_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != SPI_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_INIT_AR_RELEASE_MINOR_VERSION_PBCFG_C    != SPI_AR_RELEASE_MINOR_VERSION) || \
     (SPI_INIT_AR_RELEASE_REVISION_VERSION_PBCFG_C != SPI_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Spi_PBCfg.c and Spi.h are different"
#endif
/* Check if current file and SPI header file are of the same Software version */
#if ((SPI_INIT_SW_MAJOR_VERSION_PBCFG_C != SPI_SW_MAJOR_VERSION) || \
     (SPI_INIT_SW_MINOR_VERSION_PBCFG_C != SPI_SW_MINOR_VERSION) || \
     (SPI_INIT_SW_PATCH_VERSION_PBCFG_C != SPI_SW_PATCH_VERSION))
    #error "Software Version Numbers of Spi_PBCfg.c and Spi.h are different"
#endif

/* Check if current file and SPI header file are of the same vendor */
#if (SPI_INIT_VENDOR_ID_PBCFG_C != SPI_IPW_VENDOR_ID_INIT_PBCFG_H)
    #error "Spi_PBCfg.c and Spi_Ipw_PBCfg.h have different vendor ids"
#endif
/* Check if current file and SPI header file are of the same Autosar version */
#if ((SPI_INIT_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != SPI_IPW_AR_RELEASE_MAJOR_VERSION_INIT_PBCFG_H) || \
     (SPI_INIT_AR_RELEASE_MINOR_VERSION_PBCFG_C    != SPI_IPW_AR_RELEASE_MINOR_VERSION_INIT_PBCFG_H) || \
     (SPI_INIT_AR_RELEASE_REVISION_VERSION_PBCFG_C != SPI_IPW_AR_RELEASE_REVISION_VERSION_INIT_PBCFG_H ))
    #error "AutoSar Version Numbers of Spi_PBCfg.c and Spi_Ipw_PBCfg.h are different"
#endif
/* Check if current file and SPI header file are of the same Software version */
#if ((SPI_INIT_SW_MAJOR_VERSION_PBCFG_C != SPI_IPW_SW_MAJOR_VERSION_INIT_PBCFG_H) || \
     (SPI_INIT_SW_MINOR_VERSION_PBCFG_C != SPI_IPW_SW_MINOR_VERSION_INIT_PBCFG_H) || \
     (SPI_INIT_SW_PATCH_VERSION_PBCFG_C != SPI_IPW_SW_PATCH_VERSION_INIT_PBCFG_H))
    #error "Software Version Numbers of Spi_PBCfg.c and Spi_Ipw_PBCfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
/* Check if current file and Dem.h file are of the same Autosar version */
#if ((SPI_INIT_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != DEM_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_INIT_AR_RELEASE_MINOR_VERSION_PBCFG_C    != DEM_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Spi_PBCfg.c and Dem.h are different"
#endif
#endif
#endif

/*==================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

/* List Of Notification Functions */
/* Job start/end Notifications */
/* Sequence End Notifications */
extern void spc_RxGetLowVoltageMeasures(void); /* End Notification for Sequence SpiSequence_GetLowVoltageMeasures */
extern void spc_RxGetHvVoltageMeasures(void); /* End Notification for Sequence SpiSequence_GetHvVoltageMeasures */
extern void spc_RxGetHvCurrentMeasures(void); /* End Notification for Sequence SpiSequence_GetHvCurrentMeasures */
extern void spc_RxGetHvTemperaturesMeasures(void); /* End Notification for Sequence SpiSequence_GetHvTemperaturesMeasures */

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"
/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2)))
    #define SPI_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define SPI_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif /* ((SPI_DMA_USED == STD_ON) && ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) ||
        (SPI_LEVEL_DELIVERED == SPI_LEVEL2))) */
#include "Spi_MemMap.h"

/* Buffers Descriptors for EB Channels and Allocate Buffers for IB Channels */
static Spi_BufferDescriptorType Spi_Buffer_Init_SpiChannel_0;
static Spi_BufferDescriptorType Spi_Buffer_Init_SpiChannel_1;

#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) || (SPI_LEVEL_DELIVERED == SPI_LEVEL2)))
    #define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif /* ((SPI_DMA_USED == STD_ON) && ((SPI_LEVEL_DELIVERED == SPI_LEVEL1) ||
        (SPI_LEVEL_DELIVERED == SPI_LEVEL2))) */
#include "Spi_MemMap.h"

#define SPI_START_SEC_VAR_INIT_UNSPECIFIED
#include "Spi_MemMap.h"

/* Buffers Descriptors for IB Channels */

#define SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Spi_MemMap.h"
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#define SPI_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"

/* Channel Configuration */
/* Channel Configuration for SpiChannel_0 */
static const Spi_ChannelConfigType Spi_ChannelConfig_SpiChannel_0_Init =
{
        EB,  /* BufferType IB or EB */
        8U,   /* Frame size */
        (boolean)FALSE, /* Bite order, 1:LSB, 0: MSB */
#ifdef SPI_HALF_DUPLEX_MODE_SUPPORT
  #if (STD_ON == SPI_HALF_DUPLEX_MODE_SUPPORT)
            SPI_FULL_DUPLEX,
              #endif
#endif

        (uint32)1U,  /* DefaultTransmitValue (configured) */
        32U, /* length of buffer */
        &Spi_Buffer_Init_SpiChannel_0, /* BufferDescriptor */
        SPI_SPURIOUS_CORE_ID_U32,  /* Core Id */
        &Spi_axSpiChannelState[0U] /* ChannelState pointer */
};
/* Channel Configuration for SpiChannel_1 */
static const Spi_ChannelConfigType Spi_ChannelConfig_SpiChannel_1_Init =
{
        EB,  /* BufferType IB or EB */
        8U,   /* Frame size */
        (boolean)FALSE, /* Bite order, 1:LSB, 0: MSB */
#ifdef SPI_HALF_DUPLEX_MODE_SUPPORT
  #if (STD_ON == SPI_HALF_DUPLEX_MODE_SUPPORT)
            SPI_FULL_DUPLEX,
              #endif
#endif

        (uint32)1U,  /* DefaultTransmitValue (configured) */
        32U, /* length of buffer */
        &Spi_Buffer_Init_SpiChannel_1, /* BufferDescriptor */
        SPI_SPURIOUS_CORE_ID_U32,  /* Core Id */
        &Spi_axSpiChannelState[1U] /* ChannelState pointer */
};
/* Spi_aChannelConfigList_Init Channel Configuration */
static const Spi_ChannelsCfgType Spi_aChannelConfigList_Init[2] =
{
    /* SpiChannel_0 */
    {
        &Spi_ChannelConfig_SpiChannel_0_Init
    },
    /* SpiChannel_1 */
    {
        &Spi_ChannelConfig_SpiChannel_1_Init
    }
};

/* Channel Assignment of Jobs */
/* Spi_GetLwVoltageMeasures */
static const Spi_ChannelType Spi_Spi_GetLwVoltageMeasures_ChannelAssignment_Init[1] =
{
    SpiConf_SpiChannel_SpiChannel_1 
};
/* Spi_GetHvVoltageMeasures */
static const Spi_ChannelType Spi_Spi_GetHvVoltageMeasures_ChannelAssignment_Init[1] =
{
    SpiConf_SpiChannel_SpiChannel_0 
};
/* Spi_GetHvCurrentMeasures */
static const Spi_ChannelType Spi_Spi_GetHvCurrentMeasures_ChannelAssignment_Init[1] =
{
    SpiConf_SpiChannel_SpiChannel_0 
};
/* Spi_GetHvTemperaturesMeasures */
static const Spi_ChannelType Spi_Spi_GetHvTemperaturesMeasures_ChannelAssignment_Init[1] =
{
    SpiConf_SpiChannel_SpiChannel_0 
};

/* Configuration of Jobs */
/* Job Configuration for Spi_GetLwVoltageMeasures */
static const Spi_JobConfigType Spi_JobConfig_Spi_GetLwVoltageMeasures_Init =
{
        (Spi_ChannelType)1U, /* NumChannels field */
        Spi_Spi_GetLwVoltageMeasures_ChannelAssignment_Init, /* List of Channels */
        NULL_PTR, /* End Notification */
        NULL_PTR, /* Start Notification */
        (sint8)0, /* Priority */
        SPI_SPURIOUS_CORE_ID_U32,    /* Core ID */
        &Spi_axSpiJobState[0], /* JobState instance */
        CSIB0, /* HWUnit index */
        SPI_LowVoltageMeasurment, /* External Device */
        &Spi_aExternalDeviceConfigList_Init[SPI_LowVoltageMeasurment] /* ExternalDeviceConfig - pointer to the external device configuration */
};
/* Job Configuration for Spi_GetHvVoltageMeasures */
static const Spi_JobConfigType Spi_JobConfig_Spi_GetHvVoltageMeasures_Init =
{
        (Spi_ChannelType)1U, /* NumChannels field */
        Spi_Spi_GetHvVoltageMeasures_ChannelAssignment_Init, /* List of Channels */
        NULL_PTR, /* End Notification */
        NULL_PTR, /* Start Notification */
        (sint8)0, /* Priority */
        SPI_SPURIOUS_CORE_ID_U32,    /* Core ID */
        &Spi_axSpiJobState[1], /* JobState instance */
        CSIB2, /* HWUnit index */
        SPI_HighVoltageMeasurment, /* External Device */
        &Spi_aExternalDeviceConfigList_Init[SPI_HighVoltageMeasurment] /* ExternalDeviceConfig - pointer to the external device configuration */
};
/* Job Configuration for Spi_GetHvCurrentMeasures */
static const Spi_JobConfigType Spi_JobConfig_Spi_GetHvCurrentMeasures_Init =
{
        (Spi_ChannelType)1U, /* NumChannels field */
        Spi_Spi_GetHvCurrentMeasures_ChannelAssignment_Init, /* List of Channels */
        NULL_PTR, /* End Notification */
        NULL_PTR, /* Start Notification */
        (sint8)0, /* Priority */
        SPI_SPURIOUS_CORE_ID_U32,    /* Core ID */
        &Spi_axSpiJobState[2], /* JobState instance */
        CSIB2, /* HWUnit index */
        SPI_HighVoltageMeasurment, /* External Device */
        &Spi_aExternalDeviceConfigList_Init[SPI_HighVoltageMeasurment] /* ExternalDeviceConfig - pointer to the external device configuration */
};
/* Job Configuration for Spi_GetHvTemperaturesMeasures */
static const Spi_JobConfigType Spi_JobConfig_Spi_GetHvTemperaturesMeasures_Init =
{
        (Spi_ChannelType)1U, /* NumChannels field */
        Spi_Spi_GetHvTemperaturesMeasures_ChannelAssignment_Init, /* List of Channels */
        NULL_PTR, /* End Notification */
        NULL_PTR, /* Start Notification */
        (sint8)0, /* Priority */
        SPI_SPURIOUS_CORE_ID_U32,    /* Core ID */
        &Spi_axSpiJobState[3], /* JobState instance */
        CSIB2, /* HWUnit index */
        SPI_HighVoltageMeasurment, /* External Device */
        &Spi_aExternalDeviceConfigList_Init[SPI_HighVoltageMeasurment] /* ExternalDeviceConfig - pointer to the external device configuration */
};
/* Spi_aJobConfigList_Init Job Configuration*/
static const Spi_JobsCfgType Spi_aJobConfigList_Init[4] =
{
    /* Spi_GetLwVoltageMeasures */
    {
        &Spi_JobConfig_Spi_GetLwVoltageMeasures_Init
    },
    /* Spi_GetHvVoltageMeasures */
    {
        &Spi_JobConfig_Spi_GetHvVoltageMeasures_Init
    },
    /* Spi_GetHvCurrentMeasures */
    {
        &Spi_JobConfig_Spi_GetHvCurrentMeasures_Init
    },
    /* Spi_GetHvTemperaturesMeasures */
    {
        &Spi_JobConfig_Spi_GetHvTemperaturesMeasures_Init
    }
};

/* Job Assignment of Sequences  */
/* SpiSequence_GetLowVoltageMeasures */
static const Spi_JobType Spi_SpiSequence_GetLowVoltageMeasures_JobAssignment_Init[1] =
{
    SpiConf_SpiJob_Spi_GetLwVoltageMeasures 
};
/* SpiSequence_GetHvVoltageMeasures */
static const Spi_JobType Spi_SpiSequence_GetHvVoltageMeasures_JobAssignment_Init[1] =
{
    SpiConf_SpiJob_Spi_GetHvVoltageMeasures 
};
/* SpiSequence_GetHvCurrentMeasures */
static const Spi_JobType Spi_SpiSequence_GetHvCurrentMeasures_JobAssignment_Init[1] =
{
    SpiConf_SpiJob_Spi_GetHvCurrentMeasures 
};
/* SpiSequence_GetHvTemperaturesMeasures */
static const Spi_JobType Spi_SpiSequence_GetHvTemperaturesMeasures_JobAssignment_Init[1] =
{
    SpiConf_SpiJob_Spi_GetHvTemperaturesMeasures 
};

/* Configuration of Sequences */
/* Sequence Configuration for SpiSequence_GetLowVoltageMeasures */
static const Spi_SequenceConfigType Spi_SequenceConfig_SpiSequence_GetLowVoltageMeasures_Init =
{
        (Spi_JobType)1U,  /* Number of Job in Seq */
        SPI_SPURIOUS_CORE_ID_U32,
        Spi_SpiSequence_GetLowVoltageMeasures_JobAssignment_Init, /* List of Jobs */
        &spc_RxGetLowVoltageMeasures, /* End Notification */
        (uint8)FALSE  /* Interruptible */
        #if ((SPI_DMA_USED == STD_ON) && (SPI_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON))
        , (boolean)FALSE /* Enable Dma fast transfer */
        #endif
};
/* Sequence Configuration for SpiSequence_GetHvVoltageMeasures */
static const Spi_SequenceConfigType Spi_SequenceConfig_SpiSequence_GetHvVoltageMeasures_Init =
{
        (Spi_JobType)1U,  /* Number of Job in Seq */
        SPI_SPURIOUS_CORE_ID_U32,
        Spi_SpiSequence_GetHvVoltageMeasures_JobAssignment_Init, /* List of Jobs */
        &spc_RxGetHvVoltageMeasures, /* End Notification */
        (uint8)FALSE  /* Interruptible */
        #if ((SPI_DMA_USED == STD_ON) && (SPI_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON))
        , (boolean)FALSE /* Enable Dma fast transfer */
        #endif
};
/* Sequence Configuration for SpiSequence_GetHvCurrentMeasures */
static const Spi_SequenceConfigType Spi_SequenceConfig_SpiSequence_GetHvCurrentMeasures_Init =
{
        (Spi_JobType)1U,  /* Number of Job in Seq */
        SPI_SPURIOUS_CORE_ID_U32,
        Spi_SpiSequence_GetHvCurrentMeasures_JobAssignment_Init, /* List of Jobs */
        &spc_RxGetHvCurrentMeasures, /* End Notification */
        (uint8)FALSE  /* Interruptible */
        #if ((SPI_DMA_USED == STD_ON) && (SPI_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON))
        , (boolean)FALSE /* Enable Dma fast transfer */
        #endif
};
/* Sequence Configuration for SpiSequence_GetHvTemperaturesMeasures */
static const Spi_SequenceConfigType Spi_SequenceConfig_SpiSequence_GetHvTemperaturesMeasures_Init =
{
        (Spi_JobType)1U,  /* Number of Job in Seq */
        SPI_SPURIOUS_CORE_ID_U32,
        Spi_SpiSequence_GetHvTemperaturesMeasures_JobAssignment_Init, /* List of Jobs */
        &spc_RxGetHvTemperaturesMeasures, /* End Notification */
        (uint8)FALSE  /* Interruptible */
        #if ((SPI_DMA_USED == STD_ON) && (SPI_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON))
        , (boolean)FALSE /* Enable Dma fast transfer */
        #endif
};
/* Spi_aSequenceConfigList_Init Sequence Configuration */
static const Spi_SeqsConfigType Spi_aSequenceConfigList_Init[4] =
{
    /* SpiSequence_GetLowVoltageMeasures */
    {
        &Spi_SequenceConfig_SpiSequence_GetLowVoltageMeasures_Init
    },
    /* SpiSequence_GetHvVoltageMeasures */
    {
        &Spi_SequenceConfig_SpiSequence_GetHvVoltageMeasures_Init
    },
    /* SpiSequence_GetHvCurrentMeasures */
    {
        &Spi_SequenceConfig_SpiSequence_GetHvCurrentMeasures_Init
    },
    /* SpiSequence_GetHvTemperaturesMeasures */
    {
        &Spi_SequenceConfig_SpiSequence_GetHvTemperaturesMeasures_Init
    }
};
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
/* Spi Configuration */
 const Spi_ConfigType Spi_Config_Init=
{
    2U,  /* MaxExternalDevice - number of external devices */
    1U, /* SpiMaxChannel - number of channels */
    3U, /* SpiMaxJob - number of jobs */
    3U, /* SpiMaxSequence - number of sequences */
    SPI_SPURIOUS_CORE_ID_U32,   /* SpiCoreUse - used core */
    Spi_aChannelConfigList_Init, /* ChannelConfig */
    Spi_aJobConfigList_Init, /* JobConfig */
    Spi_aSequenceConfigList_Init, /* SequenceConfig */
    Spi_aExternalDeviceConfigList_Init, /* ExternalDeviceConfig */
    Spi_aHwUnitConfigList_Init /* HWUnitConfig */
#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    ,{ (uint32)STD_OFF, (uint32)0U} /* SPI_E_HARDWARE_ERROR parameters*/
#endif /* SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */  
};


#define SPI_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Spi_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */


