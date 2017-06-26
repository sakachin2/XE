//*CID://+v6u9R~:                             update#=   21;       //+v6u9R~
//*************************************************************    //~8308I~
//*uregex.c                                                        //~8308I~
//gnu regex 2.7 compile ****                                       //~v5mhM~
//*************************************************************    //~8308I~
//v6u9:140408 (Win)use UNICODE Api using special filename fmt.     //+v6u9I~
//v6a0:110520 Android porting(-DARM)                               //~v6a0I~
//v5mM:080723 (VC8)compile err,because errcode is typedef name     //~v5mMI~
//v5mn:080323 regex GCC support                                    //~v5mnI~
//v5mk:080312 regex OS/2 support                                   //~v5mkI~
//v5mh:080308 (W32)regex support using GNU regex v2.7.             //~v5mhI~
//*************************************************************    //~v5mhI~
                                                                   //~8306I~
#include <stddef.h>                                                //~8308I~
//#ifndef OS2                                                      //~v5mnR~
#if defined(LNX) || defined(W32)                                   //~v5mnI~
	#ifndef ARM                                                    //~v6a0I~
#include <wtypes.h>                                                //~8308I~
    #endif                                                         //~v6a0I~
#endif                                                             //~v5mkI~
#include <malloc.h>                                                //~8308I~
//**************************                                       //~v5mkI~
//**************************                                       //~8308I~
#ifdef W32                                                         //+v6u9I~
	#define NO_MACRO_REDIRECT //for ulibdefw.h macro redirection   //+v6u9I~
#endif                                                             //+v6u9I~
#include <ulib.h>                                                  //~8308I~
//**************************                                       //~8308I~
#define bool       long                                            //~8308I~
#define true       TRUE                                            //~8308I~
#define false      FALSE                                           //~8308I~
//#ifdef OS2                                                       //~v5mnR~
#if defined(LNX)||defined(W32)                                     //~v5mnI~
	#ifdef ARM                                                     //~v6a0I~
		#define TRUE  1                                            //~v6a0I~
		#define FALSE 0                                            //~v6a0I~
    #endif                                                         //~v6a0I~
#else                                                              //~v5mnI~
	#define TRUE  1                                                //~v5mkM~
	#define FALSE 0                                                //~v5mkM~
#endif                                                             //~v5mkI~
#define strcasecmp stricmp                                         //~8308I~
#define REGEX_STATIC    //static library                           //~8308I~
//**************************                                       //~8306I~
#ifdef XYZ                     //FALSE but for depgen              //~v5mMR~
	#include "gnuregex/re_comp.h"                                  //~v5mMR~
	#include "gnuregex/regcomp.c"                                  //~v5mMR~
	#include "gnuregex/regex.h"                                    //~v5mMR~
	#include "gnuregex/regex_internal.c"                           //~v5mMR~
	#include "gnuregex/regex_internal.h"                           //~v5mMR~
	#include "gnuregex/regexec.c"                                  //~v5mMR~
#endif                                                             //~v5mMI~
#include "gnuregex/regex.c"                                        //~v5mkR~
