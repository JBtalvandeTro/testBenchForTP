/*!
 * \file     DBG.c
 * \brief    Middleware layer dedicated to Powercore units Management
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

/* ---- Includes ---- */
#define DBG_MODULE
#include "DBG.h"
#include "COM.h"
#include "CTB.h"

/* ---- Defines ---- */

/* ---- Global variables ---- */

/* ---- External functions ---- */

/* ---- Static variables ---- */

/* ---- Static functions ---- */

static void dbg_executeLedsTest(void);
static void dbg_executeDiscreteIosTest(void);
static void dbg_executeRelaySwitchTest(void);
static void dbg_executeHvMeasureTest(void);
static void dbg_executeLvMeasureTest(void);

/*LDRA_HEADER_END*/

/*!     \brief   Initialization of DBG Management Module
 *       \param  none
 *       \return none
 */
void DBG_Init(void)
{
    DBG_Flags.proccesingFlags.processed = false;
}

void DBG_Update(void)
{
    // start processing the request :
    if (COM_debugTestReq.discreteIosTestRequest == true)
    {
        dbg_executeDiscreteIosTest();
        DBG_Flags.proccesingFlags.processed = true;
    }
    if (COM_debugTestReq.ledsTestRequest == true)
    {
        dbg_executeLedsTest();
        DBG_Flags.proccesingFlags.processed = true;
    }
    if (COM_debugTestReq.relaySwitchTestRequest == true)
    {
        dbg_executeRelaySwitchTest();
        DBG_Flags.proccesingFlags.processed = true;
    }
    if (COM_debugTestReq.hvMeasuresTestRequest == true)
    {
        dbg_executeHvMeasureTest();
        DBG_Flags.proccesingFlags.processed = true;
    }
    if (COM_debugTestReq.lvMeasuresTestRequest == true)
    {
        dbg_executeLvMeasureTest();
        DBG_Flags.proccesingFlags.processed = true;
    }
}

/*!     \brief   Deinitialization of DBG Management Module
 *       \param  none
 *       \return none
 */
void DBG_Deinit(void)
{
    /* Nothing to do for now */
}

static void dbg_executeDiscreteIosTest(void)
{
    // read the discretioCmd and depending on the cmd you raise a flag
    DBG_Flags.Reqflags.dsioTest = true;
    // in case we needed more operations to do
}

static void dbg_executeLedsTest(void)
{
    DBG_Flags.Reqflags.ledCmd = true;
    // in case we needed more operations to do
}

static void dbg_executeRelaySwitchTest(void)
{
    DBG_Flags.Reqflags.relaySwitchTest = true;
    // in case we needed more operations to do
}

static void dbg_executeHvMeasureTest(void)
{
    DBG_Flags.Reqflags.HvMeasure = true;
    // in case we needed more operations to do
}

static void dbg_executeLvMeasureTest(void)
{
    DBG_Flags.Reqflags.LvMeasure = true;
    // in case we needed more operations to do
}
