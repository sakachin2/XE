//*CID://+@@@@R~:                             update#=   52;       //~@@@@I~
//*from MFC include                                                //~@@@@I~
typedef DWORD DROPEFFECT;                                          //~@@@@I~
                                                                   //~@@@@I~
#ifndef afx_msg                                                    //~@@@@I~
#define afx_msg         // intentional placeholder                 //~@@@@I~
#endif                                                             //~@@@@I~
#ifndef AFX_MSG_CALL                                               //~@@@@I~
#define AFX_MSG_CALL        // intentional placeholder             //~@@@@I~
#endif                                                             //~@@@@I~
                                                                   //~@@@@I~
#ifndef COleDataObject                                             //~@@@@I~
#define COleDataObject IDataObject	//drag & drop                  //~@@@@I~
#endif                                                             //~@@@@I~
#ifndef CWnd                                                       //~@@@@I~
#define CWnd CWindow                                               //~@@@@R~
#endif                                                             //~@@@@I~
#ifndef CView                                                      //~@@@@I~
#define CView CWxeView                                                   //~@@@@R~
#endif                                                             //~@@@@I~
#ifndef CPrintInfo                                                 //+@@@@I~
#define CPrintInfo CPrintJobInfo                                   //+@@@@I~
#endif                                                             //+@@@@I~
#ifndef CSpinButtonCtrl                                            //~@@@@I~
#define CSpinButtonCtrl CUpDownCtrl                                //~@@@@I~
#endif                                                             //~@@@@I~
#ifndef CSliderCtrl                                                //~@@@@I~
#define CSliderCtrl CTrackBarCtrl                                  //~@@@@I~
#endif                                                             //~@@@@I~
#ifndef CDataExchange                                              //~@@@@I~
#define CDataExchange CWinDataExchange                             //~@@@@I~
#endif                                                             //~@@@@I~
#ifndef CMenu                                                      //~@@@@I~
#define CMenu CMenuHandle                                          //~@@@@I~
#endif                                                             //~@@@@I~
#ifndef CFrameWnd                                                  //~@@@@I~
#define CFrameWnd CMainFrame                                       //~@@@@I~
#endif                                                             //~@@@@I~
//******************************************************           //~@@@@I~
//*predefine for compile err by recursive include                  //~@@@@M~
class CMainFrame;                                                  //~@@@@M~
class CWxeView;                                                    //~@@@@M~
class CWxeApp;                                                     //~@@@@M~
//******************************************************           //~@@@@I~
                                                                   //~@@@@I~
//* dummy for wxedoc                                               //~@@@@I~
class CDocument                                                    //~@@@@I~
{                                                                  //~@@@@I~
};                                                                  //~@@@@I~
class CCmdTarget                                                   //~@@@@I~
{                                                                  //~@@@@I~
};                                                                 //~@@@@I~
class CDumpContext                                               //~@@@@I~
{                                                                  //~@@@@I~
};                                                                 //~@@@@I~
class CWinApp                                                      //~@@@@I~
{                                                                 //~@@@@I~
};                                                                 //~@@@@I~
class CArchive                                                     //~@@@@I~
{                                                                  //~@@@@I~
};                                                                 //~@@@@I~
class CCmdUI                                                       //~@@@@I~
{                                                                  //~@@@@I~
	int resID;
	CUpdateUIBase *pframewnd;//~@@@@I~
public:                                                            //~@@@@I~
    CCmdUI::CCmdUI(CMainFrame *Pframewnd,int PresID)               //~@@@@R~
    {                                                              //~@@@@I~
    	resID=PresID;
		pframewnd=(CUpdateUIBase*)Pframewnd;//~@@@@I~
    }                                                              //~@@@@I~
    void CCmdUI::Enable(BOOL Penable)                              //~@@@@R~
    {                                                              //~@@@@I~
    	pframewnd->UIEnable(resID,Penable);                        //~@@@@R~
    }                                                              //~@@@@I~
};                                                                 //~@@@@I~
struct AFX_CMDHANDLERINFO                                          //~@@@@M~
{                                                                  //~@@@@M~
    CCmdTarget* pTarget;                                           //~@@@@M~
    void (AFX_MSG_CALL CCmdTarget::*pmf)(void);                    //~@@@@M~
};                                                                 //~@@@@M~
                                                                   //~@@@@I~
#define DECLARE_DYNCREATE(class_name)	//nop                      //~@@@@I~
#define DECLARE_MESSAGE_MAP()           //nop                      //~@@@@I~
#define IMPLEMENT_DYNCREATE(class_name, base_class_name)           //~@@@@I~
#define BEGIN_MESSAGE_MAP(class_name, base_class_name) BEGIN_MSG_MAP_EX(class_name)//~@@@@R~
#define END_MESSAGE_MAP() END_MSG_MAP()                            //~@@@@I~
#define ON_COMMAND(id,func)  COMMAND_ID_HANDLER_EX(id,func)        //~@@@@I~
#define ON_UPDATE_COMMAND_UI(id,func)  COMMAND_ID_HANDLER_EX(id,func)//~@@@@I~
//*Control wParamHigh:notification,wparamLow:CotrolID lParam:Window handle//~@@@@I~
#define ON_BN_CLICKED(id,func) COMMAND_HANDLER_EX(id,BN_CLICKED,func)//~@@@@I~
#define ON_EN_CHANGE(id,func) COMMAND_HANDLER_EX(id,EN_CHANGE,func)//~@@@@I~
#define ON_CBN_SELCHANGE(id,func) COMMAND_HANDLER_EX(id,CBN_SELCHANGE,func)//~@@@@I~
//************************************                             //~@@@@I~
//*mfc\afxres.h ***                                                //~@@@@R~
#define ID_INDICATOR_EXT                0xE700  // extended selection indicator//~@@@@I~
#define ID_INDICATOR_CAPS               0xE701  // cap lock indicator//~@@@@I~
#define ID_INDICATOR_NUM                0xE702  // num lock indicator//~@@@@I~
#define ID_INDICATOR_SCRL               0xE703  // scroll lock indicator//~@@@@I~
#define ID_INDICATOR_OVR                0xE704  // overtype mode indicator//~@@@@I~
#define ID_INDICATOR_REC                0xE705  // record mode indicator//~@@@@I~
#define ID_INDICATOR_KANA               0xE706  // kana lock indicator//~@@@@I~
                                                                   //~@@@@I~
#define ID_SEPARATOR                    0   // special separator value//~@@@@I~
//*mfc\afxwin.h ***                                                //~@@@@I~
#define FWS_ADDTOTITLE  0x00008000L // modify title based on content//~@@@@I~
//************                                                     //~@@@@R~
CWxeApp* AfxGetApp();                                              //~@@@@I~
