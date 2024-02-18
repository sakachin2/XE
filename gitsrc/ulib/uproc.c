//*CID://+vc70R~:                             update#=  495;       //~vc70R~
//************************************************************* //~5825I~
//*uproc.c                                                         //~v5anR~
//* usystem,uspawnl,uspawnlp,uspawnvp,uexecchk                     //~v065R~
//*************************************************************    //~v022I~
//vc70 2023/08/14 try tool with attr of 110(executable only) to avoid M^X vioration//~vc70I~
//v77L:230626 ARM;dlclose required each time to clear static valiable//~v77LI~
//v77K:230622 ARM;use iconv_so(/system/bin/iconv installed as part of toybox. toybox is alternative of busybox and installed to >=android-6)//~v77KI~
//v77J:230622 (Bug)ARM;dlopen for libhighlight_so.so returns -1, it cause quit xe.//~v77JI~
//v77H:230622 ARM;execulte so for also highlight                   //~v77HI~
//v77G:230622 ARM;split armXsubExit to reduce xsub size            //~v77GI~
//v77F:230617 ARM;execv also faile for >=Android10:api29           //~v77FI~
//v77D:230618 ARM;v77c on subthread to avoid exit() kill whole process//~v77DI~
//v77C:230617 ARM;try dlopen to execute xe tool for >=Android10:api29//~v77CI~
//v70c:200625 =6 cmd;cmd not found, setenv is not work             //~v70cI~//~v77DR~
//v701:200611 usystem hung warning                                 //~v6L2I~
//v6L2:170624 (Win) add msi as executable                          //~v6L2I~
//v6L1:170624 (BUG:64bit) "&" dirlist cmd 0c4(ptr size4 and 8)     //~v6L1I~
//v6yc:150314 change errmsg for xesyscmd breaked case              //~v6ycI~
//v6xk:150115 (BUG:W32)spwanxx deplicated,use _spawnxx(return intptr_t, Linux returns int pid)//~v6xkI~
//v6xi:150115 conversion warning                                   //~v6xiI~
//v6up:140503 (Win:UNICODE)wsystem for xdc/xfc                     //~v6upI~
//v6qa:131203 reduce udirlist size. name max is 256,slinkname max=_MAX_PATH=4096 on suse64. change to malloc slinkname.//~v6qaI~
//v6k0:130524 mkarmnc is compile err(term.h not found) by v6j0     //~v6k0I~
//v6hm:120630 (BUG)spawn errmsg,display pathname                   //~v6hmI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6h9:120612 (FC5)avoid uninitialized variable warning by gcc 4.1.1 on FC5(copile optio -Ox is required also)//~v6h9I~
//v6h7:120609 (VC6)avoid c4701 warning by VC6(used uninitialized variable)//~v6h7I~
//v6h6:120609 (WTL)avoid c4701 warning(used uninitialized variable)//~v6h6I~
//v6dc:120217 (BUG)there is the case of system() returns rc but no stdo/stde is written//~v6dcI~
//v6db:120217 (BUG)tempnam may overflow fo Axe because /tmp is not available and changed to /mnt/sdcard/tmp/...//~v6dbI~
//v6a0:110520 Android porting(-DARM)                               //~v6a0I~
//v690:100701 m62(LP64:: int:32, long,void*:64) support (__LP64_)  //~v690I~
//v5nd:081009 (SYNH) external process ctl                          //~v5ndI~
//v5nc:081009 (LNX)MinGW compile                                   //~v5ncI~
//v5mt:080518 (BUG by v5ma)spawn fail                              //~v5mtI~
//v5ma:080219 (BUG)C+c break process after system(),spawn() because it loose console mode//~v5maI~
//v61p:080121 (FTP)psftp support                                   //~v61pI~
//v61i:080117*xuerpchk(uerrmsg parameter chk)                      //~v61iI~
//v5j6:060914 _pipe support stderr redirect                        //~v5j6I~
//v5j2:060911 usystem_cmdserversetup support intemediate shell for xe3270(need cmd prompt)//~v5ivR~
//v5iv:060906 3270server support(2nd cmdserver)                    //~v5ivI~
//v5i6:060514 (BUG)ugetexepath dose not return exepath if no path specified//~v5i6I~
//v5h1:050812 (LNX)FC4 msg "Warning:bad syntax, perhaps a bogue '-'? See /usr/share/doc/procps-3.2.5/FAQ"//~v5h1I~
//            "ps -alwx"-->"ps alwx" is right                      //~v5h1R~
//v5gb:050709 move ushellexex to uproc3.c to avoid gnome link for xsub utility//~v5gbI~
//v5ga:050708 (UNX:BUG)space enclosing is not required for LNX,spawn cmd fail. See v082//~v5g9R~
//v5g9:050708 (LNX)openwith support                                //~v5g9M~
//v5es:041031 (BUG)stderr ptr should be safe to be cleared         //~v5csI~
//v5cw:040516 (WXE)it should be notified to cmd server of cd drive id change//~v5cwI~
//v5cs:040509 (WIN:BUG)_tempnam  returns prefix itself if prefix length >=8//~v5csI~
//                     and loop when the only one name exist       //~v5csI~
//v5cc:040414 (WXE)confirm xesyscmd.exe is alive before write to pipe//~v5ccI~
//v5by:040229 shellexecute(open with application by ext association) support//~v5byI~
//v5bx:040225 cmd server function for 1 dos prompt screen(ftp use this server)//~v5bxI~
//v5bw:040223 (BUG)spawn returns process handle when NO_WAIT option//~v5bwI~
//v5bv:040222 (FTP)use resident ftp client pgm because mdos prompt appear each time under WXE//~v5bvI~
//v5br:040219 (FTP)use spawn for alternative of system because cmd prompt screen apear.//~v5anI~
//v5an:040110 (FTP)deleted msg issued for ftp temp file delete at xdd//~v5anI~
//v5ad:040105 support TZ=hhmm and DBCS=EUC/SJIS                    //~v5adI~
//v59t:031222 execute cmd by LANG=C environment to get english ftp responce msg//~v59tI~
//v59j:031108 ftp support:uspawn_pipe func(not completely tested)  //~v59jI~
//            setlinebuf(to detect child put is not effective because it is not inherited)//~v59jI~
//v59g:031103 keep temp file option for test                       //~v59gI~
//v59d:030816 ftp support                                          //~v59dI~
//v599:031025 (BUG)malloc len=0 for psinfo cmd len                 //~v599I~
//v57P:030712 (LNX)no end msg for getpsinfo                        //~v57PI~
//v57F:030419 (AIX)ps cmd flag for AIX                             //~v57FI~
//v57B:030419 (LNX)no process chain when xe executed by shell      //~v57BI~
//v57A:030413 (LNX)TTY=pts/n under X(ptsn for kon,ttyn for console)//~v57AI~
//v57t:030125 buff size parm support to usystemcsh                 //~v57tI~
//v57q:030118 (WIN)usystemcsh support(create child subshell)       //~v57qR~
//v55o:020518 (UNX)errno msg for each not by uproc                 //~v55oI~
//v55a:020427 (UNX:BUG)mdoscmd clear errmsg by ugeterrmsg;save and restore//~v55aI~
//v50H:010618 no msg option for spawn                              //~v50HI~
//v50G:010618 LNX:disket support(using mtools)                     //~v50GI~
//v50v:010422 konchk performance up                                //~v50vI~
//v428:010218 TLinux:ps operand is not same as SW3.5               //~v428I~
//v394:001104 LINUX support:rc of system() is exitcode+signalcode and errno=0//~v394I~
//                          (there is no case of rc=-1)            //~v394I~
//v393:001103 LINUX support:filename is case sensitive             //~v393I~
//v377:000930 LINUX support(dir seperater is "/" not "\")          //~v377I~
//v366:000927 LINUX support(display operation on permission errmsg)//~v366I~
//v351:000926 LINUX support(filename on permission err msg)        //~v351I~
//v327 000820:LINUX support                                        //~v327I~
//v316 000527:add EXE pgm path(OS2 and WIN only)                   //~v316I~
//v181:980509 correct uexecchk r.c comment                         //~v181I~
//v130:971217 uparsecmdin:enclose by quatation by cmd fmt          //~v130I~
//                        use for uspawnvp                         //~v130I~
//v127:971207 new func ucmdnmcom(command name compare)             //~v127I~
//v098:970723 split uparse fro ustring to uparse.c                 //~v098I~
//v082:970503 GCC accept spawnvp,spawnlp space embedding parm      //~v065I~
//            dos and os/2 split it like as "a b" to "a" and "b"   //~v065I~
//            xprint cmd is spawn by xe,filename may embedding space//~v065I~
//            so enclose by quate for dos and os2.                 //~v065I~
//            Now support spawnvp only.                            //~v065I~
//v065:970211:add uspawnvp to uproc                                //~v065I~
//v064:970210:uexecchk function add(current and path search for chk executable)//~v064I~
//v053:970107:gcc version(control by DPMI)                         //~v053I~
//            -compile err if DBCS containe \ in it.               //~v053I~
//v022:960727:WIN32(CONSOLE api)                                   //~v022I~
//************************************************************* //~5825I~
#include <time.h>                                               //~5825I~
#include <stdio.h>                                              //~5825I~
#include <stdlib.h>                                             //~5825I~
#include <string.h>                                             //~5825I~
#include <stdarg.h>                                             //~5A10I~
#include <errno.h>                                              //~5A10I~
#include <fcntl.h>                                                 //~v59jI~
#ifdef UNX                                                         //~v327I~
  #ifdef LNX                                                       //~v59jI~
   #ifdef MGW32                                                    //~v5ncI~
	#include <process.h>                                           //~v5ncI~
   #endif                                                          //~v5ndM~
	#include <sys/wait.h>                                          //~v59jI~
#if !(defined(ARM) && defined(XXE))                                //~v6a0R~
//#ifndef NOCURSES                                                 //~v6hmR~
  #ifndef NOCURSES                                                 //~v6k0I~
	#include <term.h>                                              //~v5g9I~
  #endif //NOCURSES                                                //~v6k0I~
//#endif //NOCURSES                                                //~v6hmR~
#endif //ARMXXE                                                    //~v6a0R~
  #endif                                                           //~v59jI~
	#include <sys/stat.h>                                          //~v327I~
	#include <unistd.h>                                            //~v428I~
#else                                                              //~v327I~
	#include <process.h>                                           //~v50HI~
#ifdef DOS                                                      //~5825I~
#else                                                           //~5825I~
    #ifdef W32                                                     //~v022I~
        #include <windows.h>                                       //~v316I~
        #include <dos.h>                                           //~v065I~
        #include <io.h>                                            //~v59jI~
    #else                                                          //~v022I~
        #define INCL_BASE                                          //~v316R~
        #define INCL_DOSPROCESS                                    //~v316I~
        #include <os2.h>                                           //~v316R~
    #endif                                                         //~v022I~
#endif                                                          //~5825I~
#endif   //!UNX                                                    //~v327I~
#ifdef ARM                                                         //~v77CR~
	#include <dlfcn.h>                                             //~v77CR~
	#include <pthread.h>                                           //~v77DI~
	#include <setjmp.h>                                            //~v77DI~
#endif                                                             //~v77CI~
                                                                   //~v022I~
#include <ulib.h>                                               //~5825I~
#include <uerr.h>                                               //~5A10I~
                                                                   //~v6L2I~
#define UPROC_GBLDEF                                               //~v6L2I~
#include <uproc.h>                                              //~5A10I~
                                                                   //~v6L2I~
#include <uproc2.h>                                                //~v5maI~
#include <ufile.h>                                                 //~v064I~
#include <ufile2.h>                                                //~v59dI~
#include <ufile4.h>                                                //~v428I~
#include <ufemsg.h>                                                //~v327I~
#include <ualloc.h>                                                //~v064I~
#include <uparse.h>                                                //~v098R~
#include <udos.h>                                                  //~v57qR~
#include <udbcschk.h>                                              //~v5adI~
#include <utrace.h>                                                //~v5bxI~
#include <uedit.h>                                                 //~v5ccI~
#include <uque.h>                                                  //~vc70I~
#include <uftp.h>                                                  //~vc70I~
#ifdef UNX                                                         //~v327I~
	#include <ufile2l.h>                                           //~v327I~
	#ifdef LNX                                                     //~v5g9I~
		#include <ukbdl.h>                                         //~v5g9I~
	#endif                                                         //~v5g9I~
	#include <ulibarm.h>                                           //~v70cI~
#else                                                              //~v61pI~
    #ifdef WINCON                                                  //~v61pI~
		#include <ukbd.h>                                          //~v61pI~
		#include <ukbdw.h>                                         //~v61pI~
    #endif                                                         //~v61pI~
#endif                                                             //~v327I~
#include <ufilew.h>                                                //~v6upI~
#include <ustring.h>                                               //~v77DR~
#include <udos2.h>                                                 //~v77DI~
#ifdef ARMXXE	//no support for system call from xsub tool        //~vc70I~
	#include <jnic2ju.h>                                           //~vc70R~
	#include <jnia.h>                                              //~vc70I~
#endif                                                             //~vc70I~
//*********************************************                    //~v064R~
#ifdef W32                                                         //~v5j2I~
	#define SHELLPGM "cmd.exe"                                     //~v5j2I~
#endif                                                             //~v5j2I~
#define SPAWNMAXPARM 11                                         //~5A10I~
//*                                                                //~v064I~
#ifndef UNX                                                        //~v327I~
static char *Sextlist[]={                                          //~v064M~
                        "com",                                     //~v064M~
                        "exe",                                     //~v065M~
#ifdef DOS                                                         //~v064M~
#else                                                              //~v064M~
                        "cmd",                                     //~v064M~
                        "msi",                                     //~v6L2R~
#endif                                                             //~v064M~
                        "bat"};                                    //~v064M~
#endif //!UNX                                                      //~v327I~
#if defined(UNX) || defined(W32)                                   //~v5bxI~
	int Sserverstat=0;                                             //~v5bxI~
	#define SVRS_READY   0x01  		//server started               //~v5bxR~
	#define SVRS_LAZY    0x02       //waiting first request to start server//~v5bxR~
                                                                   //~v5bxI~
    CMDSVRCALLBACK  *Scmdservercallback=0;                         //~v5bxI~
    void *Scallbackparm=0;                                         //~v5bxI~
    int Sfdpiper,Sfdpipew;                                         //~v5bxR~
#endif                                                             //~v5bxI~
static int Suprocopt=0;                                            //~v5bxM~
#if defined(UNX) || defined(W32)                                   //~v5ccI~
    int Scmdserverchildpid=0;                                      //~v5ccR~
	static int Soutbuffsz=0;                                       //~v5ivI~
	static char *Soutbuff=0;                                       //~v5ivI~
#endif                                                             //~v5ccI~
#ifdef ARM                                                         //~v77LI~
	static int dlopenErr;                                          //~v77JI~
#endif                                                             //~v77LI~
//*********************************************                    //~v064R~
//int uspawnrc(int Pmodeflag,char *Ppathname,int Prc);             //~v6xkR~
LONGHANDLE uspawnrc(int Pmodeflag,char *Ppathname,LONGHANDLE Prc); //~v6xkI~
#if defined(DOS) || defined(W32)                                   //~v394R~
int uprocerr2big(char *Ppathname,int Prc);                      //~5A10M~
#else                                                           //~5A10I~
#endif                                                          //~5A10I~
int uprocerrmem(char *Ppathname,int Prc);                       //~5A10I~
void uprocopt(int *Ppmodeflag);                                    //~v50HI~
int uprocerrnotf(char *Ppathname,int Prc);                      //~5A10I~
int uextdirsrch(char *Pfullpath);                                  //~v064M~
int ucreateshproc(int Pcol,int Prow);                              //~v57tI~
//int uproc_redirectoutchk(int Popt,char *Pcmd,char ***Pstdo,char ***Pstde,int *Pstdoctr,int *Pstdectr,//~v5bvR~
//						char *Pstdofnm,char *Pstdefnm);            //~v5bvR~
#if defined(UNX) || defined(W32)                                   //~v59jI~
int uspawnvp_pipeclose(int *Ppipe_p2c,int *Ppipe_c2p);             //~v59jI~
//int usystem_pidalivechk(int Ppid);                               //~v5ndR~
#endif //defined(UNX) || defined(W32)                              //~v59jI~
//#ifdef W32                                                       //~v5gbR~
//    char *ushellexecerrmsg(ULONG Perrid);                        //~v5gbR~
//#endif                                                           //~v5gbR~
#ifdef ARMXXE                                                      //~v77DI~
	int systemArm(char *Pcmd,int *Prc);                            //~v77DI~
	int systemArmProc(char *Pcmd,int *Pretval);                    //~vc70I~
#endif                                                             //~v77DI~
#define ERR_ONTHREAD 32767 	//to avoid rc=-1	                   //~v77JR~
//**************************************************************** //~v77FI~
#ifdef ARMXXE                                                      //~v77FI~
int unsupportedFuncArm(char *Pfunc,char *Pcmd)                     //~v77FR~
{                                                                  //~v77FI~
    int apilevel=GarmApiLevel;                                     //~v77FR~
	UTRACEP("%s:device_api_level=%d\n",UTT,apilevel);              //~v77FI~
    if (apilevel>=__ANDROID_API_Q__)	//android10(Q)=29          //~v77FI~
    {                                                              //~v77FI~
    	uerrmsg("unsupported function(%s) fot >=android-Q.(cmd=%s)",//~v77FR~
    			"android-10(Q) 以降では %s は機\x94\\しません(cmd=%s)",//~v77FR~
				Pfunc,Pcmd);                                       //~v77FR~
        return 1;                                                  //~v77FI~
	}                                                              //~v77FI~
    return 0;                                                      //~v77FI~
}                                                                  //~v77FI~
#endif                                                             //~v77FI~
//**************************************************************** //~v50HI~
#ifdef W32                                                         //~v57qR~
//**************************************************************** //~v57qR~
//*usystem                                                         //~v57qR~
//* issue command syncronous                                       //~v57qR~
//*parm1:option                                                    //~v57tR~
//*parm2:ULONG buffsz xxxxyyyy;xxxx:cols,yyyy:row                  //~v57tI~
//*retrn:rc(=errno)                                                //~v57qR~
//**************************************************************** //~v57qR~
int usystemcsh(int Popt,ULONG Pbuffsz)                             //~v57tR~
{                                                                  //~v57qR~
	int rc;                                                        //~v57qR~
//********************                                             //~v57qR~
	rc=ucreateshproc(Pbuffsz>>16,Pbuffsz & 0xffff);                //~v57tR~
    return rc;                                                     //~v57qR~
}//usystemcsh                                                      //~v57qR~
//*************************************************************    //~v57qR~
//*create sub shell process                                        //~v57qR~
//*************************************************************    //~v57qR~
int ucreateshproc(int Pcol,int Prow)                               //~v57tR~
{                                                                  //~v57qR~
    STARTUPINFO  stinfo= {                                         //~v57qR~
							sizeof(STARTUPINFO),     //cb          //~v57qR~
                            NULL,                    //rsv         //~v57qR~
                            NULL,                    //desktop     //~v57qR~
                            "SubmittedShell",		//title        //~v57qR~
                            0,0,                     //window pos  //~v57qR~
                            0,0,                     //window size //~v57qR~
            0,0,//          80,24,                   //char count  //~v57tR~
            0, //           FOREGROUND_RED|FOREGROUND_BLUE,//bg black//~v57qR~
            0, //           flags STARTF_USECOUNTCHARS,            //~v57tR~
               //           | STARTF_USEFILLATTRIBUTE              //~v57tR~
                            0,			//SHOW WINDOW              //~v57qR~
                            0,			//rsv                      //~v57qR~
                            NULL,			//rsv                  //~v57qR~
                            0,0,0};		//stdin,stdout,stderr handle//~v57qR~
                                                                   //~v57qR~
    PROCESS_INFORMATION pinfo;                                     //~v57qR~
	int rc;                                                        //~v57qR~
    char *cmdnm,*cmdstr;                                           //~v57qR~
//  char sysdir[_MAX_PATH];                                        //~v57qR~
//****************************                                     //~v57qR~
//  GetSystemDirectory(sysdir,_MAX_PATH);                          //~v57qR~
//  uerrmsgbox("Sysdir %s ",0,sysdir);                             //~v57qR~
//  GetWindowsDirectory(sysdir,_MAX_PATH);                         //~v57qR~
//  uerrmsgbox("Windir %s ",0,sysdir);                             //~v57qR~
//  uerrmsgbox("PATH=%s",0,getenv("PATH"));                        //~v57qR~
	if (Pcol && Prow)                                              //~v57tI~
    {                                                              //~v57tI~
    	stinfo.dwXCountChars=Pcol;                                 //~v57tR~
    	stinfo.dwYCountChars=Prow;                                 //~v57tR~
        stinfo.dwFlags|=STARTF_USECOUNTCHARS;                      //~v57tR~
    }                                                              //~v57tI~
    cmdnm=NULL;                                                    //~v57qR~
    if (udosiswinnt())                                             //~v57qR~
    	cmdstr="cmd.exe";                                          //~v57qR~
    else                                                           //~v57qR~
    	cmdstr="command.com";                                      //~v57qR~
	                                                               //~v57qR~
    rc=CreateProcess(cmdnm,                                        //~v57qR~
                    cmdstr,           //comandline string          //~v57qR~
                    NULL,           //process security             //~v57qR~
                    NULL,           //thread  security             //~v57qR~
                    FALSE,          //inheritance                  //~v57qR~
                    CREATE_DEFAULT_ERROR_MODE|                     //~v57qR~
                    CREATE_NEW_CONSOLE|                            //~v57qR~
                    CREATE_NEW_PROCESS_GROUP,                      //~v57qR~
                    NULL,           //pass env                     //~v57qR~
                    NULL,           //curr dir setting             //~v57qR~
                    &stinfo,  		//startup info                 //~v57qR~
                    &pinfo);        //output process info          //~v57qR~
    if (!rc)                                                       //~v57qR~
    {                                                              //~v57qR~
        rc=GetLastError();                                         //~v57qR~
    	uerrmsg("subshell CreateProcess failed rc=%d)",0,          //~v57qR~
        		rc);                                               //~v57qR~
    }                                                              //~v57qR~
    else                                                           //~v57qR~
		rc=0;                                                      //~v57qR~
    return rc;                                                     //~v57qR~
}//ucreateshproc                                                   //~v57qR~
#endif                                                             //~v57qR~
//**************************************************************** //~v50HI~
//*usystem                                                         //~v50HI~
//* issue command syncronous                                       //~v50HI~
//*parm1:command string                                            //~v50HI~
//*retrn:rc(=errno)                                                //~v50HI~
//**************************************************************** //~v50HI~
int usystem2(int Popt,char *Pcmd)                                  //~v50HI~
{                                                                  //~v50HI~
	int rc;                                                        //~v50HI~
#ifdef WINCON                                                      //~v61pI~
	UINT modestdi=0;                                                 //~v5maR~//~v6h7R~
#endif                                                             //~v61pI~
//********************                                             //~v50HI~
    UTRACEP("%s:Suprocopt=x%x,cmd=%s\n",UTT,Suprocopt,Pcmd);       //~v70cR~
#if defined(UNX) || defined(W32)                                   //~v5bxI~
  	if (!(Suprocopt & UPROC_NOSVRUSE))	//!(explicit not use server)//~v5bxI~
    {                                                              //~v5bxI~
	    if (Sserverstat & SVRS_LAZY) //start cmd server at cmd req //~v5bxI~
        {                                                          //~v5bxI~
		    rc=Scmdservercallback(CMDCB_INIT,Scallbackparm);       //~v5bxR~
            if (rc)                                                //~v5bxI~
		    	Sserverstat=0;	//setup failed                     //~v5bxI~
        }                                                          //~v5bxI~
    	if (Sserverstat & SVRS_READY)	//setup sccess             //~v5bxR~
//        	return usystem_cmdserverreq(Popt,Pcmd,0,0,Sfdpipew,Sfdpiper);//no stdo/stde filename//~v5ccR~
          	return usystem_cmdserverreq(Popt,Scmdserverchildpid,Pcmd,0,0,Sfdpipew,Sfdpiper);//no stdo/stde filename//~v5ccI~
    }                                                              //~v5bxI~
#endif                                                             //~v5bxI~
    IFDEF_WINCON(                                                  //~v5maR~
					if (Popt & UPROC_KEEPMODE)                     //~v5maR~
    				{                                              //~v5maR~
						modestdi=ugetconsolemode(0);               //~v5maR~
                    }                                              //~v5maR~
                );                                                 //~v5maR~
	Suprocopt|=(Popt&(UPROC_NOMSG|UPROC_NOOKMSG));                 //~v50HR~
	rc=usystem(Pcmd);                                              //~v50HR~
	Suprocopt&=~(Popt&(UPROC_NOMSG|UPROC_NOOKMSG));                //~v50HI~
    IFDEF_WINCON(                                                  //~v5maR~
					if (Popt & UPROC_KEEPMODE)                     //~v5maR~
    				{                                              //~v5maR~
						usetconsolemode2(0/*opt*/,0,modestdi,0);   //~v5maR~
                    }                                              //~v5maR~
                );                                                 //~v5maR~
    return rc;                                                     //~v50HI~
}//usystem2                                                        //~v5ccR~
//****************************************************************//~5A10I~
//*usystem                                                      //~5A10I~
//* issue command syncronous                                    //~5A10I~
//*parm1:command string                                         //~5A10I~
//*retrn:rc(=errno)                                             //~5A10I~
//*ifdef ARMXXE                                                    //~v77LI~
//*  if !systemArm() : if >=API29(A10:Q) && isSupportedSO() (:highlight,iconv,xfg,...)//~v77LI~
//*                       callXeToolSO(): dlopen .so && func_mainOnThread(func_main)//~v77LI~
//   else system(Pcmd)                                             //~v77LI~
//****************************************************************//~5A10I~
int usystem(char *Pcmd)                                         //~5A10I~
{                                                               //~5A10I~
    int rc;                                                     //~5A10R~
    char *pc;                                                   //~5A15I~
#ifdef ARMXXE	//no support for system call from xsub tool        //~vc70I~
    int swSystem;                                                  //~vc70I~
#endif                                                             //~vc70I~
//*********************                                         //~5A10I~
    UTRACED("Pcmd",Pcmd,(int)strlen(Pcmd));                        //~v6xiR~
    UTRACEP("%s:Pcmd=%s,envPATH=%s,PWD=%s\n",UTT,Pcmd,getenv("PATH"),getenv("PWD"));      //~v701I~//~v70cR~//~v77LR~
//#ifdef ARM                                                       //~v70cR~
//    #ifdef XXE                                                   //~v70cR~
//        setArmEnvPATH();    //TODO test                          //~v70cR~
//    #endif                                                       //~v70cR~
//#endif                                                           //~v70cR~
#ifdef ARMXXE                                                        //~v77CR~//~vc70R~
    int uproc_callxetoolTest(char *Pcmd,int *Pprc);                                   //~v77CI~//~v77DR~//~vc70R~
  if (1)    //TODO Test                                            //~vc70R~
    if (uproc_callxetoolTest(Pcmd,&rc)) //TODO test                        //~v77CR~//~v77DR~//~vc70R~
    	return rc;                                                 //~vc70I~
#endif                                                             //~v77CI~
    GuprocStat|=GUPS_SYSTEMCALL;                                   //~v701R~
#ifdef W32UNICODE                                                  //~v6upI~
//    if (strchr(Pcmd,UD_NOTLC))                                   //~v6upR~
//        rc=usystemW(0,Pcmd);                                     //~v6upR~
//    else                                                         //~v6upR~
//  UTRACEP("%s:call system() Pcmd=%s,envPATH=%s\n",UTT,Pcmd,getenv("PATH"));//~v70cR~
    	rc=system(Pcmd);                                           //~v6upI~
    UTRACEP("%s:call system() returned rc=%d\n",UTT,rc);           //~v70cI~
    GuprocStat&=~GUPS_SYSTEMCALL;                                  //~v701R~
    if (rc)                                                        //~v6upI~
#else                                                              //~v6upI~
//  if (rc=system(Pcmd),rc)                                        //~v701R~
  #ifdef ARMXXE	//no support for system call from xsub tool        //~v77DI~
    UTRACEP("%s:system or systemArm GaxeStatus=0x%x\n",UTT,GaxeStatus);//~vc70M~
    rc=0;                                                          //~vc70I~
    swSystem=0;                                                    //~vc70I~
   if ((GaxeStatus & AXES_MXTOOL)!=0)	//system call option       //~vc70R~
   {                                                               //~vc70I~
    swSystem=1;  //call system()                                   //~vc70R~
    UTRACEP("%s:call system by AXES_MXTOOL option");               //~vc70I~
   }                                                               //~vc70I~
   else                                                            //~vc70I~
   if ((GaxeStatus & AXES_SOPROC)!=0)	//system call option       //~vc70I~
   {                                                               //~vc70I~
    swSystem=systemArmProc(Pcmd,&rc)==0;                           //~vc70I~
    UTRACEP("%s:after systemArmProc() by AXES_SOPROC rc=%d,cmd=%s\n",UTT,rc,Pcmd);//~vc70I~
   }                                                               //~vc70I~
   else                                                            //~vc70I~
   if (!systemArm(Pcmd,&rc))  //not executed alternative of system() api//~v77DI~
    swSystem=1;                                                    //~vc70I~
   if (swSystem)                                                   //~vc70I~
  #endif                                                           //~v77DI~
    rc=system(Pcmd);                                               //~v701R~
    UTRACEP("%s:after system() rc=%d,cmd=%s\n",UTT,rc,Pcmd);       //~v77DI~
    GuprocStat&=~GUPS_SYSTEMCALL;                                  //~v701R~
    if (rc)                                                        //~v701R~
#endif                                                             //~v6upI~
    {                                                           //~5A15I~
        pc=strpbrk(Pcmd," ,");      //search delm               //~5A15I~
#ifndef UNX                                                        //~v327I~
#ifdef DOS                                                      //~5A10I~
#else                                                           //~5A10I~
        if (rc==1041)   //SYS1041 not found                     //~5A15R~
        {                                                       //~5A15R~
            if (pc)                                             //~5A15I~
                *pc=0;  //cut operand                           //~5A15I~
            uprocerrnotf(Pcmd,-1);                              //~5A15R~
            return -1;                                          //~5A15R~
        }                                                       //~5A15R~
#endif                                                          //~5A10I~
#endif //!UNX                                                      //~v327I~
                                                                //~5A10I~
        if (rc==-1) //meaningfull errno                         //~5A15R~
        {                                                       //~5A15R~
            switch (rc=errno,rc)                                //~5A15R~
            {                                                   //~5A15R~
                                                                   //~v394I~
#ifdef UNX                                                         //~v394I~
#else  //!UNX                                                      //~v394I~
#if defined(DOS) || defined(W32)                                   //~v394R~
            case ENOEXEC:   //not excutable                     //~5A15R~
            case ENOENT:    //not found                         //~5A15R~
                uprocerrnotf("COMMAND.COM",-1);                 //~5A15R~
#else                                                           //~5A10I~
            case ENOCMD:    //not found                         //~5A15R~
                uprocerrnotf("CMD.EXE",-1);                     //~5A15R~
#endif                                                          //~5A10I~
                break;                                          //~5A15R~
#if defined(DOS) || defined(W32)                                   //~v394R~
            case E2BIG:    //too large parameter(max 128) or env(max 32kb)//~5A15R~
                uprocerr2big(Pcmd,-1);                          //~5A15R~
                break;                                          //~5A15R~
#else                                                           //~5A10I~
            case EOS2ERR:    //os2 err                          //~5A15R~
                uerrmsg("OS/2 system error,_doserrno=%d",       //~5A15R~
                        0,                                      //~5A15R~
                        _doserrno);                             //~5A15R~
                break;                                          //~5A15R~
#endif                                                          //~5A10I~
#endif //!UNX                                                      //~v394I~
            case ENOMEM:                                        //~5A15R~
                if (pc)                                         //~5A15I~
                    *pc=0;  //cut operand                       //~5A15I~
                uprocerrmem(Pcmd,-1);                           //~5A15R~
                break;                                          //~5A15R~
            default:                                            //~5A15R~
                uerrapi1("function \"system()\"",Pcmd,rc);      //~5A15R~
            }                                                   //~5A15R~
            return -1;                                          //~5A15R~
        }//rc==-1                                               //~5A15R~
    }//rc!=0                                                    //~5A15I~
  if (!(Suprocopt & UPROC_NOMSG)                                   //~v50HR~
  &&   (rc || !(Suprocopt & UPROC_NOOKMSG)))                       //~v50HR~
  {                                                                //~v50HI~
#ifdef UNX                                                         //~v394I~
    uerrmsg("%s ended,rc=%d(x%04x)",                               //~v394I~
            "%s が終了,rc=%d(x%04x)",                              //~v394I~
            Pcmd,rc,rc);                                           //~v394I~
#else  //!UNX                                                      //~v394I~
    uerrmsg("%s ended,rc=%d(x%02x)",                               //~v394R~
            "%s が終了,rc=%d(x%02x)",                              //~v394R~
            Pcmd,rc,rc);                                           //~v327R~
#endif //!UNX                                                      //~v394I~
  }                                                                //~v50HI~
    return rc;                                                  //~5A10R~
}//usystem                                                      //~5A10I~
                                                                //~5A10I~
//****************************************************************//~5A10I~
//*uspawnl                                                      //~5A10I~
//* create child process                                        //~5A10I~
//*parm1 :mode flag (P_WAIT(0) / P_NOWAIT(1) (OS/2 only) / P_OVERLAY)//~v6xkR~
//*parm2 :pathname                                              //~5A10I~
//*parm3 :arg0                                                  //~5A10I~
//*parm4 :arg1  parm1  for pathname(option)                     //~5A10I~
//*      :                                                      //~5A10I~
//*parm13:arg10 parm10 for pathname                             //~5A10I~
//*parm14:arg11 parm11 for pathname(MAX 10 parm,last must be NULL)//~5A10I~
//*retrn:rc(=errno)                                             //~5A10I~
//****************************************************************//~5A10I~
//int uspawnl(int Pmodeflag,char *Ppathname,char *Parg0,...)       //~v6xkR~
LONGHANDLE uspawnl(int Pmodeflag,char *Ppathname,char *Parg0,...)  //~v6xkI~
{                                                               //~5A10I~
    va_list pargn;                                              //~5A10I~
    char *argsave[SPAWNMAXPARM];                                //~5A10I~
#ifdef UNX                                                         //~v327I~
    char *argv[SPAWNMAXPARM+1];                                    //~v327I~
#endif                                                             //~v327I~
//  int ii,rc;                                                     //~v6xkR~
    int ii;                                                        //~v6xkI~
    LONGHANDLE rc;                                                 //~v6xkI~
//*********************                                         //~5A10I~
	UTRACEP("%s:pathname=%s\n",Ppathname);                         //~v77DI~
    uprocopt(&Pmodeflag);                                          //~v50HI~
                                                                   //~v50HI~
    va_start(pargn,Parg0);   //argn point Parg1                 //~5A10I~
    for (ii=0;ii<SPAWNMAXPARM;ii++)                             //~5A10I~
        if ((argsave[ii]=va_arg(pargn,char *)),!argsave[ii])    //last null ptr//~v5anI~
            break;                                              //~5A10I~
    va_end(pargn);                                              //~5A10I~
//  printf("spawn va_arg,%s,%s\n",argsave[0],argsave[1]);//@@@@ //~5A10R~
    if (ii==SPAWNMAXPARM)   //missing null                      //~5A10I~
    {                                                           //~5A10I~
        uerrmsg("Too many parameters(max 11 containing last null)",//~5A10I~
                "パラメータは最後のNULLを含めて最大11個");      //~5A10I~
        return -1;                                              //~5A10I~
    }                                                           //~5A10I~
#ifdef UNX                                                         //~v327I~
    argv[0]=Parg0;                                                 //~v327I~
//  memcpy(argv+1,argsave,(ii+1)*sizeof(argsave[0]));              //~v6xiR~
    memcpy(argv+1,argsave,(UINT)(ii+1)*sizeof(argsave[0]));        //~v6xiI~
    rc=spawnv(Pmodeflag,Ppathname,argv);    //do by ugcclib        //~v327I~
#else   //!UNX                                                     //~v327I~
//  rc=spawnl(Pmodeflag,Ppathname,Parg0,                           //~v6xkR~
    rc=_spawnl(Pmodeflag,Ppathname,Parg0,                          //~v6xkR~
        argsave[0],argsave[1],argsave[2],argsave[3],argsave[4],argsave[5],//~5A10I~
        argsave[6],argsave[7],argsave[8],argsave[9],argsave[10]);//~5A15R~
#endif //!UNX                                                      //~v327I~
    return uspawnrc(Pmodeflag,Ppathname,rc);                    //~5A10R~
}//spawnl                                                          //~v327R~
                                                                //~5A10I~
//****************************************************************//~5A10I~
//*uspawnlp                                                     //~5A10I~
//* create child process (search module for dir of PATH environment)//~5A10I~
//*parm1 :mode flag (P_WAIT / P_NOWAIT (OS/2 only) / P_OVERLAY) //~5A10I~
//*parm2 :pathname                                              //~5A10I~
//*parm3 :arg0                                                  //~5A10I~
//*parm4 :arg1  parm1  for pathname(option)                     //~5A10I~
//*      :                                                      //~5A10I~
//*parm13:arg10 parm10 for pathname                             //~5A10I~
//*parm14:arg11 parm11 for pathname(MAX 10 parm,last must be NULL)//~5A10I~
//*retrn:rc(=errno)                                             //~5A10I~
//****************************************************************//~5A10I~
//int uspawnlp(int Pmodeflag,char *Ppathname,char *Parg0,...)      //~v6xkR~
LONGHANDLE uspawnlp(int Pmodeflag,char *Ppathname,char *Parg0,...) //~v6xkI~
{                                                               //~5A10I~
    va_list pargn;                                              //~5A10I~
    char *argsave[SPAWNMAXPARM];                                //~5A10I~
#ifdef UNX                                                         //~v327I~
    char *argv[SPAWNMAXPARM+1];                                    //~v327I~
#endif                                                             //~v327I~
//  int ii,rc;                                                     //~v6xkR~
    int ii;                                                        //~v6xkI~
    LONGHANDLE rc;                                                 //~v6xkI~
//*********************                                         //~5A10I~
	UTRACEP("%s:pathname=%s\n",Ppathname);                         //~v77DI~
#ifdef ARMXXE                                                      //~v77FI~
	if (unsupportedFuncArm("spawnlp",Ppathname))                   //~v77FI~
        return -1;                                                 //~v77FI~
#endif                                                             //~v77FI~
    uprocopt(&Pmodeflag);                                          //~v50HI~
                                                                   //~v50HI~
    va_start(pargn,Parg0);   //argn point Parg1                 //~5A10I~
    for (ii=0;ii<SPAWNMAXPARM;ii++)                             //~5A10I~
    {                                                              //~v022I~
        argsave[ii]=va_arg(pargn,char *);   //last null ptr        //~v5anI~
        if (!argsave[ii])   //last null ptr                        //~v022I~
            break;                                              //~5A10I~
    }                                                              //~v022I~
    va_end(pargn);                                              //~5A10I~
//  printf("spawn va_arg,%s,%s\n",argsave[0],argsave[1]);//@@@@ //~5A10R~
    if (ii==SPAWNMAXPARM)   //missing null                      //~5A10I~
    {                                                           //~5A10I~
        uerrmsg("Too many parameters(max 11 containing last null)",//~5A10I~
                "パラメータは最後のNULLを含めて最大11個");      //~5A10I~
        return -1;                                              //~5A10I~
    }                                                           //~5A10I~
#ifdef UNX                                                         //~v327I~
    argv[0]=Parg0;                                                 //~v327I~
//  memcpy(argv+1,argsave,(ii+1)*sizeof(argsave[0]));              //~v6xiR~
    memcpy(argv+1,argsave,(UINT)(ii+1)*sizeof(argsave[0]));        //~v6xiI~
    rc=spawnvp(Pmodeflag,Ppathname,argv);   //do by ugcclib        //~v327I~
#else   //!UNX                                                     //~v327I~
//  rc=spawnlp(Pmodeflag,Ppathname,Parg0,                          //~v6xkR~
    rc=_spawnlp(Pmodeflag,Ppathname,Parg0,                         //~v6xkR~
        argsave[0],argsave[1],argsave[2],argsave[3],argsave[4],argsave[5],//~5A10I~
        argsave[6],argsave[7],argsave[8],argsave[9],argsave[10]);//~5A15R~
#endif //!UNX                                                      //~v327I~
    return uspawnrc(Pmodeflag,Ppathname,rc);                    //~5A10R~
}//uspawnlp                                                     //~5A10I~
                                                                //~5A10I~
//**************************************************************** //~v065I~
//*uspawnvp                                                        //~v065I~
//* create child process (search module for dir of PATH environment)//~v065I~
//*parm1 :mode flag (P_WAIT / P_NOWAIT (OS/2 only) / P_OVERLAY)    //~v065I~
//*parm2 :cmdname                                                  //~v065I~
//*parm3 :argv                                                     //~v065I~
//*retrn:rc(=errno) or -1(if not executed),UALLOC_FAILED,99(uparsecmd failed)//~v130R~
//**************************************************************** //~v065I~
//int uspawnvp(int Pmodeflag,char *Ppathname,char **Pargv)         //~v6xkR~
LONGHANDLE uspawnvp(int Pmodeflag,char *Ppathname,char **Pargv)    //~v6xkI~
{                                                                  //~v065I~
//  int rc;                                                        //~v6xkR~
    LONGHANDLE rc;                                                 //~v6xkI~
#ifndef UNX                                                        //~v5g9R~
#ifdef DPMI                                                        //~v082R~
#else                                                              //~v082R~
    void *pcv;                                                     //~v082R~
    char *pc,*pcs,**pcp;                                           //~v082R~
    int len,ii,jj,parmno,lenw;                                     //~v082R~
#endif                                                             //~v082R~
#endif     //!UNX                                                  //~v5g9R~
    FILE *fh0=NULL;                                                     //~v5maI~//~v6h6R~
//*********************                                            //~v065I~
	UTRACEP("%s:pathname=%s\n",UTT,Ppathname);                     //~v77DI~
#ifdef ARMXXE                                                      //~v77FI~
	if (unsupportedFuncArm("spawnvp",Ppathname))                   //~v77FR~
        return -1;                                                 //~v77FR~
#endif                                                             //~v77FI~
    if (Pmodeflag & UPROC_NULLSI)   //nul stdin                    //~v5maI~
      if (!(Pmodeflag & P_NOWAIT))                                 //~v5mtI~
		if (!(fh0=uredirect(0,NULLDEVICE,0))) //append stdin/stderr to so file//~v5maI~
	    	return 8;                                              //~v5maI~
    uprocopt(&Pmodeflag);                                          //~v50HI~
#ifndef UNX                                                        //~v5g9R~
#ifdef DPMI                                                        //~v082R~
#else                                                              //~v082R~
//calc space embedding parm len                                    //~v082R~
    for(ii=jj=len=0;pc=Pargv[ii],pc;ii++)                          //~v082R~
    {                                                              //~v082R~
        if (strchr(pc,' '))                                        //~v082R~
        {                                                          //~v082R~
            jj++;                                                  //~v082R~
            len+=(int)strlen(pc);                                  //~v082R~
        }                                                          //~v082R~
    }                                                              //~v082R~
    if (jj) //space embedding parm exist                           //~v082R~
    {                                                              //~v082R~
        parmno=ii+1;                                               //~v082R~
        len=jj+len*2;       //string area len                      //~v082R~
//      pcp=pcv=umalloc((UINT)(parmno*4+len));                     //~v082R~//~v690R~
        pcp=pcv=umalloc((UINT)(parmno*PTRSZ+len));                 //~v690I~
        UALLOCCHK(pcv,UALLOC_FAILED);                              //~v082R~
        pcs=(void*)(&pcp[parmno]);                                 //~v082R~
        for(ii=0;pc=Pargv[ii],pc;ii++)                             //~v082R~
            if (strchr(pc,' '))                                    //~v082R~
            {                                                      //~v082R~
                pcp[ii]=pcs;                                       //~v082R~
//              uparsein(pc,pcs,len,0,'\"');                       //~v130R~
//              lenw=(int)strlen(pcs)+1;                           //~v130R~
                if (uparsecmdin(pc,pcs,len,&lenw)>=4)   //out area shortage//~v130I~
                {                                                  //~v130I~
                    ufree(pcv);                                    //~v130I~
                    return 99;                                     //~v130I~
                }                                                  //~v130I~
                lenw++;     //with last null                       //~v130I~
                len-=lenw;                                         //~v082R~
                pcs+=lenw;                                         //~v082R~
            }                                                      //~v082R~
            else                                                   //~v082R~
                pcp[ii]=pc;                                        //~v082R~
        pcp[ii]=0;  //last indicator                               //~v082R~
        Pargv=pcv;                                                 //~v082R~
    }                                                              //~v082R~
    else                                                           //~v082R~
        pcv=0;                                                     //~v082R~
#endif                                                             //~v082R~
#endif	//!UNX                                                     //~v5g9R~
//  for (ii=0;Pargv[ii];ii++)                                      //~v5g9R~
//      UTRACEP("uspawnvp %d=%s\n",ii,Pargv[ii]);                  //~v5g9R~
//  rc=spawnvp(Pmodeflag,Ppathname,Pargv);                         //~v5mtR~
//  rc=spawnvp(Pmodeflag & 0xff,Ppathname,Pargv);                  //~v6xkR~
#ifdef W32                                                         //~v6xkI~
    rc=_spawnvp(Pmodeflag & 0xff,Ppathname,Pargv);                 //~v6xkR~
#else                                                              //~v6xkI~
	rc=spawnvp(Pmodeflag & 0xff,Ppathname,Pargv);                  //~v6xkI~
#endif                                                             //~v6xkI~
	UTRACEP("%s:spawnvp rc=%d\n",UTT,rc);                          //~v77DI~
#ifndef UNX                                                        //~v5g9R~
#ifdef DPMI                                                        //~v082R~
#else                                                              //~v082R~
    if (pcv==Pargv)                                                //~v082R~
        ufree(pcv);                                                //~v082R~
#endif                                                             //~v082R~
#endif	//!UNX                                                     //~v5g9R~
    if (Pmodeflag & UPROC_NULLSI)   //nul stdin                    //~v5maI~
      if (!(Pmodeflag & P_NOWAIT))                                 //~v5mtI~
    {                                                              //~v5maI~
    	if (uredirectrestore(0))                                   //~v5maI~
    		return 8;                                              //~v5maI~
        fclose(fh0);                                               //~v5maI~
    }                                                              //~v5maI~
    return uspawnrc(Pmodeflag,Ppathname,rc);                       //~v065I~
}//uspawnvp                                                        //~v065I~
//**************************************************************** //~v50HI~
//*uprocopt                                                        //~v50HI~//~v6upR~
//* ch uproc option                                                //~v50HI~
//**************************************************************** //~v50HI~
void uprocopt(int *Ppmodeflag)                                     //~v50HI~
{                                                                  //~v50HI~
	if (*Ppmodeflag & UPROC_NOOKMSG)                               //~v50HI~
    {                                                              //~v50HM~
		*Ppmodeflag &= ~UPROC_NOOKMSG;                             //~v50HI~
        Suprocopt |=  UPROC_NOOKMSG;                               //~v50HI~
    }                                                              //~v50HM~
    else                                                           //~v50HM~
        Suprocopt &= ~UPROC_NOOKMSG;                               //~v50HI~
	if (*Ppmodeflag & UPROC_NOMSG)                                 //~v50HI~
    {                                                              //~v50HI~
		*Ppmodeflag &= ~UPROC_NOMSG;                               //~v50HI~
        Suprocopt |=  UPROC_NOMSG;                                 //~v50HI~
    }                                                              //~v50HI~
    else                                                           //~v50HI~
        Suprocopt &= ~UPROC_NOMSG;                                 //~v50HI~
	return;                                                        //~v50HI~
}//uprocopt                                                        //~v6upR~
//****************************************************************//~5A10I~
//*uspawnrc                                                     //~5A10I~
//* r.c chk of spawn                                            //~5A10I~
//*parm1 :mode flag (P_WAIT / P_NOWAIT (OS/2 only) / P_OVERLAY) //~5A10I~
//*parm2 :pathname                                              //~5A10I~
//*parm3 :api rc                                                //~5A10I~
//*retrn :rc(=errno)                                            //~5A10I~
//****************************************************************//~5A10I~
//int uspawnrc(int Pmodeflag,char *Ppathname,int Prc)              //~v6xkR~
LONGHANDLE uspawnrc(int Pmodeflag,char *Ppathname,LONGHANDLE Prc)  //~v6xkI~
{                                                               //~5A10I~
//  int rc;                                                        //~v6xkR~
    LONGHANDLE rc;                                                 //~v6xkI~
    UCHAR wkpid1[32],wkpid2[32];                                   //~v6xkI~
//*********************                                         //~5A10I~
	UTRACEP("%s:spawnrc pathname=%s,rc=%p\n",UTT,Ppathname,Prc);   //~v77DI~
    if ((rc=Prc)==-1)                                              //~v5bwR~
    {                                                           //~5A10I~
        switch (rc=errno,rc)                                    //~5A10R~
        {                                                       //~5A10R~
        case ENOEXEC:   //not excutable                         //~5A10R~
        case ENOENT:    //not found                             //~5A10R~
            uprocerrnotf(Ppathname,-1);                         //~5A10R~
            break;                                              //~5A10R~
        case ENOMEM:                                            //~5A10R~
            uprocerrmem(Ppathname,-1);                          //~5A10R~
            break;                                              //~5A10I~
        case EINVAL:                                            //~5A10R~
//          uerrmsg("Mode parm(%d) err",0,Pmodeflag);              //~v6hmR~
            uerrmsg("spawn parm err(%s,mode=%d)",0,Ppathname,Pmodeflag);//~v6hmI~
            break;                                              //~5A10I~
#ifdef DOS                                                      //~5A10I~
        case E2BIG:    //too large parameter(max 128) or env(max 32kb)//~5A10R~
            uprocerr2big(Ppathname,rc);                         //~5A10R~
#else                                                           //~5A10I~
        case EAGAIN:    //process limit                         //~5A10R~
            uerrmsg("Too many process creation",0);             //~5A10R~
#endif                                                          //~5A10I~
            break;                                              //~5A10I~
        default:                                                //~5A10I~
//          uerrapi1("function \"spawnxx()\"",Ppathname,rc);       //~v6xkR~
            uerrapi1("function \"spawnxx()\"",Ppathname,(int)rc);  //~v6xkI~
        }                                                       //~5A10R~
        return -1;                                              //~5A10I~
    }                                                           //~5A10I~
    if (Pmodeflag & P_NOWAIT)                                      //~v5bwM~
    	rc=0;                                                      //~v5bwI~
  if (!(Suprocopt & UPROC_NOMSG)                                   //~v50HI~
  &&   (rc || !(Suprocopt & UPROC_NOOKMSG)))                       //~v50HR~
  {                                                                //~v50HI~
    if (Pmodeflag & P_NOWAIT)                                      //~v5ivI~
//      uerrmsg("%s spawned pid=%d(0x%x)",                         //~v6xkR~
//          "%s を起動 pid=%d(0x%x)",                              //~v6xkR~
//          Ppathname,Prc,Prc);                                    //~v6xkR~
        uerrmsg("%s spawned pid=%s(0x%s)",                         //~v6xkI~
            "%s を起動 pid=%s(0x%s)",                              //~v6xkI~
            Ppathname,ueditLONGHANDLE(0,wkpid1,sizeof(wkpid1),"%$d",Prc),ueditLONGHANDLE(0,wkpid2,sizeof(wkpid2),"%$x",Prc));//~v6xkI~
    else                                                           //~v5ivI~
    {                                                              //~v5ivI~
#ifdef UNX                                                         //~v394I~
    uerrmsg("%s ended,rc=%d(x%04x)",                               //~v394I~
            "%s が終了,rc=%d(x%04x)",                              //~v394I~
            Ppathname,rc,rc);                                      //~v394I~
#else  //!UNX                                                      //~v394I~
    uerrmsg("%s ended,rc=%d(x%02x)",                               //~v394R~
            "%s が終了,rc=%d(x%02x)",                              //~v394R~
            Ppathname,rc,rc);                                      //~v327R~
#endif //!UNX                                                      //~v394I~
    }                                                              //~v5ivI~
  }//msg option                                                    //~v50HI~
    if (Pmodeflag & P_NOWAIT)                                      //~v5bwI~
    	rc=Prc;                                                    //~v5bwI~
    return rc;                                                  //~5A10R~
}//uspawnrc                                                     //~5A10I~
                                                                //~5A10I~
#if defined(DOS) || defined(W32)                                   //~v394R~
//****************************************************************//~5A10I~
//*uprocerr2big                                                 //~5A10I~
//* E2BIG err msg                                               //~5A10I~
//*parm1 :pathname                                              //~5A10I~
//*parm2 :rc                                                    //~5A10R~
//*retrn :rc                                                    //~5A10I~
//****************************************************************//~5A10I~
int uprocerr2big(char *Ppathname,int Prc)                       //~5A10R~
{                                                               //~5A10I~
//*********************                                         //~5A10I~
    uerrmsg("Too big parameter or environment information(%s)", //~5A10R~
            0,                                                  //~5A10I~
             Ppathname);                                        //~5A10I~
    return Prc;                                                 //~5A10I~
}//uprocerr2big                                                 //~5A10R~
#else                                                           //~5A10I~
#endif                                                          //~5A10I~
                                                                //~5A10I~
//****************************************************************//~5A10I~
//*uprocerrmem                                                  //~5A10I~
//* ENOMEM err msg                                              //~5A10I~
//*parm1 :pathname                                              //~5A10R~
//*parm2 :rc                                                    //~5A10I~
//*retrn :rc                                                    //~5A10I~
//****************************************************************//~5A10I~
int uprocerrmem(char *Ppathname,int Prc)                        //~5A10R~
{                                                               //~5A10I~
//*********************                                         //~5A10I~
    uerrmsg("Out of memory for %s",                             //~5A10R~
            "%s のための記憶域不足",                            //~5A10R~
            Ppathname);                                         //~5A10I~
    return Prc;                                                 //~5A10I~
}//uprocerrmem                                                  //~5A10I~
                                                                //~5A10I~
//****************************************************************//~5A10I~
//*uprocerrnotf                                                 //~5A10I~
//* ENOMEM err msg                                              //~5A10I~
//*parm1 :pathname                                              //~5A10I~
//*parm2 :rc                                                    //~5A10I~
//*retrn :rc                                                    //~5A10I~
//****************************************************************//~5A10I~
int uprocerrnotf(char *Ppathname,int Prc)                       //~5A10I~
{                                                               //~5A10I~
//*********************                                         //~5A10I~
    uerrmsg("%s is not found nor executable",                   //~5A10I~
            "%s が見つからないか実行できない",                     //~v053R~
            Ppathname);                                         //~5A10I~
    return Prc;                                                 //~5A10I~
}//uprocerrmem                                                  //~5A10I~
                                                                   //~v064I~
//*********************************************************************//~v064M~
//*uexecchk:filename is executable *                               //~v064M~
//*         chk extention if available,if not search path env var  //~v064M~
//*p1 :filename with or without extention                          //~v064M~
//*p2 :output fullpath with ext added when found                   //~v064M~
//*rc :0:not executable,1:com,2:exe,3:cmd,4:bat                    //~v181R~
//*********************************************************************//~v064M~
int uexecchk(char *Pfile,char *Pfullpath)                          //~v064M~
{                                                                  //~v064M~
    char *pc,*penv;                                                //~v064M~
    int rc,ii,opdno;                                               //~v064M~
    UINT len;                                                      //~v064M~
//********************                                             //~v064M~
    UERRSETSNOMSG();    //save and set nomsg option                //~v064M~
//printf("input=%s\n",Pfile);                                      //~v064R~
    pc=ufullpath(Pfullpath,Pfile,_MAX_PATH);                       //~v064M~
    if (!pc)     //not ok                                          //~v064M~
    {                                                              //~v064M~
        UERRBACKNOMSG();    //restore nomsg option                 //~v064M~
        return 0;                   //one of executable extention name//~v064M~
    }                                                              //~v064M~
//printf("fullpath=%s\n",Pfullpath);                               //~v064R~
#ifndef UNX                                                        //~v327I~
//ext chk if exist                                                 //~v064M~
    if (rc=uextchk(Pfile),rc!=9)    //extention chk,9 mean no extention//~v064M~
    {                                                              //~v064M~
        UERRBACKNOMSG();    //restore nomsg option                 //~v064M~
        return rc;                  //one of executable extention name//~v064M~
    }                                                              //~v064M~
#endif //!UNX                                                      //~v327I~
//search current dir                                               //~v064M~
    if (rc=uextdirsrch(Pfullpath),rc)   //found                    //~v064M~
    {                                                              //~v064M~
        UERRBACKNOMSG();    //restore nomsg option                 //~v064M~
        return rc;                                                 //~v064M~
    }//dirlist entry                                               //~v064M~
//search PATH= env                                                 //~v064M~
    if (PATHLEN(Pfile)>0)   //contain "\"                          //~v064M~
    {                                                              //~v064M~
        UERRBACKNOMSG();    //restore nomsg option                 //~v064M~
        return 0;                   //one of executable extention name//~v064M~
    }                                                              //~v064M~
#ifndef UNX                                                        //~v327I~
    if (*(Pfile+1)==':')    //d:                                   //~v064M~
        Pfile+=2;           //drop drive                           //~v064M~
#endif //!UNX                                                      //~v327I~
    if (!(penv=getenv("PATH")))                                    //~v064M~
    {                                                              //~v064M~
        UERRBACKNOMSG();    //restore nomsg option                 //~v064M~
        return 0;                   //one of executable extention name//~v064M~
    }                                                              //~v064M~
//printf("env=%s\n",penv);                                         //~v064R~
//  len=strlen(penv);                                              //~v064M~//~v6xiR~
    len=(UINT)strlen(penv);                                        //~v6xiI~
    if (pc=strchr(penv,' '),pc) //drop after ' '                   //~v064M~
//      len=(ULONG)pc-(ULONG)penv;                                 //~v064M~//~v6hhR~
//      len=(ULPTR)pc-(ULPTR)penv;                                 //~v6xkR~
        len=(UINT)((ULPTR)pc-(ULPTR)penv);                         //~v6xiR~
    pc=umalloc(len+1);                                             //~v064M~
    memcpy(pc,penv,len);                                           //~v064M~
    *(pc+len)=0;                                                   //~v064M~
    penv=pc;                                                       //~v064M~
    if (rc=uparse(penv,penv,&opdno,0,";"),rc)                      //~v064M~
    {                                                              //~v064M~
        UERRBACKNOMSG();    //restore nomsg option                 //~v064M~
        return 0;                   //one of executable extention name//~v064M~
    }//uparse fail                                                 //~v064M~
    pc=penv;                                                       //~v064M~
    for (ii=0;ii<opdno;ii++)                                       //~v064M~
    {                                                              //~v064M~
//printf("env%d=%s\n",ii,pc);                                      //~v064R~
//      if (len=strlen(pc),len)                                    //~v064M~//~v6xiR~
        if (len=(UINT)strlen(pc),len)                              //~v6xiI~
        {                                                          //~v064M~
            memcpy(Pfullpath,pc,len);                              //~v064M~
            if (PATHLEN(pc)!=(int)len)  //last is not "\"          //~v065R~
                *(Pfullpath+len++)=DIR_SEPC; // '\\';              //~v327R~
            strcpy(Pfullpath+len,Pfile);                           //~v064M~
            if (rc=uextdirsrch(Pfullpath),rc)   //found            //~v064M~
                break;                                             //~v064M~
        }                                                          //~v064M~
        pc+=strlen(pc)+1;                                          //~v064M~
    }                                                              //~v064M~
    UERRBACKNOMSG();    //restore nomsg option                     //~v064M~
    return rc;                                                     //~v064M~
}//uexecchk                                                        //~v064M~
#ifdef UNX                                                         //~v327I~
//*********************************************************************//~v327I~
//*uextdirsrch:UNX x-bit chk                                       //~v327I~
//*p1 :filename                                                    //~v327I~
//*rc :1:executable,0:not found/not executable                     //~v327I~
//*********************************************************************//~v327I~
int uextdirsrch(char *Pfullpath)                                   //~v327I~
{                                                                  //~v327I~
//**********************                                           //~v327I~
    if (uattrxchk(Pfullpath,0))	//x bit chk                        //~v327R~
        return 1;	//x-bit on                                     //~v327R~
    return 0;                                                      //~v327R~
}//uextdirsrch                                                     //~v327I~
#else //!UNX                                                       //~v327I~
//*********************************************************************//~v064M~
//*uextdirsrch:filename with ext on dir                            //~v064M~
//*p1 :filename with no ext                                        //~v064M~
//*rc :0:none of (1:exe,2:com,3:cmd,4:bat)                         //~v064M~
//*********************************************************************//~v064M~
int uextdirsrch(char *Pfullpath)                                   //~v064M~
{                                                                  //~v064M~
    int rc,ii,entryno,rclowest;                                    //~v064R~
    PUDIRLIST pudirlist,pudirlist0;                                //~v064M~
//**********************                                           //~v064M~
    strcat(Pfullpath,".*");                                        //~v064M~
    entryno=udirlist(Pfullpath,FILE_ALL-FILE_DIRECTORY,&pudirlist0,0);  //no sort//~v064R~
    if (entryno==-1)    //list not created                         //~v064R~
        return 0;                                                  //~v064M~
                                                                   //~v064M~
    rclowest=256;   //high value                                   //~v064M~
    for (ii=0,pudirlist=pudirlist0;ii<entryno;ii++,pudirlist++)    //~v064R~
    {                                                              //~v064M~
//printf("dir=%s\n",pudirlist->name);                              //~v064R~
        if (rc=uextchk(pudirlist->name),rc && rc!=9)               //~v064M~
            if (rclowest>rc)                                       //~v064M~
                rclowest=rc;                                       //~v064M~
    }                                                              //~v064M~
//  ufree(pudirlist0);                                             //~v064M~//~v6qaR~
    UDIRLIST_FREE(pudirlist0);                                     //~v6qaI~
    if (rclowest==256)  //not found                                //~v064M~
        return 0;                                                  //~v064M~
    strcpy(Pfullpath+strlen(Pfullpath)-1,Sextlist[rclowest-1]);    //~v064M~
    return rclowest;                    //one of executable extention name//~v064M~
}//uextdirsrch                                                     //~v064M~
//*********************************************************************//~v064M~
//*uextchk:chk extention is .exe/.com/.cmd/.bat                    //~v064M~
//*p1 :filename                                                    //~v064M~
//*rc :0:none of (1:exe,2:com,3:cmd,4:bat) or 9(has no ext)        //~v064M~
//*********************************************************************//~v064M~
int uextchk(char *Pfile)                                           //~v064M~
{                                                                  //~v064M~
    char *pc;                                                      //~v064M~
    int ii,extloop;                                                //~v064M~
//**********************                                           //~v064M~
    if (!(pc=strrchr(Pfile,'.')))                                  //~v064M~
        return 9;       //no ext                                   //~v064M~
    pc++;                                                          //~v064M~
//  extloop=sizeof(Sextlist)/4;                                    //~v064M~//~v6L1R~
    extloop=sizeof(Sextlist)/PTRSZ;                                //~v6L1I~
    for (ii=0;ii<extloop;ii++)                                     //~v064M~
    {                                                              //~v064M~
        if (!stricmp(pc,Sextlist[ii]))                             //~v064M~
            return ii+1;                                           //~v064M~
    }                                                              //~v064M~
    return 0;   //unmatch                                          //~v064M~
}//uextchk                                                         //~v064M~
#endif//!UNX                                                       //~v327I~
//*********************************************************************//~v127I~
//*ucmdnmcomp:chk cmd string whether cmd name is same              //~v127I~
//*p1 :cmd string1                                                 //~v127I~
//*p2 :cmd string2                                                 //~v127I~
//*rc :0:not same 1:same cmd name                                  //~v127I~
//*********************************************************************//~v127I~
int ucmdnmcomp(char *Pstr1,char *Pstr2)                            //~v127I~
{                                                                  //~v127I~
    char *pc1,*pc2,*pc11,*pc22;                                    //~v127I~
    UINT len1,len2;                                                //~v127I~
//**********************                                           //~v127I~
//search first non space                                           //~v127I~
    pc1=Pstr1+strspn(Pstr1," ");                                   //~v127I~
    pc2=Pstr2+strspn(Pstr2," ");                                   //~v127I~
//search cmd name                                                  //~v127I~
    for (pc11=pc1;*pc1;pc1++)                                      //~v127I~
    {                                                              //~v127I~
        if (*pc1==' '||*pc1=='.')                                  //~v127I~
            break;                                                 //~v127I~
//      if (*pc1=='\\')                                            //~v377R~
        if (*pc1==DIR_SEPC)                                        //~v377R~
            pc11=pc1+1;                                            //~v127I~
    }                                                              //~v127I~
    for (pc22=pc2;*pc2;pc2++)                                      //~v127I~
    {                                                              //~v127I~
        if (*pc2==' '||*pc2=='.')                                  //~v127I~
            break;                                                 //~v127I~
//      if (*pc2=='\\')                                            //~v377R~
        if (*pc2==DIR_SEPC)                                        //~v377I~
            pc22=pc2+1;                                            //~v127I~
    }                                                              //~v127I~
//compare                                                          //~v127I~
//  len1=(ULONG)pc1-(ULONG)pc11;                                   //~v127I~//~v6hhR~
//  len1=(ULPTR)pc1-(ULPTR)pc11;                                   //~v6xkR~
    len1=(UINT)((ULPTR)pc1-(ULPTR)pc11);                           //~v6xiR~
//  len2=(ULONG)pc2-(ULONG)pc22;                                   //~v127I~//~v6hhR~
//  len2=(ULPTR)pc2-(ULPTR)pc22;                                   //~v6xkR~
    len2=(UINT)((ULPTR)pc2-(ULPTR)pc22);                           //~v6xiR~
#ifdef UNX                                                         //~v393I~
    return ((len1==len2) && (memcmp(pc11,pc22,len1)==0));          //~v393I~
#else  //!UNX                                                      //~v393I~
    return ((len1==len2) && (memicmp(pc11,pc22,len1)==0));         //~v127I~
#endif //!UNX                                                      //~v393I~
}//ucmcnmcomp                                                      //~v127I~
                                                                   //~v316I~
#ifdef UNX                                                         //~v327I~
//***************************************************************  //~v327I~
//*get exe pathname(end with \)                                    //~v327I~
//*rc:path len(0 when err)                                         //~v327I~
//***************************************************************  //~v327I~
int ugetexepath(UCHAR *Pfullpath)                                  //~v327I~
{                                                                  //~v327I~
    return 0;                                                      //~v327I~
}//ugetexepath                                                     //~v327I~
#else                                                              //~v327I~
#if defined(W32) || defined(OS2)                                   //~v327R~
//***************************************************************  //~v316I~
//*get exe pathname(end with \)                                    //~v316I~
//*rc:path len(0 when err)                                         //~v316I~
//***************************************************************  //~v316I~
int ugetexepath(UCHAR *Pfullpath)                                  //~v316I~
{                                                                  //~v316I~
#ifdef W32                                                         //~v316I~
//  UCHAR *cmdline,*pc;                                            //~v5i6R~
#else                                                              //~v316I~
    PTIB  ptib;                                                    //~v316I~
    PPIB  ppib;                                                    //~v316I~
    ULONG hmte;     //module handle                                //~v316I~
    APIRET apiret;                                                 //~v316I~
#endif                                                             //~v316I~
    int len;                                                       //~v316I~
//********************************                                 //~v316I~
#ifdef W32                                                         //~v316I~
//    cmdline=GetCommandLine();                                    //~v5i6R~
////printf("cmdline=%s\n",cmdline);                                //~v5i6R~
//    len=(UINT)strlen(cmdline);                                   //~v5i6R~
//    pc=memchr(cmdline,' ',len);                                  //~v5i6R~
//    if (pc)                                                      //~v5i6R~
//        len=(ULONG)pc-(ULONG)cmdline;                            //~v5i6R~
//    memcpy(Pfullpath,cmdline,(UINT)len);                         //~v5i6R~
//    *(Pfullpath+len)=0;                                          //~v5i6R~
      len=GetModuleFileName(NULL,Pfullpath,_MAX_PATH);             //~v5i6R~
	  *(Pfullpath+len)=0;                                          //~v5i6I~
#else                                                              //~v316I~
    DosGetInfoBlocks(&ptib,&ppib);                                 //~v316I~
    hmte=ppib->pib_hmte;                                           //~v316I~
    apiret=DosQueryModuleName(hmte,_MAX_PATH,Pfullpath);           //~v316I~
    if (apiret)                                                    //~v316I~
        return 0;                                                  //~v316I~
//printf("os2 modname=%s\n",Pfullpath);                            //~v316R~
#endif                                                             //~v316I~
    len=upathlen(Pfullpath);                                       //~v316I~
    if (len<=0)                                                    //~v316I~
        return 0;                                                  //~v316I~
    *(Pfullpath+len)=0;                                            //~v316I~
    return len;                                                    //~v316I~
}//ugetexepath                                                     //~v316I~
#endif //defined(W32) || defined(OS2)                              //~v316I~
#endif //!UNX                                                      //~v327I~
#ifdef UNX                                                         //~v428I~
////*********************************************************************//~v50vR~
////* get process info by ps cmd of specified process              //~v50vR~
////ret :rc;                                                       //~v50vR~
////*********************************************************************//~v50vR~
//int uproc_getpsinfo(int Ppid,PUPSINFO Ppupsinfo)                 //~v50vR~
//{                                                                //~v50vR~
//#define PSRECSZ     256                                          //~v50vR~
//static char Spsrec[PSRECSZ+1];                                   //~v50vR~
//    char tempfnm[32],*pc,*pidpos,*ttypos,*ppidpos;               //~v50vR~
//    char pscmd[128];                                             //~v50vR~
//    FILE *fh;                                                    //~v50vR~
////************************                                       //~v50vR~
//    utempnam("/tmp","xeps_",tempfnm);                            //~v50vR~
//    sprintf(pscmd,"ps -l %d >%s",Ppid,tempfnm);                  //~v50vR~
//    if (usystem(pscmd))                                          //~v50vR~
//        return 4;                                                //~v50vR~
//    ugeterrmsg();       //clear errmsg                           //~v50vR~
//    fh=fopen(tempfnm,"r");                                       //~v50vR~
//    if (!fh)                                                     //~v50vR~
//    {                                                            //~v50vR~
//        uerrmsg("%s open failed\n",0,                            //~v50vR~
//                tempfnm);                                        //~v50vR~
//        return 4;                                                //~v50vR~
//    }                                                            //~v50vR~
////read header rec                                                //~v50vR~
//    if (!fgets(Spsrec,PSRECSZ,fh))                               //~v50vR~
//        return 4;                                                //~v50vR~
//                                                                 //~v50vR~
//    if (!(pidpos=strstr(Spsrec,"PID")))                          //~v50vR~
//        return 4;                                                //~v50vR~
//    if (!(ppidpos=strstr(Spsrec,"PPID")))                        //~v50vR~
//        return 4;                                                //~v50vR~
//    if (!(ttypos=strstr(Spsrec,"TTY")))                          //~v50vR~
//        return 4;                                                //~v50vR~
////read pid rec                                                   //~v50vR~
//    if (!fgets(Spsrec,PSRECSZ,fh))                               //~v50vR~
//        return 4;                                                //~v50vR~
//    for (pc=pidpos;pc>=Spsrec;pc--)                              //~v50vR~
//        if (*pc==' ')                                            //~v50vR~
//            break;                                               //~v50vR~
//    if (Ppid!=atoi(pc)) //pid parm err                           //~v50vR~
//        return 4;                                                //~v50vR~
//    Ppupsinfo->UPSIpid=Ppid;                                     //~v50vR~
//    for (pc=ppidpos;pc>=Spsrec;pc--)                             //~v50vR~
//        if (*pc==' ')                                            //~v50vR~
//            break;                                               //~v50vR~
//    Ppupsinfo->UPSIppid=atoi(pc);                                //~v50vR~
//    for (pc=ttypos;pc>=Spsrec;pc--)                              //~v50vR~
//        if (*pc==' ')                                            //~v50vR~
//            break;                                               //~v50vR~
//    for (;;pc++)                                                 //~v50vR~
//        if (*pc!=' ')                                            //~v50vR~
//            break;                                               //~v50vR~
//    if (!memcmp(pc,"tty",3))                                     //~v50vR~
//        pc+=3;                                                   //~v50vR~
//    if (*pc=='p')       //pty                                    //~v50vR~
//    {                                                            //~v50vR~
//        Ppupsinfo->UPSIttyno=-1;                                 //~v50vR~
//        Ppupsinfo->UPSIptyno=atoi(pc+1);                         //~v50vR~
//    }                                                            //~v50vR~
//    else                                                         //~v50vR~
//    {                                                            //~v50vR~
//        Ppupsinfo->UPSIttyno=atoi(pc);                           //~v50vR~
//        Ppupsinfo->UPSIptyno=-1;                                 //~v50vR~
//    }                                                            //~v50vR~
//    fclose(fh);                                                  //~v50vR~
//    fh=fopen(tempfnm,"r");                                       //~v50vR~
//    if (!fh)                                                     //~v50vR~
//    {                                                            //~v50vR~
//        uerrmsg("%s open failed\n",0,                            //~v50vR~
//                tempfnm);                                        //~v50vR~
//        return 4;                                                //~v50vR~
//    }                                                            //~v50vR~
////re-get cmd for long as avail                                   //~v50vR~
//    sprintf(pscmd,"ps %d >%s",Ppid,tempfnm);                     //~v50vR~
//    if (usystem(pscmd))                                          //~v50vR~
//        return 4;                                                //~v50vR~
//    ugeterrmsg();       //clear errmsg                           //~v50vR~
////read header rec                                                //~v50vR~
//    if (!fgets(Spsrec,PSRECSZ,fh))                               //~v50vR~
//        return 4;                                                //~v50vR~
//    pc=strstr(Spsrec,"COMMAND");                                 //~v50vR~
//    if (!pc)                                                     //~v50vR~
//        return 0;                                                //~v50vR~
////read pid rec                                                   //~v50vR~
//    if (!fgets(Spsrec,PSRECSZ,fh))                               //~v50vR~
//        return 4;                                                //~v50vR~
//    if (*(Spsrec+strlen(Spsrec)-1)=='\n')                        //~v50vR~
//        *(Spsrec+strlen(Spsrec)-1)=0;                            //~v50vR~
//    Ppupsinfo->UPSIcmd=pc;                                       //~v50vR~
//    fclose(fh);                                                  //~v50vR~
//    unlink(tempfnm);        //del tempfile                       //~v50vR~
//    return 0;                                                    //~v50vR~
//}//uproc_getpsinfo                                               //~v50vR~
//*********************************************************************//~v50vI~
//* get process info by specified ps cmd                           //~v50vI~
//parm1:ps cmd(if 0,"ps -alw" is default))                         //~v50vI~
//parm2:output chaind UPSINFO ptr                                  //~v50vI~
//ret :rc;                                                         //~v50vI~
//*********************************************************************//~v50vI~
int uproc_getpsinfo(char *Pcmd,PUPSINFO *Ppupsinfo)                //~v50vI~
{                                                                  //~v50vI~
#define PSRECSZ     512                                            //~v50vI~
    char psrec[PSRECSZ+1];                                         //~v50vI~
//  char tempfnm[32],*pc,*pidpos,*ttypos,*ppidpos,*cmdpos;         //~v50vI~//~v6dbR~
    char tempfnm[_MAX_PATH],*pc,*pidpos,*ttypos,*ppidpos,*cmdpos;  //~v6dbI~
//  char pscmd[128];                                               //~v50vI~//~v6dbR~
    char pscmd[128+_MAX_PATH];                                     //~v6dbI~
    char *perrmsg;                                                 //~v55aI~
	PUPSINFO ppsi,ppsi0,ppsio;                                     //~v50vI~
    int len;                                                       //~v50vI~
    FILE *fh;                                                      //~v50vI~
//************************                                         //~v50vI~
    utempnam("/tmp","xeps_",tempfnm);                              //~v50vI~
    if (Pcmd)                                                      //~v50vI~
    	sprintf(pscmd,"%s >%s",Pcmd,tempfnm);                      //~v50vR~
    else                                                           //~v50vI~
#ifdef AIX                                                         //~v57FR~
    	sprintf(pscmd,"ps -ef >%s",tempfnm); 	//default          //~v57FR~
#else                                                              //~v57FR~
//  	sprintf(pscmd,"ps -alwx >%s",tempfnm); 	//default          //~v5h1R~
    	sprintf(pscmd,"ps alwx >%s",tempfnm); 	//default          //~v5h1I~
#endif                                                             //~v57BI~
    perrmsg=ugeterrmsg();       //clear errmsg                     //~v55aI~
//  if (usystem(pscmd))                                            //~v57PR~
    if (usystem2(UPROC_NOOKMSG,pscmd))                             //~v57PR~
        return 4;                                                  //~v50vI~
//  ugeterrmsg();       //clear errmsg                             //~v55aR~
    useterrmsg(perrmsg);                                           //~v55aI~
    fh=fopen(tempfnm,"r");                                         //~v50vI~
    if (!fh)                                                       //~v50vI~
    {                                                              //~v50vI~
        uerrmsg("%s open failed\n",0,                              //~v50vI~
                tempfnm);                                          //~v50vI~
        return 4;                                                  //~v50vI~
    }                                                              //~v50vI~
//read header rec                                                  //~v50vI~
    if (!fgets(psrec,PSRECSZ,fh))                                  //~v50vI~
        return 4;                                                  //~v50vI~
                                                                   //~v50vI~
    pidpos=strstr(psrec,"PID");                                    //~v50vI~
    ppidpos=strstr(psrec,"PPID");                                  //~v50vI~
    ttypos=strstr(psrec,"TTY");                                    //~v50vI~
    cmdpos=strstr(psrec,"COMMAND");     //slackware                //~v50vR~
    if (!cmdpos)                                                   //~v50vI~
    	cmdpos=strstr(psrec,"CMD"); 	//terbo linux              //~v50vI~
//read pid rec                                                     //~v50vI~
	ppsi0=0;	//top                                              //~v50vI~
    ppsio=0;    //previous                                         //~v50vI~
	while(fgets(psrec,PSRECSZ,fh))                                 //~v50vI~
    {                                                              //~v50vI~
		ppsi=(PUPSINFO)ucalloc(1,sizeof(UPSINFO));                 //~v50vI~
        if (ppsio)                                                 //~v50vI~
        	ppsio->UPSInext=ppsi;     //chain                      //~v50vR~
        else                                                       //~v50vI~
        	ppsi0=ppsi;			//top                              //~v50vI~
        ppsio=ppsi;                                                //~v50vI~
    	if (pidpos)                                                //~v50vI~
        {                                                          //~v50vI~
	    	for (pc=pidpos;pc>=psrec;pc--)                         //~v50vI~
    	    	if (*pc==' ')                                      //~v50vI~
        	    	break;                                         //~v50vI~
		    ppsi->UPSIpid=atoi(pc); //pid                          //~v50vI~
        }                                                          //~v50vI~
    	if (ppidpos)                                               //~v50vI~
        {                                                          //~v50vI~
            for (pc=ppidpos;pc>=psrec;pc--)                        //~v50vI~
                if (*pc==' ')                                      //~v50vI~
                    break;                                         //~v50vI~
            ppsi->UPSIppid=atoi(pc);                               //~v50vI~
        }                                                          //~v50vI~
    	if (ttypos)                                                //~v50vI~
        {                                                          //~v50vI~
            for (pc=ttypos;pc>=psrec;pc--)                         //~v50vI~
                if (*pc==' ')                                      //~v50vI~
                    break;                                         //~v50vI~
            for (;;pc++)                                           //~v50vI~
                if (*pc!=' ')                                      //~v50vI~
                    break;                                         //~v50vI~
          if (!memcmp(pc,"pts/",3))                                //~v57AI~
          {                                                        //~v57AI~
                ppsi->UPSIttyno=-1;                                //~v57AI~
                ppsi->UPSIptyno=atoi(pc+4);                        //~v57AI~
                ppsi->UPSIflag=UPSIFPTS;                           //~v57AI~
          }                                                        //~v57AI~
          else                                                     //~v57AI~
          {                                                        //~v57AI~
            if (!memcmp(pc,"tty",3))                               //~v50vI~
                pc+=3;                                             //~v50vI~
            if (*pc=='p')       //pty                              //~v50vI~
            {                                                      //~v50vI~
                ppsi->UPSIttyno=-1;                                //~v50vI~
                ppsi->UPSIptyno=atoi(pc+1);                        //~v50vI~
                ppsi->UPSIflag=UPSIFPTY;                           //~v57BI~
            }                                                      //~v50vI~
            else                                                   //~v50vI~
            {                                                      //~v50vI~
                ppsi->UPSIttyno=atoi(pc);                          //~v50vI~
                ppsi->UPSIptyno=-1;                                //~v50vI~
            }                                                      //~v50vI~
          }//not pts                                               //~v57AI~
        }//ttypos                                                  //~v50vI~
    	if (cmdpos)                                                //~v50vI~
        {                                                          //~v50vI~
		    len=(int)strlen(cmdpos);                               //~v50vI~
          if (len)                                                 //~v599I~
          {                                                        //~v599I~
		    if (*(cmdpos+len-1)=='\n')                             //~v50vI~
        		len--,*(cmdpos+len)=0;                             //~v50vI~
          }                                                        //~v599I~
//  		ppsi->UPSIcmd=umalloc(len+1);                          //~v6xiR~
    		ppsi->UPSIcmd=umalloc((UINT)(len+1));                  //~v6xiI~
            strcpy(ppsi->UPSIcmd,cmdpos);                          //~v50vI~
        }//cmdpos                                                  //~v50vI~
//printf("psinfo pid=%d,ppid=%d,pts=%d,cmd=%s\n",                  //~v57FR~
//  ppsi->UPSIpid,ppsi->UPSIppid,ppsi->UPSIptyno,ppsi->UPSIcmd);   //~v57FR~
    }                                                              //~v50vI~
    fclose(fh);                                                    //~v50vI~
    unlink(tempfnm);        //del tempfile                         //~v50vI~
	*Ppupsinfo=ppsi0;                                              //~v50vI~
    return 0;                                                      //~v50vI~
}//uproc_getpsinfo                                                 //~v50vI~
//*********************************************************************//~v50vI~
//* search pid on psinfo cahin                                     //~v50vI~
//ret :rc;                                                         //~v50vI~
//*********************************************************************//~v50vI~
PUPSINFO uproc_srchpsinfo(int Popt,PUPSINFO Ppupsinfo,int Ppid)    //~v57BR~
{                                                                  //~v50vI~
	PUPSINFO ppsi;                                                 //~v50vI~
	PUPSINFO ppsil;                                                //~v57BI~
    int conid;                                                     //~v57BI~
//********************                                             //~v50vI~
  if (Popt & UPSPSI_PPID)                                          //~v57BI~
  {                                                                //~v57BI~
	for (ppsi=Ppupsinfo;ppsi;ppsi=ppsi->UPSInext)                  //~v50vI~
        if (ppsi->UPSIpid==Ppid)                                   //~v50vI~
			break;                                                 //~v50vI~
  }                                                                //~v57BI~
  else                                                             //~v57BI~
  if (Popt & UPSPSI_CONID)                                         //~v57BI~
  {                                                                //~v57BI~
  	conid=Ppid;                                                    //~v57BI~
	for (ppsi=Ppupsinfo,ppsil=0;ppsi;ppsi=ppsi->UPSInext)          //~v57BR~
    {                                                              //~v57BI~
        if (ppsi->UPSIflag & UPSIFPATH)	//found once               //~v57BI~
        	continue;                                              //~v57BI~
        if (Popt & UPSPSI_CONPTS)       //pts/n                    //~v57BI~
        {                                                          //~v57BI~
        	if (ppsi->UPSIflag & UPSIFPTS                          //~v57BI~
        	&&  ppsi->UPSIptyno==conid)                            //~v57BI~
				ppsil=ppsi; //last found                           //~v57BR~
        }                                                          //~v57BI~
        else                                                       //~v57BI~
        if (Popt & UPSPSI_CONPTY) 		//ttypn                    //~v57BI~
        {                                                          //~v57BI~
        	if (ppsi->UPSIptyno==conid)                            //~v57BI~
				ppsil=ppsi; //last found                           //~v57BI~
        }                                                          //~v57BI~
        if (Popt & UPSPSI_CONTTY) 		//ttyn                     //~v57BI~
        {                                                          //~v57BI~
        	if (ppsi->UPSIttyno==conid)                            //~v57BI~
				ppsil=ppsi; //last found                           //~v57BI~
        }                                                          //~v57BI~
  	}//                                                            //~v57BI~
    ppsi=ppsil;                                                    //~v57BI~
  }                                                                //~v57BI~
  else                                                             //~v57BI~
  	ppsi=0;                                                        //~v57BR~
    return ppsi;                                                   //~v50vI~
}//uproc_srchpsinfo                                                //~v50vI~
//*********************************************************************//~v50vI~
//* free psinfo                                                    //~v50vI~
//ret :rc;                                                         //~v50vI~
//*********************************************************************//~v50vI~
void uproc_freepsinfo(PUPSINFO Ppupsinfo)                          //~v50vI~
{                                                                  //~v50vI~
	PUPSINFO ppsi,ppsinext;                                        //~v50vI~
//********************                                             //~v50vI~
	for (ppsi=Ppupsinfo;ppsi;ppsi=ppsinext)                        //~v50vI~
    {                                                              //~v50vI~
		ppsinext=ppsi->UPSInext;                                   //~v50vI~
        if (ppsi->UPSIcmd)                                         //~v50vI~
			ufree(ppsi->UPSIcmd);                                  //~v50vI~
        ufree(ppsi);                                               //~v50vI~
	}                                                              //~v50vI~
    return;                                                        //~v50vI~
}//uproc_freepsinfo                                                //~v50vI~
#endif //UNX                                                       //~v59dI~
//*********************************************************************//~v50GI~
//* get cmd redirected result,record rength max=512;               //~v50GI~
//parm1:cmd str                                                    //~v50GI~
//parm2:output stdout record buff(ptr and record) optional         //~v50GR~
//parm3:output stderr record buff(ptr and record) optional         //~v50GR~
//parm4:output stdout record ctr                  optional         //~v50GI~
//parm5:output stderr record ctr                  optional         //~v50GI~
//ret :rc;4:err,1:std err                                          //~v50GR~
//*********************************************************************//~v50GI~
int usystem_redirect(int Popt,char *Pcmd,char ***Pstdo,char ***Pstde,int *Pstdoctr,int *Pstdectr)//~v50HR~
{                                                                  //~v50GI~
//#define MAXRECSZ     512                                         //~v5anR~
//#define MAXRECSZ     MAX_STDOREC                                 //~v5anR~
//    char rec[MAXRECSZ+1];                                        //~v5anR~
//    char tempfnm[2][32];//,*fnm,*pc,**ppc;                         //~v5anR~//~v6dbR~
    char tempfnm[2][_MAX_PATH];//,*fnm,*pc,**ppc;                  //~v6dbI~
    char syscmd[MAX_STDOREC];                                      //~v5anR~
    char *perrmsg;                                                 //~v55aR~
#ifdef UNX                                                         //~v59tI~
    char *envstr;                                                  //~v59tI~
#endif                                                             //~v59tI~
//  int stdesw;                                                    //~v5anR~
//  int  rctr[2],rsz[2],ii,jj,len;                                 //~v5anR~
//  char **stg[2]={0,0},*buffp[2];                                 //~v5anR~
//  FILE *fh;                                                      //~v5anR~
//  int rc=0;                                                      //~v5anR~
    int rc,rc2,ctr1,ctr2;                                          //~v6dcI~
//************************                                         //~v50GI~
#ifdef UNX                                                         //~v59dI~
    utempnam("/tmp","xetmpstdo_",tempfnm[0]);                      //~v50GI~
  if (Popt & UPROC_STDE2O)  //redirect stderr to stdout            //~v61pI~
    tempfnm[1][0]=0;                                               //~v61pI~
  else                                                             //~v61pI~
    utempnam("/tmp","xetmpstde_",tempfnm[1]);                      //~v50GI~
  	if (Popt & UPROC_LANGC)                                        //~v59tR~
    	envstr="export LANG=C;";                                   //~v59tR~
    else                                                           //~v59tI~
    	envstr="";                                                 //~v59tR~
//  sprintf(syscmd,"%s >%s 2>%s",Pcmd,tempfnm[0],tempfnm[1]);      //~v59tR~
  if (Popt & UPROC_STDE2O)  //redirect stderr to stdout            //~v61pI~
    sprintf(syscmd,"%s%s >%s 2>&1",envstr,Pcmd,tempfnm[0]);        //~v61pI~
  else                                                             //~v61pI~
    sprintf(syscmd,"%s%s >%s 2>%s",envstr,Pcmd,tempfnm[0],tempfnm[1]);//~v59tI~
//  stdesw=1;                                                      //~v5anR~
#else                                                              //~v59dI~
//  utempnam("","xetmpstdo_",tempfnm[0]);                          //~v5csR~
    utempnam("","xetmpf",tempfnm[0]);                              //~v5csI~
    *tempfnm[1]=0;                                                 //~v5csI~
  if (Popt & UPROC_STDE2O)  //redirect stderr to stdout            //~v61pI~
    sprintf(syscmd,"%s >%s 2>&1",Pcmd,tempfnm[0]);                 //~v61pI~
  else                                                             //~v61pI~
    sprintf(syscmd,"%s >%s",Pcmd,tempfnm[0]);                      //~v59dI~
//  stdesw=0;                                                      //~v5anR~
//  rctr[1]=0;                                                     //~v5anR~
//  rsz[1]=0;                                                      //~v5anR~
#endif                                                             //~v59dI~
	perrmsg=ugeterrmsg();       //save errmsg                      //~v55aI~
    rc=                                                            //~v6dcI~
    usystem2(Popt,syscmd);                                         //~v50HR~
                                                                   //~v50GI~
//  ugeterrmsg();       //clear errmsg                             //~v55aR~
    useterrmsg(perrmsg);                                           //~v55aI~
//  return uproc_redirectoutchk(Popt,Pcmd,Pstdo,Pstde,Pstdoctr,Pstdectr,tempfnm[0],tempfnm[1]);//~v5anR~//~v6dcR~
    rc2=uproc_redirectoutchk(Popt,Pcmd,Pstdo,Pstde,&ctr1,&ctr2,tempfnm[0],tempfnm[1]);//~v6dcI~
    if (Pstdoctr)                                                  //~v6dcI~
    	*Pstdoctr=ctr1;                                            //~v6dcI~
    if (Pstdectr)                                                  //~v6dcI~
    	*Pstdectr=ctr2;                                            //~v6dcI~
    if (rc2<=1 && rc && !ctr1 && !ctr2)  //no stdo/stde msg but cmd faileddcI~//~v6dcR~
    	rc2=rc;                                                    //~v6dcI~
    return rc2;                                                    //~v6dcI~
}//usystem_redirect                                                //~v5anI~
//*********************************************************************//~v5anI~
//* spawn width redirect                                           //~v5anI~
//ret :rc;4:err,1:std err                                          //~v5anI~
//*********************************************************************//~v5anI~
int uspawn_redirect(int Popt,char *Pcmd,char *Pstdinfnm,char ***Pstdo,char ***Pstde,int *Pstdoctr,int *Pstdectr)//~v5anR~
{                                                                  //~v5anI~
//  char tempfnm[2][32];                                           //~v5anR~//~v6dbR~
    char tempfnm[2][_MAX_PATH];                                    //~v6dbI~
    FILE *fh,*fh0=NULL;                                            //~v5anR~//~v6h7R~
#ifdef UNX
    FILE *fh2;
#endif
    char   *parm,*perrmsg;                                         //~v5anR~
    int rc;                                                        //~v5anR~
    int opdno=0;    //init for comiler warning                     //~v5anI~
    char   **argv=0;                 //spawnvp parm                //~v5anI~
#ifdef UNX                                                         //~v5anI~
    char *pcenv=NULL;                                                   //~v5anR~//~v6h9R~
static char Slangenv[32]="LANG=";                                  //~v5anR~
#endif                                                             //~v5anI~
//************************                                         //~v5anI~
#ifdef UNX                                                         //~v5anI~
  	if (Popt & UPROC_LANGC)                                        //~v5anI~
    {                                                              //~v5anI~
    	pcenv=getenv("LANG");                                      //~v5anR~
        if (pcenv)                                                 //~v5anI~
        {                                                          //~v5anI~
    		strncpy(Slangenv+5,pcenv,sizeof(Slangenv)-5);          //~v5anR~
    		putenv("LANG=C");                                      //~v5anR~
        }                                                          //~v5anI~
    }                                                              //~v5anI~
    utempnam("/tmp","xetmpstdo_",tempfnm[0]);                      //~v5anI~
    utempnam("/tmp","xetmpstde_",tempfnm[1]);                      //~v5anI~
	if (!(fh=uredirect(1,tempfnm[0],0))) //append stdin/stderr to so file//~v5anR~
    	return 8;                                                  //~v5anI~
	if (!(fh2=uredirect(2,tempfnm[1],0))) //append stdin/stderr to so file//~v5anR~
    	return 8;                                                  //~v5anI~
#else                                                              //~v5anI~
//  utempnam("","xetmpstdo_",tempfnm[0]);                          //~v5csR~
    utempnam("","xetmpf",tempfnm[0]);                              //~v5csI~
	if (!(fh=uredirect(1,tempfnm[0],0))) //append stdin/stderr to so file//~v5anR~
    	return 8;                                                  //~v5anI~
    *tempfnm[1]=0;                                                 //~v5csI~
//  fh2=0;                                                         //~v5anI~
#endif                                                             //~v5anI~
	if (Pstdinfnm)                                                 //~v5anI~
		if (!(fh0=uredirect(0,Pstdinfnm,0))) //append stdin/stderr to so file//~v5anI~
	    	return 8;                                              //~v5anI~
    parm=0;             //malloc req                               //~v5anI~
    rc=uparsecmd(UPCMD_DROPQ,Pcmd,&opdno,&parm,&argv,0);//no delmt //~v5anI~
    if (rc)                                                        //~v5anI~
    	return rc;//MALLOC_FAILED                                  //~v5anI~
//  fclose(fh);                                                    //~v5anR~
//  if (fh2)                                                       //~v5anR~
//      fclose(fh2);                                               //~v5anR~
	perrmsg=ugeterrmsg();       //save errmsg                      //~v5anI~
//  rc=uspawnvp(P_WAIT,argv[0],argv);                              //~v6xkR~
    rc=(int)uspawnvp(P_WAIT,argv[0],argv);	//WAIT dose not return process handle//~v6xkI~
    ufree(parm);	//uparse malloced                              //~v5anI~
    useterrmsg(perrmsg);                                           //~v5anI~
    if (rc==UALLOC_FAILED)                                         //~v5anI~
        return rc;                                                 //~v5anI~
#ifdef UNX                                                         //~v5anI~
  	if (Popt & UPROC_LANGC)                                        //~v5anI~
    {                                                              //~v5anI~
        if (pcenv)                                                 //~v5anI~
  		  	putenv(Slangenv);   //restore lang                     //~v5anR~
    }                                                              //~v5anI~
//  fclose(fh);                                                    //~v5anR~
    if (uredirectrestore(1))                                       //~v5anI~
    	return 8;                                                  //~v5anI~
    fclose(fh);                                                    //~v5anI~
//  fclose(fh2);                                                   //~v5anR~
    if (uredirectrestore(2))                                       //~v5anI~
    	return 8;                                                  //~v5anI~
    fclose(fh2);                                                   //~v5anI~
#else                                                              //~v5anI~
//  fclose(fh);                                                    //~v5anR~
    if (uredirectrestore(1))                                       //~v5anI~
    	return 8;                                                  //~v5anI~
    fclose(fh);                                                    //~v5anI~
#endif                                                             //~v5anI~
	if (Pstdinfnm)                                                 //~v5anI~
    {                                                              //~v5anI~
//      fclose(fh0);                                               //~v5anR~
    	if (uredirectrestore(0))                                   //~v5anI~
    		return 8;                                              //~v5anI~
        fclose(fh0);                                               //~v5anI~
    }                                                              //~v5anI~
	return uproc_redirectoutchk(Popt,Pcmd,Pstdo,Pstde,Pstdoctr,Pstdectr,tempfnm[0],tempfnm[1]);//~v5anI~
}//uspawn_redirect                                                 //~v5anI~
//*************************************************                //~v5anI~
//	redirect output parse                                          //~v5anI~
//*************************************************                //~v5anI~
int uproc_redirectoutchk(int Popt,char *Pcmd,char ***Pstdo,char ***Pstde,int *Pstdoctr,int *Pstdectr,//~v5anR~
						char *Pstdofnm,char *Pstdefnm)             //~v5anR~
{                                                                  //~v5anI~
    char rec[MAX_STDOREC+1];                                       //~v5anR~
    char *tempfnm[2],*fnm,*pc,**ppc;                               //~v5anI~
    int stdesw;                                                    //~v5anI~
    int  rctr[2],rsz[2],ii,jj,len;                                 //~v5anI~
    char **stg[2]={0,0},*buffp[2];                                 //~v5anI~
    FILE *fh;                                                      //~v5anI~
    int rc=0;                                                      //~v5anI~
//**************************                                       //~v5anI~
//#ifdef UNX                                                       //~v5csR~
  if (Pstdefnm && *Pstdefnm)                                       //~v5csR~
    stdesw=1;                                                      //~v5anI~
//#else                                                            //~v5csR~
  else                                                             //~v5csI~
  {                                                                //~v5csI~
    stdesw=0;                                                      //~v5anI~
    rctr[1]=0;                                                     //~v5anI~
    rsz[1]=0;                                                      //~v5anI~
  }                                                                //~v5csI~
//#endif                                                           //~v5csR~
	tempfnm[0]=Pstdofnm;                                           //~v5anR~
	tempfnm[1]=Pstdefnm;                                           //~v5anR~
//evaluate rec ctr and file size                                   //~v50GI~
    for (ii=0;ii<2;ii++)	//stdout and stderr                    //~v50GI~
    {                                                              //~v50GI~
	    fnm=tempfnm[ii];                                           //~v50GI~
    	fh=fopen(fnm,"r");                                         //~v50GI~
    	if (!fh)                                                   //~v50GI~
    	{                                                          //~v50GI~
        	uerrmsg("%s open-1 failed\n",0,                        //~v50GI~
            	    fnm);                                          //~v50GI~
        	return 4;                                              //~v50GI~
    	}                                                          //~v50GI~
        rctr[ii]=0;                                                //~v50GI~
        rsz[ii]=0;                                                 //~v50GI~
		while(fgets(rec,MAX_STDOREC,fh))                           //~v5anR~
        {                                                          //~v50GI~
        	rctr[ii]++;                                            //~v50HR~
//          rsz[ii]+=strlen(rec)+1;		//with last null           //~v5adR~
            len=(int)strlen(rec);		//with last null               //~v5adI~
            UTRACEP("%s:stdo/stde reclen=%d\n",UTT,len);           //~v77DR~
//          UTRACED("stdo/stde rec",rec,(int)sizeof(rec));         //~v77DR~
            UTRACED("stdo/stde rec",rec,len);                      //~v77DI~
          	if (Popt & UPROC_CVS2E)   //len may inclease by hankaku katakana//~v5adI~
		    	ushift2euccount(rec,len,&len,0); 	//get euc length//~v5adR~
            rsz[ii]+=len+1;        		//with last null           //~v5adI~
        }                                                          //~v50GI~
        fclose(fh);                                                //~v50GI~
    	if (!stdesw) 	//no std err chk                           //~v59dI~
        	break;                                                 //~v59dI~
    }//                                                            //~v50GI~
//alloc buff                                                       //~v50GI~
    for (ii=0;ii<2;ii++)	//stdout and stderr                    //~v50GI~
    {                                                              //~v50GI~
//      len=(rctr[ii]+1)*4+rsz[ii];	//ptrlist(last null) and record area//~v50GI~//~v690R~
  	    len=(rctr[ii]+1)*PTRSZ+rsz[ii];	//ptrlist(last null) and record area//~v690I~
        stg[ii]=umalloc((UINT)len);                                //~v50HR~
        UTRACEP("uproc_redirectoutchk ii=%d,ctr=%d,len=%d,ptr=%p\n",ii,rctr[ii]+1,len,stg[ii]);//~v6qaR~
        if (!stg[ii])                                              //~v50GI~
        	break;                                                 //~v50GI~
        stg[ii][0]=0;                                              //~v5csI~
//      buffp[ii]=(char*)(ULONG)stg[ii]+(rctr[ii]+1)*4;            //~v5anR~//~v690R~
//      buffp[ii]=(char*)(ULONG)stg[ii]+(rctr[ii]+1)*PTRSZ;        //~v690I~//~v6hhR~
        buffp[ii]=(char*)(ULPTR)stg[ii]+(rctr[ii]+1)*PTRSZ;        //~v6hhI~
    }                                                              //~v50GI~
    if (ii<2)                                                      //~v50GI~
    {                                                              //~v50GI~
    	if (stg[0])                                                //~v50GI~
	    	ufree(stg[0]);                                         //~v50GI~
        return UALLOC_FAILED;                                      //~v50GR~
    }                                                              //~v50GI~
//read record to buffer                                            //~v50GI~
    for (ii=0;ii<2;ii++)	//stdout and stderr                    //~v50GI~
    {                                                              //~v50GI~
	    fnm=tempfnm[ii];                                           //~v50GI~
    	fh=fopen(fnm,"r");                                         //~v50GI~
    	if (!fh)                                                   //~v50GI~
    	{                                                          //~v50GI~
        	uerrmsg("%s open-2 failed\n",0,                        //~v50GI~
            	    fnm);                                          //~v50GI~
        	break;                                                 //~v50GI~
    	}                                                          //~v50GI~
        ppc=stg[ii];     //record ptr                              //~v50HR~
        pc=buffp[ii]; 					//record buff              //~v50GI~
		for (jj=0;jj<rctr[ii];jj++,ppc++)                          //~v50GI~
        {                                                          //~v50GI~
			if (!fgets(rec,MAX_STDOREC,fh))                        //~v5anR~
            	break;                                             //~v50GI~
            *ppc=pc;                                               //~v50GI~
            len=(int)strlen(rec);		//with last null               //~v50GR~
            if (len && *(rec+len-1)=='\n')                         //~v50GI~
            	len--;                                             //~v50GI~
            if (len && *(rec+len-1)=='\r')  //ftp return 0d0d0a    //~v59dI~
            	len--;                                             //~v59dI~
          	if (Popt & UPROC_CVS2E)   //sjis->euc                  //~v5adI~
    			ushift2euc(rec,0,len,pc,0,&len,0);                 //~v5adI~
            else                                                   //~v5adI~
          	if (Popt & UPROC_CVE2S)   //euc->sjis                  //~v5adI~
    			ueuc2shift(rec,0,len,pc,0,&len,0);//len may reduced by han-kana//~v5adI~
            else                                                   //~v5adI~
            memcpy(pc,rec,(UINT)len);                              //~v50GR~
            *(pc+len++)=0;                                         //~v50GI~
        	UTRACEP("uproc_redirectoutchk ii=%d,jj=%d,len=%d,ptr=%p\n",ii,jj,len,pc);//~v6qaI~
        	UTRACED("uproc_redirectoutchk",pc,len);                //~v6qaI~
            pc+=len;                                               //~v50GI~
        }                                                          //~v50GI~
        fclose(fh);                                                //~v50GI~
        *ppc=0;         //last null ptr;                           //~v50GI~
    	if (!stdesw) 	//no std err chk                           //~v59dI~
        	break;                                                 //~v59dI~
    }//                                                            //~v50GI~
  if (!(Popt & UPROC_KEEPTEMP))                                    //~v59gR~
  {                                                                //~v59gI~
#ifdef UNX                                                         //~v59dI~
    unlink(tempfnm[0]);        //del tempfile                      //~v50HI~
    unlink(tempfnm[1]);        //del tempfile                      //~v50HI~
#else                                                              //~v59dI~
//  uremove(tempfnm[0]);        //del tempfile                     //~v5anR~
    uremovenomsg(tempfnm[0]);        //del tempfile                //~v5anI~
#endif                                                             //~v59dI~
  }//not keep temp                                                 //~v59gI~
                                                                   //~v50HI~
  if (stdesw) 	//no std err chk                                   //~v59dI~
  {                                                                //~v59dI~
    if (ii<2)		//err                                          //~v50GI~
    {                                                              //~v50GI~
	    ufree(stg[0]);                                             //~v50GI~
	    ufree(stg[1]);                                             //~v50GI~
        return 4;                                                  //~v50GI~
    }                                                              //~v50GI~
    if (stg[1][0])                                                 //~v50HM~
    {                                                              //~v50HM~
//  	uerrmsg(stg[1][0],0);                                      //~v55oR~
        rc=1;                                                      //~v50HR~
    }                                                              //~v50HM~
  }                                                                //~v59dI~
    if (Pstdo)                                                     //~v50GI~
		*Pstdo=stg[0];                                             //~v50HR~
    else                                                           //~v50HI~
        ufree(stg[0]);                                             //~v50HI~
    if (Pstde)                                                     //~v50GI~
		*Pstde=stg[1];                                             //~v50HR~
    else                                                           //~v50HI~
        ufree(stg[1]);                                             //~v50HI~
    if (Pstdoctr)                                                  //~v50GI~
		*Pstdoctr=rctr[0];                                         //~v50GI~
    if (Pstdectr)                                                  //~v50GI~
		*Pstdectr=rctr[1];                                         //~v50GI~
    return rc;                                                     //~v50HR~
}//uproc_redirectoutchk                                            //~v61pR~
//#endif //UNX                                                     //~v59dR~
#if defined(UNX) || defined(W32)                                   //~v59jI~
//*********************************************************************//~v59jM~
//* spawn with piped stdin/stdo                                    //~v59jM~
//ret :pid or 0 if err(set errno)                                  //~v59jM~
//*********************************************************************//~v59jM~
//int uspawnvp_pipe(int Popt,int *Ppids,char *Ppathname,char **Pargv)//~v6xkR~
int uspawnvp_pipe(int Popt,LONGHANDLE *Ppids,char *Ppathname,char **Pargv)//~v6xkI~
{                                                                  //~v59jM~
//  int pid;                                                       //~v6xkR~
    LONGHANDLE pid;                                                //~v6xkI~
    int fdstdosv=-1,fdstdisv=-1,errnosv;                           //~v59jM~
    int fdstdesv=-1;                                               //~v5j6I~
    int fdpipe_p2c[2]={-1,-1},fdpipe_c2p[2]={-1,-1};               //~v59jM~
//****************************                                     //~v59jM~
    fflush(stdout);                                                //~v59jM~
    fflush(stderr);                                                //~v5j6I~
    fflush(stdin);                                                 //~v5ivI~
    if (Popt & USP_STDIN)                                          //~v59jR~
    {                                                              //~v59jM~
#ifdef UNX                                                         //~v59jM~
    	if(pipe(fdpipe_p2c)==-1)	//create pipe                  //~v59jM~
#else                                                              //~v59jM~
    	if(_pipe(fdpipe_p2c,4096,O_NOINHERIT)==-1)	//create pipe  //~v59jM~
#endif                                                             //~v59jM~
        	return   0;                                            //~v59jM~
    }//p2c pipe                                                    //~v59jM~
    if (Popt & USP_STDOUT)                                         //~v59jR~
    {                                                              //~v59jM~
#ifdef UNX                                                         //~v59jM~
    	if(pipe(fdpipe_c2p)==-1)	//create pipe                  //~v59jM~
#else                                                              //~v59jM~
    	if(_pipe(fdpipe_c2p,4096,O_NOINHERIT)==-1)	//create pipe  //~v59jM~
#endif                                                             //~v59jM~
    	{                                                          //~v59jM~
			uspawnvp_pipeclose(fdpipe_p2c,fdpipe_c2p);    //close p2c//~v59jM~
        	return   0;                                            //~v59jM~
    	}                                                          //~v59jM~
    }//c2p file                                                    //~v59jM~
    if (Popt & USP_STDOUT)	//c2p pipe                             //~v59jR~
    {                                                              //~v59jM~
//setup child stdout                                               //~v59jM~
#ifdef UNX                                                         //~v59jM~
    	fdstdosv=dup(fileno(stdout)); //save stdout                //~v59jM~
#else                                                              //~v59jM~
    	fdstdosv=_dup(_fileno(stdout)); //save stdout              //~v59jM~
#endif                                                             //~v59jM~
#ifdef UNX                                                         //~v59jM~
    	if(dup2(fdpipe_c2p[1],fileno(stdout))==-1)//child stdout is c2p-W//~v59jR~
#else                                                              //~v59jM~
    	if(_dup2(fdpipe_c2p[1],_fileno(stdout))!=0)//child stdout is c2p-W//~v59jM~
#endif                                                             //~v59jM~
        	uerrexit("dup2 pipe-c2p(W) -> stdout failed,errno=%d",0,//~v59jM~
						errno);                                    //~v59jM~
    	if (Popt & USP_STDERR)	//support stderr as "2>&1"         //~v5j6I~
        {                                                          //~v5j6I~
#ifdef UNX                                                         //~v5j6I~
	    	fdstdesv=dup(fileno(stderr)); //save stdout            //~v5j6I~
#else                                                              //~v5j6I~
    		fdstdesv=_dup(_fileno(stderr)); //save stdout          //~v5j6I~
#endif                                                             //~v5j6I~
#ifdef UNX                                                         //~v5j6I~
    		if(dup2(fdpipe_c2p[1],fileno(stderr))==-1)//child stdout is c2p-W//~v5j6I~
#else                                                              //~v5j6I~
    		if(_dup2(fdpipe_c2p[1],_fileno(stderr))!=0)//child stdout is c2p-W//~v5j6I~
#endif                                                             //~v5j6I~
        		uerrexit("dup2 pipe-c2p(W) -> stderr failed,errno=%d",0,//~v5j6I~
							errno);                                //~v5j6I~
        }                                                          //~v5j6I~
    	close(fdpipe_c2p[1]);//no need for parent c2p(W)           //~v59jM~
    	fdpipe_c2p[1]=-1;	//closed                               //~v59jM~
    }//c2p pipe                                                    //~v59jM~
    if (Popt & USP_STDIN)	//p2c pipe                             //~v59jR~
    {                                                              //~v59jM~
//setup child stdin                                                //~v59jM~
#ifdef UNX                                                         //~v59jM~
    	fdstdisv=dup(fileno(stdin)); //save stdin                  //~v59jM~
#else                                                              //~v59jM~
    	fdstdisv=_dup(_fileno(stdin)); //save stdin                //~v59jM~
#endif                                                             //~v59jM~
#ifdef UNX                                                         //~v59jM~
    	if(dup2(fdpipe_p2c[0],fileno(stdin))==-1)//child stdin is p2c-R//~v59jR~
#else                                                              //~v59jM~
    	if(_dup2(fdpipe_p2c[0],_fileno(stdin))!=0)//child stdin is p2c-R//~v59jM~
#endif                                                             //~v59jM~
        	uerrexit("dup2 pipe-p2c(R) -> stdin  failed,errno=%d",0,//~v59jM~
						errno);                                    //~v59jM~
    	close(fdpipe_p2c[0]);//no need for parent p2c(R)           //~v59jM~
    	fdpipe_p2c[0]=-1;	//closed                               //~v59jM~
    }//p2c pipe                                                    //~v59jM~
//kick child                                                       //~v59jM~
    pid=uspawnvp(P_NOWAIT|UPROC_NOOKMSG|UPROC_NOMSG,Ppathname,Pargv);//~v59jR~
    errnosv=errno;                                                 //~v59jM~
//restore parent stdo,stdi                                         //~v59jM~
	if (fdstdosv>=0)                                               //~v59jM~
    {                                                              //~v59jM~
#ifdef UNX                                                         //~v59jM~
    	if(dup2(fdstdosv,fileno(stdout))==-1) // restore own stdout//~v59jR~
#else                                                              //~v59jM~
    	if(_dup2(fdstdosv,_fileno(stdout))!= 0) // restore own stdout//~v59jM~
#endif                                                             //~v59jM~
        	uerrexit("dup2 stdout restore failed,errno=%d",0,      //~v59jM~
						errno);                                    //~v59jM~
    	close(fdstdosv);      //no more required                   //~v59jM~
    }                                                              //~v59jM~
	if (fdstdesv>=0)                                               //~v5j6I~
    {                                                              //~v5j6I~
#ifdef UNX                                                         //~v5j6I~
    	if(dup2(fdstdesv,fileno(stderr))==-1) // restore own stdout//~v5j6I~
#else                                                              //~v5j6I~
    	if(_dup2(fdstdesv,_fileno(stderr))!= 0) // restore own stdout//~v5j6I~
#endif                                                             //~v5j6I~
        	uerrexit("dup2 stderr restore failed,errno=%d",0,      //~v5j6I~
						errno);                                    //~v5j6I~
    	close(fdstdesv);      //no more required                   //~v5j6I~
    }                                                              //~v5j6I~
	if (fdstdisv>=0)                                               //~v59jM~
    {                                                              //~v59jM~
#ifdef UNX                                                         //~v59jM~
	    if(dup2(fdstdisv,fileno(stdin))==-1) // restore own stdout //~v59jR~
#else                                                              //~v59jM~
    	if(_dup2(fdstdisv,_fileno(stdin))!= 0) // restore own stdout//~v59jM~
#endif                                                             //~v59jM~
        	uerrexit("dup2 stdoin restore failed,errno=%d",0,      //~v59jM~
						errno);                                    //~v59jM~
    	close(fdstdisv);      //no more required                   //~v59jM~
    }                                                              //~v59jM~
    if (pid<=0)                                                    //~v59jM~
		uspawnvp_pipeclose(fdpipe_p2c,fdpipe_c2p);                 //~v59jM~
    *Ppids=pid;                                                    //~v59jM~
    *(Ppids+1)=fdpipe_p2c[1];	//fd to write to child             //~v59jM~
    *(Ppids+2)=fdpipe_c2p[0];	//fd to read from child            //~v59jM~
    return errnosv;                                                //~v59jM~
}//uspawnvp_pipe                                                   //~v59jM~
#ifdef AAA  //no caller                                            //~v6xkI~
//*********************************************************************//~v59jM~
//*end child                                                       //~v59jM~
//*parm:int tbl; pid,Write-fd,Read-fd                              //~v59jM~
//ret :errno before close                                          //~v59jM~
//*********************************************************************//~v59jM~
//int uspawnvp_pipeend(int *Ppids)                                 //~v6xkR~
int uspawnvp_pipeend(LONGHANDLE *Ppids)                            //~v6xkI~
{                                                                  //~v59jM~
	int pstat;                                                     //~v59jM~
//**************                                                   //~v59jM~
#ifdef UNX                                                         //~v59jM~
	waitpid(*Ppids,&pstat,0);                                      //~v59jM~
#else                                                              //~v59jM~
    _cwait(&pstat,*Ppids, WAIT_CHILD );                            //~v59jM~
#endif                                                             //~v59jM~
//  printf("child exit status=%x\n",pstat);                        //~v5g9R~
    close(*(Ppids+1));                                             //~v59jM~
    close(*(Ppids+2));                                             //~v59jM~
    *(Ppids+1)=-1;                                                 //~v59jM~
    *(Ppids+2)=-1;                                                 //~v59jM~
    return pstat;                                                  //~v59jM~
}//uspawnvp_pipeend                                                //~v59jM~
#endif                                                             //~v6xkI~
//*********************************************************************//~v59jM~
//* close pipe file                                                //~v59jM~
//ret :errno before close                                          //~v59jM~
//*********************************************************************//~v59jM~
int uspawnvp_pipeclose(int *Ppipe_p2c,int *Ppipe_c2p)              //~v59jM~
{                                                                  //~v59jM~
	int errnosv,fd;                                                //~v59jM~
//**************                                                   //~v59jM~
	errnosv=errno;                                                 //~v59jM~
    fd=*Ppipe_p2c;                                                 //~v59jM~
    if (fd>=0)                                                     //~v59jM~
    	close(fd);                                                 //~v59jM~
    fd=*(Ppipe_p2c+1);                                             //~v59jM~
    if (fd>=0)                                                     //~v59jM~
    	close(fd);                                                 //~v59jM~
    fd=*Ppipe_c2p;                                                 //~v59jM~
    if (fd>=0)                                                     //~v59jM~
    	close(fd);                                                 //~v59jM~
    fd=*(Ppipe_c2p+1);                                             //~v59jM~
    if (fd>=0)                                                     //~v59jM~
    	close(fd);                                                 //~v59jM~
    errno=errnosv;                                                 //~v59jM~
    return errno;                                                  //~v59jM~
}//uspawnvp_pipeclose                                              //~v59jM~
//*********************************************************************//~v5bxI~
//* close pipe file                                                //~v5bxI~
//ret :errno before close                                          //~v5bxI~
//*********************************************************************//~v5bxI~
int usystem_cmdserverinit(int Popt,CMDSVRCALLBACK *Pcmdsvrcallback,char *Pserverpgm,int *Pppid,int *Ppfpipew,int *Ppfdpiper)//~v5bxR~
{                                                                  //~v5bxI~
//**************                                                   //~v5bxI~
    Sserverstat=0;                                                 //~v5bxI~
    UTRACEP("%s:opt=x%x,serverPgm=%s\n",UTT,Popt,Pserverpgm);      //~v70cR~
	if (Popt & UPROC_LAZY) //start cmd server st cmd req           //~v5bxI~
    {	                                                           //~v5bxI~
	    Sserverstat|=SVRS_LAZY;                                    //~v5bxI~
        Scmdservercallback=Pcmdsvrcallback;                        //~v5bxI~
        Scallbackparm=Pserverpgm;                                  //~v5bxR~
    	return 0;                                                  //~v5bxI~
    }                                                              //~v5bxI~
    return usystem_cmdserversetup(Popt,Pserverpgm,Pppid,Ppfpipew,Ppfdpiper);//~v5bxI~
}//usystem_cmdserverinit                                           //~v5bxR~
//*********************************************************************//~v5bxI~
//* send term string to childproc                                  //~v5ivR~
//ret :rc                                                          //~v5ivR~
//*********************************************************************//~v5bxI~
//int usystem_cmdserverterm(int Ppid,int Pfdw,int Pfdr)            //~v5ivR~
int usystem_cmdserverterm(int Popt,int Ppid,int Pfdw,int Pfdr)   //~v5bxR~
{                                                                  //~v5bxI~
    int fdw;                                                       //~v5bxI~
    int pid;                                                       //~v6bxR~
    int syscmd; //server is for xesyscmd                           //~v5ivI~
//**************                                                   //~v5bxI~
    syscmd=!(Popt & UPROC_SERVER2); //xesyscmd                     //~v5ivI~
  if (syscmd)                                                      //~v5ivI~
    if (!Sserverstat)                                              //~v5ccI~
    	return 0;                                                  //~v5ccI~
    if (!(pid=Ppid))                                               //~v5ccI~
    {                                                              //~v5ivI~
      if (syscmd)                                                  //~v5ivI~
    	pid=Scmdserverchildpid;                                    //~v5ccI~
      else                                                         //~v5ivI~
      	return 4;                                                  //~v5ivI~
    }                                                              //~v5ivI~
    if (usystem_pidalivechk(pid))                                  //~v5ccR~
    	return 4;                                                  //~v5ccI~
    if (!(fdw=Pfdw))                                               //~v5bxI~
    {                                                              //~v5ivI~
      if (syscmd)                                                  //~v5ivI~
        fdw=Sfdpipew;                                              //~v5bxI~
      else                                                         //~v5ivI~
      	return 4;                                                  //~v5ivI~
    }                                                              //~v5ivI~
    if (fdw)                                                       //~v5bxI~
        write(fdw,"quit\0",5);                                     //~v5bxI~
  if (syscmd)                                                      //~v5ivI~
    Sserverstat=0;                                                 //~v5bxI~
    return 0;                                                      //~v5bxI~
}//usystem_cmdserverterm                                           //~v5bxR~
//*******************************************************          //~v5bxI~
//*start cmd server                                                //~v5bxI~
//*parm 1:opt                                                      //~v5j2R~
//*parm 2:sub process progname/cmd string(when server2 flag on,%s is used for fd edit)//~v5j2R~
//*parm 3:optional output child process handle                     //~v5j2R~
//*parm 4:optional write pipe to cmd server                        //~v5j2R~
//*parm 5:optional read  pipe from cmd server                      //~v5j2R~
//*ret  6:pid of subprocess,if noreadsw on return hProcess by spawn//~v5j2R~
//*******************************************************          //~v5bxI~
int usystem_cmdserversetup(int Popt,char *Pserverpgm,int *Pppid,int *Ppfdpipew,int *Ppfdpiper)//~v5bxR~
{                                                                  //~v5bxI~
    int pipes[4];                                                  //~v5bxI~
    int pid,fdpiper,fdpipew,rc;                                    //~v6bxR~
    char sfdr[16],sfdw[16],opts[16];                               //~v5bxR~
	char respbuff[16];                                             //~v5ccI~
    int len;                                                       //~v5ccI~
    ULONG cmdsvrpid;                                               //~v5ccR~
    int syscmd; //server is for xesyscmd                           //~v5ivR~
    int opt;                                                       //~v5j2I~
    int bypassreadsw,/*shellsw,*/argvsw,callbacksw;                    //~v5j2R~//~v6a0R~
    char **argv;                                                   //~v5j2R~
	STARTSERVER_FUNC *cbfunc;                                      //~v5j2I~
#ifdef W32                                                         //~v5j2I~
    char editcmd[4096];                                            //~v5j2I~
    int shellsw;                                                   //~v6a0I~
#endif                                                             //~v5j2I~
    LONGHANDLE ph;                                                 //~v6xkI~
//***********************                                          //~v5bxI~
UTRACEP("%s:opt=x%x,serverpgm=%s\n",UTT,Popt,Pserverpgm);          //~v70cI~
    syscmd=!(Popt & UPROC_SERVER2); //xesyscmd                     //~v5ivI~
    Popt &=~UPROC_SERVER2; //Popt used as parm to uspawn           //~v5ivR~
    opt=Popt & UPROC_SYSCMD_MIN;                                   //~v5j2I~
    Popt &=~UPROC_SYSCMD_MIN; //Popt used as parm to uspawn        //~v5j2I~
	bypassreadsw=Popt & UPROC_NOREADPID;                           //~v5j2I~
    Popt &=~UPROC_NOREADPID;	//bypass initial read              //~v5j2I~
#ifdef W32                                                         //~v6a0I~
	shellsw=Popt & UPROC_BYSHELL;                                  //~v5j2I~
#endif                                                             //~v6a0I~
    Popt &=~UPROC_BYSHELL;	    //through shell                    //~v5j2I~
	argvsw=Popt & UPROC_ARGV;   //parameter by argv fmt            //~v5j2R~
    Popt &=~UPROC_ARGV;	    //through shell                        //~v5j2I~
	callbacksw=Popt & UPROC_CALLBACK;   //start child by callback function//~v5j2I~
    Popt &=~UPROC_CALLBACK;                                        //~v5j2I~
  if (syscmd)                                                      //~v5ivI~
  {                                                                //~v5ivI~
    Scmdserverchildpid=0;                                          //~v5ccI~
    Sserverstat=0;      //dont use server                          //~v5bxI~
  }                                                                //~v5ivI~
#ifdef UNX                                                         //~v5bxI~
    if (pipe(pipes)==-1)	//create pipe                          //~v5bxI~
#else                                                              //~v5bxI~
    if (_pipe(pipes,4096,_O_TEXT)<0)   //child stdin               //~v5bxI~
#endif                                                             //~v5bxI~
		return ufileapierr("_popen",Pserverpgm,errno);             //~v5bxR~
#ifdef UNX                                                         //~v5bxI~
    if (pipe(pipes+2)==-1)	//create pipe                          //~v5bxI~
#else                                                              //~v5bxI~
    if (_pipe(pipes+2,4096,_O_TEXT)<0)  //child stdout             //~v5bxI~
#endif                                                             //~v5bxI~
		return ufileapierr("_popen",Pserverpgm,errno);             //~v5bxR~
    fdpiper=dup(pipes[2]); //c->p(R)==>stdout;                     //~v5bxI~
    close(pipes[2]);		//avoid inherit                        //~v5bxI~
    fdpipew=dup(pipes[1]);//p(W)->c==>stdin                        //~v5bxI~
    close(pipes[1]);		//avoid inherit                        //~v5bxI~
//  sprintf(opts,"%d",Popt);                                       //~v5j2R~
    sprintf(opts,"%d",opt);                                        //~v5j2I~
    sprintf(sfdr,"%d",pipes[0]);                                   //~v5bxI~
    sprintf(sfdw,"%d",pipes[3]);                                   //~v5bxI~
UTRACEP("child spawn\n");                                          //~v5bxI~
 if (callbacksw)                                                   //~v5j2I~
 {                                                                 //~v5j2I~
//	cbfunc=(STARTSERVER_FUNC*)(ULONG)Pserverpgm;                   //~v5j2I~//~v6hhR~
	cbfunc=(STARTSERVER_FUNC*)(ULPTR)Pserverpgm;                   //~v6hhI~
 	pid=cbfunc(0,pipes[0],pipes[3]);                               //~v5j2I~
 }                                                                 //~v5j2I~
 else   //not callback                                             //~v5ivR~
 {                                                                 //~v5ivI~
#ifdef W32                                                         //~v5ivI~
  if (shellsw)	//xesyscmd                                         //~v5j2R~
  {                                                                //~v5j2M~
  	sprintf(editcmd,Pserverpgm,sfdr,sfdw); //edit in pipe fd       //~v5j2M~
//  pid=uspawnlp(P_NOWAIT|Popt,SHELLPGM,SHELLPGM,"/C",editcmd,0);  //~v5j2I~//~v6xkR~
	UTRACEP("%s:spawnlp editcmd=%s\n",UTT,editcmd);                //~v70cI~
    ph=uspawnlp(P_NOWAIT|Popt,SHELLPGM,SHELLPGM,"/C",editcmd,0);   //~v6xkI~
    pid=(int)UGETPROCESSID(UGPIO_ERRMSG,ph);                       //~v6xkI~
  }                                                                //~v5j2M~
  else	//xe3270                                                   //~v5j2M~
  {                                                                //~v5j2I~
#endif                                                             //~v5ivI~
   if (argvsw)                                                     //~v5j2I~
   {                                                               //~v5j2I~
// 	for (argv=(char**)(ULONG)Pserverpgm;*argv;argv++)	           //~v5j2R~//~v6hhR~
 	for (argv=(char**)(ULPTR)Pserverpgm;*argv;argv++)              //~v6hhI~
    {                                                              //~v5j2I~
//    	if ((ULONG)(*argv)==UPROC_PIPE_P2C)                        //~v5j2R~//~v6hhR~
    	if ((ULONG)(ULPTR)(*argv)==UPROC_PIPE_P2C)                 //~v6hhI~
        	*argv=sfdr;                                            //~v5j2R~
        else                                                       //~v5j2I~
//    	if ((ULONG)(*argv)==UPROC_PIPE_C2P)                        //~v5j2R~//~v6hhR~
    	if ((ULONG)(ULPTR)(*argv)==UPROC_PIPE_C2P)                 //~v6hhI~
        	*argv=sfdw;                                            //~v5j2R~
    }                                                              //~v5j2I~
// 	argv=(char**)(ULONG)Pserverpgm;                                //~v5j2I~//~v6hhR~
 	argv=(char**)(ULPTR)Pserverpgm;                                //~v6hhI~
//  pid=uspawnvp(P_NOWAIT|Popt,argv[0],argv);                      //~v5j2I~//~v6xkR~
    ph=uspawnvp(P_NOWAIT|Popt,argv[0],argv);                       //~v6xkI~
    pid=(int)UGETPROCESSID(UGPIO_ERRMSG,ph);                       //~v6xkI~
   }                                                               //~v5j2I~
   else                                                            //~v5j2I~
   {                                                               //~v6xkI~
//  pid=uspawnlp(P_NOWAIT|Popt,Pserverpgm,Pserverpgm,opts,sfdr,sfdw,0);//~v5bxR~//~v6xkR~
    ph=uspawnlp(P_NOWAIT|Popt,Pserverpgm,Pserverpgm,opts,sfdr,sfdw,0);//~v6xkI~
    pid=(int)UGETPROCESSID(UGPIO_ERRMSG,ph);                       //~v6xkI~
   }                                                               //~v6xkI~
#ifdef W32                                                         //~v5ivI~
  }                                                                //~v5j2I~
#endif                                                             //~v5ivI~
 }//not callback                                                   //~v5j2I~
    if (pid==-1)                                                   //~v5bxR~
    {                                                              //~v5bxI~
    	rc=errno;                                                  //~v5bxI~
        close(pipes[0]);                                           //~v5ccI~
        close(pipes[3]);                                           //~v5ccI~
        close(fdpipew);                                            //~v5ccR~
        close(fdpiper);                                            //~v5ccR~
		uerrmsg("%s start failed,rc=%d.",                          //~v5bxR~
//  			"%s の起動失敗。",                                 //~v61iR~
    			"%s の起動失敗。rc=%d",                            //~v61iI~
				Pserverpgm,rc);                                    //~v5bxR~
        return rc;                                                 //~v5bxR~
    }                                                              //~v5bxI~
UTRACEP("child spawned\n");                                        //~v5bxI~
	if (Ppfdpipew)                                                 //~v5bxI~
    	*Ppfdpipew=fdpipew;                                        //~v5bxI~
	if (Ppfdpiper)                                                 //~v5bxI~
    	*Ppfdpiper=fdpiper;                                        //~v5bxI~
  if (!bypassreadsw)                                               //~v5j2I~
  {                                                                //~v5j2I~
//	len=read(fdpiper,respbuff,sizeof(respbuff)-1); 	//wait reply   //~v5ccI~//~v6xiR~
	len=(int)read(fdpiper,respbuff,sizeof(respbuff)-1); 	//wait reply//~v6xiI~
UTRACEP("%s:read resp\n",UTT);                                           //~v5ccI~//~v70cR~
UTRACED("read resp",respbuff,len);                                 //~v70cI~
	if (len>=0)                                                    //~v5ccI~
		*(respbuff+len)=0; 	//wait reply                           //~v5ccI~
    ux2l(respbuff,&cmdsvrpid); //cmdserver pid                     //~v5ccR~
    pid=(int)cmdsvrpid;                                            //~v5ccR~
  }                                                                //~v5j2I~
	uerrmsg("CS:%s started, ProcessID=%d(0x%X).",                  //~v6xkI~
    		"CS:%s が起動, プロセスID=%d(0x%X)",                   //~v6xkI~
				Pserverpgm,pid,pid); //spawan pid is handle,this pid is ProcessIdNo//~v6xkI~
	if (Pppid)                                                     //~v5bxI~
    	*Pppid=pid;                                                //~v5bxI~
  if (syscmd)                                                      //~v5ivI~
  {                                                                //~v5ivI~
    Scmdserverchildpid=pid;                                        //~v5ccI~
    Sserverstat=SVRS_READY;                                        //~v5bxI~
    Sfdpiper=fdpiper;                                              //~v5bxR~
    Sfdpipew=fdpipew;                                              //~v5bxR~
  }                                                                //~v5ivI~
    return 0;                                                      //~v5bxI~
}//usystem_cmdserversetup                                          //~v5bxI~
//*******************************************************          //~v5cwI~
//*throw request to cmd server itself                              //~v5cwI~
//*parm 1:option                                                   //~v5cwI~
//*parm 2:cmd string                                               //~v5cwI~
//*ret   :rc                                                       //~v5cwI~
//*******************************************************          //~v5cwI~
int usystem_cmdtocmdserver(int Popt,char *Pcmd)                    //~v5cwI~
{                                                                  //~v5cwI~
	int rc=0;                                                      //~v5cwI~
//***********************                                          //~v5cwI~
    if (Sserverstat & SVRS_READY)	//setup sccess                 //~v5cwI~
		rc=usystem_cmdserverreq(UPROC_NOTIFY,Scmdserverchildpid,Pcmd,0,0,Sfdpipew,Sfdpiper);//no stdo/stde filename//~v5cwR~
    return rc;                                                     //~v5cwI~
}//usystem_cmdtocmdserver                                          //~v5cwI~
//*******************************************************          //~v5bxI~
//*throw request to resident client                                //~v5bxI~
//*parm 1:option                                                   //~v5bxI~
//*parm 2:cmd server process id                                    //~v5ccR~
//*parm 3:cmd string	replaced by output when 3270 server        //~v5ivR~
//*parm 4:optional stdout filename                                 //~v5ccR~
//*parm 5:optional stderr filename                                 //~v5ccR~
//*parm 6:optional write pipe fd                                   //~v5ccR~
//*parm 7:optional read  pipe fd                                   //~v5ccR~
//*ret   :rc(-1 if write failed)                                   //~v5bxR~
//*******************************************************          //~v5bxI~
//int usystem_cmdserverreq(int Popt,char *Pcmd,char *Pstdofnm,char *Pstdefnm,int Pfdw,int Pfdr)//~v5ccR~
int usystem_cmdserverreq(int Popt,int Ppid,char *Pcmd,char *Pstdofnm,char *Pstdefnm,int Pfdw,int Pfdr)//~v5ccR~
{                                                                  //~v5bxI~
//  char cmd[1024+_MAX_PATH];                                      //~v5csR~
    char cmd[UPROC_MAX_CMDSVRBUF];                                 //~v5csR~
	char respbuff[16];                                             //~v5bxI~
    int fdr,fdw,rc,len;                                            //~v5bxR~
    int syscmd; //server is for xesyscmd                           //~v5ivI~
//***********************                                          //~v5bxI~
    syscmd=!(Popt & UPROC_SERVER2); //xesyscmd                     //~v5ivI~
    if (rc=usystem_pidalivechk(Ppid),rc)                           //~v5ccR~
    {                                                              //~v5ccI~
#ifdef WXE                                                         //~v6ycI~
    	uerrmsg("cmd server process(%d) is not active(rc=0x%x),please restart wxe.",//~v6ycI~
    	        "コマンド処理プロセス(%d) が活動していません(rc=0x%x), wxe の再始動が必要です",//~v6ycI~
    			Ppid,rc);                                          //~v6ycI~
#else                                                              //~v6ycI~
    	uerrmsg("cmd server process(%d) is not active(rc=0x%x),please restart xe or DOS prompt appear each time.",0,//~v5ccR~
    			Ppid,rc);                                          //~v5ccI~
#endif                                                             //~v6ycI~
      if (syscmd)                                                  //~v5ivI~
    	Sserverstat=0;	//no more use cmd server                   //~v5ccI~
    	return 4;                                                  //~v5ccI~
    }                                                              //~v5ccI~
	if (Pstdofnm && Pstdefnm)                                      //~v5bxI~
    {                                                              //~v5bxI~
    	if (strcmp(Pstdofnm,Pstdefnm))	//stderr is different from stdout name//~v5bxI~
    		sprintf(cmd,"%s >%s 2>%s",Pcmd,Pstdofnm,Pstdefnm);     //~v5bxI~
        else                                                       //~v5bxI~
    		sprintf(cmd,"%s >%s 2>&1",Pcmd,Pstdofnm);              //~v5bxI~
    }                                                              //~v5bxI~
    else                                                           //~v5bxI~
    	if (Pstdofnm)                                              //~v5bxI~
		    sprintf(cmd,"%s >%s",Pcmd,Pstdofnm);                   //~v5bxI~
        else                                                       //~v5bxI~
	    	if (Pstdefnm)                                          //~v5bxI~
			    sprintf(cmd,"%s 2>%s",Pcmd,Pstdefnm);              //~v5bxI~
            else                                                   //~v5bxI~
                strcpy(cmd,Pcmd);                                  //~v5bxI~
    if (!(fdw=Pfdw))                                               //~v5bxI~
    {                                                              //~v5ivI~
      if (syscmd)                                                  //~v5ivI~
        fdw=Sfdpipew;                                              //~v5bxR~
      else                                                         //~v5ivI~
        return 16;                                                 //~v5ivI~
    }                                                              //~v5ivI~
    if (!(fdr=Pfdr))                                               //~v5bxI~
    {                                                              //~v5ivI~
      if (syscmd)                                                  //~v5ivI~
        fdr=Sfdpiper;                                              //~v5bxR~
      else                                                         //~v5ivI~
        return 16;                                                 //~v5ivI~
    }                                                              //~v5ivI~
//  rc=write(fdw,cmd,strlen(cmd));                                 //~v5bxR~//~v6xiR~
    rc=(int)write(fdw,cmd,strlen(cmd));                            //~v6xiI~
UTRACEP("push cmd=%s\n",cmd);                                      //~v5bxI~
	if (rc==-1)                                                    //~v5bxI~
    {                                                              //~v5bxI~
    	if (Scmdservercallback)                                    //~v5bxI~
		    Scmdservercallback(CMDCB_WRTER,Scallbackparm);         //~v5bxI~
        else                                                       //~v5bxI~
			uerrmsg("Request write to command server afiled,rc=%d",//~v5bxR~
						"コマンドサーバーへの要求の書きこみ失敗。rc=%d",//~v5bxR~
					errno);                                        //~v5bxR~
      if (syscmd)                                                  //~v5ivI~
    	Sserverstat=0;	//no more use cmd server                   //~v5bxI~
        return -1;                                                 //~v5bxI~
    }                                                              //~v5bxI~
//  len=read(fdr,respbuff,sizeof(respbuff)-1); 	//wait reply       //~v5bxR~//~v6xiR~
    len=(int)read(fdr,respbuff,sizeof(respbuff)-1); 	//wait reply//~v6xiI~
	if (len>=0)                                                    //~v5bxI~
		*(respbuff+len)=0; 	//wait reply                           //~v5bxR~
UTRACEP("read resp=%s\n",respbuff);                                           //~v5bxI~//~v6ycI~
    if (Soutbuffsz)                          //req from usystem_cmdserver2req//~v5ivI~
//  	strncpy(Soutbuff,respbuff,Soutbuffsz);	                   //~v6xiR~
    	strncpy(Soutbuff,respbuff,(UINT)Soutbuffsz);               //~v6xiI~
	return atoi(respbuff);                                         //~v5bxR~
}//usystem_cmdserverreq                                            //~v5bxI~
//*****************************************                        //~v5ivI~
//* issue cmd and get reqp to 3270 server                          //~v5ivI~
//*****************************************                        //~v5ivI~
int usystem_cmdserverreqwithoutbuff(int Popt,int Ppid,char *Pcmd,char *Pstdofnm,char *Pstdefnm,int Pfdw,int Pfdr,char *Ppresbuff,int Prespbuffsz)//~v5ivR~
{                                                                  //~v5ivI~
	int rc;                                                        //~v5ivI~
//****************************                                     //~v5ivI~
	Soutbuffsz=Prespbuffsz;                                        //~v5ivI~
	Soutbuff=Ppresbuff;                                            //~v5ivI~
	rc=usystem_cmdserverreq(Popt,Ppid,Pcmd,Pstdofnm,Pstdefnm,Pfdw,Pfdr);//~v5ivR~
	Soutbuffsz=0;                                                  //~v5ivI~
	Soutbuff=0;                                                    //~v5ivI~
    return rc;                                                     //~v5ivI~
}                                                                  //~v5ivI~
//*****************************************                        //~v5ccI~
//* process alive chk                                              //~v5ccI~
//*****************************************                        //~v5ccI~
int usystem_pidalivechk(int Ppid)                                  //~v5ccR~
{                                                                  //~v5ccI~
//#ifdef WXE                                                       //~v5ndR~
#ifdef W32                                                         //~v5ndI~
	HANDLE ph;                                                     //~v5ccI~
    ULONG exitcode;                                                //~v5ccI~
	int rc;                                                        //~v5ccI~
//*************************                                        //~v5ccI~
	ph=OpenProcess(PROCESS_QUERY_INFORMATION,FALSE,Ppid);//false:noinherit//~v5ccI~
    if (!ph)	//process not found                                //~v5ccI~
//  	return GetLastError();                                     //~v5ndR~
    	return -(int)GetLastError();	//id of pid not found      //~v5ndR~
    if (GetExitCodeProcess(ph,&exitcode))   //success              //~v5ccI~
    {                                                              //~v5ccI~
        if (exitcode==STILL_ACTIVE)                                //~v5ccR~
            rc=0;                                                  //~v5ccI~
        else                                                       //~v5ccI~
        {                                                          //~v5ccI~
    		uerrmsg("cmd server process exit,exitcode=%x",0,       //~v5ccI~
				exitcode);                                         //~v5ccI~
        	rc=exitcode;                                           //~v5ccI~
		}                                                          //~v5ccI~
    }                                                              //~v5ccI~
    else                                                           //~v5ccI~
	    rc=GetLastError();                                         //~v5ccI~
    if (!CloseHandle(ph))                                          //~v5ccI~
    	return uerrapi0("CloseHandle",GetLastError());             //~v5ccR~
#else                                                              //~v5ccI~
//*************************                                        //~v5ccI~
	int rc=0;                                                      //~v5ccI~
#endif                                                             //~v5ccI~
    return rc;                                                     //~v5ccR~
}//usystem_pidalivechk                                             //~v5ccI~
#endif  //if defined(UNX) || defined(W32)                          //~v77CI~
#ifdef ARM                                                         //~v77CR~
//*****************************************                        //~v77CI~
//* process alive chk                                              //~v77CI~
//*****************************************                        //~v77CI~
void *uproc_dlopen(char *Pfnm)                                       //~v77CI~
{                                                                  //~v77CI~
	void *handle;                                                  //~v77CI~
	char *perr;                                                    //~v77CI~
//*************************                                        //~v77CI~
	perr=dlerror();	//clear prev err                               //~v77CI~
    UTRACEP("%s:fnm=%s,prev dlerror=%s\n",UTT,Pfnm,perr);          //~v77CI~
    UTRACEP("%s:LD_LIBRARY_PATH=%s\n",UTT,getenv("LD_LIBRARY_PATH"));//~v77CI~
	handle=dlopen(Pfnm,RTLD_NOW);                                  //~v77CI~
    dlopenErr=errno;                                               //~v77JI~
	perr=dlerror();	//clear prev err                               //~v77CI~
    UTRACEP("%s:dlopen handle=%p,dlerror=%s\n",UTT,handle,perr);   //~v77CI~
    return handle;                                                 //~v77CR~
}                                                                 //~v77CI~
    typedef int (*FUNC_MAIN)(int argc,char *argp[],char *envp[]);  //~v77DR~
    typedef void *(*FUNC_THREAD)(void*);                           //~v77DR~
	static FUNC_MAIN func_main;                                    //~v77DR~
//*****************************************                        //~v77DI~
static sigjmp_buf Senv;                                          //~v77DI~
void sigHandler(int Psigno)                                        //~v77DI~
{                                                                  //~v77DI~
	UTRACEP("%s:sigHandler signal=%d\n",UTT,Psigno);               //~v77DI~
    printf("!!! signal=%d detected.\n",Psigno);                    //~v77DI~
	siglongjmp(Senv,Psigno);	//jump to after sigsetjmp          //~v77DI~
}                                                                  //~v77DI~
//*****************************************                        //~v77DI~
#define MAX_SIGNAL 5                                                //~v77DI~
static int Ssignals[MAX_SIGNAL]={SIGINT/*2:Ctrl+c*/,SIGABRT/*6*/,SIGSEGV/*11*/,SIGTERM/*15*/,SIGQUIT/*3*/};//~v77DI~
static struct sigaction SoldAction[MAX_SIGNAL];//~v77DI~
static int Sretval;                                                //~v77DI~
//*****************************************                        //~v77DI~
void setSigAction(struct sigaction *Ppaction)                      //~v77DR~
{                                                                  //~v77DR~
//********************                                             //~v77DI~
	UTRACEP("%s:entry handler=%p\n",UTT,sigHandler);               //~v77DR~
    memset (Ppaction,0,sizeof(struct sigaction));                  //~v77DI~
    Ppaction->sa_handler=sigHandler;                                //~v77DI~
    Ppaction->sa_flags=0;                                          //~v77DI~
    for (int ii=0;ii<MAX_SIGNAL;ii++)                              //~v77DI~
    {                                                              //~v77DI~
	    memset (&SoldAction[ii],0,sizeof(struct sigaction));      //~v77DI~
    	sigaction(Ssignals[ii],Ppaction,&SoldAction[ii]);         //~v77DI~
		UTRACEP("%s:SoldAction ii=%d,signal=%d,handler=%p\n",UTT,ii,Ssignals[ii],SoldAction[ii].sa_handler);//~v77DI~
    }                                                              //~v77DI~
}                                                                  //~v77DR~
//*****************************************                        //~v77DI~
void restoreSigAction()                                            //~v77DI~
{                                                                  //~v77DI~
	struct sigaction old_action;                                   //~v77DI~
//********************                                             //~v77DI~
	UTRACEP("%s:entry\n",UTT);                                     //~v77DI~
    for (int ii=0;ii<MAX_SIGNAL;ii++)                              //~v77DI~
    {                                                              //~v77DI~
    	sigaction(Ssignals[ii],&SoldAction[ii],&old_action);       //~v77DR~
		UTRACEP("%s:oldAction ii=%d,signal=%d,Sold_handle=%p,old_handle=%p\n",UTT,ii,Ssignals[ii],SoldAction[ii].sa_handler,old_action.sa_handler);//~v77DR~
    }                                                              //~v77DI~
}                                                                  //~v77DI~
//*****************************************                        //~v77DI~
char **parseParm(char *Pcmd,int *Ppopdno)                          //~v77DI~
{                                                                  //~v77DI~
	UCHAR **pargv;                                                 //~v77DR~
    int opdno;                                                     //~v77DI~
                                                                   //~v77DI~
//**********************	                                       //~v77DI~
	uparsev(Pcmd,&pargv,&opdno,0," ,");                            //~v77DR~
    *Ppopdno=opdno;                                                //~v77DI~
	UTRACEP("%s:opdno=%d,cmd=%s\n",UTT,opdno,Pcmd);                //~v77DI~
    return (char**)pargv;                                          //~v77DR~
}                                                                  //~v77DI~
//*****************************************                        //~v77DI~
void *func_thread(void* Pcmd)                                      //~v77DR~
{                                                                  //~v77DI~
	struct sigaction action;                                       //~v77DR~
    int rc,opdno;                                                  //~v77DR~
    extern char **environ;                                             //~v77DI~
//  char *pc;                                                      //~v77DR~
//********************                                             //~v77DI~
	UTRACEP("%s:entry,cmd=%s\n",UTT,Pcmd);                         //~v77DR~
    Sretval=0;                                                     //~v77DI~
    setSigAction(&action);                                         //~v77DI~
    rc=sigsetjmp(Senv,1/*!=0:request to save signal mask*/);  //rc!=0 returned by siglongjmp//~v77DI~
    if (rc!=0)                                                     //~v77DI~
    {                                                              //~v77DI~
		UTRACEP_FLUSH("%s:siglongjmp called\n",UTT);                     //~v77DI~//~v77LR~
        Sretval=0x80+rc;	//siglongjump set signal number        //~v77DI~
        return &Sretval;                                           //~v77DI~
    }                                                              //~v77DI~
//  char *arg[4];                                                  //~v77DR~
//  arg[0]=(char*)Pvoidparm;                                       //~v77DR~
//  pc=strchr(Pvoidparm,' ');                                      //~v77DR~
//  if (pc)                                                        //~v77DR~
//      arg[1]=pc+1;                                               //~v77DR~
//  else                                                           //~v77DR~
//      arg[1]="";                                                 //~v77DR~
//  arg[2]=0;                                                      //~v77DR~
    char **parg=parseParm(Pcmd,&opdno);                            //~v77DI~
	UTRACEP("%s:parseparm opdno=%d,[0]=%s,[1]=%s\n",UTT,opdno,parg[0],parg[1]);//~v77DR~
    listenv();                                                     //~v77DI~
	rc=func_main(opdno,parg,environ);                                  //~v77DR~
	UTRACEP("%s:return rc=%d\n",UTT,rc);                           //~v77DI~
    Sretval=rc;                                                    //~v77DI~
    restoreSigAction();                                            //~v77DR~
	UTRACEP("%s:exit &Sretval=%p\n",UTT,&Sretval);                 //~v77DI~
    return &Sretval;                                               //~v77DI~
}                                                                  //~v77DI~
//*****************************************                        //~v77DR~
int func_mainOnThread(FUNC_MAIN Pfunc,char *Ppgm,char *Pcmd)       //~v77DR~
{                                                                  //~v77DR~
    int rc,retval;                                                 //~v77DR~
    pthread_t pt;                                                  //~v77DR~
    int *ptrrc=0;                                                  //~v77DR~
    void *pvoidrc=0;                                               //~v77DI~
//  char pathparm[_MAX_PATH];                                      //~v77DR~
//*************************                                        //~v77DR~
	UTRACEP("%s:entry pgm=%s,cmd=%s\n",UTT,Ppgm,Pcmd);             //~v77DR~
//  sprintf(pathparm,"%s %s",Ppath,Pparm);                         //~v77DR~
    rc/*0:success*/=pthread_create(&pt,NULL,&func_thread,Pcmd);    //~v77DR~
	UTRACEP("%s:after pthread_create rc=%d\n",UTT,rc);             //~v77DR~
    rc/*0:success*/=pthread_join(pt,&pvoidrc/*ptr to pthread_exit(retval)*/);//~v77DR~
	UTRACEP("%s:after pthread_join rc=%d\n",UTT,rc);               //~v77DR~
    ptrrc=(int*)pvoidrc;                                           //~v77DI~
	UTRACEP("%s:after pthread_join retval(pthread_exit() argument)=%p,&Sretval=%p,ptrrc=%p\n",UTT,pvoidrc,&Sretval,ptrrc);//~v77DI~
//  if (ptrrc==&Sretval)  //set by siglongjmp or normal return code//~v77DR~
//  {                                                              //~v77DR~
    	retval=*ptrrc;                                             //~v77DR~
	    printf("pgm end with rc=%d=0x%x.(%s) \n",retval,retval,Ppgm);//~v77DR~
//  }                                                              //~v77DR~
//  else                                                           //~v77DR~
//  {                                                              //~v77DR~
//  	retval=(int)(unsigned long)ptrrc;  //pthread_exit(retval)  //~v77DR~
//      printf("pgm end with exit_code=%d=0x%x.(%s)\n",retval,retval,Ppgm);//~v77DR~
//  }                                                              //~v77DR~
	UTRACEP("%s:rc=%d\n",UTT,retval);                              //~v77JI~
	if (retval==-1)                                                //~v77JI~
    	retval=ERR_ONTHREAD;                                       //~v77JI~
	UTRACEP("%s:exit rc=%d\n",UTT,retval);                         //~v77DI~
    return retval;                                                 //~v77DR~
}                                                                  //~v77DR~
#ifdef ARMXXE                                                      //~vc70I~
//*****************************************                        //~v77DR~
int uproc_callxetool(char *Pfnm,char *Ppgm,char *Pcmd)                                  //~v77CR~//~v77DR~
{                                                                  //~v77CI~
	void *handle,*procaddr;                                        //~v77CI~
	char *perr;                                                    //~v77CI~
    int rc=-1;                                                     //~v77CI~//~v77DR~
//*************************                                        //~v77CI~
	UTRACEP("%s:entry fnm=%s,pgm=%s,cmd=%s\n",UTT,Pfnm,Ppgm,Pcmd); //~v77DR~
	handle=uproc_dlopen(Pfnm);                                     //~v77CI~//~v77DR~
    if (handle)                                                    //~v77CI~
    {                                                              //~v77CI~
    	procaddr=dlsym(handle,"main");                              //~v77CI~
		perr=dlerror();	//clear prev err                           //~v77CI~
	    UTRACEP("%s:dlsym procaddr=%p,dlerror=%s\n",UTT,procaddr,perr,perr);//~v77CI~
        if (procaddr)                                              //~v77CI~
        {                                                          //~v77CI~
            func_main=(FUNC_MAIN)procaddr;                         //~v77CI~
//          arg[0]=path;                                           //~v77CI~//~v77DR~
//          arg[1]=Pparm;                                         //~v77CR~//~v77DR~
//          arg[2]=0;                                              //~v77CI~//~v77DR~
//        if (1)                                                   //~v77DR~
            rc=func_mainOnThread(func_main,Ppgm,Pcmd);             //~v77DR~
//        else                                                     //~v77DR~
//          rc=func_main(1,arg);                                   //~v77CR~//~v77DR~
	    	UTRACEP("%s:after call main rc=%d\n",UTT,rc);          //~v77CR~//~v77DR~
        }                                                          //~v77CI~
        dlclose(handle);                                           //~v77LI~
        UTRACEP("%s:after dlclose\n",UTT);                         //~v77LI~
    }                                                              //~v77CI~
    else                                                           //~v77JI~
    	rc=dlopenErr;                                              //~v77JI~
	UTRACEP("%s:exit rc=%d\n",UTT,rc);                             //~v77DI~
    return rc;                                                     //~v77DI~
}                                                                  //~v77CI~
//*****************************************                        //~v77CI~
void uproc_callxetoolSystem(char *Pcmd)                            //~v77CI~
{                                                                  //~v77CI~
    char cmd[_MAX_PATH];                                           //~v77CI~
    int rc;                                                        //~v77CI~
//*************************                                        //~v77CI~
	UTRACEP("%s:cmd=%s\n",UTT,Pcmd);                               //~v77CI~
  if (1)                                                           //~v77CI~
  {                                                                //~v77CI~
    sprintf(cmd,"%s/lib%s.so",GjniNativeLibraryPath,Pcmd);         //~v77CR~
	UTRACEP("%s:call sysem() fstat=%d,cmd=%sn",UTT,ufstat(cmd,0),cmd);//~v77CI~
    strcat(cmd," parm1 parm2");                                    //~v77CI~
  }	                                                               //~v77CI~
  else                                                             //~v77CI~
    sprintf(cmd,"export LD_LIBRARY_PATH=%s;%s %s %s",GjniNativeLibraryPath,Pcmd,"parm1","parm2");//~v77CI~
	UTRACEP("%s:call sysem() cmd=%s\n",UTT,cmd);                   //~v77CI~
    rc=system(cmd);    //bin/sh(actually bash) -c                  //~v77CI~
	UTRACEP("%s:call sysem() rc=%d\n",UTT,rc);                     //~v77CR~
}                                                                  //~v77CI~
//*****************************************                        //~v77LI~
int uproc_callxetoolExec(char *Pfnm,char *Ppgm,char *Pcmd)         //~v77LI~
{                                                                  //~v77LI~
    char cmd[_MAX_PATH];                                           //~v77LI~
    int rc;                                                        //~v77LI~
//*************************                                        //~v77LI~
	UTRACEP("%s:entry fnm=%s,pgm=%s,cmd=%s\n",UTT,Pfnm,Ppgm,Pcmd); //~v77LI~
    sprintf(cmd,"%s/%s %s",GjniNativeLibraryPath,Pfnm,Pcmd+strlen(Ppgm));//~v77LI~
	UTRACEP("%s:call system() cmd=%s\n",UTT,cmd);                   //~v77LI~//~vc70R~
  if (1)                                                           //~vc70I~
  {                                                                //~vc70I~
    sprintf(cmd,"%s/%s",GjniNativeLibraryPath,Pfnm);               //~vc70R~
    rc=c2j_runProcess(cmd/*so fnm*/,Pcmd+strlen(Ppgm)/*parm*/);    //~vc70R~
  }                                                                //~vc70I~
  else                                                             //~vc70I~
  if (1)                                                           //~v77LR~
  {                                                                //~v77LI~
    rc=system(cmd);    //bin/sh(actually bash) -c  ==> rc=8b(sigsegv), on logcat: avc denied "diskstat" dev "proc"//~v77LR~
	UTRACEP("%s:after call system() rc=%d=0x%x\n",UTT,rc,rc);      //~v77LI~
  }                                                                //~v77LI~
  else                                                             //~v77LI~
  {                                                                //~v77LI~
    sprintf(cmd,"%s/%s",GjniNativeLibraryPath,Pfnm);               //~v77LI~
    char *argv[3]={cmd,"0",0};                               //~v77LI~
    rc=spawnv(0,cmd,argv);    //do by ugcclib      //--> rc=11(sigsegv),on logcat: avc denied "diskstat" dev "proc"//~v77LR~
	UTRACEP("%s:after call spawnv() rc=%d=0x%x\n",UTT,rc,rc);  //  //~v77LI~
  }                                                                //~v77LI~
    return rc;                                                     //~v77LI~
}                                                                  //~v77LI~
//*****************************************                        //~v77CI~
int uproc_callxetoolTest(char *Pcmd,int *Pprc)                              //~v77CR~//~vc70R~
{                                                                  //~v77CI~
    char fnm[_MAX_PATH];                                           //~v77CI~
//  char *pc,*pparm;                                               //~v77DI~//~vc70R~
    int rc=0;                                                       //~v77DI~//~vc70R~
//*************************                                        //~v77CI~
	UTRACEP("%s:cmd=%s\n",UTT,Pcmd);                               //~v77CI~
    *Pprc=0;                                                       //~vc70I~
	if (!memcmp(Pcmd,"testtest",8))                            //~v77CR~//~vc70R~
    {                                                              //~v77CI~
//		void *handle=uproc_dlopen("libxtestenv_so.so");            //~vc70R~
//		UTRACEP("%s:handle%p\n",UTT,handle);                       //~vc70R~
      if (0)                                                       //~vc70R~
      {                                                            //~vc70I~
        sprintf(fnm,"%s/xtestenv",GjniNativeLibraryPath);          //~vc70I~
    	rc=execl(fnm,fnm,(char*)0L);                               //~vc70R~
        int rc2=errno;          //         -->errno=2              //~vc70R~
		UTRACEP("%s:after call execl() rc=%d=0x%x,errno=%d,cmd=%s\n",UTT,rc,rc,rc2,fnm);//~vc70R~
      }                                                            //~vc70I~
      else                                                         //~vc70I~
      if (0)                                                       //~vc70R~
      {                                                            //~vc70I~
        sprintf(fnm,"%s/libxtestenv_so.so",GjniNativeLibraryPath); //~vc70I~
    	rc=execl(fnm,fnm,(char*)0L); //-->crash                    //~vc70R~
		UTRACEP("%s:after call execl() rc=%d=0x%x,cmd=%s\n",UTT,rc,rc,fnm);//~vc70I~
      }                                                            //~vc70I~
      else                                                         //~vc70I~
      if (0)                                                       //~vc70R~
      {                                                            //~vc70I~
        sprintf(fnm,"%s/xtestenv",GjniNativeLibraryPath);          //~vc70I~
    	rc=system(fnm);   //-->inaccesible or not found            //~vc70R~
		UTRACEP("%s:after call system() rc=%d=0x%x,cmd=%s\n",UTT,rc,rc,fnm);//~vc70I~
      }                                                            //~vc70I~
      else                                                         //~vc70I~
      if (1)                                                    //~vc70I~
      {                                                            //~vc70I~
		UINT rc3;                                                  //~vc70I~
		FILEFINDBUF3 ffb3;                                        //~vc70I~
	    char dtm[_MAX_PATH];                                       //~vc70I~
                                                                   //~vc70I~
        strcpy(fnm,GjniNativeLibraryPath);                         //~vc70I~
		rc3=ufstat(fnm,&ffb3);                                     //~vc70I~
		UTRACEP("%s:ufstat rc=%d,fnm=%s\n",UTT,rc3,fnm);           //~vc70R~
		UTRACEP("%s:ufstat sz=%d,attr=0x%x\n",UTT,(int)(ffb3.cbFile),(int)(ffb3.attrFile));//~vc70R~
    	sprintf(dtm,"(%02d-%02d-%02d %02d:%02d)",         //~v64bI~//~vc70I~
    	        (ffb3.fdateLastWrite.year+80)%100,                    //~v64bI~//~vc70I~
       			ffb3.fdateLastWrite.month,                            //~v64bI~//~vc70I~
          		ffb3.fdateLastWrite.day,                              //~v64bI~//~vc70I~
          		ffb3.ftimeLastWrite.hours,                            //~v64bI~//~vc70I~
          		ffb3.ftimeLastWrite.minutes);                         //~v64bI~//~vc70I~
		UTRACEP("%s:ufstat date/time=%s\n",UTT,dtm);                   //~vc70I~
                                                                   //~vc70I~
        sprintf(fnm,"%s/xtestenv",GjniNativeLibraryPath);          //~vc70R~
		rc3=ufstat(fnm,&ffb3);                                     //~vc70I~
		UTRACEP("%s:ufstat rc=%d,fnm=%s\n",UTT,rc3,fnm);           //~vc70I~
		UTRACEP("%s:ufstat sz=%d,attr=0x%x\n",UTT,(int)(ffb3.cbFile),(int)(ffb3.attrFile));//~vc70I~
    	sprintf(dtm,"(%02d-%02d-%02d %02d:%02d)",                  //~vc70I~
    	        (ffb3.fdateLastWrite.year+80)%100,                 //~vc70I~
       			ffb3.fdateLastWrite.month,                         //~vc70I~
          		ffb3.fdateLastWrite.day,                           //~vc70I~
          		ffb3.ftimeLastWrite.hours,                         //~vc70I~
          		ffb3.ftimeLastWrite.minutes);                      //~vc70I~
		UTRACEP("%s:ufstat date/time=%s\n",UTT,dtm);               //~vc70I~
                                                                   //~vc70I~
        sprintf(fnm,"%s/libxtestenv_so.so",GjniNativeLibraryPath); //~vc70I~
		rc3=ufstat(fnm,&ffb3);                                     //~vc70I~
		UTRACEP("%s:ufstat rc=%d,fnm=%s\n",UTT,rc3,fnm);           //~vc70R~
		UTRACEP("%s:ufstat sz=%d,attr=0x%x\n",UTT,(int)(ffb3.cbFile),(int)(ffb3.attrFile));//~vc70R~
    	sprintf(dtm,"(%02d-%02d-%02d %02d:%02d)",                  //~vc70I~
    	        (ffb3.fdateLastWrite.year+80)%100,                 //~vc70I~
       			ffb3.fdateLastWrite.month,                         //~vc70I~
          		ffb3.fdateLastWrite.day,                           //~vc70I~
          		ffb3.ftimeLastWrite.hours,                         //~vc70I~
          		ffb3.ftimeLastWrite.minutes);                          //~vc70I~
		UTRACEP("%s:ufstat date/time=%s\n",UTT,dtm);                   //~vc70I~
		void copyToTempForTest(char *PsrcFpath,char *PtgtName);    //~vc70I~
        copyToTempForTest(fnm,"libxtestenv_so.so");                //~vc70I~
    	rc=system(fnm); //-->segment fault                         //~vc70R~
		UTRACEP("%s:after call system() rc=%d=0x%x,cmd=%s\n",UTT,rc,rc,fnm);//~vc70I~
      }                                                            //~vc70I~
      else                                                         //~vc70I~
      {                                                            //~vc70I~
        sprintf(fnm,"%s",GjniNativeLibraryPath);      //~v77CI~//~v77DR~//~vc70R~
    	rc=c2j_runProcess(fnm,"xtestenv");                         //~vc70R~
		UTRACEP("%s:rc=%d\n",UTT,rc);                              //~vc70I~
      }                                                            //~vc70I~
      *Pprc=rc;                                                    //~vc70I~
      rc=1;                                                        //~vc70I~
    }                                                              //~v77CI~
    return rc;                                                     //~vc70I~
}                                                                  //~v77CI~
//*****************************************                        //~vc70I~
void copyToTempForTest(char *PsrcFpath,char *PtgtName)             //~vc70I~
{                                                                  //~vc70I~
	char tempFpath[_MAX_PATH];                                     //~vc70I~
    char buff[4096];                                               //~vc70I~
	UTRACEP("%s:src=%s,tgt=%s\n",UTT,PsrcFpath,PtgtName);          //~vc70I~
    sprintf(tempFpath,"%s/%s",gettempnampath(0),PtgtName);         //~vc70I~
    FILE *in=fopen(PsrcFpath,"rb");                                //~vc70I~
    FILE *out=fopen(tempFpath,"wb");                              //~vc70I~
    int tot=0;                                                     //~vc70I~
    for (;;)                                                       //~vc70I~
    {                                                              //~vc70I~
        int len=fread(buff,1,4096,in);                             //+vc70R~
        if (len<=0)                                                //~vc70I~
        	break;                                                 //~vc70I~
        tot+=len;                                                  //~vc70I~
        int lenW=fwrite(buff,1,len,out);                           //+vc70R~
        if (lenW!=len)                                             //~vc70I~
        	break;                                                 //~vc70I~
    }                                                              //~vc70I~
    fclose(in);                                                    //+vc70I~
    fclose(out);                                                   //+vc70I~
	UTRACEP("%s:tot=%d\n",UTT,tot);                                //~vc70I~
}                                                                  //~vc70I~
//*****************************************                        //~v77DI~
int callXeToolSO(char *Ppgm,char *Pcmd)                           //~v77DI~
{                                                                  //~v77DI~
    char sonm[32];                                                 //~v77DI~
	int rc;                                                        //~v77LI~
//*************************                                        //~v77DI~
	UTRACEP("%s:pgm=%s,cmd=%s\n",UTT,Ppgm,Pcmd);                   //~v77DI~
    sprintf(sonm,"lib%s_so.so",Ppgm);                              //~v77DR~
//if (0)       //TODO test                                         //~v77LR~
//  rc=uproc_callxetoolExec(sonm,Ppgm,Pcmd);                       //~v77LR~
//else                                                             //~v77LR~
//	int rc=uproc_callxetool(sonm,Ppgm,Pcmd);                       //~v77LR~
    rc=uproc_callxetool(sonm,Ppgm,Pcmd);                           //~v77LI~
    return rc;//~v77DI~
}                                                                  //~v77DI~
//*****************************************                        //~vc70I~
//*execute process                                                 //~vc70I~
//*****************************************                        //~vc70I~
int callXeToolSOProc(char *Ppgm,char *Pcmd)                        //~vc70I~
{                                                                  //~vc70I~
    char sonm[32];                                                 //~vc70I~
	int rc;                                                        //~vc70I~
//*************************                                        //~vc70I~
	UTRACEP("%s:pgm=%s,cmd=%s\n",UTT,Ppgm,Pcmd);                   //~vc70I~
  if (1)    //TODO test                                            //~vc70R~
    sprintf(sonm,"lib%s.so",Ppgm);     //errno=2                   //~vc70R~
  else                                                             //~vc70I~
    sprintf(sonm,"lib%s_so.so",Ppgm);                              //~vc70I~
	rc=uproc_callxetoolExec(sonm,Ppgm,Pcmd);                       //~vc70R~
    return rc;                                                     //~vc70I~
}                                                                  //~vc70I~
#endif                                                             //~vc70I~
////*********************************************************************//~v77DI~//~v77GR~
////*for exit() of xsub tool executed for >Android10(dlopen,dlsym,call)//~v77DI~//~v77GR~
////*redirect by #define on ulibarm.h                                //~v77DI~//~v77GR~
////*********************************************************************//~v77DI~//~v77GR~
//#ifdef XSUB                                                        //~v77DI~//~v77GR~
//#include <android/api-level.h>                                     //~v77DI~//~v77GR~
//void armXsubExit(int PexitCode)                                    //~v77DR~//~v77GR~
//{                                                                  //~v77DI~//~v77GR~
//    static int SexitCode;                                              //~v77DI~//~v77GR~
////**************                                                   //~v77DI~//~v77GR~
//#undef exit                                                        //~v77DI~//~v77GR~
//    int apilevel=android_get_device_api_level();                   //~v77DI~//~v77GR~
//    UTRACEP("%s:exitcode=%d,device_api_level=%d,&SexitCode=%p\n",UTT,PexitCode,apilevel,&SexitCode);//~v77DR~//~v77GR~
//    if (apilevel>=__ANDROID_API_Q__)    //android10(Q)=29          //~v77DI~//~v77GR~
//    {                                                              //~v77DI~//~v77GR~
//        UTRACEP("%s:pthread_exit\n",UTT);                          //~v77DI~//~v77GR~
//        SexitCode=PexitCode;                                       //~v77DR~//~v77GR~
//        pthread_exit(&SexitCode);                                  //~v77DR~//~v77GR~
//    }                                                              //~v77DI~//~v77GR~
//    else                                                           //~v77DI~//~v77GR~
//    {                                                              //~v77DI~//~v77GR~
//        UTRACEP("%s:exit\n",UTT);                                  //~v77DI~//~v77GR~
//        exit(PexitCode);                                           //~v77DI~//~v77GR~
//    }                                                              //~v77DI~//~v77GR~
//}                                                                  //~v77DI~//~v77GR~
//#endif //XSUB                                                      //~v77DI~//~v77GR~
//*********************************************************************//~v77DI~
//*rc=1:executed by dlopen for android10(Q)                        //~v77DI~
//*********************************************************************//~v77DI~
#ifdef ARMXXE                                                      //~v77DI~
//static char* SxeTools[]={"xbc","xci","xcv","xdc","xdd","xdig","xds","xfc","xff","xfg","xfmt","xfs","xlow","xmj","xpe","xts","xtestenv",0};//~v77DR~//~v77HR~
//static char* SxeTools[]={"highlight","xbc","xci","xcv","xdc","xdd","xdig","xds","xfc","xff","xfg","xfmt","xfs","xlow","xmj","xpe","xts","xtestenv",0};//~v77HI~//~v77KR~
static char* SxeTools[]={"highlight","xbc","xci","xcv","xdc","xdd","xdig","xds","xfc","xff","xfg","xfmt","xfs","xlow","xmj","xpe","xts","iconv","xtestenv",0};//~v77KR~
int isSupportedSO(char *Ppgm)                                      //~v77DI~
{                                                                  //~v77DI~
	int ii,rc=0;                                                   //~v77DI~
    char *tool;                                                    //~v77DI~
    for (ii=0;;ii++)                                               //~v77DI~
    {                                                              //~v77DI~
    	tool=SxeTools[ii];                                         //~v77DR~
        if (!tool)                                                 //~v77DI~
        	break;                                                 //~v77DI~
    	if (!strcmp(tool,Ppgm))                                    //~v77DI~
        {                                                          //~v77DI~
        	rc=1;                                                  //~v77DI~
        	break;                                                 //~v77DI~
        }                                                          //~v77DI~
    }                                                              //~v77DI~
	UTRACEP("%s:rc=%d,pgm=%s\n",UTT,rc,Ppgm);                      //~v77DI~
    return rc;                                                     //~v77DI~
}                                                                  //~v77DI~
//**********                                                       //~v77DI~
int systemArm(char *Pcmd,int *Pretval)                             //~v77DI~
{                                                                  //~v77DI~
	int len,rc;                                                    //~v77DI~
    char pgm[16],*pc;                                                  //~v77DI~
//**********                                                       //~v77DI~
	UTRACEP("%s:entry apilevel=%d,cmd=%s\n",UTT,GarmApiLevel,Pcmd);//~v77DI~
	if (GarmApiLevel<__ANDROID_API_Q__)	      //Q:10:api29         //~v77DI~
    {                                                              //~v77LI~
		UTRACEP("%s:return by low apilevel\n",UTT);                //~v77LI~
    	return 0;                                                  //~v77DI~
    }                                                              //~v77LI~
    pc=strchr(Pcmd,' ');                                           //~v77DI~
    if (pc)                                                        //~v77DI~
    	len=PTRDIFF(pc,Pcmd);                                      //~v77DI~
    else                                                           //~v77DI~
    	len=(int)strlen(Pcmd);                                     //~v77DI~
    if (len>(int)sizeof(pgm))                                      //~v77DI~
    	return 0;                                                  //~v77DI~
    UmemcpyZ(pgm,Pcmd,len);                                        //~v77DI~
    if (!isSupportedSO(pgm))                                       //~v77DI~
    	return 0;                                                  //~v77DI~
	rc=callXeToolSO(pgm,Pcmd);                                     //~v77DI~
	UTRACEP("%s:exit systemArm rc=%d\n",UTT,rc);               //~v77DI~//~v77LR~//~vc70R~
    *Pretval=rc;                                                   //~v77DR~
    return 1;                                                      //~v77DI~
}                                                                  //~v77DI~
//*****************************************************            //~vc70I~
// execute process of tool.so under apiLevel>=__ANDROID_API_Q__    //Q:10:api29//~vc70I~
//*****************************************************            //~vc70I~
int systemArmProc(char *Pcmd,int *Pretval)                         //~vc70I~
{                                                                  //~vc70I~
	int len,rc;                                                    //~vc70I~
    char pgm[16],*pc;                                              //~vc70I~
//**********                                                       //~vc70I~
	UTRACEP("%s:entry apilevel=%d,cmd=%s\n",UTT,GarmApiLevel,Pcmd);//~vc70I~
    pc=strchr(Pcmd,' ');                                           //~vc70I~
    if (pc)                                                        //~vc70I~
    	len=PTRDIFF(pc,Pcmd);                                      //~vc70I~
    else                                                           //~vc70I~
    	len=(int)strlen(Pcmd);                                     //~vc70I~
    if (len>(int)sizeof(pgm))                                      //~vc70I~
    	return 0;                                                  //~vc70I~
    UmemcpyZ(pgm,Pcmd,len);                                        //~vc70I~
    if (!isSupportedSO(pgm))                                       //~vc70I~
    	return 0;                                                  //~vc70I~
	rc=callXeToolSOProc(pgm,Pcmd);                                 //~vc70I~
	UTRACEP("%s:exit systemArmProc rc=%d\n",UTT,rc);               //~vc70I~
    *Pretval=rc;                                                   //~vc70I~
    return 1;                                                      //~vc70I~
}                                                                  //~vc70I~
#endif	//ARMXXE                                                   //~v77DI~
#endif //ARM                                                            //~v77CR~//~v77DR~
