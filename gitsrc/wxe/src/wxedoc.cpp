//*CID://+vak7R~:                             update#=   52;       //~vak7R~
//*******************************************************************//~v51eI~
//vak7:130906 redirect memcpy to memmove when overlaped            //~vak7I~
//v63h:050504 (WXE)support DragOut                                 //~v63hI~
//v51e:030517 (WXE:BUG)drug drop need svreen invalidate            //~v51eI~
//*******************************************************************//~v51eI~
// wxeDoc.cpp : CWxeDoc class                                      //~v63hR~
//

#include "stdafx.h"
                                                                   //~2A09I~
#define NO_MACRO_REDIRECT                                          //+vak7I~
#include <ulib.h>                                                  //~vak7I~
#include "utrace.h"                                                //~2A09I~
                                                                   //~2A09I~
#include "wxe.h"
#include "wxedef.h"                                                //~2811I~

#include "wxefile.h"                                               //~2817M~
#include "wxeDoc.h"
#include "wxecsub.h"                                               //~2A12I~

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWxeDoc

IMPLEMENT_DYNCREATE(CWxeDoc, CDocument)

//BEGIN_MESSAGE_MAP(CWxeDoc, CDocument)                            //~@@@@R~
//    //{{AFX_MSG_MAP(CWxeDoc)                                     //~@@@@R~
//    //}}AFX_MSG_MAP                                              //~@@@@R~
//END_MESSAGE_MAP()                                                //~@@@@R~

/////////////////////////////////////////////////////////////////////////////
// CWxeDoc constructor                                             //~v63hR~

CWxeDoc::CWxeDoc()
{
    Mcmdid=0;                                                      //~2A09I~
    Mpview=0;                                                      //~2A10I~
    Mpapp=(CWxeApp*)AfxGetApp();                                   //~2A10R~
    Mwxefile.init(this);                                           //~2817R~
}
void CWxeDoc::init(CView *Ppview)                                  //~v51eR~
{                                                                  //~v51eI~
    Mpview=Ppview;                                                 //~v51eI~
}                                                                  //~v51eI~

CWxeDoc::~CWxeDoc()
{
}



/////////////////////////////////////////////////////////////////////////////
// CWxeDoc                                                         //~v63hR~
//void CWxeDoc::Serialize(CArchive& ar)                            //~@@@@R~
//{                                                                //~@@@@R~
//    if (ar.IsStoring())                                          //~@@@@R~
//    {                                                            //~@@@@R~
//    }                                                            //~@@@@R~
//    else                                                         //~@@@@R~
//    {                                                            //~@@@@R~
//    }                                                            //~@@@@R~
//}                                                                //~@@@@R~
/////////////////////////////////////////////////////////////////////////////

//#ifdef _DEBUG                                                    //~@@@@R~
//void CWxeDoc::AssertValid() const                                //~@@@@R~
//{                                                                //~@@@@R~
//    CDocument::AssertValid();                                    //~@@@@R~
//}                                                                //~@@@@R~

//void CWxeDoc::Dump(CDumpContext& dc) const                       //~@@@@R~
//{                                                                //~@@@@R~
//    CDocument::Dump(dc);                                         //~@@@@R~
//}                                                                //~@@@@R~
//#endif //_DEBUG                                                  //~@@@@R~

/////////////////////////////////////////////////////////////////////////////
// CWxeDoc ƒRƒ}ƒ“ƒh

//BOOL CWxeDoc::OnNewDocument()                                    //~@@@@R~
BOOL CWxeDoc::OnNewDocument(char *Pfnm)                            //~@@@@I~
{                                                                  //~2A10M~
//  char newfnm[_MAX_PATH];                                        //~@@@@R~
//*********************                                            //~2A12I~
//    if (!CDocument::OnNewDocument())                             //~@@@@R~
//        return FALSE;                                            //~@@@@R~
                                                                   //~2A10M~
	// SDI doc reuse this doc                                      //~v63hR~
    if (Mpapp->Mappinitsw)	//skip msg by cmd line parm            //~2A10M~
    {                                                              //~2A12I~
//        ugettempfname(0,newfnm);    //temp on wxe temp dir       //~@@@@R~
//        SetPathName(newfnm,FALSE);  //not add to mru list;fail prompt(return CANCEL)//~@@@@R~
////      this->m_strTitle=CString("NewFile");                     //~@@@@R~
////      this->m_strPathName=CString(newfnm);                     //~@@@@R~
//        Mwxefile.filenew(newfnm);                                //~@@@@R~
        Mwxefile.filenew(Pfnm);                                    //~@@@@I~
    }                                                              //~2A12I~
	return TRUE;                                                   //~2A10M~
}                                                                  //~2A10M~
                                                                   //~2A10M~
//BOOL CWxeDoc::OnOpenDocument(LPCTSTR lpszPathName)               //~@@@@R~
BOOL CWxeDoc::OnOpenDocument(BOOLEAN Preadonly,LPCTSTR lpszPathName)//~@@@@I~
{
//*************************                                        //~2A08I~
//    if (!CDocument::OnOpenDocument(lpszPathName))                //~2A08R~
//        return FALSE;                                            //~2A08R~
	
    if (Mpapp->Mappinitsw)	//skip msg by cmd line parm            //~2A10I~
    {                                                              //~2A12I~
    	if (Mwxefile.Mxeinitsw)                                    //~2A10R~
//      	Mwxefile.fileopen(lpszPathName);                       //~@@@@R~
        	Mwxefile.fileopen(Preadonly,lpszPathName);             //~@@@@I~
    }                                                              //~2A12I~
	return TRUE;
}

BOOL CWxeDoc::OnSaveDocument(LPCTSTR lpszPathName) 
{
    UTRACEP("Mcmdid %0x\n",Mcmdid);                                //~2A09I~
//  if (Mcmdid==ID_FILE_SAVE_AS)                                   //~@@@@R~
    if (lpszPathName)	//SaveAs                                   //~@@@@I~
    	Mwxefile.filesave(lpszPathName);                           //~2A09M~
    else                                                           //~2A09I~
    	Mwxefile.filesave("");		//no filename                  //~2A09M~
//  return CDocument::OnSaveDocument(lpszPathName);                //~2A12R~
    return TRUE;                                                   //~2A12I~
}

//*filename==NULL is alternative of Mcmdid for SAVE or SAVE_AS     //~@@@@R~
//BOOL CWxeDoc::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)//~@@@@R~
//{                                                                //~@@@@R~
//    UTRACEP("OnCmdMsg nID=%x,nCode=%d\n",nID,nCode);             //~@@@@R~
//    Mcmdid=nID;     //for distinguish save and save as           //~@@@@R~
//    int rc=CDocument::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);//~@@@@R~
////  int rc2=CommDlgExtendedError();                              //~@@@@R~
//    return rc;                                                   //~@@@@R~
//}                                                                //~@@@@R~
///////////////////////////////////////////////////////////////////////////////~2A14I~
int  CWxeDoc::ondropfiles(HDROP hDropInfo)                         //~v63hR~
{                                                                  //~2A14I~
    return                                                         //~v63hI~
	Mwxefile.ondropfiles(hDropInfo);                               //~2A14I~
//  return;                                                        //~v63hR~
}                                                                  //~2A14I~
