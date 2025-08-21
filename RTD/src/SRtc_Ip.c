/*==================================================================================================
* Project : RTD AUTOSAR 4.4
* Platform : CORTEXM
* Peripheral : Ftm_Srtc_Lptmr_LPit
* Dependencies : none
*
* Autosar Version : 4.4.0
* Autosar Revision : ASR_REL_4_4_REV_0000
* Autosar Conf.Variant :
* SW Version : 1.0.1
* Build Version : S32K1_RTD_1_0_1_D2202_ASR_REL_4_4_REV_0000_20220224
*
* (c) Copyright 2020-2022 NXP Semiconductors
* All Rights Reserved.
*
* NXP Confidential. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/
/**
*   @file           SRtc_Ip.c
*
*   @addtogroup     srtc_ip Rtc IPL
*
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "SRtc_Ip.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define SRTC_IP_VENDOR_ID_C                    43
#define SRTC_IP_AR_RELEASE_MAJOR_VERSION_C     4
#define SRTC_IP_AR_RELEASE_MINOR_VERSION_C     4
#define SRTC_IP_AR_RELEASE_REVISION_VERSION_C  0
#define SRTC_IP_SW_MAJOR_VERSION_C             1
#define SRTC_IP_SW_MINOR_VERSION_C             0
#define SRTC_IP_SW_PATCH_VERSION_C             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (SRTC_IP_VENDOR_ID_C != SRTC_IP_VENDOR_ID)
    #error "SRtc_Ip.c and SRtc_Ip.h have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((SRTC_IP_AR_RELEASE_MAJOR_VERSION_C != SRTC_IP_AR_RELEASE_MAJOR_VERSION) || \
     (SRTC_IP_AR_RELEASE_MINOR_VERSION_C != SRTC_IP_AR_RELEASE_MINOR_VERSION) || \
     (SRTC_IP_AR_RELEASE_REVISION_VERSION_C != SRTC_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of SRtc_Ip.h and SRtc_Ip.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((SRTC_IP_SW_MAJOR_VERSION_C != SRTC_IP_SW_MAJOR_VERSION) || \
     (SRTC_IP_SW_MINOR_VERSION_C != SRTC_IP_SW_MINOR_VERSION) || \
     (SRTC_IP_SW_PATCH_VERSION_C != SRTC_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of SRtc_Ip.c and SRtc_Ip.h are different"
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#if (SRTC_IP_USED == STD_ON)


#define GPT_START_SEC_CONST_8
#include "Gpt_MemMap.h"
/** @brief  Table of month length (in days) for the Un-leap-year*/
static const uint8 ULY[] = {0U, 31U, 28U, 31U, 30U, 31U, 30U, 31U, 31U, 30U, 31U, 30U, 31U};

/** @brief Table of month length (in days) for the Leap-year*/
static const uint8 LY[] = {0U, 31U, 29U, 31U, 30U, 31U, 30U, 31U, 31U, 30U, 31U, 30U, 31U};
#define GPT_STOP_SEC_CONST_8
#include "Gpt_MemMap.h"

#define GPT_START_SEC_CONST_16
#include "Gpt_MemMap.h"
/** @brief Number of days from begin of the non Leap-year*/
static const uint16 MONTH_DAYS[] = {0U, 0U, 31U, 59U, 90U, 120U, 151U, 181U, 212U, 243U, 273U, 304U, 334U};
#define GPT_STOP_SEC_CONST_16
#include "Gpt_MemMap.h"

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define GPT_START_SEC_VAR_INIT_32
#include "Gpt_MemMap.h"
/**
* @brief          array variable used to store the runtime target time value.
*/
uint32 Srtc_Ip_u32TargetValue = 0U;

#define GPT_STOP_SEC_VAR_INIT_32
#include "Gpt_MemMap.h"

#define GPT_START_SEC_CONST_UNSPECIFIED
#include "Gpt_MemMap.h"
/** @brief Table of sRTC base pointers */
RTC_Type * const sRtcBase[RTC_INSTANCE_COUNT] = IP_RTC_BASE_PTRS;
#define GPT_STOP_SEC_CONST_UNSPECIFIED
#include "Gpt_MemMap.h"

#define GPT_START_SEC_VAR_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"
/** @brief Global array variable used to channel state for process common interrupt */
static Srtc_Ip_State Srtc_Ip_u32ChState[RTC_INSTANCE_COUNT] =  {
                                                                {
                                                                    (boolean)FALSE,
                                                                    0U,
                                                                    0U,
                                                                    (boolean)FALSE,
                                                                    (boolean)FALSE,
                                                                    NULL_PTR,
                                                                    0U,
                                                                    (boolean)FALSE,
                                                                    (boolean)FALSE,
                                                                    NULL_PTR,
                                                                    0U,
                                                                    SRTC_IP_CH_MODE_CONTINUOUS
                                                                }
                                                            };
#define GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

#ifdef SRTC_0_CH_0_ISR_USED
ISR(SRTC_0_Ch_0_ISR);
static void Srtc_Ip_ProcessInterrupt(uint8 instance);
#endif
static inline void Srtc_Ip_SetTimeSecondsRegister(RTC_Type * const base, uint32 value);
static inline void Srtc_Ip_SetTimeAlarmRegister(RTC_Type * const base, uint32 value);
static inline void Srtc_Ip_SetTimeInvalidInterrupt(RTC_Type * const base, boolean enable);
static inline void Srtc_Ip_SetTimeOverflowInterrupt(RTC_Type * const base, boolean enable);
static inline void Srtc_Ip_SetTimeAlarmInterrupt(RTC_Type * const base, boolean enable);
static inline void Srtc_Ip_SetTimeSecondsInterrupt(RTC_Type * const base, boolean enable);
static inline void Srtc_Ip_SoftwareReset(RTC_Type * const base);
static inline void Srtc_Ip_ConfigureTIF(RTC_Type * const base);
static inline void Srtc_Ip_ProcessAlarmInterrupt(uint8 instance);
static inline void Srtc_Ip_CounterEnable(RTC_Type * const base, boolean enable);
static inline boolean Srtc_Ip_IsCounterEnable(uint8 instance);
static inline void Srtc_Ip_SelectClock(RTC_Type * const base, Srtc_Ip_ClockSelectType clockSelect);
static inline void Srtc_Ip_SelectClockOut(RTC_Type * const base, Srtc_Ip_ClockOutType clockOut);
#if (defined (SRTC_IP_ENABLE_COMPENSATION_SUPPORT) && (SRTC_IP_ENABLE_COMPENSATION_SUPPORT == STD_ON))
static inline void Srtc_Ip_SetCompensationInterval(RTC_Type * const base, uint8 interval);
static inline void Srtc_Ip_SetCompensationRegister(RTC_Type * const base, uint8 value);
#endif
static inline Srtc_Ip_StatusType Srtc_Ip_SetSecondsInterruptConfiguration(RTC_Type * const base,
                                                                            Srtc_Ip_SecIntFreqType occursFrequency);
static boolean Srtc_Ip_IsYearLeap(uint16 year);
static boolean Srtc_Ip_IsTimeDateCorrectFormat(const Srtc_Ip_TimedateType *timeDate);
#if (STD_ON == SRTC_IP_ENABLE_USER_MODE_SUPPORT)
void Srtc_Ip_ConfigureNonSupervisorAccess(void);
#endif
#if (STD_ON == SRTC_IP_ENABLE_LOCK_REGISTER_API)
static inline Srtc_Ip_StatusType Srtc_Ip_ConfigureLockRegLock(RTC_Type * const base);
static inline Srtc_Ip_StatusType Srtc_Ip_ConfigureStatusRegLock(RTC_Type * const base);
static inline Srtc_Ip_StatusType Srtc_Ip_ConfigureControlRegLock(RTC_Type * const base);
static inline Srtc_Ip_StatusType Srtc_Ip_TimeControlRegLock(RTC_Type * const base);
static inline Srtc_Ip_StatusType Srtc_Ip_ConfigureLockReg(RTC_Type * const base, Srtc_Ip_LockRegSelectType lockReg);
#endif
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
static inline void Srtc_Ip_SetTimeSecondsRegister(RTC_Type * const base, uint32 value)
{
    /* Set value into TimeSecondsRegister */
    base->TSR  = value;
}

static inline void Srtc_Ip_SetTimeAlarmRegister(RTC_Type * const base, uint32 value)
{
    /* Set value into TimeAlarmRegister */
    base->TAR  = value;
}

static inline void Srtc_Ip_SetTimeInvalidInterrupt(RTC_Type * const base, boolean enable)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_60();
    if (TRUE == enable)
    {
        /* Enable TimeInvalid interrupt */
        base->IER |= (uint32)(1UL << RTC_IER_TIIE_SHIFT);
    }
    else
    {
        /* Disable TimeInvalid interrupt */
        base->IER &= ~(uint32)(1UL << RTC_IER_TIIE_SHIFT);
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_60();
}

static inline void Srtc_Ip_SetTimeOverflowInterrupt(RTC_Type * const base, boolean enable)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_61();
    if (TRUE == enable)
    {
        /* Enable TimeOverflow interrupt */
        base->IER |= (uint32)(1UL << RTC_IER_TOIE_SHIFT);
    }
    else
    {
        /* Disable TimeOverflow interrupt */
        base->IER &= ~(uint32)(1UL << RTC_IER_TOIE_SHIFT);
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_61();
}

static inline void Srtc_Ip_SetTimeAlarmInterrupt(RTC_Type * const base, boolean enable)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_62();
    if (TRUE == enable)
    {
        /* Enable TimeAlarm interrupt */
        base->IER |= (uint32)(1UL << RTC_IER_TAIE_SHIFT);
    }
    else
    {
        /* Disable TimeAlarm interrupt */
        base->IER &= ~(uint32)(1UL << RTC_IER_TAIE_SHIFT);
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_62();
}

static inline void Srtc_Ip_SetTimeSecondsInterrupt(RTC_Type * const base, boolean enable)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_63();
    if (TRUE == enable)
    {
        /* Enable TimeSeconds interrupt */
        base->IER |= (uint32)(1UL << RTC_IER_TSIE_SHIFT);
    }
    else
    {
        /* Disable TimeSeconds interrupt */
        base->IER &= ~(uint32)(1UL << RTC_IER_TSIE_SHIFT);
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_63();
}

static inline void Srtc_Ip_SoftwareReset(RTC_Type * const base)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_64();
    /* Enable SoftwareReset */
    base->CR |= (uint32)(1UL << RTC_CR_SWR_SHIFT);
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_64();
}

static inline void Srtc_Ip_CounterEnable(RTC_Type * const base, boolean enable)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_65();
    if (TRUE == enable)
    {
        /* Enable counter */
        base->SR |= (uint32)(1UL << RTC_SR_TCE_SHIFT);
    }
    else
    {
        /* Disable counter */
        base->SR &= ~(uint32)(1UL << RTC_SR_TCE_SHIFT);
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_65();
}

static inline boolean Srtc_Ip_IsCounterEnable(uint8 instance)
{
    uint32 IsCounterEnable;
    /* check if counter is enabled */
    IsCounterEnable = ((uint32)((sRtcBase[instance]->SR) & RTC_SR_TCE_MASK) >> RTC_SR_TCE_SHIFT);
    return ((IsCounterEnable == 1UL) ? TRUE : FALSE);
}

static inline void Srtc_Ip_SelectClock(RTC_Type * const base, Srtc_Ip_ClockSelectType clockSelect)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_66();
    switch(clockSelect)
    {
        case SRTC_IP_CLK_SRC_OSC_32KHZ:
        {
            /* Select clock source as 32KHZ */
            base->CR &= ~(uint32)(1UL << RTC_CR_LPOS_SHIFT);
        }
        break;
        case SRTC_IP_CLK_SRC_LPO_1KHZ:
        {
           /* Select clock source as 1KHZ */
            base->CR |= (uint32)(1UL << RTC_CR_LPOS_SHIFT);
        }
        break;
        default:
        {
            /* default branch, do nothing */
        }
        break;
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_66();

}

static inline void Srtc_Ip_SelectClockOut(RTC_Type * const base, Srtc_Ip_ClockOutType clockOut)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_67();
    switch(clockOut)
    {
        case SRTC_IP_CLKOUT_DISABLED:
        {
            /* Disable the clock out pin */
            base->CR &= ~(uint32)(1UL << RTC_CR_CPE_SHIFT);
        }
        break;
        case SRTC_IP_CLKOUT_SRC_TSIC:
        {
            /* Select clock out source as Time Seconds Interrupt and enable the pin */
            base->CR |= (uint32)(1UL << RTC_CR_CPE_SHIFT);
            base->CR &= ~(uint32)(1UL << RTC_CR_CPS_SHIFT);
        }
        break;
        case SRTC_IP_CLKOUT_SRC_32KHZ:
        {
            /* Select clock out source as the 32 KHz clock and enable the pin */
            base->CR |= (uint32)(1UL << RTC_CR_CPE_SHIFT);
            base->CR |= (uint32)(1UL << RTC_CR_CPS_SHIFT);
        }
        break;
        default:
        {
            /* default branch, do nothing */
        }
        break;
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_67();
}

#if (defined (SRTC_IP_ENABLE_COMPENSATION_SUPPORT) && (SRTC_IP_ENABLE_COMPENSATION_SUPPORT == STD_ON))
static inline void Srtc_Ip_SetCompensationInterval(RTC_Type * const base, uint8 interval)
{
    /* Set Compensation Interval */
    base->TCR = (base->TCR & ~RTC_TCR_CIR_MASK) | RTC_TCR_CIR(interval);
}

static inline void Srtc_Ip_SetCompensationRegister(RTC_Type * const base, uint8 value)
{
    /* Set Compensation Register */
    base->TCR = (base->TCR & ~RTC_TCR_TCR_MASK) | RTC_TCR_TCR(value);
}
#endif

static inline Srtc_Ip_StatusType Srtc_Ip_SetSecondsInterruptConfiguration(RTC_Type * const base,
                                                                            Srtc_Ip_SecIntFreqType occursFrequency)
{
    Srtc_Ip_StatusType status = SRTC_IP_ERROR;
    uint32 isEnabled = 0U;
    /* check if TimeSecondsInterrupt is enabled */
    isEnabled = ((uint32)((base->IER) & RTC_IER_TSIE_MASK) >> RTC_IER_TSIE_SHIFT);
    if(0U == isEnabled)
    {
        /* set frequency for TimeSeconds */
        base->IER = (base->IER & ~RTC_IER_TSIC_MASK) | RTC_IER_TSIC(occursFrequency);
        status = SRTC_IP_SUCCESS;
    }
    else
    {
        status = SRTC_IP_ERROR;
    }

    return status;

}
static boolean Srtc_Ip_IsYearLeap(uint16 year)
{
    boolean returnValue;

    if ((year % 4U) > 0U)
    {
        returnValue = FALSE;
    }
    else if ((year % 100U) > 0U)
    {
        returnValue = TRUE;
    }
    else if ((year % 400U) > 0U)
    {
        returnValue = FALSE;
    }
    else
    {
        returnValue = TRUE;
    }

    /* Return the exit code */
    return returnValue;
}

static boolean Srtc_Ip_IsTimeDateCorrectFormat(const Srtc_Ip_TimedateType *timeDate)
{

    /* Declare local variables */
    boolean returnValue;
    const uint8 * pDays;

    /* Set the days-in-month table for the corresponding year */
    pDays = Srtc_Ip_IsYearLeap(timeDate->year) ? (LY) : (ULY);

    /* Check if the time and date are in the correct ranges */
    if ((timeDate->year < YEAR_RANGE_START) || (timeDate->year > YEAR_RANGE_END)
            ||  (timeDate->month < 1U) || (timeDate->month > 12U)
            ||  (timeDate->day < 1U) || (timeDate->day > 31U)
            ||  (timeDate->hour >= HOURS_IN_A_DAY)
            ||  (timeDate->minutes >= MINS_IN_A_HOUR) || (timeDate->seconds >= SECONDS_IN_A_MIN))
    {
        returnValue = FALSE;
    }
    /* Check if the day is a valid day from the corresponding month */
    else if (timeDate->day > pDays[timeDate->month])
    {
        returnValue = FALSE;
    }
    else
    {
        returnValue = TRUE;
    }

    /* Return the exit code */
    return returnValue;
}


#if (STD_ON == SRTC_IP_ENABLE_USER_MODE_SUPPORT)
void Srtc_Ip_ConfigureNonSupervisorAccess(void)
{
    RTC_Type * base = sRtcBase[0U];
    /*Check Software Reset*/
    if (0UL != (uint32)(((base->CR) & RTC_CR_SWR_MASK) >> RTC_CR_SWR_SHIFT))
    {
        /* Clear Software Reset*/
        base->CR &= ~(uint32)(1UL << RTC_CR_SWR_SHIFT);
    }
    /*Non-supervisor mode write accesses are supported.*/
    base->CR |= (uint32)(1UL << RTC_CR_SUP_SHIFT);

}
#endif

static inline void Srtc_Ip_ConfigureTIF(RTC_Type * const base)
{
    /* Check if TIF */
    if (0UL != (uint32)(((base->SR) & RTC_SR_TIF_MASK) >> RTC_SR_TIF_SHIFT))
    {
		/* Clear Software Reset*/
		base->CR &= ~(uint32)(1UL << RTC_CR_SWR_SHIFT);
		/* Disable counter timer*/
		Srtc_Ip_CounterEnable(base, FALSE);
		/* TIF cleared by writing the TSR register when the time counter is disabled.*/
		Srtc_Ip_SetTimeSecondsRegister(base, 0U);
    }
}

static inline void Srtc_Ip_ProcessAlarmInterrupt(uint8 instance)
{
	uint32 counterValue = 0U;
	uint32 newAlarmTime = 0U;
	RTC_Type * base;
    base = sRtcBase[instance];
	
        /* Compute next Time Alarm */
        newAlarmTime = Srtc_Ip_GetTimeAlarmRegister(instance) + Srtc_Ip_u32TargetValue;
        /* Set New Time Alarm, and this also clears the TAF flag */
        Srtc_Ip_SetTimeAlarmRegister(base, newAlarmTime);	
        /* Call upper layer handler */
        if((TRUE == Srtc_Ip_u32ChState[instance].chInit) && \
            (NULL_PTR != Srtc_Ip_u32ChState[instance].callback))
        {
            Srtc_Ip_u32ChState[instance].callback(Srtc_Ip_u32ChState[instance].callbackParam);
        }
        /* If the alarm interrupt configuration has been defined */
        else if((FALSE != Srtc_Ip_u32ChState[instance].alarmInit) && (TRUE == Srtc_Ip_u32ChState[instance].alarmIntEnable))
        {
            if ((0UL < Srtc_Ip_u32ChState[instance].numberOfRepeats) || (TRUE == Srtc_Ip_u32ChState[instance].repeatForever))
            {
                /* Get current time */
                counterValue = Srtc_Ip_GetTimeSecondsRegister(instance);
                /* Current time is incremented with the repetition value */
                newAlarmTime = counterValue + (Srtc_Ip_u32ChState[instance].repetitionInterval - 1U);
                /* Set new value to trigger the alarm */
                Srtc_Ip_SetTimeAlarmRegister(base, newAlarmTime);
                Srtc_Ip_u32ChState[instance].isAlarmTimeNew = TRUE;
                /* If the alarm repeats forever, set number of repeats to 0 to avoid an accidental trigger of the core overflow flag */
                Srtc_Ip_u32ChState[instance].numberOfRepeats = (Srtc_Ip_u32ChState[instance].repeatForever == FALSE) ? (Srtc_Ip_u32ChState[instance].numberOfRepeats - 1UL) : 0UL;
            }
            else
            {
                Srtc_Ip_u32ChState[instance].isAlarmTimeNew = FALSE;
            }
            /* If the user has defined a callback, call it */
            if (NULL_PTR != Srtc_Ip_u32ChState[instance].alarmCallback)
            {
                Srtc_Ip_u32ChState[instance].alarmCallback(Srtc_Ip_u32ChState[instance].callbackParams);
            }
        }
        else
        {
            /*TO DO NOTHING */
        }
}

/*================================================================================================*/
#ifdef SRTC_0_CH_0_ISR_USED
/**
* @brief        Srtc_Ip_ProcessInterrupt.
* @details      Function used by interrupt service routines to call notification
*               functions if provided and enabled
*
* @param[in]     channel      hardware channel index
* @implements    Srtc_Ip_ProcessInterrupt_Activity
*/
static void Srtc_Ip_ProcessInterrupt(uint8 instance)
{
    RTC_Type * base;
    base = sRtcBase[instance];
    uint32 alarmInterruptFlag = 0U;
    uint32 invalidInterruptFlag = 0U;
    uint32 overflowInterruptFlag = 0U;
    uint32 alarmInterruptEnable = 0U;
    uint32 invalidInterruptEnable = 0U;
    uint32 overflowInterruptEnable = 0U;
    uint32 secondsInterruptEnable = 0U;

    /* Check the status flag and interrupts enable bit. */
    alarmInterruptFlag = Srtc_Ip_GetStatusFlags(instance, SRTC_IP_ALARM_INTERRUPT);
    invalidInterruptFlag = Srtc_Ip_GetStatusFlags(instance, SRTC_IP_INVALID_INTERRUPT);
    overflowInterruptFlag = Srtc_Ip_GetStatusFlags(instance, SRTC_IP_OVERFLOW_INTERRUPT);
    alarmInterruptEnable = ((sRtcBase[instance]->IER) & RTC_IER_TAIE_MASK) >> RTC_IER_TAIE_SHIFT;
    secondsInterruptEnable = ((sRtcBase[instance]->IER) & RTC_IER_TSIE_MASK) >> RTC_IER_TSIE_SHIFT;
    invalidInterruptEnable = ((sRtcBase[instance]->IER) & RTC_IER_TIIE_MASK) >> RTC_IER_TIIE_SHIFT;
    overflowInterruptEnable = ((sRtcBase[instance]->IER) & RTC_IER_TOIE_MASK) >> RTC_IER_TOIE_SHIFT;

	/* Configure TIF when POR or software reset */
	Srtc_Ip_ConfigureTIF(base);
    /* Interrupt Flags is cleared by writing the TAR register. For Time Seconds Interrupt there is no corresponding status flag to clear */
    Srtc_Ip_SetTimeAlarmRegister(base, 0U);
    /* Check if TAF and TAIE */
    if ((1U == alarmInterruptFlag) && (1U == alarmInterruptEnable))
    {
        if((SRTC_IP_CH_MODE_ONESHOT == Srtc_Ip_u32ChState[instance].channelMode))
        {
             /* Stop counter */
            (void)Srtc_Ip_StopCounter(instance);
        }
			/* Process AlarmInterrupt */
			Srtc_Ip_ProcessAlarmInterrupt(instance);

    }
    else if(((1U == invalidInterruptFlag) && (1U == invalidInterruptEnable)) || \
            ((1U == overflowInterruptFlag) && (1U == overflowInterruptEnable)) || \
            (1U == secondsInterruptEnable))
    {
        if((SRTC_IP_CH_MODE_ONESHOT == Srtc_Ip_u32ChState[instance].channelMode))
        {
             /* Stop counter */
            (void)Srtc_Ip_StopCounter(instance);
        }
        /* Call callback notification */
        if((TRUE == Srtc_Ip_u32ChState[instance].chInit) && \
            (NULL_PTR != Srtc_Ip_u32ChState[instance].callback))
        {
            Srtc_Ip_u32ChState[instance].callback(Srtc_Ip_u32ChState[instance].callbackParam);
        }
    }
    else
    {
        /*TO DO NOTHING */
    }
}
#endif
#if (STD_ON == SRTC_IP_ENABLE_LOCK_REGISTER_API)
static inline Srtc_Ip_StatusType Srtc_Ip_ConfigureLockRegLock(RTC_Type * const base)
{
    Srtc_Ip_StatusType status = SRTC_IP_ERROR;

    if(1U == (((base->LR) & RTC_LR_LRL_MASK) >> RTC_LR_LRL_SHIFT))
    {
        base->LR &= (~(RTC_LR_LRL_MASK));
        status = SRTC_IP_SUCCESS;
    }
    else
    {
        status = SRTC_IP_ERROR;
    }

    return status;
}

static inline Srtc_Ip_StatusType Srtc_Ip_ConfigureStatusRegLock(RTC_Type * const base)
{
    Srtc_Ip_StatusType status = SRTC_IP_ERROR;

    if(1U == (((base->LR) & RTC_LR_SRL_MASK) >> RTC_LR_SRL_SHIFT))
    {
        base->LR &= (~(RTC_LR_SRL_MASK));
        status = SRTC_IP_SUCCESS;
    }
    else
    {
        status = SRTC_IP_ERROR;
    }

    return status;
}

static inline Srtc_Ip_StatusType Srtc_Ip_ConfigureControlRegLock(RTC_Type * const base)
{
    Srtc_Ip_StatusType status = SRTC_IP_ERROR;

    if(1U == (((base->LR) & RTC_LR_CRL_MASK) >> RTC_LR_CRL_SHIFT))
    {
        base->LR &= (~(RTC_LR_CRL_MASK));
        status = SRTC_IP_SUCCESS;
    }
    else
    {
        status = SRTC_IP_ERROR;
    }

    return status;
}

static inline Srtc_Ip_StatusType Srtc_Ip_TimeControlRegLock(RTC_Type * const base)
{
    Srtc_Ip_StatusType status = SRTC_IP_ERROR;

    if(1U == (((base->LR) & RTC_LR_TCL_MASK) >> RTC_LR_TCL_SHIFT))
    {
        base->LR &= (~(RTC_LR_TCL_MASK));
        status = SRTC_IP_SUCCESS;
    }
    else
    {
        status = SRTC_IP_ERROR;
    }

    return status;
}

static inline Srtc_Ip_StatusType Srtc_Ip_ConfigureLockReg(RTC_Type * const base, Srtc_Ip_LockRegSelectType lockReg)
{
    Srtc_Ip_StatusType status = SRTC_IP_ERROR;

    switch (lockReg)
    {
        case SRTC_IP_LOCK_REG_LOCK:
        {
            status = Srtc_Ip_ConfigureLockRegLock(base);
        }
        break;
        case SRTC_IP_STATUS_REG_LOCK:
        {
            status = Srtc_Ip_ConfigureStatusRegLock(base);
        }
        break;
        case SRTC_IP_CTRL_REG_LOCK:
        {
            status = Srtc_Ip_ConfigureControlRegLock(base);
        }
        break;
        case SRTC_IP_TCL_REG_LOCK:
        {
            status = Srtc_Ip_TimeControlRegLock(base);
        }
        break;
        default:
        {
            /* If the register is not recognized, return error */
            status = SRTC_IP_ERROR;
        }
        break;
    }

    return status;
}
#endif
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
uint32 Srtc_Ip_GetTimeSecondsRegister(uint8 instance)
{
    uint32 secondsRegisterValue = 0U;
    /* Get TimeSecondsRegister value */
    secondsRegisterValue = sRtcBase[instance]->TSR;
    return secondsRegisterValue;
}

uint32 Srtc_Ip_GetTimeAlarmRegister(uint8 instance)
{
    uint32 alarmRegisterValue = 0U;
    /* Get TimeAlarmRegister value */
    alarmRegisterValue = sRtcBase[instance]->TAR;
    return alarmRegisterValue;
}

uint32 Srtc_Ip_GetStatusFlags(uint8 instance, Srtc_Ip_InterruptType interruptMode)
{
    uint32 flag = 0U;

    /* Get interrupt flag */
    switch(interruptMode)
    {
        case SRTC_IP_INVALID_INTERRUPT:
        {
            flag = ((sRtcBase[instance]->SR) & RTC_SR_TIF_MASK) >> RTC_SR_TIF_SHIFT;
        }
        break;
        case SRTC_IP_OVERFLOW_INTERRUPT:
        {
            flag = ((sRtcBase[instance]->SR) & RTC_SR_TOF_MASK) >> RTC_SR_TOF_SHIFT;
        }
        break;
        case SRTC_IP_ALARM_INTERRUPT:
        {
            flag = ((sRtcBase[instance]->SR) & RTC_SR_TAF_MASK) >> RTC_SR_TAF_SHIFT;
        }
        break;
        default:
        {
            flag = 0U;
        }
        break;
    }

    return flag;
}

/*================================================================================================*/
/**
*
* @brief         SRtc Driver function
* @details       This function:
*                        - will convert seconds into time-date format.
*
* @param[in]     seconds         number of seconds
* @param[in]     *timeDate       pointer to configuration
* @return        void
* @pre           The driver needs to be initialized.
* @implements    Srtc_Ip_ConvertSecondsToTimeDate_Activity
*/
void Srtc_Ip_ConvertSecondsToTimeDate(const uint32 * const seconds,
                                      Srtc_Ip_TimedateType * const timeDate)
{
#if SRTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(NULL_PTR != seconds);
    DevAssert(NULL_PTR != timeDate);
#endif
    /* Declare the variables needed */
    uint8 index;
    boolean yearLeap;
    uint32 numberOfDays;
    uint32 tempSeconds;
    uint16 daysInYear;

    /* Because the starting year(1970) is not leap, set the daysInYear
     * variable with the number of the days in a normal year
     */
    daysInYear = DAYS_IN_A_YEAR;

    /* Set the year to the beginning of the range */
    timeDate->year = YEAR_RANGE_START;

    /* Get the number of days */
    numberOfDays = (*seconds) / SECONDS_IN_A_DAY;
    /* Get the number of seconds remaining */
    tempSeconds = (*seconds) % SECONDS_IN_A_DAY;

    /* Get the current hour */
    timeDate->hour        = (uint16)(tempSeconds / SECONDS_IN_A_HOUR);
    /* Get the remaining seconds */
    tempSeconds           = tempSeconds % SECONDS_IN_A_HOUR;
    /* Get the minutes */
    timeDate->minutes     = (uint16)(tempSeconds / SECONDS_IN_A_MIN);
    /* Get seconds */
    timeDate->seconds     = (uint8)(tempSeconds % SECONDS_IN_A_MIN);

    /* Get the current year */
    while (numberOfDays >= daysInYear)
    {
        /* Increment year if the number of days is greater than the ones in
         * one year
         */
        timeDate->year++;
        /* Subtract the number of the days */
        numberOfDays -= daysInYear;

        /* Check if the year is leap or unleap */
        if (!Srtc_Ip_IsYearLeap(timeDate->year))
        {
            /* Set the number of non leap year to the current year number
             * of days.
             */
            daysInYear = DAYS_IN_A_YEAR;
        }
        else
        {
            /* Set the number of leap year to the current year number
             * of days.
             */
            daysInYear = DAYS_IN_A_LEAP_YEAR;
        }
    }

    /* Add the current day */
    numberOfDays += 1U;

    /* Check if the current year is leap */
    yearLeap = Srtc_Ip_IsYearLeap(timeDate->year);

    /* Get the month */
    for (index = 1U; index <= 12U; index++)
    {
        uint32 daysInCurrentMonth = ((yearLeap == TRUE) ? (uint32)LY[index] : (uint32)ULY[index]);
        if (numberOfDays <= daysInCurrentMonth)
        {
            timeDate->month = (uint16)index;
            break;
        }
        else
        {
            numberOfDays -= daysInCurrentMonth;
        }

    }

    /* Set the current day */
    timeDate->day = (uint16)numberOfDays;
}

/*================================================================================================*/
/**
*
* @brief         SRtc Driver function
* @details       This function:
*                        - will convert time-date into seconds.
*
* @param[in]     seconds         number of seconds
* @param[in]     *timeDate       pointer to configuration
* @return        void
* @pre           The driver needs to be initialized.
* @implements    Srtc_Ip_ConvertTimeDateToSeconds_Activity
*/
void Srtc_Ip_ConvertTimeDateToSeconds(const Srtc_Ip_TimedateType * const timeDate,
                                      uint32 * const seconds)
{
#if SRTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(NULL_PTR != seconds);
    DevAssert(NULL_PTR != timeDate);
#endif

    /* Declare local variables */
    uint16 year;

    /* Convert years to seconds */
    (*seconds) = (uint32)(DAYS_IN_A_YEAR * (uint32)(SECONDS_IN_A_DAY));
    (*seconds) *= ((uint32)timeDate->year - YEAR_RANGE_START);

    /* Add the seconds from the leap years */
    for (year = YEAR_RANGE_START; year < timeDate->year; year++)
    {
        if (Srtc_Ip_IsYearLeap(year))
        {
            (*seconds) += SECONDS_IN_A_DAY;
        }
    }

    /* If the current year is leap and 29th of February has passed, add
     * another day to seconds passed.
     */
    if ((Srtc_Ip_IsYearLeap(year)) && (timeDate->month > 2U))
    {
        (*seconds) += SECONDS_IN_A_DAY;
    }

    /* Add the rest of the seconds from the current month */
    (*seconds) += MONTH_DAYS[timeDate->month] * SECONDS_IN_A_DAY;
    /* Add the rest of the seconds from the current day */
    (*seconds) += (uint32)(((uint32)timeDate->day - 1U) * (uint32)SECONDS_IN_A_DAY);
    /* Add the rest of the seconds from the current time */
    (*seconds) += (uint32)(((uint32)timeDate->hour * SECONDS_IN_A_HOUR)   + \
                           ((uint32)timeDate->minutes * SECONDS_IN_A_MIN) + \
                            (uint32)timeDate->seconds);
}

/*================================================================================================*/
/**
* @brief   SRtc driver initialization function for SRtc module.
* @details This function:
*          - Disables the time counter
*          - Disables all interrupt modes
*          - Clears Time Invalid Flag
*          - Selects source Clock
*          - If compensation support is enabled sets the configured values
*          - Sets channel state variables
*
* @param[in]     instance     hw instance
* @param[in]     *config      pointer to configuration
* @return        void
* @pre           The data structure including the configuration set required for initializing the driver
* @implements    Srtc_Ip_Init_Activity
*/
void Srtc_Ip_Init(uint8 instance, const Srtc_Ip_ConfigType *config)
{
#if SRTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(RTC_INSTANCE_COUNT > instance);
    DevAssert(NULL_PTR != config);
#endif
#if (STD_ON == SRTC_IP_ENABLE_USER_MODE_SUPPORT)
    /* Enables SRTC registers writing in User Mode */
    OsIf_Trusted_Call(Srtc_Ip_ConfigureNonSupervisorAccess);
#endif

    RTC_Type * base = sRtcBase[instance];

#if (defined (SRTC_IP_STANDBY_WAKEUP_SUPPORT) && (SRTC_IP_STANDBY_WAKEUP_SUPPORT == STD_ON))
    if(0U == (((sRtcBase[instance]->IER) & RTC_IER_TAIE_MASK) >> RTC_IER_TAIE_SHIFT))
    {
#endif
    /*Disable time counter*/
    Srtc_Ip_CounterEnable(base, FALSE);
    /* Disable all interrupt modes */
    Srtc_Ip_SetTimeInvalidInterrupt(base, FALSE);
    Srtc_Ip_SetTimeOverflowInterrupt(base, FALSE);
    Srtc_Ip_SetTimeAlarmInterrupt(base, FALSE);
    /* On POR, TIF is set. The TSR ans TPR do not increment. */
    /* Clear TIF flag by writing to TSR */
    Srtc_Ip_SetTimeSecondsRegister(base, 0U);
#if (defined (SRTC_IP_STANDBY_WAKEUP_SUPPORT) && (SRTC_IP_STANDBY_WAKEUP_SUPPORT == STD_ON))
    }
#endif
    /* Setup the RTC instance as configured in the structure */
    Srtc_Ip_SelectClock(base, config->clockSelect);
    Srtc_Ip_SelectClockOut(base, config->clockOutSelect);
#if (defined (SRTC_IP_ENABLE_COMPENSATION_SUPPORT) && (SRTC_IP_ENABLE_COMPENSATION_SUPPORT == STD_ON))
    /* If compensation support is enabled sets the configured values */
    Srtc_Ip_SetCompensationInterval(base, config->compensationInterval);
    Srtc_Ip_SetCompensationRegister(base, config->compensation);
#endif
    /* Set channel state variables */
    Srtc_Ip_u32ChState[instance].chInit = TRUE;
    Srtc_Ip_u32ChState[instance].callback = config->callback;
    Srtc_Ip_u32ChState[instance].callbackParam = config->callbackParam;
    Srtc_Ip_u32ChState[instance].channelMode = config->channelMode;
    Srtc_Ip_u32TargetValue = 0U;

}

/*================================================================================================*/
/**
* @brief         SRtc driver de-initialization function
* @details       This function:
*                       - Performs a software reset
*                       - Clears global variables
* @param[in]     instance        Rtc hw instance
* @return        void
* @pre           The data structure including the configuration set required for initializing the GPT driver
* @implements    Srtc_Ip_DeInit_Activity
*/
void Srtc_Ip_DeInit(uint8 instance)
{
#if SRTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(RTC_INSTANCE_COUNT > instance);
#endif

    RTC_Type * base = sRtcBase[instance];

    /* Perform a software reset */
    Srtc_Ip_SoftwareReset(base);
    /* Clear global variables */
    Srtc_Ip_u32TargetValue = 0U;
}

/*================================================================================================*/
/**
* @brief         SRtc Driver function for starting the Rtc counter.
* @details       This function:
*                           - Enables the counter
* @param[in]     instance            Rtc hw instance
* @return        Srtc_Ip_StatusType  status error
* @pre           The driver needs to be initialized.
* @implements    Srtc_Ip_StartCounter_Activity
*/
Srtc_Ip_StatusType Srtc_Ip_StartCounter(uint8 instance)
{
#if SRTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(RTC_INSTANCE_COUNT > instance);
#endif

    RTC_Type * base = sRtcBase[instance];
    Srtc_Ip_StatusType status = SRTC_IP_ERROR;

    if(FALSE == Srtc_Ip_IsCounterEnable(instance))
    {
        Srtc_Ip_CounterEnable(base, TRUE);
        status = SRTC_IP_SUCCESS;
    }

    return status;
}

/*================================================================================================*/
/**
* @brief         SRtc Driver function for stopping the Rtc counter.
* @details       This function:
*                           - Disables Time Alarm Interrupt
*                           - Clears interrupt flag
*                           - Disables the counter
* @param[in]     instance            Rtc hw instance
* @return        Srtc_Ip_StatusType  status error
* @pre           The driver needs to be initialized.
* @implements    Srtc_Ip_StopCounter_Activity
*/
Srtc_Ip_StatusType Srtc_Ip_StopCounter(uint8 instance)
{
#if SRTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(RTC_INSTANCE_COUNT > instance);
#endif
    uint32 timeAlarmValue;
    RTC_Type * base = sRtcBase[instance];
    Srtc_Ip_StatusType status = SRTC_IP_ERROR;

    /* Disable Time Alarm Interrupt */
    Srtc_Ip_DisableInterrupt(instance, SRTC_IP_ALARM_INTERRUPT);
    /* Get current Timer Alarm Value */
    timeAlarmValue = Srtc_Ip_GetTimeAlarmRegister(instance);
    /* Make sure that the time alarm interrupt flag was pending cleared */
    /* Clear TAF by writing to the TAR register */
    Srtc_Ip_SetTimeAlarmRegister(base, timeAlarmValue);

#ifdef ERR_IPV_RTC_ERR010716
#if ERR_IPV_RTC_ERR010716 == STD_ON
    if(0U != Srtc_Ip_GetStatusFlags(instance, SRTC_IP_ALARM_INTERRUPT))
    {
        /* Clear TAF by writing to the TAR register */
        Srtc_Ip_SetTimeAlarmRegister(base, timeAlarmValue);
    }
#endif
#endif

    if(TRUE == Srtc_Ip_IsCounterEnable(instance))
    {
        Srtc_Ip_CounterEnable(base, FALSE);
        status = SRTC_IP_SUCCESS;
    }
    else
    {
        status = SRTC_IP_SUCCESS;
    }

    return status;

}

/*================================================================================================*/
/**
* @brief         SRtc Driver function for starting the Rtc timer channel with a timeout value.
* @details       This function:
*                       - Disables counter
*                       - Disables Time Alarm Interrupt
*                       - Gets Time Seconds Register value
*                       - Calculates new compare value
*                       - Sets Time Alarm Register
*                       - Enables Time Alarm Interrupt
*                       - Enables counter
*
* @param[in]     instance         Rtc hw instance
*                value            channel time-out value
* @return        void
* @pre           The data structure including the configuration set required for initializing the GPT driver
* @implements    Srtc_Ip_StartTimer_Activity
*/
void Srtc_Ip_StartTimer(uint8 instance, uint32 value)
{
#if SRTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(RTC_INSTANCE_COUNT > instance);
#endif

    RTC_Type * base = sRtcBase[instance];
    uint32 counterValue = 0U;
    Srtc_Ip_u32TargetValue = value;

    /* Disable counter */
    Srtc_Ip_CounterEnable(base, FALSE);
    /* Disable Time Alarm Interrupt */
    Srtc_Ip_SetTimeAlarmInterrupt(base, FALSE);
    /* Get Time Seconds Register value */
    counterValue = Srtc_Ip_GetTimeSecondsRegister(instance);
    /* Calculate new compare value */
    counterValue = counterValue + value - 1U;
    /* Set Time Alarm Register */
    Srtc_Ip_SetTimeAlarmRegister(base, counterValue);
    /* Enable Time Alarm Interrupt */
    Srtc_Ip_SetTimeAlarmInterrupt(base, TRUE);
    /* Enable counter */
    Srtc_Ip_CounterEnable(base, TRUE);

}

/*================================================================================================*/
/**
* @brief         SRtc Driver function for enabling interrupt for RTC channel
* @details       This function:
*                        - Enables Interrupt for RTC channel based on selected mode
*
* @param[in]     instance        Rtc hw instance
*                interruptMode   Rtc hw interrupt mode
* @return        void
* @pre           The driver needs to be initialized.
* @implements    Srtc_Ip_EnableInterrupt_Activity
*/
void Srtc_Ip_EnableInterrupt(uint8 instance, Srtc_Ip_InterruptType interruptMode)
{
#if SRTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(RTC_INSTANCE_COUNT > instance);
#endif

    RTC_Type * base = sRtcBase[instance];
    uint32 timeAlarmValue = 0U;


    switch(interruptMode)
    {
        case SRTC_IP_INVALID_INTERRUPT:
            Srtc_Ip_SetTimeInvalidInterrupt(base, TRUE);

        break;
        case SRTC_IP_OVERFLOW_INTERRUPT:

            Srtc_Ip_SetTimeOverflowInterrupt(base, TRUE);

        break;
        case SRTC_IP_ALARM_INTERRUPT:
        if (0U == Srtc_Ip_GetStatusFlags(instance, SRTC_IP_ALARM_INTERRUPT))
        {
        /* Get current Timer Alarm Value */
        timeAlarmValue = Srtc_Ip_GetTimeAlarmRegister(instance);
        /* Clear TAF by writing to the TAR register */
        Srtc_Ip_SetTimeAlarmRegister(base, timeAlarmValue);

#ifdef ERR_IPV_RTC_ERR010716
#if ERR_IPV_RTC_ERR010716 == STD_ON
        /* Get current Timer Alarm Value */
        timeAlarmValue = Srtc_Ip_GetTimeAlarmRegister(instance);

        if(0U != Srtc_Ip_GetStatusFlags(instance, SRTC_IP_ALARM_INTERRUPT))
        {
            /* Clear TAF by writing to the TAR register */
            Srtc_Ip_SetTimeAlarmRegister(base, timeAlarmValue);
        }
#endif
#endif
        /* Enabled TimeAlarmInterrupt*/
        Srtc_Ip_SetTimeAlarmInterrupt(base, TRUE);
        }
        break;
        case SRTC_IP_SECONDS_INTERRUPT:

        /* Enabled TimeSecondsInterrupt*/
        Srtc_Ip_SetTimeSecondsInterrupt(base, TRUE);

        break;
        default:
        /* default branch; do nothing */
        break;
    }
}
/*================================================================================================*/
/**
*
* @brief         SRtc Driver function for Disable Interrupt for RTC channel
* @details       This function:
*                        - Disable Interrupt for RTC channel based on selected mode
*
* @param[in]     instance        Rtc hw instance
* @return        void
* @pre           The driver needs to be initialized.
* @implements    Srtc_Ip_DisableInterrupt_Activity
*/
void Srtc_Ip_DisableInterrupt(uint8 instance, Srtc_Ip_InterruptType interruptMode)
{
#if SRTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(RTC_INSTANCE_COUNT > instance);
#endif

    uint32 timeAlarmValue = 0U;
    RTC_Type * base = sRtcBase[instance];

    switch(interruptMode)
    {
        case SRTC_IP_INVALID_INTERRUPT:
        {
            Srtc_Ip_SetTimeInvalidInterrupt(base, FALSE);
        }
        break;
        case SRTC_IP_OVERFLOW_INTERRUPT:
        {
            Srtc_Ip_SetTimeOverflowInterrupt(base, FALSE);
        }
        break;
        case SRTC_IP_ALARM_INTERRUPT:
        {
        /* Time Alarm Interrupt Disable */
        Srtc_Ip_SetTimeAlarmInterrupt(base, FALSE);
        /* Get current Timer Alarm Value */
        timeAlarmValue = Srtc_Ip_GetTimeAlarmRegister(instance);
        /* Clear TAF by writing to the TAR register */
        Srtc_Ip_SetTimeAlarmRegister(base, timeAlarmValue);

#ifdef ERR_IPV_RTC_ERR010716
#if ERR_IPV_RTC_ERR010716 == STD_ON
        /* Get current Timer Alarm Value */
        timeAlarmValue = Srtc_Ip_GetTimeAlarmRegister(instance);

        if(0U != Srtc_Ip_GetStatusFlags(instance, SRTC_IP_ALARM_INTERRUPT))
        {
            /* Clear TAF by writing to the TAR register */
            Srtc_Ip_SetTimeAlarmRegister(base, timeAlarmValue);
        }
#endif
#endif
        }
        break;
        case SRTC_IP_SECONDS_INTERRUPT:
        {
            Srtc_Ip_SetTimeSecondsInterrupt(base, FALSE);
        }
        break;
        default:
        {
            /* default branch; do nothing */
        }
        break;
    }

}

/*================================================================================================*/
/**
* @brief         SRtc Driver function
* @details       This function:
*                        - Sets the date passed by the user.
*
* @param[in]     instance           SRtc hw instance
* @param[in]     *timeDate          pointer to configuration
* @return        Srtc_Ip_StatusType  status error
* @pre           The driver needs to be initialized.
* @implements    Srtc_Ip_SetTimeDate_Activity
*/
Srtc_Ip_StatusType Srtc_Ip_SetTimeDate(uint8 instance, const Srtc_Ip_TimedateType *timeDate)
{
#if SRTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(NULL_PTR != timeDate);
    DevAssert(RTC_INSTANCE_COUNT > instance);
#endif

    RTC_Type * base = sRtcBase[instance];
    Srtc_Ip_StatusType status = SRTC_IP_ERROR;
    uint32 seconds = 0U;

    /* Check if the date/time format is correct */
    if(!Srtc_Ip_IsTimeDateCorrectFormat(timeDate))
    {
        /* Set the status code to error */
        status = SRTC_IP_ERROR;
    }
    else
    {
        /* Convert the time and date to seconds */
        Srtc_Ip_ConvertTimeDateToSeconds(timeDate, &seconds);
        /* Set the time */
        Srtc_Ip_SetTimeSecondsRegister(base, seconds);
        status = SRTC_IP_SUCCESS;
    }

    return status;
}

/*================================================================================================*/
/**
* @brief         SRtc Driver function
* @details       This function:
*                        - Gets the current time and date and it will
*                               store in the state structure.
*
* @param[in]     instance           sRtc hw instance
* @param[in]     *timeDate          pointer to configuration
* @return        Srtc_Ip_StatusType  status error
* @pre           The driver needs to be initialized.
* @implements    Srtc_Ip_GetTimeDate_Activity
*/
Srtc_Ip_StatusType Srtc_Ip_GetTimeDate(uint8 instance, Srtc_Ip_TimedateType * const timeDate)
{
#if SRTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(NULL_PTR != timeDate);
    DevAssert(RTC_INSTANCE_COUNT > instance);
#endif

    Srtc_Ip_StatusType status = SRTC_IP_ERROR;
    uint32 firstRead = 0U;
    uint32 secondRead = 0U;

    /* Make two consecutive reads to ensure that the read was not done when the counter is incrementing.
     * This is recommended in the reference manual. */
    firstRead = Srtc_Ip_GetTimeSecondsRegister(instance);
    secondRead = Srtc_Ip_GetTimeSecondsRegister(instance);

    if(firstRead != secondRead)
    {
        /* Reinitialize the temporary variable */
        firstRead = 0U;
        /* Get the current time again */
        firstRead = Srtc_Ip_GetTimeSecondsRegister(instance);
        if(firstRead != secondRead)
        {
            status = SRTC_IP_ERROR;
        }
        else
        {
            /* Convert the current time from seconds to time date structure */
            Srtc_Ip_ConvertSecondsToTimeDate(&firstRead, timeDate);
            status = SRTC_IP_SUCCESS;
        }
    }
    else
    {
        /* Convert the current time from seconds to time date structure */
        Srtc_Ip_ConvertSecondsToTimeDate(&firstRead, timeDate);
        status = SRTC_IP_SUCCESS;
    }

    return status;
}

/*================================================================================================*/
/**
*
* @brief         SRtc Driver function
* @details       This function:
*                        - Configures the alarm based on the
*                               configuration structure passed by the user.
*                               When using alarm that are configured to be repetitive,
*                               enable the interrupt. Otherwise the repeat function will
*                               not work.
*
* @param[in]     instance           Rtc hw instance
* @param[in]     *alarmConfig       pointer to configuration
* @return        Srtc_Ip_StatusType  status error
* @pre           The driver needs to be initialized.
* @implements    Srtc_Ip_ConfigureAlarm_Activity
*/
Srtc_Ip_StatusType Srtc_Ip_ConfigureAlarm(uint8 instance,
                                          const Srtc_Ip_AlarmConfigType *alarmConfig)
{
    Srtc_Ip_StatusType status = SRTC_IP_ERROR;
    RTC_Type * base;
    base = sRtcBase[instance];

#if SRTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(NULL_PTR != alarmConfig);
    DevAssert(RTC_INSTANCE_COUNT > instance);
#endif

    uint32 convertedAlarmTime;
    uint32 currentTime;

    /* Check if the alarm time is in a correct format */
    if (TRUE == Srtc_Ip_IsTimeDateCorrectFormat(&(alarmConfig->alarmTime)))
    {
        /* save alarm configuration into ch state variable*/
        Srtc_Ip_u32ChState[instance].alarmInit = TRUE;
        Srtc_Ip_u32ChState[instance].repetitionInterval = alarmConfig->repetitionInterval;
        Srtc_Ip_u32ChState[instance].numberOfRepeats = alarmConfig->numberOfRepeats;
        Srtc_Ip_u32ChState[instance].repeatForever = alarmConfig->repeatForever;
        Srtc_Ip_u32ChState[instance].alarmIntEnable = alarmConfig->alarmIntEnable;
        Srtc_Ip_u32ChState[instance].alarmCallback = alarmConfig->alarmCallback;
        Srtc_Ip_u32ChState[instance].callbackParams = alarmConfig->callbackParams;
        /* Convert the time date to seconds */
        Srtc_Ip_ConvertTimeDateToSeconds(&(alarmConfig->alarmTime), &convertedAlarmTime);
        /* Get current time in seconds */
        currentTime = Srtc_Ip_GetTimeSecondsRegister(instance);

        /* Check if the alarm time is greater than current time */
        if(convertedAlarmTime > currentTime)
        {
            /* Write alarm time into Time Alarm Register */
            Srtc_Ip_SetTimeAlarmRegister(base, convertedAlarmTime);
            /* Enable/disable interrupt source based on the configuration */
            Srtc_Ip_SetTimeAlarmInterrupt(base, Srtc_Ip_u32ChState[instance].alarmIntEnable);
            status = SRTC_IP_SUCCESS;
        }
        else
        {
            status = SRTC_IP_ERROR;
        }
    }
    else
    {
        status = SRTC_IP_ERROR;
    }

    /* Return the exit code */
    return status;
}

/*================================================================================================*/
/**
*
* @brief         SRtc Driver function
* @details       This function:
*                - Configures the Time Seconds Interrupt with the Seconds interrupt Configuration Type.
* @param[in]     instance            Rtc hw instance
* @param[in]     occursFrequency     how often seconds interrupt occurs
* @return        Srtc_Ip_StatusType  status error
* @pre           The driver needs to be initialized.
* @implements    Srtc_Ip_ConfigureSecondsInterrupt_Activity
*/
Srtc_Ip_StatusType Srtc_Ip_ConfigureSecondsInterrupt(uint8 instance,
                                                     Srtc_Ip_SecIntFreqType occursFrequency)
{
    Srtc_Ip_StatusType status = SRTC_IP_ERROR;
    RTC_Type * base;
    base = sRtcBase[instance];

#if SRTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(RTC_INSTANCE_COUNT > instance);
#endif

    status = Srtc_Ip_SetSecondsInterruptConfiguration(base, occursFrequency);

    return status;
}

/*================================================================================================*/
#if (STD_ON == SRTC_IP_ENABLE_LOCK_REGISTER_API)
/**
*
* @brief         SRtc Driver function
* @details       This function:
*                   - Configures register lock for the corresponding
*                     RTC instance. Remember that all the registers are unlocked
*                     only by software reset or power on reset.
*                     (Except for CR that is unlocked only by POR).
* @param[in]     instance            Rtc hw instance
* @param[in]     lockRegister        register that will be locked
* @return        Srtc_Ip_StatusType  status error
* @pre           The driver needs to be initialized.
* @implements    Srtc_Ip_ConfigureLockRegister_Activity
*/
Srtc_Ip_StatusType Srtc_Ip_ConfigureLockRegister(uint8 instance,
                                                     Srtc_Ip_LockRegConfigType * const lockRegister)
{
    Srtc_Ip_StatusType status = SRTC_IP_ERROR;
    RTC_Type * base;
    base = sRtcBase[instance];

#if SRTC_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(RTC_INSTANCE_COUNT > instance);
#endif

    /* Configure Control register lock */
    if (lockRegister->controlRegisterLock)
    {
        status = Srtc_Ip_ConfigureLockReg(base, SRTC_IP_CTRL_REG_LOCK);
    }
    /* Configure Status register lock */
    if (lockRegister->statusRegisterLock)
    {
        status = Srtc_Ip_ConfigureLockReg(base, SRTC_IP_STATUS_REG_LOCK);
    }
    /* Configure Time Compensation register lock */
    if (lockRegister->timeCompensationRegisterLock)
    {
        status = Srtc_Ip_ConfigureLockReg(base, SRTC_IP_TCL_REG_LOCK);
    }
    /* Configure Lock register lock */
    if (lockRegister->lockRegisterLock)
    {
        status = Srtc_Ip_ConfigureLockReg(base, SRTC_IP_LOCK_REG_LOCK);
    }

    /* Return the exit code */
    return status;

}
#endif

#ifdef SRTC_0_CH_0_ISR_USED
/*================================================================================================*/
/**
* @brief          Interrupt handler for RTC channel
* @details        Interrupt Service Routine corresponding to RTC_CH_0 hw channel.
* @param[in]      none
* @return         void
* @isr
* @pre            The driver needs to be initialized.
*/
ISR(SRTC_0_Ch_0_ISR)
{
    Srtc_Ip_ProcessInterrupt(0U);
    EXIT_INTERRUPT();
}
#endif

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#endif /* SRTC_IP_USED == STD_ON */
#ifdef __cplusplus
}
#endif /* SRTC_IP_C */

/** @} */
