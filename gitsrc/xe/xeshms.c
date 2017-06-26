//*CID://+v79GR~:                             update#=  187;
//*************************************************************
//v79G:081014 (SYNH) source-highlight inheritance
//*************************************************************
//*xeshms.c
//* c-sub for xeshm.cpp
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>
#ifdef W32                                                         //~v79GI~
	#include <io.h>                                                //~v79GI~
	#include <process.h>                                           //~v79GR~
#endif                                                             //~v79GI~

//**********
#ifdef W32
	#include <windows.h>
#endif
//**********
#include <ulib.h>
#include <ualloc.h>
#include <udbcschk.h>
#include <uque.h>
#include <uerr.h>
#include <udos.h>
#include <uproc.h>
#include <uproc2.h>                                                //~v79GI~
#include <uproc4.h>                                                //~v79GI~
#include <uedit.h>
#include <ustring.h>
#include <uparse.h>
#include <utrace.h>
#include <ufile.h>

#include "xescr.h"
#include "xefile.h"
#include "xeacb.h"
#include "xesyn2.h"
//*************************************************************
#define PGMSHI  "xeshm"
#define SHM_MAXCMDLEN SHMAX_CMDLEN+_MAX_PATH*3+256
#define SHM_MAXPARMNO         20

#define SHM_PARM_SHCMD          0
#define SHM_PARM_ERRFILE        1
#define SHM_PARM_MAX            2

//*************************************************************
static ULONG Spid;
static int Sstat;                                                  //~v79GR~
#define SS_TEST           0x01 	//test option                      //~v79GR~
#define SS_PENDINGREQUEST 0x10 	//pipe read not yet replyed        //~v79GR~
static FILE *Sfhtest;                                              //~v79GR~
static FILE *Sfherr;                                               //~v79GI~
static int Sfdr,Sfdw,Sopt;
static char Scmdbuff[SHM_MAXCMDLEN];
static char Sparsewk[SHM_MAXCMDLEN];
static char *Sshparm[SHM_MAXPARMNO+3];
static char *Sshacbparm[SHM_PARM_MAX];
static char  Soldextname[_MAX_PATH];
//*************************************************************
int xeshm_parseparm(int Popt,char *Pcmd,char ***Ppparm);
int xeshm_parsecmd(int Popt,char *Pcmd,int *Ppopdno,char **Pppopd);
void xeshm_atexit(void);     //callback when normal exit*/         //~v79GI~
#ifdef W32
    int minimizewindow(int Popt);
    BOOL CALLBACK cbfunc(HWND hwnd,LPARAM Pprm);
#endif
//*************************************************************    //~v79GI~
//*atexit;                                                         //~v79GI~
//*response write to avoid hangup                                  //~v79GI~
//*************************************************************    //~v79GI~
void xeshms_atexit(void)                                           //~v79GI~
{                                                                  //~v79GI~
#define ATEXIT_MSG   "-3:exit"     //id of server exit             //+v79GR~
//*****************                                                //~v79GI~
UTRACEP("atexit stat=%x\n",Sstat);                                 //~v79GI~
	if (Sstat & SS_PENDINGREQUEST)                                 //~v79GR~
    {                                                              //~v79GI~
		write(Sfdw,ATEXIT_MSG,sizeof(ATEXIT_MSG));                 //~v79GI~
    }                                                              //~v79GI~
    return;                                                        //~v79GI~
}//xeshms_atexit                                                   //~v79GI~
//*************************************************************
//*pipe initialize
//*parm1:option
//*parm2:read pipe fd number
//*parm3:write pipe fd number
//*************************************************************
int xeshms_init(int Pparmc,char **Ppparmp)
{
	char buff[SHM_MAXCMDLEN];
    char *testfile;                                                //~v79GI~
//**********************
UTRACE_INIT(PGMSHI ".trc",1);                                      //~v79GM~
    Spid=ugetpid();     //parm to callback func                    //~v79GR~
    if (Pparmc>2 && !stricmp(Ppparmp[1],"test"))	//single process test option//~v79GR~
    {
UTRACEP("test option\n");                                          //~v79GR~
    	Sstat|=SS_TEST;                                            //~v79GR~
    	testfile=Ppparmp[2];     //test file                       //~v79GR~
        Sfhtest=fopen(testfile,"r");                               //~v79GI~
        if (!Sfhtest)                                              //~v79GI~
            uerrexit("%s open err",0,testfile);                    //~v79GI~
        return 0;                                                  //~v79GI~
    }
	uerrmsg_init("",0,0);   //no stdout output                     //~v79GR~
    uerrmsg("%s:started pid=%d(x%08x)",0,                          //~v79GM~
				PGMSHI,Spid,Spid);                                 //~v79GM~
    if (Pparmc<4)
    {
    	uerrmsg("parm err;p1:option, p2:inut fd, p3:output fd\n",0);
        return 4;
    }
    Sopt=atoi(Ppparmp[1]);
    Sfdr=atoi(Ppparmp[2]);
    Sfdw=atoi(Ppparmp[3]);
UTRACEP("cur pid=%x opt=%x,fdr=%d,fdw=%d\n",Spid,Sopt,Sfdr,Sfdw);
#ifdef W32
    if (Sopt & UPROC_SYSCMD_MIN)
        minimizewindow(Sopt);
#endif
    sprintf(buff,"%x",Spid);
	write(Sfdw,buff,strlen(buff)+1);//tell pid to wxe,write last null
    atexit(xeshms_atexit);                                         //~v79GR~
UTRACED("init pipe write",buff,strlen(buff));                      //~v79GI~
	return 0;
}//xeshms_init
//*************************************************************
//*pipe close
//*************************************************************
int xeshms_term(int Popt)
{
//**********************
    if (Sstat & SS_TEST)                                           //~v79GI~
        return 0;                                                  //~v79GI~
    close(Sfdr);
	close(Sfdw);
	return 0;
}//xeshms_term
//*************************************************************
//*get input from pipe
//*************************************************************
int xeshms_getcmd(int Popt,char ***Ppparm)
{
	char buff[SHM_MAXCMDLEN],*pc;                                  //~v79GR~
    int len,rc,sec;                                                //~v79GR~
//**********************
UTRACEP("getcmd testopt=%d\n",Sstat);                              //~v79GR~
    if (Sstat & SS_TEST)                                           //~v79GI~
    {
    	for (;;)                                                   //~v79GI~
        {                                                          //~v79GI~
        	if (!fgets(buff,sizeof(buff),Sfhtest))                 //~v79GI~
            	return -1;		//EOF                              //~v79GI~
         	USTR_DROPEOL(buff);                                    //~v79GI~
            if (*buff=='#')                                        //~v79GI~
            	continue;	//comment                              //~v79GI~
            pc=buff+strspn(buff," \t");                            //~v79GI~
            if (USTRHEADIS_IC(pc,"wait"))                          //~v79GR~
            {                                                      //~v79GI~
            	pc=strchr(pc,' ');                                 //~v79GR~
                if (!pc)                                           //~v79GI~
                	continue;                                      //~v79GI~
                pc+=strspn(pc," \t");                              //~v79GI~
                sec=atoi(pc);                                      //~v79GI~
                UTRACEP("sleep %d sec\n",sec);                     //~v79GR~
                usleepms(sec*1000);                                //~v79GR~
                continue;                                          //~v79GI~
            }                                                      //~v79GI~
            len=strlen(buff);                                      //~v79GI~
            break;                                                 //~v79GI~
         }                                                         //~v79GI~
    }
    else                                                           //~v79GI~
    {                                                              //~v79GI~
        len=read(Sfdr,buff,sizeof(buff));   //read input filename  //~v79GR~
        if (len==-1)                                               //~v79GR~
        {                                                          //~v79GR~
            uerrmsg("%s pipe read failed,rc=%d",0,                 //~v79GR~
                        PGMSHI,errno);                             //~v79GR~
            return -1;                                             //~v79GR~
        }                                                          //~v79GR~
		Sstat|=SS_PENDINGREQUEST;                                  //~v79GI~
        *(buff+len)=0;                                             //~v79GR~
    }                                                              //~v79GI~
UTRACEP("xeshm read %s\n",buff);
UTRACED("pipe read ",buff,len);                                    //~v79GI~
    uerrmsg("%s:cmd:%s\n",0,
			(char *)utimeedit("HH:MM:SS",0),
			buff);
    if (!strcmp(buff,"quit"))
    	return -1;
    rc=xeshm_parseparm(0,buff,Ppparm);
    return rc;
}//xeshms_getcmd
//****************************************************************
//*parse input cmd
//****************************************************************
int xeshm_parseparm(int Popt,char *Pcmd,char ***Ppparm)
{
	char *pc,*pco,*perr,**pparm;
    int rc=4;
//************************
	pparm=Sshacbparm;
    for (;;)
    {
//get source-highlight cmd string
    	perr=Pcmd;
        if (pc=strstr(perr,"2>"),!pc)
        	break;
        *pc=0;	//drop redirect option
        strcpy(Scmdbuff,perr);
		pparm[SHM_PARM_SHCMD]=Scmdbuff;
    	pco=Scmdbuff+strlen(Scmdbuff)+1;
UTRACEP("xeshm shcmd=%s\n",Scmdbuff);
        pc+=2;
		pc+=strspn(pc," ");
        strcpy(pco,pc);
		pparm[SHM_PARM_ERRFILE]=pco;
UTRACEP("xeshm errfile=%s\n",pco);
		*Ppparm=pparm;
        rc=0;
        break;                                                     //~v79GI~
    }
    if (rc)
    {
    	uerrmsg("parmerr(%s)",0,
        		perr);
    }
    return rc;
}//xeshm_parseparm
//****************************************************************
//*source-highlight parmsetup
//* rc:0 new extension, 1:same extension as previous
//****************************************************************
int xeshm_shpreproc(int Popt,char **Pparm,int *Ppopdno,char ***Pppopd,char **Pppinpfnm,char **Pppoutfnm,char **Pppextname)
{
	char *pcmd,*perrfile,*pinpfnm=0,*pextname,*pc,*poutfnm=0;
    int rc,opdno,ii;
//************************
	pcmd=Pparm[SHM_PARM_SHCMD];
UTRACEP("shparm=%s\n",pcmd);                                       //~v79GR~
	perrfile=Pparm[SHM_PARM_ERRFILE];
	if (xeshm_parsecmd(0,pcmd,&opdno,Sshparm))
    	return 4;
    for (ii=0;ii<opdno;ii++)
    {
    	if (!strcmp(Sshparm[ii],"-i"))
        	*Pppinpfnm=pinpfnm=Sshparm[ii+1];
        else
    	if (!strcmp(Sshparm[ii],"-o"))
        	*Pppoutfnm=poutfnm=Sshparm[ii+1];
    }
    if (!pinpfnm||!poutfnm)
    	return 4;
    UTRACEP("shparm opdno=%d,errfile=%s,inpfile=%s,outfnm=%s\n",opdno,perrfile,pinpfnm,poutfnm);//~v79GR~
    pc=strrchr(pinpfnm,'.');
    if (pc)
    	pextname=pc+1;
    else
    	pextname="";
    *Pppextname=pextname;
	if (!(Sfherr=uredirect(2/*stderr*/,perrfile,0/*open(not append mode)*/)))//~v79GR~
        rc=4;
    if (LFNM_STRCMP(Soldextname,pextname))
    {
    	rc=0;	//new
        strcpy(Soldextname,pextname);
    }
    else
    	rc=1;    //same ext name as previous
    *Ppopdno=opdno;                                                //~v79GI~
    *Pppopd=Sshparm;                                               //~v79GI~
UTRACEP("preproc rc=%d\n",rc);                                     //~v79GR~
    return rc;
}//xeshm_shpreproc
//****************************************************************
//*execute source-highlight
//****************************************************************
int xeshm_shpostproc(int Popt,int Prc,char **Pparm)
{
    int rc;                                                        //~v79GR~
//************************
UTRACEP("xeshm postproc Prc=%d Sstat=%d\n",Prc,Sstat);             //~v79GR~
	rc=Prc;                                                        //~v79GI~
	if (Sfherr)                                                    //~v79GI~
    {                                                              //~v79GI~
		if (uredirectrestore(2/*stderr*/))                         //~v79GR~
        	rc=-1;                                                 //~v79GR~
        fclose(Sfherr);                                            //~v79GI~
    }                                                              //~v79GI~
    return rc;                                                     //~v79GR~
}//xeshm_shpostproc
//****************************************************************
//*source-highlight parmsetup
//****************************************************************
int xeshm_parsecmd(int Popt,char *Pcmd,int *Ppopdno,char **Pppopd)
{
	char *pc,**ppc;
    int rc=0,ii,opdno;
//************************
    if (uparse(Pcmd,Sparsewk,&opdno,0,0/*delmtbl*/))
    {
    	uerrmsg("parse failed(%s)",0,
        			Pcmd);
        return 4;
    }
    UTRACEP("parseparm opdno=%d\n",opdno);                         //~v79GR~
    for (pc=Sparsewk,ppc=Pppopd,ii=0;ii<SHM_MAXPARMNO && ii<opdno;ii++,pc+=strlen(pc)+1)
    {
		UTRACEP("xeshm parsecmd ii=%d=%s\n",ii,pc);                //~v79GR~
        *ppc++=pc;
    }
    *ppc=0;
    *Ppopdno=opdno;
    return 0;
}//xeshm_parsecmd
//*************************************************************
//*get input from pipe
//*************************************************************
int xeshms_putmsg(int Popt,int Prc,char **Pparm)
{
	char msgbuff[SH_MAX_RESPMSG],*pmsg;                            //~v79GR~
    int len,pos;
//**********************
	if (Prc)
    {
    	pos=sprintf(msgbuff,"%d:done:",Prc);                       //~v79GR~
    	pmsg=ugeterrmsg();
        UstrncpyZ(msgbuff+pos,pmsg,(UINT)(sizeof(msgbuff)-pos));
    }
    else
		strcpy(msgbuff,"0;done");
    len=strlen(msgbuff);
	write(Sfdw,msgbuff,(UINT)len);
	Sstat&=~SS_PENDINGREQUEST;	//replyed                          //~v79GI~
UTRACEP("xeshm response %s\n",msgbuff);                            //~v79GR~
UTRACED("pipe write",msgbuff,len);                                 //~v79GI~
    return 0;
}//xeshms_getcmd
#ifdef W32
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
//  char buff[512];
    ULONG pid;
//********************************
	GetWindowThreadProcessId(hwnd,&pid);
    if (pid==Spid)  //current process hwnd
    {
        ShowWindow(hwnd,SW_MINIMIZE);
    }
	return TRUE;
}//cbfunc
#endif
