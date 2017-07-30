//*CID://+vba3R~:                             update#=  438;       //+vba3R~
//******************************************************************************//~v003I~
//vba3:170715 msvs2017 warning;(Windows:PTR:64bit,ULONG 32bit,HWND:64bit)//+vba3I~
//vb3w:160621 w64 compiler warning                                 //~vb3wI~
//vb2N:160319 (Wxe)clipboard data may be translated CF_TEXT and CF_UNICODETEXT(copyed by CFTEXT is gotten as CF_UNICODETEXT)//~vb2NI~
//            It dose not consider locale data by -Ccodepage parameter//~vb2NI~
//vak7:130906 redirect memcpy to memmove when overlaped            //~vak7I~
//vafa:120607 (WXE2010)C4700 warning(used uninitialized variable)  //~vafaI~
//va7S:100907 (BUG)mouse drag at edge of screen dose not expand copy range bat scroll.//~va7SI~
//va7D:100830 (XXE:BUG)cap menu update err(it should not be based on Mcellcopy1 bur Gcsrposy)//~va7CI~
//va7C:100830 (WXEXXE:BUG)abend when paste to cmdline from filearea by mouse(Gwxecapdbcs was cleared)//~va7CI~
//            if kbd was used to move cursor                       //~va7CI~
//va5y:100518 (WXE)Windows Clipboard translate text. It cause invalid sjis to u-30fb when CF_UNICODETEXT mode//~va5yI~
//            0x0e,4481,0f,00,0a,00(setclipboatddata)-->0x0e00,4400,fb30,0000,0a00,0000(getclipboarddata)//~va5yI~
//            on the otherhand getclipboarddata with CF_TEXT option returns "?" for u2l trans err code of utf8 file(u-00a4(Sun)->"?").//~va5yI~
//            so for EBCDIC code, SetClipboard by CF_UNICODETEXT after trans to ucs2 by bynary mode(1 byte to 1 ucs2)//~va5yI~
//            CF_OEMTEXT will also translate such as 0x8586->0x8145(=u-30FB)//~va5yI~
//            for over session data identification set prefix at top of ebc data//~va5yI~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//va1b:091028_(BUG)va0q is not required splitdbcs set space for splitdbcs//~va1bI~
//                 but dbcstbl clear by setdbcssplit should be recovered//~va1bI~
//va0q:090907 (WXEXXE:BUG)mouse cap from cmdline append space at last//~va0qI~
//v795:080723 (VC8)CWnd:Killtimer parameter changed from int to UINT(link fail)//~v795I~
//v76j:070626 (WXEXXE)dnd by paste to utility panel                //~v76jI~
//v76b:070617 support paste to =2 panel;del v68f because csr moved by lbdown,paste pos become invalid//~v76bI~
//v709:060730 (WXE:XXE)bug by v703;dbl click rejected by csr pos err.Real cause of v703 is cusror setting by rbdown(v68f)//~v709I~
//v702:060726 (WXEXXE:BUG)drag on last line of 1st split screen,set pancopy mode//~v702I~
//v700:060726 (WXEXXE:BUG)cut/del protection chk err(Point1 is already chked and may be scrolled out now)//~v670I~
//v69Z:060726 (XXE)sync C&P between PFkey and mouse operation.(update enable/disable menu by also Key operation)//~v69ZI~
//v69T:060716 (WXE:BUG)by v69h swapped Shift/Ctrl shift status for scroll.//~v69TI~
//            scroll by timer with Shift to horizontal,width Ctrl shift for file bottom/top//~v69TI~
//v69g:060521 (WXE)tilt wheel mouse generate WM_VSCROLL/WM_HSCROLL by mycrosoft spec//~v69gI~
//            if scroll bar exist.(both vertical and horizontal is requred to genarate both)//~v69gI~
//v69f:060521 (WXE)xbutton1/2 support;browser backk/forwardlock on status for up/down arrow key to scroll up/down//~v69fI~
//v69c:060517 (WXE:BUG)time calc to ignore 1st lb down not to do cursor set. and expand limit time 10-->50ms//~v69cI~
//v68f:060330 (WXE)move cursor also by right mouse button down     //~v68fI~
//v68b:060329 (BUG:WXE)drag from dirlist remains cp box(for not file scr,cp box is drawn by wxescr)//~v68bI~
//v689:060328 (BUG)on dir list;s+lbdown/c+lbdown is for line selection not paste(ins/rep)//~v689I~
//v687:060323 popupmenu paste-v enable/disable set miss            //~v687I~
//v686:060323 dnd support by paste                                 //~v686I~
//v685:060322 dnd support "file copy into the dir slected" and even in inter-split-screen.//~v685I~
//v682:060313 (WXE:BUG)menu enable re-evaluation requred for drag selection on dirlist;and also when reset by esc key//~v682I~
//v681:060312 (WXE:BUG by v66m)after DrawMenu api WM_MOUSEMOVE message is post,it cause drag start by S+LBDown//~v681I~
//v66z:051211 (WXE:BUG)C&P miss last line eol at paste timing      //~v66zI~
//v66w:051211 (WXE:BUG)line dbl click is cursor pos err then leave point1 specification;capreset should be called//~v66wI~
//v66s:051027 (WXE/XXE)add Shift+Ctrl+left button to block specification because gnome intercept A+left button//~v66sI~
//v66m:051025 (WXE:BUG)DrawMenuBar is required to show grayed just a time changed status//~v66mI~
//v66i:051023 (WXE)C & P;if no Clipboard data on Windows CB,get data from ::CB//~v66iI~
//v66h:051023 C & P;region mode by mouse; mouse drag->region mode,A+mouse drag->block mode//~v66hI~
//v63p:050510 (WXE:BUG)range spcification should be for each pcw   //~v63pI~
//v63k:050509 (WXE)change mouse csr when dragout in progress       //~v63kI~
//v63i:050507 (WXE)dragdrop by copy/paste                          //~v63iI~
//v63h:050504 (WXE)support DragOut                                 //~v63hI~
//v58i:040912 (WXE)scroll by lb-press;once short stop at eof of file/dir line//~v58iI~
//v55W:040322 (WXE)AT cmd support;"AT(&) interval,count;cmd"       //~v55WI~
//v55u:040229 (WXE)add open with for dir-list                      //~v55uI~
//v55t:040229 disable "save" popup menu when not edit screen       //~v55tI~
//v53A:031013 (WXE)double click generate push and dblclick;shift+push means paste.//~v53AI~
//            so bell sound when shift+dblclick on filename-list,dir list etc.//~v53AI~
//v53b:030921 (WXE:BUG)bell when cross  lineno field seperator     //~v53bI~
//v51u:030615 (WXE)wait scroll kick at first 3 time interval       //~v51uI~
//v51d:030517 (WXE)bitmap menu                                     //~v51dI~
//v514:030223 (WXE)allow continued paste                           //~v514I~
//v510:030215 (WXE)parameterize interval for scroll by mouse       //~v510I~
//v5a1:copy/cut(shift+)/clear(ctrl+) by dblclick                   //~v5a1I~
//030202:paste by shift(insert)/ctrl(override)+lbtn-down           //~3202R~
//******************************************************************************//~v003I~
//                                                                 //~v003R~
#include   <sys/timeb.h>                                           //~v63pI~
#include    "StdAfx.h"                                             //~v003I~
#include    "DragOut.h"                                            //~vak7I~
#define NO_MACRO_REDIRECT                                          //~vak7I~
#include    "ulib.h"                                               //~vak7I~
#include    "wxedef.h"                                             //~v003I~
#include    "wxe.h"                                                //~2A10I~
#include    "wxefile.h"                                            //~v003M~
#include    "wxeDoc.h"                                             //~v003I~
#include    "wxemain.h"                                            //~v003R~
#include    "mainfrm.h"                                            //~3103I~
#include    "wxexei.h"                                             //~v003I~
#include    "wxecsub.h"                                            //~v003I~
#include    "resource.h"                                           //~v003I~
//#include    "DragOut.h"                                            //~@@@@R~//~vak7R~
                                                                   //~2A13I~
//#ifdef UTF8UCS2                                                    //~va20I~//~vak7R~
//#include    "ulib.h"                                               //~va20I~//~vak7R~
//#endif                                                             //~va20I~//~vak7R~
#include    "udbcschk.h"                                           //~va0qI~
#include    "utrace.h"                                             //~2A13I~
                                                                   //~v003I~
#define SETFOCUSTIME 50    //50ms between OnSetFocus to LBDown,then do not move cursor//~v69cI~
static UINT Slastcbfmt;                                            //~vb2NI~
//===============================================================================//~@@@@I~
int  dragoutfile(HGLOBAL Phmem);                                   //~@@@@I~
void CreateMedium(CLIPFORMAT cfFormat, HANDLE hObject, FORMATETC *pFormatetc, STGMEDIUM *pmedium);//~@@@@I~
//===============================================================================//~v003I~
//                                                                 //~v003I~
//===============================================================================//~v003I~
void CWxemain::mouselbdown(UINT Pflag,CPoint Ppoint)               //~v003R~
{                                                                  //~v003I~
	int rc;                                                        //~v003I~
    struct _timeb ctm;                                             //~v63pI~
//************************************                             //~v003I~
UTRACEP("@@@@mouselbdown flag=%x,Mswkillfocus=%d\n",Pflag,Mswkillfocus);//~v73tR~
    if (Mswkillfocus)   //1st time after killfocus                 //~v63pI~
    {                                                              //~v63pI~
    	_ftime(&ctm);	                                           //~v63pI~
//UTRACEP("time %x:%x->%x:%x\n",Msetfocustime,Msetfocusmsec,ctm.time,ctm.millitm);//~v69cR~
        ctm.time-=Msetfocustime;                                   //~v63pR~
        if (ctm.time==1 || ctm.time==0)                            //~v63pI~
        {                                                          //~v63pI~
//      	ctm.time=(ctm.time<<16)+ctm.millitm-Msetfocusmsec;     //~v69cR~
        	ctm.time=(ctm.time*1000)+ctm.millitm-Msetfocusmsec;    //~v69cI~
//UTRACEP("diff=%d\n",ctm.time);                                   //~v69cR~
//          if (ctm.time<10)	//lbdn is in 10ms after setfocus   //~v69cR~
            if (ctm.time<SETFOCUSTIME)	//lbdn is in 10ms after setfocus//~v69cI~
            	return;                                            //~v63pI~
        }                                                          //~v63pI~
        Mswkillfocus=0;                                            //~v63pR~
    }                                                              //~v63pI~
	Mlbdblclicksw=0;	//not after dbl click                      //~v5a1I~
//  wxe_capreset();                                                //~v5a1R~
    if (Mcpcopypansw)   //pane cap                                 //~2A06R~
        cpdrawpan(Mcellcopy1.y,Mcellcopy2.y,-1);  //clear cap box  //~2A06R~
    Mcpcopypansw=0; //file only                                    //~2A05I~
    Mcpcopysw=1;            //start mouse blocking                 //~v003R~
    Mcppastesw=1;                                                  //~v003R~
    Mcpstart=Ppoint;                                               //~v003I~
    Mcellcopy1.x=COL(Ppoint.x);                                    //~v003R~
    Mcellcopy1.y=ROW(Ppoint.y);                                    //~v003R~
//UTRACEP("scroll:lbdown posid=%x,col=%d,row=%d\n",Mlbposid,Mcellcopy1.x,Mcellcopy1.y);//~v69cR~
    mousescrollchk(Mcellcopy1.x,Mcellcopy1.y);                     //~v5a1R~
    Mcellcopy2=Mcellcopy1;                                         //~v003R~
    rc=wxe_movecsr(Mcellcopy1.y,Mcellcopy1.x);                     //~v003R~
	if (Pflag & MK_SHIFT)      	//with shift key                   //~3202I~
    {                                                              //~v66sI~
	  if (!(Pflag & MK_CONTROL))      //with control key           //~v66sR~
//  	cppaste(1);    //1:insert mode                             //~v689R~
    	cppaste(PASTE_TEXT_ONLY|PASTE_INSMODE);    //1:insert mode //~v689I~
    }                                                              //~v66sI~
    else                                                           //~3202I~
	if (Pflag & MK_CONTROL)      //with control key                //~3202I~
    {                                                              //~v66sI~
	  if (!(Pflag & MK_SHIFT))      	//with shift key           //~v66sR~
//  	cppaste(0);         //0:pasteon mode                       //~v689R~
    	cppaste(PASTE_TEXT_ONLY);    //rep text only               //~v689R~
    }                                                              //~v66sI~
    	                                                           //~3202I~
//  ((CMainFrame*)Mpmainframe)->enablemainmenu();	//main menu enable/disable//~v51dR~
    ((CMainFrame*)Mpmainframe)->enablemainmenu();	//main menu enable/disable//~v66mI~
    Mpview->Invalidate(FALSE);                                     //~v003R~
    return;                                                        //~v003I~
}//mouselbdown                                                     //~v003I~
//===============================================================================//~v003M~
//                                                                 //~v003M~
//===============================================================================//~v003M~
void CWxemain::mousemove(UINT Pflag,CPoint Ppoint)                 //~v003R~
{                                                                  //~v003M~
    int xx,yy,rc;                                                  //~2A05R~
    void *pcw;                                                     //~v63hR~
    int cpmode;                                                    //~v66hI~
    int kbdstat;                                                   //~v66sI~
//************************************                             //~v003M~
	if (Mdragstatus==2)                                            //~v685I~
    {                                                              //~v685I~
UTRACEP("@@@@ clear drag pcw=%p\n",Mpwxefile->Mdragfrompcw);       //~v685R~
	    Mpwxefile->Mdragfrompcw=0;	//delay short to clear dragpcw until to allow chk it at ondrop//~v685I~
        Mdragstatus=0;                                             //~v685I~
    }                                                              //~v685I~
    if (Mswkillfocus)   //1st time after killfocus                 //~v63pI~
        return;			//until lbup                               //~v63pI~
	if (!(Pflag & MK_LBUTTON))	//l-button pressed?                //~v003M~
    {                                                              //~v5a1I~
    	if (Mlbposid && Mcpcopysw==2)     //lb up miss when at out of client area//~v5a1R~
			mouselbup(Pflag,Ppoint);                               //~v5a1I~
    	Mlbposid=0;		//for auto scroll                          //~v5a1M~
	    return;                                                    //~v003M~
    }                                                              //~v5a1I~
    Mcellcopy2.x=COL(Ppoint.x);                                    //~v5a1M~
    Mcellcopy2.y=ROW(Ppoint.y);                                    //~v5a1M~
//UTRACEP("mousemove row=%d,col=%d\n",Mcellcopy2.y,Mcellcopy2.x);  //~v69TR~
  if (!SAMEPOS(Mcellcopy2,Mcellcopy1))	//moved over 1col or 1 row //~v681I~
    if (wxe_dragselectchk(DRAGOPT_DRAG,Pflag,Mcellcopy2.y,Mcellcopy2.x,&pcw,0))//~v63iR~
    {                                                              //~v63hR~
    	Mcpcopypansw=0;	//protect cap box draw at wxescr:lineput   //~v68bI~
		Mcpcopysw=0;	//stop drag text area but file drag        //~v68bI~
        mousedodrag(pcw,0);                                        //~v63iR~
        Mpview->Invalidate(FALSE);                                 //~v63hR~
        return;                                                    //~v63hR~
    }                                                              //~v63hR~
//UTRACEP("scroll:mousemove posid=%x,col=%d,row=%d\n",Mlbposid,Mcellcopy2.x,Mcellcopy2.y);//~v53bR~
    mousescrollchk(Mcellcopy2.x,Mcellcopy2.y);                     //~v5a1I~
    if (!Mcpcopysw)                                                //~v003R~
	    return;                                                    //~v003M~
    xx=Mcpstart.x-Ppoint.x;                                        //~v003R~
    yy=Mcpstart.y-Ppoint.y;                                        //~v003R~
    if (xx<0)                                                      //~v003I~
        xx=-xx;                                                    //~v003I~
    if (yy<0)                                                      //~v003I~
        yy=-yy;                                                    //~v003I~
    if (xx<(Mcellw>>1) && yy<(Mcellh>>1))                          //~v003R~
	    return;                                                    //~v003I~
    if (Mcpcopysw==1)	//1st time                                 //~v003I~
    {                                                              //~2A05I~
        wxe_capreset();    //reset box by alt+F7                   //~v5a1I~
        cpmode=CP_DRAGOPEN;                                        //~v66hI~
//		if (ugetkbdshiftstatus(VK_MENU) & WXEKBDMSG_ALTKEY)	//Alt down//~v66sR~
		kbdstat=ugetkbdshiftstatus(VK_MENU);                       //~v66sI~
		if (kbdstat & WXEKBDMSG_ALTKEY	//Alt down                 //~v66sI~
		||  (kbdstat & (WXEKBDMSG_SHIFTKEY|WXEKBDMSG_CTLKEY))==(WXEKBDMSG_SHIFTKEY|WXEKBDMSG_CTLKEY))//~v66sI~
        {                                                          //~v66hI~
        	Mcpblockmode=1;                                        //~v66hI~
        	cpmode|=CP_DRAGBLOCK;                                  //~v66hI~
        }                                                          //~v66hI~
        else                                                       //~v66hI~
        	Mcpblockmode=0;                                        //~v66hI~
//  	if (rc=wxe_capblock(0,Mcellcopy2.y,Mcellcopy2.x,&Mcpcopypansw),rc)	//block start failed//~v66hR~
//  	if (rc=wxe_capblock(cpmode,Mcellcopy2.y,Mcellcopy2.x,&Mcpcopypansw),rc)	//block start failed//~v702R~
    	if (rc=wxe_capblock(cpmode,Mcellcopy1.y,Mcellcopy1.x,&Mcpcopypansw),rc)	//block start failed//~v702I~
	    {                                                          //~v003I~
            Mcpcopysw=0;                                           //~2A05R~
    		Mpview->Invalidate(FALSE);                             //~v5a1I~
            return;                                                //~2A05R~
	    }                                                          //~v003I~
        Mcpoldpos=Mcellcopy2;                                      //~2A05R~
    }                                                              //~2A05I~
    if (Mcpcopypansw)	//file only                                //~2A05R~
    {                                                              //~2A05I~
    	if (!SAMEPOS(Mcellcopy2,Mcpoldpos))                        //~2A05R~
        {                                                          //~2A05I~
	    	cpdrawpan(Mcellcopy1.y,Mcellcopy2.y,Mcpoldpos.y);      //~2A05R~
            Mcpoldpos=Mcellcopy2;                                  //~2A05R~
        }                                                          //~2A05I~
    }                                                              //~2A05I~
    else                                                           //~2A05I~
	    wxe_movecsr(Mcellcopy2.y,Mcellcopy2.x);	//csr move	       //~2A05R~
	Mcpcopysw=2;	//moved width lbutton down                     //~v003I~
    Mpview->Invalidate(FALSE);                                     //~v003M~
}//mousemove                                                       //~v003R~
//===============================================================================//~2A05I~
//                                                                 //~2A05I~
//===============================================================================//~2A05I~
void CWxemain::cpdrawpan(int Prow1,int Prow2,int Prow3)            //~2A05R~
{                                                                  //~2A05I~
    int ii,row1,row2;                                              //~2A05R~
//************************************                             //~2A05I~
    row1=min(Prow1,Prow2);                                         //~2A05I~
    row2=max(Prow1,Prow2);                                         //~2A05I~
	if (Prow3>=0)                                                  //~2A05I~
    {                                                              //~2A05I~
    	row1=min(Prow3,row1);                                      //~2A05I~
    	row2=max(Prow3,row2);                                      //~2A05I~
    }                                                              //~2A05I~
	for (ii=row1;ii<=row2;ii++)                                    //~2A05R~
    	SETDRAWLINE(ii);                                           //~2A05I~
    return;                                                        //~2A05I~
}//cpdrawpan                                                       //~2A05R~
//===============================================================================//~v003I~
//                                                                 //~v003I~
//===============================================================================//~v003I~
void CWxemain::mouselbup(UINT Pflag,CPoint Ppoint)                 //~v003R~
{                                                                  //~v003I~
	void *plh,*pcw;                                                //~v63hR~
    int dragchkrc;                                                 //~v58iI~
    int cpmode;                                                    //~v66hI~
//************************************                             //~v003I~
UTRACEP("@@@@lbup\n");                                               //~v68bI~//~va20R~
    if (Mswkillfocus)   //1st time after killfocus                 //~v63pI~
    {                                                              //~v63pI~
        Mswkillfocus=0;                                            //~v63pI~
        return;                                                    //~v63pI~
    }                                                              //~v63pI~
	Mlbposid=0;					//for autoscroll                   //~v5a1I~
    if (Mcpcopysw!=2)            //start mouse blocking            //~v003R~
    {                                                              //~v58iI~
    	if (dragchkrc=wxe_dragselectchk(DRAGOPT_SELECT,Pflag,ROW(Ppoint.y),COL(Ppoint.x),&pcw,&plh),dragchkrc)//~v63hR~
        	mousedragfile(dragchkrc,pcw,plh);                      //~v63hR~
    	return;                                                    //~v003I~
    }                                                              //~v58iI~
    if (Mlbdblclicksw)	//after dbl click                          //~v5a1I~
    {                                                              //~v5a1I~
	    Mlbdblclicksw=0;	//after dbl click                      //~v5a1I~
    	return;                                                    //~v5a1I~
    }                                                              //~v5a1I~
    Mcellcopy2.x=COL(Ppoint.x);                                    //~v003R~
    Mcellcopy2.y=ROW(Ppoint.y);                                    //~v003R~
//  if (wxe_capblock(1,Mcellcopy2.y,Mcellcopy2.x,&Mcpcopypansw))	//block end failed//~v66hR~
    cpmode=CP_DRAGCLOSE;                                           //~v66hI~
	if (Mcpblockmode)	//Alt down                                 //~v66hR~
        cpmode|=CP_DRAGBLOCK;                                      //~v66hI~
    Mcpblockmode=0;                                                //~v66hI~
    if (wxe_capblock(cpmode,Mcellcopy2.y,Mcellcopy2.x,&Mcpcopypansw))	//block end failed//~v66hR~
    {                                                              //~v003I~
		wxe_capreset();                                            //~v5a1I~
        Mcpcopysw=0;                                               //~v003I~
    }                                                              //~v51dI~
    else                                                           //~v51dI~
    	CAPGETBOX(Mcellcopy1,Mcellcopy2);                          //~v51dR~
//  ((CMainFrame*)Mpmainframe)->enablemainmenu();	//main menu enable/disable//~v51dR~
    ((CMainFrame*)Mpmainframe)->enablemainmenu();	//main menu enable/disable//~v66mI~
    Mpview->Invalidate(FALSE);                                     //~v003I~
    return;                                                        //~v51dI~
}//mouselbup                                                       //~2A06R~
//===============================================================================//~v003M~
//                                                                 //~v003M~
//===============================================================================//~v003M~
void CWxemain::mouserbdown(UINT Pflag,CPoint Ppoint)               //~v003R~
{                                                                  //~v003M~
    CPoint scrpos;                                                 //~v003M~
    CMenu *submenu;                                                //~v003M~
    UINT flag=TPM_RIGHTALIGN;                                      //~v003M~
    int itemctr,ii;                                                //~2A12R~
    UINT menuid;                                                   //~v003M~
    BOOL enable;                                                   //~v003M~
//    int row,col;                                                 //~v76bR~
    CMenuHandle menuh;                                             //~@@@@I~
//************************************                             //~v003M~
UTRACEP("@@@@rbdown\n");                                             //~v76jI~//~va20R~
    Mswkillfocus=0;                                                //~v63pI~
	if (Mfloatmenusw)                                              //~v003M~
	    return;                                                    //~v003M~
	Mfloatmenusw=1;                                                //~v003M~
//move cursor                                                      //~v68fI~
//  if (!Mcpcopysw && !Mcpcopypansw)                                 //~v709R~,//~v76bR~
//  {                                                                //~v702I~,//~v76bR~
//    col=COL(Ppoint.x);                                             //~v68fI~,//~v76bR~
//    row=ROW(Ppoint.y);                                             //~v68fI~,//~v76bR~
//    wxe_movecsr(row,col);                                          //~v68fI~,//~v76bR~
//    Mpview->Invalidate(FALSE);  //request draw msg before popup menue draw request//~v68fR~,//~v76bR~
//  }                                                                //~v709R~,//~v76bR~
                                                                   //~v68fI~
	scrpos=Ppoint;                                                 //~v003M~
	Mpview->ClientToScreen(&scrpos);                               //~v003M~
    Mfloatmenu.LoadMenu(IDR_FLOATING);                             //~v003M~
	((CMainFrame*)Mpmainframe)->updatemenu(1,&Mfloatmenu);	//update accelerator label//~3103R~
//  submenu=Mfloatmenu.GetSubMenu(0);                              //~@@@@R~
    menuh=Mfloatmenu.GetSubMenu(0);                                //~@@@@I~
    submenu=&menuh;                                                //~@@@@I~
    itemctr=submenu->GetMenuItemCount();                           //~v003M~
    for (ii=0;ii<itemctr;ii++)                                     //~v003M~
    {                                                              //~v003M~
	    menuid=submenu->GetMenuItemID(ii);                         //~v003M~
        switch(menuid)                                             //~v003M~
        {                                                          //~v003M~
        case ID_EDIT_CUT:                                          //~v003M~
        case ID_EDIT_CLEAR:                                        //~2A06I~
        	enable=cpupdatecut();                                  //~v003M~
        	break;                                                 //~v003M~
        case ID_EDIT_COPY:                                         //~v003M~
        	enable=cpupdatecopy();                                 //~v003M~
        	break;                                                 //~v003M~
        case ID_EDIT_PASTE:                                        //~v003M~
        case ID_EDIT_PASTE_REP:                                    //~v003I~
        	enable=cpupdatepaste();                                //~v003M~
UTRACEP("rc of updatepaste=%d\n",enable);                          //~v76jI~
        	break;                                                 //~v003M~
        case ID_EDIT_PASTE_STD:                                    //~v66iM~
        	enable=cpupdatepastestd();                             //~v66iR~
UTRACEP("rc of updatepasteSTD=%d\n",enable);                       //~v76jI~
        	break;                                                 //~v687I~
        case ID_EDIT_CANCEL:                                       //~v55tI~
        	enable=wxe_chkendenable(CHKST_CANCEL);                 //~v55uR~
        	break;                                                 //~v55tI~
        case ID_EDIT_END:                                          //~v55tI~
        	enable=wxe_chkendenable(CHKST_END);                    //~v55uR~
        	break;                                                 //~v55tI~
        case ID_FILE_SAVE:                                         //~v55tR~
        	enable=wxe_chkendenable(CHKST_SAVE);                   //~v55uR~
        	break;                                                 //~v55tI~
        case ID_FILE_OPENWITH:                                     //~v55uI~
        	enable=wxe_chkendenable(CHKST_OPENWITH);               //~v55uR~
        	break;                                                 //~v55uI~
        default:                                                   //~v003M~
        	continue;                                              //~v003M~
        }                                                          //~v003M~
        if (!enable)                                               //~v003M~
		    submenu->EnableMenuItem(ii,MF_BYPOSITION|MF_GRAYED);   //~v51dR~
        else                                                       //~v003M~
		    submenu->EnableMenuItem(ii,MF_BYPOSITION|MF_ENABLED);  //~v003M~
    }                                                              //~v003M~
//  submenu->TrackPopupMenu(flag,scrpos.x,scrpos.y,Mpview,NULL);   //~@@@@R~
    submenu->TrackPopupMenu(flag,scrpos.x,scrpos.y,HWND(*Mpview),NULL);//~@@@@R~
    Mfloatmenu.DestroyMenu();                                      //~v003M~
	Mfloatmenusw=0;                                                //~v003M~
}//mouserbdown                                                     //~v003M~
//===============================================================================//~v003I~
//cut & paste:copy/cut                                             //~v003R~
//p1:cutsw 0:copy,1;cut,2:clear                                    //~2A06I~
//===============================================================================//~v003I~
int  CWxemain::cpcopy(int Pcutsw)                                  //~v003R~
{                                                                  //~v003I~
	HGLOBAL hGlobal;                                               //~v003I~
	int  totlen,row,col;                                           //~v5a1R~
    POINT pt1={0},pt2={0};                                         //~vafaR~
    int rc;                                                        //~v63iI~
    char *pcg;                                                     //~v003R~
#ifdef UTF8UCS2                                                    //~va20I~
    UINT  txtfmt=CF_TEXT;                                          //~va20I~
#endif                                                             //~va20I~
//************************************                             //~v003I~
    if (Mcpcopysw!=2)            //start mouse blocking            //~v003R~
    {                                                              //~v63iI~
      if (!wxe_capchkxestat())  //closed block by PF-key not exist //~v69ZI~
      {                                                            //~v69ZI~
    	if (rc=mousedragcopychk(),rc)	//drg pending chk          //~v63iI~
        	return rc;                                             //~v63iI~
    	return 4;                                                  //~v003R~
      }                                                            //~v69ZI~
    }                                                              //~v63iI~
  if (Mlbdblclicksw)		//by dblclick                          //~v5a1I~
  {                                                                //~v5a1I~
	if (wxe_capcopy2(Pcutsw,&totlen,Mcellcopy1.y,Mcellcopy1.x))    //~v5a1R~
    {                                                              //~v66wI~
		wxe_capreset();			//reset cap pcw                    //~v66wI~
    	Mcpcopysw=0;           //no more block                     //~v66wI~
    	return 4;                                                  //~v5a1I~
    }                                                              //~v66wI~
#ifdef UTF8UCS2                                                    //~va20I~
    if (totlen<0)                                                  //~va20I~
    {                                                              //~va20I~
        totlen=-totlen;                                            //~va20I~
        txtfmt=CF_UNICODETEXT;                                     //~va20I~
    }                                                              //~va20I~
#endif                                                             //~va20I~
  }                                                                //~v5a1I~
  else                                                             //~v5a1I~
  {                                                                //~v5a1I~
	if (Mcpcopypansw)	//copy from panel data                     //~2A05I~
    {                                                              //~2A05I~
		pt1=Mcellcopy1;                                            //~2A05R~
		pt2=Mcellcopy2;                                            //~2A05I~
#ifdef UTF8UCS2                                                    //~va20R~
		cpcopypan(0/*outaddr=0,get length*/,pt1.y,pt1.x,pt2.y,pt2.x,&totlen);//~va20R~
      if (totlen<0)                                                //~va20R~
      {                                                            //~va20R~
        totlen=-totlen;                                            //~va20R~
        txtfmt=CF_UNICODETEXT;                                     //~va20R~
      }                                                            //~va20R~
      else                                                         //~va20R~
#endif                                                             //~va20R~
      {                                                            //~va20R~
		CAPGETBOX(pt1,pt2);                                        //~2A05I~
		Mcellcopy1=pt1;                                            //~2A05I~
		Mcellcopy2=pt2;                                            //~2A05I~
        row=pt2.y-pt1.y;                                           //~2A05R~
        col=pt2.x-pt1.x+1;                                         //~2A06R~
        totlen=(row+1)*(col+2);                                    //~2A05R~
      }                                                            //~va20R~
    }                                                              //~2A05I~
    else                                                           //~2A05I~
    {                                                              //~va20I~
		if (wxe_capcopy(Pcutsw,&totlen))                           //~2A05R~
    		return 4;                                              //~2A05R~
#ifdef UTF8UCS2                                                    //~va20I~
        if (totlen<0)                                              //~va20I~
        {                                                          //~va20I~
        	totlen=-totlen;                                        //~va20I~
            txtfmt=CF_UNICODETEXT;                                 //~va20I~
        }                                                          //~va20I~
#endif                                                             //~va20I~
    }                                                              //~va20I~
  }                                                                //~v5a1I~
#ifdef AAA                                                         //~va7SI~
    if (Pcutsw) //cut or clear                                     //~v5a1I~
#endif                                                             //~va7SI~
    	Mcpcopysw=0;           //no more block                     //~v5a1I~
	if (!Mpview->OpenClipboard())                                  //~v003M~
    	return uerrlast("OpenClipboard");                          //~v003I~
//  hGlobal=GlobalAlloc(GMEM_MOVEABLE,totlen);                     //~v66zR~
    hGlobal=GlobalAlloc(GMEM_MOVEABLE,(totlen+1));                 //~v66zI~
	if (hGlobal==NULL)                                             //~v003R~
    {                                                              //~v66iI~
//  	return uerrmsgbox("Cut/Paste GlobalAlloc len=%d,rc=%d",0,  //~v66iR~
        uerrmsgbox("Cut/Paste GlobalAlloc len=%d,rc=%d",0,         //~v66iI~
							totlen,GetLastError());                //~v5a1I~
		CloseClipboard();                                          //~v66iI~
        return 4;                                                  //~v66iI~
    }                                                              //~v66iI~
    else                                                           //~v003I~
	{                                                              //~v003I~
		pcg=(char *)GlobalLock(hGlobal);                           //~v003I~
        *(pcg+totlen)=0;                                           //~v66zI~
		if (Mcpcopypansw)	//copy from panel data                 //~2A05I~
        {                                                          //~va20R~
#ifdef UTF8UCS2                                                    //~va20R~
            *pcg=(txtfmt==CF_UNICODETEXT);    //parm to cpcopypan  //~va20R~
			cpcopypan(pcg,pt1.y,pt1.x,pt2.y,pt2.x,0/*outlen*/);    //~va20R~
#else                                                              //~va20R~
			cpcopypan(pcg,pt1.y,pt1.x,pt2.y,pt2.x);                //~2A05R~
#endif                                                             //~va20R~
        }                                                          //~va20R~
        else                                                       //~2A05I~
			wxe_capcopytowincb(pcg,totlen);                        //~2A05R~
		EmptyClipboard();                                          //~v003I~
		GlobalUnlock(hGlobal);                                     //~v003I~
UTRACEP("Clipboard cpcopy fmt=%d\n",txtfmt);                       //~va20I~
UTRACED("Clipboard cpcopy setclipboard data",pcg,totlen);                          //~v66iR~//~va20I~
#ifdef UTF8UCS2                                                    //~va20I~
		SetClipboardData(txtfmt,hGlobal);                          //~va20I~
        Slastcbfmt=txtfmt;                                         //~vb2NI~
#else                                                              //~va20R~
		SetClipboardData(CF_TEXT,hGlobal);                         //~v003I~
#endif                                                             //~va20I~
	}                                                              //~v66iI~
	CloseClipboard();                                              //~v003R~
//#ifdef UTF8UCS2                                                  //~va20R~
//  GlobalFree(hGlobal);  //dont free,windows control it           //~va20R~
//  popup err "can not read memory" will be issued                 //~va20I~
//#endif                                                           //~va20R~
//  Mpview->Invalidate(FALSE);	//request from view also when rc!=0//~v66iR~
    return 0;                                                      //~v003I~
}//cpcopy                                                          //~v003I~
//===============================================================================//~2A05I~
//cut & paste:paste                                                //~2A05I~
//if Pcbdata=0,calc total length                                   //~va20R~
//===============================================================================//~2A05I~
#ifdef UTF8UCS2                                                    //~va20R~
int  CWxemain::cpcopypan(char *Pcbdata,int Prow1,int Pcol1,int Prow2,int Pcol2,int *Pplen)//~va20R~
#else                                                              //~va20R~
int  CWxemain::cpcopypan(char *Pcbdata,int Prow1,int Pcol1,int Prow2,int Pcol2)//~2A05I~
#endif                                                             //~va20R~
{                                                                  //~2A05I~
	char *pc,*pdata,*pdbcs;                                        //~2A05R~
    int row,len;                                                   //~2A05R~
    char dbcstwk[MAXCOL];                                          //~va1bR~
#ifdef UTF8UCS2                                                    //~va20R~
    int totlen,lenucs,swgetlen,opt,swucs=0,swutf8data=0;           //~va20R~
#endif                                                             //~va20R~
//************************************                             //~2A05I~
#ifdef UTF8UCS2                                                    //~va20R~
	swgetlen=(Pcbdata==NULL);    //no output area                  //~va20R~
    if (Pcbdata)                                                   //~va20R~
    	swutf8data=*Pcbdata!=0;                                    //~va20R~
	opt=swgetlen*WXEDTCPO_GETLENGTH;    //no output area           //~va20R~
#endif                                                             //~va20R~
	len=Pcol2-Pcol1+1;                                             //~2A06R~
    pc=Pcbdata;                                                    //~2A05I~
    for (row=Prow1;row<=Prow2;row++)                               //~2A05I~
    {                                                              //~2A05I~
		pdata=(char*)TEXTDATA(row,Pcol1);                          //~2A05R~
		pdbcs=(char*)TEXTDBCS(row,Pcol1);                          //~2A05R~
        len=Pcol2-Pcol1+1;                                         //~va0qR~
     if (Prow1==Prow2)	//1line,not box                            //~va1bI~
     {                                                             //~va1bI~
#ifdef UTF8UCS2                                                    //~va20I~
        if (UDBCSCHK_DBCS1STLU(*(pdbcs+len-1)))	//no GB4 consideration//~va20I~
#else                                                              //~va20I~
        if (*(pdbcs+len-1)==UDBCSCHK_DBCS1ST)                      //~va0qI~
#endif                                                             //~va20I~
            len--;                                                 //~va0qR~
#ifdef UTF8UCS2                                                    //~va20I~
        if (UDBCSCHK_DBCS2NDLU(*pdbcs))                            //~va20I~
#else                                                              //~va20I~
        if (*pdbcs==UDBCSCHK_DBCS2ND)                              //~va0qR~
#endif                                                             //~va20I~
        {                                                          //~va0qI~
            pdata++;                                               //~va0qI~
            pdbcs++;                                               //~va0qI~
            len--;                                                 //~va0qI~
        }                                                          //~va0qI~
     }                                                             //~va1bI~
//      wxe_dbcstextcopy(pc,pdata,pdbcs,len);                      //~2A05I~
		memcpy(dbcstwk,pdbcs,len);                                 //~va1bI~
#ifdef UTF8UCS2                                                    //~va20R~
	  if (!Pcbdata||swutf8data)                                    //~va20R~
      {                                                            //~va20R~
       	if (wxe_dbcstextcopypan(opt,pc,pdata,dbcstwk,len,&lenucs)) //~va20R~
      		swucs=1;                                               //~va20R~
        pc+=lenucs;	//set also crlf                                //~va20R~
      }                                                            //~va20R~
      else                                                         //~va20R~
#endif                                                             //~va20R~
      {                                                            //~va20R~
        wxe_dbcstextcopy(pc,pdata,dbcstwk,len);                    //~va1bI~
        pc+=len;                                                   //~2A05I~
        *pc++='\r';                                                //~2A05I~
        *pc++='\n';      //crlf                                    //~2A05I~
      }                                                            //~va20R~
    }                                                              //~2A05I~
#ifdef UTF8UCS2                                                    //~va20R~
//  totlen=(ULONG)pc-(ULONG)Pcbdata;                               //~va20R~//+vba3R~
    totlen=PTRDIFF(pc,Pcbdata);                                    //+vba3I~
  if (swucs||swutf8data)                                           //~va20R~
  {                                                                //~va20R~
	if (!swgetlen)                                                 //~va20R~
//		*((WUCS*)(ULONG)pc-2)=0;                                   //~va20R~//+vba3R~
  		*((WUCS*)(ULPTR)pc-2)=0;                                   //+vba3I~
UTRACEP("cpcopypan totlen=%d\n",totlen);                           //~va20R~
UTRACEDIFNZ("cpcopypan out\n",Pcbdata,totlen);                     //~va20R~
	if (swucs)                                                     //~va20R~
    	totlen=-totlen;	//notify contins ucs fromm dd fmt          //~va20R~
  }                                                                //~va20R~
  else                                                             //~va20R~
   if (!swgetlen)                                                  //~va20R~
#endif                                                             //~va20R~
    *(pc-2)=0;		//drop last line eol                           //~2A05I~
#ifdef UTF8UCS2                                                    //~va20R~
   	if (Pplen)                                                     //~va20R~
   		*Pplen=totlen;                                             //~va20R~
#endif                                                             //~va20R~
    return 0;                                                      //~2A05I~
}//cpcopypan                                                       //~2A05I~
//===============================================================================//~v003I~
//cut & paste:paste                                                //~v003I~
//parm:0:BlockRep, 1:BlockIns, 2:StdPaste                          //~v66hI~
//===============================================================================//~v003I~
int  CWxemain::cppaste(int Pinssw)                                 //~v003R~
{                                                                  //~v003I~
	HGLOBAL hGlobal;                                               //~v003I~
	int  row,col,totlen=0;                                         //~vafaR~
    char   *pcg;                                                   //~v003R~
    CPoint pointend;                                               //~v003I~
    int opensw=0;                                                  //~v66iI~
	HDROP hdrop;                                                   //~v686R~
    int opt;                                                       //~v686I~
    void *pcwtarget;                                               //~v686I~
    int textpastesw=0;                                             //~v689I~
#ifdef UTF8UCS2                                                    //~va20I~
//  UINT cbdatafmt,cbdatafmtlist[2]={CF_UNICODETEXT,CF_TEXT};      //~va20R//~vafaR~
    UINT cbdatafmt=0,cbdatafmtlist[2]={CF_UNICODETEXT,CF_TEXT};    //~vafaR~
    UINT cbdatafmtlist2[2]={CF_TEXT,CF_UNICODETEXT};    //~vak7I~  //~vb2NR~
#endif                                                             //~va20I~
//#ifndef BBB                                                      //~@@@@R~
//#else                                                            //~@@@@R~
//    HGLOBAL hGlobal2;                                            //~@@@@R~
//    HGLOBAL hGlobal3;                                            //~@@@@R~
//    HGLOBAL hGlobal4;                                            //~@@@@R~
//    char   *pcg2;                                                //~@@@@R~
//    char   *pcg3;                                                //~@@@@R~
//    char   *pcg4;                                                //~@@@@R~
//#endif                                                           //~@@@@R~
//************************************                             //~v003I~
    if (Pinssw & PASTE_TEXT_ONLY)                                  //~v689I~
    {                                                              //~v689I~
    	Pinssw &= ~PASTE_TEXT_ONLY;                                //~v689I~
	    textpastesw=1;                                             //~v689R~
    }                                                              //~v689I~
UTRACEP("@@@@ cppaste parm=%d\n",Pinssw);                          //~v685R~
//  if (!Mcppastesw)                                               //~v686R~
//  	return 4;                                                  //~v686R~
//  row=Mcellcopy1.y;                                              //~v003R~//~va7CR~
//  col=Mcellcopy1.x;                                              //~v003R~//~va7CR~
    row=Mwxeintf.WXEIcsrposy;	//caret pos                        //~v76cI~//~va7CI~
    col=Mwxeintf.WXEIcsrposx;	//caret                            //~v76cR~//~va7CI~
//  if (wxe_cappasteposchk(row,col))                               //~v686R~
//      return 4;                                                  //~v686R~
	if (!Mpview->OpenClipboard())                                  //~v003R~
  {                                                                //~v66iI~
//  	return uerrlast("OpenClipboard Failed");                   //~v66iR~
//  	uerrlast("Paste:OpenClipboard Failed");                    //~v66mR~
        hGlobal=0;                                                 //~v66iI~
  }                                                                //~v66iI~
  else                                                             //~v66iI~
  {                                                                //~v66iI~
#ifdef UTF8UCS2                                                    //~va20I~
  if (Slastcbfmt==CF_TEXT)                                         //~vb2NI~
    cbdatafmt=GetPriorityClipboardFormat(cbdatafmtlist2,2);   //CF_TEXT as primary//~vb2NI~
  else                                                             //~vb2NI~
    cbdatafmt=GetPriorityClipboardFormat(cbdatafmtlist,2);         //~va20R~
  	if ((int)cbdatafmt<=0)	//0:empty,-1:no such fmt data          //~va20R~
    	hGlobal=NULL;                                              //~va20I~
    else                                                           //~va20I~
		hGlobal=(HGLOBAL)GetClipboardData(cbdatafmt);	//unicode or text//~va20R~
//#ifndef BBB                                                      //~@@@@R~
//#else                                                            //~@@@@R~
//    hGlobal2=(HGLOBAL)GetClipboardData(CF_UNICODETEXT); //unicode or text//~@@@@R~
//    pcg2=(char *)GlobalLock(hGlobal2);                           //~@@@@R~
//    hGlobal3=(HGLOBAL)GetClipboardData(CF_TEXT);    //unicode or text//~@@@@R~
//    pcg3=(char *)GlobalLock(hGlobal3);                           //~@@@@R~
//    hGlobal4=(HGLOBAL)GetClipboardData(CF_OEMTEXT); //unicode or text//~@@@@R~
//    pcg4=(char *)GlobalLock(hGlobal4);                           //~@@@@R~
//    UTRACED("CF_UNICODE",pcg2,GlobalSize(hGlobal2));             //~@@@@R~
//    UTRACED("CF_TEXT",pcg3,GlobalSize(hGlobal3));                //~@@@@R~
//    UTRACED("CF_OEMTEXT",pcg4,GlobalSize(hGlobal4));             //~@@@@R~
//#endif                                                           //~@@@@R~
#else                                                              //~va20I~
	hGlobal=(HGLOBAL)GetClipboardData(CF_TEXT);                    //~v003R~
#endif                                                             //~va20M~
//  if (!hGlobal)                                                  //~v66mR~
//  	uerrlast("Paste:GetClipboardData Failed");                 //~v66mR~
//  CloseClipboard();                                              //~v66iR~
	if (!hGlobal)	//no text                                      //~v686R~
    {                                                              //~v686R~
		hdrop=(HDROP)GetClipboardData(CF_HDROP);                   //~v686R~
UTRACEP("@@@@ GetClipboardData hdrop=%x\n",hdrop);                   //~v686R~//~va20R~
		if (hdrop)                                                 //~v686R~
        {                                                          //~v686R~
			CloseClipboard();                                      //~v686R~
          	if (textpastesw)	//paste text request	           //~v689I~
            	return 0;       //no process drop file             //~v689I~
		    Mpwxefile->Mdragfrompcw=0;                             //~v689M~
            wxe_getpcw(&pcwtarget);//current active is target      //~v686I~
            opt=DROPFILE_CP;                                       //~v686R~
            if (Pinssw==0)	//rep mode                             //~v686I~
            	opt|=DROPFILE_REP;                                 //~v686I~
        	return Mpwxefile->ondropfilesub(opt,hdrop,pcwtarget,0,0);//row/col not requred//~v686R~
        }                                                          //~v686R~
    }                                                              //~v686R~
    else                                                           //~v686I~
		if (wxe_cappasteposchk(row,col))                           //~v686I~
        {                                                          //~v686I~
#ifdef UTF8UCS2                                                    //~va20I~
#else                                                              //~va20I~
		    GlobalUnlock(hGlobal);                                 //~v686I~
#endif                                                             //~va20I~
		    CloseClipboard();                                      //~v686I~
			return 4;                                              //~v686I~
        }                                                          //~v686I~
    opensw=1;                                                      //~v66iI~
  }                                                                //~v66iI~
//UTRACEP("@@@@ GetClipboardData hgbl=%x,fmt=%d\n",hGlobal,cbdatafmt);                  //~v685R~//~vafaR~
  if (!hGlobal)                                                    //~v66iI~
    pcg=0;                                                         //~v66iI~
  else                                                             //~v66iI~
  {                                                                //~v66iI~
	pcg=(char *)GlobalLock(hGlobal);                               //~v003R~
//  totlen=GlobalSize(hGlobal);                                    //~v003I~//~vb3wR~
    totlen=(int)GlobalSize(hGlobal);                               //~vb3wI~
UTRACED("@@@@ GetClipboardData",pcg,totlen);                       //~v685R~
  }                                                                //~v66iI~
#ifdef UTF8UCS2                                                    //~va20I~
  if (cbdatafmt==CF_UNICODETEXT)	//UNICODE text                 //~va20R~
	wxe_cappaste((Pinssw&WXECPO_MASK)|WXECPO_UCS,row,col,pcg,totlen);//~va20R~
  else                                                             //~va20I~
#endif                                                             //~va20I~
	wxe_cappaste(Pinssw,row,col,pcg,totlen);                       //~v003R~
                                                                   //~v003I~
  if (hGlobal)                                                     //~v66iI~
    GlobalUnlock(hGlobal);                                         //~v003M~
    if (opensw)	                                                   //~v66iI~
	    CloseClipboard();                                          //~v66iI~
                                                                   //~v003I~
    Mcppastesw=2;                                                  //~v003R~
    Mcpcopysw=0;                                                   //~v003I~
                                                                   //~v003I~
    Mpview->Invalidate(FALSE);                                     //~v003I~
    return 0;                                                      //~v003I~
}//cppaste                                                         //~v003R~
//===============================================================================//~v003I~
//menu disable/enable                                              //~v003I~
//===============================================================================//~v003I~
BOOL CWxemain::cpupdatecopy(void)                                  //~v003R~
{                                                                  //~v003I~
	void *pcw;                                                     //~v63iI~
//*********************                                            //~v63iI~
//  return Mcpcopysw==2;                                           //~v63iR~
//  return (Mcpcopysw==2||wxe_dragselectchk(DRAGOPT_DRAG,0,-1,-1,&pcw,0));//cut&paste or drag select//~v69ZR~
    return (  Mcpcopysw==2                                         //~v69ZI~
            ||wxe_capchkxestat()                                   //~v69ZR~
            ||wxe_dragselectchk(DRAGOPT_DRAG,0,-1,-1,&pcw,0)//cut&paste or drag select//~v69ZI~
            );                                                     //~v69ZI~
}//cpupdatecopy                                                    //~v003I~
//===============================================================================//~v003I~
//menu disable/enable                                              //~v003I~
//===============================================================================//~v003I~
BOOL CWxemain::cpupdatecut(void)                                   //~v003R~
{                                                                  //~v003I~
	if (Mcpcopysw!=2 || Mcpcopypansw)                              //~2A12I~
      if (!wxe_capchkxestat())                                     //~v69ZR~
    	return FALSE;                                              //~2A12I~
//block end and not copy pan                                       //~2A12I~
//  int rc=wxe_capchkprot(Mcellcopy1.y,Mcellcopy1.x);	//no out pcw//~v700R~
//  int rc=wxe_capchkprot(-1,-1);	//no out pcw                   //~v76jR~
    int rc=wxe_capchkprot(0,-1,-1);	//no out pcw                   //~v76jI~
    if (rc>0)	//protected                                        //~2A12I~
    	return FALSE;                                              //~2A12I~
    return TRUE;		//paste avail                              //~2A12I~
}//cpupdatecopy                                                    //~v003I~
//===============================================================================//~v003I~
//menu disable/enable                                              //~v003I~
//===============================================================================//~v003I~
BOOL CWxemain::cpupdatepaste(void)                                 //~v003R~
{                                                                  //~v003I~
	int rc2;                                                       //~v686I~
    int row,col;                                                   //~va7DR~
//****************************                                     //~v686I~
UTRACEP("updatepaste Mcpcopysw=%d\n",Mcpcopysw);                   //~v76jI~
//  if (Mcpcopysw==2 || Mcppastesw!=1)                             //~v514R~
//  if (Mcpcopysw==2 || !Mcppastesw)                               //~v686R~
    if (Mcpcopysw==2)                                              //~v686I~
    	return FALSE;                                              //~2A12I~
//!block close and not after lbdown                                //~2A12I~
	if (rc2=cppastedropchk(0),rc2>=0)	//0:paste ins/rep          //~v686R~
    	return rc2;                                                //~v686R~
//  int rc=wxe_capchkprot(Mcellcopy1.y,Mcellcopy1.x);	//no out pcw//~v76jR~
//  int rc=wxe_capchkprot(0,Mcellcopy1.y,Mcellcopy1.x);	//no out pcw//~va7DR~
    row=Mwxeintf.WXEIcsrposy;	//caret pos                        //~va7DR~
    col=Mwxeintf.WXEIcsrposx;	//caret                            //~va7DR~
    int rc=wxe_capchkprot(0,row,col);	//no out pcw               //~va7DR~
    if (rc>0)	//protected                                        //~2A12I~
    	return FALSE;                                              //~2A12I~
    return TRUE;		//paste avail                              //~2A12I~
}//cpupdatepaste                                                   //~v76jR~
//===============================================================================//~v66iI~
//menu disable/enable for Ctrl+v                                   //~v66iI~
//===============================================================================//~v66iI~
BOOL CWxemain::cpupdatepastestd(void)                              //~v66iI~
{                                                                  //~v66iI~
	int rc2;                                                       //~v686I~
    int opt;                                                       //~v76jR~
    int row,col,rc;                                                //~va7DR~
//****************************                                     //~v686I~
UTRACEP("updatepastestd Mcpcopysw=%d\n",Mcpcopysw);                //~v76jI~
//  if (!Mcppastesw)	//allow after draged started status        //~v686R~
//  	return FALSE;                                              //~v686R~
	if (rc2=cppastedropchk(1),rc2>=0)  //1:pastev                  //~v686R~
    	return rc2;                                                //~v686R~
//  int rc=wxe_capchkprot(Mcellcopy1.y,Mcellcopy1.x);	//no out pcw//~v76jR~
    opt=WXECCP_STDPASTE;                                           //~v76jI~
	if (Mcpcopysw==2)	//box or rgn drawn                         //~v76jI~
    	opt=WXECCP_DRAGED;                                         //~v76jR~
//  int rc=wxe_capchkprot(opt,Mcellcopy1.y,Mcellcopy1.x);	//no out pcw//~va7DR~
    row=Mwxeintf.WXEIcsrposy;	//caret pos                        //~va7DR~
    col=Mwxeintf.WXEIcsrposx;	//caret                            //~va7DR~
    rc=wxe_capchkprot(opt,row,col);	//no out pcw                   //~va7DR~
    if (rc>0)	//protected                                        //~v66iI~
    	return FALSE;                                              //~v66iI~
    return TRUE;		//paste avail                              //~v66iI~
}//cpupdatepastestd                                                //~v76jR~
//===============================================================================//~v686I~
//drop by paste target chk                                         //~v686I~
//rc:0:false,1:true,-1:not drop file                               //~v686I~
//===============================================================================//~v686I~
int CWxemain::cppastedropchk(int Popt)                             //~v686R~
{                                                                  //~v686I~
    int droppending=0;                                             //~v686I~
    int rc=-1;                                                     //~v686I~
    void *pcwt;                                                    //~v686R~
    int pctype;                                                    //~v76jI~
//*******************                                              //~v686I~
	if (Mpview->OpenClipboard())    //seccess                      //~v686I~
    {                                                              //~v686I~
		if (GetClipboardData(CF_HDROP))//drop pending file         //~v686I~
        	droppending=1;                                         //~v686I~
        CloseClipboard();                                          //~v686I~
    }                                                              //~v686I~
    if (droppending)                                               //~v686I~
    {                                                              //~v686I~
        rc=0;   //FALSE                                            //~v686I~
//  	rc=wxe_dropselectchk(Popt);	//target dir line selection chk//~v686R~
        if (wxe_getpcw(&pcwt)!=PRTTYPE_DIR)//current pcw is not dirlist//~v686I~
        {                                                          //~v686I~
            pctype=wxe_getpcwsubtype(pcwt);	//UPCid                //~v76jI~
          if (pctype==WXECWST_UCOMP                                //~v76jI~
          ||  pctype==WXECWST_UGREP)                               //~v76jI~
          {                                                        //~v76jI~
            if (!(Popt & 0x01))    //reject pastev(pastev for other panel is edit the file)//~v76jI~
            	rc=1;              //accept ins/rep                //~v76jI~
          }                                                        //~v76jI~
          else                                                     //~v76jI~
            if (Popt & 0x01)    //accept pastev                    //~v686I~
                rc=1;       //accept paste                         //~v686I~
        }                                                          //~v686I~
        else                                                       //~v686I~
        {                                                          //~v686I~
            if (!(Popt & 0x01)) //paste ins/rep                    //~v686I~
                rc=1;                                              //~v686I~
        }                                                          //~v686I~
    }                                                              //~v686I~
    return rc;		//chk CF_TEXT                                  //~v686R~
}//cppastedropchk                                                  //~v686I~
//===============================================================================//~2A13I~
//mouse wheel                                                      //~2A13I~
//flag:virtual key conbination                                     //~2A13I~
//delta:<0;forward scrool,>0:backward scroll                       //~2A13I~
//===============================================================================//~2A13I~
BOOL CWxemain::onmousewheel(UINT nFlags, short zDelta, CPoint pt)  //~2A13I~
{                                                                  //~2A13I~
//UTRACEP("onmousewheel flag=%x,delta=%x,(%x,%x)\n",nFlags,zDelta,pt.x,pt.y);//~v53bR~
    wxe_scroll(Mscrollctr,nFlags,zDelta);                          //~2A20R~
    Mpview->Invalidate(FALSE);                                     //~2A13I~
    return TRUE;		//paste avail                              //~2A13I~
}//onmousewheel                                                    //~v69ZR~
//===============================================================================//~3102I~
//mouse wheel                                                      //~3102I~
//flag:virtual key conbination                                     //~3102I~
//ret:1 processed,0:do default action at return                    //~3102I~
//===============================================================================//~3102I~
BOOL CWxemain::mouselbdblclk(UINT nFlags,CPoint pt)                //~3102I~
{                                                                  //~3102I~
	int rc,row,col,capinfo,cpid;                                   //~v5a1R~
//************************                                         //~3102I~
UTRACEP("@@@@mouse dbl click flag=%x,(%d,%d)\n",nFlags,pt.x,pt.y); //~v68bR~
    col=COL(pt.x);                                                 //~3102I~
    row=ROW(pt.y);                                                 //~3102I~
    Mlbdblclicksw=1;                                               //~v5a1I~
    rc=wxe_lineselect(nFlags,row,col,&capinfo);                    //~3202R~
    if (rc==-1)                                                    //~3102I~
    	exitmain();                                                //~3102I~
    if (capinfo)                                                   //~v5a1I~
    {                                                              //~v5a1I~
		wxe_capreset();                                            //~v5a1I~
    	cpid=0;                                                    //~v5a1I~
//        if (nFlags & MK_SHIFT)          //with shift key         //~v5a1R~
//            cpid=1;     //cut                                    //~v5a1R~
//        else                                                     //~v5a1R~
//        if (nFlags & MK_CONTROL)        //with shift key         //~v5a1R~
//            cpid=2;     //clear                                  //~v5a1R~
        if (nFlags & (MK_SHIFT|MK_CONTROL))  //with shift key      //~v53AI~
        	return 4;	//push+shift means paste;push & dblclick msg when dblclick//~v53AI~
        Mcellcopy1.x=col;                                          //~v5a1I~
        Mcellcopy1.y=row;                                          //~v5a1I~
        Mcellcopy2.x=col;                                          //~v5a1I~
        Mcellcopy2.y=row;                                          //~v5a1I~
    	Mcpcopysw=2;            //enable copy/cut/clear menu       //~v5a1I~
		cpcopy(cpid);                                              //~v5a1I~
    }                                                              //~v5a1I~
    Mpview->Invalidate(FALSE);                                     //~3102I~
    return rc;                                                     //~3102I~
}//mouselbdblclk                                                   //~3102I~
//===============================================================================//~v69fI~
//5 button mouse(browser back/forward) support                     //~v69fI~
//===============================================================================//~v69fI~
BOOL CWxemain::mouseappcmd(int Pappcmdid)                          //~v69fI~
{                                                                  //~v69fI~
    int rc=FALSE;                                                  //~v69fI~
//************************                                         //~v69fI~
    switch(Pappcmdid)                                              //~v69fI~
    {                                                              //~v69fI~
    case APPCOMMAND_BROWSER_BACKWARD:                              //~v69fR~
        rc=wxe_browsercmd(-1);                                     //~v69fR~
        break;                                                     //~v69fI~
    case APPCOMMAND_BROWSER_FORWARD:                               //~v69fR~
        rc=wxe_browsercmd(1);                                      //~v69fR~
        break;                                                     //~v69fI~
    }                                                              //~v69fI~
    if (rc==TRUE)                                                  //~v69fI~
	    Mpview->Invalidate(FALSE);                                 //~v69fI~
    return rc;                                                     //~v69fI~
}//mouseappcmd                                                     //~v69fI~
//**************************************************************** //~v5a1I~
//*return elapsed time                                             //~v5a1I~
//**************************************************************** //~v5a1I~
int CWxemain::ontimer(UINT Pid)                                    //~v5a1I~
{                                                                  //~v5a1I~
    int   dest,flag;                                               //~v5a1I~
    int rc/*,opt*/;                                                //~v63kR~
//****************************                                     //~v5a1I~
//  Mscrolltimereventctr++; //timer                                //~v53bR~
//UTRACEP("scroll:ontimer posid=%x,Pid=%x,eventctr=%d\n",Mlbposid,Pid,Mscrolltimereventctr);//~v53bR~
    if (Pid & TID_ATCMD)                                           //~v55WI~
        return ontimeratcmd(Pid);                                  //~v55WR~
//    if (Pid & TID_DRAGDROP)                                      //~v63kR~
//    {                                                            //~v63kR~
//        opt=DRAG_RESETDRAW;                                      //~v63kR~
//UTRACEP("ontimer dragdrop stat=%x\n",Mpwxefile->Mswdndinprogress);//~v63kR~
//        if (Mpwxefile->Mswdndinprogress)    //in progress        //~v63kR~
//        {                                                        //~v63kR~
//            Mpwxefile->Mswdndinprogress=0;    //avoid drop on my self//~v63kR~
//            opt|=DRAG_RESETMSG;                 //reset count msg//~v63kR~
//        }                                                        //~v63kR~
//UTRACEP("ontimer dragdrop opt=%x\n",opt);                        //~v63kR~
//        wxe_dragreset(Mdragpcw,opt); //reset draged file list    //~v63kR~
//        Mpview->KillTimer(Pid);                                  //~v63kR~
//        Mpview->Invalidate(FALSE);                               //~v63kR~
//UTRACEP("ontimer dragdrop return\n",opt);                        //~v63kR~
//        return TRUE;                                             //~v63kR~
//    }                                                            //~v63kR~
	if (Pid & TID_SCROLLCHK)	//scroll chk timer                 //~v5a1I~
    {                                                              //~v5a1I~
    	if (Mlbposid==(int)Pid)	//mouse not moved in the interval  //~v5a1R~
    	{                                                          //~v5a1I~
			Mscrolltimereventctr++; //timer                        //~v53bI~
          	if (Mscrolltimereventctr<=DEF_SCROLLINITWAIT)          //~v51uR~
          		return TRUE;                                       //~v51uI~
          	                                                       //~v51uI~
        	if (Pid & TID_SCLEFT)                                  //~v5a1R~
            {                                                      //~v5a1I~
//          	flag=MK_CONTROL;	//simulate ctrl+               //~v69TR~
            	flag=MK_SHIFT;	//simulate shift+ for horizontal scroll//~v69TI~
            	dest=1;     //backword                             //~v5a1R~
	    		wxe_scroll(Mscrollctr,flag,dest);                  //~v5a1I~
            }                                                      //~v5a1I~
            else                                                   //~v5a1I~
        	if (Pid & TID_SCRIGHT)                                 //~v5a1I~
            {                                                      //~v5a1I~
//          	flag=MK_CONTROL;	//simulate ctrl+               //~v69TR~
            	flag=MK_SHIFT;	//simulate shift+ for horizontal scroll//~v69TI~
            	dest=-1;	//forward                              //~v5a1I~
	    		wxe_scroll(Mscrollctr,flag,dest);                  //~v5a1I~
            }                                                      //~v5a1I~
                                                                   //~v5a1I~
            if (Pid & TID_SCTOP)                                   //~v5a1R~
            {                                                      //~v5a1I~
            	flag=0;                                            //~v5a1I~
            	dest=1;     //backword                             //~v5a1R~
	    		wxe_scroll(Mscrollctr,flag,dest);                  //~v5a1I~
            }                                                      //~v5a1I~
            if (Pid & TID_SCBOTTOM)                                //~v5a1I~
            {                                                      //~v5a1I~
            	flag=0;                                            //~v5a1I~
            	dest=-1;	//forward                              //~v5a1I~
                rc=                                                //~v58iI~
	    		wxe_scroll(Mscrollctr,flag,dest);                  //~v5a1I~
                if (rc==1)  //reached to EOL                       //~v58iI~
          			Mscrolltimereventctr=0;	//wait by initialwaittime//~v58iI~
            }                                                      //~v5a1I~
//UTRACEP("scroll:ontimer scrolled posid=%x,Pid=%x\n",Mlbposid,Pid);//~v53bR~
    		Mpview->Invalidate(FALSE);                             //~v5a1I~
		    return TRUE;		//paste avail                      //~v5a1I~
        }                                                          //~v5a1I~
    }                                                              //~v5a1I~
//UTRACEP("scroll:kill timer posid=%x,Pid=%x\n",Mlbposid,Pid);     //~v53bR~
//  Mpview->KillTimer(Pid);                                        //~v795R~
    ukilltimer(Pid);                                               //~v795I~
    Mscrolltimereventctr=0; //timer ctr                            //~v51uI~
    return 0;                                                      //~v5a1I~
}//ontimer                                                         //~v5a1I~
//**************************************************************** //~v5a1I~
//*return elapsed time                                             //~v5a1I~
//**************************************************************** //~v5a1I~
int CWxemain::mousescrollchk(int Pcol,int Prow)                    //~v5a1R~
{                                                                  //~v5a1I~
	int posid,ms;                                                  //~v510R~
//****************************                                     //~v5a1I~
	ms=Mscrolltimer;                                               //~v510I~
    if (!ms)                                                       //~v510I~
    	return 4;                                                  //~v510I~
	for (;;)                                                       //~v5a1I~
    {                                                              //~v5a1I~
    	if (posid=wxe_mouseedgechk(Pcol,Prow),!posid)	//chk file scr edge//~v5a1I~
        	break;                                                 //~v5a1I~
    	posid=TID_SCROLLCHK|posid;                                 //~v5a1I~
        if (Mlbposid!=posid)                                       //~v5a1I~
        {                                                          //~v51uI~
                                                                   //~v51uI~
//UTRACEP("scroll:starttimer posid=%x,col=%d,row=%d\n",posid,Pcol,Prow);//~v53bR~
//		    Mpview->SetTimer(posid,ms,NULL/*callback*/);           //~@@@@R~
  		    Mpview->SetTimer(posid,ms);                            //~@@@@I~
            Mscrolltimereventctr=0; //start timer                  //~v51uI~
        }                                                          //~v51uI~
//UTRACEP("scroll:continueed timer posid=%x,col=%d,row=%d\n",posid,Pcol,Prow);//~v53bR~
        Mlbposid=posid;                                            //~v5a1I~
    	return 1;                                                  //~v5a1I~
    }                                                              //~v5a1I~
//UTRACEP("scroll:set 0 posid posid=%x,col=%d,row=%d\n",posid,Pcol,Prow);//~v53bR~
    Mlbposid=0;                                                    //~v5a1I~
    return 0;                                                      //~v5a1I~
}//mousescrollchk                                                  //~v5a1I~
//===============================================================================//~v63hM~
//add file to drag filename list                                   //~v63hM~
//===============================================================================//~v63hM~
void CWxemain::mousedragfile(int Pdragopt,void *Ppcw,void* Pplh)   //~v63hR~
{                                                                  //~v63hM~
	void *plh1,*plh2;                                              //~v63hM~
//************************************                             //~v63hM~
    if	(Pdragopt & DRAGCHK_NEW)                                   //~v63hM~
    {                                                              //~v63hM~
        wxe_dragreset(Ppcw,0);                                     //~v63hR~
        plh1=plh2=Pplh;                                            //~v63hM~
        Mdragplhs=Pplh;                                            //~v63hM~
        Mdragpcw=Ppcw;                                             //~v63pI~
    }                                                              //~v63hM~
    else                                                           //~v63hM~
    if	(Pdragopt & DRAGCHK_ADD)                                   //~v63hM~
    {                                                              //~v63hM~
        plh1=plh2=Pplh;                                            //~v63hM~
        Mdragplhs=Pplh;                                            //~v63hR~
        Mdragpcw=Ppcw;                                             //~v63pI~
    }                                                              //~v63hM~
    else	//range                                                //~v63hR~
    {                                                              //~v63hM~
//  	if (Mdragplhs)                                             //~v63pR~
    	if (Mdragplhs && Ppcw==Mdragpcw)                           //~v63pI~
	    	plh1=Mdragplhs;                                        //~v63hM~
        else                                                       //~v63hM~
        {                                                          //~v63pI~
	        wxe_dragreset(Ppcw,0);                                 //~v63pI~
        	plh1=Pplh;                                             //~v63hM~
	        Mdragplhs=Pplh;                                        //~v63pI~
    	    Mdragpcw=Ppcw;                                         //~v63pI~
        }                                                          //~v63pI~
        plh2=Pplh;                                                 //~v63hM~
    }                                                              //~v63hM~
    wxe_dragset(Ppcw,plh1,plh2);                                   //~v63hR~
	((CMainFrame*)Mpmainframe)->enablemainmenu();	//main menu enable/disable//~v682I~
    Mpview->Invalidate(FALSE);                                     //~v63hM~
    return;                                                        //~v63hM~
}//mousedragfile                                                   //~v63hM~
//===============================================================================//~v63hI~
//request dragdrop                                                 //~v63hI~
//return DoDragDrop rc                                             //~v63hI~
//===============================================================================//~v63hI~
int  CWxemain::mousedodrag(void *Ppcw,int Popt)                    //~v63iR~
{                                                                  //~v63hI~
    char *dragbuff;                                                //~v63hI~
    int buffsz,rc/*,posid*/;                                       //~v63kR~
//  COleDataSource DropData;                                       //~@@@@R~
//************************************                             //~v63hI~
	rc=wxe_dragdropfilelist(DRAG_REDRAW,Ppcw,0,&buffsz);           //~v63iR~
    if (rc)                                                        //~v63hI~
    	return 0;                                                  //~v63hR~
    if (!buffsz)                                                   //~v63hI~
    	return 0;                                                  //~v63hI~
    buffsz+=sizeof(DROPFILES)+2;	//\0\0 for terminater          //~v63hI~
    dragbuff=(char*)umemalloc(buffsz);                             //~v63hR~
    if (!dragbuff)                                                 //~v63hI~
    	return 0;                                                  //~v63hI~
    memset(dragbuff,0,(UINT)buffsz);                               //~v63hI~
	((DROPFILES*)dragbuff)->pFiles=sizeof(DROPFILES);//filename list offset//~v63hI~
	rc=wxe_dragdropfilelist(DRAG_REDRAW|DRAG_REMOTECOPY,Ppcw,dragbuff+sizeof(DROPFILES),0);//~v63iR~
    if (rc)                                                        //~v63hI~
    {                                                              //~v63iI~
		umemfree(dragbuff);                                        //~v63iI~
    	return 0;                                                  //~v63hR~
    }                                                              //~v63iI~
    HGLOBAL hMem = ::GlobalAlloc(GMEM_ZEROINIT|GMEM_MOVEABLE|GMEM_DDESHARE,buffsz);//~v63hI~
    memcpy( (char*)::GlobalLock(hMem),dragbuff,buffsz);            //~v63hI~
    ::GlobalUnlock(hMem);                                          //~v63hI~
	umemfree(dragbuff);                                            //~v63hI~
                                                                   //~v63hI~
	if (Popt & DNDDODRAG_COPY)                                     //~v63iI~
    	return mousedragcopy(Ppcw,hMem);                           //~v63iI~
//  DropData.CacheGlobalData( CF_HDROP, hMem );                    //~@@@@R~
//  DROPEFFECT de = DropData.DoDragDrop(DROPEFFECT_COPY|DROPEFFECT_MOVE,NULL);//~v63hR~
//  Mpwxefile->Mswdndinprogress=1;    //avoid drop on my self      //~v63kR~
//  Mpview->DragAcceptFiles(FALSE);   //reject drop on myself      //~v685R~
	Mdragstatus=1;                                                 //~v685I~
    Mpwxefile->Mdragfrompcw=Ppcw;                  //drag source pcw//~v685R~
UTRACEP("@@@@dodragdrop start\n");                                 //~v685R~
//  DROPEFFECT de = DropData.DoDragDrop(DROPEFFECT_COPY,NULL);     //~@@@@R~
//  Mpview->DragAcceptFiles(TRUE);      //accept drop              //~v685R~
	int de=dragoutfile(hMem);                                      //~@@@@R~
    if (de)	//drop accepted                                        //~v63hR~
    {                                                              //~v63hI~
		Mdragstatus=2;	//clear pcw at 1st mousemove               //~v685I~
//  	Mdragpcw=Ppcw;                                             //~v63kR~
//  	posid=TID_DRAGDROP;                                        //~v63kR~
//  	Mpview->SetTimer(posid,10,NULL);	//reset dragdrop inprogress sw after 10ms//~v63kR~
//      wxe_dragreset(Ppcw,DRAG_RESETDRAW|DRAG_RESETMSG); //reset draged file list//~v685R~
    }                                                              //~v63hI~
    else                                                           //~v63hI~
    {                                                              //~v63hI~
		Mdragstatus=0;                                             //~v685I~
//  	wxe_dragreset(Ppcw,DRAG_RESETDRAW); //reset draged file list//~v685R~
//      Mpwxefile->Mswdndinprogress=0;    //no progress            //~v63kR~
	    Mpwxefile->Mdragfrompcw=0;                                 //~v685I~
        wxe_uerrmsg("DragDrop is Canceled",0);                     //~v709R~
    }                                                              //~v63hI~
    return de;                                                     //~v63hI~
}//mousedodrag                                                     //~v63hI~
//===============================================================================//~@@@@I~
//*dragout file                                                    //~@@@@I~
//===============================================================================//~@@@@I~
int  dragoutfile(HGLOBAL Phmem)                                    //~@@@@R~
{                                                                  //~@@@@I~
	DataObject	*dobj;                                             //~@@@@R~
	DropSource	*dsrc;                                             //~@@@@R~
    DWORD		dwEffect;                                          //~@@@@R~
//  char		*p[1];                                             //~@@@@I~
//  int	ret;                                                       //~@@@@R~
//************************************                             //~@@@@I~
	dobj = new DataObject();                                       //~@@@@R~
	dobj->AddRef();                                                //~@@@@R~
    FORMATETC etc={CF_HDROP,NULL,DVASPECT_CONTENT,-1,TYMED_HGLOBAL};//~@@@@I~
    dobj->m_vfmtetc.push_back(etc);                                //~@@@@I~
    dobj->set_hglobal(Phmem);                                      //~@@@@I~
	dsrc = new DropSource();                                       //~@@@@I~
	dsrc->AddRef();                                                //~@@@@I~
	int rc=DoDragDrop(dobj,dsrc,DROPEFFECT_COPY,&dwEffect);        //~@@@@I~
//*rc:DRAGDROP_S_DROP(0x00040100)/DRAGDROP_S_CANCEL(0x00040101),E_UNSPEC//~@@@@M~
UTRACEP("@@@@dodragdrop return rc=%d\n",rc);                       //~@@@@I~
    if (rc==DRAGDROP_S_DROP)	//drop accepted   0x00040100       //~@@@@R~
        rc=1;       //done                                         //~@@@@I~
    else                                                           //~@@@@I~
        rc=0;                                                      //~@@@@I~
    return rc;                                                     //~@@@@R~
}//dragfile                                                        //~@@@@R~
//===============================================================================//~@@@@I~
void CreateMedium(CLIPFORMAT cfFormat, HANDLE hObject, FORMATETC *pFormatetc, STGMEDIUM *pmedium)//~@@@@I~
{                                                                  //~@@@@I~
	pFormatetc->cfFormat = cfFormat;                               //~@@@@I~
	pFormatetc->dwAspect = DVASPECT_CONTENT;                       //~@@@@I~
	pFormatetc->lindex = -1;                                       //~@@@@I~
	pFormatetc->ptd = NULL;                                        //~@@@@I~
	pFormatetc->tymed = TYMED_HGLOBAL;                             //~@@@@I~
                                                                   //~@@@@I~
	pmedium->hGlobal = hObject;                                    //~@@@@I~
	pmedium->tymed = TYMED_HGLOBAL;                                //~@@@@I~
	pmedium->pUnkForRelease = NULL;                                //~@@@@I~
}                                                                  //~@@@@I~
//===============================================================================//~v63iI~
//copy dropfilename to clipboard                                   //~v686R~
//===============================================================================//~v63iI~
int  CWxemain::mousedragcopy(void * Ppcw,HGLOBAL Phmem)            //~v63iR~
{                                                                  //~v63iI~
//************************************                             //~v63iI~
	if (!Mpview->OpenClipboard())                                  //~v63iI~
    	return uerrlast("OpenClipboard");                          //~v63iI~
	EmptyClipboard();                                              //~v63iI~
	SetClipboardData(CF_HDROP,Phmem);                              //~v63iI~
UTRACEP("Clipboard mousedragcopy \n");                             //~va20R~
	CloseClipboard();                                              //~v63iI~
    return 0;                                                      //~v63iI~
}//mousedragcopy                                                   //~v63iI~
//===============================================================================//~v63iI~
//copy drop file by edit_copy                                      //~v63iI~
//===============================================================================//~v63iI~
int  CWxemain::mousedragcopychk(void)                              //~v63iR~
{                                                                  //~v63iI~
	void *pcw;                                                     //~v63iI~
//************************************                             //~v63iI~
	if (!wxe_dragselectchk(DRAGOPT_DRAG,0,-1,-1,&pcw,0))	//-1:curr pcw,no pending drag//~v63iI~
    	return 0;		//do nothing                               //~v63iI~
	return mousedodrag(pcw,DNDDODRAG_COPY);                        //~v63iI~
}//mousedragcopychk                                                //~v63iI~
//===============================================================================//~v69gI~
//scroll msg                                                       //~v69gI~
//===============================================================================//~v69gI~
int CWxemain::mousescrollbar(int Pmsg,int Pscrollcode)             //~v69gI~
{                                                                  //~v69gI~
	int rc=TRUE,msg,scrollcode,sstat,flags;                        //~v69gR~
//************************************                             //~v69gI~
UTRACEP("mousescrollbar msg=%x,scrollcode=%x\n",Pmsg,Pscrollcode); //~v69gR~
	switch(Pscrollcode)                                            //~v69gI~
    {                                                              //~v69gI~
    case SB_ENDSCROLL:                                             //~v69gI~
    	msg=(int)((ULONG)Mscrollcode>>16);                         //~v69gI~
    	scrollcode=(int)(Mscrollcode & 0xffff);                    //~v69gI~
        if (msg==WM_HSCROLL)                                       //~v69gI~
        {                                                          //~v69gI~
            switch(scrollcode)                                     //~v69gR~
            {                                                      //~v69gR~
            case SB_LINERIGHT:                                     //~v69gR~
                wxe_scrollhbar(Mscrollctr,1);                      //~v69gR~
                break;                                             //~v69gR~
            case SB_LINELEFT:                                      //~v69gR~
                wxe_scrollhbar(Mscrollctr,-1);                     //~v69gR~
                break;                                             //~v69gR~
    	    default:                                               //~v69gI~
        		rc=FALSE;                                          //~v69gI~
            }                                                      //~v69gI~
        }                                                          //~v69gI~
        else                                                       //~v69gI~
        {                                                          //~v69gI~
        	flags=0;                                               //~v69gI~
		    sstat=ugetkbdshiftstatus(0);	//                     //~v69gR~
            if (sstat & WXEKBDMSG_SHIFTKEY)                        //~v69gR~
            	flags|=VK_SHIFT;                    //endpage      //~v69gI~
            if (sstat & WXEKBDMSG_CTLKEY)                          //~v69gR~
            	flags|=VK_CONTROL;                  //horizontal scroll//~v69gI~
        	switch(scrollcode)                                     //~v69gI~
            {                                                      //~v69gI~
            case SB_LINEUP:                                        //~v69gR~
                wxe_scroll(Mscrollctr,flags,1);     //0:with no shift key,1:backward//~v69gR~
                break;                                             //~v69gR~
            case SB_LINEDOWN:                                      //~v69gR~
                wxe_scroll(Mscrollctr,flags,-1);    //0:with no shift key,-1:forward//~v69gR~
                break;                                             //~v69gR~
            default:                                               //~v69gR~
                rc=FALSE;                                          //~v69gR~
            }                                                      //~v69gR~
        }                                                          //~v69gI~
        if (rc==TRUE)                                              //~v69gI~
	        scrinvalidate();                                       //~v69gI~
    	break;                                                     //~v69gI~
    default:                                                       //~v69gI~
    	Mscrollcode=(Pmsg<<16)|Pscrollcode;                        //~v69gR~
        rc=FALSE;                                                  //~v69gI~
    }                                                              //~v69gI~
    return rc;                                                     //~v69gI~
}//mousescrollbar                                                  //~v69gI~
//===============================================================================//~v69ZI~
//global function:reset Mcpcopysw by reset key operation(called from xecap.c)//~v69ZI~
//===============================================================================//~v69ZI~
void wxemouse_capi(int Popt,void *Ppmain)                          //~v69ZR~
{                                                                  //~v69ZI~
static CWxemain *Spmain;                                           //~v69ZR~
//*******************************                                  //~v69ZI~
	if (Popt==WXEM_INIT)                                           //~v69ZR~
    {                                                              //~v69ZI~
    	Spmain=(CWxemain*)Ppmain;                                  //~v69ZR~
        return;                                                    //~v69ZI~
    }                                                              //~v69ZI~
	if (Popt==WXEM_RESET)                                          //~v69ZI~
    {                                                              //~v69ZI~
        Spmain->Mcpcopysw=0;                                       //~v69ZR~
        Spmain->Mcpcopypansw=0;                                    //~v69ZR~
        ((CMainFrame*)(Spmain->Mpmainframe))->enablemainmenu(); //main menu enable/disable//~v69ZR~
        return;                                                    //~v69ZI~
    }                                                              //~v69ZI~
	if (Popt==WXEM_SETRGN)                                         //~v69ZI~
    {                                                              //~v69ZI~
        ((CMainFrame*)(Spmain->Mpmainframe))->enablemainmenu(); //re-evaluate menu enable/disable//~v69ZR~
        return;                                                    //~v69ZI~
    }                                                              //~v69ZI~
    return;                                                        //~v69ZI~
}//wxemouse_capreset                                               //~v69ZI~
//===============================================================================//~va7DI~//~va7CI~
//csr pos change by kbd operation (assume lb down)                 //~va7DI~//~va7CI~
//===============================================================================//~va7DI~//~va7CI~
int CWxemain::mouse_csrmovedbykbd(int Popt)                                   //~va7DR~//~va7CR~
{                                                                  //~va7DI~//~va7CI~
//*******************************                                  //~va7DI~//~va7CI~
#ifdef AAA                                                         //~va7SI~
  if (Mwxeintf.WXEIcsrmovesw==2)  //not by mouse but kbd           //~va7SI~
  {                                                                //~va7SI~
    if (Mcpcopysw==2) //mouse dragged                              //~va7DI~//~va7CI~
    	Mcpcopysw=0;                                               //~va7DI~//~va7CI~
    if (Mcppastesw==2) //mouse dragged                             //~va7DI~//~va7CI~
    	Mcppastesw=0;                                              //~va7DI~//~va7CI~
  }                                                                //~va7SI~
#endif                                                             //~va7SI~
    ((CMainFrame*)Mpmainframe)->enablemainmenu();	//main menu enable/disable//~va7CM~
    return 0;                                                      //~va7DI~//~va7CI~
}//mouse_csrmovedbykbd                                             //~va7CI~
