/*!
 * \file     SPC.c
 * \brief    implements the functions of the SPC middleware
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/
#define SPC_Middleware

/* ---- Includes ---- */
#include "SPC.h"
#include "Spi.h"
#include "Dio.h"

/* ---- Defines ---- */
#define SPC_SPI_CHANNEL_HV_MEAS SpiConf_SpiChannel_SpiChannel_0
#define SPC_SPI_CHANNEL_LV_MEAS SpiConf_SpiChannel_SpiChannel_1

/* ---- Global variables ---- */

/* ---- External functions ---- */

/* ---- Static variables ---- */
static uint8_t spc_Rxbuffer[SPC_BUFFER_SIZE];
static uint8_t spc_Txbuffer[SPC_BUFFER_SIZE];

/* ---- Static functions ---- */
/*!     \brief Initialization of SPC Middleware
 *       \param none
 *       \return none
 */
void SPC_Init(void)
{
    Spi_Init(&Spi_Config_Init);
    for (uint8_t i = 0; i < SPC_BUFFER_SIZE; i++)
    {
        spc_Rxbuffer[i] = 0x00;
        spc_Txbuffer[i] = 0x00;
    }
    Spc_returnMeasures.HvVoltage = 0x00;
    Spc_returnMeasures.HvCurrent = 0x00;
    Spc_returnMeasures.HvTemperature = 0x00;
    Spc_returnMeasures.LvVoltage = 0x00;
}

/*!     \brief Reading the Lv measures
 *       \param none
 *       \return Std_ReturnType
 */
void SPC_GetLvVoltageMeasures()
{
    // the CS is auto-driven using the job start notification
    // set up the External buffer
    // execute the sequence
    // the CS is auto-driven using the job end notification
    Spi_SetupEB(SPC_SPI_CHANNEL_LV_MEAS, spc_Txbuffer, spc_Rxbuffer,
    SPC_BUFFER_SIZE);
    Spi_AsyncTransmit(SpiConf_SpiJob_Spi_GetLwVoltageMeasures);
}

/*!     \brief Reading the Hv measures
 *       \param none
 *       \return Std_ReturnType
 */
void SPC_GetHvTemperaturesMeasures()
{
    Spi_SetupEB(SPC_SPI_CHANNEL_HV_MEAS, spc_Txbuffer, spc_Rxbuffer,
    SPC_BUFFER_SIZE);
    Spi_AsyncTransmit(
    SpiConf_SpiJob_Spi_GetHvTemperaturesMeasures);
}

void SPC_GetHvVoltageMeasures()
{
    Spi_SetupEB(SPC_SPI_CHANNEL_HV_MEAS, spc_Txbuffer, spc_Rxbuffer,
    SPC_BUFFER_SIZE);
    Spi_AsyncTransmit(SpiConf_SpiJob_Spi_GetHvVoltageMeasures);
}

void SPC_GetHvCurrentMeasures()
{
    Spi_SetupEB(SPC_SPI_CHANNEL_HV_MEAS, spc_Txbuffer, spc_Rxbuffer,
    SPC_BUFFER_SIZE);
    Spi_AsyncTransmit(SpiConf_SpiJob_Spi_GetHvCurrentMeasures);
}

/*!     \brief Deinitialization of SPC Middleware
 *       \param none
 *       \return none
 */
void SPC_Deinit(void)
{
    /* Nothing to do for now */
}

/*!     \brief Deinitialization of SPC Middleware
 *       \param none
 *       \return none
 */
void spc_RxGetLowVoltageMeasures(void)
{
    Spc_returnMeasures.LvVoltage = (uint16_t) ((spc_Rxbuffer[0] << 8)
            | spc_Rxbuffer[1]);
}

/*!     \brief Deinitialization of SPC Middleware
 *       \param none
 *       \return none
 */
void spc_RxGetHvVoltageMeasures(void)
{
    Spc_returnMeasures.HvVoltage = (uint16_t) ((spc_Rxbuffer[0] << 8)
            | spc_Rxbuffer[1]);
}

/*!     \brief Deinitialization of SPC Middleware
 *       \param none
 *       \return none
 */
void spc_RxGetHvCurrentMeasures(void)
{
    Spc_returnMeasures.HvCurrent = (uint16_t) ((spc_Rxbuffer[0] << 8)
            | spc_Rxbuffer[1]);
}

/*!     \brief Deinitialization of SPC Middleware
 *       \param none
 *       \return none
 */
void spc_RxGetHvTemperaturesMeasures(void)
{
    Spc_returnMeasures.HvTemperature = (uint16_t) ((spc_Rxbuffer[0] << 8)
            | spc_Rxbuffer[1]);
}
