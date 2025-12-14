//*CID://+vbs1R~:                             update#=  488;       //+vbs1R~
//******************************************************************************//~v003I~
//vbs1:201022 ftime deprecated(ftime is obsoleted POSIX2008)       //+vbs1I~
//vbj4:180425 click on selected line cmd history list-->"s"(set on under)//~vbj4I~
//vbj3:180425 double click on cmd history list-->"x"(exec on under)//~vbj3I~
//vbj2:180424 popup menu on cmd history list                       //~vbj2I~
//vbh2:180129 wxe/gxe copypasete  clipboad len=ulhlen but copy data width CID dropped,trashdata cap data len drop CID;so dreg data is copyed at paste//~vbh2I~
//vbd8:171120 (WXE)stdregion by PFK(F6) should disable Paste REP/INS//~vbd8I~
//vbd2:171114 (Wxe)Add SelectAll menuitem                          //~vbd2I~
//vb94:170228 (Coding:bug)stdo is duplicated with jnic2j           //~vb94I~
//vb7A:170130 (gxe:Bug)accept msg even if drop failed
//vb7z:170131 (gxe:bug)dirlist file drag cause scroll
//vb7v:170128 (gxe:GTK3 BUG)DragDrop hung                          //~vb7zR~
//var8:140127 gtk3 suppott                                         //~var8I~
//vam0:130911 for distro removed gnome-print,use GTKprint          //~vam0I~
//vaa7:111117 (gcc4.6)Warning:unused-but-set                       //~vaa7I~
//va7S:100907 (BUG)mouse drag at edge of screen dose not expand copy range bat scroll.//~va7SI~
//va7D:100830 (XXE:BUG)cap menu update err(it should not be based on Mcellcopy1 bur Gcsrposy)//~va7DI~
//va7C:100830 (XXE:BUG)abend when paste to cmdline from filearea by mouse(Gwxecapdbcs was cleared)//~va7CI~
//            if kbd was used to move cursor                       //~va7CI~
//va70:000701 LP64 option support. at first chk PTR sz(ini file comaptibility)//~va70I~
//va53:100419 num setr/seti should chk margin/lrecl overflow       //~va53I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//va1c:091030_merge GB18030 support                                //~va1cI~
//va1b:091028_(BUG)va0q is not required splitdbcs set space for splitdbcs//~va1bI~
//                 but dbcstbl clear by setdbcssplit should be recovered//~va1bI~
//va0q:090907 (XXE:BUG)mouse cap from cmdline append space at last //~va0qI~
//v76j:070626 (WXEXXE)dnd by paste to utility panel                //~v76jI~
//v76g:070620 utility panel(3.14:grep and 3.12:compare);f5:open dirlist, dlcmd "^":send//~v76gI~
//v76c:070617 (XXE)paste from PRIMARY clipboard by middle button down//~v76cI~
//v76b:070617 support paste to =2 panel;del v68f because csr moved by lbdown,paste pos become invalid//~v76bI~
//v71x:061023 (XXE)it take time to download for DND and Application HUNG occurs//~v71xI~
//            aftwer completed using user msg to download,issue begindrag//~v71xI~
//v71s:061022 (WXE/XXE)err msg when drag canceled by mouse lb release//~v71sI~
//v70w:060903 (BUG:XXE)copy issue popuperr "settext:contain invalid data" when locale is UTF-8 and len contain null//~v70wI~
//v709:060730 (WXE:XXE)bug by v703;dbl click rejected by csr pos err.Real cause of v703 is cusror setting by rbdown(v68f)//~v709I~
//v702:060726 (WXEXXE:BUG)drag on last line of 1st split screen,set pancopy mode//~v702I~
//v700:060726 (WXEXXE:BUG)cut/del protection chk err(Point1 is already chked and may be scrolled out now)//~v700I~
//v69Z:060726 (XXE)sync C&P between PFkey and mouse operation.(update enable/disable menu by also Key operation)//~v69ZI~
//v69T:060716 (WXEXXE:BUG)by v69h swapped Shift/Ctrl shift status for scroll.//~v69TI~
//            scroll by timer with Shift to horizontal,width Ctrl shift for file bottom/top//~v69TI~
//v69c:060517 (WXE:BUG)time calc to ignore 1st lb down not to do cursor set. and expand limit time 10-->50ms//~v69cI~
//v68f:060330 (WXE)move cursor also by right mouse button down     //~v68fI~
//v68b:060329 (BUG:WXE)drag from dirlist remains cp box(for not file scr,cp box is drawn by wxescr)//~v68bI~
//v689:060328 (BUG)on dir list;s+lbdown/c+lbdown is for line selection not paste(ins/rep)//~v689I~
//v686:060323 dnd support by paste(edit:pastev,ins=paste-ins,rep=paste-rep)//~v686I~
//v685:060322 dnd support "file copy into the dir slected" and even in inter-split-screen.//~v685I~
//v682:060313 (WXE:BUG)menu enable re-evaluation requred for drag selection on dirlist;and also when reset by esc key//~v682I~
//v681:060312 (WXE:BUG by v66m)after DrawMenu api WM_MOUSEMOVE message is post,it cause drag start by S+LBDown//~v681I~
//            for gxe;do drag after drag start when moved ove 1 cell distance//~v681I~
//v66z:051211 (WXE:BUG)C&P miss last line eol at paste timing      //~v66zI~
//v66w:051211 (WXE:BUG)line dbl click is cursor pos err then leave point1 specification;capreset should be called//~v66wI~
//v66s:051027 (WXE/XXE)add Shift+Ctrl+left button to block specification because gnome intercept A+left button//~v66sI~
//v66r:051025 (XXE) for v66m for WXE                               //~v66rI~
//v66q:051023 (XXE) v66i of WXE;C & P;if no Clipboard data on Windows CB,get data from ::CB//~v66qI~
//v66p:051026 (XXE)std paste support(v66h of WXE)                  //~v66pI~
//v66p:051026 (XXE)std paste support                               //~v66pI~
//vXXE:050611 new for XXE                                          //~vXXEI~
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
#include <stdlib.h>                                                //~var8R~
#include <string.h>                                                //~var8R~
#include <ctype.h>                                                 //~var8R~
#include   <sys/timeb.h>                                           //~v63pI~
                                                                   //~vXXEI~
#ifndef OPTGTK3                                                    //~var8R~
#include <gnome.h>                                                 //~vXXEI~
#else                                                              //~var8R~
#include <gtk/gtk.h>                                               //~var8R~
#include <gdk/gdkx.h>                                              //~var8R~
#endif                                                             //~var8R~
#ifndef NOPRINT                                                    //~vam0R~
	#ifdef GTKPRINT                                                //~vam0I~
	#else    //!GTKPRINT                                           //~vam0I~
#include <libgnomeprint/gnome-print.h>                             //~vXXEI~
#include <libgnomeprint/gnome-print-job.h>                         //~vXXEI~
	#endif   //!GTKPRINT                                           //~vam0I~
#endif                                                             //~vam0I~
                                                                   //~vXXEI~
#include <ulib.h>                                                  //~vXXEI~
#include <uedit.h>                                                 //~v71sR~
#include <utrace.h>                                                //~v71sR~
#include <uerr.h>                                                  //~v71sI~
#include <udbcschk.h>                                              //~va0qI~
#include <uque.h>                                                  //~va53I~
#include <ufile.h>                                                 //~va53I~
#define UFTIME                                                     //+vbs1I~
#include <umiscf.h>                                                //+vbs1I~
                                                                   //~vXXEI~
#include    "gxe.h"                                                //~vXXEI~
#include    "xxeres.h"                                             //~vXXEI~
#include    "xxedef.h"                                             //~vXXEI~
#include    "xxemain.h"                                            //~vXXEI~
#include    "xxexei.h"                                             //~vXXEI~
#include    "xxecsub.h"                                            //~vXXEI~
#include    "gxemfrm.h"                                            //~vXXEI~
#include    "xxefile.h"                                            //~v686I~
#include    "xescr.h"                                              //~va53I~
#include    "xefile.h"                                             //~va53I~
#include    "xesub2.h"                                             //~va1cR~
                                                                   //~v003I~
//===============================================================================//~vXXEI~
#define SETFOCUSTIME 200   //50ms between OnSetFocus to LBDown,then do not move cursor//~v69cR~
//===============================================================================//~vXXEI~
	int  mousescrollchk(int Pcol,int Prow);                        //~vXXEM~
	void mousedragfile(int Pdragopt,void *Ppcw,void* Pplh);        //~vXXEM~
	int  mousedodrag(void *Ppcw,int Popt);                         //~vXXER~
	int  mousedragcopy(void *Ppcw,char *Plist);                    //~vXXER~
	int  mousedragcopychk(void);                                   //~vXXEM~
//  int  cpcopypan(char *Pcbdata,int Prow1,int Pcol1,int Prow2,int Pcol2);//~va0qR~
    int  cpcopypan(char *Pcbdata,int Prow1,int Pcol1,int Prow2,int Pcol2,int *Pplen);//~va0qI~
	int mousedragsetuplist(void *Ppcw,char **Pplist);              //~vXXEI~
	int cppastedropchk(int Popt);                                  //~v686I~
	void xxemain_pastecb(GtkClipboard *Ppclipboard,const gchar *Pptext,gpointer Ppdata);//~v76cR~
#define DNDDODRAG_COPY 0x01                                        //~vXXEM~
#define DNDDODRAG_BEGIN 0x02	//filesetup ended(prepared for drop file)//~v71xI~
	BOOL onfileCHLdblclick();                                      //~vbj3I~
	BOOL chkCHLselect(CPoint Ppoint);                              //~vbj4R~
	BOOL selectedCHL(UINT Pflag,CPoint Ppoint);                    //~vbj4R~
//****************************                                     //~vbj4I~
static int SrowCHL;                                                //~vbj4I~
//===============================================================================//~v003I~
//                                                                 //~v003I~
//===============================================================================//~v003I~
void xxemain_mouselbdown(UINT Pflag,CPoint Ppoint)                 //~vXXER~
{                                                                  //~v003I~
//  int rc;                                                        //~v003I~//~vaa7R~
    struct timeb ctm;                                              //~vXXER~
//************************************                             //~v003I~
dprintf("lbdn killfocus=%d\n",Mswkillfocus);                       //~v69cR~
    if (Mswkillfocus)   //1st time after killfocus                 //~v63pI~
    {                                                              //~v63pI~
//  	ftime(&ctm);	                                           //~vXXER~//+vbs1R~
    	uftime(&ctm);                                              //+vbs1I~
        ctm.time-=Msetfocustime;                                   //~v63pR~
        if (ctm.time==1 || ctm.time==0)                            //~v63pI~
        {                                                          //~v63pI~
//        	ctm.time=(ctm.time<<16)+ctm.millitm-Msetfocusmsec;     //~v69cR~
        	ctm.time=(ctm.time*1000)+ctm.millitm-Msetfocusmsec;    //~v69cI~
        dprintf("lbdown time cur=%lx-%d,prev=%lx-%d\n",ctm.time,ctm.millitm,Msetfocustime,Msetfocusmsec);//~v69cR~
//          if (ctm.time<10)	//lbdn is in 10ms after setfocus   //~v69cR~
            if (ctm.time<SETFOCUSTIME)	//lbdn is in 10ms after setfocus//~v69cI~
            	return;                                            //~v63pI~
        }                                                          //~v63pI~
        Mswkillfocus=0;                                            //~v63pR~
    }                                                              //~v63pI~
	Mlbdblclicksw=0;	//not after dbl click                      //~v5a1I~
//  wxe_capreset();                                                //~v5a1R~
    if (Mcpcopypansw)   //pane cap                                 //~2A06R~
        xxemain_mousecpdrawpan(Mcellcopy1.y,Mcellcopy2.y,-1);  //clear cap box//~vXXER~
    Mcpcopysw=1;            //start mouse blocking                 //~v003R~
    Mcppastesw=1;                                                  //~v003R~
    Mcpstart=Ppoint;                                               //~v003I~
    chkCHLselect(Ppoint);                                          //~vbj4I~
    Mcellcopy1.x=COL(Ppoint.x);                                    //~v003R~
    Mcellcopy1.y=ROW(Ppoint.y);                                    //~v003R~
dprintf("%s:lbdown (y,x)=(%d,%d)-->row=%d,col=%d\n",UTT,Ppoint.y,Ppoint.x,Mcellcopy1.y,Mcellcopy1.x);//~v685R~//~vb7AR~
    mousescrollchk(Mcellcopy1.x,Mcellcopy1.y);                     //~v5a1R~
    Mcellcopy2=Mcellcopy1;                                         //~v003R~
    /*rc=*/wxe_movecsr(Mcellcopy1.y,Mcellcopy1.x);                     //~v003R~//~vaa7R~
	if (Pflag & MK_SHIFT)      	//with shift key                   //~3202I~
    {                                                              //~v66sI~
	  if (!(Pflag & MK_CONTROL))      //with control key           //~v66sI~
//  	xxemain_cppaste(1);    //1:insert mode                     //~v689R~
    	xxemain_cppaste(PASTE_TEXT_ONLY|PASTE_INSMODE);    //1:insert mode//~v689I~
    }                                                              //~v66sI~
    else                                                           //~3202I~
	if (Pflag & MK_CONTROL)      //with control key                //~3202I~
    {                                                              //~v66sI~
	  if (!(Pflag & MK_SHIFT))      	//with shift key           //~v66sI~
//		xxemain_cppaste(0);         //0:pasteon mode               //~v689R~
    	xxemain_cppaste(PASTE_TEXT_ONLY);    //repmode             //~v689I~
    }                                                              //~v66sI~
    	                                                           //~3202I~
//  ((CMainFrame*)Mpmainframe)->enablemainmenu();	//main menu enable/disable//~v51dR~
    gxemfrm_enabletoolbar(0);//toolbar icon enable/disable         //~v66rI~
	xxemain_scrinvalidate(0);                                      //~vXXEI~
    return;                                                        //~v003I~
}//mouselbdown                                                     //~v003I~
//===============================================================================//~v003M~
//                                                                 //~v003M~
//===============================================================================//~v003M~
void xxemain_mousemove(UINT Pflag,CPoint Ppoint)                   //~vXXER~
{                                                                  //~v003M~
    int xx,yy,rc;                                                  //~2A05R~
    void *pcw;                                                     //~vXXER~
    int cpmode;                                                    //~v66pI~
//************************************                             //~v003M~
dprintf("%s:Mlbposid=%x,Mswkillfocus=%d,Pflag=%x,x=%d,y=%d\n",UTT,Mlbposid,Mswkillfocus,Pflag,Ppoint.x,Ppoint.y);//~vb7AR~
    if (Mswkillfocus)   //1st time after killfocus                 //~v63pI~
        return;			//until lbup                               //~v63pI~
	if (!(Pflag & MK_LBUTTON))	//l-button pressed?                //~v003M~
    {                                                              //~v5a1I~
    	if (Mlbposid && Mcpcopysw==2)     //lb up miss when at out of client area//~v5a1R~
			xxemain_mouselbup(Pflag,Ppoint);                       //~vXXER~
    	Mlbposid=0;		//for auto scroll                          //~v5a1M~
dprintf("%s:set Mlbposid=0\n",UTT);                                //~vb7AI~
	    return;                                                    //~v003M~
    }                                                              //~v5a1I~
    Mcellcopy2.x=COL(Ppoint.x);                                    //~v5a1M~
    Mcellcopy2.y=ROW(Ppoint.y);                                    //~v5a1M~
//dprintf("mouse move x=%d,y=%d,col=%d,row=%d\n",Ppoint.x,Ppoint.y,Mcellcopy2.x,Mcellcopy2.y);//~v702R~
 if (Mcpcopysw==2)  //drag strted                                  //~v685I~
  if (!SAMEPOS(Mcellcopy2,Mcellcopy1))	//moved over 1col or 1 row //~v681I~
    if (wxe_dragselectchk(DRAGOPT_DRAG,Pflag,Mcellcopy2.y,Mcellcopy2.x,&pcw,0))//~v63iR~
    {                                                              //~v63hR~
dprintf("%s:drag start dodrag Mcpcopysw=%d,Mcpcopypansw=%d\n",(char*)utimeedit("HHMMSS.MIL",0),Mcpcopysw,Mcpcopypansw);//~v70wR~
    	Mcpcopypansw=0;	//protect cap box draw at wxescr:lineput   //~v68bI~
	    Mcpcopysw=0;                                               //~v68bM~
        mousedodrag(pcw,0);                                        //~v63iR~
		xxemain_scrinvalidate(0);                                  //~v68bI~
        return;                                                    //~v63hR~
    }                                                              //~v63hR~
dprintf("%s:posid=%x,col=%d,row=%d\n",UTT,Mlbposid,Mcellcopy2.x,Mcellcopy2.y);//~v702R~//~vb7AR~
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
        cpmode=CP_DRAGOPEN;                                        //~v66pI~
//		if (Pflag & MK_ALT)      	//with Alt key                 //~v66sR~
  		if (Pflag & MK_ALT       	//with Alt key                 //~v66sI~
        ||  (Pflag & (MK_SHIFT|MK_CONTROL))==(MK_SHIFT|MK_CONTROL))//~v66sI~
        {                                                          //~v66pI~
        	Mcpblockmode=1;                                        //~v66pI~
        	cpmode|=CP_DRAGBLOCK;                                  //~v66pI~
        }                                                          //~v66pI~
        else                                                       //~v66pI~
        	Mcpblockmode=0;                                        //~v66pI~
//  	if (rc=wxe_capblock(0,Mcellcopy2.y,Mcellcopy2.x,&Mcpcopypansw),rc)	//block start failed//~v66pR~
//  	if (rc=wxe_capblock(cpmode,Mcellcopy2.y,Mcellcopy2.x,&Mcpcopypansw),rc)	//block start failed//~v702R~
    	if (rc=wxe_capblock(cpmode,Mcellcopy1.y,Mcellcopy1.x,&Mcpcopypansw),rc)	//block start failed//~v702I~
	    {                                                          //~v003I~
            Mcpcopysw=0;                                           //~2A05R~
			xxemain_scrinvalidate(0);                              //~vXXEI~
            return;                                                //~2A05R~
	    }                                                          //~v003I~
//dprintf("mouse capblock posid=%x,col=%d,row=%d\n",Mlbposid,Mcellcopy2.x,Mcellcopy2.y);//~v702R~
        Mcpoldpos=Mcellcopy2;                                      //~2A05R~
    }                                                              //~2A05I~
    if (Mcpcopypansw)	//file only                                //~2A05R~
    {                                                              //~2A05I~
    	if (!SAMEPOS(Mcellcopy2,Mcpoldpos))                        //~2A05R~
        {                                                          //~2A05I~
	    	xxemain_mousecpdrawpan(Mcellcopy1.y,Mcellcopy2.y,Mcpoldpos.y);//~vXXER~
            Mcpoldpos=Mcellcopy2;                                  //~2A05R~
//dprintf("mouse cadrawpan posid=%x,col=%d,row=%d\n",Mlbposid,Mcellcopy2.x,Mcellcopy2.y);//~v702R~
        }                                                          //~2A05I~
    }                                                              //~2A05I~
    else                                                           //~2A05I~
	    wxe_movecsr(Mcellcopy2.y,Mcellcopy2.x);	//csr move	       //~2A05R~
	Mcpcopysw=2;	//moved width lbutton down                     //~v003I~
	xxemain_scrinvalidate(0);                                      //~vXXEI~
}//mousemove                                                       //~v003R~
//===============================================================================//~2A05I~
//                                                                 //~2A05I~
//===============================================================================//~2A05I~
void xxemain_mousecpdrawpan(int Prow1,int Prow2,int Prow3)         //~vXXER~
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
}//xxemain_mousecpdrawpan                                          //~vXXER~
//===============================================================================//~v003I~
//                                                                 //~v003I~
//===============================================================================//~v003I~
void xxemain_mouselbup(UINT Pflag,CPoint Ppoint)                   //~vXXER~
{                                                                  //~v003I~
	void *plh,*pcw;                                                //~v63hR~
    int dragchkrc;                                                 //~v58iI~
    int cpmode;                                                    //~v66pI~
//************************************                             //~v003I~
dprintf("%s:flag=%x,Pswkillfocus=%d,Mlbposid=%x\n",UTT,Pflag,Mswkillfocus,Mlbposid);                                   //~v73tR~//~vb7AR~
UTRACEP("lbup Mcpcopysw=%d,draggingpcw=%p\n",Mcpcopysw,Mdragedpcw);//~vXXER~
    if (Mswkillfocus)   //1st time after killfocus                 //~v63pI~
    {                                                              //~v63pI~
        Mswkillfocus=0;                                            //~v63pI~
        return;                                                    //~v63pI~
    }                                                              //~v63pI~
	Mlbposid=0;					//for autoscroll                   //~v5a1I~
dprintf("%s:set Mlbposid=0\n",UTT);                                //~vb7AI~
dprintf("lbup Mdragacceptsw=%d,Mdragpcw=%p\n",Mdragacceptsw,Mdragedpcw);//~vXXER~
//    if (!Mdragacceptsw) //before "data get" returned             //~vXXER~
//        Mdragedpcw=0;                                            //~vXXER~
    if (Mcpcopysw!=2)            //start mouse blocking            //~v003R~
    {                                                              //~v58iI~
      if (!Mdragedpcw)                                             //~vXXER~
      {                                                            //~vXXEI~
    	if (dragchkrc=wxe_dragselectchk(DRAGOPT_SELECT,Pflag,ROW(Ppoint.y),COL(Ppoint.x),&pcw,&plh),dragchkrc)//~v63hR~
        	mousedragfile(dragchkrc,pcw,plh);                      //~v63hR~
dprintf("lbup dragchkrc=%d\n",dragchkrc);                          //~v689R~
	  	selectedCHL(Pflag,Ppoint);                                 //~vbj4I~
      }                                                            //~vXXEI~
    	return;                                                    //~vXXEM~
    }                                                              //~v58iI~
    if (Mlbdblclicksw)	//after dbl click                          //~v5a1I~
    {                                                              //~v5a1I~
	    Mlbdblclicksw=0;	//after dbl click                      //~v5a1I~
    	return;                                                    //~v5a1I~
    }                                                              //~v5a1I~
    Mcellcopy2.x=COL(Ppoint.x);                                    //~v003R~
    Mcellcopy2.y=ROW(Ppoint.y);                                    //~v003R~
dprintf("lbup x=%d,y=%d,col=%d,row=%d\n",Ppoint.x,Ppoint.y,Mcellcopy2.x,Mcellcopy2.y);//~v69TR~
//  if (wxe_capblock(1,Mcellcopy2.y,Mcellcopy2.x,&Mcpcopypansw))	//block end failed//~v66pR~
    cpmode=CP_DRAGCLOSE;                                           //~v66pI~
	if (Mcpblockmode)	//Alt down                                 //~v66pI~
        cpmode|=CP_DRAGBLOCK;                                      //~v66pI~
    Mcpblockmode=0;                                                //~v66pI~
dprintf("capblock\n");                                             //~v689I~
    if (wxe_capblock(cpmode,Mcellcopy2.y,Mcellcopy2.x,&Mcpcopypansw))	//block end failed//~v66pI~
    {                                                              //~v003I~
		wxe_capreset();                                            //~v5a1I~
        Mcpcopysw=0;                                               //~v003I~
    }                                                              //~v51dI~
    else                                                           //~v51dI~
    	CAPGETBOX(Mcellcopy1,Mcellcopy2);                          //~v51dR~
//  ((CMainFrame*)Mpmainframe)->enablemainmenu();	//main menu enable/disable//~v51dR~
    gxemfrm_enabletoolbar(0);//toolbar icon enable/disable         //~v66rI~
	xxemain_scrinvalidate(0);                                      //~vXXEI~
    return;                                                        //~v51dI~
}//mouselbup                                                       //~2A06R~
//===============================================================================//~v003M~
//                                                                 //~v003M~
//===============================================================================//~v003M~
int xxemain_mouserbdown(UINT Pflag,CPoint Ppoint)                  //~vXXER~
{                                                                  //~v003M~
    int ii;                                                        //~vXXEI~
    UINT menuid;                                                   //~v003M~
    BOOL enable;                                                   //~v003M~
//  int row,col;                                                   //~v76bR~
//************************************                             //~v003M~
    Mswkillfocus=0;                                                //~v63pI~
	if (Mfloatmenusw)                                              //~v003M~
	    return FALSE;                                              //~vXXER~
	Mfloatmenusw=1;                                                //~v003M~
//move cursor                                                      //~v68fI~
//  if (!Mcpcopysw && !Mcpcopypansw)                               //~v76bR~
//  {                                                              //~v76bR~
//    col=COL(Ppoint.x);                                           //~v76bR~
//    row=ROW(Ppoint.y);                                           //~v76bR~
//    wxe_movecsr(row,col);                                        //~v76bR~
//    xxemain_scrinvalidate(0);                                    //~v76bR~
//  }                                                              //~v76bR~
	if (wxe_isCHLLine(0))                                          //~vbh2I~
    	Gxxestat|=GXXES_POPUPMENU_CHL;                             //~vbh2I~
    else                                                           //~vbh2I~
    	Gxxestat&=~GXXES_POPUPMENU_CHL;                            //~vbh2I~
    for (ii=0;;ii++)                                               //~vXXEI~
    {                                                              //~vXXEI~
    	menuid=gxemfrm_popupmenu_getmenuitemid(ii);                //~vXXEI~
        UTRACEP("%s:ii=%d,menuid=%d\n",UTT,ii,menuid);             //~vbh2I~
        if (!menuid)                                               //~vXXEI~
        	break;                                                 //~vXXEI~
        switch(menuid)                                             //~v003M~
        {                                                          //~v003M~
        case ID_EDIT_SELECTALL:                                    //~vbd2I~
        	enable=xxemain_cpupdateselectall();                    //~vbd2I~
        	break;                                                 //~vbd2I~
        case ID_EDIT_CUT:                                          //~v003M~
        case ID_EDIT_CLEAR:                                        //~2A06I~
        	enable=xxemain_cpupdatecut();                          //~vXXER~
        	break;                                                 //~v003M~
        case ID_EDIT_COPY:                                         //~v003M~
        	enable=xxemain_cpupdatecopy();                         //~vXXER~
        	break;                                                 //~v003M~
        case ID_EDIT_PASTE:                                        //~v003M~
        case ID_EDIT_PASTE_REP:                                    //~v003I~
        	enable=xxemain_cpupdatepaste();                        //~vXXER~
        	break;                                                 //~v003M~
        case ID_EDIT_PASTE_V:                                      //~v66pI~
        	enable=xxemain_cpupdatepastev();                       //~v66pI~
        	break;                                                 //~v66pI~
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
        UTRACEP("%s:menuid=%d,enable=%d\n",UTT,menuid,enable);     //~vbh2I~
		upopupmenu_menuitem_enable(menuid,enable);                 //~vXXER~
    }                                                              //~v003M~
	upopupmenu_popup(Ppoint);                                      //~vXXER~
    Gxxestat&=~GXXES_POPUPMENU_CHL;                                //~vbh2I~
    return TRUE;                                                   //~vXXEI~
}//mouserbdown                                                     //~v003M~
//===============================================================================//~v003I~
//cut & paste:copy/cut                                             //~v003R~
//p1:cutsw 0:copy,1;cut,2:clear                                    //~2A06I~
//===============================================================================//~v003I~
int  xxemain_cpcopy(int Pcutsw)                                    //~vXXER~
{                                                                  //~v003I~
#ifndef XXE                                                        //~vXXEI~
	HGLOBAL hGlobal;                                               //~v003I~
#endif                                                             //~vXXEI~
	int  totlen,row,col;                                           //~v5a1R~
//  CPoint pt1,pt2;                                                //~v76jR~
    CPoint pt1={0,0},pt2={0,0};                                    //~v76jI~
    int rc;                                                        //~v63iI~
    char *pcg;                                                     //~v003R~
#ifdef UTF8UCS2                                                    //~va20I~
    int swutf8data=0,opt;                                          //~va20R~
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
        swutf8data=1;                                              //~va20R~
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
        swutf8data=1;                                              //~va20R~
      }                                                            //~va20R~
      else                                                         //~va20R~
#endif                                                             //~va20R~
      {                                                            //~va20R~
		CAPGETBOX(pt1,pt2);                                        //~2A05I~
		Mcellcopy1=pt1;                                            //~2A05I~
		Mcellcopy2=pt2;                                            //~2A05I~
        row=pt2.y-pt1.y;                                           //~2A05R~
        col=pt2.x-pt1.x+1;                                         //~va0qR~
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
            swutf8data=1;                                          //~va20R~
        }                                                          //~va20I~
#endif                                                             //~va20I~
    }                                                              //~va20I~
  }                                                                //~v5a1I~
//  if (Pcutsw) //cut or clear //enable paste after also copy is done //~v5a1I~//~va7SR~
    	Mcpcopysw=0;           //no more block                     //~v5a1I~
//  pcg=umemalloc(totlen);                                         //~v66zR~
    pcg=umemalloc(totlen+1);                                       //~v66zI~
//  *(pcg+totlen)=0;                                               //~v66zI~//~vbh2R~
    memset(pcg,0,(size_t)(totlen+1));                              //~vbh2R~
dprintf("capcopy len=%d\n",totlen);                                //~vXXER~
	rc=0;                                                          //~v70wI~
		if (Mcpcopypansw)	//copy from panel data                 //~2A05I~
        {                                                          //~va20R~
#ifdef UTF8UCS2                                                    //~va20R~
            *pcg=(swutf8data!=0);    //parm to cpcopypan           //~va20R~
#endif                                                             //~va20R~
//  		cpcopypan(pcg,pt1.y,pt1.x,pt2.y,pt2.x);                //~va0qR~
    		cpcopypan(pcg,pt1.y,pt1.x,pt2.y,pt2.x,&totlen);        //~va0qI~
#ifdef UTF8UCS2                                                    //~va20R~
            if (totlen<0)                                          //~va20R~
                totlen=-totlen; //utf8 data                        //~va20R~
#endif                                                             //~va20R~
        }                                                          //~va20R~
        else                                                       //~2A05I~
//  		wxe_capcopytowincb(pcg,totlen);                        //~v70wR~
    		rc=wxe_capcopytowincb(pcg,totlen,&totlen);             //~v70wR~
      if (!rc)                                                     //~v70wR~
      {                                                            //~vb94I~
#ifdef UTF8UCS2                                                    //~va20I~
		opt=0;                                                     //~va20I~
        if (swutf8data)                                            //~va20I~
        	opt|=UCSTO_SRCUTF8;	//utf8 encoded data                //~va20I~
    	uclipboard_settext(opt,pcg,totlen);                        //~va20I~
#else                                                              //~va20I~
    	uclipboard_settext(pcg,totlen);                            //~vXXER~
#endif                                                             //~va20I~
      }                                                            //~vb94I~
        umemfree(pcg);                                             //~vXXEI~
//  xxemain_scrinvalidate(0);                                      //~v66pR~
    return 0;                                                      //~v003I~
}//xxemain_cpcopy                                                  //~vXXER~
//===============================================================================//~2A05I~
//cut & paste:paste                                                //~2A05I~
//parm:0:BlockRep, 1:BlockIns, 2:StdPaste                          //~v66pI~
//if Pcbdata=0,calc total length                                   //~va20R~
//===============================================================================//~2A05I~
//int  cpcopypan(char *Pcbdata,int Prow1,int Pcol1,int Prow2,int Pcol2)//~va0qR~
int  cpcopypan(char *Pcbdata,int Prow1,int Pcol1,int Prow2,int Pcol2,int *Pplen)//~va0qI~
{                                                                  //~2A05I~
	char *pc,*pdata,*pdbcs;                                        //~2A05R~
    int row,len;                                                   //~2A05R~
    char dbcstwk[MAXCOL];                                          //~va1cR~
#ifdef UTF8SUPPH                                                   //~va1cR~
    int splitctr;                                                  //~va1cR~
#endif                                                             //~va1cR~
#ifdef UTF8UCS2                                                    //~va20R~
    int lenucs,swgetlen,opt,swucs=0,swutf8data=0;                  //~va20R~
#endif                                                             //~va20R~
//************************************                             //~2A05I~
#ifdef UTF8UCS2                                                    //~va20R~
	swgetlen=(Pcbdata==NULL);    //no output area                  //~va20R~
    if (Pcbdata)                                                   //~va20R~
    	swutf8data=*Pcbdata!=0;                                    //~va20R~
	opt=swgetlen*WXEDTCPO_GETLENGTH;    //no output area           //~va20R~
#endif                                                             //~va20R~
  	len=Pcol2-Pcol1+1;                                             //~va0qR~
    pc=Pcbdata;                                                    //~2A05I~
    for (row=Prow1;row<=Prow2;row++)                               //~2A05I~
    {                                                              //~2A05I~
		pdata=(char*)TEXTDATA(row,Pcol1);                          //~2A05R~
		pdbcs=(char*)TEXTDBCS(row,Pcol1);                          //~2A05R~
        len=Pcol2-Pcol1+1;                                         //~va1bI~
UTRACED("cpcopypan text",pdata,len);                               //~va1cR~
UTRACED("cpcopypan dbcs",pdbcs,len);                               //~va1cR~
     if (Prow1==Prow2)	//1line,not box                            //~va1cR~
     {                                                             //~va1cR~
#ifdef UTF8SUPPH                                                   //~va1cR~
        if (UDBCSCHK_DBCSNOTEND(*(pdbcs+len-1)))                   //~va1cR~
            len-=XESUB_DBCSSPLITCTR_L(pdbcs,len);                  //~va1cR~
        if (UDBCSCHK_DBCSNOT1ST(*pdbcs))                           //~va1cR~
        {                                                          //~va1cR~
            splitctr=XESUB_DBCSSPLITCTR_R(pdbcs,len);              //~va1cR~
            pdata+=splitctr;                                       //~va1cR~
            pdbcs+=splitctr;                                       //~va1cR~
            len-=splitctr;                                         //~va1cR~
        }                                                          //~va1cR~
#else                                                              //~va1cR~
        if (*(pdbcs+len-1)==UDBCSCHK_DBCS1ST)                      //~va1bI~
            len--;                                                 //~va1bI~
        if (*pdbcs==UDBCSCHK_DBCS2ND)                              //~va1bI~
        {                                                          //~va1bI~
            pdata++;                                               //~va1bI~
            pdbcs++;                                               //~va1bI~
            len--;                                                 //~va1bI~
        }                                                          //~va1bI~
#endif                                                             //~va1cR~
     }                                                             //~va1cR~
//      wxe_dbcstextcopy(pc,pdata,pdbcs,len);                       //~va1bR~//~va1cR~
		memcpy(dbcstwk,pdbcs,len);                                 //~va1cR~
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
        wxe_dbcstextcopy(pc,pdata,dbcstwk,len);                    //~va1cR~
UTRACED("cpcopypan out text",pc,len);                              //~va1cR~
UTRACED("cpcopypan out dbcs",dbcstwk,len);                         //~va1cR~
        pc+=len;                                                   //~2A05I~
        *pc++='\r';                                                //~2A05I~
        *pc++='\n';      //crlf                                    //~2A05I~
      }                                                            //~va20R~
    }                                                              //~2A05I~
#ifdef UTF8UCS2                                                    //~va20R~
   if (!swgetlen)                                                  //~va20R~
#endif                                                             //~va20R~
    *(pc-2)=0;		//drop last line eol                           //~2A05I~
#ifdef UTF8UCS2                                                    //~va20R~
  if (Pplen)                                                       //~va20R~
#endif                                                             //~va20R~
  {                                                                //~va20R~
    *Pplen=(int)((ULONG)pc-2-(ULONG)Pcbdata);                      //~va0qI~
  	if (swucs||swutf8data)                                         //~va20R~
	    *Pplen=-*Pplen;                                            //~va20R~
UTRACEP("cpcopypan totlen=%d\n",*Pplen);                           //~va20R~
UTRACEDIFNZ("cpcopypan out\n",Pcbdata,*Pplen);                     //~va20R~
  }                                                                //~va20R~
    return 0;                                                      //~2A05I~
}//cpcopypan                                                       //~2A05I~
//===============================================================================//~v003I~
//cut & paste:paste                                                //~v003I~
//===============================================================================//~v003I~
int  xxemain_cppaste(int Pinssw)                                   //~vXXER~
{                                                                  //~v003I~
#if defined(OPTGTK3) && !defined(YYY)                              //~vv7vI~
    int filesel;                                                   //~vv7vR~
#else                                                              //~vv7vI~
	GtkSelectionData *filesel;                                     //~v686I~
#endif                                                             //~vv7vM~
	int  row,col,totlen;                                           //~v003R~
    char   *pcg;                                                   //~v003R~
    int rc;                                                        //~v66qI~
//  CPoint pointend;                                               //~vXXER~
    int opt;                                                       //~v686I~
    void *pcwtarget;                                               //~v686I~
    int textpastesw=0;                                             //~v689I~
//************************************                             //~v003I~
dprintf("cappaste inssw=%d\n",Pinssw);                             //~vXXER~
    if (Pinssw & PASTE_TEXT_ONLY)                                  //~v689I~
    {                                                              //~v689I~
    	Pinssw &= ~PASTE_TEXT_ONLY;                                //~v689I~
	    textpastesw=1;                                             //~v689I~
    }                                                              //~v689I~
//  if (!Mcppastesw)                                               //~v686R~
//  	return 4;                                                  //~v686R~
//  row=Mcellcopy1.y;                                              //~va7CR~
//  col=Mcellcopy1.x;                                              //~va7CR~
    col=Mwxeintf.WXEIcsrposx;	//caret                            //~va7CI~
    row=Mwxeintf.WXEIcsrposy;	//caret pos                        //~va7CI~
#if defined(OPTGTK3) && !defined(YYY)                              //~vv7vI~
    filesel=uclipboard_getfileselection_Received(0,0/*puris*/,0/*userdata*/);	//0:no output len required//~vv7vR~
#else                                                              //~vv7vI~
    filesel=uclipboard_getfileselection();	//0:no output len required//~v686R~
dprintf("getfile fileselection=%p \n",filesel);                    //~v686I~
#endif                                                             //~vv7vM~
    if (filesel)   //drop file by paste                            //~v686I~
    {                                                              //~v686I~
        if (textpastesw)	//paste text request                   //~v689I~
        	return 0;       //no process drop file                 //~v689I~
		Mdragpcw=0;                                                //~v686I~
        wxe_getpcw(&pcwtarget);//current active is target          //~v686I~
        opt=DROPFILE_CP;                                           //~v686I~
        if (Pinssw==0)	//rep mode                                 //~v686I~
            opt|=DROPFILE_REP;                                     //~v686I~
#if defined(OPTGTK3) && !defined(YYY)                              //~vv7vI~
        return xxefile_ondropfiles_Paste(opt,pcwtarget,0,0);//row/col not requred//~vv7vI~
#else                                                              //~vv7vI~
        return xxefile_ondropfilesub(opt,filesel,pcwtarget,0,0);//row/col not requred//~v686I~
#endif                                                             //~vv7vI~
    }                                                              //~v686I~
    if (wxe_cappasteposchk(row,col))                               //~v53AI~
        return 4;                                                  //~v53AI~
//	if (uclipboard_gettext(&pcg,&totlen))                          //~v66qR~
//	rc=uclipboard_gettext(&pcg,&totlen);                           //~v76cR~
  	rc=uclipboard_gettext(0,&pcg,&totlen,0);	//0:GDK_SELECTION_CLIPBOARD//~v76cR~
  	if (rc && rc !=-2)	//-2:uclipboard get failed                 //~v66qI~
    {                                                              //~v686I~
dprintf("gettext rc=%d\n",rc);                                     //~v685R~
        return 4;                                                  //~vXXEI~
    }                                                              //~v686I~
UTRACEP("cappaste len=%d,str=%s\n",totlen,pcg);                    //~va53R~
	wxe_cappaste(Pinssw,row,col,pcg,totlen);                       //~v003R~
  if (pcg)                                                         //~v66qR~
	uclipboard_memfree(pcg);                                       //~vXXEI~
                                                                   //~v003I~
    Mcppastesw=2;                                                  //~v003R~
    Mcpcopysw=0;                                                   //~v003I~
                                                                   //~v003I~
	xxemain_scrinvalidate(0);                                      //~vXXEI~
    return 0;                                                      //~v003I~
}//xxemain_cppaste                                                 //~vXXER~
//===============================================================================//~v76cI~
//middle button down(paste PRINMARY clipboard)                     //~v76cI~
//===============================================================================//~v76cI~
int xxemain_mousembdown(UINT Pflag,CPoint Ppoint)                  //~v76cI~
{                                                                  //~v76cI~
    char   *pcg;                                                   //~v76cI~
	int    totlen;                                                 //~v76cI~
//************************************                             //~v76cI~
  	uclipboard_gettext(UCBGT_PRIMARY|UCBGT_SETCB,&pcg,&totlen,xxemain_pastecb);//~v76cR~
    return TRUE;                                                   //~v76cI~
}//xxemain_mousembdown                                             //~v76cI~
//===============================================================================//~v76cI~
//middle button down(paste PRINMARY clipboard)                     //~v76cI~
//===============================================================================//~v76cI~
void xxemain_pastecb(GtkClipboard *Ppclipboard,const gchar *Pptext,gpointer Ppdata)//~v76cR~
{                                                                  //~v76cI~
	int  row,col,totlen;                                           //~v76cI~
    char   *pcg;                                                   //~v76cI~
    int rc;                                                        //~v76cI~
//************************************                             //~v76cI~
    Mswkillfocus=0;		//lbdown ignore sw when 1st time after get focus//~v76cI~
    col=Mwxeintf.WXEIcsrposx;	//caret                            //~v76cR~
    row=Mwxeintf.WXEIcsrposy;	//caret pos                        //~v76cI~
dprintf("mbdown row=%d,col=%d\n",row,col);                         //~v76cR~
    if (wxe_cappasteposchk(row,col))                               //~v76cI~
    {                                                              //~v76cI~
dprintf("csrpos err\n");                                           //~v76cI~
        return;                                                    //~v76cR~
    }                                                              //~v76cI~
    pcg=(char*)Pptext;		//convert from utf8 string             //~v76cR~
  	rc=uclipboard_gettext(UCBGT_CBDATA,&pcg,&totlen,0);            //~v76cR~
  	if (rc)	//no paste from ::cb for the case rc==-2               //~v76cR~
    {                                                              //~v76cI~
dprintf("gettext primary rc=%d\n",rc);                             //~v76cR~
        return;                                                    //~v76cR~
    }                                                              //~v76cI~
UTRACEP("paste_cb len=%d,str=%s\n",totlen,pcg);                    //~va53R~
//UTRACED("cappaste primary",pcg,totlen);                          //~v76cR~
	if (!(  (totlen==1 && *pcg=='\n')    //data                    //~v76cR~
	      ||(totlen==2 && *pcg==' ' && *(pcg+1)=='\n')//ignore no meaningfull data//~v76cI~
         )                                                         //~v76cI~
       )                                                           //~v76cI~
    {                                                              //~v76cI~
dprintf("cappaste actual data exist\n");                           //~v76cI~
		wxe_cappaste(2,row,col,pcg,totlen);     //2:always std paste//~v76cR~
    }                                                              //~v76cI~
#ifdef UTF8UCS2 //gettext do not alloacte locale str converted from utf8//~va20I~
#else                                                              //~va20I~
   	if (pcg)                                                       //~v76cI~
//dont free parm str,gtk_clipboard free it                         //~va20R~
		uclipboard_memfree(pcg);                                   //~v76cI~
#endif                                                             //~va20I~
    Mcppastesw=2;                                                  //~v76cI~
    Mcpcopysw=0;                                                   //~v76cI~
	xxemain_scrinvalidate(0);                                      //~v76cI~
    return;                                                        //~v76cR~
}//xxemain_pastecb                                                 //~va20R~
//===============================================================================//~v003I~
//menu disable/enable                                              //~v003I~
//===============================================================================//~v003I~
BOOL xxemain_cpupdatecopy(void)                                    //~vXXER~
{                                                                  //~v003I~
	void *pcw;                                                     //~v63iI~
//*********************                                            //~v63iI~
//  return Mcpcopysw==2;                                           //~v63iR~
//  return (Mcpcopysw==2||wxe_dragselectchk(DRAGOPT_DRAG,0,-1,-1,&pcw,0));//cut&paste or drag select//~v69ZR~
    return (  Mcpcopysw==2                                         //~v69ZI~
            ||wxe_capchkxestat()                                   //~v69ZI~
            ||wxe_dragselectchk(DRAGOPT_DRAG,0,-1,-1,&pcw,0)//cut&paste or drag select//~v69ZI~
            );                                                     //~v69ZI~
}//xxemain_cpupdatecopy                                            //~vXXER~
//===============================================================================//~v003I~
//menu disable/enable                                              //~v003I~
//===============================================================================//~v003I~
BOOL xxemain_cpupdatecut(void)                                     //~vXXER~
{                                                                  //~v003I~
	if (Mcpcopysw!=2 || Mcpcopypansw)                              //~2A12I~
      if (!wxe_capchkxestat())                                     //~v69ZI~
    	return FALSE;                                              //~2A12I~
//block end and not copy pan                                       //~2A12I~
//  int rc=wxe_capchkprot(Mcellcopy1.y,Mcellcopy1.x);	//no out pcw//~v700R~
//  int rc=wxe_capchkprot(-1,-1);	//no out pcw                   //~v76jR~
    int rc=wxe_capchkprot(0,-1,-1);	//no out pcw                   //~v76jI~
    if (rc>0)	//protected                                        //~2A12I~
    	return FALSE;                                              //~2A12I~
    return TRUE;		//paste avail                              //~2A12I~
}//xxemain_cpupdatecut                                             //~v686R~
//===============================================================================//~v003I~
//menu disable/enable                                              //~v003I~
//===============================================================================//~v003I~
BOOL xxemain_cpupdatepaste(void)                                   //~vXXER~
{                                                                  //~v003I~
	int rc2;                                                       //~v686I~
	int  row,col;                                                  //~va7DI~
//****************************                                     //~v686I~
//  if (Mcpcopysw==2 || Mcppastesw!=1)                             //~v514R~
//  if (Mcpcopysw==2 || !Mcppastesw)                               //~v686R~
    if (Mcpcopysw==2)                                              //~v686I~
    	return FALSE;                                              //~2A12I~
//!block close and not after lbdown                                //~2A12I~
	if (rc2=cppastedropchk(0),rc2>=0)	//0:paste ins/rep          //~v686I~
    	return rc2;                                                //~v686I~
//  int rc=wxe_capchkprot(Mcellcopy1.y,Mcellcopy1.x);	//no out pcw//~v76jR~
//  int rc=wxe_capchkprot(0,Mcellcopy1.y,Mcellcopy1.x);	//no out pcw//~va7DR~
    col=Mwxeintf.WXEIcsrposx;	//caret                            //~va7DI~
    row=Mwxeintf.WXEIcsrposy;	//caret pos                        //~va7DI~
    int rc=wxe_capchkprot(0,row,col);	//no out pcw               //~va7DI~
    if (rc>0)	//protected                                        //~2A12I~
    	return FALSE;                                              //~2A12I~
    return TRUE;		//paste avail                              //~2A12I~
}//xxemain_cpupdatepaste                                           //~v76jR~
//===============================================================================//~v66pI~
//menu disable/enable                                              //~v66pI~
//===============================================================================//~v66pI~
BOOL xxemain_cpupdatepastev(void)                                  //~v66pI~
{                                                                  //~v66pI~
	int rc2;                                                       //~v686I~
    int opt;                                                       //~v76jI~
	int  row,col,rc;                                               //~va7DI~
//****************************                                     //~v686I~
//  if (!Mcppastesw)	//allow after draged started status        //~v686I~
//  	return FALSE;                                              //~v686I~
	if (rc2=cppastedropchk(1),rc2>=0)  //1:pastev                  //~v686I~
    	return rc2;                                                //~v686I~
//  int rc=wxe_capchkprot(Mcellcopy1.y,Mcellcopy1.x);	//no out pcw//~v76jR~
    opt=WXECCP_STDPASTE;                                           //~v76jI~
	if (Mcpcopysw==2)	//box or rgn drawn                         //~v76jI~
    	opt=WXECCP_DRAGED;                                         //~v76jI~
//  int rc=wxe_capchkprot(opt,Mcellcopy1.y,Mcellcopy1.x);	//no out pcw//~va7DR~
    col=Mwxeintf.WXEIcsrposx;	//caret                            //~va7DI~
    row=Mwxeintf.WXEIcsrposy;	//caret pos                        //~va7DI~
    rc=wxe_capchkprot(opt,row,col);	//no out pcw                   //~va7DI~
    if (rc>0)	//protected                                        //~v66pI~
    	return FALSE;                                              //~v66pI~
    return TRUE;		//paste avail                              //~v66pI~
}//xxemain_cpupdatepastev                                          //~v76jR~
//===============================================================================//~v686I~
//drop by paste target chk                                         //~v686I~
//rc:0:false,1:true,-1:not drop file                               //~v686I~
//===============================================================================//~v686I~
int cppastedropchk(int Popt)                                       //~v686I~
{                                                                  //~v686I~
    int rc=-1;                                                     //~v686I~
    void *pcwt;                                                    //~v686I~
    int pctype;                                                    //~v76jI~
//*******************                                              //~v686I~
	if (Mdragedpcw  //when internal drop,uclipboard_getfileselection cause dragend call,and abend in GTK//~v689I~
#if defined(OPTGTK3) && !defined(YYY)                              //~vv7vI~
	||  uclipboard_getfileselection_Received(0/*opt*/,0/*puir*/,0/*userdata*/))//~vv7vI~
#else                                                              //~vv7vI~
	||  uclipboard_getfileselection())                             //~v689R~
#endif                                                             //~vv7vI~
    {                                                              //~v686I~
        rc=0;   //FALSE                                            //~v686I~
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
    return rc;		//chk CF_TEXT                                  //~v686I~
}//cppastedropchk                                                  //~v686I~
//===============================================================================//~2A13I~
//mouse wheel                                                      //~2A13I~
//flag:virtual key conbination                                     //~2A13I~
//delta:<0;forward scrool,>0:backward scroll                       //~2A13I~
//===============================================================================//~2A13I~
BOOL xxemain_onmousewheel(UINT nFlags, int Pdirection, CPoint pt)  //~vXXER~
{                                                                  //~2A13I~
//UTRACEP("onmousewheel flag=%x,delta=%x,(%x,%x)\n",nFlags,zDelta,pt.x,pt.y);//~v53bR~
    wxe_scroll(Mscrollctr,nFlags,Pdirection);                      //~vXXER~
	xxemain_scrinvalidate(0);                                      //~vXXEI~
    return TRUE;		//paste avail                              //~2A13I~
}//xxemain_onmousewheel                                            //~vXXER~
//===============================================================================//~3102I~
//mouse wheel                                                      //~3102I~
//flag:virtual key conbination                                     //~3102I~
//ret:1 processed,0:do default action at return                    //~3102I~
//===============================================================================//~3102I~
BOOL xxemain_mouselbdblclk(UINT nFlags,CPoint pt)                  //~vXXER~
{                                                                  //~3102I~
	int rc,row,col,capinfo,cpid;                                   //~v5a1R~
//************************                                         //~3102I~
dprintf("mouse dbl click flag=%x,(%d,%d)\n",nFlags,pt.x,pt.y);     //~vXXER~
    col=COL(pt.x);                                                 //~3102I~
    row=ROW(pt.y);                                                 //~3102I~
    Mlbdblclicksw=1;                                               //~v5a1I~
  if ((wxe_isCHLLine(0)))                                          //~vbj3I~
  {                                                                //~vbj3I~
    rc=onfileCHLdblclick();                                        //~vbj3I~
    capinfo=0;                                                     //~vbj3I~
  }                                                                //~vbj3I~
  else                                                             //~vbj3I~
  {                                                                //~vbj3I~
    rc=wxe_lineselect(nFlags,row,col,&capinfo);                    //~3202R~
dprintf("mouse dbl click rcapinfo=%d,row=%d,col=%d)\n",capinfo,row,col);//~vXXER~
  }                                                                //~vbj3I~
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
#ifndef XXE                                                        //~vXXEI~
        if (nFlags & (MK_SHIFT|MK_CONTROL))  //with shift key      //~v53AI~
        	return 4;	//push+shift means paste;push & dblclick msg when dblclick//~v53AI~
#endif                                                             //~vXXEI~
        Mcellcopy1.x=col;                                          //~v5a1I~
        Mcellcopy1.y=row;                                          //~v5a1I~
        Mcellcopy2.x=col;                                          //~v5a1I~
        Mcellcopy2.y=row;                                          //~v5a1I~
    	Mcpcopysw=2;            //enable copy/cut/clear menu       //~v5a1I~
		xxemain_cpcopy(cpid);                                      //~vXXER~
    }                                                              //~v5a1I~
	xxemain_scrinvalidate(0);                                      //~vXXEI~
    return rc;                                                     //~3102I~
}//mouselbdblclk                                                   //~3102I~
//**************************************************************** //~vb7zI~
//*return elapsed time                                             //~vb7zI~
//*rc:bool:tru:continue scroll                                     //~vb7zI~
//**************************************************************** //~vb7zI~
BOOL xxemain_ontimer_mousepositionchk()                            //~vb7zI~
{                                                                  //~vb7zI~
    int xx,yy,col,row,posid,rc;                                    //~vb7zR~
//****************************                                     //~vb7zI~
	csub_get_mouse_status(0,&xx,&yy,NULL/*Ppmodmask*/);            //~vb7zI~
    col=COL(xx);                                                   //~vb7zI~
    row=ROW(yy);                                                   //~vb7zI~
    posid=wxe_mouseedgechk(col,row);                               //~vb7zR~
    rc=posid!=0;                                                   //~vb7zI~
	dprintf("%s:rc=%d,col=%d,row=%d,xx=%d,yy=%d,posid=%x\n",UTT,rc,col,row,xx,yy,posid);//~vb7zR~
    return rc;                                                     //~vb7zI~
}//xxemain_ontimer_mousepositionchk                                //~vb7zI~
//**************************************************************** //~v5a1I~
//*return elapsed time                                             //~v5a1I~
//**************************************************************** //~v5a1I~
BOOL xxemain_ontimer(void *Pdata)                                  //~vXXER~
{                                                                  //~v5a1I~
    int   dest,flag;                                               //~v5a1I~
    int rc/*,opt*/;                                                //~v63kR~
    UINT Pid;                                                      //~vXXEI~
//****************************                                     //~v5a1I~
//  Pid=(UINT)Pdata;                                               //~vXXEI~//~va70R~
    Pid=(UINT)(ULONG)Pdata;                                        //~va70I~
//  Mscrolltimereventctr++; //timer                                //~v53bR~
dprintf("%s:ontimer posid=%x,Pid=%x,eventctr=%d\n",UTT,Mlbposid,Pid,Mscrolltimereventctr);//~vXXER~//~vb7AR~
    if (Pid & TID_ATCMD)                                           //~v55WI~
        return xxemain_ontimeratcmd(Pid);                          //~vXXER~
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
	  	if (!xxemain_ontimer_mousepositionchk())                   //~vb7zR~
      	{                                                          //~vb7zR~
	    	Mlbposid=0;                                            //~vb7zI~
			dprintf("%s: pos moved set Mlbposid=0\n",UTT);         //~vb7zI~
      	}                                                          //~vb7zR~
    	if (Mlbposid==(int)Pid)	//mouse not moved in the interval  //~v5a1R~
    	{                                                          //~v5a1I~
			Mscrolltimereventctr++; //timer                        //~v53bI~
          	if (Mscrolltimereventctr<=DEF_SCROLLINITWAIT)          //~v51uR~
          		return TRUE;                                       //~v51uI~
          	                                                       //~v51uI~
        	if (Pid & TID_SCLEFT)                                  //~v5a1R~
            {                                                      //~v5a1I~
//            	flag=MK_CONTROL;	//simulate ctrl+               //~v69TR~
            	flag=MK_SHIFT;	//simulate shift+ for horizontal scroll//~v69TI~
            	dest=1;     //backword                             //~v5a1R~
	    		wxe_scroll(Mscrollctr,flag,dest);                  //~v5a1I~
            }                                                      //~v5a1I~
            else                                                   //~v5a1I~
        	if (Pid & TID_SCRIGHT)                                 //~v5a1I~
            {                                                      //~v5a1I~
//            	flag=MK_CONTROL;	//simulate ctrl+               //~v69TR~
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
dprintf("%s:scrolled posid=%x,Pid=%x\n",UTT,Mlbposid,Pid); //~vXXER~//~vb7zR~
			xxemain_scrinvalidate(0);                              //~vXXEI~
		    return TRUE;		//paste avail                      //~v5a1I~
        }                                                          //~v5a1I~
    }                                                              //~v5a1I~
dprintf("%s:kill timer posid=%x,Pid=%x\n",UTT,Mlbposid,Pid);       //~vXXER~//~vb7zR~
    Mscrolltimereventctr=0; //timer ctr                            //~v51uI~
    return FALSE;// Mpview->KillTimer(Pid);                        //~vXXER~
}//xxemain_ontimer                                                 //~vb7zR~
//**************************************************************** //~v5a1I~
//*return elapsed time                                             //~v5a1I~
//**************************************************************** //~v5a1I~
int mousescrollchk(int Pcol,int Prow)                              //~vXXER~
{                                                                  //~v5a1I~
	int posid,ms;                                                  //~v510R~
//****************************                                     //~v5a1I~
dprintf("%s:%s Mscrolltimer=%d,col=%d,row=%d,Mlbposid=%x\n",UTT,(char*)utimeedit("HHMMSS.MIL",0),Mscrolltimer,Pcol,Prow,Mlbposid);//~vb7AR~
	ms=Mscrolltimer;                                               //~v510I~
    if (!ms)                                                       //~v510I~
    	return 4;                                                  //~v510I~
	for (;;)                                                       //~v5a1I~
    {                                                              //~v5a1I~
dprintf("%s:Mdragacceptsw=%d\n",UTT,Mdragacceptsw);                //~vb7zI~
    	if (Mdragacceptsw)	//dnd started                          //~vb7zI~
        	break;                                                 //~vb7zI~
    	if (posid=wxe_mouseedgechk(Pcol,Prow),!posid)	//chk file scr edge//~v5a1I~
        	break;                                                 //~v5a1I~
    	posid=TID_SCROLLCHK|posid;                                 //~v5a1I~
        if (Mlbposid!=posid)                                       //~v5a1I~
        {                                                          //~v51uI~
                                                                   //~v51uI~
dprintf("%s:starttimer posid=%x,col=%d,row=%d\n",UTT,posid,Pcol,Prow);//~vXXER~//~vb7AR~
		    usettimer(posid,ms,0);                                 //~vXXER~
            Mscrolltimereventctr=0; //start timer                  //~v51uI~
        }                                                          //~v51uI~
dprintf("%s:continueed timer Mlbposid=%x,col=%d,row=%d\n",UTT,posid,Pcol,Prow);//~vXXER~//~vb7AR~
        Mlbposid=posid;                                            //~v5a1I~
    	return 1;                                                  //~v5a1I~
    }                                                              //~v5a1I~
dprintf("%s:set Mlbposid=0 posid=%x,col=%d,row=%d\n",UTT,posid,Pcol,Prow);//~vXXER~//~vb7AR~
    Mlbposid=0;                                                    //~v5a1I~
    return 0;                                                      //~v5a1I~
}//mousescrollchk                                                  //~v5a1I~
                                                                   //~vXXEI~
//===============================================================================//~v63hM~
//add file to drag filename list                                   //~v63hM~
//===============================================================================//~v63hM~
void mousedragfile(int Pdragopt,void *Ppcw,void* Pplh)             //~vXXER~
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
    dprintf("mousedragfile pcw=%p\n",Mdragpcw);                    //~vXXER~
    wxe_dragset(Ppcw,plh1,plh2);                                   //~v63hR~
    gxemfrm_enabletoolbar(0);//toolbar icon enable/disable         //~v682I~
	xxemain_scrinvalidate(0);                                      //~vXXEI~
    return;                                                        //~v63hM~
}//mousedragfile                                                   //~v63hM~
//===============================================================================//~v63hI~
//request dragdrop                                                 //~v63hI~
//return filename list or 0(do nothing)                            //~vXXER~
//===============================================================================//~v63hI~
int mousedodrag(void *Ppcw,int Popt)                               //~vXXER~
{                                                                  //~v63hI~
    char *dragbuff;                                                //~v63hI~
    int rc;                                                        //~vXXER~
// 	COleDataSource DropData;                                       //~vXXER~
//************************************                             //~v63hI~
#ifdef XXX                                                         //~v685I~
	rc=wxe_dragdropfilelist(DRAG_REDRAW,Ppcw,0,&buffsz);           //~v63iR~
    if (rc)                                                        //~v63hI~
    	return 0;                                                  //~v63hR~
    if (!buffsz)                                                   //~v63hI~
    	return 0;                                                  //~v63hI~
//    buffsz+=sizeof(DROPFILES)+2;	//\0\0 for terminater          //~vXXER~
    buffsz+=2;	//\0\0 for terminater                              //~vXXEI~
    dragbuff=(char*)umemalloc(buffsz);                             //~v63hR~
    if (!dragbuff)                                                 //~v63hI~
    	return 0;                                                  //~v63hI~
    memset(dragbuff,0,(UINT)buffsz);                               //~v63hI~
#endif                                                             //~v685R~
	if (Popt & DNDDODRAG_COPY)                                     //~v63iI~
    {                                                              //~vXXEI~
		rc=mousedragsetuplist(Ppcw,&dragbuff);                     //~vXXEI~
	    if (!rc)                                                   //~vXXER~
    		return 0;                                              //~vXXEI~
    	return mousedragcopy(Ppcw,dragbuff);                       //~vXXER~
    }                                                              //~vXXEI~
	if (!(Popt & DNDDODRAG_BEGIN))                                 //~v71xI~
    {                                                              //~v71xI~
        Mdraglist=0;		//for duplicate call chk               //~v71xI~
        if (wxe_isremotefile(Ppcw))                                //~v71xI~
    	{                                                          //~v71xI~
            uerrmsg("Be patient until cursor shape change,It took time to download remote file.",0);//~v71xR~
            xxe_scrdisp();//display errmsg                         //~v71xI~
    		upostmsg(ID_SCREEN_DRAW,0,0);                          //~v71xI~
//  		xxemain_scrinvalidate(0);                              //~v71xR~
        }                                                          //~v71xI~
		upostmsg(ID_FILE_DNDDRAGOUTSETUP,(ULONG)Ppcw,SDFP2_SETUPREQ);//callback is xxemain_setupdragfile_//~v71xI~
dprintf("%s:dodrag upostmsg pcw=%p\n",(char*)utimeedit("HH:MM:SS.MIL",0),Ppcw);//~v71xI~
    	return 0;                                                  //~v71xI~
    }                                                              //~v71xI~
	Mdragedpcw=Ppcw;                                               //~vXXEM~
//  Mdraglist=0;		//for duplicate call chk                   //~v71xR~
    dprintf("%s:before drag begin pcw=%p\n",(char*)utimeedit("HHMMSS.MIL",0),Mdragedpcw);//~vXXER~
    udragbegin(Mdragtimeout);		//begin drag                   //~vXXER~
//    rc=wxe_dragdropfilelist(DRAG_REDRAW|DRAG_REMOTECOPY,Ppcw,dragbuff,0);//~vXXER~
//    if (rc)                                                      //~vXXER~
//    {                                                            //~vXXER~
//        umemfree(dragbuff);                                      //~vXXER~
//        return 0;                                                //~vXXER~
//    }                                                            //~vXXER~
    dprintf("%s:mousedodrag:begin requested\n",(char*)utimeedit("HHMMSS.MIL",0));//~vXXER~
    return 1;                                                      //~vXXER~
}//mousedodrag                                                     //~v63hI~
//===============================================================================//~vXXEI~
//setup drag file list                                             //~vXXEI~
//rc:1:setup ok                                                    //~vXXER~
//===============================================================================//~vXXEI~
int mousedragsetuplist(void *Ppcw,char **Pplist)                   //~vXXER~
{                                                                  //~vXXEI~
    char *dragbuff;                                                //~vXXEI~
    int buffsz,rc/*,posid*/;                                       //~vXXEI~
//************************************                             //~vXXEI~
    dprintf("%s:xxemain_setuplist entry\n",(char*)utimeedit("HH:MM:SS.MIL",0));//~v71xI~
	rc=wxe_dragdropfilelist(DRAG_REDRAW,Ppcw,0,&buffsz);           //~vXXEI~
    if (rc)                                                        //~vXXEI~
    	return 0;                                                  //~vXXEI~
    if (!buffsz)                                                   //~vXXEI~
    	return 0;                                                  //~vXXEI~
    buffsz+=2;	//\0\0 for terminater                              //~vXXEI~
    dragbuff=(char*)umemalloc(buffsz);                             //~vXXEI~
    if (!dragbuff)                                                 //~vXXEI~
    	return 0;                                                  //~vXXEI~
    memset(dragbuff,0,(UINT)buffsz);                               //~vXXEI~
	rc=wxe_dragdropfilelist(DRAG_REDRAW|DRAG_REMOTECOPY,Ppcw,dragbuff,0);//~vXXEI~
	if (rc)                                                        //~vXXEI~
    {                                                              //~vXXEI~
		umemfree(dragbuff);                                        //~vXXEI~
    	return 0;                                                  //~vXXEI~
    }                                                              //~vXXEI~
    *Pplist=dragbuff;                                              //~vXXEI~
    dprintf("%s:xxemain_setuplist exit\n",(char*)utimeedit("HH:MM:SS.MIL",0));//~v71xI~
    return 1;                                                      //~vXXEI~
}//mousedragsetuplist                                              //~vXXEI~
//===============================================================================//~v63iI~
//copy dropfilename to clipboard(setup dnd source by copy)         //~vXXER~
//===============================================================================//~v63iI~
int mousedragcopy(void * Ppcw,char *Plist)                         //~vXXER~
{                                                                  //~v63iI~
    char *purl;                                                    //~vXXEI~
//************************************                             //~v63iI~
#ifdef XXE                                                         //~vXXER~
    purl=usetupuri(USUO_COPYFILE,Plist);                           //~vXXER~
	 dprintf("mousedragcopy:listtop=%s\n",purl);                    //~vXXER~
    uclipboard_setcopyfile(purl,strlen(purl));                     //~vXXER~
    umemfree(Plist);                                               //~vXXEI~
//  umemfree(purl);		//dont free ,callback require              //~vXXER~
#else                                                              //~vXXEI~
	if (!Mpview->OpenClipboard())                                  //~v63iI~
    	return uerrlast("OpenClipboard");                          //~v63iI~
	EmptyClipboard();                                              //~v63iI~
	SetClipboardData(CF_HDROP,Phmem);                              //~v63iI~
	CloseClipboard();                                              //~v63iI~
#endif                                                             //~vXXEI~
    return 0;                                                      //~vXXER~
}//mousedragcopy                                                   //~v63iI~
//===============================================================================//~v63iI~
//copy drop file by edit_copy                                      //~v63iI~
//===============================================================================//~v63iI~
int  mousedragcopychk(void)                                        //~vXXER~
{                                                                  //~v63iI~
	void *pcw;                                                     //~v63iI~
//************************************                             //~v63iI~
	if (!wxe_dragselectchk(DRAGOPT_DRAG,0,-1,-1,&pcw,0))	//-1:curr pcw,no pending drag//~v63iI~
    	return 0;		//do nothing                               //~v63iI~
	return mousedodrag(pcw,DNDDODRAG_COPY);                        //~vXXER~
}//mousedragcopychk                                                //~v63iI~
//===============================================================================//~v71xI~
//drag file setup(scheduled  by internal upostmsg)                 //~v71xR~
//===============================================================================//~v71xI~
int xxemain_setupdragfile(ULONG Pcmdparm1,ULONG Pcmdparm2)         //~v71xI~
{                                                                  //~v71xI~
	char *pbuff;                                                   //~v71xI~
//*****************                                                //~v71xI~
    dprintf("%s:xxemain_setupdragfile pcw=%lx,parm2=%lx\n",(char*)utimeedit("HH:MM:SS.MIL",0),Pcmdparm1,Pcmdparm2);//~v71xR~
	if (Pcmdparm2 & SDFP2_SETUPREQ)                                //~v71xI~
    {                                                              //~v71xI~
		Mdragedpcw=(void*)Pcmdparm1;                               //~v71xR~
		xxemain_mousedraggetdata(&pbuff);                          //~v71xI~
        if (wxe_isremotefile(Mdragedpcw))                          //~v71xI~
    	{                                                          //~v71xI~
            uerrmsg("Remote file setup end.",0);                   //~v71xR~
            xxe_scrdisp();//display errmsg                         //~v71xI~
			upostmsg(ID_SCREEN_DRAW,0,0);                          //~v71xR~
        }                                                          //~v71xI~
		upostmsg(ID_FILE_DNDDRAGOUTSETUP,Pcmdparm1,SDFP2_SETUPEND);//callback is xxemain_setupdragfile_//~v71xR~
dprintf("%s:xxemain_setupdragfile setup end\n",(char*)utimeedit("HH:MM:SS.MIL",0));//~v71xI~
    }                                                              //~v71xI~
    else                                                           //~v71xI~
    {                                                              //~v71xI~
		mousedodrag((void*)Pcmdparm1,DNDDODRAG_BEGIN);             //~v71xR~
dprintf("%s:xxemain_setupdragfile begin requested\n",(char*)utimeedit("HH:MM:SS.MIL",0));//~v71xI~
	}                                                              //~v71xI~
	xxemain_scrinvalidate(0);                                      //~v71xI~
    return 0;                                                      //~v71xI~
}//xxemain_setupdragfile                                           //~v71xI~
//===============================================================================//~v71sI~
//drag begin callback                                              //~v71sI~
//===============================================================================//~v71sI~
int  xxemain_mousedragbegin(void)                                  //~v71sI~
{                                                                  //~v71sI~
//************************************                             //~v71sI~
dprintf("%s:%s:enter,Mdragacceptsw=%d-->0\n",UTT,(char*)utimeedit("HH:MM:SS.MIL",0),Mdragacceptsw);//~vb7zI~
	Mdragacceptsw=0;	//data returned                            //~v71sI~
//    if (wxe_isremotefile(Mdragedpcw))                            //~v71xR~
//    {                                                            //~v71xR~
//        uerrmsg("Be patient until cursor shape change,It took time to download remote file.",//~v71xR~
//                0);                                              //~v71xR~
//        xxe_scrdisp();//display errmsg                           //~v71xR~
//    }                                                            //~v71xR~
    return 0;                                                      //~v71sI~
}//xxemain_mousedragbegin                                          //~v71sI~
//===============================================================================//~vXXEI~
//get drag file name list (drag get event)                         //~vXXEI~
//===============================================================================//~vXXEI~
int  xxemain_mousedraggetdata(char **Pplist)                       //~vXXER~
{                                                                  //~vXXEI~
    int rc;                                                        //~vXXEI~
    char *dragbuff;                                                //~vXXEI~
//************************************                             //~vXXEI~
    dprintf("%s:xxemain_mousedraggetdata pcw=%p,list=%p\n",(char*)utimeedit("HH:MM:SS.MIL",0),Mdragedpcw,Mdraglist);//~vXXER~
    dprintf("mouse draggetdata pointer is grabed?=%d\n",gdk_pointer_is_grabbed());//~v71xI~
	if (!Mdragedpcw)                                               //~vXXEI~
    	return 0;                                                  //~vXXEI~
    if (!Mdraglist)                                                //~vXXER~
    {                                                              //~vXXEI~
	    dprintf("%s:setuplist\n",(char*)utimeedit("HH:MM:SS.MIL",0));//~vXXER~
		rc=mousedragsetuplist(Mdragedpcw,&dragbuff);               //~vXXER~
    	if (!rc)    //do nothing                                   //~vXXER~
    		return 0;                                              //~vXXEI~
        Mdraglist=dragbuff;                                        //~vXXEI~
	    dprintf("%s:setuplist end\n",(char*)utimeedit("HH:MM:SS.MIL",0));//~vXXER~
	    dprintf("mouse draggetdata pointer is grabed?=%d\n",gdk_pointer_is_grabbed());//~v71xI~
    }                                                              //~vXXEI~
    dprintf("%s:drag data get return list=%p\n",(char*)utimeedit("HH:MM:SS.MIL",0),Mdraglist);//~vXXER~
//	Mdragacceptsw=1;	//data returned                            //~v71sR~
  	Mdragacceptsw++;	//data returned                            //~v71sI~
    *Pplist=Mdraglist;	//caller free                              //~vXXER~
//  Mdraglist=0;    //may be called twice                          //~vXXER~
    dprintf("%s:%s:return 1 Mdragacceptsw=%d\n",UTT,(char*)utimeedit("HH:MM:SS.MIL",0),Mdragacceptsw);//~var8I~
    return 1;                                                      //~vXXER~
}//xxemain_mousedraggetdata                                        //~vXXEI~
//===============================================================================//~vXXEI~
//get drag file name list (drag get event)                         //~vXXEI~
//===============================================================================//~vXXEI~
int  xxemain_mousedragend(void)                                    //~vXXER~
{                                                                  //~vXXEI~
//************************************                             //~vXXEI~
	dprintf("mousedragend acceptsw=%d,dragpcw=%p,dragged=%p,draglist=%p,droprc=%d\n",Mdragacceptsw,Mdragpcw,Mdragedpcw,Mdraglist,Mdroprc);//~v685R~
//    if (Mdragacceptsw)  //drop accepted                          //~v685R~
//        wxe_dragreset(Mdragpcw,DRAG_RESETDRAW|DRAG_RESETMSG); //reset draged file list//~v685R~
//    else                                                         //~v685R~
//        wxe_dragreset(Mdragpcw,DRAG_RESETDRAW|DRAG_CANCELMSG); //reset draged file list//~v685R~
//    if (Mdragacceptsw==2)   //getdata called twice               //~v71xR~
//        uerrmsg("DragDrop processed",0);                         //~v71xR~
//    else                                                         //~v71xR~
//        uerrmsg("DragDrop canceled",0);                          //~v71xR~
//    xxe_scrdisp();//display errmsg                               //~v71xR~
	  dprintf("%s:Mdragacceptsw=%d,Mdroprc(bool)=%d,Gxxestat=%x\n",UTT,Mdragacceptsw,Mdroprc,Gxxestat);//~vb7AR~
    if (!Mdragacceptsw)  //not once callback draggetdata           //~v71xI~
    {                                                              //~v71xI~
		gdk_pointer_ungrab ( GDK_CURRENT_TIME); //required to avoid hung when mouse butun released before drag begin called//~v71xR~
		gdk_keyboard_ungrab( GDK_CURRENT_TIME); //for remote it take time to reache to drag begin call//~v71xR~
        uerrmsg("DragDrop canceled",0);                            //~v71xI~
    }                                                              //~v71xI~
    else                                                           //~v71xI~
    {                                                              //~v76gI~
      if (!(Gxxestat & GXXES_DNDUTIL)) //not override errmsg(csr pos err)//~v76gR~
       if (Mdroprc)   //dropfile bool=success                      //~vb7AR~
        uerrmsg("DragDrop Accepted",0);                            //~v71xI~
    }                                                              //~v76gI~
    xxe_scrdisp();//display errmsg                                 //~v71xI~
	xxemain_scrinvalidate(0);                                      //~vXXEI~
    Mdragacceptsw=0;	//drop accepted                            //~vXXEM~
    Mdragedpcw=0;                                                  //~vXXEI~
    Mdroprc=-1;                                                    //~v685I~
    if (Mdraglist)                                                 //~vXXEI~
    {                                                              //~vXXEI~
    	umemfree(Mdraglist);                                       //~vXXER~
    	Mdraglist=0;    //data_get may be called twice             //~vXXER~
    }                                                              //~vXXEI~
    return 1;                                                      //~vXXEI~
}//xxemain_mousedragend                                            //~vXXEI~
//===============================================================================//~v69ZI~
//global function:reset Mcpcopysw by reset key operation(called from xecap.c)//~v69ZI~
//===============================================================================//~v69ZI~
void wxemouse_capi(int Popt,void *Ppmain)                          //~v69ZI~
{                                                                  //~v69ZI~
//static CWxemain *Spmain;                                         //~v69ZR~
//*******************************                                  //~v69ZI~
//    if (Popt==WXEM_INIT)                                         //~v69ZR~
//    {                                                            //~v69ZR~
//        Spmain=(CWxemain*)Ppmain;                                //~v69ZR~
//        return;                                                  //~v69ZR~
//    }                                                            //~v69ZR~
	if (Popt==WXEM_RESET)                                          //~v69ZI~
    {                                                              //~v69ZI~
        Mcpcopysw=0;                                               //~v69ZI~
        Mcpcopypansw=0;                                            //~v69ZI~
    	gxemfrm_enabletoolbar(0);//toolbar icon enable/disable     //~v702I~
        return;                                                    //~v69ZI~
    }                                                              //~v69ZI~
	if (Popt==WXEM_SETRGN)                                         //~v69ZI~
    {                                                              //~v69ZI~
    	gxemfrm_enabletoolbar(0);//toolbar icon enable/disable     //~v702I~
        return;                                                    //~v69ZI~
    }                                                              //~v69ZI~
	if (Popt==WXEM_SETRGN2)                                        //~vbd8I~
    {                                                              //~vbd8I~
        Mcpcopysw=2;                                               //~vbd8I~
    	gxemfrm_enabletoolbar(0);//toolbar icon enable/disable     //~vbd8I~
        return;                                                    //~vbd8I~
    }                                                              //~vbd8I~
    return;                                                        //~v69ZI~
}//wxemouse_capreset                                               //~v69ZI~
//===============================================================================//~va7DI~
//csr pos change by kbd operation (assume lb down)                 //~va7DI~
//===============================================================================//~va7DI~
int mouse_csrmovedbykbd(int Popt)                                  //~va7DR~
{                                                                  //~va7DI~
//*******************************                                  //~va7DI~
#ifdef AAA                                                         //~va7SI~
    if (Mcpcopysw==2) //mouse dragged                              //~va7DI~
    	Mcpcopysw=0;                                               //~va7DI~
    if (Mcppastesw==2) //mouse dragged                             //~va7DI~
    	Mcppastesw=0;                                              //~va7DI~
#endif                                                             //~va7SI~
    gxemfrm_enabletoolbar(0);//toolbar icon enable/disable         //~va7DM~
    return 0;                                                      //~va7DI~
}//mouse_csrmovedbykbd                                             //~va7DR~
//===============================================================================//~vbd2I~
//cut & paste:selectall                                            //~vbd2I~
//===============================================================================//~vbd2I~
int xxemain_cpselectall(void)                                      //~vbd2I~
{                                                                  //~vbd2I~
//************************************                             //~vbd2I~
	wxe_capreset();                                                //~vbd2I~
    Mcpcopypansw=0;		//file panel                               //~vbd2I~
    wxe_capselectall();                                            //~vbd2I~
	Mcpcopysw=2;	//moved width lbutton down                     //~vbd2I~
    gxemfrm_enabletoolbar(0);//toolbar icon enable/disable         //~vbd2I~
	xxemain_scrinvalidate(0);                                      //~vbd2I~
    return 0;                                                      //~vbd2I~
}//cpselectall                                                     //~vbd2I~
//===============================================================================//~vbd2I~
//menu disable/enable for SelectAll                                //~vbd2I~
//===============================================================================//~vbd2I~
BOOL xxemain_cpupdateselectall(void)                               //~vbd2I~
{                                                                  //~vbd2I~
	int rc;                                                        //~vbd2I~
//****************************                                     //~vbd2I~
UTRACEP("%s:updatepastestd Mcpcopysw=%d\n",UTT,Mcpcopysw);         //~vbd2I~
    rc=wxe_capchkselectall();                                      //~vbd2I~
dprintf("%s:updatepastestd Mcpcopysw=%d,capchkselectall rc=%d\n",UTT,Mcpcopysw,rc);//~vbd2I~
    return rc!=0;                                                  //~vbd2I~
}//xxemain_cpupdateselectall                                       //~vbd2I~
//===============================================================================//~vbj2I~
BOOL onfileCHL(int Pcmd)                                           //~vbj2I~
{                                                                  //~vbj2I~
	int rc;                                                        //~vbj2I~
//****************************                                     //~vbj2I~
	UTRACEP("%s:cmd=%c\n",UTT,Pcmd);                               //~vbj2I~
    rc=wxe_CHLcmd(0,Pcmd);                                         //~vbj2I~
	UTRACEP("%s:rc=%d\n",UTT,rc);                                  //~vbj2I~
	xxemain_scrinvalidate(0);                                      //~vbj2I~
    return rc==0;                                                  //~vbj2I~
}                                                                  //~vbj2I~
//===============================================================================//~vbj3I~
BOOL onfileCHLdblclick()                                           //~vbj3I~
{                                                                  //~vbj3I~
	int rc;                                                        //~vbj3I~
//****************************                                     //~vbj3I~
	UTRACEP("%s\n",UTT);                                           //~vbj3I~
    rc=wxe_CHLcmd(0,'x');                                          //~vbj3I~
    return rc==0;                                                  //~vbj3I~
}                                                                  //~vbj3I~
//===============================================================================//~vbj4I~
BOOL chkCHLselect(CPoint Ppoint)                                   //~vbj4R~
{                                                                  //~vbj4I~
	int row,rowold,rc;                                             //~vbj4I~
//****************************                                     //~vbj4I~
  	if (!(wxe_isCHLLine(0)))   //oldline                           //~vbj4I~
    {                                                              //~vbj4I~
		SrowCHL=0;                                                 //~vbj4I~
    	return 0;                                                  //~vbj4I~
    }                                                              //~vbj4I~
    row=ROW(Ppoint.y);                                             //~vbj4I~
    rowold=Mcellcopy1.y;                                           //~vbj4I~
    if (row==rowold)      //click on selected line on CHL          //~vbj4I~
    {                                                              //~vbj4I~
		UTRACEP("%s,row=%d\n",UTT,SrowCHL);                        //~vbj4I~
    	SrowCHL=row;    //chk at lbup                              //~vbj4I~
        rc=1;                                                      //~vbj4I~
    }                                                              //~vbj4I~
    else                                                           //~vbj4I~
    {                                                              //~vbj4I~
    	SrowCHL=0;                                                 //~vbj4I~
        rc=0;                                                      //~vbj4I~
    }                                                              //~vbj4I~
    return rc;                                                     //~vbj4I~
}                                                                  //~vbj4I~
//===============================================================================//~vbj4I~
BOOL selectedCHL(UINT Pflag,CPoint Ppoint)                         //~vbj4R~
{                                                                  //~vbj4I~
	int rc,row;                                                    //~vbj4I~
//****************************                                     //~vbj4I~
	UTRACEP("%s,row=\n",UTT);                                      //~vbj4I~
    if (!SrowCHL)      //click on CHL line                         //~vbj4I~
    	return 0;                                                  //~vbj4I~
    row=ROW(Ppoint.y);                                             //~vbj4I~
    if (row!=SrowCHL)                                              //~vbj4I~
    	return 0;                                                  //~vbj4I~
    rc=onfileCHL('s');	//with invalidate                          //~vbj4I~
    return rc==0;                                                  //~vbj4I~
}                                                                  //~vbj4I~
