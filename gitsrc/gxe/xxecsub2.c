//*CID://+v7f4R~:                             update#= 1475;       //~v7f4R~
//***************************************************************************//~2818I~
//* c subrtn for wxe                                               //~2818I~
//***************************************************************************//~2818I~
//v7f4:251007 (LNX)by v7f1, w0 NoComb(including format)  was not displayed by altchFormat('='). ifndef JJJ//~v7f4I~
//v7f1:250926 (LNX)avoid combining by Format char of wcwidth=0     //~v7f1I~
//vbC2:250108 (gxe)pango_layout_get_direction is from pang1.46, ub18/s390 is 1.42//~vbC2I~
//vbAv:240708 (gxe:Bug)page displayname may be null(name is not null)//~vbAvI~
//vbAu:240708 (gxe:Bug)crash when pushed print icon                //~vbAuI~
//vbAi:240619 (gxe:bug)setmonospace adjust have to consider dbcs width//~vbAiI~
//vbAh:240616 (gxe)display split combining(lig on and off). when added non space(for ex 'A') after combining half width shadow appears. use this effect.//~vbAhI~
//vbAf:240614 (gxe:bug)lig:on.comb:on; comb disappear              //~vbAfI~
//vbAe:240612 (gxe:bug)multiple combining occupy next col(it is valid for a+. it may be not 3 geom but 2(1 with combined and 2nd combining) glyph.//~vbAeI~
//            u1080+u1060+u1082:NG, u1080+u1082+u1060:OK. sequence may have meaning. so do nothing//~vbAeI~
//vbz8:240124 (BUG:gxe)0c4 when preview menu pushed. printer form may missing displayname//~vbz8I~
//vbz6:240121 (gxe)core dump by NPE                                //~vbz6I~
//vbu0:201217 Debian10 compiler warning                            //~vbu0I~
//vbs1:201022 ftime deprecated(ftime is obsoleted POSIX2008)       //~vbs1I~
//vbp4:190913 gnome2 obsoleted                                     //~vbp4I~
//vbmp:180720 (gxe)combining char of geom-width=0 may come as 2nd glyph(but still 1st gryph str)//~vbmpR~
//vbmf:180803 show altch for SCM when COMBINE_NP                   //~vbmfI~
//vbme:180731 (gxe)multiple SCM support                            //~vbmeI~
//vbmb:180723 (gxe:bug of vbma)unicomb:NP dose not show altch      //~vbmbI~
//vbm8:180716 (gxe:Bug)combine may reduce glyphctr(u306f+u399a)    //~vbm8I~
//vbm6:180716 (gxe:Bug)OVF width0 has single space to display when Lig:Off,UNICOMB:COMBINE//~vbm6I~
//vbm4:180715 (gxe:Bug)Lig:Off and UNICOMB=COMB; combining char disappear whe base is dbcs//~vbm4I~
//vbm1:180714 (gxe:Bug)OVF width0 has no space to display when Lig:On,UNICOMB:COMBINE//~vbm1I~
//vbm0:180714 (gxe:Bug)Lig:On,unicomb:Split;splyt char displayed on next char//~vbm0I~
//vbkw:180704 (gxe)try to keep col width for the case of u-0327 has 2 glyph(width=xx and width=0)//~vbkwI~
//vbku:180703 after pango_set_text combine char width may be 0,csub_setcombineLayout missed to set CSUB_GEOMID_COMBINE//~vbkuI~
//vbks:180701 SCM; try u200c(ZWNJ:zero width no join) between combined and combining when Ligature:Off split mode//~vbksI~
//vbkp:180627 (gxe)do ligature for also width0 under COMBINE_NP mode//~vbkpI~
//vbk6:180612 (XXE)Spacing Combining Marks unicode(if not combined,it becomes glyphctr=2)//~vbk6I~
//vbk4:180611 (XXE)when Ligature:OFF unicomb:COM,combining char was separated because geometry->width!=0 for combining char//~vbk4I~
//vbk3:180610 (XXE) PangoGeometry:x_offset is "horizontal offset from nominal character position"//~vbk3I~
//            it may point leading space. So set 0 to x_offset(current value:(cellwidth-glyphwidth)/2 drow font right justified//~vbk3I~
//vbj2:180424 popup menu on cmd history list                       //~vbj2I~
//vbj0:180223 (GTK3)use enumprinter as alternative of cupsGetDest  //~vbj0I~
//vbi7:180221 (gxe)cupsGetDest is time consuming,change to cupsServer() for cups active chk;see vat0(enumprinter hung if cups not running)//~vbi7I~
//vb7x:170128 (gxe:BUG)paste to out of gxe get warning operation invalid
//vb7w:170128 (gxe:BUG)paste to out fail,try text/url, but vb7x fixed it//~vb7wI~
//vb7v:170128 (gxe:GTK3 BUG)DragDrop hung                                        //~vb7vI~
//vb7t:170128 (gxe)Gtk3 deprecated
//vb74:161220 Gtk3 warning                                         //~vb74I~
//vb73:161220 fc25(GTK3 and env WAYLAND_DISPLAY=wayland-0) gxe crash at XkbUseExtension()//~vb73I~
//vb5h:160918 (XXE BUG by vb4A)when Lig:on and no combine mode, ascii string(no ligature occured:diff=0) was not displayed//~vb5hI~
//vb5e:160918 gxe compiler warning                                 //~vb5eI~
//vb4A:160815 if UNICOMB UNPR mode and LIGATURE ON, write altch just after base char using GetTextExtentPoint32W//~vb4AI~
//vat0:140221 (gxe:gtk3:bug)gtk_enumerate_printers hungs when cups is not running//~vat0I~
//var8:140127 gtk3 suppott                                         //~var8I~
//var3:140118 set margin=0 when cups printer not found(diaplayed on page dialog)//~var3I~
//vap1:131220 (LNX)configure aupports NOPRINT for RedHat5.8        //~vap1I~
//vamu:131015 (GtkPrint)"B5JIS" is not defind on gtk_paper_size_get_papername()//~vamuI~
//vamt:131015 (GtkPrint)accept minus value of margin to adjust origin for each printer's paper folder shift attachment.(case of that b5 origin is relativ to a4 origin)//~vamtI~
//vams:131010 Ligature off when Bin,VHEX,HEX mode                  //~vamsI~
//vamq:131007 (GtkPrint)(BUG) x00 terminates string                //~vamqI~
//vamp:131007 del vamk by vamm                                     //~vampI~
//vamj:131006 vama is for landscape only                           //~vamjI~
//vamh:131005 roundup font width(digit width is almost narrow)     //~vamhI~
//vamg:131004 (BUG)when font=Monospace 11-ligature mode, show dbcs as halgf width(overriden by next char when string width>cellW*colomn)//~vamgI~
//vama:131002 select max of bottom-top margin for both right/left rotated landscape//~vamaI~
//            also for gnomeprint version                          //~vamaI~
//vam9:130929 (BUG)Pango font size is by points metrics is bt pixcel//~vam9I~
//vam7:130929 add print with ligature                              //~vam7I~
//vam6:130929 round up font height from metrics(ascent+descent)    //~vam6I~
//vam5:130928 (BUG)scale to fontsize is not to fonth or fontw but to size itself//~vam5I~
//vam0:130911 for distro removed gnome-print,use GTKprint          //~vam0I~
//vak6:130905 compiler warning;never executes                      //~vak6I~
//vagG:121219 (Lnx)chk result of cupsGetDests(report from .at; folowing free() was crashed on RHEL5.73)//~vagGI~
//vaff:120613 (FC12)avoid uninitialized variable warning by gcc 4.4.4 on FC12(compile optio -Ox is required also)//~vaffI~
//vaa7:111117 (gcc4.6)Warning:unused-but-set                       //~vaa7I~
//vaa6:111109 (s390xfc14)compile err;unknown typename ppd_file_t(cups.h dose not include ppd.h)//~vaa6I~
//va72:100801 LP64 wchar_t is 4byte on LP64                        //~va72I~
//va6X:000728*(BUG)S390:abend;suse64 abend at print dialog open(missing apply of v5nD)//~va6XI~
//va6y:000706 CUPs default printer is not same as gnome default    //~va6yI~
//va4a:100411 (XXE:BUG)gnome_get_glyph_width returns width=0 for DBCS//~va4aI~
//va3u:100221 (BUG)not unconditionaly set green for combining char when ligature+split mode//~va3uI~
//            If so so,sub string split at it,then ligature in effective.//~va3uI~
//            (Split altchar is Linux console only)                //~va3uI~
//va3i:100208 (XXE)leave ligature to pango when ligature on        //~va3iI~
//va30:100126 combine mode of diacritical marks by A+/(saved to ini)//~va30I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//va1M:091121 (LNX)ligature support;keep monospace for english lagature; Arabian ? I don't know.//~va1MI~
//va1D:091115 gxeprint:2column print for 4byte dbcs if wysiwig is off//~va1DI~
//va1c:091030_merge GB18030 support                                //~va1cI~
//v7ax:090414 (LNX)compile waring int:gsize                        //~v7axR~
//v79z:080916 DBCS tbl for C and K of CJK                          //~v79zI~
//v77u:080111*(XXE:BUG)gnome font search(gnome_font_find_from_full_name) fails for complex font name//~v77sI~
//            alternnative way is gnome_font_face_find_from_family_and_style+gnome_font_face_get_font_full//~v77sI~
//v77s:080110*(XXE:BUG) no need to suppy "regular" because gxedlg do it by v77t//~v77sI~
//v76R:071015 change default print color 000000->141414            //~v76RR~
//v76c:070617 (XXE)paste from PRIMARY clipboard by middle button down//~v76cI~
//v75Y:070527 (XXE:BUG)popup menu disappear by lbutton up for FC5  //~v75YI~
//v75X:070526 (XXE:BUG)assertion fail face!=NULL, gnome_font_find  //~v75XI~
//v69V:060718 (XXE)Performance tuning for pango.                   //~v69VI~
//                 gdk_draw_layout_with_color for each char one by one is too slow//~v69VI~
//                 On the other hand string draw requres monospace and usetmonospace exaust cpu on gprof.//~v69VI~
//                 Bug of monospace determination was exist.(missed to set font to layout)//~v69VI~
//                 Monospace determination obey to font rfamily attribute.//~v69VI~
//                 DBCS is not just double iof sbcs width even for monospace font.//~v69VI~
//                 So use string write for sbcs only if mono space,else use uset monospace.//~v69VI~
//v69S:060716 (WXEXXE:BUG)corrupted dbcs disply by mouse drag when dbcs split//~v69SI~
//            It cause abend for xxe.                              //~v69SI~
//v69s:060531 (XXE:fc5)g_locale_to_utf8 return error if null char contained//~v69sI~
//v69r:060531 (XXE)print debug message by GError                   //~v69rI~
//v69n:060530 (XXE:fc5)avoid Gtk warning "GError not initialized". //~v69nI~
//v686:060323 dnd support by paste(edit:pastev,ins=paste-ins,rep=paste-rep)//~v686I~
//v66q:051023 (XXE) v66i of WXE;C & P;if no Clipboard data on Windows CB,get data from ::CB//~v66qI~
//vX03:050729 for the case sbcs is monospace but dbcs is not       //~vX03I~
//vXXE:050611 new for XXE                                          //~vXXEI~
//***************************************************************************//~vXXEI~
//vXXE:050611 new for XXE                                          //~vXXEI~
//***************************************************************************//~vXXEI~
#include <time.h>                                                  //~2907I~
#include <stdio.h>                                                 //~2907I~
#include <stdlib.h>                                                //~2907I~
#include <string.h>                                                //~2907I~
#ifdef LNX                                                         //~vb7vI~
    #include <sys/timeb.h>                                         //~v321R~//~vb7vI~
#endif                                                             //~vb7vI~
//*************************************************************    //~2907I~
#ifndef OPTGTK3                                                    //~var8R~
#include <gnome.h>                                                 //~5624I~
#else                                                              //~var8R~
#include <gtk/gtk.h>                                               //~var8R~
#endif                                                             //~var8R~
#ifndef NOPRINT                                                    //~vam0R~
	#ifdef GTKPRINT                                                //~vam0I~
        #ifndef OPTGTK3                                            //~var8R~
		#include <gtk/gtkprinter.h>                                //~vam0R~
        #else                                                      //~var8R~
          #include <gtk/gtkunixprint.h>                            //~var8R~
        #endif                                                     //~var8R~
	#else    //!GTKPRINT                                           //~vam0I~
#include <libgnomeprint/gnome-print.h>                             //~vXXEI~
#include <libgnomeprint/gnome-print-job.h>                         //~vXXEI~
#include <libgnomeprint/gnome-print-pango.h>                       //~vam7I~
	#endif   //!GTKPRINT                                           //~vam0I~
#endif                                                             //~vam0I~
#include <cups/cups.h>                                             //~va6yI~
#include <cups/ppd.h>                                              //~vaa6I~
#ifdef GCONFKBD                                                    //~v76cI~
	#include <gconf/gconf.h>                                       //~v76cR~
	#include <gconf/gconf-client.h>                                //~v76cR~
#else                                                              //~v76cI~
	#include <X11/XKBlib.h>                                        //~v76cI~
	#include <gdk/gdkx.h>                                          //~v76cI~
#endif                                                             //~v76cI~
#ifdef UTF8UCS2                                                    //~va30I~
	#define __USE_XOPEN		//wcwidth requires                     //~va30I~
	#include <wchar.h>                                             //~va30I~
#endif                                                             //~va30I~
#include "ulib.h"                                                  //~2907I~
#include "ualloc.h"                                                //~2907R~
#include "uque.h"                                                  //~2929I~
#include "uerr.h"                                                  //~2907I~
#include "ustring.h"                                               //~va6yI~
#include "utrace.h"                                                //~2914I~
#include "ufile.h"                                                 //~2922I~
#include "uedit.h"                                                 //~5625I~
#include "udbcschk.h"                                              //~vXXEI~
#include "uedit2.h"                                                //~vbAfI~
#include "utf.h"                                                   //~va1DI~
#ifdef UTF8UCS2                                                    //~va20I~
#include "utf22.h"                                                 //~va20I~
#endif                                                             //~va20I~
#define UFTIME                                                     //~vbs1I~
#include <umiscf.h>                                                //~vbs1I~
                                                                   //~2818I~
#include "xe.h"                                                    //~2929I~
#ifdef UTF8UCS2                                                    //~va20M~
#include "xescr.h"                                                 //~va20I~
#include "xefile.h"                                                //~va20I~
#include "xeutf2.h"                                                //~va20I~
#endif                                                             //~va20M~
#include "xesub2.h"                                                //~v7axI~
                                                                   //~2929I~
#include "gxe.h"                                                   //~5624I~
#include "xxedef.h"                                                //~5624I~
#include "xxemain.h"                                               //~5624I~
#include "xxecsub.h"                                               //~5624I~
#include "gxemfrm.h"                                               //~vXXEI~
#include "xxexei.h"                                                //~va1MR~
                                                                   //~5624I~
//***************************************************************************//~2818I~
#define	CUPS_CHECK_VERSION(major,minor,micro)	\
    (CUPS_VERSION_MAJOR > (major) || \
     (CUPS_VERSION_MAJOR == (major) && CUPS_VERSION_MINOR > (minor)) || \
     (CUPS_VERSION_MAJOR == (major) && CUPS_VERSION_MINOR == (minor) && \
      CUPS_VERSION_PATCH >= (micro)))                              //~vbp4I~
#if CUPS_CHECK_VERSION(1,6,0)                                      //~vbp4I~
	#define NOPPD                                                  //~vbp4I~
#endif	                                                           //~vbp4I~
#ifdef NOPPD                                                       //~vbp4I~
    typedef struct _PageSize                                       //~vbp4I~
            {                                                      //~vbp4I~
                char *displayname;   //A4 etc                      //~vbp4I~
                ppd_size_t ppdsz;                                  //~vbp4I~
            } PageSize;                                            //~vbp4I~
    #define SZ_PAGESIZE sizeof(PageSize)                           //~vbp4I~
#endif                                                             //~vbp4I~
#ifndef OPTGTK3                                                    //~var8R~
#if (PANGO_VERSION_MAJOR>1||(PANGO_VERSION_MINOR>=6))              //~vam5M~
    #define PANGO1_6_0                                             //~vam5M~
#endif                                                             //~vam5M~
#else   //OPTGTK3    //text overflow when MWWscrprt:on             //~var8R~
#endif                                                             //~var8R~
#if defined(OPTGTK3) && !defined(YYY)                              //~vb7vI~
#define  GCB_MAXUD  8                                              //~vb7vI~
static char        *Scb_uris;	             //clibpoard filename  //~vb7vI~
static char         Scb_userdataRecv[GCB_MAXUD+1];        //       //~vb7vI~
static struct timeb Scb_timeReq;                                   //~vb7vI~
static struct timeb Scb_timeRecv;                                  //~vb7vI~
#endif	//!YYY                                                     //~vb7vI~
#define SUPPORT_GNOMECOPY                                          //~vb7wR~
//***************************************************************************//~2831I~
//#define DEFAULT_PRINTCOLOR  0x00000001 //RRGGBBAA                //~v76RR~
#define DEFAULT_PRINTCOLOR  0x404040ff //RRGGBBAA                  //~v76RR~
//***************************************************************************//~2907I~
#ifdef SUPPORT_GNOMECOPY                                           //~vb7wR~
#define COPYFILETARGETNO 1                                         //~vXXEI~
#define COPYFILETARGETID "x-special/gnome-copied-files"            //~vXXEI~
//#define COPYFILETARGETID "TARGETS"                               //~var8R~
static   GtkTargetEntry Scopyfiletarget[COPYFILETARGETNO]={        //~vXXEI~
        						{COPYFILETARGETID,0,0}             //~vXXER~
														  };       //~vXXEI~
#endif                                                             //~vb7vI~
#define DRAGFILETARGETNO 1                                         //~vXXEI~
#define DRAGFILETARGETID "text/uri-list"                           //~vXXEI~
static   GtkTargetEntry Sdragfiletarget[DRAGFILETARGETNO]={        //~vXXEI~
        						{DRAGFILETARGETID,0,0}             //~vXXEI~
														  };       //~vXXEI~
#ifdef XXX //GtkDragSourceInfo,gtk_drag_cancel is internal use only now//~vXXEI~
static 	GtkDragSourceInfo *Spdraginfo;                             //~vXXEI~
static  int Sdragtimeout;                                          //~vXXEI~
#endif                                                             //~vXXEI~
#ifndef NOPRINT                                                    //~vap1I~
static int Snoligature;	//for hhex hex part,vhex line              //~vamsI~
#endif                                                             //~vap1I~
#ifdef GTKPRINT                                                    //~vam0I~
static int Senumctr,Senumdefault;                                  //~vbi7I~
static GtkPrinter *SdefaultprinterGtk;                                    //~vam0I~//~vamtR~
static GtkPrinter *SsrchprinterGtk;                                       //~vam0I~//~vamtR~
GList *csubgetcupspaperlistGtkName(char *Pprintername);            //~vam0R~
#define GET_TOP_PRINTER     "1"                                    //~vam0I~
GList *csubgetcupspaperlistGtk(GtkPrinter *Ppprinter);             //~vam0I~
#endif   //!GTKPRINT                                               //~vam0I~
//***************************************************************************//~2831I~
//int ufontismonospace(PangoFontDescription *Pfontdesc);           //~va1MR~
int ufontismonospace(PangoFontDescription *Pfontdesc,int Pfontw);  //~va1MR~
PangoFontFamily *usrchfontfamily(PangoFontDescription *Pfontdesc); //~v69VR~
#ifdef UTF8UCS2                                                    //~va20I~
int uprttextoutwsub(int Popt,int Pposx,int Pposy,char *Pdata,char *Pdbcs,int Plen,int Plenlc);//~va20R~
#endif                                                             //~va20I~
int csub_repu8null(char *Putf8,int Pu8len,int Prepch);             //~vamqR~
int csub_utf8mem_strlen(char *Putf8,int Pu8len);                   //~vamqI~
#ifdef GTKPRINT                                                    //~vat0I~
int csubgetdestctr();                                              //~vat0I~
int csubiscupsavail();                                             //~vbi7I~
#endif   //!GTKPRINT                                               //~vat0I~
#if defined(OPTGTK3) && !defined(YYY)                              //~vb7vI~
	void uclipboard_cbRequestContents(GtkClipboard *Ppclipboard,GtkSelectionData *Pseldata,gpointer Ppudata);//~vb7vI~
#endif   //YYY                                                     //~vb7vI~
int csub_ChkCombineGlyph(int Popt,char *Ppu8,int Pu8len);          //~vbm8R~
//*************************************************************    //~5624M~
//*intf to free                                                    //~5624M~
//*************************************************************    //~5624M~
void usettitle(char *Ptitle)                                       //~5624M~
{                                                                  //~5624M~
	gtk_window_set_title(GTK_WINDOW(Gpframe),Ptitle);              //~5624M~
    return;                                                        //~5624M~
}//wxefree                                                         //~5624M~
//*************************************************************    //~5624M~
//*setup color palette input color is rgb by 00rrggbb fmt          //~5624M~
//*************************************************************    //~5624M~
void usetpalettecolor(int Pmaxpal,int *Pprgb)                      //~5624M~
{                                                                  //~5624M~
	int ii,rgb,*prgb,rr,gg,bb;                                     //~5624M~
    GdkColor *pcol;                                                //~5624M~
//*********************************                                //~5624M~
	pcol=Gxxepalette;                                              //~5624M~
	for (ii=0,prgb=Pprgb;ii<Pmaxpal;ii++,prgb++,pcol++)            //~5624M~
    {                                                              //~5624M~
    	rgb=*prgb;                                                 //~5624M~
    	rr=RGB_GETRED(rgb);                                        //~5624M~
    	gg=RGB_GETGREEN(rgb);                                      //~5624M~
    	bb=RGB_GETBLUE(rgb);                                       //~5624M~
//dprintf("palette setup ii=%d,r=%x,g=%x,b=%x\n",ii,rr,gg,bb);     //~v69VR~
        pcol->red  =0xffff*rr/0xff;      //in the range of 0-0xffff from 0-0xff//~5624M~
        pcol->green=0xffff*gg/0xff;                                //~5624M~
        pcol->blue =0xffff*bb/0xff;                                //~5624M~
	    gdk_colormap_alloc_color(Gpcolormap,pcol,FALSE,TRUE);//writeable?,bestmatch?//~5624M~
//dprintf("palette setup p=%x,r=%x,g=%x,b=%x\n",pcol->pixel,pcol->red,pcol->green,pcol->blue);//~v69VR~
    }                                                              //~5624M~
    UTRACED("Gxxepalette",Gxxepalette,Pmaxpal*(int)sizeof(GdkColor));//~vbC2R~
    return;                                                        //~5624M~
}//usetpalettecolor                                                //~5624M~
//*************************************************************    //~5624I~
//*set text to clipboard                                           //~5624I~
//*rc:                                                             //~5624I~
//*************************************************************    //~5624I~
#ifdef UTF8UCS2                                                    //~va20I~
int uclipboard_settext(int Popt,char *Ptext,int Plen)              //~va20I~
#else                                                              //~va20I~
int uclipboard_settext(char *Ptext,int Plen)                       //~5624R~
#endif                                                             //~va20I~
{                                                                  //~5624I~
//  GError *errpos=NULL;                                           //~v69VR~
	int readlen,writelen;                                          //~5624R~
    char *putf8;                                                   //~5624I~
//*********************************                                //~5624I~
//  putf8=g_locale_to_utf8(Ptext,Plen,&readlen,&writelen,&errpos); //~v69VR~
//  PRINTGERR("uclipboard_settext-g_locale_to_utf8",errpos);       //~v69VR~
//  if (readlen!=Plen)                                             //~v69VR~
//  if (csublocale2utf8(Ptext,Plen,&readlen,&putf8,&writelen)>1)   //~v79zR~
    UTRACED("source",Ptext,Plen);                                  //~v79zI~
#ifdef UTF8UCS2                                                    //~va20M~
  if ((Popt & UCSTO_SRCUTF8))                                      //~va20R~
  {                                                                //~va20I~
  	putf8=Ptext;                                                   //~va20I~
    writelen=Plen;                                                 //~va20I~
  }                                                                //~va20I~
  else                                                             //~va20I~
#endif                                                             //~va20M~
  {                                                                //~va20I~
    if (csublocale2utf8(0/*data source is locale encoding*/,Ptext,Plen,&readlen,&putf8,&writelen)>1)//~v79zR~
    {                                                              //~5624I~
//  	if (putf8)                                                 //~v69VR~
//      	g_free(putf8);                                         //~v69VR~
//    	return uerrmsgbox("Cut/Paste:sorce data contains invalid text",0);//~vak6R~
        uerrmsgbox("Cut/Paste:sorce data contains invalid text",0);//~vak6I~
    	return -1;                                                 //~5624I~
    }                                                              //~5624I~
  }                                                                //~va20I~
	gtk_clipboard_set_text(Gpclipboard,putf8,writelen);//void func //~5624R~
UTRACED("uclipboard_settext",putf8,writelen);                      //~va20I~
//  g_free(putf8);                                                 //~v69VR~
    return 0;                                                      //~5624R~
}//uclipboard_settext                                               //~5624R~//~va20R~
//*************************************************************    //~vXXEI~
//*set nuatilus target(not text) string to clipboard               //~vXXEI~
//*rc:                                                             //~vXXEI~
//*************************************************************    //~vXXEI~
void uclipboard_file_get_callback(GtkClipboard *Pcb,GtkSelectionData *Pseldata,guint Pinfo,gpointer Pdata)//~vXXEI~
{                                                                  //~vXXEI~
	char *strdata;                                                 //~vXXER~
    GdkAtom cpatom;                                                //~vXXEI~
//***********************************                              //~vXXEI~
    dprintf("%s:copy get_cb data=%s,info=%d\n",UTT,(char*)Pdata,Pinfo);   //~vX03R~//~vb7vR~
	strdata=(char *)Pdata;                                         //~vXXER~
        dprintf("%s:format=%d,data=%s,len=%d\n",UTT,               //~vb7vI~
            gtk_selection_data_get_format(Pseldata),               //~vb7vI~
            gtk_selection_data_get_data(Pseldata),                 //~vb7vI~
            gtk_selection_data_get_length(Pseldata));              //~vb7vI~
        cpatom=gtk_selection_data_get_selection(Pseldata);         //~vb7vI~
        dprintf("%s:selection atom name=%s\n",UTT,                 //~vb7vI~
                 cpatom?gdk_atom_name(cpatom):"no data");          //~vb7vI~
        cpatom=gtk_selection_data_get_target(Pseldata);            //~vb7vI~
        dprintf("%s:target atom name=%s\n",UTT,                    //~vb7vI~
                 cpatom?gdk_atom_name(cpatom):"no data");          //~vb7vI~
        cpatom=gtk_selection_data_get_data_type(Pseldata);         //~vb7vI~
        dprintf("%s:type atom name=%s\n",UTT,                      //~vb7vI~
                 cpatom?gdk_atom_name(cpatom):"no data");          //~vb7vI~
//#ifdef AAA  //@@@@test                                           //~vb7vR~
//#else                                                            //~vb7vR~
//    cpatom=gdk_atom_intern(COPYFILETARGETID,TRUE);     //test exist//~vb7vR~
//        dprintf("%s:intern TRUE atom name=%s\n",UTT,             //~vb7vR~
//                 cpatom?gdk_atom_name(cpatom):"no data");        //~vb7vR~
//#endif                                                           //~vb7vR~
#ifdef SUPPORT_GNOMECOPY                                           //~vb7wR~
    cpatom=gdk_atom_intern(COPYFILETARGETID,FALSE);                //~vXXEI~
        dprintf("%s:intern FALSE atom name=%s\n",UTT,              //~vb7wR~
                 cpatom?gdk_atom_name(cpatom):"no data");          //~vb7wR~
#else                                                              //~vb7wR~
    cpatom=gdk_atom_intern(DRAGFILETARGETID,FALSE);                //~vb7wR~
        dprintf("%s:intern FALSE atom name=%s\n",UTT,              //~vb7wR~
                 cpatom?gdk_atom_name(cpatom):"no data");          //~vb7wR~
#endif                                                             //~vb7wR~
#ifdef AAA                                                         //~vb7wR~
	gtk_selection_data_set(Pseldata,cpatom,8,strdata,strlen(strdata));//~vXXEI~
#else                                                              //~vb7wR~
//  cpatom=gdk_atom_intern(DRAGFILETARGETID,FALSE);                //~vb7wR~
    dprintf("%s:intern atom name=%s\n",UTT,                        //~vb7wR~
                 cpatom?gdk_atom_name(cpatom):"no data");          //~vb7wR~
    dprintf("%s:data_set strdata=%s\n",UTT,strdata);               //~vb7wR~
	gtk_selection_data_set(Pseldata,cpatom,8,strdata,strlen(strdata));//~vb7wR~
#endif                                                             //~vb7wR~
#if defined(OPTGTK3) && !defined(YYY)                              //~vb7vI~
	uclipboard_cbRequestContents(Pcb,Pseldata,Pdata);              //~vb7vR~
#endif                                                             //~vb7vI~
    return;                                                        //~vXXEI~
}//uclipboard_file_get_callback                                    //~vb7vR~
//*************************************************************    //~vXXEI~
void uclipboard_file_clear_callback(GtkClipboard *Pcb,gpointer Pdata)//~vXXEI~
{                                                                  //~vXXEI~
    dprintf("clipboard file clear_cb data=%s\n",(char*)Pdata);     //~vX03R~
#if defined(OPTGTK3) && !defined(YYY)                              //~vb7vI~
	uclipboard_getfileselection_Clear(0);	//FIXME not tested     //~vb7vI~
#endif                                                             //~vb7vI~
    return;                                                        //~vXXEI~
}                                                                  //~vXXEI~
//*************************************************************    //~vXXEI~
int uclipboard_setcopyfile(char *Pfilenames,int Plen)              //~vXXEI~
{                                                                  //~vXXEI~
	int rc;                                                        //~vXXEI~
//*********************************                                //~vXXEI~
    dprintf("uclipboard setcopyfile str=%s\n",Pfilenames);         //~vX03R~
#ifdef SUPPORT_GNOMECOPY                                           //~vb7wR~
    rc=gtk_clipboard_set_with_data(Gpclipboard,Scopyfiletarget,COPYFILETARGETNO,//~vXXEI~
    							uclipboard_file_get_callback,uclipboard_file_clear_callback,//~vXXEI~
    							Pfilenames);                       //~vXXER~
#else                                                              //~vb7wR~
    rc=gtk_clipboard_set_with_data(Gpclipboard,Sdragfiletarget,DRAGFILETARGETNO,      //text/uri-list////~vb7wR~
    							uclipboard_file_get_callback,uclipboard_file_clear_callback,//~vb7wR~
    							Pfilenames);                       //~vb7wR~
#endif                                                             //~vb7wR~
    if (!rc)                                                       //~vXXEI~
    	uerrmsgbox("Cut/Paste:failed to copy filenames to clipboard.",0);//~vXXEI~
    return rc; 	//TRUE|FALSE                                       //~vXXEI~
}//uclipboard_setcopyfile                                          //~vXXEI~
#if defined(OPTGTK3) && !defined(YYY)                              //~vb7vI~
//*************************************************************    //~vb7vR~
//*callback for request_contents                                   //~vb7vI~
//*************************************************************
void uclipboard_cbRequestContents(GtkClipboard *Ppclipboard,GtkSelectionData *Pseldata,gpointer Ppudata)//~vb7vR~
{                                                                  //~vb7vR~
	char *pnew,*pold,*pdata;                                       //~vb7vI~
    size_t sz;                                                     //~vb7vI~
//***************                                                  //~vb7vI~
//  dprintf("%s:GtkClipboard=%p,GtkSelection=%p,userdata=%s\n",UTT,Ppclipboard,Pseldata,Ppudata);//~vb7vR~//~vbu0R~
    dprintf("%s:GtkClipboard=%p,GtkSelection=%p,userdata=%s\n",UTT,Ppclipboard,Pseldata,(char*)Ppudata);//~vbu0I~
  	dprintf("%s:format=%d,data=%s,len=%d\n",UTT,                   //~vb7vR~
		gtk_selection_data_get_format(Pseldata),                   //~vb7vR~
		gtk_selection_data_get_data(Pseldata),                     //~vb7vI~
		gtk_selection_data_get_length(Pseldata));                  //~vb7vI~
    dprintf("%s:selection atom name=%s\n",UTT,                     //~vb7vI~
			 gdk_atom_name(gtk_selection_data_get_selection(Pseldata)));//~vb7vR~
    dprintf("%s:target atom name=%s\n",UTT,                        //~vb7vI~
			 gdk_atom_name(gtk_selection_data_get_target(Pseldata)));//~vb7vR~
    dprintf("%s:type atom name=%s\n",UTT,                          //~vb7vI~
			 gdk_atom_name(gtk_selection_data_get_data_type(Pseldata)));//~vb7vR~
	pdata=(char*)gtk_selection_data_get_data(Pseldata);            //~vb7vI~
	pold=Scb_uris;                                                 //~vb7vM~
    pnew=0;                                                        //~vb7vI~
    if (pdata)                                                     //~vb7vI~
    {                                                              //~vb7vI~
      if (!pold || strcmp(pdata,pold))	                           //~vb7vI~
      {                                                            //~vb7vI~
    	sz=strlen(pdata);                                          //~vb7vI~
    	pnew=malloc(sz+1);                                         //~vb7vI~
        strcpy(pnew,pdata);                                        //~vb7vI~
      }                                                            //~vb7vI~
    }                                                              //~vb7vI~
    if (pnew)                                                      //~vb7vI~
    {                                                              //~vb7vI~
		Scb_uris=pnew;                                             //~vb7vR~
    	if (pold)                                                  //~vb7vR~
    	{                                                          //~vb7vR~
	    	dprintf("%s:old data to free=%s\n",UTT,pold);          //~vb7vR~
    		free(pold);                                            //~vb7vR~
    	}                                                          //~vb7vR~
    	if (Ppudata)                                               //~vb7vR~
    	{                                                          //~vb7vR~
    		UstrncpyZ(Scb_userdataRecv,Ppudata,sizeof(Scb_userdataRecv));//~vb7vR~
    	}                                                          //~vb7vR~
    	else                                                       //~vb7vR~
    		*Scb_userdataRecv=0;                                   //~vb7vR~
//  	ftime(&Scb_timeRecv);                                      //~vb7vI~//~vbs1R~
    	uftime(&Scb_timeRecv);                                     //~vbs1I~
    }                                                              //~vb7vI~
}//uclipboard_cbRequestContents                                    //~vb7vR~
////*************************************************************  //~vb7vI~
////*callback for request_contents //@@@@text                      //~vb7vI~
////*************************************************************  //~vb7vI~
//void uclipboard_cbURIRequestContents(GtkClipboard *Ppclipboard,gchar **Ppuris,gpointer Ppudata)//~vb7vI~
//{                                                                //~vb7vI~
////***************                                                //~vb7vI~
//    dprintf("%s:uri=%p=%s,userdata=%s\n",UTT,Ppuris,(Ppuris?*Ppuris:"no uri data"),Ppudata);//~vb7vI~
//}//uclipboard_cbURIRequestContents                               //~vb7vI~
////*************************************************************  //~vb7vI~
////*callback for request_contents     //@@@@test                  //~vb7vI~
////*************************************************************  //~vb7vI~
//void uclipboard_cbTextRequestContents(GtkClipboard *Ppclipboard,gchar *Ptext,gpointer Ppudata)//~vb7vI~
//{                                                                //~vb7vI~
////***************                                                //~vb7vI~
//    dprintf("%s:text=%p=%s,userdata=%s\n",UTT,Ptext,Ptext,Ppudata);//~vb7vI~
//}//uclipboard_cbTextRequestContents                              //~vb7vI~
//*************************************************************
//*check already received filecopt uri                             //~vb7vI~
//*rc=1:data exist,0 no data                                       //~vb7vI~
//*************************************************************
int uclipboard_getfileselection_Received(int Popt,char **Ppuris,char *Puserdata)//~vb7vI~
{
    int rc;                                                        //~vb7vI~
//***************                                                  //~vb7vI~
    dprintf("%s:entry old uri=%s\n",UTT,Scb_uris);                 //~vb7vI~
	uclipboard_getfileselection();	//later callback receive data  //~vb7vI~
    rc=Scb_uris!=0;                                                //~vb7vI~
    if (Ppuris)                                                    //~vb7vI~
		*Ppuris=Scb_uris;                                          //~vb7vR~
    if (Puserdata)                                                 //~vb7vR~
	    UstrncpyZ(Puserdata,Scb_userdataRecv,sizeof(Scb_userdataRecv));//~vb7vR~
    dprintf("%s:rc=%d,old uri=%s\n",UTT,rc,Scb_uris);              //~vb7vI~
    return rc;                                                     //~vb7vI~
}//uclipboard_cbRequestContents_Received                           //~vb7vR~
//*************************************************************
//*claer fileselection at copy done                                //~vb7vI~
//*rc=1:data exist,0 no data                                       //~vb7vI~
//*************************************************************
int uclipboard_getfileselection_Clear(int Popt)                    //~vb7vI~
{
    int rc;                                                        //~vb7vI~
//***************                                                  //~vb7vI~
	rc=Scb_uris!=0;                                                //~vb7vI~
    dprintf("%s:entry old uri=%s\n",UTT,Scb_uris);                 //~vb7vI~
	Scb_uris=0;                                                    //~vb7vI~
    return rc;                                                     //~vb7vI~
}//uclipboard_getfileselection_Clear                               //~vb7vR~
#endif //YYY                                                       //~vb7vR~
//*************************************************************    //~v686I~
GtkSelectionData *uclipboard_getfileselection(void)                //~v686R~
{                                                                  //~v686I~
    GdkAtom  atomtgt;                                              //~v686I~
//*********************************                                //~v686I~
    dprintf("%s:entry\n",UTT);                                     //~vb7vR~
#ifdef AAA                                                         //~vb7vR~
    atomtgt=gdk_atom_intern(COPYFILETARGETID,TRUE);                //~vb7vI~
    if (atomtgt==GDK_NONE)                                         //~vb7vI~
    {                                                              //~vb7vI~
	    dprintf("%s:gdk_atom_intern TRUE no atom gotten req=%s\n",UTT,COPYFILETARGETID);//~vb7vI~
        return 0;                                                  //~vb7vI~
    }                                                              //~vb7vI~
    else                                                           //~vb7vI~
    {                                                              //~vb7vI~
    	dprintf("%s:gdk_atom_intern TRUE name=%s\n",UTT,           //~vb7vI~
				 	gdk_atom_name(atomtgt));                       //~vb7vI~
    }                                                              //~vb7vI~
#endif                                                             //~vb7vI~
#ifdef SUPPORT_GNOMECOPY                                           //~vb7wR~
    atomtgt=gdk_atom_intern(COPYFILETARGETID,FALSE);               //~v686I~
#else                                                              //~vb7wR~
    atomtgt=gdk_atom_intern(DRAGFILETARGETID,FALSE);               //~vb7wR~
#endif                                                             //~vb7wR~
#if defined(OPTGTK3) && !defined(YYY)                              //~vb7vI~
//  ftime(&Scb_timeReq);                                           //~vb7vI~//~vbs1R~
    uftime(&Scb_timeReq);                                          //~vbs1I~
//  gtk_clipboard_request_uris(Gpclipboard,(GtkClipboardURIReceivedFunc)uclipboard_cbURIRequestContents,(gpointer)Gcb_userdataReq);//@@@@test//~vb7vI~
//  gtk_clipboard_request_text(Gpclipboard,(GtkClipboardTextReceivedFunc)uclipboard_cbTextRequestContents,(gpointer)Gcb_userdataReq);//@@@@test//~vb7vI~
    gtk_clipboard_request_contents(Gpclipboard,atomtgt,(GtkClipboardReceivedFunc)uclipboard_cbRequestContents,(gpointer)Gcb_userdataReq);//~vb7vR~
    dprintf("%s:gtk_clipboard_request_contents;userdata=%s,atom name=%s\n",UTT,Gcb_userdataReq,gdk_atom_name(atomtgt));//~vb7vR~
    return 0;                                                      //~vb7vR~
#else                                                              //~vb7vR~
//#ifndef AAA //@@@@test                                           //~vb7vR~
//    {                                                            //~vb7vR~
//        GtkSelectionData *psd;                                   //~vb7vR~
//        gchar **puri;                                            //~vb7vR~
//        dprintf("%s:%s:gtk_clipboard_wait_for_uri call\n",UTT,(char*)utimeedit("hh:mm:ss.mil",0));//~vb7vR~
//        puri=gtk_clipboard_wait_for_uris(Gpclipboard);           //~vb7vR~
//        dprintf("%s:%s:gtk_clipboard_wait_for_uri returned puri=%p=%s\n",UTT,(char*)utimeedit("hh:mm:ss.mil",0),puri,(puri?*puri:"no uri"));//~vb7vR~
//        dprintf("%s:%s:gtk_clipboard_wait_for_contents call\n",UTT,(char*)utimeedit("hh:mm:ss.mil",0));//~vb7vR~
//        psd=gtk_clipboard_wait_for_contents(Gpclipboard,atomtgt);//~vb7vR~
//        dprintf("%s:%s:gtk_clipboard_wait_for_contents returned\n",UTT,(char*)utimeedit("hh:mm:ss.mil",0));//~vb7vR~
//        return psd;                                              //~vb7vR~
//    }                                                            //~vb7vR~
//#else                                                            //~vb7vI~
	return gtk_clipboard_wait_for_contents(Gpclipboard,atomtgt);   //~v686R~
//#endif                                                           //~vb7vI~
#endif                                                             //~vb7vR~
}// uclipboard_getfileselection()                                  //~v686I~
#ifdef AAA	//no user                                              //~vb7vI~
//*************************************************************    //~v686I~
//*get text from clipboard                                         //~v686I~
//*                                                                //~v686I~
//*************************************************************    //~v686I~
int uclipboard_getcopyfile(char **Pfilenames,int *Pfilectr,int *Pplen)//~v686R~
{                                                                  //~v686I~
    GtkSelectionData *pseldata;                                    //~v686I~
//  GdkAtom  atomtgt;                                              //~v69rR~
    int rc;                                                        //~v686I~
//*********************************                                //~v686I~
	if (!(pseldata=uclipboard_getfileselection()))                 //~v686R~
    {                                                              //~v686I~
    	return -1;		//no drop file                             //~v686I~
    }                                                              //~v686I~
	rc=uclipboard_getcopyfilesub(UCLIPBOARD_FREESELECTION,pseldata,Pfilenames,Pfilectr,Pplen);//~v686R~
    return rc;                                                     //~v686R~
}//uclipboard_getcopyfile                                          //~v686R~
#endif                                                             //~vb7vI~
//*************************************************************    //~v686M~
//*get dropfile info from clipboard                                //~v686M~
//rc:err                                                           //~v686M~
//*************************************************************    //~v686M~
int uclipboard_getcopyfilesub(int Popt,GtkSelectionData *Pseldata,char **Pfilenames,int *Pfilectr,int *Pplen)//~v686R~
{                                                                  //~v686M~
	int  rc=0,totlen=0,len,filectr=0,reslen,reslen0;               //~v686R~
    char *pc,*pce,*pc0,*pcout,*pcout0;                             //~v686M~
    char uri[_MAX_PATH];                                           //~v686M~
    char fnm[_MAX_PATH];                                           //~v686M~
//***************************************                          //~v686M~
//	dprintf("drag data received selection=%d,target=%d,type=%d,format=%d,data=%s,len=%d\n",//~v686M~//~va72R~
//		(int)(Pseldata->selection),                                //~v686M~//~va72R~
//		(int)(Pseldata->target),                                   //~v686M~//~va72R~
//		(int)(Pseldata->type),                                     //~v686M~//~va72R~
#ifndef OPTGTK3                                                    //~var8R~
  	dprintf("drag data received selection=%p,target=%p,type=%p,format=%d,data=%s,len=%d\n",//~va72I~
  		(Pseldata->selection),                                     //~va72I~
  		(Pseldata->target),                                        //~va72I~
  		(Pseldata->type),                                          //~va72I~
		Pseldata->format,                                          //~v686M~
		Pseldata->data,                                            //~v686M~
		Pseldata->length);                                         //~v686M~
    dprintf("receive name selection=%s\n",                         //~v686M~
			 gdk_atom_name(Pseldata->selection));                  //~v686M~
    dprintf("receive name target=%s\n",                            //~v686M~
			 gdk_atom_name(Pseldata->target));                     //~v686M~
    dprintf("receive name type=%s\n",                              //~v686M~
			 gdk_atom_name(Pseldata->type));                       //~v686M~
#endif                                                             //~var8R~
#if defined(OPTGTK3) && !defined(YYY)                              //~vb7vI~
  if (!Pseldata)	//by Paste                                     //~vb7vI~
  {                                                                //~vb7vI~
	if (!uclipboard_getfileselection_Received(0,&pc0,0/*Puserdata*/))//~vb7vI~
    	return 8;                                                  //~vb7vI~
    reslen0=strlen(pc0);                                           //~vb7vI~
  }                                                                //~vb7vI~
  else                                                             //~vb7vI~
#endif                                                             //~vb7vR~//~vb7wM~
  {                                                                //~vb7vI~
#ifndef OPTGTK3                                                    //~var8R~
    if (!(Pseldata->length>0 && Pseldata->format==8))	//format:8:char bit size//~v686M~
#else                                                              //~var8R~
    if (!(gtk_selection_data_get_length(Pseldata)>0 && gtk_selection_data_get_format(Pseldata)==8))	//format:8:char bit size//~var8R~
#endif                                                             //~var8R~
    	return 8;                                                  //~v686M~
#ifndef OPTGTK3                                                    //~var8R~
    pc0=Pseldata->data;                                            //~v686R~
    reslen0=Pseldata->length;                                      //~v686R~
#else                                                              //~var8R~
    pc0=(guchar*)gtk_selection_data_get_data(Pseldata); //fdrop const//~var8R~
    reslen0=gtk_selection_data_get_length(Pseldata);               //~var8R~
#endif                                                             //~var8R~
  }//Pseldata!=null                                                //~vb7vI~
    if (reslen0>COPYFILEIDLEN && !memcmp(pc0,COPYFILEID,COPYFILEIDLEN))//copy\n for paste after copy//~v686R~
    {                                                              //~v686I~
		reslen0-=COPYFILEIDLEN;     //"copy\n"                     //~v686I~
        pc0+=COPYFILEIDLEN;                                        //~v686I~
    }                                                              //~v686I~
    else                                                           //~v686I~
    if (reslen0>CUTFILEIDLEN && !memcmp(pc0,CUTFILEID,CUTFILEIDLEN))//copy\n for paste after copy//~v686R~
    {                                                              //~v686I~
		reslen0-=CUTFILEIDLEN;     //"copy\n"                      //~v686I~
        pc0+=CUTFILEIDLEN;                                         //~v686I~
    }                                                              //~v686I~
    for (pc=pc0,reslen=reslen0;reslen>0;)                          //~v686R~
    {                                                              //~v686M~
#ifdef SUPPORT_GNOMECOPY                                           //~vb7wR~
        if (reslen<=TEXTFILEIDLEN || memcmp(pc,TEXTFILEID,TEXTFILEIDLEN))//no drop fmt//~v686M~
        {                                                          //~v686M~
        	rc=4;                                                  //~v686M~
            break;                                                 //~v686M~
        }                                                          //~v686M~
        pc+=TEXTFILEIDLEN;                                         //~v686M~
#endif                                                             //~vb7wR~
        pce=strchr(pc,'\n');                                       //~v686M~
        if (pce)                                                   //~v686M~
        {                                                          //~v686M~
            len=(ULONG)pce-(ULONG)pc;                              //~v686M~
            if (pce>pc && *(pce-1)=='\r')                          //~v686M~
                len--;                                             //~v686M~
            memcpy(uri,pc,len);                                    //~v686M~
            *(uri+len)=0;                                          //~v686M~
        }                                                          //~v686M~
        else                                                       //~v686M~
        	strncpy(uri,pc,sizeof(uri));                           //~v686M~
//		pfnm=g_filename_from_uri(pc,&phostname,&perror);	//api may have bug//~v686M~
        if (uuridecode(uri,fnm,_MAX_PATH)<0)                       //~v686M~
        {                                                          //~v686M~
            rc=4;                                                  //~v686M~
            break;                                                 //~v686M~
        }                                                          //~v686M~
        totlen+=strlen(fnm)+1;                                     //~v686M~
        filectr++;                                                 //~v686M~
    	dprintf("file# %d=%s\n",filectr,fnm);                      //~v686I~
        if (!pce)                                                  //~v686M~
            break;                                                 //~v686M~
        pc=pce+1;                                                  //~v686M~
        if (!*pc) 	//linux len contain last null                  //~v686I~
        	break;                                                 //~v686I~
    	reslen=reslen0-((LONG)pc-(ULONG)pc0);                      //~v686R~
    }                                                              //~v686M~
    if (rc)                                                        //~v686I~
        return rc;                                                 //~v686I~
    pcout=pcout0=umemalloc(totlen);                                //~v686M~
    for (pc=pc0,reslen=reslen0;reslen>0;)                          //~v686R~
    {                                                              //~v686M~
#ifdef SUPPORT_GNOMECOPY                                           //~vb7wR~
        pc+=TEXTFILEIDLEN;                                         //~v686M~
#endif                                                             //~vb7wR~
        pce=strchr(pc,'\n');                                       //~v686M~
        if (pce)                                                   //~v686M~
        {                                                          //~v686M~
            len=(ULONG)pce-(ULONG)pc;                              //~v686M~
            if (pce>pc && *(pce-1)=='\r')                          //~v686M~
                len--;                                             //~v686M~
            memcpy(uri,pc,len);                                    //~v686M~
            *(uri+len)=0;                                          //~v686M~
        }                                                          //~v686M~
        else                                                       //~v686M~
        	strncpy(uri,pc,sizeof(uri));                           //~v686M~
//		pfnm=g_filename_from_uri(pc,&phostname,&perror);	//api may have bug//~v686M~
        uuridecode(uri,fnm,_MAX_PATH);                             //~v686R~
        len=strlen(fnm)+1;                                         //~v686M~
        memcpy(pcout,fnm,len);                                     //~v686M~
        pcout+=len;                                                //~v686M~
        if (!pce)                                                  //~v686M~
            break;                                                 //~v686M~
        pc=pce+1;                                                  //~v686M~
        if (!*pc) 	//linux len contain last null                  //~v686I~
        	break;                                                 //~v686I~
    	reslen=reslen0-((LONG)pc-(ULONG)pc0);                      //~v686I~
    }                                                              //~v686M~
#if defined(OPTGTK3) && !defined(YYY)                              //~vb7vI~
#else                                                              //~vb7vI~
    if (Popt & UCLIPBOARD_FREESELECTION)  //free selection data    //~v686R~
		gtk_selection_data_free(Pseldata);                         //~v686R~
#endif                                                             //~vb7vI~
    dprintf("%s:out=%s\n",UTT,pcout0);                             //~vb7vI~
    *Pfilenames=pcout0;                                            //~v686R~
    *Pfilectr=filectr;                                             //~v686I~
    if (Pplen)                                                     //~v686R~
    	*Pplen=totlen;                                             //~v686R~
    return 0;                                                      //~v686M~
}//uclipboard_getcopyfilesub                                       //~v686I~
//*************************************************************    //~5624I~
//*get text from clipboard                                         //~5624I~
//*return by utf8 string for the case paste insto utf8 file(wide range translation)                                                                //~5624I~//~va20R~
//*************************************************************    //~5624I~
//int uclipboard_gettext(char **Pptext,int *Pplen)                 //~v76cR~
int uclipboard_gettext(int Popt,char **Pptext,int *Pplen,GtkClipboardTextReceivedFunc Ppcallback)//~v76cR~
{                                                                  //~5624I~
#ifdef UTF8UCS2                                                    //~va20I~
#else                                                              //~va20I~
    GError *errpos=NULL;                                           //~v69nR~
//	int readlen,writelen,len;                                      //~v7axR~
  	gsize readlen,writelen;                                        //~v7axR~
#endif                                                             //~va20I~
  	int len;                                                       //~v7axR~
    char *putf8/*,*ptext*/;                                            //~5624I~//~va20R~
//*********************************                                //~5624I~
	putf8=*Pptext;                                                 //~v76cI~
	*Pptext=0;                                                     //~v66qI~
//  if (!(putf8=gtk_clipboard_wait_for_text(Gpclipboard)))	//accepted len//~v76cR~
    dprintf("gettextentry \n");                                    //~v76cI~
  if (!(Popt & UCBGT_CBDATA))                                      //~v76cI~
  {                                                                //~v76cI~
    if (Popt & UCBGT_PRIMARY)                                      //~v76cI~
    {                                                              //~v76cI~
//        dprintf("PRIMARY=%p\n",Gpclipboardp);                    //~v76cR~
//        if (!Gpclipboardp)                                       //~v76cR~
//            Gpclipboardp=gtk_clipboard_get(GDK_SELECTION_PRIMARY);//~v76cR~
//        dprintf("new PRIMARY=%p\n",Gpclipboardp);                //~v76cR~
//        if (!Gpclipboardp)                                       //~v76cR~
//            return -2;                                           //~v76cR~
		if (Popt & UCBGT_SETCB)                                    //~v76cR~
        {                                                          //~v76cI~
	        dprintf("PRIMARY(%p) request data\n",Gpclipboardp);    //~v76cI~
        	gtk_clipboard_request_text(Gpclipboardp,(GtkClipboardTextReceivedFunc)Ppcallback,0);//~v76cR~
            return 0;                                              //~v76cI~
        }                                                          //~v76cI~
	    putf8=gtk_clipboard_wait_for_text(Gpclipboardp);	//PRIMARY clipboard accepted len//~v76cR~
        dprintf("PRIMARY text=%s\n",putf8);                        //~v76cI~
    }                                                              //~v76cI~
    else                                                           //~v76cI~
    	putf8=gtk_clipboard_wait_for_text(Gpclipboard);	//accepted len//~v76cI~
  }//not cbdata                                                    //~v76cI~
    if (!putf8)	//accepted len                                     //~v76cI~
    {                                                              //~5624I~
//  	return uerrmsgbox("Cut/Paste:failed to get text from clipboard",0);//~v66qR~
//  	return -1;                                                 //~v66qR~
    	return -2;                                                 //~v66qI~
    }                                                              //~5624I~
    len=strlen(putf8);                                             //~5624I~
#ifdef UTF8UCS2                                                    //~va20I~
    *Pptext=putf8;                                                 //~va20I~
    *Pplen=len;                                                    //~va20I~
dprintf("%s:uclipboard gettext %s\n",UTT,putf8);                           //~va20I~//~vb7vR~
#else                                                              //~va20I~
    ptext=g_locale_from_utf8(putf8,len,&readlen,&writelen,&errpos);//~5624I~
    PRINTGERR("uclipboard_gettext-g_locale_from_utf8",errpos);     //~v69rR~
    if (readlen!=len)                                              //~5624I~
    {                                                              //~5624I~
    	if (ptext)                                                 //~5624I~
	    	g_free(ptext);                                         //~5624I~
    	return uerrmsgbox("Cut/Paste:clipboard data contains invalid text",0);//~5624I~
    	return -1;                                                 //~5624I~
    }                                                              //~5624I~
  if (!(Popt & UCBGT_CBDATA))                                      //~v76cR~
    g_free(putf8);                                                 //~5624I~
    *Pptext=ptext;                                                 //~5624I~
    *Pplen=writelen;                                               //~5624I~
#endif                                                             //~va20M~
    return 0;                                                      //~5624I~
}//clipboard_gettext                                               //~5624I~
//*************************************************************    //~5624I~
//*get text from clipboard                                         //~5624I~
//*                                                                //~5624I~
//*************************************************************    //~5624I~
void uclipboard_memfree(char *Pmem)                                //~5624I~
{                                                                  //~5624I~
UTRACEP("uclipboard memfree addr=%p\n",Pmem);                      //~va20I~
    g_free(Pmem);                                                  //~5624I~
    return;                                                        //~5624I~
}//uclipboard_memfree(char *Pmem)                                  //~5624I~
//*************************************************************    //~5625I~
//*decode %xx:output is strz                                       //~5625R~
//*rc:1:converted,0:no encoded data,-1:fmt err,-2:outbuff ovf      //~5625R~
//*************************************************************    //~5625I~
int uuridecode(char *Puri,char *Pdecoded,int Pobuffsz)             //~5625R~
{                                                                  //~5625I~
	int encodedsw=0;                                               //~5625I~
	char *pci,*pco,*pce,*pcoe;                                     //~5625R~
//***************************                                      //~5625I~
	for (pci=Puri,pco=Pdecoded,pce=pci+strlen(pci)+1,pcoe=pco+Pobuffsz;pci<pce;)//~5625R~
    {                                                              //~5625I~
    	if (pco>=pcoe)	//buff overflow                            //~5625I~
        	return -2;                                             //~5625I~
		if (*pci!='%')                                             //~5625I~
        {                                                          //~5625I~
        	*pco++=*pci++;                                         //~5625R~
			continue;                                              //~5625I~
		}                                                          //~5625I~
        encodedsw=1;                                               //~5625R~
        pci++;                                                     //~5625I~
        if (ugethex(pci,pco,2)<0)	//hex err                      //~5625I~
        	return -1;                                             //~5625I~
    	pci+=2;                                                    //~5625R~
        pco++;                                                     //~5625I~
	}                                                              //~5625I~
    return encodedsw;                                              //~5625R~
}//uuridecode                                                      //~5625I~
//*******************************************************************//~5625M~
//*filenames setup         xxx\0yyy-->copy\nfile://xxx\ryyy\r\0    //~5628R~
//*******************************************************************//~5625M~
char *usetupuri(int Popt,char *Pstrlist)                           //~vXXER~
{                                                                  //~5625M~
	char *pci,*pco,*puri;                                          //~5625R~
    int len,filecnt=0,ii,copyfilesw;                               //~vXXER~
//*****************************                                    //~5625M~
	copyfilesw=Popt & USUO_COPYFILE;                               //~vXXEI~
#ifdef SUPPORT_GNOMECOPY                                           //~vb7wR~
#else                                                              //~vb7wR~
   	copyfilesw=0; //COPYFILEID(copy) is for x-special/gnome-copied-files and not for /text/uri-list//~vb7wR~
#endif                                                             //~vb7wR~
    for(ii=0,pci=Pstrlist;*pci!=0;ii++)                            //~5625R~
    	pci+=strlen(pci)+1;                                        //~5625M~
    filecnt=ii;                                                    //~5625M~
    if (!filecnt)                                                  //~vXXEI~
    	return "";                                                 //~vXXEI~
#ifdef SUPPORT_GNOMECOPY                                           //~vb7wR~
    len=(ULONG)pci-(ULONG)Pstrlist+filecnt*TEXTFILEIDLEN+1;        //~vXXER~
//  len=(ULONG)pci-(ULONG)Pstrlist+filecnt*(TEXTFILEIDLEN+1)+1;    //~vXXER~
#else                                                              //~vb7wR~
    len=(ULONG)pci-(ULONG)Pstrlist+1;                              //~vb7wR~
#endif                                                             //~vb7wR~
    if (copyfilesw)                                                //~vXXEI~
		len+=COPYFILEIDLEN;     //"copy\n"                         //~vXXER~
    dprintf("usetupcopyuri=len=%d,copyfilesw=%d\n",len,copyfilesw);//~vX03R~
	pco=puri=umemalloc((UINT)len);                                 //~vXXER~
    if (copyfilesw)                                                //~vXXEI~
    {                                                              //~vXXEI~
	    memcpy(pco,COPYFILEID,COPYFILEIDLEN);	//"copy\n"         //~vXXER~
    	pco+=COPYFILEIDLEN;                                        //~vXXER~
    }                                                              //~vXXEI~
    for(ii=0,pci=Pstrlist;ii<filecnt;ii++)                         //~vXXER~
	{                                                              //~5625M~
#ifdef SUPPORT_GNOMECOPY                                           //~vb7wR~
		memcpy(pco,TEXTFILEID,TEXTFILEIDLEN);                      //~5625M~
		pco+=TEXTFILEIDLEN;                                        //~5625M~
#endif                                                             //~vb7wR~
		len=strlen(pci);                                           //~5625M~
        memcpy(pco,pci,(UINT)len);	//no hostname (file://hostname/...)//~vXXER~
        pci+=len+1;                                                //~5625M~
        pco+=len;                                                  //~5625M~
//    	*pco++='\r';    //target dose not accept when \r exist     //~vXXER~
    	*pco++='\n';                                               //~vXXER~
    }                                                              //~5625M~
    pco--;	//drop last "\n"                                       //~vb7xI~
	*pco=0;		                                                   //~vXXER~
    dprintf("%s:uri=%s\n",UTT,puri);                            //~vX03R~//~vb7vR~
//  puri=gnome_vfs_escape_host_and_path_string(puri);   //fail when encoded//~vXXER~
//  dprintf("uri encode=%s\n",puri);                               //~vX03R~
    return puri;                                                   //~5625R~
}//setupuri                                                        //~5625M~
#ifdef XXX                                                         //~vXXEI~
//*******************************************************************//~vXXEI~
//*start drag                                                      //~vXXEI~
//*******************************************************************//~vXXEI~
void udragtimeout_callback(void *Pdraginfo)                        //~vXXER~
{                                                                  //~vXXEI~
    GtkDragSourceInfo *pdraginfo;                                  //~vXXER~
//*****************************                                    //~vXXEI~
	 dprintf("udrag timeout callback\n");                           //~vX03R~
    if (Sdragtimeout)                                              //~vXXEI~
    {                                                              //~vXXEI~
    	pdraginfo=(GtkDragSourceInfo)Pdraginfo;                    //~vXXER~
    	gtk_drag_cancel(pdraginfo,GDK_CURRENT_TIME);               //~vXXER~
        uerrmsgbox("Drag Timeout(%d seconds)",Sdragtimeout);       //~vXXEI~
    }                                                              //~vXXEI~
    return;                                                        //~vXXEI~
}//udragtimeout_callback                                           //~vXXER~
#endif                                                             //~vXXEI~
//*******************************************************************//~5627I~
//*start drag                                                      //~5627I~
//*******************************************************************//~5627I~
void udragbegin(int Ptimeout)                                      //~vXXER~
{                                                                  //~5627I~
    GtkTargetList *ptl;                                            //~5627I~
#if GTK_CHECK_VERSION(3,10,0)	//gtk_ui_manager was deprecated    //~vb7tR~
	int x,y;                                                       //~vb7tR~
#endif                                                             //~vb7tR~
//*****************************                                    //~5627I~
	 dprintf("%s:udragbegin source_set & drag_begin \n",(char*)utimeedit("hh:mm:ss.mil",0));//~vX03R~
    ptl= gtk_target_list_new (Sdragfiletarget, 1);	//1 entry, texturi-list//~vXXER~
//  gtk_drag_source_set(Gpview,GDK_BUTTON1_MASK,Sdragfiletarget,1,GDK_ACTION_COPY);//~vXXER~
    dprintf("%s:udragbegin:before begin request\n",(char*)utimeedit("HHMMSS.MIL",0));//~v69VI~
#if GTK_CHECK_VERSION(3,10,0)	//gtk_ui_manager was deprecated    //~vb7tR~
	x=0; y=0;                                                      //~vb7tR~
    Gpsourcedragcontext=gtk_drag_begin_with_coordinates(Gpview,ptl,GDK_ACTION_COPY,1,(GdkEvent*)NULL,x,y);//1=button1//~vb7tR~
#else                                                              //~vb7tR~
    Gpsourcedragcontext=gtk_drag_begin(Gpview,ptl,GDK_ACTION_COPY,1,(GdkEvent*)NULL);//1=button1//~vXXER~
#endif                                                             //~vb7tR~
#ifdef XXX                                                         //~vXXEI~
    if (Ptimeout)                                                  //~vXXEI~
    {                                                              //~vXXEI~
    	Spdraginfo=gtk_drag_get_source_info(Gpsourcedragcontext,FALSE);  //FALSE:createsw//~vXXEI~
        Sdragtimeout=Ptimeout;                                     //~vXXEI~
    	gtk_timeout_add(Ptimeout*1000,udragtimeout_callback,Sdraginfo);//~vXXEI~
    }                                                              //~vXXEI~
#endif                                                             //~vXXEI~
    dprintf("%s:udragbegin:begin requested\n",(char*)utimeedit("HHMMSS.MIL",0));//~v69VI~
    return;                                                        //~5627I~
}//udragbegin                                                      //~5627I~
//*******************************************************************//~5627I~
//*end drag                                                        //~5627I~
//*******************************************************************//~5627I~
void udragend(void)                                                //~5627I~
{                                                                  //~5627I~
//*****************************                                    //~5627I~
	 dprintf("udragend unset requested ***\n");                     //~vX03R~
#ifdef XXX                                                         //~vXXEI~
    Sdragtimeout=0;                                                //~vXXEI~
#endif                                                             //~vXXEI~
    dprintf("is grabed?=%d\n",gdk_pointer_is_grabbed());           //~vX03R~
//  gtk_drag_source_unset(Gpview);                                 //~vXXER~
    return;                                                        //~5627I~
}//udragend                                                        //~vXXER~
//***************************************************************************//~vXXEI~
//* setup as drag target    *************************************************//~vXXEI~
//***************************************************************************//~vXXEI~
void udragdestset(void)                                            //~vXXEI~
{                                                                  //~vXXEI~
//*******************************                                  //~vXXEI~
	gtk_drag_dest_set(Gpframe,		//drop on all window           //~vXXEI~
       					GTK_DEST_DEFAULT_ALL,                      //~vXXEI~
                    	Sdragfiletarget,DRAGFILETARGETNO,GDK_ACTION_COPY);//~vXXEI~
//  gtk_drag_source_set(Gpview,     //drag from client window      //~vXXEI~
//                    (GDK_BUTTON1_MASK)|(GDK_BUTTON2_MASK),       //~vXXEI~
//                    tgte,DND_TARGETNO,GDK_ACTION_COPY);          //~vXXEI~
	return;                                                        //~vXXEI~
}//udragdestset                                                    //~vXXER~
//***************************************************************************//~vXXEI~
//* popupmenu set sensitive                                        //~vXXER~
//***************************************************************************//~vXXEI~
void upopupmenu_menuitem_enable(int Pmenuitemid,int Penable)       //~vXXER~
{                                                                  //~vXXEI~
    GtkWidget *pmenuitem;                                          //~vXXEI~
//*******************************                                  //~vXXEI~
	pmenuitem=gxemfrm_popupmenu_getmenuitem(Pmenuitemid);          //~vXXEI~
    dprintf("menuitem=%d enable=%d\n",Pmenuitemid,Penable);        //~vX03R~
    if (pmenuitem)                                                 //~vXXEI~
    {                                                              //~vXXEI~
		gtk_widget_set_sensitive(pmenuitem,Penable);               //~vXXEI~
//        if (Penable)                                             //~vXXER~
//        {                                                        //~vXXER~
//            switch(Pselect)                                      //~vXXER~
//            {                                                    //~vXXER~
//            case 1: //set select                                 //~vXXER~
//                gtk_menu_item_select(GTK_MENU_ITEM(pmenuitem));  //~vXXER~
//                break;                                           //~vXXER~
//            case -1:    //set deselect                           //~vXXER~
//                gtk_menu_item_deselect(GTK_MENU_ITEM(pmenuitem));//~vXXER~
//            }                                                    //~vXXER~
//        }                                                        //~vXXER~
    }                                                              //~vXXEI~
	return;                                                        //~vXXEI~
}//upopupmenu_menuitem_enable                                      //~vXXER~
////***************************************************************************//~vXXER~
////* popupmenu popup                                              //~vXXER~
////***************************************************************************//~vXXER~
//void popupmenu_position_func(GtkMenu *Ppmenu,gint *Ppx,gint *Ppy,gboolean *Pppushin,gpointer Pudata)//~vXXER~
//{                                                                //~vXXER~
//    CPoint *ppoint;                                              //~vXXER~
//    GtkRequisition req;                                          //~vXXER~
//    GdkScreen *pscr;                                             //~vXXER~
//    int rootx,rooty,xx,yy,ww,hh;                                 //~vXXER~
////*******************************                                //~vXXER~
//    ppoint=(CPoint*)Pudata;                                      //~vXXER~
//    dprintf("popupmenu position buttonpos x=%d,y=%d\n",ppoint->x,ppoint->y);//~vX03R~
//    gdk_window_get_origin(Gpview->window,&rootx,&rooty);         //~vXXER~
//    dprintf("popupmenu position rootx=%d,rooty=%d\n",rootx,rooty);//~vX03R~
//    gtk_widget_size_request(GTK_WIDGET(Ppmenu),&req);            //~vXXER~
//    pscr=gtk_widget_get_screen(Gpview);                          //~vXXER~
//    ww=gdk_screen_get_width(pscr);                               //~vXXER~
//    hh=gdk_screen_get_height(pscr);                              //~vXXER~
//    dprintf("popupmenu view ww=%d,hh=%d\n",ww,hh);               //~vX03R~
//    yy=rooty+ppoint->y+5;                                        //~vXXER~
//    xx=rootx+ppoint->x+5;                                        //~vXXER~
//    *Ppx=xx;                                                     //~vXXER~
//    *Ppy=yy;                                                     //~vXXER~
//    *Pppushin=0;    //not pushin completely inside the scr       //~vXXER~
//    dprintf("popupmenu ret xx=%d,yy=%d\n",xx,yy);                //~vX03R~
//    return;                                                      //~vXXER~
//}//upopupmenu_popup                                              //~vXXER~
//***************************************************************************//~vXXEI~
//* popupmenu popup                                                //~vXXEI~
//***************************************************************************//~vXXEI~
void upopupmenu_popupCHL(CPoint Ppoint)                            //~vbj2M~
{                                                                  //~vbj2M~
//*******************************                                  //~vbj2M~
	dprintf("%s\n",UTT);                                           //~vbj2M~
    gtk_widget_show_all(GppopupmenuCHL);                           //~vbj2M~
#if GTK_CHECK_VERSION(3,22,0)	//gtk_ui_manager was deprecated    //~vbj2M~
    gtk_menu_popup_at_pointer(GTK_MENU(GppopupmenuCHL),NULL/*current GdkEvent*/);//~vbj2M~
#else                                                              //~vbj2M~
    gtk_menu_popup(GTK_MENU(GppopupmenuCHL),NULL,NULL,             //~vbj2M~
  				NULL,NULL,3,gtk_get_current_event_time());//3:button3//~vbj2M~
#endif                                                             //~vbj2M~
	return;                                                        //~vbj2M~
}//upopupmenu_popupCHL                                             //~vbj2M~
//***************************************************************************//~vbj2M~
void upopupmenu_popup(CPoint Ppoint)                               //~vXXER~
{                                                                  //~vXXEI~
//*******************************                                  //~vXXEI~
	if (Gxxestat & GXXES_POPUPMENU_CHL)                            //~vbj2I~
    {                                                              //~vbj2I~
		upopupmenu_popupCHL(Ppoint);                               //~vbj2I~
        return;                                                    //~vbj2I~
    }                                                              //~vbj2I~
	dprintf("upopupmenu_popup\n");                                 //~var8R~
    gtk_widget_show_all(Gppopupmenu);                              //~var8R~
#if GTK_CHECK_VERSION(3,22,0)	//gtk_ui_manager was deprecated    //~vb7tR~
    gtk_menu_popup_at_pointer(GTK_MENU(Gppopupmenu),NULL/*current GdkEvent*/);//~vb7tR~
#else                                                              //~vb7tR~
    gtk_menu_popup(GTK_MENU(Gppopupmenu),NULL,NULL,                //~vXXER~
//  				*popupmenu_position_func,&Ppoint,3,GDK_CURRENT_TIME);//posfunc use cause menu disapear by rb-up//~vXXER~
//				NULL,NULL,3,GDK_CURRENT_TIME);//3:button3          //~v75YR~
  				NULL,NULL,3,gtk_get_current_event_time());//3:button3//~v75YI~
#endif                                                             //~vb7tR~
	return;                                                        //~vXXEI~
}//upopupmenu_popup                                                //~vXXER~
//***************************************************************************//~vamgI~
//* test string width by PANO_SCALE                                //~vamgI~
//***************************************************************************//~vamgI~
int                                                                //~vamgI~
ufontgetstrwidth(PangoFontDescription *Pfontdesc,char *Pstr)       //~vamgI~
{                                                                  //~vamgI~
	PangoLayout *playout;                                          //~vamgR~
	PangoRectangle rect;                                           //~vamgR~
	PangoRectangle ink_rect,logical_rect;                          //~vamgI~
    int width;                                                     //~vamgI~
//**********************                                           //~vamgI~
    playout=gtk_widget_create_pango_layout(Gpview,Pstr);           //~vamgI~
    pango_layout_set_font_description(playout,Pfontdesc);          //~vamgI~
//#ifdef AAA                                                       //~vamgI~
    pango_layout_get_pixel_extents(playout,NULL,&rect);//get logical extent//~vamgR~
    UTRACEP("pango layout pixcel str=%s,rect=(x=%d,y=%d-w=%d,h=%d)\n",//~vamgR~
            Pstr,rect.x,rect.y,rect.width,rect.height);            //~vamgR~
    width=rect.width;                                              //~vamgR~
//#else                                                            //~vamgI~
    pango_layout_get_extents(playout,&ink_rect,&logical_rect);//get logical extent//~vamgI~
    UTRACEP("pango layout pixcel str=%s,inc_rect=(x=%d,y=%d-w=%d,h=%d),logical_rect=(x=%d,y=%d-w=%d,h=%d)\n",//~vamgI~
            Pstr,ink_rect.x,ink_rect.y,ink_rect.width,ink_rect.height,logical_rect.x,logical_rect.y,logical_rect.width,logical_rect.height);//~vamgI~
    width=logical_rect.width;                                      //~vamgI~
//#endif                                                           //~vamgI~
    UTRACEP("ugetfontmetrics by test='W' fw=%d\n",width);          //~vamgI~
    g_object_unref(playout);                                       //~vamgR~
    return width;                                                  //~vamgI~
}//ufontgetstrwidth                                                //~vamgI~
//***************************************************************************//~vXXEI~
//* get font metrics                                               //~vXXEI~
//set monospace sw 0:none,1:monospace,2:sbcs only mnonospace       //~vX03I~
//***************************************************************************//~vXXEI~
//void ugetfontmetrics(PangoFontDescription *Pfontdesc,int *Ppwidth,int *Ppheight,int *Ppmonospace)//~vXXER~//~vam0R~
PangoFontMetrics *ugetfontmetrics(PangoFontDescription *Pfontdesc,int *Ppwidth,int *Ppheight,int *Ppmonospace)//~vam0I~
{                                                                  //~vXXEI~
	PangoFontMetrics *pfm;                                         //~vXXEI~
    int asc,des,/*wch,*/wdz,fw,fh;                                     //~v69VR~//~vaa7R~
    int sz;                                                        //~vam9I~
#ifndef NOTRACE                                                    //~vaa7I~
    int wch;                                                       //~vaa7I~
#endif                                                             //~vaa7I~
#ifndef AAA                                                        //~vam9R~
#else                                                              //~vam9I~
	double pixbypoint;                                             //~vam9I~
#endif                                                             //~vam9I~
//*******************************                                  //~vXXEI~
    dprintf("ugetfontmetrics desc=%p\n",Pfontdesc);                //~v76RI~
    pfm=pango_context_get_metrics(Gppangocontext,Pfontdesc,Gppangolang);//~vXXEI~
    asc=pango_font_metrics_get_ascent(pfm);                        //~vXXEI~
    des=pango_font_metrics_get_descent(pfm);                       //~vXXEI~
    sz=pango_font_description_get_size(Pfontdesc);//point*PANGO_SCALE//~vam9R~
    sz=sz;                                                         //~vb74I~
    UTRACEP("ugetfontmetrics ascent=%d,descent=%d,size=%d(point*PANGO_SCALE)\n",asc,des,sz);//~vam9I~
#ifndef NOTRACE                                                    //~vaa7I~
    wch=pango_font_metrics_get_approximate_char_width(pfm);        //~vXXEI~//~vaa7R~
#endif                                                             //~vaa7M~
    wdz=pango_font_metrics_get_approximate_digit_width(pfm);       //~vXXEI~
//  fw=max(wch,wdz);            //pango unit=PANGO_SCALE           //~vXXER~
#ifndef AAA                                                        //~vam9R~
    fw=wdz;            //char_width is affected by dbcs(double width)//~vXXEI~
#ifdef BBB	//var8test                                             //~vamgM~//~var8R~
	fw=ufontgetstrwidth(Pfontdesc,"W");                            //~vamgM~
#endif                                                             //~vamgM~
//  fw+=PANGO_SCALE-1;	//roundup                                  //~vam6R~//~vam9R~
    fh=asc+des;                                                    //~vamhI~
    UTRACEP("ugetfontmetrics before roundup width by half of height fw=%d,fh=%d\n",fw,fh);//~vamhI~
    if (fw<fh/2)                                                   //~vamhI~
    {                                                              //~vamhI~
		fw+=PANGO_SCALE-1;	//roundup                              //~vamhI~
        UTRACEP("ugetfontmetrics roundup width by half of height fw=%d,fh=%d\n",fw,fh);//~vamhI~
    }                                                              //~vamhI~
    *Ppwidth=PANGO_PIXELS(fw);                                     //~vXXEI~
//  fh=asc+des;                                                    //~vXXEI~//~vamhR~
//  fh+=PANGO_SCALE-1;   //roundup                                 //~vam6R~//~vam9R~
    *Ppheight=PANGO_PIXELS(fh);                                    //~vXXEI~
#else                                                              //~vam9I~
    pixbypoint=(double)(asc+des)/sz;                               //~vam9I~
    fh=sz;                                                         //~vam9I~
    fw=(int)wdz/pixbypoint+0.999;                                  //~vam9R~
    *Ppwidth=PANGO_PIXELS(fw);                                     //~vam9I~
    *Ppheight=PANGO_PIXELS(fh);                                    //~vam9I~
    UTRACEP("ugetfontmetrics pixbypoint=%lf ascent=%d,descent=%d,size=%d(point*PANGO_SCALE),descwsz=%d\n",pixbypoint,asc,des,sz,wdz);//~vam9R~
#endif                                                             //~vam9I~
    if (Ppmonospace)                                               //~vXXEI~
//  	*Ppmonospace=ufontismonospace(Pfontdesc);                  //~va1MR~
    	*Ppmonospace=ufontismonospace(Pfontdesc,*Ppwidth);         //~va1MR~
    UTRACEP("metrics ascent=%d,descent=%d,char-ww=%d,digit-ww=%d,ww=%d,hh=%d\n",asc,des,wch,wdz,*Ppwidth,*Ppheight);//~va1MR~
//  return;                                                        //~vXXEI~//~vam0R~
    return pfm;                                                    //~vam0I~
}//ugetfontmetrics                                                 //~vXXEI~
#ifdef UTF8SUPPH                                                   //~va1MR~
//***************************************************************************//~va1MR~
//* chk string width                                               //~va1MR~
//* (usetmonospace required for logical extent difference)         //~va1MR~
//***************************************************************************//~va1MR~
int ufontgetextentw(PangoLayout *Pplayout,int Pfontw,char *Pteststr)//~va1MR~
{                                                                  //~va1MR~
	PangoRectangle rect;                                           //~va1MR~
    int width,len;                                                 //~va1MR~
    char dbcswk[256];                                              //~va1MR~
//************************************                             //~va1MR~
	len=strlen(Pteststr);                                          //~va1MR~
    len=min(len,sizeof(dbcswk));                                   //~va1MR~
    pango_layout_set_text(Pplayout,Pteststr,len);  //chk ligature(mix 2 font->1 font)//~va1MR~
    memset(dbcswk,0,(UINT)len);                                    //~va1MR~
  	usetmonospace(0,Pplayout,Pteststr,dbcswk,len,Pfontw);          //~va1MR~
    pango_layout_get_pixel_extents(Pplayout,NULL,&rect);//get logical extent//~va1MR~
UTRACEP("pango layout pixcel char=%s,len=%d,logical=(x=%d,y=%d-w=%d,h=%d)\n",//~va1MR~//~vamgR~
            Pteststr,strlen(Pteststr),rect.x,rect.y,rect.width,rect.height);//~va1MR~
    width=rect.width;                                              //~va1MR~
    return width;                                                  //~va1MR~
}//ufontgetextentw                                                 //~va1MR~
#endif                                                             //~va1MR~
//***************************************************************************//~v69VI~
//* chk monospace:pango_font_family_is_monospace is not supported pango 1.0//~v69VI~
//***************************************************************************//~v69VI~
//int ufontismonospace(PangoFontDescription *Pfontdesc)            //~va1MR~
int ufontismonospace(PangoFontDescription *Pfontdesc,int Pfontw)   //~va1MR~
{                                                                  //~v69VI~
	PangoLayout *playout;                                          //~v69VI~
	PangoRectangle rect1,rect2/*,rect3*/;                          //~va1MR~
    int monospace=0;                                               //~v69VR~
#ifdef UTF8SUPPH                                                   //~va1MR~
#ifdef AAA  //ligture check is done by glyph count on layout       //~va30R~
    int ligaturechkw1,ligaturechkw2;                               //~va1MR~
#endif                                                             //~va30R~
#endif                                                             //~va1MR~
//************************************                             //~v69VI~
    playout=gtk_widget_create_pango_layout(Gpview,NULL);           //~v69VI~
	UTRACEP("ufontismonospace layout=%p,fontdesc=%p\n",playout,Pfontdesc);//~vam0I~
    pango_layout_set_font_description(playout,Pfontdesc);          //~v69VI~
    UTRACEP("ufontismonospace pango_layout_set_font_description playout=%p,fontdesc=%p\n",playout,Pfontdesc);//~vam0R~
    pango_layout_set_text(playout,"PP",2);                         //~v69VI~
    pango_layout_get_extents(playout,&rect1,&rect2);//get logical extent//~v69VI~
UTRACEP("pango layout extent char=%s,cellw=%d,ink=(x=%d,y=%d-w=%d,h=%d),logical=(x=%d,y=%d-w=%d,h=%d)\n","PP",//~va1MR~
            Pfontw,rect1.x,rect1.y,rect1.width,rect1.height,       //~va1MR~
            rect2.x,rect2.y,rect2.width,rect2.height);             //~v69VI~
    pango_layout_get_pixel_extents(playout,NULL,&rect1);//get logical extent//~v69VI~
UTRACEP("pango layout pixel char=%s,logical=(x=%d,y=%d-w=%d,h=%d)\n","PP",//~va1MR~
            rect1.x,rect1.y,rect1.width,rect1.height);             //~v69VI~
    pango_layout_set_text(playout,"  ",2);  //space+space          //~v69VR~
    pango_layout_get_pixel_extents(playout,NULL,&rect2);//get logical extent//~v69VI~
UTRACEP("pango layout 2 space pixel char=%s,logical=(x=%d,y=%d-w=%d,h=%d)\n","  ",//~va1MR~
            rect2.x,rect2.y,rect2.width,rect2.height);             //~v69VI~
                                                                   //~va1MR~
#ifdef UTF8SUPPH                                                   //~va1MR~
#ifdef AAA  //ligture check is done by glyph count on layout       //~va30R~
	ligaturechkw1=ufontgetextentw(playout,Pfontw,"fi");            //~va1MR~
	ligaturechkw2=ufontgetextentw(playout,Pfontw,"if");            //~va1MR~
    if (ligaturechkw1<ligaturechkw2)  //"fi" is shrinked to one glyph//~va1MR~
    	Gxxestat|=GXXES_FONTLIGATURE;                              //~va1MR~
    else                                                           //~va1MR~
    	Gxxestat&=~GXXES_FONTLIGATURE;                             //~va1MR~
UTRACEP("ligature chk flag=%x,w-(fi)=%d,w-(if)=%d\n",(Gxxestat & GXXES_FONTLIGATURE),ligaturechkw1,ligaturechkw2);//~va1MR~
#endif                                                             //~va30R~
#endif                                                             //~va1MR~
    monospace=(rect1.width==rect2.width);                          //~v69VI~
#ifndef UTF8SUPPH	//no DBCS chk                                  //~va1MR~
    if (monospace)                                                 //~v69VI~
    {                                                              //~v69VI~
        pango_layout_set_text(playout,"\xe3\x81\x82",3);    //japanese A//~v69VI~
        pango_layout_get_pixel_extents(playout,NULL,&rect3);//get logical extent//~v69VI~
        dprintf("pango layout pixel char=%s,logical=(x=%d,y=%d-w=%d,h=%d)\n","дв",//~v69VI~
        rect3.x,rect3.y,rect3.width,rect3.height);                 //~v69VI~
        monospace+=(rect1.width!=rect3.width);  //2:dbcs is not monospace//~v69VI~
    }                                                              //~v69VI~
#endif                                                             //~va1MR~
    g_object_unref(G_OBJECT(playout));                             //~v69VI~
    dprintf("%s is mnospace=%d\n",pango_font_description_get_family(Pfontdesc),monospace);//~v69VR~
    return monospace;                                              //~v69VI~
}//ufontismonospace                                                //~v69VI~
//***************************************************************************//~v69VI~
//* search family                                                  //~v69VI~
//***************************************************************************//~v69VI~
PangoFontFamily *usrchfontfamily(PangoFontDescription *Pfontdesc)  //~v69VR~
{                                                                  //~v69VI~
    PangoFontFamily *family,**pfamily;                             //~v69VI~
    int numfam;                                                    //~v69VR~
    char *famname,*famname2;                                       //~v69VI~
//*******************************                                  //~v69VI~
	famname=(char*)pango_font_description_get_family(Pfontdesc);          //~v69VR~
	dprintf("fontdesc famname=%s\n",famname);                      //~v69VI~
    pango_context_list_families(Gppangocontext,&pfamily,&numfam);  //~v69VI~
	dprintf("familis=%d\n",numfam);                                //~v69VI~
    for (;numfam>0;numfam--,pfamily++)                             //~v69VI~
    {                                                              //~v69VI~
    	family=*pfamily;                                           //~v69VI~
		famname2=(char*)pango_font_family_get_name(family);               //~v69VI~
        if (!strcmp(famname2,famname))                             //~v69VI~
        	return family;                                         //~v69VI~
    }                                                              //~v69VI~
    return 0;                                                      //~v69VI~
}//usrchfontfamily                                                 //~v69VI~
#ifdef AAA                                                         //~v77sR~
//***************************************************************************//~v77sI~
//* search printer font familyname                                 //~v77sI~
//***************************************************************************//~v77sI~
void uprtsrchfamily(char *Pfontname)                               //~v77sR~
{                                                                  //~v77sI~
	GList * families, * l;                                         //~v77sI~
#ifdef AAA                                                         //~v77sI~
    GnomeFontFamily *pfamily;                                      //~v77sI~
#endif                                                             //~v77sI~
	int ii;                                                        //~v77sI~
//*******************************                                  //~v77sI~
	families=gnome_font_family_list();                             //~v77sR~
    dprintf("families=%p\n",families);                             //~v77sI~
	if (families==NULL)                                            //~v77sR~
    	return;                                                    //~v77sI~
	for (ii=0,l = families; l != NULL; l = l->next,ii++)           //~v77sI~
    {                                                              //~v77sI~
    	dprintf("%02d:list=%p,data=%p:%s\n",ii,l,l->data,(char*)(l->data));//~v77sI~
#ifdef AAA                                                         //~v77sI~
        family=(GnomeFontFamily*)l;                                //~v77sI~
#endif                                                             //~v77sI~
	}                                                              //~v77sI~
	gnome_font_family_list_free (families);                        //~v77sI~
    return;                                                        //~v77sI~
}//uprtsrchfamily                                                  //~v77sR~
#endif                                                             //~v77sI~
//===============================================================================//~v77sI~
//serach gnomeFont                                                 //~v77sI~
//===============================================================================//~v77sI~
#ifndef NOPRINT                                                    //~vam0R~
	#ifdef GTKPRINT                                                //~vam0I~
	#else    //!GTKPRINT                                           //~vam0I~
GnomeFont *uprtfontsrchsub(char *Pfontname)                        //~v77sI~
{                                                                  //~v77sI~
	char fontname[256],*pc;                                        //~v77sI~
	GnomeFont *pfont;                                              //~v77sI~
#ifdef AAA                                                         //~v77sI~
    GnomeFontFace *pface;                                          //~v77sI~
#endif                                                             //~v77sI~
    gdouble dsize;                                                 //~v77sI~
    int italic;                                                    //~v77sI~
    PangoFontDescription *pfd;                                     //~v77sI~
    PangoWeight pweight;                                           //~v77sI~
    PangoStyle pstyle;                                             //~v77sI~
//*************                                                    //~v77sI~
    dprintf("uprtfontsrchsub parm=%s\n",Pfontname);                //~v77sI~
	strcpy(fontname,Pfontname);                                    //~v77sI~
    if (pc=strrchr(fontname,' '),!pc)	//search size backward     //~v77sI~
    	return 0;                                                  //~v77sI~
    *pc++=0;      //del size                                       //~v77sI~
    dsize=(gdouble)atoi(pc);                                       //~v77sI~
    if (pc=strchr(fontname,','),pc)                                //~v77sI~
    	*pc++=0;	//style                                        //~v77sI~
    else                                                           //~v77sI~
    if (pc=strchr(fontname,' '),pc)	//space embedding(gxedlg would set "," for end of space embedding family name)//~v77sI~
    	*pc++=0;	//style                                        //~v77sI~
    else                                                           //~v77sI~
    	return 0;              //no style                          //~v77sI~
    pc+=strspn(pc," ");                                            //~v77sI~
#ifdef AAA // gnome_font_face_get_font_fuull is external but private.h//~v77sI~
    pface=gnome_font_face_find_from_family_and_style(fontname,pc); //~v77sI~
    dprintf("find face=%p,family=%s,style=%s,size=%d\n",pface,fontname,pc,(int)dsize);//~v77sI~
    if (!pface)                                                    //~v77sI~
    	return 0;                                                  //~v77sI~
    pfont=gnome_font_face_get_font_full(pface,dsize,NULL);         //~v77sI~
	dprintf("find font by face font=%p\n",pfont);                  //~v77sI~
#endif                                                             //~v77sI~
#ifndef AAA 	//test weight_slant api                            //~v77sI~
	pfd=pango_font_description_from_string(Pfontname);//desc of context may freed,so allocate new//~v77sI~
    dprintf("pangoFD=%p by %s\n",pfd,Pfontname);                   //~v77sI~
    if (!pfd)                                                      //~v77sI~
    	return 0;                                                  //~v77sI~
    pweight=pango_font_description_get_weight(pfd);                //~v77sI~
    pstyle=pango_font_description_get_style(pfd);                  //~v77sI~
    pango_font_description_free(pfd);                              //~v77sI~
    italic=(pstyle==PANGO_STYLE_ITALIC||pstyle==PANGO_STYLE_OBLIQUE);//~v77sI~
    pfont=gnome_font_find_closest_from_weight_slant(fontname,pweight,italic,dsize);//~v77sI~
    dprintf("weigth slant serach pfont=%p,by font=%s,weight=%d,italic=%d,size=%d\n",pfont,fontname,pweight,italic,(int)dsize);//~v77sI~//~va1MR~
#endif                                                             //~v77sI~
    if (pfont)                                                     //~v77sI~
    	dprintf("new prtfont for %s,fullname=%s,name=%s,family=%s,species=%s,ps=%s,size=%d\n",//~v77sI~
    			Pfontname,                                         //~v77sI~
    			gnome_font_get_full_name(pfont),                   //~v77sI~
    			gnome_font_get_name(pfont),                        //~v77sI~
    			gnome_font_get_family_name(pfont),                 //~v77sI~
    			gnome_font_get_species_name(pfont),                //~v77sI~
    			gnome_font_get_ps_name(pfont),                     //~v77sI~
    			(int)gnome_font_get_size(pfont));                  //~v77sI~
    return pfont;                                                  //~v77sI~
}//uprtfontsrchsub                                                 //~v77sI~
	#endif   //!GTKPRINT                                           //~vam0I~
#endif //!NOGOMEPRINT                                              //~vam0I~
//===============================================================================//~vXXEI~
//get font for printer                                             //~vXXEI~
//outfontname :se if changed from input                            //~v75XI~
//===============================================================================//~vXXEI~
//GnomeFont *uprtcreatefont(char *Pfontname,int *Ppfontw,int *Ppfonth)//~v75XR~
#ifndef NOPRINT                                                    //~vam0R~
	#ifdef GTKPRINT                                                //~vam0I~
//========================================================================
//GnomeFont *uprtcreatefont(char *Pfontname,int *Ppfontw,int *Ppfonth,char *Poutfontname)//~vam0R~
PangoFontMetrics *uprtcreatefontGtkPrint(char *Pfontname,int *Ppfontw,int *Ppfonth)//~vam0I~
{                                                                  //~v003I~
//	int oldh,oldw;                                                 //~vam0R~
    int monospace;                                                 //~vam0R~
    PangoFontMetrics *ppfm;                                        //~vam0R~
//************************************                             //~v003I~
    UTRACEP("uprtcreatefontGtkPrint\n");                           //~vam0R~
//	oldh=Mcellh;                                                   //~vam0R~
//	oldw=Mcellw;                                                   //~vam0R~
//	ugetfontmetrics(Gfontdata[0].FDfontdesc,&Mfontwidth,&Mfontheight,&Mmonospace);//~vam0I~
	if (Mhcopysw)                                                  //~vam0I~
    	ppfm=ugetfontmetrics(Gfontdata[0].FDfontdesc,Ppfontw,Ppfonth,&monospace);//~vam0I~
    else                                                           //~vam0I~
    	ppfm=ugetfontmetrics(Gfontdata[1].FDfontdesc,Ppfontw,Ppfonth,&monospace);//~vam0R~
//    if (Mcellh0)                                                   //~vX03M~//~vam0R~
//        Mcellh=Mcellh0;                                            //~vX03M~//~vam0R~
//    else                                                           //~vX03M~//~vam0R~
//        Mcellh=Mfontheight;                                        //~vX03M~//~vam0R~
//    if (Mcellw0)                                                   //~vX03M~//~vam0R~
//        Mcellw=Mcellw0;                                            //~vX03M~//~vam0R~
//    else                                                           //~vX03M~//~vam0R~
//        Mcellw=Mfontwidth;                                         //~vX03M~//~vam0R~
//    if (Mfontheight<Mcellh-DEF_TEXTCSR_HEIGHT)                     //~vXXEI~//~vam0R~
//    {                                                              //~vXXEI~//~vam0R~
//        Mfontoffsy=(Mcellh-DEF_TEXTCSR_HEIGHT-Mfontheight);        //~vXXEI~//~vam0R~
//    }                                                              //~vXXEI~//~vam0R~
//    else                                                           //~vXXEI~//~vam0R~
//        Mfontoffsy=0;                                              //~vXXEI~//~vam0R~
//    if (Mfontwidth<Mcellw)                                         //~vXXEI~//~vam0R~
//        Mfontoffsx=(Mcellw-Mfontwidth)/2;                          //~vXXER~//~vam0R~
//    else                                                           //~vXXEI~//~vam0R~
//        Mfontoffsx=0;                                              //~vXXEI~//~vam0R~
//setup for monospace                                              //~vX03I~
//    dprintf("create font name=%s,w=%d,h=%d,offsx=%d,offsy=%d\n",Gfontdata[1].FDfontname,Mfontwidth,Mfontheight,Mfontoffsx,Mfontoffsy);//~vX03R~//~vam0R~
//  pango_layout_set_font_description(Gplayout,Gfontdata[0].FDfontdesc);//~vX03R~//~vam0R~
    pango_layout_set_font_description(GplayoutGtkPrint,Gfontdata[1].FDfontdesc);//~vam0I~
    UTRACEP("uprtcreatefont pango_layout_set_font_description GplayoutGtkPrint=%p,fontdesc[1]=%p\n",GplayoutGtkPrint,Gfontdata[1].FDfontdesc);//~vam0R~
//    dprintf("create font old w=%d,h=%d new w=%d,h=%d,desc=%p\n",oldw,oldh,Mcellw,Mcellh,Gfontdata[0].FDfontdesc);//~v73tR~//~vam0R~
//  if (oldh!=Mcellh||oldw!=Mcellw)	//col/row may chnged           //~v69UI~//~vam0R~
//  	usetresizehint(Mcellw,Mcellh,Mscrcmaxcol,Mscrcmaxrow);     //~v69VR~//~vam0R~
//  xxe_setsynfontface();                                          //~v780I~//~vam0R~
//  return 0;                                                      //~v003I~//~vam0R~
    dprintf("uprtcreatefont exit\n");                              //~vam0I~
    return ppfm;                                                   //~vam0I~
}//uprtcreatefontGtkPrint                                          //~vam0R~
	#else    //!GTKPRINT                                           //~vam0I~
//===============================================================================
GnomeFont *uprtcreatefont(char *Pfontname,int *Ppfontw,int *Ppfonth,char *Poutfontname)//~v75XI~
{                                                                  //~vXXEI~
	GnomeFont *pfont;                                              //~vXXEI~
//  char fontname[256],*pc,*pc2,*pfontname;                        //~v77sR~
    char *pfontname;                                               //~v77sI~
    int swnopopuperr;                                              //~va6XR~
//  int len1,len2;                                                 //~v77sR~
//************************************                             //~vXXEI~
	if (Poutfontname)                                              //~v75XI~
    	*Poutfontname=0;	//clear                                //~v75XI~
	pfontname=Pfontname;                                           //~vXXEI~
    swnopopuperr=!strcmp(Mprtfontstyle,Mfontstyle);//same as screen,set when *WXEINIprtfontstyle=0//~va6XR~
   	 dprintf("uprtcreatefont=== %s\n",pfontname);                  //~v75XR~
    pfont=uprtfontsrchsub(pfontname);                              //~v77sI~
 if (!pfont)                                                       //~v77sI~
	pfont=gnome_font_find_from_full_name(pfontname);               //~vXXER~
 if (pfont)                                                        //~vX03I~
    dprintf("font=%p for %s,name=%s,family=%s,species=%s,ps=%s\n",pfont,pfontname,//~vX03R~
    	gnome_font_get_name(pfont),                                //~vXXEI~
    	gnome_font_get_family_name(pfont),                         //~vXXEI~
    	gnome_font_get_species_name(pfont),                        //~vXXEI~
    	gnome_font_get_ps_name(pfont));                            //~vXXEI~
#ifdef AAA                                                         //~v77sR~
    uprtsrchfamily(pfontname);                                     //~v77sI~
#endif                                                             //~v77sI~
    if (!pfont) //not found                                        //~vXXEI~
    {                                                              //~vXXEI~
//Regular missing case                                             //~vXXEI~
//      len1=strlen(pfontname);                                    //~v77sR~
//    	for (pc=pfontname+len1-1;pc>pfontname;pc--)                //~v77sR~
//        	if (*pc==' ')                                          //~v77sR~
//            	break;                                             //~v77sR~
//      len2=(ULONG)pc-(ULONG)pfontname+1;                         //~v77sR~
//      memcpy(fontname,pfontname,(UINT)len2);                     //~v77sR~
//      sprintf(fontname+len2,"Regular %s",pc+1);                  //~v77sR~
//      pfontname=fontname;                                        //~v77sR~
//  	pfont=gnome_font_find_from_full_name(pfontname);           //~v77sR~
// 		dprintf("search by adding regular font=%p for %s\n",pfont,pfontname);//~v77sR~
        if (!pfont)                                                //~vXXEI~
        {                                                          //~vXXEI~
			pfont=gnome_font_find_closest_from_full_name(Pfontname);//~vXXEI~
	    	if (!pfont)                                            //~vXXEI~
    		{                                                      //~vXXEI~
    			uerrmsgbox("Font %s not found",0,                  //~vXXEI~
	        			Pfontname);                                //~vXXEI~
    	    	return 0;                                          //~vXXEI~
    		}                                                      //~vXXEI~
    		dprintf("new prtfont for %s,fullname=%s,name=%s,family=%s,species=%s,ps=%s,size=%d\n",//~v77sR~
    			pfontname,                                         //~v77sR~
    			gnome_font_get_full_name(pfont),                   //~v77sR~
    			gnome_font_get_name(pfont),                        //~v77sR~
    			gnome_font_get_family_name(pfont),                 //~v77sR~
    			gnome_font_get_species_name(pfont),                //~v77sR~
    			gnome_font_get_ps_name(pfont),                     //~v77sR~
    			(int)gnome_font_get_size(pfont));                  //~v77sR~
//		    pfontname=(char*)gnome_font_get_name(pfont);           //~v77sR~
		    pfontname=(char*)gnome_font_get_full_name(pfont);      //~v77sI~
          if (swnopopuperr)                                        //~va6XR~
    		printf("Information:Font \"%s\" not found,closest Font \"%s\" was initialy selected.",0,//~va6XM~//~vamtR~
            			Pfontname,pfontname);                      //~va6XM~
          else                                                     //~va6XM~
    		uerrmsgbox("Font \"%s\" not found,closest Font \"%s\" will be selected",0,//~vXXER~
            			Pfontname,pfontname);                      //~vXXEI~
        }                                                          //~vXXEI~
		if (Poutfontname)                                          //~v75XI~
        {                                                          //~v75XI~
   		 	dprintf("outfontname=%s\n",pfontname);                 //~v75XR~
    		strcpy(Poutfontname,pfontname);                        //~v75XI~
        }                                                          //~v75XI~
    }                                                              //~vXXEI~
	ugetprtfontmetrics(pfont,Ppfontw,Ppfonth);                     //~vXXER~
    if (!*Ppfontw||!*Ppfonth)                                      //~vXXEI~
    {                                                              //~vXXEI~
    	uerrmsgbox("Font %s has size 0",0,                         //~vXXER~
        			pfontname);                                    //~vXXER~
        return 0;                                                  //~vXXEI~
    }                                                              //~vXXEI~
    return pfont;                                                  //~vXXEI~
}//uprtcreatefont                                                  //~vXXEI~
	#endif   //!GTKPRINT                                           //~vam0I~
#endif //!NOGOMEPRINT                                              //~vam0I~
//***************************************************************************//~vXXEI~
//* get printer font metrics                                       //~vXXEI~
//***************************************************************************//~vXXEI~
#ifndef NOPRINT                                                    //~vam0R~
	#ifdef GTKPRINT                                                //~vam0I~
	#else    //!GTKPRINT                                           //~vam0I~
void ugetprtfontmetrics(GnomeFont *Ppgfont,int *Ppwidth,int *Ppheight)//~vXXEI~
{                                                                  //~vXXEI~
	gdouble fsz;                                                   //~vXXEI~
//*******************************                                  //~vXXEI~
    fsz=gnome_font_get_size(Ppgfont);                              //~vXXEI~
    *Ppheight=(int)fsz;                                            //~vXXEI~
//  *Ppwidth=(int)(fsz/2);                                         //~vamhR~
    *Ppwidth=(int)((fsz+1.0)/2);                                   //~vamhR~
    UTRACEP("ugetprtfontmetrics font size=%lf,hh=%d,ww=%d\n",fsz,*Ppheight,*Ppwidth);//~vamhR~
    return;                                                        //~vXXEI~
}//ugetprtfontmetrics                                              //~vXXEI~
	#endif   //!GTKPRINT                                           //~vam0I~
#endif //!NOGOMEPRINT                                              //~vam0I~
//***************************************************************************//~vX03I~
//* dbcschk                                                        //~vX03I~
//***************************************************************************//~vX03I~
char *ugetdbcschktbl(char *Pdata,int Plen)                         //~vX03I~
{                                                                  //~vX03I~
static char *Spdbcs=0;                                             //~vX03I~
static int  Smaxlinelen=0;                                         //~vX03I~
//*******************************                                  //~vX03I~
    if (Plen>Smaxlinelen)                                          //~vX03I~
    {                                                              //~vX03I~
        if (Spdbcs)                                                //~vX03I~
            umemfree(Spdbcs);                                      //~vX03I~
        Spdbcs=umemalloc(Plen);                                    //~vX03I~
        Smaxlinelen=Plen;                                          //~vX03I~
    }                                                              //~vX03I~
    usetdbcstbl(USDT_CODE_DEFAULT,Pdata,Spdbcs,Plen);              //~vX03I~
    UTRACED("csub2:ugetdbcschktbl",Spdbcs,Plen);                   //~vamtI~
    return Spdbcs;                                                 //~vX03I~
}//ugetdbcschktbl                                                  //~vX03I~
//***************************************************************************//~va1DI~
//* unicode print width                                            //~va1DI~
//***************************************************************************//~va1DI~
int uprtwcwidth(int Popt,gunichar Pucs,int Pdbcssz)                //~va1DR~
{                                                                  //~va1DI~
	int width;                                                     //~va1DI~
//******************                                               //~va1DI~
	width=utfwcwidth(0,(ULONG)Pucs,0/*&flag*/);                    //~va1DI~
//	width=wcwidth(Pucs);                                           //~va1DR~
    width=max(1,width);                                            //~va1DI~
UTRACEP("uprtwcwidth ucs=%x,width=%d\n ",Pucs,width);              //~va1DI~
    return width;                                                  //~va1DI~
}                                                                  //~va1DI~
//***************************************************************************//~va1DI~
//* printer text font size limit of sbcs spacing                   //~va1DI~
//***************************************************************************//~va1DI~
#ifndef NOPRINT                                                    //~vam0R~
	#ifdef GTKPRINT
//==========================================================================//~vam0I~
//gdouble uprtgetsbcswidthGtk()                                    //~vam0R~
//{                                                                  //~va1DI~//~vam0R~
//#define SAMPLE_CHAR  'P'                                           //~va1DI~//~vam0R~
//#define WIDTH_ALLOWANCE 1.2                                        //~va1DI~//~vam0R~
////    gunichar ucs=SAMPLE_CHAR;                                      //~va1DI~//~vam0R~
////    gint glyph;                                                    //~va1DI~//~vam0R~
////    gdouble xwidth,xsbcswidth;                                     //~va1DI~//~vam0R~
//////*************                                                    //~va1DI~//~vam0R~
////    glyph=gnome_font_lookup_default(Ppfont,ucs);                   //~va1DI~//~vam0R~
////    xwidth=gnome_font_get_glyph_width(Ppfont,glyph);               //~va1DR~//~vam0R~
////    xsbcswidth=xwidth*WIDTH_ALLOWANCE;                             //~va1DI~//~vam0R~
//    PangoFontDescription *pfdesc;                                //~vam0R~
//    PangoFontMetrics *pfm;                                       //~vam0R~
//    gdouble xsbcswidth;                                          //~vam0R~
////*************                                                  //~vam0R~
//    pfdesc=Gfontdata[1].FDfontdesc;                              //~vam0R~
//    dprintf("ugetfontmetricsGtk desc=%p\n",pfdesc);              //~vam0R~
//    pfm=pango_context_get_metrics(Gppangocontext,pfdesc,Gppangolang);//~vam0R~
//    xsbcswidth=pango_font_metrics_get_approximate_char_width(pfm);//~vam0R~
//    xsbcswidth*=WIDTH_ALLOWANCE;                                 //~vam0R~
//UTRACEP("uprtgetsbcswidthGtk retwidth=%lf\n",xsbcswidth);//~va1DI~//~vam0R~
//    return xsbcswidth;                                             //~va1DI~//~vam0R~
//#undef WIDTH_ALLOWANCE                                           //~vam0R~
//}//uprtgetsbcswidthGtk                                                //~va1DI~//~vam0R~
	#else    //!GTKPRINT
//==========================================================================//~vam0I~
gdouble uprtgetsbcswidth(int Pposx,GnomeFont *Ppfont)              //~va1DI~
{                                                                  //~va1DI~
#define SAMPLE_CHAR  'P'                                           //~va1DI~
#define WIDTH_ALLOWANCE 1.2                                        //~va1DI~
    gunichar ucs=SAMPLE_CHAR;                                      //~va1DI~
    gint glyph;                                                    //~va1DI~
    gdouble xwidth,xsbcswidth;                                     //~va1DI~
//*************                                                    //~va1DI~
    glyph=gnome_font_lookup_default(Ppfont,ucs);                   //~va1DI~
    xwidth=gnome_font_get_glyph_width(Ppfont,glyph);               //~va1DR~
    xsbcswidth=xwidth*WIDTH_ALLOWANCE;                             //~va1DI~
UTRACEP("uprtgetsbcswidth ucs=%02x glyphwidth=%lf,retwidth=%lf\n",ucs,xwidth,xsbcswidth);//~va1DI~
    return xsbcswidth;                                             //~va1DI~
}//uprtgetsbcswidth                                                //~va1DI~
	#endif   //!GTKPRINT
#endif //!NOGOMEPRINT                                              //~vam0I~
#ifndef NOPRINT                                                    //~vap1I~
//***************************************************************************//~vXXEI~
//* printer text write                                             //~vXXEI~
//*  for locale code                                               //~va20I~
//***************************************************************************//~vXXEI~
void                                                               //~vamsI~
uprttextout_NoLigature(int Pposx,int Pposy,char *Pdata,int Plen)   //~vamsI~
{                                                                  //~vamsI~
	UTRACED("uprttextout_NoLigature",Pdata,Plen);                  //~vamsR~
	Snoligature=1;                                                 //~vamsR~
	uprttextout(Pposx,Pposy,Pdata,Plen);                           //~vamsI~
	Snoligature=0;                                                 //~vamsI~
}//uprttextout_NoLigature                                          //~vamsI~
#endif //!NOPRINT                                                  //~vap1I~
#ifndef NOPRINT                                                    //~vam0R~
	#ifdef GTKPRINT                                                //~vam0I~
//=========================================================================//~vam0I~
void uprttextout(int Pposx,int Pposy,char *Pdata,int Plen)         //~vXXER~
{                                                                  //~vXXEI~
//    GnomeGlyphList *pgl;                                           //~vXXEI~//~vam0R~
//    GnomeFont *pfont;                                              //~vXXEI~//~vam0R~
    cairo_t    *pcairocontext;                                     //~vam0I~
//    int print_color =DEFAULT_PRINTCOLOR;                           //~vXXEI~//~vam0R~
    gdouble yy,xx,dx;                                              //~vXXER~
    gchar *putf80;                                                 //~vXXER~
    char *putf8,*pc,*putf8next,*pdbcs;                             //~vX03R~
    int /*readlen,*/writelen,ii,utf8len;                           //~v69sR~
    gunichar ch;                                                   //~vXXER~
//    gint glyph;                                                    //~vXXEI~//~vam0R~
	int utfrc;                                                     //~v69VI~
#ifdef UTF8SUPPH                                                   //~va1cR~
    int dbcssz;                                                    //~va1cR~
    char *pdbcse;                                                  //~va1cR~
    int opt/*,widesw*/;                                                //~va1DR~//~vam0R~
//  gdouble xsbcswidth,glyphwidth,xcellwidth,xoffs;                //~va1DR~//~vam0R~
#endif                                                             //~va1cR~
//*******************************                                  //~vXXEI~
	if (!Plen)                                                     //~vXXEI~
    	return;                                                    //~vXXEI~
UTRACED("uprttextout input data",Pdata,Plen);                         //~va1cR~//~vam0R~
//  utfrc=csublocale2utf8(0/*locale encoding*/,Pdata,Plen,0,&putf80,&writelen);//~v79zI~//~vamqR~
    opt=CSL2UO_NULLALT;//0x08    //rep null by '.' for gtkprint    //~vamqI~
    utfrc=csublocale2utf8(opt,Pdata,Plen,0,&putf80,&writelen);     //~vamqI~
    if (utfrc>1)                                                   //~v69VR~
    	return;                                                    //~vXXEI~
UTRACED("uprttext utf8  data",putf80,writelen);                    //~va1cR~
UTRACEP("preview mode=%d,ww=%d,monospace=%d\n",Mpreviewmode,Mwwscrprt,Mmonospacepreviewfile);//~va1DR~
	utf8len=g_utf8_strlen (putf80,writelen);                       //~vXXEI~
//dprintf("uprttextout utf8len=%d\n",utf8len);                      //~vXXER~//~vamtR~
    if (Mpreviewmode)                                              //~vXXEI~
    {                                                              //~vXXEI~
        xx=Pposx*Mpreviewscalex+Mprevieworgx;                      //~vXXEI~
        yy=Pposy*Mpreviewscaley+Mprevieworgy;                      //~vXXEI~
//dprintf("uprttextout utf8len=%d,xx=%lf,yy=%lf\n",utf8len,xx,yy);  //~vXXER~//~vamtR~
#ifdef UTF8SUPPH                                                   //~va1DI~
		if (Mwwscrprt)   //print dbcs padding                      //~va1DI~
        {                                                          //~va1DI~
#else                                                              //~va1DI~
#endif                                                             //~va1DI~
            pango_layout_set_text(Gplayoutpreview,putf80,writelen);//~vXXER~
            pango_layout_set_attributes(Gplayoutpreview,Gppangoattrlist);//scaling//~vXXEI~
			if (!(Mmonospacepreviewfile==1 && Mdrawcellw==Mpfontszw))//~vX03R~
            {                                                      //~vX03I~
//dbcschk for monospcing                                           //~vX03I~
                pdbcs=ugetdbcschktbl(Pdata,Plen);                  //~vX03I~
                opt=USMSO_WWSCRPRT;                                //~va1DR~
      			usetmonospace(opt,Gplayoutpreview,Pdata,pdbcs,Plen,(int)(Mdrawcellw*Mpreviewscalex));//~va1DI~
            }                                                      //~vX03I~
            gdk_draw_layout(Gppixmappreview,Gpgcpreview,xx,yy,Gplayoutpreview);//~vXXEI~
#ifdef UTF8SUPPH                                                   //~va1DI~
        }                                                          //~vXXEI~
        else                                                       //~vXXEI~
        {                                                          //~vXXEI~
		    pdbcs=ugetdbcschktbl(Pdata,Plen);                      //~va1DI~
        	pdbcse=pdbcs+Plen;                                     //~va1DI~
    		dx=Mdrawcellw*Mpreviewscalex;                          //~vXXEI~
            for (ii=0,putf8=(char*)putf80,pc=Pdata;ii<utf8len;ii++,pc++,xx+=dx)//~vXXER~
            {                                                      //~vXXER~
                putf8next=g_utf8_next_char(putf8);                 //~vXXER~
                pango_layout_set_text(Gplayoutpreview,putf8,(ULONG)putf8next-(ULONG)putf8);//~vXXER~
                pango_layout_set_attributes(Gplayoutpreview,Gppangoattrlist);//~vXXER~
                gdk_draw_layout(Gppixmappreview,Gpgcpreview,xx,yy,Gplayoutpreview);//~vXXER~
UTRACED("preview dbcs ",pdbcs,1);                                  //~va1DI~
//*for locale code                                                 //~va20I~
		        if (*pdbcs==UDBCSCHK_DBCS1ST)  //require  2byte write for DBCS//~va1DI~
                {                                                  //~vXXER~
        		    ch=g_utf8_get_char(putf8);                     //~va1DI~
                    dbcssz=XESUB_DBCSSPLITCTR(pdbcs,(int)((ULONG)pdbcse-(ULONG)pdbcs),0);//~va1DM~
UTRACEP("preview ucs=%x,dbcssz=%d\n",ch,dbcssz);                   //~va1DR~
UTRACED("preview pc ",pc,dbcssz);                                  //~va1DI~
                    pc+=(dbcssz-1);                                //~va1DI~
                    pdbcs+=dbcssz;                                 //~va1DI~
                    xx+=dx*(uprtwcwidth(0,ch,dbcssz)-1);           //~va1DI~
                }                                                  //~vXXER~
                else                                               //~va1DI~
                    pdbcs++;                                       //~va1DI~
                putf8=putf8next;                                   //~vXXER~
            }                                                      //~vXXER~
        }                                                          //~vXXEI~
#endif    //UTF8SUPPH                                              //~va1DR~
//dprintf("prttext last=(%d,%d)-->(%lf,%lf)\n",Pposx,Pposy,xx,yy); //~vX03R~
    }                                                              //~vXXEI~
    else                                                           //~vXXEI~
    {                                                              //~vXXEI~
//      if (MprintLigature)                                          //~vam7I~//~vamsR~
        if (MprintLigature && !Snoligature)                        //~vamsI~
      {                                                            //~vam7I~
		  pcairocontext=gtk_print_context_get_cairo_context(Gpgtkprtctxt);//~vam7I~
          xx=(gdouble)Pposx;//(gdouble)Mprtrect.left;              //~vam7I~
          yy=(gdouble)(Pposy);//layout top-left is current cairo pos//~vam7I~
	      UTRACEP("uprttextout ligature Pposy=%d,cellh=%d,ascent=%d,yy=%lf\n",Pposy,Mdrawcellh,Mprtfontascendant,yy);//~vam7I~
          pango_layout_set_text(GplayoutGtkPrint,putf80,writelen); //~vam7R~
          pango_layout_set_attributes(GplayoutGtkPrint,GppangoattrlistGtkPrint);//~vam7I~
		  cairo_move_to(pcairocontext,xx,yy);                      //~vam7I~
          csub_setcolorGtk(pcairocontext);                         //~vam7I~
		  UTRACEP("uprttextout cairo move to (%lf,%lf)\n",xx,yy);  //~vam7I~
          pango_cairo_show_layout(pcairocontext,GplayoutGtkPrint); //~vam7I~
      }                                                            //~vam7I~
      else                                                         //~vam7I~
      {                                                            //~vam7I~
          pdbcs=ugetdbcschktbl(Pdata,Plen);                          //~vX03I~
          pdbcse=pdbcs+Plen;                                         //~va1cR~
          dx=Mdrawcellw;                                             //~vXXEI~
          xx=(gdouble)Pposx;//(gdouble)Mprtrect.left;                //~vXXEI~
//        yy=(gdouble)(-Pposy-Mprtfontascendant);//(Mprtrect.top-Pposy);//font baseline pos from origin(set at vieportfile)//~vXXEI~//~vam0R~
          yy=(gdouble)(Pposy);//layout top-left is current cairo pos//~vam0R~
	      UTRACEP("uprttextout Pposy=%d,cellh=%d,ascent=%d,yy=%lf\n",Pposy,Mdrawcellh,Mprtfontascendant,yy);//~vam0I~//~vam7R~
//        pfont=Mpprtfont;                                           //~vXXEI~//~vam0R~
//        xsbcswidth=uprtgetsbcswidth(0,pfont);                      //~va1DI~//~vam0R~
////dprintf("font=%p\n",pfont);                                       //~vXXER~//~vam0R~//~vamtR~
//        pgl=gnome_glyphlist_from_text_dumb(pfont,print_color,0.0,0.0,"");//kerning=letterspace=0//~vXXER~//~vam0R~
//            gnome_glyphlist_advance (pgl,FALSE);//move pen by cellszw//~vXXER~//~vam0R~
//        for (ii=0,putf8=(char*)putf80,pc=Pdata;ii<utf8len;ii++,pc++)//~vXXER~//~vam0R~
//        {                                                          //~vXXER~//~vam0R~
//            putf8next=g_utf8_next_char(putf8);                     //~vXXER~//~vam0R~
//            ch=g_utf8_get_char(putf8);                             //~vXXER~//~vam0R~
//UTRACEP("uprttext utf8 charii=%d,ch=%x,xx=%lf,*pc=%02x\n ",ii,ch,xx,*pc);//~va1cR~//~vam0R~
//            glyph=gnome_font_lookup_default(pfont,ch);             //~vX03R~//~vam0R~
//UTRACEP("uprttext utf8 pgl=%p,font=%p,griph=%p\n",pgl,pfont,glyph);//~va1cR~//~vam0R~
//#ifdef UTF8SUPPH                                                   //~va1DI~//~vam0R~
//            glyphwidth=gnome_font_get_glyph_width(pfont,glyph);    //~va1DR~//~vam0R~
//            widesw=(glyphwidth>xsbcswidth);                        //~va1DI~//~vam0R~
//            if (!glyphwidth && *pdbcs==UDBCSCHK_DBCS1ST)  //require  2byte write for DBCS//~va4aR~//~vam0R~
//                widesw=1;       //sometime gnome_font_get_glyph_width returns sbcs width for DBCS//~va4aI~//~vam0R~
//            xcellwidth=dx+dx*widesw;                               //~va1DI~//~vam0R~
//            xoffs=(glyphwidth && glyphwidth<xcellwidth ? (xcellwidth-glyphwidth)/2:0);//~va1DR~//~vam0R~
//            UTRACEP("ucs=%02x glyphwidth=%lf,sbcswidth=%lf,cellwidth=%lf,xoffs=%lf\n",ch,glyphwidth,xsbcswidth,xcellwidth,xoffs);//~va1DR~//~vam0R~
//#endif                                                             //~va1DI~//~vam0R~
//#ifdef UTF8SUPPH                                                   //~va1DI~//~vam0R~
//                gnome_glyphlist_moveto(pgl,xx+xoffs,yy); //move to center of cell//~va1DI~//~vam0R~
//#else                                                              //~va1DR~//~vam0R~
//                gnome_glyphlist_moveto(pgl,xx,yy);                 //~vXXER~//~vam0R~
//#endif                                                             //~va1DI~//~vam0R~
//                xx+=dx;                                            //~vXXER~//~vam0R~
////*for locale code                                                 //~va20I~//~vam0R~
//                if (*pdbcs==UDBCSCHK_DBCS1ST)  //require  2byte write for DBCS//~vX03I~//~vam0R~
//                {                                                  //~vX03I~//~vam0R~
//#ifdef UTF8SUPPH                                                   //~va1cR~//~vam0R~
//                    dbcssz=XESUB_DBCSSPLITCTR(pdbcs,(int)((ULONG)pdbcse-(ULONG)pdbcs),0);//~va1cR~//~vam0R~
//                  if (Mwwscrprt)    //wysisig option on page dialog//~va1DI~//~vam0R~
//                    xx+=dx*(dbcssz-1);                             //~va1cR~//~vam0R~
//                  else                                             //~va1DI~//~vam0R~
//                    xx+=dx*widesw;                                 //~va1DR~//~vam0R~
//                    pdbcs+=dbcssz;                                 //~va1cR~//~vam0R~
//                    pc+=dbcssz-1;                                  //~va1DI~//~vam0R~
//UTRACEP("uprttext utf8 dbcssz=%d\n ",dbcssz);                      //~va1cR~//~vam0R~
//#else                                                              //~va1cR~//~vam0R~
//                    xx+=dx;                                        //~vXXER~//~vam0R~
//                    pdbcs+=2;                                      //~vX03I~//~vam0R~
//#endif                                                             //~va1cR~//~vam0R~
//                }                                                  //~vX03I~//~vam0R~
//                else                                               //~vX03I~//~vam0R~
//                    pdbcs++;                                       //~vX03I~//~vam0R~
//            gnome_glyphlist_glyph(pgl,glyph);                      //~vX03R~//~vam0R~
//            putf8=putf8next;                                       //~vXXEI~//~vam0R~
//        }                                                          //~vXXER~//~vam0R~
//        gnome_print_moveto(Gpprtctxt,0.0,0.0);                     //~vXXER~//~vam0R~
//        gnome_print_glyphlist(Gpprtctxt,pgl);                      //~vXXER~//~vam0R~
//        gnome_glyphlist_unref(pgl);                                //~vXXER~//~vam0R~
		pcairocontext=gtk_print_context_get_cairo_context(Gpgtkprtctxt);//~vam0R~
//dprintf("uprttextout utf8len=%d,xx=%lf,yy=%lf\n",utf8len,xx,yy);  //~vam0I~//~vamtR~
            for (ii=0,putf8=(char*)putf80,pc=Pdata;ii<utf8len;ii++,pc++,xx+=dx)//~vam0I~
            {                                                      //~vam0I~
                putf8next=g_utf8_next_char(putf8);                 //~vam0I~
//              pango_layout_set_text(Gplayoutpreview,putf8,(ULONG)putf8next-(ULONG)putf8);//~vam0I~
                pango_layout_set_text(GplayoutGtkPrint,putf8,(ULONG)putf8next-(ULONG)putf8);//~vam0I~
				UTRACED("csub2 uprttextout set text",putf8,PTRDIFF(putf8next,putf8));//~vam0R~
//              pango_layout_set_attributes(Gplayoutpreview,Gppangoattrlist);//~vam0I~
                pango_layout_set_attributes(GplayoutGtkPrint,GppangoattrlistGtkPrint);//~vam0I~
//              gdk_draw_layout(Gppixmappreview,Gpgcpreview,xx,yy,Gplayoutpreview);//~vam0I~
				cairo_move_to(pcairocontext,xx,yy);                //~vam0R~
        		csub_setcolorGtk(pcairocontext);                   //~vam0R~
				UTRACEP("csub2 uprttextout cairo move to (%lf,%lf)\n",xx,yy);//~vam0I~
            	pango_cairo_show_layout(pcairocontext,GplayoutGtkPrint);//~vam0I~
//*for locale code                                                 //~vam0I~
		        if (*pdbcs==UDBCSCHK_DBCS1ST)  //require  2byte write for DBCS//~vam0I~
                {                                                  //~vam0I~
        		    ch=g_utf8_get_char(putf8);                     //~vam0I~
                    dbcssz=XESUB_DBCSSPLITCTR(pdbcs,(int)((ULONG)pdbcse-(ULONG)pdbcs),0);//~vam0I~
UTRACEP("preview ucs=%x,dbcssz=%d\n",ch,dbcssz);                   //~vam0I~
UTRACED("preview pc ",pc,dbcssz);                                  //~vam0I~
                    pc+=(dbcssz-1);                                //~vam0I~
                    pdbcs+=dbcssz;                                 //~vam0I~
                    xx+=dx*(uprtwcwidth(0,ch,dbcssz)-1);           //~vam0I~
                }                                                  //~vam0I~
                else                                               //~vam0I~
                    pdbcs++;                                       //~vam0I~
                putf8=putf8next;                                   //~vam0I~
            }                                                      //~vam0I~
//dprintf("prttext last=(%d,%d)-->(%lf,%lf)\n",Pposx,Pposy,xx,yy); //~vam0I~
		}//!ligature                                               //~vam7I~
    }                                                              //~vXXEI~
    return;                                                        //~vXXEI~
}//uprttextout                                                     //~vXXER~
	#else    //!GTKPRINT                                           //~vam0I~
//=========================================================================//~vam7I~
void                                                               //~vam7I~
uprttextout_GnomeLigature(int Pposx,int Pposy,char *Pdata,int Plen)//~vam7R~
{                                                                  //~vam7I~
#ifndef AAA                                                        //~vam7I~
#else                                                              //~vam7I~
	char *pc;                                                      //~vam7I~
#endif                                                             //~vam7I~
    PangoLayout *playout;                                          //~vam7I~
    PangoFontDescription *pfontdesc;                               //~vam7I~
    gdouble yy,xx;                                                 //~vam7I~
//********************************                                 //~vam7I~
    xx=(gdouble)Pposx;//(gdouble)Mprtrect.left;                    //~vam7I~
//  yy=-(gdouble)(Pposy+Mprtfontascendant);//(Mprtrect.top-Pposy);//font baseline pos from origin(set at vieportfile)//~vam7R~
    yy=-(gdouble)(Pposy);//(Mprtrect.top-Pposy);//-baseline in gnome_print_pango_layout//~vam7I~
	UTRACEP("uprttextout_GnomeLigature ligature context=%p,Pposx=%d->%lf,Pposy=%d->%lf,Mpfontascendant=%d\n",Gpprtctxt,Pposx,xx,Pposy,yy,Mprtfontascendant);//~vam7R~
	UTRACED("uprttextout_GnomeLigature utf8data",Pdata,Plen);      //~vam7I~
    gnome_print_setrgbcolor(Gpprtctxt,0.01,0.01,0.01);             //~vam7R~
//  gnome_print_scale(Gpprtctxt,1.0,-1.0);                         //~vam7R~
#ifndef AAA                                                        //~vam7R~
//  gnome_print_scale(Gpprtctxt,0.818,0.818); //var8test           //~var8R~
    pfontdesc=Gfontdata[1].FDfontdesc;                             //~vam7I~
    playout=GplayoutGnomePrint;                                    //~vam7I~
    pango_layout_set_font_description(playout,pfontdesc);          //~vam7I~
    pango_layout_set_text(playout,Pdata,Plen);                     //~vam7R~
    gnome_print_moveto(Gpprtctxt,xx,yy);                           //~vam7R~
    gnome_print_pango_layout(Gpprtctxt,playout);                   //~vam7R~
#else                                                              //~vam7I~
	pc=malloc(Plen+1);                                             //~vam7I~
    UmemcpyZ(pc,Pdata,Plen);                                       //~vam7I~
    gnome_print_moveto(Gpprtctxt,Pposx,Pposy);                     //~vam7R~
    gnome_print_show(Gpprtctxt,pc);                                //~vam7I~
    free(pc);                                                      //~vam7I~
#endif                                                             //~vam7I~
}//uprttextout_GnomeLigature(int Pposx,int Pposy,char *Pdata,int Plen)//~vam7I~
//=========================================================================
void uprttextout(int Pposx,int Pposy,char *Pdata,int Plen)         //~vXXER~
{                                                                  //~vXXEI~
    GnomeGlyphList *pgl;                                           //~vXXEI~
    GnomeFont *pfont;                                              //~vXXEI~
	int print_color =DEFAULT_PRINTCOLOR;                           //~vXXEI~
    gdouble yy,xx,dx;                                              //~vXXER~
    gchar *putf80;                                                 //~vXXER~
    char *putf8,*pc,*putf8next,*pdbcs;                             //~vX03R~
    int /*readlen,*/writelen,ii,utf8len;                           //~v69sR~
//  GError *errpos=NULL;                                           //~v69sR~
    gunichar ch;                                                   //~vXXER~
    gint glyph;                                                    //~vXXEI~
//	ArtPoint adv;                                                  //~va1DR~
	int utfrc;                                                     //~v69VI~
#ifdef UTF8SUPPH                                                   //~va1cR~
    int dbcssz;                                                    //~va1cR~
    char *pdbcse;                                                  //~va1cR~
    int opt,widesw;                                                //~va1DR~
    gdouble xsbcswidth,glyphwidth,xcellwidth,xoffs;                //~va1DR~
#endif                                                             //~va1cR~
//*******************************                                  //~vXXEI~
	if (!Plen)                                                     //~vXXEI~
    	return;                                                    //~vXXEI~
UTRACED("uprttext input data",Pdata,Plen);                         //~va1cR~
//gnome_print_line_stroked(Gpprtctxt,0.0,(gdouble)(-Pposy),(gdouble)(Mdrawcellw*(Mprtcmaxcol+4)),(gdouble)(-Pposy));//~vXXER~
//  xx=(gdouble)(Mprtrect.left);                                   //~vXXER~
//  yy=(gdouble)(Mprtrect.top-Pposy-Mprtfontascendant);            //~vXXER~
//dprintf("uprttextout x=%lf,y=%d->%lf,len=%d,%.*s\n",xx,Pposy,yy,Plen,Plen,Pdata);//~vXXER~//~vamtR~
//  putf80=g_locale_to_utf8(Pdata,Plen,&readlen,&writelen,&errpos);//~v69sR~
//  PRINTGERR("uprttextout-g_locale_to_utf8",errpos);              //~v69sR~
//  putf80=csublocale2utf8(Pdata,Plen,0,&writelen);                //~v69VR~
//  utfrc=csublocale2utf8(Pdata,Plen,0,&putf80,&writelen);         //~v79zR~
    utfrc=csublocale2utf8(0/*locale encoding*/,Pdata,Plen,0,&putf80,&writelen);//~v79zI~
//  if (!putf80)                                                   //~v69VR~
    if (utfrc>1)                                                   //~v69VR~
    	return;                                                    //~vXXEI~
UTRACED("uprttext utf8  data",putf80,writelen);                    //~va1cR~
UTRACEP("preview mode=%d,ww=%d,monospace=%d\n",Mpreviewmode,Mwwscrprt,Mmonospacepreviewfile);//~va1DR~
	utf8len=g_utf8_strlen (putf80,writelen);                       //~vXXEI~
//dprintf("uprttextout utf8len=%d\n",utf8len);                      //~vXXER~//~vamtR~
    if (Mpreviewmode)                                              //~vXXEI~
    {                                                              //~vXXEI~
        xx=Pposx*Mpreviewscalex+Mprevieworgx;                      //~vXXEI~
        yy=Pposy*Mpreviewscaley+Mprevieworgy;                      //~vXXEI~
//dprintf("uprttextout utf8len=%d,xx=%lf,yy=%lf\n",utf8len,xx,yy);  //~vXXER~//~vamtR~
#ifdef UTF8SUPPH                                                   //~va1DI~
		if (Mwwscrprt)   //print dbcs padding                      //~va1DI~
        {                                                          //~va1DI~
#else                                                              //~va1DI~
#ifdef XXX                                                         //~vX03I~
		if (Mmonospacepreviewfile)                                 //~vXXEI~
        {                                                          //~vXXEI~
#endif                                                             //~vX03I~
#endif                                                             //~va1DI~
            pango_layout_set_text(Gplayoutpreview,putf80,writelen);//~vXXER~
            pango_layout_set_attributes(Gplayoutpreview,Gppangoattrlist);//scaling//~vXXEI~
			if (!(Mmonospacepreviewfile==1 && Mdrawcellw==Mpfontszw))//~vX03R~
            {                                                      //~vX03I~
//dbcschk for monospcing                                           //~vX03I~
                pdbcs=ugetdbcschktbl(Pdata,Plen);                  //~vX03I~
//            	 dprintf("preview monospacing cellw=%d,fontw=%d,monospace=%d\n",Mdrawcellw,Mpfontszw,Mmonospacepreviewfile);//~v69VR~
//  			usetmonospace(Gplayoutpreview,pdbcs,Plen,(int)(Mdrawcellw*Mpreviewscalex));//~v79zR~
//    			usetmonospace(Gplayoutpreview,Pdata,pdbcs,Plen,(int)(Mdrawcellw*Mpreviewscalex));//~va1DR~
                opt=USMSO_WWSCRPRT;                                //~va1DR~
      			usetmonospace(opt,Gplayoutpreview,Pdata,pdbcs,Plen,(int)(Mdrawcellw*Mpreviewscalex));//~va1DI~
            }                                                      //~vX03I~
            gdk_draw_layout(Gppixmappreview,Gpgcpreview,xx,yy,Gplayoutpreview);//~vXXEI~
//#ifdef XXX                                                       //~va1DR~
#ifdef UTF8SUPPH                                                   //~va1DI~
        }                                                          //~vXXEI~
        else                                                       //~vXXEI~
        {                                                          //~vXXEI~
		    pdbcs=ugetdbcschktbl(Pdata,Plen);                      //~va1DI~
        	pdbcse=pdbcs+Plen;                                     //~va1DI~
    		dx=Mdrawcellw*Mpreviewscalex;                          //~vXXEI~
            for (ii=0,putf8=(char*)putf80,pc=Pdata;ii<utf8len;ii++,pc++,xx+=dx)//~vXXER~
            {                                                      //~vXXER~
                putf8next=g_utf8_next_char(putf8);                 //~vXXER~
                pango_layout_set_text(Gplayoutpreview,putf8,(ULONG)putf8next-(ULONG)putf8);//~vXXER~
                pango_layout_set_attributes(Gplayoutpreview,Gppangoattrlist);//~vXXER~
                gdk_draw_layout(Gppixmappreview,Gpgcpreview,xx,yy,Gplayoutpreview);//~vXXER~
//#ifndef UTF8SUPPJ                                                //~va1DR~
//        	    if (UDBCSCHK_ISDBCS1ST(*pc))                       //~va1DR~
//#else                                                            //~va1DR~
//                if (SJIS1(*pc))                                  //~va1DR~
//#endif                                                           //~va1DR~
UTRACED("preview dbcs ",pdbcs,1);                                  //~va1DI~
//*for locale code                                                 //~va20I~
		        if (*pdbcs==UDBCSCHK_DBCS1ST)  //require  2byte write for DBCS//~va1DI~
                {                                                  //~vXXER~
        		    ch=g_utf8_get_char(putf8);                     //~va1DI~
                    dbcssz=XESUB_DBCSSPLITCTR(pdbcs,(int)((ULONG)pdbcse-(ULONG)pdbcs),0);//~va1DM~
UTRACEP("preview ucs=%x,dbcssz=%d\n",ch,dbcssz);                   //~va1DR~
UTRACED("preview pc ",pc,dbcssz);                                  //~va1DI~
//                  pc++;                                          //~va1DR~
//                  xx+=dx;                                        //~va1DI~
                    pc+=(dbcssz-1);                                //~va1DI~
                    pdbcs+=dbcssz;                                 //~va1DI~
                    xx+=dx*(uprtwcwidth(0,ch,dbcssz)-1);           //~va1DI~
                }                                                  //~vXXER~
                else                                               //~va1DI~
                    pdbcs++;                                       //~va1DI~
                putf8=putf8next;                                   //~vXXER~
            }                                                      //~vXXER~
        }                                                          //~vXXEI~
#endif    //UTF8SUPPH                                              //~va1DR~
//dprintf("prttext last=(%d,%d)-->(%lf,%lf)\n",Pposx,Pposy,xx,yy); //~vX03R~
    }                                                              //~vXXEI~
    else                                                           //~vXXEI~
    {                                                              //~vXXEI~
      if (MprintLigature)                                          //~vam7M~
      {                                                            //~vam7M~
      	uprttextout_GnomeLigature(Pposx,Pposy,putf80,writelen);   //~vam7I~//~vamjR~
      }                                                            //~vam7M~
      else //!Ligature                                             //~vam7M~
      {                                                            //~vam7M~
        pdbcs=ugetdbcschktbl(Pdata,Plen);                          //~vX03I~
#ifdef UTF8SUPPH                                                   //~va1cR~
        pdbcse=pdbcs+Plen;                                         //~va1cR~
#endif                                                             //~va1cR~
    	dx=Mdrawcellw;                                             //~vXXEI~
    	xx=(gdouble)Pposx;//(gdouble)Mprtrect.left;                //~vXXEI~
	    yy=(gdouble)(-Pposy-Mprtfontascendant);//(Mprtrect.top-Pposy);//font baseline pos from origin(set at vieportfile)//~vXXEI~
	    pfont=Mpprtfont;                                           //~vXXEI~
        xsbcswidth=uprtgetsbcswidth(0,pfont);                      //~va1DI~
//dprintf("font=%p\n",pfont);                                       //~vXXER~//~vamtR~
        pgl=gnome_glyphlist_from_text_dumb(pfont,print_color,0.0,0.0,"");//kerning=letterspace=0//~vXXER~
//      if (Mchkpfontsz)                                           //~vX03R~
            gnome_glyphlist_advance (pgl,FALSE);//move pen by cellszw//~vXXER~
//      else                                                       //~vX03R~
//      {                                                          //~vX03R~
//          gnome_glyphlist_advance (pgl,TRUE);//move pen by font standard advance vector//~vX03R~
//          gnome_glyphlist_moveto(pgl,xx,yy);                     //~vX03R~
//      }                                                          //~vX03R~
        for (ii=0,putf8=(char*)putf80,pc=Pdata;ii<utf8len;ii++,pc++)//~vXXER~
        {                                                          //~vXXER~
        	putf8next=g_utf8_next_char(putf8);                     //~vXXER~
            ch=g_utf8_get_char(putf8);                             //~vXXER~
UTRACEP("uprttext utf8 charii=%d,ch=%x,xx=%lf,*pc=%02x\n ",ii,ch,xx,*pc);//~va1cR~
            glyph=gnome_font_lookup_default(pfont,ch);             //~vX03R~
UTRACEP("uprttext utf8 pgl=%p,font=%p,griph=%p\n",pgl,pfont,glyph);//~va1cR~
#ifdef UTF8SUPPH                                                   //~va1DI~
        	glyphwidth=gnome_font_get_glyph_width(pfont,glyph);    //~va1DR~
            widesw=(glyphwidth>xsbcswidth);                        //~va1DI~
		    if (!glyphwidth && *pdbcs==UDBCSCHK_DBCS1ST)  //require  2byte write for DBCS//~va4aR~
                widesw=1;       //sometime gnome_font_get_glyph_width returns sbcs width for DBCS//~va4aI~
            xcellwidth=dx+dx*widesw;                               //~va1DI~
            xoffs=(glyphwidth && glyphwidth<xcellwidth ? (xcellwidth-glyphwidth)/2:0);//~va1DR~
        	UTRACEP("ucs=%02x glyphwidth=%lf,sbcswidth=%lf,cellwidth=%lf,xoffs=%lf\n",ch,glyphwidth,xsbcswidth,xcellwidth,xoffs);//~va1DR~
#endif                                                             //~va1DI~
//          if (Mchkpfontsz)                                       //~vX03R~
//          {                                                      //~vX03R~
#ifdef UTF8SUPPH                                                   //~va1DI~
                gnome_glyphlist_moveto(pgl,xx+xoffs,yy); //move to center of cell//~va1DI~
#else                                                              //~va1DR~
                gnome_glyphlist_moveto(pgl,xx,yy);                 //~vXXER~
#endif                                                             //~va1DI~
                xx+=dx;                                            //~vXXER~
//*for locale code                                                 //~va20I~
		        if (*pdbcs==UDBCSCHK_DBCS1ST)  //require  2byte write for DBCS//~vX03I~
                {                                                  //~vX03I~
#ifdef UTF8SUPPH                                                   //~va1cR~
                    dbcssz=XESUB_DBCSSPLITCTR(pdbcs,(int)((ULONG)pdbcse-(ULONG)pdbcs),0);//~va1cR~
                  if (Mwwscrprt)    //wysisig option on page dialog//~va1DI~
                    xx+=dx*(dbcssz-1);                             //~va1cR~
                  else                                             //~va1DI~
                  	xx+=dx*widesw;                                 //~va1DR~
                    pdbcs+=dbcssz;                                 //~va1cR~
                    pc+=dbcssz-1;                                  //~va1DI~
UTRACEP("uprttext utf8 dbcssz=%d\n ",dbcssz);                      //~va1cR~
#else                                                              //~va1cR~
                    xx+=dx;                                        //~vXXER~
                    pdbcs+=2;                                      //~vX03I~
#endif                                                             //~va1cR~
                }                                                  //~vX03I~
                else                                               //~vX03I~
                    pdbcs++;                                       //~vX03I~
//          }                                                      //~vX03R~
            gnome_glyphlist_glyph(pgl,glyph);                      //~vX03R~
            putf8=putf8next;                                       //~vXXEI~
        }                                                          //~vXXER~
    //  gnome_print_moveto(Gpprtctxt,xx,yy);                       //~vXXER~
        gnome_print_moveto(Gpprtctxt,0.0,0.0);                     //~vXXER~
        gnome_print_glyphlist(Gpprtctxt,pgl);                      //~vXXER~
        gnome_glyphlist_unref(pgl);                                //~vXXER~
//dprintf("prttext last=(%d,%d)-->(%lf,%lf) dx=%d\n",Pposx,Pposy,xx,yy,Mdrawcellw);//~vX03R~//~vamtR~
      }//!Ligature                                                 //~vam7I~
    }                                                              //~vXXEI~
//if (!utfrc)                                                      //~v79zR~
//  g_free(putf80);                                                //~v79zR~
    return;                                                        //~vXXEI~
}//uprttextout                                                     //~vXXER~
	#endif   //!GTKPRINT                                           //~vam0I~
#endif //!NOGOMEPRINT                                              //~vam0I~
#ifdef UTF8UCS2                                                    //~va20I~
//***************************************************************************////~va20I~
//* print dd fmt text                                              //~va20I~
//* rc :UALLOC_FAILED,4                                            //~va20I~
//***************************************************************************////~va20I~
#ifndef NOPRINT                                                    //~vam0I~
int uprttextoutw(int Popt,int Pxx,int Pyy,char *Pdata,char *Pdbcs,int Plen)//~va20I~
{                                                                  //~va20I~
    int rc,u8len,opt;                                              //~va20R~
    UCHAR *pu8,*pdbcs;                                             //~va20I~
//*******************************                                  //~va20I~
	opt=UTFDD2FO_ERRREP;                                           //~va20R~
    opt|=UTFDD2FO_NULLALT;	//rep null by altch                    //~vamqI~
    rc=xeutfcvdd2f(opt,Pdata,Pdbcs,Plen,&pu8,&u8len,&pdbcs); //dbcstbl is for locale code//~va20R~
    if (rc)                                                        //~va20I~
    	return rc;                                                 //~va20I~
//  csub_repu8null(pu8,u8len,0/*repch,use default*/);              //~vamqI~
    opt=0;                                                         //~va20I~
	rc=uprttextoutwsub(opt,Pxx,Pyy,pu8,pdbcs,u8len,Plen);          //~va20I~
    return rc;                                                     //~va20I~
}//uprttextoutw                                                    //~va20I~
#endif //!NOGOMEPRINT                                              //~vam0I~
//***************************************************************************//~vXXEI~//~va20I~
//* printer text write from utf8 str                                             //~vXXEI~//~va20I~
//* dbcs tbl is old fmt(DBCS1ST/DBCS2ND)                           //~va20I~
//***************************************************************************//~vXXEI~//~va20I~
#ifndef NOPRINT                                                    //~vam0R~
	#ifdef GTKPRINT                                                //~vam0I~
//==========================================================================//~vam0I~
int uprttextoutwsub(int Popt,int Pposx,int Pposy,char *Pdata,char *Pdbcs,int Plen,int Plenlc)         //~vXXER~//~va20R~
{                                                                  //~vXXEI~//~va20I~
//  GnomeGlyphList *pgl;                                           //~vXXEI~//~va20I~//~vam0R~
//  GnomeFont *pfont;                                              //~vXXEI~//~va20I~//~vam0R~
    cairo_t    *pcairocontext;                                     //~vam0I~
//  int print_color =DEFAULT_PRINTCOLOR;                           //~vXXEI~//~va20I~//~vam0R~
    gdouble yy,xx,dx;                                              //~vXXER~//~va20I~
    gchar *putf80;                                                 //~vXXER~//~va20I~
    char *putf8,*putf8next,*pdbcs;                             //~vX03R~//~va20R~
    int writelen,ii,utf8len,dbcsid;                           //~v69sR~//~va20R~
//  gunichar ch;                                                   //~vXXER~//~vam0R~
//  gint glyph;                                                    //~vXXEI~//~va20I~//~vam0R~
//  int widesw;                                                //~va1DR~//~va20R~//~vam0R~
//  int combinesw;                                                 //~va30I~//~vam0R~
//  gdouble xsbcswidth,glyphwidth,xcellwidth,xoffs;                //~va1DR~//~va20I~//~vam0R~
//*******************************                                  //~vXXEI~//~va20I~
	if (!Plen)                                                     //~vXXEI~//~va20I~
    	return 0;                                                  //~vXXEI~//~va20R~
    putf80=Pdata;                                                  //~va20I~
    writelen=Plen;                                                 //~va20I~
UTRACED("uprttextoutwsub utf8 data",Pdata,Plen);                    //~va1cR~//~va20I~//~vamqR~
UTRACEP("uprttextoutwsub preview mode=%d,ww=%d,monospace=%d,posx=%d,posy=%d\n",Mpreviewmode,Mwwscrprt,Mmonospacepreviewfile,Pposx,Pposy);//~va1DR~//~va20I~//~vam0R~//~vamqR~
    utf8len=g_utf8_strlen (putf80,writelen);                       //~vXXEI~//~va20I~//~vamqR~
//  utf8len=csub_utf8mem_strlen(putf80,writelen);                  //~vamqR~
//dprintf("uprttextoutwsub utf8len=%d\n",utf8len);                      //~vXXER~//~va20I~//~vamtR~
    if (Mpreviewmode)                                              //~vXXEI~//~va20I~
    {                                                              //~vXXEI~//~va20I~
        xx=Pposx*Mpreviewscalex+Mprevieworgx;                      //~vXXEI~//~va20I~
        yy=Pposy*Mpreviewscaley+Mprevieworgy;                      //~vXXEI~//~va20I~
//dprintf("uprttextout utf8len=%d,xx=%lf,yy=%lf\n",utf8len,xx,yy);  //~vXXER~//~va20I~//~vamtR~
		    pdbcs=Pdbcs;                                           //~va20I~
    		dx=Mdrawcellw*Mpreviewscalex;                          //~vXXEI~//~va20I~
//no monospace consideration for preview                           //~va20I~
            for (ii=0,putf8=(char*)putf80;ii<utf8len;ii++,xx+=dx)//~vXXER~//~va20I~
            {                                                      //~vXXER~//~va20I~
                putf8next=g_utf8_next_char(putf8);                 //~vXXER~//~va20I~
                pango_layout_set_text(Gplayoutpreview,putf8,(ULONG)putf8next-(ULONG)putf8);//~vXXER~//~va20I~
                pango_layout_set_attributes(Gplayoutpreview,Gppangoattrlist);//~vXXER~//~va20I~
                gdk_draw_layout(Gppixmappreview,Gpgcpreview,xx,yy,Gplayoutpreview);//~vXXER~//~va20I~
UTRACED("preview dbcs ",pdbcs,1);                                  //~va1DI~//~va20I~
                dbcsid=*pdbcs;                                     //~va20I~
//for utf8 file dd2f changed dbcscstbl                             //~va20I~
		        if (dbcsid==UDBCSCHK_DBCS1ST)  //require  2byte write for DBCS//~va1DI~//~va20R~
                {                                                  //~vXXER~//~va20I~
//      		    ch=g_utf8_get_char(putf8);                     //~va1DI~//~vam0R~
                    pdbcs+=2;                                 //~va1DI~//~va20I~
                    xx+=dx;           //~va1DI~                    //~va20I~
                }                                                  //~vXXER~//~va20I~
                else                                               //~va1DI~//~va20I~
                    pdbcs++;                                       //~va1DI~//~va20I~
                putf8=putf8next;                                   //~vXXER~//~va20I~
            }                                                      //~vXXER~//~va20I~
//dprintf("prttext last=(%d,%d)-->(%lf,%lf)\n",Pposx,Pposy,xx,yy); //~vX03R~//~va20I~
    }                                                              //~vXXEI~//~va20I~
    else                                                           //~vXXEI~//~va20I~
    {                                                              //~vXXEI~//~va20I~
      if (MprintLigature)                                          //~vam7I~
      {                                                            //~vam7I~
		  pcairocontext=gtk_print_context_get_cairo_context(Gpgtkprtctxt);//~vam7I~
          xx=(gdouble)Pposx;//(gdouble)Mprtrect.left;              //~vam7I~
          yy=(gdouble)(Pposy);//layout top-left is current cairo pos//~vam7I~
	      UTRACEP("uprttextoutwsub ligature Pposy=%d,cellh=%d,ascent=%d,yy=%lf\n",Pposy,Mdrawcellh,Mprtfontascendant,yy);//~vam7I~
          pango_layout_set_text(GplayoutGtkPrint,putf80,writelen); //~vam7R~
          pango_layout_set_attributes(GplayoutGtkPrint,GppangoattrlistGtkPrint);//~vam7I~
		  cairo_move_to(pcairocontext,xx,yy);                      //~vam7I~
          csub_setcolorGtk(pcairocontext);                         //~vam7I~
		  UTRACEP("uprttextoutwsub cairo move to (%lf,%lf)\n",xx,yy);//~vam7R~
          pango_cairo_show_layout(pcairocontext,GplayoutGtkPrint); //~vam7I~
      }                                                            //~vam7I~
      else                                                         //~vam7I~
      {                                                            //~vam7I~
          dx=Mdrawcellw;                                             //~vXXEI~//~va20I~
          xx=(gdouble)Pposx;//(gdouble)Mprtrect.left;                //~vXXEI~//~va20I~
//        yy=(gdouble)(-Pposy-Mprtfontascendant);//(Mprtrect.top-Pposy);//font baseline pos from origin(set at vieportfile)//~vXXEI~//~va20I~//~vam0R~
          yy=(gdouble)(Pposy);//cairo current pos=layout top-left  //~vam0R~
	      UTRACEP("uprttextoutsub Pposy=%d,cellh=%d,ascent=%d,yy=%lf\n",Pposy,Mdrawcellh,Mprtfontascendant,yy);//~vam0I~
//        pfont=Mpprtfont;                                           //~vXXEI~//~va20I~//~vam0R~
//        xsbcswidth=uprtgetsbcswidth(0,pfont);                      //~va1DI~//~va20I~//~vam0R~
////printf("font=%p\n",pfont);                                       //~vXXER~//~va20I~//~vam0R~
//        pgl=gnome_glyphlist_from_text_dumb(pfont,print_color,0.0,0.0,"");//kerning=letterspace=0//~vXXER~//~va20I~//~vam0R~
//            gnome_glyphlist_advance (pgl,FALSE);//move pen by cellszw//~vXXER~//~va20I~//~vam0R~
//        for (ii=0,putf8=(char*)putf80;ii<utf8len;ii++)//~vXXER~    //~va20I~//~vam0R~
//        {                                                          //~vXXER~//~va20I~//~vam0R~
//            putf8next=g_utf8_next_char(putf8);                     //~vXXER~//~va20I~//~vam0R~
//            ch=g_utf8_get_char(putf8);                             //~vXXER~//~va20I~//~vam0R~
//UTRACEP("uprttext utf8 Mwwscrprt=%d,charii=%d,ch=%x,xx=%lf\n ",Mwwscrprt,ii,ch,xx);//~va30I~//~vam0R~
//            glyph=gnome_font_lookup_default(pfont,ch);             //~vX03R~//~va20I~//~vam0R~
//            glyphwidth=gnome_font_get_glyph_width(pfont,glyph);    //~va1DR~//~va20I~//~vam0R~
//            combinesw=0;                                           //~va30I~//~vam0R~
//            if (UTF_COMBINEMODE()    //combine mode                //~va30R~//~vam0R~
//            ||  !Mwwscrprt          //combine for print if not wysisig//~va30I~//~vam0R~
//            )                                                      //~va30I~//~vam0R~
//                combinesw=(glyphwidth==0) && (wcwidth(ch)==0);     //~va30R~//~vam0R~
//UTRACEP("uprttext utf8 ucs=%04x,pgl=%p,font=%p,griph=%x,glyphwidth=%lf,combinesw=%d\n",ch,pgl,pfont,glyph,glyphwidth,combinesw);//~va30R~//~vam0R~
//            xoffs=0;                                               //~va20I~//~vam0R~
//          if (combinesw)                                           //~va30I~//~vam0R~
//            xoffs=-dx;                                             //~va30I~//~vam0R~
//          else                                                     //~va30I~//~vam0R~
//          if (Mwwscrprt)    //wysisig option on page dialog        //~va20I~//~vam0R~
//          {                                                        //~va20I~//~vam0R~
//            widesw=(glyphwidth>xsbcswidth);                        //~va1DI~//~va20I~//~vam0R~
//            xcellwidth=dx+dx*widesw;                               //~va1DI~//~va20I~//~vam0R~
//            xoffs=(glyphwidth && glyphwidth<xcellwidth ? (xcellwidth-glyphwidth)/2:0);//~va1DR~//~va20I~//~vam0R~
//          }                                                        //~va20I~//~vam0R~
//                gnome_glyphlist_moveto(pgl,xx+xoffs,yy); //move to center of cell//~va1DI~//~va20I~//~vam0R~
//                dbcsid=*pdbcs;                                     //~va20I~//~vam0R~
////          UTRACEP("ucs=%02x dbcsid=%x,glyphwidth=%lf,sbcswidth=%lf,cellwidth=%lf,xoffs=%lf,dx=%lf\n",ch,dbcsid,glyphwidth,xsbcswidth,xcellwidth,xoffs,dx);//~va1DR~//~vaffR~//~vam0R~
////for utf8 file dd2f changed dbcscstbl                             //~va20I~//~vam0R~
//                if (dbcsid==UDBCSCHK_DBCS1ST)  //dd2f change dbcstbl to locale code from ucs//~va20R~//~vam0R~
//                {                                                  //~vX03I~//~va20I~//~vam0R~
//                  if (Mwwscrprt||!glyphwidth)   //wysisig option on page dialog,glyph width mwy be 0 //~va1DI~//~va20R~//~vam0R~
//                    xx+=dx+dx;                                     //~va20I~//~vam0R~
//                  else                                             //~va1DI~//~va20I~//~vam0R~
//                    xx+=glyphwidth;                                 //~va1DR~//~va20I~//~vam0R~
//                    pdbcs+=2;                                      //~va20I~//~vam0R~
//                }                                                  //~vX03I~//~va20I~//~vam0R~
//                else                                               //~vX03I~//~va20I~//~vam0R~
//                {                                                  //~va20I~//~vam0R~
//                 if (!combinesw)                                   //~va30I~//~vam0R~
//                 {                                                 //~va30I~//~vam0R~
//                  if (Mwwscrprt||!glyphwidth)    //wysisig option on page dialog//~va20R~//~vam0R~
//                    xx+=dx;                                        //~va20I~//~vam0R~
//                  else                                             //~va20I~//~vam0R~
//                    xx+=glyphwidth;                                //~va20I~//~vam0R~
//                 }                                                 //~va30I~//~vam0R~
//                    pdbcs++;                                       //~vX03I~//~va20I~//~vam0R~
//                }                                                  //~va20I~//~vam0R~
//            gnome_glyphlist_glyph(pgl,glyph);                      //~vX03R~//~va20I~//~vam0R~
//            putf8=putf8next;                                       //~vXXEI~//~va20I~//~vam0R~
//        }                                                          //~vXXER~//~va20I~//~vam0R~
//        gnome_print_moveto(Gpprtctxt,0.0,0.0);                     //~vXXER~//~va20I~//~vam0R~
//        gnome_print_glyphlist(Gpprtctxt,pgl);                      //~vXXER~//~va20I~//~vam0R~
//        gnome_glyphlist_unref(pgl);                                //~vXXER~//~va20I~//~vam0R~
		pcairocontext=gtk_print_context_get_cairo_context(Gpgtkprtctxt);//~vam0I~
//dprintf("uprttextout utf8len=%d,xx=%lf,yy=%lf\n",utf8len,xx,yy);  //~vXXER~//~va20I~//~vamtR~
		    pdbcs=Pdbcs;                                           //~va20I~
//  		dx=Mdrawcellw*Mpreviewscalex;                          //~vXXEI~//~va20I~//~vam0R~
//no monospace consideration for preview                           //~va20I~
            for (ii=0,putf8=(char*)putf80;ii<utf8len;ii++,xx+=dx)//~vXXER~//~va20I~
            {                                                      //~vXXER~//~va20I~
                putf8next=g_utf8_next_char(putf8);                 //~vXXER~//~va20I~
				UTRACEP("uprttextoutwsub utf8 data ii=%d,utf8len=%d,putf8=%p,next=%p\n",ii,utf8len,putf8,putf8next);//~vamqR~
//              pango_layout_set_text(Gplayoutpreview,putf8,(ULONG)putf8next-(ULONG)putf8);//~vXXER~//~va20I~//~vam0R~
                pango_layout_set_text(GplayoutGtkPrint,putf8,(ULONG)putf8next-(ULONG)putf8);//~vam0I~
				UTRACED("uprttextoutwsub utf8 data",putf8,putf8next>putf8?PTRDIFF(putf8next,putf8):1);//~vam0I~//~vamqR~
//              pango_layout_set_attributes(Gplayoutpreview,Gppangoattrlist);//~vXXER~//~va20I~//~vam0R~
                pango_layout_set_attributes(GplayoutGtkPrint,GppangoattrlistGtkPrint);//~vam0I~
//              gdk_draw_layout(Gppixmappreview,Gpgcpreview,xx,yy,Gplayoutpreview);//~vXXER~//~va20I~//~vam0R~
				cairo_move_to(pcairocontext,xx,yy);                //~vam0I~
				csub_setcolorGtk(pcairocontext);                   //~vam0I~
            	pango_cairo_show_layout(pcairocontext,GplayoutGtkPrint);//~vam0I~
				UTRACEP("uprttextoutwsub xx=%lf,yy=%lf\n",xx,yy);  //~vam0R~
                dbcsid=*pdbcs;                                     //~va20I~
//for utf8 file dd2f changed dbcscstbl                             //~va20I~
		        if (dbcsid==UDBCSCHK_DBCS1ST)  //require  2byte write for DBCS//~va1DI~//~va20R~
                {                                                  //~vXXER~//~va20I~
//      		    ch=g_utf8_get_char(putf8);                     //~va1DI~//~vam0R~
                    pdbcs+=2;                                 //~va1DI~//~va20I~
                    xx+=dx;           //~va1DI~                    //~va20I~
                }                                                  //~vXXER~//~va20I~
                else                                               //~va1DI~//~va20I~
                    pdbcs++;                                       //~va1DI~//~va20I~
                putf8=putf8next;                                   //~vXXER~//~va20I~
            }                                                      //~vXXER~//~va20I~
        }//!ligature                                               //~vam7I~
    }                                                              //~vXXEI~//~va20I~
    return 0;                                                        //~vXXEI~//~va20R~
}//uprttextoutwsub                                                 //~vXXER~//~va20R~
	#else    //!GTKPRINT                                           //~vam0I~
//==========================================================================//~vam0I~
int uprttextoutwsub(int Popt,int Pposx,int Pposy,char *Pdata,char *Pdbcs,int Plen,int Plenlc)         //~vXXER~//~va20R~
{                                                                  //~vXXEI~//~va20I~
    GnomeGlyphList *pgl;                                           //~vXXEI~//~va20I~
    GnomeFont *pfont;                                              //~vXXEI~//~va20I~
	int print_color =DEFAULT_PRINTCOLOR;                           //~vXXEI~//~va20I~
    gdouble yy,xx,dx;                                              //~vXXER~//~va20I~
    gchar *putf80;                                                 //~vXXER~//~va20I~
    char *putf8,*putf8next,*pdbcs;                             //~vX03R~//~va20R~
    int writelen,ii,utf8len,dbcsid;                           //~v69sR~//~va20R~
    gunichar ch;                                                   //~vXXER~//~va20I~
    gint glyph;                                                    //~vXXEI~//~va20I~
    int widesw;                                                //~va1DR~//~va20R~
    int combinesw;                                                 //~va30I~
    gdouble xsbcswidth,glyphwidth,xcellwidth,xoffs;                //~va1DR~//~va20I~
//*******************************                                  //~vXXEI~//~va20I~
	if (!Plen)                                                     //~vXXEI~//~va20I~
    	return 0;                                                  //~vXXEI~//~va20R~
    putf80=Pdata;                                                  //~va20I~
    writelen=Plen;                                                 //~va20I~
UTRACED("uprttextwsub utf8 data",Pdata,Plen);                    //~va1cR~//~va20I~
UTRACEP("preview mode=%d,ww=%d,monospace=%d\n",Mpreviewmode,Mwwscrprt,Mmonospacepreviewfile);//~va1DR~//~va20I~
	utf8len=g_utf8_strlen (putf80,writelen);                       //~vXXEI~//~va20I~
//dprintf("uprttextoutwsub utf8len=%d\n",utf8len);                      //~vXXER~//~va20I~//~vamtR~
    if (Mpreviewmode)                                              //~vXXEI~//~va20I~
    {                                                              //~vXXEI~//~va20I~
        xx=Pposx*Mpreviewscalex+Mprevieworgx;                      //~vXXEI~//~va20I~
        yy=Pposy*Mpreviewscaley+Mprevieworgy;                      //~vXXEI~//~va20I~
//dprintf("uprttextout utf8len=%d,xx=%lf,yy=%lf\n",utf8len,xx,yy);  //~vXXER~//~va20I~//~vamtR~
		    pdbcs=Pdbcs;                                           //~va20I~
    		dx=Mdrawcellw*Mpreviewscalex;                          //~vXXEI~//~va20I~
//no monospace consideration for preview                           //~va20I~
            for (ii=0,putf8=(char*)putf80;ii<utf8len;ii++,xx+=dx)//~vXXER~//~va20I~
            {                                                      //~vXXER~//~va20I~
                putf8next=g_utf8_next_char(putf8);                 //~vXXER~//~va20I~
                pango_layout_set_text(Gplayoutpreview,putf8,(ULONG)putf8next-(ULONG)putf8);//~vXXER~//~va20I~
                pango_layout_set_attributes(Gplayoutpreview,Gppangoattrlist);//~vXXER~//~va20I~
                gdk_draw_layout(Gppixmappreview,Gpgcpreview,xx,yy,Gplayoutpreview);//~vXXER~//~va20I~
UTRACED("preview dbcs ",pdbcs,1);                                  //~va1DI~//~va20I~
                dbcsid=*pdbcs;                                     //~va20I~
//for utf8 file dd2f changed dbcscstbl                             //~va20I~
		        if (dbcsid==UDBCSCHK_DBCS1ST)  //require  2byte write for DBCS//~va1DI~//~va20R~
                {                                                  //~vXXER~//~va20I~
        		    ch=g_utf8_get_char(putf8);                     //~va1DI~//~va20I~
                    pdbcs+=2;                                 //~va1DI~//~va20I~
                    xx+=dx;           //~va1DI~                    //~va20I~
                }                                                  //~vXXER~//~va20I~
                else                                               //~va1DI~//~va20I~
                    pdbcs++;                                       //~va1DI~//~va20I~
                putf8=putf8next;                                   //~vXXER~//~va20I~
            }                                                      //~vXXER~//~va20I~
//dprintf("prttext last=(%d,%d)-->(%lf,%lf)\n",Pposx,Pposy,xx,yy); //~vX03R~//~va20I~
    }                                                              //~vXXEI~//~va20I~
    else                                                           //~vXXEI~//~va20I~
    {                                                              //~vXXEI~//~va20I~
      if (MprintLigature)                                          //~vam7M~
      {                                                            //~vam7M~
      	uprttextout_GnomeLigature(Pposx,Pposy,putf80,utf8len);     //~vam7I~
      }                                                            //~vam7M~
      else //!Ligature                                             //~vam7M~
      {                                                            //~vam7M~
        pdbcs=Pdbcs;                                               //~va20I~
    	dx=Mdrawcellw;                                             //~vXXEI~//~va20I~
    	xx=(gdouble)Pposx;//(gdouble)Mprtrect.left;                //~vXXEI~//~va20I~
	    yy=(gdouble)(-Pposy-Mprtfontascendant);//(Mprtrect.top-Pposy);//font baseline pos from origin(set at vieportfile)//~vXXEI~//~va20I~
	    pfont=Mpprtfont;                                           //~vXXEI~//~va20I~
        xsbcswidth=uprtgetsbcswidth(0,pfont);                      //~va1DI~//~va20I~
//dprintf("font=%p\n",pfont);                                       //~vXXER~//~va20I~//~vamtR~
        pgl=gnome_glyphlist_from_text_dumb(pfont,print_color,0.0,0.0,"");//kerning=letterspace=0//~vXXER~//~va20I~
            gnome_glyphlist_advance (pgl,FALSE);//move pen by cellszw//~vXXER~//~va20I~
        for (ii=0,putf8=(char*)putf80;ii<utf8len;ii++)//~vXXER~    //~va20I~
        {                                                          //~vXXER~//~va20I~
        	putf8next=g_utf8_next_char(putf8);                     //~vXXER~//~va20I~
            ch=g_utf8_get_char(putf8);                             //~vXXER~//~va20I~
UTRACEP("uprttext utf8 Mwwscrprt=%d,charii=%d,ch=%x,xx=%lf\n ",Mwwscrprt,ii,ch,xx);//~va30I~
            glyph=gnome_font_lookup_default(pfont,ch);             //~vX03R~//~va20I~
        	glyphwidth=gnome_font_get_glyph_width(pfont,glyph);    //~va1DR~//~va20I~
            combinesw=0;                                           //~va30I~
	        if (UTF_COMBINEMODE()    //combine mode                //~va30R~
          	||  !Mwwscrprt          //combine for print if not wysisig//~va30I~
            )                                                      //~va30I~
            	combinesw=(glyphwidth==0) && (wcwidth(ch)==0);     //~va30R~
UTRACEP("uprttext utf8 ucs=%04x,pgl=%p,font=%p,griph=%x,glyphwidth=%lf,combinesw=%d\n",ch,pgl,pfont,glyph,glyphwidth,combinesw);//~va30R~
            xoffs=0;                                               //~va20I~
          if (combinesw)                                           //~va30I~
            xoffs=-dx;                                             //~va30I~
          else                                                     //~va30I~
          if (Mwwscrprt)    //wysisig option on page dialog        //~va20I~
          {                                                        //~va20I~
            widesw=(glyphwidth>xsbcswidth);                        //~va1DI~//~va20I~
            xcellwidth=dx+dx*widesw;                               //~va1DI~//~va20I~
            xoffs=(glyphwidth && glyphwidth<xcellwidth ? (xcellwidth-glyphwidth)/2:0);//~va1DR~//~va20I~
          }                                                        //~va20I~
                gnome_glyphlist_moveto(pgl,xx+xoffs,yy); //move to center of cell//~va1DI~//~va20I~
                dbcsid=*pdbcs;                                     //~va20I~
//      	UTRACEP("ucs=%02x dbcsid=%x,glyphwidth=%lf,sbcswidth=%lf,cellwidth=%lf,xoffs=%lf,dx=%lf\n",ch,dbcsid,glyphwidth,xsbcswidth,xcellwidth,xoffs,dx);//~va1DR~//~vaffR~
//for utf8 file dd2f changed dbcscstbl                             //~va20I~
		        if (dbcsid==UDBCSCHK_DBCS1ST)  //dd2f change dbcstbl to locale code from ucs//~va20R~
                {                                                  //~vX03I~//~va20I~
                  if (Mwwscrprt||!glyphwidth)   //wysisig option on page dialog,glyph width mwy be 0 //~va1DI~//~va20R~
                    xx+=dx+dx;                                     //~va20I~
                  else                                             //~va1DI~//~va20I~
                  	xx+=glyphwidth;                                 //~va1DR~//~va20I~
                    pdbcs+=2;                                      //~va20I~
                }                                                  //~vX03I~//~va20I~
                else                                               //~vX03I~//~va20I~
                {                                                  //~va20I~
				 if (!combinesw)                                   //~va30I~
                 {                                                 //~va30I~
                  if (Mwwscrprt||!glyphwidth)    //wysisig option on page dialog//~va20R~
                    xx+=dx;                                        //~va20I~
                  else                                             //~va20I~
                  	xx+=glyphwidth;                                //~va20I~
                 }                                                 //~va30I~
                    pdbcs++;                                       //~vX03I~//~va20I~
                }                                                  //~va20I~
            gnome_glyphlist_glyph(pgl,glyph);                      //~vX03R~//~va20I~
            putf8=putf8next;                                       //~vXXEI~//~va20I~
        }                                                          //~vXXER~//~va20I~
        gnome_print_moveto(Gpprtctxt,0.0,0.0);                     //~vXXER~//~va20I~
        gnome_print_glyphlist(Gpprtctxt,pgl);                      //~vXXER~//~va20I~
        gnome_glyphlist_unref(pgl);                                //~vXXER~//~va20I~
      }//!ligature                                                 //~vam7I~
    }                                                              //~vXXEI~//~va20I~
    return 0;                                                        //~vXXEI~//~va20R~
}//uprttextoutwsub                                                 //~vXXER~//~va20R~
	#endif   //!GTKPRINT                                           //~vam0I~
#endif //!NOGOMEPRINT                                              //~vam0I~
#endif                                                             //~va20I~
//***************************************************************************//~vXXEI~
//* printer text write from screen data utf string(preview),or char(print)//~vX03R~
//***************************************************************************//~vXXEI~
#ifndef NOPRINT                                                    //~vam0R~
	#ifdef GTKPRINT                                                //~vam0I~
//==========================================================================//~vam0I~
void uprtscrtextout(char *Pputf8str,int Pposx,int Pposy,int Plen)  //~vXXEI~
{                                                                  //~vXXEI~
//  GnomeGlyphList *pgl;                                           //~vXXEI~//~vam0R~
//  GnomeFont *pfont;                                              //~vXXEI~//~vam0R~
    cairo_t    *pcairocontext;                                     //~vam0I~
//	int print_color =DEFAULT_PRINTCOLOR;                           //~vXXEI~//~vam0R~
    gdouble yy,xx;                                                 //~vXXEI~
//    gunichar ch;                                                   //~vXXEI~//~vam0R~
//  gint glyph;                                                    //~vXXEI~//~vam0R~
//*******************************                                  //~vXXEI~
	if (!Plen)                                                     //~vXXEI~
    	return;                                                    //~vXXEI~
    if (Mpreviewmode)                                              //~vX03R~
    {                                                              //~vXXEI~
        xx=Pposx*Mpreviewscalex+Mprevieworgx;                      //~vXXEM~
        yy=Pposy*Mpreviewscaley+Mprevieworgy;                      //~vXXEM~
    	pango_layout_set_text(Gplayoutpreview,Pputf8str,Plen);     //~vXXER~
        pango_layout_set_attributes(Gplayoutpreview,Gppangoattrlist);//~vXXER~
UTRACEP("uprtscrtextout previewmode xx=%d--%lf,yy=%d-->%lf,len=%d\n",Pposx,xx,Pposy,yy,Plen);//~vXXER~//~vam0R~
UTRACED("uprtscrtextout text",Pputf8str,Plen);                     //~vam9R~
      	gdk_draw_layout(Gppixmappreview,Gpgcpreview,xx,yy,Gplayoutpreview);//~vXXER~
    }                                                              //~vXXEI~
    else                                                           //~vXXEI~
    {                                                              //~vXXEI~
//        pfont=Mpprtfont;    //var8                                 //~vX03R~//~var8R~
//        xx=(gdouble)Pposx;//(gdouble)Mprtrect.left;                //~vXXER~//~vam0R~
//        yy=(gdouble)(-Pposy-Mprtfontascendant);//(Mprtrect.top-Pposy);//font baseline pos from origin(set at vieportfile)//~vXXER~//~vam0R~
//        pgl=gnome_glyphlist_from_text_dumb(pfont,print_color,0.0,0.0,"");//kerning=letterspace=0//~vXXER~//~vam0R~
//        gnome_glyphlist_advance (pgl,FALSE);//not move pen by font standard advance vector//~vXXER~//~vam0R~
//        gnome_glyphlist_moveto(pgl,xx,yy);                         //~vXXER~//~vam0R~
//        ch=g_utf8_get_char(Pputf8str);                             //~vXXER~//~vam0R~
//        glyph=gnome_font_lookup_default (pfont,ch);                //~vXXER~//~vam0R~
//        gnome_glyphlist_glyph (pgl,glyph);                         //~vXXER~//~vam0R~
//        gnome_print_moveto(Gpprtctxt,0.0,0.0);                     //~vXXER~//~vam0R~
//        gnome_print_glyphlist(Gpprtctxt,pgl);                      //~vXXER~//~vam0R~
//        gnome_glyphlist_unref(pgl);                                //~vXXER~//~vam0R~
		pcairocontext=gtk_print_context_get_cairo_context(Gpgtkprtctxt);//~vam0I~
        xx=Pposx;                                                  //~vam0I~
        yy=Pposy;                                                  //~vam0I~
    	pango_layout_set_text(GplayoutGtkPrintScr,Pputf8str,Plen); //~vam0R~
        UTRACED("uprtscrtextout not preview",Pputf8str,Plen);      //~vamaI~
        pango_layout_set_attributes(GplayoutGtkPrintScr,GppangoattrlistGtkPrint);//~vam0R~
//dprintf("text xx=%d--%lf,yy=%d-->%lf,len=%d\n",Pposx,xx,Pposy,yy,Plen);//~vam0I~//~vamtR~
//    	gdk_draw_layout(Gppixmappreview,Gpgcpreview,xx,yy,Gplayoutpreview);//~vam0I~
		cairo_move_to(pcairocontext,xx,yy);                        //~vam0I~
		csub_setcolorGtk(pcairocontext);                           //~vam0I~
        pango_cairo_show_layout(pcairocontext,GplayoutGtkPrintScr);//~vam0R~
        UTRACEP("uprtscrtextout pango_cairo_show_layout GplayoutGtkPrintScr=%p\n",GplayoutGtkPrintScr);//~vam0R~
    }                                                              //~vXXEI~
    return;                                                        //~vXXEI~
}//uprtscrtextout                                                  //~vXXEI~
	#else    //!GTKPRINT                                           //~vam0I~
//==========================================================================//~vam0I~
void uprtscrtextout(char *Pputf8str,int Pposx,int Pposy,int Plen)  //~vXXEI~
{                                                                  //~vXXEI~
    GnomeGlyphList *pgl;                                           //~vXXEI~
    GnomeFont *pfont;                                              //~vXXEI~
	int print_color =DEFAULT_PRINTCOLOR;                           //~vXXEI~
    gdouble yy,xx;                                                 //~vXXEI~
    gunichar ch;                                                   //~vXXEI~
    gint glyph;                                                    //~vXXEI~
//*******************************                                  //~vXXEI~
	if (!Plen)                                                     //~vXXEI~
    	return;                                                    //~vXXEI~
    if (Mpreviewmode)                                              //~vX03R~
    {                                                              //~vXXEI~
        xx=Pposx*Mpreviewscalex+Mprevieworgx;                      //~vXXEM~
        yy=Pposy*Mpreviewscaley+Mprevieworgy;                      //~vXXEM~
    	pango_layout_set_text(Gplayoutpreview,Pputf8str,Plen);     //~vXXER~
        pango_layout_set_attributes(Gplayoutpreview,Gppangoattrlist);//~vXXER~
//dprintf("text xx=%d--%lf,yy=%d-->%lf,len=%d\n",Pposx,xx,Pposy,yy,Plen);//~vXXER~//~vamtR~
      	gdk_draw_layout(Gppixmappreview,Gpgcpreview,xx,yy,Gplayoutpreview);//~vXXER~
    }                                                              //~vXXEI~
    else                                                           //~vXXEI~
    {                                                              //~vXXEI~
        pfont=Mpprtfont;	//var8                                 //~var8R~
        xx=(gdouble)Pposx;//(gdouble)Mprtrect.left;                //~vXXER~
        yy=(gdouble)(-Pposy-Mprtfontascendant);//(Mprtrect.top-Pposy);//font baseline pos from origin(set at vieportfile)//~vXXER~
        pgl=gnome_glyphlist_from_text_dumb(pfont,print_color,0.0,0.0,"");//kerning=letterspace=0//~vXXER~
        gnome_glyphlist_advance (pgl,FALSE);//not move pen by font standard advance vector//~vXXER~
        gnome_glyphlist_moveto(pgl,xx,yy);                         //~vXXER~
        ch=g_utf8_get_char(Pputf8str);                             //~vXXER~
        glyph=gnome_font_lookup_default (pfont,ch);                //~vXXER~
        gnome_glyphlist_glyph (pgl,glyph);                         //~vXXER~
        gnome_print_moveto(Gpprtctxt,0.0,0.0);                     //~vXXER~
        gnome_print_glyphlist(Gpprtctxt,pgl);                      //~vXXER~
        gnome_glyphlist_unref(pgl);                                //~vXXER~
//      dprintf("scrprint ch=%c,len=%d,x=%lf,y=%lf,posx=%d,posy=%d\n",*Pputf8str,Plen,xx,yy,Pposx,Pposy);//~vX03R~
    }                                                              //~vXXEI~
    return;                                                        //~vXXEI~
}//uprtscrtextout                                                  //~vXXEI~
	#endif   //!GTKPRINT                                           //~vam0I~
#endif //!NOGOMEPRINT                                              //~vam0I~
//***************************************************************************//~vXXEI~
//* printer line write                                             //~vXXEI~
//***************************************************************************//~vXXEI~
#ifndef NOPRINT                                                    //~vam0R~
	#ifdef GTKPRINT                                                //~vam0I~
//=========================================================================//~vam0I~
void uprtlineout(int Pposx0,int Pposy0,int Pposx1,int Pposy1)      //~vam0I~
{                                                                  //~vam0I~
	gdouble x0,y0,x1,y1;                                           //~vam0I~
    cairo_t    *pcairocontext;                                     //~vam0I~
//*******************************                                  //~vam0I~
    if (Mpreviewmode)                                              //~vam0I~
    {                                                              //~vam0I~
        x0=Pposx0*Mpreviewscalex+Mprevieworgx;                     //~vam0I~
        y0=Pposy0*Mpreviewscaley+Mprevieworgy;                     //~vam0I~
        x1=Pposx1*Mpreviewscalex+Mprevieworgx;                     //~vam0I~
        y1=Pposy1*Mpreviewscaley+Mprevieworgy;                     //~vam0I~
#ifndef OPTGTK3                                                    //~var8R~
	    gdk_draw_line(Gppixmappreview,Gpgcpreview,x0,y0,x1,y1);    //~vam0I~
#else                                                              //~var8R~
	    csub_gdk_draw_line(Gppixmappreview,Gpgcpreview,x0,y0,x1,y1);//~var8R~
#endif                                                             //~var8R~
    }                                                              //~vam0I~
    else                                                           //~vam0I~
    {                                                              //~vam0I~
		pcairocontext=gtk_print_context_get_cairo_context(Gpgtkprtctxt);//~vam0I~
        x0=(gdouble)Pposx0;                                        //~vam0I~
        y0=(gdouble)Pposy0;                                        //~vam0R~
        x1=(gdouble)Pposx1;                                        //~vam0I~
        y1=(gdouble)Pposy1;                                        //~vam0R~
//      gnome_print_line_stroked(Gpprtctxt,x0,y0,x1,y1);           //~vam0I~
        cairo_move_to(pcairocontext,x0,y0);                        //~vam0I~
        cairo_set_line_width(pcairocontext,1.0);                   //~vam0R~
		csub_setcolorGtk(pcairocontext);                           //~vam0I~
        cairo_line_to(pcairocontext,x1,y1);                        //~vam0I~
        cairo_stroke(pcairocontext);                               //~vam0I~
	}                                                              //~vam0I~
	UTRACEP("uprtlineout parm=(%d,%d-->%d,%d)\n",Pposx0,Pposy0,Pposx1,Pposy1);//~vam0R~
	UTRACEP("uprtlineout scale(%f,%f-->%f,%f)\n",x0,y0,x1,y1);     //~var8R~
    return;                                                        //~vam0I~
}//uprtlineout;                                                    //~vam0I~
	#else    //!GTKPRINT                                           //~vam0I~
//=========================================================================//~vam0I~
void uprtlineout(int Pposx0,int Pposy0,int Pposx1,int Pposy1)      //~vXXER~
{                                                                  //~vXXEI~
	gdouble x0,y0,x1,y1;                                           //~vXXEI~
//*******************************                                  //~vXXEI~
    if (Mpreviewmode)                                              //~vXXEI~
    {                                                              //~vXXEI~
        x0=Pposx0*Mpreviewscalex+Mprevieworgx;                     //~vXXEI~
        y0=Pposy0*Mpreviewscaley+Mprevieworgy;                     //~vXXEI~
        x1=Pposx1*Mpreviewscalex+Mprevieworgx;                     //~vXXEI~
        y1=Pposy1*Mpreviewscaley+Mprevieworgy;                     //~vXXEI~
	    gdk_draw_line(Gppixmappreview,Gpgcpreview,x0,y0,x1,y1);    //~vXXEI~
    }                                                              //~vXXEI~
    else                                                           //~vXXEI~
    {                                                              //~vXXEI~
        x0=(gdouble)Pposx0;                                        //~vXXER~
        y0=(gdouble)(-Pposy0);                                     //~vXXER~
        x1=(gdouble)Pposx1;                                        //~vXXER~
        y1=(gdouble)(-Pposy1);                                     //~vXXER~
        gnome_print_line_stroked(Gpprtctxt,x0,y0,x1,y1);           //~vXXER~
	}                                                              //~vXXEI~
    UTRACEP("uprtlineout(Gnome) parm=(%d,%d-->%d,%d line %lf,%lf-->%lf,%lf\n",Pposx0,Pposy0,Pposx1,Pposy1,x0,y0,x1,y1);//~vam7R~
    return;                                                        //~vXXEI~
}//uprtlineout;                                                    //~vXXEI~
	#endif   //!GTKPRINT                                           //~vam0I~
#endif //!NOGOMEPRINT                                              //~vam0I~
#ifdef PANGO1_6_0                                                  //~vam5I~
//***************************************************************************//~vam5I~
//* preview font scale set                                         //~vam5I~
//***************************************************************************//~vam5I~
void upreviewsetfontscalePango160(int Phcopysw,int Pcellw,int Pcellh,gdouble Pfscalex,gdouble Pfscaley)//~vam5I~
{                                                                  //~vam5I~
    PangoAttribute *ppafg,*ppabg;                                  //~vam5I~
    PangoAttrList  *ppal;                                          //~vam5I~
    guint16 fg=0,bg=65535;                                         //~vam5I~
    PangoMatrix *ppm;                                              //~vam5R~
    PangoMatrix pminit=PANGO_MATRIX_INIT;                          //~vam5I~
    int swnullppm=0;                                               //~vam5I~
//*******************************                                  //~vam5I~
UTRACEP("previewsetfontscalePango160 Phcopysw=%d,Pcellw=%d,Pcellh=%d,Pfscalex=%lf,Pfscaley=%lf\n",Phcopysw,Pcellw,Pcellh,Pfscalex,Pfscaley);//~vam5R~
//    if (Phcopysw)                                                //~vam5I~
//    {                                                            //~vam5I~
//        ugetfontmetrics(Gfontdata[0].FDfontdesc,&fontw,&fonth,0);//0 no moospace chk//~vam5I~
//        fdfontsz=pango_font_description_get_size(Gfontdata[0].FDfontdesc);//by pango unit//~vam5I~
//    }                                                            //~vam5I~
//    else                                                         //~vam5I~
//    {                                                            //~vam5I~
//        ugetfontmetrics(Gfontdata[1].FDfontdesc,&fontw,&fonth,&Mmonospacepreviewfile);//~vam5I~
//        fdfontsz=pango_font_description_get_size(Gfontdata[1].FDfontdesc);//~vam5I~
//    }                                                            //~vam5I~
//    UTRACEP("upreviewsetfontscale scrfont font-fontsz=%d,ww=%d,hh=%d prtfont ww=%d,hh=%d,scalex=%lf,scaley=%lf\n",fdfontsz,fontw,fonth,Mpfontszw,Mpfontszh,Pfscalex,Pfscaley);//~vam5I~
//    frateh=(gdouble)Mpfontszh/fonth*Pfscaley;                    //~vam5I~
//    fratew=(gdouble)Mpfontszw/fontw*Pfscalex;                    //~vam5I~
//    UTRACEP("previewsetfontscale frateh=%lf,fratew=%lf\n",frateh,fratew);//~vam5I~
//    if (frateh<fratew)                                           //~vam5I~
//        ffontsize=fdfontsz*frateh;//fdfontsz is by pango unit    //~vam5I~
//    else                                                         //~vam5I~
//        ffontsize=fdfontsz*fratew;                               //~vam5I~
//    fontsize=(int)(ffontsize);                                   //~vam5I~
//    UTRACEP("preview frateh=%lf,fratew=%lf fontsize=%d =pangounit(%d)* %lf(point)\n",frateh,fratew,fontsize,PANGO_SCALE,ffontsize);//~vam5I~
//    ppa=pango_attr_size_new(fontsize);                           //~vam5I~
//    ppa->start_index=0;         //start byte offset              //~vam5I~
//    ppa->end_index=G_MAXINT;    //end                            //~vam5I~
    ppafg=pango_attr_foreground_new(fg,fg,fg);                     //~vam5I~
    ppafg->start_index=0;         //start byte offset              //~vam5I~
    ppafg->end_index=G_MAXINT;    //end                            //~vam5I~
    ppabg=pango_attr_background_new(bg,bg,bg);                     //~vam5I~
    ppabg->start_index=0;         //start byte offset              //~vam5I~
    ppabg->end_index=G_MAXINT;    //end                            //~vam5I~
    ppal=pango_attr_list_new();                                    //~vam5I~
//    pango_attr_list_insert(ppal,ppa);                            //~vam5I~
    pango_attr_list_insert(ppal,ppafg);                            //~vam5I~
    pango_attr_list_insert(ppal,ppabg);                            //~vam5I~
    Gppangoattrlist=ppal;	//unref at gxepage                     //~vam5I~
    UTRACEP("Pango160 Gppangoattrlist=%p\n",Gppangoattrlist);      //~var8R~
//#ifdef XXX  //matrix support from 1.6                            //~vam5I~
    ppm=(PangoMatrix*)pango_context_get_matrix(Gppangocontext);    //~vam5R~
    UTRACEP("upreviewsetfontscalePango160 pango_context_get_matrix ppm=%p\n",ppm);//~vam5I~
    if (!ppm)                                                      //~vam5I~
    {                                                              //~vam5I~
        swnullppm=1;                                               //~vam5I~
    	ppm=pango_matrix_copy(&pminit);                            //~vam5I~
    }                                                              //~vam5I~
    UTRACEP("pango matrix old ppm=%p,xx=%lf,xy=%lf,yx=%lf,yy=%lf,x0=%lf,y0=%lf\n",//~vam5R~
            ppm,ppm->xx,ppm->xy,ppm->yx,ppm->yy,ppm->x0,ppm->y0);  //~vam5I~
//  pango_matrix_scale(ppm,Pfscalex,Pfscaley);                     //~vam5R~
    UTRACEP("pango matrix scaled ppm=%p,xx=%lf,xy=%lf,yx=%lf,yy=%lf,x0=%lf,y0=%lf\n",//~vam5I~
            ppm,ppm->xx,ppm->xy,ppm->yx,ppm->yy,ppm->x0,ppm->y0);  //~vam5I~
#ifndef OPTGTK3
    ppm->xx=Pfscalex;                                              //~vam9R~
    ppm->yy=Pfscaley;                                              //~vam9I~
#else                                                              //~var8R~
    if (Pfscalex>Pfscaley)                                         //~var8R~
    {                                                              //~var8R~
    	ppm->xx=Pfscaley;                                          //~var8R~
    	ppm->yy=Pfscaley;                                          //~var8R~
    }                                                              //~var8R~
    else                                                           //~var8R~
    {                                                              //~var8R~
    	ppm->xx=Pfscalex;                                          //~var8R~
    	ppm->yy=Pfscalex;                                          //~var8R~
    }                                                              //~var8R~
#endif                                                             //~var8R~
    UTRACEP("pango matrix new ppm=%p,xx=%lf,xy=%lf,yx=%lf,yy=%lf,x0=%lf,y0=%lf\n",//~vam9I~
            ppm,ppm->xx,ppm->xy,ppm->yx,ppm->yy,ppm->x0,ppm->y0);  //~vam9I~
    if (swnullppm)                                                 //~vam5M~
    	pango_context_set_matrix(Gppangocontext,ppm);              //~vam5M~
    ppm=(PangoMatrix*)pango_context_get_matrix(Gppangocontext);    //~vam5R~
    UTRACEP("pango matrix new reget ppm=%p,xx=%lf,xy=%lf,yx=%lf,yy=%lf,x0=%lf,y0=%lf\n",//~vam5R~//~vam9R~
            ppm,ppm->xx,ppm->xy,ppm->yx,ppm->yy,ppm->x0,ppm->y0);  //~vam5I~
//#endif                                                           //~vam5I~
    return;                                                        //~vam5I~
}//upreviewsetfontscalePango160                                    //~vamaR~
#endif	//PANGO1_6_0                                               //~vam5I~
//***************************************************************************//~vam5I~
void upreviewresetfontscalePango160()                              //~vam5R~
{                                                                  //~vam5I~
#ifdef PANGO1_6_0                                                  //~vam5I~
    UTRACEP("upreviewresetfontscalePango160\n");                   //~vam5I~
    pango_context_set_matrix(Gppangocontext,NULL);                 //~vam5I~
#endif                                                             //~vam5I~
}//upreviewsetfontscale                                            //~vam5I~
//***************************************************************************//~vXXEI~
//* preview font scale set                                         //~vXXEI~
//***************************************************************************//~vXXEI~
void upreviewsetfontscale(int Phcopysw,int Pcellw,int Pcellh,gdouble Pfscalex,gdouble Pfscaley)//~vXXER~
{                                                                  //~vXXEI~
	int fontsize;                                                  //~vXXER~
    int fontw,fonth;                                               //~vXXER~
//  gdouble fscalex,fscaley,fscale;                                //~vXXER~
    gdouble frateh,fratew,ffontsize;                               //~vXXER~
    PangoAttribute *ppa;                                           //~vXXEI~
    PangoAttribute *ppafg,*ppabg;                                  //~vam0I~
    PangoAttrList  *ppal;                                          //~vXXER~
    guint16 fg=0,bg=65535;                                         //~vam0R~
    int fdfontsz;                                                  //~vam5I~
//*******************************                                  //~vXXEI~
//  dprintf("setfontscale PANGO_VERSION=%d,encode=%d\n",PANGO_VERSION,PANGO_VERSION_ENCODE(1,6,0));//~var8R~
#ifdef PANGO1_6_0                                                  //~vam5I~
	if (PANGO_VERSION_CHECK(1,6,0))                                //~vam5I~
    {                                                              //~vam5I~
		upreviewsetfontscalePango160(Phcopysw,Pcellw,Pcellh,Pfscalex,Pfscaley);//~vam5I~
        return;                                                    //~vam5I~
    }                                                              //~vam5I~
#endif                                                             //~vam5I~
//    stretch=pango_font_description_get_stretch(Gfontdata[1].FDfontdesc);//~vXXER~
//    dprintf("stretch=%d\n",stretch);                             //~vX03R~
//    stretch=3;                                                   //~vXXER~
//    pango_font_description_set_stretch(Gfontdata[1].FDfontdesc,stretch);//~vXXER~
UTRACEP("previewsetfontscale Phcopysw=%d,Pcellw=%d,Pcellh=%d\n",Phcopysw,Pcellw,Pcellh);             //~va1cR~//~vam0R~
    if (Phcopysw)                                                  //~vXXEI~
    {                                                              //~vam5I~
    	ugetfontmetrics(Gfontdata[0].FDfontdesc,&fontw,&fonth,0);//0 no moospace chk//~vXXER~
        fdfontsz=pango_font_description_get_size(Gfontdata[0].FDfontdesc);//by pango unit//~vam5R~
    }                                                              //~vam5I~
    else                                                           //~vXXEI~
    {                                                              //~vam5I~
    	ugetfontmetrics(Gfontdata[1].FDfontdesc,&fontw,&fonth,&Mmonospacepreviewfile);//~vXXER~
        fdfontsz=pango_font_description_get_size(Gfontdata[1].FDfontdesc);//~vam5I~
    }                                                              //~vam5I~
    UTRACEP("upreviewsetfontscale scrfont font-fontsz=%d,ww=%d,hh=%d prtfont ww=%d,hh=%d,scalex=%lf,scaley=%lf\n",fdfontsz,fontw,fonth,Mpfontszw,Mpfontszh,Pfscalex,Pfscaley);//~v69VR~//~vam0R~//~vam5R~
//    fscalex=Pfscalex*Pcellw/fontw;                               //~vXXER~
//    fscaley=Pfscaley*Pcellh/fonth;                               //~vXXER~
//    if (fscalex<fscaley)                                         //~vXXER~
//        fscale=fscalex;                                          //~vXXER~
//    else                                                         //~vXXER~
//        fscale=fscaley;                                          //~vXXER~
//  dprintf("preview font scale set size=%d,scaley=%lf,scalex=%lf,scale=%lf\n",fontsize,fscalex,fscaley,fscale);//~vX03R~
//  ppa=pango_attr_scale_new(fscale);                              //~vXXER~
    frateh=(gdouble)Mpfontszh/fonth*Pfscaley;                      //~vXXER~
    fratew=(gdouble)Mpfontszw/fontw*Pfscalex;                      //~vXXER~
    UTRACEP("previewsetfontscale frateh=%lf,fratew=%lf\n",frateh,fratew);      //~vX03R~//~vam0R~
#ifdef AAA                                                         //~vam5I~
    if (frateh<fratew)                                             //~vXXEI~
    	ffontsize=Mpfontszh*frateh;                                //~vXXER~
    else                                                           //~vXXEI~
    	ffontsize=Mpfontszh*fratew;                                //~vXXER~
	fontsize=(int)(ffontsize*PANGO_SCALE);                         //~vXXER~
#else                                                              //~vam5M~
    if (frateh<fratew)                                             //~vam5M~
    	ffontsize=fdfontsz*frateh;//fdfontsz is by pango unit      //~vam5I~
    else                                                           //~vam5M~
    	ffontsize=fdfontsz*fratew;                                 //~vam5M~
	fontsize=(int)(ffontsize);                                     //~vam5I~
#endif                                                             //~vam5M~
    UTRACEP("preview frateh=%lf,fratew=%lf fontsize=%d =pangounit(%d)* %lf(point)\n",frateh,fratew,fontsize,PANGO_SCALE,ffontsize);//~vX03R~//~vam0R~
    ppa=pango_attr_size_new(fontsize);                             //~vXXER~
    ppa->start_index=0;         //start byte offset                //~vXXEI~
    ppa->end_index=G_MAXINT;    //end                              //~vXXEI~
    ppafg=pango_attr_foreground_new(fg,fg,fg);                     //~vam0I~
    ppafg->start_index=0;         //start byte offset              //~vam0I~
    ppafg->end_index=G_MAXINT;    //end                            //~vam0I~
    ppabg=pango_attr_background_new(bg,bg,bg);                     //~vam0R~
    ppabg->start_index=0;         //start byte offset              //~vam0I~
    ppabg->end_index=G_MAXINT;    //end                            //~vam0I~
    ppal=pango_attr_list_new();                                    //~vXXEI~
    pango_attr_list_insert(ppal,ppa);                              //~vXXER~
    pango_attr_list_insert(ppal,ppafg);                            //~vam0I~
    pango_attr_list_insert(ppal,ppabg);                            //~vam0I~
    Gppangoattrlist=ppal;	//unref at gxepage                     //~vXXER~
#ifdef XXX  //matrix support from 1.6                              //~vXXEI~//~vam5R~
    const PangoMatrix *ppm=pangeo_context_get_matrix(Gppangocontext);//~vXXER~
    dprintf("pango matrix old ppm=%p,xx=%lf,xy=%lf,yx=%x,yy=%lf,x0=%lf,y0=%lf\n",//~vX03R~
            ppm,ppm->xx,ppm->xy,ppm->yx,ppm->yy,ppm->x0,ppm.y0);   //~vXXER~
    pango_matrix_scale(ppm,Pfscalex,Pfscaley);                     //~vXXEI~
    ppm->xx=Pfscaley;ppm->yy=Pfscaley;                             //~vXXEI~
    ppm=pangeo_context_get_matrix(Gppangocontext);                 //~vXXER~
    dprintf("pango matrix new ppm=%p,xx=%lf,xy=%lf,yx=%x,yy=%lf,x0=%lf,y0=%lf\m",//~vX03R~
            ppm,ppm->xx,ppm->xy,ppm->yx,ppm->yy,ppm->x0,ppm.y0);   //~vXXER~
#endif                                                             //~vXXEI~
    return;                                                        //~vXXEI~
}//upreviewsetfontscale                                            //~vXXEI~
#ifdef UTF8UCS2                                                    //~va20I~
//===============================================================================//~va20I~
//trace layout glyph gemetry                                       //~va20I~
//===============================================================================//~va20I~
void utracelayout(PangoLayout *Pplayout)                           //~va20I~
{                                                                  //~va20I~
  	GSList *tmp_list;                                              //~va20I~
  	PangoLayoutIter *iter;                                         //~va20I~
    PangoLayoutLine *line;                                         //~va20I~
    PangoLayoutRun *run;                                           //~var8R~
    PangoGlyphString *pglyphstr;                                   //~va20I~
    PangoGlyphInfo *pglyphinfo;                                    //~va20I~
#ifndef NOTRACE                                                    //~vaa7I~
    PangoGlyphGeometry *pgeom;                                     //~va20I~
#endif                                                             //~vaa7I~
    int ii;                                                        //~va20I~
#ifndef NOTRACE    	                                               //~vbz8I~
    PangoRectangle ink,logical;                                    //~vbz8I~
    int baseline;                                                  //~vbz8I~
    const PangoFontDescription *pfont;                             //~vbz8I~
#endif                                                             //~vbz8I~
//******************************                                   //~va20I~
    UTRACELAYOUT_ATTR(Pplayout);                                   //~vbz8I~
#ifndef NOTRACE                                                    //~vbz8I~
	pango_layout_get_pixel_extents(Pplayout,&ink,&logical);        //~vbz8R~
	baseline=pango_layout_get_baseline(Pplayout);                  //~vbz8I~
	pfont=pango_layout_get_font_description(Pplayout);             //~vbz8I~
	UTRACEP("%s:baseline=%d,text=%s,ink=(x=%d,y=%d,w=%d,h=%d),logical=(%d,%d,%d,%d)\n",//~vbz8R~//~vbAfR~
		UTT,baseline,                                              //~vbAfR~
		UB2XS(0/*opt*/,pango_layout_get_text(Pplayout),0/*len*/),  //~vbAfI~
		ink.x,ink.y,ink.width,ink.height,logical.x,logical.y,logical.width,logical.height);//~vbz8I~
	UTRACEP("%s:font=%s\n",UTT,pango_font_description_to_string(pfont));//~vbz8I~
#endif                                                             //~vbz8I~
  	iter = pango_layout_get_iter(Pplayout);                        //~va20I~
    line=pango_layout_iter_get_line (iter);                        //~va20I~
    if (!line)  //split dbcs is set to layout                      //~va20I~
        return;                                                    //~va20I~
    tmp_list=line->runs;                                           //~va20I~
UTRACEP("utracelayout iter=%p,line=%p,runs=%p\n",iter,line,tmp_list);//~var8R~
	int gidx=0;                                                    //~vbAiI~
  	while(tmp_list)                                                //~va20I~
  	{                                                              //~va20I~
    	run=tmp_list->data;                                        //~va20I~
		UTRACEP("run @@@=%p\n",run);                               //~va20I~
    	if (!run)  //split dbcs is set to layout                   //~va20I~
        	return;                                                //~va20I~
    	pglyphstr=run->glyphs;                                     //~va20I~
    	if (!pglyphstr)  //split dbcs is set to layout             //~va20I~
        	return;                                                //~va20I~
		UTRACEP("temp list=%p\n",pglyphstr);                       //~va20I~
    	for (ii=pglyphstr->num_glyphs,pglyphinfo=pglyphstr->glyphs;ii>0;ii--,pglyphinfo++)//~va20I~
    	{                                                          //~va20I~
#ifndef NOTRACE                                                    //~vaa7I~
        	pgeom=&(pglyphinfo->geometry);                         //~va20I~
#else                                                              //~vaa7I~
			;                                                      //~vaa7I~
#endif                                                             //~vaa7I~
//  		UTRACEP("%s:geometry ii=%d,offs_x=%d,offs_y=%d,width=%d,gidx=%d,direction=%d\n",UTT,ii,pgeom->x_offset,pgeom->y_offset,pgeom->width,gidx,pango_layout_get_direction(Pplayout,gidx));//~va20R~//~vbj2R~//~vbAiR~//~vbC2R~
    		UTRACEP("%s:geometry ii=%d,offs_x=%d,offs_y=%d,width=%d,gidx=%d\n",UTT,ii,pgeom->x_offset,pgeom->y_offset,pgeom->width,gidx);//~vbC2R~
            gidx++;                                                //~vbAiI~
    	}                                                          //~va20I~
    	tmp_list=tmp_list->next;                                   //~va20I~
  }//runs                                                          //~va20I~
  	pango_layout_iter_free (iter);                                 //~va20I~
  	return;                                                        //~va20I~
}//utracelayout                                                    //~va20I~
//===============================================================================//~vbAhI~
int csubGetLayoutTextLen(int Popt,PangoLayout *Pplayout)           //~vbAhI~
{                                                                  //~vbAhI~
  	GSList *tmp_list;                                              //~vbAhI~
  	PangoLayoutIter *iter;                                         //~vbAhI~
    PangoLayoutLine *line;                                         //~vbAhI~
    PangoLayoutRun *run;                                           //~vbAhI~
    PangoGlyphInfo *pglyphinfo;                                    //~vbAhI~
    PangoGlyphGeometry *pgeom;                                     //~vbAhI~
    PangoGlyphString *pglyphstr;                                   //~vbAhI~
    int ii;                                                        //~vbAhI~
    int wwtotal=0;                                                 //~vbAhI~
    PangoRectangle logical;                                        //~vbAiI~
//******************************                                   //~vbAhI~
//  swutf8data=Popt & USMSO_DDFMT;   //scr data is dd fmt,pdata is not lc,dont access//~vbAhI~
    if (!(Popt & USMSO_SPLITPADDED)) //except last padding         //~vbAiI~
    {                                                              //~vbAiI~
		pango_layout_get_pixel_extents(Pplayout,NULL/*ink*/,&logical);//~vbAiI~
		UTRACEP("%s:return %d,text=%s,pixel_extent logical=(x=%d,y=%d,width=%d,height=%d)\n",UTT,logical.width,//~vbAiR~
			UB2XS(0/*opt*/,pango_layout_get_text(Pplayout),0/*len*/),logical.x,logical.y,logical.width,logical.height);//~vbAiI~
        return logical.width;                                      //~vbAiI~
    }                                                              //~vbAiI~
  	iter = pango_layout_get_iter(Pplayout);                        //~vbAhI~
    line=pango_layout_iter_get_line (iter);                        //~vbAhI~
    if (!line)  //split dbcs is set to layout                      //~vbAhI~
        return -1;                                                 //~vbAhR~
    tmp_list=line->runs;                                           //~vbAhI~
  	while(tmp_list)                                                //~vbAhI~
  	{                                                              //~vbAhI~
    	run=tmp_list->data;                                        //~vbAhI~
	    if (!run)  //split dbcs is set to layout                   //~vbAhI~
    	    return -1;                                             //~vbAhR~
    	pglyphstr=run->glyphs;                                     //~vbAhI~
    	if (!pglyphstr)  //split dbcs is set to layout             //~vbAhI~
        	return -1;                                             //~vbAhI~
    	for (ii=pglyphstr->num_glyphs,pglyphinfo=pglyphstr->glyphs;ii>0;ii--,pglyphinfo++)//~vbAhI~
    	{                                                          //~vbAhI~
        	pgeom=&(pglyphinfo->geometry);
        	UTRACEP("%s:ii=%d,width=%d,offs=%d\n",UTT,ii,pgeom->width,pgeom->x_offset);//~vbAhR~
        	if (ii==1)                                             //~vbAhI~
            	if (Popt & USMSO_SPLITPADDED) //except last padding//~vbAhI~
            		break;                                         //~vbAhI~
        	pgeom=&(pglyphinfo->geometry);                         //~vbAhI~
        	wwtotal+=pgeom->width;                                 //~vbAhI~
    	}                                                          //~vbAhI~
    	tmp_list=tmp_list->next;                                   //~vbAhI~
  	}//runs                                                        //~vbAhI~
  	pango_layout_iter_free (iter);                                 //~vbAhI~
    int rc=(wwtotal+PANGO_SCALE-1)/PANGO_SCALE;	//                                  //~vbAhI~//~vbAiR~
    UTRACEP("%s:rc=%d,wwtotal=%d\n",UTT,rc,wwtotal);               //~vbAhI~
  	return rc;                                                     //~vbAhR~
}//csubGetLayoutTextLen                                            //~vbAhI~
//===============================================================================//~va30R~
//get layoutinfo:glyphctr,width0 glyph                             //~va30R~
//===============================================================================//~va30R~
int csublyoutinfo(int Popt,PangoLayout *Pplayout,int *Pretinfo)    //~va30R~
{                                                                  //~va30R~
  	GSList *tmp_list;                                              //~va30R~
  	PangoLayoutIter *iter;                                         //~va30R~
    PangoLayoutLine *line;                                         //~va30R~
    PangoLayoutRun *run;                                           //~va30R~
    PangoGlyphString *pglyphstr;                                   //~va30R~
    int glyphctr=0;                                                //~va30R~
//******************************                                   //~va30R~
UTRACEP("csublayoutinfo\n");                                       //~va30R~
    UTRACELAYOUT(Pplayout);                                        //~vbAiI~
    Pretinfo[CSUBLI_CTR]=0;                                        //~va30R~
  	iter = pango_layout_get_iter(Pplayout);                        //~va30R~
    line=pango_layout_iter_get_line (iter);                        //~va30R~
    if (!line)  //split dbcs is set to layout                      //~va30R~
        return 4;                                                  //~va30R~
    tmp_list=line->runs;                                           //~va30R~
UTRACEP("csublayoutinfo iter=%p,line=%p,runs=%p\n",iter,line,tmp_list);//~var8R~
  	while(tmp_list)                                                //~va30R~
  	{                                                              //~va30R~
    	run=tmp_list->data;                                        //~va30R~
		UTRACEP("run @@@=%p\n",run);                               //~va30R~
    	if (!run)  //split dbcs is set to layout                   //~va30R~
        	break;                                                 //~va30R~
    	pglyphstr=run->glyphs;                                     //~va30R~
    	if (!pglyphstr)  //split dbcs is set to layout             //~va30R~
        	break;                                                 //~va30R~
		UTRACEP("temp list=%p\n",pglyphstr);                       //~va30R~
        glyphctr+=pglyphstr->num_glyphs;                           //~va30R~
    	tmp_list=tmp_list->next;                                   //~va30R~
    }//runs                                                        //~va30R~
  	pango_layout_iter_free (iter);                                 //~va30R~
    Pretinfo[CSUBLI_CTR]=glyphctr;                                 //~va30R~
UTRACEP("csublayoutinfo glyphctr=%d\n",glyphctr);                  //~va30R~
  	return 0;                                                      //~va30R~
}//csublyoutinfo                                                   //~vbAiR~
#endif                                                             //~va20I~
//===============================================================================//~vX03M~
//set monospaceing                                                 //~vX03M~
//Ppdata:dddata if Popt & USMSO_DDFMT not used                     //~vbkwR~
//       else u8 or lcdata and used                                //~vbkwR~
//Ppdbcs:lcdbcs,Plen:lclen                                         //~vbkwI~
//===============================================================================//~vX03M~
//void usetmonospace(PangoLayout *Pplayout,char *Ppdbcs,int Plen,int Pcellw)//~v79zR~
//void usetmonospace(PangoLayout *Pplayout,char *Ppdata,char *Ppdbcs,int Plen,int Pcellw)//~va1DR~
void usetmonospace(int Popt,PangoLayout *Pplayout,char *Ppdata,char *Ppdbcs,int Plen,int Pcellw)//~va1DI~
{                                                                  //~vX03M~
  	GSList *tmp_list;                                              //~vX03M~
  	PangoLayoutIter *iter;                                         //~vX03M~
    PangoLayoutLine *line;                                         //~vX03M~
    PangoLayoutRun *run;                                           //~vX03M~
    PangoGlyphString *pglyphstr;                                   //~vX03M~
    PangoGlyphInfo *pglyphinfo;                                    //~vX03M~
    PangoGlyphGeometry *pgeom;                                     //~vX03M~
#ifdef AAA	//SCM is now controlled by xxescr:drawtextstr_NoLigatureu8_SCM//~vbk6I~
    PangoGlyphGeometry *pgeomscm2;                                 //~vbk6I~
#endif //AAA                                                       //~vbk6I~
    char *pdbcs,*pdbcse;                                          //~vX03M~//~va30R~
    char *pdata;                                                   //~v79zI~
    int ii;                                                        //~vX03M~
//  int oldw,neww;                                                 //~v69VI~//~vbk4R~
#ifdef UTF8SUPPH                                                   //~v7axI~
	int dbcssz;                                                    //~v7axI~
#endif                                                             //~v7axI~
#ifdef UTF8UCS2                                                    //~va20I~
	int swutf8data;                                                //~va20I~
//  int oldx,/*oldy,*/wwpango,w0ctr=0,glyphctr=0,swtoperr,combspan,wwtotal=0;//~va30R~//~vaffR~
//  int oldx,/*oldy,*/wwpango,w0ctr=0,glyphctr=0,swtoperr=0,combspan=0,wwtotal=0;//~vaffI~//~vbk4R~
    int /*oldx,*//*oldy,*/wwpango,w0ctr=0,glyphctr=0,swtoperr=0,combspan=0,wwtotal=0;//~vbk4I~
    PangoGlyphGeometry *pgeomlast=NULL;                            //~vaffR~
#endif                                                             //~va20I~
	int swcombine,combbase_offs=0,oldw;                            //~vbk4R~
#ifdef AAA	//SCM is now controlled by xxescr:drawtextstr_NoLigatureu8_SCM//~vbk6I~
	int swscm;                                                     //~vbk6I~
    int scm1w,scm2w;                                               //~vbk6I~
#endif //AAA                                                       //~vbk6I~
#ifdef SSS                                                         //~vbkwI~
#else                                                              //~vbkwI~
    PangoGlyphGeometry *pgeomnext;                                 //~vbkwI~
    int nextwidth;                                                 //~vbkwI~
#endif //SSS                                                       //~vbkwI~
//******************************                                   //~vX03M~
#ifdef UTF8UCS2                                                    //~va20I~
	swutf8data=Popt & USMSO_DDFMT;   //scr data is dd fmt,pdata is not lc,dont access//~va20I~
#endif                                                             //~va20I~
  	iter = pango_layout_get_iter(Pplayout);                        //~vX03R~
    line=pango_layout_iter_get_line (iter);                        //~vX03M~
    if (!line)  //split dbcs is set to layout                      //~v69VR~
        return;                                                    //~v69VR~
    tmp_list=line->runs;                                           //~vX03M~
UTRACEP("%s:Popt=0x%x,swutf8data=0x%x layout=%p,opt=%x,len=%d,iter=%p,line=%p,runs=%p\n",UTT,Popt,swutf8data,Pplayout,Popt,Plen,iter,line,tmp_list);//~var8R~//~vbkwR~
UTRACED("Ppdata dddata or u8 by swutf8data",Ppdata,Plen);          //~vbkwR~
UTRACED("Ppdata lcdbcs",Ppdbcs,Plen);                              //~vbkwI~
//dprintf("list@@@=%p\n",tmp_list);                                //~v69VR~
  pdata=Ppdata;                                                    //~v79zI~
  pdbcs=Ppdbcs;                                                    //~v69VI~
  pdbcse=Ppdbcs+Plen;		//end addr;                            //~v69VI~
  while(tmp_list)                                                  //~v69VR~
  {                                                                //~v69VI~
    run=tmp_list->data;                                            //~vX03M~
UTRACEP("run=%p\n",run);                                           //~var8R~
    if (!run)  //split dbcs is set to layout                       //~v69VR~
        return;                                                    //~v69VR~
    pglyphstr=run->glyphs;                                         //~vX03M~
    if (!pglyphstr)  //split dbcs is set to layout                 //~v69VR~
        return;                                                    //~v69VR~
UTRACEP("temp list=%p\n",pglyphstr);                               //~va1cR~
//  pdbcs=Ppdbcs;                                                  //~v69VR~
//  pdbcse=Ppdbcs+Plen;		//end addr;                            //~v69VR~
	wwpango=Pcellw*PANGO_SCALE;                                    //~va30R~
#ifdef AAA	//SCM is now controlled by xxescr:drawtextstr_NoLigatureu8_SCM//~vbk6I~
    pgeomscm2=0;                                                   //~vbk6I~
#endif //AAA                                                       //~vbk6I~
    for (ii=pglyphstr->num_glyphs,pglyphinfo=pglyphstr->glyphs;ii>0;ii--,pglyphinfo++)//~vX03M~
    {                                                              //~vX03M~
        glyphctr++;                                                //~va30R~
        pgeom=&(pglyphinfo->geometry);                             //~vX03M~
        pgeomlast=pgeom;                                           //~va30R~
//      oldw=pgeom->width;                                         //~v69VI~//~vbk4R~
        oldw=pgeom->width & CSUB_GEOMID_WIDTH_MASK;                //~vbk4R~
        swcombine=pgeom->width & CSUB_GEOMID_COMBINE;              //~vbk4I~
#ifdef AAA	//SCM is now controlled by xxescr:drawtextstr_NoLigatureu8_SCM//~vbk6I~
        swscm=pgeom->width & (CSUB_GEOMID_SCM1|CSUB_GEOMID_SCM2);  //~vbk6I~
        if (swscm)                                                 //~vbk6I~
        {                                                          //~vbk6I~
        	if (swscm & CSUB_GEOMID_SCM2)	//prev of combining    //~vbk6I~
            	pgeomscm2=pgeom;                                   //~vbk6I~
            else                                                   //~vbk6I~
            	if (!pgeomscm2)                                    //~vbk6I~
                	swscm=0;	//assume scm follows base          //~vbk6I~
        }                                                          //~vbk6I~
        else                                                       //~vbk6I~
            pgeomscm2=0;                                           //~vbk6I~
#endif //AAA                                                       //~vbk6I~
//      pgeom->width &= ~CSUB_GEOMID_COMBINE;                      //~vbk4I~//~vbk6R~
        pgeom->width = oldw;                                       //~vbk6R~
//      oldx=pgeom->x_offset;                                      //~va30R~//~vbk4R~
//	    oldy=pgeom->y_offset;                                      //~va30R~//~vaa7R~
UTRACEP("geometry ii=%d/%d,offs_x=%d,offs_y=%d,width=%d cellw=%d\n",ii,pglyphstr->num_glyphs,pgeom->x_offset,pgeom->y_offset,pgeom->width,Pcellw);//~va1cR~//~vbk4R~
//      if (*pdbcs==UDBCSCHK_DBCS1ST && pdbcs+1<pdbcse)  //require  2byte write for DBCS//~v79zR~
#ifdef UTF8SUPPH                                                   //~va1cR~
		dbcssz=1;	//sbcs                                         //~va1cR~
#ifdef AAA	//SCM is now controlled by xxescr:drawtextstr_NoLigatureu8_SCM//~vbk6I~
        if (swscm)  //spacing combine mark; wcwidth=1 && glyphctr=2//~vbk6I~
        {                                                          //~vbk6I~
#ifdef AAA                                                         //~vbk6I~
	        pgeom->width=Pcellw*PANGO_SCALE;                       //~vbk6I~
#else                                                              //~vbk6I~
        	if (swscm & CSUB_GEOMID_SCM1)                          //~vbk6I~
            {                                                      //~vbk6I~
//      		pgeomscm2=&((pglyphinfo+1)->geometry);             //~vbk6R~
            	scm1w=oldw;                                        //~vbk6I~
		        scm2w=pgeomscm2->width & CSUB_GEOMID_WIDTH_MASK;   //~vbk6I~
                if (scm2w<scm1w)    //combining glyph is at before the base//~vbk6I~
                    pgeom->width=Mcellw*PANGO_SCALE*2-scm2w;       //~vbk6R~
                else                //combining glyph is at after the base//~vbk6I~
                    pgeom->width=Mcellw*PANGO_SCALE*2-scm1w;       //~vbk6R~
                UTRACEP("%s:SCM1 scm2w=0x%x->,0x%x,scm1w=0x%x->0x%0x,pangoMcellw=%d\n",UTT,scm2w,pgeomscm2->width,scm1w,pgeom->width,Pcellw*PANGO_SCALE);//~vbk6R~
            }                                                      //~vbk6I~
#endif                                                             //~vbk6I~
            pdata++;                                               //~vbk6I~
            pdbcs++;                                               //~vbk6I~
        }                                                          //~vbk6I~
        else                                                       //~vbk6I~
#endif //AAA                                                       //~vbk6I~
#ifdef UTF8UCS2                                                    //~va20I~
        if ((swutf8data||*pdata>=0x80)                             //~va20I~
//*pdata>=0x80  is actualy no meaning because *pdbcs==DBCS1ST incluse *pdata>=0x80//~vbkwI~
#else                                                              //~va20I~
        if (*pdata>=0x80                                           //~va1cR~
#endif                                                             //~va20I~
//*after ucs dbcsid is converted to locale dbcsid                  //~va20I~
        &&  *pdbcs==UDBCSCHK_DBCS1ST                               //~va1cR~
        &&  pdbcs+(dbcssz=XESUB_DBCSSPLITCTR(pdbcs,(int)((ULONG)pdbcse-(ULONG)pdbcs),0))<=pdbcse//~va1cR~
        )                                                          //~va1cR~
        {                                                          //~va1cR~
//#ifdef BBB                                                       //~vbk4I~
//          neww=                                                  //~va1cR~//~vbk4R~
	        pgeom->width=(Pcellw+Pcellw)*PANGO_SCALE;              //~va1cR~
//#endif                                                           //~vbk4I~
          	if (Popt & USMSO_WWSCRPRT)	//wysiwig print            //~va1DI~
            	pgeom->width=(Pcellw*dbcssz)*PANGO_SCALE;	//for dbcs padding space//~va1DR~
            pdata+=dbcssz; //print width is 2 column but data is 3-4 byte//~va1cR~
            pdbcs+=dbcssz; //after 3/4 byte dbcs "." is padded by csublocale2utfscr//~va1cR~
        }                                                          //~va1cR~
#else                                                              //~va1cR~
        if (*pdata>=0x80 && *pdbcs==UDBCSCHK_DBCS1ST && pdbcs+1<pdbcse)  //require  2byte write for DBCS//~v79zI~
        {                                                          //~vX03M~
//          neww=                                                  //~v69VI~//~vbk4R~
	        pgeom->width=(Pcellw+Pcellw)*PANGO_SCALE;              //~vX03M~
//          if (Pcellw>Pfontw)                                     //~vX03M~
//      	    pgeom->x_offset=(Pcellw-Pfontw)*PANGO_SCALE;       //~vX03M~
            pdata+=2;                                              //~v79zI~
            pdbcs+=2;                                              //~vX03M~
        }                                                          //~vX03M~
#endif                                                             //~va1cR~
        else                                                       //~vX03M~
        {                                                          //~vX03M~
//#ifdef BBB                                                       //~vbk4I~
//        	neww=                                                  //~v69VI~//~vbk4R~
	        pgeom->width=Pcellw*PANGO_SCALE;                       //~vX03M~
//#endif                                                           //~vbk4I~
            pdata++;                                               //~v79zI~
            pdbcs++;                                               //~vX03M~
        }                                                          //~vX03M~
#ifdef BBB                                                         //~vbk4I~
//      if (oldw)                                                  //~va30R~//~vbk4R~
//      	pgeom->x_offset=(neww-oldw)/2;                         //~va30R~//~vbk3R~
      		pgeom->x_offset=(wwpango-oldw)/2;                      //~vbk4I~
#else                                                              //~vbk4I~
        	pgeom->x_offset=0;                                     //~vbj2I~
#endif                                                             //~vbk4I~
        if (Popt & USMSO_COMBINEOF)	//1 column for each combining char//~va30R~
        {                                                          //~va30R~
#ifdef AAA                                                         //~vbk4I~
	        if (!oldw)	//width=0                                  //~va30R~
            {                                                      //~va30R~
		        pgeom->width=wwpango;                              //~va30R~
//		        pgeom->y_offset=0;                                 //~va30R~
                while (oldx<=0) { oldx+=wwpango; }                 //~va30R~
		        pgeom->x_offset=oldx;                              //~va30R~
	            w0ctr++;                                           //~va30R~
            }                                                      //~va30R~
            else                                                   //~va30R~
            if (w0ctr)  //after combining char                     //~va30R~
            {                                                      //~va30R~
                w0ctr=0;                                           //~va30R~
            }                                                      //~va30R~
#else                                                              //~vbk4I~
#ifdef SSS                                                         //~vbkwI~
            ;                                                      //~vbk4I~
#else                                                              //~vbkwI~
        	if (Popt & USMSO_SBCSCOMBSPLIT  //sbcs combining       //~vbkwR~
    		&& pglyphstr->num_glyphs==2     //show 2 glyph         //~vbkwI~
            )                                                      //~vbkwI~
            {                                                      //~vbkwI~
				if (ii==2)                        //1st plyph      //~vbkwI~
                {                                                  //~vbkwI~
                    pgeomnext=&((pglyphinfo+1)->geometry);         //~vbkwR~
                    nextwidth=pgeomnext->width;                    //~vbkwR~
                    UTRACEP("%s:SBCSCOMBSPLIT nextW=%d,nextoffs=%d,currW=%d,curroffs=%d,oldw=%d\n",UTT,nextwidth,pgeomnext->x_offset,oldw,pgeom->x_offset,oldw);//~vbkwR~
                    if (!nextwidth)                                //~vbkwR~
                    {                                              //~vbkwR~
                        if (oldw<wwpango)                          //~vbkwR~
                        {                                          //~vbkwI~
                            pgeom->width=oldw;	//org width        //~vbkwR~
                            pgeomnext->width=wwpango-oldw; //2nd by remaining//~vbkwI~
                        }                                          //~vbkwI~
                        else                                       //~vbkwR~
                        {                                          //~vbkwI~
                            pgeom->width=wwpango;                  //~vbkwR~
                        }                                          //~vbkwI~
                        UTRACEP("%s:SBCSCOMBSPLIT modified nextW=%d,nextoffs=%d,currW=%d,curroffs=%d\n",UTT,pgeomnext->width,pgeomnext->x_offset,pgeom->width,pgeom->x_offset);//~vbkwR~
                    }                                              //~vbkwR~
                }                                                  //~vbkwI~
            }                                                      //~vbkwI~
#endif  //SSS                                                      //~vbkwR~
#endif                                                             //~vbk4I~
        }                                                          //~va30R~
        else                                                       //~va30R~
        if (Popt & USMSO_COMBINEON)	//combine width 0 char         //~va30R~
        {                                                          //~va30R~
//          if (!oldw)	//width=0                                  //~va30R~//~vbk4R~
            if (swcombine)	//combining char; wcwidth=0 && pgeom->width!=0//~vbk4I~
            {                                                      //~va30R~
//  	        pgeom->x_offset=oldx;	//keep original            //~va30R~//~vbk4R~
//  	        pgeom->width=0;	//keep original                    //~va30R~//~vbk4R~
            	if (!w0ctr)	//combine start                        //~va30R~
                {                                                  //~va30R~
                    combspan=0;                                    //~va30R~
                	swtoperr=(glyphctr==1);	//err if str top is combine chae//~va30R~
                    if (swtoperr)                                  //~va30R~
                    {                                              //~va30R~
//  	        		pgeom->x_offset+=wwpango;	//offset from next cell right boundary//~va30R~//~vbk4R~
//  	        		pgeom->width=wwpango;                      //~va30R~//~vbm6R~
    	        		pgeom->width=wwpango*dbcssz;               //~vbm6I~
                    }                                              //~va30R~
                    else                                           //~va30R~
                    	combspan=wwpango;	//span to skip to net no combining char//~va30R~
                }                                                  //~va30R~
                else	//2nd combining                            //~va30R~
                {                                                  //~va30R~
//                  combspan+=wwpango;  //span to next noncombining char//~va30R~//~vbm6R~
                    combspan+=wwpango*dbcssz;  //span to next noncombining char//~vbm6I~
//                  if (swtoperr)                                  //~va30R~//~vbk4R~
//                      pgeom->x_offset+=wwpango;                  //~va30R~//~vbk4R~
                }                                                  //~va30R~
//		        pgeom->y_offset=0;                                 //~va30R~
              if (!swtoperr)                                       //~vbk4I~
              {                                                    //~vbk4I~
	            w0ctr++;                                           //~va30R~
#ifndef AAA   //combine to offset=pgeom->x_offset of base          //~vbk4R~
    	        pgeom->x_offset=combbase_offs;	//back to abse char//~vbk4R~
#else        //combine to base char cell                           //~vbk4I~
    	        pgeom->x_offset=-w0ctr*wwpango;	//back to abse char//~vbk4I~
#endif                                                             //~vbk4I~
//              combbase_offs+=oldw-wwpango;                       //~vbk4R~//~vbm4R~
                combbase_offs+=oldw-pgeom->width;                  //~vbm4I~
              }                                                    //~vbk4I~
            }                                                      //~va30R~
            else    //not combining char                           //~va30R~
//          if (w0ctr)  //next of non combining                    //~va30R~//~vbk4R~
            {                                                      //~va30R~
//  	        pgeom->width=combspan+wwpango;	//for width0 and itself//~va30R~//~vbk4R~
//		        pgeom->x_offset=pgeom->width-neww+(neww-oldw)/2;   //~va30R~//~vbk3R~
//		        pgeom->x_offset=pgeom->width-neww;                 //~vbk3I~//~vbk4R~
                w0ctr=0;                                           //~va30R~
//            	combbase_offs=oldw-wwpango;	//end pixel of combining base char//~vbk4R~//~vbm4R~
              	combbase_offs=oldw-pgeom->width;	//end pixel of combining base char//~vbm4I~
            }                                                      //~va30R~
        }                                                          //~va30R~
UTRACEP("%s pgeom=%p,new glyphctr=%d swcombine=0x%x,width=%d-->%d,offsx=%d,offsy=%d,combspan=%d,combbase_offs=%d,swtoperr=%d\n",UTT,pgeom,glyphctr,swcombine,oldw,pgeom->width,pgeom->x_offset,pgeom->y_offset,combspan,combbase_offs,swtoperr);//~va30R~//~vbk4R~//~vbkuR~//~vbm1R~
		wwtotal+=pgeom->width;                                     //~va30R~
#ifdef AAA                                                         //~va1cR~
#ifdef UTF8SUPPH                                                   //~va1cR~
        if (dbcssz>UDBCSCHK_DBCSSZ) //3 or 4 byte dbcs             //~va1cR~
        {                                                          //~va1cR~
UTRACEP("dbcs3/4 ii=%d\n",ii);                                     //~va1cR~
    		pglyphinfo++;                                          //~va1cR~
        	pgeom=&(pglyphinfo->geometry);                         //~va1cR~
	    	pgeom->width=Pcellw*PANGO_SCALE;                       //~va1cR~
            ii--;                                                  //~va1cR~
	        if (dbcssz=UDBCSCHK_GB4SZ) //4 byte dbcs               //~va1cR~
            {                                                      //~va1cR~
UTRACEP("dbcs4 ii=%d\n",ii);                                       //~va1cR~
	    		pglyphinfo++;                                      //~va1cR~
    	    	pgeom=&(pglyphinfo->geometry);                     //~va1cR~
	    		pgeom->width=Pcellw*PANGO_SCALE;                   //~va1cR~
	            ii--;                                              //~va1cR~
            }                                                      //~va1cR~
        }                                                          //~va1cR~
#endif                                                             //~va1cR~
#endif	//AAA                                                      //~va1cR~
    }                                                              //~vX03M~
    tmp_list=tmp_list->next;                                       //~v69VI~
  }//runs                                                          //~v69VI~
  	if (glyphctr<Plen	//ligatured occured                        //~va30R~
    &&  glyphctr                                                   //~va30R~
    &&  Popt & USMSO_COMBINESP	//add space whe ligture occued     //~va30R~
    )                                                              //~va30R~
    {                                                              //~va30R~
  		pgeomlast->width=Plen*wwpango-wwtotal;                     //~va30R~
		UTRACEP("geometry last width after ligature width=%d,glyphctr=%d,len=%d\n",pgeomlast->width,glyphctr,Plen);//~va30R~
    }                                                              //~va30R~
  	pango_layout_iter_free (iter);                                 //~vX03M~
    UTRACELAYOUT(Pplayout);                                        //~vbk4I~
    UTRACEP("%s:return\n",UTT);                                    //~vbk4I~
  	return;                                                        //~vX03M~
}//usetmonospace                                                   //~vX03I~
#ifndef JJJ                                                        //~vbm8R~
//===============================================================================//~vbm8I~
//set monospaceing  for combine str under Ligature:Off             //~vbm8I~
//Ppdata:dddata if Popt & USMSO_DDFMT not used                     //~vbm8I~
//       else u8 or lcdata and used                                //~vbm8I~
//Ppdbcs:lcdbcs,Plen:lclen                                         //~vbm8I~
//return shrink/oveflow of cells zie                               //~vbm8I~
//===============================================================================//~vbm8I~
int usetmonospaceCombineStr(int Popt,PangoLayout *Pplayout,char *Ppdata,char *Ppdbcs,int Plen,int Pcellw)//~vbm8R~
{                                                                  //~vbm8I~
  	GSList *tmp_list;                                              //~vbm8I~
  	PangoLayoutIter *iter;                                         //~vbm8I~
    PangoLayoutLine *line;                                         //~vbm8I~
    PangoLayoutRun *run;                                           //~vbm8I~
    PangoGlyphString *pglyphstr;                                   //~vbm8I~
    PangoGlyphInfo *pglyphinfo;                                    //~vbm8I~
    PangoGlyphGeometry *pgeom;                                     //~vbm8I~
    PangoGlyphGeometry *pgeomlast=0;                               //~vbm8I~
    char *pdbcs,*pdata;                                            //~vbm8R~
	int ii,swdbcs,dbcssz, wwpango,glyphctr=0,wwtotal=0,combineshrink;//~vbm8R~
//******************************                                   //~vbm8I~
  	iter = pango_layout_get_iter(Pplayout);                        //~vbm8I~
    line=pango_layout_iter_get_line (iter);                        //~vbm8I~
    if (!line)  //split dbcs is set to layout                      //~vbm8I~
        return 0;                                                  //~vbm8R~
    tmp_list=line->runs;                                           //~vbm8I~
UTRACEP("%s:Popt=0x%x,layout=%p,opt=%x,len=%d,iter=%p,line=%p,runs=%p\n",UTT,Popt,Pplayout,Popt,Plen,iter,line,tmp_list);//~vbm8R~
UTRACED("Ppdata dddata or u8 by swutf8data",Ppdata,Plen);          //~vbm8I~
UTRACED("Ppdata lcdbcs",Ppdbcs,Plen);                              //~vbm8I~
	wwpango=Pcellw*PANGO_SCALE;                                    //~vbm8M~
  pdata=Ppdata;                                                    //~vbm8I~
  pdbcs=Ppdbcs;                                                    //~vbm8I~
  while(tmp_list)                                                  //~vbm8I~
  {                                                                //~vbm8I~
    run=tmp_list->data;                                            //~vbm8I~
UTRACEP("run=%p\n",run);                                           //~vbm8I~
    if (!run)  //split dbcs is set to layout                       //~vbm8I~
        return 0;                                                  //~vbm8R~
    pglyphstr=run->glyphs;                                         //~vbm8I~
    if (!pglyphstr)  //split dbcs is set to layout                 //~vbm8I~
        return 0;                                                  //~vbm8R~
UTRACEP("temp list=%p\n",pglyphstr);                               //~vbm8I~
    for (ii=pglyphstr->num_glyphs,pglyphinfo=pglyphstr->glyphs;ii>0;ii--,pglyphinfo++)//~vbm8I~
    {                                                              //~vbm8I~
        glyphctr++;                                                //~vbm8I~
        pgeom=&(pglyphinfo->geometry);                             //~vbm8I~
        pgeomlast=pgeom;                                           //~vbm8I~
UTRACEP("%s:geometry ii=%d/%d,wwtotal=%d,offs_x=%d,offs_y=%d,width=%d cellw=%d\n",UTT,ii,pglyphstr->num_glyphs,wwtotal,pgeom->x_offset,pgeom->y_offset,pgeom->width,Pcellw);//~vbAeI~
	 if (0)   //do nothing                                         //~vbAeR~
        if (pgeom->width==0)	//width0 ,combining                //~vbAeI~
        {                                                          //~vbAeI~
			if (pglyphstr->num_glyphs-ii>=3) //3 glyph prev of width0//~vbAeI~
            {                                                      //~vbAeI~
			    PangoGlyphInfo *pglyphinfo_p1=pglyphinfo-1;        //~vbAeR~
			    PangoGlyphInfo *pglyphinfo_p2=pglyphinfo-2;        //~vbAeR~
			    PangoGlyphGeometry *pgeom_p1=&(pglyphinfo_p1->geometry);//~vbAeI~
			    PangoGlyphGeometry *pgeom_p2=&(pglyphinfo_p2->geometry);//~vbAeI~
				UTRACEP("%s:geometry ii=%d,p1;offs_x=%d,offs_y=%d,width=%d\n",UTT,ii,pgeom_p1->x_offset,pgeom_p1->y_offset,pgeom_p1->width);//~vbAeI~
				UTRACEP("%s:geometry ii=%d,p2;offs_x=%d,offs_y=%d,width=%d\n",UTT,ii,pgeom_p2->x_offset,pgeom_p2->y_offset,pgeom_p2->width);//~vbAeI~
				if (pgeom_p1->width!=0 && pgeom_p2->width==0)	//base+comb+dummybase for cont combining(?)+comb//~vbAeI~
                {                                                  //~vbAeI~
			        wwtotal-=pgeom_p1->width;                      //~vbAeI~
					int offp2=pgeom_p1->width+pgeom->x_offset;  //2nd combining offs from 0//~vbAeR~
					pgeom_p1->width=0;                             //~vbAeM~
					pgeom->x_offset=-offp2;                        //~vbAeI~
            	}                                                  //~vbAeI~
				UTRACEP("%s:geometry ii=%d,p1;offs_x=%d,offs_y=%d,width=%d\n",UTT,ii,pgeom_p1->x_offset,pgeom_p1->y_offset,pgeom_p1->width);//~vbAeI~
            }                                                      //~vbAeI~
        }                                                          //~vbAeI~
        wwtotal+=pgeom->width;                                     //~vbm8I~
UTRACEP("%s:geometry ii=%d/%d,wwtotal=%d,offs_x=%d,offs_y=%d,width=%d cellw=%d\n",UTT,ii,pglyphstr->num_glyphs,wwtotal,pgeom->x_offset,pgeom->y_offset,pgeom->width,Pcellw);//~vbm8R~//~vbAeR~
        swdbcs=(*pdbcs==UDBCSCHK_DBCS1ST);                         //~vbm8R~
		dbcssz=1+swdbcs;	//sbcs                                 //~vbm8I~
        pdata+=dbcssz; //print width is 2 column but data is 3-4 byte//~vbm8R~
        pdbcs+=dbcssz; //after 3/4 byte dbcs "." is padded by csublocale2utfscr//~vbm8R~
    }                                                              //~vbm8I~
    tmp_list=tmp_list->next;                                       //~vbm8I~
  }//runs                                                          //~vbm8I~
  	combineshrink=Plen*wwpango-wwtotal;                            //~vbm8I~
  if (pgeomlast)                                                   //~vbz6I~
  {                                                                //~vbz6I~
    if (combineshrink>0)                                           //~vbm8I~
    {                                                              //~vbm8I~
  		pgeomlast->width+=combineshrink;                           //~vbm8R~
		UTRACEP("%s:geometry last width after ligature width=%d,x_offset=%x\n",UTT,pgeomlast->width,pgeomlast->x_offset);//~vbm8R~
    }                                                              //~vbm8I~
    else                                                           //~vbm8I~
    {                                                              //~vbm8I~
  		pgeomlast->x_offset=combineshrink;                         //~vbm8I~
		UTRACEP("%s:geometry last width after ligature width=%d,x_offset=%x\n",UTT,pgeomlast->width,pgeomlast->x_offset);//~vbm8I~
    }                                                              //~vbm8I~
  }                                                                //~vbz6I~
  	pango_layout_iter_free(iter);                                  //~vbm8R~
    UTRACELAYOUT(Pplayout);                                        //~vbm8I~
    UTRACEP("%s:return combineshrink=%d\n",UTT,combineshrink);     //~vbm8R~
  	return combineshrink;                                          //~vbm8R~
}//usetmonospaceCombineStr                                         //~vbm8I~
#endif //JJJ                                                       //~vbm8I~
//===============================================================================//~va3iI~
//set monospaceing for ligature mode (utf8 file)                   //~va3iI~
//leave spacing to pango                                           //~va3iI~
//  except, adjust last for next string column position            //~va3iI~
//  (combining char under nocombine mode is split by color attr at xefile23)//~va3iI~
//===============================================================================//~va3iI~
int usetmonospace_ligature(int Popt,PangoLayout *Pplayout,         //~va3iR~
							char *Ppdataxx/*not used*/,char *Ppdbcsxx/*lc dbcs*/,//~va3iI~//~vamgR~
//							int Plen/*column width*/,int Pcellw)   //~vb4AR~
  							int Plen/*column width*/,int Pcellw,int *Ppstrwidth)//~vb4AI~
{                                                                  //~va3iI~
  	GSList *tmp_list;                                              //~va3iI~
  	PangoLayoutIter *iter;                                         //~va3iI~
    PangoLayoutLine *line;                                         //~va3iI~
    PangoLayoutRun *run;                                           //~va3iI~
    PangoGlyphString *pglyphstr;                                   //~va3iI~
    PangoGlyphInfo *pglyphinfo;                                    //~va3iI~
    PangoGlyphGeometry *pgeom=NULL,*pgeomlast=NULL;                //~vaffR~
    int ii,wwpango,glyphctr=0,wwtotal=0,wwglyph;                   //~va3iR~
#ifdef GGG                                                         //~vbAhI~
    int diff,ccoffs,difftotal;                                     //~va3uR~
#else                                                              //~vbAhI~
    int diff,difftotal;                                            //~vbAhI~
#endif                                                             //~vbAhI~
    char *pdbcs;                                                   //~vamgI~
    int wwtotaldbcs=0,dbcsstep,dbcscols=0,swsbcsonly;              //~vamgI~
//  int strwidth;                                                  //~vb4AI~//~vb5eR~
	int rc_wwtotal;                                                //~vb5hI~
#ifdef GGG                                                         //~vbAhI~
#ifdef SSS                                                         //~vbkwI~
#else                                                              //~vbkwI~
    PangoGlyphGeometry *pgeomnext;                                 //~vbkwI~
    int nextwidth;                                                 //~vbkwI~
#endif //SSS                                                       //~vbkwI~
#endif //GGG                                                       //~vbAhI~
    int glyphstrctr=0;                                             //~vbkwI~//~vbmpR~
//******************************                                   //~va3iI~
  	iter = pango_layout_get_iter(Pplayout);                        //~va3iI~
    line=pango_layout_iter_get_line (iter);                        //~va3iI~
//dprintf("usetmonospace_ligature opt=%x,len=%d\n",Popt,Plen);       //~va3iI~//~vamtR~
    if (!line)  //split dbcs is set to layout                      //~va3iI~
        return 4;                                                  //~va3iR~
    tmp_list=line->runs;                                           //~va3iI~
UTRACEP("usetmonospace_ligature opt=%x,len=%d,layout=%p,line=%p,runs=%p\n",Popt,Plen,Pplayout,line,tmp_list);       //~va3iR~//~var8R~
UTRACED("usetmonospace_ligature Pdbcs",Ppdbcsxx,Plen);             //~vam0I~//~vbAhM~
//dprintf("list@@@=%p\n",tmp_list);                                //~va3iI~
	wwpango=Pcellw*PANGO_SCALE;                                    //~va3iI~
    pdbcs=Ppdbcsxx;                                                //~vamgR~
    int swPadded=0;                                                //~vbAhI~
  	while(tmp_list)                                                //~va3iI~
  	{                                                              //~va3iI~
    	run=tmp_list->data;                                        //~va3iI~
UTRACEP("run=%p\n",run);                                           //~var8R~
    	if (!run)  //split dbcs is set to layout                   //~va3iI~
        	break;                                                 //~va3iI~
    	pglyphstr=run->glyphs;                                     //~va3iI~
    	if (!pglyphstr)  //split dbcs is set to layout             //~va3iI~
        	break;                                                 //~va3iI~
UTRACEP("%s:tmp list=%p,strctr=%d\n",UTT,pglyphstr,glyphstrctr);                               //~va3iI~//~vbmpR~
    	for (ii=pglyphstr->num_glyphs,pglyphinfo=pglyphstr->glyphs;ii>0;ii--,pglyphinfo++)//~va3iI~
    	{                                                          //~va3iI~
        	pgeom=&(pglyphinfo->geometry);                         //~va3iI~
        	pgeomlast=pgeom;                                       //~va3iI~
UTRACEP("%s:geometry ii=%d,offs_x=%d,offs_y=%d,width=%d cellw=%d\n",UTT,ii,pgeom->x_offset,pgeom->y_offset,pgeom->width,Pcellw);//~va3iI~//~vbAfR~
	    	wwglyph=pgeom->width;                                  //~va3iI~
#ifdef GGG  //3entry(dummybase+combining+dummy padding) manu\ipulate easer than 2entry(dummybase +combining)//~vbAhI~
#ifdef SSS                                                         //~vbkwI~
#else                                                              //~vbkwI~
        	if (Popt & USMSO_SBCSCOMBSPLIT  //sbcs combining under split mode//~vbkwI~
    		&& pglyphstr->num_glyphs==2     //show 2 glyph         //~vbkwI~
            )                                                      //~vbkwI~
            {                                                      //~vbkwI~
				if (ii==2)                        //1st plyph      //~vbkwI~
                {                                                  //~vbkwI~
                    pgeomnext=&((pglyphinfo+1)->geometry);         //~vbkwI~
                    nextwidth=pgeomnext->width;                    //~vbkwI~
                    UTRACEP("%s:SBCSCOMBSPLIT nextW=%d,nextoffs=%d,currW=%d,curroffs=%d\n",UTT,nextwidth,pgeomnext->x_offset,wwglyph,pgeom->x_offset);//~vbkwI~
                    if (!nextwidth)                                //~vbkwI~
                    {                                              //~vbkwI~
#ifdef AAA                                                         //~vbkwI~
                        if (wwglyph<wwpango)                       //~vbkwI~
                            wwglyph=pgeomnext->width=wwpango-wwglyph; //2nd by remaining//~vbkwR~
#endif                                                             //~vbkwI~
                        UTRACEP("%s:SBCSCOMBSPLIT modified nextW=%d,nextoffs=%d,currW=%d,curroffs=%d\n",UTT,pgeomnext->width,pgeomnext->x_offset,pgeom->width,pgeom->x_offset);//~vbkwI~
                    }                                              //~vbkwI~
                }                                                  //~vbkwI~
                UTRACEP("%s:SBCSCOMBSPLIT ii=%d,wwglyph=%d\n",UTT,ii,wwglyph);//~vbkwI~
            }                                                      //~vbkwI~
            else                                                   //~vbkwI~
#endif  //SSS                                                      //~vbkwI~
#endif // GGG                                                      //~vbAhI~
#ifdef GGG  //3entry(dummybase+combining+dummy padding) manu\ipulate easer than 2entry(dummybase +combining)//~vbAhI~
//          if (!wwglyph && !glyphctr)	//start with combining char//~va3iI~//~va3uR~
            if (!wwglyph)	//combining char                       //~va3uI~
          {                                                        //~vbm1I~
            if (!glyphctr	//start with combining char            //~va3uI~
            ||  (Popt & USMSO_COMBINEOF)	//split mode           //~va3uI~
            )                                                      //~va3uI~
            {                                                      //~va3iI~
            	ccoffs=pgeom->x_offset;			//offset from roght boundary of prev cell//~va3uM~
              if (ccoffs<0)                                        //~va3uI~
              {                                                    //~va3uI~
            		wwglyph=wwpango+ccoffs;	//offset is right end? //~va3uR~
            		pgeom->width=wwglyph;	//it may be combining char glyph size//~va3uI~
            		pgeom->x_offset=wwglyph;                       //~va3uR~
              }                                                    //~va3uI~
              else                                                 //~va3uI~
              {                                                    //~va3uI~
            	pgeom->width=wwglyph=wwpango;	//space for next char//~va3iR~
#ifdef AAA                                                         //~vbmfI~
            	pgeom->x_offset+=wwglyph;		//required to see it//~va3iR~
#endif                                                             //~vbmfR~
              }                                                    //~va3uI~
            	if (Popt & USMSO_COMBINEOF)	//split mode           //~va3uI~
//            		pgeom->y_offset=0;	//up when continued combining char//~va3uI~//~vbm0R~
            		pgeom->x_offset=0;	//up when continued combining char//~vbkwI~
                UTRACEP("%s:combine top glyphstrctr=%d,glyphctr=%d,geomwidth=%d\n",UTT,glyphstrctr,glyphctr,pgeom->width);//~vbmbR~
            }                                                      //~va3iI~
            else                                                   //~vbm1I~
            {	//COMBINE && not top                               //~vbm1I~
#ifdef BBB                                                         //~vbAfI~
#ifdef AAA                                                         //~vbmfI~
		      	if (*pdbcs==UDBCSCHK_DBCS1ST)  //require  2byte write for DBCS//~vbm1I~
            		wwglyph=wwpango;	//set half width           //~vbm1I~
              	else                                               //~vbm1I~
            		wwglyph=wwpango/2;	//set half width           //~vbm1I~
#else                                                              //~vbmfI~
   #ifdef AAA                                                      //~vbmpI~
            	wwglyph=wwpango;	//set half width               //~vbmfI~
   #else                                                           //~vbmpI~
                wwglyph=0;                                         //~vbmpI~
   #endif                                                          //~vbmpI~
#endif                                                             //~vbmfI~
            	pgeom->width=wwglyph;	//set half width           //~vbm1I~
            	pgeom->x_offset=0;		//required to see it       //~vbm1I~
#endif //BBB                                                       //~vbAfI~
                UTRACEP("%s:combine not top glyphstrctr=%d,glyphctr=%d,geomwidth=%d,offs=%d\n",UTT,glyphstrctr,glyphctr,pgeom->width,pgeom->x_offset);//~vbmbR~//~vbmpR~//~vbAfR~
            }                                                      //~vbm1I~
          }//width=0                                               //~vbm1I~
#endif // GGG                                                      //~vbAhI~
	    	if (Popt & USMSO_SPLITPADDED) //   0x2000 //split combining with dummy trailer padding//~vbAhI~
            	if ((glyphctr+1)==Plen)	//padded entry             //~vbAhI~
                {                                                  //~vbAhI~
                    UTRACEP("%s:ii=%d,break by last of option:SPLITPADDED\n",UTT,ii);//~vbAhR~
                	swPadded=1;                                    //~vbAhI~
                    break;                                         //~vbAhI~
                }                                                  //~vbAhI~
	    	wwtotal+=wwglyph;                                      //~va3iR~
            UTRACEP("%s:wwglyph=%d,wwtotal=%d\n",UTT,wwglyph,wwtotal);//~vbkwI~
        	glyphctr++;                                            //~va3iM~
            dbcsstep=1;                                            //~vamgI~
//            if (Popt & USMSO_DDFMT) //dbcs is ddfmt  -->dbcs is locale 1(p)2 fmt//~vamgR~
//            {                                                    //~vamgR~
//                if (UDBCSCHK_ISUCSDBCS(*pdbcs))                  //~vamgR~
//                {                                                //~vamgR~
//                    wwtotaldbcs+=wwglyph;                        //~vamgR~
//                    dbcsstep=2;                                  //~vamgR~
//                    dbcscols+=2;                                 //~vamgR~
//                    wwtotaldbcs+=wwglyph;                        //~vamgR~
//                }                                                //~vamgR~
//            }                                                    //~vamgR~
//            else                                                 //~vamgR~
		    if (*pdbcs==UDBCSCHK_DBCS1ST)  //require  2byte write for DBCS//~vamgI~
            {                                                      //~vamgI~
            	dbcsstep=UDBCSCHK_PCD_MBCHSZ(pdbcs,(Plen-PTRDIFF(pdbcs,Ppdbcsxx)));//~vamgR~
                dbcscols+=dbcsstep;                                //~vamgI~
		    	wwtotaldbcs+=wwglyph;                              //~vamgI~
            }                                                      //~vamgI~
            UTRACEP("%sdbcsid=x%02x,dbcscols=%d,wwglyph=%d,wwtotaldbcs=%d\n",UTT,*pdbcs,dbcsstep,wwglyph,wwtotaldbcs);//~vamgR~//~vbAfR~//~vbAhR~
            pdbcs+=dbcsstep;                                       //~vamgI~
UTRACEP("geometry gliphctr=%d, new width==%d offs==%d totalwidth=%d\n",glyphctr,pgeom->width,pgeom->x_offset,wwtotal);//~va3iR~//~va3uR~
        }                                                          //~va3iI~
        glyphstrctr++;                                             //~vbmbM~
    	tmp_list=tmp_list->next;                                   //~va3iI~
        if (swPadded)                                              //~vbAhI~
        	break;                                                 //~vbAhI~
  	}//runs                                                        //~va3iI~
    rc_wwtotal=wwtotal;                                            //~vb5hI~
    if (glyphctr)                                                  //~va3iI~
    {                                                              //~va3iI~
//		pgeomlast->width=Plen*wwpango-wwtotal;                     //~va3iI~//~va3uR~
	  if (swPadded)                                                //~vbAhI~
      {                                                            //~vbAhI~
  		diff=(Plen-1)*wwpango-wwtotal;                             //~vbAhI~
        if (diff>=0)    //cell is larger                           //~vbAhI~
        {                                                          //~vbAhI~
			UTRACEP("%s:geometry PADDED cell is large set diff=0.\n",UTT);//~vbAhI~
            diff=0;     //avoid expand combining char(erase just after combining at DrawSplitCombiningLigature)//~vbAhI~
        }                                                          //~vbAhI~
      }                                                            //~vbAhI~
      else                                                         //~vbAhI~
      {                                                            //~vbAhI~
  		diff=Plen*wwpango-wwtotal;                                 //~va3uI~
      }                                                            //~vbAhI~
      rc_wwtotal=wwtotal+diff;    //target width                   //~vbAhI~
UTRACEP("%s:geometry last before adjusted new width==%d offs==%d totalwidth=%d,diff=%d,rc_wwtotal=%d\n",UTT,pgeomlast->width,pgeom->x_offset,wwtotal,diff,rc_wwtotal);//~va3uI~//~vbAfR~//~vbAhR~
//      if (diff>0)                                                //~va3uI~//~vb5hR~
//  		pgeomlast->width=diff;                                 //~va3uI~//~vb5hR~
        if (diff>=0)                                               //~vb5hI~
    		pgeomlast->width+=diff;                                //~vb5hI~
        else // overflow, do monospacing                           //~va3uR~
        {                                                          //~va3uI~
        	swsbcsonly=(Plen-dbcscols)*wwpango<(wwtotal-wwtotaldbcs);//no need to dbcs adjust//~vamgI~
            UTRACEP("%s:usetmonospace_ligature adjusting sbcsonly=%d,wwtotaldbcs=%d,wwtotal=%d,Plen=%d,dbcscols=%d\n",UTT,swsbcsonly,wwtotaldbcs,wwtotal,Plen,dbcscols);//~vamgI~//~vbAfR~
//      	wwtotal=0;                                             //~va3uI~//~vbAhR~
    		tmp_list=line->runs;                                   //~va3uI~
            difftotal=-diff;                                       //~va3uR~
            pdbcs=Ppdbcsxx;                                        //~vamgR~
            swPadded=0;                                            //~vbAhI~
            while(tmp_list)                                        //~va3uI~
            {                                                      //~va3uI~
                run=tmp_list->data;                                //~va3uI~
                if (!run)  //split dbcs is set to layout           //~va3uI~
                    break;                                         //~va3uI~
                pglyphstr=run->glyphs;                             //~va3uI~
                if (!pglyphstr)  //split dbcs is set to layout     //~va3uI~
                    break;                                         //~va3uI~
                for (ii=pglyphstr->num_glyphs,pglyphinfo=pglyphstr->glyphs;ii>0;ii--,pglyphinfo++)//~va3uI~
                {                                                  //~va3uI~
                                                                   //~vamgI~
                    dbcsstep=1;                                    //~vamgI~
//                    if (Popt & USMSO_DDFMT) //dbcs is ddfmt      //~vamgR~
//                    {                                            //~vamgR~
//                        if (!UDBCSCHK_ISUCSSBCS(*pdbcs))         //~vamgR~
//                        {                                        //~vamgR~
//                            dbcsstep=2;                          //~vamgR~
//                        }                                        //~vamgR~
//                    }                                            //~vamgR~
//                    else                                         //~vamgR~
                    if (*pdbcs==UDBCSCHK_DBCS1ST)  //require  2byte write for DBCS//~vamgI~
                    {                                              //~vamgI~
                        dbcsstep=UDBCSCHK_PCD_MBCHSZ(pdbcs,(Plen-PTRDIFF(pdbcs,Ppdbcsxx)));//~vamgR~
                    }                                              //~vamgI~
                    pdbcs+=dbcsstep;                               //~vamgI~
                    pgeom=&(pglyphinfo->geometry);                 //~va3uI~
                    wwglyph=pgeom->width;                          //~va3uI~
                    int cellwidth=wwpango*dbcsstep;                //~vbAiI~
                    UTRACEP("usetmonospace_ligature adjusting ii=%d,dbcsstep=%d,glyphwidth=%d\n",ii,dbcsstep,wwglyph);//~vamgI~
                    if (dbcsstep>1 && swsbcsonly)                  //~vamgI~
                    	;                                          //~vamgI~
                    else                                           //~vamgI~
//                  if (wwglyph>wwpango)                           //~va3uI~//~vbAiR~
                    if (wwglyph>cellwidth)                         //~vbAiR~
                    {                                              //~va3uI~
//                      diff=wwglyph-wwpango;                      //~va3uI~//~vbAiR~
                        diff=wwglyph-cellwidth;                    //~vbAiI~
                        difftotal-=diff;                           //~va3uI~
UTRACEP("%s,geometry ii=%d,adjust old offs_x=%d,width=%d\n",UTT,ii,pgeom->x_offset,pgeom->width);//~va3uI~//~vbAfR~
//                      pgeom->width=wwpango;                      //~va3uI~//~vbAiR~
                        pgeom->width=cellwidth;                    //~vbAiI~
//                      if (pgeom->x_offset>wwpango)	//combining ch//~va3uI~//~vbAiR~
                        if (pgeom->x_offset>cellwidth)  //combining ch//~vbAiI~
//                          pgeom->x_offset=wwpango;               //~va3uI~//~vbAiR~
                            pgeom->x_offset=cellwidth;             //~vbAiI~
#ifdef BBB                                                         //~vbAhI~
                        else                                       //~vbAfI~
                            pgeom->x_offset-=diff/2;   //maybe visible//~vbAfR~
#endif                                                             //~vbAhI~
UTRACEP("%s:geometry ii=%d,adjust offs_x=%d,width=%d\n",UTT,ii,pgeom->x_offset,pgeom->width);//~va3uI~//~vbAfR~
                    }                                              //~va3uI~
//#ifdef AAA                                                       //~vbAfR~
//#else                                                            //~vbAfR~
//                    if (wwglyph==0 && pgeom->x_offset==0)    //combining glyph entry//~vbAfR~
//                    {                                            //~vbAfR~
//                        pgeom->x_offset=-wwpango;   //TODO test  //~vbAfR~
//                        UTRACEP("%s:geometry combining entry \n",UTT);//~vbAfR~
//                    }                                            //~vbAfR~
//#endif                                                           //~vbAfR~
//                  wwtotal+=wwglyph;                              //~va3uI~//~vbAhR~
//#ifdef AAA                                                       //~vbAfR~
                    if (difftotal<=0)                              //~va3uI~
//#else                                                            //~vbAfR~
//                    if (difftotal<0)                             //~vbAfR~
//#endif                                                           //~vbAfR~
                        break;                                     //~va3uI~
			    	if (Popt & USMSO_SPLITPADDED) //   0x2000 //split combining with dummy trailer padding//~vbAhI~
            			if (pgeom==pgeomlast)	//padded entry     //~vbAhI~
			            {                                          //~vbAhI~
                        	UTRACEP("%s:break by last of option:SPLITPADDED\n",UTT);//~vbAhR~
                			swPadded=1;                            //~vbAhI~
                    		break;                                 //~vbAhI~
                		}                                          //~vbAhI~
                }                                                  //~va3uI~
//#ifdef AAA                                                       //~vbAfR~
                if (difftotal<=0)                                  //~va3uI~
//#else                                                            //~vbAfR~
//                if (difftotal<0)                                 //~vbAfR~
//#endif                                                           //~vbAfR~
                    break;                                         //~va3uI~
                tmp_list=tmp_list->next;                           //~va3uI~
		        if (swPadded)                                      //~vbAhI~
        			break;                                         //~vbAhI~
            }//runs                                                //~va3uI~
			pgeomlast->width+=-difftotal;                          //~va3uR~
//  	    rc_wwtotal+=difftotal;                                 //~vb5hI~//~vbAfR~
// 	  	    rc_wwtotal=Plen*wwpango;                               //~vbAfI~//~vbAhR~
UTRACEP("%s:geometry last adjusted new width==%d offs==%d rc_wwtotal=%d,difftotal=%d\n",UTT,pgeomlast->width,pgeom->x_offset,rc_wwtotal,difftotal);//~va3uI~//~vbAfR~
        }                                                          //~va3uI~
    }                                                              //~va3iI~
  	pango_layout_iter_free (iter);                                 //~va3iI~
    if (Ppstrwidth)                                                //~vb4AI~
    {                                                              //~vb4AI~
//        if (Popt & USMSO_SPLITPADDED && glyphctr>1) //   0x2000 //split combining with dummy trailer padding//~vbAhR~
//        {                                                        //~vbAhR~
//            UTRACEP("%s:SPLITADD rc_wwtota=%d,last width=%d\n",UTT,rc_wwtotal,pgeomlast->width);//~vbAhR~
//            rc_wwtotal-=pgeomlast->width;                        //~vbAhR~
//        }                                                        //~vbAhR~
//      *Ppstrwidth=(wwtotal+PANGO_SCALE-1)/PANGO_SCALE;           //~vb4AR~//~vb5hR~
        *Ppstrwidth=(rc_wwtotal+PANGO_SCALE-1)/PANGO_SCALE;        //~vb5hI~
        UTRACEP("%s:set strwidth=%d,rc_wwtotal=%d\n",UTT,*Ppstrwidth,rc_wwtotal);//~vb4AR~//~vb5hR~//~vbAhR~
    }                                                              //~vb4AI~
    UTRACELAYOUT(Pplayout);                                        //~vbkwI~
    UTRACEP("%s:return\n",UTT);                                    //~vbAhI~
  	return 0;                                                      //~va3iI~
}//usetmonospace_ligature                                          //~va3iI~
//===============================================================================//~va6yI~
//!GTKPRINT                                                        //~vbAiI~
//get default printer  Mprinter_cupsdefault                        //~va6yI~
//rc:1: cups default ult defined                                   //~va6yI~
//===============================================================================//~va6yI~
int csubgetdefaultprinter(int Popt)                                //~va6yI~
{                                                                  //~2B03aI~//~va6yI~
    int pn,/*pn0,*/rc=0;                                               //~va6yI~//~vaa7R~
    int pn0;                                                       //~vagGI~
    cups_dest_t  *pl,*pl0;                                         //~va6yI~
//********************************                                 //~va6yI~
    dprintf("csubgetdefaultprinter\n");                            //~vam0I~
    UTRACEP("%s:entry\n",UTT);                                     //~vb7wI~
    *Mprinter_cupsdefault=0;                                       //~va6yI~
    pn0=                                                           //~vagGI~
    /*pn0=*/pn=cupsGetDests(&pl0);                                     //~va6yI~//~vaa7R~
//  dprintf("csubgetdefaultprinter getDest=%p\n",pn0);             //~vam0I~//~vbu0R~
    dprintf("csubgetdefaultprinter getDest=%d\n",pn0);             //~vbu0I~
    UTRACEP("%s:getDest=%p\n",UTT,pn0);                            //~vb7wI~
  if (pn)                                                          //~vagGI~
  {                                                                //~vagGI~
    dprintf("csubgetdefaultprinter:num dest=%d\n",pn);             //~vagGI~
    for (pl=pl0;pn>0;pn--,pl++)                                    //~va6yI~
    {                                                              //~va6yI~
    	dprintf("cups printer list=%s,isdefault=%d\n",pl->name,pl->is_default);//~va6yI~
    	UTRACEP("%s:cups printer list=%s,isdefault=%d\n",UTT,pl->name,pl->is_default);//~vb7wI~
        if (pl->is_default)                                        //~va6yI~
        {                                                          //~va6yI~
        	UstrncpyZ(Mprinter_cupsdefault,pl->name,sizeof(Mprinter_cupsdefault));//~va6yI~
            rc=1;                                                  //~va6yI~
    dprintf("csubgetdefaultprinter:default dest=%s\n",pl->name);   //~vagGI~
    UTRACEP("%s:default dest=%s\n",UTT,pl->name);                  //~vb7wI~
        }                                                          //~va6yI~
    }                                                              //~va6yI~
//  free(pl0);  //free printer list                                //~vagGR~
    cupsFreeDests(pn0,pl0);  //free printer list                   //~vagGR~
  }                                                                //~vagGI~
    UTRACEP("%s:exit rc=%d\n",UTT,rc);                             //~vb7wI~
    return rc;                                                     //~va6yI~
}//csubgetdefaultprinter                                           //~va6yR~
#ifdef GTKPRINT                                                    //~vam0I~
//===============================================================================//~vam0I~
//= get default printer using Gtk api                              //~vam0I~
//===============================================================================//~vam0I~
gboolean cb_enumprinter(GtkPrinter *Ppprinter,gpointer *Pudata)    //~vam0R~
{                                                                  //~vam0I~
	gboolean rc=FALSE;                                             //~vam0I~
    char *pdata;                                                   //~vam0R~
    const char *pname;                                             //~vam0I~
//*******************                                              //~vam0I~
    pdata=(char*)Pudata;                                           //~vam0R~
    pname=gtk_printer_get_name(Ppprinter);                         //~vam0I~
    UTRACEP("%s:%s,udata=%s,virtual=%d\n",UTT,pname,(pdata?pdata:"NULL"),gtk_printer_is_virtual(Ppprinter));//~vam0R~//~vbi7R~
    UTRACEP("%s:desc=%s,loc=%s,isdefault=%d,capability=%x\n",UTT,  //~vbi7I~
		gtk_printer_get_description(Ppprinter),gtk_printer_get_location(Ppprinter),//~vbi7I~//~vbj0R~
		gtk_printer_is_default(Ppprinter),                         //~vbi7I~//~vbj0R~
		gtk_printer_get_capabilities(Ppprinter));                    //~vbi7I~//~vbj0R~
    UTRACEP("%s:virtual=%d,pdf=%d,ps=%d,iconname=%s\n",UTT,gtk_printer_is_virtual(Ppprinter),//~vbAuI~
    	gtk_printer_accepts_pdf(Ppprinter),                        //~vbAuI~
    	gtk_printer_accepts_ps(Ppprinter),                         //~vbAuI~
    	gtk_printer_get_icon_name(Ppprinter));                     //~vbAuI~
    if (gtk_printer_is_virtual(Ppprinter))                         //~vbAuI~
    {                                                              //~vbAuI~
    	UTRACEP("%s:%s is virtual\n",UTT,pname);                   //~vbAuI~
    }                                                              //~vbAuI~
    else                                                           //~vbAuI~
    if (ustrstri(pname,"LPR"))   //print to LPR                    //~vbAuR~
    {                                                              //~vbAuI~
    	UTRACEP("%s:%s is not real printer\n",UTT,pname);          //~vbAuI~
    }                                                              //~vbAuI~
    else                                                           //~vbAuI~
    if (pdata)                                                     //~vam0R~
    {                                                              //~vam0I~
        if (!strcmp(pdata,DEF_PRINTER)                             //~vam0R~
        &&  gtk_printer_is_default(Ppprinter))                     //~vam0I~
        {                                                          //~vam0I~
	        g_object_ref(Ppprinter);                               //~vam0I~
            SsrchprinterGtk=Ppprinter;                             //~vam0I~
            rc=TRUE;    //stop enum                                //~vam0I~
        }                                                          //~vam0I~
        if (!strcmp(pdata,GET_TOP_PRINTER)                         //~vam0R~
        &&  !gtk_printer_is_virtual(Ppprinter))                    //~vam0I~
        {                                                          //~vam0I~
	        g_object_ref(Ppprinter);                               //~vam0I~
            SsrchprinterGtk=Ppprinter;                             //~vam0I~
            rc=TRUE;    //stop enum                                //~vam0I~
        }                                                          //~vam0I~
        if (!strcmp(pdata,pname))                                  //~vam0R~
        {                                                          //~vam0I~
	        g_object_ref(Ppprinter);                               //~vam0I~
            SsrchprinterGtk=Ppprinter;                             //~vam0I~
            rc=TRUE;    //stop enum                                //~vam0I~
        }                                                          //~vam0I~
    }                                                              //~vam0I~
    else                                                           //~vam0I~
        if (gtk_printer_is_default(Ppprinter))                     //~vam0R~
        {                                                          //~vam0R~
            UTRACEP("%s:%s isdefault printer\n",UTT,pname);        //~vbAuI~
            g_object_ref(Ppprinter);                               //~vam0R~
            SdefaultprinterGtk=Ppprinter;                          //~vam0R~
            rc=TRUE;    //stop enum                                //~vam0R~
        }                                                          //~vam0R~
    return rc;                                                     //~vam0I~
}//csubenumprinter                                                 //~vam0I~
//===============================================================================//~vbi7I~
//= get default printer using Gtk api                              //~vbi7I~
//===============================================================================//~vbi7I~
gboolean cb_enumprinter2(GtkPrinter *Ppprinter,gpointer *Pudata)   //~vbi7I~
{                                                                  //~vbi7I~
static int Saccumlen;                                              //~vbi7R~
	gboolean rc=FALSE;                                             //~vbi7I~
    char *pdata,*pdatanew,**ppdata;                                //~vbi7I~
    const char *pname;                                             //~vbi7I~
    int len,leno;                                                  //~vbi7I~
//*******************                                              //~vbi7I~
    ppdata=(char**)Pudata; //initialy set to ""                    //~vbi7R~
    pdata=*ppdata;                                                 //~vbi7I~
    pname=gtk_printer_get_name(Ppprinter);                         //~vbi7I~
    UTRACEP("%s:%s,udata=%s,virtual=%d\n",UTT,pname,(pdata?pdata:"NULL"),gtk_printer_is_virtual(Ppprinter));//~vbj0I~
    UTRACEP("%s:desc=%s,loc=%s,isdefault=%d,capability=%x\n",UTT,  //~vbj0I~
		gtk_printer_get_description(Ppprinter),gtk_printer_get_location(Ppprinter),//~vbj0I~
		gtk_printer_is_default(Ppprinter),                         //~vbj0I~
		gtk_printer_get_capabilities(Ppprinter));                  //~vbj0I~
  if (!gtk_printer_is_virtual(Ppprinter)) //virtual if "to file"   //~vbj0I~
  {                                                                //~vbj0I~
    len=strlen(pname);                                             //~vbi7I~
    leno=Saccumlen;                                                //~vbi7R~
//  pdatanew=umalloc(leno+1+len+1);                                //~vbi7R~//~vbj0R~
    pdatanew=malloc(leno+1+len+1);                                 //~vbj0I~
    if (*pdata)                                                    //~vbi7R~
    {                                                              //~vbi7I~
    	memcpy(pdatanew,pdata,(size_t)leno);                       //~vbi7R~
    	memcpy(pdatanew+leno,pname,(size_t)len+1);                 //~vbi7R~
        Saccumlen+=len+1;                                          //~vbi7I~
    }                                                              //~vbi7I~
    else                                                           //~vbi7I~
    {                                                              //~vbi7I~
    	memcpy(pdatanew,pname,(size_t)len+1);                      //~vbi7I~
        Saccumlen=len+1;                                           //~vbi7R~
    }                                                              //~vbi7I~
    if (gtk_printer_is_default(Ppprinter))                         //~vbi7I~
	    Senumdefault=Senumctr;                                     //~vbi7I~
    Senumctr++;                                                    //~vbi7I~
    UTRACEP("%s:entry=%s,accum=%s\n",UTT,pname,pdatanew);          //~vbi7I~
    *ppdata=pdatanew;                                              //~vbi7I~
  }                                                                //~vbj0I~
    return rc;                                                     //~vbi7I~
}//csubenumprinter2                                                //~vbi7I~
//**************************************                           //~vam0I~
/*GtkPrinter*/void *csubgetdefaultprinterGtk()                     //~vam0R~
{                                                                  //~vam0I~
	GtkPrinterFunc pfunc;                                          //~vam0R~
//*******************                                              //~vam0I~
    UTRACEP("%s:entry\n",UTT);                                     //~vb7wI~
	SdefaultprinterGtk=NULL;                                       //~vam0I~
//	if (!csubgetdestctr())                                         //~vbi7R~
  	if (!csubiscupsavail())                                        //~vbi7I~
	    return NULL;                                               //~vat0I~
	pfunc=(GtkPrinterFunc)cb_enumprinter;                          //~vam0R~
    UTRACEP("%s:before enum\n",UTT);                               //~vb7wI~
	gtk_enumerate_printers(pfunc,NULL/*user data*/,NULL/*GdestroyNotify*/,TRUE/*wait*/);//~vam0R~
    UTRACEP("csubgetdefaultprinterGtk default=%s\n",(SdefaultprinterGtk?gtk_printer_get_name(SdefaultprinterGtk):"NULL"));//~vam0I~
    if (SdefaultprinterGtk)                                        //~vam0I~
    {                                                              //~vam0I~
        UstrncpyZ(Mprinter_cupsdefault,gtk_printer_get_name(SdefaultprinterGtk),sizeof(Mprinter_cupsdefault));//~vam0R~
//		csubgetcupspaperlistGtk(SdefaultprinterGtk);//var8test     //~var8R~
    }                                                              //~vam0I~
    else                                                           //~vam0I~
        *Mprinter_cupsdefault=0;                                   //~vam0I~
    UTRACEP("csubgetdefaultprinterGtk Mprinter_cupsdefault=%s\n",Mprinter_cupsdefault);//~vam0I~
    return SdefaultprinterGtk;                                     //~vam0I~
}//csubgetdefaultprinterGtk()                                      //~vam0I~
//**************************************************************************//~vam0R~
/*GtkPrinter*/void *csubsrchprinterGtk(char *Pprintername,char *Pprealname)//~vam0R~
{                                                                  //~vam0I~
	GtkPrinterFunc pfunc;                                          //~vam0I~
//*******************                                              //~vam0I~
	UTRACEP("%s:entry\n",UTT);                                     //~vb7wI~
    SsrchprinterGtk=NULL;                                          //~vam0I~
//if (csubgetdestctr())	//cups dest found                          //~vbi7R~
  if (csubiscupsavail())	//cups dest found                      //~vbi7I~
  {                                                                //~vat0I~
    pfunc=(GtkPrinterFunc)cb_enumprinter;                          //~vam0I~
	if (Pprintername)                                              //~vam0I~
    {                                                              //~vam0I~
		gtk_enumerate_printers(pfunc,Pprintername,NULL/*GdestroyNotify*/,TRUE/*wait*/);//~vam0I~
    	UTRACEP("csubsrchprinterGtk req=%s,SsrchprinterGtk=%s\n",Pprintername,(SsrchprinterGtk?gtk_printer_get_name(SsrchprinterGtk):"NULL"));//~vam0I~
    }                                                              //~vam0I~
    if (!SsrchprinterGtk)	//getdefault or parm printer not found //~vam0I~
		SsrchprinterGtk=csubgetdefaultprinterGtk();                //~vam0I~
    if (!SsrchprinterGtk)	//no default defined                   //~vam0I~
    {                                                              //~vam0I~
		gtk_enumerate_printers(pfunc,GET_TOP_PRINTER/*user data*/,NULL/*GdestroyNotify*/,TRUE/*wait*/);//~vam0I~
    	UTRACEP("csubsrchprinterGtk req=%s,SsrchprinterGtk=%s\n",Pprintername,(SsrchprinterGtk?gtk_printer_get_name(SsrchprinterGtk):"NULL"));//~vam0I~
    }                                                              //~vam0I~
  }                                                                //~vat0I~
    if (Pprealname)                                                //~vam0I~
    {                                                              //~vam0I~
	    *Pprealname=0;                                             //~vam0I~
    	if (SsrchprinterGtk)                                       //~vam0I~
	    	strcpy(Pprealname,gtk_printer_get_name(SsrchprinterGtk));//~vam0I~
    }                                                              //~vam0I~
//	csubgetcupspaperlistGtk(SsrchprinterGtk);//var8test            //~var8R~
    UTRACEP("csubsrchprinterGtk printer=%s backend=%p\n",(SsrchprinterGtk?gtk_printer_get_name(SsrchprinterGtk):"no printer"),(SsrchprinterGtk?gtk_printer_get_backend(SsrchprinterGtk):NULL));//~var8R~
    return SsrchprinterGtk;                                        //~vam0I~
}//csubsrchprinterGtk()                                            //~vam0I~
#endif   //!GTKPRINT                                               //~vam0I~
//===============================================================================//~vbp4I~
#ifdef NOPPD                                                       //~vbp4I~
//===============================================================================//~vbp4I~
//compare papersize name                                           //~vbp4I~
//rc:0:fullstring match,1:contains parm string,-1:unmatch          //~vbp4I~
//===============================================================================//~vbp4I~
int comparePaperSize(char *Pparm,char *Pname,char *Pdisplayname)   //~vbp4I~
{                                                                  //~vbp4I~
	int rc=1;//unmatch                                             //~vbp4I~
//*****************                                                //~vbp4I~
    if (!stricmp(Pparm,Pname)    //by display name                 //~vbp4I~
//  ||  (Pdisplayname && !stricmp(Pparm,Pdisplayname)))    //by display name//~vbp4I~
	)                                                              //~vbp4I~
    	rc=0;                                                      //~vbp4I~
    else                                                           //~vbp4I~
    {                                                              //~vbp4I~
    	if (USTRHEADIS_IC(Pname,"iso_"))                           //~vbp4I~
        	rc=stricmp(Pparm,Pname+4);                             //~vbp4I~
        else                                                       //~vbp4I~
    	if (USTRHEADIS_IC(Pname,"ppd_"))                           //~vbp4I~
        	rc=stricmp(Pparm,Pname+4);                             //~vbp4I~
        else                                                       //~vbp4I~
    	if (USTRHEADIS_IC(Pname,"na_"))                            //~vbp4I~
        	rc=stricmp(Pparm,Pname+3);                             //~vbp4I~
    }                                                              //~vbp4I~
    if (rc)                                                        //~vbp4I~
    {                                                              //~vbp4I~
    	rc=-1;                                                     //~vbp4I~
        if (ustrstri(Pname,Pparm))                                 //~vbp4I~
        	rc=1;	//partial match                                //~vbp4I~
        else                                                       //~vbp4I~
        if (Pdisplayname && ustrstri(Pdisplayname,Pparm))          //~vbp4I~
        	rc=1;                                                  //~vbp4I~
    }                                                              //~vbp4I~
    UTRACEP("comparepaperSize rc=%d,parm=%s,name=%s,display=%s\n",rc,Pparm,Pname,Pdisplayname);//~vbp4I~
    return rc;                                                     //~vbp4I~
}//comparePaperSize                                                //~vbp4I~
//=========================================================================//~vbp4I~
//=get papername from displayname                                  //~vbp4I~
//=========================================================================//~vbp4I~
const char *csub2_getcupspapername(char *Ppaperdisplayname)        //~vbp4I~
{                                                                  //~2B03aI~//~vbp4I~
	GList *gl,*gl0;                                                //~vbp4I~
    GtkPaperSize *pps;                                             //~vbp4I~
    const char *pdisplayname;                                      //~vbp4I~
    const char *pname;                                             //~vbp4I~
    int swfound=0;                                                 //~vbp4I~
//************************************                             //~vbp4I~
    gl0=gtk_paper_size_get_paper_sizes(FALSE);                     //~vbp4I~
//  Scupspaperlistsize=(int)g_list_length(gl0);                    //~vbp4R~
    for (gl=g_list_first(gl0);gl!=NULL;gl=gl->next)                //~vbp4I~
    {                                                              //~vbp4I~
    	pps=(GtkPaperSize*)gl->data;                               //~vbp4I~
        pdisplayname=gtk_paper_size_get_display_name(pps);         //~vbp4I~
        UTRACEP("xxecsub2.csub2_getcupspapername name=%s,displayname=%s\n",gtk_paper_size_get_name(pps),pdisplayname);//~vbp4I~
        if (!pdisplayname)                                         //~vbAvI~
        	continue;                                              //~vbAvI~
        if (!stricmp((void*)pdisplayname,Ppaperdisplayname))       //~vbp4I~
        {                                                          //~vbp4I~
	        pname=gtk_paper_size_get_name(pps);                    //~vbp4I~
            swfound=1;                                             //~vbp4I~
        	break;                                                 //~vbp4I~
        }                                                          //~vbp4I~
    }                                                              //~vbp4I~
    if (!swfound)                                                  //~vbp4I~
    	pname=NULL;                                                //~vbp4I~
    UTRACEP("csub2_getcupspapername name=%s\n",pname);             //~vbp4I~
    return pname;                                                  //~vbp4I~
}//csub2_getcupspapername                                          //~vbp4I~
//=========================================================================//~vbp4I~
//=get gtk paper displayname papername from cups paper name        //~vbp4I~
//=========================================================================//~vbp4I~
const char *csub2_getcupspapernameGtk(char *Pname,char **Pppname)  //~vbp4R~
{                                                                  //~2B03aI~//~vbp4I~
	GList *gl,*gl0;                                                //~vbp4I~
    GtkPaperSize *pps;                                             //~vbp4I~
    const char *pdisplayname;                                      //~vbp4I~
    const char *pname,*pc;                                         //~vbp4R~
    int swfound=0,rc;                                              //~vbp4R~
//************************************                             //~vbp4I~
    gl0=gtk_paper_size_get_paper_sizes(FALSE);                     //~vbp4I~
    for (gl=g_list_first(gl0);gl!=NULL;gl=gl->next)                //~vbp4I~
    {                                                              //~vbp4I~
    	pps=(GtkPaperSize*)gl->data;                               //~vbp4I~
        pdisplayname=gtk_paper_size_get_display_name(pps);         //~vbp4I~
        if (!pdisplayname)                                         //~vbAvI~
        	continue;                                              //~vbAvI~
        pname=gtk_paper_size_get_name(pps);                        //~vbp4I~
        *Pppname=(char*)pname;                                     //~vbp4R~
    	pc=strchr(Pname,'_');                                      //~vbp4R~
        if (pc)                                                    //~vbp4I~
	    	pc=strchr(pc+1,'_');                                   //~vbp4I~
        rc=pc && !memcmp(Pname,pname,(size_t)PTRDIFF(pc,Pname));   //~vbp4I~
//      if (!rc)                                                   //~vbp4I~
//      	rc=!memcmp(Pname,pname,strlen(pname));                 //~vbp4I~
        UTRACEP("xxecsub2.csub2_getcupspapernameGtk rc=%d,pc=%s,parm=%s,name=%s,displayname=%s\n",rc,pc,Pname,pname,pdisplayname);//~vbp4R~
        if (rc)                                                    //~vbp4R~
        {                                                          //~vbp4I~
            swfound=1;                                             //~vbp4I~
        	break;                                                 //~vbp4I~
        }                                                          //~vbp4I~
    }                                                              //~vbp4I~
    if (!swfound)                                                  //~vbp4I~
    	pdisplayname=NULL;                                         //~vbp4I~
    UTRACEP("csub2_getcupspapernameGtk parm=%s,rc=%s,Pppname=%s\n",Pname,pdisplayname,*Pppname);//~vbp4R~
    return pdisplayname;                                           //~vbp4I~
}//csub2_getcupspapernameGtk                                       //~vbp4I~
//************************************************************************************//~vbp4I~
cups_dest_t* csub2_cupsGetPPD(char *Pprinter,cups_dest_t **Ppdests,int *Ppctr)//~vbp4I~
{                                                                  //~vbp4I~
	cups_dest_t *dests,*dest;                                      //~vbp4I~
    //*******************                                          //~vbp4I~
    int ctr=cupsGetDests2(CUPS_HTTP_DEFAULT,&dests); /* Number of destinations *///~vbp4I~
    UTRACEP("%s:printer=%s,destCtr=%d\n",UTT,Pprinter,ctr);//~vbp4I~//~vbAiR~
    dest=cupsGetDest(Pprinter,NULL/*instancename*/,ctr,dests);     //~vbp4I~
    *Ppdests=dests;                                                //~vbp4I~
    *Ppctr=ctr;                                                    //~vbp4I~
    return dest;                                                   //~vbp4I~
}                                                                  //~vbp4I~
//************************************************************************************//~vbp4I~
void csub2_ppdClose(cups_dest_t *Pdests,int Pctr,http_t *Phttp,cups_dinfo_t *Pdinfo)//~vbp4I~
{                                                                  //~vbp4I~
    UTRACEP("xplnxp_ppdClose\n");                                  //~vbp4I~
    if (Pdests)                                                    //~vbp4I~
        cupsFreeDests(Pctr,Pdests);                                //~vbp4I~
	if (Phttp)                                                     //~vbp4I~
	    httpClose(Phttp);                                          //~vbp4I~
	if (Pdinfo)                                                    //~vbp4I~
	    cupsFreeDestInfo(Pdinfo);                                  //~vbp4I~
}                                                                  //~vbp4I~
//************************************************************************************//~vbp4I~
http_t* csub2_ppdOpenFile(cups_dest_t *Pdest,cups_dinfo_t **Ppdinfo)//~vbp4I~
{                                                                  //~vbp4I~
  	cups_dinfo_t  *dinfo;         /* Destination info */           //~vbp4I~
	http_t    *http;          /* Connection to destination */      //~vbp4I~
    //******************                                           //~vbp4I~
    UTRACEP("xplnxp_ppdOpenFile\n");                               //~vbp4I~
  	if ((http=cupsConnectDest(Pdest,0/*dflags*/,30000/*timeout*/, NULL, NULL, 0, NULL, NULL)) == NULL)//~vbp4I~
    	return NULL;                                               //~vbp4I~
  	dinfo=cupsCopyDestInfo(http,Pdest);                            //~vbp4I~
    *Ppdinfo=dinfo;                                                //~vbp4I~
    return http;                                                   //~vbp4I~
}                                                                  //~vbp4I~
//************************************************************************************//~vbp4I~
int getMediaCount(cups_dest_t *Pdest,http_t *Phttp,cups_dinfo_t *Pdinfo)//~vbp4I~
{                                                                  //~vbp4I~
	int ctr,flags=0;                                               //~vbp4I~
    //***********************                                      //~vbp4I~
	ctr=cupsGetDestMediaCount(Phttp,Pdest,Pdinfo,flags);           //~vbp4I~
	UTRACEP("getMediaCount mediaCtr=%d\n",ctr);                    //~vbp4I~
    return ctr;                                                    //~vbp4I~
}                                                                  //~vbp4I~
//************************************************************************************//~vbp4I~
//*ppd_sizet unit:point and,margin is not edge but left bottom origin coordination//~vbp4I~
//************************************************************************************//~vbp4I~
ppd_size_t *cupsSize2ppdSize(cups_size_t *Pcupssz/*unit=1/100mm*/,ppd_size_t *Pppdsz/*unit=point*/)//~vbp4R~
{                                                                  //~vbp4I~
	ppd_size_t *ppdsz;                                             //~vbp4I~
    //*********************************************                //~vbp4I~
    if (!Pppdsz)                                                   //~vbp4I~
		ppdsz=(ppd_size_t*)g_malloc(sizeof(ppd_size_t));           //~vbp4I~
    else                                                           //~vbp4I~
		ppdsz=Pppdsz;                                              //~vbp4I~
    strncpy(ppdsz->name,Pcupssz->media,sizeof(ppdsz->name));       //~vbp4I~
    ppdsz->width=MM2POINT(Pcupssz->width)/100;                     //~vbp4R~
    ppdsz->length=MM2POINT(Pcupssz->length)/100;                   //~vbp4R~
    ppdsz->top=MM2POINT(Pcupssz->top)/100;                         //~vbp4R~
    ppdsz->bottom=MM2POINT(Pcupssz->bottom)/100;                   //~vbp4R~
    ppdsz->left=MM2POINT(Pcupssz->left)/100;                       //~vbp4R~
    ppdsz->right=MM2POINT(Pcupssz->right)/100;                     //~vbp4R~
    ppdsz->marked=0;                                               //~vbp4I~
                                                                   //~vbp4I~
    ppdsz->right=ppdsz->width-ppdsz->right;	//right coordinate     //~vbp4I~
    ppdsz->top=ppdsz->length-ppdsz->top;	//top coordinate       //~vbp4R~
                                                                   //~vbp4I~
	UTRACEP("xxecsub2.cupsSize2ppdSize namd=%s w=%f,h=%f,l=%f,r=%f,t=%f,b=%f\n",ppdsz->name,ppdsz->width,ppdsz->length,ppdsz->left,ppdsz->right,ppdsz->top,ppdsz->bottom);//~vbp4R~
    return ppdsz;                                                  //~vbp4I~
#define MM2POINT(mm)    ((float)(mm)*360.0f/127.0f)      // 72/25.4 //1inch=72point=25.4mm//~vam3I~//~vbp4I~
}                                                                  //~vbp4I~
//************************************************************************************//~vbp4I~
//*size by point likeas ppdPageSize                                //~vbp4I~
//************************************************************************************//~vbp4I~
PageSize *getPageSize(cups_dest_t *Pdest,http_t *Phttp,cups_dinfo_t *Pdinfo,int *Ppctr)//~vbp4R~
{                                                                  //~vbp4I~
	int ii,count,flags=0,nondupctr=0;                              //~vbp4I~
    char dupchk[256]={0};                                          //~vbp4I~
  	cups_size_t   size;                                            //~vbp4R~
    PageSize *ppgsz,*ppgsz0;                                       //~vbp4I~
    ppd_size_t *ppdsz;                                             //~vbp4R~
    char *gtkname,*displayname,*displaynameByLocale;               //~vbp4R~
    //***********************                                      //~vbp4I~
	count = cupsGetDestMediaCount(Phttp,Pdest,Pdinfo,flags);       //~vbp4I~
	UTRACEP("getPageSize mediaCtr=%d\n",count);                    //~vbp4R~
    for (ii=0;ii<count;ii++)                                       //~vbp4I~
    {                                                              //~vbp4I~
    	if (cupsGetDestMediaByIndex(Phttp,Pdest,Pdinfo,ii,flags,&size))//~vbp4I~
        {                                                          //~vbp4I~
          	if (strcmp(dupchk,size.media))                         //~vbp4I~
            {                                                      //~vbp4I~
	        	UTRACEP("getPageSize  %s (%s)\n", size.media, cupsLocalizeDestMedia(Phttp,Pdest,Pdinfo,flags,&size));//~vbp4I~
                nondupctr++;                                       //~vbp4I~
	            strcpy(dupchk,size.media);                         //~vbp4I~
            }                                                      //~vbp4I~
        }                                                          //~vbp4I~
      	else                                                       //~vbp4I~
	        UTRACEP("getPageSize error");                          //~vbp4I~
    }                                                              //~vbp4I~
//  ppgsz0=ppgsz=(PageSize*)umalloc(SZ_PAGESIZE*nondupctr);        //~vbp4I~//~vbAuR~
    ppgsz0=ppgsz=(PageSize*)umalloc(SZ_PAGESIZE*(nondupctr+1)); //avoid null return//~vbAuI~
    *dupchk=0;                                                     //~vbp4I~
    for (ii=0;ii<count;ii++)                                       //~vbp4I~
    {                                                              //~vbp4I~
    	if (cupsGetDestMediaByIndex(Phttp,Pdest,Pdinfo,ii, flags,&size))//by 1/100mm//~vbp4R~
        {                                                          //~vbp4I~
          	if (strcmp(dupchk,size.media))                         //~vbp4I~
            {                                                      //~vbp4I~
                ppdsz=&ppgsz->ppdsz;                               //~vbp4M~
	        	cupsSize2ppdSize(&size,ppdsz);                     //~vbp4M~
//          	ppgsz->displayname=(char*)cupsLocalizeDestMedia(Phttp,Pdest,Pdinfo,flags,&size);//~vbp4R~
            	displayname=(char*)cupsLocalizeDestMedia(Phttp,Pdest,Pdinfo,flags,&size);//~vbp4I~
		        UTRACEP("xxecsub2.getPageSize displayname by cupsLocalizeDestMedia=%s for %s\n",displayname,ppdsz->name);//~vbp4R~
            	displaynameByLocale=(char*)csub2_getcupspapernameGtk(ppdsz->name,&gtkname);   //papername from displayname//~vbp4R~
                if (gtkname)                                       //~vbp4I~
	            	ppgsz->displayname=displaynameByLocale;        //~vbp4R~
                strncpy(ppdsz->name,displayname,sizeof(ppdsz->name));//~vbp4R~
		        UTRACEP("xxecsub2.getPageSize displayname by localename=%s,ppdname=%s\n",displaynameByLocale,ppdsz->name);//~vbp4R~
                ppgsz++;                                           //~vbp4I~
	            strcpy(dupchk,size.media);                         //~vbp4I~
            }                                                      //~vbp4I~
        }                                                          //~vbp4I~
    }                                                              //~vbp4I~
    *Ppctr=nondupctr;                                              //~vbp4I~
	UTRACEP("getPageSize nondupCtr=%d\n",nondupctr);               //~vbp4R~
    return ppgsz0;                                                 //~vbp4I~
}                                                                  //~vbp4I~
//************************************************************************************//~vbp4I~
//*size by point likeas ppdPageSize                                //~vbp4I~
//************************************************************************************//~vbp4I~
ppd_size_t *csub_ppdPageSize(cups_dest_t *Pdest,http_t *Phttp,cups_dinfo_t *Pdinfo,char *Pform)//~vbp4R~
{                                                                  //~vbp4I~
    PageSize *pPageSz,*pPageSz0;                                   //~vbp4I~
//  GtkPaperSize *pps=NULL;                                        //~vbp4R~
  	cups_size_t cupssize;                                          //~vbp4R~
    ppd_size_t *ppdsz,*ppdszFound=NULL;                            //~vbp4I~
	int ii,formno,partialmatchctr=0;                               //~vbp4I~
    const char *pname;                                             //~vbp4I~
    char *pdisplayname;                                            //~vbp4I~
    int flags;                                                     //~vbp4I~
    int rc2;                                                       //~vbp4R~
    //***********************                                      //~vbp4I~
    if (!Pform)                                                    //~vbp4I~
    {                                                              //~vbp4I~
    	flags=CUPS_MEDIA_FLAGS_DEFAULT;                            //~vbp4I~
    	if (cupsGetDestMediaDefault(Phttp,Pdest,Pdinfo,flags,&cupssize))//~vbp4R~
        	ppdsz=cupsSize2ppdSize(&cupssize,NULL/*ouputArea:null return g_malloc area*/);//~vbp4R~
        else                                                       //~vbp4I~
        	ppdsz=NULL;                                            //~vbp4I~
	    UTRACEP("xxecsub2.csub_ppdPageSize Pform=null ppdsz=%p",ppdsz);//~vbp4R~
        return ppdsz;                                              //~vbp4I~
    }                                                              //~vbp4I~
	pPageSz=pPageSz0=getPageSize(Pdest,Phttp,Pdinfo,&formno);      //~vbp4R~
	UTRACEP("xxecsub2.csub_ppdPageSize mediaCtr=%d\n",formno);     //~vbp4R~
    for (ii=formno;ii>0;ii--,pPageSz++)                            //~vbp4I~
    {                                                              //~vbp4I~
        pdisplayname=pPageSz->displayname;                         //~vbp4I~
        ppdsz=&(pPageSz->ppdsz);                                   //~vbp4I~
        pname=ppdsz->name;                                         //~vbp4I~
        UTRACEP("xxecsub2.csub_ppdPageSize name=%s,w=%f,h=%f,t=%f,b=%f,l=%f,r=%f\n",ppdsz->name,ppdsz->width,ppdsz->length,ppdsz->top,ppdsz->bottom,ppdsz->left,ppdsz->right);//~vbp4I~
        UTRACEP("csub_ppdPageSize parm=%s,displayname=%s\n",Pform,pdisplayname);//~vbp4R~
        UTRACEP("comp %s:%s-%s\n",Pform,pname,pdisplayname);       //~vbp4R~
        UTRACEP("ppd %s margin t=%f,b=%f,l=%f,r=%f\n",pname,       //~vbp4I~
                        ppdsz->length-ppdsz->top,ppdsz->bottom,    //~vbp4R~
                        ppdsz->left,ppdsz->width-ppdsz->right);    //~vbp4R~
        rc2=comparePaperSize(Pform,(char*)pname,(char*)pdisplayname);//~vbp4R~
        if (!rc2 || (rc2==1 && partialmatchctr==0))                //~vbp4I~
        {                                                          //~vbp4I~
            UTRACEP("csub_ppdPageSize paper found rc=%d,%s [\"%s\"]\n",rc2,pname,pdisplayname);//~vbp4R~
            UTRACEP("ww=%f,hh=%f point\n",ppdsz->width,ppdsz->length);//~vbp4R~
            UTRACEP("ppds margin t=%f,b=%f,l=%f,r=%f\n",ppdsz->top,ppdsz->bottom,ppdsz->left,ppdsz->right);//~vbp4R~
//TODO      pname=csub2_getcupspapername(pdisplayname);   //papername from displayname//~vbp4I~
//          pname=ppgsz->name;                                     //~vbp4I~
//          pps=gtk_paper_size_new(pname);                         //~vbp4R~
//          UTRACEP("xxecsub2.gaetPageSize pname=%s getname=%s displayname=%s\n",pname,gtk_paper_size_get_name(pps),gtk_paper_size_get_display_name(pps));//~vbp4I~
            ppdszFound=&(pPageSz->ppdsz);                          //~vbp4R~
          	if (!rc2)                                              //~vbp4I~
          	{                                                      //~vbp4I~
            	partialmatchctr=0;                                 //~vbp4I~
            	break;                                             //~vbp4I~
	        }                                                      //~vbp4I~
    	    if (rc2==1)                                            //~vbp4I~
        		partialmatchctr++;                                 //~vbp4I~
        }                                                          //~vbp4I~
    }                                                              //~vbp4I~
    if (partialmatchctr>1)                                         //~vbp4R~
    	ppdszFound=NULL;                                           //~vbp4I~
    if (ppdszFound)                                                //~vbp4I~
    {                                                              //~vbp4I~
    	ppdsz=g_malloc(sizeof(ppd_size_t));                        //~vbp4R~
    	memcpy(ppdsz,ppdszFound,sizeof(ppd_size_t));               //~vbp4R~
    }                                                              //~vbp4I~
    if (formno)                                                    //~vbp4R~
	    ufree(pPageSz0);                                           //~vbp4I~
    return ppdsz;                                                  //~vbp4R~
}                                                                  //~vbp4I~
#endif   //NOPPD                                                   //~vbp4I~
//===============================================================================//~va6yI~
//get default printer geometry,unit=mm                                     //~vamjR~//~vbp4R~
// return not coord but width of each direction                    //~vamjR~
//rc:4: err                                                        //~va6yI~
//===============================================================================//~va6yI~
//int csubgetcupspagesz(int Popt,RECT *Pprect,char *Pform)         //~vamjR~
int                                                                //~vamjI~
//csubgetcupspagesz(int Popt,RECT *Pprect,char *Pform,gdouble *Pptblr)//~vamjR~//~vampR~
csubgetcupspagesz(int Popt,RECT *Pprect,char *Pform)               //~vampI~
{                                                                  //~2B03aI~//~va6yI~
    int rc=0;                                                      //~va6yI~
#ifdef NOPPD                                                       //~vbp4M~
    char *pdest,*pform;                                            //~vbp4I~
    cups_dest_t *pppdnm,*destS;                                    //~vbp4M~
    int destCtr;                                                   //~vbp4M~
    http_t     *ppd;                                               //~vbp4M~
    cups_dinfo_t  *dinfo;                                          //~vbp4M~
#else                                                              //~vbp4M~
    char *pdest,*pppdnm,*pform;                                    //~va6yR~
    ppd_file_t *ppd;                                               //~va6yI~
#endif                                                             //~vbp4I~
    ppd_size_t *ppgsz;                                             //~va6yI~
    gdouble fmr,fml,fmt,fmb,fmw,fmh;                               //~va6yR~
//************************************                             //~va6yI~
    UTRACEP("cups margin inrect opt=%x,dest=%s,default=%s\n",Popt,Mprinter,Mprinter_cupsdefault);//~vam0R~
    Pprect->top=0;                                                 //~var8R~
    Pprect->left=0;                                                //~var3I~
    Pprect->bottom=0;                                              //~var3I~
    Pprect->right=0;                                               //~var3I~
//    if (Pptblr)                                                    //~vamjI~//~vampR~
//    {                                                              //~vamjI~//~vampR~
//        Pptblr[0]=0.0;                                             //~vamjI~//~vampR~
//        Pptblr[1]=0.0;                                             //~vamjI~//~vampR~
//        Pptblr[2]=0.0;                                             //~vamjI~//~vampR~
//        Pptblr[3]=0.0;                                             //~vamjI~//~vampR~
//    }                                                              //~vamjI~//~vampR~
//  if (strcmp(Mprinter,DEF_PRINTER) || !*Mprinter_cupsdefault)    //~va6yI~//~vbAuR~
    if ((strcmp(Mprinter,DEF_PRINTER) && strcmp(Mprinter,NO_CUPS_PRINTER)) || !*Mprinter_cupsdefault)//~vbAuI~
        pdest=Mprinter;                                            //~va6yI~
    else                                                           //~va6yI~
        pdest=Mprinter_cupsdefault;                                //~va6yI~
#ifdef NOPPD                                                       //~vbp4I~
    pppdnm=csub2_cupsGetPPD(pdest,&destS,&destCtr);	//dest         //~vbp4R~
#else                                                              //~vbp4I~
    pppdnm=(char *)cupsGetPPD((const char *)pdest);                //~va6yR~
    UTRACEP("cups margin inrect dest=%s,default=%s,ppd=%s\n",Mprinter,Mprinter_cupsdefault,pppdnm);//~vam0R~
#endif                                                             //~vbp4I~
    if (!pppdnm)                                                   //~va6yI~
    	return 4;                                                  //~va6yI~
#ifdef NOPPD                                                       //~vbp4I~
    ppd=csub2_ppdOpenFile(pppdnm,&dinfo);  //http                  //~vbp4I~
#else                                                              //~vbp4I~
    ppd=ppdOpenFile(pppdnm);                                       //~va6yR~
#endif                                                             //~vbp4I~
    if (!ppd)                                                      //~va6yI~
    	return 4;                                                  //~va6yI~
    pform=Pform;                                                   //~va6yR~
    if (!(pform))                                                  //~va6yR~
   		pform=Mformtype;                                           //~va6yR~
#ifdef NOPPD                                                       //~vbp4I~
    ppgsz=csub_ppdPageSize(pppdnm/*dest*/,ppd/*http*/,dinfo,pform);   //page size by point 72point/inch//~vbp4R~
#else                                                              //~vbp4I~
    ppgsz=ppdPageSize(ppd,pform);   //page size by point 72point/inch//~va6yR~
    if (!ppgsz)                                                    //~va6yI~
	    ppgsz=ppdPageSize(ppd,NULL);   //currentry seslected       //~va6yI~
#endif                                                             //~vbp4I~
    if (!ppgsz)                                                    //~va6yI~
    	rc=4;                                                      //~va6yR~
    else                                                           //~va6yI~
    {                                                              //~va6yI~
        UTRACEP("subgetcupspagesz top=%lf,left=%lf,bot=%lf,right=%lf,width=%lf,length=%lf\n",//~vam0I~
        ppgsz->top,ppgsz->left,ppgsz->bottom,ppgsz->right,ppgsz->width,ppgsz->length);//~vam0I~
      if (Popt & CGCPOHW)	//get width and height                 //~va6yI~
      {                                                            //~va6yI~
        if (ppgsz->bottom>ppgsz->top)                              //~va6yI~
        	fmt=ppgsz->top;                                        //~va6yR~
        else                                                       //~va6yI~
        	fmt=ppgsz->bottom;                                     //~va6yI~
        fml=ppgsz->left;                                           //~va6yI~
        fmr=ppgsz->width;                                          //~va6yI~
        fmb=ppgsz->length;                                         //~va6yI~
      }                                                            //~va6yI~
      else                                                         //~va6yI~
      {                                                            //~va6yI~
        fml=ppgsz->left;                                           //~va6yR~
        fmr=ppgsz->right;                                          //~va6yR~
        fmt=ppgsz->top;                                            //~va6yR~
        fmb=ppgsz->bottom;                                         //~va6yR~
        fmw=ppgsz->width;                                          //~va6yR~
        fmh=ppgsz->length;                                         //~va6yI~
//#ifdef GTKPRINT                                                  //~vamaR~
        fmr=fmw-fmr;		//up to form edge                      //~vam0I~
        if (fmt>fmb)                                               //~vam0I~
        	fmt=fmh-fmt;                                           //~vam0I~
        else                                                       //~vam0I~
        {                                                          //~vam0I~
        	fmt=fmb;                                               //~vam0I~
            fmb=fmh-ppgsz->top;                                    //~vamjR~
        }                                                          //~vam0I~
#ifdef DDD                                                         //~vamjI~
//get max because ldscape rotation depends printer                 //~vamhI~
        if (fmt>fmb)      //get max(fmb,fmt)                       //~vamaI~
        	fmb=fmt;                                               //~vamaI~
        else                                                       //~vamaI~
        	fmt=fmb;                                               //~vamaR~
        if (fmr>fml)      //get max(fml,fmr)                       //~vamaI~
        	fml=fmr;                                               //~vamaI~
        else                                                       //~vamaI~
        	fmr=fml;                                               //~vamaI~
#endif                                                             //~vamjI~
//#else                                                            //~vamaR~
//        fmr=fmw-fml-fmr;     //width-leftmargin-rightPos         //~vamaR~
//        if (fmr<0)                                               //~vamaR~
//            fmr=0;                                               //~vamaR~
//        if (fmt>fmb)                                             //~vamaR~
//        {                                                        //~vamaR~
//            fmb=fmh-fmb-fmt; //height-topmargin-bottomPos        //~vamaR~
//            if (fmb<0)                                           //~vamaR~
//                fmb=0;                                           //~vamaR~
//            fmt=ppgsz->bottom;                                   //~vamaR~
//        }                                                        //~vamaR~
//        else                                                     //~vamaR~
//        {                                                        //~vamaR~
//            fmb=fmh-fmt-fmb; //height-topmargin-bottomPos        //~vamaR~
//            if (fmb<0)                                           //~vamaR~
//                fmb=0;                                           //~vamaR~
//        }                                                        //~vamaR~
//#endif                                                           //~vamaR~
      }                                                            //~va6yI~
        fml=POINT2MM(fml);                                         //~va6yR~
        fmr=POINT2MM(fmr);                                         //~va6yR~
        fmt=POINT2MM(fmt);                                         //~va6yR~
        fmb=POINT2MM(fmb);                                         //~va6yR~
        Pprect->top =(int)(fmt+0.9999);                            //~va6yR~
        Pprect->left=(int)(fml+0.9999);                            //~va6yR~
        Pprect->bottom=(int)(fmb+0.9999);                          //~va6yR~
        Pprect->right =(int)(fmr+0.9999);                          //~va6yR~
        UTRACEP("csubgetcupspagesz form=%s,mark=%d,w=%lfmm,h=%lfmm,top=%d,left=%d,bot=%d,right=%d\n",//~vam0R~//~vbp4R~
            ppgsz->name,ppgsz->marked,POINT2MM(ppgsz->width),POINT2MM(ppgsz->length),Pprect->top,Pprect->left,Pprect->bottom,Pprect->right);//~va6yR~//~vam0R~
//        if (Pptblr)                                                //~vamjI~//~vampR~
//        {                                                          //~vamjI~//~vampR~
//            Pptblr[0]=fmt;                                         //~vamjI~//~vampR~
//            Pptblr[1]=fmb;                                         //~vamjI~//~vampR~
//            Pptblr[2]=fml;                                         //~vamjI~//~vampR~
//            Pptblr[3]=fmr;                                         //~vamjI~//~vampR~
//        }                                                          //~vamjI~//~vampR~
    }                                                              //~va6yI~
#ifdef NOPPD                                                       //~vbp4I~
    csub2_ppdClose(destS,destCtr,ppd,dinfo);                            //~vamuI~//~v970I~                   0//~vbp4I~
	if (ppgsz)                                                     //~vbp4I~
		g_free(ppgsz);                                             //~vbp4I~
#else                                                              //~vbp4I~
    ppdClose(ppd);                                                 //~va6yM~
#endif                                                             //~vbp4I~
    return rc;                                                     //~va6yR~
}//csubgetcupspagesz                                               //~va6yI~
//===============================================================================//~va6yI~
//get form supported by the printer                                //~vamtR~
//===============================================================================//~va6yI~
int csubgetcupsform(int Popt,char *Pprinter,char **Pppform,int *Ppformno,int *Ppentsz)//~va6yI~
{                                                                  //~2B03aI~//~va6yI~
#ifndef CCC //var8test                                              //~vamuM~//~var8R~
    int ii,entsz,formno;                                           //~va6yI~
#ifdef NOPPD                                                       //~vbp4I~
    char *pdest,*pform,*pform0;                                    //~vbp4I~
    cups_dest_t *pppdnm,*destS;                                    //~vbp4R~
    http_t     *ppd;                                               //~vbp4I~
    cups_dinfo_t  *dinfo;                                          //~vbp4I~
    int destCtr;                                                   //~vbp4I~
    PageSize *pPageSz,*pPageSz0;                                   //~vbp4I~
#else                                                              //~vbp4I~
    char *pdest,*pform,*pform0,*pppdnm;                            //~va6yR~
    ppd_file_t *ppd;                                               //~va6yI~
#endif                                                             //~vbp4I~
    ppd_size_t *ppgsz;                                             //~va6yI~
#else                                                              //~vamuI~
    int entsz,formno;                                              //~vamuI~
    char *pdest,*pform,*pform0;                                    //~vamuI~
    GtkPrinter *pprinter;                                          //~vamuI~
    GList *gl,*ppaperlist;                                         //~vamuR~
#endif                                                             //~vamuI~
    char *formnm;                                                  //~vbz8I~
//************************************                             //~va6yI~
//	csubgetcupspaperlistGtkName(Mprinter);	//var8test             //~var8R~
    UTRACEP("cupsgetcupsform parm printer=%s,Mprinter=%s,Mprinter_cupsdefault=%s\n",Pprinter,Mprinter,Mprinter_cupsdefault);//~vam0R~
    if (Pprinter)                                                  //~va6yI~
        pdest=Pprinter;                                            //~va6yI~
    else                                                           //~va6yI~
//  if (strcmp(Mprinter,DEF_PRINTER) || !*Mprinter_cupsdefault)    //~va6yI~//~vbAuR~
    if ((strcmp(Mprinter,DEF_PRINTER) && strcmp(Mprinter,NO_CUPS_PRINTER)) || !*Mprinter_cupsdefault)//~vbAuI~
        pdest=Mprinter;                                            //~va6yI~
    else                                                           //~va6yI~
        pdest=Mprinter_cupsdefault;                                //~va6yI~
#ifndef CCC                                                        //~vamtR~
#ifdef NOPPD                                                       //~vbp4I~
    pppdnm=csub2_cupsGetPPD(pdest,&destS/*to be freed*/,&destCtr);	//dest//~vbp4R~
    UTRACEP("xxecsub2.cupsgetcupsform dest=%s,default=%s,ppdnm=%p\n",Mprinter,Mprinter_cupsdefault,pppdnm);//~vbp4I~
#else                                                              //~vbp4I~
    pppdnm=(char *)cupsGetPPD((const char *)pdest);                //~va6yI~
    dprintf("cups margin inrect dest=%s,default=%s,ppd=%s\n",Mprinter,Mprinter_cupsdefault,pppdnm);//~va6yI~
#endif                                                             //~vbp4I~
    if (!pppdnm)                                                   //~va6yI~
    	return 4;                                                  //~va6yI~
#ifdef NOPPD                                                       //~vbp4I~
    ppd=csub2_ppdOpenFile(pppdnm,&dinfo);  //http                  //~vbp4I~
#else                                                              //~vbp4I~
    ppd=ppdOpenFile(pppdnm);                                       //~va6yI~
#endif                                                             //~vbp4R~
    if (!ppd)                                                      //~va6yI~
    	return 4;                                                  //~va6yI~
#ifdef NOPPD                                                       //~vbp4I~
	pPageSz0=pPageSz=getPageSize(pppdnm,ppd,dinfo,&formno);        //~vbp4R~
#else                                                              //~vbp4I~
    formno=ppd->num_sizes;                                         //~va6yI~
    ppgsz=ppd->sizes;                                              //~va6yR~
#endif                                                             //~vbp4I~
    if (!formno)                                                   //~va6yI~
    	return 4;                                                  //~va6yI~
    entsz=sizeof(ppgsz->name);                                     //~va6yR~
    pform=pform0=umalloc(formno*entsz);                            //~va6yR~
    memset(pform0,0,(size_t)(formno*entsz));                       //~vbp4I~
#ifdef NOPPD                                                       //~vbp4I~
    for (ii=formno;ii>0;ii--,pPageSz++,pform+=entsz)               //~vbp4I~
#else                                                              //~vbp4I~
    for (ii=formno;ii>0;ii--,ppgsz++,pform+=entsz)                 //~va6yI~
#endif                                                             //~vbp4I~
    {                                                              //~vam0I~
#ifdef NOPPD                                                       //~vbp4I~
    	ppgsz=&(pPageSz->ppdsz);                                   //~vbp4R~
//    	strncpy(pform,pPageSz->displayname,entsz);                 //~vbp4I~//~vbz8R~
		formnm=pPageSz->displayname;                               //~vbz8I~
        if (!formnm)                                               //~vbz8R~
			formnm=pPageSz->ppdsz.name;                            //~vbz8R~
		if (!formnm)                                               //~vbz8I~
        	continue;                                              //~vbz8I~
      	strncpy(pform,formnm,entsz);                               //~vbz8I~
#else                                                              //~vbp4I~
//    	memcpy(pform,ppgsz->name,entsz);	                       //~va6yI~//~vbz8R~
		formnm=ppgsz->name;                                        //~vbz8I~
		if (!formnm)                                               //~vbz8I~
        	continue;                                              //~vbz8I~
    	memcpy(pform,formnm,entsz);                                //~vbz8I~
#endif                                                             //~vbp4M~
        UTRACEP("csubgetcupsform name=%s,w=%f,h=%f,t=%f,b=%f,l=%f,r=%f\n",ppgsz->name,ppgsz->width,ppgsz->length,ppgsz->top,ppgsz->bottom,ppgsz->left,ppgsz->right);          //~vam0I~//~vamuR~
        dprintf("csubgetcupsform ii=%d,name=%s,w=%f,h=%f,t=%f,b=%f,l=%f,r=%f\n",ii,ppgsz->name,ppgsz->width,ppgsz->length,ppgsz->top,ppgsz->bottom,ppgsz->left,ppgsz->right);//~var8R~
    }                                                              //~vam0I~
#ifdef NOPPD                                                       //~vbp4I~
  if (pPageSz0)                                                    //~vbAuI~
	ufree(pPageSz0);                                               //~vbp4M~
    csub2_ppdClose(destS,destCtr,ppd,dinfo);                            //~vamuI~//~v970I~                   0//~vbp4I~
#else                                                              //~vbp4I~
    ppdClose(ppd);                                                 //~va6yI~
#endif                                                             //~vbp4I~
#else     //CCC                                                    //~vbp4R~
	pprinter=csubsrchprinterGtk(pdest,NULL);                       //~vamuI~
    ppaperlist=gtk_printer_list_papers(pprinter);  //from gtk2.12  //~vamuR~
    formno=g_list_length(ppaperlist);                              //~vamuR~
    UTRACEP("csubgetcupsform printer=%p,has_detail=%d,list#=%d\n",pprinter,gtk_printer_has_details(pprinter),formno);//~vamuR~
    if (!formno)	//var8test                                     //~var8R~
    {                                                              //~vamuI~
    	gtk_printer_request_details(pprinter);                     //~vamuI~
        UTRACEP("request details\n");                              //~vamuI~
    }    	                                                       //~vamuI~
    pform0=NULL;                                                   //~vamuI~
    if (formno)                                                    //~vamuI~
    {                                                              //~vamuI~
        entsz=PPDMAXNAME;                                          //~vamuI~
        pform=pform0=umalloc(formno*entsz);                        //~vamuI~
        for (gl=ppaperlist;gl!=NULL;gl=gl->next)                   //~vamuI~
        {                                                          //~vamuI~
            UTRACEP("csubgetcupsform data=%s\n",(char*)(gl->data));//~vamuI~
            UstrncpyZ(pform,gl->data,entsz);                       //~vamuI~
            pform+=entsz;                                          //~vamuI~
        }                                                          //~vamuI~
    }                                                              //~vamuI~
#endif                                                             //~vamuI~
    *Ppformno=formno;                                              //~va6yI~
    *Ppentsz=entsz;                                                //~va6yR~
    *Pppform=pform0;                                               //~va6yI~
    return 0;                                                      //~va6yI~
}//csubgetcupsform                                                 //~va6yI~
#ifdef GTKPRINT                                                    //~vamuI~
//===============================================================================//~vamuI~
//get default printer geometry                                     //~vamuI~
//rc:4: err                                                        //~vamuI~
//===============================================================================//~vamuI~
GtkPaperSize *csubgetpapersizeGtk_fromPPD(char *Pprinter,char *Ppform,PFRECT Ppmargin)//~vamuR~
{                                                                  //~2B03aI~//~vamuI~
    int ii=0,formno;                                               //~vamuI~
#ifdef NOPPD                                                       //~vbp4I~
    char *pdest;                                                   //~vbp4I~
    cups_dest_t *pppdnm,*destS;                                    //~vbp4I~
//  http_t     *ppd;                                               //~vbp4I~//~vbAuR~
    http_t     *ppd=NULL;                                          //~vbAuI~
    cups_dinfo_t  *dinfo;                                          //~vbp4I~
    int destCtr;                                                   //~vbp4I~
//  PageSize *pPageSz,*pPageSz0;                                   //~vbp4I~//~vbAuR~
    PageSize *pPageSz,*pPageSz0=NULL;                              //~vbAuI~
#else                                                              //~vbp4I~
    char *pdest,*pppdnm;                                           //~vamuR~
    ppd_file_t *ppd=NULL;                                          //~vamuI~
#endif                                                             //~vbp4I~
    ppd_size_t *ppgsz;                                             //~vamuI~
    GtkPaperSize *pps=NULL,*ppsa4=NULL;                            //~vamuR~
    FRECT   recta4={0.0,0.0,0.0,0.0};                              //~vamuI~
    FRECT   fmargins={0.0,0.0,0.0,0.0};                            //~vamuR~
    const char *pname;                                             //~vamuR~
//************************************                             //~vamuI~
    UTRACEP_FLUSH("%s:parm printer=%s,Mprinter=%s,Mprinter_cupsdefault=%s,form=%s\n",UTT,Pprinter,Mprinter,Mprinter_cupsdefault,Ppform);//~vamuI~//~vbAiR~
    if (Pprinter)                                                  //~vamuI~
        pdest=Pprinter;                                            //~vamuI~
    else                                                           //~vamuI~
//  if (strcmp(Mprinter,DEF_PRINTER) || !*Mprinter_cupsdefault)    //~vamuI~//~vbAuR~
    if ((strcmp(Mprinter,DEF_PRINTER) && strcmp(Mprinter,NO_CUPS_PRINTER)) || !*Mprinter_cupsdefault)//~vbAuI~//~vbAvR~
        pdest=Mprinter;                                            //~vamuI~
    else                                                           //~vamuI~
        pdest=Mprinter_cupsdefault;                                //~vamuI~
    UTRACEP_FLUSH("%s:dest=%s\n",UTT,pdest);                       //~vbAiI~
    for (;;)                                                       //~vamuI~
    {                                                              //~vamuI~
#ifdef NOPPD                                                       //~vbp4I~
    	pppdnm=csub2_cupsGetPPD(pdest,&destS/*to be freed*/,&destCtr);	//dest//~vbp4I~
#else                                                              //~vbp4I~
        pppdnm=(char *)cupsGetPPD((const char *)pdest);            //~vamuI~
#endif                                                             //~vbp4I~
        UTRACEP("%s:cups margin inrect Mprinter=%s,Mprinter_cupsdefault=%s,ppd=%s\n",UTT,Mprinter,Mprinter_cupsdefault,pppdnm);//~vbp4R~//~vbAiR~
        if (!pppdnm)                                               //~vamuI~
        {                                                          //~vamuI~
            fprintf(stderr,"printer:%s is defined(cupsGetPPD failed)",pdest);//~vamuI~
	        UTRACEP_FLUSH("%s:pppdnm=NULL\n",UTT);                 //~vbAiI~
            break;                                                 //~vamuI~
        }                                                          //~vamuI~
#ifdef NOPPD                                                       //~vbp4I~
    	ppd=csub2_ppdOpenFile(pppdnm,&dinfo);  //http              //~vbp4R~
#else                                                              //~vbp4I~
        ppd=ppdOpenFile(pppdnm);                                   //~vamuI~
#endif                                                             //~vbp4I~
        if (!ppd)                                                  //~vamuI~
        {                                                          //~vamuI~
            fprintf(stderr,"printer:%s is defined(ppdOpenFile failed)",pdest);//~vamuI~
	        UTRACEP_FLUSH("%s:pppOpenFile failed\n",UTT);          //~vbAiI~
            break;                                                 //~vamuI~
        }                                                          //~vamuI~
#ifdef NOPPD                                                       //~vbp4I~
		pPageSz0=pPageSz=getPageSize(pppdnm,ppd,dinfo,&formno);    //~vbp4I~
#else                                                              //~vbp4I~
        formno=ppd->num_sizes;                                     //~vamuI~
        ppgsz=ppd->sizes;                                          //~vamuI~
#endif                                                             //~vbp4I~
        if (!formno)                                               //~vamuI~
        {                                                          //~vamuI~
            fprintf(stderr,"No form is defined on printer:%s",pdest);//~vamuI~
	        UTRACEP_FLUSH("%s:No form defined for %s\n",UTT,pdest);//~vbAiI~
            break;                                                 //~vamuI~
        }                                                          //~vamuI~
#ifdef NOPPD                                                       //~vbp4I~
    	for (ii=formno;ii>0;ii--,pPageSz++)                        //~vbp4I~
#else                                                              //~vbp4I~
        for (ii=formno;ii>0;ii--,ppgsz++)                          //~vamuI~
#endif                                                             //~vbp4I~
        {                                                          //~vamuI~
#ifdef NOPPD                                                       //~vbp4I~
            UTRACEP_FLUSH("%s:csubgetcupsform displayname=%s\n",UTT,pPageSz->displayname);//~vbp4R~//~vbAvR~
    		ppgsz=&(pPageSz->ppdsz);                               //~vbp4I~
            UTRACEP_FLUSH("%s:name=%s\n",UTT,ppgsz->name);         //~vbAvI~
#endif                                                             //~vbp4I~
            UTRACEP("csubgetcupsform name=%s,w=%f,h=%f,t=%f,b=%f,l=%f,r=%f\n",ppgsz->name,ppgsz->width,ppgsz->length,ppgsz->top,ppgsz->bottom,ppgsz->left,ppgsz->right);//~vamuI~
#ifdef NOPPD                                                       //~vbp4I~
//    		if (!strcmp(Ppform,pPageSz->displayname))    //by display name//~vbp4R~//~vbAvR~
        	if (pPageSz->displayname && !strcmp(Ppform,pPageSz->displayname))    //by display name//~vbAvI~
#else                                                              //~vbp4I~
        	if (!strcmp(Ppform,ppgsz->name))    //by display name  //~vamuI~
#endif                                                             //~vbp4I~
            {                                                      //~vamuI~
//    #ifdef AAA                                                   //~vamuR~
				pname=csubgetcupspapername(Ppform); 	//paper name//~vamuI~
//    #else                                                        //~vamuR~
//                pname=csubgetcupspapername("JB5");  //var8test   //~var8R~
//    #endif                                                       //~vamuR~
                UTRACEP("std papername srch result=%s for %s\n",pname,Ppform);//~vamuI~
                if (pname)                                         //~vamuI~
    				pps=gtk_paper_size_new(pname);                 //~vamuI~
                else                                               //~vamuI~
    				pps=gtk_paper_size_new_custom(Ppform,Ppform,ppgsz->width,ppgsz->length,GTK_UNIT_POINTS);//~vamuI~
                fmargins.top=ppgsz->top;                           //~vamuI~
                fmargins.bottom=ppgsz->bottom;                     //~vamuI~
                fmargins.left=ppgsz->left;                         //~vamuI~
                fmargins.right=ppgsz->right;                       //~vamuI~
            	break;                                             //~vamuI~
            }                                                      //~vamuI~
        	if (!strcmp("A4",ppgsz->name))                         //~vamuI~
            {                                                      //~vamuI~
    			ppsa4=gtk_paper_size_new(GTK_PAPER_NAME_A4);     //iso_a4//~vamuR~
                recta4.top=ppgsz->top;                             //~vamuI~
                recta4.bottom=ppgsz->bottom;                       //~vamuI~
                recta4.left=ppgsz->left;                           //~vamuI~
                recta4.right=ppgsz->right;                         //~vamuI~
            }                                                      //~vamuI~
        }                                                          //~vamuI~
        break;                                                     //~vamuI~
    }                                                              //~vamuI~
#ifdef NOPPD                                                       //~vbp4I~
  if (pPageSz0)                                                    //~vbAuI~
	ufree(pPageSz0);                                               //~vbp4I~
  if (ppd)                                                         //~vbAuI~
    csub2_ppdClose(destS,destCtr,ppd,dinfo);                            //~vamuI~//~v970I~                   0//~vbp4I~
#else                                                              //~vbp4I~
    if (ppd)                                                       //~vamuI~
	    ppdClose(ppd);                                             //~vamuI~
#endif                                                             //~vbp4I~
    if (!pps)                                                      //~vamuR~
    {                                                              //~vamuI~
        UTRACEP("%s not found\n",Ppform);                          //~vamuI~
    	pps=ppsa4;        //issue errmsg, assume A4                //~vamuR~
        if (!pps)                                                  //~vamuI~
			pps=gtk_paper_size_new(Ppform);                        //~vamuI~
    	fprintf(stderr,"form:%s is not defined on printer:%s,assume A4",Ppform,pdest);//~vamuI~
        fmargins=recta4;                                           //~vamuI~
    }                                                              //~vamuI~
    if (Ppmargin)                                                  //~vamuI~
  		*Ppmargin=fmargins;                                        //~vamuI~
    if (!pps)                                                      //~vbAuI~
    {                                                              //~vbAuI~
	    UTRACEP("%s:return pps=NULL\n",UTT);                       //~vbAuI~
    }                                                              //~vbAuI~
    UTRACEP("%s:iscustom=%d,w=%f point,h=%f point,t=%f,b=%f,l=%f,r=%f\n",UTT,gtk_paper_size_is_custom(pps),gtk_paper_size_get_width(pps,GTK_UNIT_POINTS),gtk_paper_size_get_height(pps,GTK_UNIT_POINTS),fmargins.top,fmargins.bottom,fmargins.left,fmargins.right);//~vamuR~//~vbAuR~
    return pps;                                                    //~vamuI~
}//csubgetpapersizeGtk_fromPPD                                     //~vamuI~
#endif //GTKPRINT                                                  //~vamuI~
#ifdef GTKPRINT                                                    //~vam0I~
//=========================================================================
//=get papername from displayname                                  //~vam0I~
//=========================================================================
const char *csubgetcupspapername(char *Ppaperdisplayname)          //~vam0R~
{                                                                  //~2B03aI~
	GList *gl,*gl0;
    GtkPaperSize *pps;                                             //~vam0I~
    const char *pdisplayname;                                      //~vam0R~
    const char *pname;                                             //~vam0R~
    int swfound=0;                                                 //~vam0I~
//************************************
    gl0=gtk_paper_size_get_paper_sizes(FALSE);                     //~vam0I~
    for (gl=gl0;gl!=NULL;gl=gl->next)                              //~vam0I~
    {                                                              //~vam0I~
    	pps=(GtkPaperSize*)gl->data;                               //~vam0I~
        pdisplayname=gtk_paper_size_get_display_name(pps);         //~vam0R~
        if (!pdisplayname)                                         //~vbAvI~
        	continue;                                              //~vbAvI~
        UTRACEP("csubgetcupspapername name=%s,displayname=%s\n",gtk_paper_size_get_name(pps),pdisplayname);//~vam0I~//~vamuR~
        UTRACEP("csubgetcupspapername w=%f,h=%f\n",gtk_paper_size_get_width(pps,GTK_UNIT_POINTS),gtk_paper_size_get_height(pps,GTK_UNIT_POINTS));//~vamuR~
        if (!strcmp(pdisplayname,Ppaperdisplayname))               //~vam0I~
        {                                                          //~vam0I~
	        pname=gtk_paper_size_get_name(pps);                    //~vam0I~
            swfound=1;                                             //~vam0I~
        	break;                                                 //~vam0I~
        }                                                          //~vam0I~
    }                                                              //~vam0I~
    if (!swfound)                                                  //~vam0I~
    	pname=NULL;                                                //~vam0I~
    UTRACEP("csubgetcupspapername name=%s\n",pname);               //~vam0I~
    return pname;                                                  //~vam0I~
}//csubgetcupspapername                                            //~vam0I~
//=========================================================================//~vam0I~
GList *csubgetcupspaperlistGtk(GtkPrinter *Ppprinter)              //~vam0I~
{                                                                  //~2B03aI~//~vam0I~
	GList *gl,*gl0;                                                //~vam0I~
//************************************                             //~vam0I~
    UTRACEP("csubgetcupspaperlistGtk printer=%s\n",gtk_printer_get_name(Ppprinter));//~vam0I~
    UTRACEP("csubgetcupspaperlistGtk has_detail=%d\n",gtk_printer_has_details(Ppprinter));//~vam0I~
    if (!gtk_printer_has_details(Ppprinter))                       //~vam0R~
    	gtk_printer_request_details(Ppprinter);                    //~vam0I~
    UTRACEP("csubgetcupspaperlistGtk has_detail=%d\n",gtk_printer_has_details(Ppprinter));//~vam0I~
    gl0=gtk_printer_list_papers(Ppprinter);                        //~vam0I~
    for (gl=gl0;gl!=NULL;gl=gl->next)                              //~vam0I~
    {                                                              //~vam0I~
        UTRACEP("csubgetcupspaperlistGtk data=%s\n",(char*)(gl->data));//~vam0R~
    }                                                              //~vam0I~
    UTRACEP("csubgetcupspaperlistGtk gl0=%p\n",gl0);               //~vam0I~
    return gl0;                                                    //~vam0I~
}//csubgetcupspaperlistGtk                                         //~vam0I~
//===============================================================================//~vam0M~
//=paper list of default printer                                   //~vam0M~
//===============================================================================//~vam0M~
#ifdef BBB                                                         //~vam0R~
GList *csubgetcupspaperlistGtkName(char *Pprintername)             //~vam0I~
{                                                                  //~vam0M~
	GtkPrinter *pprinter;                                          //~vam0M~
    GList *ppaperlist;                                             //~vam0M~
    GList *gl;                                                     //~vam0I~
//***********************                                          //~vam0M~
	UTRACEP("csubgetcupspaperlistGtkName,parm=%s\n",Pprintername); //~vam0R~
	pprinter=csubsrchprinterGtk(Pprintername,NULL);                //~vam0I~
    if (!pprinter)                                                 //~vam0M~
    	return NULL;                                               //~vam0M~
    UTRACEP("csubgetpaperlistGtk name=%s=%s,detail=%d\n",Pprintername,gtk_printer_get_name(pprinter),gtk_printer_has_details(pprinter));//~vam0R~
#ifndef BBB                                                        //~vam0I~
    ppaperlist=gtk_printer_list_papers(pprinter);                  //~vam0I~
    for (gl=ppaperlist;gl!=NULL;gl=gl->next)                       //~vam0I~
    {                                                              //~vam0I~
        UTRACEP("csubgetcupspaperlistGtkName data=%s\n",(char*)(gl->data));//~vam0R~
    }                                                              //~vam0I~
#else                                                              //~vam0I~
  	ppaperlist=csubgetcupsformGtk(pprinter);                       //~vam0M~
#endif                                                             //~vam0I~
	UTRACEP("csubgetcupspaperlistGtkName exit\n");                 //~vam0R~
    return ppaperlist;                                             //~vam0M~
}//csubgetpaperlistGtkName                                         //~vam0R~
#endif //BBB                                                       //~vam0R~
//=========================================================================//~vam0I~
GList *csubgetcupsformGtk(GtkPrinter *Ppprinter)                   //~vam0R~
{                                                                  //~2B03aI~//~vam0I~
	GList *gl=NULL;                                                //~vam0R~
    int ii,formno;                                                 //~vam0R~
#ifdef NOPPD                                                       //~vbp4I~
    cups_dest_t *pppdnm,*destS;                                    //~vbp4I~
    http_t     *ppd;                                               //~vbp4I~
    cups_dinfo_t  *dinfo;                                          //~vbp4I~
    int destCtr;                                                   //~vbp4I~
    PageSize *pPageSz,*pPageSz0;                                   //~vbp4I~
#else                                                              //~vbp4I~
    char *pppdnm;                                                  //~vam0R~
    ppd_file_t *ppd;                                               //~vbp4M~
#endif                                                             //~vbp4I~
    const gchar *pdest;                                            //~vam0R~
    ppd_size_t *ppgsz;                                             //~vam0I~
//************************************                             //~vam0I~
    pdest=gtk_printer_get_name(Ppprinter);                         //~vam0I~
    UTRACEP("csubgetcupsformGtk printer=%s\n",pdest);              //~vam0I~
#ifdef NOPPD                                                       //~vbp4I~
    pppdnm=csub2_cupsGetPPD((char*)pdest,&destS/*to be freed*/,&destCtr);	//dest//~vbp4R~
    UTRACEP("cups margin inrect dest=%s,default=%s,ppd=%p\n",Mprinter,Mprinter_cupsdefault,pppdnm);//~vbp4I~
#else                                                              //~vbp4I~
    pppdnm=(char *)cupsGetPPD((const char *)pdest);                //~vam0I~
    dprintf("cups margin inrect dest=%s,default=%s,ppd=%s\n",Mprinter,Mprinter_cupsdefault,pppdnm);//~vam0I~
#endif                                                             //~vbp4I~
    if (!pppdnm)                                                   //~vam0I~
    	return NULL;                                               //~vam0R~
#ifdef NOPPD                                                       //~vbp4I~
    ppd=csub2_ppdOpenFile(pppdnm,&dinfo);  //http                  //~vbp4I~
#else                                                              //~vbp4I~
    ppd=ppdOpenFile(pppdnm);                                       //~vam0I~
#endif                                                             //~vbp4I~
    if (!ppd)                                                      //~vam0I~
    	return NULL;                                               //~vam0R~
#ifdef NOPPD                                                       //~vbp4I~
	pPageSz0=pPageSz=getPageSize(pppdnm,ppd,dinfo,&formno);        //~vbp4I~
#else                                                              //~vbp4I~
    formno=ppd->num_sizes;                                         //~vam0I~
    ppgsz=ppd->sizes;                                              //~vam0I~
#endif                                                             //~vbp4I~
    if (!formno)                                                   //~vam0I~
    	return NULL;                                               //~vam0R~
#ifdef NOPPD                                                       //~vbp4I~
    for (ii=formno;ii>0;ii--,pPageSz++)                            //~vbp4I~
#else                                                              //~vbp4I~
    for (ii=formno;ii>0;ii--,ppgsz++)                              //~vam0I~
#endif                                                             //~vbp4I~
    {                                                              //~vam0I~
#ifdef NOPPD                                                       //~vbp4I~
    	ppgsz=&(pPageSz->ppdsz);                                   //~vbp4I~
#endif                                                             //~vbp4I~
    	UTRACEP("csubgetcupsformGtk entry=%s\n",ppgsz->name);      //~vam0I~
        gl=g_list_append(gl,ppgsz->name);                          //~vam0I~
    }                                                              //~vam0I~
#ifdef NOPPD                                                       //~vbp4I~
  if (pPageSz0)                                                    //~vbAuI~
	ufree(pPageSz0);                                               //~vbp4I~
    csub2_ppdClose(destS,destCtr,ppd,dinfo);                            //~vamuI~//~v970I~                   0//~vbp4I~
#else                                                              //~vbp4I~
    ppdClose(ppd);                                                 //~vam0I~
#endif                                                             //~vbp4I~
    return gl;                                                     //~vam0I~
}//csubgetcupsformGtk                                                 //~vam0I~//~vamtR~
//=========================================================================//~vamtI~
//=setup custom paper when papershift                              //~vamtI~
//=========================================================================//~vamtI~
GtkPaperSize *                                                     //~vamtR~
csubgetpaperShiftGtk(GtkPaperSize *Ppps)                           //~vamtR~
{                                                                  //~2B03aI~//~vamtI~
    gdouble ww,hh;                                                 //~vamtI~
    GtkPaperSize *pps,*ppsn;                                       //~vamtR~
    int iscustom;                                                  //~vamtI~
    const char *name1,*name2;                                      //~vamtR~
    char *name1n,*name2n;                                          //~vamtI~
//************************************                             //~vamtI~
	hh=gtk_paper_size_get_height(Ppps,GTK_UNIT_MM);                //~vamtI~
	ww=gtk_paper_size_get_width(Ppps,GTK_UNIT_MM);                 //~vamtI~
	iscustom=gtk_paper_size_is_custom(Ppps);                       //~vamtI~
	UTRACEP("csubgetpapershiftGtk input w=%lf mm,h=%lf mm,is_custom=%d\n",ww,hh,iscustom);//~vamtR~
    hh+=MmarginshiftT+MmarginshiftB;                               //~vamtR~
    ww+=MmarginshiftL+MmarginshiftR;                               //~vamtR~
	UTRACEP("csubgetpaperShiftGtk landscape=%d,new w=%lf mm,h=%lf mm,Mmarginshift T=%d,B=%d,L=%d,R=%d\n",Mlandscape,ww,hh,MmarginshiftT,MmarginshiftB,MmarginshiftL,MmarginshiftR);//~vamtR~
    pps=Ppps;                                                      //~vamtI~
    if (iscustom)                                                  //~vamtI~
    {                                                              //~vamtI~
    	gtk_paper_size_set_size(pps,ww,hh,GTK_UNIT_MM);            //~vamtR~
    }                                                              //~vamtI~
    else                                                           //~vamtI~
    {                                                              //~vamtI~
    	name1=gtk_paper_size_get_name(pps);                        //~vamtR~
    	name2=gtk_paper_size_get_display_name(pps);                //~vamtR~
        name1n=malloc(strlen(name1)+32);                           //~vamtI~
      if (!name2)                                                  //~vbAvI~
        name2n=malloc(32);                                         //~vbAvI~
      else                                                         //~vbAvI~
        name2n=malloc(strlen(name2)+32);                           //~vamtI~
        sprintf(name1n,"%sC",name1);                               //~vamtI~
        sprintf(name2n,"%sC",name2);                               //~vamtI~
    	ppsn=gtk_paper_size_new_custom(name1n,name2n,ww,hh,GTK_UNIT_MM);//~vamtI~
        free(name1n);                                              //~vamtI~
        free(name2n);                                              //~vamtI~
    	gtk_paper_size_free(pps);                                  //~vamtR~
        pps=ppsn;                                                  //~vamtI~
    }                                                              //~vamtI~
	UTRACEP("csubgetpaperShiftGtk output w=%lf mm,h=%lf mm,is_custom=%d\n",gtk_paper_size_get_width(pps,GTK_UNIT_MM),gtk_paper_size_get_height(pps,GTK_UNIT_MM),gtk_paper_size_is_custom(pps));//~vamtR~
    return pps;                                                    //~vamtI~
}//csubgetpaperShiftGtk                                            //~vamtR~
//===============================================================================//~vam0I~
//=gdowble width/height of paper by POINTS(include HWmargin)       //~vam0R~
//===============================================================================//~vam0I~
//void *csubgetpapersizeGtk(int Popt/*free*/,char *Pformtype,gdouble *Ppww,gdouble *Pphh)//~vam0R~//~vamuR~
void *                                                             //~vamuI~
csubgetpapersizeGtk(int Popt/*free*/,char *Pformtype,gdouble *Ppww,gdouble *Pphh)//~vamuR~
{                                                                  //~vam0I~
	GtkPaperSize *pps;                                             //~vam0I~
//    const char *pname;                                             //~vam0I~//~vamuR~
    gdouble ww,hh;                                                 //~vam0R~
//*******************************                                  //~vam0I~
	UTRACEP("%s:Pformtype=%s\n",UTT,Pformtype);                    //~vbAiI~
//  pps=gtk_paper_size_new(Pformtype);   //unknow paper size for B5JIS//~vamuR~
//    pname=csubgetcupspapername(Pformtype);                         //~vam0I~//~vamuR~
//    pps=gtk_paper_size_new(pname);                                 //~vam0I~//~vamuR~
	pps=csubgetpapersizeGtk_fromPPD(NULL/*printer*/,Pformtype,NULL);//~vamuR~
    if (!pps)                                                      //~vbAuI~
    	return NULL;                                               //~vbAuI~
//    pps=gtk_paper_size_new_from_ppd(Pformtype,Pformtype,0,0);    //~vamuR~
	if (Mmarginshift)                                              //~vamtR~
    	pps=csubgetpaperShiftGtk(pps);                             //~vamtR~
	UTRACEP("csubgetpaperShiftGtk w=%lf mm,h=%lf mm,is_custom=%d\n",gtk_paper_size_get_width(pps,GTK_UNIT_MM),gtk_paper_size_get_height(pps,GTK_UNIT_MM),gtk_paper_size_is_custom(pps));//~vamtR~
	ww=gtk_paper_size_get_width(pps,GTK_UNIT_POINTS);              //~vamuI~
	hh=gtk_paper_size_get_height(pps,GTK_UNIT_POINTS);             //~vam0R~
	UTRACEP("csubgetpapersizegtk new for paper=%s w=%lf Point,h=%lf Point,is_custom=%d\n",Pformtype,ww,hh,gtk_paper_size_is_custom(pps));//~vam0R~//~vamuR~//~vamtR~
	UTRACEP("csubgetpapersizegtk new name=%s,displayname=%s\n",gtk_paper_size_get_name(pps),gtk_paper_size_get_display_name(pps));//~vam0R~//~vamtR~
    if (Ppww)                                                      //~vam0I~
        *Ppww=ww;                                                  //~vam0I~
    if (Pphh)                                                      //~vam0I~
        *Pphh=hh;                                                  //~vam0I~
    if (Popt & CSGPS_FREE)                                         //~vam0I~
    {                                                              //~vam0I~
	    gtk_paper_size_free(pps);                                  //~vam0I~
        pps=NULL;                                                  //~vam0I~
    }                                                              //~vam0I~
    return pps;                                                    //~vam0I~
}//csubgetpapersizeGtk                                             //~vam0R~
//===============================================================================//~vam0I~
//=gdowble width/height of paper by POINTS                         //~vam0I~
//===============================================================================//~vam0I~
void csubsetpapersizeGtk(char *Pformtype)                          //~vam0R~
{                                                                  //~vam0I~
	GtkPaperSize *pps;                                             //~vam0I~
    gdouble ww,hh;                                                 //~vam0I~
//*******************************                                  //~vam0I~
    UTRACEP("%s:parm form=%s\n",UTT,Pformtype);                    //~vbAiI~
	pps=(GtkPaperSize*)csubgetpapersizeGtk(0/*no free*/,Pformtype,&ww,&hh);//~vam0R~
    if (!pps)                                                      //~vbAuI~
    {                                                              //~vbAuI~
	    UTRACEP_FLUSH("%s:@@@@ pps NULL\n",UTT);                   //~vbAuI~
    	return;                                                    //~vbAuI~
    }                                                              //~vbAuI~
    UTRACEP("%s:form=%s,pps=%p,name=%s,displayname=%s\n",UTT,pps,gtk_paper_size_get_name(pps),gtk_paper_size_get_display_name(pps));//~vam0R~  //~vamsI~//~vamuR~//~vbAiR~
    gtk_print_settings_set_paper_size(Gpgtkps,pps);                //~vam0I~
//  gtk_print_settings_set_paper_width(Gpgtkps,ww,GTK_UNIT_POINTS);//~vam0I~//~vamqR~
//  gtk_print_settings_set_paper_height(Gpgtkps,hh,GTK_UNIT_POINTS);//~vam0I~//~vamqR~
    ww=gtk_print_settings_get_paper_width(Gpgtkps,GTK_UNIT_POINTS);//~vam0I~
    hh=gtk_print_settings_get_paper_height(Gpgtkps,GTK_UNIT_POINTS);//~vam0I~
    UTRACEP("csubsetpapersizeGtk after set form=%s,w=%lf,h=%lf\n",Pformtype,ww,hh);//~vam0R~//~vamsR~
    gtk_paper_size_free(pps);                                      //~vam0I~
}//csubsetpapersizeGtk                                             //~vam0I~
//===============================================================================//~vam0I~
void csub_setcolorGtk(cairo_t *Ppct)                               //~vam0I~
{                                                                  //~vam0I~
    UTRACEP("csub_setcolorGtk\n");                       //~vam0R~ //~vamqR~
//    cairo_set_source_rgb(Ppct,0.01,0.01,0.01);                     //~vam0R~//~vamtR~
      cairo_set_source_rgb(Ppct,0.0,0.0,0.0);                      //~vamtI~
}                                                                  //~vam0I~
#endif   //!GTKPRINT                                               //~vam0I~
//===============================================================================//~vX03I~
//get default config                                               //~vX03I~
//parm1:prev pointer to be freed                                   //~vX03I~
//parm2:printer name to be set to config                           //~vX03I~
//ret  :new config                                                 //~vX03I~
//===============================================================================//~vX03I~
#ifndef NOPRINT                                                    //~vam0R~
	#ifdef GTKPRINT                                                //~vam0I~
	#else    //!GTKPRINT                                           //~vam0I~
void *uprtgetconfig(void *Ppprtconf,char *Ppprinter)               //~vX03R~
{                                                                  //~vX03I~
    GnomePrintConfig *pprtconf;                                    //~vX03R~
    char *poldprinter;                                             //~vX03I~
//************************************                             //~vX03I~
	if (Ppprtconf)	//free previous req                            //~vX03R~
    	gnome_print_config_unref((GnomePrintConfig*)(Ppprtconf));  //~vX03R~
    pprtconf=gnome_print_config_default();                         
    poldprinter=gnome_print_config_get(pprtconf,"Printer");        //~vX03I~
//  dprintf("config printer before=%s,req=%s\n",poldprinter,Ppprinter);//~v69VR~
    if (Ppprinter)	//printer specified                            //~vX03I~
    {                                                              //~vX03I~
    	if (!strcmp(Ppprinter,DEF_PRINTER)	//default specified    //~va4aI~
        && *Mprinter_cupsdefault)			//cups defult was set  //~va4aI~
        {                                                          //~va4aI~
        	gnome_print_config_set(pprtconf,"Printer",Mprinter_cupsdefault);//~va4aI~
  		    dprintf("config printer %s->%s\n",Mprinter_cupsdefault,gnome_print_config_get(pprtconf,"Printer"));//~va4aI~
        }                                                          //~va4aI~
        else                                                       //~va4aI~
    	if (strcmp(Ppprinter,DEF_PRINTER)	//not default specified//~vX03R~
//  	&&  strcmp(Ppprinter,poldprinter))	//not default          //~va6yR~
    	&&  (!poldprinter ||strcmp(Ppprinter,poldprinter)))	//not default//~va6yI~
        {                                                          //~vX03I~
        	gnome_print_config_set(pprtconf,"Printer",Ppprinter);  //~vX03I~
    		 dprintf("config printer after=%s,Mprinter=%s\n",gnome_print_config_get(pprtconf,"Printer"),Ppprinter);//~va6yR~
        }                                                          //~vX03I~
    }                                                              //~vX03I~
    if (poldprinter)                                               //~va6yI~
    	g_free(poldprinter);                                       //~va6yI~
	return (void*)pprtconf;                                        //~vX03R~
}//uprtgetconfig                                                   //~vX03I~
	#endif   //!GTKPRINT                                           //~vam0I~
#endif //!NOGOMEPRINT                                              //~vam0I~
//===============================================================================//~v76cI~
//get keyboard rate from gconf db                                  //~v76cI~
//parm1:output typematic delay                                     //~v76cI~
//parm2:output typematic interval(ms)                              //~v76cR~
//ret  :err                                                        //~v76cI~
//===============================================================================//~v76cI~
int ugconfgetkbdrate(int *Ppdelay,int *Ppinterval)                 //~v76cR~
{                                                                  //~v76cI~
#ifdef GCONFKBD                                                    //~v76cI~
	GConfClient *client;                                           //~v76cI~
#endif                                                             //~v76cI~
    int rate,delay;                                                //~v76cI~
#ifndef OPTGTK3                                                    //+var8I~//+var8I//~vb73I~
#else                                                              //~vb73I~
	GdkDisplay *gdkdisplay;                                        //~vb73R~
	GdkWindow  *gdkwindow;                                         //~vb73I~
    const char *displayname;                                       //~vb73I~
#endif                                                             //~vb73I~
//************************************                             //~v76cI~
#ifdef GCONFKBD	//KDE may not have gconf db                        //~v76cR~
	client = gconf_client_get_default ();                          //~v76cI~
    dprintf("client=%p\n",client);                                 //~v76cI~
    if (!client)                                                   //~v76cI~
    	return 4;                                                  //~v76cI~
    delay=gconf_client_get_int(client,"/desktop/gnome/peripherals/keyboard/delay",NULL);//~v76cI~
    rate =gconf_client_get_int(client,"/desktop/gnome/peripherals/keyboard/rate",NULL);//~v76cI~
    dprintf("delay=%d,rate=%d\n",delay,rate);                      //~v76cR~
    *Ppdelay=delay;                                                //~v76cI~
    if (rate)                                                      //~v76cI~
    	*Ppinterval=1000/rate;                                     //~v76cR~
    else                                                           //~v76cI~
    	*Ppinterval=0;                                             //~v76cR~
	g_object_unref (G_OBJECT (client));                            //~v76cI~
#else                                                              //~v76cI~
#ifndef OPTGTK3                                                    //+var8I~//+var8I//~var8R~
    XkbGetAutoRepeatRate(GDK_DISPLAY (),XkbUseCoreKbd,(UINT*)(&delay),(UINT*)(&rate));//~v76cI~//~va72R~
#else   //OPTGTK3                                                  //+var8I//~var8R~
//  XkbGetAutoRepeatRate(GDK_WINDOW_XDISPLAY(gtk_widget_get_window(Gpview)),XkbUseCoreKbd,(UINT*)(&delay),(UINT*)(&rate));//~vb73I~
	gdkwindow=gtk_widget_get_window(Gpview);                       //~vb73R~
	gdkdisplay=gdk_window_get_display(gdkwindow);                  //~vb73I~
    displayname=gdk_display_get_name(gdkdisplay);                  //~vb73I~
    if (!strstr(displayname,"wayland"))                            //~vb73I~
    	XkbGetAutoRepeatRate(GDK_WINDOW_XDISPLAY(gtk_widget_get_window(Gpview)),XkbUseCoreKbd,(UINT*)(&delay),(UINT*)(&rate));//~v76cI~//~vb73R~
    else                                                           //~vb73I~
    {                                                              //~vb73I~
	    dprintf("ugconfgetkbdrate:bypass XkbdGetAutoRepeatRate by wayland displayname=%s\n",displayname);//~vb73I~
    	return 4;                                                  //~vb73I~
    }                                                              //~vb73I~
#endif                                                             //+var8I//~var8R~
    dprintf("delay=%d,rate=%d\n",delay,rate);                      //~v76cI~
    *Ppdelay=delay;                                                //~v76cI~
    *Ppinterval=rate;                                              //~v76cR~
#endif                                                             //~v76cI~
    return 0;                                                      //~v76cI~
}//ugconfgetkbdrate                                                //~v76cI~
//***********************************************************************//~vamqI~
//*rc:rep count                                                    //~vamqI~
//***********************************************************************//~vamqI~
int                                                                //~vamqI~
csub_repu8null(char *Putf8,int Pu8len,int Prepch)                  //~vamqI~
{                                                                  //~vamqI~
	int ctr=0,ch=0,altch,repch;                                    //~vamqI~
	char *pc,*pce;                                                 //~vamqI~
	unsigned int len;                                              //~vamqI~
//******************                                               //~vamqI~
	if (!Pu8len)                                                   //~vamqI~
		return 0;                                                  //~vamqI~
    repch=Prepch;                                                  //~vamqI~
    if (!repch)                                                    //~vamqI~
    {                                                              //~vamqI~
    	repch='.';                                                 //~vamqI~
		altch=UTF_GETALTCH_CTL(ch);                                //~vamqR~
		if (altch>0 && altch<0x80)                                 //~vamqI~
        	repch=altch;                                           //~vamqI~
    }                                                              //~vamqI~
    pc=Putf8;                                                      //~vamqI~
    pce=pc+Pu8len;                                                 //~vamqI~
    for (;;)                                                       //~vamqI~
    {                                                              //~vamqI~
        len=PTRDIFF(pce,pc);                                       //~vamqI~
    	pc=memchr(pc,ch,len);                                      //~vamqI~
        if (!pc)                                                   //~vamqI~
        	break;                                                 //~vamqI~
		*pc++=repch;                                               //~vamqI~
        ctr++;                                                     //~vamqI~
	}                                                              //~vamqI~
	return ctr;                                                    //~vamqI~
}//csub_repu8null                                                  //~vamqI~
//***********************************************************************//~vamqI~
//*rc:char count of utf8 mem                                       //~vamqI~
//***********************************************************************//~vamqI~
int                                                                //~vamqI~
csub_utf8mem_strlen(char *Putf8,int Pu8len)                        //~vamqI~
{                                                                  //~vamqI~
	int ctr=0;                                                     //~vamqR~
	char *pc,*pce,*pc2;                                            //~vamqI~
	unsigned int len;                                              //~vamqI~
//******************                                               //~vamqI~
	if (!Pu8len)                                                   //~vamqI~
		return 0;                                                  //~vamqI~
    pc=Putf8;                                                      //~vamqI~
    pce=pc+Pu8len;                                                 //~vamqI~
    for (;;)                                                       //~vamqI~
    {                                                              //~vamqI~
        len=PTRDIFF(pce,pc);                                       //~vamqI~
    	pc2=memchr(pc,0,len);                                      //~vamqR~
        if (pc2)                                                   //~vamqI~
        	len=PTRDIFF(pc2,pc);                                   //~vamqI~
        ctr+=g_utf8_strlen(pc,len);                                //~vamqI~
        if (!pc2)                                                  //~vamqI~
        	break;                                                 //~vamqI~
        ctr++;                                                     //~vamqI~
        pc=pc2+1;                                                  //~vamqI~
	}                                                              //~vamqI~
    UTRACEP("csub_memutf8_strlen ctr=%d\n",ctr);                   //~vamqI~
	return ctr;                                                    //~vamqI~
}//csub_utf8mem_strlen                                             //~vamqI~
#ifdef GTKPRINT                                                    //~vat0I~
//**************************************                           //~vat0I~
//*cups active chk                                                 //~vat0I~
//**************************************                           //~vat0I~
int csubgetdestctr()                                               //~vat0I~
{                                                                  //~vat0I~
    int destctr;                                                   //~vat0I~
    cups_dest_t *dest;                                             //~vat0I~
//*******************                                              //~vat0I~
    UTRACEP("%s:entry\n",UTT);                                     //~vb7wI~
    destctr=cupsGetDests(&dest);                                   //~vat0I~
    dprintf("csubgetdestctr destctr=%d\n",destctr);                //~vat0I~
    cupsFreeDests(destctr,dest);                                   //~vat0I~
    UTRACEP("%s: destctr=%d\n",UTT,destctr);                       //~vb7wM~
    return destctr;                                                //~vat0I~
}//csubgetdestctr                                                  //~vat0I~
//**************************************                           //~vbi7I~
//*cups active chk                                                 //~vbi7I~
//**************************************                           //~vbi7I~
int csubiscupsavail()                                              //~vbi7I~
{                                                                  //~vbi7I~
    const char *pc;                                                //~vbi7R~
    int rc;                                                        //~vbi7I~
//*******************                                              //~vbi7I~
    UTRACEP("%s:entry\n",UTT);                                     //~vbi7I~
    pc=cupsGetDefault();                                           //~vbi7I~
    UTRACEP("%s: cupsgetDefault=%s\n",UTT,pc);                     //~vbi7I~
    pc=cupsServer();                                               //~vbi7I~
    UTRACEP("%s: cupsServer=%s\n",UTT,pc);                         //~vbi7I~
    rc=pc!=0;                                                      //~vbi7R~
    UTRACEP("%s:return rc=%d\n",UTT,rc);                           //~vbi7I~
    return rc;                                                     //~vbi7I~
}//csubgetdestctr                                                  //~vbi7I~
//**************************************************************************//~vbi7I~
//listup printer not by cupsDests but enum function                //~vbi7I~
//return ctr;                                                      //~vbi7I~
//**************************************************************************//~vbi7I~
int csublistprinter(char **Pplist,int *Ppdefaultindex)             //~vbi7R~
{                                                                  //~vbi7I~
	GtkPrinterFunc pfunc;                                          //~vbi7I~
    char *plist="";                                                //~vbi7R~
//*******************                                              //~vbi7I~
	UTRACEP("%s:entry\n",UTT);                                     //~vbi7I~
  	if (!csubiscupsavail())	//cups dest found                      //~vbi7I~
    	return 0;                                                  //~vbi7I~
    Senumctr=0;                                                    //~vbi7I~
    Senumdefault=-1;                                               //~vbi7I~
    pfunc=(GtkPrinterFunc)cb_enumprinter2;                         //~vbi7I~
	gtk_enumerate_printers(pfunc,&plist/*data to cbfunc*/,NULL/*GdestroyNotify*/,TRUE/*wait all enumerated*/);//~vbi7I~
    *Ppdefaultindex=Senumdefault;                                  //~vbi7I~
    *Pplist=plist;                                                 //~vbi7I~
	UTRACEP("%s:return ctr=%d,defaultindex=\n",UTT,Senumctr,Senumdefault);//~vbi7I~
    return Senumctr;                                               //~vbi7I~
}//csubsrchprinterGtk()                                            //~vbi7I~
#endif                                                             //~vat0I~
//===============================================================================//~vbk4I~
//set chk combining char                                           //~vbk4I~
//Ppucs is valid only when sbcs combining or ovf dbcs              //~vbkpI~
//rc  1:sbcs w0,2: ucs4 w0                                         //~vbk4I~
//===============================================================================//~vbk4I~
int csub_iswidth0(int Popt,UCHAR *Ppdddata,UCHAR *Ppdddbcs,int Plen,gunichar *Ppucs,int *Ppchsz)//~vbk4I~
{                                                                  //~vbk4I~
	UWUCS ucs4=-1;                                                    //~vbk4I~//~vbk6R~
    int chsz=1,rc=0;                                               //~vbk4I~
//*****************************                                    //~vbk4I~
	if (UDBCSCHK_ISUCSWIDTH0(*Ppdddbcs))                           //~vbk4R~
    {                                                              //~vbk4I~
        ucs4=(WUCS)UTF_GETUCSSBCS(Ppdddata,Ppdddbcs);              //~vbk4R~
        chsz=1;                                                    //~vbk4I~
    	rc=1;                                                      //~vbk4I~
    }                                                              //~vbk4I~
    else                                                           //~vbk4I~
	if (UDBCSCHK_ISUCSOVF1ST(*Ppdddbcs))                           //~vbkpI~
    {                                                              //~vbk4I~
		ucs4=utfdd2u1chsz(0,Ppdddata,Ppdddbcs,Plen,&chsz);         //~vbk4I~
    	if (chsz<0)                                                //~vbk4I~
    		chsz=-chsz; //-1: err(split), -2: unprintable          //~vbk4I~
    	else //confirmed Plen>1 by chsz>0                          //~vbk4R~
			rc=utf22_iswidth0Ovf(0,*Ppdddata,*(Ppdddata+1),*Ppdddbcs,*(Ppdddbcs+1),&ucs4)?2:0;//~vbk4R~
    }                                                              //~vbk4I~
    if (Ppchsz)                                                    //~vbk4I~
    	*Ppchsz=chsz;                                              //~vbk4I~
    if (Ppucs)                                                     //~vbk4I~
    	*Ppucs=ucs4;                                               //~vbk4I~
    UTRACEP("%s:rc=%d,ucs=%04x,chsz=%d,dbcsid=%0x\n",UTT,rc,ucs4,chsz,*Ppdddbcs);//~vbk4I~
    return rc;                                                     //~vbk4I~
}//csub_iswidth0                                                //~vbk4I~
//===============================================================================//~vbmfI~
//set chk combining char                                           //~vbmfI~
//Ppucs is valid only when sbcs combining or ovf dbcs              //~vbmfI~
//rc  0x01:sbcs w0,0x02: ucs4 w0  0x04:SCM                         //~vbmfR~
//===============================================================================//~vbmfI~
int csub_iscombining(int Popt,UCHAR *Ppdddata,UCHAR *Ppdddbcs,int Plen,gunichar *Ppucs,int *Ppchsz)//~vbmfI~
{                                                                  //~vbmfI~
	UWUCS ucs;                                                     //~vbmfI~
    int chsz=1,rc=0;                                               //~vbmfI~
//*****************************                                    //~vbmfI~
	ucs=utfdd2u1chsz(0,Ppdddata,Ppdddbcs,Plen,&chsz);              //~vbmfI~
    if (chsz<0)                                                    //~vbmfI~
    {                                                              //~vbmfI~
    	chsz=-chsz; //-1: err(split), -2: unprintable              //~vbmfI~
		ucs=-1;                                                    //~vbmfR~
    }                                                              //~vbmfI~
    else                                                           //~vbmfI~
    {                                                              //~vbmfI~
//  	rc=utf_iscombining(0,*Ppdddbcs,(int)ucs);                  //~vbmfR~//~v7f1R~
		int opt4=UICO_COMBONLY;	//exclude FMT                      //~v7bVI~//~v7f1I~
#ifndef KKK                                                        //~v7f4I~
		if (Popt & CICO_RCNOCOMB)	//rc=8 for w0 no combine       //~v7f4I~
			opt4|=UICO_RCNOCOMB;	                               //~v7f4I~
#endif                                                             //~v7f4I~
		rc=utf_iscombining(opt4,*Ppdddbcs,(int)ucs);               //~v7f1I~
    }                                                              //~vbmfI~
    if (Ppchsz)                                                    //~vbmfI~
    	*Ppchsz=chsz;                                              //~vbmfI~
    if (Ppucs)                                                     //~vbmfI~
    	*Ppucs=ucs;                                                //~vbmfI~
    UTRACEP("%s:opt=%04x,rc=%d,ucs=%06x,chsz=%d,dbcsid=%0x\n",UTT,Popt,rc,ucs,chsz,*Ppdddbcs);//~vbmfI~//~v7f4R~
    return rc;                                                     //~vbmfI~
}//csub_iscombining                                                //~vbmfI~
//===============================================================================//~vbk6I~
//chk spacing combining char                                       //~vbk6I~
//rc  1/0                                                          //~vbk6I~
//===============================================================================//~vbk6I~
int csub_isSpacingCombiningMark(int Popt,gunichar Pucs)            //~vbk6R~
{                                                                  //~vbk6I~
	int rc;                                                        //~vbk6I~
//*****************************                                    //~vbk6I~
	if (UTF8ISASCII(Pucs))                                         //~vbk6I~
    	return 0;                                                  //~vbk6I~
	rc=utf4_isSpacingCombiningMark(0,(UWUCS)Pucs);                 //~vbk6R~
    UTRACEP("%s:rc=%d,ucs=%04x\n",UTT,rc,Pucs);                    //~vbk6R~
    return rc;                                                     //~vbk6I~
}//csub_isSpacingCombiningMark                                     //~vbk6I~
//===============================================================================//~vbk4I~
//set flag to geom->width for width=0 and SCM                      //~vbk6R~
//Pscmctr:glyphctr-ucsctr(>0 if no combine occured)                //~vbk6R~
//===============================================================================//~vbk4I~
//void csub_setcombineLayout(int Popt,PangoLayout *Pplayout,char *Ppdddata,char *Ppdddbcs,int Plen)//~vbk4I~//~vbk6R~
#ifdef AAA	//SCM is now controlled by xxescr:drawtextstr_NoLigatureu8_SCM//~vbk6I~
void csub_setcombineLayout(int Popt,PangoLayout *Pplayout,char *Ppdddata,char *Ppdddbcs,int Plen,int Pglyphctr,int Pscmctr)//~vbk6I~
#else                                                              //~vbk6I~
void csub_setcombineLayout(int Popt,PangoLayout *Pplayout,char *Ppdddata,char *Ppdddbcs,int Plen)//~vbk6I~
#endif                                                             //~vbk6I~
{                                                                  //~vbk4I~
  	GSList *tmp_list;                                              //~vbk4I~
  	PangoLayoutIter *iter;                                         //~vbk4I~
    PangoLayoutLine *line;                                         //~vbk4I~
    PangoLayoutRun *run;                                           //~vbk4I~
    PangoGlyphString *pglyphstr;                                   //~vbk4I~
    PangoGlyphInfo *pglyphinfo;                                    //~vbk4I~
    PangoGlyphGeometry *pgeom;                                     //~vbk4I~
    char *pdbcs,*pdata;                                            //~vbk4R~
    int ii,reslen;                                                 //~vbk4R~
    int oldw,chwidth,swcombine,glyphctr=0;                         //~vbk4R~
    gunichar ucs;                                                  //~vbk4I~
//  int scmctr=0,swscm;                                            //~vbk6R~
#ifdef AAA	//SCM is now controlled by xxescr:drawtextstr_NoLigatureu8_SCM//~vbk6I~
    int swscm;                                                     //~vbk6I~
#endif                                                             //~vbk6I~
//******************************                                   //~vbk4I~
  	iter = pango_layout_get_iter(Pplayout);                        //~vbk4I~
    line=pango_layout_iter_get_line (iter);                        //~vbk4I~
    if (!line)  //split dbcs is set to layout                      //~vbk4I~
        return;                                                    //~vbk4I~
    tmp_list=line->runs;                                           //~vbk4I~
UTRACEP("%s:layout=%p,opt=%x,len=%d,iter=%p,line=%p,runs=%p\n",UTT,Pplayout,Popt,Plen,iter,line,tmp_list);//~vbk4I~//~vbk6R~
UTRACED("Ppdddata",Ppdddata,Plen);                                 //~vbk4R~
UTRACED("Ppdddbcs",Ppdddbcs,Plen);                                 //~vbk4R~
  	pdata=Ppdddata;                                                //~vbk4I~
  	pdbcs=Ppdddbcs;                                                //~vbk4I~
    reslen=Plen;                                                   //~vbk4I~
  	while(tmp_list)                                                //~vbk4I~
  	{                                                              //~vbk4I~
    	run=tmp_list->data;                                        //~vbk4I~
    	if (!run)  //split dbcs is set to layout                   //~vbk4I~
        	return;                                                //~vbk4I~
    	pglyphstr=run->glyphs;                                     //~vbk4I~
    	if (!pglyphstr)  //split dbcs is set to layout             //~vbk4I~
        	return;                                                //~vbk4I~
    	for (ii=pglyphstr->num_glyphs,pglyphinfo=pglyphstr->glyphs;ii>0;ii--,pglyphinfo++)//~vbk4I~
    	{                                                          //~vbk4I~
        	pgeom=&(pglyphinfo->geometry);                         //~vbk4I~//~vbk6M~
        	glyphctr++;                                            //~vbk4I~//~vbk6M~
UTRACEP("%s:geometry glyphctr=%d,ii=%d/%d,width=%d=0x%x\n",UTT,glyphctr,pglyphstr->num_glyphs-ii,pglyphstr->num_glyphs,pgeom->width,pgeom->width);//~vbk6R~
        	swcombine=csub_iswidth0(0,pdata,pdbcs,reslen,&ucs,&chwidth);//~vbk4I~
#ifdef AAA	//SCM is now controlled by xxescr:drawtextstr_NoLigatureu8_SCM//~vbk6M~
            swscm=0;                                               //~vbk6I~
//          if (scmctr<Pscmctr)                                    //~vbk6R~
            if (Pscmctr)                                           //~vbk6I~
            {                                                      //~vbk6I~
            	ucs=UTF_GETDDUCS1(pdata,pdbcs,reslen);             //~vbk6I~
            	swscm=csub_isSpacingCombiningMark(0,ucs);          //~vbk6R~
//            	if (swscm)                                         //~vbk6R~
//            		scmctr++;                                      //~vbk6R~
            }                                                      //~vbk6I~
UTRACEP("%s:glyphctr=%d,ucs=%04x,swscm=%d\n",UTT,glyphctr,UTF_GETDDUCS1(pdata,pdbcs,reslen),swscm);//~vbk6R~
#endif                                                             //~vbk6I~
	    	oldw=pgeom->width;                                     //~vbk4I~
	    	oldw=oldw; //for compiler warning                      //~vbmpI~
//          if (oldw>0 && swcombine)                               //~vbk4I~//~vbkuR~
            if (swcombine)                                         //~vbkuI~
		    	pgeom->width|=CSUB_GEOMID_COMBINE;                 //~vbk4R~
#ifdef AAA	//SCM is now controlled by xxescr:drawtextstr_NoLigatureu8_SCM//~vbk6I~
            if (swscm)                                             //~vbk6I~
            {                                                      //~vbk6I~
				pgeom->width|=CSUB_GEOMID_SCM1;                    //~vbk6R~
//                pglyphinfo++;   //SCM is at next position of base(ii=0)//~vbk6R~
//                ii--;                                            //~vbk6R~
//                pgeom=&(pglyphinfo->geometry);                   //~vbk6R~
//                pgeom->width|=CSUB_GEOMID_SCM2;                  //~vbk6R~
		    	if (glyphctr>1)	//prev glyph exist                 //~vbk6I~
                {                                                  //~vbk6I~
                	pgeom=&((pglyphinfo-1)->geometry);             //~vbk6I~
	                pgeom->width|=CSUB_GEOMID_SCM2;                //~vbk6I~
                }                                                  //~vbk6I~
            }                                                      //~vbk6I~
UTRACEP("%s:geometry ii=%d/%d,glyphctr=%d,ucs=%04x,swcombine=%d,swscm=%d,oldw=0x%x,scm2 geom->width=0x%x,dddata=%02x,dddbcs=%02x,chwidth=%d\n",UTT,ii,pglyphstr->num_glyphs,glyphctr,ucs,swcombine,swscm,oldw,pgeom->width,*pdata,*pdbcs,chwidth);//~vbk4I~//~vbk6R~
#endif                                                             //~vbk6M~
UTRACEP("%s:geometry ii=%d/%d,glyphctr=%d,ucs=%04x,swcombine=%d,oldw=0x%x,geom->width=0x%x,dddata=%02x,dddbcs=%02x,chwidth=%d\n",UTT,ii,pglyphstr->num_glyphs,glyphctr,ucs,swcombine,oldw,pgeom->width,*pdata,*pdbcs,chwidth);//~vbk6I~
            pdata+=chwidth;                                        //~vbk4I~
            pdbcs+=chwidth;                                        //~vbk4I~
            reslen-=chwidth;                                       //~vbk4I~
    	}                                                          //~vbk4I~
    	tmp_list=tmp_list->next;                                   //~vbk4I~
  	}//runs                                                        //~vbk4I~
  	pango_layout_iter_free (iter);                                 //~vbk4I~
  	return;                                                        //~vbk4I~
}//csub_setcombineLayout                                           //~vbk4I~
#ifdef JJJ                                                         //~vbm8I~
//===============================================================================//~vbm8I~
//set comnining tbl for dd str                                     //~vbm8I~
//rc:split string ctr                                              //~vbm8R~
//===============================================================================//~vbm8I~
int csub_GetCombineIdTbl(int Popt,char *Ppu8,char *Ppdddata,char *Ppdddbcs,int Plen,int *Ppu8idxtbl,int *Ppddidxtbl)//~vbm8R~
{                                                                  //~vbm8I~
    char *pu8,*pdbcs,*pdata,*pu8start;                             //~vbm8R~
    int ii,idlen=0,combinectr=0,u8len,base,nocombstart,outidxctr;  //~vbm8R~
    int chwidth,swcombine,glyphctr,combinedglyphctr=0;             //~vbm8R~
    gunichar ucs;                                                  //~vbm8I~
    int wku8idx[MAXCOL+1],*pu8idx;                                 //~vbm8R~
    int wkddidx[MAXCOL+1],*pddidx;                                 //~vbm8I~
    int wkid[MAXCOL],*pid;                                         //~vbm8I~
//******************************                                   //~vbm8I~
UTRACED("Ppdddata",Ppdddata,Plen);                                 //~vbm8I~
UTRACED("Ppdddbcs",Ppdddbcs,Plen);                                 //~vbm8I~
	for (pu8=Ppu8,pdata=Ppdddata,pdbcs=Ppdddbcs,pid=wkid,pu8idx=wku8idx,pddidx=wkddidx,ii=0;ii<Plen;)//~vbm8R~
    {                                                              //~vbm8I~
    	swcombine=csub_iswidth0(0,pdata,pdbcs,Plen-ii,&ucs,&chwidth);//~vbm8I~
        *pid++=(char)swcombine?1:0;                                //~vbm8R~
        *pu8idx=PTRDIFF(pu8,Ppu8);                                 //~vbm8I~
        pu8+=UTF8CHARLEN(*pu8);                                    //~vbm8R~
        *pddidx=PTRDIFF(pdata,Ppdddata);                           //~vbm8I~
        if (swcombine)                                             //~vbm8I~
        	combinectr++;                                          //~vbm8I~
        pdata+=chwidth;                                            //~vbm8I~
        pdbcs+=chwidth;                                            //~vbm8I~
        ii+=chwidth;                                               //~vbm8I~
    }                                                              //~vbm8I~
    *pu8idx=PTRDIFF(pu8,Ppu8);	//next of last                     //~vbm8I~
    *pddidx=PTRDIFF(pdata,Ppdddata);	//next of last             //~vbm8I~
    idlen=PTRDIFF(pid,wkid);                                       //~vbm8R~
    UTRACEP("%s:combinectr=%d\n",UTT,combinectr);                  //~vbm8I~
    UTRACED("wkid",wkid,idlen);                                    //~vbm8R~
    UTRACED("wku8idx",wku8idx,idlen*(int)sizeof(int));             //~vbm8I~
    UTRACED("wkddidx",wkddidx,idlen*(int)sizeof(int));             //~vbm8I~
    if (!combinectr)                                               //~vbm8I~
    	return 0;                                                  //~vbm8I~
    base=-1;                                                       //~vbm8I~
    combinectr=0;                                                  //~vbm8I~
	for (pid=wkid,pu8idx=wku8idx,ii=0;ii<idlen;ii++)               //~vbm8R~
    {                                                              //~vbm8I~
    	swcombine=pid[ii];                                         //~vbm8I~
        if (swcombine)                                             //~vbm8I~
        {                                                          //~vbm8I~
        	if (!ii)                                               //~vbm8I~
            	base=0;                                            //~vbm8I~
            else                                                   //~vbm8I~
            	if (!pid[ii-1])	//not continued combine            //~vbm8I~
                {                                                  //~vbm8I~
        			base=ii-1;                                     //~vbm8I~
                    combinectr++;	//ctr of base+combine          //~vbm8I~
                }                                                  //~vbm8I~
            combinectr++;                                          //~vbm8I~
        }                                                          //~vbm8I~
        else                                                       //~vbm8I~
        {                                                          //~vbm8I~
        	if (combinectr)                                        //~vbm8I~
            {                                                      //~vbm8I~
            	pu8start=Ppu8+wku8idx[base];                       //~vbm8R~
            	u8len=wku8idx[base+combinectr]-wku8idx[base];      //~vbm8R~
            	glyphctr=csub_ChkCombineGlyph(0,pu8start,u8len);   //~vbm8R~
                if (glyphctr!=combinectr)                          //~vbm8I~
                {                                                  //~vbm8I~
                	wkid[base]|=(combinectr<<1);                   //~vbm8I~
                	combinedglyphctr++;                            //~vbm8I~
                }                                                  //~vbm8I~
            }                                                      //~vbm8I~
            combinectr=0;                                          //~vbm8I~
        }                                                          //~vbm8I~
    }                                                              //~vbm8I~
    UTRACEP("%s:combinedglyphctr=%d\n",UTT,combinedglyphctr);      //~vbm8I~
    UTRACED("wkid",wkid,idlen);                                    //~vbm8I~
    if (!combinedglyphctr)                                         //~vbm8I~
    	return 0;                                                  //~vbm8I~
    nocombstart=-1;                                                //~vbm8I~
	for (pid=wkid,pu8idx=Ppu8idxtbl,pddidx=Ppddidxtbl,ii=0,outidxctr=0;ii<idlen;ii++)//~vbm8I~
    {
    	swcombine=pid[ii]>>1;                                      //~vbm8I~
        if (swcombine)
        {
        	if (nocombstart>=0)                                    //~vbm8I~
            {                                                      //~vbm8I~
            	*pu8idx++=wku8idx[nocombstart];                    //~vbm8I~
                *pu8idx++=wku8idx[ii]-wku8idx[nocombstart];        //~vbm8I~
            	*pddidx++=wkddidx[nocombstart];                    //~vbm8I~
                *pddidx++=wkddidx[ii]-wkddidx[nocombstart];        //~vbm8I~
                outidxctr++;                                       //~vbm8I~
                nocombstart=-1;                                    //~vbm8I~
            }                                                      //~vbm8I~
            *pu8idx++=wku8idx[ii];                                 //~vbm8I~
            *pu8idx++=wku8idx[ii+swcombine]-wku8idx[ii];           //~vbm8I~
            *pddidx++=wkddidx[ii];                                 //~vbm8I~
            *pddidx++=wkddidx[ii+swcombine]-wkddidx[ii];           //~vbm8I~
            outidxctr++;                                           //~vbm8I~
        }
        else
        {
        	if (nocombstart<0)                                     //~vbm8I~
            	nocombstart=ii;                                    //~vbm8I~
        }
    }
    if (nocombstart>=0)                                            //~vbm8I~
    {                                                              //~vbm8I~
    	*pu8idx++=wku8idx[nocombstart];                            //~vbm8I~
        *pu8idx++=wku8idx[idlen]-wku8idx[nocombstart];             //~vbm8I~
        *pddidx++=wkddidx[nocombstart];                            //~vbm8I~
        *pddidx++=wkddidx[idlen]-wkddidx[nocombstart];             //~vbm8I~
        outidxctr++;                                               //~vbm8I~
    }                                                              //~vbm8I~
  	return outidxctr;                                              //~vbm8R~
}//csub_GetCombineIdTbl                                            //~vbm8I~
//===============================================================================//~vbm8I~
//chk glyphctr for combining                                       //~vbm8I~
//===============================================================================//~vbm8I~
int csub_ChkCombineGlyph(int Popt,char *Ppu8,int Pu8len)           //~vbm8R~
{                                                                  //~vbm8I~
	int layoutinfo[CSUBLI_MAX],glyphctr;                           //~vbm8I~
	static PangoLayout *Splayout;                                  //~vbm8I~
//******************************                                   //~vbm8I~
	if (!Splayout)                                                 //~vbm8I~
		Splayout=gtk_widget_create_pango_layout(Gpview,NULL);      //~vbm8I~
	pango_layout_set_text(Splayout,Ppu8,Pu8len);                   //~vbm8I~
	csublyoutinfo(0,Splayout,layoutinfo);                          //~vbm8I~
	glyphctr=layoutinfo[CSUBLI_CTR];                               //~vbm8I~
  	return glyphctr;                                               //~vbm8I~
}//csub_ChkCombineGlyph                                            //~vbm8R~
#else                                                              //~vbm8I~
//===============================================================================//~vbm8I~
//set combine substring index                                      //~vbm8R~
//rc:combining string ctr                                          //~vbm8I~
//*out idtbl                                                       //~v7f4I~
//*1:sbcs combining, 2:combinable prev char, 3:dbcs combining 2nd, 4:dbcs not combining 2nd//~v7f4I~
//===============================================================================//~vbm8I~
//int csub_GetCombineStrTbl(int Popt,char *Ppu8,int Pu8len,char *Ppdddata,char *Ppdddbcs,int Pddlen,int *Ppu8idxtbl,int *Ppddidxtbl)//~vbm8R~//~vbmbR~
int csub_GetCombineStrTbl(int Popt,char *Ppu8,int Pu8len,char *Ppdddata,char *Ppdddbcs,int Pddlen,int *Ppu8idxtbl,int *Ppddidxtbl,char *Ppw0tbl)//~vbmbI~
{                                                                  //~vbm8I~
    char *pdbcs,*pdata,*pu8;                                       //~vbm8R~
    int ii,idlen=0,combinectr=0,base;                              //~vbm8R~
    int chwidth,swcombine,strctr,swstr,*poutu8,*poutdd;            //~vbm8R~
#ifndef KKK                                                        //~v7f4I~
    int swcombineW0NOCOMB;                                         //~v7f4I~
#endif                                                             //~v7f4I~
    gunichar ucs;                                                  //~vbm8I~
    gunichar ucso; //uint                                          //~vbmfR~
    int wkddidx[MAXCOL+1],*pddidx;                                 //~vbm8I~
    int wku8idx[MAXCOL+1],*pu8idx;                                 //~vbm8I~
    char wkid[MAXCOL],*pid;                                        //~vbm8R~
    char *pidprev;                                                 //~vbmfI~
    int ucsctr,baseucsctr;                                         //~vbmbR~
//******************************                                   //~vbm8I~
UTRACED("Ppu8",Ppu8,Pu8len);                                       //~vbm8R~
UTRACED("Ppdddata",Ppdddata,Pddlen);                               //~vbm8I~
UTRACED("Ppdddbcs",Ppdddbcs,Pddlen);                               //~vbm8R~
    ucsctr=0;                                                      //~vbmbI~
    ucs=0;                                                         //~vbmfI~
    memset(wkid,0,sizeof(wkid));                                   //~vbmfI~
	for (pu8=Ppu8,pdata=Ppdddata,pdbcs=Ppdddbcs,pid=wkid,pu8idx=wku8idx,pddidx=wkddidx,ii=0;ii<Pddlen;)//~vbm8R~
    {                                                              //~vbm8I~
        ucso=ucs;                                                  //~vbmfI~
#ifdef JJJ                                                         //~v7f4I~
    	swcombine=csub_iswidth0(0,pdata,pdbcs,Pddlen-ii,&ucs,&chwidth);//~vbm8R~
#else                                                              //~v7f4I~
		int optcic=0;	                                           //~v7f4I~
#ifndef KKK                                                        //~v7f4I~
		optcic|=CICO_RCNOCOMB;	//rc=8 for FMT                     //~v7f4R~
#endif                                                             //~v7f4I~
        swcombine=csub_iscombining(optcic,pdata,pdbcs,Pddlen-ii,&ucs,&chwidth);	//no format,combine only//~v7f4R~
#ifndef KKK                                                        //~v7f4I~
    	swcombineW0NOCOMB=0;                                       //~v7f4I~
      if (swcombine & UICRC_NOCOMB)   //rc of utf_iscombining      //~v7f4R~
      {                                                            //~v7f4I~
    	swcombineW0NOCOMB=1;                                       //~v7f4I~
	    swcombine=0;                                               //~v7f4I~
      }                                                            //~v7f4I~
#endif                                                             //~v7f4I~
#endif                                                             //~v7f4I~
        if ((int)ucs<0)	//!swcombine                               //~vbmfR~
			ucs=UTF_GETDDUCS1VIO(pdata,pdbcs,Pddlen-ii,&chwidth);  //~vbmfI~
        UTRACEP("%s:ii=%d,chsz=%d,ucs=%06x,ucso=%06x,swcombine=%d\n",UTT,ii,chwidth,ucs,ucso,swcombine);              //~vbm8I~//~vbmfR~
#ifndef KKK                                                        //~v7f4I~
    	if (swcombineW0NOCOMB)                                     //~v7f4I~
        {                                                          //~v7f4I~
        	*pid=(char)ID_W0NOCOMB; //5                            //~v7f4R~
        	combinectr++;                                          //~v7f4I~
	        UTRACEP("%s:W0NOCOMB ii=%d,ucs=%06x\n",UTT,ii,ucs);    //~v7f4R~
        }                                                          //~v7f4I~
        else                                                       //~v7f4I~
#endif                                                             //~v7f4I~
        if (swcombine)                                             //~vbm8I~
        {                                                          //~vbm8I~
        	*pid=(char)1;                                          //~vbm8R~
            if (chwidth==2)  //have to consider overflow combining //~vbm8I~
                *++pid=3;                                          //~vbm8I~//~vbmbR~
        	combinectr++;                                          //~vbm8M~
            if (ii>0)                                              //~vbmfI~
            {                                                      //~vbmfI~
                pidprev=pid-1;                                     //~vbmfR~
                if (*pidprev==4)    //dbcs 2nd                     //~vbmfR~
                    pidprev--;                                     //~vbmfR~
                if (!*pidprev)                                     //~vbmfR~
                	if (UTF_COMBINABLE(ucso))                      //~vbmfI~
			            *pidprev=2;	//combinable                   //~vbmfR~
            }                                                      //~vbmfI~
        }                                                          //~vbm8I~
        else                                                       //~vbm8I~
        {                                                          //~vbm8I~
//  		ucs=UTF_GETDDUCS1VIO(pdata,pdbcs,Pddlen-ii,&chwidth);  //~vbm8I~//~vbmfR~
//          *pid=(char)(UTF_COMBINABLE(ucs)?2:0);      //allow space,2:combinable base//~vbm8R~//~vbmfR~
            if (chwidth==2)  //dbcs 2nd                            //~vbmbR~
                *++pid=4;                                          //~vbmbI~
        }                                                          //~vbm8I~
        pid++;                                                     //~vbm8I~
        *pu8idx++=PTRDIFF(pu8,Ppu8);                               //~vbm8R~
        *pddidx++=PTRDIFF(pdata,Ppdddata);                         //~vbm8I~
        pu8+=UTF8CHARLEN(*pu8);                                    //~vbm8I~
        pdata+=chwidth;                                            //~vbm8I~
        pdbcs+=chwidth;                                            //~vbm8I~
        ii+=chwidth;                                               //~vbm8I~
        ucsctr++;                                                  //~vbmbI~
    }                                                              //~vbm8I~
    *pu8idx=PTRDIFF(pu8,Ppu8);	//next of last                     //~vbm8R~
    *pddidx=PTRDIFF(pdata,Ppdddata);	//next of last             //~vbm8I~
    ucsctr++;                                                      //~vbmbI~
    idlen=PTRDIFF(pid,wkid);                                       //~vbm8I~
    UTRACEP("%s:combinectr=%d\n",UTT,combinectr);                  //~vbm8I~
    UTRACED("wkid",wkid,idlen);                                    //~vbm8I~
    UTRACED("wku8idx",wku8idx,ucsctr*(int)sizeof(int));         //~vbm8R~//~vbmbR~
    UTRACED("wkddidx",wkddidx,ucsctr*(int)sizeof(int));         //~vbm8R~//~vbmbR~
    if (!combinectr)                                               //~vbm8I~
    	return 0;                                                  //~vbm8I~
    memcpy(Ppw0tbl,wkid,(size_t)Pddlen);                           //~vbmbI~
    base=-1;                                                       //~vbm8I~
    strctr=0;                                                      //~vbm8I~
    swstr=0;                                                       //~vbm8R~
    ucsctr=0;                                                      //~vbmbI~
    baseucsctr=0;                                                  //~vbmbI~
	for (pid=wkid,poutu8=Ppu8idxtbl,poutdd=Ppddidxtbl,ii=0;ii<idlen;ii++,pid++)//~vbm8R~
    {                                                              //~vbm8I~
    	swcombine=*pid;                                            //~vbm8I~
        if (swcombine==3)    //ovf combine                         //~vbm8I~
            continue;                                              //~vbm8I~
        if (swcombine==4)    //dbcs 2nd                            //~vbmbI~
            continue;                                              //~vbmbI~
#ifndef KKK                                                        //~v7f4I~
    	if (swcombine==ID_W0NOCOMB) 	//5                        //~v7f4I~
        {                                                          //~v7f4I~
            base=ii;                                               //~v7f4I~
            baseucsctr=ucsctr;                                     //~v7f4I~
            if (!swstr)                                            //~v7f4I~
            {                                                      //~v7f4I~
            	*poutdd++=base;                                    //~v7f4I~
            	*poutu8++=wku8idx[baseucsctr];                     //~v7f4I~
            	swstr=1;                                           //~v7f4I~
            	strctr++;                                          //~v7f4I~
            }                                                      //~v7f4I~
        }                                                          //~v7f4I~
        else                                                       //~v7f4I~
#endif                                                             //~v7f4I~
        if (swcombine==1)                                          //~vbm8I~
        {                                                          //~vbm8I~
        	if (!ii)                                               //~vbm8I~
            	base=0;                                            //~vbm8I~
            else                                                   //~vbm8I~
            {                                                      //~vbm8I~
            	if (*(pid-1)==2)	//combinable                   //~vbm8I~
                {                                                  //~vbmbI~
        			base=ii-1;                                     //~vbm8I~
                    baseucsctr=ucsctr-1;                           //~vbmbI~
                }                                                  //~vbmbI~
                else                                               //~vbm8I~
            	if (*(pid-1)==4)	//dbcs combinable              //~vbmbI~
                {                                                  //~vbmbI~
        			base=ii-2;                                     //~vbmbI~
                    baseucsctr=ucsctr-1;                           //~vbmbI~
                }                                                  //~vbmbI~
                else                                               //~vbmbI~
            	if (!swstr)	//combinable                           //~vbm8I~
                {                                                  //~vbmbI~
                	base=ii;                                       //~vbm8I~
                    baseucsctr=ucsctr;                             //~vbmbI~
                }                                                  //~vbmbI~
            }                                                      //~vbm8I~
            if (!swstr)                                            //~vbm8I~
            {                                                      //~vbm8I~
            	*poutdd++=base;                                    //~vbm8R~
            	*poutu8++=wku8idx[baseucsctr];                     //~vbm8R~//~vbmbR~
            	swstr=1;                                           //~vbm8R~
            	strctr++;                                          //~vbm8R~
            }                                                      //~vbm8I~
        }                                                          //~vbm8I~
        else                                                       //~vbm8I~
        {                                                          //~vbm8I~
        	if (swstr)                                             //~vbm8I~
            {                                                      //~vbm8I~
	            *poutdd++=ii; 	//pos after combining str          //~vbm8R~
//              *poutu8++=wku8idx[ii]; 	//pos after combining str  //~vbm8I~//~vbmbR~
                *poutu8++=wku8idx[ucsctr]; 	//pos after combining str//~vbmbR~
                swstr=0;                                           //~vbm8I~
            }                                                      //~vbm8I~
        }                                                          //~vbm8I~
        ucsctr++;                                                  //~vbmbI~
    }                                                              //~vbm8I~
    if (swstr)                                                     //~vbm8I~
    {                                                              //~vbm8I~
//  	*poutu8++=wku8idx[ii]; 	//pos after combining str          //~vbm8R~//~vbmbR~
    	*poutu8++=wku8idx[ucsctr]; 	//pos after combining str      //~vbmbI~
		*poutdd++=ii; 	//pos after combining str                  //~vbm8I~
    }                                                              //~vbm8I~
    UTRACEP("%s:strctr=%d\n",UTT,strctr);                          //~vbm8I~
    UTRACED("Ppu8idxtbl",Ppu8idxtbl,strctr*2*(int)sizeof(int));    //~vbm8R~
    UTRACED("Ppddidxtbl",Ppddidxtbl,strctr*2*(int)sizeof(int));    //~vbm8R~
  	return strctr;                                                 //~vbm8I~
}//csub_GetCombineStrTbl                                           //~vbm8I~
#endif                                                             //~vbm8I~
//===============================================================================//~vbk6I~
//set monospaceing for SCM                                         //~vbk6I~
// write 2 ucs(prev+SCM) or 1 ucs(SCM aplit)                       //~vbk6I~
//===============================================================================//~vbk6I~
int usetmonospace_SCM(int Popt,PangoLayout *Pplayout,int Pucsctr,int Pcellw)//~vbk6I~
{                                                                  //~vbk6I~
  	GSList *tmp_list;                                              //~vbk6I~
  	PangoLayoutIter *iter;                                         //~vbk6I~
    PangoLayoutLine *line;                                         //~vbk6I~
    PangoLayoutRun *run;                                           //~vbk6I~
    PangoGlyphString *pglyphstr;                                   //~vbk6I~
    PangoGlyphInfo *pglyphinfo;                                    //~vbk6I~
    PangoGlyphGeometry *pgeom1,*pgeom2;                            //~vbk6I~
    int wwpango,glyphctr;                                          //~vbk6I~
    int scm1w,rc;                                                  //~vbk6I~
//******************************                                   //~vbk6I~
  	iter = pango_layout_get_iter(Pplayout);                        //~vbk6I~
    line=pango_layout_iter_get_line (iter);                        //~vbk6I~
    if (!line)  //split dbcs is set to layout                      //~vbk6I~
        return 4;                                                  //~vbk6I~
    tmp_list=line->runs;                                           //~vbk6I~
UTRACEP("%s:layout=%p,opt=%x,ucsctr=%d\n",UTT,Pplayout,Popt,Pucsctr);//~vbk6I~//~vbmeR~
    rc=4;                                                          //~vbk6I~
    wwpango=Pcellw*PANGO_SCALE;                                    //~vbk6I~
  	while(tmp_list)                                                //~vbk6I~
  	{                                                              //~vbk6I~
    	run=tmp_list->data;                                        //~vbk6I~
    	if (!run)  //split dbcs is set to layout                   //~vbk6I~
        	break;                                                 //~vbk6I~
    	pglyphstr=run->glyphs;                                     //~vbk6I~
    	if (!pglyphstr)  //split dbcs is set to layout             //~vbk6I~
        	break;                                                 //~vbk6I~
    	glyphctr=pglyphstr->num_glyphs;                            //~vbk6I~
		UTRACEP("%s:glyphctr=%d\n",UTT,glyphctr);                  //~vbmeI~
#ifdef QQQ                                                         //~vbksI~
        if (glyphctr!=2)                                           //~vbk6I~
#else                                                              //~vbksI~
        if (glyphctr<2)                                            //~vbksI~
#endif                                                             //~vbksI~
        	break;                                                 //~vbk6I~
    	pglyphinfo=pglyphstr->glyphs;                              //~vbk6I~
	    pgeom1=&(pglyphinfo->geometry);                            //~vbk6I~
        scm1w=pgeom1->width;                                       //~vbk6I~
		UTRACEP("%s:geometry1 offs_x=%d,offs_y=%d,width=%d cellw=%d\n",UTT,pgeom1->x_offset,pgeom1->y_offset,pgeom1->width,wwpango);//~vbk6I~//~vbmeR~
    	pglyphinfo++;                                              //~vbk6I~
	    pgeom2=&(pglyphinfo->geometry);                            //~vbk6I~
		UTRACEP("%s:geometry2 offs_x=%d,offs_y=%d,width=%d cellw=%d\n",UTT,pgeom2->x_offset,pgeom2->y_offset,pgeom2->width,wwpango);//~vbk6I~//~vbmeR~
        pgeom2->width=wwpango*2-scm1w;                             //~vbk6I~
        UTRACEP("%s:SCM1 new scm2w=0x%x\n",UTT,pgeom2->width);     //~vbk6R~
#ifndef QQQ                                                        //~vbksI~
        if (glyphctr>2)                                            //~vbksI~
        {                                                          //~vbksI~
	    	pglyphinfo++;                                          //~vbksI~
		    pgeom2=&(pglyphinfo->geometry);                        //~vbksI~
	        UTRACEP("%s:SCM1 new scm3w=0x%x\n",UTT,pgeom2->width); //~vbksI~
        }                                                          //~vbksI~
#endif                                                             //~vbksI~
        rc=0;                                                      //~vbk6I~
        break;                                                     //~vbk6I~
    }                                                              //~vbk6I~
  	pango_layout_iter_free (iter);                                 //~vbk6I~
    UTRACELAYOUT(Pplayout);                                        //~vbk6I~
    UTRACEP("%s:return rc=%d\n",UTT,rc);                           //~vbk6I~
  	return rc;                                                     //~vbk6I~
}//usetmonospace_SCM                                               //~vbk6I~
