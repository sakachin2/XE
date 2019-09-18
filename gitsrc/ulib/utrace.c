//*CID://+v6VuR~:                              update#=  111;      //~v6VuR~
//***********************************************************************//~v026I~
//* utrace.c                                                       //~v022R~
//***********************************************************************
//v6Vu:180622 UTRACE;support force option off                      //~v6VuI~
//v6Vi:180617 support __LINE__ for UTRACEP                         //~v6ViI~
//v6J6:170209 UTRACED 64bit addr                                   //~v6B1I~
//v6B1:160114 trace,mtrace file no share mode                      //~v6B1I~
//v6u9:140408 (Win)use UNICODE Api using special filename fmt.     //~v6u9I~
//v6p1:130916 (LNX:XXE)dispaly thredid on trace                    //~v6p1I~
//v6hr:120713 Warning C4305 truncation from CREITICAL_SECTION* to ULONG//~v6hrI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6b6:110829 timestamp to trace open msg                          //~v6b6I~
//v6a0:110520 Android porting(-DARM)                               //~v6a0I~
//v690:100701 m62(LP64:: int:32, long,void*:64) support (__LP64_)  //~v690I~
//v63e:100206 utrace skip dump if addr is null                     //~v63eI~
//v5nD:090329 S390 support                                         //~v5nDI~
//v5ny:081129 (BUG)UTRACEP top \n should be written before timestamp//~v5nyI~
//v5nx:081129 avoid redundant link; utrace:no MTTRACE              //~v5nxI~
//v5nc:081009 (LNX)MinGW compile                                   //~v5ncI~
//v5ja:060921 (LNX)3270 support                                    //~v5jaI~
//v5j0:060911 (WIN)utrace multi thread support                     //~v5j0I~
//v5cb:040406 (BUG)utrace funcname top 1 byte dropped              //~v5cbI~
//v57v:030126 (DOS)move utracepnop to another mdule for DOS memory shortage//~v57vI~
//v57b:021214 utrace fmt chng(time stamp for UTRACEP)              //~v57bI~
//v352:000926 LINUX support(permission err msg)                    //~v352I~
//v345:000925 LINUX support(month:tm_mon start from 0)             //~v345I~
//v336 000904:LINUX support(UNIX but LINUX addr is little endian)  //~v336I~
//v330 000820:LINUX support(dir seperator "/")                     //~v330I~
//v322:000223 EBCDIC code dump suppot(UTRACED_EBC macro)           //~v322R~
//v323:000222 stdout/stderr support by filename "stdout" or "stderr"//~v321R~
//v321 000729:UNIX support                                         //~v321I~
//v101:971009 long filename                                        //~v101I~
//            utrace.c:trace filename,up to maxpath                //~v101I~
//v053:970107:gcc version(control by DPMI)                         //~v053I~
//            -char array index generates warning                  //~v053I~
//            -printf ptr parm to int format generates warning     //~v053I~
//            -size_t unsigned int-->long int,int 2-->4 byte       //~v053I~
//            -errno need errno.h                                  //~v053I~
//            -ptr is 4 byte near ptr                              //~v053I~
//v048:961201:force open after once open if trace file name is specified.//~v048I~
//            First is implicitly called foor stdout before utrace_init call.//~v048I~
//v041:961027:UTRACEP NOTRACE option                               //~v041I~
//v026:960901:display offset of seg:off for DOS utrace             //~v026I~
//v022:960727:WIN32(CONSOLE api)                                   //~v022I~
//v014:960203:printf format UTRACEP                             //~6203R~
//*950829 uerrmsg/uerrexit-->printf and exit to avoid many link sub//~5829I~
//*       trace close function by utrace init                   //~5829I~
//*       integer trace for os2(4 byte integer)                 //~5829I~
//*950807 ignore open err option for trace init                 //~5807I~
//*950806 bug,for os2 datetime api not issued(issued only first time)//~5806I~
//***********************************************************************//~5806I~
// UTRCAEI/UTRACED/UTRACES/UTRACEOPT macro process
//***********************************************************************
// FORMAT(changed #019)
//   UTRACEI(comment,int)       //integer or char trace
//     -->   utrace(__FILE__,__LINE__,'i',comment,int,0);
//   UTRACES(comment,string,len)    //string trace
//     -->   utrace(__FILE__,__LINE__,'s',comment,string,len);//len parm may be 0(use strlen)
//   UTRACED(comment,addr,len)  //area dump trace
//     -->   utrace(__FILE__,__LINE__,'d',comment,addr,len);
//   rc=UTRACE_INIT(trace_file_name,option) //trace option set  //~5829R~
//       (option==>0:inactive, 1:active, 2:ignore open err,3 inact and close)//~5829I~
//       (rc    ==>0:open ok,  else:errno for option=2)         //~5829I~
//     -->rc=utrace_init(__FILE__,__LINE__,'d',trace_file_name,option);//~5829I~
//***********************************************************************

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>                                             //~6203I~
#ifdef UNX                                                         //~v321R~
    #include <errno.h>                                             //~v321R~
    #include <time.h>                                              //~v321R~
    #include <sys/timeb.h>                                         //~v321R~
  #ifdef ARM                                                       //~v6a0I~
//  #include <sys/syscall.h>                                       //~v6a0R~
    #include <pthread.h>                                           //~v6a0I~
  #endif                                                           //~v6a0I~
  #ifdef LNX                                                       //~v5jaI~
//  #ifndef NOMT                                                   //~v5nxR~
  #ifndef NOMT_TRACE                                               //~v5nxI~
    #include <pthread.h>                                           //~v5jaI~
  #endif                                                           //~v5ncI~
    #include <unistd.h>                                            //~v6p1R~
    #include <sys/syscall.h>                                       //~v6p1I~
    #include <sys/types.h>                                         //~v6p1I~
  #endif                                                           //~v5jaI~
#else                                                              //~v321R~
#include <time.h>
#ifdef DPMI                 //DPMI version                         //~v053I~
    #include <errno.h>                                             //~v053I~
#else                       //not DPMI                             //~v053I~
#endif                      //DPMI or not                          //~v053I~

#ifdef DOS 
#include <dos.h>
//#define ULONG unsigned long int                                  //~v022R~
//#define UCHAR unsigned char                                      //~v022R~
//#define UINT  unsigned int                                       //~v022R~
#else
    #ifdef W32                           //v3.6a                   //~v022I~
        #include <windows.h>                                       //~v022I~
    #else                                //v3.6a                   //~v022I~
#define INCL_BASE
#include <os2.h>
    #endif                                                         //~v022I~
#endif
#endif                                                             //~v321R~
                                                                   //~v321R~

#define NO_MACRO_REDIRECT //loop if redirectb UTRACE macro in ufopenW//~v6u9R~
#include <ulib.h>                                                  //~v022I~
#include <uerr.h>
#define GBL_UTRACE  //define global variable                       //~v6ViI~
#include <utrace.h>                                             //~5829I~
#include <uproc2.h>                                                //~v5j0R~
#include <ufile.h>                                                 //~v6B1I~
#include <ufile2.h>                                                //~v6B1I~

//****************************************************************
#ifdef DOS                                                         //~v026I~
  #ifdef DPMI                   //DPMI version                     //~v053I~
    #define FP_OFF_SZ   0                                          //~v053I~
  #else                       //not DPMI                           //~v053I~
    #define FP_OFF_SZ   9                                          //~v026R~
  #endif                      //DPMI or not                        //~v053I~
#else                                                              //~v026I~
    #define FP_OFF_SZ   0                                          //~v026I~
#endif                                                             //~v026I~
#define MAXSTRLEN 128
#define LINEADDRPOS  0        //storage addr colomn
#if defined(ULIB64) || defined(ULIB64X)                            //~v6J6R~
	#define LINEHEXPOS   (8+9+FP_OFF_SZ)        //hex dump start colomn//~v6J6R~
#else                                                              //~v6J6R~
#define LINEHEXPOS   9+FP_OFF_SZ        //hex dump start colomn    //~v026R~
#endif                                                             //~v6J6R~
//****************************************************************
//#ifdef W32                                                       //~v5jaR~
#if defined(W32)||defined(LNX)                                     //~v5jaI~
//#ifdef NOMT                                                      //~v5nxR~
  #ifdef NOMT_TRACE                                                //~v5nxI~
	#define LOCK_ENTER()                                           //~v5ncI~
	#define LOCK_LEAVE()                                           //~v5ncI~
  #else                                                            //~v5ncI~
	#define LOCK_ENTER()    if (Sseminitsw) {   \
												 ucriticalsection(CRITSEC_ENTER,(/*ULONG*/ULPTR)Spsem); \
											}                      //~v5j0I~
	#define LOCK_LEAVE()    if (Sseminitsw) {   \
												if (Sfile)	\
 													fflush(Sfile); \
												 ucriticalsection(CRITSEC_LEAVE,(/*ULONG*/ULPTR)Spsem); \
											}                      //~v5j0I~
  #endif //!NOMT                                                   //~v5ncI~
#endif                                                             //~v5j0I~
//****************************************************************//~6203I~
    static FILE *Sfile=0;           //handle                    //~6203I~
    static FILE *Sfile_force=0;           //handle                 //~v6VuI~
#ifdef W32                                                         //~v6B1I~
	HANDLE Slockhandle;                                            //~v6B1I~
#else                                                              //~v6B1I~
	int    Slockhandle;                                            //~v6B1I~
#endif                                                             //~v6B1I~
    static char Sutracefilename[_MAX_PATH]="utrace.out";           //~v101R~
    static char Sutracefilename_force[_MAX_PATH];                  //~v6VuI~
    static int Sutraceopt=1;
    static int Sswputforce;                                        //~v6VuI~
    static int Sswnoforce=0;                                       //~v6VuI~
    static int Sswnoshare=0;                                       //~v6B1I~
    static int Sebcsw;                                             //~v322R~
    static int  Dumpboundary=1;    //domp boundary is 4 byte
    static UCHAR* Samestart=0;         //Same line start addr value
    static char  Line    [133];      //print line                  //~v022R~
    static char  Sameline[133];      //same as above line          //~v022R~
    static UCHAR Samesave[16];     //same chk dump data save
#if defined(ULIB64) || defined(ULIB64X)                            //~v6J6R~
    static int   Linewidth=(8+67+FP_OFF_SZ-2);        //colomn per line//~v6J6R~
    static int   Linecharpos=(8+50+FP_OFF_SZ-2);       //char dump colomn in line//~v6J6R~
#else                                                              //~v6J6R~
    static int   Linewidth=67+FP_OFF_SZ-2;        //colomn per line//~v026R~
    static int   Linecharpos=50+FP_OFF_SZ-2;       //char dump colomn in line//~v026R~
#endif                                                             //~v6J6R~
//fdef W32                                                         //~v5jaR~
#if defined(W32)||defined(LNX)                                     //~v5jaI~
//ifndef NOMT                                                      //~v5nxR~
 #ifndef NOMT_TRACE                                                //~v5nxI~
  #ifdef W32                                                       //~v5jaI~
	static CRITICAL_SECTION *Spsem;	//multithread semaphore ptr    //~v5j0R~
	static CRITICAL_SECTION Ssem;	//multithread semaphore        //~v5j0I~
  #else                                                            //~v5jaI~
	static pthread_mutex_t *Spsem;                                 //~v5jaR~
	static pthread_mutex_t Ssem=PTHREAD_MUTEX_INITIALIZER;	//multithread semaphore//~v5jaI~
  #endif                                                           //~v5jaI~
    static int Sseminitsw=0;                                       //~v5j0I~
 #endif //!NOMT                                                    //~v5ncM~
    static int Slockgotten=0;	//protect deadlock                 //~v5j0I~
#endif                                                             //~v5j0I~

static int utraceopen(void);                                    //~5829I~
static void utraceocmsg(char *Pmsg);                               //~v022R~
static void   putline(char *,int);
static void   printdump(void *,int,void*);
static int typechk(char,char);  //char type  chk
char *utracectime(void);                                           //~v57bR~
int utraceopen_force(void);                                        //~v6VuI~
void utraceocmsg_force(char *Pmsg);                                //~v6VuI~
//#ifdef W32                                                       //~v5jaR~
#if defined(W32)||defined(LNX)                                     //~v5jaI~
//#ifndef NOMT                                                     //~v5nxR~
  #ifndef NOMT_TRACE                                               //~v5nxI~
//**************************************************************** //~v5j0I~
//*share multithread semaphore with other pgm                      //~v5j0I~
//*rc:4 not multithred library(compile option invalid)             //~v5j0I~
//**************************************************************** //~v5j0I~
int utrace_initmt(void *Ppsem)                                     //~v5j0I~
{                                                                  //~v5j0I~
	int rc;                                                        //~v5j0I~
//*****************                                                //~v5j0I~
//  #ifdef _MT	//compile option /MT(d)                            //~v5jaR~
    #if defined(_MT)|| defined(LNX)	//compile option /MT(d)        //~v5jaI~
      #ifdef LNX                                                   //~v5jaI~
		Spsem=(pthread_mutex_t*)Ppsem;                             //~v5jaI~
      #else                                                        //~v5jaI~
		Spsem=(CRITICAL_SECTION*)Ppsem;                            //~v5j0R~
      #endif                                                       //~v5jaI~
//  	ucriticalsection(CRITSEC_INIT,(ULONG)Spsem);               //~v6hrR~
    	ucriticalsection(CRITSEC_INIT,(ULPTR)Spsem);               //~v6hrI~
    	Sseminitsw=1;                                              //~v5j0R~
        rc=0;                                                      //~v5j0I~
    #else                                                          //~v5j0I~
    	rc=4;                                                      //~v5j0I~
	#endif                                                         //~v5j0M~
    return rc;                                                     //~v5j0R~
}                                                                  //~v5j0I~
  #endif //!NOMT                                                   //~v5ncI~
#endif                                                             //~v5j0I~
//****************************************************************
//*parm1 :trace file name
//*parm2 :trace option  0:inactive, 1:active, 2:ignore open err //~5807R~
//*ret   :open rc;                                              //~5829I~
//****************************************************************
int utrace_init(char *Putracefile,int Popt)                     //~5829R~
{
    int rc=0;                                                   //~5829R~
//#ifdef ARM                                                         //~v6a0I~//~v6b6R~
//    int optlogcat;                                                 //~v6a0I~//~v6b6R~
//#endif //ARM                                                       //~v6a0I~//~v6b6R~
//********************                                          //~5829I~
	Sswnoshare=0;                                                  //~v6B1I~
#ifndef ARM                                                        //~v6VuI~
	if (Popt & UTRACEO_FORCEFNM)                                   //~v6VuI~
    {                                                              //~v6VuI~
        strncpy(Sutracefilename_force,Putracefile,_MAX_PATH-1);    //~v6VuI~
        return 0;                                                  //~v6VuR~
    }                                                              //~v6VuI~
#endif                                                             //~v6VuI~
	if (Popt & UTRACEO_NOFORCE)                                    //~v6VuI~
    {                                                              //~v6VuI~
    	Sswnoforce=1;                                              //~v6VuI~
        Popt &=~UTRACEO_NOFORCE;                                   //~v6VuI~
    }                                                              //~v6VuI~
	if (Popt & UTRACEO_NOSHARE)                                    //~v6B1I~
    {	                                                           //~v6B1I~
    	Sswnoshare=1;                                              //~v6B1I~
        Popt &=~UTRACEO_NOSHARE;                                   //~v6B1I~
    }                                                              //~v6B1I~
//#ifdef W32                                                       //~v5jaR~
#if defined(W32)||defined(LNX)                                     //~v5jaR~
//#ifndef NOMT                                                     //~v5nxR~
  #ifndef NOMT_TRACE                                               //~v5nxI~
    if (Popt & UTRACEO_MT)                                         //~v5j0R~
        utrace_initmt(&Ssem);                                      //~v5j0R~
  #endif //!NOMT                                                   //~v5ncI~
#endif                                                             //~v5j0I~
    if (Putracefile
    &&  *Putracefile)
//      strcpy(Sutracefilename,Putracefile);                       //~v101R~
        strncpy(Sutracefilename,Putracefile,_MAX_PATH-1);          //~v101R~
#ifdef ARM                                                         //~v6a0I~
    if (Popt & UTRACEO_TEMPCLOSE)                                  //~v6a0R~
    {                                                              //~v6a0I~
    	Sutraceopt=0;                                              //~v6a0R~
        return 0;                                                  //~v6a0I~
    }                                                              //~v6a0I~
    if (Popt & UTRACEO_REOPEN)                                     //~v6a0R~
    {                                                              //~v6a0I~
        if (!Sfile && *Sutracefilename)                            //~v6a0R~
			utraceopen();                                          //~v6a0I~
    	Sutraceopt=UTRACEO_ON|(Popt & UTRACEO_LOGCAT);             //~v6b6R~
        return 0;                                                  //~v6a0I~
    }                                                              //~v6a0I~
#endif                                                             //~v6a0I~
    if (Popt==3)    //close and trace off                       //~5829I~
    {                                                           //~5829I~
        Popt=0;                                                 //~5829I~
        if (Sfile)  //file opened                               //~6203R~
        {                                                       //~5829I~
            utraceocmsg("TRACE CLOSE AT");                      //~5829I~
          if (Sfile!=stdout && Sfile!=stderr)                      //~v323R~
            fclose(Sfile);                                      //~6203R~
            Sfile=0;                                            //~6203R~
          	if (Sfile_force)                                       //~v6VuI~
            	fclose(Sfile_force);                               //~v6VuI~
            Sfile_force=0;                                         //~v6VuI~
        }                                                       //~5829I~
    }                                                           //~5829I~
//#ifdef ARM                                                         //~v6a0I~//~v6b6R~
//    optlogcat=Sutraceopt & UTRACEO_LOGCAT;                         //~v6a0I~//~v6b6R~
//#endif //ARM                                                       //~v6a0I~//~v6b6R~
    Sutraceopt=Popt;
#ifdef ARM                                                         //~v6a0I~
//    if (Sutraceopt)                                                //~v6a0I~//~v6b6R~
//        Sutraceopt|=optlogcat;                                     //~v6a0R~//~v6b6R~
    LOGPD("utrace_init opt=%x",Sutraceopt);                        //~v6a0R~
#endif //ARM                                                       //~v6a0M~
//  if (Sutraceopt && !Sfile)   //init and not yet opened          //~v048R~
    if (Sutraceopt          //init                                 //~v048I~
    &&  Putracefile                                                //~v048I~
    &&  *Putracefile)                                              //~v048I~
    {                                                              //~v048I~
        if (Sfile)                                                 //~v048I~
        {                                                          //~v048I~
          if (Sfile!=stdout && Sfile!=stderr)                      //~v323R~
            fclose(Sfile);                                         //~v048I~
            Sfile=0;                                               //~v048I~
        }                                                          //~v048I~
        rc=utraceopen();                                        //~5829I~
    }                                                              //~v048I~
    return rc;                                                  //~5829R~
}//utrace_init                                                   //~5829R~//~v6a0R~
                                                                //~6203I~
//****************************************************************//~6203I~
//* printf format trace                                         //~6203I~
//*parm1 :printf format                                         //~6203I~
//*parm2-:printf data                                           //~6203I~
//****************************************************************//~6203I~
void utracepop(char *Pfmt,...)                                     //~v041R~
{                                                               //~6203I~
    va_list argptr;                                             //~6203I~
    int topcrlfctr=0;                                              //~v5nyI~
    char *pc;                                                      //~v5nyI~
//***********************************                           //~6203I~
    if (!Sutraceopt)                                            //~6203I~
         return;                                                //~6203I~
//#ifdef W32                                                       //~v5jaR~
#if defined(W32)||defined(LNX)                                     //~v5jaR~
    LOCK_ENTER()                                                   //~v5j0I~
#endif                                                             //~v5j0I~
    if (!Sfile)                                                 //~6203I~
        utraceopen();                                           //~6203I~
    for (pc=Pfmt;*pc=='\n';pc++)                                   //~v5nyI~
    {                                                              //~v5nyI~
    	topcrlfctr++;                                              //~v5nyI~
    	fprintf(Sfile,"\n");                                       //~v5nyI~
    }                                                              //~v5nyI~
    fprintf(Sfile,"= %s = ",utracectime());                        //~v57bR~
    va_start(argptr,Pfmt);  //addr of stack parm next of Pfmt   //~6203R~
//  vfprintf(Sfile,Pfmt,argptr);                                //~6203I~//~v5nyR~
    vfprintf(Sfile,Pfmt+topcrlfctr,argptr);                        //~v5nyI~
#ifdef ARM                                                         //~v6a0I~
    if (Sutraceopt & UTRACEO_LOGCAT)                               //~v6b6R~
    {                                                              //~v6b6R~
		__android_log_vprint(ANDROID_LOG_DEBUG,"UTRACEP",Pfmt+topcrlfctr,argptr);//~v6a0I~
    }                                                              //~v6b6R~
#endif //ARM                                                       //~v6a0I~
    va_end(argptr);                                                //~v5nDI~
//#ifdef W32                                                       //~v5jaR~
#if defined(W32)||defined(LNX)                                     //~v5jaR~
    LOCK_LEAVE()                                                   //~v5j0I~
#endif                                                             //~v5j0I~
    return;                                                     //~6203I~
}//utracepop                                                       //~v041R~
//**************************************************************** //~v6b6I~
//* printf format trace regardless trace option for elapsed time chk//~v6b6I~
//**************************************************************** //~v6b6I~
void utracepopf(char *Pfmt,...)                                    //~v6b6I~
{                                                                  //~v6b6I~
    va_list argptr;                                                //~v6b6I~
    int topcrlfctr=0;                                              //~v6b6I~
    char *pc;                                                      //~v6b6I~
    FILE* pfh;                                                     //~v6VuI~
//***********************************                              //~v6b6I~
//    if (!Sutraceopt)                                             //~v6b6I~
//         return;                                                 //~v6b6I~
#if defined(W32)||defined(LNX)                                     //~v6b6I~
    LOCK_ENTER()                                                   //~v6b6I~
#endif                                                             //~v6b6I~
    if (Sswnoforce)                                                //~v6VuR~
        return;                                                    //~v6VuI~
  if (*Sutracefilename_force)                                      //~v6VuI~
  {                                                                //~v6VuI~
    if (!Sfile_force)                                              //~v6VuI~
        utraceopen_force();                                        //~v6VuI~
    pfh=Sfile_force;                                               //~v6VuI~
  }                                                                //~v6VuI~
  else                                                             //~v6VuI~
  {                                                                //~v6VuI~
    if (!Sfile)                                                    //~v6b6I~
        utraceopen();                                              //~v6b6I~
    pfh=Sfile;                                                     //~v6VuI~
  }                                                                //~v6VuI~
  	if (!pfh)                                                      //~v6VuI~
    	return;                                                    //~v6VuI~
    for (pc=Pfmt;*pc=='\n';pc++)                                   //~v6b6I~
    {                                                              //~v6b6I~
    	topcrlfctr++;                                              //~v6b6I~
//  	fprintf(Sfile,"\n");                                       //~v6b6I~//~v6VuR~
    	fprintf(pfh,"\n");                                         //~v6VuI~
    }                                                              //~v6b6I~
//  fprintf(Sfile,"= %s = ",utracectime());                        //~v6b6I~//~v6VuR~
    fprintf(pfh,"= %s = ",utracectime());                          //~v6VuI~
    va_start(argptr,Pfmt);  //addr of stack parm next of Pfmt      //~v6b6I~
//  vfprintf(Sfile,Pfmt+topcrlfctr,argptr);                        //~v6b6I~//~v6VuR~
    vfprintf(pfh,Pfmt+topcrlfctr,argptr);                          //~v6VuI~
#ifdef ARM                                                         //~v6b6I~
    if (Sutraceopt & UTRACEO_LOGCAT)                               //~v6b6I~
    {                                                              //~v6b6I~
		__android_log_vprint(ANDROID_LOG_DEBUG,"UTRACEP",Pfmt+topcrlfctr,argptr);//~v6b6I~
    }                                                              //~v6b6I~
#endif //ARM                                                       //~v6b6I~
    va_end(argptr);                                                //~v6b6I~
#if defined(W32)||defined(LNX)                                     //~v6b6I~
    LOCK_LEAVE()                                                   //~v6b6I~
#endif                                                             //~v6b6I~
    return;                                                        //~v6b6I~
}//utracepopf                                                      //~v6b6I~
                                                                   //~v041I~
#ifdef DOSDOS       //for native dos utracedmy.c is included       //~v57vI~
#else                                                              //~v57vI~
//**************************************************************** //~v041I~
//* printf format trace nop mode                                   //~v041I~
//*parm1 :printf format                                            //~v041I~
//*parm2-:printf data                                              //~v041I~
//**************************************************************** //~v041I~
void utracepnop(char *Pfmt,...)                                    //~v041I~
{                                                                  //~v041I~
//***********************************                              //~v041I~
    return;                                                        //~v041I~
}//utracepnop                                                      //~v041I~
#endif                                                             //~v57vI~
                                                                   //~v041I~
void utrace_ebc(char * Pfile,int Pline,int Ptype,char *Pcomment,void *Paddr,int Plen)//~v322R~
{                                                                  //~v322R~
//#ifdef W32                                                       //~v5jaR~
#if defined(W32)||defined(LNX)                                     //~v5jaR~
    LOCK_ENTER()                                                   //~v5j0I~
    Slockgotten=1;	//protect deadlock                             //~v5j0M~
#endif                                                             //~v5j0I~
    Sebcsw=1;                                                      //~v322R~
    utrace(Pfile,Pline,Ptype,Pcomment,Paddr,Plen);                 //~v322R~
    Sebcsw=0;                                                      //~v322R~
//#ifdef W32                                                       //~v5jaR~
#if defined(W32)||defined(LNX)                                     //~v5jaR~
    Slockgotten=0;                                                 //~v5j0M~
    LOCK_LEAVE()                                                   //~v5j0I~
#endif                                                             //~v5j0I~
}                                                                  //~v322R~
//****************************************************************
//*parm1 :source file name
//*parm2 :source file line
//*parm3 :trace type
//*          i:integer/char trace--output by hex,decimal and char
//*          s:string trace      --output by string
//*          d:dump trace        --output by dump(hex and char)
//*parm4:comment string
//*parm5:value for 'i' type
//*     :addr  for 's' type
//*     :addr  for 'd' type
//*parm6:always 0 for 'i' type
//*     :len      for 's' type(it may be 0)
//*     :len      for 'd' type
//****************************************************************
void utrace (char * Pfile,int Pline,int Ptype,char *Pcomment,void *Paddr,int Plen)
{
    char dump[80+MAXSTRLEN];             /* dump line */
    int nextpos;
    int len;
    int i;
    char c1,c2;
#ifdef UNX                                                         //~v321R~
//struct    timeb tb;      //time_t and milisec                    //~v57bR~
//struct    tm* ptm;       //date and time                         //~v57bR~
    char c3,c4;                                                    //~v321R~
#else                                                              //~v321R~
#ifdef DOS                      //v7.0a
  #ifdef DPMI                   //DPMI version                     //~v053I~
    char c3,c4;                                                    //~v053I~
  #else                       //not DPMI                           //~v053I~
  #endif                      //DPMI or not                        //~v053I~
//  union REGS reg;                                                //~v57bR~
#else
    char c3,c4;                                                 //~5829I~
    #ifdef W32                                                     //~v022M~
//      SYSTEMTIME      datetime;   //*hh,mm,ss,th,day,month,year,tz,dayofweek//~v57bR~
    #else                                                          //~v022M~
//  DATETIME      datetime;   //*hh,mm,ss,th,day,month,year,tz,dayofweek//~v57bR~
    #endif                                                         //~v022I~
#endif
#endif               //!UNX                                        //~v321R~
    char  *comm;
//***********************************
    if (!Sutraceopt)
         return;
//#ifdef W32                                                       //~v5jaR~
#if defined(W32)||defined(LNX)                                     //~v5jaR~
    if (!Slockgotten)	//protect deadlock                         //~v5j0I~
    {                                                              //~v5j0I~
    	LOCK_ENTER()                                               //~v5j0I~
    }                                                              //~v5j0I~
#endif                                                             //~v5j0I~
    if (!Sfile)                                                 //~6203R~
        utraceopen();                                           //~5829I~
//  for (i=(int)strlen(Pfile)-1;i>0;i--)                           //~v5cbR~
    for (i=(int)strlen(Pfile)-1;i>=0;i--)                          //~v5cbI~
#ifdef UNX                                                         //~v330I~
        if (*(Pfile+i)==DIR_SEPC)                                  //~v330I~
#else                                                              //~v330I~
        if (*(Pfile+i)=='\\'||*(Pfile+i)==':')
#endif                                                             //~v330I~
            break;
    comm=(Pcomment?Pcomment:"");    
#ifdef UNX                                                         //~v321R~
//    ftime(&tb);                                                  //~v57bR~
//    ptm=localtime(&tb.time);    //date and time                  //~v57bR~
//    nextpos=sprintf(dump,"=== %s-%4d (%2.2d:%2.2d:%2.2d.%3.3d) %s:",//~v57bR~
//            Pfile+i,Pline,                                       //~v57bR~
//            (int)ptm->tm_hour,                                   //~v57bR~
//            (int)ptm->tm_min,                                    //~v57bR~
//            (int)ptm->tm_sec,                                    //~v57bR~
//            (int)tb.millitm,                                     //~v57bR~
//            comm);                                               //~v57bR~
//  nextpos=sprintf(dump,"= %s = %-12s-%4d %s:",                   //~v57bR~//~v6ViR~
    nextpos=sprintf(dump,"= %s = %-12s-%d %s:",                    //~v6ViI~
            utracectime(),                                         //~v57bI~
            Pfile+i+1,Pline,                                       //~v57bR~
            comm);                                                 //~v57bI~
#else                                                              //~v321R~
#ifdef DOS                      //v7.0a
//    reg.h.ah=0x2c;      //get time                               //~v57bR~
//    intdos(&reg,&reg);                                           //~v57bR~
//    nextpos=sprintf(dump,"=== %s-%4d (%2.2d:%2.2d:%2.2d.%2.2d) %s:",//~v57bR~
//            Pfile+i,Pline,                                       //~v57bR~
//            reg.h.ch,reg.h.cl,reg.h.dh,reg.h.dl,                 //~v57bR~
//            comm);                                               //~v57bR~
    nextpos=sprintf(dump,"= %s = %-12s-%4d %s:",                   //~v57bR~
    		utracectime(),                                         //~v57bI~
            Pfile+i+1,Pline,                                       //~v57bR~
            comm);                                                 //~v57bI~
#else
    #ifdef W32                                                     //~v022I~
//      GetLocalTime(&datetime);                                   //~v57bR~
//      nextpos=sprintf(dump,"=== %s-%4d (%2.2d:%2.2d:%2.2d.%2.2d) %s:",//~v57bR~
//              Pfile+i,Pline,                                     //~v57bR~
//              (int)datetime.wHour,                               //~v57bR~
//              (int)datetime.wMinute,                             //~v57bR~
//              (int)datetime.wSecond,                             //~v57bR~
//              (int)datetime.wMilliseconds/10,                    //~v57bR~
//              comm);                                             //~v57bR~
//      nextpos=sprintf(dump,"= %s = %-12s-%4d %s:",               //~v57bR~//~v6ViR~
        nextpos=sprintf(dump,"= %s = %-12s-%d %s:",                //~v6ViI~
                utracectime(),                                     //~v57bI~
                Pfile+i+1,Pline,                                   //~v57bR~
                comm);                                             //~v57bI~
    #else                                                          //~v022I~
//  DosGetDateTime(&datetime);                                     //~v57bR~
//  nextpos=sprintf(dump,"=== %s-%4d (%2.2d:%2.2d:%2.2d.%2.2d) %s:",//~v57bR~
//          Pfile+i,Pline,                                         //~v57bR~
//          datetime.hours,                                        //~v57bR~
//          datetime.minutes,                                      //~v57bR~
//          datetime.seconds,                                      //~v57bR~
//          datetime.hundredths,                                   //~v57bR~
//          comm);                                                 //~v57bR~
    nextpos=sprintf(dump,"= %s = %-12s-%4d %s:",                   //~v57bR~
            utracectime(),                                         //~v57bI~
            Pfile+i+1,Pline,                                       //~v57bR~
            comm);                                                 //~v57bI~
    #endif                                                         //~v022I~
#endif
#endif  //!UNX                                                     //~v321R~


    switch (Ptype)
    {
    case 's':
        len=((Plen==0)?(int)strlen(Paddr):Plen);
        len=((len>MAXSTRLEN)?MAXSTRLEN:len);    
        memcpy(dump+nextpos,Paddr,(UINT)len);
        *(dump+nextpos+len)=0;
        strcat(dump,"\n");
        putline(dump,(int)strlen(dump));
        break;

    case 'i':
        c1=(char)(Plen>>8);
        c2=(char)(Plen&255);
        if (c1<' ')
            c1='.';
        if (c2<' ')
            c2='.';
//#ifdef DOS                    //v7.0a                            //~v053R~
#if defined(DOS) && !defined(DPMI)                                 //~v053I~
        sprintf(dump+nextpos," 0x%04X(%d,\"%c%c\")\n",             //~v053R~
                Plen,Plen,c2,c1);                               //~5829R~
#else                                                           //~5829I~
        c3=(char)(Plen>>24);                                    //~5829I~
        c4=(char)(Plen>>16);                                    //~5829I~
        if (c3<' ')                                             //~5829I~
            c3='.';                                             //~5829I~
        if (c4<' ')                                             //~5829I~
            c4='.';                                             //~5829I~
        sprintf(dump+nextpos," 0x%08X(%d,\"%c%c%c%c\")\n",         //~v053R~
                Plen,Plen,c2,c1,c4,c3);                         //~5829I~
#endif                                                          //~5829I~
        putline(dump,(int)strlen(dump));
        break;

    case 'd':
//#ifdef DOS                    //v7.0a                            //~v053R~
#if defined(DOS) && !defined(DPMI)                                 //~v053I~
        sprintf(dump+nextpos," ;ADDR=%p LEN=%04X(%5d)\n",
                Paddr,Plen,Plen);
#else
    #ifdef ULIB64                                                  //~v690I~
        sprintf(dump+nextpos," ;ADDR=%p LEN=%04X(%5d)\n",          //~v690I~
                Paddr,Plen,Plen);                                  //~v690I~
    #elif defined(ULIB64X)                                         //~v6hhR~
        sprintf(dump+nextpos," ;ADDR=%p LEN=%04X(%5d)\n",          //~v6hhI~
                Paddr,Plen,Plen);                                  //~v6hhI~
    #else                                                          //~v690I~
        sprintf(dump+nextpos," ;ADDR=%08X LEN=%04X(%5d)\n",
                (unsigned)Paddr,Plen,Plen);                        //~v053R~
    #endif                                                         //~v690I~
#endif
        putline(dump,(int)strlen(dump));
      if (Paddr)                                                   //~v63eI~
        printdump(Paddr,Plen,Paddr);
    }
//#ifdef W32                                                       //~v5jaR~
#if defined(W32)||defined(LNX)                                     //~v5jaR~
    if (!Slockgotten)	//protect deadlock                         //~v5j0I~
    {                                                              //~v5j0I~
    	LOCK_LEAVE()                                               //~v5j0I~
    }                                                              //~v5j0I~
#endif                                                             //~v5j0I~
}//utrace                              /* trace    */
//**************************************************************** //~v57bI~
//* edit curr time                                                 //~v57bI~
//*parm :none                                                      //~v57bI~
//*ret  :ptr to edit out area                                      //~v57bI~
//**************************************************************** //~v57bI~
char *utracectime(void)                                            //~v57bR~
{                                                                  //~v57bI~
#ifdef ARM                                                         //~v6a0I~
	static char Seditwk[32];                                       //~v6a0I~
#else                                                              //~v6a0I~
  #ifdef XXE                                                       //~v6p1R~
	static char Seditwk[32];                                       //~v6p1I~
  #else                                                            //~v6p1I~
	static char Seditwk[16];                                       //~v57bR~
  #endif                                                           //~v6p1I~
#endif                                                             //~v6a0I~
#ifdef UNX                                                         //~v57bI~
struct    timeb tb;      //time_t and milisec                      //~v57bI~
struct    tm* ptm;       //date and time                           //~v57bI~
#else                                                              //~v57bI~
#ifdef DOS                      //v7.0a                            //~v57bI~
  #ifdef DPMI                   //DPMI version                     //~v57bI~
  #else                       //not DPMI                           //~v57bI~
  #endif                      //DPMI or not                        //~v57bI~
    union REGS reg;                                                //~v57bI~
#else                                                              //~v57bI~
    #ifdef W32                                                     //~v57bI~
        SYSTEMTIME      datetime;   //*hh,mm,ss,th,day,month,year,tz,dayofweek//~v57bI~
    #else                                                          //~v57bI~
    	DATETIME      datetime;   //*hh,mm,ss,th,day,month,year,tz,dayofweek//~v57bR~
    #endif                                                         //~v57bI~
#endif                                                             //~v57bI~
#endif               //!UNX                                        //~v57bI~
//*************************                                        //~v57bI~
#ifdef UNX                                                         //~v57bI~
    ftime(&tb);                                                    //~v57bI~
    ptm=localtime(&tb.time);    //date and time                    //~v57bI~
  #ifdef ARM                                                       //~v6a0I~
//  #define gettid() syscall(__NR_gettid)                          //~v6a0R~
    #define gettid() pthread_self()                                //~v6a0I~
    sprintf(Seditwk,"%08x-%2.2d:%2.2d:%2.2d.%3.3d",                //~v6a0R~
            (int)gettid(),                                         //~v6a0I~
            (int)ptm->tm_hour,                                     //~v6a0I~
            (int)ptm->tm_min,                                      //~v6a0I~
            (int)ptm->tm_sec,                                      //~v6a0I~
            (int)tb.millitm);                                      //~v6a0I~
  #else                                                            //~v6a0I~
    #ifdef XXE                                                     //~v6p1I~
    #define gettid() syscall(SYS_gettid)                           //~v6p1I~
    sprintf(Seditwk,"%2.2d:%2.2d:%2.2d.%3.3d (%lx)",               //~v6p1R~
            (int)ptm->tm_hour,                                     //~v6p1I~
            (int)ptm->tm_min,                                      //~v6p1I~
            (int)ptm->tm_sec,                                      //~v6p1I~
            (int)tb.millitm,                                       //~v6p1I~
            gettid());                                             //~v6p1I~
    #else                                                          //~v6p1I~
    sprintf(Seditwk,"%2.2d:%2.2d:%2.2d.%3.3d",                     //~v57bI~
            (int)ptm->tm_hour,                                     //~v57bI~
            (int)ptm->tm_min,                                      //~v57bI~
            (int)ptm->tm_sec,                                      //~v57bI~
            (int)tb.millitm);                                      //~v57bI~
    #endif                                                         //~v6p1I~
  #endif                                                           //~v6a0I~
#else                                                              //~v57bI~
#ifdef DOS                      //v7.0a                            //~v57bI~
    reg.h.ah=0x2c;      //get time                                 //~v57bI~
    intdos(&reg,&reg);                                             //~v57bI~
    sprintf(Seditwk,"%2.2d:%2.2d:%2.2d.%2.2d",                     //~v57bI~
            reg.h.ch,reg.h.cl,reg.h.dh,reg.h.dl);                  //~v57bI~
#else                                                              //~v57bI~
    #ifdef W32                                                     //~v57bI~
        GetLocalTime(&datetime);                                   //~v57bI~
        sprintf(Seditwk,"%2.2d:%2.2d:%2.2d.%3.3d",                 //~v57bI~
                (int)datetime.wHour,                               //~v57bI~
                (int)datetime.wMinute,                             //~v57bI~
                (int)datetime.wSecond,                             //~v57bI~
                (int)datetime.wMilliseconds);                      //~v57bI~
    #else                                                          //~v57bI~
    	DosGetDateTime(&datetime);                                 //~v57bI~
    	sprintf(Seditwk,"%2.2d:%2.2d:%2.2d.%2.2d",                 //~v57bI~
            			datetime.hours,                            //~v57bI~
            			datetime.minutes,                          //~v57bI~
            			datetime.seconds,                          //~v57bI~
            			datetime.hundredths);                      //~v57bI~
    #endif                                                         //~v57bI~
#endif                                                             //~v57bI~
#endif  //!UNX                                                     //~v57bI~
	return Seditwk;                                                //~v57bI~
}//utracectime                                                     //~v57bI~
//****************************************************************//~5829I~
//* open trace file                                             //~5829I~
//*parm :none                                                   //~5829I~
//*ret  :rc(0;ok,else errno)                                    //~5829I~
//****************************************************************//~5829I~
int utraceopen(void)                                            //~5829I~
{                                                               //~5829I~
    int rc;                                                     //~5829I~
//***********************************                           //~5829I~
  if (!strcmp(Sutracefilename,"stdout"))                           //~v323R~
    Sfile=stdout;                                                  //~v323R~
  else                                                             //~v323R~
  if (!strcmp(Sutracefilename,"stderr"))                           //~v323R~
    Sfile=stderr;                                                  //~v323R~
  else                                                             //~v323R~
  {                                                                //~v6B1I~
   if (Sswnoshare)                                                 //~v6B1I~
    Sfile=ufileopenexclusivewrite(0,Sutracefilename,&Slockhandle);             //open output//~v6B1M~
   else                                                            //~v6B1I~
    Sfile=fopen(Sutracefilename,"w");             //open output //~6203R~
  }                                                                //~v6B1I~
#ifdef ARM                                                         //~v6a0I~
    LOGPD("utraceopen Sfile=%p,file=%s",Sfile,Sutracefilename);    //~v6a0R~
#endif                                                             //~v6a0I~
    if (Sfile)                            //open output         //~6203R~
    {                                                           //~5829I~
        utraceocmsg("TRACE START AT");                          //~5829I~
    	fprintf(Sfile,"= %s = \n",utracectime());                  //~v6b6R~
 		fflush(Sfile);                                             //~v6b6I~
        return 0;                                               //~5829I~
    }                                                           //~5829I~
    rc=errno;                                                   //~5829I~
#ifdef ARM                                                         //~v6a0I~
    LOGPD("utraceopen err=%x",rc);                                 //~v6a0I~
#endif                                                             //~v6a0I~
#ifdef UNX                                                         //~v352I~
    if (rc==EACCES)                                                //~v352I~
    	printf("%s(%s) Open failed(permission denied)\n",          //~v352R~
            	Sutracefilename,"w");                              //~v352I~
    else                                                           //~v352I~
#endif //UNX                                                       //~v352I~
    	printf("%s(%s) Open failed(errno=%d)\n",                   //~v352R~
            Sutracefilename,"w",rc);                            //~5829I~
//  if (Sutraceopt==1)  //not ignore trace opt                     //~v5j0R~
    if (!(Sutraceopt & UTRACEO_IGNOREOPENERR))  //not ignore trace opt//~v5j0I~
        exit(19);                                               //~5829I~
    Sutraceopt=0;   //bypass trace                              //~5829I~
    return rc;                                                  //~5829I~
}//utraceopen                                                   //~5829I~
//**************************************************************** //~v6VuI~
//* open trace file for UTRACEPF                                   //~v6VuI~
//**************************************************************** //~v6VuI~
int utraceopen_force(void)                                         //~v6VuI~
{                                                                  //~v6VuI~
    int rc;                                                        //~v6VuI~
    FILE *pfh;                                                     //~v6VuI~
//***********************************                              //~v6VuI~
   	if (Sswnoshare)                                                //~v6VuI~
    	pfh=ufileopenexclusivewrite(0,Sutracefilename_force,&Slockhandle);             //open output//~v6VuI~
   else                                                            //~v6VuI~
    	pfh=fopen(Sutracefilename_force,"w");             //open output//~v6VuI~
	Sfile_force=pfh;                                               //~v6VuI~
    if (pfh)                            //open output              //~v6VuI~
    {                                                              //~v6VuI~
        utraceocmsg_force("TRACE_FORCE START AT");                 //~v6VuR~
    	fprintf(pfh,"= %s = \n",utracectime());                    //~v6VuI~
 		fflush(pfh);                                               //~v6VuI~
        return 0;                                                  //~v6VuI~
    }                                                              //~v6VuI~
    rc=errno;                                                      //~v6VuI~
#ifdef UNX                                                         //~v6VuI~
    if (rc==EACCES)                                                //~v6VuI~
    	printf("%s(%s) Open failed(permission denied)\n",          //~v6VuI~
            	Sutracefilename_force,"w");                        //~v6VuI~
    else                                                           //~v6VuI~
#endif //UNX                                                       //~v6VuI~
    	printf("%s(%s) Open failed(errno=%d)\n",                   //~v6VuI~
            Sutracefilename_force,"w",rc);                         //~v6VuI~
    if (!(Sutraceopt & UTRACEO_IGNOREOPENERR))  //not ignore trace opt//~v6VuI~
        exit(19);                                                  //~v6VuI~
    return rc;                                                     //~v6VuI~
}//utraceopen_force                                                //~v6VuI~
//****************************************************************//~5829I~
//* open/close msg                                              //~5829I~
//*parm :start or end msg                                       //~5829I~
//*ret  :none                                                   //~5829I~
//****************************************************************//~5829I~
void utraceocmsg(char *Pmsg)                                       //~v022R~
{                                                               //~5829I~
    char dump[80];                                              //~5829I~
#ifdef UNX                                                         //~v321R~
struct    tm* ptm;       //date and time                           //~v321R~
    time_t wkt;                                                    //~v321R~
#else                                                              //~v321R~
#ifdef DOS                                                      //~5829I~
    union REGS reg;                                             //~5829I~
#else                                                           //~5829I~
    #ifdef W32                                                     //~v022I~
        SYSTEMTIME      datetime;   //*hh,mm,ss,th,day,month,year,tz,dayofweek//~v022I~
    #else                                                          //~v022I~
    DATETIME      datetime;   //*hh,mm,ss,th,day,month,year,tz,dayofweek//~5829I~
    #endif                                                         //~v022I~
#endif                                                          //~5829I~
#endif                      //!UNX                                 //~v321R~
//***********************************                           //~5829I~
#ifdef UNX                                                         //~v321R~
    time(&wkt); //date and time                                    //~v321R~
    ptm=localtime(&wkt);    //date and time                        //~v321R~
//  sprintf(dump,"%s %4.4d/%02d/%02d\n",                           //~v321R~//~v6B1R~
    sprintf(dump,"%s %4.4d/%02d/%02d pid=%ld\n",                   //~v6B1I~
            Pmsg,                                                  //~v321R~
            ptm->tm_year+1900,                                     //~v321R~
//          ptm->tm_mon,                                           //~v345R~
            ptm->tm_mon+1,                                         //~v345R~
//          ptm->tm_mday);                                         //~v321R~//~v6B1R~
            ptm->tm_mday,                                          //~v6B1I~
            (ULONG)ugetpid());                                     //~v6B1I~
#else                                                              //~v321R~
#ifdef DOS                      //v7.0a                         //~5829I~
    reg.h.ah=0x2a;      //get date                              //~5829I~
    intdos(&reg,&reg);                                          //~5829I~
    sprintf(dump,"%s %4.4d/%02d/%02d\n",                        //~5829I~
            Pmsg,                                               //~5829I~
            (int)reg.x.cx,reg.h.dh,reg.h.dl);                      //~v053R~
#else                                                           //~5829I~
    #ifdef W32                                                     //~v022I~
        GetLocalTime(&datetime);                                   //~v022R~
//      sprintf(dump,"%s %4.4d/%02d/%02d\n",                       //~v022I~//~v6B1R~
        sprintf(dump,"%s %4.4d/%02d/%02d pid=%ld\n",               //~v6B1I~
                Pmsg,                                              //~v022I~
                (int)datetime.wYear,                               //~v022I~
                (int)datetime.wMonth,                              //~v022R~
//              (int)datetime.wDay);                               //~v022I~//~v6B1R~
                (int)datetime.wDay,                                //~v6B1I~
                (ULONG)ugetpid());                                 //~v6B1I~
    #else                                                          //~v022I~
    DosGetDateTime(&datetime);                                  //~5829I~
    sprintf(dump,"%s %4.4d/%02d/%02d\n",                        //~5829I~
            Pmsg,                                               //~5829I~
            datetime.year,                                      //~5829I~
            datetime.month,                                     //~5829I~
            datetime.day);                                      //~5829I~
    #endif                                                         //~v022I~
#endif                                                          //~5829I~
#endif //!UNX                                                      //~v321R~
    putline(dump,(int)strlen(dump));                            //~5829I~
    return;                                                     //~5829I~
}//utraceocmsg                                                  //~5829I~
//**************************************************************** //~v6VuI~
//* open/close msg                                                 //~v6VuI~
//*parm :start or end msg                                          //~v6VuI~
//*ret  :none                                                      //~v6VuI~
//**************************************************************** //~v6VuI~
void utraceocmsg_force(char *Pmsg)                                 //~v6VuI~
{                                                                  //~v6VuI~
	Sswputforce=1;                                                 //~v6VuI~
	utraceocmsg(Pmsg);                                             //~v6VuR~
    Sswputforce=0;                                                 //~v6VuI~
    return;                                                        //~v6VuI~
}//utraceocmsg_force                                               //~v6VuI~
//********************************************************************
//* dump edit
//*   input:
//*     addr  :dump storage addr
//*     length:dump data length
//*     area  :actual data area addr
//*   output:
//*     none
//********************************************************************
void printdump(void* addr,int len,void* area)
{

  int   i,j;                /*work*/
  int    Dumpwidth=16;
  int     comp;               /*same line compare sw*/
  int     prevtype=0;         //previous char type a931014
#if defined(ULIB64) || defined(ULIB64X)                            //~v6J6R~
#else                                                              //~v6J6R~
//ULONG li;                //far ptr conv                          //~v6hhR~
  ULPTR li;                //far ptr conv                          //~v6hhI~
#endif                                                             //~v6J6R~
  int   maxbyte;            /*source range*/
  UCHAR *pc1,*pc2,*pc;      /*source  addr*/
  UCHAR *pcdata;            /*actual source  addr*/
  UCHAR *ln1,*ln2;          /*line ptr*/                           //~v022R~

//static UCHAR trt[16]="0123456789ABCDEF";/*hex cnv tbl*/          //~v6hhR~
static UCHAR trt[17]="0123456789ABCDEF";/*hex cnv tbl*///for C4295 //~v6hhI~
//static unsigned char Sebc2asc[256]=                                //~v322R~//~v6hhR~
static unsigned char Sebc2asc[257]=       //for C4295:could not contain last null//~v6hhI~
//       0123456789abcdef                                          //~v322R~
        "................"     //00-0f                             //~v322R~
        "................"     //10-1f                             //~v322R~
        "................"     //20-2f                             //~v322R~
        "................"     //30-3f                             //~v322R~
        " ...........<(+|"     //40-4f                             //~v322R~
        "&.........!.*);."     //50-5f                             //~v322R~
        "-/.........,%_>?"     //60-6f                             //~v322R~
        "..........:#@'=\""     //70-7f                            //~v322R~
        "................"     //80-8f                             //~v322R~
        "................"     //90-9f                             //~v322R~
        "................"     //a0-af                             //~v322R~
        "................"     //b0-bf                             //~v322R~
        "{ABCDEFGHI......"     //c0-cf                             //~v322R~
        "}JKLMNOPQR......"     //d0-df                             //~v322R~
        "..STUVWXYZ......"     //e0-ef                             //~v322R~
        "0123456789......";    //f0-ff                             //~v322R~
//*********************
  pc1=(UCHAR*)addr;         /*start addr*/
  pc2=pc1+len;              /*end addr*/

  if (Dumpboundary==1)      //4byte boundary 931014add
    i=4; //boundary unit 931014add
  else//931014add
    i=Dumpwidth;
//pc =(void*)((ULONG)pc1 & (0-i));  //first print data block addr  //~v6hhR~
//pc =(void*)((ULPTR)pc1 & (0-i));  //first print data block addr  //~v6B1R~
  pc =(void*)((ULPTR)pc1 & (ULPTR)(0-i));  //first print data block addr//~v6B1I~
//maxbyte=(int)(((ULONG)(pc2+i-1) & (0-i))-(ULONG)pc);//next of last print block addr//~v6hhR~
//maxbyte=(int)(((ULPTR)(pc2+i-1) & (0-i))-(ULPTR)pc);//next of last print block addr//~v6B1R~
  maxbyte=(int)(((ULPTR)(pc2+i-1) & (ULPTR)(0-i))-(ULPTR)pc);//next of last print block addr//~v6B1I~
  if (!maxbyte)     //length=0 931014add
    return;         //931014add
 
  Samestart=NULL;                            //first time sw 931014add
  memset(Line,' ',(UINT)Linewidth);                  /*print line clear*/
  Line[Linecharpos-1]='*';                     /*char part start*/
  Line[Linewidth]='\n';                    /*end of string*/

  for (i=0;i<=maxbyte;i+=Dumpwidth)        /*full area*/
  {                                 /*max byte*/
//  pcdata    =(UCHAR*)area+(ULONG)pc-(ULONG)addr;                 //~v6hhR~
    pcdata    =(UCHAR*)area+(ULPTR)pc-(ULPTR)addr;                 //~v6hhI~
    comp=1;                            //unmatch id
    if (pc>=pc1 && pc+Dumpwidth<=pc2)   //full dumpwidth data
    {
      if (Samestart) //not first time
        comp=memcmp(Samesave,pcdata,(UINT)Dumpwidth);

      if (comp)      //unmatch or first line
        comp=2;      //full new line id
    }//full 1 dump line

    if (  comp                    //unmatch
       && Samestart               //save line exist
       && pc!=Samestart+Dumpwidth)// not single line
    {
      memset(Sameline,' ',LINEHEXPOS+1);  /*print line clear*/
//    j=sprintf(Sameline+LINEHEXPOS+1,                             //~v6J6R~
      j=sprintf(Sameline+LINEHEXPOS-1,                             //~v6J6R~
#if defined(DOS) && !defined(DPMI)                                 //~v336I~
              "%p to %p is same as above\n",                       //~v053R~
              Samestart+Dumpwidth,pc-1)+LINEHEXPOS+1;              //~v053R~
#else                                                              //~v336M~
    #ifdef ULIB64                                                  //~v690I~
              "%p to %p is same as above\n",                       //~v690I~
              (Samestart+Dumpwidth),(pc-1))+LINEHEXPOS+1;          //~v690I~
    #elif defined(ULIB64X)                                         //~v6hhR~
              "%p to %p is same as above\n",                       //~v6hhI~
              (Samestart+Dumpwidth),(pc-1))+LINEHEXPOS+1;          //~v6hhI~
    #else                                                          //~v690I~
              "%08X to %08X is same as above\n",                   //~v336M~
              (unsigned int)(Samestart+Dumpwidth),(unsigned int)(pc-1))+LINEHEXPOS+1;//~v336I~
    #endif                                                         //~v690I~
#endif                                                             //~v336M~
        j-=2;                                                      //~v6J6R~
      putline(Sameline,j);
    }

    if (i>=maxbyte)       // last line
      break;

    if (!comp) //match case
      pc+=Dumpwidth;//next line data
    else
    {//unmatch case
      if (comp==2)   //full dumpwidth data unmatch
      {
        memcpy(Samesave,pcdata,(UINT)Dumpwidth);
        Samestart=pc;
      }
      else
        Samestart=NULL;   //clear for last line chk
//*edit addr value
      ln1=Line+LINEADDRPOS;     //addr edit start pos
//    li=(ULONG)pc;                                                //~v6hhR~
#if defined(ULIB64) || defined(ULIB64X)                            //~v6J6R~
#else                                                              //~v6J6R~
      li=(ULPTR)pc;                                                //~v6hhI~
#endif                                                             //~v6J6R~
//#ifdef DOS                    //v7.0a                            //~v053R~
#if defined(DOS) && !defined(DPMI)                                 //~v053I~
//xxxxxx                                                           //~v026R~
      li=((li>>16)<<4)+((li<<16)>>16);
      ln2=(UCHAR*)&li+3;        //source field                     //~v026I~
      for (j=0;j<3;j++)         //edit 4 byte hex                  //~v026I~
      {                                                            //~v026I~
        *(ln1++)=*(trt+(*(--ln2)>>4));       //first 4 bit         //~v026I~
        *(ln1++)=*(trt+(*ln2 & 0x0000000f)); //last 4 bit          //~v026I~
      }                                                            //~v026I~
//ssss:oooo                                                        //~v026M~
      *(ln1++)='(';                                                //~v026M~
      li=(ULONG)pc;                                                //~v026I~
      ln2=(UCHAR*)&li+4;        //source field                     //~v026M~
      for (j=0;j<4;j++)         //edit 4 byte hex                  //~v026M~
      {                                                            //~v026M~
        *(ln1++)=*(trt+(*(--ln2)>>4));       //first 4 bit         //~v026M~
        *(ln1++)=*(trt+(*ln2 & 0x0000000f)); //last 4 bit          //~v026M~
        if (j==1)                                                  //~v026M~
            *(ln1++)=':';                                          //~v026M~
      }                                                            //~v026M~
      *ln1=')';                                                    //~v026M~
#else                                                              //~v026I~
  #if defined(ULIB64) || defined(ULIB64X)                          //~v6J6R~
#ifdef W32                                                         //~v6J6I~
  	sprintf(ln1,"%016llX",(ULPTR)pc);                              //~v6J6R~
#else                                                              //~v6J6I~
  	sprintf(ln1,"%016lx",(ULONG)pc);                               //~v6J6R~
#endif                                                             //~v6J6I~
    *(ln1+16)=' ';                                                 //~v6J6R~
  #else                                                            //~v6J6R~
//  #ifdef UNX                  //big endian                       //~v336R~
    #if defined(UNX) && !defined(LNX)                  //big endian//~v336I~
      ln2=(UCHAR*)&li-1;        //source field                     //~v321R~
      for (j=0;j<4;j++)         //edit 4 byte hex                  //~v321R~
      {                                                            //~v321R~
        *(ln1++)=*(trt+(*(++ln2)>>4));       //first 4 bit         //~v321R~
        *(ln1++)=*(trt+(*ln2 & 0x0000000f)); //last 4 bit          //~v321R~
      }                                                            //~v321R~
    #else                                                          //~v321R~
      ln2=(UCHAR*)&li+4;        //source field                     //~v022R~
      for (j=0;j<4;j++)         //edit 4 byte hex
      {
        *(ln1++)=*(trt+(*(--ln2)>>4));       //first 4 bit
        *(ln1++)=*(trt+(*ln2 & 0x0000000f)); //last 4 bit
      }
    #endif                                                         //~v321R~
  #endif                                                           //~v6J6R~
#endif                                                             //~v026M~
      ln1=Line+LINEHEXPOS-1;                     /*hex start*/
      ln2=Line+Linecharpos;                       /*char start*/

      Line[Linecharpos+Dumpwidth]='*'; //reset last dbcs //a931014

      for (j=0;j<Dumpwidth;j++)           /* 1 line setup*/
      {
        if (!(j & 0x00000003)) ln1++;  /*' ' each 4 byte*/
        if (!(j & 0x0000000F)) ln1++;  /*' ' each 16 byte*/

        if (pc<pc1 || pc>=pc2)   /*by boundary align*/
        {
          *ln2    =' ';                /*char part*/
          *ln1=*(ln1+1)=' '; /*dump part,2byte*/
        }
        else                             /*net area*/
        {
//        pcdata    =(UCHAR*)area+(ULONG)pc-(ULONG)addr;           //~v6hhR~
          pcdata    =(UCHAR*)area+(ULPTR)pc-(ULPTR)addr;           //~v6hhI~
         if (Sebcsw)                                               //~v322R~
         {                                                         //~v322R~
            *ln2=Sebc2asc[*pcdata];       //force unprintable      //~v322R~
         }                                                         //~v322R~
         else                                                      //~v322R~
         { //not ebcdic                                            //~v322R~
//        *ln2    =(UCHAR)max(*pcdata,' ');   /*char part*/ //d931014
//*dbcs consideration** a931014
          switch (prevtype)               //previous is dbcs first byte
          {
          case 2:                        //previous is dbcs first byte
            prevtype=0;                  //dbcs end
            *ln2=*pcdata;                //set char dump part
            break;
          case 3:                        //dbcs at dump width boundary 
            prevtype=0;                  //dbcs end
            *ln2='.';                    //force unprintable
            break;
          default:
            if (pc==pc2-1)              //last byte
              prevtype=typechk(*pcdata,0);//sbcs printable chk
            else
              prevtype=typechk(*pcdata,*(pcdata+1));//dbcs chk
            switch (prevtype)
            {
            case 0:                      //unprintable
              *ln2='.';                  //unprintable id
              break; 
            case 1:                      //sbcs
              *ln2=*pcdata;              /*char part*/
              break;
            default:                     //2,dbcs
              *ln2=*pcdata;              //dbcs first byte
              if (j==Dumpwidth-1)        //last colomn of line
              {
                *(ln2+1)=*(pcdata+1);    //set also dbcs second byte
                prevtype=3;              //force unprintable at next time
              }
              break;
            }//switch by current type
          }//switch by prevtype
         } //not ebcdic                                            //~v322R~

          *ln1    =*(trt+(*pcdata>>4));      /*first 4 bit*/
          *(ln1+1)=*(trt+(*pcdata & 0x0000000F));/*last 4*/
        }

        ln1+=2;                          /*hex part */
        ln2++;                           /*char part*/
        pc++;                          /*next source byte*/
      }                                  /*dumpwidth loop*/
      
      putline(Line,Linewidth+1);        //print not same line with crlf
    }//not same line
  }                                   /*loop by max*/
}//end of printdump

//**********************************************************************
void putline(char *area,int count) //v3.5r
{
	FILE *pfh;                                                     //~v6VuI~
//*****************************                                    //~v6VuI~
	if (Sswputforce)                                               //~v6VuR~
    	pfh=Sfile_force;                                           //~v6VuI~
    else                                                           //~v6VuI~
    	pfh=Sfile;                                                 //~v6VuI~
//      printf("%s:sh=%p\n",UTT,pfh);//@@@@test                    //~v6VuR~
//  fwrite(area,1,(UINT)count,Sfile);                           //~6203R~//~v6VuR~
    fwrite(area,1,(UINT)count,pfh);                                //~v6VuI~
    return;
}//end of pline
//******************************************
//* printable chk           a931014        *
//*   return   0:unprintable               *
//*            1:printable sbcs            *
//*            2:dbcs first byte           *
//******************************************
int typechk(char c1,char c2) 
{
//*************
int chartype;
//*************
//code table  * 0:unprintable 1:printable 2:DBCS first byte
//*************
//first byte chk tbl     0 1 2 3 4 5 6 7 8 9 a b c d e f
  static int code1[256]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //"0x"
                         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //"1x"
                         1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"2x"
                         1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"3x"
                         1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"4x"
                         1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"5x"
                         1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"6x"
                         1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0, //"7x"
                         0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2, //"8x"
                         2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2, //"9x"
                         0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"ax"
                         1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"bx"
                         1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"cx"
                         1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"dx"
                         2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2, //"ex"
                         2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0};//"fx"
//second byte chk tbl    0 1 2 3 4 5 6 7 8 9 a b c d e f
  static int code2[256]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //"0x"
                         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //"1x"
                         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //"2x"
                         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //"3x"
                         1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"4x"
                         1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"5x"
                         1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"6x"
                         1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0, //"7x"
                         1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"8x"
                         1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"9x"
                         1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"ax"
                         1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"bx"
                         1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"cx"
                         1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"dx"
                         1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, //"ex"
                         1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0};//"fx"
//****************************************

  if ((chartype=code1[(int)c1])==2)     //first byte chk,dbcs      //~v053R~
    if (!code2[(int)c2])                //valid second byte        //~v053R~
      chartype=0;                  //unprintable
  return chartype;
}
#ifdef W32                                                         //~v6u9I~
//*************************************************************    //~v6u9I~
void printUWCH(int Popt,char *Pprefix,UWCH *Ppwucs,char *Ppostfix) //~v6u9I~
{                                                                  //~v6u9I~
static HANDLE Shcons_stdout;                                       //~v6u9I~
	int wrtctr;                                                    //~v6u9I~
//**************************************                           //~v6u9I~
	if (Popt & PUWCHO_OPEN)                                        //~v6u9I~
    {                                                              //~v6u9I~
	    Shcons_stdout=GetStdHandle(STD_OUTPUT_HANDLE);             //~v6u9I~
        return;                                                    //~v6u9I~
    }                                                              //~v6u9I~
	if (!Shcons_stdout)                                            //~v6u9I~
    	printUWCH(PUWCHO_OPEN,NULL,NULL,NULL);                     //~v6u9I~
    if (Pprefix)                                                   //~v6u9I~
    	printf(Pprefix);                                           //~v6u9I~
    WriteConsoleW(Shcons_stdout,Ppwucs,strctrW(Ppwucs),&wrtctr,NULL);//~v6u9I~
    if (Ppostfix)                                                  //~v6u9I~
    	printf(Ppostfix);                                          //~v6u9I~
}//printUWCH                                                       //~v6u9I~
#endif //W32                                                       //~v6u9I~
//*************************************************************    //~v6B1I~
int utrace_term(int Popt)                                          //~v6B1I~
{                                                                  //~v6B1I~
//      printf("%s:sh=%p\n",UTT,Sfile);//@@@@test                  //~v6VuR~
//      printf("%s:sh_force=%p\n",UTT,Sfile_force);//@@@@test      //~v6VuR~
	if (Sfile)  //file opened                                      //~v6B1I~
    {                                                              //~v6B1I~
    	utraceocmsg("TRACE CLOSE AT");                             //~v6B1I~
        if (Sfile!=stdout && Sfile!=stderr)                        //~v6B1I~
            fclose(Sfile);                                         //~v6B1I~
        Sfile=0;                                                   //~v6B1I~
    }                                                              //~v6B1I~
	if (Sfile_force)  //file opened                                //~v6VuI~
    {                                                              //~v6VuI~
    	utraceocmsg_force("TRACE_FORCE CLOSE AT");                 //~v6VuI~
        fclose(Sfile_force);                                       //~v6VuI~
        Sfile_force=0;                                             //~v6VuI~
    }                                                              //~v6VuI~
    Sutraceopt=0;                                                  //~v6B1I~
    return 0;                                                      //~v6B1I~
}//utrace_term                                                     //~v6B1I~
