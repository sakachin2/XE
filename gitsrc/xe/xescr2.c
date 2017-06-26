//CID://+vafkR~:              update#=      11                     //+vafkR~
//***********************************************************
//* xescr2.c
//* confirm/splith/splitv/swap/nextpan/prevpan                  //~5105R~
//***********************************************************
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//+vafkI~
//va1q:091107 compchkm                                             //~va1qI~
//va1c:091030_merge GB18030 support                                //~va1cI~
//v74x:070223*(BUG)generated tab expand required for "cv x2c"      //~v74xI~
//v53m:030928 (LNX)mouse support                                   //~v53mI~
//v500:020929 (WXE)scr cut/paste                                   //~v500I~
//v0jm:980723 INS cmd(operand=ON/OFF)                              //~v0jmI~
//v0j4:980720 return norma when split is same as current for pfk comd string//~v0j4I~
//v09l:970518:csr wait mark in dlcmd or cmd processing             //~v09lI~
//            drop pcw parm not used on scrcsrtyperestore          //~v09lI~
//v07s:960825:new ulib.h/ulibdef.h(no need base def by os2.h)      //~v07sI~
//            to speed up compile,drop include(caused by WIN95 modify)//~v07sI~
//v05k:951119:del dir confirm                                   //~v05kI~
//v04d:950930:malloc/calloc rc chk for dos                      //~v04dI~
//950527 bug:vsplit pos when cmd input                          //~5527I~
//***********************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifdef DOS
#else
//  #define INCL_BASE                                              //~v07sR~
//  #include <os2.h>                                               //~v07sR~
#endif
//*******************************************************
#include <ulib.h>
#include <uque.h>
#include <uerr.h>                                               //~5105I~
#include <ufile.h>                                              //~v05kI~
#ifdef UTF8SUPPH                                                   //~va1qI~
#include <udbcschk.h>                                              //~va1cR~
#endif                                                             //~va1qI~
                                                                //~5105I~
#include "xe.h"
#include "xescr.h"
#include "xescr2.h"
#include "xepan.h"
#include "xecsr.h"
#include "xefunc.h"                                             //~5105I~
#include "xefunc2.h"                                               //~v500I~
#include "xeerr.h"                                                 //~v0jmI~
#include "xefile.h"                                                //~v500I~
#include "xedir.h"                                                 //~v500I~
#include "xesub.h"                                                 //~v74xM~
#ifdef UTF8SUPPH                                                   //~va1qI~
#include "xesub2.h"                                                //~va1cR~
#endif                                                             //~va1qI~
//*******************************************************
int scrpansw(PUCLIENTWE Ppcw,int Pdest);                        //~5105I~
//void scrcpgetframedata(PUCLIENTWE Ppcw,PUSCRD Ppsd,int Prow,int Pcol,int Pcolend,//~v500R~
//                    char **Ppdata,char **Ppdbcs,int *Pplen);     //~v500R~
//****************************************************************
// scrconfirmchk
//*chk confirmation msg active
//*parm1 :requester id
//*return :rc=1:active 0:inactive(requested)
//****************************************************************
int scrconfirmchk(int Preqid)
{
//*********************************
	switch(Preqid)
	{
	case GSCRCONFUNDO:
		if (UCBITCHK(Gopt,GOPTUNDONOCONF))	//no confirm option
			return 1;		//assume active
		break;
	case GSCRCONFCANCEL:
		if (UCBITCHK(Gopt,GOPTCANCELNOCONF))	//no confirm
			return 1;		//assume active
		break;
	case GSCRCONFSAVE:                                          //~5128I~
		if (UCBITCHK(Gopt,GOPTSAVENOCONF))	//no confirm        //~5128I~
			return 1;		//assume active                     //~5128I~
		break;                                                  //~5128I~
	}
	if (Gscrconfactid==Preqid)
	{
		Gscrconfactid=0;	//effective only once
		return 1;			//active
	}

	Gscrconfactid=0;			//deactivate previous other conf msg
	Gscrconfreqid=Preqid;		//request to scrdispl
	return 0;					//now not active
}//scrconfirmchk

//****************************************************************
// scrconfirmset
//*set confirm msg issued status
//*parm1 :none                                                  //~v05kR~
//*return :none
//****************************************************************
void scrconfirmset(void)                                        //~v05kR~
{
//*********************************
	Gscrconfactid=Gscrconfreqid;	//accept request
	Gscrconfreqid=0;				//accepted
	return;
}//scrconfirmset

//****************************************************************
// scrconfirmreset
//*reset confirm msg issued status
//*parm1 :none
//*return :none                                                 //~v05kR~
//****************************************************************
void scrconfirmreset(void)                                      //~v05kR~
{
//*********************************
	Gscrconfactid=0;		//reset confirm msg active
	if (Gscrconfreqid!=GSCRCONFDELDIR)//next is also xdel confirm?//~v05kR~
	    Gxdconfindex=0;                                         //~v05kR~
	return;                                                     //~v05kR~
}//scrconfirmreset

//****************************************************************
// scrclearmsg
//*clear errmsg displayed on hdr line
//*parm1 :pcw
//*return :none
//****************************************************************
void scrclearmsg(PUCLIENTWE Ppcw)
{
//*********************************
	UCBITON(((PUSCRD)Ppcw->UCWpsd)->USDflag2,USDF2DRAW);//msg clear
	return;
}//scrclearmsg

//****************************************************************
// scrclearconfirmmsg
//*clear confirm msg if exist
//*parm1 :none
//*return :none
//****************************************************************
void scrclearconfirmmsg(void)
{
	PUCLIENTWE pcw;
//*********************************
	if (Gscrconfactid)	//conf msg active
	{
		pcw=scrgetcw(0);	//active client
		UCBITON(((PUSCRD)pcw->UCWpsd)->USDflag2,USDF2DRAW);//msg clear
	}
	return;
}//scrclearconfirmmsg

//****************************************************************
// func_splith
//*screen horizontal split
//****************************************************************
int func_splith(PUCLIENTWE Ppcw)
{
	PUCLIENTWE pcw1,pcw2;
//***************
	if (!Gcsrposy)//top line
		return 4;
	pcw1=scrgetcw(1);
	pcw2=scrgetcw(2);
	if (!pcw2)		//no splith
	{
		UCBITON(pcw1->UCWflag,UCWFDRAW);
		UCBITON(Gscrstatus,GSCRSSPLITH);
		Gscrcurclient=1;
		Gscrsplith=Gcsrposy;			//splith at csr pos
		Gscrsplitv=0;			//splith at csr pos
		scrresize(pcw1);			//set first client size
	    if (!panregist(PANTOPMENU))		//top menu setup;       //~v04dR~
        	return 8;	//storage shortage                      //~v04dI~
	}//first split
	else	//already splith
	{
		if (UCBITCHK(Gscrstatus,GSCRSSPLITH))
		{
			if (Gcsrposy==Gscrsplith)//move split upper
//  			return 4;                                          //~v0j4R~
    			return 0;                                          //~v0j4R~
			if (Gcsrposy<Gscrsplith)//move split upper
				Gscrcurclient=1;	//sewcond is new active
			else						//down split line
				Gscrcurclient=0;	//first is new active
			Gscrsplith=Gcsrposy;			//splith at csr pos
		}//change horizon
		else	//change splitv-->splith
		{		
			UCBITOFF(Gscrstatus,GSCRSSPLITV);
			UCBITON(Gscrstatus,GSCRSSPLITH);
			if (Gcsrposx<Gscrsplitv)//left of virtical split line
				Gscrcurclient=0;	//upper is active
			else						//right of vline
				Gscrcurclient=1;	//lower is active
			Gscrsplitv=0;					//stop splitv
			Gscrsplith=Gcsrposy;			//splith at csr pos
		}
		scrresize(pcw1);
		scrresize(pcw2);
		csrhomepos(0);			//move csr to 1st fld of current active
		UCBITON(pcw1->UCWflag,UCWFDRAW);
		UCBITON(pcw2->UCWflag,UCWFDRAW);
	}//already split
	return 0;
}//func_splith

//****************************************************************
// func_splitv
//*screen virtical split
//****************************************************************
int func_splitv(PUCLIENTWE Ppcw)
{
	PUCLIENTWE pcw1,pcw2;
//***************
    if (Ppcw->UCWkeytype==UCWKTCMD)	//cmd input,posx changed by csrhome//~5527I~
      	Gcsrposx=Ppcw->UCWvsplitx;	//set at exec_pan           //~5527I~
	if (!Gcsrposx)//first
		return 4;
	pcw1=scrgetcw(1);
	pcw2=scrgetcw(2);
	if (!pcw2)		//no splith
	{
		UCBITON(pcw1->UCWflag,UCWFDRAW);
		UCBITON(Gscrstatus,GSCRSSPLITV);
		Gscrcurclient=1;
		Gscrsplitv=Gcsrposx;			//splith at csr pos
		Gscrsplith=0;			//splith at csr pos
		scrresize(pcw1);			//set client size for forst
	    if (!panregist(PANTOPMENU))		//top menu setup;       //~v04dR~
        	return 8;	//storage shortage                      //~v04dI~
	}//first split
	else	//already splith
	{
		if (UCBITCHK(Gscrstatus,GSCRSSPLITV))//already virtical
		{
			if (Gcsrposx==Gscrsplitv)//move split upper
//  			return 4;                                          //~v0j4R~
    			return 0;                                          //~v0j4R~
			if (Gcsrposx<Gscrsplitv)//move split left more
				Gscrcurclient=1;	//sewcond is new active
			else						//down split line
				Gscrcurclient=0;	//first is new active
			Gscrsplitv=Gcsrposx;			//splith at csr pos
		}//change horizon
		else	//change splitv-->splith
		{		
			UCBITOFF(Gscrstatus,GSCRSSPLITH);
			UCBITON(Gscrstatus,GSCRSSPLITV);
			if (Gcsrposy<Gscrsplith)//upper of horizontal split line
				Gscrcurclient=0;	//upper is active
			else						//right of vline
				Gscrcurclient=1;	//lower is active
			Gscrsplith=0;					//stop splitv
			Gscrsplitv=Gcsrposx;			//splith at csr pos //~4C31R~
		}
		scrresize(pcw1);
		scrresize(pcw2);
		csrhomepos(0);			//move csr to 1st fld of current active
		UCBITON(pcw1->UCWflag,UCWFDRAW);
		UCBITON(pcw2->UCWflag,UCWFDRAW);
	}//already split
	return 0;
}//func_splitv

//****************************************************************
// func_swap
//*swap screen(swap screen size)
//****************************************************************
int func_swap(PUCLIENTWE Ppcw)
{
	PUCLIENTWE pcw1,pcw2;                                       //~4C24I~
//***************
	if (UCBITCHK(Gscrstatus,GSCRSSPLITV))//already virtical
		Gscrsplitv=Gscrwidth-Gscrsplitv;//set csr to change width//~4C24R~
	else
		if (UCBITCHK(Gscrstatus,GSCRSSPLITH))//already horizontal
			Gscrsplith=Gscrheight-Gscrsplith;//set csr to change width//~4C24R~
		else
			return 4;                                           //~4C24R~
	Gscrcurclient=!Gscrcurclient;	//lower is active           //~4C24I~
	scrresize(pcw1=scrgetcw(1));                                //~4C24R~
	scrresize(pcw2=scrgetcw(2));                                //~4C24R~
	csrhomepos(0);	//home pos of cur client                    //~5224R~
	UCBITON(pcw1->UCWflag,UCWFDRAW);                            //~4C24I~
	UCBITON(pcw2->UCWflag,UCWFDRAW);                            //~4C24I~
	return 0;                                                   //~4C24R~
}//func_swap

//****************************************************************//~5105I~
// func_nextpan                                                 //~5105I~
//*push current,pop bottom panel                                //~5105I~
//****************************************************************//~5105I~
int func_nextpan(PUCLIENTWE Ppcw)                               //~5105I~
{                                                               //~5105I~
//***************                                               //~5105I~
	return scrpansw(Ppcw,1);                                    //~5105I~
}//func_nextpan                                                 //~5105I~
                                                                //~5105I~
//****************************************************************//~5105I~
// func_prevpan                                                 //~5105I~
//*pop up current then enq to bottom                            //~5105I~
//****************************************************************//~5105I~
int func_prevpan(PUCLIENTWE Ppcw)                               //~5105I~
{                                                               //~5105I~
//***************                                               //~5105I~
	return scrpansw(Ppcw,-1);                                   //~5105I~
}//func_prevpan                                                 //~5105I~
                                                                //~5105I~
//****************************************************************//~5105I~
// scrpansw                                                     //~5105I~
//*rotate panel                                                 //~5105I~
//****************************************************************//~5105I~
int scrpansw(PUCLIENTWE Ppcw,int Pdest)                         //~5105I~
{                                                               //~5105I~
	PUQUEH pqh;                                                 //~5105I~
	PUCLIENTWE pcw;                                             //~5105I~
//***************                                               //~5105I~
	pqh=UGETQHDR(Ppcw);		                                    //~5105I~
	if (UGETQCTR(pqh)==1)	//only myself                       //~5105I~
	{                                                           //~5105I~
		uerrmsg("Only one panel stacked",                       //~5105I~
				"1 画面しかスタックされていません");            //~5105I~
		return 4;                                               //~5105I~
	}                                                           //~5105I~
    if (Pdest>0)    //nextpan                                   //~5105I~
    {                                                           //~5105I~
		pcw=UGETQEND(pqh);	//get bottom pcw                    //~5105I~
		scrpopup(pcw,0);	//move to top,no return deq pcw ptr parm//~5228R~
    }                                                           //~5105I~
	else			//prevpan                                   //~5105I~
//  	scrpopup((PUCLIENTWE)(-1),0);	//rotational popup,no save ptr//~5228R~//+vafkR~
    	scrpopup((PUCLIENTWE)(ULPTR)(-1),0);	//rotational popup,no save ptr//+vafkI~
	return 0;                                                   //~5105I~
}//func_nextpan                                                 //~5105I~
                                                                //~5105I~
//****************************************************************
// insert toggle
//****************************************************************
int func_ins(PUCLIENTWE Ppcw)
{
	int cid;
    UCHAR *pc;                                                     //~v0jmR~
//**********************
	if (Ppcw->UCWkeytype==UCWKTCMD	//cmd input                    //~v0jmI~
 	&&  (pc=Ppcw->UCWparm,pc))				//parm exist           //~v0jmI~
    {                                                              //~v53mI~
		if (!strcmp(strupr(pc),"ON"))                              //~v0jmI~
        {                                                          //~v0jmI~
			if (UCBITCHK(Gscrstatus,GSCRSINS))//already isrt mode  //~v0jmI~
            	return 0;                                          //~v0jmI~
		}                                                          //~v0jmI~
        else                                                       //~v0jmI~
			if (!strcmp(strupr(pc),"OFF"))                         //~v0jmI~
            {                                                      //~v0jmI~
				if (!UCBITCHK(Gscrstatus,GSCRSINS))//already isrt mode//~v0jmI~
    	        	return 0;                                      //~v0jmI~
            }                                                      //~v0jmI~
            else                                                   //~v0jmI~
                return errinvalid(pc);                             //~v0jmI~
    }//cmd input parm exist                                        //~v53mI~
	if (UCBITCHK(Gscrstatus,GSCRSINS))//already isrt mode
	{	
		csrchangetype(CSRTYPNOR);
		UCBITOFF(Gscrstatus,GSCRSINS);
	}
	else
	{
		csrchangetype(CSRTYPINS);
		UCBITON(Gscrstatus,GSCRSINS);
	}
	if (UCBITCHK(Gscrstatus,GSCRSSPLITV))	//split virtical
		cid=2;
	else
		cid=1;
	UCBITON(((PUSCRD)scrgetcw(cid)->UCWpsd)->USDflag2,USDF2DRAW);//draw hdr to change rep mode display 
	return 0;
}//func_ins
                                                                   //~v05kI~
//**************************************************************** //~v05kI~
// csr restore                                                     //~v05kI~
//**************************************************************** //~v05kI~
void scrcsrtyperestore(void)                                       //~v09lR~
{                                                                  //~v05kI~
//**********************                                           //~v05kI~
	if (UCBITCHK(Gscrstatus,GSCRSINS))//already isrt mode          //~v05kI~
		csrchangetype(CSRTYPINS);                                  //~v05kI~
	else                                                           //~v05kI~
		csrchangetype(CSRTYPNOR);                                  //~v05kI~
	return;                                                        //~v05kI~
}//scrcsrtyperestore                                               //~v05kR~
//#ifdef WXE                                                       //~v53mR~
#if defined(WXE)||defined(LNX)                                     //~v53mI~
////****************************************************************//~v500R~
//// csr restore                                                   //~v500R~
////****************************************************************//~v500R~
//int scrcpgetdata(int Prow,int Pcol,int Pendcol,char **Ppdata,char **Ppdbcs,int *Pplen)//~v500R~
//{                                                                //~v500R~
//    PUCLIENTWE pcw;                                              //~v500R~
//    PUSCRD     psd;                                              //~v500R~
//    PULINEH    plh;                                              //~v500R~
//    PUFILEC    pfc;                                              //~v500R~
//    PUFILEH    pfh;                                              //~v500R~
//    int pcwtype,psdpos,len,pos;                                  //~v500R~
//    char *pc;                                                    //~v500R~
////**********************                                         //~v500R~
//    psdpos=scrcpgetpcw(Prow,Pcol,&pcw);                          //~v500R~
//    pcwtype=pcw->UCWtype;                                        //~v500R~
//    psd=pcw->UCWpsd;                                             //~v500R~
//    psd+=psdpos;                                                 //~v500R~
//    switch(pcwtype)                                              //~v500R~
//    {                                                            //~v500R~
//    case UCWTMENU:                                               //~v500R~
//        scrcpgetframedata(pcw,psd,Prow,Pcol,Pendcol,&pc,Ppdbcs,&len);//~v500R~
//        break;                                                   //~v500R~
//    case UCWTFILE:                                               //~v500R~
//        if (Prow<pcw->UCWfilehdrlineno)                          //~v500R~
//        {                                                        //~v500R~
//            scrcpgetframedata(pcw,psd,Prow,Pcol,Pendcol,&pc,Ppdbcs,&len);//~v500R~
//            break;                                               //~v500R~
//        }                                                        //~v500R~
//        if (Prow>=pcw->UCWmaxline)                               //~v500R~
//        {                                                        //~v500R~
//            pc=0,len=0;                                          //~v500R~
//            break;                                               //~v500R~
//        }                                                        //~v500R~
//        plh=psd->USDbuffc;                                       //~v500R~
//        pfh=UGETPFH(plh);                                        //~v500R~
//        pfc=pcw->UCWpfc;                                         //~v500R~
//        pc=plh->ULHdata;                                         //~v500R~
//        len=plh->ULHlen;                                         //~v500R~
//        if (Pcol>=(int)pcw->UCWlinenosz)    //data area          //~v500R~
//        {                                                        //~v500R~
//            pos=Pcol+pfc->UFCleft;                               //~v500R~
//            pc+=pos;                                             //~v500R~
//            len-=pos;                                            //~v500R~
//            if (len<0)                                           //~v500R~
//                pc=0,len=0;                                      //~v500R~
//        }                                                        //~v500R~
//        if (Pendcol>=(int)pcw->UCWlinenosz) //data area          //~v500R~
//        {                                                        //~v500R~
//            pos=Pendcol+pfc->UFCleft;                            //~v500R~
//            if (pos<plh->ULHlen)                                 //~v500R~
//                len-=plh->ULHlen-pos;                            //~v500R~
//        }                                                        //~v500R~
//        break;                                                   //~v500R~
//    case UCWTDIR:                                                //~v500R~
//        if (Prow<pcw->UCWfilehdrlineno)                          //~v500R~
//        {                                                        //~v500R~
//            scrcpgetframedata(pcw,psd,Prow,Pcol,Pendcol,&pc,Ppdbcs,&len);//~v500R~
//            break;                                               //~v500R~
//        }                                                        //~v500R~
//        if (Prow>=pcw->UCWmaxline)                               //~v500R~
//        {                                                        //~v500R~
//            pc=0,len=0;                                          //~v500R~
//            break;                                               //~v500R~
//        }                                                        //~v500R~
//        scrcpgetframedata(pcw,psd,Prow,Pcol,Pendcol,&pc,Ppdbcs,&len);//~v500R~
//        break;                                                   //~v500R~
//    }                                                            //~v500R~
//    if (Ppdata)                                                  //~v500R~
//        *Ppdata=pc;                                              //~v500R~
//    *Pplen=len;                                                  //~v500R~
//    return pcwtype;                                              //~v500R~
//}//scrcpgetdata                                                  //~v500R~
//**************************************************************** //~v500I~
// search pcw at csr pos                                           //~v500R~
//**************************************************************** //~v500I~
int scrcpgetpcw(int Prow,int Pcol,PUCLIENTWE *Pppcw)               //~v500I~
{                                                                  //~v500I~
    PUCLIENTWE pcw;                                                //~v500I~
    int pcwid,psdpos;                                              //~v500R~
//**********************                                           //~v500I~
    psdpos=Prow;                                                   //~v500I~
	if (UCBITCHK(Gscrstatus,GSCRSSPLITH))  //horizontal            //~v500I~
		if (Prow >= Gscrsplith)                                    //~v500I~
        {                                                          //~v500I~
        	pcwid=2; 	//2nd client                               //~v500I~
        	psdpos-=Gscrsplith;                                    //~v500I~
        }                                                          //~v500I~
        else                                                       //~v500I~
        	pcwid=1;                                               //~v500I~
    else                                                           //~v500I~
	if (UCBITCHK(Gscrstatus,GSCRSSPLITV))       //virtical         //~v500I~
		if (Pcol >= Gscrsplitv)                                    //~v500I~
        	pcwid=2; 	//2nd client                               //~v500I~
        else                                                       //~v500I~
        	pcwid=1;                                               //~v500I~
    else                                                           //~v500I~
        pcwid=1;                                                   //~v500I~
    pcw=scrgetcw(pcwid);    //2nd client                           //~v500I~
    *Pppcw=pcw;                                                    //~v500I~
    return psdpos;                                                 //~v500I~
}//scrcpgetpcw                                                     //~v500I~
////****************************************************************//~v500R~
//// get frame data                                                //~v500R~
////****************************************************************//~v500R~
//void scrcpgetframedata(PUCLIENTWE Ppcw,PUSCRD Ppsd,int Prow,int Pcol,int Pcolend,//~v500R~
//                    char **Ppdata,char **Ppdbcs,int *Pplen)      //~v500R~
//{                                                                //~v500R~
//    int len;                                                     //~v500R~
//    char *pc;                                                    //~v500R~
////**********************                                         //~v500R~
//    if (Prow>Ppcw->UCWheight)    //over max line                 //~v500R~
//        pc=0,len=0;                                              //~v500R~
//    else                                                         //~v500R~
//    {                                                            //~v500R~
//        pc=Ppsd->USDdata+Pcol;                                   //~v500R~
//        len=Ppsd->USDlen;                                        //~v500R~
//        if (len<Pcol)                                            //~v500R~
//            pc=0,len=0;                                          //~v500R~
//        else        //start in data                              //~v500R~
//            if (len>Pcolend)                                     //~v500R~
//                len=Pcolend-Pcol;                                //~v500R~
//            else                                                 //~v500R~
//                len-=Pcol;                                       //~v500R~
//    }                                                            //~v500R~
//    *Pplen=len;                                                  //~v500R~
//    if (Ppdata)                                                  //~v500R~
//        *Ppdata=pc;                                              //~v500R~
//    if (pc)                                                      //~v500R~
//        pc=Ppsd->USDdbcs+(ULONG)pc-(ULONG)Ppsd->USDdata;         //~v500R~
//    if (Ppdbcs)                                                  //~v500R~
//        *Ppdbcs=pc;                                              //~v500R~
//}//scrcpgetframedata                                             //~v500R~
//**************************************************************** //~v500I~
// get frame data                                                  //~v500I~
//ret:0:pcw is active,1:pcw is not active                          //~v500I~
//**************************************************************** //~v500I~
int scrsetcsrpos(int Prow,int Pcol)                                //~v500R~
{                                                                  //~v500I~
	int row,col;                                                   //~v500R~
    PUCLIENTWE pcw;                                                //~v500I~
//**********************                                           //~v500I~
#ifdef UTF8SUPPH                                                   //~va1cR~
	if (UDBCSCHK_DBCSNOT1ST(Gscrdbcstbl[Prow*Gscrbuffwidth+Pcol])) //~va1cR~
    {                                                              //~va1cR~
    	Pcol-=XESUB_DBCSSPLITCTR_L(Gscrdbcstbl+Prow*Gscrbuffwidth,Pcol);//~va1cR~
		if (UDBCSCHK_DBCSNOT1ST(Gscrdbcstbl[Prow*Gscrbuffwidth+Pcol])) //not yet enough by lineno column//~va1cR~
            Pcol--;                                                //~va1cR~
    }                                                              //~va1cR~
#else                                                              //~va1cR~
	if (Gscrdbcstbl[Prow*Gscrbuffwidth+Pcol]==DBCS2NDCHAR)         //~v500I~
    	Pcol--;                                                    //~v500I~
#endif                                                             //~va1cR~
	row=scrcpgetpcw(Prow,Pcol,&pcw);                               //~v500I~
    col=Pcol;                                                      //~v500I~
	if (UCBITCHK(Gscrstatus,GSCRSSPLITV))       //virtical         //~v500I~
		if (Pcol >= Gscrsplitv)                                    //~v500I~
        	col=Pcol-Gscrsplitv; 	//relative                     //~v500I~
                                                                   //~v500I~
    pcw->UCWrcsrx=col;                                             //~v500I~
    pcw->UCWrcsry=row;                                             //~v500I~
	csrloctogbl(pcw);	//convert local to gbl csr pos             //~v500I~
    return (pcw->UCWsplitid!=Gscrcurclient);	//1 if inactive    //~v500I~
}//scrsetcsrpos                                                    //~v500I~
#endif                                                             //~v500I~
