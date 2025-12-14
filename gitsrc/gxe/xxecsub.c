//*CID://+vbBzR~:                             update#=  966;       //~vbBzR~
//***************************************************************************//~2818I~
//* c subrtn for wxe                                               //~2818I~
//***************************************************************************//~2818I~
//vbBz:241219 (gxe:bug) when sudo panel height shrink; get_window_size is available with gtk_windw_set_default_size to save/restore window size.//~vbBzI~
//vbA3:240531 (Bug:gxe)SCM remaining char shown by altch color     //~vbA3I~
//vbA2:240529 (gxe) gdk_color_to_string was deprecated             //~vbzbI~
//vbzb:240129 (XXE:Bug)cursor hides background text                //~vbzbI~
//vbza:240127 (XXE)reduce single width limit(F2c and ambiguous only,<0x80 is out of range)//~vbzaI~
//vbz5:240120 try vbz3 to XXE(apichk by char extent)               //~vbz5I~
//vbu0:201217 Debian10 compiler warning                            //~vbu0I~
//vbrb:200801 (gxe)uerrexit msgbox corrupted (already utf8)        //~vbrbI~
//vbi9:180221 (GTK3:bug)window size recovery err                   //~vbi9I~
//vb7z:170131 (gxe:bug)dirlist file drag cause scroll              //~vb7zI~
//vb7t:170128 (gxe)Gtk3 deprecated
//vb7s:170128 (gxe:bug)avoid "Gtk-Message:GtkDialog mapped without a transient parent."
//vb3z:160623 (gxe)dbcsspace altch by 1 altch for ls file sqame as utf8 file//~vb3zI~
//v6un:140502 MultiByte2WideChar failes by 0xfdff(cp)-->f8f1+f8f3(ucs2) by MB_ERR_INVALID_CHARS;pass it not W func as is//~v6unI~
//varc:140215 add resizehint option  --gh={Y|n}                    //~varcI~
//varb:140215 (BUG)resizehint shirink window up to minimum on Kubuntu 12.4(gtk 3.4.2)//~varbI~
//var8:140127 gtk3 suppott                                         //~var8I~
//var4:140118 set transient for msgbox from dialog to pretect heide msgbox behind dialog//~var4I~
//var2:140117 set title for popup dialog                           //~var2I~
//vamK:131123 (BUG)at ubuntu13.4 global menu option;frame width shrink to min width even when expanded by mouse.//~vamKI~
//vamG:131119 (BUG:gxe)lc print conversion fail when dbcs split at eol(recfm=R/V)//~vamGI~
//vam4:130928 file scrprint show unprintable by box char,use altch like scr draw//~vam4I~
//vam0:130911 for distro removed gnome-print,use GTKprint          //~vam0I~
//vaf5:120604 (WXE/XXE) msgbox for uerrexit by inifile version unmatch//~vaf5I~
//vaa7:111117 (gcc4.6)Warning:unused-but-set                       //~vaa7I~
//va70:000701 LP64 option support. at first chk PTR sz(ini file comaptibility)//~va70I~
//va6X:000728 (BUG)suse64 abend at print dialog open(missing apply of v5nD)//~va6XI~
//va6p:000623 (LNX:BUG) ligature ignored for locale file           //~va6pI~
//va6n:000623 (BUG)Guviompadch was changed to ucs by ulib v65p     //~va6nI~
//va53:100419 num setr/seti should chk margin/lrecl overflow       //~va53I~
//va47:100401 va46 for LNX                                         //~va47I~
//va44:100329 to print 0x14 glyph(q:0xb6),use another altchar(0xff)(DBCS space)//~va44I~
//va42:100328 (WXE:BUG)tab,tab padding char is not visual,print alt char//~va42I~
//va3b:100205 (GXE)no ligature for hex edit(HEX mode and EH cmd)   //~va3bI~
//va30:100126 combine mode of diacritical marks by A+/(saved to ini)//~va30I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//va1c:091012 GB18030 4 byte dbcs support                          //~va1cR~
//v7ax:090414 (LNX)compile waring int:gsize                        //~v7axI~
//v7ad:081109 EUC-JP SS3 support(display by .+DBCS)                //~v7adI~
//v7a4:081102 (XXE:BUG)abend by /N8 option                         //~v7a4I~
//v79Y:081029 (XXE) replace unprintable by '.'                     //~v79YI~
//v79Q:081027 (XXE:BUG)0x0a or 0x0d is cause of line is not drawn;replace it by unprintable id//~v79QI~
//v79D:081011 (XXE) draw ime cursor                                //~v79DI~
//v79z:080916 DBCS tbl for C and K of CJK                          //~v79zI~
//v78D:080503 (XXE)csr write to scr direct(not pix map) to avoid old csr line draw//~v77qI~
//v77q:080110*(XXE:BUG) screen hight expand when font style chang  //~v77qI~
//v706:060729 (XXE:BUG)Gerror should be clear before call(cause abend)//~v706I~
//v705:060727 graphic char setup by external file                  //~v705I~
//v69X:060720 (XXE)line-draw support also fo gxe when OPT LINECH ON.(v69M)//~v69XI~
//v69V:060718 (XXE)Performance tuning for pango.                   //~v69VI~
//                 gdk_draw_layout_with_color for each char one by one is too slow//~v69VI~
//                 On the other hand string draw requres monospace and usetmonospace exaust cpu on gprof.//~v69VI~
//                 Bug of monospace determination was exist.(missed to set font to layout)//~v69VI~
//                 Monospace determination obey to font rfamily attribute.//~v69VI~
//                 DBCS is not just double iof sbcs width even for monospace font.//~v69VI~
//                 So use string write for sbcs only if mono space,else use uset monospace.//~v69VI~
//v69U:060718 (XXE:BUG)errmsg "Cut/Pastet source data contains invalid data"//~v69UI~
//            because scr width is not multiple of cellw,copy data contains 1 column over//~v69UI~
//v69Q:060715 (XXE)utf conversion perfomance chk                   //~v69QI~
//v69s:060531 (XXE:fc5)g_locale_to_utf8 return error if null char contained//~v69sI~
//v69r:060531 (XXE)print debug message by GError                   //~v69rI~
//v69n:060530 (XXE:fc5)avoid Gtk warning "GError not initialized". //~v69nI~
//v68j:060404 (XXE)gtk dmsgdialog okcan button default is cancel,force ok as default like as Windows//~v68jI~
//v68i:060331 (WXEXXE)activate window when dropped                 //~v68iI~
//v685:060322 dnd support "file copy into the dir slected" and even in inter-split-screen.//~v685I~
//v67A:051227 (GXE:BUG)msg dialog source string should be utf8     //~v67AI~
//v66A:051220 dialog to confirm wxe/gxe termination when func-key used//~v66AI~
//vXXE:050611 new for XXE                                          //~vXXEI~
//v63m:050510 (WXE)draw screen between exe cmd file                //~v63mI~
//v56h:040404 (WXE)ignore setcaretpos r.c because it may occur when windows z-order is changed//~v56hI~
//v560:040324 (WIN)break sleep by esc*2                            //~v560I~
//v55Z:040324 (WXE)ctl multicmd by wxe to display intermediate screen//~v55ZI~
//v55W:040322 (WXE)AT cmd support;"AT(&) interval,count;KEY_S_P0       cmd"//~vXXER~
//v55D:040307 (WXE)kick wxe.hlp by help cmd             KEY_S_P1   //~vXXER~
//v55c:040208 (WXE)distingush L-CTL/R-CTL               KEY_S_P2   //~vXXER~
//v54y:040118 (WXE)wxp cmd support(send file to wxe for KEY_S_P3       print by wxe)//~vXXER~
//v53t:031004 (WXE:BUG)not freed area exist             KEY_S_P4   //~vXXER~
//******************************************************KEY_S_P5       *********************//~vXXER~
#include <time.h>                                                  //~vXXER~
#include <stdio.h>                                                 //~vXXER~
#include <stdlib.h>                                                //~vXXER~
#include <string.h>                                                //~vXXER~
#include <iconv.h>                                                 //~va1cR~
//******************************************************KEY_S_PPERIOD  *******//~vXXER~
#ifndef OPTGTK3                                                    //~var8R~
#include <gnome.h>                                                 //~vXXER~
#else                                                              //~var8R~
#include <gtk/gtk.h>                                               //~var8R~
#include <gdk/gdkx.h>                                              //~var8R~
#endif                                                             //~var8R~
#include <glib.h>                                                  //~v69QI~
#ifndef NOPRINT                                                    //~vam0R~
	#ifdef GTKPRINT                                                //~vam0I~
	#else    //!GTKPRINT                                           //~vam0I~
#include <libgnomeprint/gnome-print.h>                             //~vXXEI~
#include <libgnomeprint/gnome-print-job.h>                         //~vXXEI~
	#endif   //!GTKPRINT                                           //~vam0I~
#endif                                                             //~vam0I~
                                                                   //~vXXER~
#include "callbacks.h"                                             //~vXXER~
#include "interface.h"                                             //~vXXER~
#include "support.h"                                               //~vXXEI~
                                                                   //~2907I~
#include "ulib.h"                                                  //~2907I~
#include "ualloc.h"                                                //~2907R~
#include "uque.h"                                                  //~2929I~
#include "uerr.h"                                                  //~2907I~
#include "utrace.h"                                                //~2914I~
#include "ufile.h"                                                 //~2922I~
#include "ufile2.h"                                                //~2923I~
#include "ufile4.h"                                                //~2923I~
#include "udbcschk.h"                                              //~vXXEI~
#include "uedit.h"                                                 //~v69rI~
#include "ucvucs.h"                                                //~va1cR~
#include "utf.h"                                                   //~va1cR~
#include "uviom.h"                                                 //~va1cR~
#ifdef UTF8UCS2                                                    //~va20I~
#include "utf22.h"                                                 //~va20I~
#endif                                                             //~va20I~
#include "uedit2.h"                                                //~vbA3I~
                                                                   //~2818I~
#include <gxe.h>                                                   //~var8R~
#include "xxedef.h"                                                //~vXXER~
#include "xxecsub.h"                                               //~vXXER~
//#include <gxe.h>                                                 //~var8R~
#include <xe.h>                                                    //~vXXEI~
#include <xescr.h>     //for xesub2.h                              //~va53I~
#include <xefile.h>    //for xesub2.h                              //~va53M~
#include <xesub2.h>                                                //~va1cR~
#include <xxexei.h>                                                //~vXXEI~
#include <xxemain.h>                                               //~vXXEI~
//***************************************************************************//~2818I~
#define UERRMSG_MAXPARM   10                                       //~va6XR~
#define MAX_LINEACS 11                                             //~v705I~
//#define COL(x)          ((x-BORDERMARGIN)/Scellw)                //~vXXER~
//#define ROW(y)          ((y-BORDERMARGIN)/Scellh)                //~vXXER~
//#define XX(col)         ((col)*Scellw+BORDERMARGIN)              //~vXXER~
//#define YY(row)         ((row)*Scellh+BORDERMARGIN)              //~vXXER~
//***************************************************************************//~2831I~
#ifndef XXE                                                        //~vXXEI~
static int Sstylectr=0;                                            //~2818I~
static int Selfmaxctr=0;                                           //~vXXER~
#endif                                                             //~vXXEI~
static GtkWindow  *Shwnd=0;                                        //~vXXER~
//static HBITMAP Shbm_caret[4];                                    //~2914R~
//static int   Scellh,Scellw;                                      //~vXXER~
static int   Scaretheight,Scrow,Sccol;                             //~vXXER~
static char  Swdtemp[_MAX_PATH];                                   //~2B30R~
//static int Sisutf8;                                              //~v79zR~
static const char *Scurrent_charsetname=0;                         //~v69QR~
static GIConv Sconverterdescriptor=0;                              //~v69QR~
static UCHAR *Sacsmap[256]; //line drawing char definition         //~v69XM~
static int    Sacslentb[256]; //line drawing char length           //~v705R~
static GtkWidget *Spmsgboxparent;                                  //~var4I~
static int Sminx,Sresizectr;                                       //~varcR~
#define THV_RESIZECTR    10  //                                    //~varcI~
#define THV_RESIZETIME   3   //seconds                             //~varcI~
PangoLayout *SplayoutForExtent;                                    //~vbz5I~
int Ssbcswidth;                                                    //~vbz5I~
//***************************************************************************//~2907I~
//#ifndef OPTGTK3                                                  //~var8R~
//#else   //OPTGTK3                                                //~var8R~
//    #define GXE_CAIRO_USERDATA_KEY_BG &Scairo_user_data_key_bg   //~var8R~
//    static cairo_user_data_key_t Scairo_user_data_key_bg;        //~var8R~
//#endif                                                           //~var8R~
//***************************************************************************//~var8R~
int  iniacrnmchk(FILE *Pfh);                                       //~2907I~
int  iniacrnmput(FILE *Pfh);                                       //~2907I~
int  usetupwd(void);                                               //~2A12I~
int  usetupwdtemp(void);                                           //~2A12I~
int udrawcaret(int Pshowsw,int Prow,int Pcol);                     //~vXXEI~
int csubutf8init(void);                                            //~v69QI~
#if GTK_CHECK_VERSION(3,22,0)                                      //~vb7tI~
cairo_t *csub_get_cairot(int Popt,GtkWidget *Ppwidget,cairo_rectangle_int_t *Pprect);//~vb7tR~
#define CSGCO_END       0x01 //end drawing                         //~vb7tI~
#endif                                                             //~vb7tI~
//***************************************************************************//~2831I~
//init static                                                      //~2831I~
//***************************************************************************//~2831I~
int csubinit1(HWND Phwnd)                                          //~vXXER~
{                                                                  //~2831I~
	Shwnd=(GtkWindow*)Phwnd;	//Mpview->window                   //~vXXER~
//    memcpy(Shbm_caret,Phbmtbl,sizeof(Shbm_caret));               //~2914R~
	csubutf8init();                                                //~v69QI~
    return 0;                                                      //~2831I~
}                                                                  //~2831I~
//***************************************************************************//~vbz5I~
//redo mapinit                                                     //~vbz5I~
//***************************************************************************//~vbz5I~
void csubinit3()                                                   //~vbz5I~
{                                                                  //~vbz5I~
	xxe_mapinit();                                                 //~vbz5I~
}                                                                  //~vbz5I~
int csubutf8init(void)                                             //~v69QI~
{                                                                  //~v69QI~
    int isutf8;                                                    //~v79zI~
//******************                                               //~v79zI~
//  Sisutf8=g_get_charset(&Scurrent_charsetname);                  //~v79zR~
    isutf8=g_get_charset(&Scurrent_charsetname);                   //~v79zI~
    if (isutf8)                                                    //~v79zR~
    	Gwxestat|=GWXES_ENVISUTF8;                                 //~v79zR~
//  if (!Sisutf8)    //current is not utf8                         //~v79zR~
    if (!isutf8    //current is not utf8                           //~v79zR~
//  ||   Gxxestat & GXXES_KBDIMEICONV)  //locale cmdline parm or UTF8 env(file is mb)//~v79zI~//~v7a4R~
    ||   *Gcharset)                     //locale cmdline parm or UTF8 env(file is mb)//~v7a4I~
    {                                                              //~v69QI~
//		if (Gxxestat & GXXES_KBDIMEICONV)  //locale cmdline parm or UTF8 env(file is mb)//~v79zI~//~v7a4R~
  		if (*Gcharset)  //default or /Ccharset(Not UTF8) parm      //~v7a4I~
			Scurrent_charsetname=Gcharset;                         //~v79zI~
        Sconverterdescriptor=g_iconv_open ("UTF-8",Scurrent_charsetname);//~v69QI~
        if (Sconverterdescriptor==(GIConv)-1)                      //~v69QR~
            uerrmsg("%s to UTF-8 is not supported\n",0,            //~v69QI~
					Scurrent_charsetname);                         //~v69XI~
    }                                                              //~v69QI~
//  dprintf("utf8mode=%d charset=%s,converter=%x\n",isutf8,Scurrent_charsetname,(UINT)Sconverterdescriptor);//~v79zR~//~va70R~
    dprintf("utf8mode=%d charset=%s,converter=%p\n",isutf8,Scurrent_charsetname,Sconverterdescriptor);//~va70I~
    return 0;                                                      //~v69QI~
}                                                                  //~v69QI~
//*********************************************************************//~v69XM~
//* uviol_acssetup  for EUC code                                   //~v69XM~
//*   parm seq is fix                                              //~v69XM~
//*********************************************************************//~v69XM~
void csubacssetup(int Psetsw,int Pentno,UCHAR *Pacstbl,int *Pplentb,char **Pdispstr)//~v705R~
{                                                                  //~v69XM~
	int ii;                                                        //~v69XM~
	UCHAR *pc;                                                     //~v69XM~
//*************************                                        //~v69XM~
    memset(Sacsmap,0,sizeof(Sacsmap));                             //~v705I~
    if (Psetsw)	//not set req                                      //~v705R~
    {                                                              //~v705I~
        for (ii=0,pc=Pacstbl;ii<MAX_LINEACS;ii++,pc++)             //~v69XM~
        {                                                          //~v69XM~
         	if (ii<Pentno && *pc)                                  //~v69XM~
			{                                                      //~v705I~
//          	Sacsmap[*pc]=Sgraphchutfcode[ii];                  //~v705R~
            	Sacsmap[(int)(*pc)]=Pdispstr[ii];                  //~v705R~
		        Sacslentb[(int)(*pc)]=Pplentb[ii];                 //~v705R~
            }                                                      //~v705I~
        }                                                          //~v69XM~
    }                                                              //~v705I~
    return;                                                        //~v69XM~
}//uviol_acssetup                                                  //~v69XM~
//**************************************************************** //~2831I~
// save caret type                                                 //~vXXEI~
// parm1:start line hight; 1:tall(insert),2:low(rep)-->see xecsr.c //~vXXEI~
//*rc:ret code                                                     //~2831I~
//**************************************************************** //~2831I~
int usetcaret(int Pheightrate,int Pcellw,int Pcellh,int Pfonth)    //~vXXER~
{                                                                  //~2831I~
//********************************                                 //~2831I~
//    Scdbcssw=Pdbcssw;   //save for setcaretpos failed            //~vXXER~
	if (Pheightrate==1)     //ins mode                             //~vXXER~
    	Scaretheight=Pfonth/2*2;  //font height from cell bottom,even number to avoid overflow to next cell//~vXXER~
    else                                                           //~vXXEI~
	if (Pheightrate==2)     //rep mode                             //~vXXER~
    {                                                              //~vXXEI~
	    Scaretheight=Pcellh/20*2;   //even number    10%           //~vXXER~
        if (Scaretheight<DEF_TEXTCSR_HEIGHT)                       //~vXXER~
        	Scaretheight=DEF_TEXTCSR_HEIGHT;                       //~vXXER~
    }                                                              //~vXXEI~
    else                                                           //~vXXEI~
        Scaretheight=1;                                            //~vXXEI~
    dprintf("caret height=%d,fonth=%d\n",Scaretheight,Pfonth);     //~vXXER~
//#ifndef OPTGTK3                                                  //~var8R~
	gdk_gc_set_line_attributes(Gpgccsr,Scaretheight,               //~vXXEI~
    	GDK_LINE_SOLID,GDK_CAP_NOT_LAST,GDK_JOIN_MITER);           //~vXXEM~
//#else                                                            //~var8R~
//    csub_gdk_gc_set_line_attributes(Gpgccsr,Scaretheight,        //~var8R~
//        GDK_LINE_SOLID,GDK_CAP_NOT_LAST,GDK_JOIN_MITER);         //~var8R~
//#endif                                                           //~var8R~
	if (Pheightrate==1)     //ins mode                             //~vbzbI~
    {                                                              //~vbzbI~
	    gdk_gc_set_foreground(Gpgccsr,&GcsrcolorBox);              //~vbzbI~
    	csub_gdk_gc_set_foregroundA(Gpgccsr,&GcsrcolorBox,OPAQUE_CSR_BOX);//~vbzbR~
    }                                                              //~vbzbI~
    else                                                           //~vbzbI~
    {                                                              //~vbzbI~
	    gdk_gc_set_foreground(Gpgccsr,&Gcsrcolor);                 //~vbzbI~
		csub_gdk_gc_set_foreground(Gpgccsr,&Gcsrcolor);            //~vbzbI~
    }                                                              //~vbzbI~
UTRACEP("%s:Pheightrate=%d,hight=%d,cellh=%d,fonth=%d\n",UTT,Pheightrate,Scaretheight,Pcellh,Pfonth);//~vXXER~//~vbzaR~//~vbzbR~
    return 0;                                                      //~vXXER~
}                                                                  //~2831I~
//**************************************************************** //~2922I~
//*rc:ret code                                                     //~2922I~
//**************************************************************** //~2922I~
void uredrawcaret(void)                                            //~2922I~
{                                                                  //~2922I~
//********************************                                 //~2922I~
#ifndef XXE                                                        //~vXXEI~
	usetcaret(Scdbcssw,Scheightrate,Scellw,Scellh,Scfonth);	//recreate//~2922I~
	usetcaretpos(Scrow,Sccol);                                     //~2922I~
#endif                                                             //~vXXEI~
	ushowcaret();                                                  //~2922I~
    return;                                                        //~2922I~
}                                                                  //~2922I~
//**************************************************************** //~2831I~
//*rc:ret code                                                     //~2831I~
//**************************************************************** //~2831I~
int ushowcaret(void)                                               //~2831I~
{                                                                  //~2831I~
	udrawcaret(1,Scrow,Sccol);                                     //~vXXER~
    return 0;                                                      //~vXXEI~
}                                                                  //~2831I~
//**************************************************************** //~2831I~
//*rc:ret code                                                     //~2831I~
//**************************************************************** //~2831I~
int uhidecaret(void)                                               //~2831I~
{                                                                  //~2831I~
	udrawcaret(0,Scrow,Sccol);                                     //~vXXER~
    return 0;                                                      //~vXXEI~
}                                                                  //~2831I~
//**************************************************************** //~2831I~
//*rc:ret code                                                     //~2831I~
//**************************************************************** //~2831I~
int ugetcaretpos(int *Pprow,int *Ppcol)	//client axis              //~2831I~
{                                                                  //~2831I~
    *Pprow=Scrow;                                                  //~vXXEI~
    *Ppcol=Sccol;                                                  //~vXXEI~
    dprintf("get caretpos row=%d,col=%d\n",*Pprow,*Ppcol);         //~vXXER~
    return 0;                                                      //~vXXEI~
}                                                                  //~2831I~
//**************************************************************** //~2831I~
//*rc:ret code                                                     //~2831I~
//**************************************************************** //~2831I~
int usetcaretpos(int Prow,int Pcol)                                //~2831I~
{                                                                  //~2831I~
//********************************                                 //~vXXEI~
	if (Prow!=Scrow||Pcol!=Sccol)	                               //~vXXEI~
		uhidecaret();                                              //~vXXER~
    Scrow=Prow;                                                    //~vXXER~
    Sccol=Pcol;                                                    //~vXXER~
    dprintf("set caretpos row=%d,col=%d\n",Prow,Pcol);             //~vXXER~
//  ushowcaret();                                                  //~vXXER~
    return 0;                                                      //~vXXEI~
}                                                                  //~2831I~
//**************************************************************** //~vXXEI~
//*rc:draw visivle/invisivle caret                                 //~vXXEI~
//**************************************************************** //~vXXEI~
int udrawcaret(int Pshowsw,int Prow,int Pcol)                      //~vXXEI~
{                                                                  //~vXXEI~
    char *pdbcs;                                                   //~vXXER~
    int ww,hh,xx,xx2,yy;                                           //~vXXER~
#ifdef UTF8SUPPH                                                   //~va1cR~
    int dbcssz;                                                    //~va1cR~
#endif                                                             //~va1cR~
//********************************                                 //~vXXEI~
    if (Mwxeintf.WXEIxetermsw)	//xe term called already           //~v78DI~
    	return 0;                                                  //~v78DI~
	if (!Pshowsw)                                                  //~vXXER~
    	return 0;                                                  //~vXXEI~
    pdbcs=(char*)TEXTDBCS(Prow,Pcol);                              //~vXXEI~
#ifdef UTF8UCS2                                                    //~va20I~
    if (UDBCSCHK_DBCS1STLU(*pdbcs))                                //~va20I~
#else                                                              //~va20I~
    if (*pdbcs==UDBCSCHK_DBCS1ST)                                  //~vXXER~
#endif                                                             //~va20I~
    {                                                              //~va1cR~
#ifdef UTF8SUPPH                                                   //~va1cR~
        dbcssz=XESUB_DBCSSPLITCTR(pdbcs,Mscrcmaxcol-Pcol,0);       //~va1cR~
	    ww=Mcellw*dbcssz;                                          //~va1cR~
#else                                                              //~va1cR~
        if ((Pcol+1)>=Mscrcmaxcol)                                 //~vXXEI~
	        ww=Mcellw;                                             //~vXXEI~
        else                                                       //~vXXEI~
	        ww=Mcellw+Mcellw;                                      //~vXXER~
#endif                                                             //~va1cR~
    }                                                              //~va1cR~
    else                                                           //~vXXEI~
        ww=Mcellw;                                                 //~vXXEI~
    hh=Scaretheight;                                               //~vXXER~
    xx=XX(Pcol);                                                   //~vXXER~
    yy=YY(Prow+1)-hh/2;	//from bottom of cell (pos is center of height?)//~vXXER~
#ifdef ARM                                                         //~va70I~
    if (hh & 0x01)  //odd                                          //~va70I~
        yy--;                                                      //~va70I~
#endif                                                             //~va70I~
    xx2=xx+ww;                                                     //~vXXER~
//  if (Prow==4) //TEST                                              //~vbzaI~//~vbzbR~
//    UTRACEP("%s:loc x=%d,y=%d w=%d,h=%d\n",UTT,xx,yy,ww,hh);   //~vXXER~//~vbzaR~//~vbzbR~
//  pgc=_gtk_get_insertion_cursor_gc(Gpview,FALSE);//   true:primary(black),false:secondary(gray)//~vXXER~
//#define XXX                                                      //~vXXER~
#ifdef XXX                                                         //~vXXEI~
    _gtk_draw_insertion_cursor(Gpview,Gppixmap,pgc,&csrloc,GTK_TEXT_DIR_LTR,1);//0:no draw arrow//~vXXER~
#else                                                              //~vXXEI~
//    for (ii=0,xx=csrloc.x,xx2=xx+csrloc.width,yy=csrloc.y;ii<csrloc.height;ii++,yy++)//~vXXER~
//        gdk_draw_line(Gppixmap,pgc,xx,yy,xx2,yy);                //~vXXER~
//  gdk_draw_line(Gppixmap,Gpgccsr,xx,yy,xx2,yy);                  //~v78DR~
#ifndef OPTGTK3                                                    //~var8R~
    dprintf("Gpview=%p,window=%p\n",Gpview,Gpview->window);        //~v78DI~
    gdk_draw_line(Gpview->window,Gpgccsr,xx,yy,xx2,yy);            //~v78DR~
#else                                                              //~var8R~
    csub_gdk_draw_line_direct(GpgcOnDraw,Gpgccsr,xx,yy,xx2,yy);    //~var8R~
#endif                                                             //~var8R~
#endif                                                             //~vXXEI~
    UTRACEP("%s:xx=%d,yy=%d,xx2=%d,row=%d,col=%d\n",UTT,xx,yy,xx2,Prow,Pcol);              //~vbz5I~//~vbzaR~
    return 0;                                                      //~vXXER~
}//udrawcaret                                                      //~vXXEI~
//**************************************************************** //~var4I~
int umsgbox_modalinparent(GtkWidget *Ppwidget,char *Ppmsg,int Pflag)//~var4R~
{                                                                  //~var4I~
	int rc;                                                        //~var4I~
//********************************                                 //~var4I~
	Spmsgboxparent=Ppwidget;                                       //~var4I~
	rc=umsgbox(Ppmsg,Pflag);                                       //~var4R~
	Spmsgboxparent=NULL;                                           //~var4I~
    return rc;                                                     //~var4I~
}//umsgbox_modalinparent                                           //~var4I~
//**************************************************************** //~2901I~
//*rc:ret code                                                     //~2901I~
//**************************************************************** //~2901I~
//int umsgbox(char *Ppmsg)                                         //~v685R~
int umsgbox(char *Ppmsg,int Pflag)                                 //~v685I~
{                                                                  //~2901I~
	GtkWidget *msgdlg;                                             //~vXXEI~
    int button;                                                    //~v685I~
    int rc;                                                        //~v66AI~
//********************************                                 //~2901I~
//  MessageBox(Shwnd,Ppmsg,NULL,MB_OK);                            //~vXXER~
	if (Pflag==MB_YESNOCANCEL)                                     //~v685I~
//  	button=MB_YESNO;                                           //~v68jR~
    	button=GTK_BUTTONS_NONE;                                   //~v68jI~
    else                                                           //~v685I~
	if (Pflag==MB_OKCANCEL)                                        //~v68jR~
    	button=MB_OK;                                              //~v68jI~
    else                                                           //~v68jI~
    	button=Pflag;                                              //~v685I~
    msgdlg=gtk_message_dialog_new(NULL,	//parent                   //~v66AR~
                                GTK_DIALOG_MODAL|GTK_DIALOG_DESTROY_WITH_PARENT, //flag//~vXXER~
                                GTK_MESSAGE_ERROR,	//messagetype  //~vXXEI~
//                              GTK_BUTTONS_CLOSE,   //button      //~v685R~
//                              Pflag,              //button       //~v685R~
                                button,             //button       //~v685I~
//  							Ppmsg);             //msg          //~v6unR~
								"%s",Ppmsg);             //msg     //~v6unI~
	gtk_window_set_title (GTK_WINDOW(msgdlg),WXE_TITLE);           //~var2I~
	if (Pflag==MB_YESNOCANCEL)                                     //~v685I~
    {                                                              //~v68jI~
        gtk_dialog_add_button(GTK_DIALOG(msgdlg),GTK_STOCK_YES,GTK_RESPONSE_YES);//~v68jI~
        gtk_dialog_add_button(GTK_DIALOG(msgdlg),GTK_STOCK_NO,GTK_RESPONSE_NO);//~v68jI~
        gtk_dialog_add_button(GTK_DIALOG(msgdlg),GTK_STOCK_CANCEL,GTK_RESPONSE_CANCEL);//~v685R~
    }                                                              //~v68jI~
    else                                                           //~v68jI~
	if (Pflag==MB_OKCANCEL)                                        //~v68jR~
        gtk_dialog_add_button(GTK_DIALOG(msgdlg),GTK_STOCK_CANCEL,GTK_RESPONSE_CANCEL);//~v68jI~
    if (Spmsgboxparent)                                            //~var4I~
		gtk_window_set_transient_for(GTK_WINDOW(msgdlg),GTK_WINDOW(Spmsgboxparent));//~var4I~
    else                                                           //~vb7sI~
    {                                                              //~vb7sI~
		if (Gpframe)                                               //~vb7sI~
			gtk_window_set_transient_for(GTK_WINDOW(msgdlg),GTK_WINDOW(Gpframe));//~vb7sI~
    }                                                              //~vb7sI~
    rc=                                                            //~v66AI~
    gtk_dialog_run(GTK_DIALOG(msgdlg));                            //~vXXEI~
    gtk_widget_destroy(msgdlg);                                    //~vXXEI~
    if (rc==IDOK||rc==IDYES)                                       //~v66AI~
    	return 0;                                                  //~v66AI~
    return rc;                                                     //~v66AR~
}//umsgbox                                                         //~var8R~
//**************************************************************** //~v66AI~
//*rc:ret code                                                     //~v66AI~
//**************************************************************** //~v66AI~
int umsgbox2(char *Ppmsg,int Pmessagetype,int Pbuttontype)         //~v66AR~
{                                                                  //~v66AI~
	int rc;                                                        //~v66AI~
	GtkWidget *msgdlg;                                             //~v66AI~
    int button;                                                    //~v685I~
//********************************                                 //~v66AI~
	dprintf("umsgbox2 msg=%s\n",Ppmsg);                            //~var8R~
	if (Pbuttontype==MB_YESNOCANCEL)                               //~v685R~
    	button=GTK_BUTTONS_NONE;                                   //~v68jR~
    else                                                           //~v68jI~
	if (Pbuttontype==MB_OKCANCEL)                                  //~v68jI~
    	button=MB_OK;                                              //~v68jI~
    else                                                           //~v685I~
    	button=Pbuttontype;                                        //~v685I~
    msgdlg=gtk_message_dialog_new(NULL,	//parent                   //~v66AR~
                                GTK_DIALOG_MODAL|GTK_DIALOG_DESTROY_WITH_PARENT, //flag//~v66AI~
                                Pmessagetype,	//messagetype      //~v66AI~
//                              Pbuttontype,   //button            //~v685R~
                                button,   //button                 //~v685I~
//  							Ppmsg);             //msg          //~v6unR~
								"%s",Ppmsg);             //msg     //~v6unI~
	gtk_window_set_title (GTK_WINDOW(msgdlg),WXE_TITLE);           //~var2R~
	if (Pbuttontype==MB_YESNOCANCEL)                               //~v685I~
    {                                                              //~v68jI~
        gtk_dialog_add_button(GTK_DIALOG(msgdlg),GTK_STOCK_YES,GTK_RESPONSE_YES);//~v68jR~
        gtk_dialog_add_button(GTK_DIALOG(msgdlg),GTK_STOCK_NO,GTK_RESPONSE_NO);//~v68jR~
        gtk_dialog_add_button(GTK_DIALOG(msgdlg),GTK_STOCK_CANCEL,GTK_RESPONSE_CANCEL);//~v685R~
    }                                                              //~v68jI~
    else                                                           //~v68jI~
	if (Pbuttontype==MB_OKCANCEL)                                  //~v68jI~
    {                                                              //~var8R~
        gtk_dialog_add_button(GTK_DIALOG(msgdlg),GTK_STOCK_CANCEL,GTK_RESPONSE_CANCEL);//~v68jI~
#ifndef OPTGTK3                                                    //~var8R~
#else   //OPTGTK3                                                  //~var8R~
////      {                                                        //~var8R~
//            GtkWidget *w;                                        //~var8R~
//            w=gtk_dialog_get_widget_for_response(GTK_DIALOG(msgdlg),GTK_RESPONSE_OK);//~var8R~
////          gtk_widget_override_background_color(w,GTK_STATE_FLAG_PRELIGHT,GphoverRGBA);//~var8R~
//            gtk_widget_grab_focus(w);                            //~var8R~
////      }                                                        //~var8R~
#endif //OPTGTK3                                                   //~var8R~
    }                                                              //~var8R~
#ifndef OPTGTK3                                                    //~var8R~
#else        //showtop of mainwindow was deleted call from configure event//~var8R~
#ifdef AAA                                                         //~var8R~
//    gtk_window_set_transient_for(GTK_WINDOW(msgdlg),GTK_WINDOW(Gpframe));//~var8R~
#endif                                                             //~var8R~
//  gtk_widget_show_all(msgdlg);                                   //~var8R~
//    gtk_window_present(GTK_WINDOW(msgdlg));                      //~var8R~
	if (Gpframe)                                                   //~vb7sM~
    {                                                              //~vb7sI~
    	gtk_window_set_transient_for(GTK_WINDOW(msgdlg),GTK_WINDOW(Gpframe));//~vb7sM~
        dprintf("umsgbox2 set_transient_for Gpframe=%p\n",Gpframe);//~vb7sI~
    }                                                              //~vb7sI~
#endif //OPTGTK3                                                   //~var8R~
	dprintf("umsgbox2 run\n");                                     //~var8R~
    rc=gtk_dialog_run(GTK_DIALOG(msgdlg));                         //~v66AI~
    gtk_widget_destroy(msgdlg);                                    //~v66AI~
    if (rc==GTK_RESPONSE_OK||rc==GTK_RESPONSE_YES)                 //~v66AI~
    	return 0;                                                  //~v66AI~
	dprintf("umsgbox2 return\n");                                  //~var8R~
    return rc;                                                     //~v66AI~
}//umsgbox2                                                        //~var8R~
//**************************************************************** //~2907I~
//*rc:ret code                                                     //~2907I~
//**************************************************************** //~2907I~
int uerrmsgbox(char * Pemsg,char * Pjmsg,... )                     //~2907R~
{                                                                  //~2907I~
//  GError *errpos=NULL;                                           //~v79zR~
//  ULONG *parm;                                                   //~2907R~//~va6XR~
	unsigned long parm[UERRMSG_MAXPARM];                           //~va6XR~
	char *pmsg;                                                    //~2907I~
    char *putf8;                                                   //~v67AI~
	int readlen,writelen;                                          //~v67AI~
//********************************                                 //~2907I~
//  parm=(unsigned long*)(void*)((&Pjmsg)+1);                      //~2907I~//~va6XR~
	UGETSTDARG(unsigned long,parm,Pjmsg,UERRMSG_MAXPARM);          //~va6XR~
	pmsg=uerrmsgedit("",Pemsg,Pjmsg,parm);                         //~2907R~
//  putf8=g_locale_to_utf8(pmsg,strlen(pmsg),&readlen,&writelen,&errpos);//~v79zR~
//  PRINTGERR("uerrmsgbox-g_locale_to_utf8",errpos);               //~v79zR~
	csublocale2utf8(0,pmsg,strlen(pmsg),&readlen,&putf8,&writelen);//~v79zI~
//	umsgbox(pmsg);                                                 //~v67AR~
//	umsgbox(putf8);                                                //~v685R~
  	umsgbox(putf8,MB_OK);                                          //~v685I~
    ugeterrmsg();		//clear msg saved                          //~2928I~
//  g_free(putf8);                                                 //~v79zR~
    return 4;                                                      //~2B02R~
}//uerrmsgbox                                                      //~2907R~
//**************************************************************** //~v66AI~
//*rc:ret code                                                     //~v66AI~
//**************************************************************** //~v66AI~
int uerrmsgboxokcan(char * Pemsg,char * Pjmsg,... )                //~v66AI~
{                                                                  //~v66AI~
//  GError *errpos=NULL;                                           //~v79zR~
//  ULONG *parm;                                                   //~v66AI~//~va6XR~
	unsigned long parm[UERRMSG_MAXPARM];                           //~va6XR~
	char *pmsg;                                                    //~v66AI~
    char *putf8;                                                   //~v67AI~
    int rc;                                                        //~v66AI~
	int readlen,writelen;                                          //~v67AI~
//********************************                                 //~v66AI~
//  parm=(unsigned long*)(void*)((&Pjmsg)+1);                      //~v66AI~//~va6XR~
	UGETSTDARG(unsigned long,parm,Pjmsg,UERRMSG_MAXPARM);          //~va6XR~
	pmsg=uerrmsgedit("",Pemsg,Pjmsg,parm);                         //~v66AI~
//  putf8=g_locale_to_utf8(pmsg,strlen(pmsg),&readlen,&writelen,&errpos);//~v79zR~
//  PRINTGERR("uerrmsgboxokscan-g_locale_to_utf8",errpos);         //~v79zR~
	csublocale2utf8(0,pmsg,strlen(pmsg),&readlen,&putf8,&writelen);//~v79zI~
//  rc=umsgbox2(pmsg,GTK_MESSAGE_QUESTION,GTK_BUTTONS_OK_CANCEL);  //~v67AR~
    rc=umsgbox2(putf8,GTK_MESSAGE_QUESTION,GTK_BUTTONS_OK_CANCEL); //~v67AI~
    ugeterrmsg();		//clear msg saved                          //~v66AI~
//  g_free(putf8);                                                 //~v79zR~
    return rc;                                                     //~v66AI~
}//uerrmsgboxokcan                                                 //~v66AI~
//**************************************************************** //~vaf5I~
//*rc:ret code                                                     //~vaf5I~
//**************************************************************** //~vaf5I~
int umsgboxlocalemsg(char * Pmsg,int Pflag)                        //~vaf5I~
{                                                                  //~vaf5I~
    char *putf8;                                                   //~vaf5I~
    int rc;                                                        //~vaf5I~
#ifdef AAA                                                         //~vbrbI~
	int readlen,writelen;                                          //~vaf5I~
#endif                                                             //~vbrbI~
//********************************                                 //~vaf5I~
#ifdef AAA                                                         //~vbrbI~
	csublocale2utf8(0,Pmsg,strlen(Pmsg),&readlen,&putf8,&writelen);//~vaf5I~
#else                                                              //~vbrbI~
	putf8=Pmsg;                                                    //~vbrbI~
#endif                                                             //~vbrbI~
    rc=umsgbox(putf8,Pflag);                                       //~vaf5I~
    return rc;                                                     //~vaf5I~
}//umsgboxlocalemsg                                                //~vaf5I~
//**************************************************************** //~vXXEI~
//*rc:ret code                                                     //~vXXEI~
//**************************************************************** //~vXXEI~
int uactivate_menuitem(char *Pobjectname)                          //~vXXER~
{                                                                  //~vXXEI~
  	GtkWidget *pwd;                                                //~vXXEI~
//********************************                                 //~vXXEI~
  	pwd=lookup_widget(GTK_WIDGET(Gpframe),Pobjectname);            //~vXXER~
	if (!pwd)                                                      //~vXXEI~
    	return 4;                                                  //~vXXEI~
    dprintf("uactivate_menuitem name=%s,menuitem=%p\n",Pobjectname,pwd);//~var8R~
	gtk_menu_item_activate(GTK_MENU_ITEM(pwd));                    //~vXXER~
    return 0;                                                      //~vXXEI~
}//uactivate_menuitem                                              //~vXXER~
//**************************************************************** //~vXXEI~
//*rc:ret code                                                     //~vXXEI~
//**************************************************************** //~vXXEI~
int uclick_toolbarbutton(char *Pobjectname)                        //~vXXEI~
{                                                                  //~vXXEI~
  	GtkWidget *pwd;                                                //~vXXEI~
//********************************                                 //~vXXEI~
  	pwd=lookup_widget(GTK_WIDGET(Gpframe),Pobjectname);            //~vXXEI~
	if (!pwd)                                                      //~vXXEI~
    	return 4;                                                  //~vXXEI~
//#ifndef OPTGTK3                                                  //~var8R~
	gtk_signal_emit_by_name(GTK_OBJECT(pwd),"clicked","popupmenu");//~vXXEI~
//#else                                                            //~var8R~
//    csub_gtk_signal_emit_by_name(GTK_OBJECT(pwd),"clicked","popupmenu");//~var8R~
//#endif                                                           //~var8R~
    return 0;                                                      //~vXXEI~
}//uclick_toolbarbutton                                            //~vXXEI~
//**************************************************************** //~v68iI~
//*rc:ret code                                                     //~v68iI~
//**************************************************************** //~v68iR~
void usetfocus(void)                                               //~v68iI~
{      	                                                           //~v68iR~
//  GtkWidget *top;                                                //~v68jR~
//********************************                                 //~v68iI~
dprintf("usetfocus isuue gtkwindow_present\n");                    //~var8R~
////  gtk_widget_grab_focus (Gpview);                              //~v68iR~
//dprintf("usetfocus signal=%d\n",GTK_WIDGET_GET_CLASS(Gpview)->activate_signal);//~v68iR~
////  rc=gtk_widget_activate(Gpview);                              //~v68iR~
//dprintf("usetfocus activate rc=%d\n",rc);                        //~v68iR~
//dprintf("usetfocus frame can get focus=%d\n",GTK_WIDGET_CAN_FOCUS(Gpframe));//~v68iR~
////  gtk_widget_grab_focus (Gpframe);                             //~v68iR~
//dprintf("usetfocus drame signal=%d\n",GTK_WIDGET_GET_CLASS(Gpframe)->activate_signal);//~v68iR~
////  rc=gtk_widget_activate(Gpframe);                             //~v68iR~
//dprintf("usetfocus frame activate rc=%d\n",rc);                  //~v68iR~
//    gtk_widget_show(Gpview);                                     //~v68iR~
//    gtk_widget_show(Gpframe);                                    //~v68iR~
//  gdk_window_raise(Gpframe->window);                             //~v68iR~
//  gdk_window_raise(Gpview->window);                              //~v68iI~
//  gtk_window_present(Gpview->window);                            //~v68iI~
//    gtk_window_present(Gpframe->window);                         //~v68iI~
//    rc=gtk_widget_activate(Gpframe);                             //~v68iI~
//    gtk_widget_show(Gpframe);                                    //~v68iI~
//    top=gtk_widget_get_toplevel(Gpframe);                        //~v68iR~
//dprintf("top from frame(%p)=%p\n",Gpframe,top);                  //~v68iR~
//    top=gtk_widget_get_toplevel(Gpview);                         //~v68iR~
//dprintf("top from view(%p)=%p\n",Gpview,top);                    //~v68iR~
//  gtk_window_iconify(GTK_WINDOW(Gpframe));                       //~v68iR~
    gtk_window_present(GTK_WINDOW(Gpframe));                       //~v68iI~
    return;                                                        //~v68iR~
}//usetfocus                                                       //~v68iI~
//**************************************************************** //~v685R~
//* use client_event(connect signal by Glade is required)          //~v685I~
//* signal_emit,gtk_main_do_event,gtk_widget_event is all syncronouse//~v685R~
//* (but dialog msg allow schedule other msg)                      //~v685R~
//* gdk_event_put is asynchronouse                                 //~v685I~
//**************************************************************** //~v685R~
int upostmsg(UINT Pmsg,ULONG Pwparm,ULONG Plparm)                  //~v685R~
{                                                                  //~v685R~
    GdkEventClient send_event; //gdk_event_put enq copyed event    //~v685R~
#ifndef OPTGTK3                                                    //~var8R~
    GdkAtom atom=GDK_NONE;                                         //~v685R~
#else                                                              //~var8R~
    Atom atom;                                                     //~var8R~
#endif                                                             //~var8R~
//  BOOL retval=FALSE;	//used when emit                           //~v685R~
    int rc=0;                                                      //~v685I~
    GdkWindow *window;                                             //~v685I~
//********************************                                 //~v685R~
#ifndef OPTGTK3                                                    //~var8R~
    window=Gpview->window;                                         //~v685I~
#else                                                              //~var8R~
    window=gtk_widget_get_window(Gpview);                          //~var8R~
#endif                                                             //~var8R~
//  send_event = (GdkEventClient*)gdk_event_new (GDK_CLIENT_EVENT);//~v685R~
#ifndef OPTGTK3                                                    //~var8R~
    send_event.type=GDK_CLIENT_EVENT;                              //~v685I~
#else                                                              //~var8R~
    send_event.type=ClientMessage;	//xevent                       //~var8R~
#endif                                                             //~var8R~
#ifndef OPTGTK3
    send_event.window=window;                                      //~v685R~
#endif
    send_event.send_event=FALSE;  //?                              //~v685R~
#ifndef OPTGTK3
    send_event.message_type = atom;                                //~v685R~
#endif
#ifndef OPTGTK3
    send_event.data_format = 32;   //parm data is LONG[4]          //~v685R~
#else
    send_event.format = 32;   //parm data is LONG[4]               //~var8R~
#endif
    send_event.data.l[0] = (ULONG)Gpview; //uniq id to chk msg is to me//~v685R~
    send_event.data.l[1] = Pmsg;                                   //~v685R~
    send_event.data.l[2] = Pwparm;                                 //~v685R~
    send_event.data.l[3] = Plparm;                                 //~v685R~
    dprintf("client_event emit start event=%p\n",&send_event);     //~v685R~
//  g_signal_emit_by_name(GTK_OBJECT(widget),"client_event",send_event,&retval);//~v685R~
//  retval=gtk_widget_event(widget,send_event);                    //~v685R~
//  gtk_main_do_event(send_event);                                 //~v685R~
//  gdk_event_send_client_message_for_display (gtk_widget_get_display (widget), send_event, xid);//~v685R~
#ifndef OPTGTK3                                                    //~var8R~
    gdk_event_put((GdkEvent*)(&send_event));  //put on que copy of event//~v685R~
#else                                                              //~var8R~
	{                                                              //~var8R~
    Display *display;                                              //~var8R~
    Window w;                                                      //~var8R~
    //*************                                                //~var8R~
    w=GDK_WINDOW_XID(window);                                      //~var8R~
    send_event.window=w;                                           //~var8R~
    display=open_display();	//xxekbd.c	                           //~var8R~
    atom=XInternAtom(display,XEVENT_CLIENT_MSG_TYPE,FALSE/*only if exist*/);//to interface_msg_filter//~var8R~
    send_event.message_type = atom;                                //~var8R~
    XSendEvent(display,w,0/*propagate*/,0/*eventmask*/,(XEvent*)&send_event);//~var8R~
	close_display(display);                                        //~var8R~
    }                                                              //~var8R~
#endif                                                             //~var8R~
    dprintf("client_event send end\n");                            //~v685R~
    dprintf("upostmsg event=%p,parm=%lx,%lx\n",&send_event,Pwparm,Plparm);//~v685R~
//  gdk_event_free((GdkEvent*)send_event);	//cause abend even by gdk_event_new//~v685R~
    return rc;                                                     //~v685R~
}//upostmsg                                                        //~v685R~
//**************************************************************** //~v55ZI~
//setup timer callback                                             //~vXXEI~
//interval by miliseconds                                          //~vXXEI~
//*rc:ret timer handler id for killtimer                           //~vXXER~
//**************************************************************** //~v55ZI~
UINT usettimer(UINT Ptimerid,int Pintvlms,void *Pcallback)         //~vXXER~
{                                                                  //~v55ZI~
    UINT timerhandlerid;                                           //~vXXER~
//********************************                                 //~v55ZI~
	if (Pcallback)                                                 //~vXXEI~
//  	timerhandlerid=gtk_timeout_add(Pintvlms,Pcallback,(void*)Ptimerid);//~vXXER~//~va70R~
#ifndef OPTGTK3                                                    //~var8R~
    	timerhandlerid=gtk_timeout_add(Pintvlms,Pcallback,(void*)(ULONG)Ptimerid);//~va70I~
#else                                                              //~var8R~
    	timerhandlerid=g_timeout_add(Pintvlms,Pcallback,(void*)(ULONG)Ptimerid);//~var8R~
#endif                                                             //~var8R~
    else                                                           //~vXXEI~
//  	timerhandlerid=gtk_timeout_add(Pintvlms,xxemain_ontimer,(void*)Ptimerid);//~vXXER~//~va70R~
#ifndef OPTGTK3                                                    //~var8R~
  		timerhandlerid=gtk_timeout_add(Pintvlms,xxemain_ontimer,(void*)(ULONG)Ptimerid);//~va70I~
#else                                                              //~var8R~
  		timerhandlerid=g_timeout_add(Pintvlms,xxemain_ontimer,(void*)(ULONG)Ptimerid);//~var8R~
#endif                                                             //~var8R~
    return timerhandlerid;                                         //~vXXER~
}//usettimer                                                       //~v55ZI~
//**************************************************************** //~vXXER~
//*rc:ret code                                                     //~vXXER~
//**************************************************************** //~vXXER~
int ukilltimer(UINT Ptimerid)                                      //~vXXER~
{                                                                  //~vXXER~
#ifndef OPTGTK3                                                    //~var8R~
    gtk_timeout_remove(Ptimerid);                                  //~vXXER~
#else                                                              //~var8R~
    g_source_remove(Ptimerid);                                     //~var8R~
#endif                                                             //~var8R~
    return 0;                                                      //~vXXEI~
}//ukilltimer                                                      //~vXXER~
//**************************************************************** //~v55WI~
//*invalidate rect(emit expose event,write pixbuff to window)      //~vXXER~
//*rc:ret code                                                     //~v55WI~
//**************************************************************** //~v55WI~
int uinvalidate(int Popt)                                          //~vXXER~
{                                                                  //~v55WI~
    int hh,ww;                                                     //~vXXEI~
//********************************                                 //~v55WI~
#ifndef OPTGTK3                                                    //~var8R~
    ww=Gpview->allocation.width;                                   //~vXXEI~
    hh=Gpview->allocation.height;                                  //~vXXEI~
#else                                                              //~var8R~
	csub_get_widget_allocation_wh(Gpview,&ww,&hh);                 //~var8R~
#endif                                                             //~var8R~
    if (Popt)	//direct draw                                      //~vXXEI~
    {                                                              //~var8R~
#ifndef OPTGTK3                                                    //~var8R~
		gdk_draw_drawable(Gpview->window,                          //~vXXEI~
                      Gpview->style->fg_gc[GTK_WIDGET_STATE(Gpview)],//~vXXEI~
                      Gppixmap,                                    //~vXXEI~
                      0,0,0,0,ww,hh);                              //~vXXEI~
#else                                                              //~var8R~
		//*FIXME                                                   //~var8R~
#ifdef AAA                                                         //~var8R~
		csub_gdk_draw_drawable(Gpview,Gppixmap,0/*xsrc*/,0/*ysrc*/,0/*xdest*/,0/*ydest*/,ww,hh);//~var8R~
#else                                                              //~var8R~
	    gtk_widget_queue_draw(Gpview);//to window, emit signal expose(==draw on GTK3)//~var8R~
#endif                                                             //~var8R~
#endif                                                             //~var8R~
    }                                                              //~var8R~
    else                                                           //~vXXEI~
    {                                                              //~var8R~
#ifdef AAA                                                         //~v69VI~
	    gtk_widget_queue_draw_area(Gpview,0,0,ww,hh);              //~vXXER~
#else                                                              //~v69VI~
#ifndef OPTGTK3                                                    //~var8R~
		gdk_draw_drawable(Gpview->window,                          //~v69VI~
                      Gpview->style->fg_gc[GTK_WIDGET_STATE(Gpview)],//~v69VI~
                      Gppixmap,                                    //~v69VI~
                      0,0,0,0,ww,hh);                              //~v69VI~
#else                                                              //~var8R~
//  	csub_gdk_draw_drawable(Gpview,Gppixmap,0/*xsrc*/,0/*ysrc*/,0/*xdest*/,0/*ydest*/,ww,hh);//~var8R~
	    gtk_widget_queue_draw(Gpview);//to window, emit signal expose(==draw on GTK3)//~var8R~
#endif                                                             //~var8R~
#endif                                                             //~v69VI~
	}                                                              //~var8R~
    dprintf("uinvalidate\n");                                      //~v78DR~
    return 0;                                                      //~vXXER~
}//ureqredraw                                                      //~v55WI~
//===============================================================================//~2907I~
//get ini file on work dir                                         //~2907I~
//===============================================================================//~2907I~
int ugetinidata(PWXEINIDATA Ppwxeini)                              //~2907I~
{                                                                  //~2907I~
	int rc=0,len;                                                  //~2907R~
//	char fnm[_MAX_PATH];                                           //~vbu0R~
  	char fnm[_MAX_PATH+32];                                        //~vbu0I~
    WXEINIDATA wei;                                                //~2907I~
    FILE *fh;                                                      //~2907I~
//************************************                             //~2907I~
    sprintf(fnm,"%s%s",Gworkdir,INI_FILENAME);                     //~vXXER~
    memset(Ppwxeini,0,sizeof(WXEINIDATA));                         //~2907I~
	fh=fopen(fnm,"rb");                                            //~2907I~
    if (!fh)                                                       //~2907I~
		return 1;                                                  //~2907I~
    rc=iniacrnmchk(fh);                                            //~2907I~
    if (!rc)                                                       //~2907I~
    {                                                              //~2907I~
		len=fread(&wei,1,sizeof(wei),fh);                          //~2907R~
    	if (len!=sizeof(wei))                                      //~2907I~
        	rc=4;                                                  //~2907I~
	    dprintf("%s:WXEINIframe width=%d,height=%d\n",UTT,wei.WXEINIframewidth,wei.WXEINIframeheight);//~vbA3I~
	    UTRACEP("%s:WXEINIframe width=%d,height=%d\n",UTT,wei.WXEINIframewidth,wei.WXEINIframeheight);//~vbA3I~
//        if (wei.WXEINIver!=WXE_VER)                              //~vXXER~
//        {                                                        //~vXXER~
//            uerrmsgbox("Old Version ini file(%s);Delete then restart.",0,//~vXXER~
//                        fnm);                                    //~vXXER~
//            rc=2;                                                //~vXXER~
//        }                                                        //~vXXER~
    }                                                              //~2907I~
    if (!rc)                                                       //~2907I~
    	rc=iniacrnmchk(fh);                                        //~2907I~
    if (rc)                                                        //~vXXER~
    	uerrmsgbox("Invalid format ini file(%s), It may be of old version.",0,//~vXXER~
					fnm);                                          //~2907R~
    if (!rc)                                                       //~2907I~
    	memcpy(Ppwxeini,&wei,sizeof(WXEINIDATA));                  //~2907R~
    fclose(fh);                                                    //~2907I~
    UTRACED("ugetinidata WXEINIDATA",Ppwxeini,(int)WXEINIDATASZ);  //~vb7zR~
    return rc;                                                     //~2907I~
}//ugetinidata                                                     //~2907I~
//===============================================================================//~2907I~
//put ini file to work dir                                         //~2907I~
//===============================================================================//~2907I~
int uputinidata(PWXEINIDATA Ppwxeini)                              //~2907I~
{                                                                  //~2907I~
	int rc=0,len;                                                  //~2907R~
//  char fnm[_MAX_PATH];                                           //~vbu0R~
    char fnm[_MAX_PATH+32];                                        //~vbu0I~
    FILE *fh;                                                      //~2907I~
//************************************                             //~2907I~
    dprintf("%s:WXEINIframe width=%d,height=%d\n",UTT,Ppwxeini->WXEINIframewidth,Ppwxeini->WXEINIframeheight);//~vbA3I~
    UTRACEP("%s:WXEINIframe width=%d,height=%d\n",UTT,Ppwxeini->WXEINIframewidth,Ppwxeini->WXEINIframeheight);//~vbA3I~
    sprintf(fnm,"%s%s",Gworkdir,INI_FILENAME);                     //~vXXER~
	fh=fopen(fnm,"wb");                                            //~2907I~
    if (!fh)                                                       //~2907I~
    {                                                              //~2907I~
    	uerrmsgbox("ini file \"wb\" open failed(%s)",0,            //~2928R~
					fnm);                                          //~2928R~
		return 1;                                                  //~2907I~
    }                                                              //~2907I~
    rc=iniacrnmput(fh);                                            //~2907I~
    if (!rc)                                                       //~2907I~
    {                                                              //~2907I~
		len=fwrite(Ppwxeini,1,sizeof(WXEINIDATA),fh);              //~2907R~
    	if (len!=sizeof(WXEINIDATA))                               //~2907I~
        	rc=4;                                                  //~2907I~
    }                                                              //~2907I~
    if (!rc)                                                       //~2907I~
    	rc=iniacrnmput(fh);                                        //~2907I~
    if (rc)                                                        //~2907I~
    	uerrmsgbox("ini file write failed(%s)",0,                  //~2907I~
					fnm);                                          //~2907R~
    fclose(fh);                                                    //~2907I~
    UTRACED("uputinidata WXEINIDATA",Ppwxeini,(int)WXEINIDATASZ);  //~vb7zR~
    return rc;                                                     //~2907I~
}//uputinidata                                                     //~2907I~
//===============================================================================//~2907I~
//ini file acronym chk                                             //~2907I~
//===============================================================================//~2907I~
int  iniacrnmchk(FILE *Pfh)                                        //~2907I~
{                                                                  //~2907I~
	int rc=0,len;                                                  //~2907I~
	char *inidata[256];                                            //~2907I~
//************************************                             //~2907I~
	len=fread(inidata,1,sizeof(INI_ACRNM),Pfh);                    //~2907I~
    if (len!=sizeof(INI_ACRNM))                                    //~2907I~
    	rc=4;                                                      //~2907I~
    if (!rc)                                                       //~2907I~
    	if (memcmp(inidata,INI_ACRNM,sizeof(INI_ACRNM)))           //~2907R~
        	rc=4;                                                  //~2907I~
    return rc;                                                     //~2907I~
}//iniacrnmchk                                                     //~2907I~
//===============================================================================//~2907I~
//ini file acronym put                                             //~2907I~
//===============================================================================//~2907I~
int  iniacrnmput(FILE *Pfh)                                        //~2907I~
{                                                                  //~2907I~
	int rc=0,len;                                                  //~2907I~
//************************************                             //~2907I~
	len=fwrite(INI_ACRNM,1,sizeof(INI_ACRNM),Pfh);                 //~2907R~
    if (len!=sizeof(INI_ACRNM))                                    //~2907I~
    	rc=4;                                                      //~2907I~
    return rc;                                                     //~2907I~
}//iniacrnmput                                                     //~2907I~
//*************************************************************    //~2922I~
//*get current path                                                //~2922I~
//*rc:1:path changed after prev                                    //~2922I~
//*************************************************************    //~2922I~
int  ugetcpath(char *Ppath)                                        //~2922I~
{                                                                  //~2922I~
	int rc;                                                        //~2922I~
static 	char Scpath[_MAX_PATH];                                    //~2922I~
//***********************                                          //~2922I~
	ugetcwd(Ppath);                                                //~2922I~
    if (strcmp(Ppath,Scpath))                                      //~2922I~
    {                                                              //~2922I~
    	strcpy(Scpath,Ppath);                                      //~2922I~
    	rc=1;                                                      //~2922I~
    }                                                              //~2922I~
    else                                                           //~2922I~
    	rc=0;                                                      //~2922I~
    return rc;                                                     //~2922I~
}//ugetcpath                                                       //~2922I~
//*************************************************************    //~2923I~
//*get tempfilename on workdir                                     //~2923I~
//*option:1 use Gworkdir if avail                                  //~2A12I~
//*************************************************************    //~2923I~
int ugettempfname(int Popt,char *Ptempnam)                         //~2A12R~
{                                                                  //~2923I~
	int rc;                                                        //~2929R~
//static int Stmpdirsw=0;                                          //~vXXER~
//***********************                                          //~2923I~
    if (Popt==1 && *Gworkdir)  //xe called once                    //~2A12R~
    	strcpy(Ptempnam,Gworkdir);                                 //~2A12R~
    else                                                           //~2A12I~
    {                                                              //~2A12I~
		usetupwdtemp();                                            //~2A12I~
    	strcpy(Ptempnam,Swdtemp);                                  //~2A12I~
    }                                                              //~2A12I~
    rc=utempnam(Ptempnam,"nf_",Ptempnam)!=0;     //dir,prefix,outarea//~2929R~
    return rc;                                                     //~2923I~
}//ugettempfname                                                   //~2923I~
#ifndef XXE                                                        //~vXXEM~
//*************************************************************    //~2A12M~
//*allocate dummy file for the case no filename parm in cmdline    //~2A12M~
//*  to avoid filename prompt at "save file"                       //~2A12M~
//*************************************************************    //~2A12M~
void uallocdummynewfile(char *Pfnm)                                //~2A12M~
{                                                                  //~2A12M~
	FILE *fh;                                                      //~2A12M~
//****************************                                     //~2A12M~
	ugettempfname(0,Pfnm); 		//temp on wxe work                 //~2A12M~
    strcpy(Pfnm+PATHLEN(Pfnm),"tmpfile");                          //~2A12M~
	if (ufstat(Pfnm,0))	//not found                                //~2A12M~
    {                                                              //~2A12M~
		fh=fopen(Pfnm,"w");                                        //~2A12M~
		fclose(fh);                                                //~2A12M~
    }                                                              //~2A12M~
    return;                                                        //~2A12M~
}//uallocdummynewfile                                              //~2A12M~
////===============================================================================//~2B30R~
////get ini file on work dir                                       //~2B30R~
////===============================================================================//~2B30R~
//int usetupwd(void)                                               //~2B30R~
//{                                                                //~2B30R~
//    char *fnm;                                                   //~2B30R~
//static int Ssetupwd=0;                                           //~2B30R~
////************************************                           //~2B30R~
//    if (!Ssetupwd)                                               //~2B30R~
//    {                                                            //~2B30R~
//        Ssetupwd=1;                                              //~2B30R~
//        fnm=WXE_WKDIR;                                           //~2B30R~
//        if (ufstat(fnm,0))  //not found                          //~2B30R~
//        {                                                        //~2B30R~
//            if (!umkdir(fnm))                                    //~2B30R~
//                uerrmsgbox("WorkDir %s is for %s now created",0, //~2B30R~
//                        fnm,WXE_PGMNAME);                        //~2B30R~
//            else                                                 //~2B30R~
//                uerrmsgbox("WorkDir %s for %s created",0,        //~2B30R~
//                        fnm,WXE_PGMNAME);                        //~2B30R~
//        }                                                        //~2B30R~
//    }                                                            //~2B30R~
//    return 0;                                                    //~2B30R~
//}//usetupwd                                                      //~2B30R~
#endif                                                             //~vXXEI~
//*************************************************************    //~2A12I~
//*get tempfilename on workdir                                     //~2A12I~
//*option:1 use Gworkdir if avail                                  //~2A12I~
//*************************************************************    //~2A12I~
int usetupwdtemp(void)                                             //~2A12I~
{                                                                  //~2A12I~
static int Ssetupwdtemp=0;                                         //~2A12I~
	int rc=0;                                                      //~2B30I~
//***********************                                          //~2A12I~
	if (!Ssetupwdtemp)                                             //~2A12I~
    {                                                              //~2A12I~
		Ssetupwdtemp=1;                                            //~2A12I~
		strcpy(Swdtemp,Gworkdir);                                  //~2B30I~
		strcat(Swdtemp,WXE_TEMPDIR);                               //~2B30I~
        if (ufstat(Swdtemp,0)) //not found                         //~2A12I~
        	rc=umkdir(Swdtemp);                                    //~2B30R~
    }                                                              //~2A12I~
    return rc;                                                     //~2B30R~
}//usetupwdtemp                                                    //~2A12I~
//*************************************************************    //~2929I~
//*intf to umalloc                                                 //~2929I~
//*************************************************************    //~2929I~
void *umemalloc(int Plen)                                          //~2929I~
{                                                                  //~2929I~
	return umalloc(Plen);	                                       //~2929I~
}//umemalloc                                                       //~2929I~
//*************************************************************    //~2929I~
//*intf to ufree                                                   //~2929I~
//*************************************************************    //~2929I~
void umemfree(void *Paddr)                                         //~2929I~
{                                                                  //~2929I~
	ufree(Paddr);                                                  //~2929I~
    return;                                                        //~2929I~
}//umemfree                                                        //~2929I~
//*************************************************************    //~v53tI~
//*intf to malloc                                                  //~v53tI~
//*************************************************************    //~v53tI~
void *wxemalloc(int Plen)                                          //~v53tI~
{                                                                  //~v53tI~
	return malloc(Plen);                                           //~v53tI~
}//wxemalloc                                                       //~v53tI~
//*************************************************************    //~v53tI~
//*intf to free                                                    //~v53tI~
//*************************************************************    //~v53tI~
void wxefree(void *Paddr)                                          //~v53tI~
{                                                                  //~v53tI~
	free(Paddr);                                                   //~v53tI~
    return;                                                        //~v53tI~
}//wxefree                                                         //~v53tI~
//*************************************************************    //~v69rI~
//*print api err message                                           //~v69rI~
//*************************************************************    //~v69rI~
void csubprintgerror(char *Pfile,int Pline,char *Pcmt,GError *Ppgerr)//~v69rR~
{                                                                  //~v69rI~
    if (Ppgerr==NULL)                                              //~v69rR~
    	return;                                                    //~v69rI~
//  dprintf("%s %s:%d %s: %s\n",(char*)utimeedit("HHMMSS.MIL",0),Pfile,Pline,Pcmt,Ppgerr->message);//+vbBzR~
    fprintf(stderr,"%s %s:%d %s: %s\n",(char*)utimeedit("HHMMSS.MIL",0),Pfile,Pline,Pcmt,Ppgerr->message);//+vbBzI~
    g_error_free(Ppgerr);                                          //~v69rI~
}//csubprintgerror                                                 //~v69rI~
//*************************************************************    //~v69sI~
//*locale to utf8 conversion with null replacing to space          //~v69sI~
//*************************************************************    //~v69sI~
//*************************************************************    //~v69QI~
//*glib/convert.c                                                  //~v69QI~
//*************************************************************    //~v69QI~
//gchar *                                                          //~v69QI~
//g_locale_to_utf8 (const gchar  *opsysstring,                     //~v69QI~
//          gssize        len,                                     //~v69QI~
//          gsize        *bytes_read,                              //~v69QI~
//          gsize        *bytes_written,                           //~v69QI~
//          GError      **error)                                   //~v69QI~
//{                                                                //~v69QI~
//  const char *charset;                                           //~v69QI~
//  if (g_get_charset (&charset))                                  //~v69QI~
//    return strdup_len (opsysstring, len, bytes_read, bytes_written, error);//~v69QI~
//  else                                                           //~v69QI~
//    return g_convert (opsysstring, len,                          //~v69QI~
//              "UTF-8", charset, bytes_read, bytes_written, error);//~v69QI~
//}                                                                //~v69QI~
//gchar*                                                           //~v69QI~
//g_convert (const gchar *str,                                     //~v69QI~
//           gssize       len,                                     //~v69QI~
//           const gchar *to_codeset,                              //~v69QI~
//           const gchar *from_codeset,                            //~v69QI~
//           gsize       *bytes_read,                              //~v69QI~
//       gsize       *bytes_written,                               //~v69QI~
//       GError     **error)                                       //~v69QI~
//{                                                                //~v69QI~
//  gchar *res;                                                    //~v69QI~
//  GIConv cd;                                                     //~v69QI~
//  g_return_val_if_fail (str != NULL, NULL);                      //~v69QI~
//  g_return_val_if_fail (to_codeset != NULL, NULL);               //~v69QI~
//  g_return_val_if_fail (from_codeset != NULL, NULL);             //~v69QI~
//  cd = open_converter (to_codeset, from_codeset, error);         //~v69QI~
//  if (cd == (GIConv) -1)                                         //~v69QI~
//    {                                                            //~v69QI~
//      if (bytes_read)                                            //~v69QI~
//        *bytes_read = 0;                                         //~v69QI~
//      if (bytes_written)                                         //~v69QI~
//        *bytes_written = 0;                                      //~v69QI~
//      return NULL;                                               //~v69QI~
//    }                                                            //~v69QI~
//  res = g_convert_with_iconv (str, len, cd,                      //~v69QI~
//                  bytes_read, bytes_written,                     //~v69QI~
//                  error);                                        //~v69QI~
//  close_converter (cd);                                          //~v69QI~
//  return res;                                                    //~v69QI~
//}                                                                //~v69QI~
//static GIConv                                                    //~v69QI~
//open_converter (const gchar *to_codeset,                         //~v69QI~
//        const gchar *from_codeset,                               //~v69QI~
//        GError     **error)                                      //~v69QI~
//{                                                                //~v69QI~
//  struct _iconv_cache_bucket *bucket;                            //~v69QI~
//  gchar *key;                                                    //~v69QI~
//  GIConv cd;                                                     //~v69QI~
//  /* create our key */                                           //~v69QI~
//  key = g_alloca (strlen (from_codeset) + strlen (to_codeset) + 2);//~v69QI~
//  _g_sprintf (key, "%s:%s", from_codeset, to_codeset);           //~v69QI~
//  G_LOCK (iconv_cache_lock);                                     //~v69QI~
//  /* make sure the cache has been initialized */                 //~v69QI~
//  iconv_cache_init ();                                           //~v69QI~
//  bucket = g_hash_table_lookup (iconv_cache, key);               //~v69QI~
//  if (bucket)                                                    //~v69QI~
//    {                                                            //~v69QI~
//      if (bucket->used)                                          //~v69QI~
//        {                                                        //~v69QI~
//          cd = g_iconv_open (to_codeset, from_codeset);          //~v69QI~
//          if (cd == (GIConv) -1)                                 //~v69QI~
//            goto error;                                          //~v69QI~
//        }                                                        //~v69QI~
//      else                                                       //~v69QI~
//        {                                                        //~v69QI~
//      /* Apparently iconv on Solaris <= 7 segfaults if you pass in//~v69QI~
//       * NULL for anything but inbuf; work around that. (NULL outbuf//~v69QI~
//       * or NULL *outbuf is allowed by Unix98.)                  //~v69QI~
//       */                                                        //~v69QI~
//      gsize inbytes_left = 0;                                    //~v69QI~
//      gchar *outbuf = NULL;                                      //~v69QI~
//      gsize outbytes_left = 0;                                   //~v69QI~
//          cd = bucket->cd;                                       //~v69QI~
//          bucket->used = TRUE;                                   //~v69QI~
//          /* reset the descriptor */                             //~v69QI~
//          g_iconv (cd, NULL, &inbytes_left, &outbuf, &outbytes_left);//~v69QI~
//        }                                                        //~v69QI~
//      bucket->refcount++;                                        //~v69QI~
//    }                                                            //~v69QI~
//  else                                                           //~v69QI~
//    {                                                            //~v69QI~
//      cd = g_iconv_open (to_codeset, from_codeset);              //~v69QI~
//      if (cd == (GIConv) -1)                                     //~v69QI~
//        goto error;                                              //~v69QI~
//      iconv_cache_expire_unused ();                              //~v69QI~
//      bucket = iconv_cache_bucket_new (key, cd);                 //~v69QI~
//    }                                                            //~v69QI~
//  g_hash_table_insert (iconv_open_hash, cd, bucket->key);        //~v69QI~
//  G_UNLOCK (iconv_cache_lock);                                   //~v69QI~
//  return cd;                                                     //~v69QI~
// error:                                                          //~v69QI~
//  G_UNLOCK (iconv_cache_lock);                                   //~v69QI~
//  /* Something went wrong.  */                                   //~v69QI~
//  if (error)                                                     //~v69QI~
//    {                                                            //~v69QI~
//      if (errno == EINVAL)                                       //~v69QI~
//    g_set_error (error, G_CONVERT_ERROR, G_CONVERT_ERROR_NO_CONVERSION,//~v69QI~
//             _("Conversion from character set '%s' to '%s' is not supported"),//~v69QI~
//             from_codeset, to_codeset);                          //~v69QI~
//      else                                                       //~v69QI~
//    g_set_error (error, G_CONVERT_ERROR, G_CONVERT_ERROR_FAILED, //~v69QI~
//             _("Could not open converter from '%s' to '%s'"),    //~v69QI~
//             from_codeset, to_codeset);                          //~v69QI~
//    }                                                            //~v69QI~
//  return cd;                                                     //~v69QI~
//}                                                                //~v69QI~
//gchar*                                                           //~v69QI~
//g_convert_with_iconv (const gchar *str,                          //~v69QI~
//              gssize       len,                                  //~v69QI~
//              GIConv       converter,                            //~v69QI~
//              gsize       *bytes_read,                           //~v69QI~
//              gsize       *bytes_written,                        //~v69QI~
//              GError     **error)                                //~v69QI~
//{                                                                //~v69QI~
//  gchar *dest;                                                   //~v69QI~
//  gchar *outp;                                                   //~v69QI~
//  const gchar *p;                                                //~v69QI~
//  const gchar *shift_p = NULL;                                   //~v69QI~
//  gsize inbytes_remaining;                                       //~v69QI~
//  gsize outbytes_remaining;                                      //~v69QI~
//  gsize err;                                                     //~v69QI~
//  gsize outbuf_size;                                             //~v69QI~
//  gboolean have_error = FALSE;                                   //~v69QI~
//  gboolean done = FALSE;                                         //~v69QI~
//  g_return_val_if_fail (converter != (GIConv) -1, NULL);         //~v69QI~
//  if (len < 0)                                                   //~v69QI~
//    len = strlen (str);                                          //~v69QI~
//  p = str;                                                       //~v69QI~
//  inbytes_remaining = len;                                       //~v69QI~
//  outbuf_size = len + 1; /* + 1 for nul in case len == 1 */      //~v69QI~
//  outbytes_remaining = outbuf_size - 1; /* -1 for nul */         //~v69QI~
//  outp = dest = g_malloc (outbuf_size);                          //~v69QI~
//  while (!done && !have_error)                                   //~v69QI~
//    {                                                            //~v69QI~
//      err = g_iconv (converter, (char **)&p, &inbytes_remaining, &outp, &outbytes_remaining);//~v69QI~
//      if (err == (size_t) -1)                                    //~v69QI~
//    {                                                            //~v69QI~
//      switch (errno)                                             //~v69QI~
//        {                                                        //~v69QI~
//        case EINVAL:                                             //~v69QI~
//          /* Incomplete text, do not report an error */          //~v69QI~
//          done = TRUE;                                           //~v69QI~
//          break;                                                 //~v69QI~
//        case E2BIG:                                              //~v69QI~
//          {                                                      //~v69QI~
//        size_t used = outp - dest;                               //~v69QI~
//        outbuf_size *= 2;                                        //~v69QI~
//        dest = g_realloc (dest, outbuf_size);                    //~v69QI~
//        outp = dest + used;                                      //~v69QI~
//        outbytes_remaining = outbuf_size - used - 1; /* -1 for nul *///~v69QI~
//          }                                                      //~v69QI~
//          break;                                                 //~v69QI~
//        case EILSEQ:                                             //~v69QI~
//          if (error)                                             //~v69QI~
//        g_set_error (error, G_CONVERT_ERROR, G_CONVERT_ERROR_ILLEGAL_SEQUENCE,//~v69QI~
//                 _("Invalid byte sequence in conversion input"));//~v69QI~
//          have_error = TRUE;                                     //~v69QI~
//          break;                                                 //~v69QI~
//        default:                                                 //~v69QI~
//          if (error)                                             //~v69QI~
//        g_set_error (error, G_CONVERT_ERROR, G_CONVERT_ERROR_FAILED,//~v69QI~
//                 _("Error during conversion: %s"),               //~v69QI~
//                 g_strerror (errno));                            //~v69QI~
//          have_error = TRUE;                                     //~v69QI~
//          break;                                                 //~v69QI~
//        }                                                        //~v69QI~
//    }                                                            //~v69QI~
//      else                                                       //~v69QI~
//    {                                                            //~v69QI~
//      if (!shift_p)                                              //~v69QI~
//        {                                                        //~v69QI~
//          /* call g_iconv with NULL inbuf to cleanup shift state *///~v69QI~
//          shift_p = p;                                           //~v69QI~
//          p = NULL;                                              //~v69QI~
//          inbytes_remaining = 0;                                 //~v69QI~
//        }                                                        //~v69QI~
//      else                                                       //~v69QI~
//        done = TRUE;                                             //~v69QI~
//    }                                                            //~v69QI~
//    }                                                            //~v69QI~
//  if (shift_p)                                                   //~v69QI~
//    p = shift_p;                                                 //~v69QI~
//  *outp = '\0';                                                  //~v69QI~
//  if (bytes_read)                                                //~v69QI~
//    *bytes_read = p - str;                                       //~v69QI~
//  else                                                           //~v69QI~
//    {                                                            //~v69QI~
//      if ((p - str) != len)                                      //~v69QI~
//    {                                                            //~v69QI~
//          if (!have_error)                                       //~v69QI~
//            {                                                    //~v69QI~
//          if (error)                                             //~v69QI~
//        g_set_error (error, G_CONVERT_ERROR, G_CONVERT_ERROR_PARTIAL_INPUT,//~v69QI~
//                 _("Partial character sequence at end of input"));//~v69QI~
//              have_error = TRUE;                                 //~v69QI~
//            }                                                    //~v69QI~
//    }                                                            //~v69QI~
//    }                                                            //~v69QI~
//  if (bytes_written)                                             //~v69QI~
//    *bytes_written = outp - dest;   /* Doesn't include '\0' */   //~v69QI~
//  if (have_error)                                                //~v69QI~
//    {                                                            //~v69QI~
//      g_free (dest);                                             //~v69QI~
//      return NULL;                                               //~v69QI~
//    }                                                            //~v69QI~
//  else                                                           //~v69QI~
//    return dest;                                                 //~v69QI~
//}                                                                //~v69QI~
//char *csublocale2utf8(char *Ptext,int Plen,int *Ppreadlen,int *Ppwritelen)//~v69VR~
//************************************************************     //~v69VI~
//*rc:4 err,1:ascii(0x00-0x7f) only(don't free utf8 buff)           //~v69VI~//~vam4R~
//*out utf8 is strZ                                                //~vam4I~
//************************************************************     //~v69VI~
//int csublocale2utf8(char *Ptext,int Plen,int *Ppreadlen,char **Pputf8,int *Ppwritelen)//~v79zR~
int csublocale2utf8(int Popt,char *Ptext,int Plen,int *Ppreadlen,char **Pputf8,int *Ppwritelen)//~v79zI~
{                                                                  //~v69sI~
//#define INVALIDCH '?'                                              //~v69XI~//~v79YR~
#define INVALIDCH '.'                                              //~v79YI~
//#define MAXUTF8CHSZ 6                                            //~va1cR~
static char *Sbuff=0;                                              //~v69sI~
static int   Sbufflen=0;                                           //~v69sI~
    gchar *putf8;                                                  //~v69XI~
  	UCHAR *pc,*pc2,*pcout,*plinech;                                //~va1cR~
    const gchar *pcinvalid;                                        //~va1cR~
//  int readlen,writelen,linechlen;                                //~v7axR~
    gsize readlen,writelen;                                        //~v7axI~
    int linechlen;                                                 //~v7axI~
    GError *perr;/*=NULL*/                                         //~v706R~
    int len,reslen,ch,utflen;                                      //~v69XR~
    int envutf8sw;                                                 //~v79zI~
#ifndef UTF8SUPPH                                                  //~vaa7I~
    int eucjsw,ss3sw;                                              //~v7adI~
#endif                                                             //~vaa7I~
//****************************                                     //~v69sI~
UTRACED("locale2utf8 in",Ptext,Plen);                              //~v69XI~
//  if (Sisutf8)    //current is not utf8                          //~v69VR~
//  	return Ptext;	//no need to convert;do not gfree if Ptext returned//~v69VR~
//if (!Sisutf8)    //current is not utf8                           //~v79zR~
  envutf8sw=(Popt & CSL2UO_ENCENV) && (Gwxestat & GWXES_ENVISUTF8);//~v79zR~
#ifndef UTF8SUPPH                                                  //~vaa7I~
  eucjsw=!envutf8sw && UDBCSCHK_ISEUCJ();                          //~v7adI~
#endif                                                             //~vaa7I~
  if (!envutf8sw)    //current is not utf8                         //~v79zI~
  {                                                                //~v69VI~
    if (Sconverterdescriptor==(GIConv)-1) //no converter           //~v69QR~
//  	return Ptext;	//no conversion                            //~v69VR~
        ;                                                          //~v69VI~
    else             	//no conversion                            //~v69VI~
    if (Sconverterdescriptor==0)                                   //~v69QI~
        csubutf8init();                                            //~v69QI~
  }                                                                //~v69VI~
	if (Plen>Sbufflen)                                             //~v69sI~
    {                                                              //~v69sI~
    	if (Sbuff)                                                 //~v69sI~
        	free(Sbuff);                                           //~v69sR~
        Sbufflen=0;                                                //~v69sI~
//      Sbuff=malloc(Plen);                                        //~v69VR~
//      Sbuff=malloc(Plen+1);                                      //~v69XR~
//      Sbuff=malloc(Plen*MAXUTF8CHSZ+1);	//6:max utfcode size   //~va1cR~
        Sbuff=malloc(Plen*UTF8_MAXCHARSZMAX+1);	//6:max utfcode size//~va1cR~
        if (Sbuff)                                                 //~v69sI~
	        Sbufflen=Plen;                                         //~v69sI~
    }                                                              //~v69sI~
//  ptext=Ptext;                                                   //~v69VR~
    if (!Sbuff)                                                    //~v69VR~
    	return 4;                                                  //~v69VI~
//  if (Sbuff)                                                     //~v69VI~
//  {                                                              //~v69VI~
//        if (pc=memchr(Ptext,0,(UINT)Plen),pc)                    //~v69VR~
//        {                                                        //~v69VR~
//            len=(int)((ULONG)pc-(ULONG)Ptext);                   //~v69VR~
//            memcpy(Sbuff,Ptext,(UINT)len);                       //~v69VR~
//            for (pce=Ptext+Plen,pc2=Sbuff+len;pc<pce;pc++)       //~v69VR~
//            {                                                    //~v69VR~
//                if (!*pc)                                        //~v69VR~
//                    *pc2++=' ';                                  //~v69VR~
//                else                                             //~v69VR~
//                    *pc2++=*pc;                                  //~v69VR~
//            }                                                    //~v69VR~
//            ptext=Sbuff;                                         //~v69VR~
//        }                                                        //~v69VR~
//    for (ii=Plen,pc=Ptext,pc2=Sbuff;ii>0;ii--)                   //~v69XR~
//    {                                                            //~v69XR~
//        ch=*pc++;                                                //~v69XR~
//        if (!ch)                                                 //~v69XR~
//            *pc2++=' ';                                          //~v69XR~
//        else                                                     //~v69XR~
//        {                                                        //~v69XR~
//            *pc2++=ch;                                           //~v69XR~
//            if (ch>=0x80)                                        //~v69XR~
//                noascii=1;                                       //~v69XR~
//        }                                                        //~v69XR~
//    }                                                            //~v69XR~
	for (pc=Ptext,pcout=Sbuff,reslen=Plen;reslen>0;)               //~v69XI~
    {                                                              //~v69XI~
        ch=*pc;                                                    //~v69XI~
        if (!ch)                                                   //~v69XI~
        {                                                          //~v69XI~
          if (Popt & CSL2UO_NULLALT)//0x08    //rep null by '.' for gtkprint//~vam4I~
            *pcout++='.';                                          //~vam4I~
          else                                                     //~vam4I~
            *pcout++=' ';                                          //~v69XI~
            pc++;                                                  //~v69XI~
            reslen--;                                              //~v69XI~
            continue;                                              //~v69XI~
        }                                                          //~v69XI~
        if (ch<0x20)    //ctlch                                    //~v69XI~
        {                                                          //~v69XI~
        	if ((plinech=Sacsmap[(UINT)(*pc)]))	//line drawing char defined//~v69XR~
            {                                                      //~v69XI~
//              linechlen=strlen(plinech);                         //~v705R~
                linechlen=Sacslentb[(int)(*pc)];                   //~v705R~
                memcpy(pcout,plinech,linechlen);                   //~v69XI~
                pcout+=linechlen;                                  //~v69XI~
            }                                                      //~v69XI~
            else                                                   //~v69XI~
            if ((ch==0x0a||ch==0x0d) && (Popt & CSL2UO_REP0a0d))   //~v79QI~
                *pcout++=INVALIDCH;	//current gtk version erase 0a...0d combination//~v79QI~
            else                                                   //~v79QI~
            	*pcout++=ch;	//no conversion                    //~v69XI~
            pc++;                                                  //~v69XI~
            reslen--;                                              //~v69XI~
            continue;                                              //~v69XI~
        }//linech defined                                          //~v69XI~
        if (ch<0x80)    //ascii;                                   //~v69XI~
        {                                                          //~v69XI~
            *pcout++=ch;                                           //~v69XI~
            pc++;                                                  //~v69XI~
            reslen--;                                              //~v69XI~
            continue;                                              //~v69XI~
        }                                                          //~v69XI~
//**  >=0x80                                                       //~v69XI~
#ifndef UTF8SUPPH                                                  //~vaa7I~
        ss3sw=0;                                                   //~v7adI~
#endif                                                             //~vaa7I~
        for (pc2=pc,len=0;len<reslen;len++,pc2++) //search next ascii//~v69XI~
        {                                                          //~v69XI~
#ifdef UTF8SUPPH                                                   //~va1cR~
            if (UDBCSCHK_ISGB4STR(pc2,reslen-len))                 //~va1cR~
            {                                                      //~va1cR~
                len+=UDBCSCHK_GB4SZ-1;                             //~va1cR~
                pc2+=UDBCSCHK_GB4SZ-1;                             //~va1cR~
                continue;                                          //~va1cR~
            }                                                      //~va1cR~
            if (ISSS3STR(pc2,reslen-len))                          //~va1cR~
            {                                                      //~va1cR~
                len+=UDBCSCHK_SS3SZ-1;                             //~va1cR~
                pc2+=UDBCSCHK_SS3SZ-1;                             //~va1cR~
                continue;                                          //~va1cR~
            }                                                      //~va1cR~
//          if (UDBCSCHK_ISDBCS1ST(*pc2))                          //~va1cR~//~vamGR~
            if (UDBCSCHK_ISDBCS1ST(*pc2) && (reslen-len)>1)        //~vamGI~
            {                                                      //~va1cR~
                len+=UDBCSCHK_DBCSSZ-1;                            //~va1cR~
                pc2+=UDBCSCHK_DBCSSZ-1;                            //~va1cR~
                continue;                                          //~va1cR~
            }                                                      //~va1cR~
#else                                                              //~va1cR~
            if (eucjsw                                             //~v7adI~
            &&  *pc2==SS3   //SS3+xxxx                             //~v7adI~
            &&  reslen-len>=3)                                     //~v7adI~
            {                                                      //~v7adI~
                if (!len) 	//previous dbcs                        //~v7adI~
                {                                                  //~v7adI~
                	len=3;	//1 char convert;else until before SS3 //~v7adI~
                    ss3sw=1;                                       //~v7adI~
                }                                                  //~v7adI~
                break;  //convert until before SS3                 //~v7adI~
            }                                                      //~v7adI~
#endif                                                             //~va1cR~
            if (*pc2<0x80)                                         //~v69XI~
                break;                                             //~v69XI~
        }                                                          //~v69XI~
        utflen=len;                                                //~v69XI~
//      if (Sisutf8)    //current is utf8                          //~v79zR~
        if (envutf8sw)    //current is utf8                        //~v79zI~
        {                                                          //~v69XR~
UTRACED("noconv",pc,len);                                          //~v69XI~
            if (!g_utf8_validate(pc,len,&pcinvalid))    //invalid exist//~v69XR~
                len=(ULONG)pcinvalid-(ULONG)pc;                    //~v69XR~
UTRACEP("noconv out len=%d pc=%p,invaplid=%p\n",len,pc,pcinvalid); //~v69XI~
            memcpy(pcout,pc,len);                                  //~v69XR~
            pcout+=len;                                            //~v69XR~
            reslen-=len;                                           //~v69XR~
            pc+=len;                                               //~v69XR~
            utflen-=len;                                           //~v69XI~
        }                                                          //~v69XR~
        else        //current is not utf8                          //~v69XR~
            if (Sconverterdescriptor!=(GIConv)-1) //converter exist//~v69XR~
            {                                                      //~v69XR~
//                    writelen=len*MAXUTF8CHSZ;     //buffsz       //~v69XI~
//                    readlen=len;                                 //~v69XI~
//                    pc2=pc;                                      //~v69XI~
//                    for (;;)                                     //~v69XI~
//                    {                                            //~v69XI~
//                        if (g_iconv(Sconverterdescriptor,(gchar **)(&pc2),&readlen,(gchar **)(&pcout),&writelen)==(size_t)-1) //err//~v69XI~
//                            break;                               //~v69XI~
//                    }                                            //~v69XI~
//                    len=(ULONG)pc2-(ULONG)pc;                    //~v69XI~
//                    reslen-=len;                                 //~v69XI~
//                    pc+=len;                                     //~v69XI~
//    UTRACEP("g_iconv out errno=%d,len=%d readlen=%d,writelen=%d readlen=%d pc2=%p,pcout=%p\n",errno,len,readlen,writelen,readlen,pc2,pcout);//~v69XI~
                perr=NULL;                                         //~v706I~
                putf8=g_convert_with_iconv(pc,len,Sconverterdescriptor,&readlen,&writelen,&perr);//~v69XR~
                PRINTGERR("csublocale2utf8-g_locale_to_utf8",perr);//~v69XR~
UTRACEP("iconv out putf8=%p len=%d,readlen=%d,writelen=%d\n",putf8,len,readlen,writelen);//~v69XI~
                if (putf8)                                         //~v69XR~
                {                                                  //~v69XR~
#ifndef UTF8SUPPH                                                  //~va1cR~
                	if (ss3sw)                                     //~v7adI~
                    {                                              //~v7adI~
                    	*pcout++=INVALIDCH;                        //~v7adI~
                    }                                              //~v7adI~
#endif                                                             //~va1cR~
                    memcpy(pcout,putf8,writelen);                  //~v69XR~
                    g_free(putf8);                                 //~v69XR~
UTRACED("iconv out",pcout,writelen);                               //~v69XI~
                    pc+=readlen;                                   //~v69XR~
                    reslen-=readlen;                               //~v69XR~
                    pcout+=writelen;                               //~v69XR~
                    utflen-=readlen;                               //~v69XI~
                }                                                  //~v69XR~
            }//converter exist                                     //~v69XR~
        if (utflen) // >0x80 invalid utf or no converter           //~v69XI~
        {                                                          //~v69XI~
            if ((plinech=Sacsmap[(UINT)(*pc)]))  //line drawing char defined//~v69XR~
            {                                                      //~v69XI~
//              linechlen=strlen(plinech);                         //~v705R~
                linechlen=Sacslentb[(int)(*pc)];                   //~v705R~
                memcpy(pcout,plinech,linechlen);                   //~v69XI~
                pcout+=linechlen;                                  //~v69XI~
            }                                                      //~v69XI~
            else                                                   //~v69XI~
                *pcout++=INVALIDCH;                                //~v69XI~
            pc++;                                                  //~v69XI~
            reslen--;                                              //~v69XI~
        }                                                          //~v69XI~
    }//reslen                                                      //~v69XI~
    *pcout=0;                                                      //~v69XI~
    *Pputf8=Sbuff;                                                 //~v69XI~
    if (Ppreadlen)                                                 //~v69XI~
    	*Ppreadlen=Plen;                                           //~v69XI~
	writelen=(ULONG)pcout-(ULONG)Sbuff;                            //~v69XI~
    if (Ppwritelen)                                                //~v69XI~
		*Ppwritelen=writelen;                                      //~v69XR~
UTRACED("locale2utf8 out",Sbuff,writelen);                         //~v69XI~
    return 1;       //no not free output addr                      //~v69XI~
//    if (!noascii //all ascii                                     //~v69XR~
//    ||  Sisutf8     //current is utf8                            //~v69XR~
//    ||  Sconverterdescriptor==(GIConv)-1) //no converter         //~v69XR~
//    {                                                            //~v69XR~
//        *Pputf8=Sbuff;                                           //~v69XR~
//        if (Ppreadlen)                                           //~v69XR~
//            *Ppreadlen=Plen;                                     //~v69XR~
//        if (Ppwritelen)                                          //~v69XR~
//            *Ppwritelen=Plen;                                    //~v69XR~
//        return 1;       //no not free output addr                //~v69XR~
//    }                                                            //~v69XR~
//  }                                                              //~v69VR~
//  putf8=g_locale_to_utf8(ptext,Plen,&readlen,&writelen,&perr);   //~v69QR~
//	putf8=g_convert_with_iconv(ptext,Plen,Sconverterdescriptor,&readlen,&writelen,&perr);//~v69VR~
//  dprintf("locale2utf8 len=%d %s\n",Plen,Sbuff);                 //~v69VR~
//    putf8=g_convert_with_iconv(Sbuff,Plen,Sconverterdescriptor,&readlen,&writelen,&perr);//~v69XR~
//    PRINTGERR("csublocale2utf8-g_locale_to_utf8",perr);          //~v69XR~
//  if (readlen!=Plen)                                             //~v69VR~
//  	dprintf("locale2utf8 read=%d %s\n",readlen,Sbuff);         //~v69VR~
//    if (Ppreadlen)                                               //~v69XR~
//        *Ppreadlen=readlen;                                      //~v69XR~
//    if (Ppwritelen)                                              //~v69XR~
//        *Ppwritelen=writelen;                                    //~v69XR~
////  return putf8;                                                //~v69XR~
//    *Pputf8=putf8;                                               //~v69XR~
//    return 0;                                                    //~v69XR~
}//csublocale2utf8                                                 //~v69sI~
#ifdef UTF8SUPPH                                                   //~va1cR~
//************************************************************     //~va1cR~
//*for scrdata                                                     //~va1cR~
//*rc:1 dbcs padding done                                          //~va1cR~
//************************************************************     //~va1cR~
int csublocale2utf8scr(int Popt,char *Ptext,char *Pdbcs,int Plen,  //~va1cR~
						int *Ppreadlen,char **Pputf8,              //~va1cR~
						char **Ppdata,char **Ppdbcs,USHORT **Ppoffst,//~va1cR~
						int *Ppwritelen,int *Pplclen,int *Ppslno)  //~va1cR~
{                                                                  //~va1cR~
#undef INVALIDCH                                                   //~va1cR~
#define INVALIDCH '.'                                              //~va1cR~
static char *Sbuff=0;                                              //~va1cR~
static int   Sbufflen=0;                                           //~va1cR~
  	UCHAR *pc,*pcout,*pdbcs,*pdata,*pdbcs0,*pdata0,*pcd,*pcoutpad=0;//~va1cR~
    USHORT *psl,*psl0;                                             //~va1cR~
    int readlen,writelen,slno=0;                                   //~va1cR~
    int reslen,ch,buffsz,outlenlc;                                 //~va1cR~
	char utf8wk[UTF8_MAXCHARSZMAX*MAX_MBCSLEN];                    //~va1cR~
//  int opt;                                                       //~va1cR~//~vaa7R~
    wchar_t ucs;                                                   //~va1cR~
    int swaltch,altch;                                             //~va42R~
    int padu8len;                                                  //~va6nI~
    int swligaturemode;                                            //~va6pI~
//****************************                                     //~va1cR~
UTRACED("locale2utf8 in",Ptext,Plen);                              //~va1cR~
UTRACED("locale2utf8 dbcs",Pdbcs,Plen);                            //~va1cR~
	swligaturemode=Popt & CSL2UO_LIGATURE;                         //~va6pI~
	if (Plen>Sbufflen)                                             //~va1cR~
    {                                                              //~va1cR~
    	if (Sbuff)                                                 //~va1cR~
        	free(Sbuff);                                           //~va1cR~
        Sbufflen=0;                                                //~va1cR~
        buffsz=Plen*(UTF8_MAXCHARSZMAX+(1+2)*2+4);                 //~va1cR~
//            1+2: 2byte ".." may be added by GB4 expansion,*2:dbcs tbl//~va1cR~
//            4: USHORT offset of dbcs padding on utf8 str and dbcs str//~va1cR~
        Sbuff=malloc((UINT)buffsz);                                //~va1cR~
        if (Sbuff)                                                 //~va1cR~
	        Sbufflen=Plen;                                         //~va1cR~
UTRACEP("locale2utf8 malloclen=%d,buff=%p\n",buffsz,Sbuff);        //~va1cR~
    }                                                              //~va1cR~
    if (!Sbuff)                                                    //~va1cR~
    	return 4;                                                  //~va1cR~
//  opt=UDCGMLO_LEN1IFERR;                                         //~va1cR~//~vaa7R~
    pdata0=pdata=Sbuff+Plen*UTF8_MAXCHARSZMAX;                     //~va1cR~
    pdbcs0=pdbcs=pdata+Plen*3;                                     //~va1cR~
    psl0=psl=(USHORT*)(ULONG)(pdbcs+Plen*3);                       //~va1cR~
	for (pc=Ptext,pcd=Pdbcs,pcout=Sbuff,reslen=Plen;reslen>0;)     //~va1cR~
    {                                                              //~va1cR~
        ch=*pc;                                                    //~va1cR~
        if (!ch)                                                   //~va1cR~
        {                                                          //~va1cR~
            *pcout++=' ';                                          //~va1cR~
            pc++;                                                  //~va1cR~
            *pdata++=' ';                                          //~va1cR~
          if (Pdbcs)    //if null,all sbcs                         //~vam4I~
            *pdbcs++=*pcd++;                                       //~va1cR~
          else                                                     //~vam4I~
            *pdbcs++=0;                                            //~vam4I~
            reslen--;                                              //~va1cR~
            continue;                                              //~va1cR~
        }                                                          //~va1cR~
        swaltch=0;                                                 //~va42I~
        if (ch<0x80)    //ascii                                    //~va1cR~
        {                                                          //~va1cR~
            ucs=*pc;	//errid                                    //~va42R~
            if (ucs<0x20)                                          //~va42I~
                if ((altch=UTF_GETALTCH_CTL(ucs))>0)               //~va44R~
                {                                                  //~va42R~
                    swaltch=1;                                     //~va42R~
                    ucs=altch;                                     //~va42R~
                }                                                  //~va42R~
          if (!swaltch)                                            //~va42R~
          {                                                        //~va42I~
            if ((ch==0x0a||ch==0x0d) && (Popt & CSL2UO_REP0a0d))   //~va1cR~
                *pcout++=INVALIDCH;	//current gtk version erase 0a...0d combination//~va1cR~
            else                                                   //~va1cR~
            if (UDBCSCHK_ISPRINT(ch))                              //~va1cR~
            	*pcout++=ch;	//no conversion                    //~va1cR~
            else                                                   //~va1cR~
                *pcout++=INVALIDCH;	//current gtk version erase 0a...0d combination//~va1cR~
            *pdata++=*(pcout-1);                                   //~va1cR~
          if (Pdbcs)                                               //~vam4I~
            *pdbcs++=*pcd++;                                       //~va1cR~
          else                                                     //~vam4I~
            *pdbcs++=0;                                            //~vam4I~
            pc++;                                                  //~va1cR~
            reslen--;                                              //~va1cR~
            continue;                                              //~va1cR~
          }//not alt ch trans                                      //~va42I~
        }//linech defined                                          //~va1cR~
        else                                                       //~va42I~
        if (!Pdbcs)                                                //~vam4I~
        {                                                          //~vam4I~
            if (ch==DEFAULT_ALTCH                                  //~vam4I~
            &&  (altch=UTF_GETALTCH_SBCS(0))>0                     //~vam4I~
            )                                                      //~vam4I~
            {                                                      //~vam4I~
                swaltch=1;                                         //~vam4I~
                ucs=altch;                                         //~vam4I~
            }                                                      //~vam4I~
            else                                                   //~vam4I~
            if (!UDBCSCHK_ISPRINT(ch))                             //~vam4I~
            {                                                      //~vam4I~
                *pcout++=INVALIDCH;                                //~vam4I~
            	*pdata++=INVALIDCH;                                //~vam4I~
            	*pc++=INVALIDCH;		//drawrepunprintable did it//~vam4I~
            	*pdbcs++=0;                                        //~vam4I~
            	reslen--;                                          //~vam4I~
            	continue;                                          //~vam4I~
            }                                                      //~vam4I~
        }                                                          //~vam4I~
        else                                                       //~vam4I~
        if (*pcd!=UDBCSCHK_DBCS1ST)                                //~va42I~
        {                                                          //~va42I~
            if (ch==DEFAULT_ALTCH                                  //~va47I~
            &&  (altch=UTF_GETALTCH_SBCS(*pcd))>0                  //~va47I~
            )                                                      //~va47I~
            {                                                      //~va47I~
                swaltch=1;                                         //~va47I~
                ucs=altch;                                         //~va47I~
            }                                                      //~va47I~
            else                                                   //~va47I~
            if (!UDBCSCHK_ISPRINT(ch))                             //~va42I~
            {                                                      //~va42I~
                *pcout++=INVALIDCH;                                //~va42I~
            	*pdata++=INVALIDCH;                                //~va42I~
            	*pc++=INVALIDCH;		//drawrepunprintable did it//~va42I~
            	*pdbcs++=*pcd++;                                   //~va42I~
            	reslen--;                                          //~va42I~
            	continue;                                          //~va42I~
            }                                                      //~va42I~
        }                                                          //~va42I~
        else    //DBCS1ST                                          //~va44I~
        {                                                          //~va44I~
            if (*pc==DEFAULT_ALTCH                                 //~va44R~
            &&   reslen>0                                          //~va44I~
            &&  *(pc+1)==DEFAULT_ALTCH                             //~va44R~
            &&  ((altch=UTF_GETALTCH_DBCS())>0)                    //~va44R~
            )                                                      //~va44I~
            {                                                      //~va44I~
                swaltch=2;                                         //~va44I~
            	ucs=altch;                                         //~va44I~
            }                                                      //~va44I~
        }                                                          //~va44I~
//**  >=0x80                                                       //~va1cR~
    if (swaltch==2)	//not DBCSSPACE                                //~va44I~
        readlen=2;   //DBCS                                        //~va44I~
    else                                                           //~va44I~
    {                                                              //~va44I~
      if (swaltch)                                                 //~va42R~
        readlen=1;                                                 //~va42I~
      else                                                         //~va42I~
//      readlen=utfcvl2uany1mb(0,pc,reslen,&ucs);                  //~v6unR~
        readlen=utfcvl2uany1mb(0,pc,reslen,&ucs,NULL/*rc*/);       //~v6unI~
    }                                                              //~va44I~
        if (readlen>0)  //cv ok                                    //~va1cR~
        {                                                          //~va1cR~
            writelen=uccvucs2utf((ULONG)ucs,utf8wk);               //~va1cR~
//          width=utfwcwidth(0,ucs,&widthflag);                    //~va1cR~
UTRACED("csubl2f inp lc data",pc,readlen);                         //~va1cR~
UTRACED("csubl2f out utf8wk",utf8wk,writelen);                     //~va1cR~
            memcpy(pcout,utf8wk,(UINT)writelen);                   //~va1cR~
            pcout+=writelen;                                       //~va1cR~
            memcpy(pdata,pc,(UINT)readlen);                        //~va1cR~
          if (Pdbcs)                                               //~vam4I~
            memcpy(pdbcs,pcd,(UINT)readlen);                       //~va1cR~
          else                                                     //~vam4I~
            memset(pdbcs,0,(UINT)readlen);                         //~vam4I~
            pdata+=readlen;                                        //~va1cR~
            pdbcs+=readlen;                                        //~va1cR~
#ifdef SSS                                                         //~vb3zI~
            if (swaltch==2)                                        //~va44I~
            {                                                      //~va44I~
	            memcpy(pcout,utf8wk,(UINT)writelen);               //~va44I~
    	        pcout+=writelen;                                   //~va44I~
                *(pdbcs-2)=0;   //set to sbcs                      //~va44I~
                *(pdbcs-1)=0;                                      //~va44I~
            }                                                      //~va44I~
            else                                                   //~va44I~
#endif                                                             //~vb3zI~
            if (readlen==UDBCSCHK_SS3SZ)                           //~va1cR~
            {                                                      //~va1cR~
              if (!swligaturemode)                                 //~va6pI~
              {                                                    //~va6pI~
            	slno++;                                            //~va1cR~
            	*psl++=(USHORT)((ULONG)pcout-(ULONG)Sbuff);        //~va1cR~
            	*psl++=(USHORT)((ULONG)pdata-(ULONG)pdata0);       //~va1cR~
//              *pcout++=Guviomdbcspad;                            //~va6nR~
                padu8len=uccvucs2utf((ULONG)Guviomdbcspad,pcout);  //~va6nR~
                pcout+=padu8len;                                   //~va6nI~
                pcoutpad=pcout;	//end chk                          //~va1cR~
//              *pdata++=Guviomdbcspad;                            //~va6nR~
                *pdata++=',';	//set only to keep column for drawtextstr_ligature//~va6nR~
    	        *pdbcs++=0;                                        //~va1cR~
              }                                                    //~va6pI~
            }                                                      //~va1cR~
            else                                                   //~va1cR~
            if (readlen==UDBCSCHK_GB4SZ)                           //~va1cR~
            {                                                      //~va1cR~
              if (!swligaturemode)                                 //~va6pI~
              {                                                    //~va6pI~
            	slno++;                                            //~va1cR~
            	*psl++=(USHORT)(((ULONG)pcout-(ULONG)Sbuff)|0x8000/*gb4 id*/);//~va1cR~
            	*psl++=(USHORT)((ULONG)pdata-(ULONG)pdata0);       //~va1cR~
//              *pcout++=Guviomdbcspad;                            //~va6nR~
//              *pcout++=Guviomdbcspad;                            //~va6nR~
                padu8len=uccvucs2utf((ULONG)Guviomdbcspad,pcout);  //~va6nR~
                pcout+=padu8len;                                   //~va6nI~
                padu8len=uccvucs2utf((ULONG)Guviomdbcspad,pcout);  //~va6nR~
                pcout+=padu8len;                                   //~va6nI~
                pcoutpad=pcout;	//end chk                          //~va1cR~
//              *pdata++=Guviomdbcspad;                            //~va6nR~
                *pdata++=',';	//set only to keep column          //~va6nI~
    	        *pdbcs++=0;                                        //~va1cR~
//              *pdata++=Guviomdbcspad;                            //~va6nR~
                *pdata++=',';	//set only to keep column          //~va6nI~
    	        *pdbcs++=0;                                        //~va1cR~
              }                                                    //~va6pI~
            }                                                      //~va1cR~
        }                                                          //~va1cR~
        else    //readlen=0;trans err                              //~va1cR~
        {                                                          //~va1cR~
            *pcout++=INVALIDCH;                                    //~va1cR~
            *pdata++=INVALIDCH;                                    //~va1cR~
            *pdbcs++=0;                                            //~va1cR~
            readlen=1;                                             //~va1cR~
        }                                                          //~va1cR~
        pc+=readlen;                                               //~va1cR~
        pcd+=readlen;                                              //~va1cR~
        reslen-=readlen;                                           //~va1cR~
    }//reslen                                                      //~va1cR~
    *pcout=0;                                                      //~va1cR~
    *Pputf8=Sbuff;                                                 //~va1cR~
    *Ppdata=pdata0;                                                //~va1cR~
    *Ppdbcs=pdbcs0;                                                //~va1cR~
    if (Ppreadlen)                                                 //~va1cR~
    	*Ppreadlen=Plen;                                           //~va1cR~
	writelen=(ULONG)pcout-(ULONG)Sbuff;                            //~va1cR~
    if (Ppwritelen)                                                //~va1cR~
		*Ppwritelen=writelen;                                      //~va1cR~
	outlenlc=(ULONG)pdata-(ULONG)pdata0;                           //~va1cR~
    if (Pplclen)                                                   //~va1cR~
		*Pplclen=outlenlc;                                         //~va1cR~
    if (slno                                                       //~va1cR~
    && pcoutpad!=pcout)	//not end by padding                       //~va1cR~
    {                                                              //~va1cR~
    	*psl++=writelen;	//set end of string                    //~va1cR~
    	*psl++=outlenlc;                                           //~va1cR~
        slno++;                                                    //~va1cR~
    }                                                              //~va1cR~
    if (Ppslno)                                                    //~va1cR~
		*Ppslno=slno;                                              //~va1cR~
    if (Ppoffst)                                                   //~va1cR~
		*Ppoffst=psl0;                                             //~va1cR~
UTRACED("csubl2f out return",Sbuff,writelen);                      //~va1cR~
UTRACED("csubl2f out return lc",pdata0,outlenlc);                  //~va1cR~
UTRACED("csubl2f out return dbcs",pdbcs0,outlenlc);                //~va1cR~
UTRACED("csubl2f out return slt ",psl0,slno*4);                    //~va1cR~
UTRACEP("slno=%d\n",slno);                                         //~va1cR~
    return slno!=0;       //dbcs padding done sw                   //~va1cR~
}//csublocale2utf8scr                                              //~va1cR~
#endif                                                             //~va1cR~
//===============================================================================//~v69UI~
//force scr resize by unit of cell size                            //~v69UI~
//parm:cell width/height                                           //~v69VI~
//===============================================================================//~v69UI~
void usetresizehint(int Pwidth,int Pheight,int Pcol,int Prow)      //~v69VR~
{                                                                  //~v69UI~
	GdkGeometry hints;                                             //~v69UI~
    GtkRequisition req;                                            //~v69UI~
    int basex,basey,minx,miny;                           //~v69VR~ //~vamKR~
#ifdef AAA                                                         //~varcI~
  	static int Sreqh=0;                                            //~v706R~
#endif                                                             //~varcI~
    int ghopt;                                                     //~varcI~
//************************************                             //~v69UI~
	UTRACEP("usetresizehint w=%d,h=%d,col=%d,row=%d\n",Pwidth,Pheight,Pcol,Prow);//~var8R~
    if (Gxxestat & GXXES_NOGEOMETRYHINT)	//no set geometry hint //~varcI~
    	return;                                                    //~varcI~
    memset(&hints,0,sizeof(hints));                                //~v69VR~
//  gtk_widget_get_child_requisition(Gpframe,&req);                //~v77qR~
//dprintf("requisition  t w=%d,h=%d\n",req.width,req.height);      //~v77qR~
	hints.width_inc =Pwidth;		//force width unit             //~v69UI~
	hints.height_inc=Pheight;		//force width unit             //~v69UI~
                                                                   //~v69VI~
    minx=Pwidth*MINCOLUMN;  //in fc5 when shrink to min,window is not movable//~v69UR~
	basex=0;//base of column calc -req.width;//RESIZE_HINT_BASE_ADJUST-Pheight*RESIZE_HINT_BASE_COLUMN;//ajust to display cols from left boundary//~v69UR~
    miny=Pheight*3;     //hdr ,cmdline,top line                    //~v69VR~
    basey=0;                                                       //~v69VI~
#ifndef OPTGTK3                                                    //~varcI~
    gtk_widget_get_child_requisition(Gpframe,&req);                //~vamKI~
#else                                                              //~varcI~
    gtk_widget_get_preferred_size(Gpframe,NULL,&req);              //~varcR~
#endif                                                             //~varcI~
	UTRACEP("Gpframe requisition w=%d,h=%d\n",req.width,req.height);//~vamKI~
    Sminx=max(minx,req.width)+Pwidth-1;                            //~varcR~
    basex=Pwidth-req.width%Pwidth;	//at compute_hits in gtkwindow.c; base_width+=req_width; become result%Pwidth==0//~vamKI~
	UTRACEP("Gpframe requisition w=%d,Pwidth=%d,basex=%d\n",req.width,Pwidth,basex);//~vamKI~
    if (Ggeometrybasex)                                            //~varcI~
    {                                                              //~varcI~
	    basex=Ggeometrybasex;	//for test                         //~varcI~
		UTRACEP("Gpframe basex parm from cmdline=%d\n",basex);     //~varcR~
    }                                                              //~varcI~
	hints.base_width=basex;                                        //~v69UI~
	hints.base_height=basey;                                       //~v69VR~
	hints.min_width=minx;                                          //~v69VR~
	hints.min_height=miny;                                         //~v69VI~
	dprintf("usetsizehint for Gpview inc=(w=%d,h=%d),base=(w=%d,h=%d),min=(w=%d,h=%d)\n",Pwidth,Pheight,basex,basey,minx,miny);//~v69UR~//~var8R~
	UTRACEP("usetsizehint for Gpview inc=(w=%d,h=%d),base=(w=%d,h=%d),min=(w=%d,h=%d)\n",Pwidth,Pheight,basex,basey,minx,miny);//~var8R~
    ghopt=GDK_HINT_MIN_SIZE|GDK_HINT_RESIZE_INC;                   //~varcI~
#ifndef OPTGTK3                                                    //~varcR~
  	if (!(Gxxestat & GXXES_BASE0))	//set to frame                 //~varcI~
#else                                                              //~varcI~
    if (Ggeometrybasex)                                            //~varcR~
#endif                                                             //~varcI~
    {                                                              //~varcI~
	  	UTRACEP("geometryhint Not Base=0\n");                      //~varcR~
	    ghopt|=GDK_HINT_BASE_SIZE;                                 //~varcI~
    }                                                              //~varcI~
//  if (Gxxestat & GXXES_FRAMEGH) //set to frame                   //~varcR~
//  {                                                              //~varcR~
//    UTRACEP("geometryhint to FRAME\n");                          //~varcR~
//    gtk_window_set_geometry_hints(GTK_WINDOW(Gpframe),GTK_WIDGET(Gpframe),&hints,ghopt);//~varbR~//~varcR~
//  }                                                              //~varcR~
//  else                                                           //~varcR~
//  if (Gxxestat & GXXES_VIEWGH)  //set to frame                   //~varcR~
//  {                                                              //~varcR~
//    UTRACEP("geometryhint to VIEW\n");                           //~varcR~
//    gtk_window_set_geometry_hints(GTK_WINDOW(Gpview),GTK_WIDGET(Gpview),&hints,ghopt);//~varcR~
//  }                                                              //~varcR~
//else                                                             //~varcR~
  {                                                                //~varcI~
  	UTRACEP("geometryhint to FRAME/VIEW,ghopt=%d\n",ghopt);        //~varcR~
    gtk_window_set_geometry_hints(GTK_WINDOW(Gpframe),GTK_WIDGET(Gpview),//~v69UI~//~varbR~//~varcR~
    									&hints,                    //~v69UI~
                                        ghopt);                    //~varcI~
  }                                                                //~varcI~
//                                        GDK_HINT_MIN_SIZE|         //~v69XR~//~varcR~
////#ifndef OPTGTK3   //no need base                                   //~var8R~//~varbR~//~varcR~
//                                        GDK_HINT_BASE_SIZE|        //~v69UR~//~varcR~
////#endif                                                             //~var8R~//~varbR~//~varcR~
//                                        GDK_HINT_RESIZE_INC);      //~v69XI~//~varcR~
                                                                   //~v69VI~
#ifdef AAA                                                         //~varcI~
  if (!Sreqh)                                                      //~v77qR~
  {                                                                //~v77qR~
    gtk_widget_get_child_requisition(Gpframe,&req);                //~v77qI~
	UTRACEP("child requisition w=%d,h=%d\n",req.width,req.height);           //~v77qR~//~vamKR~
    Sreqh=req.height;                                              //~v77qR~
#ifdef AAA                                                         //~vamKM~
	gtk_widget_set_size_request(Gpview,req.width,req.height); //requred for column calc from base//~v69UI~
#endif                                                             //~vamKM~
  }                                                                //~v77qR~
#endif                                                             //~varcI~
#ifdef AAA                                                         //~vamKI~
    neww=Pwidth*Pcol;                                              //~v69VR~
//  newh=Pheight*Prow+req.height;                                  //~v77qR~
    newh=Pheight*Prow+Sreqh;                                       //~v77qM~
    neww+=2;                                                       //~vamKR~
UTRACEP("userresizehint frame window resize w=%d,h=%d,col=%d,row=%d\n",neww,newh,Pcol,Prow);//~v706R~//~vamKR~
    gtk_window_resize(GTK_WINDOW(Gpframe),neww,newh);              //~v69VR~
#endif                                                             //~vamKI~
    return;                                                        //~v69UI~
}//usetresizehint                                                  //~v69UI~
//===============================================================================//~varcI~
int chkresizelimit(int Pscrwidth)                                  //~varcR~
{                                                                  //~varcI~
static time_t Stm0;    //seconds                                   //~varcI~
static int Soverminwidth;                                          //~varcI~
static int Sautoshrink;                                            //~varcI~
	time_t tm;                                                     //~varcI~
    int ms=0,rc=0;                                                 //~varcI~
//*********************                                            //~varcI~
	if (Pscrwidth>Sminx)                                           //~varcI~
    {                                                              //~varcI~
    	Soverminwidth=Sminx;                                       //~varcI~
    }                                                              //~varcI~
    else                                                           //~varcI~
    {                                                              //~varcI~
    	if (Soverminwidth)   //need once over min                  //~varcI~
        {                                                          //~varcI~
            rc=Sautoshrink!=0;                                     //~varcI~
            UTRACEP("reached MIN after overed once rc=%d\n",rc);   //~varcI~
            if (rc)                                                //~varcI~
            {                                                      //~varcI~
		    	Soverminwidth=0;                                   //~varcI~
            	Sresizectr=0;	//avoid duplicated warning         //~varcI~
            }                                                      //~varcI~
            return rc;                                             //~varcI~
        }                                                          //~varcI~
        UTRACEP("reached MIN but not overed once\n");              //~varcR~
        return 0;                                                  //~varcI~
    }                                                              //~varcI~
	if (!Sresizectr)                                               //~varcI~
    {                                                              //~varcI~
        Sautoshrink=0;                                             //~varcI~
    	time(&Stm0);                                               //~varcR~
    }                                                              //~varcI~
    else                                                           //~varcI~
    {                                                              //~varcI~
    	time(&tm);                                                 //~varcR~
        ms=tm-Stm0;                                                //~varcI~
        if (ms<THV_RESIZETIME && Sresizectr>THV_RESIZECTR)         //~varcI~
        {                                                          //~varcI~
        	Sautoshrink=1;                                         //~varcR~
	        UTRACEP("autoshrink detected\n");                      //~varcI~
        }                                                          //~varcI~
        else                                                       //~varcI~
        if (ms>=THV_RESIZETIME)                                    //~varcI~
        {                                                          //~varcI~
        	Sresizectr=-1;   //later ++                            //~varcR~
        }                                                          //~varcI~
    }                                                              //~varcI~
    Sresizectr++;                                                  //~varcI~
    UTRACEP("chkresizelimit rc=%d,ctr=%d,interval=%d\n",rc,Sresizectr,ms);//~varcI~
    return rc;                                                     //~varcI~
}//chkresizelimit                                                  //~varcI~
//===============================================================================//~varcI~
//after init limit resize by mouse                                 //~varcI~
//===============================================================================//~varcI~
void usetresizehint2(int Pscrwidth,int Pscrheight,int Pmaxcol,int Pmaxrow)//~varcI~
{                                                                  //~varcI~
	GdkGeometry hints,*phints;                                     //~varcI~
    int basex,basey;                                               //~varcI~
    int ghopt;                                                     //~varcI~
    int paddx,paddy;                                               //~varcI~
//    int mincol=20;                                               //~varcR~
//    int minrow=3;                                                //~varcR~
    GtkWidget *widget;                                             //~varcI~
//************************************                             //~varcI~
	UTRACEP("%s:usetresizehint2 w=%d,h=%d,col=%d,row=%d\n",UTT,Pscrwidth,Pscrheight,Pmaxcol,Pmaxrow);//~varcI~//~vbA3R~
    if (Gxxestat & GXXES_NOGEOMETRYHINT)	//no set geometry hint //~varcI~
    {                                                              //~varcI~
		UTRACEP("usetresizehint2 NOGEOMHINT option\n");            //~varcI~
    	return;                                                    //~varcI~
    }                                                              //~varcI~
    if (!(Gxxestat & GXXES_GHATONSIZE))	//no set at onsize         //~varcR~
    {//check resize                                                //~varcI~
		UTRACEP("%s:usetresizehint2 not RESIZE ON ONSIZE option min=%d,scr=%d\n",UTT,Sminx,Pscrwidth);//~varcR~//~vbA3R~
    	if (chkresizelimit(Pscrwidth))                             //~varcR~
	        uerrmsgbox("Try \"--gh=N\" commandline option if window size autmatically shrink.",0);//~varcR~
    	return;                                                    //~varcI~
    }                                                              //~varcI~
    if (!Pmaxcol || !Pmaxrow)                                      //~varcI~
    	return;                                                    //~varcI~
    memset(&hints,0,sizeof(hints));                                //~varcI~
	hints.width_inc =Pscrwidth/Pmaxcol;		//force width unit     //~varcI~
	hints.height_inc=Pscrheight/Pmaxrow;		//force width unit //~varcI~
	paddx=Pscrwidth%Pmaxcol;		//force width unit             //~varcI~
	paddy=Pscrheight%Pmaxrow;		//force width unit             //~varcI~
	basex=0;                                                       //~varcI~
    basey=0;                                                       //~varcI~
    widget=GTK_WIDGET(Gpview);                                     //~varcI~
    if (!paddx && !paddy)                                          //~varcI~
    {                                                              //~varcI~
        phints=NULL;                                               //~varcI~
        ghopt=0;                                                   //~varcI~
        UTRACEP("geometryhint set NULL by Padding=0\n");           //~varcR~
    }                                                              //~varcI~
    else                                                           //~varcI~
    {                                                              //~varcI~
    	ghopt=GDK_HINT_MIN_SIZE|GDK_HINT_RESIZE_INC|GDK_HINT_BASE_SIZE;//~varcI~
		hints.min_width=hints.width_inc*Pmaxcol;                   //~varcI~
		hints.min_height=hints.height_inc*Pmaxrow;                 //~varcI~
		hints.base_width=basex;                                    //~varcI~
		hints.base_height=basey;                                   //~varcI~
        phints=&hints;                                             //~varcI~
		UTRACEP("usetsizehint2 inc=(w=%d,h=%d),min=(%d,%d),padd=(%d,%d)\n",hints.width_inc,hints.height_inc,hints.min_width,hints.min_height,paddx,paddy);//~varcI~
    }                                                              //~varcI~
    gtk_window_set_geometry_hints(GTK_WINDOW(Gpframe),widget,phints,ghopt);//~varcI~
    return;                                                        //~varcI~
}//usetresizehint                                                  //~varcI~
#ifdef UTF8UCS2                                                    //~va20I~
//**************************************************************** //~va20I~
//*                                                                //~va20I~
//**************************************************************** //~va20I~
int csubchkdd(int Popt,char *Pdbcs,int Plen)                       //~va20I~
{                                                                  //~va20I~
    return utfchkdd(0,(UCHAR*)Pdbcs,Plen);                         //~va20I~
}//csubchkdd                                                       //~va20I~
#ifdef AAA //no caller                                             //~vbi9I~
//**************************************************************** //~va30I~
//*                                                                //~va30I~
//**************************************************************** //~va30I~
int csubddcombine(int Popt,char *Pdata,char *Pdbcs,char *Pcombineid,int Plen,int *Ppstarterrctr,int *Ppendcombinectr)//~va30R~
{                                                                  //~va30I~
	return utfddcombine(Popt,Pdata,Pdbcs,Pcombineid,Plen,Ppstarterrctr,Ppendcombinectr);//~va30R~
}//csubddcombine                                                   //~va30I~
#endif //AAA //no caller                                           //~vbi9I~
//**************************************************************** //~va3bI~
//*get column of csr position-1 and +1 and +0                      //~va3bR~
//**************************************************************** //~va3bI~
int csubgetcsrposbf(int Popt,char *Pdbcs,int Plen,int Ppos,int *Ppposb,int *Ppposc,int *Ppposa)//~va3bR~
{                                                                  //~va3bI~
	int rc;                                                        //~va3bI~
//**************************                                       //~va3bM~
	rc=utfddgetcsrposbca(Popt,Pdbcs,Plen,Ppos,Ppposb,Ppposc,Ppposa);//~va3bI~
//dprintf("getcsrposba len=%d,pos=%d,prev=%d,cpos=%d,next=%d\n",Plen,Ppos,*Ppposb,*Ppposc,*Ppposa);//~va3bR~
    return rc;                                                     //~va3bR~
}//csubgetcsrposbf                                                 //~va3bI~
#endif                                                             //~va20I~
#ifndef OPTGTK3                                                    //~var8R~
#else                                                              //~var8R~
//*************************************************************************//~var8R~
//*from xxescr:drawimcsr                                           //~var8R~
//*************************************************************************//~var8R~
void csub_gdk_draw_lines(GdkPixmap *Pppixmap,GdkGC *Ppgc,GdkPoint *Ppoint,int Pctr)//~var8R~
{                                                                  //~var8R~
#ifdef AAA    //Gpgcim set as Gppixmap as source surface           //~var8R~
    cairo_surface_t *cs;                                           //~var8R~
    int ww,hh;                                                     //~var8R~
#endif                                                             //~var8R~
    int xx,yy,ii;                                                  //~var8R~
    GdkPoint *ppoint;                                              //~var8R~
//************************************                             //~var8R~
	dprintf("csub_gdk_draw_lines pixmap=%p,ref=%d\n",Pppixmap,cairo_surface_get_reference_count(Pppixmap));//~var8R~
#ifdef AAA    //Gpgcim set as Gppixmap as source surface           //~var8R~
  	gdk_pixmap_get_size(Pppixmap,&ww,&hh);                         //~var8R~
    cs=(cairo_surface_t*)Pppixmap;                                 //~var8R~
    cairo_set_source_surface(Ppgc,cs,ww,hh);                       //~var8R~
#endif                                                             //~var8R~
    ppoint=Ppoint;                                                 //~var8R~
    xx=ppoint->x,yy=ppoint->y;                                     //~var8R~
    cairo_move_to(Ppgc,xx,yy);                                     //~var8R~
    for (ii=1,ppoint++;ii<Pctr;ii++,ppoint++)                      //~var8R~
    {                                                              //~var8R~
	    xx=ppoint->x,yy=ppoint->y;                                 //~var8R~
	    cairo_line_to(Ppgc,xx,yy);                                 //~var8R~
    }                                                              //~var8R~
    cairo_stroke(Ppgc);                                            //~var8R~
	dprintf("csub_gdk_draw_lines pixmap=%p,ref=%d\n",Pppixmap,cairo_surface_get_reference_count(Pppixmap));//~var8R~
}//csub_gdk_draw_lines                                             //~var8R~
//*************************************************************************//~var8R~
//*copy gc attribute(line width,foreground)                        //~var8R~
//* see  csub_gdk_gc_new_with_values                               //~var8R~
//*************************************************************************//~var8R~
double csub_copy_gc(GdkGC *Ppgc,GdkGC *Ppgcsource)                 //~var8R~
{                                                                  //~var8R~
    cairo_pattern_t *pattern;                                      //~var8R~
    double linewidth;                                              //~var8R~
//************************************                             //~var8R~
    pattern=cairo_get_source(Ppgcsource);                          //~var8R~
	cairo_set_source(Ppgc,pattern);                                //~var8R~
	linewidth=cairo_get_line_width(Ppgcsource);                    //~var8R~
    cairo_set_line_width(Ppgc,linewidth);                          //~var8R~
    UTRACEP("%s:src=%p,tgt=%p,linewidth=%f,cairo_patern_type=%d\n",UTT,Ppgcsource,Ppgc,linewidth,cairo_pattern_get_type(pattern));//~var8R~//~vbzbR~
    return linewidth;                                              //~var8R~
}//csub_copy_gc                                                    //~var8R~
//*************************************************************************//~var8R~
void csub_draw_line(GdkGC *Ppgc,double Plinewidth,int Px1,int Py1,int Px2,int Py2)//~var8R~
{                                                                  //~var8R~
	gboolean oddlinewidth;                                         //~var8R~
    int iw;                                                        //~var8R~
    double dw;                                                     //~var8R~
//************************************                             //~var8R~
    iw=(int)Plinewidth;                                            //~var8R~
    dw=(double)iw;                                                 //~var8R~
    oddlinewidth=(Plinewidth==dw && iw%2!=0);	//odd integer      //~var8R~
	if (oddlinewidth)	//cairo                                    //~var8R~
    {                                                              //~var8R~
    	if (Py1==Py2)	//horizontal line                          //~var8R~
        {                                                          //~var8R~
    		cairo_move_to(Ppgc,Px1,Py1+0.5);                       //~var8R~
    		cairo_line_to(Ppgc,Px2,Py2+0.5);                       //~var8R~
        }                                                          //~var8R~
        else                                                       //~var8R~
    	if (Px1==Px2)	//vertical line                            //~var8R~
        {                                                          //~var8R~
    		cairo_move_to(Ppgc,Px1+0.5,Py1);                       //~var8R~
    		cairo_line_to(Ppgc,Px2+0.5,Py2);                       //~var8R~
        }                                                          //~var8R~
        else                                                       //~var8R~
        {                                                          //~var8R~
    		cairo_move_to(Ppgc,Px1,Py1);                           //~var8R~
    		cairo_line_to(Ppgc,Px2,Py2);                           //~var8R~
        }                                                          //~var8R~
    }                                                              //~var8R~
    else                                                           //~var8R~
    {                                                              //~var8R~
    	cairo_move_to(Ppgc,Px1,Py1);                               //~var8R~
    	cairo_line_to(Ppgc,Px2,Py2);                               //~var8R~
    }                                                              //~var8R~
    cairo_stroke(Ppgc);                                            //~var8R~
    dprintf("csub_gdk_draw_line_direct stroke cairo_t=%p,linewidth=%f\n",Ppgc,cairo_get_line_width(Ppgc));
}//csub_draw_line                                                  //~var8R~
//*************************************************************************//~var8R~
//*pixmai is not used,it was set as source of th gc                //~var8R~
//*************************************************************************//~var8R~
void csub_gdk_draw_line(GdkPixmap *Pppixmap,GdkGC *Ppgc,int Px1,int Py1,int Px2,int Py2)//~var8R~
{                                                                  //~var8R~
	double linewidth;                                              //~var8R~
//************************************                             //~var8R~
	linewidth=cairo_get_line_width(Ppgc);                          //~var8R~
	csub_draw_line(Ppgc,linewidth,Px1,Py1,Px2,Py2);                //~var8R~
    dprintf("csub_gdk_draw_line stroke linewidth=%f\n",cairo_get_line_width(Ppgc));//~var8R~
}//csub_gdk_draw_line                                              //~var8R~
//*************************************************************************//~var8R~
void csub_gdk_draw_line_direct(GdkGC *Ppgc,GdkGC *Ppgcsource,int Px1,int Py1,int Px2,int Py2)//~var8R~
{                                                                  //~var8R~
	double linewidth;                                              //~var8R~
//************************************                             //~var8R~
	linewidth=csub_copy_gc(Ppgc,Ppgcsource);                       //~var8R~
	csub_draw_line(Ppgc,linewidth,Px1,Py1,Px2,Py2);                //~var8R~
    UTRACEP("%s:stroke linewidth=%f\n",UTT,linewidth);//~var8R~    //~vbzbR~
}//csub_gdk_draw_line                                              //~var8R~
#endif                                                             //~vbi9R~
#if GTK_CHECK_VERSION(2,18,0)                                      //~vbi9R~
//*************************************************************************//~var8R~
void csub_get_widget_allocation_wh(GtkWidget *Ppwidget,int *Ppww,int *Pphh)//~var8R~
{                                                                  //~var8R~
    GtkAllocation alloc;                                           //~var8R~
//************************************************                 //~var8R~
    gtk_widget_get_allocation(Ppwidget,&alloc);                    //~var8R~
    *Ppww=alloc.width;                                             //~var8R~
    *Pphh=alloc.height;                                            //~var8R~
    UTRACEP("%s:widget=%p,w=%d,h=%d,x=%d,y=%d\n",UTT,Ppwidget,alloc.width,alloc.height,alloc.x,alloc.y);//~vb7zR~
}//csub_get_widget_allocation_wh                                   //~var8R~
#endif                                                             //~vbi9R~
#ifndef OPTGTK3                                                    //~vbi9R~
#else                                                              //~vbi9R~
//*************************************************************************//~vbBzI~
void csub_get_widget_size(GtkWidget *Ppwidget,int *Ppww,int *Pphh) //~vbBzI~
{                                                                  //~vbBzI~
//************************************************                 //~vbBzI~
    gtk_window_get_size(GTK_WINDOW(Ppwidget),Ppww,Pphh);   //void  //~vbBzR~
    UTRACEP("%s:widget=%p,w=%d,h=%d\n",UTT,Ppwidget,*Ppww,*Pphh);  //~vbBzI~
}//csub_get_widget_size                                            //~vbBzI~
//*************************************************************************//~var8R~
#ifdef AAA //not called                                            //~vb7tI~
void csub_gdk_draw_drawable(GtkWidget *Ppwidget,GdkPixmap *Pppixmap,int Pxxsrc,int Pyysrc,int Pxxdest,int Pyydest,int Pww,int Phh)//~var8R~
{                                                                  //~var8R~
    cairo_t *cr;                                                   //~var8R~
    cairo_surface_t *cs;                                           //~var8R~
//  GtkStyle *pstyle;                                              //~var8R~
//  GtkStateType state;                                            //~var8R~
//******************************                                   //~var8R~
//  Ppwidget->style->fg_gc[GTK_WIDGET_STATE(Ppwidget)],            //~var8R~
//  pstyle=gtk_widget_get_style(Ppwidget);                         //~var8R~
//  state=gtk_widget_get_state(Ppwidget);                          //~var8R~
    cs=(cairo_surface_t*)Pppixmap;                                 //~var8R~
	dprintf("csub_gdk_draw_drawable pixmap=%p,ref=%d\n",Pppixmap,cairo_surface_get_reference_count(Pppixmap));//~var8R~
    cr=gdk_cairo_create(gtk_widget_get_window(Ppwidget));          //~var8R~
    cairo_set_source_surface(cr,cs,(double)Pxxsrc,(double)Pyysrc); //~var8R~
//  cairo_fill(cr);                                                //~var8R~
    cairo_paint(cr);                                               //~var8R~
    cairo_destroy(cr);                                             //~var8R~
	dprintf("csub_gdk_draw_drawable return pixmap=%p,ref=%d\n",Pppixmap,cairo_surface_get_reference_count(Pppixmap));//~var8R~
}//csub_gdk_draw_drawable                                          //~var8R~
#endif                                                             //~vb7tI~
//*************************************************************************//~var8R~
void csub_draw_pixmap_to_screen(cairo_t *Pcr,GdkPixmap *Pppixmap)  //~var8R~
{                                                                  //~var8R~
    cairo_t *cr;                                                   //~var8R~
    cairo_surface_t *cs;                                           //~var8R~
//******************************                                   //~var8R~
    cs=(cairo_surface_t*)Pppixmap;                                 //~var8R~
	dprintf("csub_gdk_draw_to_screen cr=%p,pixmap=%p,ref=%d\n",Pcr,Pppixmap,cairo_surface_get_reference_count(Pppixmap));//~var8R~
    cr=Pcr;                                                        //~var8R~
    cairo_set_source_surface(cr,cs,0.0/*Pxxsrc*/,0.0/*Pyysrc*/);   //~var8R~
//  cairo_fill(cr);                                                //~var8R~
    cairo_paint(cr);                                               //~var8R~
	dprintf("csub_gdk_draw_pixmap_to_screen return pixmap=%p,ref=%d\n",Pppixmap,cairo_surface_get_reference_count(Pppixmap));//~var8R~
}//csub_draw_pixmap_to_screen                                      //~var8R~
//*************************************************************************//~var8R~
void csub_gdk_gc_set_line_attributes(GdkGC *Ppgc,int Pwidth,GdkLineStyle Plinetype,GdkCapStyle Pcaptype,GdkJoinStyle Pjointype)//~var8R~
{                                                                  //~var8R~
	cairo_set_line_width(Ppgc,(double)Pwidth);                     //~var8R~
	if (Pjointype==GDK_JOIN_MITER)                                 //~var8R~
    	cairo_set_line_join(Ppgc,CAIRO_LINE_JOIN_MITER);           //~var8R~
	if (Pcaptype==GDK_CAP_NOT_LAST)      //if len=0 no print else same as BUTT(no round)//~var8R~
    	cairo_set_line_cap(Ppgc,CAIRO_LINE_CAP_BUTT);              //~var8R~
//  if (Plinetype==GDK_LINE_SOLID)		//strait line              //~var8R~
}//csub_gdk_gc_set_line_attributes                                 //~var8R~
//*************************************************************************
void csub_gtk_signal_emit_by_name(GtkObject *Ppwidget,const gchar *Psigname,gchar *Pparm)//~var8R~
{
//*********************                                            //~var8R~
	g_signal_emit_by_name(Ppwidget,Psigname,Pparm,G_TYPE_NONE);    //~var8R~
}//csub_gtk_gc_set_line_attributes                                 //~var8R~
//*************************************************************************//~var8R~
GdkGC *csub_gc_new(GtkWidget *Ppwidget)                            //~var8R~
{                                                                  //~var8R~
#if GTK_CHECK_VERSION(3,22,0)                                      //~vb7tI~
    cairo_t        *cr;	//=GdkGC                                   //~vb7tI~
#endif                                                             //~vb7tI~
//**********************************                               //~vb7tI~
#if GTK_CHECK_VERSION(3,22,0)                                      //~vb7tI~
	cr=csub_get_cairot(0,Ppwidget,0);                              //~vb7tR~
    dprintf("csub_gc_new widget=%p,cairot=%p\n",Ppwidget,cr);      //~vb7tI~
    return cr;                                                     //~vb7tI~
#else                                                              //~vb7tI~
	return gdk_cairo_create(gtk_widget_get_window(Ppwidget));      //~var8R~
#endif                                                             //~vb7tI~
}                                                                  //~var8R~
//*************************************************************************//~var8R~
GdkGC *csub_gc_new_pixmap(GtkWidget *Ppwidget,GdkPixmap *Pppixmap) //~var8R~
{                                                                  //~var8R~
	cairo_t *cr;                                                   //~var8R~
//********************************                                 //~var8R~
	cr=cairo_create(Pppixmap);                                     //~var8R~
	dprintf("csub_gc_new_pixmap pixmap=%p,cr=%p\n",Pppixmap,cr);   //~var8R~
	return cr;                                                     //~var8R~
}                                                                  //~var8R~
//*************************************************************************//~var8R~
void csub_gdk_gc_set_rgb(GdkGC *Ppgc,GdkColor *Ppcolor)            //~var8R~
{                                                                  //~var8R~
	double rr,gg,bb;                                               //~var8R~
//********************************                                 //~var8R~
	rr=Ppcolor->red/65535.0;                                       //~var8R~
	gg=Ppcolor->green/65535.0;                                     //~var8R~
	bb=Ppcolor->blue/65535.0;                                      //~var8R~
    dprintf("csub_gdk_gc_set_rgb rr=%f,gg=%f,bb=%f\n",rr,gg,bb);   //~var8R~
	cairo_set_source_rgb(Ppgc,rr,gg,bb);                           //~var8R~
}//csub_gdk_gc_set_rgb                                             //~var8R~
//*************************************************************************//~vbzbI~
void csub_gdk_gc_set_rgba(GdkGC *Ppgc,GdkColor *Ppcolor,double Palpha)//~vbzbI~
{                                                                  //~vbzbI~
	double rr,gg,bb,aa;                                            //~vbzbI~
//********************************                                 //~vbzbI~
	rr=Ppcolor->red/65535.0;                                       //~vbzbI~
	gg=Ppcolor->green/65535.0;                                     //~vbzbI~
	bb=Ppcolor->blue/65535.0;                                      //~vbzbI~
	aa=Palpha/65535.0;                                             //~vbzbI~
    UTRACEP("%s: aa=%f,rr=%f,gg=%f,bb=%f\n",UTT,aa,rr,gg,bb);      //~vbzbI~
	cairo_set_source_rgba(Ppgc,aa,rr,gg,bb);                       //~vbzbI~
}//csub_gdk_gc_set_rgb                                             //~vbzbI~
//*************************************************************************//~var8R~
//*output should be freed by gdk_rgba_free()                       //~var8R~
//*************************************************************************//~var8R~
GdkRGBA *csub_gdkColor2RGBA(GdkColor *Ppcolor,int Palpha)          //~var8R~
{                                                                  //~var8R~
	GdkRGBA rgba;                                                  //~var8R~
//********************************                                 //~var8R~
	rgba.red=Ppcolor->red/65535.0;                                 //~var8R~
	rgba.green=Ppcolor->green/65535.0;                             //~var8R~
	rgba.blue=Ppcolor->blue/65535.0;                               //~var8R~
    if (Palpha==-1)                                                //~var8R~
		rgba.alpha=1.0;                                            //~var8R~
    else                                                           //~var8R~
		rgba.alpha=Palpha/65535.0;                                 //~var8R~
    UTRACEP("csubgdkColor2RGBA in=(%d,%d,%d),out=(%f,%f,%f)\n",Ppcolor->red,Ppcolor->green,Ppcolor->blue,rgba.red,rgba.green,rgba.blue);//~var8R~
    return gdk_rgba_copy(&rgba);                                   //~var8R~
}//csub_gdkColor2RGBA                                              //~var8R~
//*************************************************************************//~var8R~
//*output should be freed by gdk_color_free()                      //~var8R~
//*************************************************************************//~var8R~
GdkColor *csub_gdkRGBA2Color(GdkRGBA *Pprgba,GdkColor *Ppcolor)    //~var8R~
{                                                                  //~var8R~
	GdkColor color,*pcolor;                                        //~var8R~
//********************************                                 //~var8R~
	color.pixel=24;	//Doc:not used anymore                         //~var8R~
	color.red=Pprgba->red*65535;                                   //~var8R~
	color.green=Pprgba->green*65535;                               //~var8R~
	color.blue=Pprgba->blue*65535;                                 //~var8R~
    UTRACEP("csubgdkRGBA2Color in=(%d,%d,%d),out=(%f,%f,%f)\n",Pprgba->red,Pprgba->green,Pprgba->blue,color.red,color.green,color.blue);//~var8R~
    if (Ppcolor)                                                   //~var8R~
    {                                                              //~var8R~
    	memcpy(Ppcolor,&color,sizeof(GdkColor));                   //~var8R~
        pcolor=Ppcolor;                                            //~var8R~
    }                                                              //~var8R~
    else                                                           //~var8R~
    {                                                              //~vb7tI~
#if GTK_CHECK_VERSION(3,14,0)                                      //~vb7tI~
    	pcolor=malloc(sizeof(GdkColor));                           //~vb7tI~
        memcpy(pcolor,&color,sizeof(GdkColor));                    //~vb7tI~
#else                                                              //~vb7tI~
    	pcolor=gdk_color_copy(&color);                             //~var8R~
#endif                                                             //~vb7tI~
    }                                                              //~vb7tI~
    return pcolor;                                                 //~var8R~
}//csub_gdkRGBA2Color                                              //~var8R~
//*************************************************************************//~var8R~
GdkGC *csub_gdk_gc_new_with_values(GtkWidget *Ppwidget,GdkGCValues *Ppgcvalues,GdkGCValuesMask Pflag)//~var8R~
{                                                                  //~var8R~
	cairo_t *cr;                                                   //~var8R~
    GdkColor fg;                                                   //~var8R~
//  GdkLineStyle linestyle=GDK_LINE_SOLID;                         //~var8R~
    int linewidth=1;                                               //~var8R~
//**************************************************************   //~var8R~
	cr=csub_gc_new(Ppwidget);                                      //~var8R~
	if (Pflag & GDK_GC_LINE_WIDTH)                                 //~var8R~
    	linewidth=Ppgcvalues->line_width;                          //~var8R~
	cairo_set_line_width(cr,(double)linewidth);                    //~var8R~
//  if (Pflag & GDK_GC_LINE_STYLE)                                 //~var8R~
//  	linestyle=Ppgcvalues->line_style;                          //~var8R~
	if (Pflag & GDK_GC_FOREGROUND)                                 //~var8R~
    {                                                              //~var8R~
    	fg=Ppgcvalues->foreground;                                 //~var8R~
		csub_gdk_gc_set_rgb(cr,&fg);                               //~var8R~
    }                                                              //~var8R~
    return cr;                                                     //~var8R~
}//csub_gdk_gc_new_with_values                                     //~var8R~
//*************************************************************************//~var8R~
int csub_gdk_gc_set_function(GdkGC *Ppgc,GdkFunction Pfunc)        //~var8R~
{                                                                  //~var8R~
	int rc=0;                                                      //~var8R~
    cairo_operator_t op;                                           //~var8R~
//**************************************************************   //~var8R~
	if (Pfunc==GDK_INVERT)                                         //~var8R~
    	op=CAIRO_OPERATOR_DIFFERENCE;                              //~var8R~
    else                                                           //~var8R~
    {                                                              //~vbzbI~
    	rc=8;                                                      //~var8R~
    }                                                              //~vbzbI~
#ifndef TEST                                                        //~vbz9I~//~vbzbM~
//        op=CAIRO_OPERATOR_XOR;                                   //~vbzbI~
//        op=CAIRO_OPERATOR_ADD;                                   //~vbzbI~
//        op=CAIRO_OPERATOR_LIGHTEN;                               //~vbzbI~
//        op=CAIRO_OPERATOR_DARKEN;                                //~vbzbI~
//        op=CAIRO_OPERATOR_DEST;                                  //~vbzbI~
//        op=CAIRO_OPERATOR_OVERLAY;                               //~vbzbI~
//        op=CAIRO_OPERATOR_SCREEN;                                //~vbzbI~
//        op=CAIRO_OPERATOR_HSL_HUE;                               //~vbzbI~
//        op=CAIRO_OPERATOR_DEST_OUT;                              //~vbzbI~
//        op=CAIRO_OPERATOR_DEST_IN;                               //~vbzbI~
//    rc=0;                                                        //~vbzbI~
#endif                                                             //~vbz9I~//~vbzbM~
	UTRACEP("%s:cairo_set_operator op=0x%x\n",UTT,op);             //~vbzbI~
    if (!rc)                                                       //~var8R~
		cairo_set_operator(Ppgc,op);	//void                     //~var8R~
    return rc;                                                     //~var8R~
}//csub_gdk_gc_set_function                                        //~var8R~
//*************************************************************************//~var8R~
//*pixmap is not used,it is already set source to gc               //~var8R~
//*************************************************************************//~var8R~
void csub_gdk_draw_rectangle(GdkPixmap *Pppixmap,GdkGC *Ppgc,gboolean Pfill,int Pxx,int Pyy,int Pww,int Phh)//~var8R~
{                                                                  //~var8R~
    GdkRectangle rect;                                             //~var8R~
#ifdef AAA  //auready set surface to cairo_t                       //~var8R~
    cairo_surface_t *cs;                                           //~var8R~
#endif                                                             //~var8R~
//**************************************************************   //~var8R~
	dprintf("csub_gdk_draw_rectangle gc=%p,fill=%d,pixmap=%p,xx=%d,yy=%d,ww=%d,hh=%d,ref=%d\n",Ppgc,Pfill,Pppixmap,Pxx,Pyy,Pww,Phh,cairo_surface_get_reference_count(Pppixmap));//~var8R~
	rect.x=Pxx;                                                    //~var8R~
	rect.y=Pyy;                                                    //~var8R~
	rect.width=Pww;                                                //~var8R~
	rect.height=Phh;                                               //~var8R~
#ifdef AAA  //auready set surface to cairo_t                       //~var8R~
    cs=(cairo_surface_t*)Pppixmap;                                 //~var8R~
    cairo_set_source_surface(Ppgc,cs,Pww,Phh);                     //~var8R~
#endif                                                             //~var8R~
    if (Pfill)                                                     //~var8R~
    {                                                              //~var8R~
	dprintf("csub_gdk_draw_rectabglet pixmap=%p,ref=%d\n",Pppixmap,cairo_surface_get_reference_count(Pppixmap));//~var8R~
dprintf("csub_gdk_draw_rectangle before cairo_rectangle cairo_status=%d\n",cairo_status(Gpgc));//~var8R~
    	gdk_cairo_rectangle(Ppgc,&rect);                           //~var8R~
dprintf("csub_gdk_draw_rectangle before cairo_fill cairo_status=%d\n",cairo_status(Gpgc));//~var8R~
    	cairo_fill(Ppgc);                                          //~var8R~
dprintf("csub_gdk_draw_rectangle after cairo_fill cairo_status=%d\n",cairo_status(Gpgc));//~var8R~
    }                                                              //~var8R~
    else                                                           //~var8R~
    {                                                              //~var8R~
    	cairo_move_to(Ppgc,Pxx,Pyy);                               //~var8R~
	    cairo_line_to(Ppgc,Pxx+Pww,Pyy);                           //~var8R~
	    cairo_line_to(Ppgc,Pxx+Pww,Pyy+Phh);                       //~var8R~
	    cairo_line_to(Ppgc,Pxx,Pyy+Phh);                           //~var8R~
	    cairo_line_to(Ppgc,Pxx,Pyy);                               //~var8R~
    	cairo_stroke(Ppgc);                                        //~var8R~
    }                                                              //~var8R~
#ifdef AAA                                                         //~var8R~
    cairo_fill(Ppgc);                                              //~var8R~
#endif                                                             //~var8R~
	dprintf("csub_gdk_draw_rectangle pixmap return ref=%d\n",cairo_surface_get_reference_count(Pppixmap));//~var8R~
}//csub_gdk_draw_rectangle                                         //~var8R~
#ifdef AAA  //notused                                              //~vb7tI~
//*************************************************************************//~var8R~
void csub_gdk_draw_rectangle_direct(GtkWidget *Ppwidget,GdkColor *Ppcolor,gboolean Pfill,int Pxx,int Pyy,int Pww,int Phh)//~var8R~
{                                                                  //~var8R~
#if GTK_CHECK_VERSION(3,22,0)                                      //~vb7tI~
    cairo_rectangle_int_t rect;                                    //~vb7tI~
#else                                                              //~vb7tI~
    GdkRectangle rect;                                             //~var8R~
#endif                                                             //~vb7tI~
    cairo_t *cr;                                                   //~var8R~
    GdkRGBA *prgba;                                                //~var8R~
//**************************************************************   //~var8R~
	dprintf("csub_gdk_draw_rectangle_direct fill=%d,widget=%p,ww=%d,hh=%d,xx=%d,yy=%d\n",Pfill,Ppwidget,Pww,Phh,Pxx,Pyy);//~var8R~
	rect.x=Pxx;                                                    //~var8R~
	rect.y=Pyy;                                                    //~var8R~
	rect.width=Pww;                                                //~var8R~
	rect.height=Phh;                                               //~var8R~
#if GTK_CHECK_VERSION(3,22,0)                                      //~vb7tI~
	cr=csub_get_cairot(0,Ppwidget,&rect);                          //~vb7tR~
    dprintf("csub_gdk_draw_rectangle_direct_new widget=%p,cairot=%p\n",Ppwidget,cr);//~vb7tR~
#else                                                              //~vb7tI~
	cr=gdk_cairo_create(gtk_widget_get_window(Ppwidget));          //~var8R~
#endif                                                             //~vb7tI~
	prgba=csub_gdkColor2RGBA(Ppcolor,-1/*alpha*/);                 //~var8R~
    cairo_set_source_rgb(cr,prgba->red,prgba->green,prgba->blue);  //~var8R~
    if (Pfill)                                                     //~var8R~
    {                                                              //~var8R~
    	gdk_cairo_rectangle(cr,&rect);                             //~var8R~
    	cairo_fill(cr);                                            //~var8R~
    }                                                              //~var8R~
    else                                                           //~var8R~
    {                                                              //~var8R~
    	cairo_move_to(cr,Pxx,Pyy);                                 //~var8R~
	    cairo_line_to(cr,Pxx+Pww,Pyy);                             //~var8R~
	    cairo_line_to(cr,Pxx+Pww,Pyy+Phh);                         //~var8R~
	    cairo_line_to(cr,Pxx,Pyy+Phh);                             //~var8R~
	    cairo_line_to(cr,Pxx,Pyy);                                 //~var8R~
    	cairo_stroke(cr);                                          //~var8R~
    }                                                              //~var8R~
    gdk_rgba_free(prgba);                                          //~var8R~
#if GTK_CHECK_VERSION(3,22,0)                                      //~vb7tI~
	csub_get_cairot(CSGCO_END,0);                                  //~vb7tR~
#endif                                                             //~vb7tI~
    cairo_destroy(cr);                                             //~var8R~
}//csub_gdk_draw_rectangle                                         //~var8R~
#endif //AAA                                                       //~vb7tR~
//*************************************************************************//~var8R~
PangoAttribute *csub_get_attribute_background(GdkColor *Ppbg)      //~var8R~
{                                                                  //~var8R~
	PangoAttribute *pattr;                                         //~var8R~
//**************                                                   //~var8R~
	UTRACEP("csub_get_attribute_background\n");                    //~var8R~
	pattr=pango_attr_background_new(Ppbg->red,Ppbg->green,Ppbg->blue);//~var8R~
    pattr->start_index=0;	//start byte to apply                  //~var8R~
    pattr->end_index=-1;                                           //~var8R~
	return pattr;                                                  //~var8R~
}//csub_get_attribute_background                                   //~var8R~
//*************************************************************************//~var8R~
PangoAttribute *csub_get_attribute_foreground(GdkColor *Ppfg)      //~var8R~
{                                                                  //~var8R~
	PangoAttribute *pattr;                                         //~var8R~
//**************                                                   //~var8R~
	UTRACEP("csub_get_attribute_foreground\n");                    //~var8R~
	pattr=pango_attr_foreground_new(Ppfg->red,Ppfg->green,Ppfg->blue);//~var8R~
    pattr->start_index=0;                                          //~var8R~
    pattr->end_index=-1;                                           //~var8R~
	return pattr;                                                  //~var8R~
}//csub_get_attribute_background                                   //~var8R~
//*************************************************************************//~var8R~
PangoAttrList *csub_get_attrlist_textcolor(GdkColor *Ppfg,GdkColor *Ppbg)//~var8R~
{                                                                  //~var8R~
	PangoAttribute *pattrfg,*pattrbg;                              //~var8R~
	PangoAttrList  *plist;                                         //~var8R~
//**************                                                   //~var8R~
	plist=pango_attr_list_new();                                   //~var8R~
    if (Ppfg)                                                      //~var8R~
    {                                                              //~var8R~
		pattrfg=csub_get_attribute_foreground(Ppfg);               //~var8R~
		pango_attr_list_insert(plist,pattrfg);                     //~var8R~
    }                                                              //~var8R~
    if (Ppbg)                                                      //~var8R~
    {                                                              //~var8R~
		pattrbg=csub_get_attribute_background(Ppbg);               //~var8R~
		pango_attr_list_insert(plist,pattrbg);                     //~var8R~
    }                                                              //~var8R~
	return plist;                                                  //~var8R~
}//csub_get_attrlist_textcolor                                     //~var8R~
//*************************************************************************//~vbzbI~
void utracelayoutAttr(PangoLayout *Pplayout)                       //~vbzbI~
{                                                                  //~vbzbI~
	PangoAttrList *al=pango_layout_get_attributes(Pplayout);       //~vbzbI~
    if (al)                                                        //~vbzbI~
    {                                                              //~vbzbI~
#ifdef PANGO_VERSION_1_5                                           //~vbA3I~
    	UTRACEP("%s:%p:%s\n",UTT,Pplayout,pango_attr_list_to_string(al));//~vbzbR~
#else                                                              //~vbA3I~
    	UTRACEP("%s:%s is from ver 1.5\n",UTT,"Pplayout,pango_attr_list_to_string");//~vbA3I~
#endif                                                             //~vbA3I~
    }                                                              //~vbzbI~
    else                                                           //~vbzbI~
    	UTRACEP("%s:returned null attrlist,layout=%p\n",UTT,Pplayout);//~vbzbR~
}                                                                  //~vbzbI~
//*************************************************************************//~var8R~
void csub_layout_set_textcolor(PangoLayout *Pplayout,GdkColor *Ppfg,GdkColor *Ppbg)//~var8R~
{                                                                  //~var8R~
	PangoAttrList  *plist;                                         //~var8R~
//**************                                                   //~var8R~
	UTRACEP("%s:csub_layout_set_textcolor before,fg=%s,bg=%s\n",UTT,csub_GdkColorToString(Ppfg),csub_GdkColorToString(Ppbg));                 //~var8R~//~vbzbR~
//  UTRACELAYOUT(Pplayout);                                        //~var8R~
    plist=csub_get_attrlist_textcolor(Ppfg,Ppbg);                  //~var8R~
    pango_layout_set_attributes(Pplayout,plist); //do pango_layout_clear_lines//~var8R~
    UTRACELAYOUT_ATTR(Pplayout);                                   //~vbzbR~
	UTRACEP("csub_layout_set_textcolor after Gppangoattrlist=%p\n",Gppangoattrlist);//~var8R~
//  UTRACELAYOUT(Pplayout);                                        //~var8R~
	pango_attr_list_unref(plist);                                  //~var8R~
}//csub_layout_set_textcolor                                       //~vbzbR~
//*************************************************************************//~var8R~
void csub_gdk_draw_layout_with_colors(GdkPixmap *Pppixmap,GdkGC *Ppgc,int Pxx,int Pyy,PangoLayout *Pplayout,GdkColor *Ppfg,GdkColor *Ppbg)//~var8R~
{                                                                  //~var8R~
//    PangoAttrList  *plist;                                       //~var8R~
//**************                                                   //~var8R~
//	gdk_cairo_set_source_color(Ppgc,Ppfg);                         //~var8R~
//#ifdef AAA                                                       //~var8R~
//    csub_gdk_gc_set_rgb(Ppgc,Ppfg);                              //~var8R~
//#else                                                            //~var8R~
//    UTRACEP("csub_gdk_draw_layout_width_colors\n");              //~var8R~
//    UTRACELAYOUT(Pplayout);                                      //~var8R~
//    plist=csub_get_attrlist_textcolor(Ppfg,Ppbg);                //~var8R~
//    UTRACEP("csub_gdk_draw_layout_width_colors after textcolor\n");//~var8R~
//    UTRACELAYOUT(Pplayout);                                      //~var8R~
//#ifdef AAA                                                       //~var8R~
//    pango_layout_set_attributes(Pplayout,plist); //do pango_layout_clear_lines//~var8R~
//    UTRACEP("csub_gdk_draw_layout_width_colors after setattr\n");//~var8R~
//    UTRACELAYOUT(Pplayout);                                      //~var8R~
//#endif                                                           //~var8R~
//    pango_attr_list_unref(plist);                                //~var8R~
//    UTRACEP("csub_gdk_draw_layout_width_colors after unref\n");  //~var8R~
//    UTRACELAYOUT(Pplayout);                                      //~var8R~
//#endif                                                           //~var8R~
//  pango_cairo_update_layout(Ppgc,Pplayout);     //FIXME var8tst  //~var8R~
	UTRACEP("%s:x=%d,y=%d,fg=(%02x,%02x,%02x),bg=(%02x,%02x,%02x),text=%s\n",UTT,Pxx,Pyy,//~vbz5R~
		Ppfg->red,Ppfg->green,Ppfg->blue,Ppbg->red,Ppbg->green,Ppbg->blue,//~vbz5R~
		UB2XS(0/*opt*/,pango_layout_get_text(Pplayout),0/*len*/)); //~vbA3R~
	csub_gdk_draw_layout(NULL/*already GC has surface*/,Ppgc,Pxx,Pyy,Pplayout);//~var8R~
}//csub_gdk_draw_layout_with_colors                                //~var8R~
//*************************************************************************//~vbA3I~
void csubDrawLayoutTempColor(GdkPixmap *Pppixmap,GdkGC *Ppgc,int Pxx,int Pyy,PangoLayout *Pplayout,GdkColor *PpfgTemp,GdkColor *Ppfg,GdkColor *Ppbg)//~vbA3R~
{                                                                  //~vbA3I~
//    PangoAttrList  *plist;                                       //~vbA3I~
//**************                                                   //~vbA3I~
	UTRACEP("%s:x=%d,y=%d,temp=%s,fg=%s,bg=%s,text=%s\n",UTT,Pxx,Pyy,COLOR2STRING(PpfgTemp),COLOR2STRING(Ppfg),COLOR2STRING(Ppbg),pango_layout_get_text(Pplayout));//~vbA3I~
#ifndef OPTGTK3                                                    //~vbA3I~
	gdk_draw_layout_with_colors(Pppixmap,Ppgc,Pxx,Pyy,Gplayout,PpfgTemp,Ppbg);//~vbA3R~
#else   //OPTGTK3                                                  //~vbA3I~
	csub_layout_set_textcolor(Gplayout,PpfgTemp,Ppbg);             //~vbA3I~
	gdk_draw_layout_with_colors(Pppixmap,Ppgc,Pxx,Pyy,Gplayout,PpfgTemp,Ppbg);//~vbA3R~
	csub_layout_set_textcolor(Gplayout,Ppfg,Ppbg);                 //~vbA3I~
#endif                                                             //~vbA3I~
}//csub_gdk_draw_layout_with_colors                                //~vbA3I~
//*************************************************************************//~var8R~
//*pixmap is not used, it was set as source to gc                  //~var8R~
//*************************************************************************//~var8R~
void csub_gdk_draw_layout(GdkPixmap *Pppixmap,GdkGC *Ppgc,int Pxx,int Pyy,PangoLayout *Pplayout)//~var8R~
{                                                                  //~var8R~
#ifdef AAA                                                         //~var8R~
    cairo_surface_t *cs;                                           //~var8R~
    int ww,hh;                                                     //~var8R~
#endif                                                             //~var8R~
//**************************************************************   //~var8R~
#ifdef AAA                                                         //~var8R~
	if (Pppixmap)                                                  //~var8R~
    {                                                              //~var8R~
    	cs=(cairo_surface_t*)Pppixmap;                             //~var8R~
		dprintf("csub_gdk_draw_layout pixmap=%p,ref=%d\n",Pppixmap,cairo_surface_get_reference_count(Pppixmap));//~var8R~
		gdk_pixmap_get_size(Pppixmap,&ww,&hh);                     //~var8R~
    	cairo_set_source_surface(Ppgc,cs,ww,hh);                   //~var8R~
    }                                                              //~var8R~
#endif                                                             //~var8R~
    UTRACEP("%s:before csub_gdk_draw_layout,Pxx=%d,Pyy=%d\n",UTT,Pxx,Pyy);                      //~var8R~//~vbz5R~
//  UTRACELAYOUT(Pplayout);                                        //~var8R~
    cairo_move_to(Ppgc,Pxx,Pyy);                                   //~var8R~
    pango_cairo_show_layout(Ppgc,Pplayout);                        //~var8R~
    UTRACEP("%s:after csub_gdk_draw_layout\n",UTT);                       //~var8R~//~vbz5R~
    UTRACELAYOUT(Pplayout);                                        //~var8R~//~vbzbR~
//	dprintf("csub_gdk_draw_layout pixmap=%p,ref=%d\n",Pppixmap,cairo_surface_get_reference_count(Pppixmap));//~var8R~
}//csub_gdk_draw_layout                                            //~var8R~
//*************************************************************************//~var8R~
void csub_gdk_gc_set_foreground(GdkGC *Ppgc,GdkColor *Ppfg)        //~var8R~
{                                                                  //~var8R~
//	gdk_cairo_set_source_color(Ppgc,Ppfg);                         //~var8R~
    UTRACEP("%s:fg=%s\n",UTT,COLOR2STRING(Ppfg));                  //~vbzbR~
	csub_gdk_gc_set_rgb(Ppgc,Ppfg);
}//csub_gdk_gxe_set_foreground                                     //~var8R~
//*************************************************************************//~vbzbI~
void csub_gdk_gc_set_foregroundA(GdkGC *Ppgc,GdkColor *Ppfg,int PalphaRate)//~vbzbR~
{                                                                  //~vbzbI~
	UTRACEP("%s:alphaRate=%d,color=%s\n",UTT,PalphaRate,COLOR2STRING(Ppfg));//~vbzbR~
	double alpha=65535.0*PalphaRate/100;                           //~vbzbI~
	csub_gdk_gc_set_rgba(Ppgc,Ppfg,alpha);                         //~vbzbI~
}                                                                  //~vbzbI~
#ifdef AAA //not used                                              //~vb7tI~
//*************************************************************************//~var8R~
//*called when cairo_t is destroyed                                //~var8R~
//*************************************************************************//~var8R~
void csub_cairo_userdata_bg_destroy(void *Puserdata)               //~var8R~
{                                                                  //~var8R~
	if (Puserdata)                                                 //~var8R~
		gdk_color_free((GdkColor*)Puserdata);                      //~var8R~
}//csub_cairo_userdata_destroy                                     //~var8R~
#endif                                                             //~vb7tI~
//*************************************************************************//~var8R~
void csub_gdk_gc_set_background(GdkGC *Ppgc,GdkColor *Ppfg)        //~var8R~
{                                                                  //~var8R~
//    GdkColor *pcolor;                                            //~var8R~
//*********************	                                           //~var8R~
//    pcolor=gdk_color_copy(Ppfg);                                 //~var8R~
//    cairo_set_user_data(Ppgc,GXE_CAIRO_USERDATA_KEY_BG,pcolor,csub_cairo_userdata_bg_destroy);//~var8R~
}//csub_gdk_gxe_set_foreground                                     //~var8R~
//*************************************************************************//~var8R~
void csub_gdk_gc_unref(GdkGC *Ppgc)                                //~var8R~
{                                                                  //~var8R~
	cairo_destroy(Ppgc);                                           //~var8R~
}//csub_gdk_gc_unref                                               //~var8R~
//*************************************************************************//~var8R~
void csub_gtk_combo_set_popdown_strings(GtkComboBoxText *Ppwidget,GList *Pplist)//~var8R~
{                                                                  //~var8R~
    GList *pgl;                                                    //~var8R~
//**************************                                       //~var8R~
    gtk_combo_box_text_remove_all((GtkComboBoxText*)Ppwidget);     //~var8R~
    for (pgl=Pplist;pgl!=NULL;pgl=pgl->next)                       //~var8R~
    {                                                              //~var8R~
    	gtk_combo_box_text_append_text((GtkComboBoxText*)Ppwidget,(gchar *)(pgl->data));//~var8R~
    }                                                              //~var8R~
}//csub_gtk_combo_set_popdown_strings                              //~var8R~
//*************************************************************************//~var8R~
cairo_surface_t *csub_pixmap_new(GtkWidget *Ppwidget,int Pwidth,int Pheight,int Pdepth)//~var8R~
{                                                                  //~var8R~
#ifdef AAA                                                         //~var8R~
    GdkVisual *pv;                                                 //~var8R~
    int depth;                                                     //~var8R~
    cairo_format_t fmt;                                            //~var8R~
    cairo_surface_t *cs;                                           //~var8R~
    cairo_status_t   stat;                                         //~var8R~
//**************************                                       //~var8R~
	pv=gdk_window_get_visual(Pwindow);                             //~var8R~
    depth=Pdepth;                                                  //~var8R~
    if (depth==-1)                                                 //~var8R~
    	depth=gdk_visual_get_depth(pv);                            //~var8R~
    switch(depth)                                                  //~var8R~
    {                                                              //~var8R~
    case 32:                                                       //~var8R~
    	fmt=CAIRO_FORMAT_ARGB32;                                   //~var8R~
    	break;                                                     //~var8R~
    case 24:                                                       //~var8R~
    	fmt=CAIRO_FORMAT_RGB24;                                    //~var8R~
    	break;                                                     //~var8R~
    case 8:                                                        //~var8R~
    	fmt=CAIRO_FORMAT_A8;                                       //~var8R~
    	break;                                                     //~var8R~
    case 1:                                                        //~var8R~
    	fmt=CAIRO_FORMAT_A1;                                       //~var8R~
    	break;                                                     //~var8R~
    default:                                                       //~var8R~
    	fmt=CAIRO_FORMAT_ARGB32;                                   //~var8R~
    }                                                              //~var8R~
    cs=cairo_image_surface_create(fmt,Pwidth,Pheight);             //~var8R~
    stat=cairo_surface_status(cs);                                 //~var8R~
	dprintf("csub_gdk_pixmap_new surface=%p status=%d ww=%d,hh=%d,ref=%d\n",cs,stat,Pwidth,Pheight,cairo_surface_get_reference_count(cs));//~var8R~
    return cs;                                                     //~var8R~
#endif                                                             //~var8R~
    GdkWindow *pwindow;                                            //~var8R~
    cairo_surface_t *cs;                                           //~var8R~
//**************************                                       //~var8R~
	pwindow=gtk_widget_get_window(Ppwidget);                       //~var8R~
    cs=gdk_window_create_similar_surface(pwindow,CAIRO_CONTENT_COLOR,Pwidth,Pheight);//~var8R~
	dprintf("csub_gdk_pixmap_new surface=%p ww=%d,hh=%d,ref=%d,stat=%d\n",cs,Pwidth,Pheight,cairo_surface_get_reference_count(cs),cairo_surface_status(cs));//~var8R~
    return cs;                                                     //~var8R~
}//csub_gdk_pixmap_new                                             //~var8R~
//*************************************************************************//~var8R~
void csub_gtk_widget_get_child_requisition(GtkWidget* Ppwidget,GtkRequisition *Ppreq)//~var8R~
{                                                                  //~var8R~
	GtkRequisition min,natural;                                    //~var8R~
//*******************                                              //~var8R~
	gtk_widget_get_preferred_size(Ppwidget,&min,&natural);         //~var8R~
    *Ppreq=natural;                                                //~var8R~
}//csub_gtk_widget_get_child_requisition                           //~var8R~
//*************************************************************************//~var8R~
void csub_gdk_pixmap_get_size(GdkPixmap *Pppixmap,int *Ppwidth,int *Ppheight)//~var8R~
{                                                                  //~var8R~
	*Ppwidth=cairo_image_surface_get_width(Pppixmap);              //~var8R~
	*Ppheight=cairo_image_surface_get_height(Pppixmap);            //~var8R~
}//csub_gdk_pixmap_get_size                                        //~var8R~
//*************************************************************************//~var8R~
void csub_gdk_colormap_alloc_color(GdkColormap */*GdkVisual*/ Ppcolormap,GdkColor *Ppcolor,gboolean Pwritable,gboolean Pbestmatch)//~var8R~
{                                                                  //~var8R~
//FIXME                                                            //~var8R~
}//csub_gdk_colormap_alloc_color                                   //~var8R~
//*************************************************************************//~var8R~
void csub_get_device(GdkDevice **Ppmouse,GdkDevice **Ppkbd)        //~var8R~
{                                                                  //~var8R~
	GdkDevice *pdevice,*pdevice2;                                  //~var8R~
	GdkDisplay *pdisplay;                                          //~var8R~
#if GTK_CHECK_VERSION(3,20,0)                                      //~vb7tR~
    GdkSeat *pseat;                                                //~vb7tR~
#else                                                              //~vb7tR~
	GdkDeviceManager *pmgr;                                        //~var8R~
#endif                                                             //~vb7tR~
    GdkInputSource source;                                         //~var8R~
    GdkDeviceType  type;                                           //~var8R~
//*****************                                                //~var8R~
	pdisplay=gdk_display_get_default();                            //~var8R~
#if GTK_CHECK_VERSION(3,20,0)                                      //~vb7tR~
    pseat=gdk_display_get_default_seat(pdisplay);                  //~vb7tR~
    pdevice=gdk_seat_get_pointer(pseat);                           //~vb7tR~
#else                                                              //~vb7tR~
	pmgr=gdk_display_get_device_manager(pdisplay);                 //~var8R~
	pdevice=gdk_device_manager_get_client_pointer(pmgr);           //~var8R~
#endif                                                             //~vb7tR~
	type=gdk_device_get_device_type(pdevice);                      //~var8R~
    if (type==GDK_DEVICE_TYPE_SLAVE)                               //~var8R~
		pdevice=gdk_device_get_associated_device(pdevice);//get master//~var8R~
	pdevice2=gdk_device_get_associated_device(pdevice);//paired for master//~var8R~
    source=gdk_device_get_source(pdevice);                         //~var8R~
    if (Ppkbd)                                                     //~var8R~
    {                                                              //~var8R~
    	if (source==GDK_SOURCE_KEYBOARD)                           //~var8R~
	        *Ppkbd=pdevice;                                        //~var8R~
        else                                                       //~var8R~
	        *Ppkbd=pdevice2;                                       //~var8R~
    }                                                              //~var8R~
    if (Ppmouse)                                                   //~var8R~
    {                                                              //~var8R~
    	if (source==GDK_SOURCE_KEYBOARD)                           //~var8R~
	        *Ppmouse=pdevice2;                                     //~var8R~
        else                                                       //~var8R~
	        *Ppmouse=pdevice;                                      //~var8R~
    }                                                              //~var8R~
}//csub_get_device_mouse                                           //~var8R~
//*************************************************************************//~var8R~
gboolean csub_gdk_pointer_is_grabbed()                             //~var8R~
{                                                                  //~var8R~
	GdkDevice *pdevice;                                            //~var8R~
	GdkDisplay *pdisplay;                                          //~var8R~
#if GTK_CHECK_VERSION(3,20,0)                                      //~vb7tR~
    GdkSeat *pseat;                                                //~vb7tR~
#else                                                              //~vb7tR~
	GdkDeviceManager *pmgr;                                        //~var8R~
#endif                                                             //~vb7tR~
//*****************                                                //~var8R~
	pdisplay=gdk_display_get_default();                            //~var8R~
#if GTK_CHECK_VERSION(3,20,0)                                      //~vb7tR~
    pseat=gdk_display_get_default_seat(pdisplay);                  //~vb7tR~
    pdevice=gdk_seat_get_pointer(pseat);                           //~vb7tR~
#else                                                              //~vb7tR~
	pmgr=gdk_display_get_device_manager(pdisplay);                 //~var8R~
	pdevice=gdk_device_manager_get_client_pointer(pmgr);           //~var8R~
#endif                                                             //~vb7tR~
	return gdk_display_device_is_grabbed(pdisplay,pdevice);        //~var8R~
}//csub_gdk_pointer_is_grabbed                                     //~var8R~
//*************************************************************************//~var8R~
void csub_gdk_pointer_ungrab(guint32 Ptime)                        //~var8R~
{                                                                  //~var8R~
#if GTK_CHECK_VERSION(3,20,0)                                      //~vb7tR~
    GdkSeat *pseat;                                                //~vb7tR~
#else                                                              //~vb7tR~
	GdkDevice *pdevice;                                            //~var8R~
	GdkDeviceManager *pmgr;                                        //~var8R~
#endif                                                             //~vb7tR~
//*****************                                                //~var8R~
#if GTK_CHECK_VERSION(3,20,0)                                      //~vb7tR~
    pseat=gdk_display_get_default_seat(gdk_display_get_default()); //~vb7tR~
    gdk_seat_ungrab(pseat);                                        //~vb7tR~
#else                                                              //~vb7tR~
	pmgr=gdk_display_get_device_manager(gdk_display_get_default());//~var8R~
	pdevice=gdk_device_manager_get_client_pointer(pmgr);           //~var8R~
	gdk_device_ungrab(pdevice,Ptime);                              //~var8R~
#endif                                                             //~vb7tR~
}//csub_gdk_pointer_ungrab                                         //~var8R~
//*************************************************************************//~var8R~
void csub_gdk_keyboard_ungrab(guint32 Ptime)                       //~var8R~
{                                                                  //~var8R~
#if GTK_CHECK_VERSION(3,20,0)                                      //~vb7tR~
    GdkSeat *pseat;                                                //~vb7tR~
#else                                                              //~vb7tR~
	GdkDevice *pkbddevice;                                         //~var8R~
#endif                                                             //~vb7tR~
//*****************                                                //~var8R~
#if GTK_CHECK_VERSION(3,20,0)                                      //~vb7tR~
    pseat=gdk_display_get_default_seat(gdk_display_get_default()); //~vb7tR~
    gdk_seat_ungrab(pseat);                                        //~vb7tR~
#else                                                              //~vb7tR~
	csub_get_device(NULL,&pkbddevice);                             //~var8R~
	gdk_device_ungrab(pkbddevice,Ptime);                           //~var8R~
#endif                                                             //~vb7tR~
}//csub_gdk_keyboard_ungrab                                        //~var8R~
//*************************************************************************//~var8R~
void csub_pixmap_destroy(GdkPixmap *Pppixmap)                      //~var8R~
{                                                                  //~var8R~
	int ctr,ii;                                                    //~var8R~
//*****************                                                //~var8R~
	ctr=cairo_surface_get_reference_count(Pppixmap);               //~var8R~
	dprintf("csub_pixmap_destroy:%p,ref=%d\n",Pppixmap,ctr);       //~var8R~
    for (ii=ctr;ii>0;ii--)                                         //~var8R~
    {                                                              //~var8R~
		dprintf("csub_pixmap_destroy:%p,ii=%d,ref=%d\n",Pppixmap,ii,cairo_surface_get_reference_count(Pppixmap));//~var8R~
		cairo_surface_destroy(Pppixmap);                           //~var8R~
    }                                                              //~var8R~
}//csub_pixmap_dstroy                                              //~var8R~
//*************************************************************************//~var8R~
//*ref cont up before destry gc which related to a pixmap          //~var8R~
//*************************************************************************//~var8R~
void csub_gc_destroy_pixmap(GdkGC *Ppgc,GdkPixmap *Pppixmap)       //~var8R~
{                                                                  //~var8R~
//*****************                                                //~var8R~
    if (Pppixmap)                                                  //~var8R~
		cairo_surface_reference(Pppixmap);	//protect ref count reaches to 0//~var8R~
	csub_gdk_gc_unref(Ppgc);		//destroy cairo_t which sourc is cairo_surface//~var8R~
    if (Pppixmap)                                                  //~var8R~
		csub_pixmap_destroy(Pppixmap);                             //~var8R~
}//csub_pixmap_dstroy                                              //~var8R~
#endif                                                             //~var8R~
#if GTK_CHECK_VERSION(3,22,0)                                      //~vb7tI~
#ifdef AAA                                                         //~vb7tI~
//*save DrawingContext                                             //~vb7tI~
#define CSUB_MAXGC       5                                         //~vb7tI~
static GtkWidget         *Sgdkw[CSUB_MAXGC];                       //~vb7tR~
static GdkDrawingContext *Sgdkdc[CSUB_MAXGC];                      //~vb7tI~
//*************************************************************************//~vb7tI~
//*keep for multiple cairo_t                                       //~vb7tI~
//*************************************************************************//~vb7tI~
GdkDrawingContext *csub_get_cairot_old(GtkWidget *Ppwidget)        //~vb7tI~
{                                                                  //~vb7tI~
	int ii;                                                        //~vb7tI~
	GdkDrawingContext *pdc=0;                                      //~vb7tI~
//*******************                                              //~vb7tI~
    for (ii=0;ii<CSUB_MAXGC;ii++)                                  //~vb7tI~
    {                                                              //~vb7tI~
    	if (Ppwidget==Sgdkw[ii])                                   //~vb7tI~
        {                                                          //~vb7tI~
        	pdc=Sgdkdc[ii];                                        //~vb7tI~
            break;                                                 //~vb7tI~
        }                                                          //~vb7tI~
    }                                                              //~vb7tI~
	dprintf("%s:widget=%p,ii=%d,context=%p\n",UTT,Ppwidget,ii,pdc);//~vb7tI~
    return pdc;                                                    //~vb7tI~
}//csub_get_cairot_new                                             //~vb7tI~
//*************************************************************************//~vb7tI~
int csub_get_cairot_freeold(GtkWidget *Ppwidget)                   //~vb7tR~
{                                                                  //~vb7tI~
	int ii,rc=0;                                                   //~vb7tI~
	GdkDrawingContext *pdc=0;                                      //~vb7tI~
	GdkWindow *pgdkw;                                              //~vb7tI~
//*******************                                              //~vb7tI~
    for (ii=0;ii<CSUB_MAXGC;ii++)                                  //~vb7tI~
    {                                                              //~vb7tI~
    	if (Ppwidget==Sgdkw[ii])                                   //~vb7tI~
        {                                                          //~vb7tI~
            pdc=Sgdkdc[ii];                                        //~vb7tI~
			dprintf("%s:found free context widget=%p,ii=%d,widget=%p,context=%p\n",UTT,Ppwidget,ii,Ppwidget,pdc);//~vb7tI~
		    pgdkw=gtk_widget_get_window(GTK_WIDGET(Ppwidget));     //~vb7tI~
			gdk_window_end_draw_frame(pgdkw,pdc);                  //~vb7tI~
	    	Sgdkw[ii]=0;                                           //~vb7tI~
	    	Sgdkdc[ii]=0;                                          //~vb7tI~
            rc=1;                                                  //~vb7tI~
            break;                                                 //~vb7tI~
        }                                                          //~vb7tI~
    }                                                              //~vb7tI~
	dprintf("%s:return widget=%p,rc=%d\n",UTT,Ppwidget,rc);        //~vb7tI~
    return rc;                                                     //~vb7tI~
}//csub_get_cairot_freeold                                         //~vb7tR~
//*************************************************************************//~vb7tI~
int csub_get_cairot_save(GtkWidget *Ppwidget,GdkDrawingContext *Ppdc)//~vb7tR~
{                                                                  //~vb7tI~
	int ii,iifree=-1,rc=0;                                         //~vb7tR~
//*******************                                              //~vb7tI~
    for (ii=0;ii<CSUB_MAXGC;ii++)                                  //~vb7tI~
    {                                                              //~vb7tI~
    	if (!Sgdkw[ii])                                            //~vb7tR~
        	if (iifree<0)                                          //~vb7tI~
	        	iifree=ii;                                         //~vb7tR~
		dprintf("%s:ii=%d,free=%d,widget=%p\n",UTT,ii,iifree,Sgdkw[ii]);//~vb7tI~
    	if (Ppwidget==Sgdkw[ii])                                   //~vb7tI~
        {                                                          //~vb7tI~
        	Sgdkdc[ii]=Ppdc;                                       //~vb7tI~
            break;                                                 //~vb7tI~
        }                                                          //~vb7tI~
    }                                                              //~vb7tI~
    if (ii>=CSUB_MAXGC)                                            //~vb7tI~
    	if (iifree>=0)                                             //~vb7tI~
        {                                                          //~vb7tI~
        	ii=iifree;                                             //~vb7tI~
        	Sgdkw[ii]=Ppwidget;                                    //~vb7tI~
        	Sgdkdc[ii]=Ppdc;                                       //~vb7tI~
            rc=1;                                                  //~vb7tI~
        }                                                          //~vb7tI~
        else                                                       //~vb7tI~
        {                                                          //~vb7tI~
	    	uerrmsgbox("Internal Error, DrawingContext table overflow(>%d)",0,//~vb7tI~
            CSUB_MAXGC);                                           //~vb7tI~
        }                                                          //~vb7tI~
	dprintf("%s:widget=%p,ii=%d,context=%p\n",UTT,Ppwidget,ii,Ppdc);//~vb7tI~
    return rc;                                                     //~vb7tR~
}//csub_get_cairot_save                                            //~vb7tR~
//*************************************************************************//~vb7tI~
//*get cairo_t                                                     //~vb7tI~
//*************************************************************************//~vb7tI~
cairo_t *csub_get_cairot(int Popt,GtkWidget *Ppwidget,cairo_rectangle_int_t *Pprect)//~vb7tR~
{                                                                  //~vb7tI~
    cairo_region_t        *preg;                                   //~vb7tI~
    cairo_t        *cr;	//=GdkGC                                   //~vb7tI~
	cairo_rectangle_int_t rect,*prect;                             //~vb7tI~
	GdkDrawingContext *pgdkdc;                                     //~vb7tI~
	GdkWindow *pgdkw;                                              //~vb7tI~
//**********************************                               //~vb7tI~
    dprintf("%s:opt=%x,prect=%p,Widget=%p\n",UTT,Popt,Pprect,Ppwidget,Pprect);//~vb7tI~
    if (Popt & CSGCO_END)	//no user                              //~vb7tR~
    {                                                              //~vb7tI~
		csub_get_cairot_freeold(Ppwidget);                         //~vb7tR~
        return 0;                                                  //~vb7tI~
    }                                                              //~vb7tI~
	pgdkdc=csub_get_cairot_old(Ppwidget);                          //~vb7tR~
    pgdkw=gtk_widget_get_window(GTK_WIDGET(Ppwidget));             //~vb7tI~
    if (!Pprect)                                                   //~vb7tI~
    {                                                              //~vb7tI~
		rect.x=0; rect.y=0;                                        //~vb7tI~
		rect.width=gdk_window_get_width(pgdkw);                    //~vb7tR~
		rect.height=gdk_window_get_height(pgdkw);                  //~vb7tR~
        prect=&rect;                                               //~vb7tI~
    }                                                              //~vb7tI~
    else                                                           //~vb7tI~
    	prect=Pprect;                                              //~vb7tI~
    dprintf("%s:widget=%p,Pprect=%p,w=%d,h=%d\n",UTT,Ppwidget,Pprect,prect->width,prect->height);//~vb7tR~
	preg=cairo_region_create_rectangle(&rect);                     //~vb7tI~
	pgdkdc=gdk_window_begin_draw_frame(pgdkw,preg);                //~vb7tR~
	cr=gdk_drawing_context_get_cairo_context(pgdkdc);              //~vb7tR~
	cairo_region_destroy(preg);                                    //~vb7tI~
	csub_get_cairot_save(Ppwidget,pgdkdc);                         //~vb7tR~
    dprintf("%s:return widget=%p,w=%d,h=%d,cairot=%p\n",UTT,Ppwidget,prect->width,prect->height,cr);//~vb7tR~
    return cr;                                                     //~vb7tI~
}//csub_get_cairot                                                 //~vb7tI~
#endif	//AAA                                                      //~vb7tI~
//*************************************************************************//~vb7tI~
//*get cairo_t                                                     //~vb7tI~
//*(DrawingContext should be closed before begin newly)            //~vb7tI~
//*************************************************************************//~vb7tI~
cairo_t *csub_get_cairot(int Popt,GtkWidget *Ppwidget,cairo_rectangle_int_t *Pprect)//~vb7tI~
{                                                                  //~vb7tI~
    cairo_t        *cr;	//=GdkGC                                   //~vb7tI~
	cairo_surface_t *cs;                                           //~vb7tI~
	GdkWindow *pgdkw;                                              //~vb7tI~
    int ww,hh;                                                     //~vb7tI~
//**********************************                               //~vb7tI~
//  dprintf("%s:opt=%x,prect=%p,Widget=%p\n",UTT,Popt,Pprect,Ppwidget,Pprect);//~vb7tI~//~vbu0R~
    dprintf("%s:opt=%x,prect=%p,Widget=%p\n",UTT,Popt,Pprect,Ppwidget);//~vbu0I~
    if (!Pprect)                                                   //~vb7tI~
    {                                                              //~vb7tI~
	    pgdkw=gtk_widget_get_window(GTK_WIDGET(Ppwidget));         //~vb7tI~
		ww=gdk_window_get_width(pgdkw);                            //~vb7tI~
		hh=gdk_window_get_height(pgdkw);                           //~vb7tI~
    }                                                              //~vb7tI~
    else                                                           //~vb7tI~
    {                                                              //~vb7tI~
		ww=Pprect->width;                                          //~vb7tI~
		hh=Pprect->height;                                         //~vb7tI~
    }                                                              //~vb7tI~
	cs=csub_pixmap_new(Ppwidget,ww,hh,-1/*Pdepth*/);               //~vb7tI~
    cr=csub_gc_new_pixmap(Gpview,cs);                              //~vb7tI~
    dprintf("%s:return widget=%p,w=%d,h=%d,cairot=%p\n",UTT,Ppwidget,ww,hh,cr);//~vb7tI~
    return cr;                                                     //~vb7tI~
}//csub_get_cairot                                                 //~vb7tI~
#endif  //GTK3.22                                                  //~vb7tR~
//*************************************************************************//~vb7zR~
//*csub_getmousestatus                                             //~vb7zR~
//*because mouse move event is not requested at interface          //~vb7zR~
//*get x,y and modifier                                            //~vb7zR~
//*************************************************************************//~vb7zR~
int csub_get_mouse_status(int Popt,int *Ppx,int *Ppy,int *Ppmod)   //~vb7zR~
{                                                                  //~vb7zR~
	int xx,yy;                                                     //~vb7zR~
	GdkModifierType mod;                                           //~vb7zR~
    GdkWindow *window;                                             //~vb7zR~
#if GTK_CHECK_VERSION(3,0,0)                                       //~vb7zR~
	GdkDevice *pmouse;                                             //~vb7zR~
#endif                                                             //~vb7zR~
//**********************************                               //~vb7zR~
#ifndef OPTGTK3                                                    //~vb7zR~
    window=Gpview->window;                                         //~vb7zR~
#else                                                              //~vb7zR~
    window=gtk_widget_get_window(Gpview);                          //~vb7zR~
#endif                                                             //~vb7zR~
#if GTK_CHECK_VERSION(3,0,0)                                       //~vb7zR~
	csub_get_device(&pmouse,NULL/*kbd*/);                          //~vb7zR~
	gdk_window_get_device_position(window,pmouse,&xx,&yy,&mod);    //~vb7zR~
#else                                                              //~vb7zR~
	gdk_window_get_pointer(window,&xx,&yy,&mod);                   //~vb7zR~
#endif                                                             //~vb7zR~
    dprintf("%s:x=%d,y=%d,mod=%x\n",UTT,xx,yy,mod);                //~vb7zR~
    if (Ppx)                                                       //~vb7zR~
    	*Ppx=xx;                                                   //~vb7zR~
    if (Ppy)                                                       //~vb7zR~
    	*Ppy=yy;                                                   //~vb7zR~
    if (Ppmod)                                                     //~vb7zR~
    	*Ppmod=(int)mod;                                           //~vb7zR~
    return 0;                                                      //~vb7zR~
}//csub_get_mouse_status                                           //~vb7zR~
//**************************************************************** //~vbz5I~
int getUcsExtent(PangoLayout *Pplayout,wchar_t Pucs)               //~vbz5R~
{                                                                  //~vbz5I~
	PangoRectangle rect_ink,rect_logical;                          //~vbz5I~
    char wku8[8];                                                  //~vbz5R~
    int rc;                                                        //~vbz5I~
//  *pu8;                                                          //~vbz5I~
//**********************                                           //~vbz5I~
	int len=uccvucs2utf(Pucs,wku8);                                //~vbz5I~
//  memcpy(wku8+len,wku8,(size_t)len);  //chk double               //~vbz5R~
//  wku8[len*2]=0;                                                 //~vbz5R~
//  UTRACED("wku8",wku8,len);                                      //~vbz5R~
    pango_layout_set_text(Pplayout,wku8,len);                      //~vbz5R~
//  pu8=pango_layout_get_text(Pplayout);                           //~vbz5R~
//  UTRACEP("%s:after setText pu8=%s,%s\n",UTT,pu8,strcmp(pu8,wku8)?"Err":"OK");//~vbz5R~
    pango_layout_get_pixel_extents(Pplayout,&rect_ink,&rect_logical);//get logical extent//~vbz5R~
    rc=rect_logical.width;                                         //~vbz5R~
    UTRACEP("%s:rc=%d,ucs=0x%04x,ink=(%d,%d),logical=(%d,%d)\n",UTT,rc,Pucs,rect_ink.width,rect_ink.height,rect_logical.width,rect_logical.width);//~vbz5R~
//  pango_layout_set_text(Pplayout,wku8,len*2);                    //~vbz5R~
//  pu8=pango_layout_get_text(Pplayout);                           //~vbz5I~
//  UTRACEP("%s:after setText pu8=%s,%s\n",UTT,pu8,strcmp(pu8,wku8)?"Err":"OK");//~vbz5I~
//  pango_layout_get_pixel_extents(Pplayout,&rect_ink,&rect_logical);//get logical extent//~vbz5R~
//  rc=rect_logical.width;                                         //~vbz5R~
//  UTRACEP("%s:rc*2=%d,ucs=0x%04x,ink=(%d,%d),logical=(%d,%d)\n",UTT,rc,Pucs,rect_ink.width,rect_ink.height,rect_logical.width,rect_logical.width);//~vbz5R~
//  rc/2=2;                                                        //~vbz5I~
    return rc;                                                     //~vbz5R~
}                                                                  //~vbz5I~
//**************************************************************** //~vbz5I~
int getSingleWidth()                                               //~vbz5I~
{                                                                  //~vbz5I~
	PangoLayout *playout;                                          //~vbz5I~
	PangoFontDescription *pfontdesc;                               //~vbz5I~
//***********************                                          //~vbz5I~
    playout=gtk_widget_create_pango_layout(Gpview,NULL);           //~vbz5I~
	pfontdesc=Gfontdata[0].FDfontdesc;                             //~vbz5I~
    UTRACEP("%s:fontname=%s\n",UTT,Gfontdata[0].FDfontname);       //~vbz5I~
    SplayoutForExtent=playout;                                     //~vbz5M~
                                                                   //~vbz5I~
	pango_layout_set_font_description(playout,pfontdesc);          //~vbz5I~
    int wwA=getUcsExtent(playout,'A');                             //~vbz5R~
    UTRACEP("%s:\'A\'=%d\n",UTT,wwA);                              //~vbz5R~
#ifndef NOTRACE                                                    //~vbzbI~
    int wwa=getUcsExtent(playout,'a');                             //~vbz5I~
    UTRACEP("%s:\'a\'=%d\n",UTT,wwa);                              //~vbz5R~
#endif                                                             //~vbzbI~
    int wwW=getUcsExtent(playout,'W');                             //~vbz5I~
    UTRACEP("%s:\'W\'=%d\n",UTT,wwW);                              //~vbz5R~
#ifndef NOTRACE                                                    //~vbzbI~
    int wwl=getUcsExtent(playout,'l');                             //~vbz5I~
    UTRACEP("%s:\'l\'=%d\n",UTT,wwl);                              //~vbz5R~
#endif                                                             //~vbzbI~
    int wwDBCS=getUcsExtent(playout,0x4e00);                       //~vbz5I~
    UTRACEP("%s:DBCS ichi 0x%04x=%d\n",UTT,0x4e00,wwDBCS);         //~vbz5R~
    int swMonospace=(wwA==wwW) ? 1:0 ;                             //~vbz5I~
    int rc;                                                        //~vbz5I~
    if (swMonospace)                                               //~vbz5I~
    	rc=wwA;                                                    //~vbz5I~
    else                                                           //~vbz5I~
//  	rc=wwDBCS-1;                                               //~vbz5I~//~vbzaR~
    	rc=(wwDBCS+1)/2;	//half of kanji                        //~vbzaI~
    UTRACEP("%s:rc=%d,swMonospace=%d,wwDBCS=%d,wwA=%d\n",UTT,rc,swMonospace,wwDBCS,wwA);//~vbz5R~
    return rc;                                                     //~vbz5I~
}                                                                  //~vbz5I~
//**************************************************************** //~vbz5I~
//*get charwidth by GetTextExtentPoint at mapinit                  //~vbz5I~
//**************************************************************** //~vbz5I~
int csubGetCursorPos(int Popt,ULONG Pucs)                          //~vbz5I~
{                                                                  //~vbz5I~
	int rc=0;                                                      //~vbz5R~
	wchar_t ucs;                                                   //~vbz5R~
#ifndef NOTRACE                                                    //~vbz5I~
    UCHAR utf8[12];                                                //~vbz5I~
    int u8len;                                                     //~vbz5I~
#endif    	                                                       //~vbz5I~
    UTRACEP("%s:ucs=0x%04x,Ssbcswidth=%d,szwchar_t=%d\n",UTT,Pucs,Ssbcswidth,sizeof(wchar_t));//~vbz5R~
	if (!Ssbcswidth)                                               //~vbz5I~
    	Ssbcswidth=getSingleWidth();                               //~vbz5I~
    if (Ssbcswidth<=0)                                             //~vbz5I~
    	return -1;                                                 //~vbz5I~
//  if (Pucs & 0xffff0000)                                         //~vbz5R~
//  	return -1;                                                 //~vbz5R~
	ucs=(wchar_t)Pucs;                                             //~vbz5R~
	int ww=getUcsExtent(SplayoutForExtent,ucs);                    //~vbz5I~
    if (ww)                                                        //~vbz5R~
	    rc=(ww<=Ssbcswidth)? 1 : 2;                                //~vbz5R~
    UTRACEP("%s:ucs=0x%04x,utf8=(%s)rc=%d ww=%d,Ssbcswidth=%d,err=%d\n",UTT,Pucs,(u8len=uccvucs2utf((UWUCS)Pucs,utf8),utf8[u8len]=0,utf8),rc,ww,Ssbcswidth);//~vbz5R~
    return rc;                                                     //~vbz5I~
}                                                                  //~vbz5I~
//*for trace simultaneously max 4 color support                    //~vbzbI~
char *csub_GdkColorToString(GdkColor *Ppcolor)                     //~vbzbI~
{                                                                  //~vbzbI~
    static char Sstr[4][32];                                       //~vbzbR~
    static int Sidx=0;                                             //~vbzbR~
    int idx=(Sidx++)%4;                                            //~vbzbI~
    char *str=Sstr[idx];                                           //~vbzbR~
    sprintf(str,"%02x-%04x,%04x,%04x",Ppcolor->pixel,Ppcolor->red,Ppcolor->green,Ppcolor->blue);//~vbzbR~
    return str;                                                    //~vbzbI~
}                                                                  //~vbzbI~
