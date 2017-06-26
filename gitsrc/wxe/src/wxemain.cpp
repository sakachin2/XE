//*CID://+vb4qR~:                             update#=  203;       //~vb4qR~
//******************************************************************************//~v003I~
//vb4q:160810 display ligature/combine mode on "TOP OF LINE"       //~vb4qI~
//vb20:160108 (Wxe:BUG)setup/preview dialog change waas not written to wxeini(put init even when cancel exit)//~vb20I~
//vak7:130906 redirect memcpy to memmove when overlaped            //~vak7I~
//va3g:100207 try ligature for also wxe(write ucs string at once) for arabic etc//~Va3gI~
//v7an:090111 (WXE)bgcolor/rular color back to default when set to all 0//~V7anR~
//v7ah:081120 (WXE:bug)helpmsg popup for each line                 //~V7ahI~
//v795:080723 (VC8)CWnd:Killtimer parameter changed from int to UINT(link fail)//~V795I~
//v780:080212 syntaxhighlight support (SYN cmd,C+s func key)       //~V780I~
//v76T:071023 (WXE) sticky crosshair cursor mode                   //~V76TI~
//v740:070201 (WXE/XXE)kde dose not report keypress event for S+C+F1;so use keyup event//~V740I~
//            so support specify trigger key on setupdialog        //~V740I~
//v73y:070128-(WXE/XXE)Quiet-exit support                          //~V73tI~
//v73t:070125 cross-hair ruler support by Shift+Ctl+lbuton         //~V73tI~
//v69Z:060726 (WXEXXE)sync C&P between PFkey and mouse operation.(update enable/disable menu by also Key operation)//~V69ZI~
//v69i:060523 (WXE)use pgleft/pgright also for elecom hscroll mouse(generate VK_SCROLL+VK_LEFT/VK_RIGHT+VK_SCROLL)//~V69iI~
//v69g:060521 (WXE)tilt wheel mouse generate WM_VSCROLL/WM_HSCROLL by mycrosoft spec//~V685I~
//            if scroll bar exist.(both vertical and horizontal is requred to genarate both)//~V685I~
//v685:060322 dnd support "file copy into the dir slected" and even in inter-split-screen.//~V685I~
//v655:050725 (WXE) allow cellsz max is 0(no limit)                //~V655I~
//v63r:050525 ignore(no cursor move) 1st mouse click after killfocus//~V63rI~
//v63k:050509 (WXE)change mouse csr when dragout in progress       //~V63kI~
//v63h:050504 (WXE)support DragOut                                 //~V63hI~
//v62W:050422 (WXE)maximum cell height definition for small doc    //~V62WI~
//v560:040324 (WIN)break sleep by esc*2                            //~V560I~
//v55G:040315 (WXE)Beep option on setup dialog                     //~V55GI~
//v55q:040228 option to scroll by csr move(CSRSCROLL option)       //~V55qI~
//v55c:040208 (WXE)distingush L-CTL/R-CTL & report R-CTL           //~V55cI~
//v53q:030930 (WXE:BUG) area not freed when print canceled because endprinting is not called//~V53qI~
//v51h:030525 (WXE)col/row by font size specification              //~V510I~
//v510:030215 (WXE)parameterize interval for scroll by mouse       //~3215I~
//******************************************************************************//~v003I~
//                                                                 //~v003R~
#include    "StdAfx.h"                                             //~v003I~
#define NO_MACRO_REDIRECT                                          //~vak7I~
#include    <ulib.h>                                               //~vak7M~
#include    "wxedef.h"                                             //~v003I~
#include    "wxe.h"                                                //~2A10I~
#include    "wxefile.h"                                            //~v003M~
#include    "wxeDoc.h"                                             //~v003I~
#include    "wxexei.h"                                             //~V780M~
#include    "wxemain.h"                                            //~v003R~
#include    "mainfrm.h"                                            //~2A14I~
#include    "resource.h"                                           //~v003M~
#include    "wxedlg.h"                                             //~v003I~
#include    "wxeview.h"                                            //~v003I~
#include    "wxecsub.h"                                            //~v003I~
                                                                   //~2A12I~
#include    "utrace.h"                                             //~2A12M~
                                                                   //~2A12M~
//******************************************************************************//~v003I~
//******************************************************************************//~v003I~
//===============================================================================//~v003I~
//                                                                 //~v003I~
//===============================================================================//~v003I~
CWxemain::CWxemain()                                               //~v003R~
{                                                                  //~v003I~
//    HGDIOBJ obj;                                                 //~v003R~
//    CFont *pfont;                                                //~v003R~
//    LOGFONT lfont;                                               //~v003R~
	int ii;                                                        //~V780I~
//***********************                                          //~v003I~
	Mxeinitsw=0;                                                   //~v003I~
	Mbgcolor=DEF_BGCOLOR;	//default bg color                     //~v003R~
	Mrulercolor=DEF_RULERCOLOR;	//default bg color                 //~V73tI~
	strcpy(Mrulerkey,DEF_RULERKEY);	//default bg color             //~V740I~
	Mpfont=0;                                                      //~v003I~
    for (ii=WXEFONTSTYLE_NORMAL;ii<WXEFONTSTYLE_MAX;ii++)          //~V780R~
    {                                                              //~V780I~
	  	Mpfonts[ii]=0;                                             //~V780I~
    }                                                              //~V780I~
    Mcharinpup[0]=0;                                               //~v003R~
    Mcharinpdn[0]=0;                                               //~v003I~
    Mcharwp[0]=0;                                                  //~v003I~
    Mfontwidth=DEF_FONTSZW;                                        //~v003I~
    Mfontheight=DEF_FONTSZH;                                       //~v003I~
    Mcellw=DEF_COLW;                                               //~v003R~
    Mcellh=DEF_ROWH;                                               //~v003R~
    Mcharset=DEF_CHARSET;                                          //~v003I~
    Mothercharset=DEF_OTHERCHARSET;                                //~3102R~
    Mttfont=TRUE;                                                  //~v003I~
    Museact=0;   //default no accelerator                          //~3103R~
    Musemk =0;   //default no menukey                              //~3105I~
    Mrctl  =0;   //default no menukey                              //~V55cR~
//  if (wxe_iswinnt())                                             //~2C03R~
//  	strcpy(Mfontstyle,DEF_FONTSTYLE2);                         //~2C03R~
//  else                                                           //~2C03R~
    	strcpy(Mfontstyle,DEF_FONTSTYLE);                          //~2B30R~
//    obj=GetStockObject(ANSI_FIXED_FONT);                         //~v003R~
//    pfont=pfont->FromHandle((HFONT)obj);                         //~v003R~
//    pfont->GetLogFont(&lfont);;                                  //~v003R~
//    strncpy(Mfontstyle,lfont.lfFaceName,sizeof(Mfontstyle));     //~v003R~
//    obj=GetStockObject(HOLLOW_BRUSH);                            //~v003R~
//    Mphollowbrush=Mphollowbrush->FromHandle((HBRUSH)obj);        //~v003R~
    Mscrmaxrow=MAXROW;	//buff size                                //~v003I~
    Mscrmaxcol=MAXCOL;                                             //~v003M~
    Mscrcmaxrow=DEF_SCRROW;                                        //~v003I~
    Mscrcmaxcol=DEF_SCRCOL;                                        //~v003I~
	Mscrollctr =DEF_SCROLLCTR;                                     //~2A13I~
	Mscrolltimer=DEF_SCROLLTIMER;                                  //~V510R~
//  Mscrwidth=XX(Mscrcmaxrow);                                     //~V69gR~
//  Mscrheight=YY(Mscrcmaxcol);                                    //~V69gR~
    Mscrwidth=XX(Mscrcmaxcol);     //bug,no effect,reset by OnSize //~V69gI~
    Mscrheight=YY(Mscrcmaxrow);                                    //~V69gI~
    Mpmemdc=0;                                                     //~v003I~
    Mpbgbitmap=0;                                                  //~v003I~
    Mcpcopysw=0;                                                   //~v003R~
    Mcpcopypansw=0;                                                //~v003I~
    Mlbdblclicksw=0;                                               //~3202I~
    Mlbposid=0;                                                    //~3208I~
    Mimeonsw=0;                                                    //~3208I~
    Mcppastesw=0;                                                  //~v003I~
    Mfloatmenusw=0;                                                //~v003I~
    Mfulldrawsw=0;                                                 //~v003I~
    Mhcopysw=0;                                                    //~2B23R~
//    Mbm_caret[0].LoadBitmap(IDB_SBCSREP);                        //~v003R~
//    Mbm_caret[1].LoadBitmap(IDB_SBCSINS);                        //~v003R~
//    Mbm_caret[2].LoadBitmap(IDB_DBCSREP);                        //~v003R~
//    Mbm_caret[3].LoadBitmap(IDB_DBCSINS);                        //~v003R~
//page setup data                                                  //~2B03I~
	strcpy(Mformtype,DEF_FORMSIZE);                                //~2B09R~
	strcpy(Mprtfontstyle,DEF_PRTFONTSTYLE);                        //~V51hI~
	M2p=FALSE;                                                     //~2B03I~
	Mlandscape=FALSE;                                              //~2B03R~
	Mfullpage=FALSE;                                               //~2B30I~
	Mlinenumber=TRUE;                                              //~2B03M~
	Mfiletime=TRUE;                                                //~2B03I~
	Msystime=TRUE;                                                 //~2B03M~
	Mwwscrprt=TRUE;                                                //~2B10I~
	Mheader=TRUE;                                                  //~2B03I~
	Mfooter=TRUE;                                                  //~2B03M~
	Mprtcol=DEF_A4_COL;                                            //~2B03R~
	Mprtrow=DEF_A4_ROW;                                            //~2B03I~
	Mpfontszh=10;		//default fontszh                          //~V51hR~
	Mpfontszw=0;                                                   //~V51hI~
	Mpcellszh=0;		//default cellszh ;0:same as fontsz        //~V51hR~
	Mpcellszhmax=DEF_CELLSZHMAX;	//default max cellszh          //~V62WI~
	Mpcellszw=0;                                                   //~V51hI~
	Mchkpfontsz=0;                                                 //~V51hI~
	Mprt2pcol=DEF_2PCOL;                                           //~2B04I~
	Mmarginl=0;                                                    //~2B03I~
	Mmarginr=0;                                                    //~2B03I~
	Mmargint=0;                                                    //~2B03I~
	Mmarginb=0;                                                    //~2B03M~
	Mnewimephrase=0;                                               //~3104R~
    Mprtlinework=0;     //init for free chk at afterprint          //~V53qI~
    Mprtpagework=0;     //init for free chk at afterprint          //~V53qI~
    Mpprtfont=0;        //init for free chk at afterprint          //~V53qI~
//  Mdragplhs=0;        //dragdrop start range                     //~V63kR~
    Mswkillfocus=0;     //killfocus msg drived sw                  //~V63rI~
    Mdragstatus=0;                                                 //~V685I~
    Mscrollcode=-1;                                                //~V69gR~
    Mscrolllocksw=0;    //VK_SCROLL off                            //~V69iR~
    wxemouse_capi(WXEM_INIT,this);  //to reset Mcpcopysw from xe   //~V69ZR~
    Mrulermode=Mrulermodeo=WXERULER_NONE;                          //~V73tR~
    Mrulerrow=Mrulercol=0;                                         //~V73tR~
    Mprinterinit=0;                                                //~@@@@I~
//page setup data end                                              //~2B03I~
}//CWxemain()                                                      //~v003I~
//===============================================================================//~v003I~
//                                                                 //~v003I~
//===============================================================================//~v003I~
CWxemain::~CWxemain()                                              //~v003R~
{                                                                  //~v003I~
}                                                                  //~v003I~
//===============================================================================//~v003I~
//                                                                 //~v003I~
//===============================================================================//~v003I~
int CWxemain::init(CView *Ppview)                                  //~v003R~
{                                                                  //~v003I~
	CDC tempdc;                                                    //~v003I~
//    HBITMAP hbm[4];                                              //~v003R~
//*******************                                              //~v003I~
    Mpview=Ppview;                                                 //~v003R~
    Mpmainframe=((CWxeView*)Ppview)->Mpmainframewnd;               //~2A14R~
    ((CMainFrame*)Mpmainframe)->frmsetxemain(this);	//tell to mainfrm//~2A14R~
    Mpdoc=Ppview->GetDocument();                                   //~2A08R~
    Mpwxefile=&((CWxeDoc*)Mpdoc)->Mwxefile;                        //~v003R~
//    hbm[0]=(HBITMAP)Mbm_caret[0].m_hObject;                      //~v003R~
//    hbm[1]=(HBITMAP)Mbm_caret[1].m_hObject;                      //~v003R~
//    hbm[2]=(HBITMAP)Mbm_caret[2].m_hObject;                      //~v003R~
//    hbm[3]=(HBITMAP)Mbm_caret[3].m_hObject;                      //~v003R~
    iniget();                                                      //~2A19M~
    wxe_onsize(Mscrcmaxrow,Mscrcmaxcol,0);	//init                 //~2A19M~
    wxe_setcharset(1,Mcharset);		//init                         //~2A19M~
	csubinit1(Ppview->m_hWnd);                                     //~v003R~
	scrinit();                                                     //~v003I~
	xeinitcall();                                                  //~v003R~
    Mpwxefile->Mxeinitsw=1;                                        //~2A08R~
    return 0;                                                      //~v003I~
}//init                                                            //~v003R~
//********************************************                     //~vb4qM~
void CWxemain::optligatureinit(int Popt)                           //~vb4qR~
{                                                                  //~vb4qM~
//************************                                         //~vb4qM~
	if (Mligature)                                                 //~vb4qM~
		Mwxeintf.WXEIstatus|=WXEIS_LIGATURE;                       //~vb4qM~
    else                                                           //~vb4qM~
	    Mwxeintf.WXEIstatus&=~WXEIS_LIGATURE;                      //+vb4qR~
}//optligatureinit                                                 //~vb4qI~
//===============================================================================//~v003M~
//ret:rc                                                           //~v003R~
//===============================================================================//~v003M~
int CWxemain::xeinitcall()                                         //~v003R~
{                                                                  //~v003M~
    int rc;                                                        //~2A07I~
//**********************                                           //~2A07I~
	memset(&Mwxeintf,0,sizeof(Mwxeintf));                          //~v003M~
    Mwxeintf.WXEImaxrow=Mscrmaxrow;                                //~v003R~
    Mwxeintf.WXEImaxcol=Mscrmaxcol;                                //~v003R~
    memset(Mwxeintf.WXEIpallette,0,sizeof(Mwxeintf.WXEIpallette)); //~v003R~
    for (int ii=0;ii<__argc;ii++)                                  //~2A12M~
    	UTRACEP("cmd parm %d=%s\n",ii,__targv[ii]);                //~2A12M~
    optligatureinit(0);                                            //~vb4qR~
	rc=wxe_xecall(WXE_REQ_INIT,&Mwxeintf,__argc,__targv);          //~2A07R~
        xeerrchk();     //errmsg msg display                       //~2A12R~
    if (rc==-1)                                                    //~2A07I~
    {                                                              //~V7ahI~
    	exitmain();                                                //~2A07I~
		exit(4);                                                   //~V7ahI~
    }                                                              //~V7ahI~
    Mxeinitsw=1;		//init called                              //~v003I~
//  wxe_optligature(WXEIOLO_CHNGDIALOGOPT,Mligature);              //~vb4qR~
	csubinit2(Mcellh,Mcellw);                                      //~v003M~
    return 0;                                                      //~v003I~
}//xeinitcall()                                                    //~v003M~
//===============================================================================//~v003I~
//ret:rc                                                           //~v003I~
//===============================================================================//~v003I~
int CWxemain::xeerrchk()                                           //~v003I~
{                                                                  //~v003I~
	int rc=0;                                                      //~v003I~
//*****************************                                    //~v003I~
	if (Mwxeintf.WXEIerrmsg)                                       //~v003I~
    {                                                              //~v003I~
    	Mpview->MessageBox(Mwxeintf.WXEIerrmsg,NULL,MB_OK);        //~v003I~
    	free(Mwxeintf.WXEIerrmsg);                                 //~v003I~
    	Mwxeintf.WXEIerrmsg=0;                                     //~v003I~
        rc=4;                                                      //~v003R~
    }                                                              //~v003I~
    return rc;                                                     //~v003I~
}//xeerrchk                                                        //~v003I~
//===============================================================================//~v003M~
//                                                                 //~v003M~
//===============================================================================//~v003M~
int  CWxemain::OnOk()                                              //~v003M~
{                                                                  //~v003M~
	int cpchngsw;                                                  //~v003I~
//************************************                             //~v003M~
    if (!Mxeinitsw)		//init called                              //~v003R~
    	return 0;                                                  //~v003I~
	csubinit2(Mcellh,Mcellw);                                      //~v003R~
	cpchngsw=wxe_setcharset(0,Mcharset);	//tell eng/jap changed //~v003R~
    ((CMainFrame*)Mpmainframe)->Loadact(Museact);	//load/delete if changed//~3105R~
    ((CMainFrame*)Mpmainframe)->updatemainmenu(Musemk);	//load/delete if changed//~3105I~
    wxe_setrctl(Mrctl);	//issue opt rctl cmd                       //~V55cR~
    wxe_setfreecsr(Mfreecsr);	//issue opt rctl cmd               //~V55qI~
    wxe_setbeep(Mbeep);                                            //~V55GI~
	wxe_optligature(WXEIOLO_CHNGDIALOGOPT,Mligature);              //~Va3gR~
	scronok(cpchngsw);                                             //~v003R~
    return 1;                                                      //~v003I~
}//OnOk                                                            //~v003M~
//===============================================================================//~v003I~
//get ini file on work dir                                         //~v003I~
//===============================================================================//~v003I~
int  CWxemain::iniget()                                            //~v003I~
{                                                                  //~v003I~
    WXEINIDATA wxei;                                               //~2A20I~
//************************************                             //~v003I~
	wxei=((CMainFrame*)Mpmainframe)->Mwxeinidata;	//mainfrm read inital//~2A20R~
                                                                   //~2A19I~
	if (!wxei.WXEINIver) //read success at mainfrm                 //~2A20R~
    	return 4;                                                  //~2A19I~
	if (*wxei.WXEINIfontstyle) //font style                        //~2A20R~
		strcpy(Mfontstyle,wxei.WXEINIfontstyle); //font style      //~2A20R~
	if (wxei.WXEINIcmaxrow)	//current row count                    //~2A20R~
		Mscrcmaxrow  =wxei.WXEINIcmaxrow;                          //~2A20R~
	if (wxei.WXEINIcmaxcol)	//current col count                    //~2A20R~
		Mscrcmaxcol  =wxei.WXEINIcmaxcol;                          //~2A20R~
	if (wxei.WXEINIcellh)	//cell height                          //~2A20R~
		Mcellh       =wxei.WXEINIcellh;	//cell height              //~2A20R~
	if (wxei.WXEINIcellw)	//cell width                           //~2A20R~
		Mcellw       =wxei.WXEINIcellw;	//cell width               //~2A20R~
//  if (wxei.WXEINIcharset)	//font charset(0 for ansi)             //~2A20R~
		Mcharset     =wxei.WXEINIcharset;                          //~2A20R~
    if (wxei.WXEINIothercharset)                                   //~3102I~
		Mothercharset     =wxei.WXEINIothercharset;                //~3102I~
	if (wxei.WXEINIfontheight)	//char height                      //~2A20R~
		Mfontheight  =wxei.WXEINIfontheight;	//char height      //~2A20R~
	if (wxei.WXEINIfontheight)	//char height                      //~2C14I~
		Mfontwidth   =wxei.WXEINIfontwidth;	//char width           //~2C14I~
//  if (wxei.WXEINIbgcolor)//background color                      //~2A20R~//~V7anR~
		Mbgcolor     =wxei.WXEINIbgcolor;//background color        //~2A20R~
//  if (wxei.WXEINIrulercolor)//ruler color                        //~V73tI~//~V7anR~
		Mrulercolor     =wxei.WXEINIrulercolor;//background color  //~V73tI~
	if (*wxei.WXEINIrulerkey)//ruler color                         //~V740I~
		memcpy(Mrulerkey,wxei.WXEINIrulerkey,sizeof(Mrulerkey));   //~V740R~
	if (wxei.WXEINIscrollctr)//background color                    //~2A20R~
		Mscrollctr   =wxei.WXEINIscrollctr;//background color      //~2A20R~
	if (wxei.WXEINIscrolltimer)                                    //~V510R~
		Mscrolltimer =wxei.WXEINIscrolltimer;//background color    //~V510R~
	Mttfont=wxei.WXEINIttfont;                                     //~2A20R~
	Museact=wxei.WXEINIuseact;                                     //~3103I~
	Musemk =wxei.WXEINIusemk ;                                     //~3105I~
//*page setup data                                                 //~2B03I~
	if (*wxei.WXEINIformsize)                                      //~V51hI~
	strncpy(Mformtype,wxei.WXEINIformsize,sizeof(Mformtype));      //~2B09R~
	if (*wxei.WXEINIprtfontstyle)                                  //~V51hR~
		strncpy(Mprtfontstyle,wxei.WXEINIprtfontstyle,sizeof(Mprtfontstyle));//~V51hI~
    Mlandscape   =wxei.WXEINIlandscape ;                           //~2B03I~
    Mfullpage    =wxei.WXEINIfullpage  ;                           //~2B30I~
    Mlinenumber  =wxei.WXEINIlinenmber ;                           //~2B03I~
    M2p          =wxei.WXEINI2p        ;                           //~2B03I~
    Mheader      =wxei.WXEINIheader    ;                           //~2B03I~
    Mfooter      =wxei.WXEINIfooter    ;                           //~2B03I~
    Mfiletime    =wxei.WXEINIfiletime  ;                           //~2B03I~
    Msystime     =wxei.WXEINIsystime   ;                           //~2B03I~
    Mwwscrprt    =wxei.WXEINIwwscrprt  ;                           //~2B10I~
    Mprtcol      =wxei.WXEINIprtcol    ;                           //~2B03I~
    Mprtrow      =wxei.WXEINIprtrow    ;                           //~2B03I~
    Mprt2pcol    =wxei.WXEINIprt2pcol  ;                           //~2B04I~
    Mmarginl     =wxei.WXEINIleft      ;                           //~2B03I~
    Mmarginr     =wxei.WXEINIright     ;                           //~2B03I~
    Mmargint     =wxei.WXEINItop       ;                           //~2B03I~
    Mmarginb     =wxei.WXEINIbottom    ;                           //~2B03I~
    Mchkpfontsz  =wxei.WXEINIchkpfontsz;                           //~V51hI~
	if (wxei.WXEINIpfontszh)                                       //~V51hI~
	    Mpfontszh    =wxei.WXEINIpfontszh;                         //~V51hR~
    Mpfontszw    =wxei.WXEINIpfontszw;                             //~V51hI~
	if (wxei.WXEINIpcellszh)                                       //~V51hI~
	    Mpcellszh    =wxei.WXEINIpcellszh;                         //~V51hI~
//	if (wxei.WXEINIpcellszhmax)                                    //~V655R~
	    Mpcellszhmax =wxei.WXEINIpcellszhmax;                      //~V62WI~
    Mpcellszw    =wxei.WXEINIpcellszw;                             //~V51hI~
//*page setup data end                                             //~2B03I~
  	if (wxei.WXEINIsetflag & WXEINIF_OPT_QEXIT)                    //~V73tI~
    	wxe_setqexit(1);                                           //~V73tI~
  	if (wxei.WXEINIsetflag & WXEINIF_OPT_LIGATURE)                 //~Va3gI~
    	Mligature=1;                                               //~Va3gI~
    else                                                           //~Va3gI~
    	Mligature=0;                                               //~Va3gI~
    Mrulermode=(wxei.WXEINIsetflag & WXEINIF_OPT_RULER)>>8;        //~V76TI~
    return 0;                                                      //~v003I~
}//iniget                                                          //~v003I~
//===============================================================================//~v003I~
//save ini data(write at mainframe close)                          //~2A19R~
//===============================================================================//~v003I~
int  CWxemain::iniput(WXEINIDATA *Pwxei)                           //~2A20R~
{                                                                  //~v003I~
//************************************                             //~v003I~
	Pwxei->WXEINIver         =WXE_VER;                             //~2A20R~
	strcpy(Pwxei->WXEINIfontstyle,Mfontstyle);                     //~2A20R~
	Pwxei->WXEINIcmaxrow     =Mscrcmaxrow;//current row            //~3102R~
	Pwxei->WXEINIcmaxcol     =Mscrcmaxcol;//current col            //~3102R~
	Pwxei->WXEINIcellh       =Mcellh;	//cell height              //~3102R~
	Pwxei->WXEINIcellw       =Mcellw;	//cell width               //~3102R~
	Pwxei->WXEINIcharset     =Mcharset;  //cell width              //~3102R~
	Pwxei->WXEINIothercharset=Mothercharset;  //cell width         //~3102I~
	Pwxei->WXEINIfontheight  =Mfontheight;	//char height          //~3102R~
	Pwxei->WXEINIfontwidth   =Mfontwidth;	//char height          //~3102R~
	Pwxei->WXEINIbgcolor     =Mbgcolor;//background color          //~3102R~
	Pwxei->WXEINIrulercolor  =Mrulercolor;//ruler color            //~V73tI~
	memcpy(Pwxei->WXEINIrulerkey,Mrulerkey,sizeof(Mrulerkey));     //~V740I~
	Pwxei->WXEINIscrollctr   =Mscrollctr;                          //~3102R~
	Pwxei->WXEINIscrolltimer =Mscrolltimer;                        //~V510R~
	Pwxei->WXEINIttfont      =Mttfont;                             //~3102R~
	Pwxei->WXEINIuseact      =Museact;                             //~3103I~
	Pwxei->WXEINIusemk       =Musemk ;                             //~3105I~
//*page setup data                                                 //~2B03I~
	strncpy(Pwxei->WXEINIformsize,Mformtype,sizeof(Pwxei->WXEINIformsize));//~2B09R~
	strncpy(Pwxei->WXEINIprtfontstyle,Mprtfontstyle,sizeof(Pwxei->WXEINIprtfontstyle));//~V51hI~
    Pwxei->WXEINIlandscape=Mlandscape;                             //~2B03I~
    Pwxei->WXEINIfullpage =Mfullpage ;                             //~2B30I~
    Pwxei->WXEINIlinenmber=Mlinenumber;                            //~2B03I~
    Pwxei->WXEINI2p 	  =M2p;                                    //~2B10R~
    Pwxei->WXEINIheader   =Mheader;                                //~2B10R~
    Pwxei->WXEINIfooter   =Mfooter;                                //~2B10R~
    Pwxei->WXEINIfiletime =Mfiletime;                              //~2B10R~
    Pwxei->WXEINIsystime  =Msystime;                               //~2B10R~
    Pwxei->WXEINIwwscrprt =Mwwscrprt;                              //~2B10I~
    Pwxei->WXEINIprtcol   =Mprtcol;                                //~2B10R~
    Pwxei->WXEINIprt2pcol =Mprt2pcol;                              //~2B10R~
    Pwxei->WXEINIprtrow   =Mprtrow;                                //~2B10R~
    Pwxei->WXEINIleft     =Mmarginl;                               //~2B10R~
    Pwxei->WXEINIright    =Mmarginr;                               //~2B10R~
    Pwxei->WXEINItop      =Mmargint;                               //~2B10R~
    Pwxei->WXEINIbottom   =Mmarginb;                               //~2B10R~
    Pwxei->WXEINIchkpfontsz=Mchkpfontsz;                           //~V51hI~
    Pwxei->WXEINIpfontszh =Mpfontszh;                              //~V51hR~
    Pwxei->WXEINIpfontszw =Mpfontszw;                              //~V51hI~
    Pwxei->WXEINIpcellszh =Mpcellszh;                              //~V51hI~
    Pwxei->WXEINIpcellszhmax =Mpcellszhmax;                        //~V62WI~
    Pwxei->WXEINIpcellszw =Mpcellszw;                              //~V51hI~
//*page setup data end                                             //~2B03I~
    if (wxe_getqexit())                                            //~V73tR~
  		Pwxei->WXEINIsetflag|=WXEINIF_OPT_QEXIT;                   //~V73tI~
    else                                                           //~V73tI~
  		Pwxei->WXEINIsetflag&=~WXEINIF_OPT_QEXIT;                  //~V73tI~
    if (Mligature)                                                 //~Va3gI~
  		Pwxei->WXEINIsetflag|=WXEINIF_OPT_LIGATURE;                //~Va3gI~
    else                                                           //~Va3gI~
  		Pwxei->WXEINIsetflag&=~WXEINIF_OPT_LIGATURE;               //~Va3gI~
    Pwxei->WXEINIsetflag&=~WXEINIF_OPT_RULER;  	//clear old ruler mode//~V76TI~
    Pwxei->WXEINIsetflag|=((Mrulermode<<8) & WXEINIF_OPT_RULER);   //~V76TR~
    return 0;                                                      //~2A19R~
}//iniput                                                          //~v003R~
//===============================================================================//~v003I~
//xe returned -1                                                   //~v003I~
//===============================================================================//~v003I~
void CWxemain::exitmain()                                          //~v003I~
{                                                                  //~v003I~
//************************************                             //~v003I~
    if (Mpmainframe)                                               //~2A19I~
    {                                                              //~vb20I~
    	((CMainFrame*)Mpmainframe)->Mswappexit=1;	//exit by appl action//~vb20I~
    	((CMainFrame*)Mpmainframe)->PostMessage(WM_SYSCOMMAND,SC_CLOSE,0);//~2A19R~
    }                                                              //~vb20I~
    else                                                           //~2A19I~
		exit(0);                                                   //~2A19R~
}//exitmain                                                        //~v003R~
//**************************************************************** //~V55GI~
//*atcmd timer process                                             //~V55GI~
//**************************************************************** //~V55GI~
int CWxemain::ontimeratcmd(UINT Pid)                               //~V55GI~
{                                                                  //~V55GI~
    int   ms,rc,apprc;                                             //~V55GR~
//****************************                                     //~V55GI~
//  Mscrolltimereventctr++; //timer                                //~V55GI~
//UTRACEP("scroll:ontimer posid=%x,Pid=%x,eventctr=%d\n",Mlbposid,Pid,Mscrolltimereventctr);//~V55GI~
	if (Pid & TID_ATCMDTIMER)	//timer expired from last cmd      //~V55GI~
//      Mpview->KillTimer(Pid);                                    //~V795R~
        ukilltimer(Pid);                                           //~V795I~
	if (Pid & TID_ATCMDDRAW) 	//msg draw req                     //~V55GI~
    {                                                              //~V55GI~
        wxe_timerreset(WXEAT_DRAW);                                //~V560R~
    	Mpview->Invalidate(FALSE);                                 //~V55GI~
	    return 0;                                                  //~V55GI~
    }                                                              //~V55GI~
	if (Pid & TID_ATCMDSLEEP) 	//sleep time                       //~V560I~
    {                                                              //~V560I~
        wxe_timerreset(WXEAT_SLEEPED);                             //~V560I~
    	Mpview->Invalidate(FALSE);                                 //~V560I~
	    return 0;                                                  //~V560I~
    }                                                              //~V560I~
	if (!Mwxeintf.WXEIatcmdstring)	//reset requested              //~V55GI~
	    return 0;                                                  //~V55GI~
  if (Pid & TID_SLEEPSUBCMP) 	//sleep time                       //~V560I~
  {                                                                //~V560I~
    	rc=Mwxeintf.WXEIsleepinmult-1;  //eventid when sleep subcmd detectede//~V560R~
    	Mwxeintf.WXEIsleepinmult=0;		//sleep subcmd processed   //~V560I~
        apprc=0;                                                   //~V560I~
  }                                                                //~V560I~
  else                                                             //~V560I~
    rc=wxe_atcmdctl(&apprc);      //execute 1 of mult cmd          //~V55GI~
    if (apprc==-1)                                                 //~V55GI~
    {                                                              //~V55GI~
        exitmain();                                                //~V55GI~
        return 0;                                                  //~V55GI~
    }                                                              //~V55GI~
    if (apprc>=4                                                   //~V560R~
    &&  !(Mwxeintf.WXEIatcmdopt & WXEAT_IGNOREERR))                //~V560I~
        wxe_timerreset(WXEAT_CMDER);//free saved                   //~V55GR~
    else                                                           //~V55GI~
    {                                                              //~V55GI~
        switch(rc)                                                 //~V55GI~
        {                                                          //~V55GI~
        case 0:		//middle of multi cmd                          //~V55GM~
//          Mpview->SetTimer(TID_ATCMD|TID_ATCMDTIMER,WXEAT_MULTCMDTIMER,NULL/*callback*/);//schedule next subcmd//~@@@@R~
            Mpview->SetTimer(TID_ATCMD|TID_ATCMDTIMER,WXEAT_MULTCMDTIMER);//schedule next subcmd//~@@@@I~
        	break;                                                 //~V55GM~
        case 1:		//end of 1st repeat                            //~V55GR~
        case 2:     //end of multi cmd in each repeat              //~V55GI~
            ms=Mwxeintf.WXEIatcmdintvl*1000;    //by millisec      //~V55GI~
//          Mpview->SetTimer(TID_ATCMD|TID_ATCMDTIMER,ms,NULL/*callback*/);//~@@@@R~
            Mpview->SetTimer(TID_ATCMD|TID_ATCMDTIMER,ms);         //~@@@@I~
        	break;                                                 //~V55GI~
        case 3:		//end of last repeat                           //~V55GR~
            wxe_timerreset(WXEAT_COMP);//free saved                //~V55GI~
        	break;                                                 //~V55GR~
        case 4:		//sleep subcmd                                 //~V560I~
        	break;                                                 //~V560I~
        }//sw                                                      //~V55GI~
    }                                                              //~V55GI~
    Mpview->Invalidate(FALSE);                                     //~V55GM~
    return 0;                                                      //~V55GR~
}//ontimeratcmd                                                    //~V55GI~
