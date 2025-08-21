/*
C TESTBED VERSION  : 10.1.0
FILE UNDER TEST  : "C:\Users\jbtalvande\Documents\Tronico\Team-Power\01_Projet\02_MTU\02-Code\01_MCU\50073-50147DC333-S
DATE OF ANALYSIS : Fri Apr  4 11:39:04 2025
*/
 /*!
 * \file CBU_Maintenance.c
 * \brief Middleware layer dedicated to maintenance CAN bus
 *
 * TRONICO
 * 26, rue du bocage
 * 85660 St Philbert De Bouaine
 **/
/* ---- Includes ---- */
#define QQQdialect GCC____C99                                                                                                                                                                                                        
#undef QQQ146
#undef QQQ148
#undef QQQbndchk
#undef QQQ294
#undef QQQEMBEDDEDICE
 /* Note: for BITMAP execution histories QQQthreaded is not defined */
#undef QQQthreaded 
#undef QQQdo178b
#undef QQQfixbra
#undef QQQswitch3
#undef QQQternary
#undef QQQswitch
#undef QQQmacrof
#undef QQQMULTIPROCESSEXH
#undef QQFLUSH
#undef QQNEWBS
#define qqqMaxBranchDepth      2
#undef QQQstructbitmap
 static int zzfileid =      1;
#undef QQQALGONE
#undef QQQVCLFLG
#undef QQQFORKFL
#undef QQQIADDRF
#undef QQQRTI
#undef QQQPERFA
#undef QQQADRMOD
#undef QQQDCAPFL
#undef QQQTEMPLATEONLY
#undef QQQNOATEXIT
#undef QQQUPLOADATEND
#undef QQQNOSTDIO
#undef QQQASHLINGVITRA
#undef QQQBITMAPMCDC 
#undef QQQTIC2XSERIALIO
#undef QQQTIC2XFLASH
#undef QQQCOMPRESSED_EXH
#undef QQQMAINFL
#undef QQQSINGLEFILE
#undef QQQFILEID
#undef QQQseparate
 static int CBUmaint_1zzopen                                                                                     = 0;
#ifndef QQQLDRA_PORT                                                                                                                                                                                                                                                
#define FILEPOINT FILE * f,                                                                                                                                                                                                                                         
#if !defined(QQQTEMPLATEONLY) && !defined(FILE) && !defined(QQQNOSTDIO)                                                                                                                                                                                             
#include <stdio.h>                                                                                                                                                                                                                                                  
    /* ----------------------------------------------------------------------* 100 *                                                                                                                                                                                
     * If stdio.h is not available then insert:                                                                                                                                                                                                                     
     *      typedef int * FILE;                                                                                                                                                                                                                                     
     * -----------------------------------------------------------------------------                                                                                                                                                                                
     */                                                                                                                                                                                                                                                             
#endif  /* !(QQQTEMPLATEONLY) && !(FILE) && !(QQQNOSTDIO) */                                                                                                                                                                                                        
#else  /* QQQLDRA_PORT */                                                                                                                                                                                                                                           
#define FILEPOINT                                                                                                                                                                                                                                                   
#include "ldra_port.h"        /* Generic header file for LDRA_PORT */                                                                                                                                                                                               
#ifdef inc_ldra_port_instr                                                                                                                                                                                                                                          
#include "ldra_port_instr.h"  /* Communication definitions and ldra_port common code */                                                                                                                                                                             
#endif  /* inc_ldra_port_instr */                                                                                                                                                                                                                                   
#endif /* QQQLDRA_PORT */                                                                                                                                                                                                                                           
#ifndef QQQnumfil                                                                                                                                                                                                                                                   
#define QQQnumfil 40  /* default setting */                                                                                                                                                                                                                         
#endif  /* QQQnumfil */                                                                                                                                                                                                                                             
#if defined(QQQstructbitmap) && defined(QQQSINGLEFILE)                                                                                                                                                                                                              
      typedef void(*ldra_void_function)();                                                                                                                                                                                                                          
#if defined(QQQMAINFL)                                                                                                                                                                                                                                              
        /* Set qqqshell_upload to 1 if you want to call the qqqtotalupload separately. Although                                                                                                                                                                     
           through the target you would have to set this to 0 before calling the qqqupload.                                                                                                                                                                         
           Move this into ldra_port mechanism. */                                                                                                                                                                                                                   
       int qqqshell_upload = 0;                                                                                                                                                                                                                                     
       int QQQfcn_ptr_num = 0;                                                                                                                                                                                                                                      
       static int qqqisinitialised = 0;                                                                                                                                                                                                                             
       ldra_void_function qqqaccumupload[QQQnumfil];                                                                                                                                                                                                                
       ldra_void_function qqqaccumreset[QQQnumfil];                                                                                                                                                                                                                 
       void qqqtotalupload(void);                                                                                                                                                                                                                                   
       void qqqtotalreset(void);                                                                                                                                                                                                                                    
       void qqpopulate_array_fcn_ptrQQ(int x, ldra_void_function y, ldra_void_function z)                                                                                                                                                                           
       {                                                                                                                                                                                                                                                            
         qqqaccumupload[x]=y;                                                                                                                                                                                                                                       
         qqqaccumreset[x]=z;                                                                                                                                                                                                                                        
         QQQfcn_ptr_num++;                                                                                                                                                                                                                                          
       }                                                                                                                                                                                                                                                            
#else  /* (QQQMAINFL) */                                                                                                                                                                                                                                            
        extern int QQQfcn_ptr_num;                                                                                                                                                                                                                                  
        extern ldra_void_function qqqaccumupload[QQQnumfil];                                                                                                                                                                                                        
        extern void qqpopulate_array_fcn_ptrQQ(int x, ldra_void_function y, ldra_void_function z);                                                                                                                                                                  
        static int qqqstructzzopen = 0;                                                                                                                                                                                                                             
#endif  /* defined(QQQMAINFL) */                                                                                                                                                                                                                                    
#endif  /* defined(QQQstructbitmap) && defined(QQQSINGLEFILE) */                                                                                                                                                                                                    
#ifdef QQQ_KEEPCOMMENTS                                                                                                                                                                                                                                             
  /* -----------------------------------------------------------------------* 101 *                                                                                                                                                                                 
  *            Special settings for systems lacking standard functions.                                                                                                                                                                                             
  * To include code for fprintf define ldra_fprintf                                                                                                                                                                                                                 
  * To include code for sscanf  define ldra_sscanf                                                                                                                                                                                                                  
  * -----------------------------------------------------------------------------                                                                                                                                                                                   
  */                                                                                                                                                                                                                                                                
#endif  /* QQQ_KEEPCOMMENTS */                                                                                                                                                                                                                                      
#if !defined(QQQSUPPRESS_UNDEF)                                                                                                                                                                                                                                     
#undef ldra_fprintf                                                                                                                                                                                                                                                 
#undef ldra_sscanf                                                                                                                                                                                                                                                  
#endif  /* !defined(QQQSUPPRESS_UNDEF) */                                                                                                                                                                                                                           
  /*  #define ldra_fprintf */                                                                                                                                                                                                                                       
  /*  #define ldra_sscanf */                                                                                                                                                                                                                                        
#undef QQQHITMAP_STORAGE                                                                                                                                                                                                                                            
#undef qqnull_params                                                                                                                                                                                                                                                
#define qqnull_params void                                                                                                                                                                                                                                          
#define QQQ_PROTOTYPE_DEF                                                                                                                                                                                                                                           
  /* Conventional Instrumentation */                                                                                                                                                                                                                                
#undef QQ_ANSI_PROTOTYPE                                                                                                                                                                                                                                            
#ifdef __STDC__                                                                                                                                                                                                                                                     
#define QQ_ANSI_PROTOTYPE 1                                                                                                                                                                                                                                         
#else /* __STDC__ */                                                                                                                                                                                                                                                
#ifdef VAXC                                                                                                                                                                                                                                                         
#define QQ_ANSI_PROTOTYPE 1                                                                                                                                                                                                                                         
#endif  /* VAXC */                                                                                                                                                                                                                                                  
#endif  /* __STDC__ */                                                                                                                                                                                                                                              
  static void qqoutput(FILEPOINT char * s,int i);                                                                                                                                                                                                                   
  static void qqoutput0(FILEPOINT char * s);                                                                                                                                                                                                                        
  static int CBUmaint_1zqqzqz(qqnull_params);                                                                                                                                                                                                                       
  static int CBUmaint_1zqqzqz1(qqnull_params);                                                                                                                                                                                                                      
  static int CBUmaint_1zzqqzz (int qqqi);                                                                                                                                                                                                                           
  static int CBUmaint_1zqzqzq (int qqqi);                                                                                                                                                                                                                           
  static int CBUmaint_1zzzqtz (int qqqa, int qqqb);                                                                                                                                                                                                                 
  static int CBUmaint_1zzzqfz (int qqqa, int qqqb);                                                                                                                                                                                                                 
/* ------------------------------ END OF TESTBED PROTOTYPES -------------------------------- */                                                                                                                                                                     
/* OPEN FILE C:\Users\jbtalvande\Documents\Tronico\Team-Power\01_Projet\02_MTU\02-Code\01_MCU\50073-50147DC333-SW001\trunk\LDRA\LDRA_Files\CBUmaint.h */
/*!
 * \file CBU_Maintenance.h
 * \brief Maintenance CAN Bus middleware header
 *
 * TRONICO
 * 26, rue du bocage
 * 85660 St Philbert De Bouaine
 **/
#ifndef FILE_CBUMAINT_H
#define FILE_CBUMAINT_H
/* ---- Includes ---- */
#include "CST.h"
#include "TYPedef.h"
/* ---- Defines ---- */
/* ---- Global variables ---- */
/* ---- Global functions ---- */
/* -- TX -- */
 
void
    CBU_SendMaintenanceEquipmentTestResponse ( void ) ;
 
void
    CBU_SendMaintenanceParameterResponse (
    uint16_t paramId ,
    uint32_t ParamValue ,
    boolean status ) ;
    /* -- RX -- */
 
void
    CBU_GetMaintenanceEquipmentTestRequest (
    const uint8_t buffer [] ,
    uint8_t * testCmd ,
    uint8_t * muxAddress ,
    uint8_t * measFormat ,
    uint8_t * relaySwitchCmd ,
    uint8_t * relaySwitchId ,
    uint8_t * discreteIoCmd ,
    uint8_t * discreteIoId ,
    uint8_t * ledCmd ,
    uint8_t * ledId ,
    uint8_t * ledColor ,
    uint8_t * ledBlinkFreq ) ;
 
void
    CBU_GetMaintenanceParameterRequest (
    const uint8_t buffer [] ,
    uint8_t * reqType ,
    uint16_t * id ,
    uint32_t * value ) ;
       /* FILE_CBU_MAINTENANCE_H */
 
#endif /*00 C:\Users\jbtalvande\Documents\Tronico\Team-Power\01_Projet\02_MTU\02-Code\01_MCU\50073-50147DC333-SW001\trunk\LDRA\LDRA_Files\CBUmaint.h*/
/*   CLOSE_FILE Include File */
 
/* OPEN FILE C:\Users\jbtalvande\Documents\Tronico\Team-Power\01_Projet\02_MTU\02-Code\01_MCU\50073-50147DC333-SW001\trunk\LDRA\LDRA_Files\COM.h */
/*!
 * \file COM.h
 * \brief Brief description of file content
 *
 * TRONICO
 * 26, rue du bocage
 * 85660 St Philbert De Bouaine
 **/
#ifndef FILE_COM_H
#define FILE_COM_H
/* ---- Includes ---- */
/* OPEN FILE C:\Users\jbtalvande\Documents\Tronico\Team-Power\01_Projet\02_MTU\02-Code\01_MCU\50073-50147DC333-SW001\trunk\LDRA\LDRA_Files\COMrx.h */
/*!
 * \file COM_Rx.h
 * \brief Brief description of file content
 *
 * TRONICO
 * 26, rue du bocage
 * 85660 St Philbert De Bouaine
 **/
#ifndef FILE_COMRX_H
#define FILE_COMRX_H
/* ---- Includes ---- */
#include "TYPedef.h"
#include "CST.h"
/* ---- Defines ---- */
/* ---- Global variables ---- */
/* ---- Global functions ---- */
 
void
    COM_RxTask ( void ) ;
       /* FILE_COM_RX_H */
 
#endif /*00 C:\Users\jbtalvande\Documents\Tronico\Team-Power\01_Projet\02_MTU\02-Code\01_MCU\50073-50147DC333-SW001\trunk\LDRA\LDRA_Files\COMrx.h*/
/*   CLOSE_FILE Include File */
 
/* OPEN FILE C:\Users\jbtalvande\Documents\Tronico\Team-Power\01_Projet\02_MTU\02-Code\01_MCU\50073-50147DC333-SW001\trunk\LDRA\LDRA_Files\COMtx.h */
/*!
 * \file COM_Tx.h
 * \brief Brief description of file content
 *
 * TRONICO
 * 26, rue du bocage
 * 85660 St Philbert De Bouaine
 **/
#ifndef FILE_COMTX_H
#define FILE_COMTX_H
/* ---- Includes ---- */
#include "TYPedef.h"
#include "CST.h"
/* ---- Defines ---- */
/* ---- Global variables ---- */
/* ---- Global functions ---- */
 
void
    COM_TxScheduledTasks ( void ) ;
 
void
    COM_TxRequestedTasks ( void ) ;
       /* FILE_COM_TX_H */
 
#endif /*00 C:\Users\jbtalvande\Documents\Tronico\Team-Power\01_Projet\02_MTU\02-Code\01_MCU\50073-50147DC333-SW001\trunk\LDRA\LDRA_Files\COMtx.h*/
/*   CLOSE_FILE Include File */
 
#include "TYPedef.h"
#include "CST.h"
/* OPEN FILE C:\Users\jbtalvande\Documents\Tronico\Team-Power\01_Projet\02_MTU\02-Code\01_MCU\50073-50147DC333-SW001\trunk\LDRA\LDRA_Files\FSM.h */
/*!
 * \file FSM.h
 * \brief Brief description of file content
 *
 * TRONICO
 * 26, rue du bocage
 * 85660 St Philbert De Bouaine
 **/
#ifndef FILE_FSM_H
#define FILE_FSM_H
/* ---- Includes ---- */
#include "TYPedef.h"
#include "CST.h"
/* ---- Defines ---- */
 
typedef
    enum
    {
        FSM_MODE_INIT = 0 ,
        FSM_MODE_PBIT = 1 ,
        FSM_MODE_STANDBY = 2 ,
        FSM_MODE_BOOST = 3 ,
        FSM_MODE_BUCK = 4 ,
        FSM_MODE_SHUTDOWN = 5 ,
        FSM_MODE_EMERGENCY = 6 ,
        FSM_MODE_MAINTENANCE = 7
    } FSM_ModesE ;
 
typedef
    struct
    {
        boolean EnterMaintModeNotMet : 1 ;
        boolean bbAuxInMaintMode : 1 ;
        boolean autonomousBuckEnd : 1 ;
        boolean autonomousBoostEnd : 1 ;
        boolean failedPbit : 1 ;
    } FSM_ErrorsStr ;
    /* ---- Global variables ---- */
 
extern FSM_ModesE
    FSM_mode ;
 
extern FSM_ErrorsStr
    FSM_errors ;
    /* ---- Global functions ---- */
 
void
    FSM_Init ( void ) ;
 
void
    FSM_Deinit ( void ) ;
       /* FILE_FSM_H */
 
#endif /*00 C:\Users\jbtalvande\Documents\Tronico\Team-Power\01_Projet\02_MTU\02-Code\01_MCU\50073-50147DC333-SW001\trunk\LDRA\LDRA_Files\FSM.h*/
/*   CLOSE_FILE Include File */
 
/* ---- Defines ---- */
#define COM_TX_PERIODICITY 10
 
typedef
    enum
    {
        COM_FRAME_DIR_RX = 0 ,
        COM_FRAME_DIR_TX
    } COM_FrameDirE ;
/**
 * \brief Classes of groups of Control Tx frames
 */
 
typedef
    enum
    {
        COM_FRAME_GROUP_NONE = 0 ,
                              /// Default value
        COM_FRAME_GROUP_PWR_MEAS ,
                              /// Power Measure Frames
        COM_FRAME_GROUP_TEMP_MEAS ,
                               /// Temperature Measure Frames
        COM_FRAME_GROUP_COMETI_1 ,
                              /// COMETI 1 control frames
        COM_FRAME_GROUP_COMETI_2 ,
                              /// COMETI 2 control frames
        COM_FRAME_GROUP_ALERT ,
                           /// Alerts Frames
        COM_FRAME_GROUP_STATUS ,
                            /// Status Frames
        COM_FRAME_GROUP_COUNT
    } COM_FrameGroupE ;
/**
 * \brief Classes of groups of Control Tx frames
 */
 
typedef
    enum
    {
        COM_INTERNAL_FRAME_GROUP_NONE = 0 ,
                                       /// Default value
        COM_INTERNAL_FRAME_GROUP_CMD ,
                                  /// Power Measure Frames
        COM_INTERNAL_FRAME_GROUP_CNTRL ,
                                    /// Temperature Measure Frames
        COM_INTERNAL_FRAME_GROUP_COUNT
    } COM_InternalFrameGroupE ;
 
typedef
    enum
    {
        COM_PAR_REQ_NOACTION = 0 ,
        COM_PAR_REQ_READ = 1 ,
        COM_PAR_REQ_UPDATE = 2 ,
        COM_PAR_REQ_SAVE = 3
    } COM_ParReqTypeE ;
 
typedef
    enum
    {
        COM_DBG_REQ_NOACTION = 0 ,
        COM_DBG_REQ_RELAYSWITCH = 1 ,
        COM_DBG_REQ_HVMEASURES = 2 ,
        COM_DBG_REQ_LVMEASURES = 3 ,
        COM_DBG_REQ_DISCRETEIOS = 4 ,
        COM_DBG_REQ_LEDS = 5
    } COM_DebugTestReqTypeE ;
 
typedef
    enum
    {
        COM_DBG_RELAYSWITCHCMD_NONE = 0 ,
        COM_DBG_RELAYSWITCHCMD_OPEN = 1 ,
        COM_DBG_RELAYSWITCHCMD_CLOSE = 2 ,
        COM_DBG_RELAYSWITCHCMD_READ = 3
    } COM_DebugRelaySwitchCmdTypeE ;
 
typedef
    enum
    {
        COM_DBG_RELAYSWITCHID_NONE = 0 ,
        COM_DBG_RELAYSWITCHID_S1 = 1 ,
        COM_DBG_RELAYSWITCHID_S2 = 2 ,
        COM_DBG_RELAYSWITCHID_S3 = 3
    } COM_DebugRelaySwitchIdTypeE ;
 
typedef
    enum
    {
        COM_DBG_RELAYSWITCHRES_NONE = 0 ,
        COM_DBG_RELAYSWITCHRES_OPENED = 1 ,
        COM_DBG_RELAYSWITCHRES_CLOSED = 2
    } COM_DebugRelaySwitchResultTypeE ;
 
typedef
    enum
    {
        COM_DBG_MEASFORMAT_RAW = 0 ,
        COM_DBG_MEASFORMAT_HMI = 1
    } COM_DebugMeasuresFormatTypeE ;
 
typedef
    enum
    {
        COM_DBG_DSIOCMD_NONE = 0 ,
        COM_DBG_DSIOCMD_SET = 1 ,
        COM_DBG_DSIOCMD_UNSET = 2 ,
        COM_DBG_DSIOCMD_READ = 3 ,
        COM_DBG_DSIOCMD_TEST = 4 ,
        COM_DBG_DSIOCMD_STOPTEST = 5
    } COM_DebugDsioCmdTypeE ;
 
typedef
    enum
    {
        COM_DBG_DSIOID_NONE = 0 ,
        COM_DBG_DSIOID_DSI_HPP1 = 1 ,
        COM_DBG_DSIOID_DSI_HPP2 = 2 ,
        COM_DBG_DSIOID_DSI_SPARE1 = 3 ,
        COM_DBG_DSIOID_DSI_EMERSTOP = 4 ,
        COM_DBG_DSIOID_DSI_SPARE2 = 5 ,
        COM_DBG_DSIOID_DSI_SPAREINT = 6 ,
        COM_DBG_DSIOID_DSI_MAINT = 7 ,
        COM_DBG_DSIOID_DSO_HEALTH = 8 ,
        COM_DBG_DSIOID_DSO_SPARE28VINT = 9 ,
        COM_DBG_DSIOID_DSO_SPARE1 = 10 ,
        COM_DBG_DSIOID_DSO_SPAREINT = 11
    } COM_DebugDsioIdTypeE ;
 
typedef
    enum
    {
        COM_DBG_DSIORES_NONE = 0 ,
        COM_DBG_DSIORES_OPENEDOK = 1 ,
        COM_DBG_DSIORES_CLOSEDFAILED = 2
    } COM_DebugDsioResultTypeE ;
 
typedef
    enum
    {
        COM_DBG_LEDCMD_NONE = 0 ,
        COM_DBG_LEDCMD_ON = 1 ,
        COM_DBG_LEDCMD_OFF = 2 ,
        COM_DBG_LEDCMD_BLINK = 3
    } COM_DebugLedCmdTypeE ;
 
typedef
    enum
    {
        COM_DBG_LEDID_NONE = 0 ,
        COM_DBG_LEDID_LED1 = 1 ,
        COM_DBG_LEDID_LED2 = 2 ,
        COM_DBG_LEDID_LED3 = 3
    } COM_DebugLedIdTypeE ;
 
typedef
    enum
    {
        COM_DBG_LEDCOLOR_GREEN = 0 ,
        COM_DBG_LEDCOLOR_RED = 1
    } COM_DebugLedColorTypeE ;
 
typedef
    enum
    {
        COM_FRAME_CONTROL_TX_CURRENTMEAS = 0 ,
        COM_FRAME_CONTROL_TX_POWERMEAS ,
        COM_FRAME_CONTROL_TX_TEMPERATUREMEAS ,
        COM_FRAME_CONTROL_TX_VOLTAGEMEAS ,
        COM_FRAME_CONTROL_TX_CONTROLSTATUS ,
        COM_FRAME_CONTROL_TX_ERRORSWARNINGS ,
        COM_FRAME_CONTROL_TX_PBITRESULTS ,
        COM_FRAME_CONTROL_RX_PTCUCMDS ,
        COM_FRAME_CONTROL_RX_ERRORRESETREQ ,
        COM_FRAMES_CONTROL_COUNT
    } COM_FramesControlNameE ;
 
typedef
    enum
    {
        COM_FRAME_INTERNAL_TX_CONTROLREQCOMETI1 = 0 ,
        COM_FRAME_INTERNAL_TX_MODEREQCOMETI1 ,
        COM_FRAME_INTERNAL_TX_CONTROLREQCOMETI2 ,
        COM_FRAME_INTERNAL_TX_MODEREQCOMETI2 ,
        COM_FRAME_INTERNAL_TX_ERRORRESETREQCOMETI1 ,
        COM_FRAME_INTERNAL_TX_ERRORRESETREQCOMETI2 ,
        COM_FRAME_INTERNAL_RX_CURRENTMEAS ,
        COM_FRAME_INTERNAL_RX_CURRENTMEASTEMP ,
        COM_FRAME_INTERNAL_RX_POWERMEAS ,
        COM_FRAME_INTERNAL_RX_TEMPERATUREMEAS ,
        COM_FRAME_INTERNAL_RX_VOLTAGEMEAS ,
        COM_FRAME_INTERNAL_RX_REGULATIONINFO ,
        COM_FRAME_INTERNAL_RX_CONTROLINFO ,
        COM_FRAME_INTERNAL_RX_ERRORS ,
        COM_FRAME_INTERNAL_RX_WARNINGS ,
        COM_FRAMES_INTERNAL_COUNT
    } COM_FramesInternalNameE ;
 
typedef
    enum
    {
        COM_FRAME_MAINTENANCE_TX_EQUIPTESTRESP = 0 ,
        COM_FRAME_MAINTENANCE_TX_PARAMETERRESP ,
        COM_FRAME_MAINTENANCE_RX_EQUIPTESTREQ ,
        COM_FRAME_MAINTENANCE_RX_PARAMETERREQ ,
        COM_FRAMES_MAINTENANCE_COUNT
    } COM_FramesMaintenanceNameE ;
 
typedef
    struct
    {
        uint32_t id ;
                 // Frame ID
        COM_FrameDirE dir ;
                       // TX/RX
        COM_FrameGroupE group ;
                           // group for TX frames
        uint32_t offset ;
                     // Delay in ms for TX frames
        uint32_t FrameLenght ;
                          // Frame lenght
    } COM_FrameStr ;
    /* All COM module fault flags */
 
typedef
    struct
    {
        boolean moduleUninitialized : 1 ;
        boolean middlewareUninitialized : 1 ;
        boolean canCUninitialized : 1 ;
        boolean canIUninitialized : 1 ;
        boolean canMUninitialized : 1 ;
        boolean pbitFault : 1 ;
        boolean canCComLoss : 1 ;
        boolean canIComLoss : 1 ;
        boolean unkownCOMETi : 1 ;
        uint16_t reserved : 7 ;
    } COM_FaultFlagsStr ;
    /* Union to read all fault flags as an uint16_t */
 
typedef
    union
    {
        COM_FaultFlagsStr flags ;
        uint16_t all ;
    } COM_FaultFlagsU ;
    /* All COM module status flags */
 
typedef
    struct
    {
        boolean moduleInitialized : 1 ;
        boolean middlewareInitialized : 1 ;
        boolean canCInitialized : 1 ;
        boolean canIInitialized : 1 ;
        boolean canMInitialized : 1 ;
        boolean pbitOk : 1 ;
        boolean powerRequest : 1 ;
        boolean settingRequestEnter : 1 ;
        boolean settingRequestExit : 1 ;
        boolean maintenanceRequestEnter : 1 ;
        boolean maintenanceRequestExit : 1 ;
        boolean errorResetRequest : 1 ;
        boolean boostRequest : 1 ;
        boolean buckRequest : 1 ;
        boolean stopRequest : 1 ;
        boolean shutDownReq : 1 ;
        uint16_t reserved : 5 ;
    } COM_StatusFlagsStr ;
    /* Union to read all status flags as an uint16_t */
 
typedef
    union
    {
        COM_StatusFlagsStr flags ;
        uint16_t all ;
    } COM_StatusFlagsU ;
    /* Flag structure */
 
typedef
    struct
    {
        COM_FaultFlagsU faults ;
        COM_StatusFlagsU status ;
    } COM_FlagsStr ;
    /* Union to read all flags as an uint32_t */
 
typedef
    union
    {
        COM_FlagsStr moduleFlags ;
        uint32_t all ;
    } COM_FlagsU ;
    /* All COM module status flags related to Parameter management */
 
typedef
    struct
    {
        boolean readRequest : 1 ;
        boolean changeRequest : 1 ;
        boolean saveRequest : 1 ;
        uint16_t reserved : 13 ;
        uint16_t index ;
        uint32_t value ;
    } COM_ParamRequestStr ;
    /* All COM module status flags related to Debug/Test management */
 
typedef
    struct
    {
        boolean relaySwitchTestRequest : 1 ;
        boolean hvMeasuresTestRequest : 1 ;
        boolean lvMeasuresTestRequest : 1 ;
        boolean discreteIosTestRequest : 1 ;
        boolean ledsTestRequest : 1 ;
        uint32_t reserved : 27 ;
        uint8_t muxAddress ;
        uint8_t measFormat ;
        uint8_t relaySwitchCmd ;
        uint8_t relaySwitchId ;
        uint8_t discreteIoCmd ;
        uint8_t discreteIoId ;
        uint8_t ledCmd ;
        uint8_t ledId ;
        uint8_t ledColor ;
        uint8_t ledBlinkFreq ;
        uint8_t relaySwitchResult ;
        uint8_t discreteIosReadResult ;
        uint8_t discreteIosPWMResult ;
        uint32_t rawMeasure ;
        uint32_t hmiMeasure ;
    } COM_DebugTestRequestStr ;
 
typedef
    enum
    {
        COM_SEVERITY_NONE = 0 ,
        COM_SEVERITY_WARNING = 1 ,
        COM_SEVERITY_OPERATING = 2 ,
        COM_SEVERITY_CRITICAL = 3
    } COM_SeverityTypeE ;
    /* Faults structure */
 
typedef
    struct
    {
        uint16_t bbauxErrors ;
        uint16_t bbauxWarnings ;
        uint16_t powercoreErrors ;
        uint8_t powercoreWarnings ;
        COM_SeverityTypeE severity ;
        uint32_t faultOrigin ;
        boolean hasNewValuesErr : 1 ;
        boolean hasNewValuesWarn : 1 ;
        uint32_t reserved : 30 ;
    } COM_ErrorsAndWarningsStr ;
    /* Power measures structure */
 
typedef
    struct
    {
        uint16_t uBusHv ;
        uint16_t uBusLv ;
        uint16_t uBusHvAux ;
        uint16_t iBusHv ;
        uint16_t iBusLv ;
        uint16_t reserved : 16 ;
        uint32_t pBusHv ;
        uint32_t pBusLv ;
    } COM_PowerMeasurementsStr ;
 
typedef
    enum
    {
        COM_TEMPNOTIF_NOMINAL = 0 ,
        COM_TEMPNOTIF_GENTLEWARN = 1 ,
        COM_TEMPNOTIF_URGENTWARN = 2 ,
        COM_TEMPNOTIF_CRITICALTEMP = 3
    } COM_TempNotificationTypeE ;
    /* Temperature measures structure */
 
typedef
    struct
    {
        int8_t tempHvCoupler ;
        int8_t temp1Cometi ;
        int8_t temp2Cometi ;
        COM_TempNotificationTypeE tempNotif ;
    } COM_TempMeasurementsStr ;
 
typedef
    enum
    {
        COM_LIMITATIONTYPE_NOLIMITATION = 0U ,
        COM_LIMITATIONTYPE_TEMPERATURELIMITATION = 1U ,
        COM_LIMITATIONTYPE_POWERLIMITATION = 2U
    } COM_LimitationTypeValuesE ;
 
typedef
    enum
    {
        COM_RELAYSTATUS_OPEN = 0U ,
        COM_RELAYSTATUS_CLOSED = 1U
    } COM_RelayStatusValuesE ;
 
typedef
    enum
    {
        COM_BUCKTYPE_NOINBUCK = 0U ,
        COM_BUCKTYPE_CURRENTSOURCE = 1U ,
        COM_BUCKTYPE_VOLTAGEREGULATION = 2U
    } COM_BuckTypeValuesE ;
    /* Control Status info structure */
 
typedef
    struct
    {
        uint32_t setpoint ;
        uint16_t currentLimit ;
        FSM_ModesE dcdcState ;
        COM_LimitationTypeValuesE limitationType ;
        COM_RelayStatusValuesE lvPrechargeStatus ;
        COM_RelayStatusValuesE hvCouplerStatus1 ;
        COM_BuckTypeValuesE buckType ;
        uint8_t powercoreUnitsNb ;
        boolean emerstopStatus ;
        boolean healthStatus ;
        boolean hasNewValues ;
    } COM_ControlStatusInfoStr ;
 
typedef
    enum
    {
        COM_PBITSTATUS_NOTEXECUTED = 0U ,
        COM_PBITSTATUS_INPROGRESS = 1U ,
        COM_PBITSTATUS_PASS = 2U ,
        COM_PBITSTATUS_FAIL = 3U
    } COM_PbitStatusValuesE ;
 
typedef
    enum
    {
        COM_RELAYPBITSTATUS_NOTTESTED = 0U ,
        COM_RELAYPBITSTATUS_PASS = 1U ,
        COM_RELAYPBITSTATUS_FAIL = 2U
    } COM_RelayPbitStatusValuesE ;
    /* Pbit Results info structure */
 
typedef
    struct
    {
        uint32_t softwareVersion ;
        COM_PbitStatusValuesE pbitStatus ;
        COM_RelayPbitStatusValuesE lvPrechargeStatus ;
        COM_RelayPbitStatusValuesE hvCouplerStatus ;
        uint8_t dsioStatus ;
    } COM_PbitResultsInfoStr ;
 
typedef
    enum
    {
        COM_BBAUXCMD_NONE = 0 ,
        COM_BBAUXCMD_BOOST = 1 ,
        COM_BBAUXCMD_BUCK = 2 ,
        COM_BBAUXCMD_STOP = 3 ,
        COM_BBAUXCMD_SHUTDOWN = 4
    } COM_BbauxCmdTypeE ;
/**
 * \brief Rx data to send to ACT module
 */
 
typedef
    struct
    {
        COM_BbauxCmdTypeE bbauxCommand ;
    /// Regulation mode / way
        uint8_t mainMode ;
    /// Regulation Type
        uint8_t regType ;
    /// Setpoint
        uint32_t setpoint ;
    /// Limite en courant - pour mode regulation en tension avec limite en courant
        uint16_t currentLimit ;
    /// True if one of the limitation is active
        boolean limitationActive ;
    /// Type of the limitation :
        uint8_t limitationType ;
    /// Start order
        boolean startOrder ;
        boolean startOrderValid ;
    } COM_BbauxModeStr ;
/**
 * \brief Error masks
 */
 
typedef
    struct
    {
        uint32_t error1Mask ;
        uint32_t error2Mask ;
    } COM_ErrorMaskStr ;
    /* ---- Global variables ---- */
 
extern COM_FlagsU
    COM_flags ;
 
extern uint8_t
    COM_Address ;
 
extern COM_ErrorsAndWarningsStr
    COM_errorsAndWarnings ;
 
extern COM_PowerMeasurementsStr
    COM_powerMeasures ;
 
extern COM_TempMeasurementsStr
    COM_tempMeasures ;
 
extern COM_ControlStatusInfoStr
    COM_controlStatusInfo ;
 
extern COM_PbitResultsInfoStr
    COM_pbitResultsInfo ;
 
extern COM_FrameStr COM_framesControl [ COM_FRAMES_CONTROL_COUNT ] ;
 
extern COM_FrameStr COM_framesInternal [ COM_FRAMES_INTERNAL_COUNT ] ;
 
extern COM_FrameStr COM_framesMaintenance [ COM_FRAMES_MAINTENANCE_COUNT ] ;
 
extern uint32_t
    COM_controlComLostCounter ;
 
extern uint32_t
    COM_internalComLostCounter ;
 
extern COM_BbauxModeStr
    COM_mode ;
 
extern COM_ParamRequestStr
    COM_paramReq ;
 
extern COM_DebugTestRequestStr
    COM_debugTestReq ;
 
extern COM_ErrorMaskStr
    COM_errorMasks ;
 
extern uint32_t
    COM_txDelayCounterControl [ COM_FRAME_GROUP_COUNT ] ;
 
extern uint32_t
    COM_txDelayCounterInternal [ COM_FRAME_GROUP_COUNT ] ;
 
extern uint32_t
    COM_txPeriodControl [ COM_FRAME_GROUP_COUNT ] ;
 
extern uint32_t
    COM_txPeriodInternal [ COM_FRAME_GROUP_COUNT ] ;
    /* ---- Global functions ---- */
 
void
    COM_Init ( void ) ;
 
void
    COM_Deinit ( void ) ;
 
void
    COM_UpdatePeriodParams ( void ) ;
       /* FILE_COM_H */
 
#endif /*00 C:\Users\jbtalvande\Documents\Tronico\Team-Power\01_Projet\02_MTU\02-Code\01_MCU\50073-50147DC333-SW001\trunk\LDRA\LDRA_Files\COM.h*/
/*   CLOSE_FILE Include File */
 
/* OPEN FILE C:\Users\jbtalvande\Documents\Tronico\Team-Power\01_Projet\02_MTU\02-Code\01_MCU\50073-50147DC333-SW001\trunk\LDRA\LDRA_Files\CBUs.h */
/*!
 * \file CBUs.h
 * \brief CAN Bus middleware header
 *
 * TRONICO
 * 26, rue du bocage
 * 85660 St Philbert De Bouaine
 **/
#ifndef FILE_CBUS_H
#define FILE_CBUS_H
/* ---- Includes ---- */
#include "TYPedef.h"
#include "CST.h"
/* OPEN FILE C:\Users\jbtalvande\Documents\Tronico\Team-Power\01_Projet\02_MTU\02-Code\01_MCU\50073-50147DC333-SW001\trunk\LDRA\LDRA_Files\CBUctrl.h */
/*!
 * \file CBU_Control.h
 * \brief Control CAN Bus middleware header
 *
 * TRONICO
 * 26, rue du bocage
 * 85660 St Philbert De Bouaine
 **/
#ifndef FILE_CBUCTRL_H
#define FILE_CBUCTRL_H
/* ---- Includes ---- */
#include "CST.h"
#include "TYPedef.h"
/* ---- Defines ---- */
/* ---- Global variables ---- */
/* ---- Global functions ---- */
/* -- TX -- */
 
void
    CBU_SendControlCurrentMeasuresFrame ( void ) ;
 
void
    CBU_SendControlPowerMeasuresFrame ( void ) ;
 
void
    CBU_SendControlTemperatureMeasuresFrame ( void ) ;
 
void
    CBU_SendControlVoltageMeasuresFrame ( void ) ;
 
void
    CBU_SendControlControlStatusFrame ( void ) ;
 
void
    CBU_SendControlErrorsWarningsFrame ( void ) ;
 
void
    CBU_SendControlPbitResultsFrame ( void ) ;
    /* -- RX -- */
 
void
    CBU_GetControlPtcuCmdsFrameData (
    const uint8_t buffer [] ,
    uint8_t * bbauxCommand ) ;
       /* FILE_CBU_CONTROL_H */
 
#endif /*00 C:\Users\jbtalvande\Documents\Tronico\Team-Power\01_Projet\02_MTU\02-Code\01_MCU\50073-50147DC333-SW001\trunk\LDRA\LDRA_Files\CBUctrl.h*/
/*   CLOSE_FILE Include File */
 
/* OPEN FILE C:\Users\jbtalvande\Documents\Tronico\Team-Power\01_Projet\02_MTU\02-Code\01_MCU\50073-50147DC333-SW001\trunk\LDRA\LDRA_Files\CBUinter.h */
/*!
 * \file CBU_Internal.h
 * \brief Secondary CAN Bus middleware header
 *
 * TRONICO
 * 26, rue du bocage
 * 85660 St Philbert De Bouaine
 **/
#ifndef FILE_CBUINTER_H
#define FILE_CBUINTER_H
/* ---- Includes ---- */
#include "CST.h"
#include "TYPedef.h"
/* ---- Defines ---- */
/* ---- Global variables ---- */
/* ---- Global functions ---- */
/* -- TX -- */
 
void
    CBU_SendInternalControlRequestFrameCOMETi1 ( void ) ;
 
void
    CBU_SendInternalControlRequestFrameCOMETi2 ( void ) ;
 
void
    CBU_SendInternalModeRequestFrameCOMETi1 ( void ) ;
 
void
    CBU_SendInternalModeRequestFrameCOMETi2 ( void ) ;
 
void
    CBU_SendInternalErrorResetRequestFrameCOMETi1 ( void ) ;
 
void
    CBU_SendInternalErrorResetRequestFrameCOMETi2 ( void ) ;
    /* -- RX -- */
 
void
    CBU_GetInternalCurrentMeasuresFrameData (
    const uint8_t buffer [] ,
    uint16_t * iBus1 ,
    uint16_t * iBus2 ) ;
 
void
    CBU_GetInternalPowerMeasuresFrameData (
    const uint8_t buffer [] ,
    uint32_t * pBus1 ,
    uint32_t * pBus2 ) ;
 
void
    CBU_GetInternalTemperatureMeasuresFrameData (
    const uint8_t buffer [] ,
    uint8_t * temp1 ,
    uint8_t * temp2 ,
    uint8_t * temp3 ,
    uint8_t * temp4 ,
    uint8_t * temp5 ,
    uint8_t * temp6 ,
    uint8_t * temp7 ,
    uint8_t * temp8 ) ;
 
void
    CBU_GetInternalVoltageMeasuresFrameData (
    const uint8_t buffer [] ,
    uint16_t * vBus1 ,
    uint16_t * vBus2 ) ;
 
void
    CBU_GetInternalRegulationInfoFrameData (
    const uint8_t buffer [] ,
    uint8_t * softwareMode ,
    uint32_t * setpoint ,
    uint8_t * limitationType ) ;
 
void
    CBU_GetInternalControlInfoFrameData (
    const uint8_t buffer [] ,
    uint8_t * regMode ,
    uint8_t * regType ,
    uint16_t * currentLimit ) ;
 
void
    CBU_GetInternalErrorsFrameData (
    const uint8_t buffer [] ,
    uint32_t * criticalErrors ,
    uint32_t * functionnalErrors ) ;
 
void
    CBU_GetInternalWarningsFrameData (
    const uint8_t buffer [] ,
    uint32_t * warnings ) ;
       /* FILE CBU_INTERNAL_H */
 
#endif /*00 C:\Users\jbtalvande\Documents\Tronico\Team-Power\01_Projet\02_MTU\02-Code\01_MCU\50073-50147DC333-SW001\trunk\LDRA\LDRA_Files\CBUinter.h*/
/*   CLOSE_FILE Include File */
 
#include "CBUmaint.h"
#include "Can.h"
#include "CanIf.h"
/* OPEN FILE C:\Users\jbtalvande\Documents\Tronico\Team-Power\01_Projet\02_MTU\02-Code\01_MCU\50073-50147DC333-SW001\trunk\LDRA\LDRA_Files\CNV.h */
/*!
 * \file CNV.h
 * \brief Brief description of file content
 *
 * TRONICO
 * 26, rue du bocage
 * 85660 St Philbert De Bouaine
 **/
#ifndef FILE_CNV_H
#define FILE_CNV_H
/* ---- Includes ---- */
#include "TYPedef.h"
#include "CST.h"
/* ---- Defines ---- */
#define CNV_POWERCORE_UNITS_NB 2U
 
typedef
    enum
    {
        CNV_SOFTWAREMODE_EMERGENCY = 0 ,
        CNV_SOFTWAREMODE_STANDBY = 1 ,
        CNV_SOFTWAREMODE_RUNNING = 2 ,
        CNV_SOFTWAREMODE_POWERDOWN = 3 ,
        CNV_SOFTWAREMODE_SETTINGS = 4 ,
                                   // impossible in BB-AUX case
        CNV_SOFTWAREMODE_MAINTENANCE = 5 ,
                                      // impossible in BB-AUX case
        CNV_SOFTWAREMODE_INIT = 0xFF
    } CNV_SoftwareModesE ;
 
typedef
    enum
    {
        CNV_REGTYPE_NOT_SET = 0U ,
        CNV_REGTYPE_VBUS2 = 1U ,
        CNV_REGTYPE_VBUS1 = 2U ,
        CNV_REGTYPE_IBUS2 = 3U ,
        CNV_REGTYPE_IBUS1 = 4U ,
        CNV_REGTYPE_PBUS2 = 5U ,
        CNV_REGTYPE_PBUS1 = 6U ,
        CNV_REGTYPE_VBUS2_ILIM = 7U ,
        CNV_REGTYPE_VBUS1_ILIM = 8U ,
        CNV_REGTYPE_COUNT ,
    } CNV_RegulationTypesE ;
/// Control loop main modes
 
typedef
    enum
    {
        CNV_REGMODE_NOT_SET = 0U ,
        CNV_REGMODE_BUS1TOBUS2 = 1U ,
        CNV_REGMODE_BUS2TOBUS1 = 2U ,
        CNV_REGMODE_BIDIRECTIONAL = 3U ,
        CNV_REGMODE_COUNT
    } CNV_RegulationModesE ;
// Error Reset Request for Each COMETi
 
typedef
    enum
    {
        COMETi1_ErrorResetReq = 0U ,
        COMETi2_ErrorResetReq
    } CNV_ErrorResetRequestE ;
 
typedef
    enum
    {
        CNV_LIMITATIONTYPE_NOLIMITATION = 0U ,
        CNV_LIMITATIONTYPE_TEMPERATURELIMITATION = 1U ,
        CNV_LIMITATIONTYPE_RAMPLIMITATION = 2U ,
        CNV_LIMITATIONTYPE_POWERLIMITATION = 4U
    } CNV_LimitationTypeValuesE ;
// Types and Defines -----------------------------------------------------------
 
typedef
    struct
    {
        boolean uBus1MaxCritical : 1 ;
        boolean uBus2MaxCritical : 1 ;
        boolean iBus1Leg1MaxCritical : 1 ;
        boolean iBus1Leg2MaxCritical : 1 ;
        boolean iBus2Leg1MaxCritical : 1 ;
        boolean iBus2Leg2MaxCritical : 1 ;
        boolean parameters : 1 ;
                           // Should never happen in BB-AUX otherwise set componentInternalError
        boolean powerMap : 1 ;
                         // Should never happen in BB-AUX otherwise set componentInternalError
        boolean fpgaLost : 1 ;
        boolean mcuClockUnsync : 1 ;
        boolean fpgaClockUnsync : 1 ;
        boolean servicePowerSupplyLostMcu : 1 ;
        boolean servicePowerSupplyLostFpga : 1 ;
        boolean mosfetDriverFault : 1 ;
        boolean inoperationalCurrentSensor : 1 ;
        boolean inoperationalVoltageSensor : 1 ;
        boolean uBusAuxMaxCritical : 1 ;
                                   // new added error
        unsigned int reserved : 15 ;
    } CNV_CometiCriticalErrorStr ;
                              // COMETI Fast PowerDown Errors
 
typedef
    union
    {
        CNV_CometiCriticalErrorStr flags ;
        uint32_t value ;
    } CNV_CometiCriticalErrorU ;
 
typedef
    struct
    {
        boolean uBus1Min : 1 ;
        boolean uBus1Max : 1 ;
        boolean uBus2Min : 1 ;
        boolean uBus2Max : 1 ;
        boolean iBus1Leg1Max : 1 ;
        boolean iBus1Leg2Max : 1 ;
        boolean iBus2Leg1Max : 1 ;
        boolean iBus2Leg2Max : 1 ;
        boolean outCoolantTempMinCritical : 1 ;
        boolean outCoolantTempMaxCritical : 1 ;
        boolean inCoolantTempMinCritical : 1 ;
        boolean inCoolantTempMaxCritical : 1 ;
        boolean ambientTempMinCritical : 1 ;
        boolean ambientTempMaxCritical : 1 ;
        boolean mosfetTempMaxCritical : 1 ;
        boolean transformerTempMaxCritical : 1 ;
        boolean selfTempMaxCritical : 1 ;
        boolean coolantDeltaTempMaxCritical : 1 ;
        boolean comIsLost : 1 ;
                          // Should never happen in BB-AUX otherwise set componentInternalError
        boolean unknownControlMode : 1 ;
                                   // Should never happen in BB-AUX otherwise set componentInternalError
        boolean unknownControlType : 1 ;
                                   // Should never happen in BB-AUX otherwise set componentInternalError
        boolean incompatibleCtrlModeType : 1 ;
                                         // Should never happen in BB-AUX otherwise set componentInternalError
        boolean controlLoopNotSet : 1 ;
                                  // Should never happen in BB-AUX otherwise set componentInternalError
        boolean powerLimitReached : 1 ;
                                  // Should never happen in BB-AUX otherwise set componentInternalError
        boolean inoperationalTemperatureSensor : 1 ;
                                               // Should never happen in BB-AUX otherwise set componentInternalError
        unsigned int reserved : 7 ;
    } CNV_CometiFunctionalErrorStr ;
                                // COMETI Slow PowerDown Errors
 
typedef
    union
    {
        CNV_CometiFunctionalErrorStr flags ;
        uint32_t value ;
    } CNV_CometiFunctionalErrorU ;
 
typedef
    struct
    {
        boolean highOutCoolantTemp : 1 ;
        boolean highInCoolantTemp : 1 ;
        boolean highAmbientTemp : 1 ;
        boolean highMosfetTemp : 1 ;
        boolean highTransformerTemp : 1 ;
        boolean highSelfTemp : 1 ;
        boolean highCoolantDeltaTemp : 1 ;
        boolean setPointUnreachableTooLow : 1 ;
                                          // Should never happen in BB-AUX otherwise set componentSwWarning
        boolean setPointUnreachableTooHigh : 1 ;
                                           // Should never happen in BB-AUX otherwise set componentSwWarning
        boolean controlTypeChangeNotAllowed : 1 ;
                                            // Should never happen in BB-AUX otherwise set componentSwWarning
        boolean backupApplicationStarted : 1 ;
        boolean backupParametersLoaded : 1 ;
        unsigned int reserved : 20 ;
    } CNV_CometiWarningStr ;
 
typedef
    union
    {
        CNV_CometiWarningStr flags ;
        uint32_t value ;
    } CNV_CometiWarningU ;
/// Errors of the CNV Manager Library
 
typedef
    enum
    {
    /// No error **MUST** be 0
        CNV_ERROR_NO_ERROR = 0U ,
    /// The count of errors
        CNV_ERROR_COUNT
    } CNV_ErrorsE ;
    /* Error flags of CNV module */
 
typedef
    struct
    {
        boolean uBusHvMin : 1 ;
        boolean uBusLvMin : 1 ;
        boolean uBusHvMax : 1 ;
        boolean uBusLvMax : 1 ;
        boolean iBusHvMax : 1 ;
        boolean iBusLvMax : 1 ;
        boolean outCoolantTempCritical : 1 ;
        boolean inCoolantTempCritical : 1 ;
        boolean ambientTempCritical : 1 ;
        boolean otherTempCritical : 1 ;
        boolean coolantDeltaTempCritical : 1 ;
        boolean uBusHvMaxCritical : 1 ;
        boolean uBusLvMaxCritical : 1 ;
        boolean iBusHvMaxCritical : 1 ;
        boolean iBusLvMaxCritical : 1 ;
        boolean componentInternalError : 1 ;
    } CNV_FaultFlagsStr ;
                     // Powercore Errors retained
/* Warning flags of CNV module */
 
typedef
    struct
    {
        boolean outCoolantTemp : 1 ;
        boolean inCoolantTemp : 1 ;
        boolean ambientTemp : 1 ;
        boolean mosfetTemp : 1 ;
        boolean transformerTemp : 1 ;
        boolean selfTemp : 1 ;
        boolean coolantDeltaTemp : 1 ;
        boolean componentSwWarn : 1 ;
    } CNV_WarnFlagsStr ;
                    // Powercore Warnings retained
/* Status flags of CNV module */
 
typedef
    struct
    {
        boolean moduleInitialized : 1 ;
        boolean comLost : 1 ;
        boolean hasNewValuesErr : 1 ;
                                // useful ?
        boolean hasNewValuesWarn : 1 ;
                                 // useful ?
        uint8_t reserved : 6 ;
    } CNV_StatusFlagsStr ;
    /* Flag unions to be able to check them in one instruction */
 
typedef
    union
    {
        CNV_FaultFlagsStr flags ;
        uint16_t all ;
    } CNV_FaultFlagsU ;
 
typedef
    union
    {
        CNV_WarnFlagsStr flags ;
        uint8_t all ;
    } CNV_WarnFlagsU ;
 
typedef
    union
    {
        CNV_StatusFlagsStr flags ;
        uint8_t all ;
    } CNV_StatusFlagsU ;
    /* Structure to unite Errors, Warnings and Status regs */
 
typedef
    struct
    {
        CNV_FaultFlagsU faults ;
        CNV_WarnFlagsU warns ;
        CNV_StatusFlagsU status ;
    } CNV_FlagsStr ;
    /* Flag structures union to be able to check them in one instruction */
 
typedef
    union
    {
        CNV_FlagsStr moduleFlags ;
        uint32_t all ;
    } CNV_FlagsU ;
    /* Power measures structure */
 
typedef
    struct
    {
        uint16_t vBus1 ;
        uint16_t vBus2 ;
        uint16_t iBus1 ;
        uint16_t iBus2 ;
        uint32_t pBus1 ;
        uint32_t pBus2 ;
    } CNV_PowerMeasurementsStr ;
    /* Temp measures structure */
 
typedef
    struct
    {
        uint8_t temp1 ;
                   // Transformer1
        uint8_t temp2 ;
                   // Transformer2
        uint8_t temp3 ;
                   // SelfBoost1
        uint8_t temp4 ;
                   // SelfBoost2
        uint8_t temp5 ;
                   // SelfPSFB1
        uint8_t temp6 ;
                   // SelfPSFB2
        uint8_t temp7 ;
                   // MosfetBoost1
        uint8_t temp8 ;
                   // MosfetBoost2
    } CNV_TempMeasurementsStr ;
/* Regulation info structure */ // Regrouper CNV_RegulationInfoStr et CNV_ControlInfoStr ???
 
typedef
    struct
    {
        CNV_SoftwareModesE softMode ;
        uint32_t setpoint ;
        CNV_LimitationTypeValuesE limitationType ;
        boolean hasNewValues ;
                          // useful ?
    } CNV_RegulationInfoStr ;
    /* Control info structure */
 
typedef
    struct
    {
        CNV_RegulationModesE regMode ;
        CNV_RegulationTypesE regType ;
        uint16_t currentLimit ;
        boolean hasNewValues ;
                          // useful ?
    } CNV_ControlInfoStr ;
    /* Mode info structure */
 
typedef
    struct
    {
        CNV_RegulationModesE regMode ;
        CNV_RegulationTypesE regType ;
        uint32_t setpoint ;
        uint16_t currentLimit ;
        boolean startOrder ;
    } CNV_InternalRequestStr ;
    /* PowerCore Unit structure */
 
typedef
    struct
    {
        uint8_t address ;
        CNV_FlagsU flags ;
        uint32_t comLostCounter ;
        CNV_PowerMeasurementsStr powerMeas ;
        CNV_TempMeasurementsStr tempMeas ;
        CNV_RegulationInfoStr regulInfo ;
        CNV_ControlInfoStr controlInfo ;
        CNV_InternalRequestStr request ;
    } CNV_PowercoreUnitStr ;
    /* ---- Global variables ---- */
 
extern CNV_FlagsU
    CNV_flags ;
 
extern CNV_PowercoreUnitStr CNV_powercoreUnitTable [ 2U ] ;
/* ---- Global functions ---- */
/* -- Init -- */
 
void
    CNV_Init ( void ) ;
 
void
    CNV_Deinit ( void ) ;
    /* -- TX -- */
 
void
    CNV_ManageInternalErrorResetRequestFrame ( void ) ;
    /* -- RX -- */
 
void
    CNV_GetInternalCurrentMeasuresFrame (
    const uint8_t buffer [] ,
    uint8_t powercoreUnitIndex ) ;
 
void
    CNV_GetInternalPowerMeasuresFrame (
    const uint8_t buffer [] ,
    uint8_t powercoreUnitIndex ) ;
 
void
    CNV_GetInternalTemperatureMeasuresFrame (
    const uint8_t buffer [] ,
    uint8_t powercoreUnitIndex ) ;
 
void
    CNV_GetInternalVoltageMeasuresFrame (
    const uint8_t buffer [] ,
    uint8_t powercoreUnitIndex ) ;
 
void
    CNV_GetInternalRegulationInfoFrame (
    const uint8_t buffer [] ,
    uint8_t powercoreUnitIndex ) ;
 
void
    CNV_GetInternalControlInfoFrame (
    const uint8_t buffer [] ,
    uint8_t powercoreUnitIndex ) ;
 
void
    CNV_GetInternalErrorsFrame (
    const uint8_t buffer [] ,
    uint8_t powercoreUnitIndex ) ;
 
void
    CNV_GetInternalWarningsFrame (
    const uint8_t buffer [] ,
    uint8_t powercoreUnitIndex ) ;
    /* -- Other -- */
 
uint8_t
    CNV_getPowercoreUnitsIndex (
    uint8_t powercoreUnitAddress ) ;
 
void
    CNV_updatePowercoreUnitsComlossCounter (
    uint8_t powercoreUnitIndex ) ;
 
void
    CNV_ChangePowercoreUnitsCommand ( void ) ;
       /* FILE_CNV_H */
 
#endif /*00 C:\Users\jbtalvande\Documents\Tronico\Team-Power\01_Projet\02_MTU\02-Code\01_MCU\50073-50147DC333-SW001\trunk\LDRA\LDRA_Files\CNV.h*/
/*   CLOSE_FILE Include File */
 
/* ---- Defines ---- */
/* CAN controllers affectation */
#define CBU_CONTROLCAN CanController_Primary
#define CBU_MAINTENANCECAN CanController_Maint
#define CBU_INTERNALCAN CanController_Internal
#define CBU_NBCAN 3u
/* Macro */
#define CBU_SET_UINT16( buffer , index , value ) do { ( buffer [ index ] ) = ( uint8_t ) ( value ) ; buffer [ index + 1 ] = ( uint8_t ) ( ( value ) >> 8 ) ; } while ( 0 )
#define CBU_SET_UINT32( buffer , index , value ) do { buffer [ index ] = ( uint8_t ) ( ( value ) & 0xFF ) ; buffer [ index + 1 ] = ( uint8_t ) ( ( value >> 8 ) & 0xFF ) ; buffer [ index + 2 ] = ( uint8_t ) ( ( value >> 16 ) & 0xFF ) ; \
buffer [ index + 3 ] = ( uint8_t ) ( ( value >> 24 ) & 0xFF ) ; } while ( 0 )
#define CBU_GET_UINT16( buffer , index ) ( uint16_t ) ( ( ( uint16_t ) ( buffer ) [ index + 1 ] << 8 ) | ( uint16_t ) ( buffer ) [ index ] )
#define CBU_GET_UINT32( buffer , index ) ( uint32_t ) ( ( ( uint32_t ) buffer [ index + 3 ] << 24 ) | ( ( uint32_t ) buffer [ index + 2 ] << 16 ) | ( ( uint32_t ) buffer [ index + 1 ] << 8 ) | ( uint32_t ) buffer [ index ] )
/* Mailboxes count */
#define CBU_MAILBOXES_COUNT CAN_HWOBJECT_CONFIG_COUNT
 
typedef
    struct
    {
        boolean canCInitialized : 1 ;
        boolean canIInitialized : 1 ;
        boolean canMInitialized : 1 ;
        boolean middlewareInitialized : 1 ;
        boolean canCComLost : 1 ;
        boolean canIComLost : 1 ;
        boolean canMComLost : 1 ;
        uint8_t reserved : 1 ;
    } CBU_FlagsStr ;
 
typedef
    union
    {
        CBU_FlagsStr status ;
        uint8 all ;
    } CBU_FlagsU ;
 
typedef
    struct
    {
        uint8_t idController ;
        uint32_t frameId ;
        Can_HwObjectHandleType frameDir ;
        boolean isPending ;
        uint8_t buffer [ CST_CAN_BUFFER_SIZE ] ;
        uint32_t frameLength ;
    } CBU_FrameStatusStr ;
 
typedef
    enum
    {
    /// 500 kbps nominal, no BRS
        CBU_BR_500KBPS = 0 ,
        CBU_BR_COUNTS
    } CBU_BitRatesE ;
    /* ---- Global variables ---- */
 
extern CBU_FrameStatusStr CBU_framesStatus [ CAN_HWOBJECT_CONFIG_COUNT ] ;
 
extern CBU_FlagsU
    CBU_flags ;
 
extern uint8_t
    CBU_Address ;
 
extern uint8_t
    CBU_powerCoreAdd ;
    /* ---- Global functions ---- */
 
void
    CBU_Init (
    boolean cStart ,
    boolean iStart ,
    boolean mStart ) ;
 
void
    CBU_Deinit ( void ) ;
 
void
    CBU_CheckErrors ( void ) ;
 
void
    CBU_ClearPendingFlag (
    uint16_t mailbox ) ;
 
void
    CBU_CreatePduInfo (
    Can_IdType id ,
    PduIdType swPduHandle ,
    uint8 length ,
    uint8 * sdu ,
    Can_PduType * pduInfoPtr ) ;
 
void
    CBU_SendFrame (
    Can_PduType pdu ,
    uint8_t mailbox ) ;
 
void
    CBU_SetBitrate (
    uint8_t canPort ,
    uint16_t bitrate ,
    uint32_t finalState ) ;
 
uint8_t
    CBU_CheckLength (
    uint8_t length ) ;
       /* FILE_CBUS_H */
 
#endif /*00 C:\Users\jbtalvande\Documents\Tronico\Team-Power\01_Projet\02_MTU\02-Code\01_MCU\50073-50147DC333-SW001\trunk\LDRA\LDRA_Files\CBUs.h*/
/*   CLOSE_FILE Include File */
 
/* ---- Defines ---- */
#define BUFFER_MAX_SIZE 64U
/* ---- Global variables ---- */
/* ---- External functions ---- */
/* ---- Static variables ---- */
/* ---- Static functions ---- */
/* LDRA_HEADER_END
*/
/*! \brief Send Parameter Response Frame
 * \param id + datas
 * \return none
 */
 
void
    CBU_SendMaintenanceEquipmentTestResponse()
    {
   int iCBUmaint_1zzqqzz                                                                                    
 = CBUmaint_1zzqqzz                                                                                     (       1 ) ; /* 37 */
        uint32_t
            id_value = COM_framesMaintenance [ COM_FRAME_MAINTENANCE_TX_EQUIPTESTRESP ].id + CAN_EXTENDED_ID_U32 ;
        uint8_t
            buffer [ 64U ] ;
        uint8_t
            index = 0 ;
        Can_PduType
            local_pduInfo ;
        uint16_t
            swPduHandle = 0 ; // No need to be change
        if
            (
            COM_debugTestReq.measFormat == COM_DBG_MEASFORMAT_RAW
            )
 {
            {
                do
                    {
                        buffer [ index ] = ( uint8_t ) (
                        ( COM_debugTestReq.rawMeasure ) & 0xFF ) ;
                        buffer [ index + 1 ] = ( uint8_t ) (
                        ( COM_debugTestReq.rawMeasure >> 8 ) & 0xFF ) ;
                        buffer [ index + 2 ] = ( uint8_t ) (
                        ( COM_debugTestReq.rawMeasure >> 16 ) & 0xFF ) ;
                        buffer [ index + 3 ] = ( uint8_t ) (
                        ( COM_debugTestReq.rawMeasure >> 24 ) & 0xFF ) ;
                    }
                while
 (  /* 50 */
                    (
                    0
           ) &&                                                                                                  
CBUmaint_1zzqqzz                                                                                     (       2 ) /* 24 */
                    ) ;                                             // return the format wanted by the user
            }
    CBUmaint_1zzqqzz                                                                                     (      3 ) ; /* 3 */
 }
        else
 {                                                                                                    ;
CBUmaint_1zzqqzz                                                                                     (      4 ); /* 2 */
            {
                do
                    {
                        buffer [ index ] = ( uint8_t ) (
                        ( COM_debugTestReq.hmiMeasure ) & 0xFF ) ;
                        buffer [ index + 1 ] = ( uint8_t ) (
                        ( COM_debugTestReq.hmiMeasure >> 8 ) & 0xFF ) ;
                        buffer [ index + 2 ] = ( uint8_t ) (
                        ( COM_debugTestReq.hmiMeasure >> 16 ) & 0xFF ) ;
                        buffer [ index + 3 ] = ( uint8_t ) (
                        ( COM_debugTestReq.hmiMeasure >> 24 ) & 0xFF ) ;
                    }
                while
 (  /* 50 */
                    (
                    0
           ) &&                                                                                                  
CBUmaint_1zzqqzz                                                                                     (       5 ) /* 24 */
                    ) ;
            }
 }
        index += 4U ;// incrementing the index by 4 the measurments occupy 4 bytes
        // formatting the buffer according to the DBC
        buffer [ index ++ ] = ( uint8_t ) (
        (
        ( COM_debugTestReq.discreteIoId & 0x0F ) << 4 ) + (
        ( COM_debugTestReq.discreteIosPWMResult & 0x03 ) << 2 ) + ( COM_debugTestReq.discreteIosReadResult & 0x03 ) ) ;
        buffer [ index ++ ] = ( uint8_t ) (
        (
        ( COM_debugTestReq.relaySwitchId & 0x03 ) << 2 ) + ( COM_debugTestReq.relaySwitchResult & 0x03 ) ) ;
        CBU_CreatePduInfo ( id_value , swPduHandle , index , buffer , & local_pduInfo ) ;
        CBU_SendFrame ( local_pduInfo , Can_Maint_Frame_Tx_EquipmentTest ) ;
    CBUmaint_1zzqqzz                                                                                     (       6 ) ; /* 30 */  
    }
/*! \brief Send Parameter Response Frame
 * \param id + datas
 * \return none
 */
 
void
    CBU_SendMaintenanceParameterResponse (
    uint16_t paramId ,
    uint32_t ParamValue ,
    boolean status )
    {
   int iCBUmaint_1zzqqzz                                                                                    
 = CBUmaint_1zzqqzz                                                                                     (       7 ) ; /* 37 */
        uint32_t
            id_value = COM_framesControl [ COM_FRAME_MAINTENANCE_TX_PARAMETERRESP ].id + CAN_EXTENDED_ID_U32 ;
        uint8_t
            buffer [ 64U ] ;
        uint8_t
            index = 0 ;
        Can_PduType
            local_pduInfo ;
        uint16_t
            swPduHandle = 0 ; // No need to be change
            // formatting the buffer according to the DBC
        do
            {
                buffer [ index ] = ( uint8_t ) (
                ( ParamValue ) & 0xFF ) ;
                buffer [ index + 1 ] = ( uint8_t ) (
                ( ParamValue >> 8 ) & 0xFF ) ;
                buffer [ index + 2 ] = ( uint8_t ) (
                ( ParamValue >> 16 ) & 0xFF ) ;
                buffer [ index + 3 ] = ( uint8_t ) (
                ( ParamValue >> 24 ) & 0xFF ) ;
            }
        while
 (  /* 50 */
            (
            0
           ) &&                                                                                                  
CBUmaint_1zzqqzz                                                                                     (       8 ) /* 24 */
            ) ;
        index += 4U ;
        do
            {
                ( buffer [ index ] ) = ( uint8_t ) ( paramId ) ;
                buffer [ index + 1 ] = ( uint8_t ) (
                ( paramId ) >> 8 ) ;
            }
        while
 (  /* 50 */
            (
            0
           ) &&                                                                                                  
CBUmaint_1zzqqzz                                                                                     (       9 ) /* 24 */
            ) ;
        index += 2U ;
        buffer [ index ++ ] = ( uint8_t ) status & 0x03 ;
        CBU_CreatePduInfo ( id_value , swPduHandle , index , buffer , & local_pduInfo ) ;
        CBU_SendFrame ( local_pduInfo , Can_Maint_Frame_Tx_Paramter ) ;
    CBUmaint_1zzqqzz                                                                                     (      10 ) ; /* 30 */  
    }
/*! \brief Get Equipment Test Request Frame
 * \param input : buffer pointer
 * output : request type + request's parameters
 * \return none
 */
 
void
    CBU_GetMaintenanceEquipmentTestRequest (
    const uint8_t buffer [] ,
    uint8_t * testCmd ,
    uint8_t * muxAddress ,
    uint8_t * measFormat ,
    uint8_t * relaySwitchCmd ,
    uint8_t * relaySwitchId ,
    uint8_t * discreteIoCmd ,
    uint8_t * discreteIoId ,
    uint8_t * ledCmd ,
    uint8_t * ledId ,
    uint8_t * ledColor ,
    uint8_t * ledBlinkFreq )
    {
   int iCBUmaint_1zzqqzz                                                                                    
 = CBUmaint_1zzqqzz                                                                                     (      11 ) ; /* 37 */
        uint8_t
            byte = 0 ;
        byte = buffer [ 0 ] ;
        * testCmd = byte & 0x0F ;
                            // reading the Test cmd from the Buffer
        byte >>= 4 ;
        * muxAddress = byte & 0x07 ;
                               // reading the MuxAddress from the Buffer
        byte >>= 3 ;
        * measFormat = byte & 0x01 ;
                               // reading the measFormat (RAW OR HMI) from the Buffer
        byte = buffer [ 1 ] ;
        * relaySwitchCmd = byte & 0x0F ;
                                   // reading the relay Switch cmd from the Buffer
        byte >>= 4 ;
        * relaySwitchId = byte & 0x03 ;
                                  // reading the relay Switch Id from the Buffer
        byte = buffer [ 2 ] ;
        * discreteIoCmd = byte & 0x0F ;
                                  // reading the DSIO cmd from the Buffer
        byte >>= 4 ;
        * discreteIoId = byte & 0x0F ;
                                 // reading the DSIO Id from the Buffer
        * ledBlinkFreq = buffer [ 3 ] ;
                               // reading the Blink Freq from the Buffer Unused for the moment
        byte = buffer [ 4 ] ;
        * ledCmd = byte & 0x03 ;
                           // reading the Led Cmd from the Buffer (ON/ OFF)
        byte >>= 2 ;
        * ledId = byte & 0x03 ;
                          // reading the LED id from the Buffer
        byte >>= 2 ;
        * ledColor = byte & 0x01 ;
                             // reading the Color of the led from the Buffer Unused for the moment
    CBUmaint_1zzqqzz                                                                                     (      12 ) ; /* 30 */  
    }
/*! \brief Get Parameter Request Frame
 * \param input : buffer pointer
 * output : request type + request's parameters
 * \return none
 */
 
void
    CBU_GetMaintenanceParameterRequest (
    const uint8_t buffer [] ,
    uint8_t * reqType ,
    uint16_t * id ,
    uint32_t * value )
    {
   int iCBUmaint_1zzqqzz                                                                                    
 = CBUmaint_1zzqqzz                                                                                     (      13 ) ; /* 37 */
        * value = ( uint32_t ) (
        (
        ( uint32_t ) buffer [ 0 + 3 ] << 24 ) | (
        ( uint32_t ) buffer [ 0 + 2 ] << 16 ) | (
        ( uint32_t ) buffer [ 0 + 1 ] << 8 ) | ( uint32_t ) buffer [ 0 ] ) ;
                                        // reading the new value of the PAR from the Buffer Unused for the moment
        * id = ( uint16_t ) (
        (
        ( uint16_t ) ( buffer ) [ 4 + 1 ] << 8 ) | ( uint16_t ) ( buffer ) [ 4 ] ) ;
                                     // reading the ID of the PAR from the Buffer Unused for the moment
        * reqType = buffer [ 6 ] & 0x03 ;
                                 // reading the request for the PAR from the Buffer Unused for the moment (update, save, read)
    CBUmaint_1zzqqzz                                                                                     (      14 ) ; /* 30 */  
    }
#define qqqbranches     14
#define QQQMAXMCDCSIZE      2
 static FILE * CBUmaint_1zzhfil                                                                                     ;
  /* put in undefs to protect our parameter names from macros */                                                                                                                                                                                                    
#undef f                                                                                                                                                                                                                                                            
#undef i                                                                                                                                                                                                                                                            
#undef j                                                                                                                                                                                                                                                            
#undef k                                                                                                                                                                                                                                                            
#undef s                                                                                                                                                                                                                                                            
#undef l                                                                                                                                                                                                                                                            
#undef ii                                                                                                                                                                                                                                                           
#undef some                                                                                                                                                                                                                                                         
#undef none                                                                                                                                                                                                                                                         
#undef from                                                                                                                                                                                                                                                         
#undef a                                                                                                                                                                                                                                                            
#undef b                                                                                                                                                                                                                                                            
#undef iz                                                                                                                                                                                                                                                           
#undef jz                                                                                                                                                                                                                                                           
#undef qqnull_params                                                                                                                                                                                                                                                
#define qqnull_params void                                                                                                                                                                                                                                          
  /* Conventional Instrumentation */                                                                                                                                                                                                                                
    /* not single file and not fileid */                                                                                                                                                                                                                            
    static char qqqqone[]   = "%6d\n";           /* single point */                                                                                                                                                                                                 
  /* uncompressed data structures */                                                                                                                                                                                                                                
  static int CBUmaint_1zqqzqz(qqnull_params);                                                                                                                                                                                                                       
  static int CBUmaint_1zqqzqz1(qqnull_params);                                                                                                                                                                                                                      
    /* ----------------------------------------------------------------------* 200 *                                                                                                                                                                                
     *            Procedures                                                                                                                                                                                                                                        
     * -----------------------------------------------------------------------------                                                                                                                                                                                
     */                                                                                                                                                                                                                                                             
  /* ----------------------------------------------------------------------* 210 *                                                                                                                                                                                  
   *    C System utilities in use:                                                                                                                                                                                                                                  
   *        fprintf                                                                                                                                                                                                                                                 
   *        fclose                                                                                                                                                                                                                                                  
   *        sscanf                                                                                                                                                                                                                                                  
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  /* ----------------------------------------------------------------------* 213 *                                                                                                                                                                                  
   *            qqoutput* suite                                                                                                                                                                                                                                     
   *      Main output routines. These may require modification.                                                                                                                                                                                                     
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  /* ----------------------------------------------------------------------* 214 *                                                                                                                                                                                  
   *            qqoutput                                                                                                                                                                                                                                            
   *    This is the principle output routine.                                                                                                                                                                                                                       
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
    static void qqoutput(FILEPOINT char * s,int i)                                                                                                                                                                                                                  
  /* f - file pointer, s - format string, i - integer for probe value */                                                                                                                                                                                            
  {                                                                                                                                                                                                                                                                 
    /* printing to a file */                                                                                                                                                                                                                                        
    /* fprintf exists, not threaded */                                                                                                                                                                                                                              
      /* fprintf exists,not threaded, (not SINGLEFILE and not FILEID ) */                                                                                                                                                                                           
      /* fprintf exists,not threaded, (not SINGLEFILE and not FILEID ) and not forkfl  */                                                                                                                                                                           
      fprintf(f,s,i);                                                                                                                                                                                                                                               
  } /* end of qqoutput */                                                                                                                                                                                                                                           
    /* ----------------------------------------------------------------------* 215 *                                                                                                                                                                                
     *            qqoutput0                                                                                                                                                                                                                                         
     * -----------------------------------------------------------------------------                                                                                                                                                                                
     */                                                                                                                                                                                                                                                             
    static void qqoutput0(FILEPOINT char * s)                                                                                                                                                                                                                       
    {                                                                                                                                                                                                                                                               
      fprintf(f,s);                                                                                                                                                                                                                                                 
    } /* end of qqoutput0 */                                                                                                                                                                                                                                        
  /* ----------------------------------------------------------------------* 219 *                                                                                                                                                                                  
   *            end of qqoutput* suite                                                                                                                                                                                                                              
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
#undef QQQTEMP1                                                                                                                                                                                                                                                     
#define QQQTEMP1                                                                                                                                                                                                                                                    
  /* ----------- zqqzqz ---------------------------------------------------* 310 *                                                                                                                                                                                  
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  /* ----------------------------------------------------------------------* 312 *                                                                                                                                                                                  
   * This routine opens the execution history file. It is instrumented at the                                                                                                                                                                                       
   * start of the main program if one exists in the file. In general this is                                                                                                                                                                                        
   * superceded by CBUmaint_1zqqzqz1 below.                                                                                                                                                                                                                         
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int CBUmaint_1zqqzqz(qqnull_params)                                                                                                                                                                                                                        
  {                                                                                                                                                                                                                                                                 
    if ( CBUmaint_1zzopen != 1 )                                                                                                                                                                                                                                    
    {                                                                                                                                                                                                                                                               
#undef QQQMUSTOPEN                                                                                                                                                                                                                                                  
      CBUmaint_1zzopen = 1;                                                                                                                                                                                                                                         
    }                                                                                                                                                                                                                                                               
    return(1);                                                                                                                                                                                                                                                      
  }  /* end of zqqzqz */                                                                                                                                                                                                                                            
  /* ----------- zqqzqz1 --------------------------------------------------* 315 *                                                                                                                                                                                  
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  /* ----------------------------------------------------------------------* 317 *                                                                                                                                                                                  
   * This routine also opens the execution history file.  It is called                                                                                                                                                                                              
   * automatically if a probe fires and the execution history is not already                                                                                                                                                                                        
   * opened (CBUmaint_1zzopen = 0 ).                                                                                                                                                                                                                                
   * Because this always works ( it was intended for files with no main program                                                                                                                                                                                     
   * it is now the de facto common way to open the execution history.                                                                                                                                                                                               
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int CBUmaint_1zqqzqz1(qqnull_params)                                                                                                                                                                                                                       
  {                                                                                                                                                                                                                                                                 
    if ( CBUmaint_1zzopen != 1 )                                                                                                                                                                                                                                    
    {                                                                                                                                                                                                                                                               
      if ( CBUmaint_1zzopen == 0 )                                                                                                                                                                                                                                  
      {                                                                                                                                                                                                                                                             
      CBUmaint_1zzhfil =                                                                                                                                                                                                                                            
           fopen( "CBUmaint_1.exh","w");  /* 12 */                                                                                                                                                                                                                  
      }                                                                                                                                                                                                                                                             
      else                                                                                                                                                                                                                                                          
      {                                                                                                                                                                                                                                                             
          CBUmaint_1zzhfil =                                                                                                                                                                                                                                        
               fopen( "CBUmaint_1.exh","a");  /* 13 */                                                                                                                                                                                                              
      }                                                                                                                                                                                                                                                             
      CBUmaint_1zzopen = 1;                                                                                                                                                                                                                                         
    }                                                                                                                                                                                                                                                               
    return(1);                                                                                                                                                                                                                                                      
  }  /* end of zqqzqz1 */                                                                                                                                                                                                                                           
  /* ----------- zzqqzz ---------------------------------------------------* 321 *                                                                                                                                                                                  
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  /* ----------------------------------------------------------------------* 323 *                                                                                                                                                                                  
   *            This is the routine which usually puts an integer into                                                                                                                                                                                              
   * the execution history file and returns unity.                                                                                                                                                                                                                  
   * This routine is the primary routine for gathering                                                                                                                                                                                                              
   * the execution history. Note that the last entry                                                                                                                                                                                                                
   * is usually inserted by CBUmaint_1zqzqzq.                                                                                                                                                                                                                       
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int CBUmaint_1zzqqzz(int qqqi)                                                                                                                                                                                                                             
  {                                                                                                                                                                                                                                                                 
    if ( CBUmaint_1zzopen != 1 )                                                                                                                                                                                                                                    
    {                                                                                                                                                                                                                                                               
      CBUmaint_1zqqzqz1();                                                                                                                                                                                                                                          
    }                                                                                                                                                                                                                                                               
    if ( CBUmaint_1zzopen )                                                                                                                                                                                                                                         
    {                                                                                                                                                                                                                                                               
      /* streamed */                                                                                                                                                                                                                                                
      /* unbuffered */                                                                                                                                                                                                                                              
        qqoutput(                                                                                                                                                                                                                                                   
        CBUmaint_1zzhfil,                                                                                                                                                                                                                                           
          qqqqone, qqqi);                                                                                                                                                                                                                                           
    }                                                                                                                                                                                                                                                               
    return(1);                                                                                                                                                                                                                                                      
  } /* end of zzqqzz */                                                                                                                                                                                                                                             
  /* ----------- zqzqzq ---------------------------------------------------* 342 *                                                                                                                                                                                  
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  /* ----------------------------------------------------------------------* 344 *                                                                                                                                                                                  
   * This routine should be called before the program                                                                                                                                                                                                               
   * terminates. It closes the execution history                                                                                                                                                                                                                    
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int CBUmaint_1zqzqzq(int qqqi)                                                                                                                                                                                                                             
  {                                                                                                                                                                                                                                                                 
      if ( CBUmaint_1zzopen != 1 )                                                                                                                                                                                                                                  
      {                                                                                                                                                                                                                                                             
        CBUmaint_1zqqzqz1();                                                                                                                                                                                                                                        
      }                                                                                                                                                                                                                                                             
      /* not compressed */                                                                                                                                                                                                                                          
      /* streamed */                                                                                                                                                                                                                                                
      /* notbuffered */                                                                                                                                                                                                                                             
      qqoutput(CBUmaint_1zzhfil,                                                                                                                                                                                                                                    
        qqqqone, qqqi);                                                                                                                                                                                                                                             
      /* upload the history */                                                                                                                                                                                                                                      
        fclose(CBUmaint_1zzhfil);                                                                                                                                                                                                                                   
        CBUmaint_1zzopen = 2;                                                                                                                                                                                                                                       
    return(1);                                                                                                                                                                                                                                                      
  } /* end of zqzqzq */                                                                                                                                                                                                                                             
  /*   the following routines should be left alone */                                                                                                                                                                                                               
  /* ----------------------------------------------------------------------* 355 *                                                                                                                                                                                  
   *            CBUmaint_1zzzqtz                                                                                                                                                                                                                                    
   * This routine captures the value of an expression                                                                                                                                                                                                               
   * and then returns a jump if the value is not 0.                                                                                                                                                                                                                 
   *                                                                                                                                                                                                                                                                
   *   qqqa - value of expression                                                                                                                                                                                                                                   
   *   qqqb - jump table index.                                                                                                                                                                                                                                     
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int CBUmaint_1zzzqtz(int qqqa, int qqqb)                                                                                                                                                                                                                   
  {                                                                                                                                                                                                                                                                 
      if (qqqa)                                                                                                                                                                                                                                                     
      {                                                                                                                                                                                                                                                             
        CBUmaint_1zzqqzz(qqqb) ;                                                                                                                                                                                                                                    
      }                                                                                                                                                                                                                                                             
    return(qqqa);                                                                                                                                                                                                                                                   
  } /* end of zzzqtz */                                                                                                                                                                                                                                             
  /* ----------------------------------------------------------------------* 356 *                                                                                                                                                                                  
   *            CBUmaint_1zzzqfz                                                                                                                                                                                                                                    
   * This routine captures the value of an expression                                                                                                                                                                                                               
   * and then returns a jump if the value is 0.                                                                                                                                                                                                                     
   *                                                                                                                                                                                                                                                                
   *  qqqa - value of expression                                                                                                                                                                                                                                    
   *  qqqb - jump table index.                                                                                                                                                                                                                                      
   * -----------------------------------------------------------------------------                                                                                                                                                                                  
   */                                                                                                                                                                                                                                                               
  static int CBUmaint_1zzzqfz(int qqqa,int qqqb)                                                                                                                                                                                                                    
  {                                                                                                                                                                                                                                                                 
    {                                                                                                                                                                                                                                                               
      if (qqqa)                                                                                                                                                                                                                                                     
      {                                                                                                                                                                                                                                                             
        return(qqqa);                                                                                                                                                                                                                                               
      }                                                                                                                                                                                                                                                             
      else                                                                                                                                                                                                                                                          
      {                                                                                                                                                                                                                                                             
        CBUmaint_1zzqqzz(qqqb);                                                                                                                                                                                                                                     
      }                                                                                                                                                                                                                                                             
    }                                                                                                                                                                                                                                                               
    return(qqqa);                                                                                                                                                                                                                                                   
  } /* zzzqfz */                                                                                                                                                                                                                                                    
/* END OF TESTBED INSTRUMENTATION */                                                                                                                                                                                                                                
 
