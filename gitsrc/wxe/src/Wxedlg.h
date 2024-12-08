//*CID://+@@@@R~:                             update#=   84;       //~@@@@R~
//***********************************************************************//~v510I~
//va3g:100207 try ligature for also wxe(write ucs string at once) for arabic etc//~va3gI~
//va0R:091006!(WXE)charset combo box                               //~va0RI~
//v740:070201 (WXE/XXE)kde dose not report keypress event for S+C+F1;so use keyup event//~v740I~
//            so support specify trigger key on setupdialog        //~v740I~
//v73y:070128-(WXE/XXE)Quiet-exit support                          //~v73yI~
//v73t:070125 cross-hair ruler support by Shift+Ctl+lbuton         //~v73tI~
//v71A:061030 (WXE)Use HtmlHelp;Winhelp is deprecated at Vista;XP english ersion cannot read .hlp by the readson of codepage unsupported//~v71AI~
//v55D:040309 (WXE)popup help for dialog control                   //~v55DI~
//v55q:040228 option to scroll by csr move(CSRSCROLL option)       //~v55qI~
//v55c:040208 (WXE)distingush L-CTL/R-CTL & report R-CTL           //~v55cI~
//v510:030215 (WXE)parameterize interval for scroll by mouse       //~v510I~
//***********************************************************************//~v510I~
#if !defined(AFX_WXEDLG_H__29FDC661_B1E6_11D6_8C9B_00909951ADD0__INCLUDED_)
#define AFX_WXEDLG_H__29FDC661_B1E6_11D6_8C9B_00909951ADD0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Wxedlg.h                                                        //~v55DR~
//

#define FONTSZH_MIN     4                                          //~2818M~
#define FONTSZH_MAX     50                                         //~2C03R~
#define FONTSZW_MIN     2                                          //~2908R~
#define FONTSZW_MAX     50                                         //~2C03R~
#define SCROLL_MIN      1                                          //~2A13R~
#define SCROLL_MAX      MAXROW                                     //~2A13I~
                                                                   //~2818I~
#define ROWH_MIN        FONTSZH_MIN                                //~2818I~
#define ROWH_MAX       (FONTSZH_MAX*2)                             //~2818I~
#define COLW_MIN        FONTSZW_MIN                                //~2818I~
#define COLW_MAX       (FONTSZW_MAX*2)                             //~2818I~
                                                                   //~2818I~
/////////////////////////////////////////////////////////////////////////////

//class CWxedlg : public CDialog                                   //~@@@@R~
class CWxedlg : public CDialogImpl<CWxedlg>                        //~@@@@R~
				,public CWinDataExchange<CWxedlg>                  //~@@@@I~
{
public:
	CWxedlg(CWnd* pParent = NULL);                                 //~v55DR~
	CWxedlg(CWnd* pParent,CWxemain *Ppwxemain);                    //~v55DR~
//BOOL Create(void);                                                 //~v510I~//~@@@@R~
	//{{AFX_DATA(CWxedlg)                                          //~v510I~
	enum { IDD = IDD_SETUP };
	CButton	Mcheckbeep;
	CButton	Mcheckqexit;                                           //~v73yI~
	CButton	Mcharsetgroup;
	CComboBox	Mcombostyle;
	CComboBox	Mcombocharsetother;                                //~va0RI~
	CButton	Mcheckfreecsr;                                         //~v55qR~
	CButton	Mcheckrctl;                                            //~v55cR~
	CButton	Mcheckruler;                                           //~v73tI~
	CEdit  	Meditrulerkey;                                         //~v740R~
	CSpinButtonCtrl	Mspinscrolltimer;
	CEdit	Meditscrolltimer;
	CButton	Mcheckusemk;
	CButton	Mcheckuseact;                                          //~3103R~
	CEdit	Meditother;
	CSpinButtonCtrl	Mspinscrollctr;
	CEdit	Meditscrollctr;
	CEdit	Meditfontw;
	CEdit	Meditfonth;
	CEdit	Meditcellh;
	CEdit	Meditcellw;
	CStatic	Mstaticfontbox;
	CStatic	Mstaticcolordisplay;
	CButton	Mttcheckbox;
	CButton	Mligaturecheckbox;                                     //~va3gI~
	CEdit	Medit_g;                                               //~2907R~
	CEdit	Medit_r;                                               //~2907R~
	CEdit	Medit_b;                                               //~2907R~
	CSliderCtrl	Mslider_r;                                         //~2907R~
	CSliderCtrl	Mslider_g;                                         //~2907R~
	CSliderCtrl	Mslider_b;                                         //~2907R~
	CSpinButtonCtrl	Mspinrowheight;
	CSpinButtonCtrl	Mspincolwidth;
	CComboBox	*Mpcombofs;                                        //~2818R~
	CComboBox	*Mpcombocs;   //other charset                      //~va0RI~
	CSpinButtonCtrl	Mspinfontsz_w;
	CSpinButtonCtrl	Mspinfontsz_h;
	int		Mfontsz_h;
	int		Mfontsz_w;
	int		Mcellw;                                                //~2901R~
	int		Mcellh;                                                //~2901R~
	int		Mcharset;                                              //~2915I~
	int		Mbgcolor_b;                                            //~2907R~
	int		Mbgcolor_g;                                            //~2907R~
	int		Mbgcolor_r;                                            //~2907R~
	int		Mrulercolor_b;                                         //~v73tI~
	int		Mrulercolor_g;                                         //~v73tI~
	int		Mrulercolor_r;                                         //~v73tI~
	int		Mscrollctr;                                            //~2A13I~
	BOOL	Mttfont;
	BOOL	Mligature;                                             //~va3gI~
	int 	Mothercharset;                                         //~3102R~
	BOOL	Museact;                                               //~3103R~
	BOOL	Musemk;
	int		Mscrolltimer;                                          //~v510R~
	BOOL	Mrctl;                                                 //~v55cR~
	BOOL	Mruler;                                                //~v73tI~
	BOOL	Mfreecsr;                                              //~v55qR~
	BOOL	Mbeep;
	BOOL	Mqexit;                                                //~v73yI~
	CString	Mrulerkeycstring;                                      //~v740R~
	//}}AFX_DATA
private:                                                           //~2817R~
	RECT  Mcolorbox_rect;                                          //~2928R~
	RECT  Mfontbox_rect;                                           //~2928I~
	int   Mpaintsw;                                                //~2923I~
	int   Mfontstylectr;                                           //~2817I~
	char  Mfontstyle[80];                                          //~2817I~
	char  Mrulerkey[4];                                            //~v740I~
    CWnd* Mpparentwnd;                                             //~2817R~
    CWxemain* Mpwxemain;                                           //~2827R~
    BOOL Initcombo();                                              //~2817I~
    BOOL Initcomboothercharset();                                  //~va0RI~
	void setselectothercharset(char *Peditcharset);	//other charset combo box selected entry update//~va0RR~
	void displaycolor(void);                                       //~2923I~
	void displayfont(void);                                        //~2928I~
//	int chkinrect(CPoint point);                                   //~v71AR~
	char *chkinrect(CPoint point);                                 //~v71AI~
	int chkinrectsub(CPoint Ppt,int Prid);                         //~v55DI~
	int setrulerkey(int Popt);                                     //~v740I~

	//{{AFX_VIRTUAL(CWxedlg)
//    protected:                                                   //~@@@@R~
//    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support//~v55DR~//~@@@@R~
	//}}AFX_VIRTUAL

protected:

	//{{AFX_MSG(CWxedlg)
	virtual void OnOK();
		    void OnOKW(UINT code,int id,HWND lParam)               //~@@@@I~
            {                                                      //~@@@@I~
			    OnOK();                                            //~@@@@R~
//              EndDialog(id); //for modal                         //+@@@@R~
                DestroyWindow();                                   //+@@@@I~
            }                                                      //~@@@@I~
	virtual void OnCancel();
		    void OnCancelW(UINT code,int id,HWND lParam)           //~@@@@I~
            {                                                      //~@@@@I~
			    OnCancel();                                        //~@@@@I~
//              EndDialog(id);  //for modal                        //+@@@@R~
                DestroyWindow();                                   //+@@@@I~
            }                                                      //~@@@@I~
	virtual BOOL OnInitDialog();
		    BOOL OnInitDialogW(CWindow wndFocus,LPARAM lInitParam) //~@@@@R~
            {                                                      //~@@@@I~
			    return OnInitDialog();                             //~@@@@R~
            }                                                      //~@@@@I~
	afx_msg void OnSelchangeComboStyle();
		    void OnSelchangeComboStyleW(UINT code,int id,HWND lParam)//~@@@@I~
            {                                                      //~@@@@I~
			    OnSelchangeComboStyle();                           //~@@@@I~
            }                                                      //~@@@@I~
	afx_msg void OnSelchangeComboCharset();                        //~va0RI~
		    void OnSelchangeComboCharsetW(UINT code,int id,HWND lParam)//~@@@@I~
            {                                                      //~@@@@I~
			    OnSelchangeComboCharset();                         //~@@@@I~
            }                                                      //~@@@@I~
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
            void OnHScrollW(UINT nSBCode, UINT nPos, HWND Phwnd)   //~@@@@I~
			{                                                      //~@@@@I~
				OnHScroll(nSBCode,nPos,(CScrollBar *)(new CWindow(Phwnd)));//~@@@@I~
			}                                                      //~@@@@I~
    afx_msg void OnPaint();                                        //~2928R~
            void OnPaintW(HDC Pdc)                                 //~@@@@I~
			{                                                      //~@@@@I~
				OnPaint();                                         //~@@@@I~
			}                                                      //~@@@@I~
	afx_msg void OnChangeEditHeight();
		    void OnChangeEditHeightW(UINT code,int id,HWND lParam) //~@@@@I~
            {                                                      //~@@@@I~
			    OnChangeEditHeight();                              //~@@@@I~
            }                                                      //~@@@@I~
	afx_msg void OnChangeEditColw();
		    void OnChangeEditColwW(UINT code,int id,HWND lParam)   //~@@@@I~
            {                                                      //~@@@@I~
			    OnChangeEditColw();                                //~@@@@I~
            }                                                      //~@@@@I~
	afx_msg void OnChangeEditRowh();
		    void OnChangeEditRowhW(UINT code,int id,HWND lParam)   //~@@@@I~
            {                                                      //~@@@@I~
			    OnChangeEditRowh();                                //~@@@@I~
            }                                                      //~@@@@I~
	afx_msg void OnChangeEditWidth();
		    void OnChangeEditWidthW(UINT code,int id,HWND lParam)  //~@@@@I~
            {                                                      //~@@@@I~
			    OnChangeEditWidth();                               //~@@@@I~
            }                                                      //~@@@@I~
	afx_msg void OnCheckTtfont();
		    void OnCheckTtfontW(UINT code,int id,HWND lParam)      //~@@@@I~
            {                                                      //~@@@@I~
			    OnCheckTtfont();                                   //~@@@@I~
            }                                                      //~@@@@I~
	afx_msg void OnCheckLigature();                                //~va3gI~
		    void OnCheckLigatureW(UINT code,int id,HWND lParam)    //~@@@@I~
            {                                                      //~@@@@I~
			    OnCheckLigature();                                 //~@@@@I~
            }                                                      //~@@@@I~
	afx_msg void OnRadioAnsi();
		    void OnRadioAnsiW(UINT code,int id,HWND lParam)        //~@@@@I~
            {                                                      //~@@@@I~
			    OnRadioAnsi();                                     //~@@@@I~
            }                                                      //~@@@@I~
	afx_msg void OnRadioDefault();
		    void OnRadioDefaultW(UINT code,int id,HWND lParam)     //~@@@@I~
            {                                                      //~@@@@I~
			    OnRadioDefault();                                  //~@@@@I~
            }                                                      //~@@@@I~
	afx_msg void OnRadioSjis();
		    void OnRadioSjisW(UINT code,int id,HWND lParam)        //~@@@@I~
            {                                                      //~@@@@I~
			    OnRadioSjis();                                     //~@@@@I~
            }                                                      //~@@@@I~
	afx_msg void OnRadioOther();                                   //~3102I~
		    void OnRadioOtherW(UINT code,int id,HWND lParam)       //~@@@@I~
            {                                                      //~@@@@I~
			    OnRadioOther();                                    //~@@@@I~
            }                                                      //~@@@@I~
	afx_msg void OnChangeEditOther();
		    void OnChangeEditOtherW(UINT code,int id,HWND lParam)  //~@@@@I~
            {                                                      //~@@@@I~
			    OnChangeEditOther();                               //~@@@@I~
            }                                                      //~@@@@I~
	afx_msg void OnCheckRctl();                                    //~v55cR~
		    void OnCheckRctlW(UINT code,int id,HWND lParam)        //~@@@@I~
            {                                                      //~@@@@I~
			    OnCheckRctl();                                     //~@@@@I~
            }                                                      //~@@@@I~
	afx_msg void OnCheckFreecsr();                                 //~v55qR~
		    void OnCheckFreecsrW(UINT code,int id,HWND lParam)     //~@@@@I~
            {                                                      //~@@@@I~
			    OnCheckFreecsr();                                  //~@@@@I~
            }                                                      //~@@@@I~
	afx_msg void OnCheckRuler();                                   //~v73tI~
		    void OnCheckRulerW(UINT code,int id,HWND lParam)       //~@@@@I~
            {                                                      //~@@@@I~
			    OnCheckRuler();                                    //~@@@@I~
            }                                                      //~@@@@I~
	afx_msg void OnChangeEditRulerkey();                           //~v740I~
		    void OnChangeEditRulerkeyW(UINT code,int id,HWND lParam)//~@@@@I~
            {                                                      //~@@@@I~
			    OnChangeEditRulerkey();                            //~@@@@I~
            }                                                      //~@@@@I~
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
		    void OnContextMenuW(HWND Phwnd, CPoint point)          //~@@@@I~
            {                                                      //~@@@@I~
			    OnContextMenu(new CWindow(Phwnd),point);           //~@@@@I~
            }                                                      //~@@@@I~
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnCheckBeep();
		    void OnCheckBeepW(UINT code,int id,HWND lParam)        //~@@@@I~
            {                                                      //~@@@@I~
			    OnCheckBeep();                                     //~@@@@I~
            }                                                      //~@@@@I~
	afx_msg void OnCheckQexit();                                   //~v73yI~
		    void OnCheckQexitW(UINT code,int id,HWND lParam)       //~@@@@I~
            {                                                      //~@@@@I~
			    OnCheckQexit();                                    //~@@@@I~
            }                                                      //~@@@@I~
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
BEGIN_MESSAGE_MAP(CWxedlg, CDialog)                                //~@@@@I~
	ON_CBN_SELCHANGE(IDC_COMBO_STYLE, OnSelchangeComboStyleW)      //~@@@@R~
	ON_CBN_SELCHANGE(IDC_COMBO_CHARSET, OnSelchangeComboCharsetW)  //~@@@@R~
//  ON_WM_HSCROLL()                                                //~@@@@R~
    MSG_WM_HSCROLL(OnHScrollW)                                     //~@@@@I~
//  ON_WM_PAINT()                                                  //~@@@@R~
    MSG_WM_PAINT(OnPaintW)                                         //~@@@@I~
	ON_EN_CHANGE(IDC_EDIT_HEIGHT, OnChangeEditHeightW)             //~@@@@R~
	ON_EN_CHANGE(IDC_EDIT_COLW, OnChangeEditColwW)                 //~@@@@R~
	ON_EN_CHANGE(IDC_EDIT_ROWH, OnChangeEditRowhW)                 //~@@@@R~
	ON_EN_CHANGE(IDC_EDIT_WIDTH, OnChangeEditWidthW)               //~@@@@R~
	ON_BN_CLICKED(IDC_CHECK_TTFONT, OnCheckTtfontW)                //~@@@@R~
	ON_BN_CLICKED(IDC_CHECK_LIGATURE, OnCheckLigatureW)            //~@@@@R~
	ON_BN_CLICKED(IDC_RADIO_ANSI, OnRadioAnsiW)                    //~@@@@R~
	ON_BN_CLICKED(IDC_RADIO_DEFAULT, OnRadioDefaultW)              //~@@@@R~
	ON_BN_CLICKED(IDC_RADIO_SJIS, OnRadioSjisW)                    //~@@@@R~
	ON_BN_CLICKED(IDC_RADIO_OTHER, OnRadioOtherW)                  //~@@@@R~
	ON_EN_CHANGE(IDC_EDIT_OTHER, OnChangeEditOtherW)               //~@@@@R~
	ON_EN_CHANGE(IDC_EDIT_RULERKEY,OnChangeEditRulerkeyW)          //~@@@@R~
	ON_BN_CLICKED(IDC_CHECK_RCTL, OnCheckRctlW)                    //~@@@@R~
	ON_BN_CLICKED(IDC_CHECK_RULER, OnCheckRulerW)                  //~@@@@R~
	ON_BN_CLICKED(IDC_CHECK_FREECSR, OnCheckFreecsrW)              //~@@@@R~
//	ON_WM_CONTEXTMENU()                                            //~@@@@R~
    MSG_WM_CONTEXTMENU(OnContextMenuW)                             //~@@@@R~
//	ON_WM_HELPINFO()                                               //~@@@@R~
    MSG_WM_HELP(OnHelpInfo)                                        //~@@@@I~
	ON_BN_CLICKED(IDC_CHECK_BEEP, OnCheckBeepW)                    //~@@@@R~
	ON_BN_CLICKED(IDC_CHECK_QEXIT,OnCheckQexitW)                   //~@@@@R~
	ON_BN_CLICKED(IDOK,OnOKW)                                      //~@@@@R~
	ON_BN_CLICKED(IDCANCEL,OnCancelW)                              //~@@@@R~
	MSG_WM_INITDIALOG(OnInitDialogW)                               //~@@@@I~
END_MESSAGE_MAP()                                                  //~@@@@I~
BEGIN_DDX_MAP(CWxedlg)                                             //~@@@@I~
    DDX_CONTROL_HANDLE  (IDC_CHECK_BEEP, Mcheckbeep);              //~@@@@R~
    DDX_CONTROL_HANDLE  (IDC_CHECK_QEXIT,Mcheckqexit);             //~@@@@R~
    DDX_CONTROL_HANDLE  (IDC_STATIC_CHARSET, Mcharsetgroup);       //~@@@@R~
    DDX_CONTROL_HANDLE  (IDC_COMBO_STYLE, Mcombostyle);            //~@@@@R~
    DDX_CONTROL_HANDLE  (IDC_COMBO_CHARSET, Mcombocharsetother);   //~@@@@R~
    DDX_CONTROL_HANDLE  (IDC_CHECK_FREECSR, Mcheckfreecsr);        //~@@@@R~
    DDX_CONTROL_HANDLE  (IDC_CHECK_RCTL, Mcheckrctl);              //~@@@@R~
    DDX_CONTROL_HANDLE  (IDC_CHECK_RULER, Mcheckruler);            //~@@@@R~
    DDX_CONTROL_HANDLE  (IDC_EDIT_RULERKEY, Meditrulerkey);        //~@@@@R~
    DDX_CONTROL_HANDLE  (IDC_SPIN_SCROLLTIMER, Mspinscrolltimer);  //~@@@@R~
    DDX_CONTROL_HANDLE  (IDC_EDIT_SCROLLTIMER, Meditscrolltimer);  //~@@@@R~
    DDX_CONTROL_HANDLE  (IDC_CHECK_USEMK, Mcheckusemk);            //~@@@@R~
    DDX_CONTROL_HANDLE  (IDC_CHECK_USEACT, Mcheckuseact);          //~@@@@R~
    DDX_CONTROL_HANDLE  (IDC_EDIT_OTHER, Meditother);              //~@@@@R~
    DDX_CONTROL_HANDLE  (IDC_SPIN_SCROLLCTR, Mspinscrollctr);      //~@@@@R~
    DDX_CONTROL_HANDLE  (IDC_EDIT_SCROLLCTR, Meditscrollctr);      //~@@@@R~
    DDX_CONTROL_HANDLE  (IDC_EDIT_WIDTH, Meditfontw);              //~@@@@R~
    DDX_CONTROL_HANDLE  (IDC_EDIT_HEIGHT, Meditfonth);             //~@@@@R~
    DDX_CONTROL_HANDLE  (IDC_EDIT_ROWH, Meditcellh);               //~@@@@R~
    DDX_CONTROL_HANDLE  (IDC_EDIT_COLW, Meditcellw);               //~@@@@R~
    DDX_CONTROL_HANDLE  (IDC_STATIC_FONTBOX, Mstaticfontbox);      //~@@@@R~
    DDX_CONTROL_HANDLE  (IDC_STATIC_COLORBOX, Mstaticcolordisplay);//~@@@@R~
    DDX_CONTROL_HANDLE  (IDC_CHECK_TTFONT, Mttcheckbox);           //~@@@@R~
    DDX_CONTROL_HANDLE  (IDC_CHECK_LIGATURE, Mligaturecheckbox);   //~@@@@R~
    DDX_CONTROL_HANDLE  (IDC_EDIT_GREEN, Medit_g);                 //~@@@@R~
    DDX_CONTROL_HANDLE  (IDC_EDIT_RED, Medit_r);                   //~@@@@R~
    DDX_CONTROL_HANDLE  (IDC_EDIT_BLUE, Medit_b);                  //~@@@@R~
    DDX_CONTROL_HANDLE  (IDC_SLIDER_RED, Mslider_r);               //~@@@@R~
    DDX_CONTROL_HANDLE  (IDC_SLIDER_GREEN, Mslider_g);             //~@@@@R~
    DDX_CONTROL_HANDLE  (IDC_SLIDER_BLUE, Mslider_b);              //~@@@@R~
    DDX_CONTROL_HANDLE  (IDC_SPIN_ROWH, Mspinrowheight);           //~@@@@R~
    DDX_CONTROL_HANDLE  (IDC_SPIN_COLW, Mspincolwidth);            //~@@@@R~
    DDX_CONTROL_HANDLE  (IDC_SPIN_WIDTH, Mspinfontsz_w);           //~@@@@R~
    DDX_CONTROL_HANDLE  (IDC_SPIN_HEIGHT, Mspinfontsz_h);          //~@@@@R~
//        DDX_TEXT   (IDC_EDIT_HEIGHT, Mfontsz_h);                 //~@@@@M~
    DDX_INT_RANGE(IDC_EDIT_HEIGHT,Mfontsz_h,FONTSZH_MIN,FONTSZH_MAX);//classview issue err when define value//~@@@@I~
//        DDX_TEXT   (IDC_EDIT_WIDTH, Mfontsz_w);                  //~@@@@M~
    DDX_INT_RANGE(IDC_EDIT_WIDTH,Mfontsz_w,FONTSZW_MIN,FONTSZW_MAX);//~@@@@I~
//        DDX_TEXT   (IDC_EDIT_COLW, Mcellw);                      //~@@@@M~
    DDX_INT_RANGE(IDC_EDIT_COLW,Mcellw,COLW_MIN,COLW_MAX);         //~@@@@I~
//        DDX_TEXT   (IDC_EDIT_ROWH, Mcellh);                      //~@@@@M~
    DDX_INT_RANGE(IDC_EDIT_ROWH,Mcellh,ROWH_MIN,ROWH_MAX);         //~@@@@I~
//        DDX_Slider(pDX, IDC_SLIDER_BLUE, Mbgcolor_b);            //~@@@@M~
    DDX_INT_RANGE(IDC_SLIDER_BLUE,Mbgcolor_b,  0,255);             //~@@@@I~
//        DDX_Slider(pDX, IDC_SLIDER_GREEN, Mbgcolor_g);           //~@@@@M~
    DDX_INT_RANGE(IDC_SLIDER_GREEN,Mbgcolor_g, 0,255);             //~@@@@I~
//        DDX_Slider(pDX, IDC_SLIDER_RED, Mbgcolor_r);             //~@@@@M~
    DDX_INT_RANGE(IDC_SLIDER_RED,Mbgcolor_r,   0,255);             //~@@@@I~
//        DDX_TEXT   (IDC_EDIT_SCROLLCTR, Mscrollctr);             //~@@@@M~
    DDX_INT_RANGE(IDC_EDIT_SCROLLCTR, Mscrollctr,SCROLL_MIN,SCROLL_MAX);//~@@@@I~
    DDX_CHECK    (IDC_CHECK_TTFONT, Mttfont);                      //~@@@@I~
    DDX_CHECK    (IDC_CHECK_LIGATURE, Mligature);                  //~@@@@I~
//        DDX_TEXT   (IDC_EDIT_OTHER, Mothercharset);              //~@@@@M~
    DDX_INT_RANGE(IDC_EDIT_OTHER,Mothercharset, 0, 65536);         //~@@@@R~
    DDX_CHECK    (IDC_CHECK_USEACT, Museact);                      //~@@@@I~
    DDX_CHECK    (IDC_CHECK_USEMK, Musemk);                        //~@@@@I~
//        DDX_TEXT   (IDC_EDIT_SCROLLTIMER, Mscrolltimer);         //~@@@@M~
    DDX_INT_RANGE(IDC_EDIT_SCROLLTIMER,Mscrolltimer, 1, 10);       //~@@@@R~
    DDX_CHECK    (IDC_CHECK_RCTL, Mrctl);                          //~@@@@I~
    DDX_CHECK    (IDC_CHECK_RULER, Mruler);                        //~@@@@I~
    DDX_CHECK    (IDC_CHECK_FREECSR, Mfreecsr);                    //~@@@@I~
    DDX_CHECK    (IDC_CHECK_BEEP, Mbeep);                          //~@@@@I~
    DDX_CHECK    (IDC_CHECK_QEXIT, Mqexit);                        //~@@@@I~
END_DDX_MAP()                                                      //~@@@@I~
};

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_WXEDLG_H__29FDC661_B1E6_11D6_8C9B_00909951ADD0__INCLUDED_)
