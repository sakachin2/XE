//*CID://+vb07R~:                             update#=  104;       //~vb07R~
//*************************************************************
//vb07:150314 add Ctrl+C handley to xesyscmd to break cmd wait     //~vb07I~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vafc:120607 C4701 warning(used uninitialized variable) by VC6    //~vafcI~
//v70r:060826 sub cmd;set stdin redirect to protect hung by wait kbd input//~v70rI~
//v59Q:041127 (BUG)append mode redirect require fseek not only fopen("a")//~v59QI~
//v59L:041121 (BUG) ENV var may large for PATH etc                 //~v59LI~
//v59E:041120 (WXE)pass env to sub process xesyscmd.exe            //~v59EI~
//v59n:041013 (BUG of v58E) remove failed because not closed       //~v59nR~
//v58E:041011 (BUG) win98 system() dose not support redirect for bat file,try set redirection before system() call//~v58EI~
//v579:040516 (WXE:BUG)cmd svr should set CD effect for cmd grep etc//~v579I~
//v56x:040414 (WXE)tell pid to wxe to chk pid active(spawan returns dos prompt pid)//~v56xI~
//v56w:040411 (WXE)win2000 title is differ from w98,so use pid for search hwnd//~v55wI~
//v55o:040222 (FTP)use client pgm for avoid dos prompt screen appear
//*************************************************************
//*xeftpc.c
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <io.h>
#include <fcntl.h>
#include <process.h>

//**********
#include <windows.h>
//**********
#include <ulib.h>
#include <uque.h>                                                  //~v58ER~
#include <uerr.h>                                                  //~v58EI~
#include <ufile.h>
#include <ufemsg.h>
#include <udos.h>                                                  //~v58EI~
#include <uproc.h>                                                 //~v58EI~
#include <uproc2.h>                                                //~v58EI~
#include <uedit.h>                                                 //~v58EI~
//#undef NOTRACE                                                   //~v55oR~
#include <utrace.h>
                                                                   //~v579I~
#include "xesyscmd.h"                                              //~v58EI~
//*************************************************************
#define PGM  "xesyscmd"                                            //~v55oI~
#define KILLED "16:done"                                           //~vb07I~
//*************************************************************    //~v55oI~
static ULONG  Spid;                                                //~v55wI~
//*************************************************************    //~v55wI~
int putcmd(char *Pcmd);                                            //~v58EI~
int callftp(char *Pcmd);
int minimizewindow(int Popt);
BOOL CALLBACK cbfunc(HWND hwnd,LPARAM Pprm);
int cmdforme(char *Pcmd);                                          //~v579I~
BOOL WINAPI ctrlHandler(DWORD Peventid);                           //~vb07I~
                                                                   //~vb07I~
static int Sfdw;                                                   //~vb07I~
static int Sprocessing;                                            //~vb07I~
//*************************************************************
//*parm1:option
//*parm2:read pipe fd number
//*parm3:write pipe fd number
//*************************************************************
int main(int parmc,char * parmp[])
{
//  char buff[256];                                                //~v59LR~
    char buff[UPROC_MAX_CMDSVRBUF];                                //~v59LR~
    int fdr,fdw,len,opt;
//**********************
    Spid=_getpid();     //parm to callback func                    //~v56xM~
    uerrmsg("%s:started pid=%d(x%08x)",0,                          //~v579R~
				PGM,Spid,Spid);                                    //~v579R~
UTRACE_INIT("xesyscmd.trc",1);                                     //~v70rR~
//UTRACEP("parmc=%d\n",parmc);                                     //~v56wR~

    if (parmc!=4)
    {
    	uerrexit("parm err;p1:option,p2:inut fd,p3:output fd\n",0);
    }
    opt=atoi(parmp[1]);
    fdr=atoi(parmp[2]);
    fdw=atoi(parmp[3]);
    Sfdw=fdw;                                                      //~vb07I~
//UTRACEP("curpid=%x\n",Spid);                                     //~v56wR~
//fprintf(stderr,"curpid=%x\n",Spid);                              //~v56xR~
    if (opt & UPROC_SYSCMD_MIN)                                    //~v55oR~
        minimizewindow(opt);                                       //~v55oR~
    sprintf(buff,"%x",Spid);                                       //~v56xR~
	write(fdw,buff,strlen(buff)+1);//tell pid to wxe,write last null//~v56xR~
    SetConsoleCtrlHandler(ctrlHandler,TRUE/*add handler*/);        //~vb07R~
    for (;;)
    {
		Sprocessing=0;                                             //~vb07I~
		len=read(fdr,buff,sizeof(buff));
		Sprocessing=1;                                             //~vb07I~
        if (len==-1)
        {
            uerrmsg("xesyscmd read failed,rc=%d",0,
                    errno);
            break;
        }
        *(buff+len)=0;
//UTRACEP("xeftpc read %s\n",buff);                                //~v56wR~
        *(buff+len)=0;
//        uerrmsg("cmd:%s\n",0,                                    //~v58ER~
        uerrmsg("%s:cmd:%s\n",0,                                   //~v58EI~
					(char *)utimeedit("HH:MM:SS",0),               //~v58EI~
					buff);                                         //~v55oI~
        if (!strcmp(buff,"quit"))
        	break;
      if (*buff==XECMDSVR_CMDID)                                   //~v579R~
        cmdforme(buff+1);	//sve should execute                   //~v579I~
      else                                                         //~v579I~
        callftp(buff);
		write(fdw,"0;done",6);                                     //~v55oR~
//UTRACEP("xeftpc write resp\n");                                  //~v56wR~
    }
    uerrmsg("%s:exit",0,                                           //~v55oI~
				PGM);                                              //~v55oI~
	return 0;
}//main
//****************************************************************
//*execute ftp
//****************************************************************
int callftp(char *Pcmd)
{
#ifdef AAA
#define BUFFSZ 4096
    char *pc;
    char *stdofnm;
    char buff[BUFFSZ];
    FILE *fhpipe,*fhstdo;
//*******************
	pc=strchr(Pcmd,'>');
    if (!pc)
    	return 4;
	*pc++=0;
    stdofnm=pc+strspn(pc," ");	//redirect out filename
//UTRACEP("xeftpc before popen\n");                                //~v56wR~
    fhpipe=_popen(Pcmd,"r");
//UTRACEP("xeftpc after popen fh=%x\n",fhpipe);                    //~v56wR~
    if (!fhpipe)
    	return ufileapierr("_popen","for ftp",errno);
    fhstdo=fopen(stdofnm,"w");
    while (!feof(fhpipe))
    {
    	if (fgets(buff,BUFFSZ,fhpipe))
        	fprintf(fhstdo,buff);
//UTRACEP("xeftpc read %s\n",buff);                                //~v56wR~
    }
    _pclose(fhpipe);
    fclose(fhstdo);
    return 0;
#else
//UTRACEP("xeftpc system call\n");                                 //~v56wR~
//  return usystem2(UPROC_NOOKMSG,Pcmd);                           //~v58ER~
    return putcmd(Pcmd);                                           //~v58EI~
//UTRACEP("xeftpc end\n");                                         //~v56wR~
#endif
}//callftp
//**************************************************************** //~v58EI~
//*minimize console window                                         //~v58EI~
//**************************************************************** //~v58EI~
int putcmd(char *Pcmd)                                             //~v58EI~
{                                                                  //~v58EI~
	char stdofnm[_MAX_PATH];                                       //~v58EI~
	char stdefnm[_MAX_PATH];                                       //~v58EI~
    int rc=0,cmdlen,redirectparm;                                  //~v58EI~
    FILE *fh12=0,*fh1=0,*fh2=0;                                    //~v58ER~
//************************                                         //~v58EI~
    if (!udosiswinnt())                                            //~v58EI~
    {                                                              //~v58EI~
//      if (uprocparseredirect(Pcmd,stdofnm,stdefnm,&redirectparm,&cmdlen))//~v70rR~
        if (uprocparseredirect(Pcmd,0,stdofnm,stdefnm,&redirectparm,&cmdlen))//0:no stdin parse//~v70rI~
        {	                                                       //~v58EI~
        	uerrmsg("parse redirect failed for \"%s\"",0,          //~v58EI~
            			Pcmd);                                     //~v58EI~
            return 4;                                              //~v58EI~
        }                                                          //~v58EI~
printf("! NT cmd=%s,stdo=%s,stde=%s\n",Pcmd,stdofnm,stdefnm);      //~v70rI~
UTRACEP("! NT cmd=%s,stdo=%s,stde=%s\n",Pcmd,stdofnm,stdefnm);     //~v70rI~
        if (!stdefnm||*stdefnm=='&')                               //~v58EI~
          if (redirectparm & PRERC_STDOAPPEND)                     //~v59QI~
//          fh12=uredirect(3,stdofnm,(FILE*)(ULONG)1);	//append mode//~v59QI~//~vafkR~
            fh12=uredirect(3,stdofnm,(FILE*)(ULPTR)1);	//append mode//~vafkI~
          else                                                     //~v59QI~
	        fh12=uredirect(3,stdofnm,0);                           //~v58EI~
        else                                                       //~v58EI~
        {                                                          //~v58EI~
            if (*stdofnm)   //stdo redirected                      //~v58ER~
              if (redirectparm & PRERC_STDOAPPEND)                 //~v59QI~
//              fh1=uredirect(1,stdofnm,(FILE*)(ULONG)1);   //append mode//~v59QI~//~vafkR~
                fh1=uredirect(1,stdofnm,(FILE*)(ULPTR)1);   //append mode//~vafkI~
              else                                                 //~v59QI~
                fh1=uredirect(1,stdofnm,0);                        //~v58ER~
            if (*stdefnm)   //stdo redirected                      //~v58EI~
              if (redirectparm & PRERC_STDEAPPEND)                 //~v59QI~
//              fh2=uredirect(2,stdefnm,(FILE*)(ULONG)1);	//append mode//~v59QI~//~vafkR~
                fh2=uredirect(2,stdefnm,(FILE*)(ULPTR)1);	//append mode//~vafkI~
              else                                                 //~v59QI~
                fh2=uredirect(2,stdefnm,0);                        //~v58EI~
        }                                                          //~v58EI~
        *(Pcmd+cmdlen)=0;                                          //~v58EI~
    }//win95,win98                                                 //~v58EI~
//  fprintf(stdout,"==%s\n",Pcmd);                                 //~v58ER~
	rc=usystem2(UPROC_NOOKMSG,Pcmd);                               //~v58EI~
UTRACEP("usystem2 rc=%d\n",rc);                                    //~v70rI~
    if (fh12)                                                      //~v58ER~
    {                                                              //~v59nR~
        uredirectrestore(3);                                       //~v58ER~
    	fclose(fh12);                                              //~v59nR~
    }                                                              //~v59nR~
    else                                                           //~v58EI~
    {                                                              //~v58EI~
        if (fh1)                                                   //~v58EI~
        {                                                          //~v59nR~
            uredirectrestore(1);                                   //~v58EI~
	    	fclose(fh1);                                           //~v59nR~
        }                                                          //~v59nR~
        if (fh2)                                                   //~v58EI~
        {                                                          //~v59nR~
            uredirectrestore(2);                                   //~v58EI~
	    	fclose(fh2);                                           //~v59nR~
        }                                                          //~v59nR~
    }                                                              //~v58EI~
printf(" cmdrc=%d fh1=%p,fh2=%p,fh12=%p\n",rc,fh1,fh2,fh12);       //~v70rR~
    return rc;                                                     //~v58EI~
}//putcmd                                                          //~v59QR~
//****************************************************************
//*minimize console window
//****************************************************************
int minimizewindow(int Popt)
{
    return EnumWindows(cbfunc,Popt);
}//minimizewindow
//***************************************************************************
//  enumwin callback;minimyze myself
//**************************************************************************
BOOL CALLBACK cbfunc(HWND hwnd,LPARAM Pprm)
{
//  char buff[512];                                                //~v56wR~
    ULONG pid;                                                     //~v56wR~
//********************************
	GetWindowThreadProcessId(hwnd,&pid);                           //~v56wR~
//	GetWindowText(hwnd,buff,sizeof(buff));                         //~v56wR~
//UTRACEP("windows pid=%x,hwnd=%x,text=%s\n",pid,hwnd,buff);       //~v56wR~
//  if (!stricmp(buff,"XESYSCMD"))	//all xesyscmd.exe             //~v56wR~
    if (pid==Spid)  //current process hwnd                         //~v56wR~
    {                                                              //~v55oI~
//		UTRACEP("minimize\n");                                     //~v56wR~
        ShowWindow(hwnd,SW_MINIMIZE);
    }                                                              //~v55oI~
	return TRUE;
}//cbfunc
//**************************************************************** //~v579I~
//*cmdforme                                                        //~v579I~
//*excute cmd for myself(cd etc,env setup)                         //~v579I~
//**************************************************************** //~v579I~
int cmdforme(char *Pcmd)                                           //~v579I~
{                                                                  //~v579I~
    char *pcmd,*popd,wkfnm[_MAX_PATH];                             //~v579R~
    char *pc;                                                      //~v59EI~
    int   cmdid,rc=0;                                                //~v579R~//~vafcR~
//*******************                                              //~v579I~
	pcmd=Pcmd;                                                     //~v579I~
    cmdid=*pcmd;                                                   //~v579R~
    popd=pcmd+XECMDSVR_OPDPOS-1;                                   //~v579R~
	switch(cmdid)                                                  //~v579I~
    {                                                              //~v579I~
	case XECMDSVR_DRIVECMD:                                        //~v579R~
    	rc=uchdrive(*popd);                                        //~v579R~
        uerrmsg("cmd:rc=%d;%s\n",0,                                //~v579I~
					rc,Pcmd);                                      //~v579I~
    	break;                                                     //~v579M~
	case XECMDSVR_CDCMD:                                           //~v579I~
    	rc=uchdir(0,popd);                                         //~v579I~
        uerrmsg("cmd:rc=%d;%s\n",0,                                //~v579I~
					rc,Pcmd);                                      //~v579I~
    	break;                                                     //~v579I~
	case XECMDSVR_PWDCMD:                                          //~v579R~
    	rc=(ugetcwd(wkfnm)==0);                                    //~v579R~
        uerrmsg("cmd:rc=%d;%s:%s\n",0,                             //~v579I~
					rc,Pcmd,wkfnm);                                //~v579I~
    	break;                                                     //~v579I~
	case XECMDSVR_GETENV:                                          //~v59EI~
    	pc=getenv(popd);                                           //~v59EI~
        if (pc)                                                    //~v59EI~
	        uerrmsg("cmd:%s=%s\n",0,                               //~v59EI~
						Pcmd,pc);                                  //~v59EI~
        else                                                       //~v59EI~
	        uerrmsg("cmd:%s=(not defined)\n",0,                    //~v59EI~
						Pcmd);                                     //~v59EI~
    	break;                                                     //~v59EI~
	case XECMDSVR_PUTENV:                                          //~v59EI~
    	rc=putenv(popd);                                           //~v59EI~
        uerrmsg("cmd:rc=%d;%s\n",0,                                //~v59EI~
					rc,Pcmd);                                      //~v59EI~
    	break;                                                     //~v59EI~
    default:                                                       //~v579I~
        uerrmsg("cmd:%s\n",0,                                      //~v579I~
					Pcmd);                                         //~v579I~
        rc=8;                                                      //~v579I~
    }                                                              //~v579I~
    return rc;                                                     //~v579I~
}//cmdfome                                                         //~v579I~
//*****************************************************************//~vb07I~
void endprocess(BOOL Pswcontinue)                                  //~vb07I~
{                                                                  //~vb07I~
	if (Sprocessing)  //not yet reponsed                           //~vb07I~
		write(Sfdw,KILLED,sizeof(KILLED)-1);                       //~vb07R~
    if (!Pswcontinue)                                              //~vb07I~
	    close(Sfdw);                                               //~vb07I~
}                                                                  //~vb07I~
//*****************************************************************//~vb07I~
BOOL WINAPI ctrlHandler(DWORD Peventid)                            //~vb07I~
{                                                                  //~vb07I~
	char *peventid="unknown";                                      //~vb07I~
    BOOL swcontinue=FALSE;                                         //~vb07I~
//***********************                                          //~vb07I~
	switch(Peventid)                                               //~vb07I~
    {                                                              //~vb07I~
    case CTRL_C_EVENT:                                             //~vb07I~
    	peventid="Ctrl+C";                                         //~vb07I~
        swcontinue=TRUE;                                           //~vb07I~
        break;                                                     //~vb07I~
    case CTRL_BREAK_EVENT:                                         //~vb07I~
    	peventid="Ctrl+Break";                                     //~vb07I~
        swcontinue=TRUE;                                           //~vb07I~
        break;                                                     //~vb07I~
    case CTRL_CLOSE_EVENT:                                         //~vb07I~
    	peventid="Close";                                          //~vb07I~
        break;                                                     //~vb07I~
    case CTRL_LOGOFF_EVENT:                                        //~vb07I~
    	peventid="Logoff";                                         //~vb07I~
        break;                                                     //~vb07I~
    case CTRL_SHUTDOWN_EVENT:                                      //~vb07I~
    	peventid="Shutdown";                                       //~vb07I~
        break;                                                     //~vb07I~
    }                                                              //~vb07I~
    endprocess(swcontinue);                                        //~vb07I~
	UTRACEP("ctrlHandler swProcessing=%d,id=%d(%s)\n",Sprocessing,Peventid,peventid);//~vb07R~
	uerrmsg("Detected Control Break eventid=%d(%s)\n",0,           //~vb07I~
					Peventid,peventid);                            //~vb07I~
    if (swcontinue)                                                //+vb07I~
		uerrmsg("Process Continue\n",0);                           //+vb07I~
    else                                                           //+vb07I~
		uerrmsg("Process will exit\n",0);                          //+vb07I~
    return swcontinue;	//FALSE:finally ExitProcess()              //~vb07I~
}//ctrlHandler                                                     //~vb07I~
