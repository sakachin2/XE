//CID://+v7fzR~:                             update#=  711;        //~v7fzR~
//******************************************************************************//~v003I~
//v7fz:251205 (gxe) hcopy eol option for also gxe                  //~v7fzI~
//vbEf:251110 (gxe)display "+" for u-200d("-" was displayed)       //~v7EfI~
//v7f4:251007 (LNX)by v7f1, w0 NoComb(including format)  was not displayed by altchFormat('='). ifndef JJJ//~v7f4I~
//vbDs:250730 (gxe)vbDp for gxe(split combining,vhex csr data color)//~vbDsI~
//vbDh:250709 (gxe)4byte dbcs padding color was not tab color      //~vbDhI~
//vbAr:240702 (gxe:Bug)ddstr and u8 string column unmatch by utfcvdd2f for x1b<-->e286bc. Invalid char is show.//~vbArI~
//vbAq:240702 (gxe:Bug)case in Liguture occured when non-ligaturemode, line disppear(ii was init initialized)//~vbAqI~
//vbAk:240621 (gxe)display "="(same as xe) for format char other than zwj/zwnj//~vbAkI~
//vbAj:240619 (gxe)if LIG:ON and COMB:ON, allow expand line by large glyph when no split by cursor//~vbAjI~
//vbAh:240616 (gxe)display split combining(lig on and off). when added non space(for ex 'A') after combining half width shadow appears. use this effect.//~vbAhI~
//vbAf:240614 (gxe:bug)lig:on.comb:on; comb disappear              //~vbAfI~
//vbAe:240612 gxe:combining without base color was yello.          //~vbAeI~
//vbA3:240531 (Bug:gxe)SCM remaining char shown by altch color     //~vbA3I~
//vbzb:240129 (XXE:Bug)cursor hides background text                //~vbzbI~
//vbz9:240126 (BUG:gxe)gauge line have underline remaining before corsor.//~vbz9I~
//vbz5:240120 try vbz3 to XXE(apichk by char extent)               //~vbz5I~
//vbv4:221120 UTSSTART/UTSEND was made NOP by ftime deprecation; so timeb is became unused//~vbv4I~
//vbs1:201022 ftime deprecated(ftime is obsoleted POSIX2008)       //~vbs1I~
//vbmf:180803 show altch for SCM when COMBINE_NP                   //~vbmfI~
//vbme:180731 (gxe)multiple SCM support                            //~vbmeI~
//vbmc:180730 (gxe/wxe)attr:green for combining after unprintable like as console version//~vbmcR~
//vbmb:180723 (gxe:bug of vbma)unicomb:NP dose not show altch      //~vbmaI~
//vbma:180723 (gxe)colomn shift to left if ligature occured, correct it when Ligature:Off.(If selected Mono-space-font, no problem)//~vbmaI~
//vbm8:180716 (gxe:Bug)combine may reduce glyphctr(u306f+u399a)    //~vbm8I~
//vbm7:180716 (gxe:Bug)Lig:Off,split show unprintable+combine ": ;"(intermediate space exist)//~vbm7I~
//vbm5:180715 (gxe:Bug)lineno fld and top unprintable(":;") is same color so ligature not applied. So,cut strput by linenosize>//~vbm5I~
//vbm2:180714 (gxe)SCM support for ligature:On                     //~vbm2I~
//vbkw:180704 (gxe)try to keep col width for the case of u-0327 has 2 glyph(width=xx and width=0)//~vbkwI~
//vbkv:180703 (gxe)the case comb+comb, split mode may not show 2nd comb (u01b5+0327+0308) write ayt once because attr is same//~vbkvI~
//vbks:180701 SCM; try u200c(ZWNJ:zero width no join) between combined and combining when Ligature:Off split mode//~vbksR~
//vbkq:180628 (XXE)for also nocombine mode Spacing Combining Marks(SCM) unicode(if not combined,it becomes glyphctr=2)//~vbkqI~
//vbkp:180627 (gxe)do ligature for also width0 under COMBINE_NP mode//~vbkpI~
//vbkn:180627 (gxe)width=0 char over 0x20000 was not treated as combining//~vbknI~
//vbk6:180612 (XXE)Spacing Combining Marks unicode(if not combined,it becomes glyphctr=2)//~vbk6I~
//vbk4:180611 (XXE)when Ligature:OFF unicomb:COM,combining char was separated because geometry->width!=0 for combining char//~vbk4I~
//vbdn:171125 disable filemenu depending curent pcw type           //~vbdnI~
//vb7t:170128 (gxe)Gtk3 deprecated                                 //~vb7tI~
//vb5i:160918 (LNX) gdk_draw_layout_with_colors() was deprecated at GTK3;when Lig:on and not combine mode,split char was yellow.//~vb5iI~
//vb5e:160918 gxe compiler warning                                 //~vb5eI~
//vb4A:160815 if UNICOMB UNPR mode and LIGATURE ON, write altch just after base char using GetTextExtentPoint32W//~vb4AI~
//vb4r:160811 (XXE) v4f for XXE((ULIB:v6Ei)specify ligature on/off,combine on/of line by line(used for edit/filename  panel))//~vb4rI~
//vaik:130601 virtical ruler disappear when col=0                  //~vaikI~
//varc:140215 add resizehint option  --gh={Y|n}                    //~varcI~
//var8:140127 gtk3 suppott                                         //~var8I~
//vamr:131009 (GtkPrint)hcopy consider cursor pos for RTL          //~vamrI~
//vamf:131004 try scrprint by glyph like as scrdraw                //~vamfI~
//vame:131003 (BUG)keep font same as screen for syntax for scrprt  //~vameI~
//vam7:130929 add print with ligature                              //~vam7I~
//vam4:130928 file scrprint show unprintable by box char,use altch like scr draw//~vam4I~
//vam0:130911 for distro removed gnome-print,use GTKprint          //~vam0I~
//vaff:120613 (FC12)avoid uninitialized variable warning by gcc 4.4.4 on FC12(compile optio -Ox is required also)//~vaffI~
//vaa7:111117 (gcc4.6)Warning:unused-but-set                       //~vaa7I~
//va7S:100907 (BUG)mouse drag at edge of screen dose not expand copy range bat scroll.//~va7SI~
//va7G:100902 (GXE:BUG)ss3 display invalid padding char '?'        //~va7GI~
//va7D:100830 (XXE:BUG)cap menu update err(it should not be based on Mcellcopy1 bur Gcsrposy)//~va7DI~
//va6p:000623 (LNX:BUG) ligature ignored for locale file           //~va6pI~
//va6n:000623 (BUG)Guviompadch was changed to ucs by ulib v65p     //~va6nI~
//va53:100419 num setr/seti should chk margin/lrecl overflow       //~va53I~
//va42:100328 (WXE:BUG)tab,tab padding char is not visual,print alt char//~va42I~
//va3t:100221 (WXEXXE)break also at prev char of vhex data csr pos for backspace at vhex line//~va3tI~
//va3i:100208 (XXE)leave ligature to pango when ligature on        //~va3iI~
//va3d:100206 (LNX)toggle ligature temprary by A+";", change combine key A+"/"-->C+":"//~va3dI~
//va3b:100205 (GXE)no ligature for hex edit(HEX mode and EH cmd)   //~va30I~
//va30:100126 combine mode of diacritical marks by A+/(saved to ini)//~va30I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//va1M:091121 (LNX)ligature support;keep monospace for english lagature; Arabian ? I don't know.//~va1MI~
//va1K:091119 slow performance at UB9,abend when -d01(trace)       //~va1KI~
//va1D:091115 gxeprint:2column print for 4byte dbcs if wysiwig is off//~va1DI~
//va1c:091030_merge GB18030 support                                //~va1cI~
//va0U:091003!(BUG:XXE)dbcstbl should be localdbcstbl for UTF8env  //~va0UI~
//v79Y:081029 (XXE) replace unprintable by '.'                     //~v79YI~
//v79Q:081027 (XXE:BUG)0x0a or 0x0d is cause of line is not drawn;replace it by unprintable id//~v79QI~
//v79D:081011 (XXE) draw ime cursor                                //~v79DI~
//v79z:080916 DBCS tbl for C and K of CJK                          //~v79zI~
//v78D:080503 (XXE)csr write to scr direct(not pix map) to avoid old csr line draw//~v78DI~
//v78B:080426*(wxe,gxe)vertical ruler draw performance             //~v78BI~
//v780:080212 syntaxhighlight support (SYN cmd,C+s func key)       //~v780I~
//v73t:070125 cross-hair ruler support by Shift+Ctl+lbuton         //~v73tI~
//v69V:060718 (XXE)Performance tuning for pango.                   //~v69VI~
//                 gdk_draw_layout_with_color for each char one by one is too slow//~v69VI~
//                 On the other hand string draw requres monospace and usetmonospace exaust cpu on gprof.//~v69VI~
//                 Bug of monospace determination was exist.(missed to set font to layout)//~v69VI~
//                 Monospace determination obey to font rfamily attribute.//~v69VI~
//                 DBCS is not just double iof sbcs width even for monospace font.//~v69VI~
//                 So use string write for sbcs only if mono space,else use uset monospace.//~v69VI~
//v69U:060718 (XXE:BUG)errmsg "Cut/Pastet source data contains invalid data"//~v69UI~
//            because scr width is not multiple of cellw,copy data contains 1 column over//~v69UI~
//v69S:060716 (WXEXXE:BUG)corrupted dbcs disply by mouse drag when dbcs split//~v69SI~
//            It cause abend for xxe.                              //~v69SI~
//v69Q:060715 (XXE)utf conversion perfomance chk                   //~v69QI~
//v69y:060608 (XXE:BUG)missing g_free for im msg translation       //~v69yI~
//v69v:060602 (XXE:FC5)utf8 im text is not displayed               //~v69vI~
//v69s:060531 (XXE:fc5)g_locale_to_utf8 return error if null char contained//~v69sI~
//v69r:060531 (XXE)print debug message by GError                   //~v69rI~
//v69n:060530 (XXE:fc5)avoid Gtk warning "GError not initialized". //~v69nI~
//v69d:060518 (GXE:BUG)killfocus chk logic missing                 //~v69dI~
//v682:060313 (WXE:BUG)menu enable re-evaluation requred for drag selection on dirlist;and also when reset by esc key//~v682I~
//vX03:050729 for the case sbcs is monospace but dbcs is not       //~vX03I~
//vX01:050729 cellh/cellw=0 mean same as fonth/fontw               //~vX01I~
//vXXE:050611 new for XXE                                          //~vXXEI~
//v63r:050525 ignore(no cursor move) 1st mouse click after killfocus//~v63rI~
//v55W:040322 (WXE)AT cmd support;"AT(&) interval,count;cmd"       //~v55WI~
//v55u:040229 (WXE)add open with for dir-list                      //~v55uI~
//v51w:030615 (WXE)icon for MDOS and Explorer                      //~v51wI~
//******************************************************************************//~v003I~
//******************************************************************************//~v003I~
#include <sys/timeb.h>                                             //~v63rI~
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
#ifdef UTF8UCS2                                                                   //~vXXEI~//~va20R~
#include <pango/pango-types.h>                                     //~va20I~
#endif                                                             //~va20I~
                                                                   //~v003I~
#include    "ulib.h"                                               //~v003I~
#include    "udbcschk.h"                                           //~v003I~
#include    "utrace.h"                                             //~2914I~
#include    "uque.h"                                               //~v780I~
#include    "ustring.h"                                            //~vb4rI~
#include    "utf.h"                                                //~v79DR~
#include    "utf2.h"                                               //~v79DR~
#include    "ufile.h"                                              //~va1cR~
#include    "uviom.h"                                              //~va1cR~
#include    "uvio.h"                                               //~v7fzR~
#include    "uvio2.h"                                              //~v7fzI~
#ifdef UTF8UCS2                                                    //~va20I~
#include    "ucvucs.h"                                             //~va20R~
#include    "utf22.h"                                              //~va20I~
#include    "utrace.h"                                             //~va30R~
#endif                                                             //~va20I~
#define UFTIME                                                     //~vbs1I~
#include <umiscf.h>                                                //~vbs1I~
                                                                   //~vXXEI~
#include    "gxe.h"                                                //~vXXEI~
#include    "xxedef.h"                                             //~vXXEI~
#include    "xxemain.h"                                            //~vXXEI~
#include    "xxexei.h"                                             //~vXXEI~
#include    "xxecsub.h"                                            //~vXXEI~
#include    "gxemfrm.h"                                            //~v682I~
//#include    "xeacb.h"                                            //~va1cR~
//#include    "xesub2.h"                                             //~va1cR~//~va53R~
#ifdef UTF8UCS2                                                    //~va20I~
#include    "xescr.h"                                              //~va20R~
#include    "xefile.h"                                             //~va20I~
#include    "xeutf2.h"                                             //~va20I~
#endif                                                             //~va20I~
#include    "xesub2.h"                                             //~va53I~
//===============================================================================//~v003I~
	#define U8_ZWNJ    "\xe2\x80\x8c"    //U-200c:Zero Width Non Joiner//~vbksR~
	#define U8SZ_ZWNJ  3                                           //~vbksI~
	#define U8_ZWJ     "\xe2\x80\x8d"    //U-200d:Zero Width Joiner//~vbksR~
	#define U8SZ_ZWNJ  3                                           //~vbksI~
	#define U8_COMBINEBASE       "\xc2a0"    //U-00a0:No Breake Space;base of combining char to show itself//~vbksR~
	#define U8SZ_COMBININGBASE   2                                 //~vbksI~
	#define PADDING_SPLITCOMB    0x61     //"a"                    //~vbAhR~
	#define PADDING_SPLITFMT     '='                               //~vbAkR~
int isZWJZWNJ(int Popt,char *Ppu8,int Pu8len);                     //~vbAhI~
#define ISZO_ALTCH           0x01 //return altch                   //~vbAhI~
int getFormatAltchar(int Popt,char *Ppu8,int Pu8len);              //~vbAkI~
//===============================================================================//~va30R~
//  int  lineput(CDC *Ppdc,int Pprintsw,int Prow);                 //~va3bR~
    int  lineput(int Popt,CDC *Ppdc,int Pprintsw,int Prow);        //~va3bR~
	#define LPO_CSRBREAK     0x01	//strput split at csr pos      //~va3bR~
	#define LPO_CPU8         0x02	//csr is on CPU8 text          //~va3bI~
	#define LPO_VHEX         0x04	//data line of vhex line       //~va3tI~
//  #define LPO_VHEXMASK   0xff00                                  //~va3tI~//~vbDsR~
	#define LPO_VHEXMASK   0xffff00                                //~vbDsI~
	#define LPO_VHEXSHIFT       8                                  //~va3tI~
	#define LPO_GETVHEXPOS(opt) (((opt) & LPO_VHEXMASK)>>LPO_VHEXSHIFT)//~va3tI~
//	int  strput(CDC *Ppdc,int Pprintsw,int Prow,int Pcol,int Plen,USHORT Pattr,int Pcapsw);//~v69VR~
//	int  strput(CDC *Ppdc,int Pprintsw,int Prow,int Pcol,int Plen,USHORT Pattr,int Pcapsw,int Pdbcsctr);//~v780R~
//	int  strput(CDC *Ppdc,int Pprintsw,int Prow,int Pcol,int Plen,USHORT Pattr,int Pstyle,int Pcapsw,int Pdbcsctr);//~v780I~//~vbDsR~
  	int  strput(CDC *Ppdc,int Pprintsw,int Prow,int Pcol,int Plen,USHORT Pattr,int Pstyle,int Pcapsw,int Pdbcsctr,int Popt2);//~vbDsI~
#ifdef UTF8UCS2                                                    //~va20I~
	#define  SPO_PRINT         0x01       //printsw                //~va20I~
	#define  SPO_DDFMT         0x02       //data/dbcs              //~va20I~
	#define  SPO_NOLIGATURE    0x04       //str is of part of ligature disabled//~va3bI~
	#define  SPO_VHEXDATACPOS  0x08       //data start position is corresponding vhex line cursor position//~vbDsI~
#endif                                                             //~va20I~
//  int  scrcsr(void);                                             //~v78DR~
#ifndef OPTGTK3 //never used                                       //~var8R~
	void  setfgbgcolorfrompal(int Pfgpal,int Pbgpal);              //~vXXER~
#endif                                                             //~var8R~
	void  scrdrawbrush(CDC *Ppdc,PRECT Pprect,int Pbgpal);         //~vXXER~
	void  drawtext(CDC *Ppdc,int Pprintsw,int Px,int Py,char *Ptext,int Plen,int Pfgpal,int Pbgpal);//~vXXER~
//	void  drawtextstr(CDC *Ppdc,int Pprintsw,int Px,int Py,char *Ptext,char *Pdbcs,int Plen,int Pfgpal,int Pbgpal);//~v69VR~
// 	void  drawtextstr(CDC *Ppdc,int Pprintsw,int Px,int Py,char *Ptext,char *Pdbcs,int Plen,int Pfgpal,int Pbgpal,int Pdbcsctr);//~va30R~
//	void  drawtextstr(CDC *Ppdc,int Pprintsw,int Px,int Py,char *Ptext,char *Pdbcs,int Plen,int Pfgpal,int Pbgpal,int Pdbcsctr,int Prow);//~va30R~
//	void  drawtextstr(CDC *Ppdc,int Pprintsw,int Px,int Py,char *Ptext,char *Pdbcs,int Plen,int Pfgpal,int Pbgpal,int Pdbcsctr,int Prow,int Pcol);//~vb4rR~
  	void  drawtextstr(int Popt,CDC *Ppdc,int Pprintsw,int Px,int Py,char *Ptext,char *Pdbcs,int Plen,int Pfgpal,int Pbgpal,int Pdbcsctr,int Prow,int Pcol);//~vb4rI~
//	void scrruler(int Prow,int Pcol);                              //~v78BR~
//	void scrrulererase(int Prow,int Pcol);                         //~v78BR~
//	void scrdrawline(CPoint *Pppoint);                             //~v78BR~
#ifndef OPTGTK3                                                    //~var8R~
  	void scrdrawline(CDC *Ppdc,CPoint *Pppoint);                   //~v78BI~
#else   //OPTGTK3                                                  //~var8R~
	void scrdrawline(GdkGC *Ppgc,CPoint *Pppoint);                 //~var8R~
#endif                                                             //~var8R~
//  int  xxemain_setfont(int Pcase);                               //~v780R~//~vameR~
    int  xxemain_setfont(int Pcase,int Pprintsw);                  //~vameI~
	int drawimcsr(int Popt,int Pxx,int Pyy);                       //~v79DR~
int drawtextstr_ligatureu8_nocombine(int Popt,CDC *Ppdc,GdkGC *Ppgc,int Px,int Py,GdkColor *Ppfg,GdkColor *Ppbg,char *Ppu8,int Pu8len,char *Pdddata,char *Pdddbcs,char *Plcdbcs,int Pddlen);//~vb4AR~
int updateFileMenu(int Popt);                                      //~vbdnR~
int xxescr_chkWidth0Ovf(int Popt,char *Pdddata,char *Pdddbcs,int Pddlen);//~vbknR~
#define CW0OO_SBCS  0x01                                           //~vbkvI~
void  drawtextstr_NoLigatureu8_NoCombine(int Popt,CDC *Ppdc,GdkGC *Ppgc,int Px,int Py,GdkColor *Ppfg,GdkColor *Ppbg,char *Ppu8,int Pu8len,char *Pdddata,char *Pdddbcs,char *Plcdbcs,int Pddlen);//~vbknI~
int drawtextstr_NoLigatureu8_SCM(int Popt,CDC *Ppdc,GdkGC *Ppgc,int Px,int Py,GdkColor *Ppfg,GdkColor *Ppbg,char *Ppu8,int Pu8len,char *Pdddata,char *Pdddbcs,char *Plcdbcs,int Pddlen);//~vbkqI~
int drawtextstr_NoLigatureu8_NoSCM(int Popt,CDC *Ppdc,GdkGC *Ppgc,int Px,int Py,GdkColor *Ppfg,GdkColor *Ppbg,char *Ppu8,int Pu8len,char *Pdddata,char *Pdddbcs,char *Plcdbcs,int Pddlen);//~vbkqI~
int  drawtextstr_ligatureu8_SCM(int Popt,CDC *Ppdc,GdkGC *Ppgc,int Px,int Py,GdkColor *Ppfg,GdkColor *Ppbg,char *Ppu8,int Pu8len,char *Pdddata,char *Pdddbcs,char *Plcdbcs,int Pddlen);//~vbm2R~
#ifndef JJJ                                                        //~vbm8I~
int  drawtextstr_NoLigatureu8_NoSCMSub(int Popt,CDC *Ppdc,GdkGC *Ppgc,int Px,int Py,GdkColor *Ppfg,GdkColor *Ppbg,//~vbm8R~
		char *Ppu8,int Pu8len,char *Pdddata,char *Pdddbcs,char *Plcdbcs,int Pddlen);//~vbm8I~
#endif                                                             //~vbm8I~
int  drawtextstr_NoLigatureu8_NoSCM_Monospace(int Popt,CDC *Ppdc,GdkGC *Ppgc,int Px,int Py,GdkColor *Ppfg,GdkColor *Ppbg,//~vbmaI~
		char *Ppu8,int Pu8len,char *Pdddata,char *Pdddbcs,char *Plcdbcs,int Pddlen);//~vbmaI~
int drawtextstr_ligatureu8_chkcombinesplit(int Popt,CDC *Ppdc,GdkGC *Ppgc,int Px,int Py,GdkColor *Ppfg,GdkColor *Ppbg,char *Ppu8,int Pu8len,char *Pdddata,char *Pdddbcs,char *Plcdbcs,int Pddlen);//~vbmcI~
static GdkColor SfgPadding={0,0/*r*/,0xffff/*g*/,0/*b*/};          //~vbA3R~
int drawSplitCombineNoLigature(int Popt,CDC *Ppdc,GdkGC *Ppgc,int Px,int Py,GdkColor *Ppfg,GdkColor *Ppbg,char *Ppu8,int Pu8len);//~vbAhR~
int drawSplitCombineLigature(int Popt,CDC *Ppdc,GdkGC *Ppgc,int Px,int Py,GdkColor *Ppfg,GdkColor *Ppbg,char *Ppu8,int Pu8len,char *Plcdbcs,int Plclen);//~vbAhR~
#ifndef RRR                                                        //~vbAjM~
void getPosEOL(int Popt,int Prow,int Plen);                        //~vbAjR~
static int SposEOL[2];                                             //~vbAjR~
static int SposVsplit;                                             //~vbAjI~
static int ScolExpandLigatureEOL;                                  //~vbAjI~
int chkLigatureExpand(int Popt,int Pcol,int Plen);                 //~vbAjR~
#endif                                                             //~vbAjI~
#ifndef KKK                                                        //~v7f4I~
#ifdef AAA                                                         //~v7f4I~
int getFormatAltcharZWJZWNJ(int Popt,char *Ppu8,int Pu8len);       //~v7f4I~
#else                                                              //~v7f4I~
int getFormatAltcharZWJZWNJ(int Popt,int Pucs);                    //~v7f4I~
#endif                                                             //~v7f4I~
#endif                                                             //~v7f4I~
int getUcsAltchar(int Popt,int Pucs);                              //~v7f4I~
static int SxxVhexDataCpos;                                        //~vbDsI~
int setAltchDD(int Popt,char *Ppdddata,char *Ppdddbcs,int Pddlen); //~v7fzR~
#define  SADO_VLEFT   0x01                                         //~v7fzI~
//===============================================================================//~vXXEI~
//                                                                 //~v003I~
//===============================================================================//~v003I~
void  xxemain_scrinit(void)                                        //~vXXER~
{                                                                  //~v003I~
    int ww,hh;                                                     //~vXXEI~
#if GTK_CHECK_VERSION(3,22,0)	//gtk_ui_manager was deprecated    //~vb7tI~
#else                                                              //~vb7tI~
    GdkScreen *psc;                                                //~vXXEI~
#endif                                                             //~vb7tI~
    GdkGCValues gcvalue;                                           //~v73tI~
#if GTK_CHECK_VERSION(3,22,0)	//gtk_ui_manager was deprecated    //~vb7tR~
    GdkDisplay *pdisp;                                             //~vb7tR~
    GdkMonitor *pmon;                                              //~vb7tR~
    GdkRectangle rect;                                             //~vb7tR~
#endif                                                             //~vb7tR~
//************************************                             //~v003I~
    dprintf("xxemain_scrinit\n");                                  //~var8R~
#if GTK_CHECK_VERSION(3,22,0)	//gtk_ui_manager was deprecated    //~vb7tM~
    pdisp=gdk_display_get_default();                               //~vb7tM~
    dprintf("xxemain_scrinit monitor n=%d\n",gdk_display_get_n_monitors(pdisp));//~vb7tM~
    dprintf("xxemain_scrinit get monitor 0=%p\n",gdk_display_get_monitor(pdisp,0));//~vb7tM~
    dprintf("xxemain_scrinit get monitor 1=%p\n",gdk_display_get_monitor(pdisp,1));//~vb7tM~
    dprintf("xxemain_scrinit get monitor at window=%p\n",gdk_display_get_monitor_at_window(pdisp,gtk_widget_get_window(Gpview)));//~vb7tM~
    dprintf("xxemain_scrinit get monitor at point=%p\n",gdk_display_get_monitor_at_point(pdisp,0,0));//~vb7tM~
    dprintf("xxemain_scrinit get monitor primaru=%p\n",gdk_display_get_primary_monitor(pdisp));//~vb7tM~
    pmon=gdk_display_get_monitor_at_window(pdisp,gtk_widget_get_window(Gpview));//~vb7tM~
    gdk_monitor_get_geometry(pmon,&rect);                          //~vb7tM~
	Mwinextw=rect.width;    //application pixel                    //~vb7tM~
	Mwinexth=rect.height;                                          //~vb7tM~
    dprintf("xxemain_scrinit monitor w=%d,h=%d\n",Mwinextw,Mwinexth);//~vb7tM~
#else                                                              //~vb7tM~
    psc=gdk_screen_get_default();                                  //~vXXER~
	Mwinextw=gdk_screen_get_width(psc);		//physical screen size by pixel//~vXXEI~
	Mwinexth=gdk_screen_get_height(psc);                           //~vXXEI~
    UTRACEP("xxemain_scrinit default scr=%p,w=%d,h=%d\n",psc,Mwinextw,Mwinexth);//~var8R~
#endif                                                             //~vb7tM~
#ifndef OPTGTK3                                                    //~var8R~
    Mscrwidth=ww=Gpview->allocation.width;                         //~vXXER~
    Mscrheight=hh=Gpview->allocation.height;                       //~vXXER~
#else                                                              //~var8R~
	csub_get_widget_allocation_wh(Gpview,&ww,&hh);                 //~var8R~
    Mscrwidth=ww;                                                  //~var8R~
    Mscrheight=hh;                                                 //~var8R~
    UTRACEP("%s:xxemain_scrinit Gpview=%p w=%d,h=%d\n",UTT,Gpview,Mscrwidth,Mscrheight);//~var8R~//~vbAfR~
#endif                                                             //~var8R~
    UTRACEP("%s:scrinit pixmap(view alloc) w=%d,h=%d\n",UTT,ww,hh);                          //~vX03R~//~vamrR~//~vbAfR~
#ifndef OPTGTK3                                                    //~var8R~
    Gppixmap=gdk_pixmap_new(Gpview->window,ww,hh,-1);              //~vXXER~
#else                                                              //~var8R~
    Gppixmap=csub_pixmap_new(Gpview,ww,hh,-1);                     //~var8R~
#endif                                                             //~var8R~
#ifndef OPTGTK3                                                    //~var8R~
    Gpgc=gdk_gc_new(Gpview->window);                               //~vXXEI~
#else                                                              //~var8R~
    Gpgc=csub_gc_new_pixmap(Gpview,Gppixmap);                      //~var8R~
#endif                                                             //~var8R~
//color                                                            //~vXXEI~
#if GTK_CHECK_VERSION(3,22,0)	//gtk_ui_manager was deprecated    //~vb7tR~
//gxe.h:	#define gdk_colormap_get_system  gdk_visual_get_system //~vb7tR~
    Gpcolormap=gdk_screen_get_system_visual(gdk_screen_get_default());	//pcm:GdkVisual by gxe.h//~vb7tR~
#else    	                                                       //~vb7tR~
    Gpcolormap=gdk_colormap_get_system();                          //~vXXEI~
#endif                                                             //~vb7tR~
    gdk_colormap_alloc_color(Gpcolormap,&(Gcolordata.CDcolor),FALSE,TRUE);//writeable?,bestmatch?//~vXXER~
    Gcolordata.CDstatus=CDST_PIXEL;     //alloc end                //~vXXEI~
//setup for ruler                                                  //~v73tI~
	Grulerfg.red=Mrulercolor.red;                                  //~v73tI~
	Grulerfg.green=Mrulercolor.green;                              //~v73tI~
	Grulerfg.blue=Mrulercolor.blue;                                //~v73tI~
    gdk_colormap_alloc_color(Gpcolormap,&Grulerfg,FALSE,TRUE);//writeable?,bestmatch?//~v73tI~
	gcvalue.line_width=1;                                          //~v73tI~
	gcvalue.line_style=GDK_LINE_SOLID;                             //~v73tI~
	gcvalue.foreground=Grulerfg;                                   //~v73tR~
#ifndef OPTGTK3                                                    //~var8R~
    Gpgcruler=gdk_gc_new_with_values(Gpview->window,&gcvalue,GDK_GC_FOREGROUND|GDK_GC_LINE_WIDTH|GDK_GC_LINE_STYLE);//~v73tI~
#else                                                              //~var8R~
    Gpgcruler=csub_gdk_gc_new_with_values(Gpview,&gcvalue,GDK_GC_FOREGROUND|GDK_GC_LINE_WIDTH|GDK_GC_LINE_STYLE);//~var8R~
#endif                                                             //~var8R~
//color for hcopy                                                  //~vXXER~
#ifndef OPTGTK3                                                    //~var8R~
    Gpprtgc=gdk_gc_new(Gpview->window);                            //~vXXER~
#else                                                              //~var8R~
    Gpprtgc=csub_gc_new_pixmap(Gpview,csub_pixmap_new(Gpview,Mscrwidth,Mscrheight,-1));//for prtscr//~var8R~
#endif                                                             //~var8R~
    gdk_colormap_alloc_color(Gpcolormap,&Gprintbg,FALSE,TRUE);//writeable?,bestmatch?//~vXXEI~
    gdk_colormap_alloc_color(Gpcolormap,&Gprintfg,FALSE,TRUE);//writeable?,bestmatch?//~vXXEI~
    gdk_colormap_alloc_color(Gpcolormap,&Gpreviewbg,FALSE,TRUE);//writeable?,bestmatch?//~vXXEI~
    gdk_gc_set_foreground(Gpprtgc,&Gprintfg);                      //~vXXER~
    gdk_gc_set_background(Gpprtgc,&Gprintbg);                      //~vXXER~
//cursor                                                           //~vXXEI~
#ifndef OPTGTK3                                                    //~var8R~
    Gpgccsr=gdk_gc_new(Gpview->window);                            //~vXXEI~
#else                                                              //~var8R~
    Gpgccsr=csub_gc_new(Gpview);                                   //~var8R~
#endif                                                             //~var8R~
    gdk_colormap_alloc_color(Gpcolormap,&Gcsrcolor,FALSE,TRUE);//writeable?,bestmatch?//~vXXER~
    gdk_colormap_alloc_color(Gpcolormap,&GcsrcolorBox,FALSE,TRUE); //fill pixel field//~vbzbR~
//  gdk_gc_set_foreground(Gpgccsr,&Gcsrcolor);                     //~vXXER~//~vbz9R~//~vbzbR~
    gdk_gc_set_foreground(Gpgccsr,&GcsrcolorBox);                  //~vbzbI~
  	gdk_gc_set_function(Gpgccsr,GDK_INVERT /*GDK_XOR GDK_COPY*/);//-->csub  //~vXXER~
//im preedit                                                       //~vXXEI~
#ifndef OPTGTK3                                                    //~var8R~
    Gpgcim=gdk_gc_new(Gpview->window);                             //~vXXEI~
    gdk_colormap_alloc_color(Gpcolormap,&Gimbgcolor,FALSE,TRUE);//writeable?,bestmatch?//~vXXEI~
    gdk_colormap_alloc_color(Gpcolormap,&Gimfgcolor,FALSE,TRUE);//writeable?,bestmatch?//~vXXEI~
	gdk_gc_set_line_attributes(Gpgcim,1,      //line width         //~vXXEI~
    	GDK_LINE_SOLID,GDK_CAP_NOT_LAST,GDK_JOIN_MITER);           //~vXXEI~
#endif                                                             //~var8R~
    xxemain_scrbgrect();                                           //~vXXER~
    csubinit3();                                                   //~vbz5I~
	return;                                                        //~v003I~
}//scrinit                                                         //~v003I~
#ifndef OPTGTK3                                                    //~var8R~
#else                                                              //~var8R~
//===============================================================================//~var8R~
//im preedit                                                       //~var8R~
//===============================================================================//~var8R~
void im_gcinit()                                                   //~var8R~
{                                                                  //~var8R~
    dprintf("im_gcinit Gpgcim=%p,pixmap=%p,ref=%d\n",Gpgcim,Gppixmap,cairo_surface_get_reference_count(Gppixmap));//~var8R~
    Gpgcim=csub_gc_new_pixmap(Gpview,Gppixmap);                    //~var8R~
	csub_gdk_gc_set_line_attributes(Gpgcim,1,      //line width    //~var8R~
    	GDK_LINE_SOLID,GDK_CAP_NOT_LAST,GDK_JOIN_MITER);           //~var8R~
    dprintf("im_gcinit Gpgcim=%p,pixmap=%p,ref=%d\n",Gpgcim,Gppixmap,cairo_surface_get_reference_count(Gppixmap));//~var8R~
}                                                                  //~var8R~
#endif                                                             //~var8R~
//===============================================================================//~2908I~
//                                                                 //~2908I~
//===============================================================================//~2908I~
void  xxemain_scronok(int Pcpchngsw)                               //~vXXER~
{                                                                  //~2908I~
    Mscrcmaxrow=ROWCTR(Mscrheight);                                //~2908I~
    Mscrcmaxcol=COLCTR(Mscrwidth);                                 //~2908I~
    Mwxeintf.WXEIcsrchangesw=1;	//recreate caret                   //~2914I~
#ifndef XXE                                                        //~vXXEI~
    createfont();                                                  //~2A23M~
#endif                                                             //~vXXEI~
//  OnSize(0,Mscrwidth,Mscrheight); 	//ajust row/col ctr and resize//~vXXER~
	dprintf("%s:Mscrcmaxrow=%d,Mscrcmaxcol=%d,MscrHeight=%d,Mscrwidth=%d\n",UTT,Mscrcmaxrow,Mscrcmaxcol,Mscrheight,Mscrwidth);//~vbAfI~
    xxemain_OnSize(Mscrwidth,Mscrheight); 	//ajust row/col ctr and resize//~vXXEI~
//  wxe_onsize(Mscrcmaxrow,Mscrcmaxcol,Pcpchngsw);	//init         //~2A23R~
//  scrbgrect(Mpmemdc);                                            //~2A23R~
//  Mfulldrawsw=1;                                                 //~2A23R~
//  scrinvalidate();                                               //~2A23R~
	return;                                                        //~2908I~
}//scronok                                                         //~2928R~
//===============================================================================//~2908I~
//draw background rectangle                                        //~2908I~
//===============================================================================//~2908I~
void  xxemain_scrbgrect(void)                                      //~vXXER~
{                                                                  //~2908I~
    int hh,ww;                                                     //~vXXEI~
//************************************                             //~vXXER~
#ifndef OPTGTK3                                                    //~var8R~
    ww=Gpview->allocation.width;                                   //~vXXEI~
    hh=Gpview->allocation.height;                                  //~vXXEI~
#else                                                              //~var8R~
	csub_get_widget_allocation_wh(Gpview,&ww,&hh);                 //~var8R~
#endif                                                             //~var8R~
  	UTRACEP("%s:main scrbgrect allocationwh,w=%d,h=%d,status=%d\n",UTT,ww,hh,Gcolordata.CDstatus);//~vX03R~//~vbAfR~
#ifndef OPTGTK3                                                    //~var8R~
    if (Gcolordata.CDstatus!=CDST_PIXEL)     //alloc end           //~vXXEI~
    {                                                              //~vXXEI~
    	if (Gcolordata.CDstatus==CDST_RGB)     //valid rgb set     //~vXXEI~
//	    	gdk_color_alloc(Gpcolormap,&(Gcolordata.CDcolor));     //~v73tR~
  	    	gdk_colormap_alloc_color(Gpcolormap,&(Gcolordata.CDcolor),FALSE,TRUE);//gdk_alloc_color deplicated//~v73tI~
        else                                                       //~vXXEI~
	        return;     //not yet initialize Gpcolormap            //~vXXER~
    }                                                              //~vXXEI~
#endif                                                             //~var8R~
    UTRACEP("%s:color %x=(%x,%x,%x)\n",UTT,Gcolordata.CDcolor.pixel,Gcolordata.CDcolor.red,Gcolordata.CDcolor.green,Gcolordata.CDcolor.blue);//~var8R~//~vbz9R~
//  Gcolordata.CDstatus=CDST_PIXEL;     //alloc end                //~vXXER~
//  dprintf("xxemain_scrbgrect surface=%p ref=%d\n",Gppixmap,cairo_surface_get_reference_count(Gppixmap));//~var8R~
    gdk_gc_set_foreground(Gpgc,&(Gcolordata.CDcolor));             //~vXXER~
//  gdk_gc_set_background(Gpgc,&(Gcolordata.CDcolor));             //~vXXER~
    gdk_draw_rectangle(Gppixmap,Gpgc,TRUE,0,0,ww,hh);              //~vXXEI~
    UTRACEP("%s: draw rect w=%d,h=%d\n",UTT,ww,hh);              //~var8R~//~vbz9R~
    gtk_widget_queue_draw_area(Gpview,0,0,ww,hh);                  //~vXXER~
	return;                                                        //~2908I~
}//xxemain_scrbgrect                                               //~vXXER~
//===============================================================================//~v003I~
//                                                                 //~v003I~
//===============================================================================//~v003I~
int  xxemain_OnSize(int Px,int Py)                                 //~vXXER~
{                                                                  //~v003I~
//    TEXTMETRIC tm;                                               //~vXXER~
//    CSize tl;                                                    //~vXXER~
//	WINDOWPLACEMENT wp;                                            //~vXXER~
#ifdef NOTRACE                                                     //~vbs1I~
#else                                                              //~vbs1I~
    int /*screxpandsw,*/ceilx,ceily;                               //~v69UR~
#endif    	                                                       //~vbs1I~
//************************************                             //~v003I~
    dprintf("%s:wxescr onsize x=%d,y=%d\n",UTT,Px,Py);                    //~vX03R~//~var8R~//~vbAfR~
    UTRACEP("%s:wxescr onsize x=%d,y=%d\n",UTT,Px,Py);             //~vbAfI~
    if (!Px || !Py)                                                //~2A23I~
		return 0;                                                  //~2A23I~
    Mscrheight=Py;                                                 //~2908R~
    Mscrwidth=Px;                                                  //~2908R~
#ifndef OPTGTK3                                                    //~var8R~
	if (Gppixmap)                                                  //~vXXEI~
		g_object_unref(Gppixmap);                                  //~vXXEI~
#endif                                                             //~var8R~
//    UTRACEP("wxescr_onsize before sleep\n");                     //~vam0R~
//    usleepms(100);    //milisec wait for Mxxemaininitsw          //~vam0R~
//    UTRACEP("wxescr_onsize after sleep\n");                      //~vam0R~
    if (!Mxxemaininitsw) //before xxemain init end                 //~vX03R~
        return 0;                                                  //~vX01I~
    UTRACEP("wxescr onsize after maininit w=%d,h=%d\n",Px,Py);     //~var8R~
#ifndef OPTGTK3                                                    //~var8R~
    Gppixmap=gdk_pixmap_new(Gpview->window,Px,Py,-1);              //~vXXER~
#else                                                              //~var8R~
    if (Gpgc)                                                      //~var8R~
    	csub_gc_destroy_pixmap(Gpgc,Gppixmap);  //destroy gc and pixmap//~var8R~
    Gppixmap=csub_pixmap_new(Gpview,Px,Py,-1);                     //~var8R~
    Gpgc=csub_gc_new_pixmap(Gpview,Gppixmap);//renewal surface_t of cairo_t to avoid use old destryed surface//~var8R~
//  Gplayout=pango_cairo_create_layout(Gpgc);    //FIXME @@@@test  //~var8R~
    UTRACEP("xxemain_onsize Gplayout=%p\n",Gplayout);              //~var8R~
	im_gcinit();                                                   //~var8R~
#endif                                                             //~var8R~
    Mscrcmaxrow=ROWCTR(Mscrheight);                                //~v003R~
    Mscrcmaxcol=COLCTR(Mscrwidth);                                 //~v003R~
#ifdef NOTRACE    	                                               //~vbs1I~
#else                                                              //~vbs1I~
    ceily=Py-CWINHEIGHT(Mscrcmaxrow);                              //~v69UR~
    ceilx=Px-CWINWIDTH(Mscrcmaxcol);                               //~v69UR~
UTRACEP("%s:maxcol=%d,maxrow=%d,ceilx=%d,ceily=%d,mcellw=%d,mcellh=%d\n",UTT,Mscrcmaxcol,Mscrcmaxrow,ceilx,ceily,Mcellw,Mcellh);//~var8R~//~vbAfR~
//dprintf("maxcol=%d,maxrow=%d,ceilx=%d,ceily=%d,mcellw=%d,mcellh=%d\n",Mscrcmaxcol,Mscrcmaxrow,ceilx,ceily,Mcellw,Mcellh);//~var8R~//~vbs1R~
#endif                                                             //~vbs1I~
    usetresizehint2(Px,Py,Mscrcmaxcol,Mscrcmaxrow);	               //~varcI~
	xxemain_scrbgrect();                                           //~vXXER~
//    if (!Mxeinitsw) //before xe init                             //~vX01R~
//        return 0;                                                //~vX01R~
    wxe_onsize(Mscrcmaxrow,Mscrcmaxcol,0);                         //~vXXEM~
    Mfulldrawsw=1;                                                 //~2914I~
    UTRACEP("%s:wxescr onsize req invalidate\n",UTT);                     //~vam0I~//~vbAfR~
	xxemain_scrinvalidate(0);                                      //~vXXER~
	return 1;                                                      //~v003R~
}//xxemain_OnSize                                                  //~vXXER~
//===============================================================================//~v003M~
//                                                                 //~v003M~
//===============================================================================//~v003M~
int  xxemain_draw(void)                                            //~vXXER~
{                                                                  //~v003M~
    char newpath[_MAX_PATH];                                       //~2922I~
    char newtitle[_MAX_PATH*2];                                    //~2922I~
//************************************                             //~v003M~
	if (!Mxeinitsw)		//xe init called                           //~2914I~
    	return 0;                                                  //~2914I~
    if (Mwxeintf.WXEIxetermsw)	//xe term called already           //~v55WR~
    	return 0;                                                  //~v55WR~
//  Mfulldrawsw=1;                                                 //~2914R~
    if (ugetcpath(newpath))    //current path changed              //~2922I~
    {                                                              //~2922I~
    	sprintf(newtitle,"%s    CWD=%s",WXE_TITLE,newpath);        //~2922R~
    	usettitle(newtitle);                                       //~vXXEI~
    }                                                              //~2922I~
    SfgPadding=*(Gxxepalette+UVIOM_PADATTR);                       //~vbA3R~
    UTRACEP("%s:SfgPadding=%s\n",UTT,COLOR2STRING(&SfgPadding));   //~vbA3R~
	xxemain_scrupdate(Gppixmap,0);                                 //~vXXER~
	updateFileMenu(0);                                             //~vbdnR~
	return 0;                                                      //~v003M~
}//draw                                                            //~v003M~
//===============================================================================//~v003I~
//                                                                 //~v003I~
//===============================================================================//~v003I~
void xxemain_scrupdate(CDC *Ppdc,int Pprintsw)                     //~vXXER~
{                                                                  //~v003I~
//  int row,currow,redrawcsrsw=0;                                  //~v78DR~
    int row;                                                       //~v78DR~
    UCHAR *puf;                                                    //~v003R~
    int linectr;                                                   //~v69UR~
    int csrrow,csrcol,csrredrawreqcond;                            //~va30R~
    int csrdataline=-1,rc2,opt,opt0,fileinfo;                      //~va3bR~
//  char *pdbcs;                                                   //~va30R~//~vaa7R~
    int vhexpos;                                                   //~va3tI~
//************************************                             //~v003I~
	xxe_setsynpalettecolor();                                      //~v780I~
    puf=Mwxeintf.WXEIlineupdate;                                   //~v003R~
//  currow=Mwxeintf.WXEIcsrposy;                                   //~v78DR~
    csrrow=Mwxeintf.WXEIcsrposy;                                   //~va30R~
    csrcol=Mwxeintf.WXEIcsrposx;                                   //~va30R~
//  pdbcs=(char*)TEXTDBCS(csrrow,0);                               //~va30R~//~vaa7R~
//	scrrulererase(Mwxeintf.WXEIcsrposy,Mwxeintf.WXEIcsrposx);	//set redraw flag to erase prev line//~v78BR~
//  if (Mwxeintf.WXEIcsrmovesw & WXEICSR_CHANGEROW)                //~v78DR~
//  	puf[Mwxeintf.WXEIoldcsrposy]=1;	//redraw the old cursor line to clear old cursor//~v78DR~
//  if (Mwxeintf.WXEIcsrmovesw || Mwxeintf.WXEIcsrchangesw) //colomn change or ins/rep change//~v78DR~
//  	puf[currow]=1;	//redraw the current cursor line to clear old cursor type//~v78DR~
    dprintf("scrupdate hdrline print=%x\n",*puf);                  //~v69UR~
    UTRACED("drawlineflag",puf,Mscrcmaxrow);                       //~va6pI~
    linectr=0;                                                     //~v69UI~
//    csrredrawreqcond=(!Pprintsw                                    //~va30R~//~vamrR~
      csrredrawreqcond=(TRUE                                       //~vamrI~
//  					 && (Mlinedrawstat[csrrow] & (LDS_COMBINE|LDS_LIGATURE))//~va30R~
                     );//previously drawn combine char or ligature //~va30R~
	opt0=0;                                                        //~va3bI~
    if (csrredrawreqcond)                                          //~va3bR~
    {                                                              //~va3bR~
//  	rc2=xxe_chkcsrpos(XXECCPO_CSRLINEBREAK,csrrow,csrcol,&fileinfo);//csr is on text area?//~va3bR~//~vbDsR~
    	rc2=xxe_chkcsrpos(XXECCPO_CSRLINEBREAK|XXECCPO_NOT_RELATIVE,csrrow,csrcol,&fileinfo);//csr is on text area?//~vbDsI~
        if (rc2)	//csr is on data or vhex line                  //~va3bI~
        {                                                          //~va3bI~
	        if (fileinfo & XXECCPI_CPU8)                           //~va3bI~
            {                                                      //~va3bI~
                opt0|=LPO_CPU8;                                    //~va3bI~
                if (rc2>0)      //csr is on dataline               //~va3bR~
                    csrdataline=csrrow; //csr is on dataline       //~va3bR~
                //else;  data line is redrawn when csr is on vhex line for CPU8 file//~va3bI~
                else                                               //~va3tI~
                {                                                  //~va3tI~
                    if (fileinfo & XXECCPI_VHEXCSRPOS)   //vheccsrpos is returned//~va3tI~
                    {                                              //~va3tI~
						vhexpos=XXECCPI_GETVHEXCSR(fileinfo);      //~va3tI~
                    	csrdataline=csrrow+rc2; //draw dataline on csr corresponding to csr vhex line//~va3tI~
                        vhexpos<<=LPO_VHEXSHIFT;                   //~va3tI~
                		opt0|=LPO_VHEX|vhexpos;                    //~va3tI~
                    }                                              //~va3tI~
                }                                                  //~va3tI~
            }                                                      //~va3bI~
            else                                                   //~va3bI~
            {                                                      //~va3bI~
//              if (Mligature)  //allow ligature                   //~va3dR~
                if (Mligature^Mligaturereverse)  //allow ligature  //~va3dI~
                {                                                  //~va3bI~
                    if (rc2>0)      //csr is ondataline            //~va3bI~
                        csrdataline=csrrow; //csr is on dataline   //~va3bI~
                    else                                           //~va3bI~
                        csrdataline=csrrow+rc2; //draw dataline on csr corresponding to csr vhex line//~va3bI~
                }                                                  //~va3bI~
            }                                                      //~va3bI~
        }                                                          //~va3bI~
    }                                                              //~va3bR~
    for (row=0;row<Mscrcmaxrow;row++,puf++)                        //~v003R~
    {                                                              //~v003I~
UTRACEP("scrupdate row=%d,Mfulldrawsw=%d,puf=%x\n",row,Mfulldrawsw,*puf);//~va20I~
//  	if (Mfulldrawsw || *puf!=0)	//line updated                 //~va30R~
    	if (Mfulldrawsw	//full scr draw                            //~va30R~
    	||  *puf!=0	//line updated                                 //~va30R~
//  	||  (row==csrrow && csrredrawreqcond)                      //~va3bR~
    	||  (row==csrdataline)                                     //~va3bR~
        )                                                          //~va30R~
        {                                                          //~v003I~
//  		Mlinedrawstat[row]=LDS_DRAWN;    //once clear combine\/ligature flag//~va30R~
UTRACEP("*************lineput row=%d,csrdataline=%d,printsw=%d\n",row,csrdataline,Pprintsw);                      //~va3bR~//~vam7R~
//        	lineput(Ppdc,Pprintsw,row);                            //~va3bR~
			opt=opt0;                                              //~va3bI~
			if (row==csrdataline)                                  //~va3bR~
				opt|=LPO_CSRBREAK;	//strput split at csr pos      //~va3bR~
          	lineput(opt,Ppdc,Pprintsw,row);                        //~va3bR~
		    *puf=0;	//reset line updated                           //~v003I~
//      	if (row==currow)	//cursor line reddrawn	           //~v78DR~
//          	redrawcsrsw=1;                                     //~v78DR~
            linectr++;                                             //~v69UI~
        }                                                          //~v003I~
    }                                                              //~v003I~
//UTRACEP("@@@@ scrupdate line=%d\n",linectr);                     //~v69UR~
    if (!Pprintsw)                                                 //~2A27I~
    {                                                              //~v682I~
//      scrruler(Mwxeintf.WXEIcsrposy,Mwxeintf.WXEIcsrposx);       //~v78BR~
//    if (redrawcsrsw)                                             //~v78DR~
//      scrcsr();                                                  //~v78DR~
    	if (Mwxeintf.WXEIstatus & WXEIS_DRAWMENU)	//draw menu req by reset key//~v682I~
        {                                                          //~v682I~
    		Mwxeintf.WXEIstatus &=~WXEIS_DRAWMENU;	//processed    //~v682I~
    		gxemfrm_enabletoolbar(0);//toolbar icon enable/disable //~v682I~
        }                                                          //~v682I~
    }                                                              //~v682I~
    Mfulldrawsw=0;	//reset                                        //~2914R~
    return;                                                        //~v003I~
}//xxemain_scrupdate                                               //~vXXER~
//===============================================================================//~v73tI~
//draw cursor on widget directly                                   //~var8R~
//===============================================================================//~v73tI~
void  scrruler(int Prow,int Pcol)                                  //~v73tI~
{                                                                  //~v73tI~
    CPoint pt[2];                                                  //~v73tI~
	int xx,yy;                                                     //~v73tI~
//************************************                             //~v73tI~
//	if (Pcol && Mrulermode & WXERULER_V)	//vertical line        //~v78BR~
  	if (Mrulermode & WXERULER_V)	//vertical line                //~v78BI~
    {                                                              //~v73tI~
		xx=XX(Pcol)-1;                                             //~v73tI~
        if (xx<0)                                                  //~vaikI~
	        xx=0;                                                  //~vaikI~
    	pt[0].x=xx;                                                //~v73tI~
    	pt[1].x=xx;                                                //~v73tI~
    	pt[0].y=0;                                                 //~v73tI~
    	pt[1].y=Mscrheight;                                        //~v73tI~
//  	scrdrawline(pt);		//draw line                        //~v78BR~
#ifndef OPTGTK3                                                    //~var8R~
    	scrdrawline(Gpview->window,pt);		//draw line            //~v78BI~
#else                                                              //~var8R~
    	scrdrawline(GpgcOnDraw,pt);		//draw line                //~var8R~
#endif                                                             //~var8R~
	    Mrulercol=Pcol;                                            //~v73tI~
        Mrulermodeo|=WXERULER_V;                                   //~v73tI~
    }                                                              //~v73tI~
//  if (Prow && Mrulermode & WXERULER_H)	//horizontal           //~v78BR~
    if (Mrulermode & WXERULER_H)	//horizontal                   //~v78BI~
    {                                                              //~v73tI~
		yy=YY(Prow+1)-1;                                           //~v73tI~
    	pt[0].x=0;                                                 //~v73tI~
    	pt[1].x=Mscrwidth;                                         //~v73tI~
    	pt[0].y=yy;                                                //~v73tI~
    	pt[1].y=yy;                                                //~v73tI~
//  	scrdrawline(pt);		//draw line                        //~v78BR~
#ifndef OPTGTK3                                                    //~var8R~
    	scrdrawline(Gpview->window,pt);		//draw line            //~v78BI~
#else                                                              //~var8R~
    	scrdrawline(GpgcOnDraw,pt);		//draw line                //~var8R~
#endif                                                             //~var8R~
    	Mrulerrow=Prow;                                            //~v73tI~
        Mrulermodeo|=WXERULER_H;                                   //~v73tI~
    }                                                              //~v73tI~
    return;                                                        //~v73tI~
}//scrruler                                                        //~v73tI~
#ifdef AAA                                                         //~v78BI~
//===============================================================================//~v73tI~
//csr process                                                      //~v73tI~
//===============================================================================//~v73tI~
void  scrrulererase(int Prow,int Pcol)                             //~v73tI~
{                                                                  //~v73tI~
    UCHAR *puf;                                                    //~v73tI~
//************************************                             //~v73tI~
    if (Mrulermodeo & WXERULER_V)                                  //~v73tI~
    {                                                              //~v73tI~
    	Mfulldrawsw=1;                                             //~v73tI~
		Mrulermodeo&=~WXERULER_V;       //erased                   //~v73tI~
	}                                                              //~v73tI~
    else                                                           //~v73tI~
    if (Mrulermodeo & WXERULER_H && Mrulerrow!=0 && Mrulerrow!=Prow)    //col changed//~v73tI~
    {                                                              //~v73tI~
    	puf=Mwxeintf.WXEIlineupdate;                               //~v73tI~
        puf+=Mrulerrow;                                            //~v73tI~
        *puf=1;		//drw prev line to erase ruler for the case v-split screen//~v73tI~
		Mrulermodeo&=~WXERULER_H;                                  //~v73tI~
    }                                                              //~v73tI~
    return;                                                        //~v73tI~
}//scrruler                                                        //~v73tI~
#endif                                                             //~v78BI~
//===============================================================================//~v73tI~
//open by application                                              //~v73tI~
//===============================================================================//~v73tI~
int xxemain_scrsetruler(int Ptype)                                 //~v73tR~
{                                                                  //~v73tI~
//************************************                             //~v73tI~
    if (Ptype)                                                     //~v73tI~
    {                                                              //~v73tI~
    	if (Mrulermode==Ptype)                                     //~v73tI~
    		Mrulermode=0;                                          //~v73tI~
        else                                                       //~v73tI~
    		Mrulermode=Ptype;                                      //~v73tR~
    }                                                              //~v73tI~
    else                                                           //~v73tI~
    if (++Mrulermode>WXERULER_VH)                                  //~v73tI~
    	Mrulermode=WXERULER_NONE;                                  //~v73tI~
dprintf("setruler mode=%d\n",Mrulermode);                          //~v78BI~
    Mfulldrawsw=1;                                                 //~v73tI~
    xxemain_scrinvalidate(0);                                      //~v73tI~
    return Mrulermode;                                             //~v73tI~
}//scrsetruler                                                     //~v73tI~
//***************************************************************************//~v73tI~
//*linedraw                                                        //~v73tI~
//***************************************************************************//~v73tI~
//void scrdrawline(CPoint *Pppoint)                                //~v78BR~
#ifndef OPTGTK3                                                    //~var8R~
void scrdrawline(CDC *Pdc,CPoint *Pppoint)                         //~v78BI~
{                                                                  //~v73tI~
//*******************************                                  //~v73tI~
UTRACEP("%s:Not OPTGTK3 (%d,%d)->(%d,%d)\n",UTT,Pppoint->x,Pppoint->y,(Pppoint+1)->x,(Pppoint+1)->y);//~v73tI~//~vbz9R~
//  gdk_draw_line(Gppixmap,Gpgcruler,Pppoint->x,Pppoint->y,(Pppoint+1)->x,(Pppoint+1)->y);//~v78BR~
    gdk_draw_line(Pdc,Gpgcruler,Pppoint->x,Pppoint->y,(Pppoint+1)->x,(Pppoint+1)->y);//~v78BI~
    return;                                                        //~v73tI~
}//scrdrawline                                                     //~v73tI~
#else   //OPTGTK3                                                  //~var8R~
void scrdrawline(GdkGC *Ppgc,CPoint *Pppoint)                      //~var8R~
{                                                                  //~var8R~
//*******************************                                  //~var8R~
	UTRACEP("%s:OPTGTK3 (%d,%d)->(%d,%d)\n",UTT,Pppoint->x,Pppoint->y,(Pppoint+1)->x,(Pppoint+1)->y);//~var8R~//~vbz9R~
    csub_gdk_draw_line_direct(Ppgc/*cairo_t from draw signal*/,Gpgcruler,Pppoint->x,Pppoint->y,(Pppoint+1)->x,(Pppoint+1)->y);//~var8R~
    return;                                                        //~var8R~
}//scrdrawline                                                     //~var8R~
#endif                                                             //~var8R~
//===============================================================================//~2914I~
//draw cursor to window direct                                     //~var8R~
//===============================================================================//~2914I~
int  scrcsr(void)                                                  //~vXXER~
{                                                                  //~2914I~
	int rc=0;                                                      //~2914I~
//************************************                             //~2914I~
    if (Mwxeintf.WXEIcsrchangesw)                                  //~2914R~
    {                                                              //~2914I~
	    Mwxeintf.WXEIcsrchangesw=0;                                //~vXXEI~
//      rc+=usetcaret(Mwxeintf.WXEIcsrdbcssw,                      //~2915R~
        rc+=usetcaret( //for performance use sbcs csr always.      //~vXXER~
					Mwxeintf.WXEIcsrhstart,Mcellw,Mcellh,Mfontheight);//~2915I~
//      rc+=ushowcaret();   //duplicated req by csrmovesw on       //~vXXER~
    }                                                              //~2914I~
#ifndef XXE                                                        //~vXXEI~
    if (Mwxeintf.WXEIcsrvisiblechangesw)                           //~2914R~
    {                                                              //~2914I~
	    Mwxeintf.WXEIcsrvisiblechangesw=0;		//processed        //~2914M~
    	if (Mwxeintf.WXEIcsrvisible)                               //~2914R~
        	rc+=ushowcaret();	                                   //~2914R~
        else                                                       //~2914I~
        	rc+=uhidecaret();                                      //~2914R~
    }                                                              //~2914I~
#endif                                                             //~vXXEI~
    if (Mwxeintf.WXEIcsrmovesw)	//csr moved                        //~vXXER~
    {                                                              //~vXXER~
//  	Mwxeintf.WXEIcsrmovesw=0;	//processed                    //~va7DR~
		rc+=usetcaretpos(Mwxeintf.WXEIcsrposy,Mwxeintf.WXEIcsrposx);//~vXXER~
//      if (Mwxeintf.WXEIcsrmovesw & WXEICSR_CHANGEBYKBD)          //~va7DI~//~va7SR~
            mouse_csrmovedbykbd(0);        //update toolbar menu item//~va7DI~
    	Mwxeintf.WXEIcsrmovesw=0;	//processed                    //~va7DI~
    }                                                              //~vXXER~
    ushowcaret();                                                  //~vXXEI~
    return rc;                                                     //~2914I~
}//scrcsr                                                          //~2914I~
//===============================================================================//~v003I~
//1 line write                                                     //~v003I~
//===============================================================================//~v003I~
//int  lineput(CDC *Ppdc,int Pprintsw,int Prow)                    //~va3bR~
int  lineput(int Popt,CDC *Ppdc,int Pprintsw,int Prow)             //~va3bR~
{                                                                  //~v003I~
    USHORT *pattr,attr;                                            //~v003I~
    int col,totlen,len,colstart;                                   //~2A05R~
    int inboxswn,inboxsw;                                          //~2A05R~
    int nextcolstart;                                              //~v69SI~
//  CPoint pt1,pt2;                                                //~v780R~
    CPoint pt1={0,0},pt2={0,0};                                    //~v780I~
    char *pdbcs;                                                   //~v69SI~
    int dbcsctr=0,nextdbcsctr;                                     //~v69VI~
    char *pstyle,style;                                            //~v780I~
    int styleid,oldstyle=-1;                                       //~vaffR~
#ifdef UTF8SUPPH                                                   //~va1cR~
    char *pdbcs0;                                                  //~va1cR~
    int csrposbreaksw,csrpos,csrposnext,csrposprev;         //~va3bR~//~va30R~
    int vhexcol;                                                   //~va3tI~
#endif                                                             //~va1cR~
    int linenosz;                                                  //~vbm5I~
    int opt2;                                                      //~vbDsI~
    int colvhexdata=0;                                             //~vbDsI~
//************************************                             //~v003I~
	pattr=TEXTATTR(Prow,0);                                        //~2901R~
	pstyle=(char*)TEXTSTYLE(Prow,0);                               //~v780I~
    totlen=Mscrcmaxcol;                                            //~v003I~
 	UTRACEP("lineput opt=%x,row=%d\n",Popt,Prow);                  //~va3bR~
  	UTRACED("line data",TEXTDATA(Prow,0),totlen);                  //~v78DR~
  	UTRACED("line dbcs",TEXTDBCS(Prow,0),totlen);                  //~v78DR~
	UTRACED("line attr",TEXTATTR(Prow,0),totlen*2);                //~vb4rR~
	UTRACED("line style",pstyle,totlen);                           //~v780I~
#ifndef RRR                                                        //~vbAjI~
	ScolExpandLigatureEOL=0;                                       //~vbAjI~
#endif                                                             //~vbAjI~
    len=0;                                                         //~2901R~
    attr=*pattr;                                                   //~2901I~
    style=*pstyle;	//top byte may be set no use                   //~v780I~
    if (Mcpcopypansw)	//pan copy                                 //~2A05I~
    {                                                              //~2A05R~
        pt1=Mcellcopy1;                                            //~2A05R~
        pt2=Mcellcopy2;                                            //~2A05R~
        CAPGETBOX(pt1,pt2);  //get let top and right bottom        //~2A05R~
        inboxsw=CAPCHKINBOX(pt1,pt2,Prow,0);	//attr of col 0    //~2A05R~
    }                                                              //~2A05R~
    else                                                           //~2A05R~
        inboxsw=-1;     //id of line is out of range               //~2A05R~
    colstart=0;                                                    //~2A05I~
    pdbcs=(char*)TEXTDBCS(Prow,0);  //top of the line              //~v69SI~
#ifdef UTF8SUPPH                                                   //~va1cR~
	pdbcs0=pdbcs;                                                  //~va1cR~
//  csrposbreaksw=( (Prow==Mwxeintf.WXEIcsrposy)                   //~va3bR~
//  			&&	!Pprintsw                                      //~va3bR~
//                );                                               //~va3bR~
    csrposbreaksw=(Popt & LPO_CSRBREAK);                           //~va3bR~
	csrpos=-1;                                                     //~va30R~
    csrposnext=-1;				//for no combining case(CPLC)      //~va30R~
    csrposprev=-1;				//for no combining case(CPLC)      //~va30I~
    if (csrposbreaksw)          //also for CPLC for ligatutre chk  //~va30R~
    {                                                              //~va30R~
      if (Popt & LPO_VHEX)                                         //~va3tI~
      {                                                            //~va3tI~
        vhexcol=LPO_GETVHEXPOS(Popt);                              //~va3tI~
        UTRACEP("%s:vhexcol=%d\n",UTT,vhexcol);                    //~vbDpI~//~vbDsI~
		csubgetcsrposbf(UTFDDGSP_ALSOLOCAL,pdbcs,Mscrcmaxcol,vhexcol,&csrposprev,&csrpos,0/*next*/);//~va3tI~
        colvhexdata=csrpos;                                        //~vbDsI~
	  }                                                            //~va3tI~
      else                                                         //~va3tI~
      {                                                            //~vbDpI~//~vbDsI~
        UTRACEP("%s:WXEIcsrposx=%d\n",UTT,Mwxeintf.WXEIcsrposx);   //~vbDpI~//~vbDsI~
		csubgetcsrposbf(UTFDDGSP_ALSOLOCAL,pdbcs,Mscrcmaxcol,Mwxeintf.WXEIcsrposx,&csrposprev,&csrpos,&csrposnext);//~va3bR~//~va3dR~
      }                                                            //~vbDsI~
    }                                                              //~va30R~
UTRACEP("%s:csrpos sw=%d,b=%d,c=%d,a=%d,vhexcol=%d\n",UTT,csrposbreaksw,csrposprev,csrpos,csrposnext,vhexcol);//~va30I~//~vbAjR~//~vbDsR~
#endif                                                             //~va1cR~
#ifndef RRR                                                        //~vbAjI~
    memset(SposEOL,0,sizeof(SposEOL));                             //~vbAjR~
//  linenosz=xxe_getlinenosz(0,Prow,0);                            //~vbAjR~
	UTRACEP("%s:printsw=%d,csrbreaksw=%d,csrpos=%d\n",UTT,Pprintsw,csrposbreaksw,csrpos);//~vbAjR~
	if (!Pprintsw)                                                 //~vbAjI~
//      if (!csrposbreaksw || csrpos<linenosz)	//not cursor line or on lineno on csr line//~vbAjR~
        if (!csrposbreaksw)	//csr is ondata line part              //~vbAjI~
		    	getPosEOL(Popt,Prow,Mscrcmaxcol);                  //~vbAjI~
#endif                                                             //~vbAjI~
//  for (col=0;col<totlen;col++,pattr++,len++)                     //~v69SR~
//  for (col=0;col<totlen;col++,pattr++,pdbcs++)                   //~v780R~
    for (col=0;col<totlen;col++,pattr++,pdbcs++,pstyle++)          //~v780I~
    {                                                              //~v003I~
        if (inboxsw>=0)	//row is in the cap range                  //~2A05R~
            inboxswn=CAPCHKINBOX(pt1,pt2,Prow,col);                //~2A05R~
        else                                                       //~2A05R~
            inboxswn=-1;                                           //~2A05R~
	    linenosz=xxe_getlinenosz(0,Prow,col);                      //~vbm5I~
		UTRACEP("%s:col=%d,csrpos=%d,pattr=%p,*pattr=%04x\n",UTT,col,csrpos,pattr,*pattr);    //~vbDpR~//~vbDsI~
//      if (attr!=*pattr || inboxswn!=inboxsw)                     //~v780R~
        if (                                                       //~v780I~
			attr!=*pattr                                           //~v780I~
        ||  col==linenosz                                          //~vbm5I~
		||  (!Pprintsw && style!=*pstyle)                          //~v780I~
		||  (col==csrposprev||col==csrpos||col==csrposnext)	//to keep csr position char//~va3bR~
		|| inboxswn!=inboxsw                                       //~v780I~
        )                                                          //~v780I~
        {                                                          //~v003I~
        	nextdbcsctr=0;                                         //~v69VI~
#ifdef UTF8SUPPH                                                   //~va1cR~
            if (inboxswn==1 && inboxsw==0 && UDBCSCHK_DBCSNOT1ST(*pdbcs))//pad or 2nd//~va1cR~
	            nextcolstart=col+XESUB_DBCSSPLITCTR_R(pdbcs,totlen-col);//~va1cR~
#else                                                              //~va1cR~
            if (inboxswn==1 && inboxsw==0 && *pdbcs==UDBCSCHK_DBCS2ND)//left boundary split dbcs//~v69SI~
			                                                       //~va1cR~
	            nextcolstart=col+1;                                //~v69SI~
#endif                                                             //~va1cR~
            else                                                   //~v69SI~
#ifdef UTF8SUPPH                                                   //~va1cR~
            if (inboxswn==0 && inboxsw==1 && UDBCSCHK_DBCSNOT1ST(*pdbcs))//next is pad or end//~va1cR~
#else                                                              //~va1cR~
            if (inboxswn==0 && inboxsw==1 && *pdbcs==UDBCSCHK_DBCS2ND)//right boundary split dbcs//~v69SI~
#endif                                                             //~va1cR~
            {                                                      //~v69VI~
#ifdef UTF8SUPPH                                                   //~va1cR~
	            nextcolstart=col-XESUB_DBCSSPLITCTR_L(pdbcs0,col); //~va1cR~
#else                                                              //~va1cR~
	            nextcolstart=col-1;  //next start col by dbcs 1st  //~v69SI~
#endif                                                             //~va1cR~
                nextdbcsctr=1;                                     //~v69VI~
                dbcsctr--;		//process on top of next string    //~v69VI~
            }                                                      //~v69VI~
            else                                                   //~v69SI~
	            nextcolstart=col;  //next start col by dbcs 1st    //~v69SI~
            len=nextcolstart-colstart;                             //~v69SI~
            if (col && style==oldstyle)                            //~v780I~
                styleid=-1;                                        //~v780I~
            else                                                   //~v780I~
                styleid=style;                                     //~v780I~
UTRACEP("row=%d,colstart=%d,len=%d,attr=%x,inbox=%d,dbcsctr=%d\n",Prow,colstart,len,attr,inboxsw,dbcsctr);//~va1cR~
          if (len>0)                                               //~v69SI~
          {                                                        //~vbDsI~
            opt2=(colvhexdata && colvhexdata==colstart)?SPO_VHEXDATACPOS:0;//~vbDsR~
            UTRACEP("%s:colvhexdata=%d,colstart=%d,opt2=%02x\n",UTT,colvhexdata,colstart,opt2);//~vbDsI~
//          strput(Ppdc,Pprintsw,Prow,colstart,len,attr,inboxsw);  //~v69VR~
//          strput(Ppdc,Pprintsw,Prow,colstart,len,attr,inboxsw,dbcsctr);//~v780R~
//          strput(Ppdc,Pprintsw,Prow,colstart,len,attr,styleid,inboxsw,dbcsctr);//~v780R~//~vbDsR~
            strput(Ppdc,Pprintsw,Prow,colstart,len,attr,styleid,inboxsw,dbcsctr,opt2);//~vbDsI~
          }                                                        //~vbDsI~
        	attr=*pattr;                                           //~v003I~
            oldstyle=style;                                        //~v780I~
        	style=*pstyle;                                         //~v780I~
//          colstart=col;                                          //~v69SR~
            colstart=nextcolstart;                                 //~v69SI~
            inboxsw=inboxswn;                                      //~2A05R~
            len=0;                                                 //~v003I~
            dbcsctr=nextdbcsctr;                                   //~v69VI~
        }                                                          //~v003I~
#ifdef UTF8UCS2                                                    //~va20I~
        if (UDBCSCHK_DBCS1STLU(*pdbcs))                            //~va20I~
#else                                                              //~va20I~
        if (*pdbcs==UDBCSCHK_DBCS1ST)                              //~v69VI~
#endif                                                             //~va20I~
            dbcsctr++;                                             //~v69VI~
    }                                                              //~v003I~
    len=totlen-colstart;                                           //~v69SI~
UTRACEP("last str row=%d,colstart=%d,len=%d,dbcsctr=%d\n",Prow,colstart,len,dbcsctr);//~va20I~
    if (len)                                                       //~2901I~
    {                                                              //~vbDsI~
        opt2=(!colvhexdata && colvhexdata==colstart)?SPO_VHEXDATACPOS:0;//~vbDsI~
        UTRACEP("%s:colvhexdata=%d,colstart=%d,opt2=%02x\n",UTT,colvhexdata,colstart,opt2);//~vbDsI~
// 		strput(Ppdc,Pprintsw,Prow,colstart,len,attr,inboxsw);      //~v69VR~
// 		strput(Ppdc,Pprintsw,Prow,colstart,len,attr,inboxsw,dbcsctr);//~v780R~
// 		strput(Ppdc,Pprintsw,Prow,colstart,len,attr,style,inboxsw,dbcsctr);//~v780I~//~vbDsR~
 		strput(Ppdc,Pprintsw,Prow,colstart,len,attr,style,inboxsw,dbcsctr,opt2);//~vbDsI~
    }                                                              //~vbDsI~
//dprintf("endofstrput stype=%d\n",style);                         //~v78BR~
    if (style!=WXEFONTSTYLE_NOSYNTAX) //not syntax highlight part  //~v780I~
//  	xxemain_setfont(-1); 			//back to original         //~v780I~//~vameR~
    	xxemain_setfont(-1,Pprintsw); 			//back to original //~vameI~
    return 0;                                                      //~v003I~
}//lineput                                                         //~v003R~
//===============================================================================//~2901I~
//1 line write                                                     //~2901I~
//parm:capsw:-1:no cap line,0:cap line but out of range,1:str in cap range//~2A01I~
//===============================================================================//~2901I~
//int  strput(CDC *Ppdc,int Pprintsw,int Prow,int Pcol,int Plen,USHORT Pattr,int Pcapsw)//~v69VR~
//int  strput(CDC *Ppdc,int Pprintsw,int Prow,int Pcol,int Plen,USHORT Pattr,int Pcapsw,int Pdbcsctr)//~v780R~
//int  strput(CDC *Ppdc,int Pprintsw,int Prow,int Pcol,int Plen,USHORT Pattr,int Pstyle,int Pcapsw,int Pdbcsctr)//~v780I~//~vbDsR~
int  strput(CDC *Ppdc,int Pprintsw,int Prow,int Pcol,int Plen,USHORT Pattr,int Pstyle,int Pcapsw,int Pdbcsctr,int Popt2)//~vbDsI~
{                                                                  //~2901I~
    char   *pdata,*pdbcs/*,*pdatasbcs*/;                           //~vX03R~
    int  xx,yy,fgpal=0,bgpal=0;                                    //~vX03R~
    int ii/*,dbcssw*/;//sbcscnt,xxsbcs;                                //~vX03R~//~vaa7R~
#ifdef UTF8SUPPH                                                   //~vaa7I~
#else                                                              //~vaa7I~
    int dbcssw;                                                    //~vaa7I~
#endif                                                             //~vaa7I~
#define PANCOLAJUST 20                                             //~2A05R~
    RECT rect;                                                     //~2A05R~
#ifdef UTF8UCS2                                                    //~va20I~
    int swutf8data;                                                //~va20I~
    int opt;                                                       //~va3bI~
#endif                                                             //~va20I~
    int oldxx,localestrlen,dbcslen;                                //~vam7R~
    char *oldpdata;                                                //~vam7R~
    int lineopt;                                                   //~vb4rI~
//************************************                             //~2901I~
  	UTRACEP("%s:Popt2=%02x,row=%d,col=%d,Plen=%d,Pprintsw=%02x,Pattr=%04x\n",UTT,Popt2,Prow,Pcol,Plen,Pprintsw,Pattr);//~vbDsI~
  	lineopt=wxe_getlineopt(0,Prow,Pcol);                           //~vb4rI~
//  MAKE_TEXT_RECT(&rect,Prow,Pcol,Plen);                          //~vXXEI~//~vbAjI~
#ifndef RRR                                                        //~vbAjI~
    MAKE_TEXT_RECT(&rect,Prow,Pcol+ScolExpandLigatureEOL,Plen);    //~vbAjI~
  	UTRACEP("%s:Mcellw=%d,ScolExpandLigatureEOL=%d,rect.left=xx=%d\n",UTT,Mcellw,ScolExpandLigatureEOL,rect.left);//~vbAjI~
#else                                                              //~vbAjI~
    MAKE_TEXT_RECT(&rect,Prow,Pcol,Plen);                          //~vbAjI~
#endif                                                             //~vbAjI~
  	UTRACEP("%s:printsw=%d,preview=%d,row=%d,col=%d,len=%d,attr=%x,style=%x\n",UTT,Pprintsw,Mpreviewmode,Prow,Pcol,Plen,Pattr,Pstyle);//~va1cR~//~va30R~//~vam0R~//~vam4R~//~vbv4R~//~vbAjR~
#ifndef RRR                                                        //~vbAjI~
#endif                                                             //~vbAjI~
#ifndef GTKPRINT                                                   //~vamfI~
    if (Pprintsw)                                                  //~2A27M~
    {                                                              //~2A27I~
//      ;                                                          //~vXXEI~//~vameR~
		if (Pstyle>=0) 	//style changed                            //~vameI~
      		xxemain_setfont(Pstyle,Pprintsw);            //back to original//~vameI~
    }                                                              //~2A27I~
    else                                                           //~2A27I~
#endif                                                             //~vamfI~
    {                                                              //~2A27M~
UTRACEP("strput row=%d,col=%d,style=%d,len=%d\n",Prow,Pcol,Pstyle,Plen);//~v780I~
		if (Pstyle>=0) 	//style changed                            //~v780I~
//      	xxemain_setfont(Pstyle);            //back to original //~v780R~//~vameR~
        	xxemain_setfont(Pstyle,Pprintsw);            //back to original//~vameI~
        if (Pcapsw==1)                                             //~2A27R~
        {                                                          //~2A27R~
            bgpal=Pattr & 0x0f;                                    //~2A27R~
            fgpal=(Pattr>>4) & 0x0f;                               //~2A27R~
        }                                                          //~2A27R~
        else                                                       //~2A27R~
        {                                                          //~2A27R~
            fgpal=Pattr & 0x0f;                                    //~2A27R~
            bgpal=(Pattr>>4) & 0x0f;                               //~2A27R~
        }                                                          //~2A27R~
	  if (Pcapsw==1 || Pstyle==WXEFONTSTYLE_NOSYNTAX) //capcopy on pan or not syntax highlight part//~v780I~
      {                                                            //~v780I~
        //fgcolor=Mwxeintf.WXEIpalrgb[fgpal];                      //~v780I~
        //bgcolor=Mwxeintf.WXEIpalrgb[bgpal];                      //~v780I~
        ;                                                          //~v780I~
      }                                                            //~v780I~
      else                                                         //~v780I~
      {                                                            //~v780I~
        if (Mwxeintf.WXEIsynrgb[fgpal] & WXE_SYNTAXRGB)            //~v780R~
	        fgpal|=WXE_SYNTAXRGB;                                  //~v780R~
//      else                                                       //~v780I~
//          fgcolor=Mwxeintf.WXEIpalrgb[fgpal];                    //~v780I~
        if (Mwxeintf.WXEIsynrgb[bgpal] & WXE_SYNTAXRGB)            //~v780R~
	        bgpal|=WXE_SYNTAXRGB;                                  //~v780R~
//      else                                                       //~v780I~
//          bgcolor=Mwxeintf.WXEIpalrgb[bgpal];                    //~v780I~
      }                                                            //~v780I~
                                                                   //~2A27R~
//      if (!Pprintsw && Prow==Mscrcmaxrow-1) //last row           //~vXXER~
//          rect.bottom=Mscrheight;                                //~vXXER~
//      if (rect.right<Mscrwidth && rect.right+Mcellw>Mscrwidth)   //~vXXER~
//          rect.right+=Mscrwidth;                                 //~vXXER~
                                                                   //~vXXEI~
//  	setfgbgcolorfrompal(bgpal,fgpal);                          //~vXXER~
//      Ppmemdc->FillRect(&rect,&br);                              //~vXXER~
#ifdef GTKPRINT                                                    //~vamfR~
      if (!Pprintsw)                                               //~vamfI~
#endif                                                             //~vamfI~
#ifndef TEST                                                       //~vbz5I~
//    if ((Prow==2 && bgpal==7))                                   //~vbz5R~
//        UTRACEP("%s:row=%d,bg=%d\n",UTT,Prow,bgpal);             //~vbz5R~
//    else                                                         //~vbz5R~
//    if (Prow==2 && bgpal==7)                                     //~vbz5R~
//        rect.bottom-=8;                                          //~vbz5R~
//  if (Prow!=2)                                                   //~vbz5I~//~vbz9R~
//        if (Prow==2 && bgpal==7)                                 //~vbz9R~
//        {                                                        //~vbz9R~
//          scrdrawbrush(Ppdc,&rect,6);                            //~vbz9R~
//          bgpal=7;                                               //~vbz9R~
//        }                                                        //~vbz9R~
//        else                                                     //~vbz9R~
//    if (Prow==4)                                                 //~vbz9R~
//        UTRACEP("%s:row=%d,\n",UTT,Prow);                        //~vbz9R~
#endif                                                             //~vbz5I~
		scrdrawbrush(Ppdc,&rect,bgpal);                            //~vXXER~
//printf("strput bgpal=%x\n",bgpal);                               //~vXXER~
//      Ppmemdc->SetTextColor(fgcolor);                            //~vXXER~
//      Ppmemdc->SetBkColor(bgcolor);                              //~vXXER~
//  	setfgbgcolorfrompal(fgpal,bgpal);                          //~vXXER~
    }                                                              //~2A27M~
    pdata=(char*)TEXTDATA(Prow,Pcol);                              //~2901R~
    pdbcs=(char*)TEXTDBCS(Prow,Pcol);                              //~2901R~
    UTRACED("strput input",pdata,Plen);                            //~vam7I~
#ifdef UTF8UCS2                                                    //~va20I~
    swutf8data=csubchkdd(0,pdbcs,Plen)*SPO_DDFMT;                  //~va20I~
    UTRACEP("strput swutf8data=%d\n",swutf8data);                  //~vam0I~
//  if (swutf8data)                                                //~va30R~
//  	Mlinedrawstat[Prow]|=LDS_DDFMT;                            //~va30R~
#endif                                                             //~va20I~
//printf("strput row=%d,col=%d,len=%d,str=%s\n",Prow,Pcol,Plen,pdata);//~vXXER~
//printf("strput attr=%x,str=%s\n",Pattr,pdata);                   //~vXXER~
	xx=rect.left+Mfontoffsx;                                       //~vXXER~
	yy=rect.top+Mfontoffsy;                                        //~vXXER~
#ifdef GTKPRINT                                                    //~vamfI~
  if (TRUE)   //also for hcopy                                     //~vamfI~
#else                                                              //~vamfI~
  if (!Pprintsw || Mpreviewmode)//for performance put whole string to screen//~vX03R~
#endif                                                             //~vamfI~
  {                                                                //~va20I~
//	drawtextstr(Ppdc,Pprintsw,xx,yy,pdata,pdbcs,Plen,fgpal,bgpal);//var8//~var8R~
#ifdef UTF8UCS2                                                    //~va20I~
    opt=swutf8data|Pprintsw;                                       //~va3bI~
  if (lineopt & UVIOO_CSRPOSCHK)                                   //~vb4rI~
  {                                                                //~vb4rI~
    if (xxe_chkcsrpos(XXECCPO_STRCHK,Prow,Pcol,0/*fileinfo*/))//chk disable ligature for each str//~va3bI~
    	opt|=SPO_NOLIGATURE;                                       //~va3bR~
    opt|=Popt2; 	//SPO_VHEXDATACPOS                             //~vbDsI~
  }                                                                //~vb4rI~
//	drawtextstr(Ppdc,Pprintsw|swutf8data,xx,yy,pdata,pdbcs,Plen,fgpal,bgpal,Pdbcsctr);//~va30R~
//	drawtextstr(Ppdc,Pprintsw|swutf8data,xx,yy,pdata,pdbcs,Plen,fgpal,bgpal,Pdbcsctr,Prow);//~va30R~
//	drawtextstr(Ppdc,Pprintsw|swutf8data,xx,yy,pdata,pdbcs,Plen,fgpal,bgpal,Pdbcsctr,Prow,Pcol);//~va3bR~
//	drawtextstr(Ppdc,opt,xx,yy,pdata,pdbcs,Plen,fgpal,bgpal,Pdbcsctr,Prow,Pcol);//~vb4rR~
  	drawtextstr(lineopt,Ppdc,opt,xx,yy,pdata,pdbcs,Plen,fgpal,bgpal,Pdbcsctr,Prow,Pcol);//~vb4rI~
#else                                                              //~va20I~
  	drawtextstr(Ppdc,Pprintsw,xx,yy,pdata,pdbcs,Plen,fgpal,bgpal,Pdbcsctr);//var8//~var8R~
#endif                                                             //~va20I~
  }                                                                //~va20I~
  else	//scrprint to paper                                        //~vX03R~
#ifdef UTF8UCS2                                                    //~va20I~
  if (swutf8data)                                                  //~va20I~
  {                                                                //~va20I~
#ifndef NOPRINT                                                    //~vam0I~
	uprttextoutw(0,xx,yy,pdata,pdbcs,Plen);	//write dd string      //~va20I~
#else                                                              //~vam0I~
		;                                                          //~vam0I~
#endif                                                             //~vam0I~
  }                                                                //~va20I~
  else                                                             //~va20I~
#endif                                                             //~va20I~
//if (Mligature^Mligaturereverse)  //allow ligature                //~vb4rR~
  if (WXE_LIGATUREMODE(lineopt))  //allow ligature                 //~vb4rI~
  {                                                                //~vam7I~
    oldpdata=pdata;                                                //~vam7R~
    oldxx=xx;                                                      //~vam7I~
    for (ii=0;ii<Plen;ii++,pdata++,pdbcs++,xx+=Mcellw)             //~vam7I~
    {                                                              //~vam7I~
        if (!*pdata||*pdata==' ')                                  //~vam7R~
        {                                                          //~vam7I~
        	localestrlen=PTRDIFF(pdata,oldpdata);                  //~vam7I~
            if (localestrlen)                                      //~vam7I~
            {                                                      //~vam7I~
                UTRACEP("strput ligature null data pos=%d,xx=%d\n",ii,oldxx);//~vam7R~
                UTRACED("strput ligature oldpdata",oldpdata,localestrlen);//~vam7R~
				drawtext(Ppdc,Pprintsw,oldxx,yy,oldpdata,localestrlen,fgpal,bgpal);//~vam7I~
            }                                                      //~vam7I~
            *pdata=' ';                                            //~vam7I~
			drawtext(Ppdc,Pprintsw,xx,yy,pdata,1,fgpal,bgpal);     //~vam7I~
            oldpdata=pdata+1;                                      //~vam7R~
            oldxx=xx+Mcellw;                                       //~vam7I~
        }                                                          //~vam7I~
        if (*pdata>=0x80            //no ascii(for the case dbcs space rep char)//~vam7I~
        &&  *pdbcs==UDBCSCHK_DBCS1ST //require  full byte write for DBCS//~vam7I~
        &&  (ii+XESUB_DBCSSPLITCTR(pdbcs,Plen-ii,0))<=Plen)  //require  2byte write for DBCS//~vam7I~
        {                                                          //~vam7I~
//			drawtext(Ppdc,Pprintsw,xx,yy,pdata,2,fgpal,bgpal);     //~vam7I~
            dbcslen=XESUB_DBCSSPLITCTR(pdbcs,Plen-ii,0);           //~vam7I~
            pdata+=dbcslen-1;                                      //~vam7I~
            pdbcs+=dbcslen-1;                                      //~vam7I~
            xx+=Mcellw*(dbcslen-1);                                //~vam7I~
			continue;	//skip dbcs                                //~vam7I~
        }                                                          //~vam7I~
        else                                                       //~vam7I~
        if (UDBCSCHK_DBCSNOT1ST(*pdbcs))	//spli dbcs            //~vam7I~
        {                                                          //~vam7I~
//          continue;                                              //~vam7I~
        	localestrlen=PTRDIFF(pdata,oldpdata);                  //~vam7I~
            if (localestrlen)                                      //~vam7I~
            {                                                      //~vam7I~
                UTRACEP("strput ligature dbcssplit pos=%d,xx=%d\n",ii,oldxx);//~vam7I~
                UTRACED("strput ligature oldpdata",oldpdata,localestrlen);//~vam7R~
				drawtext(Ppdc,Pprintsw,oldxx,yy,oldpdata,localestrlen,fgpal,bgpal);//~vam7I~
            }                                                      //~vam7I~
			drawtext(Ppdc,Pprintsw,xx,yy,pdata,1,fgpal,bgpal);     //~vam7I~
            oldpdata=pdata+1;                                      //~vam7R~
            oldxx=xx+Mcellw;                                       //~vam7I~
        }                                                          //~vam7I~
        else	//ascii                                            //~vam7I~
        {                                                          //~vam7I~
//  		drawtext(Ppdc,Pprintsw,xx,yy,pdata,1,fgpal,bgpal);     //~vam7I~
            continue;                                              //~vam7I~
        }                                                          //~vam7I~
    }//for                                                         //~vam7I~
    localestrlen=PTRDIFF(pdata,oldpdata);                          //~vam7I~
    if (localestrlen)                                              //~vam7I~
    {                                                              //~vam7I~
        UTRACEP("strput ligature endofstr xx=%d\n",oldxx);         //~vam7I~
        UTRACED("strput ligature oldpdata",oldpdata,localestrlen); //~vam7R~
		drawtext(Ppdc,Pprintsw,oldxx,yy,oldpdata,localestrlen,fgpal,bgpal);//~vam7I~
    }                                                              //~vam7I~
  }                                                                //~vam7I~
  else                                                             //~vam7I~
  {                                                                //~vX03I~
#ifdef UTF8SUPPH                                                   //~vaa7I~
#else                                                              //~vaa7I~
    dbcssw=0;                                                      //~vXXEI~
#endif                                                             //~vaa7I~
    for (ii=0;ii<Plen;ii++,pdata++,pdbcs++,xx+=Mcellw)             //~vXXER~
    {                                                              //~2901I~
        if (!*pdata)                                               //~2901I~
            *pdata=' ';                                            //~vXXEI~
//      if (*pdbcs==UDBCSCHK_DBCS1ST && (ii+1)<Plen)  //require  2byte write for DBCS//~v79zR~
        if (*pdata>=0x80            //no ascii(for the case dbcs space rep char)//~v79zI~
#ifdef UTF8SUPPH                                                   //~va1cR~
//*not utf8 data                                                   //~va20I~
        &&  *pdbcs==UDBCSCHK_DBCS1ST //require  full byte write for DBCS//~va1cR~
        &&  (ii+XESUB_DBCSSPLITCTR(pdbcs,Plen-ii,0))<=Plen)  //require  2byte write for DBCS//~va1cR~
#else                                                              //~va1cR~
        &&  *pdbcs==UDBCSCHK_DBCS1ST && (ii+1)<Plen)  //require  2byte write for DBCS//~v79zI~
#endif                                                             //~va1cR~
        {                                                          //~vXXEI~
			drawtext(Ppdc,Pprintsw,xx,yy,pdata,2,fgpal,bgpal);     //~vXXER~
#ifdef UTF8SUPPH                                                   //~vaa7I~
#else                                                              //~vaa7I~
            dbcssw=1;                                              //~vXXEI~
#endif                                                             //~vaa7I~
        }                                                          //~vXXEI~
        else                                                       //~2901I~
#ifdef UTF8SUPPH                                                   //~va1cR~
        if (UDBCSCHK_DBCSNOT1ST(*pdbcs))	//pad or 2nd           //~va1cR~
            continue;                                              //~va1cR~
#else                                                              //~va1cR~
        if (*pdbcs==UDBCSCHK_DBCS2ND)                              //~2901I~
        {                                                          //~vXXEI~
            if (dbcssw)                                            //~vXXEI~
            	continue;                                          //~vXXER~
			drawtext(Ppdc,Pprintsw,xx,yy,pdata,1,fgpal,bgpal);     //~vXXER~
        }                                                          //~vXXEI~
#endif                                                             //~va1cR~
        else                                                       //~2901I~
        {                                                          //~vXXEI~
#ifdef UTF8SUPPH                                                   //~vaa7I~
#else                                                              //~vaa7I~
        	dbcssw=0;                                              //~vXXEI~
#endif                                                             //~vaa7I~
			drawtext(Ppdc,Pprintsw,xx,yy,pdata,1,fgpal,bgpal);     //~vXXER~
        }                                                          //~vXXEI~
    }                                                              //~2901I~
  }//not monospace                                                 //~vX03R~
    return 0;                                                      //~2901I~
}//strput                                                          //~2901I~
#ifndef OPTGTK3                                                    //~var8R~
//===============================================================================//~vXXEI~
//draw text background rectangle                                   //~vXXEI~
//===============================================================================//~vXXEI~
void  setfgbgcolorfrompal(int Pfgpal,int Pbgpal)                   //~vXXER~
{                                                                  //~vXXEI~
	GdkColor *pfg,*pbg;                                            //~vXXEI~
//************************************                             //~vXXEI~
	pfg=Gxxepalette+Pfgpal;                                        //~vXXER~
    if (Pbgpal)                                                    //~vXXER~
		pbg=Gxxepalette+Pbgpal;                                    //~vXXER~
    else                                                           //~vXXEI~
	    pbg=&(Gcolordata.CDcolor);                                 //~vXXEI~
    gdk_gc_set_foreground(Gpgc,pfg);                               //~vXXEI~
    gdk_gc_set_background(Gpgc,pbg);                               //~vXXEI~
	return;                                                        //~vXXEI~
}//setfgbgcolorfrompal                                             //~vXXEI~
#endif                                                             //~var8R~
//===============================================================================//~vXXEI~
//draw background rectangle                                        //~vXXEI~
//===============================================================================//~vXXEI~
void  scrdrawbrush(CDC *Ppdc,PRECT Pprect,int Pbgpal)              //~vXXER~
{                                                                  //~vXXEI~
    int xx,yy,hh,ww;                                               //~vXXEI~
	GdkColor *pbg;                                                 //~vXXEI~
    GdkGC    *pgc;                                                 //~vXXEI~
//************************************                             //~vXXEI~
    pgc=Gpgc;                                                      //~vXXER~
    if (Pbgpal)                                                    //~vXXER~
        pbg=Gxxepalette+Pbgpal;                                    //~vXXER~
    else                                                           //~vXXER~
        pbg=&(Gcolordata.CDcolor);                                 //~vXXER~
//  gdk_gc_set_background(Gpgc,pbg);                               //~vXXER~
	gdk_gc_set_foreground(pgc,pbg);                                //~vXXER~
	xx=Pprect->left;                                               //~vXXEI~
	yy=Pprect->top;                                                //~vXXEI~
	ww=Pprect->right-xx;                                           //~vXXER~
	hh=Pprect->bottom-yy;                                          //~vXXER~
dprintf("scrdrawbrush xx=%d,yy=%d,ww=%d,hh=%d,bg=%x\n",xx,yy,ww,hh,Pbgpal);//~va1cR~
UTRACEP("%s: draw rect xx=%d,yy=%d,ww=%d,hh=%d,bg=%x\n",UTT,xx,yy,ww,hh,Pbgpal);//~var8R~//~vbz9R~
#ifndef TEST                                                       //~vbm5R~
  #ifndef TEST                                                     //~vbm5I~//~vbm8R~
    gdk_draw_rectangle(Ppdc,pgc,TRUE,xx,yy,ww,hh);                 //~vXXER~
  #else                                                            //~vbm5I~
    gdk_draw_rectangle(Ppdc,pgc,TRUE,xx,yy-2,ww,hh+2);             //~vbm5I~//~vbm8R~
  #endif                                                           //~vbm5I~
//    if (Pbgpal)                                                  //~vXXER~
//        {                                                        //~vXXER~
//            pbg=&(Gcolordata.CDcolor);                           //~vXXER~
//            gdk_gc_set_background(Gpgc,pbg);                     //~vXXER~
//        }                                                        //~vXXER~
#else                                                              //~vbm5R~
    pbg=Gxxepalette+3;                                             //~vbm5R~
	gdk_gc_set_foreground(pgc,pbg);                                //~vbm5I~
    gdk_draw_line(Ppdc,pgc,xx,yy,xx+ww,yy);                        //~vbm5R~
    pbg=Gxxepalette+6;                                             //~vbm5R~
	gdk_gc_set_foreground(pgc,pbg);                                //~vbm5I~
    gdk_draw_line(Ppdc,pgc,xx,yy+hh-2,xx+ww,yy+hh-2);              //~vbm5R~
UTRACEP("%s:test line\n",UTT);                                     //~vbm5I~
#endif                                                             //~vbm5I~
	return;                                                        //~vXXEI~
}//scrdrawbrush                                                    //~vXXER~
////===============================================================================//~vbz9R~
//void  xxescr_drawlayout(CDC *Ppdc,GdkGC *Ppgc,int Px,int Py,PangoLayout *Pplayout,GdkColor *Pfg,GdkColor *Pbg)//~vbz9R~
//{                                                                //~vbz9R~
//    UTRACEP("%s:x=%d,y=%d,fg=(%02x,%02x,%02x),bg=(%02x,%02x,%02x),text=%s\n",UTT,Px,Py,//~vbz9R~
//        Pfg->red,Pfg->green,Pfg->blue,Pbg->red,Pbg->green,Pbg->blue,//~vbz9R~
//        pango_layout_get_text(Pplayout));                        //~vbz9R~
//    gdk_draw_layout_with_colors(Ppdc,Ppgc,Px,Py,Pplayout,Pfg,Pbg);//~vbz9R~
//}                                                                //~vbz9R~
//===============================================================================//~vXXEI~
//draw a text char by utf8                                         //~vXXER~
//===============================================================================//~vXXEI~
void  drawtext(CDC *Ppdc,int Pprintsw,int Px,int Py,char *Ptext,int Plen,int Pfgpal,int Pbgpal)//~vXXER~
{                                                                  //~vXXEI~
//  GError *errpos=NULL;                                           //~v69sR~
	char *ptext;                                                   //~vXXEI~
    int /*readlen,*/writelen;                                      //~v69sR~
	GdkColor *pfg,*pbg;                                            //~vXXEI~
    GdkGC *pgc;                                                    //~vXXEI~
    int utfrc;                                                     //~v69VI~
#ifdef UTF8SUPPH                                                   //~vam4R~
    char *pdatascr,*pdbcsscr,*ptextscr;	//expanded  by "." insersion for SS3/GB4//~vam4R~
    USHORT *poffst;                                                //~vam4R~
    int writelenlc,slno,opt;                                       //~vam4R~
#endif                                                             //~vam4R~
//********************                                             //~vXXEI~
UTRACEP("%s:printsw=%d\n",UTT,Pprintsw);                         //~vam0R~//~vbz9R~
	if (Pprintsw)                                                  //~vXXEI~
    {                                                              //~vXXEI~
        pfg=&Gprintfg;                                             //~vXXEI~
        pbg=&Gprintbg;                                             //~vXXEI~
        pgc=Gpprtgc;                                               //~vXXER~
    }                                                              //~vXXEI~
    else                                                           //~vXXEI~
    {                                                              //~vXXEI~
	  if (Pfgpal & WXE_SYNTAXRGB)                                  //~v780I~
        pfg=Gxxesynpalette+(Pfgpal&0x0f);                          //~v780I~
      else                                                         //~v780I~
        pfg=Gxxepalette+Pfgpal;                                    //~vXXER~
	  if (Pbgpal & WXE_SYNTAXRGB)                                  //~v780I~
        pbg=Gxxesynpalette+(Pbgpal&0x0f);                          //~v780I~
      else                                                         //~v780I~
        if (Pbgpal)                                                //~vXXER~
            pbg=Gxxepalette+Pbgpal;                                //~vXXER~
        else                                                       //~vXXER~
            pbg=&(Gcolordata.CDcolor);                             //~vXXER~
        pgc=Gpgc;                                                  //~vXXEI~
    }                                                              //~vXXEI~
//  ptext=g_locale_to_utf8(Ptext,Plen,&readlen,&writelen,&errpos); //~v69sR~
//  PRINTGERR("drawtext g_locale_to_utf8",errpos);                 //~v69sR~
//  ptext=csublocale2utf8(Ptext,Plen,0,&writelen);                 //~v69VR~
UTRACED("drawtext",Ptext,Plen);                                    //~v69UR~
//  utfrc=csublocale2utf8(Ptext,Plen,0,&ptext,&writelen);          //~v79zR~
//  utfrc=csublocale2utf8(0/*SOURCE IS LOCALE MULTIBYTE*/,Ptext,Plen,0,&ptext,&writelen);//~v79QR~
#ifdef UTF8SUPPH                                                   //~vam4R~
	opt=CSL2UO_REP0a0d/*rep 0a 0d by ?*/;                          //~vam4R~
    utfrc=csublocale2utf8scr(opt,Ptext,NULL/*pdbcs*/,Plen,0/*preadlen*/,&ptextscr,&pdatascr,&pdbcsscr,&poffst,&writelen,&writelenlc,&slno);//apply altch for ctl char//~vam4R~//~vameR~
    ptext=ptextscr;                                                //~vam4R~
#else                                                              //~vam4R~
    utfrc=csublocale2utf8(CSL2UO_REP0a0d/*rep 0a 0d by ?*/,Ptext,Plen,0,&ptext,&writelen);//~v79QI~
#endif                                                             //~vam4R~
//  if (!ptext)                                                    //~v69VR~
	UTRACEP("drawtext csublocale2utf8 rc=%d,Mimageprtscr=%d\n",utfrc,Mimageprtscr);//~vam0I~
    if (utfrc>1)                                                   //~v69VI~
    	return;                                                    //~vXXEI~
    if (Pprintsw && !Mimageprtscr) //screen print by gnome_print   //~vXXEI~
    {                                                              //~vam0I~
#ifndef NOPRINT                                                    //~vam0I~
    	uprtscrtextout(ptext,Px,Py,writelen);                      //~vXXER~
#else                                                              //~vam0I~
		;                                                          //~vam0I~
#endif                                                             //~vam0I~
	}                                                              //~vam0I~
    else                                                           //~vXXER~
    {                                                              //~vXXER~
#ifndef OPTGTK3                                                    //~var8R~
#else   //OPTGTK3                                                  //~var8R~
        UTRACEP("%s:call csub_layout_set_textcolor fg=%s,bg=%s\n",UTT,csub_GdkColorToString(pfg),csub_GdkColorToString(pbg));//~vbzbI~
		csub_layout_set_textcolor(Gplayout,pfg,pbg);//setattr refresh layout lines//~var8R~
#endif                                                             //~var8R~
    	pango_layout_set_text(Gplayout,ptext,writelen);            //~vXXER~
UTRACEP("drawtext xx=%d,yy=%d,len=%d,bg=%x,fg=%x\n",Px,Py,writelen,Pbgpal,Pfgpal);//~v69UR~
//printf("fgcolor=%x=(%x,%x,%x,)\n",pfg->pixel,pfg->red,pfg->green,pfg->blue);//~vXXER~
    	gdk_draw_layout_with_colors(Ppdc,pgc,Px,Py,Gplayout,pfg,pbg);//~vXXER~//~vbz9R~
//  	xxescr_drawlayout(Ppdc,pgc,Px,Py,Gplayout,pfg,pbg);        //~vbz9R~
	}                                                              //~vXXEI~
//if (ptext!=Ptext)	//converted by csyblocale2utf8                 //~v69VR~
//if (!utfrc)      	//converted by csyblocale2utf8                 //~v79DR~
//  g_free(ptext);                                                 //~v79DR~
    return;                                                        //~vXXEI~
}//drawtext                                                        //~vXXER~
#ifdef AAA  //function moved to csub                               //~va42I~
//===============================================================================//~v79YI~
//replace unprintable                                              //~v79YI~
//===============================================================================//~v79YI~
void  drawrepunprintable(char *Ptext,char *Pdbcs,int Plen)         //~v79YI~
{                                                                  //~v79YI~
	UCHAR *pdata,*pdbcs;                                           //~v79YI~
    int ii,errrep='.';                                             //~v79YI~
//************************                                         //~v79YI~
    for (ii=0,pdata=Ptext,pdbcs=Pdbcs;ii<Plen;ii++,pdata++,pdbcs++)//~v79YI~
    {                                                              //~v79YI~
#ifdef UTF8SUPPH                                                   //~va1cR~
        if (UDBCSCHK_DBCSCOLS(*pdbcs))	//1st,pad,2nd              //~va1cR~
            continue;                                              //~va1cR~
#else                                                              //~va1cR~
        if (*pdbcs==UDBCSCHK_DBCS1ST)                              //~v79YI~
        {                                                          //~v79YI~
			pdata++;                                               //~v79YI~
            pdbcs++;                                               //~v79YI~
            ii++;                                                  //~v79YI~
            continue;                                              //~v79YI~
        }                                                          //~v79YI~
#endif                                                             //~va1cR~
        if (!*pdata)	//rep space at csublocale2utf8             //~v79YI~
            continue;                                              //~v79YI~
#ifdef UTF8SUPPH                                                   //~va0UI~
        if (Gpxxedbcstbl[*pdata]&UDBCSCHK_TYPEUNP)	//unprintable ascii//~va0UI~
#else                                                              //~va0UI~
        if (Gpdbcstbl[*pdata]&UDBCSCHK_TYPEUNP)	//unprintable ascii//~v79YR~
#endif                                                             //~va0UI~
        	*pdata=errrep;                                         //~v79YI~
    }                                                              //~v79YI~
}//drawrepunprintable                                              //~v79YI~
#endif                                                             //~va42I~
#ifdef UTF8UCS2                                                    //~va20I~
//===============================================================================//~va20I~
//RTL chk (unicode is right to left)                               //~va20I~
//===============================================================================//~va20I~
int drawtextstr_chkrtl(int Popt,char *Ppu8,int Pu8len)             //~va20R~
{                                                                  //~va20I~
#ifdef UTF8RTL                                                     //~va30I~
#ifndef  S390                                                      //~va30I~
	ULONG ucs;                                                     //~va20I~
    char *pu8;                                                     //~va20I~
    int reslen,chsz,dir,rc=0;                                      //~va20I~
//*****************                                                //~va20I~
    for (reslen=Pu8len,pu8=Ppu8;reslen>0;pu8+=chsz,reslen-=chsz)   //~va20I~
    {                                                              //~va20I~
		uccvutf2ucs(0,pu8,reslen,&ucs,&chsz);                      //~va20I~
        if (!chsz)                                                 //~va20I~
        	break;                                                 //~va20I~
        dir=pango_unichar_direction(ucs);                          //~va20I~
        if (dir==PANGO_DIRECTION_RTL)                              //~va20I~
        {                                                          //~va20I~
        	rc=1;                                                  //~va20I~
        	break;                                                 //~va20I~
        }                                                          //~va20I~
    }                                                              //~va20I~
UTRACEP("rtlchk rc=%d\n",rc);                                      //~va20I~
    return rc;                                                     //~va20I~
#else 	//S390                                                     //~va30I~
	return 0;                                                      //~va30I~
#endif	//S390                                                     //~va30I~
#else                                                              //~va30I~
	return 0;                                                      //~va30I~
#endif                                                             //~va30I~
}//drawtextstr_chkrtl                                              //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8SUPPH                                                   //~va1MR~
#ifdef GTKPRINT                                                    //~vamfI~
//===============================================================================
//draw textstring by utf8; 1 by 1 for ligature
//===============================================================================
int xxescr_chkligatureGtk(PangoLayout *Pplayout,char *Pdbcs,int Plclen)//~vamfR~
{
	int layoutinfo[CSUBLI_MAX],ii,dbcsctr,rc=0,glyphctr;
    char *pcd;
//***************
	UTRACED("xxescr_chkligatureGtk dbcs",Pdbcs,Plclen);            //~vamfR~
//  csublyoutinfo(0,Gplayout,layoutinfo);                          //~vamfR~
    csublyoutinfo(0,Pplayout,layoutinfo);                          //~vamfI~
	glyphctr=layoutinfo[CSUBLI_CTR];
    for (ii=0,dbcsctr=0,pcd=Pdbcs;ii<Plclen;ii++)
    {
    	if (*pcd++==UDBCSCHK_DBCS1ST)
        	dbcsctr++;
    }
    if (glyphctr<Plclen-dbcsctr)
    	rc=1;
    UTRACEP("%s rc=%d,lclen=%d,glyphctr=%d,dbcsctr=%d,layout=%p\n",UTT,rc,Plclen,glyphctr,dbcsctr,Pplayout);//~vamfR~//~vbk4R~
    return rc;
}//xxescr_chkligatureGtk                                           //~vamfR~
#endif	//!GTKPRINT                                                //~vamfM~
//===============================================================================//~va30R~
//draw textstring by utf8; 1 by 1 for ligature                     //~va30R~
//===============================================================================//~va30R~
//int xxescr_chkligature(char *Pdbcs,int Plclen)                     //~va30R~//~vbk6R~
int xxescr_chkligature(char *Pdbcs,int Plclen,int *Ppglyphctr,int *Ppucsctr)//~vbk6I~
{                                                                  //~va30R~
	int layoutinfo[CSUBLI_MAX],ii,dbcsctr,rc=0,glyphctr;           //~va30R~
    char *pcd;                                                     //~va30R~
//***************                                                  //~va30R~
	UTRACED("chkligature dbcs",Pdbcs,Plclen);                      //~va30R~
	csublyoutinfo(0,Gplayout,layoutinfo);                          //~va30R~
	glyphctr=layoutinfo[CSUBLI_CTR];                               //~va30R~
    for (ii=0,dbcsctr=0,pcd=Pdbcs;ii<Plclen;ii++)                  //~va30R~
    {                                                              //~va30R~
    	if (*pcd++==UDBCSCHK_DBCS1ST)                              //~va30R~
        	dbcsctr++;                                             //~va30R~
    }                                                              //~va30R~
    if (glyphctr<Plclen-dbcsctr)                                   //~va30R~
    	rc=1;                                                      //~va30R~
    if (Ppglyphctr)                                                //~vbk6R~
    	*Ppglyphctr=glyphctr;                                      //~vbk4M~//~vbk6R~
    if (Ppucsctr)                                                  //~vbk6I~
    	*Ppucsctr=Plclen-dbcsctr;                                  //~vbk6I~
    UTRACEP("%s: rc=%d,lclen=%d,glyphctr=%d,dbcsctr=%d,ucsctr=%d\n",UTT,rc,Plclen,glyphctr,dbcsctr,Plclen-dbcsctr);//~va30R~//~vbk4R~//~vbk6R~
    return rc;                                                     //~va30R~
}//xxescr_chkligature                                              //~va30R~
//===============================================================================//~vbmaI~
//chk ligature occured for utf8 file (glyphctr<ucsctr)             //~vbmaI~
//===============================================================================//~vbmaI~
int xxescr_chkligatureu8(char *Pdddata,char *Pdddbcs,int Pddlen,int *Ppglyphctr,int *Ppucsctr)//~vbmaI~
{                                                                  //~vbmaI~
	int layoutinfo[CSUBLI_MAX],ii,ucsctr=0,rc=0,glyphctr,chsz;     //~vbmaR~
    char *pc,*pcd;                                                 //~vbmaI~
//***************                                                  //~vbmaI~
	UTRACED("dddbcs",Pdddbcs,Pddlen);                              //~vbmaI~
	csublyoutinfo(0,Gplayout,layoutinfo);                          //~vbmaI~
	glyphctr=layoutinfo[CSUBLI_CTR];                               //~vbmaI~
    for (ii=0,pc=Pdddata,pcd=Pdddbcs;ii<Pddlen;ii+=chsz,pc+=chsz,pcd+=chsz)//~vbmaR~
    {                                                              //~vbmaI~
    	UTF_GETDDUCS1VIO(pc,pcd,Pddlen-ii,&chsz);                  //~vbmaR~
        ucsctr++;                                                  //~vbmaI~
    }                                                              //~vbmaI~
    if (glyphctr<ucsctr)                                           //~vbmaI~
    	rc=1;                                                      //~vbmaI~
    if (Ppglyphctr)                                                //~vbmaI~
    	*Ppglyphctr=glyphctr;                                      //~vbmaI~
    if (Ppucsctr)                                                  //~vbmaI~
    	*Ppucsctr=ucsctr;                                          //~vbmaI~
    UTRACEP("%s:rc=%d,glyphctr=%d,ucsctr=%d\n",UTT,rc,glyphctr,ucsctr);//~vbmaI~
    return rc;                                                     //~vbmaI~
}//xxescr_chkligatureu8                                            //~vbmaI~
#ifdef GTKPRINT                                                    //~vamfI~
//===============================================================================//~vamfI~
//draw hcopy print using cairo                                     //~vamfI~
//===============================================================================//~vamfI~
void                                                               //~vamfI~
xxescr_scrprtGtk(int Px,int Py,PangoLayout *Pplayout)              //~vamfI~
{                                                                  //~vamfI~
    cairo_t    *pcairocontext;                                     //~vamfI~
//******************************                                   //~vamfI~
	UTRACEP("xxescr_scrprtGtk x=%d,y=%d,layout=%p\n",Px,Py,Pplayout);//~vamfI~
	pcairocontext=gtk_print_context_get_cairo_context(Gpgtkprtctxt);//~vamfI~
	csub_setcolorGtk(pcairocontext);                               //~vam7I~
	cairo_move_to(pcairocontext,Px,Py);                            //~vamfI~
    pango_cairo_show_layout(pcairocontext,Pplayout);               //~vamfI~
}//xxescr_scrprtGtk                                                //~vamfI~
#endif //GTKPRINT                                                  //~vamfI~
#ifdef GTKPRINT                                                    //~vamfI~
//===============================================================================//~va1MR~
//draw textstring by utf8; 1 by 1 for ligature using gtk                      //~va1MR~//~vamfR~
//===============================================================================//~va1MR~
//void  drawtextstr_ligature(int Popt,CDC *Ppdc,GdkGC *Ppgc,int Px,int Py,GdkColor *Ppfg,GdkColor *Ppbg,char *Pptext,int Plenu8,char *Ppdata,char *Ppdbcs,int Plen)//~va20I~//~vamfR~
void  drawtextstr_ligatureGtk(int Popt,CDC *Ppdc,GdkGC *Ppgc,PangoLayout *Pplayout,int Px,int Py,GdkColor *Ppfg,GdkColor *Ppbg,char *Pptext,int Plenu8,char *Ppdata,char *Ppdbcs,int Plen)//~vamfR~
{                                                                  //~va1MR~
	char *ptext,*pdata,*pdbcs;                                     //~va1MR~
    int ii,chsz,xx=0,dbcssz;                                       //~vaffR~
    int accumctr=0,xx1=0;                                          //~vaffI~
    char wknonalpha[MAXCOL],*pc=wknonalpha,*pcd=NULL;//accum numeric(no ligature) write at once//~vaffI~
//*****************                                                //~va1MR~
UTRACED("drawtextstr_ligatureGtk Pptext",Pptext,Plenu8);                                      //~va1MR~//~vamfR~
UTRACED("plc",Ppdata,Plen);                                        //~va1MR~
UTRACED("pdbcs",Ppdbcs,Plen);                                      //~va1MR~
    for (ii=0,ptext=Pptext,pdata=Ppdata,pdbcs=Ppdbcs,xx=Px;        //~va1MR~
		ii<Plen;                                                   //~va1MR~
		ii++,ptext+=chsz,pdata+=dbcssz,pdbcs+=dbcssz,xx+=Mcellw)   //~va1MR~
    {                                                              //~va1MR~
    	if (*ptext<'A')	//no ligature may occur                    //~va3bI~
        {                                                          //~va3bI~
        	dbcssz=1;                                              //~va3bI~
            chsz=1;                                                //~va3bI~
            *pc++=*ptext;	//                                     //~va3bI~
            if (!accumctr)	//top                                  //~va3bI~
            {                                                      //~va3bI~
            	pcd=pdbcs;                                         //~va3bI~
                xx1=xx;                                            //~va3bI~
            }                                                      //~va3bI~
            accumctr++;                                            //~va3bI~
            continue;                                              //~va3bI~
        }                                                          //~va3bI~
        if (accumctr)                                              //~va3bI~
        {                                                          //~va3bI~
        	pc=wknonalpha;                                         //~va3bI~
//      	pango_layout_set_text(Gplayout,pc,accumctr);           //~va3bI~//~vamfR~
        	pango_layout_set_text(Pplayout,pc,accumctr);           //~vamfI~
// 			usetmonospace(Popt,Gplayout,pc,pcd,accumctr,Mcellw);   //~va3bI~//~vamfR~
  			usetmonospace(Popt,Pplayout,pc,pcd,accumctr,Mcellw);   //~vamfI~
UTRACED("drawtextstr_ligature nonalpha",pc,accumctr);              //~va3bI~
//    		gdk_draw_layout_with_colors(Ppdc,Ppgc,xx1,Py,Gplayout,Ppfg,Ppbg);//~va3bI~//~vamfR~
	        xxescr_scrprtGtk(xx1,Py,Pplayout);                     //~vamfI~
            accumctr=0;                                            //~va3bI~
        }                                                          //~va3bI~
    	chsz=UTF8CHARLENERR1(*ptext);                              //~va1MR~
//*after converted dd dbcs to locale dbcs                          //~va20I~
        if (*pdbcs==UDBCSCHK_DBCS1ST) //require  full byte write for DBCS//~va1MR~
        	dbcssz=XESUB_DBCSSPLITCTR(pdbcs,Plen-ii,0);            //~va1MR~
        else                                                       //~va1MR~
        	dbcssz=1;                                              //~va1MR~
//  	pango_layout_set_text(Gplayout,ptext,chsz);                //~va1MR~//~vamfR~
    	pango_layout_set_text(Pplayout,ptext,chsz);                //~vamfI~
//		usetmonospace(Popt,Gplayout,pdata,pdbcs,dbcssz,Mcellw);    //~va20I~//~vamfR~
  		usetmonospace(Popt,Pplayout,pdata,pdbcs,dbcssz,Mcellw);    //~vamfI~
UTRACEP("drawtextstr_ligature utf8 ii=%d,dbcssz=%d\n",ii,dbcssz);  //~va1MR~
UTRACED("drawtextstr_ligature utf8",ptext,chsz);                   //~va1MR~
UTRACED("drawtextstr_ligature lc  ",pdata,dbcssz);                 //~va1MR~
//  	gdk_draw_layout_with_colors(Ppdc,Ppgc,xx,Py,Gplayout,Ppfg,Ppbg);//~va1MR~//~vamfR~
	    xxescr_scrprtGtk(xx,Py,Pplayout);                          //~vamfI~
        if (dbcssz>1)                                              //~va1MR~
        {                                                          //~va1MR~
            ii++;                                                  //~va1MR~
            xx+=Mcellw;                                            //~va1MR~
        }                                                          //~va1MR~
    }                                                              //~va1MR~
    if (accumctr)	//last remaining                               //~va3bI~
    {                                                              //~va3bI~
        pc=wknonalpha;                                             //~va3bI~
//      pango_layout_set_text(Gplayout,pc,accumctr);               //~va3bI~//~vamfR~
        pango_layout_set_text(Pplayout,pc,accumctr);               //~vamfI~
//      usetmonospace(Popt,Gplayout,pc,pcd,accumctr,Mcellw);       //~va3bI~//~vamfR~
        usetmonospace(Popt,Pplayout,pc,pcd,accumctr,Mcellw);       //~vamfI~
UTRACED("drawtextstr_ligature nonalpha last",pc,accumctr);         //~va3bI~
dprintf("drawtextstr_ligature nonalpha last xx=%d,len=%d\n",xx1,accumctr);//~va3bI~
//      gdk_draw_layout_with_colors(Ppdc,Ppgc,xx1,Py,Gplayout,Ppfg,Ppbg);//~va3bI~//~vamfR~
        xxescr_scrprtGtk(xx1,Py,Pplayout);                         //~vamfI~
    }                                                              //~va3bI~
}//drawtextstr_ligatureGtk                                            //~va1MR~//~vamfR~
#endif //!GTKPRINT                                                 //~vamfM~
//===============================================================================//~va1MR~
//draw textstring by utf8; 1 by 1 for ligature                     //~va1MR~
//===============================================================================//~va1MR~
#ifdef UTF8UCS2                                                    //~va20I~
void  drawtextstr_ligature(int Popt,CDC *Ppdc,GdkGC *Ppgc,int Px,int Py,GdkColor *Ppfg,GdkColor *Ppbg,char *Pptext,int Plenu8,char *Ppdata,char *Ppdbcs,int Plen)//~va20I~
#else                                                              //~va20I~
void  drawtextstr_ligature(CDC *Ppdc,GdkGC *Ppgc,int Px,int Py,GdkColor *Ppfg,GdkColor *Ppbg,char *Pptext,int Plenu8,char *Ppdata,char *Ppdbcs,int Plen)//~va1MR~
#endif                                                             //~va20I~
{                                                                  //~va1MR~
	char *ptext,*pdata,*pdbcs;                                     //~va1MR~
    int ii,chsz,xx=0,dbcssz;                                       //~vaffR~
//  int accumctr=0,xx1;                                            //~vaffR~
    int accumctr=0,xx1=0;                                          //~vaffI~
//  char wknonalpha[MAXCOL],*pc=wknonalpha,*pcd;//accum numeric(no ligature) write at once//~vaffR~
    char wknonalpha[MAXCOL],*pc=wknonalpha,*pcd=NULL;//accum numeric(no ligature) write at once//~vaffI~
//*****************                                                //~va1MR~
UTRACED("pu8",Pptext,Plenu8);                                      //~va1MR~
UTRACED("plc",Ppdata,Plen);                                        //~va1MR~
UTRACED("pdbcs",Ppdbcs,Plen);                                      //~va1MR~
    for (ii=0,ptext=Pptext,pdata=Ppdata,pdbcs=Ppdbcs,xx=Px;        //~va1MR~
		ii<Plen;                                                   //~va1MR~
		ii++,ptext+=chsz,pdata+=dbcssz,pdbcs+=dbcssz,xx+=Mcellw)   //~va1MR~
    {                                                              //~va1MR~
    	if (*ptext<'A')	//no ligature may occur                    //~va3bI~
        {                                                          //~va3bI~
        	dbcssz=1;                                              //~va3bI~
            chsz=1;                                                //~va3bI~
            *pc++=*ptext;	//                                     //~va3bI~
            if (!accumctr)	//top                                  //~va3bI~
            {                                                      //~va3bI~
            	pcd=pdbcs;                                         //~va3bI~
                xx1=xx;                                            //~va3bI~
            }                                                      //~va3bI~
            accumctr++;                                            //~va3bI~
            continue;                                              //~va3bI~
        }                                                          //~va3bI~
        if (accumctr)                                              //~va3bI~
        {                                                          //~va3bI~
        	pc=wknonalpha;                                         //~va3bI~
	    	pango_layout_set_text(Gplayout,pc,accumctr);           //~va3bI~
  			usetmonospace(Popt,Gplayout,pc,pcd,accumctr,Mcellw);   //~va3bI~
UTRACED("drawtextstr_ligature nonalpha",pc,accumctr);              //~va3bI~
dprintf("drawtextstr_ligature nonalpha xx=%d,len=%d\n",xx1,accumctr);//~va3bI~
    		gdk_draw_layout_with_colors(Ppdc,Ppgc,xx1,Py,Gplayout,Ppfg,Ppbg);//~va3bI~
            accumctr=0;                                            //~va3bI~
        }                                                          //~va3bI~
    	chsz=UTF8CHARLENERR1(*ptext);                              //~va1MR~
//*after converted dd dbcs to locale dbcs                          //~va20I~
        if (*pdbcs==UDBCSCHK_DBCS1ST) //require  full byte write for DBCS//~va1MR~
        	dbcssz=XESUB_DBCSSPLITCTR(pdbcs,Plen-ii,0);            //~va1MR~
        else                                                       //~va1MR~
        	dbcssz=1;                                              //~va1MR~
    	pango_layout_set_text(Gplayout,ptext,chsz);                //~va1MR~
#ifdef UTF8UCS2                                                    //~va20I~
  		usetmonospace(Popt,Gplayout,pdata,pdbcs,dbcssz,Mcellw);    //~va20I~
#else                                                              //~va20I~
  		usetmonospace(0,Gplayout,pdata,pdbcs,dbcssz,Mcellw);       //~va1MR~
#endif                                                             //~va20I~
UTRACEP("drawtextstr_ligature utf8 ii=%d,dbcssz=%d\n",ii,dbcssz);  //~va1MR~
UTRACED("drawtextstr_ligature utf8",ptext,chsz);                   //~va1MR~
UTRACED("drawtextstr_ligature lc  ",pdata,dbcssz);                 //~va1MR~
    	gdk_draw_layout_with_colors(Ppdc,Ppgc,xx,Py,Gplayout,Ppfg,Ppbg);//~va1MR~
        if (dbcssz>1)                                              //~va1MR~
        {                                                          //~va1MR~
            ii++;                                                  //~va1MR~
            xx+=Mcellw;                                            //~va1MR~
        }                                                          //~va1MR~
    }                                                              //~va1MR~
    if (accumctr)	//last remaining                               //~va3bI~
    {                                                              //~va3bI~
        pc=wknonalpha;                                             //~va3bI~
        pango_layout_set_text(Gplayout,pc,accumctr);               //~va3bI~
        usetmonospace(Popt,Gplayout,pc,pcd,accumctr,Mcellw);       //~va3bI~
UTRACED("drawtextstr_ligature nonalpha last",pc,accumctr);         //~va3bI~
dprintf("drawtextstr_ligature nonalpha last xx=%d,len=%d\n",xx1,accumctr);//~va3bI~
        gdk_draw_layout_with_colors(Ppdc,Ppgc,xx1,Py,Gplayout,Ppfg,Ppbg);//~va3bI~
    }                                                              //~va3bI~
}//drawtextstr_ligature                                            //~va1MR~
#endif                                                             //~va1MR~
#ifdef UTF8UCS2                                                    //~va30R~
#ifdef GTKPRINT                                                    //~vamfI~
//===============================================================================//~va30R~
//draw textstring by utf8; 1 by 1 for ligature considering combining char using Gtk//~va30R~//~vamfR~
//===============================================================================//~va30R~
//void  drawtextstr_ligatureu8(int Popt,CDC *Ppdc,GdkGC *Ppgc,int Px,int Py,GdkColor *Ppfg,GdkColor *Ppbg,char *Pptext,int Plenu8,char *Ppdata,char *Ppdbcs,int Plen,char *Ppdddbcs)//~va30R~//~vamfR~
void  drawtextstr_ligatureu8Gtk(int Popt,CDC *Ppdc,GdkGC *Ppgc,PangoLayout *Pplayout,int Px,int Py,GdkColor *Ppfg,GdkColor *Ppbg,char *Pptext,int Plenu8,char *Ppdata,char *Ppdbcs,int Plen,char *Ppdddbcs)//~vamfR~
{                                                                  //~va30R~
	char *pu8,*pdbcs,*pdddbcs,*pdata;                              //~va30R~
	char *pu8n,*pdbcsn,*pdddbcsn,*pcombdddbcs,*pcombu8,*pdatan;    //~va30R~
    int ii,xx,chsz,dbcssz,lenu8,lenlc,dbcsid,comblenlc,comblenu8=0;//~vaffR~
//*****************                                                //~va30R~
UTRACED("drawetxtstr_ligatureGtk Pptext",Pptext,Plenu8);                                      //~va30R~//~vamfR~
UTRACED("plc",Ppdata,Plen);                                        //~va30R~
UTRACED("pdbcs",Ppdbcs,Plen);                                      //~va30R~
UTRACED("pdddbcs",Ppdddbcs,Plen);                                  //~va30R~
    for (ii=0,pu8=Pptext,pdbcs=Ppdbcs,pdddbcs=Ppdddbcs,pdata=Ppdata,xx=Px;//~va30R~
		ii<Plen;                                                   //~va30R~
		pdata+=lenlc,pu8+=lenu8,pdbcs+=lenlc,pdddbcs+=lenlc)       //~va30R~
    {                                                              //~va30R~
        for (lenu8=0,lenlc=0,comblenlc=0,pu8n=pu8,pdbcsn=pdbcs,pdddbcsn=pdddbcs,pdatan=pdata;//~va30R~
            ii<Plen;                                               //~va30R~
            ii+=dbcssz,pu8n+=chsz,pdbcsn+=dbcssz,pdddbcsn+=dbcssz,lenlc+=dbcssz,lenu8+=chsz,pdatan+=dbcssz)//~va30R~
        {                                                          //~va30R~
            chsz=UTF8CHARLENERR1(*pu8n);                           //~va30R~
    //*after converted dd dbcs to locale dbcs                      //~va30R~
            if (*pdbcsn==UDBCSCHK_DBCS1ST) //require  full byte write for DBCS//~va30R~
                dbcssz=2;                                          //~va30R~
            else                                                   //~va30R~
                dbcssz=1;                                          //~va30R~
            if (ii+dbcssz<Plen)                                    //~va30R~
            {                                                      //~va30R~
                dbcsid=*(pdddbcsn+dbcssz);                         //~va30R~
                if (UDBCSCHK_ISUCSWIDTH0(dbcsid))    //next has following combining char//~va30R~
                {                                                  //~va30R~
                	for (comblenu8=chsz,comblenlc=dbcssz,ii+=dbcssz,pcombu8=pu8n+chsz,pcombdddbcs=pdddbcsn+dbcssz;//~va30R~
							ii<Plen;                               //~va30R~
							ii++,pcombdddbcs++,comblenlc++,pcombu8+=chsz,comblenu8+=chsz)//~va30R~
                    {                                              //~va30R~
			            chsz=UTF8CHARLENERR1(*pcombu8);            //~va30R~
		                dbcsid=*pcombdddbcs;                       //~va30R~
		                if (!UDBCSCHK_ISUCSWIDTH0(dbcsid))    //next has following combining char//~va30R~
	                		break;                                 //~va30R~
                    }                                              //~va30R~
                    break;                                         //~va30R~
                }                                                  //~va30R~
            }                                                      //~va30R~
        }                                                          //~va30R~
        if (lenlc)                                                 //~va30R~
        {                                                          //~va30R~
//  		drawtextstr_ligature(Popt,Ppdc,Ppgc,xx,Py,Ppfg,Ppbg,pu8,lenu8,pdata,pdbcs,lenlc);//~va30R~//~vamfR~
    		drawtextstr_ligatureGtk(Popt,Ppdc,Ppgc,Pplayout,xx,Py,Ppfg,Ppbg,pu8,lenu8,pdata,pdbcs,lenlc);//~vamfI~
            xx+=lenlc*Mcellw;                                      //~va30R~
        }                                                          //~va30R~
        if (comblenlc)                                             //~va30R~
        {                                                          //~va30R~
UTRACED("drawtextstr_ligatureu8 settext utf8",pu8n,comblenu8);     //~va30R~
UTRACED("drawtextstr_ligatureu8 settext lc  ",pdatan,comblenlc);   //~va30R~
//  		pango_layout_set_text(Gplayout,pu8n,comblenu8);        //~va30R~//~vamfR~
    		pango_layout_set_text(Pplayout,pu8n,comblenu8);        //~vamfI~
//			usetmonospace(Popt,Gplayout,pdatan,pdbcsn,comblenlc,Mcellw);//~va30R~//~vamfR~
  			usetmonospace(Popt,Pplayout,pdatan,pdbcsn,comblenlc,Mcellw);//~vamfI~
//  		gdk_draw_layout_with_colors(Ppdc,Ppgc,xx,Py,Gplayout,Ppfg,Ppbg);//~va30R~//~vamfR~
        	xxescr_scrprtGtk(xx,Py,Pplayout);                      //~vamfI~
            xx+=comblenlc*Mcellw;                                  //~va30R~
            lenlc+=comblenlc;                                      //~va30R~
            lenu8+=comblenu8;                                      //~va30R~
        }                                                          //~va30R~
    }                                                              //~va30R~
}//drawtextstr_ligatureu8Gtk                                          //~va30R~//~vamfR~
#endif //GTKPRINT                                                  //~vamfI~
//===============================================================================//~va30R~
//draw textstring by utf8; 1 by 1 for ligature considering combining char//~va30R~
//===============================================================================//~va30R~
void  drawtextstr_ligatureu8(int Popt,CDC *Ppdc,GdkGC *Ppgc,int Px,int Py,GdkColor *Ppfg,GdkColor *Ppbg,char *Pptext,int Plenu8,char *Ppdata,char *Ppdbcs,int Plen,char *Ppdddbcs)//~va30R~
{                                                                  //~va30R~
	char *pu8,*pdbcs,*pdddbcs,*pdata;                              //~va30R~
	char *pu8n,*pdbcsn,*pdddbcsn,*pcombdddbcs,*pcombu8,*pdatan;    //~va30R~
    int ii,xx,chsz,dbcssz,lenu8,lenlc,dbcsid,comblenlc,comblenu8=0;//~vaffR~
//*****************                                                //~va30R~
UTRACED("pu8",Pptext,Plenu8);                                      //~va30R~
UTRACED("plc",Ppdata,Plen);                                        //~va30R~
UTRACED("pdbcs",Ppdbcs,Plen);                                      //~va30R~
UTRACED("pdddbcs",Ppdddbcs,Plen);                                  //~va30R~
    for (ii=0,pu8=Pptext,pdbcs=Ppdbcs,pdddbcs=Ppdddbcs,pdata=Ppdata,xx=Px;//~va30R~
		ii<Plen;                                                   //~va30R~
		pdata+=lenlc,pu8+=lenu8,pdbcs+=lenlc,pdddbcs+=lenlc)       //~va30R~
    {                                                              //~va30R~
        for (lenu8=0,lenlc=0,comblenlc=0,pu8n=pu8,pdbcsn=pdbcs,pdddbcsn=pdddbcs,pdatan=pdata;//~va30R~
            ii<Plen;                                               //~va30R~
            ii+=dbcssz,pu8n+=chsz,pdbcsn+=dbcssz,pdddbcsn+=dbcssz,lenlc+=dbcssz,lenu8+=chsz,pdatan+=dbcssz)//~va30R~
        {                                                          //~va30R~
            chsz=UTF8CHARLENERR1(*pu8n);                           //~va30R~
    //*after converted dd dbcs to locale dbcs                      //~va30R~
            if (*pdbcsn==UDBCSCHK_DBCS1ST) //require  full byte write for DBCS//~va30R~
                dbcssz=2;                                          //~va30R~
            else                                                   //~va30R~
                dbcssz=1;                                          //~va30R~
            if (ii+dbcssz<Plen)                                    //~va30R~
            {                                                      //~va30R~
                dbcsid=*(pdddbcsn+dbcssz);                         //~va30R~
                if (UDBCSCHK_ISUCSWIDTH0(dbcsid))    //next has following combining char//~va30R~
                {                                                  //~va30R~
                	for (comblenu8=chsz,comblenlc=dbcssz,ii+=dbcssz,pcombu8=pu8n+chsz,pcombdddbcs=pdddbcsn+dbcssz;//~va30R~
							ii<Plen;                               //~va30R~
							ii++,pcombdddbcs++,comblenlc++,pcombu8+=chsz,comblenu8+=chsz)//~va30R~
                    {                                              //~va30R~
			            chsz=UTF8CHARLENERR1(*pcombu8);            //~va30R~
		                dbcsid=*pcombdddbcs;                       //~va30R~
		                if (!UDBCSCHK_ISUCSWIDTH0(dbcsid))    //next has following combining char//~va30R~
	                		break;                                 //~va30R~
                    }                                              //~va30R~
                    break;                                         //~va30R~
                }                                                  //~va30R~
            }                                                      //~va30R~
        }                                                          //~va30R~
        if (lenlc)                                                 //~va30R~
        {                                                          //~va30R~
			drawtextstr_ligature(Popt,Ppdc,Ppgc,xx,Py,Ppfg,Ppbg,pu8,lenu8,pdata,pdbcs,lenlc);//~va30R~
            xx+=lenlc*Mcellw;                                      //~va30R~
        }                                                          //~va30R~
        if (comblenlc)                                             //~va30R~
        {                                                          //~va30R~
UTRACED("drawtextstr_ligatureu8 settext utf8",pu8n,comblenu8);     //~va30R~
UTRACED("drawtextstr_ligatureu8 settext lc  ",pdatan,comblenlc);   //~va30R~
    		pango_layout_set_text(Gplayout,pu8n,comblenu8);        //~va30R~
  			usetmonospace(Popt,Gplayout,pdatan,pdbcsn,comblenlc,Mcellw);//~va30R~
    		gdk_draw_layout_with_colors(Ppdc,Ppgc,xx,Py,Gplayout,Ppfg,Ppbg);//~va30R~
            xx+=comblenlc*Mcellw;                                  //~va30R~
            lenlc+=comblenlc;                                      //~va30R~
            lenu8+=comblenu8;                                      //~va30R~
        }                                                          //~va30R~
    }                                                              //~va30R~
}//drawtextstr_ligatureu8                                          //~va30R~
#endif                                                             //~va30R~
#ifdef GTKPRINT
//===============================================================================//~vXXEI~
//draw textstring by utf8  for hcopy print by GTK                                        //~vXXEI~//~vamfR~
//print and dot preview mode                                       //~vbA3R~
//===============================================================================//~vXXEI~
//void  drawtextstrGtk(CDC *Ppdc,int Pprintsw,int Px,int Py,char *Ptext,char *Ppdbcs,int Plen,int Pfgpal,int Pbgpal,int Pdbcsctr,int Prow,int Pcol)//~va30I~//~vb4rR~
void  drawtextstrGtk(int Popt,CDC *Ppdc,int Pprintsw,int Px,int Py,char *Ptext,char *Ppdbcs,int Plen,int Pfgpal,int Pbgpal,int Pdbcsctr,int Prow,int Pcol)//~vb4rI~
{                                                                  //~vXXEI~
  	UCHAR *ptext/*,*pc,*pce*/;                                     //~vaffI~
    int /*readlen,*/writelen;                                      //~v69sR~
	GdkColor *pfg,*pbg;                                            //~vXXEI~
    GdkGC *pgc;                                                    //~vXXEI~
	int utfrc;                                                     //~v69VI~
    char *pdatascr,*pdbcsscr,*ptextscr,*pdata;	//expanded  by "." insersion for SS3/GB4//~vaffI~
    UCHAR *pdbcs;	//expanded  by "." insersion for SS3/GB4       //~vaffI~
    USHORT *poffst;                                                //~va1cR~
    int writelenlc,slno,xx,offsu8,offslc,oldoffslc,oldoffsu8,padlen,jj,reslen;//~va1cR~
	GdkColor *pfgpad,*pfgorg;                                      //~va1cR~
    int swligature;                                                //~va1MR~
	int optds,swutf8data,opt,rc,optusms=0;                         //~va20R~
    int swrtl=0;    //right to left                                //~va20I~
    char *pdddbcs=NULL;                                            //~vaffR~
    int swligaturemode;                                            //~va6pR~
    PangoLayout *playout;                                          //~vamfI~
//********************                                             //~vXXEI~
UTRACEP("drawtextstrGtk printsw=%d,row=%d,xx=%d,yy=%d,len=%d\n",Pprintsw,Prow,Px,Py,Plen);//~va6pR~//~vam0R~//~vamfR~
	optds=Pprintsw;                                                //~va20I~
	Pprintsw &=SPO_PRINT;                                          //~va20I~
    swutf8data=optds & SPO_DDFMT;                                  //~va20I~
//  swligaturemode= (Mligature^Mligaturereverse)  //ligature mode  //~vb4rR~
    swligaturemode= WXE_LIGATUREMODE(Popt)  //ligature mode        //~vb4rI~
   					&&  !(optds & SPO_NOLIGATURE);	 //not ligature disabled part//~va6pI~
    if (Pprintsw)                                                  //~vamfI~
    	playout=GplayoutGtkPrintScr;                               //~vamfI~
    else                                                           //~vamfI~
    	playout=Gplayout;                                          //~vamfI~
  	if (swutf8data)                                                  //~va20I~
  	{                                                                //~va20I~
		opt=UTFDD2FO_ERRREP|UTFDD2FO_DBCSSPACEREP|UTFDD2FO_DUPREPCHK|UTFDD2FO_VIO;//~va20R~
        opt|=UTFDD2FO_SETDDDBCSALT;//     0x4000 //update dddbcs by altch//~vbArI~
    	rc=xeutfcvdd2f(opt,Ptext,Ppdbcs,Plen,(UCHAR**)&ptext,&writelen,(UCHAR**)&pdbcs);//~va20R~
    	if (rc)                                                        //~va20I~
    		return;                                                    //~va20R~
UTRACED("drawtextstr inp data",Ptext,Plen);                        //~va20I~
UTRACED("drawtextstr inp dbcs",Ppdbcs,Plen);                       //~va20I~
UTRACED("drawtextstr out utf8",ptext,writelen);                    //~va20I~
UTRACED("drawtextstr out dbcs",pdbcs,Plen);                        //~va20I~
    	pdddbcs=Ppdbcs; //dd fmt dbcs for ligature process             //~va30R~
    	Ppdbcs=pdbcs;	//like setdbcstbl,set DBCS1ST and DBCS2ND and rep errch//~va20M~
    	slno=0; //no dbcs padding                                      //~va20I~
    	writelenlc=Plen;    //dd str len                               //~va20I~
    	optusms=USMSO_DDFMT; //scr data is dd fmt                      //~va20R~
    	pdata=Ptext;	//ddfmt should not used,but safety for access vioration err//~va20R~
    	swrtl=drawtextstr_chkrtl(0,ptext,writelen);                    //~va20I~
        if (swrtl)                                                 //~vbkqI~
	    	optusms=USMSO_RTL; //scr data is dd fmt                //~vbkqI~
  	}                                                                //~va20I~
  	else                                                             //~va20I~
  	{                                                                //~va20I~
UTRACED("drawtextstr",Ptext,Plen);                                 //~v69UI~
		opt=CSL2UO_REP0a0d/*rep 0a 0d by ?*/;                          //~va6pI~
    	if (swligaturemode)                                            //~va6pI~
			opt=CSL2UO_LIGATURE;	//set no padding                   //~va6pI~
    	utfrc=csublocale2utf8scr(opt,Ptext,Ppdbcs,Plen,0,&ptextscr,&pdatascr,&pdbcsscr,&poffst,&writelen,&writelenlc,&slno);//~va6pI~
    	ptext=ptextscr;                                                //~va1cR~
    	pdata=pdatascr;                                                //~va1cR~
    	pdbcs=pdbcsscr;                                                //~va1cR~
    	if (utfrc>1)                                                   //~v69VI~
    		return;                                                    //~vXXEM~
  	}//not dd fmt                                                    //~va20I~
#ifndef GTKPRINT                                                   //~vamfI~
	if (Pprintsw)	//previewmode                                  //~vXXEI~
    {                                                              //~vXXEI~
    	uprtscrtextout(ptext,Px,Py,writelen);                      //~vXXEI~
    }                                                              //~vXXEI~
    else                                                           //~vXXEI~
#endif                                                             //~vamfI~
    {                                                              //~vXXEI~
	  	if (Pfgpal & WXE_SYNTAXRGB)                                  //~v780I~
        	pfg=Gxxesynpalette+(Pfgpal&0x0f);                          //~v780I~
      	else                                                         //~v780I~
    		pfg=Gxxepalette+Pfgpal;                                    //~vXXER~
		if (slno)                                                  //~va1cR~
        {                                                          //~va1cR~
		  	if (Pfgpal & WXE_SYNTAXRGB)                            //~va1cR~
        		pfgpad=Gxxesynpalette+UVIOM_PADATTR;               //~va1cR~
      		else                                                   //~va1cR~
    			pfgpad=Gxxepalette+UVIOM_PADATTR;                  //~va1cR~
        }                                                          //~va1cR~
        else                                                       //~vaffI~
            pfgpad=pfg; //not used when slno=0 but for uninit warning//~vaffI~
	  	if (Pbgpal & WXE_SYNTAXRGB)                                  //~v780I~
        	pbg=Gxxesynpalette+(Pbgpal&0x0f);                          //~v780I~
      	else                                                         //~v780I~
    	if (Pbgpal)                                                //~vXXER~
        	pbg=Gxxepalette+Pbgpal;                                //~vXXER~
    	else                                                       //~vXXER~
        	pbg=&(Gcolordata.CDcolor);                             //~vXXER~
    	pgc=Gpgc;                                                  //~vXXER~
UTRACEP("pos=y=%d,x=%d,bg=%x,fg=%x\n",Py,Px,*pbg,*pfg);            //~va1cR~
UTRACED("drawtextstr",ptext,writelen);                             //~va1cR~
    	if (UTF_COMBINEMODE())                                     //~va30R~
        	optusms|=USMSO_COMBINEON;	//parm to also draw ligature//~va30R~
    	else                                                       //~va30R~
        	optusms|=USMSO_COMBINEOF;                              //~va30R~
        pfgorg=pfg;                                                //~va1cR~
      	for (oldoffsu8=0,oldoffslc=0,xx=Px,reslen=writelenlc;reslen>0;)//~va1cR~
      	{	//padding attr setting                                     //~va1cR~
        	pfg=pfgorg;                                                //~va1cR~
UTRACEP("drawtextstr reslen=%d,slno=%d\n",reslen,slno);            //~va1DI~
			if (slno)                                                  //~va1cR~
        	{                                                          //~va1cR~
            	offsu8=*poffst++;                                      //~va1cR~
            	offslc=*poffst++;                                      //~va1cR~
	        	padlen=((offsu8 & 0x8000)!=0)+1;	//2 for gb4,1 for ss3//~va1cR~
            	offsu8&=0x7fff;                                        //~va1cR~
            	writelen=offsu8-oldoffsu8;                             //~va1cR~//~va7GR~
            	writelenlc=offslc-oldoffslc;                           //~va1cR~//~va7GR~
      	    	oldoffsu8=offsu8;                                      //~va7GI~
          		oldoffslc=offslc+padlen;                               //~va1cR~
            	reslen-=writelenlc+padlen;                             //~va1cR~
            	slno--;                                                //~va1cR~
        	}	                                                          //~va1cR~
        	else                                                       //~va1KI~
        	{                                                          //~va1KI~
	        	padlen=0;                                              //~va1KI~
            	reslen-=writelenlc;                                    //~va1KI~
        	}                                                          //~va1KI~
UTRACEP("drawtextstr2 reslen=%d,slno=%d\n",reslen,slno);           //~va1KI~
       		for (jj=0;jj<2;jj++)                                        //~va1cR~
       		{                                                           //~va1cR~
UTRACEP("drawtextstr jj=%d,paddlen=%d,reslen=%d,slno=%d,writelen=%d,writelenlc=%d\n",jj,padlen,reslen,slno,writelen,writelenlc);//~va1DI~
//  			pango_layout_set_text(Gplayout,ptext,writelen);            //~vXXER~//~vamfR~
    			pango_layout_set_text(playout,ptext,writelen);     //~vamfI~
				UTRACED("drawtextstr pango settext",ptext,writelen);       //~va6nR~
   				if (swligaturemode)                                             //~va6pI~
   				{                                                               //~va3iI~
    				UTRACEP("drawtextstr ligature mode\n");                         //~va6pI~//~vamfR~
//					usetmonospace_ligature(optusms,Gplayout,pdata,pdbcs,writelenlc,Mcellw);//~va3iI~//~vamfR~
//  					usetmonospace_ligature(optusms,playout,pdata,pdbcs,writelenlc,Mcellw);//~vb4rR~
    					usetmonospace_ligature(optusms,playout,pdata,pdbcs,writelenlc,Mcellw,0/*xx=strwidth*/);//~vb4rI~
//  				gdk_draw_layout_with_colors(Ppdc,pgc,xx,Py,Gplayout,pfg,pbg);  //~va3iI~//~vamfR~
                  if (Pprintsw)                                    //~vamfI~
                    xxescr_scrprtGtk(xx,Py,playout);               //~vamfR~
                  else                                             //~vamfI~
    				gdk_draw_layout_with_colors(Ppdc,pgc,xx,Py,playout,pfg,pbg);//~vamfI~
   				}                                                               //~va3iI~
   				else	//not ligature mode write                                  //~va3iI~
   				{                                                               //~va3iI~
//     				swligature=xxescr_chkligature(pdbcs,writelenlc);           //~va3bM~//~vamfR~
       				swligature=xxescr_chkligatureGtk(playout,pdbcs,writelenlc);//~vamfI~
					UTRACEP("chkligature swligature=%d\n",swligature);                            //~va3bM~//~vamfR~
					dprintf("ligature %d,opt=x%x\n",swligature,optds);                 //~va3bM~
    				if (swligature)	//correct ligature to monospace                //~va30R~
    				{                                                              //~va30R~
      					if (swutf8data)                                              //~va30R~
//      					drawtextstr_ligatureu8(optusms,Ppdc,pgc,xx,Py,pfg,pbg,ptext,writelen,pdata,pdbcs,writelenlc,pdddbcs);//~va30R~//~vamfR~
        					drawtextstr_ligatureu8Gtk(optusms,Ppdc,pgc,playout,xx,Py,pfg,pbg,ptext,writelen,pdata,pdbcs,writelenlc,pdddbcs);//~vamfI~
      					else                                                         //~va30R~
//      					drawtextstr_ligature(optusms,Ppdc,pgc,xx,Py,pfg,pbg,ptext,writelen,pdata,pdbcs,writelenlc);//~va30R~//~vamfR~
        					drawtextstr_ligatureGtk(optusms,Ppdc,pgc,playout,xx,Py,pfg,pbg,ptext,writelen,pdata,pdbcs,writelenlc);//~vamfI~
    				}                                                              //~va30R~
    				else                                                           //~va30R~
    				{	//no ligature occurred                                     //~va30R~
            			if (optusms & USMSO_COMBINEON)   //scr combine mode    //~va30R~
    						optusms|=USMSO_COMBINESP;    //widen width for the string if ligature occured//~va30R~
//						usetmonospace(optusms,Gplayout,pdata,pdbcs,writelenlc,Mcellw);//~va20I~//~vamfR~
  						usetmonospace(optusms,playout,pdata,pdbcs,writelenlc,Mcellw);//~vamfI~
						UTRACED("pango setmonospace",pdbcs,writelenlc);            //~va1cR~
      					if (swrtl)                                                   //~va20I~
      					{                                                            //~va20I~
        					swligature=1;                                              //~va20I~
//      					drawtextstr_ligature(optusms,Ppdc,pgc,xx,Py,pfg,pbg,ptext,writelen,pdata,pdbcs,writelenlc);//~va20I~//~vamfR~
        					drawtextstr_ligatureGtk(optusms,Ppdc,pgc,playout,xx,Py,pfg,pbg,ptext,writelen,pdata,pdbcs,writelenlc);//~vamfI~
      					}                                                            //~va20I~
      					else                                                         //~va20I~
      					{                                                            //~va20I~
//  						UTRACELAYOUT(Gplayout);                                    //~va30R~//~vamfR~
    						UTRACELAYOUT(playout);                 //~vamfI~
      					}//!swrtl                                                    //~va20I~
						UTRACEP("drawtextstr not ligature gdk_draw_layout_with_colors pos=%d,y=%d\n",xx,Py);//~vam4I~//~vam7R~
						if (!swligature)                                               //~va1MR~
                        {                                          //~vamfI~
//  						gdk_draw_layout_with_colors(Ppdc,pgc,xx,Py,Gplayout,pfg,pbg);//~va1cR~//~vamfR~
                  		  if (Pprintsw)                            //~vamfI~
                    		xxescr_scrprtGtk(xx,Py,playout);       //~vamfR~
                  		  else                                     //~vamfI~
    						gdk_draw_layout_with_colors(Ppdc,pgc,xx,Py,playout,pfg,pbg);//~vamfI~//~vbz9R~
//  						xxescr_drawlayout(Ppdc,pgc,xx,Py,playout,pfg,pbg);//~vbz9R~
                        }                                          //~vamfI~
    				}	//no ligature occurred                                     //~va30R~
   				}//not ligature mode wrire                                      //~va3iI~
//  			UTRACEP("pango color swligature=%d,xx=%d\n",swligature,xx);                        //~va1cR~//~vaffR~
				if (reslen<0)     //last may not end by padding            //~va1cR~
        			break;                                                 //~va1cR~
        		ptext+=writelen;                                           //~va1cR~
        		pdata+=writelenlc;                                         //~va1cR~
        		pdbcs+=writelenlc;                                         //~va1cR~
        		xx+=Mcellw*(writelenlc-padlen);	//advance by char width(drop adjust by padlen for pad write)//~va1cR~
        		UTRACEP("xx=%d\n",xx);                                     //~va7GR~
				if (!padlen)     //last has no padding                     //~va1KI~
        			break;                                                 //~va1KI~
        		writelen=padlen*UTF8CHARLENERR1(*ptext);//Guviomdbcspad set by csublocaletoutf8 may not be ascii but ucs altchar//~va6nR~
      			oldoffsu8+=writelen;	//offsetlc is already updated      //~va7GI~
        		writelenlc=padlen;                                         //~va1cR~
        		padlen=0;	//no padding for padd write                    //~va1cR~
        		pfg=pfgpad; //for padding                                  //~va1cR~
       		}//org string and padding                                   //~va1cR~
			if (!slno)                                                 //~va1cR~
        		break;                                                 //~va1cR~
      	}	//padding attr setting loop                                //~va1cR~
//!printsw                                                         //~va30R~
    }                                                              //~vXXEI~
//UTRACEP("@@@ str=%d,utf=%d,mono=%d,text=%d,draw=%d\n",Setstr,Setutf,Setmono,Settext,Setdraw);//~v69VR~
    return;                                                        //~vXXEI~
}//drawtextstrGtk                                                     //~vXXER~//~vamfR~
#endif //GTKPRINT
//===============================================================================//~vXXEI~
//draw textstring by utf8                                          //~vXXEI~
//scr draw or print preview                                        //~va30R~
//Pprintsw:option SPO_xxxx                                         //~vbDsI~
//===============================================================================//~vXXEI~
//void  drawtextstr(CDC *Ppdc,int Pprintsw,int Px,int Py,char *Ptext,char *Ppdbcs,int Plen,int Pfgpal,int Pbgpal)//~v69VR~
//void  drawtextstr(CDC *Ppdc,int Pprintsw,int Px,int Py,char *Ptext,char *Ppdbcs,int Plen,int Pfgpal,int Pbgpal,int Pdbcsctr)//~va30R~
//void  drawtextstr(CDC *Ppdc,int Pprintsw,int Px,int Py,char *Ptext,char *Ppdbcs,int Plen,int Pfgpal,int Pbgpal,int Pdbcsctr,int Prow)//~va30R~
//void  drawtextstr(CDC *Ppdc,int Pprintsw,int Px,int Py,char *Ptext,char *Ppdbcs,int Plen,int Pfgpal,int Pbgpal,int Pdbcsctr,int Prow,int Pcol)//~vb4rR~
void  drawtextstr(int Popt,CDC *Ppdc,int Pprintsw,int Px,int Py,char *Ptext,char *Ppdbcs,int Plen,int Pfgpal,int Pbgpal,int Pdbcsctr,int Prow,int Pcol)//~vb4rI~
{                                                                  //~vXXEI~
//  GError *errpos=NULL;                                           //~v69sR~
//	char *ptext/*,*pc,*pce*/;                                      //~v69sR~//~vaffR~
  	UCHAR *ptext/*,*pc,*pce*/;                                     //~vaffI~
    int /*readlen,*/writelen;                                      //~v69sR~
	GdkColor *pfg,*pbg;                                            //~vXXEI~
    GdkGC *pgc;                                                    //~vXXEI~
#ifdef AAA                                                         //~va30R~
    PangoRectangle recti,rectl;                                    //~va1KR~
#endif                                                             //~va30R~
//  PangoAttrList  *ppal;                                          //~vX03R~
	int utfrc;                                                     //~v69VI~
#ifndef NOTRACE                                                    //~v69UI~
//  struct timeb tb,tb2;                                           //~v69VI~//~vbv4R~
//  static int Setutf,Setmono,Setstr,Settext,Setdraw;              //~v69VI~//~vbv4R~
#endif                                                             //~v69UI~
#ifdef UTF8SUPPH                                                   //~va1cR~
//  char *pdatascr,*pdbcsscr,*ptextscr,*pdata,*pdbcs;	//expanded  by "." insersion for SS3/GB4//~va1cR~//~vaffR~
    char *pdatascr,*pdbcsscr,*ptextscr,*pdata;	//expanded  by "." insersion for SS3/GB4//~vaffI~
    UCHAR *pdbcs;	//expanded  by "." insersion for SS3/GB4       //~vaffI~
    USHORT *poffst;                                                //~va1cR~
    int writelenlc,slno,xx,offsu8,offslc,oldoffslc,oldoffsu8,padlen,jj,reslen;//~va1cR~
	GdkColor *pfgpad,*pfgorg;                                      //~va1cR~
    int swligature;                                                //~va1MR~
#ifdef AAA                                                         //~va30R~
    int boxwidth;                                                  //~va1MR~
#endif                                                             //~va30R~
#endif                                                             //~va1cR~
#ifdef UTF8UCS2                                                    //~va20I~
	int optds,swutf8data,opt,rc,optusms=0;                         //~va20R~
    int swrtl=0;    //right to left                                //~va20I~
    char *pdddbcs=NULL;                                            //~vaffR~
#endif                                                             //~va20I~
    int swligaturemode;                                            //~va6pR~
    int glyphctr,ucsctr;                                           //~vbk6I~
    int swcombinemodeline,swwidth0Ovf;                             //~vbknR~
    int optusmsVhexDataCpos;                                       //~vbDsI~
//********************                                             //~vXXEI~
	swcombinemodeline=COMBINEMODE(Popt);  //split or unpr          //~vbknI~
UTRACEP("%s:Popt=%04x,Printsw=%04x,row=%d,col=%d,xx=%d,yy=%d,len=%d,fg=%d,bg=%d\n",UTT,Popt,Pprintsw,Prow,Pcol,Px,Py,Plen,Pfgpal,Pbgpal);//~va6pR~//~vam0R~//~vbz5R~//~vbDsR~
#ifdef GTKPRINT                                                    //~vamfI~
	if ((Pprintsw & SPO_PRINT) && !Mpreviewmode)	//hcopy scrprint//~vamfR~
    {                                                              //~vamfI~
//  	drawtextstrGtk(Ppdc,Pprintsw,Px,Py,Ptext,Ppdbcs,Plen,Pfgpal,Pbgpal,Pdbcsctr,Prow,Pcol);//~vb4rR~
    	drawtextstrGtk(Popt,Ppdc,Pprintsw,Px,Py,Ptext,Ppdbcs,Plen,Pfgpal,Pbgpal,Pdbcsctr,Prow,Pcol);//~vb4rI~
    	return;                                                    //~vamfI~
    }                                                              //~vamfI~
#endif                                                             //~vamfI~
#ifdef UTF8UCS2                                                    //~va20I~
	optds=Pprintsw;                                                //~va20I~
	Pprintsw &=SPO_PRINT;                                          //~va20I~
    swutf8data=optds & SPO_DDFMT;                                  //~va20I~
    optusmsVhexDataCpos=(optds & SPO_VHEXDATACPOS) ? USMSO_VHEXDATACPOS : 0;	//x20//~vbDsI~
    SxxVhexDataCpos=0;                                             //~vbDsI~
    if (optusmsVhexDataCpos)                                       //~vbDsI~
        SxxVhexDataCpos=Px;                                        //~vbDsI~
//  swligaturemode= (Mligature^Mligaturereverse)  //ligature mode  //~vb4rR~
    swligaturemode= WXE_LIGATUREMODE(Popt)  //ligature mode        //~vb4rI~
   					&&  !(optds & SPO_NOLIGATURE);	 //not ligature disabled part//~va6pI~
    UTRACEP("%s:swligaturemode=%04x,Popt=%04x,optds=%04x\n",UTT,swligaturemode,Popt,optds);//~vbm5I~//~vbDhR~//~vbDsR~
#ifndef RRR                                                        //~vbAjI~
	int swLigatureExpand=0;                                        //~vbAjI~
#endif	//RRR                                                      //~vbAjI~
  if (swutf8data)                                                  //~va20I~
  {                                                                //~va20I~
#ifndef RRR                                                        //~vbAjI~
	swLigatureExpand=chkLigatureExpand(Popt,Pcol,Plen);            //~vbAjR~
#endif	//RRR                                                      //~vbAjI~
	opt=UTFDD2FO_ERRREP|UTFDD2FO_DBCSSPACEREP|UTFDD2FO_DUPREPCHK|UTFDD2FO_VIO;//~va20R~
    opt|=UTFDD2FO_SETDDDBCSALT;//     0x4000 //update dddbcs by altch//~vbArI~
    rc=xeutfcvdd2f(opt,Ptext,Ppdbcs,Plen,(UCHAR**)&ptext,&writelen,(UCHAR**)&pdbcs);//~va20R~
    if (rc)                                                        //~va20I~
    	return;                                                    //~va20R~
UTRACED("drawtextstr inp dddata",Ptext,Plen);                        //~va20I~//~vbkqR~
UTRACED("drawtextstr inp dddbcs",Ppdbcs,Plen);                       //~va20I~//~vbkqR~
UTRACED("drawtextstr out utf8",ptext,writelen);                    //~va20I~
UTRACED("drawtextstr out lcdbcs",pdbcs,Plen);                        //~va20I~//~vbkqR~
    pdddbcs=Ppdbcs; //dd fmt dbcs for ligature process             //~va30R~
    Ppdbcs=pdbcs;	//like setdbcstbl,set DBCS1ST and DBCS2ND and rep errch//~va20M~
    slno=0; //no dbcs padding                                      //~va20I~
    writelenlc=Plen;    //dd str len                               //~va20I~
    optusms=USMSO_DDFMT; //scr data is dd fmt                      //~va20R~
    optusms|=optusmsVhexDataCpos;                                  //~vbDsI~
    pdata=Ptext;	//ddfmt should not used,but safety for access vioration err//~va20R~
    swrtl=drawtextstr_chkrtl(0,ptext,writelen);                    //~va20I~
  }                                                                //~va20I~
  else                                                             //~va20I~
#endif                                                             //~va20I~
  {                                                                //~va20I~
UTRACED("drawtextstr",Ptext,Plen);                                 //~v69UI~
//  drawrepunprintable(Ptext,Ppdbcs,Plen);                         //~v79YI~//~va42R~
UTSSTART(tb2);                                                     //~v69VI~
//  ptext=g_locale_to_utf8(Ptext,Plen,&readlen,&writelen,&errpos); //~v69sR~
//  PRINTGERR("drawtextstr-g_locale_to_utf8",errpos);              //~v69sR~
//  ptext=csublocale2utf8(Ptext,Plen,0,&writelen);                 //~v69VR~
UTSSTART(tb);                                                      //~v69VI~
//  utfrc=csublocale2utf8(Ptext,Plen,0,&ptext,&writelen);          //~v79zR~
//  utfrc=csublocale2utf8(0/*source is locale encoding*/,Ptext,Plen,0,&ptext,&writelen);//~v79QR~
#ifdef UTF8SUPPH                                                   //~va1cR~
//    utfrc=csublocale2utf8scr(CSL2UO_REP0a0d/*rep 0a 0d by ?*/,Ptext,Ppdbcs,Plen,0,&ptextscr,&pdatascr,&pdbcsscr,&poffst,&writelen,&writelenlc,&slno);//~va6pR~
	opt=CSL2UO_REP0a0d/*rep 0a 0d by ?*/;                          //~va6pI~
    if (swligaturemode)                                            //~va6pI~
		opt=CSL2UO_LIGATURE;	//set no padding                   //~va6pI~
    utfrc=csublocale2utf8scr(opt,Ptext,Ppdbcs,Plen,0,&ptextscr,&pdatascr,&pdbcsscr,&poffst,&writelen,&writelenlc,&slno);//~va6pI~
    ptext=ptextscr;                                                //~va1cR~
    pdata=pdatascr;                                                //~va1cR~
    pdbcs=pdbcsscr;                                                //~va1cR~
//  if (!(Guviomopt2 & UVIOMO2_PADON))	//padding display?         //~va1cR~//~va1MR~
//  	slno=0;	//no padding display attr setting                  //~va1cR~//~va1MR~
#else                                                              //~va1cR~
    utfrc=csublocale2utf8(CSL2UO_REP0a0d/*rep 0a 0d by ?*/,Ptext,Plen,0,&ptext,&writelen);//~va1cR~
#endif                                                             //~va1cR~
UTSEND(tb,Setutf);                                                 //~v69VI~
//  if (!ptext)                                                    //~v69VR~
    if (utfrc>1)                                                   //~v69VI~
    	return;                                                    //~vXXEM~
  }//not dd fmt                                                    //~va20I~
//replace null-->space because pango_layout_set_text ingnore after null//~vXXEI~
//  if (pc=memchr(ptext,0,(UINT)writelen),pc)                      //~v69sR~
//  	for (pce=ptext+writelen;pc<pce;pc++)                       //~v69sR~
//      	if (!*pc)                                              //~v69sR~
//          	*pc=' ';	                                       //~v69sR~
	if (Pprintsw)	//previewmode                                  //~vXXEI~
    {                                                              //~vXXEI~
#ifndef NOPRINT                                                    //~vam0I~
    	uprtscrtextout(ptext,Px,Py,writelen);                      //~vXXEI~
//      dprintf("preview prtscr=%s",ptext);                        //~vX03R~
#else                                                              //~vam0I~
		;                                                          //~vam0I~
#endif                                                             //~vam0I~
    }                                                              //~vXXEI~
    else                                                           //~vXXEI~
    {                                                              //~vXXEI~
	  if (Pfgpal & WXE_SYNTAXRGB)                                  //~v780I~
        pfg=Gxxesynpalette+(Pfgpal&0x0f);                          //~v780I~
      else                                                         //~v780I~
    	pfg=Gxxepalette+Pfgpal;                                    //~vXXER~
#ifdef UTF8SUPPH                                                   //~va1cR~
		if (slno)                                                  //~va1cR~
        {                                                          //~va1cR~
		  	if (Pfgpal & WXE_SYNTAXRGB)                            //~va1cR~
        		pfgpad=Gxxesynpalette+UVIOM_PADATTR;               //~va1cR~
      		else                                                   //~va1cR~
    			pfgpad=Gxxepalette+UVIOM_PADATTR;                  //~va1cR~
        }                                                          //~va1cR~
        else                                                       //~vaffI~
            pfgpad=pfg; //not used when slno=0 but for uninit warning//~vaffI~
#endif                                                             //~va1cR~
	  if (Pbgpal & WXE_SYNTAXRGB)                                  //~v780I~
        pbg=Gxxesynpalette+(Pbgpal&0x0f);                          //~v780I~
      else                                                         //~v780I~
    	if (Pbgpal)                                                //~vXXER~
        	pbg=Gxxepalette+Pbgpal;                                //~vXXER~
    	else                                                       //~vXXER~
        	pbg=&(Gcolordata.CDcolor);                             //~vXXER~
    	pgc=Gpgc;                                                  //~vXXER~
UTRACEP("%s:pos=y=%d,x=%d,bg=0x%x,fg=0x%x\n",UTT,Py,Px,*pbg,*pfg);            //~va1cR~//~vbAeR~
UTRACED("drawtextstr",ptext,writelen);                             //~va1cR~
#ifndef OPTGTK3                                                    //~var8R~
#else   //OPTGTK3                                                  //~var8R~
        UTRACEP("%s:call csub_layout_set_textcolor fg=%s,bg=%s\n",UTT,csub_GdkColorToString(pfg),csub_GdkColorToString(pbg));//~vbzbI~
		csub_layout_set_textcolor(Gplayout,pfg,pbg);//setattr refresh layout lines//~var8R~
#endif                                                             //~var8R~
//dprintf("drawtextstr plen=%d,len=%d,%*.*s\n",Plen,writelen,writelen,writelen,ptext);//~v69VR~
#ifdef UTF8SUPPH                                                   //~va1cR~
//    	if (UTF_COMBINEMODE())                                     //~va30R~//~vbkqR~
		if (swcombinemodeline)    //COMBINEMODE(Popt)              //~vbkqI~
        	optusms|=USMSO_COMBINEON;	//parm to also draw ligature//~va30R~
    	else                                                       //~va30R~
        	optusms|=USMSO_COMBINEOF;                              //~va30R~
        pfgorg=pfg;                                                //~va1cR~
      for (oldoffsu8=0,oldoffslc=0,xx=Px,reslen=writelenlc;reslen>0;)//~va1cR~
      {	//padding attr setting                                     //~va1cR~
        pfg=pfgorg;                                                //~va1cR~
UTRACEP("drawtextstr reslen=%d,slno=%d\n",reslen,slno);            //~va1DI~
		if (slno)                                                  //~va1cR~
        {                                                          //~va1cR~
            offsu8=*poffst++;                                      //~va1cR~
            offslc=*poffst++;                                      //~va1cR~
	        padlen=((offsu8 & 0x8000)!=0)+1;	//2 for gb4,1 for ss3//~va1cR~
            offsu8&=0x7fff;                                        //~va1cR~
            writelen=offsu8-oldoffsu8;                             //~va1cR~//~va7GR~
            writelenlc=offslc-oldoffslc;                           //~va1cR~//~va7GR~
//    	    oldoffsu8=offsu8+padlen;                               //~va7GR~
      	    oldoffsu8=offsu8;                                      //~va7GI~
          	oldoffslc=offslc+padlen;                               //~va1cR~
            reslen-=writelenlc+padlen;                             //~va1cR~
            slno--;                                                //~va1cR~
        }                                                          //~va1cR~
        else                                                       //~va1KI~
        {                                                          //~va1KI~
	        padlen=0;                                              //~va1KI~
            reslen-=writelenlc;                                    //~va1KI~
        }                                                          //~va1KI~
UTRACEP("drawtextstr2 reslen=%d,slno=%d\n",reslen,slno);           //~va1KI~
       for (jj=0;jj<2;jj++)                                        //~va1cR~
       {                                                           //~va1cR~
UTRACEP("drawtextstr jj=%d,paddlen=%d,reslen=%d,slno=%d,writelen=%d,writelenlc=%d\n",jj,padlen,reslen,slno,writelen,writelenlc);//~va1DI~
#endif                                                             //~va1cR~
UTSSTART(tb);                                                      //~v69VI~
//      int expandLigature=0;                                      //~vbAfR~
    	pango_layout_set_text(Gplayout,ptext,writelen);            //~vXXER~
UTSEND(tb,Settext);                                                //~v69VI~
		UTRACED("drawtextstr pango settext",ptext,writelen);       //~va6nR~
// if (swutf8data                    //utf8 file                   //~va6pR~
// &&  (Mligature^Mligaturereverse)  //ligature mode               //~va6pR~
// &&  !(optds & SPO_NOLIGATURE)     //not ligature disabled part  //~va6pR~
// )                                                               //~va6pR~
// if (swligaturemode)                                             //~va6pI~//~vbkqR~
   if (swligaturemode||swrtl)                                      //~vbkqI~
   {                                                               //~va3iI~
    UTRACEP("%s:drawtextstr ligature mode xx=%d\n",UTT,xx);                         //~va6pI~//~vamfR~//~vbAeR~
    if (swutf8data                                                 //~vb4AR~
//  &&  !COMBINEMODE(Popt))  //split or unpr                       //~vb4AR~//~vbknR~
    &&  !swcombinemodeline)  //split or unpr                       //~vbknI~
      if (!UTF_COMBINEMODE_NP())                                   //~vbm2R~
      	drawtextstr_ligatureu8_SCM(optusms,Ppdc,pgc,xx,Py,pfg,pbg,ptext,writelen,pdata,pdddbcs,pdbcs,writelenlc);//~vbm2I~
      else                                                         //~vbm2I~
      	drawtextstr_ligatureu8_nocombine(optusms,Ppdc,pgc,xx,Py,pfg,pbg,ptext,writelen,pdata,pdddbcs,pdbcs,writelenlc);//~vb4AR~
    else                                                           //~vb4AR~
    {                                                              //~vb4AR~
//    if (!swutf8data||!drawtextstr_ligatureu8_chkcombinesplit(optusms,Ppdc,pgc,xx,Py,pfg,pbg,ptext,writelen,pdata,pdddbcs,pdbcs,writelenlc))//draw combining char at top of str//~vbmcR~//~vbAfR~
//    if (!swutf8data||!(expandLigature=drawtextstr_ligatureu8_chkcombinesplit(optusms,Ppdc,pgc,xx,Py,pfg,pbg,ptext,writelen,pdata,pdddbcs,pdbcs,writelenlc)))//draw combining char at top of str//~vbAfR~
      if (!swutf8data||!drawtextstr_ligatureu8_chkcombinesplit(optusms,Ppdc,pgc,xx,Py,pfg,pbg,ptext,writelen,pdata,pdddbcs,pdbcs,writelenlc))//draw combining char at top of str//~vbAfI~
      {                                                            //~vbmcI~
#ifndef RRR                                                        //~vbAjI~
	int ligExpand=0;                                               //~vbAjI~
   if (swLigatureExpand)  //last string followed space(+EOL) only  //~vbAjR~
   {                                                               //~vbAjI~
    int layoutlen=csubGetLayoutTextLen(0,Gplayout);                //~vbAjI~
    ligExpand=layoutlen-writelenlc*Mcellw;                         //~vbAjI~
   }                                                               //~vbAjI~
   if (ligExpand>0)                                                //~vbAjR~
   {                                                               //~vbAjI~
  	UTRACEP("%s:ligexpand=%d,oldxx=%d,newxx=%d,writelenlc=%d,Mcellw=%d\n",UTT,ligExpand,xx,xx+ligExpand,writelenlc,Mcellw);//~vbAjR~
    gdk_draw_layout_with_colors(Ppdc,pgc,xx,Py,Gplayout,pfg,pbg);  //~vbAjI~
	ScolExpandLigatureEOL+=(ligExpand+Mcellw-1)/Mcellw;	//strput(drawtextstr), use it once after set//~vbAjR~
    xx+=ligExpand;                                                 //~vbAjI~
   }                                                               //~vbAjI~
   else                                                            //~vbAjI~
#endif //RRR                                                       //~vbAjI~
   {                                                               //~vbAjI~
//	usetmonospace_ligature(optusms,Gplayout,pdata,pdbcs,writelenlc,Mcellw);//~vb4rR~
  	usetmonospace_ligature(optusms,Gplayout,pdata,pdbcs,writelenlc,Mcellw,0/*strwidth=xx*/);//~vb4rI~
    gdk_draw_layout_with_colors(Ppdc,pgc,xx,Py,Gplayout,pfg,pbg);  //~va3iI~
   }                                                               //~vbAjI~
      }                                                            //~vbmcI~
    }                                                              //~vb4AR~
   }                                                               //~va3iI~
   else	//not ligature mode write                                  //~va3iI~
   {                                                               //~va3iI~
   	if (swutf8data)	                                               //~vbkqI~
    {                                                              //~vbkqI~
      	xx+=drawtextstr_NoLigatureu8_SCM(optusms,Ppdc,pgc,xx,Py,pfg,pbg,ptext,writelen,pdata,pdddbcs,pdbcs,writelenlc);//SCM consideration//~vbkqR~
    }                                                              //~vbkqI~
    else                                                           //~vbkqI~
    {                                                              //~vbkqI~
//  	swwidth0Ovf=swutf8data && !swcombinemodeline && xxescr_chkWidth0Ovf(optusms,pdata/*dddata*/,pdddbcs,writelenlc);//~vbknR~//~vbkvR~
    	swwidth0Ovf=swutf8data && !swcombinemodeline && xxescr_chkWidth0Ovf(0,pdata/*dddata*/,pdddbcs,writelenlc);//~vbkvI~
    if (swwidth0Ovf)                                               //~vbknI~
      	drawtextstr_NoLigatureu8_NoCombine(optusms,Ppdc,pgc,xx,Py,pfg,pbg,ptext,writelen,pdata,pdddbcs,pdbcs,writelenlc);//~vbknI~
    else                                                           //~vbknI~
    {//!width0Ovf                                                  //~vbknI~
//     	swligature=xxescr_chkligature(pdbcs,writelenlc);           //~va3bM~//~vbk6R~
     	swligature=xxescr_chkligature(pdbcs,writelenlc,&glyphctr,&ucsctr);//~vbk6I~
UTRACEP("chkligature %d Mmonospace=%d\n",swligature,Mmonospace);   //~var8R~
//        if (swligature) //ligature detected                      //~va3iR~
//          if (!(optds & SPO_NOLIGATURE))    //not ligature disabled part//~va3iR~
////          if (Mligature)          //dialog option allow ligature//~va3iR~
//            if (Mligature^Mligaturereverse)  //allow ligature    //~va3iR~
//            {                                                    //~va3iR~
////              Mlinedrawstat[Prow]|=LDS_LIGATURE;  //redraw csrline even if not updated//~va3iR~
//                swligature=0;   //no regature correction         //~va3iR~
//            }                                                    //~va3iR~
//dprintf("ligature %d,opt=x%x\n",swligature,optds);                 //~va3bM~//~vbDsR~
                                                                   //~var8R~
    if (swligature)	//correct ligature to monospace                //~va30R~
    {                                                              //~va30R~
      if (swutf8data)                                              //~va30R~
	    drawtextstr_ligatureu8(optusms,Ppdc,pgc,xx,Py,pfg,pbg,ptext,writelen,pdata,pdbcs,writelenlc,pdddbcs);//~va30R~
      else                                                         //~va30R~
	    drawtextstr_ligature(optusms,Ppdc,pgc,xx,Py,pfg,pbg,ptext,writelen,pdata,pdbcs,writelenlc);//~va30R~
    }                                                              //~va30R~
    else                                                           //~va30R~
    {	//no ligature occurred                                     //~va30R~
//dprintf("drawtextstr @@@@;%s;\n",pango_layout_get_text(Gplayout));//~v69UR~
//dprintf("draw text row=%d,monospace=%d,Pdbcsctr=%d,Mcellw=%d,Mfontw=%d\n",Py,Mmonospace,Pdbcsctr,Mcellw,Mfontwidth);//~v69VR~
UTSSTART(tb);                                                      //~v69VI~
#ifdef AAA  //mono font is not mono for space char at fc4          //~v69VI~
        if (!(Mmonospace==1&&Mcellw==Mfontwidth))                  //~vX03I~
          if (!(!Pdbcsctr && Mmonospace && Mcellw==Mfontwidth))	//except (all sbcs and sbcs monospace and cellsz=fontsz)//~v69VI~
#endif                                                             //~v69VI~
//			usetmonospace(Gplayout,Ppdbcs,Plen,Mcellw);            //~v79zR~
#ifdef UTF8SUPPH                                                   //~va1cR~
//			usetmonospace(Gplayout,pdata,pdbcs,writelenlc,Mcellw); //~va1DR~
#ifdef AAA  //SCM consideration moved to drawtextstr_NoLigatureu8_SCM//~vbkqI~
        	if (glyphctr>ucsctr)                                   //~vbk6R~
  				optusms|=USMSO_SCM;	//may contain Spacing Combining Mark(glpthctr>1)//~vbk6M~
#endif //AAA                                                       //~vbkqI~
            if (optusms & USMSO_COMBINEON)   //scr combine mode    //~va30R~
            {                                                      //~vbk4I~
    			optusms|=USMSO_COMBINESP;    //widen width for the string if ligature occured//~va30R~
				if (swutf8data)                                    //~vbk4I~
//                	csub_setcombineLayout(0,Gplayout,Ptext,pdddbcs,Plen);//~vbk4I~//~vbk6R~
#ifdef AAA  //SCM consideration moved to drawtextstr_NoLigatureu8_SCM//~vbkqI~
                  	csub_setcombineLayout(optusms,Gplayout,Ptext,pdddbcs,Plen,glyphctr,glyphctr-ucsctr);//~vbk6R~
#else                                                              //~vbkqI~
                  	csub_setcombineLayout(optusms,Gplayout,Ptext,pdddbcs,Plen);//~vbkqI~
#endif //AAA                                                       //~vbkqI~
            }                                                      //~vbk4I~
    #ifdef UTF8UCS2                                                //~va20I~
  			usetmonospace(optusms,Gplayout,pdata,pdbcs,writelenlc,Mcellw);//~va20I~
    #else                                                          //~va20I~
  			usetmonospace(0,Gplayout,pdata,pdbcs,writelenlc,Mcellw);//~va1DI~
    #endif                                                         //~va20I~
#else                                                              //~va1cR~
  			usetmonospace(Gplayout,Ptext,Ppdbcs,Plen,Mcellw);      //~v79zI~
#endif                                                             //~va1cR~
		UTRACED("pango setmonospace",pdbcs,writelenlc);            //~va1cR~
UTSEND(tb,Setmono);                                                //~v69VI~
#ifdef UTF8SUPPH                                                   //~va1MR~
#ifdef UTF8UCS2                                                    //~va20I~
#ifdef AAA //rtl moved to before                                   //~vbkqI~
      if (swrtl)                                                   //~va20I~
      {                                                            //~va20I~
        swligature=1;                                              //~va20I~
	    drawtextstr_ligature(optusms,Ppdc,pgc,xx,Py,pfg,pbg,ptext,writelen,pdata,pdbcs,writelenlc);//~va20I~
      }                                                            //~va20I~
      else                                                         //~va20I~
#endif   //AAA                                                     //~vbkqI~
#endif                                                             //~va20I~
      {                                                            //~va20I~
#ifdef AAA                                                         //~va30R~
		swligature=0;                                              //~va1MR~
//    		pango_layout_get_extents(Gplayout,&recti,&rectl);      //~va1MR~
//  		UTRACEP("pango attr shape rectl x=%d,y=%d,w=%d,h=%d,cellw=%d\n",//~va1MR~
//    		rectl.x,rectl.y,rectl.width,rectl.height,Mcellw*writelenlc*PANGO_SCALE);//~va1MR~
//  	if (!Mligature			//disalog option dose not allow ligature//~va3dR~
//      if (!(Mligature^Mligaturereverse))  //not allow ligature   //~vb4rR~
        if (!WXE_LIGATUREMODE(Popt))  //not allow ligature         //~vb4rI~
    	&& Gxxestat & GXXES_FONTLIGATURE)                          //~va1MI~
        {                                                          //~va1MR~
    		pango_layout_get_extents(Gplayout,&recti,&rectl);          //~va1KR~//~va1MR~
  			UTRACEP("pango attr shape rectl x=%d,y=%d,w=%d,h=%d,cellw=%d\n",          //~va1KR~//~va1MR~
    		rectl.x,rectl.y,rectl.width,rectl.height,Mcellw*writelenlc*PANGO_SCALE);                     //~va1KR~//~va1MR~
  			UTRACEP("drawtextstr xx=%d,yy=%d,bg=%x,fg=%x\n",Px,Py,pbg,pfg);  //~va1KR~//~va1MR~
            boxwidth=Mcellw*(writelenlc-padlen)*PANGO_SCALE;	//ligature occured//~va1MR~
  			UTRACEP("drawtextstr padlen=%d,boxw=%d\n",padlen,boxwidth);//~va1MR~
            if (rectl.width<boxwidth)	//ligature occured         //~va1MR~
            {                                                      //~va1MR~
#ifdef UTF8UCS2                                                    //~va20I~
	        	drawtextstr_ligature(optusms,Ppdc,pgc,xx,Py,pfg,pbg,ptext,writelen,pdata,pdbcs,writelenlc);//~va20I~
#else                                                              //~va20I~
	        	drawtextstr_ligature(Ppdc,pgc,xx,Py,pfg,pbg,ptext,writelen,pdata,pdbcs,writelenlc);//~va1MR~
#endif                                                             //~va20I~
                swligature=1;                                      //~va1MR~
            }                                                      //~va1MR~
        }                                                          //~va1MR~
#endif //AAA                                                       //~va30R~
		UTRACELAYOUT(Gplayout);                                    //~va30R~
      }//!swrtl                                                    //~va20I~
#endif                                                             //~va1MR~
		UTRACEP("darwtextstr not ligature gdk_draw_layout_with_colors pos=%d,y=%d\n",xx,Py);//~vam4I~
UTSSTART(tb);                                                      //~v69VI~
#ifdef UTF8SUPPH                                                   //~va1cR~
	if (!swligature)                                               //~va1MR~
    {                                                              //~vbArI~
        UTRACEP("%s:call with_color jj=%d,slno=%d,pfg=%s,pbg=%s,pfgpad=%s\n",UTT,jj,slno,csub_GdkColorToString(pfg),csub_GdkColorToString(pbg),csub_GdkColorToString(pfgpad));//~vbArR~
      if (jj)   //padding                                          //~vbDhI~
        csubDrawLayoutTempColor(Ppdc,pgc,xx,Py,Gplayout,pfgpad,pfgorg,pbg); //draw by pfgpad ,then restore layout to pfgorg//~vbDhI~
      else                                                         //~vbDhI~
    	gdk_draw_layout_with_colors(Ppdc,pgc,xx,Py,Gplayout,pfg,pbg);//~va1cR~//~vbz9R~
    }                                                              //~vbArI~
//  	xxescr_drawlayout(Ppdc,pgc,xx,Py,Gplayout,pfg,pbg);        //~vbz9R~
#else                                                              //~va1cR~
    	gdk_draw_layout_with_colors(Ppdc,pgc,Px,Py,Gplayout,pfg,pbg);//~vXXER~//~vbz9R~
//  	xxescr_drawlayout(Ppdc,pgc,Px,Py,Gplayout,pfg,pbg);        //~vbz9R~
#endif                                                             //~va1cR~
    }	//no ligature occurred                                     //~va30R~
    }	//!width0Ovf                                               //~vbknI~
    }	//!swutf8file                                              //~vbkqI~
   }//not ligature mode wrire                                      //~va3iI~
//  	UTRACEP("pango color swligature=%d,xx=%d\n",swligature,xx);                        //~va1cR~//~vaffR~
UTSEND(tb,Setdraw);                                                //~v69VI~
#ifdef UTF8SUPPH                                                   //~va1cR~
		if (reslen<0)     //last may not end by padding            //~va1cR~
        	break;                                                 //~va1cR~
        ptext+=writelen;                                           //~va1cR~
        pdata+=writelenlc;                                         //~va1cR~
        pdbcs+=writelenlc;                                         //~va1cR~
        xx+=Mcellw*(writelenlc-padlen);	//advance by char width(drop adjust by padlen for pad write)//~va1cR~
     	UTRACEP("%s:newxx=%d\n",UTT,xx);                           //~vbAjI~
//      if (expandLigature>xx)	//advance by char width(drop adjust by padlen for pad write)//~vbAfR~
//      	xx=expandLigature;                                     //~vbAfR~
        UTRACEP("%s:xx=%d,padlen=%d,writelenlc=%d\n",UTT,xx,padlen,writelenlc);                                     //~va7GR~//~vbAfR~
		if (!padlen)     //last has no padding                     //~va1KI~
        	break;                                                 //~va1KI~
//      writelen=padlen;                                           //~va6nR~
        writelen=padlen*UTF8CHARLENERR1(*ptext);//Guviomdbcspad set by csublocaletoutf8 may not be ascii but ucs altchar//~va6nR~
      	oldoffsu8+=writelen;	//offsetlc is already updated      //~va7GI~
        writelenlc=padlen;                                         //~va1cR~
        padlen=0;	//no padding for padd write                    //~va1cR~
        pfg=pfgpad; //for padding                                  //~va1cR~
       }//org string and padding                                   //~va1cR~
		if (!slno)                                                 //~va1cR~
        	break;                                                 //~va1cR~
      }	//padding attr setting loop                                //~va1cR~
#endif                                                             //~va1cR~
//!printsw                                                         //~va30R~
    }                                                              //~vXXEI~
#ifndef UTF8SUPPH                                                  //~va1cR~
//if (ptext!=Ptext)	//converted by csyblocale2utf8                 //~v69VR~
#ifdef UTF8UCS2                                                    //~va20I~
 if (!swutf8data)                                                  //~va20I~
#endif                                                             //~va20I~
  if (!utfrc)       //converted by csyblocale2utf8                 //~v69VI~
    g_free(ptext);                                                 //~vXXEI~
#endif                                                             //~va1cR~
UTSEND(tb2,Setstr);                                                //~v69VI~
//UTRACEP("@@@ str=%d,utf=%d,mono=%d,text=%d,draw=%d\n",Setstr,Setutf,Setmono,Settext,Setdraw);//~v69VR~
    return;                                                        //~vXXEI~
}//drawtextstr                                                     //~vXXER~
#ifdef XXX                                                         //~vX03R~
//===============================================================================//~vX03I~
// monospace setting                                               //~vX03I~
//!!! glyph draw bypassed at gdk_draw_layout if shape attr is set,so use geomery setting(csub2)//~vX03I~
//===============================================================================//~vX03I~
void setlayoutattr(void)                                           //~vX03I~
{                                                                  //~vX03I~
    PangoAttrList  *ppal,*ppalo;                                   //~vX03I~
	PangoRectangle recti,rectl;                                    //~vX03M~
    PangoAttribute *ppa;                                           //~vX03M~
//********************                                             //~vX03I~
//  if (Gppangoattrlistscreen)  //may original by gtk              //~vX03I~
//  	pango_attr_list_unref(Gppangoattrlistscreen);              //~vX03I~
    ppalo=pango_layout_get_attributes(Gplayout);                   //~vX03I~
//dprintf("old attrlist=%p\n",ppalo);                              //~vX03R~
    if (!ppalo)                                                    //~vX03I~
    	ppal=pango_attr_list_new();                                //~vX03I~
    else                                                           //~vX03I~
    	ppal=ppalo;                                                //~vX03I~
//dprintf("new attrlist=%p\n",ppal);                               //~vX03R~
    pango_layout_get_extents(Gplayout,&recti,&rectl);              //~vX03I~
//dprintf("pango before shape recti x=%d,y=%d,w=%d,h=%d\n",        //~vX03R~
	recti.x,recti.y,recti.width,recti.height);                     //~vX03I~
//dprintf("pango before shape rectl x=%d,y=%d,w=%d,h=%d\n",        //~vX03R~
	rectl.x,rectl.y,rectl.width,rectl.height);                     //~vX03I~
//shape attr                                                       //~vX03I~
	recti.x=0;                                                     //~vX03M~
	recti.y=0;//-Mfontheight*PANGO_SCALE;                          //~vX03R~
	recti.width=Mfontwidth*PANGO_SCALE;                            //~vX03R~
	recti.height=Mfontheight*PANGO_SCALE;                          //~vX03M~
	rectl.x=0;                                                     //~vX03M~
	rectl.y=0;//-Mcellh*PANGO_SCALE;                               //~vX03R~
	rectl.width=Mcellw*PANGO_SCALE;                                //~vX03R~
	rectl.height=Mcellh*PANGO_SCALE;                               //~vX03R~
    ppa=pango_attr_shape_new(&recti,&rectl);                       //~vX03M~
//dprintf("pango  shape new recti x=%d,y=%d,w=%d,h=%d\n",          //~vX03R~
	recti.x,recti.y,recti.width,recti.height);                     //~vX03I~
//dprintf("pango shape new rectl x=%d,y=%d,w=%d,h=%d\n",           //~vX03R~
	rectl.x,rectl.y,rectl.width,rectl.height);                     //~vX03I~
    ppa->start_index=0;         //start byte offset                //~vX03M~
    ppa->end_index=G_MAXINT;    //end                              //~vX03M~
//  pango_attr_list_change(ppal,ppa);  //@@@@                      //~vX03R~
                                                                   //~vX03I~
//font attr                                                        //~vX03R~
    ppa=pango_attr_font_desc_new(Gfontdata[0].FDfontdesc);         //~vX03I~
    ppa->start_index=0;         //start byte offset                //~vX03I~
    ppa->end_index=G_MAXINT;    //end                              //~vX03I~
    pango_attr_list_change(ppal,ppa);                              //~vX03R~
                                                                   //~vX03I~
    Gppangoattrlistscreen=ppal;                                    //~vX03M~
    if (!ppalo)	                                                   //~vX03I~
        pango_layout_set_attributes(Gplayout,ppal); //monospacing  //~vX03I~
    pango_layout_get_extents(Gplayout,&recti,&rectl);              //~vX03I~
//dprintf("pango after shape recti x=%d,y=%d,w=%d,h=%d\n",         //~vX03R~
	recti.x,recti.y,recti.width,recti.height);                     //~vX03M~
//dprintf("pango after shape rectl x=%d,y=%d,w=%d,h=%d\n",         //~vX03R~
	rectl.x,rectl.y,rectl.width,rectl.height);                     //~vX03M~
}                                                                  //~vX03I~
#endif                                                             //~vX03R~
//===============================================================================//~v003I~
// screen font                                                     //~vXXER~
//===============================================================================//~v003I~
int  xxemain_createfont()                                          //~vXXER~
{                                                                  //~v003I~
	int oldh,oldw;                                                 //~v69UI~
//************************************                             //~v003I~
	oldh=Mcellh;                                                   //~v69UI~
	oldw=Mcellw;                                                   //~v69UI~
	ugetfontmetrics(Gfontdata[0].FDfontdesc,&Mfontwidth,&Mfontheight,&Mmonospace);//~vXXER~
    if (Mcellh0)                                                   //~vX03M~
    	Mcellh=Mcellh0;                                            //~vX03M~
    else                                                           //~vX03M~
    	Mcellh=Mfontheight;                                        //~vX03M~
    if (Mcellw0)                                                   //~vX03M~
    	Mcellw=Mcellw0;                                            //~vX03M~
    else                                                           //~vX03M~
    	Mcellw=Mfontwidth;                                         //~vX03M~
	if (Mfontheight<Mcellh-DEF_TEXTCSR_HEIGHT)                     //~vXXEI~
    {                                                              //~vXXEI~
        Mfontoffsy=(Mcellh-DEF_TEXTCSR_HEIGHT-Mfontheight);        //~vXXEI~
//      Mfontheight=Mcellh-Mfontoffsy;                             //~vXXER~
    }                                                              //~vXXEI~
    else                                                           //~vXXEI~
    	Mfontoffsy=0;                                              //~vXXEI~
    if (Mfontwidth<Mcellw)                                         //~vXXEI~
    	Mfontoffsx=(Mcellw-Mfontwidth)/2;                          //~vXXER~
    else                                                           //~vXXEI~
    	Mfontoffsx=0;                                              //~vXXEI~
//setup for monospace                                              //~vX03I~
    UTRACEP("%s:create font name=%s,w=%d,h=%d,Mfontoffsx=%d,Mfontoffsy=%d\n",UTT,Gfontdata[0].FDfontname,Mfontwidth,Mfontheight,Mfontoffsx,Mfontoffsy);//~vX03R~//~vbz9R~
#ifdef XXX                                                         //~vX03I~
    setlayoutattr();                                               //~vX03R~
#else                                                              //~vX03I~
    pango_layout_set_font_description(Gplayout,Gfontdata[0].FDfontdesc);//~vX03R~
    UTRACEP("xxemain_createfont pango_layout_set_font_description Gplayout=%p,fontdesc[0]=%p\n",Gplayout,Gfontdata[0].FDfontdesc);//~vameR~//~vamfR~
#endif                                                             //~vX03I~
    UTRACEP("create font old w=%d,h=%d new w=%d,h=%d,desc=%p\n",oldw,oldh,Mcellw,Mcellh,Gfontdata[0].FDfontdesc);//~var8R~
	if (oldh!=Mcellh||oldw!=Mcellw)	//col/row may chnged           //~v69UI~
    	usetresizehint(Mcellw,Mcellh,Mscrcmaxcol,Mscrcmaxrow);     //~v69VR~
    xxe_setsynfontface();                                          //~v780I~
	return 0;                                                      //~v003I~
}//xxemain_createfont                                              //~v69UR~
//===============================================================================//~v780I~
// change font                                                     //~v780I~
//===============================================================================//~v780I~
//int  xxemain_setfont(int Pcase)                                    //~v780I~//~vameR~
int  xxemain_setfont(int Pcase,int Pprintsw)                       //~vameR~
{                                                                  //~v780I~
    PangoFontDescription *pfd;                                     //~v780I~
//************************************                             //~v780I~
    UTRACEP("xxemain_setfont case=%d,printsw=%d\n",Pcase,Pprintsw);//~vameR~
#ifdef GTKPRINT                                                    //~vameI~
#else                                                              //~vameI~
	if (Pprintsw)                                                  //~vameI~
    	return 0;	//gnomeprin use gliph list and no font change by syntak case//~vameI~
#endif                                                             //~vameI~
	pfd=Gfontdata[0].FDfontdesc;                                   //~v780I~
	if (Pcase>=0                                                   //~v780R~
    &&  Pcase!=WXEFONTSTYLE_NOSYNTAX //not syntax highlight part   //~v780R~
	&&  Gsynfontdesc[Pcase])                                       //~v780I~
		pfd=Gsynfontdesc[Pcase];                                   //~v780I~
//  dprintf("set font case=%d\n",Pcase);                           //~v78BR~
//  dprintf("syn font toring=%s\n",pango_font_description_to_string((const PangoFontDescription*)(pfd)));//~v78BR~
#ifdef GTKPRINT                                                    //~vameR~
  if (Pprintsw)                                                    //~vameI~
  {                                                                //~vameI~
	pango_layout_set_font_description(GplayoutGtkPrintScr,pfd);    //~vameR~
    UTRACEP("xxemain_setfont pango_layout_set_font_description GplayoutGtkPrintScr=%p,pfd=%p,[0]=%p\n",GplayoutGtkPrintScr,pfd,Gfontdata[0].FDfontdesc);//~vameR~//~vamfR~
  }                                                                //~vameI~
  else                                                             //~vameI~
#endif	//GTKPRINT                                                 //~vameI~
  {                                                                //~vameI~
	pango_layout_set_font_description(Gplayout,pfd);               //~v780I~
    UTRACEP("xxemain_setfont pango_layout_set_font_description Gplayout=%p,pfd=%p,[0]=%p\n",Gplayout,pfd,Gfontdata[0].FDfontdesc);//~vameI~//~vamfR~
  }                                                                //~vameI~
	return 0;                                                      //~v780I~
}//xxemain_setfont                                                 //~v780I~
//===============================================================================//~2901I~
//                                                                 //~2901I~
//===============================================================================//~2901I~
void xxemain_scrinvalidate(int Popt)                               //~vXXER~
{                                                                  //~vXXER~
//************************************                             //~2901I~
    if (Mwxeintf.WXEIxetermsw)	//xe term called already           //~v78DI~
    	return;                                                    //~v78DI~
dprintf("scrinvalidate opt=%d \n",Popt);                           //~v69UR~
    if (Popt & SCRINVO_FULLDRAW)                                   //~vXXER~
		Mfulldrawsw=1;	//reset                                    //~vXXEI~
	xxemain_draw();                                                //~vXXEI~
    if (Popt & SCRINVO_SYNCEXPOSE)                                 //~vXXEI~
    	uinvalidate(UINVO_SYNC);	//direct draw                  //~vXXER~
    else                                                           //~vXXEI~
		uinvalidate(0);	//queue request                            //~vXXER~
#ifndef OPTGTK3                                                    //~var8R~
    scrruler(Mwxeintf.WXEIcsrposy,Mwxeintf.WXEIcsrposx);           //~v78BI~
    scrcsr();                                                      //~v78DR~
#else   //OPTGTK3                                                  //~var8R~
//*direct draw ruler and csr to widget from gxview_draw            //~var8R~
#endif                                                             //~var8R~
    return;                                                        //~2901I~
}//xxemain_scrinvalidate                                           //~vXXER~
//===============================================================================//~2922I~
//                                                                 //~2922I~
//===============================================================================//~2922I~
void xxemain_onsetfocus(void)                                      //~v69dR~
{                                                                  //~2922I~
    struct timeb ctm;                                              //~v69dR~
//*********************                                            //~v682I~
dprintf("xxemain_onsetfocus\n");                                   //~var8R~
//    if (Mxeinitsw)      	    //xe init called                   //~v69dR~
//		uredrawcaret();                                            //~v69dR~
//  Mswkillfocus=0;             //by frame window clicked          //~v63rR~
//  ftime(&ctm);		//chk later lbdown                         //~v69dR~//~vbs1R~
    uftime(&ctm);		//chk later lbdown                         //~vbs1I~
	Msetfocustime=ctm.time;		//chk later lbdown                 //~v63rI~
	Msetfocusmsec=ctm.millitm;		//chk later lbdown             //~v63rI~
    return;                                                        //~2922I~
}//xxemain_onsetfocus                                              //~v69dR~
//===============================================================================//~2922I~
//                                                                 //~2922I~
//===============================================================================//~2922I~
void xxemain_onkillfocus(void)                                     //~v69dR~
{                                                                  //~2922I~
//************************************                             //~2922I~
dprintf("xxemain_onkillfocus\n");                                  //~var8R~
//  if (Mxeinitsw)      	    //xe init called                   //~v69dR~
//  	DestroyCaret();                                            //~v69dR~
    Mswkillfocus=1;             //ignore 1st click after kill focus//~v63rI~
    return;                                                        //~2922I~
}//onkillfocus                                                     //~2922I~
//===============================================================================//~3102I~
//End command by popup menu                                        //~3102I~
//===============================================================================//~3102I~
int xxemain_scrend(void)                                           //~vXXER~
{                                                                  //~3102I~
    return xxemain_scrcmd(WXEOF_END,"");                           //~vXXER~
}//scrend                                                          //~3102I~
//===============================================================================//~3102I~
//Cancel command by popup menu                                     //~3102I~
//===============================================================================//~3102I~
int xxemain_scrcancel(void)                                        //~vXXER~
{                                                                  //~3102I~
    return xxemain_scrcmd(WXEOF_CANCEL,"");                        //~vXXER~
}//scrcancel                                                       //~3102I~
//===============================================================================//~3102I~
//End command by popup menu                                        //~3102I~
//===============================================================================//~3102I~
int xxemain_scrcmd(int Pfuncid,char *Pparm)                        //~vXXER~
{                                                                  //~3102I~
    int rc;                                                        //~3102I~
//************************************                             //~3102I~
    rc=wxe_otherfunc(Pfuncid,Pparm);                               //~3102R~
    if (rc==-1)                                                    //~3102I~
    	exitmain();                                                //~3102I~
	xxemain_scrinvalidate(0);                                      //~vXXER~
    return rc;                                                     //~3102R~
}//xxemain_scrcmd                                                  //~vXXER~
//===============================================================================//~v51wI~
//exlorler(nautilus) kick                                          //~vXXER~
//===============================================================================//~v51wI~
int xxemain_scrstrcmd(char *Pcmd,char *Pparm)                      //~vXXER~
{                                                                  //~v51wI~
    int rc;                                                        //~v51wI~
//************************************                             //~v51wI~
    rc=wxe_strcmd(Pcmd,Pparm);                                     //~v51wI~
    if (rc==-1)                                                    //~v51wI~
    	exitmain();                                                //~v51wI~
	xxemain_scrinvalidate(0);                                      //~vXXER~
    return rc;                                                     //~v51wI~
}//xxemain_scrstrcmd                                               //~vXXER~
//===============================================================================//~v55uI~
//open by application                                              //~v55uI~
//===============================================================================//~v55uI~
int xxemain_onfileopenwith(void)                                   //~vXXER~
{                                                                  //~v55uI~
    int rc;                                                        //~v55uI~
//************************************                             //~v55uI~
    rc=wxe_onfileopenwith();                                       //~v55uI~
    if (!rc)                                                       //~v55uI~
	    xxemain_scrinvalidate(0);                                  //~vXXER~
    return rc;                                                     //~v55uI~
}//onfileopenwith                                                  //~v55uI~
//===============================================================================//~vXXEI~
//display preedit string                                           //~vXXER~
//===============================================================================//~vXXEI~
int xxemain_scrpreedit(char *Pstr,int Plen,int Pcsrpos)            //~vXXEI~
{                                                                  //~vXXEI~
//static int Smaxtextlen,Ssplitlen;                                //~v79DR~
static int Smaxtextlen;                                            //~v79DI~
void  scrpreeditbrush(RECT *Pprect);                               //~vXXER~
//int   scrpreedittext(RECT *Pprect,char *Pstr,int Plen);          //~v79DR~
int scrpreedittext(RECT *Pprect,char *Pstr,int Plen,int Putflen,int Pcsrpos,int *Ppoutcharcnt);//~v79DR~
//  int row,col,len,writelen,textlen,maxlinech,splitlen;           //~v79DR~
    int row,col,len,writelen,textlen,maxlinech;                    //~v79DI~
    RECT rect;                                                     //~vXXER~
    char *pstr;                                                    //~vXXEI~
    int utflen,charcnt,strwidth,csrpos;                            //~v79DR~
//************************************                             //~vXXEI~
  dprintf("scrpreedit str=%s,len=%d,csrpos=%d,Smaxtextlen=%d\n",Pstr,Plen,Pcsrpos,Smaxtextlen);//~v79DR~
//  if (Plen+Ssplitlen>Smaxtextlen)	//to clear pre-edit area when backspace used//~v79DR~
//  	Smaxtextlen=Plen+Ssplitlen;                                //~v79DR~
//  if (strwidth+Ssplitlen>Smaxtextlen)	//to clear pre-edit area when backspace used//~v79DR~
//  	Smaxtextlen=strwidth+Ssplitlen;                            //~v79DR~
    row=Mwxeintf.WXEIcsrposy;                                      //~vXXEM~
    col=Mwxeintf.WXEIcsrposx;                                      //~vXXEM~
    if (!Plen)                                                     //~vXXEI~
    {                                                              //~vXXEI~
	    Smaxtextlen=0;	//to clear pre-edit area when backspace used//~vXXEI~
//      Ssplitlen=0;                                               //~v79DR~
		xxemain_scrinvalidate(0);	//clear preedit string         //~vXXEI~
//  	 dprintf("scrpreedit clear\n");                             //~vX03R~
        return 0;                                                  //~vXXEI~
    }                                                              //~vXXEI~
//bkg fill                                                         //~vXXEI~
//	textlen=Smaxtextlen;                                           //~v79DR~
    maxlinech=Mscrcmaxcol-col;                                     //~vXXER~
    utfgetstrwidth(0,Pstr,Plen,&len,0/*out utflen*/);              //~v79DI~
UTRACED("imepreedit str",Pstr,Plen);                               //~va1cR~
UTRACEP("ime str width=%d\n",len);                                 //~va1cR~
    dprintf("strwidth=%d\n",len);                                  //~v79DI~
    strwidth=len;                                                  //~v79DI~
    if (len>maxlinech)	//dbcs may be cut                          //~v79DI~
    {                                                              //~v79DI~
    	len=maxlinech;                                             //~v79DI~
	    utfgetstrwidth(UTCO_MAXCOL|UTCO_DBCSBACK/*get len before split dbcs*/,Pstr,Plen,&len,0);//~v79DI~
#ifdef UTF8SUPPH                                                   //~va1cR~
        len=strwidth+(maxlinech-len);	//fill space for fold space//~va1cR~
#else                                                              //~va1cR~
        len=strwidth+(len!=maxlinech);	//+1 if dbcs split         //~v79DI~
#endif                                                             //~va1cR~
    }                                                              //~v79DI~
    if (len>Smaxtextlen)	//to clear pre-edit area when backspace used//~v79DI~
   		Smaxtextlen=len;                                           //~v79DI~
	textlen=Smaxtextlen;	//brush width                          //~v79DI~
    dprintf("bkgd clear len=%dn",textlen);                         //~v79DI~
    for (;;)                                                       //~vXXEI~
    {                                                              //~vXXEI~
		INVALIDATE_LINE(row);		//flag line is updated to clear later//~vXXEI~
        len=min(textlen,maxlinech);                                //~v79zR~
dprintf("preedit Makerect len=%d,textlen=%d\n",len,textlen);       //~v79DR~
    	MAKE_TEXT_RECT(&rect,row,col,len);                         //~v79zR~
		scrpreeditbrush(&rect);                                    //~vXXER~
    	textlen-=len;                                              //~v79zR~
        if (textlen<=0)                                            //~v79zR~
        	break;                                                 //~vXXEI~
//      row++;                                                     //~vXXER~
//      if (row>=Mscrcmaxrow)                                      //~v79DR~
//      	break;                                                 //~v79DR~
        col=0;                                                     //~vXXEI~
        maxlinech=Mscrcmaxcol;                                     //~vXXER~
    }                                                              //~vXXEI~
//text fill                                                        //~vXXEI~
    row=Mwxeintf.WXEIcsrposy;                                      //~vXXEI~
    col=Mwxeintf.WXEIcsrposx;                                      //~vXXEI~
dprintf("csrposx=%d,Ppos=%d\n",col,Pcsrpos);                       //~v79DR~
//  textlen=Plen;                                                  //~v79DR~
    textlen=strwidth;                                              //~v79DI~
    maxlinech=Mscrcmaxcol-col;                                     //~vXXER~
    pstr=Pstr;                                                     //~vXXEI~
//  splitlen=0;                                                    //~v79DR~
	csrpos=Pcsrpos;                                                //~v79DI~
    for (;;)                                                       //~vXXEI~
    {                                                              //~vXXEI~
//      len=min(textlen,maxlinech);                                //~v79DR~
		len=maxlinech;	//right boundary                           //~v79DI~
	    utfgetstrwidth(UTCO_MAXCOL|UTCO_DBCSBACK,pstr,0,&len,&utflen);//~v79DI~
#ifdef UTF8SUPPH                                                   //~va1cR~
      if (!utflen)                                                 //~va1cR~
      {                                                            //~va1cR~
      	writelen=0;                                                //~va1cR~
        charcnt=0;                                                 //~va1cR~
      }                                                            //~va1cR~
      else                                                         //~va1cR~
#endif                                                             //~va1cR~
      {                                                            //~va1cR~
    	MAKE_TEXT_RECT(&rect,row,col,len);                         //~v79zR~
//  	writelen=scrpreedittext(&rect,pstr,len);                   //~v79DR~
    	writelen=scrpreedittext(&rect,pstr,len,csrpos,utflen,&charcnt);//~v79DR~
        if (!writelen)                                             //~vXXEI~
        	break;		//protect loop                             //~vXXEI~
      }                                                            //~va1cR~
//      if (writelen<len)   //dbcs splitted                        //~v79DR~
//          splitlen+=(len-writelen);                              //~v79DR~
    	textlen-=writelen;                                         //~vXXEI~
        csrpos-=charcnt;                                           //~v79DR~
dprintf("csrpos parm=%d,curr==%d,charcnt=%d\n",Pcsrpos,csrpos,charcnt);//~va1cR~
        if (textlen<=0)                                            //~vXXEI~
        	break;                                                 //~vXXEI~
//      pstr+=writelen;                                            //~v79DR~
        pstr+=utflen;                                              //~v79DR~
//      row++;                 //wrap in the line                  //~vXXER~
//      if (row>=Mscrcmaxrow)                                      //~vXXER~
//        	break;                                                 //~vXXER~
        col=0;                                                     //~vXXEI~
        maxlinech=Mscrcmaxcol;                                     //~vXXER~
    }                                                              //~vXXEI~
//  if (splitlen>Ssplitlen)                                        //~v79DR~
//      Ssplitlen=splitlen;                                        //~v79DR~
	uinvalidate(0);	//queue expose req                             //~vXXER~
    return 0;                                                      //~vXXEI~
}//xxemain_scrpreedit                                              //~vXXEI~
//===============================================================================//~vXXEI~
//draw preedit string text                                         //~vXXEI~
//===============================================================================//~vXXEI~
//int scrpreedittext(RECT *Pprect,char *Pstr,int Plen)             //~v79DR~
int scrpreedittext(RECT *Pprect,char *Pstr,int Plen,int Pcsrpos,int Putflen,int *Ppoutcharcnt)//~v79DR~
{                                                                  //~vXXEI~
	void  drawimtext(int Px,int Py,char *Pdata,int Plen);          //~vXXEI~
	char *pdata;                                                   //~vXXEI~
//  int ii,xx,yy,dbcssw,len,xxcell,writelen=0;                     //~v79DR~
    int ii,xx,yy,/*xxcell,*/writelen=0;                                //~v79DI~//~vaa7R~
    int charcnt,chklen,chwidth,right,rc,rlen,csrpos;               //~v79DR~
//************************************                             //~vXXEI~
dprintf("preedittext str=%s,width=%d,csrpos=%d,utflen=%d\n",Pstr,Plen,Pcsrpos,Putflen);//~v79DI~
    pdata=Pstr;                                                    //~vXXEI~
	xx=Pprect->left+Mfontoffsx;                                    //~vXXEI~
	yy=Pprect->top+Mfontoffsy;                                     //~vXXEI~
//  xxcell=Pprect->left;                                           //~vXXEI~//~vaa7R~
//if (Gudbcschk_flag & UDBCSCHK_UTF8)  //ja_JP.UTF-8               //~v79DR~
//{                                                                //~v79DR~
//  writelen=Plen;                                                 //~v79zR~
//  drawimtext(xx,yy,pdata,writelen);                              //~v79DR~
//}                                                                //~v79DR~
//else                                                             //~v79DR~
//{                                                                //~v79DR~
//  dbcssw=0;                                                      //~v79DR~
//  for (ii=0;ii<Plen;ii++,pdata++,xx+=Mcellw,xxcell+=Mcellw)      //~v79DR~
//  {                                                              //~v79DR~
//  	if (dbcssw)                                                //~v79DR~
//      {                                                          //~v79DR~
//      	dbcssw=0;                                              //~v79DR~
//          continue;                                              //~v79DR~
//      }                                                          //~v79DR~
//      if (udbcschk(*pdata))                                      //~v79DR~
//      {                                                          //~v79DR~
//          if (writelen+2>Plen)                                   //~v79DR~
//              break;                                             //~v79DR~
//      	dbcssw=1;                                              //~v79DR~
//  		drawimtext(xx,yy,pdata,2);                             //~v79DR~
//          len=2;                                                 //~v79DR~
//      }                                                          //~v79DR~
//      else                                                       //~v79DR~
//          len=1;                                                 //~v79DR~
//  	drawimtext(xx,yy,pdata,len);                               //~v79DR~
//      writelen+=len;                                             //~v79DR~
//  }                                                              //~v79DR~
//}                                                                //~v79DR~
    charcnt=0;                                                     //~v79DR~
    csrpos=0;                                                      //~v79DI~
    rlen=Putflen;                                                  //~v79DI~
    for (ii=0;ii<Plen;ii+=chwidth,pdata+=chklen,xx+=right,csrpos++)//~v79DI~
    {                                                              //~v79DI~
        rc=utfmb2wc(0,pdata,rlen,0/*out ucs*/,&chklen,&chwidth);   //~v79DI~
        right=Mcellw;                                              //~v79DI~
        if (!rc)                                                   //~v79DI~
        {                                                          //~v79DI~
            if (chwidth==2)   //dbcs                               //~v79DI~
            {                                                      //~v79DI~
                if (ii+1>=Plen)                                    //~v79DI~
                    break;                                         //~v79DI~
                right+=Mcellw;                                     //~v79DI~
            }                                                      //~v79DI~
            else                                                   //~v79DI~
#ifdef UTF8SUPPH                                                   //~va1cR~
            if (chwidth>UDBCSCHK_DBCSSZ)   //dbcs sz is 3 or 4     //~va1cR~
            {                                                      //~va1cR~
                if (ii+chwidth>Plen)                               //~va1cR~
                    break;                                         //~va1cR~
                right+=Mcellw*(chwidth-1);  //display by byte length//~va1cR~
            }                                                      //~va1cR~
            else                                                   //~va1cR~
#endif            	                                               //~va1cR~
            if (chwidth!=1)                                        //~v79DI~
                right=0;                                           //~v79DI~
        }                                                          //~v79DI~
		drawimtext(xx,yy,pdata,chklen);                            //~v79DI~
dprintf("im char write csrpos=%d,chklen=%d,xx=%d,chwidth=%d\n",csrpos,chklen,xx,chwidth);//~va1cR~
UTRACED("drwaimtext",pdata,chklen);                                //~va1cR~
        if (csrpos==Pcsrpos)    //intermediate by left arrow-key   //~v79DI~
        	drawimcsr(0,xx,yy);                                    //~v79DI~
        charcnt++;                                                 //~v79DR~
        rlen-=chklen;                                              //~v79DI~
        writelen+=chwidth;                                         //~v79DI~
    }                                                              //~v79DI~
  	if (csrpos==Pcsrpos)    //at string end                        //~v79DR~
  	{                                                              //~v79DR~
  		drawimcsr(0,xx,yy);                                        //~v79DR~
        dprintf("eos cursol pos=%d\n",csrpos);                     //~v79DR~
    }                                                              //~v79DR~
    *Ppoutcharcnt=charcnt;                                         //~v79DR~
    return writelen;                                               //~vXXER~
}//scrpreedittext                                                  //~vXXER~
//===============================================================================//~v79DR~
//draw im csursor                                                  //~v79DR~
//===============================================================================//~v79DR~
int drawimcsr(int Popt,int Pxx,int Pyy)                            //~v79DR~
{                                                                  //~v79DR~
    CPoint pt[2];                                                  //~v79DR~
//******************                                               //~v79DR~
    pt[0].x=Pxx;                                                   //~v79DR~
    pt[1].x=Pxx;                                                   //~v79DR~
    pt[0].y=Pyy;                                                   //~v79DR~
    pt[1].y=Pyy+Mcellh;                                            //~v79DR~
dprintf("drawimecsr xx=%d,yy=%d,cellh=%d\n",Pxx,Pyy,Mcellh);       //~v79DR~
    gdk_draw_lines(Gppixmap,Gpgcim,pt,2);   //vertical line        //~v79DR~
    return 0;                                                      //~v79DR~
}//drawimcsr                                                       //~v79DR~
//===============================================================================//~vXXEI~
//draw im text char                                                //~vXXEI~
//===============================================================================//~vXXEI~
void  drawimtext(int Px,int Py,char *Pdata,int Plen)               //~vXXEI~
{                                                                  //~vXXEI~
//  GError *errpos=NULL;                                           //~v69QR~
	char *ptext;                                                   //~vXXEI~
//	int utfrc,writelen;                                            //~v79DR~
  	int writelen;                                                  //~v79DI~
//****************************                                     //~vXXEI~
//dprintf("imtext write str=%s (%x),len=%d\n",Pdata,*Pdata,Plen);  //~vX03R~
//UTRACED("@@@drawimtext locale",Pdata,Plen);                      //~v69UR~
//  ptext=g_locale_to_utf8(Pdata,Plen,&readlen,&writelen,&errpos); //~v69QR~
//  PRINTGERR("drawimtext-g_locale_to_utf8",errpos);               //~v69QR~
//  ptext=csublocale2utf8(Pdata,Plen,0,&writelen);                 //~v69VR~
//  utfrc=csublocale2utf8(Pdata,Plen,0,&ptext,&writelen);          //~v79DR~
//  if (!ptext)                                                    //~v69VR~
//  if (utfrc>1)                                                   //~v79DR~
//  	return;                                                    //~v79DR~
#ifndef OPTGTK3                                                    //~var8R~
#else   //OPTGTK3                                                  //~var8R~
	csub_layout_set_textcolor(Gplayout,&Gimfgcolor,&Gimbgcolor);   //~var8R~
#endif                                                             //~var8R~
    ptext=Pdata;                                                   //~v79DI~
    writelen=Plen;                                                 //~v79DI~
UTRACEP("@@@drawimtext x=%d,y=%d\n",Px,Py);                        //~va1cR~
UTRACED("@@@drawimtext utf8",ptext,writelen);                      //~v69sR~
    pango_layout_set_text(Gplayout,ptext,writelen);                //~vXXEI~
//dprintf("imtext write utfstr=%s (%x),len=%d\n",ptext,*ptext,writelen);//~vX03R~
    gdk_draw_layout_with_colors(Gppixmap,Gpgcim,Px,Py,Gplayout,&Gimfgcolor,&Gimbgcolor);//~vXXEI~
//if (ptext!=Pdata)	//converted                                    //~v69VR~
//if (!utfrc)	//converted                                        //~v79DR~
//  g_free(ptext);                                                 //~v79DR~
    return;                                                        //~vXXEI~
}//drawimtext                                                      //~vXXEI~
//===============================================================================//~vXXEI~
//draw background rectangle                                        //~vXXEI~
//===============================================================================//~vXXEI~
void  scrpreeditbrush(RECT *Pprect)                                //~vXXER~
{                                                                  //~vXXEI~
    int xx,yy,hh,ww,xx2,yy2;                                       //~vXXER~
    GdkPoint points[4];                                            //~vXXEI~
//************************************                             //~vXXEI~
//brush box                                                        //~vXXEI~
    gdk_gc_set_foreground(Gpgcim,&Gimbgcolor);                     //~vXXER~
	xx=Pprect->left;                                               //~vXXEI~
	yy=Pprect->top;                                                //~vXXEI~
	xx2=Pprect->right-1;                                           //~vXXER~
	yy2=Pprect->bottom-1;                                          //~vXXER~
	ww=xx2-xx;                                                     //~vXXEI~
	hh=yy2-yy;                                                     //~vXXEI~
dprintf("Gpgcim=%p,Gppixmap=%p\n",Gpgcim,Gppixmap);                //~var8R~
dprintf("im brush xx=%d,yy=%d,ww=%d,hh=%d\n",xx,yy,ww,hh);         //~var8R~
#ifndef OPTGTK3                                                    //~var8I~
#else   //OPTGTK3                                                  //~var8I~
dprintf("im brush before draw_rect cairo_status=%d\n",cairo_status(Gpgcim));//~var8R~
#endif                                                             //~var8I~
    gdk_draw_rectangle(Gppixmap,Gpgcim,TRUE,xx,yy,ww,hh);          //~vXXER~
#ifndef OPTGTK3                                                    //~var8I~
#else   //OPTGTK3                                                  //~var8I~
dprintf("im brush after draw_rect cairo_status=%d\n",cairo_status(Gpgcim));//~var8R~
#endif                                                             //~var8I~
//lim                                                              //~vXXEI~
    points[0].x=xx;                                                //~vXXEI~
    points[0].y=yy;                                                //~vXXEI~
    points[1].x=xx2;                                               //~vXXEI~
    points[1].y=yy;                                                //~vXXEI~
    points[2].x=xx2;                                               //~vXXEI~
    points[2].y=yy2;                                               //~vXXEI~
    points[3].x=xx;                                                //~vXXEI~
    points[3].y=yy2;                                               //~vXXEI~
    gdk_gc_set_foreground(Gpgcim,&Gimfgcolor);                     //~vXXER~
    gdk_draw_lines(Gppixmap,Gpgcim,points,4);   //edge box         //~vXXEI~
	return;                                                        //~vXXEI~
}//scrpreeditbrush                                                 //~vXXER~
//===============================================================================//~vb4AR~
//write combining char by altch under UNICOMB SPLIT(from ligatureu8_SCM)/UNPR(from drawTextStr) and Ligature ON //~vb4AR~//~vbmfR~
//return string width                                              //~vb4AI~
//===============================================================================//~vb4AR~
int drawtextstr_ligatureu8_nocombine(int Popt,CDC *Ppdc,GdkGC *Ppgc,int Px,int Py,GdkColor *Ppfg,GdkColor *Ppbg,char *Ppu8,int Pu8len,char *Pdddata,char *Pdddbcs,char *Plcdbcs,int Pddlen)//~vb4AR~
{                                                                  //~vb4AR~
    int xx,len,reslen,optusms,stru8len,strlclen,strwidth;          //~vb4AR~
    int dbcsid,chsz,lenalt,lenu8;                                  //~vb4AR~
//  char *pdddbcs,*plcdbcs,*pu8,*pdddbcso,*plcdbcso,*pu8o;         //~vb4AR~//~vb5eR~
    char *pdddbcs,*plcdbcs,*pu8,          *plcdbcso,*pu8o;         //~vb5eI~
//  char wku8[8],wkdbcs[1]={0};                                    //~vb4AI~//~vbknR~
    char wku8[8],wkdbcs[2]={0,0};                                  //~vbknI~
//  GdkColor fgaltch={0,0/*r*/,0xffff/*g*/,0/*b*/};                //~vb4AR~//~vbA3R~
    GdkColor fgaltch=SfgPadding;                                   //~vbA3I~
    char *pdddata;                                                 //~vbknI~
    int swcombiningscm,ddlenalt;                                   //~vbmfI~
#ifndef KKK                                                        //~v7f4I~
    int swcombine;                                                 //~v7f4I~
	int optcic=CICO_RCNOCOMB;	//rc=8 for w0 no combine           //~v7f4I~
    int ucs;                                                       //~v7f4I~
#endif                                                             //~v7f4I~
//************************************                             //~vb4AR~
	UTRACEP("%s:opt=%04x,xx=%d,yy=%d,fg=%04x,bg=%04x\n",UTT,Popt,Px,Py,Ppfg,Ppbg);//~vb4AR~
	UTRACED("u8data",Ppu8,Pu8len);                                 //~vb4AR~
	UTRACED("dddata",Pdddata,Pddlen);                              //~vb4AR~
	UTRACED("dddbcs",Pdddbcs,Pddlen);                              //~vb4AR~
	UTRACED("lcdbcs",Plcdbcs,Pddlen);                              //~vb4AR~
    optusms=Popt;                                                  //~vb4AR~
    xx=Px;                                                         //~vb4AI~
    strlclen=0,stru8len=0;                                         //~vb4AI~
    pu8o=Ppu8,plcdbcso=Plcdbcs;                                    //~vb4AR~
    for (pu8=Ppu8,pdddbcs=Pdddbcs,plcdbcs=Plcdbcs,reslen=Pddlen;reslen>0;)//~vb4AI~
    {                                                              //~vb4AR~
    	pdddata=Pdddata+PTRDIFF(pdddbcs,Pdddbcs);                  //~vbknI~
        dbcsid=*pdddbcs;                                           //~vb4AI~
        if (!dbcsid)                                               //~vb4AI~
        {                                                          //~vb4AI~
    		len=umemspnc(pdddbcs,0,reslen);                        //~vb4AR~
        	strlclen+=len;                                         //~vb4AR~
        	stru8len+=len;                                         //~vb4AR~
            pu8+=len;                                              //~vb4AI~
            pdddbcs+=len;                                          //~vb4AI~
            plcdbcs+=len;                                          //~vb4AI~
            reslen-=len;                                           //~vb4AI~
        }                                                          //~vb4AI~
        else                                                       //~vb4AI~
#ifdef KKK                                                         //~v7f4I~
        if (UDBCSCHK_ISUCSWIDTH0(dbcsid))//combining char detected //~vb4AI~
#else                                                              //~v7f4I~
        if ((swcombine=csub_iscombining(optcic,pdddata,pdddbcs,reslen,&ucs,0/*ppshsz*/)))//~v7f4R~
#endif                                                             //~v7f4I~
        {                                                          //~vb4AI~
            if (stru8len)                                          //~vb4AI~
            {                                                      //~vb4AI~
                UTRACED("pango_layout_set_text pu8",pu8o,stru8len);//~vb4AI~
                pango_layout_set_text(Gplayout,pu8o,stru8len);     //~vb4AI~
                usetmonospace_ligature(optusms,Gplayout,pu8o,plcdbcso,strlclen,Mcellw,&strwidth);//~vb4AI~
                UTRACEP("%s:draw_layout_with_colors xx=%d,fg RGB=%04x,%04x,%04x\n",UTT,xx,Ppfg->red,Ppfg->green,Ppfg->blue);//~vb4AI~
                gdk_draw_layout_with_colors(Ppdc,Ppgc,xx,Py,Gplayout,Ppfg,Ppbg);//~vb4AI~
                xx+=strwidth;                                      //~vb4AI~
            }                                                      //~vb4AI~
            lenu8=UTF8CHARLEN(*pu8);                               //~vb4AI~
#ifndef OPTGTK3                                                    //~vb5iI~
#else   //OPTGTK3                                                  //~vb5iI~
      	  if ((Popt & USMSO_VHEXDATACPOS) && Px==SxxVhexDataCpos)  //~vbDsI~
          {                                                        //~vbDsI~
      		UTRACEP("%s:NoRep split combining color Px=%d,Ppfg=%s\n",UTT,Px,COLOR2STRING(Ppfg));//~vbDsI~
          }                                                        //~vbDsI~
          else                                                     //~vbDsI~
          {                                                        //~vbDsI~
   			UTRACEP("%s:call csub_layout_set_textcolor fg=%s,bg=%s\n",UTT,csub_GdkColorToString(&fgaltch),csub_GdkColorToString(Ppbg));//~vbzbI~//~vbDsM~
			csub_layout_set_textcolor(Gplayout,&fgaltch,Ppbg);//gdk_draw_layout_with_colors() ignore color parameter//~vb5iI~
          }                                                        //~vbDsI~
#endif                                                             //~vb5iI~
            if (UTF_COMBINEMODE_NP())                              //~vb4AI~
            {                                                      //~vb4AI~
#ifndef KKK                                                        //~v7f4I~
				int altch=getUcsAltchar(0,ucs);                    //~v7f4R~
            	lenalt=uccvucs2utf(altch,wku8);                    //~v7f4I~
#else                                                              //~v7f4I~
            	lenalt=uccvucs2utf(Gutfcombaltch,wku8);            //~vb4AI~
#endif                                                             //~v7f4M~
    	        UTRACED("combineNP pango_layout_set_text wku8",wku8,lenalt);//~vb4AI~
            	pango_layout_set_text(Gplayout,wku8,lenalt);       //~vb4AI~
//	            usetmonospace_ligature(optusms,Gplayout,wku8,wkdbcs,1,Mcellw,0/*strwidth:xx*/);//~vb4AI~//~vbkpR~
  	            usetmonospace_ligature(optusms,Gplayout,wku8,wkdbcs,1,Mcellw,&strwidth);//~vbkpI~
            	UTRACEP("%s:draw_layout_with_colors COMBINENP NPxx=%d,altfg RGB r=%04x,g=%04x,b=%04x\n",UTT,xx,fgaltch.red,fgaltch.green,fgaltch.blue);//~vbAhI~
				gdk_draw_layout_with_colors(Ppdc,Ppgc,xx,Py,Gplayout,&fgaltch,Ppbg);//~vbAhI~
            }                                                      //~vb4AI~
            else                                                   //~vb4AI~
            {                                                      //~vb4AI~
    	        UTRACED("combine SPLIT pango_layout_set_text pu8",pu8,lenu8);//~vb4AR~
//          	pango_layout_set_text(Gplayout,pu8,lenu8);         //~vb4AI~//~vbAhR~
//              usetmonospace_ligature(optusms,Gplayout,pu8,plcdbcs,1,Mcellw,0/*xx:strwidth*/);//~vb4AR~//~vbkpR~
#ifdef SSS                                                         //~vbkwI~
                usetmonospace_ligature(optusms,Gplayout,pu8,plcdbcs,1,Mcellw,&strwidth);//~vbkpI~
#else                                                              //~vbkwI~
//              usetmonospace_ligature(optusms|USMSO_SBCSCOMBSPLIT,Gplayout,pu8,plcdbcs,1,Mcellw,&strwidth); //split mode,chk 2 gliph and  2nd is width=0//~vbkwR~//~vbAhR~
#endif                                                             //~vbkwI~
				strwidth=drawSplitCombineLigature(optusms,Ppdc,Ppgc,xx,Py,&fgaltch,Ppbg,pu8,lenu8,plcdbcs,1);//~vbAhR~
	            UTRACEP("%s:draw_layout_with_colors xx=%d,altfg RGB r=%04x,g=%04x,b=%04x\n",UTT,xx,fgaltch.red,fgaltch.green,fgaltch.blue);//~vbAhI~
            }                                                      //~vb4AI~
//          gdk_draw_layout_with_colors(Ppdc,Ppgc,xx,Py,Gplayout,&fgaltch,Ppbg);//~vb4AI~//~vbAhR~
#ifndef OPTGTK3                                                    //~vb5iI~
#else   //OPTGTK3                                                  //~vb5iI~
      	  if ((Popt & USMSO_VHEXDATACPOS) && Px==SxxVhexDataCpos)  //~vbDsI~
          {                                                        //~vbDsI~
      		UTRACEP("%s:NoNeed to restore Ppfg color Px=%d,Ppfg=%s\n",UTT,Px,COLOR2STRING(Ppfg));//~vbDsI~
          }                                                        //~vbDsI~
          else                                                     //~vbDsI~
          {                                                        //~vbDsI~
   			UTRACEP("%s:call csub_layout_set_textcolor fg=%s,bg=%s\n",UTT,csub_GdkColorToString(Ppfg),csub_GdkColorToString(Ppbg));//~vbzbI~
			csub_layout_set_textcolor(Gplayout,Ppfg,Ppbg);//restore for not COMBINE NP/SPLIT//~vb5iI~
          }                                                        //~vbDsI~
#endif                                                             //~vb5iI~
//          xx+=Mcellw;                                            //~vb4AI~//~vbkpR~
            xx+=strwidth;                                          //~vbkpI~
        	strlclen=0;                                            //~vb4AI~
        	stru8len=0;                                            //~vb4AI~
            pu8+=lenu8;                                            //~vb4AI~
            pdddbcs++;                                             //~vb4AI~
            plcdbcs++;                                             //~vb4AI~
            reslen--;                                              //~vb4AI~
                                                                   //~vb4AI~
            pu8o=pu8;                                              //~vb4AI~
//          pdddbcso=pdddbcs;                                      //~vb4AI~//~vb5eR~
            plcdbcso=plcdbcs;                                      //~vb4AI~
        }                                                          //~vb4AI~
        else                                                       //~vb4AI~
//      if (csub_iswidth0(0,pdddata,pdddbcs,reslen,0/*Ppucs*/,0/*ppshsz*/)==2)//combining char(>=0x20000) detected//~vbknI~//~vbmfR~
        if (swcombiningscm=csub_iscombining(0,pdddata,pdddbcs,reslen,0/*Ppucs*/,0/*ppshsz*/),(swcombiningscm & (UICRC_OVF|UICRC_SCM)))//combining char(>=0x20000) or SCM(2cell) detected//~vbmfR~
        {                                                          //~vbknI~
            if (stru8len)                                          //~vbknI~
            {                                                      //~vbknI~
                UTRACED("pango_layout_set_text pu8",pu8o,stru8len);//~vbknI~
                pango_layout_set_text(Gplayout,pu8o,stru8len);     //~vbknI~
                usetmonospace_ligature(optusms,Gplayout,pu8o,plcdbcso,strlclen,Mcellw,&strwidth);//~vbknI~
                UTRACEP("%s:draw_layout_with_colors xx=%d,fg RGB=%04x,%04x,%04x\n",UTT,xx,Ppfg->red,Ppfg->green,Ppfg->blue);//~vbknI~
                gdk_draw_layout_with_colors(Ppdc,Ppgc,xx,Py,Gplayout,Ppfg,Ppbg);//~vbknI~
                xx+=strwidth;                                      //~vbknI~
            }                                                      //~vbknI~
            lenu8=UTF8CHARLEN(*pu8);                               //~vbknI~
#ifndef OPTGTK3                                                    //~vbknI~
#else   //OPTGTK3                                                  //~vbknI~
   			UTRACEP("%s:call csub_layout_set_textcolor fg=%s,bg=%s\n",UTT,csub_GdkColorToString(&fgaltch),csub_GdkColorToString(Ppbg));//~vbzbI~
			csub_layout_set_textcolor(Gplayout,&fgaltch,Ppbg);//gdk_draw_layout_with_colors() ignore color parameter//~vbknI~
#endif                                                             //~vbknI~
            if (UTF_COMBINEMODE_NP())                              //~vbknI~
            {                                                      //~vbknI~
//          	lenalt=uccvucs2utf(Gutfcombaltch,wku8);            //~vbknI~//~vbmfR~
//              wku8[lenalt++]=UVIOM_COMBINE_ALTCH2;               //~vbknR~//~vbmfR~
				lenalt=uviom_getcombaltchU8(UVIOM_GCAC_2CELL,wku8,0/*pdddata*/,0/*pdddbcs*/,&ddlenalt);//~vbmfI~
    	        UTRACED("combineNP pango_layout_set_text wku8",wku8,lenalt);//~vbknI~
            	pango_layout_set_text(Gplayout,wku8,lenalt);       //~vbknI~
//              usetmonospace_ligature(optusms,Gplayout,wku8,wkdbcs,2,Mcellw,&strwidth);//~vbknR~//~vbmfR~
	            usetmonospace_ligature(optusms,Gplayout,wku8,wkdbcs,ddlenalt,Mcellw,&strwidth);//~vbmfI~
            }                                                      //~vbknI~
            else                                                   //~vbknI~
            {                                                      //~vbknI~
//          	pango_layout_set_text(Gplayout,pu8,lenu8);         //~vbknR~
//              usetmonospace_ligature(optusms,Gplayout,pu8,plcdbcs,1,Mcellw,&strwidth);//~vbknR~
            	strncpy(wku8,pu8,sizeof(wku8)-1);                  //~vbknI~
                len=lenu8;                                         //~vbknI~
                wku8[len++]=UVIOM_COMBINE_ALTCH2;                  //~vbknI~
    	        UTRACED("combine SPLIT pango_layout_set_text pu8",wku8,len);//~vbknI~
              	pango_layout_set_text(Gplayout,wku8,len);          //~vbknI~
      			usetmonospace_ligature(optusms,Gplayout,wku8,wkdbcs,2,Mcellw,&strwidth);//~vbknR~
            }                                                      //~vbknI~
            UTRACEP("%s:draw_layout_with_colors xx=%d,altfg RGB r=%04x,g=%04x,b=%04x\n",UTT,xx,fgaltch.red,fgaltch.green,fgaltch.blue);//~vbknI~
            gdk_draw_layout_with_colors(Ppdc,Ppgc,xx,Py,Gplayout,&fgaltch,Ppbg);//~vbknI~
#ifndef OPTGTK3                                                    //~vbknI~
#else   //OPTGTK3                                                  //~vbknI~
   			UTRACEP("%s:call csub_layout_set_textcolor fg=%s,bg=%s\n",UTT,csub_GdkColorToString(Ppfg),csub_GdkColorToString(Ppbg));//~vbzbI~
			csub_layout_set_textcolor(Gplayout,Ppfg,Ppbg);//restore for not COMBINE NP/SPLIT//~vbknI~
#endif                                                             //~vbknI~
//          xx+=Mcellw;                                            //~vbknR~
            xx+=strwidth;                                          //~vbknI~
        	strlclen=0;                                            //~vbknI~
        	stru8len=0;                                            //~vbknI~
            pu8+=lenu8;                                            //~vbknI~
            pdddbcs+=2;                                            //~vbknI~
            plcdbcs+=2;                                            //~vbknI~
            reslen-=2;                                             //~vbknI~
                                                                   //~vbknI~
            pu8o=pu8;                                              //~vbknI~
            plcdbcso=plcdbcs;                                      //~vbknI~
        }                                                          //~vbknI~
        else                                                       //~vbknI~
        {                                                          //~vb4AI~
        	if (UDBCSCHK_ISUCSSBCS(dbcsid))//combining char detected//~vb4AI~
                chsz=1;                                            //~vb4AI~
            else                                                   //~vb4AI~
            if (UDBCSCHK_ISUCSNP(dbcsid))                          //~vbkqI~
                chsz=1;                                            //~vbkqI~
            else                                                   //~vbkqI~
            	chsz=2;                                            //~vb4AI~
            lenu8=UTF8CHARLEN(*pu8);                               //~vb4AI~
        	strlclen+=chsz;                                        //~vb4AI~
        	stru8len+=lenu8;                                       //~vb4AI~
            pu8+=lenu8;                                            //~vb4AI~
            pdddbcs+=chsz;                                         //~vb4AI~
            plcdbcs+=chsz;                                         //~vb4AI~
            reslen-=chsz;                                          //~vb4AI~
        }                                                          //~vb4AI~
    }//for                                                         //~vb4AR~
    if (stru8len)                                                  //~vb4AI~
    {                                                              //~vb4AI~
        UTRACED("pango_layout_set_text pu8:last",pu8o,stru8len);   //~vb4AI~
        pango_layout_set_text(Gplayout,pu8o,stru8len);             //~vb4AI~
        usetmonospace_ligature(optusms,Gplayout,pu8o,plcdbcso,strlclen,Mcellw,&strwidth);//~vb4AI~
        UTRACEP("%s:draw_layout_with_colors xx=%d,fg RGB=%04x,%04x,%04x\n",UTT,xx,Ppfg->red,Ppfg->green,Ppfg->blue);//~vb4AI~
        gdk_draw_layout_with_colors(Ppdc,Ppgc,xx,Py,Gplayout,Ppfg,Ppbg);//~vb4AI~
        xx+=strwidth;                                              //~vb4AI~
    }                                                              //~vb4AI~
    UTRACEP("%s:return strwidth=%d\n",UTT,xx-Px);                  //~vb4AI~
    return xx-Px;                                                  //~vb4AR~
}//drawtextstr_ligatureu8_nocombine                                //~vb4AR~
//===============================================================================//~vbdnR~
//open by application                                              //~vbdnR~
//===============================================================================//~vbdnR~
int updateFileMenu(int Popt)                             //~vbdnI~ //~vb7tI~
{                                                                  //~vbdnR~
	int rc=0;                                                      //~vbdnR~
//********************************                                 //~vbdnR~
    if (wxe_chkUpdateFileMenu(Popt))                               //~vbdnR~
    {                                                              //~vbdnR~
		rc=gxemfrm_updateFileMenu(Popt);                           //~vbdnR~
    }                                                              //~vbdnR~
    return rc;                                                     //~vbdnR~
}//updateFileMenu                                                  //~vbdnR~
//===============================================================================//~vbknI~
int xxescr_chkWidth0Ovf(int Popt,char *Pdddata,char *Pdddbcs,int Pddlen)//~vbknR~
{                                                                  //~vbknI~
	int rc=0,reslen;                                               //~vbknR~
    char *pdata,*pdbcs;                                            //~vbknI~
//**************                                                   //~vbknI~
    for (pdata=Pdddata,pdbcs=Pdddbcs,reslen=Pddlen;reslen>0;pdata++,pdbcs++,reslen--)//~vbknI~
    {                                                              //~vbknI~
		if (UDBCSCHK_ISUCSOVF1ST(*pdbcs))                          //~vbknR~
        {                                                          //~vbknI~
			if (csub_iswidth0(0,pdata,pdbcs,reslen,0/*Ppucs*/,0/*Ppchsz*/))//~vbknI~
            {                                                      //~vbknI~
            	rc=1;                                              //~vbknI~
            	break;                                             //~vbknI~
            }                                                      //~vbknI~
            pdata++; //step 2 colomn                               //~vbknI~
            pdbcs++;                                               //~vbknI~
            reslen--;                                              //~vbknI~
        }                                                          //~vbknI~
        else                                                       //~vbkvI~
        {                                                          //~vbkvI~
	    	if (Popt & CW0OO_SBCS)                                 //~vbkvI~
				if (UDBCSCHK_ISUCSWIDTH0(*pdbcs))                  //~vbkvI~
	    	    {                                                  //~vbkvI~
    	    		rc=1;                                          //~vbkvI~
        	    	break;                                         //~vbkvI~
        		}                                                  //~vbkvI~
        }                                                          //~vbkvI~
    }                                                              //~vbknI~
    UTRACEP("%s:rc=%d\n",UTT,rc);                                  //~vbknI~
    return rc;                                                     //~vbknI~
}//xxescr_chkWidth0Ovf                                             //~vbknI~
//===============================================================================//~vbknM~
//draw textstring by utf8; No ligature and !COMBINEMODE            //~vbknR~
//write overflow combining char by altch if COMBINE_NP,else single write//~vbknI~
//===============================================================================//~vbknM~
void  drawtextstr_NoLigatureu8_NoCombine(int Popt,CDC *Ppdc,GdkGC *Ppgc,int Px,int Py,GdkColor *Ppfg,GdkColor *Ppbg,char *Ppu8,int Pu8len,char *Pdddata,char *Pdddbcs,char *Plcdbcs,int Pddlen)//~vbknI~
{                                                                  //~vbknI~
    int xx,len,reslen,optusms,stru8len,strlclen;                   //~vbknR~
    int dbcsid,chsz,lenalt,lenu8;                                  //~vbknI~
    char *pdddbcs,*plcdbcs,*pu8,          *plcdbcso,*pu8o;         //~vbknI~
    char wku8[8],wkdbcs[2]={0};                                    //~vbknR~
//  GdkColor fgaltch={0,0/*r*/,0xffff/*g*/,0/*b*/};                //~vbknI~//~vbA3R~
    GdkColor fgaltch=SfgPadding;                                   //~vbA3I~
    char *pdddata;                                                 //~vbknI~
//************************************                             //~vbknI~
	UTRACEP("%s:opt=%04x,xx=%d,yy=%d,fg=%04x,bg=%04x\n",UTT,Popt,Px,Py,Ppfg,Ppbg);//~vbknI~
	UTRACED("u8data",Ppu8,Pu8len);                                 //~vbknI~
	UTRACED("dddata",Pdddata,Pddlen);                              //~vbknI~
	UTRACED("dddbcs",Pdddbcs,Pddlen);                              //~vbknI~
    optusms=Popt;                                                  //~vbknI~
    xx=Px;                                                         //~vbknI~
    strlclen=0,stru8len=0;                                         //~vbknI~
    pu8o=Ppu8,plcdbcso=Plcdbcs;                                    //~vbknI~
    for (pu8=Ppu8,pdddbcs=Pdddbcs,plcdbcs=Plcdbcs,reslen=Pddlen;reslen>0;)//~vbknI~
    {                                                              //~vbknI~
    	pdddata=Pdddata+PTRDIFF(pdddbcs,Pdddbcs);                  //~vbknI~
        dbcsid=*pdddbcs;                                           //~vbknI~
        if (!dbcsid)                                               //~vbknI~
        {                                                          //~vbknI~
    		len=umemspnc(pdddbcs,0,reslen);                        //~vbknI~
        	strlclen+=len;                                         //~vbknI~
        	stru8len+=len;                                         //~vbknI~
            pu8+=len;                                              //~vbknI~
            pdddbcs+=len;                                          //~vbknI~
            plcdbcs+=len;                                          //~vbknI~
            reslen-=len;                                           //~vbknI~
        }                                                          //~vbknI~
        else                                                       //~vbknI~
		if (UDBCSCHK_ISUCSOVF1ST(dbcsid)                           //~vbknI~
        &&  csub_iswidth0(0,pdddata,pdddbcs,reslen,0/*Ppucs*/,0/*ppshsz*/)==2)//combining char(>=0x20000) detected//~vbknI~
        {                                                          //~vbknI~
            if (stru8len)                                          //~vbknI~
            {                                                      //~vbknI~
                UTRACED("pango_layout_set_text pu8",pu8o,stru8len);//~vbknI~
                pango_layout_set_text(Gplayout,pu8o,stru8len);     //~vbknI~
	  			usetmonospace(optusms,Gplayout,pu8o,plcdbcso,strlclen,Mcellw);//~vbknI~
                UTRACEP("%s:draw_layout_with_colors xx=%d,fg RGB=%04x,%04x,%04x\n",UTT,xx,Ppfg->red,Ppfg->green,Ppfg->blue);//~vbknI~
                gdk_draw_layout_with_colors(Ppdc,Ppgc,xx,Py,Gplayout,Ppfg,Ppbg);//~vbknI~
                xx+=strlclen*Mcellw;                               //~vbknR~
            }                                                      //~vbknI~
            lenu8=UTF8CHARLEN(*pu8);                               //~vbknI~
#ifndef OPTGTK3                                                    //~vbknI~
#else   //OPTGTK3                                                  //~vbknI~
   			UTRACEP("%s:call csub_layout_set_textcolor fg=%s,bg=%s\n",UTT,csub_GdkColorToString(&fgaltch),csub_GdkColorToString(Ppbg));//~vbzbI~
			csub_layout_set_textcolor(Gplayout,&fgaltch,Ppbg);//gdk_draw_layout_with_colors() ignore color parameter//~vbknI~
#endif                                                             //~vbknI~
            if (UTF_COMBINEMODE_NP())                              //~vbknI~
            {                                                      //~vbknI~
            	lenalt=uccvucs2utf(Gutfcombaltch,wku8);            //~vbknI~
                wku8[lenalt++]=UVIOM_COMBINE_ALTCH2;               //~vbknI~
    	        UTRACED("combineNP pango_layout_set_text wku8",wku8,lenalt);//~vbknI~
            	pango_layout_set_text(Gplayout,wku8,lenalt);       //~vbknI~
	  			usetmonospace(optusms,Gplayout,wku8,wkdbcs,2,Mcellw);//~vbknI~
            }                                                      //~vbknI~
            else                                                   //~vbknI~
            {                                                      //~vbknI~
//            	pango_layout_set_text(Gplayout,pu8,lenu8);         //~vbknR~
//    			usetmonospace(optusms,Gplayout,pu8,plcdbcs,lenu8,Mcellw);//~vbknM~
            	strncpy(wku8,pu8,sizeof(wku8)-1);                  //~vbknR~
                len=lenu8;                                         //~vbknI~
                wku8[len++]=UVIOM_COMBINE_ALTCH2;                  //~vbknR~
    	        UTRACED("combine SPLIT pango_layout_set_text pu8",wku8,len);//~vbknR~
              	pango_layout_set_text(Gplayout,wku8,len);          //~vbknR~
      			usetmonospace(optusms,Gplayout,wku8,wkdbcs,2,Mcellw);//~vbknR~
            }                                                      //~vbknI~
            UTRACEP("%s:draw_layout_with_colors xx=%d,altfg RGB r=%04x,g=%04x,b=%04x\n",UTT,xx,fgaltch.red,fgaltch.green,fgaltch.blue);//~vbknI~
            gdk_draw_layout_with_colors(Ppdc,Ppgc,xx,Py,Gplayout,&fgaltch,Ppbg);//~vbknI~
#ifndef OPTGTK3                                                    //~vbknI~
#else   //OPTGTK3                                                  //~vbknI~
   			UTRACEP("%s:call csub_layout_set_textcolor fg=%s,bg=%s\n",UTT,csub_GdkColorToString(Ppfg),csub_GdkColorToString(Ppbg));//~vbzbI~
			csub_layout_set_textcolor(Gplayout,Ppfg,Ppbg);//restore for not COMBINE NP/SPLIT//~vbknI~
#endif                                                             //~vbknI~
            xx+=Mcellw*2;                                          //~vbknI~
        	strlclen=0;                                            //~vbknI~
        	stru8len=0;                                            //~vbknI~
            pu8+=lenu8;                                            //~vbknI~
            pdddbcs+=2;                                            //~vbknI~
            plcdbcs+=2;                                            //~vbknI~
            reslen-=2;                                             //~vbknI~
                                                                   //~vbknI~
            pu8o=pu8;                                              //~vbknI~
            plcdbcso=plcdbcs;                                      //~vbknI~
        }                                                          //~vbknI~
        else                                                       //~vbkvI~
		if (UDBCSCHK_ISUCSWIDTH0(dbcsid))                          //~vbkvI~
        {                                                          //~vbkvI~
            if (stru8len)                                          //~vbkvI~
            {                                                      //~vbkvI~
                UTRACED("pango_layout_set_text pu8",pu8o,stru8len);//~vbkvI~
                pango_layout_set_text(Gplayout,pu8o,stru8len);     //~vbkvI~
	  			usetmonospace(optusms,Gplayout,pu8o,plcdbcso,strlclen,Mcellw);//~vbkvI~
                UTRACEP("%s:draw_layout_with_colors xx=%d,fg RGB=%04x,%04x,%04x\n",UTT,xx,Ppfg->red,Ppfg->green,Ppfg->blue);//~vbkvI~
                gdk_draw_layout_with_colors(Ppdc,Ppgc,xx,Py,Gplayout,Ppfg,Ppbg);//~vbkvI~
                xx+=strlclen*Mcellw;                               //~vbkvI~
            }                                                      //~vbkvI~
            lenu8=UTF8CHARLEN(*pu8);                               //~vbkvI~
#ifndef OPTGTK3                                                    //~vbkvI~
#else   //OPTGTK3                                                  //~vbkvI~
   			UTRACEP("%s:call csub_layout_set_textcolor fg=%s,bg=%s\n",UTT,csub_GdkColorToString(&fgaltch),csub_GdkColorToString(Ppbg));//~vbzbI~
			csub_layout_set_textcolor(Gplayout,&fgaltch,Ppbg);//gdk_draw_layout_with_colors() ignore color parameter//~vbkvI~
#endif                                                             //~vbkvI~
            if (UTF_COMBINEMODE_NP())                              //~vbkvI~
            {                                                      //~vbkvI~
            	lenalt=uccvucs2utf(Gutfcombaltch,wku8);            //~vbkvI~
    	        UTRACED("sbcs combineNP pango_layout_set_text wku8",wku8,lenalt);//~vbkvI~
            	pango_layout_set_text(Gplayout,wku8,lenalt);       //~vbkvI~
	  			usetmonospace(optusms,Gplayout,wku8,wkdbcs,2,Mcellw);//~vbkvI~
            }                                                      //~vbkvI~
            else                                                   //~vbkvI~
            {                                                      //~vbkvI~
    	        UTRACED("sbcs combine SPLIT pango_layout_set_text pu8",pu8,lenu8);//~vbkvI~
            	pango_layout_set_text(Gplayout,pu8,lenu8);         //~vbkvI~
#ifdef SSS                                                         //~vbkwI~
	  			usetmonospace(optusms,Gplayout,pu8,plcdbcs,1,Mcellw);//~vbkvI~
#else                                                              //~vbkwI~
	  			usetmonospace(optusms|USMSO_SBCSCOMBSPLIT,Gplayout,pu8,plcdbcs,1,Mcellw); //chk 2 gliph and  2nd is width=0//~vbkwR~
#endif                                                             //~vbkwI~
            }                                                      //~vbkvI~
            UTRACEP("%s:draw_layout_with_colors xx=%d,altfg RGB r=%04x,g=%04x,b=%04x\n",UTT,xx,fgaltch.red,fgaltch.green,fgaltch.blue);//~vbkvI~
            gdk_draw_layout_with_colors(Ppdc,Ppgc,xx,Py,Gplayout,&fgaltch,Ppbg);//~vbkvI~
#ifndef OPTGTK3                                                    //~vbkvI~
#else   //OPTGTK3                                                  //~vbkvI~
   			UTRACEP("%s:call csub_layout_set_textcolor fg=%s,bg=%s\n",UTT,csub_GdkColorToString(Ppfg),csub_GdkColorToString(Ppbg));//~vbzbI~
			csub_layout_set_textcolor(Gplayout,Ppfg,Ppbg);//restore for not COMBINE NP/SPLIT//~vbkvI~
#endif                                                             //~vbkvI~
            xx+=Mcellw;                                            //~vbkvI~
        	strlclen=0;                                            //~vbkvI~
        	stru8len=0;                                            //~vbkvI~
            pu8+=lenu8;                                            //~vbkvI~
            pdddbcs++;                                             //~vbkvI~
            plcdbcs++;                                             //~vbkvI~
            reslen--;                                              //~vbkvI~
                                                                   //~vbkvI~
            pu8o=pu8;                                              //~vbkvI~
            plcdbcso=plcdbcs;                                      //~vbkvI~
        }                                                          //~vbkvI~
        else                                                       //~vbknI~
        {                                                          //~vbknI~
        	if (UDBCSCHK_ISUCSSBCS(dbcsid))//combining char detected//~vbknI~
                chsz=1;                                            //~vbknI~
            else                                                   //~vbknI~
            	chsz=2;                                            //~vbknI~
		  if (UDBCSCHK_ISUCSNP1ST(dbcsid))                         //~vbm7I~
            lenu8=2;                                               //~vbm7I~
          else                                                     //~vbm7I~
            lenu8=UTF8CHARLEN(*pu8);                               //~vbknI~
        	strlclen+=chsz;                                        //~vbknI~
        	stru8len+=lenu8;                                       //~vbknI~
            pu8+=lenu8;                                            //~vbknI~
            pdddbcs+=chsz;                                         //~vbknI~
            plcdbcs+=chsz;                                         //~vbknI~
            reslen-=chsz;                                          //~vbknI~
        }                                                          //~vbknI~
    }//for                                                         //~vbknI~
    if (stru8len)                                                  //~vbknI~
    {                                                              //~vbknI~
        UTRACED("pango_layout_set_text pu8:last",pu8o,stru8len);   //~vbknI~
        pango_layout_set_text(Gplayout,pu8o,stru8len);             //~vbknI~
	  	usetmonospace(optusms,Gplayout,pu8o,plcdbcso,strlclen,Mcellw);//~vbknR~
        UTRACEP("%s:draw_layout_with_colors xx=%d,fg RGB=%04x,%04x,%04x\n",UTT,xx,Ppfg->red,Ppfg->green,Ppfg->blue);//~vbknI~
        gdk_draw_layout_with_colors(Ppdc,Ppgc,xx,Py,Gplayout,Ppfg,Ppbg);//~vbknI~
        xx+=strlclen*Mcellw;                                       //~vbknR~
    }                                                              //~vbknI~
}//drawtextstr_NoLigatureu8_NoCombine                              //~vbknM~
//===============================================================================//~vbmaI~
//draw combine str; No ligature and !COMBINEMODE                   //~vbmaI~
//write overflow combining char by altch if COMBINE_NP,else single write//~vbmaI~
//w0tbl:1:combinech,2:not combine char,3:2nd of ovf combine,4:dbcs2nb,0:not combinable char//~vbmaR~//~vbmcR~
//===============================================================================//~vbmaI~
void  drawtextstr_NoLigatureu8_NoSCM_NoCombine(int Popt,CDC *Ppdc,GdkGC *Ppgc,int Px,int Py,GdkColor *Ppfg,GdkColor *Ppbg,char *Ppu8,int Pu8len,char *Pdddata,char *Pdddbcs,char *Plcdbcs,int Pddlen,char *Pw0tbl)//~vbmaI~
{                                                                  //~vbmaI~
    int xx,len,reslen,lenu8;                                       //~vbmaI~
    char *pu8,*poutu8,*pw0;                                        //~vbmaR~
    char wku8[UTF8_MAXCHARSZMAX+1];                                //~vbmaI~
//  GdkColor fgaltch={0,0/*r*/,0xffff/*g*/,0/*b*/};                //~vbmaI~//~vbA3R~
    GdkColor fgaltch=SfgPadding;                                   //~vbA3I~
    GdkColor *pfg;                                                 //~vbmaI~
//************************************                             //~vbmaI~
	UTRACEP("%s:opt=%04x,xx=%d,yy=%d,fg=%s,bg=%s\n",UTT,Popt,Px,Py,COLOR2STRING(Ppfg),COLOR2STRING(Ppbg));//~vbmaI~//~vbAhR~
	UTRACED("u8data",Ppu8,Pu8len);                                 //~vbmaI~
	UTRACED("dddata",Pdddata,Pddlen);                              //~vbmaI~
	UTRACED("dddbcs",Pdddbcs,Pddlen);                              //~vbmaI~
	UTRACED("w0tbl",Pw0tbl,Pddlen);                                //~vbmaR~
    int swsplit=0;                                                 //~vbAhR~
    for (xx=Px,pu8=Ppu8,pw0=Pw0tbl,poutu8=wku8,reslen=Pddlen;reslen>0;pu8+=lenu8,reslen--,pw0++)//~vbmaR~
    {                                                              //~vbmaI~
        lenu8=UTF8CHARLEN(*pu8);                                   //~vbmaI~
        pfg=&fgaltch;                                              //~vbmaI~
        UTRACEP("%s:pw0=%d,lenu8=%d\n",UTT,*pw0,lenu8);            //~vbmaI~
        switch (*pw0)                                              //~vbmaI~
        {                                                          //~vbmaI~
        case 2: //combinable                                       //~vbmaR~
        	pfg=Ppfg;                                              //~vbmaI~
        	poutu8=pu8;                                            //~vbmaI~
            len=lenu8;                                             //~vbmaI~
            break;                                                 //~vbmaI~
        case 1:	//combinech                                        //~vbmaI~
            if (UTF_COMBINEMODE_NP())                              //~vbmaI~
            {                                                      //~vbmaI~
            	len=uccvucs2utf(Gutfcombaltch,wku8);               //~vbmaI~
	            poutu8=wku8;                                       //~vbmaI~
            }                                                      //~vbmaI~
            else                                                   //~vbmaI~
            {                                                      //~vbmaI~
            	poutu8=pu8;                                        //~vbmaI~
	            len=lenu8;                                         //~vbmaI~
                swsplit=1;                                         //~vbAhI~
            }                                                      //~vbmaI~
            break;                                                 //~vbmaI~
        case 3:	//combinech    ovf 2nd                             //~vbmaR~
            *wku8=UVIOM_COMBINE_ALTCH2;                            //~vbmaI~
            len=1;                                                 //~vbmaI~
	        poutu8=wku8;                                           //~vbmaI~
            lenu8=0;                                               //~vbmaI~
            break;                                                 //~vbmaI~
        case 4:	//dbcs 2nd                                         //~vbmaI~
            len=0;                                                 //~vbmaI~
            lenu8=0;                                               //~vbmaI~
            break;                                                 //~vbmaI~
#ifndef KKK                                                        //~v7f4R~
        case ID_W0NOCOMB:	//w0 no combining                      //~v7f4R~
        	UTRACED("W0NOCOMB",pu8,lenu8);                         //~v7f4R~
            poutu8=pu8;                                            //~v7f4I~
	        len=lenu8;                                             //~v7f4I~
            swsplit=1;   //goto drawsplitCombineNoLigature         //~v7f4I~
            break;                                                 //~v7f4I~
#endif //KKK                                                       //~v7f4R~
        }                                                          //~vbmaI~
      UTRACEP("%s:len=%d,swsplit=%d\n",UTT,len,swsplit);           //~v7f4I~
      if (len)                                                     //~vbmaI~
      {                                                            //~vbmaI~
       if (swsplit)                                                //~vbAhI~
        	drawSplitCombineNoLigature(Popt,Ppdc,Ppgc,xx,Py,Ppfg,Ppbg,poutu8,len);//~vbAhR~
       else                                                        //~vbAhI~
       {                                                           //~vbAhI~
        pango_layout_set_text(Gplayout,poutu8,len);                //~vbmaI~
        UTRACED("outu8",poutu8,len);                               //~vbmaI~
        UTRACELAYOUT(Gplayout);                                    //~vbmfI~
        gdk_draw_layout_with_colors(Ppdc,Ppgc,xx,Py,Gplayout,pfg,Ppbg);//~vbmaI~
        UTRACEP("%s:xx=%d\n",UTT,xx);                              //~vbmaR~
       }                                                           //~vbAhI~
      }                                                            //~vbmaI~
        xx+=Mcellw;                                                //~vbmaI~
    }                                                              //~vbmaI~
}//drawtextstr_NoLigatureu8_NoSCM_NoCombine                        //~vbmaI~
//**********************************************************************//~vbmeI~
int  drawtextstr_NoLigatureu8_SCM_chkcont(int Popt,char *Ppu8,int Pu8len,char *Pdddata,char *Pdddbcs,int Pddlen,int *Ppu8lencont,int *Ppddlencont,int *Ppscmucsctrcont)//~vbmeI~
{                                                                  //~vbmeI~
    int reslen,chsz,lenu8,swscm,ucs,scmucsctr=0,ddlencont,u8lencont;//~vbmeR~
    char *pdata,*pdbcs,*pu8;                                       //~vbmeI~
//************************************                             //~vbmeI~
    UTRACEP("%s:opt=%x,u8len=%d,ddlen=%d\n",UTT,Popt,Pu8len,Pddlen);//~vbmeI~
    for (pu8=Ppu8,pdata=Pdddata,pdbcs=Pdddbcs,reslen=Pddlen;reslen>0;pu8+=lenu8,pdata+=chsz,pdbcs+=chsz,reslen-=chsz)//~vbmeR~
    {                                                              //~vbmeI~
        if (!*pdbcs)	//ascii                                    //~vbmeI~
            break;                                                 //~vbmeI~
        lenu8=UTF8CHARLEN(*pu8);                                   //~vbmeI~
		ucs=UTF_GETDDUCS1VIO(pdata,pdbcs,reslen,&chsz);            //~vbmeI~
        swscm=csub_isSpacingCombiningMark(0,ucs);                  //~vbmeI~
        UTRACEP("%s:ucs=%04x,scm=%d\n",UTT,ucs,swscm);             //~vbmeI~
        if (!swscm)                                                //~vbmeI~
        	break;                                                 //~vbmeI~
        scmucsctr++;                                               //~vbmeR~
    }                                                              //~vbmeI~
    if (scmucsctr)                                                 //~vbmeR~
    	u8lencont=PTRDIFF(pu8,Ppu8),ddlencont=PTRDIFF(pdata,Pdddata);//~vbmeI~
    else                                                           //~vbmeI~
    	u8lencont=ddlencont=0;                                     //~vbmeI~
    *Ppu8lencont=u8lencont;                                        //~vbmeI~
    *Ppddlencont=ddlencont;                                        //~vbmeI~
    *Ppscmucsctrcont=scmucsctr;                                    //~vbmeI~
    UTRACEP("%s:u8lencont=%d,ddlencont=%d,ucsctr=%d\n",UTT,u8lencont,ddlencont,scmucsctr);//~vbmeR~
    return scmucsctr!=0;                                           //~vbmeI~
}//drawtextstr_NoLigatureu8_SCM_chkcont                            //~vbmeI~
//===============================================================================//~vbkqI~
//draw textstring by utf8 considering SCM                          //~vbkqR~
//SCM generate 2 glyph(with prev ucs when combined or 1 ucs 1tself //~vbkqR~
//===============================================================================//~vbkqI~
int  drawtextstr_NoLigatureu8_SCM(int Popt,CDC *Ppdc,GdkGC *Ppgc,int Px,int Py,GdkColor *Ppfg,GdkColor *Ppbg,char *Ppu8,int Pu8len,char *Pdddata,char *Pdddbcs,char *Plcdbcs,int Pddlen)//~vbkqR~
{                                                                  //~vbkqI~
    int xx,reslen,optusms,stru8len,strddlen;                   //~vbkqR~//~vbksR~
    int chsz,chszo,lenu8,lenu8o,swscm,swscmo,ucs,scmucsctr;        //~vbkqR~
    char *pdata,*pdbcs,*plcdbcs,*pu8;                              //~vbkqR~
    char *pstru8start,*pstrdatastart,*pstrdbcsstart,*pstrlcdbcsstart;//~vbkqI~
#ifndef QQQ   //try ZWNC(u200c)                                    //~vbksR~
#ifdef AAA                                                         //~vbksI~
    char wku8str[32],*pc;                                          //~vbksR~
#endif                                                             //~vbksI~
#endif //QQQ                                                       //~vbksI~
	int u8lencont,ddlencont,scmucsctrcont,swbase;                  //~vbmeR~
//  GdkColor fgaltch={0,0/*r*/,0xffff/*g*/,0/*b*/};                //~vbmfI~//~vbA3R~
    GdkColor fgaltch=SfgPadding;                                   //~vbA3I~
	int ucso,ddlenalt,lenalt;                                      //~vbmfR~
    char wku8str[32];                                              //~vbmfI~
    char wkdddata[32];                                             //~vbmfI~
//************************************                             //~vbkqI~
	UTRACEP("%s:opt=%04x,xx=%d,yy=%d,fg=%04x,bg=%04x\n",UTT,Popt,Px,Py,Ppfg,Ppbg);//~vbkqI~
	UTRACED("u8data",Ppu8,Pu8len);                                 //~vbkqI~
	UTRACED("dddata",Pdddata,Pddlen);                              //~vbkqI~
	UTRACED("dddbcs",Pdddbcs,Pddlen);                              //~vbkqI~
    optusms=Popt;                                                  //~vbkqI~
    xx=Px;                                                         //~vbkqI~
    strddlen=0,stru8len=0;                                         //~vbkqR~
    pstru8start=Ppu8,pstrdbcsstart=Pdddbcs,pstrdatastart=Pdddata,pstrlcdbcsstart=Plcdbcs;//~vbkqR~
    chsz=0,lenu8=0,swscm=0;                                        //~vbkqR~
	ucs=0;                                                         //~vbmfI~
    for (pu8=Ppu8,pdata=Pdddata,pdbcs=Pdddbcs,plcdbcs=Plcdbcs,reslen=Pddlen;reslen>0;pu8+=lenu8,pdata+=chsz,pdbcs+=chsz,plcdbcs+=chsz,reslen-=chsz)//~vbkqR~
    {                                                              //~vbkqI~
		ucso=ucs;                                                  //~vbmfI~
        chszo=chsz;                                                //~vbkqI~
        lenu8o=lenu8;                                              //~vbkqR~
        swscmo=swscm;                                              //~vbkqI~
        UTRACEP("%s:ch=%0x,dbcs=%0x,reslen=%d\n",UTT,*pdata,*pdbcs,reslen);//~vbkqR~
        if (!*pdbcs)                                               //~vbkqR~
        {                                                          //~vbkqI~
	        ucs=*pdata;                                            //~vbkqI~
        	lenu8=1;                                               //~vbkqM~
            chsz=1;                                                //~vbkqI~
            swscm=0;                                               //~vbkqM~
        }                                                          //~vbkqI~
        else                                                       //~vbkqI~
        {                                                          //~vbkqI~
        	lenu8=UTF8CHARLEN(*pu8);                               //~vbkqI~
//        	ucs=UTF_GETDDUCS1(pdata,pdbcs,reslen);   //NP consider unprintable//~vbkqR~
			ucs=UTF_GETDDUCS1VIO(pdata,pdbcs,reslen,&chsz);        //~vbkqR~
            swscm=csub_isSpacingCombiningMark(0,ucs);              //~vbkqI~
        }                                                          //~vbkqI~
        UTRACEP("%s:ucs=%04x,scm=%d\n",UTT,ucs,swscm);             //~vbkqI~
        if (swscm)                                                 //~vbkqR~
        {                                                          //~vbkqI~
        	if (!swscmo)	//not continued scm                    //~vbkqI~
            {                                                      //~vbkqI~
        		stru8len=PTRDIFF(pu8,pstru8start)-lenu8o;          //~vbkqR~
        		strddlen=PTRDIFF(pdbcs,pstrdbcsstart)-chszo;       //~vbkqR~
            }                                                      //~vbkqI~
            else                                                   //~vbkqI~
            {                                                      //~vbkqI~
        		stru8len=0;                                        //~vbkqI~
        		strddlen=0;                                        //~vbkqI~
            }                                                      //~vbkqI~
            if (stru8len)                                          //~vbkqR~
            {                                                      //~vbkqI~
//*draw str before SCM                                             //~vbkqI~
                UTRACEP("%s:before scm xx=%d,strddlen=%d\n",UTT,xx,strddlen);//~vbkqR~
                UTRACED("before scm u8",pstru8start,stru8len);     //~vbkqI~
                UTRACED("before scm data",pstrdatastart,strddlen); //~vbkqI~
                UTRACED("before scm dbcs",pstrdbcsstart,strddlen); //~vbkqI~
				drawtextstr_NoLigatureu8_NoSCM(Popt,Ppdc,Ppgc,xx,Py,Ppfg,Ppbg,pstru8start,stru8len,pstrdatastart,pstrdbcsstart,pstrlcdbcsstart,strddlen);//~vbkqR~
	            xx+=strddlen*Mcellw;                               //~vbkqI~
            }                                                      //~vbkqI~
//*draw SCM   with/without prev char                               //~vbkqI~
            swbase=0;                                              //~vbmeI~
        	if (swscmo)      //no combine,write itselg             //~vbkqR~
            {                                                      //~vbkqI~
            	pstru8start=pu8;                                   //~vbkqI~
            	pstrdatastart=pdata;                               //~vbkqI~
            	pstrdbcsstart=pdbcs;                               //~vbkqI~
            	pstrlcdbcsstart=plcdbcs;                           //~vbkqI~
                stru8len=lenu8;                                    //~vbkqI~
                strddlen=chsz;                                     //~vbkqR~
                scmucsctr=1;                                       //~vbkqI~
            }                                                      //~vbkqI~
            else           //write eith prev char                  //~vbkqR~
            {                                                      //~vbkqI~
#ifndef QQQ   //try ZWNC(u200c)                                    //~vbksI~
//      	  if (((Popt & USMSO_COMBINEOF) && !UTF_COMBINEMODE_NP())    //combine split//~vbksR~//~vbmfR~
//            && (lenu8o!=U8SZ_ZWNJ || memcmp(pstru8start,U8_ZWNJ,U8SZ_ZWNJ)) //prev is not ZWNJ//~vbksI~//~vbmfR~
//            )                                                    //~vbksI~//~vbmfR~
        	  if (Popt & USMSO_COMBINEOF||!UTF_COMBINABLE(ucso))      //comb:split/np, prev is not combinable//~vbmfI~
              {                                                    //~vbksI~
#ifdef AAA                                                         //~vbksI~
//*put ZWNJ between base and SCM                                   //~vbksI~
                    pc=wku8str;                                    //~vbksI~
                	memcpy(pc,pstru8start,(size_t)lenu8o);         //~vbksI~
                    pc+=lenu8o;                                    //~vbksI~
                    memcpy(pc,U8_ZWNJ,U8SZ_ZWNJ);                  //~vbksI~
                    pc+=U8SZ_ZWNJ;                                 //~vbksI~
                    memcpy(pc,pstru8start+lenu8o,(size_t)lenu8);   //~vbksI~
                    pc+=lenu8;                                     //~vbksI~
                    pstru8start=wku8str;                           //~vbksI~
                    stru8len=PTRDIFF(pc,pstru8start);              //~vbksI~
                    scmucsctr=3;                                   //~vbksI~
		            strddlen=chszo+chsz;                           //~vbksI~
#else                                                              //~vbksI~
//*put twice base and ZWNJ+SCM                                     //~vbksR~
	            	pstru8start+=stru8len;                         //~vbm2I~
	            	stru8len=lenu8o;                               //~vbm2I~
		            UTRACED("before scm single write pango_set_text",pstru8start,stru8len);//~vbksM~//~vbm2R~
            		pango_layout_set_text(Gplayout,pstru8start,stru8len);//~vbksM~//~vbm2R~
//    				usetmonospace_SCM(optusms,Gplayout,chszo,Mcellw);//~vbksM~//~vbmeR~
				    UTRACEP("%s:call usetmonospace len=%d\n",UTT,chszo);//~vbzbI~
  					usetmonospace(optusms,Gplayout,pstrdatastart+strddlen,pstrlcdbcsstart+strddlen,chszo,Mcellw);//~vbmeI~
		            UTRACEP("%s:call gdk_draw_layout_with_colors xx=%d,yy=%d,fg=%s,bg=%s\n",UTT,xx,Py,csub_GdkColorToString(Ppfg),csub_GdkColorToString(Ppbg));//~vbzbR~
            		gdk_draw_layout_with_colors(Ppdc,Ppgc,xx,Py,Gplayout,Ppfg,Ppbg);//~vbksM~
                    xx+=chszo*Mcellw;                              //~vbksM~
            #ifdef BBB                                             //~vbksI~
                    pc=wku8str;                                    //~vbksM~
                    memcpy(pc,U8_ZWNJ,U8SZ_ZWNJ);                  //~vbksM~
                    pc+=U8SZ_ZWNJ;                                 //~vbksM~
                    memcpy(pc,pstru8start+lenu8o,(size_t)lenu8);   //~vbksM~
                    pc+=lenu8;                                     //~vbksM~
                    pstru8start=wku8str;                           //~vbksM~
                    stru8len=PTRDIFF(pc,pstru8start);              //~vbksM~
                    scmucsctr=2;                                   //~vbksI~
		            strddlen=chsz;   //write pos of next char      //~vbksI~
            #else   //no use ZWNJ, write 1 by 1                    //~vbksR~
                    pstru8start=pu8;                               //~vbksI~
                    stru8len=lenu8;                                //~vbksI~
                    scmucsctr=1;                                   //~vbksI~
		            strddlen=chsz;   //write pos of next char      //~vbksI~
            #endif                                                 //~vbksI~
              }                                                    //~vbksI~
              else                                                 //~vbksI~
#endif //AAA                                                       //~vbksR~
#endif //QQQ                                                       //~vbksI~
              {                                                    //~vbksI~
//COMBINEON & prev is combinable                                   //~vbmfR~
              	swbase=USMSO_WITHSCMBASE;                          //~vbmeI~
            	pstru8start=pu8-lenu8o;                            //~vbkqR~
            	pstrdatastart=pdata-chszo;                         //~vbkqI~
            	pstrdbcsstart=pdbcs-chszo;                         //~vbkqI~
            	pstrlcdbcsstart=plcdbcs-chszo;                     //~vbkqI~
                stru8len=lenu8+lenu8o;                             //~vbkqR~
                strddlen=chszo+chsz;                               //~vbkqI~
                scmucsctr=2;                                       //~vbkqI~
//        	  	if ((Popt & USMSO_COMBINEON) || UTF_COMBINEMODE_NP())    //UNICOMB=COMB or UNP//~vbmeR~//~vbmfR~
              	{                                                  //~vbmeI~
					if (drawtextstr_NoLigatureu8_SCM_chkcont(Popt,pu8+lenu8,PTRDIFF(pu8,Ppu8)-lenu8,pdata+chsz,pdbcs+chsz,reslen-chsz,&u8lencont,&ddlencont,&scmucsctrcont))//~vbmeI~
                    {                                              //~vbmeI~
                    	stru8len+=u8lencont,strddlen+=ddlencont,scmucsctr+=scmucsctrcont;//~vbmeI~
                    	lenu8+=u8lencont,chsz+=ddlencont;          //~vbmeI~
                    }                                              //~vbmeI~
              	}                                                  //~vbmeI~
              }                                                    //~vbksI~
            }                                                      //~vbkqI~
            UTRACEP("%s:write scm xx=%d,scmucsctr=%d\n",UTT,xx,scmucsctr);//~vbkqI~//~vbksR~
            UTRACED("pango_set_text",pstru8start,stru8len);        //~vbkqI~//~vbksR~
#ifndef OPTGTK3                                                    //~vbA3I~
#else   //OPTGTK3                                                  //~vbA3I~
		int swaltcolor=0;                                          //~vbA3I~
#endif                                                             //~vbA3I~
       	if ((Popt & USMSO_COMBINEOF) && UTF_COMBINEMODE_NP())    //combine split//~vbmfR~
        {                                                          //~vbmfI~
			lenalt=uviom_getcombaltchU8(UVIOM_GCAC_2CELL,wku8str,wkdddata,0/*pdddbcs*/,&ddlenalt);//~vbmfR~
		    UTRACED("pango_layoyut_set_text wku8str",wku8str,lenalt);//~vbzbI~
        	pango_layout_set_text(Gplayout,wku8str,lenalt);        //~vbmfI~
			UTRACEP("%s:call usetmonospace len=%d\n",UTT,ddlenalt);//~vbzbI~
  			usetmonospace(optusms,Gplayout,wkdddata,"\x00\x00",ddlenalt,Mcellw);//~vbmfR~
		    UTRACEP("%s:call gdk_draw_layout_with_colors ALT xx=%d,yy=%d,fg=%s,bg=%s\n",UTT,xx,Py,csub_GdkColorToString(&fgaltch),csub_GdkColorToString(Ppbg));//~vbzbR~
#ifndef OPTGTK3                                                    //~vbA3I~
#else   //OPTGTK3                                                  //~vbA3I~
		    UTRACEP("%s:OPTGTK3 call csub_layout_set_textcolors fg=%s,bg=%s\n",UTT,csub_GdkColorToString(&fgaltch),csub_GdkColorToString(Ppbg));//~vbA3I~
			csub_layout_set_textcolor(Gplayout,&fgaltch,Ppbg);//gdk_draw_layout_with_colors() ignore color parameter//~vbA3I~
			swaltcolor=1;                                          //~vbA3I~
#endif                                                             //~vbA3I~
            gdk_draw_layout_with_colors(Ppdc,Ppgc,xx,Py,Gplayout,&fgaltch,Ppbg);//~vbmfI~
        }                                                          //~vbmfI~
        else                                                       //~vbmfI~
        {                                                          //~vbmfI~
		    UTRACED("pango_layoyut_set_text",pstru8start,stru8len);//~vbzbI~
            pango_layout_set_text(Gplayout,pstru8start,stru8len);  //~vbkqR~
          if (!swbase)                                             //~vbmeI~
          {                                                        //~vbmeI~
			UTRACEP("%s:call usetmonospace len=%d\n",UTT,scmucsctr);//~vbzbI~
      		usetmonospace_SCM(optusms,Gplayout,scmucsctr,Mcellw);  //~vbkqR~
		    UTRACEP("%s:call gdk_draw_layout_with_colors xx=%d,yy=%d,fg=%s,bg=%s\n",UTT,xx,Py,csub_GdkColorToString(&fgaltch),csub_GdkColorToString(Ppbg));//~vbzbR~
#ifndef OPTGTK3                                                    //~vbA3I~
#else   //OPTGTK3                                                  //~vbA3I~
      	  if ((Popt & USMSO_VHEXDATACPOS) && Px==SxxVhexDataCpos)  //~vbDsI~
          {                                                        //~vbDsI~
		    UTRACEP("%s:skip set textcolor altch by SxxVhexDataCpos Px=%d\n",UTT,Px);//~vbDsI~
          }                                                        //~vbDsI~
          else                                                     //~vbDsI~
          {                                                        //~vbDsI~
		    UTRACEP("%s:OPTGTK3 call csub_layout_set_textcolors fg=%s,bg=%s\n",UTT,csub_GdkColorToString(&fgaltch),csub_GdkColorToString(Ppbg));//~vbA3I~
			csub_layout_set_textcolor(Gplayout,&fgaltch,Ppbg);//gdk_draw_layout_with_colors() ignore color parameter//~vbA3I~
			swaltcolor=1;                                          //~vbA3I~
          }                                                        //~vbDsI~
#endif                                                             //~vbA3I~
            gdk_draw_layout_with_colors(Ppdc,Ppgc,xx,Py,Gplayout,&fgaltch,Ppbg);//~vbmfI~
          }                                                        //~vbmeI~
          else                                                     //~vbmfI~
          {                                                        //~vbzbI~
		    UTRACEP("%s:call gdk_draw_layout_with_colors xx=%d,yy=%d,fg=%s,bg=%s\n",UTT,xx,Py,csub_GdkColorToString(Ppfg),csub_GdkColorToString(Ppbg));//~vbzbR~
            gdk_draw_layout_with_colors(Ppdc,Ppgc,xx,Py,Gplayout,Ppfg,Ppbg);//~vbkqI~
          }                                                        //~vbzbI~
          UTRACELAYOUT(Gplayout);                                  //~vbmfI~
        }                                                          //~vbmfI~
#ifndef OPTGTK3                                                    //~vbkqM~
#else   //OPTGTK3                                                  //~vbkqM~
		if (swaltcolor)                                            //~vbA3I~
        {                                                          //~vbA3I~
		    UTRACEP("%s:OPTGTK3 call csub_layout_set_textcolors fg=%s,bg=%s\n",UTT,csub_GdkColorToString(Ppfg),csub_GdkColorToString(Ppbg));//~vbzbR~//~vbA3R~
//  		csub_layout_set_textcolor(Gplayout,&fgaltch,Ppbg);//gdk_draw_layout_with_colors() ignore color parameter//~vbkqM~//~vbA3R~
    		csub_layout_set_textcolor(Gplayout,Ppfg,Ppbg);//restore fg color//~vbA3I~
        }                                                          //~vbA3I~
#endif                                                             //~vbkqM~
			pstru8start=pu8+lenu8;                                 //~vbkqR~
			pstrdatastart=pdata+chsz;                              //~vbkqR~
			pstrdbcsstart=pdbcs+chsz;                              //~vbkqI~
			pstrlcdbcsstart=plcdbcs+chsz;                          //~vbkqR~
	        xx+=strddlen*Mcellw;                                   //~vbkqI~
        } //swscm                                                         //~vbkqI~//~vbm2R~
    }//for                                                         //~vbkqI~
    stru8len=PTRDIFF(pu8,pstru8start);                             //~vbkqI~
    strddlen=PTRDIFF(pdbcs,pstrdbcsstart);                         //~vbkqI~
    if (stru8len)                                                  //~vbkqI~
    {                                                              //~vbkqI~
                UTRACEP("%s:last xx=%d,strddlen=%d\n",UTT,xx,strddlen);//~vbkqI~
                UTRACED("last noscm u8",pstru8start,stru8len);     //~vbkqI~
                UTRACED("last noscm data",pstrdatastart,strddlen); //~vbkqI~
                UTRACED("last noscm dbcs",pstrdbcsstart,strddlen); //~vbkqI~
		drawtextstr_NoLigatureu8_NoSCM(Popt,Ppdc,Ppgc,xx,Py,Ppfg,Ppbg,pstru8start,stru8len,pstrdatastart,pstrdbcsstart,pstrlcdbcsstart,strddlen);//~vbkqI~
        xx+=strddlen*Mcellw;                                       //~vbkqR~
    }                                                              //~vbkqI~
    return xx;                                                     //~vbkqI~
}//drawtextstr_NoLigatureu8_SCM                                    //~vbksR~
#ifndef JJJ                                                        //~vbm8I~
//===============================================================================//~vbm8I~
//draw textstring by utf8 which dose not contain SCM               //~vbm8I~
//combbine strg split write                                        //~vbm8I~
//===============================================================================//~vbm8I~
int  drawtextstr_NoLigatureu8_NoSCM(int Popt,CDC *Ppdc,GdkGC *Ppgc,int Px,int Py,GdkColor *Ppfg,GdkColor *Ppbg,//~vbm8I~
		char *Ppu8,int Pu8len,char *Pdddata,char *Pdddbcs,char *Plcdbcs,int Pddlen)//~vbm8I~
{                                                                  //~vbm8I~
    int ii,substrctr,startu8,startdd,xx,lenu8,lendd;               //~vbm8R~
    int ddidxtbl[(MAXCOL+1)*2],*pidxdd;//dd start offs,end offs    //~vbm8R~
    int u8idxtbl[(MAXCOL+1)*2],*pidxu8;	//u8 start offs,end offs   //~vbm8R~
    char w0idtbl[MAXCOL];	//1:combine char,3 2nd of ovf combine char,2:not combine//~vbmaI~
    int opt,swcombinable;                                          //~vbmcI~
//*****************************                                    //~vbm8I~
	UTRACEP("%s:opt=%x,x=%d,y=%d,ddlen=%d\n",UTT,Popt,Px,Py,Pddlen);           //~vbm8I~//~vbmaR~
	UTRACED("u8",Ppu8,Pu8len);                                     //~vbm8I~
	UTRACED("dddata",Pdddata,Pddlen);                              //~vbm8I~
	UTRACED("dddbcs",Pdddbcs,Pddlen);                              //~vbm8I~
	UTRACED("lcdbcs",Plcdbcs,Pddlen);                              //~vbm8I~
//  substrctr=csub_GetCombineStrTbl(0,Ppu8,Pu8len,Pdddata,Pdddbcs,Pddlen,u8idxtbl,ddidxtbl);//~vbm8R~//~vbmaR~
    substrctr=csub_GetCombineStrTbl(0,Ppu8,Pu8len,Pdddata,Pdddbcs,Pddlen,u8idxtbl,ddidxtbl,w0idtbl);//~vbmaI~
    opt=Popt;                                                      //~vbmcI~
    if (substrctr)                                                 //~vbm8I~
    {                                                              //~vbm8I~
        startu8=0;                                                 //~vbm8R~
        startdd=0;                                                 //~vbm8R~
        for (ii=0,xx=Px,pidxdd=ddidxtbl,pidxu8=u8idxtbl;ii<substrctr;ii++,pidxdd+=2,pidxu8+=2)//~vbm8R~
        {                                                          //~vbm8R~
            lenu8=*pidxu8-startu8;                                 //~vbm8R~
            lendd=*pidxdd-startdd;                                 //~vbm8R~
            if (lenu8)    //before combinestr                      //~vbm8R~
            {                                                      //~vbm8R~
//              drawtextstr_NoLigatureu8_NoSCMSub(Popt|USMSO_NOCOMBINESTR,Ppdc,Ppgc,xx,Py,Ppfg,Ppbg,Ppu8+startu8,lenu8,Pdddata+startdd,Pdddbcs+startdd,Plcdbcs+startdd,lendd);//~vbm8R~//~vbmcR~
                opt=Popt|USMSO_NOCOMBINESTR;                       //~vbmcI~
                drawtextstr_NoLigatureu8_NoSCMSub(opt,Ppdc,Ppgc,xx,Py,Ppfg,Ppbg,Ppu8+startu8,lenu8,Pdddata+startdd,Pdddbcs+startdd,Plcdbcs+startdd,lendd);//~vbmcI~
                xx+=Mcellw*lendd;                                  //~vbm8R~
            }                                                      //~vbm8R~
            startu8=*pidxu8;                                       //~vbm8R~
            lenu8=*(pidxu8+1)-startu8;                             //~vbm8R~
            startdd=*pidxdd;                                       //~vbm8R~
            lendd=*(pidxdd+1)-startdd;                             //~vbm8R~
            UTRACEP("%s:ii=%d,startu8=%d,lenu8=%d,startdd=%d,lendd=%d\n",UTT,ii,startu8,lenu8,startdd,lendd);//~vbAhI~
            UTRACED("u8str",Ppu8+startu8,lenu8);                   //~vbAhI~
		  if (Popt & USMSO_COMBINEOF)       //NP or split mode     //~vbmaR~
	        drawtextstr_NoLigatureu8_NoSCM_NoCombine(Popt,Ppdc,Ppgc,xx,Py,Ppfg,Ppbg,Ppu8+startu8,lenu8,Pdddata+startdd,Pdddbcs+startdd,Plcdbcs+startdd,lendd,w0idtbl+startdd);//~vbmaR~
          else                                                     //~vbmaI~
          {                                                        //~vbmcI~
#ifdef KKK                                                         //~v7f4I~
    	   if (w0idtbl[startdd]==1) //start fom combining char     //~vbAhI~
#else                                                              //~v7f4I~
    	   if (w0idtbl[startdd]==1 //start fom combining char      //~v7f4I~
    	   ||  w0idtbl[startdd]==ID_W0NOCOMB)//start fom w0nocomb  char//~v7f4R~
#endif                                                             //~v7f4I~
	        drawtextstr_NoLigatureu8_NoSCM_NoCombine(Popt,Ppdc,Ppgc,xx,Py,Ppfg,Ppbg,Ppu8+startu8,lenu8,Pdddata+startdd,Pdddbcs+startdd,Plcdbcs+startdd,lendd,w0idtbl+startdd);//for multiple combining//~vbAhI~
           else                                                    //~vbAhI~
           {                                                       //~vbAhI~
//          drawtextstr_NoLigatureu8_NoSCMSub(Popt|USMSO_COMBINESTR,Ppdc,Ppgc,xx,Py,Ppfg,Ppbg,Ppu8+startu8,lenu8,Pdddata+startdd,Pdddbcs+startdd,Plcdbcs+startdd,lendd);//~vbm8R~//~vbmcR~
            opt=Popt|USMSO_COMBINESTR;                             //~vbmcI~
//  	    swcombinable=(w0idtbl[ii]!=1); //not start fom combining char//~vbmcR~//~vbmfR~
    	    swcombinable=(w0idtbl[startdd]!=1); //not start fom combining char//~vbmfI~
            UTRACEP("%s:swcombinable=%d,ii=%d,startdd=%d,w0idtbl=%d,dddata=%x,lendd=%d\n",UTT,swcombinable,ii,startdd,w0idtbl[startdd],*(Pdddata+startdd),lendd);//~vbmcI~//~vbmfR~
            if (!swcombinable)                                     //~vbmcI~
            	opt|=USMSO_NOTCOMBINABLE;                          //~vbmcI~
            drawtextstr_NoLigatureu8_NoSCMSub(opt,Ppdc,Ppgc,xx,Py,Ppfg,Ppbg,Ppu8+startu8,lenu8,Pdddata+startdd,Pdddbcs+startdd,Plcdbcs+startdd,lendd);//~vbmcI~
           }                                                       //~vbAhI~
          }                                                        //~vbmcI~
            xx+=Mcellw*lendd;                                      //~vbm8R~
            startu8=*(pidxu8+1);  //next substr                    //~vbm8R~
            startdd=*(pidxdd+1);                                   //~vbm8R~
        }                                                          //~vbm8R~
        lendd=Pddlen-startdd;                                      //~vbm8I~
        if (lendd>0)	//remains after last combining str         //~vbm8I~
        {                                                          //~vbm8I~
	        lenu8=Pu8len-startu8;                                  //~vbm8I~
//          drawtextstr_NoLigatureu8_NoSCMSub(Popt|USMSO_NOCOMBINESTR,Ppdc,Ppgc,xx,Py,Ppfg,Ppbg,Ppu8+startu8,lenu8,Pdddata+startdd,Pdddbcs+startdd,Plcdbcs+startdd,lendd);//~vbm8R~//~vbmcR~
            opt=Popt|USMSO_NOCOMBINESTR;                           //~vbmcI~
            drawtextstr_NoLigatureu8_NoSCMSub(opt,Ppdc,Ppgc,xx,Py,Ppfg,Ppbg,Ppu8+startu8,lenu8,Pdddata+startdd,Pdddbcs+startdd,Plcdbcs+startdd,lendd);//~vbmcI~
        }                                                          //~vbm8I~
    }                                                              //~vbm8I~
    else                                                           //~vbm8I~
    {                                                              //~vbm8I~
    	drawtextstr_NoLigatureu8_NoSCMSub(Popt,Ppdc,Ppgc,Px,Py,Ppfg,Ppbg,Ppu8,Pu8len,Pdddata,Pdddbcs,Plcdbcs,Pddlen);//~vbm8I~
    }                                                              //~vbm8I~
	UTRACEP("%s:substrctr=%d\n",UTT,substrctr);                    //~vbm8I~
    return substrctr;                                              //~vbm8R~
}//drawtextstr_NoLigatureu8_NoSCM                                  //~vbm8I~
#endif //!JJJ                                                      //~vbm8I~
//===============================================================================//~vbkqI~
//draw textstring by utf8 which dose not contain SCM               //~vbkqI~
//consider combining ovf char(>=u20000)                            //~vbkqI~
//===============================================================================//~vbkqI~
#ifdef JJJ                                                         //~vbm8I~
int  drawtextstr_NoLigatureu8_NoSCM(int Popt,CDC *Ppdc,GdkGC *Ppgc,int Px,int Py,GdkColor *Ppfg,GdkColor *Ppbg,//~vbkqR~
#else                                                              //~vbm8I~
int  drawtextstr_NoLigatureu8_NoSCMSub(int Popt,CDC *Ppdc,GdkGC *Ppgc,int Px,int Py,GdkColor *Ppfg,GdkColor *Ppbg,//~vbm8I~
#endif                                                             //~vbm8I~
		char *Ppu8,int Pu8len,char *Pdddata,char *Pdddbcs,char *Plcdbcs,int Pddlen)//~vbkqI~
{                                                                  //~vbkqI~
#ifdef JJJ                                                         //~vbm8I~
    int optusms,swwidth0,writelenlc,xx,swcombinemodeline,writelen;//~vbkqR~//~vbkvR~
    char *pdddata,*plcdbcs,*pdddbcs,*ptext;                        //~vbkqR~
#else                                                              //~vbm8I~
    int optusms,writelenlc,xx;                                     //~vbm8I~
    char *pdddata,*plcdbcs;                                        //~vbm8I~
#endif                                                             //~vbm8I~
	int swligature=0;                                              //~vbmaI~
//  GdkColor fgaltch={0,0/*r*/,0xffff/*g*/,0/*b*/};                //~vbmcI~//~vbA3R~
    GdkColor fgaltch=SfgPadding;                                   //~vbA3I~
//*****************************                                    //~vbkqI~
	UTRACEP("%s:opt=%x,x=%d,y=%d,ddlen=%d\n",UTT,Popt,Px,Py,Pddlen);                                     //~vbkqI~//~vbm8R~//~vbmfR~
	UTRACED("u8",Ppu8,Pu8len);                                     //~vbm8I~
	UTRACED("dddata",Pdddata,Pddlen);                              //~vbkqI~
	UTRACED("dddbcs",Pdddbcs,Pddlen);                              //~vbkqI~
	UTRACED("lcdbcs",Plcdbcs,Pddlen);                              //~vbkqI~
    optusms=Popt;                                                  //~vbkqI~
//    swrtl=optusms & USMSO_RTL;                                   //~vbkqR~
#ifdef JJJ                                                         //~vbm8I~
    ptext=Ppu8,pdddata=Pdddata,pdddbcs=Pdddbcs,plcdbcs=Plcdbcs;    //~vbkqR~
    writelenlc=Pddlen,xx=Px,writelen=Pu8len;                       //~vbkqR~
#else                                                              //~vbm8I~
    pdddata=Pdddata,plcdbcs=Plcdbcs;                               //~vbm8I~
    writelenlc=Pddlen,xx=Px;                                       //~vbm8I~
#endif                                                             //~vbm8I~
#ifdef JJJ                                                         //~vbm8I~
    swcombinemodeline=optusms&USMSO_COMBINEON;	//parm to also draw ligature//~vbkqI~
//  swwidth0Ovf=swutf8data && !swcombinemodeline && xxescr_chkWidth0Ovf(optusms,pdata/*dddata*/,pdddbcs,writelenlc);//~vbkqR~
//  swwidth0Ovf=!swcombinemodeline && xxescr_chkWidth0Ovf(optusms,pdddata,pdddbcs,writelenlc);//~vbkqR~//~vbkvR~
    swwidth0=!swcombinemodeline && xxescr_chkWidth0Ovf(CW0OO_SBCS,pdddata,pdddbcs,writelenlc);//~vbkvI~
//  if (swwidth0Ovf)                                               //~vbkqI~//~vbkvR~
    if (swwidth0)                                                  //~vbkvI~
      	drawtextstr_NoLigatureu8_NoCombine(optusms,Ppdc,Ppgc,xx,Py,Ppfg,Ppbg,ptext/*pu8*/,writelen/*u8len*/,pdddata,pdddbcs,plcdbcs,writelenlc);//~vbkqR~
    else                                                           //~vbkqI~
#endif                                                             //~vbm8I~
    {//!width0Ovf                                                  //~vbkqI~
        UTRACEP("%s:write xx=%d ddlen=%d\n",UTT,xx,Pddlen);        //~vbksR~
        UTRACED("pango_set_text",Ppu8,Pu8len);                     //~vbksI~
    	pango_layout_set_text(Gplayout,Ppu8,Pu8len);               //~vbkqI~
                                                                   //~vbkqI~
//            if (glyphctr>ucsctr)                                 //~vbkqR~
//                optusms|=USMSO_SCM; //may contain Spacing Combining Mark(glpthctr>1)//~vbkqR~
#ifdef JJJ                                                         //~vbm8R~
    		if (swcombinemodeline)                                 //~vbkqI~
            {                                                      //~vbkqI~
            	csub_setcombineLayout(optusms,Gplayout,pdddata,pdddbcs,writelenlc);//~vbkqR~//~vbksR~
            }                                                      //~vbkqI~
#else                                                              //~vbm8I~
          if (Popt & USMSO_COMBINESTR)                             //~vbm8R~//~vbmaR~
          {                                                        //~vbzbI~
			UTRACEP("%s:call usetmonospace len=%d\n",UTT,writelenlc);//~vbzbI~
  			usetmonospaceCombineStr(optusms,Gplayout,pdddata,plcdbcs,writelenlc,Mcellw);//~vbm8I~
          }                                                        //~vbzbI~
          else                                                     //~vbm8I~
          if (xxescr_chkligatureu8(Pdddata,Pdddbcs,Pddlen,0/*Ppglyphctr*/,0/*Ppucsctr*/))	//ligature detected//~vbmaR~
          {                                                        //~vbmaI~
			drawtextstr_NoLigatureu8_NoSCM_Monospace(Popt,Ppdc,Ppgc,Px,Py,Ppfg,Ppbg,Ppu8,Pu8len,Pdddata,Pdddbcs,Plcdbcs,Pddlen);//~vbmaR~
          	swligature=1;                                          //~vbmaR~
          }                                                        //~vbmaI~
          else                                                     //~vbmaI~
#endif                                                             //~vbm8M~
          {                                                        //~vbzbI~
			UTRACEP("%s:call usetmonospace len=%d\n",UTT,writelenlc);//~vbzbI~
  			usetmonospace(optusms,Gplayout,pdddata,plcdbcs,writelenlc,Mcellw);//~vbkqR~
          }                                                        //~vbzbI~
          if (!swligature)                                         //~vbmaI~
          {                                                        //~vbmaI~
			UTRACED("pango setmonospace dddata",pdddata,writelenlc);//~vbkqR~
			UTRACED("pango setmonospace lcdbcs",plcdbcs,writelenlc);//~vbkqI~
			UTRACEP("darwtextstr not ligature gdk_draw_layout_with_colors pos=%d,y=%d\n",xx,Py);//~vbkqI~
            UTRACELAYOUT(Gplayout);                                //~vbkqI~
           if (Popt & USMSO_NOTCOMBINABLE)                         //~vbmcI~
           {                                                       //~vbzbI~
		    UTRACEP("%s:call gdk_draw_layout_with_colors xx=%d,yy=%d,fg=%s,bg=%s\n",UTT,xx,Py,csub_GdkColorToString(&fgaltch),csub_GdkColorToString(Ppbg));//~vbzbR~
//    		gdk_draw_layout_with_colors(Ppdc,Ppgc,xx,Py,Gplayout,&fgaltch,Ppbg);//~vbmcI~//~vbAeR~
            csubDrawLayoutTempColor(Ppdc,Ppgc,xx,Py,Gplayout,&fgaltch,Ppfg,Ppbg); //draw by fgaltch ,then restore layout to Ppfg//~vbAeI~
           }                                                       //~vbzbI~
           else                                                    //~vbmcI~
           {                                                       //~vbzbI~
		    UTRACEP("%s:call gdk_draw_layout_with_colors xx=%d,yy=%d,fg=%s,bg=%s\n",UTT,xx,Py,csub_GdkColorToString(Ppfg),csub_GdkColorToString(Ppbg));//~vbzbR~
    		gdk_draw_layout_with_colors(Ppdc,Ppgc,xx,Py,Gplayout,Ppfg,Ppbg);//~vbkqR~
           }                                                       //~vbzbI~
          }                                                        //~vbmaI~
    }	//!width0Ovf                                               //~vbkqI~
    return 0;                                                      //~vbkqI~
}//drawtextstr_NoLigatureu8_NoSCMSub                               //~vbkqI~//~vbm8R~
//===============================================================================//~vbmaI~
//draw textstring one by one because ligature detected under Lig:Off mode//~vbmaI~
//===============================================================================//~vbmaI~
int  drawtextstr_NoLigatureu8_NoSCM_Monospace(int Popt,CDC *Ppdc,GdkGC *Ppgc,int Px,int Py,GdkColor *Ppfg,GdkColor *Ppbg,//~vbmaI~
		char *Ppu8,int Pu8len,char *Pdddata,char *Pdddbcs,char *Plcdbcs,int Pddlen)//~vbmaI~
{                                                                  //~vbmaI~
    int xx,ii,chsz,lenu8;                                          //~vbmaR~
    char *pdddata,*pdddbcs,*pu8;                                   //~vbmaR~
//*****************************                                    //~vbmaI~
	UTRACEP("%s:x=%d,y=%d,ddlen=%d\n",UTT,Px,Py,Pddlen);           //~vbmaI~
	UTRACED("u8",Ppu8,Pu8len);                                     //~vbmaI~
	UTRACED("dddata",Pdddata,Pddlen);                              //~vbmaI~
	UTRACED("dddbcs",Pdddbcs,Pddlen);                              //~vbmaI~
	UTRACED("lcdbcs",Plcdbcs,Pddlen);                              //~vbmaI~
    ii=0;                                                          //~vbAqI~
    for (pu8=Ppu8,pdddata=Pdddata,pdddbcs=Pdddbcs,xx=Px;ii<Pddlen;ii+=chsz,pu8+=lenu8,pdddata+=chsz,pdddbcs+=chsz,xx+=chsz*Mcellw)//~vbmaI~
    {                                                              //~vbmaI~
    	UTF_GETDDUCS1VIO(pdddata,pdddbcs,Pddlen-ii,&chsz);         //~vbmaR~
        lenu8=UTF8CHARLEN(*pu8);                                   //~vbmaI~
        pango_layout_set_text(Gplayout,pu8,lenu8);                 //~vbmaI~
        gdk_draw_layout_with_colors(Ppdc,Ppgc,xx,Py,Gplayout,Ppfg,Ppbg);//~vbmaI~
		UTRACEP("%s:x=%d,y=%d\n",UTT,Px,Py);                       //~vbmaI~
		UTRACED("u8",pu8,lenu8);                                   //~vbmaR~
    }                                                              //~vbmaI~
    return 0;                                                      //~vbmaI~
}//drawtextstr_NoLigatureu8_NoSCM_Monospace                        //~vbmaI~
//===============================================================================//~vbm2I~
//draw textstring by utf8 considering SCM under Ligature:ON and COMBINE:SPLIT//~vbm2I~
//SCM generate 2 glyph(with prev ucs when combined or 1 ucs 1tself //~vbm2I~
//===============================================================================//~vbm2I~
int  drawtextstr_ligatureu8_SCM(int Popt,CDC *Ppdc,GdkGC *Ppgc,int Px,int Py,GdkColor *Ppfg,GdkColor *Ppbg,char *Ppu8,int Pu8len,char *Pdddata,char *Pdddbcs,char *Plcdbcs,int Pddlen)//~vbm2R~
{                                                                  //~vbm2I~
    int xx,reslen,optusms,stru8len,strddlen;                       //~vbm2I~
    int chsz,chszo,lenu8,lenu8o,swscm,swscmo,ucs,scmucsctr;        //~vbm2I~
    char *pdata,*pdbcs,*plcdbcs,*pu8;                              //~vbm2I~
    char *pstru8start,*pstrdatastart,*pstrdbcsstart,*pstrlcdbcsstart;//~vbm2I~
    int strwidth;                                                  //~vbm2I~
//  GdkColor fgaltch={0,0/*r*/,0xffff/*g*/,0/*b*/};                //~vbmfI~//~vbA3R~
    GdkColor fgaltch=SfgPadding;                                   //~vbA3I~
//************************************                             //~vbm2I~
	UTRACEP("%s:opt=%04x,xx=%d,yy=%d,fg=%04x,bg=%04x\n",UTT,Popt,Px,Py,Ppfg,Ppbg);//~vbm2I~
	UTRACED("u8data",Ppu8,Pu8len);                                 //~vbm2I~
	UTRACED("dddata",Pdddata,Pddlen);                              //~vbm2I~
	UTRACED("dddbcs",Pdddbcs,Pddlen);                              //~vbm2I~
    optusms=Popt;                                                  //~vbm2I~
    xx=Px;                                                         //~vbm2I~
    strddlen=0,stru8len=0;                                         //~vbm2I~
    pstru8start=Ppu8,pstrdbcsstart=Pdddbcs,pstrdatastart=Pdddata,pstrlcdbcsstart=Plcdbcs;//~vbm2I~
    chsz=0,lenu8=0,swscm=0;                                        //~vbm2I~
    for (pu8=Ppu8,pdata=Pdddata,pdbcs=Pdddbcs,plcdbcs=Plcdbcs,reslen=Pddlen;reslen>0;pu8+=lenu8,pdata+=chsz,pdbcs+=chsz,plcdbcs+=chsz,reslen-=chsz)//~vbm2I~
    {                                                              //~vbm2I~
        chszo=chsz;                                                //~vbm2I~
        lenu8o=lenu8;                                              //~vbm2I~
        swscmo=swscm;                                              //~vbm2I~
        UTRACEP("%s:ch=%0x,dbcs=%0x,reslen=%d\n",UTT,*pdata,*pdbcs,reslen);//~vbm2I~
        if (!*pdbcs)                                               //~vbm2I~
        {                                                          //~vbm2I~
	        ucs=*pdata;                                            //~vbm2I~
        	lenu8=1;                                               //~vbm2I~
            chsz=1;                                                //~vbm2I~
            swscm=0;                                               //~vbm2I~
        }                                                          //~vbm2I~
        else                                                       //~vbm2I~
        {                                                          //~vbm2I~
        	lenu8=UTF8CHARLEN(*pu8);                               //~vbm2I~
			ucs=UTF_GETDDUCS1VIO(pdata,pdbcs,reslen,&chsz);        //~vbm2I~
            swscm=csub_isSpacingCombiningMark(0,ucs);              //~vbm2I~
        }                                                          //~vbm2I~
        UTRACEP("%s:ucs=%04x,scm=%d\n",UTT,ucs,swscm);             //~vbm2I~
        if (swscm)                                                 //~vbm2I~
        {                                                          //~vbm2I~
        	if (!swscmo)	//not continued scm                    //~vbm2I~
            {                                                      //~vbm2I~
        		stru8len=PTRDIFF(pu8,pstru8start)-lenu8o;          //~vbm2I~
        		strddlen=PTRDIFF(pdbcs,pstrdbcsstart)-chszo;       //~vbm2I~
            }                                                      //~vbm2I~
            else                                                   //~vbm2I~
            {                                                      //~vbm2I~
        		stru8len=0;                                        //~vbm2I~
        		strddlen=0;                                        //~vbm2I~
            }                                                      //~vbm2I~
            if (stru8len)                                          //~vbm2I~
            {                                                      //~vbm2I~
//*draw str before SCM                                             //~vbm2I~
                UTRACEP("%s:before scm xx=%d,strddlen=%d\n",UTT,xx,strddlen);//~vbm2I~
                UTRACED("before scm u8",pstru8start,stru8len);     //~vbm2I~
                UTRACED("before scm data",pstrdatastart,strddlen); //~vbm2I~
                UTRACED("before scm dbcs",pstrdbcsstart,strddlen); //~vbm2I~
      	        strwidth=drawtextstr_ligatureu8_nocombine(Popt,Ppdc,Ppgc,xx,Py,Ppfg,Ppbg,pstru8start,stru8len,pstrdatastart,pstrdbcsstart,pstrlcdbcsstart,strddlen);//~vbm2R~
	            xx+=strwidth;                                      //~vbm2R~
            }                                                      //~vbm2I~
//*draw SCM   with/without prev char                               //~vbm2I~
        	if (swscmo)      //no combine,write itselg             //~vbm2I~
            {                                                      //~vbm2I~
            	pstru8start=pu8;                                   //~vbm2I~
            	pstrdatastart=pdata;                               //~vbm2I~
            	pstrdbcsstart=pdbcs;                               //~vbm2I~
            	pstrlcdbcsstart=plcdbcs;                           //~vbm2I~
                stru8len=lenu8;                                    //~vbm2I~
                strddlen=chsz;                                     //~vbm2I~
                scmucsctr=1;                                       //~vbm2I~
            }                                                      //~vbm2I~
            else           //write with prev char                  //~vbm2R~
            {                                                      //~vbm2I~
//      	  if (((Popt & USMSO_COMBINEOF) && !UTF_COMBINEMODE_NP())    //combine split//~vbm2I~
//            && (lenu8o!=U8SZ_ZWNJ || memcmp(pstru8start,U8_ZWNJ,U8SZ_ZWNJ)) //prev is not ZWNJ//~vbm2R~
//            )                                                    //~vbm2I~
//            if (lenu8o!=U8SZ_ZWNJ || memcmp(pstru8start,U8_ZWNJ,U8SZ_ZWNJ)) //prev is not ZWNJ//~vbm2I~//~vbmfR~
              {                                                    //~vbm2I~
//*put twice base and ZWNJ+SCM                                     //~vbm2I~
	            	pstru8start+=stru8len;                         //~vbm2I~
	            	stru8len=lenu8o;                               //~vbm2I~
		            UTRACED("before scm single write pango_set_text",pstru8start,stru8len);//~vbm2R~
            		pango_layout_set_text(Gplayout,pstru8start,lenu8o);//~vbm2I~
					UTRACEP("%s:call usetmonospace len=%d\n",UTT,chszo);//~vbzbI~
	  				usetmonospace_SCM(optusms,Gplayout,chszo,Mcellw);//~vbm2I~
				    UTRACEP("%s:call gdk_draw_layout_with_colors xx=%d,yy=%d,fg=%s,bg=%s\n",UTT,xx,Py,csub_GdkColorToString(Ppfg),csub_GdkColorToString(Ppbg));//~vbzbR~
            		gdk_draw_layout_with_colors(Ppdc,Ppgc,xx,Py,Gplayout,Ppfg,Ppbg);//~vbm2I~
                    xx+=chszo*Mcellw;                              //~vbm2I~
                    pstru8start=pu8;                               //~vbm2I~
                    stru8len=lenu8;                                //~vbm2I~
                    scmucsctr=1;                                   //~vbm2I~
		            strddlen=chsz;   //write pos of next char      //~vbm2I~
              }                                                    //~vbm2I~
//            else                                                 //~vbm2I~//~vbmfR~
//            {                                                    //~vbm2I~//~vbmfR~
//          	pstru8start=pu8-lenu8o;                            //~vbm2I~//~vbmfR~
//          	pstrdatastart=pdata-chszo;                         //~vbm2I~//~vbmfR~
//          	pstrdbcsstart=pdbcs-chszo;                         //~vbm2I~//~vbmfR~
//          	pstrlcdbcsstart=plcdbcs-chszo;                     //~vbm2I~//~vbmfR~
//              stru8len=lenu8+lenu8o;                             //~vbm2I~//~vbmfR~
//              strddlen=chszo+chsz;                               //~vbm2I~//~vbmfR~
//              scmucsctr=2;                                       //~vbm2I~//~vbmfR~
//            }                                                    //~vbm2I~//~vbmfR~
            }                                                      //~vbm2I~
            UTRACEP("%s:write scm xx=%d,scmucsctr=%d\n",UTT,xx,scmucsctr);//~vbm2I~
            UTRACED("pango_set_text",pstru8start,stru8len);        //~vbm2I~
            pango_layout_set_text(Gplayout,pstru8start,stru8len);  //~vbm2I~
			UTRACEP("%s:call usetmonospace len=%d\n",UTT,scmucsctr);//~vbzbR~
	  		usetmonospace_SCM(optusms,Gplayout,scmucsctr,Mcellw);  //~vbm2I~
      	  if ((Popt & USMSO_VHEXDATACPOS) && xx==SxxVhexDataCpos)  //~vbDsI~
          {                                                        //~vbDsI~
		    UTRACEP("%s:skip set textcolor altch by SxxVhexDataCpos xx=%d\n",UTT,xx);//~vbDsI~
            gdk_draw_layout_with_colors(Ppdc,Ppgc,xx,Py,Gplayout,Ppfg,Ppbg);//~vbDsI~
          }                                                        //~vbDsI~
          else                                                     //~vbDsI~
          {                                                        //~vbDsI~
//          gdk_draw_layout_with_colors(Ppdc,Ppgc,xx,Py,Gplayout,Ppfg,Ppbg);//~vbm2I~//~vbmfR~
		    UTRACEP("%s:call gdk_draw_layout_with_colors xx=%d,yy=%d,fg=%s,bg=%s\n",UTT,xx,Py,csub_GdkColorToString(&fgaltch),csub_GdkColorToString(Ppbg));//~vbzbR~
//          gdk_draw_layout_with_colors(Ppdc,Ppgc,xx,Py,Gplayout,&fgaltch,Ppbg);//~vbmfI~//~vbA3R~
            csubDrawLayoutTempColor(Ppdc,Ppgc,xx,Py,Gplayout,&fgaltch,Ppfg,Ppbg);//~vbA3R~
          }                                                        //~vbDsI~
			pstru8start=pu8+lenu8;                                 //~vbm2I~
			pstrdatastart=pdata+chsz;                              //~vbm2I~
			pstrdbcsstart=pdbcs+chsz;                              //~vbm2I~
			pstrlcdbcsstart=plcdbcs+chsz;                          //~vbm2I~
	        xx+=strddlen*Mcellw;                                   //~vbm2I~
        }                                                          //~vbm2I~
    }//for                                                         //~vbm2I~
    stru8len=PTRDIFF(pu8,pstru8start);                             //~vbm2I~
    strddlen=PTRDIFF(pdbcs,pstrdbcsstart);                         //~vbm2I~
    if (stru8len)                                                  //~vbm2I~
    {                                                              //~vbm2I~
                UTRACEP("%s:last xx=%d,strddlen=%d\n",UTT,xx,strddlen);//~vbm2I~
                UTRACED("last noscm u8",pstru8start,stru8len);     //~vbm2I~
                UTRACED("last noscm data",pstrdatastart,strddlen); //~vbm2I~
                UTRACED("last noscm dbcs",pstrdbcsstart,strddlen); //~vbm2I~
//  	drawtextstr_NoLigatureu8_NoSCM(Popt,Ppdc,Ppgc,xx,Py,Ppfg,Ppbg,pstru8start,stru8len,pstrdatastart,pstrdbcsstart,pstrlcdbcsstart,strddlen);//~vbm2I~//~vbm8R~
      	strwidth=drawtextstr_ligatureu8_nocombine(Popt,Ppdc,Ppgc,xx,Py,Ppfg,Ppbg,pstru8start,stru8len,pstrdatastart,pstrdbcsstart,pstrlcdbcsstart,strddlen);//~vbm2I~
	    xx+=strwidth;                                              //~vbm2I~
    }                                                              //~vbm2I~
    UTRACEP("%s:return xx=%d\n",UTT,xx);                           //~vbm2I~
    return xx;                                                     //~vbm2I~
}//drawtextstr_ligatureu8_SCM                                      //~vbm2R~
//===============================================================================//~vbAhI~
//=Lig:off,Comb:off/off                                            //~vbAhR~
//===============================================================================//~vbAhI~
int drawSplitCombineNoLigature(int Popt,CDC *Ppdc,GdkGC *Ppgc,int Px,int Py,GdkColor *Ppfg,GdkColor *Ppbg,char *Ppu8,int Pu8len)//~vbAhR~
{                                                                  //~vbAhI~
	char textDraw[16];                                             //~vbAhI~
    GdkColor fgaltch=SfgPadding;                                   //~vbAhI~
    int layoutlen;                                                 //~vbAhI~
    //*************************                                    //~vbAhI~
    UTRACEP("%s:opt=0x%04x,Px=%d,fg=%s\n",UTT,Popt,Px,COLOR2STRING(Ppfg));//~vbAhR~
	UTRACED("stru8",Ppu8,Pu8len);                                  //~vbAhI~
    int altch=isZWJZWNJ(ISZO_ALTCH,Ppu8,Pu8len);  //len=3 and ZWJ  //~vbAhR~
    if (!altch)                                                    //~vbAkI~
	    altch=getFormatAltchar(0,Ppu8,Pu8len);                     //~vbAkI~
    int len=min(Pu8len,sizeof(textDraw)-1);                        //~vbAhI~
  if (!altch)                                                      //~vbAhR~
  {                                                                //~vbAhM~
    memcpy(textDraw,Ppu8,len);                                     //~vbAhI~
    *(textDraw+len)=PADDING_SPLITCOMB; //0xa0                      //~vbAhR~
    len++;                                                         //~vbAhI~
  }                                                                //~vbAhI~
  else                                                             //~vbAhI~
  {                                                                //~vbAhI~
    textDraw[0]=altch;   //'+'                                     //~vbAhR~
    len=1;                                                         //~vbAhI~
  }                                                                //~vbAhI~
	pango_layout_set_text(Gplayout,textDraw,len);                  //~vbAhR~
    if (Popt & USMSO_COMBINEON)	//not green if comb on             //~vbAhR~
    {                                                              //~vbDsI~
      if ((Popt & USMSO_VHEXDATACPOS) && Px==SxxVhexDataCpos)      //~vbDsR~
      {                                                            //~vbDsI~
      	UTRACEP("%s:NoRep split combining color Px=%d,Ppfg=%s\n",UTT,Px,COLOR2STRING(Ppfg));//~vbDsR~
    	gdk_draw_layout_with_colors(Ppdc,Ppgc,Px,Py,Gplayout,Ppfg,Ppbg);//~vbDsI~
      }                                                            //~vbDsI~
      else                                                         //~vbDsI~
      {                                                            //~vbDsI~
      	UTRACEP("%s:Rep split combining color Px=%d,SxxVhexdataCpos=%d,Ppfg=%s,fgaltch=%s\n",UTT,Px,SxxVhexDataCpos,COLOR2STRING(Ppfg),COLOR2STRING(&fgaltch));//~vbDsR~
		csubDrawLayoutTempColor(Ppdc,Ppgc,Px,Py,Gplayout,&fgaltch,Ppfg,Ppbg);//~vbAhI~
      }                                                            //~vbDsI~
    }                                                              //~vbDsI~
    else                                                           //~vbAhI~
    {                                                              //~vbDsI~
      	UTRACEP("%s:NoRep COMBINEOFF Px=%d,Ppfg=%s\n",UTT,Px,COLOR2STRING(Ppfg));//~vbDsI~
#ifndef KKK                                                        //~v7f4I~
      if (altch                                                    //~v7f4R~
      && !((Popt & USMSO_VHEXDATACPOS) && Px==SxxVhexDataCpos)     //~v7f4I~
      )                                                            //~v7f4I~
		csubDrawLayoutTempColor(Ppdc,Ppgc,Px,Py,Gplayout,&fgaltch,Ppfg,Ppbg);//~v7f4I~
      else                                                         //~v7f4I~
#endif                                                             //~v7f4I~
    	gdk_draw_layout_with_colors(Ppdc,Ppgc,Px,Py,Gplayout,Ppfg,Ppbg);//~vbAhR~
    }                                                              //~vbDsI~
  if (!altch)                                                      //~vbAhR~
  {                                                                //~vbAhI~
    layoutlen=csubGetLayoutTextLen(USMSO_SPLITPADDED,Gplayout);    //~vbAhR~
    textDraw[0]=' ';                                               //~vbAhI~
    textDraw[1]=' ';                                               //~vbAhI~
	pango_layout_set_text(Gplayout,textDraw,2);                    //~vbAhI~
	UTRACEP("%s:clear comb last padding xx=%d\n",UTT,Px+layoutlen);//~vbAhR~
	gdk_draw_layout_with_colors(Ppdc,Ppgc,Px+layoutlen,Py,Gplayout,Ppfg,Ppbg);//~vbAhR~
  }                                                                //~vbAhI~
  else                                                             //~vbAhI~
  {                                                                //~vbAhI~
    layoutlen=csubGetLayoutTextLen(0,Gplayout);                    //~vbAhI~
	UTRACEP("%s:ZWJ Px=%d,layoutlen=%d\n",UTT,Px,layoutlen);       //~vbAhI~
  }                                                                //~vbAhI~
    return layoutlen;                                              //~vbAhR~
}//drawSplitCombineNoLigature                                      //~vbAhR~
//===============================================================================//~vbAhI~
//=Lig:on,split Combining                                          //~vbAhR~
//===============================================================================//~vbAhI~
int drawSplitCombineLigature(int Popt,CDC *Ppdc,GdkGC *Ppgc,int Px,int Py,GdkColor *Ppfg,GdkColor *Ppbg,char *Ppu8,int Pu8len,char *Plcdbcs,int Plclen)//~vbAhR~
{                                                                  //~vbAhI~
	char textDraw[16];                                             //~vbAhI~
	char lcdbcs[16];                                               //~vbAhI~
    int strwidth,opt;                                              //~vbAhR~
    //*************************                                    //~vbAhI~
    UTRACEP("%s:opt=0x%04x,Px=%d\n",UTT,Popt,Px);                  //~vbAhI~
	UTRACED("stru8",Ppu8,Pu8len);                                  //~vbAhI~
    int altch=isZWJZWNJ(ISZO_ALTCH,Ppu8,Pu8len);  //len=3 and ZWJ  //~vbAhR~
    if (!altch)                                                    //~vbAkI~
	    altch=getFormatAltchar(0,Ppu8,Pu8len);                     //~vbAkI~
    int len=min(Pu8len,sizeof(textDraw)-1);                        //~vbAhI~
    int lclen=Plclen;                                              //~vbAhI~
  if (!altch)                                                      //~vbAhR~
  {                                                                //~vbAhI~
    memcpy(textDraw,Ppu8,len);                                     //~vbAhI~
    memcpy(lcdbcs,Plcdbcs,Plclen);                                 //~vbAhI~
    *(lcdbcs+Plclen)=0;                                            //~vbAhI~
    *(textDraw+len)=PADDING_SPLITCOMB; //0xa0                      //~vbAhI~
    len++;                                                         //~vbAhI~
    lclen++;                                                       //~vbAhI~
    opt=Popt|USMSO_SPLITPADDED;                                    //~vbAhI~
  }                                                                //~vbAhI~
  else                                                             //~vbAhI~
  {                                                                //~vbAhI~
    textDraw[0]=altch;   //'+'                                     //~vbAhR~
    lcdbcs[0]=0;                                                   //~vbAhI~
    len=1;                                                         //~vbAhI~
    lclen=1;                                                       //~vbAhI~
    opt=Popt;                                                      //~vbAhI~
  }                                                                //~vbAhI~
	pango_layout_set_text(Gplayout,textDraw,len);                  //~vbAhI~
    gdk_draw_layout_with_colors(Ppdc,Ppgc,Px,Py,Gplayout,Ppfg,Ppbg);//~vbAhI~
//  usetmonospace_ligature(Popt|USMSO_SBCSCOMBSPLIT,Gplayout,textDraw,lcdbcs,Plclen+1,Mcellw,&strwidth); //split mode,chk 2 gliph and  2nd is width=0//~vbAhR~
    usetmonospace_ligature(opt,Gplayout,textDraw,lcdbcs,lclen,Mcellw,&strwidth); //split mode,chk 2 gliph and  2nd is width=0//~vbAhR~
	UTRACEP("%s:usetmonospace_ligature strwidth=%d\n",UTT,strwidth);//~vbAhI~
//  int layoutlen=csubGetLayoutTextLen(USMSO_SPLITPADDED,Gplayout);//~vbAhR~
    int layoutlen=strwidth;                                        //~vbAhI~
  if (!altch)                                                      //~vbAhR~
  {                                                                //~vbAhI~
    textDraw[0]=' ';                                               //~vbAhI~
    textDraw[1]=' ';                                               //~vbAhI~
	pango_layout_set_text(Gplayout,textDraw,2);                    //~vbAhI~
	gdk_draw_layout_with_colors(Ppdc,Ppgc,Px+layoutlen,Py,Gplayout,Ppfg,Ppbg);//~vbAhI~
	UTRACEP("clear comb last padding xx=%d,leyoutlen=%d\n",Px+layoutlen,layoutlen);//~vbAhI~
  }                                                                //~vbAhI~
  else                                                             //~vbAhI~
  {                                                                //~vbAhI~
	UTRACEP("%s:ZWJ Px=%d,layoutlen=%d\n",UTT,Px,layoutlen);       //~vbAhI~
  }                                                                //~vbAhI~
    return layoutlen;                                              //~vbAhI~
}//drawSplitCombineLigature                                        //~vbAhR~
#ifdef GGG //common to drawSplitCombineLigature                    //~vbAhI~
//===============================================================================//~vbAhI~
//draw split combining itself                                      //~vbAhI~
//===============================================================================//~vbAhI~
void setSplitCombine(int Popt,char *Ppu8,int Plenu8,char *Pplcdbcs,int Pchsz,int *Ppstrwidth)//~vbAhI~
{                                                                  //~vbAhI~
	char textDraw[16];                                         //~vbAfI~//~vbAhI~
	char lcdbcs[16];                                               //~vbAhI~
    int strwidth;                                                  //~vbAhI~
//**********************                                           //~vbAhI~
	UTRACEP("%s:opt=0x%04x,chsz=%d\n",UTT,Popt,Pchsz);             //~vbAhR~
	UTRACED("Ppu8",Ppu8,Plenu8);                                   //~vbAhI~
	UTRACED("lcdbcs",Pplcdbcs,Pchsz);                              //~vbAhI~
    memcpy(textDraw,Ppu8,Plenu8);                                //~vbAfR~//~vbAhI~
    memcpy(lcdbcs,Pplcdbcs,Pchsz);                                 //~vbAhI~
    *(textDraw+Plenu8)=PADDING_SPLITCOMB; //0xa0                   //~vbAhR~
    *(lcdbcs+Pchsz)=0;                                             //~vbAhI~
    pango_layout_set_text(Gplayout,textDraw,Plenu8+1);          //~vbAfI~//~vbAhI~
    int opt=Popt | USMSO_SPLITPADDED; //   0x2000 //split combining with dummy trailer padding//~vbAhI~
	usetmonospace_ligature(opt,Gplayout,textDraw,lcdbcs,Pchsz+1,Mcellw,&strwidth);//~vbAfI~//~vbAhI~
    *Ppstrwidth=strwidth;                                          //~vbAhI~
	UTRACEP("%s:strwidth=%d\n",UTT,*Ppstrwidth);                   //~vbAhI~
}//setSplitCombine                                                 //~vbAhI~
#endif //GGG                                                       //~vbAhI~
//===============================================================================//~vbmfI~
//draw textstring by utf8 considering SCM/Combining is after combinable under Ligature:ON and UNICOMB=COMB//~vbmfI~
//===============================================================================//~vbmfI~
int drawtextstr_ligatureu8_chkcombinesplit(int Popt,CDC *Ppdc,GdkGC *Ppgc,int Px,int Py,GdkColor *Ppfg,GdkColor *Ppbg,char *Ppu8,int Pu8len,char *Pdddata,char *Pdddbcs,char *Plcdbcs,int Pddlen)//~vbmfI~
{                                                                  //~vbmfI~
    int xx,reslen,optusms,stru8len,strddlen;                       //~vbmfI~
    int chsz,lenu8,swcomb,swcombo;                                 //~vbmfR~
    char *pdata,*pdbcs,*plcdbcs,*pu8;                              //~vbmfI~
    char *pstru8start,*pstrdatastart,*pstrdbcsstart,*pstrlcdbcsstart;//~vbmfI~
    int strwidth,swsplit,swsplitout=0,swcombinable=0;              //~vbmfR~
//  GdkColor fgaltch={0,0/*r*/,0xffff/*g*/,0/*b*/};                //~vbmfI~//~vbA3R~
    GdkColor fgaltch=SfgPadding;                                   //~vbA3I~
	gunichar ucs,prevucs;                                          //~vbmfR~
//************************************                             //~vbmfI~
	UTRACEP("%s:opt=%04x,xx=%d,yy=%d,fg=%04x,bg=%04x\n",UTT,Popt,Px,Py,Ppfg,Ppbg);//~vbmfI~
	UTRACED("u8data",Ppu8,Pu8len);                                 //~vbmfI~
	UTRACED("dddata",Pdddata,Pddlen);                              //~vbmfI~
	UTRACED("dddbcs",Pdddbcs,Pddlen);                              //~vbmfI~
	UTRACED("lcdbcs",Plcdbcs,Pddlen);                              //~vbmfI~
    optusms=Popt;                                                  //~vbmfI~
    xx=Px;                                                         //~vbmfI~
    strddlen=0,stru8len=0;                                         //~vbmfI~
    pstru8start=0,pstrdbcsstart=Pdddbcs,pstrdatastart=Pdddata,pstrlcdbcsstart=Plcdbcs;//~vbmfR~
    pstrdatastart=pstrdatastart;                                   //~vbmfI~
    swcomb=0,ucs=0,swsplit=0;                                      //~vbmfR~
    for (pu8=Ppu8,pdata=Pdddata,pdbcs=Pdddbcs,plcdbcs=Plcdbcs,reslen=Pddlen;reslen>0;pu8+=lenu8,pdata+=chsz,pdbcs+=chsz,plcdbcs+=chsz,reslen-=chsz)//~vbmfI~
    {                                                              //~vbmfI~
        prevucs=ucs;                                               //~vbmfI~
        swcombo=swcomb;                                            //~vbmfI~
        UTRACEP("%s:ch=%0x,dbcs=%0x,reslen=%d\n",UTT,*pdata,*pdbcs,reslen);//~vbmfI~
        if (!*pdbcs)                                               //~vbmfI~
        {                                                          //~vbmfI~
	        ucs=*pdata;                                            //~vbmfI~
        	lenu8=1;                                               //~vbmfI~
            chsz=1;                                                //~vbmfI~
            swcomb=0;                                              //~vbmfI~
        }                                                          //~vbmfI~
        else                                                       //~vbmfI~
        {                                                          //~vbmfI~
        	lenu8=UTF8CHARLEN(*pu8);                               //~vbmfI~
            swcomb=csub_iscombining(0,pdata,pdbcs,reslen,&ucs,&chsz);//~vbmfI~
        }                                                          //~vbmfI~
        stru8len=0;                                                //~vbmfI~
        if (swcomb)                                                //~vbmfI~
        {                                                          //~vbmfI~
        	if (swcombo)                                           //~vbmfI~
		    	swcombinable=(swsplit==0);                         //~vbmfI~
            else                                                   //~vbmfI~
		    	swcombinable=UTF_COMBINABLE(prevucs);              //~vbmfR~
        	if (!swcombinable)	//prev char is not base            //~vbmfR~
            {                                                      //~vbmfI~
                if (pstru8start)                                   //~vbmfR~
                {                                                  //~vbmfI~
        			stru8len=PTRDIFF(pu8,pstru8start);             //~vbmfR~
	        		strddlen=PTRDIFF(pdbcs,pstrdbcsstart);         //~vbmfR~
                }                                                  //~vbmfI~
                swsplit=1;                                         //~vbmfI~
            	swsplitout=1;                                      //~vbmfM~
            }                                                      //~vbmfI~
    	}                                                          //~vbmfI~
        else  //not comb                                           //~vbmfR~
        if (!pstru8start)                                          //~vbmfI~
        {                                                          //~vbmfI~
            pstru8start=pu8;                                       //~vbmfR~
            pstrdatastart=pdata;                                   //~vbmfR~
            pstrdbcsstart=pdbcs;                                   //~vbmfR~
            pstrlcdbcsstart=plcdbcs;                               //~vbmfR~
            swsplit=0;                                             //~vbmfI~
        }                                                          //~vbmfI~
        UTRACEP("%s:ucs=%04x,prev combinable=%d,swcomb=%d,swsplit=%d,stru8len=%d\n",UTT,ucs,swcombinable,swcomb,swsplit,stru8len);//~vbmfR~
        if (stru8len)	//string split by combine/scm following combinable//~vbmfI~
        {                                                          //~vbmfI~
//*draw str before comb                                            //~vbmfI~
        	UTRACEP("%s:before comb xx=%d,stru8len=%d\n",UTT,xx,stru8len);//~vbmfI~
            UTRACED("before comb settext",pstru8start,stru8len);   //~vbmfR~
            UTRACED("before comb data",pstrdatastart,strddlen);    //~vbmfI~
            UTRACED("before comb dbcs",pstrdbcsstart,strddlen);    //~vbmfI~
            UTRACED("before comb dbcs",pstrlcdbcsstart,strddlen);  //~vbmfR~
	        pango_layout_set_text(Gplayout,pstru8start,stru8len);  //~vbmfI~
	        usetmonospace_ligature(optusms,Gplayout,pstru8start,pstrlcdbcsstart,strddlen,Mcellw,&strwidth);//~vbmfR~
        	gdk_draw_layout_with_colors(Ppdc,Ppgc,xx,Py,Gplayout,Ppfg,Ppbg);//~vbmfI~
        	xx+=strwidth;                                          //~vbmfI~
        	UTRACEP("%s:drawlayout before comb split strwidth=%d,xx=%d\n",UTT,strwidth,xx);//~vbmfI~
            pstru8start=0;                                         //~vbmfR~
        }                                                          //~vbmfI~
        if (swsplit)                                               //~vbmfR~
        {                                                          //~vbmfI~
#ifdef GGG                                                         //~vbAfR~
	        pango_layout_set_text(Gplayout,pu8,lenu8);             //~vbmfR~
        	UTRACEP("%s:comb split xx=%d,ucs=%06x\n",UTT,xx,ucs);  //~vbmfR~//~vbAhR~
        	UTRACED("comb split settext",pu8,lenu8);               //~vbmfI~
	        usetmonospace_ligature(optusms,Gplayout,pu8,plcdbcs,chsz,Mcellw,&strwidth);//~vbmfI~
//        	gdk_draw_layout_with_colors(Ppdc,Ppgc,xx,Py,Gplayout,&fgaltch,Ppbg);//~vbmfI~//~vbA3R~
          	csubDrawLayoutTempColor(Ppdc,Ppgc,xx,Py,Gplayout,&fgaltch,Ppfg,Ppbg);//~vbA3I~
#else                                                              //~vbAfI~//~vbAhM~
//  		setSplitCombine(optusms,pu8,lenu8,plcdbcs,chsz,&strwidth);//~vbAhI~
          if (!(Popt & USMSO_VHEXDATACPOS))                        //~vbDsR~
			csub_layout_set_textcolor(Gplayout,&fgaltch,Ppbg);//gdk_draw_layout_with_colors() ignore color parameter//~vbAhI~
			strwidth=drawSplitCombineLigature(optusms,Ppdc,Ppgc,xx,Py,&fgaltch,Ppbg,pu8,lenu8,plcdbcs,chsz);//~vbAhI~
          if (!(Popt & USMSO_VHEXDATACPOS))                        //~vbDsR~
			csub_layout_set_textcolor(Gplayout,Ppfg,Ppbg);//restore for not COMBINE NP/SPLIT//~vbAhI~
#endif                                                             //~vbAfI~//~vbAhM~
        	xx+=strwidth;                                          //~vbmfI~
        	UTRACEP("%s:drawlayout comb split strwidth=%d,xx=%d\n",UTT,strwidth,xx);//~vbmfI~
        }                                                          //~vbmfI~
    }//for                                                         //~vbmfI~
    if (swsplitout)                                                //~vbmfR~
    {                                                              //~vbmfI~
    	if (pstru8start)                                           //~vbmfI~
        {                                                          //~vbmfR~
            stru8len=PTRDIFF(pu8,pstru8start);                     //~vbmfR~
            strddlen=PTRDIFF(pdbcs,pstrdbcsstart);                 //~vbmfR~
            if (stru8len>0)                                        //~vbmfR~
            {                                                      //~vbmfR~
                UTRACEP("%s:last xx=%d,strddlen=%d\n",UTT,xx,strddlen);//~vbmfR~
                UTRACED("last nocomb settext",pstru8start,stru8len);//~vbmfR~
                UTRACED("last nocomb data",pstrdatastart,strddlen);//~vbmfR~
                UTRACED("last nocomb dbcs",pstrdbcsstart,strddlen);//~vbmfR~
                UTRACED("last nocomb lcdbcs",pstrlcdbcsstart,strddlen);//~vbmfR~
                pango_layout_set_text(Gplayout,pstru8start,stru8len);//~vbmfR~
                usetmonospace_ligature(optusms,Gplayout,pstru8start,pstrlcdbcsstart,strddlen,Mcellw,&strwidth);//~vbmfR~
                gdk_draw_layout_with_colors(Ppdc,Ppgc,xx,Py,Gplayout,Ppfg,Ppbg);//~vbmfR~
                xx+=strwidth;                                      //~vbmfR~
                UTRACEP("%s:drawlayout last strwidth=%d,xx=%d\n",UTT,strwidth,xx);//~vbmfI~
            }                                                      //~vbmfR~
        }
    }                                                              //~vbmfI~
    else                                                           //~vbmfI~
    	xx=0;                                                      //~vbmfI~
    UTRACEP("%s:return xx=%d\n",UTT,xx);                           //~vbmfI~
    return xx;                                                     //~vbmfI~
}//drawtextstr_ligatureu8_chkcombinesplit                          //~vbmfI~
//===============================================================================//~vbAhI~
//if len=3, rc=1:ZWJ,rc=-1:ZWNJ, if len>3, 2 and -2                //~vbAhR~
//===============================================================================//~vbAhI~
int isZWJZWNJ(int Popt,char *Ppu8,int Pu8len)                      //~vbAhI~
{                                                                  //~vbAhI~
    int altch=0;                                                   //~vbAhI~
	int rc=0;                                                      //~vbAhI~
    if (Pu8len>=3)                                                 //~vbAhR~
    {                                                              //~vbAhI~
        if (!memcmp(Ppu8,U8_ZWJ,3))                                //~vbAhI~
        {                                                          //~vbAhI~
        	rc=1;                                                  //~vbAhI~
            altch=UVIOM_ALTCH_ZWJ;   //'+'                         //~vbAhI~
        }                                                          //~vbAhI~
        else                                                       //~vbAhI~
        if (!memcmp(Ppu8,U8_ZWNJ,3))                               //~vbAhI~
        {                                                          //~vbAhI~
        	rc=-1;                                                 //~vbAhR~
            altch=UVIOM_ALTCH_ZWNJ;   //'-'                        //~vbAhI~
        }                                                          //~vbAhI~
        if (Pu8len>3)                                              //~vbAhR~
        	rc*=2;                                                 //~vbAhR~
    }                                                              //~vbAhI~
	if (Popt & ISZO_ALTCH)//           0x01 //return altch         //~vbAhI~
    	rc=altch;                                                  //~vbAhI~
    UTRACEP("%s:opt=0x%x,return rc=%d\n",UTT,Popt,rc);             //~vbAhR~
    return rc;                                                     //~vbAhI~
}//isZWJZWNJ                                                       //~vbAhI~
//===============================================================================//~vbAkI~
int getFormatAltchar(int Popt,char *Ppu8,int Pu8len)               //~vbAkI~
{                                                                  //~vbAkI~
	int chklen,len,rc=0;                                           //~vbAkI~
    UWUCS ucs;                                                     //~vbAkI~
    UTRACED("Ppu8",Ppu8,Pu8len);                                   //~vbAkI~
    len=UTF8CHARLEN(*Ppu8);                                        //~vbAkI~
    len=min(len,Pu8len);                                           //~vbAkI~
	if (len>1 && !uccvutf2ucs(0,Ppu8,len,&ucs,&chklen))                   //~v62NI~//~vbAkI~
    	if (utf4_isFormat(0,ucs))                                     //~v7bWI~//~vbAkI~
	    	rc=UVIOM_ALTCH_FORMAT;                                     //~v7bWR~//~vbAkI~
    UTRACEP("%s:return rc=0x%02x,ucs=0x%04x\n",UTT,rc,ucs);        //~vbAkR~
    return rc;                                                     //~vbAkI~
}                                                                  //~vbAkI~
//===============================================================================//~vbAjI~
//=get eol col for cpu8 file                                       //~vbAjI~
//===============================================================================//~vbAjI~
#ifndef AAA                                                         //~4620I~//~vbAjI~
int getLineTrailerLen(int Popt,int Prow,int Pcol,int Plen)         //~vbAjI~//~4620I~//~vbAjI~
{                                                                  //~vbAjI~//~4620I~//~vbAjI~
    UTRACEP("%s:row=%d,col=%d,len=%d\n",UTT,Prow,Pcol,Plen);       //~vbAjI~//~4620I~//~vbAjI~
    char *pdata0=(char*)TEXTDATA(Prow,Pcol);                        //~vbAjI~//~4620I~//~vbAjI~
    char *pdbcs0=(char*)TEXTDBCS(Prow,Pcol);                        //~vbAjI~//~4620I~//~vbAjI~
	USHORT *pattr0=TEXTATTR(Prow,Pcol);                             //~vbAjI~//~4620I~//~vbAjI~
#else     //for UnitTest                                                         //~4620I~//~vbAjI~
int getLineTrailerLen(int Popt,char *Ppdata,char *Ppdbcs,USHORT *Ppattr,int Plen)//~4620I~//~vbAjI~
{                                                                  //~4620I~//~vbAjI~
    char *pdata0=Ppdata;                                           //~4620I~//~vbAjI~
    char *pdbcs0=Ppdbcs;                                           //~4620I~//~vbAjI~
	USHORT *pattr0=Ppattr;                                         //~4620I~//~vbAjI~
#endif                                                             //~4620I~//~vbAjI~
#ifdef AAA                                                         //~vbAjI~
    int posEOL=0;                                                  //~4620I~//~vbAjM~
#endif                                                             //~vbAjI~
	UTRACED("data",pdata0,Plen);                                   //~vbAjI~
	UTRACED("dbcs",pdbcs0,Plen);                                   //~vbAjI~
	UTRACED("attr",pattr0,Plen*sizeof(USHORT));                    //~vbAjI~
    char *pc=pdata0+Plen-1; char *pcd=pdbcs0+Plen-1; USHORT *pattr=pattr0+Plen-1;//~4620I~//~vbAjI~
    USHORT attrY=UVIOM_PADATTR; 	//  (Guviomoptstr[2]&0x0f)    //padding attr fg//~vbAjR~
    int ctrTrailer=0;                                              //~4620I~//~vbAjI~
    for (int ii=0;ii<Plen;ii++,pc--,pcd--,pattr--)                 //~4620I~//~vbAjI~
    {                                                              //~4620I~//~vbAjI~
    	USHORT attr=*pattr;                                        //~vbAjI~
        UTRACEP("%s:ii=%d,*pc=%02x,pcd=%02x,ctr=%d,attr=%02x\n",UTT,ii,*pc,*pcd,ctrTrailer,attr);//~vbAjR~
    	if (UVIOM_ATTRBG(attr))                                    //~vbAjR~
            break;                                                 //~vbAjI~
    	if (*pc==' ' && *pcd==0)                                   //~vbAjI~
        {                                                          //~4620I~//~vbAjI~
        	ctrTrailer++;                                          //~4620I~//~vbAjI~
        	continue;                                              //~4620I~//~vbAjI~
        }                                                          //~4620I~//~vbAjI~
        if ((*pcd==0||*pcd==DEFAULT_UNPATTR/*l*/) &&  *pattr==attrY)	// may be eol              //~4620I~//~vbAjR~
        {                                                          //~4620I~//~vbAjI~
#ifdef AAA                                                         //~vbAjI~
        	if (!posEOL)                                           //~4620I~//~vbAjI~
            {                                                      //~vbAjI~
        		posEOL=ii;                                         //~4620I~//~vbAjI~
	        	ctrTrailer++;                                      //~vbAjI~
            }                                                      //~vbAjI~
            else                                                   //~4620I~//~vbAjI~
            	break;                                             //~4620I~//~vbAjI~
#else        //space to eol is included in usetmonospace layout length//~vbAjI~
	        ctrTrailer++;                                          //~vbAjI~
            break;                                                 //~vbAjI~
#endif                                                             //~vbAjI~
        }                                                          //~4620I~//~vbAjI~
        else                                                       //~4620I~//~vbAjI~
            break;                                             //~4620I~//~vbAjI~
    }                                                              //~4620I~//~vbAjI~
    UTRACEP("%s:rc=%d,attrY=0x%02x\n",UTT,ctrTrailer,attrY);                          //~4620I~//~vbAjR~
    return ctrTrailer;                                             //~4620I~//~vbAjI~
}//getLineTrailerLen                                               //~vbAjI~//~4620I~//~vbAjI~
//===============================================================================//~vbAjI~
//=get eol col for cpu8 file                                       //~vbAjI~
//===============================================================================//~vbAjI~
void getPosEOL(int Popt,int Prow,int Plen)                         //~vbAjR~
{                                                                  //~vbAjI~
    UTRACEP("%s:opt=0x%x,row=%d,len=%d\n",UTT,Popt,Prow,Plen);     //~vbAjI~
    int posVsplit=wxe_getPosVsplit(0,Prow);                        //~vbAjI~
    SposVsplit=posVsplit;                                          //~vbAjI~
    int swVsplit1=posVsplit>0;	//if minus 2nd is active           //~vbAjI~
    if (!swVsplit1)                                                //~vbAjI~
    	posVsplit=-posVsplit;	//absolute value                   //~vbAjI~
  	int lineopt=wxe_getlineopt(0,Prow,0);                          //~vbAjI~
	int swcombinemode=COMBINEMODE(lineopt);                        //~vbAjI~
	int swligaturemode=WXE_LIGATUREMODE(lineopt);                  //~vbAjR~
    int start=0;                                                   //~vbAjR~
    int len=posVsplit ? posVsplit : Plen;                          //~vbAjR~
    if (!swVsplit1)    //2nd is active                             //~vbAjR~
      	len--;    //exclude splitter                               //~vbAjR~
    for (int ii=0;ii<2;ii++)                                       //~vbAjI~
    {                                                              //~vbAjI~
    	UTRACEP("%s:row=%d,lineopt=0x%x,swcombinemode=%d,swligaturemode=%d\n",UTT,Prow,lineopt,swcombinemode,swligaturemode);//~vbAjR~
        if (swcombinemode && swligaturemode)                       //~vbAjI~
        {                                                          //~vbAjI~
	        int lenTrailer=getLineTrailerLen(0,Prow,start,len);    //~vbAjR~
	        SposEOL[ii]=start+len-lenTrailer;                      //~vbAjI~
    		UTRACEP("%s:row=%d,ii=%d,triler=%d,pos=%d,vsplit=%d\n",UTT,Prow,ii,lenTrailer,SposEOL[ii],posVsplit);//~vbAjI~
        }                                                          //~vbAjI~
        if (!posVsplit)                                            //~vbAjI~
        	break;                                                 //~vbAjI~
	  	lineopt=wxe_getlineopt(0,Prow,posVsplit);                  //~vbAjI~
		swcombinemode=COMBINEMODE(lineopt);                        //~vbAjI~
		swligaturemode=WXE_LIGATUREMODE(lineopt);                  //~vbAjR~
	    start=posVsplit;                                           //~vbAjI~
    	len=Plen-posVsplit;                                        //~vbAjI~
        if (swVsplit1)	//left is active                           //~vbAjR~
        {                                                          //~vbAjR~
        	start++;                                               //~vbAjR~
    		len--;                                                 //~vbAjR~
        }                                                          //~vbAjR~
    }                                                              //~vbAjI~
    UTRACEP("%s:return row=%d,SposEol={%d,%d}\n",UTT,Prow,SposEOL[0],SposEOL[1]);//~vbAjI~
}//getPosEOL                                                       //~vbAjR~
#ifndef RRR                                                        //~vbAjI~
//===============================================================================//~vbAjI~
int chkLigatureExpand(int Popt,int Pcol,int Plen)                  //~vbAjR~
{                                                                  //~vbAjI~
	int swLastString;                                              //~vbAjI~
    if (SposVsplit)	//vsplit                                       //~vbAjI~
    {                                                              //~vbAjI~
    	if (Pcol<SposVsplit)                                       //~vbAjI~
	    	swLastString=(Pcol+Plen==SposEOL[0]);                  //~vbAjI~
        else                                                       //~vbAjI~
	    	swLastString=(Pcol+Plen==SposEOL[1]);                  //~vbAjI~
    }                                                              //~vbAjI~
    else                                                           //~vbAjI~
    	swLastString=(Pcol+Plen==SposEOL[0]);                      //~vbAjI~
    UTRACEP("%s:rc=%d,opt=0x%x,col=%d,len=%d,Svsplitpos=%d,SposEOL=%d,%d\n",UTT,swLastString,Popt,Pcol,Plen,SposVsplit,SposEOL[0],SposEOL[1]);//~vbAjR~
//  swLastString=0;	//TODO test                                    //~vbAjR~
    return swLastString;                                           //~vbAjI~
}//chkLigatureExpand                                               //~vbAjI~
#endif //RRR                                                       //~vbAjI~
//===============================================================================//~v7fzI~
int srchEOL(int Popt,char *Ppdddata,char *Ppdddbcs,int Pddlen)     //~v7fzI~
{                                                                  //~v7fzI~
	char *pcd,*pcde;                                               //~v7fzR~
    int ddlen;                                                     //~v7fzI~
    //********************************                             //~v7fzI~
    UTRACED("Ppdddata input",Ppdddata,Pddlen);                     //~v7fzI~
    UTRACED("Ppdddbcs input",Ppdddbcs,Pddlen);                     //~v7fzI~
    ddlen=Pddlen;                                                  //~v7fzI~
    for (pcd=Ppdddbcs,pcde=pcd+Pddlen;pcd<pcde;)                   //~v7fzI~
    {                                                              //~v7fzI~
    	int reslen=PTRDIFF(pcde,pcd);                              //~v7fzI~
        char *pcd2=memchr(pcd,DEFAULT_UNPATTR,(UINT)reslen);       //~v7fzI~
        if (!pcd2)                                                 //~v7fzI~
            break;                                                 //~v7fzI~
        int pos=PTRDIFF(pcd2,Ppdddbcs);                            //~v7fzI~
        if (*(Ppdddata+pos)==UVIOM_ESC_CHAR)                       //~v7fzR~
        {                                                          //~v7fzI~
        	ddlen=pos;                                             //~v7fzI~
            break;                                                 //~v7fzI~
        }                                                          //~v7fzI~
        pcd=pcd2+1;                                                //~v7fzI~
    }                                                              //~v7fzI~
    UTRACEP("%s:ddlen=%d\n",UTT,ddlen);                            //~v7fzI~
    return ddlen;                                                  //~v7fzI~
}                                                                  //~v7fzI~
//===============================================================================//~vbAkI~
int setAltchDD(int Popt,char *Ppdddata,char *Ppdddbcs,int Pddlen)  //~vbAkI~//~v7fzR~
{                                                                  //~vbAkI~
	int altddlen,altchdbcsspace=0,repctr=0;                        //~vbAkR~
    int ddlen;                                                     //~v7fzI~
    char *pc,*pce;                                                 //~vbAkR~
    char wkdddata[8],wkdddbcs[8];                                  //~vbAkI~
    //********************************                             //~vbAkI~
    UTRACED("Ppdddata input",Ppdddata,Pddlen);                     //~vbAkI~
    UTRACED("Ppdddbcs input",Ppdddbcs,Pddlen);                     //~vbAkI~
    ddlen=Pddlen;                                                  //~v7fzI~
//  for (pc=Ppdddata,pce=pc+Pddlen;pc<pce;)                        //~vbAkR~//~v7fzR~
    for (pc=Ppdddata,pce=pc+ddlen;pc<pce;)                         //~v7fzI~
    {                                                              //~vbAkI~
    	int reslen=PTRDIFF(pce,pc);                                //~vbAkI~
        char *pc2=memchr(pc,DEFAULT_ALTCH,(UINT)reslen);           //~vbAkR~
        if (!pc2)                                                  //~vbAkI~
            break;                                                 //~vbAkI~
        int pos=PTRDIFF(pc2,Ppdddata);                             //~vbAkR~
        char *pcd2=Ppdddbcs+pos;                                   //~vbAkI~
        if (pc2+1<pce && *(pc2+1)==DEFAULT_ALTCH    //dbcsspace    //~vbAkR~
        &&  *pcd2==UDBCSCHK_DBCS1STUCS  && *(pcd2+1)==UDBCSCHK_DBCS2NDUCS)//~vbAkR~
        {                                                          //~vbAkI~
        	UTRACEP("%s:dbcsspace altch=0x%04x,pos=%d\n",UTT,altchdbcsspace,pos);//~vbAkI~
            if (!altchdbcsspace)                                   //~vbAkI~
            {                                                      //~vbAkI~
		    	altchdbcsspace=UTF_GETALTCH_DBCS();                //~vbAkI~
				utfcvu2dd1(0,altchdbcsspace,wkdddata,wkdddbcs,&altddlen); //~v6WuR~//~vbAkI~
				wkdddata[1]=wkdddata[0];                           //~vbAkI~
				wkdddbcs[1]=wkdddbcs[0];                           //~vbAkI~
            }                                                      //~vbAkI~
            if (altchdbcsspace>0)                                  //~vbAkI~
            {                                                      //~vbAkI~
            	memcpy(pc2,wkdddata,2);                            //~vbAkR~
            	memcpy(pcd2,wkdddbcs,2);                           //~vbAkR~
                repctr++;                                          //~vbAkI~
            }                                                      //~vbAkI~
            pc=pc2+2;                                              //~vbAkR~
        }                                                          //~vbAkI~
        else                                                       //~vbAkI~
        {                                                          //~vbAkI~
            int altch=UTF_GETALTCH_SBCS(*pcd2);                    //~vbAkR~
        	UTRACEP("%s:sbcs alt=0x%04x pos=%d\n",UTT,altch,pos);  //~vbAkI~
            if (altch>0)                                           //~vbAkI~
            {                                                      //~vbAkI~
	        	utfcvu2dd1(0,altch,wkdddata+2,wkdddbcs+2,&altddlen);//~vbAkR~
            	*pc2=wkdddata[2];                                  //~vbAkR~
            	*pcd2=wkdddbcs[2];                                 //~vbAkR~
                repctr++;                                          //~vbAkI~
            }                                                      //~vbAkI~
            pc=pc2+1;                                              //~vbAkI~
        }                                                          //~vbAkI~
    }                                                              //~vbAkI~
    UTRACED("Ppdddata return",Ppdddata,ddlen);                    //~vbAkI~//~v7fzR~
    UTRACED("Ppdddbcs return",Ppdddbcs,ddlen);                    //~vbAkI~//~v7fzR~
    UTRACEP("%s:repctr=%d,rc=ddlen=%d\n",UTT,repctr,ddlen);                          //~vbAkI~//~v7fzR~
//  return repctr;                                                 //~vbAkI~//~v7fzR~
    return ddlen;                                                  //~v7fzI~
}//setAltchDD                                                      //~vbAkI~//~v7fzR~
//===============================================================================//~vbAkI~
//=output hardcopy ddfmt                                           //~vbAkI~
//===============================================================================//~vbAkI~
//int  drawtextstrHC(int Popt,char *Ppdata,char *Ppdbcs,int Plen,int Prow,int Pcol,char *Ppdddata,char *Ppdddbcs)//~vbAkR~//~v7fzR~
int  drawtextstrHC(int Popt,char *Ppdata,char *Ppdbcs,int Plen,int Prow,int Pcol,char *Ppdddata,char *Ppdddbcs,int *Ppddlen)//~v7fzR~
{                                                                  //~vbAkI~
    int writelen;                                                  //~vbAkI~
    char *pdatascr,*pdbcsscr,*ptextscr;                            //~vbAkR~
    USHORT *poffst;                                                //~vbAkI~
//  int offsu8,offslc,padlen,ii,pos;                               //~vbAkR~
    int writelenlc,ddlen;                                          //~vbAkI~
    int lclen;                                                     //+v7fzI~
	int swutf8data,opt,rc=0,slno=0;                                //~vbAkR~
    char wkdddata[MAXCOL],wkdddbcs[MAXCOL];                        //~vbAkR~
    char wkpadding[4];                                             //~vbAkI~
    int posEOL=-1;                                                 //~v7fzI~
//********************                                             //~vbAkI~
	UTRACEP("%s:opt=0x%04x,row=%d,col=%d,len=%d,cmaxcol=%d\n",UTT,Popt,Prow,Pcol,Plen,Mscrcmaxcol);//~vbAkI~//~v7fzR~
	UTRACED("drawtextstr inp dddata",Ppdata,Plen);                 //~vbAkR~
	UTRACED("drawtextstr inp dddbcs",Ppdbcs,Plen);                 //~vbAkI~
    int swVLeft=(Pcol==0 && Plen<Mscrcmaxcol);                     //~v7fzM~
    if (!(swVLeft)                                                 //~v7fzM~
    &&  (Guvio2Stat & UVIO2S_HCOPY_CHKEOL) //              0x4000  //hcopy cut line by EOL(0x1b)//~v7fyI~//~v7fzM~
    )                                                              //~v7fzM~
    {                                                              //~v7fzM~
    	posEOL=srchEOL(0,Ppdata,Ppdbcs,Plen);                      //~v7fzR~
    }                                                              //~v7fzM~
	UTRACEP("%s:swVLeft=%d,posEOL=%d\n",UTT,swVLeft,posEOL);       //~v7fzI~
    swutf8data=csubchkdd(0,Ppdbcs,Plen)!=0;                        //~vbAkI~
    memset(wkpadding,Guviomdbcspad,sizeof(wkpadding));             //~vbAkI~
	opt=CSL2UO_REP0a0d/*rep 0a 0d by ?*/;                          //~vbAkI~
  	if (swutf8data)                                                //~vbAkI~
  	{                                                              //~vbAkI~
      if (posEOL>=0)                                               //~v7fzI~
    	ddlen=posEOL;                                              //~v7fzI~
      else                                                         //~v7fzI~
    	ddlen=Plen;    //dd str len                                //~vbAkR~
	    memcpy(Ppdddata,Ppdata,(UINT)ddlen);                       //~vbAkI~
    	memcpy(Ppdddbcs,Ppdbcs,(UINT)ddlen);                       //~vbAkI~
//      int optsad=swVLeft ? SADO_VLEFT : 0;                       //~v7fzR~
  		setAltchDD(0,Ppdddata,Ppdddbcs,ddlen);	//chng tab ,dbcs space//~vbAkI~//~v7fzR~
  	}                                                              //~vbAkI~
  	else                                                           //~vbAkI~
  	{                                                              //~vbAkI~
      if (posEOL>=0)                                               //+v7fzI~
    	lclen=posEOL;                                              //+v7fzI~
      else                                                         //+v7fzI~
    	lclen=Plen;    //dd str len                                //+v7fzI~
//  	int utfrc=csublocale2utf8scr(opt,Ppdata,Ppdbcs,Plen,0,&ptextscr,&pdatascr,&pdbcsscr,&poffst,&writelen,&writelenlc,&slno);//~vbAkR~//+v7fzR~
    	int utfrc=csublocale2utf8scr(opt,Ppdata,Ppdbcs,lclen,0,&ptextscr,&pdatascr,&pdbcsscr,&poffst,&writelen,&writelenlc,&slno);//+v7fzI~
		UTRACEP("%s:call locale2utf8scr rc=%d,slno=%d\n",UTT,utfrc,slno);//~vbAkI~
    	if (utfrc>1)                                               //~vbAkI~
    		return -1;                                             //~vbAkR~
		UTRACED("offst",poffst,writelenlc*sizeof(*poffst)*2);      //~vbAkI~
		utfcvf2dd(0,ptextscr,writelen,wkdddata,wkdddbcs,(int)sizeof(wkdddata),&ddlen);//~vbAkR~
	    memcpy(Ppdddata,wkdddata,(UINT)ddlen);                     //~vbAkI~
    	memcpy(Ppdddbcs,wkdddbcs,(UINT)ddlen);                     //~vbAkI~
  	}//not dd fmt                                                  //~vbAkI~
	UTRACED("out dddata",Ppdddata,ddlen);                          //~vbAkR~
	UTRACED("out dddbcs",Ppdddbcs,ddlen);                          //~vbAkR~
    *Ppddlen=ddlen;                                                //~v7fzI~
    return rc;                                                     //~vbAkR~
}//drawtextstrHC                                                   //~vbAkI~
#ifndef KKK                                                        //~v7f4I~
//***************************************                          //~v7f4I~
#ifdef AAA                                                         //~v7f4I~
int getFormatAltcharZWJZWNJ(int Popt,char *Ppu8,int Pu8len)        //~v7f4I~
{                                                                  //~v7f4I~
    int altch=isZWJZWNJ(ISZO_ALTCH,Ppu8,Pu8len);  //len=3 and ZWJ  //~v7f4I~
    if (!altch)                                                    //~v7f4I~
	    altch=getFormatAltchar(0,Ppu8,Pu8len);                     //~v7f4I~
    UTRACEP("%s:altch=%04x\n",UTT,altch);                          //~v7f4I~
    return altch;                                                  //~v7f4I~
}                                                                  //~v7f4I~
#else                                                              //~v7f4I~
int getUcsAltchar(int Popt,int Pucs)                               //~v7f4R~
{                                                                  //~v7f4I~
	int altch;                                                     //~v7f4I~
//  if (UTF_ISZWJZWNJ(Pucs))                                       //~v7f4I~//~v7EfR~
    if (UTF_ISZWJ(Pucs))                                           //~v7EfI~
	    altch=UVIOM_ALTCH_ZWJ;   //'-'                            //~v7f4I~//~v7EfR~
    else                                                           //~v7f4I~
    if (UTF_ISZWNJ(Pucs))                                          //~v7EfI~
	    altch=UVIOM_ALTCH_ZWNJ;   //'-'                            //~v7EfI~
    else                                                           //~v7EfI~
    if (utf4_isFormat(0,Pucs))                                     //~v7f4I~
	    altch=UVIOM_ALTCH_FORMAT;                                  //~v7f4I~
    else                                                           //~v7f4I~
    	altch=Gutfcombaltch;                                       //~v7f4I~
    UTRACEP("%s:altch=%04x,ucs=%04x\n",UTT,altch,Pucs);            //~v7f4I~
    return altch;                                                  //~v7f4I~
}                                                                  //~v7f4I~
#endif                                                             //~v7f4I~
#endif //ifndef KKK                                                //~v7f4I~
