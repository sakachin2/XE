//*CID://+@@@@R~:                             update#=   26;       //~@@@@R~
//***************************************************************  //~v51eI~
//v63h:050504 (WXE)support DragOut                                 //~v63hI~
//v51e:030517 (WXE:BUG)drug drop need svreen invalidate            //~v51eI~
//***************************************************************  //~v51eI~
// wxeDoc.h                                                        //~v63hR~
//
/////////////////////////////////////////////////////////////////////////////

//#if !defined(AFX_WXEDOC_H__F3393129_AD0D_11D6_8C9B_00909951ADD0__INCLUDED_)//~@@@@R~
//#define AFX_WXEDOC_H__F3393129_AD0D_11D6_8C9B_00909951ADD0__INCLUDED_//~@@@@R~

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <stdafx.h>                                                //~@@@@R~
//#include <wxe.h>                                                 //~@@@@R~
#include <wxefile.h>                                               //~@@@@I~

class CWxeDoc : public CDocument
{
//protected:                                                       //~@@@@R~
public:                                                            //~@@@@I~
	CWxeDoc();
	DECLARE_DYNCREATE(CWxeDoc)
public:
	CWxefile Mwxefile;                                             //~2817I~
	CView   *Mpview;                                               //~2A10M~
	void     init(CView*);                                         //~v51eI~
private :                                                          //~2817I~
	UINT Mcmdid;  		//cmd id                                   //~2A09I~
	CWxeApp *Mpapp;                                                //~2A10I~
public:

	//{{AFX_VIRTUAL(CWxeDoc)
	public:
//  virtual BOOL OnNewDocument();                                  //~@@@@R~
	virtual BOOL OnNewDocument(char *Pfnm);                        //+@@@@R~
//    virtual void Serialize(CArchive& ar);                        //~@@@@R~
//  virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);             //~@@@@R~
    virtual BOOL OnOpenDocument(BOOLEAN Preadonly,LPCTSTR lpszPathName);//~@@@@R~
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
//    virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);//~@@@@R~
	//}}AFX_VIRTUAL

public:
	virtual ~CWxeDoc();
//#ifdef _DEBUG                                                    //~@@@@R~
//    virtual void AssertValid() const;                            //~@@@@R~
//    virtual void Dump(CDumpContext& dc) const;                   //~@@@@R~
//#endif                                                           //~@@@@R~
	int  ondropfiles(HDROP hDropInfo);                             //~v63hR~

protected:

protected:
	//{{AFX_MSG(CWxeDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}

//#endif // !defined(AFX_WXEDOC_H__F3393129_AD0D_11D6_8C9B_00909951ADD0__INCLUDED_)//~@@@@R~
