//*CID://+v6XaR~:                             update#=  425;       //+v6XaR~
//************************************************************* //~5825I~
//*uproc2.c                                                        //~v5euR~
//* parse-redirect,rsh                                             //~v5euR~
//*************************************************************    //~v022I~
//v6Xa:180821 enumproc show fullpath(xp was shoing)                //~v6XaI~
//v6X6:180819 (W32)enumproc optionally output fullpath exe name    //~v6X6I~
//v6N0:171114 (Bug)ugetprocessuid have to chk handle=-1 to avoid read wait if xesyscmd was spawned//~v6N0I~
//v6L5:170715 msvs2017 warning;(Windows:PTR:64bit,ULONG 32bit,HWND:64bit)//~v6L5I~
//v6xr:150118 (BUG of v6xm) 6xm is for W7 only;back to old logic when XP//~v6xrI~
//v6xq:150116 add uapierr1nt                                       //~v6xqI~
//v6xp:150116 (BUG:LNX)kill parm is not thread_t but pid_t         //~v6xpI~
//v6xn:150116 (BUG:W64)ugetpidfromhandle() fails on Windows7.use GetProcessId()//~v6xnI~
//v6xm:150116 (BUG:W64)if SHCMDR(xeshm resident) is on xesynw.cfg, crash at uenumpid() to set pid to parm.//~v6xmI~
//            pid position was changed by v5nd. (xkp set to parm[0])//~v6xmI~
//            But why OK at XP, because OSVERSIONINFO returns platformid=1(<Windows98) on Windows7.//~v6xmI~
//v6xj:150115 (BUG:W64)uintptr_t is 8byte                          //~v6xjI~
//v6xi:150115 conversion warning                                   //~v6xiI~
//v6j0:121102 for xcifb; -DNOCURSES -DXSUB                         //~v6j0I~
//v6hj:120628 PSAPI.DLL is missing EnumProcess was changed to use kernel:K32EnumProcess//~v6hjI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6a0:110520 Android porting(-DARM)                               //~v6a0I~
//v690:100701 m62(LP64:: int:32, long,void*:64) support (__LP64_)  //~v690I~
//v5nc:081009 (LNX)MinGW compile                                   //~v5ncI~
//v5kv:070709 for xkp to display parent pid                        //~v5kvI~
//v5kb:070518 split uproc2.c to uproc22.c for link trouble in LNX(pthread)(move v5iv & v5ja to uproc22)//~v5kbI~
//v5ja:060921 (LNX)3270 support                                    //~v5jaI~
//v5iv:060906 3270server support(2nd cmdserver)                    //~v5ivI~
//v5it:060826 gcc:submit abend by bat file is not .bat by getpid is not done(gcc support getpid)//~v5itI~
//v5is:060826 stdin support for uprocparseredirect                 //~v5isI~
//v5g1:050428 ugetpid function add                                 //~v5g1I~
//v5ew:041031 rsh chmod:cmd string log to ftplog                   //~v5ewI~
//v5ev:041031 ftp chmod:try rsh after setmod failed                //~v5evI~
//v5eu:041031 rsh support                                          //~v5euI~
//v5eb:041011 uproc2:parseredirect function for xedcmd             //~v5ebI~
//************************************************************* //~5825I~
#include <time.h>                                               //~5825I~
#include <stdio.h>                                              //~5825I~
#include <stdlib.h>                                             //~5825I~
#include <string.h>                                             //~5825I~
#include <stdarg.h>                                             //~5A10I~
#include <errno.h>                                              //~5A10I~
#include <fcntl.h>                                                 //~v59jI~
#ifdef UNX                                                         //~v5ewI~
	#include <unistd.h>                                            //~v5ewI~
    #ifdef LNX                                                     //~v5jaI~
		#include <pthread.h>                                       //~v5jaI~
		#include <signal.h>                                        //~v5jaI~
    #endif                                                         //~v5jaI~
#else                                                              //~v5g1I~
    #ifdef DPMI                                                    //~v5itR~
		#include <unistd.h>                                        //~v5itI~
    #endif                                                         //~v5itI~
	#include <process.h>                                           //~v5g1I~
#endif                                                             //~v5ewR~
#ifdef W32                                                         //~v5ivI~
	#include <windows.h>                                           //~v5ivI~
    #include <tlhelp32.h>	//enumproc                             //~v5ivI~
  #ifndef MGW32                                                    //~v5ncI~
    #include <vdmdbg.h>     //enumproc                             //~v5ivI~
  #endif                                                           //~v5ncI~
#endif                                                             //~v5ivI~
                                                                   //~v022I~
#include <ulib.h>                                               //~5825I~
#include <uque.h>                                                  //~v5euI~
#include <uerr.h>                                               //~5A10I~
#include <uproc.h>                                              //~5A10I~
#include <uproc2.h>                                                //~v5ebI~
#include <uparse.h>                                                //~v5ebI~
#include <ualloc.h>                                                //~v5ebI~
#include <ufile.h>                                                 //~v5euI~
#include <ufile2.h>                                                //~v5euI~
#include <ufile4.h>                                                //~v5euI~
#include <uftp.h>                                                  //~v5euI~
#include <ufemsg.h>                                                //~v5euI~
#include <utrace.h>                                                //~v6xmI~
//*********************************************                    //~v064R~
//*********************************************                    //~v064R~
#ifdef LNX                                                         //~v5jaM~
  #ifndef NOMT                                                     //~v6a0I~
    typedef struct _UEVENTLIST {                                   //~v5jaI~
                int               UECBLecbcount;     //ecblist ecb count//~v5jaI~
                int               UECBLpostcount;    //count of waiting ecb//~v5jaR~
                PUEVENTCB        *UECBLpcopyecblist; //ECB pointer array//~v5jaR~
                        } UEVENTLIST,*PUEVENTLIST;                 //~v5jaI~
    #define UEVENTLISTSZ sizeof(UEVENTLIST)                        //~v5jaI~
  #endif                                                           //~v6a0I~
#endif                                                             //~v5jaM~
//**************************************************************** //~v50HI~
#ifdef LNX                                                         //~v5jaI~
  #ifndef NOMT                                                     //~v6a0I~
	#define	UEVENT_LOCK()    if (rc=ucriticalsection(CRITSEC_ENTER,(ULONG)&Sueventmutex),rc) \
    								return UEVENTRC_ERR|rc         //~v5jaI~
	#define	UEVENT_UNLOCK()  ucriticalsection(CRITSEC_LEAVE,(ULONG)&Sueventmutex)//~v5jaR~
    int uevent_setuplist(PUEVENTCB Pplistecb);                     //~v5jaR~
    int uevent_resetlist(PUEVENTCB Pplistecb);                     //~v5jaI~
    int uevent_postm(PUEVENTCB Ppecb);                             //~v5jaI~
    int uevent_waitm(int Popt,int Peventcnt,PUEVENTCB *Pppecb,struct timespec *Pptimeout,int *Ppindex);//~v5jaR~
    int uevent_post1(int Plockedsw,PUEVENTCB Ppecb);               //~v5jaI~
    int uevent_wait1(int Plockedsw,PUEVENTCB Ppecb,struct timespec *Ptimespec);//~v5jaI~
    int uevent_reset1(PUEVENTCB Ppecb);                            //~v5jaR~
  #endif                                                           //~v6a0I~
#endif                                                             //~v5jaI~
//***************************************************** ********** //~v5jaI~
#ifdef LNX                                                         //~v5jaI~
  #ifndef NOMT                                                     //~v6j0I~
	static pthread_mutex_t Sueventmutex=PTHREAD_MUTEX_INITIALIZER; //~v5jaI~
  #endif                                                           //~v6j0I~
#endif                                                             //~v5jaI~
#ifdef W32                                                         //~v5ivI~
//**************************************************************** //~v5ivI~
//* process active chk                                             //~v5ivI~
//* parameter:handle returned by spawn                             //~v5ivI~
//*rc 0:active 1:end 2:invalid handle(may ended) 4:other err       //~v5ivR~
//**************************************************************** //~v5ivI~
int getprocstatus(ULONG Phandle)                                   //~v5ivI~
{                                                                  //~v5ivI~
//  ULONG ecblist[1];                                              //~v5ivI~//~v6hhR~
    ULPTR ecblist[1];                                              //~v6hhI~
    int rc;                                                        //~v5ivI~
//*************************                                        //~v5ivI~
	ecblist[0]=Phandle;                                            //~v5ivI~
	rc=uevent(UEVENTO_WAIT,1,ecblist,0,0);	//timeout=0,return idx=0//~v5ivI~
    if (rc==UEVENTRC_TIMEOUT)                                      //~v5ivI~
        rc=0;                                                      //~v5ivR~
    else                                                           //~v5ivI~
    if (rc==UEVENTRC_POSTED)    //exit                             //~v5ivI~
        rc=1;                                                      //~v5ivR~
    else                                                           //~v5ivI~
    if (rc==ERROR_INVALID_HANDLE)                                  //~v5ivI~
        rc=2;                                                      //~v5ivI~
    else                                                           //~v5ivI~
        rc=4;                                                      //~v5ivI~
    return rc;                                                     //~v5ivI~
}//getprocstatus                                                   //~v5ivI~
#endif                                                             //~v5ivI~
#ifdef LNX                                                         //~v5jaI~
//**************************************************************** //~v5jaI~
//*kill process by pid (LNX)                                       //~v5jaI~
//*rc 4:no process,0:done,1:fail                                   //~v5jaI~
//**************************************************************** //~v5jaI~
//int ukillpid(void *Pppid,int Psignal)                              //~v5jaI~//~v6xpR~
int ukillpid(ULONG *Pppid,int Psignal)                             //~v6xpI~
{                                                                  //~v5jaI~
//  pthread_t pid;                                                 //~v5jaI~//~v6xpR~
    pid_t     pid;                                                 //~v6xpI~
    int sig,rc;                                                    //~v5jaR~
//*************************                                        //~v5jaI~
	if (!(sig=Psignal))                                            //~v5jaI~
    	sig=SIGKILL;                                               //~v5jaI~
//  pid=*(pthread_t*)(ULONG)Pppid;                                 //~v5jaI~//~v6xpR~
    pid=(pid_t)*Pppid;                                             //~v6xpR~
    if ((rc=kill(pid,sig)))                                        //~v5jaI~
    {                                                              //~v5jaI~
    	rc=errno;                                                  //~v5jaI~
//  	uerrapi0("kill",rc);                                       //~v5jaI~//~v6xqR~
    	uerrapi1nt(0/*GetLastError*/,"kill",(ULONG)pid,"pid=0x%lx",rc);//~v6xqR~
    }                                                              //~v5jaI~
    return rc;                                                     //~v5jaI~
}//ukillpid                                                        //~v5jaI~
#endif                                                             //~v5jaI~
#ifdef W32                                                         //~v5ivI~
//**************************************************************** //~v5ivM~
//*kill process by hProcess(retuned by spawn)                      //~v5ivI~
//*rc 0:done,else getlasterr                                       //~v5ivR~
//**************************************************************** //~v5ivM~
//int ukillph(ULONG Ppid,int Pexitcode)                              //~v5ivM~//~v6hhR~
int ukillph(ULPTR Ppid,int Pexitcode)                              //~v6hhI~
{                                                                  //~v5ivM~
    int rc;                                                        //~v5ivM~
//*************************                                        //~v5ivM~
    rc=TerminateProcess((HANDLE)Ppid,Pexitcode)==0;		//rc:TRUE/FALSE//~v5ivM~
    if (rc)                                                        //~v5ivI~
        rc=GetLastError();                                         //~v5ivI~
    return rc;                                                     //~v5ivM~
}//ukillph                                                         //~v5ivM~
//**************************************************************** //~v5ivM~
//*kill process by pid if you know                                 //~v5ivI~
//*rc 4:no process,0:done,1:fail                                   //~v5ivM~
//**************************************************************** //~v5ivM~
//int ukillpid(ULONG Ppid,int Pexitcode)                           //~v5jaR~
//int ukillpid(void *Ppid,int Pexitcode)                             //~v5jaI~//~v6xpR~
int ukillpid(ULONG *Ppid,int Pexitcode)                            //~v6xpI~
{                                                                  //~v5ivM~
    HANDLE  hProcess ;                                             //~v5ivM~
    int rc;                                                        //~v5ivM~
    ULONG pid;                                                     //~v5jaI~
//*************************                                        //~v5ivM~
//	pid=*(ULONG*)(ULONG)Ppid;                                      //~v5jaI~//~v6hhR~
//  pid=*(ULONG*)(ULPTR)Ppid;                                      //~v6hhI~//~v6xpR~
    pid=*Ppid;                                                     //~v6xpI~
    hProcess=OpenProcess(PROCESS_TERMINATE, //access flag:to enable terminateprocess by this handle//~v5ivM~
               			FALSE,  			//inherit              //~v5ivM~
//  					Ppid );				//process id           //~v5jaR~
    					pid);				//process id           //~v5jaI~
    if (hProcess!=NULL)                                            //~v5ivM~
//    	rc=ukillph((ULONG)hProcess,Pexitcode);                     //~v5ivR~//~v6hhR~
    	rc=ukillph((ULPTR)hProcess,Pexitcode);                     //~v6hhI~
    else                                                           //~v5ivM~
    	rc=GetLastError();                                         //~v5ivR~
    return rc;                                                     //~v5ivM~
}//ukillpid                                                        //~v5ivM~
//*************************************************************    //~v5ivM~
//*get pid from hProcess(Windows spawn returns hProcess)           //~v5ivI~
//*************************************************************    //~v5ivI~
//ULONG ugetpidfromhandle(ULONG Php)                                 //~v5ivI~//~v6hhR~
ULONG ugetpidfromhandle(ULPTR Php)                                 //~v6hhI~
{                                                                  //~v5ivM~
    HANDLE  ht;                                                    //~v5ivI~
    ULONG   pid;                                                   //~v5ivI~
    FARPROC pfunc;                                                 //~v5ivI~
//********************************                                 //~v5ivI~
    pid=(ULONG)ugetprocessid(0/*no rrmsg*/,Php);                   //~v6xnR~
	UTRACEP("ugetpidfromhandle handle=%p,GetProcessId==%p,err=%d\n",Php,pid,GetLastError());//~v6xnI~
    if ((int)pid>0)                                                //~v6xnI~
    	return pid;                                                //~v6xnI~
    pfunc=GetProcAddress(GetModuleHandle("Kernel32.dll"),"GetCurrentProcessId");//~v5ivI~
//execute GetCurrentProcessId at the process's thread              //~v5ivI~
    ht=CreateRemoteThread((HANDLE)Php,                             //~v5ivR~
                          NULL,	//security,inherit etc             //~v5ivI~
                          0,    //stack size                       //~v5ivI~
                          (LPTHREAD_START_ROUTINE)pfunc,           //~v5ivI~
                          NULL, //param                            //~v5ivI~
                          0,    //flag, suspend etc                //~v5ivI~
                          NULL);//output threadid                  //~v5ivI~
	UTRACEP("ugetpidfromhandle CreateRemotHandle ht=%xp func=%p,err=%d\n",ht,pfunc,GetLastError());//~v6xmR~
    if (!ht)                                                       //~v5ivI~
    {                                                              //~v6xmI~
        pid=0;                                                     //~v5ivI~
    }                                                              //~v6xmI~
    else                                                           //~v5ivM~
    {                                                              //~v5ivM~
        DWORD rc;                                                  //~v6xmI~
        rc=                                                        //~v6xmI~
        WaitForSingleObject(ht,INFINITE);                          //~v5ivI~
		UTRACEP("ugetpidfromhandle WaitForSingleObject rc=%d,err=%d\n",rc,GetLastError());//~v6xmI~
        rc=                                                        //~v6xmI~
        GetExitCodeThread(ht,&pid);	//GetCurrentProcessId's rc     //~v5ivI~
		UTRACEP("ugetpidfromhandle GetExitCodeThread rc=%d,err=%d\n",rc,GetLastError());//~v6xmI~
        CloseHandle(ht);                                           //~v5ivI~
		UTRACEP("ugetpidfromhandle CreateRemotHandle success pid=%d(x%x)\n",pid,pid);//~v6xmI~
	}                                                              //~v5ivI~
   	return pid;                                                    //~v5ivI~
}//ugetpidfromhandle                                               //~v5ivI~
#ifdef _MT  //by multithread compile option option of /MT or /MTd  //~v5ivI~
//**************************************************************** //~v5ivM~
//*create thread                                                   //~v5ivM~
//**************************************************************** //~v5ivM~
//ULONG uthread(int Popt,UTHFUNC Pfunc,int Pstacksz,ULONG Pparm,ULONG *Ppthid)//~v5ivM~//~v6hhR~
//ULONG uthread(int Popt,UTHFUNC Pfunc,int Pstacksz,ULPTR Pparm,ULONG *Ppthid)//~v6xjR~
ULPTR uthread(int Popt,UTHFUNC Pfunc,int Pstacksz,ULPTR Pparm,ULONG *Ppthid)//~v6xjI~
{                                                                  //~v5ivM~
//  struct SECURITY_ATTRIBUTE seca={sizeof(SECURITY_ATTRIBUTE),NULL,TRUE};	//true:inherit handle//~v5ivM~
//  struct SECURITY_ATTRIBUTE *pseca=0;                            //~v5ivM~
//  ULONG th;                                                      //~v6xjR~
    ULPTR th;                                                      //~v6xjI~
//  int opt=0;                                                     //~v5ivM~
//  ULONG thid;                                                    //~v5ivM~
//***************                                                  //~v5ivM~
//  if (Popt & UTHO_SUSPEND)                                       //~v5ivM~
//  	opt=CREATE_SUSPENDED;                                      //~v5ivM~
//  if (Popt & UTHO_INHERIT)                                       //~v5ivM~
//  	pseca=&seca;                                               //~v5ivM~
//	th=CreateThread(pseca,                                         //~v5ivM~
//					Pstacksz,	//if 0:default size;stack may expand if requiresd//~v5ivM~
//        	     	Pfunc,                                         //~v5ivM~
//					Pparm,                                         //~v5ivM~
//                  opt,                                           //~v5ivM~
//					&thid);                                        //~v5ivM~
	th=_beginthread(Pfunc,                                         //~v5ivM~
					Pstacksz,	//if 0:default size;stack may expand if requiresd//~v5ivM~
                    (void*)Pparm);                                 //~v5ivM~
//  if (Ppthid)                                                    //~v5ivM~
//  	*Ppthid=thid;                                              //~v5ivM~
//  if (!th)                                                       //~v5ivM~
//  	apierr("CreateThread",GetLastError());                     //~v5ivM~
    if (th==-1)                                                    //~v5ivM~
    {                                                              //~v5ivM~
    	uerrapi0("_beginthread",errno); 	//1:errno print        //~v5ivR~
        th=0;                                                      //~v5ivM~
    }                                                              //~v5ivM~
	return th;                                                     //~v5ivM~
}//uthread                                                         //~v5ivM~
#endif //_MT  //by multithread compile option option of /MT or /MTd//~v5ivI~
//**************************************************************** //~v5ivM~
//*uselect init/wait                                               //~v5ivM~
//time parameter unit is milisec                                   //~v5ivM~
//rc for wait:1:timeout,2:abandoned                                //~v5ivM~
//**************************************************************** //~v5ivM~
//int uevent(int Popt,int Peventcnt,ULONG *Peventcb,int Ptimeout,int *Ppindex)//~v5ivM~//~v6hhR~
int uevent(int Popt,int Peventcnt,ULPTR *Peventcb,int Ptimeout,int *Ppindex)//~v6hhI~
{                                                                  //~v5ivM~
	HANDLE eh;                                                     //~v5ivM~
    int optall,waittime,ii,eventidx;                               //~v5ivM~
    char wk[32];                                                   //~v5ivI~
    int initsig,manreset;                                          //~v5ivI~
//***************                                                  //~v5ivM~
	if (Popt & UEVENTO_INIT)	//fill eventcb                     //~v5ivM~
    {                                                              //~v5ivM~
    	for (ii=0;ii<Peventcnt;ii++)                               //~v5ivM~
        {                                                          //~v5ivM~
			manreset=(Popt & UEVENTO_MANUALRESET)!=0;	//manual resetfill eventcb//~v5ivI~
			initsig =(Popt & UEVENTO_INITSIGNAL)!=0;	//fill eventcb//~v5ivI~
        	eh=CreateEvent(NULL,		//no inherit               //~v5ivM~
							manreset,		//auto reset(reset if posted)//~v5ivR~
							initsig,		//initial status:reset //~v5ivR~
							NULL);      //event name               //~v5ivM~
            if (!eh)                                               //~v5ivM~
            	return	uerrapi0("CreateEvent",GetLastError());    //~v5ivR~
//        	Peventcb[ii]=(ULONG)eh;                                //~v5ivM~//~v6hhR~
         	Peventcb[ii]=(ULPTR)eh;                                //~v6hhI~
        }                                                          //~v5ivM~
        return 0;                                                  //~v5ivM~
    }                                                              //~v5ivM~
	if (Popt & (UEVENTO_WAIT|UEVENTO_WAITALL))	//wait event       //~v5ivM~
    {                                                              //~v5ivM~
		if (Popt & UEVENTO_WAITALL)	//wait all ecb posted          //~v5ivM~
        	optall=TRUE;                                           //~v5ivM~
        else                                                       //~v5ivM~
        	optall=FALSE;                                          //~v5ivM~
        waittime=Ptimeout;                                         //~v5ivM~
        if (waittime<0)                                            //~v5ivM~
        	waittime=INFINITE;                                     //~v5ivM~
//     	eventidx=WaitForMultipleObjects(Peventcnt,(void**)(ULONG)Peventcb,optall,waittime);//~v5ivM~//~v6hhR~
     	eventidx=WaitForMultipleObjects(Peventcnt,(void**)(ULPTR)Peventcb,optall,waittime);//~v6hhI~
        if (eventidx==WAIT_FAILED)                                 //~v5ivM~
        {                                                          //~v5ivI~
//          sprintf(wk,"1st handle=0x%x",*Peventcb);               //~v5ivI~//~v6L5R~
            sprintf(wk,"1st handle=0x%" FMT_PTR("x"),*Peventcb);   //~v6L5R~
        	return	uerrapi1("WaitMultipleObjects",wk,GetLastError());//~v5ivR~
        }                                                          //~v5ivI~
        if (eventidx==WAIT_TIMEOUT)                                //~v5ivM~
            return UEVENTRC_TIMEOUT;                               //~v5ivM~
        if (eventidx>=WAIT_ABANDONED_0)                            //~v5ivM~
        {                                                          //~v5ivM~
        	if (Ppindex)                                           //~v5ivM~
        		*Ppindex=eventidx-WAIT_ABANDONED_0;	//abandned index//~v5ivM~
	        return UEVENTRC_ABANDONED;                             //~v5ivM~
        }                                                          //~v5ivM~
        if (eventidx>=WAIT_OBJECT_0)                               //~v5ivM~
        {                                                          //~v5ivM~
        	if (Ppindex)		//if waitall no index required     //~v5ivM~
        		*Ppindex=eventidx-WAIT_OBJECT_0;                   //~v5ivM~
	        return UEVENTRC_POSTED;                                //~v5ivM~
    	}                                                          //~v5ivM~
        return -1;                                                 //~v5ivR~
    }                                                              //~v5ivM~
	if (Popt & UEVENTO_POST)	//signal raise                     //~v5ivM~
    {                                                              //~v5ivM~
//     	if (!SetEvent((HANDLE)(ULONG)*Peventcb))                   //~v5ivM~//~v6hhR~
     	if (!SetEvent((HANDLE)(ULPTR)*Peventcb))                   //~v6hhI~
        {                                                          //~v5ivI~
//          sprintf(wk,"handle=0x%x",*Peventcb);                   //~v5ivI~//~v6L5R~
            sprintf(wk,"handle=0x%" FMT_PTR("x"),*Peventcb);       //~v6L5R~
        	return uerrapi1("SetEvent",wk,GetLastError());         //~v5ivR~
        }                                                          //~v5ivI~
        return 0;                                                  //~v5ivM~
    }                                                              //~v5ivM~
	if (Popt & UEVENTO_RESET)   //signal raise                     //~v5ivI~
    {                                                              //~v5ivI~
//     	if (!ResetEvent((HANDLE)(ULONG)*Peventcb))                 //~v5ivI~//~v6hhR~
     	if (!ResetEvent((HANDLE)(ULPTR)*Peventcb))                 //~v6hhI~
        {                                                          //~v5ivI~
//          sprintf(wk,"handle=0x%x",*Peventcb);                   //~v5ivI~//~v6L5R~
            sprintf(wk,"handle=0x%" FMT_PTR("x"),*Peventcb);       //~v6L5R~
        	return uerrapi1("ResetEvent",wk,GetLastError());       //~v5ivR~
        }                                                          //~v5ivI~
        return 0;                                                  //~v5ivI~
    }                                                              //~v5ivI~
    return -1;                                                     //~v5ivR~
}//uevent                                                          //~v5ivM~
//**************************************************************** //~v5ivM~
//*uselect init/wait                                               //~v5ivM~
//rc for wait:1:timeout,2:abandoned                                //~v5ivM~
//**************************************************************** //~v5ivM~
//void ucriticalsection(int Popc,ULONG Ppsem)                      //~v5jaR~
//int ucriticalsection(int Popc,ULONG Ppsem)                         //~v5jaI~//~v6hhR~
int ucriticalsection(int Popc,ULPTR Ppsem)                         //~v6hhI~
{                                                                  //~v5ivM~
	CRITICAL_SECTION *psem;                                        //~v5ivM~
//***************                                                  //~v5ivM~
	psem=(CRITICAL_SECTION *)Ppsem;                                //~v5ivM~
    switch (Popc)                                                  //~v5ivM~
    {                                                              //~v5ivM~
	case CRITSEC_INIT:                                             //~v5ivM~
		InitializeCriticalSection(psem);                           //~v5ivM~
        break;                                                     //~v5ivM~
	case CRITSEC_ENTER:                                            //~v5ivM~
		EnterCriticalSection(psem);                                //~v5ivM~
        break;                                                     //~v5ivM~
	case CRITSEC_LEAVE:                                            //~v5ivM~
	   	LeaveCriticalSection(psem);                                //~v5ivM~
        break;                                                     //~v5ivM~
	case CRITSEC_DELETE:                                           //~v5ivM~
   		DeleteCriticalSection(psem);                               //~v5ivM~
        break;                                                     //~v5ivM~
    }                                                              //~v5ivM~
//  return;                                                        //~v5jaR~
    return 0;                                                      //~v5jaI~
}//ucriticalsection                                                //~v5ivM~
#ifndef MGW32                                                      //~v5ncI~
//**************************************************************** //~v5ivI~
//*pid enum thrue callback func (logic from web)                   //~v5ivI~
//**************************************************************** //~v5ivI~
typedef struct                                                     //~v5ivI~
{                                                                  //~v5ivI~
      DWORD          dwPID ;                                       //~v5ivI~
      CB_ENUMPID    *cbfunc ;                                      //~v5ivR~
      void          *lParam ;                                      //~v5ivR~
      BOOL           bEnd ;                                        //~v5ivI~
} EnumInfoStruct ;                                                 //~v5ivI~
//**************************************************************** //~v5ivI~
//BOOL uenumpid(CB_ENUMPID Pcbfunc,void *Pparm)                    //~v5kvR~
BOOL uenumpid(int Popt,CB_ENUMPID Pcbfunc,void *Pparm)             //~v5kvI~
{                                                                  //~v5ivI~
	  BOOL WINAPI Enum16( DWORD dwThreadId, WORD hMod16, WORD hTask16,//~v5ivI~
    		  PSZ pszModName, PSZ pszFileName, LPARAM lpUserDefined ) ;//~v5ivI~
      OSVERSIONINFO  osver ;                                       //~v5ivI~
      HINSTANCE      hInstLib ;                                    //~v5ivI~
      HINSTANCE      hInstLib2 ;                                   //~v5ivI~
      HANDLE         hSnapShot ;                                   //~v5ivI~
      PROCESSENTRY32 procentry ;                                   //~v5ivI~
      BOOL           bFlag ;                                       //~v5ivI~
      LPDWORD        lpdwPIDs ;                                    //~v5ivI~
      DWORD          dwSize, dwSize2, dwIndex ;                    //~v5ivI~
      HMODULE        hMod ;                                        //~v5ivI~
      HANDLE         hProcess ;                                    //~v5ivI~
      char           szFileName[ MAX_PATH ] ;                      //~v5ivI~
      EnumInfoStruct sInfo ;                                       //~v5ivI~
      // ToolHelp func ptr                                         //~v5ivI~
      HANDLE (WINAPI *lpfCreateToolhelp32Snapshot)(DWORD,DWORD) ;  //~v5ivI~
      BOOL (WINAPI *lpfProcess32First)(HANDLE,LPPROCESSENTRY32) ;  //~v5ivI~
      BOOL (WINAPI *lpfProcess32Next)(HANDLE,LPPROCESSENTRY32) ;   //~v5ivI~
                                                                   //~v5ivI~
      // PSAPI func ptr                                            //~v5ivI~
      BOOL (WINAPI *lpfEnumProcesses)( DWORD *, DWORD cb, DWORD * );//~v5ivI~
      BOOL (WINAPI *lpfEnumProcessModules)( HANDLE, HMODULE *,DWORD,LPDWORD);//~v5ivI~
      DWORD (WINAPI *lpfGetModuleFileNameEx)(HANDLE,HMODULE,LPTSTR,DWORD );//~v5ivI~
                                                                   //~v5ivI~
      // VDMDBG func ptr                                           //~v5ivI~
      INT (WINAPI *lpfVDMEnumTaskWOWEx)( DWORD,TASKENUMPROCEX  fp, LPARAM );//~v5ivI~
      int *pparentpid;                                             //~v5kvI~
      int sww7;                                                    //~v6hjI~
      int cbopt=0;                                                 //~v6xrI~
//    DWORD cpid;                                                  //~v6xmR~
      DWORD cpid;                                                  //~v6X6R~
      int swokPSAPI=0;                                             //~v6X6I~
//********************************                                 //~v5ivI~
      //Windows 95 or Windows NT?                                  //~v5ivI~
      osver.dwOSVersionInfoSize = sizeof( osver ) ;                //~v5ivI~
      if( !GetVersionEx( &osver ) )                                //~v5ivI~
      {                                                            //~v5ivI~
         return FALSE ;                                            //~v5ivI~
      }                                                            //~v5ivI~
      sww7=((osver.dwMajorVersion<<8)|osver.dwMinorVersion)>=0x601;//~v6hjR~
	  if (Popt & UEPI_HELPER)	                                   //~v5kvR~
	      osver.dwPlatformId=VER_PLATFORM_WIN32_WINDOWS;	//force to use helperfunc to get parent pid//~v5kvI~
      else                                                         //~v6hjI~
      if (sww7)                                                    //~v6hjI~
	      osver.dwPlatformId=VER_PLATFORM_WIN32_WINDOWS;	//user kernel enum func//~v6hjI~
//    cpid=ugetpid();                                              //~v6xmR~
      if( osver.dwPlatformId == VER_PLATFORM_WIN32_NT ) //Windows NT//~v5ivI~
      {                                                            //~v5ivI~
         hInstLib = LoadLibraryA( "PSAPI.DLL" ) ;                  //~v5ivI~
         if( hInstLib == NULL )                                    //~v5ivI~
         {                                                         //~v6hjI~
            uerrmsg("uenumpid:PSAPI.DLL is missing",0);            //~v6hjI~
            return FALSE ;                                         //~v5ivI~
         }                                                         //~v6hjI~
                                                                   //~v5ivI~
         hInstLib2 = LoadLibraryA( "VDMDBG.DLL" ) ;                //~v5ivI~
         if( hInstLib2 == NULL )                                   //~v5ivI~
         {                                                         //~v6hjI~
            uerrmsg("uenumpid:VDMDBG.DLL is missing",0);           //~v6hjI~
            return FALSE ;                                         //~v5ivI~
         }                                                         //~v6hjI~
                                                                   //~v5ivI~
         lpfEnumProcesses = (BOOL(WINAPI *)(DWORD *,DWORD,DWORD*)) //~v5ivI~
            GetProcAddress( hInstLib, "EnumProcesses" ) ;          //~v5ivI~
         lpfEnumProcessModules = (BOOL(WINAPI *)(HANDLE, HMODULE *,//~v5ivI~
            DWORD, LPDWORD)) GetProcAddress( hInstLib,             //~v5ivI~
            "EnumProcessModules" ) ;                               //~v5ivI~
         lpfGetModuleFileNameEx =(DWORD (WINAPI *)(HANDLE, HMODULE,//~v5ivI~
            LPTSTR, DWORD )) GetProcAddress( hInstLib,             //~v5ivI~
            "GetModuleFileNameExA" ) ;                             //~v5ivI~
         lpfVDMEnumTaskWOWEx =(INT(WINAPI *)( DWORD, TASKENUMPROCEX,//~v5ivI~
            LPARAM))GetProcAddress( hInstLib2, "VDMEnumTaskWOWEx" );//~v5ivI~
         if( lpfEnumProcesses == NULL ||                           //~v5ivI~
            lpfEnumProcessModules == NULL ||                       //~v5ivI~
            lpfGetModuleFileNameEx == NULL ||                      //~v5ivI~
            lpfVDMEnumTaskWOWEx == NULL)                           //~v5ivI~
            {                                                      //~v5ivI~
               FreeLibrary( hInstLib ) ;                           //~v5ivI~
               FreeLibrary( hInstLib2 ) ;                          //~v5ivI~
               return FALSE ;                                      //~v5ivI~
            }                                                      //~v5ivI~
                                                                   //~v5ivI~
         // call EnumProcesses func of PSAPI to get all ProcID     //~v5ivI~
         // CbNeeded is set PID count                              //~v5ivI~
         dwSize2 = 256 * sizeof( DWORD ) ;                         //~v5ivI~
         lpdwPIDs = NULL ;                                         //~v5ivI~
         do                                                        //~v5ivI~
         {                                                         //~v5ivI~
            if( lpdwPIDs )                                         //~v5ivI~
            {                                                      //~v5ivI~
               HeapFree( GetProcessHeap(), 0, lpdwPIDs ) ;         //~v5ivI~
               dwSize2 *= 2 ;                                      //~v5ivI~
            }                                                      //~v5ivI~
            lpdwPIDs = HeapAlloc( GetProcessHeap(), 0, dwSize2 );  //~v5ivI~
            if( lpdwPIDs == NULL )                                 //~v5ivI~
            {                                                      //~v5ivI~
               FreeLibrary( hInstLib ) ;                           //~v5ivI~
               FreeLibrary( hInstLib2 ) ;                          //~v5ivI~
               return FALSE ;                                      //~v5ivI~
            }                                                      //~v5ivI~
            if( !lpfEnumProcesses( lpdwPIDs, dwSize2, &dwSize ) )  //~v5ivI~
            {                                                      //~v5ivI~
               HeapFree( GetProcessHeap(), 0, lpdwPIDs ) ;         //~v5ivI~
               FreeLibrary( hInstLib ) ;                           //~v5ivI~
               FreeLibrary( hInstLib2 ) ;                          //~v5ivI~
               return FALSE ;                                      //~v5ivI~
            }                                                      //~v5ivI~
         }while( dwSize == dwSize2 ) ;                             //~v5ivI~
                                                                   //~v5ivI~
         dwSize /= sizeof( DWORD ) ;   //count of PID              //~v5ivI~
                                                                   //~v5ivI~
         for( dwIndex = 0 ; dwIndex < dwSize ; dwIndex++ )         //~v5ivI~
         {                                                         //~v5ivI~
            szFileName[0] = 0 ;                                    //~v5ivI~
            hProcess = OpenProcess(                                //~v5ivI~
               PROCESS_QUERY_INFORMATION | PROCESS_VM_READ,        //~v5ivI~
               FALSE, lpdwPIDs[ dwIndex ] ) ;                      //~v5ivI~
            if( hProcess != NULL )                                 //~v5ivI~
            {                                                      //~v5ivI~
               //read 1st module of process by EnumProcessModules  //~v5ivI~
               if( lpfEnumProcessModules( hProcess, &hMod, sizeof( hMod ), &dwSize2 ) )//~v5ivI~
               {                                                   //~v5ivI~
                  if( !lpfGetModuleFileNameEx( hProcess, hMod, szFileName, sizeof( szFileName ) ) )	//get fullpath//~v5ivI~
               	  {                                                //~v5ivI~
                     szFileName[0] = 0 ;                           //~v5ivI~
                  }                                                //~v5ivI~
               }                                                   //~v5ivI~
               CloseHandle( hProcess ) ;                           //~v5ivI~
            }                                                      //~v5ivI~
//          if(!Pcbfunc(lpdwPIDs[dwIndex],0,szFileName,Pparm))//regardless rc of OpenProcess pass pid//~v5ivR~//~v6xrR~
            if(!Pcbfunc(cbopt,lpdwPIDs[dwIndex],0,szFileName,Pparm))//regardless rc of OpenProcess pass pid//~v6xrI~
               break ;                                             //~v5ivR~
                                                                   //~v5ivI~
            // NTVDM exist?                                        //~v5ivI~
            if( _stricmp( szFileName+(strlen(szFileName)-9),"NTVDM.EXE")==0)//~v5ivI~
            {                                                      //~v5ivI~
               //16bit enumproc                                    //~v5ivI~
               sInfo.dwPID = lpdwPIDs[dwIndex] ;                   //~v5ivI~
               sInfo.cbfunc = Pcbfunc;                             //~v5ivR~
               sInfo.lParam = Pparm;                               //~v5ivI~
               sInfo.bEnd = FALSE ;                                //~v5ivI~
               // enum 16 bit stack                                //~v5ivI~
               lpfVDMEnumTaskWOWEx( lpdwPIDs[dwIndex],             //~v5ivI~
                  (TASKENUMPROCEX) Enum16,                         //~v5ivI~
                  (LPARAM) &sInfo);                                //~v5ivI~
               // enum main end?                                   //~v5ivI~
               if(sInfo.bEnd)                                      //~v5ivI~
                  break ;                                          //~v5ivI~
            }                                                      //~v5ivI~
         }                                                         //~v5ivI~
         HeapFree( GetProcessHeap(), 0, lpdwPIDs ) ;               //~v5ivI~
         FreeLibrary( hInstLib2 ) ;                                //~v5ivI~
                                                                   //~v5ivI~
      // Windows 95                                                //~v5ivI~
      }else if( osver.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS ) //~v5ivI~
      {                                                            //~v5ivI~
         	hInstLib = LoadLibraryA( "PSAPI.DLL" ) ;               //~v6X6I~
            lpfEnumProcessModules=0;                               //~v6X6I~
            lpfGetModuleFileNameEx=0;                              //~v6X6I~
         	if( hInstLib == NULL )                                 //~v6X6I~
            	uerrmsg("uenumpid:PSAPI.DLL is missing, exe-fullpathname not available.",0);//~v6X6I~
         	else                                                   //~v6X6I~
         	{                                                      //~v6X6I~
         		lpfEnumProcessModules = (BOOL(WINAPI *)(HANDLE, HMODULE *,//~v6X6I~
            						DWORD, LPDWORD)) GetProcAddress( hInstLib,//~v6X6I~
            						"EnumProcessModules" ) ;       //~v6X6I~
         		lpfGetModuleFileNameEx =(DWORD (WINAPI *)(HANDLE, HMODULE,//~v6X6I~
            						LPTSTR, DWORD )) GetProcAddress( hInstLib,//~v6X6I~
            						"GetModuleFileNameExA" ) ;     //~v6X6I~
                swokPSAPI=lpfEnumProcessModules && lpfGetModuleFileNameEx;//~v6X6I~
            }                                                      //~v6X6I~
         hInstLib = LoadLibraryA( "Kernel32.DLL" ) ;               //~v5ivI~
         if( hInstLib == NULL )                                    //~v5ivI~
            return FALSE ;                                         //~v5ivI~
                                                                   //~v5ivI~
         lpfCreateToolhelp32Snapshot=                              //~v5ivI~
            (HANDLE(WINAPI *)(DWORD,DWORD))                        //~v5ivI~
            GetProcAddress( hInstLib,                              //~v5ivI~
            "CreateToolhelp32Snapshot" ) ;                         //~v5ivI~
         lpfProcess32First=                                        //~v5ivI~
            (BOOL(WINAPI *)(HANDLE,LPPROCESSENTRY32))              //~v5ivI~
            GetProcAddress( hInstLib, "Process32First" ) ;         //~v5ivI~
         lpfProcess32Next=                                         //~v5ivI~
            (BOOL(WINAPI *)(HANDLE,LPPROCESSENTRY32))              //~v5ivI~
            GetProcAddress( hInstLib, "Process32Next" ) ;          //~v5ivI~
         if( lpfProcess32Next == NULL ||                           //~v5ivI~
            lpfProcess32First == NULL ||                           //~v5ivI~
            lpfCreateToolhelp32Snapshot == NULL )                  //~v5ivI~
         {                                                         //~v5ivI~
            FreeLibrary( hInstLib ) ;                              //~v5ivI~
            return FALSE ;                                         //~v5ivI~
         }                                                         //~v5ivI~
                                                                   //~v5ivI~
         // Toolhelp snapshot handle of system process             //~v5ivI~
         hSnapShot = lpfCreateToolhelp32Snapshot(                  //~v5ivI~
            TH32CS_SNAPPROCESS, 0 ) ;                              //~v5ivI~
         if( hSnapShot == INVALID_HANDLE_VALUE )                   //~v5ivI~
         {                                                         //~v5ivI~
            FreeLibrary( hInstLib ) ;                              //~v5ivI~
            return FALSE ;                                         //~v5ivI~
         }                                                         //~v5ivI~
                                                                   //~v5ivI~
         procentry.dwSize = sizeof(PROCESSENTRY32) ;	           //~v5ivI~
         bFlag = lpfProcess32First( hSnapShot, &procentry ) ;      //~v5ivI~
         if (Pparm)                                                //~v5kvI~
//            pparentpid=*((int**)(ULONG)Pparm);                     //~v5kvR~//~v6hhR~
              pparentpid=*((int**)(ULPTR)Pparm);                   //~v6hhI~
         else                                                      //~v5kvI~
            pparentpid=0;                                          //~v5kvI~
         cbopt=CBEPIO_KERNEL_LOGIC;//     0x01	//enum by kernel logic//~v6xrI~
         while( bFlag )                                            //~v5ivI~
         {                                                         //~v5ivI~
            if (pparentpid)                                        //~v5kvI~
            	*pparentpid=procentry.th32ParentProcessID;         //~v5kvI~
//          if (Popt & UEPI_VERBOSE && swokPSAPI)	//  0x02	//output fullpath exe name//~v6X6I~//~v6XaR~
            if (swokPSAPI)	//  0x02	//output fullpath exe name //~v6XaI~
            {                                                      //~v6X6I~
                cpid=procentry.th32ProcessID;                      //~v6X6I~
                hProcess = OpenProcess(                            //~v6X6I~
                   PROCESS_QUERY_INFORMATION | PROCESS_VM_READ,    //~v6X6I~
                   FALSE, cpid) ;                                  //~v6X6I~
                if( hProcess != NULL )                             //~v6X6I~
                {                                                  //~v6X6I~
                   	if( lpfEnumProcessModules( hProcess, &hMod, sizeof( hMod ), &dwSize2 ) )//~v6X6I~
                   	{                                              //~v6X6I~
                      	if( lpfGetModuleFileNameEx( hProcess, hMod, szFileName, sizeof( szFileName ) ) ) //get fullpath//~v6X6I~
		                   strcpy(procentry.szExeFile,szFileName); //~v6X6R~
                   	}                                              //~v6X6I~
                   	CloseHandle( hProcess ) ;                      //~v6X6I~
                }                                                  //~v6X6I~
            }                                                      //~v6X6I~
//          if(Pcbfunc( procentry.th32ProcessID, 0,procentry.szExeFile,Pparm))//~v5ivR~//~v6xrR~
            if(Pcbfunc(cbopt,procentry.th32ProcessID,0,procentry.szExeFile,Pparm))//~v6xrR~
            {                                                      //~v5ivI~
               procentry.dwSize = sizeof(PROCESSENTRY32) ;         //~v5ivI~
               bFlag = lpfProcess32Next( hSnapShot, &procentry );  //~v5ivI~
            }else                                                  //~v5ivI~
               bFlag = FALSE ;                                     //~v5ivI~
         }                                                         //~v5ivI~
                                                                   //~v5ivI~
      }else                                                        //~v5ivI~
         return FALSE ;                                            //~v5ivI~
      FreeLibrary( hInstLib ) ;                                    //~v5ivI~
      return TRUE ;                                                //~v5ivI~
}//uenumpid                                                        //~v5ivI~
//****************************                                     //~v5ivI~
BOOL WINAPI Enum16( DWORD dwThreadId, WORD hMod16, WORD hTask16,   //~v5ivI~
      PSZ pszModName, PSZ pszFileName, LPARAM lpUserDefined )      //~v5ivI~
{                                                                  //~v5ivI~
      BOOL bRet ;                                                  //~v5ivI~
      EnumInfoStruct *psInfo = (EnumInfoStruct *)lpUserDefined ;   //~v5ivI~
      int cbopt=0;                                                 //~v6xrR~
//*************************                                        //~v5ivI~
//    bRet = psInfo->cbfunc(psInfo->dwPID, hTask16, pszFileName,psInfo->lParam ) ;//~v5ivR~//~v6xrR~
      bRet = psInfo->cbfunc(cbopt,psInfo->dwPID, hTask16, pszFileName,psInfo->lParam ) ;//~v6xrI~
      if(!bRet)                                                    //~v5ivI~
      {                                                            //~v5ivI~
         psInfo->bEnd = TRUE ;                                     //~v5ivI~
      }                                                            //~v5ivI~
      return !bRet;                                                //~v5ivI~
}//Enum16                                                          //~v5ivI~
#endif //!MGW32                                                    //~v5ncI~
#endif  //WIN32                                                    //~v5ivR~
#ifdef LNX                                                         //~v5jaI~
#ifndef NOMT                                                       //~v6a0I~
//**************************************************************** //~v5jaI~
//*create thread (LNX)                                             //~v5jaR~
//**************************************************************** //~v5jaI~
//ULONG uthread(int Popt,UTHFUNC Pfunc,int Pstacksz,ULONG Pparm,ULONG *Ppthid)//~v6xjR~
ULPTR uthread(int Popt,UTHFUNC Pfunc,int Pstacksz,ULONG Pparm,ULONG *Ppthid)//~v6xjI~
{                                                                  //~v5jaI~
	pthread_t th;                                                  //~v5jaI~
    int rc;                                                        //~v5jaI~
//***************                                                  //~v5jaI~
	rc=pthread_create(&th,	//output handle                        //~v5jaI~
					NULL,   //thread attr structure                //~v5jaI~
					Pfunc,  //init routine                         //~v5jaI~
                    (void*)Pparm);                                 //~v5jaI~
    if (rc)                                                        //~v5jaI~
    {                                                              //~v5jaI~
    	uerrapi0t(0,"pthread_create",errno);                       //~v5jaI~
        th=0;                                                      //~v5jaI~
    }                                                              //~v5jaI~
//  return (ULONG)th;                                              //~v6xjR~
    return (ULPTR)th;                                              //~v6xjI~
}//uthread                                                         //~v5jaI~
//**************************************************************** //~v5jaM~
//*uevent (LNX)                                                    //~v5jaR~
//time parameter unit is milisec                                   //~v5jaM~
//rc for wait:1:timeout,2:abandoned                                //~v5jaM~
//**************************************************************** //~v5jaM~
int uevent(int Popt,int Peventcnt,ULONG *Peventcb,int Ptimeout,int *Ppindex)//~v5jaM~
{                                                                  //~v5jaM~
    int waittime,ii;                                               //~v5jaR~
    PUEVENTCB *ppecb,pecb;                                         //~v5jaM~
    struct timespec timeout,*ptimeout;                             //~v5jaI~
//***************                                                  //~v5jaM~
	if (Popt & UEVENTO_INIT)	//fill eventcb                     //~v5jaM~
    {                                                              //~v5jaM~
        ppecb=(PUEVENTCB*)(ULONG)Peventcb;                         //~v5jaR~
    	for (ii=0;ii<Peventcnt;ii++,ppecb++)                       //~v5jaM~
        {                                                          //~v5jaM~
        	pecb=(PUEVENTCB)malloc(UEVENTCBSZ);                    //~v5jaI~
            memset(pecb,0,UEVENTCBSZ);                             //~v5jaM~
			if (Popt & UEVENTO_MANUALRESET)	//manual resetfill eventcb//~v5jaI~
            	pecb->UECBflag|=UECBF_MANUAL;                      //~v5jaI~
			if (Popt & UEVENTO_INITSIGNAL)	//initialy signaled status//~v5jaI~
            	pecb->UECBflag|=UECBF_POSTED;                      //~v5jaI~
			pthread_cond_init(&pecb->UECBcond,NULL);               //~v5jaR~
        	*ppecb=pecb;                                           //~v5jaI~
        }                                                          //~v5jaM~
        return 0;                                                  //~v5jaM~
    }                                                              //~v5jaM~
    pecb=(PUEVENTCB)(ULONG)*Peventcb;	//top ecb                  //~v5jaR~
	if (Popt & (UEVENTO_WAIT|UEVENTO_WAITALL))	//wait event       //~v5jaM~
    {                                                              //~v5jaM~
        waittime=Ptimeout;                                         //~v5jaM~
        if (waittime<0)                                            //~v5jaM~
        	ptimeout=0;                                            //~v5jaI~
        else                                                       //~v5jaI~
        {                                                          //~v5jaI~
        	time(&timeout.tv_sec);                                 //~v5jaI~
            timeout.tv_sec+=waittime/1000;	//seconds              //~v5jaI~
            timeout.tv_nsec+=(waittime%1000)*1000000;	//nano-seconds//~v5jaI~
            ptimeout=&timeout;                                     //~v5jaI~
        }                                                          //~v5jaI~
        if (Peventcnt==1)    //wait for single object              //~v5jaR~
            return uevent_wait1(0,pecb,ptimeout);                  //~v5jaR~
        else                                                       //~v5jaI~
            return uevent_waitm(Popt,Peventcnt,(PUEVENTCB*)(ULONG)Peventcb,ptimeout,Ppindex);//~v5jaR~
    }                                                              //~v5jaM~
	if (Popt & UEVENTO_POST)	//signal raise                     //~v5jaM~
        return uevent_post1(0,pecb);	//0:lock required in subrtn//~v5jaR~
	if (Popt & UEVENTO_RESET)   //signal raise                     //~v5jaM~
        return uevent_reset1(pecb);                                //~v5jaR~
    return -1;                                                     //~v5jaM~
}//uevent                                                          //~v5jaM~
//**************************************************************** //~v5jaI~
//*wait 1 ecb(not ecblist)                                         //~v5jaI~
//time parameter by timeout struc                                  //~v5jaI~
//rc for wait:1:timeout,2:abandoned                                //~v5jaI~
//**************************************************************** //~v5jaI~
int uevent_wait1(int Plockedsw,PUEVENTCB Ppecb,struct timespec *Ptimespec)//~v5jaR~
{                                                                  //~v5jaI~
    int rc;                                                        //~v5jaI~
//***************                                                  //~v5jaI~
	if (!Plockedsw)                                                //~v5jaI~
		UEVENT_LOCK();                                             //~v5jaR~
	if (Ppecb->UECBflag & UECBF_POSTED)    //already posted        //~v5jaR~
        rc=UEVENTRC_POSTED;                                        //~v5jaR~
    else                                                           //~v5jaR~
    {                                                              //~v5jaI~
        Ppecb->UECBflag|=UECBF_WAITING;    //accept post           //~v5jaR~
        if (!Ptimespec) //no timeout parameter                     //~v5jaR~
        {                                                          //~v5jaR~
            while (!(Ppecb->UECBflag & UECBF_POSTED))  //until real post//~v5jaR~
                pthread_cond_wait(&Ppecb->UECBcond,&Sueventmutex);  //void func//~v5jaR~
	        rc=UEVENTRC_POSTED;                                    //~v5jaI~
        }                                                          //~v5jaR~
        else    //time parameter                                   //~v5jaR~
        {                                                          //~v5jaR~
            for (;;)                                               //~v5jaR~
            {                                                      //~v5jaR~
                rc=pthread_cond_timedwait(&Ppecb->UECBcond,&Sueventmutex,Ptimespec);//~v5jaR~
                switch(rc)                                         //~v5jaR~
                {                                                  //~v5jaR~
                case 0: //sccress                                  //~v5jaR~
		            if (!(Ppecb->UECBflag & UECBF_POSTED))  //until real post//~v5jaR~
                        continue;                                  //~v5jaR~
                    rc=UEVENTRC_POSTED;                            //~v5jaR~
                    break;                                         //~v5jaR~
                case ETIMEDOUT:                                    //~v5jaR~
		            if (!(Ppecb->UECBflag & UECBF_POSTED))  //until real post//~v5jaI~
                        rc=UEVENTRC_TIMEOUT;                //timeout//~v5jaR~
                    else                                           //~v5jaR~
                        rc=UEVENTRC_POSTED;                        //~v5jaR~
                    break;                                         //~v5jaR~
                default:            //EINTR interrupted by signal  //~v5jaR~
                    rc=UEVENTRC_ABANDONED;              //err      //~v5jaR~
                }                                                  //~v5jaR~
                break;                                             //~v5jaI~
            }//loop                                                //~v5jaR~
        }//timewait                                                //~v5jaR~
        Ppecb->UECBflag&=~UECBF_WAITING;    //reset wait           //~v5jaI~
    }                                                              //~v5jaI~
    if (!(Ppecb->UECBflag & UECBF_MANUAL))  //auto reset           //~v5jaI~
        Ppecb->UECBflag &=~UECBF_POSTED;     //reset post bit      //~v5jaI~
	if (!Plockedsw)                                                //~v5jaI~
		UEVENT_UNLOCK();                                           //~v5jaI~
    return rc;                                                     //~v5jaI~
}//uevent_wait1                                                    //~v5jaI~
//**************************************************************** //~v5jaI~
//*post ecb                                                        //~v5jaI~
//**************************************************************** //~v5jaI~
int uevent_post1(int Plockedsw,PUEVENTCB Ppecb)                    //~v5jaI~
{                                                                  //~v5jaI~
    int rc=0;                                                      //~v5jaR~
//***************                                                  //~v5jaI~
	if (!Plockedsw)                                                //~v5jaI~
		UEVENT_LOCK();                                             //~v5jaI~
    if (!(Ppecb->UECBflag & UECBF_POSTED))	//not double post      //~v5jaR~
    {                                                              //~v5jaR~
        Ppecb->UECBflag |=UECBF_POSTED;       //real post          //~v5jaI~
        if (!(Ppecb->UECBflag & UECBF_ECBLIST) && Ppecb->UECBpecblist)   //not ecblist itselef but wait by ecblist//~v5jaR~
            rc=uevent_postm(Ppecb);                                //~v5jaI~
        else                                                       //~v5jaI~
        {                                                          //~v5jaI~
        	if (Ppecb->UECBflag & UECBF_WAITING)    //waiting      //~v5jaR~
            	pthread_cond_broadcast(&Ppecb->UECBcond); //void   //~v5jaR~
        }                                                          //~v5jaI~
    }                                                              //~v5jaI~
	if (!Plockedsw)                                                //~v5jaI~
		UEVENT_UNLOCK();                                           //~v5jaI~
    return rc;                                                     //~v5jaI~
}//uevent_post1                                                    //~v5jaI~
//**************************************************************** //~v5jaI~
//*wait by ecblist                                                 //~v5jaR~
//time parameter by timeout struc                                  //~v5jaI~
//rc for wait:1:timeout,2:abandoned                                //~v5jaI~
//**************************************************************** //~v5jaI~
int uevent_waitm(int Popt,int Peventcnt,PUEVENTCB *Pppecb,struct timespec *Pptimeout,int *Ppindex)//~v5jaR~
{                                                                  //~v5jaI~
    int rc,idx;                                                    //~v5jaR~
    PUEVENTCB plistecb,*ppecb,*pcopyecblist;                       //~v5jaR~
    PUEVENTLIST pecblist;                                          //~v5jaR~
//***************                                                  //~v5jaI~
	uevent(UEVENTO_INIT,1,(ULONG*)(ULONG)&plistecb,0,0);	//get ecb for ecblist//~v5jaR~
    plistecb->UECBflag|=UECBF_ECBLIST;	//ecblist ecb              //~v5jaI~
    if (Popt & UEVENTO_WAITALL)                                    //~v5jaI~
    	plistecb->UECBflag|=UECBF_WAITALL;                         //~v5jaR~
//  pecblist=(PUEVENTLIST)malloc(UEVENTLISTSZ+Peventcnt*4);        //~v5jaR~//~v690R~
//  pecblist=(PUEVENTLIST)malloc(UEVENTLISTSZ+Peventcnt*PTRSZ);    //~v690I~//~v6xiR~
    pecblist=(PUEVENTLIST)malloc(UEVENTLISTSZ+(ULONG)Peventcnt*PTRSZ);//~v6xiI~
    plistecb->UECBpecblist=pecblist;    //chain to ecblist         //~v5jaI~
    pcopyecblist=(PUEVENTCB*)(ULONG)(pecblist+1);                  //~v5jaR~
//  memcpy(pcopyecblist,Pppecb,Peventcnt*4);                       //~v5jaR~//~v690R~
//  memcpy(pcopyecblist,Pppecb,Peventcnt*PTRSZ);                   //~v690I~//~v6xiR~
    memcpy(pcopyecblist,Pppecb,(size_t)(Peventcnt*PTRSZ));         //~v6xiI~
    pecblist->UECBLpcopyecblist=pcopyecblist;		//ptr list     //~v5jaR~
    pecblist->UECBLecbcount=Peventcnt;	//ecb count                //~v5jaR~
                                                                   //~v5jaI~
    UEVENT_LOCK();                                                 //~v5jaI~
                                                                   //~v5jaI~
    if (!(rc=uevent_setuplist(plistecb)))                          //~v5jaR~
    {                                                              //~v5jaI~
		rc=uevent_wait1(1,plistecb,Pptimeout);                     //~v5jaR~
        if (rc==UEVENTRC_POSTED)                                   //~v5jaR~
        {                                                          //~v5jaI~
            for (ppecb=pcopyecblist,idx=0;idx<Peventcnt;idx++,ppecb++)//~v5jaR~
            {                                                      //~v5jaR~
                if (!*ppecb)                                       //~v5jaR~
                    break;                                         //~v5jaR~
            }                                                      //~v5jaR~
            *Ppindex=idx;                                          //~v5jaR~
        }                                                          //~v5jaI~
    }                                                              //~v5jaI~
    uevent_resetlist(plistecb);                                    //~v5jaI~
                                                                   //~v5jaI~
	UEVENT_UNLOCK();                                               //~v5jaI~
                                                                   //~v5jaI~
	free(plistecb);                                                //~v5jaI~
	free(pecblist);                                                //~v5jaI~
    return rc;                                                     //~v5jaI~
}//uevent_waitm                                                    //~v5jaR~
//**************************************************************** //~v5jaI~
//*post ecblist (ecb lock is already gotten)                       //~v5jaR~
//*parm:posted ecb                                                 //~v5jaI~
//**************************************************************** //~v5jaI~
int uevent_postm(PUEVENTCB Ppecb)                                  //~v5jaR~
{                                                                  //~v5jaI~
    PUEVENTCB plistecb,*ppecb,*pcopyecblist;                       //~v5jaR~
    PUEVENTLIST pecblist;                                          //~v5jaI~
    int rc=0,ii;                                                   //~v5jaR~
//***************                                                  //~v5jaI~
    plistecb=Ppecb->UECBpecblist;	//wait by ecblist              //~v5jaR~
	if (plistecb->UECBflag & UECBF_WAITING)    //waiting           //~v5jaR~
    {                                                              //~v5jaI~
	    pecblist=plistecb->UECBpecblist;                           //~v5jaI~
    	pcopyecblist=(PUEVENTCB*)pecblist->UECBLpcopyecblist;      //~v5jaR~
        for (ii=pecblist->UECBLecbcount,ppecb=pcopyecblist;ii>0;ppecb++,ii--)//~v5jaR~
        {                                                          //~v5jaR~
            if (Ppecb==*ppecb)                                     //~v5jaR~
            {                                                      //~v5jaR~
                pecblist->UECBLpostcount++;                        //~v5jaR~
                Ppecb->UECBpecblist=0;   //accept only once post to ecblist//~v5jaR~
                *ppecb=0;   //posted id                            //~v5jaR~
			    if (!(Ppecb->UECBflag & UECBF_MANUAL))  //auto reset//~v5jaI~
        			Ppecb->UECBflag &=~UECBF_POSTED;     //reset post bit//~v5jaI~
            }                                                      //~v5jaR~
        }                                                          //~v5jaR~
        if (!(plistecb->UECBflag & UECBF_WAITALL)               //one ecb posted//~v5jaR~
        ||  pecblist->UECBLpostcount==pecblist->UECBLecbcount)    //posted all//~v5jaR~
            rc=uevent_post1(1,plistecb); //1:need not get lock     //~v5jaR~
    }                                                              //~v5jaI~
    return rc;                                                     //~v5jaR~
}//uevent_postm                                                    //~v5jaR~
//**************************************************************** //~v5jaI~
//*reset post bit                                                  //~v5jaI~
//rc 16:err                                                        //~v5jaI~
//**************************************************************** //~v5jaI~
int uevent_reset1(PUEVENTCB Ppecb)                                 //~v5jaI~
{                                                                  //~v5jaI~
    int rc;                                                        //~v5jaI~
//***************                                                  //~v5jaI~
    UEVENT_LOCK();                                                 //~v5jaI~
	if (Ppecb->UECBflag & UECBF_WAITING)    //waiting              //~v5jaR~
    	rc=UEVENTRC_ERR;                                           //~v5jaR~
    else                                                           //~v5jaI~
		Ppecb->UECBflag&=~UECBF_POSTED;                            //~v5jaR~
	UEVENT_UNLOCK();                                               //~v5jaI~
    return rc;                                                     //~v5jaR~
}//uevent_reset1                                                   //~v5jaR~
//**************************************************************** //~v5jaI~
//*set/reset back ptr to ecblist (under LOCK gotten)               //~v5jaR~
//rc 16:err                                                        //~v5jaI~
//**************************************************************** //~v5jaI~
int uevent_setuplist(PUEVENTCB Pplistecb)                          //~v5jaR~
{                                                                  //~v5jaI~
    int rc=0,ii,postcount,ecbcount;                                //~v5jaR~
    PUEVENTLIST pecblist;                                          //~v5jaI~
    PUEVENTCB *ppecb,pecb;                                         //~v5jaR~
//***************                                                  //~v5jaI~
	pecblist=Pplistecb->UECBpecblist;                              //~v5jaI~
	ppecb=pecblist->UECBLpcopyecblist;                             //~v5jaI~
    ecbcount=pecblist->UECBLecbcount;                              //~v5jaI~
    for (ii=ecbcount,postcount=0;ii>0;ii--,ppecb++)                //~v5jaI~
    {                                                              //~v5jaI~
        pecb=*ppecb;                                               //~v5jaI~
        if (pecb->UECBpecblist) //already in multiple wait         //~v5jaR~
        {                                                          //~v5jaI~
            rc=UEVENTRC_ERR;                                       //~v5jaR~
            break;                                                 //~v5jaI~
        }                                                          //~v5jaI~
        else                                                       //~v5jaR~
        if (pecb->UECBflag & UECBF_WAITING) //already in waiting   //~v5jaI~
        {                                                          //~v5jaI~
            rc=UEVENTRC_ERR;                                       //~v5jaI~
            break;                                                 //~v5jaI~
        }                                                          //~v5jaI~
        else                                                       //~v5jaI~
        if (pecb->UECBflag & UECBF_POSTED) //already posted        //~v5jaR~
        {                                                          //~v5jaI~
            *ppecb=0;                                              //~v5jaI~
            postcount++;                                           //~v5jaI~
		    if (!(pecb->UECBflag & UECBF_MANUAL))  //auto reset    //~v5jaI~
        		pecb->UECBflag &=~UECBF_POSTED;     //reset post bit//~v5jaI~
        }                                                          //~v5jaI~
        else                                                       //~v5jaI~
            pecb->UECBpecblist=Pplistecb;                          //~v5jaR~
    }                                                              //~v5jaI~
    if (!rc)                                                       //~v5jaR~
    {                                                              //~v5jaI~
        pecblist->UECBLpostcount=postcount;                        //~v5jaR~
        if (postcount)                                             //~v5jaI~
        {                                                          //~v5jaI~
	        if (!(Pplistecb->UECBflag & UECBF_WAITALL)               //one ecb posted//~v5jaR~
	        ||  postcount==pecblist->UECBLecbcount)    //posted all//~v5jaI~
		        Pplistecb->UECBflag|=UECBF_POSTED;                 //~v5jaR~
        }                                                          //~v5jaI~
	}                                                              //~v5jaI~
    return rc;                                                     //~v5jaI~
}//uevent_setuplist                                                //~v5jaR~
//**************************************************************** //~v5jaI~
//*set/reset back ptr to ecblist (under LOCK gotten)               //~v5jaI~
//**************************************************************** //~v5jaI~
int uevent_resetlist(PUEVENTCB Pplistecb)                          //~v5jaI~
{                                                                  //~v5jaI~
    int ecbcount,ii;                                               //~v5jaR~
    PUEVENTLIST pecblist;                                          //~v5jaI~
    PUEVENTCB *ppecb,pecb;                                         //~v5jaR~
//***************                                                  //~v5jaI~
	pecblist=Pplistecb->UECBpecblist;                              //~v5jaI~
	ppecb=pecblist->UECBLpcopyecblist;                             //~v5jaI~
    ecbcount=pecblist->UECBLecbcount;                              //~v5jaI~
    for (ii=ecbcount;ii>0;ii--,ppecb++) //reset all                //~v5jaI~
    {                                                              //~v5jaI~
        pecb=*ppecb;                                               //~v5jaI~
        if (pecb && pecb->UECBpecblist==Pplistecb) //my list       //~v5jaR~
            pecb->UECBpecblist=0;            //clear ptr to the ecblist//~v5jaR~
    }                                                              //~v5jaI~
    return 0;                                                      //~v5jaI~
}//uevent_setuplist                                                //~v5jaI~
//**************************************************************** //~v5jaI~
//*critical section control by semaphore                           //~v5jaI~
//*parm:handle, when init it must contains key if not private      //~v5jaI~
//**************************************************************** //~v5jaI~
int ucriticalsection(int Popc,ULONG Ppmutex)                       //~v5jaR~
{                                                                  //~v5jaR~
	int reqcode,rc=4;                                              //~v5jaR~
	pthread_mutex_t *pmutex;                                       //~v5jaI~
//***************                                                  //~v5jaI~
	reqcode=Popc & CRITSEC_REQIDMASK;                              //~v5jaI~
	pmutex=(pthread_mutex_t *)Ppmutex;                             //~v5jaR~
    switch (reqcode)                                               //~v5jaI~
    {                                                              //~v5jaI~
	case CRITSEC_INIT:                                             //~v5jaI~
		pthread_mutex_init(pmutex,          //return always 0      //~v5jaR~
							NULL);	//attr                         //~v5jaI~
        rc=0;                                                      //~v5jaI~
        break;                                                     //~v5jaI~
	case CRITSEC_ENTER:                                            //~v5jaI~
		rc=pthread_mutex_lock(pmutex);                             //~v5jaR~
        if (rc)		//already locked by myself                     //~v5jaR~
        	return uerrapi0t(0,"pthread_mutex_lock",rc);           //~v5jaI~
        break;                                                     //~v5jaI~
	case CRITSEC_LEAVE:                                            //~v5jaI~
		rc=pthread_mutex_unlock(pmutex);                           //~v5jaR~
        if (rc)    //already unlocked,owned by other thread        //~v5jaR~
        	return uerrapi0t(0,"pthread_mutex_unlock",rc);         //~v5jaI~
        break;                                                     //~v5jaI~
	case CRITSEC_DELETE:                                           //~v5jaI~
		rc=pthread_mutex_destroy(pmutex);                          //~v5jaR~
        if (rc)                                                    //~v5jaI~
        	return uerrapi0t(0,"pthread_mutex_destroy",rc);        //~v5jaI~
        break;                                                     //~v5jaI~
    }                                                              //~v5jaI~
    return rc;                                                     //~v5jaI~
}//ucriticalsection                                                //~v5jaI~
#endif  //NOMT                                                     //~v6a0I~
#endif  //LNX                                                      //~v5jaI~
//*************************************************************    //~v6xnI~
#ifdef W32                                                         //~v6xnI~
DWORD ugetprocessid(int Popt,ULPTR Pprocesshandle)                 //~v6xnR~
{                                                                  //~v6xnI~
	DWORD pid;                                                     //~v6xnI~
    char wk[32];                                                   //~v6xnI~
//*********************                                            //~v6xnI~
	if ((LONGHANDLE)Pprocesshandle==(LONGHANDLE)-1)                //~v6N0R~
    	return (DWORD)-1;                                          //~v6N0I~
    pid=GetProcessId((HANDLE)Pprocesshandle);                      //~v6xnI~
    if ((int)pid<=0)                                               //~v6xnI~
        if (Popt & UGPIO_ERRMSG)                                   //~v6xnI~
        {                                                          //~v6xnI~
//          sprintf(wk,"x%p",Pprocesshandle);                      //~v6xnI~//~v6L5R~
            sprintf(wk,"x%" FMT_PTR("x"),Pprocesshandle);          //~v6L5I~
        	uerrapi1t(1/*err description by last err*/,"GetProcessId",wk,-1/*issue GetLastError()*/);//~v6xnR~
        }                                                          //~v6xnI~
    UTRACEP("ugetprocessid handle=%p,pid=%d=x%x,error=%d\n",Pprocesshandle,pid,pid,GetLastError());//~v6xnI~
    return pid;                                                    //~v6xnI~
}//ugetprocessid                                                   //~v6xnR~
#endif                                                             //~v6xnI~
