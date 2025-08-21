/*!
 * \file     CTBCbit.c
 * \brief    implements the functions of the CTBCbit sub-module
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

/* ---- Includes ---- */
#define CTBCbit_SubModule

#include "CTBCbit.h"
#include "Port.h"
#include "Dio.h"
#include "TYPedef.h"
#include "CTB_dsiodef.h"
#include "COM.h"

/* ---- Defines ---- */

/* ---- Global variables ---- */

/* ---- External functions ---- */

/* ---- Static variables ---- */

/* ---- Static functions ---- */

static boolean ctbCbit_ReadHealthDSO(void);
static void ctbCbit_SetHealthDSO(void);
static void ctbCbit_UnsetHealthDSO(void);
static boolean ctbCbit_ReadSpareDSO(void);
static void ctbCbit_SetSpareDSO(void);
static void ctbCbit_UnsetSpareDSO(void);

/*!     \brief Initialization of CTBCbit Sub-Module
 *       \param none
 *       \return none
 */
void CTBCbit_Init(void)
{
    // enabling the power supply on the DSI/DSO
    Dio_WriteChannel(DioConf_DioChannel_DSI_EN1, STD_HIGH);
    Dio_WriteChannel(DioConf_DioChannel_DSI_EN2, STD_HIGH);
    Dio_WriteChannel(DioConf_DioChannel_DSI_EN3, STD_HIGH);
    Dio_WriteChannel(DioConf_DioChannel_DSI_EN4, STD_HIGH);
    Dio_WriteChannel(DioConf_DioChannel_DSI_EN5, STD_HIGH);
    Dio_WriteChannel(DioConf_DioChannel_DSI_EN6, STD_HIGH);
    Dio_WriteChannel(DioConf_DioChannel_DSO_28_EN, STD_HIGH);
    Dio_WriteChannel(DioConf_DioChannel_DSO_GND_EN, STD_HIGH);
}


/*!     \brief setting the a specific DSO to STD_HIGH
 *       \param     state   boolean
 *       \return none
 */
void CTBCbit_SetDSO(uint8_t pinId)
{
    switch (pinId)
    {
        case HEALTH:
            ctbCbit_SetHealthDSO();
            break;
        case DSO_SPARE_1:
            ctbCbit_SetSpareDSO();
            break;
        default:
            // Undefined Pin do nothing // shall never happen
            break;
    }
}

/*!     \brief setting the a specific DSO pin to STD_LOW
 *       \param     state   boolean
 *       \return none
 */
void CTBCbit_UnsetDSO(uint8_t pinId)
{
    switch (pinId)
    {
        case HEALTH:
            ctbCbit_UnsetHealthDSO();
            break;
        case DSO_SPARE_1:
            ctbCbit_UnsetSpareDSO();
            break;
        default:
            // Undefined Pin do nothing // shall never happen
            break;
    }
}

/*!     \brief reading the a specific DSO pin
 *       \param pinId uint8_t
 *       \return boolean
 */
void CTBCbit_ReadDSO(uint8_t pinId)
{
    switch (pinId)
    {
        case HEALTH:
            ctb_DSO_readResult = ctbCbit_ReadHealthDSO();
            break;
        case DSO_SPARE_1:
            ctb_DSO_readResult = ctbCbit_ReadSpareDSO();
            break;
        default:
            // Undefined Pin do nothing // shall never happen
            break;
    }
}

/*!     \brief function to start the tests on CTBCbit
 *       \param none
 *       \return none
 */
void CTBCbit_Runtests(void)
{
    uint8_t pinId, pincmd;
    pinId = COM_debugTestReq.discreteIoId;
    pincmd = COM_debugTestReq.discreteIoCmd;
    switch (pincmd)
    {
        // other cmd will be managed with the CTB_PBIT submodule (start tests DSI, stop tests DSO ...)
        case CTBCBIT_READDSO_CMD:
            CTBCbit_ReadDSO(pinId);
            break;
        case CTBCBIT_UNSETDSO_CMD:
            CTBCbit_UnsetDSO(pinId);
            break;
        case CTBCBIT_SETDSO_CMD:
            CTBCbit_SetDSO(pinId);
            break;
        default:
            // Undefined Command do nothing
            break;
    }
}

/*!     \brief Deinitialisation of CTBCbit Sub-Module
 *       \param none
 *       \return none
 */
void CTBCbit_Deinit(void)
{
    /* Nothing to do for now*/
}

/*!     \brief reading the DSO HEALTH
 *       \param
 *       \return boolean
 */
static boolean ctbCbit_ReadHealthDSO(void)
{
    Port_SetPinMode(DSO_CPU1_PIN, DSO_CPU1_GPIO_MODE);
    return Dio_ReadChannel(DioConf_DioChannel_DSO_CPU1);
}

/*!     \brief reading the DSO Spare
 *       \param
 *       \return boolean
 */
static boolean ctbCbit_ReadSpareDSO(void)
{
    Port_SetPinMode(DSO_CPU2_PIN, DSO_CPU2_GPIO_MODE);
    return Dio_ReadChannel(DioConf_DioChannel_DSO_CPU2);
}

/*!     \brief setting the DSO HEALTH
 *       \param    none
 *       \return none
 */
static void ctbCbit_SetHealthDSO(void)
{
    Port_SetPinMode(DSO_CPU1_PIN, DSO_CPU1_GPIO_MODE);
    Dio_WriteChannel(DioConf_DioChannel_DSO_CPU1, STD_HIGH);
}

/*!     \brief Unsetting setting the DSO HEALTH
 *       \param     none
 *       \return none
 */
static void ctbCbit_UnsetHealthDSO(void)
{
    Port_SetPinMode(DSO_CPU1_PIN, DSO_CPU1_GPIO_MODE);
    Dio_WriteChannel(DioConf_DioChannel_DSO_CPU1, STD_LOW);
}

/*!     \brief setting the DSO HEALTH
 *       \param    none
 *       \return none
 */
static void ctbCbit_SetSpareDSO(void)
{
    Port_SetPinMode(DSO_CPU2_PIN, DSO_CPU2_GPIO_MODE);
    Dio_WriteChannel(DioConf_DioChannel_DSO_CPU2, STD_HIGH);
}

/*!     \brief Unsetting setting the DSO HEALTH
 *       \param     none
 *       \return none
 */
static void ctbCbit_UnsetSpareDSO(void)
{
    Port_SetPinMode(DSO_CPU2_PIN, DSO_CPU2_GPIO_MODE);
    Dio_WriteChannel(DioConf_DioChannel_DSO_CPU2, STD_LOW);
}
