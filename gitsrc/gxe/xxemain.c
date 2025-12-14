//*CID://+vbs4R~:                             update#=  279;       //~vbs4R~
//******************************************************************************//~v003I~
//vbs4:201023 (Bug) coding scr width/height exchanged              //~vbs4I~
//vb4q:160810 display ligature/combine mode on "TOP OF LINE"       //~vb4qI~
//var8:140127 gtk3 suppott                                         //~var8I~
//var1:140116 (Bug:gxe)when trace on,ending status may not be saved//~var1I~
//vamt:131015 (GtkPrint)accept minus value of margin to adjust origin for each printer's paper folder shift attachment.(case of that b5 origin is relativ to a4 origin)//~vamtI~
//vam7:130929 add print with ligature(also for gnomeprint)         //~vam7I~
//vam1:130915 sometime miss to initial screen drawing by the reason of cupsenumprinter lose control(all on main thread)//~vam1I~
//            and signal:onsize by resizehint intercept xxemain_init process;//~vam1I~
//            so call enumprinter after xxemaini init end          //~vam1I~
//vam0:130911 for distro removed gnome-print,use GTKprint          //~vam0I~
//va3d:100206 (LNX)toggle ligature temprary by A+";", change combine key A+"/"-->C+":"//~va3dI~
//va1M:091121 (LNX)ligature support;keep monospace for english lagature; Arabian ? I don't know.//~va1MI~
//v76T:071023 (WXE) sticky crosshair cursor mode                   //~v76TI~
//v76e:070618 (XXE)typematic support for R-Ctrl                    //~v76eI~
//v740:070201 (WXE/XXE)kde dose not report keypress event for S+C+F1;so use keyup event//~v740I~
//            so support specify trigger key on setupdialog        //~v740I~
//v73y:070128-(WXE/XXE)Quiet-exit support                          //~v73yI~
//v73t:070125 cross-hair ruler support by Shift+Ctl+lbuton         //~v73tI~
//v69i:060523 (WXEXXE)use pgleft/pgright also for elecom hscroll mouse(generate VK_SCROLL+VK_LEFT/VK_RIGHT+VK_SCROLL)//~v69iI~
//v685:060322 dnd support "file copy into the dir slected" and even in inter-split-screen.//~v685I~
//v667:050823 (XXE)add printer selection dropdown list(effective only for CUPS)//~v667I~
//vX01:050729 cellh/cellw=0 mean same as fonth/fontw               //~VX01I~
//vXXE:050611 new for XXE                                          //~VXXEI~
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
#include <stdlib.h>                                                //~var8R~
#include <string.h>                                                //~var8R~
#include <ctype.h>                                                 //~var8R~
#ifndef OPTGTK3                                                    //~var8R~
#include <gnome.h>                                                 //~VXXEI~
#else                                                              //~var8R~
#include <gtk/gtk.h>                                               //~var8R~
#include <gdk/gdkx.h>                                              //~var8R~
#endif                                                             //~var8R~
#ifndef NOPRINT                                                    //~vam0R~
	#ifdef GTKPRINT                                                //~vam0I~
	#else    //!GTKPRINT                                           //~vam0I~
#include <libgnomeprint/gnome-print.h>                             //~VXXEI~
#include <libgnomeprint/gnome-print-job.h>                         //~VXXEI~
	#endif   //!GTKPRINT                                           //~vam0I~
#endif                                                             //~vam0I~
                                                                   //~VXXE~//~VXXER~
#include    <ulib.h>                                               //~VXXEI~
#include    <utrace.h>                                             //~vam0I~
                                                                   //~VXXEI~
                                                                   //~VXXEI~
#include    "gxe.h"                                                //~var8R~
#define GBL_XXEMAIN                                                //~VXXEI~
#include    <xxedef.h>                                             //~VXXEI~
#include    <xxemain.h>                                            //~VXXER~
#include    <xxecsub.h>                                            //~VXXEM~
#include    <xxeres.h>                                             //~VXXEI~
#include    <xxexei.h>                                             //~VXXEI~
                                                                   //~VXXEI~
//#include    "gxe.h"                                              //~var8R~
#include    "gxemfrm.h"                                            //~VXXER~
#include    "gxedlg.h"                                             //~VXXEI~
#include    "gxepage.h"                                            //~VXXEI~
#include    "gxeview.h"                                            //~var8R~
                                                                   //~VXXEI~
                                                                   //~VXXEI~
//******************************************************************************//~v003I~
	int  iniget(void);        //ini file get                       //~VXXEI~
	int  xeerrchk(void);                                           //~VXXEI~
	int  xeinitcall(void);                                         //~VXXEI~
//******************************************************************************//~v003I~
//===============================================================================//~v003I~
//                                                                 //~v003I~
//===============================================================================//~v003I~
void xxemain_construct(void)                                       //~VXXER~
{                                                                  //~v003I~
//    HGDIOBJ obj;                                                 //~v003R~
//    CFont *pfont;                                                //~v003R~
//    LOGFONT lfont;                                               //~v003R~
//***********************                                          //~v003I~
	dprintf("xxemain_construct\n");                                //~var8R~
	Mxeinitsw=0;                                                   //~v003I~
	COLORCOPY(Mbgcolor,DEF_BGCOLOR);	//default bg color         //~VXXER~
	COLORCOPY(Mrulercolor,DEF_RULERCOLOR);	//default bg color     //~v73tI~
	strcpy(Mrulerkey,DEF_RULERKEY);	//default rulerkey             //~v740R~
//  Mpfont=0;                                                      //~VXXER~
    Mcharinpup[0]=0;                                               //~v003R~
    Mcharinpdn[0]=0;                                               //~v003I~
    Mcharwp[0]=0;                                                  //~v003I~
    Mfontwidth=DEF_FONTSZW;                                        //~v003I~
    Mfontheight=DEF_FONTSZH;                                       //~v003I~
    Mcellw=DEF_COLW;                                               //~v003R~
    Mcellh=DEF_ROWH;                                               //~v003R~
//  Mcharset=DEF_CHARSET;                                          //~VXXER~
//  Mothercharset=DEF_OTHERCHARSET;                                //~VXXER~
    Mttfont=TRUE;                                                  //~v003I~
    Museact=0;   //default no accelerator                          //~3103R~
    Musemk =0;   //default no menukey                              //~3105I~
    Mligature=0;                                                   //~va1MI~
    Mrctl  =0;   //default no menukey                              //~V55cR~
    strcpy(Mfontstyle,DEF_FONTSTYLE);                              //~VXXER~
    Mscrmaxrow=MAXROW;	//buff size                                //~v003I~
    Mscrmaxcol=MAXCOL;                                             //~v003M~
    Mscrcmaxrow=DEF_SCRROW;                                        //~v003I~
    Mscrcmaxcol=DEF_SCRCOL;                                        //~v003I~
	Mscrollctr =DEF_SCROLLCTR;                                     //~2A13I~
	Mscrolltimer=DEF_SCROLLTIMER;                                  //~V510R~
	Mdblclicktimer=DEF_DBLCLICKTIMER;                              //~VXXEI~
	Mtypematicdelay=DEF_TYPEMATICDELAY;                            //~v76eI~
	Mtypematicinterval=DEF_TYPEMATICINTERVAL;                      //~v76eI~
	Mtypematicchkinterval=DEF_TYPEMATICCHKINTERVAL;                //~v76eI~
//  Mscrwidth=XX(Mscrcmaxrow);                                     //~v003R~//~vbs4R~
//  Mscrheight=YY(Mscrcmaxcol);                                    //~v003R~//~vbs4R~
    Mscrwidth=XX(Mscrcmaxcol);                                     //~vbs4I~
    Mscrheight=YY(Mscrcmaxrow);                                    //~vbs4I~
//  Mpmemdc=0;                                                     //~VXXER~
//  Mpbgbitmap=0;                                                  //~VXXER~
    Mcpcopysw=0;                                                   //~v003R~
    Mcpcopypansw=0;                                                //~v003I~
    Mlbdblclicksw=0;                                               //~3202I~
    Mlbposid=0;                                                    //~3208I~
    Mimeonsw=0;                                                    //~3208I~
    Mcppastesw=0;                                                  //~v003I~
    Mfloatmenusw=0;                                                //~v003I~
    Mfulldrawsw=0;                                                 //~v003I~
    Mhcopysw=0;                                                    //~2B23R~
//page setup data                                                  //~2B03I~
	strcpy(Mformtype,DEF_FORMSIZE);                                //~2B09R~
	strcpy(Mprtfontstyle,DEF_PRTFONTSTYLE);                        //~V51hI~
	strcpy(Mprinter,DEF_PRINTER);                                  //~v667R~
	M2p=FALSE;                                                     //~2B03I~
	Mlandscape=FALSE;                                              //~2B03R~
	Mfullpage=FALSE;                                               //~2B30I~
	MprintLigature=FALSE;                                          //~vam7R~
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
//  Mprtlinework=0;     //init for free chk at afterprint          //~VXXER~
//  Mprtpagework=0;     //init for free chk at afterprint          //~VXXER~
//  Mpprtfont=0;        //init for free chk at afterprint          //~VXXER~
    Mswkillfocus=0;     //killfocus msg drived sw                  //~V63rI~
	Mdragtimeout=DEF_DRAGTIMEOUT;                                  //~VXXEI~
	Mxxemaininitsw=0;                                              //~VX01I~
    Mdroprc=-1;         //set no meaningfull drop r.c              //~v685I~
    Mscrolllocksw=0;    //VK_SCROLL off                            //~v69iI~
    Mrulermode=Mrulermodeo=WXERULER_NONE;                          //~v73tI~
    Mrulerrow=Mrulercol=0;                                         //~v73tI~
    dprintf("%s:xxemain_constructed,Mscrwidth=%d,Mscrheight=%d\n",UTT,Mscrwidth,Mscrheight);                              //~v69iR~//~vbs4R~
//page setup data end                                              //~2B03I~
}//xxemain_construct                                               //~VXXER~
//===============================================================================//~v003I~
//                                                                 //~v003I~
//===============================================================================//~v003I~
int xxemain_init(int Pswinigetfail)                                //~VXXER~
{                                                                  //~v003I~
//	CDC tempdc;                                                    //~VXXER~
//*******************                                              //~v003I~
    UTRACEP("xxemain_init\n");                                     //~vam0I~
//  Gpview=Ppview;                                                 //~VXXER~
//  Gpframe=((CWxeView*)Ppview)->Gpframewnd;                       //~VXXER~
//  ((CMainFrame*)Gpframe)->frmsetxemain(this);	//tell to mainfrm  //~VXXER~
//  Mpdoc=Ppview->GetDocument();                                   //~VXXER~
//  Mpwxefile=&((CWxeDoc*)Mpdoc)->Mwxefile;                        //~VXXER~
	if (!Pswinigetfail)                                            //~VXXEI~
	    iniget();                                                  //~VXXER~
	gxedlg_init();  //setup font(cellh/w fonth/w)                  //~VX01I~
    wxe_onsize(Mscrcmaxrow,Mscrcmaxcol,0);	//init                 //~VXXER~
//  wxe_setcharset(1,Mcharset);		//init                         //~VXXER~
#ifndef OPTGTK3                                                    //~var8R~
	csubinit1(Gpview->window);                                     //~VXXER~
#else                                                              //~var8R~
	csubinit1(gtk_widget_get_window(Gpview));                      //~var8R~
#endif                                                             //~var8R~
	xxemain_kbdinit();                                             //~VXXEI~
#ifndef NOPRINT                                                    //~vam0I~
	gxepage_init();                                                //~VXXEI~
#endif                                                             //~vam0I~
	xxemain_scrinit();                                             //~VXXER~
#ifndef NOPRINT                                                    //~vam0I~
	xxemain_prtinit();                                             //~VXXEI~
#endif                                                             //~vam0I~
//#ifndef XXE                                                      //~VXXER~
	xeinitcall();                                                  //~VXXER~
//#else                                                            //~VXXER~
//    kbdcvkeyname2euc();    //save stdin consolemode at entry     //~VXXER~
//#endif                                                           //~VXXER~
	Mxxemaininitsw=1;                                              //~VX01I~
    UTRACEP("xxemain_init END\n");                                 //~vam0I~//~vam1M~
#ifdef GTKPRINT                                                    //~vam1I~
	gxepage_init2();	//cups enum printer                        //~vam1I~
#endif   //!GTKPRINT                                               //~vam1I~
    return 0;                                                      //~v003I~
}//xxemain_init                                                    //~v003R~//~vam0R~
//===============================================================================//~v003M~
//ret:rc                                                           //~v003R~
//===============================================================================//~v003M~
int xeinitcall(void)                                               //~VXXER~
{                                                                  //~v003M~
    int rc;                                                        //~2A07I~
//**********************                                           //~2A07I~
	memset(&Mwxeintf,0,sizeof(Mwxeintf));                          //~v003M~
    Mwxeintf.WXEImaxrow=Mscrmaxrow;                                //~v003R~
    Mwxeintf.WXEImaxcol=Mscrmaxcol;                                //~v003R~
    memset(Mwxeintf.WXEIpallette,0,sizeof(Mwxeintf.WXEIpallette)); //~v003R~
                                                                   //~VXXEI~
    xxe_optligature(XXEIOLO_INIT,Mligature);                       //~vb4qI~
	rc=wxe_xecall(WXE_REQ_INIT,&Mwxeintf);                         //~VXXER~
    xeerrchk();     //errmsg msg display                           //~VXXER~
    if (rc==-1)                                                    //~2A07I~
    	exitmain();                                                //~2A07I~
    Mxeinitsw=1;		//init called                              //~v003I~
//  xxe_optligature(XXEIOLO_INIT,Mligature);                       //~vb4qR~
//  csubinit2(Mcellh,Mcellw);                                      //~VXXER~
    return 0;                                                      //~v003I~
}//xeinitcall()                                                    //~v003M~
//===============================================================================//~v003I~
//ret:rc                                                           //~v003I~
//===============================================================================//~v003I~
int xeerrchk(void)                                                 //~VXXER~
{                                                                  //~v003I~
	int rc=0;                                                      //~v003I~
//*****************************                                    //~v003I~
	if (Mwxeintf.WXEIerrmsg)                                       //~v003I~
    {                                                              //~v003I~
//  	umsgbox(Mwxeintf.WXEIerrmsg);                              //~v685R~
    	umsgbox(Mwxeintf.WXEIerrmsg,MB_OK);                        //~v685I~
    	free(Mwxeintf.WXEIerrmsg);                                 //~v003I~
    	Mwxeintf.WXEIerrmsg=0;                                     //~v003I~
        rc=4;                                                      //~v003R~
    }                                                              //~v003I~
    return rc;                                                     //~v003I~
}//xeerrchk                                                        //~VXXER~
//===============================================================================//~v003M~
//optiondlg retuned by OK                                          //~VXXER~
//===============================================================================//~v003M~
//int  CWxemain::OnOk()                                            //~VXXER~
int  xxemain_OnOk()                                                //~VXXEI~
{                                                                  //~v003M~
//  int cpchngsw;                                                  //~VXXER~
//************************************                             //~v003M~
    if (!Mxeinitsw)		//init called                              //~v003R~
    	return 0;                                                  //~v003I~
#ifndef XXE                                                        //~VXXEM~
	csubinit2(Mcellh,Mcellw);                                      //~v003R~
	cpchngsw=wxe_setcharset(0,Mcharset);	//tell eng/jap changed //~v003R~
#endif                                                             //~VXXEM~
    gxemfrm_Loadact(Museact);	//load/delete if changed           //~VXXER~
    gxemfrm_updatemainmenu(Musemk);	//main menu label update       //~VXXER~
    wxe_setrctl(Mrctl);	//issue opt rctl cmd                       //~V55cR~
    wxe_setfreecsr(Mfreecsr);	//issue opt rctl cmd               //~V55qI~
    wxe_setbeep(Mbeep);                                            //~V55GI~
    xxe_optligature(XXEIOLO_CHNGDIALOGOPT,Mligature);              //~va3dI~
//	scronok(cpchngsw);                                             //~VXXER~
  	xxemain_scronok(0); 	//no codepage change                   //~VXXEI~
    return 1;                                                      //~v003I~
}//OnOk                                                            //~v003M~
//===============================================================================//~v003I~
//get ini file on work dir                                         //~v003I~
//===============================================================================//~v003I~
int  iniget()                                                      //~VXXER~
{                                                                  //~v003I~
    WXEINIDATA wxei;                                               //~2A20I~
//************************************                             //~v003I~
	wxei=Mwxeinidata;	//mainfrm read inital                      //~VXXER~
                                                                   //~2A19I~
	if (!wxei.WXEINIver) //read success at mainfrm                 //~2A20R~
    	return 4;                                                  //~2A19I~
	if (*wxei.WXEINIfontstyle) //font style                        //~2A20R~
		strcpy(Mfontstyle,wxei.WXEINIfontstyle); //font style      //~2A20R~
	if (wxei.WXEINIcmaxrow)	//current row count                    //~2A20R~
		Mscrcmaxrow  =wxei.WXEINIcmaxrow;                          //~2A20R~
	if (wxei.WXEINIcmaxcol)	//current col count                    //~2A20R~
		Mscrcmaxcol  =wxei.WXEINIcmaxcol;                          //~2A20R~
//  if (wxei.WXEINIcellh)	//cell height                          //~VX01R~
		Mcellh0      =wxei.WXEINIcellh;	//cell height              //~VX01R~
//  if (wxei.WXEINIcellw)	//cell width                           //~VX01R~
		Mcellw0      =wxei.WXEINIcellw;	//cell width               //~VX01R~
//  if (wxei.WXEINIcharset)	//font charset(0 for ansi)             //~2A20R~
//  	Mcharset     =wxei.WXEINIcharset;                          //~VXXER~
//  if (wxei.WXEINIothercharset)                                   //~VXXER~
//  	Mothercharset     =wxei.WXEINIothercharset;                //~VXXER~
//	if (wxei.WXEINIfontheight)	//char height                      //~VXXER~
//		Mfontheight  =wxei.WXEINIfontheight;	//char height      //~VXXER~
//	if (wxei.WXEINIfontheight)	//char height                      //~VXXER~
//		Mfontwidth   =wxei.WXEINIfontwidth;	//char width           //~VXXER~
//  if (wxei.WXEINIbgcolor)//background color                      //~VXXER~
//if (wxei.WXEINIsetflag & WXEINIF_BGCOLOR)                        //~v73yR~
	COLORCOPY(Mbgcolor,wxei.WXEINIbgcolor);//background color      //~VXXER~
  if (wxei.WXEINIsetflag & WXEINIF_RULERCOLOR)                     //~v73tI~
	COLORCOPY(Mrulercolor,wxei.WXEINIrulercolor);//background color//~v73tR~
  if (wxei.WXEINIsetflag & WXEINIF_RULERKEY)                       //~v740I~
	memcpy(Mrulerkey,wxei.WXEINIrulerkey,sizeof(Mrulerkey));       //~v740I~
	if (wxei.WXEINIscrollctr)//background color                    //~2A20R~
		Mscrollctr   =wxei.WXEINIscrollctr;//background color      //~2A20R~
	if (wxei.WXEINIscrolltimer)                                    //~V510R~
		Mscrolltimer =wxei.WXEINIscrolltimer;//background color    //~V510R~
	if (wxei.WXEINIdblclicktimer)                                  //~VXXEI~
		Mdblclicktimer=wxei.WXEINIdblclicktimer;                   //~VXXER~
	Mttfont=wxei.WXEINIttfont;                                     //~2A20R~
	Museact=wxei.WXEINIuseact;                                     //~3103I~
	Musemk =wxei.WXEINIusemk ;                                     //~3105I~
//*page setup data                                                 //~2B03I~
	if (*wxei.WXEINIformsize)                                      //~V51hI~
	strncpy(Mformtype,wxei.WXEINIformsize,sizeof(Mformtype));      //~2B09R~
	if (*wxei.WXEINIprinter)                                       //~v667I~
		strncpy(Mprinter,wxei.WXEINIprinter,sizeof(Mprinter));     //~v667I~
	if (*wxei.WXEINIprtfontstyle)                                  //~V51hR~
		strncpy(Mprtfontstyle,wxei.WXEINIprtfontstyle,sizeof(Mprtfontstyle));//~V51hI~
    Mlandscape   =wxei.WXEINIlandscape ;                           //~2B03I~
    Mfullpage    =wxei.WXEINIfullpage  ;                           //~2B30I~
    MprintLigature=wxei.WXEINIprintLigature;                       //~vam7R~
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
//	if (wxei.WXEINIpfontszh)                                       //~VXXER~
//	    Mpfontszh    =wxei.WXEINIpfontszh;                         //~VXXER~
//  Mpfontszw    =wxei.WXEINIpfontszw;                             //~VXXER~
	if (wxei.WXEINIpcellszh)                                       //~V51hI~
	    Mpcellszh    =wxei.WXEINIpcellszh;                         //~V51hI~
//	if (wxei.WXEINIpcellszhmax)	  //allow 0 (no limit)             //~VXXER~
	    Mpcellszhmax =wxei.WXEINIpcellszhmax;                      //~V62WI~
    Mpcellszw    =wxei.WXEINIpcellszw;                             //~V51hI~
//*page setup data end                                             //~2B03I~
  	if (wxei.WXEINIsetflag & WXEINIF_OPT_QEXIT)                    //~v73yI~
        Gwxestat|=GWXES_OPT_QEXIT;                                 //~v73yI~
  	Mligature=(wxei.WXEINIsetflag & WXEINIF_OPT_LIGATURE)!=0;      //~va1MI~
    Mrulermode=(wxei.WXEINIsetflag & WXEINIF_OPT_RULER)>>8;        //~v76TI~
    return 0;                                                      //~v003I~
}//iniget                                                          //~v003I~
//===============================================================================//~v003I~
//save ini data(write at mainframe close)                          //~2A19R~
//===============================================================================//~v003I~
int  xxemain_iniput(WXEINIDATA *Pwxei)                             //~VXXER~
{                                                                  //~v003I~
//************************************                             //~v003I~
	Pwxei->WXEINIver         =WXE_VER;                             //~2A20R~
	strcpy(Pwxei->WXEINIfontstyle,Mfontstyle);                     //~2A20R~
	Pwxei->WXEINIcmaxrow     =Mscrcmaxrow;//current row            //~3102R~
	Pwxei->WXEINIcmaxcol     =Mscrcmaxcol;//current col            //~3102R~
	Pwxei->WXEINIcellh       =Mcellh0;  //cell height              //~VX01R~
	Pwxei->WXEINIcellw       =Mcellw0;  //cell width               //~VX01R~
//	Pwxei->WXEINIcharset     =Mcharset;  //cell width              //~VXXER~
//	Pwxei->WXEINIothercharset=Mothercharset;  //cell width         //~VXXER~
//	Pwxei->WXEINIfontheight  =Mfontheight;	//char height          //~VXXER~
//	Pwxei->WXEINIfontwidth   =Mfontwidth;	//char height          //~VXXER~
	COLORCOPY(Pwxei->WXEINIbgcolor,Mbgcolor);//background color    //~VXXER~
	COLORCOPY(Pwxei->WXEINIrulercolor,Mrulercolor);//background color//~v73tI~
	memcpy(Pwxei->WXEINIrulerkey,Mrulerkey,sizeof(Mrulerkey));     //~v740I~
  	Pwxei->WXEINIsetflag|=WXEINIF_RULERCOLOR                       //~v740R~
  	                      |WXEINIF_RULERKEY;                       //~v740I~
	Pwxei->WXEINIscrollctr   =Mscrollctr;                          //~3102R~
	Pwxei->WXEINIscrolltimer =Mscrolltimer;                        //~V510R~
	Pwxei->WXEINIdblclicktimer=Mdblclicktimer;                     //~VXXEI~
	Pwxei->WXEINIttfont      =Mttfont;                             //~3102R~
	Pwxei->WXEINIuseact      =Museact;                             //~3103I~
	Pwxei->WXEINIusemk       =Musemk ;                             //~3105I~
//*page setup data                                                 //~2B03I~
	strncpy(Pwxei->WXEINIformsize,Mformtype,sizeof(Pwxei->WXEINIformsize));//~2B09R~
	strncpy(Pwxei->WXEINIprinter,Mprinter,sizeof(Pwxei->WXEINIprinter));//~v667I~
	strncpy(Pwxei->WXEINIprtfontstyle,Mprtfontstyle,sizeof(Pwxei->WXEINIprtfontstyle));//~V51hI~
    Pwxei->WXEINIlandscape=Mlandscape;                             //~2B03I~
    Pwxei->WXEINIfullpage =Mfullpage ;                             //~2B30I~
    Pwxei->WXEINIprintLigature=MprintLigature;                     //~vam7R~
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
#ifdef GTKPRINT                                                    //~vamtI~
    gxepage_savemarginshift(Pwxei);                                //~vamtI~
#else                                                              //~vamtI~
    Pwxei->WXEINIleft     =Mmarginl;                               //~2B10R~
    Pwxei->WXEINIright    =Mmarginr;                               //~2B10R~
    Pwxei->WXEINItop      =Mmargint;                               //~2B10R~
    Pwxei->WXEINIbottom   =Mmarginb;                               //~2B10R~
#endif                                                             //~vamtI~
    Pwxei->WXEINIchkpfontsz=Mchkpfontsz;                           //~V51hI~
//  Pwxei->WXEINIpfontszh =Mpfontszh;                              //~VXXER~
//  Pwxei->WXEINIpfontszw =Mpfontszw;                              //~VXXER~
    Pwxei->WXEINIpcellszh =Mpcellszh;                              //~V51hI~
    Pwxei->WXEINIpcellszhmax =Mpcellszhmax;                        //~V62WI~
    Pwxei->WXEINIpcellszw =Mpcellszw;                              //~V51hI~
//*page setup data end                                             //~2B03I~
    if (Gwxestat & GWXES_OPT_QEXIT)                                //~v73yI~
  		Pwxei->WXEINIsetflag|=WXEINIF_OPT_QEXIT;                   //~v73yR~
    else                                                           //~v73yI~
  		Pwxei->WXEINIsetflag&=~WXEINIF_OPT_QEXIT;                  //~v73yR~
    if (Mligature)                                                 //~va1MI~
  		Pwxei->WXEINIsetflag|=WXEINIF_OPT_LIGATURE;                //~va1MI~
    else                                                           //~va1MI~
  		Pwxei->WXEINIsetflag&=~WXEINIF_OPT_LIGATURE;               //~va1MI~
    Pwxei->WXEINIsetflag&=~WXEINIF_OPT_RULER;  	//clear old ruler mode//~v76TI~
    Pwxei->WXEINIsetflag|=((Mrulermode<<8) & WXEINIF_OPT_RULER);   //~v76TI~
    UTRACEP("%s:INIframe width=%d,height=%d\n",UTT,Pwxei->WXEINIframewidth,Pwxei->WXEINIframeheight);      //~vb4qI~//+vbs4R~
    UTRACED("xxemain_iniput WXEINI",Pwxei,(int)WXEINIDATASZ);      //+vbs4I~
    return 0;                                                      //~2A19R~
}//xxemain_iniput                                                  //~VXXER~
//===============================================================================//~v003I~
//xe returned -1                                                   //~v003I~
//===============================================================================//~v003I~
void exitmain(void)                                                //~VXXER~
{                                                                  //~v003I~
//************************************                             //~v003I~
    if (Gpframe)                                                   //~VXXER~
    	uactivate_menuitem(STRID_FILE_EXIT);                       //~VXXER~
    else                                                           //~2A19I~
    {                                                              //~var1I~
    dprintf("exitmain quit\n");                                    //~v667R~
#ifndef OPTGTK3                                                    //~var8R~
		gtk_main_quit();                                           //~VXXER~
#else   //OPTGTK3                                                  //~var8R~
		gxeview_OnExit();	//not quit but destry widget           //~var8R~
#endif                                                             //~var8R~
    }                                                              //~var1I~
}//exitmain                                                        //~VXXER~
//**************************************************************** //~V55GI~
//*atcmd timer process                                             //~V55GI~
//rc:FALSE:stop timer,TRUE:continue timer                          //~VXXEI~
//**************************************************************** //~V55GI~
int xxemain_ontimeratcmd(UINT Pid)                                 //~VXXER~
{                                                                  //~V55GI~
    int   ms,rc,apprc;                                             //~V55GR~
    int   continuetimer=TRUE;                                      //~VXXEI~
//****************************                                     //~V55GI~
//  Mscrolltimereventctr++; //timer                                //~V55GI~
dprintf("scroll:ontimer posid=%x,Pid=%x,eventctr=%d\n",Mlbposid,Pid,Mscrolltimereventctr);//~v667R~
	if (Pid & TID_ATCMDTIMER)	//timer expired from last cmd      //~V55GI~
        continuetimer=FALSE;//Gpview->KillTimer(Pid);              //~VXXER~
	if (Pid & TID_ATCMDDRAW) 	//msg draw req                     //~V55GI~
    {                                                              //~V55GI~
        wxe_timerreset(WXEAT_DRAW);                                //~V560R~
    	xxemain_scrinvalidate(0);//Gpview->Invalidate(FALSE);      //~VXXER~
	    return continuetimer;                                      //~VXXER~
    }                                                              //~V55GI~
	if (Pid & TID_ATCMDSLEEP) 	//sleep time                       //~V560I~
    {                                                              //~V560I~
        wxe_timerreset(WXEAT_SLEEPED);                             //~V560I~
    	xxemain_scrinvalidate(0);//Gpview->Invalidate(FALSE);      //~VXXEI~
	    return continuetimer;                                      //~VXXEI~
    }                                                              //~V560I~
	if (!Mwxeintf.WXEIatcmdstring)	//reset requested              //~V55GI~
	    return continuetimer;                                      //~VXXEI~
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
	    return continuetimer;                                      //~VXXEI~
    }                                                              //~V55GI~
    if (apprc>=4                                                   //~V560R~
    &&  !(Mwxeintf.WXEIatcmdopt & WXEAT_IGNOREERR))                //~V560I~
        wxe_timerreset(WXEAT_CMDER);//free saved                   //~V55GR~
    else                                                           //~V55GI~
    {                                                              //~V55GI~
        switch(rc)                                                 //~V55GI~
        {                                                          //~V55GI~
        case 0:		//middle of multi cmd                          //~V55GM~
            usettimer(TID_ATCMD|TID_ATCMDTIMER,WXEAT_MULTCMDTIMER,0);//schedule next subcmd//~VXXER~
        	break;                                                 //~V55GM~
        case 1:		//end of 1st repeat                            //~V55GR~
        case 2:     //end of multi cmd in each repeat              //~V55GI~
            ms=Mwxeintf.WXEIatcmdintvl*1000;    //by millisec      //~V55GI~
            usettimer(TID_ATCMD|TID_ATCMDTIMER,ms,0);              //~VXXER~
        	break;                                                 //~V55GI~
        case 3:		//end of last repeat                           //~V55GR~
            wxe_timerreset(WXEAT_COMP);//free saved                //~V55GI~
        	break;                                                 //~V55GR~
        case 4:		//sleep subcmd                                 //~V560I~
        	break;                                                 //~V560I~
        }//sw                                                      //~V55GI~
    }                                                              //~V55GI~
    xxemain_scrinvalidate(0);//Gpview->Invalidate(FALSE);          //~VXXEI~
    return continuetimer;                                          //~VXXEI~
}//ontimeratcmd                                                    //~V55GI~
