//CID://+vb3wR~:      update#=      4                              //+vb3wR~
//******************************************************************************//~v003I~
//vb3w:160621 w64 compiler warning                                 //+vb3wI~
//vak7:130906 redirect memcpy to memmove when overlaped            //~vak7I~
//v76j:070626 (WXEXXE)dnd by paste to utility panel                //~v76jI~
//v76g:070620 utility panel(3.14:grep and 3.12:compare);f5:open dirlist, dlcmd "^":send//~v76gI~
//v68i:060331 (WXEXXE)activate window when dropped                 //~v68iI~
//v68a:060328 activete window when dropped                         //~v68aI~
//v686:060323 dnd support by paste                                 //~v686I~
//v685:060322 dnd support "file copy into the dir slected" and even in inter-split-screen.//~v685I~
//v63k:050509 (WXE)change mouse csr when dragout in progress       //~v63kI~
//v63h:050504 (WXE)support DragOut                                 //~v63gI~
//v63g:050504 (WXE)DrgFinish required to avoid memory leak         //~v63gI~
//******************************************************************************//~v003I~
//******************************************************************************//~v003I~
//                                                                 //~v003I~
#include    "StdAfx.h"                                             //~v003I~
//#include    "AfxWin.h"                                           //~@@@@R~
#define NO_MACRO_REDIRECT                                          //~vak7I~
#include    <ulib.h>                                               //~vak7M~
#include    "wxedef.h"                                             //~v003I~
#include    "wxe.h"                                                //~v003I~
#include    "wxefile.h"                                            //~v003M~
#include    "wxeDoc.h"                                             //~v003I~
#include    "wxemain.h"                                            //~v685I~
#include    "wxeView.h"                                            //~v685I~
#include    "wxexei.h"                                             //~v003I~
#include    "wxecsub.h"                                            //~v003I~
#include    "resource.h"                                           //~v003I~
                                                                   //~v003I~
#include    "utrace.h"                                             //~v63gI~
//==============================================================================//~v003I~
//                                                                 //~v003I~
//==============================================================================//~v003I~
extern  "C"                                                        //~v003I~
{                                                                  //~v003I~
}                                                                  //~v003I~
//===============================================================================//~v003I~
//                                                                 //~v003I~
//===============================================================================//~v003I~
CWxefile::CWxefile()                                               //~v003R~
{                                                                  //~v003I~
    Mxeinitsw=0;    //xeinit sw                                    //~v003I~
//  Mswdndinprogress=0;    //dodrag in progress by wxemouse        //~v63kR~
    Mdragfrompcw=0;		    //drag start pcw                       //~v685I~
}                                                                  //~v003I~
//===============================================================================//~v003I~
//                                                                 //~v003I~
//===============================================================================//~v003I~
CWxefile::~CWxefile()                                              //~v003R~
{                                                                  //~v003I~
}                                                                  //~v003I~
//===============================================================================//~v003I~
//                                                                 //~v003I~
//===============================================================================//~v003I~
int  CWxefile::init(CDocument *Ppdoc)                              //~v003R~
{                                                                  //~v003I~
//*********************                                            //~v003I~
     Mpdoc=Ppdoc;                                                  //~v003R~
     return 0;                                                     //~v003I~
}//newfile                                                         //~v003I~
//===============================================================================//~v003I~
//filenew is always called at start by setting at wxe.app on commmandlineinfo//~v003R~
//===============================================================================//~v003I~
int  CWxefile::filenew(char *Pfnm)                                 //~v003R~
{                                                                  //~v003I~
//*********************                                            //~v003I~
    wxe_editcmd("E",Pfnm);                                         //~v003R~
    invalidate();                                                  //~v003R~
    return 0;                                                      //~v003R~
}//newfile                                                         //~v003R~
//===============================================================================//~v003I~
//Open                                                             //~v003R~
//===============================================================================//~v003I~
//int CWxefile::fileopen(LPCTSTR Pfilename)                        //~@@@@R~
int CWxefile::fileopen(BOOLEAN Preadonly,LPCTSTR Pfilename)        //~@@@@I~
{                                                                  //~v003I~
	if (Preadonly)                                                 //~@@@@I~
     wxe_editcmd("B",(char *)Pfilename);                           //~@@@@I~
    else                                                           //~@@@@I~
     wxe_editcmd("E",(char *)Pfilename);                           //~v003R~
	 invalidate();                                                 //~v003R~
     return 0;                                                     //~v003I~
}//fileopen                                                        //~v003R~
//===============================================================================//~v003I~
//Open                                                             //~v003I~
//===============================================================================//~v003I~
int CWxefile::filesave(LPCTSTR Pfilename)                          //~v003I~
{                                                                  //~v003I~
//*********************                                            //~v003I~
     wxe_editcmd("S",(char *)Pfilename);                           //~v003R~
	 invalidate();                                                 //~v003I~
     return 0;                                                     //~v003I~
}//filesave                                                        //~v003I~
//===============================================================================//~v003I~
//                                                                 //~v003I~
//===============================================================================//~v003I~
void CWxefile::invalidate(void)                                    //~v003I~
{                                                                  //~v003I~
	CWxeDoc* pdoc;                                                 //~v003I~
//************************                                         //~v003I~
	pdoc=(CWxeDoc*)Mpdoc;                                          //~v003R~
	if (pdoc->Mpview)                                              //~v003I~
		(pdoc->Mpview)->Invalidate(FALSE);                         //~v003R~
    return;                                                        //~v003I~
}//invalidate                                                      //~v003I~
//===============================================================================//~v63gI~
//open dropped file                                                //~v63gR~
//===============================================================================//~v63gI~
int  CWxefile::ondropfiles(HDROP Phd)                              //~v63gR~
{                                                                  //~v003I~
    POINT pt;                                                      //~v686I~
    int row,col,rc;                                                //~v686R~
//***************************************                          //~v686I~
    DragQueryPoint(Phd,&pt);                                       //~v686I~
	point2rowcol(pt,&row,&col);                                    //~v686I~
UTRACEP("@@@@ondrop row=%d,col=%d\n",row,col);                     //~v686I~
	rc=ondropfilesub(0,Phd,0,row,col); //target pcw determined later by row/col//~v686R~
    DragFinish(Phd);//avoid memory leak                            //~v686I~
  	usetfocus();                                                   //~v68iR~
    return rc;                                                     //~v686I~
}                                                                  //~v686I~
//===============================================================================//~v686I~
int  CWxefile::ondropfilesub(int Popt,HDROP Phd,void *Ppcwtarget,int Prow,int Pcol)//~v686R~
{                                                                  //~v686I~
	int ii,fileno,rc;                                              //~v003R~
    int rc2=TRUE;                                                  //~v685I~
    char fnm[_MAX_PATH+1];                                         //~v003R~
    char targetdir[_MAX_PATH+1];                                   //~v685I~
    int filecopy,opt;                                              //~v68aR~
//***************************************                          //~v003I~
//  if (Mswdndinprogress)    //dodrag in progress by wxemouse      //~v63kR~
//  {                                                              //~v63kR~
//  	Mswdndinprogress=0;  //drop to myselp rejected             //~v63kR~
//  	return FALSE;   	//reject drop on myself                //~v63kR~
//  }                                                              //~v63kR~
//  DragQueryPoint(Phd,&pt);                                       //~v686R~
//  point2rowcol(pt,&row,&col);                                    //~v686R~
	opt=DROP_COPYCHKMSG;                                           //~v68aR~
    filecopy=wxe_dndfilecopychk(opt,Mdragfrompcw,Ppcwtarget,Prow,Pcol,targetdir);//~v68aR~
  if (filecopy<0)	//drop on dir list failed(target not selected) or not dir//~v685R~
  	rc2=FALSE;                                                     //~v685R~
  else                                                             //~v685I~
  if (filecopy==DROPRC_UTIL)	//drop to utility panel            //~v76gI~
  {                                                                //~v76gI~
	fileno=DragQueryFile(Phd,-1,NULL,0);                           //~v76gI~
    for (ii=fileno-1;ii>=0;ii--)                                   //~v76gI~
    {                                                              //~v76gI~
		DragQueryFile(Phd,ii,fnm,sizeof(fnm));                     //~v76gI~
     	rc=wxe_dndutil(Popt,fnm,Prow);	//opt:ins/rep              //~v76jR~
        if (rc)                                                    //~v76gI~
        	break;                                                 //~v76gI~
    }                                                              //~v76gI~
	rc2=TRUE;	//done                                             //~v76jR~
  }                                                                //~v76gI~
  else                                                             //~v76gI~
  if (filecopy)                                                    //~v685I~
  {                                                                //~v685I~
    filepostcopybydndmsg(Popt,Phd,targetdir);                      //~v686R~
	rc2=TRUE;                                                      //~v685I~
  }                                                                //~v685I~
  else                                                             //~v685I~
  {                                                                //~v685I~
	fileno=DragQueryFile(Phd,-1,NULL,0);                           //~v003R~
    for (ii=fileno-1;ii>=0;ii--)                                   //~v003R~
    {                                                              //~v003I~
		DragQueryFile(Phd,ii,fnm,sizeof(fnm));                     //~v003R~
     	rc=wxe_editcmd("E",fnm);                                   //~v003I~
        if (rc)                                                    //~v003I~
        	break;                                                 //~v003I~
    }                                                              //~v003I~
	rc2=TRUE;                                                      //~v685I~
  }                                                                //~v685I~
//  DragFinish(Phd);//avoid memory leak                            //~v686R~
    invalidate();                                                  //~v003I~
//    activate();                                                  //~v685R~
//	return TRUE;                                                   //~v685R~
  	return rc2;                                                    //~v685I~
}                                                                  //~v003I~
//===============================================================================//~v63gI~
//1st time drop csr entered                                        //~v63gI~
//===============================================================================//~v63gI~
DROPEFFECT CWxefile::ondragenter(COleDataObject* pDataObject, DWORD dwKeyState, CPoint point)//~v63gI~
{                                                                  //~v63gI~
	int row,col;                                                   //~v685I~
//*****************************                                    //~v685I~
//  if (Mswdndinprogress)    //dodrag in progress by wxemouse      //~v63kR~
//  	return DROPEFFECT_NONE;                                    //~v63kR~
	point2rowcol(point,&row,&col);                                 //~v685I~
UTRACEP("@@@@dragenter row=%d,col=%d\n",row,col);                  //~v685I~
	if (wxe_dndfilecopychk(0,Mdragfrompcw,0,row,col,0)<0)          //~v686R~
	  	return DROPEFFECT_NONE; 		//drop not avail           //~v685I~
    return DROPEFFECT_COPY;                                        //~v63gI~
}                                                                  //~v63gI~
//===============================================================================//~v63gI~
//1st time drop csr entered                                        //~v63gI~
//===============================================================================//~v63gI~
DROPEFFECT CWxefile::ondragover(COleDataObject* pDataObject, DWORD dwKeyState, CPoint point)//~v63gI~
{                                                                  //~v63gI~
	int row,col;                                                   //~v685I~
//*****************************                                    //~v685I~
//  if (Mswdndinprogress)    //dodrag in progress by wxemouse      //~v63kR~
//  	return DROPEFFECT_NONE;                                    //~v63kR~
	point2rowcol(point,&row,&col);                                 //~v685I~
UTRACEP("@@@@dragover row=%d,col=%d\n",row,col);                   //~v685I~
	if (wxe_dndfilecopychk(0,Mdragfrompcw,0,row,col,0)<0)          //~v686R~
	  	return DROPEFFECT_NONE; 		//drop not avail           //~v685I~
    return DROPEFFECT_COPY;                                        //~v63gI~
}                                                                  //~v63gI~
//===============================================================================//~v685I~
//send copy file msg                                               //~v685I~
//===============================================================================//~v685I~
int  CWxefile::filepostcopybydndmsg(int Popt,HDROP Phd,char *Ptarget)//~v686R~
{                                                                  //~v685I~
    char *pc,*pc0;                                                 //~v685R~
    int len,totlen,reslen,fileno,ii;                               //~v685R~
    long parm2;                                                    //~v685I~
//***************************************                          //~v685I~
	fileno=DragQueryFile(Phd,-1,NULL,0);                           //~v685I~
    if (!fileno)                                                   //~v686I~
    	return -1;                                                 //~v686I~
    totlen=len=strlen(Ptarget)+1;                                  //~v685I~
    for (ii=0;ii<fileno;ii++)                                      //~v685I~
    {                                                              //~v685I~
		totlen+=DragQueryFile(Phd,ii,NULL,0)+1;                    //~v685R~
    }                                                              //~v685I~
    pc0=pc=(char*)umemalloc(totlen);                               //~v685I~
    memcpy(pc,Ptarget,len);	//top is target                        //~v685I~
    pc+=len;                                                       //~v685I~
    reslen=totlen-len;                                             //~v685I~
    for (ii=0;ii<fileno;ii++)                                      //~v685I~
    {                                                              //~v685I~
		len=DragQueryFile(Phd,ii,pc,reslen);	//get source filename//~v685I~
        pc+=len+1;                                                 //~v685I~
        reslen-=len+1;                                             //~v685I~
    }                                                              //~v685I~
UTRACEP("dragdrop postmag fileno=%d,t=%s\n",fileno,Ptarget);       //~v685R~
    parm2=(1<<16)|fileno;	//seq & total                          //~v685R~
    parm2|=Popt;                                                   //~v686I~
	return upostmsg(ID_FILE_DNDCOPY,(ULONG)pc0,parm2);             //~v685R~
}//filepostcopybydnd                                               //~v685I~
//===============================================================================//~v685I~
//execute copy by post msg                                         //~v685R~
//===============================================================================//~v685I~
BOOL  CWxefile::filecopybydnd(WPARAM Pcmdparm1,LPARAM Pcmdparm2)   //~v685R~
{                                                                  //~v685I~
    char *tgt,*src;                                                //~v685R~
    int rc,seq,tot,ii;                                             //~v685R~
    ULONG nextseq,flag;                                            //~v686R~
    int opt=0;                                                     //~v686I~
//***************************************                          //~v685I~
    flag=Pcmdparm2 & DROPFILE_FLAGMASK;                            //~v686R~
    Pcmdparm2 &= ~DROPFILE_FLAGMASK;                               //~v686R~
    if (flag & DROPFILE_REP)                                       //~v686I~
    	opt|=DNDCOPY_REP;                                          //~v686I~
//  seq=Pcmdparm2>>16;                                             //~v685I~//+vb3wR~
    seq=(int)(Pcmdparm2>>16);                                      //+vb3wI~
    tot=Pcmdparm2&0xffff;                                          //~v685I~
	tgt=(char*)Pcmdparm1;                                          //~v685I~
    src=tgt+strlen(tgt)+1;                                         //~v685R~
    for (ii=seq-1;ii>0;ii--)                                       //~v685R~
    	src+=strlen(src)+1;                                        //~v685I~
UTRACEP("@@@@dragdrop postmag enter seq=%d of %d s=%s,t=%s\n",seq,tot,src,tgt);//~v685R~
	rc=wxe_dndcopyfile(opt,seq,tot,src,tgt);                       //~v686R~
UTRACEP("@@@@dragdrop rc=%d\n",rc);                                //~v685I~
    if (rc==-1||seq==tot)	//cancelled or last                    //~v685R~
	    umemfree((void*)Pcmdparm1);                                //~v685R~
    else                                                           //~v685I~
    {                                                              //~v685I~
    	seq++;                                                     //~v685I~
        nextseq=(seq<<16)|tot;                                     //~v685I~
        nextseq|=flag;                                             //~v686I~
		upostmsg(ID_FILE_DNDCOPY,(ULONG)Pcmdparm1,nextseq);        //~v685I~
    }                                                              //~v685I~
    invalidate();                                                  //~@@@@R~
	return rc;                                                     //~v685I~
}//filecopybydnd                                                   //~v685I~
//===============================================================================//~v685I~
void  CWxefile::point2rowcol(POINT Ppoint,int *Pprow,int *Ppcol)   //~v685I~
{                                                                  //~v685I~
	CWxeView* pview;                                               //~v685I~
	CWxemain* pmain;                                               //~v685R~
    int cellw,cellh;                                               //~v685I~
//*************************                                        //~v685I~
	pview=(CWxeView*)(((CWxeDoc*)Mpdoc)->Mpview);                  //~v685R~
    pmain=&(pview->Mwxemain);                                      //~v685R~
    cellw=pmain->Mcellw;                                           //~v685I~
    cellh=pmain->Mcellh;                                           //~v685I~
#define COL2(x)      min( MAXCOL-1, ((x-BORDERMARGIN)/cellw) )     //~v685R~
#define ROW2(y)      min( MAXROW-1, ((y-BORDERMARGIN)/cellh) )     //~v685R~
    *Ppcol=COL2(Ppoint.x);                                         //~v685R~
    *Pprow=ROW2(Ppoint.y);                                         //~v685R~
}                                                                  //~v685I~
