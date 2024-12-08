//*CID://+vavCR~:                             update#=  131;       //+vavCR~
//********************************************************************//~2B09I~
//vavC:140430 change Dialog to modeal                              //+vavCI~
//vavB:140429 (BUG:wxe)preview box was not redrawn at focus regain //~vavBI~
//vavz:140428 (wxe)display ucs2 filename on page dialog            //~vavzI~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//v71A:061030 (WXE)Use HtmlHelp;Winhelp is deprecated at Vista;XP english ersion cannot read .hlp by the readson of codepage unsupported//~v71AI~
//v65i:050802 (BUG:WXE)allow print font minimum 0,but err when both cellh and font is 0//~v65iI~
//v62W:050422 (WXE)maximum cell height definition for small doc    //~v62WI~
//v55D:040309 (WXE)popup help for dialog control                   //~v55DI~
//v51h:030525 (WXE)col/row by font size specification              //~3525I~
//********************************************************************//~3525I~
#define MARGIN_PREVIEWBOX    8    //preview box border margin      //~2B09R~
#define MARGIN_FORM_CLIP     5    //5mm form minimum margin        //~2B23R~
#define PRINTCOL_MIN         0    //print page column minimum      //~3525I~
//#define PRINTCOL_MAX         500  //print page column maximum      //~3525R~//~va20R~
#define PRINTROW_MIN         0    //print page row    minimum      //~3525I~
#define PRINTROW_MAX         500  //print page row    maximum      //~3525R~
//#define PRINTFONTSZH_MIN      2    //print page fontsz minimum   //~v65iR~
#define PRINTFONTSZH_MIN      0    //print page fontsz minimum     //~v65iI~
#define PRINTFONTSZH_MAX     999   //print page fontsz maximum     //~3601R~
#define PRINTFONTSZW_MIN      0    //print page fontsz minimum     //~3525I~
#define PRINTFONTSZW_MAX     999   //print page fontsz maximum     //~3601R~
#define PRINTCELLSZH_MIN      0    //print page fontsz minimum     //~v51hI~
#define PRINTCELLSZH_MAX     999   //print page fontsz maximum     //~v51hI~
#define PRINTCELLSZW_MIN      0    //print page fontsz minimum     //~v51hI~
#define PRINTCELLSZW_MAX     999   //print page fontsz maximum     //~v51hI~
#define PRINTCELLSZHMAX_MIN      0    //print page cell height max //~v62WI~
#define PRINTCELLSZHMAX_MAX     999   //print page cell height max //~v62WI~
//********************************************************************//~2B09I~
#if !defined(AFX_WXEPAGE_H__1BDEDA44_EEFB_11D6_8C9B_00909951ADD0__INCLUDED_)
#define AFX_WXEPAGE_H__1BDEDA44_EEFB_11D6_8C9B_00909951ADD0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Wxepage.h                                                       //~v65iR~
//
/////////////////////////////////////////////////////////////////////////////
// CWxepage                                                        //~v65iR~

//class CWxepage : public CDialog                                  //~@@@@R~
  class CWxepage : public CDialogImpl<CWxepage>                    //~@@@@I~
				,public CWinDataExchange<CWxepage>                  //~@@@@I~
{
public:
	CWxepage(CWnd* pParent = NULL);                                //~v65iR~
	~CWxepage();                                                   //~2B09I~
	CWxepage(CWnd* pParent,CWxemain *Ppwxemain);                   //~2B03I~

	//{{AFX_DATA(CWxepage)
	enum { IDD = IDD_PAGE_SETUP };
	CSpinButtonCtrl	Mspinpcellszhmax;                              //~v62WR~
	CEdit	Meditpcellszhmax;                                      //~v62WR~
	CButton	Mbuttonok;
	CButton	Mbuttoncancel;
	CButton	MbuttonPreviewPrintScr;
	CButton	MbuttonPrintScr;
	CSpinButtonCtrl	Mspinpcellszw;                                 //~3608R~
	CSpinButtonCtrl	Mspinpcellszh;                                 //~3608R~
	CEdit	Meditpcellszw;                                         //~3608R~
	CEdit	Meditpcellszh;                                         //~3608R~
	CComboBox	Mcombofontstyle;
	CButton	Mcheckpfontsz;
	CEdit	Meditpfontszh;                                         //~3525R~
	CEdit	Meditpfontszw;                                         //~3525I~
	CSpinButtonCtrl	Mspinrow;
	CSpinButtonCtrl	Mspinpfontszh;                                 //~3525R~
	CSpinButtonCtrl	Mspinpfontszw;                                 //~3525I~
	CSpinButtonCtrl	Mspincol;
	CButton	Mbuttonpreviewnextpage;
	CEdit	Meditcurpage;
	CButton	Mbuttonpreviewprevpage;
	CButton	Mcheckfullpage;
	CButton	Mchecklandscape;
	CButton	Mbuttonprint;
	CButton	Mbuttonpreview;
	CButton	Mcheckwwscrprt;                                        //~2B10R~
	CEdit	Meditfilename;
	CEdit	Meditmaxcolrow;                                        //~3525R~
	CEdit	Meditmaxlrecl;
	CStatic	Mstaticpreview;
	CEdit	Medit2p;
	CButton	Mcheckfooter;
	CButton	Mchecksystime;
	CButton	Mchecklinenumber;
	CButton	Mcheckfiletime;
	CButton	Mcheckheader;                                          //~2B03R~
	CButton	Mcheck2p;
	CEdit	Medittop;
	CEdit	Meditright;
	CEdit	Meditrow;
	CEdit	Meditleft;
	CEdit	Meditcolumn;
	CEdit	Meditbottom;
	CComboBox	Mcombo_form;
	BOOL	Mlandscape;                                            //~2B03M~
	BOOL	Mfullpage;                                             //~2B30I~
	BOOL	M2p;                                                   //~2B03M~
	BOOL	Mheader;                                               //~2B03M~
	BOOL	Mfooter;                                               //~2B03I~
	BOOL	Mlinenumber;                                           //~2B03M~
	BOOL	Mfiletime;                                             //~2B03M~
	BOOL	Msystime;                                              //~2B03M~
	int		Mpagecol;                                              //~2B09R~
	int		Mpagerow;                                              //~2B09R~
	int		Mmarginb;                                              //~2B03M~
	int		Mmarginl;                                              //~2B03M~
	int		Mmarginr;                                              //~2B03M~
	int		Mmargint;                                              //~2B03M~
	int		M2pcol;
	BOOL	Mwwscrprt;
	int		Mcurpage;
	int		Mpfontszh;                                             //~3601R~
	int		Mpfontszw;                                             //~3601I~
	BOOL	Mchkpfontsz;                                           //~3525R~
//  UINT    Mpcellszh;                                             //~@@@@R~
    int     Mpcellszh;                                             //~@@@@I~
//  UINT    Mpcellszw;                                             //~@@@@R~
    int     Mpcellszw;                                             //~@@@@I~
//  UINT    Mpcellszhmax;                                          //~@@@@R~
    int     Mpcellszhmax;                                          //~@@@@I~
	//}}AFX_DATA
        //~3608R~
	//}}AFX_DATA


	//{{AFX_VIRTUAL(CWxepage)
	public:
//  virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);//~2B03R~
//	virtual BOOL Create(CWnd* pParentWnd);                         //~@@@@R~
	protected:
//    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート//~@@@@R~
	//}}AFX_VIRTUAL

protected:

	//{{AFX_MSG(CWxepage)
  	afx_msg void OnWindowPosChanged(LPWINDOWPOS Ppos);             //~vavBR~
	        void OnWindowPosChangedW(LPWINDOWPOS Ppos)             //~vavBR~
			{                                                      //~vavBI~
				OnWindowPosChanged(Ppos);                          //~vavBR~
			}                                                      //~vavBI~
  	afx_msg void OnWindowPosChanging(LPWINDOWPOS Ppos);            //~vavBI~
	        void OnWindowPosChangingW(LPWINDOWPOS Ppos)            //~vavBI~
			{                                                      //~vavBI~
				OnWindowPosChanging(Ppos);                         //~vavBI~
			}                                                      //~vavBI~
	virtual void OnOK();
		    void OnOKW(UINT code,int id,HWND lParam)               //~@@@@I~
            {                                                      //~@@@@I~
			    OnOK();                                            //~@@@@I~
                EndDialog(id);  //DestroyWindow is assrt err for modal dialog//+vavCI~
            }                                                      //~@@@@I~
	afx_msg void OnPrint();
		    void OnPrintW(UINT code,int id,HWND lParam)            //~@@@@I~
            {                                                      //~@@@@I~
				OnPrint();                                         //~@@@@I~
                EndDialog(id);  //DestroyWindow is assrt err for modal dialog//+vavCI~
            }                                                      //~@@@@I~
	afx_msg void OnPreview();
		    void OnPreviewW(UINT code,int id,HWND lParam)          //~@@@@I~
            {                                                      //~@@@@I~
				OnPreview();                                       //~@@@@I~
            }                                                      //~@@@@I~
	afx_msg void OnPreviewprevpage();                              //~2C14I~
		    void OnPreviewprevpageW(UINT code,int id,HWND lParam)  //~@@@@I~
            {                                                      //~@@@@I~
				OnPreviewprevpage();                               //~@@@@I~
            }                                                      //~@@@@I~
	virtual BOOL OnInitDialog();
		    BOOL OnInitDialogW(CWindow wndFocus,LPARAM lInitParam) //~@@@@I~
            {                                                      //~@@@@I~
			    return OnInitDialog();                             //~@@@@I~
            }                                                      //~@@@@I~
	afx_msg void OnCheck2p();
		    void OnCheck2pW(UINT code,int id,HWND lParam)          //~@@@@I~
            {                                                      //~@@@@I~
				OnCheck2p();                                       //~@@@@I~
            }                                                      //~@@@@I~
	afx_msg void OnCheckpfontsz();                                 //~3525I~
		    void OnCheckpfontszW(UINT code,int id,HWND lParam)     //~@@@@I~
            {                                                      //~@@@@I~
				OnCheckpfontsz();                                  //~@@@@I~
            }                                                      //~@@@@I~
	afx_msg void OnCheckFooter();
		    void OnCheckFooterW(UINT code,int id,HWND lParam)      //~@@@@I~
            {                                                      //~@@@@I~
				OnCheckFooter();                                   //~@@@@I~
            }                                                      //~@@@@I~
	afx_msg void OnCheckHeader();
		    void OnCheckHeaderW(UINT code,int id,HWND lParam)      //~@@@@I~
            {                                                      //~@@@@I~
				OnCheckHeader();                                   //~@@@@I~
            }                                                      //~@@@@I~
	afx_msg void OnPreviewprtscr();
		    void OnPreviewprtscrW(UINT code,int id,HWND lParam)    //~@@@@I~
            {                                                      //~@@@@I~
				OnPreviewprtscr();                                 //~@@@@I~
            }                                                      //~@@@@I~
	afx_msg void OnPrtscr();
		    void OnPrtscrW(UINT code,int id,HWND lParam)           //~@@@@I~
            {                                                      //~@@@@I~
				OnPrtscr();                                        //~@@@@I~
                EndDialog(id);  //DestroyWindow is assrt err for modal dialog//+vavCI~
            }                                                      //~@@@@I~
	afx_msg void OnChangeEditCurpage();
		    void OnChangeEditCurpageW(UINT code,int id,HWND lParam)//~@@@@I~
            {                                                      //~@@@@I~
				OnChangeEditCurpage();                             //~@@@@I~
            }                                                      //~@@@@I~
	afx_msg void OnPreviewNextpage();
		    void OnPreviewNextpageW(UINT code,int id,HWND lParam)  //~@@@@I~
            {                                                      //~@@@@I~
				OnPreviewNextpage();                               //~@@@@I~
            }                                                      //~@@@@I~
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
		    void OnContextMenuW(HWND Phwnd, CPoint point)          //~@@@@I~
            {                                                      //~@@@@I~
			    OnContextMenu(new CWindow(Phwnd),point);           //~@@@@I~
            }                                                      //~@@@@I~
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnPageCancel();
		    void OnPageCancelW(UINT code,int id,HWND lParam)       //~@@@@I~
            {                                                      //~@@@@I~
			    OnPageCancel();                                    //~@@@@I~
                EndDialog(id);  //DestroyWindow is assrt err for modal dialog//+vavCI~
            }                                                      //~@@@@I~
	//}}AFX_MSG
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:                                                           //~2B03I~
//****pvt func                                                     //~2B03I~
    BOOL Initcombo();                                              //~2B03I~
	void displayform(int Pscrprtid);                               //~2B10R~
	int  getparm();                                                //~3601R~
	void putparm();                                                //~2B09R~
	int  pagecount(int Pscrprtid);                                 //~3601R~
	void displaypageno(void);                                      //~2B09I~
	void previewrectdraw(CDC *Ppdc,CBrush *Ppbrush,RECT *Pprect);  //~2B09R~
	void displaybyrect(CDC *Ppdc,int Pprtscrid,RECT &Pdrawrect);   //~2B23I~
	void saverestparm(int Psavesw);                                //~2B23I~
//  int chkinrect(CPoint point);                                   //~v71AR~
	char *chkinrect(CPoint point);                                 //~v71AR~
	int chkinrectsub(CPoint Ppt,int Prid);                         //~v55DI~
//****pvt data                                                     //~2B03I~
    CWxemain* Mpwxemain;                                           //~2B03I~
	RECT  Mpreview_rect;                                           //~2B04I~
	int Mprttype,Mtotlineno,Mcmaxcol,Mcmaxrow,Mlinenodigit,Mmaxpage;//~2B30R~
	int Mprtdatamaxcol,Mprtdatamaxrow;                             //~3601R~
	int Morgprttype;                                               //~2B30R~
    int Mmaxlrecl,Mlinenosz,Mtotrow,Mcmaxlrecl;                    //~2C01R~
    char Mprtfnm[_MAX_PATH];                                       //~2B07I~
#ifdef W32UNICODE                                                  //~vavzI~
    UWCH MprtfnmW[_MAX_PATHWC];                                    //~vavzR~
#endif                                                             //~vavzI~
    char Mformtype[32];                                            //~2B09R~
    char Msvformtype[32];                                          //~2B23I~
    char Mprtfontstyle[32];                                        //~3601R~
	BOOL	Msv2p;                                                 //~2B23I~
	BOOL	Msvfiletime;                                           //~2B23I~
	BOOL	Msvheader;                                             //~2B23I~
	BOOL	Msvfooter;                                             //~2B23I~
	BOOL	Msvlinenumber;                                         //~2B23I~
	BOOL	Msvsystime;                                            //~2B23I~
	BOOL	Msvwwscrprt;                                           //~2B23I~
	int		Msvpagecol;                                            //~2B23I~
	int		Msvpagerow;                                            //~2B23I~
	int		Msv2pcol;                                              //~2B23I~
	int		Msvmarginl;                                            //~2B23I~
	int		Msvmarginr;                                            //~2B23I~
	int		Msvmargint;                                            //~2B23I~
	int		Msvmarginb;                                            //~2B23I~
	BOOL	Msvlandscape;                                          //~2B23I~
	BOOL	Msvfullpage;                                           //~2B30I~
BEGIN_MESSAGE_MAP(CWxepage, CDialog)                               //~@@@@I~
	MSG_WM_WINDOWPOSCHANGED(OnWindowPosChangedW)                   //~vavBR~
	MSG_WM_WINDOWPOSCHANGING(OnWindowPosChangingW)                 //~vavBI~
	ON_BN_CLICKED(IDC_PRINT, OnPrintW)                             //~@@@@R~
	ON_BN_CLICKED(IDC_PREVIEW, OnPreviewW)                          //~@@@@I~
	ON_BN_CLICKED(IDC_PREVIEW_PREVPAGE, OnPreviewprevpageW)         //~@@@@I~
	ON_BN_CLICKED(IDC_CHECK_2P, OnCheck2pW)                        //~@@@@R~
	ON_BN_CLICKED(IDC_CHECK_PFONTSZ, OnCheckpfontszW)              //~@@@@R~
	ON_BN_CLICKED(IDC_CHECK_FOOTER, OnCheckFooterW)                //~@@@@R~
	ON_BN_CLICKED(IDC_CHECK_HEADER, OnCheckHeaderW)                //~@@@@R~
	ON_BN_CLICKED(IDC_PREVIEWPRTSCR, OnPreviewprtscrW)             //~@@@@R~
	ON_BN_CLICKED(IDC_PRTSCR, OnPrtscrW)                           //~@@@@R~
	ON_EN_CHANGE(IDC_EDIT_CURPAGE, OnChangeEditCurpageW)           //~@@@@R~
	ON_BN_CLICKED(IDC_PREVIEW_NEXTPAGE, OnPreviewNextpageW)        //~@@@@R~
//  ON_WM_CONTEXTMENU()                                            //~@@@@R~
    MSG_WM_CONTEXTMENU(OnContextMenuW)                             //~@@@@R~
//  ON_WM_HELPINFO()                                               //~@@@@R~
    MSG_WM_HELP(OnHelpInfo)                                        //~@@@@I~
	ON_BN_CLICKED(IDCANCEL, OnPageCancelW)                         //~@@@@R~
	ON_BN_CLICKED(IDOK, OnOKW)                                     //~@@@@I~
	MSG_WM_INITDIALOG(OnInitDialogW)                               //~@@@@I~
END_MESSAGE_MAP()                                                  //~@@@@I~
                                                                   //~@@@@I~
BEGIN_DDX_MAP(CWxedlg)                                             //~@@@@I~
    DDX_CONTROL_HANDLE(IDC_SPIN_CELLSZH_MAX, Mspinpcellszhmax);    //~@@@@I~
    DDX_CONTROL_HANDLE(IDC_EDIT_CELLSZH_MAX, Meditpcellszhmax);    //~@@@@I~
    DDX_CONTROL_HANDLE(IDOK, Mbuttonok);                           //~@@@@I~
    DDX_CONTROL_HANDLE(IDCANCEL, Mbuttoncancel);                   //~@@@@I~
    DDX_CONTROL_HANDLE(IDC_PREVIEWPRTSCR, MbuttonPreviewPrintScr); //~@@@@I~
    DDX_CONTROL_HANDLE(IDC_PRTSCR, MbuttonPrintScr);               //~@@@@I~
    DDX_CONTROL_HANDLE(IDC_SPIN_CELLSZW, Mspinpcellszw);           //~@@@@I~
    DDX_CONTROL_HANDLE(IDC_SPIN_CELLSZH, Mspinpcellszh);           //~@@@@I~
    DDX_CONTROL_HANDLE(IDC_EDIT_CELLSZW, Meditpcellszw);           //~@@@@I~
    DDX_CONTROL_HANDLE(IDC_EDIT_CELLSZH, Meditpcellszh);           //~@@@@I~
    DDX_CONTROL_HANDLE(IDC_COMBO_FONTSTYLE, Mcombofontstyle);      //~@@@@I~
    DDX_CONTROL_HANDLE(IDC_CHECK_PFONTSZ, Mcheckpfontsz);          //~@@@@I~
    DDX_CONTROL_HANDLE(IDC_EDIT_PFONTSZH, Meditpfontszh);          //~@@@@I~
    DDX_CONTROL_HANDLE(IDC_EDIT_PFONTSZW, Meditpfontszw);          //~@@@@I~
    DDX_CONTROL_HANDLE(IDC_SPIN_ROW, Mspinrow);                    //~@@@@I~
    DDX_CONTROL_HANDLE(IDC_SPIN_PFONTSZH, Mspinpfontszh);          //~@@@@I~
    DDX_CONTROL_HANDLE(IDC_SPIN_PFONTSZW, Mspinpfontszw);          //~@@@@I~
    DDX_CONTROL_HANDLE(IDC_SPIN_COL, Mspincol);                    //~@@@@I~
    DDX_CONTROL_HANDLE(IDC_PREVIEW_NEXTPAGE, Mbuttonpreviewnextpage);//~@@@@I~
    DDX_CONTROL_HANDLE(IDC_EDIT_CURPAGE, Meditcurpage);            //~@@@@I~
    DDX_CONTROL_HANDLE(IDC_PREVIEW_PREVPAGE, Mbuttonpreviewprevpage);//~@@@@I~
    DDX_CONTROL_HANDLE(IDC_CHECK_FULLPAGE, Mcheckfullpage);        //~@@@@I~
    DDX_CONTROL_HANDLE(IDC_CHECK_LANDSCAPE, Mchecklandscape);      //~@@@@I~
    DDX_CONTROL_HANDLE(IDC_PRINT, Mbuttonprint);                   //~@@@@I~
    DDX_CONTROL_HANDLE(IDC_PREVIEW, Mbuttonpreview);               //~@@@@I~
    DDX_CONTROL_HANDLE(IDC_CHECK_WWSCRPRT, Mcheckwwscrprt);        //~@@@@I~
    DDX_CONTROL_HANDLE(IDC_EDIT_FILENAME, Meditfilename);          //~@@@@I~
    DDX_CONTROL_HANDLE(IDC_EDIT_MAXCOLROW, Meditmaxcolrow);        //~@@@@I~
    DDX_CONTROL_HANDLE(IDC_EDIT_MAXLRECL, Meditmaxlrecl);          //~@@@@I~
    DDX_CONTROL_HANDLE(IDC_STATIC_PREVIEW, Mstaticpreview);        //~@@@@I~
    DDX_CONTROL_HANDLE(IDC_EDIT_2P, Medit2p);                      //~@@@@I~
    DDX_CONTROL_HANDLE(IDC_CHECK_FOOTER, Mcheckfooter);            //~@@@@I~
    DDX_CONTROL_HANDLE(IDC_CHECK_SYSTIME, Mchecksystime);          //~@@@@I~
    DDX_CONTROL_HANDLE(IDC_CHECK_LINENUMBER, Mchecklinenumber);    //~@@@@I~
    DDX_CONTROL_HANDLE(IDC_CHECK_FILETIME, Mcheckfiletime);        //~@@@@I~
    DDX_CONTROL_HANDLE(IDC_CHECK_HEADER, Mcheckheader);            //~@@@@I~
    DDX_CONTROL_HANDLE(IDC_CHECK_2P, Mcheck2p);                    //~@@@@I~
    DDX_CONTROL_HANDLE(IDC_EDIT_TOP, Medittop);                    //~@@@@I~
    DDX_CONTROL_HANDLE(IDC_EDIT_RIGHT, Meditright);                //~@@@@I~
    DDX_CONTROL_HANDLE(IDC_EDIT_ROW, Meditrow);                    //~@@@@I~
    DDX_CONTROL_HANDLE(IDC_EDIT_LEFT, Meditleft);                  //~@@@@I~
    DDX_CONTROL_HANDLE(IDC_EDIT_COLUMN, Meditcolumn);              //~@@@@I~
    DDX_CONTROL_HANDLE(IDC_EDIT_BOTTOM, Meditbottom);              //~@@@@I~
    DDX_CONTROL_HANDLE(IDC_COMBO_FORM, Mcombo_form);               //~@@@@I~
    DDX_CHECK(IDC_CHECK_2P, M2p);                                  //~@@@@I~
    DDX_CHECK(IDC_CHECK_HEADER, Mheader);                          //~@@@@I~
    DDX_CHECK(IDC_CHECK_FOOTER, Mfooter);                          //~@@@@I~
    DDX_CHECK(IDC_CHECK_LINENUMBER, Mlinenumber);                  //~@@@@I~
    DDX_CHECK(IDC_CHECK_FILETIME, Mfiletime);                      //~@@@@I~
    DDX_CHECK(IDC_CHECK_SYSTIME, Msystime);                        //~@@@@I~
    DDX_INT_RANGE(IDC_EDIT_COLUMN, Mpagecol,PRINTCOL_MIN, PRINTCOL_MAX);//~@@@@I~
    DDX_INT_RANGE(IDC_EDIT_ROW, Mpagerow,PRINTROW_MIN, PRINTROW_MAX);//~@@@@I~
    DDX_INT_RANGE(IDC_EDIT_BOTTOM, Mmarginb,0, 1000);              //~@@@@I~
    DDX_INT_RANGE(IDC_EDIT_LEFT, Mmarginl,0, 1000);                //~@@@@I~
    DDX_INT_RANGE(IDC_EDIT_RIGHT, Mmarginr,0, 1000);               //~@@@@I~
    DDX_INT_RANGE(IDC_EDIT_TOP, Mmargint,0, 1000);                 //~@@@@I~
    DDX_INT_RANGE(IDC_EDIT_2P, M2pcol, 0, 100);                    //~@@@@I~
    DDX_CHECK(IDC_CHECK_WWSCRPRT, Mwwscrprt);                      //~@@@@I~
    DDX_INT(IDC_EDIT_CURPAGE, Mcurpage);                           //~@@@@R~
    DDX_INT_RANGE(IDC_EDIT_PFONTSZH, Mpfontszh,PRINTFONTSZH_MIN, PRINTFONTSZH_MAX);//~@@@@I~
    DDX_INT_RANGE(IDC_EDIT_PFONTSZW, Mpfontszw, PRINTFONTSZW_MIN, PRINTFONTSZW_MAX);//~@@@@I~
    DDX_CHECK(IDC_CHECK_PFONTSZ, Mchkpfontsz);                     //~@@@@I~
    DDX_UINT_RANGE(IDC_EDIT_CELLSZH, Mpcellszh, PRINTCELLSZH_MIN, PRINTCELLSZH_MAX);//~@@@@R~
    DDX_UINT_RANGE(IDC_EDIT_CELLSZW, Mpcellszw, PRINTCELLSZW_MIN, PRINTCELLSZW_MAX);//~@@@@R~
    DDX_UINT_RANGE(IDC_EDIT_CELLSZH_MAX, Mpcellszhmax, PRINTCELLSZHMAX_MIN, PRINTCELLSZHMAX_MAX);//~@@@@R~
END_DDX_MAP()                                                      //~@@@@M~
};

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_WXEPAGE_H__1BDEDA44_EEFB_11D6_8C9B_00909951ADD0__INCLUDED_)
