//*CID://+vbs7R~:                             update#= 491;        //~vbkdR~//+vbs7R~
//*************************************************************
//*xepan23.c                                                       //~7620R~
//*   utility compare,grep                                         //~v76gR~
//************************************************************* //~5610I~
//vbs7:201028 Debian10 compiler warning -Wformat-overflow          //+vbs7I~
//vbkd:180619 like vbj1 cpu8 option to =3.12                       //~vbkdI~
//vba0:170624 (BUG:64bit) 3.14 crush by ptrsz                      //~vba0I~
//vb4B:160819 (BUG) missing clear Gsubgblopt:XESUB_GBLOPT_WILDPATH flag before return//~vb4BI~
//vb31:160418 (LNX64)Compiler warning                              //~vb31I~
//vb30:160411 (LNX)Compiler warning                                //~vb30I~
//vawe:140602 it should be strip UD for send data to util panel    //~vaweI~
//vavN:140405 (W32UNICODE)vavM is not effective,spawn dose also multibyte process(invalid UD to dbcs translation),use UD_UTF8X fmt//~vavNI~
//vavy:140428 (BUG).312/3.14 panel;remains help text after deleted last non space char//~vavyI~
//vavp:140426 (vaub for Win)maintain ddfmt for pan fnmlist and util panel//~vavpI~
//vavc:140421 (Win)unicode support(UD fmt string)                  //~vavcI~
//vav9:140410 (Win)unicode support(UD fmt string,_MAX_PATH changes)//~vav9I~
//vauc:140308 (BUG)setdbcstbl length is invalid;util-compare fnm1,fnm2 dbcs half cut//~vaucI~
//vaub:140306 maintain ddfmt for pan fnmlist and util panel        //~vaubI~
//vaua:140306 getmixwdword output dddata and dddbcs                //~vauaI~
//vagA:120918 rc chk for ufullpath                                 //~vagAI~
//vafw:120703 (LNX)keep ini file size after _MAX_PATH expanded     //~vafwI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//vaa7:111117 (gcc4.6)Warning:unused-but-set                       //~vaa7I~
//va70:000701 LP64 option support                                  //~va70I~
//va5w:100517 panutil:keep utf8 codetype over session              //~va5wI~
//va5v:100516 display util fnm by dd fmt                           //~va5vI~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//va1q:091107 compchkm                                             //~va1qI~
//va1n:091103_(UTF8)cmdline parm for filename encoding             //~va1nI~
//va1c:091030_merge GB18030 support                                //~va1cI~
//va0E:090725!accept utf8 input on =3.14 option line(utfg string search)//~va0EI~
//va0t:090913!maintains locale and utf8 code for panel input(cmdline,panutil)//~va0tI~
//va0h:090803 (BUG)always set cdir                                 //~va0hI~
//va0e:090718 (BUG)util cmd,missing clear ini data                 //~va0eI~
//va0d:090717 (BUG)util grep hung when no file parameter specified //~va0dI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          filename list is mixed of utf8 and locale code         //~va00I~
//          ignore translation err for utility result file(parm to edit_file2)//~va00I~
//v77c:071220 update current dir on utility panel when CD changed  //~v77cI~
//v76p:070628 compare remote file support                          //~v76pI~
//v76j:070626 (WXEXXE)dnd by paste to utility panel                //~v76jI~
//v76g:070620 utility panel(3.14:grep and 3.12:compare);f5:open dirlist, dlcmd "^":send//~v76gI~
//************************************************************* //~5610I~
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifdef W32                                                         //~v76gI~
	#include <io.h>                                                //~v76gI~
#endif                                                             //~v76gI~
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <uque.h>
#include <ualloc.h>
#include <ufile.h>                                              //~5318I~
#include <utrace.h>                                                //~v075I~
#include <uparse.h>                                                //~v0b2R~
#include <ustring.h>                                               //~v76gI~
#include <ufemsg.h>                                                //~v76gI~
#include <uftp.h>                                                  //~v76pI~
#include <ufilew.h>                                                //~vavNI~
#ifdef UTF8SUPPH                                                   //~va00I~
	#include <utf.h>                                               //~va00I~
#endif                                                             //~va00I~
                                                                //~5318I~
#include "xe.h"
#include "xescr.h"
#include "xecsr.h"
#include "xefunc.h"
#include "xefunc2.h"                                               //~v76gI~
#include "xepan.h"
#include "xepan2.h"
#include "xefile.h"                                             //~v020I~
#include "xesub.h"                                                 //~v74xM~
#include "xedir.h"                                              //~v020I~
#include "xedlcmd.h"                                               //~v76gI~
#include "xedlcmd6.h"                                              //~v76gI~
#include "xedcmd.h"                                                //~v76gR~
#include "xedcmd4.h"                                               //~v76gI~
#include "xeerr.h"                                                 //~v76gI~
#include "xegbl.h"                                                 //~v76gI~
#include "xechar12.h"                                              //~v76jI~
#ifdef UTF8SUPPH                                                   //~va00I~
	#include "xeutf.h"                                             //~va00R~
	#include "xepan22.h"                                           //~va00M~
	#include "xeutf2.h"                                            //~va5vI~
#endif                                                             //~va00I~
#include "xefsubw.h"                                               //~vaweI~
#include "xeopt.h"                                                 //~vbkdI~
//**************************************************************** //~v075I~
//*comp panel data                                                 //~v76gI~
typedef struct _UPANCOMP  {							//field def    //~v76gI~
							int   UPANCflag;                       //~v76gI~
							int   UPANCcsry;                       //~v76gR~
							char *UPANCopt;                        //~v76gI~
							char *UPANCfnm1;                       //~v76gI~
							char *UPANCfnm2;                       //~v76gI~
							char *UPANCoptdbcs;                    //~v76gR~
							char *UPANCfnm1dbcs;                   //~v76gI~
							char *UPANCfnm2dbcs;                   //~v76gI~
					  	} UPANCOMP,*PUPANCOMP;                     //~v76gI~
#define UPANCOMPSZ   (sizeof(UPANCOMP))                            //~v76gI~
typedef struct _UPANGREP  {							//field def    //~v76gI~
							int   UPANGflag;                       //~v76gI~
							int   UPANGcsry;                       //~v76gI~
							char *UPANGopt;                        //~v76gI~
							char *UPANGfnm[PANLUGFILENO];          //~v76gR~
							char *UPANGoptdbcs;                    //~v76gI~
							char *UPANGfnmdbcs[PANLUGFILENO];      //~v76gR~
					  	} UPANGREP,*PUPANGREP;                     //~v76gI~
#define UPANGREPSZ   (sizeof(UPANGREP))                            //~v76gI~
//*********************************                                //~v76gI~
#ifdef LNX                                                         //~vafwI~
    #define INIFNMSZ  _MAX_PATH_FOR_INIFILE                        //~vafwI~
#else                                                              //~vafwI~
    #define INIFNMSZ  _MAX_PATH                                    //~vafwI~
#endif                                                             //~vafwI~
static char  Scompopt[MAXCOLUMN];                                  //~v76gR~
static char  Scompfile1[_MAX_PATH];                                //~v76gI~
static char  Scompfile2[_MAX_PATH];                                //~v76gI~
static char  Sgrepopt[MAXCOLUMN];                                  //~v76gI~
static char  Sgrepfile[PANLUGFILENO][_MAX_PATH];                   //~v76gI~
static char  Scompoptct[MAXCOLUMN];                                //~va5wI~
static char  Scompfile1ct[_MAX_PATH];                              //~va5wI~
static char  Scompfile2ct[_MAX_PATH];                              //~va5wI~
static char  Sgrepoptct[MAXCOLUMN];                                //~va5wI~
static char  Sgrepfilect[PANLUGFILENO][_MAX_PATH];                 //~va5wI~
#ifdef W32UNICODE                                                  //~vavNI~
	static char  SfnmUD[_MAX_PATH];                                //~vavNI~
	static int SfnmUDlen;                                          //~vavNI~
#endif                                                             //~vavNI~
static int   Sutilstat;                                            //~va5wI~
#define    SUS_INICODETYPE     0x01 //codetype read from ini       //~va5wI~
int Sutilcolstart;                                                 //~v76gR~
//#ifdef AAA  //use when outout save data to another ::file          //~vaucR~//~vavpR~
//#ifdef LNX                                                         //~vaubI~//~vavpR~
//    typedef enum       //index of Sddfmttb                         //~vaubI~//~vavpR~
//    {                                                              //~vaubI~//~vavpR~
//        PUDIE_COMPOPT,                                             //~vaubI~//~vavpR~
//        PUDIE_COMPFILE1,                                           //~vaubI~//~vavpR~
//        PUDIE_COMPFILE2,                                           //~vaubI~//~vavpR~
//        PUDIE_GREPOPT,                                             //~vaubI~//~vavpR~
//        PUDIE_GREPFILE                                             //~vaubI~//~vavpR~
//    } PANUTILDDIDX;                                                //~vaubI~//~vavpR~
//    #define PUDIE_MAXENT (1+PUDIE_GREPFILE+PANLUGFILENO)           //~vaubI~//~vavpR~
//    static char *Sddfmttb[PUDIE_MAXENT];                           //~vaubI~//~vavpR~
//    static int   Sddfmtsztb[PUDIE_MAXENT];                         //~vaubI~//~vavpR~
//    #define PANUTILFNM  "xe_save_panutil"                          //~vaubI~//~vavpR~
//    #define PANUTILACRNM "PANU";                                   //~vaubI~//~vavpR~
//    #define PANU_VERSION 3                                         //~vaubI~//~vavpR~
//#endif                                                             //~vaubI~//~vavpR~
//#endif  //AAA                                                      //~vaucI~//~vavpR~
//**************************************************************** //~v76gI~
int pancompwakeup1(PUCLIENTWE Ppcw);                               //~v76gI~
int panutilsetcdir(PUCLIENTWE Ppcw,int Plineid,char *Ppath);       //~v76gI~
int pancompdataproc(int Popt,PUCLIENTWE Ppcw,char **Ppdata,char **Ppdbcs,int *Pplen);//~v76gR~
int pangrepdataproc(int Popt,PUCLIENTWE Ppcw,char **Ppdata,char **Ppdbcs,int *Pplen);//~v76gR~
int panutilview(PUCLIENTWE Ppcw,int Ppanelid,char *Pfilename);     //~v76gI~
int panutilviewswap(PUCLIENTWE Ppcw,PUCLIENTWE *Pppcw2);           //~v76gI~
int panutilerrline(void);                                          //~v76gI~
int panutilerrlinefull(void);                                      //~v76gI~
#ifdef UTF8SUPPH                                                   //~va00I~
	int panutilsetfld_f2l(int Popt,PUPANELL Ppupl,char *Pdata,char *Pdatabylc,int Poutbuffsz,int *Ppoutlen);//~va00R~
#endif                                                             //~va00I~
//#ifdef AAA                                                         //~vaucI~//~vavpR~
//#ifdef LNX                                                         //~vaubI~//~vavpR~
//    int panutilinigetDDFMT();                                      //~vaubI~//~vavpR~
//    int panutiliniputDDFMT();                                      //~vaubI~//~vavpR~
//#endif                                                             //~vaubI~//~vavpR~
//#endif//AAA                                                        //~vaucI~//~vavpR~
int pan23chkcpu8option(int Popt,char *Ppoptstr);                   //~vbkdI~
int	pan23ShowCmdResult(int Popt,PUCLIENTWE Ppcw,char *Pfnm);       //~vbkdI~
#define P23SCRO_CPU8           0x01 // cpu8 option                 //~vbkdI~
//**************************************************************** //~v76gI~
//* ini file put                                                   //~v76gI~
//* parm1 :pcw                                                     //~v76gI~
//* retrn:rc                                                       //~v76gI~
//**************************************************************** //~v76gI~
int panutiliniput(FILE *Pfh)                                       //~v76gR~
{                                                                  //~v76gI~
//  ULONG pandataver=1;                                            //~va5wR~
//  ULONG pandataver=2;                                            //~va5wI~//~va70R~
    UINT4 pandataver=2;                                            //~va70I~
#ifdef LNX                                                         //~vafwI~
	int ii;                                                        //~vafwI~
#endif                                                             //~vafwI~
//*****************                                                //~v76gI~
    fwrite(&pandataver,1,sizeof(pandataver),Pfh);                  //~v76gR~
    fwrite(Scompopt,1,sizeof(Scompopt),Pfh);                       //~v76gR~
//  fwrite(Scompfile1,1,sizeof(Scompfile1),Pfh);                   //~v76gR~//~vafwR~
    fwrite(Scompfile1,1,INIFNMSZ,Pfh);                             //~vafwI~
//  fwrite(Scompfile2,1,sizeof(Scompfile2),Pfh);                   //~v76gR~//~vafwR~
    fwrite(Scompfile2,1,INIFNMSZ,Pfh);                             //~vafwI~
    fwrite(Sgrepopt,1,sizeof(Sgrepopt),Pfh);                       //~v76gR~
#ifdef LNX                                                         //~vafwI~
    for (ii=0;ii<PANLUGFILENO;ii++)                                //~vafwI~
    	fwrite(Sgrepfile[ii],1,INIFNMSZ,Pfh);                      //~vafwR~
#else                                                              //~vafwI~
    fwrite(Sgrepfile,1,sizeof(Sgrepfile),Pfh);                     //~v76gR~
#endif                                                             //~vafwI~
    fwrite(Scompoptct,1,sizeof(Scompopt),Pfh);                     //~va5wI~
//  fwrite(Scompfile1ct,1,sizeof(Scompfile1),Pfh);                 //~va5wI~//~vafwR~
    fwrite(Scompfile1ct,1,INIFNMSZ,Pfh);                           //~vafwR~
//  fwrite(Scompfile2ct,1,sizeof(Scompfile2),Pfh);                 //~va5wI~//~vafwR~
    fwrite(Scompfile2ct,1,INIFNMSZ,Pfh);                           //~vafwR~
    fwrite(Sgrepoptct,1,sizeof(Sgrepopt),Pfh);                     //~va5wI~
#ifdef LNX                                                         //~vafwI~
    for (ii=0;ii<PANLUGFILENO;ii++)                                //~vafwI~
    	fwrite(Sgrepfilect[ii],1,INIFNMSZ,Pfh);                    //~vafwR~
#else                                                              //~vafwI~
    fwrite(Sgrepfilect,1,sizeof(Sgrepfile),Pfh);                   //~va5wI~
#endif                                                             //~vafwI~
//#ifdef AAA                                                         //~vaucI~//~vavpR~
//#ifdef LNX                                                         //~vaubM~//~vavpR~
//    panutiliniputDDFMT();                                          //~vaubI~//~vavpR~
//#endif                                                             //~vaubM~//~vavpR~
//#endif//AAA                                                        //~vaucI~//~vavpR~
    return 0;                                                      //~v76gI~
}//mpanutiliniput                                                  //~vaubR~
//**************************************************************** //~v76gI~
//* ini file get                                                   //~v76gI~
//* parm1 :pcw                                                     //~v76gI~
//* retrn:rc                                                       //~v76gI~
//**************************************************************** //~v76gI~
int panutiliniget(FILE *Pfh)                                       //~v76gR~
{                                                                  //~v76gI~
//  ULONG pandataver=1;                                            //~va5wR~
//  ULONG pandataver;                                              //~va5wI~//~va70R~
    UINT4 pandataver;                                              //~va70I~
#ifdef LNX                                                         //~vafwI~//~vavpR~
	int ii;                                                        //~vafwI~
#endif                                                             //~vafwI~
//*****************                                                //~v76gI~
    fread(&pandataver,1,sizeof(pandataver),Pfh);                   //~v76gR~
    fread(Scompopt,1,sizeof(Scompopt),Pfh);                        //~v76gR~
//  fread(Scompfile1,1,sizeof(Scompfile1),Pfh);                    //~v76gR~//~vafwR~
    fread(Scompfile1,1,INIFNMSZ,Pfh);                              //~vafwR~
//  fread(Scompfile2,1,sizeof(Scompfile2),Pfh);                    //~v76gR~//~vafwR~
    fread(Scompfile2,1,INIFNMSZ,Pfh);                              //~vafwR~
    fread(Sgrepopt,1,sizeof(Sgrepopt),Pfh);                        //~v76gR~
        UTRACED("Scompfile1",Scompfile1,INIFNMSZ);                 //~vaubI~
        UTRACED("Scompfile2",Scompfile2,INIFNMSZ);                 //~vaubI~
#ifdef LNX                                                         //~vafwI~//~vavpR~
    for (ii=0;ii<PANLUGFILENO;ii++)                                //~vafwI~
	    fread(Sgrepfile[ii],1,INIFNMSZ,Pfh);                       //~vafwR~
#else                                                              //~vafwI~
    fread(Sgrepfile,1,sizeof(Sgrepfile),Pfh);                      //~v76gR~
#endif                                                             //~vafwI~
    if (pandataver==2)                                             //~va5wR~
    {                                                              //~va5wI~
        fread(Scompoptct,1,sizeof(Scompopt),Pfh);                  //~va5wI~
//      fread(Scompfile1ct,1,sizeof(Scompfile1),Pfh);              //~va5wI~//~vafwR~
        fread(Scompfile1ct,1,INIFNMSZ,Pfh);                        //~vafwR~
//      fread(Scompfile2ct,1,sizeof(Scompfile2),Pfh);              //~va5wI~//~vafwR~
        fread(Scompfile2ct,1,INIFNMSZ,Pfh);                        //~vafwR~
        fread(Sgrepoptct,1,sizeof(Sgrepopt),Pfh);                  //~va5wI~
        UTRACED("Scompfile1ct",Scompfile1ct,INIFNMSZ);             //~vaubI~
        UTRACED("Scompfile2ct",Scompfile2ct,INIFNMSZ);             //~vaubI~
#ifdef LNX                                                         //~vafwI~//~vavpR~
    	for (ii=0;ii<PANLUGFILENO;ii++)                            //~vafwI~
	        fread(Sgrepfilect[ii],1,INIFNMSZ,Pfh);                 //~vafwR~
#else                                                              //~vafwI~
        fread(Sgrepfilect,1,sizeof(Sgrepfile),Pfh);                //~va5wI~
#endif                                                             //~vafwI~
		Sutilstat|=SUS_INICODETYPE;//codetype read from ini        //~va5wI~
    }                                                              //~va5wI~
//#ifdef AAA                                                         //~vaucI~//~vavpR~
//#ifdef LNX                                                         //~vaubI~//~vavpR~
//    panutilinigetDDFMT();                                          //~vaubR~//~vavpR~
//#endif                                                             //~vaubI~//~vavpR~
//#endif//AAA                                                        //~vaucI~//~vavpR~
    return 0;                                                      //~v76gI~
}//panutiliniget                                                   //~v76gR~
//**************************************************************** //~v075M~
//* compare utility panel                                          //~v76gR~
//* parm1 :pcw                                                     //~v075M~
//* retrn:rc                                                       //~v075M~
//**************************************************************** //~v075M~
int pancomp(PUCLIENTWE Ppcw)                                       //~v76gR~
{                                                                  //~v075M~
	PUCLIENTWE pcw;                                                //~v075M~
//*****************                                                //~v075M~
    pcw=panregist(PANUCOMP);		//callback wakeup & draw       //~v76gR~
    UALLOCCHK(pcw,8);               //return if storage shortage   //~v075M~
    return 0;                                                      //~v075M~
}//pancomp                                                         //~v76gR~
//**************************************************************** //~v76gI~
//* grep    utility panel                                          //~v76gR~
//* parm1 :pcw                                                     //~v76gI~
//* retrn:rc                                                       //~v76gI~
//**************************************************************** //~v76gI~
int pangrep(PUCLIENTWE Ppcw)                                       //~v76gI~
{                                                                  //~v76gI~
	PUCLIENTWE pcw;                                                //~v76gI~
//*****************                                                //~v76gI~
    pcw=panregist(PANUGREP);		//color option                 //~v76gI~
    UALLOCCHK(pcw,8);               //return if storage shortage   //~v76gI~
    return 0;                                                      //~v76gI~
}//pangrep                                                         //~v76gR~
//**************************************************************** //~v76gI~
//* 1st wakeup after regist                                        //~v76gR~
//* parm1 :pcw                                                     //~v76gI~
//* retrn:rc                                                       //~v76gI~
//**************************************************************** //~v76gI~
int pancompwakeup1(PUCLIENTWE Ppcw)                                //~v76gR~
{                                                                  //~v76gI~
	UFLDE  *pfle;                                                  //~v76gM~
	int rc;                                                        //~v76gR~
//*****************                                                //~v76gI~
    pfle=getuflde(Ppcw,PANLUCOPT,PANLUDATAFLD);                    //~v76gR~
    Sutilcolstart=pfle->UFLstart;                                  //~v76gR~
    if (rc=pancompdataproc(PANUO_INIT,Ppcw,0,0,0),rc)              //~v76gI~
        return rc;  //mem shortage                                 //~v76gI~
    pancompdataproc(PANUO_SETFLD|PANLUCOPT,Ppcw,0,0,0); //set to fld//~v76gR~
    pancompdataproc(PANUO_SETFLD|PANLUCFILE1,Ppcw,0,0,0);          //~v76gR~
    pancompdataproc(PANUO_SETFLD|PANLUCFILE2,Ppcw,0,0,0);          //~v76gR~
    return 0;                                                      //~v76gI~
}//pancompwakeup1                                                  //~v76gI~
//**************************************************************** //~v76gI~
//* 1st wakeup after regist                                        //~v76gI~
//* parm1 :pcw                                                     //~v76gI~
//* retrn:rc                                                       //~v76gI~
//**************************************************************** //~v76gI~
int pangrepwakeup1(PUCLIENTWE Ppcw)                                //~v76gI~
{                                                                  //~v76gI~
	UFLDE  *pfle;                                                  //~v76gI~
	int rc,yy;                                                     //~v76gR~
//*****************                                                //~v76gI~
    pfle=getuflde(Ppcw,PANLUGOPT,PANLUDATAFLD);                    //~v76gI~
    Sutilcolstart=pfle->UFLstart;                                  //~v76gI~
    if (rc=pangrepdataproc(PANUO_INIT,Ppcw,0,0,0),rc)              //~v76gI~
        return rc;  //mem shortage                                 //~v76gI~
    pancompdataproc(PANUO_SETFLD|PANLUGOPT,Ppcw,0,0,0); //set to fld//~v76gR~
    for (yy=PANLUGFILE1;yy<=PANLUGFILELAST;yy++)                   //~v76gI~
	    pancompdataproc(PANUO_SETFLD|yy,Ppcw,0,0,0);               //~v76gR~
    return 0;                                                      //~v76gI~
}//pangrepwakeup1                                                  //~v76gI~
//**************************************************************** //~v76gI~
//* compare utility draw                                           //~v76gI~
//* parm1 :pcw                                                     //~v76gI~
//* retrn:rc                                                       //~v76gI~
//**************************************************************** //~v76gI~
int pancompdraw(PUCLIENTWE Ppcw,int Popt)                          //~v76gI~
{                                                                  //~v76gI~
	PUSCRD  psd,psd0;                                              //~v76gI~
	PUPANELC ppc;                                                  //~v76gI~
	int cdrivesw=1,len;                                            //~v76gR~
    char  flddata[MAXCOLUMN];                                      //~v76gR~
	int yy,yyo,fulldrawsw;                                         //~v76gR~
    PUPANCOMP ppand;                                               //~v76gR~
#ifdef UNX                                                         //~v76gI~
#else                                                              //~v76gI~
    char  *pc;                                                     //~v76gI~
    int rc;                                                        //~v76gI~
#endif                                                             //~v76gI~
#ifdef UTF8SUPPH                                                   //~va0eI~
    char  *pch;                                                    //~va0eI~
#endif                                                             //~va0eI~
//*****************                                                //~v76gI~
    ppc=(PUPANELC)Ppcw->UCWppc;                                    //~v76gM~
	if (!UCBITCHK(ppc->UPCflag,UPCFWAKEN)) //1st time after regist,set old data//~v76gR~
    {                                                              //~v76gI~
		pancompwakeup1(Ppcw);                                      //~v76gI~
	    UCBITON(ppc->UPCflag,UPCFWAKEN); //1st time after regist,set old data//~v76gI~
    }                                                              //~v76gI~
    ppand=(PUPANCOMP)(ppc->UPCpandata);                            //~v76gR~
	fulldrawsw=UCBITCHK(Ppcw->UCWflag,UCWFDRAW);	//full draw    //~v76pR~
    psd0=Ppcw->UCWpsd;                                             //~v76gM~
    psd=psd0+PANLUCOPT;                                            //~v76gM~
	if (fulldrawsw||UCBITCHK(psd->USDflag2,USDF2DRAW))             //~v76gM~
    {                                                              //~v76gI~
		pancompdataproc(PANUO_GETDATA|PANLUCOPT,Ppcw,0,0,&len);	//get actual data len//~v76gR~
        if (len)                                                   //~v76gI~
			pancompdataproc(PANUO_SETFLD|PANUO_SETSAVE|PANLUCOPT,Ppcw,0,0,0);	//set to fld//~v76gR~
        else                                                       //~v76gI~
#ifdef UTF8SUPPH                                                   //~va0eI~
		{                                                          //~va0eI~
        	pch=PANUHELPMSG;                                       //~va0eI~
			pancompdataproc(PANUO_SETFLD|PANUO_SETSAVE|PANUO_HELPMSG|PANLUCOPT,Ppcw,&pch,0/*pdbcs*/,0/*outlen*/);	//set to fld//~va0eI~
        }                                                          //~va0eI~
#else                                                              //~va0eI~
			setflddata(Ppcw,PANLUCOPT,PANLUDATAFLD,PANUHELPMSG);   //~v76gR~
#endif                                                             //~va0eI~
    }                                                              //~v76gI~
    psd=psd0+PANLUCFILE1;                                          //~v76gM~
	if (fulldrawsw||UCBITCHK(psd->USDflag2,USDF2DRAW))             //~v76gM~
    {                                                              //~v76gI~
		pancompdataproc(PANUO_GETDATA|PANLUCFILE1,Ppcw,0,0,&len);	//get actual data len//~v76gR~
        if (len)                                                   //~v76gI~
			pancompdataproc(PANUO_SETFLD|PANUO_SETSAVE|PANLUCFILE1,Ppcw,0,0,0);	//set to fld//~v76gR~
        else                                                       //~v76gI~
#ifdef UTF8SUPPH                                                   //~va0eI~
		{                                                          //~va0eI~
        	pch=PANUHELPMSGFIND;                                   //~va0eI~
			pancompdataproc(PANUO_SETFLD|PANUO_SETSAVE|PANUO_HELPMSG|PANLUCFILE1,Ppcw,&pch,0/*pdbcs*/,0/*outlen*/);	//set to fld//~va0eR~
        }                                                          //~va0eI~
#else                                                              //~va0eI~
			setflddata(Ppcw,PANLUCFILE1,PANLUDATAFLD,PANUHELPMSGFIND);//~v76gR~
#endif                                                             //~va0eI~
    }                                                              //~v76gI~
    psd=psd0+PANLUCFILE2;                                          //~v76gM~
	if (fulldrawsw||UCBITCHK(psd->USDflag2,USDF2DRAW))             //~v76gM~
    {                                                              //~v76gI~
		pancompdataproc(PANUO_GETDATA|PANLUCFILE2,Ppcw,0,0,&len);	//get actual data len//~v76gR~
	    if (len)                                                   //~v76gI~
			pancompdataproc(PANUO_SETFLD|PANUO_SETSAVE|PANLUCFILE2,Ppcw,0,0,0);	//set to fld//~v76gR~
        else                                                       //~v76gI~
#ifdef UTF8SUPPH                                                   //~va0eI~
		{                                                          //~va0eI~
        	pch=PANUHELPMSGFIND2;                                  //~va0eI~
			pancompdataproc(PANUO_SETFLD|PANUO_SETSAVE|PANUO_HELPMSG|PANLUCFILE2,Ppcw,&pch,0/*pdbcs*/,0/*outlen*/);	//set to fld//~va0eR~
        }                                                          //~va0eI~
#else                                                              //~va0eI~
			setflddata(Ppcw,PANLUCFILE2,PANLUDATAFLD,PANUHELPMSGFIND2);//~v76gR~
#endif                                                             //~va0eI~
    }                                                              //~v76gI~
	yy=Ppcw->UCWrcsry;                                             //~v76gM~
    if (yy<Ppcw->UCWmaxline)    //csr is in the screen             //~v76gI~
    {                                                              //~v76gI~
#ifdef UNX                                                         //~v76gI~
#else                                                              //~v76gI~
        if (yy==PANLUCFILE1 || yy==PANLUCFILE2)                    //~v76gR~
        {                                                          //~v76gR~
#ifdef UTF8SUPPH                                                   //~va0eI~
            BYUTF8_getfldinput(0,Ppcw,yy,PANLUDATAFLD,flddata);//concat filename//~va0eI~
#else                                                              //~va0eI~
            getfldinput(Ppcw,yy,PANLUDATAFLD,flddata);//concat filename//~v76gR~
#endif                                                             //~va0eI~
            pc=flddata;                                            //~v76gR~
            if (*pc=='"'||*pc=='\'')                               //~v76gR~
                pc++;                                              //~v76gR~
            if (*pc && *(pc+1)==':')    //driveid changed          //~v76gR~
            {                                                      //~v76gR~
                *(pc+2)=0;  //driveid only                         //~v76gR~
                rc=panutilsetcdir(Ppcw,PANLUCCDIR,pc);             //~v76gR~
                if (!rc)                                           //~v76gR~
                    cdrivesw=0;                                    //~v76gR~
            }                                                      //~v76gR~
        }                                                          //~v76gR~
#endif                                                             //~v76gI~
//      if (cdrivesw)                                              //~v77cR~
//      {                                                          //~v77cR~
//          len=getfldinput(Ppcw,PANLUCCDIR,PANLUDATAFLD,flddata);//concat filename//~v77cR~
//          if (!len||fulldrawsw)   //not yet set                  //~v77cR~
//              panutilsetcdir(Ppcw,PANLUCCDIR,"." DIR_SEPS);      //~v77cR~
//      }                                                          //~v77cR~
//prepare for send                                                 //~v76gI~
        yyo=ppand->UPANCcsry;                                      //~v76gR~
        if (yy==PANLUCFILE1 || yy==PANLUCFILE2)                    //~v76gR~
        {                                                          //~v76gR~
            if (yy!=yyo)                                           //~v76gR~
            {                                                      //~v76gR~
                if (yyo)                                           //~v76gR~
                    panflderr(Ppcw,yyo,PANLUHDRFLD,PANFERESET|PANFEFORCE);    //set err reverse on cur csr//~v76gR~
                panflderr(Ppcw,yy,PANLUHDRFLD,PANFESET|PANFEKEEPCSR|PANFEFORCE);    //set err reverse on cur csr//~v76gR~
                ppand->UPANCcsry=yy;                               //~v76gR~
            }                                                      //~v76gR~
        }                                                          //~v76gR~
    }//csr is in the screen                                        //~v76gI~
    if (cdrivesw)                                                  //~v77cI~
    {                                                              //~v77cI~
        if (fulldrawsw                                             //~v77cI~
    	||  UCBITCHK((Ppcw->UCWpsd+PANLUCCDIR)->USDflag2,USDF2DRAW) //cd may changed by dcmddraw//~v77cI~
#ifndef AAA                                                        //~va0hR~
        ||  !getfldinput(Ppcw,PANLUCCDIR,0,flddata)//concat filename//~va0hI~
#else                                                              //~va0hI~
        ||  !getfldinput(Ppcw,PANLUCCDIR,PANLUDATAFLD,flddata)//concat filename//~v77cI~
#endif                                                             //~va0hI~
        )                                                          //~v77cI~
        {                                                          //~v77cI~
            panutilsetcdir(Ppcw,PANLUCCDIR,"." DIR_SEPS);          //~v77cI~
        }                                                          //~v77cI~
    }                                                              //~v77cI~
    return 0;                                                      //~v76gI~
}//pancompdraw                                                     //~v76gI~
#ifdef UTF8SUPPH                                                   //~v91mI~//~va00I~
//**************************************************               //~va5vI~
//*panutillf2dd                                                    //~va5vI~
//translate locale+utf8 mixed to dd fmt for utility fld            //~va5vI~
//**************************************************               //~va5vI~
int panutillf2dd(int Popt,PUCLIENTWE Ppcw,PUPANELL Ppupl,PUSCRD Ppsd,int Prow,int Pfldno,int Plclen)//~va5vR~
{                                                                  //~va5vI~
	UFLDE  *pfle;                                                  //~va5vI~
	UCHAR *pct,*pu8,*pdata,*pdbcs,*pdddbcs,*pdddata,*pcell,*pdd;    //~va5vR~//~va5wR~
    int len,outlen,fldposs,fldpose,u8len,fldw,ii;                  //~va5vR~
//**************************************************               //~va5vI~
	pfle=getuflde(Ppcw,Prow,Pfldno);                               //~va5vR~
	pdata=Ppsd->USDdata;                                           //~va5vI~
	pdbcs=Ppsd->USDdbcs;                                           //~va5vI~
    pct=Ppupl->UPLcodetype;                                        //~va5vI~
    pu8=Ppupl->UPLbuffbyutf8;                                      //~va5vI~
	fldposs=pfle->UFLstart;                                        //~va5vR~
	fldpose=pfle->UFLend;                                          //~va5vR~
    pdata+=fldposs;                                                //~va5vI~
    pdbcs+=fldposs;                                                //~va5vI~
    u8len=(int)strlen(pu8);                                        //~va5vI~
//if ((int)umemspnc(pu8,' ',u8len)==u8len)  //all space            //~vavyR~//~vb30R~
//if ((int)umemspnc(pu8,' ',(size_t)u8len)==u8len)  //all space    //~vb30I~//~vb31R~
  if ((int)umemspnc(pu8,' ',(unsigned)u8len)==u8len)  //all space  //~vb31I~
    outlen=0;                                                      //~vavyI~
  else                                                             //~vavyI~
  {                                                                //~vavyI~
    fldw=fldpose-fldposs;                                          //~va5vI~
	if (xeutfcvlf2dd(0,pu8,u8len,0/*pdbcs*/,pct,Plclen,&pdddata,&pdddbcs,fldw,&outlen)>4)//~va5vI~
    	return 4;                                                  //~va5vI~
    len=min(fldw,outlen);                                          //~va5vI~
    if (Ppsd->USDflag==USDFCELLSTR)	//err attr set,psd is by cell(data+attr)//~va5vI~
    {                                                              //~va5vI~
		for (pcell=Ppsd->USDcell+fldposs*2,pdd=pdddata,ii=0;ii<len;ii++,pcell++)//~va5vR~
        	*pcell++=*pdd++;                                       //~va5vR~
    }                                                              //~va5vI~
    else                            //psd is sddata and cell(2byte attr)//~va5vI~
//  	memcpy(pdata,pdddata,len);   //ddstr                       //~va5vR~//~vb30R~
    	memcpy(pdata,pdddata,(size_t)len);   //ddstr               //~vb30I~
//  memcpy(pdbcs,pdddbcs,len);   //ddstr                           //~va5vR~//~vb30R~
    memcpy(pdbcs,pdddbcs,(size_t)len);   //ddstr                   //~vb30I~
  }                                                                //~vavyI~
    pdata+=outlen;                                                 //~va5vI~
    pdbcs+=outlen;                                                 //~va5vI~
    return 0;                                                      //~va5vI~
}//panutillf2dd                                                    //~va5vR~
//**************************************************************** //~v91mI~//~va00I~
//* compare utility draw mixed code fld                            //~v91mI~//~va00I~
//* parm1 :pcw                                                     //~v91mI~//~va00I~
//* retrn:rc                                                       //~v91mI~//~va00I~
//**************************************************************** //~v91mI~//~va00I~
int pancompdraw2(int Popt,PUCLIENTWE Ppcw,PUSCRD Ppsd,int Pyy)     //~v91mR~//~va00I~
{                                                                  //~v91mI~//~va00I~
	PUPANELC ppc;                                                  //~v91mI~//~va00I~
	PUPANELL pupl;                                                 //~va00I~
    int fnmlen,fldno=0;                                              //~v91mR~//~vaf9R~
    char *pct;                                                     //~va00R~
//*****************                                                //~v91mI~//~va00I~
    UTRACEP("%s:row=%d\n",UTT,Pyy);                                //~vba0I~
    ppc=(PUPANELC)Ppcw->UCWppc;                                    //~v91mI~//~va00I~
	if (!(UCBITCHK(Ppcw->UCWflag,UCWFDRAW)||UCBITCHK(Ppsd->USDflag2,USDF2DRAW)))//~v91mR~//~va00I~
    	return 0;                                                  //~v91mI~//~va00I~
    pupl=ppc->UPCline+Pyy;                                         //~va00R~
    pct=pupl->UPLcodetype;                                         //~va00I~
    switch(Pyy)                                                    //~va00I~
    {                                                              //~va00I~
    case PANLUCCDIR:                                               //~va00I~
    	fldno=PANLUCDIRFLD;                                        //~va00I~
        break;                                                     //~va00I~
    case PANLUCFILE1:                                              //~va00I~
    case PANLUCFILE2:                                              //~va00I~
    	fldno=PANLUDATAFLD;                                        //~va00I~
        break;                                                     //~va00I~
    }                                                              //~va00I~
    if (pct) //contains utf8 code                                  //~va00R~
    {                                                              //~va00I~
//  	fnmlen=pupl->UPLctlen;                                     //~va00I~
    	fnmlen=(int)strlen(pupl->UPLbuff);                         //~va00I~
        panutillf2dd(0,Ppcw,pupl,Ppsd,Pyy,fldno,fnmlen);           //~va5vI~
        pansetfnmattr(Ppcw,Ppsd,Pyy,fldno,pct,fnmlen);             //~va00R~
    }                                                              //~va00I~
    return 1;                                                     //~v91mR~//~va00R~
}//pancompdraw2                                                    //~v91mR~//~va00I~
#endif  //UTF8SUPPH                                               //~v91mI~//~va00I~
//**************************************************************** //~v76gM~
//* grep    utility draw                                           //~v76gM~
//* parm1 :pcw                                                     //~v76gM~
//* retrn:rc                                                       //~v76gM~
//**************************************************************** //~v76gM~
int pangrepdraw(PUCLIENTWE Ppcw,int Popt)                          //~v76gM~
{                                                                  //~v76gM~
	PUSCRD  psd,psd0;                                              //~v76gI~
	PUPANELC ppc;                                                  //~v76gI~
	int cdrivesw=1,len;                                            //~v76gI~
    char  flddata[MAXCOLUMN];                                      //~v76gI~
	int yy,yyo,fulldrawsw;                                         //~v76gI~
    PUPANGREP ppand;                                               //~v76gI~
    char *helpmsgtb[]={                                            //~v76gI~
	                PANUHELPMSGFIND                                //~v76gR~
					,PANUHELPMSGFIND2                              //~v76gR~
					,PANUHELPMSGOPTFNM                             //~v76gR~
#ifdef WXEXXE                                                      //~v76gI~
					,PANUHELPMSGDND                                //~v76gI~
#endif                                                             //~v76gI~
					,PANUHELPMSGRESET                              //~v76gI~
                    };                                             //~v76gI~
    int idx;                                                       //~v76gR~
#ifdef UNX                                                         //~v76gI~
#else                                                              //~v76gI~
    char  *pc;                                                     //~v76gI~
    int rc;                                                        //~v76gI~
#endif                                                             //~v76gI~
#ifdef UTF8SUPPH                                                   //~va0eI~
    char  *pch;                                                    //~va0eI~
#endif                                                             //~va0eI~
//*****************                                                //~v76gI~
    ppc=(PUPANELC)Ppcw->UCWppc;                                    //~v76gI~
	if (!UCBITCHK(ppc->UPCflag,UPCFWAKEN)) //1st time after regist,set old data//~v76gI~
    {                                                              //~v76gI~
		pangrepwakeup1(Ppcw);                                      //~v76gI~
	    UCBITON(ppc->UPCflag,UPCFWAKEN); //1st time after regist,set old data//~v76gI~
    }                                                              //~v76gI~
    ppand=(PUPANGREP)(ppc->UPCpandata);                            //~v76gI~
	fulldrawsw=UCBITCHK(Ppcw->UCWflag,UCWFDRAW);	//full draw    //~v76pR~
    psd0=Ppcw->UCWpsd;                                             //~v76gI~
    psd=psd0+PANLUGOPT;                                            //~v76gR~
	if (fulldrawsw||UCBITCHK(psd->USDflag2,USDF2DRAW))             //~v76gI~
    {                                                              //~v76gI~
		pangrepdataproc(PANUO_GETDATA|PANLUGOPT,Ppcw,0,0,&len);	//get actual data len//~v76gR~
        if (len)                                                   //~v76gI~
			pangrepdataproc(PANUO_SETFLD|PANUO_SETSAVE|PANLUGOPT,Ppcw,0,0,0);	//set to fld//~v76gR~
        else                                                       //~v76gI~
#ifdef UTF8SUPPH                                                   //~va0eI~
		{                                                          //~va0eI~
        	pch=PANUHELPMSGGREP;                                   //~va0eI~
			pangrepdataproc(PANUO_SETFLD|PANUO_SETSAVE|PANUO_HELPMSG|PANLUGOPT,Ppcw,&pch,0/*pdbcs*/,0/*outlen*/);	//set to fld//~va0eR~
        }                                                          //~va0eI~
#else                                                              //~va0eI~
			setflddata(Ppcw,PANLUGOPT,PANLUDATAFLD,PANUHELPMSGGREP);//~v76gR~
#endif                                                             //~va0eI~
    }                                                              //~v76gI~
    psd=psd0+PANLUGFILE1;                                          //~v76gR~
    for (yy=PANLUGFILE1;yy<=PANLUGFILELAST;yy++,psd++)             //~v76gI~
    {                                                              //~v76gI~
        if (fulldrawsw||UCBITCHK(psd->USDflag2,USDF2DRAW))         //~v76gI~
        {                                                          //~v76gI~
            pangrepdataproc(PANUO_GETDATA|yy,Ppcw,0,0,&len);   //get actual data len//~v76gR~
            if (len)                                               //~v76gI~
	            pangrepdataproc(PANUO_SETFLD|PANUO_SETSAVE|yy,Ppcw,0,0,0);  //set to fld//~v76gR~
            else                                                   //~v76gI~
            {                                                      //~v76gI~
            	idx=yy-PANLUGFILE1;                                //~v76gR~
#ifdef UTF8SUPPH                                                   //~va0eI~
//              if (idx<sizeof(helpmsgtb)/4)                       //~va0eI~//~vba0R~
                if (idx<sizeof(helpmsgtb)/PTRSZ)                   //~vba0I~
        			pch=helpmsgtb[idx];                            //~va0eI~
                else                                               //~va0eI~
                	pch="";                                        //~va0eI~
				pangrepdataproc(PANUO_SETFLD|PANUO_SETSAVE|PANUO_HELPMSG|yy,Ppcw,&pch,0/*pdbcs*/,0/*outlen*/);	//set to fld//~va0eR~
#else                                                              //~va0eI~
//              if (idx<sizeof(helpmsgtb)/4)                       //~v76gR~//~vba0R~
                if (idx<sizeof(helpmsgtb)/PTRSZ)                   //~vba0I~
	                setflddata(Ppcw,yy,PANLUDATAFLD,helpmsgtb[idx]);//~v76gR~
                else                                               //~v76pI~
	                setflddata(Ppcw,yy,PANLUDATAFLD,"");    //should clear//~v76pI~
#endif                                                             //~va0eI~
            }                                                      //~v76gI~
        }                                                          //~v76gI~
    }                                                              //~v76gI~
	yy=Ppcw->UCWrcsry;                                             //~v76gI~
    if (yy<Ppcw->UCWmaxline)    //csr is in the screen             //~v76gI~
    {                                                              //~v76gI~
#ifdef UNX                                                         //~v76gI~
#else                                                              //~v76gI~
        if ((yy>=PANLUGFILE1 && yy<=PANLUGFILELAST))               //~v76gI~
        {                                                          //~v76gR~
#ifdef UTF8SUPPH                                                   //~va0eI~
            BYUTF8_getfldinput(0,Ppcw,yy,PANLUDATAFLD,flddata);//concat filename//~va0eI~
#else                                                              //~va0eI~
            getfldinput(Ppcw,yy,PANLUDATAFLD,flddata);//concat filename//~v76gR~
#endif                                                             //~va0eI~
            pc=flddata;                                            //~v76gR~
            if (*pc=='"'||*pc=='\'')                               //~v76gR~
                pc++;                                              //~v76gR~
            if (*pc && *(pc+1)==':')    //driveid changed          //~v76gR~
            {                                                      //~v76gR~
                *(pc+2)=0;  //driveid only                         //~v76gR~
                rc=panutilsetcdir(Ppcw,PANLUGCDIR,pc);             //~v76gR~
                if (!rc)                                           //~v76gR~
                    cdrivesw=0;                                    //~v76gR~
            }                                                      //~v76gR~
        }                                                          //~v76gR~
#endif                                                             //~v76gI~
//      if (cdrivesw)                                              //~v77cR~
//      {                                                          //~v77cR~
//          len=getfldinput(Ppcw,PANLUGCDIR,PANLUDATAFLD,flddata);//concat filename//~v77cR~
//          if (!len||fulldrawsw)   //not yet set                  //~v77cR~
//              panutilsetcdir(Ppcw,PANLUGCDIR,"." DIR_SEPS);      //~v77cR~
//      }                                                          //~v77cR~
//prepare for send                                                 //~v76gI~
        yyo=ppand->UPANGcsry;                                      //~v76gR~
        if (yy>=PANLUGFILE1 && yy<=PANLUGFILELAST)                 //~v76gR~
        {                                                          //~v76gR~
            if (yy!=yyo)                                           //~v76gR~
            {                                                      //~v76gR~
                if (yyo)                                           //~v76gR~
                    panflderr(Ppcw,yyo,PANLUHDRFLD,PANFERESET|PANFEFORCE);    //set err reverse on cur csr//~v76gR~
                panflderr(Ppcw,yy,PANLUHDRFLD,PANFESET|PANFEKEEPCSR|PANFEFORCE);    //set err reverse on cur csr//~v76gR~
                ppand->UPANGcsry=yy;                               //~v76gR~
            }                                                      //~v76gR~
        }                                                          //~v76gR~
    }//csr is in the screen                                        //~v76gI~
    if (cdrivesw)                                                  //~v77cI~
    {                                                              //~v77cI~
        if (fulldrawsw                                             //~v77cI~
    	||  UCBITCHK((Ppcw->UCWpsd+PANLUGCDIR)->USDflag2,USDF2DRAW) //cd may changed by dcmddraw//~v77cI~
#ifndef AAA                                                        //~va0hR~
        ||  !getfldinput(Ppcw,PANLUGCDIR,0,flddata) //concat filename//~va0hI~
#else                                                              //~va0hI~
        ||  !getfldinput(Ppcw,PANLUGCDIR,PANLUDATAFLD,flddata) //concat filename//~v77cI~
#endif                                                             //~va0hI~
        )                                                          //~v77cI~
        {                                                          //~v77cI~
            panutilsetcdir(Ppcw,PANLUGCDIR,"." DIR_SEPS);          //~va0hR~
        }                                                          //~v77cI~
    }                                                              //~v77cI~
    return 0;                                                      //~v76gM~
}//pangrepdraw                                                     //~v76gM~
#ifdef UTF8SUPPH                                                   //~v91mI~//~va00I~
//**************************************************************** //~v91mI~//~va00I~
//* grep    utility draw  mixed code fld                           //~v91mI~//~va00I~
//* parm1 :pcw                                                     //~v91mI~//~va00I~
//* retrn:rc                                                       //~v91mI~//~va00I~
//**************************************************************** //~v91mI~//~va00I~
int pangrepdraw2(int Popt,PUCLIENTWE Ppcw,PUSCRD Ppsd,int Pyy)     //~v91mR~//~va00I~
{                                                                  //~v91mI~//~va00I~
	PUPANELC ppc;                                                  //~v91mI~//~va00I~
	PUPANELL pupl;                                                 //~va00I~
	int fnmlen,fldno=0;                                                    //~v91mR~//~vaf9R~
    char *pct;                                                     //~va00R~
//*****************                                                //~v91mI~//~va00I~
    ppc=(PUPANELC)Ppcw->UCWppc;                                    //~v91mI~//~va00I~
	if (!(UCBITCHK(Ppcw->UCWflag,UCWFDRAW)||UCBITCHK(Ppsd->USDflag2,USDF2DRAW)))//~v91mI~//~va00I~
    	return 0;                                                  //~v91mI~//~va00I~
    pupl=ppc->UPCline+Pyy;                                         //~va00R~
    pct=pupl->UPLcodetype;                                         //~va00I~
    if (Pyy==PANLUGOPT)                                            //~va0EI~
    	fldno=PANLUDATAFLD;                                        //~va0EI~
    else                                                           //~va0EI~
    if (Pyy==PANLUGCDIR                                            //~va00I~
    || (Pyy>=PANLUGFILE1 && Pyy<=PANLUGFILELAST)                   //~va00I~
    )                                                              //~va00I~
    {                                                              //~va00I~
	    if (Pyy==PANLUGCDIR)                                       //~va00I~
    		fldno=PANLUCDIRFLD;                                    //~va00I~
        else                                                       //~va00I~
    		fldno=PANLUDATAFLD;                                    //~va00I~
    }                                                              //~va00I~
    if (pct) //contains utf8 code                                  //~va00R~
    {                                                              //~va00I~
//      fnmlen=pupl->UPLctlen;                                     //~va00M~
        fnmlen=(int)strlen(pupl->UPLbuff);                         //~va00M~
        panutillf2dd(0,Ppcw,pupl,Ppsd,Pyy,fldno,fnmlen);           //~va5vI~
        pansetfnmattr(Ppcw,Ppsd,Pyy,fldno,pct,fnmlen);             //~va00R~
    }                                                              //~va00I~
    return 1;                                                      //~v91mR~//~va00R~
}//pangrepdraw2                                                    //~v91mR~//~va00I~
#endif  //UTF8SUPPH                                                //~v91mI~//~va00I~
//**************************************************************** //~v76gI~
//* compare utility exec                                           //~v76gI~
//* parm1 :pcw                                                     //~v76gI~
//* retrn:rc                                                       //~v76gI~
//**************************************************************** //~v76gI~
int pancompexec(PUCLIENTWE Ppcw)                                   //~v76gI~
{                                                                  //~v76gI~
	char  utilopt[MAXCOLUMN],compfile1[_MAX_PATH],compfile2[_MAX_PATH];//~v76gR~
	char  compfpath1[_MAX_PATH],compfpath2[_MAX_PATH];             //~v76gI~
//  char  cmdstr[MAXCOLUMN+_MAX_PATH+_MAX_PATH],*pc;               //~v76gR~//+vbs7R~
    char  cmdstr[MAXCOLUMN+_MAX_PATH+_MAX_PATH+1],*pc;             //+vbs7I~
    char  redirectfnm[_MAX_PATH],*pcmdnm;                          //~v76gR~
    int leno,lenf1,lenf2,len,rc,redirectctr,helpsw,swnolist=0;     //~v76gR~
    int dirsw1=-1,dirsw2=-1,opt;                                   //~v76pR~
    FILEFINDBUF3 ffb3;                                             //~v76gI~
#ifdef FTPSUPP                                                     //~v76pI~
//	PUFTPHOST puftph1=(PUFTPHOST)-1,puftph2=(PUFTPHOST)-1;         //~v76pR~//~vafkR~
	PUFTPHOST puftph1=(PUFTPHOST)(ULPTR)-1,puftph2=(PUFTPHOST)(ULPTR)-1;//~vafkI~
#endif                                                             //~v76pI~
	int swcpu8=0;                                                  //~vbkdI~
//*****************                                                //~v76gI~
    pc=utilopt;                                                    //~v76gR~
    pancompdataproc(PANUO_GETDATA|PANLUCOPT,Ppcw,&pc,0,&leno);     //~v76gR~
    if (leno && *utilopt=='?')	//help                             //~v76gR~
    {                                                              //~v76gI~
    	*utilopt=0;                                                //~v76gR~
        *compfpath1=0;                                             //~v76gI~
        *compfpath2=0;                                             //~v76gI~
	    len=sprintf(cmdstr,"%s %s",Gcomparecmdf,utilopt+1);        //~v76gR~
        helpsw=1;                                                  //~v76gI~
    }                                                              //~v76gI~
    else                                                           //~v76gI~
    if (leno && !strcmp(pc,"--help"))	//help                     //~v76gR~
    {                                                              //~v76gI~
        *compfpath1=0;                                             //~v76gI~
        *compfpath2=0;                                             //~v76gI~
	    len=sprintf(cmdstr,"%s %s",Gcomparecmdf,utilopt);          //~v76gI~
        helpsw=2;                                                  //~v76gR~
    }                                                              //~v76gI~
    else                                                           //~v76gI~
    {                                                              //~v76gI~
        if (leno && pan23chkcpu8option(0,pc))                      //~vbkdI~
        {                                                          //~vbkdI~
            swcpu8=P23SCRO_CPU8; //           0x01 // cpu8 option  //~vbkdI~
        }                                                          //~vbkdI~
    	pc=ustrstri(utilopt,PANUOPTNOLIST);                        //~v76gR~
        if (pc)                                                    //~v76gI~
        {                                                          //~v76gI~
        	swnolist=1;                                            //~v76gI~
            memset(pc,' ',sizeof(PANUOPTNOLIST)-1);                //~v76gI~
        }                                                          //~v76gI~
        helpsw=0;                                                  //~v76gI~
        pc=compfile1;                                              //~v76gR~
        pancompdataproc(PANUO_GETDATA|PANLUCFILE1,Ppcw,&pc,0,&lenf1);//~v76gR~
#ifdef W32UNICODE                                                  //~vavNI~
		if (SfnmUDlen)                                             //~vavNI~
        	strcpy(pc,SfnmUD);                                     //~vavNI~
#endif                                                             //~vavNI~
        pc=compfile2;                                              //~v76gR~
        pancompdataproc(PANUO_GETDATA|PANLUCFILE2,Ppcw,&pc,0,&lenf2);//~v76gR~
    	if (!lenf1 || !lenf2)                                      //~v76gR~
    	{                                                          //~v76gI~
    		uerrmsg("fill both filespec line.",                    //~v76gI~
        		"ファイル指定をしてください");                     //~v76gR~
        	return 0;                                              //~v76gR~
    	}                                                          //~v76gI~
#ifdef W32UNICODE                                                  //~vavNI~
		if (SfnmUDlen)                                             //~vavNI~
        	strcpy(pc,SfnmUD);                                     //~vavNI~
#endif                                                             //~vavNI~
        opt=FFPA_WILDPATH|FFPA_WILDMEMB;	//resolve wild pathg   //~v76pR~
    	if (filefullpatha(opt,0,compfile1,0,compfpath1,0))//0:pcw,localfilename,out local fpath//~v76pR~
        	return 4;                                              //~v76pR~
    	if (filefullpatha(opt,0,compfile2,0,compfpath2,0))//0:pcw,localfilename,out local fpath//~v76pR~
        	return 4;                                              //~v76pI~
#ifdef FTPSUPP
		rc=dlccompchkfiletype(compfpath1,compfpath2,&puftph1,&puftph2,&dirsw1,&dirsw2);//get local copy if remote//~v76pR~
        if (rc)                                                    //~v76pI~
        	return rc;                                             //~v76pI~
      if (!puftph1 && !puftph2)	//both local                       //~v76pR~
#endif
      {                                                            //~v76pI~
	    dirsw1=!ufstat(compfpath1,&ffb3) && (ffb3.attrFile & FILE_DIRECTORY);//~v76gR~
        if (dirsw1)                                                //~v76gI~
	        dirsw2=!ufstat(compfpath2,&ffb3) && (ffb3.attrFile & FILE_DIRECTORY);//~v76gR~
      }                                                            //~v76pI~
        if (dirsw1 && dirsw2)                                      //~v76gI~
        	pcmdnm=Gcomparecmdd;                                   //~v76gR~
        else                                                       //~v76gI~
        	pcmdnm=Gcomparecmdf;                                   //~v76gR~
//      len=sprintf(cmdstr,"%s %s \"%s\" \"%s\"",pcmdnm,utilopt,compfpath1,compfpath2);//~v76pR~
        ufilenameenclose(0,compfpath1,compfpath1);                 //~v76pI~
        ufilenameenclose(0,compfpath2,compfpath2);                 //~v76pI~
        len=sprintf(cmdstr,"%s %s %s %s",pcmdnm,utilopt,compfpath1,compfpath2);//~v76pI~
    }                                                              //~v76gI~
	redirectctr=++Gcompctr;                                        //~v76gI~
    rc=dcmd_comparedlcmd(Ppcw,cmdstr,len,redirectfnm,redirectctr); //~v76gI~
    if (helpsw)	//append xdc help                                  //~v76gR~
    {                                                              //~v76gI~
	    len=sprintf(cmdstr,"%s %s",Gcomparecmdd,utilopt+2-helpsw); //~v76gR~
	    rc+=dcmd_comparedlcmd(Ppcw,cmdstr,len,redirectfnm,redirectctr);//~v76gI~
    }                                                              //~v76gI~
//edit/browse redirect file at last                                //~v76gI~
    Ppcw->UCWparm=redirectfnm;                                     //~v76gR~
    if (!swnolist)                                                 //~v76gI~
#ifdef AAA                                                         //~vbkdM~
#ifdef UTF8SUPPH                                                   //~va00I~
    	func_edit_file2(Ppcw,FEBFIO_UTF8IE); //internal edit call;ignor utf8 trans err//~va00M~
#else                                                              //~va00M~
    	func_edit_file2(Ppcw,0);	//internal edit call           //~va00I~
#endif                                                             //~va00I~
#else                                                              //~vbkdI~
		pan23ShowCmdResult(swcpu8,Ppcw,redirectfnm);               //~vbkdR~
#endif                                                             //~vbkdI~
    return rc;                                                     //~v76gI~
}//pancompexec                                                     //~v76gR~
#ifdef UTF8SUPPH                                                   //~va1qI~
//**************************************************************** //~va0dI~
//* chk file parameter exist for grep                              //~va0dI~
//* return posparm count                                           //~va0dI~
//**************************************************************** //~va0dI~
int panchkposparm(char *Pparm)                                     //~va0dI~
{                                                                  //~va0dI~
	int opdno,rc,ii,posparm=0;                                     //~va0dR~
    char *parm,**argv;                                             //~va0dI~
	char  wkpot[MAXCOLUMN*2];                                      //~va0dI~
//***************************                                      //~va0dI~
	parm=wkpot;	//parseout area                                    //~va0dI~
    rc=uparsecmd(0,Pparm,&opdno,&parm,&argv,0);//no delmt          //~va0dI~
    if (rc) //uparsev err                                          //~va0dI~
        return 0;	//no posparm                                   //~va0dI~
    for (ii=opdno;ii>0;ii--,argv++)                                //~va0dI~
    {                                                              //~va0dI~
    	parm=*argv;                                                //~va0dI~
    	if (*parm=='-'                                             //~va0dI~
#ifndef UNX                                                        //~va0dI~
    	||  *parm=='/'                                             //~va0dI~
#endif                                                             //~va0dI~
        )                                                          //~va0dI~
        {                                                          //~va0dI~
        	if (*(parm+1))                                         //~va0dI~
            	continue;                                          //~va0dI~
            ii--;                                                  //~va0dI~
            argv++;                                                //~va0dI~
        }                                                          //~va0dI~
        else                                                       //~va0dI~
        	posparm++;  //posparm found                            //~va0dR~
    }                                                              //~va0dI~
    return posparm;                                                //~va0dR~
}//panchkposparm                                                   //~va0dI~
#endif                                                             //~va1qI~
                                                                   //~va1qI~
//**************************************************************** //~v76gI~
//* grep utility exec                                              //~v76gR~
//* parm1 :pcw                                                     //~v76gI~
//* retrn:rc                                                       //~v76gI~
//**************************************************************** //~v76gI~
int pangrepexec(PUCLIENTWE Ppcw)                                   //~v76gR~
{                                                                  //~v76gI~
    FILEFINDBUF3 ffb3;                                             //~v76gI~
	char  utilopt[MAXCOLUMN]/*,optfile[_MAX_PATH]*/;               //~v76gR~
	char  cmdhelp[MAXCOLUMN];                                      //~v76gI~
	char  fnm[_MAX_PATH],fpath[_MAX_PATH];                         //~v76gI~
	char  *pcmdstr,*pc;                                            //~v76gR~
    char  redirectfnm[_MAX_PATH];                                  //~v76gR~
    int swfree=0;                                                  //~v76gI~
    int dirsw[PANLUGFILENO];                                       //~v76gI~
    int lenopt,/*lenoptf,*/lenfnm,yy,len,rc,redirectctr,swnolist=0,cmdstrlen;//~v76gR~
#ifdef UTF8SUPPH                                                   //~va1qI~
    int parmsw=0,optpctr;                                          //~va0dR~
#endif                                                             //~va1qI~
//*****************                                                //~v76gI~
    pc=utilopt;                                                    //~v76gI~
    pangrepdataproc(PANUO_GETDATA|PANLUGOPT,Ppcw,&pc,0,&lenopt);   //~v76gR~
    if (lenopt && *pc=='?')	//help                                 //~v76gR~
    {                                                              //~v76gI~
    	*pc=0;                                                     //~v76gR~
	    len=sprintf(cmdhelp,"%s %s",Ggrepcmd,pc+1);                //~v76gR~
        pcmdstr=cmdhelp;                                           //~v76gR~
    }                                                              //~v76gI~
    else                                                           //~v76gI~
    if (lenopt && !strcmp(pc,"--help"))	//help                     //~v76gR~
    {                                                              //~v76gI~
	    len=sprintf(cmdhelp,"%s %s",Ggrepcmd,pc);                  //~v76gR~
        pcmdstr=cmdhelp;                                           //~v76gR~
    }                                                              //~v76gI~
    else                                                           //~v76gI~
    {                                                              //~v76gI~
    	cmdstrlen=(int)strlen(Ggrepcmd)+1+lenopt+1;                     //~v76gR~
    	pc=ustrstri(utilopt,PANUOPTNOLIST);                        //~v76gI~
        if (pc)                                                    //~v76gI~
        {                                                          //~v76gI~
        	swnolist=1;                                            //~v76gI~
            memset(pc,' ',sizeof(PANUOPTNOLIST)-1);                //~v76gI~
        }                                                          //~v76gI~
        for (yy=PANLUGFILE1;yy<=PANLUGFILELAST;yy++)               //~v76gI~
        {                                                          //~v76gI~
            dirsw[yy-PANLUGFILE1]=0;                               //~v76gR~
	        pc=fnm;                                                //~v76gI~
		    pangrepdataproc(PANUO_GETDATA|yy,Ppcw,&pc,0,&lenfnm);  //~v76gR~
#ifdef W32UNICODE         //grep dose not understand UD fmt        //~vavNR~
            if (SfnmUDlen)                                         //~vavNR~
            {                                                      //~vavNI~
                lenfnm=SfnmUDlen;                                  //~vavNR~
                UmemcpyZ(pc,SfnmUD,lenfnm);                        //~vavNI~
            }                                                      //~vavNI~
#endif                                                             //~vavNR~
            if (lenfnm)                                            //~v76gI~
            {                                                      //~v76gI~
#ifdef UTF8SUPPH                                                   //~va1qI~
                parmsw=1;                                          //~va0dI~
#endif                                                             //~va1qI~
	            cmdstrlen+=lenfnm+1;	//space delm               //~v76gR~
		    	Gsubgblopt|=XESUB_GBLOPT_WILDPATH;                 //~v76gI~
    			pc=filefullpath(fpath,fnm,_MAX_PATH);              //~v76gI~
//  	    	Gsubgblopt|=XESUB_GBLOPT_WILDPATH;                 //~vb4BR~
    	    	Gsubgblopt&=~XESUB_GBLOPT_WILDPATH;                //~vb4BI~
        		if (!pc)     	//fullpath err                     //~v76gI~
        			return 4;                                      //~v76gI~
                if (!WILDCARD(fpath))                              //~v76gI~
                {                                                  //~v76gI~
	    			if (ufstat(fpath,&ffb3))                       //~v76gI~
                    	return ufilenotfound(fpath,4);             //~v76gR~
	        		if (ffb3.attrFile & FILE_DIRECTORY)            //~v76gI~
                	{                                              //~v76gI~
                		dirsw[yy-PANLUGFILE1]=1;                   //~v76gR~
//                  	cmdstrlen+=sizeof(DIR_ALLMEMB);            //~v76gI~//~vb30R~
                    	cmdstrlen+=(int)sizeof(DIR_ALLMEMB);       //~vb30I~
                	}                                              //~v76gI~
                }                                                  //~v76gI~
            }                                                      //~v76gI~
        }                                                          //~v76gI~
#ifdef UTF8SUPPH                                                   //~va1qI~
        optpctr=panchkposparm(utilopt);                            //~va0dR~
        if (!optpctr)                                              //~va0dI~
        {                                                          //~va0dI~
            uerrmsg("Missing search string parameter",0);          //~va0dI~
            return 4;                                              //~va0dI~
        }                                                          //~va0dI~
        parmsw+=optpctr;                                           //~va0dI~
        if (parmsw<2)                                              //~va0dR~
        {                                                          //~va0dR~
            uerrmsg("Missing file/dir parameter",0);               //~va0dR~
            return 4;                                              //~va0dR~
        }                                                          //~va0dR~
#endif                                                             //~va1qI~
    	pcmdstr=pc=umalloc((UINT)cmdstrlen+1);	//1:last null      //~v76gR~
        UALLOCCHK(pc,UALLOC_FAILED);	//return if storage        //~v76gI~
        swfree=1;                                                  //~v76gI~
	    pc+=sprintf(pc,"%s %s ",Ggrepcmd,utilopt);                 //~v76gR~
        for (yy=PANLUGFILE1;yy<=PANLUGFILELAST;yy++)               //~v76gI~
        {                                                          //~v76gI~
		    pangrepdataproc(PANUO_GETDATA|yy,Ppcw,&pc,0,&lenfnm);  //~v76gR~
#ifdef W32UNICODE         //grep dose not understand UD fmt        //~vavNR~
            if (SfnmUDlen)                                         //~vavNR~
            {                                                      //~vavNR~
                lenfnm=SfnmUDlen;                                  //~vavNR~
                UmemcpyZ(pc,SfnmUD,lenfnm);                        //~vavNR~
            }                                                      //~vavNR~
#endif                                                             //~vavNR~
            if (lenfnm)                                            //~v76gI~
            {                                                      //~v76gI~
            	pc+=lenfnm;                                        //~v76gI~
                if (dirsw[yy-PANLUGFILE1])                         //~v76gI~
                {                                                  //~v76gI~
                	pc+=sprintf(pc,"%c%s",DIR_SEPC,DIR_ALLMEMB);   //~v76gR~
                }                                                  //~v76gI~
                *pc++=' ';                                         //~v76gI~
            }                                                      //~v76gI~
        }                                                          //~v76gI~
        *pc=0;                                                     //~v76gI~
//      len=(int)((ULONG)pc-(ULONG)pcmdstr);                       //~v76gR~//~vafkR~
        len=(int)((ULPTR)pc-(ULPTR)pcmdstr);                       //~vafkI~
    }                                                              //~v76gI~
	redirectctr=++Ggrepctr;                                        //~v76gI~
    rc=dcmd_grepdlcmd(Ppcw,pcmdstr,len,redirectfnm,redirectctr);   //~v76gR~
    if (swfree)                                                    //~v76gI~
        ufree(pcmdstr);                                            //~v76gR~
//edit/browse redirect file at last                                //~v76gI~
    Ppcw->UCWparm=redirectfnm;                                     //~v76gI~
    if (!swnolist)                                                 //~v76gI~
#ifdef UTF8SUPPH                                                   //~va00I~
    	func_edit_file2(Ppcw,FEBFIO_UTF8IE); //internal edit call;ignor utf8 trans err//~va00M~
#else                                                              //~va00M~
    	func_edit_file2(Ppcw,0);	//internal edit call           //~v76gI~
#endif                                                             //~va00I~
    return rc;                                                     //~v76gI~
}//pangrepexec                                                     //~v76gR~
//**************************************************************** //~v76gI~
//* set currentdir                                                 //~v76gI~
//* retrn:rc                                                       //~v76gI~
//**************************************************************** //~v76gI~
int panutilsetcdir(PUCLIENTWE Ppcw,int Plineid,char *Ppath)        //~v76gI~
{                                                                  //~v76gI~
	int rc=4;                                                  //~v76gR~
    char  curdir[_MAX_PATH];                                       //~v76gI~
    char  flddata[_MAX_PATH];                                      //~v76gI~
//*****************                                                //~v76gI~
#ifndef AAA                                                        //~va0hR~
    BYUTF8_getfldinput(0,Ppcw,PANLUCCDIR,0,flddata);//concat filename//~va0hR~
#else                                                              //~va0eI~
	getfldinput(Ppcw,PANLUCCDIR,PANLUDATAFLD,flddata);//concat filename//~v76gR~
#endif                                                             //~va0eI~
    if (ufullpath(curdir,Ppath,_MAX_PATH))//fullpath               //~v76gR~
    {                                                              //~v76gI~
#ifdef CCC                                                         //~va0tI~
		setflddata(Ppcw,Plineid,PANLUCDIRFLD,curdir);              //~v76gR~
#else                                                              //~va0tI~
		BYUTF8_pansetflddata(0,Ppcw,Plineid,PANLUCDIRFLD,curdir);  //~va0tI~
#endif                                                             //~va0tI~
        if (strcmp(curdir,flddata))                                //~v76gI~
			UCBITON((Ppcw->UCWpsd+Plineid)->USDflag2,USDF2DRAW);   //~v76gR~
        rc=0;                                                      //~v76gI~
    }                                                              //~v76gI~
    return rc;                                                     //~v76gI~
}//panutilsetcdir                                                  //~v76gI~
//**************************************************************** //~v76gI~
//* utility data manipulate                                        //~v76gI~
//* retrn:rc                                                       //~v76gI~
//**************************************************************** //~v76gI~
int panutildataproc(int Popt,PUCLIENTWE Ppcw,char **Ppdata,char **Ppdbcs,int *Pplen)//~v76gR~
{                                                                  //~v76gI~
	int rc=0;                                                      //~v76gI~
//*****************                                                //~v76gI~
	switch(((PUPANELC)Ppcw->UCWppc)->UPCid)                        //~v76gI~
    {                                                              //~v76gI~
	case PANUCOMP  :		//compare                              //~v76gI~
		rc=pancompdataproc(Popt,Ppcw,Ppdata,Ppdbcs,Pplen);         //~v76gI~
		break;                                                     //~v76gI~
	case PANUGREP  :		//grep                                 //~v76gI~
		rc=pangrepdataproc(Popt,Ppcw,Ppdata,Ppdbcs,Pplen);         //~v76gI~
		break;                                                     //~v76gI~
    }                                                              //~v76gI~
    return rc;                                                     //~v76gI~
}//panutildataproc                                                 //~v76gI~
#ifdef UTF8SUPPH                                                   //~va0tI~
//**************************************************************** //~va0tI~
//* utility data manipulate                                        //~va0tI~
//* retrn:rc                                                       //~va0tI~
//**************************************************************** //~va0tI~
int panutilgetpupl(int Popt,PUCLIENTWE Ppcw,PUPANELL *Pppupl,int *Pbuffszu8)//~va0tI~
{                                                                  //~va0tI~
    PUPANELC ppc;                                                  //~va0tI~
    PUPANELL pupl;                                                 //~va0tI~
    int yy,buffsz;                                                 //~va0tI~
//*****************                                                //~va0tI~
	ppc=(PUPANELC)Ppcw->UCWppc;                                    //~va0tI~
    yy=Ppcw->UCWrcsry;                                             //~va0tI~
    pupl=ppc->UPCline+yy;                                          //~va0tR~
    if (pupl->UPLbuffbyutf8)                                       //~va0tR~
	    buffsz=UPLBUFF2SZ;                                         //~va0tI~
    else                                                           //~va0tI~
    	buffsz=0;                                                  //~va0tI~
	*Pppupl=pupl;                                                  //~va0tI~
	*Pbuffszu8=buffsz;   //for UPLbuffbyutf8 and UPLcodetype       //~va0tR~
    return 0;                                                      //~va0tI~
}//panutilgetpupl                                                  //~va0ER~
#endif                                                             //~va0tI~
//**************************************************************** //~v76gI~
//* compare data manipulate                                        //~v76gI~
//* opt:GETLINE:get pandata line addr,GETDATA:get pandata,SETDATA:set data to pandata,static area,SETFLD:set to FLD//~v76gR~
//* pdbcs:not used for SET                                         //~v76gR~
//* len:field width for GET,datalen for GETDATA                    //~v76gI~
//* retrn:UALLOC_FAILED(INIT only),4:lineno err                    //~v76gR~
//**************************************************************** //~v76gI~
int pancompdataproc(int Popt,PUCLIENTWE Ppcw,char **Ppdata,char **Ppdbcs,int *Pplen)//~v76gR~
{                                                                  //~v76gI~
	int len,yy,width;                                              //~v76gR~
#ifdef UTF8SUPPH                                                   //~va00I~
	int fnmbuffsz;                                                 //~va00R~
#endif                                                             //~va00I~
    char *pc,*pc2,*pdata,*pdbcs;                                   //~v76gR~
    PUPANCOMP ppand;                                               //~v76gR~
    PUPANELC ppc;                                                  //~v76gI~
#ifdef UTF8SUPPH                                                   //~va00M~
    PUPANELL pupl,pupl0;                                           //~va00I~
    char *pu8,*pct;                                                     //~va00R~//~va0tR~
    int lenlc=0;                                                   //~vaf9R~
    int opt;                                                       //~va5wI~
    char *pct2=0;                                                  //~va5wR~
#endif                                                             //~va00I~
//*****************                                                //~v76gI~
	ppc=(PUPANELC)Ppcw->UCWppc;                                    //~v76gI~
	if (Popt & PANUO_INIT)                                         //~v76gI~
    {                                                              //~v76gI~
//  	len=UPANCOMPSZ+(MAXCOLUMN)*2+(_MAX_PATH)*4+Sutilcolstart*6;//~v76jR~//~vb30R~
    	len=(int)UPANCOMPSZ+(MAXCOLUMN)*2+(_MAX_PATH)*4+Sutilcolstart*6;//~vb30I~
#ifdef UTF8SUPPH                                                   //~va00I~
        fnmbuffsz=UPLBUFF2SZ;   //for UPLbuffbyutf8 and UPLcodetype//~va0eR~
    	len+=(fnmbuffsz+fnmbuffsz)*3; //cdir/fnm1/fnm2 utf8/codetype//~va0eR~
//*opt line has no UPLbuffbyutf8,so utfcode is not displayed !!!   //~vaucI~
#endif                                                             //~va00I~
    	pc=umalloc((UINT)len);                                     //~v76gI~
        UALLOCCHK(pc,UALLOC_FAILED);	//return if storage        //~v76gI~
        memset(pc,0,(UINT)len);                                    //~v76gI~
        ppc->UPCpandata=pc;                                        //~v76gI~
        ppand=(PUPANCOMP)pc;                                       //~v76gR~
        pc+=UPANCOMPSZ;                    //opt                   //~v76gR~
        ppand->UPANCopt=pc;                                        //~v76gR~
        pc+=MAXCOLUMN+Sutilcolstart;       //opt dbcs              //~v76jR~
        ppand->UPANCoptdbcs=pc;                                    //~v76gR~
        pc+=MAXCOLUMN+Sutilcolstart;     // fnm1                   //~v76jR~
        ppand->UPANCfnm1=pc;                                       //~v76gR~
        pc+=_MAX_PATH+Sutilcolstart;       //fnm1 dbcs             //~v76jR~
        ppand->UPANCfnm1dbcs=pc;                                   //~v76gR~
        pc+=_MAX_PATH+Sutilcolstart;       //fnm2                  //~v76jR~
        ppand->UPANCfnm2=pc;                                       //~v76gR~
        pc+=_MAX_PATH+Sutilcolstart;      //fnm2 dbcs              //~v76jR~
        ppand->UPANCfnm2dbcs=pc;                                   //~v76gR~
#ifdef UTF8SUPPH                                                   //~va00I~
        pc+=_MAX_PATH+Sutilcolstart;                               //~va00I~
        pupl0=ppc->UPCline;                                        //~va00I~
        pupl=pupl0+PANLUCCDIR;                                     //~va00I~
		pupl->UPLbuffbyutf8=pc;          //cdir by utf8            //~va00R~
        pc+=fnmbuffsz;                                             //~va00R~
		pupl->UPLcodetype=pc;                                      //~va00R~
        pc+=fnmbuffsz;                                             //~va0eI~
        pupl=pupl0+PANLUCFILE1;                                    //~va00I~
		pupl->UPLbuffbyutf8=pc;          //fnm1 by utf8            //~va00R~
        pc+=fnmbuffsz;                                             //~va00R~
		pupl->UPLcodetype=pc;                                      //~va00R~
        pc+=fnmbuffsz;                                             //~va0eI~
        pupl=pupl0+PANLUCFILE2;                                    //~va00I~
		pupl->UPLbuffbyutf8=pc;                                    //~va00R~
        pc+=fnmbuffsz;                                             //~va00R~
		pupl->UPLcodetype=pc;                                      //~va00R~
#endif                                                             //~va00I~
        strcpy(ppand->UPANCopt+Sutilcolstart,Scompopt);            //~v76gR~
#ifdef UTF8SUPPH                                                   //~va00I~
//  	panutilsetfld_f2l(0,pupl0+PANLUCFILE1,Scompfile1,ppand->UPANCfnm1+Sutilcolstart,_MAX_PATH,&lenlc);//utf8-->lc//~va1cR~
//  	panutilsetfld_f2l(0,pupl0+PANLUCFILE2,Scompfile2,ppand->UPANCfnm2+Sutilcolstart,_MAX_PATH,&lenlc);//utf8-->lc//~va1cR~
//  	panutilsetfld_f2l(0,pupl0+PANLUCFILE1,Scompfile1,ppand->UPANCfnm1+Sutilcolstart,UPLBUFF2SZNET,&lenlc);//utf8-->lc//~va5wR~
//  	panutilsetfld_f2l(0,pupl0+PANLUCFILE2,Scompfile2,ppand->UPANCfnm2+Sutilcolstart,UPLBUFF2SZNET,&lenlc);//utf8-->lc//~va5wR~
        opt=0;                                                     //~va5wI~
		if (Sutilstat & SUS_INICODETYPE)//codetype read from ini   //~va5wI~
        {                                                          //~va5wI~
//          memcpy((pupl0+PANLUCFILE1)->UPLcodetype,Scompfile1ct,(UINT)fnmbuffsz);//~va5wI~//~vafwR~
//          memcpy((pupl0+PANLUCFILE1)->UPLcodetype,Scompfile1ct,(UINT)min(fnmbuffsz,sizeof(Scompfile1ct)));//~vafwI~//~vb30R~
            memcpy((pupl0+PANLUCFILE1)->UPLcodetype,Scompfile1ct,min((size_t)fnmbuffsz,sizeof(Scompfile1ct)));//~vb30I~
//          memcpy((pupl0+PANLUCFILE2)->UPLcodetype,Scompfile2ct,(UINT)fnmbuffsz);//~va5wI~//~vafwR~
//          memcpy((pupl0+PANLUCFILE2)->UPLcodetype,Scompfile2ct,(UINT)min(fnmbuffsz,sizeof(Scompfile2ct)));//~vafwI~//~vb30R~
            memcpy((pupl0+PANLUCFILE2)->UPLcodetype,Scompfile2ct,min((size_t)fnmbuffsz,sizeof(Scompfile2ct)));//~vb30I~
            opt=PSFF2LO_USECT;                                     //~va5wI~
        }                                                          //~va5wI~
    	panutilsetfld_f2l(opt,pupl0+PANLUCFILE1,Scompfile1,ppand->UPANCfnm1+Sutilcolstart,UPLBUFF2SZNET,&lenlc);//utf8-->lc//~va5wI~
        setdbcstbl(ppand->UPANCfnm1+Sutilcolstart,ppand->UPANCfnm1dbcs+Sutilcolstart,lenlc);//~vaucI~
        UTRACED("after setdbcstbl fnm1 lc",ppand->UPANCfnm1+Sutilcolstart,lenlc);//~vaucM~
        UTRACED("after setdbcstbl fnm1 dbcs",ppand->UPANCfnm1dbcs+Sutilcolstart,lenlc);//~vaucM~
    	panutilsetfld_f2l(opt,pupl0+PANLUCFILE2,Scompfile2,ppand->UPANCfnm2+Sutilcolstart,UPLBUFF2SZNET,&lenlc);//utf8-->lc//~va5wI~
        setdbcstbl(ppand->UPANCfnm2+Sutilcolstart,ppand->UPANCfnm2dbcs+Sutilcolstart,lenlc);//~vaucI~
        UTRACED("after setdbcstbl fnm2 lc",ppand->UPANCfnm2+Sutilcolstart,lenlc);//~vaucM~
        UTRACED("after setdbcstbl fnm2 dbcs",ppand->UPANCfnm2dbcs+Sutilcolstart,lenlc);//~vaucM~
#else                                                              //~va00I~
        strcpy(ppand->UPANCfnm1+Sutilcolstart,Scompfile1);         //~v76gR~
        strcpy(ppand->UPANCfnm2+Sutilcolstart,Scompfile2);         //~v76gR~
#endif                                                             //~va00I~
        setdbcstbl(Scompopt,ppand->UPANCoptdbcs+Sutilcolstart,(int)strlen(Scompopt));//~v76gR~
#ifdef UTF8SUPPH                                                   //~va00I~
//      setdbcstbl(ppand->UPANCfnm1+Sutilcolstart,ppand->UPANCfnm1dbcs+Sutilcolstart,lenlc);//~vaucR~
//      setdbcstbl(ppand->UPANCfnm2+Sutilcolstart,ppand->UPANCfnm2dbcs+Sutilcolstart,lenlc);//~vaucR~
#else                                                              //~va00I~
        setdbcstbl(Scompfile1,ppand->UPANCfnm1dbcs+Sutilcolstart,(int)strlen(Scompfile1));//~v76gR~
        setdbcstbl(Scompfile2,ppand->UPANCfnm2dbcs+Sutilcolstart,(int)strlen(Scompfile2));//~v76gR~
#endif                                                             //~va00I~
        return 0;                                                  //~v76gI~
    }                                                              //~v76gI~
    ppand=(PUPANCOMP)(ppc->UPCpandata);                            //~v76gR~
    yy=Popt & PANUO_LINENO;                                        //~v76gR~
	if (!yy)                                                       //~v76gR~
	    yy=Ppcw->UCWrcsry;                                         //~v76gI~
#ifdef UTF8SUPPH                                                   //~va00I~
    pupl=ppc->UPCline+yy;                                          //~va00I~
	pu8=pupl->UPLbuffbyutf8;                                       //~va0eR~
	pct=pupl->UPLcodetype;                                         //~va0tI~
//  if (pu8)                                                       //~va00R~
//  	pu8+=Sutilcolstart;                                        //~va00R~
#endif                                                             //~va00I~
    switch (yy)                                                    //~v76gI~
    {                                                              //~v76gI~
    case PANLUCOPT:                                                //~v76gI~
        pdata=ppand->UPANCopt;                                     //~v76gR~
        pdbcs=ppand->UPANCoptdbcs;                                 //~v76gR~
        pc2=Scompopt;                                              //~v76gI~
        width=MAXCOLUMN-1; //leave last null for strlen            //~v76jR~
        break;                                                     //~v76gI~
    case PANLUCFILE1:                                              //~v76gI~
        pdata=ppand->UPANCfnm1;                                    //~v76gR~
        pdbcs=ppand->UPANCfnm1dbcs;                                //~v76gR~
        pc2=Scompfile1;                                            //~v76gI~
        pct2=Scompfile1ct;                                         //~va5wI~
        width=_MAX_PATH-1;                                         //~v76jR~
        break;                                                     //~v76gI~
    case PANLUCFILE2:                                              //~v76gI~
        pdata=ppand->UPANCfnm2;                                    //~v76gR~
        pdbcs=ppand->UPANCfnm2dbcs;                                //~v76gR~
        pc2=Scompfile2;                                            //~v76gI~
        pct2=Scompfile2ct;                                         //~va5wI~
        width=_MAX_PATH-1;                                         //~v76jR~
        break;                                                     //~v76gI~
    default:                                                       //~v76gR~
        return 4;                                                  //~v76gI~
    }                                                              //~v76gI~
	if (Popt & PANUO_GETLINE)                                      //~v76gR~
    {                                                              //~v76gI~
		if (Popt & PANUO_FLDTOP)                                   //~v76gI~
        {                                                          //~v76gI~
	    	pdata+=Sutilcolstart;                                  //~v76gR~
	    	pdbcs+=Sutilcolstart;                                  //~v76gR~
        }                                                          //~v76gI~
    	*Ppdata=pdata;                                             //~v76gI~
        if (Ppdbcs)                                                //~v76gI~
	    	*Ppdbcs=pdbcs;                                         //~v76gR~
        if (Pplen)                                                 //~v76gI~
	        *Pplen=width;                                          //~v76gR~
        return 0;                                                  //~v76gI~
    }                                                              //~v76gI~
	if (Popt & PANUO_GETDATA)                                      //~v76gI~
    {                                                              //~v76gI~
    	pdata+=Sutilcolstart;                                      //~v76gR~
#ifdef UTF8SUPPH                                                   //~va00I~
    	if (pu8) //contains utf8 code                              //~va00R~
        	pdata=pu8;                                             //~va00I~
#endif                                                             //~va00I~
    	width=(int)strlen(pdata);                                       //~v76gM~
        pdata+=umemspnc(pdata,' ',(UINT)width);                          //~v76gR~
    	width=(int)strlen(pdata);                                       //~v76gI~
        width-=(int)umemrspnc(pdata,' ',(UINT)width);                         //~v76gR~
#ifdef UTF8SUPPH                                                   //~va00M~
        if (Ppdata)                                                //~va00I~
//      	UmemcpyZ(*Ppdata,pdata,width);                         //~va00I~//~vb30R~
        	UmemcpyZ(*Ppdata,pdata,(size_t)width);                 //~vb30I~
#else                                                              //~va00I~
        *(pdata+width)=0;                                          //~v76gI~
        if (Ppdata)                                                //~v76gI~
	    	strcpy(*Ppdata,pdata);                                 //~v76gR~
#endif                                                             //~va00M~
        if (Pplen)                                                 //~v76gI~
	        *Pplen=width;                                          //~v76gR~
#ifdef W32UNICODE                                                  //~vavNI~
		SfnmUDlen=0;                                               //~vavNI~
        if (pu8 && pct && memchr(pct,UTFCT_UTF8,width))            //~vavNI~
        	ufilecvU8CT2UD(0,pu8,pct,width,SfnmUD,sizeof(SfnmUD),&SfnmUDlen);//~vavNR~
#endif                                                             //~vavNI~
        return 0;                                                  //~v76gI~
    }                                                              //~v76gI~
    pc=pdata+Sutilcolstart;                                        //~v76gI~
	if (Popt & PANUO_SETDATA) //set to pandata from parm           //~v76gR~
    {                                                              //~v76gI~
#ifdef UTF8SUPPH                                                   //~va00I~
      if (pu8)                                                     //~va00R~
//  	panutilsetfld_f2l(0,pupl,*Ppdata,pc,_MAX_PATH,&lenlc);//utf8-->lc//~va1cR~
    	panutilsetfld_f2l(0,pupl,*Ppdata,pc,UPLBUFF2SZNET,&lenlc);//utf8-->lc//~va1cR~
      else                                                         //~va00I~
#endif                                                             //~va00I~
        strncpy(pc,*Ppdata,(UINT)(width-Sutilcolstart));    //set to pandata//~v76gR~
#ifdef UTF8SUPPH                                                   //~va00I~
        setdbcstbl(pc,pdbcs+Sutilcolstart,lenlc);                  //~va00I~
#else                                                              //~va00I~
        setdbcstbl(pc,pdbcs+Sutilcolstart,(int)strlen(pdata));     //~v76gR~
#endif                                                             //~va00I~
    }                                                              //~v76gI~
	if (Popt & PANUO_SETFLD) //set to fld and save area from pandata//~v76gI~
#ifdef UTF8SUPPH                                                   //~va0eI~
    {                                                              //~va0eI~
	  if (Popt & PANUO_HELPMSG) //set to fld and save area from pandata//~va0eI~
		setflddata(Ppcw,yy,PANLUDATAFLD,*Ppdata);                  //~va0eI~
      else                                                         //~va0eI~
#endif                                                             //~va0eI~
		setflddata(Ppcw,yy,PANLUDATAFLD,pc);                       //~v76gR~
#ifdef UTF8SUPPH                                                   //~va0eI~
    }                                                              //~va0eI~
#endif                                                             //~va0eI~
	if (Popt & PANUO_SETSAVE) //set to fld and save area from pandata//~v76gI~
    {                                                              //~va00I~
#ifdef UTF8SUPPH                                                   //~va00I~
      	if (pct2)                                                  //~va5wI~
//      	memset(pct2,0,width);		//static save area from pandata//~va5wI~//~vb30R~
        	memset(pct2,0,(size_t)width);		//static save area from pandata//~vb30I~
	  if (Popt & PANUO_HELPMSG) //set to fld and save area from pandata//~va0eI~
      	*pc2=0;                                                    //~va0eI~
      else                                                         //~va0eI~
      if (pu8) //contains utf8 code                                //~va00R~
      {                                                            //~va5wI~
        strcpy(pc2,pu8);		//static save area from pandata    //~va00I~
        if (pct && pct2)                                           //~va5wI~
//      	memcpy(pct2,pct,width);		//static save area from pandata//~va5wI~//~vb30R~
        	memcpy(pct2,pct,(size_t)width);		//static save area from pandata//~vb30I~
      }                                                            //~va5wI~
      else                                                         //~va00I~
#endif                                                             //~va00I~
        strcpy(pc2,pc); 		//static save area from pandata    //~v76gI~
    }                                                              //~va00I~
    return 0;                                                      //~v76gI~
}//pancompdataproc                                                 //~v76gI~
//**************************************************************** //~v76gI~
//* grep    data manipulate                                        //~v76gI~
//* opt:GETLINE:get pandata line addr,GETDATA:get pandata,SETDATA:set data to pandata,static area,SETFLD:set to FLD//~v76gI~
//* pdbcs:not used for SET                                         //~v76gI~
//* len:field width for GET,datalen for GETDATA                    //~v76gI~
//* retrn:UALLOC_FAILED(INIT only),4:lineno err                    //~v76gI~
//**************************************************************** //~v76gI~
int pangrepdataproc(int Popt,PUCLIENTWE Ppcw,char **Ppdata,char **Ppdbcs,int *Pplen)//~v76gI~
{                                                                  //~v76gI~
	int ii,len,yy,width,fileidx;                                   //~v76gR~
    char *pc,*pc2,*pdata,*pdbcs;                                   //~v76gI~
    PUPANGREP ppand;                                               //~v76gI~
    PUPANELC ppc;                                                  //~v76gI~
#ifdef UTF8SUPPH                                                   //~va00M~
    PUPANELL pupl,pupl0;                                           //~va00I~
	int fnmbuffsz,lenlc=0;                                         //~vaf9R~
    char *pu8,*pct;                                                     //~va00R~//~va0tR~
    int opt;                                                       //~va5wI~
    char *pct2=0;                                                  //~va5wI~
#endif                                                             //~va00I~
//*****************                                                //~v76gI~
	ppc=(PUPANELC)Ppcw->UCWppc;                                    //~v76gI~
	if (Popt & PANUO_INIT)                                         //~v76gI~
    {                                                              //~v76gI~
//    	len=UPANGREPSZ+MAXCOLUMN*2+_MAX_PATH*(2+PANLUGFILENO*2)+Sutilcolstart*(2+2+PANLUGFILENO*2);//~v76gR~
//    	len=UPANGREPSZ+(MAXCOLUMN)*2+(_MAX_PATH)*(PANLUGFILENO*2)+Sutilcolstart*(2+PANLUGFILENO*2);//~v76jR~//~vb30R~
      	len=(int)UPANGREPSZ+(MAXCOLUMN)*2+(_MAX_PATH)*(PANLUGFILENO*2)+Sutilcolstart*(2+PANLUGFILENO*2);//~vb30I~
#ifdef UTF8SUPPH                                                   //~va00I~
        fnmbuffsz=UPLBUFF2SZ;   //for UPLbuffbyutf8 and UPLcodetype//~va0eI~
    	len+=(fnmbuffsz+fnmbuffsz)*(1+PANLUGFILENO); //cpath and fnm//~va0eR~
    	len+=(fnmbuffsz+fnmbuffsz); //utf8 and codetype for option line//~va0EI~
#endif                                                             //~va00I~
    	pc=umalloc((UINT)len);                                     //~v76gI~
        UALLOCCHK(pc,UALLOC_FAILED);	//return if storage        //~v76gI~
        memset(pc,0,(UINT)len);                                    //~v76gI~
        ppc->UPCpandata=pc;                                        //~v76gI~
        ppand=(PUPANGREP)pc;                                       //~v76gI~
        pc+=UPANGREPSZ;         //opt                              //~v76gR~
                                                                   //~v76gI~
        ppand->UPANGopt=pc;                                        //~v76gI~
        pc+=MAXCOLUMN+Sutilcolstart;     //optdbcs                 //~v76jR~
        ppand->UPANGoptdbcs=pc;                                    //~v76gI~
#ifdef UTF8SUPPH                                                   //~va0EI~
#else                                                              //~va0EI~
        strcpy(ppand->UPANGopt+Sutilcolstart,Sgrepopt);            //~v76gI~
        setdbcstbl(Sgrepopt,ppand->UPANGoptdbcs+Sutilcolstart,(int)strlen(Sgrepopt));//~v76gI~
#endif                                                             //~va0EI~
        pc+=MAXCOLUMN+Sutilcolstart;      //optfnm                 //~v76jR~
#ifdef UTF8SUPPH                                                   //~va00I~
//      pc+=_MAX_PATH+Sutilcolstart;                               //~va00I~//~va0ER~
        pupl0=ppc->UPCline;                                        //~va00I~
//option line                                                      //~va0EM~
        pupl=pupl0+PANLUGOPT;                                      //~va0EM~
		pupl->UPLbuffbyutf8=pc;                                    //~va0EM~
        pc+=fnmbuffsz;                                             //~va0EM~
		pupl->UPLcodetype=pc;                                      //~va0EM~
        pc+=fnmbuffsz;                                             //~va0EM~
//cdir line                                                        //~va0EI~
        pupl=pupl0+PANLUGCDIR;                                     //~va00I~
		pupl->UPLbuffbyutf8=pc;        //current dir               //~va00R~
        pc+=fnmbuffsz;                                             //~va00R~
		pupl->UPLcodetype=pc;                                      //~va00R~
        pc+=fnmbuffsz;                                             //~va0eI~
        pupl=pupl0+PANLUGFILE1;                                    //~va00I~
#endif                                                             //~va00I~
        for (ii=0;ii<PANLUGFILENO;ii++)                            //~v76gI~
        {                                                          //~v76gI~
	        ppand->UPANGfnm[ii]=pc;                                //~v76gI~
	        pc+=_MAX_PATH+Sutilcolstart;  //fnm dbcs               //~v76jR~
        	ppand->UPANGfnmdbcs[ii]=pc;                            //~v76gI~
	        pc+=_MAX_PATH+Sutilcolstart;                           //~v76jR~
#ifdef UTF8SUPPH                                                   //~va00I~
			pupl->UPLbuffbyutf8=pc;                                //~va00R~
        	pc+=fnmbuffsz;                                         //~va00R~
			pupl->UPLcodetype=pc;                                  //~va00R~
	        pc+=fnmbuffsz;                                         //~va0eI~
#endif                                                             //~va00I~
#ifdef UTF8SUPPH                                                   //~va00I~
//  		panutilsetfld_f2l(0,pupl,Sgrepfile[ii],ppand->UPANGfnm[ii]+Sutilcolstart,_MAX_PATH,&lenlc);//utf8-->lc//~va1cR~
//  		panutilsetfld_f2l(0,pupl,Sgrepfile[ii],ppand->UPANGfnm[ii]+Sutilcolstart,UPLBUFF2SZNET,&lenlc);//utf8-->lc//~va1cR~//~va5wR~
        	opt=0;                                                 //~va5wI~
			if (Sutilstat & SUS_INICODETYPE)//codetype read from ini//~va5wI~
        	{                                                      //~va5wI~
//          	memcpy(pupl->UPLcodetype,Sgrepfilect[ii],(UINT)fnmbuffsz);//~va5wI~//~vafwR~
//          	memcpy(pupl->UPLcodetype,Sgrepfilect[ii],(UINT)min(fnmbuffsz,sizeof(Sgrepfilect[0])));//~vafwI~//~vb30R~
            	memcpy(pupl->UPLcodetype,Sgrepfilect[ii],min((size_t)fnmbuffsz,sizeof(Sgrepfilect[0])));//~vb30I~
            	opt=PSFF2LO_USECT;                                 //~va5wI~
        	}                                                      //~va5wI~
    		panutilsetfld_f2l(opt,pupl,Sgrepfile[ii],ppand->UPANGfnm[ii]+Sutilcolstart,UPLBUFF2SZNET,&lenlc);//utf8-->lc//~va5wI~
	        setdbcstbl(ppand->UPANGfnm[ii]+Sutilcolstart,ppand->UPANGfnmdbcs[ii]+Sutilcolstart,lenlc);//~va00R~
            pupl++;                                                //~va00M~
#else                                                              //~va00I~
        	strcpy(ppand->UPANGfnm[ii]+Sutilcolstart,Sgrepfile[ii]);//~v76gI~
	        setdbcstbl(Sgrepfile[ii],ppand->UPANGfnmdbcs[ii]+Sutilcolstart,(int)strlen(Sgrepfile[ii]));//~v76gI~
#endif                                                             //~va00I~
        }                                                          //~v76gI~
#ifdef UTF8SUPPH                                                   //~va0EI~
      if (Sutilstat & SUS_INICODETYPE)//codetype read from ini     //~va5wI~
      {                                                            //~va5wI~
        pupl=pupl0+PANLUGOPT;                                      //~va5wI~
//      memcpy(pupl->UPLcodetype,Sgrepoptct,min(fnmbuffsz,sizeof(Sgrepopt)));//~va5wI~//~vb30R~
        memcpy(pupl->UPLcodetype,Sgrepoptct,min((size_t)fnmbuffsz,sizeof(Sgrepopt)));//~vb30I~
        opt=PSFF2LO_USECT;                                         //~va5wI~
    	panutilsetfld_f2l(opt,pupl,Sgrepopt,ppand->UPANGopt+Sutilcolstart,MAXCOLUMN,&lenlc);//utf8-->lc//~va5wR~
	    setdbcstbl(ppand->UPANGopt+Sutilcolstart,ppand->UPANGoptdbcs+Sutilcolstart,lenlc);//~va5wI~
      }                                                            //~va5wI~
      else                                                         //~va5wI~
//  	panutilfldupdate_utf8(PUFU8O_PARMROW,Ppcw,PANLUGOPT,PANLUDATAFLD,0/*offs*/,Sgrepopt,strlen(Sgrepopt),ppand->UPANGoptdbcs);//~va0ER~//~vb30R~
    	panutilfldupdate_utf8(PUFU8O_PARMROW,Ppcw,PANLUGOPT,PANLUDATAFLD,0/*offs*/,Sgrepopt,(int)strlen(Sgrepopt),ppand->UPANGoptdbcs);//~vb30I~
#endif                                                             //~va0EI~
        return 0;                                                  //~v76gI~
    }                                                              //~v76gI~
    ppand=(PUPANGREP)(ppc->UPCpandata);                            //~v76gI~
    yy=Popt & PANUO_LINENO;                                        //~v76gI~
	if (!yy)                                                       //~v76gI~
	    yy=Ppcw->UCWrcsry;                                         //~v76gI~
#ifdef UTF8SUPPH                                                   //~va00I~
    pupl=ppc->UPCline+yy;                                          //~va00I~
	pu8=pupl->UPLbuffbyutf8;                                       //~va00I~
	pct=pupl->UPLcodetype;                                         //~va0tI~
//  if (pu8)                                                       //~va00R~
//		pu8+=Sutilcolstart;                                        //~va00R~
#endif                                                             //~va00I~
    if (yy==PANLUGOPT)                                             //~v76gI~
    {                                                              //~v76gI~
        pdata=ppand->UPANGopt;                                     //~v76gR~
        pdbcs=ppand->UPANGoptdbcs;                                 //~v76gR~
        pc2=Sgrepopt;                                              //~v76gR~
        pct2=Sgrepoptct;                                           //~va5wI~
        width=MAXCOLUMN-1;                                         //~v76jR~
    }                                                              //~v76gI~
    else                                                           //~v76gI~
    if (yy>=PANLUGFILE1 && yy<=PANLUGFILELAST)                     //~v76gR~
    {                                                              //~v76gI~
        fileidx=yy-PANLUGFILE1;                                    //~v76gI~
        pdata=ppand->UPANGfnm[fileidx];                            //~v76gR~
        pdbcs=ppand->UPANGfnmdbcs[fileidx];                        //~v76gR~
        pc2=Sgrepfile[fileidx];                                    //~v76gI~
        pct2=Sgrepfilect[fileidx];                                 //~va5wI~
        width=_MAX_PATH-1;                                         //~v76jR~
    }                                                              //~v76gI~
    else                                                           //~v76gI~
        return 4;                                                  //~v76gI~
	if (Popt & PANUO_GETLINE)                                      //~v76gI~
    {                                                              //~v76gI~
		if (Popt & PANUO_FLDTOP)                                   //~v76gI~
        {                                                          //~v76gI~
	    	pdata+=Sutilcolstart;                                  //~v76gI~
	    	pdbcs+=Sutilcolstart;                                  //~v76gI~
        }                                                          //~v76gI~
    	*Ppdata=pdata;                                             //~v76gI~
        if (Ppdbcs)                                                //~v76gI~
	    	*Ppdbcs=pdbcs;                                         //~v76gI~
        if (Pplen)                                                 //~v76gI~
	        *Pplen=width;                                          //~v76jR~
        return 0;                                                  //~v76gI~
    }                                                              //~v76gI~
	if (Popt & PANUO_GETDATA)                                      //~v76gI~
    {                                                              //~v76gI~
    	pdata+=Sutilcolstart;                                      //~v76gI~
#ifdef UTF8SUPPH                                                   //~va00I~
    	if (pu8) //contains utf8 code                              //~va00R~
        	pdata=pu8;                                             //~va00I~
#endif                                                             //~va00I~
    	width=(int)strlen(pdata);                                       //~v76gI~
        pdata+=umemspnc(pdata,' ',(UINT)width);                          //~v76gI~
    	width=(int)strlen(pdata);                                       //~v76gI~
        width-=(int)umemrspnc(pdata,' ',(UINT)width);                         //~v76gI~
#ifdef UTF8SUPPH                                                   //~va00I~
        if (Ppdata)                                                //~va00I~
//      	UmemcpyZ(*Ppdata,pdata,width);                         //~va00I~//~vb30R~
        	UmemcpyZ(*Ppdata,pdata,(size_t)width);                 //~vb30I~
#else                                                              //~va00I~
        *(pdata+width)=0;                                          //~v76gI~
        if (Ppdata)                                                //~v76gI~
	    	strcpy(*Ppdata,pdata);                                 //~v76gI~
#endif                                                             //~va00I~
        if (Pplen)                                                 //~v76gI~
	        *Pplen=width;                                          //~v76gI~
#ifdef W32UNICODE         //grep dose not understand UD fmt        //~vavNI~
		SfnmUDlen=0;                                               //~vavNI~
        if (pu8 && pct && memchr(pct,UTFCT_UTF8,width))            //~vavNI~
        	ufilecvU8CT2UD(0,pu8,pct,width,SfnmUD,sizeof(SfnmUD),&SfnmUDlen);//~vavNI~
#endif                                                             //~vavNI~
        return 0;                                                  //~v76gI~
    }                                                              //~v76gI~
    pc=pdata+Sutilcolstart;                                        //~v76gI~
	if (Popt & PANUO_SETDATA) //set to fld and save area           //~v76gI~
    {                                                              //~v76gI~
#ifdef UTF8SUPPH                                                   //~va00I~
	  if (pu8)		//fnm1/2                                       //~va00I~
//  	panutilsetfld_f2l(0,pupl,*Ppdata,pc,_MAX_PATH,&lenlc);//utf8-->lc//~va1cR~
    	panutilsetfld_f2l(0,pupl,*Ppdata,pc,UPLBUFF2SZNET,&lenlc);//utf8-->lc//~va1cR~
      else                                                         //~va00I~
#endif                                                             //~va00I~
        strncpy(pc,*Ppdata,(UINT)(width-Sutilcolstart));           //~v76gR~
#ifdef UTF8SUPPH                                                   //~va00I~
        setdbcstbl(pc,pdbcs+Sutilcolstart,lenlc);                  //~va00I~
#else                                                              //~va00I~
        strcpy(pc2,pdata);                                         //~v76gM~
        setdbcstbl(pc,pdbcs+Sutilcolstart,(int)strlen(pdata));     //~v76gR~
#endif                                                             //~va00I~
    }                                                              //~v76gM~
	if (Popt & PANUO_SETFLD) //set to fld and save area            //~v76gI~
#ifdef UTF8SUPPH                                                   //~va0eI~
    {                                                              //~va0eI~
	  if (Popt & PANUO_HELPMSG) //set to fld and save area from pandata//~va0eI~
		setflddata(Ppcw,yy,PANLUDATAFLD,*Ppdata);                  //~va0eI~
      else                                                         //~va0eI~
#endif                                                             //~va0eI~
		setflddata(Ppcw,yy,PANLUDATAFLD,pc);                       //~v76gR~
#ifdef UTF8SUPPH                                                   //~va0eI~
    }                                                              //~va0eI~
#endif                                                             //~va0eI~
	if (Popt & PANUO_SETSAVE) //set to fld and save area from pandata//~v76gI~
    {                                                              //~va00I~
#ifdef UTF8SUPPH                                                   //~va00I~
      if (pct2)                                                    //~va5wI~
//    	memset(pct2,0,width);		//static save area from pandata//~va5wR~//~vb30R~
      	memset(pct2,0,(size_t)width);		//static save area from pandata//~vb30I~
	  if (Popt & PANUO_HELPMSG) //set to fld and save area from pandata//~va0eI~
      	*pc2=0;                                                    //~va0eI~
      else                                                         //~va0eI~
	  if (pu8) //contains utf8 code                                //~va00R~
      {                                                            //~va5wI~
        strcpy(pc2,pu8);		//static save area from pandata    //~va00I~
        if (pct && pct2)                                           //~va5wI~
//      	memcpy(pct2,pct,width);		//static save area from pandata//~va5wI~//~vb30R~
        	memcpy(pct2,pct,(size_t)width);		//static save area from pandata//~vb30I~
      }                                                            //~va5wI~
      else                                                         //~va00I~
#endif                                                             //~va00I~
        strcpy(pc2,pc); 		//static save area from pandata    //~v76gI~
    }                                                              //~va00I~
    return 0;                                                      //~v76gI~
}//pangrepdataproc                                                 //~v76gI~
//**************************************************************** //~v76gI~
//* utility find(open dirlist)                                     //~v76gI~
//* retrn:rc                                                       //~v76gI~
//**************************************************************** //~v76gI~
int panutilfind(int Popt,PUCLIENTWE Ppcw,int Ppanelid)             //~v76gR~
{                                                                  //~v76gI~
    PUPANCOMP ppand;                                               //~v76gR~
    PUPANELC ppc;                                                  //~v76gI~
	int rc=0,yy;                                                   //~v76gR~
    char *pdata,flddata[_MAX_PATH];                                //~v76gI~
//*****************                                                //~v76gI~
	ppc=(PUPANELC)Ppcw->UCWppc;                                    //~v76gI~
    ppand=(PUPANCOMP)(ppc->UPCpandata);                            //~v76gR~
	yy=ppand->UPANCcsry;                                           //~v76gR~
    switch(Ppanelid)                                               //~v76gR~
    {                                                              //~v76gI~
    case PANUCOMP:                                                 //~v76gI~
	    if (yy!=PANLUCFILE1 && yy!=PANLUCFILE2)                    //~v76gI~
			return panutilerrline();                               //~v76gI~
        pdata=flddata;                                             //~v76gI~
		pancompdataproc(PANUO_GETDATA|yy,Ppcw,&pdata,0,0);	//get data(trim space)//~v76gI~
        rc=panutilview(Ppcw,Ppanelid,pdata);                       //~v76gR~
        break;                                                     //~v76gI~
    case PANUGREP:                                                 //~v76gI~
	    if (yy<PANLUGFILE1 || yy>PANLUGFILELAST)                   //~v76gI~
			return panutilerrline();                               //~v76gI~
        pdata=flddata;                                             //~v76gI~
		pangrepdataproc(PANUO_GETDATA|yy,Ppcw,&pdata,0,0);	//get data(trim space)//~v76gI~
        rc=panutilview(Ppcw,Ppanelid,pdata);                       //~v76gI~
        break;                                                     //~v76gI~
    default:                                                       //~v76gI~
    	return 4;                                                  //~v76gI~
    }                                                              //~v76gI~
    return rc;                                                     //~v76gI~
}//panutilfind                                                     //~v76gI~
//**************************************************************** //~v76gI~
// dlcmdviewscrswap1                                               //~v76gI~
// setup view screen                                               //~v76gI~
//**************************************************************** //~v76gI~
int panutilview(PUCLIENTWE Ppcw,int Ppanelid,char *Pfilename)      //~v76gI~
{                                                                  //~v76gI~
	PUCLIENTWE pcw2;                                               //~v76gI~
	FILEFINDBUF3 ffb3;                                             //~v76gI~
    int rc,splitrc;                                                //~v76gI~
    char fpath[_MAX_PATH];                                         //~v76gI~
    char *pc;                                                      //~vagAI~
//*******************                                              //~v76gI~
	if (*Pfilename)                                                //~v76gI~
    {                                                              //~v76gI~
    	rc=filefind(Pfilename,fpath,&ffb3,FFNODIRMSG);             //~v76gR~
        if (!rc)                                                   //~v76gR~
        	return ufilenotdir(fpath,4);                           //~v76gM~
        if (!(rc==16||rc==20))	//dir,wildcard                     //~v76gR~
        	return 4;                                              //~v76gR~
    }                                                              //~v76gI~
    else                                                           //~v76gI~
    {                                                              //~vagAI~
      pc=                                                          //~vagAI~
	    ufullpath(fpath,"." DIR_SEPS,_MAX_PATH);//fullpath         //~v76gR~
        if (!pc)                                                   //~vagAI~
        	return 4;                                              //~vagAI~
    }                                                              //~vagAI~
	splitrc=panutilviewswap(Ppcw,&pcw2);                           //~v76gR~
    if (splitrc>1)                                                 //~v76gI~
    	return splitrc;                                            //~v76gR~
    pcw2->UCWparm=fpath;                                           //~v76gI~
    rc=func_browse_file2(pcw2,0);	//no other edit option         //~v76gI~
    pcw2->UCWparm=0;        //worked                               //~v76gI~
    if (rc)                                                        //~v76gI~
        return rc;                                                 //~v76gI~
    if (splitrc) 		//newly split                              //~v76gR~
    {                                                              //~v76gI~
        scrpopup(pcw2,0);   //pop menu to top                      //~v76gI~
        panpopup(pcw2);     //free top                             //~v76gI~
    }                                                              //~v76gI~
    return 0;                                                      //~v76gI~
}//panutilview                                                     //~v76gI~
//**************************************************************** //~v76gI~
// dlcmdviewscrswap1                                               //~v76gI~
// setup view screen                                               //~v76gI~
//*rc   :1:split generated,0:already split,4:err                   //~v76gI~
//**************************************************************** //~v76gI~
int panutilviewswap(PUCLIENTWE Ppcw,PUCLIENTWE *Pppcw2)            //~v76gI~
{                                                                  //~v76gI~
    int rc=0;                                                      //~v76gI~
//*******************                                              //~v76gI~
    if (!scrgetcw(2))	//not splitted                             //~v76gI~
    {                                                              //~v76gI~
		Gcsrposy=Gscrheight/2;	//half of screen                   //~v76gI~
        if (func_splith(Ppcw))	//active change                    //~v76gI~
        	return 4;                                              //~v76gI~
        *Pppcw2=scrgetcw(2);	//split half                       //~v76gI~
        rc=1;                                                      //~v76gI~
    }                                                              //~v76gI~
    else                                                           //~v76gI~
    {                                                              //~v76gI~
        *Pppcw2=scrgetcw(-1);	//other half                       //~v76gI~
        Gscrcurclient=!Gscrcurclient;	//change active            //~v76gI~
        rc=0;                                                      //~v76gI~
    }                                                              //~v76gI~
	return rc;                                                     //~v76gI~
}//panutilviewswap                                                 //~v76gI~
//**************************************************************** //~v76gI~
//* utility receive filename                                       //~v76gI~
//* retrn:rc                                                       //~v76gI~
//**************************************************************** //~v76gI~
int panutilreceive(int Popt,PUCLIENTWE Ppcw,PUCLIENTWE Ppcw2,int Ppanelid,char *Pfnm)//~v76gR~
{                                                                  //~v76gI~
    PUPANCOMP ppand;                                               //~v76gR~
    PUPANELC ppc;                                                  //~v76gI~
	int yy,ii,yyo,fullsw=0;                                        //~v76gR~
    char *pdata;                                                   //~v76gI~
//*****************                                                //~v76gI~
	ppc=(PUPANELC)Ppcw2->UCWppc;                                   //~v76gI~
    ppand=(PUPANCOMP)(ppc->UPCpandata);                            //~v76gR~
    yyo=ppand->UPANCcsry;                                          //~v76gI~
    if (Popt & PANSENDO_INS)    //insert;serach null line          //~v76gI~
    {                                                              //~v76gI~
        switch(Ppanelid)                                           //~v76gI~
        {                                                          //~v76gI~
        case PANUCOMP:                                             //~v76gI~
        	yy=PANLUCFILE1;                                        //~v76gI~
            for (ii=0;ii<2;ii++)                                   //~v76gI~
            {                                                      //~v76gI~
            	pancompdataproc(PANUO_GETLINE|PANUO_FLDTOP|yy,Ppcw2,&pdata,0,0);//~v76gR~
            	pdata+=strspn(pdata," ");                          //~v76gR~
            	if (!*pdata)                                       //~v76gI~
                	break;                                         //~v76gI~
	        	yy=PANLUCFILE2;                                    //~v76gI~
            }                                                      //~v76gI~
            if (ii==2)                                             //~v76gI~
            {                                                      //~v76gI~
				panutilerrlinefull();                              //~v76gI~
                fullsw=1;                                          //~v76gI~
                if (yyo==PANLUCFILE1)                              //~v76gI~
                	yy=PANLUCFILE2;                                //~v76gI~
                else                                               //~v76gI~
                	yy=PANLUCFILE1;                                //~v76gI~
            }                                                      //~v76gI~
            break;                                                 //~v76gI~
        case PANUGREP:                                             //~v76gI~
            for (yy=PANLUGFILE1;yy<=PANLUGFILELAST;yy++)           //~v76gR~
            {                                                      //~v76gI~
            	pangrepdataproc(PANUO_GETLINE|PANUO_FLDTOP|yy,Ppcw2,&pdata,0,0);//~v76gR~
            	pdata+=strspn(pdata," ");                          //~v76gR~
            	if (!*pdata)                                       //~v76gI~
                	break;                                         //~v76gI~
            }                                                      //~v76gI~
            if (yy>PANLUGFILELAST)                                 //~v76gR~
            {                                                      //~v76gI~
				panutilerrlinefull();                              //~v76gI~
                fullsw=1;                                          //~v76gI~
                if (yyo>=PANLUGFILE1 && yyo<PANLUGFILELAST)        //~v76gR~
                	yy=yyo+1;                                      //~v76gI~
                else                                               //~v76gI~
                	yy=PANLUGFILE1;                                //~v76gR~
            }                                                      //~v76gI~
            break;                                                 //~v76gI~
        default:                                                   //~v76gI~
            return 4;                                              //~v76gI~
        }                                                          //~v76gI~
        if (yyo)                                                   //~v76gI~
	        panflderr(Ppcw2,yyo,PANLUHDRFLD,PANFERESET|PANFEFORCE);    //set err reverse on cur csr//~v76gR~
    	ppand->UPANCcsry=yy;    //prepare for rep/del              //~v76gR~
        panflderr(Ppcw2,yy,PANLUHDRFLD,PANFESET|PANFEKEEPCSR|PANFEFORCE);    //set err reverse on cur csr//~v76gR~
        if (fullsw)                                                //~v76gI~
            return 4;                                              //~v76gI~
    	pdata=Pfnm;                                                //~v76gI~
		panutildataproc(PANUO_SETDATA|PANUO_SETFLD|PANUO_SETSAVE|yy,Ppcw2,&pdata,0,0);//~v76gR~
    }//ins                                                         //~v76gI~
    else                                                           //~v76gI~
    if (Popt & (PANSENDO_REP|PANSENDO_DEL))    //insert;serach null line//~v76gR~
    {                                                              //~v76gI~
        if (Popt & PANSENDO_CMD)                                   //~v76gI~
        {                                                          //~v76gI~
            yy=Popt & PANSENDO_LINENO;                             //~v76gR~
            if (Popt & PANSENDO_DND)	//dnd drop or paste filename//~v76jI~
            {                                                      //~v76jI~
            	if (yy)					//dnd drop                 //~v76jI~
		        	yy-=Ppcw->UCWorgy;  //parm yy is grobal(it may be 2nd screen of horizontal split)//~v76jR~
                else                                               //~v76jI~
			    	yy=ppand->UPANCcsry;//paste                    //~v76jI~
            }                                                      //~v76jI~
            switch(Ppanelid)                                       //~v76gI~
            {                                                      //~v76gI~
            case PANUCOMP:                                         //~v76gI~
                if (yy==PANLUCFILE1                                //~v76gI~
                ||  yy==PANLUCFILE2)                               //~v76gR~
                    break;                                         //~v76gI~
                return errcsrpos();                                //~v76gR~
            case PANUGREP:                                         //~v76gI~
                if (yy>=PANLUGFILE1 && yy<=PANLUGFILELAST)         //~v76gI~
                	break;                                         //~v76gI~
                return errcsrpos();                                //~v76gI~
            default:                                               //~v76gI~
                return 4;                                          //~v76gI~
            }                                                      //~v76gI~
                                                                   //~v76gI~
        }                                                          //~v76gI~
        else                                                       //~v76gI~
	    	yy=ppand->UPANCcsry;                                   //~v76gR~
    	if (!yy)                                                   //~v76gI~
			return panutilerrline();                               //~v76gI~
	    if (Popt & PANSENDO_DEL)    //insert;serach null line      //~v76gI~
        	pdata="";	//clear                                    //~v76gI~
        else                                                       //~v76gI~
	    	pdata=Pfnm;                                            //~v76gI~
		panutildataproc(PANUO_SETDATA|PANUO_SETFLD|PANUO_SETSAVE|yy,Ppcw2,&pdata,0,0);//~v76gR~
    }                                                              //~v76gI~
    else		//up/down                                          //~v76gI~
    {                                                              //~v76gI~
    	yy=ppand->UPANCcsry;                                       //~v76gR~
        switch(Ppanelid)                                           //~v76gI~
        {                                                          //~v76gI~
        case PANUCOMP:                                             //~v76gI~
            if (yy==PANLUCFILE1)                                   //~v76gR~
                yy=PANLUCFILE2;                                    //~v76gI~
            else                                                   //~v76gI~
                yy=PANLUCFILE1;                                    //~v76gR~
            break;                                                 //~v76gI~
        case PANUGREP:                                             //~v76gI~
	    	if (Popt & PANSENDO_DOWN)	//csr down                 //~v76gI~
            {                                                      //~v76gI~
                if (yy>=PANLUGFILE1 && yy<PANLUGFILELAST)          //~v76gR~
                	yy++;                                          //~v76gI~
                else                                               //~v76gI~
                  	yy=PANLUGFILE1;                                //~v76gI~
            }                                                      //~v76gI~
	    	else 	//csr up                                       //~v76gI~
            {                                                      //~v76gI~
                if (yy>PANLUGFILE1 && yy<=PANLUGFILELAST)          //~v76gR~
                	yy--;                                          //~v76gI~
                else                                               //~v76gI~
                	yy=PANLUGFILELAST;                             //~v76gI~
            }                                                      //~v76gI~
            break;                                                 //~v76gI~
        default:                                                   //~v76gI~
            return 4;                                              //~v76gI~
        }                                                          //~v76gI~
        if (yyo)                                                   //~v76gI~
	        panflderr(Ppcw2,yyo,PANLUHDRFLD,PANFERESET|PANFEFORCE);    //set err reverse on cur csr//~v76gI~
        panflderr(Ppcw2,yy,PANLUHDRFLD,PANFESET|PANFEKEEPCSR|PANFEFORCE);    //set err reverse on cur csr//~v76gI~
    	ppand->UPANCcsry=yy;    //prepare for rep/del              //~v76gI~
    }                                                              //~v76gI~
    return 0;                                                      //~v76gR~
}//panutilreceive                                                  //~v76gI~
//**************************************************************** //~v76gI~
//* utility receive filename                                       //~v76gI~
//* retrn:rc                                                       //~v76gI~
//**************************************************************** //~v76gI~
int panutilreset(int Popt,PUCLIENTWE Ppcw,int Ppanelid)            //~v76gR~
{                                                                  //~v76gI~
	int yy,ii;                                                     //~v76gR~
    char *pdata;                                                   //~v76gI~
//*****************                                                //~v76gI~
    pdata="";   //clear                                            //~v76gI~
    switch(Ppanelid)                                               //~v76gI~
    {                                                              //~v76gI~
    case PANUCOMP:                                                 //~v76gI~
        yy=PANLUCOPT;                                              //~v76gI~
		panutildataproc(PANUO_SETDATA|PANUO_SETFLD|PANUO_SETSAVE|yy,Ppcw,&pdata,0,0);//~v76gR~
        yy=PANLUCFILE1;                                            //~v76gI~
        for (ii=0;ii<2;ii++)                                       //~v76gI~
        {                                                          //~v76gI~
			panutildataproc(PANUO_SETDATA|PANUO_SETFLD|PANUO_SETSAVE|yy,Ppcw,&pdata,0,0);//~v76gR~
            yy=PANLUCFILE2;                                        //~v76gI~
        }                                                          //~v76gI~
        break;                                                     //~v76gI~
    case PANUGREP:                                                 //~v76gI~
        yy=PANLUGOPT;                                              //~v76gI~
		panutildataproc(PANUO_SETDATA|PANUO_SETFLD|PANUO_SETSAVE|yy,Ppcw,&pdata,0,0);//~v76gR~
        for (yy=PANLUGFILE1;yy<=PANLUGFILELAST;yy++)               //~v76gI~
			panutildataproc(PANUO_SETDATA|PANUO_SETFLD|PANUO_SETSAVE|yy,Ppcw,&pdata,0,0);//~v76gR~
        break;                                                     //~v76gI~
    default:                                                       //~v76gI~
        return 4;                                                  //~v76gI~
    }                                                              //~v76gI~
    return 0;                                                      //~v76gI~
}//panutilreset                                                    //~v76gI~
//**************************************************************** //~v76gI~
int panutilerrline(void)                                           //~v76gI~
{                                                                  //~v76gI~
	uerrmsg("Receive line is not yet selected",                    //~v76gR~
    		"宛先行が選択されていません");                         //~v76gR~
    return 4;                                                      //~v76gI~
}//panutilerrline                                                  //~v76gI~
//**************************************************************** //~v76gM~
int panutilerrlinefull(void)                                       //~v76gI~
{                                                                  //~v76gI~
	uerrmsg("All receive line is filled",                          //~v76gI~
    		"宛先に挿入すべき空白行がありません");                 //~v76gR~
    return 4;                                                      //~v76gI~
}//panutilerrline                                                  //~v76gI~
#ifdef UTF8SUPPH                                                   //~va00I~
#ifdef AAA                                                         //~va0tI~
//*******************************************************          //~va00I~
//*save kbdinput under UTF8 env by utf8code                        //~va00I~
//*return locale code len                                          //~va00I~
//*******************************************************          //~va00I~
int pancompsetfld_l2f(int Popt,PUCLIENTWE Ppcw,int Prow,char *Pcodetype,char *Putf8,int *Pputf8len)//~va00R~
{                                                                  //~va00I~
    PUPANCOMP ppand;                                               //~va00I~
    PUPANELC ppc;                                                  //~va00I~
    PUPANELL pupl;                                                 //~va00I~
    char *pdata,*pct,*pu8,*pdbcs;                                  //~va00R~
//  char wk[_MAX_PATH];                                            //~va1cR~
//  char wk[_MAX_PATH*UTF8_MAXCHARSZMAX];                          //~va1cR~//~vav9R~
    char wk[_MAX_PATHU8];                                          //~vav9I~
	int inplen,opt,rc2;                                            //~va00R~
//************************                                         //~va00I~
    ppc=Ppcw->UCWppc;                                              //~va00I~
    pupl=ppc->UPCline+Prow;                                        //~va00I~
    ppand=(PUPANCOMP)(ppc->UPCpandata);                            //~va00I~
    switch(Prow)                                                   //~va00I~
    {                                                              //~va00I~
    case PANLUCFILE1:  //xfc filename1                             //~va00I~
        pdata=ppand->UPANCfnm1;                                    //~va00I~
        pdbcs=ppand->UPANCfnm1dbcs;                                //~va00I~
    	break;                                                     //~va00I~
    case PANLUCFILE2:  //xfc filename2                             //~va00I~
        pdata=ppand->UPANCfnm2;                                    //~va00I~
        pdbcs=ppand->UPANCfnm2dbcs;                                //~va00I~
    	break;                                                     //~va00I~
    }                                                              //~va00I~
    pdata+=Sutilcolstart;                                          //~va00I~
    pdbcs+=Sutilcolstart;                                          //~va00I~
    inplen=(int)strlen(pdata);                                     //~va00I~
    pct=Pcodetype/*+Sutilcolstart*/;                               //~va00R~
    pu8=Putf8/*+Sutilcolstart*/;                                   //~va00R~
    opt=XEUTFCVO_SETCT; //set utf8 even if ascii                   //~va00I~
    rc2=                                                           //~va00I~
	xeutf_fldl2f(opt,pdata,pdbcs,wk,inplen,pct,pu8,Pputf8len);     //~va00R~
    if (rc2==XEUTFILRC_UTF8)                                       //~va00I~
    	pupl->UPLflags|=UPLFUTF8;	//utf8 code                    //~va00I~
    else                                                           //~va00I~
    	pupl->UPLflags&=~UPLFUTF8;	//utf8 code                    //~va00I~
    return inplen;                                                 //~va00I~
}//pancompsetfld_l2f                                               //~va00R~
//*******************************************************          //~va00I~
//*save kbdinput under UTF8 env by utf8code                        //~va00I~
//*return locale code len                                          //~va00I~
//*******************************************************          //~va00I~
int pangrepsetfld_l2f(int Popt,PUCLIENTWE Ppcw,int Prow,char *Pcodetype,char *Putf8,int *Pputf8len)//~va00I~
{                                                                  //~va00I~
    PUPANGREP ppand;                                               //~va00R~
    PUPANELC ppc;                                                  //~va00I~
    PUPANELL pupl;                                                 //~va00I~
    char *pdata,*pct,*pu8,*pdbcs;                                  //~va00R~
//  char wk[_MAX_PATH];                                            //~va1cR~
//  char wk[_MAX_PATH*UTF8_MAXCHARSZMAX];                          //~va1cR~//~vav9R~
    char wk[_MAX_PATHU8];                                          //~vav9I~
	int inplen,idx,opt,rc2;                                        //~va00R~
//************************                                         //~va00I~
    ppc=Ppcw->UCWppc;                                              //~va00I~
    pupl=ppc->UPCline+Prow;                                        //~va00I~
    ppand=(PUPANGREP)(ppc->UPCpandata);                            //~va00R~
    idx=Prow-PANLUGFILE1;                                          //~va00I~
    pdata=ppand->UPANGfnm[idx];                                    //~va00I~
    pdbcs=ppand->UPANGfnmdbcs[idx];                                //~va00I~
    pdata+=Sutilcolstart;                                          //~va00I~
    pdbcs+=Sutilcolstart;                                          //~va00I~
    inplen=(int)strlen(pdata);                                     //~va00I~
    pct=Pcodetype/*+Sutilcolstart*/;                               //~va00R~
    pu8=Putf8/*+Sutilcolstart*/;                                   //~va00R~
    opt=XEUTFCVO_SETCT; //set utf8 even if ascii                   //~va00I~
    rc2=                                                           //~va00I~
	xeutf_fldl2f(opt,pdata,pdbcs,wk,inplen,pct,pu8,Pputf8len);     //~va00R~
    if (rc2==XEUTFILRC_UTF8)                                       //~va00I~
    	pupl->UPLflags|=UPLFUTF8;	//utf8 code                    //~va00I~
    else                                                           //~va00I~
    	pupl->UPLflags&=~UPLFUTF8;	//utf8 code                    //~va00I~
    return inplen;                                                 //~va00I~
}//pangrepsetfld_l2f                                               //~va00I~
#endif	//AAA                                                      //~va0tI~
//**************************************************************** //~va00I~
// get locale filename from utf8 fld data                          //~va00I~
//rc: 1:f2l done                                                   //~va00I~
//**************************************************************** //~va00I~
int panutilsetfld_f2l(int Popt,PUPANELL Ppupl,char *Pdata,char *Pdatabylc,int Poutbuffsz,int *Ppoutlen)//~va00I~
{                                                                  //~va00I~
	int inplen,lenlc,lenr,rc=0,rc2;                                //~va00R~
    char *pct,*pu8;                                                //~va00I~
//************************                                         //~va00I~
//  inplen=strlen(Pdata);                                          //~va00I~//~vb30R~
    inplen=(int)strlen(Pdata);                                     //~vb30I~
    pct=Ppupl->UPLcodetype/*+Sutilcolstart*/;                      //~va00R~
    pu8=Ppupl->UPLbuffbyutf8/*+Sutilcolstart*/;                    //~va00R~
UTRACED("panutilsetfld_f2l inp",Pdata,inplen);                     //~va00I~
  if (Popt & PSFF2LO_USECT)	//codetype tbl was setup               //~va5wR~
  {                                                                //~va5wI~
//#ifdef LNX                                                         //~vaubI~//~vavpR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaI~//~vavpI~
    rc2=xeutf_cvlf2lbyctDDW(0,Pdata,inplen,pct,inplen,Pdatabylc,Poutbuffsz,&lenlc);	//ct is new type(along ddfmt for utf8 part)//~vaubI~
#else                                                              //~vaubI~
    rc2=xeutf_cvlf2lbyct(0,Pdata,inplen,pct,inplen,Pdatabylc,Poutbuffsz,&lenlc);//~va5wR~
#endif                                                             //~vaubI~
    if (rc2 & 1)                                                   //~va5wI~
    	rc2=XEUTFGU8MRC_UTF8;                                      //~va5wI~
  }                                                                //~va5wI~
  else                                                             //~va5wI~
  {                                                                //~va5wI~
//#ifdef LNX                                                         //~vaubI~//~vavpR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaI~//~vavpI~
//FIXME test surrogate:FIXED                                       //~vav9I~//~vaweR~
#ifdef W32UNICODE                                                  //~vavcI~
//FIXME fullpath?:FIXED                                                  //~vavcI~//~vavNR~
   if (uftpisremote(Pdata,NULL))                                        //~vavcI~//~vavpR~
    rc2=xeutf_getlocalepathname(XEUTFGLPNO_STRZ|XEUTFGLPNO_LCWIDTHBYDDWIDTH|XEUTFGLPNO_REMOTE,Pdata,inplen,Pdatabylc,pct,Poutbuffsz,&lenlc,NULL/*pdddata*/,NULL/*pdddbcs*/,NULL/*pddcode*/,0/*ddbuffsz*/,NULL/*pddlen*/);//~vavcI~
   else                                                            //~vavcI~
#endif                                                             //~vavcI~
    rc2=xeutf_getlocalepathname(XEUTFGLPNO_STRZ|XEUTFGLPNO_LCWIDTHBYDDWIDTH,Pdata,inplen,Pdatabylc,pct,Poutbuffsz,&lenlc,NULL/*pdddata*/,NULL/*pdddbcs*/,NULL/*pddcode*/,0/*ddbuffsz*/,NULL/*pddlen*/);//~vaubI~
#else                                                              //~vaubI~
//  rc2=xeutf_getlocalepathname(XEUTFGLPNO_STRZ,Pdata,inplen,Pdatabylc,pct,Poutbuffsz,&lenlc);//~vauaR~
    rc2=xeutf_getlocalepathname(XEUTFGLPNO_STRZ,Pdata,inplen,Pdatabylc,pct,Poutbuffsz,&lenlc,NULL/*pdddata*/,NULL/*pdddbcs*/,NULL/*pddcode*/,0/*ddbuffsz*/,NULL/*pddlen*/);//~vauaI~
#endif                                                             //~vaubI~
  }                                                                //~va5wI~
    if (rc2 & XEUTFGU8MRC_UTF8)                                    //~va00I~
    {                                                              //~va00I~
#ifdef W32UNICODE                                                  //~vaweI~
	  if (memchr(Pdatabylc,UD_NOTLC,lenlc))	//drop space from ct of UD str//~vaweI~
      {                                                            //~vaweI~
      	fsubw_stripUDCT(0,Pdatabylc,lenlc,Pdatabylc,lenlc,pct,lenlc,&lenlc);//~vaweR~
        fsubw_stripUDCT(0,Pdata,inplen,pu8,inplen,NULL/*outct*/,0/*outctsz*/,&inplen);//~vaweR~
      }                                                            //~vaweI~
      else                                                         //~vaweI~
#endif                                                             //~vaweI~
      {                                                            //~vaweI~
//    	Ppupl->UPLflags|=UPLFUTF8;	//utf8 code                    //~va00R~
        memcpy(pu8,Pdata,(UINT)inplen+1); //save utf8              //~va00I~
//      Ppupl->UPLctlen=lenlc;                                     //~va00R~
      }                                                            //~vaweI~
        rc=1;                                                      //~va00I~
    }                                                              //~va00I~
    else                                                           //~va00I~
    {                                                              //~va00I~
//    	Ppupl->UPLflags&=~UPLFUTF8;	//no utf8 code                 //~va00R~
        memcpy(pu8,Pdata,(UINT)inplen+1); //save locale            //~va00I~
//      Ppupl->UPLctlen=inplen;                                    //~va00R~
    }                                                              //~va00I~
    if ((lenr=Poutbuffsz-lenlc)>0)                                 //~va00I~
	    memset(Pdatabylc+lenlc,0,(UINT)lenr);	//clear for charpan update//~va00R~
    if (Ppoutlen)                                                  //~va00I~
        *Ppoutlen=lenlc;                                           //~va00I~
UTRACEP("panutilsetfld_f2l out lenlc=%d\n",lenlc);                 //~va00R~
UTRACED("panutilsetfld_f2l out",Pdatabylc,lenlc+1);                //~va00I~
    return rc;                                                     //~va00I~
}//panutilsetfld_f2l                                               //~va00I~
//**************************************************************** //~va00I~
// from captofld                                                   //~va00R~
//**************************************************************** //~va00I~
int panutilfldupdate_utf8(int Popt,PUCLIENTWE Ppcw,int Prow,int Pfldno,int Poffs,char *Pdata,int Pdatalen,char*Pdbcs)//~va00R~
{                                                                  //~va00I~
//  PUPANELC ppc;                                                  //~va00I~//~vaa7R~
//	PUPANELL pupl;                                                 //~va00I~//~vaa7R~
    char srccodetype[UPLBUFF2SZ];                                  //~va00I~
    char srcutf8[UPLBUFF2SZ];                                      //~va00R~
    char  *flddata,*flddbcs,*ptgtutf8,*ptgtcodetype;               //~va00R~
	int srclclen,srcutf8len,fldwidth,opt,/*tgtutf8len,*/tgtlclen/*,rc2*/;  //~va00R~//~vaa7R~
//************************                                         //~va00I~
//  if (panutildataproc(PANUO_GETLINE|PANUO_FLDTOP,Ppcw,&flddata,&flddbcs,&fldwidth))//~va00R~//~va0ER~
	opt=PANUO_GETLINE|PANUO_FLDTOP;                                //~va0EI~
	if (Popt & PUFU8O_PARMROW)                                     //~va0EI~
    	opt|=Prow;                                                 //~va0EI~
    if (panutildataproc(opt,Ppcw,&flddata,&flddbcs,&fldwidth))     //~va0EI~
    	return -1;				//fld top addr                     //~va00I~
    srclclen=Pdatalen;    //strlen at mixedstrupdate               //~va00I~
    tgtlclen=-1;  //strlen at mixedstrupdate                       //~va00I~
    UTRACED("flddata",flddata,fldwidth);                           //~vaubI~
    UTRACED("flddata",flddbcs,fldwidth);                           //~vaubI~
    if (!getfldutf8(Ppcw,Prow,Pfldno,&ptgtutf8,&ptgtcodetype)) //field has utf8/codetype buff//~va00I~
    {                                                              //~va00I~
    	opt=XEUTFMSUO_STRZ|XEUTFMSUO_SETUTF8RC;                    //~va00I~
        if (Popt & PUFU8O_INS)                                     //~va00I~
            opt|=XEUTFMSUO_INS;                                    //~va00I~
//      tgtutf8len=-1;  //strlen at mixedstrupdate                 //~va00I~//~vaa7R~
        *srcutf8=0;     //setup src utf8/codetype                  //~va00I~
        srcutf8len=0;                                              //~va00I~
//      ppc=Ppcw->UCWppc;                                          //~va00I~//~vaa7R~
//      pupl=ppc->UPCline+Prow;                                    //~va00I~//~vaa7R~
#ifdef UTF8UCS2                                                    //~va20R~
      if (Popt & PUFU8O_SETCT2)	//pass lc by Gcmdbuff              //~va20I~
        /*rc2=*/xeutf_mixedstrupdate(opt,flddata,ptgtutf8,ptgtcodetype,flddbcs,tgtlclen,0/*&(pupl->UPLctlen)*/,0/*out utf8len*/,//~va20I~//~vaa7R~
                        Poffs,fldwidth,                            //~va20I~
                        Gcmdbufflc,Pdata,Gcmdbuffct,Pdbcs,Gcmdbufflclen,Pdatalen,sizeof(Gcmdbuffu8));//~va20I~
      else                                                         //~va20I~
#endif                                                             //~va20I~
        /*rc2=*/xeutf_mixedstrupdate(opt,flddata,ptgtutf8,ptgtcodetype,flddbcs,tgtlclen,0/*&(pupl->UPLctlen)*/,0/*out utf8len*/,//~va00R~//~vaa7R~
                        Poffs,fldwidth,                            //~va00R~
                        Pdata,srcutf8,srccodetype,Pdbcs,srclclen,srcutf8len,sizeof(srcutf8));//~va00R~
//      if (rc2==XEUTFMSURC_UTF8)       //target contains utf8 coed//~va00R~
//          pupl->UPLflags|=UPLFUTF8;                              //~va00R~
//      else                                                       //~va00R~
//          pupl->UPLflags&=~UPLFUTF8;                             //~va00R~
    }                                                              //~va00I~
    else                                                           //~va00I~
    {                                                              //~va00I~
        opt=SFDDO_STRZ;                                            //~va00I~
        if (Popt & PUFU8O_INS)                                     //~va00I~
            opt|=SFDDO_INS;                                        //~va00I~
        setflddatadbcs(opt,flddata,flddbcs,tgtlclen,0/*&(pupl->UPLctlen)*/,Poffs,fldwidth,Pdata,Pdbcs,srclclen);//~va00R~
    }                                                              //~va00I~
	panutildataproc(PANUO_SETFLD|PANUO_SETSAVE,Ppcw,0,0,0);        //~va00I~
    return 0;                                                      //~va00R~
}//panutilfldupdate_utf8                                           //~va00I~
//**************************************************************** //~va00I~
// transplate codetype utf8<-->locale                              //~va00I~
//return locale code length                                        //~va00I~
//**************************************************************** //~va00I~
int pancompsetflddata_utf8(PUCLIENTWE Ppcw,int Prow,int Pfldno,UCHAR *Pdata)//~va00I~
{                                                                  //~va00I~
	PUPANELC ppc;                                                  //~va00I~
	PUPANELL   pupl;                                               //~va00I~
	int lenlc;                                                     //~va00R~
//	char *pu8,*pct,*pdata,wkcv[_MAX_PATH+1];                       //~va1cR~
//	char /**pu8,*pct,*/*pdata,wkcv[_MAX_PATH*UTF8_F2LMAXRATE+1];       //~va1cR~//~vaa7R~//~vav9R~
  	char /**pu8,*pct,*/*pdata,wkcv[_MAX_PATHF2L+1];                //~vav9I~
//************************                                         //~va00I~
    ppc=Ppcw->UCWppc;                                              //~va00I~
    pdata=Pdata;	//null for PANL300FILENAME,PANL300DIR          //~va00I~
    pupl=ppc->UPCline+Prow;                                        //~va00I~
//  pct=pupl->UPLcodetype;                                         //~va00R~//~vaa7R~
//  pu8=pupl->UPLbuffbyutf8;                                       //~va00R~//~vaa7R~
    switch(Prow)                                                   //~va00I~
    {                                                              //~va00I~
    case PANLUCCDIR:  //current path                               //~va00I~
		if (pansetfld_f2l(0,pupl,0/*fldno*/,Pdata,wkcv,sizeof(wkcv),&lenlc))	//f2l done//~va00R~
            pdata=wkcv;                       //set SDbuff by locale code//~va00I~
        break;                                                     //~va00I~
    case PANLUCFILE1:  //xfc filename1                             //~va00I~
    case PANLUCFILE2:  //xfc filename2                             //~va00I~
#ifdef CCC                                                         //~va0tR~
        if (!Pdata)  //from charpan                                //~va00R~
        {                                                          //~va00I~
        	lenlc=pancompsetfld_l2f(0,Ppcw,Prow,pct,pu8,0/*utf8len*/);//~va00R~
//      	pupl->UPLctlen=lenlc;                                  //~va00R~
        }                                                          //~va00I~
#else                                                              //~va0tI~
//  	    pupl->UPLflags|=UPLFUTF8;	//utf8 code                //~va00R~
#endif                                                             //~va0tI~
        break;                                                     //~va00I~
    }                                                              //~va00I~
#ifdef CCC                                                         //~va0tI~
    if (pdata)	//set to plbuff required                           //~va00I~
    {                                                              //~va00I~
        UCBITON(Ppcw->UCWflag2,UCWF2SETFLD);    //avoid recursive call//~va00I~
#endif                                                             //~va0tI~
        lenlc=setflddata(Ppcw,Prow,Pfldno,pdata); //set locale code to UPLdata//~va00I~
#ifdef CCC                                                         //~va0tI~
        UCBITOFF(Ppcw->UCWflag2,UCWF2SETFLD);                      //~va00I~
//     	pupl->UPLctlen=lenlc;                                      //~va00R~
    }                                                              //~va00I~
#endif                                                             //~va0tI~
    return lenlc;                                                  //~va00I~
}//pancompsetflddata_utf8                                          //~va00I~
//**************************************************************** //~va00I~
// transplate codetype utf8<-->locale                              //~va00I~
//return locale code length                                        //~va00I~
//**************************************************************** //~va00I~
int pangrepsetflddata_utf8(PUCLIENTWE Ppcw,int Prow,int Pfldno,UCHAR *Pdata)//~va00I~
{                                                                  //~va00I~
	PUPANELC ppc;                                                  //~va00I~
	PUPANELL   pupl;                                               //~va00I~
	int lenlc;                                                     //~va00R~
//  char *pu8,*pct,*pdata,wkcv[_MAX_PATH+1];                       //~va1cR~
//  char /**pu8,*pct,*/*pdata,wkcv[_MAX_PATH*UTF8_F2LMAXRATE+1];       //~va1cR~//~vaa7R~//~vav9R~
    char /**pu8,*pct,*/*pdata,wkcv[_MAX_PATHF2L+1];                //~vav9I~
//************************                                         //~va00I~
    ppc=Ppcw->UCWppc;                                              //~va00I~
    pdata=Pdata;	//null for PANL300FILENAME,PANL300DIR          //~va00I~
    pupl=ppc->UPCline+Prow;                                        //~va00I~
//  pct=pupl->UPLcodetype;                                         //~va00R~//~vaa7R~
//  pu8=pupl->UPLbuffbyutf8;                                       //~va00R~//~vaa7R~
    if (Prow==PANLUGCDIR)  //current path                          //~va00I~
    {                                                              //~va00I~
		if (pansetfld_f2l(0,pupl,0/*fldno*/,Pdata,wkcv,sizeof(wkcv),&lenlc))	//f2l done//~va00R~
            pdata=wkcv;                       //set SDbuff by locale code//~va00I~
    }                                                              //~va00I~
    else                                                           //~va00I~
    if (Prow>=PANLUGFILE1 && Prow<=PANLUGFILELAST)                 //~va00I~
    {                                                              //~va00I~
#ifdef CCC                                                         //~va0tR~
        if (!Pdata)  //not from charpan                            //~va00R~
        {                                                          //~va00I~
        	lenlc=pangrepsetfld_l2f(0,Ppcw,Prow,pct,pu8,0/*utf8len*/);//~va00R~
//      	pupl->UPLctlen=lenlc;                                  //~va00R~
        }                                                          //~va00I~
#else                                                              //~va0tI~
//		pupl->UPLflags|=UPLFUTF8;	//utf8 code                    //~va00R~
#endif                                                             //~va0tI~
    }                                                              //~va00I~
#ifdef CCC                                                         //~va0tI~
    if (pdata)	//set to plbuff required                           //~va00I~
    {                                                              //~va00I~
        UCBITON(Ppcw->UCWflag2,UCWF2SETFLD);    //avoid recursive call//~va00I~
#endif                                                             //~va0tI~
        lenlc=setflddata(Ppcw,Prow,Pfldno,pdata); //set locale code to UPLdata//~va00I~
#ifdef CCC                                                         //~va0tI~
        UCBITOFF(Ppcw->UCWflag2,UCWF2SETFLD);                      //~va00I~
//      pupl->UPLctlen=lenlc;                                      //~va00R~
    }                                                              //~va00I~
#endif                                                             //~va0tM~
    return lenlc;                                                  //~va00I~
}//pangrepsetflddata_utf8                                          //~va00R~
//#ifdef AAA                                                         //~va0EI~//~vavpR~
////**************************************************************** //~va00I~//~vavpR~
//// get fld data addr(filename,dir,current)                         //~va00I~//~vavpR~
////**************************************************************** //~va00I~//~vavpR~
//UCHAR *pancompgetfldpos_utf8(PUCLIENTWE Ppcw,int Prow,int Pfldno,UCHAR *Pdata)//~va00I~//~vavpR~
//{                                                                  //~va00I~//~vavpR~
//    PUPANELC ppc;                                                  //~va00I~//~vavpR~
//    PUPANELL   pupl;                                               //~va00I~//~vavpR~
//    UCHAR *pu8;                                                    //~va00I~//~vavpR~
////************************                                         //~va00I~//~vavpR~
//    if (UCBITCHK(Ppcw->UCWflag2,UCWF2SETFLD))   //from setflddata_utf8//~va00I~//~vavpR~
//        return Pdata;                                              //~va00I~//~vavpR~
//    ppc=Ppcw->UCWppc;                                              //~va00I~//~vavpR~
//    pupl=ppc->UPCline+Prow;                                        //~va00I~//~vavpR~
//    pu8=pupl->UPLbuffbyutf8;                                       //~va00I~//~vavpR~
//    switch(Prow)                                                   //~va00I~//~vavpR~
//    {                                                              //~va00I~//~vavpR~
//    case PANLUCCDIR:  //current path                               //~va00I~//~vavpR~
//        if (pu8)    //utf8 code                                    //~va00R~//~vavpR~
//            return pu8;                                            //~va00R~//~vavpR~
//        break;                                                     //~va00I~//~vavpR~
//    }                                                              //~va00I~//~vavpR~
//    return Pdata;                                                  //~va00R~//~vavpR~
//}//pancompgetfldpos_utf8                                           //~va00I~//~vavpR~
////**************************************************************** //~va00I~//~vavpR~
//// get fld data addr(filename,dir,current)                         //~va00I~//~vavpR~
////**************************************************************** //~va00I~//~vavpR~
//UCHAR *pangrepgetfldpos_utf8(PUCLIENTWE Ppcw,int Prow,int Pfldno,UCHAR *Pdata)//~va00I~//~vavpR~
//{                                                                  //~va00I~//~vavpR~
//    PUPANELC ppc;                                                  //~va00I~//~vavpR~
//    PUPANELL   pupl;                                               //~va00I~//~vavpR~
////************************                                         //~va00I~//~vavpR~
//    if (UCBITCHK(Ppcw->UCWflag2,UCWF2SETFLD))   //from setflddata_utf8//~va00I~//~vavpR~
//        return Pdata;                                              //~va00I~//~vavpR~
//    ppc=Ppcw->UCWppc;                                              //~va00I~//~vavpR~
//    pupl=ppc->UPCline+Prow;                                        //~va00I~//~vavpR~
//    if (Prow==PANLUGCDIR)                                          //~va00R~//~vavpR~
//        return pupl->UPLbuffbyutf8;                                //~va00R~//~vavpR~
//    return Pdata;                                                  //~va00R~//~vavpR~
//}//pangrepgetfldpos_utf8                                           //~va00I~//~vavpR~
//#endif //AAA                                                       //~va0EI~//~vavpR~
#endif //UTF8SUPPH                                                 //~va00I~
//#ifdef AAA                                                         //~vaucI~//~vavpR~
//#ifdef LNX                                                         //~vaubI~//~vavpR~
////**************************************************************** //~vaubI~//~vavpR~
////* ini file get                                                   //~vaubI~//~vavpR~
////**************************************************************** //~vaubI~//~vavpR~
//int panutiliniread(char *Pfnm,FILE *Pfh,void *Pbuff,int Plen)      //~vaubI~//~vavpR~
//{                                                                  //~vaubI~//~vavpR~
//    int len;                                                       //~vaubI~//~vavpR~
////*****************                                                //~vaubI~//~vavpR~
//    len=fread(Pbuff,1,Plen,Pfh);                                   //~vaubR~//~vavpR~
//    if (len!=Plen)                                                 //~vaubI~//~vavpR~
//    {                                                              //~vaubI~//~vavpR~
//        ufileapierr(Pfnm,"read",errno);                            //~vaubI~//~vavpR~
//        return 4;                                                  //~vaubI~//~vavpR~
//    }                                                              //~vaubI~//~vavpR~
//    return 0;                                                      //~vaubI~//~vavpR~
//}//panutiliniread                                                  //~vaubR~//~vavpR~
////**************************************************************** //~vaubI~//~vavpR~
//int panutiliniwrite(char *Pfnm,FILE *Pfh,void *Pbuff,int Plen)     //~vaubR~//~vavpR~
//{                                                                  //~vaubI~//~vavpR~
//    int len;                                                       //~vaubI~//~vavpR~
////*****************                                                //~vaubI~//~vavpR~
//    len=fwrite(Pbuff,1,Plen,Pfh);                                  //~vaubI~//~vavpR~
//    if (len!=Plen)                                                 //~vaubI~//~vavpR~
//    {                                                              //~vaubI~//~vavpR~
//        ufileapierr(Pfnm,"write",errno);                           //~vaubI~//~vavpR~
//        return 4;                                                  //~vaubI~//~vavpR~
//    }                                                              //~vaubI~//~vavpR~
//    return 0;                                                      //~vaubI~//~vavpR~
//}                                                                  //~vaubI~//~vavpR~
////**************************************************************** //~vaubI~//~vavpR~
////*rc:1:err no more errmsg required,4:corrupted file               //~vaubI~//~vavpR~
////**************************************************************** //~vaubI~//~vavpR~
//int panutilinigetDDFMTsub(char *Pfnm,FILE *Pfh)                    //~vaubI~//~vavpR~
//{                                                                  //~vaubI~//~vavpR~
//    int ii;                                                        //~vaubR~//~vavpR~
//    UINT4 wkint;                                                   //~vaubI~//~vavpR~
//    UCHAR acronym[4]=PANUTILACRNM;                                 //~vaubI~//~vavpR~
//    UCHAR wkbuff[_MAX_PATH*3];  //dddata/dddbcs/ddcode             //~vaubI~//~vavpR~
//    UCHAR *pc;                                                     //~vaubI~//~vavpR~
////*****************                                                //~vaubI~//~vavpR~
//    if (panutiliniread(Pfnm,Pfh,wkbuff,sizeof(acronym)))           //~vaubR~//~vavpR~
//        return 1;   //err but no more msg                          //~vaubI~//~vavpR~
//    if (memcmp(wkbuff,acronym,sizeof(acronym)))                    //~vaubR~//~vavpR~
//        return 4;   //invalid data msg                             //~vaubI~//~vavpR~
//    if (panutiliniread(Pfnm,Pfh,&wkint,sizeof(wkint)))             //~vaubR~//~vavpR~
//        return 1;   //err but no more msg                          //~vaubI~//~vavpR~
//    if (wkint!=PANU_VERSION)                                       //~vaubI~//~vavpR~
//        return 4;   //invalid data msg                             //~vaubI~//~vavpR~
//    if (panutiliniread(Pfnm,Pfh,&wkint,sizeof(wkint)))             //~vaubR~//~vavpR~
//        return 1;   //err but no more msg                          //~vaubI~//~vavpR~
//    if (wkint!=PUDIE_MAXENT)                                       //~vaubI~//~vavpR~
//        return 4;   //invalid data msg                             //~vaubI~//~vavpR~
//    for (ii=0;ii<PUDIE_MAXENT;ii++)                                //~vaubI~//~vavpR~
//    {                                                              //~vaubI~//~vavpR~
//        if (panutiliniread(Pfnm,Pfh,&wkint,sizeof(wkint)))         //~vaubR~//~vavpR~
//            return 1;   //err but no more msg                      //~vaubI~//~vavpR~
//        if (wkint>sizeof(wkbuff))                                  //~vaubI~//~vavpR~
//            return 4;   //invalid data msg                         //~vaubI~//~vavpR~
//        if(wkint%3)                                                //~vaubI~//~vavpR~
//            return 4;   //invalid data msg                         //~vaubI~//~vavpR~
//        if (panutiliniread(Pfnm,Pfh,wkbuff,wkint))                 //~vaubR~//~vavpR~
//            return 1;   //err but no more msg                      //~vaubI~//~vavpR~
//        pc=umalloc(wkint+3);                                       //~vaubR~//~vavpR~
//        if (!pc)                                                   //~vaubI~//~vavpR~
//            return 1;                                              //~vaubI~//~vavpR~
//        Sddfmtsztb[ii]=wkint/3;                                    //~vaubI~//~vavpR~
//        Sddfmttb[ii]=pc;                                           //~vaubI~//~vavpR~
//        memcpy(pc,wkbuff,wkint);                                   //~vaubI~//~vavpR~
//    }                                                              //~vaubI~//~vavpR~
//    return 0;                                                      //~vaubI~//~vavpR~
//}//panutilinigetDDFMTsub                                           //~vaubI~//~vavpR~
////**************************************************************** //~vaubI~//~vavpR~
////*rc:1:err no more errmsg required,4:corrupted file               //~vaubI~//~vavpR~
////**************************************************************** //~vaubI~//~vavpR~
//void panutilfreeddfmt()                                            //~vaubI~//~vavpR~
//{                                                                  //~vaubI~//~vavpR~
//    int ii;                                                        //~vaubI~//~vavpR~
////*****************                                                //~vaubI~//~vavpR~
//    for (ii=0;ii<PUDIE_MAXENT;ii++)                                //~vaubI~//~vavpR~
//    {                                                              //~vaubI~//~vavpR~
//        Sddfmtsztb[ii]=0;                                          //~vaubI~//~vavpR~
//        UFREEIFNZ(Sddfmttb[ii]);                                   //~vaubI~//~vavpR~
//        Sddfmttb[ii]=0;                                            //~vaubI~//~vavpR~
//    }                                                              //~vaubI~//~vavpR~
//}//panutilinigetDDFMTsub                                           //~vaubI~//~vavpR~
////**************************************************************** //~vaubI~//~vavpR~
////* ini file get                                                   //~vaubI~//~vavpR~
////* parm1 :pcw                                                     //~vaubI~//~vavpR~
////* retrn:rc                                                       //~vaubI~//~vavpR~
////**************************************************************** //~vaubI~//~vavpR~
//int panutilinigetDDFMT()                                           //~vaubI~//~vavpR~
//{                                                                  //~vaubI~//~vavpR~
//static int Srecursive;                                             //~vaubI~//~vavpR~
//    int rc;                                                        //~vaubI~//~vavpR~
//    UCHAR savefile[]=WORKDIRPATHID PANUTILFNM;  //"xe_save_panutil"//~vaubI~//~vavpR~
//    UCHAR fpath[_MAX_PATH];                                        //~vaubI~//~vavpR~
//    FILE *fh;                                                      //~vaubI~//~vavpR~
////*****************                                                //~vaubI~//~vavpR~
//    if (Srecursive)                                                //~vaubI~//~vavpR~
//        return 0;                                                  //~vaubI~//~vavpR~
//    Srecursive=1;                                                  //~vaubI~//~vavpR~
//    if (filefind(savefile,fpath,0,FFNONFMSG))//no need fstat3      //~vaubR~//~vavpR~
//        return 1;                                                  //~vaubI~//~vavpR~
//    if (!(fh=fileopen(fpath,"rb")))                                //~vaubI~//~vavpR~
//    {                                                              //~vaubI~//~vavpR~
//        ufileapierr(fpath,"open",errno);                           //~vaubI~//~vavpR~
//        return 1;                                                  //~vaubI~//~vavpR~
//    }                                                              //~vaubI~//~vavpR~
//    panutiliniget(fh);  //with different codetbl pattern           //~vaubI~//~vavpR~
//    rc=panutilinigetDDFMTsub(fpath,fh);                            //~vaubI~//~vavpR~
//    fclose(fh);                                                    //~vaubI~//~vavpR~
//    if (rc==4)                                                     //~vaubI~//~vavpR~
//    {                                                              //~vaubI~//~vavpR~
//        uerrmsg("save file for utility panel(%s) is corrupted,delete it and restart\n",0,//~vaubI~//~vavpR~
//                fpath);                                            //~vaubI~//~vavpR~
//    }                                                              //~vaubI~//~vavpR~
//    if (rc)                                                        //~vaubI~//~vavpR~
//        panutilfreeddfmt();                                        //~vaubR~//~vavpR~
//    return rc;                                                     //~vaubI~//~vavpR~
//}//panutilinigetDDFMT                                              //~vaubI~//~vavpR~
////**************************************************************** //~vaubI~//~vavpR~
////* ini file get                                                   //~vaubI~//~vavpR~
////* parm1 :pcw                                                     //~vaubI~//~vavpR~
////* retrn:rc                                                       //~vaubI~//~vavpR~
////**************************************************************** //~vaubI~//~vavpR~
//int panutiliniputDDFMT()                                           //~vaubI~//~vavpR~
//{                                                                  //~vaubI~//~vavpR~
//static int Srecursive;                                             //~vaubI~//~vavpR~
//    UCHAR savefile[]=WORKDIRPATHID PANUTILFNM;  //"xe_save_panutil"//~vaubI~//~vavpR~
//    UCHAR fpath[_MAX_PATH];                                        //~vaubI~//~vavpR~
//    UINT4 wkint,rc,ii;                                             //~vaubR~//~vavpR~
//    UCHAR acronym[4]=PANUTILACRNM;                                 //~vaubI~//~vavpR~
//    FILE *fh;                                                      //~vaubI~//~vavpR~
////*****************                                                //~vaubI~//~vavpR~
//    if (Srecursive)                                                //~vaubI~//~vavpR~
//        return 0;                                                  //~vaubI~//~vavpR~
//    Srecursive=1;                                                  //~vaubI~//~vavpR~
//    filefullpath(fpath,savefile,sizeof(fpath));                    //~vaubI~//~vavpR~
//    if (!(fh=fileopen(fpath,"wb")))                                //~vaubI~//~vavpR~
//    {                                                              //~vaubI~//~vavpR~
//        ufileapierr(fpath,"open",errno);                           //~vaubR~//~vavpR~
//        return 1;                                                  //~vaubI~//~vavpR~
//    }                                                              //~vaubI~//~vavpR~
//    panutiliniput(fh);  //of version3 with different codetbl pattern//~vaubI~//~vavpR~
//    rc=1;                                                          //~vaubI~//~vavpR~
//    for (;;)                                                       //~vaubI~//~vavpR~
//    {                                                              //~vaubI~//~vavpR~
//        if (panutiliniwrite(fpath,fh,acronym,sizeof(acronym)))     //~vaubR~//~vavpR~
//            break;                                                 //~vaubI~//~vavpR~
//        wkint=PANU_VERSION;                                        //~vaubI~//~vavpR~
//        if (panutiliniwrite(fpath,fh,&wkint,sizeof(wkint)))        //~vaubR~//~vavpR~
//            break;                                                 //~vaubI~//~vavpR~
//        wkint=PUDIE_MAXENT;                                        //~vaubI~//~vavpR~
//        if (panutiliniwrite(fpath,fh,&wkint,sizeof(wkint)))        //~vaubR~//~vavpR~
//            break;                                                 //~vaubI~//~vavpR~
//        for (ii=0;ii<PUDIE_MAXENT;ii++)                            //~vaubI~//~vavpR~
//        {                                                          //~vaubI~//~vavpR~
//            wkint=Sddfmtsztb[ii]*3;                                //~vaubI~//~vavpR~
//            if (panutiliniwrite(fpath,fh,&wkint,sizeof(wkint)))    //~vaubR~//~vavpR~
//                break;                                             //~vaubI~//~vavpR~
//            if (panutiliniwrite(fpath,fh,Sddfmttb[ii],wkint))      //~vaubR~//~vavpR~
//                break;                                             //~vaubI~//~vavpR~
//        }                                                          //~vaubI~//~vavpR~
//        rc=0;                                                      //~vaubI~//~vavpR~
//        break;                                                     //~vaubI~//~vavpR~
//    }                                                              //~vaubI~//~vavpR~
//    fclose(fh);                                                    //~vaubI~//~vavpR~
//    if (rc)                                                        //~vaubI~//~vavpR~
//        ufileapierr(fpath,"write",errno);                          //~vaubI~//~vavpR~
//    return rc;                                                     //~vaubI~//~vavpR~
//}//panutiliniputDDFMT                                              //~vaubI~//~vavpR~
//#endif  //LNX                                                      //~vaubI~//~vavpR~
//#endif  //AAA                                                      //~vaucI~//~vavpR~
//************************************************************************************//~vbkdI~
int pan23chkcpu8option(int Popt,char *Ppoptstr)                    //~vbkdI~
{                                                                  //~vbkdI~
	int swcpu8;                                                    //~vbkdI~
//*********************                                            //~vbkdI~
	swcpu8=ustrstri(Ppoptstr,MODE_UTF8)!=0;                        //~vbkdR~
    UTRACEP("%s:rc=%d,optstr=%s\n",UTT,swcpu8,Ppoptstr);           //~vbkdI~
	return swcpu8;                                                 //~vbkdI~
}//pan23chkcpu8option                                              //~vbkdI~
//************************************************************************************//~vbkdI~
int	pan23ShowCmdResult(int Popt,PUCLIENTWE Ppcw,char *Pfnm)        //~vbkdR~
{                                                                  //~vbkdI~
    char cmdstr[_MAX_PATH*2+MAXCOLUMN],*pc;                        //~vbkdR~
    int len,rc;                                                    //~vbkdI~
//*******************                                              //~vbkdI~
	pc=cmdstr;                                                     //~vbkdI~
  	if (Popt & P23SCRO_CPU8)                                       //~vbkdI~
    	pc+=sprintf(pc,"%c %s %s %s",'e',Pfnm,MODE_UTF8,MODE_IE);  //~vbkdR~
  	else                                                           //~vbkdI~
    	pc+=sprintf(pc,"%c %s",'e',Pfnm);                          //~vbkdR~
    len=(int)((ULPTR)pc-(ULPTR)cmdstr);                            //~vbkdI~
    rc=funcsetlongcmd(Ppcw,1,cmdstr,len,0); //1:execute(put on cmd buff),0:no output len//~vbkdI~
    UTRACEP("%s:rc=%d,cmd=%s\n",UTT,rc,cmdstr);                    //~vbkdI~
    return rc;                                                     //~vbkdI~
}//pan23ShowCmdResult                                              //~vbkdI~
