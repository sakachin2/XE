//*CID://+v6G4R~:                             update#=   12;       //+v6G4R~
//**************************************************************
//* ueh.h
//**************************************************************
//v6G4:161212 (Win10)compile err by v022 was appieared when win10  //+v6G4I~
//v6F1:160831 W64 try Exception msg                                //~v6F1I~
//v423:010101 TLinux:another SignalHandler definition insignal.h   //~v423I~
//v422:010101 TLinux:_fpreg is defined on sigcontext.h,it is duplicated with ueh.h//~v422I~
//v407:001109 AIX support:no native SignalHandler definition       //~v407I~
//v406:001109 AIX support:compile dose not support #pragma pack    //~v406I~
//v324 000813:LINUX support                                        //~v324I~
//v053:970107:gcc version(control by DPMI)                         //~v053I~
//            -ehception handle by signal                          //~v053I~
//v022:960727:WIN32(CONSOLE api)                                   //~v022I~
//********************************************************************
//*data area
//********************************************************************
#ifdef W32  //copy from f:\toolkt21\c\os2h\bsexcpt.h               //~v022I~
                                                                   //~v022I~
//*********                                                        //~v022I~
    #define XCPT_ACCESS_VIOLATION       	/*os2=0xC0000005*/ \
            EXCEPTION_ACCESS_VIOLATION      /*w95:same      */     //~v022I~
    #define XCPT_DATATYPE_MISALIGNMENT  	/*os2=0xC000009E*/ \
            EXCEPTION_DATATYPE_MISALIGNMENT /*w95=0x80000002*/     //~v022I~
    #define XCPT_BREAKPOINT                 /*os2=0xC000009F*/ \
            EXCEPTION_BREAKPOINT            /*w95=0x80000003*/     //~v022I~
    #define XCPT_SINGLE_STEP                /*os2=0xC00000A0*/ \
            EXCEPTION_SINGLE_STEP           /*w95=0x80000004*/     //~v022I~
    #define XCPT_ARRAY_BOUNDS_EXCEEDED      /*os2=0xC0000093*/ \
            EXCEPTION_ARRAY_BOUNDS_EXCEEDED /*w95=0xC000008C*/     //~v022I~
    #define XCPT_FLOAT_DENORMAL_OPERAND     /*os2=0xC0000094*/ \
            EXCEPTION_FLT_DENORMAL_OPERAND  /*w95=0xC000008D*/     //~v022I~
    #define XCPT_FLOAT_DIVIDE_BY_ZERO       /*os2=0xC0000095*/ \
            EXCEPTION_FLT_DIVIDE_BY_ZERO    /*w95=0xC000008E*/     //~v022I~
    #define XCPT_FLOAT_INEXACT_RESULT       /*os2=0xC0000096*/ \
            EXCEPTION_FLT_INEXACT_RESULT    /*w95=0xC000008F*/     //~v022I~
    #define XCPT_FLOAT_INVALID_OPERATION    /*os2=0xC0000097*/ \
            EXCEPTION_FLT_INVALID_OPERATION /*w95=0xC0000090*/     //~v022I~
    #define XCPT_FLOAT_OVERFLOW             /*os2=0xC0000098*/ \
            EXCEPTION_FLT_OVERFLOW          /*w95=0xC0000091*/     //~v022I~
    #define XCPT_FLOAT_STACK_CHECK          /*os2=0xC0000099*/ \
            EXCEPTION_FLT_STACK_CHECK       /*w95=0xC0000092*/     //~v022I~
    #define XCPT_FLOAT_UNDERFLOW            /*os2=0xC000009A*/ \
            EXCEPTION_FLT_UNDERFLOW         /*w95=0xC0000092*/     //~v022I~
    #define XCPT_INTEGER_DIVIDE_BY_ZERO     /*os2=0xC000009B*/ \
            EXCEPTION_INT_DIVIDE_BY_ZERO    /*w95=0xC0000094*/     //~v022I~
    #define XCPT_INTEGER_OVERFLOW           /*os2=0xC000009C*/ \
            EXCEPTION_INT_OVERFLOW          /*w95=0xC0000095*/     //~v022I~
    #define XCPT_PRIVILEGED_INSTRUCTION     /*os2=0xC000009D*/ \
            EXCEPTION_PRIV_INSTRUCTION      /*w95=0xC0000096*/     //~v022I~
    #define XCPT_IN_PAGE_ERROR              /*os2=0xC0000006*/ \
            EXCEPTION_IN_PAGE_ERROR         /*w95=same      */     //~v022I~
    #define XCPT_ILLEGAL_INSTRUCTION        /*os2=0xC000001C*/ \
            EXCEPTION_ILLEGAL_INSTRUCTION   /*w95=0xC000001D*/     //~v022I~
    #define XCPT_NONCONTINUABLE_EXCEPTION   /*os2=0xC0000024*/ \
            EXCEPTION_NONCONTINUABLE_EXCEPTION  /*w95=0xC0000025*/ //~v022I~
    #define XCPT_UNABLE_TO_GROW_STACK       /*os2=0x80010001*/ \
            EXCEPTION_STACK_OVERFLOW        /*w95=0xC00000FD*/     //~v022I~
    #define XCPT_INVALID_DISPOSITION        /*os2=0xC0000025*/ \
            EXCEPTION_INVALID_DISPOSITION   /*w95=0xC0000026*/     //~v022I~
    #define XCPT_GUARD_PAGE_VIOLATION       /*os2=0x80000001*/ \
            EXCEPTION_GUARD_PAGE            /*w95=same      */     //~v022I~
                                                                   //~v022I~
    //#define XCPT_PROCESS_TERMINATE          0xC0010001           //~v022I~
    //#define XCPT_ASYNC_PROCESS_TERMINATE    0xC0010002           //~v022I~
    //#define XCPT_INVALID_LOCK_SEQUENCE      0xC000001D           //~v022I~
    //#define XCPT_B1NPX_ERRATA_02            0xC0010004           //~v022I~
    //#define XCPT_UNWIND                     0xC0000026           //~v022I~
    //#define XCPT_BAD_STACK                  0xC0000027           //~v022I~
    //#define XCPT_INVALID_UNWIND_TARGET      0xC0000028           //~v022I~
    //#define XCPT_SIGNAL                     0xC0010003           //~v022I~
                                                                   //~v022I~
	#define XCPT_CONTINUE_SEARCH    	/*os2=0x00000000*/ /* exception not handled   */\
            EXCEPTION_CONTINUE_SEARCH   /*w95=same      */         //~v022I~
	#define XCPT_CONTINUE_EXECUTION 	/*os2=0xFFFFFFFF*/ /* exception handled       */\
            EXCEPTION_CONTINUE_EXECUTION/*w95=same      */         //~v022I~
	#define XCPT_CONTINUE_STOP      	/*0x00716668    */ /* exception handled by    */\
    			                                           /* debugger (VIA DosDebug) */\
            EXCEPTION_EXECUTE_HANDLER	/*w95=1         */ /*???*/ //~v022I~
                                                                   //~v022I~
	#define EH_NONCONTINUABLE   		/*os2=0x1       */ /* Noncontinuable exception */\
			EXCEPTION_NONCONTINUABLE    /*w95=same      */         //~v022I~
                                                                   //~v022I~
//OS/2 registration record                                         //~v022I~
#ifdef W32                                                         //+v6G4I~
typedef ULONG (*UEXCEPTIONHANDLER)(PEXCEPTIONREPORTRECORD,         //+v6G4I~
					           	PEXCEPTIONREGISTRATIONRECORD,      //+v6G4I~
								PCONTEXTRECORD);                   //+v6G4I~
#else                                                              //+v6G4I~
typedef ULONG (*UEXCEPTIONHANDLER)(PEXCEPTIONREPORTRECORD,         //~v022I~
					           	PEXCEPTIONREGISTRATIONRECORD,      //~v022I~
								PCONTEXTRECORD,                    //~v022I~
								PVOID);                            //~v022I~
#endif                                                             //~v6F1M~
	struct _EXCEPTIONREGISTRATIONRECORD                            //~v022I~
   	{                                                              //~v022I~
// 		struct _EXCEPTIONREGISTRATIONRECORD * volatile prev_structure;//~v022I~
//    	_ERR * volatile ExceptionHandler;				//os/2     //~v022I~
		LPTOP_LEVEL_EXCEPTION_FILTER PrevWinExceptionHandler; //win32//~v022I~
		UEXCEPTIONHANDLER            UExceptionHandler;            //~v022R~
   };                                                              //~v022I~
#else                                                              //~v053I~
#endif                                                             //~v053I~
                                                                   //~v053I~
#if defined(W32) || defined(DPMI) || defined(UNX)                  //~v324R~
                                                                   //~v053I~
//  #ifdef DPMI					//DPMI version                     //~v324R~
    #if defined(DPMI)||defined(UNX)					//DPMI version //~v324R~
    	#define EXCEPTION_MAXIMUM_PARAMETERS	4                  //~v053R~
    	#define EXCEPTION_UABEND	            0xfe               //~v053I~
    #else                       //not DPMI                         //~v053I~
    #endif                      //DPMI or not                      //~v053I~
typedef struct _EXCEPTIONREGISTRATIONRECORD EXCEPTIONREGISTRATIONRECORD;//~v022I~
typedef struct _EXCEPTIONREGISTRATIONRECORD *PEXCEPTIONREGISTRATIONRECORD;//~v022I~
//OS/2 report record                                               //~v022I~
                                                                   //~v022I~
struct _EXCEPTIONREPORTRECORD                                      //~v022I~
   {                                                               //~v022I~
   ULONG   ExceptionNum;                /* exception number */     //~v022I~
   ULONG   fHandlerFlags;                                          //~v022I~
// struct  _EXCEPTIONREPORTRECORD    *NestedExceptionReportRecord;//os2//~v022R~
   void    *NestedExceptionReportRecord;        //w95              //~v022I~
   PVOID   ExceptionAddress;                                       //~v022I~
   ULONG   cParameters;                 /* Size of Exception Specific Info *///~v022I~
#ifdef ULIB64X                                                     //~v6F1I~
   DWORD64 ExceptionInfo[EXCEPTION_MAXIMUM_PARAMETERS];            //~v6F1I~
#else                                                              //~v6F1I~
   ULONG   ExceptionInfo[EXCEPTION_MAXIMUM_PARAMETERS];            //~v022I~
#endif                                                             //~v6F1I~
                                        /* Exception Specfic Info *///~v022I~
   };                                                              //~v022I~
                                                                   //~v022I~
typedef struct _EXCEPTIONREPORTRECORD EXCEPTIONREPORTRECORD;       //~v022I~
typedef struct _EXCEPTIONREPORTRECORD *PEXCEPTIONREPORTRECORD;     //~v022I~
                                                                   //~v022I~
/*                                                                 //~v022I~
 * ContextRecord                                                   //~v022I~
 *                                                                 //~v022I~
 * This is the machine specific register contents for the thread   //~v022I~
 * at the time of the exception. Note that only the register sets  //~v022I~
 * specified by ContextFlags contain valid data. Conversely, only  //~v022I~
 * registers specified in ContextFlags will be restored if an exception//~v022I~
 * is handled.                                                     //~v022I~
 */                                                                //~v022I~
//OS/2 report record                                               //~v022I~
                                                                   //~v022I~
/*XLATOFF */                                                       //~v022I~
                                                                   //~v406I~
#ifdef AIX                                                         //~v406I~
#else                                                              //~v406I~
#pragma pack(1)                                                    //~v022I~
#endif                                                             //~v406I~
                                                                   //~v406I~
/*XLATON  */                                                       //~v022I~
//typedef struct  _fpreg      /* coprocessor stack register element *///~v422R~
typedef struct  _ueh_fpreg      /* coprocessor stack register element *///~v422I~
   {                                                               //~v022I~
   ULONG losig;                                                    //~v022I~
   ULONG hisig;                                                    //~v022I~
   USHORT signexp;                                                 //~v022I~
   } FPREG , *PFPREG ;                                             //~v022I~
                                                                   //~v406I~
#ifdef AIX                                                         //~v406I~
#else                                                              //~v406I~
#pragma pack()                                                     //~v022I~
#endif                                                             //~v406I~
                                                                   //~v022I~
struct _CONTEXT_OS2                                                //~v022R~
   {                                                               //~v022I~
  /*                                                               //~v022I~
   * The flags values within this flag control the contents of     //~v022I~
   * a ContextRecord.                                              //~v022I~
   *                                                               //~v022I~
   * If the ContextRecord is used as an input parameter, then      //~v022I~
   * for each portion of the ContextRecord controlled by a flag    //~v022I~
   * whose value is set, it is assumed that that portion of the    //~v022I~
   * ContextRecord contains valid context. If the ContextRecord    //~v022I~
   * is being used to modify a thread's context, then only that    //~v022I~
   * portion of the thread's context will be modified.             //~v022I~
   *                                                               //~v022I~
   * If the ContextRecord is used as an Input/Output parameter to  //~v022I~
   * capture the context of a thread, then only those portions of the//~v022I~
   * thread's context corresponding to set flags will be returned. //~v022I~
   */                                                              //~v022I~
                                                                   //~v022I~
   ULONG ContextFlags;                                             //~v022I~
                                                                   //~v022I~
  /*                                                               //~v022I~
   * This section is specified/returned if the ContextFlags        //~v022I~
   * contains the flag CONTEXT_FLOATING_POINT.                     //~v022I~
   */                                                              //~v022I~
                                                                   //~v022I~
   ULONG   ctx_env[7];                                             //~v022I~
   FPREG   ctx_stack[8];                                           //~v022I~
                                                                   //~v022I~
  /*                                                               //~v022I~
   * This section is specified/returned if the ContextFlags        //~v022I~
   * contains the flag CONTEXT_SEGMENTS.                           //~v022I~
   */                                                              //~v022I~
                                                                   //~v022I~
   ULONG ctx_SegGs;                                                //~v022I~
   ULONG ctx_SegFs;                                                //~v022I~
   ULONG ctx_SegEs;                                                //~v022I~
   ULONG ctx_SegDs;                                                //~v022I~
                                                                   //~v022I~
  /*                                                               //~v022I~
   * This section is specified/returned if the ContextFlags        //~v022I~
   * contains the flag CONTEXT_INTEGER.                            //~v022I~
   */                                                              //~v022I~
                                                                   //~v022I~
   ULONG ctx_RegEdi;                                               //~v022I~
   ULONG ctx_RegEsi;                                               //~v022I~
   ULONG ctx_RegEax;                                               //~v022I~
   ULONG ctx_RegEbx;                                               //~v022I~
   ULONG ctx_RegEcx;                                               //~v022I~
   ULONG ctx_RegEdx;                                               //~v022I~
                                                                   //~v022I~
  /*                                                               //~v022I~
   * This section is specified/returned if the ContextFlags        //~v022I~
   * contains the flag CONTEXT_CONTROL.                            //~v022I~
   */                                                              //~v022I~
                                                                   //~v022I~
   ULONG ctx_RegEbp;                                               //~v022I~
   ULONG ctx_RegEip;                                               //~v022I~
   ULONG ctx_SegCs;                                                //~v022I~
   ULONG ctx_EFlags;                                               //~v022I~
   ULONG ctx_RegEsp;                                               //~v022I~
   ULONG ctx_SegSs;                                                //~v022I~
                                                                   //~v022I~
   };                                                              //~v022I~
                                                                   //~v022I~
typedef struct _CONTEXT_OS2 CONTEXTRECORD;                         //~v022R~
typedef struct _CONTEXT_OS2 *PCONTEXTRECORD;                       //~v022R~
                                                                   //~v022I~
#else                                                              //~v022I~
#endif                                                             //~v022M~
                                                                   //~v022I~
//#ifdef DPMI					//DPMI version                     //~v324R~
#if defined(DPMI) || defined(UNX)					//DPMI version //~v324R~
	#define XCPT_CONTINUE_SEARCH    		0	/*os2=0x00000000*/ /* exception not handled   *///~v053I~
    #define CONTEXT_CONTROL         0x00000001L     /* SS:ESP, CS:EIP, EFLAGS,  *///~v053I~
                                                    /* EBP                      *///~v053I~
    #define CONTEXT_INTEGER         0x00000002L     /* EAX, EBX, ECX, EDX, ESI, *///~v053I~
                                                    /* EDI                      *///~v053I~
    #define CONTEXT_SEGMENTS        0x00000004L     /* DS, ES, FS, GS           *///~v053I~
    #define CONTEXT_FLOATING_POINT  0x00000008L     /* numeric coprocessor state *///~v053I~
#ifndef UNX 					//Linux define it in signal.h      //~v324R~
    typedef void (*SignalHandler)(int);                            //~v053I~
#else                                                              //~v407I~
	#ifdef AIX                                                     //~v407I~
	    typedef void (*SignalHandler)(int);                        //~v407I~
	#else                                                          //~v407I~
        #ifdef LNXLC2                                              //~v423I~
            #define SignalHandler __sighandler_t      //in signal.h//~v423I~
        #else                                                      //~v423I~
        #endif                                                     //~v423I~
	#endif                                                         //~v407I~
#endif                                                             //~v324I~
    typedef ULONG (*UEXCEPTIONHANDLER)(PEXCEPTIONREPORTRECORD,     //~v053I~
    					           	PEXCEPTIONREGISTRATIONRECORD,  //~v053I~
    								PCONTEXTRECORD);               //~v053R~
	struct _EXCEPTIONREGISTRATIONRECORD                            //~v053I~
   	{                                                              //~v053I~
		UEXCEPTIONHANDLER            UExceptionHandler;            //~v053I~
		SignalHandler                *PPrevSignalHandler;          //~v053I~
   };                                                              //~v053I~
#else                       //not DPMI                             //~v053I~
#endif                      //DPMI or not                          //~v053I~
                                                                   //~v022I~
//***************************************************************  //~v022M~
//* parameter control block
typedef struct _UEXREGREC{
        EXCEPTIONREGISTRATIONRECORD
						UERGsys;  /*system record*/
//***********************************
//*input section(caller must setup)
//***********************************
        int             UERGheapsize;//initial heap size by 64k byte 
        UCHAR          *UERGmapfn;		//map file name
        UCHAR          *UERGdumpfn;		//dump filename
void             		(*UERGuxfunc)(int,struct _UEXREGREC*);//exit func
//****                  parm1:0-call at entry to E.H
//****                       :2-call at exit from E.H
		PVOID           UERGparm;		//user parm to exit func
//*****************************************************
//*internal use section
//*****************************************************
        int             UERGflag; /*ueh control*/
#define UERGFEHACT      0x40000000        //exception handler activ
#define UERGFENQ 		0x20000000		  //e.h in progress
#define UERGFENTRY 		0x10000000		  //e.h once entered
#define UERGFEHINP		0x08000000		 //in progress
#define UERGFEHINP		0x08000000		 //in progress
#define UERGFDUMPED  	0x04000000		//once dump taken
#define UERGFNODUMP  	0x02000000		//once dump taken
#define UERGFDUMPERR  	0x01000000		//once dump taken
                                                                   //~v022I~
#ifdef W32  //copy from f:\toolkt21\c\os2h\bsexcpt.h               //~v022I~
        FILE 			*UERGdumpfh;	//FILE                     //~v022I~
#else                                                              //~v022I~
//  #ifdef DPMI					//DPMI version                     //~v324R~
    #if defined(DPMI) || defined(UNX)					//DPMI version//~v324R~
        FILE 			*UERGdumpfh;	//FILE                     //~v053I~
    #else                       //not DPMI                         //~v053I~
        ULONG           UERGdumpfh;		//HFILE
    #endif                      //DPMI or not                      //~v053I~
#endif                                                             //~v022I~
                                                                   //~v022I~
        int 			UERGentryctr;//entry count
        UINT 			UERGthreadid;//thread id
} UEXREGREC;

typedef UEXREGREC*  PUEXREGREC;
#define UEXREGRECSZ (sizeof(UEXREGREC))
//************************************
//* parm :user exception registration record addr
//* return:none
//************************************
void useteh(PUEXREGREC);/*exception handler set*/
void ureseteh(PUEXREGREC);/*exception handler unset*/

