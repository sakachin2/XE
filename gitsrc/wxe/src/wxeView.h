//*CID://+vbj2R~:                             update#=   91;       //~vbj2R~
//***************************************************************************//~v51VI~
//vbj2:180424 popup menu on cmd history list                       //~vbj2I~
//vbd2:171114 (Wxe)Add SelectAll menuitem                          //~vbd2I~
//v77w:080117 visual studio 2005 compiler warning(LRESULT:BOOL)    //~v77wI~
//v69g:060521 (WXE)tilt wheel mouse generate WM_VSCROLL/WM_HSCROLL by mycrosoft spec//~v69gI~
//            if scroll bar exist.(both vertical and horizontal is requred to genarate both)//~v69gI~
//v685:060322 dnd support "file copy into the dir slected" and even in inter-split-screen.//~v685I~
//v66h:051023 C & P;region mode by mouse; mouse drag->region mode,A+mouse drag->block mode//~v66hI~
//            delete Ctrl+V(preview) from menu and add to icon menu and popup menu//~v66hI~
//***************************************************************************//~v51VI~
// wxeView.h                                                       //~v66hR~
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_WXEVIEW_H__F339312B_AD0D_11D6_8C9B_00909951ADD0__INCLUDED_)
#define AFX_WXEVIEW_H__F339312B_AD0D_11D6_8C9B_00909951ADD0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "StdAfx.h"                                                //~@@@@I~
#include <wxeDoc.h>                                                //~@@@@R~
#include <MainFrm.h>                                               //~@@@@R~
#include <wxemain.h>                                               //~@@@@R~
#include <resource.h>                                              //~@@@@I~

//class CWxeView : public CView                                    //~@@@@R~
class CWxeView : public CWindowImpl<CWxeView>                      //~@@@@I~
{
private:                                                           //~@@@@I~
   	CWxeDoc *m_pDocument;                                          //~@@@@I~
//protected:                                                       //~@@@@R~
public:                                                            //~@@@@I~
	CWxeView();
                                                                   //~@@@@I~
BEGIN_MESSAGE_MAP(CWxeView, CView)                                 //~@@@@I~
	//{{AFX_MSG_MAP(CWxeView)                                      //~@@@@I~
	MSG_WM_PAINT(OnPaint)                                          //~@@@@I~
//    ON_WM_KEYDOWN()                                              //~@@@@I~
	MSG_WM_KEYDOWN(OnKeyDown)                                      //~@@@@R~
//    ON_WM_KEYUP()                                                //~@@@@I~
	MSG_WM_KEYUP(OnKeyUp)                                          //~@@@@R~
//    ON_WM_LBUTTONDOWN()                                          //~@@@@M~
	MSG_WM_LBUTTONDOWN(OnLButtonDown)                              //~@@@@M~
//    ON_WM_LBUTTONUP()                                            //~@@@@M~
	MSG_WM_LBUTTONUP(OnLButtonUp)                                  //~@@@@M~
//    ON_WM_MOUSEMOVE()                                            //~@@@@M~
	MSG_WM_MOUSEMOVE(OnMouseMove)                                  //~@@@@M~
//    ON_WM_RBUTTONDOWN()                                          //~@@@@M~
	MSG_WM_RBUTTONDOWN(OnRButtonDown)                              //~@@@@M~
//    ON_WM_CHAR()                                                 //~@@@@M~
	MSG_WM_CHAR(OnChar)                                            //~@@@@M~
//    ON_WM_SETFOCUS()                                             //~@@@@M~
	MSG_WM_CHAR(OnChar)                                            //~@@@@I~
//    ON_WM_SETFOCUS()                                             //~@@@@I~
	MSG_WM_SETFOCUS(OnSetFocusW)                                   //~@@@@M~
//    ON_WM_KILLFOCUS()                                            //~@@@@M~
	MSG_WM_KILLFOCUS(OnKillFocusW)                                 //~@@@@M~
//    ON_WM_CREATE()                                               //~@@@@I~
	MSG_WM_CREATE(OnCreate)                                        //~@@@@R~
//  ON_COMMAND(IDC_FONT,OnFont)                                    //~@@@@R~
//    ON_WM_SIZE()                                                 //~@@@@I~
	MSG_WM_SIZE(OnSizeW)                                           //~@@@@R~
//  ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, OnUpdateEditPaste)         //~@@@@R~
//  ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)                         //~@@@@R~
    ON_COMMAND(ID_EDIT_PASTE, OnEditPasteW)                        //~@@@@I~
//  ON_UPDATE_COMMAND_UI(ID_EDIT_COPY, OnUpdateEditCopy)           //~@@@@R~
//	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)                           //~@@@@R~
  	ON_COMMAND(ID_EDIT_COPY, OnEditCopyW)                          //~@@@@I~
//  ON_UPDATE_COMMAND_UI(ID_EDIT_CUT, OnUpdateEditCut)             //~@@@@R~
//	ON_COMMAND(ID_EDIT_CUT, OnEditCut)                             //~@@@@R~
  	ON_COMMAND(ID_EDIT_CUT, OnEditCutW)                            //~@@@@I~
//	ON_COMMAND(ID_EDIT_PASTE_REP, OnEditPasteRep)                  //~@@@@R~
  	ON_COMMAND(ID_EDIT_PASTE_REP, OnEditPasteRepW)                 //~@@@@I~
//  ON_COMMAND(ID_EDIT_PASTE_STD, OnEditPasteStd)                  //~@@@@R~
    ON_COMMAND(ID_EDIT_PASTE_STD, OnEditPasteStdW)                 //~@@@@I~
//  ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE_REP, OnUpdateEditPasteRep)  //~@@@@R~
//  ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE_STD, OnUpdateEditPasteStd)  //~@@@@R~
	ON_COMMAND(ID_EDIT_CLEAR, OnEditClearW)                        //~@@@@R~
	ON_COMMAND(ID_EDIT_SELECTALL, OnEditSelectAllW)                //~vbd2R~
//  ON_UPDATE_COMMAND_UI(ID_EDIT_CLEAR, OnUpdateEditClear)         //~@@@@R~
//    ON_WM_MOUSEWHEEL()                                           //~@@@@I~
	MSG_WM_MOUSEWHEEL(OnMouseWheel)                                //~@@@@R~
//    ON_WM_DROPFILES()                                            //~@@@@I~
	MSG_WM_DROPFILES(OnDropFiles)                                  //~@@@@R~
//  ON_COMMAND(ID_FILE_SCRPRT, OnFileScrprt)                       //~@@@@R~
    ON_COMMAND(ID_FILE_SCRPRT, OnFileScrprtW)                      //~@@@@I~
//	ON_COMMAND(ID_PAGE_SETUP, OnPageSetup)                         //~@@@@R~
    ON_COMMAND(ID_FILE_SAVE, OnFileSave)                           //~@@@@R~
//	ON_COMMAND(ID_EDIT_END, OnEditEnd)                             //~@@@@R~
	ON_COMMAND(ID_EDIT_END, OnEditEndW)                            //~@@@@I~
//	ON_COMMAND(ID_EDIT_CANCEL, OnEditCancel)                       //~@@@@R~
  	ON_COMMAND(ID_EDIT_CANCEL, OnEditCancelW)                      //~@@@@I~
//    ON_WM_LBUTTONDBLCLK()                                        //~@@@@I~
	MSG_WM_LBUTTONDBLCLK(OnLButtonDblClk)                          //~@@@@R~
//    ON_WM_TIMER()                                                //~@@@@I~
	MSG_WM_TIMER(OnTimer)                                          //~@@@@R~
//  ON_COMMAND(ID_FILE_DOS, OnFileDos)                             //~@@@@R~
    ON_COMMAND(ID_FILE_DOS, OnFileDosW)                            //~@@@@I~
//	ON_COMMAND(ID_FILE_EXPLORER, OnEditExplorer)                   //~@@@@R~
  	ON_COMMAND(ID_FILE_EXPLORER, OnEditExplorerW)                  //~@@@@I~
	ON_COMMAND(ID_FILE_OPENWITH, OnFileOpenwithW)                  //~@@@@R~
//  ON_UPDATE_COMMAND_UI(ID_FILE_OPENWITH, OnUpdateFileOpenwith)   //~@@@@R~
//    ON_WM_HSCROLL()                                              //~@@@@I~
	MSG_WM_HSCROLL(OnHScrollW)                                     //~@@@@R~
//    ON_WM_VSCROLL()                                              //~@@@@I~
	MSG_WM_HSCROLL(OnVScrollW)                                     //~@@@@R~
	//}}AFX_MSG_MAP                                                //~@@@@I~
	// 標準印刷コマンド                                            //~@@@@I~
//    ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)                //~@@@@R~
//    ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)         //~@@@@R~
//    ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview) //~@@@@R~
	ON_COMMAND(IDOK, CWxeView::OnOkW)                              //~@@@@R~
//    ON_MESSAGE(ID_FILE_DNDCOPY,CWxeView::OnFileDNDCopy)          //~@@@@R~
	MESSAGE_HANDLER_EX(ID_FILE_DNDCOPY, CWxeView::OnFileDNDCopyW)  //~@@@@R~
	MESSAGE_RANGE_HANDLER_EX(0,0xffff,CWxeView::DefWindowProcW)    //~@@@@R~
	ON_COMMAND(ID_CHL_SET_CLOSED, OnFileCHLSetClosedW)             //+vbj2R~
	ON_COMMAND(ID_CHL_SET_CURRENT, OnFileCHLSetCurrentW)           //+vbj2R~
	ON_COMMAND(ID_CHL_SET_SPLIT, OnFileCHLSetSplitW)               //+vbj2R~
	ON_COMMAND(ID_CHL_EXE_CLOSED, OnFileCHLExeClosedW)             //+vbj2R~
	ON_COMMAND(ID_CHL_EXE_CURRENT, OnFileCHLExeCurrentW)           //+vbj2R~
	ON_COMMAND(ID_CHL_EXE_SPLIT, OnFileCHLExeSplitW)               //+vbj2R~
END_MESSAGE_MAP()                                                  //~@@@@I~

public:
	virtual BOOL PreTranslateMessage(MSG* pMsg)                    //~@@@@I~
	{                                                              //~@@@@I~
		return FALSE;                                              //~@@@@I~
	}                                                              //~@@@@I~
	virtual BOOL OnIdle()                                          //~@@@@I~
	{                                                              //~@@@@I~
		return FALSE;                                              //~@@@@I~
	}                                                              //~@@@@I~
	CWxeDoc* GetDocument();                                        //~2A08R~
  	void OnOk(void);                                               //~@@@@R~
	void OnOkW(UINT unotifyCode,int nID,HWND wndCtl)               //~@@@@R~
    {                                                              //~@@@@I~
    	OnOk();                                                    //~@@@@I~
    }                                                              //~@@@@I~
//    CWnd *Mpmainframewnd;                                        //~@@@@R~
    CMainFrame *Mpmainframewnd;                                    //~@@@@I~
//private:                                                         //~v685R~
	CWxemain Mwxemain;                                             //~2827R~

public:

	//{{AFX_VIRTUAL(CWxeView)
	public:

	virtual void OnPaint(HDC Phdc);                                //~@@@@R~
	virtual void OnDraw(CDC* pDC);                                 //~v66hR~
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
//  virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);//~@@@@R~
	virtual HWND Create(CMainFrame *pParentWnd,RECT pRect,LPCTSTR pWindowname, DWORD dwStyle,DWORD dwExStyle);//~@@@@R~
//  virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);  //~@@@@R~
	virtual DROPEFFECT OnDragEnter(COleDataObject* pDataObject, DWORD dwKeyState, CPoint point);
	virtual DROPEFFECT OnDragOver(COleDataObject* pDataObject, DWORD dwKeyState, CPoint point);
	virtual void OnInitialUpdate();
//  protected:                                                     //~@@@@R~
//  virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);             //~@@@@R~
    virtual BOOL OnPreparePrinting();                              //~@@@@I~
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual LRESULT DefWindowProcW(UINT message, WPARAM wParam, LPARAM lParam);//~@@@@R~
	virtual LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam);//~@@@@I~
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
//  virtual BOOL OnFileDNDCopy(WPARAM wParam, LPARAM lParam);      //~v77wR~
    virtual LRESULT OnFileDNDCopy(WPARAM wParam, LPARAM lParam);   //~@@@@R~
            LRESULT OnFileDNDCopyW(UINT message,WPARAM wParam, LPARAM lParam)//~@@@@R~
			{                                                      //~@@@@I~
    			return OnFileDNDCopy(wParam,lParam);               //~@@@@I~
            }                                                      //~@@@@I~

	//}}AFX_VIRTUAL

public:
//    virtual ~CWxeView(){};                                       //~@@@@R~
    virtual ~CWxeView();                                           //~@@@@I~
//#ifdef _DEBUG                                                    //~@@@@R~
//      virtual void AssertValid() const;                          //~@@@@R~
//      virtual void Dump(CDumpContext& dc) const;                 //~@@@@R~
//#endif                                                           //~@@@@R~


//protected:                                                       //~@@@@R~
public:                                                            //~@@@@I~
//*WM_COMMAND wParam : high=notifyCode, low=Id                     //~@@@@R~
	//{{AFX_MSG(CWxeView)
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
  	afx_msg void OnFont();                                         //~@@@@R~
    afx_msg void OnSize(UINT nType, int cx, int cy);               //~@@@@R~
            void OnSizeW(UINT nType,CSize Psz)                     //~@@@@R~
			{	OnSize(nType,Psz.cx,Psz.cy);	}                  //~@@@@I~
    afx_msg void OnUpdateEditPaste(CCmdUI* pCmdUI);                //~@@@@R~
    afx_msg void OnEditPaste();                                    //~@@@@R~
	 	    void OnEditPasteW(UINT unotifyCode,int nID,HWND wndCtl)//~@@@@R~
			{                                                      //~@@@@R~
			 	OnEditPaste();                                     //~@@@@I~
			 	OnUpdateEditPaste(new CCmdUI(Mpmainframewnd,nID)); //~@@@@R~
            }                                                      //~@@@@I~
  	afx_msg void OnUpdateEditCopy(CCmdUI* pCmdUI);                 //~@@@@R~
    afx_msg void OnEditCopy();                                     //~@@@@R~
            void OnEditCopyW(UINT unotifyCode,int nID,HWND wndCtl) //~@@@@R~
			{                                                      //~@@@@R~
			 	OnEditCopy();                                      //~@@@@R~
			 	OnUpdateEditCopy(new CCmdUI(Mpmainframewnd,nID));  //~@@@@R~
			}                                                      //~@@@@I~
  	afx_msg void OnUpdateEditCut(CCmdUI* pCmdUI);                  //~@@@@R~
    afx_msg void OnEditCut();                                      //~@@@@R~
	        void OnEditCutW(UINT unotifyCode,int nID,HWND wndCtl)  //~@@@@R~
			{                                                      //~@@@@R~
				OnEditCut();                                       //~@@@@I~
				OnUpdateEditCut(new CCmdUI(Mpmainframewnd,nID));   //~@@@@R~
			}                                                      //~@@@@I~
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
  	afx_msg void OnSetFocus(CWnd* pOldWnd);                        //~@@@@R~
	        void OnSetFocusW(HWND Phwnd)                           //~@@@@I~
			{                                                      //~@@@@I~
				OnSetFocus(new CWindow(Phwnd));                    //~@@@@I~
			}                                                      //~@@@@I~
  	afx_msg void OnKillFocus(CWnd* pNewWnd);                       //~@@@@R~
	        void OnKillFocusW(HWND Phwnd)                          //~@@@@I~
			{                                                      //~@@@@I~
				OnKillFocus(new CWindow(Phwnd));                   //~@@@@I~
			}                                                      //~@@@@I~
  	afx_msg void OnEditPasteRep();                                 //~@@@@R~
            void OnEditPasteRepW(UINT unotifyCode,int nID,HWND wndCtl)//~@@@@R~
			{                                                      //~@@@@I~
				OnEditPasteRep();                                  //~@@@@I~
				OnUpdateEditPasteRep(new CCmdUI(Mpmainframewnd,nID));//~@@@@R~
			}                                                      //~@@@@I~
    afx_msg void OnEditPasteStd();                                 //~@@@@R~
            void OnEditPasteStdW(UINT unotifyCode,int nID,HWND wndCtl)//~@@@@R~
			{                                                      //~@@@@I~
				OnEditPasteStd();                                  //~@@@@I~
				OnUpdateEditPasteStd(new CCmdUI(Mpmainframewnd,nID));//~@@@@R~
			}                                                      //~@@@@I~
  	afx_msg void OnUpdateEditPasteRep(CCmdUI* pCmdUI);             //~@@@@R~
  	afx_msg void OnUpdateEditPasteStd(CCmdUI* pCmdUI);             //~@@@@R~
    afx_msg void OnEditClear();                                    //~@@@@R~
            void OnEditClearW(UINT unotifyCode,int nID,HWND wndCtl)//~@@@@R~
			{                                                      //~@@@@I~
				OnEditClear();                                     //~@@@@I~
				OnUpdateEditClear(new CCmdUI(Mpmainframewnd,nID)); //~@@@@R~
			}                                                      //~@@@@I~
  	afx_msg void OnUpdateEditClear(CCmdUI* pCmdUI);                //~@@@@R~
    afx_msg void OnEditSelectAll();                                //~vbd2R~
  	afx_msg void OnUpdateEditSelectAll(CCmdUI* pCmdUI);            //~vbd2R~
            void OnEditSelectAllW(UINT unotifyCode,int nID,HWND wndCtl)//~vbd2M~
			{                                                      //~vbd2M~
				OnEditSelectAll();                                 //~vbd2R~
				OnUpdateEditSelectAll(new CCmdUI(Mpmainframewnd,nID));//~vbd2R~
			}                                                      //~vbd2M~
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnDropFiles(HDROP hDropInfo);
            void OnFilePrint()  //from MainFrame                   //~@@@@I~
			{                                                      //~@@@@I~
            	OnPreparePrinting();	                           //~@@@@I~
            }                                                      //~@@@@I~
    afx_msg void OnFileScrprt();                                   //~@@@@R~
            void OnFileScrprtW(UINT unotifyCode,int nID,HWND wndCtl)//~@@@@R~
			{	OnFileScrprt();	}                                  //~@@@@I~
    afx_msg void OnPageSetup();                                    //~@@@@R~
            void OnFileSave(UINT unotifyCode,int nID,HWND wndCtl); //~@@@@R~
    afx_msg void OnEditEnd();                                      //~@@@@R~
            void OnEditEndW(UINT unotifyCode,int nID,HWND wndCtl)  //~@@@@R~
			{	OnEditEnd();	}                                  //~@@@@I~
    afx_msg void OnEditCancel();                                   //~@@@@R~
            void OnEditCancelW(UINT unotifyCode,int nID,HWND wndCtl)//~@@@@R~
			{	OnEditCancel();	}                                  //~@@@@I~
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
  	afx_msg void OnFileDos();                                      //~@@@@R~
  	        void OnFileDosW(UINT unotifyCode,int nID,HWND wndCtl)  //~@@@@R~
			{	OnFileDos();	}                                  //~@@@@I~
    afx_msg void OnEditExplorer();                                 //~@@@@R~
            void OnEditExplorerW(UINT unotifyCode,int nID,HWND wndCtl)//~@@@@R~
			{	OnEditExplorer();}                                 //~@@@@I~
    afx_msg void OnFileOpenwith();                                 //~@@@@R~
            void OnFileOpenwithW(UINT unotifyCode,int nID,HWND wndCtl)//~@@@@R~
			{                                                      //~@@@@I~
				OnFileOpenwith();                                  //~@@@@I~
				OnUpdateFileOpenwith(new CCmdUI(Mpmainframewnd,nID));//~@@@@R~
			}                                                      //~@@@@I~
  	afx_msg void OnUpdateFileOpenwith(CCmdUI* pCmdUI);             //~@@@@R~
    afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);//~@@@@R~
            void OnHScrollW(UINT nSBCode, UINT nPos, HWND Phwnd)   //~@@@@I~
			{                                                      //~@@@@I~
				OnHScroll(nSBCode,nPos,(CScrollBar *)(new CWindow(Phwnd)));//~@@@@I~
			}                                                      //~@@@@I~
    afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);//~@@@@R~
            void OnVScrollW(UINT nSBCode, UINT nPos, HWND Phwnd)   //~@@@@I~
			{                                                      //~@@@@I~
				OnVScroll(nSBCode,nPos,(CScrollBar *)(new CWindow(Phwnd)));//~@@@@I~
			}                                                      //~@@@@I~
    afx_msg void OnFileCHLSetClosed();                             //~vbj2I~
            void OnFileCHLSetClosedW(UINT unotifyCode,int nID,HWND wndCtl)//+vbj2I~
			{                                                      //+vbj2I~
				OnFileCHLSetClosed();                              //+vbj2I~
			}                                                      //+vbj2I~
    afx_msg void OnFileCHLSetCurrent();                            //~vbj2I~
            void OnFileCHLSetCurrentW(UINT unotifyCode,int nID,HWND wndCtl)//+vbj2I~
			{                                                      //+vbj2I~
				OnFileCHLSetCurrent();                             //+vbj2I~
			}                                                      //+vbj2I~
    afx_msg void OnFileCHLSetSplit();                              //~vbj2I~
            void OnFileCHLSetSplitW(UINT unotifyCode,int nID,HWND wndCtl)//+vbj2I~
			{                                                      //+vbj2I~
				OnFileCHLSetSplit();                               //+vbj2I~
			}                                                      //+vbj2I~
    afx_msg void OnFileCHLExeClosed();                             //~vbj2I~
            void OnFileCHLExeClosedW(UINT unotifyCode,int nID,HWND wndCtl)//+vbj2I~
			{                                                      //+vbj2I~
				OnFileCHLExeClosed();                              //+vbj2I~
			}                                                      //+vbj2I~
    afx_msg void OnFileCHLExeCurrent();                            //~vbj2I~
            void OnFileCHLExeCurrentW(UINT unotifyCode,int nID,HWND wndCtl)//+vbj2I~
			{                                                      //+vbj2I~
				OnFileCHLExeCurrent();                             //+vbj2I~
			}                                                      //+vbj2I~
    afx_msg void OnFileCHLExeSplit();                              //~vbj2I~
            void OnFileCHLExeSplitW(UINT unotifyCode,int nID,HWND wndCtl)//+vbj2I~
			{                                                      //+vbj2I~
				OnFileCHLExeSplit();                               //+vbj2I~
			}                                                      //+vbj2I~
	//}}AFX_MSG
      DECLARE_MESSAGE_MAP()                                        //~@@@@R~
private:
    CScrollBar *Mpvscrollbar,*Mphscrollbar;                        //~v69gI~
	int resizescrollbar(int Pcx,int Pcy);                          //~v69gR~
};

#ifndef _DEBUG  //                                                 //~@@@@R~
inline CWxeDoc* CWxeView::GetDocument()
   { return (CWxeDoc*)m_pDocument; }
#endif                                                             //~@@@@R~

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_WXEVIEW_H__F339312B_AD0D_11D6_8C9B_00909951ADD0__INCLUDED_)
