//*CID://+vbDsR~:                               update#=  678;     //~vbAjR~//~vbDsR~
//*********************************************************************//~v440I~
//* wxe interface **                                               //~v69mR~
//*********************************************************************//~v440I~
//vbDs:250730 (gxe)vbDp for gxe(split combining,vhex csr data color)//~vbDsI~
//vbAj:240619 (gxe)if LIG:ON and COMB:ON, allow expand line by large glyph when no split by cursor//~vbAjI~
//vbu0:201217 Debian10 compiler warning                            //~vbu0I~
//vbtb:201214 (BUG) TODO TEST was remained(IME conv err for SJIS)  //~vbtbI~
//vbta:201214 allow -Nm for linux(abondon vbt3)                    //~vbtaI~
//vbp5:190914 gdk_beep deprecated at GTK3 use gdk_display_beep     //~vbp5I~
//vbm5:180715 (gxe:Bug)lineno fld and top unprintable(":;") is same color so ligature not applied. So,cut strput by linenosize>//~vbm5I~
//vbj2:180424 popup menu on cmd history list                       //~vbj2I~
//vb74:161220 Gtk3 warning                                         //~vb74I~
//vb4t:160812 consider errmsg 2nd line for combine                 //~vb4tI~
//vb4q:160810 display ligature/combine mode on "TOP OF LINE"       //~vb4qI~
//vb4r:160811 (XXE) v4f for XXE((ULIB:v6Ei)specify ligature on/off,combine on/of line by line(used for edit/filename  panel))//~vb4rI~
//vanh:131214 (BUG:gxe) keyname should be utf8 when --xxekbchk option//~vanhI~
//vam0:130911 for distro removed gnome-print,use GTKprint          //~vam0I~
//vaf5:120604 (WXE/XXE) msgbox for uerrexit by inifile version unmatch//~vaf5I~
//vaa7:111117 (gcc4.6)Warning:unused-but-set                       //~vaa7I~
//vaa3:110926 (WXEXXE:BUG)mouse lineselect on top menu,row count was changed;//~vaa3I~
//va7S:100907 (BUG)mouse drag at edge of screen dose not expand copy range bat scroll.//~va7SI~
//va7D:100830 (XXE:BUG)cap menu update err(it should not be based on Mcellcopy1 bur Gcsrposy)//~va7DI~
//va72:100801 LP64 wchar_t is 4byte on LP64                        //~va72I~
//va70:000701 LP64 option support                                  //~va70I~
//va6q:000623 avoid ligature for not data line(gauge, xline etc)   //~va6qI~
//va5z:100519 (WXEXXE) spell miss(temorarily)                      //~va5zI~
//va3D:100310 (WXE)Unicode direct input support(A+"+" and Uxxxx)   //~va3DI~
//va3t:100221 (WXEXXE)break also at prev char of vhex data csr pos for backspace at vhex line//~va3tI~
//va3d:100206 (LNX)toggle ligature temprary by A+";", change combine key A+"/"-->C+":"//~va3dI~
//va3b:100205 (GXE)no ligature for hex edit(HEX mode and EH cmd)   //~va3bI~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//va1c:091030_merge GB18030 support                                //~va1cI~
//va0V:091007!(BUG:XXE)use not a2a but cvf2l because a2a dbcschk is invalid for UTF8//~va0VI~
//va0U:091003!(BUG:XXE)dbcstbl should be localdbcstbl for UTF8env  //~va0UI~
//va0T:091003!(BUG:XXE)miss utf8 string when ime returns mutiple utf8 char//~va0TI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          return utf8string on kyinfo                            //~va00I~
//v79z:080916 DBCS tbl for C and K of CJK                          //~v79zI~
//v780:080212 syntaxhighlight support (SYN cmd,C+s func key)       //~v780I~
//v76p:070628 compare remote file support                          //~v76pI~
//v76n:070628 scroll size support for =2/=1 panel                  //~v76nI~
//v76f:070619-(XXE:BUG)loop at kbdproc when paste after rctl under RCTL on mode//~v76fI~
//v76e:070618 (XXE)typematic support for R-Ctrl                    //~v76eI~
//v73y:070128-(WXE/XXE)Quiet-exit support                          //~v70zI~
//v70z:060904 3270 ftp support                                     //~v70zI~
//v705:060727 graphic char setup by external file                  //~v705I~
//v69m:060524 (WXEXXE)pass scroll ctr not by string cmd parm but thrugh gbl var to avoid cmd line input cleared//~v69mI~
//v69j:060523 (WXEXXE)avoid horizontal scroll err msg for dir list //~v69jI~
//v69i:060523 (WXEXXE)use pgleft/pgright also for elecom hscroll mouse(generate VK_SCROLL+VK_LEFT/VK_RIGHT+VK_SCROLL)//~v69iI~
//v69h:060521 (WXEXXE)windows generate WM_HSCROLL by Shift+Wheel; so S+Wheel(filend) and C+Wheel(Hscroll)//~v69hI~
//v69b:060516 horizontal scroll function by Left/Right key on ScrollLock status//~v69bI~
//v67G:051231 (WXEXXE)display menu before termination confirm dialog//~v67GI~
//v672:051225 (WXE) errmsg issue when no key/cmd assigned to the func//~v672I~
//v671:051224 (WXE:BUG) cmdline wxe with filename;fullpath modified by WXE implicit /R option. skip set /R when pos parm exist//~v671I~
//v66A:051220 dialog to confirm wxe/gxe termination when func-key used//~v66AI~
//vXXE:050611 new for XXE                                          //~vXXEI~
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
//#include <io.h>                                                  //~v62NR~
//*************************************************************    //~v440I~
#ifndef OPTGTK3                                                    //~var8R~
#include <gnome.h>                                                 //~v62NI~
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
//*************************************************************    //~v440I~
#include <ulib.h>                                                  //~v440I~
#include <uque.h>                                                  //~v440I~
#include <uvio.h>                                                  //~v440I~
#include <ufile.h>                                                 //~v440I~
#include <udbcschk.h>                                              //~2915I~
#include <uerr.h>                                                  //~2928I~
#include <ualloc.h>                                                //~2929I~
#include <utrace.h>                                                //~2929M~
#include <uproc.h>                                                 //~v55oI~
#include <ustring.h>                                               //~v55UI~
#include <ukbd.h>                                                  //~v62NR~
#include <uftp.h>                                                  //~v76pI~
#include <ucvext.h>                                                //~v79zI~
#include <utf.h>                                                   //~va0VI~
#include <ucvucs.h>                                                //~va3DI~
#define UVIOMDEFONLY	//for uviom.h                              //~vb4rI~
#include <uviom.h>                                                 //~vb4rI~
                                                                   //~v440I~
#include "xe.h"                                                    //~v440R~
#include "xescr.h"                                                 //~v440I~
#include "xekbd.h"                                                 //~v440I~//~vam0M~
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
#include "xeacb.h"                                                 //~va1cR~
#include "xesub2.h"                                                //~va1cR~
#include "xesyn.h"                                                 //~v780I~
#include "xesyn2.h"                                                //~v780I~
#include "xeutf.h"                                                //~va3tI~//~va3DR~
#include "xeutf2.h"                                                //~va3DI~
#include "xeopt.h"                                                 //~vb4rI~
                                                                   //~v440I~
#include "gxe.h"                                                   //~v62NI~
#include <xxedef.h>                                                //~v62NI~
#include <xxemain.h>                                               //~v62NR~
#define  WXEXEI_GLOBAL                                             //~2928I~
#include <xxexei.h>                                                //~v62NR~
#include "xxecsub.h"                                               //~vXXER~
#include "xxexei3.h"                                               //~vXXER~
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
    WXEINTF *Spwxei;                                               //~va7DR~
//*************************************************************    //~v440I~
//#define IM_MAXLEN 256 			//commit string max len            //~v62NR~//~va0TR~
//static UCHAR Simstr[IM_MAXLEN];                                    //~v62NI~//~va0TR~
static UCHAR Simstr[MAXIMECHARCTR];                                //~va0TI~
#ifdef UTF8SUPPH                                                   //~va00I~
static UCHAR Simdbcs[MAXIMECHARCTR];                               //~va0TR~//~va0VR~
//static UCHAR Sutf8str[UTF8_MAXCHARSZMAX+1];                        //~va00I~//~va0TR~
static UCHAR Sutf8str[UTF8_MAXCHARSZMAX*MAXIMECHARCTR+1];          //~va0TR~
static int Sutf8strlen,Sutf8stroffs;                               //~va0TI~
#endif                                                             //~va00I~
static int   Simstrlen,Simnextpos;                                 //~vXXER~
static int   Sdatasw;                                              //~vXXEI~
static KBDKEYINFO Skeyinfo;                                        //~v62NI~
static int Sargc;                                                  //~v440I~
static int Sxeinitsw=0;                                            //~2907I~
static char **Sargv;                                               //~v440I~
static int Slastinputkey=0;                                        //~v66AI~
#ifdef UTF8UCS4                                                    //~va3DI~
	static int Simef2lerr=0;                                       //~va3DI~
#endif                                                             //~va3DI~
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
void xxexei_kbdinit(void);                                         //~v76eI~
void  xxe_setdbcstbl(char *Ptext,char *Pdbcs,int Plen);            //~va0VI~
int xxe_imef2lerr(int Popt,KBDKEYINFO *Pkeyinfo,char *Ppu8,int Pu8len);//~va3DI~
#define     XXEIMEERRO_NOTERR   0x01    //1st utf8 char successed f2l//~va3DR~
#define     XXEIMEERRO_CONT     0x02    //confirm err for multiple utf8 string//~va3DI~
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
  if (wxe_parmchk(Pargc,Pargv)) //posparm cnt!=0                   //~v671I~
  {                                                                //~v671I~
    Sargc=Pargc;                                                   //~v671I~
//  Sargv=(char**)malloc((Sargc+1)*4);                             //~v671I~//~va70R~
    Sargv=(char**)malloc((Sargc+1)*PTRSZ);                         //~va70I~
//  memcpy(Sargv,Pargv,(Sargc+1)*4);                               //~v671I~//~va70R~
    memcpy(Sargv,Pargv,(Sargc+1)*PTRSZ);                           //~va70I~
  }                                                                //~v671I~
  else                                                             //~v671I~
  {                                                                //~v671I~
    Sargc=Pargc+1;                                                 //~v62NI~
//  Sargv=(char**)malloc((Sargc+1)*4);                             //~v62NI~//~va70R~
    Sargv=(char**)malloc((Sargc+1)*PTRSZ);                         //~va70I~
//  memcpy(Sargv,Pargv,Sargc*4);                                   //~v62NI~//~va70R~
    memcpy(Sargv,Pargv,Sargc*PTRSZ);                               //~va70I~
    Sargv[Pargc]="-R";      //add parm to restore last cur dir     //~v62NR~
    Sargv[Sargc]=0;     //last null ptr;                           //~v62NI~
  }                                                                //~v671I~
	memset(&wxeintf,0,sizeof(wxeintf));                            //~2B30I~
	rc=wxe_xecall(WXE_REQ_PREINIT,&wxeintf);                       //~v62NR~
    return rc;                                                     //~2B30I~
}//wxe_preinit                                                     //~2B30I~
//*************************************************************    //~v671I~
//*parmchk                                                         //~v671I~
//*ret:posparm cnt                                                 //~v671I~
//*************************************************************    //~v671I~
int wxe_parmchk(int Pargc,char **Pargv)                            //~v671I~
{                                                                  //~v671I~
	int posparmno=0,ii;                                            //~v671I~
	char *pc;                                                      //~v671I~
//***********************                                          //~v671I~
	for (ii=1;ii<Pargc;ii++)                                       //~v671I~
    {                                                              //~v671I~
    	pc=Pargv[ii];                                              //~v671I~
        if (*pc=='/'||*pc=='-')                                    //~v671I~
        	continue;                                              //~v671I~
        posparmno++;                                               //~v671I~
    }                                                              //~v671I~
    return posparmno;                                              //~v671I~
}//wxe_parmchk                                                     //~v671I~
//*************************************************************    //~v62NI~
//*interface to kbdgetname                                         //~v62NI~
//*************************************************************    //~v62NI~
char *wxe_kbdgetname(int Pkey,int Pshift)                          //~v62NI~
{                                                                  //~v62NI~
    char *pc,*putf8;                                               //~vanhI~
    int readlen,writelen;                                          //~vanhI~
//***********************                                          //~v62NI~
//  return (char*)kbdgetname((USHORT)Pkey,Pshift);                 //~v62NI~//~vanhR~
    pc=(char*)kbdgetname((USHORT)Pkey,Pshift);                     //~vanhI~
    if (XE_ISDBCSJ())                                              //~vanhI~
    {                                                              //~vanhI~
		csublocale2utf8(0,pc,strlen(pc),&readlen,&putf8,&writelen);//~vanhI~
        if (putf8)                                                 //~vanhI~
		    pc=putf8;//static in csublocale2utf8                   //~vanhI~
    }                                                              //~vanhI~
    return pc;                                                     //~vanhI~
}//wxe_kbdgetname                                                  //~v62NI~
//*************************************************************    //~v440I~
//*call xe                                                         //~v440I~
//*p1:req type                                                     //~v440I~
//*p2:initreq:arg ctr                                              //~v440I~
//*p3:initreq:arg ptr list                                         //~v440I~
//*************************************************************    //~v440I~
int wxe_xecall(int Preqtype,void *Ppwxei)                          //~v62NR~
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
		rc=xemain(Preqtype,Sargc,Sargv);                           //~2C15R~
        if (Preqtype==WXE_REQ_PREINIT)                             //~2B30I~
            break;                                                 //~2B30I~
        if (rc==-1)                                                //~2A07I~
            break;                                                 //~2A07I~
//#fndef XXE                                                       //~v70zR~
//		usystem_cmdserverinit(UPROC_LAZY,wxe_cmdservercallback,0,0,0,0);//use cmd server for system()//~v70zR~
//#endif                                                           //~v70zR~
        Sxeinitsw=Preqtype;                                        //~2B30R~
    	Spwxei->WXEIdbcs=Gscrdbcstbl;    //by scrinit()            //~2901I~
    	Spwxei->WXEIsynstyle=Gsynstyletbl;    //by syninit         //~v780I~
    	Spwxei->WXEIsynrgb=Gsyncfg.SYNCrgb;    //rgb tbl by xesyn.cfg//~v780I~
        xxexei_kbdinit();                                          //~v76eI~
        if (*Gcmdbuff) //no command pending                        //~v440I~
            kbdproc();		//initial cmd                          //~v440I~
        scrdisp();          //ist screen                           //~v440I~
        break;                                                     //~v440I~
    case WXE_REQ_TERM:                                             //~v440R~
        dprintf("xei term sw=%d\n",Spwxei->WXEIxetermsw);   	//xe malloc area is all freeed//~vXXER~
//  	if (Sargv)	//dup chk                                      //~v55UR~
	    if (!Spwxei->WXEIxetermsw)		//xe malloc area is all freeed//~v55UI~
        {                                                          //~3125I~
//			usystem_cmdserverterm(0,0,0);                          //~v70zR~
	    	Spwxei->WXEIxetermsw=1;		//xe malloc area is all freeed//~v55UI~
	        dprintf("xei term lastpft=%p\n",Gproclastpft);   	//xe malloc area is all freeed//~vXXER~
        	if (Gproclastpft)	//avoid abend at xe.c              //~3125I~
				rc=xemain(Preqtype,Sargc,Sargv);                   //~3125R~
        	free(Sargv);                                           //~3125R~
        	Sargv=0;                                               //~3125R~
//      }                                                          //~v55UR~
//      usystem_cmdserverterm(0,0,0);                              //~v56xR~
        }                                                          //~v55UI~
        break;                                                     //~v440I~
    case WXE_REQ_KEYEVENT:                                         //~v440R~
//		Gwxestat|=GWXES_KBDEVENT;	//for wxe_setcurpos            //~va7DR~//~va7SR~
        for (;;)                                                   //~v440I~
        {                                                          //~v440I~
UTRACEP("%s:call xekbd:kbdproc\n",UTT);                                         //~2914I~//~vbAjR~
        	rc=kbdproc();                                          //~v440I~
        	if (rc==-1)		//quit                                 //~v440I~
            {                                                      //~v66AI~
              if (Slastinputkey!=KEY_ENTER)	//not by cmd input but by func key//~v66AR~
              {                                                    //~v66AI~
                    if (Gwxestat & GWXES_OPT_QEXIT)	//exit w/o dialog//~v70zI~
                    	break;                                     //~v70zI~
                    pcw=panregist(PANTOPMENU);                     //~v67GI~
    	        	scrdisp();  //set dbcs tbl before csr move     //~v67GI~
  		            wxe_scrdraw();    //redraw wxe scr @@@@        //~v67GI~
//                	if (uerrmsgboxokcan("Exit xe ? (File was saved)",0)!=0)	//cancelled//~v672R~
                	if (uerrmsgboxokcan("Exit xe ?","xe 終了確認")!=0)	//cancelled//~v672I~
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
			  if (!(Simstrlen && Simnextpos<Simstrlen))            //~vXXEI~
            	break;                                             //~v440I~
        	if (!*Gcmdbuff) //no command pending                   //~2914I~
	        	scrdisp();  //set dbcs tbl before csr move         //~2914I~
        }                                                          //~v440I~
        if (rc==XEKBD_RC_MORE)		//request next key input       //~2915I~
        	return rc;                                             //~2915I~
        if (rc==-1)//quit                                          //~2915R~
        {                                                          //~2915I~
			wxe_xecall(WXE_REQ_TERM,Ppwxei);                       //~v62NR~
        	return -1;                                             //~2915R~
        }                                                          //~2915I~
        scrdisp();          //1st screen                           //~v440I~
// 		Gwxestat&=~GWXES_KBDEVENT;	//for wxe_setcurpos            //~va7DI~//~va7SR~
        break;                                                     //~v440I~
    }                                                              //~v440I~
//dprintf("xecall return\n");                                      //~vXXER~
    return rc;                                                     //~v440I~
}//wxe_xecall                                                      //~v440R~
//*************************************************************    //~v76eI~
//*kbdinit                                                         //~v76eI~
//*kbd delay and rate                                              //~v76eM~
//*************************************************************    //~v76eI~
void xxexei_kbdinit(void)                                          //~v76eI~
{                                                                  //~v76eI~
	int delay,interval;                                            //~v76eR~
//********************************                                 //~v76eI~
    Spwxei->WXEIkbddelay=Gkbddelay;	//by ini file                  //~v76eI~
    if (Gkbdspeed)                                                 //~v76eI~
        Spwxei->WXEIkbdspeed=1000/Gkbdspeed;                       //~v76eI~
    if (!ugconfgetkbdrate(&delay,&interval))                       //~v76eR~
    {                                                              //~v76eI~
        if (delay)                                                 //~v76eI~
            Spwxei->WXEIkbddelay=delay;    //by Gconf              //~v76eR~
        if (interval)                                              //~v76eI~
            Spwxei->WXEIkbdspeed=interval;                         //~v76eR~
    }                                                              //~v76eI~
    return;                                                        //~v76eI~
}//xxexei_kbdinit                                                  //~v76eI~
//*************************************************************    //~2901I~
//*kbd msgproc                                                     //~2901I~
//*rc:-1:exit,1:redraw,0:no draw                                   //~2914I~
//*************************************************************    //~2901I~
int  wxe_kbdmsg(int Pstat,UINT Pscanchar,UCHAR *Pstr,int Pstrlen)  //~v62NR~
{                                                                  //~2901I~
	int keystate=0,rc,len,fbstate=0;                               //~vXXER~
#ifdef UTF8SUPPH                                                   //~va0TI~
    int u8chsz;                                                    //~va0TI~
    int dbcssz,nlsopt=0;                                           //~va1cR~
    int opt;                                                       //~va3DI~
#endif                                                             //~va0TI~
//***********************                                          //~2901I~
	Slastinputkey=Pscanchar;                                       //~v66AI~
    if (Pstat & WXEKBDMSG_SYSKEY)                                  //~v62NR~
        keystate|=KBDSTF_ALT;                                      //~v62NR~
    if (Pstat & WXEKBDMSG_SHIFTKEY)                                //~2921R~
        keystate|=(KBDSTF_RIGHTSHIFT|KBDSTF_LEFTSHIFT);            //~v62NR~
    if (Pstat & WXEKBDMSG_SCROLLLOCKON)                            //~v69bI~
        keystate|=KBDSTF_SCROLLLOCK_ON;                            //~v69bR~
    if (Pstat & WXEKBDMSG_CTLKEY)                                  //~2921I~
    {                                                              //~v62NI~
      if (Pstat & WXEKBDMSG_RCTLKEY)                               //~v55cI~
      {                                                            //~vXXEI~
		keystate|=KBDSTF_RIGHTCONTROL|KBDSTF_CONTROL;              //~v62NR~
        fbstate=KBDTRF_SHIFT_KEY_IN; //for xekbd                   //~vXXEI~
      }                                                            //~vXXEI~
      else                                                         //~v55cI~
		keystate|=KBDSTF_CONTROL;                                  //~v62NR~
    }                                                              //~v62NI~
//    if (Pstat & WXEKBDMSG_FFKEY)                                 //~v62NR~
//    {                                                            //~v62NR~
//        if (!(Pscanchar & 255)) //no char code                   //~v62NR~
//        {                                                        //~v62NR~
//            dprintf("enhanced key\n");                           //~vXXER~
//            keystate|=ENHANCED_KEY;                              //~v62NR~
//        }                                                        //~v62NR~
//    }                                                            //~v62NR~
                                                                   //~2921I~
    Skeyinfo.fsState=(USHORT)keystate;                             //~v62NR~
    Skeyinfo.fbStatus=(UCHAR)fbstate;                              //~vXXER~
    Skeyinfo.bNlsShift=0;   //utf8 info                            //~va0VI~
	memset(Skeyinfo.u8str,0,sizeof(Skeyinfo.u8str));               //~va0VR~
    Simstrlen=0;                                                   //~vXXEI~
    if (Pstat & WXEKBDMSG_ONCHAR)                                  //~v62NI~
    {                                                              //~v62NI~
    	Skeyinfo.chScan=0;                                         //~v62NR~
    	Skeyinfo.chChar=*Pstr;                                     //~vXXEI~
//      len=min(Pstrlen,IM_MAXLEN);                                //~v62NI~//~va0TR~
        len=min(Pstrlen,MAXIMECHARCTR);                            //~va0TI~
        if (len>1)                                                 //~vXXEI~
        {                                                          //~vXXEI~
#ifdef UTF8SUPPH                                                   //~va1cR~
          if (Gxxestat & GXXES_DBCSREAD)	//return dbcs at once  //~va1cR~
          {                                                        //~va1cR~
UTRACED("dbcsstr",Pstr,Pstrlen);                                   //~va1cR~
UTRACED("dbcstbl",Simdbcs,Pstrlen);                                //~va1cR~
          	dbcssz=XESUB_DBCSSPLITCTR(Simdbcs,len,0);              //~va1cR~
UTRACEP("dbcssz=%d\n",dbcssz);                                     //~va1cR~
            memcpy(Skeyinfo.mbstr,Pstr,(UINT)dbcssz);              //~va1cR~
            if (dbcssz==UDBCSCHK_DBCSSZ)    //2byte dbcs           //~va1cR~
            	nlsopt=KBDNLS_F2L_DBCS2ND;                         //~va1cR~
            else                                                   //~va1cR~
            if (dbcssz==UDBCSCHK_GB4SZ)                            //~va1cR~
            	nlsopt=KBDNLS_GB4;//later DBCS1ST will be on       //~va1cR~
            else                                                   //~va1cR~
            if (dbcssz==UDBCSCHK_SS3SZ)                            //~va1cR~
            	nlsopt=KBDNLS_SS3;                                 //~va1cR~
            len-=dbcssz;                                           //~va1cR~
        	memcpy(Simstr,Pstr+dbcssz,(UINT)len);	//save ie commit string//~va1cR~
          }                                                        //~va1cR~
          else                                                     //~va1cR~
#endif                                                             //~va1cR~
          {                                                        //~va1cR~
        	len--;                                                 //~vXXEI~
        	memcpy(Simstr,Pstr+1,(UINT)len);	//save ie commit string//~vXXER~
          }                                                        //~va1cR~
        	Simstrlen=len;                                         //~vXXER~
        	Simnextpos=0;                                          //~vXXER~
        }                                                          //~vXXEI~
#ifdef UTF8SUPPH                                                   //~va00I~
//      if (*Sutf8str)                                             //~va00I~//~va0TR~
        if (Sutf8stroffs<Sutf8strlen)    //utf8string was saved                 //~va0TI~//~va0VR~
        {                                                          //~va00I~
//      	strncpy(Skeyinfo.u8str,Sutf8str,UTF8_MAXCHARSZMAX);    //~va00I~//~va0TR~
            u8chsz=UTF8CHARLEN(*Sutf8str);                         //~va0TI~
          if (u8chsz)	//valid utf8                               //~va0TI~
          {                                                        //~va0TI~
        	UmemcpyZ(Skeyinfo.u8str,Sutf8str,u8chsz);              //~va0TI~
           if (u8chsz>1)                                           //~va0VI~
           {                                                       //~va0VI~
            if (Simef2lerr)                                        //~va3DR~
            {                                                      //~va3DI~
				opt=XXEIMEERRO_NOTERR*(*Pstr!=XEUTF_ERRREPCH_F2LFILE);//~va3DI~
            	xxe_imef2lerr(opt,&Skeyinfo,Sutf8str,u8chsz);      //~va3DR~
        		Simstrlen=0;	//until Sutfstr exausted           //~va3DI~
            }                                                      //~va3DI~
            else                                                   //~va3DI~
            if (*Simdbcs==UDBCSCHK_DBCS1ST)                        //~va0VR~
            	Skeyinfo.bNlsShift=KBDNLS_F2L_DBCS1ST;             //~va00I~
            else                                                   //~va00I~
            	Skeyinfo.bNlsShift=KBDNLS_F2L_SBCS;                //~va00I~
           }                                                       //~va0VR~
            Skeyinfo.bNlsShift|=nlsopt;                            //~va1cR~
            Sutf8stroffs+=u8chsz;                                  //~va0TI~
            if (Sutf8stroffs>=Sutf8strlen)                         //~va0VI~
                Sutf8strlen=0;                                     //~va0VI~
          }                                                        //~va0TI~
          else                                                     //~va0TI~
            Sutf8strlen=0;                                         //~va0TI~
 		dprintf("wxe_kbdmsg 1st u8str=%s,keyinfu8=%s,nextoffs=%d,shift=%x\n",Sutf8str,Skeyinfo.u8str,Sutf8stroffs,Skeyinfo.bNlsShift);//~va0VR~
        }                                                          //~va00I~
#endif                                                             //~va00I~
    }                                                              //~v62NI~
    else                                                           //~v62NI~
    {                                                              //~v62NI~
    	Skeyinfo.chScan=(Pscanchar>>8);                            //~v62NI~
    	Skeyinfo.chChar=(Pscanchar&255);                           //~v62NI~
    }                                                              //~v62NI~
    Sdatasw=1;      //Skeyinfo  has data                           //~vXXEI~
  	Gwxestat|=GWXES_KBDEVENT;	//for wxe_setcurpos                //~va7SI~
	rc=wxe_xecall(WXE_REQ_KEYEVENT,0);                             //~v62NR~
  	Gwxestat&=~GWXES_KBDEVENT;	//for wxe_setcurpos                //~va7SI~
UTRACEP("wxe_kbdmsg rc=%d\n",rc);                                  //~2914I~
UTRACED("wxe_kbdmsg skeyinfo",&Skeyinfo,sizeof(Skeyinfo));         //~va1cR~
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
    	if ((!sc && !ch)&& (!(pft->FTcmd)||!(*(pft->FTcmd)))) //parm exist or no key defined//~v672I~
        {                                                          //~v672I~
			uerrmsgbox("No key nand cmd is defined for func %s","機\x94\\ %s にキー、コマンドが割り当てられていません",pft->FTnamee);//~v672R~
        	rc=4;                                                  //~v672I~
        }                                                          //~v672I~
        else                                                       //~v672I~
		rc=wxe_strcmd(pft->FTcmd,Pcmdparm);                        //~2A20I~
    }                                                              //~v672I~
    else	//func key input                                       //~2A20I~
    {                                                              //~2A20I~
        if (pft->FTkflag[0] & FTSHIFT)  //effective with shift key(same key value with and without shift)//~2A20R~
		    Skeyinfo.fsState=(KBDSTF_RIGHTSHIFT|KBDSTF_LEFTSHIFT); //~vXXEI~
        else                                                       //~2A20R~
		    Skeyinfo.fsState=0;		//no modifyer info required,scan+ch means func//~vXXEI~
    	Skeyinfo.fbStatus=0;	//clear SHIFT_KEY_IN               //~v76fI~
    	Skeyinfo.chScan=sc;                                        //~vXXER~
    	Skeyinfo.chChar=ch;                                        //~vXXER~
	    Sdatasw=1;		//Skeyinfo  has data                       //~vXXEI~
        rc=wxe_xecall(WXE_REQ_KEYEVENT,0);                         //~vXXER~
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
	rc=wxe_xecall(WXE_REQ_KEYEVENT,0);                             //~vXXER~
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
  if (!Spwxei->WXEImaxrow)	//before readini                       //~vXXEI~
  {                                                                //~vXXEI~
	    *Ppcol=MAXCOL;                                             //~vXXEI~
    	*Pprow=MAXROW;                                             //~vXXEI~
  }                                                                //~vXXEI~
  else                                                             //~vXXEI~
  {                                                                //~vXXEI~
    *Ppcol=(USHORT)Spwxei->WXEImaxcol;                             //~v440R~
    *Pprow=(USHORT)Spwxei->WXEImaxrow;                             //~v440R~
  }                                                                //~vXXEI~
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
		UTRACEP("%s:wxe_onsize row=%d,col=%d\n",UTT,Prow,Pcol);                 //~vXXER~//~vbu0R~
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
// chk csrmove by kbd operation(called from uviosetcurpos)         //~va7DI~
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
	Spwxei->WXEIoldcsrposy=Spwxei->WXEIcsrposy;                    //~vXXEI~
	if (Prow!=Spwxei->WXEIcsrposy)                                 //~v440R~
    {                                                              //~v440I~
    	Spwxei->WXEIcsrmovesw|=WXEICSR_CHANGEROW;                  //~vXXER~
    	Spwxei->WXEIcsrposy=Prow;                                  //~v440R~
    }                                                              //~v440I~
	if (Pcol!=Spwxei->WXEIcsrposx)                                 //~v440R~
    {                                                              //~v440I~
    	Spwxei->WXEIcsrposx=Pcol;                                  //~v440R~
    	Spwxei->WXEIcsrmovesw|=WXEICSR_CHANGECOL; 	//col cahnged  //~vXXER~
    }                                                              //~v440I~
  	if (Gwxestat & GWXES_KBDEVENT)	//for wxe_setcurpos            //~va7DR~
    	if (Spwxei->WXEIcsrmovesw)                                 //~va7DR~
	    	Spwxei->WXEIcsrmovesw|=WXEICSR_CHANGEBYKBD; 	//col cahnged//~va7DI~
	return 0;                                                      //~v440I~
}//wxe_setcurpos                                                   //~v440I~
//*************************************************************    //~v440I~
//*************************************************************    //~v440I~
int  wxe_getcurtype(void * /*PVIOCURSORINFO*/ pviocursorInfo)      //~v440I~
{                                                                  //~v440I~
	PVIOCURSORINFO pci;                                            //~v440I~
//***********************                                          //~v440I~
	pci=(PVIOCURSORINFO)pviocursorInfo;                            //~v440I~
    pci->yStart=Spwxei->WXEIcsrhstart;                             //~v440I~
    pci->cEnd  =Spwxei->WXEIcsrhend;                               //~v440R~
    if (Spwxei->WXEIcsrvisible)                                    //~2914I~
	    pci->attr=0;  //0:normal,-1:hidden                         //~2914R~
    else                                                           //~2914I~
	    pci->attr=0xffff /*-1*/;  //0:normal,-1:hidden             //~vXXER~
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
    newvisible=(pci->attr!=0xffff /*-1*/);  //0:normal,-1:hidden   //~vXXER~
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
//int  wxe_uviogetwork(UCHAR *Pbuffc,USHORT *Pbuffa,UCHAR *Plineupdate)//~vb4rR~
int  wxe_uviogetwork(UCHAR *Pbuffc,USHORT *Pbuffa,UCHAR *Plineupdate,int *Plineopt)//~vb4rI~
{                                                                  //~v440I~
//***********************                                          //~v440I~
    Spwxei->WXEItext=Pbuffc;         //at uviogetwork              //~v440R~
    Spwxei->WXEIattr=Pbuffa;                                       //~v440R~
    Spwxei->WXEIlineupdate=Plineupdate;                            //~v440R~
    Spwxei->WXEIlineopt=Plineopt;                                  //~vb4rI~
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
//input maxcol=8 and col 8-15 is set highligh color                //~vXXEI~
        for (ii=0;ii<maxpal;ii++)                                  //~v440I~
        {                                                          //~2905I~
    		colno=(UINT)ppal->acolor[ii];   //color reg of the pallette//~2905R~
    		Spwxei->WXEIpallette[ii]=(SHORT)colno;                 //~2905I~
       		Spwxei->WXEIpalrgb[ii]=XE2RGB(colno);                  //~vXXEI~
        }                                                          //~2905I~
//      usetpalettecolor(maxpal,Spwxei->WXEIpalrgb);               //~vXXER~//~va72R~
        usetpalettecolor(maxpal,(int*)(Spwxei->WXEIpalrgb));       //~va72I~
        break;                                                     //~v440I~
	case 2:		//brink or highlight background                    //~v440I~
    	break;	//ignore request                                   //~v440I~
    default:                                                       //~v440I~
        return ERROR_VIO_INVALID_PARMS;                            //~v440I~
    }//switch by reqtype                                           //~v440I~
	return 0;                                                      //~v440I~
}//wxe_uviosetstate                                                //~v440I~
//*************************************************************    //~v440I~
//get color palleteno fo color dialog sample color                 //~vXXEI~
//*************************************************************    //~vXXEI~
int  wxe_getsamplecolor(char *Pattrtbl)                            //~vXXEI~
{                                                                  //~vXXEI~
	char *pc;                                                      //~vXXEI~
//***********************                                          //~vXXEI~
    pc=Pattrtbl;                                                   //~vXXEI~
    *pc++=Gattrtbl[COLOR_BCLIENT];                                 //~vXXER~
    *pc++=Gattrtbl[COLOR_ECLIENT];                                 //~vXXER~
    *pc++=Gattrtbl[COLOR_ELINENO];                                 //~vXXER~
    return ((ULONG)pc-(ULONG)Pattrtbl);                            //~vXXEI~
}//wxegetsamplecolor                                               //~vXXEI~
//*************************************************************    //~v440I~
int  wxe_readkbd(void /* KBDKEYINFO */ *Ppkbdinf,int Pwait)        //~v62NR~
{                                                                  //~v440I~
	int rc=1;                                                      //~vXXER~
    PKBDKEYINFO pki;                                               //~vXXER~
#ifdef UTF8SUPPH                                                   //~va0TI~
	int u8chsz;                                                    //~va0TI~
	int dbcssz,nlsopt=0;                                           //~va1cR~
    char *pu8,*pdbcs;                                              //~va0TI~//~va0VR~
#endif                                                             //~va0TI~
//***********************                                          //~v440I~
UTRACEP("wxe_readkbd entry imsstrlen=%d,imnextpos=%d,utf8strlen=%d,utf8nextpos=%d\n",Simstrlen,Simnextpos,Sutf8strlen,Sutf8stroffs);//~va3DR~
	pki=(PKBDKEYINFO)Ppkbdinf;                                     //~v62NI~
    memcpy(pki,&Skeyinfo,sizeof(KBDKEYINFO));                      //~vXXER~
    if (!Sdatasw)                                                  //~vXXEI~
    {                                                              //~vXXEI~
        pki->bNlsShift=0;                                          //~va0VI~
		memset(pki->u8str,0,sizeof(pki->u8str));                   //~va0VR~
#ifdef UTF8UCS4                                                    //~va3DI~
        if (Simef2lerr)                                            //~va3DI~
        {                                                          //~va3DI~
	        if (Sutf8strlen>Sutf8stroffs)//remains utf8str         //~va3DI~
            {                                                      //~va3DI~
				pu8=Sutf8str+Sutf8stroffs;                         //~va3DI~
	         	u8chsz=UTF8CHARLEN(*pu8);                          //~va3DI~
                if (u8chsz)	//valid                                //~va3DI~
                {                                                  //~va3DI~
                	if (u8chsz>1)	//not ascii                    //~va3DI~
            			xxe_imef2lerr(XXEIMEERRO_CONT,pki,pu8,u8chsz);//~va3DI~
        			UmemcpyZ(pki->u8str,pu8,u8chsz);               //~va3DI~
	            	Sutf8stroffs+=u8chsz;                          //~va3DI~
					UTRACEP("wxe_readkbd keyinfu8=%s,totlen=%d,nextoffs=%d\n",pki->u8str,Sutf8strlen,Sutf8stroffs);//~va3DI~
					dprintf("wxe_readkbd keyinfu8=%s,totlen=%d,nextoffs=%d\n",pki->u8str,Sutf8strlen,Sutf8stroffs);//~va3DI~
			        if (Sutf8stroffs>=Sutf8strlen)                 //~va3DI~
            		    Simef2lerr=Sutf8strlen=0;                  //~va3DI~
                }                                                  //~va3DI~
                else	//invalidutf8                              //~va3DI~
                {                                                  //~va3DI~
            		Simef2lerr=Sutf8strlen=0;                      //~va3DI~
                    rc=0;                                          //~va3DI~
                }                                                  //~va3DI~
            }                                                      //~va3DI~
            else                                                   //~va3DI~
            {                                                      //~va3DI~
            	Simef2lerr=Sutf8strlen=0;                          //~va3DI~
                rc=0;                                              //~va3DI~
            }                                                      //~va3DI~
        }                                                          //~va3DI~
        else                                                       //~va3DI~
#endif                                                             //~va3DI~
        if (Simstrlen)  //dbcs str                                 //~vXXER~
        {                                                          //~vXXER~
            if (Simnextpos>=Simstrlen)                             //~vXXER~
            {                                                      //~vXXER~
                Simstrlen=0;                                       //~vXXER~
                rc=0;                                              //~vXXER~
            }                                                      //~vXXER~
            else                                                   //~vXXER~
            {                                                      //~va00I~
                pki->chChar=*(Simstr+Simnextpos++);                //~vXXER~
#ifdef UTF8SUPPH                                                   //~va00I~
				dprintf("wxe_readkbd UTF8=%s,offs=%d\n",Sutf8str,Sutf8stroffs);//~va0TR~//~va0VR~
              if (Gxxestat & GXXES_DBCSREAD)    //return dbcs at once//~va1cR~
              {                                                    //~va1cR~
                	Simnextpos--;                                  //~va1cR~
UTRACED("imdata next",Simstr+Simnextpos,Simstrlen-Simnextpos);     //~va1cR~
UTRACED("imdbcs next",Simdbcs+Simnextpos,Simstrlen-Simnextpos);    //~va1cR~
		            pdbcs=Simdbcs+Simnextpos; //dbcs start from 1  //~va1cR~
                    dbcssz=XESUB_DBCSSPLITCTR(pdbcs,Simstrlen-Simnextpos,0);//~va1cR~
                    memcpy(pki->mbstr,Simstr+Simnextpos,(UINT)dbcssz);//~va1cR~
                    if (dbcssz==UDBCSCHK_DBCSSZ)                   //~va1cR~
                        nlsopt=KBDNLS_F2L_DBCS2ND;                 //~va1cR~
                    else                                           //~va1cR~
                    if (dbcssz==UDBCSCHK_GB4SZ)                    //~va1cR~
                        nlsopt=KBDNLS_GB4;//later DBCS1ST will be on//~va1cR~
                    else                                           //~va1cR~
                    if (dbcssz==UDBCSCHK_SS3SZ)                    //~va1cR~
                        nlsopt=KBDNLS_SS3;                         //~va1cR~
                    else                                           //~va1cR~
                        dbcssz=1;    //avoid loop by dbcssz=0 when trans err//~va1cR~
                    Simnextpos+=dbcssz;                            //~va1cR~
              }                                                    //~va1cR~
              else                                                 //~va1cR~
                pdbcs=Simdbcs+Simnextpos; //dbcs start from 1  //~va0TR~//~va0VI~
               	if (*pdbcs==UDBCSCHK_DBCS2ND)                      //~va0VI~
//            		Skeyinfo.bNlsShift=KBDNLS_F2L_DBCS2ND;             //~va00I~//~va0TR~//~va0VR~
              		pki->bNlsShift=KBDNLS_F2L_DBCS2ND;                 //~va0TI~//~va0VR~
                else                                               //~va0VI~
              	if (Sutf8strlen>Sutf8stroffs)                      //~va0TR~
              	{                                                  //~va0TR~
					pu8=Sutf8str+Sutf8stroffs;                     //~va0TR~
	         		u8chsz=UTF8CHARLEN(*pu8);                      //~va0TR~
                	if (u8chsz)	//valid                            //~va0TR~
                	{                                              //~va0TR~
                      if (u8chsz>1)	//not ascii	                   //~va0VI~
                      {                                            //~va0VI~
               			if (*pdbcs==UDBCSCHK_DBCS1ST)              //~va0TR~//~va0VR~
                        {                                          //~va1cR~
            				pki->bNlsShift=KBDNLS_F2L_DBCS1ST;     //~va0TR~
                        }                                          //~va1cR~
                    	else                                       //~va0TR~
		            		pki->bNlsShift=KBDNLS_F2L_SBCS;        //~va0TR~
                      }                                            //~va0VI~
        				UmemcpyZ(pki->u8str,pu8,u8chsz);           //~va0TR~
	            		Sutf8stroffs+=u8chsz;                      //~va0TR~
		            	pki->bNlsShift|=nlsopt;                    //~va1cR~
						dprintf("wxe_readkbd keyinfu8=%s,nNlsShift=%02x,nextoffs=%d,dbcstbl=%x\n",pki->u8str,pki->bNlsShift,Sutf8stroffs,*pdbcs);//~va0TR~//~va0VR~
			            if (Sutf8stroffs>=Sutf8strlen)             //~va0VI~
            			    Sutf8strlen=0;                         //~va0VI~
                	}                                              //~va0TR~
                	else                                           //~va0TR~
                    {                                              //~va3DI~
               	 		Sutf8strlen=0;                             //~va0TR~
                        rc=0;                                      //~va3DI~
                    }                                              //~va3DI~
             	}//remains utf8                                    //~va0TR~
             	else                                               //~va0TR~
                {                                                  //~va3DI~
               		Sutf8strlen=0;                                 //~va0TR~
                    rc=0;                                          //~va3DI~
                }                                                  //~va3DI~
#endif                                                             //~va00I~//~va0TM~
        	}                                                      //~va00I~
        }                                                          //~vXXER~
    }                                                              //~vXXEI~
//  dprintf("readkbd imlen=%d,rc=%d,scan=%x,char=%x,stat=%x,imlen=%d,next=%d\n",Simstrlen,rc,pki->chScan,pki->chChar,pki->fsState,Simstrlen,Simnextpos);//~vXXER~
UTRACED("outkeyinf",pki,sizeof(KBDKEYINFO));                       //~va1cR~
    Sdatasw=0;                                                     //~vXXEI~
    return rc;                                                     //~v62NI~
}//wxe_readkbd                                                     //~v440I~
#ifndef XXE                                                        //~vXXEI~
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
int  wxe_geteventno(int *Ppeventno)                                //~v440I~
{                                                                  //~v440I~
//***********************                                          //~v440I~
	return 0;                                                      //~v440I~
}//wxe_geteventno                                                  //~v440I~
//*************************************************************    //~v440I~
//*************************************************************    //~v440I~
int  wxe_uerrmsgstdo(char *Ppmsg)                                  //~v440I~
{                                                                  //~v440I~
//***********************                                          //~v440I~
    if (Sxeinitsw==WXE_REQ_INIT)	//init end                     //~2B30I~
		Spwxei->WXEIerrmsg=wxeenqmsg(Ppmsg,Spwxei->WXEIerrmsg);    //~2A07R~
    else                                                           //~2B30I~
    	umsgbox(Ppmsg);                                            //~2B30I~
	return 0;                                                      //~v440I~
}//wxe_uerrmsgstdo                                                 //~v440I~
#endif                                                             //~vaf5I~
//*************************************************************    //~v440I~
//*************************************************************    //~v440I~
int  wxe_uerrexitstdo(char *Ppmsg)                                 //~v440I~
{                                                                  //~v440I~
//***********************                                          //~v440I~
//  umsgbox(Ppmsg);                                                //~vaf5R~
    umsgbox(Ppmsg,MB_OK);                                          //~vaf5I~
	exit(24);                                                      //~2901R~
}//wxe_uerrexitstdo                                                //~v440I~
//*************************************************************    //~vaf5I~
//*************************************************************    //~vaf5I~
int  wxe_uerrexitmsgbox(char *Ppmsg)                               //~vaf5I~
{                                                                  //~vaf5I~
//***********************                                          //~vaf5I~
//  umsgbox(Ppmsg);                                                //~vaf5I~
    umsgboxlocalemsg(Ppmsg,MB_OK);                                 //~vaf5I~
	exit(24);                                                      //~vaf5I~
}//wxe_uerrexitstdo                                                //~vaf5I~
#ifndef XXE                                                        //~vaf5I~
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
    *(newmsg+len1++)='\n';                                         //~v440I~
    *(newmsg+len1++)=0;                                            //~v440I~
	return newmsg;                                                 //~2A07R~
}//wxeenqmsg                                                       //~v440I~
//*************************************************************    //~2929I~
//*tell charset changed                                            //~2929I~
//*ret 1:cp changed                                                //~2929I~
//*************************************************************    //~2929I~
int  wxe_setcsrpos(int Prow,int Pcol)                              //~2929I~
{                                                                  //~2929I~
//***********************                                          //~2929I~
	return scrsetcsrpos(Prow,Pcol);                                //~2929I~
}//wxe_setcsrpos                                                   //~2929I~
#endif                                                             //~vXXEI~
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
    if (pcw->UCWtype==UCWTFILE) //vertical and horizontal          //~v69jI~
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
    if (ctrlsw)  //with control                                    //~v69hI~
    {                                                              //~2A13I~
//    	if (scrtype!=2)	//file/dir only                            //~v69jR~
    	if (!scrtype)                                              //~v69jI~
        	return 0;                                              //~v55bI~
		if (Pdest<0)	//forward                                  //~2A13I~
        	funcid=FUNCID_BOTTOM;		//file end                 //~2A13M~
        else                                                       //~2A13I~
        	funcid=FUNCID_TOP;          //file top page            //~2A13M~
    }                                                              //~2A13I~
    else                                                           //~2A13I~
//  if (ctrlsw)  //with control                                    //~v69hR~
    if (shiftsw)  //shift                                          //~v69hI~
    {                                                              //~2A20I~
    	if (scrtype!=2)	//file/dir only                            //~v55bI~
        	return 0;                                              //~v55bI~
        sprintf(cmdparm,"%d",Pscrollctr);                          //~2A20I~
		if (Pdest<0)	//forward                                  //~2A20I~
        	funcid=FUNCID_PGRIGHT;                                 //~2A20I~
        else                                                       //~2A20I~
        	funcid=FUNCID_PGLEFT;                                  //~2A20I~
    }                                                              //~2A20I~
    else                                                           //~2A20I~
    {                                                              //~2A13I~
    	if (!scrtype)	//file/dir/filelist only                   //~v55bI~
        	return 0;                                              //~v55bI~
        sprintf(cmdparm,"%d",Pscrollctr);                          //~2A20I~
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
//	rc=wxe_funccall(funcid,cmdparm);                               //~v69mR~
  	rc=wxe_funccall(-funcid,cmdparm);	//minus:ignore cmdparm if func key defined//~v69mI~
    if (!rc)                                                       //~v58iI~
	    if (oldmaxline && pcw->UCWmaxline<pcw->UCWheight)          //~v58iI~
    		rc=1;                                                  //~v58iI~
//  wxe_movecsr(oldrow,oldcol);                                    //~v76nR~
    return rc;                                                     //~2A13I~
}//wxe_scroll                                                      //~2A13I~
#ifdef AAA  //logic use scrollock on and left/right key simulation //~v69iI~
//*************************************************************    //~v69bI~
//*horizontal scroll by mouse(detected vk_left/right after scrolllock up in short time//~v69bI~
//*************************************************************    //~v69bI~
void wxe_scrollh(int Pscrollctr,UINT nChar)                        //~v69bI~
{                                                                  //~v69bI~
//***********************                                          //~v69bI~
	if (Pscrollctr)                                                //~v69bI~
    {                                                              //~v69bI~
	    Gwxescrollctr=Pscrollctr;                                  //~v69bI~
		Gwxestat|=GWXES_MOUSEHSCROLL;    	//horizontal scroll by mouse//~v69bI~
	}                                                              //~v69bI~
    else                                                           //~v69bI~
		Gwxestat&=~GWXES_MOUSEHSCROLL;    	//horizontal scroll by mouse//~v69bI~
    return;                                                        //~v69bI~
}//wxe_scrollh                                                     //~v69bI~
#endif                                                             //~v69iI~
//*************************************************************    //~v69iI~
//*horizontal scroll by mouse WM_HSCROLL msg                       //~v69iI~
//*************************************************************    //~v69iI~
int wxe_scrollhbar(int Pscrollctr,int Pdest)                       //~v69iI~
{                                                                  //~v69iI~
	PUCLIENTWE pcw;                                                //~v69iI~
	int  rc,funcid,oldrow,oldcol;                                  //~v69iI~
    char cmdparm[16];                                              //~v69iI~
//***********************                                          //~v69iI~
UTRACEP("wxe_scrollhbar ctr=%d,dest=%d\n",Pscrollctr,Pdest);       //~v69iI~
    oldrow=Gcsrposy;                                               //~v69iI~
    oldcol=Gcsrposx;                                               //~v69iI~
    *cmdparm=0;                                                    //~v69iI~
    pcw=scrgetcw(0); 	//current active                           //~v69iI~
    if (pcw->UCWtype!=UCWTFILE)                                    //~v69iI~
        return 0;                                                  //~v69iI~
    sprintf(cmdparm,"%d",Pscrollctr);                              //~v69iI~
	if (Pdest<0)	//left                                         //~v69iI~
        funcid=FUNCID_PGLEFT;                                      //~v69iI~
    else                                                           //~v69iI~
        funcid=FUNCID_PGRIGHT;                                     //~v69iI~
    Gwxestat|=GWXES_SCROLLBYMOUSE; //tell to getscrollsz it is scroll by mouse//~v69mI~
	Gwxescrollctr=Pscrollctr;                                      //~v69mI~
//  rc=wxe_funccall(funcid,cmdparm);                               //~v69mR~
    rc=wxe_funccall(-funcid,cmdparm);//-:ignore cmd parm if func key defined//~v69mI~
	wxe_movecsr(oldrow,oldcol);                                    //~v69iI~
    return rc;                                                     //~v69iI~
}//wxe_scrollhbar                                                  //~v69iI~
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
            {                                                      //~vXXEI~
//              if (col<=pcw->UCWlinenosz)                         //~v53bR~
                if (col==pcw->UCWlinenosz)                         //~v53bI~
                {                                                  //~v53bI~
                  if (pfc->UFCleft) //scrollable                   //~v53bI~
                    posid|=MEC_LEFT;                               //~v5a0R~
                }                                                  //~v53bI~
                else                                               //~v5a0R~
                if (col==pcw->UCWwidth-1)                          //~v5a0R~
                    posid|=MEC_RIGHT;                              //~v5a0R~
            }                                                      //~vXXEI~
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
    dprintf("%s:Prow=%d,Pcol=%d,UCWtype=%d,posid=%x\n",UTT,Prow,Pcol,pcw->UCWtype,posid);//~vb74R~
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
    wxe_kbdmsg(WXEKBDMSG_KEYDOWN,DMYSCANCODE|cmdid,0,0);           //~vXXER~
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
    if (Prow==PANL300DIR||Prow==PANL300CURRENT)                    //~vXXER~
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
//  int did;                                                       //~vXXER~
    char cmdnm[2],fnm[_MAX_PATH];                                  //~v54wR~
//******************************                                   //~v54vI~
//  if (Prow==PANL300DRIVE)                                        //~vXXER~
//  {                                                              //~vXXER~
//    did=pan300drawdid(Ppcw);                                     //~vXXER~
//    if (!did)                                                    //~vXXER~
//        return 0;   //nothing occur                              //~vXXER~
//    fnm[0]=did;                                                  //~vXXER~
//    fnm[1]=':';                                                  //~vXXER~
//    fnm[2]=0;                                                    //~vXXER~
//  }                                                              //~vXXER~
//  else                                                           //~vXXER~
//  {                                                              //~vXXER~
    getfldinput(Ppcw,Prow,0,fnm);                                  //~v54wR~
    if (!*fnm)                                                     //~v54wI~
        return 0;   //nothing occur                                //~v54wI~
//  }                                                              //~vXXER~
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
//  char *pc;                                                      //~v5a0I~//~vaa7R~
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
//  	pc=plh->ULHdata+pos;                                       //~v5a0R~//~vaa7R~
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
	int lcmd,stat=0;                                               //~vXXER~
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
    stat|=WXEKBDMSG_KEYDOWN;                                       //~vXXER~
    return wxe_kbdmsg(stat,DMYSCANCODE|lcmd,0,0);		//1:repeat,0:flag//~vXXER~
}//wxe_belcmd                                                      //~3102I~
//*************************************************************    //~v56jI~
//*************************************************************    //~v62NI~
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
//*************************************************************    //~vXXEI~
//*beep support                                                    //~vXXEI~
//*************************************************************    //~vXXEI~
int xxe_beep(void)                                                 //~vXXEI~
{                                                                  //~vXXEI~
#ifdef OPTGTK3                                                     //~vbp5I~
#if GTK_CHECK_VERSION(3,22,0)	//gtk_ui_manager was deprecated    //~vbp5I~
    GdkDisplay *pdisp;                                             //~vbp5I~
#endif                                                             //~vbp5I~
//************************************                             //~vbp5I~
    dprintf("xxemain_scrinit\n");                                  //~vbp5I~
#if GTK_CHECK_VERSION(3,22,0)	//gtk_ui_manager was deprecated    //~vbp5I~
    pdisp=gdk_display_get_default();                               //~vbp5I~
    gdk_display_beep(pdisp);                                       //~vbp5R~
#else                                                              //~vbp5I~
    gdk_beep();                                                    //~vbp5I~
#endif                                                             //~vbp5I~
#else                                                              //~vbp5I~
    gdk_beep();                                                    //~vXXER~
#endif                                                             //~vbp5I~
    return 0;                                                      //~vXXEI~
}//xxe_beep                                                        //~vXXEI~
//*************************************************************    //~vXXEI~
//*beep support                                                    //~vXXEI~
//*************************************************************    //~vXXEI~
void xxe_scrdisp(void)                                             //~vXXER~
{                                                                  //~vXXEI~
	scrdisp();                                                     //~vXXEI~
    return;                                                        //~vXXEI~
}//xxe_scrdispreq                                                  //~vXXEI~
//*************************************************************    //~v79zI~
//*CJK multibyte support init                                      //~v79zI~
//*************************************************************    //~v79zI~
int xxe_kbdwcinit(int Popt,int Pkbdstat,ULONG Pcodepage,UCHAR *Pcharset)//~v79zR~
{                                                                  //~v79zI~
#ifdef UTF8SUPPH                                                   //~va0UI~
    ULONG pl2uconverters;                                          //~va0UR~
#endif                                                             //~va0UI~
//***********************                                          //~v79zI~
//#ifdef AAA   -Nm option process at xe                            //~vbu0R~
#ifdef AAA   //-Nm option process at xe                            //~vbu0I~
    if (Pkbdstat & UDCWCIO_KBDNOUTF8)   //input lang is UTF8 but return byte by byte//~v79zI~
        Gxxestat|=GXXES_KBDNOUTF8;                                 //~v79zI~
    else                                                           //~v79zI~
#endif                                                             //~vbtaI~
    {                                                              //~v79zI~
    	if (Pkbdstat & UDCWCIO_KBDUTF8)   	//input lang is UTF8   //~v79zI~
        	Gxxestat|=GXXES_KBDIMEICONV;    //no use locale_from_utf8//~v79zI~
    }                                                              //~v79zI~
    if (Pkbdstat & UDCWCIO_FORCELOCALE)   	//converter parameter specified//~v79zI~
        Gxxestat|=GXXES_KBDIMEICONV;                               //~v79zI~
#ifdef UTF8SUPPH                                                   //~va0UI~
    if (Pkbdstat & UDCWCIO_DBCSREAD)    //input lang is UTF8 but return byte by byte//~va1cR~
        Gxxestat|=GXXES_DBCSREAD;                                  //~va1cR~
  	udbcschk_getbaseconverter(0,&pl2uconverters,&Gpxxedbcstbl);//converter is same as Pcodepage//~va0UR~
#endif                                                             //~va0UM~
    if (Pcodepage)                                                 //~v79zI~
    	Gconverters=Pcodepage;      //iconv_t[2]                   //~v79zI~
    UstrncpyZ(Gcharset,Pcharset,MAXLOCALESZ);                      //~v79zI~
UTRACEP("xxe_kbdwcinit Popt=%x,Gxxestat=%x\n",Popt,Gxxestat);      //~v79zI~
	return 0;                                                      //~v79zI~
}//xxe_kbdwcinit                                                   //~v79zI~
//*************************************************************    //~v79zI~
//*CJK multibyte support init                                      //~v79zI~
//*************************************************************    //~v79zI~
int xxe_imeconv(int Popt,UCHAR *Pstr,int Pstrlen,UCHAR *Ppmbs,int Poutbuffsz,int *Ppmbslen)//~v79zI~
{                                                                  //~v79zI~
#ifdef UTF8SUPPH                                                   //~va0VR~
	int opt,rc;                                                    //~va0VI~
#else                                                              //~va0VI~
	int opt,chklen,rc,repctr;                                      //~v79zR~
    ULONG pconverters[3];                                          //~v79zI~
#endif                                                             //~va0VI~
//***********************                                          //~v79zI~
#ifdef UTF8SUPPH                                                   //~va00I~
//  *Sutf8str=0;                                                   //~va00I~//~va0TR~
    Sutf8strlen=0;                                                 //~va0TI~
#endif                                                             //~va00I~
    if (Pstrlen==1                                                 //~v79zI~
    )                                                              //~v79zI~
    {                                                              //~v79zI~
        *Ppmbs=*Pstr;                                              //~v79zI~
        *Ppmbslen=1;                                               //~v79zI~
        rc=0;                                                      //~v79zI~
    }                                                              //~v79zI~
    else                                                           //~v79zI~
    {                                                              //~v79zI~
#ifdef UTF8SUPPH                                                   //~va0VI~
		opt=UTFCVO_ERRREP|('?'<<8);                                //~va0VI~
//      Pstr="\xc2\xa4"; Pstrlen=2; //TODO test                    //~vbp5I~//~vbtbR~
		rc=utfcvf2l(opt,Ppmbs,Pstr,Pstrlen,0/*pchklen*/,Ppmbslen,0/*pcharwidth*/);//~va0VI~
        if (rc==UTFCVRC_ALLASCII)                                  //~va0VI~
			memset(Simdbcs,0,*Ppmbslen);                           //~va0VI~
        else                                                       //~va0VI~
			xxe_setdbcstbl(Ppmbs,Simdbcs,*Ppmbslen);               //~va0VR~
#else                                                              //~va0VI~
        pconverters[HICONV_CPFROM]=0;                              //~v79zR~
        pconverters[HICONV_CPTO]=Gconverters;                      //~v79zR~
#ifdef UTF8SUPPH                                                   //~va0UM~
        pconverters[HICONV_DBCSSTARTER]=(ULONG)Gpxxedbcstbl;       //~va0UI~
#else                                                              //~va0UM~
        pconverters[HICONV_DBCSSTARTER]=(ULONG)Gpdbcstbl;          //~v79zR~
#endif                                                             //~va0UI~
        opt=UCVEXTO_FROMUTF8;          //utf8 to MB                //~v79zR~
//      rc=ucvext_iconva2as(opt,pconverters,Pstr,0/*dbcs*/,Pstrlen,Ppmbs,Poutbuffsz,&chklen,Ppmbslen,'?'/*errrep*/,&repctr);//~v79zR~//~va0TR~
        rc=ucvext_iconva2as(opt,pconverters,Pstr,Simdbcs,Pstrlen,Ppmbs,Poutbuffsz,&chklen,Ppmbslen,'?'/*errrep*/,&repctr);//~va0TI~
#endif                                                             //~va0VI~
#ifdef UTF8SUPPH                                                   //~va00I~
#ifdef UTF8UCS4                                                    //~va3DI~
        Simef2lerr=rc;	//to set KBDNLS_F2L_ERR                    //~va3DI~
#else                                                              //~va3DI~
        if (!rc)                                                   //~va00I~
#endif                                                             //~va3DI~
        {                                                          //~va0TI~
//  		UmemcpyZ(Sutf8str,Pstr,Pstrlen);                       //~va00I~//~va0TR~
            Sutf8strlen=min(Pstrlen,sizeof(Sutf8str)-1);           //~va0TI~
    		UmemcpyZ(Sutf8str,Pstr,Sutf8strlen);                   //~va0TI~
            Sutf8stroffs=0;                                        //~va0TI~
        }                                                          //~va0TI~
#endif                                                             //~va00I~
    }                                                              //~v79zI~
    return rc;                                                     //~v79zI~
}//xxe_imeconv                                                     //~v79zR~
//===============================================================================//~va3DI~
//process f2lerr input utf8(not ascii)                             //~va3DI~
//rc:0 no cverr, 1:err sbcs,2:err dbcs                             //~va3DI~
//===============================================================================//~va3DI~
int xxe_imef2lerr(int Popt,KBDKEYINFO *Pkeyinfo,char *Ppu8,int Pu8len)//~va3DI~
{                                                                  //~va3DI~
//	WUCS ucs;                                                      //~va3DI~//~va72R~
  	UWUCS ucs;                                                     //~va72I~
    int rc=0,dbcssz,/*opt,*/chklen,nlsopt;                             //~va3DR~//~vaa7R~
    char mbstr[MAX_MBCSLEN];                                       //~va3DI~
//**************                                                   //~va3DI~
	UTRACED("xxe_imef2lerr utf8",Ppu8,Pu8len);                     //~va3DR~
	uccvutf2ucs(UCVUCS_UCS4,Ppu8,Pu8len,&ucs,&chklen);             //~va3DR~
	UTRACEP("xxe_imef2lerr opt=%x,ucs=%x\n",Popt,ucs);             //~va3DR~
	if (Popt & (XXEIMEERRO_NOTERR|XXEIMEERRO_CONT))//re-chk f2l validity//~va3DR~
    {                                                              //~va3DI~
//  	opt=UTFCVO_ERRREP|(XEUTF_ERRREPCH_F2LFILE<<8);             //~va3DI~//~vaa7R~
		rc=ucvext_iconvucs2local1(0,(ULONG)Gconverters,(WUCS)ucs,mbstr,&dbcssz);//~va3DI~
		UTRACEP("f2lerr iconvucs2local rc=%d,dbcssz=%d,mbstr=%s\n",dbcssz,mbstr);//~va3DI~
        if (!rc)                                                   //~va3DI~
        {                                                          //~va3DI~
        	UmemcpyZ(Pkeyinfo->mbstr,mbstr,dbcssz);                //~va3DR~
            Pkeyinfo->chChar=*mbstr;                               //~va3DI~
            nlsopt=0;                                              //~va3DI~
            if (dbcssz==UDBCSCHK_DBCSSZ)                           //~va3DI~
                nlsopt=KBDNLS_F2L_DBCS2ND;                         //~va3DI~
            else                                                   //~va3DI~
            if (dbcssz==UDBCSCHK_GB4SZ)                            //~va3DI~
                nlsopt=KBDNLS_GB4;//later DBCS1ST will be on       //~va3DI~
            else                                                   //~va3DI~
            if (dbcssz==UDBCSCHK_SS3SZ)                            //~va3DI~
                nlsopt=KBDNLS_SS3;                                 //~va3DI~
		    if (nlsopt)                                            //~va3DR~
				nlsopt=KBDNLS_F2L_SBCS;                            //~va3DR~
            else                                                   //~va3DI~
            	nlsopt|=KBDNLS_F2L_DBCS1ST;                        //~va3DI~
			Pkeyinfo->bNlsShift=nlsopt;                            //~va3DI~
			UTRACEP("xxe_imef2lerr rc=0,nlsopt=%x,mbstr=%s\n",nlsopt,Pkeyinfo->mbstr);//~va3DR~
            return 0;                                              //~va3DI~
        }                                                          //~va3DI~
    }                                                              //~va3DI~
    dbcssz=utfwcwidth(0,ucs,0/*flag*/);                            //~va3DI~
    if (dbcssz==1)                                             //~v65cI~//~va3DR~
    {                                                              //~va3DI~
		Pkeyinfo->bNlsShift=KBDNLS_F2L_ERR|KBDNLS_F2L_SBCS;    //~v65cR~//~va3DI~
        rc=1;                                                      //~va3DI~
        Pkeyinfo->mbstr[0]=XEUTF_ERRREPCH_F2LFILE;                 //~va3DI~
        Pkeyinfo->mbstr[1]=0;                                      //~va3DI~
    }                                                              //~va3DI~
    else                                                       //~v65cI~//~va3DI~
    {                                                              //~va3DI~
		Pkeyinfo->bNlsShift=KBDNLS_F2L_ERR|KBDNLS_F2L_DBCS1ST|KBDNLS_F2L_DBCS2ND;//~v65cI~//~va3DI~
        Pkeyinfo->mbstr[0]=XEUTF_ERRREPCH_F2LFILE;                 //~va3DI~
        Pkeyinfo->mbstr[1]=XEUTF_ERRREPCH_F2LFILE;                 //~va3DI~
        Pkeyinfo->mbstr[2]=0;                                      //~va3DI~
        rc=2;                                                      //~va3DI~
    }                                                              //~va3DI~
	UTRACEP("xxe_imef2lerr rc=%d,dbcssz=%d,mbstr=%s\n",rc,dbcssz,Pkeyinfo->mbstr);//~va3DR~
    return rc;                                                     //~va3DI~
}//xxe_imef2lerr                                                   //~va3DI~
//===============================================================================//~va0VI~
//setdbcstbl for utf8 kbdinput                                     //~va0VI~
//===============================================================================//~va0VI~
void  xxe_setdbcstbl(char *Ptext,char *Pdbcs,int Plen)             //~va0VI~
{                                                                  //~va0VI~
#ifdef AAA                                                         //~va1cR~
	UCHAR *pdata,*pdbcs;                                           //~va0VI~
    int ii;                                                        //~va0VI~
//************************                                         //~va0VI~
    for (ii=0,pdata=Ptext,pdbcs=Pdbcs;ii<Plen;ii++,pdata++)        //~va0VI~
    {                                                              //~va0VI~
        if (Gpxxedbcstbl[*pdata] & UDBCSCHK_TYPEDBCS)              //~va0VR~
        {                                                          //~va0VI~
			pdata++;                                               //~va0VI~
            *pdbcs++=UDBCSCHK_DBCS1ST;                             //~va0VI~
            *pdbcs++=UDBCSCHK_DBCS2ND;                             //~va0VI~
            ii++;                                                  //~va0VI~
        }                                                          //~va0VI~
        else                                                       //~va0VI~
            *pdbcs++=0;                                            //~va0VI~
    }                                                              //~va0VI~
#else                                                              //~va1cR~
    usetdbcstblmb(0,Ptext,Pdbcs,Plen);                             //~va1cR~
#endif                                                             //~va1cR~
    return;                                                        //~va0VI~
}//xxe_setdbcstbl                                                  //~va0VI~
//===============================================================================//~va3bI~
//ligature allowance                                               //~va3bR~
//rc:0:csr is on dataline                                          //~va3bR~
//  :1:not file panel                                              //~va3bI~
//  :2:hhex/bin file                                               //~va3bI~
//  :-1:vhex1 hexline data                                         //~va3bR~
//  :-2:vhex2 hexline data                                         //~va3bI~
//  :3:not data line                                               //~va6qI~
//  :4:not on text area                                            //~va3bI~
//===============================================================================//~va3bI~
int xxe_chkcsrisfiledataline(int Popt,PUCLIENTWE Ppcw,int Prow,int Pcol,int *Ppinfo)//~va3bR~
{                                                                  //~va3bI~
    PUFILEC pfc;                                                   //~va3bI~
    PUFILEH pfh;                                                   //~va3bI~
    PULINEH plh;                                                   //~va3tI~
    PUSCRD  psd;                                                   //~va3bI~
    int rc=0,rcinfo=0,rrow,rcol;                                     //~va3bR~//~va3dR~
    int /*rc2,*/pos,offs;                                              //~va3tI~//+vbDsR~
//************************                                         //~va3bI~
    rrow=Prow-Ppcw->UCWorgy;                                       //~va3bI~
    rcol=Pcol-Ppcw->UCWorgx;                                       //~va3bI~
    if (rrow==CMDLINENO)                                           //~va3bI~
    {                                                              //~va3bI~
        rcinfo|=XXECCPI_CMDLINE;                                   //~va3bI~
//      return 0;   //break,allow ligature                         //~va3bI~//~va3tR~
        rc=4;                                                      //~va3tI~
    }                                                              //~va3bI~
    else                                                           //~va3tI~
    if (Ppcw->UCWtype==UCWTFILE)                                   //~va3bR~
    {                                                              //~va3bI~
        pfc=Ppcw->UCWpfc;                                          //~va3bR~
        pfh=pfc->UFCpfh;                                           //~va3bI~
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
        if (UCBITCHK(pfh->UFHflag11,UFHF11FILEFK))                 //~va6qR~
    		rc=1;                                                  //~va6qI~
        else                                                       //~va6qI~
        if (UCBITCHK(pfh->UFHflag5,UFHF5HEX)                       //~va3bI~
        ||  UCBITCHK(pfh->UFHflag4,UFHF4BIN)                       //~va3bI~
        )                                                          //~va3bI~
        {                                                          //~va3bI~
        	rc=2;                                                  //~va3bI~
        	rcinfo|=XXECCPI_BIN;	//dataline is cpu8 file        //~va3bI~
        }                                                          //~va3bI~
        else                                                       //~va6qM~
        if (UCBITCHK(psd->USDflag2,USDF2PROTFHDR)                  //~va6qM~
    	||  (plh && plh->ULHtype!=ULHTDATA)                        //~va6qM~
        )                                                          //~va6qM~
        {                                                          //~va6qM~
        	rc=3;	//not data line                                //~va6qM~
        	rcinfo|=XXECCPI_HDRLINE; //cols is on lineno fld       //~va6qM~
        }                                                          //~va6qM~
      }                                                            //~va6qI~
//      else                                                       //~va6qR~
      if (!rc)                                                     //~va6qI~
      {                                                            //~va6qI~
        if (UCBITCHK(pfc->UFCflag2,UFCF2VHEX))	//vhex mode        //~va3bI~
        {                                                          //~va3bI~
    		if (RPOSONFILEDATA(Ppcw,rrow,rcol))                    //~va3bR~
            {                                                      //~va3bI~
            	psd=Ppcw->UCWpsd+rrow;                             //~va3bR~
            	if (UCBITCHK(psd->USDflag2,USDF2VHEXLINE1))        //~va3bR~
                {                                                  //~va3bI~
                	rc=-1;                                         //~va3bR~
        			rcinfo|=XXECCPI_VHEX;	//cols on vhex text    //~va3bI~
                }                                                  //~va3bI~
                else                                               //~va3bI~
            	if (UCBITCHK(psd->USDflag2,USDF2VHEXLINE2))        //~va3bI~
                {                                                  //~va3bI~
                	rc=-2;                                         //~va3bR~
        			rcinfo|=XXECCPI_VHEX;	//cols on vhex text    //~va3bI~
                }                                                  //~va3bI~
                else                                               //~va3bI~
                {                                                  //~va6qI~
                	rc=0;	//file dataline                        //~va3bR~
                }                                                  //~va6qI~
                if (rc<0)                                          //~va3tI~
                {                                                  //~va3tI~
                    plh=psd->USDbuffc;                             //~va3tI~
                    offs=rcol-Ppcw->UCWlinenosz;                   //~va3tI~
                    if (offs>=0)                                   //~va3tI~
                    {                                              //~va3tI~
//                    	rc2=xeutf_getvhexpos(0,Ppcw,plh,offs,&pos,0/*out dbcsid*/);//~va3tI~//+vbDsR~
                      	xeutf_getvhexpos(0,Ppcw,plh,offs,&pos,0/*out dbcsid*/);//+vbDsI~
//                      if (rc2==2)	//dbcs split                   //~va3tI~//~vbDsR~
//                        	pos--;                                 //~va3tI~//~vbDsR~
                        UTRACEP("%s:pos=%d,left=%d,UCWorgx=%d\n",UTT,pos,pfc->UFCleft,Ppcw->UCWorgx);//~vbDgR~//~vbDsI~
					  if (Popt & XXECCPO_NOT_RELATIVE)	//    0x04	//for vsplit, col includes left panel width//~vbDsI~
                      	pos+=Ppcw->UCWorgx;                        //~vbDsI~
                        pos-=pfc->UFCleft;                         //~va3tI~
                        pos+=Ppcw->UCWlinenosz;                    //~va3tI~
                        pos<<=XXECCPI_VHEXCSRSHIFT;                //~va3tI~
        				rcinfo|=(pos|XXECCPI_VHEXCSRPOS);          //~va3tI~
                    }                                              //~va3tI~
                }                                                  //~va3tI~
            }                                                      //~va3bI~
//            else                                                 //~va6qR~
//            {                                                    //~va6qR~
//                if (GPOSONFILELINE(Ppcw,rrow))                   //~va6qR~
//                    rcinfo|=XXECCPI_LINENO; //cols is on lineno fld//~va6qR~
//                rc=4;                                            //~va6qR~
//            }                                                    //~va6qR~
        }                                                          //~va3bI~
      }//rc                                                        //~va6qI~
        if (FILEUTF8MODE(pfh))                                     //~va3bI~
        	rcinfo|=XXECCPI_CPU8;	//dataline is cpu8 file        //~va3bI~
    }                                                              //~va3bI~
    else                                                           //~va3bI~
    	rc=1;                                                      //~va3bI~
    if (Ppinfo)                                                    //~va3bI~
    	*Ppinfo=rcinfo;                                            //~va3bI~
UTRACEP("%s:rc=%d,row=%d,col=%d,info=%x,rrow=%d,rcol=%d\n",UTT,rc,Prow,Pcol,rcinfo,rrow,rcol);//~va6qR~//~vbAjR~
//dprintf("csrposchk rc=%d,row=%d,col=%d,info=%x,rrow=%d,rcol=%d\n",rc,Prow,Pcol,rcinfo,rrow,rcol);//~va6qI~//~vbAjR~
    return rc;                                                     //~va3bI~
}//xxe_chkcsrisfiledataline                                        //~va3bR~
//===============================================================================//~va3bI~
//ligature allowance                                               //~va3bI~
//===============================================================================//~va3bI~
int xxe_chkcsrpos(int Popt,int Prow,int Pcol,int *Ppinfo)          //~va3bR~
{                                                                  //~va3bI~
    PUCLIENTWE pcw;                                                //~va3bI~
    int rc,rc2,info;                                               //~va3bR~
//************************                                         //~va3bI~
    scrcpgetpcw(Prow,Pcol,&pcw);                                   //~va3bI~
	if (Popt & XXECCPO_CSRLINEBREAK)	//should break at csr pos ?//~va3bI~
    {                                                              //~va3bI~
//return row: "+":csr line is dataline,                            //~va3bR~
//            0:not on file text area                              //~va3bI~
//            "-":csrline is vhex and return dataline row          //~va3bI~
    	rc2=xxe_chkcsrisfiledataline(Popt,pcw,Prow,Pcol,Ppinfo);   //~va3bR~
        if (!rc2)                                                  //~va3bI~
        	rc=Prow;    //csr pos is on dataline                   //~va3bR~
        else                                                       //~va3bI~
        if (rc2<0)   //on vhexline                                 //~va3bI~
        	rc=rc2;                                                //~va3bI~
        else                                                       //~va3bI~
        	rc=0;                                                  //~va3bI~
UTRACEP("chkcsrpos BREAKCHK rc=%d,row=%d,col=%d\n",rc,Prow,Pcol);  //~va3bI~
        return rc;                                                 //~va3bI~
    }                                                              //~va3bI~
	if (Popt & XXECCPO_STRCHK)	//disable ligature ?               //~va3bI~
    {                                                              //~va3bI~
//return 1  : disable ligature for ,ex, vhex line                  //~va3bI~
    	rc2=xxe_chkcsrisfiledataline(Popt,pcw,Prow,Pcol,&info);    //~va3bR~
        if (rc2==1)	//not file panel                               //~va3bI~
            rc=1;   //disable ligature                             //~va3bI~
        else                                                       //~va3bI~
        if (info                                                   //~va3bI~
                 &	(XXECCPI_BIN                                   //~va3bI~
                    |XXECCPI_VHEX                                  //~va3bI~
                    |XXECCPI_LINENO                                //~va3bI~
        			|XXECCPI_HDRLINE //cols is on lineno fld       //~va6qI~
                    |XXECCPI_CMDLINE //cmdline ;avoid "===>"is ligatured//~va6qI~
                    |XXECCPI_PAN     //panel data                  //~va6qI~
                  	)                                              //~va3bI~
        )                                                          //~va3bI~
            rc=1;   //disable ligature                             //~va3bI~
        else                                                       //~va3bI~
            rc=0;                                                  //~va3bI~
        if (Ppinfo)                                                //~va3bI~
        	*Ppinfo=info;                                          //~va3bI~
UTRACEP("chkcsrpos STRCHK rc=%d,row=%d,col=%d\n",rc,Prow,Pcol);    //~va3bI~
//dprintf("chkcsrpos STRCHK rc=%d,row=%d,col=%d\n",rc,Prow,Pcol);    //~va3bI~//~vbm5R~
        return rc;                                                 //~va3bI~
    }                                                              //~va3bI~
    return 0;                                                      //~va3bI~
}//xxe_chkcsrpos                                                   //~va3bI~
//===============================================================================//~vbm5I~
//ligature allowance starts after lineno size                      //~vbm5I~
//===============================================================================//~vbm5I~
int xxe_getlinenosz(int Popt,int Prow,int Pcol)                    //~vbm5I~
{                                                                  //~vbm5I~
    PUCLIENTWE pcw;                                                //~vbm5I~
    int rc=-1;                                                     //~vbm5R~
//************************                                         //~vbm5I~
    scrcpgetpcw(Prow,Pcol,&pcw);                                   //~vbm5I~
    if (pcw->UCWtype==UCWTFILE)                                    //~vbm5R~
    {                                                              //~vbm5I~
    	if (GPOSONFILELINE(pcw,Prow))                              //~vbm5R~
        {                                                          //~vbm5I~
        	rc=pcw->UCWlinenosz+pcw->UCWorgx;                      //~vbm5R~
	    	UTRACEP("%s:row=%d,col=%d,rc=%d\n",UTT,Prow,Pcol,rc);  //~vbm5R~
        }                                                          //~vbm5I~
    }                                                              //~vbm5I~
    return rc;                                                     //~vbm5I~
}//xxe_getlinenosz                                                 //~vbm5I~
//===============================================================================//~va3dI~
//ligature allowance                                               //~va3dI~
//===============================================================================//~va3dI~
int xxe_optligature(int Popt,int Pvalue)                           //~va3dR~
{                                                                  //~va3dI~
    PUCLIENTWE pcw;                                                //~va3dR~
static int Soldligature;                                           //~va3dR~
//************************                                         //~va3dI~
	if (Popt & XXEIOLO_ISON)                                       //~va3dI~
    {                                                              //~va3dI~
	    return ((Mligature!=0)^(Mligaturereverse!=0));             //~va3dR~
    }                                                              //~va3dI~
	if (Popt & XXEIOLO_INIT)                                       //~va3dI~
    {                                                              //~va3dI~
    	Soldligature=Pvalue;                                       //~va3dI~
        return 0;                                                  //~va3dI~
    }                                                              //~va3dI~
	if (Popt & XXEIOLO_CHNGDIALOGOPT)                              //~va3dI~
    {                                                              //~va3dI~
    	if (Mligature==Soldligature)                               //~va3dI~
        	return 0;                                              //~va3dI~
        Soldligature=Mligature;                                    //~va3dI~
	    Mligaturereverse=0;                                        //~va3dI~
		scrcpgetpcw(0,0,&pcw);                                     //~va3dI~
      if (pcw)  //not at before xe INIT call                       //~vb4qI~
      {                                                            //~vb4qI~
		wxe_resethdrligature(0,Mligature);                         //~vb4qR~
		scrfulldraw(pcw);                                          //~va3dI~
      }                                                            //~vb4qI~
        return 1;   //ligature changed                             //~va3dI~
    }                                                              //~va3dI~
    Mligaturereverse^=1; //toggle reverse Ligarure option          //~va3dR~
    if (Mligature)                                                 //~va3dR~
    	if (Mligaturereverse)	//one of two is ON                 //~va3dI~
//    		uerrmsg("Ligature is OFF temorarily",0);               //~va3dR~//~va5zR~
      		uerrmsg("Ligature is OFF temporarily.(Use setup dialog to fix)",0);//~va5zI~
        else                                                       //~va3dI~
        {                                                          //~va3dI~
    		uerrmsg("Ligature was restored(now ON)",0);            //~va3dI~
            if (!UTF_COMBINEMODE())                                //~va3dR~
            	uerrmsgcat(" ,but NO-combine mode",0);             //~va3dR~
        }                                                          //~va3dI~
    else                                                           //~va3dI~
    	if (Mligaturereverse)	//one of two is ON                 //~va3dI~
        {                                                          //~va3dI~
//  		uerrmsg("Ligature is ON temorarily",0);                //~va3dR~//~va5zR~
    		uerrmsg("Ligature is ON temporarily.(Use setup dialog to fix)",0);//~va5zI~
            if (!UTF_COMBINEMODE())                                //~va3dR~
            	uerrmsgcat(" ,but NO-combine mode",0);             //~va3dR~
        }                                                          //~va3dI~
        else                                                       //~va3dI~
    		uerrmsg("Ligature was restored(now OFF)",0);           //~va3dI~
    return 0;                                                      //~va3dI~
}//xxe_optligature                                                 //~va3dI~
//===============================================================================//~vb4rI~
//chk row is ligature line                                         //~vb4rI~
//===============================================================================//~vb4rI~
int wxe_getlineopt(int Popt,int Prow,int Pcol)                     //~vb4rI~
{                                                                  //~vb4rI~
	PUCLIENTWE pcw;                                                //~vb4rI~
//  int lineopt,vsplit2nd,errmsglineopt=0;                         //~vb74R~
    int lineopt,vsplit2nd;                                         //~vb74I~
//************************                                         //~vb4rI~
	pcw=scrgetcw(2);    //2nd pcw                                  //~vb4rI~
    vsplit2nd=((pcw && pcw->UCWorgx && Pcol>=pcw->UCWorgx) ? UVIOO_VSPLIT2ND :0);//~vb4rI~
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
//    }                                                            //~vb4tR~
    UTRACEP("%s:Prow=%d,Pcol=%d,rc:lineopt=%04x,vsplit2nd=%04x\n",UTT,Prow,Pcol,lineopt,vsplit2nd);//~vb74R~
    return lineopt;                                                //~vb4rI~
}//wxe_getlineopt                                                  //~vb4rI~
//===============================================================================//~vbAjI~
//get vsplit col                                                   //~vbAjI~
//===============================================================================//~vbAjI~
//=return vsplit col, if current is vsplit 2nd return -col         //~vbAjI~
//===============================================================================//~vbAjI~
int wxe_getPosVsplit(int Popt,int Prow)                            //~vbAjI~
{                                                                  //~vbAjI~
	PUCLIENTWE pcw2;                                               //~vbAjI~
    int pos=0;                                                     //~vbAjI~
//************************                                         //~vbAjI~
	pcw2=scrgetcw(2);    //2nd pcw                                 //~vbAjI~
    if (pcw2)                                                      //~vbAjI~
    {                                                              //~vbAjI~
		pos=pcw2->UCWorgx;                                         //~vbAjI~
        if (pcw2==scrgetcw(0))  //2nd is current                   //~vbAjI~
            pos=-pos;                                              //~vbAjI~
    }                                                              //~vbAjI~
    UTRACEP("%s:rc=%d,pcw2=%p\n",UTT,pos,pcw2);                    //~vbAjI~
    return pos;                                                    //~vbAjI~
}//wxe_getPosVsplit                                                //~vbAjI~
//*************************************************************    //~vb4qI~
int wxe_resethdrligature(int Popt,int Pligature)                   //~vb4qR~
{                                                                  //~vb4qI~
    PUCLIENTWE pcw;                                                //~vb4qI~
//***********************                                          //~vb4qI~
    UTRACEP("%s:Pligature=%d\n",UTT,Pligature);                    //~vb4qI~
	pcw=scrgetcw(0);	//active client                            //~vb4qI~
	optresethdrligcomb(0,pcw);                                     //~vb4qI~
    scrdisp();          //update screen                            //~vb4qI~
    return 0;                                                      //~vb4qI~
}//wxe_resethdrligature                                            //~vb4qI~
//*************************************************************    //~vbj2I~
//*chk current is cmdHistoryListPanel                              //~vbj2I~
//*rc:1:Yes                                                        //~vbj2I~
//*************************************************************    //~vbj2I~
void *wxe_isCHLLine(int Popt)                                      //~vbj2I~
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
    	return 0;                                                  //~vbj2I~
	pfc=pcw->UCWpfc;                                               //~vbj2I~
	pfh=pfc->UFCpfh;                                               //~vbj2I~
    if (pfh->UFHtype!=UFHTCMDHIST)                                 //~vbj2I~
    	return 0;                                                  //~vbj2I~
    if (!CSRONFILELINE(pcw))                                       //~vbj2I~
    	return 0;                                                  //~vbj2I~
    row=pcw->UCWrcsry;                                             //~vbj2I~
    psd=pcw->UCWpsd;                                               //~vbj2I~
    psd+=row;                                                      //~vbj2I~
    plh=psd->USDbuffc;                                             //~vbj2I~
    if (!plh)                                                      //~vbj2I~
    	return 0;                                                  //~vbj2I~
    if (plh->ULHtype==ULHTHDR)                                     //~vbj2I~
    	return 0;                                                  //~vbj2I~
    UTRACEP("%s:row=%d,plhline=%d,pcw=%p\n",UTT,row,plh->ULHlinenor,pcw);//~vbj2I~
    return pcw;                                                    //~vbj2I~
}//wxe_isCHLLine                                                   //~vbj2I~
//*************************************************************    //~vbj2I~
//*chk current is cmdHistoryListPanel                              //~vbj2I~
//*rc:1:Yes                                                        //~vbj2I~
//*************************************************************    //~vbj2I~
int  wxe_CHLcmd(int Popt,int Pcmd)                                 //~vbj2I~
{                                                                  //~vbj2I~
	PUCLIENTWE pcw;                                                //~vbj2I~
    int rc;                                                        //~vbj2I~
    int stat=0;                                                    //~vbj2I~
//***********************                                          //~vbj2I~
	pcw=wxe_isCHLLine(0);                                          //~vbj2I~
	if (!pcw)                                                      //~vbj2I~
    	return -1;                                                 //~vbj2I~
    stat|=WXEKBDMSG_KEYDOWN;                                       //~vbj2I~
    rc=wxe_kbdmsg(stat,(UINT)(DMYSCANCODE|Pcmd),0,0);		//1:repeat,0:flag//~vbj2I~
    return rc;                                                     //~vbj2I~
}//wxe_CHLcmd                                                      //~vbj2I~
