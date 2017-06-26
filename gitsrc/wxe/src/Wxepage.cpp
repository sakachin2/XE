//*CID://+vavBR~:                             update#=  329;       //~vavBR~
//***********************************************************************//~v51gI~
//vavC:140430 change Dialog to modeal                              //~vavCI~
//vavB:140429 (BUG:wxe)preview box was not redrawn at focus regain //~vavBI~
//vavz:140428 (wxe)display ucs2 filename on page dialog            //~vavzI~
//vak7:130906 redirect memcpy to memmove when overlaped            //~vak7I~
//vafh:120616 for VC10:/W4 warning except C4115,C4214,C4100,C4706,C4244,C4210,C4127,C4245//~vafhI~
//va8a:100926 (WXE)end wxp work at end print                       //~va8aI~
//va49:100406 (WXE:BUG)wxe print abend when VHEX and HHEX.         //~va49I~
//v71A:061030 (WXE)Use HtmlHelp;Winhelp is deprecated at Vista;XP english ersion cannot read .hlp by the readson of codepage unsupported//~v71AI~
//v65i:050802 (BUG:WXE)allow print font minimum 0,but err when both cellh and font is 0//~v65iI~
//v62W:050422 (WXE)maximum cell height definition for small doc    //~v62WI~
//v627:050309 (WXE)vhex print support                              //~v627I~
//v56v:040411 (WXE)shorten page/line msg                           //~v56vI~
//v55F:040314 (WXE)english help                                    //~v55FI~
//v55D:040309 (WXE)popup help for dialog control                   //~v55DI~
//v51h:030525 (WXE)col/row by font size specification              //~v51hI~
//v51g:030525 (WXE)allow wrap around by NextPage/PrevPage button   //~v51gI~
//***********************************************************************//~v51gI~
// Wxepage.cpp                                                     //~v71AR~
//

#include "stdafx.h"
#define NO_MACRO_REDIRECT                                          //~vavzI~
#include <ulib.h>                                                  //~vak7M~
#include "wxedef.h"                                                //~2B03I~
#include "wxe.h"
#include "wxefile.h"                                               //~2B03I~
#include "wxedoc.h"                                                //~2B03I~
#include "wxemain.h"                                               //~2B03I~
#include "mainfrm.h"                                               //~2B03I~
#include "Wxepage.h"
#include "wxexei.h"                                                //~2B09I~
#include "wxecsub.h"                                               //~v51hI~
#include "wxehelp.h"                                               //~v55DI~
#include "wxehelps.h" //by help tool                               //~v71AI~
#include <utrace.h>                                                //~vavBI~

#ifdef _DEBUG
//#define new DEBUG_NEW                                            //~@@@@R~
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
static int Sdisplaytype;                                           //+vavBR~
/////////////////////////////////////////////////////////////////////////////
//void CWxepage::DoDataExchange(CDataExchange* pDX)                //~@@@@R~
//{                                                                //~@@@@R~
//    CDialog::DoDataExchange(pDX);                                //~@@@@R~
//    //{{AFX_DATA_MAP(CWxepage)                                   //~@@@@R~
//    DDX_Control(pDX, IDC_SPIN_CELLSZH_MAX, Mspinpcellszhmax);    //~@@@@R~
//    DDX_Control(pDX, IDC_EDIT_CELLSZH_MAX, Meditpcellszhmax);    //~@@@@R~
//    DDX_Control(pDX, IDOK, Mbuttonok);                           //~@@@@R~
//    DDX_Control(pDX, IDCANCEL, Mbuttoncancel);                   //~@@@@R~
//    DDX_Control(pDX, IDC_PREVIEWPRTSCR, MbuttonPreviewPrintScr); //~@@@@R~
//    DDX_Control(pDX, IDC_PRTSCR, MbuttonPrintScr);               //~@@@@R~
//    DDX_Control(pDX, IDC_SPIN_CELLSZW, Mspinpcellszw);           //~@@@@R~
//    DDX_Control(pDX, IDC_SPIN_CELLSZH, Mspinpcellszh);           //~@@@@R~
//    DDX_Control(pDX, IDC_EDIT_CELLSZW, Meditpcellszw);           //~@@@@R~
//    DDX_Control(pDX, IDC_EDIT_CELLSZH, Meditpcellszh);           //~@@@@R~
//    DDX_Control(pDX, IDC_COMBO_FONTSTYLE, Mcombofontstyle);      //~@@@@R~
//    DDX_Control(pDX, IDC_CHECK_PFONTSZ, Mcheckpfontsz);          //~@@@@R~
//    DDX_Control(pDX, IDC_EDIT_PFONTSZH, Meditpfontszh);          //~@@@@R~
//    DDX_Control(pDX, IDC_EDIT_PFONTSZW, Meditpfontszw);          //~@@@@R~
//    DDX_Control(pDX, IDC_SPIN_ROW, Mspinrow);                    //~@@@@R~
//    DDX_Control(pDX, IDC_SPIN_PFONTSZH, Mspinpfontszh);          //~@@@@R~
//    DDX_Control(pDX, IDC_SPIN_PFONTSZW, Mspinpfontszw);          //~@@@@R~
//    DDX_Control(pDX, IDC_SPIN_COL, Mspincol);                    //~@@@@R~
//    DDX_Control(pDX, IDC_PREVIEW_NEXTPAGE, Mbuttonpreviewnextpage);//~@@@@R~
//    DDX_Control(pDX, IDC_EDIT_CURPAGE, Meditcurpage);            //~@@@@R~
//    DDX_Control(pDX, IDC_PREVIEW_PREVPAGE, Mbuttonpreviewprevpage);//~@@@@R~
//    DDX_Control(pDX, IDC_CHECK_FULLPAGE, Mcheckfullpage);        //~@@@@R~
//    DDX_Control(pDX, IDC_CHECK_LANDSCAPE, Mchecklandscape);      //~@@@@R~
//    DDX_Control(pDX, IDC_PRINT, Mbuttonprint);                   //~@@@@R~
//    DDX_Control(pDX, IDC_PREVIEW, Mbuttonpreview);               //~@@@@R~
//    DDX_Control(pDX, IDC_CHECK_WWSCRPRT, Mcheckwwscrprt);        //~@@@@R~
//    DDX_Control(pDX, IDC_EDIT_FILENAME, Meditfilename);          //~@@@@R~
//    DDX_Control(pDX, IDC_EDIT_MAXCOLROW, Meditmaxcolrow);        //~@@@@R~
//    DDX_Control(pDX, IDC_EDIT_MAXLRECL, Meditmaxlrecl);          //~@@@@R~
//    DDX_Control(pDX, IDC_STATIC_PREVIEW, Mstaticpreview);        //~@@@@R~
//    DDX_Control(pDX, IDC_EDIT_2P, Medit2p);                      //~@@@@R~
//    DDX_Control(pDX, IDC_CHECK_FOOTER, Mcheckfooter);            //~@@@@R~
//    DDX_Control(pDX, IDC_CHECK_SYSTIME, Mchecksystime);          //~@@@@R~
//    DDX_Control(pDX, IDC_CHECK_LINENUMBER, Mchecklinenumber);    //~@@@@R~
//    DDX_Control(pDX, IDC_CHECK_FILETIME, Mcheckfiletime);        //~@@@@R~
//    DDX_Control(pDX, IDC_CHECK_HEADER, Mcheckheader);            //~@@@@R~
//    DDX_Control(pDX, IDC_CHECK_2P, Mcheck2p);                    //~@@@@R~
//    DDX_Control(pDX, IDC_EDIT_TOP, Medittop);                    //~@@@@R~
//    DDX_Control(pDX, IDC_EDIT_RIGHT, Meditright);                //~@@@@R~
//    DDX_Control(pDX, IDC_EDIT_ROW, Meditrow);                    //~@@@@R~
//    DDX_Control(pDX, IDC_EDIT_LEFT, Meditleft);                  //~@@@@R~
//    DDX_Control(pDX, IDC_EDIT_COLUMN, Meditcolumn);              //~@@@@R~
//    DDX_Control(pDX, IDC_EDIT_BOTTOM, Meditbottom);              //~@@@@R~
//    DDX_Control(pDX, IDC_COMBO_FORM, Mcombo_form);               //~@@@@R~
//    DDX_Check(pDX, IDC_CHECK_2P, M2p);                           //~@@@@R~
//    DDX_Check(pDX, IDC_CHECK_HEADER, Mheader);                   //~@@@@R~
//    DDX_Check(pDX, IDC_CHECK_FOOTER, Mfooter);                   //~@@@@R~
//    DDX_Check(pDX, IDC_CHECK_LINENUMBER, Mlinenumber);           //~@@@@R~
//    DDX_Check(pDX, IDC_CHECK_FILETIME, Mfiletime);               //~@@@@R~
//    DDX_Check(pDX, IDC_CHECK_SYSTIME, Msystime);                 //~@@@@R~
//    DDX_Text(pDX, IDC_EDIT_COLUMN, Mpagecol);                    //~@@@@R~
//    DDV_MinMaxInt(pDX, Mpagecol, PRINTCOL_MIN, PRINTCOL_MAX);    //~@@@@R~
//    DDX_Text(pDX, IDC_EDIT_ROW, Mpagerow);                       //~@@@@R~
//    DDV_MinMaxInt(pDX, Mpagerow, PRINTROW_MIN, PRINTROW_MAX);    //~@@@@R~
//    DDX_Text(pDX, IDC_EDIT_BOTTOM, Mmarginb);                    //~@@@@R~
//    DDV_MinMaxInt(pDX, Mmarginb, 0, 1000);                       //~@@@@R~
//    DDX_Text(pDX, IDC_EDIT_LEFT, Mmarginl);                      //~@@@@R~
//    DDV_MinMaxInt(pDX, Mmarginl, 0, 1000);                       //~@@@@R~
//    DDX_Text(pDX, IDC_EDIT_RIGHT, Mmarginr);                     //~@@@@R~
//    DDV_MinMaxInt(pDX, Mmarginr, 0, 1000);                       //~@@@@R~
//    DDX_Text(pDX, IDC_EDIT_TOP, Mmargint);                       //~@@@@R~
//    DDV_MinMaxInt(pDX, Mmargint, 0, 1000);                       //~@@@@R~
//    DDX_Text(pDX, IDC_EDIT_2P, M2pcol);                          //~@@@@R~
//    DDV_MinMaxInt(pDX, M2pcol, 0, 100);                          //~@@@@R~
//    DDX_Check(pDX, IDC_CHECK_WWSCRPRT, Mwwscrprt);               //~@@@@R~
//    DDX_Text(pDX, IDC_EDIT_CURPAGE, Mcurpage);                   //~@@@@R~
//    DDX_Text(pDX, IDC_EDIT_PFONTSZH, Mpfontszh);                 //~@@@@R~
//    DDV_MinMaxInt(pDX, Mpfontszh, PRINTFONTSZH_MIN, PRINTFONTSZH_MAX);//~@@@@R~
//    DDX_Text(pDX, IDC_EDIT_PFONTSZW, Mpfontszw);                 //~@@@@R~
//    DDV_MinMaxInt(pDX, Mpfontszw, PRINTFONTSZW_MIN, PRINTFONTSZW_MAX);//~@@@@R~
//    DDX_Check(pDX, IDC_CHECK_PFONTSZ, Mchkpfontsz);              //~@@@@R~
//    DDX_Text(pDX, IDC_EDIT_CELLSZH, Mpcellszh);                  //~@@@@R~
//    DDV_MinMaxInt(pDX, Mpcellszh, PRINTCELLSZH_MIN, PRINTCELLSZH_MAX);//~@@@@R~
//    DDX_Text(pDX, IDC_EDIT_CELLSZW, Mpcellszw);                  //~@@@@R~
//    DDV_MinMaxInt(pDX, Mpcellszw, PRINTCELLSZW_MIN, PRINTCELLSZW_MAX);//~@@@@R~
//    DDX_Text(pDX, IDC_EDIT_CELLSZH_MAX, Mpcellszhmax);           //~@@@@R~
//    DDV_MinMaxInt(pDX, Mpcellszhmax, PRINTCELLSZHMAX_MIN, PRINTCELLSZHMAX_MAX);//~@@@@R~
//    //}}AFX_DATA_MAP                                             //~@@@@R~
//}                                                                //~@@@@R~


//BEGIN_MESSAGE_MAP(CWxepage, CDialog)                             //~va8aR~
//    //{{AFX_MSG_MAP(CWxepage)                                    //~va8aR~
//    ON_BN_CLICKED(IDC_PRINT, OnPrint)                            //~va8aR~
//    ON_BN_CLICKED(IDC_PREVIEW, OnPreview)                        //~va8aR~
//    ON_BN_CLICKED(IDC_PREVIEW_PREVPAGE, OnPreviewprevpage)       //~va8aR~
//    ON_BN_CLICKED(IDC_CHECK_2P, OnCheck2p)                       //~va8aR~
//    ON_BN_CLICKED(IDC_CHECK_PFONTSZ, OnCheckpfontsz)             //~va8aR~
//    ON_BN_CLICKED(IDC_CHECK_FOOTER, OnCheckFooter)               //~va8aR~
//    ON_BN_CLICKED(IDC_CHECK_HEADER, OnCheckHeader)               //~va8aR~
//    ON_BN_CLICKED(IDC_PREVIEWPRTSCR, OnPreviewprtscr)            //~va8aR~
//    ON_BN_CLICKED(IDC_PRTSCR, OnPrtscr)                          //~va8aR~
//    ON_EN_CHANGE(IDC_EDIT_CURPAGE, OnChangeEditCurpage)          //~va8aR~
//    ON_BN_CLICKED(IDC_PREVIEW_NEXTPAGE, OnPreviewNextpage)       //~va8aR~
//    ON_WM_CONTEXTMENU()                                          //~va8aR~
//    ON_WM_HELPINFO()                                             //~va8aR~
//    ON_BN_CLICKED(IDCANCEL, OnPageCancel)                        //~va8aR~
//    //}}AFX_MSG_MAP                                              //~va8aR~
//END_MESSAGE_MAP()                                                //~va8aR~

CWxepage::CWxepage(CWnd* pParent,CWxemain *Ppwxemain)              //~2B09M~
//    : CDialog(CWxepage::IDD, pParent)                            //~@@@@R~
{                                                                  //~2B09M~
	void *pfh;                                                     //~2B10I~
    int lnotype;                                                   //~2C07I~
//********************************                                 //~2B09I~
	Mpwxemain=Ppwxemain;                                           //~2B09M~
	//{{AFX_DATA_INIT(CWxepage)                                    //~2B09M~
	Mcurpage = 0;                                                  //~3104R~
	//}}AFX_DATA_INIT
//  Mformsize  =Mformtype;                                         //~v51hR~
	Mlandscape =Mpwxemain->Mlandscape;                             //~2B09M~
	Mfullpage  =Mpwxemain->Mfullpage ;                             //~2B30I~
	M2p        =Mpwxemain->M2p;                                    //~2B09M~
	Mheader    =Mpwxemain->Mheader;                                //~2B09M~
	Mfooter    =Mpwxemain->Mfooter;                                //~2B09M~
	Mlinenumber=Mpwxemain->Mlinenumber;                            //~2B09M~
	Mfiletime  =Mpwxemain->Mfiletime;                              //~2B09M~
	Msystime   =Mpwxemain->Msystime;                               //~2B09M~
	Mwwscrprt  =Mpwxemain->Mwwscrprt;                              //~2B10I~
	Mpagecol   =Mpwxemain->Mprtcol;                                //~2B09M~
	Mpagerow   =Mpwxemain->Mprtrow;                                //~2B09M~
	Mpfontszh  =Mpwxemain->Mpfontszh;                              //~v51hR~
	Mpfontszw  =Mpwxemain->Mpfontszw;                              //~v51hI~
	Mpcellszh  =Mpwxemain->Mpcellszh;                              //~v51hI~
	Mpcellszhmax  =Mpwxemain->Mpcellszhmax;                        //~v62WI~
	Mpcellszw  =Mpwxemain->Mpcellszw;                              //~v51hI~
	Mmarginb   =Mpwxemain->Mmarginb;                               //~2B09M~
	Mmarginl   =Mpwxemain->Mmarginl;                               //~2B09M~
	Mmarginr   =Mpwxemain->Mmarginr;                               //~2B09M~
	Mmargint   =Mpwxemain->Mmargint;                               //~2B09M~
	M2pcol     =Mpwxemain->Mprt2pcol;                              //~2B09M~
	Mchkpfontsz=Mpwxemain->Mchkpfontsz;                            //~v51hR~
    Mmaxlrecl=0;                                                   //~2B09I~
    Mtotlineno=0;                                                  //~2B09I~
    Mmaxpage=0;                                                    //~2B09I~
    Mcmaxcol=0;                                                    //~2B09I~
    Mcmaxrow=0;                                                    //~2B09I~
    Mprttype=0;                                                    //~2B30R~
    Mtotrow=0;                                                     //~2B09I~
	strncpy(Mformtype,Mpwxemain->Mformtype,sizeof(Mformtype));     //~2B09M~
	strncpy(Mprtfontstyle,Mpwxemain->Mprtfontstyle,sizeof(Mprtfontstyle));//~v51hI~
	*Mprtfnm=0;                                                    //~2B10I~
//  Morgprttype=wxe_prtgetfnm(Mprtfnm,&pfh,&lnotype);	//file/dir/screen//~v627R~
#ifdef W32UNICODE                                                  //~vavzI~
	*MprtfnmW=0;                                                   //~vavzI~
    Morgprttype=wxe_prtgetfnm(Mprtfnm,0,&pfh,&lnotype,MprtfnmW,sizeof(MprtfnmW),NULL/*ucsctr*/);	//file/dir/screen//~vavzI~
#else                                                              //~vavzI~
    Morgprttype=wxe_prtgetfnm(Mprtfnm,0,&pfh,&lnotype);	//file/dir/screen//~v627I~
#endif                                                             //~vavzI~
    if (Morgprttype==PRTTYPE_HCOPY)                                //~2C14R~
    {                                                              //~vavzI~
    	strcpy(Mprtfnm,PRTSCRID);                                  //~2C14I~
#ifdef W32UNICODE                                                  //~vavzI~
    	strcpyW_ASCII(MprtfnmW,PRTSCRID);                          //~vavzI~
#endif                                                             //~vavzI~
    }                                                              //~vavzI~
	Sdisplaytype=-1;                                               //~vavBI~
}                                                                  //~2B09M~
CWxepage::~CWxepage(void)                                          //~2B09R~
{                                                                  //~2B09R~
    return;                                                        //~2B09R~
}//~CWxepage                                                       //~2B09R~
/////////////////////////////////////////////////////////////////////////////
//BOOL CWxepage::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)//~2B09M~
//BOOL CWxepage::Create(CWnd* pParentWnd)                          //~@@@@R~
//{                                                                //~@@@@R~
//                                                                 //~@@@@R~
//    return CDialog::Create(IDD_PAGE_SETUP, pParentWnd);          //~@@@@R~
//}                                                                //~@@@@R~
                                                                   //~2B09M~
BOOL CWxepage::OnInitDialog()                                      //~2B09M~
{                                                                  //~2B09M~
//************************                                         //~2B09M~
//    CDialog::OnInitDialog();                                     //~@@@@R~
	DoDataExchange(FALSE);	//set handle to Mxx object             //~@@@@I~
    Mspinpfontszw.SetRange(PRINTFONTSZW_MIN,PRINTFONTSZW_MAX);     //~v51hR~
    Mspinpfontszh.SetRange(PRINTFONTSZH_MIN,PRINTFONTSZH_MAX);     //~v51hI~
    Mspinpcellszw.SetRange(PRINTCELLSZW_MIN,PRINTCELLSZW_MAX);     //~v51hR~
    Mspinpcellszh.SetRange(PRINTCELLSZH_MIN,PRINTCELLSZH_MAX);     //~v51hR~
    Mspinpcellszhmax.SetRange(PRINTCELLSZHMAX_MIN,PRINTCELLSZHMAX_MAX);//~v62WI~
    Mspincol.SetRange(PRINTCOL_MIN,PRINTCOL_MAX);                  //~v51hI~
    Mspinrow.SetRange(PRINTROW_MIN,PRINTROW_MAX);                  //~v51hI~
                                                                   //~2B09I~
    Mstaticpreview.GetClientRect(&Mpreview_rect);                  //~2B09M~
	                                                               //~2B09M~
    Mchecklandscape.SetCheck(Mlandscape);                          //~2B30R~
    Mcheckfullpage.SetCheck(Mfullpage);                            //~2B30I~
    Mcheckheader.SetCheck(Mheader);                                //~2B09M~
    Mcheckfooter.SetCheck(Mfooter);                                //~2B09M~
    Mchecklinenumber.SetCheck(Mlinenumber);                        //~2B09M~
    Mcheckfiletime.SetCheck(Mfiletime);                            //~2B09M~
    Mchecksystime.SetCheck(Msystime);                              //~2B09M~
    Mcheckwwscrprt.SetCheck(Mwwscrprt);                            //~2B10I~
    Mcheck2p.SetCheck(M2p);                                        //~2B09M~
    Mcheckpfontsz.SetCheck(Mchkpfontsz);                           //~v51hR~
	OnCheckpfontsz();		//enable/disable pfontsz,col,row       //~v51hI~
    if (!M2p)                                                      //~2B09M~
	    Medit2p.EnableWindow(FALSE);                               //~2B09M~
    if (!Mheader)                                                  //~2B09I~
	    Mcheckfiletime.EnableWindow(FALSE);                        //~2B09I~
    if (!Mfooter)                                                  //~2B09I~
	    Mchecksystime.EnableWindow(FALSE);                         //~2B09I~
    if (Morgprttype<0)	//current is not file scr                  //~2B30R~
    {                                                              //~2B10I~
	    Mbuttonprint.EnableWindow(FALSE);                          //~2B10I~
	    Mbuttonpreview.EnableWindow(FALSE);                        //~2B10I~
	    Mbuttonpreviewnextpage.EnableWindow(FALSE);                //~3104R~
	    Mbuttonpreviewprevpage.EnableWindow(FALSE);                //~3104I~
    }                                                              //~2B10I~
#ifdef W32UNICODE                                                  //~vavzI~
  if (*MprtfnmW)                                                   //~vavzI~
//  Meditfilename.SetWindowTextW(MprtfnmW);	//filename             //~vavzR~
    SetWindowTextW(HWND(Meditfilename),(LPCWSTR)MprtfnmW);	//filename//~vavzI~
  else                                                             //~vavzI~
#endif                                                             //~vavzI~
    Meditfilename.SetWindowText(Mprtfnm);	//filename             //~2C14M~
    Meditmaxlrecl.SetWindowText("page");       //max lrecl         //~2C14R~
    Initcombo();                                                   //~2B09M~
	Invalidate(FALSE);                                             //~2B09M~
	return TRUE;  // true if not set focus on the ctl              //~v65iR~
	              // false for OCX property page                   //~v65iR~
}//OnInitDialog                                                    //~2B09M~
void CWxepage::OnOK() 
{
//**********************                                           //~2B03I~
	if (getparm())                                                 //~v51hR~
    	return;                                                    //~v51hI~
	putparm();                                                     //~2B07I~
//  CDialog::OnOK();                                               //~@@@@R~
//    DestroyWindow();                                             //~vavCR~
}

void CWxepage::OnPrint() 
{
	if (getparm())                                                 //~v51hR~
    	return;                                                    //~v51hI~
	putparm();                                                     //~2B07I~
	((CMainFrame*)(Mpwxemain->Mpmainframe))->PostMessage(WM_COMMAND,ID_FILE_PRINT,0);//~2B04I~
//  CDialog::OnOK();                                               //~@@@@R~
//    DestroyWindow();                                             //~vavCR~
}
void CWxepage::OnPrtscr()                                          //~2B10M~
{                                                                  //~2B10M~
	if (getparm())                                                 //~v51hR~
    	return;                                                    //~v51hI~
	putparm();                                                     //~2B10I~
	((CMainFrame*)(Mpwxemain->Mpmainframe))->PostMessage(WM_COMMAND,ID_FILE_SCRPRT,0);//~2B10I~
//  CDialog::OnOK();                                               //~@@@@R~
//    DestroyWindow();                                             //~vavCR~
}                                                                  //~2B10M~
void CWxepage::OnPreview()                                         //~2B04M~
{                                                                  //~2B04M~
	if (getparm())                                                 //~v51hR~
    	return;                                                    //~v51hI~
    Mcurpage=1;                                                    //~3104R~
	displayform(0);     //prtfile                                  //~2B10R~
}                                                                  //~2B04M~
void CWxepage::OnPreviewprevpage()                                 //~2C14I~
{                                                                  //~2C14I~
	if (getparm())                                                 //~v51hI~
    	return;                                                    //~v51hI~
    Mcurpage--;                                                    //~3104M~
    if (Mcurpage<=0)                                               //~v51gR~
        Mcurpage=-1;    //around to max req                        //~v51gR~
	displayform(0);     //prtfile                                  //~2C14I~
}                                                                  //~2C14I~
void CWxepage::OnPreviewNextpage()                                 //~3104M~
{                                                                  //~3104M~
	if (getparm())                                                 //~v51hI~
    	return;                                                    //~v51hI~
    Mcurpage++;                                                    //~3104M~
	displayform(0);     //prtfile                                  //~3104I~
}                                                                  //~3104M~
                                                                   //~2B10M~
void CWxepage::OnPreviewprtscr()                                   //~2B10M~
{                                                                  //~2B10M~
	if (getparm())                                                 //~v51hI~
    	return;                                                    //~v51hI~
    Mcurpage=1;                                                    //~2C14R~
	displayform(1);   	//prtscr                                   //~2B10I~
}                                                                  //~2B10M~
                                                                   //~2B10M~
void CWxepage::OnCheckHeader()                                     //~2B10M~
{                                                                  //~2B10M~
    Mheader=Mcheckheader.GetCheck();                               //~2B10M~
	Mcheckfiletime.EnableWindow(Mheader);                          //~2B10M~
	                                                               //~2B10M~
}                                                                  //~2B10M~
                                                                   //~2B10M~
void CWxepage::OnCheckFooter()                                     //~2B10M~
{                                                                  //~2B10M~
    Mfooter=Mcheckfooter.GetCheck();                               //~2B10M~
	Mchecksystime.EnableWindow(Mfooter);                           //~2B10M~
	                                                               //~2B10M~
}                                                                  //~2B10M~
                                                                   //~vavBI~
void CWxepage::OnWindowPosChanged(LPWINDOWPOS Ppos)                //~vavBR~
{                                                                  //~vavBI~
//*****************                                                //~vavBI~
	UTRACEP("%s:pos=%p,hwnd=%p,insertafter=%p,flag=%x\n",UTT,Ppos,Ppos->hwnd,Ppos->hwndInsertAfter,Ppos->flags);//~vavBR~
////  hwnd=HWND(Mstaticpreview);                                   //~vavBR~
////  InvalidateRect(hwnd,NULL/*rect:full*/,FALSE/*bgerase*/);     //~vavBR~
//    Mstaticpreview.InvalidateRect(NULL/*rect:full*/,FALSE/*bgerase*/);//~vavBR~
////  UpdateWindow(hwnd);   //send WM_PAINT                        //~vavBR~
//    Mstaticpreview.UpdateWindow();   //send WM_PAINT             //~vavBR~
	if (Sdisplaytype>=0)                                           //~vavBI~
		displayform(Sdisplaytype);   	//prtscr                   //~vavBI~
}                                                                  //~vavBI~
void CWxepage::OnWindowPosChanging(LPWINDOWPOS Ppos)               //~vavBI~
{                                                                  //~vavBI~
	UTRACEP("%s:pos=%p,hwnd=%p,insertafter=%p,flag=%x\n",UTT,Ppos,Ppos->hwnd,Ppos->hwndInsertAfter,Ppos->flags);//~vavBI~
}                                                                  //~vavBI~

//**************************************************************** //~2B04I~
//*get value and set to wxemain variable                           //~2B06R~
//**************************************************************** //~2B04I~
int  CWxepage::getparm()                                           //~v51hR~
{                                                                  //~2B04I~
    char txt[80];                                                  //~2B04I~
//**********************                                           //~2B04I~
    Meditrow.GetWindowText(txt,sizeof(txt));                       //~2B04I~
    Mpagerow   =atoi(txt);                                         //~2B10R~
    Meditcolumn.GetWindowText(txt,sizeof(txt));                    //~2B04I~
    Mpagecol   =atoi(txt);                                         //~2B10R~
    Meditpfontszh.GetWindowText(txt,sizeof(txt));                  //~v51hR~
    Mpfontszh  =atoi(txt);                                         //~v51hR~
    Meditpfontszw.GetWindowText(txt,sizeof(txt));                  //~v51hI~
    Mpfontszw  =atoi(txt);                                         //~v51hI~
    Meditpcellszh.GetWindowText(txt,sizeof(txt));                  //~v51hI~
    Mpcellszh  =atoi(txt);                                         //~v51hI~
    Meditpcellszhmax.GetWindowText(txt,sizeof(txt));               //~v62WI~
    Mpcellszhmax  =atoi(txt);                                      //~v62WI~
    Meditpcellszw.GetWindowText(txt,sizeof(txt));                  //~v51hI~
    Mpcellszw  =atoi(txt);                                         //~v51hI~
    Medit2p.GetWindowText(txt,sizeof(txt));                        //~2B04I~
    M2pcol     =atoi(txt);                                         //~2B10R~
    Meditleft.GetWindowText(txt,sizeof(txt));                      //~2B04I~
    Mmarginl   =atoi(txt);                                         //~2B10R~
    Meditright.GetWindowText(txt,sizeof(txt));                     //~2B04I~
    Mmarginr   =atoi(txt);                                         //~2B10R~
    Medittop.GetWindowText(txt,sizeof(txt));                       //~2B04I~
    Mmargint   =atoi(txt);                                         //~2B10R~
    Meditbottom.GetWindowText(txt,sizeof(txt));                    //~2B04I~
    Mmarginb   =atoi(txt);                                         //~2B10R~
    Mheader    =Mcheckheader.GetCheck();                           //~2B10R~
    Mfooter    =Mcheckfooter.GetCheck();                           //~2B10R~
    Mlinenumber=Mchecklinenumber.GetCheck();                       //~2B04I~
    Mfiletime  =Mcheckfiletime.GetCheck();                         //~2B10R~
    Msystime   =Mchecksystime.GetCheck();                          //~2B10R~
    Mwwscrprt  =Mcheckwwscrprt.GetCheck();                         //~2B10R~
    M2p        =Mcheck2p.GetCheck();                               //~2B10R~
	Mlandscape =Mchecklandscape.GetCheck();                        //~2B30I~
	Mfullpage  =Mcheckfullpage.GetCheck();                         //~2B30I~
                                                                   //~2B04I~
    Mcombo_form.GetLBText(Mcombo_form.GetCurSel(),txt);            //~2B04I~
	strncpy(Mformtype,txt,sizeof(Mformtype));                      //~2B09R~
    Mcombofontstyle.GetLBText(Mcombofontstyle.GetCurSel(),txt);    //~v51hI~
	strncpy(Mprtfontstyle,txt,sizeof(Mprtfontstyle));              //~v51hI~
    if (  Mchkpfontsz                                              //~v51hI~
    	  &&  (  (Mpfontszh<PRINTFONTSZH_MIN||Mpfontszh>PRINTFONTSZH_MAX)//~v51hI~
    	       ||(Mpfontszw<PRINTFONTSZW_MIN||Mpfontszw>PRINTFONTSZW_MAX)//~v51hR~
    	       ||(Mpcellszh<PRINTCELLSZH_MIN||Mpcellszh>PRINTCELLSZH_MAX)//~v51hR~
    	       ||(Mpcellszw<PRINTCELLSZW_MIN||Mpcellszw>PRINTCELLSZW_MAX)//~v51hR~
    	       ||(!Mpcellszh && !Mpfontszh)                        //~v65iI~
              )                                                    //~v51hI~
       )                                                           //~v51hI~
    {                                                              //~v51hI~
//  	uerrmsgbox("invalid Col,Row,FontH FontW parm",0);          //~v627R~
//  	uerrmsgbox("\"Col/Row by Cell-H/W\" is checked and other corresponding parm is invalid",0);//~v65iR~
    	uerrmsgbox("FontSize/CellSize err;min/max limit or Both FontH and CellH is 0",0);//~v65iI~
        return 4;                                                  //~v51hI~
    }                                                              //~v51hI~
    return 0;                                                      //~v51hR~
}//getparm                                                         //~2B09R~
//**************************************************************** //~2B07I~
//*set parm to wxemain variable                                    //~2B07I~
//**************************************************************** //~2B07I~
void CWxepage::putparm()                                           //~2B07I~
{                                                                  //~2B07I~
//**********************                                           //~2B07I~
	strncpy(Mpwxemain->Mformtype,Mformtype,sizeof(Mpwxemain->Mformtype));//~2B09R~
	strncpy(Mpwxemain->Mprtfontstyle,Mprtfontstyle,sizeof(Mpwxemain->Mprtfontstyle));//~v51hI~
	Mpwxemain->M2p        =M2p;                                    //~2B04I~
	Mpwxemain->Mfiletime  =Mfiletime;                              //~2B04I~
	Mpwxemain->Mheader    =Mheader;                                //~2B04I~
	Mpwxemain->Mfooter    =Mfooter;                                //~2B04I~
	Mpwxemain->Mlinenumber=Mlinenumber;                            //~2B04I~
	Mpwxemain->Msystime   =Msystime;                               //~2B04I~
	Mpwxemain->Mwwscrprt  =Mwwscrprt;                              //~2B10I~
	Mpwxemain->Mprtcol    =Mpagecol;                               //~2B09R~
	Mpwxemain->Mprtrow    =Mpagerow;                               //~2B09R~
	Mpwxemain->Mpfontszh  =Mpfontszh;                              //~v51hR~
	Mpwxemain->Mpfontszw  =Mpfontszw;                              //~v51hI~
	Mpwxemain->Mpcellszh  =Mpcellszh;                              //~v51hI~
	Mpwxemain->Mpcellszhmax  =Mpcellszhmax;                        //~v62WI~
	Mpwxemain->Mpcellszw  =Mpcellszw;                              //~v51hI~
	Mpwxemain->Mprt2pcol  =M2pcol;                                 //~2B04I~
	Mpwxemain->Mmarginl   =Mmarginl;                               //~2B04I~
	Mpwxemain->Mmarginr   =Mmarginr;                               //~2B04I~
	Mpwxemain->Mmargint   =Mmargint;                               //~2B04I~
	Mpwxemain->Mmarginb   =Mmarginb;                               //~2B04I~
	Mpwxemain->Mlandscape =Mlandscape;                             //~2B04I~
	Mpwxemain->Mfullpage  =Mfullpage ;                             //~2B30I~
	Mpwxemain->Mchkpfontsz=Mchkpfontsz;                            //~v51hI~
    return;                                                        //~2B04I~
}//putparm                                                         //~2B09R~
//**************************************************************** //~2B23I~
//*save and restore wxemain parm at preview call                   //~2B23I~
//**************************************************************** //~2B23I~
void CWxepage::saverestparm(int Psavesw)                           //~2B23I~
{                                                                  //~2B23I~
//**********************                                           //~2B23I~
	if (Psavesw)                                                   //~2B23I~
    {                                                              //~2B23I~
//pagesetup parm                                                   //~2B23I~
        strncpy(Msvformtype,Mpwxemain->Mformtype,sizeof(Msvformtype));//~2B23I~
        Msv2p           =Mpwxemain->M2p        ;                   //~2B23I~
        Msvfiletime     =Mpwxemain->Mfiletime  ;                   //~2B23I~
        Msvheader       =Mpwxemain->Mheader    ;                   //~2B23I~
        Msvfooter       =Mpwxemain->Mfooter    ;                   //~2B23I~
        Msvlinenumber   =Mpwxemain->Mlinenumber;                   //~2B23I~
        Msvsystime      =Mpwxemain->Msystime   ;                   //~2B23I~
        Msvwwscrprt     =Mpwxemain->Mwwscrprt  ;                   //~2B23I~
        Msvpagecol      =Mpwxemain->Mprtcol    ;                   //~2B23I~
        Msvpagerow      =Mpwxemain->Mprtrow    ;                   //~2B23I~
        Msv2pcol        =Mpwxemain->Mprt2pcol  ;                   //~2B23I~
        Msvmarginl      =Mpwxemain->Mmarginl   ;                   //~2B23I~
        Msvmarginr      =Mpwxemain->Mmarginr   ;                   //~2B23I~
        Msvmargint      =Mpwxemain->Mmargint   ;                   //~2B23I~
        Msvmarginb      =Mpwxemain->Mmarginb   ;                   //~2B23I~
        Msvlandscape    =Mpwxemain->Mlandscape ;                   //~2B23I~
        Msvfullpage     =Mpwxemain->Mfullpage  ;                   //~2B30I~
    }                                                              //~2B23I~
    else                                                           //~2B23I~
    {                                                              //~2B23I~
        strncpy(Mpwxemain->Mformtype,Msvformtype,sizeof(Mpwxemain->Mformtype));//~2B23I~
        Mpwxemain->M2p        =Msv2p;                              //~2B23I~
        Mpwxemain->Mfiletime  =Msvfiletime;                        //~2B23I~
        Mpwxemain->Mheader    =Msvheader;                          //~2B23I~
        Mpwxemain->Mfooter    =Msvfooter;                          //~2B23I~
        Mpwxemain->Mlinenumber=Msvlinenumber;                      //~2B23I~
        Mpwxemain->Msystime   =Msvsystime;                         //~2B23I~
        Mpwxemain->Mwwscrprt  =Msvwwscrprt;                        //~2B23I~
        Mpwxemain->Mprtcol    =Msvpagecol;                         //~2B23I~
        Mpwxemain->Mprtrow    =Msvpagerow;                         //~2B23I~
        Mpwxemain->Mprt2pcol  =Msv2pcol;                           //~2B23I~
        Mpwxemain->Mmarginl   =Msvmarginl;                         //~2B23I~
        Mpwxemain->Mmarginr   =Msvmarginr;                         //~2B23I~
        Mpwxemain->Mmargint   =Msvmargint;                         //~2B23I~
        Mpwxemain->Mmarginb   =Msvmarginb;                         //~2B23I~
        Mpwxemain->Mlandscape =Msvlandscape;                       //~2B23I~
        Mpwxemain->Mfullpage  =Msvfullpage ;                       //~2B30I~
    }                                                              //~2B23I~
    return;                                                        //~2B23I~
}//putparm                                                         //~2B23I~
//**************************************************************** //~2B09I~
//*                                                                //~2B09I~
//**************************************************************** //~2B09I~
int  CWxepage::pagecount(int Phcopysw)                             //~v51hR~
{                                                                  //~2B09I~
	int formw,formh,cellh,cellw,linenofw,col2p,lnotype;            //~2C07R~
//  int pfontsz;                                                   //~v51hR~
    void *pfh;                                                     //~2B09I~
    void *pcw;                                                     //~v627I~
//*******************************                                  //~2B09I~
//  Mprttype=Mpwxemain->prtgetscrdata(Phcopysw,Mwwscrprt,&pfh,Mprtfnm,//~v627R~
#ifdef W32UNICODE                                                  //~vavzI~
    Mprttype=Mpwxemain->prtgetscrdata(Phcopysw,Mwwscrprt,&pcw,&pfh,Mprtfnm,MprtfnmW,sizeof(MprtfnmW),//~vavzI~
#else                                                              //~vavzI~
    Mprttype=Mpwxemain->prtgetscrdata(Phcopysw,Mwwscrprt,&pcw,&pfh,Mprtfnm,//~v627I~
#endif                                                             //~vavzI~
									&Mtotlineno,&Mmaxlrecl,&Mlinenosz,&Mcmaxlrecl,&lnotype);//~2C07R~
	cellh=Mpwxemain->Mcellh;                                       //~2B09I~
	cellw=Mpwxemain->Mcellw;                                       //~2B09I~
	if (Mchkpfontsz)	//fontsize specified                       //~v51hI~
    {                                                              //~v51hI~
    	cellh=Mpcellszh,cellw=Mpcellszw;                           //~v51hR~
        if (!cellh)                                                //~v51hI~
        	cellh=Mpfontszh;                                       //~v51hR~
    }                                                              //~v51hI~
    Mprtdatamaxcol=                                                //~v51hR~
    Mcmaxcol=Mpagecol;                                             //~2B09I~
    Mprtdatamaxrow=                                                //~v51hR~
    Mcmaxrow=Mpagerow;                                             //~2B09I~
    if (Mprttype==PRTTYPE_VHEXTEXT                                 //~v627R~
    ||  Mprttype==PRTTYPE_VHEXHHEX                                 //~va49I~
    ||  Mprttype==PRTTYPE_VHEXBIN)                                 //~v627R~
    {                                                              //~v627I~
        if (Mprtdatamaxrow>=3)                                     //~v627I~
            Mprtdatamaxrow=(Mprtdatamaxrow/3)*3;    //multiple of 3 line//~v627R~
    }                                                              //~v627I~
//  if (!Mcmaxcol || !Mcmaxrow)                                    //~v51hR~
    if (Mprttype>0)                                                //~v51hI~
    {                                                              //~2B09I~
      if (!Mcmaxcol || !Mcmaxrow || Mchkpfontsz)//fixed font or col/ro is 0//~v51hI~
      {                                                            //~v51hI~
		Mpwxemain->prtgetformsz(Mlandscape,Mformtype,&formw,&formh);//~2B09I~
        formw-=max(Mmarginl,MARGIN_FORM_CLIP)+max(Mmarginr,MARGIN_FORM_CLIP);//~2B24I~
        formh-=max(Mmargint,MARGIN_FORM_CLIP)+max(Mmarginb,MARGIN_FORM_CLIP);//~2B24I~
        if (Mlinenumber)                                           //~2B09I~
        	linenofw=Mlinenosz+1;                                  //~2B09I~
        else                                                       //~2B09I~
        	linenofw=0;                                            //~2B09I~
        if (M2p)                                                   //~2B09I~
            col2p=M2pcol;                                          //~2B09R~
        else                                                       //~2B09I~
            col2p=0;                                               //~2B09I~
//        if (Mchkpfontsz)//fixed font                             //~v51hR~
//            pfontsz=(Mpfontszw<<16)|Mpfontszh;  //id of fixed font//~v51hR~
//        else                                                     //~v51hR~
//            pfontsz=0;                                           //~v51hR~
    	if (Mpwxemain->prtajustcolrow(Mprttype,formw,formh,Mheader+Mfooter,cellw,cellh,//~v51hR~
//  							Mcmaxlrecl,Mtotlineno,linenofw,col2p,&Mcmaxcol,&Mcmaxrow);//~v51hR~
    							Mcmaxlrecl,Mtotlineno,linenofw,col2p,&Mcmaxcol,&Mcmaxrow,//~v51hR~
//  							Mchkpfontsz,&Mprtdatamaxcol,&Mprtdatamaxrow))//~v62WR~
    							Mchkpfontsz,Mpcellszhmax,&Mprtdatamaxcol,&Mprtdatamaxrow))//~v62WI~
      		return 4;                    	                       //~v51hR~
      }//fixed font or col/ro is 0                                 //~v51hI~
      else                                                         //~v51hI~
      {                                                            //~v51hI~
      	Mprtdatamaxcol=Mcmaxcol;                                   //~v51hR~
      	Mprtdatamaxrow=Mcmaxrow;                                   //~v51hR~
      }                                                            //~v51hI~
//  }                                                              //~v51hR~
//  if (Mprttype>0)                                                //~v51hR~
//  {                                                              //~v51hR~
//      Mmaxpage=wxe_prtgetmaxpage(pfh,&Mcmaxlrecl,&Mcmaxcol,Mcmaxrow,&Mtotrow);//~v51hR~
//      Mmaxpage=wxe_prtgetmaxpage(pfh,&Mcmaxlrecl,&Mcmaxcol,&Mprtdatamaxcol,Mprtdatamaxrow,&Mtotrow);//~v627R~
        Mmaxpage=wxe_prtgetmaxpage(pcw,pfh,&Mcmaxlrecl,&Mcmaxcol,&Mprtdatamaxcol,Mprtdatamaxrow,&Mtotrow);//~v627I~
        if (M2p)                                                   //~2B24I~
        	Mmaxpage=(Mmaxpage+1)>>1;                              //~2B24I~
    }                                                              //~2B24I~
    else                                                           //~2B10I~
    {                                                              //~2B10I~
  	 	Mtotrow=Mtotlineno;                                        //~2B10I~
    	Mmaxpage=1;                                                //~2B10I~
    }                                                              //~2B10I~
    return 0;                                                      //~v51hR~
}//pagecount                                                       //~2B09I~
//**************************************************************** //~2B03I~
//*                                                                //~2B03I~
//**************************************************************** //~2B03I~
BOOL CWxepage::Initcombo()                                         //~2B03R~
{                                                                  //~2B03I~
    int ii,formno;                                                 //~2B09R~
    char **formtbl;                                                //~2B09R~
//********************************                                 //~2B03I~
	formno=Mpwxemain->prtgetformtype(&formtbl);                    //~2B09R~
    for (ii=0;ii<formno;ii++,formtbl++)                            //~2B09R~
	    Mcombo_form.AddString(*formtbl);                           //~2B09R~
	Mcombo_form.SelectString(-1,Mformtype);                        //~2B09R~
	Mcombofontstyle.SelectString(-1,Mprtfontstyle);                //~v51hI~
	Mpwxemain->createfontlist(&Mcombofontstyle,Mprtfontstyle);     //~v51hR~
    return 0;                                                      //~2B03I~
}                                                                  //~2B03I~
//**************************************************************** //~v51hI~
void CWxepage::OnCheck2p()                                         //~2B04R~
{                                                                  //~2B04I~
    M2p=Mcheck2p.GetCheck();                                       //~2B04I~
    if (M2p)                                                       //~2B04I~
	    Medit2p.EnableWindow(TRUE);                                //~2B04I~
    else                                                           //~2B04I~
	    Medit2p.EnableWindow(FALSE);                               //~2B04I~
}                                                                  //~2B04I~
//**************************************************************** //~v51hI~
void CWxepage::OnCheckpfontsz()                                    //~v51hI~
{                                                                  //~v51hI~
    Mchkpfontsz=Mcheckpfontsz.GetCheck();                          //~v51hI~
    if (Mchkpfontsz)                                               //~v51hI~
    {                                                              //~v51hI~
//      Meditrow.EnableWindow(FALSE);                              //~v51hR~
//      Meditcolumn.EnableWindow(FALSE);                           //~v51hR~
	    Meditpfontszh.EnableWindow(TRUE);                          //~v51hR~
	    Meditpfontszw.EnableWindow(TRUE);                          //~v51hI~
	    Meditpcellszh.EnableWindow(TRUE);                          //~v51hI~
	    Meditpcellszw.EnableWindow(TRUE);                          //~v51hI~
	    Meditpcellszhmax.EnableWindow(FALSE);                      //~v62WR~
    }                                                              //~v51hI~
    else                                                           //~v51hI~
    {                                                              //~v51hI~
//      Meditrow.EnableWindow(TRUE);                               //~v51hR~
//      Meditcolumn.EnableWindow(TRUE);                            //~v51hR~
	    Meditpfontszh.EnableWindow(FALSE);                         //~v51hR~
	    Meditpfontszw.EnableWindow(FALSE);                         //~v51hI~
	    Meditpcellszh.EnableWindow(FALSE);                         //~v51hI~
	    Meditpcellszw.EnableWindow(FALSE);                         //~v51hI~
	    Meditpcellszhmax.EnableWindow(TRUE);                       //~v62WR~
    }                                                              //~v51hI~
}//OnCheckpfontsz                                                  //~v51hI~
//**************************************************************** //~2B09I~
//*                                                                //~2B09I~
//**************************************************************** //~2B09I~
void CWxepage::displaypageno(void)                                 //~2B09I~
{                                                                  //~2B09I~
    char txt[128];                                                 //~v51hR~
    int pos;                                                       //~v51hR~
//*************************                                        //~2B09I~
#ifdef W32UNICODE                                                  //~vavzI~
  if (*MprtfnmW)                                                   //~vavzI~
//  Meditfilename.SetWindowTextW(MprtfnmW);	//filename             //~vavzR~
    SetWindowTextW(HWND(Meditfilename),(LPCWSTR)MprtfnmW);	//filename//~vavzI~
  else                                                             //~vavzI~
#endif                                                             //~vavzI~
    Meditfilename.SetWindowText(Mprtfnm);	//filename             //~2B10I~
    sprintf(txt,"%d",Mcurpage);                                    //~2C14R~
    Meditcurpage.SetWindowText(txt);       //max lrecl             //~2C14I~
//  sprintf(txt,"/%d page. %d line. maxlen=%d",                    //~v56vR~
    sprintf(txt,"/%d pg. %d ln. maxln=%d",                         //~v56vI~
    		Mmaxpage,Mtotlineno,Mmaxlrecl);                        //~2C14I~
    Meditmaxlrecl.SetWindowText(txt);       //max lrecl            //~2B10R~
//    if (Mpagecol)                       //non 0 parm specified   //~v51hR~
////      *txt=0;                                                  //~v51hR~
//        col=Mpagecol;                                            //~v51hR~
//    else                                                         //~v51hR~
////      sprintf(txt,"%d",Mcmaxcol);                              //~v51hR~
//        col=Mcmaxcol;                                            //~v51hR~
////  Meditmaxcol0.SetWindowText(txt);        //calculated  maxcol when col=0//~v51hR~
//    if (Mpagerow)                                                //~v51hR~
////      *txt=0;                                                  //~v51hR~
//        row=Mpagerow;                                            //~v51hR~
//    else                                                         //~v51hR~
////      sprintf(txt,"%d",Mcmaxrow);                              //~v51hR~
//        row=Mcmaxrow;                                            //~v51hR~
////  Meditmaxrow0.SetWindowText(txt);        //calculated max row when row=0//~v51hR~
//    sprintf(txt,"( col: %d , row: %d )",col,row);                //~v51hR~
	if (Mprtdatamaxcol==Mcmaxcol)                                  //~v51hI~
    	pos=sprintf(txt,"(col: %d , ",Mcmaxcol);                   //~v51hI~
    else                                                           //~v51hI~
    	pos=sprintf(txt,"(col: %d/%d , ",Mprtdatamaxcol,Mcmaxcol); //~v51hI~
	if (Mprtdatamaxrow==Mcmaxrow)                                  //~v51hI~
    	sprintf(txt+pos,"row: %d )",Mcmaxrow);                     //~v51hI~
    else                                                           //~v51hI~
    	sprintf(txt+pos,"row: %d/%d )",Mprtdatamaxrow,Mcmaxrow);   //~v51hI~
    Meditmaxcolrow.SetWindowText(txt);        //calculated max row when row=0//~v51hI~
}//displaypageno                                                   //~2B09I~
	                                                               //~2B09M~
//**************************************************************** //~2B04I~
//*                                                                //~2B04I~
//**************************************************************** //~2B04I~
void CWxepage::displayform(int Phcopysw)                           //~2B23R~
{                                                                  //~2B04I~
#define MINPIXEL 1                                                 //~2B09R~
	COLORREF bg=RGB(180,180,180);     //gray                       //~2B04I~
	COLORREF bgf=RGB(255,255,255);     //form                      //~2B09R~
//	COLORREF txtfg=RGB(160,160,160);     //gray                    //~2B10R~//~vafhR~
	int ww,hh,formw,formh,marginx=0,marginy=0;                     //~2B23R~
	int  marginl,marginr,margint,marginb;                          //~2B23R~
    RECT formrect,drawrect;                                        //~2B23R~
    float fh,frhws,frhwf;                                          //~2B23R~
//************************                                         //~2B04I~
    UTRACEP("%s:Phcopysw=%d\n",UTT,Phcopysw);                      //~vavBI~
    if (pagecount(Phcopysw))	//parm err                         //~v51hR~
    	return;                                                    //~v51hI~
    if (Mcurpage>Mmaxpage)                                         //~2C14R~
//      Mcurpage=Mmaxpage;                                         //~v51gR~
        Mcurpage=1;                                                //~v51gI~
    else                                                           //~v51gI~
    	if (Mcurpage<0)                                            //~v51gR~
        	Mcurpage=Mmaxpage;                                     //~v51gR~
        else                                                       //~v51gI~
    		if (!Mcurpage)                                         //~v51gI~
	        	Mcurpage=1;                                        //~v51gR~
    displaypageno();                                               //~2B09R~
                                                                   //~2B09I~
//  CDC *pdc=Mstaticpreview.GetDC();                               //~@@@@R~
  	CDC *pdc=new CDC(Mstaticpreview.GetDC());                      //~@@@@R~
//  CBrush  br(bg);                                                //~@@@@R~
    CBrush  br;                                                    //~@@@@I~
    br.CreateSolidBrush(bg);                                       //~@@@@I~
    previewrectdraw(pdc,&br,&Mpreview_rect);                       //~2B09R~
//**form rectangle                                                 //~2B09M~
	Mpwxemain->prtgetformsz(Mlandscape,Mformtype,&formw,&formh);   //~2B09R~
    formrect=Mpreview_rect;                                        //~2B06I~
    marginx=MARGIN_PREVIEWBOX;                                     //~2B06I~
    marginy=MARGIN_PREVIEWBOX;                                     //~2B06I~
    formrect.top+=marginy;                                         //~2B06I~
    formrect.bottom-=marginy;                                      //~2B06I~
    formrect.left+=marginx;                                        //~2B06I~
    formrect.right-=marginx;                                       //~2B06I~
    ww=formrect.right-formrect.left;                               //~2B09R~
    hh=formrect.bottom-formrect.top;                               //~2B09R~
    frhwf=(fh=(float)formh)/formw;		//forma rate h/w           //~2B06R~
    frhws=(fh=(float)hh)/ww;		//box rate h/w                 //~2B09R~
    if (frhwf<frhws)			//screen is taller,landscape       //~2B06I~
    {                                                              //~2B06I~
        marginx=0;                                                 //~2B06I~
      	marginy=(hh-(int)(ww*frhwf))/2;                            //~2B09R~
    }                                                              //~2B06I~
    else						//sceen is portlate                //~2B06R~
    {                                                              //~2B06I~
        marginx=(ww-(int)(hh/frhwf))/2;                            //~2B09R~
        marginy=0;                                                 //~2B06I~
    }                                                              //~2B06I~
    formrect.top   +=marginy;                                      //~2B06R~
    formrect.bottom-=marginy;                                      //~2B06R~
    formrect.left  +=marginx;                                      //~2B06R~
    formrect.right -=marginx;                                      //~2B06R~
//  CBrush  brf(bgf);                                              //~2B04//~@@@@R~
    CBrush  brf;                                              //~2B04//~@@@@I~
    brf.CreateSolidBrush(bgf);                                     //~@@@@I~
    previewrectdraw(pdc,&brf,&formrect);                           //~2B09R~
//**draw area rectangle in form                                    //~2B09I~
    drawrect=formrect;                                             //~2B06I~
    ww=formrect.right-formrect.left;                               //~2B09R~
    hh=formrect.bottom-formrect.top;                               //~2B09R~
    marginl=max(Mmarginl,MARGIN_FORM_CLIP);                        //~2B23R~
    marginr=max(Mmarginr,MARGIN_FORM_CLIP);                        //~2B23I~
    margint=max(Mmargint,MARGIN_FORM_CLIP);                        //~2B23I~
    marginb=max(Mmarginb,MARGIN_FORM_CLIP);                        //~2B23I~
    drawrect.left  +=ww*marginl/formw;	//margin by box pixel      //~2B23I~
    drawrect.right -=ww*marginr/formw;	//margin by box pixel      //~2B23R~
    drawrect.top   +=hh*margint/formh;	//margin by box pixel      //~2B23R~
    drawrect.bottom-=hh*marginb/formh;	//margin by box pixel      //~2B23R~
//**draw text by rectangle                                         //~2B09I~
//#define PREVIEWTEXT                                              //~v51hR~
//#ifdef PREVIEWTEXT                                               //~v51hR~
	saverestparm(1);    //save wxemain parm                        //~2B23I~
	putparm();          //update wxemain parm                      //~2B23I~
                                                                   //~2C14I~
    Mpwxemain->prtpreview(pdc,&drawrect,Phcopysw,Mcurpage);        //~2C14R~
	saverestparm(0);    //restore wxemain parm                     //~2B23I~
//#else                                                            //~v51hR~
//    displaybyrect(pdc,int Phcopysw,&drawrect);                   //~v51hR~
//#endif                                                           //~v51hR~
    Invalidate(FALSE);                                             //~2B06M~
//  ReleaseDC(pdc);                                                //~@@@@R~
    ReleaseDC((HDC)(*pdc));                                        //~@@@@I~
	Sdisplaytype=Phcopysw;                                         //+vavBR~
    return;                                                        //~2B04I~
}//displayform                                                     //~2B04R~
                                                                   //~2B09I~
////****************************************************************//~v51hR~
////*                                                              //~v51hR~
////****************************************************************//~v51hR~
//void CWxepage::displaybyrect(CDC *Ppdc,int Phcopysw,RECT &Pdrawrect)//~v51hR~
//{                                                                //~v51hR~
//#define MINPIXEL 1                                               //~v51hR~
//    COLORREF bg=RGB(180,180,180);     //gray                     //~v51hR~
//    COLORREF bgf=RGB(255,255,255);     //form                    //~v51hR~
//    COLORREF txtfg=RGB(160,160,160);     //gray                  //~v51hR~
//    int ww,ww2,ww3,ww4,hh,hh2,hh3,marginx=0,marginy=0;           //~v51hR~
//    int  linenofw;                                               //~v51hR~
//    RECT textrect,textrect2,linenorect,hdrrect,ftrrect;          //~v51hR~
//    float fh,fw,frhwf,frhwt;                                     //~v51hR~
//    int   cmaxrow,txtw,txth,swlineno,swww,sw2p,swheader,swfooter;//~v51hR~
////************************                                       //~v51hR~
//    if (Mprttype<0) //prtscr                                     //~v51hR~
//    {                                                            //~v51hR~
//        swheader=0;                                              //~v51hR~
//        swfooter=0;                                              //~v51hR~
//        swlineno=0;                                              //~v51hR~
//        sw2p=0;                                                  //~v51hR~
//        swww=Mwwscrprt;                                          //~v51hR~
//    }                                                            //~v51hR~
//    else                                                         //~v51hR~
//    {                                                            //~v51hR~
//        swheader=Mheader;                                        //~v51hR~
//        swfooter=Mfooter;                                        //~v51hR~
//        swlineno=Mlinenumber;                                    //~v51hR~
//        sw2p=M2p;                                                //~v51hR~
//        swww=0;                                                  //~v51hR~
//    }                                                            //~v51hR~
//    textrect=Pdrawrect;                                          //~v51hR~
//    cmaxrow=Mcmaxrow+(swheader+swfooter)*2;                      //~v51hR~
//    if (swlineno)                                                //~v51hR~
//        linenofw=Mlinenosz+1;                                    //~v51hR~
//    else                                                         //~v51hR~
//        linenofw=0;                                              //~v51hR~
//    txtw=Mcmaxcol+linenofw;                                      //~v51hR~
//    if (sw2p)                                                    //~v51hR~
//        txtw+=txtw+M2pcol;      //width of 2p                    //~v51hR~
//    fw=(float)(Mpwxemain->Mcellw*txtw);                          //~v51hR~
//    fh=(float)(Mpwxemain->Mcellh*cmaxrow);                       //~v51hR~
//    frhwt=fh/fw;                                                 //~v51hR~
//    ww=textrect.right-textrect.left;                             //~v51hR~
//    hh=textrect.bottom-textrect.top;                             //~v51hR~
//    frhwf=(float)hh/ww;     //form  rate h/w in margin           //~v51hR~
//    if (frhwt>frhwf)        //text is tall                       //~v51hR~
//        textrect.right-=ww-(int)(hh/frhwt); //ajust width by form orientation//~v51hR~
//    else                                                         //~v51hR~
//        textrect.bottom-=hh-(int)(ww*frhwt);//ajust height by form orientation//~v51hR~
//    CBrush  brt(txtfg);                                          //~v51hR~
//    hh2=hh/cmaxrow; // 1line height                              //~v51hR~
//    hh3=hh*2/cmaxrow;//2line height                              //~v51hR~
//    if (hh2<MINPIXEL)                                            //~v51hR~
//        hh2=MINPIXEL;                                            //~v51hR~
//    if (hh3<=hh2+MINPIXEL)                                       //~v51hR~
//        hh3=hh2+MINPIXEL;                                        //~v51hR~
//    if (swheader)                                                //~v51hR~
//    {                                                            //~v51hR~
//        hdrrect=textrect;                                        //~v51hR~
//        hdrrect.bottom=hdrrect.top+hh2;                          //~v51hR~
//        previewrectdraw(Ppdc,&brt,&hdrrect);                     //~v51hR~
//        textrect.top+=hh3;                                       //~v51hR~
//    }                                                            //~v51hR~
//    if (swfooter)                                                //~v51hR~
//    {                                                            //~v51hR~
//        ftrrect=textrect;                                        //~v51hR~
//        ftrrect.top=ftrrect.bottom-hh2;                          //~v51hR~
//        textrect.bottom-=hh3;                                    //~v51hR~
//    }                                                            //~v51hR~
////text area                                                      //~v51hR~
//    ww=textrect.right-textrect.left;                             //~v51hR~
//    hh=textrect.bottom-textrect.top;                             //~v51hR~
//    if (sw2p)                                                    //~v51hR~
//    {                                                            //~v51hR~
//        ww4=ww*M2pcol/txtw;                                      //~v51hR~
//        if (ww4<MINPIXEL)                                        //~v51hR~
//            ww4=MINPIXEL;                                        //~v51hR~
//    }                                                            //~v51hR~
//    ww2=ww*(linenofw-1)/txtw;   //pixel for lineno fld           //~v51hR~
//    ww3=ww*linenofw/txtw;       //pixel for lineno fld+1 byte delm//~v51hR~
//    if (ww2<MINPIXEL)                                            //~v51hR~
//        ww2=MINPIXEL;                                            //~v51hR~
//    if (ww3<=ww2+MINPIXEL)                                       //~v51hR~
//        ww3=ww2+MINPIXEL;                                        //~v51hR~
//    if (swww)       //wysiwig scr prt                            //~v51hR~
//    {                                                            //~v51hR~
//        textrect.right=textrect.left+ww*Mpwxemain->Mscrcmaxcol/Mcmaxcol;//net range//~v51hR~
//        textrect.bottom=textrect.top+hh*Mpwxemain->Mscrcmaxrow/cmaxrow;//net range//~v51hR~
//    }                                                            //~v51hR~
//    else                                                         //~v51hR~
//        if (Mtotrow<Mcmaxrow)    //draw net row range for 1page  //~v51hR~
//        {                                                        //~v51hR~
//            txth=Mtotrow+(swheader+swfooter)*2;                  //~v51hR~
//            textrect.bottom=hh*txth/cmaxrow;                     //~v51hR~
//        }                                                        //~v51hR~
//    if (sw2p)                                                    //~v51hR~
//    {                                                            //~v51hR~
//        textrect2=textrect;                                      //~v51hR~
//        textrect.right=textrect.left+(ww-ww4)/2;                 //~v51hR~
//        textrect2.left=textrect.right+ww4;                       //~v51hR~
//    }                                                            //~v51hR~
//    if (swlineno)                                                //~v51hR~
//    {                                                            //~v51hR~
//        linenorect=textrect;                                     //~v51hR~
//        linenorect.right=linenorect.left+ww2;                    //~v51hR~
//        previewrectdraw(Ppdc,&brt,&linenorect);                  //~v51hR~
//        textrect.left+=ww3;                                      //~v51hR~
//    }                                                            //~v51hR~
//    previewrectdraw(Ppdc,&brt,&textrect);                        //~v51hR~
//    if (sw2p)                                                    //~v51hR~
//    {                                                            //~v51hR~
//        if (swlineno)                                            //~v51hR~
//        {                                                        //~v51hR~
//            linenorect=textrect2;                                //~v51hR~
//            linenorect.right=linenorect.left+ww2;                //~v51hR~
//            previewrectdraw(Ppdc,&brt,&linenorect);              //~v51hR~
//            textrect2.left+=ww3;                                 //~v51hR~
//        }                                                        //~v51hR~
//        previewrectdraw(Ppdc,&brt,&textrect2);                   //~v51hR~
//    }                                                            //~v51hR~
//                                                                 //~v51hR~
//    if (swfooter)                                                //~v51hR~
//        previewrectdraw(Ppdc,&brt,&ftrrect);                     //~v51hR~
//    return;                                                      //~v51hR~
//}//displaybyrect                                                 //~v51hR~
                                                                   //~2B23I~
void CWxepage::previewrectdraw(CDC *Ppdc,CBrush *Ppbrush,RECT *Pprect)//~2B09R~
{                                                                  //~2B09I~
	if (Pprect->top<0) 					Pprect->top=0;             //~2B09R~
	if (Pprect->bottom<=Pprect->top)	Pprect->bottom=Pprect->top+1;//~2B09R~
	if (Pprect->left<0) 				Pprect->left=0;            //~2B09R~
	if (Pprect->right <=Pprect->left)	Pprect->right=Pprect->left+1;//~2B09R~
//  Ppdc->FillRect(Pprect,Ppbrush);                                //~@@@@R~
    Ppdc->FillRect(Pprect,*Ppbrush);                               //~@@@@I~
    return;                                                        //~2B09I~
}//previewrectdraew                                                //~2B09R~


void CWxepage::OnChangeEditCurpage() 
{
    char txt[16];                                                  //~2C14I~
//****************************                                     //~2C14I~
	Mcurpage=atoi((Meditcurpage.GetWindowText(txt,sizeof(txt)-1),txt));//~2C14I~
}

//int CWxepage::chkinrect(CPoint point)                            //~v71AR~
char *CWxepage::chkinrect(CPoint point)                            //~v71AI~
{                                                                  //~v55DI~
//  int ctxid;                                                     //~v71AR~
    char *ctxid;                                                   //~v71AI~
    int  dbcssw;                                                   //~v55FI~
//*************************                                        //~v55DI~
    dbcssw=wxegetdbcsmode();                                       //~v55FI~
    if (chkinrectsub(point,IDC_STATIC_SIZE         )) //:    1090  //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_FORMSIZE);                       //~v55FR~
    else                                                           //~v55DI~
    if (chkinrectsub(point,IDC_STATIC_LEFT         )) //:    1092  //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_MARGINLEFT);                     //~v55FR~
    else                                                           //~v55DI~
    if (chkinrectsub(point,IDC_STATIC_RIGHT        )) //:    1092  //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_MARGINRIGHT);                    //~v55FR~
    else                                                           //~v55DI~
    if (chkinrectsub(point,IDC_STATIC_TOP          )) //:    1092  //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_MARGINTOP);                      //~v55FR~
    else                                                           //~v55DI~
    if (chkinrectsub(point,IDC_STATIC_BOTTOM       )) //:    1092  //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_MARGINBOTTOM);                   //~v55FR~
    else                                                           //~v55DI~
    if (chkinrectsub(point,IDC_STATIC_MARGIN       )) //:    1091  //~v55DM~
		ctxid=GETCTXID(dbcssw,IDH_MARGINGRP);                      //~v55FR~
    else                                                           //~v55DM~
    if (chkinrectsub(point,IDC_STATIC_FORM        ))               //~v55DM~
		ctxid=GETCTXID(dbcssw,IDH_FORMGRP);                        //~v55FR~
    else                                                           //~v55DM~
    if (chkinrectsub(point,IDC_STATIC_STYLE        )) //:    1093  //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_PRINTFONTSTYLE);                 //~v55FR~
    else                                                           //~v55DI~
    if (chkinrectsub(point,IDC_STATIC_FONTH        )) //:    1030  //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_PRINTFONTH);                     //~v55FR~
    else                                                           //~v55DI~
    if (chkinrectsub(point,IDC_STATIC_FONTW        )) //:    1030  //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_PRINTFONTW);                     //~v55FR~
    else                                                           //~v55DI~
    if (chkinrectsub(point,IDC_STATIC_CELLH        )) //:    1030  //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_PRINTCELLH);                     //~v55FR~
    else                                                           //~v55DI~
    if (chkinrectsub(point,IDC_STATIC_CELLW        )) //:    1030  //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_PRINTCELLW);                     //~v55FR~
    else                                                           //~v55DI~
    if (chkinrectsub(point,IDC_STATIC_MAXCELLH     )) //:    1030  //~v62WI~
		ctxid=GETCTXID(dbcssw,IDH_PRINTMAXCELLH);                  //~v62WI~
    else                                                           //~v62WI~
    if (chkinrectsub(point,IDC_STATIC_FONT         )) //:    1093  //~v55DM~
		ctxid=GETCTXID(dbcssw,IDH_PRINTFONTGRP);                   //~v55FR~
    else                                                           //~v55DM~
    if (chkinrectsub(point,IDC_STATIC_COL          )) //:    1099  //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_PRINTCOLCTR);                    //~v55FR~
    else                                                           //~v55DI~
    if (chkinrectsub(point,IDC_STATIC_ROW          )) //:          //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_PRINTROWCTR);                    //~v55FR~
    else                                                           //~v55DI~
    if (chkinrectsub(point,IDC_STATIC_PREVIEW      )) //:          //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_PREVIEWBOX);                     //~v55FR~
    else                                                           //~v55DI~
    if (chkinrectsub(point,IDC_STATIC_PREVIEWGRP   )) //:    1029  //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_PREVIEWGRP);                     //~v55FR~
    else                                                           //~v55DI~
        ctxid=0;                                                   //~v55DI~
    return ctxid;                                                  //~v55DI~
}//chkrect                                                         //~v55DI~
//*************************************************                //~v55DI~
//*chk screen cord is on the control rect         *                //~v55DI~
//*parm1:point by screen cord                                      //~v55DI~
//*parm2:resourceID                                                //~v55DI~
//*************************************************                //~v55DI~
int CWxepage::chkinrectsub(CPoint Ppt,int Prid)                    //~v55DR~
{                                                                  //~v55DI~
    CWnd    *pwnd;                                                 //~v55DI~
	CRect   rect;                                                  //~v55DI~
	CPoint  pt;                                                    //~v55DI~
//*************************************                            //~v55DI~
    pt=Ppt;         			//screen cord                      //~v55DI~
 #ifdef HHH                                                        //~vafhI~
	pwnd=(CWnd*)GetDlgItem(Prid);  //control window                //~v55DI~
#else           CWindow& operator =(HWND)                          //~vafhI~
                                                                   //~vafhI~
	CWindow ww=GetDlgItem(Prid);  //control window                 //~vafhR~
    pwnd=&ww;                                                      //~vafhI~
#endif                                                             //~vafhI~
	pwnd->ScreenToClient(&pt);     //by the control client cord    //~v55DI~
	pwnd->GetClientRect(&rect);    //get the client region width,height//~v55DI~
	return rect.PtInRect(pt);      //chk in the region             //~v55DI~
}                                                                  //~v55DI~

void CWxepage::OnContextMenu(CWnd* pWnd, CPoint point) 
{

    HWND hwnd;                                                     //~v55DI~
//  int   ctxid;                                                   //~v71AR~
    char *ctxid;                                                   //~v71AI~
    CPoint pt;                                                     //~v55DI~
    int  dbcssw;                                                   //~v55FI~
//******************************                                   //~v55DI~
    dbcssw=wxegetdbcsmode();                                       //~v55FI~
    hwnd=pWnd->m_hWnd;                                             //~v55DI~
    if (hwnd==this->m_hWnd)                                        //~v55DI~
    {                                                              //~v55DI~
    	pt=point;          //parnm is screen coord                 //~v55DI~
		ctxid=chkinrect(pt);                                       //~v55DI~
	}                                                              //~v55DI~
    else                                                           //~v55DI~
    if (hwnd==Mcombo_form.m_hWnd)                                  //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_FORMSIZE);                       //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==Mchecklandscape.m_hWnd)                              //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_LANDSCAPE);                      //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==Meditleft.m_hWnd)                                    //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_MARGINLEFT);                     //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==Meditright.m_hWnd)                                   //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_MARGINRIGHT);                    //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==Medittop.m_hWnd)                                     //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_MARGINTOP);                      //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==Meditbottom.m_hWnd)                                  //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_MARGINBOTTOM);                   //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==Mcombofontstyle.m_hWnd)                              //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_PRINTFONTSTYLE);                 //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==Meditpfontszh.m_hWnd || hwnd==Mspinpfontszh.m_hWnd)  //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_PRINTFONTH);                     //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==Meditpfontszw.m_hWnd || hwnd==Mspinpfontszw.m_hWnd)  //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_PRINTFONTW);                     //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==Meditpcellszh.m_hWnd || hwnd==Mspinpcellszh.m_hWnd)  //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_PRINTCELLH);                     //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==Meditpcellszhmax.m_hWnd || hwnd==Mspinpcellszhmax.m_hWnd)//~v62WR~
		ctxid=GETCTXID(dbcssw,IDH_PRINTMAXCELLH);	//help contex  //~v62WR~
    else                                                           //~v62WI~
    if (hwnd==Meditpcellszw.m_hWnd || hwnd==Mspinpcellszw.m_hWnd)  //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_PRINTCELLW);                     //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==Mcheckpfontsz.m_hWnd)                                //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_PRINTROWCOLBYCELL);              //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==Meditcolumn.m_hWnd || hwnd==Mspincol.m_hWnd)         //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_PRINTCOLCTR);                    //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==Meditrow.m_hWnd || hwnd==Mspinrow.m_hWnd)            //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_PRINTROWCTR);                    //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==Mchecklinenumber.m_hWnd)                             //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_PRINTLINESEQ);                   //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==Mcheck2p.m_hWnd)                                     //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_PRINT2P);                        //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==Medit2p.m_hWnd)                                      //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_PRINT2PSPACE);                   //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==Mcheckheader.m_hWnd)                                 //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_PRINTHEADER);                    //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==Mcheckfiletime.m_hWnd)                               //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_PRINTFILETIME);                  //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==Mcheckfooter.m_hWnd)                                 //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_PRINTFOOTER);                    //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==Mchecksystime.m_hWnd)                                //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_PRINTTIMESTAMP);                 //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==Mcheckwwscrprt.m_hWnd)                               //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_WWSCRPRT);                       //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==Mcheckfullpage.m_hWnd)                               //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_FULLPAGE);                       //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==Meditcurpage.m_hWnd)                                 //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_PREVIEWPAGENO);                  //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==Mbuttonpreview.m_hWnd)                               //~v55DR~
		ctxid=GETCTXID(dbcssw,IDH_PREVIEW);                        //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==Mbuttonpreviewnextpage.m_hWnd)                       //~v55DR~
		ctxid=GETCTXID(dbcssw,IDH_PREVIEWNEXT);                    //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==Mbuttonpreviewprevpage.m_hWnd)                       //~v55DR~
		ctxid=GETCTXID(dbcssw,IDH_PREVIEWPREV);                    //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==MbuttonPreviewPrintScr.m_hWnd)                       //~v55DR~
		ctxid=GETCTXID(dbcssw,IDH_PREVIEWPRTSCR);                  //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==Mbuttonprint.m_hWnd)                                 //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_PRINTGO);                        //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==MbuttonPrintScr.m_hWnd)                              //~v55DR~
		ctxid=GETCTXID(dbcssw,IDH_PRTSCRGO);                       //~v55FR~
    else                                                           //~v55DI~
    if (hwnd==Mbuttonok.m_hWnd)                                    //~v55DM~
		ctxid=GETCTXID(dbcssw,IDH_PRINTOK);                        //~v55FR~
    else                                                           //~v55DM~
    if (hwnd==Mbuttoncancel.m_hWnd)                                //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_PRINTCAN);                       //~v55FR~
    else                                                           //~v55DI~
        ctxid=0;                                                   //~v55DI~
    if (ctxid)                                                     //~v55DI~
//  	WinHelp(ctxid,HELP_CONTEXTPOPUP);                          //~v71AR~
		uhtmlhelp(dbcssw!=0,hwnd,ctxid,point);                     //~v71AI~
}
//************************************************                 //~v71AI~
//* F1 pressed(Mouse Rbutton is not effective for EDIT control as help popup)//~v71AI~
//************************************************                 //~v71AI~
BOOL CWxepage::OnHelpInfo(HELPINFO* pHelpInfo) 
{
    int ctlid;                                                     //~v71AR~
//  int   ctxid;                                                   //~v71AR~
    char *ctxid;                                                   //~v71AI~
    int  dbcssw;                                                   //~v55FI~
//*********************                                            //~v55DI~
    dbcssw=wxegetdbcsmode();                                       //~v55FI~
    ctlid=pHelpInfo->iCtrlId;                                      //~v55DI~
    switch(ctlid)                                                  //~v55DI~
    {                                                              //~v55DI~
    case IDC_EDIT_LEFT            ://    1037                      //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_MARGINLEFT);                     //~v55FR~
        break;                                                     //~v55DI~
    case IDC_EDIT_RIGHT           ://    1040                      //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_MARGINRIGHT);                    //~v55FR~
        break;                                                     //~v55DI~
    case IDC_EDIT_TOP             ://    1038                      //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_MARGINTOP);                      //~v55FR~
        break;                                                     //~v55DI~
    case IDC_EDIT_BOTTOM          ://    1041                      //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_MARGINBOTTOM);                   //~v55FR~
        break;                                                     //~v55DI~
    case IDC_EDIT_PFONTSZH        ://    1077                      //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_PRINTFONTH);                     //~v55FR~
        break;                                                     //~v55DI~
    case IDC_EDIT_PFONTSZW        ://    1081                      //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_PRINTFONTW);                     //~v55FR~
        break;                                                     //~v55DI~
    case IDC_EDIT_CELLSZH         ://    1084                      //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_PRINTCELLH);                     //~v55FR~
        break;                                                     //~v55DI~
    case IDC_EDIT_CELLSZH_MAX      ://                             //~v62WR~
		ctxid=GETCTXID(dbcssw,IDH_PRINTMAXCELLH);                  //~v62WR~
        break;                                                     //~v62WI~
    case IDC_EDIT_CELLSZW         ://    1085                      //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_PRINTCELLW);                     //~v55FR~
        break;                                                     //~v55DI~
    case IDC_EDIT_COLUMN          ://    1042                      //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_PRINTCOLCTR);                    //~v55FR~
        break;                                                     //~v55DI~
    case IDC_EDIT_ROW             ://    1043                      //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_PRINTROWCTR);                    //~v55FR~
        break;                                                     //~v55DI~
    case IDC_EDIT_2P              ://    1053                      //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_PRINT2PSPACE);                   //~v55FR~
        break;                                                     //~v55DI~
    case IDC_EDIT_FILENAME        ://    1060                      //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_PREVIEWFILENAME);                //~v55FR~
        break;                                                     //~v55DI~
    case IDC_EDIT_CURPAGE         ://    1068                      //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_PREVIEWPAGENO);                  //~v55FR~
        break;                                                     //~v55DI~
    case IDC_EDIT_MAXLRECL        ://    1054                      //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_PREVIEWMAXLRECL);                //~v55FR~
        break;                                                     //~v55DI~
    case IDC_EDIT_MAXCOLROW       ://    1058                      //~v55DI~
		ctxid=GETCTXID(dbcssw,IDH_PREVIEWMAXCOLROW);               //~v55FR~
        break;                                                     //~v55DI~
    default:                                                       //~v55DI~
        ctxid=0;                                                   //~v55DI~
    }                                                              //~v55DI~
    if (ctxid)                                                     //~v55DI~
//  	WinHelp(ctxid,HELP_CONTEXTPOPUP);                          //~v71AR~
		uhtmlhelp(dbcssw!=0,0,ctxid,pHelpInfo->MousePos);          //~v71AI~
//  return CDialog::OnHelpInfo(pHelpInfo);                         //~@@@@R~
    return TRUE;                                                   //~@@@@I~
}//OnHelpInfo                                                      //~v55DR~

void CWxepage::OnPageCancel() 
{
    UTRACEP("%s:\n",UTT);                                          //~vavBI~
	Mpwxemain->afterprint(2);	//cancel print work                //~va8aI~
//  CDialog::OnCancel();                                           //~@@@@R~
//    DestroyWindow();                                             //~vavCR~
}
