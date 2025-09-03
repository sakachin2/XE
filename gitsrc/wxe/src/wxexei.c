//*CID://+vbDqR~:                              update#=  569;      //~vbDqR~
//*********************************************************************//~v440I~
//* wxe interface definition                                       //~v440I~
//*********************************************************************//~v440I~
//vbDq:250728 (WXE:bug)vhex to data err when xpos split ucs4       //~vbDqI~
//vbDg:250706 (wxe)4byte dbcs missing display tab padding          //~vbDgI~
//vbD6:250702 (WXE)exception handling using DbgHelp API            //~vbD6I~
//vbt9:201214 WXE help was double line, exceed screen height when /??//~vbt9I~
//vbt7:201213 (WXE:bug)WM_CHAR receives UTF16,do not chk DBCS. WizKey input is checked as dbcs 1st byte.//~vbt7I~
//vbj2:180424 popup menu on cmd history list                       //~vbj2I~
//vb4t:160812 consider errmsg 2nd line for combine                 //~vb4tI~
//vb4q:160810 display ligature/combine mode on "TOP OF LINE"       //~vb4qI~
//vb4i:160805 vb4f for wxe(specify ligature on/off,combine on/of line by line)//~vb4iI~
//vb3q:160617 (BUG)dbcsspace dispchar should be fix to ffff(apply assign by ini file to LC file only)//~vb3qI~
//vb3p:160616 (BUG)when utf8 ligature on,1st colomn green is ligatured to linono//~vb3pI~
//vb2J:160313 (W32) compier warning                                //~vb2JI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vafn:120626 (Win:BUG)ptr list size is not 4 byte but 8 byte for LLP64 and LP64//~vafnI~
//vaa3:110926 (WXEXXE:BUG)mouse lineselect on top menu,row count was changed;//~vaa3I~
//va7S:100907 (BUG)mouse drag at edge of screen dose not expand copy range bat scroll.//~va7SI~
//va7D:100830 (XXE:BUG)cap menu update err(it should not be based on Mcellcopy1 bur Gcsrposy)//~va7DI~
//va75:100806 (BUG:WXE)force eng to errmsg when charset changed on setupdialog//~va75I~
//va6q:000623 avoid ligature for not data line(gauge, xline etc)   //~va6qI~
//va5z:100519 (WXEXXE) spell miss(temorarily)                      //~va5zI~
//va3D:100310 (WXE)Unicode direct input support(A+"+" and Uxxxx)   //~va3DI~
//va3t:100221 (WXEXXE)break also at prev char of vhex data csr pos for backspace at vhex line//~va3tI~
//va3k:100210 (BUG:WIN)vsplit line draw err(=1,=2,edit hdr line at right half)//~va3kI~
//va3h:100207 try ligature for also win32 console version          //~va3hI~
//va3g:100207 try ligature for also wxe(write ucs string at once) for arabic etc//~va3gI~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//v7ah:081120 (WXE:bug)helpmsg popup for each line                 //~v7ahI~
//v79z:080916 DBCS tbl for C and K of CJK                          //~v79zI~
//v780:080212 syntaxhighlight support (SYN cmd,C+s func key)       //~v780I~
//v76n:070628 scroll size support for =2/=1 panel                  //~v76nI~
//v73y:070128-(WXE/XXE)Quiet-exit support                          //~v73yI~
//v71B:061031 (WXE:Vista)use not sjis but default_charset for englishmode//~v71BI~
//v71s:061022 err msg when drag canceled by mouse lb release       //~v71sI~
//v70z:060904 3270 ftp support                                     //~v70zI~
//v705:060727 graphic char setup by external file                  //~v705I~
//v69m:060524 (WXEXXE)pass scroll ctr not by string cmd parm but thrugh gbl var to avoid cmd line input cleared//~v69mI~
//v69j:060523 (WXEXXE)avoid horizontal scroll err msg for dir list //~v69jI~
//v69h:060521 (WXE)windows generate WM_HSCROLL by Shift+Wheel; so S+Wheel(filend) and C+Wheel(Hscroll)//~v69hI~
//v69g:060521 (WXE)tilt wheel mouse generate WM_VSCROLL/WM_HSCROLL by mycrosoft spec//~v69gI~
//            if scroll bar exist.(both vertical and horizontal is requred to genarate both)//~v69gI~
//v69f:060521 (WXE)xbutton1/2 support;browser backk/forwardlock on status for up/down arrow key to scroll up/down//~v69fI~
//v69b:060516 horizontal scroll function by Left/Right key on ScrollLock status//~v69bI~
//v67G:051231 (WXEXXE)display menu before termination confirm dialog//~v67GI~
//v672:051225 (WXE) errmsg issue when no key/cmd assigned to the func//~v672I~
//v671:051224 (WXE:BUG) cmdline wxe with filename;fullpath modified by WXE implicit /R option. skip set /R when pos parm exist//~v671I~
//v66A:051220 dialog to confirm wxe/gxe termination when func-key used//~v66AI~
//v64m:050623 (WXE:BUG)compiler warning(no initialized variable used)//~v64mI~
//v62N:050417 (WXE)del utrace                                      //~v62NI~
//v58i:040912 (WXE)scroll by lb-press;once short stop at eof of file/dir line//~v58iI~
//v56x:040414 (WXE)tell pid to wxe to chk pid active(spawan returns dos prompt pid)//~v56xI~
//v56j:040404 (WXE)support DPU/DPD by mouse dblclick               //~v56jI~
//v56g:040404 (WXE)use lcmd to reset filename list top entry       //~v56gI~
//v56e:040404 xp open dir by explorler,so allow dir for openwith   //~v56eI~
//v56c:040403 (WXE)change to use associaten when dblclicked if mous pos is left edge//~v56cI~
//v56a:040403 (WXE)open by xe if lbtndblclick position is linecmd fld(not by shift key)//~v56aI~
//v569:040402 (WXE)open by xe if lbtndblclick is with Shift key(ignore association)//~v569I~
//v568:040402 (WXE:BUG)ignore association for dir(force open by xe)//~v568I~
//v567:040402 (WXE:BUG)dir list dblclick skipped associatiob chk   //~v567I~
//v55U:040321 (WXE)openwith when dblclick on filenamelist/dirlist if associated//~v55UI~
//v55o:040222 (FTP)use client pgm for avoid dos prompt screen appear//~v55oI~
//v55c:040208 (WXE)distingush L-CTL/R-CTL & report R-CTL           //~v55cI~
//v55b:040208 (WXE)ignore scroll req except file/dirlist/fnamelist //~v55bI~
//v54w:040114 refrect to dblclick on dirname on filename liist panell//~v54wI~
//v54v:040114 display and select by cursor the driveid list.       //~v54vI~
//v53z:031012 (WXE)redraw required when charset changed for unprintable may changed//~v53zI~
//v53x:031005 (WXE:BUG)browse or edit determination for dirlist dblclick//~v53xI~
//v53o:030929 (WXE:BUG)initialy english mode unprintable charset   //~v53oI~
//                     charset is considered later                 //~v53oI~
//v53n:030929 (WXE:BUG)cahrset chnange dose not effect on unpdispchar//~v53nI~
//v53b:030921 (WXE:BUG)bell when cross  lineno field seperator     //~v53bI~
//v53a:030921 (WXE:BUG)stop scroll when leave edge not over end-of-file//~v53aI~
//v51w:030615 (WXE)icon for MDOS and Explorer                      //~v5a0I~
//v5a0:030202 capcopy by lb dblclick on file scr                   //~v5a0I~
//v500:021003 (WXE:BUG)initial color is all black.    over update#175//~2A03I~
//v500:020827 wxe support                                          //~v440I~
//*********************************************************************//~v440I~
#include <time.h>                                                  //~v440I~
#include <stdio.h>                                                 //~v440I~
#include <stdlib.h>                                                //~v440I~
#include <string.h>                                                //~v440I~
#include <io.h>                                                    //~v568I~
//*************************************************************    //~v440I~
#include <windows.h>                                               //~v440I~
//*************************************************************    //~v440I~
#include <ulib.h>                                                  //~v440I~
#include <uque.h>                                                  //~v440I~
#include <uvio.h>                                                  //~v440I~
#include <uviom.h>                                                 //~vb4iI~
#include <ufile.h>                                                 //~v440I~
#include <udbcschk.h>                                              //~2915I~
#include <uerr.h>                                                  //~2928I~
#include <ualloc.h>                                                //~2929I~
#include <utrace.h>                                                //~2929M~
#include <uproc.h>                                                 //~v55oI~
#include <ustring.h>                                               //~v55UI~
#include <uwinsub.h>                                               //~v55UI~
#include <uftp.h>                                                  //~v76nI~
#include <utf.h>                                                   //~va3hI~
#include <ueh.h>                                                   //~vbD6I~
                                                                   //~v440I~
#include "xe.h"                                                    //~v440R~
#include "xescr.h"                                                 //~v440I~
#include "xekbd.h"                                                 //~vafkM~
#include "xescr2.h"                                                //~2929I~
#include "xecsr.h"                                                 //~2929I~
#include "xefile.h"                                                //~v440I~
#include "xepan.h"                                                 //~v440I~
#include "xepan22.h"                                               //~v54vI~
#include "xegbl.h"                                                 //~2929I~
#include "xefunc.h"                                                //~2A03I~
#include "xefunc2.h"                                               //~2929I~
#include "xefunct.h"                                               //~2A03I~
#include "xesub.h"                                                 //~2929I~
#include "xedir.h"                                                 //~v55UI~
#include "xedlcmd.h"                                               //~v55UI~
#include "xedlcmd2.h"                                              //~v55UR~
#include "xedlcmd6.h"                                              //~v56eI~
#include "xeacb.h"                                                 //~v780I~
#include "xesyn.h"                                                 //~v780I~
#include "xesyn2.h"                                                //~v780I~
#include "xeutf2.h"                                                //~va3tI~
#include "xeopt.h"                                                 //~vb4qI~
                                                                   //~v440I~
#include "wxedef.h"                                                //~v780I~
#define  WXEXEI                                                    //~v440I~
#include "wxemain.h"                                               //~v440M~
#define  WXEXEI_GLOBAL                                             //~2928I~
#include "wxexei.h"                                                //~v440I~
#include "wxexei3.h"                                               //~v56gI~
#include "wxecsub.h"                                               //~2901I~
//*************************************************************    //~2915I~
#undef   TEXTDBCS                                                  //~2915R~
#define TEXTDBCS(row,col)    (Spwxei->WXEIdbcs+(row)*MAXCOL+col)   //~2915I~
                                                                   //~v569I~
#define OPENBYXE_DLPOS1    0 //when dblclicked on dir list on this pos,//~v56aR~
#define OPENBYXE_DLPOS2    4 // open by xe ignoreing association even if exist//~v56aR~
#define OPENBYXE_HLPOS1    0 //when dblclicked on kistorylist on this pos,//~v56aR~
#define OPENBYXE_HLPOS2    2 // open by xe ignoreing association even if exist//~v56aR~
                                                                   //~v56jI~
#define DPUCOLS         0      //when dbl clicked                  //~v56jI~
#define DPUCOLE         3      //col.1-->4 for DPU(DirPathUp) cmd  //~v56jI~
#define DPDCOLS         9      //when dbl clicked                  //~v56jI~
#define DPDCOLE         6      //col.-9-->-6 for DPD(DirPathDown) cmd//~v56jI~
//*************************************************************    //~v440I~
    WXEINTF *Spwxei;                                               //~v440R~
//*************************************************************    //~v440I~
static int Sargc;                                                  //~v440I~
static int Sxeinitsw=0;                                            //~2907I~
static char **Sargv;                                               //~v440I~
static int  Sdbcssw=0;                                             //~2910I~
static INPUT_RECORD Sinprec;                                       //~2901I~
static INPUT_RECORD Sinprec_dbcs1st;                               //~2910I~
static int Slastinputkey=0;                                        //~v66AI~
//static int Sligaturerows[LIGATURE_ROW_TBSZ];                     //~vb4iR~
//*************************************************************    //~v440I~
int  wxe_lineselect_topmenu(PUCLIENTWE Ppcw,int Pshiftsw,int Prow);//~3104M~
//int  wxe_lineselect_fnamelist(PUCLIENTWE Ppcw,int Pshiftsw,int Prow);//~v56aR~
int  wxe_lineselect_fnamelist(PUCLIENTWE Ppcw,int Pshiftsw,int Prow,int Pcol);//~v56aR~
//int  wxe_lineselect_dirlist(PUCLIENTWE Ppcw,int Pshiftsw,int Prow);//~v56aR~
int  wxe_lineselect_dirlist(PUCLIENTWE Ppcw,int Pshiftsw,int Prow,int Pcol);//~v56aR~
int  wxe_lineselect_file(PUCLIENTWE Ppcw,int Pflag,int Prow,int Pcol,int *Pcapinfo);//~v5a0R~
int  wxe_lineselect_driveid(PUCLIENTWE Ppcw,int Prow,int Pshiftsw);//~v54wR~
char *wxeenqmsg(char *Ppmsg,char *Ppprevmsg);                      //~2A07R~
int  wxe_belcmd(PUCLIENTWE Ppcw,int Pshiftsw);                     //~3102I~
//int  wxe_assoclcmd(PUCLIENTWE Ppcw,int Pshiftsw);                //~v56gR~
//int  wxegetbg(PUCLIENTWE Ppcw);                                  //~2905R~
int  wxepathupdown(PUCLIENTWE Ppcw,int Pcol);                      //~v56jI~
int wxe_parmchk(int Pargc,char **Pargv);                           //~v671I~
int wxe_resethdrligature(int Popt,int Pligature);                  //~vb4qI~
//*************************************************************    //~2B30I~
//*parmproc to get workdir and trace init                          //~2B30I~
//*called from wxe.cpp                                             //~2B30I~
//*************************************************************    //~2B30I~
int wxe_preinit(int Pargc,char **Pargv)                            //~2B30R~
{                                                                  //~2B30I~
	WXEINTF wxeintf;                                               //~2B30I~
	int rc;                                                        //~2B30I~
//***********************                                          //~2B30I~
	memset(&wxeintf,0,sizeof(wxeintf));                            //~2B30I~
	rc=wxe_xecall(WXE_REQ_PREINIT,&wxeintf,Pargc,Pargv);           //~2B30R~
    return rc;                                                     //~2B30I~
}//wxe_preinit                                                     //~2B30I~
//*************************************************************    //~v55oI~
//*callback from usystem2()                                        //~v55oI~
//*p1:callback parm set when usystem_cmdserverinit()               //~v55oI~
//*************************************************************    //~v55oI~
int wxe_cmdservercallback(int Popt,void *Pcallbackparm)            //~v55oR~
{                                                                  //~v55oI~
	char *cmdservername="xesyscmd.exe";                            //~v55oI~
    char fpath[_MAX_PATH];                                         //~v55oI~
    int rc=0,pathlen;                                              //~v55oR~
//***********************                                          //~v55oI~
	if (Popt & CMDCB_INIT)                                         //~v55oI~
    {                                                              //~v55oI~
        rc=usystem_cmdserversetup(UPROC_SYSCMD_MIN,cmdservername,0,0,0);//use cmd server for system()//~v55oR~
        if (rc)                                                    //~v55oR~
        {                                                          //~v55oR~
            strcpy(fpath,__argv[0]);    //wxe pgm path             //~v55oR~
            pathlen=PATHLEN(fpath);                                //~v55oR~
            if (pathlen>0)                                         //~v55oR~
            {                                                      //~v55oR~
                strcpy(fpath+pathlen,cmdservername);               //~v55oR~
                rc=usystem_cmdserversetup(UPROC_SYSCMD_MIN,fpath,0,0,0);//use cmd server for system()//~v55oR~
            }                                                      //~v55oR~
        }                                                          //~v55oR~
        if (rc)                                                    //~v55oR~
            uerrmsgbox("shell command server:%s start failed,rc=%d.Check PATH.",//~v55oR~
                        "シェルコマンドサーバー:%s の起動失敗。rc=%d。PATHを確認してください。",//~v55oR~
                        cmdservername,rc);                         //~v55oR~
    }                                                              //~v55oI~
	if (Popt & CMDCB_WRTER)                                        //~v55oI~
    {                                                              //~v55oI~
		uerrmsgbox("Request write to shell command server afiled,rc=%d",//~v55oR~
					"シェルコマンドサーバーへの要求の書きこみ失敗。rc=%d",//~v55oR~
				errno);                                            //~v55oI~
    }                                                              //~v55oI~
    return rc;                                                     //~v55oI~
}//wxe_cmdservercallback                                           //~v55oI~
//*************************************************************    //~v440I~
//*call xe                                                         //~v440I~
//*p1:req type                                                     //~v440I~
//*p2:initreq:arg ctr                                              //~v440I~
//*p3:initreq:arg ptr list                                         //~v440I~
//*************************************************************    //~v440I~
#ifdef WIN_EXH                                                     //~vbD6R~
int wxe_xecall(int Preqtype,void *Ppwxei,int Pargc,char **Pargv)   //~vbD6I~
{                                                                  //~vbD6I~
	int wxe_xecallsub(int Preqtype,void *Ppwxei,int Pargc,char **Pargv);//~vbD6I~
	int rc=0;                                                      //~vbD6I~
	__try                                                          //~vbD6I~
  	{                                                              //~vbD6I~
		UTRACEP("%s:try\n",UTT);                                   //~vbD6I~
		rc=wxe_xecallsub(Preqtype,Ppwxei,Pargc,Pargv);             //~vbD6I~
    }                                                              //~vbD6I~
  	__except                                                       //~vbD6I~
  	(                                                              //~vbD6I~
  	//*filter-expression                                           //~vbD6I~
  		uehfilter(GetExceptionCode(),GetExceptionInformation())    //~vbD6I~
  	)                                                              //~vbD6I~
  	{                                                              //~vbD6I~
    //*exception-handler block                                     //~vbD6I~
    //never reach to this point by filter rc is CONTINUE           //~vbD6I~
    	UTRACEP("%s:excetion block\n",UTT);                        //~vbD6I~
  	}                                                              //~vbD6I~
    return rc;                                                     //~vbD6I~
}                                                                  //~vbD6I~
int wxe_xecallsub(int Preqtype,void *Ppwxei,int Pargc,char **Pargv)//~vbD6I~
#else                                                              //~vbD6I~
int wxe_xecall(int Preqtype,void *Ppwxei,int Pargc,char **Pargv)   //~v440R~
#endif                                                             //~vbD6R~
{                                                                  //~v440I~
	int rc=0;                                                      //~2908R~
    PUCLIENTWE pcw;                                                //~v67GI~
//***********************                                          //~v440I~
//UTRACEP("xecall type=%d\n",Preqtype);                            //~v62NR~
	switch(Preqtype)                                               //~v440I~
    {                                                              //~v440I~
    case WXE_REQ_PREINIT:                                          //~2B30I~
    case WXE_REQ_INIT:                                             //~v440R~
    	Spwxei=(PWXEINTF)Ppwxei;                                   //~v440R~
#ifdef UTF8UCS2                                                    //~va20I~
    	Gpwxei=Spwxei;  //to wxexei2                               //~va20I~
#endif                                                             //~va20I~
        if (!Sargv)                                                //~2C15I~
        {                                                          //~2C15I~
          if (wxe_parmchk(Pargc,Pargv))	//posparm cnt!=0           //~v671I~
          {                                                        //~v671I~
        	Sargc=Pargc;                                           //~v671I~
//        	Sargv=(char**)malloc((Sargc+1)*4);                     //~v671I~//~vafnR~
        	Sargv=(char**)malloc((Sargc+1)*PTRSZ);                 //~vafnI~
//        	memcpy(Sargv,Pargv,(Sargc+1)*4);                       //~v671I~//~vafnR~
        	memcpy(Sargv,Pargv,(Sargc+1)*PTRSZ);                   //~vafnI~
          }                                                        //~v671I~
          else                                                     //~v671I~
          {                                                        //~v671I~
        	Sargc=Pargc+1;                                         //~2C15R~
//        	Sargv=(char**)malloc((Sargc+1)*4);                     //~2C15R~//~vafnR~
        	Sargv=(char**)malloc((Sargc+1)*PTRSZ);                 //~vafnI~
//        	memcpy(Sargv,Pargv,Sargc*4);                           //~2C15R~//~vafnR~
        	memcpy(Sargv,Pargv,Sargc*PTRSZ);                       //~vafnI~
        	Sargv[Pargc]="/R";		//add parm to restore last cur dir//~2C15R~
        	Sargv[Sargc]=0;		//last null ptr;                   //~2C15R~
          }                                                        //~v671I~
        }                                                          //~2C15I~
		rc=xemain(Preqtype,Sargc,Sargv);                           //~2C15R~
        if (Preqtype==WXE_REQ_PREINIT)                             //~2B30I~
            break;                                                 //~2B30I~
        if (rc==-1)                                                //~2A07I~
            break;                                                 //~2A07I~
		wxe_kbdwcinit(1,0/*stat*/,0/*codepage*/);                  //~v79zI~
		usystem_cmdserverinit(UPROC_LAZY,wxe_cmdservercallback,0,0,0,0);//use cmd server for system()//~v55oR~
        Sxeinitsw=Preqtype;                                        //~2B30R~
    	Spwxei->WXEIdbcs=Gscrdbcstbl;    //by scrinit()            //~2901I~
    	Spwxei->WXEIsynstyle=Gsynstyletbl;    //by syninit         //~v780R~
    	Spwxei->WXEIsynrgb=Gsyncfg.SYNCrgb;    //rgb tbl by xesyn.cfg//~v780I~
        if (*Gcmdbuff) //no command pending                        //~v440I~
            kbdproc();		//initial cmd                          //~v440I~
        scrdisp();          //ist screen                           //~v440I~
    	memcpy(Spwxei->WXEIunpdispchar,Gunpdispchar,sizeof(Spwxei->WXEIunpdispchar));//~vb3qI~
        break;                                                     //~v440I~
    case WXE_REQ_TERM:                                             //~v440R~
        Sxeinitsw=Preqtype;                                        //~v7ahI~
//  	if (Sargv)	//dup chk                                      //~v55UR~
	    if (!Spwxei->WXEIxetermsw)		//xe malloc area is all freeed//~v55UI~
        {                                                          //~3125I~
//  		usystem_cmdserverterm(0,0,0);                          //~v70zR~
    		usystem_cmdserverterm(0,0,0,0);                        //~v70zI~
	    	Spwxei->WXEIxetermsw=1;		//xe malloc area is all freeed//~v55UI~
        	if (Gproclastpft)	//avoid abend at xe.c              //~3125I~
				rc=xemain(Preqtype,Sargc,Sargv);                   //~3125R~
        	free(Sargv);                                           //~3125R~
        	Sargv=0;                                               //~3125R~
//      }                                                          //~v55UR~
//      usystem_cmdserverterm(0,0,0);                              //~v56xR~
        }                                                          //~v55UI~
        break;                                                     //~v440I~
    case WXE_REQ_KEYEVENT:                                         //~v440R~
//		Gwxestat|=GWXES_KBDEVENT;	//for wxe_setcurpos,KEYEVENY called from funccall by mouse event//~va7SR~
        for (;;)                                                   //~v440I~
        {                                                          //~v440I~
UTRACEP("call kbdproc\n");                                         //~2914I~
        	rc=kbdproc();                                          //~v440I~
        	if (rc==-1)		//quit                                 //~v440I~
            {                                                      //~v66AI~
              if (Slastinputkey!=VK_RETURN)	//not by cmd input but by func key//~v66AR~
              {                                                    //~v66AI~
                    if (Gwxestat & GWXES_OPT_QEXIT)	//exit w/o dialog//~v73yI~
                    	break;                                     //~v73yI~
                    pcw=panregist(PANTOPMENU);                     //~v67GR~
    	        	scrdisp();  //set dbcs tbl before csr move     //~v67GI~
  		            wxe_scrdraw();    //redraw wxe scr @@@@        //~v67GR~
                	if (uerrmsgboxokcan("Exit xe ?","xe 終了確認")!=0)	//cancelled//~v66AR~
                    {                                              //~v66AI~
//                  	panregist(PANTOPMENU);                     //~v67GR~
                    	rc=0;	//continue process                 //~v66AI~
                    }                                              //~v66AI~
                    else                                           //~v66AI~
                    {                                              //~v67GI~
                    	panpopup(pcw);//free menu                  //~v67GI~
                    	break;                                     //~v66AI~
                    }                                              //~v67GI~
              }                                                    //~v66AI~
              else                                                 //~v66AI~
                break;                                             //~v440I~
            }                                                      //~v66AI~
        	if (!*Gcmdbuff //no command pending                    //~2908R~
            &&  !Gstrinputlen     //string input by Alt+n(line draw char func)//~v705I~
            &&  !UCBITCHK(Gprocstatus,GPROCSCSRDOWN|GPROCSCSRRIGHT))//csr move//~2908I~
            	break;                                             //~v440I~
        	if (!*Gcmdbuff) //no command pending                   //~2914I~
	        	scrdisp();  //set dbcs tbl before csr move         //~2914I~
        }                                                          //~v440I~
        if (rc==XEKBD_RC_MORE)		//request next key input       //~2915I~
        	return rc;                                             //~2915I~
        if (rc==-1)//quit                                          //~2915R~
        {                                                          //~2915I~
			wxe_xecall(WXE_REQ_TERM,Ppwxei,0,0);                   //~2915I~
        	return -1;                                             //~2915R~
        }                                                          //~2915I~
        scrdisp();          //1st screen                           //~v440I~
//		Gwxestat&=~GWXES_KBDEVENT;	//for wxe_setcurpos            //~va7DI~//~va7SR~
        break;                                                     //~v440I~
    }                                                              //~v440I~
    return rc;                                                     //~v440I~
}//wxe_xecall                                                      //~v440R~
//*************************************************************    //~v671I~
//*parmchk                                                         //~v671I~
//*ret:posparm cnt                                                 //~v671I~
//*************************************************************    //~v671I~
int wxe_parmchk(int Pargc,char **Pargv)                            //~v671I~
{                                                                  //~v671I~
	int posparmno=0,ii;                                            //~v671R~
	char *pc;                                                      //~v671R~
//***********************                                          //~v671I~
	for (ii=1;ii<Pargc;ii++)                                       //~v671R~
    {                                                              //~v671I~
    	pc=Pargv[ii];                                              //~v671R~
        if (*pc=='/'||*pc=='-')                                    //~v671I~
        	continue;                                              //~v671I~
        posparmno++;                                               //~v671I~
    }                                                              //~v671I~
    return posparmno;                                              //~v671I~
}//wxe_parmchk                                                     //~v671I~
//*************************************************************    //~2901I~
//*kbd msgproc                                                     //~2901I~
//*rc:-1:exit,1:redraw,0:no draw                                   //~2914I~
//*************************************************************    //~2901I~
int  wxe_kbdmsg(int Pstat,UINT Pchar,UINT Prepctr,UINT Pflag)      //~2901I~
{                                                                  //~2901I~
	int keystate=0,asciichar,rc,dbcssw;                            //~2921R~
//***********************                                          //~2901I~
UTRACEP("wxe_kbdmsg stat=%x,char=%x,repctr=%d,flag=%x\n",Pstat,Pchar,Prepctr,Pflag);//~va3DI~
	Slastinputkey=Pchar;                                           //~v66AI~
    if (Pflag & KF_ALTDOWN)     //winuser.h                        //~2908I~
    {                                                              //~2916I~
        keystate|=(RIGHT_ALT_PRESSED|LEFT_ALT_PRESSED);            //~2921R~
		UTRACEP("alt key\n");                                      //~2916I~
    }                                                              //~2916I~
    if (Pstat & WXEKBDMSG_SCROLLLOCKON)                            //~v69bR~
        keystate|=SCROLLLOCK_ON;                                   //~v69bI~
    if (Pstat & WXEKBDMSG_SHIFTKEY)                                //~2921R~
        keystate|=SHIFT_PRESSED;                                   //~2921R~
    if (Pstat & WXEKBDMSG_CTLKEY)                                  //~2921I~
//  	keystate|=(RIGHT_CTRL_PRESSED|LEFT_CTRL_PRESSED);          //~v55cI~
      if (Pstat & WXEKBDMSG_RCTLKEY)                               //~v55cI~
		keystate|=RIGHT_CTRL_PRESSED;                              //~v55cI~
      else                                                         //~v55cI~
		keystate|=LEFT_CTRL_PRESSED;                               //~v55cR~
    if (Pflag & ENHANCED_KEY)                                      //~2921I~
    {                                                              //~2921I~
		UTRACEP("enhanced key\n");                                 //~2921M~
        keystate|=ENHANCED_KEY;                                    //~2921I~
    }                                                              //~2921I~
                                                                   //~2921I~
    Sinprec.Event.KeyEvent.dwControlKeyState=(USHORT)keystate;     //~2921R~
                                                                   //~2921I~
	Sinprec.EventType=KEY_EVENT;                                   //~2901I~
    Sinprec.Event.KeyEvent.bKeyDown=WXEKBDMSG_KEYDOWN;             //~2921R~
//  Sinprec.Event.KeyEvent.wRepeatCount=Prepctr;                   //~2901I~//~vb2JR~
    Sinprec.Event.KeyEvent.wRepeatCount=(WORD)Prepctr;             //~vb2JI~
  if (Pstat & WXEKBDMSG_ONCHARUCS)                                 //~v79zM~
  {                                                                //~v79zM~
//  Sinprec.Event.KeyEvent.uChar.UnicodeChar=Pchar;                //~v79zM~//~vb2JR~
    Sinprec.Event.KeyEvent.uChar.UnicodeChar=(WCHAR)Pchar;         //~vb2JI~
    Sinprec.Event.KeyEvent.wVirtualKeyCode=0;    //ime id for ukbdw//~v79zI~
    dbcssw=0;                                                      //~v79zI~
  }                                                                //~v79zM~
  else                                                             //~v79zM~
  {                                                                //~v79zM~
//  Sinprec.Event.KeyEvent.wVirtualKeyCode=Pchar;                  //~2901I~//~vb2JR~
    Sinprec.Event.KeyEvent.wVirtualKeyCode=(WORD)Pchar;            //~vb2JI~
    dbcssw=0;                                                      //~2C15I~
//  if (!(Sinprec.Event.KeyEvent.wVirtualScanCode=Pflag & 0xff))   //~va3DR~
    if (Pstat & WXEKBDMSG_RAWMODE)                                 //~va3DI~
    	Sinprec.Event.KeyEvent.wVirtualScanCode=0;     //id of ime for xekbd to read twice for dbcs//~va3DI~
    else                                                           //~va3DI~
    	Sinprec.Event.KeyEvent.wVirtualScanCode=Pflag & 0xff;   //set scancode//~va3DR~
    if (!(Pstat & WXEKBDMSG_SYSKEY))   //I did not see this case   //~va3DR~
    	if (Pstat & WXEKBDMSG_ONCHAR)                              //~2C15I~
    	  if (!(Spwxei->WXEIimestat & WXEIIMES_WIDEAPI))           //~vbt7R~
          {                                                        //~vbt7I~
//      	if (SJIS1(Pchar))                                      //~va3DR~
        	if (UDBCSCHK_ISDBCS1ST(Pchar))                         //~va3DM~
	    		dbcssw=1;                                          //~2C15R~
          }                                                        //~vbt7I~
    if ((Pstat & WXEKBDMSG_ONCHAR))                                //~2921I~
    	asciichar=Pchar;                                           //~2921R~
    else                                                           //~2921I~
    	asciichar=0;                                               //~2921I~
//  Sinprec.Event.KeyEvent.uChar.AsciiChar=asciichar;              //~2908I~//~vb2JR~
    Sinprec.Event.KeyEvent.uChar.AsciiChar=(CHAR)asciichar;        //~vb2JI~
    if (Sdbcssw==1)  //saved 1st byte                              //~2C15I~
        Sdbcssw=2;                                                 //~2C15I~
    else                                                           //~2C15I~
    {                                                              //~2C15I~
    	if (dbcssw)                                                //~2C15R~
        {                                                          //~2910I~
        	Sdbcssw=1;	                                           //~2910I~
            Sinprec_dbcs1st=Sinprec;	//save 1st byte            //~2910I~
            return 0;                   //wait 2nd                 //~2910I~
		}                                                          //~2910I~
        else                                                       //~2C15I~
	    	Sdbcssw=0;                                             //~2C15I~
    }                                                              //~2C15I~
  }                                                                //~v79zI~
  	Gwxestat|=GWXES_KBDEVENT;	//for wxe_setcurpos                //~va7SI~
	rc=wxe_xecall(WXE_REQ_KEYEVENT,0,0,0);                         //~2908R~
  	Gwxestat&=~GWXES_KBDEVENT;	//for wxe_setcurpos                //~va7SR~
UTRACEP("wxe_kbdmsg rc=%d\n",rc);                                  //~2914I~
    if (rc==-1)                                                    //~2908I~
    	return -1;                                                 //~2908I~
    return rc==0;		//1:redraw                                 //~2908R~
}//wxe_kbdmsg                                                      //~2901R~
//*************************************************************    //~2A03M~
//*call xe by funcid                                               //~2A13R~
//*************************************************************    //~2A03M~
int  wxe_funccall(int Pfuncid,char *Pcmdparm)                      //~2A20R~
{                                                                  //~2A03M~
	FUNCTBL *pft;                                                  //~2A03M~
	int  rc,sc,ch;                                                 //~2A03M~
    int ignoreparmoption=0,strcmdsw;                               //~v69mI~
//***********************                                          //~2A03M~
	if (Pfuncid<0)	//ignore cmdparm if key defined                //~v69mI~
    {                                                              //~v69mI~
    	Pfuncid=-Pfuncid;                                          //~v69mI~
        ignoreparmoption=1;                                        //~v69mI~
    }                                                              //~v69mI~
	pft=functblsrch(Pfuncid);                                      //~2A03M~
    if (!pft)                                                      //~2A03M~
    	return 16;                                                 //~2A03M~
    sc=pft->FTkey[0]>>8;                                           //~2A03M~
    ch=pft->FTkey[0]&255;                                          //~2A03M~
    if (!sc && !ch)	//no key defined                               //~v69mI~
    	strcmdsw=1;                                                //~v69mI~
    else            //key defined                                  //~v69mI~
    	if (ignoreparmoption)                                      //~v69mI~
        	strcmdsw=0;                                            //~v69mI~
        else                                                       //~v69mI~
		    if (*Pcmdparm)	//parm exist                           //~v69mI~
	        	strcmdsw=1;                                        //~v69mI~
            else                                                   //~v69mI~
	        	strcmdsw=0;                                        //~v69mI~
//  if (*Pcmdparm || (!sc && !ch)) //parm exist or no key defined  //~v69mR~
    if (strcmdsw)                  //parm exist or no key defined  //~v69mI~
    {                                                              //~v672I~
    	if ((!sc && !ch)&& (!(pft->FTcmd)||!(*(pft->FTcmd)))) //parm exist or no key defined//~v672R~
        {                                                          //~v672I~
			uerrmsgbox("No key nand cmd is defined for func %s","機\x94\\ %s にキー、コマンドが割り当てられていません",pft->FTnamee);//~v67GR~
        	rc=4;                                                  //~v672I~
        }                                                          //~v672I~
        else                                                       //~v672I~
		rc=wxe_strcmd(pft->FTcmd,Pcmdparm);                        //~2A20I~
    }                                                              //~v672I~
    else	//func key input                                       //~2A20I~
    {                                                              //~2A20I~
        Sdbcssw=0;                                                 //~2A20I~
        if (pft->FTkflag[0] & FTSHIFT)  //effective with shift key(same key value with and without shift)//~2A20R~
            Sinprec.Event.KeyEvent.dwControlKeyState=SHIFT_PRESSED;//~2A20R~
        else                                                       //~2A20R~
            Sinprec.Event.KeyEvent.dwControlKeyState=0;            //~2A20R~
                                                                   //~2A20R~
        Sinprec.EventType=KEY_EVENT;                               //~2A20R~
        Sinprec.Event.KeyEvent.bKeyDown=WXEKBDMSG_KEYDOWN;         //~2A20R~
        Sinprec.Event.KeyEvent.wRepeatCount=1;                     //~2A20R~
//      Sinprec.Event.KeyEvent.wVirtualKeyCode=ch;                 //~2A20R~//~vb2JR~
        Sinprec.Event.KeyEvent.wVirtualKeyCode=(WORD)ch;           //~vb2JI~
        if (ch)                                                    //~2A20R~
//          Sinprec.Event.KeyEvent.uChar.AsciiChar=ch;             //~2A20R~//~vb2JR~
            Sinprec.Event.KeyEvent.uChar.AsciiChar=(CHAR)ch;       //~vb2JI~
        else                                                       //~2A20R~
            Sinprec.Event.KeyEvent.uChar.AsciiChar=0xe0;    //to skip ukbdw conv by shiftkey//~2A20R~
//      Sinprec.Event.KeyEvent.wVirtualScanCode=sc;                //~2A20R~//~vb2JR~
        Sinprec.Event.KeyEvent.wVirtualScanCode=(WORD)sc;          //~vb2JI~
        rc=wxe_xecall(WXE_REQ_KEYEVENT,0,0,0);                     //~2A20R~
    }                                                              //~2A20I~
UTRACEP("wxe_funccall funcid=%d,rc=%d\n",Pfuncid,rc);              //~v5a0R~
    if (rc==-1)                                                    //~2A03M~
    	return -1;                                                 //~2A03M~
    return rc;                                                     //~2A03M~
}//wxe_funccall                                                    //~2A03M~
//*************************************************************    //~3102M~
//*reset(Esc)                                                      //~3102M~
//*ret 4:cursor pos err                                            //~3102M~
//*************************************************************    //~3102M~
int  wxe_otherfunc(int Pid,char *Pparm)                            //~3102M~
{                                                                  //~3102M~
	int funcid=0;                                                  //~3102M~
//***********************                                          //~3102M~
	switch(Pid)                                                    //~3102M~
    {                                                              //~3102M~
    case	WXEOF_END:                                             //~3102M~
    	funcid=FUNCID_END;                                         //~3102M~
        break;                                                     //~3102M~
    case	WXEOF_CANCEL:                                          //~3102M~
    	funcid=FUNCID_CANCEL;                                      //~3102M~
        break;                                                     //~3102M~
    case	WXEOF_DOSPROMPT:                                       //~v5a0I~
    	funcid=FUNCID_DOS;                                         //~v5a0I~
        break;                                                     //~v5a0I~
    default:                                                       //~3102M~
    	return 4;                                                  //~3102M~
    }                                                              //~3102M~
	return wxe_funccall(funcid,Pparm);                             //~3102M~
}//wxe_otherfunc                                                   //~3102M~
//*************************************************************    //~2A20I~
//*pass edit cmd                                                   //~2A20I~
//*************************************************************    //~2A20I~
int  wxe_strcmd(char *Pcmd,char *Pparm)                            //~2A20I~
{                                                                  //~2A20I~
	int rc;                                                        //~2A20I~
//***********************                                          //~2A20I~
    sprintf(Gcmdbuff,"%s %s",Pcmd,Pparm);                          //~2A20I~
  	Gwxestat|=GWXES_CMD;	//cmd from wxe                         //~2A20I~
	rc=wxe_xecall(WXE_REQ_KEYEVENT,0,0,0);                         //~2A20I~
  	Gwxestat&=~GWXES_CMD;	//cmd from wxe                         //~2A20I~
    return rc;                                                     //~2A20I~
}//wxe_strcmd                                                      //~2A20I~
//*************************************************************    //~2A20M~
//*pass edit/save cmd                                              //~2A20I~
//*************************************************************    //~2A20M~
int  wxe_editcmd(char *Pcmd,char *Pfnm)                            //~2A20M~
{                                                                  //~2A20M~
	int rc;                                                        //~2A20M~
    char fnm[_MAX_PATH+3];                                         //~2A20I~
//***********************                                          //~2A20M~
    if (Pfnm && *Pfnm)                                             //~3104I~
		sprintf(fnm,"\"%s\"",Pfnm);                                //~3104R~
    else                                                           //~3104I~
    	*fnm=0;                                                    //~3104I~
	rc=wxe_strcmd(Pcmd,fnm);                                       //~2A20I~
    return rc;                                                     //~2A20M~
}//wxe_editcmd                                                     //~2A20M~
//*************************************************************    //~v440I~
//*return screen buffer width                                 *    //~v440I~
//*************************************************************    //~v440I~
int  wxe_getmaxscrsize(USHORT *Ppcol,USHORT *Pprow)                //~v440I~
{                                                                  //~v440I~
//***********************                                          //~v440I~
    *Ppcol=(USHORT)Spwxei->WXEImaxcol;                             //~v440R~
    *Pprow=(USHORT)Spwxei->WXEImaxrow;                             //~v440R~
	return 0;                                                      //~v440I~
}//wxe_getmaxscrsize                                               //~v440I~
//*************************************************************    //~2901I~
//*tell scr size changed to xe                                     //~2907R~
//*************************************************************    //~2901I~
int  wxe_onsize(int Prow,int Pcol,int Pcpchngsw)                   //~2929R~
{                                                                  //~2901I~
    static int Sprow=0,Spcol=0;                                    //~2908I~
//***********************                                          //~2901I~
    if (!Prow && !Pcol)	//ignore initial event                     //~2916I~
    	return 0;                                                  //~2916I~
    if (Prow!=Sprow || Pcol!=Spcol || Pcpchngsw)                   //~2929R~
    {                   //for the case char set changed            //~2929R~
    	Sprow=Prow;                                                //~2908I~
    	Spcol=Pcol;                                                //~2908I~
UTRACEP("wxe_onsize row=%d,col=%d\n",Prow,Pcol);                   //~2916I~
    	scronsize(Prow,Pcol,Pcpchngsw);                            //~2929R~
    }                                                              //~2929R~
	return 0;                                                      //~2A20R~
}//wxe_onsize                                                      //~2A14R~
//*************************************************************    //~v440I~
//*************************************************************    //~v440I~
int  wxe_getcurpos(int *Pprow,int *Ppcol)                          //~v440I~
{                                                                  //~v440I~
//***********************                                          //~v440I~
    *Pprow=Spwxei->WXEIcsrposy;                                    //~v440R~
    *Ppcol=Spwxei->WXEIcsrposx;                                    //~v440R~
	return 0;                                                      //~v440I~
}//wxe_getcurpos                                                   //~v440I~
//*************************************************************    //~v440I~
//*************************************************************    //~v440I~
int  wxe_setcurpos(int Prow,int Pcol)                              //~v440I~
{                                                                  //~v440I~
//    int dbcssw;                                                  //~2915R~
//***********************                                          //~v440I~
//    dbcssw=(*TEXTDBCS(Prow,Pcol)==UDBCSCHK_DBCS1ST);             //~2915R~
//    if (dbcssw!=Spwxei->WXEIcsrdbcssw)                           //~2915R~
//    {                                                            //~2915R~
//        Spwxei->WXEIcsrchangesw=1;                               //~2915R~
//        Spwxei->WXEIcsrdbcssw=dbcssw;                            //~2915R~
//    }                                                            //~2915R~
//UTRACEP("Wxe_setcurpos:movesw=%d,old=(%d,%d),new=(%d,%d)\n",Spwxei->WXEIcsrmovesw,Spwxei->WXEIcsrposy,Spwxei->WXEIcsrposx,Prow,Pcol);//~v56gR~
	if (Prow!=Spwxei->WXEIcsrposy)                                 //~v440R~
    {                                                              //~v440I~
    	Spwxei->WXEIcsrmovesw=1;                                   //~v440R~
    	Spwxei->WXEIcsrposy=Prow;                                  //~v440R~
    }                                                              //~v440I~
	if (Pcol!=Spwxei->WXEIcsrposx)                                 //~v440R~
    {                                                              //~v440I~
    	Spwxei->WXEIcsrposx=Pcol;                                  //~v440R~
    	Spwxei->WXEIcsrmovesw=1;                                   //~v440R~
    }                                                              //~v440I~
  	if (Gwxestat & GWXES_KBDEVENT)	//for wxe_setcurpos            //~va7DI~
    	if (Spwxei->WXEIcsrmovesw)                                 //~va7DI~
    		Spwxei->WXEIcsrmovesw=2;                               //~va7DI~
	return 0;                                                      //~v440I~
}//wxe_setcurpos                                                   //~v440I~
//*************************************************************    //~v440I~
//*************************************************************    //~v440I~
int  wxe_getcurtype(void * /*PVIOCURSORINFO*/ pviocursorInfo)      //~v440I~
{                                                                  //~v440I~
	PVIOCURSORINFO pci;                                            //~v440I~
//***********************                                          //~v440I~
	pci=(PVIOCURSORINFO)pviocursorInfo;                            //~v440I~
//  pci->yStart=Spwxei->WXEIcsrhstart;                             //~v440I~//~vb2JR~
    pci->yStart=(USHORT)(Spwxei->WXEIcsrhstart);                   //~vb2JI~
//  pci->cEnd  =Spwxei->WXEIcsrhend;                               //~v440R~//~vb2JR~
    pci->cEnd  =(USHORT)(Spwxei->WXEIcsrhend);                     //~vb2JI~
    if (Spwxei->WXEIcsrvisible)                                    //~2914I~
	    pci->attr=0;  //0:normal,-1:hidden                         //~2914R~
    else                                                           //~2914I~
	    pci->attr=-1;  //0:normal,-1:hidden                        //~2914I~
	return 0;                                                      //~v440I~
}//wxe_getcurtype                                                  //~v440I~
//*************************************************************    //~v440I~
//*************************************************************    //~v440I~
int  wxe_setcurtype(void * /*PVIOCURSORINFO*/ pviocursorInfo)      //~v440I~
{                                                                  //~v440I~
	PVIOCURSORINFO pci;                                            //~v440I~
    int oldvisible,newvisible,oldstart,oldend;                     //~2914R~
//***********************                                          //~v440I~
	pci=(PVIOCURSORINFO)pviocursorInfo;                            //~2914M~
    oldvisible=Spwxei->WXEIcsrvisible;                             //~2914I~
    oldstart=Spwxei->WXEIcsrhstart;                                //~2914R~
    oldend=Spwxei->WXEIcsrhend;                                    //~2914R~
    newvisible=(pci->attr!=-1);  //0:normal,-1:hidden              //~2914I~
    if (oldstart!=pci->yStart||oldend!=pci->cEnd)                  //~2914M~
    {                                                              //~2914M~
    	Spwxei->WXEIcsrhstart=pci->yStart;                         //~2914M~
    	Spwxei->WXEIcsrhend  =pci->cEnd;                           //~2914M~
   	 	Spwxei->WXEIcsrchangesw=1;                                 //~2914M~
    }                                                              //~2914M~
    if (oldvisible!=newvisible)                                    //~2914I~
    {                                                              //~2914I~
    	Spwxei->WXEIcsrvisible=newvisible;  //0:normal,-1:hidden   //~2914I~
	    Spwxei->WXEIcsrvisiblechangesw=1;                          //~2914R~
    }                                                              //~2914I~
	return 0;                                                      //~v440I~
}//wxe_setcurtype                                                  //~v440I~
//*************************************************************    //~v440I~
//*************************************************************    //~v440I~
//int  wxe_uviogetwork(UCHAR *Pbuffc,USHORT *Pbuffa,UCHAR *Plineupdate)//~vb4iR~
int  wxe_uviogetwork(UCHAR *Pbuffc,USHORT *Pbuffa,UCHAR *Plineupdate,int *Plineopt)//~vb4iR~
{                                                                  //~v440I~
//***********************                                          //~v440I~
    Spwxei->WXEItext=Pbuffc;         //at uviogetwork              //~v440R~
    Spwxei->WXEIattr=Pbuffa;                                       //~v440R~
    Spwxei->WXEIlineupdate=Plineupdate;                            //~v440R~
    Spwxei->WXEIlineopt=Plineopt;                                  //~vb4iI~
	return 0;                                                      //~v440I~
}//wxe_uviogetwork                                                 //~v440I~
//*************************************************************    //~v440I~
//*************************************************************    //~v440I~
int  wxe_uviogetstate(void *Ppreqblk)                              //~v440I~
{                                                                  //~v440I~
static int S1stsw=0;                                               //~2A03I~
	int reqtype,ii,maxpal;                                         //~v440I~
	PVIOPALSTATE ppal;                                             //~v440I~
//***********************                                          //~v440I~
  	reqtype=(int)(*((short*)Ppreqblk+1));                          //~v440I~
	switch(reqtype)                                                //~v440I~
	{                                                              //~v440I~
	case 0:		//pallette reg get req                             //~v440I~
		ppal=Ppreqblk;                                             //~v440I~
		if (ppal->cb < sizeof(VIOPALSTATE)                         //~v440I~
		||  ppal->cb > sizeof(VIOPALSTATE)+15*2)                   //~v440I~
			return ERROR_VIO_INVALID_LENGTH;                       //~v440I~
		if (ppal->iFirst >= MAXCOLOR)                              //~2901R~
			return ERROR_VIO_INVALID_PARMS;                        //~v440I~
        maxpal=(ppal->cb-sizeof(VIOPALSTATE))/2+1;                 //~v440I~
         if ((maxpal+ppal->iFirst) > MAXCOLOR)                     //~2901R~
            return ERROR_VIO_INVALID_PARMS;                        //~v440I~
        if (!S1stsw)	//return default color at init             //~2A03I~
        {                                                          //~2A03I~
        	S1stsw=1;                                              //~2A03I~
            for (ii=0;ii<MAXCOLOR;ii++)                            //~2A03I~
                Spwxei->WXEIpallette[ii]=Gdefpallette[ii];         //~2A03I~
        }                                                          //~2A03I~
		for (ii=0;ii<maxpal;ii++)                                  //~v440R~
			ppal->acolor[ii]=Spwxei->WXEIpallette[ii];             //~2905R~
		break;                                                     //~v440I~
	default:                                                       //~v440I~
		return ERROR_VIO_INVALID_PARMS;                            //~v440I~
	}//switch by reqtype                                           //~v440I~
	return 0;                                                      //~v440I~
}//wxe_uviogetstate                                                //~v440I~
//*************************************************************    //~v440I~
//*************************************************************    //~v440I~
int  wxe_uviosetstate(void *Ppreqblk)                              //~v440I~
{                                                                  //~v440I~
	int reqtype,ii,maxpal;                                         //~v440I~
    UINT colno;                                                    //~2905R~
	PVIOPALSTATE  ppal;                                            //~v440I~
//***********************                                          //~v440I~
    reqtype=(int)(*((short*)Ppreqblk+1));                          //~v440I~
    switch(reqtype)                                                //~v440I~
    {                                                              //~v440I~
    case 0:     //pallette reg set req                             //~v440I~
        ppal=Ppreqblk;                                             //~v440I~
        if (ppal->cb < sizeof(VIOPALSTATE)                         //~v440I~
        ||  ppal->cb > sizeof(VIOPALSTATE)+15*2)                   //~v440I~
            return ERROR_VIO_INVALID_LENGTH;                       //~v440I~
        if (ppal->iFirst > MAXCOLOR)                               //~2901R~
            return ERROR_VIO_INVALID_PARMS;                        //~v440I~
        maxpal=(ppal->cb-sizeof(VIOPALSTATE))/2+1;                 //~v440I~
        if ((maxpal+ppal->iFirst) > MAXCOLOR)                      //~2901R~
            return ERROR_VIO_INVALID_PARMS;                        //~v440I~
        for (ii=0;ii<maxpal;ii++)                                  //~v440I~
        {                                                          //~2905I~
    		colno=(UINT)ppal->acolor[ii];   //color reg of the pallette//~2905R~
    		Spwxei->WXEIpallette[ii]=(SHORT)colno;                 //~2905I~
    		Spwxei->WXEIpalrgb[ii]=XE2RGB(colno);                  //~2905I~
        }                                                          //~2905I~
        break;                                                     //~v440I~
	case 2:		//brink or highlight background                    //~v440I~
    	break;	//ignore request                                   //~v440I~
    default:                                                       //~v440I~
        return ERROR_VIO_INVALID_PARMS;                            //~v440I~
    }//switch by reqtype                                           //~v440I~
	return 0;                                                      //~v440I~
}//wxe_uviosetstate                                                //~v440I~
////*************************************************************  //~2905R~
////*************************************************************  //~2905R~
//int  wxe_scrsetsplit(int Pvsplitsw,void * /*PUCLIENTWE*/ Ppcw1,void * /*PUCLIENTWE*/ Ppcw2)//~2905R~
//{                                                                //~2905R~
//    int palno;                                                   //~2905R~
////***********************                                        //~2905R~
//    Spwxei->WXEIvsplitsw=Pvsplitsw;                              //~2905R~
//    if (Pvsplitsw)                                               //~2905R~
//        Spwxei->WXEIsplitpos=Gscrsplitv;        //col            //~2905R~
//    else                                                         //~2905R~
//        Spwxei->WXEIsplitpos=Gscrsplith;        //row            //~2905R~
//    palno=wxegetbg((PUCLIENTWE)Ppcw1);                           //~2905R~
//    Spwxei->WXEIscrbg[0]=Spwxei->WXEIpallette[palno];            //~2905R~
//    if (Ppcw2)                                                   //~2905R~
//    {                                                            //~2905R~
//        palno=wxegetbg((PUCLIENTWE)Ppcw2);                       //~2905R~
//        Spwxei->WXEIscrbg[1]=Spwxei->WXEIpallette[palno];        //~2905R~
//    }                                                            //~2905R~
//    return 0;                                                    //~2905R~
//}//wxe_scrsetsplit                                               //~2905R~
////*************************************************************  //~2905R~
////*************************************************************  //~2905R~
//int  wxegetbg(PUCLIENTWE Ppcw)                                   //~2905R~
//{                                                                //~2905R~
//    int bgpal=0,scrtype;                                         //~2905R~
//    PUFILEC pfc;                                                 //~2905R~
////***********************                                        //~2905R~
//    pfc=Ppcw->UCWpfc;                                            //~2905R~
//    scrtype=Ppcw->UCWtype;                                       //~2905R~
//    switch(scrtype)                                              //~2905R~
//    {                                                            //~2905R~
//    case UCWTMENU:                                               //~2905R~
//        bgpal=Gattrtbl[COLOR_FRAME]>>4;                          //~2905R~
//        break;                                                   //~2905R~
//    case UCWTFILE:                                               //~2905R~
//        if (Ppcw->UCWmenuopt==PANMOCMD)                          //~2905R~
//            bgpal=Gattrtbl[COLOR_CCLIENT]>>4;                    //~2905R~
//        else                                                     //~2905R~
//            if (UCBITCHK(pfc->UFCflag,UFCFBROWSE))               //~2905R~
//                bgpal=Gattrtbl[COLOR_BCLIENT]>>4;                //~2905R~
//            else                                                 //~2905R~
//                bgpal=Gattrtbl[COLOR_ECLIENT]>>4;                //~2905R~
//        break;                                                   //~2905R~
//    case UCWTDIR:                                                //~2905R~
//        bgpal=Gattrtbl[COLOR_DCLIENT]>>4;                        //~2905R~
//        break;                                                   //~2905R~
//    }                                                            //~2905R~
//    return bgpal;                                                //~2905R~
//}//wxegetbng                                                     //~2905R~
//*************************************************************    //~v440I~
//*************************************************************    //~v440I~
int  wxe_readkbd(void * /*PINPUT_RECORD*/ Pinprec,int *Polen)      //~2901R~
{                                                                  //~v440I~
//***********************                                          //~v440I~
    *Polen=(Sinprec.EventType==KEY_EVENT);                         //~3119M~
	if (Sdbcssw==2)                                                //~2910I~
    {                                                              //~2910I~
    	Sdbcssw=1;                                                 //~2910I~
		memcpy(Pinprec,&Sinprec_dbcs1st,sizeof(INPUT_RECORD));     //~2910R~
        return 1;                                                  //~2910I~
    }                                                              //~2910I~
    else                                                           //~2910I~
    {                                                              //~2910I~
    	Sdbcssw=0;                                                 //~2910I~
		memcpy(Pinprec,&Sinprec,sizeof(INPUT_RECORD));             //~2910I~
    }                                                              //~2910I~
UTRACEP("vchar=%02x,ascii=%02x,scan=%02x\n",                       //~2921M~
    			Sinprec.Event.KeyEvent.wVirtualKeyCode,            //~2921M~
			    Sinprec.Event.KeyEvent.uChar.AsciiChar,            //~2921M~
    			Sinprec.Event.KeyEvent.wVirtualScanCode);          //~2921M~
	memset(&Sinprec,0,sizeof(INPUT_RECORD));	//clear after read //~2908R~
	return 0;                                                      //~v440I~
}//wxe_readkbd                                                     //~v440I~
//*************************************************************    //~v440I~
//*************************************************************    //~v440I~
int  wxe_peekkbd(void * /*PINPUT_RECORD*/ Pinprec,int *Poutctr)    //~2901R~
{                                                                  //~v440I~
//***********************                                          //~v440I~
	memcpy(Pinprec,&Sinprec,sizeof(INPUT_RECORD));                 //~2901R~
    *Poutctr=(Sinprec.EventType==KEY_EVENT);                       //~2901R~
	return 0;                                                      //~v440I~
}//wxe_peekkbd                                                     //~v440I~
//*************************************************************    //~v440I~
//*************************************************************    //~v440I~
int  wxe_geteventno(DWORD *Ppeventno)                                //~v440I~//~vaa3R~
{                                                                  //~v440I~
//***********************                                          //~v440I~
	*Ppeventno=0;                                                  //~vaa3I~
	return 0;                                                      //~v440I~
}//wxe_geteventno                                                  //~v440I~
//*************************************************************    //~v440I~
char *wxe_uerrmsg(char *Pemsg ,char *Pjmsg,... )                   //~v71sI~
{                                                                  //~v71sI~
//  unsigned long **parm;                                          //~v71sI~//~vafkR~
 	ULPTR parm[UERRMSG_MAXPARM];                                   //~vafkI~
	char *pmsg;                                                    //~v71sI~
//****************************                                     //~v71sI~
    UTRACEP("%s:emsg=%s\n",UTT,Pemsg);                             //~vbD6I~
//  parm=(unsigned long**)(ULONG)((&Pjmsg)+1);                     //~v71sI~//~vafkR~
    UGETSTDARG(ULPTR,parm,Pjmsg,UERRMSG_MAXPARM);                  //~vafkI~
	pmsg=uerrmsg(Pemsg,Pjmsg,parm[0],parm[1],parm[2],parm[3],parm[4],//~v71sI~
	             parm[5],parm[6],parm[7],parm[8],parm[9]);         //~v71sI~
     scrdisp();          //ist screen                              //~v71sI~
	return pmsg;                                                   //~v71sI~
}//wxe_uerrmsg                                                     //~v71sI~
//*************************************************************    //~v440I~
int  wxe_uerrmsgstdo(char *Ppmsg)                                  //~v440I~
{                                                                  //~v440I~
//***********************                                          //~v440I~
    UTRACEP("%s:pemsg=%s\n",UTT,Ppmsg);                            //~vbD6I~
//  if (Sxeinitsw==WXE_REQ_INIT)	//init end                     //~2B30I~//~v7ahR~
    if (Sxeinitsw==WXE_REQ_PREINIT)	//before init end              //~v7ahI~
		Spwxei->WXEIerrmsg=wxeenqmsg(Ppmsg,Spwxei->WXEIerrmsg);    //~2A07R~
    else                                                           //~2B30I~
    if (Sxeinitsw!=WXE_REQ_TERM)	//not title msg                //~v7ahI~
//  	umsgbox(Ppmsg);                                            //~v66AR~
    	umsgbox(Ppmsg,MB_OK);                                      //~v66AI~
	return 0;                                                      //~v440I~
}//wxe_uerrmsgstdo                                                 //~v440I~
//*************************************************************    //~v440I~
//*************************************************************    //~v440I~
int  wxe_uerrexitstdo(char *Ppmsg)                                 //~v440I~
{                                                                  //~v440I~
//***********************                                          //~v440I~
//  umsgbox(Ppmsg);                                                //~v66AR~
    umsgbox(Ppmsg,MB_OK);                                          //~v66AI~
	exit(24);                                                      //~2901R~
}//wxe_uerrexitstdo                                                //~v440I~
//*************************************************************    //~v440I~
//*************************************************************    //~v440I~
char *wxeenqmsg(char *Ppmsg,char *Ppprevmsg)                       //~2A07R~
{                                                                  //~v440I~
	UINT len1,len2;                                                //~v440I~
    char *newmsg;                                                  //~2A07R~
//***********************                                          //~v440I~
	if (Ppprevmsg)                                                 //~2A07R~
    	len2=strlen(Ppprevmsg);                                    //~2A07R~
    else                                                           //~v440I~
    	len2=0;                                                    //~2901M~
	len1=strlen(Ppmsg);                                            //~v440I~
    newmsg=malloc(len1+1+len2+2);                                  //~v440I~
    if (len2 && Ppprevmsg)                                         //~2A07R~
    {                                                              //~v440I~
    	memcpy(newmsg,Ppprevmsg,len2);                             //~2A07R~
        if (*(newmsg+len2-1)!='\n')                                //~2A07I~
    		*(newmsg+len2++)='\n';                                 //~2A07R~
        free(Ppprevmsg);                                           //~2A07R~
    }                                                              //~v440I~
    memcpy(newmsg+len2,Ppmsg,len1);                                //~v440I~
    len1=len2+len1;                                                //~v440I~
//  *(newmsg+len1++)='\n';                                         //~v440I~//~vbt9R~
    *(newmsg+len1++)=0;                                            //~v440I~
	return newmsg;                                                 //~2A07R~
}//wxeenqmsg                                                       //~v440I~
//*************************************************************    //~2928I~
//*tell charset changed                                            //~2928I~
//*ret 1:cp changed                                                //~2929I~
//*************************************************************    //~2928I~
int  wxe_setcharset(int Pinitsw,int Pcharset)                      //~2928R~
{                                                                  //~2928I~
	int jmode;                                                     //~v53nR~
    static int Soldsw932=0;                                        //~2928I~
    PUCLIENTWE pcw;                                                //~v53zI~
//***********************                                          //~2928I~
//  oldsw932=Gwxestat;                                             //~v53nR~
	if (Pcharset==DEFAULT_CHARSET)                                 //~v71BI~
    {                                                              //~v71BI~
		if (ugetcp()==932)                                         //~v71BI~
        {                                                          //~v71BI~
	    	Gwxestat|=GWXES_CP932;                                 //~v71BI~
    	    jmode=1;                                               //~v71BI~
        }                                                          //~v71BI~
        else                                                       //~v71BI~
	    {                                                          //~v71BI~
    		Gwxestat&=~GWXES_CP932;                                //~v71BI~
    		jmode=0;                                               //~v71BI~
    	}                                                          //~v71BI~
    }                                                              //~v71BI~
    else                                                           //~v71BI~
//  if (Pcharset!=ANSI_CHARSET)                                    //~2928R~//~va75R~
    if (Pcharset==SHIFTJIS_CHARSET)                                //~va75R~
    {                                                              //~2928I~
    	Gwxestat|=GWXES_CP932;                                     //~2928I~
        jmode=1;                                                   //~2929R~
    }                                                              //~2928I~
    else                                                           //~2928I~
    {                                                              //~2928I~
    	Gwxestat&=~GWXES_CP932;                                    //~2928I~
    	jmode=0;                                                   //~2929R~
    }                                                              //~2928I~
    if (Pinitsw)                                                   //~2928I~
    {                                                              //~v53nI~
        Soldsw932=jmode;                                           //~v53nI~
    	gblcpchng(jmode);                                          //~v53oI~
    	return 0;	//initial call before xe init call             //~2928I~
    }                                                              //~v53nI~
//  if (oldsw932==Gwxestat)                                        //~v53nR~
    if (Soldsw932==jmode)                                          //~v53nR~
    	return 0;                                                  //~2928I~
    Soldsw932=jmode;                                               //~v53nI~
    gblcpchng(jmode);                                              //~2929R~
//full re-draw screen                                              //~v53zI~
	pcw=scrgetcw(0);	//active client                            //~v53zI~
	scrfulldraw(pcw);   //full draw also inactive pcw              //~v53zI~
	scrdisp();                                                     //~v53zI~
    return 1;                                                      //~2928I~
}//wxe_setcharset                                                  //~2928I~
//*************************************************************    //~2929I~
//*tell charset changed                                            //~2929I~
//*ret 1:cp changed                                                //~2929I~
//*************************************************************    //~2929I~
int  wxe_setcsrpos(int Prow,int Pcol)                              //~2929I~
{                                                                  //~2929I~
//***********************                                          //~2929I~
	return scrsetcsrpos(Prow,Pcol);                                //~2929I~
}//wxe_setcsrpos                                                   //~2929I~
//*************************************************************    //~2929I~
//*tell charset changed                                            //~2929I~
//*ret 1:active changed                                            //~2929I~
//*************************************************************    //~2929I~
int  wxe_movecsr(int Prow,int Pcol)                                //~2929R~
{                                                                  //~2929I~
	int  rc;                                                       //~2929R~
//***********************                                          //~2929I~
    Gkbdinpctr++;		//tc cmd block specification is continued alt+f7 key.avoid it.//~v5a0M~
	rc=scrsetcsrpos(Prow,Pcol);	//1 if inactive pcw                //~2929R~
	scrdisp();                                                     //~2929R~
    return rc;                                                     //~2929R~
}//wxe_movecsr                                                     //~2929R~
//*************************************************************    //~2A13I~
//*scroll by mouse wheel                                           //~2A13I~
//*flag:shift key conbination                                      //~2A13I~
//*dest:wheel destination(forward if <0)                           //~2A13I~
//*ret 1:reached to EOF                                            //~v58iR~
//*************************************************************    //~2A13I~
int  wxe_scroll(int Pscrollctr,int Pflag,int Pdest)                //~2A13R~
{                                                                  //~2A13I~
	PUCLIENTWE pcw;                                                //~v55bI~
	int  rc,funcid,/*oldrow,oldcol,*/shiftsw,ctrlsw;               //~v76nR~
    int scrtype;                                                   //~v55bI~
    int oldmaxline;                                                //~v58iI~
    char cmdparm[16];                                              //~2A20I~
//***********************                                          //~2A13I~
    oldmaxline=0;  //set when file/dir scroll down                 //~v58iI~
	shiftsw=(Pflag & MK_SHIFT);      	//with shift key           //~2A20I~
	ctrlsw=(Pflag & MK_CONTROL);        //with control key         //~2A20I~
//  oldrow=Gcsrposy;                                               //~v76nR~
//  oldcol=Gcsrposx;                                               //~v76nR~
    *cmdparm=0;                                                    //~2A20I~
    pcw=scrgetcw(0); 	//current active                           //~v55bR~
//  if (pcw->UCWtype==UCWTFILE||pcw->UCWtype==UCWTDIR)             //~v69jR~
    if (pcw->UCWtype==UCWTFILE)                                    //~v69jI~
        scrtype=2;                                                 //~v55bI~
    else		//menu                                             //~v69jI~
    if (pcw->UCWtype==UCWTDIR)                                     //~v69jI~
        scrtype=1;      //virtical only                            //~v69jI~
    else		//menu                                             //~v55bI~
		if (((PUPANELC)pcw->UCWppc)->UPCid==PANFNAME)              //~v55bR~
	        scrtype=1;                                             //~v55bI~
        else                                                       //~v55bI~
	        scrtype=0;                                             //~v55bI~
//  if (shiftsw)  //shift                                          //~v69hR~
    if (ctrlsw)  //control+wheel                                   //~v69hI~
    {                                                              //~2A13I~
//  	if (scrtype!=2)	//file/dir only                            //~v69jR~
    	if (!scrtype)	//file/dir only                            //~v69jI~
        	return 0;                                              //~v55bI~
		if (Pdest<0)	//forward                                  //~2A13I~
        	funcid=FUNCID_BOTTOM;		//file end                 //~2A13M~
        else                                                       //~2A13I~
        	funcid=FUNCID_TOP;          //file top page            //~2A13M~
    }                                                              //~2A13I~
    else                                                           //~2A13I~
//  if (ctrlsw)  //with control                                    //~v69hR~
    if (shiftsw)  //shift+wheel                                    //~v69hI~
    {                                                              //~2A20I~
    	if (scrtype!=2)	//file/dir only                            //~v55bI~
        	return 0;                                              //~v55bI~
        sprintf(cmdparm,"%d",Pscrollctr);                          //~v69mR~
		if (Pdest<0)	//forward                                  //~2A20I~
        	funcid=FUNCID_PGRIGHT;                                 //~2A20I~
        else                                                       //~2A20I~
        	funcid=FUNCID_PGLEFT;                                  //~2A20I~
    }                                                              //~2A20I~
    else                                                           //~2A20I~
    {                                                              //~2A13I~
    	if (!scrtype)	//file/dir/filelist only                   //~v55bI~
        	return 0;                                              //~v55bI~
        sprintf(cmdparm,"%d",Pscrollctr);                          //~v69mR~
		if (Pdest<0)	//forward                                  //~2A13I~
        {                                                          //~v58iI~
        	funcid=FUNCID_PGDN;                                    //~2A20R~
		    if (scrtype==2) //dir/file                             //~v58iI~
            	if (pcw->UCWmaxline==pcw->UCWheight)               //~v58iI~
	        	    oldmaxline=pcw->UCWmaxline; //save maxline before scroll//~v58iI~
        }                                                          //~v58iI~
        else                                                       //~2A13I~
        	funcid=FUNCID_PGUP;                                    //~2A20R~
    }                                                              //~2A13I~
    Gwxestat|=GWXES_SCROLLBYMOUSE; //tell to getscrollsz it is scroll by mouse//~v69mI~
	Gwxescrollctr=Pscrollctr;                                      //~v69mI~
//  rc=wxe_funccall(funcid,cmdparm);                               //~v69mR~
    rc=wxe_funccall(-funcid,cmdparm);                              //~v69mI~
    if (!rc)                                                       //~v58iI~
	    if (oldmaxline && pcw->UCWmaxline<pcw->UCWheight)          //~v58iI~
    		rc=1;                                                  //~v58iI~
//  wxe_movecsr(oldrow,oldcol);                                    //~v76nR~
    return rc;                                                     //~2A13I~
}//wxe_scroll                                                      //~2A13I~
#ifdef AAA  //logic use scrollock on and left/right key simulation //~v69gM~
//*************************************************************    //~v69bI~
//*horizontal scroll by mouse(detected vk_left/right after scrolllock up in short time//~v69bI~
//*************************************************************    //~v69bI~
void wxe_scrollh(int Pscrollctr,UINT nChar)                        //~v69bI~
{                                                                  //~v69bI~
//***********************                                          //~v69bI~
	if (Pscrollctr)                                                //~v69bI~
    {                                                              //~v69bI~
	    Gwxescrollctr=Pscrollctr;                                  //~v69bR~
		Gwxestat|=GWXES_MOUSEHSCROLL;    	//horizontal scroll by mouse//~v69bR~
	}                                                              //~v69bI~
    else                                                           //~v69bI~
		Gwxestat&=~GWXES_MOUSEHSCROLL;    	//horizontal scroll by mouse//~v69bI~
    return;                                                        //~v69bI~
}//wxe_scrollh                                                     //~v69bI~
//*************************************************************    //~v69gI~
//*horizontal scroll by mouse WM_HSCROLL msg                       //~v69gR~
//*************************************************************    //~v69gI~
int wxe_scrollhbar(int Pscrollctr,int Pdest)                       //~v69gI~
{                                                                  //~v69gI~
	UINT vkey;                                                     //~v69gI~
	int flags=ENHANCED_KEY,rc,opt;                                 //~v69gR~
//***********************                                          //~v69gI~
	if (Pdest<0)                                                   //~v69gI~
    {                                                              //~v69gI~
    	vkey=VK_LEFT;                                              //~v69gI~
        flags|=(KEY_LEFT>>8);	//scancode                         //~v69gI~
    }                                                              //~v69gI~
    else                                                           //~v69gI~
    {                                                              //~v69gI~
    	vkey=VK_RIGHT;                                             //~v69gI~
        flags|=(KEY_RIGHT>>8);	//scancode                         //~v69gI~
    }                                                              //~v69gI~
	wxe_scrollh(Pscrollctr,vkey);                                  //~v69gI~
    opt=WXEKBDMSG_KEYDOWN|WXEKBDMSG_SCROLLLOCKON;	//scrolllock flag is for xecsr.c//~v69gI~
    rc=wxe_kbdmsg(opt,vkey,1,flags);//1:repcnt                     //~v69gR~
	wxe_scrollh(0,vkey);		//reset flag of hscroll by mouse   //~v69gI~
    return rc;                                                     //~v69gI~
}//wxe_scrollhbar                                                  //~v69gI~
#else          //logic to use pgleft/pgright cmd                   //~v69gI~
//*************************************************************    //~v69gI~
//*horizontal scroll by mouse WM_HSCROLL msg                       //~v69gI~
//*************************************************************    //~v69gI~
int wxe_scrollhbar(int Pscrollctr,int Pdest)                       //~v69gI~
{                                                                  //~v69gI~
	PUCLIENTWE pcw;                                                //~v69gI~
	int  rc,funcid,oldrow,oldcol;                                  //~v69gI~
    char cmdparm[16];                                              //~v69gI~
//***********************                                          //~v69gI~
UTRACEP("wxe_scrollhbar ctr=%d,dest=%d\n",Pscrollctr,Pdest);       //~v69gR~
    oldrow=Gcsrposy;                                               //~v69gI~
    oldcol=Gcsrposx;                                               //~v69gI~
    *cmdparm=0;                                                    //~v69gI~
    pcw=scrgetcw(0); 	//current active                           //~v69gI~
    if (pcw->UCWtype!=UCWTFILE)                                    //~v69gI~
        return 0;                                                  //~v69gI~
    sprintf(cmdparm,"%d",Pscrollctr);                              //~v69mR~
	if (Pdest<0)	//left                                         //~v69gI~
        funcid=FUNCID_PGLEFT;                                      //~v69gI~
    else                                                           //~v69gI~
        funcid=FUNCID_PGRIGHT;                                     //~v69gI~
    Gwxestat|=GWXES_SCROLLBYMOUSE; //tell to getscrollsz it is scroll by mouse//~v69mI~
	Gwxescrollctr=Pscrollctr;                                      //~v69mI~
//  rc=wxe_funccall(funcid,cmdparm);                               //~v69mR~
    rc=wxe_funccall(-funcid,cmdparm);                              //~v69mI~
	wxe_movecsr(oldrow,oldcol);                                    //~v69gI~
    return rc;                                                     //~v69gI~
}//wxe_scrollhbar                                                  //~v69gI~
#endif                                                             //~v69gI~
//*************************************************************    //~v5a0I~
//*mouse position chk for auto scroll                              //~v5a0I~
//*ret :1:left,2:right,4:top,8:bottom,0:other                      //~v5a0I~
//*************************************************************    //~v5a0I~
int  wxe_mouseedgechk(int Pcol,int Prow)                           //~v5a0I~
{                                                                  //~v5a0I~
    PUCLIENTWE pcw;                                                //~v5a0I~
    PUFILEC    pfc;                                                //~v5a0I~
    PUFILEH    pfh;                                                //~v53bI~
    PULINEH    plh;                                                //~v5a0I~
    PULINEH    plhtop,plhend;                                      //~v53bI~
    int posid=0,col,row;                                           //~v5a0I~
//***********************                                          //~v5a0I~
    scrcpgetpcw(Prow,Pcol,&pcw);                                   //~v5a0I~
    if (pcw->UCWtype==UCWTFILE||pcw->UCWtype==UCWTDIR)             //~v5a0I~
    {                                                              //~v5a0I~
	    pfc=pcw->UCWpfc;                                           //~v5a0R~
	    pfh=pfc->UFCpfh;                                           //~v53bI~
    	col=Pcol-pcw->UCWorgx;                                     //~v5a0I~
    	row=Prow-pcw->UCWorgy;                                     //~v5a0I~
//row                                                              //~v5a0I~
        if (row==pcw->UCWfilehdrlineno)                            //~v5a0I~
        {                                                          //~v53bI~
            plhtop=UGETQTOP(&pfh->UFHlineque);                     //~v53bI~
          if (pfc->UFCcurtop!=plhtop)                              //~v53bI~
            posid|=MEC_TOP;       //pgup                           //~v5a0R~
        }                                                          //~v53bI~
        else                                                       //~v5a0I~
//  	if (row>=pcw->UCWmaxline-1)                                //~v53aR~
    	if (row==pcw->UCWheight-1)                                 //~v53aI~
        {                                                          //~v53bI~
            plhend=UGETQEND(&pfh->UFHlineque);                     //~v53bI~
          if (pfc->UFCcurtop!=plhend)                              //~v53bI~
            posid|=MEC_BOTTOM;       //pgdn                        //~v5a0R~
        }                                                          //~v53bI~
//col                                                              //~v5a0I~
    	if (pcw->UCWtype==UCWTFILE)                                //~v5a0I~
            if (row>=pcw->UCWfilehdrlineno)                        //~v5a0R~
//              if (col<=pcw->UCWlinenosz)                         //~v53bR~
                if (col==pcw->UCWlinenosz)                         //~v53bI~
                {                                                  //~v53bI~
                  if (pfc->UFCleft) //scrollable                   //~v53bI~
                    posid|=MEC_LEFT;                               //~v5a0R~
                }                                                  //~v53bI~
                else                                               //~v5a0R~
                if (col==pcw->UCWwidth-1)                          //~v5a0R~
                    posid|=MEC_RIGHT;                              //~v5a0R~
        if ((posid & MEC_TOP) && (posid & (MEC_LEFT|MEC_RIGHT)))   //~v5a0I~
        {                                                          //~v5a0I~
			plh=pfc->UFCcurtop;						//top line to be display//~v5a0I~
            if (!UGETQPREV(plh))                                   //~v5a0I~
		        posid &=~MEC_TOP;		//avoid bell               //~v5a0R~
        }                                                          //~v5a0I~
        if ((posid & MEC_LEFT) && (posid & (MEC_TOP|MEC_BOTTOM)))  //~v5a0I~
        {                                                          //~v5a0I~
            if (!pfc->UFCleft)		//left most                    //~v5a0I~
		        posid &=~MEC_LEFT;		//avoid bell               //~v5a0R~
        }                                                          //~v5a0I~
    }                                                              //~v5a0I~
    return posid;                                                  //~v5a0I~
}//wxe_mouseedgechk                                                //~v5a0I~
//*************************************************************    //~3102I~
//*line select by dbl click                                        //~3102I~
//*flag:shift key conbination                                      //~3102I~
//*ret 1:event processed,0:none of mine(do default action)         //~3102I~
//*************************************************************    //~3102I~
int  wxe_lineselect(UINT Pflag,int Prow,int Pcol,int *Ppcapinfo)   //~v5a0R~
{                                                                  //~3102I~
	int  rc=0,shiftsw,pcid,row,col,funcid;                         //~v5a0R~
    PUCLIENTWE pcw;                                                //~3102I~
//***********************                                          //~3102I~
	*Ppcapinfo=0;                                                  //~v5a0I~
	shiftsw=(Pflag & MK_SHIFT);      	//with shift key           //~3102I~
    scrcpgetpcw(Prow,Pcol,&pcw);                                   //~3102I~
	pcid=((PUPANELC)pcw->UCWppc)->UPCid;                           //~3102I~
    row=Prow-pcw->UCWorgy;                                         //~3102R~
    col=Pcol-pcw->UCWorgx;                                         //~v5a0I~
    if (!row)           //hdr line                                 //~3115I~
    {                                                              //~3115I~
        if (shiftsw)                                               //~3115R~
            funcid=FUNCID_CANCEL;                                  //~3115I~
        else                                                       //~3115I~
            funcid=FUNCID_END;                                     //~3115I~
        rc=wxe_funccall(funcid,"");                                //~3115I~
        if (rc==-1)                                                //~3115I~
        	return -1;                                             //~3115I~
        return 1;                                                  //~3115I~
    }                                                              //~3115I~
	switch(pcid)                                                   //~3102I~
    {                                                              //~3102I~
	case PANTOPMENU:                                               //~3102I~
		rc=wxe_lineselect_topmenu(pcw,shiftsw,row);                //~3102R~
		break;                                                     //~3102I~
	case PANFNAME  :		//filename                             //~3102I~
//  	rc=wxe_lineselect_fnamelist(pcw,shiftsw,row);              //~v56aR~
    	rc=wxe_lineselect_fnamelist(pcw,shiftsw,row,col);          //~v56aR~
		break;                                                     //~3102I~
	case PANDIR   :		//dir list                                 //~3102I~
//  	rc=wxe_lineselect_dirlist(pcw,shiftsw,row);                //~v56aR~
    	rc=wxe_lineselect_dirlist(pcw,shiftsw,row,col);            //~v56aR~
		break;                                                     //~3102I~
    case PANFBROWSE:                                               //~3104R~
    case PANFEDIT:                                                 //~3104I~
		rc=wxe_lineselect_file(pcw,Pflag,row,col,Ppcapinfo);       //~v5a0R~
		break;                                                     //~3104I~
//  default:;   //PANOPTCOLOR                                      //~3115R~
    }                                                              //~3102I~
    return rc;                                                     //~3115R~
}//wxe_lineselect                                                  //~3102I~
//*************************************************************    //~3102I~
//*top menu line select                                            //~3102I~
//*************************************************************    //~3102I~
int  wxe_lineselect_topmenu(PUCLIENTWE Ppcw,int Pshiftsw,int Prow) //~3102R~
{                                                                  //~3102I~
    int cmdid=0,rc;                                                //~3102R~
//**********************                                           //~3102I~
	switch(Prow)                                                   //~3102I~
    {                                                              //~3102I~
//    case  3:                                                     //~vaa3R~
//    case  4:                                                     //~vaa3R~
	case PANL00PARM:	//   3 	//0:PARM                           //~vaa3I~
	case PANL00COLOR:	//   4 	//0.0 COLOR                        //~vaa3I~
    	cmdid='0';                                                 //~3102I~
        break;                                                     //~3102I~
//    case  5:                                                     //~vaa3R~
	case PANL00SCCMD:	//   5 	//0.1 SC-CMD                       //~vaa3I~
    	cmdid='A';                                                 //~3102I~
        break;                                                     //~3102I~
//    case  6:                                                     //~vaa3R~
	case PANL00F_K:  	//   6 	//0.2 FUNC-KEY                     //~vaa3I~
    	cmdid='B';                                                 //~3102I~
        break;                                                     //~3102I~
//    case  7:                                                     //~vaa3R~
	case PANL00K_F:  	//   7 	//0.3 KEY_FUNC                     //~vaa3I~
    	cmdid='C';                                                 //~3102I~
        break;                                                     //~3102I~
//    case  8:                                                     //~vaa3R~
	case PANL00BROWSE:	//  8 	//1 BROWSE                         //~vaa3I~
    	cmdid='1';                                                 //~3102I~
        break;                                                     //~3102I~
//    case  9:                                                     //~vaa3R~
	case PANL00EDIT:	//    9 	//2 EDIT                       //~vaa3I~
    	cmdid='2';                                                 //~3102I~
        break;                                                     //~3102I~
	case PANL00COMP:	//   11 	//3.12 COMPARE                 //~vaa3I~
    	cmdid='F';                                                 //~vaa3I~
        break;                                                     //~vaa3I~
	case PANL00SRCH:	//   12 	//3.14 SEARCH                  //~vaa3I~
    	cmdid='G';                                                 //~vaa3I~
        break;                                                     //~vaa3I~
//    case  10:                                                    //~vaa3R~
	case PANL00CMD:		//    13 	//6 CMD                        //~vaa3I~
    	cmdid='6';                                                 //~3102I~
        break;                                                     //~3102I~
//    case  11:                                                    //~vaa3R~
	case PANL00EXIT:	//   15 	//X EXIT                       //~vaa3I~
    	cmdid='X';                                                 //~3102I~
        break;                                                     //~3102I~
//    case  12:                                                    //~vaa3R~
	case PANL00RET: 	//   16 	//R RETURN                     //~vaa3I~
    	cmdid='R';                                                 //~3102I~
        break;                                                     //~3102I~
//    case  13:                                                    //~vaa3R~
	case PANL00QUIT:	//   17 	//Q QUIT                       //~vaa3I~
    	cmdid='Q';                                                 //~3102I~
        break;                                                     //~3102I~
    }                                                              //~3102I~
    if (!cmdid)                                                    //~3102I~
    	return 0;                                                  //~3102I~
	csronthefld(Ppcw,CMDLINENO,0,0);	//fldno=0,offset=0         //~3102I~
    wxe_kbdmsg(WXEKBDMSG_ONCHAR,cmdid,1,0);		//1:repeat,0:flag  //~3102I~
	rc=wxe_funccall(FUNCID_EXECNL,"");                             //~3102I~
    if (rc==-1)                                                    //~3115R~
    	return -1;                                                 //~3115R~
	return 1;	//-1:for exit                                      //~3115R~
}//wxe_lineselect_topmenu                                          //~3102I~
//*************************************************************    //~3102I~
//*filename list line select                                       //~3102I~
//*************************************************************    //~3102I~
//int  wxe_lineselect_fnamelist(PUCLIENTWE Ppcw,int Pshiftsw,int Prow)//~v56aR~
int  wxe_lineselect_fnamelist(PUCLIENTWE Ppcw,int Pshiftsw,int Prow,int Pcol)//~v56aR~
{                                                                  //~3102I~
//  FILEFINDBUF3 ffb3;                                             //~v56eR~
    UCHAR fnm[MAXCOLUMN];	                                       //~3102I~
	int assocsw;                                                   //~v55UI~
	int openbyxesw;                                                //~v56aR~
//  int rc;                                                        //~v56eR~
//  UCHAR fpath[_MAX_PATH],*pc;                                    //~v56eR~
//******************************                                   //~3102I~
    if (Prow==PANL300DRIVE||Prow==PANL300DIR||Prow==PANL300CURRENT)//~v54wR~
        return wxe_lineselect_driveid(Ppcw,Prow,Pshiftsw);         //~v54wR~
	if (!(Prow>=PANL300LISTTOP && Prow<Ppcw->UCWmaxline))          //~3102R~
    	return 0;                                                  //~3102I~
    getfldinput(Ppcw,Prow,PANL300NAME,fnm);                        //~3102I~
    if (!*fnm)		//not filled                                   //~3102I~
    	return 0;                                                  //~3102I~
	csronthefld(Ppcw,Prow,PANL300LCMD,0);	//1 if inactive pcw    //~3102I~
//  openbyxesw=(Pcol>=OPENBYXE_HLPOS1 && Pcol<=OPENBYXE_HLPOS2);   //~v56cR~
    openbyxesw=!(Pcol>=OPENBYXE_HLPOS1 && Pcol<=OPENBYXE_HLPOS2);  //~v56cI~
    assocsw=0;                                                     //~v55UI~
//    if (pan300getfnm(Ppcw->UCWrcsry+Ppcw->UCWtopfnlist,fpath))  //get stacked name over scr width//~v56eR~
//    {                                                            //~v56eR~
////    if (!Pshiftsw)                                             //~v56eR~
//      if (!openbyxesw)                                           //~v56eR~
//      {                                                          //~v56eR~
//        pc=umemrchr(fpath,'.',strlen(fpath));   //search extension//~v56eR~
//        if (pc)                                                  //~v56eR~
//        {                                                        //~v56eR~
//            rc=ufstat(fpath,&ffb3);                              //~v56eR~
//          if (!rc && !(ffb3.attrFile & FILE_DIRECTORY))          //~v56eR~
//            assocsw=uwinreg_chkassociation(pc);                  //~v56eR~
//        }                                                        //~v56eR~
//      }//without Shift key                                       //~v56eR~
//    }                                                            //~v56eR~
  	if (!openbyxesw)                                               //~v56eI~
		assocsw=dlcmdassocchk_fnamelist(Ppcw);                     //~v56eR~
  if (assocsw)                                                     //~v55UR~
	wxe_assoclcmd(Ppcw,Pshiftsw);                                  //~v55UI~
  else                                                             //~v55UI~
	wxe_belcmd(Ppcw,Pshiftsw);                                     //~3102I~
    return 1;                                                      //~3102I~
}//wxe_lineselect_fnamelist                                        //~3102I~
//*************************************************************    //~v54vI~
//*driveid selection                                               //~v54vI~
//*************************************************************    //~v54vI~
int  wxe_lineselect_driveid(PUCLIENTWE Ppcw,int Prow,int Pshiftsw) //~v54wR~
{                                                                  //~v54vI~
    int did;                                                       //~v54vR~
    char cmdnm[2],fnm[_MAX_PATH];                                  //~v54wR~
//******************************                                   //~v54vI~
  if (Prow==PANL300DRIVE)                                          //~v54wI~
  {                                                                //~v54wI~
    did=pan300drawdid(Ppcw);                                       //~v54vR~
    if (!did)                                                      //~v54vI~
        return 0;   //nothing occur                                //~v54vI~
//  fnm[0]=did;                                                    //~v54wM~//~vb2JR~
    fnm[0]=(char)did;                                              //~vb2JI~
    fnm[1]=':';                                                    //~v54wM~
    fnm[2]=0;                                                      //~v54wM~
  }                                                                //~v54wI~
  else                                                             //~v54wI~
  {                                                                //~v54wI~
    getfldinput(Ppcw,Prow,0,fnm);                                  //~v54wR~
    if (!*fnm)                                                     //~v54wI~
        return 0;   //nothing occur                                //~v54wI~
  }                                                                //~v54wI~
    if (Pshiftsw)   //reverse edit/browse                          //~v54wI~
        if (Ppcw->UCWmenuopt==PANMOBROWSE)                         //~v54wI~
            cmdnm[0]='e';                                          //~v54wI~
        else                                                       //~v54wI~
            cmdnm[0]='b';                                          //~v54wI~
    else                                                           //~v54wI~
        if (Ppcw->UCWmenuopt==PANMOBROWSE)                         //~v54wR~
            cmdnm[0]='b';                                          //~v54wR~
        else                                                       //~v54wR~
            cmdnm[0]='e';                                          //~v54wR~
    cmdnm[1]=0;                                                    //~v54vI~
	wxe_strcmd(cmdnm,fnm);                                         //~v54vI~
    return 1;                                                      //~v54vI~
}//wxe_lineselect_driveid                                          //~v54vI~
//*************************************************************    //~3104I~
//*browse/edit                                                     //~3115R~
//*p3/p4:relative pos                                              //~v5a0I~
//ret 1:cap copyed                                                 //~v5a0I~
//*************************************************************    //~3104I~
int  wxe_lineselect_file(PUCLIENTWE Ppcw,int Pflag,int Prow,int Pcol,int *Ppcapinfo)//~v5a0R~
{                                                                  //~3104I~
	int pos;                                                       //~v5a0R~
    char *pc;                                                      //~v5a0I~
	PUSCRD  psd;                                                   //~v5a0I~
    PULINEH plh;                                                   //~v5a0I~
    PUFILEC pfc;                                                   //~v5a0I~
//******************************                                   //~3104I~
	if (Prow==CMDLINENO)                                           //~v56jI~
    	return wxepathupdown(Ppcw,Pcol);                           //~v56jI~
    if (Prow<Ppcw->UCWfilehdrlineno || Prow>=Ppcw->UCWmaxline)     //~v5a0I~
	    return 0;                                                  //~v5a0R~
    pfc=Ppcw->UCWpfc;                                              //~v5a0I~
    psd=Ppcw->UCWpsd;                                              //~v5a0I~
    psd+=Prow;                                                     //~v5a0I~
    plh=psd->USDbuffc;                                             //~v5a0I~
    if (!plh)                                                      //~v5a0I~
    	return 0;                                                  //~v5a0I~
    if (plh->ULHtype==ULHTHDR)                                     //~v5a0I~
    	return 0;                                                  //~v5a0I~
    if (Pcol<(int)Ppcw->UCWlinenosz)	//lineno col;line mode     //~v5a0I~
        *Ppcapinfo=LSCI_LINE;		//line cap id                  //~v5a0I~
    else 		//cs is on file data                               //~v5a0I~
    {                                                              //~v5a0I~
    	pos=pfc->UFCleft+Pcol-Ppcw->UCWlinenosz;                   //~v5a0R~
    	pc=plh->ULHdata+pos;                                       //~v5a0R~
        if (pos<plh->ULHlen)                                       //~v5a0R~
        	*Ppcapinfo=LSCI_FIELD;      //line cap id              //~v5a0I~
    }                                                              //~v5a0I~
	return 0;                                                      //~v5a0I~
}//wxe_lineselect_file                                             //~3115R~
//*************************************************************    //~3102I~
//*top menu line select                                            //~3102I~
//*************************************************************    //~3102I~
//int  wxe_lineselect_dirlist(PUCLIENTWE Ppcw,int Pshiftsw,int Prow)//~v56aR~
int  wxe_lineselect_dirlist(PUCLIENTWE Ppcw,int Pshiftsw,int Prow,int Pcol)//~v56aR~
{                                                                  //~3102I~
//  PUDIRLH pdh;                                                   //~v56eR~
	int assocsw=0;                                                 //~v567R~
	int openbyxesw;                                                //~v56aR~
//  int rc;                                                        //~v56eR~
//  UCHAR fpath[_MAX_PATH],*pc;                                    //~v56eR~
//**********************************                               //~v55UI~
	if (Prow==CMDLINENO)                                           //~v56jI~
    	return wxepathupdown(Ppcw,Pcol);                           //~v56jI~
    if (!(Prow>=Ppcw->UCWfilehdrlineno && Prow<Ppcw->UCWmaxline))  //~3102R~
    	return 0;                                                  //~3102I~
//    openbyxesw=(Pcol>=OPENBYXE_DLPOS1 && Pcol<=OPENBYXE_DLPOS2); //~v56cR~
      openbyxesw=!(Pcol>=OPENBYXE_DLPOS1 && Pcol<=OPENBYXE_DLPOS2);//~v56cI~
	csronthefld(Ppcw,Prow,0,0);	//fldno=0,offs=0                   //~3102I~
//  if (dlcgetdirlistfname(Ppcw,fpath))                            //~v567R~
//  if (!dlcgetdirlistfname(Ppcw,fpath))                           //~v568R~
//    rc=dlcgetdirlistfname(Ppcw,fpath,&pdh);                      //~v56eR~
//    if (!rc && !(pdh->UDHattr & FILE_DIRECTORY))//not dirname    //~v56eR~
//    {                                                            //~v56eR~
////    if (!Pshiftsw)                                             //~v56eR~
//      if (!openbyxesw)                                           //~v56eR~
//      {                                                          //~v56eR~
//        pc=umemrchr(fpath,'.',strlen(fpath));   //search extension//~v56eR~
//        if (pc)                                                  //~v56eR~
//            assocsw=uwinreg_chkassociation(pc);                  //~v56eR~
//      }//without Shift key                                       //~v56eR~
//    }                                                            //~v56eR~
	if (!openbyxesw)                                               //~v56eI~
		assocsw=dlcmdassocchk_dirlist(Ppcw);                       //~v56eR~
  if (assocsw)                                                     //~v55UI~
	wxe_assoclcmd(Ppcw,Pshiftsw);                                  //~v55UI~
  else                                                             //~v55UI~
	wxe_belcmd(Ppcw,Pshiftsw);                                     //~3102I~
	wxe_funccall(FUNCID_EXECNL,"");                                //~3102I~
    return 1;                                                      //~3102I~
}//wxe_lineselect_dirlist                                          //~3102I~
//*************************************************************    //~3102I~
//*lcmd input                                                      //~3102I~
//*************************************************************    //~3102I~
int  wxe_belcmd(PUCLIENTWE Ppcw,int Pshiftsw)                      //~3102I~
{                                                                  //~3102I~
//	int lcmd,stat;                                                 //~v64mR~
	int lcmd,stat=0;                                               //~v64mI~
    PUFILEC pfc;                                                   //~v53xI~
//****************************                                     //~3102I~
	pfc=Ppcw->UCWpfc;                                              //~v53xI~
    if (Pshiftsw)   //reverse edit/browse                          //~3102I~
    {                                                              //~3102I~
    	stat=WXEKBDMSG_SHIFTKEY;                                   //~3102I~
    	if (Ppcw->UCWtype==UCWTDIR)                                //~v53xI~
			if (!UCBITCHK(pfc->UFCflag,UFCFDEDIT))   //dir list by edit cmd//~v53xI~
                lcmd='e';                                          //~v53xI~
            else                                                   //~v53xI~
                lcmd='b';                                          //~v53xI~
        else                                                       //~v53xI~
        if (Ppcw->UCWmenuopt==PANMOBROWSE)                         //~3102I~
            lcmd='e';                                              //~3102I~
        else                                                       //~3102I~
            lcmd='b';                                              //~3102I~
    }                                                              //~3102I~
    else                                                           //~3102I~
    {                                                              //~3102I~
    	if (Ppcw->UCWtype==UCWTDIR)                                //~v53xI~
			if (!UCBITCHK(pfc->UFCflag,UFCFDEDIT))   //dir list by edit cmd//~v53xI~
                lcmd='b';                                          //~v53xI~
            else                                                   //~v53xI~
                lcmd='e';                                          //~v53xI~
        else                                                       //~v53xI~
        if (Ppcw->UCWmenuopt==PANMOBROWSE)                         //~3102I~
            lcmd='b';                                              //~3102I~
        else                                                       //~3102I~
            lcmd='e';                                              //~3102I~
    }                                                              //~3102I~
    stat|=WXEKBDMSG_ONCHAR;                                        //~3102I~
    return wxe_kbdmsg(stat,lcmd,1,0);		//1:repeat,0:flag      //~3102R~
}//wxe_belcmd                                                      //~3102I~
//*************************************************************    //~v56jI~
//*lcmd input                                                      //~v56jI~
//*************************************************************    //~v56jI~
int  wxepathupdown(PUCLIENTWE Ppcw,int Pcol)                       //~v56jI~
{                                                                  //~v56jI~
	int funcid,width;                                              //~v56jR~
//****************************                                     //~v56jI~
	if (Pcol>=DPUCOLS && Pcol<=DPUCOLE)                            //~v56jI~
    	funcid=FUNCID_PATHUP;                                      //~v56jI~
    else                                                           //~v56jI~
    {                                                              //~v56jI~
    	width=Ppcw->UCWwidth;                                      //~v56jI~
        if (Pcol>=(width-DPDCOLS) && Pcol<=(width-DPDCOLE))        //~v56jR~
            funcid=FUNCID_PATHDOWN;                                //~v56jR~
        else                                                       //~v56jR~
            return 0;                                              //~v56jR~
    }                                                              //~v56jI~
	return wxe_funccall(funcid,"");                                //~v56jI~
}//wxepathupdown                                                   //~v56jI~
//*************************************************************    //~v69fI~
//*browser cmd by 5 button mouse                                   //~v69fI~
//*ret 1:event processed,0:do default window proc                  //~v69fI~
//*************************************************************    //~v69fI~
int  wxe_browsercmd(int Pcmdid)                                    //~v69fI~
{                                                                  //~v69fI~
	int  rc=FALSE,pcid,funcid;                                     //~v69fR~
    PUCLIENTWE pcw;                                                //~v69fI~
//***********************                                          //~v69fI~
	pcw=scrgetcw(0);	//active client                            //~v69fI~
	pcid=((PUPANELC)pcw->UCWppc)->UPCid;                           //~v69fI~
	switch(pcid)                                                   //~v69fI~
    {                                                              //~v69fI~
	case PANDIR   :		//dir list                                 //~v69fI~
    case PANFBROWSE:                                               //~v69fI~
    case PANFEDIT:                                                 //~v69fI~
    	if (Pcmdid<0)                                              //~v69fI~
	    	funcid=FUNCID_PATHUP;                                  //~v69fI~
        else                                                       //~v69fI~
            funcid=FUNCID_PATHDOWN;                                //~v69fI~
		wxe_funccall(funcid,"");                                   //~v69fI~
        rc=TRUE;                                                   //~v69fI~
    }                                                              //~v69fI~
    return rc;                                                     //~v69fI~
}//wxe_browsercmd                                                  //~v69fI~
//*************************************************************    //~v79zI~
int  wxe_kbdwcinit(int Popt,int Pkbdstat,int Pcodepage)            //~v79zR~
{                                                                  //~v79zI~
static int Spreinitstat=0;                                         //~v79zI~
//***********************                                          //~v79zI~
	if (!Popt)          //Spwxei is temporary when preinit         //~v79zI~
    {                                                              //~v79zI~
    	if (Pkbdstat & UDCWCIO_WIDEAPI)                            //~v79zR~
    		Spwxei->WXEIimestat|=WXEIIMES_WIDEAPI;                 //~v79zR~
		Spreinitstat=Spwxei->WXEIimestat;                          //~v79zI~
        return 0;                                                  //~v79zI~
    }                                                              //~v79zI~
	Spwxei->WXEIimestat=Spreinitstat;                              //~v79zI~
	return 0;                                                      //~v79zI~
}//wxe_kbdwcinit                                                   //~v79zI~
//===============================================================================//~va3kI~
//ligature allowance                                               //~va3kI~
//rc:0:csr is on dataline                                          //~va3kI~
//  :1:not file panel                                              //~va3kI~
//  :2:hhex/bin file                                               //~va3kI~
//  :-1:vhex1 hexline data                                         //~va3kI~
//  :-2:vhex2 hexline data                                         //~va3kI~
//  :3:not data line                                               //~va6qI~
//  :4:not on text area                                            //~va3kI~
//===============================================================================//~va3kI~
int xxe_chkcsrisfiledataline(int Popt,PUCLIENTWE Ppcw,int Prow,int Pcol,int *Ppinfo)//~va3kI~
{                                                                  //~va3kI~
    PUFILEC pfc;                                                   //~va3kI~
    PUFILEH pfh;                                                   //~va3kI~
    PULINEH plh;                                                   //~va3tR~
    PUSCRD  psd;                                                   //~va3kI~
    int rc=0,rcinfo=0,rrow,rcol;                                   //~va3kR~
    int rc2,pos,offs;                                              //~va3tI~
//************************                                         //~va3kI~
    UTRACEP("%s:opt=%04x,row=%d,col=%d\n",UTT,Popt,Prow,Pcol);     //~vbDgR~
    rrow=Prow-Ppcw->UCWorgy;                                       //~va3kI~
    rcol=Pcol-Ppcw->UCWorgx;                                       //~va3kI~
    if (rrow==CMDLINENO)                                           //~va3kI~
    {                                                              //~va3kI~
        rcinfo|=XXECCPI_CMDLINE;                                   //~va3kI~
//      return 0;   //break,allow ligature                         //~va3tR~
        rc=4;                                                      //~va3tI~
    }                                                              //~va3kI~
    else                                                           //~va3tI~
    if (Ppcw->UCWtype==UCWTFILE)                                   //~va3kI~
    {                                                              //~va3kI~
        pfc=Ppcw->UCWpfc;                                          //~va3kI~
        pfh=pfc->UFCpfh;                                           //~va3kI~
        psd=Ppcw->UCWpsd+rrow;                                     //~va6qI~
    	if (RPOSONFILELINE(Ppcw,rrow))                             //~va6qI~
        {                                                          //~va6qI~
            plh=psd->USDbuffc;                                     //~va6qI~
        	if (!RPOSONFILEDATA(Ppcw,rrow,rcol))                   //~va6qI~
        	{                                                      //~va6qI~
        		rcinfo|=XXECCPI_LINENO; //cols is on lineno fld    //~va6qI~
            	rc=4;                                              //~va6qI~
            }                                                      //~va6qI~
        }                                                          //~va6qI~
        else                                                       //~va6qI~
        {                                                          //~va6qI~
        	plh=0;                                                 //~va6qI~
        	rcinfo|=XXECCPI_PAN; //panel part                      //~va6qI~
            rc=4;                                                  //~va6qI~
        }                                                          //~va6qI~
      if (!rc)                                                     //~va6qI~
      {                                                            //~va6qI~
        if (UCBITCHK(pfh->UFHflag11,UFHF11FILEFK))                 //~va6qI~
    		rc=1;                                                  //~va6qI~
        else                                                       //~va6qI~
        if (UCBITCHK(pfh->UFHflag5,UFHF5HEX)                       //~va3kI~
        ||  UCBITCHK(pfh->UFHflag4,UFHF4BIN)                       //~va3kI~
        )                                                          //~va3kI~
        {                                                          //~va3kI~
        	rc=2;                                                  //~va3kI~
        	rcinfo|=XXECCPI_BIN;	//dataline is cpu8 file        //~va3kI~
        }                                                          //~va3kI~
        else                                                       //~va6qI~
        if (UCBITCHK(psd->USDflag2,USDF2PROTFHDR)                  //~va6qI~
    	||  (plh && plh->ULHtype!=ULHTDATA)                        //~va6qI~
        )                                                          //~va6qI~
        {                                                          //~va6qI~
        	rc=3;	//not data line                                //~va6qI~
        	rcinfo|=XXECCPI_HDRLINE; //cols is on lineno fld       //~va6qI~
        }                                                          //~va6qI~
      }                                                            //~va6qI~
//      else                                                       //~va3kI~//~va6qR~
      if (!rc)                                                     //~va6qI~
      {                                                            //~va6qI~
        if (UCBITCHK(pfc->UFCflag2,UFCF2VHEX))	//vhex mode        //~va3kI~
        {                                                          //~va3kI~
    		if (RPOSONFILEDATA(Ppcw,rrow,rcol))                    //~va3kI~
            {                                                      //~va3kI~
            	psd=Ppcw->UCWpsd+rrow;                             //~va3kI~
            	if (UCBITCHK(psd->USDflag2,USDF2VHEXLINE1))        //~va3kI~
                {                                                  //~va3kI~
                	rc=-1;                                         //~va3kI~
        			rcinfo|=XXECCPI_VHEX;	//cols on vhex text    //~va3kI~
                }                                                  //~va3kI~
                else                                               //~va3kI~
            	if (UCBITCHK(psd->USDflag2,USDF2VHEXLINE2))        //~va3kI~
                {                                                  //~va3kI~
                	rc=-2;                                         //~va3kI~
        			rcinfo|=XXECCPI_VHEX;	//cols on vhex text    //~va3kI~
                }                                                  //~va3kI~
                else                                               //~va3kI~
                {                                                  //~va6qI~
                	rc=0;	//file dataline                        //~va3kI~
                }                                                  //~va6qI~
                if (rc<0)                                          //~va3tI~
                {                                                  //~va3tI~
                    plh=psd->USDbuffc;                             //~va3tI~
                    offs=rcol-Ppcw->UCWlinenosz;                   //~va3tI~
                    if (offs>=0)                                   //~va3tI~
                    {                                              //~va3tI~
                    	rc2=xeutf_getvhexpos(0,Ppcw,plh,offs,&pos,0/*out dbcsid*/);//~va3tR~
//                      if (rc2==2)	//dbcs split                   //~vbDqR~
//                      	pos--;                                 //~vbDqR~
                        UTRACEP("%s:pos=%d,left=%d,UCWorgx=%d\n",UTT,pos,pfc->UFCleft,Ppcw->UCWorgx);//~vbDgR~
					  if (Popt & XXECCPO_NOT_RELATIVE)	//    0x04	//for vsplit, col includes left panel width//+vbDqR~
                      	pos+=Ppcw->UCWorgx;                        //+vbDqR~
                        pos-=pfc->UFCleft;                         //~va3tI~
                        pos+=Ppcw->UCWlinenosz;                    //~va3tI~
                        pos<<=XXECCPI_VHEXCSRSHIFT;                //~va3tI~
        				rcinfo|=(pos|XXECCPI_VHEXCSRPOS);          //~va3tI~
                    }                                              //~va3tI~
                }                                                  //~va3tI~
            }                                                      //~va3kI~
//            else                                                   //~va3kI~//~va6qR~
//            {                                                      //~va3kI~//~va6qR~
//                if (GPOSONFILELINE(Ppcw,rrow))                     //~va3kI~//~va6qR~
//                    rcinfo|=XXECCPI_LINENO; //cols is on lineno fld//~va3kI~//~va6qR~
//                rc=4;                                              //~va3kI~//~va6qR~
//            }                                                      //~va3kI~//~va6qR~
        }                                                          //~va3kI~
      }//rc                                                        //~va6qI~
        if (FILEUTF8MODE(pfh))                                     //~va3kI~
        	rcinfo|=XXECCPI_CPU8;	//dataline is cpu8 file        //~va3kI~
    }                                                              //~va3kI~
    else                                                           //~va3kI~
    	rc=1;                                                      //~va3kI~
    if (Ppinfo)                                                    //~va3kI~
    	*Ppinfo=rcinfo;                                            //~va3kI~
UTRACEP("%s:rc=%d,row=%d,col=%d,info=%x\n",UTT,rc,Prow,Pcol,rcinfo);//~vbDgR~
    return rc;                                                     //~va3kI~
}//xxe_chkcsrisfiledataline                                        //~va3kI~
//===============================================================================//~va3kI~
//ligature allowance                                               //~va3kI~
//===============================================================================//~va3kI~
int xxe_chkcsrpos(int Popt,int Prow,int Pcol,int *Ppinfo)          //~va3kI~
{                                                                  //~va3kI~
    PUCLIENTWE pcw;                                                //~va3kI~
    int rc,rc2,info;                                               //~va3kI~
//************************                                         //~va3kI~
UTRACEP("%s:Popt=%04x,row=%d,col=%d\n",UTT,Popt,Prow,Pcol);        //~vbDgR~
    scrcpgetpcw(Prow,Pcol,&pcw);                                   //~va3kI~
	if (Popt & XXECCPO_CSRLINEBREAK)	//should break at csr pos ?//~va3kI~
    {                                                              //~va3kI~
//return row: "+":csr line is dataline,                            //~va3kI~
//            0:not on file text area                              //~va3kI~
//            "-":csrline is vhex and return dataline row          //~va3kI~
    	rc2=xxe_chkcsrisfiledataline(Popt,pcw,Prow,Pcol,Ppinfo);   //~va3kI~
        if (!rc2)                                                  //~va3kI~
        	rc=Prow;    //csr pos is on dataline                   //~va3kI~
        else                                                       //~va3kI~
        if (rc2<0)   //on vhexline                                 //~va3kI~
        	rc=rc2;                                                //~va3kI~
        else                                                       //~va3kI~
        	rc=0;                                                  //~va3kI~
UTRACEP("%s:BREAKCHK rc=%d,row=%d,col=%d\n",UTT,rc,Prow,Pcol);     //~vbDgR~
        return rc;                                                 //~va3kI~
    }                                                              //~va3kI~
	if (Popt & XXECCPO_STRCHK)	//disable ligature ?               //~va3kI~
    {                                                              //~va3kI~
//return 1  : disable ligature for ,ex, vhex line                  //~va3kI~
    	rc2=xxe_chkcsrisfiledataline(Popt,pcw,Prow,Pcol,&info);    //~va3kI~
        if (rc2==1)	//not file panel                               //~va3kI~
            rc=1;   //disable ligature                             //~va3kI~
        else                                                       //~va3kI~
        if (info                                                   //~va3kI~
                 &	(XXECCPI_BIN                                   //~va3kI~
                    |XXECCPI_VHEX                                  //~va3kI~
                    |XXECCPI_LINENO                                //~va3kI~
        			|XXECCPI_HDRLINE //cols is on lineno fld       //~va6qI~
                    |XXECCPI_CMDLINE //cmdline ;avoid "===>"is ligatured//~va6qI~
                    |XXECCPI_PAN     //panel data                  //~va6qI~
                  	)                                              //~va3kI~
        )                                                          //~va3kI~
            rc=1;   //disable ligature                             //~va3kI~
        else                                                       //~va3kI~
            rc=0;                                                  //~va3kI~
        if (Ppinfo)                                                //~va3kI~
        	*Ppinfo=info;                                          //~va3kI~
UTRACEP("chkcsrpos STRCHK rc=%d,row=%d,col=%d,info=%04x\n",rc,Prow,Pcol,info);//~vbDgR~
        return rc;                                                 //~va3kI~
    }                                                              //~va3kI~
    return 0;                                                      //~va3kI~
}//xxe_chkcsrpos                                                   //~va3kI~
//===============================================================================//~va3gI~
//ligature allowance                                               //~va3gI~
//===============================================================================//~va3gI~
int wxe_optligature(int Popt,int Pvalue)                           //~va3gR~
{                                                                  //~va3gI~
	PUCLIENTWE pcw;                                                //~va3gI~
    int oldlig;                                                    //~vb4qI~
//************************                                         //~va3gI~
	if (Popt & WXEIOLO_ISON)                                       //~va3hR~
    {                                                              //~va3hI~
		UTRACEP("%s:rc=%d,WXEIstatus=0x%04x\n",UTT,(((Spwxei->WXEIstatus & WXEIS_LIGATURE)!=0)^((Spwxei->WXEIstatus & WXEIS_TEMPLIGATURE)!=0)),Spwxei->WXEIstatus);//~vbt9R~
	    return (((Spwxei->WXEIstatus & WXEIS_LIGATURE)!=0)^((Spwxei->WXEIstatus & WXEIS_TEMPLIGATURE)!=0));//~va3hI~
    }                                                              //~va3hI~
	if (Popt & WXEIOLO_CHNGDIALOGOPT)		//dialog option        //~va3gI~
    {                                                              //~va3gI~
    	if (!(((Spwxei->WXEIstatus & WXEIS_LIGATURE)!=0) ^ ((Pvalue)!=0)))	//same value//~va3gR~
        	return 0;                                              //~va3gI~
        oldlig=(Spwxei->WXEIstatus & WXEIS_LIGATURE);              //~vb4qI~
        if (Pvalue)                                                //~va3gI~
	    	Spwxei->WXEIstatus|=WXEIS_LIGATURE;                    //~va3gI~
        else                                                       //~va3gI~
	    	Spwxei->WXEIstatus&=~WXEIS_LIGATURE;                   //~va3gI~
	    Spwxei->WXEIstatus&=~WXEIS_TEMPLIGATURE;                   //~va3gI~
		scrcpgetpcw(0,0,&pcw);                                     //~va3gI~
    if (oldlig!=(Spwxei->WXEIstatus & WXEIS_LIGATURE))             //~vb4qI~
      if (pcw)  //not at before xe INIT call                       //~vb4qI~
      {                                                            //~vb4qI~
		wxe_resethdrligature(0,Spwxei->WXEIstatus & WXEIS_LIGATURE);//~vb4qI~
		scrfulldraw(pcw);                                          //~va3gR~
      }                                                            //~vb4qI~
        return 1;   //ligature changed                             //~va3gR~
    }                                                              //~va3gI~
//by Alt+";" key                                                   //~va3gI~
    Spwxei->WXEIstatus^=WXEIS_TEMPLIGATURE;                        //~va3gI~
    if (Spwxei->WXEIstatus & WXEIS_LIGATURE)                       //~va3gR~
    	if (Spwxei->WXEIstatus & WXEIS_TEMPLIGATURE)               //~va3gI~
//    		uerrmsg("Ligature is OFF temorarily",0);               //~va3gR~//~va5zR~
      		uerrmsg("Ligature is OFF temporarily.(Use setup dialog to fix)",0);//~va5zI~
        else                                                       //~va3gI~
        {                                                          //~va3gI~
    		uerrmsg("Ligature was restored(now ON)",0);            //~va3gI~
            if (!UTF_COMBINEMODE())                                //~va3gI~
            	uerrmsgcat(" ,but NO-combine mode",0);             //~va3gI~
        }                                                          //~va3gI~
    else                                                           //~va3gI~
    	if (Spwxei->WXEIstatus & WXEIS_TEMPLIGATURE)               //~va3gI~
        {                                                          //~va3gI~
//    		uerrmsg("Ligature is ON temorarily",0);                //~va3gR~//~va5zR~
    		uerrmsg("Ligature is ON temporarily.(Use setup dialog to fix)",0);//~va5zI~
            if (!UTF_COMBINEMODE())                                //~va3gI~
            	uerrmsgcat(" ,but NO-combine mode",0);             //~va3gI~
        }                                                          //~va3gI~
        else                                                       //~va3gI~
    		uerrmsg("Ligature was restored(now OFF)",0);           //~va3gI~
    return 0;                                                      //~va3gI~
}//wxe_optligature                                                 //~va3gI~
//===============================================================================//~vb3pI~
//=get start column of file edit contents                          //~vb3pI~
//===============================================================================//~vb3pI~
int xxe_getlinenofldsz(int Popt,int Prow,int *Poutcols)            //~vb3pR~
{                                                                  //~vb3pI~
	PUCLIENTWE pcw1,pcw2,pcw;                                      //~vb3pR~
    int rc=0,rrow,ii;                                              //~vb3pR~
//************************                                         //~vb3pI~
	pcw1=scrgetcw(0);	//active client                            //~vb3pI~
	pcw2=scrgetcw(-1);	//inactive client                          //~vb3pI~
    Poutcols[0]=-1;                                                //~vb3pI~
    Poutcols[1]=-1;                                                //~vb3pI~
	for (ii=0,pcw=pcw1;ii<2;ii++,pcw=pcw2)                         //~vb3pI~
	{                                                              //~vb3pI~
		if (!pcw)                                                  //~vb3pI~
			continue;                                              //~vb3pI~
    	if (pcw->UCWtype!=UCWTFILE)                                //~vb3pR~
    		continue;                                              //~vb3pR~
    	rrow=Prow-pcw->UCWorgy;                                    //~vb3pI~
    	if (!RPOSONFILELINE(pcw,rrow))                             //~vb3pR~
    		continue;                                              //~vb3pI~
    	Poutcols[ii]=pcw->UCWlinenosz+pcw->UCWorgx;                //~vb3pR~
        rc++;                                                      //~vb3pI~
	}                                                              //~vb3pI~
UTRACEP("%s rc=%d,row=%d,col=%d,%d\n",UTT,rc,Prow,Poutcols[0],Poutcols[1]);//~vb3pR~
    return rc;                                                     //~vb3pR~
}//xxe_getlinenofldsz                                              //~vb3pI~
////===============================================================================//~vb4iR~
////get ligature row                                               //~vb4iR~
////rc=1;hsplit,2:vsplit,0 no split                                //~vb4iR~
////===============================================================================//~vb4iR~
//int wxe_getligaturerows(int Popt,int *Pvalues)                   //~vb4iR~
//{                                                                //~vb4iR~
//    PUCLIENTWE pcw,pcw1,pcw2;                                    //~vb4iR~
//    int rc=0;                                                    //~vb4iR~
////************************                                       //~vb4iR~
//    if (!Pvalues)                                                //~vb4iR~
//        Pvalues=Sligaturerows;                                   //~vb4iR~
//    memset(Pvalues,0,sizeof(int)*LIGATURE_ROW_TBSZ);             //~vb4iR~
//    pcw1=scrgetcw(1);         //split1                           //~vb4iR~
//    pcw2=scrgetcw(2);         //split2                           //~vb4iR~
//    if (pcw2)                                                    //~vb4iR~
//    {                                                            //~vb4iR~
//        pcw=pcw2;                                                //~vb4iR~
//        Pvalues[LIGATURE_ROW_HDRLNO2]=pcw->UCWfilehdrlineno;     //~vb4iR~
//        if (UCBITCHK(Gscrstatus,GSCRSSPLITH))                    //~vb4iR~
//        {                                                        //~vb4iR~
//            Pvalues[LIGATURE_ROW_TOP2ND]=pcw->UCWorgy;           //~vb4iR~
//            rc=LIGATURE_ROW_RC_HSPLIT;                           //~vb4iR~
//        }                                                        //~vb4iR~
//        else                                                     //~vb4iR~
//        {                                                        //~vb4iR~
//            Pvalues[LIGATURE_ROW_COL2ND]=pcw->UCWorgx;           //~vb4iR~
//            rc=LIGATURE_ROW_RC_VSPLIT;                           //~vb4iR~
//        }                                                        //~vb4iR~
//        if (pcw->UCWtype==UCWTDIR)                               //~vb4iR~
//            Pvalues[LIGATURE_ROW_DIRENT2]=pcw->UCWorgy+pcw->UCWfilehdrlineno;//~vb4iR~
//    }                                                            //~vb4iR~
//    pcw=pcw1;                                                    //~vb4iR~
//    {                                                            //~vb4iR~
//        Pvalues[LIGATURE_ROW_HDRLNO1]=pcw->UCWfilehdrlineno;     //~vb4iR~
//        if (pcw->UCWtype==UCWTDIR)                               //~vb4iR~
//            Pvalues[LIGATURE_ROW_DIRENT1]=pcw->UCWorgy+pcw->UCWfilehdrlineno;//~vb4iR~
//    }                                                            //~vb4iR~
//    UTRACEP("%s:2ndrow=%d,2ndcol=%d,dir1=%d,dir2=%d\n",Pvalues[LIGATURE_ROW_TOP2ND],Pvalues[LIGATURE_ROW_COL2ND],Pvalues[LIGATURE_ROW_DIRENT1],Pvalues[LIGATURE_ROW_DIRENT2]);//~vb4iR~
//    UTRACEP("%s:hdrlineno1=%d,hdrlineno2=%d\n",Pvalues[LIGATURE_ROW_HDRLNO1],Pvalues[LIGATURE_ROW_HDRLNO2]);//~vb4iR~
//    return rc;                                                   //~vb4iR~
//}//wxe_getligaturerows                                           //~vb4iR~
////===============================================================================//~vb4iR~
////chk row is ligature line                                       //~vb4iR~
////===============================================================================//~vb4iR~
//int wxe_chkligaturerow(int Popt,int *Pligaturerows,int Prow,int Pcol,int *Prelativerow)//~vb4iR~
//{                                                                //~vb4iR~
//    int rc=0,rrow=-1,top2nd,col2nd,dirrow;                       //~vb4iR~
////************************                                       //~vb4iR~
//    rc=0;// depend ligature/combine option                       //~vb4iR~
//    if (!Pligaturerows)                                          //~vb4iR~
//        Pligaturerows=Sligaturerows;                             //~vb4iR~
//                                                                 //~vb4iR~
//    top2nd=Pligaturerows[LIGATURE_ROW_TOP2ND];    //hsplit       //~vb4iR~
//    col2nd=Pligaturerows[LIGATURE_ROW_COL2ND];    //hsplit       //~vb4iR~
//    if (top2nd) //hsplit                                         //~vb4iR~
//    {                                                            //~vb4iR~
//        if (Prow>=top2nd && Prow<=top2nd+CMDLINENO)              //~vb4iR~
//            rrow=Prow-top2nd;   //hdr or cmdlineno               //~vb4iR~
//        else                                                     //~vb4iR~
//        if (Prow<=CMDLINENO)                                     //~vb4iR~
//            rrow=Prow;                                           //~vb4iR~
//        else                                                     //~vb4iR~
//        {                                                        //~vb4iR~
//            dirrow=Pligaturerows[LIGATURE_ROW_DIRENT2];    //hsplit//~vb4iR~
//            if (dirrow && Prow>=dirrow)                          //~vb4iR~
//                rrow=Prow-top2nd;   //>=2 or 3                   //~vb4iR~
//            dirrow=Pligaturerows[LIGATURE_ROW_DIRENT1];    //hsplit//~vb4iR~
//            if (dirrow && Prow>=dirrow && Prow<top2nd)           //~vb4iR~
//                rrow=Prow;  //>=2 or 3                           //~vb4iR~
//        }                                                        //~vb4iR~
//    }                                                            //~vb4iR~
//    else                                                         //~vb4iR~
//    if (col2nd) //vsplit                                         //~vb4iR~
//    {                                                            //~vb4iR~
//        if (Prow<=CMDLINENO)                                     //~vb4iR~
//            rrow=Prow;                                           //~vb4iR~
//        else                                                     //~vb4iR~
//        {                                                        //~vb4iR~
//            if (Pcol<col2nd)    //pcw1                           //~vb4iR~
//                dirrow=Pligaturerows[LIGATURE_ROW_DIRENT1];    //hsplit//~vb4iR~
//            else                                                 //~vb4iR~
//                dirrow=Pligaturerows[LIGATURE_ROW_DIRENT2];    //hsplit//~vb4iR~
//            if (dirrow && Prow>=dirrow)                          //~vb4iR~
//                rrow=Prow;  //>=2 or 3                           //~vb4iR~
//        }                                                        //~vb4iR~
//    }                                                            //~vb4iR~
//    else                                                         //~vb4iR~
//    {                                                            //~vb4iR~
//        if (Prow<=CMDLINENO)                                     //~vb4iR~
//            rrow=Prow;                                           //~vb4iR~
//        else                                                     //~vb4iR~
//        {                                                        //~vb4iR~
//            dirrow=Pligaturerows[LIGATURE_ROW_DIRENT1];    //hsplit//~vb4iR~
//            if (dirrow && Prow>=dirrow)                          //~vb4iR~
//                rrow=Prow;  //>=2 or 3                           //~vb4iR~
//        }                                                        //~vb4iR~
//    }                                                            //~vb4iR~
//    if (!rrow)                     //hdr                         //~vb4iR~
//        rc=CHKLIGATURE_RC_LIGATURE; //combine dependts option    //~vb4iR~
//    else                                                         //~vb4iR~
//    if (rrow=CMDLINENO)            //cmdline                     //~vb4iR~
//        rc=CHKLIGATURE_RC_NOLIGATURE|CHKLIGATURE_RC_NOCOMBINE;   //~vb4iR~
//    else                                                         //~vb4iR~
//    if (rrow)                     //dir entry                    //~vb4iR~
//        rc=CHKLIGATURE_RC_LIGATURE;      //combine is depends option//~vb4iR~
//    *Prelativerow=rrow;                                          //~vb4iR~
//    UTRACEP("%s:rc=%02x,Prow=%d,Pcol=%d,rrow=%d,top2nd=%d,col2nd=%d\n",rc,Prow,Pcol,rrow,top2nd,col2nd);//~vb4iR~
//    return rc;                                                   //~vb4iR~
//}//wxe_getligaturerows                                           //~vb4iR~
//===============================================================================//~vb4iI~
//chk row is ligature line                                         //~vb4iI~
//===============================================================================//~vb4iI~
int wxe_getlineopt(int Popt,int Prow,int Pcol)                     //~vb4iR~
{                                                                  //~vb4iI~
	PUCLIENTWE pcw;                                                //~vb4iI~
//  int lineopt,vsplit2nd,errmsglineopt=0;                         //~vb4tR~
    int lineopt,vsplit2nd;                                         //~vb4tI~
//************************                                         //~vb4iI~
	pcw=scrgetcw(2);    //2nd pcw                                  //~vb4iI~
    vsplit2nd=((pcw && pcw->UCWorgx && Pcol>=pcw->UCWorgx) ? UVIOO_VSPLIT2ND :0);//~vb4iR~
//  lineopt=uvio_getbufflineopt(0,Prow,vsplit2nd);                 //~vb4tR~
    lineopt=uvio_getbufflineopt(0,Prow,vsplit2nd,Pcol);            //~vb4tI~
//    if (lineopt & UVIOO_ERRMSGMASK)                              //~vb4tR~
//    {                                                            //~vb4tR~
//        errmsglineopt=lineopt>>16;                               //~vb4tR~
//        if (vsplit2nd)                                           //~vb4tR~
//        {                                                        //~vb4tR~
//            if (Pcol==pcw->UCWorgx)                              //~vb4tR~
//                lineopt=errmsglineopt;                           //~vb4tR~
//        }                                                        //~vb4tR~
//        if (!Pcol)                                               //~vb4tR~
//            lineopt=errmsglineopt;                               //~vb4tR~
//        else                                                     //~vb4tR~
//            lineopt&=~UVIOO_ERRMSGMASK;                          //~vb4tR~
//    }                                                            //~vb4tR~
    UTRACEP("%s:Prow=%d,Pcol=%d,rc:lineopt=%04x,vsplit2nd=%04x\n",UTT,Prow,Pcol,lineopt,vsplit2nd);//~vb4tR~
    return lineopt;                                                //~vb4iI~
}//wxe_getlineopt                                                  //~vb4iI~
//*************************************************************    //~vb4qI~
int wxe_resethdrligature(int Popt,int Pligature)                   //~vb4qR~
{                                                                  //~vb4qI~
    PUCLIENTWE pcw;                                                //~vb4qI~
//***********************                                          //~vb4qI~
    UTRACEP("%s:Pligature=%d\n",UTT,Pligature);                    //~vb4qI~
	pcw=scrgetcw(0);	//active client                            //~vb4qI~
	optresethdrligcomb(0,pcw);                                     //~vb4qR~
    scrdisp();          //update screen                            //~vb4qI~
    return 0;                                                      //~vb4qI~
}//wxe_resethdrligature                                            //~vb4qI~
//*************************************************************    //~vbj2I~
//*chk current is cmdHistoryListPanel                              //~vbj2I~
//*rc:1:Yes                                                        //~vbj2I~
//*************************************************************    //~vbj2I~
void *wxe_isCHLLine(int Popt)                                      //~vbj2R~
{                                                                  //~vbj2I~
	PUCLIENTWE pcw;                                                //~vbj2I~
    PUFILEC    pfc;                                                //~vbj2I~
    PUFILEH    pfh;                                                //~vbj2I~
    PULINEH    plh;                                                //~vbj2I~
    PUSCRD psd;                                                    //~vbj2I~
    int row;                                                       //~vbj2I~
//***********************                                          //~vbj2I~
	pcw=scrgetcw(0);	//active client                            //~vbj2I~
    if (pcw->UCWtype!=UCWTFILE)                                    //~vbj2I~
    	return 0;                                                  //~vbj2R~
	pfc=pcw->UCWpfc;                                               //~vbj2I~
	pfh=pfc->UFCpfh;                                               //~vbj2I~
    if (pfh->UFHtype!=UFHTCMDHIST)                                 //~vbj2I~
    	return 0;                                                  //~vbj2R~
    if (!CSRONFILELINE(pcw))                                       //~vbj2I~
    	return 0;                                                  //~vbj2I~
    row=pcw->UCWrcsry;                                             //~vbj2R~
    psd=pcw->UCWpsd;                                               //~vbj2I~
    psd+=row;                                                      //~vbj2I~
    plh=psd->USDbuffc;                                             //~vbj2I~
    if (!plh)                                                      //~vbj2I~
    	return 0;                                                  //~vbj2I~
    if (plh->ULHtype==ULHTHDR)                                     //~vbj2I~
    	return 0;                                                  //~vbj2I~
    UTRACEP("%s:row=%d,plhline=%d,pcw=%p\n",UTT,row,plh->ULHlinenor,pcw);//~vbj2R~
    return pcw;                                                    //~vbj2R~
}//wxe_isCHLLine                                                   //~vbj2R~
//*************************************************************    //~vbj2I~
//*chk current is cmdHistoryListPanel                              //~vbj2I~
//*rc:1:Yes                                                        //~vbj2I~
//*************************************************************    //~vbj2I~
int  wxe_CHLcmd(int Popt,int Pcmd)                                 //~vbj2R~
{                                                                  //~vbj2I~
	PUCLIENTWE pcw;                                                //~vbj2I~
    int rc;                                                        //~vbj2I~
    int stat=0;                                                    //~vbj2I~
//***********************                                          //~vbj2I~
	pcw=wxe_isCHLLine(0);                                          //~vbj2R~
	if (!pcw)                                                      //~vbj2R~
    	return -1;                                                 //~vbj2R~
    stat|=WXEKBDMSG_ONCHAR;                                        //~vbj2I~
	rc=wxe_kbdmsg(stat,(UINT)Pcmd,1/*Prepctr*/,0/*flag*/);         //~vbj2R~
    return rc;                                                     //~vbj2I~
}//wxe_CHLcmd                                                      //~vbj2R~
//*************************************************************    //~vbDgI~
//*get xe global                                                   //~vbDgI~
//*************************************************************    //~vbDgI~
int  wxexei_getXeOpt(int Popt)                                     //~vbDgI~
{                                                                  //~vbDgI~
	int rc=0;                                                      //~vbDgI~
    switch(Popt)                                                   //~vbDgI~
    {                                                              //~vbDgI~
    case GXEO_TABDISPLAY:      //1                                 //~vbDgI~
    	rc=(Gopt & GOPTTABDISPLAY);	//       0x10       //tab char display//~vbDgI~
        break;                                                     //~vbDgI~
    case GXEO_TABCOLORFG:      //2                                 //~vbDgI~
    	int fgpal=Gattrtbl[COLOR_ELINENO] & 0x0f/*fg*/;            //~vbDgI~
        rc=Spwxei->WXEIpalrgb[fgpal];                              //~vbDgR~
	    UTRACEP("%s:Gattrtbl[COLOR_ELINENO:%d]=%02x,fgpal=%02x,fgcolor=%08x\n",UTT,COLOR_ELINENO,Gattrtbl[COLOR_ELINENO],fgpal,rc);//~vbDgR~
        break;                                                     //~vbDgI~
    }                                                              //~vbDgI~
    UTRACEP("%s:opt=%d,rc=%d\n",UTT,Popt,rc);                      //~vbDgI~
    return rc;                                                     //~vbDgI~
}//wxexei_getXeOpt                                                 //~vbDgI~
