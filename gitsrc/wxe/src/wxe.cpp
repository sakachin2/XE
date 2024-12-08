//*CID://+vavAR~:                             update#=   32;       //~vavAR~
//****************************************************************************//~vavAI~
//vavA:140429 (wxe)crash by write protection at CAccelerator,#ifdef W32UNICODE,wxemain class is expanded(class size differ on each compilation)//~vavAI~
//****************************************************************************//~vavAI~
// wxe.cpp : main source file for wxe.exe
//
#pragma once                                                       //~@@@@I~

#include <stdafx.h>

#define NO_MACRO_REDIRECT                                          //+vavAI~
#include <ulib.h>                                                  //~vavAR~
//#include <atlframe.h>                                            //~@@@@R~
//#include <atlctrls.h>                                            //~@@@@R~
//#include <atldlgs.h>                                             //~@@@@R~
//#include <atlctrlw.h>                                            //~@@@@R~
//#include <atlribbon.h>                                           //~@@@@R~

//#include "Ribbon.h"                                              //~@@@@R~

#include "resource.h"

//#include "wxeView.h"                                             //~@@@@R~
#include <aboutdlg.h>
#include <MainFrm.h>
#include <wxe.h>                                                   //~@@@@I~

CAppModule _Module;
void preinit();                                                    //~@@@@R~

int Run(LPTSTR /*lpstrCmdLine*/ = NULL, int nCmdShow = SW_SHOWDEFAULT)
{
    CWxeApp *papp=AfxGetApp();   //construct CWxeApp,preinit call  //~@@@@I~
	CMessageLoop theLoop;
	_Module.AddMessageLoop(&theLoop);

	CMainFrame wndMain;

	if(wndMain.CreateEx() == NULL)
	{
		ATLTRACE(_T("Main window creation failed!\n"));
		return 0;
	}
    papp->InitInstance(&wndMain);    //menubat icon                //~@@@@R~
	wndMain.ShowWindow(nCmdShow);

	int nRet = theLoop.Run();

	_Module.RemoveMessageLoop();
	return nRet;
}

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPTSTR lpstrCmdLine, int nCmdShow)
{
	HRESULT hRes = ::CoInitialize(NULL);
// If you are running on NT 4.0 or higher you can use the following call instead to 
// make the EXE free threaded. This means that calls come in on a random RPC thread.
//	HRESULT hRes = ::CoInitializeEx(NULL, COINIT_MULTITHREADED);
	ATLASSERT(SUCCEEDED(hRes));

	// this resolves ATL window thunking problem when Microsoft Layer for Unicode (MSLU) is used
	::DefWindowProc(NULL, 0, 0, 0L);

	AtlInitCommonControls(ICC_COOL_CLASSES | ICC_BAR_CLASSES);	// add flags to support other controls

	hRes = _Module.Init(NULL, hInstance);
	ATLASSERT(SUCCEEDED(hRes));

	int nRet = Run(lpstrCmdLine, nCmdShow);

	_Module.Term();
	::CoUninitialize();

	return nRet;
}
///////////////////////////////////////////////////////////////////////////////~@@@@I~
//*******************                                              //~@@@@I~
CWxeApp* AfxGetApp()                                               //~@@@@I~
{                                                                  //~@@@@I~
	static CWxeApp* papp;                                          //~@@@@I~
    if (!papp)                                                     //~@@@@I~
    	papp=new CWxeApp();                                        //~@@@@I~
    return papp;                                                   //~@@@@I~
}                                                                  //~@@@@I~
//BOOL CWxeApp::InitInstance()                                     //~@@@@I~
BOOL CWxeApp::InitInstance(CMainFrame *Pmainframe)                 //~@@@@I~
{                                                                  //~@@@@I~
	int usemk,useact;                                              //~@@@@I~
//  char newtemp[_MAX_PATH];                                       //~@@@@R~
//  int oletimeout=600000;	//10min by milisec                     //~@@@@R~
//*****************************************                        //~@@@@I~
	Mpmainframe=Pmainframe;                                        //~@@@@I~
//    if (!AfxOleInit())                                           //~@@@@R~
//    {                                                            //~@@@@R~
//        AfxMessageBox("AfxOleInit Error!");                      //~@@@@R~
//        return FALSE;                                            //~@@@@R~
//    }                                                            //~@@@@R~
  	OleInitialize (NULL); // required fro dragout                  //~@@@@I~
//    AfxOleGetMessageFilter()->SetMessagePendingDelay(oletimeout);//~@@@@R~
//                                                                 //~@@@@R~
//#ifdef _AFXDLL                                                   //~@@@@R~
//    Enable3dControls();     // dll                               //~@@@@R~
//#else                                                            //~@@@@R~
//    Enable3dControlsStatic();   // static link                   //~@@@@R~
//#endif                                                           //~@@@@R~
//                                                                 //~@@@@R~
//    SetRegistryKey(_T("Local AppWizard-Generated Applications"));//~@@@@R~
//                                                                 //~@@@@R~
//    LoadStdProfileSettings(10);  // std INI file option load  (contains MRU)//~@@@@R~
//                                                                 //~@@@@R~
//                                                                 //~@@@@R~
//    CSingleDocTemplate* pDocTemplate;                            //~@@@@R~
//    pDocTemplate = new CSingleDocTemplate(                       //~@@@@R~
//        IDR_MAINFRAME,                                           //~@@@@R~
//        RUNTIME_CLASS(CWxeDoc),                                  //~@@@@R~
//        RUNTIME_CLASS(CMainFrame),       // main SDI frame window//~@@@@R~
//        RUNTIME_CLASS(CWxeView));                                //~@@@@R~
//    AddDocTemplate(pDocTemplate);                                //~@@@@R~
//                                                                 //~@@@@R~
//    CCommandLineInfo cmdInfo;                                    //~@@@@R~
//    ParseCommandLine(cmdInfo);                                   //~@@@@R~
//                                                                 //~@@@@R~
////  cmdInfo.m_nShellCommand=CCommandLineInfo::FileNew;  //force new,pass filename to xe at initcall//~@@@@R~
//    if (cmdInfo.m_nShellCommand==CCommandLineInfo::FileNew)  //no file parm//~@@@@R~
//    {                                                            //~@@@@R~
//        cmdInfo.m_nShellCommand=CCommandLineInfo::FileOpen;      //~@@@@R~
//        uallocdummynewfile(newtemp); //alocate dummy file        //~@@@@R~
//        cmdInfo.m_strFileName=CString(newtemp);                  //~@@@@R~
//    }                                                            //~@@@@R~
//    if (!ProcessShellCommand(cmdInfo))                           //~@@@@R~
//        return FALSE;                                            //~@@@@R~
    initprntdlg();                                                 //~@@@@I~
    Mappinitsw=1;                                                  //~@@@@I~
                                                                   //~@@@@I~
//load accelerator                                                 //~@@@@I~
	usemk=useact=-1;			//init id                          //~@@@@I~
    ((CMainFrame*)Mpmainframe)->Loadact(useact);	//-1 initsw    //~@@@@I~
    ((CMainFrame*)Mpmainframe)->updatemainmenu(usemk);	//-1 initsw//~@@@@I~
//  HICON   icon = LoadIcon( IDR_MAINFRAME );                         // <---//~@@@@I~
    CIcon  cicon;                                                  //~@@@@I~
    HICON   icon = cicon.LoadIcon( IDR_MAINFRAME );                         // <---//~@@@@I~
    CMainFrame *m_pMainWnd=Mpmainframe;	                           //~@@@@I~
//  m_pMainWnd->SetIcon(icon,TRUE); //TRUE:big(32bit) icon         //~@@@@I~
    m_pMainWnd->SetIcon(icon,FALSE); //FALS:big(16bit) icon,TRUE is not effective//~@@@@I~
    if (Mshowmaxsw)                                                //~@@@@I~
		m_pMainWnd->ShowWindow(SW_SHOWMAXIMIZED);                  //~@@@@I~
    else                                                           //~@@@@I~
		m_pMainWnd->ShowWindow(SW_SHOW);                           //~@@@@I~
	m_pMainWnd->UpdateWindow();                                    //~@@@@I~
                                                                   //~@@@@I~
	return TRUE;                                                   //~@@@@I~
}                                                                  //~@@@@I~
                                                                   //~@@@@I~
//***************************************************************************//~@@@@I~
//*setup printer devmode becuase it is not initailized until 1st print req//~@@@@I~
//*orientation and form change is set to it by wxeprt.cpp          //~@@@@R~
//***************************************************************************//~@@@@I~
void CWxeApp::initprntdlg(void)                                    //~@@@@I~
{                                                                  //~@@@@I~
//    Mppdevmode=&m_hDevMode; //wxeprt use                         //~@@@@R~
//    CPrintDialog pd(TRUE);                                       //~@@@@R~
//    pd.GetDefaults();                                            //~@@@@R~
//    m_hDevMode = pd.m_pd.hDevMode;                               //~@@@@R~
//    m_hDevNames = pd.m_pd.hDevNames;                             //~@@@@R~
}//initprntdlg                                                     //~@@@@I~
