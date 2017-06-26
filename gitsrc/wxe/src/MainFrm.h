//*CID://+vb4vR~:                                   update#=   96; //~vb4vR~
//*****************************************************************************//~vb20I~
//vb4v:160813 (WXE bug)ATl/WTL is missing OnPrecreateWindow        //~vb4vI~
//vb20:160108 (Wxe:BUG)setup/preview dialog change waas not written to wxeini(put init even when cancel exit)//~vb20I~
//*****************************************************************************//~vb20I~
// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#pragma once                                                       //~@@@@R~
#include <stdafx.h>                                                //~@@@@R~
#include <wxedef.h>                                                //~@@@@R~
#include <wxeview.h>                                               //~@@@@I~
#include <AboutDlg.h>                                              //~@@@@I~
class CMainFrame :                                                 //~@@@@R~
//  public CRibbonFrameWindowImpl<CMainFrame>,                     //~@@@@R~
	public CUpdateUI<CMainFrame>,                                  //~@@@@I~
	public CFrameWindowImpl<CMainFrame>,                           //~@@@@I~
    public CMessageFilter, public CIdleHandler                     //~@@@@R~
    ,public CPrintJobInfo                                          //~@@@@R~
{
public:
	DECLARE_FRAME_WND_CLASS(NULL, IDR_MAINFRAME)

    CWxeView m_view;                 //~@@@@R~
//  CCommandBarCtrl m_CmdBar;                                      //~@@@@R~
//public:                                                          //~@@@@R~
//    static WTL::CFrameWndClassInfo& GetWndClassInfo()            //~@@@@R~
//    {                                                            //~@@@@R~
//        static WTL::CFrameWndClassInfo wc =                      //~@@@@R~
//        {                                                        //~@@@@R~
//            {                                                    //~@@@@R~
//                sizeof(WNDCLASSEX), CS_HREDRAW | CS_VREDRAW,     //~@@@@R~
//                StartWindowProc, 0, 0, NULL, NULL, NULL,         //~@@@@R~
//                (HBRUSH)(COLOR_WINDOW + 1),                      //~@@@@R~
//                MAKEINTRESOURCE(IDR_MAINFRAME),                  //~@@@@R~
//                "wxe", NULL  //                                  //~@@@@R~
//            },                //WNDCLASSEX                       //~@@@@R~
//            NULL,             // window class                    //~@@@@R~
//            NULL,             // window procedure                //~@@@@R~
//            NULL,             //cursor resource                  //~@@@@R~
//            TRUE,           // system cursor:TRUE, else FALSE    //~@@@@R~
//            0,                // window class ID                 //~@@@@R~
//            _T("")            // window class name               //~@@@@R~
//            IDR_MAINFRAME     // common resource ID              //~@@@@R~
//        };                                                       //~@@@@R~
//        return wc;                                               //~@@@@R~
//    }                                                            //~@@@@R~


	// Ribbon control map
//  BEGIN_RIBBON_CONTROL_MAP(CMainFrame)                           //~@@@@R~
//  END_RIBBON_CONTROL_MAP()                                       //~@@@@R~

	virtual BOOL PreTranslateMessage(MSG* pMsg)
	{
//  	if(CRibbonFrameWindowImpl<CMainFrame>::PreTranslateMessage(pMsg))//~@@@@R~
		if (Museact && Mpact)                                      //~@@@@R~
        	if (Mcacc.TranslateAccelerator(m_hWnd,pMsg))           //~@@@@R~
            	return true;                                       //~@@@@I~
		if(CFrameWindowImpl<CMainFrame>::PreTranslateMessage(pMsg))//~@@@@I~
			return TRUE;

		return m_view.PreTranslateMessage(pMsg);
	}

	virtual BOOL OnIdle()
	{
//  	UIUpdateToolBar();                                         //~@@@@R~
		return FALSE;
	}

	BEGIN_UPDATE_UI_MAP(CMainFrame)
//  	UPDATE_ELEMENT(ID_VIEW_TOOLBAR, UPDUI_MENUPOPUP)           //~@@@@R~
		UPDATE_ELEMENT(ID_VIEW_STATUS_BAR, UPDUI_MENUPOPUP)
	END_UPDATE_UI_MAP()

	BEGIN_MSG_MAP_EX(CMainFrame)
//		MESSAGE_HANDLER(WM_CREATE, OnCreate)                       //~@@@@R~
  		MSG_WM_CREATE(OnCreateW)                                   //~@@@@R~
		MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
		COMMAND_ID_HANDLER(ID_APP_EXIT, OnFileExit)
		COMMAND_ID_HANDLER(ID_FILE_NEW, OnFileNew)
//  	COMMAND_ID_HANDLER(ID_VIEW_TOOLBAR, OnViewToolBar)         //~@@@@R~
		COMMAND_ID_HANDLER(ID_VIEW_STATUS_BAR, OnViewStatusBar)
//  	COMMAND_ID_HANDLER(ID_VIEW_RIBBON, OnViewRibbon)           //~@@@@R~
		COMMAND_ID_HANDLER(ID_APP_ABOUT, OnAppAbout)
//      ON_WM_CLOSE()                                              //~@@@@I~
		MSG_WM_CLOSE(OnClose)                                      //~@@@@I~
//      ON_WM_INITMENU()                                           //~@@@@I~
		MSG_WM_INITMENU(OnInitMenuW)                               //~@@@@R~
        ON_COMMAND(ID_HELPXE,OnHelpW)                              //~@@@@I~
//  	CHAIN_MSG_MAP(CRibbonFrameWindowImpl<CMainFrame>)          //~@@@@R~
//  	CHAIN_MSG_MAP(CUpdateUI<CMainFrame>)                       //~@@@@R~
		CHAIN_MSG_MAP(CFrameWindowImpl<CMainFrame>)                //~@@@@I~
//menu operation is frame window msg *******                       //~@@@@I~
        ON_COMMAND(ID_EDIT_CUT, OnEditCut)                         //~@@@@I~
        ON_COMMAND(ID_EDIT_COPY, OnEditCopy)                       //~@@@@I~
        ON_COMMAND(ID_EDIT_CLEAR, OnEditClear)                     //~@@@@I~
        ON_COMMAND(ID_EDIT_PASTE_STD, OnEditPasteStd)              //~@@@@I~
        ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)                     //~@@@@I~
        ON_COMMAND(ID_EDIT_PASTE_REP, OnEditPasteRep)              //~@@@@I~
        ON_COMMAND(ID_EDIT_END, OnEditEnd)		//from toolbar     //~@@@@R~
        ON_COMMAND(ID_EDIT_CANCEL, OnEditCancel)                   //~@@@@R~
                                                                   //~@@@@I~
        ON_COMMAND(ID_FILE_PRINT, OnFilePrint)                     //~@@@@I~
        ON_COMMAND(ID_FILE_SCRPRT, OnFileScrprt)                   //~@@@@I~
        ON_COMMAND(ID_FILE_EXPLORER, OnEditExplorer)               //~@@@@I~
        ON_COMMAND(ID_FILE_DOS, OnFileDos)                         //~@@@@I~
                                                                   //~@@@@I~
		ON_COMMAND(IDC_FONT,OnFont)                                //~@@@@I~
		ON_COMMAND(ID_PAGE_SETUP,OnPageSetup)                      //~@@@@R~
//because no Doc&View structure ***                                //~@@@@R~
        ON_COMMAND(ID_FILE_OPEN, OnFileOpen)                       //~@@@@I~
        ON_COMMAND(ID_FILE_SAVE, OnFileSave)                       //~@@@@I~
        ON_COMMAND(ID_FILE_SAVE_AS, OnFileSaveAs)                  //~@@@@I~
	END_MSG_MAP()

// Handler prototypes (uncomment arguments if needed):
//	LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
//	LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//	LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)

//  LRESULT OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)//~@@@@R~
	int OnCreateW(LPCREATESTRUCT lpCreateStruct)                   //~@@@@R~
	{
//  	bool bRibbonUI = RunTimeHelper::IsRibbonUIAvailable();     //~@@@@R~
//  	if (bRibbonUI)                                             //~@@@@R~
//  		UIAddMenu(GetMenu(), true);                            //~@@@@R~
//  	else                                                       //~@@@@R~
//  		CMenuHandle(GetMenu()).DeleteMenu(ID_VIEW_RIBBON, MF_BYCOMMAND);//~@@@@R~

//        // create command bar window                             //~@@@@R~
//        HWND hWndCmdBar = m_CmdBar.Create(m_hWnd, rcDefault, NULL, ATL_SIMPLE_CMDBAR_PANE_STYLE);//~@@@@R~
//        // attach menu                                           //~@@@@R~
//        m_CmdBar.AttachMenu(GetMenu());                          //~@@@@R~
//        // load command bar images                               //~@@@@R~
//        m_CmdBar.LoadImages(IDR_MAINFRAME);                      //~@@@@R~
//        // remove old menu                                       //~@@@@R~
//        SetMenu(NULL);                                           //~@@@@R~

//        HWND hWndToolBar = CreateSimpleToolBarCtrl(m_hWnd, IDR_MAINFRAME, FALSE, ATL_SIMPLE_TOOLBAR_PANE_STYLE);//~@@@@R~

//        CreateSimpleReBar(ATL_SIMPLE_REBAR_NOBORDER_STYLE);      //~@@@@R~
//        AddSimpleReBarBand(hWndCmdBar);                          //~@@@@R~
//        AddSimpleReBarBand(hWndToolBar, NULL, TRUE);             //~@@@@R~

		CreateSimpleStatusBar();

//        m_hWndClient = m_view.Create(m_hWnd, rcDefault, NULL, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN, WS_EX_CLIENTEDGE);//~@@@@R~
        m_view.Create(this,rcDefault, NULL, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN, WS_EX_CLIENTEDGE);//~@@@@R~
        m_hWndClient=HWND(m_view);  //required to enable child view's message map                               //~@@@@I~

//  	UIAddToolBar(hWndToolBar);                                 //~@@@@R~
//  	UISetCheck(ID_VIEW_TOOLBAR, 1);                            //~@@@@R~
		UISetCheck(ID_VIEW_STATUS_BAR, 1);

		// register object for message filtering and idle updates
		CMessageLoop* pLoop = _Module.GetMessageLoop();
		ATLASSERT(pLoop != NULL);
		pLoop->AddMessageFilter(this);
		pLoop->AddIdleHandler(this);

//  	ShowRibbonUI(bRibbonUI);                                   //~@@@@R~
//  	UISetCheck(ID_VIEW_RIBBON, bRibbonUI);                     //~@@@@R~
    	OnPreCreateWindowW(lpCreateStruct);                        //+vb4vI~
		OnCreate(lpCreateStruct);	//MainFrm.cpp                   //~@@@@I~

		return 0;
	}

	LRESULT OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled)
	{
		// unregister message filtering and idle updates
		CMessageLoop* pLoop = _Module.GetMessageLoop();
		ATLASSERT(pLoop != NULL);
		pLoop->RemoveMessageFilter(this); 
		pLoop->RemoveIdleHandler(this);

		bHandled = FALSE;
        PostQuitMessage(0/*exitcode*/);                            //~@@@@R~
		return 0;                                                  //~@@@@R~
	}

	LRESULT OnFileExit(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
	{
		Mswappexit=1;                                              //~@@@@I~
		PostMessage(WM_CLOSE);
		return 0;
	}

//    LRESULT OnFileNew(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)//~@@@@R~
//    {                                                            //~@@@@R~
//        // TODO: add code to initialize document                 //~@@@@R~
//        return 0;                                                //~@@@@R~
//    }                                                            //~@@@@R~
    LRESULT OnFileNew(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);//~@@@@I~
//    LRESULT OnViewToolBar(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)//~@@@@R~
//    {                                                            //~@@@@R~
//        static BOOL bVisible = TRUE;    // initially visible     //~@@@@R~
//        bVisible = !bVisible;                                    //~@@@@R~
//        CReBarCtrl rebar = m_hWndToolBar;                        //~@@@@R~
//        int nBandIndex = rebar.IdToIndex(ATL_IDW_BAND_FIRST + 1);   // toolbar is 2nd added band//~@@@@R~
//        rebar.ShowBand(nBandIndex, bVisible);                    //~@@@@R~
//        UISetCheck(ID_VIEW_TOOLBAR, bVisible);                   //~@@@@R~
//        UpdateLayout();                                          //~@@@@R~
//        return 0;                                                //~@@@@R~
//    }                                                            //~@@@@R~

	LRESULT OnViewStatusBar(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
	{
		BOOL bVisible = !::IsWindowVisible(m_hWndStatusBar);
		::ShowWindow(m_hWndStatusBar, bVisible ? SW_SHOWNOACTIVATE : SW_HIDE);
		UISetCheck(ID_VIEW_STATUS_BAR, bVisible);
		UpdateLayout();
		return 0;
	}
//  LRESULT OnViewRibbon(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)//~@@@@R~
//  {                                                              //~@@@@R~
//  	ShowRibbonUI(!IsRibbonUI());                               //~@@@@R~
//  	UISetCheck(ID_VIEW_RIBBON, IsRibbonUI());                  //~@@@@R~
//  	return 0;                                                  //~@@@@R~
//  }                                                              //~@@@@R~
	LRESULT OnAppAbout(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
	{
		CAboutDlg dlg;
		dlg.DoModal();
		return 0;
	}
///////////////////////////////////////////////////////////////////////////////~@@@@I~
//protected:                                                       //~@@@@R~
public:                                                            //~@@@@I~
	CMainFrame();                                                  //~@@@@I~
	DECLARE_DYNCREATE(CMainFrame)                                  //~@@@@I~
                                                                   //~@@@@I~
public:                                                            //~@@@@I~
    int       Museact;                                             //~@@@@I~
    int       Musemk ;                                             //~@@@@I~
	WXEINIDATA Mwxeinidata;                                        //~@@@@I~
	int  CMainFrame::updatemenu(int Pfloatsw,CMenu *Ppmenu);       //~@@@@I~
public:                                                            //~@@@@I~
                                                                   //~@@@@I~
	//{{AFX_VIRTUAL(CMainFrame)                                    //~@@@@I~
	public:                                                        //~@@@@I~
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);                //~@@@@I~
	protected:                                                     //~@@@@I~
	virtual LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam);//~@@@@I~
	//}}AFX_VIRTUAL                                                //~@@@@I~
                                                                   //~@@@@I~
private:                                                           //~@@@@I~
    CWxeApp  *Mpapp;                                               //~@@@@I~
    CWxemain *Mpxemain;                                            //~@@@@I~
    ACCEL    *Mpact;                                               //~@@@@I~
    CAccelerator Mcacc;                                            //~@@@@I~
    int       Mactno;                                              //~@@@@I~
	int       updatemenutext(char *Ptext,ACCEL *Ppact);            //~@@@@I~
	int       updatemainmenu(CMenu *Ppmenu);                       //~@@@@I~
	int  	  updatemainmenutext(int Pmenupos,char *Ptext,int Pusesw);//~@@@@I~
//  int       Monsizetype;                                         //~@@@@I~
public:                                                            //~@@@@I~
	virtual ~CMainFrame();                                         //~@@@@I~
	void    frmsetxemain(CWxemain *Ppm);                           //~@@@@I~
	int     Loadact(int Puseact);                                  //~@@@@I~
	int     updatemainmenu(int Pusemk);                            //~@@@@I~
	int     enablemainmenu(void);                                  //~@@@@I~
//#ifdef _DEBUG                                                    //~@@@@R~
//    virtual void AssertValid() const;                            //~@@@@R~
//    virtual void Dump(CDumpContext& dc) const;                   //~@@@@R~
//#endif                                                           //~@@@@R~
                                                                   //~@@@@I~
protected:                                                         //~@@@@I~
//  CStatusBar  m_wndStatusBar;                                    //~@@@@I~
//  CToolBar    m_wndToolBar;                                      //~@@@@I~
                                                                   //~@@@@I~
protected:                                                         //~@@@@I~
	//{{AFX_MSG(CMainFrame)                                        //~@@@@I~
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);           //~@@@@R~
    afx_msg int OnPreCreateWindowW(LPCREATESTRUCT lpCreateStruct); //~vb4vI~
	afx_msg void OnClose();                                        //~@@@@I~
	afx_msg void OnInitMenu(CMenu* pMenu);                         //~@@@@I~
            void OnInitMenuW(HMENU pMenu)                          //~@@@@I~
			{                                                      //~@@@@I~
				OnInitMenu(new CMenu(pMenu));                      //~@@@@I~
			}                                                      //~@@@@I~
	afx_msg void OnHelp();                                         //~@@@@I~
            void OnHelpW(UINT unotifyCode,int nID,HWND wndCtl)     //~@@@@I~
			{	OnHelp();	}                                      //~@@@@I~
	//}}AFX_MSG                                                    //~@@@@I~
	DECLARE_MESSAGE_MAP()                                          //~@@@@I~
private:                                                           //~@@@@I~
	int Menablecopy,Menablecut,Menablepaste;                       //~@@@@I~
	int Menablepastev;                                             //~@@@@I~
public:                                                            //~vb20I~
	int Mswappexit;                                                //~@@@@I~
private:                                                           //~vb20I~
	CBitmap Mbmsave,Mbmend,Mbmcancel,Mbmprint,Mbmcopy,Mbmcut,Mbmclear,Mbmpastei,Mbmpaster;//~@@@@I~
	CBitmap Mbmexplorer,Mbmdos;                                    //~@@@@I~
	CBitmap Mbmpastev;                                             //~@@@@I~
	int  appendmenu(CMenu* Ppmenu);                                //~@@@@I~
	CMenu *GetMenuW();                                             //~@@@@I~
///////////////////////////////////////////////////////////////////////////////~@@@@I~
    void OnEditCut(UINT unotifyCode,int nID,HWND wndCtl)           //~@@@@I~
	{                                                              //~@@@@I~
		m_view.OnEditCut();                                        //~@@@@I~
	}                                                              //~@@@@I~
    void OnEditCopy(UINT unotifyCode,int nID,HWND wndCtl)          //~@@@@I~
	{                                                              //~@@@@I~
		m_view.OnEditCopy();                                       //~@@@@I~
	}                                                              //~@@@@I~
    void OnEditClear(UINT unotifyCode,int nID,HWND wndCtl)         //~@@@@I~
	{                                                              //~@@@@I~
		m_view.OnEditClear();                                      //~@@@@I~
	}                                                              //~@@@@I~
    void OnEditPasteStd(UINT unotifyCode,int nID,HWND wndCtl)      //~@@@@I~
	{                                                              //~@@@@I~
		m_view.OnEditPasteStd();                                   //~@@@@I~
	}                                                              //~@@@@I~
    void OnEditPaste(UINT unotifyCode,int nID,HWND wndCtl)         //~@@@@I~
	{                                                              //~@@@@I~
		m_view.OnEditPaste();                                      //~@@@@I~
	}                                                              //~@@@@I~
    void OnEditPasteRep(UINT unotifyCode,int nID,HWND wndCtl)      //~@@@@I~
	{                                                              //~@@@@I~
		m_view.OnEditPasteRep();                                   //~@@@@I~
	}                                                              //~@@@@I~
    void OnEditEnd(UINT unotifyCode,int nID,HWND wndCtl)           //~@@@@I~
	{                                                              //~@@@@I~
		m_view.OnEditEnd();                                        //~@@@@I~
	}                                                              //~@@@@I~
    void OnEditCancel(UINT unotifyCode,int nID,HWND wndCtl)        //~@@@@I~
	{                                                              //~@@@@I~
		m_view.OnEditCancel();                                     //~@@@@I~
	}                                                              //~@@@@I~
                                                                   //~@@@@I~
    void OnFilePrint(UINT unotifyCode,int nID,HWND wndCtl)         //~@@@@R~
	{                                                              //~@@@@I~
		m_view.OnFilePrint();  //through wxeview, goto wxeprt      //~@@@@R~
	}                                                              //~@@@@I~
	void BeginPrintJob(HDC hDC)                                    //~@@@@I~
	{                                                              //~@@@@I~
		m_view.OnBeginPrinting(new CDC(hDC),this/*CPrintJobInfo*/);//~@@@@R~
	}                                                              //~@@@@I~
	void EndPrintJob(HDC hDC, bool bAborted)                       //~@@@@I~
	{                                                              //~@@@@I~
		m_view.OnEndPrinting(new CDC(hDC),this/*CPrintJobInfo*/);  //~@@@@R~
	}                                                              //~@@@@I~
//  void PrePrintPage(UINT nPage, HDC hDC);  //SaveDC              //~@@@@I~
	bool PrintPage(UINT nPage, HDC hDC)   //rc:False=Cancel        //~@@@@I~
	{                                                              //~@@@@I~
		return Mpxemain->printpage(nPage,hDC);                     //~@@@@R~
	}                                                              //~@@@@I~
//  void PostPrintPage(UINT nPage, HDC hDC); //RestoreDC           //~@@@@I~
	bool IsValidPage(UINT nPage)   //rc:False=Cancel               //~@@@@I~
	{                                                              //~@@@@I~
		return Mpxemain->isvalidpage(nPage);                       //~@@@@R~
	}                                                              //~@@@@I~
                                                                   //~@@@@I~
    void OnFileScrprt(UINT unotifyCode,int nID,HWND wndCtl)        //~@@@@I~
	{                                                              //~@@@@I~
		m_view.OnFileScrprt();                                     //~@@@@I~
	}                                                              //~@@@@I~
    void OnEditExplorer(UINT unotifyCode,int nID,HWND wndCtl)      //~@@@@I~
	{                                                              //~@@@@I~
		m_view.OnEditExplorer();                                   //~@@@@I~
	}                                                              //~@@@@I~
    void OnFileDos(UINT unotifyCode,int nID,HWND wndCtl)           //~@@@@I~
	{                                                              //~@@@@I~
		m_view.OnFileDos();                                        //~@@@@I~
	}                                                              //~@@@@I~
                                                                   //~@@@@I~
    void OnFont(UINT unotifyCode,int nID,HWND wndCtl)              //~@@@@I~
	{                                                              //~@@@@I~
		m_view.OnFont();                                           //~@@@@I~
	}                                                              //~@@@@I~
    void OnPageSetup(UINT unotifyCode,int nID,HWND wndCtl)         //~@@@@I~
	{                                                              //~@@@@I~
		m_view.OnPageSetup();                                      //~@@@@I~
	}                                                              //~@@@@I~
	void OnFileOpen(UINT unotifyCode,int nID,HWND wndCtl);         //~@@@@I~
public:                                                            //~@@@@I~
	void OnFileSave(UINT unotifyCode,int nID,HWND wndCtl);         //~@@@@I~
	void OnFileSaveAs(UINT unotifyCode,int nID,HWND wndCtl);       //~@@@@I~
	int fileselectiondlg(int Pcmd,char *Pfnm);                     //~@@@@R~
};
