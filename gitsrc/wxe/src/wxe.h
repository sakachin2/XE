//*CID://+@@@@R~:                             update#=   29;       //~@@@@R~
//********************************************************         //~4304I~
//********************************************************         //~4304I~
// wxe.h :                                                         //~5C21R~
//

#if !defined(AFX_WXE_H__F3393123_AD0D_11D6_8C9B_00909951ADD0__INCLUDED_)
#define AFX_WXE_H__F3393123_AD0D_11D6_8C9B_00909951ADD0__INCLUDED_

//#if _MSC_VER > 1000                                              //~@@@@R~
#pragma once
//#endif // _MSC_VER > 1000                                        //~@@@@R~

//#ifndef __AFXWIN_H__                                             //~@@@@R~
//    #error include 'stdafx.h' before including this file for PCH //~@@@@R~
//#endif                                                           //~@@@@R~

#include <stdafx.h>       // main symbol                           //~@@@@R~
#include <MainFrm.h>       // main symbol                          //~@@@@I~
#include "resource.h"       // main symbol                         //~@@@@I~
#include <wxexei.h>       // main symbol                           //+@@@@I~

/////////////////////////////////////////////////////////////////////////////
// CWxeApp:
//

class CWxeApp : public CWinApp
{
public:
    CWxeApp()                                                      //~@@@@I~
    {                                                              //~@@@@I~
    //************************                                     //~@@@@I~
        if (wxe_preinit(__argc,__argv))                            //~@@@@I~
            exit(9);                                               //~@@@@I~
        Mappinitsw=0;                                              //~@@@@I~
        Mshowmaxsw=0;                                              //~@@@@I~
    }                                                              //~@@@@I~
	void initprntdlg(void);                                        //~3116I~
    int Mappinitsw;                                                //~2A10I~
    int Mshowmaxsw; //at init CMainfrm set from ini file           //~2A19I~
    CFrameWnd *Mpmainframe; 	//at init CMainfrm set from ini file//~3103I~
    void *Mppdevmode;                                              //~3105I~

// override                                                        //~5C21R~
	//{{AFX_VIRTUAL(CWxeApp)
	public:
//  virtual BOOL InitInstance();                                   //~@@@@R~
    BOOL InitInstance(CMainFrame *Pmainframe);                     //~@@@@R~
	//}}AFX_VIRTUAL

// imple                                                           //~5C21R~
	//{{AFX_MSG(CWxeApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
///////////////////////////////////////////////////////////////////////////////~@@@@I~
// uniq   CWxeApp object                                           //~@@@@I~
                                                                   //~@@@@I~
//CWxeApp theApp;                                                  //~@@@@R~
CDC     GmemDC;                                                    //~@@@@I~
///////////////////////////////////////////////////////////////////////////////~@@@@I~
// CWxeApp class init                                              //~@@@@I~
                                                                   //~@@@@I~
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_WXE_H__F3393123_AD0D_11D6_8C9B_00909951ADD0__INCLUDED_)
