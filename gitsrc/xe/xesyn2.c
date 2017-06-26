//*CID://+vba1R~:                             update#=  300;       //+vba1R~
//*************************************************************
//*xesyn2.c                                                        //~v780R~
//*syntax highlight                                                //~v780I~
//*************************************************************
//vba1:170625 (BUG) syntaxh,podelmtbl overflow crash for long record of xesynl.cfg//+vba1I~
//vb89:170217 create if not found. ::xehosts ::xesync_.cfg         //~vb89I~
//vaz8:150109 C4244 except ULPTR and ULONG                         //~vaz8I~
//vap0:131215 (ARM)warning strict aliasing                         //~vap0I~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//vaaD:120114 install highlight-2.16                               //~vaaDI~
//vaa7:111117 (gcc4.6)Warning:unused-but-set                       //~vaa7I~
//va08:090628 (BUG)uerrmsg disappear by syn usystem msg            //~va08I~
//v7at:090403 support andre-simon's Highlight(not resident mode)   //~v7atI~
//            (it drop triling space for ansi output)              //~v7atI~
//v79J:081019 (BUG)SynH issue length err when line contains \n     //~v78JI~
//v79G:081014 (SYNH) source-highlight inheritance                  //~v78GI~
//v78s:080326*syn errmsg contains ACB yet                          //~v78sI~
//v78o:080322 (SYN:BUG)reverse is not able to distingush on browse screen//~v78oI~
//v78n:080321 (SYN:BUG)work file is not cleared                    //~v78nI~
//v78m:080321 (SYN)S.H performance;ot thru acb but direct read source-highlight output//~v78mI~
//v78b:080305*(SYN:BUG)GUI & CUI hig effect each other             //~v78bI~
//v78a:080304 (SYN)debug option(no unlink temp file at termination)//~v78aI~
//v786:080301 (SYNH)"ENTERU":update line only option               //~v786I~
//v780:080212 syntaxhighlight support                              //~v780I~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#ifdef W32
	#include <windows.h>                                           //~v780I~
	#include <io.h>                                                //~v780R~
	#include <errno.h>                                             //~v780R~
#endif
#ifdef LNX                                                         //~v780I~
    #include <unistd.h>                                            //~v780I~
#endif                                                             //~v780I~

//*******************************************************
#include <ulib.h>
#include <ualloc.h>
#include <uerr.h>
#include <uque.h>
#include <ufile.h>
#include <ustring.h>
#include <uedit.h>
#include <uproc.h>
#include <uproc4.h>                                                //~v78GR~
#include <utrace.h>
#include <uparse.h>
#include <ufemsg.h>                                                //~v780I~

#include "xe.h"
#include "xescr.h"
#include "xefile.h"
#include "xefunc.h"
#include "xesub.h"
#include "xeerr.h"
#include "xeundo.h"                                                //~v780I~
#include "xesyn.h"                                                 //~v780I~
#include "xeacb.h"                                                 //~v780M~
#define XESYN2_GLOBAL                                              //~v780R~
#include "xesyn2.h"                                                //~v780I~
#ifdef WXE                                                         //~v780I~
	#include "wxedef.h"                                            //~v780R~
	#include "wxexei.h"                                            //~v780I~
#endif                                                             //~v780R~
#ifdef XXE                                                         //~v780I~
	#include "xxedef.h"                                            //~v780R~
#endif                                                             //~v780I~
//****************************************************************
//****************************************************************
#define SYNCFG_DUMMY_RECORD  "## " SHFNM_CONFIG " ## xe created this dummy file as it is not found; see xee.txt/xej.txt for detail format ##\n"//~vb89R~
#define MAX_CONFRECSZ  1024                                        //~v780I~
#define DEFAULT_EXT    "default"                                   //~v786I~
#define RBUFFSZ  32760                                             //~v78mI~
#define CH_ESC1     0x1b                                           //~v78mI~
#define CH_ESC2     '['                                            //~v78mI~
#define CH_DELM     ';'                                            //~v78mI~
#define CH_RESET    'm'                                            //~v78mI~
#define DEFAULT_FG       0x07      //whilte on black               //~v78mI~
#define DEFAULT_BG       0         //whilte on black               //~v78mI~
//**************************************************************** //~v780I~
#ifdef SYNSUPP                                                     //~v780I~
static int   Ssynstat2;                                            //~v780I~
#define      SYNS2OPEN   0x01                                      //~v780M~
static FILE *Sfhcolor,*Sfhindex;                                   //~v780R~
ULONG        Sindexfsz,Scolorfsz,Scolorfoffs;                      //~v780I~
static int   Sopenctr=0;                                           //~v780M~
static PSHINDEX Sindexbuff;                                        //~v780I~
static int   Sindexbuffrecnotop;                                   //~v780I~
static int   Sindexbuffrecnoend;                                   //~v780I~
static int   Sstyle,Sfg,Sbg,Slineno,Sdefbg,Sdeffg;                 //~v78mR~
static  char *Spbuffinp;                                           //~v78mI~
static  char *Spbuffstylecolor;                                    //~v78mI~
static  char *Spbuffcolor;                                         //~v78mI~
static  char *Spbuffstyle;                                         //~v78mI~
//**************************************************************** //~v780I~
int synchkcfgrec(char *Pdata);                                     //~v780R~
int syngetindex(int Popt,int Plineno,PSHINDEX Ppshidx);            //~v780R~
int synopencf(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,int *Pphandle);//~v780I~
int syngetcolorparm(int Popt,char *Pparmname,char *Pparmvalue,int Pmaxvalue,int *Ppcolor);//~v780I~
int syngetcmapparm(char *Ppcmap);                                  //~v780R~
int syngetrgbparm(char *Ppcol,char *Pprgb);                        //~v780R~
int syngetpathparm(char *Plangtype,char *Ppath);                   //~v780I~
                                                                   //~v780I~
int synkicksh2(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,char *Ppfnmprefix,char *Ppfnminput,UCHAR *Plangtype);//~v78mI~
void fileproc(void);                                               //~v78mI~
int getinput(void);                                                //~v78mI~
int escchk(char *Pinp,char *Peol,char **Pinpnext,int *Ppfg,int *Ppbg,int *Ppstyle);//~v78mI~
int syngetcfdata2(int Popt,int Phandle,int Pindex,PULHCI Pplhci,int Pctr);//~v78mI~
int syngetcfdata3(int Popt,int Plineno,int *Pplen);                //~v78mI~
int lineproc(char *Pbuffinp,int Pleninp,char *Pbuffoutc,char *Pbuffouts,int *Ppoutlen);//~v78mI~
int xesyn_serverinit(int Popt,char *Pcmdname);                     //~v78GR~
int xesyn_shreq(int Popt,char *Pcmd);                              //~v78GR~
int xesyn_serverterm(int Popt);                                    //~v78GR~
                                                                   //~v78mI~
#endif //SYNSUPP                                                   //~v780I~
#ifdef SYNSUPP                                                     //~v780M~
//**************************************************************** //~v780I~
//syncfgfree                                                       //~v780I~
//  return source-highlight cmd string                             //~v780I~
//**************************************************************** //~v780I~
int syncfgfree(int Popt)                                           //~v780I~
{                                                                  //~v780I~
	char fpath[_MAX_PATH],*pc;                                     //~v780I~
    int len;                                                       //~v780I~
#ifndef NOTRACE                                                    //~vaa7I~
    int rc;                                                        //~v78GI~
#endif                                                             //~vaa7I~
//*****************************::                                  //~v780I~
	xesyn_serverterm(0);    //before del err file                  //~v78GI~
//del work                                                         //~v780I~
	if (Popt & SCFO_UNLINK)                                        //~v780R~
    {                                                              //~v780I~
        pc=Gsyncfg.SYNCpfnmprefix;                                 //~v780R~
        if (pc)                                                    //~v780R~
        {                                                          //~v780R~
            len=(int)strlen(pc);                                   //~v780R~
            memcpy(fpath,pc,(UINT)len);                            //~v780R~
          if (!(Gsyncfg.SYNCflag & SYNCF_DEBUG1))                  //~v78aI~
          {                                                        //~v78aI~
    	   if ((Gsyncfg.SYNCflag & SYNCF_USEACB))   //new logic    //~v78GI~
           {                                                       //~v78GI~
            strcpy(fpath+len,SHFNM_COLORF);                        //~v780R~
            unlink(fpath);                                         //~v780R~
           }                                                       //~v78GI~
//          strcpy(fpath,SHFNM_INDEXF);                            //~v78nR~
    	   if ((Gsyncfg.SYNCflag & SYNCF_USEACB))   //new logic    //~v78mI~
           {                                                       //~v78mI~
            strcpy(fpath+len,SHFNM_INDEXF);                        //~v78nI~
            unlink(fpath);                                         //~v780R~
           }                                                       //~v78mI~
//          strcpy(fpath,SHFNM_ERRORF);                            //~v78nR~
            strcpy(fpath+len,SHFNM_ERRORF);                        //~v78nI~
#ifndef NOTRACE                                                    //~vaa7I~
            rc=                                                    //~v78GI~
#endif                                                             //~vaa7I~
            unlink(fpath);                                         //~v780R~
#ifndef NOTRACE                                                    //~vaa7I~
            UTRACEP("unlink err %s rc=%d\n",fpath,rc);             //~v78GI~
#endif                                                             //~vaa7I~
//          strcpy(fpath,SHFNM_ERRORF2);                           //~v78nR~
    	   if (!(Gsyncfg.SYNCflag & SYNCF_USEACB))   //new logic   //~v78mI~
           {                                                       //~v78mI~
            strcpy(fpath+len,SHFNM_ESCOUTF);                       //~v78mM~
            unlink(fpath);                                         //~v78mM~
           }                                                       //~v78mI~
           else                                                    //~v78mI~
           {                                                       //~v78mI~
            strcpy(fpath+len,SHFNM_ERRORF2);                       //~v78nI~
            unlink(fpath);                                         //~v780R~
           }                                                       //~v78mI~
          }                                                        //~v78aI~
        }                                                          //~v780R~
    }                                                              //~v780I~
                                                                   //~v780I~
    UFREECLEARIFNZ(Gsyncfg.SYNCpfnmprefix);                        //~v780R~
    UFREECLEARIFNZ(Gsyncfg.SYNCshcmd);                             //~v780R~
    UFREECLEARIFNZ(Gsyncfg.SYNCacbcmd);                            //~v780R~
    UFREECLEARIFNZ(Gsyncfg.SYNCacbopt);                            //~v780R~
    UFREECLEARIFNZ(Sindexbuff);                                    //~v780R~
	synqeproc(SYNQEPO_FREE,&Gsyncfg.SYNCqhopenextlist,0,0);        //~v780R~
	synqeproc(SYNQEPO_FREE,&Gsyncfg.SYNCqhlangpathlist,0,0);       //~v780R~
	synqeproc(SYNQEPO_FREE,&Gsyncfg.SYNCqhupdonlyextlist,0,0);     //~v786I~
    memset(&Gsyncfg,0,sizeof(Gsyncfg));                            //~v780I~
    UFREECLEARIFNZ(Spbuffinp);                                     //~v78mI~
    return 0;                                                      //~v780I~
}//syncfgfree                                                      //~v780I~
//****************************************************************
//syngetshcmd                                                      //~v780R~
//  return source-highlight cmd string                             //~v780I~
//****************************************************************
char *syngetshcmd(int Popt)                                        //~v780R~
{
	char *pc;                                                      //~v780I~
//*****************************::
    if (!(Gsyncfg.SYNCflag & SYNCF_OK))                            //~v780I~
    	return 0;                                                  //~v780R~
	pc=Gsyncfg.SYNCshcmd;                                          //~v780R~
UTRACED("cfg cmd",pc,(int)strlen(pc));                                  //~v780I~//~vaz8R~
	return pc;                                                     //~v780R~
}//syngetshcmd                                                     //~v780R~
//**************************************************************** //~v780I~
//syngetshopt                                                      //~v780R~
//  return xeacb option(BG color etc)                              //~v780I~
//**************************************************************** //~v780I~
char *syngetshopt(int Popt)                                        //~v780I~
{                                                                  //~v780I~
	char *pc;                                                      //~v780R~
    int pos;                                                       //~v780R~
	char acbopt[_MAX_PATH+128];                                    //~v780I~
//*****************************::                                  //~v780I~
    if (!(Gsyncfg.SYNCflag & SYNCF_OK))                            //~v780I~
    	return 0;                                                  //~v780R~
    pc=Gsyncfg.SYNCacbopt;                                         //~v780R~
    if (pc)                                                        //~v780I~
    	return pc;                                                 //~v780M~
    pc=acbopt;                                                     //~v780I~
    pos=sprintf(pc,"%s",SH_ACBOPT);                                //~v780R~
    if (Gsyncfg.SYNCflag & SYNCF_BG)                               //~v780R~
    	pos+=sprintf(pc+pos," -B%d",Gsyncfg.SYNCbg);               //~v780R~
    if (Gsyncfg.SYNCflag & SYNCF_FG)                               //~v780R~
    	pos+=sprintf(pc+pos," -F%d",Gsyncfg.SYNCfg);               //~v780R~
    if (!(pc=ustrdup(0,pc,0)))                                     //~v780R~
    	return 0;                                                  //~v780R~
    Gsyncfg.SYNCacbopt=pc;                                         //~v780R~
UTRACED("cfg shopt",pc,(int)strlen(pc));                                //~v780I~//~vaz8R~
	return pc;                                                     //~v780R~
}//syngetshopt                                                     //~v780R~
//**************************************************************** //~v780I~
//syngetwkfnm                                                      //~v780I~
//  return filenames for xeacb                                     //~v780I~
//**************************************************************** //~v780I~
char *syngetwkfnm(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh)           //~v780R~
{                                                                  //~v780I~
    int len;                                                       //~v780I~
    char fpath[_MAX_PATH],*pc;                                     //~v780R~
//*****************************                                    //~v780R~
    if (!(Gsyncfg.SYNCflag & SYNCF_OK))                            //~v780I~
    	return 0;                                                  //~v780R~
    pc=Gsyncfg.SYNCpfnmprefix;                                     //~v780R~
    len=(int)strlen(pc);                                           //~v780R~
    memcpy(fpath,pc,(UINT)len);                                    //~v780R~
    strcpy(fpath+len,SHFNM_ERRORF);                                //~v780R~
    unlink(fpath);	//source-highlight stderr                      //~v780R~
    strcat(fpath+len,SHFNM_ERRORF2);                               //~v780I~
    unlink(fpath);	//xeacb errexit msg                            //~v780I~
    return pc;                                                     //~v780R~
}//syngetwkfnms                                                    //~v780I~
//**************************************************************** //~v780I~
//synsetinpfnm                                                     //~v780I~
//  setup input filename (keep extention name for source-highlight)//~v780I~
//**************************************************************** //~v780I~
int synsetinpfnm(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,char *Ppfpath)//~v780I~
{                                                                  //~v780I~
    char *pc;                                                      //~v780I~
    int pathlen;                                                   //~v780I~
//*****************************                                    //~v780I~
    if (!(Gsyncfg.SYNCflag & SYNCF_OK))                            //~v780I~
    	return 4;                                                  //~v780I~
    pc=Gsyncfg.SYNCpfnmprefix;                                     //~v780R~
    strcpy(Ppfpath,pc);                                            //~v780I~
    strcat(Ppfpath,SHFNM_INPUTF);                                  //~v780I~
    if (*Ppfh->UFHsyntype)                                         //~v780R~
    {                                                              //~v780I~
    	strcat(Ppfpath,".");                                       //~v780R~
    	strcat(Ppfpath,Ppfh->UFHsyntype);                          //~v780I~
    }                                                              //~v780I~
    else                                                           //~v780I~
    {                                                              //~v780I~
        pathlen=PATHLEN(Ppfh->UFHfilename);                        //~v780I~
    	if (pathlen>0 && (pc=strrchr(Ppfh->UFHfilename+pathlen,'.'),pc))//~v780R~
	    	strcat(Ppfpath,pc);                                    //~v780I~
        else                                                       //~v780I~
        {                                                          //~v780I~
            uerrmsg("SyntaxHL:%s has no extension name",0,         //~v780I~
            		Ppfh->UFHfilename);                            //~v780I~
            return 4;                                              //~v780I~
        }                                                          //~v780I~
    }                                                              //~v780I~
    return 0;                                                      //~v780R~
}//synsetinpfnm                                                    //~v780I~
//**************************************************************** //~v780I~
//syngetcsg                                                        //~v780I~
//  read cfg file                                                  //~v780I~
//  rc:1 cfg not found                                             //~v780I~
//**************************************************************** //~v780I~
int syngetcfg(int Popt)                                            //~v780I~
{                                                                  //~v780I~
	FILE *fh;                                                      //~v780I~
	char fpath[_MAX_PATH],*pc;                                     //~v780R~
    char buff[MAX_CONFRECSZ];                                      //~v780I~
    int rc,rc2=0,lineno,ii;                                        //~v780R~
    int len;                                                       //~v78mI~
//*****************************                                    //~v780I~
    if (!(Popt & SGCO_RESET))                                      //~v780I~
        if (Gsyncfg.SYNCflag & SYNCF_OK)                           //~v780R~
            return 0;                                              //~v780R~
//reset previous value ***                                         //~v780I~
	syncfgfree(0);		//reset prev value and free and clear all  //~v780R~
//*buff init                                                       //~v78mI~
    len=RBUFFSZ*5;                                                 //~v78mI~
    Spbuffinp=umalloc((UINT)len);                                  //~v78mI~
    UALLOCCHK(Spbuffinp,UALLOC_FAILED);                            //~v78mR~
	Spbuffcolor=Spbuffinp+RBUFFSZ;                                 //~v78mI~
	Spbuffstyle=Spbuffinp+RBUFFSZ*2;                               //~v78mI~
	Spbuffstylecolor=Spbuffinp+RBUFFSZ*3;                          //~v78mI~
//set default                                                      //~v780I~
    if (!(pc=ustrdup(0,SYN_PGM,0)))                                //~v780I~
        return 4;                                                  //~v780I~
    Gsyncfg.SYNCacbcmd=pc;                                         //~v780I~
	if (!filefullpath(fpath,SHFNM_PREFIX,_MAX_PATH))               //~v780R~
    	return 4;                                                  //~v780I~
    if (!(pc=ustrdup(0,fpath,0)))                                  //~v780R~
    	return 4;                                                  //~v780I~
    Gsyncfg.SYNCpfnmprefix=pc;                                     //~v780R~
    for (pc=Gsyncfg.SYNCcmap,ii=0;ii<SHMAX_COLOR;ii++,pc++)        //~v780R~
    	*pc=(UCHAR)ii;                                             //~v780I~
	Gsyncfg.SYNCenter=-1;	//no threshold for enter triger        //~v786I~
//style default map                                                //~v780I~
	Gsyncfg.SYNCfg=DEFAULT_FG;                                     //~v78mI~
	Gsyncfg.SYNCbg=DEFAULT_BG;                                     //~v78mI~
	Gsyncfg.SYNCbgrevedit=(Gattrtbl[COLOR_ECLIENT_R] >>4);         //~v78oR~
#if defined(LNX) && !defined(XXE)                                  //~v78oI~
	Gsyncfg.SYNCbgrevbrowse=(Gattrtbl[COLOR_ECLIENT_R]>>4);        //~v78oI~
#else                                                              //~v78oI~
	Gsyncfg.SYNCbgrevbrowse=(Gattrtbl[COLOR_CCLIENT_R]>>4);        //~v78oR~
#endif                                                             //~v78oI~
	Gsyncfg.SYNCstyleopt[SYNC_STYLE_BOLD]=SYNC_STYLE_CUI_HIGH|SYNC_STYLE_GUI_EACH;//~v780R~
	Gsyncfg.SYNCstyleopt[SYNC_STYLE_UNDERLINE]=SYNC_STYLE_GUI_EACH;//~v780R~
	Gsyncfg.SYNCstyleopt[SYNC_STYLE_ITALIC]=SYNC_STYLE_GUI_EACH;   //~v780R~
    Gsyncfg.SYNCsmap[SHSTYLE_BOLD      & 0x0f]=SYNC_STYLE_BOLD;    //~v780R~
    Gsyncfg.SYNCsmap[SHSTYLE_UNDERLINE & 0x0f]=SYNC_STYLE_UNDERLINE;//~v780R~
    Gsyncfg.SYNCsmap[SHSTYLE_BLINK     & 0x0f]=SYNC_STYLE_ITALIC;  //~v780R~
//read config file                                                 //~v780I~
	if (!filefullpath(fpath,SHFNM_CONFIG,_MAX_PATH))               //~v780M~
    	return 4;                                                  //~v780M~
//#ifdef ARM                                                         //~va08I~//~vaaDR~
//    else            //ARM dose not support SyntaxHighlight so far  //~va08I~//~vaaDR~
//        return 4;   //avoid file not found msg                     //~va08I~//~vaaDR~
//#endif                                                             //~va08I~//~vaaDR~
//  if (!(fh=fileopen(fpath,"r"))) //fileopen issue not found err  //~v780M~//~vb89R~
    if (!(fh=fileopencreate(0,fpath,"r",SYNCFG_DUMMY_RECORD))) //fileopen issue not found err,if not found create dummy//~vb89R~
    	return 4;                                                  //~v780M~
	lineno=0;                                                      //~v780I~
    while (fgets(buff,MAX_CONFRECSZ,fh))                           //~v780R~
    {                                                              //~v780I~
    	lineno++;                                                  //~v780I~
        USTR_DROPEOL(buff);                                        //~v780I~
		rc=synchkcfgrec(buff);                                     //~v780R~
        if (rc)                                                    //~v780I~
        {                                                          //~v780I~
            if (rc!=8)                                             //~v780I~
            	uerrmsg("%s:lineNo %d err:%s",0,                   //~v780I~
					SHFNM_CONFIG,lineno,buff);                     //~v780I~
        	rc2+=rc;                                               //~v780R~
        }                                                          //~v780I~
    }                                                              //~v780I~
    fclose(fh);                                                    //~v780I~
    if (!synqeproc(SYNQEPO_SCAN|SYNQEPO_ICASE,&Gsyncfg.SYNCqhupdonlyextlist,DEFAULT_EXT,0))//~v786R~
		Gsyncfg.SYNCflag|=SYNCF_DEFAULT_UPDONLY;                   //~v786I~
    if (Gsyncfg.SYNCshcmd)	                                       //~v780I~
		Gsyncfg.SYNCflag|=SYNCF_OK;                                //~v780R~
UTRACED("cfg data",&Gsyncfg,sizeof(SYNCFG));                       //~v780R~
	return rc2;                                                    //~v780R~
}//syngetcfg                                                       //~v780I~
//**************************************************************** //~v780I~
//* chec config record                                             //~v780I~
//* rc:0: 8:errmsg issued                                          //~v780I~
//**************************************************************** //~v780I~
int synchkcfgrec(char *Pdata)                                      //~v780R~
{                                                                  //~v780I~
    char   *pc,*pcv;                                               //~v780I~
    int    wordno,rc,color,opid,chv,ii;                            //~v780R~
//  UCHAR  powkpo[MAX_CONFRECSZ],*powkpop;                         //~v780R~//+vba1R~
    UCHAR  powkpo[MAX_CONFRECSZ*2],*powkpop;                       //+vba1I~
//  char   powkdt[MAX_CONFRECSZ];                                  //~v780I~//+vba1R~
    char   powkdt[MAX_CONFRECSZ*UPODELMTBLSZ];                     //+vba1I~
    void *pvoid;                                                   //~vap0I~
    PUPODELMTBL pupod;                                             //~v780I~
#define SYNCFG_OPENLIST  "OPEN_EXT"                                //~v780I~
#define SYNCFG_ITALICESC "ITALIC_ESC"                              //~v780I~
#define SYNCFG_PATH_EXT  "PATH_EXT_"                               //~v780R~
static UCHAR *Swordtbl="SHCMD\0" "BG\0" "FG\0"                     //~v780I~
                       "BG_EOL\0"                                  //~v780I~
                       "BG_TAB\0"                                  //~v780I~
                       "ACBCMD\0"                                  //~v780I~
                       "OPEN\0"       //7                          //~v780I~
                       "ENTER\0"      //8                          //~v780I~
                       SYNCFG_OPENLIST "\0"   //9                  //~v780R~
                       "BG_UPD\0"   //10                           //~v780I~
                       "CMAP\0"   //11                             //~v780R~
                       SYNCFG_ITALICESC "\0" //12                  //~v780R~
                       "C_BOLD\0"        //13                      //~v780I~
                       "C_UNDERLINE\0"   //14                      //~v780I~
                       "C_ITALIC\0"      //15                      //~v780I~
                       "G_BOLD\0"        //16                      //~v780I~
                       "G_UNDERLINE\0"   //17                      //~v780I~
                       "G_ITALIC\0"      //18                      //~v780I~
                       SYNCFG_PATH_EXT "\0" //19                   //~v780R~
                       "UPDONLY_EXT\0" //20                        //~v786R~
                       "DEBUG\0"       //21                        //~v78aI~
                       "BG_REVERSE_EDIT\0"       //22              //~v78oI~
                       "BG_REVERSE_BROWSE\0"     //23              //~v78oI~
                       "BG_BROWSE\0"             //24              //~v78oR~
                       "SHCMDR\0"            //25                  //~v78GR~
                       "SHCMDA\0"            //26                  //~v7atI~
						;                                          //~v780I~
//*****************                                                //~v780I~
    pc=Pdata+strspn(Pdata," \t");                                  //~v780R~
    if (*pc=='#')    //comment                                     //~v780R~
        return 0;                                                  //~v780I~
//  pupod=(PUPODELMTBL)(ULONG)powkdt;  //out delmtbl               //~v780R~//~vafkR~
//  pupod=(PUPODELMTBL)(ULPTR)powkdt;  //out delmtbl               //~vafkI~//~vap0R~
    pvoid=powkdt;  //out delmtbl                                   //~vap0R~
    pupod=(PUPODELMTBL)pvoid;  //out delmtbl                       //~vap0I~
    powkpop=powkpo;                     //out parseout data        //~v780R~
    if ((rc=uparse2(pc,&pupod,&powkpop,&wordno,UPARSE2USEAREAPARM,"="))>=4)//~v780R~
        return rc;          //umalloc failed                       //~v780I~
    if (wordno<2)                                                  //~v780I~
    {	                                                           //~v780I~
    	if (!wordno) 	//null line                                //~v780I~
        	return 0;                                              //~v780I~
    	if (wordno==1 && !stricmp(powkpo,SYNCFG_OPENLIST))         //~v780R~
        	return 0;		//allow null opd                       //~v780I~
        return 4;                                                  //~v780I~
    }                                                              //~v780I~
    pc=powkpo;                                                     //~v780I~
    pcv=pc+strlen(pc)+1;                                           //~v780R~
    if (strlen(pc)>=3 && !memicmp(pc,"RGB",3))                     //~v780I~
        return syngetrgbparm(pc+3,pcv);                            //~v780I~
    if (strlen(pc)>sizeof(SYNCFG_PATH_EXT)-1 && !memicmp(pc,SYNCFG_PATH_EXT,sizeof(SYNCFG_PATH_EXT)-1))//~v780R~
        return syngetpathparm(pc+sizeof(SYNCFG_PATH_EXT)-1,pcv);   //~v780R~
    opid=wordtblisrch(pc,Swordtbl);                                //~v780I~
    chv=toupper(*pcv);                                             //~v780I~
    switch(opid)                                                   //~v780I~
    {                                                              //~v780I~
    case 0: //err                                                  //~v780I~
        return 4;                                                  //~v780I~
    case 1: //SHCMD                                                //~v780I~
    case 6: //SHCMD                                                //~v780I~
    case 25: //SHCMDR                                              //~v78GR~
    case 26: //SHCMDA                                              //~v7atI~
        if (strlen(pcv)>SHMAX_CMDLEN )                             //~v780I~
        {                                                          //~v780I~
            uerrmsg("SyntaxHL:Max command length is %d\n",0,       //~v780R~
                    SHMAX_CMDLEN);                                 //~v780I~
            return 8;                                              //~v780I~
        }                                                          //~v780I~
        if (!(pc=ustrdup(0,pcv,0)))                                //~v780R~
            return 4;                                              //~v780I~
//  	if (opid==1)                                               //~v78GR~
//  	if (opid==1||opid==25)                                     //~v78GR~//~v7atR~
    	if (opid==1||opid==25||opid==26)                           //~v7atI~
        {                                                          //~v780I~
	        UFREEIFNZ(Gsyncfg.SYNCshcmd);                          //~v780R~
	        Gsyncfg.SYNCshcmd=pc;                                  //~v780I~
        }                                                          //~v780I~
        else                                                       //~v780I~
        {                                                          //~v780I~
	        UFREEIFNZ(Gsyncfg.SYNCacbcmd);                         //~v780I~
	        Gsyncfg.SYNCacbcmd=pc;                                 //~v780I~
        }                                                          //~v780I~
		if (opid==1)    //SHCMD                                    //~v78GR~
	        Gsyncfg.SYNCflag|=SYNCF_NORESIDENT;                    //~v78GR~
        else                                                       //~v78GR~
		if (opid==25)                                              //~v78GR~
	        Gsyncfg.SYNCflag&=~SYNCF_NORESIDENT;                   //~v78GR~
        else                                                       //~v7atI~
		if (opid==26)        //andre-simon's Highlight             //~v7atI~
	        Gsyncfg.SYNCflag|=(SYNCF_NORESIDENT|SYNCF_HIGHLIGHT2); //~v7atI~
        break;                                                     //~v780I~
    case 2: //BG                                                   //~v780I~
		if (syngetcolorparm(0,"BG",pcv,SHMAX_COLOR_BG,&color))     //~v780I~
            return 8;  //8:errmsg issued                           //~v780R~
        Gsyncfg.SYNCbg=(UCHAR)color;                               //~v780R~
        Gsyncfg.SYNCflag|=SYNCF_BG;                                //~v780R~
        break;                                                     //~v780I~
    case 3: //FG                                                   //~v780I~
		if (syngetcolorparm(0,"FG",pcv,SHMAX_COLOR,&color))        //~v780I~
            return 8;                                              //~v780R~
        Gsyncfg.SYNCfg=(UCHAR)color;                               //~v780R~
        Gsyncfg.SYNCflag|=SYNCF_FG;                                //~v780R~
        break;                                                     //~v780I~
    case 4: //BG_EOL                                               //~v780I~
		if (syngetcolorparm(0,"BG_EOL",pcv,SHMAX_COLOR_BG,&color)) //~v780I~
            return 8;                                              //~v780R~
        Gsyncfg.SYNCbgeol=(UCHAR)color;                            //~v780R~
        Gsyncfg.SYNCflag|=SYNCF_BG_EOL;                            //~v780I~
        break;                                                     //~v780I~
    case 5: //BG_TAB                                               //~v780I~
		if (syngetcolorparm(0,"BG_TAB",pcv,SHMAX_COLOR_BG,&color)) //~v780I~
            return 8;                                              //~v780R~
        Gsyncfg.SYNCbgtab=(UCHAR)color;                            //~v780R~
        Gsyncfg.SYNCflag|=SYNCF_BG_TAB;                            //~v780I~
        break;                                                     //~v780I~
    case 7: //OPEN                                                 //~v780R~
		if (chv=='Y')                                              //~v780I~
	        Gsyncfg.SYNCflag|=SYNCF_OPEN;                          //~v780I~
        else                                                       //~v780I~
		if (chv=='A')                                              //~v780I~
	        Gsyncfg.SYNCflag|=SYNCF_OPEN|SYNCF_OPENALL;            //~v780I~
        else                                                       //~v780I~
		if (chv!='N')                                              //~v780I~
            return 4;   //                                         //~v780I~
        break;                                                     //~v780I~
    case 8: //ENTER                                                //~v780I~
	    Gsyncfg.SYNCenter=atoi(pcv);                               //~v780M~
		if (!Gsyncfg.SYNCenter && !isdigit(chv))                   //~v780R~
        	return 4;                                              //~v780I~
        break;                                                     //~v780I~
    case 9: //OPEN_EXT                                             //~v780I~
        for (pc=pcv,ii=1;ii<wordno && *pc;ii++,pc+=strlen(pc)+1)   //~v780R~
        {                                                          //~v780I~
        	if (rc=synqeproc(SYNQEPO_ENQ,&Gsyncfg.SYNCqhopenextlist,pc,0),rc)//~v780R~
            	break;                                             //~v780I~
        }                                                          //~v780I~
        break;                                                     //~v780I~
    case 10: //BG_UPD                                              //~v780I~
		if (syngetcolorparm(0,"BG_UPD",pcv,SHMAX_COLOR_BG,&color)) //~v780I~
            return 8;                                              //~v780I~
        Gsyncfg.SYNCbgupd=(UCHAR)color;                            //~v780I~
        Gsyncfg.SYNCflag|=SYNCF_BG_UPD;                            //~v780I~
        break;                                                     //~v780I~
    case 11: //CMAP                                                //~v780I~
		return syngetcmapparm(pcv);                                //~v780I~
    case 12: //ITALIC_ESC                                          //~v780I~
        if (!isdigit(chv))                                         //~v780I~
        	return 4;                                              //~v780I~
        if (chv==SHSTYLE_NORMAL                                    //~v780R~
        ||  chv==SHSTYLE_BOLD                                      //~v780R~
        ||  chv==SHSTYLE_UNDERLINE)                                //~v780R~
        {                                                          //~v780I~
            uerrmsg("SyntaxHL:%s should be one digit other than %c,%c and %c",0,//~v780R~
            		SYNCFG_ITALICESC,SHSTYLE_NORMAL,SHSTYLE_BOLD,SHSTYLE_UNDERLINE);//~v780R~
            return 8;                                              //~v780I~
        }                                                          //~v780I~
        Gsyncfg.SYNCsmap[chv-'0']=SYNC_STYLE_ITALIC;               //~v780I~
        if (chv!=SHSTYLE_BLINK)	//default is blink                 //~v780I~
        	Gsyncfg.SYNCsmap[SHSTYLE_BLINK-'0']=0;	//reset default//~v780I~
        break;                                                     //~v780I~
    case 13: //C_BOLD                                              //~v780I~
    case 14: //C_UNDERLINE                                         //~v780I~
    case 15: //C_ITALIC                                            //~v780I~
    	ii=opid-12;                                                //~v780I~
//      Gsyncfg.SYNCstyleopt[ii]=0;                                //~v78bR~
//      Gsyncfg.SYNCstyleopt[ii]&=~SYNC_STYLE_CUI_HIGH;            //~v78bI~//~vaz8R~
        Gsyncfg.SYNCstyleopt[ii]&=(UCHAR)(~SYNC_STYLE_CUI_HIGH);   //~vaz8I~
        if (chv=='H')                                              //~v780I~
            Gsyncfg.SYNCstyleopt[ii]|=SYNC_STYLE_CUI_HIGH;         //~v78bR~
        else                                                       //~v780I~
        if (chv!='N')                                              //~v780R~
        	return 4;                                              //~v780I~
        break;                                                     //~v780I~
    case 16: //G_BOLD                                              //~v780I~
    case 17: //G_UNDERLINE                                         //~v780I~
    case 18: //G_ITALIC                                            //~v780I~
    	ii=opid-15;       //1:bold                                 //~v780R~
//      Gsyncfg.SYNCstyleopt[ii]=0;                                //~v78bR~
//      Gsyncfg.SYNCstyleopt[ii]&=~(SYNC_STYLE_GUI_HIGH|SYNC_STYLE_GUI_EACH);//~v78bI~//~vaz8R~
        Gsyncfg.SYNCstyleopt[ii]&=(UCHAR)(~(SYNC_STYLE_GUI_HIGH|SYNC_STYLE_GUI_EACH));//~vaz8I~
        for (pc=pcv;*pc;pc++)                                      //~v780I~
        {                                                          //~v780I~
        	switch(toupper(*pc))                                   //~v780I~
            {                                                      //~v780I~
        	case 'H':                                              //~v780I~
	            Gsyncfg.SYNCstyleopt[ii]|=SYNC_STYLE_GUI_HIGH;     //~v78bR~
            	break;                                             //~v780I~
        	case 'Y':                                              //~v780I~
    	        Gsyncfg.SYNCstyleopt[ii]|=SYNC_STYLE_GUI_EACH;     //~v780I~
            	break;                                             //~v780I~
        	case 'N':                                              //~v780I~
            	break;                                             //~v780I~
            default:                                               //~v780I~
            	return 4;                                          //~v780I~
            }                                                      //~v780I~
        }                                                          //~v780I~
        break;                                                     //~v780I~
    case 20: //UPDONLY_EXT                                         //~v786R~
        for (pc=pcv,ii=1;ii<wordno && *pc;ii++,pc+=strlen(pc)+1)   //~v786I~
        {                                                          //~v786I~
        	if (rc=synqeproc(SYNQEPO_ENQ,&Gsyncfg.SYNCqhupdonlyextlist,pc,0),rc)//~v786I~
            	break;                                             //~v786I~
        }                                                          //~v786I~
        break;                                                     //~v786I~
    case 21: //DEBUG                                               //~v78aI~
      if (chv=='1')                                                //~v78mI~
    	Gsyncfg.SYNCflag|=SYNCF_DEBUG1;                            //~v78aI~
        break;                                                     //~v78aI~
    case 22: //BG_REVERSE_EDIT                                     //~v78oI~
		if (syngetcolorparm(0,"BG_REVERSE_EDIT",pcv,SHMAX_COLOR_BG,&color))//~v78oI~
            return 8;                                              //~v78oI~
		Gsyncfg.SYNCbgrevedit=(UCHAR)color;                        //~v78oI~
        break;                                                     //~v78oI~
    case 23: //BG_REVERSE_BROWSE                                   //~v78oI~
		if (syngetcolorparm(0,"BG_REVERSE_BROWSE",pcv,SHMAX_COLOR_BG,&color))//~v78oI~
            return 8;                                              //~v78oI~
		Gsyncfg.SYNCbgrevbrowse=(UCHAR)color;                      //~v78oI~
        break;                                                     //~v78oI~
    case 24: //BG_BROWSE                                           //~v78oR~
        if (syngetcolorparm(0,"BG_BROWSE",pcv,SHMAX_COLOR_BG,&color))//~v78oR~
            return 8;                                              //~v78oR~
        Gsyncfg.SYNCbgbrowse=(UCHAR)color;                         //~v78oR~
        Gsyncfg.SYNCflag|=SYNCF_BG_BROWSE;                         //~v78oR~
        break;                                                     //~v78oR~
    }                                                              //~v780I~
    return 0;                                                      //~v780R~
}//synchkcfgrec                                                    //~v780R~
//**************************************************************** //~v780I~
//* open string q-list handling                                    //~v780I~
//* rc=0:found for scan req                                        //~v780I~
//**************************************************************** //~v780I~
int synqeproc(int Popt,PUQUEH Ppqh,char *Pstr,PUQUEE *Pppqe)       //~v780R~
{                                                                  //~v780I~
	int len,pos;                                                   //~v780R~
    PSYNQE pqe;                                                    //~v780I~
    UQUEH *pqh;                                                    //~v780I~
//************************                                         //~v780I~
    pqh=Ppqh;                                                      //~v780R~
	                                                               //~v780I~
	if (Popt & SYNQEPO_FREE)                                       //~v780R~
    {                                                              //~v780I~
    	UQUFREE(pqh);                                              //~v780I~
    }                                                              //~v780I~
	if (Popt & SYNQEPO_ENQ)                                        //~v780I~
    {                                                              //~v780I~
//      len=strlen(Pstr);                                          //~v780I~//~vaz8R~
        len=(int)strlen(Pstr);                                     //~vaz8I~
        if (!len)                                                  //~v780I~
            return 0;                                              //~v780R~
//      pqe=(PSYNQE)ucalloc(1,len+SYNQESZ);                        //~v780R~//~vaz8R~
        pqe=(PSYNQE)ucalloc(1,(size_t)len+SYNQESZ);                //~vaz8I~
        UALLOCCHK(pqe,UALLOC_FAILED);                              //~v780I~
        strcpy(pqe->SYNQEstr,Pstr);                                //~v780I~
        UENQ(UQUE_END,pqh,pqe);                                    //~v780I~
		if (Pppqe)                                                 //~v780I~
//	     	*Pppqe=(PUQUEE)(ULONG)pqe;                             //~v780R~//~vafkR~
        	*Pppqe=(PUQUEE)(ULPTR)pqe;                             //~vafkI~
        return 0;                                                  //~v780I~
    }                                                              //~v780I~
	if (Popt & SYNQEPO_SCAN)                                       //~v780I~
    {                                                              //~v780I~
        pos=(Popt&SYNQEPO_SCANOFFS_MASK);                          //~v780R~
    	for (pqe=UGETQTOP(pqh);pqe;pqe=UGETQNEXT(pqe))             //~v780I~
        {                                                          //~v780I~
                                                                   //~v786I~
//      	if (!LFNM_STRCMP(pqe->SYNQEstr+pos,Pstr))              //~v786R~
			if (((Popt & SYNQEPO_ICASE) && !stricmp(pqe->SYNQEstr+pos,Pstr))//~v786R~
           	||  (!LFNM_STRCMP(pqe->SYNQEstr+pos,Pstr))             //~v786I~
            )                                                      //~v786I~
            {                                                      //~v780I~
		        if (Pppqe)                                         //~v780I~
//		        	*Pppqe=(PUQUEE)(ULONG)pqe;                     //~v780I~//~vafkR~
		        	*Pppqe=(PUQUEE)(ULPTR)pqe;                     //~vafkI~
            	return 0;                                          //~v780I~
            }                                                      //~v780I~
        }                                                          //~v780I~
    }                                                              //~v780I~
    return 4;                                                      //~v780I~
}//synqeproc                                                       //~v780I~
//**************************************************************** //~v780I~
//* get color parm                                                 //~v780I~
//* rc:0: 8:errmsg issued                                          //~v780I~
//**************************************************************** //~v780I~
int syngetcolorparm(int Popt,char *Pparmname,char *Pparmvalue,int Pmaxvalue,int *Ppcolor)//~v780R~
{                                                                  //~v780I~
//  int rc=0,color;                                                //~vaf9R~
    int rc=0,color=0;                                              //~vaf9I~
//***************                                                  //~v780I~
	if (!isdigit(*Pparmvalue))                                     //~v780I~
    	rc=8;                                                      //~v780R~
    else                                                           //~v780I~
    {                                                              //~v780I~
        color=atoi(Pparmvalue);                                    //~v780I~
        if (color<0||color>=Pmaxvalue)                             //~v780R~
        	rc=8;                                                  //~v780I~
    }                                                              //~v780I~
    if (rc)                                                        //~v780I~
    	uerrmsg("SyntaxHL:%s value(%s) is not from %d to %d",0,    //~v780R~
                    Pparmname,Pparmvalue,0,Pmaxvalue-1);           //~v780I~
    *Ppcolor=color;                                                //~v780I~
    return rc;                                                     //~v780I~
}//syngetcolorparm                                                 //~v780I~
//**************************************************************** //~v780I~
//* get color map parm                                             //~v780R~
//**************************************************************** //~v780I~
int syngetcmapparm(char *Ppcmap)                                   //~v780I~
{                                                                  //~v780I~
    int ii,colno;                                                  //~v780I~
	UCHAR *pc,usermap[SHMAX_COLOR];                                //~v780I~
//***************                                                  //~v780I~
    memcpy(usermap,Gsyncfg.SYNCcmap,SHMAX_COLOR);                  //~v780I~
    for (pc=Ppcmap,ii=0;*pc && ii<SHMAX_COLOR;ii++)                //~v780R~
    {                                                              //~v780I~
    	if (isdigit(*pc) && isdigit(*(pc+1)))                      //~v780I~
        {                                                          //~v780I~
        	colno=(*pc&0x0f)*10+(*(pc+1)&0x0f);                    //~v780I~
            if (colno>=SHMAX_COLOR)                                //~v780I~
            	return 4;                                          //~v780I~
//          usermap[ii]=colno;                                     //~v780I~//~vaz8R~
            usermap[ii]=(UCHAR)colno;                              //~vaz8I~
        }                                                          //~v780I~
        else                                                       //~v780I~
        if (!(*pc=='_' && *(pc+1)=='_'))                           //~v780I~
            return 4;                                              //~v780I~
        pc+=2;                                                     //~v780I~
        if (!*pc)                                                  //~v780I~
        	break;                                                 //~v780I~
        if (*pc!='.')                                              //~v780I~
            return 4;                                              //~v780I~
        pc++;                                                      //~v780I~
    }                                                              //~v780I~
    if (*pc)                                                       //~v780I~
    	return 4;	//over 16 entry                                //~v780I~
    memcpy(Gsyncfg.SYNCcmap,usermap,SHMAX_COLOR);                  //~v780I~
    return 0;                                                      //~v780I~
}//syngetcmapparm                                                  //~v780I~
//**************************************************************** //~v780I~
//* get rgb parm                                                   //~v780I~
//**************************************************************** //~v780I~
int syngetrgbparm(char *Ppcol,char *Pprgb)                         //~v780R~
{                                                                  //~v780I~
    int colno,rc;                                                  //~v780R~
    ULONG ulrgb;                                                   //~v780I~
//***************                                                  //~v780I~
	if (rc=syngetcolorparm(0,"RGBn",Ppcol,SHMAX_COLOR,&colno),rc)  //~v780R~
    	return rc;                                                 //~v780I~
    if (strlen(Pprgb)!=6||ux2l(Pprgb,&ulrgb))                      //~v780R~
    {                                                              //~v780I~
    	uerrmsg("SyntaxHL:RGB value(%s) is not 6 hexdigit",0,      //~v780R~
        			Pprgb);                                        //~v780R~
    	return 8;                                                  //~v780I~
    }                                                              //~v780I~
#ifdef WXEXXE                                                      //~v780I~
    Gsyncfg.SYNCrgb[colno]=(int)ulrgb|WXE_SYNTAXRGB;	           //~v780R~
#endif                                                             //~v780I~
    return 0;                                                      //~v780I~
}//syngetrgbparm                                                   //~v780I~
//**************************************************************** //~v780I~
//* get rgb parm                                                   //~v780I~
//**************************************************************** //~v780I~
int syngetpathparm(char *Plangtype,char *Ppath)                    //~v780I~
{                                                                  //~v780I~
    int rc,len;                                                    //~v780R~
    char fpath[MAX_SYNTYPE+1+_MAX_PATH];                           //~v780I~
    PUQUEE   pqe;                                                  //~v780I~
    PSYNQE   psqe;                                                 //~v780I~
//***************                                                  //~v780I~
//  len=strlen(Plangtype);                                         //~v780R~//~vaz8R~
    len=(int)strlen(Plangtype);                                    //~vaz8I~
    if (len>MAX_SYNTYPE)                                           //~v780I~
    {                                                              //~v780I~
    	uerrmsg("SyntaxHL:invalid lang type(%s), max langtype is %d",0,//~v780R~
        			Plangtype,MAX_SYNTYPE);                        //~v780R~
    	return 8;                                                  //~v780I~
    }                                                              //~v780I~
	sprintf(fpath,"%-*.*s %s",MAX_SYNTYPE,MAX_SYNTYPE,Plangtype,Ppath);//~v780R~
    if (rc=synqeproc(SYNQEPO_ENQ,&Gsyncfg.SYNCqhlangpathlist,fpath,&pqe),rc)//~v780R~
    	return rc;                                                 //~v780I~
//  psqe=(PSYNQE)(ULONG)pqe;                                       //~v780I~//~vafkR~
    psqe=(PSYNQE)(ULPTR)pqe;                                       //~vafkI~
    *(psqe->SYNQEstr+len)=0;	//for strcpy                       //~v780R~
    return 0;                                                      //~v780I~
}//syngetrgbparm                                                   //~v780I~
//**************************************************************** //~v780M~
// system call                                                     //~v780M~
//*rc   :0                                                         //~v780M~
//**************************************************************** //~v780M~
int synkicksh(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,char *Ppfnmprefix,char *Ppfnminput,UCHAR *Plangtype)//~v780R~
{                                                                  //~v780M~
	char cmdstr[SHMAX_CMDLEN+_MAX_PATH*3+256];                     //~v780M~
    char fpatherr[_MAX_PATH];                                      //~v780M~
    char *pshcmd,*pshopt,*pacbcmd;                                 //~v780R~
    FILE *fh;                                                      //~v780M~
    char errmsg[256];                                              //~v780M~
    int rc,len;                                                    //~v780M~
//  char langtype[MAX_SYNTYPE+8];                                  //~v780R~
//*******************                                              //~v780M~
    if (!(Gsyncfg.SYNCflag & SYNCF_USEACB))   //new logic          //~v78mI~
		return synkicksh2(Popt,Ppcw,Ppfh,Ppfnmprefix,Ppfnminput,Plangtype);//~v78mI~
	if (!(pshcmd=syngetshcmd(0)))                                  //~v780M~
    	return 4;                                                  //~v780M~
	if (!(pshopt=syngetshopt(0)))                                  //~v780M~
    	return 4;                                                  //~v780M~
//    if (*Plangtype)                                              //~v780R~
//        sprintf(langtype,"-s %s",Plangtype);  //source lang type //~v780R~
//    else                                                         //~v780R~
//        *langtype=0;                                             //~v780R~
    strcpy(fpatherr,Ppfnmprefix);                                  //~v780M~
    strcat(fpatherr,SHFNM_ERRORF);      //source-highlight stderr  //~v780R~
    pacbcmd=Gsyncfg.SYNCacbcmd;                                    //~v780I~
	sprintf(cmdstr,"%s -i %s %s 2>%s | %s -p%s %s",                //~v780R~
    		pshcmd,/*langtype,*/                                   //~v780R~
			Ppfnminput,SH_DEFAULT_CMDOPT,fpatherr,                 //~v780I~
			pacbcmd,Ppfnmprefix,pshopt);                           //~v780R~
    rc=usystem2(UPROC_KEEPMODE/*keep console mode when not syscmd server*/,cmdstr);//~v780R~
    strcpy(fpatherr,Ppfnmprefix);                                  //~v780I~
    strcat(fpatherr,SHFNM_ERRORF2);    //xeacb uerrexit msg  	   //~v780I~
    fh=fopen(fpatherr,"r");                                        //~v780M~
    if (fh)		//err file exist                                   //~v780M~
    {                                                              //~v780M~
    	if (fgets(errmsg,sizeof(errmsg),fh))                       //~v780M~
        {                                                          //~v780M~
        	if (memcmp(errmsg,SIGN_COMPLETED,sizeof(SIGN_COMPLETED)-1))//~v780M~
            {                                                      //~v780M~
                len=(int)strlen(errmsg);                           //~v780R~
                if (len && *(errmsg+len-1)=='\n')                  //~v780M~
                	*(errmsg+len-1)=0;                             //~v780M~
        		uerrmsg("SyntaxHL:%s failed by \"%s\"",0,          //~v780R~
						SYN_PGM,errmsg);                           //~v780M~
             	rc=4;                                              //~v780M~
            }                                                      //~v780M~
            else                                                   //~v780M~
            {                                                      //~v780M~
            	ugeterrmsg();	//clear usystem done msg           //~v780M~
            	rc=0;                                              //~v780M~
            }                                                      //~v780M~
        }                                                          //~v780M~
        fclose(fh);                                                //~v780M~
    }                                                              //~v780M~
    else                                                           //~v780M~
    	if (!rc)	//usyystem rc=ok                               //~v780M~
        {                                                          //~v780M~
        	uerrmsg("SyntaxHL:external process failed",0);         //~v780R~
            rc=4;                                                  //~v780M~
        }                                                          //~v780M~
    return rc;                                                     //~v780M~
}//synkicksh                                                       //~v780M~
//**************************************************************** //~v78mI~
// system call (no xeacb call)                                     //~v78mR~
//*rc   :0                                                         //~v78mI~
//**************************************************************** //~v78mI~
int synkicksh2(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,char *Ppfnmprefix,char *Ppfnminput,UCHAR *Plangtype)//~v78mI~
{                                                                  //~v78mI~
	char cmdstr[SHMAX_CMDLEN+_MAX_PATH*3+256];                     //~v78mI~
    char fpatherr[_MAX_PATH];                                      //~v78mI~
    char fpathout[_MAX_PATH];                                      //~v78mI~
    char *pshcmd;                                                  //~v78mR~
    FILE *fh;                                                      //~v78mI~
    char errmsg[256];                                              //~v78mI~
    int rc,len;                                                    //~v78mI~
    char *cmdopt;                                                  //~v7atI~
//  char langtype[MAX_SYNTYPE+8];                                  //~v78mI~
//*******************                                              //~v78mI~
	if (!(pshcmd=syngetshcmd(0)))                                  //~v78mI~
    	return 4;                                                  //~v78mI~
    strcpy(fpathout,Ppfnmprefix);                                  //~v78mI~
    strcat(fpathout,SHFNM_ESCOUTF);    //S.H outfile(lang=esc)     //~v78mI~
    strcpy(fpatherr,Ppfnmprefix);                                  //~v78mI~
    strcat(fpatherr,SHFNM_ERRORF);      //source-highlight stderr  //~v78mI~
  	if (Gsyncfg.SYNCflag & SYNCF_HIGHLIGHT2)  //andre-simon's Highlight//~v7atI~
		cmdopt=SH_DEFAULT_CMDOPT2;	/*-A*/                         //~v7atR~
    else                                                           //~v7atI~
		cmdopt=SH_DEFAULT_CMDOPT;	/*-f esc*/                     //~v7atR~
	sprintf(cmdstr,"%s %s -i %s -o %s 2>%s", //langtype is by temp input file extention//~v78mI~
    		pshcmd,/*langtype is by temp input file extention*/    //~v78mI~
//  		SH_DEFAULT_CMDOPT/*-f esc*/,                           //~v78mI~//~v7atR~
    		cmdopt,                                                //~v7atI~
			Ppfnminput,                                            //~v78mI~
			fpathout,                                              //~v78mI~
			fpatherr);                                             //~v78mI~
  if (!(Gsyncfg.SYNCflag & SYNCF_NORESIDENT))                      //~v78GR~
	rc=xesyn_shreq(0,cmdstr);                                      //~v78GR~
  else                                                             //~v78GR~
//  rc=usystem2(UPROC_KEEPMODE/*keep console mode when not syscmd server*/,cmdstr);//~v78mI~//~va08R~
    rc=usystem2(UPROC_KEEPMODE/*keep console mode when not syscmd server*/|UPROC_NOOKMSG,cmdstr);//~va08I~
    fh=fopen(fpatherr,"r");                                        //~v78mI~
    if (fh)		//err file exist                                   //~v78mI~
    {                                                              //~v78mI~
    	if (fgets(errmsg,sizeof(errmsg),fh))                       //~v78mI~
        {                                                          //~v78mI~
        	len=(int)strlen(errmsg);                               //~v78mI~
            if (len && *(errmsg+len-1)=='\n')                      //~v78mI~
            {                                                      //~v78mI~
            	len--;                                             //~v78mI~
                *(errmsg+len)=0;                                   //~v78mI~
            }                                                      //~v78mI~
            if (len>0)                                             //~v78mI~
            {                                                      //~v78mI~
//      		uerrmsg("SyntaxHL:%s failed by \"%s\"",0,          //~v78sR~
//  					SYN_PGM,errmsg);                           //~v78sR~
        		uerrmsg("SyntaxHL:failed by \"%s\"",0,             //~v78sI~
    					errmsg);                                   //~v78sI~
            	rc=4;                                              //~v78mI~
            }                                                      //~v78mI~
        }                                                          //~v78mI~
        fclose(fh);                                                //~v78mI~
    }                                                              //~v78mI~
    else                                                           //~v78mI~
    {                                                              //~v78GR~
      if ((Gsyncfg.SYNCflag & SYNCF_NORESIDENT))   //NORESIDENT    //~v78GR~
    	if (!rc)	//usyystem rc=ok                               //~v78mI~
        {                                                          //~v78mI~
        	uerrmsg("SyntaxHL:external process failed",0);         //~v78mI~
            rc=4;                                                  //~v78mI~
        }                                                          //~v78mI~
    }                                                              //~v78GR~
//    if (!rc)                                                       //~v78mI~//~va08R~
//    	ugeterrmsg();	//clear usystem done msg                   //~v78mI~//~va08R~
    return rc;                                                     //~v78mI~
}//synkicksh2                                                      //~v78mR~
//**************************************************************** //~v780I~
//synopencf                                                        //~v780I~
//  open color info file                                           //~v780I~
//**************************************************************** //~v780I~
int synopencf(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,int *Pphandle) //~v780R~
{                                                                  //~v780I~
    char fpath[_MAX_PATH],*pc,colortbl[sizeof(SIGN_HEAD)-1];       //~v780R~
    FILE *fhc,*fhx;                                                //~v780R~
//    PUFILEC pfc;                                                 //~v78oR~
    FILEFINDBUF3 ffb3;                                             //~v780I~
    int len;                                                       //~v780I~
    SHINDEX indexrec[2];                                           //~v780R~
//  int browsesw;                                                  //~v78oR~
//*****************************                                    //~v780I~
    pc=Gsyncfg.SYNCpfnmprefix;                                     //~v780R~
    len=(int)strlen(pc);                                           //~v780R~
    memcpy(fpath,pc,(UINT)len);                                    //~v780R~
  if (!(Gsyncfg.SYNCflag & SYNCF_USEACB))   //new logic            //~v78mI~
  {                                                                //~v78mI~
    strcpy(fpath+len,SHFNM_ESCOUTF);                               //~v78mI~
    if (!(fhc=fileopen(fpath,"r")))                                //~v78mI~
    	return 4;                                                  //~v78mI~
    Sfhcolor=fhc;                                                  //~v78mI~
    Sopenctr++;                                                    //~v78mI~
//    browsesw=(Popt & SYNCPO_BROWSE);                             //~v78oR~
//    if (!browsesw)                                               //~v78oR~
//    {                                                            //~v78oR~
//        pfc=Ppcw->UCWpfc;                                        //~v78oR~
//        if (pfc && UCBITCHK(pfc->UFCflag,UFCFBROWSE))            //~v78oR~
//            browsesw=1;                                          //~v78oR~
//    }                                                            //~v78oR~
//  if (browsesw && (Gsyncfg.SYNCflag & SYNCF_FG_BROWSE))          //~v78oR~
//    Sdeffg=Gsyncfg.SYNCfgbrowse;                                 //~v78oR~
//  else                                                           //~v78oR~
	Sdeffg=Gsyncfg.SYNCfg;                                         //~v78mR~
//  if (browsesw && (Gsyncfg.SYNCflag & SYNCF_BG_BROWSE))          //~v78oR~
//    Sdefbg=Gsyncfg.SYNCbgbrowse;                                 //~v78oR~
//  else                                                           //~v78oR~
//    Sdefbg=Gsyncfg.SYNCbg;                                       //~v78oR~
	Sfg=Sdeffg;                                                    //~v78mI~
	Sbg=Sdefbg;                                                    //~v78mI~
	Sstyle=SHSTYLE_NORMAL;                                         //~v78mI~
    Slineno=0;                                                     //~v78mI~
  }                                                                //~v78mI~
  else                                                             //~v78mI~
  {                                                                //~v78mI~
//inedx rec                                                        //~v780I~
    strcpy(fpath+len,SHFNM_INDEXF);                                //~v780I~
    if (!(fhx=fileopen(fpath,"rb")))                               //~v780I~
    	return 4;                                                  //~v780M~
    if (ufstat(fpath,&ffb3))                                       //~v780I~
    {                                                              //~v780I~
    	fclose(fhx);                                               //~v780I~
    	return 4;                                                  //~v780I~
    }                                                              //~v780I~
    Sindexfsz=(UINT)ffb3.cbFile;                                   //~v780R~
    if (!fread(&indexrec,SHINDEXSZ*2,1/*count*/,fhx))              //~v780R~
    {	                                                           //~v780I~
    	fclose(fhx);                                               //~v780I~
    	ufileapierr("fread",fpath,errno);                          //~v780I~
        return 4;                                                  //~v780I~
    }                                                              //~v780I~
    if (memcmp(indexrec,SIGN_HEAD,SHINDEXSZ))                      //~v780I~
    {                                                              //~v780I~
    	fclose(fhx);                                               //~v780I~
    	uerrmsg("SyntaxHL:Invalid header record on index file(%s)",0,//~v780R~
					fpath);                                        //~v780I~
        return 4;                                                  //~v780I~
    }                                                              //~v780I~
//color file                                                       //~v780I~
    strcpy(fpath+len,SHFNM_COLORF);                                //~v780I~
    if (!(fhc=fileopen(fpath,"rb")))                               //~v780I~
    {                                                              //~v780I~
    	fclose(fhx);                                               //~v780I~
    	return 4;                                                  //~v780I~
    }                                                              //~v780I~
    if (ufstat(fpath,&ffb3))                                       //~v780I~
    {                                                              //~v780I~
    	fclose(fhc);                                               //~v780I~
    	fclose(fhx);                                               //~v780I~
    	return 4;                                                  //~v780I~
    }                                                              //~v780I~
    Scolorfsz=(ULONG)ffb3.cbFile;                                  //~v780R~
    if (!fread(colortbl,sizeof(colortbl),1/*count*/,fhc))          //~v780I~
    {                                                              //~v780I~
    	fclose(fhx);                                               //~v780I~
    	fclose(fhc);                                               //~v780I~
    	ufileapierr("fread",fpath,errno);                          //~v780I~
        return 4;                                                  //~v780I~
    }                                                              //~v780I~
    if (memcmp(colortbl+sizeof(int)/*lenfld*/,SIGN_HEAD,SIGN_HEAD_CHKLEN))//~v780R~
    {                                                              //~v780I~
    	fclose(fhx);                                               //~v780I~
    	fclose(fhc);                                               //~v780I~
    	uerrmsg("SyntaxHL:Invalid header record on color info file(%s)",0,//~v780R~
					fpath);                                        //~v780I~
        return 4;                                                  //~v780I~
    }                                                              //~v780I~
    Sfhcolor=fhc;                                                  //~v780R~
    Sfhindex=fhx;                                                  //~v780R~
    Sopenctr++;                                                    //~v780I~
	Sindexbuffrecnotop=0;                                          //~v780I~
	Sindexbuffrecnoend=0;                                          //~v780I~
	Scolorfoffs=0;                                                 //~v780R~
  }//old logic                                                     //~v78mI~
    Ssynstat2|=SYNS2OPEN;                                          //~v780I~
    *Pphandle=Sopenctr;                                            //~v780M~
    return 0;                                                      //~v780I~
}//synopencf                                                       //~v780R~
//**************************************************************** //~v780I~
//synclosecf                                                       //~v780I~
//  close color info file                                          //~v780I~
//**************************************************************** //~v780I~
int synclosecf(int Popt)                                           //~v780I~
{                                                                  //~v780I~
    if (Ssynstat2 & SYNS2OPEN)                                     //~v780I~
    {                                                              //~v780I~
    	Ssynstat2 &= ~SYNS2OPEN;                                   //~v780I~
  	  if (!(Gsyncfg.SYNCflag & SYNCF_USEACB))   //new logic        //~v78mI~
  	  {                                                            //~v78mI~
    	fclose(Sfhcolor);                                          //~v78mI~
      }                                                            //~v78mI~
      else                                                         //~v78mI~
      {                                                            //~v78mI~
    	fclose(Sfhindex);                                          //~v780I~
    	fclose(Sfhcolor);                                          //~v780I~
      }//old logic                                                 //~v78mI~
    }                                                              //~v780I~
    return 0;                                                      //~v780I~
}//synclosecf                                                      //~v780I~
//**************************************************************** //~v780I~
//syngetcf                                                         //~v780I~
//  get color data                                                 //~v780I~
//  Ppbuff:input old color data area. output:get color data        //~v780I~
//  rc -1:eof, 4/8                                                 //~v780R~
//**************************************************************** //~v780I~
int syngetcfdata(int Popt,int Phandle,int Pindex,PULHCI *Ppplhci,int Pctr)//~v780R~
{                                                                  //~v780I~
    ULONG  offs=0;                                                 //~vaf9R~
    SHINDEX idxrec;                                                //~v780R~
    int rc,reclen,readlen,readreqlen,bufflen,datalen;              //~v780R~
    PULHCI plhci;                                                  //~v780R~
    char *readinto;                                                //~v780I~
//*****************************                                    //~v780I~
    if (!(Ssynstat2 & SYNS2OPEN))                                  //~v780I~
    	return 8;	//stop next req                                //~v780R~
    if (Phandle!=Sopenctr)                                         //~v780I~
    	return 8;                                                  //~v780I~
                                                                   //~v780I~
    plhci=*Ppplhci; //old data                                     //~v780I~
//  bufflen=ULHCI_BUFFLEN(Pctr);                                   //~v780I~//~vaz8R~
    bufflen=(int)ULHCI_BUFFLEN((size_t)Pctr);                      //~vaz8I~
    if (!plhci                                                     //~v780I~
    ||  bufflen>plhci->ULHcibufflen)   //old buff shortage         //~v780I~
    {                                                              //~v780I~
    	if (plhci)                                                 //~v780I~
        	ufree(plhci);                                          //~v780I~
        *Ppplhci=plhci=(PULHCI)umalloc((UINT)bufflen);             //~v780I~
        UALLOCCHK(plhci,UALLOC_FAILED);                            //~v780I~
        plhci->ULHcibufflen=bufflen;                               //~v780I~
    }                                                              //~v780I~
                                                                   //~v780I~
  if (!(Gsyncfg.SYNCflag & SYNCF_USEACB))   //new logic            //~v78mI~
  {                                                                //~v78mI~
  	rc=syngetcfdata2(Popt,Phandle,Pindex/*concatinated lineno*/,plhci,Pctr/*ulhlen*/);//~v78mR~
  }                                                                //~v78mI~
  else                                                             //~v78mI~
  {                                                                //~v78mI~
    if (!(Popt & (SGCDO_SPLIT2)))	//not split or top of split    //~v780R~
    {                                                              //~v780I~
        rc=syngetindex(Popt,Pindex,&idxrec);                       //~v780R~
        if (rc)                                                    //~v780R~
            return rc;                                             //~v780R~
        offs=idxrec.SHXoffs;                                       //~v780R~
        reclen=(int)idxrec.SHXlen;                                 //~v780R~
//      if (offs+reclen>=Scolorfsz)                                //~v780I~//~vaz8R~
        if (offs+(ULONG)reclen>=Scolorfsz)                         //~vaz8I~
        {                                                          //~v780I~
            uerrmsg("SyntaxHL:Invalid Index record. Offset %08lx is out of range of color file(size=%08lx)",0,//~v780R~
//                          offs+reclen,Scolorfsz);                //~v780I~//~vaz8R~
                            offs+(ULONG)reclen,Scolorfsz);         //~vaz8I~
            return 4;                                              //~v780I~
        }                                                          //~v780I~
        if (offs!=Scolorfoffs)  //sequencial read not avail        //~v780M~
        {                                                          //~v780M~
            if (fseek(Sfhcolor,(LONG)offs,SEEK_SET))               //~v780M~
            {                                                      //~v780M~
                uerrmsg("SyntaxHL:Invalid Index record(seek %08lx failed,file size(%08lx))",0,//~v780R~
                                offs,Scolorfsz);                   //~v780M~
                return 4;                                          //~v780M~
            }                                                      //~v780M~
            Scolorfoffs=offs;                                      //~v780M~
        }                                                          //~v780M~
//      readreqlen=ULHCI_READLEN(Pctr);//index record len contains last eol//~v780I~//~vaz8R~
        readreqlen=(int)ULHCI_READLEN((size_t)Pctr);//index record len contains last eol//~vaz8I~
        if (!(Popt & (SGCDO_SPLIT1)))  //single record             //~v780R~
        {                                                          //~v780I~
            if (reclen!=readreqlen)                                //~v780I~
            {                                                      //~v780I~
                uerrmsg("SyntaxHL:Invalid Index record. Lineno %d record length(%d) unmatch width data length(%d)",0,//~v780R~
                                Pindex,reclen,readreqlen);         //~v780I~
                return 4;                                          //~v780I~
            }                                                      //~v780I~
        }                                                          //~v780R~
        else    //top of split                                     //~v780I~
        {                                                          //~v780I~
            readreqlen--;                                          //~v780I~
        }                                                          //~v780I~
//      readinto=(char*)(ULONG)(&plhci->ULHcidatalen);             //~v780I~//~vafkR~
        readinto=(char*)(ULPTR)(&plhci->ULHcidatalen);             //~vafkI~
    }//not follower                                                //~v780I~
    else    //follower                                             //~v780R~
    {                                                              //~v780I~
    	readreqlen=ULHCI_DATALEN(Pctr);                            //~v780R~
	    if (!(Popt & (SGCDO_SPLIT1)))	//last of split folllower  //~v780I~
        	readreqlen++;                                          //~v780R~
	    readinto=plhci->ULHcidata;                                 //~v780M~
    }                                                              //~v780I~
    readlen=(int)fread(readinto,1,(UINT)readreqlen,Sfhcolor);      //~v780R~
    rc=0;                                                          //~v780R~
    if (readlen!=readreqlen)                                       //~v780R~
    {                                                              //~v780R~
        uerrmsg("SyntaxHL:Color file read err(offset=%08lx,reqlen=%d,readlen=%d)",0,//~v780R~
                offs,readreqlen,readlen);                          //~v780R~
        rc=4;                                                      //~v780R~
    }                                                              //~v780R~
//  datalen=(int)ULHCI_DATAHDR(Pctr);                              //~v780I~//~vaz8R~
    datalen=(int)ULHCI_DATAHDR((size_t)Pctr);                      //~vaz8I~
    if (!(Popt & (SGCDO_SPLIT1|SGCDO_SPLIT2)))	//not split        //~v780R~
    {                                                              //~v780I~
        if (datalen!=plhci->ULHcidatalen)                          //~v780I~
        {                                                          //~v780I~
        	uerrmsg("SyntaxHL:Color file read err(offset=%08lx,reqlen=%d,len on header=%d)",0,//~v780R~
                        offs,datalen,plhci->ULHcidatalen);         //~v780R~
            rc=4;                                                  //~v780R~
        }                                                          //~v780I~
    }                                                              //~v780I~
    else                                                           //~v780I~
    {                                                              //~v780I~
	    if ((Popt & (SGCDO_SPLIT1)))	//has follower             //~v780I~
        	datalen--;                                             //~v780I~
    	plhci->ULHcidatalen=datalen;                               //~v780I~
    }                                                              //~v780I~
//  Scolorfoffs+=readlen;       //update position                  //~v780I~//~vaz8R~
    Scolorfoffs+=(ULONG)readlen;       //update position           //~vaz8I~
  }//old logic                                                     //~v78mI~
    return rc;                                                     //~v780I~
}//syngetcfdata                                                    //~v780R~
//**************************************************************** //~v780I~
//syngetindex                                                      //~v780I~
//  read index record                                              //~v780I~
//  rc:-1 eof,4:err                                                //~v780I~
//**************************************************************** //~v780I~
int syngetindex(int Popt,int Plineno,PSHINDEX Ppshindex)           //~v780R~
{                                                                  //~v780I~
	int len,readctr,linenotop;                                     //~v780R~
    char *pc;                                                      //~v780I~
    ULONG idxoffs;                                                 //~v780R~
    PSHINDEX pshidx;                                               //~v780I~
//***********************                                          //~v780I~
	if (!Plineno)	//lineno start from 1                          //~v780I~
    	return 4;                                                  //~v780I~
	if (!Sindexbuff)                                               //~v780I~
    {	                                                           //~v780I~
    	len=SHINDEXSZ*MAX_INDEX_STACKSZ;                           //~v780I~
        pc=umalloc((ULONG)len);                                    //~v780R~
        if (!len)                                                  //~v780I~
        	return 4;                                              //~v780I~
//      Sindexbuff=(PSHINDEX)(ULONG)pc;                            //~v780I~//~vafkR~
        Sindexbuff=(PSHINDEX)(ULPTR)pc;                            //~vafkI~
    }                                                              //~v780I~
    linenotop=(Plineno/MAX_INDEX_STACKSZ)*MAX_INDEX_STACKSZ;       //~v780R~
    if (Plineno<Sindexbuffrecnotop || Plineno>=Sindexbuffrecnoend) //~v780I~
    {                                                              //~v780I~
//      idxoffs=(ULONG)GET_CFINDEXOFFS(linenotop);                 //~v780R~//~vaz8R~
        idxoffs=(ULONG)GET_CFINDEXOFFS((size_t)linenotop);         //~vaz8I~
        if (idxoffs>=Sindexfsz)                                    //~v780I~
        {                                                          //~v780I~
            uerrmsg("SyntaxHL:Invalid Index record(Line count(%d) beyond Index file size(%ld))",0,//~v780R~
						Plineno,Sindexfsz);                        //~v780I~
            return 4;                                              //~v780I~
        }                                                          //~v780I~
    	Sindexbuffrecnotop=linenotop;                              //~v780R~
        if (fseek(Sfhindex,(LONG)idxoffs,SEEK_SET))                //~v780R~
        {                                                          //~v780I~
            uerrmsg("SyntaxHL:Invalid Index record(seek %08lx failed,file size(%08lx))",0,//~v780R~
						idxoffs,Sindexfsz);                        //~v780I~
            return 4;                                              //~v780I~
        }                                                          //~v780I~
        readctr=(int)fread(Sindexbuff,SHINDEXSZ,MAX_INDEX_STACKSZ,Sfhindex);//~v780R~
    	Sindexbuffrecnoend=linenotop+readctr;                      //~v780R~
        if (Plineno>=Sindexbuffrecnoend)                           //~v780R~
        {                                                          //~v780I~
            uerrmsg("SyntaxHL:Index record read failed(Line count(%ld) beyond Index count(%ld))",0,//~v780R~
						Plineno,Sindexbuffrecnoend);               //~v780R~
            return 4;                                              //~v780I~
        }                                                          //~v780I~
    }                                                              //~v780I~
    pshidx=Sindexbuff+(Plineno-linenotop);                         //~v780I~
    *Ppshindex=*pshidx;                                            //~v780I~
    if (pshidx->SHXlen==0xffffffff)	//EOF record                   //~v780R~
    	return -1;                                                 //~v780I~
    return 0;                                                      //~v780I~
}//syngetindex                                                     //~v780I~
//**************************************************************** //~v78mI~
//syngetcf2                                                        //~v78mI~
//  get color data(analyze source-highlight output)                //~v78mI~
//  rc -1:eof, 4/8                                                 //~v78mI~
//**************************************************************** //~v78mI~
int syngetcfdata2(int Popt,int Phandle,int Pindex,PULHCI Pplhci,int Pctr)//~v78mR~
{                                                                  //~v78mI~
    int rc,reclen,readreqlen;                                      //~v78mR~
    char *readinto;                                                //~v78mI~
    int paddinglen,ii,reslen;                                      //~v7atR~
    char color,*pc;                                                //~v7atR~
static int Sreadlen,Sreadoffs;                                     //~v78mI~
//*****************************                                    //~v78mI~
    readreqlen=Pctr+Pctr;                                          //~v78mI~
    if (!(Popt & (SGCDO_SPLIT2)))	//not split or top of split    //~v78mI~
    {                                                              //~v78mI~
        rc=syngetcfdata3(Popt,Pindex,&reclen);                     //~v78mI~
        if (rc)                                                    //~v78mI~
            return rc;                                             //~v78mI~
        Sreadoffs=0;                                               //~v78mR~
        Sreadlen=reclen;                                           //~v78mR~
    }//not follower                                                //~v78mI~
//    if ( (   (Popt & SGCDO_SPLIT1)  //has follower                 //~v78mI~//~v7atR~
//          && (Sreadoffs+readreqlen>Sreadlen)                       //~v78mR~//~v7atR~
//         )                                                         //~v78mI~//~v7atR~
//         ||                                                        //~v78mI~//~v7atR~
//         (  !(Popt & SGCDO_SPLIT1)  //not split or last of split   //~v78mI~//~v7atR~
//          && Sreadoffs+readreqlen!=Sreadlen                        //~v78mR~//~v7atR~
//         )                                                         //~v78mI~//~v7atR~
//       )                                                           //~v78mI~//~v7atR~
//    {                                                              //~v78mI~//~v7atR~
//        uerrmsg("SyntaxHL:Esc data read failed at lineno %d, record offs=%d,remaining=%d,linelen=%d",0,//~v78mI~//~v7atR~
//                        Pindex,Sreadoffs,Sreadlen-Sreadoffs,readreqlen);//~v78mR~//~v7atR~
//        return 4;                                                  //~v78mI~//~v7atR~
//    }                                                              //~v78mI~//~v7atR~
	readinto=Pplhci->ULHcidata;                                    //~v78mR~
  if (Sreadoffs+readreqlen<=Sreadlen)                              //~v7atI~
  {                                                                //~v7atI~
//  memcpy(readinto,Spbuffstylecolor+Sreadoffs,readreqlen);        //~v78mI~//~vaz8R~
    memcpy(readinto,Spbuffstylecolor+Sreadoffs,(size_t)readreqlen);//~vaz8I~
    Sreadoffs+=readreqlen;                                         //~v78mI~
  }                                                                //~v7atI~
  else    //highlight output is short                              //~v7atI~
  {                                                                //~v7atI~
  	reslen=max(0,Sreadlen-Sreadoffs);	//residual to be copyed    //~v7atI~
  	paddinglen=readreqlen-reslen; //padding len                    //~v7atR~
  	if (reslen)                                                    //~v7atR~
    {                                                              //~v7atI~
//  	memcpy(readinto,Spbuffstylecolor+Sreadoffs,reslen);        //~v7atR~//~vaz8R~
    	memcpy(readinto,Spbuffstylecolor+Sreadoffs,(size_t)reslen);//~vaz8I~
	    Sreadoffs+=reslen;                                         //~v7atR~
    }                                                              //~v7atI~
//  color=(Sbg<<4)|Sfg;                                            //~v7atI~//~vaz8R~
    color=(char)((Sbg<<4)|Sfg);                                    //~vaz8I~
    for (ii=paddinglen/2,pc=readinto+reslen;ii>0;ii--)             //~v7atR~
    {                                                              //~v7atI~
//  	*pc++=Sstyle;                                              //~v7atI~//~vaz8R~
    	*pc++=(char)Sstyle;                                        //~vaz8I~
    	*pc++=color;                                               //~v7atI~
    }                                                              //~v7atI~
  }                                                                //~v7atI~
    Pplhci->ULHcidatalen=readreqlen;                               //~v78mR~
    return 0;                                                      //~v78mI~
}//syngetcfdata2                                                   //~v78mI~
//**********************************************************************//~v78mI~
//* source hilight esc format output read                          //~v78mI~
//**********************************************************************//~v78mI~
int syngetcfdata3(int Popt,int Plineno,int *Pplen)                 //~v78mR~
{                                                                  //~v78mI~
//  int len,outlen,rc=-1,ii;                                       //~vaf9R~
    int len,outlen=0,rc=-1,ii;                                     //~vaf9I~
    char *pcsc,*pcc,*pcs;                                          //~v78mI~
//*********                                                        //~v78mI~
	if ((len=getinput())>=0)     //until eof                       //~v78mI~
 	{                                                              //~v78mI~
    	rc=0;                                                      //~v78mI~
        if (len>0)                                                 //~v78mI~
        {                                                          //~v78mI~
            lineproc(Spbuffinp,len,Spbuffcolor,Spbuffstyle,&outlen);//~v78mR~
            if (outlen)                                            //~v78mI~
            {                                                      //~v78mI~
                pcsc=Spbuffstylecolor;                             //~v78mI~
                pcc=Spbuffcolor;                                   //~v78mI~
                pcs=Spbuffstyle;                                   //~v78mI~
                for (ii=0;ii<outlen;ii++)                          //~v78mI~
                {                                                  //~v78mI~
                    *pcsc++=*pcs++;                                //~v78mI~
                    *pcsc++=*pcc++;                                //~v78mI~
                }                                                  //~v78mI~
                outlen+=outlen;                                    //~v78mI~
            }                                                      //~v78mI~
        }                                                          //~v78mI~
        else                                                       //~v78mI~
            outlen=0;                                              //~v78mI~
	}//until eof                                                   //~v78mI~
    *Pplen=outlen;                                                 //~v78mI~
	return rc;                                                     //~v78mI~
}//syngetcfdata3                                                   //~v78mI~
//**********************************************************************//~v78mI~
//* get 1 line                                                     //~v78mI~
//* ret:line length,-1 if eof                                      //~v78mI~
//**********************************************************************//~v78mI~
int getinput(void)                                                 //~v78mI~
{                                                                  //~v78mI~
	int len;                                                       //~v78mI~
//****************                                                 //~v78mI~
    Slineno++;                                                     //~v78mI~
	if (!fgets(Spbuffinp,RBUFFSZ,Sfhcolor))	//fgets set null at eol//~v78mI~
    {                                                              //~v78mI~
UTRACEP("getinput fail errno=%d\n",errno);                         //~v78mI~
		if (ferror(Sfhcolor))                                      //~v78mR~
			uerrmsg("Input read error",0);                         //~v78mR~
		return -1;                                                 //~v78mR~
    }                                                              //~v78mI~
	len=(int)strlen(Spbuffinp);			//read len                 //~v78mI~
	if (*(Spbuffinp+len-1)!='\n')                                  //~v78mI~
    {                                                              //~v78mI~
      	if (len>=RBUFFSZ-1)                                        //~v78mI~
			uerrmsg("\n????? Input has too long record over %d byte at line %d",0,//~v78mI~
					RBUFFSZ-1,Slineno);                            //~v78mI~
    }                                                              //~v78mI~
    else                                                           //~v78mI~
        len--;                                                     //~v78mI~
//  if (len>1 && *(Spbuffinp+len-1)==0x0d) 	//pc/mac file          //~v78JR~
//  	len--;                                                     //~v78JR~
	*(Spbuffinp+len)=0;                                            //~v78mI~
UTRACED("getinput",Spbuffinp,len);                                 //~v78mI~
	return len;                                                    //~v78mI~
}//end of getinput                                                 //~v78mI~
//**********************************************************************//~v78mI~
//* esc.outlang                                                    //~v78mI~
//      extension "txt"                                            //~v78mI~
//                                                                 //~v78mI~
//      styletemplate "\x1b[$stylem$text\x1b[m"                    //~v78mI~
//      styleseparator ";"                                         //~v78mI~
//                                                                 //~v78mI~
//      bold "01$style"                                            //~v78mI~
//      underline "04$style"                                       //~v78mI~
//      italics "$style"                                           //~v78mI~
//      color "$style"                                             //~v78mI~
//                                                                 //~v78mI~
//                                                                 //~v78mI~
//      colormap                                                   //~v78mI~
//      "green" "32"                                               //~v78mI~
//      "red" "31"                                                 //~v78mI~
//      "darkred" "31"                                             //~v78mI~
//      "blue" "34"                                                //~v78mI~
//      "brown" "31"                                               //~v78mI~
//      "pink" "35"                                                //~v78mI~
//      "yellow" "33"                                              //~v78mI~
//      "cyan" "36"                                                //~v78mI~
//      "purple" "35"                                              //~v78mI~
//      "orange" "31"                                              //~v78mI~
//      "brightorange" "31"                                        //~v78mI~
//      "brightgreen" "32"                                         //~v78mI~
//      "darkgreen" "32"                                           //~v78mI~
//      "black" "30"                                               //~v78mI~
//      "teal" "37"                                                //~v78mI~
//      "gray" "37"                                                //~v78mI~
//      "darkblue" "34"                                            //~v78mI~
//      default "30;"                                              //~v78mI~
//      end                                                        //~v78mI~
//                                                                 //~v78mI~
//      # Decorate text with terminal control sequences (escape sequences).//~v78mI~
//      # To set the attribute/fg_color/bg_color we need to print  //~v78mI~
//      #   "\033[AA;FF;BBm"                                       //~v78mI~
//      # where AA is one of these:                                //~v78mI~
//      # 00=none 01=bold 04=underscore 05=blink 07=reverse 08=concealed,//~v78mI~
//      # FF is one of these:                                      //~v78mI~
//      # 30=black 31=red 32=green 33=yellow 34=blue 35=magenta 36=cyan 37=white//~v78mI~
//      # BB is one of these:                                      //~v78mI~
//      # 40=black 41=red 42=green 43=yellow 44=blue 45=magenta 46=cyan 47=white//~v78mI~
//      #                                                          //~v78mI~
//      # Any of AA,FF,BB may be omited.                           //~v78mI~
//      #                                                          //~v78mI~
//      # To reset do default color/attribute we need to print     //~v78mI~
//      # "\033[m"                                                 //~v78mI~
//*sample output                                                   //~v78mI~
//      0x1b01;34m#include0x1b[m 0x1b[31m<string.h>0x1b[m     0x1b[31m//0x1b[m0x1b[31m~7112I~0x1b[m//~v78mI~
//      0x1b31m//0x1b[m0x1b[31m*************************************************************    //~7112I~0x1b[m//~v78mI~
//*output color: bg(4bit)+fg(4bit)                                 //~v78mI~
//        style: "0":none,"1":bold,"4":underline                   //~v78mI~
//**********************************************************************//~v78mI~
int lineproc(char *Pbuffinp,int Pleninp,char *Pbuffoutc,char *Pbuffouts,int *Ppoutlen)//~v78mR~
{                                                                  //~v78mI~
	char *pci,*pcoc,*pcos,*pcn,*pce,*nextpci=0;                    //~vaf9R~
	int reslen,len,color,nextstyle,nextfg,nextbg,fg,bg;            //~v78mI~
    int eolsw;                                                     //~v78mI~
//*********                                                        //~v78mI~
    UTRACED("xesyn2 lineproc:inp",Pbuffinp,Pleninp);               //~vap0I~
    pci=Pbuffinp;                                                  //~v78mI~
    pce=pci+Pleninp;                                               //~v78mI~
    pcoc=Pbuffoutc;                                                //~v78mI~
    pcos=Pbuffouts;                                                //~v78mI~
	fg=Sfg;                                                        //~v78mI~
	bg=Sbg;                                                        //~v78mI~
    nextstyle=Sstyle;		//cont over line                       //~v78mI~
    for (;;)                                                       //~v78mI~
    {                                                              //~v78mI~
//	    reslen=(int)((ULONG)pce-(ULONG)pci);                       //~v78mI~//~vafkR~
	    reslen=(int)((ULPTR)pce-(ULPTR)pci);                       //~vafkI~
        pcn=pci;                                                   //~v78mI~
        nextfg=fg;                                                 //~v78mI~
        nextbg=bg;                                                 //~v78mI~
        for (;;)                                                   //~v78mI~
        {                                                          //~v78mI~
            eolsw=1;                                               //~v78mI~
//		    len=(int)((ULONG)pce-(ULONG)pcn);                      //~v78mI~//~vafkR~
		    len=(int)((ULPTR)pce-(ULPTR)pcn);                      //~vafkI~
//*all non ascii data is replaced by 0xa0 at xesyn.c               //~va08I~
    		pcn=memchr(pcn,CH_ESC1,(UINT)len);                     //~v78mI~
        	if (!pcn)                                              //~v78mI~
            	break;                                             //~v78mI~
            eolsw=0;                                               //~v78mI~
	        if (escchk(pcn,pce,&nextpci,&nextfg,&nextbg,&nextstyle))//color esc found//~v78mI~
            	break;                                             //~v78mI~
            pcn++;         //esc is not for color                  //~v78mI~
                                                                   //~v78mI~
        }                                                          //~v78mI~
	    color=(bg <<4) | (fg);                                     //~v78mI~
        if (eolsw)                                                 //~v78mI~
        	break;                                                 //~v78mI~
//      len=(int)((ULONG)pcn-(ULONG)pci);                          //~v78mI~//~vafkR~
        len=(int)((ULPTR)pcn-(ULPTR)pci);                          //~vafkI~
	    memset(pcoc,color,(UINT)len);                              //~v78mI~
        pcoc+=len;                                                 //~v78mI~
        fg=nextfg;                                                 //~v78mI~
        bg=nextbg;                                                 //~v78mI~
                                                                   //~v78mI~
        memset(pcos,Sstyle,(UINT)len);                             //~v78mI~
        pcos+=len;                                                 //~v78mI~
        Sstyle=nextstyle;                                          //~v78mI~
        pci=nextpci;                                               //~v78mI~
    }                                                              //~v78mI~
    memset(pcoc,color,(UINT)reslen);                               //~v78mI~
    pcoc+=reslen;                                                  //~v78mI~
//  *Ppoutlen=(int)((ULONG)pcoc-(ULONG)Pbuffoutc);                 //~v78mI~//~vafkR~
    *Ppoutlen=(int)((ULPTR)pcoc-(ULPTR)Pbuffoutc);                 //~vafkI~
    if (reslen>0)                                                  //~v78mI~
        memset(pcos,Sstyle,(UINT)reslen);                          //~v78mI~
	Sfg=fg;                                                        //~v78mI~
	Sbg=bg;                                                        //~v78mI~
    UTRACED("xesyn2 lineproc:out color",Pbuffoutc,*Ppoutlen);      //~vap0I~
    UTRACED("xesyn2 lineproc:out style",Pbuffouts,*Ppoutlen);      //~vap0I~
	return 0;                                                      //~v78mI~
}//lineproc                                                        //~v78mI~
//**********************************************************************//~v78mI~
//*chk esc str                                                     //~v78mI~
//*ANSI format                                                     //~v78mI~
//* ESC[#(;#)m    multiple seperated by ; and end with m           //~v78mI~
//*  0,1,4,5,7,8  style(source-highkigh is 00,01...)               //~v78mI~
//*    ( 1(Bold) means highlight by ansi)                          //~v78mI~
//*  30,31,...37  fg                                               //~v78mI~
//*  40,31,...37  bg                                               //~v78mI~
//* rc:1:color esc detected,0:not valid color esc                  //~v78mI~
//**********************************************************************//~v78mI~
int escchk(char *Pinp,char *Peol,char **Pinpnext,int *Ppfg,int *Ppbg,int *Ppstyle)//~v78mI~
{                                                                  //~v78mI~
	char *pc;                                                      //~v78mI~
	int fg,bg,style,value,ch,valuesw=0;                            //~v78mI~
//*********                                                        //~v78mI~
	pc=Pinp;                                                       //~v78mI~
    fg=*Ppfg;                                                      //~v78mI~
	bg=*Ppbg;                                                      //~v78mI~
    style=*Ppstyle;     //continue until reset                     //~v78mI~
    pc++;                                                          //~v78mI~
    if (pc>=Peol)                                                  //~v78mI~
        return 0;                                                  //~v78mI~
    if (*pc!=CH_ESC2)  	//[ of 0x1b[                               //~v78mI~
        return 0;                                                  //~v78mI~
    pc++;                                                          //~v78mI~
    value=0;                                                       //~v78mI~
    for (;;pc++)                                                   //~v78mI~
    {                                                              //~v78mI~
    	if (pc>=Peol)                                              //~v78mI~
        	return 0;                                              //~v78mI~
    	ch=*pc;                                                    //~v78mI~
        if (ch==CH_RESET                                           //~v78mI~
        ||  ch==CH_DELM)	//m                                    //~v78mI~
        {                                                          //~v78mI~
            if (value<10)                                          //~v78mI~
                style=value;                                       //~v78mI~
            else                                                   //~v78mI~
            if (value>=30 && value<=37)                            //~v78mI~
                fg=value-30;                                       //~v78mI~
            else                                                   //~v78mI~
            if (value>=40 && value<=47)                            //~v78mI~
                bg=value-40;                                       //~v78mI~
            else                                                   //~v78mI~
                return 0;                                          //~v78mI~
            if (ch==CH_DELM)                                       //~v78mI~
            {                                                      //~v78mI~
                value=0;                                           //~v78mI~
                continue;                                          //~v78mI~
            }                                                      //~v78mI~
        	pc++;                                                  //~v78mI~
            if (valuesw)	//any parm                             //~v78mI~
            	break;                                             //~v78mI~
            fg=Sdeffg;	//reset to default                         //~v78mR~
            bg=Sdefbg;                                             //~v78mI~
        	break;                                                 //~v78mI~
        }                                                          //~v78mI~
        if (!isdigit(ch))	//m                                    //~v78mI~
        	return 0;                                              //~v78mI~
        value=value*10+(ch & 0x0f);                                //~v78mI~
        valuesw=1;                                                 //~v78mI~
    }                                                              //~v78mI~
    *Pinpnext=pc;                                                  //~v78mI~
    *Ppfg=fg;                                                      //~v78mI~
    *Ppbg=bg;                                                      //~v78mI~
    style|='0';	//"0":normal                                       //~v78mI~
    *Ppstyle=style;                                                //~v78mI~
    return 1;   //valid color esc                                  //~v78mI~
}//escchk                                                          //~v78mI~
//**************************************************************** //~v780M~
//syngetbg                                                         //~v780M~
//**************************************************************** //~v780M~
int syngetbgeol(int Popt)                                          //~v780M~
{                                                                  //~v780M~
	int bg;                                                        //~v780M~
//****************                                                 //~v780M~
	if (Gsyncfg.SYNCflag & SYNCF_BG_EOL)                           //~v780M~
		bg=SYN_PAL_BGCOLOR(Gsyncfg.SYNCbgeol);                     //~v780R~
    else                                                           //~v780M~
    {                                                              //~v78oI~
//  	bg=-1;                                                     //~v78oR~
    	if ((Popt & SYNCPO_BROWSE)                                 //~v78oR~
        &&  (Gsyncfg.SYNCflag & SYNCF_BG_BROWSE))                  //~v78oI~
			bg=SYN_PAL_BGCOLOR(Gsyncfg.SYNCbgbrowse);              //~v78oI~
        else                                                       //~v78oI~
			bg=SYN_PAL_BGCOLOR(Gsyncfg.SYNCbg);                    //~v78oI~
    }                                                              //~v78oI~
	return bg;                                                     //~v780M~
}//syngetbgeol                                                     //~v780M~
//**************************************************************** //~v780M~
//syngetbgtab: if                                                  //~v780M~
//**************************************************************** //~v780M~
int syngetbgtab(int Popt)                                          //~v780M~
{                                                                  //~v780M~
	int bg;                                                        //~v780M~
//****************                                                 //~v780M~
	if (Gsyncfg.SYNCflag & SYNCF_BG_TAB)                           //~v780M~
		bg=SYN_PAL_BGCOLOR(Gsyncfg.SYNCbgtab);                     //~v780I~
    else                                                           //~v780M~
    {                                                              //~v78oI~
//  	bg=-1;                                                     //~v78oR~
    	if ((Popt & SYNCPO_BROWSE)                                 //~v78oI~
        &&  (Gsyncfg.SYNCflag & SYNCF_BG_BROWSE))                  //~v78oI~
			bg=SYN_PAL_BGCOLOR(Gsyncfg.SYNCbgbrowse);              //~v78oI~
        else                                                       //~v78oI~
			bg=SYN_PAL_BGCOLOR(Gsyncfg.SYNCbg);                    //~v78oI~
    }                                                              //~v78oI~
	return bg;                                                     //~v780M~
}//syngetbgtab                                                     //~v780M~
//**************************************************************** //~v780M~
//syngetbgupd: if                                                  //~v780M~
//**************************************************************** //~v780M~
int syngetbgupd(int Popt)                                          //~v780M~
{                                                                  //~v780M~
	int bg;                                                        //~v780M~
//****************                                                 //~v780M~
	if (Gsyncfg.SYNCflag & SYNCF_BG_UPD)                           //~v780M~
		bg=SYN_PAL_BGCOLOR(Gsyncfg.SYNCbgupd);                     //~v780R~
    else                                                           //~v780M~
    	bg=-1;                                                     //~v780M~
	return bg;                                                     //~v780M~
}//syngetbgupd                                                     //~v780M~
//**************************************************************** //~v780I~
//syngetbgupd: if                                                  //~v780I~
//**************************************************************** //~v780I~
int syngetstylecolor(int Popt,char *Pstylecolor,int *Ppstyle)      //~v780R~
{                                                                  //~v780I~
	int style,color,styleopt;                                      //~v780I~
	int bg;                                                        //~v78oI~
//****************                                                 //~v780I~
	style=SYN_STYLE_MAP(*Pstylecolor);                             //~v780I~
	color=SYN_PAL_COLOR(*(Pstylecolor+1));                         //~v780R~
    if ((Popt & SYNCPO_BROWSE)                                     //~v78oR~
    &&  (Gsyncfg.SYNCflag & SYNCF_BG_BROWSE))                      //~v78oI~
		bg=SYN_PAL_BGCOLOR(Gsyncfg.SYNCbgbrowse);                  //~v78oI~
    else                                                           //~v78oI~
		bg=SYN_PAL_BGCOLOR(Gsyncfg.SYNCbg);                        //~v78oI~
    color|=bg;                                                     //~v78oI~
    styleopt=Gsyncfg.SYNCstyleopt[style];                          //~v780I~
    if (styleopt & SYNC_STYLE_HIGH)                                //~v780I~
		color|=SYN_HIGHLIGHT_FG;		//uvio.h                   //~v780R~
    if (!(styleopt & SYNC_STYLE_GUI_EACH))                         //~v780I~
		style=SYNC_STYLE_NORMAL;                                   //~v780R~
    *Ppstyle=style;                                                //~v780I~
    return color;                                                  //~v780R~
}//syngetstylecolor                                                //~v780I~
//***********************************************************************//~v78GR~
//*syntax highlight server init                                    //~v78GR~
//***********************************************************************//~v78GR~
int xesyn_serverinit(int Popt,char *Pcmdname)                      //~v78GR~
{                                                                  //~v78GR~
    int rc;                                                        //~v78GR~
    char *pc;                                                      //~v78GR~
    int opt=0;                                                     //~v79GI~
//*****************                                                //~v78GR~
    pc=strchr(Pcmdname,' ');                                       //~v78GR~
    if (pc)                                                        //~v78GR~
        *pc=0;  //start use exe name only                          //~v78GR~
#ifdef WXE                                                         //~v79GI~
    opt|=UPROC_SYSCMD_MIN;	//minimize window size                 //~v79GI~
#else                                                              //~v79GI~
#endif                                                             //~v79GI~
    rc=uproc_shserverinit(opt,0/*callback*/,Pcmdname,0,0,0);//use cmd server for system()//~v78GR~//~v79GR~
    *pc=' ';    //option is used later at shcmd                    //~v78GR~
	if (!rc)                                                       //~v78GI~
		Gsyncfg.SYNCflag|=SYNCF_RSVRACTIVE;                        //~v78GI~
    else                                                           //~v78GI~
		Gsyncfg.SYNCflag&=~SYNCF_OK;                               //~v78GI~
    return rc;                                                     //~v78GR~
}//xesyn_serverinit                                                //~v78GR~
//***********************************************************************//~v78GR~
//*syntax highlight server init                                    //~v78GR~
//***********************************************************************//~v78GR~
int xesyn_shreq(int Popt,char *Pcmd)                               //~v78GR~
{                                                                  //~v78GR~
    int rc,opt;                                                    //~v78GR~
    char respmsg[SH_MAX_RESPMSG];                                  //~v78GR~
//*****************                                                //~v78GR~
    if (!(Gsyncfg.SYNCflag & SYNCF_RSVRACTIVE))                    //~v78GI~
    {                                                              //~v78GI~
        if (xesyn_serverinit(0,Gsyncfg.SYNCshcmd))                 //~v78GI~
        	return 4;                                              //~v78GI~
    }                                                              //~v78GI~
    if (Gsyncfg.SYNCflag & SYNCF_RSVRPARMOK)                       //~v78GR~
    	opt=0;                                                     //~v78GI~
    else                                                           //~v78GI~
    	opt=UPSPO_ALIVECHK;        //check server is active before read response to protect read wait//~v78GI~
    rc=uproc_shcmd(opt,Pcmd,respmsg,sizeof(respmsg));              //~v78GR~
    if (!rc)                                                       //~v78GR~
    {                                                              //~v78GR~
    	Gsyncfg.SYNCflag |= SYNCF_RSVRPARMOK;	//chek alive server only 1st time//~v78GI~
        rc=atoi(respmsg);                                          //~v78GR~
        if (rc)                                                    //~v78GR~
            uerrmsg("%s",0,                                        //~v78GR~
                    respmsg);                                      //~v78GR~
    }                                                              //~v78GR~
    else                                                           //~v78GI~
    if (rc<0)	//server stopped /write err                        //~v78JR~
    {                                                              //~v78GI~
    	Gsyncfg.SYNCflag &=~(SYNCF_OK|SYNCF_RSVRACTIVE);           //~v78GI~
    }                                                              //~v78GI~
    return rc;                                                     //~v78GR~
}//xesyn_shreq                                                     //~v78GR~
//***********************************************************************//~v78GR~
//*syntax highlight server termination                             //~v78GR~
//***********************************************************************//~v78GR~
int xesyn_serverterm(int Popt)                                     //~v78GR~
{                                                                  //~v78GR~
    int rc;                                                        //~v78GR~
//*****************                                                //~v78GR~
    if ((Gsyncfg.SYNCflag & SYNCF_NORESIDENT))                     //~v78GI~
    	return 0;                                                  //~v78GI~
	if (!(Gsyncfg.SYNCflag&SYNCF_RSVRACTIVE))                      //~v78GI~
    	return 0;                                                  //~v78GI~
	rc=uproc_shserverterm(0,0,0,0);                                //~v78GR~
    return rc;                                                     //~v78GR~
}//xesyn_serverterm                                                //~v78GR~
#endif //SYNSUPP                                                   //~v780I~
