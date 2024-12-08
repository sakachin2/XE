//*CID://+v6D5R~:                             update#=  428;       //+v6D5R~
//************************************************************* //~5825I~
//*uproc4.c                                                        //~v5ndR~
//* syntax highliht external process control(Linux and Win only)   //~v5ndR~
//*************************************************************    //~v022I~
//v6D5:160430 LNX compiler warning for FD_SET/FD_ISSET             //~v6D5I~
//v6D0:160408 LNX compiler warning                                 //~v6D0I~
//v6xr:150118 (BUG of v6xm) 6xm is for W7 only;back to old logic when XP//~v6xrI~
//v6xm:150116 (BUG:W64)if SHCMDR(xeshm resident) is on xesynw.cfg, crash at uenumpid() to set pid to parm.//~v6xmI~
//            pid position was changed by v5nd. (xkp set to parm[0])//~v6xmI~
//            But why OK at XP, because OSVERSIONINFO returns platformid=1(<Windows98) on Windows7.//~v6xmI~
//v6xk:150115 (BUG:W32)spwanxx deplicated,use _spawnxx(return intptr_t, Linux returns int pid)//~v6xkI~
//v6xi:150115 conversion warning                                   //~v6xiI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6b9:111117 (gcc4.6)Warning:unused-but-set                       //~v6b9I~
//v63c:091120 (BUG)Ubuntu9 compiler warning                        //~v63cI~
//v5nd:081009 (SYNH) external process ctl                          //~v5ndI~
//************************************************************* //~5825I~
#include <time.h>                                               //~5825I~
#include <stdio.h>                                              //~5825I~
#include <stdlib.h>                                             //~5825I~
#include <string.h>                                             //~5825I~
#include <stdarg.h>                                             //~5A10I~
#include <errno.h>                                              //~5A10I~
#include <fcntl.h>                                                 //~v5ndI~
#ifdef UNX                                                         //~v5ndR~
	#include <unistd.h>                                            //~v428I~
	#include <sys/time.h>                                          //~v5ndI~
	#include <sys/types.h>                                         //~v5ndI~
	#include <sys/wait.h>                                          //~v5ndI~
#else                                                              //~v5ndI~
	#include <io.h>                                                //~v5ndI~
#endif   //!UNX                                                    //~v327I~
#ifdef W32                                                         //~v5ndI~
	#include <process.h>                                           //~v5ndI~
    #include <windows.h>                                           //~v5ndI~
#endif                                                             //~v5ndR~
                                                                   //~v022I~
#include <ulib.h>                                               //~5825I~
#include <uerr.h>                                               //~5A10I~
#include <uproc.h>                                              //~5A10I~
#include <uproc2.h>                                                //~v5ndI~
#include <uproc4.h>                                                //~v5ndI~
#include <ualloc.h>                                                //~v064I~
#include <uparse.h>                                                //~v098R~
#include <utrace.h>                                                //~v5bxI~
#include <ufile.h>                                                 //~v5ndI~
#include <uedit.h>                                                 //~v5ccI~
#include <ufemsg.h>                                                //~v5ndR~
#include <ustring.h>                                               //~v5ndI~
//*********************************************                    //~v064R~
#define WAIT_INTERVAL  100   //wait interval to chk process start  //~v5ndI~
#define INIT_WAITTIME  2000  //initialy wait to process start(Win) //~v5ndI~
                             //or read fd available(LNX:larger value ok because select returns when read avail)//~v5ndI~
#ifdef UNX                                                         //~v5ndI~
	#define INIT_WAIT1ST   1000  //wait 1st request reqponse to chk server terminated by the request//~v5ndI~
#else                                                              //~v5ndI~
	#define INIT_WAIT1ST   200   //wait 1st request reqponse to chk server terminated by the request//~v5ndR~
#endif                                                             //~v5ndM~
                                                                   //~v5ndI~
//#define  UPSP_OPT      0    //enum callback parameter            //~v6xmR~
//#define  UPSP_PID      1                                         //~v6xmR~
#define  UPSP_PID      0    //output pid addr                      //~v6xmR~
#define  UPSP_OPT      1    //enum callback parameter              //~v6xmI~
#define  UPSP_NAME     2                                           //~v5ndM~
#define  UPSP_OUTPL    3                                           //~v5ndM~
#define  UPSP_OUTCTR   4                                           //~v5ndM~
#define  UPSP_MAXENT   5                                           //~v5ndR~
//********************                                             //~v5ndM~
typedef struct _PIDLIST{	//serch process parameter              //~v5ndI~
                        ULONG PLpid;                               //~v5ndM~
                        char *PLfnm;                               //~v5ndM~
                       } PIDLIST,*PPIDLIST;                        //~v5ndM~
#define PIDLISTSZ sizeof(PIDLIST)                                  //~v5ndM~
//*********************************************                    //~v5ndI~
#ifdef W32                                                         //~v5j2I~
	#define SHELLPGM "cmd.exe"                                     //~v5j2I~
#endif                                                             //~v5j2I~
//*                                                                //~v064I~
	static int Sserverstat=0;                                      //~v5ndR~
	#define SVRS_READY   0x01  		//server started               //~v5bxR~
	#define SVRS_LAZY    0x02       //waiting first request to start server//~v5bxR~
                                                                   //~v5bxI~
    static CMDSVRCALLBACK  *Scmdservercallback=0;                  //~v5ndR~
    static void *Scallbackparm=0;                                  //~v5ndR~
    static int Sfdpiper,Sfdpipew;                                  //~v5ndR~
    static int Scmdserverchildpid=0;                               //~v5ndR~
//*********************************************                    //~v064R~
int uproc_shserverreq(int Popt,int Ppid,char *Pcmd,char *Pstdofnm,char *Pstdefnm,int Pfdw,int Pfdr,char *Prespbuff,int Prespbuffsz);//~v5ndR~
int uproc_shserversetup(int Popt,char *Pserverpgm,int *Pppid,int *Ppfdpipew,int *Ppfdpiper);//~v5ndI~
//**************************************************************** //~v50HI~
//**************************************************************** //~v50HI~
//*usystem                                                         //~v50HI~
//* issue command syncronous                                       //~v50HI~
//*parm1:command string                                            //~v50HI~
//*retrn:rc(=errno)                                                //~v50HI~
//**************************************************************** //~v50HI~
int uproc_shcmd(int Popt,char *Pcmd,char *Prespbuff,int Prespbuffsz)//~v5ndR~
{                                                                  //~v50HI~
	int rc;                                                        //~v50HI~
//********************                                             //~v50HI~
	    if (Sserverstat & SVRS_LAZY) //start cmd server at cmd req //~v5bxI~
        {                                                          //~v5bxI~
		    rc=Scmdservercallback(CMDCB_INIT,Scallbackparm);       //~v5bxR~
            if (rc)                                                //~v5bxI~
		    	Sserverstat=0;	//setup failed                     //~v5bxI~
        }                                                          //~v5bxI~
    	if (Sserverstat & SVRS_READY)	//setup sccess             //~v5bxR~
          	return uproc_shserverreq(Popt,Scmdserverchildpid,Pcmd,0,0,Sfdpipew,Sfdpiper,Prespbuff,Prespbuffsz);//no stdo/stde filename//~v5ndR~
    uerrmsg("Syntax highligh server is not ready",0);              //~v5ndI~
    return 8;                                                      //~v5ndI~
}//usystem2                                                        //~v5ccR~
//* close pipe file                                                //~v5bxI~
//ret :errno before close                                          //~v5bxI~
//*********************************************************************//~v5bxI~
int uproc_shserverinit(int Popt,CMDSVRCALLBACK *Pcmdsvrcallback,char *Pserverpgm,int *Pppid,int *Ppfpipew,int *Ppfdpiper)//~v5ndR~
{                                                                  //~v5bxI~
//**************                                                   //~v5bxI~
    Sserverstat=0;                                                 //~v5bxI~
	if (Popt & UPROC_LAZY) //start cmd server st cmd req           //~v5bxI~
    {	                                                           //~v5bxI~
	    Sserverstat|=SVRS_LAZY;                                    //~v5bxI~
        Scmdservercallback=Pcmdsvrcallback;                        //~v5bxI~
        Scallbackparm=Pserverpgm;                                  //~v5bxR~
    	return 0;                                                  //~v5bxI~
    }                                                              //~v5bxI~
    return uproc_shserversetup(Popt,Pserverpgm,Pppid,Ppfpipew,Ppfdpiper);//~v5ndR~
}//uproc_shserverinit                                              //~v5ndR~
//*********************************************************************//~v5bxI~
//* send term string to childproc                                  //~v5ivR~
//ret :rc                                                          //~v5ivR~
//*********************************************************************//~v5bxI~
int uproc_shserverterm(int Popt,int Ppid,int Pfdw,int Pfdr)        //~v5ndR~
{                                                                  //~v5bxI~
    int fdw;                                                       //~v5bxI~
    int pid;                                                       //~v5ccI~
//**************                                                   //~v5bxI~
    if (!Sserverstat)                                              //~v5ccI~
    	return 0;                                                  //~v5ccI~
    if (!(pid=Ppid))                                               //~v5ccI~
    {                                                              //~v5ivI~
    	pid=Scmdserverchildpid;                                    //~v5ccI~
    }                                                              //~v5ivI~
UTRACEP("shserver term pid(%d) Ppid=%d,Scmdserverpid=%d chk\n",pid,Ppid,Scmdserverchildpid);//~v5ndI~
    if (usystem_pidalivechk(pid))                                  //~v5ccR~
    	return 4;                                                  //~v5ccI~
    if (!(fdw=Pfdw))                                               //~v5bxI~
    {                                                              //~v5ivI~
        fdw=Sfdpipew;                                              //~v5bxI~
    }                                                              //~v5ivI~
UTRACEP("shserver term fdw=%d\n",fdw);                             //~v5ndI~
    if (fdw)                                                       //~v5bxI~
        write(fdw,"quit\0",5);                                     //~v5bxI~
    Sserverstat=0;                                                 //~v5bxI~
    return 0;                                                      //~v5bxI~
}//uproc_shserverterm                                              //~v5ndR~
//*******************************************************          //~v5bxI~
//*start cmd server                                                //~v5bxI~
//*parm 1:opt                                                      //~v5j2R~
//*parm 2:sub process progname/cmd string(when server2 flag on,%s is used for fd edit)//~v5j2R~
//*parm 3:optional output child process handle                     //~v5j2R~
//*parm 4:optional write pipe to cmd server                        //~v5j2R~
//*parm 5:optional read  pipe from cmd server                      //~v5j2R~
//*ret  6:pid of subprocess,if noreadsw on return hProcess by spawn//~v5j2R~
//*******************************************************          //~v5bxI~
int uproc_shserversetup(int Popt,char *Pserverpgm,int *Pppid,int *Ppfdpipew,int *Ppfdpiper)//~v5nd
{                                                                  //~v5bxI~
    int pipes[4];                                                  //~v5bxI~
    int pid,fdpiper,fdpipew,rc;                                    //~v5bxR~
    char sfdr[16],sfdw[16],opts[16];                               //~v5bxR~
	char respbuff[16];                                             //~v5ccI~
    int len;                                                       //~v5ccI~
    int cmdsvrpid=0;                                               //~v63cR~
    ULONG ulcmdsvrpid;                                             //~v5ndI~
    int opt;                                                       //~v5j2I~
    int bypassreadsw,/*shellsw,*/argvsw,callbacksw;                    //~v5j2R~//~v6b9R~
    char **argv;                                                   //~v5j2R~
	STARTSERVER_FUNC *cbfunc;                                      //~v5j2I~
#ifdef W32                                                         //~v5j2I~
    int optsp;                                                     //~v5ndM~
    int shellsw;                                                   //~v6b9I~
    char editcmd[4096];                                            //~v5j2I~
#else                                                              //~v5ndI~
	int rcselect;                                                  //~v5ndI~
#endif                                                             //~v5j2I~
	LONGHANDLE ph;                                                 //~v6xkI~
//***********************                                          //~v5bxI~
    opt=Popt & UPROC_SYSCMD_MIN;                                   //~v5j2I~
    Popt &=~UPROC_SYSCMD_MIN; //Popt used as parm to uspawn        //~v5j2I~
	bypassreadsw=Popt & UPROC_NOREADPID;                           //~v5j2I~
    Popt &=~UPROC_NOREADPID;	//bypass initial read              //~v5j2I~
#ifdef W32                                                         //~v6b9I~
	shellsw=Popt & UPROC_BYSHELL;                                  //~v5j2I~
#endif                                                             //~v6b9I~
    Popt &=~UPROC_BYSHELL;	    //through shell                    //~v5j2I~
	argvsw=Popt & UPROC_ARGV;   //parameter by argv fmt            //~v5j2R~
    Popt &=~UPROC_ARGV;	    //through shell                        //~v5j2I~
	callbacksw=Popt & UPROC_CALLBACK;   //start child by callback function//~v5j2I~
    Popt &=~UPROC_CALLBACK;                                        //~v5j2I~
    Scmdserverchildpid=0;                                          //~v5ccI~
    Sserverstat=0;      //dont use server                          //~v5bxI~
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
    ph=uspawnlp(P_NOWAIT|Popt,SHELLPGM,SHELLPGM,"/C",editcmd,0);   //~v6xkI~
    pid=(int)UGETPROCESSID(UGPIO_ERRMSG,ph);                       //~v6xmI~
  }                                                                //~v5j2M~
  else	//xe3270                                                   //~v5j2M~
  {                                                                //~v5j2I~
#endif                                                             //~v5ivI~
   if (argvsw)                                                     //~v5j2I~
   {                                                               //~v5j2I~
// 	for (argv=(char**)(ULONG)Pserverpgm;*argv;argv++)	           //~v5j2R~//~v6hhR~
 	for (argv=(char**)(ULPTR)Pserverpgm;*argv;argv++)              //~v6hhI~
    {                                                              //~v5j2I~
//  	if ((ULONG)(*argv)==UPROC_PIPE_P2C)                        //~v5j2R~//~v6hhR~
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
    pid=(int)UGETPROCESSID(UGPIO_ERRMSG,ph);                       //~v6xmI~
   }                                                               //~v5j2I~
   else                                                            //~v5j2I~
   {                                                               //~v6xkI~
//  pid=uspawnlp(P_NOWAIT|Popt,Pserverpgm,Pserverpgm,opts,sfdr,sfdw,0);//~v5bxR~//~v6xkR~
    ph=uspawnlp(P_NOWAIT|Popt,Pserverpgm,Pserverpgm,opts,sfdr,sfdw,0);//~v6xkI~
    pid=(int)UGETPROCESSID(UGPIO_ERRMSG,ph);                       //~v6xmI~
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
//UTRACEP("child spawned,ph=%p,pid=%d\n",pid,ugetpidfromhandle(pid));//~v6xkR~//~v6xiR~
	if (Ppfdpipew)                                                 //~v5bxI~
    	*Ppfdpipew=fdpipew;                                        //~v5bxI~
	if (Ppfdpiper)                                                 //~v5bxI~
    	*Ppfdpiper=fdpiper;                                        //~v5bxI~
  if (!bypassreadsw)                                               //~v5j2I~
  {                                                                //~v5j2I~
#ifdef UNX                                                         //~v5ndI~
   	rcselect=uproc_select(0,fdpiper,-1/*writefd:not use*/,-1/*exception fd*/,INIT_WAITTIME/*milisec*/,pid);//~v5ndR~
	if (!rcselect)  //timeout                                      //~v5ndI~
    {                                                              //~v5ndI~
    	uerrmsg("%s start failed(Initial response timeout(%d ms) ).",0,//~v5ndI~
                    Pserverpgm,INIT_WAITTIME);                     //~v5ndI~
        return 4;                                                  //~v5ndI~
    }                                                              //~v5ndI~
    if (rcselect<0)	//child exit                                   //~v5ndI~
#else                                                              //~v5ndI~
	optsp=UPSPO_BYNAME;                                            //~v5ndI~
    if (!uproc_srchprocessw(optsp,pid,Pserverpgm,&cmdsvrpid,INIT_WAITTIME)) //pid spawn returns is not pid but handle.(usystem_alivechk is not effective)//~v5ndR~
#endif	                                                           //~v5ndM~
    {                                                              //~v5ndI~
		uerrmsg("%s start failed(ABORTED).",                       //~v5ndR~
    			"%s の起動失敗(プロセス不在)",                     //~v5ndR~
				Pserverpgm);                                       //~v5ndR~
    	return 4;                                                  //~v5ndI~
    }                                                              //~v5ndI~
UTRACEP("srchprocess pid=%d\n",cmdsvrpid);                         //~v5ndI~
UTRACEP("read wait fd=%d\n",fdpiper);                              //~v5ndR~
//	len=read(fdpiper,respbuff,sizeof(respbuff)-1); 	//wait reply   //~v5ccI~//~v6xiR~
  	len=(int)read(fdpiper,respbuff,sizeof(respbuff)-1); 	//wait reply//~v6xiR~
UTRACED("read resp\n",respbuff,(len>0?len:0));                     //~v5ndR~
	if (len>=0)                                                    //~v5ccI~
		*(respbuff+len)=0; 	//wait reply                           //~v5ccI~
	ux2l(respbuff,&ulcmdsvrpid); //cmdserver pid                   //~v5ndR~
    cmdsvrpid=(int)ulcmdsvrpid;                                    //~v5ndI~
    pid=(int)cmdsvrpid;                                            //~v5ccI~
  }                                                                //~v5j2I~
	if (Pppid)                                                     //~v5bxI~
    	*Pppid=pid;                                                //~v5bxI~
	uerrmsg("SH:%s started, ProcessID=%d(0x%X).",                  //~v6xkR~
    		"SH:%s が起動, プロセスID=%d(0x%X)",                   //~v6xkR~
				Pserverpgm,pid,pid); //spawan pid is handle,this pid is ProcessIdNo//~v6xkR~
    Scmdserverchildpid=pid;                                        //~v5ccI~
    Sserverstat=SVRS_READY;                                        //~v5bxI~
    Sfdpiper=fdpiper;                                              //~v5bxR~
    Sfdpipew=fdpipew;                                              //~v5bxR~
    return 0;                                                      //~v5bxI~
}//uproc_shserversetup                                             //~v5ndR~
//*******************************************************          //~v5bxI~
//*throw request to resident client                                //~v5bxI~
//*parm 1:option                                                   //~v5bxI~
//*parm 2:cmd server process id                                    //~v5ccR~
//*parm 3:cmd string	replaced by output when 3270 server        //~v5ivR~
//*parm 4:optional stdout filename                                 //~v5ccR~
//*parm 5:optional stderr filename                                 //~v5ccR~
//*parm 6:optional write pipe fd                                   //~v5ccR~
//*parm 7:optional read  pipe fd                                   //~v5ccR~
//*ret   :rc(-1 if write failed,-2:server terminated,-3:server exit)//~v5ndR~
//*******************************************************          //~v5bxI~
int uproc_shserverreq(int Popt,int Ppid,char *Pcmd,char *Pstdofnm,char *Pstdefnm,int Pfdw,int Pfdr,char *Pprespbuff,int Prespbuffsz)//~v5ndR~
{                                                                  //~v5bxI~
    char cmd[UPROC_MAX_CMDSVRBUF];                                 //~v5csR~
	char respbuff[SH_MAX_RESPMSG];                                 //~v5ndR~
    int fdr,fdw,rc,len;                                            //~v5bxR~
#ifdef UNX                                                         //~v5ndI~
	int rcselect;                                                  //~v5ndI~
#endif                                                             //~v5ndI~
//***********************                                          //~v5bxI~
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
        fdw=Sfdpipew;                                              //~v5bxR~
    }                                                              //~v5ivI~
    if (!(fdr=Pfdr))                                               //~v5bxI~
    {                                                              //~v5ivI~
        fdr=Sfdpiper;                                              //~v5bxR~
    }                                                              //~v5ivI~
//  rc=write(fdw,cmd,strlen(cmd));                                 //~v5bxR~//~v6xiR~
    rc=(int)write(fdw,cmd,strlen(cmd));                            //~v6xiR~
UTRACEP("push cmd=%s\n",cmd);                                      //~v5bxI~
	if (rc==-1)                                                    //~v5bxI~
    {                                                              //~v5bxI~
    	if (Scmdservercallback)                                    //~v5bxI~
		    Scmdservercallback(CMDCB_WRTER,Scallbackparm);         //~v5bxI~
        else                                                       //~v5bxI~
			uerrmsg("Write request to SyntaxHighlight server failed,rc=%d",//~v5ndR~
						"シンタックスハイライトサーバーへの要求の書きこみ失敗。rc=%d",//~v5ndR~
					errno);                                        //~v5bxR~
    	Sserverstat=0;	//no more use cmd server                   //~v5bxI~
        return UPSPRC_WRTERR;                                      //~v5ndR~
    }                                                              //~v5bxI~
    if (Popt & UPSPO_ALIVECHK)                                     //~v5ndI~
    {                                                              //~v5ndI~
#ifdef UNX                                                         //~v5ndI~
   		rcselect=uproc_select(0,fdr,-1/*writefd:not use*/,-1/*exception fd*/,INIT_WAIT1ST/*milisec*/,Ppid);//~v5ndI~
    	if (rcselect<0)	//child exit                               //~v5ndI~
#else                                                              //~v5ndI~
    	usleepms(INIT_WAIT1ST);                                    //~v5ndI~
        if (usystem_pidalivechk(Ppid))                             //~v5ndR~
#endif                                                             //~v5ndI~
        {                                                          //~v5ndI~
    		if (Scmdservercallback)                                //~v5ndI~
			    Scmdservercallback(CMDCB_READERR,Scallbackparm);   //~v5ndR~
            else                                                   //~v5ndI~
            	uerrmsg("SyntaxHighlight server(pid=%d) terminated(check cfg parameter).",//~v5ndR~
						"シンタックスハイライトサーバー(pid=%d)が停止(cfgパラメータをチェックしてください)。",//~v5ndR~
                	    Ppid);                                     //~v5ndR~
            Sserverstat=0;  //no more use cmd server               //~v5ndI~
            return UPSPRC_PSTOP;                                   //~v5ndR~
        }                                                          //~v5ndI~
    }                                                              //~v5ndI~
//  len=read(fdr,respbuff,sizeof(respbuff)-1); 	//wait reply       //~v5bxR~//~v6xiR~
    len=(int)read(fdr,respbuff,sizeof(respbuff)-1); 	//wait reply//~v6xiR~
UTRACED("read resp\n",respbuff,(len>0?len:0));                     //~v5ndI~
	if (len>=0)                                                    //~v5bxI~
		*(respbuff+len)=0; 	//wait reply                           //~v5bxR~
    if (Prespbuffsz && Pprespbuff)            //req from uproc_shserver2req//~v5ndR~
//  	UstrncpyZ(Pprespbuff,respbuff,Prespbuffsz);	               //~v5ndR~//~v6xiR~
    	UstrncpyZ(Pprespbuff,respbuff,(size_t)Prespbuffsz);        //~v6xiR~
	rc=atoi(respbuff);                                             //~v5ndR~
    if (rc==UPSPRC_EXIT)                                           //~v5ndI~
    {                                                              //~v5ndI~
        uerrmsg("SyntaxHighlight server(pid=%d) was exit(check cfg parameter).",//~v5ndI~
				"シンタックスハイライトサーバー(pid=%d)がexit(cfgパラメータをチェックしてください)。",//~v5ndI~
                    Ppid);                                         //~v5ndI~
    }                                                              //~v5ndI~
    return rc;                                                     //~v5ndI~
}//uproc_shserverreq                                               //~v5ndR~
#ifdef W32                                                         //~v5ndI~
//****************************************                         //~v5ndM~
//*enumpid callback function                                       //~v5ndM~
//****************************************                         //~v5ndM~
//int uproc_cbenumpid(ULONG Ppid,USHORT Ppid16,char *Pfnm,void *Pprm)//~v5ndR~//~v6xrR~
int uproc_cbenumpid(int Popt,ULONG Ppid,USHORT Ppid16,char *Pfnm,void *Pprm)//~v6xrI~
{                                                                  //~v5ndM~
    ULONG pid;                                                     //~v5ndM~
    int len,parmopt,parmpid,*parmoutctr,lenp;                      //~v5ndR~
    void **enumcbparm;                                             //~v5ndM~
    char *parmname;                                                //~v5ndM~
	PPIDLIST  parmppl;                                             //~v5ndM~
    int swnameok,swkernel;                                         //~v6xrR~
//******************                                               //~v5ndM~
//  printf("callback pid=%d pid16=%d,fnm=%s,parm=%p\n",Ppid,Ppid16,Pfnm,Pprm);//~v5ndR~
//	enumcbparm=(void**)(ULONG)Pprm;                                //~v5ndM~//~v6hhR~
	enumcbparm=(void**)(ULPTR)Pprm;                                //~v6hhI~
//	parmopt=(int)enumcbparm[UPSP_OPT];                             //~v5ndM~//~v6hhR~
	parmopt=(int)(ULPTR)enumcbparm[UPSP_OPT];                      //~v6hhI~
//	parmpid=(int)enumcbparm[UPSP_PID];                             //~v5ndM~//~v6hhR~
//  parmpid=(int)(ULPTR)enumcbparm[UPSP_PID];                      //~v6xmR~
    parmpid=*(int*)(ULPTR)enumcbparm[UPSP_PID];                    //~v6xmR~
	parmname=(char*)enumcbparm[UPSP_NAME];                         //~v5ndM~
	parmppl=(PPIDLIST)enumcbparm[UPSP_OUTPL];                      //~v5ndM~
	parmoutctr=enumcbparm[UPSP_OUTCTR];                            //~v5ndM~
//  printf("callback parm opt=%d pid=%d fnm=%s,parm=%p\n",parmopt,parmpid,parmname);//~v5ndR~
	swkernel=Popt & CBEPIO_KERNEL_LOGIC;//     0x01	//enum by kernel logic//~v6xrI~
    if (Ppid16)                                                    //~v5ndM~
        pid=Ppid16;                                                //~v5ndM~
    else                                                           //~v5ndM~
        pid=Ppid;                                                  //~v5ndM~
    if (parmopt & UPSPO_BYPID)	//pid operand exist                //~v5ndM~
    {                                                              //~v5ndM~
        if (pid==(UINT)parmpid)                                    //~v5ndM~
        {                                                          //~v5ndM~
            *parmoutctr=*parmoutctr+1;                             //~v5ndM~
            if (Pfnm)                                              //~v5ndM~
            {                                                      //~v5ndM~
                len=strlen(Pfnm);                                  //~v5ndM~
                parmppl->PLfnm=(char*)umalloc(len+1);              //~v5ndM~
                memcpy(parmppl->PLfnm,Pfnm,len+1);                 //~v5ndM~
            }                                                      //~v5ndM~
            else                                                   //~v5ndM~
            	if (!parmppl->PLfnm)                               //~v5ndM~
                	parmppl->PLfnm="?";                            //~v5ndM~
        }                                                          //~v5ndM~
    }                                                              //~v5ndM~
    else                                                           //~v5ndM~
    {                                                              //~v5ndM~
    	len=(int)strlen(Pfnm);                                     //~v5ndR~
    	lenp=strlen(parmname);                                     //~v5ndR~
        UTRACEP("uproc_cbenum parm=%s,process=%s,pid=%x\n",parmname,Pfnm,pid);//~v6xmI~
//      if (len>=lenp && memicmp(Pfnm+len-lenp,parmname,(UINT)lenp)==0)//~v6xmR~
//      if (len/*exe name*/<=lenp/*fpath*/ && memicmp(Pfnm,parmname+lenp-len,(UINT)len)==0)//~v6xrR~
        if (!swkernel) //0x01	//usekernel logic for Windows7     //~v6xrR~
			swnameok=(len>=lenp && memicmp(Pfnm+len-lenp,parmname,(UINT)lenp)==0);//~v6xrI~
        else                                                       //~v6xrI~
			swnameok=(len>0 && len/*exe name*/<=lenp/*fpath*/ && memicmp(Pfnm,parmname+lenp-len,(UINT)len)==0);//~v6xrI~
        if (swnameok)                                              //~v6xrI~
		{                                                          //~v5ndM~
          if (!swkernel/*use PSAPI.dll,parent pid unknowm*/ || (ULONG)parmpid==ugetpid())                           //~v6xmR~//~v6xrR~
          {                                                        //~v6xmI~
            *parmoutctr=*parmoutctr+1;                             //~v5ndM~
            if (!parmppl->PLfnm)	//1st time                     //~v5ndM~
            {                                                      //~v5ndM~
            	parmppl->PLpid=pid;                                //~v5ndM~
            	parmppl->PLfnm=(char*)umalloc(len+1);              //~v5ndM~
            	memcpy(parmppl->PLfnm,Pfnm,len+1);                 //~v5ndM~
            }                                                      //~v5ndM~
           if (swkernel)	//parent pid match                     //~v6xrR~
            return 0;	//beak paent loop                          //~v6xmI~
          }//parent is this xe                                     //~v6xmI~
        }                                                          //~v5ndM~
    }                                                              //~v5ndM~
//  printf("callback outctr=%d\n",*parmoutctr);                    //~v5ndR~
    return 1;                                                      //~v5ndM~
}//uproc_cbenumpid                                                 //~v5ndI~
#endif                                                             //~v5ndI~
//*************************************************************    //~v5ndI~
//*process search by pid/filename with waittime(loop chk)          //~v5ndI~
//*rc:found process count                                          //~v5ndI~
//*************************************************************    //~v5ndI~
int uproc_srchprocessw(int Popt,int Ppid,char *Pexename,int *Pppid,int Pwaittime)//~v5ndI~
{                                                                  //~v5ndI~
	int rc=0,waittime,rtime,chkctr=0;	//mili seconds             //~v5ndR~
//******************                                               //~v5ndI~
	for (rtime=Pwaittime;rtime>0;)                                 //~v5ndR~
    {                                                              //~v5ndI~
    	waittime=min(rtime,WAIT_INTERVAL);                         //~v5ndI~
		usleepms(waittime);                                        //~v5ndR~
        rtime-=waittime;                                           //~v5ndI~
		rc=uproc_srchprocess(Popt,Ppid,Pexename,Pppid);            //~v5ndI~
        if (rc)                                                    //~v5ndI~
        {                                                          //~v5ndI~
        	if (chkctr)	//active twice                             //~v5ndI~
	        	break;                                             //~v5ndR~
            chkctr++;                                              //~v5ndI~
        }                                                          //~v5ndI~
    }                                                              //~v5ndI~
    UTRACEP("srch process max wait=%d,residual time=%d\n",Pwaittime,rtime);//~v5ndI~
    return rc;                                                     //~v5ndI~
}//uproc_srchprocessw                                              //~v5ndI~
//*************************************************************    //~v5ndM~
//*process search by pid/filename                                  //~v5ndM~
//*rc:found process count                                          //~v5ndM~
//*************************************************************    //~v5ndM~
int uproc_srchprocess(int Popt,int Ppid,char *Pexename,int *Pppid) //~v5ndM~
{                                                                  //~v5ndM~
#ifdef W32                                                         //~v5ndI~
	CB_ENUMPID cbenumpid;                                          //~v5ndM~
    void *enumcbparm[UPSP_MAXENT];                                 //~v5ndM~
    void *penumcbparm;                                             //~v5ndM~
	int  enumctr=0;                                                //~v5ndM~
	PIDLIST  pl;                                                   //~v5ndM~
//***********************                                          //~v5ndM~
//  enumcbparm[UPSP_OPT]=(void*)(ULONG)Popt;                       //~v5ndM~//~v6hhR~
    enumcbparm[UPSP_OPT]=(void*)(ULPTR)Popt;                       //~v6hhI~
//  enumcbparm[UPSP_PID]=(void*)(ULONG)Ppid;                       //~v5ndM~//~v6hhR~
//  enumcbparm[UPSP_PID]=(void*)(ULPTR)Ppid;                       //~v6xmR~
    enumcbparm[UPSP_PID]=(void*)(ULPTR)Pppid;	//parent pid work,parm to uproc_cbenumpid from uenumpid//~v6xmI~
	enumcbparm[UPSP_NAME]=Pexename;                                //~v5ndM~
	enumcbparm[UPSP_OUTPL]=&pl;                                    //~v5ndM~
	enumcbparm[UPSP_OUTCTR]=&enumctr;                              //~v5ndM~
    memset(&pl,0,sizeof(pl));                                      //~v5ndM~
//	penumcbparm=(void*)(ULONG)enumcbparm;                          //~v5ndM~//~v6hhR~
	penumcbparm=(void*)(ULPTR)enumcbparm;                          //~v6hhI~
    uenumpid(0,uproc_cbenumpid,penumcbparm);                       //~v5ndR~
UTRACEP("outctr=%d,pid=%d,exename=%s\n",enumctr,pl.PLpid,pl.PLfnm);//~v5ndR~
    if (enumctr)                                                   //~v5ndM~
    {                                                              //~v5ndI~
        if (Popt & UPSPO_BYNAME)                                   //~v5ndM~
        {                                                          //~v5ndM~
            if (Pppid)                                             //~v5ndM~
                *Pppid=pl.PLpid;                                   //~v5ndM~
        }                                                          //~v5ndM~
        else                                                       //~v5ndM~
        {                                                          //~v5ndM~
            if (Pexename)                                          //~v5ndM~
                strcpy(Pexename,pl.PLfnm);                         //~v5ndM~
        }                                                          //~v5ndM~
        if (pl.PLfnm)                                              //~v5ndI~
            ufree(pl.PLfnm);                                       //~v5ndI~
    }                                                              //~v5ndI~
    return enumctr;                                                //~v5ndM~
#else                                                              //~v5ndI~
    static int Sprocchk;                                           //~v5ndI~
    char procpid[32];                                              //~v5ndI~
//***********************                                          //~v5ndI~
    if (Popt & UPSPO_BYNAME)                                       //~v5ndI~
    	return 0;	//not yet supported                            //~v5ndI~
    if (!Sprocchk)                                                 //~v5ndI~
    {                                                              //~v5ndI~
    	if (ufstat("/proc",0))                                     //~v5ndI~
        	Sprocchk=-1;	//no proc system                       //~v5ndI~
        else                                                       //~v5ndI~
        	Sprocchk=1;     //procok;                              //~v5ndI~
    }                                                              //~v5ndI~
    if (Sprocchk<0)	//no proc                                      //~v5ndI~
    	return 1;    //assume pid active                           //~v5ndI~
    sprintf(procpid,"/proc/%d",Ppid);                              //~v5ndR~
    if (ufstat(procpid,0)) //no pid                                //~v5ndI~
    	return 0;                                                  //~v5ndI~
    return 1;                                                      //~v5ndR~
#endif                                                             //~v5ndI~
}//uproc_serchprocess                                              //~v5ndM~
#ifdef UNX                                                         //~v5ndI~
//*************************************************************    //~v5ndI~
//*issue select                                                    //~v5ndI~
//*parm fd: (-1:no fd spefcified id)                               //~v5ndR~
//*     childpid: 0 or pid to be checked exit when timeout         //~v5ndI~
//*rc:-1:api failed,0:timeout,-pid:timeout and child exit ,>0:ready mask:0x01-read, 0x02-write, 0x04-exception//~v5ndR~
//*************************************************************    //~v5ndI~
int uproc_select(int Popt,int Prfd,int Pwfd,int Pefd,int Pmilisec,int Pchildpid)//~v5ndR~
{                                                                  //~v5ndI~
    fd_set rfds,wfds,efds,*prfd=0,*pwfd=0,*pefd=0;                 //~v5ndI~
    struct timeval tv,*ptv=0;                                      //~v5ndR~
    int rc,nfd=0,pid;                                              //~v5ndR~
//***********************                                          //~v5ndI~
    UTRACEP("select rfd=%d,wfd=%d,efd=%d,wait mili=%d,childpid=%d\n",Prfd,Pwfd,Pefd,Pmilisec,Pchildpid);//~v5ndR~
    if (Prfd>=0)                                                   //~v5ndI~
    {                                                              //~v5ndI~
	    prfd=&rfds;                                                //~v5ndI~
	    FD_ZERO(&rfds);                                            //~v5ndI~
//    	FD_SET(Prfd,&rfds);                                        //~v5ndI~//~v6D0R~
//      FD_SET((size_t)Prfd,&rfds);                                //~v6D0I~//~v6D5R~
      	UFD_SET(Prfd,&rfds);                                       //~v6D5I~
        nfd=max(nfd,Prfd);                                         //~v5ndI~
    }                                                              //~v5ndI~
    if (Pwfd>=0)                                                   //~v5ndI~
    {                                                              //~v5ndI~
    	pwfd=&wfds;                                                //~v5ndI~
	    FD_ZERO(&wfds);                                            //~v5ndI~
//  	FD_SET(Pwfd,&wfds);                                        //~v5ndI~//~v6D0R~
//  	FD_SET((size_t)Pwfd,&wfds);                                //~v6D0I~//~v6D5R~
    	UFD_SET(Pwfd,&wfds);                                       //~v6D5I~
        nfd=max(nfd,Prfd);                                         //~v5ndI~
    }                                                              //~v5ndI~
    if (Pefd>=0)                                                   //~v5ndI~
    {                                                              //~v5ndI~
	    pefd=&efds;                                                //~v5ndI~
	    FD_ZERO(&efds);                                            //~v5ndI~
//  	FD_SET(Pefd,&efds);                                        //~v5ndI~//~v6D0R~
    	UFD_SET(Pefd,&efds);                                       //~v6D5I~
        nfd=max(nfd,Pefd);                                         //~v5ndI~
    }                                                              //~v5ndI~
    nfd++;                                                         //~v5ndI~
	if (Pmilisec>=0)                                               //~v5ndI~
    {                                                              //~v5ndI~
    	tv.tv_sec=Pmilisec/1000;                                   //~v5ndI~
    	tv.tv_usec=(Pmilisec%1000)*1000;                           //~v5ndI~
        ptv=&tv;                                                   //~v5ndR~
    }                                                              //~v5ndI~
    rc=select(nfd,prfd,pwfd,pefd,ptv);                             //~v5ndR~
    UTRACEP("select rc=%d\n",rc);                                  //~v5ndR~
    if (rc==-1)                                                    //~v5ndI~
        uerrmsg("select failed (r=%d,w=%d,e=%d)errorno=%d",0,      //~v5ndI~
        		Prfd,Pwfd,Pefd,errno);                             //~v5ndI~
    else                                                           //~v5ndI~
    if (rc>0)   //not timeout                                      //~v5ndI~
    {                                                              //~v5ndI~
        rc=0;                                                      //~v5ndI~
//      if (Prfd>=0 && FD_ISSET(Prfd,prfd))                        //~v5ndR~//~v6D0R~
//      if (Prfd>=0 && FD_ISSET((size_t)Prfd,prfd))                //~v6D0I~//~v6D5R~
        if (Prfd>=0 && UFD_ISSET(Prfd,prfd))                       //~v6D5I~
        	rc|=1;                                                 //~v5ndI~
//      if (Pwfd>=0 && FD_ISSET(Pwfd,pwfd))                        //~v5ndR~//~v6D0R~
//      if (Pwfd>=0 && FD_ISSET((size_t)Pwfd,pwfd))                //~v6D0I~//~v6D5R~
        if (Pwfd>=0 && UFD_ISSET(Pwfd,pwfd))                       //~v6D5I~
        	rc|=2;                                                 //~v5ndI~
//      if (Pefd>=0 && FD_ISSET(Pefd,pefd))                        //~v5ndR~//~v6D0R~
//      if (Pefd>=0 && FD_ISSET((size_t)Pefd,pefd))                //~v6D0I~//~v6D5R~
        if (Pefd>=0 && UFD_ISSET(Pefd,pefd))                       //~v6D5I~
        	rc|=4;                                                 //~v5ndI~
    }                                                              //~v5ndI~
    else	//0:timeout                                            //~v5ndI~
    {                                                              //~v5ndI~
    	if (Pchildpid)	//pid specified to be chk exit status      //~v5ndI~
        {                                                          //~v5ndI~
    		pid=waitpid(Pchildpid,NULL,WNOHANG/*no wait mode*/);   //~v5ndI~
		    UTRACEP("select witipid rc=%d\n",pid);                 //~v5ndI~
            if (pid==-1)                                           //~v5ndI~
            {                                                      //~v5ndI~
        		uerrmsg("waitpid failed pid=%d,errorno=%d",0,      //~v5ndI~
        				Pchildpid,errno);                          //~v5ndI~
                rc=-1;                                             //~v5ndI~
            }                                                      //~v5ndI~
            else                                                   //~v5ndI~
            if (pid)	//child exit                               //~v5ndI~
            	rc=-pid;	//child process terminated id          //~v5ndI~
        }                                                          //~v5ndI~
    }                                                              //~v5ndI~
    UTRACEP("uproc_select exit rc=%d\n",rc);                       //~v5ndI~
    return rc;      //fd count                                     //~v5ndI~
}                                                                  //~v5ndI~
//*************************************************************    //~v6D5I~
void uproc4_fdset(int Pfd,fd_set *Ppfd_set)                        //~v6D5R~
{                                                                  //~v6D5I~
   	FD_SET(Pfd,Ppfd_set);                                          //~v6D5R~
}//uproc4_fdset                                                    //~v6D5I~
//*************************************************************    //~v6D5I~
int uproc4_fdisset(int Pfd,fd_set *Ppfd_set)                       //~v6D5R~
{                                                                  //~v6D5I~
    return FD_ISSET(Pfd,Ppfd_set);                                 //~v6D5I~
}//uproc4_isset                                                    //~v6D5I~
#endif                                                             //~v5ndI~
