//*CID://+vbj2R~:                             update#=  250;       //~vbj2R~
//***************************************************************************//~v516I~
//vbj2:180424 popup menu on cmd history list                       //~vbj2I~
//vbd2:171114 (Wxe)Add SelectAll menuitem                          //~vbd2I~
//vba3:170715 msvs2017 warning;(Windows:PTR:64bit,ULONG 32bit)     //~vba3I~
//vb3w:160621 w64 compiler warning                                 //~vb3wI~
//vavC:140430 change Dialog to modeal                              //~vak7I~
//vak7:130906 redirect memcpy to memmove when overlaped            //~vak7I~
//va8a:100926 (WXE)end wxp work at end print                       //~va8aI~
//v79z:080916 DBCS tbl for C and K of CJK                          //~v79zI~
//v77w:080117 visual studio 2005 compiler warning(LRESULT:BOOL)    //~v77wI~
//v69g:060521 (WXE)tilt wheel mouse generate WM_VSCROLL/WM_HSCROLL by mycrosoft spec//~v69gI~
//            if scroll bar exist.(both vertical and horizontal is requred to genarate both)//~v69gI~
//v69f:060521 (WXE)xbutton1/2 support;browser backk/forwardlock on status for up/down arrow key to scroll up/down//~v69fI~
//v68p:060416 (WXE:BUG)screen shake at IME composition window close//~v68pI~
//v688:060324 (BUG)menu item enable/disable dose not sync with popup//~v688I~
//v685:060322 dnd support "file copy into the dir slected" and even in inter-split-screen.//~v685I~
//v67K:060205 (BUG:WXE)beep by Alt+char if not menu key;correction of v51U//~v67KI~
//v66h:051023 C & P;region mode by mouse; mouse drag->region mode,A+mouse drag->block mode//~v66hI~
//            delete Ctrl+V(preview) from menu and add to icon menu and popup menu//~v66hI~
//v59z:041115 (WXE)more after v53q(free print work leaved by print cancel)//~v59zI~
//v55u:040229 (WXE)add open with for dir-list                      //~v55uI~
//v51U:030808 (WXE:BUG)rc of WM_SYSKEYDOWN should be 0.(beep by alt+".":macro pair search)//~v51UI~
//v51w:030615 (WXE)icon for MDOS and Explorer                      //~v51wI~
//v51e:030517 (WXE:BUG)drug drop need svreen invalidate            //~v516I~
//v516:030223 (WXE)shortcut key for dos prompt                     //~v516I~
//***************************************************************************//~v516I~
// wxeView.cpp : CWxeView class                                    //~v66hR~
//

#pragma once                                                       //~@@@@I~
#include <stdafx.h>                                                //~@@@@R~
#define NO_MACRO_REDIRECT                                          //~vak7I~
#include <ulib.h>                                                  //~vak7I~
#include <MainFrm.h>                                               //~@@@@I~
                                                                   //~2909I~
#include "utrace.h"                                                //~2909I~
                                                                   //~2909I~
#include "wxe.h"

#include "wxedef.h"                                                //~2811M~
#include "wxefile.h"                                               //~2817I~
#include "wxeDoc.h"
#include "wxemain.h"                                               //~2831I~
#include "wxedlg.h"                                                //~2817I~
#include "wxepage.h"                                               //~2B03I~
#include "wxeView.h"
#include "wxecsub.h"                                               //~2907I~
#include "wxexei.h"                                                //~v516I~

#ifdef _DEBUG
//#define new DEBUG_NEW                                            //~@@@@R~
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
                                                                   //~@@@@I~
                                                                   //~@@@@I~
//BEGIN_MESSAGE_MAP(CWxeView)                                      //~@@@@I~
//    ON_WM_KEYDOWN()                                              //~@@@@I~
//    ON_WM_KEYUP()                                                //~@@@@I~
//    ON_WM_CREATE()                                               //~@@@@I~
//    ON_COMMAND(IDC_FONT, OnFont)                                 //~@@@@I~
//    ON_WM_SIZE()                                                 //~@@@@I~
//    ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, OnUpdateEditPaste)       //~@@@@I~
//    ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)                       //~@@@@I~
//    ON_UPDATE_COMMAND_UI(ID_EDIT_COPY, OnUpdateEditCopy)         //~@@@@I~
//    ON_COMMAND(ID_EDIT_COPY, OnEditCopy)                         //~@@@@I~
//    ON_UPDATE_COMMAND_UI(ID_EDIT_CUT, OnUpdateEditCut)           //~@@@@I~
//    ON_COMMAND(ID_EDIT_CUT, OnEditCut)                           //~@@@@I~
//    ON_WM_LBUTTONDOWN()                                          //~@@@@I~
//    ON_WM_LBUTTONUP()                                            //~@@@@I~
//    ON_WM_MOUSEMOVE()                                            //~@@@@I~
//    ON_WM_RBUTTONDOWN()                                          //~@@@@I~
//    ON_WM_CHAR()                                                 //~@@@@I~
//    ON_WM_SETFOCUS()                                             //~@@@@I~
//    ON_WM_KILLFOCUS()                                            //~@@@@I~
//    ON_COMMAND(ID_EDIT_PASTE_REP, OnEditPasteRep)                //~@@@@I~
//    ON_COMMAND(ID_EDIT_PASTE_STD, OnEditPasteStd)                //~@@@@I~
//    ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE_REP, OnUpdateEditPasteRep)//~@@@@I~
//    ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE_STD, OnUpdateEditPasteStd)//~@@@@I~
//    ON_COMMAND(ID_EDIT_CLEAR, OnEditClear)                       //~@@@@I~
//    ON_UPDATE_COMMAND_UI(ID_EDIT_CLEAR, OnUpdateEditClear)       //~@@@@I~
//    ON_WM_MOUSEWHEEL()                                           //~@@@@I~
//    ON_WM_DROPFILES()                                            //~@@@@I~
//    ON_COMMAND(ID_FILE_SCRPRT, OnFileScrprt)                     //~@@@@I~
//    ON_COMMAND(ID_PAGE_SETUP, OnPageSetup)                       //~@@@@I~
//    ON_COMMAND(ID_EDIT_END, OnEditEnd)                           //~@@@@I~
//    ON_COMMAND(ID_EDIT_CANCEL, OnEditCancel)                     //~@@@@I~
//    ON_WM_LBUTTONDBLCLK()                                        //~@@@@I~
//    ON_WM_TIMER()                                                //~@@@@I~
//    ON_COMMAND(ID_FILE_DOS, OnFileDos)                           //~@@@@I~
//    ON_COMMAND(ID_FILE_EXPLORER, OnEditExplorer)                 //~@@@@I~
//    ON_COMMAND(ID_FILE_OPENWITH, OnFileOpenwith)                 //~@@@@I~
//    ON_UPDATE_COMMAND_UI(ID_FILE_OPENWITH, OnUpdateFileOpenwith) //~@@@@I~
//    ON_WM_HSCROLL()                                              //~@@@@I~
//    ON_WM_VSCROLL()                                              //~@@@@I~
//    ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)                //~@@@@I~
//    ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)         //~@@@@I~
//    ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview) //~@@@@I~
//    ON_COMMAND(IDOK, CWxeView::OnOk)                             //~@@@@I~
//    ON_MESSAGE(ID_FILE_DNDCOPY,CWxeView::OnFileDNDCopy)          //~@@@@I~
//END_MESSAGE_MAP()                                                //~@@@@I~


/////////////////////////////////////////////////////////////////////////////
// CWxeView constructor                                            //~v66hR~

CWxeView::CWxeView()
{
	Mpvscrollbar=0;                                                //~v69gI~
	Mphscrollbar=0;                                                //~v69gI~
}

CWxeView::~CWxeView()
{
	if (Mpvscrollbar)                                              //~v69gI~
		delete Mpvscrollbar;                                       //~v69gI~
	if (Mphscrollbar)                                              //~v69gI~
		delete Mphscrollbar;                                       //~v69gI~
	Mpvscrollbar=0;                                                //~v69gI~
	Mphscrollbar=0;                                                //~v69gI~
    UTRACE_INIT(0,3);	//close trace                              //~2A12I~
}

BOOL CWxeView::PreCreateWindow(CREATESTRUCT& cs)
{
//  return CView::PreCreateWindow(cs);                             //~@@@@R~
	return TRUE;                                                   //~@@@@I~
}

/////////////////////////////////////////////////////////////////////////////
// CWxeView class paint                                            //~v66hR~

void CWxeView::OnDraw(CDC* pDC)
{
    char fontface[64];                                             //~2C03I~
//************************                                         //~2C03I~
	CWxeDoc* pDoc = GetDocument();                                 //~2817R~
//    ASSERT_VALID(pDoc);                                          //~@@@@R~
//  pDC->GetTextFace(64,fontface);                                 //~@@@@R~
    pDC->GetTextFace((LPTSTR)fontface,sizeof(fontface));                   //~@@@@I~
UTRACEP("default font=%s\n",fontface);                             //~2C03R~
    Mwxemain.draw(pDC,pDoc);                                       //~2827R~
}
///////////////////////////////////////////////////////////////////////////////~@@@@I~
void CWxeView::OnPaint(HDC Phdc)                                   //~@@@@R~
{                                                                  //~@@@@I~
//****************                                                 //~@@@@I~
//    if (Phdc)                                                    //~@@@@R~
//    {                                                            //~@@@@R~
//        CDC  dc(Phdc);                                           //~@@@@R~
//        OnDraw(&dc);                                             //~@@@@R~
//    }                                                            //~@@@@R~
//    else                                                         //~@@@@R~
    {                                                              //~@@@@I~
		CPaintDC dc(m_hWnd);                                       //~@@@@I~
	    OnDraw(&dc);                                               //~@@@@I~
    }                                                              //~@@@@I~
}                                                                  //~@@@@I~

/////////////////////////////////////////////////////////////////////////////
// CWxeView class print                                            //~v66hR~

//BOOL CWxeView::OnPreparePrinting(CPrintInfo* pInfo)              //~@@@@R~
BOOL CWxeView::OnPreparePrinting()                                 //~@@@@I~
{
	int rc;                                                        //~2B10I~
//  rc=Mwxemain.onprepareprinting(pInfo);                          //~@@@@R~
    rc=Mwxemain.onprepareprinting(1/*printsw*/);                   //~@@@@I~
    if (rc==FALSE)                                                 //~2B10I~
    	return FALSE;                                              //~2B10I~
//  return DoPreparePrinting(pInfo);                               //~v59zR~
//  rc=DoPreparePrinting(pInfo);                                   //~@@@@R~
    rc=Mwxemain.printdlg();                                        //~@@@@R~
    if (rc==FALSE)  //print canceld                                //~v59zI~
//  	Mwxemain.afterprint();   //free work                       //~v59zR~//~va8aR~
    	Mwxemain.afterprint(2);   //free work,2:cancel             //~va8aI~
    return rc;                                                     //~v59zI~
}

void CWxeView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)        //~2A27R~
{
}

void CWxeView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)          //~2B04R~
{
	Mwxemain.onendprinting(pDC,pInfo);                             //~2B04I~
}

/////////////////////////////////////////////////////////////////////////////
// CWxeView ƒNƒ‰ƒX‚Ìf’f

#ifdef _DEBUG                                                      //~@@@@R~
//void CWxeView::AssertValid() const                               //~@@@@R~
//{                                                                //~@@@@R~
//    CView::AssertValid();                                        //~@@@@R~
//}                                                                //~@@@@R~

//void CWxeView::Dump(CDumpContext& dc) const                      //~@@@@R~
//{                                                                //~@@@@R~
//    CView::Dump(dc);                                             //~@@@@R~
//}                                                                //~@@@@R~

CWxeDoc* CWxeView::GetDocument() // inline if release version      //~v66hR~
{
//    ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWxeDoc)));       //~@@@@R~
	return (CWxeDoc*)m_pDocument;
}
#endif //_DEBUG                                                    //~@@@@R~

/////////////////////////////////////////////////////////////////////////////

//BOOL CWxeView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)//~@@@@R~
//{                                                                //~@@@@R~
//    int rc;                                                      //~@@@@R~
////*********************                                          //~@@@@R~
//     Mpmainframewnd=pParentWnd;                                  //~@@@@R~
////   return CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);//~@@@@R~
//     rc=CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);//~@@@@R~
//     return rc;                                                  //~@@@@R~
//}                                                                //~@@@@R~
HWND CWxeView::Create(CMainFrame *pParentWnd,RECT pRect,LPCTSTR pWindowname, DWORD dwStyle,DWORD dwExStyle)//~@@@@R~
{                                                                  //~@@@@I~
    HWND rc;                                                        //~@@@@I~
//*********************                                            //~@@@@I~
     Mpmainframewnd=pParentWnd;                                    //~@@@@I~
     rc=CWindowImpl::Create(pParentWnd->m_hWnd,pRect,pWindowname,dwStyle,dwExStyle);//~@@@@R~
     return rc;                                                    //~@@@@I~
}                                                                  //~@@@@I~

void CWxeView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
    UTRACEP("OnKeyDown ch=%x,rep=%d,flag=%08x\n",nChar,nRepCnt,nFlags);//~2909R~
	
//    CWnd *hwnd=GetFocus();                                       //~v688R~
//    UTRACEP("focus-window=%p\n",hwnd);                           //~v688R~
//    hwnd=GetActiveWindow();                                      //~v688R~
//    UTRACEP("active-window=%p\n",hwnd);                          //~v688R~
	Mwxemain.onkeydown(nChar, nRepCnt, nFlags);                    //~2914R~
}
void CWxeView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)       //~2908M~
{                                                                  //~2908M~
    UTRACEP("OnChar key ch=%x,rep=%d,flag=%08x\n",nChar,nRepCnt,nFlags);//~2916R~
	                                                               //~2908M~
	Mwxemain.onchar(nChar, nRepCnt, nFlags);                       //~2914R~
}                                                                  //~2908M~

void CWxeView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
//  uerrmsgbox("keyup key=%x,flag=%x",0,nChar,nFlags);             //~2908R~
    UTRACEP("OnKeyUp   ch=%x,rep=%d,flag=%08x\n",nChar,nRepCnt,nFlags);//~2909R~
	Mwxemain.onkeyup(nChar, nRepCnt, nFlags);                      //~2914R~
}

LRESULT CWxeView::DefWindowProcW(UINT message, WPARAM wParam, LPARAM lParam)//~@@@@I~
{                                                                  //~@@@@I~
    BOOL rc;                                                       //~@@@@I~
//**************************                                       //~@@@@I~
//  rc=CWxeView::DefWindowProc(message,wParam,lParam);             //~@@@@I~//~vb3wR~
    rc=(BOOL)CWxeView::DefWindowProc(message,wParam,lParam);       //~vb3wI~
    SetMsgHandled(rc);	//reset action by MESSAGE_RANGE_HANDLER_EX //~@@@@R~
//  return rc;                                                     //~@@@@I~//~vb3wR~
    return (LRESULT)rc;                                            //~vb3wI~
}                                                                  //~@@@@I~
LRESULT CWxeView::DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	int appcmdid;                                                  //~v69fI~
//**************************                                       //~2914I~
    UTRACEP("DefWinPro msg=%08x,parm=%08x,lparm=%08x\n",message,wParam,lParam);//~2909R~
//  CFrameWnd *pwnd=GetParentFrame();                              //~@@@@R~
    CFrameWnd *pwnd=Mpmainframewnd;                                //~@@@@I~
    UTRACEP("Parent=%08x hwnd=%08x\n",pwnd,pwnd->m_hWnd);          //~2A13R~
	if  (message==WM_SYSKEYDOWN||message==WM_SYSKEYUP||message==WM_SYSCHAR)//~2914R~
    {                                                              //~v79zI~
    	if (Mwxemain.syskeyproc(message,wParam,lParam))            //~2C02R~
        {                                                          //~v66hI~
//      	return TRUE;                                           //~v51UR~
//      	return 0;                                              //~v67KR~
    		UTRACEP("syskeyproc returned TRUE\n");                 //~v79zR~
        	return TRUE;                                           //~v66hI~
        }                                                          //~v66hI~
    	UTRACEP("syskeyproc returned FALSE\n");                    //~v79zI~
    }                                                              //~v79zI~
	if  (message==WM_MOUSEACTIVATE)                                //~2A13R~
//   	if (wParam!=(ULONG)(Mpmainframewnd->m_hWnd))               //~2A13R~//~vba3R~
     	if (wParam!=(ULPTR)(Mpmainframewnd->m_hWnd))               //~vba3I~
//      	return MA_NOACTIVATE;                                  //~2A13R~
        	return MA_NOACTIVATEANDEAT;                            //~2A13R~
	if  (message==WM_IME_STARTCOMPOSITION //open                   //~3104R~
	||   message==WM_IME_ENDCOMPOSITION   //close                  //~3208I~
	||   message==WM_IME_COMPOSITION      //conversion start       //~3104R~
	||   message==WM_IME_CHAR)            //send DBCS              //~3104I~
    {                                                              //~v79zI~
//  	Mwxemain.kbdimectl(Mpmainframewnd->m_hWnd,message);        //~v79zR~
    	if (Mwxemain.kbdimectl(Mpmainframewnd->m_hWnd,message,wParam,lParam))	//processed,skip defwinproc//~v79zR~
        	return TRUE;                                           //~v79zI~
    }                                                              //~v79zI~
    if  (message==WM_ERASEBKGND)                                   //~v68pR~
    {                                                              //~v68pR~
    	return TRUE;  //APP will erase,cause of screen flicker     //~v68pR~
    }                                                              //~v68pR~
    if  (message==WM_APPCOMMAND)                                   //~v69fI~
    {                                                              //~v69fI~
    	appcmdid=((ULONG)lParam>>16)&~FAPPCOMMAND_MASK;            //~v69fR~
        return Mwxemain.mouseappcmd(appcmdid);                     //~v69fR~
    }                                                              //~v69fI~
//    if  (message==WM_VSCROLL||message==WM_HSCROLL)               //~v69gR~
//    {                                                            //~v69gR~
//        scrollcode=(ULONG)wParam & 0xffff;  //low                //~v69gR~
//        return Mwxemain.mousescrollbar(message,scrollcode);      //~v69gR~
//    }                                                            //~v69gR~
//  return CView::DefWindowProc(message, wParam, lParam);          //~@@@@R~
    return FALSE;                                                  //~@@@@I~
}

int CWxeView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
//  if (CView::OnCreate(lpCreateStruct) == -1)                     //~@@@@R~
//  	return -1;                                                 //~@@@@R~
                                                                   //~2A14I~
    DragAcceptFiles(TRUE);      //accep drag & drop,drop file(WM_DROPFILES)//~2A14I~
	m_pDocument=new CWxeDoc();                                     //~@@@@I~
	Mwxemain.init(this);                                           //~2827R~
	((CWxeDoc*)GetDocument())->init(this);                         //~v51eR~
	
	return 0;
}

void CWxeView::OnFont() 
{
	CWxedlg *pwxedlg = new CWxedlg( (CWnd*)this,&Mwxemain);        //~2B03I~
//  pwxedlg->Create();                                             //~2B03R~//~@@@@R~
	pwxedlg->Create(NULL);   //CDialogImpl method, modeless dialog //~@@@@R~
    pwxedlg->ShowWindow(SW_SHOW);                                  //~2B03R~
	
}
void CWxeView::OnOk()                                              //~2817I~
{                                                                  //~2817I~
    Mwxemain.OnOk();                                               //~2827R~
	Invalidate(FALSE);                                             //~2817I~
}                                                                  //~2817I~

BOOL CWxeView::OnCommand(WPARAM wParam, LPARAM lParam) 
{
	
//  return CView::OnCommand(wParam, lParam);                       //~@@@@R~
    return FALSE;                                                  //~@@@@I~
}

void CWxeView::OnSize(UINT nType, int cx, int cy)                  //~2818I~
{                                                                  //~2818I~
    WINDOWPLACEMENT wp;                                            //~2A14M~
//**************************                                       //~2A14M~
    UTRACEP("View onsize:type=%d (%d,%d)\n",nType,cx,cy);          //~2A14I~
//  CView::OnSize(nType, cx, cy);                                  //~@@@@R~
    GetWindowPlacement(&wp);                                       //~2A14M~
    UTRACED("View onsize:wp",&wp,sizeof(wp));                      //~2A14I~
    Mwxemain.OnSize(nType,cx,cy);                                  //~2827R~
#ifdef AAA                                                         //~@@@@R~
    resizescrollbar(cx,cy);                                        //~v69gI~
#endif                                                             //~@@@@I~
}                                                                  //~2818I~
#ifdef AAA                                                         //~@@@@R~
//*****************************************************************//~v69gI~
//*create and resize horizontal/vertical scrollbar(visible but height and width is 0)//~v69gI~
//*if scrollbar exist tilt whell mouse generate WM_HSCROLL/WM_VSCROLL msg//~v69gI~
//*****************************************************************//~v69gI~
int CWxeView::resizescrollbar(int Pcx,int Pcy)                     //~v69gI~
{                                                                  //~v69gM~
	RECT rect;                                                     //~v69gM~
	int hight=0;                                                   //~v69gR~
	int width=0;                                                   //~v69gR~
//***********************************                              //~v69gM~
	rect.top=rect.left=0;                                          //~v69gI~
	rect.bottom=Pcy; rect.right=Pcx;                               //~v69gR~
//h-scrollbar                                                      //~v69gM~
	if (!Mphscrollbar)                                             //~v69gR~
    {                                                              //~v69gI~
	    Mphscrollbar=new CScrollBar();                             //~v69gI~
		Mphscrollbar->Create(SBS_BOTTOMALIGN|SBS_HORZ,rect,this,IDC_HSCROLLBAR);//~v69gI~
		Mphscrollbar->ShowScrollBar(SB_CTL|SB_HORZ);               //~v69gI~
	}                                                              //~v69gI~
	Mphscrollbar->MoveWindow(rect.left,rect.bottom-hight,rect.right,hight);    //x,y,w,h//~v69gM~
//v-scrollbar                                                      //~v69gM~
	if (!Mpvscrollbar)                                             //~v69gR~
    {                                                              //~v69gI~
	    Mpvscrollbar=new CScrollBar();                             //~v69gI~
		Mpvscrollbar->Create(SBS_RIGHTALIGN|SBS_VERT,rect,this,IDC_VSCROLLBAR);//~v69gI~
		Mpvscrollbar->ShowScrollBar(SB_CTL|SB_VERT);               //~v69gI~
    }                                                              //~v69gI~
	Mpvscrollbar->MoveWindow(rect.right-width,rect.top,width,rect.bottom);    //x,y,w,h//~v69gM~
    return 0;                                                      //~v69gM~
}//resizescrollbar                                                 //~v69gI~
#endif                                                             //~@@@@I~

void CWxeView::OnUpdateEditPaste(CCmdUI* pCmdUI) 
{
UTRACEP("@@@@OnUpdateEditPaste\n");                                //~@@@@R~
	pCmdUI->Enable(Mwxemain.cpupdatepaste());                      //~2827R~
	
}
                                                                   //~2A03M~
void CWxeView::OnUpdateEditPasteRep(CCmdUI* pCmdUI)                //~2A03M~
{                                                                  //~2A03M~
UTRACEP("@@@@OnUpdateEditPasteRep\n");                             //~@@@@R~
	pCmdUI->Enable(Mwxemain.cpupdatepaste());                      //~2A03I~
	                                                               //~2A03M~
}                                                                  //~2A03M~

void CWxeView::OnUpdateEditPasteStd(CCmdUI* pCmdUI)                //~v66hI~
{                                                                  //~v66hI~
//UTRACEP("@@@@OnUpdateEditPasteStd\n");                           //~v688R~
	pCmdUI->Enable(Mwxemain.cpupdatepastestd());                   //~v66hR~
                                                                   //~v66hI~
}                                                                  //~v66hI~
                                                                   //~v66hI~
void CWxeView::OnEditPaste() 
{
	Mwxemain.cppaste(1);                                           //~2A03R~
	
}
                                                                   //~2A03I~
void CWxeView::OnEditPasteRep()                                    //~2A03M~
{                                                                  //~2A03M~
	Mwxemain.cppaste(0);                                           //~2A03I~
	                                                               //~2A03M~
}                                                                  //~2A03M~
void CWxeView::OnEditPasteStd()                                    //~v66hI~
{                                                                  //~v66hI~
	Mwxemain.cppaste(2);        //2:std paste                      //~v66hI~
                                                                   //~v66hI~
}                                                                  //~v66hI~

void CWxeView::OnUpdateEditCopy(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(Mwxemain.cpupdatecopy());                       //~2827R~
	
}

void CWxeView::OnEditCopy() 
{
	Mwxemain.cpcopy(0);                                            //~2A03R~
    Invalidate(FALSE);                                             //~v66hI~
	
}

void CWxeView::OnUpdateEditCut(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(Mwxemain.cpupdatecut());                        //~2827R~
	
}
                                                                   //~2A06M~
void CWxeView::OnUpdateEditClear(CCmdUI* pCmdUI)                   //~2A06M~
{                                                                  //~2A06M~
	pCmdUI->Enable(Mwxemain.cpupdatecut());                        //~2A06I~
	                                                               //~2A06M~
}                                                                  //~2A06M~
void CWxeView::OnUpdateEditSelectAll(CCmdUI* pCmdUI)               //~vbd2R~
{                                                                  //~vbd2I~
	pCmdUI->Enable(Mwxemain.cpupdateselectall());                  //~vbd2I~
}                                                                  //~vbd2I~

void CWxeView::OnEditCut() 
{
	Mwxemain.cpcopy(1);                                            //~2A03R~
    Invalidate(FALSE);                                             //~v66hI~
}
                                                                   //~2A06M~
void CWxeView::OnEditClear()                                       //~2A06M~
{                                                                  //~2A06M~
	Mwxemain.cpcopy(2);                                            //~2A06I~
    Invalidate(FALSE);                                             //~v66hI~
}                                                                  //~2A06M~
void CWxeView::OnEditSelectAll()                                   //~vbd2R~
{                                                                  //~vbd2I~
	Mwxemain.cpselectall();                                        //~vbd2R~
    Invalidate(FALSE);                                             //~vbd2I~
}                                                                  //~vbd2I~

void CWxeView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	Mwxemain.mouselbdown(nFlags,point);                            //~2827R~
//  CView::OnLButtonDown(nFlags, point);                           //~@@@@R~
}

void CWxeView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	Mwxemain.mouselbup(nFlags,point);                              //~2827R~
	
//  CView::OnLButtonUp(nFlags, point);                             //~@@@@R~
}

void CWxeView::OnMouseMove(UINT nFlags, CPoint point) 
{
	Mwxemain.mousemove(nFlags,point);                              //~2827R~
	
//  CView::OnMouseMove(nFlags, point);                             //~@@@@R~
}

void CWxeView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	Mwxemain.mouserbdown(nFlags,point);                            //~2827R~
	
//  CView::OnRButtonDown(nFlags, point);                           //~@@@@R~
}


void CWxeView::OnSetFocus(CWnd* pOldWnd) 
{
//  CView::OnSetFocus(pOldWnd);                                    //~@@@@R~
	
	Mwxemain.onsetfocus(pOldWnd);                                  //~2922I~
	
}

void CWxeView::OnKillFocus(CWnd* pNewWnd) 
{
//  CView::OnKillFocus(pNewWnd);                                   //~@@@@R~
	
	Mwxemain.onkillfocus(pNewWnd);                                 //~2922I~
	
}


//======================================================================//~2A13I~
// ret 0:mousewheel is effective 1:inefective                      //~2A13I~
//======================================================================//~2A13I~
BOOL CWxeView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
    UTRACEP("view:onmousewheel flag=%x,delta=%x,(%x,%x)\n",nFlags,zDelta,pt.x,pt.y);//~2A13I~
	Mwxemain.onmousewheel(nFlags,zDelta,pt);                       //~2A13M~
	
//  return CView::OnMouseWheel(nFlags, zDelta, pt);                //~@@@@R~
    return FALSE;       //not efective                             //~2A13I~
}

void CWxeView::OnDropFiles(HDROP hDropInfo) 
{
	
//  CView::OnDropFiles(hDropInfo);                                 //~2A14R~
    GetDocument()->ondropfiles(hDropInfo);                         //~2A14R~
}
//BOOL CWxeView::OnFileDNDCopy(WPARAM wParam, LPARAM lParam)       //~v77wR~
LRESULT CWxeView::OnFileDNDCopy(WPARAM wParam, LPARAM lParam)      //~v77wI~
{                                                                  //~v685I~
	return  (GetDocument()->Mwxefile).filecopybydnd(wParam,lParam);//~v685R~
}                                                                  //~v685I~

void CWxeView::OnFileScrprt() 
{
    Mwxemain.Mhcopysw=1;                                           //~2B23R~
    Mpmainframewnd->PostMessage(WM_COMMAND,ID_FILE_PRINT,0);       //~2B02R~
    return;                                                        //~2B02I~
}

//void CWxeView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo)          //~@@@@R~
//{                                                                //~@@@@R~
//    if (pInfo)                      //print,not scr              //~@@@@R~
//        Mwxemain.prtpreparedc(pDC,pInfo);                        //~@@@@R~
//    CView::OnPrepareDC(pDC, pInfo);                              //~@@@@R~
//}                                                                //~@@@@R~

void CWxeView::OnPageSetup() 
{
	CWxepage *pwxepage = new CWxepage( (CWnd*)this,&Mwxemain);     //~2B03I~
//  pwxepage->Create(NULL);   //CDialogImpl method, modeless dialog//~vak7R~
//  pwxepage->ShowWindow(SW_SHOW);                                 //~vak7R~
	pwxepage->DoModal();   //Modal dialog                          //~vak7I~
}

void CWxeView::OnEditEnd() 
{
    Mwxemain.scrend();                                             //~3102I~
}

void CWxeView::OnEditCancel() 
{
    Mwxemain.scrcancel();                                          //~3102I~
}

void CWxeView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	if (Mwxemain.mouselbdblclk(nFlags,point))	//processed        //~3102I~
		return;                                                    //~3102R~
//  CView::OnLButtonDblClk(nFlags, point);                         //~@@@@R~
}

void CWxeView::OnTimer(UINT nIDEvent) 
{
	Mwxemain.ontimer(nIDEvent);                                    //~3208R~
}

void CWxeView::OnFileDos() 
{
    Mwxemain.scrcmd(WXEOF_DOSPROMPT,"CMD");                        //~v516R~
}

void CWxeView::OnEditExplorer() 
{
    Mwxemain.strcmd("SPAWN","explorer");                           //~v51wR~
}


void CWxeView::OnFileOpenwith()                                    //~v55uR~
{                                                                  //~v55uR~
    Mwxemain.onfileopenwith();                                     //~v55uI~
}                                                                  //~v55uR~

void CWxeView::OnUpdateFileOpenwith(CCmdUI* pCmdUI)                //~v55uR~
{                                                                  //~v55uR~
}                                                                  //~v55uR~


DROPEFFECT CWxeView::OnDragEnter(COleDataObject* pDataObject, DWORD dwKeyState, CPoint point) 
{
	
//  return CView::OnDragEnter(pDataObject, dwKeyState, point);     //~v59zR~
    return (GetDocument()->Mwxefile).ondragenter(pDataObject,dwKeyState,point);//~v59zR~
}

DROPEFFECT CWxeView::OnDragOver(COleDataObject* pDataObject, DWORD dwKeyState, CPoint point) 
{
	
//  return CView::OnDragOver(pDataObject, dwKeyState, point);      //~v59zR~
    return (GetDocument()->Mwxefile).ondragover(pDataObject,dwKeyState,point);//~v59zI~
}

void CWxeView::OnInitialUpdate() 
{
//  CView::OnInitialUpdate();                                      //~@@@@R~
	
//	m_droptarget.Register(this);	//get control of OnDragEnter,OnDragOver//~v685R~
}

void CWxeView::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
//	CView::OnHScroll(nSBCode, nPos, pScrollBar);                   //~v69gR~
	Mwxemain.mousescrollbar(WM_HSCROLL,nSBCode);                   //~v69gI~
}

void CWxeView::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
//	CView::OnVScroll(nSBCode, nPos, pScrollBar);                   //~v69gR~
	Mwxemain.mousescrollbar(WM_VSCROLL,nSBCode);                   //~v69gI~
}
void CWxeView::OnFileSave(UINT unotifyCode,int nID,HWND wndCtl)    //~@@@@R~
{                                                                  //~@@@@I~
    Mpmainframewnd->OnFileSave(unotifyCode,nID,wndCtl);            //~@@@@I~
}                                                                  //~@@@@I~
void CWxeView::OnFileCHLSetClosed()                                //~vbj2I~
{                                                                  //~vbj2I~
    Mwxemain.onfileCHL('s');                                       //+vbj2R~
}                                                                  //~vbj2I~
void CWxeView::OnFileCHLSetCurrent()                               //~vbj2I~
{                                                                  //~vbj2I~
    Mwxemain.onfileCHL('S');                                       //+vbj2R~
}                                                                  //~vbj2I~
void CWxeView::OnFileCHLSetSplit()                                 //~vbj2I~
{                                                                  //~vbj2I~
    Mwxemain.onfileCHL('t');                                       //+vbj2R~
}                                                                  //~vbj2I~
void CWxeView::OnFileCHLExeClosed()                                //~vbj2I~
{                                                                  //~vbj2I~
    Mwxemain.onfileCHL('x');                                       //+vbj2R~
}                                                                  //~vbj2I~
void CWxeView::OnFileCHLExeCurrent()                               //~vbj2I~
{                                                                  //~vbj2I~
    Mwxemain.onfileCHL('X');                                       //+vbj2R~
}                                                                  //~vbj2I~
void CWxeView::OnFileCHLExeSplit()                                 //~vbj2I~
{                                                                  //~vbj2I~
    Mwxemain.onfileCHL('y');                                       //+vbj2R~
}                                                                  //~vbj2I~
