//*CID://+v70rR~:                             update#=  116;       //~v70rR~
//*************************************************************
//*************************************************************
//*xeshm.c                                                         //~v70rR~
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
#ifdef W32                                                         //~v70rI~
	#include <windows.h>                                           //~v70rR~
#endif                                                             //~v70rI~
//**********
#include <ulib.h>
#include <ualloc.h>                                                //~v70rR~
#include <udbcschk.h>                                              //+v70rR~
#include <uque.h>                                                  //~v70rI~
#include <uerr.h>                                                  //~v58EI~
#include <ufile.h>
#include <ufemsg.h>
#include <udos.h>                                                  //~v58EI~
#include <uproc.h>                                                 //~v58EI~
#include <uedit.h>                                                 //~v58EI~
#include <ustring.h>                                               //~v70rI~
#include <uparse.h>                                                //~v70rR~
#include <utrace.h>                                                //~v70rI~
                                                                   //~v579I~
#include "xe.h"                                                    //~v70rR~
#include "xescr.h"                                                 //~v70rI~
#include "xefile.h"                                                //~v70rI~
#include "xeacb.h"                                                 //~v70rM~
#include "xesyn.h"                                                 //~v70rI~
#include "xesyn2.h"                                                //~v70rI~
//#include "xeshm.h"                                               //~v70rM~
//*************************************************************
#define PGMSHI  "xeshm"                                            //~v70rR~
#define SHM_MAXCMDLEN SHMAX_CMDLEN+_MAX_PATH*3+256                 //~v70rR~
#define SHM_MAXPARMNO         20                                   //~v70rI~
                                                                   //~v70rI~
#define SHM_PARM_SHCMD          0                                  //~v70rI~
#define SHM_PARM_ERRFILE        1                                  //~v70rI~
#define SHM_PARM_ACBCMD         2                                  //~v70rI~
#define SHM_PARM_MAX            3                                  //~v70rI~
//*************************************************************    //~v55oI~
static ULONG  Spid;                                                //~v55wI~
static char Sprefixname[_MAX_PATH];                                //~v70rI~
//*************************************************************    //~v55wI~
int callacb(char **Ppout);                                         //~v70rI~
int callsh(char **Ppout);                                          //~v70rI~
int parsecmd(char *Pcmd,char **Ppout);                             //~v70rI~
int dosh(char *Pcmd);                                              //~v70rI~
                                                                   //~v70rI~
#ifdef W32                                                         //~v70rI~
    int minimizewindow(int Popt);                                  //~v70rR~
    BOOL CALLBACK cbfunc(HWND hwnd,LPARAM Pprm);                   //~v70rR~
#endif                                                             //~v70rI~
//*************************************************************
//*parm1:option
//*parm2:read pipe fd number
//*parm3:write pipe fd number
//*************************************************************
int main(int parmc,char * parmp[])
{
    char buff[SHM_MAXCMDLEN];                                      //~v70rR~
    char errmsgbuff[MAX_UERRMSGLL+32];                             //~v70rI~
    int fdr,fdw,len,opt,rc;                                        //~v70rR~
//**********************
    Spid=_getpid();     //parm to callback func                    //~v56xM~
    uerrmsg("%s:started pid=%d(x%08x)",0,                          //~v579R~
				PGMSHI,Spid,Spid);                                 //~v70rR~
UTRACE_INIT(PGMSHI ".trc",1);                                      //~v70rR~
//UTRACEP("parmc=%d\n",parmc);                                     //~v56wR~

    if (parmc!=4)
    {
    	uerrexit("parm err;p1:option, p2:inut fd, p3:output fd, p4: source-highlight parameters\n",0);//~v70rR~
    }
    opt=atoi(parmp[1]);
    fdr=atoi(parmp[2]);
    fdw=atoi(parmp[3]);
UTRACEP("curpid=%x opt=%x,fdr=%d,fdw=%d,wd=%s,parm=%s",Spid,opt,fdr,fdw);//~v70rR~
#ifdef W32                                                         //~v70rI~
    if (opt & UPROC_SYSCMD_MIN)                                    //~v55oR~
        minimizewindow(opt);                                       //~v55oR~
#endif                                                             //~v70rI~
    sprintf(buff,"%x",Spid);                                       //~v56xR~
	write(fdw,buff,strlen(buff)+1);//tell pid to wxe,write last null//~v56xR~
                                                                   //~v56xI~
    for (;;)
    {
		len=read(fdr,buff,sizeof(buff));	//read input filename  //~v70rR~
        if (len==-1)
        {
            uerrmsg("%s read failed,rc=%d",0,                      //~v70rR~
                    PGMSHI,errno);                                 //~v70rR~
            break;
        }
        *(buff+len)=0;
UTRACEP("xeftpc read %s\n",buff);                                  //~v70rR~
        *(buff+len)=0;
        uerrmsg("%s:cmd:%s\n",0,                                   //~v58EI~
					(char *)utimeedit("HH:MM:SS",0),               //~v58EI~
					buff);                                         //~v55oI~
        if (!strcmp(buff,"quit"))
        	break;
        rc=dosh(buff);                                             //~v70rR~
        if (rc)                                                    //~v70rI~
        {                                                          //~v70rI~
        	sprintf(errmsgbuff,"%d:%s",rc,ugeterrmsg());           //~v70rI~
			write(fdw,errmsgbuff,strlen(errmsgbuff));              //~v70rI~
        }                                                          //~v70rI~
        else                                                       //~v70rI~
			write(fdw,"0;done",6);                                 //~v70rR~
UTRACEP("xeftpc write resp\n");                                    //~v70rR~
    }
    uerrmsg("%s:exit",0,                                           //~v55oI~
				PGMSHI);                                           //~v70rR~
	return 0;
}//main
//**************************************************************** //~v58EI~
//*execute source-highlight                                        //~v70rR~
//**************************************************************** //~v58EI~
int dosh(char *Pcmd)                                               //~v70rR~
{                                                                  //~v58EI~
	char *ppout[SHM_PARM_MAX];                                     //~v70rR~
    int rc=0;                                                      //~v70rR~
//************************                                         //~v58EI~
	if ((rc=parsecmd(Pcmd,ppout)),rc)                              //~v70rI~
    	return rc;                                                 //~v70rI~
	if (rc=callsh(ppout),rc)	//execute source-highlight         //~v70rR~
    	return rc;                                                 //~v70rI~
	if (rc=callacb(ppout),rc)	//execute source-highlight         //~v70rR~
    	return rc;                                                 //~v70rI~
    return rc;                                                     //~v58EI~
}//callsh                                                          //~v70rR~
//**************************************************************** //~v70rI~
//*execute source-highlight                                        //~v70rI~
//**************************************************************** //~v70rI~
int parsecmd(char *Pcmd,char **Ppout)                              //~v70rI~
{                                                                  //~v70rI~
	char *pc,*pc2,*perr,*pacbcmd;                                  //~v70rI~
    int rc=4,len;                                                  //~v70rR~
//************************                                         //~v70rI~
	Ppout[SHM_PARM_SHCMD]=Pcmd;                                    //~v70rI~
    for (;;)                                                       //~v70rI~
    {                                                              //~v70rI~
    	perr=Pcmd;                                                 //~v70rI~
    	if (pc=strchr(Pcmd,'|'),!pc)      //shcmd -i inpfile shopt 2>err | acbcmd -pprefix acbopt//~v70rI~
        	break;                                                 //~v70rI~
        *pc++=0;                                                   //~v70rI~
    	Ppout[SHM_PARM_ACBCMD]=perr=pacbcmd=pc+strspn(pc," ");     //~v70rI~
        if (pc=strstr(Pcmd,"2>"),!pc)                              //~v70rI~
        	break;                                                 //~v70rI~
        *pc=0;                                                     //~v70rI~
        pc+=2;                                                     //~v70rI~
		Ppout[SHM_PARM_ERRFILE]=pc+strspn(pc," ");                 //~v70rR~
        if (pc=strstr(pacbcmd,"-p"),!pc)                           //~v70rI~
        	break;                                                 //~v70rI~
        pc+=2;                                                     //~v70rI~
        pc2=strchr(pc,' ');                                        //~v70rI~
        if (!pc2)                                                  //~v70rI~
			len=strlen(pc);                                        //~v70rI~
        else                                                       //~v70rI~
	    	len=(int)((ULONG)pc2-(ULONG)pc);                       //~v70rI~
        UmemcpyZ(Sprefixname,pc,len);                              //~v70rI~
        rc=0;                                                      //~v70rI~
    }                                                              //~v70rI~
    if (rc)                                                        //~v70rI~
    {                                                              //~v70rI~
    	uerrmsg("parmerr(%s)",0,                                   //~v70rI~
        		perr);                                             //~v70rI~
    }                                                              //~v70rI~
    return rc;                                                     //~v70rI~
}//parsecmd                                                        //~v70rI~
//**************************************************************** //~v70rI~
//*execute source-highlight                                        //~v70rI~
//**************************************************************** //~v70rI~
int callsh(char **Ppout)                                           //~v70rI~
{                                                                  //~v70rI~
	char *pcmd,**ppparm,*perrfile,*pparg[SHM_MAXPARMNO];           //~v70rR~
    char outfnm[_MAX_PATH+4];                                      //~v70rI~
    int rc=0,opdno;                                                //~v70rR~
    FILE *fh;                                                      //~v70rI~
//************************                                         //~v70rI~
	pcmd=Ppout[SHM_PARM_SHCMD];                                    //~v70rI~
	perrfile=Ppout[SHM_PARM_ERRFILE];                              //~v70rI~
    if (uparsev(pcmd,&ppparm,&opdno,0,0/*delmtbl*/))               //~v70rI~
    {                                                              //~v70rI~
    	uerrmsg("parse failed(%s)",0,                              //~v70rI~
        			pcmd);                                         //~v70rI~
        return 4;                                                  //~v70rI~
    }                                                              //~v70rI~
	if (!(fh=uredirect(2/*stderr*/,perrfile,0/*open(not append mode)*/)))//~v70rI~
        rc=4;                                                      //~v70rI~
    else                                                           //~v70rI~
    {                                                              //~v70rI~
    	sprintf(outfnm,"%s" SHFNM_ESCOUTF,Sprefixname);            //~v70rR~
        memcpy(pparg,ppparm,(UINT)opdno*4);                        //~v70rI~
        pparg[opdno++]="-o";                                       //~v70rI~
        pparg[opdno++]=outfnm;                                     //~v70rI~
        pparg[opdno]=0;                                            //~v70rI~
		shsub(opdno,pparg);                                        //~v70rI~
		if (uredirectrestore(2/*stderr*/))                         //~v70rR~
        	rc=4;                                                  //~v70rI~
	}                                                              //~v70rI~
    ufree(ppparm);                                                 //~v70rI~
    return rc;                                                     //~v70rI~
}//callsh                                                          //~v70rI~
//**************************************************************** //~v70rI~
//*analyze source-highlight output                                 //~v70rI~
//**************************************************************** //~v70rI~
int callacb(char **Ppout)                                          //~v70rI~
{                                                                  //~v70rI~
	char *pcmd,**ppparm;                                           //~v70rR~
    int rc=0,opdno;                                                //~v70rI~
//************************                                         //~v70rI~
	pcmd=Ppout[SHM_PARM_ACBCMD];                                   //~v70rI~
    if (uparsev(pcmd,&ppparm,&opdno,0,0/*delmtbl*/))               //~v70rI~
    {                                                              //~v70rI~
    	uerrmsg("parse failed(%s)",0,                              //~v70rI~
        			pcmd);                                         //~v70rI~
        return 4;                                                  //~v70rI~
    }                                                              //~v70rI~
	if (acbsub(opdno,ppparm))                                      //~v70rR~
    	rc=4;                                                      //~v70rI~
    ufree(ppparm);                                                 //~v70rI~
    return rc;                                                     //~v70rI~
}//callacb                                                         //~v70rI~
#ifdef W32                                                         //~v70rI~
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
    if (pid==Spid)  //current process hwnd                         //~v56wR~
    {                                                              //~v55oI~
        ShowWindow(hwnd,SW_MINIMIZE);
    }                                                              //~v55oI~
	return TRUE;
}//cbfunc
#endif                                                             //~v70rI~
#define ACBSUB                                                     //~v70rI~
#include "xeacbs.c"                                                //~v70rR~
