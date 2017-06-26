//*CID://+vb2JR~:                             update#=  190;       //+vb2JR~
//***************************************************************************//~2818I~
//* c subrtn for wxe                                               //~2818I~
//***************************************************************************//~2818I~
//vb2J:160313 (W32) compier warning                                //+vb2JI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vafh:120616 for VC10:/W4 warning except C4115,C4214,C4100,C4706,C4244,C4210,C4127,C4245//~vafhI~
//v71A:061030 (WXE)Use HtmlHelp;Winhelp is deprecated at Vista;XP english ersion cannot read .hlp by the readson of codepage unsupported//~v71AI~
#include <time.h>                                                  //~2907I~
#include <stdio.h>                                                 //~2907I~
#include <stdlib.h>                                                //~2907I~
#include <string.h>                                                //~2907I~
//*************************************************************    //~2907I~
#include <windows.h>                                               //~2818R~
#include <htmlhelp.h> //by help tool                               //~v71AR~
                                                                   //~2907I~
#include "ulib.h"                                                  //~2907I~
#include "ualloc.h"                                                //~2907R~
#include "uque.h"                                                  //~2929I~
#include "uerr.h"                                                  //~2907I~
#include "utrace.h"                                                //~2914I~
#include "ufile.h"                                                 //~2922I~
#include "ufile2.h"                                                //~2923I~
#include "ufile4.h"                                                //~2923I~
                                                                   //~2818I~
#include "xe.h"                                                    //~2929I~
                                                                   //~2929I~
#include "wxedef.h"                                                //~2923I~
#include "wxemain.h"                                               //~2901I~
#include "wxecsub.h"                                               //~2831I~
#include "wxexei.h"                                                //~2907I~
//***************************************************************************//~2818I~
//***************************************************************************//~2831I~
//***************************************************************************//~2907I~
//***************************************************************************//~2831I~
int ugetdriverinfo(char *Ptype,char *Pdriver,char *Pport);         //~2B24R~
DEVMODE *usetprintersub(char *Pdriver,char *Ppdevicename,char *Pport,int Pformtype,int Plandscape);//~2B24I~
DEVMODE *ugetsetdm(HANDLE Phprinter,char *Ppdevicename,DEVMODE *Ppdm);//~2B24I~
//***************************************************************************//~2831I~
                                                                   //~2B24I~
//**********************************************************************//~2B24I~
//* setup FONT object                                              //~2B24I~
//parm:fontname or NULL if no parm specified                       //~2B24I~
//**********************************************************************//~2B24I~
DEVMODE *usetupprinter(int Pformid,int Plandscape)                 //~2B24R~
{                                                                  //~2B24I~
    char    prntype[128];                                          //~2B24I~
	char    prndriver[128];                                        //~2B24I~
	char    prnport[32];                                           //~2B24I~
    DEVMODE *pdm=0;                                                //~2B24I~
//********************************                                 //~2B24I~
    if (!ugetdriverinfo(prntype,prndriver,prnport))                //~2B24R~
		pdm=usetprintersub(prndriver,prntype,prnport,Pformid,Plandscape);//~2B24R~
    return pdm;                                                    //~2B24R~
}//usetupprinter                                                   //~2B24I~
//***************************************************************************//~2B24I~
//*get driver info using GetProfileString                          //~2B24I~
//parm1:output printer type                                        //~2B24I~
//parm2:output drivername                                          //~2B24I~
//parm3:output port name                                           //~2B24I~
//ret :none                                                        //~2B24I~
//**************************************************************************//~2B24I~
int ugetdriverinfo(char *Ptype,char *Pdriver,char *Pport)          //~2B24R~
{                                                                  //~2B24I~
    char    buff[512];                                             //~2B24I~
    char    *pc,*prntype,*prndriver,*prnport;;                     //~2B24I~
//********************************                                 //~2B24I~
                                                                   //~2B24I~
    if (!GetProfileString("windows", "device", (LPSTR)NULL, buff,sizeof(buff)))//~2B24I~
		return uerrlast("GetrofileString");                        //~2B24I~
    pc=prntype=buff;                                               //~2B24I~
    prndriver=prnport=0;                                           //~2B24I~
    while (*pc)                                                    //~2B24I~
	{                                                              //~2B24I~
		if (*pc==',')                                              //~2B24I~
		{                                                          //~2B24I~
	    	*pc++=0;                                               //~2B24I~
	    	while (*pc==' ')                                       //~2B24I~
				pc++;                                              //~2B24I~
	    	if (!prndriver)                	//first time           //~2B24I~
				prndriver=pc;                                      //~2B24I~
	    	else                                                   //~2B24I~
			{                                                      //~2B24I~
				prnport=pc;                                        //~2B24I~
				break;                                             //~2B24I~
	    	}                                                      //~2B24I~
		}                                                          //~2B24I~
		else                                                       //~2B24I~
			pc++;                                                  //~2B24I~
    }                                                              //~2B24I~
    if (!prndriver)                                                //~2B24I~
        prndriver="";                                              //~2B24I~
    if (!prnport)                                                  //~2B24I~
        prnport="";                                                //~2B24I~
    strcpy(Ptype,prntype);                                         //~2B24I~
	if (prndriver)                                                 //~2B24I~
    	strcpy(Pdriver,prndriver);                                 //~2B24I~
    else                                                           //~2B24I~
    	*Pdriver=0;                                                //~2B24I~
    if (prnport)                                                   //~2B24I~
	    strcpy(Pport,prnport);                                     //~2B24I~
    else                                                           //~2B24I~
    	*Pport=0;                                                  //~2B24I~
	return 0;                                                      //~2B24R~
}//ugetdriverinfo                                                  //~2B24I~
//***************************************************************************//~2B24I~
//*change printer form/orientation                                 //~2B24I~
//**************************************************************************//~2B24I~
DEVMODE *usetprintersub(char *Pdriver,char *Ppdevicename,char *Pport,int Pformtype,int Plandscape)//~2B24R~
{                                                                  //~2B24I~
    HANDLE hprinter;                                               //~2B24M~
	DEVMODE *pdm,*pdm2=0,*pdm0=0;                                  //~3105R~
    PRINTER_DEFAULTS pd;                                           //~3113R~
    int ori;                                                       //~3105I~
//  int buffsz=0;                                                  //~3105R~//~vafhR~
//    PRINTER_INFO_2 *ppi2;                                        //~3113R~
//********************************                                 //~2B24I~
    if (Plandscape)                                                //~3105M~
    	ori=DMORIENT_LANDSCAPE;                                    //~3105I~
    else                                                           //~3105M~
    	ori=DMORIENT_PORTRAIT;                                     //~3105I~
   /* プリンタのハンドルをオープン                                 //~3105I~
   (Windows NT の場合、SetPrinter にはすべての権限 (ALL_ACCESS) が必要になります)//~3105I~
   */                                                              //~3105I~
    memset(&pd,0,sizeof(pd));                                      //~3113R~
    pd.DesiredAccess = PRINTER_ALL_ACCESS;                         //~3113R~
UTRACEP("OpenPrinter %s\n",Ppdevicename);                          //~3113R~
    if (!OpenPrinter(Ppdevicename,&hprinter,&pd))                  //~3113R~
    {                                                              //~3113R~
        uerrmsgbox("OpenPrinter(%s) failed,rc=%d",Ppdevicename,GetLastError());//~3113R~
        return 0;                                                  //~3113R~
    }                                                              //~3113R~
//    GetPrinter(hprinter,2,0,0,&buffsz);//2:ifolevel,0:buff addr,0:buffsz//~3113R~
//    if (!buffsz)                                                 //~3113R~
//    {                                                            //~3113R~
//        uerrlast("GetPrinter-1");                                //~3113R~
//        return 0;                                                //~3113R~
//    }                                                            //~3113R~
//    ppi2=(PRINTER_INFO_2*)umemalloc(buffsz);                     //~3113R~
//    if (!GetPrinter(hprinter,2,(LPBYTE)ppi2,buffsz,&buffsz))     //~3113R~
//    {                                                            //~3113R~
//        uerrlast("GetPrinter-2");                                //~3113R~
//        return 0;                                                //~3113R~
//    }                                                            //~3113R~
//    pdm=ppi2->pDevMode;                                          //~3113R~
//    if (pdm)                                                     //~3113R~
//UTRACEP("GetPrinter prev ori=%d=%d paper=%d=%d\n", ppi2->pDevMode->dmFields&DM_ORIENTATION,//~3113R~
//                    ppi2->pDevMode->dmOrientation,               //~3113R~
//                    ppi2->pDevMode->dmFields&DM_PAPERSIZE,       //~3113R~
//                    ppi2->pDevMode->dmPaperSize);                //~3113R~
//    if (!pdm)   //no gotten                                      //~3113R~
//    {                                                            //~3113R~
    	pdm0=ugetsetdm(hprinter,Ppdevicename,0);	//get current dm//~3105R~
    	if (!pdm0)                                                 //~3105R~
    	{                                                          //~3105R~
//        	umemfree(ppi2);                                        //~3113R~
    		return 0;                                              //~3105R~
    	}                                                          //~3105R~
//      ppi2->pDevMode=pdm=pdm0;                                   //~3113R~
		pdm=pdm0;                                                  //~3113I~
//    }                                                            //~3113R~
    if (pdm->dmFields & DM_ORIENTATION)    //supported             //~3113I~
    	if (ori!=pdm->dmOrientation)                               //~3113I~
//      	pdm->dmOrientation=ori;                                //~3113I~//+vb2JR~
        	pdm->dmOrientation=(short)ori;                         //+vb2JI~
        else                                                       //~3113I~
	    	pdm->dmFields&=~DM_ORIENTATION;    //supported         //~3113I~
        	                                                       //~3113I~
    if (pdm->dmFields & DM_PAPERSIZE)    //supported               //~3113I~
        if (Pformtype!=pdm->dmPaperSize)                           //~3113I~
//          pdm->dmPaperSize=Pformtype;                            //~3113I~//+vb2JR~
            pdm->dmPaperSize=(short)Pformtype;                     //+vb2JI~
        else                                                       //~3113I~
			pdm->dmFields&=~DM_PAPERSIZE;    //supported           //~3113R~
    if (pdm->dmFields & (DM_ORIENTATION|DM_PAPERSIZE))    //chng requied//~3113I~
    {                                                              //~3113I~
	    pdm->dmFields&=(DM_ORIENTATION|DM_PAPERSIZE);              //~3113I~
UTRACEP("Setdoc req ori=%d==%d paper=%d==%d\n",                    //~3105R~
					pdm->dmFields&DM_ORIENTATION,                  //~3105I~
    				pdm->dmOrientation,                            //~3105I~
	    			pdm->dmFields&DM_PAPERSIZE,                    //~3105I~
    				pdm->dmPaperSize);                             //~3105R~
    	pdm2=ugetsetdm(hprinter,Ppdevicename,pdm);	//set and get new dm//~3105R~
//        if (!SetPrinter(hprinter,2,(LPBYTE)ppi2,0))              //~3113R~
//      	    uerrlast("SetPrinter");                            //~3113R~
    }//status changed                                              //~3105I~
//    umemfree(ppi2);                                              //~3113R~
	if (!ClosePrinter(hprinter))                                   //~2B24R~
		uerrlast("ClosePrinter");                                  //~2B24R~
    if (pdm0)                                                      //~3105I~
	    umemfree(pdm0);                                            //~3105R~
    if (pdm2)                                                      //~2B24I~
    	umemfree(pdm2);                                            //~2B24I~
    return 0;                                                      //~2B24I~
}//usetprintersub                                                  //~2B24I~
//***************************************************************************//~2B24I~
//*get current devmode                                             //~2B24I~
//ret  :devmode struc                                              //~2B24I~
//**************************************************************************//~2B24I~
DEVMODE *ugetsetdm(HANDLE Phprinter,char *Ppdevicename,DEVMODE *Ppdm)//~2B24I~
{                                                                  //~2B24I~
    DEVMODE   *pdmout,*pdmin;                                      //~3113R~
    LPDEVMODE gpdmout,gpdmin;                                      //~3113I~
    int mode,rc,len;                                               //~3113R~
    HANDLE mho,mhi;                                                //~3113I~
//*****************                                                //~2B24I~
    mode=0; //get size                                             //~2B24I~
    rc=DocumentProperties(HWND_TOP,Phprinter,Ppdevicename,NULL,NULL,mode);//~3113R~
    if (rc<=0)                                                     //~2B24I~
    {                                                              //~2B24I~
        uerrmsgbox("DocumentProperties(get size) failed,rc=%d",Ppdevicename,GetLastError());//~2B24R~
        return 0;                                                  //~2B24I~
    }                                                              //~2B24I~
    len=rc;                                                        //~3113I~
    pdmout=umemalloc(len);                                         //~3113R~
    if (!Ppdm)	//get                                              //~2B24I~
    {                                                              //~2B24I~
	    mho=GlobalAlloc(GHND,len);                                 //~3113I~
		gpdmout=(LPDEVMODE)GlobalLock(mho);                        //~3113I~
        mode=DM_OUT_BUFFER; //get current setting                  //~2B24I~
        rc=DocumentProperties(HWND_TOP,Phprinter,Ppdevicename,gpdmout,NULL,mode);//~3113R~
        memcpy(pdmout,gpdmout,(UINT)len);                          //~3113I~
		GlobalFree(mho);                                           //~3113R~
        if (!rc)                                                   //~2B24I~
        {                                                          //~2B24I~
	        uerrmsgbox("DocumentProperties(get devmode) failed,rc=%d",Ppdevicename,GetLastError());//~2B24R~
	        return 0;                                              //~2B24I~
        }                                                          //~2B24I~
UTRACEP("GetDocumentProperties ori=%d=%d paper=%d=%d\n",           //~3105R~
					pdmout->dmFields&DM_ORIENTATION,               //~3105I~
    				pdmout->dmOrientation,                         //~3105I~
	    			pdmout->dmFields&DM_PAPERSIZE,                 //~3105I~
    				pdmout->dmPaperSize);                          //~3105R~
    }//get                                                         //~2B24I~
    else                                                           //~2B24I~
    {                                                              //~2B24I~
	    mho=GlobalAlloc(GHND,len);                                 //~3113I~
		gpdmout=(LPDEVMODE)GlobalLock(mho);                        //~3113I~
	    mhi=GlobalAlloc(GHND,len);                                 //~3113I~
		gpdmin=(LPDEVMODE)GlobalLock(mhi);                         //~3113I~
        pdmin=Ppdm;                                                //~3113I~
        memcpy(gpdmin,pdmin,(UINT)len);                            //~3113R~
        mode=DM_IN_BUFFER|DM_OUT_BUFFER; //get current setting     //~2B24I~
        rc=DocumentProperties(HWND_TOP,Phprinter,Ppdevicename,gpdmout,gpdmin,mode);//~3113R~
        memcpy(pdmout,gpdmout,(UINT)len);                          //~3113I~
		GlobalFree(mho);                                           //~3113R~
		GlobalFree(mhi);                                           //~3113R~
        if (!rc)                                                   //~2B24I~
        {                                                          //~2B24I~
	        uerrmsgbox("DocumentProperties(set devmode) failed,rc=%d",Ppdevicename,GetLastError());//~2B24R~
	        return 0;                                              //~2B24I~
        }                                                          //~2B24I~
UTRACEP("SetDocumentProperties-in ori=%d=%d paper=%d=%d\n",        //~3105R~
					pdmin->dmFields&DM_ORIENTATION,                //~3105I~
    				pdmin->dmOrientation,                          //~3105I~
	    			pdmin->dmFields&DM_PAPERSIZE,                  //~3105I~
    				pdmin->dmPaperSize);                           //~3105R~
UTRACEP("SetDocumentProperties-out ori=%d=%d paper=%d=%d\n",       //~3105R~
					pdmout->dmFields&DM_ORIENTATION,               //~3105I~
    				pdmout->dmOrientation,                         //~3105I~
	    			pdmout->dmFields&DM_PAPERSIZE,                 //~3105I~
    				pdmout->dmPaperSize);                          //~3105R~
    }                                                              //~2B24I~
    return pdmout;                                                 //~2B24I~
}//ugetsetdm                                                       //~2B24I~
//***************************************************************************//~v71AI~
//*get current devmode                                             //~v71AI~
//ret  :devmode struc                                              //~v71AI~
//**************************************************************************//~v71AI~
int uhtmlhelp(int Popt,HWND Pwnd,char *Ppopuptext,POINT Ppoint)    //~v71AR~
{                                                                  //~v71AI~
    HH_POPUP popup;                                                //~v71AI~
    RECT     popuprcm={-1,-1,-1,-1};     //default                 //~v71AM~
//*****************                                                //~v71AI~
	memset(&popup,0,sizeof(popup));                                //~v71AR~
    popup.cbStruct=sizeof(popup);                                  //~v71AI~
    popup.hinst=0;               //handle to get by idString       //~v71AI~
    popup.idString=0;            //string resource id              //~v71AI~
    popup.pszText=Ppopuptext;   //direct text string               //~v71AI~
    popup.pt=Ppoint;              //popup window top center by parameter(Mouse click screen coordinate)//~v71AI~
//  popup.clrForeground=-1;      //FG color  -1:system color of window//~v71AI~//~vafhR~
//  popup.clrBackground=-1;      //BG color                        //~v71AI~//~vafhR~
    popup.clrForeground=(UINT)-1;      //FG color  -1:system color of window//~vafhI~
    popup.clrBackground=(UINT)-1;      //BG color                  //~vafhI~
    popup.rcMargins=popuprcm;    //margin of each rect             //~v71AI~
    if (Popt & 0x01)	//dbcs                                     //~v71AI~
//      popup.pszFont="ＭＳ ゴシック,10, ,BOLD"; //font            //~v71AR~
        popup.pszFont="ＭＳ ゴシック,10"; //font                   //~v71AI~
    else                                                           //~v71AI~
//      popup.pszFont="MS Sans Sherif,10, ,BOLD"; //font           //~v71AR~
        popup.pszFont="MS Sans Sherif,10"; //font                  //~v71AI~
    HtmlHelp(0,//pWnd->GetSafeHwnd(),                              //~v71AI~
                NULL,                                              //~v71AI~
                HH_DISPLAY_TEXT_POPUP,                             //~v71AI~
//              (DWORD)&popup);                                    //~v71AI~//~vafkR~
                (ULPTR)&popup);                                    //~vafkR~
    return 0;                                                      //~v71AI~
}//uhtmlhelp                                                       //~v71AI~
