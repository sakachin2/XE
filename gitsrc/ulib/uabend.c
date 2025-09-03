//CID://+v6hhR~:          update#=      4 1                        //~v6hhR~
// *******************************************************************
// * uabend                                                     //~5124R~
// *******************************************************************//~5124I~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v358:000927 LINUX support(use abort for uabend to take core)     //~v358I~
//v327 000820:LINUX support                                        //~v327I~
//v059:970201:use unsigned int for UINT                            //~v059I~
//v053:970107:gcc version(control by DPMI)                         //~v053I~
//            -use raise for abort(in DOS native raise dose not cause exit)//~v053I~
//v022:960727:WIN32(CONSOLE api)                                   //~v022I~
// *     930124   :a.s:for nmake,avoid '//*'                          *
// *******************************************************************

#include <time.h>                                               //~5124I~
#include <stdio.h>                                              //~5124I~
#include <stdlib.h>                                             //~5124I~
#include <ctype.h>                                              //~5124I~
#include <string.h>                                             //~5124I~
#include <stdarg.h>                                             //~5124I~
                                                                //~5124I~
#ifdef UNX                                                         //~v327I~
	#include <signal.h>                                            //~v327I~
#else                                                              //~v327I~
#ifdef DOS                                                      //~5124I~
	#include <signal.h>                                            //~v059I~
#else                                                           //~5124I~
    #ifdef W32                                                     //~v022I~
		#include <windows.h>                                       //~v022I~
//copyed from f:\toolkt21\c\os2h\bsexcpt.h                         //~v022I~
        #define XCPT_FATAL_EXCEPTION    0xC0000000                 //~v022I~
        #define XCPT_CUSTOMER_CODE      0x20000000                 //~v022I~
    #else                                                          //~v022I~
	#define INCL_BASE                                           //~5124I~
	#define INCL_DOSEXCEPTIONS //for DosRaiseException          //~5124I~
	#include <os2.h>                                            //~5124I~
	#endif                                                         //~v022I~
#endif                                                          //~5124I~
#endif                                                             //~v327I~
//*******************************************************       //~5124I~
#include <ulib.h>                                               //~5124I~
#include <uabend.h>                                             //~5124I~
#include <utrace.h>                                                //+v6hhI~

//***************************************************************//~5124R~
//* uabend                                                      //~5124R~
//* INPUT      :                                                //~5124R~
//      p1:abend code
//      p2:abend information-1
//      p3:abend information-2
//      p4:abend information-3
//*****************************************************************//~5124R~
void uabend(unsigned int perrno,unsigned long p1,unsigned long p2,unsigned long p3)//~v059I~
{                                                               //~5124R~
//#ifdef DOS                                                       //~v327R~
#if defined(DOS)||defined(UNX)                                     //~v327I~
	printf("\nuabend:err code=%d,p1=%08lX,p2=%08lX,p3=%08lX\n", //~5204R~
			perrno,p1,p2,p3);                                   //~5124I~
    #ifdef DPMI					//DPMI version                     //~v053I~
	    raise(SIGUSR1);                                            //~v053I~
    #else                       //not DPMI                         //~v053I~
	    abort();
    #endif                      //DPMI or not                      //~v053I~
#else                                                           //~5124I~
    #ifdef W32                                                     //~v022I~
        DWORD   code;                                              //~v022I~
//  	DWORD	exarg[EXCEPTION_MAXIMUM_PARAMETERS];               //~v022I~//~v6hhR~
    	ULPTR	exarg[EXCEPTION_MAXIMUM_PARAMETERS];               //~v6hhI~
//********************************************                     //~v022I~
        UTRACEP("%s:errno=%d,p1=%p,p2=%p,p3=%p\n",UTT,perrno,p1,p2,p3);//~v6hhI~
		_flushall();                                               //~v6hhI~
        code=XCPT_FATAL_EXCEPTION | XCPT_CUSTOMER_CODE;            //~v022I~
       	exarg[0]=perrno;                                           //~v022R~
       	exarg[1]=p1;                                               //~v022I~
       	exarg[2]=p2;                                               //~v022R~
       	exarg[3]=p3;                                               //~v022R~
       	RaiseException(code,                                       //~v022R~
						EXCEPTION_NONCONTINUABLE,                  //~v022I~
						4,                                         //~v022R~
                        exarg);                                    //~v022I~
    #else                                                          //~v022I~
	EXCEPTIONREPORTRECORD exreprec;                             //~5124R~
//********************************************                  //~5124R~
   	exreprec.ExceptionNum=XCPT_FATAL_EXCEPTION | XCPT_CUSTOMER_CODE;//~5124R~
   	exreprec.fHandlerFlags=EH_NONCONTINUABLE;                   //~5124R~
   	exreprec.NestedExceptionReportRecord=NULL;                  //~5124R~
   	exreprec.ExceptionAddress                                   //~5124R~
   	  =(void*)( *( (UINT*)&perrno-1 ) );/*next of call uabend*/ //~5124R~
   	exreprec.cParameters=4L;          //ExceptionInfo efective count//~5124R~
   	exreprec.ExceptionInfo[0]=perrno;                           //~5124R~
   	exreprec.ExceptionInfo[1]=p1;                               //~5124R~
   	exreprec.ExceptionInfo[2]=p2;                               //~5124R~
   	exreprec.ExceptionInfo[3]=p3;                               //~5124R~
   	/*****/                                                     //~5124R~
   	DosRaiseException(&exreprec);                               //~5124R~
	#endif                                                         //~v022I~
#endif                                                          //~5124I~
	return;                                                     //~5124I~
}
