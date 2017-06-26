//*CID://+@@@@R~:                             update#=   43;       //~@@@@R~
//******************************************************************************//~v63hI~
//v76j:070626 (WXEXXE)dnd by paste to utility panel                //~v76jI~
//v686:060323 dnd support by paste                                 //~v686I~
//v685:060322 dnd support "file copy into the dir slected" and even in inter-split-screen.//~v685I~
//v63k:050509 (WXE)change mouse csr when dragout in progress       //~v63kI~
//v63h:050504 (WXE)support DragOut                                 //~5506I~
//******************************************************************************//~v63hI~
//#ifndef HEADER_WXEFILE                                           //~@@@@R~
//#define HEADER_WXEFILE                                           //~@@@@R~
#pragma once                                                       //~@@@@I~
                                                                   //~2816I~
#ifdef __cplusplus                                                 //~v76jI~
                                                                   //~v76jI~
//#include    <afxwin.h>                                           //~@@@@R~
#include <stdafx.h>                                                //~@@@@R~



//================================================================================//~2816I~
//file                                                             //~2817R~
//================================================================================//~2816I~
class   CWxefile                                                   //~2817R~
{                                                                  //~2816I~
public :                                                           //~2816I~
                                                                   //~v76jI~
    CWxefile();                                                    //~2817R~
    ~CWxefile();                                                   //~2817R~
	int init(CDocument *Ppdoc);                                    //~2817R~
                                                                   //~v76jI~
#endif  //cplusplus                                                //~v76jM~
                                                                   //~v76jI~
	int filenew(char *Pfnm);                                       //~2A12R~
//  int fileopen(LPCTSTR Pfilename);                               //+@@@@R~
    int fileopen(BOOLEAN Preadonly,LPCTSTR Pfilename);             //+@@@@I~
	int filesave(LPCTSTR Pfilename);                               //~2922I~
	int  ondropfiles(HDROP hDropInfo);                             //~v63hR~
	int  ondropfilesub(int Popt,HDROP Phd,void *Ppcwtarget,int Prow,int Pcol);//~v686R~
#define DROPFILE_CP       0x80000000   //drag&drop by cut&paste    //~v686R~
#define DROPFILE_REP      0x40000000   //file copy by replace mode //~v686I~
#define DROPFILE_FLAGMASK 0xf0000000   //post message flag mask    //~v686I~
                                                                   //~v76jI~
#ifdef __cplusplus                                                 //~v76jI~
                                                                   //~v76jI~
	DROPEFFECT ondragenter(COleDataObject* pDataObject, DWORD dwKeyState, CPoint point);//~v63hI~
	DROPEFFECT ondragover(COleDataObject* pDataObject, DWORD dwKeyState, CPoint point);//~v63hI~
                                                                   //~v76jI~
#endif  //cplusplus                                                //~v76jI~
                                                                   //~v76jI~
    int Mxeinitsw;                                                 //~2A08R~
//  int Mswdndinprogress;   //dodrag in progress by wxemouse       //~v63kR~
    void *Mdragfrompcw;		//drag start pcw for copy into dir operation by dnd//~v685I~
	BOOL  filecopybydnd(WPARAM Pcmdid,LPARAM Pcmdparm);            //~v685I~
                                                                   //~v76jI~
#ifdef __cplusplus                                                 //~v76jI~
                                                                   //~v76jI~
private :                                                          //~2816I~
                                                                   //~v76jI~
#endif  //cplusplus                                                //~v76jI~
	void invalidate(void);                                         //~2817R~
	void activate(void);                                           //~v685I~
                                                                   //~v76jI~
#ifdef __cplusplus                                                 //~v76jI~
                                                                   //~v76jI~
    CDocument  *Mpdoc;                                             //~2A10R~
                                                                   //~v76jI~
#endif  //cplusplus                                                //~v76jI~
                                                                   //~v76jI~
	int   filepostcopybydndmsg(int Popt,HDROP Phd,char *Ptarget);  //~v686R~
	void  point2rowcol(POINT Ppoint,int *Pprow,int *Ppcol);        //~v685I~
                                                                   //~v76jI~
#ifdef __cplusplus                                                 //~v76jI~
                                                                   //~v76jI~
};                                                                 //~2816I~
                                                                   //~v76jI~
#endif  //cplusplus                                                //~v76jI~
                                                                   //~2816I~
//#endif  //HEADER_WXEFILE                                         //~@@@@R~
