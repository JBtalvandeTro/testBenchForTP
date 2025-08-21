/*!
 * \file     PAR.h
 * \brief    Brief description of file content
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

#ifndef FILE_PAR_H
#define FILE_PAR_H

/* ---- Includes ---- */
#include "TYPedef.h"
#include "CST.h"
#include "PARdef.h"
#include "PARenum.h"
#include "Crc.h"
#include "FLA.h"

/* ---- Defines ---- */
#define PAR_CRC_INDEX            255U
#define PAR_SPECIFIC_WORD_INDEX  256U

/// params specific word value
#define PAR_SPECIFIC_WORD           0x5555AAAAU

/// size of param values table (4bytes for each param)
#define PAR_TABLE_SIZE              (PAR_SPECIFIC_WORD_INDEX + 2U)

/// Flash sector used for params
#define PAR_MAIN_PARTITION1         FLA_PARTITION_0
#define PAR_MAIN_PARTITION2         FLA_PARTITION_1
#define PAR_BACKUP_PARTITION1       FLA_PARTITION_2

/// The access rights of the application
//
/**
 * Some rules:
 * @li The access rights **MUST** be *one hot encoded*. It means, that the
 * values **MUST be powers of 2**.
 *
 * @li All values **MUST be positive**.
 *
 * @li The access right #PAR_ACCESSRIGHT_NO_PRIVILEDGE **MUST** exist. It's
 * value **MUST be 1**.
 */
typedef enum
{
    PAR_ACCESSRIGHT_NO_ACCESS = 0,
    /// No priviledge
    PAR_ACCESSRIGHT_NO_PRIVILEDGE = 0x1,
    /// Access right of the customer
    PAR_ACCESSRIGHT_CUSTOMER = 0x2,
    /// Access right of the super user
    PAR_ACCESSRIGHT_SUPERUSER = 0x4
} PAR_AccessRightE;

/// The union of signed/unsigned representations of parameter's value
typedef union
{
    /// The unsigned representation of the value
    uint32_t unsignedVal;
    /// The signed representation of the value
    int32_t signedVal;
    /// The float representation of the value
    float32 floatVal;
} PAR_ValueU;

/// Define the different possible types of a parameter
typedef enum
{
    /// Unsigned type 32 bits
    PAR_TYPE_UNSIGNED_32 = 0U,
    /// Signed type 32 bits
    PAR_TYPE_SIGNED_32,
    /// Unsigned type 16 bits
    PAR_TYPE_UNSIGNED_16,
    /// Signed type 16 bits
    PAR_TYPE_SIGNED_16,
    /// Unsigned type 8 bits
    PAR_TYPE_UNSIGNED_8,
    /// Signed type 8 bits
    PAR_TYPE_SIGNED_8,
    /// Float type
    PAR_TYPE_FLOAT
} PAR_TypeE;

/// An enum for read/write access
typedef enum
{
    /// Read access
    PAR_READ = 0U,
    /// Write access
    PAR_WRITE
} PAR_AccessE;

/// Enumation of the supported init value
typedef enum
{
    /// Initialize variable with value from FLASH
    PAR_INITVAL_USE_FLASH_VAL = 0,
    /// Initialize variable with default value (hard coded)
    PAR_INITVAL_USE_DEFAULT_VAL
} PAR_InitValueE;

// Types and Defines -----------------------------------------------------------
/// The errors of the Paramater Manager Library
typedef enum
{
    /// No error **MUST** be 0
    PAR_ERROR_NO_ERROR = 0U,
    /// Read access denied by access control
    PAR_ERROR_READ_ACCESS_DENIED,
    /// Write access denied by access control
    PAR_ERROR_WRITE_ACCESS_DENIED,
    /// Parameter index is not known (check #PAR_param_e)
    PAR_ERROR_WRONG_PARAM_INDEX,
    /// Unsupported access right (check #PAR_AccessRightE)
    PAR_ERROR_UNSUPPORTED_ACCESSRIGHT,
    /// Unsupported access type (check #par_access_e)
    PAR_ERROR_UNSUPPORTED_ACCESSTYPE,
    /// Unsupported initial value (see #PAR_initValue_e)
    PAR_ERROR_UNSUPPORTED_INITVAL,
    /// Feature not supported (because of HW limitation for example)
    PAR_ERROR_FEATURE_NOT_SUPPORTED,
    /// Bank index for "use default value" flag is out of bound
    PAR_ERROR_USEDEFVAL_FLAG_BANK_OUTOFBOUND,
    /// "Use default value" flag index is out of bound
    PAR_ERROR_USEDEFVAL_FLAG_INDEX_OUTOFBOUND,
    /// An unexpected behavior happened (probably a software bug or misuse of the module)
    PAR_ERROR_INTERNAL_ERROR,
    /// Memory overflow: parameter data is too big to be stored in memory
    PAR_ERROR_MEMORY_OVERFLOW,
    /// Parameters' initialization error
    PAR_ERROR_INITIALIZATION_ERROR,
    /// The value of a parameter is out of its defined possible range
    PAR_ERROR_OUT_OF_RANGE,

//#if TARGET_IS_TI_F2803X
    /// The CSM is preventing the function from performing its operation
    PAR_ERROR_STATUS_FAIL_CSM_LOCKED,
    /// Device REVID does not match that required by the API
    PAR_ERROR_STATUS_FAIL_REVID_INVALID,
    /// Invalid address passed to the API
    PAR_ERROR_STATUS_FAIL_ADDR_INVALID,
    /// Incorrect PARTID: for example the F2806 API was used on a F2808 device.
    PAR_ERROR_STATUS_FAIL_INCORRECT_PARTID,
    /** API/Silicon missmatch.  An old version of the API is being used on
     * silicon it is not valid for Please update to the latest API. */
    PAR_ERROR_STATUS_FAIL_API_SILICON_MISMATCH,

    // ---- Erase Specific errors ----
    /// Erase error: no sector specified
    PAR_ERROR_STATUS_FAIL_NO_SECTOR_SPECIFIED,
    /// Erase error: precondition failed
    PAR_ERROR_STATUS_FAIL_PRECONDITION,
    /// Erase error: erase failed
    PAR_ERROR_STATUS_FAIL_ERASE,
    /// Erase error: compaction failed
    PAR_ERROR_STATUS_FAIL_COMPACT,
    /// Erase error: precompaction failed
    PAR_ERROR_STATUS_FAIL_PRECOMPACT,

    // ---- Program Specific errors ----
    /// Program error: zero bit error
    PAR_ERROR_STATUS_FAIL_ZERO_BIT_ERROR,

    // ---- Verify Specific errors ----

    /** Busy is set by each API function before it determines a pass or fail
     * condition for that operation. The calling function will will not receive
     * this status condition back from the API*/
    PAR_ERROR_STATUS_BUSY,
//#endif
    /// Program error: program failed
    PAR_ERROR_STATUS_FAIL_PROGRAM,
    /// Verify error: verify failed
    PAR_ERROR_STATUS_FAIL_VERIFY,
    /// A timeout occurred during sector erase operation
    PAR_ERROR_FLASH_ERASE_TIMEOUT,
    /// Configuration error
    PAR_ERROR_BAD_SECTOR,
    /// Address configured is not a flash address
    PAR_ERROR_NOT_FLASH_ADDR,
    /// Memory corruption
    PAR_ERROR_CORRUPTED_MEMORY,

    /// The count of errors
    PAR_ERROR_COUNT
} PAR_ErrorsE;

/// The structure for parameters configuration
typedef struct
{
    /// The read access rights
    PAR_AccessRightE readAccessRight;
    /// The write access rights
    PAR_AccessRightE writeAccessRight;
    /// Minimum value of the parameter
    PAR_ValueU min;
    /// Maximum value of a parameter
    PAR_ValueU max;
    /// The harcoded value (default value)
    PAR_ValueU defaultVal;
    /// The real value
    PAR_ValueU realVal;
    /// Type of a parameter - to check parameter value range
    PAR_TypeE type;
} PAR_ConfigStr;

typedef struct
{
    boolean processed :1;
    uint16_t index;
    PAR_ValueU value;
    PAR_ValueU readValue;
    PAR_ErrorsE lastError;
} PAR_ParamReqStr;

/* fault flags of PAR module */
typedef struct
{
    boolean flashValueError :1;
    uint32_t reserved :31;
} PAR_FaultFlagsStr;

/* status flags of PAR module */
typedef struct
{
    boolean moduleInitialized :1;
    boolean rebootRequested :1;
    uint32_t reserved :30;
} PAR_StatusFlagsStr;

/* Flag union to be able to check them in one instruction */
typedef union
{
    PAR_FaultFlagsStr flags;
    uint32_t all;
} PAR_FaultFlagsU;

/* Flag union to be able to check them in one instruction */
typedef union
{
    PAR_StatusFlagsStr flags;
    uint32_t all;
} PAR_StatusFlagsU;

/* Structure to unite faults and statuts regs */
typedef struct
{
    PAR_FaultFlagsU faults;
    PAR_StatusFlagsU status;
} PAR_FlagsStr;

/* Flag structures union to be able to check them in one instruction */
typedef union
{
    PAR_FlagsStr moduleFlags;
    uint64_t all;
} PAR_FlagsU;


/* ---- Global variables ---- */

/* Defined in PARconfig.c */
extern PAR_ConfigStr PAR_paramConfig[PAR_COUNT];

#ifndef PAR_MODULE
extern PAR_FlagsU PAR_flags;
extern PAR_ParamReqStr PAR_paramReq;
extern PAR_AccessRightE PAR_right;
extern boolean PAR_flashUpToDate;
extern boolean PAR_writeAtInit;
extern uint32_t PAR_ParamValues[PAR_TABLE_SIZE];
extern boolean PAR_FpgaParamUpdatePending[PAR_COUNT];
extern FLA_PartitionIdE PAR_currentFlashPartition;
#else
PAR_FlagsU          PAR_flags;
PAR_ParamReqStr     PAR_paramReq;
PAR_AccessRightE    PAR_right;
boolean             PAR_flashUpToDate;      /* If true, at least one parameter has been updated in RAM but not saved in Flash yet */
boolean             PAR_writeAtInit;
uint32_t PAR_ParamValues[PAR_TABLE_SIZE];
boolean PAR_FpgaParamUpdatePending[PAR_COUNT];
FLA_PartitionIdE PAR_currentFlashPartition;
#endif

/* ---- Global functions ---- */
void PAR_Init(void);
uint16_t PAR_CalculateCRC(const uint8_t *data, uint32_t len);
void PAR_Deinit(void);

#endif /* FILE_PAR_H */
