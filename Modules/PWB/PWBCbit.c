/*!
 * \file     PWBCbit.c
 * \brief    implements the functions of the PWBCbit sub-module
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/
#define PWBCBIT_SUBMODULE
/* ---- Includes ---- */
#include "PWBCbit.h"
#include "SPC.h"
#include "PAR.h"
#include "COM.h"
#include "Dio.h"
#include "TYPedef.h"

/* ---- Defines ---- */
#define A01 DioConf_DioChannel_A0_1
#define A11 DioConf_DioChannel_A1_1
#define A21 DioConf_DioChannel_A2_1

#define A02 DioConf_DioChannel_A0_2
#define A12 DioConf_DioChannel_A1_2
#define A22 DioConf_DioChannel_A2_2

#define BUFFER_SIZE 2U

/* ---- Global variables ---- */

/* ---- External functions ---- */

/* ---- Static variables ---- */
static uint32_t psValidDebounceBuffer = 0xFFFF;
/* ---- Static functions ---- */
static int32_t pwbCbit_getGainCalibration(uint8_t muxAdd);
static int32_t pwbCbit_getOffSetCalibration(uint8_t muxAdd);

/*!     \brief Initialazing the PWBCbit subModule
 *       \param none
 *       \return none
 */
void PWBCbit_Init(void)
{
    PWBCbit_cmdResults.ReadMeasResultHMI = 0;
    PWBCbit_cmdResults.ReadMeasResultRaw = 0;

    PWB_psValidState = true; // supposing we have a good ps valid in the initation
}

/*!     \brief getting the LV measures depeding on the muxAdd
 *       \param none
 *       \return none
 */
void PWBCbit_GetLvMeasures(uint8_t muxAdd)
{
    uint8_t bit0 = muxAdd & 0x01; // Least significant bit
    uint8_t bit1 = (muxAdd >> 1) & 0x01; // Second least significant bit
    uint8_t bit2 = (muxAdd >> 2) & 0x01; // Third least significant bit
    // driver the GPIO pins to access the Mux, based on the muxAdd
    Dio_WriteChannel(A02, bit0);
    Dio_WriteChannel(A12, bit1);
    Dio_WriteChannel(A22, bit2);

    uint32_t result = 0;

    SPC_GetLvVoltageMeasures();
    result = Spc_returnMeasures.LvVoltage;

    // calibrating the measures

    int32_t gain = PAR_paramConfig[PAR_CALIBRATION_A_VLV].realVal.signedVal;
    int32_t offset = PAR_paramConfig[PAR_CALIBRATION_B_VLV].realVal.signedVal;
    int32_t tempMeasure = 0;

    PWBCbit_cmdResults.ReadMeasResultRaw = (uint16_t) result;
    tempMeasure = (int32_t)((gain * result) + offset);
    PWBCbit_cmdResults.ReadMeasResultHMI = (int32_t)(tempMeasure/100);
}

/*!     \brief getting the HV measures depeding on the muxAdd
 *       \param none
 *       \return none
 */

void PWBCbit_GetHvMeasures(uint8_t muxAdd)
{
    uint8_t bit0 = muxAdd & 0x01; // Least significant bit
    uint8_t bit1 = (muxAdd >> 1) & 0x01; // Second least significant bit
    uint8_t bit2 = (muxAdd >> 2) & 0x01; // Third least significant bit
    // driver the GPIO pins to access the Mux, based on the muxAdd
    Dio_WriteChannel(A01, bit0);
    Dio_WriteChannel(A11, bit1);
    Dio_WriteChannel(A21, bit2);

    uint32_t result = 0;

    switch (muxAdd)
    {
        case Hv_Current_Meas_Mux:
            SPC_GetHvCurrentMeasures();
            result = Spc_returnMeasures.HvCurrent;
            break;
        case Hv_Temp_Meas_Mux:
            SPC_GetHvTemperaturesMeasures();
            result = Spc_returnMeasures.HvTemperature;
            break;
        case Hv_Voltage_Meas_Mux:
            SPC_GetHvVoltageMeasures();
            result = Spc_returnMeasures.HvVoltage;
            break;
        default:
            break;
    }

    // calibrating the measures

    int32_t gain = pwbCbit_getGainCalibration(muxAdd);
    int32_t offset = pwbCbit_getOffSetCalibration(muxAdd);
    int32_t tempMeasure = 0;

    PWBCbit_cmdResults.ReadMeasResultRaw = (uint16_t) result;
    tempMeasure = (int32_t)((gain * result) + offset);
    PWBCbit_cmdResults.ReadMeasResultHMI = (int32_t)(tempMeasure/100);
}

/*!     \brief deinitialazing the PWBCbit subModule
 *       \param none
 *       \return none
 */
void PWBCbit_Deinit(void)
{
    /*Nothing to do*/
}

static int32_t pwbCbit_getGainCalibration(uint8_t muxAdd)
{
    int32_t gainTemp = 0;
    switch (muxAdd)
    {
        case Hv_Voltage_Meas_Mux:
            gainTemp = PAR_paramConfig[PAR_CALIBRATION_A_VHV].realVal.signedVal;
            break;
        case Hv_Current_Meas_Mux:
            gainTemp = PAR_paramConfig[PAR_CALIBRATION_A_IHV].realVal.signedVal;
            break;
        case Hv_Temp_Meas_Mux:
            gainTemp = PAR_paramConfig[PAR_CALIBRATION_A_T1].realVal.signedVal;
            break;
        default:
            /* Nothing to do the Gain is set to 0 by default */
            break;
    }
    return gainTemp;
}

static int32_t pwbCbit_getOffSetCalibration(uint8_t muxAdd)
{
    int32_t offSetTemp = 0;
    switch (muxAdd)
    {
        case Hv_Voltage_Meas_Mux:
            offSetTemp =
                    PAR_paramConfig[PAR_CALIBRATION_B_VHV].realVal.signedVal;
            break;
        case Hv_Current_Meas_Mux:
            offSetTemp =
                    PAR_paramConfig[PAR_CALIBRATION_B_IHV].realVal.signedVal;
            break;
        case Hv_Temp_Meas_Mux:
            offSetTemp =
                    PAR_paramConfig[PAR_CALIBRATION_B_T1].realVal.signedVal;
            break;
        default:
            /* Nothing to do the Gain is set to 0 by default */
            break;
    }
    return offSetTemp;
}

void PWBCBit_UpdatePsValidState(void)
{
    boolean currentState = Dio_ReadChannel(DioConf_DioChannel_PsValid);
    psValidDebounceBuffer = (psValidDebounceBuffer << 1) | currentState;
    if ((psValidDebounceBuffer & 0x1F) == 0x1F)
    {
        PWB_psValidState = true;
    }
    else if ((psValidDebounceBuffer & 0x1F) == 0x00)
    {
        PWB_psValidState = false;
    }
    else
    {

    }
}
