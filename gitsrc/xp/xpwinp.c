//CID://+v994R~:        update#=   28                              //+v994R~
//**********************************************************************
//* xpwinp.c                                                       //~v928R~
//**********************************************************************
//v994:160308 v9.32 W32 compiler warning                           //+v994I~
//v990:140506 v9.30 (W32UNICODE) filename by UD fmt                //~v990I~
//120629 v968 VC2010:LP64 support                                  //~v968I~
//120616 v967 for VC6:/W4 warning except C4115,C4214,C4100,C4706,C4244,C4210,C4127,C4245//~v967I~
//120611 v965 avoid C4701 warning(variable may not be uninitialized)//~v965I~
//101106 v962 (Win:BUG)if without /c for multiple file(wildcard) print,char-height shrink gradually//~v962I~
//            height/width rate shirink by maxcol 82:41-->98(by lineCellHeight<106):53-->75:41//~v962I~
//100909 v955 v9.19 print EBC file by TextOutW for avoid print "?" for trans err to locale code//~v955I~
//100706 v950 v9.18 64bit compile                                  //~v950I~
//071013 v92f (Win)auto-set maxcol/maxline when not predefined pich specified//~v92fI~
//071005 v928 (Win)UTF8 support                                    //~v928I~
//030113 v91f try driber setting chng                              //~v91fI~
//020720 v916 (WIN)auto set form orientation by option /Yd         //~v916I~
//020719 v914 support FORM2P for prntyp WIN                        //~v914I~
//020406 v90v (WIN)Letter support(ZHnn) for the case drive setup is not work//~v90vI~
//011218 v90q :v90p has no effect(2nd page back to default font)   //~v90qI~
//             win95 reset at startpage.                           //~v90qI~
//011218 v90p :(TEST)try setmapmode also when /Nr                  //~v90pI~
//010401 v904 :2 parts print suport for windows printer            //~v904I~
//            (no form parm for windows,auto pich calc by device info)//~v904I~
//990829 v889 :/Yt win trace option for win.                       //~v889I~
//981219 v885 :(WIN)left margin                                    //~v885I~
//981114 v875 :(WIN)set lpi when specified maxline only(no lpi/no form specified)//~v875I~
//981114 v874 :(WIN)set cpi when specified maxcol only(no cpi/no form specified)//~v874I~
//981028 v869 :docname parm support(/J)                            //~v869I~
//981024 v862 :(WIN)delete logfont at each closedoc                //~v862I~
//981024 v861 :(WIN)support other posrt                            //~v861I~
//981024 v860 :chk output is printer by enumprinter                //~v860I~
//980927 v844 :(WIN) /EW option(use Win32 API to use spool)
//971124 v831 :split xppf from xprint
//971123 v827 :split xpsub1 from xrint.c
//970928 v826 :w95 version
//970214 v807:use FINDBUF3 by ufile.h
//961210 v788:72cpi for ibm pagep
//961210 v787:lipsIII kanji cpi is fixed at 72 cpi(max colum=100)
//961210 v786:use unit 1/180 inchi not but 1/360 inch
//            because canon escp emulator not supported 1/360
//961108 v785:1st page EJECT bypass option
//961106 v784:ESCP has ROMAN font
//961106 v783:Cannon printer support(LIPS-III)
//960113 v752 :set lpitch default to 6-lpi
//950829 v74l :form id on /E
//**********************************************************************
#include <time.h>     //v1.1
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>    //v1.6add
#include <string.h>   //v1.3add

//**********************************************************************
#include <windows.h>                                               //~v844R~
//**********************************************************************

#include <ulib.h>                                                  //~v844R~
#include <ufile.h>                                                 //~v844R~
#include <ustring.h>                                               //~v844I~
#include <utrace.h>                                                //~v91fI~
#include <uerr.h>                                                  //~v990I~
#include <ufilew.h>                                                //~v990I~

#include "xp.h"
#include "xpwinp.h"
#include "xp2p.h"                                                  //~v914I~
#include "xpesc.h"                                                 //~v916I~
#include "xputf.h"                                                 //~v928I~
//*********************************************************************
extern char pgmid[];
extern char ver[];
extern int  dbcsenv;           //dbcs environment sw v4.9a v7.23r
extern int maxline;    //line   no per page v7.23r                 //~v844I~
extern int lineskip;   //1:double space,2:tripple space            //~v875I~
extern int esccmdlen;          //esccmd lenngth     ..v2.9add v3.6rep//~v844I~
extern int asciimode;        //char set id                     v2.5add//~v844I~
extern int hdr0linesw;       //in xppf,header0 print req           //~v844I~
extern int skip1stff2;       //1st formfeed skip option            //~v844I~
extern char *prn;				//output dest name                 //~v861I~
extern char *jobname;			//document name	override			v7.11a//~v869I~
extern int Gtraceopt;			//trace option to stdout           //~v889I~
extern int linespec;            //line count parm specified sw     //~v904I~
extern int breakpage;           //current page count from last for despage print//~v904I~
extern int despageno;           //total page of despage print      //~v904R~
extern int Gzoomh,Gzoomw;       //zoom rate                        //~v90vI~
extern int Gdriversetsw;		//set orientation,form at createdc //~v916R~
extern int Gformtype;	     	//orientation,form                 //~v916I~
//**********************************************************************
#define MAXELF 4            	//4 candidate                      //~v844R~
#define TOPMARGIN 32        	//page top margin                  //~v875R~
#define TOPMARGIN2 90        	//page top margin                  //~v904R~
#define LEFTMARGIN 30        	//page left margin                 //~v885R~
#define LEFTMARGIN2 60        	//page left margin                 //~v904R~
#define RIGHTMARGIN 10        	//page right margin                //~v92fI~
static int   Sformsz[3][2]={        //unit=mm                      //~v92fI~
//  				{297,420},	//A3                               //~v92fI~
					{210,297},	//A4   h/v                         //~v92fI~
//  				{148,210},	//A5                               //~v92fI~
					{257,364},	//B4                               //~v92fI~
					{182,257} 	//B5                               //~v92fI~
//  				{216,279},	//letter                           //~v92fI~
//  				{216,355} 	//leagal                           //~v92fI~
                    };                                             //~v92fI~
#define INCHESBYMM      ((float)1.0/(float)25.4)       //1inch=25.4mm//~v92fI~
#define MM2POINT(mm)    ((float)((float)mm*INCHESBYMM*72)) //1inch=72point=25.4mm//~v92fI~
#define POINT2MM(pt)    ((float)((float)pt/72/INCHESBYMM)) //1inch=72point=25.4mm//~v92fI~
                                                                   //~v92fI~
static	ENUMLOGFONT Self[MAXELF];	//4 candidit parm to callback func//~v844R~
static	LOGFONT Slogfont;                                          //~v844I~
static float Sfhwrate=0.0;                                         //~v962I~
static	int     Sfontid;		//parm to callback func
static	HDC hdc;
static  int Sopendocsw,Sopenpagesw;                                //~v844R~
static  int Sfontfoundsw;                                          //~v844R~
static  int Spagewidthpixel,Spageheightpixel;	//pixel of DC      //~v844R~
static  int Sinchwidthpixel,Sinchheightpixel;	//inch by pixel    //~v844R~
static  int Scharwidth,Scharheight;				//char size by pixel//~v844R~
static  int Slineheight;                                           //~v844I~
static  int Sleftmargin=LEFTMARGIN;                                //~v904R~
static  int Stopmargin=TOPMARGIN;                                  //~v904I~
static  int Sposx,Sposy,Sposy1st;                                  //~v844R~
static  int Srightpageposx;      //right page start pos            //~v904I~
static  int Sendjobsw;                                             //~v844I~
static  int Sfontlistsw;        //list req by ?                    //~v844I~
static  int Sfontlistctr;       //serched font counter             //~v844I~
static  HDC Shdc;                                                  //~v844I~
static  HFONT Shfont;                                              //~v844I~
static  char *Sfontnm;                                             //~v844I~
static  char Sprinter[128];                                        //~v861I~
static  char Sport[32];                                            //~v861I~
static int Snpnrsw;                                                //~v904I~
//**********************************************************************
void win_getdriverinf(char *Ptype,char *Pdriver,char *Pport);
HDC win_createdc(char *Pdriver,char *Ptype,char *Pport);
int win_searchfont(HDC Phdc,char *Pfontnm,ENUMLOGFONT *Pelf);      //~v844R~
void win_setmapmode(void);                                         //~v844I~
void win_selectobject(void);                                       //~v844I~
void win_createlogfont(int Phmi,int Pvmi);                         //~v844I~
void win_closepage(void);
void win_chktm(void);                                              //~v844I~
//void win_chkelf(int Pft,ENUMLOGFONT *Pelf);                      //~v91fR~
void win_chkelf(int Pft,CONST LOGFONT *Pelf);                      //~v91fI~
void win_chkdc(void);                                              //~v844I~
void win_getdcinf(void);                                           //~v844I~
void win_getstockobject(ENUMLOGFONT *Pelf);                        //~v844R~
//**********************************************************************//~v860I~
//* setup FONT object                                              //~v860I~
//parm:output destination name ptr                                 //~v860I~
//ret :1:output is printer,0:output is file                        //~v860I~
//**********************************************************************//~v860I~
int win_portchk(char *Poutid)                                      //~v860R~
{                                                                  //~v860I~
    PRINTER_INFO_5 *inf5;                                          //~v860I~
    DWORD need,retcnt,buffsz;                                      //~v860I~
    int rc;                                                        //~v860R~
    char *buff,*portid;                                            //~v860R~
//********************************                                 //~v860I~
    if (!stricmp(Poutid,"PRN"))                                    //~v860R~
    	return 1;                                                  //~v860I~
                                                                   //~v860I~
    if (!EnumPrinters(PRINTER_ENUM_LOCAL,                          //~v860R~
						NULL,				//name                 //~v860I~
						5,					//level                //~v860I~
						NULL,  				//outbuff              //~v860R~
						0,		    	   //buffsz                //~v860R~
						&need,              //need byte            //~v860I~
						&retcnt))                                  //~v860R~
	{                                                              //~v860I~
    	rc=GetLastError();                                         //~v860I~
		if (rc!=ERROR_INSUFFICIENT_BUFFER)                        	//~v860R~
        {                                                          //~v860I~
	    	printf("EnumPrinter-1 failed,rc=%d\n",rc);             //~v860R~
        	return 0;		//treate as file                       //~v860R~
        }                                                          //~v860I~
	}                                                              //~v860I~
//printf("need=%d,retc=%d\n",need,retcnt);                         //~v860R~
    buffsz=need;                                                   //~v860R~
	buff=malloc(buffsz);                                           //~v860R~
    if (!EnumPrinters(PRINTER_ENUM_LOCAL,                          //~v860I~
						NULL,				//name                 //~v860I~
						5,					//level                //~v860I~
						buff,				//outbuff              //~v860I~
						buffsz,                  //buffsz          //~v860I~
						&need,              //need byte            //~v860I~
						&retcnt))                                  //~v860I~
    {                                                              //~v860I~
    	printf("EnumPrinter-2 failed,rc=%d\n",GetLastError());     //~v860I~
        free(buff);                                                //~v860I~
        return 0;		//treate as file                           //~v860I~
	}                                                              //~v860I~
//printf("req=%d,need=%d,retc=%d\n",buffsz,need,retcnt);           //~v860R~
//serach port                                                      //~v860I~
    inf5=(PRINTER_INFO_5*)(void*)buff;                             //~v860I~
    for (;retcnt>0;retcnt--,inf5++)                                //~v860R~
    {                                                              //~v860I~
//printf("req=%s,portname=%s\n",Poutid,inf5->pPortName);           //~v860R~
    	if (portid=inf5->pPortName,portid)                         //~v860I~
        {                                                          //~v860I~
        	*(portid+strlen(portid)-1)=0;	//drop last ':'        //~v860I~
	    	if (!stricmp(Poutid,portid))                           //~v860R~
            {                                                      //~v861I~
            	strcpy(Sprinter,inf5->pPrinterName);               //~v861I~
            	strcpy(Sport,inf5->pPortName);                     //~v861I~
    	    	break;                                             //~v860R~
			}                                                      //~v861I~
        }                                                          //~v860I~
	}                                                              //~v860I~
	free(buff);                                                    //~v860R~
    if (retcnt>0)                                                  //~v860R~
        rc=1;           //printer                                  //~v860M~
    else                                                           //~v860I~
        rc=0;           //file output                              //~v860I~
//printf("ret port chk rc=%d\n",rc);                               //~v860R~
    return rc;                                                     //~v860R~
}//win_portchk                                                     //~v860I~
                                                                   //~v860I~
//**********************************************************************
//* setup FONT object
//parm:fontname or NULL if no parm specified                       //~v844R~
//**********************************************************************
void win_setupfont(char *Pfontnm)                                  //~v844R~
{
	ENUMLOGFONT elf;
    char    prntype[128];
	char    prndriver[128];
	char    prnport[32];                                           //~v861R~
//********************************
    if (Shdc)                                                      //~v844M~
    {                                                              //~v844M~
		if (Gtraceopt)		//trace option by /Yt                  //~v889I~
			printf("dupricated DC set request\n");                 //~v889R~
        return;                                                    //~v844R~
	}                                                              //~v844M~
  if (!stricmp(prn,"PRN"))                                         //~v861R~
    win_getdriverinf(prntype,prndriver,prnport);
  else                                                             //~v861I~
  {                                                                //~v861I~
    strcpy(prntype,Sprinter);	//gotten at portchk                //~v861R~
    strcpy(prnport,Sport);	//gotten at portchk                    //~v861I~
  }                                                                //~v861I~
	Shdc=win_createdc(prndriver,prntype,prnport);
//win_chktm();                                                     //~v844R~
    win_getdcinf();           //get resolusion                     //~v844R~
	Sfontfoundsw=(win_searchfont(Shdc,Pfontnm,&elf)==0);           //~v844R~

    Slogfont=elf.elfLogFont;					//save selected LOGFONT//~v844R~
	if (Slogfont.lfHeight && Slogfont.lfWidth)                     //~v962I~
		Sfhwrate=(float)Slogfont.lfHeight/(float)Slogfont.lfWidth; //~v962R~
    else                                                           //~v962I~
    	Sfhwrate=0.0;                                              //~v962I~
//win_chkelf(0,&elf);                                              //~v844R~
    win_setmapmode();		//unit=pixel                           //~v844I~
    if (Gtraceopt)      //trace option by /Yt                      //~v90vI~
    {                                                              //~v90vI~
		win_chkdc();           //get resolusion                    //~v90vI~
        printf("Page Width=%d ,Height=%d pixel;CharWidth=%d, LineHeight=%d pixel.\n",//~v90vI~
				Spagewidthpixel,Spageheightpixel,Scharwidth,Slineheight);//~v90vR~
    }                                                              //~v90vI~
	return;                                                        //~v844R~
}//win_setupfont

//***************************************************************************
//*get driver info using GetProfileString
//parm1:output printer type
//parm2:output drivername
//parm3:output port name
//ret :none
//**************************************************************************
void win_getdriverinf(char *Ptype,char *Pdriver,char *Pport)
{
    char    buff[512];
    char    *pc,*prntype,*prndriver,*prnport;;                     //~v844R~
//********************************

    if (!GetProfileString("windows", "device", (LPSTR)NULL, buff,sizeof(buff)))
	{
		printf("\nGetrofileString failed rc=%d\n",GetLastError()); //~v844R~
		exit(8);
    }
	if (Gtraceopt)		//trace option by /Yt                      //~v889I~
		printf("getdriverinf:profile=%s\n",buff);                  //~v889R~
//*
    pc=prntype=buff;
    prndriver=prnport=0;
    while (*pc)
	{
		if (*pc==',')
		{
	    	*pc++=0;
	    	while (*pc==' ')
				pc++;
	    	if (!prndriver)                	//first time
				prndriver=pc;
	    	else
			{
				prnport=pc;
				break;
	    	}
		}
		else
			pc++;
    }
    if (!prndriver)                                                //~v844R~
        prndriver="";                                              //~v844R~
    if (!prnport)                                                  //~v844R~
        prnport="";                                                //~v844R~
	if (Gtraceopt)		//trace option by /Yt                      //~v889I~
		printf("printer driver name get\n\
				type=%s,driver=%s,port=%s\n",                      //~v889R~
				prntype,prndriver,prnport);                        //~v889R~
    strcpy(Ptype,prntype);
	if (prndriver)                                                 //~v844R~
    	strcpy(Pdriver,prndriver);
    else
    	*Pdriver=0;
    if (prnport)
	    strcpy(Pport,prnport);
    else
    	*Pport=0;
	return;
}//wingetdriverinf
//***************************************************************************//~v916I~
//*get current devmode                                             //~v916I~
//ret  :devmode struc                                              //~v916I~
//**************************************************************************//~v916I~
DEVMODE *getsetdm(char *Ppdevicename,DEVMODE *Ppdm)                //~v916I~
{                                                                  //~v916I~
    HANDLE hprinter;                                               //~v916I~
    HANDLE mho,mhi;                                                //~v91fI~
//  DEVMODE dmin,dmout,*pdmout,*pdmin;                             //~v91fR~
    DEVMODE  *pdmout,*pdmin;                                       //~v91fI~
    LPDEVMODE gpdmout,gpdmin;                                      //~v91fI~
    int len;                                                       //~v91fI~
    int mode,rc;                                                   //~v916I~
//*****************                                                //~v916I~
	rc=OpenPrinter(Ppdevicename,&hprinter,NULL);                   //~v916I~
    if (!rc)                                                       //~v916I~
    {                                                              //~v916I~
    	printf("Opendriver Failed for %s,rc=%d\n",Ppdevicename,GetLastError());//~v916I~
        return 0;                                                  //~v916I~
    }                                                              //~v916I~
    mode=0; //get size                                             //~v916I~
//  rc=DocumentProperties(HWND_TOP,hprinter,Ppdevicename,&dmout,&dmin,mode);//~v91fR~
    rc=DocumentProperties(HWND_TOP,hprinter,Ppdevicename,NULL,NULL,mode);//~v91fI~
//printf("dmsize=%d\n",rc);                                        //~v916R~
    if (rc<=0)                                                     //~v916I~
    {                                                              //~v916I~
        printf("DocumentProperties(get size) Failed for %s,rc=%d\n",Ppdevicename,GetLastError());//~v916I~
        return 0;                                                  //~v916I~
    }                                                              //~v916I~
    pdmout=malloc(rc);                                             //~v916I~
    len=rc;                                                        //~v91fI~
    if (!Ppdm)	//get                                              //~v916I~
    {                                                              //~v916I~
	    mho=GlobalAlloc(GHND,len);                                 //~v91fI~
		gpdmout=(LPDEVMODE)GlobalLock(mho);                        //~v91fI~
        mode=DM_OUT_BUFFER; //get current setting                  //~v916I~
//      rc=DocumentProperties(HWND_TOP,hprinter,Ppdevicename,pdmout,&dmin,mode);//~v91fR~
        rc=DocumentProperties(HWND_TOP,hprinter,Ppdevicename,gpdmout,NULL,mode);//~v91fI~
        memcpy(pdmout,gpdmout,(UINT)len);                          //~v91fI~
UTRACED("docprop get",pdmout,64);                                  //~v91fR~
		GlobalFree(mho);                                           //~v91fI~
//printf("get dm rc=%d\n",rc);                                     //~v916R~
        if (!rc)                                                   //~v916I~
        {                                                          //~v916I~
            printf("DocumentProperties(get devmode) Failed for %s,rc=%d\n",Ppdevicename,GetLastError());//~v916I~
            return 0;                                              //~v916I~
        }                                                          //~v916I~
    }//get                                                         //~v916I~
    else                                                           //~v916I~
    {                                                              //~v916I~
	    mho=GlobalAlloc(GHND,len);                                 //~v91fI~
		gpdmout=(LPDEVMODE)GlobalLock(mho);                        //~v91fI~
	    mhi=GlobalAlloc(GHND,len);                                 //~v91fI~
		gpdmin=(LPDEVMODE)GlobalLock(mhi);                         //~v91fI~
    	pdmin=Ppdm;                                                //~v916I~
        memcpy(gpdmin,pdmin,(UINT)len);                            //~v91fI~
        mode=DM_IN_BUFFER|DM_OUT_BUFFER; //get current setting     //~v91fR~
        mode|=DM_IN_PROMPT; //get current setting                  //~v91fI~
//      rc=DocumentProperties(HWND_TOP,hprinter,Ppdevicename,pdmout,pdmin,mode);//~v91fR~
        rc=DocumentProperties(HWND_TOP,hprinter,Ppdevicename,gpdmout,gpdmin,mode);//~v91fI~
//UTRACEP("dlg rc=%d\n",rc);                                       //~v91fR~
UTRACED("docprop set-in",gpdmin,64);                               //~v91fR~
UTRACED("docprop set-out",gpdmout,64);                             //~v91fR~
        memcpy(pdmout,gpdmout,(UINT)len);                          //~v91fI~
		GlobalFree(mho);                                           //~v91fI~
		GlobalFree(mhi);                                           //~v91fI~
//printf("set dm rc=%d\n",rc);                                     //~v916R~
        if (rc==IDCANCEL)                                          //~v91fM~
        {                                                          //~v91fM~
            printf("Print Canceled\n");                            //~v91fM~
            exit(4);                                               //~v91fM~
        }                                                          //~v91fM~
        if (!rc)                                                   //~v916I~
        {                                                          //~v916I~
            printf("DocumentProperties(set devmode) Failed for %s,rc=%d\n",Ppdevicename,GetLastError());//~v916I~
            return 0;                                              //~v916I~
        }                                                          //~v916I~
    }                                                              //~v916I~
    if (!ClosePrinter(hprinter))                                   //~v91fR~
    	printf("Closedriver Failed for %s,rc=%d\n",Ppdevicename,GetLastError());//~v91fR~
    return pdmout;                                                 //~v916I~
}                                                                  //~v916I~
//***************************************************************************//~v91fI~
//*printer setup                                                   //~v91fI~
//ret  :devmode struc                                              //~v91fI~
//**************************************************************************//~v91fI~
DEVMODE *setupform(char *Ppdevicename,int Pori,int Ppapersz)       //~v91fI~
{                                                                  //~v91fI~
    DEVMODE  *pdm,*pdmo;                                           //~v91fI~
    HANDLE hprinter;                                               //~v91fI~
    HANDLE mh;                                                     //~v91fI~
    PRINTER_DEFAULTS pd;                                           //~v91fI~
    PRINTER_INFO_2  *ppi2;                                         //~v91fI~
//  int buffsz=0,rc,mode;                                          //~v91fR~//~v967R~
    int rc,mode;                                                   //~v967I~
    ULONG buffsz=0;                                                //~v967I~
//*****************                                                //~v91fI~
    memset(&pd,0,sizeof(pd));                                      //~v91fI~
    pd.DesiredAccess = PRINTER_ALL_ACCESS;                         //~v91fI~
	rc=OpenPrinter(Ppdevicename,&hprinter,&pd);                    //~v91fI~
    if (!rc)                                                       //~v91fI~
    {                                                              //~v91fI~
    	printf("OpenPrinter Failed for %s,rc=%d\n",Ppdevicename,GetLastError());//~v91fI~
        return 0;                                                  //~v91fI~
    }                                                              //~v91fI~
    GetPrinter(hprinter,2,0,0,&buffsz);//2:ifolevel,0:buff addr,0:buffsz//~v91fI~
    if (!buffsz)                                                   //~v91fI~
    {                                                              //~v91fI~
    	printf("GetPrinter-1 Failed for %s,rc=%d\n",Ppdevicename,GetLastError());//~v91fI~
        return 0;                                                  //~v91fI~
    }                                                              //~v91fI~
	mh=GlobalAlloc(GHND,buffsz);                                   //~v91fI~
    ppi2=(PRINTER_INFO_2*)GlobalLock(mh);                          //~v91fI~
    if (!GetPrinter(hprinter,2,(LPBYTE)ppi2,buffsz,&buffsz))       //~v91fI~
    {                                                              //~v91fI~
    	printf("GetPrinter-2 Failed for %s,rc=%d\n",Ppdevicename,GetLastError());//~v91fI~
	    GlobalFree(mh);                                            //~v91fM~
        return 0;                                                  //~v91fI~
    }                                                              //~v91fI~
//UTRACED("getprinter ppi2",ppi2,256);                             //~v91fR~
	pdm=ppi2->pDevMode;                                            //~v91fI~
UTRACED("getprinter pdm",pdm,64);                                  //~v91fR~
UTRACEP("ori=%d,form=%d\n",Pori,Ppapersz);                         //~v91fR~
	if (pdm->dmOrientation!=Pori || pdm->dmPaperSize!=Ppapersz)    //~v91fI~
    {                                                              //~v91fI~
//  	pdm->dmOrientation=Pori;                                   //~v91fR~//+v994R~
    	pdm->dmOrientation=(short)Pori;                            //+v994I~
//  	pdm->dmPaperSize=Ppapersz;                                 //~v91fR~//+v994R~
    	pdm->dmPaperSize=(short)Ppapersz;                          //+v994I~
UTRACED("setprinter",pdm,64);                                      //~v91fR~
//UTRACED("setprinter ppi2",ppi2,256);                             //~v91fR~
    	rc=SetPrinter(hprinter,2,(LPBYTE)ppi2,0);//2:ifolevel,0:buff addr,0:buffsz//~v91fR~
//UTRACED("setprinter",pdm,64);                                    //~v91fR~
    	if (!rc)                                                   //~v91fR~
    	{                                                          //~v91fR~
    		printf("SetPrinter Failed for %s,rc=%d\n",Ppdevicename,GetLastError());//~v91fR~
	    	GlobalFree(mh);                                        //~v91fI~
        	return 0;                                              //~v91fR~
    	}                                                          //~v91fR~
    	if (!GetPrinter(hprinter,2,(LPBYTE)ppi2,buffsz,&buffsz))   //~v91fI~
    	{                                                          //~v91fI~
    		printf("GetPrinter-2 Failed for %s,rc=%d\n",Ppdevicename,GetLastError());//~v91fI~
	    	GlobalFree(mh);                                        //~v91fI~
        	return 0;                                              //~v91fI~
    	}                                                          //~v91fI~
UTRACED("getprinter after setprinter",pdm,64);                     //~v91fR~
    }//ori or paper changed                                        //~v91fI~
//get result                                                       //~v91fI~
	mode=0;                                                        //~v91fI~
    buffsz=DocumentProperties(HWND_TOP,hprinter,Ppdevicename,NULL,NULL,mode);//~v91fI~
    if (buffsz<=0)                                                 //~v91fI~
    {                                                              //~v91fI~
        printf("DocumentProperties(get size) Failed for %s,rc=%d\n",Ppdevicename,GetLastError());//~v91fI~
	    GlobalFree(mh);                                            //~v91fI~
        return 0;                                                  //~v91fI~
    }                                                              //~v91fI~
    pdmo=malloc(buffsz);                                           //~v91fI~
    memcpy(pdmo,pdm,buffsz);                                       //~v91fI~
    GlobalFree(mh);                                                //~v91fM~
//    mode=DM_OUT_BUFFER; //get current setting                    //~v91fR~
//    rc=DocumentProperties(HWND_TOP,hprinter,Ppdevicename,pdmo,NULL,mode);//~v91fR~
//    if (!rc)                                                     //~v91fR~
//    {                                                            //~v91fR~
//        printf("DocumentProperties(get devmode) Failed for %s,rc=%d\n",Ppdevicename,GetLastError());//~v91fR~
//        free(pdmo);                                              //~v91fR~
//        return 0;                                                //~v91fR~
//    }//get                                                       //~v91fR~
//UTRACED("docprop",pdmo,64);                                      //~v91fR~
	if (!ClosePrinter(hprinter))                                   //~v91fI~
    	printf("Closedriver Failed for %s,rc=%d\n",Ppdevicename,GetLastError());//~v91fI~
    return pdmo;                                                   //~v91fI~
}//setupform                                                       //~v91fI~
//***************************************************************************//~v916I~
//*initialze devmode struc                                         //~v916I~
//ret  :1:devmode set required,0:not required                      //~v916R~
//**************************************************************************//~v916I~
int win_initdm(DEVMODE **Ppdm,char *Pdriver,char *Ptype,char *Pport)//~v916R~
{                                                                  //~v916I~
	DEVMODE *pdm;                                                  //~v916I~
    int ori,papersz=DMPAPER_A4;                                               //~v91fI~//~v965R~
//********************************                                 //~v916I~
	*Ppdm=0;                                                       //~v916I~
	if (Gtraceopt)		//trace option by /Yt                      //~v916I~
		printf("initdm:devicename=%s,driver=%s,port=%s\n",Ptype,Pdriver,Pport);//~v916I~
//  pdm=getsetdm(Ptype,0);	//get current dm                       //~v91fR~
//  if (!pdm)                                                      //~v91fR~
//  	return 0;                                                  //~v91fR~
//    pdm->dmSpecVersion=DM_SPECVERSION;                           //~v916R~
//    rc=DeviceCapabilities(Ptype,Pport,DC_DRIVER,0,NULL);         //~v916R~
//    if (Gtraceopt)      //trace option by /Yt                    //~v916R~
//        printf("DriverVersion=%d\n",rc);                         //~v916R~
//    pdm->dmDriverVersion=rc;                                     //~v916R~
//    pdm->dmSize=sizeof(DEVMODE);                                 //~v916R~
//    pdm->dmDriverExtra=0;                                        //~v916R~
//  pdm=&dm;                                                       //~v91fR~
//  pdm->dmFields=0;                                               //~v91fR~
//  pdm->dmFields|=DM_ORIENTATION;                                 //~v91fR~
    if (Gformtype & PFT_YOKO)                                      //~v916I~
    {                                                              //~v916I~
    	ori=DMORIENT_LANDSCAPE;                                    //~v91fR~
		if (Gtraceopt)		//trace option by /Yt                  //~v916I~
			printf("initdm:landscape\n");                          //~v916R~
    }                                                              //~v916I~
    else                                                           //~v916I~
    {                                                              //~v916I~
    	ori=DMORIENT_PORTRAIT;                                     //~v91fR~
		if (Gtraceopt)		//trace option by /Yt                  //~v916I~
			printf("initdm:portrate\n");                           //~v916R~
    }                                                              //~v916I~
    if ((Gformtype & PFT_FORM)==PFT_A4)                            //~v916I~
    {                                                              //~v916I~
//  	pdm->dmFields|=DM_PAPERSIZE;                               //~v91fR~
    	papersz=DMPAPER_A4;                                        //~v91fR~
		if (Gtraceopt)		//trace option by /Yt                  //~v916I~
			printf("initdm:A4\n");                                 //~v916I~
    }                                                              //~v916I~
    if ((Gformtype & PFT_FORM)==PFT_B4)                            //~v916R~
    {                                                              //~v916I~
//  	pdm->dmFields|=DM_PAPERSIZE;                               //~v91fR~
    	papersz=DMPAPER_B4;                                        //~v91fR~
		if (Gtraceopt)		//trace option by /Yt                  //~v916I~
			printf("initdm:B4\n");                                 //~v916I~
    }                                                              //~v916I~
    if ((Gformtype & PFT_FORM)==PFT_B5)                            //~v916I~
    {                                                              //~v916I~
//  	pdm->dmFields|=DM_PAPERSIZE;                               //~v91fR~
    	papersz=DMPAPER_B5;                                        //~v91fR~
		if (Gtraceopt)		//trace option by /Yt                  //~v916I~
			printf("initdm:B5\n");                                 //~v916I~
    }                                                              //~v916I~
                                                                   //~v91fI~
    pdm=setupform(Ptype,ori,papersz);	//set and get new dm       //~v91fR~
//canon lbp dose not work for setprinter so documentproperties with prompt requred//~v91fI~
    pdm=getsetdm(Ptype,0);	//get current dm                       //~v91fI~
    if (!pdm)                                                      //~v91fM~
    	return 0;                                                  //~v91fM~
    if (pdm->dmOrientation!=ori||pdm->dmPaperSize!=papersz)        //~v91fR~
    {                                                              //~v91fI~
	    pdm->dmFields=0;                                           //~v91fI~
	    pdm->dmFields|=DM_ORIENTATION;                             //~v91fI~
	  	pdm->dmFields|=DM_PAPERSIZE;                               //~v91fI~
//  	pdm->dmOrientation=ori;                                    //~v91fR~//+v994R~
    	pdm->dmOrientation=(short)ori;                             //+v994I~
//  	pdm->dmPaperSize=papersz;                                  //~v91fR~//+v994R~
    	pdm->dmPaperSize=(short)papersz;                           //+v994I~
    	pdm=getsetdm(Ptype,pdm);	//set and get new dm           //~v91fR~
//  	pdm=getsetdm(Ptype,0);	//get current dm                   //~v91fR~
    }                                                              //~v91fI~
//UTRACED("docprop",pdm,64);                                       //~v91fR~
	*Ppdm=pdm;                                                     //~v916I~
	return 1;                                                      //~v916R~
}//win_initdm                                                      //~v916I~
//***************************************************************************
//*create printer dc
//parm1:drivername
//parm2:printer type
//parm3:port name
//ret  :HDC
//**************************************************************************
HDC win_createdc(char *Pdriver,char *Ptype,char *Pport)
{
    HDC  	hdc;
    DEVMODE *pdevmode=0;                                           //~v91fR~
//********************************
	if (Gtraceopt)		//trace option by /Yt                      //~v889I~
		printf("createdc:ptype=%s,driver=%s,port=%s\n",Ptype,Pdriver,Pport);//~v916R~
//	if (!(hdc=CreateDC(Pdriver,Ptype,Pport,0)))
//	if (!(hdc=CreateDC(NULL,Ptype,NULL,0)))//driver name and output is for compatibilty of old win//~v916R~
  	                                       //last 0 is no driver data//~v844R~
    if (Gdriversetsw)		//set orientation,form at createdc     //~v916I~
    {                                                              //~v916I~
    	win_initdm(&pdevmode,Pdriver,Ptype,Pport);	// parm /Nd or no form//~v916R~
        if (!pdevmode)                                             //~v916I~
        	printf("Use /Nd to skip driver setting\n");            //~v916I~
    }                                                              //~v916I~
//printf("pdevmode=%x\n",pdevmode);                                //~v916R~
  	if (!(hdc=CreateDC(NULL,Ptype,NULL,pdevmode)))//driver name and output is for compatibilty of old win//~v916I~
	{
		printf("\nCreateDC(%s) failed,rc=%d\n",                    //~v844R~
				Ptype,GetLastError());
		exit(8);
    }
	return hdc;
}//win_createdc
//****************************************************************************//~v844I~
//reset after startpage for win95                                  //~v844I~
//****************************************************************************//~v844I~
void win_restoredc(void)                                           //~v844I~
{                                                                  //~v844I~
//********************************                                 //~v844I~
//  win_setmapmode();                                              //~v90qR~
    if (UCBITCHK(swsw3,SW3WINNPNR))  //restore required            //~v904I~
    {                                                              //~v904I~
    	if (Snpnrsw)  //win95 also require reset after newpage     //~v904R~
        	return;                                                //~v904R~
    	Snpnrsw=1;                                                 //~v904R~
    }                                                              //~v904I~
//  win_setmapmode();                                              //~v90pR~
    win_setmapmode();                                              //~v90qI~
	win_selectobject();                                            //~v844I~
//win_chkdc();           //get resolusion                          //~v844R~
//win_chktm();                                                     //~v844R~
}//win_restoredc                                                   //~v844I~
//****************************************************************************//~v844I~
//setmapmode                                                       //~v844I~
//****************************************************************************//~v844I~
void win_setmapmode(void)                                          //~v844I~
{                                                                  //~v844I~
    int oldmapmode;                                                //~v844I~
//********************************                                 //~v844I~
	oldmapmode=SetMapMode(Shdc,MM_TEXT);    //set unit is pixel    //~v844M~
    if (!oldmapmode)                                               //~v844M~
    {                                                              //~v844M~
    	printf("\nSetMapMode failed rc=%d\n",GetLastError());      //~v844M~
        uexit(8);                                                  //~v844R~
	}                                                              //~v844M~
    else                                                           //~v844M~
	    if (oldmapmode!=MM_TEXT)                                   //~v844M~
	if (Gtraceopt)		//trace option by /Yt                      //~v889I~
		printf("SetMapMode from %d to %d\n",oldmapmode,MM_TEXT);   //~v889R~
                                                                   //~v844M~
	return;                                                        //~v844I~
}//win_setmapmode                                                  //~v844R~
//****************************************************************************//~v844I~
//select object                                                    //~v844I~
//****************************************************************************//~v844I~
void win_selectobject(void)                                        //~v844I~
{                                                                  //~v844I~
//********************************                                 //~v844I~
    if (!SelectObject(Shdc,Shfont))                                //~v844M~
    {                                                              //~v844M~
        printf("\nSelectObject failed,rc=%d\n",GetLastError());    //~v844M~
        uexit(8);                                                  //~v844R~
    }                                                              //~v844M~
}//win_selectobject                                                //~v844R~
//****************************************************************************//~v844I~
//create logfont                                                   //~v844I~
//p1rm1:char width by 1/720 inch                                   //~v844R~
//*OR minus (column parm-LINENOSZ-1) from xppf.c when no form and no cpi and with maxcol//~v874I~
//p1rm2:char height by 1/720 inch                                  //~v844R~
//****************************************************************************//~v844I~
void win_createlogfont(int Phmi,int Pvmi)                          //~v844I~
{                                                                  //~v844I~
//    int hwrate;                                                    //~v844I~//~v962R~
    int maxcol=0;                                                    //~v874I~//~v965R~
    int maxlin=0;                                                    //~v875I~//~v965R~
    int doublesw;                                                  //~v904I~
//********************************                                 //~v844I~
	doublesw=(UCBITCHK(swsw3,SW3WIN2P)!=0);                        //~v904I~
	if (Phmi<0)	//maxcol parm only(no form,no cpi)                 //~v874I~
    {                                                              //~v874I~
    	maxcol=-Phmi+LINENOSZ+1;	//char in a line               //~v874I~
//      Scharwidth=Spagewidthpixel/maxcol;                         //~v885R~
      if (doublesw)                                                //~v904I~
      {                                                            //~v904I~
      	Sleftmargin=LEFTMARGIN2;                                   //~v904I~
        Scharwidth=((Spagewidthpixel-LEFTMARGIN-LEFTMARGIN2)/maxcol)>>1;//~v904R~
        Srightpageposx=((Spagewidthpixel-LEFTMARGIN-LEFTMARGIN2)>>1)//~v904R~
						+LEFTMARGIN2+LEFTMARGIN;                   //~v904I~
      }                                                            //~v904I~
      else                                                         //~v904I~
      {                                                            //~v904I~
      	Sleftmargin=LEFTMARGIN;                                    //~v904I~
//      Scharwidth=(Spagewidthpixel-LEFTMARGIN)/maxcol;            //~v92fR~
        Scharwidth=(Spagewidthpixel-LEFTMARGIN-RIGHTMARGIN)/maxcol;//~v92fI~
        Srightpageposx=0;                                          //~v904I~
      }                                                            //~v904I~
    }                                                              //~v874I~
    else                                                           //~v874I~
    Scharwidth=(Phmi*Sinchwidthpixel)/720;                         //~v844R~
    if (Gtraceopt)      //trace option by /Yt                      //~v90vI~
        printf("\nPhmi=%d,maxcol=%d,Scharwidth=%d,Spagewidthpixel=%d\n",//~v90vI~
                Phmi,maxcol,Scharwidth,Spagewidthpixel);           //~v90vI~
    if (Gzoomw && Gzoomw!=100)                                     //~v90vR~
	    Scharwidth=Scharwidth*Gzoomw/100;                          //~v90vR~
	if (Pvmi<0)	//maxline parm only(no form,no lpi)                //~v875I~
    {                                                              //~v875I~
    	maxlin=(-Pvmi)*(lineskip+1)+3;	//line in a page last 1 line redundancy//~v875R~
//      Slineheight=(Spageheightpixel-TOPMARGIN*2)/maxlin;         //~v904R~
        if (Srightpageposx) //double page                          //~v904I~
            Stopmargin=TOPMARGIN2;                                 //~v904I~
        else                                                       //~v904I~
            Stopmargin=TOPMARGIN;                                  //~v904I~
        Slineheight=(Spageheightpixel-Stopmargin-Stopmargin)/maxlin;//~v904I~
    }                                                              //~v875I~
    else                                                           //~v875I~
    Slineheight=(Pvmi*Sinchheightpixel)/720;    //posy advance value//~v844R~
    if (Gzoomh && Gzoomh!=100)                                     //~v90vR~
	    Slineheight=Slineheight*Gzoomh/100;                        //~v90vR~
    if (Gtraceopt)      //trace option by /Yt                      //~v90vI~
        printf("Pvmi=%d,maxlin=%d,Slineheight=%d,Spageheightpixel=%d\n",//~v90vI~
                Pvmi,maxlin,Slineheight,Spageheightpixel);         //~v90vI~
//    if (Slogfont.lfWidth)                                          //~v844I~//~v962R~
    if (Sfhwrate!=0.0)                                             //~v962I~
    {                                                              //~v844I~
//        hwrate=(Slogfont.lfHeight*100)/Slogfont.lfWidth;           //~v844I~//~v962R~
//        Scharheight=(Scharwidth*hwrate)/100;                       //~v844I~//~v962R~
        Scharheight=(int)(Scharwidth*Sfhwrate);                    //~v962I~
        if (Scharheight>Slineheight)                               //~v844I~
        	Scharheight=Slineheight;                               //~v844I~
	}                                                              //~v844I~
    else                                                           //~v844I~
    	Scharheight=Slineheight;                                   //~v844I~
	if (Gtraceopt)		//trace option by /Yt                      //~v962M~
		printf("logfont rate=%f cW=%d,cH=%d\n",Sfhwrate,Scharwidth,Scharheight);//~v962I~
	if (Gtraceopt)		//trace option by /Yt                      //~v889I~
		printf("\nOld logfont H=%d,W=%d\n",                        //~v889R~
				Slogfont.lfHeight,Slogfont.lfWidth);               //~v889R~
                                                                   //~v844I~
    Slogfont.lfHeight=Scharheight;                                 //~v844M~
    Slogfont.lfWidth =Scharwidth ;                                 //~v844M~
                                                                   //~v844I~
	if (Gtraceopt)		//trace option by /Yt                      //~v889I~
		printf("New logfont lh=%d,cH=%d=%d*%d/720,W=%d=%d*%d/720\n",//~v889R~
				Slineheight,Slogfont.lfHeight,Pvmi,Sinchheightpixel,//~v889R~
				Slogfont.lfWidth ,Phmi,Sinchwidthpixel);           //~v889R~
                                                                   //~v844R~
//  Slogfont.lfOutPrecision=OUT_DEVICE_PRECIS;  //if doubled use devicefont//~v844R~
    Slogfont.lfOutPrecision=OUT_TT_PRECIS;  //if doubled use devicefont//~v844I~
    Slogfont.lfClipPrecision=CLIP_DEFAULT_PRECIS;                  //~v844R~
//  Slogfont.lfPitchAndFamily=(FIXED_PITCH|FF_MODERN);//monospace  //~v844R~
//             this cause font change by the reason of no candidate//~v844R~
//    if (asciimode!=1)   //katakana set                           //~v844R~
//        Slogfont.lfCharSet=ANSI_CHARSET;                         //~v844R~
//    else                                                         //~v844R~
//        Slogfont.lfCharSet=DEFAULT_CHARSET;                      //~v844R~
//             this cause font change by the reason of no candidate//~v844I~
    if (!(Shfont=CreateFontIndirect(&Slogfont)))                   //~v844I~
    {                                                              //~v844I~
        printf("\nCreateLogFont failed,rc=%d\n",GetLastError());   //~v844I~
        uexit(8);                                                  //~v844R~
    }                                                              //~v844I~
//strat line pos set                                               //~v844I~
//    if ((maxline+4)*Scharheight<Spageheightpixel)                //~v875R~
//        Sposy1st=Slineheight;                                    //~v875R~
//    else                                                         //~v875R~
//	    Sposy1st=Scharheight;                                      //~v875R~
//  Sposy1st=TOPMARGIN;                                            //~v904R~
    Sposy1st=Stopmargin;                                           //~v904I~
	if (Gtraceopt)		//trace option by /Yt                      //~v889I~
		printf("Sposy1st=%d=(%d+4)*%d<%d)\n",                      //~v889R~
				Sposy1st,maxline,Scharheight,Spageheightpixel);    //~v889R~
    return;                                                        //~v844I~
}//win_createlogfont                                               //~v844I~
//****************************************************************************//~v844I~
//get dc inf                                                       //~v844R~
//****************************************************************************//~v844I~
void win_getdcinf(void)                                            //~v844R~
{                                                                  //~v844I~
//********************************                                 //~v844I~
    Spagewidthpixel =GetDeviceCaps(Shdc,HORZRES);  //by pixel      //~v844M~
    Spageheightpixel=GetDeviceCaps(Shdc,VERTRES);  //by pixel      //~v844M~
    Sinchwidthpixel =GetDeviceCaps(Shdc,LOGPIXELSX);  //inch by pixel//~v844M~
    Sinchheightpixel=GetDeviceCaps(Shdc,LOGPIXELSY);  //inch by pixel//~v844M~
    if (Spagewidthpixel<Spageheightpixel)   //width<height         //~v904I~
        UCBITON(swsw3,SW3WINTATE);          //prtrate              //~v904I~
}//win_getdcinf                                                    //~v844R~
                                                                   //~v844M~
//****************************************************************************//~v844I~
//trace dc inf                                                     //~v844I~
//****************************************************************************//~v844I~
void win_chkdc(void)                                               //~v844I~
{                                                                  //~v844I~
//********************************                                 //~v844I~
	printf("pageW=%d,pageH=%d,inchW=%d,inchH=%d,textcap=%d\n",     //~v844I~
    		GetDeviceCaps(Shdc,HORZRES),  //by pixel               //~v844I~
			GetDeviceCaps(Shdc,VERTRES),  //by pixel               //~v844I~
    		GetDeviceCaps(Shdc,LOGPIXELSX),  //inch by pixel       //~v844I~
  			GetDeviceCaps(Shdc,LOGPIXELSY),  //inch by pixel       //~v844I~
			GetDeviceCaps(Shdc,TEXTCAPS));                         //~v844I~
}//win_chkdc                                                       //~v844I~
//****************************************************************************//~v844I~
//chk tm                                                           //~v844I~
//****************************************************************************//~v844I~
void win_chktm(void)                                               //~v844I~
{                                                                  //~v844I~
    TEXTMETRIC tm;                                                 //~v844I~
//********************************                                 //~v844I~
    GetTextMetrics(Shdc,&tm);                                      //~v844R~
    printf("\ntextmetric H=%d,W=%d,MAXW=%d\n",                     //~v844R~
			tm.tmHeight,tm.tmAveCharWidth,tm.tmMaxCharWidth);      //~v844I~
}//win_chktm                                                       //~v844I~
//****************************************************************************//~v844I~
//chk LOGFONT                                                      //~v844I~
//****************************************************************************//~v844I~
//void win_chkelf(int Pft,ENUMLOGFONT *Pelf)                       //~v91fR~
void win_chkelf(int Pft,CONST LOGFONT *Pelf)                       //~v91fI~
{                                                                  //~v844I~
	char fonttype[64];                                             //~v844R~
//********************************                                 //~v844I~
	*fonttype=0;                                                   //~v844I~
    if (Pft & RASTER_FONTTYPE)                                     //~v844I~
    	strcat(fonttype,"RASTER ");                                //~v844R~
    if (Pft & DEVICE_FONTTYPE)                                     //~v844I~
    	strcat(fonttype,"DEVICE ");                                //~v844R~
    if (Pft & TRUETYPE_FONTTYPE)                                   //~v844R~
    	strcat(fonttype,"TRUETYPE");                               //~v844R~
    printf("\nFaceName=\"%s\":%s:\n\
Height=%d,Width=%d,Escapement=%ld,Orientation=%ld,Weight=%ld,Italic=%d,\n\
UnderLine=%d,Strikeout=%d,CharSet=%d,OutPrecision=%d,ClipPrecision=%d,\n\
Quality=%d,PitchAndFamily=%d\n",                                   //~v844I~
        Pelf->lfFaceName,                                          //~v91fR~
        fonttype,                                                  //~v844I~
//        Pelf->elfFullName,                                       //~v91fR~
//        Pelf->elfStyle,                                          //~v91fR~
        Pelf->lfHeight,                                            //~v91fR~
        Pelf->lfWidth,                                             //~v91fR~
        Pelf->lfEscapement,                                        //~v91fR~
        Pelf->lfOrientation,                                       //~v91fR~
        Pelf->lfWeight,                                            //~v91fR~
        (unsigned)Pelf->lfItalic,                                  //~v91fR~
        (unsigned)Pelf->lfUnderline,                               //~v91fR~
        (unsigned)Pelf->lfStrikeOut,                               //~v91fR~
        (unsigned)Pelf->lfCharSet,                                 //~v91fR~
        (unsigned)Pelf->lfOutPrecision,                            //~v91fR~
        (unsigned)Pelf->lfClipPrecision,                           //~v91fR~
        (unsigned)Pelf->lfQuality,                                 //~v91fR~
        (unsigned)Pelf->lfPitchAndFamily);                         //~v91fR~
	return;                                                        //~v844I~
}//win_chkelf                                                      //~v844R~
//***************************************************************************//~v844I~
//*use system stock object                                         //~v844I~
//parm :output ENUMLOGFONT                                         //~v844I~
//ret  :none                                                       //~v844I~
//**************************************************************************//~v844I~
void win_getstockobject(ENUMLOGFONT *Pelf)                         //~v844R~
{                                                                  //~v844I~
    HFONT hfont;                                                   //~v844I~
    LOGFONT lf;                                                    //~v844I~
//********************************                                 //~v844I~
    if (!(hfont=GetStockObject(SYSTEM_FIXED_FONT)))                //~v844I~
    {                                                              //~v844I~
        printf("\nGetStockObject failed for SYSTEM_FIXED_FONT,rc=%d\n",GetLastError());//~v844I~
        uexit(8);                                                  //~v844I~
    }                                                              //~v844I~
    if (!GetObject(hfont,sizeof(lf),&lf))                          //~v844I~
    {                                                              //~v844I~
        printf("\nGetObject failed for SYSTEM_FIXED_FONT,rc=%d\n",GetLastError());//~v844I~
        uexit(8);                                                  //~v844I~
    }                                                              //~v844I~
    Pelf->elfLogFont=lf;                                           //~v844I~
//  strcpy(Pelf->elfFullName,"SYSTEM_FIXED_FONT");                 //~v91fR~
//  strcpy(Pelf->elfStyle,"GetStockObject");                       //~v91fR~
//win_chkelf(0,Pelf);                                              //~v844R~
    return;                                                        //~v844I~
}//win_getstockobject                                              //~v844I~
//***************************************************************************
//*search font parm specified
//parm1:HDC
//parm2:fontid 0:no specificasion use driver setting
//             1:MIN,2:GOT,3:ROM,4:COU,5:SYS
//parm3:output ENUMLOGFONT
//ret  :rc    4:not found SYSTEM_FIXED_FONT use 1:fontid=0         //~v844R~
//**************************************************************************
int win_searchfont(HDC Phdc,char *Pfontnm,ENUMLOGFONT *Pelf)       //~v844R~
{
//  int CALLBACK effp(ENUMLOGFONT FAR *elf,NEWTEXTMETRIC FAR *ntm,int ft,LPARAM lp);//~v91fR~
    int CALLBACK effp(CONST LOGFONT *elf,CONST TEXTMETRIC *ntm,ULONG ft,LPARAM lp);//~v91fR~
    int ii,rc=0;
    int  fontid;                                                   //~v844I~
//********************************
//chk /F parm                                                      //~v844I~
    fontid=0;       //use default                                  //~v844I~
    if (!Pfontnm || !*Pfontnm)                                     //~v844R~
    	fontid=1;			//default MIN                          //~v844I~
 	else                                                           //~v844I~
    {                                                              //~v844I~
//printf("fontname=%s\n",Pfontnm);                                 //~v844R~
        if (*Pfontnm=='?')  //query req                            //~v844I~
        {                                                          //~v844I~
            Sfontlistsw=1;                                         //~v844I~
            if (*(Pfontnm+1))	//not all req                      //~v844I~
            {                                                      //~v844I~
            	Pfontnm++;                                         //~v844I~
	            Sfontlistsw=2;	//specified font group             //~v844I~
			}                                                      //~v844I~
        }                                                          //~v844I~
        if (!stricmp(Pfontnm,"MIN"))                               //~v844R~
            fontid=1;                                              //~v844I~
        if (!stricmp(Pfontnm,"GOT"))                               //~v844R~
            fontid=2;                                              //~v844I~
        if (!stricmp(Pfontnm,"ROM"))                               //~v844R~
            fontid=3;                                              //~v844I~
        if (!stricmp(Pfontnm,"COU"))                               //~v844R~
            fontid=4;                                              //~v844I~
        if (!stricmp(Pfontnm,"SYS"))                               //~v844R~
            fontid=5;                                              //~v844I~
        if (!stricmp(Pfontnm,"OBJ"))                               //~v844I~
            fontid=9;                                              //~v844R~
    }                                                              //~v844I~
	memset(Self,0,sizeof(Self));                                   //~v844R~
    Sfontid=fontid;         //if 0 search direct                   //~v844R~
    Sfontnm=Pfontnm;		//parm to callback                     //~v844R~
    if (fontid==9)                                                 //~v844R~
    {                                                              //~v844R~
      win_getstockobject(Pelf);                                    //~v844R~
      rc=0;                                                        //~v844R~
    }                                                              //~v844R~
    else                                                           //~v844R~
    {                                                              //~v844R~
//search font name                                                 //~v844I~
        EnumFontFamilies(Phdc,0,effp,0);//no specific family name  //~v91fR~
        if (Sfontlistsw)                                           //~v844R~
        {                                                          //~v844R~
            printf("%d font listed\n",Sfontlistctr);               //~v844R~
            uexit(1);                                              //~v844R~
        }                                                          //~v844R~
        for (ii=0;ii<MAXELF;ii++)                                  //~v844R~
        {                                                          //~v844R~
            if (Self[ii].elfLogFont.lfHeight)                      //~v844R~
                break;                                             //~v844R~
        }                                                          //~v844R~
        if (ii>=MAXELF)                                            //~v844R~
        {                                                          //~v844R~
            if (!fontid)                                           //~v844R~
            {                                                      //~v844R~
                printf("\nNo matching Font for parm(%s),try /F? parm to list all Font\n",//~v844R~
                        Pfontnm);                                  //~v844R~
                uexit(8);                                          //~v844R~
            }                                                      //~v844R~
            printf("\nFont search failed of /F parm(%s),SYSTEM_FIXED_FONT may used\n",//~v844R~
                    Pfontnm);                                      //~v844R~
            win_getstockobject(Pelf);                              //~v844R~
            rc=4;                                                  //~v844R~
        }                                                          //~v844R~
        else                                                       //~v844R~
        {                                                          //~v844R~
            *Pelf=Self[ii];                                        //~v844R~
            rc=0;                                                  //~v844R~
        }                                                          //~v844R~
    }//by not getstockobject                                       //~v844R~
  if (Gtraceopt)		//trace option by /Yt                      //~v914I~
	printf("Font=\"%s\" is selected\n",                            //~v844R~
			Pelf->elfLogFont.lfFaceName);                          //~v844R~
    return rc;                                                     //~v844R~
}//win_searchfont

//***************************************************************************
//*callback function from EnumFontFamilies to chk font name with /F parm
//parm1:ENUMLOGFONT ptr
//parm2:NEWTEXTMETRICS ptr
//parm3:font type: x01:RASTER_FONTTYPE
//                 x02:DEVICE_FONTTYPE
//                 x04:TRUETYPE_FONTTYPE
//parm4:user data ptr(not used)
//ret  :rc    4:not found
//**************************************************************************
//int CALLBACK effp(ENUMLOGFONT FAR *Pelf,NEWTEXTMETRIC FAR *Pntm,int Pft,LPARAM Plp)//~v91fR~
int CALLBACK effp(CONST LOGFONT *Pelf,CONST TEXTMETRIC *Pntm,ULONG Pft,LPARAM Plp)//~v91fR~
{
    CONST char *facenm;                                            //~v91fR~
    int  found;                                                    //~v844R~
//*****************************
//    printf("fonttype=%d=%s,style=%s\n",Pft,Pelf->elfFullName,Pelf->elfStyle);//~v844R~
//win_chkelf(Pft,Pelf);                                            //~v844R~
//  facenm=Pelf->elfLogFont.lfFaceName;                            //~v91fR~
    facenm=Pelf->lfFaceName;                                       //~v91fI~
    found=0;           //not found id
    switch(Sfontid)                                                //~v844R~
    {                                                              //~v844R~
    case 0:     //other tan else                                   //~v844R~
        if (ustrstri(facenm,Sfontnm))                              //~v844R~
            if (*facenm=='@')                                      //~v844I~
                found=4;                                           //~v844I~
            else                                                   //~v844I~
	        	found=1;                                           //~v844R~
        break;                                                     //~v844R~
    case 1:     //MIN                                              //~v844R~
        if (ustrstri(facenm,"MINCHO")                              //~v844R~
        ||  ustrstri(facenm,"–¾’©"))                               //~v844R~
            if (*facenm=='@')                                      //~v844I~
                found=4;                                           //~v844I~
			else                                                   //~v844I~
                if (ustrstri(facenm,"‚o–¾’©"))                     //~v844R~
                    found=3;                                       //~v844R~
                else                                               //~v844R~
                    if (ustrstri(facenm,"MS")                      //~v844R~
                    ||  ustrstri(facenm,"‚l‚r"))                   //~v844R~
                        found=1;                                   //~v844R~
                    else                                           //~v844R~
                        found=2;                                   //~v844R~
        break;                                                     //~v844R~
    case 2:     //GOT                                              //~v844R~
        if (ustrstri(facenm,"GOTHIC")                              //~v844R~
        ||  ustrstri(facenm,"ƒSƒVƒbƒN"))                           //~v844R~
            if (*facenm=='@')                                      //~v844I~
                found=4;                                           //~v844I~
			else                                                   //~v844I~
                if (ustrstri(facenm,"‚oƒSƒVƒbƒN"))                 //~v844R~
                    found=2;                                       //~v844R~
                else                                               //~v844R~
                    found=1;                                       //~v844R~
        break;                                                     //~v844R~
    case 3:     //ROM                                              //~v844R~
        if (ustrstri(facenm,"Roman"))                              //~v844R~
            if (*facenm=='@')                                      //~v844I~
                found=4;                                           //~v844I~
			else                                                   //~v844I~
                if (ustrstri(facenm,"Times"))                      //~v844R~
                    found=1;                                       //~v844R~
                else                                               //~v844R~
                    found=2;        //use if not Times             //~v844R~
        break;                                                     //~v844R~
    case 4:     //COU                                              //~v844R~
        if (ustrstri(facenm,"Courier"))                            //~v844R~
            if (*facenm=='@')                                      //~v844I~
                found=4;                                           //~v844I~
			else                                                   //~v844I~
                if (!ustrstri(facenm,"New"))                       //~v844R~
                    found=1;                                       //~v844R~
                else                                               //~v844R~
                    found=2;        //use if New Courier           //~v844R~
        break;                                                     //~v844R~
    case 5:     //SYS                                              //~v844R~
        if (ustrstri(facenm,"Sys"))                                //~v844R~
            if (*facenm=='@')                                      //~v844I~
                found=4;                                           //~v844I~
			else                                                   //~v844I~
                if (ustrstri(facenm,"Fix"))                        //~v844R~
                    found=1;                                       //~v844R~
                else                                               //~v844R~
                    found=2;    //next candidate                   //~v844R~
        break;                                                     //~v844R~
    }//switch by fontid                                            //~v844R~
//priority	DEVICE-->TRUETYPE-->RASTER                             //~v844I~
//printf("***found=%d,fontid=%d\n",found,Sfontid);                 //~v844R~
	if (Sfontlistsw==1		//list all                             //~v844I~
    ||  (Sfontlistsw==2 && found))	//list matched                 //~v844I~
    {                                                              //~v844I~
        Sfontlistctr++;                                            //~v844I~
    	win_chkelf(Pft,Pelf);                                      //~v844I~
    }                                                              //~v844I~
    else                                                           //~v844R~
        if (found)                                                 //~v844I~
	    {                                                          //~v844R~
    		found--;                                               //~v844R~
//        if (!(Pft & TRUETYPE_FONTTYPE)) //not trutype            //~v844R~
//            found+=(MAXELF*2/3);                                 //~v844R~
//        else                            //true type              //~v844R~
//            if (!(Pft & DEVICE_FONTTYPE))   //not driver font    //~v844R~
//                found+=(MAXELF/3);                               //~v844R~
        	if (!*Self[found].elfLogFont.lfFaceName)               //~v844R~
//  			Self[found]=*Pelf;                                 //~v91fR~
    			memcpy(&Self[found],Pelf,sizeof(LOGFONT));         //~v91fI~
//printf("fonttype=%d=%s,style=%s\n",Pft,Pelf->elfFullName,Pelf->elfStyle);//~v844R~
//printf("selected font=======%s,found=%d,old=%s\n",               //~v844R~
//facenm,found,Self[found].elfLogFont.lfFaceName);                 //~v844R~
		}                                                          //~v844R~
	return 1;
}//effp
//****************************************************************************
//*setup font and open doc
//*parm1:horizontal width of char by unit of 1/720 per inch
//*OR minus (column parm-LINENOSZ-1) from xppf.c when no form and no cpi and with maxcol//~v874I~
//*parm2:vertical  height of char by unit of 1/720 per inch        //~v844R~
//*parm3:docname                                                   //~v844I~
//****************************************************************************
void win_opendoc(int Phmi,int Pvmi,char *Pdocname)                 //~v844R~
{
#ifdef W32UNICODE                                                  //~v990I~
static	DOCINFOW Sdocinfo={sizeof(DOCINFOW)};                      //~v990I~
	UWCH jbnW[_MAX_PATHWC];                                        //~v990R~
#else                                                              //~v990I~
static	DOCINFO	Sdocinfo={sizeof(DOCINFO)};
#endif                                                             //~v990I~
    char *jbn;                                                     //~v869I~
//********************************
    Snpnrsw=0;            //restore at first time                  //~v904I~
	if (Sopendocsw)                                                //~v844I~
    	printf("duplicated doc open req\n");                       //~v844I~
	else                                                           //~v844I~
    {                                                              //~v844I~
//win_chktm();                                                     //~v844R~
//win_chkdc();           //get resolusion                          //~v844R~
		win_createlogfont(Phmi,Pvmi);                              //~v844R~
//win_chktm();                                                     //~v844R~
//win_chkdc();           //get resolusion                          //~v844R~
        win_selectobject();		//set font to DC                   //~v844I~
//win_chktm();                                                     //~v844R~
//win_chkdc();           //get resolusion                          //~v844R~
    //*                                                            //~v844R~
        if (!(jbn=jobname))                                        //~v869I~
            jbn=Pdocname;                                          //~v869I~
//      Sdocinfo.lpszDocName=Pdocname;   //set in xppf openinput   //~v869R~
#ifdef W32UNICODE                                                  //~v990R~
		ufilecvUD2WCnopath(0,jbn,jbnW,sizeof(jbnW),NULL/*ucsctr*/);//~v990R~
        Sdocinfo.lpszDocName=jbnW;   //set in xppf openinput       //~v990R~
        if (StartDocW(Shdc,&Sdocinfo)<=0)	//success              //~v990R~
#else                                                              //~v990I~
        Sdocinfo.lpszDocName=jbn;   //set in xppf openinput        //~v869I~
        if (StartDoc(Shdc,&Sdocinfo)<=0)	//success              //~v844R~
#endif                                                             //~v990I~
		{                                                          //~v844R~
#ifdef W32UNICODE                                                  //~v990R~
            uerrfprintfutf(0,stdout,"\nStartDoc(%s) failed rc=%d\n",0,//~v990R~
                      jbn,GetLastError());                         //~v990I~
#else                                                              //~v990I~
            printf("\nStartDoc(%s) failed rc=%d\n",                //~v844R~
//                    Pdocname,GetLastError());                    //~v869R~
                      jbn,GetLastError());                         //~v869I~
#endif                                                             //~v990I~
			exit(8);                                               //~v844I~
		}                                                          //~v844I~
        Sopendocsw=1;                                              //~v844I~
	}//nit opened                                                  //~v844I~
	if (Gtraceopt)		//trace option by /Yt                      //~v889I~
		printf("start doc\n");                                     //~v889R~
//win_chktm();                                                     //~v844R~
//win_chkdc();           //get resolusion                          //~v844R~
}//win_opendoc
//**********************************************************************//~v844M~
//* close doc                                                      //~v844I~
//**********************************************************************//~v844M~
void win_closedoc(void)                                            //~v844M~
{                                                                  //~v844M~
//********************************                                 //~v844M~
	if (Gtraceopt)		//trace option by /Yt                      //~v889I~
		printf("EndDoc\n");                                        //~v889R~
  	if (UCBITCHK(swsw3,SW3FORM2P))	//form 2p                      //~v914I~
		closedoc2p();	//flushout line on 2p work tbl             //~v914R~
	if (Sopendocsw)                                                //~v844R~
    {                                                              //~v844I~
		win_closepage();                                           //~v844I~
	    if (EndDoc(Shdc)<=0)                                       //~v844R~
        	printf("\nEndDoc failed,rc=%d\n",GetLastError());      //~v844R~
		Sopendocsw=0;                                              //~v844M~
        if (Shfont)                                                //~v862I~
        {                                                          //~v862I~
            if (!DeleteObject(Shfont))                             //~v862I~
                printf("\nDeleteObject for font failed,rc=%d\n",GetLastError());//~v862I~
            Shfont=0;                                              //~v862I~
        }                                                          //~v862I~
	}                                                              //~v844M~
	return;                                                        //~v844M~
}//win_closedoc                                                    //~v844M~
//****************************************************************************
//start new page
//****************************************************************************
void win_newpage(void)                                             //~v844R~
{
    int leftpagesw,newpagesw;                                      //~v904R~
//********************************
    if (Srightpageposx)                                            //~v904R~
    	if (despageno)      //reverse page print                   //~v904I~
        {                                                          //~v904I~
            leftpagesw=((despageno-breakpage)%2==0); //left when residual page is even//~v904R~
            newpagesw=!leftpagesw || (breakpage==1);               //~v904R~
        }                                                          //~v904I~
        else                                                       //~v904I~
            newpagesw=leftpagesw=(breakpage%2!=0);                 //~v904R~
    else                                                           //~v904I~
    	newpagesw=leftpagesw=1;                                    //~v904R~
  if (newpagesw)	//before new page start                        //~v904R~
  {                                                                //~v904I~
	if (Sopenpagesw)                                               //~v844R~
    {
	if (Gtraceopt)		//trace option by /Yt                      //~v889I~
		printf("duplicated page open reques\n");                   //~v889R~
    	win_closepage();                                           //~v844R~
	}
	if (Gtraceopt)		//trace option by /Yt                      //~v889I~
		printf("StartPage\n");                                     //~v889R~
	if (StartPage(Shdc)<=0)                                        //~v844R~
	{
		printf("\nStartPage failed rc=%d\n",GetLastError());       //~v844R~
		uexit(8);                                                  //~v844R~
    }
    win_restoredc();	//need for win95 after new page            //~v904I~
  }                                                                //~v904I~
    Sopenpagesw=1;                                                 //~v844R~
    Sposy=Sposy1st;                                                //~v844R~
//  Sposx=0;                                                       //~v885R~
  if (leftpagesw)                                                  //~v904I~
  {                                                                //~v904I~
//  Sposx=LEFTMARGIN;                                              //~v904R~
    Sposx=Sleftmargin;                                             //~v904I~
//  win_restoredc();	//need for win95 after new page            //~v904R~
  }                                                                //~v904I~
  else                                                             //~v904I~
    Sposx=Srightpageposx;                                          //~v904R~
    return;
}//win_newpage                                                     //~v862R~
//****************************************************************************
//close page
//****************************************************************************
void win_closepage(void)
{
//********************************
	if (!Sopenpagesw)
        return;
    Sopenpagesw=0;                                                 //~v844M~
	if (Gtraceopt)		//trace option by /Yt                      //~v889I~
		printf("EndPage\n");                                       //~v889R~
	if (EndPage(Shdc)<=0)
	{
		printf("\nEndPage failed rc=%d\n",GetLastError());         //~v844R~
       	uexit(8);                                                  //~v844R~
    }
    return;
}//win_closepage
//****************************************************************************
//write line into DC
//parm1:text addr
//parm2:text len
//****************************************************************************
void win_putline(char *Pbuff,unsigned long Plen)
{
    char *ptext,*pc;                                               //~v844R~
    long len;	                                                   //~v844I~
    int  lastcr;                                                   //~v844I~
#ifdef UTF8SUPP                                                    //~v928I~
//  USHORT *pucs,*pucs2;                                           //~v928R~//~v950R~
    WUCS *pucs,*pucs2;                                             //~v950I~
#endif                                                             //~v928I~
//********************************
//  if (*(ptext=Pbuff)==FORMFEED)		//form feed                //~v844R~
    ptext=Pbuff;                                                   //~v844I~
UTRACED("win_putline buff",Pbuff,Plen);                            //~v92fI~
    if (hdr0linesw)		//form feed                                //~v844R~
    {                                                              //~v844I~
        win_newpage();                                             //~v844I~
    	ptext+=1-skip1stff2+esccmdlen;	//if skip 1st ff,already addr is skipped//~v844R~
        len=Plen-1+skip1stff2-esccmdlen;                           //~v844R~
	}                                                              //~v844I~
    else                                                           //~v844I~
    	len=Plen;                                                  //~v844I~
#ifdef UTF8SUPP                                                    //~v928I~
//if (Gxputfstat & GXPUS_UCSLINE)	//data is unicode              //~v928R~//~v955R~
  if (Gxputfstat & (GXPUS_UCSLINE|GXPUS_UCSLINE_EBC))   //data is unicode//~v955R~
  {                                                                //~v928I~
  	if (Gxputfstat & GXPUS_UCSLINE_EBC)   //data is unicode        //~v955I~
    	len/=WUCSSZ;                                               //~v955R~
//	pucs=(USHORT*)(ULONG)ptext;                                    //~v928R~//~v950R~
// 	pucs=(WUCS*)(ULONG)ptext;                                      //~v950I~//~v968R~
  	pucs=(WUCS*)(ULPTR)ptext;                                      //~v968I~
    while(len && *pucs=='\n')                                      //~v928I~
    {                                                              //~v928I~
        pucs++;                                                    //~v928I~
        len--;                                                     //~v928I~
		Sposy+=Slineheight;                                        //~v928I~
    }                                                              //~v928I~
    pucs2=pucs+len-1;                                              //~v928I~
    lastcr=0;                                                      //~v928I~
    while(len && *pucs2=='\n')                                     //~v928I~
    {                                                              //~v928I~
    	len--;                                                     //~v928I~
        lastcr++;                                                  //~v928I~
        pucs2--;                                                   //~v928R~
    }                                                              //~v928I~
UTRACEP("winp TextOutW posy=%d,x=%d,ctr=%d\n",Sposy,Sposx,len);                               //~v92fR~//~v955R~
UTRACED("winp TextOutW",pucs,len*2);                               //~v955I~
	if (!TextOutW(Shdc,Sposx,Sposy,pucs,len))                      //~v928I~
	{                                                              //~v928I~
		printf("\nTextOutW failed rc=%d\n",GetLastError());        //~v928I~
       	uexit(8);                                                  //~v928I~
    }                                                              //~v928I~
  }                                                                //~v928I~
  else                                                             //~v928I~
  {                                                                //~v928I~
#endif                                                             //~v928I~
    while(len && *ptext=='\n')                                     //~v844I~
    {                                                              //~v844I~
        ptext++;                                                   //~v844I~
        len--;                                                     //~v844I~
		Sposy+=Slineheight;                                        //~v844R~
    }                                                              //~v844I~
    pc=ptext+len-1;                                                //~v844I~
    lastcr=0;                                                      //~v844I~
    while(len && *pc=='\n')                                        //~v844I~
    {                                                              //~v844I~
    	len--;                                                     //~v844I~
        lastcr++;                                                  //~v844I~
        pc--;                                                      //~v844I~
    }                                                              //~v844I~
//#ifdef yyy                                                       //~v862R~
//    if (Gtraceopt)      //trace option by /Yt                    //~v90vR~
//        printf("TextOut:pos=(%3d,%4d),len=%3d,data=%.*s==\n",    //~v90vR~
//                Sposx,Sposy,len,len,ptext);                      //~v90vR~
UTRACED("winp textOut",ptext,len);                                 //~v92fI~
	if (!TextOut(Shdc,Sposx,Sposy,ptext,len))                      //~v844R~
	{
		printf("\nTextOut failed rc=%d\n",GetLastError());         //~v844R~
       	uexit(8);                                                  //~v844R~
    }
//#else                                                            //~v862R~
//    if (Escape(Shdc,PASSTHROUGH,len,ptext,NULL)<0)               //~v862R~
//    {                                                            //~v862R~
//        printf("Escape err err=%d\n",GetLastError());            //~v862R~
//    }                                                            //~v862R~
//#endif                                                           //~v862R~
#ifdef UTF8SUPP                                                    //~v928I~
  }                                                                //~v928I~
#endif                                                             //~v928I~
UTRACEP("winp textOut lastcr=%d\n",lastcr);                        //~v92fI~
    while(lastcr)                                                  //~v844I~
    {                                                              //~v844I~
    	lastcr--;                                                  //~v844I~
		Sposy+=Slineheight;                                        //~v844R~
    }                                                              //~v844I~
}//win_putline

//**********************************************************************//~v844I~
//* cleanup at end of job                                          //~v844I~
//parm1:end type 0:normal,4:by esc key,8:err                       //~v844R~
//**********************************************************************//~v844I~
void win_endjob(int Pendsw)                                        //~v844R~
{                                                                  //~v844I~
	static int Sendrequested;                                      //~v844R~
//********************************                                 //~v844I~
	if (Gtraceopt)		//trace option by /Yt                      //~v889I~
		printf("endjob sw=%d\n",Pendsw);                           //~v889R~
	if (Sendrequested)	//loop detection                           //~v844I~
    	return;                                                    //~v844I~
	Sendrequested=1;	//loop detection                           //~v844I~
	Sendjobsw=Pendsw;                                              //~v844I~
	if (!Shdc)                                                     //~v844I~
    	return;                                                    //~v844I~
	win_closepage();                                               //~v844I~
	if (Sopendocsw)                                                //~v844I~
		win_closedoc();                                            //~v844R~
//    if (Shfont)                                                  //~v862R~
//    {                                                            //~v862R~
//        if (!DeleteObject(Shfont))                               //~v862R~
//            printf("\nDeleteObject for font failed,rc=%d\n",GetLastError());//~v862R~
//        Shfont=0;                                                //~v862R~
//    }                                                            //~v862R~
    if (!DeleteDC(Shdc))                                           //~v844I~
        printf("\nDeleteDC failed,rc=%d\n",GetLastError());        //~v844R~
	Shdc=0;                                                        //~v844I~
	return;                                                        //~v844I~
}//win_endjob                                                      //~v844I~
//**********************************************************************//~v92fI~
//* calc maxcol by formtype and char pitch                         //~v92fI~
//**********************************************************************//~v92fI~
int win_getmaxcol(int Pformtype,int Pnonumsw,int Ppitch)           //~v92fI~
{                                                                  //~v92fI~
	int maxc,idx,ww,margin;                                        //~v92fI~
    float fpitch;                                                  //~v92fI~
//********************************                                 //~v92fI~
    if (Ppitch>=15)                                                //~v92fI~
		fpitch=(float)Ppitch*2/10;                                 //~v92fI~
    else                                                           //~v92fI~
		fpitch=(float)Ppitch*2;                                    //~v92fI~
    switch(Pformtype&PFT_FORM)                                     //~v92fI~
    {                                                              //~v92fI~
    case PFT_B4:                                                   //~v92fI~
        idx=1;                                                     //~v92fI~
        break;                                                     //~v92fI~
    case PFT_B5:                                                   //~v92fI~
        idx=2;                                                     //~v92fI~
        break;                                                     //~v92fI~
    default:                                                       //~v92fI~
        idx=0;                                                     //~v92fI~
    }                                                              //~v92fI~
    if (Pformtype & PFT_YOKO)                                      //~v92fI~
        ww=Sformsz[idx][1];	//mm                                   //~v92fI~
    else                                                           //~v92fI~
        ww=Sformsz[idx][0];                                        //~v92fI~
	if (UCBITCHK(swsw3,SW3WIN2P))                                  //~v92fI~
        margin=LEFTMARGIN+LEFTMARGIN2;                             //~v92fI~
    else                                                           //~v92fI~
      	margin=LEFTMARGIN+RIGHTMARGIN;	//by pixcel                //~v92fI~
    maxc=(int)(fpitch*(ww-POINT2MM(margin))*INCHESBYMM);           //~v92fI~
    printf("getmaxcol formtype=%x, Pitch=%d,maxcol=%d,pagew=%d,margin=%d\n",Pformtype,Ppitch,maxc,ww,margin);//~v92fI~
    printf("fmargin=%f,fpitch=%f charwidth=%d\n",POINT2MM(margin),fpitch,(int)((ww-POINT2MM(margin))/maxc));//~v92fI~
    if (!Pnonumsw)                                                 //~v92fI~
    	maxc-=LINENOSZ+1;                                          //~v92fI~
    if (maxc>30)                                                   //~v92fI~
	    maxc=maxc/5*5;                                             //~v92fR~
	return maxc;                                                   //~v92fI~
}//win_getmaxcol                                                   //~v92fI~
//**********************************************************************//~v92fI~
//* calc maxline by formtype and line pitch                        //~v92fI~
//**********************************************************************//~v92fI~
int win_getmaxline(int Pformtype,int Ppitch)                       //~v92fI~
{                                                                  //~v92fI~
	int maxl,idx,hh,margin;                                        //~v92fI~
    float fpitch;                                                  //~v92fI~
//********************************                                 //~v92fI~
    if (Ppitch>=15)                                                //~v92fI~
		fpitch=(float)Ppitch/10;                                   //~v92fI~
    else                                                           //~v92fI~
		fpitch=(float)Ppitch;                                      //~v92fI~
    switch(Pformtype&PFT_FORM)                                     //~v92fI~
    {                                                              //~v92fI~
    case PFT_B4:                                                   //~v92fI~
        idx=1;                                                     //~v92fI~
        break;                                                     //~v92fI~
    case PFT_B5:                                                   //~v92fI~
        idx=2;                                                     //~v92fI~
        break;                                                     //~v92fI~
    default:                                                       //~v92fI~
        idx=0;                                                     //~v92fI~
    }                                                              //~v92fI~
    if (Pformtype & PFT_YOKO)                                      //~v92fI~
        hh=Sformsz[idx][0]; //mm                                   //~v92fI~
    else                                                           //~v92fI~
        hh=Sformsz[idx][1];                                        //~v92fI~
	if (UCBITCHK(swsw3,SW3WIN2P))                                  //~v92fI~
        margin=TOPMARGIN2;                                         //~v92fI~
    else                                                           //~v92fI~
        margin=TOPMARGIN;                                          //~v92fI~
    maxl=(int)(fpitch*(hh-POINT2MM(margin))*INCHESBYMM);           //~v92fI~
    printf("getmaxcol Pitch=%d,maxline=%d,pageh=%d,margin=%d\n",Ppitch,maxl,hh,margin);//~v92fI~
    printf("fmargin=%f,fpitch=%f\n",POINT2MM(margin),fpitch);      //~v92fI~
	return maxl;                                                   //~v92fI~
}//win_getmaxline                                                  //~v92fI~
