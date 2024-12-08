//*CID://+vbt1R~:                             update#=  251;       //+vbt1R~
//***********************************************************************//~3102I~
//vbt1:201210 WXE:when kbd changed to 2nd language DBCS chk should be changed//+vbt1I~
//vb2J:160313 (W32) compier warning                                //~vb2JI~
//va75:100806 (BUG:WXE)force eng to errmsg when charset changed on setupdialog//~va75I~
//va74:100806 (BUG:WXE)reset va6v; write by locale code to use font codepage on setupdialog//~va74I~
//                     currentrly l2uany use base locale           //~va74I~
//va6v:000626 (WXE)use textoutW for locale code (more printable for any font slected)//~va6vI~
//va43:100329 (WXE:BUG)setup disalog limit Other CP to 256;accept up to 65536,current max is 65001//~va43I~
//va3g:100207 try ligature for also wxe(write ucs string at once) for arabic etc//~va3gI~
//va0R:091006!(WXE)charset combo box                               //~va0RI~
//v740:070201 (WXE/XXE)kde dose not report keypress event for S+C+F1;so use keyup event//~v740I~
//            so support specify trigger key on setupdialog        //~v740I~
//v73y:070128-(WXE/XXE)Quiet-exit support                          //~v73yI~
//v73t:070125 cross-hair ruler support by Shift+Ctl+lbuton         //~v73tI~
//v738:070106 (WXE/XXE) print 0x80 etc for english mode sample font text//~v738I~
//v71A:061030 (WXE)Use HtmlHelp;Winhelp is deprecated at Vista;XP english ersion cannot read .hlp by the readson of codepage unsupported//~v71AI~
//v55G:040315 (WXE)Beep option on setup dialog                     //~v55GI~
//v55F:040314 (WXE)english help                                    //~v55FI~
//v55D:040309 (WXE)popup help for dialog control                   //~v55DI~
//v55q:040228 option to scroll by csr move(CSRSCROLL option)       //~v55qI~
//v55c:040208 (WXE)distingush L-CTL/R-CTL & report R-CTL           //~v55cI~
//v510:030215 (WXE)parameterize interval for scroll by mouse       //~v510I~
//030102:other carset support                                      //~3102R~
//***********************************************************************//~3102I~
// Wxedlg.cpp :                                                    //~v55GR~
//

#include "stdafx.h"
//#include "resource.hm"	//for html help                        //~v55DR~
//#include "htmlhelp.h"                                            //~v55DR~
                                                                   //~v740I~
#define NO_MACRO_REDIRECT                                          //~@@@@I~
#include    "ulib.h"                                               //~v740I~
#include    "utrace.h"                                             //~v740I~
                                                                   //~v740I~
#include "wxedef.h"                                                //~2817I~
#include "wxe.h"
#include "wxefile.h"                                               //~2817I~
#include "wxedoc.h"                                                //~2817I~
#include "Wxemain.h"                                               //~2831R~
#include "Wxedlg.h"                                                //~2831I~
#include "wxecsub.h"                                               //~2818I~
#include "wxexei.h"                                                //~v55cI~
#include "wxexei.h"                                                //~v55DI~
#include "wxehelp.h" //by help tool                                //~v55DR~
#include "wxehelps.h" //by help tool                               //~v71AI~

#ifdef _DEBUG
//#define new DEBUG_NEW                                            //~@@@@R~
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

static char *Sothercharset[]={                                     //~va0RR~
             "ARABIC  178",                                        //~va0RR~
             "BALTIC  186",                                        //~va0RR~
             "CHINESEBIG5  136",                                   //~va0RR~
             "EASTEUROPE  238",                                    //~va0RR~
             "GB2312  134",                                        //~va0RR~
             "GREEK  161",                                         //~va0RR~
             "HANGEUL  129",                                       //~va0RR~
             "HEBREW  177",                                        //~va0RR~
             "JOHAB  130",                                         //~va0RR~
             "OEM  255",                                           //~va0RR~
             "RUSSIAN  204",                                       //~va0RR~
             "THAI  222",                                          //~va0RR~
             "TURKISH  162",                                       //~va0RR~
             "VIETNAMESE  163",                                    //~va0RR~
             ""                                                    //~va0RI~
							};                                     //~va0RI~
//int CALLBACK effp(LOGFONT *Pelf,TEXTMETRIC *Pntm,DWORD Pft,LPARAM Plp);//~2817R~
//int (CALLBACK *effp)(const LOGFONT *Pelf,const TEXTMETRIC *Pntm,DWORD Pft,LPARAM Plp);//~2817R~
//	FONTENUMPROC effp;                                             //~2817R~
/////////////////////////////////////////////////////////////////////////////
// CWxedlg dialog                                                  //~v55GR~


CWxedlg::CWxedlg(CWnd* pParent,CWxemain *Ppwxemain)                //~2831R~
//    : CDialog(CWxedlg::IDD, pParent)                             //~@@@@R~
{
    char *pc;                                                      //~2818I~
//****************************                                     //~2818I~
	Mpparentwnd=pParent;                                           //~2817I~
	Mpwxemain=Ppwxemain;                                           //~2831R~
	//{{AFX_DATA_INIT(CWxedlg)
	Mfontsz_h=Mpwxemain->Mfontheight;                              //~2827R~
	Mfontsz_w=Mpwxemain->Mfontwidth;                               //~2827R~
	Mcellw=Mpwxemain->Mcellw;                                      //~2901R~
	Mcellh=Mpwxemain->Mcellh;                                      //~2901R~
	Mcharset=Mpwxemain->Mcharset;                                  //~2915I~
	Mbgcolor_b=RGB_GETBLUE(Mpwxemain->Mbgcolor);                   //~2907R~
	Mbgcolor_g=RGB_GETGREEN(Mpwxemain->Mbgcolor);                  //~2907R~
	Mbgcolor_r=RGB_GETRED(Mpwxemain->Mbgcolor);                    //~2907R~
	Mrulercolor_b=RGB_GETBLUE(Mpwxemain->Mrulercolor);             //~v73tI~
	Mrulercolor_g=RGB_GETGREEN(Mpwxemain->Mrulercolor);            //~v73tI~
	Mrulercolor_r=RGB_GETRED(Mpwxemain->Mrulercolor);              //~v73tI~
	Mscrollctr=Mpwxemain->Mscrollctr;                              //~2A13I~
	Mttfont = Mpwxemain->Mttfont;                                  //~2915R~
	Mligature= Mpwxemain->Mligature;                               //~va3gI~
	Mothercharset=Mpwxemain->Mothercharset;                        //~3102I~
	Museact = Mpwxemain->Museact;                                  //~3103M~
	Musemk  = Mpwxemain->Musemk ;                                  //~3105I~
	Mscrolltimer=Mpwxemain->Mscrolltimer/100;	//by 1/10sec unit  //~v510R~
	Mrctl   = wxe_getrctl();                                       //~v55cR~
	Mfreecsr= wxe_getfreecsr();                                    //~v55qR~
	Mbeep = wxe_getbeep();                                         //~v55GI~
	Mqexit= wxe_getqexit();                                        //~v73yI~
	pc=Mpwxemain->Mfontstyle;                                      //~2827R~
	pc=strncpy(Mfontstyle,pc,sizeof(Mfontstyle));                  //~2824R~
    Mpaintsw=0;                                                    //~2923I~
    Mpcombocs=0;	                                               //~va0RR~
//  Mrulerkeycstring = CString(Mpwxemain->Mrulerkey,sizeof(Mpwxemain->Mrulerkey));//~v740R~
	//}}AFX_DATA_INIT
}


//void CWxedlg::DoDataExchange(CDataExchange* pDX)                 //~@@@@R~
//{                                                                //~@@@@R~
//    CDialog::DoDataExchange(pDX);                                //~@@@@R~
//    //{{AFX_DATA_MAP(CWxedlg)                                    //~@@@@R~
//    DDX_Control(pDX, IDC_CHECK_BEEP, Mcheckbeep);                //~@@@@R~
//    DDX_Control(pDX, IDC_CHECK_QEXIT,Mcheckqexit);                 //~v73yI~//~@@@@R~
//    DDX_Control(pDX, IDC_STATIC_CHARSET, Mcharsetgroup);         //~@@@@R~
//    DDX_Control(pDX, IDC_COMBO_STYLE, Mcombostyle);              //~@@@@R~
//    DDX_Control(pDX, IDC_COMBO_CHARSET, Mcombocharsetother);       //~va0RI~//~@@@@R~
//    DDX_Control(pDX, IDC_CHECK_FREECSR, Mcheckfreecsr);          //~@@@@R~
//    DDX_Control(pDX, IDC_CHECK_RCTL, Mcheckrctl);                //~@@@@R~
//    DDX_Control(pDX, IDC_CHECK_RULER, Mcheckruler);                //~v73tI~//~@@@@R~
//    DDX_Control(pDX, IDC_EDIT_RULERKEY, Meditrulerkey);            //~v740I~//~@@@@R~
//    DDX_Control(pDX, IDC_SPIN_SCROLLTIMER, Mspinscrolltimer);      //~v510R~//~@@@@R~
//    DDX_Control(pDX, IDC_EDIT_SCROLLTIMER, Meditscrolltimer);    //~@@@@R~
//    DDX_Control(pDX, IDC_CHECK_USEMK, Mcheckusemk);              //~@@@@R~
//    DDX_Control(pDX, IDC_CHECK_USEACT, Mcheckuseact);              //~3103R~//~@@@@R~
//    DDX_Control(pDX, IDC_EDIT_OTHER, Meditother);                //~@@@@R~
//    DDX_Control(pDX, IDC_SPIN_SCROLLCTR, Mspinscrollctr);        //~@@@@R~
//    DDX_Control(pDX, IDC_EDIT_SCROLLCTR, Meditscrollctr);        //~@@@@R~
//    DDX_Control(pDX, IDC_EDIT_WIDTH, Meditfontw);                //~@@@@R~
//    DDX_Control(pDX, IDC_EDIT_HEIGHT, Meditfonth);               //~@@@@R~
//    DDX_Control(pDX, IDC_EDIT_ROWH, Meditcellh);                 //~@@@@R~
//    DDX_Control(pDX, IDC_EDIT_COLW, Meditcellw);                 //~@@@@R~
//    DDX_Control(pDX, IDC_STATIC_FONTBOX, Mstaticfontbox);        //~@@@@R~
//    DDX_Control(pDX, IDC_STATIC_COLORBOX, Mstaticcolordisplay);  //~@@@@R~
//    DDX_Control(pDX, IDC_CHECK_TTFONT, Mttcheckbox);             //~@@@@R~
//    DDX_Control(pDX, IDC_CHECK_LIGATURE, Mligaturecheckbox);       //~va3gI~//~@@@@R~
//    DDX_Control(pDX, IDC_EDIT_GREEN, Medit_g);                     //~2907R~//~@@@@R~
//    DDX_Control(pDX, IDC_EDIT_RED, Medit_r);                       //~2907R~//~@@@@R~
//    DDX_Control(pDX, IDC_EDIT_BLUE, Medit_b);                      //~2907R~//~@@@@R~
//    DDX_Control(pDX, IDC_SLIDER_RED, Mslider_r);                   //~2907R~//~@@@@R~
//    DDX_Control(pDX, IDC_SLIDER_GREEN, Mslider_g);                 //~2907R~//~@@@@R~
//    DDX_Control(pDX, IDC_SLIDER_BLUE, Mslider_b);                  //~2907R~//~@@@@R~
//    DDX_Control(pDX, IDC_SPIN_ROWH, Mspinrowheight);             //~@@@@R~
//    DDX_Control(pDX, IDC_SPIN_COLW, Mspincolwidth);              //~@@@@R~
//    DDX_Control(pDX, IDC_SPIN_WIDTH, Mspinfontsz_w);             //~@@@@R~
//    DDX_Control(pDX, IDC_SPIN_HEIGHT, Mspinfontsz_h);            //~@@@@R~
//    DDX_Text(pDX, IDC_EDIT_HEIGHT, Mfontsz_h);                   //~@@@@R~
//    DDV_MinMaxInt(pDX, Mfontsz_h,FONTSZH_MIN,FONTSZH_MAX);//classview issue err when define value//~2928R~//~@@@@R~
//    DDX_Text(pDX, IDC_EDIT_WIDTH, Mfontsz_w);                    //~@@@@R~
//    DDV_MinMaxInt(pDX, Mfontsz_w,FONTSZW_MIN,FONTSZW_MAX);         //~2928R~//~@@@@R~
//    DDX_Text(pDX, IDC_EDIT_COLW, Mcellw);                          //~2901R~//~@@@@R~
//    DDV_MinMaxInt(pDX, Mcellw,COLW_MIN,COLW_MAX);                  //~2928R~//~@@@@R~
//    DDX_Text(pDX, IDC_EDIT_ROWH, Mcellh);                          //~2901R~//~@@@@R~
//    DDV_MinMaxInt(pDX, Mcellh,ROWH_MIN,ROWH_MAX);                  //~2928R~//~@@@@R~
//    DDX_Slider(pDX, IDC_SLIDER_BLUE, Mbgcolor_b);                  //~2907R~//~@@@@R~
//    DDV_MinMaxInt(pDX, Mbgcolor_b,  0,255);                        //~2907R~//~@@@@R~
//    DDX_Slider(pDX, IDC_SLIDER_GREEN, Mbgcolor_g);                 //~2907R~//~@@@@R~
//    DDV_MinMaxInt(pDX, Mbgcolor_g, 0,255);                         //~2907R~//~@@@@R~
//    DDX_Slider(pDX, IDC_SLIDER_RED, Mbgcolor_r);                   //~2907R~//~@@@@R~
//    DDV_MinMaxInt(pDX, Mbgcolor_r,   0,255);                       //~2907R~//~@@@@R~
//    DDX_Text(pDX, IDC_EDIT_SCROLLCTR, Mscrollctr);                 //~2A13M~//~@@@@R~
//    DDV_MinMaxInt(pDX, Mscrollctr,SCROLL_MIN,SCROLL_MAX);          //~2A13I~//~@@@@R~
//    DDX_Check(pDX, IDC_CHECK_TTFONT, Mttfont);                   //~@@@@R~
//    DDX_Check(pDX, IDC_CHECK_LIGATURE, Mligature);                 //~va3gI~//~@@@@R~
//    DDX_Text(pDX, IDC_EDIT_OTHER, Mothercharset);                //~@@@@R~
////  DDV_MinMaxUInt(pDX, Mothercharset, 0, 255);                    //~va43R~//~@@@@R~
//    DDV_MinMaxUInt(pDX, Mothercharset, 0, 65536);                  //~va3gI~//~@@@@R~
//    DDX_Check(pDX, IDC_CHECK_USEACT, Museact);                     //~3103I~//~@@@@R~
//    DDX_Check(pDX, IDC_CHECK_USEMK, Musemk);                     //~@@@@R~
//    DDX_Text(pDX, IDC_EDIT_SCROLLTIMER, Mscrolltimer);             //~v510R~//~@@@@R~
//    DDV_MinMaxInt(pDX, Mscrolltimer, 1, 10);                       //~v510R~//~@@@@R~
//    DDX_Check(pDX, IDC_CHECK_RCTL, Mrctl);                       //~@@@@R~
//    DDX_Check(pDX, IDC_CHECK_RULER, Mruler);                       //~v73tI~//~@@@@R~
//    DDX_Check(pDX, IDC_CHECK_FREECSR, Mfreecsr);                 //~@@@@R~
//    DDX_Check(pDX, IDC_CHECK_BEEP, Mbeep);                       //~@@@@R~
//    DDX_Check(pDX, IDC_CHECK_QEXIT, Mqexit);                       //~v73yI~//~@@@@R~
////  DDX_Text(pDX, IDC_EDIT_RULERKEY, Mrulerkeycstring);            //~v740R~//~@@@@R~
//    //}}AFX_DATA_MAP                                             //~@@@@R~
//}                                                                //~@@@@R~


//BEGIN_MESSAGE_MAP(CWxedlg, CDialog)                              //~@@@@R~
//    //{{AFX_MSG_MAP(CWxedlg)                                     //~@@@@R~
//    ON_CBN_SELCHANGE(IDC_COMBO_STYLE, OnSelchangeComboStyle)     //~@@@@R~
//    ON_CBN_SELCHANGE(IDC_COMBO_CHARSET, OnSelchangeComboCharset) //~@@@@R~
//    ON_WM_HSCROLL()                                              //~@@@@R~
//    ON_WM_PAINT()                                                //~@@@@R~
//    ON_EN_CHANGE(IDC_EDIT_HEIGHT, OnChangeEditHeight)            //~@@@@R~
//    ON_EN_CHANGE(IDC_EDIT_COLW, OnChangeEditColw)                //~@@@@R~
//    ON_EN_CHANGE(IDC_EDIT_ROWH, OnChangeEditRowh)                //~@@@@R~
//    ON_EN_CHANGE(IDC_EDIT_WIDTH, OnChangeEditWidth)              //~@@@@R~
//    ON_BN_CLICKED(IDC_CHECK_TTFONT, OnCheckTtfont)               //~@@@@R~
//    ON_BN_CLICKED(IDC_CHECK_LIGATURE, OnCheckLigature)           //~@@@@R~
//    ON_BN_CLICKED(IDC_RADIO_ANSI, OnRadioAnsi)                   //~@@@@R~
//    ON_BN_CLICKED(IDC_RADIO_DEFAULT, OnRadioDefault)             //~@@@@R~
//    ON_BN_CLICKED(IDC_RADIO_SJIS, OnRadioSjis)                   //~@@@@R~
//    ON_BN_CLICKED(IDC_RADIO_OTHER, OnRadioOther)                 //~@@@@R~
//    ON_EN_CHANGE(IDC_EDIT_OTHER, OnChangeEditOther)              //~@@@@R~
//    ON_EN_CHANGE(IDC_EDIT_RULERKEY,OnChangeEditRulerkey)         //~@@@@R~
//    ON_BN_CLICKED(IDC_CHECK_RCTL, OnCheckRctl)                   //~@@@@R~
//    ON_BN_CLICKED(IDC_CHECK_RULER, OnCheckRuler)                 //~@@@@R~
//    ON_BN_CLICKED(IDC_CHECK_FREECSR, OnCheckFreecsr)             //~@@@@R~
//    ON_WM_CONTEXTMENU()                                          //~@@@@R~
//    ON_WM_HELPINFO()                                             //~@@@@R~
//    ON_BN_CLICKED(IDC_CHECK_BEEP, OnCheckBeep)                   //~@@@@R~
//    ON_BN_CLICKED(IDC_CHECK_QEXIT,OnCheckQexit)                  //~@@@@R~
//    //}}AFX_MSG_MAP                                              //~@@@@R~
//END_MESSAGE_MAP()                                                //~@@@@R~

/////////////////////////////////////////////////////////////////////////////

void CWxedlg::OnOK() 
{
    char txt[80];                                                  //~2817M~
    CButton *prb;                                                  //~2915I~
//**********************                                           //~2817M~
    if (setrulerkey(0))                                            //~v740I~
    	return;                                                    //~v740I~
//  ((CEdit*)GetDlgItem(IDC_EDIT_WIDTH))->GetWindowText(txt,sizeof(txt));//~2817I~//~@@@@R~
    (new CEdit(GetDlgItem(IDC_EDIT_WIDTH)))->GetWindowText(txt,sizeof(txt));//~@@@@I~
    Mfontsz_w=atoi(txt);                                           //~2817R~
//  ((CEdit*)GetDlgItem(IDC_EDIT_HEIGHT))->GetWindowText(txt,sizeof(txt));//~2817I~//~@@@@R~
    (new CEdit(GetDlgItem(IDC_EDIT_HEIGHT)))->GetWindowText(txt,sizeof(txt));//~@@@@I~
    Mfontsz_h=atoi(txt);                                           //~2817R~
//  ((CEdit*)GetDlgItem(IDC_EDIT_COLW))->GetWindowText(txt,sizeof(txt));//~2818I~//~@@@@R~
    (new CEdit(GetDlgItem(IDC_EDIT_COLW)))->GetWindowText(txt,sizeof(txt));//~@@@@I~
    Mcellw=atoi(txt);                                              //~2901R~
//  ((CEdit*)GetDlgItem(IDC_EDIT_ROWH))->GetWindowText(txt,sizeof(txt));//~2818I~//~@@@@R~
    (new CEdit(GetDlgItem(IDC_EDIT_ROWH)))->GetWindowText(txt,sizeof(txt));//~@@@@I~
    Mcellh=atoi(txt);                                              //~2901R~
    Mpwxemain->Mfontwidth=Mfontsz_w;                               //~2C14R~
    Mpwxemain->Mfontheight=Mfontsz_h;                              //~2827R~
    Mpwxemain->Mcellw=Mcellw;                                      //~2901R~
    Mpwxemain->Mcellh=Mcellh;                                      //~2901R~
    Mpwxemain->Mrulercolor=RGB_MAKE(Mrulercolor_r,Mrulercolor_g,Mrulercolor_b);//~v73tI~
    Mpwxemain->scrpeninit(0);	//re initialize pen                //~v73tR~
//  Mbgcolor_r=Mslider_r.GetPos();                                 //~v73tR~
//  Mbgcolor_g=Mslider_g.GetPos();                                 //~v73tR~
//  Mbgcolor_b=Mslider_b.GetPos();                                 //~v73tR~
    Mpwxemain->Mbgcolor=RGB_MAKE(Mbgcolor_r,Mbgcolor_g,Mbgcolor_b);//~2907R~
    strncpy(Mpwxemain->Mfontstyle,Mfontstyle,sizeof(Mpwxemain->Mfontstyle));//~2827R~
                                                                   //~2915I~
//  prb=(CButton*)GetDlgItem(IDC_RADIO_DEFAULT);                   //~2915I~//~@@@@R~
    prb=new CButton(GetDlgItem(IDC_RADIO_DEFAULT));                //~@@@@I~
    if (prb->GetCheck())                                           //~2915I~
	    Mcharset=DEFAULT_CHARSET;                                  //~2915R~
//  prb=(CButton*)GetDlgItem(IDC_RADIO_ANSI);                      //~2915R~//~@@@@R~
    prb=new CButton(GetDlgItem(IDC_RADIO_ANSI));                   //~@@@@I~
    if (prb->GetCheck())                                           //~2915I~
	    Mcharset=ANSI_CHARSET;                                     //~2915R~
//  prb=(CButton*)GetDlgItem(IDC_RADIO_SJIS);                      //~2915I~//~@@@@R~
    prb=new CButton(GetDlgItem(IDC_RADIO_SJIS));                   //~@@@@I~
    if (prb->GetCheck())                                           //~2915I~
	    Mcharset=SHIFTJIS_CHARSET;                                 //~2915R~
//  prb=(CButton*)GetDlgItem(IDC_RADIO_OTHER);                     //~3102I~//~@@@@R~
    prb=new CButton(GetDlgItem(IDC_RADIO_OTHER));                  //~@@@@I~
    if (prb->GetCheck())                                           //~3102R~
    {                                                              //~3102I~
    	Meditother.GetWindowText(txt,sizeof(txt));                 //~3102R~
    	Mcharset=Mothercharset=atoi(txt);                          //~3102R~
    }                                                              //~3102I~
    Mpwxemain->Mcharset=Mcharset;                                  //~2915M~
    Mpwxemain->Mothercharset=Mothercharset;                        //~3102I~
    UTRACEP("CREATEFONT dlg charset=%d\n",Mpwxemain->Mcharset);    //~va75I~
//truetype font option                                             //~2915I~
//  prb=(CButton*)GetDlgItem(IDC_CHECK_TTFONT);                    //~2915I~//~@@@@R~
    prb=new CButton(GetDlgItem(IDC_CHECK_TTFONT));                 //~@@@@I~
    Mttfont=prb->GetCheck();                                       //~2915I~
	Mpwxemain->Mttfont=Mttfont;                                    //~2915I~
//Ligature option                                                  //~va3gI~
//  prb=(CButton*)GetDlgItem(IDC_CHECK_LIGATURE);                  //~va3gI~//~@@@@R~
    prb=new CButton(GetDlgItem(IDC_CHECK_LIGATURE));               //~@@@@I~
    Mligature=prb->GetCheck();                                     //~va3gI~
	Mpwxemain->Mligature=Mligature;                                //~va3gI~
//accelerator                                                      //~3103I~
    Museact=Mcheckuseact.GetCheck();                               //~3103I~
	Mpwxemain->Museact=Museact;                                    //~3103R~
//menukey usage                                                    //~3105I~
    Musemk =Mcheckusemk.GetCheck();                                //~3105I~
	Mpwxemain->Musemk =Musemk ;                                    //~3105I~
//rctl key useage                                                  //~v55cI~
    Mrctl  =Mcheckrctl.GetCheck();                                 //~v55cI~
	Mpwxemain->Mrctl  =Mrctl  ;                                    //~v55cI~
//freecsr mode                                                     //~v55qR~
    Mfreecsr=Mcheckfreecsr.GetCheck();                             //~v55qR~
	Mpwxemain->Mfreecsr=Mfreecsr;                                  //~v55qR~
//beep  r mode                                                     //~v55GI~
    Mbeep   =Mcheckbeep.GetCheck();                                //~v55GI~
	Mpwxemain->Mbeep=Mbeep;                                        //~v55GI~
    Mqexit  =Mcheckqexit.GetCheck();                               //~v73yI~
                                                                   //~3103I~
//  ((CEdit*)GetDlgItem(IDC_EDIT_SCROLLCTR))->GetWindowText(txt,sizeof(txt));//~2A13I~//~@@@@R~
    (new CEdit(GetDlgItem(IDC_EDIT_SCROLLCTR)))->GetWindowText(txt,sizeof(txt));//~@@@@I~
    Mscrollctr=atoi(txt);                                          //~2A13I~
	Mpwxemain->Mscrollctr=Mscrollctr;                              //~2A13I~
    Meditscrolltimer.GetWindowText(txt,sizeof(txt));               //~v510I~
    Mscrolltimer=atoi(txt);                                        //~v510R~
	Mpwxemain->Mscrolltimer=Mscrolltimer*100;	//by ms            //~v510R~
                                                                   //~2915I~
//  wxe_setcharset(0/*initsw*/,Mcharset); wxxemain:onOK will be called                     //~va75R~//+vbt1R~
                                                                   //~2915I~
    Mpparentwnd->SendMessage(WM_COMMAND,IDOK);                     //~2817R~
    wxe_setqexit(Mqexit);                                          //~v73yI~
	
//    CDialog::OnOK();                                             //~@@@@R~
}

void CWxedlg::OnCancel() 
{
	
//    CDialog::OnCancel();                                         //~@@@@R~
}

//BOOL CWxedlg::Create()    //derived member could not be used                                         //~2817R~//~@@@@R~
//{                                                                //~@@@@R~
//    int rc=CDialog::Create(IDD_SETUP, Mpparentwnd);                //~2B03R~//~@@@@R~
//    return rc;                                                     //~2817I~//~@@@@R~
//}                                                                //~@@@@R~
//**************************************************************** //~2817I~
//*                                                                //~2817I~
//**************************************************************** //~2817I~
BOOL CWxedlg::Initcombo()                                          //~2817I~
{                                                                  //~2817I~
//    LOGFONT elftbl[MAXELF];                                      //~v510R~
//    int ii;                                                      //~v510R~
//    char *pc;                                                    //~v510R~
//    HDC hdc;                                                     //~v510R~
//********************************                                 //~2817I~
//    hdc=Mpwxemain->Mpmemdc->m_hDC;                               //~v510R~
//    Mfontstylectr=enumfont(hdc,elftbl,MAXELF);                   //~v510R~
//    for (ii=0;ii<Mfontstylectr;ii++)                             //~v510R~
//    {                                                            //~v510R~
//        pc=(char *)(elftbl[ii].lfFaceName);                      //~v510R~
//        Mpcombofs->AddString(pc);                                //~v510R~
//    }                                                            //~v510R~
//    Mpcombofs->SelectString(-1,Mfontstyle);                      //~v510R~
	Mfontstylectr=Mpwxemain->createfontlist(Mpcombofs,Mfontstyle); //~v510R~
	Invalidate(FALSE);                                             //~2923I~
    return 0;                                                      //~2817I~
}                                                                  //~2817I~
//**************************************************************** //~va0RI~
//*add entry to other charset combo box                            //~va0RI~
//**************************************************************** //~va0RI~
BOOL CWxedlg::Initcomboothercharset()                              //~va0RI~
{                                                                  //~va0RI~
    char **ppc,*pc,*pc2,*pc3=0;                                    //~va0RI~
    int csno;                                                      //~va0RI~
//********************************                                 //~va0RI~
	for (ppc=Sothercharset;pc=*ppc,*pc;ppc++)                      //~va0RI~
    {                                                              //~va0RI~
    	pc2=strchr(pc,' ');                                        //~va0RI~
        if (pc2)                                                   //~va0RI~
        {                                                          //~va0RI~
        	pc2+=strspn(pc2," ");                                  //~va0RI~
            csno=atoi(pc2);                                        //~va0RI~
            if (csno==Mothercharset)  //match charsetno width other_edit textbox//~va0RI~
            	pc3=pc;                                            //~va0RI~
        }                                                          //~va0RI~
	    Mpcombocs->AddString(pc);                                  //~va0RI~
    }                                                              //~va0RI~
    if (pc3)                                                       //~va0RI~
		Mpcombocs->SelectString(-1/*search all entry*/,pc3);	//set to edit area//~va0RI~
    return 0;                                                      //~va0RI~
}//Initcomboothercharset                                           //~va0RI~
//**************************************************************** //~va0RI~
//*                                                                //~va0RI~
//**************************************************************** //~va0RI~
void CWxedlg::setselectothercharset(char *Peditother)	//other charset combo box selected entry update//~va0RR~
{                                                                  //~va0RI~
    char **ppc,*pc,*pc2,*pc3=0;                                    //~va0RR~
//********************************                                 //~va0RI~
	if (!Mpcombocs)                                                //~va0RI~
    	return;                                                    //~va0RI~
	for (ppc=Sothercharset;pc=*ppc,*pc;ppc++)                      //~va0RI~
    {                                                              //~va0RI~
    	pc2=strchr(pc,' ');                                        //~va0RI~
        if (pc2)                                                   //~va0RI~
        {                                                          //~va0RI~
        	pc2+=strspn(pc2," ");                                  //~va0RI~
            if (!strcmp(pc2,Peditother))  //match charsetno width other_edit textbox//~va0RR~
            {                                                      //~va0RI~
            	pc3=pc;                                            //~va0RI~
                break;                                             //~va0RI~
            }                                                      //~va0RI~
        }                                                          //~va0RI~
    }                                                              //~va0RI~
    if (pc3)                                                       //~va0RI~
		Mpcombocs->SelectString(-1/*search all entry*/,pc3);	//set to edit area//~va0RR~
    else                                                           //~va0RI~
		Mpcombocs->Clear();                                        //~va0RI~
}//setselectothercharset                                           //~va0RI~
//**************************************************************** //~2817I~
//*                                                                //~2817I~
//**************************************************************** //~2817I~

BOOL CWxedlg::OnInitDialog() 
{
    BOOL enable;                                                   //~3102I~
    UINT rbid;                                                     //~3102I~
    CButton *prb;                                                  //~3102I~
	char wkedit[8];                                                //~2907I~
//************************                                         //~2907I~
//    CDialog::OnInitDialog();                                     //~@@@@R~
	DoDataExchange(FALSE);	//set handle to Mxx object             //~@@@@I~
	
    Mspinfontsz_h.SetRange(FONTSZH_MIN,FONTSZH_MAX);               //~2817M~
    Mspinfontsz_h.SetBuddy(GetDlgItem(IDC_EDIT_HEIGHT));           //~2817M~
    Mspinfontsz_w.SetRange(FONTSZW_MIN,FONTSZW_MAX);               //~2817M~
    Mspinfontsz_w.SetBuddy(GetDlgItem(IDC_EDIT_WIDTH));            //~2817M~
                                                                   //~2915I~
    Mspinrowheight.SetRange(ROWH_MIN,ROWH_MAX);                    //~2915M~
    Mspinrowheight.SetBuddy(GetDlgItem(IDC_EDIT_ROWH));            //~2915M~
    Mspincolwidth.SetRange(COLW_MIN,COLW_MAX);                     //~2915M~
    Mspincolwidth.SetBuddy(GetDlgItem(IDC_EDIT_COLW));             //~2915M~
                                                                   //~2A13I~
    Mspinscrollctr.SetRange(SCROLL_MIN,SCROLL_MAX);                //~2A13I~
    Mspinscrollctr.SetBuddy(GetDlgItem(IDC_EDIT_SCROLLCTR));       //~2A13I~
    Mspinscrolltimer.SetRange(1,10);                               //~v510I~
    Mspinscrolltimer.SetBuddy(GetDlgItem(IDC_EDIT_SCROLLTIMER));   //~v510I~
                                                                   //~2915M~
                                                                   //~2905I~
//  Mslider_r.GetRange(Mbgcolor_g,Mbgcolor_b);                     //~2907R~
    Mslider_r.SetRange(0,255,TRUE);                                //~2915R~
    Mslider_r.SetPos(Mbgcolor_r);                                  //~2907R~
    Mslider_g.SetRange(0,255,TRUE);                                //~2915R~
    Mslider_g.SetPos(Mbgcolor_g);                                  //~2907R~
    Mslider_b.SetRange(0,255,TRUE);                                //~2915R~
    Mslider_b.SetPos(Mbgcolor_b);                                  //~2907R~
    sprintf(wkedit,"% 3d",Mbgcolor_r);                             //~2907I~
    Medit_r.SetWindowText(wkedit);                                 //~2907I~
    sprintf(wkedit,"% 3d",Mbgcolor_g);                             //~2907I~
    Medit_g.SetWindowText(wkedit);                                 //~2907I~
    sprintf(wkedit,"% 3d",Mbgcolor_b);                             //~2907I~
    Medit_b.SetWindowText(wkedit);                                 //~2907I~
//charset radio button                                             //~2915I~
    enable=FALSE;                                                  //~3102I~
    switch(Mcharset)                                               //~3102I~
    {                                                              //~3102I~
    case DEFAULT_CHARSET:                                          //~3102I~
        rbid=IDC_RADIO_DEFAULT;                                    //~3102I~
        break;                                                     //~3102I~
    case ANSI_CHARSET:                                             //~3102I~
        rbid=IDC_RADIO_ANSI;                                       //~3102I~
        break;                                                     //~3102I~
    case SHIFTJIS_CHARSET:                                         //~3102I~
        rbid=IDC_RADIO_SJIS;                                       //~3102I~
        break;                                                     //~3102I~
    default:                                                       //~3102I~
        rbid=IDC_RADIO_OTHER;                                      //~3102I~
        enable=TRUE;                                               //~3102I~
    }                                                              //~3102I~
//  prb=(CButton*)GetDlgItem(rbid);                                //~3102I~//~@@@@R~
    prb=new CButton(GetDlgItem(rbid));                                          //~@@@@I~
    prb->SetCheck(TRUE);                                           //~3102I~
                                                                   //~3102I~
    sprintf(wkedit,"%d",Mothercharset);                            //~3102I~
    Meditother.SetWindowText(wkedit);	//filename                 //~3102I~
	Meditother.EnableWindow(enable);                               //~3102I~
	Mcombocharsetother.EnableWindow(enable);                       //~va0RI~
    setrulerkey(1);                                                //~v740R~
                                                                   //~3102I~
//  Mstaticcolordisplay.GetRect(&Mcolorbox_rect);                  //~2928R~
    Mstaticcolordisplay.GetClientRect(&Mcolorbox_rect);            //~2928R~
    Mstaticfontbox.GetClientRect(&Mfontbox_rect);                  //~2928I~
//font style                                                       //~2915R~
//  Mpcombofs=(CComboBox*)GetDlgItem(IDC_COMBO_STYLE);             //~2818R~//~@@@@R~
    Mpcombofs=new CComboBox(GetDlgItem(IDC_COMBO_STYLE));          //~@@@@I~
//Other Charset                                                    //~va0RI~
//  Mpcombocs=(CComboBox*)GetDlgItem(IDC_COMBO_CHARSET);           //~va0RI~//~@@@@R~
    Mpcombocs=new CComboBox(GetDlgItem(IDC_COMBO_CHARSET));        //~@@@@I~
    Initcombo();                                                   //~2817M~
    Initcomboothercharset();                                       //~va0RI~
	
                                                                   //~2923I~
	return TRUE;  // if not set focaus to the ctl return TRUE      //~v55GR~
	              // if OCX property page return FALSE             //~v55GR~
}

void CWxedlg::OnSelchangeComboStyle() 
{
//  Mpcombofs=(CComboBox*)GetDlgItem(IDC_COMBO_STYLE);             //~2818R~//~@@@@R~
    Mpcombofs=new CComboBox(GetDlgItem(IDC_COMBO_STYLE));          //~@@@@I~
    Mpcombofs->GetLBText(Mpcombofs->GetCurSel(),Mfontstyle);       //~2818R~
    displayfont();                                                 //~2928I~
}
void CWxedlg::OnSelchangeComboCharset()                            //~va0RI~
{                                                                  //~va0RI~
	char  *pc,selectedcharset[80];                                 //~va0RI~
//******************************                                   //~va0RI~
//  Mpcombocs=(CComboBox*)GetDlgItem(IDC_COMBO_CHARSET);           //~va0RI~//~@@@@R~
    Mpcombocs=new CComboBox(GetDlgItem(IDC_COMBO_CHARSET));        //~@@@@I~
    Mpcombocs->GetLBText(Mpcombocs->GetCurSel(),selectedcharset);  //~va0RI~
    pc=strchr(selectedcharset,' ');                                //~va0RI~
    if (pc)                                                        //~va0RI~
    {                                                              //~va0RI~
    	pc+=strspn(pc," ");                                        //~va0RI~
    	Meditother.SetWindowText(pc);                              //~va0RR~
		OnRadioOther();                                            //~va0RR~
    }                                                              //~va0RI~
}                                                                  //~va0RI~

void CWxedlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	char wkedit[8];                                                //~2907I~
//************************                                         //~2907I~
//  if (pScrollBar==(CScrollBar *)&Mslider_r)                      //~2907I~//~@@@@R~
    if ((HWND)(*pScrollBar)==(HWND)Mslider_r)                      //~@@@@R~
    {                                                              //~2907I~
      if (Mruler)                                                  //~v73tI~
      {                                                            //~v73tI~
		Mrulercolor_r=Mslider_r.GetPos();                          //~v73tI~
    	sprintf(wkedit,"% 3d",Mrulercolor_r);                      //~v73tI~
      }                                                            //~v73tI~
      else                                                         //~v73tI~
      {                                                            //~v73tI~
		Mbgcolor_r=Mslider_r.GetPos();                             //~2907I~
    	sprintf(wkedit,"% 3d",Mbgcolor_r);                         //~2907I~
      }                                                            //~v73tI~
    	Medit_r.SetWindowText(wkedit);                             //~2907I~
    }                                                              //~2907I~
    else                                                           //~2907I~
//  if (pScrollBar==(CScrollBar *)&Mslider_g)                      //~2907I~//~@@@@R~
    if ((HWND)(*pScrollBar)==(HWND)Mslider_g)                      //~@@@@R~
    {                                                              //~2907I~
      if (Mruler)                                                  //~v73tI~
      {                                                            //~v73tI~
		Mrulercolor_g=Mslider_g.GetPos();                          //~v73tI~
    	sprintf(wkedit,"% 3d",Mrulercolor_g);                      //~v73tI~
      }                                                            //~v73tI~
      else                                                         //~v73tI~
      {                                                            //~v73tI~
		Mbgcolor_g=Mslider_g.GetPos();                             //~2907I~
    	sprintf(wkedit,"% 3d",Mbgcolor_g);                         //~2907I~
      }                                                            //~v73tI~
    	Medit_g.SetWindowText(wkedit);                             //~2907I~
    }                                                              //~2907I~
    else                                                           //~2907I~
//  if (pScrollBar==(CScrollBar *)&Mslider_b)                      //~2907R~//~@@@@R~
    if ((HWND)(*pScrollBar)==(HWND)Mslider_b)                      //~@@@@R~
    {                                                              //~2907I~
      if (Mruler)                                                  //~v73tI~
      {                                                            //~v73tI~
		Mrulercolor_b =Mslider_b.GetPos();                         //~v73tI~
    	sprintf(wkedit,"% 3d",Mrulercolor_b);                      //~v73tI~
      }                                                            //~v73tI~
      else                                                         //~v73tI~
      {                                                            //~v73tI~
		Mbgcolor_b =Mslider_b.GetPos();                            //~2907I~
    	sprintf(wkedit,"% 3d",Mbgcolor_b);                         //~2907I~
      }                                                            //~v73tI~
	    Medit_b.SetWindowText(wkedit);                             //~2907I~
    }                                                              //~2907I~
	displaycolor();                                                //~2923I~
//    CDialog::OnHScroll(nSBCode, nPos, pScrollBar);               //~@@@@R~
}//OnHScroll                                                       //~2923R~
//**************************************************************** //~2923I~
//*                                                                //~2923I~
//**************************************************************** //~2923I~
void CWxedlg::displaycolor(void)                                   //~2923I~
{                                                                  //~2923I~
	COLORREF bg;                                                   //~2923R~
	COLORREF rulercolor;                                           //~v73tI~
	COLORREF fgw=RGB(255,255,255);     //white                     //~2923R~
	COLORREF fgb=RGB(0,0,0);    //black                            //~2923I~
    char *ptxt1=" Bg ";                                            //~2923I~
    char *ptxt2="Color";                                           //~2923R~
    SIZE  sz;                                                      //~2923R~
    int xx,yy;                                                     //~2928I~
    CPen penn;                                                     //~v73tI~
    CPoint pt[2];                                                  //~v73tI~
//************************                                         //~2923I~
    bg=RGB_MAKE(Mbgcolor_r,Mbgcolor_g,Mbgcolor_b);                 //~2928M~
    rulercolor=RGB_MAKE(Mrulercolor_r,Mrulercolor_g,Mrulercolor_b);//~v73tR~
//#define TEST1                                                    //~2928R~
#ifdef TEST1                                                       //~2928I~
    CClientDC dc(this);                                            //~2928R~
    dc.SetTextColor(fgw);                                          //~2928R~
    dc.SetBkColor(bg);                                             //~2928R~
    dc.TextOut(35,128,ptxt1,strlen(ptxt1));                        //~2928R~
//    CDC *pmemdc=new CDC();                                       //~2923I~
//    pmemdc->CreateCompatibleDC(&dc);                             //~2923I~
//    CBrush  br(RGB_MAKE(Mbgcolor_r,Mbgcolor_g,Mbgcolor_b));      //~2923I~
//    pmemdc->FillRect(&Mcolorbox_rect,&br);                       //~2928R~
//    dc.BitBlt(Mcolorbox_rect.left,Mcolorbox_rect.top,            //~2928R~
//                    Mcolorbox_rect.right-Mcolorbox_rect.left,    //~2928R~
//                    Mcolorbox_rect.bottom-Mcolorbox_rect.top,    //~2928R~
//                    pmemdc,0,0,SRCCOPY);                         //~2923I~
#else                                                              //~2928I~
//	CDC *pdc=Mstaticcolordisplay.GetDC();                          //~2928R~//~@@@@R~
  	CDCHandle *pdc=new CDCHandle(Mstaticcolordisplay.GetDC());     //~@@@@I~
//  CBrush  br(bg);                                                //~2928I~//~@@@@R~
    CBrush  br;                                                    //~@@@@I~
    br.CreateSolidBrush(bg);                                       //~@@@@I~
    pdc->SelectBrush(br);                                          //~@@@@I~
//  pdc->FillRect(&Mcolorbox_rect,&br);                            //~2928R~//~@@@@R~
    pdc->FillRect(&Mcolorbox_rect,br);                             //~@@@@I~
    pdc->SetBkColor(bg);                                           //~2923R~
    pdc->SetTextColor(fgw);                                        //~2923I~
    xx=Mcolorbox_rect.left+BORDERMARGIN;                           //~2928R~
	yy=Mcolorbox_rect.top+BORDERMARGIN;                            //~2928R~
    pdc->TextOut(xx,yy,ptxt1,strlen(ptxt1));                       //~2928R~
    pdc->SetTextColor(fgb);                                        //~2923R~
//  sz=pdc->GetTextExtent(ptxt1,strlen(ptxt1));                    //~2923R~//~@@@@R~
    pdc->GetTextExtent(ptxt1,strlen(ptxt1),&sz);                   //~@@@@I~
    pdc->TextOut(xx+sz.cx,yy,ptxt2,strlen(ptxt2));                 //~2928R~
//draw ruller                                                      //~v73tI~
    penn.CreatePen(PS_SOLID,0,rulercolor);                         //~v73tI~
//	pdc->SelectObject(penn);   //inner grid;save cuurrent          //~v73tI~//~@@@@R~
  	pdc->SelectPen(penn);   //inner grid;save cuurrent             //~@@@@I~
//h-line                                                           //~v73tI~
    pt[0].x=0;                                                     //~v73tR~
    pt[1].x=Mcolorbox_rect.right;                                  //~v73tR~
    pt[0].y=pt[1].y=yy+sz.cy;                                      //~v73tR~
	pdc->Polyline(pt,2);		//draw line                        //~v73tI~
//v-line                                                           //~v73tI~
    pt[0].x=pt[1].x=sz.cx;                                         //~v73tI~
    pt[0].y=0;                                                     //~v73tI~
    pt[1].y=Mcolorbox_rect.bottom;                                 //~v73tI~
	pdc->Polyline(pt,2);		//draw line                        //~v73tI~
    penn.DeleteObject();                                           //~v73tI~
//  ReleaseDC(pdc);                                                //~2923R~//~@@@@R~
    ReleaseDC((HDC)(*pdc));                                        //~@@@@R~
#endif                                                             //~2928I~
    return;                                                        //~2923I~
}//displaycolor                                                    //~2923I~
//**************************************************************** //~2928I~
//*                                                                //~2928I~
//**************************************************************** //~2928I~
void CWxedlg::displayfont(void)                                    //~2928I~
{                                                                  //~2928I~
	COLORREF bg=RGB(255,255,255);     //white                      //~2928I~
	COLORREF fg=RGB(0,0,0);    //black                             //~2928I~
    char *ptxt1="Aa x01()";                                       //~2928I~
    char *ptxt2="あアぁァ亜";                                      //~2928R~
    char *ptxt2e="x80(\x80)xC0(\xc0)";                             //~v738R~
    char *ptxt3="1234567890";                                      //~2928I~
    char *pdata;                                                   //~2928I~
    int xx,yy,xx0,xx1,yy1,len,ii;                                  //~2C04R~
    int rc;                                                        //~2C04I~
    CFont *pfont,*poldfont;                                        //~2928R~
//	CBrush  br(bg);                                                //~2928I~//~@@@@R~
    CRgn  crgn;                                                    //~2C04R~
//************************                                         //~2928I~
//	CDC *pdc=Mstaticfontbox.GetDC();                               //~2928I~//~@@@@R~
  	CDCHandle *pdc=new CDCHandle(Mstaticfontbox.GetDC());          //~@@@@I~
	CBrush  br;                                                    //~@@@@I~
    br.CreateSolidBrush(bg);                                       //~@@@@I~
    pdc->SelectBrush(br);                                          //~@@@@I~
////clip consideration                                             //~2C03R~
//    pdc->SetMapMode(MM_ANISOTROPIC);                             //~2C03R~
//    pdc->SetWindowOrg(0,0);                                      //~2C03R~
//    pdc->SetWindowExt(Mfontbox_rect.right,Mfontbox_rect.bottom);   //range of logical axis by max display size//~2C03R~
//    pdc->SetViewportOrg(0,0);//map origin on physical axis       //~2C03R~
//    pdc->SetViewportExt(Mfontbox_rect.right,Mfontbox_rect.bottom);//~2C03R~
	crgn.CreateRectRgnIndirect(&Mfontbox_rect);                    //~2C04R~
//  rc=pdc->SelectClipRgn(&crgn);                                  //~2C04R~//~@@@@R~
    rc=pdc->SelectClipRgn(crgn);                                   //~@@@@I~
                                                                   //~2C04I~
	pfont=Mpwxemain->createfontsub(Mcharset,Mfontstyle,Mttfont,Mfontsz_h,Mfontsz_w,0);//~2B23R~
//  poldfont=pdc->SelectObject(pfont);   //inner grid;save cuurrent//~2928R~//~@@@@R~
    HFONT holdfont=pdc->SelectFont((HFONT)(*pfont));               //~@@@@R~
    poldfont=new CFont(holdfont);                                  //~@@@@R~
//  pdc->FillRect(&Mfontbox_rect,&br);                             //~2928I~//~@@@@R~
    pdc->FillRect(&Mfontbox_rect,br);                              //~@@@@I~
    pdc->SetBkColor(bg);                                           //~2928I~
    pdc->SetTextColor(fg);                                         //~2928I~
    xx0=Mfontbox_rect.left+BORDERMARGIN;                           //~2928I~
    xx1=xx0+Mfontbox_rect.right;                                   //~2C04R~
	yy=Mfontbox_rect.top+BORDERMARGIN;                             //~2928R~
    yy1=yy+Mfontbox_rect.bottom;                                   //~2C04R~
//  yylim=max(Mcellh,Mfontsz_h);                                   //~2C04R~
//  xxlim=max(Mcellw,Mfontsz_h/2);                                 //~2C04R~
                                                                   //~2928I~
    pdata=(char*)ptxt1;                                            //~2928R~
    len=strlen(ptxt1);                                             //~2928R~
    for (xx=xx0,ii=0;ii<len;ii++,pdata++,xx+=Mcellw)               //~2928I~
    {                                                              //~2928I~
//      if (xx+xxlim>xx1)                                          //~2C04R~
        if (xx>xx1)                                                //~2C04I~
            break;                                                 //~2C04R~
//  	pdc->TextOut(xx,yy,pdata,1);                               //~2928I~//~va6vR~
//  	csubtextoutw1_locale(CSTOW1LO_LOCALEIFCVERR,pdc->m_hDC,xx,yy,pdata,1);//~va6vR~//~va74R~
    	csubtextoutw1_locale(CSTOW1LO_NOTRANS,pdc->m_hDC,xx,yy,pdata,1);//~va74I~
    }                                                              //~2928I~
                                                                   //~2928I~
	yy+=Mcellh;                                                    //~2928I~
//  if (yy+yylim<yy1)                                              //~2C04R~
    if (yy<yy1)                                                    //~2C04I~
    {                                                              //~2C04R~
	  if (wxegetdbcsmode())                                        //~v738I~
      {                                                            //~v738I~
        pdata=(char*)ptxt2;                                        //~2928R~
        len=strlen(ptxt2);                                         //~2928R~
      }                                                            //~v738I~
      else                                                         //~v738M~
      {                                                            //~v738I~
        pdata=(char*)ptxt2e;                                       //~v738M~
        len=strlen(ptxt2e);                                        //~v738I~
      }                                                            //~v738I~
        for (xx=xx0,ii=0;ii<len;ii+=2,pdata+=2,xx+=Mcellw+Mcellw)  //~2928R~
        {                                                          //~2928R~
//          if (xx+xxlim+xxlim>xx1)                                //~2C04R~
            if (xx>xx1)                                            //~2C04I~
                break;                                             //~2C04R~
//          pdc->TextOut(xx,yy,pdata,2);                           //~2928R~//~va6vR~
//  		csubtextoutw1_locale(CSTOW1LO_LOCALEIFCVERR,pdc->m_hDC,xx,yy,pdata,2);//~va6vR~//~va74R~
			csubtextoutw1_locale(CSTOW1LO_NOTRANS,pdc->m_hDC,xx,yy,pdata,2);//~va74I~
        }                                                          //~2928R~
    }                                                              //~2C04R~
                                                                   //~2928I~
    yy+=Mcellh;                                                    //~2928I~
//  if (yy+yylim<yy1)                                              //~2C04R~
    if (yy<yy1)                                                    //~2C04I~
    {                                                              //~2C04R~
        pdata=(char*)ptxt3;                                        //~2928R~
        len=strlen(ptxt3);                                         //~2928R~
        for (xx=xx0,ii=0;ii<len;ii++,pdata++,xx+=Mcellw)           //~2928R~
        {                                                          //~2928R~
//          if (xx+xxlim>xx1)                                      //~2C04R~
            if (xx>xx1)                                            //~2C04I~
                break;                                             //~2C04R~
//          pdc->TextOut(xx,yy,pdata,1);                           //~2928R~//~va6vR~
//  		csubtextoutw1_locale(CSTOW1LO_LOCALEIFCVERR,pdc->m_hDC,xx,yy,pdata,1);//~va6vR~//~va74R~
    		csubtextoutw1_locale(CSTOW1LO_NOTRANS,pdc->m_hDC,xx,yy,pdata,1);//~va74I~
        }                                                          //~2928R~
    }                                                              //~2C04R~
    rc=pdc->SelectClipRgn(NULL);                                   //~2C04I~
//  pdc->SelectObject(poldfont);   //inner grid;save cuurrent      //~2928I~//~@@@@R~
    pdc->SelectFont((HFONT)(*poldfont));   //inner grid;save cuurrent //~@@@@R~
//  ReleaseDC(pdc);                                                //~2928I~//~@@@@R~
    ReleaseDC((HDC)(*pdc));                                        //~@@@@R~
    pfont->DeleteObject();                                         //~2928R~
    return;                                                        //~2928I~
}//displayfont                                                     //~2928I~
                                                                   //~2928I~
void CWxedlg::OnPaint()                                            //~2928R~
{                                                                  //~2928R~
//  CPaintDC dc(this); //Dont delete this line 092802;             //~@@@@R~
    CPaintDC dc(m_hWnd); //Dont delete this line 092802; 描画用のデバイス コンテキスト//~@@@@I~
//****************************************                         //~2928R~
//  if (!Mpaintsw)  //1st time                                     //~2928R~
//  {                                                              //~2928R~
//      Mpaintsw=1;                                                //~2928R~
        displaycolor();     //no effect at oninitdialog            //~2928R~
        displayfont();     //no effect at oninitdialog             //~2928I~
//  }                                                              //~2928R~
                                                                   //~2928R~
    // dont call CDialog::OnPaint()                                //~v55GR~
}                                                                  //~2928R~
//*********************                                            //~2C14I~
//*font height                                                     //~2C14I~
//*********************                                            //~2C14I~
void CWxedlg::OnChangeEditHeight() 
{
    char buff[128];                                                //~2928I~
//*********************                                            //~2928I~
	Mfontsz_h=atoi((Meditfonth.GetWindowText(buff,sizeof(buff)-1),buff));//~2928R~
    if (Mfontsz_h>Mcellh)	//font height induced                  //~2C14I~
    {                                                              //~2C14I~
        Mcellh=Mfontsz_h;   //induce col width                     //~2C14I~
    	sprintf(buff,"% 3d",Mcellh);                               //~2C14I~
    	Meditcellh.SetWindowText(buff);                            //~2C14I~
	    Mspinrowheight.SetPos(Mcellh);                             //~2C14I~
    }                                                              //~2C14I~
    displayfont();     //no effect at oninitdialog                 //~2928I~
	
}
//*********************                                            //~2C14I~
//*font width                                                      //~2C14I~
//*********************                                            //~2C14I~
void CWxedlg::OnChangeEditWidth()                                  //~2928M~
{                                                                  //~2928M~
    char buff[128];                                                //~2928M~
//*********************                                            //~2928M~
	Mfontsz_w=atoi((Meditfontw.GetWindowText(buff,sizeof(buff)-1),buff));//~2928R~
    if (Mfontsz_w>Mcellw)	//font wdidth induced                  //~2C14R~
    {                                                              //~2C14I~
        Mcellw=Mfontsz_w;   //induce col width                     //~2C14R~
    	sprintf(buff,"% 3d",Mcellw);                               //~2C14I~
    	Meditcellw.SetWindowText(buff);                            //~2C14I~
	    Mspincolwidth.SetPos(Mcellw);                              //~2C14I~
    }                                                              //~2C14I~
    displayfont();     //no effect at oninitdialog                 //~2928M~
	                                                               //~2928M~
}                                                                  //~2928M~
//*********************                                            //~2C14I~
//*row height                                                      //~2C14I~
//*********************                                            //~2C14I~
void CWxedlg::OnChangeEditRowh() 
{
    char buff[128];                                                //~2928I~
//*********************                                            //~2928I~
	Mcellh=atoi((Meditcellh.GetWindowText(buff,sizeof(buff)-1),buff));//~2928R~
    if (Mfontsz_h>Mcellh) 	//row height reduced                   //~2C14I~
    {                                                              //~2C14I~
        Mfontsz_h=Mcellh;   //reduce font width                    //~2C14I~
    	sprintf(buff,"% 3d",Mfontsz_h);                            //~2C14I~
    	Meditfonth.SetWindowText(buff);                            //~2C14I~
    	Mspinfontsz_h.SetPos(Mfontsz_h);                           //~2C14I~
    }                                                              //~2C14I~
    displayfont();     //no effect at oninitdialog                 //~2928I~
	
}
//*********************                                            //~2C14I~
//*col width                                                       //~2C14I~
//*********************                                            //~2C14I~
void CWxedlg::OnChangeEditColw()                                   //~2928M~
{                                                                  //~2928M~
    char buff[128];                                                //~2928M~
//*********************                                            //~2928M~
	Mcellw=atoi((Meditcellw.GetWindowText(buff,sizeof(buff)-1),buff));//~2928R~
    if (Mfontsz_w>Mcellw) 	//col width reduced                    //~2C14R~
    {                                                              //~2C14I~
        Mfontsz_w=Mcellw;   //reduce font width                    //~2C14R~
    	sprintf(buff,"% 3d",Mfontsz_w);                            //~2C14I~
    	Meditfontw.SetWindowText(buff);                            //~2C14I~
    	Mspinfontsz_w.SetPos(Mfontsz_w);                           //~2C14I~
    }                                                              //~2C14I~
    displayfont();                                                 //~2928R~
	                                                               //~2928M~
}                                                                  //~2928M~

void CWxedlg::OnCheckTtfont() 
{
    Mttfont=Mttcheckbox.GetCheck();                                //~2928I~
    displayfont();                                                 //~2928I~
}
void CWxedlg::OnCheckLigature()                                    //~va3gI~
{                                                                  //~va3gI~
    Mligature=Mligaturecheckbox.GetCheck();                        //~va3gI~
    displayfont();                                                 //~va3gI~
}                                                                  //~va3gI~

void CWxedlg::OnRadioAnsi() 
{
	Mcharset=ANSI_CHARSET;                                         //~3102R~
	Meditother.EnableWindow(FALSE);                                //~3102I~
	Mcombocharsetother.EnableWindow(FALSE);                        //~va0RI~
    displayfont();                                                 //~3102R~
}

void CWxedlg::OnRadioDefault() 
{
    Mcharset=DEFAULT_CHARSET;                                      //~2928R~
	Meditother.EnableWindow(FALSE);                                //~3102I~
	Mcombocharsetother.EnableWindow(FALSE);                        //~va0RI~
    displayfont();                                                 //~2928R~
}

void CWxedlg::OnRadioSjis() 
{
    Mcharset=SHIFTJIS_CHARSET;                                     //~2928R~
	Meditother.EnableWindow(FALSE);                                //~3102I~
	Mcombocharsetother.EnableWindow(FALSE);                        //~va0RI~
    displayfont();                                                 //~2928R~
}
                                                                   //~3102I~
void CWxedlg::OnRadioOther()                                       //~3102I~
{                                                                  //~3102I~
	char txt[8];                                                   //~3102R~
	int  charset;                                                  //~3102I~
//**********************                                           //~3102I~
    Meditother.GetWindowText(txt,sizeof(txt));                     //~3102I~
    charset=atoi(txt);                                             //~3102R~
    if (charset>=0 && charset<256)                                 //~3102I~
    	Mcharset=Mothercharset=charset;                            //~3102I~
    else                                                           //~3102I~
    {                                                              //~3102I~
    	sprintf(txt,"%d",Mothercharset);                           //~3102I~
    	Meditother.SetWindowText(txt);	//filename                 //~3102R~
    }                                                              //~3102I~
	Meditother.EnableWindow(TRUE);                                 //~3102I~
	Mcombocharsetother.EnableWindow(TRUE);                         //~va0RI~
    displayfont();                                                 //~3102R~
}                                                                  //~3102I~
                                                                   //~3102M~
void CWxedlg::OnChangeEditOther()                                  //~3102M~
{                                                                  //~3102M~
    char txt[8];                                                   //~3102R~//~va0RR~
//**********************                                           //~3102I~
    Meditother.GetWindowText(txt,sizeof(txt));                   //~3102R~//~va0RR~
//    Mcharset=Mothercharset=atoi(txt);                            //~3102R~
//    displayfont();                                               //~3102R~
	setselectothercharset(txt);	//other charset combo box selected entry update//~va0RR~
}                                                                  //~3102M~
void CWxedlg::OnChangeEditRulerkey()                               //~v740I~
{                                                                  //~v740I~
    return; //called not last but each time char input             //~v740I~
}                                                                  //~v740I~
//***************************************************************************//~v740I~
//color data exchange  for ruler                                   //~v740I~
//***************************************************************************//~v740I~
int CWxedlg::setrulerkey(int Popt)                                 //~v740I~
{                                                                  //~v740I~
    char entrytext[128];                                           //~v740R~
    char *pc,*pco;                                                 //~v740I~
    int ii,ch;                                                     //~v740I~
//****************************                                     //~v740I~
    if (Popt)//gbl init,setup for dialog                           //~v740I~
    {                                                              //~v740I~
    	memcpy(Mrulerkey,Mpwxemain->Mrulerkey,sizeof(Mrulerkey));  //~v740R~
    	pc=Mrulerkey;                                              //~v740I~
    	for (pco=entrytext,ii=0;ii<3;ii++,pc++)                    //~v740R~
        	if (*pc>=1 && *pc<=12) 	//F1-->F12                     //~v740I~
            	if (ii<2)                                          //~v740I~
	            	pco+=sprintf(pco,"F%d,",*pc);                  //~v740R~
                else                                               //~v740I~
	            	pco+=sprintf(pco,"F%d",*pc);                   //~v740R~
            else                                                   //~v740I~
//          	*pco++=toupper(*pc);                               //~v740I~//~vb2JR~
            	*pco++=(char)toupper(*pc);                         //~vb2JI~
        *pco=0;                                                    //~v740I~
		Meditrulerkey.SetWindowText(entrytext);                    //~v740R~
    }                                                              //~v740I~
    else                                                           //~v740I~
    {                                                              //~v740I~
    	memset(entrytext,0,sizeof(entrytext));                     //~v740I~
		Meditrulerkey.GetWindowText(entrytext,sizeof(entrytext));  //~v740R~
UTRACED("rulerkey inputtext",entrytext,sizeof(entrytext));         //~v740R~
        pc=entrytext+strspn(entrytext," ");                        //~v740I~
        for (pco=Mrulerkey,ii=0;*pc && ii<3;ii++)                  //~v740R~
        {                                                          //~v740I~
            ch=toupper(*pc);                                       //~v740I~
        	if (ch=='F'		//Fn key                               //~v740R~
            &&  (*(pc+1)>='1' && *(pc+1)<='9'))                    //~v740R~
            {                                                      //~v740I~
            	pc++;                                              //~v740I~
            	ch=atoi(pc);                                       //~v740I~
                if (!(ch>=1 && ch<=12))                            //~v740I~
                	break;	//err                                  //~v740I~
                while(*pc>='0' && *pc<='9')                        //~v740R~
                	pc++;                                          //~v740I~
            }                                                      //~v740I~
            else                                                   //~v740I~
            {                                                      //~v740I~
                pc++;                                              //~v740I~
                if (ch==',')                                       //~v740I~
                {                                                  //~v740I~
                	ii--;                                          //~v740I~
                    continue;                                      //~v740I~
                }                                                  //~v740I~
            }                                                      //~v740I~
//          *pco++=ch;                                             //~v740I~//~vb2JR~
            *pco++=(char)ch;                                       //~vb2JI~
        }                                                          //~v740I~
        if (ii)    //not cleared                                   //~v740R~
        {                                                          //~v740I~
            if (ii!=3||*pc)                                        //~v740R~
            {                                                      //~v740R~
                uerrmsgbox("specify 3 upper letter by the sequence of Vertical/Horizontal/Cross ruler\n"//~v740R~
                           "ex) \"F1F2F12\":F1,F2,F12  \"123\":1,2,3  \"IOP\":iop",0);//~v740R~
                return 4;                                          //~v740R~
            }                                                      //~v740R~
            *pco=0;                                                //~v740R~
            memcpy(Mpwxemain->Mrulerkey,Mrulerkey,sizeof(Mrulerkey));//~v740R~
		}                                                          //~v740M~
        else                                                       //~v740I~
            strcpy(Mpwxemain->Mrulerkey,DEF_RULERKEY);             //~v740I~
UTRACEP("rulerkey=%x %x %x\n",(UINT)Mrulerkey[0],(UINT)Mrulerkey[1],(UINT)Mrulerkey[2]);//~v740I~
    }                                                              //~v740I~
    return 0;                                                      //~v740I~
}//setrulerkey                                                     //~v740I~


void CWxedlg::OnCheckRctl() 
{
    Mrctl=Mcheckrctl.GetCheck();                                   //~v55cR~
}
void CWxedlg::OnCheckRuler()                                       //~v73tI~
{                                                                  //~v73tI~
    int rr,gg,bb;                                                  //~v73tI~
	char wkedit[8];                                                //~v73tI~
//*************                                                    //~v73tI~
    Mruler=Mcheckruler.GetCheck();                                 //~v73tI~
    if (Mruler) //changed to ruler color setup                     //~v73tI~
    {                                                              //~v73tI~
        rr=Mrulercolor_r;                                          //~v73tR~
        gg=Mrulercolor_g;                                          //~v73tR~
        bb=Mrulercolor_b;                                          //~v73tR~
    }                                                              //~v73tI~
    else                                                           //~v73tI~
    {                                                              //~v73tI~
        rr=Mbgcolor_r;                                             //~v73tI~
        gg=Mbgcolor_g;                                             //~v73tI~
        bb=Mbgcolor_b;                                             //~v73tI~
    }                                                              //~v73tI~
//redraw                                                           //~v73tI~
    Mslider_r.SetPos(rr);                                          //~v73tI~
    Mslider_g.SetPos(gg);                                          //~v73tI~
    Mslider_b.SetPos(bb);                                          //~v73tI~
    sprintf(wkedit,"% 3d",rr);                                     //~v73tI~
    Medit_r.SetWindowText(wkedit);                                 //~v73tI~
    sprintf(wkedit,"% 3d",gg);                                     //~v73tI~
    Medit_g.SetWindowText(wkedit);                                 //~v73tI~
    sprintf(wkedit,"% 3d",bb);                                     //~v73tI~
    Medit_b.SetWindowText(wkedit);                                 //~v73tI~
}                                                                  //~v73tI~

void CWxedlg::OnCheckFreecsr() 
{
    Mfreecsr=Mcheckfreecsr.GetCheck();                             //~v55qR~
}
void CWxedlg::OnCheckBeep()                                        //~v55GM~
{                                                                  //~v55GM~
    Mbeep=Mcheckbeep.GetCheck();                                   //~v55GI~
}                                                                  //~v55GM~
void CWxedlg::OnCheckQexit()                                       //~v73yI~
{                                                                  //~v73yI~
    Mqexit=Mcheckqexit.GetCheck();                                 //~v73yI~
}                                                                  //~v73yI~
void CWxedlg::OnContextMenu(CWnd* pWnd, CPoint point)              //~v55DR~
{

//static DWORD Shtmlhelptbl[]={                                    //~v55DR~
//    IDC_CHECK_FREECSR,HIDC_CHECK_FREECSR,    // IDD_SETUP        //~v55DR~
//    IDC_CHECK_RCTL   ,HIDC_CHECK_RCTL   ,    // IDD_SETUP        //~v55DR~
//    IDC_CHECK_USEACT ,HIDC_CHECK_USEACT ,                        //~v55DR~
//    IDC_CHECK_USEMK  ,HIDC_CHECK_USEMK  ,                        //~v55DR~
//    0,0};                                                        //~v55DR~
    HWND hwnd;                                                     //~v55DI~
//  int   ctxid;                                                   //~v71AR~
    char *ctxid;                                                   //~v71AI~
    CPoint pt;                                                     //~v55DI~
    int  dbcssw;                                                   //~v55FI~
//******************************                                   //~v55DI~
//    HtmlHelp(                                                    //~v55DM~
//    pWnd->GetSafeHwnd(),                                         //~v55DM~
//    "wxehhelp.txt",                                              //~v55DM~
//    HH_TP_HELP_CONTEXTMENU,                                      //~v55DM~
//    (DWORD)(LPVOID)Shtmlhelptbl);                                //~v55DM~
//    GetClientRect(&rc);                                          //~v55DM~
//    pt=point;                                                    //~v55DM~
//    ScreenToClient(&pt);                                         //~v55DM~
//    if (PtInRect(&rc,pt))                                        //~v55DM~
//    {                                                            //~v55DM~
//        WinHelp(480,HELP_CONTEXTPOPUP);                          //~v55DM~
//    }                                                            //~v55DM~
    dbcssw=wxegetdbcsmode();                                       //~v55FI~
    hwnd=pWnd->m_hWnd;                                             //~v55DI~
    if (hwnd==this->m_hWnd)                                        //~v55DR~
    {                                                              //~v55DI~
    	pt=point;          //parnm is screen coord                 //~v55DR~
		ctxid=chkinrect(pt);                                       //~v55DI~
	}                                                              //~v55DI~
    else                                                           //~v55DI~
    if (hwnd==Meditfonth.m_hWnd || hwnd==Mspinfontsz_h.m_hWnd)     //~v55DR~
		ctxid=GETCTXID(dbcssw,IDH_FONTH);                          //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==Meditfontw.m_hWnd || hwnd==Mspinfontsz_w.m_hWnd)     //~v55DR~
		ctxid=GETCTXID(dbcssw,IDH_FONTW);                          //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==Meditcellh.m_hWnd || hwnd==Mspinrowheight.m_hWnd)    //~v55DR~
		ctxid=GETCTXID(dbcssw,IDH_ROWH);                           //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==Meditcellw.m_hWnd || hwnd==Mspincolwidth.m_hWnd)     //~v55DR~
		ctxid=GETCTXID(dbcssw,IDH_COLW);                           //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==Mcombostyle.m_hWnd)                                  //~v55DR~
    	ctxid=GETCTXID(dbcssw,IDH_FONTSTYLE);                      //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==Mttcheckbox.m_hWnd)                                  //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_TRUETYPE);                       //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==Mligaturecheckbox.m_hWnd)                            //~va3gI~
		ctxid=GETCTXID(dbcssw,IDH_LIGATURE);                       //~va3gI~
    else                                                           //~va3gI~
    if (hwnd==Medit_r.m_hWnd || hwnd==Mslider_r.m_hWnd)            //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_RED);                            //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==Medit_g.m_hWnd || hwnd==Mslider_g.m_hWnd)            //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_GREEN);                          //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==Medit_b.m_hWnd || hwnd==Mslider_b.m_hWnd)            //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_BLUE);                           //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==Mspinscrollctr.m_hWnd || hwnd==Meditscrollctr.m_hWnd)//~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_SCROLLCTR);                      //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==Mspinscrolltimer.m_hWnd || hwnd==Meditscrolltimer.m_hWnd)//~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_SCROLLTIMER);                    //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==Mcheckuseact.m_hWnd)                                 //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_USEACCKEY);                      //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==Mcheckusemk.m_hWnd)                                  //~v55DM~
		ctxid=GETCTXID(dbcssw,IDH_USEMETAKEY);                     //~v55FR~
    else                                                           //~v55DM~
    if (hwnd==Mcheckrctl.m_hWnd)                                   //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_USERCTL);                        //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==Mcheckfreecsr.m_hWnd)                                //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_FREECSR);                        //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==Mcheckbeep.m_hWnd)                                   //~v55GI~
		ctxid=GETCTXID(dbcssw,IDH_BEEP);                           //~v55GI~
    else                                                           //~v55GI~
    if (hwnd==Mcheckqexit.m_hWnd)                                  //~v73yI~
		ctxid=GETCTXID(dbcssw,IDH_QEXIT);                          //~v73yI~
    else                                                           //~v73yI~
    if (hwnd==Mcheckruler.m_hWnd)                                  //~v73tI~
		ctxid=GETCTXID(dbcssw,IDH_RULER);                          //~v73tI~
    else                                                           //~v73tI~
//  if (hwnd==((CButton*)GetDlgItem(IDC_RADIO_DEFAULT))->m_hWnd)   //~v55DI~//~@@@@R~
    if (hwnd==GetDlgItem(IDC_RADIO_DEFAULT))                       //~@@@@I~
        ctxid=GETCTXID(dbcssw,IDH_CSDEFAULT);                      //~v55FR~
    else                                                           //~v55DI~
//  if (hwnd==((CButton*)GetDlgItem(IDC_RADIO_ANSI))->m_hWnd)      //~v55DI~//~@@@@R~
    if (hwnd==GetDlgItem(IDC_RADIO_ANSI))                          //~@@@@I~
        ctxid=GETCTXID(dbcssw,IDH_CSANSI);                         //~v55FR~
    else                                                           //~v55DI~
//  if (hwnd==((CButton*)GetDlgItem(IDC_RADIO_SJIS))->m_hWnd)      //~v55DI~//~@@@@R~
    if (hwnd==GetDlgItem(IDC_RADIO_SJIS))                          //~@@@@I~
        ctxid=GETCTXID(dbcssw,IDH_CSSJIS);                         //~v55FR~
    else                                                           //~v55DI~
//  if (hwnd==((CButton*)GetDlgItem(IDC_RADIO_OTHER))->m_hWnd)     //~v55DI~//~@@@@R~
    if (hwnd==GetDlgItem(IDC_RADIO_OTHER))                         //~@@@@I~
        ctxid=GETCTXID(dbcssw,IDH_CSOTHER);                        //~v55FR~
    else                                                           //~v55DM~
    if (hwnd==Meditother.m_hWnd)                                   //~v55DM~
		ctxid=GETCTXID(dbcssw,IDH_OTHERCHARSET);                   //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==Meditrulerkey.m_hWnd)                                //~v740I~
		ctxid=GETCTXID(dbcssw,IDH_RULERKEY);                       //~v740I~
    else                                                           //~v740I~
        ctxid=0;                                                   //~v55DI~
    if (ctxid)                                                     //~v55DI~
//  	WinHelp(ctxid,HELP_CONTEXTPOPUP);                          //~v71AR~
		uhtmlhelp(dbcssw!=0,hwnd,ctxid,point);                     //~v71AR~
}//OncontextMenu                                                   //~v740R~
//************************************************                 //~v71AR~
//* F1 pressed(Mouse Rbutton is not effective for EDIT control as help popup)//~v71AI~
//************************************************                 //~v71AI~
BOOL CWxedlg::OnHelpInfo(HELPINFO* pHelpInfo)                      //~v55DR~
{                                                                  //~v55DR~
    int ctlid;                                                     //~v71AR~
    int  dbcssw;                                                   //~v55FI~
//  int   ctxid;                                                   //~v71AR~
    char *ctxid;                                                   //~v71AI~
//*********************                                            //~v55DR~
    dbcssw=wxegetdbcsmode();                                       //~v55FI~
    ctlid=pHelpInfo->iCtrlId;                                      //~v55DR~
    switch(ctlid)                                                  //~v55DR~
    {                                                              //~v55DR~
    case IDC_EDIT_HEIGHT          ://    1007                      //~v55DR~
        ctxid=GETCTXID(dbcssw,IDH_FONTH);                          //~v55FR~
        break;                                                     //~v55DR~
    case IDC_EDIT_WIDTH           ://    1008                      //~v55DR~
        ctxid=GETCTXID(dbcssw,IDH_FONTW);                          //~v55FR~
        break;                                                     //~v55DR~
    case IDC_EDIT_ROWH            ://    1013                      //~v55DR~
        ctxid=GETCTXID(dbcssw,IDH_ROWH);                           //~v55FR~
        break;                                                     //~v55DR~
    case IDC_EDIT_COLW            ://    1012                      //~v55DR~
        ctxid=GETCTXID(dbcssw,IDH_COLW);                           //~v55FR~
        break;                                                     //~v55DR~
    case IDC_EDIT_RED             ://    1018                      //~v55DR~
        ctxid=GETCTXID(dbcssw,IDH_RED);                            //~v55FR~
        break;                                                     //~v55DR~
    case IDC_EDIT_GREEN           ://    1019                      //~v55DR~
        ctxid=GETCTXID(dbcssw,IDH_GREEN);                          //~v55FR~
        break;                                                     //~v55DR~
    case IDC_EDIT_BLUE            ://    1020                      //~v55DR~
        ctxid=GETCTXID(dbcssw,IDH_BLUE);                           //~v55FR~
        break;                                                     //~v55DR~
    case IDC_EDIT_SCROLLCTR       ://    1031                      //~v55DR~
        ctxid=GETCTXID(dbcssw,IDH_SCROLLCTR);                      //~v55FR~
        break;                                                     //~v55DR~
    case IDC_EDIT_SCROLLTIMER     ://    1074                      //~v55DR~
        ctxid=GETCTXID(dbcssw,IDH_SCROLLTIMER);                    //~v55FR~
        break;                                                     //~v55DR~
    case IDC_EDIT_OTHER           ://    1070                      //~v55DR~
        ctxid=GETCTXID(dbcssw,IDH_CSOTHER);                        //~v55FR~
        break;                                                     //~v55DR~
    case IDC_EDIT_RULERKEY       ://    1122                       //~v740R~
        ctxid=GETCTXID(dbcssw,IDH_RULERKEY);                       //~v740I~
        break;                                                     //~v740I~
    default:                                                       //~v55DR~
        ctxid=0;                                                   //~v55DR~
    }                                                              //~v55DR~
    if (ctxid)                                                     //~v55DR~
//      WinHelp(ctxid,HELP_CONTEXTPOPUP);                          //~v71AR~
		uhtmlhelp(dbcssw!=0,0,ctxid,pHelpInfo->MousePos);          //~v71AR~
//  return CDialog::OnHelpInfo(pHelpInfo);                         //~@@@@R~
    return TRUE;                                                   //~@@@@I~
}                                                                  //~v55DR~

//int CWxedlg::chkinrect(CPoint point)                             //~v71AR~
char *CWxedlg::chkinrect(CPoint point)                             //~v71AI~
{                                                                  //~v55DI~
//	int ctxid;                                                     //~v71AR~
    char *ctxid;                                                   //~v71AI~
    int  dbcssw;                                                   //~v55FI~
//*************************                                        //~v55DI~
    dbcssw=wxegetdbcsmode();                                       //~v55FI~
    if (chkinrectsub(point,IDC_STATIC_FONTH        )) //:    1089  //~v55DR~
		ctxid=GETCTXID(dbcssw,IDH_FONTH);                          //~v55FR~
    else                                                           //~v55DM~
    if (chkinrectsub(point,IDC_STATIC_FONTW        )) //:    1090  //~v55DR~
		ctxid=GETCTXID(dbcssw,IDH_FONTW);                          //~v55FR~
    else                                                           //~v55DM~
    if (chkinrectsub(point,IDC_STATIC_ROWH         )) //:    1091  //~v55DR~
		ctxid=GETCTXID(dbcssw,IDH_ROWH);                           //~v55FR~
    else                                                           //~v55DM~
    if (chkinrectsub(point,IDC_STATIC_COLW         )) //:    1092  //~v55DR~
		ctxid=GETCTXID(dbcssw,IDH_COLW);                           //~v55FR~
    else                                                           //~v55DM~
    if (chkinrectsub(point,IDC_STATIC_FONTSTYLE    )) //:    1093  //~v55DR~
		ctxid=GETCTXID(dbcssw,IDH_FONTSTYLE);                      //~v55FR~
    else                                                           //~v55DM~
    if (chkinrectsub(point,IDC_STATIC_FONTBOX      )) //:    1030  //~v55DR~
		ctxid=GETCTXID(dbcssw,IDH_FONTBOX);                        //~v55FR~
    else                                                           //~v55DM~
    if (chkinrectsub(point,IDC_STATIC_RED          )) //:    1099  //~v55DR~
		ctxid=GETCTXID(dbcssw,IDH_RED);                            //~v55FR~
    else                                                           //~v55DM~
    if (chkinrectsub(point,IDC_STATIC_GREEN        )) //:          //~v55DR~
		ctxid=GETCTXID(dbcssw,IDH_GREEN);                          //~v55FR~
    else                                                           //~v55DM~
    if (chkinrectsub(point,IDC_STATIC_BLUE         )) //:          //~v55DR~
		ctxid=GETCTXID(dbcssw,IDH_BLUE);                           //~v55FR~
    else                                                           //~v55DM~
    if (chkinrectsub(point,IDC_STATIC_COLORBOX     )) //:    1029  //~v55DR~
		ctxid=GETCTXID(dbcssw,IDH_COLORBOX);                       //~v55FR~
    else                                                           //~v55DM~
    if (chkinrectsub(point,IDC_STATIC_BGCOLOR      )) //:    1094  //~v55DR~
		ctxid=GETCTXID(dbcssw,IDH_BGCOLOR);                        //~v55FR~
    else                                                           //~v55DM~
    if (chkinrectsub(point,IDC_STATIC_SCROLLCTR    )) //:    1095  //~v55DR~
		ctxid=GETCTXID(dbcssw,IDH_SCROLLCTR);                      //~v55FR~
    else                                                           //~v55DM~
    if (chkinrectsub(point,IDC_STATIC_INTVL        )) //:    1097  //~v55DR~
		ctxid=GETCTXID(dbcssw,IDH_SCROLLTIMER);                    //~v55FR~
    else                                                           //~v55DM~
    if (chkinrectsub(point,IDC_STATIC_SECOND       )) //:    1098  //~v55DR~
		ctxid=GETCTXID(dbcssw,IDH_SCROLLTIMER);                    //~v55FR~
    else                                                           //~v55DM~
    if (chkinrectsub(point,IDC_STATIC_CHARSET      )) //:    1096  //~v55DR~
		ctxid=GETCTXID(dbcssw,IDH_CHARSET);                        //~v55FR~
    else                                                           //~v740I~
    if (chkinrectsub(point,IDC_STATIC_RULERKEY    )) //:    1095   //~v740I~
		ctxid=GETCTXID(dbcssw,IDH_RULERKEY);                       //~v740I~
    else                                                           //~v55DM~
        ctxid=0;                                                   //~v55DM~
    return ctxid;                                                  //~v55DI~
}//chkrect                                                         //~v55DI~
//*************************************************                //~v55DM~
//*chk screen cord is on the control rect         *                //~v55DM~
//*parm1:point by screen cord                                      //~v55DM~
//*parm2:resourceID                                                //~v55DM~
//*************************************************                //~v55DM~
int CWxedlg::chkinrectsub(CPoint Ppt,int Prid)                     //~v55DI~
{                                                                  //~v55DM~
    CWnd    *pwnd;                                                 //~v55DM~
	CRect   rect;                                                  //~v55DM~
	CPoint  pt;                                                    //~v55DM~
//*************************************                            //~v55DM~
    pt=Ppt;         			//screen cord                      //~v55DM~
//  pwnd=(CWnd*)GetDlgItem(Prid);  //control window                //~v55DM~//~@@@@R~
    pwnd=new CWnd(GetDlgItem(Prid));  //control window             //~@@@@I~
	pwnd->ScreenToClient(&pt);     //by the control client cord    //~v55DM~
	pwnd->GetClientRect(&rect);    //get the client region width,height//~v55DM~
	return rect.PtInRect(pt);      //chk in the region             //~v55DM~
}                                                                  //~v55DM~
