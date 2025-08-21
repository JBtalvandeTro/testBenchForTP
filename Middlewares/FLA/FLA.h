/*!
 * \file     FLA.h
 * \brief    Internal flash middleware header file.
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

#ifndef FILE_FLA_H
#define FILE_FLA_H

/* ---- Includes ---- */
#include "TYPedef.h"
#include "CST.h"

/* ---- Defines ---- */
/// Flash sector size in bytes
#define FLA_SECTOR_SIZE 4096U

typedef enum
{
    /// Main params 1 sector
    FLA_PARTITION_0 = 0,
    /// Main params 2 sector
    FLA_PARTITION_1,
    /// Backup params sector
    FLA_PARTITION_2,
    FLA_PARTITION_COUNT
}FLA_PartitionIdE;

typedef enum
{
    FLA_OK = 0,
    FLA_NOT_OK,
}FLA_StatusE;


/* ---- Global variables ---- */
extern boolean FLA_Initialized;

/* ---- Global functions ---- */
void FLA_Init(void);
void FLA_Deinit(void);
FLA_StatusE Fla_GetPartitionSize(FLA_PartitionIdE partition, uint32_t* size);
FLA_StatusE FLA_Erase(FLA_PartitionIdE partition);
FLA_StatusE FLA_Program(FLA_PartitionIdE partition, uint8* dataBuffer, uint32_t size);
FLA_StatusE FLA_Write(FLA_PartitionIdE partition, uint32_t offset, const uint8* dataBuffer, uint32_t size);
FLA_StatusE FLA_Read(FLA_PartitionIdE partition, uint32_t offset, uint8* dataBuffer, uint32_t size);

#endif /* FILE_FLA_H */
