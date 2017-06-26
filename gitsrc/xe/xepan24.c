//*CID://+vb2DR~:                                    update#=   69;//+vb2DR~
//*************************************************************
//*xepan24.c                                                       //~v76mR~
//*   filename list find process                                   //~v76mR~
//*************************************************************
//vb2D:160221 LNX compiler warning                                 //+vb2DI~
//vavw:140428 (BUG)find cmd fail on filename list for srch not ascii(ddsrch required)//~vavwI~
//vavv:140428 (BUG)find cmd on filename list for newly created line//~vavvI~
//vavu:140428 (BUG)0c4 by rfind on filename list panel.rc=0 but Sfindplh=0 because of async schedule//~vavuI~
//vavp:140426 (vaub for Win)maintain ddfmt for pan fnmlist and util panel//~vavpI~
//vaub:140306 maintain ddfmt for pan fnmlist and util panel        //~vaubI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//va0t:090913!maintains locale and utf8 code for panel input(cmdline,panutil)//~va0tI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          find by locale code                                    //~va00I~
//          filename list is mixed of utf8 and locale code         //~va00I~
//          files encoded by utf8                                  //~va00I~
//v76m:070627 find support on =1/=2 filename list panel            //~7627I~
//*************************************************************
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <uque.h>
#include <ualloc.h>
#include <ufile.h>
#include <ufile4.h>                                                //~v76mI~
#include <ustring.h>                                               //~v61cI~
#include <utrace.h>

#include "xe.h"
#include "xescr.h"
#include "xecsr.h"
#include "xefunc.h"
#include "xefile.h"
#include "xefile13.h"                                              //~v76mI~
#include "xefile2.h"                                               //~v76mI~
#include "xepan.h"
#include "xepan2.h"                                                //~v76mR~
#include "xepan22.h"                                               //~v76mI~
#include "xesub.h"
#include "xefcmd2.h"                                               //~v76mI~
#include "xefcmd23.h"                                              //~v76mI~
#ifdef UTF8SUPPH                                                   //~va00I~
	#include "xeutf.h"                                             //~va00I~
	#include "xechar.h"                                            //~va0tI~
#endif                                                             //~va00I~
//****************************************************************
#define FNLTEMPFNM "xefnltmp"                                      //~v76mI~
//**************************************************************** //~v76mI~
static PUCLIENTWE Spcwfnl=0;                                       //~v76mR~
static PUFILEH    Spfhfnl=0;                                       //~v76mR~
static UQUEH     *Spfnstack=0;                                     //~v76mR~
//*******************************************************          //~v76mI~
int panfnlsetupplh(PUFILEH Ppfh,UQUEH *Ppqh);                      //~v76mI~
//int panfnlalloclh(char *Pdata,int Plen,PULINEH *Ppplh);          //~vaubR~
int panfnlalloclh(PUP300LIST Ppsc,char *Pdata,int Plen,PULINEH *Ppplh);//~vaubR~
//*******************************************************          //~v76mI~
//!panfnlsetuppfh                                                  //~v76mI~
//* setup pfh for find in filename list                            //~v76mI~
//* retrn:pfh                                                      //~v76mI~
//*******************************************************          //~v76mI~
int panfnlsetuppfh(PUCLIENTWE Ppcw,UQUEH *Ppqh)                    //~v76mI~
{                                                                  //~v76mI~
 	PUCLIENTWE pcw;                                                //~v76mI~
    UCHAR  fnm[_MAX_PATH];                                         //~v76mR~
    int rc;                                                        //~v76mI~
//*******************                                              //~v76mI~
	if (Spcwfnl)                                                   //~v76mI~
    	return 0;                                                  //~v76mI~
    Spfnstack=Ppqh;                                                //~v76mI~
    utempnam(0,FNLTEMPFNM,fnm);                                    //~v76mI~
    Ppcw->UCWparm=fnm;                                             //~v76mI~
    rc=func_edit_file2(Ppcw,FEBFIO_TEMP2); //0:no parm             //~v76mR~
    Ppcw->UCWparm=0;        //worked                               //~v76mI~
    if (rc)                                                        //~v76mI~
        return rc;                                                 //~v76mI~
	pcw=scrdeqcw(Gscrcurclient,0,0);	//deq and not free(top entry)//~v76mI~
    Spcwfnl=pcw;          //save cb edit pcw                       //~v76mI~
    Spfhfnl=((PUFILEC)pcw->UCWpfc)->UFCpfh;                        //~v76mR~
#ifdef UTF8SUPPH                                                   //~v90pI~//~va00I~
//  if (XEUTF8MODE())                                              //~v90pI~//~va00I~
#if defined(LNX) || defined(W32UNICODE)  //plhdata is from U3Ldddata//~vavwI~
#else                                                              //~vavwI~
    if (XEUTF8MODE_ENV_FORCE())                                              //~v90pI~//~va00I~
#endif                                                             //~vavwI~
    	UCBITON(Spfhfnl->UFHflag8,UFHF8UTF8);                      //~v90pI~//~va00I~
#endif                                                             //~v90pI~//~va00I~
	panfnlsetupplh(Spfhfnl,Ppqh);                                  //~v76mI~
	return 0;                                                      //~v76mR~
}//panfnlsetuppfh                                                  //~v76mI~
//*******************************************************          //~v76mI~
//!free dummy pcw/pfh                                              //~v76mI~
//*******************************************************          //~v76mI~
int panfnlfreepfh(void)                                            //~v76mI~
{                                                                  //~v76mI~
 	PUCLIENTWE pcw;                                                //~v76mI~
//*******************                                              //~v76mI~
	pcw=Spcwfnl;                                                   //~v76mI~
	if (!pcw)                                                      //~v76mR~
    	return 0;                                                  //~v76mI~
    screnqcw(Gscrcurclient,pcw,UQUE_TOP,0);                        //~v76mR~
    filefree(Spfhfnl);                                             //~v76mI~
    filefreepfh(Spfhfnl);                                          //~v76mI~
    filepopup(pcw);                                                //~v76mR~
	Spcwfnl=0;                                                     //~v76mI~
	return 0;                                                      //~v76mR~
}//panfnlfreepfh                                                   //~v76mI~
//*******************************************************          //~v76mI~
//!panfnlsetuppfh                                                  //~v76mI~
//* setup plh for each stack element                               //~v76mI~
//* retrn:pfh                                                      //~v76mI~
//*******************************************************          //~v76mI~
int panfnlsetupplh(PUFILEH Ppfh,UQUEH *Ppqh)                       //~v76mI~
{                                                                  //~v76mI~
    PUP300LIST psc;                                                //~v76mI~
    PULINEH plh,plhprev;                                           //~v76mI~
    int rc,len;                                                    //~v76mR~
    LONG lineno;                                                   //~v76mI~
    char *pdata;                                                   //~v76mR~
//*******************                                              //~v76mI~
	psc=(PUP300LIST)UGETQTOP(Ppqh);                                //~v76mI~
    plhprev=UGETQTOP(&Ppfh->UFHlineque);                           //~v76mR~
    lineno=plhprev->ULHlinenor;                                    //~v76mI~
	for (;psc;psc=UGETQNEXT(psc))                                  //~v76mI~
    {                                                              //~v76mI~
#ifdef UTF8SUPPH                                                   //~va00R~
		if (!(psc->U3Lflag & U3LFUTF8CHKED))	//not locale code gotten//~va00I~
			pan300editcmdf2l(0,psc);                               //~va00I~
		len=U3L_GETLOCALEDATA_LEN(psc,&pdata);                     //~va00R~
#else                                                              //~va00R~
        pdata=psc->U3Lfnm;                                         //~v76mI~
        len=psc->U3Lnetfnmlen;                                     //~v76mI~
#endif                                                             //~va00R~
//  	if (rc=panfnlalloclh(pdata,len,&plh),rc)                   //~vaubR~
    	if (rc=panfnlalloclh(psc,pdata,len,&plh),rc)               //~vaubR~
        	return rc;                                             //~v76mI~
        plh->ULHlinenor=++lineno;                                  //~v76mI~
		UENQENT(UQUE_AFT,plhprev,plh);	                           //~v76mI~
        psc->U3Lplh=plh;                                           //~v76mI~
		plhprev=plh;                                               //~v76mI~
	}//loop by repeat count                                        //~v76mI~
	return 0;                                                      //~v76mI~
}//panfnlsetupplh                                                  //~v76mI~
//*******************************************************          //~v76mI~
//!panfnlalloclh                                                   //~v76mI~
//* allocate plh                                                   //~v76mI~
//* retrn:rc                                                       //~v76mI~
//*******************************************************          //~v76mI~
//int panfnlalloclh(char *Pdata,int Plen,PULINEH *Ppplh)           //~vaubR~
int panfnlalloclh(PUP300LIST Ppsc,char *Pdata,int Plen,PULINEH *Ppplh)//~vaubR~
{                                                                  //~v76mI~
    PULINEH plh;                                                   //~v76mI~
//#ifdef LNX                                                         //~vaubR~//~vavpR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaI~//~vavpI~
	int ddlen;                                                     //~vaubR~
#endif                                                             //~vaubR~
//*******************                                              //~v76mI~
//#ifdef LNX                                                         //~vaubR~//~vavpR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavpI~
    ddlen=Ppsc->U3Lddlen;                                          //~vaubR~
	plh=filealloclh(ULHTDATA,ddlen);                               //~vaubR~
    UALLOCCHK(plh,UALLOC_FAILED);                                  //~vaubR~
//  memcpy(plh->ULHdata,Ppsc->U3Ldddata,ddlen);                    //~vaubR~//+vb2DR~
    memcpy(plh->ULHdata,Ppsc->U3Ldddata,(size_t)ddlen);            //+vb2DI~
	plh->ULHdbcs=UALLOCC(1,(UINT)plh->ULHbufflen);                 //~vaubR~
	UALLOCCHK(plh->ULHdbcs,UALLOC_FAILED);   //return 0 if storage shortage//~vaubR~
//  memcpy(plh->ULHdbcs,Ppsc->U3Ldddbcs,ddlen);                    //~vaubR~//+vb2DR~
    memcpy(plh->ULHdbcs,Ppsc->U3Ldddbcs,(size_t)ddlen);            //+vb2DI~
    UTRACED("dddata",plh->ULHdata,ddlen);                          //~vaubI~
    UTRACED("dddbcs",plh->ULHdbcs,ddlen);                          //~vaubI~
#else                                                              //~vaubR~
	plh=filealloclh(ULHTDATA,Plen);                                //~v76mI~
    UALLOCCHK(plh,UALLOC_FAILED);                                  //~v76mI~
    memcpy(plh->ULHdata,Pdata,(UINT)Plen);                         //~v76mR~
	plh->ULHdbcs=UALLOCC(1,(UINT)plh->ULHbufflen);                 //~v76mI~
	UALLOCCHK(plh->ULHdbcs,UALLOC_FAILED);   //return 0 if storage shortage//~v76mI~
    filesetdbcstbl(plh->ULHdata,plh->ULHdbcs,Plen,0);//no chk tab  //~v76mI~
#endif                                                             //~vaubI~
    *Ppplh=plh;                                                    //~v76mI~
    return 0;                                                      //~v76mI~
}//panfnlalloclh                                                   //~v76mI~
//*******************************************************          //~v76mI~
//!panfnlupdatepfh                                                 //~v76mI~
//* maintenace pfh for find in filename list                       //~v76mI~
//* retrn:pfh                                                      //~v76mI~
//*******************************************************          //~v76mI~
int panfnlupdatepfh(int Popt,PUP300LIST Ppsc)                      //~v76mR~
{                                                                  //~v76mI~
    UQUEH   *plhq;                                                 //~v76mI~
 	PULINEH  plh,plh0,plh1;                                        //~v76mR~
    char *pdata;                                                   //~v76mI~
    int rc,len;                                                    //~v76mR~
    LONG lineno;                                                   //~v76mI~
//*******************                                              //~v76mI~
	if (!Spcwfnl)	//not yet setup(addentry at ini process)       //~v76mR~
    	return 0;                                                  //~v76mI~
    plhq=&Spfhfnl->UFHlineque;    	//plhq                         //~v76mR~
    plh0=UGETQTOP(plhq);                                           //~v76mI~
	plh1=UGETQNEXT(plh0);	//top entry                            //~v76mR~
    plh=Ppsc->U3Lplh;                                              //~v76mI~
    if (Popt & PANFIND_ENQ)     //new or reenq                     //~v76mR~
    {                                                              //~v76mI~
        if (plh)	//re-enq                                       //~v76mI~
        {                                                          //~v76mI~
            if (plh!=plh1)  //not same                             //~v76mR~
				UDEQ(UQUE_ENT,plhq,plh);	//deq to re-enq        //~v76mR~
        }                                                          //~v76mI~
        else                                                       //~v76mI~
        {                                                          //~v76mI~
#ifdef UTF8SUPPH                                                   //~va00R~
			if (!(Ppsc->U3Lflag & U3LFUTF8CHKED))	//not locale code gotten//~va00R~
				pan300editcmdf2l(0,Ppsc);                          //~va00R~
			len=U3L_GETLOCALEDATA_LEN(Ppsc,&pdata);                //~va00R~
#else                                                              //~va00R~
        	pdata=Ppsc->U3Lfnm;                                    //~v76mI~
        	len=Ppsc->U3Lnetfnmlen;                                //~v76mI~
#endif                                                             //~va00R~
//  		if (rc=panfnlalloclh(pdata,len,&plh),rc)               //~vaubR~
    		if (rc=panfnlalloclh(Ppsc,pdata,len,&plh),rc)          //~vaubR~
        		return rc;                                         //~v76mI~
        	Ppsc->U3Lplh=plh;	//for find cmd                     //~vavvR~
        }                                                          //~v76mI~
        if (plh!=plh1)                                             //~v76mR~
        {                                                          //~v76mI~
	        UENQENT(UQUE_AFT,plh0,plh); //re-enq after ttop header plh//~v76mI~
            lineno=plh0->ULHlinenor;	//renum                    //~v76mR~
            for (plh=UGETQNEXT(plh0);plh;plh=UGETQNEXT(plh))   //initialy setup max count//~v76mR~
                plh->ULHlinenor=++lineno;                          //~v76mI~
        }                                                          //~v76mI~
    }                                                              //~v76mI~
    else	//DEQ                                                  //~v76mI~
    {                                                              //~v76mI~
        if (plh)	//re-enq                                       //~v76mI~
        {                                                          //~v76mI~
			UDEQ(UQUE_ENT,plhq,plh);	//deq to re-enq            //~v76mR~
        	filefreeplh(plh,1);			//1:free plh               //~v76mR~
        }                                                          //~v76mI~
    }                                                              //~v76mI~
    return 0;                                                      //~v76mI~
}//panfnlupdatepfh                                                 //~v76mI~
//*******************************************************          //~v76mI~
//!panfnlfind                                                      //~v76mI~
//*opt icase/rfind/rev                                             //~v76mI~
//*******************************************************          //~v76mI~
int panfnlfind(int Popt,PUCLIENTWE Ppcw)                           //~v76mI~
{                                                                  //~v76mI~
    int rc,line,startline,ii,linetop,cwheight;                     //~v76mR~
    PULINEH plh,plhtop;                                            //~v76mR~
    PUFILEC pfc;                                                   //~v76mI~
	PUCLIENTWE pcw;                                                //~v76mR~
	PUP300LIST psc;                                                //~v76mI~
//*******************                                              //~v76mI~
	pcw=Spcwfnl;	//not yet setup(addentry at ini process)       //~v76mI~
	if (!pcw)	//not yet setup(addentry at ini process)           //~v76mR~
    	return 0;                                                  //~v76mI~
//setup fcmd2 env                                                  //~v76mI~
    pfc=pcw->UCWpfc;                                               //~v76mI~
	startline=Ppcw->UCWtopfnlist;                                  //~v76mI~
    for (ii=0,psc=UGETQTOP(Spfnstack);ii<startline && psc;ii++)//all entry//~v76mI~
    	psc=UGETQNEXT(psc);		//skip prev page                   //~v76mI~
    if (!psc)                                                      //~v76mI~
    	return 4;                                                  //~v76mI~
    pfc->UFCcurtop=psc->U3Lplh;                                    //~v76mI~
    cwheight=Ppcw->UCWheight;                                      //~v76mR~
    Ppcw->UCWheight=Ppcw->UCWheight-PANL300LISTTOP+pcw->UCWfilehdrlineno;//~v76mI~
    Ppcw->UCWpfc=pcw->UCWpfc;                                      //~v76mI~
    Gpanfindopt|=PANFO_FNL; //filename list search                 //~v76mI~
//*                                                                //~v76mM~
    if (Popt & PANFIND_ICASE)                                      //~v76mI~
        rc=func_ifind_file(Ppcw);                                  //~v76mR~
    else                                                           //~v76mI~
    if (Popt & PANFIND_REV)                                        //~v76mM~
        rc=func_revrfind_file(Ppcw);                               //~v76mM~
    else                                                           //~v76mM~
    if (Popt & PANFIND_RFIND)                                      //~v76mI~
        rc=func_rfind_file(Ppcw);                                  //~v76mR~
    else                                                           //~v76mI~
        rc=func_find_file(Ppcw);                                   //~v76mR~
//*                                                                //~v76mI~
    Gpanfindopt&=~PANFO_FNL; //reset filename list search          //~v76mI~
    Ppcw->UCWpfc=0;                                                //~v76mI~
    Ppcw->UCWheight=cwheight;                                      //~v76mI~
//*                                                                //~v76mI~
    if (rc)                                                        //~v76mI~
    	return rc;                                                 //~v76mI~
    if (!Sfoundplh)  //rc=0 may occur when F5 with searchword on cmdline//~vavuI~
    	return rc;                                                 //~vavuI~
//scroll                                                           //~v76mI~
    plhtop=pfc->UFCcurtop;                                         //~v76mI~
    linetop=(int)plhtop->ULHlinenor-1;                             //~v76mI~
    plh=Sfoundplh;                                                 //~v76mR~
    line=(int)plh->ULHlinenor-1;                                   //~v76mR~
    pan300locatepage(Ppcw,linetop,line);                           //~v76mR~
	return 0;                                                      //~v76mR~
}//panfnlfind                                                      //~v76mI~
//**************************************************************** //~v76mI~
//!get start offset from current csr pos                           //~v76mI~
//* rc    :0:csr is  on client area, 4:csr is out of client area   //~v76mI~
//         1:cout of client area but line is on client area        //~v76mI~
//**************************************************************** //~v76mI~
int panfnlgetstartplhoffs(PUCLIENTWE Ppcw,PULINEH *Ppplh,int *Ppoffset,int Popt)//~v76mI~
{                                                                  //~v76mI~
	int offset,rc,ii,startline,yy;                                 //~v76mR~
	PULINEH plh;                                                   //~v76mI~
	PUFILEC pfc;                                                   //~v76mI~
	PUP300LIST psc,psco=0;                                         //~vaf9R~
//*****************                                                //~v76mI~
	rc=4;                                                          //~v76mI~
	offset=0;                                                      //~v76mI~
	pfc=Ppcw->UCWpfc;                                              //~v76mI~
    yy=Ppcw->UCWrcsry-PANL300LISTTOP;                              //~v76mI~
    if (yy<0)                                                      //~v76mI~
    {                                                              //~v76mI~
	    plh=pfc->UFCcurtop;                                        //~v76mI~
        if (Popt)                                                  //~v76mI~
        	offset=OFFS_TOP;		//before client area           //~v76mI~
	}                                                              //~v76mI~
	else                                                           //~v76mI~
    {                                                              //~v76mI~
		startline=Ppcw->UCWtopfnlist+yy;                           //~v76mR~
    	for (ii=0,psc=UGETQTOP(Spfnstack);ii<startline && psc;ii++)//all entry//~v76mI~
        {                                                          //~v76mI~
        	psco=psc;                                              //~v76mI~
    		psc=UGETQNEXT(psc);		//skip prev page               //~v76mI~
        }                                                          //~v76mI~
		if (psc)                                                   //~v76mI~
		{                                                          //~v76mI~
	    	plh=psc->U3Lplh;                                       //~v76mI~
            rc=0;                                                  //~v76mI~
            if (plh==Sfoundplh)                                    //~v76mI~
                if (Ssubcmdid==SUBCMD_PREV) //reverse search       //~v76mI~
                    offset=0; //serach from prevline               //~v76mI~
                else                                               //~v76mI~
                    offset=plh->ULHlen;	//search from next line    //~v76mI~
            else                                                   //~v76mI~
                if (Ssubcmdid==SUBCMD_PREV) //reverse search       //~v76mR~
                    offset=plh->ULHlen; //serach this line         //~v76mR~
                else                                               //~v76mR~
                    offset=0;           //search this line         //~v76mR~
		}                                                          //~v76mI~
		else	//out of end of file                               //~v76mI~
		{                                                          //~v76mI~
	    	plh=psco->U3Lplh;                                      //~v76mI~
			offset=plh->ULHlen;                                    //~v76mI~
  		    if (Popt)                                              //~v76mI~
            	offset=OFFS_LAST;		//after client area        //~v76mI~
		}                                                          //~v76mI~
    }                                                              //~v76mI~
	*Ppplh=plh;                                                    //~v76mI~
	*Ppoffset=offset;                                              //~v76mI~
	return rc;                                                     //~v76mI~
}//panfnlgetstartplhoffs                                           //~v76mI~
#ifdef UTF8SUPPH                                                   //~va00I~
//*******************************************************          //~va00M~
//*save utf8code data of  input filed(locale code)                 //~va00M~
//*!!! through BYUTF8_pansetflddata                                //~vaf9I~
//*******************************************************          //~va00M~
#ifdef CCC                                                         //~va0tM~
int pansetflddata_utf8(int Popt,PUCLIENTWE Ppcw,int Prow,int Pfldno)//~va00M~
#else                                                              //~va0tI~
int pansetflddata_utf8(int Popt,PUCLIENTWE Ppcw,int Prow,int Pfldno,char *Pdata)//~va0tI~
#endif                                                             //~va0tI~
{                                                                  //~va00M~
//************************                                         //~va00M~
    switch(((PUPANELC)Ppcw->UCWppc)->UPCid)                        //~va00M~
    {                                                              //~va00M~
    case PANFNAME  :        //filename                             //~va00M~
#ifdef CCC                                                         //~va0tI~
        pan300setflddata_utf8(Ppcw,Prow,Pfldno,0);                 //~va00R~
#else                                                              //~va0tI~
        pan300setflddata_utf8(Ppcw,Prow,Pfldno,Pdata);             //~va0tI~
#endif                                                             //~va0tI~
        break;                                                     //~va00I~
    case PANUCOMP  :        //compare utility                      //~va00M~
#ifdef CCC                                                         //~va0tI~
        pancompsetflddata_utf8(Ppcw,Prow,Pfldno,0/*from charpan*/);//~va00I~
#else                                                              //~va0tI~
        pancompsetflddata_utf8(Ppcw,Prow,Pfldno,Pdata);            //~va0tI~
#endif                                                             //~va0tI~
        break;                                                     //~va00I~
    case PANUGREP  :        //grep utility panel                   //~va00M~
#ifdef CCC                                                         //~va0tI~
        pangrepsetflddata_utf8(Ppcw,Prow,Pfldno,0/*from char pan*/);//~va00I~
#else                                                              //~va0tI~
        pangrepsetflddata_utf8(Ppcw,Prow,Pfldno,Pdata);            //~va0tI~
#endif                                                             //~va0tI~
        break;                                                     //~va00I~
    }                                                              //~va00M~
    return 0;                                                      //~va00R~
}//pansetflddata                                                   //~va00M~
//*******************************************************          //~va0tI~
//*get utf8 buffer for other than panutil/cmdline                  //~va0tI~
//return charfldedit option                                        //~va0tI~
//*******************************************************          //~va0tI~
int pangetbuff_utf8(int Popt,PUCLIENTWE Ppcw,int Prow,int Pfldno,  //~va0tI~
					PUPANELL *Pppupl,UCHAR **Ppbuffu8,UCHAR **Ppcodetype,int *Ppbuffu8sz)//~va0tR~
{                                                                  //~va0tI~
	PUPANELC ppc;                                                  //~va0tI~
	PUPANELL pupl;                                                 //~va0tI~
    UCHAR *pct,*pu8;                                               //~va0tI~
//  int buffu8sz,swu8=0;                                           //~vaf9R~
    int buffu8sz=0,swu8=0;                                         //~vaf9I~
//************************                                         //~va0tI~
    ppc=(PUPANELC)Ppcw->UCWppc;                                    //~va0tI~
    pupl=ppc->UPCline+Prow;                                        //~va0tI~
	pu8=pupl->UPLbuffbyutf8;                                       //~va0tI~
    if (!pu8)	//no utf8 buff                                     //~va0tI~
    	return 0;                                                  //~va0tI~
    pct=pupl->UPLcodetype;                                         //~va0tI~
    switch(ppc->UPCid)                                             //~va0tI~
    {                                                              //~va0tI~
    case PANFNAME  :        //filename                             //~va0tI~
        switch(Prow)                                               //~va0tI~
        {                                                          //~va0tI~
        case PANL300FILENAME:                                      //~va0tI~
        case PANL300DIR:                                           //~va0tI~
        	buffu8sz=UPLBUFF2SZ;                                   //~va0tR~
            swu8=CFEO_OPTPANFNM;    //fnm panel                    //~va0tI~
        }                                                          //~va0tI~
        break;                                                     //~va0tI~
    }                                                              //~va0tI~
    if (!swu8)                                                     //~va0tI~
        return 0;                                                  //~va0tI~
    *Pppupl=pupl;                                                  //~va0tR~
    *Ppbuffu8=pu8;                                                 //~va0tI~
    *Ppcodetype=pct;                                               //~va0tI~
    *Ppbuffu8sz=buffu8sz;                                          //~va0tI~
    return swu8;                                                   //~va0tR~
}//pangetbuff_utf8                                                 //~va0tI~
#endif	//UTF8SUPPH                                                //~va00I~
