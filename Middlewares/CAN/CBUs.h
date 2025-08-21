/*!
 * \file     CBUs.h
 * \brief    CAN Bus middleware header
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

#ifndef FILE_CBUS_H
#define FILE_CBUS_H

/* ---- Includes ---- */
#include "TYPedef.h"
#include "CST.h"
#include "CBUctrl.h"
#include "CBUinter.h"
#include "CBUmaint.h"
#include "Can.h"
#include "CanIf.h"
#include "CNV.h"

/* ---- Defines ---- */
/* CAN controllers affectation */
#define CBU_CONTROLCAN      CanController_Primary // check MCAL definition
#define CBU_MAINTENANCECAN    CanController_Maint
#define CBU_INTERNALCAN  CanController_Internal


#define CBU_NBCAN           3u
/* Macro */
#define CBU_SET_UINT16(buffer, index, value) \
    do { \
        (buffer[index]) = (uint8_t)(value); \
        buffer[index + 1] = (uint8_t)((value) >> 8); \
    } while (0)

#define CBU_SET_UINT32(buffer, index, value) \
    do { \
    buffer[index] = (uint8_t)((value) & 0xFF); \
    buffer[index + 1] = (uint8_t)((value >> 8) & 0xFF); \
    buffer[index + 2] = (uint8_t)((value >> 16) & 0xFF); \
    buffer[index + 3] = (uint8_t)((value >> 24) & 0xFF); \
    } while(0)


#define CBU_GET_UINT16(buffer, index)  \
 (uint16_t)(((uint16_t)(buffer)[index + 1] << 8) | (uint16_t)(buffer)[index])


#define CBU_GET_UINT32(buffer, index) \
     (uint32_t)(((uint32_t)buffer[index + 3] << 24) | ((uint32_t)buffer[index + 2] << 16) | \
     ((uint32_t)buffer[index + 1] << 8) | (uint32_t)buffer[index])

/* Mailboxes count */
#define CBU_MAILBOXES_COUNT CAN_HWOBJECT_CONFIG_COUNT


typedef struct
{
    boolean canCInitialized :1;
    boolean canIInitialized :1;
    boolean canMInitialized :1;
    boolean middlewareInitialized :1;
    boolean canCComLost :1;
    boolean canIComLost :1;
    boolean canMComLost :1;
    uint8_t reserved :1;
} CBU_FlagsStr;

typedef union
{
    CBU_FlagsStr status;
    uint8 all;
} CBU_FlagsU;

typedef struct
{
    uint8_t idController;
    uint32_t frameId;
    Can_HwObjectHandleType frameDir;
    boolean isPending;
    uint8_t buffer[CST_CAN_BUFFER_SIZE];
    uint32_t frameLength;
} CBU_FrameStatusStr;

typedef enum
{
    /// 500 kbps nominal, no BRS
    CBU_BR_500KBPS= 0,
    CBU_BR_COUNTS
} CBU_BitRatesE;

/* ---- Global variables ---- */
#ifndef CBU_MIDDLEWARE
extern CBU_FrameStatusStr CBU_framesStatus[CBU_MAILBOXES_COUNT];
extern CBU_FlagsU CBU_flags;
extern uint8_t CBU_Address;
extern uint8_t CBU_powerCoreAdd;
#else
CBU_FrameStatusStr  CBU_framesStatus[CBU_MAILBOXES_COUNT];
CBU_FlagsU  CBU_flags;
uint8_t CBU_Address;
uint16_t CBU_powerCoreAdd;
#endif

/* ---- Global functions ---- */
void CBU_Init(boolean cStart, boolean iStart, boolean mStart);
void CBU_Deinit(void);
void CBU_CheckErrors(void);
void CBU_ClearPendingFlag(uint16_t mailbox);
void CBU_CreatePduInfo(Can_IdType id, PduIdType swPduHandle, uint8 length, uint8 *sdu, Can_PduType* pduInfoPtr);
void CBU_SendFrame(Can_PduType pdu, uint8_t mailbox);
void CBU_SetBitrate(uint8_t  canPort, uint16_t bitrate, uint32_t finalState);
uint8_t CBU_CheckLength(uint8_t length);


#endif /* FILE_CBUS_H */
