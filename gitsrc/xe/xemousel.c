//*CID://+vb30R~:                             update#=  353;       //+vb30R~
//*************************************************************
//xemousel.c
//*	linux mouse proc
//*************************************************************
//vb30:160411 (LNX)Compiler warning                                //+vb30I~
//vafe:120612 BUG found by chk uninitialized variable warning by gcc 4.1.1 on FC5//~vafeI~
//vaa7:111117 (gcc4.6)Warning:unused-but-set                       //~vaa7I~
//v76p:070628 compare remote file support                          //~v76pR~
//v69m:060524 (WXEXXE)pass scroll ctr not by string cmd parm but thrugh gbl var to avoid cmd line input cleared//~v69mI~
//v69k:060523 (LNX)console;Shift/Ctrl+mouse wheel logic missing    //~v69kI~
//v64w:050709 (LNX)openwith support by mouse dbl click             //~v64wI~
//v63y:050602 (LNX)accept mouse weel event to scroll down /up      //~v63yI~
//v63x:050602 (LNX)ignore mouse weel event                         //~v63xI~
//            (ukbdlnxm.c returns now wheel event toavoid buff overflow for wait btn up after btn down)//~v63xI~
//v63n:050510 (LNX)revese  mouse selected line on dirlist          //~v63nI~
//v56k:040404 (LNX)support DPU/DPD by mouse dblclick               //~v56kI~
//v55T:040319 (LNX)detect down and up event for cut & paste        //~v55TI~
//v53B:031013 (LNX)paste by mouse(middle button),edit/brouse by Ctrl key,//~v53BI~
//v53m:030928 (LNX)mouse support
//*************************************************************
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//**********************
#include <ulib.h>
#include <uque.h>
#include <ukbd.h>
#include <ukbdlnxc.h>
#include <ukbdlnxm.h>
#include <uerr.h>
#include <udbcschk.h>
#include <utrace.h>
#include <uedit.h>
#include <ufile.h>
#include <uftp.h>                                                  //~v76pR~
//**********************
#include "xe.h"
#include "xescr.h"
#include "xescr2.h"
#include "xefile.h"
#include "xefunc.h"
#include "xefunct.h"
                                                                   //~v69mI~
#define XEMOUSEL_GLOBAL		//gbl define                           //~v69mI~
#include "xemousel.h"
                                                                   //~v69mI~
#include "xepan.h"
#include "xesub.h"
#include "xecsr.h"
#include "xecap.h"
#include "xedlcmd.h"                                               //~v63nI~
#include "xedlcmd6.h"                                              //~v64wI~
//*************************************************************
#define FUNCTYPE_IGN  0
#define FUNCTYPE_PFK  1
#define FUNCTYPE_CMD  2
#define FUNCTYPE_CHR  3
#define FUNCTYPE_ERR  -2
                                                                   //~v56kI~
#define OPENBYXE_DLPOS1    0 //when dblclicked on dir list on this pos,//~v64wI~
#define OPENBYXE_DLPOS2    4 // open by xe ignoreing association even if exist//~v64wI~
#define OPENBYXE_HLPOS1    0 //when dblclicked on kistorylist on this pos,//~v64wI~
#define OPENBYXE_HLPOS2    2 // open by xe ignoreing association even if exist//~v64wI~
                                                                   //~v64wI~
#define DPUCOLS         0      //when dbl clicked                  //~v56kI~
#define DPUCOLE         3      //col.1-->4 for DPU(DirPathUp) cmd  //~v56kI~
#define DPDCOLS         9      //when dbl clicked                  //~v56kI~
#define DPDCOLE         6      //col.-9-->-6 for DPD(DirPathDown) cmd//~v56kI~
                                                                   //~v63nI~
#define DRAGCHK_NEW      0x01 //new selection                      //~v63nI~
#define DRAGCHK_ADD      0x02 //ctrl+                              //~v63nI~
#define DRAGCHK_RANGE    0x04 //Shift+                             //~v63nI~
//*************************************************************
	static int Sdownposx=0,Sdownposy=0;                            //~v55TI~
//  static char *Sscrollsz="3";                                    //~v69mR~
//  static PULINEH Sdragplhs=0;                                    //~v63nR~
//*************************************************************    //~v55TI~
     FTFUNC mousel_nop;
int mousel_lbdown(PUCLIENTWE Ppcw,int Pposx,int Pposy,FUNCTBL **Pppft);
int mousel_lbup(PUCLIENTWE Ppcw,int Pposx,int Pposy,FUNCTBL **Pppft);//~v55TI~
int mousel_lbclick(PUCLIENTWE Ppcw,int Pposx,int Pposy,FUNCTBL **Pppft);
int mousel_lbdblclick(PUCLIENTWE Ppcw,int Pposx,int Pposy,FUNCTBL **Pppft);
int  mousel_movecsr(int Prow,int Pcol);
int  mousel_lineselect(PUCLIENTWE Ppcw,int Prow,int Pcol,int Pflag,FUNCTBL **Pppft);
//int  mousel_lineselect_dirlist(PUCLIENTWE Ppcw,int Pshiftsw,int Prow,FUNCTBL **Pppft);//~v56kR~
int  mousel_lineselect_dirlist(PUCLIENTWE Ppcw,int Pshiftsw,int Prow,int Pcol,FUNCTBL **Pppft);//~v56kR~
//int  mousel_lineselect_fnamelist(PUCLIENTWE Ppcw,int Pshiftsw,int Prow,FUNCTBL **Pppft);//~v64wR~
int  mousel_lineselect_fnamelist(PUCLIENTWE Ppcw,int Pshiftsw,int Prow,int Pcol,FUNCTBL **Pppft);//~v64wI~
int  mousel_lineselect_file(PUCLIENTWE Ppcw,int Pflag,int Prow,int Pcol,FUNCTBL **Pppft);
int  mousel_lineselect_topmenu(PUCLIENTWE Ppcw,int Pshiftsw,int Prow,FUNCTBL **Pppft);
int  mousel_linedrag_dirlist(PUCLIENTWE Ppcw,int Pshiftsw,int Prow,int Pcol);//~v63nI~
int  mousel_strcmd(char *Pcmd,char *Pparm);
int  mousel_cmdline(PUCLIENTWE Ppcw,char *Pcmd,char *Pparm);
int  mousel_belcmd(PUCLIENTWE Ppcw,int Pshiftsw);
int  mousel_charinput(PUCLIENTWE Ppcw,int Row,int Pcol,int Pchar);
int mousel_mbdown(PUCLIENTWE Ppcw,int Pposx,int Pposy,FUNCTBL **Pppft);//~v53BI~
int  mousel_cappaste(PUCLIENTWE Ppcw,int Pinssw,int Pcol,int Prow,FUNCTBL **Pppft);//~v53BI~
int  mouselpathupdown(PUCLIENTWE Ppcw,int Pcol,FUNCTBL **Pppft);   //~v56kR~
int  mousel_dragselectchk(int Pshiftflag,int Prow,int Pcol,PUCLIENTWE Pppcw,PULINEH *Ppplh);//~v63nR~
int mousel_dragfile(int Pdragopt,PUCLIENTWE Ppcw,PULINEH Pplh);    //~v63nI~
int mousel_wheel(PUCLIENTWE Ppcw,int Pposx,int Pposy,int Pbutton,FUNCTBL **Pppft);//~v63yI~
//*************************************************************
//mouse event process
//*********************************************************************
int mousel_btnproc(KBDKEYINFO *Ppkeyinf)
{
    int eventid,button;
//**********************
    eventid=Ppkeyinf->chChar;
    button=eventid & 0x03;
UTRACEP("btnproc eventid=%x,button=%d\n",eventid,button);                         //~v56kR~//~v76pI~
//  if (button)	//not left button   0:left,1:middle,2:right,3:release//~v53BR~
    if (button>1)	//not left or middle                           //~v53BI~
	    return 0;		//ignore event
//  if (!(eventid & (UKLM_CLICK|UKLM_DBLCLICK))) //not click nor dblclick//~v55TR~
    if ((eventid & (UKLM_WHEEL))) //mouse whel                     //~v63xI~
//	    return 0;		//ignore event                             //~v63yR~
  	    return 1;		//process event                            //~v63yI~
    if ((eventid & (UKLM_TRPCLICK))) //accept click,dbl,down,up    //~v55TI~
	    return 0;		//ignore event
    return 1; 	//continue process
}//mousel_btnproc
//*************************************************************
//mouse func search
//Pkey:posx+posy+button status
//*********************************************************************
int mousel_funcsrch(PUCLIENTWE Ppcw,UCHAR *Pkey,FUNCTBL **Pppft,FTFUNC **Ppfunc)
{
    int eventid,button,posx,posy,rc=0,errrc=0;
    int wheelsw;                                                   //~v63yI~
	FUNCTBL *pft=0;
static int Sprevdownbutton=-1,Spreveventid=-1;                     //~v55TR~
//************************************
    eventid=Pkey[2];
UTRACEP("funcsrch eventid=%x,prebbutton=%d,preveventid=%x\n",eventid,Sprevdownbutton,Spreveventid);                        //~v56kR~//~v76pR~
    button=eventid & UKLM_BUTTON;//0x03;                           //~v55TR~
  	wheelsw= (eventid & UKLM_WHEEL);	//wheel up/down            //~v63yI~
    eventid=eventid & UKLM_DOWNMASK;                               //~v55TI~
    posx=Pkey[0];
    posy=Pkey[1];
  if (wheelsw)	//wheel up/down                                    //~v63yR~
    	rc=mousel_wheel(Ppcw,posx,posy,button,&pft);               //~v63yI~
  else                                                             //~v63yI~
  {                                                                //~v63yI~
    if (!button)	//not left button   0:left,1:middle,2:right,3:release
    {
    	rc=FUNCTYPE_IGN;   //ignore event                          //~v55TI~
        if (eventid & UKLM_DOWN)
            rc=mousel_lbdown(Ppcw,posx,posy,&pft);
        else                                                       //~v55TI~
        if (!eventid)            //button up                       //~v55TI~
        {                                                          //~v55TI~
        	if (Spreveventid & UKLM_DOWN                           //~v55TI~
            &&  Sprevdownbutton==0)       //prev event is button1 down//~v55TI~
	            rc=mousel_lbup(Ppcw,posx,posy,&pft);               //~v55TI~
        }                                                          //~v55TI~
        else
        if (eventid & UKLM_CLICK)
            rc=mousel_lbclick(Ppcw,posx,posy,&pft);
        else
        if (eventid & UKLM_DBLCLICK)
            rc=mousel_lbdblclick(Ppcw,posx,posy,&pft);
    }
    else		//middle button                                    //~v53BI~
    {                                                              //~v53BI~
        if (eventid & UKLM_DOWN                                    //~v53BR~
        ||  eventid & UKLM_CLICK)                                  //~v53BI~
            rc=mousel_mbdown(Ppcw,posx,posy,&pft);                 //~v53BI~
        else                                                       //~v53BI~
    	    rc=FUNCTYPE_IGN;   //ignore event                      //~v53BR~
    }                                                              //~v53BI~
    Sprevdownbutton=button;                                        //~v55TI~
    Spreveventid=eventid;                                          //~v55TI~
  }//not wheel                                                     //~v63yI~
    *Pppft=pft;
    if (pft)
    	*Ppfunc=pft->FTfunc[Ppcw->UCWtype];
    else
    	if (rc==FUNCTYPE_CMD)	//cmd string set
	    	*Ppfunc=&func_cmd;
        else
    	if (rc==FUNCTYPE_CHR)	//cmd string set
	    	*Ppfunc=&func_char;
        else
    	if (rc==FUNCTYPE_IGN)	//cmd string set
	    	*Ppfunc=&mousel_nop;
        else
        	errrc=4;
UTRACEP("funcsrch pft=%x\n",*Ppfunc);                              //~v76pI~
    return errrc;
}//mousel_funcsrch
//*************************************************************
//do nothing but scrdisp after return
//*********************************************************************
int mousel_nop(PUCLIENTWE Ppcw)
{
    return 0;
}//mousel_nop
//*************************************************************
//lbclick                                                          //~v55TR~
//*********************************************************************
int mousel_lbclick(PUCLIENTWE Ppcw,int Pposx,int Pposy,FUNCTBL **Pppft)
{
	int shiftstat;                                                 //~v63nI~
//************************************
    mousel_movecsr(Pposy,Pposx);
    if (Ppcw->UCWtype==UCWTDIR)                                    //~v63nM~
    {                                                              //~v63nM~
    	shiftstat=Ppcw->UCWkeyshift;                               //~v63nI~
        mousel_linedrag_dirlist(Ppcw,shiftstat,Pposy,Pposx); //reverse done//~v63nR~
    }    	                                                       //~v63nM~
    return FUNCTYPE_IGN;
}//mousel_lbclick
//*************************************************************
//lbdown
//*********************************************************************
int mousel_lbdown(PUCLIENTWE Ppcw,int Pposx,int Pposy,FUNCTBL **Pppft)
{
	int shiftstat;                                                 //~v55TI~
//************************************
    shiftstat=Ppcw->UCWkeyshift;                                   //~v55TI~
	if ((shiftstat & (UKBDLNXC_MOD_SHIFTL|UKBDLNXC_MOD_SHIFTR))    //~v55TI~
	||  (shiftstat & (UKBDLNXC_MOD_CONTROL)))                      //~v55TI~
    	return FUNCTYPE_IGN;                                       //~v55TI~
	Sdownposx=Pposx;                                               //~v55TI~
	Sdownposy=Pposy;                                               //~v55TI~
    mousel_movecsr(Pposy,Pposx);
    return FUNCTYPE_IGN;
}//mousel_lbdown
//*************************************************************    //~v55TI~
//lbup                                                             //~v55TI~
//*prev is lbdown,down pos is saved                                //~v55TI~
//*********************************************************************//~v55TI~
int mousel_lbup(PUCLIENTWE Ppcw,int Pposx,int Pposy,FUNCTBL **Pppft)//~v55TI~
{                                                                  //~v55TI~
	int shiftstat;                                                 //~v55TI~
//************************************                             //~v55TI~
UTRACEP("lbup posx=%d,posy=%d down=(x=%d,y=%d)\n",Pposx,Pposy,Sdownposx,Sdownposy);//~v76pI~
    shiftstat=Ppcw->UCWkeyshift;                                   //~v55TI~
	if ((shiftstat & (UKBDLNXC_MOD_SHIFTL|UKBDLNXC_MOD_SHIFTR))    //~v55TI~
	||  (shiftstat & (UKBDLNXC_MOD_CONTROL)))                      //~v55TI~
    	return FUNCTYPE_IGN;                                       //~v55TI~
    if (Ppcw->UCWtype!=UCWTFILE)                                   //~v55TI~
	    return FUNCTYPE_IGN;                                       //~v55TI~
    if (!CSRONFILELINE(Ppcw))                                      //~v55TI~
	    return FUNCTYPE_IGN;                                       //~v55TI~
	if (Sdownposx!=Pposx                                           //~v55TI~
	||  Sdownposy!=Pposy)                                          //~v55TI~
	    return FUNCTYPE_IGN;                                       //~v55TI~
UTRACEP("blockfile call\n");                                       //~v76pI~
    return func_block_file(Ppcw);                                  //~v55TI~
}//mousel_lbup                                                     //~v55TI~
//*********************************************************************
//lb double click
//*********************************************************************
int mousel_lbdblclick(PUCLIENTWE Ppcw,int Pposx,int Pposy,FUNCTBL **Pppft)
{
	int rc,shiftstat;
//************************
    shiftstat=Ppcw->UCWkeyshift;
    rc=mousel_lineselect(Ppcw,Pposy,Pposx,shiftstat,Pppft);
    return rc;
}//mousel_lbdblclk
//*********************************************************************//~v63yI~
//wheel up when button=0,down when button=1                        //~v63yI~
//*********************************************************************//~v63yI~
int mousel_wheel(PUCLIENTWE Ppcw,int Pposx,int Pposy,int Pbutton,FUNCTBL **Pppft)//~v63yI~
{                                                                  //~v63yI~
	FUNCTBL *pft;                                                  //~v63yR~
	int rc,funcid;                                                 //~v63yR~
//  char *cmdstr,*scrollszparm;                                    //~v69mR~
	int shiftstat,shiftsw,ctrlsw;;                                 //~v69kI~
//************************                                         //~v63yI~
    rc=0;                                                          //~v69kI~
    shiftstat=Ppcw->UCWkeyshift;                                   //~v69kI~
	shiftsw=shiftstat & (UKBDLNXC_MOD_SHIFTL|UKBDLNXC_MOD_SHIFTR); //~v69kI~
	ctrlsw=shiftstat & (UKBDLNXC_MOD_CONTROL);                     //~v69kI~
    if (Ppcw->UCWtype==UCWTFILE||Ppcw->UCWtype==UCWTDIR)           //~v63yI~
//      scrollszparm=Sscrollsz;                                    //~v69mR~
        rc=FUNCTYPE_PFK;                                           //~v69mI~
    else		//menu                                             //~v63yI~
		if (((PUPANELC)Ppcw->UCWppc)->UPCid==PANFNAME)             //~v63yI~
//          scrollszparm="";                                       //~v69mR~
    	    rc=FUNCTYPE_PFK;                                       //~v69mI~
        else                                                       //~v63yI~
		    return FUNCTYPE_IGN;                                   //~v63yI~
    if (ctrlsw)          //top/bottom                              //~v69kI~
    {                                                              //~v69kI~
	    if (Pbutton)    //button 2(button5)                        //~v69kI~
    	    funcid=FUNCID_BOTTOM;                                  //~v69kI~
    	else                                                       //~v69kI~
        	funcid=FUNCID_TOP;                                     //~v69kI~
//      scrollszparm="";                                           //~v69mR~
        rc=FUNCTYPE_PFK;                                           //~v69kI~
    }                                                              //~v69kI~
    else                                                           //~v69kI~
    if (shiftsw)          //horizontal scroll                      //~v69kI~
    {                                                              //~v69kI~
	    if (Ppcw->UCWtype!=UCWTFILE)                               //~v69kI~
		    return FUNCTYPE_IGN;                                   //~v69kI~
	    if (Pbutton)    //button 2(button5)                        //~v69kI~
    	    funcid=FUNCID_PGRIGHT;                                 //~v69kI~
    	else                                                       //~v69kI~
        	funcid=FUNCID_PGLEFT;                                  //~v69kI~
        rc=FUNCTYPE_PFK;                                           //~v69mI~
    }                                                              //~v69kI~
    else                                                           //~v69kI~
    {                                                              //~v69mI~
    if (Pbutton)    //button 2(button5)                            //~v63yI~
        funcid=FUNCID_PGDN;                                        //~v63yR~
    else                                                           //~v63yI~
        funcid=FUNCID_PGUP;                                        //~v63yR~
        rc=FUNCTYPE_PFK;                                           //~v69mI~
    }                                                              //~v69mI~
	if (!(pft=functblsrch(funcid)))                                //~v63yR~
	    return FUNCTYPE_IGN;                                       //~v63yI~
//if (rc==FUNCTYPE_PFK)//avoid string cmd remains on cmd input field//~v69mR~
  	*Pppft=pft;	                                                   //~v69kI~
//else                                                             //~v69mR~
//{                                                                //~v69mR~
//  cmdstr=pft->FTcmd;                                             //~v69mR~
//  rc=mousel_strcmd(cmdstr,scrollszparm);                         //~v69mR~
//}                                                                //~v69mR~
    Gwxestat|=GWXES_SCROLLBYMOUSE; //tell to getscrollsz it is scroll by mouse//~v69mI~
    return rc;                                                     //~v63yI~
}//mousel_wheel                                                    //~v63yI~
//*********************************************************************//~v53BI~
//mb down                                                          //~v53BI~
//*********************************************************************//~v53BI~
int mousel_mbdown(PUCLIENTWE Ppcw,int Pposx,int Pposy,FUNCTBL **Pppft)//~v53BI~
{                                                                  //~v53BI~
	int rc,shiftstat,isrtsw,shiftsw,ctlsw;                         //~v53BR~
//************************                                         //~v53BI~
    mousel_movecsr(Pposy,Pposx);                                   //~v53BI~
    shiftstat=Ppcw->UCWkeyshift;                                   //~v53BR~
	shiftsw=(shiftstat & (UKBDLNXC_MOD_SHIFTL|UKBDLNXC_MOD_SHIFTR));//~v53BI~
	ctlsw=(shiftstat & (UKBDLNXC_MOD_CONTROL));                    //~v53BI~
	if (shiftsw)      	//with shift key;may not detected          //~v53BR~
		isrtsw=1;       //1:insert mode                            //~v53BR~
    else                                                           //~v53BI~
	if (ctlsw)      //with control key                             //~v53BR~
		isrtsw=0;         //0:pasteon mode                         //~v53BR~
    else                                                           //~v53BI~
		isrtsw=1;    //1:insert mode                               //~v53BI~
	rc=mousel_cappaste(Ppcw,isrtsw,Pposx,Pposy,Pppft);    //1:insert mode//~v53BR~
    return rc;                                                     //~v53BI~
}//mousel_mbdown                                                   //~v53BI~
//*************************************************************
//*line select by dbl click
//*ret 0:ignore event,1:pft set,2:pft=0 but func_cmd call
//*************************************************************
int  mousel_lineselect(PUCLIENTWE Ppcw,int Prow,int Pcol,int Pflag,FUNCTBL **Pppft)
{
	int  rc=0,shiftsw,pcid,row,col,funcid,ctlsw;                   //~v53BR~
//***********************
	shiftsw=(Pflag & (UKBDLNXC_MOD_SHIFTL|UKBDLNXC_MOD_SHIFTR));
	ctlsw=(Pflag & (UKBDLNXC_MOD_CONTROL));                        //~v53BI~
    shiftsw|=ctlsw;                                                //~v53BI~
	pcid=((PUPANELC)Ppcw->UCWppc)->UPCid;
    row=Prow-Ppcw->UCWorgy;
    col=Pcol-Ppcw->UCWorgx;
    if (!row)           //hdr line
    {
        if (shiftsw)
            funcid=FUNCID_CANCEL;
        else
            funcid=FUNCID_END;
		*Pppft=functblsrch(funcid);
        return FUNCTYPE_PFK;
    }
	switch(pcid)
    {
	case PANTOPMENU:
		rc=mousel_lineselect_topmenu(Ppcw,shiftsw,row,Pppft);
		break;
	case PANFNAME  :		//filename
//  	rc=mousel_lineselect_fnamelist(Ppcw,shiftsw,row,Pppft);    //~v64wR~
    	rc=mousel_lineselect_fnamelist(Ppcw,shiftsw,row,col,Pppft);//~v64wI~
		break;
	case PANDIR   :		//dir list
//  	rc=mousel_lineselect_dirlist(Ppcw,shiftsw,row,Pppft);      //~v56kR~
    	rc=mousel_lineselect_dirlist(Ppcw,shiftsw,row,col,Pppft);  //~v56kI~
		break;
    case PANFBROWSE:
    case PANFEDIT:
		rc=mousel_lineselect_file(Ppcw,Pflag,row,col,Pppft);
		break;
//  default:;   //PANOPTCOLOR
    }
    return rc;
}//mousel_lineselect
//*************************************************************
//*top menu line select
//*************************************************************
int  mousel_lineselect_topmenu(PUCLIENTWE Ppcw,int Pshiftsw,int Prow,FUNCTBL **Pppft)
{
    int cmdid=0;
    char  cmdstr[2];
//**********************
	switch(Prow)
    {
    case  3:
    case  4:
    	cmdid='0';
        break;
    case  5:
    	cmdid='A';
        break;
    case  6:
    	cmdid='B';
        break;
    case  7:
    	cmdid='C';
        break;
    case  8:
    	cmdid='1';
        break;
    case  9:
    	cmdid='2';
        break;
    case  10:
    	cmdid='6';
        break;
    case  11:
    	cmdid='X';
        break;
    case  12:
    	cmdid='R';
        break;
    case  13:
    	cmdid='Q';
        break;
    }
    if (!cmdid)
    	return FUNCTYPE_IGN;
//  cmdstr[0]=cmdid;                                               //+vb30R~
    cmdstr[0]=(char)cmdid;                                         //+vb30I~
    cmdstr[1]=0;
    mousel_cmdline(Ppcw,cmdstr,"");
	*Pppft=functblsrch(FUNCID_EXECNL);
    return FUNCTYPE_PFK;
}//mousel_lineselect_topmenu
//*************************************************************
//*filename list line select
//*************************************************************
//int  mousel_lineselect_fnamelist(PUCLIENTWE Ppcw,int Pshiftsw,int Prow,FUNCTBL **Pppft)//~v64wR~
int  mousel_lineselect_fnamelist(PUCLIENTWE Ppcw,int Pshiftsw,int Prow,int Pcol,FUNCTBL **Pppft)//~v64wI~
{
//  UCHAR fnm[MAXCOLUMN];                                          //~v53BR~
    UCHAR fnm[_MAX_PATH+2];                                        //~v53BI~
    char cmdstr[2];                                                //~v53BI~
    int lcmd;
    int len;                                                       //~v53BI~
	int assocsw,openbyxesw;                                        //~v64wI~
//******************************
	if (Prow==PANL300DIR||Prow==PANL300CURRENT)                    //~v53BR~
    {                                                              //~v53BI~
        fnm[0]='"';                                                //~v53BI~
    	len=getfldinput(Ppcw,Prow,0,fnm+1);                        //~v53BI~
        if (!len)                                                  //~v53BI~
	    	return FUNCTYPE_IGN;                                   //~v53BI~
        *(fnm+1+len)='"';                                          //~v53BI~
        *(fnm+1+len+1)=0;                                          //~v53BI~
//  	cmdstr[0]=mousel_belcmd(Ppcw,Pshiftsw);                    //~v53BR~//+vb30R~
    	cmdstr[0]=(char)mousel_belcmd(Ppcw,Pshiftsw);              //+vb30I~
        cmdstr[1]=0;                                               //~v53BI~
	    return mousel_strcmd(cmdstr,fnm);                          //~v53BI~
    }                                                              //~v53BI~
	if (!(Prow>=PANL300LISTTOP && Prow<Ppcw->UCWmaxline))
    	return FUNCTYPE_IGN;
    getfldinput(Ppcw,Prow,PANL300NAME,fnm);
    if (!*fnm)		//not filled
    	return FUNCTYPE_IGN;
    openbyxesw=!(Pcol>=OPENBYXE_HLPOS1 && Pcol<=OPENBYXE_HLPOS2);  //~v64wI~
    assocsw=0;                                                     //~v64wI~
  	if (!openbyxesw)                                               //~v64wI~
		assocsw=dlcmdassocchk_fnamelist(Ppcw);                     //~v64wI~
  if (assocsw)                                                     //~v64wI~
	lcmd=UDLCCMD_OPENWITH;                                         //~v64wI~
  else                                                             //~v64wI~
	lcmd=mousel_belcmd(Ppcw,Pshiftsw);
	mousel_charinput(Ppcw,Prow,0,lcmd);
    return FUNCTYPE_CHR;
}//mousel_lineselect_fnamelist
//*************************************************************
//*browse/edit
//*p3/p4:relative pos
//ret 1:cap copyed
//*************************************************************
int  mousel_lineselect_file(PUCLIENTWE Ppcw,int Pflag,int Prow,int Pcol,FUNCTBL **Pppft)
{
	PUSCRD  psd;
    PULINEH plh;
    PUFILEC pfc;
    int pos,funcid,rc=0;
//******************************
    if (Prow==CMDLINENO)                                           //~v56kR~
    	return mouselpathupdown(Ppcw,Pcol,Pppft);                  //~v56kR~
    if (!CSRONFILELINE(Ppcw))
	    return FUNCTYPE_IGN;
    pfc=Ppcw->UCWpfc;
    psd=Ppcw->UCWpsd;
    psd+=Prow;
    plh=psd->USDbuffc;
    if (!plh)
    	return FUNCTYPE_IGN;
    if (plh->ULHtype==ULHTHDR)
    	return FUNCTYPE_IGN;
    capreset(1);	//reset if pendig C & P
    if (Pcol<(int)Ppcw->UCWlinenosz)	//lineno col;line mode
    {
        rc=func_block_file(Ppcw);			//line start
        if (!rc)
        {
            capsavecsrpos(Ppcw);
            caplinechk(Ppcw,plh);
	        rc=func_block_file(Ppcw);			//line start
            if (!rc)
            {
	            capsavecsrpos(Ppcw);
	            caplinechk(Ppcw,plh);
        		funcid=FUNCID_COPYTOCB;			//field cap
            }
        }
    }
    else 		//cs is on file data
    {
    	pos=pfc->UFCleft+Pcol-Ppcw->UCWlinenosz;
        if (pos<plh->ULHlen)
        	funcid=FUNCID_COPYWORD;			//field cap
        else                                                       //~vafeR~
        	rc=4;     //invalid key combination err msg            //~vafeR~
    }
    if (rc)
    	rc=FUNCTYPE_ERR;
    else
    {
		*Pppft=functblsrch(funcid);
	    rc=FUNCTYPE_PFK;
    }
    return rc;
}//mousel_lineselect_file
//*************************************************************
//*top menu line select
//*************************************************************
//int  mousel_lineselect_dirlist(PUCLIENTWE Ppcw,int Pshiftsw,int Prow,FUNCTBL **Pppft)//~v56kR~
int  mousel_lineselect_dirlist(PUCLIENTWE Ppcw,int Pshiftsw,int Prow,int Pcol,FUNCTBL **Pppft)//~v56kI~
{
    int lcmd;
	int assocsw=0,openbyxesw;                                      //~v64wI~
//***********************
	if (Prow==CMDLINENO)                                           //~v56kR~
    	return mouselpathupdown(Ppcw,Pcol,Pppft);                  //~v56kR~
    if (!CSRONFILELINE(Ppcw))
	    return FUNCTYPE_IGN;
    openbyxesw=!(Pcol>=OPENBYXE_DLPOS1 && Pcol<=OPENBYXE_DLPOS2);  //~v64wI~
	if (!openbyxesw)                                               //~v64wI~
		assocsw=dlcmdassocchk_dirlist(Ppcw);                       //~v64wI~
  if (assocsw)                                                     //~v64wI~
	lcmd=UDLCCMD_OPENWITH;                                         //~v64wI~
  else                                                             //~v64wI~
	lcmd=mousel_belcmd(Ppcw,Pshiftsw);
	mousel_charinput(Ppcw,Prow,0,lcmd);
	mousel_strcmd("ENT","");			//exec after char input
    return FUNCTYPE_CHR;               //char input(dlcmd save)
}//mousel_lineselect_dirlist
//*************************************************************    //~v63nI~
//*top menu line select                                            //~v63nI~
//*************************************************************    //~v63nI~
int  mousel_linedrag_dirlist(PUCLIENTWE Ppcw,int Pshiftsw,int Prow,int Pcol)//~v63nI~
{                                                                  //~v63nI~
	PULINEH plh;                                                   //~v63nR~
    int dragchkrc;                                                 //~v63nI~
//***********************                                          //~v63nI~
    if (dragchkrc=mousel_dragselectchk(Pshiftsw,Prow,Pcol,Ppcw,&plh),dragchkrc)//~v63nR~
    {                                                              //~v63nI~
    	mousel_dragfile(dragchkrc,Ppcw,plh);                       //~v63nI~
        return 0;   //processed                                    //~v63nI~
    }                                                              //~v63nI~
    return 1;	//continue                                         //~v63nI~
}//mousel_linedrag_dirlist                                         //~v63nI~
//*************************************************************    //~v63nI~
//*drag option chk/drag pending chk                                //~v63nI~
//*************************************************************    //~v63nI~
int  mousel_dragselectchk(int Pflag,int Prow,int Pcol,PUCLIENTWE Ppcw,PULINEH *Ppplh)//~v63nR~
{                                                                  //~v63nI~
	int  rc=0,row;                                                 //~v63nR~
	PUSCRD  psd;                                                   //~v63nI~
    PULINEH plh;                                                   //~v63nI~
//  PUFILEC pfc;                                                   //~v63nI~//~vaa7R~
//  PUFILEH pfh;                                                   //~v63nI~//~vaa7R~
//***********************                                          //~v63nI~
    row=Ppcw->UCWrcsry;                                            //~v63nI~
    if (!(row>=Ppcw->UCWfilehdrlineno && row<Ppcw->UCWmaxline))    //~v63nI~
    	return 0;                                                  //~v63nI~
//  pfc=Ppcw->UCWpfc;                                              //~v63nR~//~vaa7R~
//  pfh=pfc->UFCpfh;                                               //~v63nI~//~vaa7R~
    psd=Ppcw->UCWpsd;                                              //~v63nR~
    psd+=row;                                                      //~v63nI~
    plh=psd->USDbuffc;                                             //~v63nI~
    if (!plh)                                                      //~v63nI~
    	return 0;                                                  //~v63nI~
    if (Ppplh)                                                     //~v63nI~
	    *Ppplh=plh;                                                //~v63nI~
//  if (Pflag & UKBDLNXC_MOD_CONTROL)        //with control key    //~v63nR~
//      rc=DRAGCHK_ADD;                                            //~v63nR~
//  else                                                           //~v63nR~
//      if (Pflag & (UKBDLNXC_MOD_SHIFTL|UKBDLNXC_MOD_SHIFTR))       //range//~v63nR~
//          rc=DRAGCHK_RANGE;       //from prev entry              //~v63nR~
//      else                                                       //~v63nR~
            rc=DRAGCHK_NEW;         //                             //~v63nI~
    return rc;                                                     //~v63nI~
}//mousel_dragselectchk                                            //~v63nI~
//===============================================================================//~v63nI~
//add file to drag filename list                                   //~v63nI~
//===============================================================================//~v63nI~
int mousel_dragfile(int Pdragopt,PUCLIENTWE Ppcw,PULINEH Pplh)     //~v63nI~
{                                                                  //~v63nI~
	PULINEH plh1,plh2;                                             //~v63nI~
	PUFILEH pfh;                                                   //~v63nI~
//************************************                             //~v63nI~
	pfh=UGETPFHFROMPCW(Ppcw);                                      //~v63nI~
    if	(Pdragopt & DRAGCHK_NEW)                                   //~v63nI~
    {                                                              //~v63nI~
	    dlcmddndreset(Ppcw);                                       //~v63nI~
        plh1=plh2=Pplh;                                            //~v63nI~
//      Sdragplhs=Pplh;                                            //~v63nR~
    	dlcmddndset(Ppcw,pfh,plh1,plh2);                           //~v63nI~
    }                                                              //~v63nI~
//  else                                                           //~v63nR~
//  if	(Pdragopt & DRAGCHK_ADD)                                   //~v63nR~
//  {                                                              //~v63nR~
//      plh1=plh2=Pplh;                                            //~v63nR~
//      Sdragplhs=Pplh;                                            //~v63nR~
//  }                                                              //~v63nR~
//  else	//range                                                //~v63nR~
//  {                                                              //~v63nR~
//  	if (Sdragplhs)                                             //~v63nR~
//      {                                                          //~v63nR~
//      	plh1=Sdragplhs;                                        //~v63nR~
//          Sdragplhs=0;                                           //~v63nR~
//      }                                                          //~v63nR~
//      else                                                       //~v63nR~
//      	plh1=Pplh;                                             //~v63nR~
//      plh2=Pplh;                                                 //~v63nR~
//  }                                                              //~v63nR~
//  dlcmddndset(Ppcw,pfh,plh1,plh2);                               //~v63nR~
    return 0;                                                      //~v63nI~
}//mousedragfile                                                   //~v63nI~
//*************************************************************    //~v53BI~
//*cap copy                                                        //~v53BI~
//*ret 1:active changed                                            //~v53BI~
//*************************************************************    //~v53BI~
int  mousel_cappaste(PUCLIENTWE Ppcw,int Pinssw,int Pcol,int Prow,FUNCTBL **Pppft)//~v53BI~
{                                                                  //~v53BI~
    PUCLIENTWE pcw;                                                //~v53BI~
	int funcid;                                                    //~v53BR~
//**********************                                           //~v53BI~
    scrcpgetpcw(Prow,Pcol,&pcw);                                   //~v53BI~
	if (Pinssw)                                                    //~v53BI~
    	funcid=FUNCID_BLOCKINS;                                    //~v53BI~
    else                                                           //~v53BI~
    	funcid=FUNCID_BLOCKREP;                                    //~v53BI~
    *Pppft=functblsrch(funcid);                                    //~v53BI~
    return FUNCTYPE_PFK;                                           //~v53BI~
}//mousel_cappaste                                                 //~v53BI~
//*************************************************************
//*tell charset changed
//*ret 1:active changed
//*************************************************************
int  mousel_movecsr(int Prow,int Pcol)
{
//***********************
    Gkbdinpctr++;		//tc cmd block specification is continued alt+f7 key.avoid it.
	scrsetcsrpos(Prow,Pcol);	//1 if inactive pcw
    return 1;
}//mousel_movecsr
//*************************************************************
//*pass edit cmd
//*************************************************************
int mousel_strcmd(char *Pcmd,char *Pparm)
{
//***********************
    sprintf(Gcmdbuff,"%s %s",Pcmd,Pparm);
    return FUNCTYPE_CMD;
}//mousel_strcmd
//*************************************************************
//*pass edit cmd
//*************************************************************
int mousel_cmdline(PUCLIENTWE Ppcw,char *Pcmd,char *Pparm)
{
	char cmdbuff[MAXCOLUMN];
//***********************
    sprintf(cmdbuff,"%s %s",Pcmd,Pparm);
	csronthefld(Ppcw,CMDLINENO,0,0);
	setflddata(Ppcw,CMDLINENO,0,cmdbuff);
    return 0;
}//mousel_cmdline                                                  //~v53BR~
//*************************************************************
//*lcmd input
//*************************************************************
int  mousel_belcmd(PUCLIENTWE Ppcw,int Pshiftsw)
{
	int lcmd;
    PUFILEC pfc;
//****************************
	pfc=Ppcw->UCWpfc;
    if (Pshiftsw)   //reverse edit/browse
    {
    	if (Ppcw->UCWtype==UCWTDIR)
			if (!UCBITCHK(pfc->UFCflag,UFCFDEDIT))   //dir list by edit cmd
                lcmd='e';
            else
                lcmd='b';
        else  				//filename list
            if (Ppcw->UCWmenuopt==PANMOBROWSE)
                lcmd='e';
            else
                lcmd='b';
    }
    else
    {
    	if (Ppcw->UCWtype==UCWTDIR)
			if (!UCBITCHK(pfc->UFCflag,UFCFDEDIT))   //dir list by edit cmd
                lcmd='b';
            else
                lcmd='e';
        else  				//filename list
            if (Ppcw->UCWmenuopt==PANMOBROWSE)
                lcmd='b';
            else
                lcmd='e';
    }
    return lcmd;
}//mousel_belcmd
//*************************************************************
//*char input simulation
//*************************************************************
int  mousel_charinput(PUCLIENTWE Ppcw,int Prow,int Pcol,int Pchar)
{
//****************************
	csronthefld(Ppcw,Prow,Pcol,0);	//
	Ppcw->UCWkeytype=UCWKTSBCS;		//key type
//  *Ppcw->UCWkeydata=Pchar;		//key data SBCS                //+vb30R~
    *Ppcw->UCWkeydata=(UCHAR)Pchar;		//key data SBCS            //+vb30I~
	*(Ppcw->UCWkeydata+1)=0;		//key data SBCS
    return 0;
}//mousel_charinput
//*************************************************************    //~v56kR~
//*lcmd input                                                      //~v56kR~
//*************************************************************    //~v56kR~
int  mouselpathupdown(PUCLIENTWE Ppcw,int Pcol,FUNCTBL **Pppft)    //~v56kR~
{                                                                  //~v56kR~
	int funcid,width;                                              //~v56kR~
//****************************                                     //~v56kR~
	if (Pcol>=DPUCOLS && Pcol<=DPUCOLE)                            //~v56kR~
    	funcid=FUNCID_PATHUP;                                      //~v56kR~
    else                                                           //~v56kR~
    {                                                              //~v56kR~
    	width=Ppcw->UCWwidth;                                      //~v56kR~
        if (Pcol>=(width-DPDCOLS) && Pcol<=(width-DPDCOLE))        //~v56kR~
            funcid=FUNCID_PATHDOWN;                                //~v56kR~
        else                                                       //~v56kR~
	    	return FUNCTYPE_IGN;                                   //~v56kR~
    }                                                              //~v56kR~
	*Pppft=functblsrch(funcid);                                    //~v56kR~
    return FUNCTYPE_PFK;                                           //~v56kR~
}//mouselpathupdown                                                //~v56kR~
