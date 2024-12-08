//*CID://+vbdnR~:                             update#=  338;       //~vbdnR~
//************************************************************************//~v51dI~
//vbdo:171125 (wxe:BUG)crashh when File/New is canceled            //~vbdnI~//~vbdoR~
//vbdn:171125 disable filemenu depending curent pcw type           //~vbdnI~
//vbd3:171117 (Wxe)MainMenu enable/disable also on Edit submenu    //~vbd3I~
//vbd2:171114 (Wxe)Add SelectAll menuitem                          //~vbd2I~
//vb4v:160813 (WXE bug)ATl/WTL is missing OnPrecreateWindow        //~vb4vI~
//vb3w:160621 w64 compiler warning                                 //~vb3wI~
//vak7:130906 redirect memcpy to memmove when overlaped            //~vak7I~
//v782:080219 (BUG)Vista dose not support WinHelp                  //~v782I~
//v71A:061030 (WXE)Use HtmlHelp;Winhelp is deprecated at Vista;XP english ersion cannot read .hlp by the readson of codepage unsupported//~v71AI~
//v66E:051220 (WXE)english version(drop japanese vcc comment,dialog string text etc)//~v66EI~
//v66m:051025 (WXE:BUG)DrawMenuBar is required to show grayed just a time changed status//~v66mI~
//v66h:051023 C & P;region mode by mouse; mouse drag->region mode,A+mouse drag->block mode//~v66hI~
//            delete Ctrl+V(preview) from menu and add to icon menu and popup menu//~v66hI~
//v55F:040314 (WXE)english help                                    //~v55FI~
//v55z:040304 (WXE)help support                                    //~v55zI~
//v53t:031004 (WXE:BUG)not freed area exist                        //~v51wI~
//v51w:030615 (WXE)icon for MDOS and Explorer                      //~v51wI~
//v51d:030517 (WXE)bitmap menu                                     //~v51dI~
//************************************************************************//~v51dI~

#pragma once                                                       //~@@@@I~
#include "stdafx.h"
#define NO_MACRO_REDIRECT                                          //~vavAI~
#include <ulib.h>                                                  //~vavAR~
#include "wxe.h"
#include "wxedef.h"                                                //~2922I~
#include "wxecsub.h"                                               //~vavAR~

#include "wxefile.h"                                               //~2A14I~
#include "wxedoc.h"                                                //~2A14I~
#include "wxemain.h"                                               //~2A14I~
#include "MainFrm.h"                                               //~vavAR~
#include "wxexei.h"                                                //~3125I~
#include "wxehelp.h"                                               //~v55FI~
                                                                   //~2A14I~
#include "utrace.h"                                                //~2A14I~

#define m_hAccelTable m_hAccel                                     //~@@@@I~
                                                                   //~@@@@I~
#ifdef _DEBUG
//#define new DEBUG_NEW                                            //~@@@@R~
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//#define APPENDPOS   9                                            //~v51wR~
#define APPENDPOS   11                //pos of Cut(Icon) on menubar//~v51wI~
#define TOOLBARINDEX_SAVE 5                                        //~vbdnI~
/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

//BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)                         //~@@@@R~
//    //{{AFX_MSG_MAP(CMainFrame)                                  //~@@@@R~
//    ON_WM_CREATE()                                               //~@@@@R~
//    ON_WM_CLOSE()                                                //~@@@@R~
//    ON_WM_INITMENU()                                             //~@@@@R~
//    ON_COMMAND(ID_HELPXE, OnHelp)                                //~@@@@R~
//    //}}AFX_MSG_MAP                                              //~@@@@R~
//END_MESSAGE_MAP()                                                //~@@@@R~
                                                                   //~v51wI~
static UINT indicators[]=                                          //~v51wR~
{
	ID_SEPARATOR,           // status line indicator               //~v66ER~
	ID_INDICATOR_KANA,
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////

CMainFrame::CMainFrame()
{
    Mpapp=(CWxeApp*)AfxGetApp();                                   //~2A19I~
	Mpxemain=0;	//for OnSize                                       //~2A14I~
	Mswappexit=0;                                                  //~@@@@I~
//    Monsizetype=0;  //for OnSize                                 //~2A19R~
	ugetinidata(&Mwxeinidata);		//read ini data                //~2A19I~
    Mpapp->Mshowmaxsw=Mwxeinidata.WXEINIshowmaxsw;	//show max at init instance of wxe.cpp//~2A19R~
    Mpapp->Mpmainframe=this;                                       //~3103R~
    Museact=Mwxeinidata.WXEINIuseact;	//accelerator use          //~3103I~
    Musemk =Mwxeinidata.WXEINIusemk ;	//accelerator use          //~3105I~
    Mpact=0;        //accelerator table copy                       //~3104I~
    Menableselectall=1;                                            //~vbd2R~
    Menablecut=1;     //initialy dispaly menu bitmap               //~v51dR~
    Menablecopy=1;                                                 //~v51dR~
    Menablepaste=1;                                                //~v51dR~
    Menablepastev=1;                                               //~v66hI~
}

CMainFrame::~CMainFrame()
{
    if (Mpact)        //accelerator table copy                     //~v53tR~
    	wxefree(Mpact);                                            //~v53tR~
}
///////////////////////////////////////////////////////////////////////////////~2A14I~
int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
//    WINDOWPLACEMENT wp;                                          //~2A19R~
//**************************                                       //~2A14I~
//    if (CFrameWnd::OnCreate(lpCreateStruct) == -1)               //~@@@@R~
//        return -1;                                               //~@@@@R~
////  if (Monsizetype==SIZE_MAXIMIZED                              //~2A19R~
////  ||  Monsizetype==SIZE_MAXSHOW                                //~2A19R~
////  ||  Monsizetype==SIZE_MAXHIDE)                               //~2A19R~
//    Mpxemain->Mrestoreframesize=1;                               //~2A19R~
//    if (Monsizetype)                                             //~2A19R~
//    {                                                            //~2A19R~
//        GetWindowPlacement(&wp);                                 //~2A19R~
//        UTRACED("WP:bef",&wp,sizeof(wp));                        //~2A19R~
//        ugetinitsize2(&wp);                                      //~2A19R~
//        UTRACED("WP:restore",&wp,sizeof(wp));                    //~2A19R~
////      wp.showCmd=SW_SHOWMAXIMIZED;                             //~2A19R~
//        SetWindowPlacement(&wp);                                 //~2A19R~
////      SendMessage(WM_SYSCOMMAND,SC_MAXIMIZE,0);                //~2A19R~
//        GetWindowPlacement(&wp);                                 //~2A19R~
//        UTRACED("WP:aft",&wp,sizeof(wp));                        //~2A19R~
//        wp.flags  =WPF_RESTORETOMAXIMIZED;                       //~2A19R~
////      wp.showCmd=SW_SHOWMAXIMIZED;                             //~2A19R~
//        SetWindowPlacement(&wp);                                 //~2A19R~
////      SendMessage(WM_SYSCOMMAND,SC_MAXIMIZE,0);                //~2A19R~
//        GetWindowPlacement(&wp);                                 //~2A19R~
//        UTRACED("WP:aft",&wp,sizeof(wp));                        //~2A19R~
//    }                                                            //~2A19R~
//  ModifyStyle(0,WS_MAXIMIZE,0);//add maximize flag               //~2A14M~
	ModifyStyle(FWS_ADDTOTITLE,0,0);//remove flag(openfilename add to title)//~2A14R~
//  SetWindowText(WXE_TITLE);                                      //~@@@@R~
    SetWindowText((LPCTSTR)WXE_TITLE);                             //~@@@@I~
//Following deleted because access err at x840dd949 when mouse moved on to toolbar area//~2914I~
//    if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP//~2914R~
//        | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||//~2914R~
//        !m_wndToolBar.LoadToolBar(IDR_MAINFRAME))                //~2914R~
//    {                                                            //~2914R~
//        TRACE0("Failed to create toolbar\n");                    //~2914R~
//        return -1;                                               //~v66ER~
//    }                                                            //~2914R~

//    if (!m_wndStatusBar.Create(this) ||                          //~2915R~
//        !m_wndStatusBar.SetIndicators(indicators,                //~2915R~
//          sizeof(indicators)/sizeof(UINT)))                      //~2915R~
//    {                                                            //~2915R~
//        TRACE0("Failed to create status bar\n");                 //~2915R~
//        return -1;                                               //~v66ER~
//    }                                                            //~2915R~

//    m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);                  //~2914R~
//    EnableDocking(CBRS_ALIGN_ANY);                               //~2914R~
//    DockControlBar(&m_wndToolBar);                               //~2914R~
	return 0;
}

BOOL CMainFrame::OnPreCreateWindowW(LPCREATESTRUCT lpcs)           //~vb4vR~
{                                                                  //~vb4vI~
	int X=0,Y=0,ww,hh;                                             //~vb4vR~
    UINT uflag;                                                    //~vb4vI~
//*****************************                                    //~vb4vI~
//  PreCreateWindow(*lpcs);	//@@@@test                             //~vb4vI~
	uflag=SWP_NOMOVE/*ignore X,Y parm*/|SWP_SHOWWINDOW;            //~vb4vI~
    ww=Mwxeinidata.WXEINIframewidth;	//restore size             //~vb4vR~
	hh=Mwxeinidata.WXEINIframeheight;	//restore size             //~vb4vR~
    if (hh && ww)                                                  //~vb4vI~
    {                                                              //~vb4vI~
//  	SetWindowPos(m_hWnd,HWND_TOP,X,Y,ww,hh,uflag);	//not ATL  //~vb4vI~
    	SetWindowPos(HWND_TOP,X,Y,ww,hh,uflag);         //ATL      //~vb4vI~
    }                                                              //~vb4vI~
    return 0;                                                      //~vb4vI~
}                                                                  //~vb4vI~
BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
//**********************************                               //~2A14I~
//    if( !CFrameWnd::PreCreateWindow(cs) )                        //~@@@@R~
//        return FALSE;                                            //~@@@@R~
	UTRACEP("precreate window before style=%08x,(cx=%08x,cy=%08x,x=%08x,y=%08x)\n",//~2A19R~
    			cs.style,cs.cx,cs.cy,cs.x,cs.y);                   //~2A14I~
//    ugetinitsize(&Monsizetype,&cs.cx,&cs.cy);                    //~2A19I~
    if (Mwxeinidata.WXEINIframewidth)	//read ok and not minimized//~2A19R~
    	cs.cx=Mwxeinidata.WXEINIframewidth;	//restore size         //~2A19I~
    if (Mwxeinidata.WXEINIframeheight)	//not minimized            //~2A19R~
    	cs.cy=Mwxeinidata.WXEINIframeheight;	//restore size     //~2A19I~
	UTRACEP("precreate window after style=%08x,(cx=%08x,cy=%08x,x=%08x,y=%08x)\n",//~2A19I~
    			cs.style,cs.cx,cs.cy,cs.x,cs.y);                   //~2A19I~
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////

//#ifdef _DEBUG                                                    //~@@@@R~
//void CMainFrame::AssertValid() const                             //~@@@@R~
//{                                                                //~@@@@R~
//    CFrameWnd::AssertValid();                                    //~@@@@R~
//}                                                                //~@@@@R~

//void CMainFrame::Dump(CDumpContext& dc) const                    //~@@@@R~
//{                                                                //~@@@@R~
//    CFrameWnd::Dump(dc);                                         //~@@@@R~
//}                                                                //~@@@@R~

//#endif //_DEBUG                                                  //~@@@@R~

/////////////////////////////////////////////////////////////////////////////
// CMainFrame msg handler                                          //~v66ER~

//void CMainFrame::OnSize(UINT nType, int cx, int cy)              //~2A19R~
//{                                                                //~2A19R~
//    CFrameWnd::OnSize(nType, cx, cy);                            //~2A19R~
//                                                                 //~2A19R~
//    UTRACEP("frame on size;type=%d,cx=%d,cy=%d\n",nType,cx,cy);  //~2A19R~
//    if (Mpxemain)                                                //~2A19R~
//        Mpxemain->iniput(nType,cx,cy);//write scr size           //~2A19R~
//}                                                                //~2A19R~
///////////////////////////////////////////////////////////////////////////////~2A14I~
void CMainFrame::frmsetxemain(CWxemain *Ppm)                       //~2A14I~
{                                                                  //~2A14I~
	Mpxemain=Ppm;	//for OnSize                                   //~2A14I~
    return;                                                        //~2A14I~
}                                                                  //~2A14I~

void CMainFrame::OnClose() 
{
    WINDOWPLACEMENT wp;                                            //~2A19I~
//*******************************                                  //~2A19I~
	UTRACEP("%s:Mpxemain=%p\n",UTT,Mpxemain);                      //+vbdnI~
    if (Mpxemain)                                                  //~2A20R~
    {                                                              //~2A20I~
        Mpxemain->iniput(&Mwxeinidata);//write scr size            //~2A20R~
        GetWindowPlacement(&wp);                                   //~2A20R~
        Mwxeinidata.WXEINIframewidth=wp.rcNormalPosition.right-wp.rcNormalPosition.left;//~2A20R~
        Mwxeinidata.WXEINIframeheight=wp.rcNormalPosition.bottom-wp.rcNormalPosition.top;//~2A20R~
        Mwxeinidata.WXEINIshowmaxsw=IsZoomed();                    //~2A20R~
	  if (Mswappexit)	//not by close button on top right         //~@@@@I~
      {                                                            //~@@@@I~
        uputinidata(&Mwxeinidata);                                 //~2A20R~
        wxe_xecall(WXE_REQ_TERM,0,0,0);	//write xe.ini             //~3125R~
      }                                                            //~@@@@I~
    }                                                              //~2A20I~
#ifdef AAA                                                         //~v782I~
    Mpapp->WinHelp(0,HELP_QUIT);                                   //~v55zI~
#endif                                                             //~v782I~
	
//  CFrameWnd::OnClose();                                          //~@@@@R~
	DestroyWindow();	//callback:OnDestroy                       //~@@@@R~
    PostQuitMessage(0/*exitcode*/);                                //~@@@@I~
}
int  CMainFrame::Loadact(int Puseact)                              //~3105R~
{                                                                  //~3103I~
//  int delsw=0;                                                   //~3105R~//~@@@@R~
    int actid=IDR_MAINFRAME_DYN;                                   //~@@@@I~
    CMenu *pmenu;                                                  //~3103I~
//*******************************                                  //~3103I~
	if (Puseact!=-1)        //init req from wxe.cpp                //~3103I~
    	if (Museact==Puseact)   //not changed                      //~3103I~
            return 0;                                              //~3103R~
        else                                                       //~3103I~
            Museact=Puseact;                                       //~3103I~
    else                     //init req from wxe.cpp               //~@@@@I~
    	Mcacc.LoadAccelerators(actid);                             //~@@@@R~
//    if (Museact)    //accelerator use                              //~3103I~//~@@@@R~
//    {                                                              //~3103I~//~@@@@R~
//        if (m_hAccelTable)  //already loaded,mfc asset fail        //~3103R~//~@@@@R~
//            delsw=1;                                               //~3103I~//~@@@@R~
//    }                                                              //~3103I~//~@@@@R~
//    else                                                           //~3103I~//~@@@@R~
//        if (m_hAccelTable)  //already loaded,mfc asset fail        //~3103I~//~@@@@R~
//            delsw=1;                                               //~3103I~//~@@@@R~
//    if (delsw)                                                     //~3103I~//~@@@@R~
//    {                                                              //~3103I~//~@@@@R~
//        DestroyAcceleratorTable(m_hAccelTable);                    //~3103R~//~@@@@R~
//        m_hAccelTable=0;                                           //~3103R~//~@@@@R~
//    }                                                              //~3103I~//~@@@@R~
//  pmenu=GetMenu();                                               //~@@@@R~
    pmenu=GetMenuW();                                              //~@@@@I~
	updatemenu(0,pmenu);                                           //~3103R~
	if (Puseact==-1)        //init req from wxe.cpp                //~v51dI~
		appendmenu(pmenu);                                         //~v51dI~
    Invalidate(FALSE);                                             //~v51dI~
	return 1;                                                      //~3103R~
}                                                                  //~3103I~
//***********************************************                  //~v51dI~
int  CMainFrame::appendmenu(CMenu* Ppmenu)                         //~v51dI~
{                                                                  //~v51dI~
    int flag1,flag2;                                               //~v51dR~
//***************************                                      //~v51dI~
    Mbmsave.LoadBitmap(IDB_SAVE);                                  //~v51dI~
    Mbmend.LoadBitmap(IDB_END);                                    //~v51dI~
    Mbmcancel.LoadBitmap(IDB_CANCEL);                              //~v51dI~
    Mbmprint.LoadBitmap(IDB_PRINT);                                //~v51dI~
    Mbmcopy.LoadBitmap(IDB_COPY);                                  //~v51dI~
    Mbmcut.LoadBitmap(IDB_CUT);                                    //~v51dI~
    Mbmclear.LoadBitmap(IDB_CLEAR);                                //~v51dI~
    Mbmpastev.LoadBitmap(IDB_PASTEV);                              //~v66hI~
    Mbmpastei.LoadBitmap(IDB_PASTE_INS);                           //~v51dR~
    Mbmpaster.LoadBitmap(IDB_PASTE_REP);                           //~v51dI~
    Mbmexplorer.LoadBitmap(IDB_EXPLORER);                          //~v51wI~
    Mbmdos.LoadBitmap(IDB_DOS);                                    //~v51wR~
//UTRACEP("@@@@menuitemcount=%d\n",Ppmenu->GetMenuItemCount());    //~v688R~
                                                                   //~v51dI~
    flag1=MF_BYCOMMAND|MF_BITMAP|MF_RIGHTJUSTIFY|MF_ENABLED;       //~v51dR~
//  flag2=MF_BYCOMMAND|MF_BITMAP|MF_RIGHTJUSTIFY|MF_GRAYED;        //~v51dR~
    flag2=MF_BYCOMMAND|MF_BITMAP|MF_RIGHTJUSTIFY|MF_ENABLED;       //~v51dI~
//    Ppmenu->AppendMenu(flag1,ID_FILE_SAVE,&Mbmsave);             //~@@@@R~
//    Ppmenu->AppendMenu(flag1,ID_EDIT_END,&Mbmend);               //~@@@@R~
//    Ppmenu->AppendMenu(flag1,ID_EDIT_CANCEL,&Mbmcancel);         //~@@@@R~
//    Ppmenu->AppendMenu(flag1,ID_FILE_PRINT,&Mbmprint);           //~@@@@R~
//    Ppmenu->AppendMenu(flag1,ID_FILE_EXPLORER,&Mbmexplorer);     //~@@@@R~
//    Ppmenu->AppendMenu(flag1,ID_FILE_DOS,&Mbmdos);               //~@@@@R~
////UTRACEP("@@@@menuitemcount=%d\n",Ppmenu->GetMenuItemCount());  //~@@@@R~
//    Ppmenu->AppendMenu(flag2,ID_EDIT_CUT,&Mbmcut);               //~@@@@R~
//    Ppmenu->AppendMenu(flag2,ID_EDIT_COPY,&Mbmcopy);             //~@@@@R~
//    Ppmenu->AppendMenu(flag2,ID_EDIT_CLEAR,&Mbmclear);           //~@@@@R~
//    Ppmenu->AppendMenu(flag2,ID_EDIT_PASTE_STD,&Mbmpastev);      //~@@@@R~
//    Ppmenu->AppendMenu(flag2,ID_EDIT_PASTE,&Mbmpastei);          //~@@@@R~
//    Ppmenu->AppendMenu(flag2,ID_EDIT_PASTE_REP,&Mbmpaster);      //~@@@@R~
    Ppmenu->AppendMenu(flag1,ID_FILE_SAVE,HBITMAP(Mbmsave));       //~@@@@I~
    Ppmenu->AppendMenu(flag1,ID_EDIT_END,HBITMAP(Mbmend));         //~@@@@I~
    Ppmenu->AppendMenu(flag1,ID_EDIT_CANCEL,HBITMAP(Mbmcancel));   //~@@@@I~
    Ppmenu->AppendMenu(flag1,ID_FILE_PRINT,HBITMAP(Mbmprint));     //~@@@@I~
    Ppmenu->AppendMenu(flag1,ID_FILE_EXPLORER,HBITMAP(Mbmexplorer));//~@@@@I~
    Ppmenu->AppendMenu(flag1,ID_FILE_DOS,HBITMAP(Mbmdos));         //~@@@@I~
//UTRACEP("@@@@menuitemcount=%d\n",Ppmenu->GetMenuItemCount());    //~@@@@I~
    Ppmenu->AppendMenu(flag2,ID_EDIT_CUT,HBITMAP(Mbmcut));         //~@@@@I~
    Ppmenu->AppendMenu(flag2,ID_EDIT_COPY,HBITMAP(Mbmcopy));       //~@@@@I~
    Ppmenu->AppendMenu(flag2,ID_EDIT_CLEAR,HBITMAP(Mbmclear));     //~@@@@I~
    Ppmenu->AppendMenu(flag2,ID_EDIT_PASTE_STD,HBITMAP(Mbmpastev));//~@@@@I~
    Ppmenu->AppendMenu(flag2,ID_EDIT_PASTE,HBITMAP(Mbmpastei));    //~@@@@I~
    Ppmenu->AppendMenu(flag2,ID_EDIT_PASTE_REP,HBITMAP(Mbmpaster));//~@@@@I~
//    Ppmenu->ModifyMenu(ID_FILE_SAVE2,flag1,ID_FILE_SAVE2,&Mbmsave);//~v51dR~
//    Ppmenu->ModifyMenu(ID_FILE_PRINT2,flag1,ID_FILE_PRINT2,&Mbmprint);//~v51dR~
//    Ppmenu->ModifyMenu(ID_EDIT_END,flag1,0,&Mbmend);             //~v51dR~
//    Ppmenu->ModifyMenu(ID_EDIT_CANCEL,flag1,ID_EDIT_CANCEL,&Mbmcancel);//~v51dR~
//    Ppmenu->ModifyMenu(ID_EDIT_COPY2,flag2,ID_EDIT_COPY2,&Mbmcopy);//~v51dR~
//    Ppmenu->ModifyMenu(ID_EDIT_CUT2,flag2,ID_EDIT_CUT2,&Mbmcut); //~v51dR~
//    Ppmenu->ModifyMenu(ID_EDIT_CLEAR,flag2,ID_EDIT_CLEAR,&Mbmclear);//~v51dR~
//    Ppmenu->ModifyMenu(ID_EDIT_PASTE2,flag2,ID_EDIT_PASTE2,&Mbmpastei);//~v51dR~
//    Ppmenu->ModifyMenu(ID_EDIT_PASTE_REP,flag2,ID_EDIT_PASTE_REP,&Mbmpaster);//~v51dR~
    return 0;                                                      //~v51dI~
}//appendmenu                                                      //~v51dI~
//***********************************************                  //~v51dI~
//*icon menu enable/disable *(submenu is by onupdatecommandui)     //~v66ER~
//***********************************************                  //~v66hI~
int  CMainFrame::enablemainmenu(void)                              //~v51dI~
{                                                                  //~v51dI~
    CMenu *pmenu;                                                  //~v51dI~
    CMenu *psubmenu;                                               //~vbd3I~
    int enablecopy,enablepaste,enablecut,flag0,flag;               //~v51dR~
    int enablepastev;                                              //~v66hR~
    int enableselectall;                                           //~vbd2R~
    int chngsw=0;                                                  //~v51dI~
//***************************                                      //~v51dI~
//  flag=MF_BYCOMMAND;                                             //~v51dR~
    flag0=MF_BYPOSITION;                                           //~v51dR~
//  pmenu=GetMenu();                                               //~@@@@R~
//  pmenu=this->GetMenu();                                         //~@@@@R~
    pmenu=GetMenuW();                                              //~@@@@M~
    psubmenu=GetSubMenuW(pmenu,1);                                 //~vbd3R~
    enableselectall =Mpxemain->cpupdateselectall();                //~vbd2R~
    enablecopy =Mpxemain->cpupdatecopy();                          //~v51dI~
    enablecut  =Mpxemain->cpupdatecut();                           //~v51dI~
    enablepaste=Mpxemain->cpupdatepaste();                         //~v51dI~
    enablepastev=Mpxemain->cpupdatepastestd();                     //~v66hI~
UTRACEP("enable mainmenu copy=%d->%d,cut=%d->%d,paste=%d->%d,pasteV=%d->%d\n",//~v66ER~
  	Menablecopy,enablecopy,Menablecut,enablecut,Menablepaste,enablepaste,Menablepastev,enablepastev);//~v66ER~
    if (enableselectall!=Menableselectall)                         //~vbd2R~
    {                                                              //~vbd2R~
    	chngsw=1;                                                  //~vbd2R~
    	Menableselectall=enableselectall;                          //~vbd2R~
        flag=flag0|(enableselectall ? MF_ENABLED : MF_GRAYED);     //~vbd2R~
    	psubmenu->EnableMenuItem(0,flag);                  //~vbd2R~//~vbd3R~
    }                                                              //~vbd2R~
    if (enablecopy!=Menablecopy)                                   //~v51dI~
    {                                                              //~v51dI~
    	chngsw=1;                                                  //~v66mR~
    	Menablecopy=enablecopy;                                    //~v51dI~
        flag=flag0|(enablecopy ? MF_ENABLED : MF_GRAYED);          //~v51dR~
//  	pmenu->EnableMenuItem(ID_EDIT_COPY2,flag);                 //~v51dR~
    	pmenu->EnableMenuItem(APPENDPOS+1,flag);                   //~v51dI~
    	psubmenu->EnableMenuItem(2,flag);                     //~vbd2R~//~vbd3R~
    }                                                              //~v51dI~
    if (enablecut !=Menablecut )                                   //~v51dI~
    {                                                              //~v51dI~
    	chngsw=1;                                                  //~v66mR~
    	Menablecut=enablecut;                                      //~v51dR~
        flag=flag0|(enablecut  ? MF_ENABLED : MF_GRAYED);          //~v51dR~
//  	pmenu->EnableMenuItem(ID_EDIT_CUT2 ,flag);                 //~v51dR~
//  	pmenu->EnableMenuItem(ID_EDIT_CLEAR,flag);                 //~v51dR~
    	pmenu->EnableMenuItem(APPENDPOS+0,flag);                   //~v51dI~
    	psubmenu->EnableMenuItem(1,flag);   //Cut                  //~vbd2R~//~vbd3R~
    	pmenu->EnableMenuItem(APPENDPOS+2,flag);                   //~v51dI~
    	psubmenu->EnableMenuItem(3,flag);   //Clear                  //~vbd2R~//~vbd3R~
    }                                                              //~v51dI~
    if (enablepastev!=Menablepastev)                               //~v66hI~
    {                                                              //~v66hI~
    	chngsw=1;                                                  //~v66mI~
    	Menablepastev=enablepastev;                                //~v66hI~
        flag=flag0|(enablepastev ? MF_ENABLED : MF_GRAYED);        //~v66hI~
    	pmenu->EnableMenuItem(APPENDPOS+3,flag);                   //~v66hI~
    	psubmenu->EnableMenuItem(4,flag);  //PasteV                   //~vbd2R~//~vbd3R~
    }                                                              //~v66hI~
    if (enablepaste!=Menablepaste)                                 //~v51dI~
    {                                                              //~v51dI~
    	chngsw=1;                                                  //~v66mR~
    	Menablepaste=enablepaste;                                  //~v51dR~
        flag=flag0|(enablepaste ? MF_ENABLED : MF_GRAYED);         //~v51dR~
//  	pmenu->EnableMenuItem(ID_EDIT_PASTE2,flag);                //~v51dR~
//  	pmenu->EnableMenuItem(ID_EDIT_PASTE_REP,flag);             //~v51dR~
//  	pmenu->EnableMenuItem(APPENDPOS+3,flag);                   //~v66hR~
    	pmenu->EnableMenuItem(APPENDPOS+4,flag);                   //~v51dI~
    	psubmenu->EnableMenuItem(5,flag);   //Paste(Ins)                  //~vbd2R~//~vbd3R~
    	pmenu->EnableMenuItem(APPENDPOS+5,flag);                   //~v66hI~
    	psubmenu->EnableMenuItem(6,flag);   //Paste(Rep)                  //~vbd2R~//~vbd3R~
    }                                                              //~v51dI~
    if (chngsw)                                                    //~v66mR~
//  	Invalidate(FALSE);                                         //~v51dR~
    	DrawMenuBar();                                             //~v66mR~
    return 0;                                                      //~v51dI~
}//enablemainmenu                                                  //~v51dI~
//***********************************************                  //~3103I~
int  CMainFrame::updatemenu(int Pfloatsw,CMenu *Ppmenu)            //~3103R~
{                                                                  //~3103I~
	int ii,jj,kk,itemctr,cmdid;                                    //~3104R~
//  int actid=IDR_MAINFRAME_DYN;                                   //~3103M~//~@@@@R~
    char menutext[64];                                             //~3103I~
    CMenu *psubmenu;                                               //~3103R~
    ACCEL *pact,*pact0;                                            //~3103R~
    TCHAR *ptcmenutext=(TCHAR*)menutext;                           //~@@@@I~
    CMenuHandle menuh;                                             //~@@@@I~
//***************************                                      //~3103I~
	if (Museact)	//accelerator use                              //~3103I~
    {                                                              //~3103I~
//  	if (!Pfloatsw)	//main manue                               //~3103R~//~@@@@R~
//      	LoadAccelTable(MAKEINTRESOURCE(actid));                //~@@@@R~
        if (!Mpact)                                                //~3104I~
        {                                                          //~3104I~
//  		Mactno=CopyAcceleratorTable(m_hAccelTable,NULL,0);//act entryno//~3104R~//~@@@@R~
    		Mactno=CopyAcceleratorTable(Mcacc.m_hAccel,NULL,0);//act entryno,class method assert NULL//~@@@@R~
//      	Mpact=(ACCEL*)umemalloc(Mactno*sizeof(ACCEL));         //~v53tR~
        	Mpact=(ACCEL*)wxemalloc(Mactno*sizeof(ACCEL));//alloc out of xe//~v53tR~
//  		CopyAcceleratorTable(m_hAccelTable,Mpact,Mactno);//act entryno//~3104R~//~@@@@R~
    		Mcacc.CopyAcceleratorTable(Mpact,Mactno);//act entryno //~@@@@I~
        }                                                          //~3104I~
        pact0=Mpact;                                               //~3104I~
    }                                                              //~3103I~
    else                                                           //~3103I~
    	pact0=0;                                                   //~3103I~
    for (jj=0;;jj++)                                               //~3103I~
    {                                                              //~3103I~
//  	psubmenu=Ppmenu->GetSubMenu(jj);                           //~@@@@R~
//      if (!psubmenu)                                             //~3103I~//~@@@@R~
//      	break;                                                 //~3103I~//~@@@@R~
    	menuh=Ppmenu->GetSubMenu(jj);                              //~@@@@I~
        if (menuh)                                                 //~@@@@I~
        	break;                                                 //~@@@@I~
        psubmenu=&menuh;                                           //~@@@@I~
    	itemctr=psubmenu->GetMenuItemCount();                      //~3103I~
        for (ii=0;ii<itemctr;ii++)                                 //~3103I~
        {                                                          //~3103I~
            cmdid=psubmenu->GetMenuItemID(ii);	//cmd              //~3103R~
            if (pact0)                                             //~3103R~
            {                                                      //~3103I~
                for (pact=pact0,kk=0;kk<Mactno;kk++,pact++)        //~3104R~
                    if (pact->cmd==cmdid)                          //~3103I~
                        break;                                     //~3103I~
                if (kk>=Mactno)                                    //~3104R~
                    continue;                                      //~3103I~
            }                                                      //~3103I~
            else                                                   //~3103I~
            	pact=0;                                            //~3103I~
//          psubmenu->GetMenuString(ii,menutext,sizeof(menutext),MF_BYPOSITION);//~@@@@R~
            psubmenu->GetMenuString(ii,ptcmenutext,sizeof(menutext),MF_BYPOSITION);//~@@@@R~
			if (updatemenutext(menutext,pact))                     //~3103I~
//              psubmenu->ModifyMenu(ii,MF_BYPOSITION,cmdid,menutext);//~@@@@R~
                psubmenu->ModifyMenu(ii,MF_BYPOSITION,cmdid,ptcmenutext);//~@@@@R~
        }//in popup menu                                           //~3103I~
    }//all sub menu                                                //~3103I~
    return 0;                                                      //~3103I~
}//updatemenu                                                      //~3103I~
//***********************************************                  //~3103I~
//*ret 0:no update required                                        //~3103I~
//***********************************************                  //~3103I~
int  CMainFrame::updatemenutext(char *Ptext,ACCEL *Ppact)          //~3103R~
{                                                                  //~3103I~
	int len;                                                       //~3103I~
    char *pc,*tabpos;                                              //~3103R~
//***************************                                      //~3103I~
	tabpos=strchr(Ptext,'\t');                                     //~3103I~
    if (tabpos)	//tabfound                                         //~3103I~
    {                                                              //~3103I~
    	if (Ppact) 		//set req                                  //~3103I~
        	return 0;	//already set                              //~3103I~
        *tabpos=0;		//clear accelerator id                     //~3103I~
    }                                                              //~3103I~
    else	//no tab                                               //~3103I~
    {                                                              //~3103I~
    	if (!Ppact)     //clear req                                //~3103R~
        	return 0;	//already cleared                          //~3103I~
        tabpos=Ptext+strlen(Ptext);                                //~3103R~
        *tabpos++='\t';                                            //~3103I~
        if (Ppact->fVirt & FSHIFT)                                 //~3103R~
        	pc="Shift+";                                           //~3103I~
        else                                                       //~3103I~
        if (Ppact->fVirt & FCONTROL)                               //~3103R~
        	pc="Ctrl+";                                            //~3103I~
        else                                                       //~3103I~
        if (Ppact->fVirt & FALT)                                   //~3103R~
        	pc="Alt+";                                             //~3103I~
        else                                                       //~3103I~
        	pc="";                                                 //~3103I~
        len=strlen(pc);                                            //~3103I~
        memcpy(tabpos,pc,(UINT)len);                               //~3103I~
        tabpos+=len;                                               //~3103R~
        *tabpos++=(char)Ppact->key;                                //~3103R~
        *tabpos=0;                                                 //~3103R~
    }                                                              //~3103I~
    return 1;                                                      //~3103I~
}//updatemenutext                                                  //~3103I~
//***********************************************                  //~3104I~
//*update mein manue text                                          //~3104I~
//*return:1:updated                                                //~3104I~
//***********************************************                  //~3104I~
int  CMainFrame::updatemainmenu(int Pusemk)                        //~3105R~
{                                                                  //~3104I~
    CMenu *pmenu;                                                  //~3105I~
	int ii,cmdid,updatesw=0;                                       //~3104R~
    char menutext[64];                                             //~3104I~
    TCHAR *ptcmenutext=(TCHAR*)menutext;                           //~@@@@I~
//***************************                                      //~3104I~
	if (Pusemk!=-1)        //init req from wxe.cpp                 //~3105I~
    	if (Musemk==Pusemk)   //not changed                        //~3105I~
            return 0;                                              //~3105I~
        else                                                       //~3105I~
            Musemk=Pusemk;                                         //~3105I~
//  pmenu=GetMenu();                                               //~@@@@R~
    pmenu=GetMenuW();                                              //~@@@@I~
    for (ii=0;;ii++)                                               //~3104I~
    {                                                              //~3104I~
        cmdid=pmenu->GetMenuItemID(ii);	//cmd                      //~3105R~
//      if (!pmenu->GetMenuString(ii,menutext,sizeof(menutext),MF_BYPOSITION))//~@@@@R~
        if (!pmenu->GetMenuString(ii,ptcmenutext,sizeof(menutext),MF_BYPOSITION))//~@@@@I~
			break;                                                 //~3104I~
		if (updatemainmenutext(ii,menutext,Musemk))                //~3105R~
        {                                                          //~3104I~
        	updatesw=1;                                            //~3104I~
//  	    pmenu->ModifyMenu(ii,MF_BYPOSITION,cmdid,menutext);    //~@@@@R~
    	    pmenu->ModifyMenu(ii,MF_BYPOSITION,cmdid,ptcmenutext); //~@@@@I~
        }                                                          //~3104I~
    }//all sub menu                                                //~3104I~
    if (Pusemk==-1)		//initial                                  //~3105I~
		if (updatesw)                                              //~3105I~
//	    	SetMenu(pmenu);                                        //~@@@@R~
  	    	SetMenu(HMENU(pmenu));                                 //~@@@@I~
    return updatesw;                                               //~3104R~
}//updatemainmenu                                                  //~3104I~
//***********************************************                  //~vbdnI~
int  CMainFrame::updateFileMenu(int Popt)                          //~vbdnR~
{                                                                  //~vbdnI~
	CMenu *pmenu,*psubmenu;                                        //~vbdnI~
    int rc;                                                        //~vbdnR~
//********************************                                 //~vbdnI~
	pmenu=GetMenuW();                                              //~vbdnR~
	psubmenu=GetSubMenuW(pmenu,0);                                 //~vbdnI~
	rc=updatemainmenuFile(psubmenu);                               //~vbdnR~
//*toolbar save icon                                               //~vbdnI~
	rc+=updateMenuIcon(0,CHKSTF_SAVE,TOOLBARINDEX_SAVE);           //~vbdnI~
    return  rc;                                                    //~vbdnI~
}//updateFileManu                                                  //~vbdnI~
//***********************************************                  //~vbdnI~
int  CMainFrame::updateMenuIcon(int Popt,int Pchkidx,int Piconidx) //~vbdnI~
{                                                                  //~vbdnI~
	CMenu *pmenu;                                                  //~vbdnI~
    int rc=0;                                                      //~vbdnR~
	UINT enable,stat;                                              //~vbdnI~
//********************************                                 //~vbdnI~
	pmenu=GetMenuW();                                              //~vbdnI~
    enable=wxe_chkEnableFileSubmenu(0,Pchkidx)?MF_ENABLED:MF_GRAYED; //wxexei3//~vbdnI~
    stat=pmenu->GetMenuState(Piconidx,MF_BYPOSITION) & (MF_ENABLED|MF_GRAYED); //wxexei3//~vbdnI~
    UTRACEP("%s:iconidx=%d,menuid=%d,chkenable=%d,itemstatus=%x\n",UTT,Piconidx,pmenu->GetMenuItemID(Piconidx),enable,stat);//~vbdnI~
    if (stat!=enable)                                              //~vbdnI~
    {                                                              //~vbdnI~
		pmenu->EnableMenuItem(Piconidx,MF_BYPOSITION|enable);      //~vbdnI~
	    UTRACEP("%s:iconidx=%d,enable=%x\n",UTT,Piconidx,enable);  //~vbdnI~
    	DrawMenuBar();                                             //~vbdnI~
        rc=1;                                                      //~vbdnR~
    }                                                              //~vbdnI~
    return  rc;                                                    //~vbdnI~
}//updateMenuIcon                                                  //~vbdnI~
//***********************************************                  //~vbdnI~
//*update mein manue text                                          //~vbdnI~
//*return:1:updated                                                //~vbdnI~
//***********************************************                  //~vbdnI~
int  CMainFrame::updatemainmenuFile(CMenu *Pmenu)                  //~vbdnI~
{                                                                  //~vbdnI~
	int ii,updatectr=0,itemctr;                                    //~vbdnR~
	UINT enable;                                                   //~vbdnR~
    UINT stat;                                                     //~vbdnI~
    CMenu *submenu;                                                //~vbdnR~
//***************************                                      //~vbdnI~
//  submenu=GetSubMenuW(Pmenu,0);                                  //~vbdnR~
    submenu=Pmenu;                                                 //~vbdnR~
    itemctr=submenu->GetMenuItemCount();                           //~vbdnR~
    for (ii=0;ii<itemctr;ii++)                                     //~vbdnI~
    {                                                              //~vbdnI~
        stat=submenu->GetMenuState(ii,MF_BYPOSITION) & (MF_ENABLED|MF_GRAYED);//~vbdnR~
        enable=wxe_chkEnableFileSubmenu(0,ii)?MF_ENABLED:MF_GRAYED; //wxexei3//~vbdnR~
        UTRACEP("%s:ii=%d,id=%d,chkenable=%d,itemstatus=%x\n",UTT,ii,Pmenu->GetMenuItemID(ii),enable,stat);//~vbdnR~
        if (stat!=enable)                                          //~vbdnR~
        {                                                          //~vbdnI~
		    submenu->EnableMenuItem(ii,MF_BYPOSITION|enable);      //~vbdnR~
            updatectr++;                                           //~vbdnI~
        }                                                          //~vbdnI~
    }//all sub menu                                                //~vbdnI~
    return updatectr;                                              //~vbdnR~
}//updatemainmenuFile                                              //~vbdnR~
//***********************************************                  //~3104I~
//*ret 0:no update required                                        //~3104I~
//***********************************************                  //~3104I~
int  CMainFrame::updatemainmenutext(int Pmenupos,char *Ptext,int Pusemk)//~3105R~
{                                                                  //~3104I~
static char *Smenuchar="FESPH";                                    //~3104M~
    char *lppos,*sppos;                                            //~3104R~
//***************************                                      //~3104I~
	lppos=strchr(Ptext,'(');                                       //~3104I~
    if (lppos)	//left parenthesys                                 //~3104I~
    {                                                              //~3104I~
    	if (Pusemk) 		//set req                              //~3105R~
        	return 0;	//already set                              //~3104I~
        *lppos=0;		//clear accelerator id                     //~3104I~
    }                                                              //~3104I~
    else	//no lp                                                //~3104R~
    {                                                              //~3104I~
    	if (!Pusemk)     //clear req                               //~3105R~
        	return 0;	//already cleared                          //~3104I~
		sppos=strchr(Ptext,' ');    //initialy set space padding because not redrwan//~3104I~
        lppos=Ptext+strlen(Ptext);	                               //~3104R~
        if (sppos && sppos<lppos)                                  //~3104I~
        	lppos=sppos;                                           //~3104I~
        *lppos++='(';                                              //~3104I~
        *lppos++='&';                                              //~3104I~
        *lppos++=Smenuchar[Pmenupos];                              //~3104R~
        *lppos++=')';                                              //~3104I~
        *lppos=0;                                                  //~3104I~
    }                                                              //~3104I~
    return 1;                                                      //~3104I~
}//updatemainmenutext                                              //~3104I~

//********************************************************************//~v51dI~
//*parm:selected(pushed) menu                                      //~v51dI~
//********************************************************************//~v51dI~
void CMainFrame::OnInitMenu(CMenu* pMenu) 
{
//************                                                     //~v51dI~
//    CFrameWnd::OnInitMenu(pMenu);                                //~@@@@R~
}
//********************************************************************//~vbdnI~
//*Pindex:Menubar position,PswSysMenu:True if Control Menu(Move,Minimize etc)//~vbdnI~
//********************************************************************//~vbdnI~
void CMainFrame::OnInitMenuPopup(CMenu* pMenu,UINT Pindex,BOOL PswSysMenu)//~vbdnI~
{                                                                  //~vbdnI~
////************                                                   //~vbdnR~
//    UTRACEP("%s:index=%d,swContextmenu=%d\n",UTT,Pindex,PswSysMenu);//~vbdnR~
//    if (!PswSysMenu && Pindex==0)   //Menubar-File               //~vbdnR~
//        updatemainmenuFile(pMenu);                               //~vbdnR~
}                                                                  //~vbdnI~

LRESULT CMainFrame::DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
//  if (message==WM_NCMOUSEMOVE)                                   //~v66mR~
//  	if ((INT)wParam==HTMENU)                                   //~v66mR~
//  		enablemainmenu();	//enable/disable cut/paste on mainmenu//~v66mR~
	
//    return CFrameWnd::DefWindowProc(message, wParam, lParam);    //~@@@@R~
	return 0;                                                      //~@@@@I~
}

void CMainFrame::OnHelp() 
{
//  int ctxid;                                                     //~v71AR~
//******************                                               //~v55FI~
//  Mpapp->WinHelp(0,HELP_CONTENTS);                               //~v55FR~
//  Mpapp->WinHelp(0,HELP_FINDER);                                 //~v55zR~
//    if (wxegetdbcsmode())                                        //~v71AR~
//        ctxid=IDH_JAPANESE;                                      //~v71AR~
//    else                                                         //~v71AR~
//        ctxid=IDH_ENGLISH;                                       //~v71AR~
//    WinHelp(ctxid,HELP_CONTEXT);                                 //~v71AR~
	wxe_helpcall();                                                //~v71AR~
    Invalidate(FALSE);                                             //~v71AI~
}
//**********************************                               //~@@@@I~
CMenu *CMainFrame::GetMenuW()                                      //~@@@@R~
{                                                                  //~@@@@I~
	HMENU hmenu;                                                   //~@@@@I~
//******************                                               //~@@@@I~
    hmenu=GetMenu();        //MainFrm.h do "setMenu(NULL);"        //~@@@@R~
//  hmenu=m_CmdBar.GetMenu();                                //~v782I~//~@@@@R~
	return new CMenu(hmenu);                                       //~@@@@I~
}                                                                  //~@@@@I~
//**********************************                               //~vbd3I~
CMenu *CMainFrame::GetSubMenuW(CMenu *Pmenu,int Ppos)              //~vbd3R~
{                                                                  //~vbd3I~
	HMENU hmenu;                                                   //~vbd3I~
//******************                                               //~vbd3I~
    hmenu=Pmenu->GetSubMenu(Ppos);                                 //~vbd3R~
	return new CMenu(hmenu);                                       //~vbd3I~
}                                                                  //~vbd3I~
//************************************************************     //~@@@@I~
//*file dialog                                                     //~@@@@I~
//************************************************************     //~@@@@I~
LRESULT CMainFrame::OnFileNew(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)//~@@@@I~
{                                                                  //~@@@@I~
    char fnm[_MAX_PATH];                                           //~@@@@I~
    int rc;                                                        //~@@@@I~
//*********************************                                //~@@@@I~
    *fnm=0;                                                        //~vbdoR~
	rc=fileselectiondlg(1/*new*/,fnm);                             //~@@@@I~
//  m_view.GetDocument()->OnNewDocument();                         //~@@@@R~
  if (rc<4)                                                        //~vbdoR~
    m_view.GetDocument()->OnNewDocument(fnm);                      //~@@@@I~
    return 0;                                                      //~@@@@I~
}                                                                  //~@@@@I~
//************************************************************     //~@@@@I~
void CMainFrame::OnFileOpen(UINT unotifyCode,int nID,HWND wndCtl)  //~@@@@I~
{                                                                  //~@@@@I~
    char fnm[_MAX_PATH];                                           //~@@@@I~
    int rc;                                                        //~@@@@I~
//*********************************                                //~@@@@I~
    *fnm=0;                                                        //~vbdoR~
	rc=fileselectiondlg(2/*Open*/,fnm);                            //~@@@@R~
    if (rc<4)                                                      //~@@@@R~
	    m_view.GetDocument()->OnOpenDocument(rc==1,fnm);           //~@@@@R~
}                                                                  //~@@@@I~
//************************************************************     //~@@@@I~
void CMainFrame::OnFileSave(UINT unotifyCode,int nID,HWND wndCtl)  //~@@@@I~
{                                                                  //~@@@@I~
//  if (!wxe_chkEnableFileSubmenu(CHKSTFO_MSG,CHKSTF_SAVE)) //WM_INITMENUPOPUP is issued also by Ctrl+x//~vbdnR~
//        return;                                                  //~vbdnR~
    m_view.GetDocument()->OnSaveDocument(NULL);                    //~@@@@R~
}                                                                  //~@@@@I~
//************************************************************     //~@@@@I~
void CMainFrame::OnFileSaveAs(UINT unotifyCode,int nID,HWND wndCtl)//~@@@@I~
{                                                                  //~@@@@I~
    char fnm[_MAX_PATH];                                           //~@@@@I~
    int rc;                                                        //~@@@@I~
//*********************************                                //~@@@@I~
//  if (!wxe_chkEnableFileSubmenu(CHKSTFO_MSG,CHKSTF_SAVEAS)) //WM_INITMENUPOPUP is issued also by Ctrl+x//~vbdnR~
//  	return;                                                    //~vbdnR~
	*fnm=0;                                                        //~@@@@I~
	rc=fileselectiondlg(3/*SaveAs*/,fnm);                          //~@@@@R~
    if (!rc)                                                       //~@@@@I~
	    m_view.GetDocument()->OnSaveDocument(fnm);                 //~@@@@I~
}                                                                  //~@@@@I~
//************************************************************     //~vbdnI~
//*OnFilePrint                                                     //~vbdnI~
//************************************************************     //~vbdnI~
void CMainFrame::OnFilePrint(UINT unotifyCode,int nID,HWND wndCtl) //~vbdnI~
{                                                                  //~vbdnI~
//  if (!wxe_chkEnableFileSubmenu(CHKSTFO_MSG,CHKSTF_PRINT)) //WM_INITMENUPOPUP is issued also by Ctrl+x//~vbdnR~
//      return;                                                    //~vbdnR~
    m_view.OnFilePrint();  //through wxeview, goto wxeprt          //~vbdnI~
}                                                                  //~vbdnI~
//************************************************************     //~@@@@I~
//*open file dialog as Modal                                       //~@@@@I~
//*rc:0:ok,1:ok with ReadOnly open,4:cancel                        //~@@@@I~
//************************************************************     //~@@@@I~
int CMainFrame::fileselectiondlg(int Pcmd,char *Pfnm)              //~@@@@R~
{                                                                  //~@@@@I~
	int flag,rc;                                                   //~@@@@I~s
    char *pext=NULL;	//default extension when extension is missing from filename//~@@@@R~
    char *pfnm=NULL,*pfilter;                                      //~@@@@I~
    char customfilter[_MAX_PATH]={0};                              //~@@@@R~
    BOOLEAN swopen=TRUE;                                           //~@@@@I~
//*********************************                                //~@@@@I~
    flag=0;                                                        //~@@@@R~
//  pfilter="All files (*.*)\0*.*\0\0";                            //~@@@@R~
//    pfilter="Text File(*.txt)\0*.txt\0All files (*.*)\0*.*\0\0"; //~@@@@R~
    pfilter=                                                       //~@@@@I~
            "All files (*.*)\0*.*\0"                               //~@@@@I~
            "Text (.txt)\0*.txt\0"                                 //~@@@@R~
            "C/C++ (.c,.cpp,.h,.hpp,.cxx)\0*.c;*.cpp;*.h;*.hpp;*.cxx\0"//~@@@@R~
            "Java (.java)\0*.java\0"                               //~@@@@I~
            "Html (.html,.htm)\0*.html;*.htm\0"                    //~@@@@I~
            "Xml (.xml)\0*.xml\0"                                  //~@@@@I~
            "\0";                                                  //~@@@@I~
    switch(Pcmd)                                                   //~@@@@I~
    {                                                              //~@@@@I~
    case 1://new                                                   //~@@@@I~
		flag|=OFN_HIDEREADONLY;	//hide readonly chkbox             //~@@@@R~
    	pfnm="NewFile";                                            //~@@@@I~
    	break;                                                     //~@@@@I~
    case 2://open                                                  //~@@@@I~
    	break;                                                     //~@@@@I~
    case 3://saveas                                                //~@@@@I~
		flag|=OFN_HIDEREADONLY;	//hide readonly chkbox             //~@@@@R~
		flag|=OFN_OVERWRITEPROMPT;//prompt overwrite existing file when save//~@@@@I~
        swopen=FALSE;                                              //~@@@@I~
	    pfnm=Pfnm;      //default filename,from current open       //~@@@@M~
    	break;                                                     //~@@@@I~
    }                                                              //~@@@@I~
	CFileDialog dlg(swopen,pext,pfnm,flag,pfilter/*,parent hwnd*/);//~@@@@R~
    dlg.m_ofn.lpstrCustomFilter=customfilter;                      //~@@@@I~
    dlg.m_ofn.nMaxCustFilter=sizeof(customfilter);                 //~@@@@I~
    dlg.m_ofn.nFilterIndex=0;                                      //~@@@@I~
//  rc=dlg.DoModal();                                              //~@@@@I~//~vb3wR~
    rc=(int)dlg.DoModal();                                         //~vb3wI~
    if (rc==IDOK)                                                  //~@@@@I~
    {                                                              //~@@@@I~
        pfnm=dlg.m_szFileName;                                     //~@@@@R~
        strcpy(Pfnm,pfnm);                                         //~@@@@I~
        if (Pcmd==2 && dlg.GetReadOnlyPref())	//open as readonly(chkbox on)//~@@@@I~
        	rc=1;                                                  //~@@@@I~
        else                                                       //~@@@@I~
        	rc=0;                                                  //~@@@@R~
    }                                                              //~@@@@I~
    else                                                           //~@@@@I~
    	rc=4;	//cancel                                           //~@@@@I~
    return rc;                                                     //~@@@@I~
}                                                                  //~@@@@I~
