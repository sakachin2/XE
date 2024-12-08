//CID://+v9j4R~:        update#=   1120                            //~v9j4R~
//**********************************************************************
//* xplnxp.c                                                       //~v980R~
//**********************************************************************
//v9j4:240630 (LNX)size in fontname by int                         //~v9j4I~
//v9j3:240629 ubuntu; font size is rounddown to integer and cause wide margin at right.//~v9j3I~
//            rown up to next integer and apply scale(it works)    //~v9j3I~
//v9j1:240629 cairo scaling did not work?(line overflow page width)//~v9j1R~
//v9i0:201217 Debian10 compiler warning                            //~v9i0I~
//v9h0:180129 gnome2 obsoleted                                     //~v9h0R~
//v9g0:180129 (Ubuntu 17.10:gcc7.2)Lnx warning not reachable       //~v9g0I~
//v9c0:170128 v9.36 Gtk3 deprecated                                //~v9c0I~
//v9b0:161220 v9.35 warning when NOTRACE or GTK3                   //~v9b0I~
//v9a2:160623 v9.33 issue msg "-qfile is not supported by gxp"     //~v9a2I~
//v9a1:160418 v9.33 LNX64 Compiler warning                         //~v9a1I~
//v9a0:160418 v9.33 LNX compiler warning                           //~v9a0I~
//v992:150529 v9.31 uerrmsg parm count err by xuerpck              //~v992I~
//v991:140624 v9.30 s390x compiler warning                         //~v991I~
//v98q:140312 v9.29 print selected papersize                       //~v98qI~
//v98n:140214 no need to get margin from ppd,PageSetup prepare it. //~v98nI~
//v98m:140213 select default papersize which was set by printer setting//~v98mI~
//v98k:140209 confirm GtkPaperSize and ppd not by sequence but by name//~v98kI~
//v98j:140209 Margin by double                                     //~v98jI~
//v98i:140208 (BUG)Paper width/haight re-evaluation is required when orientation was changed by dialog//~v98iI~
//v98h:140208 v98g is no effect;add margin option because sorigin shift may cut opposit side.//~v98hI~
//v98g:140208 (GTK:BUG?)confusing b5 an jb5 for papersize;ppd is valid for papersize//~v98gI~
//v98f:140208 try not fullpage to avoid edge cut by margin         //~v98aI~
//v98e:140208 (BUG)if printer changed by dialog,paper list was not changed//~v98eI~
//v98d:140207 (BUG)errexit by printer "" not found  if no default printer defined.//~v98dI~
//v98c:140206 forced to default printer if dislog was not opened   //~v98cI~
//v98b:140206 (BUG)multiple printer err when -q is default printer //~v98bI~
//v98a:140206 simple shift parameter(previous shift function is expand papersize as custom paper size//~v98aI~
//			  to avoid printer warning of papersize unmatch)       //~v98aI~
//v989:140203 (BUG) could not select printer by multiple match. select it when fully match.//~v989I~
//v988:140201 default margin by gtkpaperlist is common to all,get from ppd//~v988I~
//v987:140201 (BUG)when papersize change by dialog,need to adjust maxcol/maxline//~v987I~
//v986:140131 (BUG)papersize change by dialog had no effect        //~v986I~
//v985:140130 2 job was submit by init_dialogt,use printunix dialog
//v984:140130 tray wait requrest_details                           //~v984I~
//v983:140130 display displaynem of papersize for -e/? like as print operation dialog//~v983I~
//v982:140130 gtk_print_list_papers use ppd internaly but fail because reuest_detail is asynchronous("details_acquired" signal handling:see gtkprintunixdialog)//~v982I~
//v981:140128 gtk_print_operation_run returns cancelled when not action:dialog//~v981I~
//v980:140128 gtk3 support                                         //~v980I~
//v97r:131110 (BUG)utf8 null(x00)will cut text string              //~v97rI~
//v97p:131110 hexline monospace(vhex and hhex partially)           //~v97pI~
//v97m:131104 (gxp)header print err for utf8 filename;chk utf8 encoding for filename//~v97mI~
//v97h:131104 conjunct mode subheader should be monospace          //~v97hI~
//v97d:131030 reuse widget without destroy(avoid flicker)          //~v97dI~
//v97c:131029 chk pagerange of printdialog                         //~v97cI~
//v97b:131029 abandon v97a(printer do not expand paper width to landscape width)//~v97bI~
//v97a:131027 -E/A4L/P P:rotate option for printer was not set to Landscape//~v97aI~
//v979:131027 display printer list by -q?                          //~v979I~
//v977:131025 (gxp)other pagesize support by margin shift          //~v977I~
//v976:131024 (Lnx:Bug)eucjp dbcs was not printed                  //~v976I~
//v975:131022 (GtkPrint)option of scaling for each line if width overflow//~v975I~
//v973:131011 (GtkPrint)new form option(E[w]/form[L](2p is by /Y2 only)//~v973I~
//v970:130922 GtkPrint for alternative of Gnomeprint               //~v970I~
//121219 v96c (Lnx)chk result of cupsGetDests(report from .at; folowing free() was crashed on RHEL5.73)//~v96cI~
//120613 v966 warning(variable may not be uninitialized) on FC12   //~v966I~
//111117 v964 (gcc4.6)Warning:unused-but-set                       //~v964I~
//101115 v963 V9.21 compiler warning, unused variable              //~v963I~
//100909 v955 v9.19 print EBC file by TextOutW for avoid print "?" for trans err to locale code//~v955I~
//100802 v951 v9.18(BUG)rc not initialized;errmsg issued printertype!=W for utf8//~v951I~
//100706 v950 v9.18 64bit compile                                  //~v950I~
//100706 v944 (gxp)accept cups destination by -q parameter         //~v944I~
//            (use gtk because update of gpa_root by cups printer is done through asyncrronous gtk dispatching system)//~v944I~
//090414 v92v (LNX)compiler warning                                //~v92vI~
//071024 v92n (LNX)support utf8 file(conv to locale)               //~v92nI~
//071024 v92m (GXP)warning "missing /Mu" when locale2utf8 conversion err//~v92mI~
//071014 v92h (GXP)color parameter                                 //~v92hI~
//071013 v92f (Win/gxp)auto-set maxcol/maxline when not predefined pich specified//~v92fI~
//071006 v92d (Lnx)UTF8 support                                    //~v92dI~
//**********************************************************************
#include <time.h>     //v1.1
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>    //v1.6add
#include <string.h>   //v1.3add
#include <locale.h>   //v1.3add                                    //~v92dI~

//**********************************************************************
#ifndef OPTGTK3                                                    //~v980I~
#include <gnome.h>                                                 //~v92dI~
#else                                                              //~v980I~
	#include <gtk/gtk.h>                                           //~v980I~
//  #include <libgnome/libgnome.h>                                 //~v9h0R~
//#endif                                            0              //~v9i0R~
#endif                //                            0              //~v9i0I~
#ifdef GTKPRINT                                                    //~v96cI~
	#ifndef OPTGTK3                                                //~v980I~
	#include <gtk/gtkprinter.h>                                //~vam0R~//~v973I~
	#include <gtk/gtkprintunixdialog.h>                            //~v985I~
	#else                                                          //~v980I~
		#include <gtk/gtkunixprint.h>                              //~v980I~
	#endif                                                         //~v980I~
#else                                                              //~v96cI~
#ifndef OPTGTK3                                                    //~v980I~
#include <libgnomeprint/gnome-print.h>                             //~v92dI~
#include <libgnomeprint/gnome-print-job.h>                         //~v92dI~
#include <libgnomeprint/gnome-print-unit.h>                        //~v92dI~
#include <libgnomeprint/gnome-print-paper.h>                       //~v92dI~
#else                                                              //~v980I~
#endif                                                             //~v980I~
#endif                                                             //~v96cI~
#include <cups/cups.h>                                             //~v92dM~
#include <pthread.h>                                               //~v985I~
#ifdef GTKPRINT                                                    //~v97bI~
#include <cups/ppd.h>                                              //~v97bI~
#endif                                                             //~v97bI~
#ifdef BBB                                                         //~v92dI~
#include <libgnomeprint/private/gpa-node.h>                        //~v92dI~
#include <libgnomeprint/private/gpa-root.h>                        //~v92dI~
#include <libgnomeprint/private/gpa-printer.h>                     //~v92dI~
#include <libgnomeprint/private/gnome-print-config-private.h>      //~v92dI~
#endif                                                             //~v92dI~
//**********************************************************************

#include <ulib.h>                                                  //~v844R~
#include <ufile.h>                                                 //~v844R~
#include <ustring.h>                                               //~v844I~
#include <utrace.h>                                                //~v91fI~
#include <uerr.h>                                                  //~v92dI~
#include <ucvucs.h>                                                //~v92dI~
#include <uedit.h>                                                 //~v92dI~
#include <utf.h>                                                   //~v92mI~
#include <ualloc.h>                                                //~v9h0I~

#include "xp.h"
#include "xplnxp.h"                                                //~v92dR~
#include "xp2p.h"                                                  //~v914I~
#include "xpesc.h"                                                 //~v916I~
#include "xputf.h"                                                 //~v928I~
#ifdef GTKPRINT                                                    //~v970I~
	#include "xpdesp.h"                                            //~v970I~
#endif                                                             //~v970I~
//#define NOPPD _PPD_DEPRECATED	//deprecated in cups 1.6           //~v9h0R~
#define	CUPS_CHECK_VERSION(major,minor,micro)	\
    (CUPS_VERSION_MAJOR > (major) || \
     (CUPS_VERSION_MAJOR == (major) && CUPS_VERSION_MINOR > (minor)) || \
     (CUPS_VERSION_MAJOR == (major) && CUPS_VERSION_MINOR == (minor) && \
      CUPS_VERSION_PATCH >= (micro)))                              //~v9h0I~
#if CUPS_CHECK_VERSION(1,6,0)                                      //~v9h0I~
	#define NOPPD                                                  //~v9h0I~
#endif                                                             //~v9h0I~
//*********************************************************************
//	int Gprint_color=DEFAULT_PRINTCOLOR;                           //~v92hI~//~v9a0R~
  	unsigned Gprint_color=DEFAULT_PRINTCOLOR;                      //~v9a0I~
	int Gl2uconverr=0;                                             //~v92mI~
	int Gdrawpagectr;                                              //~v97cI~
//*********************************************************************//~v92hI~
extern char *prn;				//output dest name                 //~v92dM~
extern int Gformtype;	     	//orientation,form                 //~v92dM~
extern int Gtraceopt;			//trace option to stdout           //~v92dM~
extern int Gzoomh,Gzoomw;       //zoom rate                        //~v92dM~
extern int lineskip;   //1:double space,2:tripple space            //~v92dM~
extern int maxline;                                                //~v92dR~
extern int maxcol;                                                 //~v92dI~
extern int despageno;           //total page of despage print      //~v92dM~
extern int breakpage;           //current page count from last for despage print//~v92dM~
extern int hdr0linesw;       //in xppf,header0 print req           //~v92dM~
extern int skip1stff2;       //1st formfeed skip option            //~v92dM~
extern int esccmdlen;          //esccmd lenngth     ..v2.9add v3.6rep//~v92dM~
extern int outdevprn;          //esccmd lenngth     ..v2.9add v3.6rep//~v92dI~
extern char *fontstyle;                                            //~v92dI~
extern int lineprefixsw;    //lineno output                        //~v92dI~
extern char docname[];                                             //~v970I~
extern char header1[];                                             //~v970I~
extern int  header1len;                                            //~v970I~
extern int pagerangectr;		//entry no of pagerange            //~v97cI~
extern int  totpage;         //v4.1a total page count              //~v97cI~
extern int  dbcsenv;           //dbcs environment sw v4.9a v7.23r  //~v97cI~
extern FILE *Gmsgfile;       //for print start msg                 //~v90mI~//~v97cI~
extern char pgmid[];     //v7.1a v7.23r                            //~v831I~//~v97cI~
extern char ver[]; 		    //v7.1a v7.23r                         //~v831I~//~v97cI~
extern int pagestart;        //print page range v3.2add            //~v97cI~
extern int pageend;    //print page range v3.2add      v3.6r       //~v97cI~
extern int  realpage;				//real output page count    v5.8a//~v97cI~
extern int  page;                                                  //~v97cI~
extern int Linecharpos;       //char dump colomn in line           //~v97pI~
extern char Hexline1[];		//record hexdump hex first 4bit v6.7a  //~v97pR~
extern char Hexline2[];		//record hexdump hex first 4bit v6.7a  //~v97pR~
extern int linespec;      //line option specified                  //~v987R~
//**********************************************************************
#define ugettid() pthread_self()                                   //~v984I~
#if GTK_CHECK_VERSION(2,12,0)                                      //~v981I~
	#define GTKV2120                                               //~v981I~
#endif                                                             //~v981I~
#if GTK_CHECK_VERSION(2,14,0)                                      //~v98mI~
	#define GTKV2140         //gtk_printer_get_default_paper_size()//~v98mI~
#endif                                                             //~v98mI~
#if GTK_CHECK_VERSION(2,20,0)                                      //~v987I~
	#define GTKV2200                                               //~v987I~
#endif                                                             //~v987I~
                                                                   //~v988I~
#ifdef NNN                                                         //~v98nI~
typedef struct _UPPDSZ {                                           //~v988R~
	ppd_size_t UPPDSZppdsz;                                        //~v988R~
    char       UPPDSZdisplayname[1];                               //~v988R~
} UPPDSZ,*PUPPDSZ;                                                 //~v988I~
#define UPPDSZSIZE sizeof(UPPDSZ)                                  //~v988R~
#endif  //NNN                                                      //~v98nI~
#ifdef NOPPD                                                       //~v9h0I~
    typedef struct _PageSize                                       //~v9h0I~
            {                                                      //~v9h0I~
                char *displayname;                                 //~v9h0R~
                ppd_size_t ppdsz;                                  //~v9h0R~
            } PageSize;                                            //~v9h0I~
    #define SZ_PAGESIZE sizeof(PageSize)                           //~v9h0I~
#endif                                                             //~v9h0R~
//PANGO_SCALE 1024                             //defined in pango-types.h//~v9i0I~
//PANGO_PIXELS_FLOOR(val) (((int)(val))>>10)   //defined in pango-types.h//~v9i0I~
#define PANGO_SCALE_FLOOR_DOUBLE(value)  (   ((double)( (int)((value)*PANGO_SCALE)  ))/PANGO_SCALE ) //get floor by PANGO_SCALE//~v970R~
#define PANGO_SCALE_FLOOR_INT(value)  ( ( (double)(  ((value)*PANGO_SCALE)  ) )/PANGO_SCALE )//get floor by PANGO_SCALE//~v970R~
#define FMAX(f1,f2) ((f1)>(f2)?f1:f2)                              //~v977I~
#define FMIN(f1,f2) ((f1)>(f2)?f2:f1)                              //~v977I~
#define DEF_PRINTER     "Default"                                  //~v981I~
#define GET_TOP_PRINTER     "1"                                    //~v981I~
#ifdef GTKPRINT                                                    //~v970I~
#define DEFAULT_FONTNAME    "Monospace"                            //~v970R~
#else                                                              //~v970I~
#define DEFAULT_FONTNAME    "Sans Regular 10"                      //~v92dR~
#endif                                                             //~v970I~
#ifdef GTKPRINT                                                    //~v970I~
#define DEFAULT_FONTSIZE    72.0                                   //~v970I~
#else                                                              //~v970I~
#define DEFAULT_FONTSIZE    10.0                                   //~v92hR~
#endif                                                             //~v970I~
#define PRINTGERR(comment,pgerr) {if (pgerr!=NULL) lnx_printgerror((char*)__FUNCTION__,__LINE__,comment,pgerr);}//~v92dR~
#define INCHESBYMM      ((float)1.0/(float)25.4)       //1inch=25.4mm//~v92fI~
#define INCHESBYPOINT   ((float)1.0/(float)72.0)      //1inch=72 point//~v92fR~
#define POINTSBYMM      (INCHESBYPOINT/INCHESBYMM)     // (x/72point)inch*25.4mm//~v98aI~
                                                                   //~v92dI~
#define MAXELF 4            	//4 candidate                      //~v844R~
//#define TOPMARGIN  10           //default page top margin by mm  //~v98jR~
//#define LEFTMARGIN 10           //default page left margin       //~v98jR~
#define TOPMARGIN  10.0           //default page top margin by mm  //~v98jI~
#define LEFTMARGIN 10.0           //default page left margin       //~v98jI~
#define MIN_RIGHTM 30.0           //minimum right margin for not monospace font//~v9j1I~
#define PAGEHEIGHT  297         //mm A4 portrate                   //~v92dI~
#define PAGEWIDTH   210         //mm A4 portrate                   //~v92dI~
                                                                   //~v989I~
//static  int     Sfontid;        //parm to callback func          //~v92dR~
static  int Sopendocsw,Sopenpagesw;                                //~v844R~
//static  int Sfontfoundsw;                                        //~v92dR~
static  int Spagewidth=PAGEWIDTH,Spageheight=PAGEHEIGHT;	//pixel of DC//~v92dR~
#ifdef GTKPRINT                                                    //~v970I~
static  double Sinchwidthpixel,Sinchheightpixel;	//inch by pixel//~v970I~
#else                                                              //~v970I~
static  int Sinchwidthpixel,Sinchheightpixel;	//inch by pixel    //~v844R~
#endif                                                             //~v970I~
#ifndef GTKPRINT                                                   //~v975I~
static  int Scharwidth;                                            //~v92dR~
static  int Slineheight;                                           //~v844I~
#endif                                                             //~v975I~
//static  int Sleftmargin=LEFTMARGIN;                              //~v98jR~
//static  int Srightmargin=LEFTMARGIN;                             //~v98jR~
//static  int Stopmargin=TOPMARGIN;                                //~v98jR~
//static  int Sbottommargin=TOPMARGIN;                             //~v98jR~
static  double Sleftmargin=LEFTMARGIN;                             //~v98jI~
static  double Srightmargin=LEFTMARGIN;                            //~v98jI~
static  double Stopmargin=TOPMARGIN;                               //~v98jI~
static  double Sbottommargin=TOPMARGIN;                            //~v98jI~
static  gdouble Sposx,Sposy,Sposy1st;                              //~v92dR~
static  int Srightpageposx;      //right page start pos            //~v904I~
static  int Sendjobsw;                                             //~v844I~
static  int Sfontw,Sfonth;                                         //~v92dI~
static  int Sgtkinit;                                              //~v981I~
//**********************************************************************//~v92dI~
#ifdef GTKPRINT                                                    //~v96cI~
#else  //!GTKPRINT                                                 //~v96cI~
static  GnomePrintConfig     *Spgpconfig;                          //~v92dR~
static  GnomePrintContext    *Spgpcontext;                         //~v92dR~
static  GnomePrintJob        *Spgpjob;                             //~v92dR~
#endif //!GTKPRINT                                                 //~v96cI~
static  PangoFontDescription *Sppangofd;                           //~v92dR~
static  PangoContext         *Sppangocontext;                      //~v92dI~
static  PangoLanguage        *Sppangolanguage;                     //~v92dI~
#ifdef GTKPRINT                                                    //~v96cI~
#else  //!GTKPRINT                                                 //~v96cI~
static  GnomeFont            *Spgfont;                             //~v92dR~
#endif //!GTKPRINT                                                 //~v96cI~
//static  PangoLayout          *Splayout;                          //~v92dR~
                                                                   //~v92dI~
static  int Sisutf8;                                               //~v92dI~
#ifdef GTKPRINT                                                    //~v970I~
#else  //!GTKPRINT                                                 //~v970I~
static  gdouble Sffontsz;                                          //~v92dI~
#endif //!GTKPRINT                                                 //~v970I~
static  int Sfontsizespecifiedsw; 	//font size is not specified   //~v92dR~
static  gdouble Sfontascendant;                                    //~v92dR~
static  GIConv Sconverterdescriptor=0;                             //~v92dI~
static const char *Scurrent_charsetname=0;                         //~v92dI~
static gdouble Sfscalex,Sfscaley,Sffontscale;                      //~v92dR~
static gdouble Slineheightf,Scharwidthf;                           //~v92dI~
static gdouble Slinewidthf;                                        //~v975I~
#define CUPS_DESTSZ  80                                            //~v944I~
#ifdef GTKPRINT                                                    //~v96cI~
#else  //!GTKPRINT                                                 //~v96cI~
static  GnomePrintConfig *Spprtconf;                               //~v944I~
#endif //!GTKPRINT                                                 //~v96cI~
static char Scupsprinter[CUPS_DESTSZ];                             //~v944I~
static int Sswcancel;                                              //~v944I~
#ifdef GTKPRINT
	static char Sdest[CUPS_DESTSZ];                                //~v970R~
    static GtkPrintOperation *Spoperation;                         //~v970R~
    static GtkPrintSettings *Spsettings;                           //~v970R~
	static int Sflushphase;                                        //~v970I~
	static int Srealpagectr;                                       //~v970I~
	static GtkWidget *Smainwindow;                                 //~v970I~
  	static GtkWidget *Sbutton_can;                                 //~v97mI~
	static GtkLabel *Slabel;                                       //~v97dR~
    static cairo_t *Spcairocontext;                                //~v970R~
    static PangoLayout *Splayout;                                  //~v970I~
    static PangoLayout *SplayoutLineno;                            //~v970R~
    static int Sswapply;                                           //~v970I~
    static double Sfont_height_by_size;	//height-pixel/font-size   //~v970I~
    static double Sfont_width_by_size;	//width/size rate          //~v970I~
//  static char* Scupspapersizename;                               //~v98aR~
    static int Scupspaperorientation;                              //~v973I~
    static int Scupspaperlistsize;                                 //~v973I~
//    static ppd_size_t *Sppdsz;                                   //~v970R~
    static GtkPaperSize *Sppapersz;                                //~v970I~
    static FRECT Sfmargins;                                        //~v970I~
    static FRECT SfmarginsA4;                                      //~v977I~
    static int SpagewidthA4,SpageheightA4;                         //~v977R~
    static char *Sselectedfontface;                                //~v970I~
    static int Smonospacefont;                                     //~v975I~
    static double Scharwidthf_scaled;	//for monospacing          //~v970I~
//  static int Slandscape_orientation=GTK_PAGE_ORIENTATION_LANDSCAPE;//~v970R~
    static int Slandscape_orientation=GTK_PAGE_ORIENTATION_REVERSE_LANDSCAPE;   //page top is now ink left//~v970I~
//  static int SshiftdistanceV,SshiftdistanceH;                    //~v98aR~
    static double SshiftdistanceV,SshiftdistanceH;                 //~v98aI~
    static int Sshiftdirection;                                    //~v977I~
#ifdef MMM                                                         //~v98hI~
    static int Sshiftdirectionorigin;                              //~v98aI~
#endif                                                             //~v98hI~
    #define SD_TOP       0x01                                      //~v977I~
    #define SD_BOT       0x02                                      //~v977I~
    #define SD_LEFT      0x04                                      //~v977I~
    #define SD_RIGHT     0x08                                      //~v977I~
#ifndef MMM                                                        //~v98hI~
    #define SD_TOPM      0x0100                                    //~v98hI~
    #define SD_BOTM      0x0200                                    //~v98hI~
    #define SD_LEFTM     0x0400                                    //~v98hI~
    #define SD_RIGHTM    0x0800                                    //~v98hI~
#endif                                                             //~v98hI~
    static int Spagerangectr;                                      //~v97cI~
    static int Spagestart,Spageend;                                //~v97cI~
    static GtkPageRange *Spagerange; //start,end:0 base pageno     //~v97cR~
	static GtkPrinter *SsrchprinterGtk,*SdefaultprinterGtk;        //~v981I~
    static int Shavedetail=-1;                                     //~v984I~
    static GList *Sglprinter;                                      //~v984I~
    static int Sglprinterinit;                                     //~v984I~
	static GMainLoop *Sloop;                                       //~v984I~
	static int Sotherform;                                         //~v987I~
                                                                   //~v989I~
	#ifdef   GTKV2200      //2.20                                  //~v989I~
    	double Shardmarginl,Shardmarginr,Shardmargint,Shardmarginb;//~v989R~
	#endif //GTKV2120                                              //~v989I~
    double Sxshift,Syshift;                                        //~v98aR~
#ifndef MMM                                                        //~v98hI~
    double Sparmmargint,Sparmmarginb,Sparmmarginl,Sparmmarginr;    //~v98hI~
#endif                                                                   //~v989M~//~v98hR~
	#ifdef GTKV2140                                                //~v98mI~
		static char Sprinterdefaultpapersize[sizeof(Gpapersizeparm)];//~v98mR~
		char *get_printer_defaultpapersize(GtkPrinter *Ppprinter,char *Pform);//~v98mR~
    #endif                                                         //~v98mI~
#endif //!GTKPRINT
//**********************************************************************
void lnx_closepage(void);                                          //~v92dI~
void lnx_newpage(void);                                            //~v92dI~
//void lnx_opendoc(int Phmi,int Pvmi,char *Pdocname);              //~v970R~
#ifdef GTKPRINT                                                    //~v970I~
	INT lnx_searchfont(int Popt,char *Pstr);                       //~v970I~
    #define SFO_LIST   0x01     //list fontname                    //~v970R~
#else  //!GTKPRINT                                                 //~v970I~
INT lnx_searchfont(char *Pstr);                                    //~v92dR~
#endif //!GTKPRINT                                                 //~v970I~
void lnx_getdcinf(void);                                           //~v92dI~
void lnx_createlogfont(int Phmi,int Pvmi);                         //~v92dI~
#ifdef GTKPRINT                                                    //~v96cI~
#else  //!GTKPRINT                                                 //~v96cI~
GnomePrintContext *lnx_createdc(void);                             //~v92dI~
#endif //!GTKPRINT                                                 //~v96cI~
#ifdef GTKPRINT                                                    //~v970I~
int lnx_initdm(GtkPrintOperation *Ppppo,GtkPrintSettings *Ppsettings);//~v970R~
#else  //!GTKPRINT                                                 //~v970I~
int lnx_initdm(void);                                              //~v92dI~
#endif //!GTKPRINT                                                 //~v970I~
#ifdef GTKPRINT                                                    //~v96cI~
void lnx_getconfig(char *Ppprinter);                               //~v970I~
#else  //!GTKPRINT                                                 //~v96cI~
GnomePrintConfig *lnx_getconfig(char *Pprinter);                   //~v92dI~
#endif //!GTKPRINT                                                 //~v96cI~
#ifdef UTF8SUPP                                                    //~v92hI~
//  int lnx_ucs2utf8(USHORT *Ppucs,int Plen,char **Pputf8,int *Ppwritelen);//~v92hR~//~v950R~
    int lnx_ucs2utf8(WUCS *Ppucs,int Plen,char **Pputf8,int *Ppwritelen);//~v950I~
#endif                                                             //~v92hI~
int lnx_locale2utf8(char *Ptext,int Plen,int *Ppreadlen,char **Pputf8,int *Ppwritelen);//~v92dR~
void lnx_textout(int Popt,gdouble Pposx,gdouble Pposy,char *Pdata,int Plen);//~v92dR~
int lnx_utf8init(void);                                            //~v92dI~
void lnx_printgerror(char *Pfile,int Pline,char *Pcmt,GError *Ppgerr);//~v92dI~
#ifdef GTKPRINT                                                    //~v96cI~
PangoFontDescription *lnx_createfont(char *Pfontname,gdouble Pffontsz);//~v970R~
#else  //!GTKPRINT                                                 //~v96cI~
GnomeFont *lnx_createfont(char *Pfontname,gdouble Pffontsz);       //~v92dR~
#endif //!GTKPRINT                                                 //~v96cI~
void lnx_getfontmetrics(PangoFontDescription *Pfontdesc,int *Ppwidth,int *Ppheight);//~v92dI~
PangoLanguage *lnx_getpangolang(void);                             //~v92dI~
int lnx_portchk(char *Poutid);                                     //~v92dI~
#ifdef GTKPRINT                                                    //~v970I~
	void lnx_setscale(int Pfontw,int Plinecols);                   //~v970R~
#else                                                              //~v970I~
void lnx_setscale(void);                                           //~v92dI~
#endif                                                             //~v970I~
void lnx_lineout(gdouble Pposx0,gdouble Pposy0,gdouble Pposx1,gdouble Pposy1);//~v92dI~
int lnx_setconfigprinter(char *Ppprinter);                         //~v944I~
#ifdef GTKPRINT                                                    //~v970I~
	void lnx_setpapersize(GtkPrintSettings *Ppsettings);           //~v970R~
	void *lnx_getpapersize(int Popt/*free*/,char *Pformtype,gdouble *Ppww,gdouble *Pphh);//~v970I~
	#define CSGPS_FREE     0x01                                    //~v970I~
	int printdialogGtk(int Popt,GtkWidget *Pparent);               //~v970R~
    #define PDGO_INIT      0x01 //initial open printer dialog      //~v970I~
	void lnx_setcolorGtk(cairo_t *Ppct);                           //~v970I~
	void lnx_papersizeinit();                                      //~v970I~
	void chkglyphextent(PangoFontDescription *Ppfd);               //~v970I~
	double getstringxscale();                                      //~v970I~
	void lnx_setlayoutoption();                                    //~v970R~
	void chklayoutextent(PangoLayout *Pplayout,PangoRectangle *Pprect);                   //~v970I~//~v975R~
	void usetmonospace(int Popt,PangoLayout *Pplayout,double Pcellw);//~v970I~
	void lnx_showlayout(cairo_t *Pcr,PangoLayout *Pplayout,char *Pptext,int Plen,double Plinewidth);//~v975R~
	int lnx_ismonospace(PangoFontDescription *Ppfd);               //~v975R~
	int lnx_chkfontsize(int Pmonospace,PangoFontDescription *Ppfd,int *Ppww,int *Pphh);//~v975R~
	GtkPaperSize *getCustomPapersize(char *Ppform,char *Pinternalname,ppd_size_t *Pppgsz,FRECT *Ppfrect);//~v977I~
	void getshiftparm(char *Pparm);                                //~v977I~
#ifdef MMM                                                         //~v98hI~
	void shiftpaperorigin(double Pwidth,double Pheight,double *Ppxshift,double *Ppyshift);//~v98aI~
#else                                                              //~v98hI~
	void applyparmmargin(FRECT *Ppfrect,double Pww,double Phh);    //~v98hM~
#endif                                                             //~v98hM~
	GtkPaperSize *lnx_srchGtkPaperSize(int Popt,char *Pprinter,char *Ppform,PFRECT Ppfmargin);//~v977R~
    #define SGPSO_NOSHIFT       0x01                               //~v977I~
    #define SGPSO_GETDEFAULTPAPERSIZE  0x02 	//get default papersize set by printer setting//~v98mI~
	void getDialogPageRange(GtkPrintSettings *Ppsettings);         //~v97cR~
	int getDialogNpage(int Pnpage);                                //~v97cI~
	int getDialogSelectpage(int Pdrawpage);                        //~v97cI~
	void printedmsg();                                             //~v97cI~
	int isallascii(char *Pputf8,int Plen);                         //~v97pI~
	GtkPrinter *srchprinterGtk(char *Pprintername,char *Pprealname);//~v981I~
	GList *getcupspaperlistGtk(GtkPrinter *Ppprinter);             //~v981I~
#ifdef NNN                                                         //~v98nR~
	void getpapersizewh(int Popt,GtkPaperSize *Ppps,FRECT *Ppfrect,double *Ppfwidth,double *Ppfheight);//~v985I~
#else                                                              //~v98nR~
	void getpapermarginwh(GtkPaperSize *Ppps,GtkPageSetup *Ppsetup,FRECT *Ppfrect,double *Ppfwidth,double *Ppfheight);//~v98nR~
#endif                                                             //~v98nR~
	#define GPS_EDGE 		0x01   //set edge width                //~v985I~
	#define GPS_BOTTOMLEFT  0x02   //set margin position by origin=BottomLeft//~v985R~
	GtkPageSetup *create_pagesetup(GtkPrintSettings*);             //~v989R~
	void printPaperSize(char *Pname,char *Pdisplayname);           //~v98aI~
#endif //GTKPRINT                                                  //~v970I~
char *getdisplayname(ppd_file_t *Pppd,char *Ppapersize);           //~v988I~
//****************************************************             //~v92dI~
//**********************************************************************//~v92dM~
//* setup FONT object                                              //~v92dM~
//parm:fontname or NULL if no parm specified                       //~v92dM~
//**********************************************************************//~v92dM~
int lnx_init(int argc,char **argv)                                 //~v92dR~
{                                                                  //~v92dM~
static int Sinitsw=0;                                              //~v92dM~
#define PACKAGE "gxp"                                              //~v92dM~
#define PACKAGE_DATA_DIR "/usr/local/share"                        //~v92dM~
#ifndef NOGNOME2                                                   //~v9h0I~
	char *version=VER;        //vxx.yy fmt                         //~v92dM~
#endif                                                             //~v9h0I~
//  cups_dest_t  *pl,*pl0;                                         //~v92hR~
//  int pn;                                                        //~v92hR~
    int rc;                                                        //~v92hI~
//  GList  *paperlist=NULL;                                        //~v92hR~
//  GnomePrintPaper *ppp;                                          //~v92hR~
    char *pdest;                                                   //~v92dI~
    char  prncups[CUPS_DESTSZ];                                    //~v944R~
//********************************                                 //~v92dM~
    UTRACEP("lnx_init Sinitsw=%d,outdevprn=%d,prn=%s,othropt=%x,lineprefixsw=%d\n",Sinitsw,outdevprn,prn,Gxpotheropt,lineprefixsw);//~v970R~//~v97rR~
    UTRACEP("lnx_init tid=%p\n",ugettid());                        //~v984I~
	if (UCBITCHK(swsw4,SW4OUTSTDO))                                //~v970I~
    	return 0;		    //outdevprn=0:to file                  //~v970I~
	if (Sinitsw)                                                   //~v92dM~
    	return 1;                                                  //~v92dR~
    Sinitsw=1;                                                     //~v92dM~
#ifdef ENABLE_NLS                                                  //~v92dI~
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);            //~v92dI~
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");              //~v92dI~
  textdomain (GETTEXT_PACKAGE);                                    //~v92dI~
#endif                                                             //~v92dI~
#ifndef NOGNOME2                                                   //~v9h0I~
#ifndef OPTGTK3                                                    //~v980I~
	gnome_program_init (PACKAGE,version+1,                         //~v92dM~
//  					LIBGNOMEUI_MODULE,//libgnomeui_module_info_get();//~v92dM~//~v981R~
    					LIBGNOME_MODULE,  //no gnomeui but gtkprint//~v981R~
                      argc, argv,                                  //~v92dM~
                      GNOME_PARAM_APP_DATADIR, PACKAGE_DATA_DIR,   //~v92dM~
                      NULL);                                       //~v92dM~
#else                                                              //~v980I~
	gnome_program_init (PACKAGE,version+1,                         //~v980I~
    					LIBGNOME_MODULE,                           //~v980I~
                      argc, argv,                                  //~v980I~
                      GNOME_PARAM_APP_DATADIR, PACKAGE_DATA_DIR,   //~v980I~
                      NULL);                                       //~v980I~
#endif                                                             //~v980I~
#endif //NOGNOME2                                                  //~v9h0I~
//  setlocale(LC_ALL,"");   //for pango_language_get_default()     //~v92nR~
//*******                                                          //~v92dI~
//#ifdef AAA                                                       //~v96cR~
//    pn=cupsGetDests(&pl0);                                       //~v96cR~
//    for (pl=pl0;pn>0;pn--,pl++)                                  //~v96cR~
//        printf("cups printer list=%s\n",pl->name);               //~v96cR~
//    free(pl0);  //free printer list                              //~v96cR~
//    paperlist=gnome_print_paper_get_list();                      //~v96cR~
//    while(paperlist!=NULL)                                       //~v96cR~
//    {                                                            //~v96cR~
//        ppp=(GnomePrintPaper*)(paperlist->data);                 //~v96cR~
//        printf("formsize %s ww=%lf,hh=%lf\n",ppp->name,ppp->width,ppp->height);//~v96cR~
//        paperlist=paperlist->next;                               //~v96cR~
//    }                                                            //~v96cR~
//#endif                                                           //~v96cR~
//**********                                                       //~v92dI~
    if (!outdevprn)	//dest is not "prn"                            //~v92dR~
    {                                                              //~v92dI~
//      pdest=prn;                                                 //~v944R~
//  	rc=lnx_portchk(prn);	//chk qname                        //~v944R~
        strcpy(prncups,prn);    //for case sensitive               //~v944I~
        pdest=prncups;                                             //~v944I~
    	rc=lnx_portchk(prncups);	//chk qname                    //~v944I~
    	if (!rc)    //print to file                                //~v92dI~
        {                                                          //~v944I~
#ifdef GTKPRINT                                                    //~v970M~
//    	uerrexit("%s is invalid destination. (\"%cQ?\" will show destination list.) ",//~v979I~//~v9a2R~
//    		      "宛先 %s が見つかりません. (\"%cQ?\" でリストされます)",//~v979I~//~v9a2R~
      	uerrexit("%s is invalid destination. (\"%cQ?\" will show destination list. gxp dose not support file as destination.)",//~v9a2R~
      		      "宛先 %s が見つかりません. (\"%cQ?\" でリストされます｡gxp はファイル出力はサポートしていません)",//~v9a2I~
            	Gqparm,CMDFLAG_PREFIX);                            //~v979I~
#endif                                                             //~v970I~
            printf("Print to file:%s\n",prn);                      //~v944I~
        	return rc;                                             //~v92dI~
        }                                                          //~v944I~
#ifdef GTKPRINT                                                    //~v970I~
		if (!(Gxpotheropt & GOO_PRINTDIALOG))                      //~v970I~
	        if (strcmp(pdest,prn))	//partial match                //~v970R~
    	        printf("%s was selected\n",pdest);                 //~v970R~
#endif                                                             //~v970I~
        if (rc==2)	//cups default printer                         //~v944I~
        {                                                          //~v944I~
            printf("%s is default printer\n",pdest);               //~v944I~
	        pdest=0;                                               //~v944I~
        }                                                          //~v944I~
    }                                                              //~v92dI~
    else        //!prn etc                                         //~v92dI~
    {                                                              //~v951I~
        pdest=0;                                                   //~v92dI~
        rc=outdevprn;                                              //~v951I~
    }                                                              //~v951I~
#ifdef GTKPRINT                                                    //~v970I~
    lnx_getconfig(pdest);                                          //~v970I~
    if (outdevprn)	//PRN,LPT1..                                   //~v970I~
		if (!(Gxpotheropt & GOO_PRINTDIALOG))                      //~v970I~
            printf("%s is default printer\n",Sdest);               //~v970I~
#else  //!GTKPRINT                                                 //~v970I~
    Spgpconfig=lnx_getconfig(pdest);                               //~v92dR~
	Spgpcontext=lnx_createdc();                                    //~v92dR~
#endif //!GTKPRINT                                                 //~v970I~
    lnx_getdcinf();           //get resolusion                     //~v92dM~
    return rc;	//outdevprn                                        //~v92dR~
}//lnx_init                                                        //~v92dM~

#ifdef GTKPRINT                                                    //~v96cI~
//===============================================================================//~v92dM~
//get default printer                                              //~v970R~
//parm:printername,NULL if use default                             //~v970R~
//===============================================================================//~v92dM~
//GnomePrintConfig *lnx_getconfig(char *Ppprinter)                 //~v970R~
void lnx_getconfig(char *Ppprinter)                                //~v970I~
{                                                                  //~v92dM~
//  GnomePrintConfig *pprtconf;                                    //~v970R~
//  char *poldprinter;                                             //~v970R~
    char  defaultprinter[CUPS_DESTSZ]={0};                         //~v970I~
//  gchar *pprinter;                                               //~v944R~
//************************************                             //~v92dM~
//  Spprtconf=                                                     //~v970R~
//  pprtconf=gnome_print_config_default();                         //~v970R~
//  poldprinter=gnome_print_config_get(pprtconf,"Printer");        //~v970R~
//  if (Ppprinter && *Ppprinter)	//printer specified            //~v970R~
//  {                                                              //~v970R~
//  	if (strcmp(Ppprinter,poldprinter))	//not default          //~v970R~
//      {                                                          //~v970R~
//      	lnx_setconfigprinter(Ppprinter);                       //~v970R~
//      }                                                          //~v970R~
//  }                                                              //~v970R~
//  return pprtconf;                                               //~v970R~
    if (!Ppprinter) //default printer                              //~v970I~
    {                                                              //~v970I~
    	lnx_portchk(defaultprinter);	//chk qname                //~v970I~
	    strcpy(Sdest,defaultprinter);                              //~v970R~
    }                                                              //~v970I~
    else                                                           //~v970I~
	    strcpy(Sdest,Ppprinter);                                   //~v970R~
    UTRACEP("lnx_getconfig parmdest=%s,Sdest=%s\n",Ppprinter,Sdest);//~v970R~
	lnx_papersizeinit();	//set Sppapersz                        //~v970R~
   	lnx_setconfigprinter(Sdest);                                   //~v970R~
}//lnx_getconfig                                                   //~v92dM~
#else  //!GTKPRINT                                                 //~v96cI~
//===============================================================================//~v92dM~
//get default config                                               //~v92dM~
//parm1:prev pointer to be freed                                   //~v92dM~
//parm2:printer name to be set to config                           //~v92dM~
//ret  :new config                                                 //~v92dM~
//===============================================================================//~v92dM~
GnomePrintConfig *lnx_getconfig(char *Ppprinter)                   //~v92dM~
{                                                                  //~v92dM~
    GnomePrintConfig *pprtconf;                                    //~v92dM~
    char *poldprinter;                                             //~v92dM~
//  gchar *pprinter;                                               //~v944R~
#ifdef BBB                                                         //~v92dR~
	GPANode *node, *printers, *child;                              //~v92dI~
	GSList *list, *l;                                              //~v92dI~
	GtkWidget *dialog;                                             //~v92dI~
	GtkWidget *option_menu;                                        //~v92dI~
	gint len;                                                      //~v92dI~
#endif                                                             //~v92dI~
//************************************                             //~v92dM~
	Spprtconf=                                                     //~v944I~
    pprtconf=gnome_print_config_default();                         //~v92dM~
#ifdef AAA                                                         //~v92dI~
    gnome_print_config_dump(pprtconf);  //dump to stdout           //~v92dR~
#endif                                                             //~v92dI~
    poldprinter=gnome_print_config_get(pprtconf,"Printer");        //~v92dM~
//  printf("config'%p) printer before=%s,req=%s\n",pprtconf,poldprinter,Ppprinter);//~v92hR~
    if (Ppprinter && *Ppprinter)	//printer specified            //~v92dM~
    {                                                              //~v92dM~
    	if (strcmp(Ppprinter,poldprinter))	//not default          //~v92dM~
        {                                                          //~v92dM~
#ifdef CCC                                                         //~v944I~
		    pprinter=g_new(gchar,strlen(Ppprinter)+1); //required to avoid "WARNING: Could not GPAReference"//~v92dI~
    		strcpy(pprinter,Ppprinter);                            //~v92dM~
//          printf("usleepms %d\n",usleepms(1000));                //~v92dR~
        	gnome_print_config_set(pprtconf,"Printer",pprinter);   //~v92dM~
//          printf("usleepms %d\n",usleepms(1000));                //~v92dR~
//    		printf("config printer after=%s,qfile=%s\n",gnome_print_config_get(pprtconf,"Printer"),Ppprinter);//~v92hR~
#else                                                              //~v944I~
        	lnx_setconfigprinter(Ppprinter);                       //~v944R~
//  	    pprtconf=gnome_print_config_default();                 //~v944R~
//  		printf("poldprinter after=%s\n",gnome_print_config_get(pprtconf,"Printer"));//~v944R~
#endif                                                             //~v944I~
        }                                                          //~v92dM~
    }                                                              //~v92dM~
#ifdef BBB                                                         //~v92dR~
	node = gnome_print_config_get_node(pprtconf);                  //~v92dI~
    printf("node %p\n",node);                                      //~v92dI~
//	printers = gpa_node_get_child_from_path (node, "Globals.Printers");//~v92dR~
  	printers = GPA_NODE(gpa_get_printers());                       //~v92dI~
    printf("printers %p\n",printers);                              //~v92dI~
	list = NULL;                                                   //~v92dI~
	child = gpa_node_get_child (printers, NULL);                   //~v92dI~
	for (; child != NULL; child = gpa_node_get_child (printers, child))//~v92dI~
    {                                                              //~v92dI~
          printf("usleepms %d\n",usleepms(1000));                  //~v92dI~
		list = g_slist_prepend (list, child);                      //~v92dI~
		l = list;                                                  //~v92dI~
		while (l) {                                                //~v92dI~
			printf("printer %s\n", gpa_node_id (l->data));         //~v92dI~
			l = l->next;                                           //~v92dR~
          printf("usleepms %d\n",usleepms(1000));                  //~v92dI~
            }                                                      //~v92dI~
    }                                                              //~v92dI~
#endif                                                             //~v92dI~
	return pprtconf;                                               //~v92dM~
}//lnx_getconfig                                                   //~v92dM~
#endif //!GTKPRINT                                                 //~v96cI~
//**********************************************************************//~v860I~
//* search printer                                                 //~v970R~
//parm:output destination name ptr                                 //~v860I~
//ret :1:output is printer,0:output is file                        //~v860I~
//     2:output is default                                         //~v970I~
//**********************************************************************//~v860I~
#ifdef GTKPRINT
//=========================================================================
int lnx_portchk(char *Poutid)                                      //~v92dR~
{                                                                  //~v860I~
    int rc;                                                        //~v860R~
    cups_dest_t  *pl,*pl0;                                         //~v944I~
    int pn,swdefault=0;                                            //~v944I~//~v970R~
    int pn0;                                                       //~v96cI~
    int dupctr=0;                                                  //~v970I~
    char *parmname=NULL;                                           //~v970I~
    int ctr=0;                                                     //~v979I~
//********************************                                 //~v860I~
	UTRACEP("lnx_portchk parm=%s\n",Poutid);                       //~v970I~
//  if (!stricmp(Poutid,"PRN"))                                    //~v970R~
//  	return 1;                                                  //~v970R~
    pn=cupsGetDests(&pl0);                                         //~v944I~
  if (pn)                                                          //~v96cI~
  {                                                                //~v96cI~
    pn0=pn;                                                        //~v96cI~
    for (pl=pl0;pn>0;pn--,pl++)                                    //~v944I~
    {                                                              //~v944I~
    	UTRACEP("lnx_portchk Gtk cups printer list=%s\n",pl->name);                //~v944I~//~v970R~
        if (*Poutid=='?')                                          //~v979I~
        {                                                          //~v979I~
            ctr++;                                                 //~v979I~
	        if (pl->is_default)                                    //~v979I~
            	printf("%s. (This is default)\n",pl->name);        //~v979R~
            else                                                   //~v979I~
            	printf("%s.\n",pl->name);                          //~v979R~
        }                                                          //~v979I~
        else                                                       //~v979I~
        if (!*Poutid)                                              //~v970I~
        {                                                          //~v970I~
	        swdefault=(pl->is_default!=0);                         //~v970I~
	        if (swdefault)                                         //~v970I~
            {                                                      //~v970I~
            	strcpy(Poutid,pl->name);	//for case err         //~v970I~
        		break;                                             //~v970I~
            }                                                      //~v970I~
        }                                                          //~v970I~
        else                                                       //~v970I~
      {                                                            //~v98bI~
        if (!stricmp(pl->name,Poutid))                             //~v989I~
        {                                                          //~v989I~
	        swdefault=(pl->is_default!=0);                         //~v989I~
            strcpy(Poutid,pl->name);	//correct case             //~v98cI~
            dupctr=1;                                              //~v989I~
        	break;                                                 //~v989I~
        }                                                          //~v989I~
        if (ustrstri(pl->name,Poutid))                             //~v944R~
        {                                                          //~v944I~
          if (!dupctr)	                                           //~v970I~
          {                                                        //~v970I~
          	parmname=strdup(Poutid);                               //~v970I~
	        swdefault=(pl->is_default!=0);                         //~v944I~
            strcpy(Poutid,pl->name);	//for case err             //~v944I~
          }                                                        //~v970I~
//      	break;                                                 //~v944I~//~v970R~
            dupctr++;                                              //~v970I~
        }                                                          //~v944I~
      }                                                            //~v98bI~
    }                                                              //~v944I~
//  free(pl0);  //free printer list                                //~v96cR~
    cupsFreeDests(pn0,pl0);  //free printer list                   //~v96cI~
  }                                                                //~v96cI~
    if (*Poutid=='?')                                              //~v979I~
    {                                                              //~v979I~
        uerrexit("%d destinations was listed.\n",0,ctr);           //~v979R~
    }                                                              //~v979I~
  	if (dupctr>1)                                                  //~v970I~
  	{                                                              //~v970I~
    	uerrexit("multiple destination for \"%s\"\n",              //~v970R~
    	         "複数の宛先が\"%s\"に一致します\n",               //~v970I~
        		parmname);                                         //~v970I~
  	}                                                              //~v970I~
    else                                                           //~v970I~
    if (dupctr)                                                    //~v970R~
    	pn=1;	//found                                            //~v970I~
	free(parmname);                                                //~v970I~
    if (!*Poutid && !swdefault)                                    //~v98dI~
        uerrexit("No default printer defined",0);                  //~v98dI~
  if (pn>0)                                                        //~v944I~
  	rc=1+swdefault;                                                //~v944R~
  else                                                             //~v944I~
	rc=0;                                                          //~v92dI~
    UTRACEP("lnx_portchk rc=%d,parm=%s\n",rc,Poutid);              //~v970I~
    return rc;                                                     //~v860R~
}//lnx_portchk                                                     //~v92fR~
#else  //!GTKPRINT
//=========================================================================
int lnx_portchk(char *Poutid)                                      //~v92dR~
{                                                                  //~v860I~
    int rc;                                                        //~v860R~
    cups_dest_t  *pl,*pl0;                                         //~v944I~
    int pn,swdefault;                                              //~v944I~
    int pn0;                                                       //~v96cI~
//********************************                                 //~v860I~
    if (!stricmp(Poutid,"PRN"))                                    //~v860R~
    	return 1;                                                  //~v860I~
    pn=cupsGetDests(&pl0);                                         //~v944I~
  if (pn)                                                          //~v96cI~
  {                                                                //~v96cI~
    pn0=pn;                                                        //~v96cI~
    for (pl=pl0;pn>0;pn--,pl++)                                    //~v944I~
    {                                                              //~v944I~
    	UTRACEP("cups printer list=%s\n",pl->name);                //~v944I~
        if (ustrstri(pl->name,Poutid))                             //~v944R~
        {                                                          //~v944I~
	        swdefault=(pl->is_default!=0);                         //~v944I~
            strcpy(Poutid,pl->name);	//for case err             //~v944I~
        	break;                                                 //~v944I~
        }                                                          //~v944I~
    }                                                              //~v944I~
//  free(pl0);  //free printer list                                //~v96cR~
    cupsFreeDests(pn0,pl0);  //free printer list                   //~v96cI~
  }                                                                //~v96cI~
  if (pn>0)                                                        //~v944I~
  	rc=1+swdefault;                                                //~v944R~
  else                                                             //~v944I~
	rc=0;                                                          //~v92dI~
    UTRACEP("lnx_portchk rc=%d,parm=%s\n",rc,Poutid);              //~v970I~
    return rc;                                                     //~v860R~
}//lnx_portchk                                                     //~v92fR~
#endif //!GTKPRINT
//**********************************************************************
//* setup FONT object
//parm:fontname or NULL if no parm specified                       //~v844R~
//**********************************************************************
#ifdef GTKPRINT
//=========================================================================
//=from scfontchk                                                  //~v970I~
//=========================================================================//~v970I~
void lnx_setupfont(char *Pfontnm)                                  //~v92dR~
{
	int ww,hh,sz;                                                  //~v970R~
//************************                                         //~v92dI~
	if (UCBITCHK(swsw4,SW4OUTSTDO))                                //~v970I~
        return;                                                    //~v970I~
    if (Pfontnm && *Pfontnm=='?')	//listup fontname              //~v92dR~
    {                                                              //~v92dI~
		lnx_searchfont(SFO_LIST,Pfontnm+1);                        //~v970R~
        exit(4);                                                   //~v92dR~
    }                                                              //~v92dI~
    Sppangocontext=gdk_pango_context_get();                        //~v92dI~
  	Sppangolanguage=lnx_getpangolang();                            //~v92dI~
  	pango_context_set_language(Sppangocontext,Sppangolanguage);    //~v92dI~
//  Spgfont=lnx_createfont(fontstyle,0.0);    //get font scale     //~v970R~
    Sppangofd=lnx_createfont(fontstyle,0.0);    //get font scale   //~v970I~
    Smonospacefont=lnx_ismonospace(Sppangofd);  //any of size      //~v970I~
	lnx_getfontmetrics(Sppangofd,&ww,&hh);	//set Sffontscale      //~v970I~
    sz=pango_font_description_get_size(Sppangofd);                 //~v970I~
    Sfont_width_by_size=(gdouble)ww/PANGO_PIXELS(sz);              //~v970R~
    Sfont_height_by_size=(gdouble)hh/PANGO_PIXELS(sz);             //~v970I~
    UTRACEP("%s:ww=%d,hh=%d,Sffontscale=%lf,Sfont_width_by_size=%lf,Sfont_height_by_size=%lf\n",UTT,ww,hh,Sffontscale,Sfont_width_by_size,Sfont_height_by_size);//~v970R~//~v9i0R~
}//lnx_setupfont                                                   //~v92dR~
#else  //!GTKPRINT
//=========================================================================
void lnx_setupfont(char *Pfontnm)                                  //~v92dR~
{
//************************                                         //~v92dI~
    if (Pfontnm && *Pfontnm=='?')	//listup fontname              //~v92dR~
    {                                                              //~v92dI~
		lnx_searchfont(Pfontnm+1);                                 //~v92dR~
        exit(4);                                                   //~v92dR~
    }                                                              //~v92dI~
    Sppangocontext=gdk_pango_context_get();                        //~v92dI~
  	Sppangolanguage=lnx_getpangolang();                            //~v92dI~
  	pango_context_set_language(Sppangocontext,Sppangolanguage);    //~v92dI~
	Spgfont=lnx_createfont(fontstyle,0.0);    //get font scale     //~v92dR~
}//lnx_setupfont                                                   //~v92dR~
#endif //!GTKPRINT
//***************************************************************************//~v92dI~
//* get font metrics                                               //~v92dI~
//*   width/height by pixel(Point),set Sffontscale                 //~v970I~
//***************************************************************************//~v970I~
#ifdef GTKPRINT                                                    //~v970I~
//=========================================================================//~v970I~
//=return width by point                                           //~v970I~
//=========================================================================//~v970I~
void lnx_getfontmetrics(PangoFontDescription *Pfontdesc,int *Ppwidth,int *Ppheight)//~v92dI~
{                                                                  //~v92dI~
	PangoFontMetrics *pfm;                                         //~v92dI~
    int asc,des,wch,wdz,fw,fh;                         //~v92dI~//~v975R~//~v970R~
//    gunichar ch;                                                 //~v970R~
//    gint glyph;                                                  //~v970R~
//    gdouble fglyphsz;                                            //~v970R~
//*******************************                                  //~v92dI~
    pfm=pango_context_get_metrics(Sppangocontext,Pfontdesc,Sppangolanguage);//~v92dI~
    asc=pango_font_metrics_get_ascent(pfm);                        //~v92dI~
    des=pango_font_metrics_get_descent(pfm);                       //~v92dI~
    wch=pango_font_metrics_get_approximate_char_width(pfm);        //~v92dI~
    wdz=pango_font_metrics_get_approximate_digit_width(pfm);       //~v92dI~
    fh=asc+des;                                                    //~v92dI~//~v975M~
    fw=max(wdz,wch);            //char_width is affected by dbcs(double width)//~v92dI~//~v975R~
    UTRACEP("%s:asc=%lf,des=%lf,h=%lf,wch=%lf,wdigit=%lf,fw=%lf\n",UTT,//~v975I~//~v9j1R~
    		(double)asc/PANGO_SCALE,(double)des/PANGO_SCALE,(double)fh/PANGO_SCALE,(double)wch/PANGO_SCALE,(double)wdz/PANGO_SCALE,(double)fw/PANGO_SCALE);//~v975R~
#ifdef AAA                                                         //~v975I~
    *Ppwidth=PANGO_PIXELS(fw);                                     //~v92dI~
//  UTRACEP("PANGO_PIXCEL width %d->%d\n",fw,*Ppwidth);            //~v951R~
    *Ppheight=PANGO_PIXELS(fh);                                    //~v92dI~
    UTRACEP("PANGO_PIXCEL height %d->%d\n",fh,*Ppheight);          //~v951R~
    UTRACEP("metrics pango ascent=%d,descent=%d,char-ww=%d,digit-ww=%d,ww=%d,hh=%d\n",asc,des,wch,wdz,*Ppwidth,*Ppheight);//~v970R~
//  Sfontascendant=gnome_font_get_ascender(Spgfont);               //~v970R~
    Sfontascendant=PANGO_PIXELS(asc);	//asc is PANGO_SCALE       //~v970R~
    UTRACEP("font ascendant =%lf\n",Sfontascendant);               //~v951R~
//  Sffontscale=(gdouble)wch/(gdouble)fh;	//width/height         //~v92dR~//~v970R~
    Sffontscale=(gdouble)(max(wch,wdz))/(gdouble)fh;	//width/height//~v970I~
    UTRACEP("fontscale %lf(by avg-char=%lf,by digit=%lf\n",Sffontscale,(gdouble)wch/fh,(gdouble)wdz/fh);//~v951R~//~v955R~//~v970I~
//    ch='A';                                                      //~v970R~
//    glyph=gnome_font_lookup_default(Spgfont,ch);                 //~v970R~
//    fglyphsz=gnome_font_get_glyph_width(Spgfont,glyph);          //~v970R~
//    UTRACEP("glyph %x(%d) size=%lf\n",ch,glyph,fglyphsz);        //~v970R~
//    ch='0';                                                      //~v970R~
//    glyph=gnome_font_lookup_default(Spgfont,ch);                 //~v970R~
//    fglyphsz=gnome_font_get_glyph_width(Spgfont,glyph);          //~v970R~
//    UTRACEP("glyph %x(%d) size=%lf\n",ch,glyph,fglyphsz);        //~v970R~
//    ch=0x3042;       //hiragana "A"                              //~v970R~
//    glyph=gnome_font_lookup_default(Spgfont,ch);                 //~v970R~
//    fglyphsz=gnome_font_get_glyph_width(Spgfont,glyph);          //~v970R~
//    UTRACEP("glyph %x(%d) size=%lf\n",ch,glyph,fglyphsz);        //~v970R~
//    fglyphsz-=fglyphsz; //for compilerwarning:unused-but-set     //~v970R~
	chkglyphextent(Pfontdesc);                                     //~v970I~
#else                                                              //~v975I~
    Sfontascendant=PANGO_PIXELS_FLOOR(asc);	//asc is PANGO_SCALE   //~v975R~
	lnx_chkfontsize(Smonospacefont,Pfontdesc,&fw,&fh);                //~v975I~//~v970R~
    Sffontscale=(double)fw/fh;	//width/height                     //~v975I~
    *Ppwidth=PANGO_PIXELS_FLOOR(fw);                               //~v975R~
    *Ppheight=PANGO_PIXELS_FLOOR(fh);                              //~v975R~
#endif                                                             //~v975I~
    UTRACEP("%s:out monospace=%d,w=%d,h=%d,Sffontscale=%lf=%d/%d\n",UTT,Smonospacefont,*Ppwidth,*Ppheight,Sffontscale,fw,fh);//~v975R~//~v9j1R~
    return;                                                        //~v92dI~
}//lnx_getfontmetrics                                             //~v92dI~//~v970R~
#else  //!GTKPRINT                                                 //~v970I~
//=========================================================================//~v970I~
void lnx_getfontmetrics(PangoFontDescription *Pfontdesc,int *Ppwidth,int *Ppheight)//~v92dI~
{                                                                  //~v92dI~
	PangoFontMetrics *pfm;                                         //~v92dI~
    int asc,des,wch,wdz,fw,fh;                                     //~v92dI~
    gunichar ch;                                                   //~v92dI~
    gint glyph;                                                    //~v92dI~
    gdouble fglyphsz;                                              //~v92dR~
//*******************************                                  //~v92dI~
    pfm=pango_context_get_metrics(Sppangocontext,Pfontdesc,Sppangolanguage);//~v92dI~
    asc=pango_font_metrics_get_ascent(pfm);                        //~v92dI~
    des=pango_font_metrics_get_descent(pfm);                       //~v92dI~
    wch=pango_font_metrics_get_approximate_char_width(pfm);        //~v92dI~
    wch=wch;	//for compilerwarning:unused-but-set               //~v964I~
    wdz=pango_font_metrics_get_approximate_digit_width(pfm);       //~v92dI~
    fw=wdz;            //char_width is affected by dbcs(double width)//~v92dI~
    *Ppwidth=PANGO_PIXELS(fw);                                     //~v92dI~
//  UTRACEP("PANGO_PIXCEL width %d->%d\n",fw,*Ppwidth);            //~v951R~
    fh=asc+des;                                                    //~v92dI~
    *Ppheight=PANGO_PIXELS(fh);                                    //~v92dI~
    UTRACEP("PANGO_PIXCEL height %d->%d\n",fh,*Ppheight);          //~v951R~
    UTRACEP("metrics pango scent=%d,descent=%d,char-ww=%d,digit-ww=%d,ww=%d,hh=%d\n",asc,des,wch,wdz,*Ppwidth,*Ppheight);//~v951R~
    Sfontascendant=gnome_font_get_ascender(Spgfont);               //~v92dR~
    UTRACEP("font ascendant =%lf\n",Sfontascendant);               //~v951R~
    UTRACEP("fontscale by char=%lf,by digit=%lf\n",(gdouble)wch/fh,(gdouble)wdz/fh);//~v951R~//~v955R~
//  Sffontscale=(gdouble)wch/(gdouble)fh;	//width/height         //~v92dR~
    ch='A';                                                        //~v92dI~
    glyph=gnome_font_lookup_default(Spgfont,ch);                   //~v92dR~
    fglyphsz=gnome_font_get_glyph_width(Spgfont,glyph);            //~v92dR~
    UTRACEP("glyph %x(%d) size=%lf\n",ch,glyph,fglyphsz);          //~v951R~
    ch='0';                                                        //~v92dI~
    glyph=gnome_font_lookup_default(Spgfont,ch);                   //~v92dR~
    fglyphsz=gnome_font_get_glyph_width(Spgfont,glyph);            //~v92dR~
    UTRACEP("glyph %x(%d) size=%lf\n",ch,glyph,fglyphsz);          //~v951R~
    ch=0x3042;       //hiragana "A"                                //~v92dI~
    glyph=gnome_font_lookup_default(Spgfont,ch);                   //~v92dR~
    fglyphsz=gnome_font_get_glyph_width(Spgfont,glyph);            //~v92dR~
    UTRACEP("glyph %x(%d) size=%lf\n",ch,glyph,fglyphsz);          //~v951R~
    fglyphsz-=fglyphsz;	//for compilerwarning:unused-but-set       //~v964R~
    UTRACEP("%s:*Ppwidth=%d,*Ppheight=%d\n",*Ppwidth,*Ppheight);   //~v9i0I~
    return;                                                        //~v92dI~
}//lnx_ugetfontmetrics                                             //~v92dI~
#endif //!GTKPRINT                                                 //~v970I~
#ifdef GTKPRINT                                                    //~v970I~
//***************************************************************************//~v970I~
//*set form and orientation for GtkPrintDialog                     //~v970R~
//**************************************************************************//~v970I~
void lnx_printdialoginit(GtkPrintOperation *Pppo,GtkPrintSettings *Ppsettings)//~v970R~
{                                                                  //~v970I~
    GtkPageOrientation ori;                                        //~v970I~
    GtkPageSetup *ppagesetup;                                      //~v970I~
	GtkPaperSize *pps;                                             //~v970I~
//***************************:                                     //~v970I~
    ppagesetup=gtk_page_setup_new();                               //~v970R~
    UTRACEP("lnx_setdefaultpagsetup new pagesetup=%p\n",ppagesetup);//~v970I~
//*ori                                                             //~v970I~
    ori=gtk_print_settings_get_orientation(Ppsettings);            //~v970I~
    UTRACEP("lnx_setdefaultpagsetup orientation=%d\n",ori);        //~v970I~
    gtk_page_setup_set_orientation(ppagesetup,ori);                //~v970I~
//*form                                                            //~v970I~
	pps=gtk_print_settings_get_paper_size(Ppsettings);             //~v970I~
    UTRACEP("lnx_setdefaultpagsetup pps=%p\n",pps);                //~v970I~
    gtk_page_setup_set_paper_size(ppagesetup,pps);                 //~v970I~
//*                                                                //~v970I~
    UTRACEP("lnx_setdefaultpagsetup old pagesetup=%p\n",gtk_print_operation_get_default_page_setup(Pppo));//~v970R~
	gtk_print_operation_set_default_page_setup(Pppo,ppagesetup);   //~v970R~
//*printer                                                         //~v970I~
    gtk_print_settings_set(Ppsettings,"format-for-printer",Sdest); //~v97dR~
}//lnx_printdialoginit                                             //~v970R~
//***************************************************************************//~v916I~
//*set form and orientation                                        //~v970R~
//**************************************************************************//~v916I~
int lnx_initdm(GtkPrintOperation *Pppo,GtkPrintSettings *Ppsettings)                                               //~v92dR~//~v970R~
{                                                                  //~v916I~
//  gchar *pori,*papersz;                                          //~v970R~
//    gchar *papersz;                                              //~v970R~
    GtkPageOrientation ori;                                        //~v970I~
//  int rc=0;                                                      //~v92dR~//~v964R~
//***************************:                                     //~v92dI~
//*printer                                                         //~v970I~
    gtk_print_settings_set_printer(Ppsettings,Sdest);              //~vam0I~//~v970I~
    UTRACEP("lnx_initdm:set printer=%s,settings=%p\n",Sdest,Ppsettings);//~v970I~
  if ((Gxpotheropt & GOO_NOROTATION))                              //~v97aR~
  {                                                                //~v97aI~
#ifdef DDD                                                         //~v97aI~
//*page orientation                                                //~v97aI~
    if (Gformtype & PFT_YOKO)                                      //~v97aI~
//      ori=GTK_PAGE_ORIENTATION_PORTRAIT;                         //~v97aR~
        ori=GTK_PAGE_ORIENTATION_REVERSE_PORTRAIT;                 //~v97aI~
    else                                                           //~v97aI~
        ori=GTK_PAGE_ORIENTATION_REVERSE_LANDSCAPE;                //~v97aR~
    gtk_print_settings_set_orientation(Ppsettings,ori);            //~v97aI~
    UTRACEP("lnx_initdm:set page orientation=%d,settings=%p\n",ori,Ppsettings);//~v97aI~
#endif                                                             //~v97aM~
    ;                                                              //~v97aI~
  }                                                                //~v97aI~
  else                                                             //~v97aI~
  {                                                                //~v97aI~
//*page orientation                                                //~v970I~
    if (Gformtype & PFT_YOKO)                                      //~v92dI~
//      pori="R90";                                                //~v970R~
        ori=Slandscape_orientation;                                //~v970R~
    else                                                           //~v92dI~
//	    pori="R0";                                                 //~v970R~
        ori=GTK_PAGE_ORIENTATION_PORTRAIT;                         //~v970I~
//	gnome_print_config_set(Gpprtconf,GNOME_PRINT_KEY_PAGE_ORIENTATION,pori);//~vXXEI~//~v970I~
    gtk_print_settings_set_orientation(Ppsettings,ori);            //~v970R~
    UTRACEP("lnx_initdm:set page orientation=%d,settings=%p\n",ori,Ppsettings);              //~v667R~//~v970R~
  }                                                                //~v97aI~
////*form                                                          //~v970R~
//    if ((Gformtype & PFT_FORM)==PFT_A4)                            //~v92dI~//~v970R~
//        papersz="A4";                                              //~v92dI~//~v970R~
//    else                                                           //~v92dI~//~v970R~
//    if ((Gformtype & PFT_FORM)==PFT_B4)                            //~v92dI~//~v970R~
//        papersz="B4";                                              //~v92dI~//~v970R~
//    else                                                           //~v92dI~//~v970R~
//    if ((Gformtype & PFT_FORM)==PFT_B5)                            //~v92dI~//~v970R~
//        papersz="B5";                                              //~v92dI~//~v970R~
//    else                                                           //~v92dI~//~v970R~
//        papersz="A4";                                            //~v970R~
//    UTRACEP("lnx_initdm paper size=%s,settings=%p\n",papersz,Ppsettings);//~v970R~
//    if (papersz)                                                   //~v92dR~//~v970R~
//  	/*rc=*/gnome_print_config_set(Spgpconfig,GNOME_PRINT_KEY_PAPER_SIZE,papersz);//~v92dR~//~v970R~
	lnx_setpapersize(Ppsettings);                                  //~v970R~
    UTRACEP("lnx_setdefaultpagsetup olddefault pagesetup=%p\n",gtk_print_operation_get_default_page_setup(Pppo));//~v970R~
    lnx_printdialoginit(Pppo,Ppsettings);  //default printer/paper selection of printdialog//~v970R~
    return 0;                                                      //~v92dI~
}//lnx_initdm                                                      //~v92dR~
#else  //!GTKPRINT                                                 //~v970I~
//***************************************************************************//~v916I~
//*initialze devmode struc                                         //~v916I~
//ret  :1:devmode set required,0:not required                      //~v916R~
//**************************************************************************//~v916I~
int lnx_initdm(void)                                               //~v92dR~
{                                                                  //~v916I~
    gchar *pori,*papersz;                                          //~v92dR~
//  int rc=0;                                                      //~v92dR~//~v964R~
//***************************:                                     //~v92dI~
    if (Gformtype & PFT_YOKO)                                      //~v92dI~
	    pori="R90";                                                //~v92dI~
    else                                                           //~v92dI~
	    pori="R0";                                                 //~v92dI~
	/*rc=*/gnome_print_config_set(Spgpconfig,GNOME_PRINT_KEY_PAGE_ORIENTATION,pori);//~v92dR~//~v964R~
//  printf("paper orientation(%s) set rc=%d,errno=%d\n",pori,rc,errno);//~v92hR~
    if ((Gformtype & PFT_FORM)==PFT_A4)                            //~v92dI~
    	papersz="A4";                                              //~v92dI~
    else                                                           //~v92dI~
    if ((Gformtype & PFT_FORM)==PFT_B4)                            //~v92dI~
    	papersz="B4";                                              //~v92dI~
    else                                                           //~v92dI~
    if ((Gformtype & PFT_FORM)==PFT_B5)                            //~v92dI~
    	papersz="B5";                                              //~v92dI~
    else                                                           //~v92dI~
    	papersz=0;                                                 //~v92dR~
    if (papersz)                                                   //~v92dR~
		/*rc=*/gnome_print_config_set(Spgpconfig,GNOME_PRINT_KEY_PAPER_SIZE,papersz);//~v92dR~//~v964R~
//  printf("paper size(%s) set rc=%d\n",papersz,rc);               //~v92hR~
    return 0;                                                      //~v92dI~
}//lnx_initdm                                                      //~v92dR~
#endif //!GTKPRINT                                                 //~v970I~

#ifdef GTKPRINT                                                    //~v96cI~
#else  //!GTKPRINT                                                 //~v96cI~
//***************************************************************************
//*create printer dc
//parm1:drivername
//parm2:printer type
//parm3:port name
//ret  :HDC
//**************************************************************************
GnomePrintContext *lnx_createdc(void)                              //~v92dI~
{
	GnomePrintContext *ppctxt;                                     //~v92dI~
#ifdef BBB                                                         //~v92dR~
	GnomePrintConfig  *pjobconf;                                   //~v92dI~
#endif                                                             //~v92dI~
//**********************                                           //~v92dI~
    Spgpjob=gnome_print_job_new(Spgpconfig);                       //~v92dR~
    ppctxt=gnome_print_job_get_context(Spgpjob);                   //~v92dR~
//  printf("job=%p,context=%p\n",Spgpjob,ppctxt);                  //~v92hR~
#ifdef BBB                                                         //~v92dR~
    pjobconf=gnome_print_job_get_config(Spgpjob);                  //~v92dR~
    gnome_print_config_set(pjobconf,"Printer",qfile);              //~v92dI~
    printf("jobconf conf=%p,after=%s\n",pjobconf,gnome_print_config_get(pjobconf,"Printer"));//~v92dR~
#endif                                                             //~v92dI~
    lnx_initdm();                                                  //~v92dI~
    return ppctxt;                                                 //~v92dI~
}//lnx_createdc                                                    //~v92dR~
#endif //!GTKPRINT                                                 //~v96cI~
#ifdef GTKPRINT
//****************************************************************************//~v844I~
//create logfont                                                   //~v844I~
//p1rm1:cell width by 1/720 inch(=0.1 point)                                   //~v844R~//~v970R~
//*OR minus (column parm-LINENOSZ-1) from xppf.c when no form and no cpi and with maxcol//~v874I~
//p1rm2:char height by 1/720 inch                                  //~v844R~
//****************************************************************************//~v844I~
#ifdef BBB                                                         //~v970R~
//****************************************************************************//~v970I~
void lnx_createlogfont(int Phmi,int Pvmi)                          //~v92dR~
{                                                                  //~v844I~
//  int parmmaxcol=0;                                              //~v966R~//~v970R~
    int maxlineparm=0;                                             //~v966R~
    int doublesw;                                                  //~v904I~
    int halfwidth;                                                 //~v92hI~
    int linecols;                                                  //~v970R~
//********************************                                 //~v844I~
    UTRACEP("\ncreatelogfont hmi=%d,vmi=%d,maxcol=%d,phase2sw=%d,header1len=%d\n",Phmi,Pvmi,maxcol,phase2sw,header1len);            //~v951R~//~v975R~//~v970R~
    UTRACED("createlogfont header1",header1,header1len);           //~v970R~
	doublesw=(UCBITCHK(swsw3,SW3WIN2P)!=0);                        //~v904I~
	linecols=header1len-1-(LINENOSZ+1)*(lineprefixsw==0);          //~v970R~
//*                                                                //~v970I~
    Slinewidthf=(double)(Spagewidth-(Sleftmargin+Srightmargin));   //~v970R~
    Scharwidthf=Slinewidthf/linecols;	//cell width for monospacing//~v970R~
    UTRACEP("%s:linecols=%d,Scharwidthf=%lf,Spagewidth=%d,Slinwidthf=%lf\n",UTT,//~v970I~//~v9i0R~
                linecols,Scharwidthf,Spagewidth,Slinewidthf);      //~v970R~
	if (Phmi<0)	//maxcol parm only(no form,no cpi)                 //~v92dR~
    {                                                              //~v874I~
      if (doublesw)                                                //~v904I~
      {                                                            //~v904I~
        halfwidth=(Spagewidth-(Sleftmargin+Sleftmargin+Srightmargin))>>1;//~v92hR~
        Srightpageposx=Spagewidth-(halfwidth+Srightmargin);        //~v92hR~
    	Slinewidthf=(double)halfwidth;	                           //~v970R~
	    Scharwidthf=Slinewidthf/linecols;	//cell width for monospace//~v970R~
	    UTRACEP("double linecols=%d,Scharwidthf=%lf,Spagewidth=%d,Slinwidthf=%lf\n",//~v970I~
                linecols,Scharwidthf,Spagewidth,Slinewidthf);      //~v970I~
      }                                                            //~v904I~
      else                                                         //~v904I~
      {                                                            //~v904I~
        Srightpageposx=0;                                          //~v904I~
      }                                                            //~v904I~
    }                                                              //~v874I~
    else                                                           //~v874I~
    {                                                              //~v975I~
        ;                                                          //~v970I~
    }                                                              //~v975I~
	if (Pvmi<0)	//maxline parm only(no form,no lpi)                //~v875I~
    {                                                              //~v875I~
    	maxlineparm=(-Pvmi)*(lineskip+1)+3;	//line in a page last 1 line redundancy//~v92dR~
        Slineheightf=(Spageheight-Stopmargin-Sbottommargin)/(gdouble)maxlineparm;//~v92dR~
    	UTRACEP("page=%d,top=%f,bottom=%f\n",Spageheight,Stopmargin,Sbottommargin);//~v98jR~
    }                                                              //~v875I~
    else                                                           //~v875I~
    	Slineheightf=(gdouble)Pvmi/10;  //by pixel//~v975I~        //~v970M~
    UTRACEP("Pvmi=%d,maxlineparm=%d,Slineheightf=%lf,Spageheight=%d\n",//~v951R~//~v975R~
                Pvmi,maxlineparm,Slineheightf,Spageheight);//~v951R~//~v975R~
    Sposy1st=Stopmargin;                                           //~v904I~
    UTRACEP("Sposy1st=%lf\n",Sposy1st);                            //~v951R~
    UTRACEP("lnx_createlogfont fontscale=%lf\n",Sffontscale);      //~v970I~
//fontsize set                                                     //~v92dI~//~v970M~
	if (!Sflushphase)                                              //~v970I~
	    createfontByWidth(Sppangofd,Scharwidthf,&Sfontw,&Sfonth);  //~v970R~
    Scharwidthf=Sfontw;                                            //~v970I~
    Slinewidthf=Scharwidthf*linecols;                              //~v970I~
    UTRACEP("lnx_createlogfont linecols=%d,Scharwidthf(cellw)=%lf,Slinewidthf=%lf\n",linecols,Scharwidthf,Slinewidthf);//~v975R~
	lnx_setlayoutoption();                                         //~v970I~
	lnx_setscale();                                                //~v92dI~
//after locale adjust                                              //~v92dI~
    if (Gzoomw && Gzoomw!=100)                                     //~v92dM~
	    Scharwidthf=Scharwidthf*Gzoomw/100;                        //~v92dR~
    if (Gzoomh && Gzoomh!=100)                                     //~v92dM~
	    Slineheightf=Slineheightf*Gzoomh/100;                      //~v92dR~
    return;                                                        //~v844I~
}//lnx_createlogfont                                               //~v92dR~
#else	//BBB                                                     //~v970R~//~v976R~
//****************************************************************************//~v970I~
void lnx_createlogfont(int Phmi,int Pvmi)                          //~v970I~
{                                                                  //~v970I~
//  int parmmaxcol=0;                                              //~v970I~
    int maxlineparm=0;                                             //~v970I~
    int doublesw;                                                  //~v970I~
    int halfwidth;                                                 //~v970I~
//  gdouble dpi=1.0;                                               //~v970I~//~v97pR~
    gdouble ffontsize,vv,hh;                                       //~v970I~
    gdouble ffontsizeW,ffontsizeH;                                 //~v970I~
    int ceilfsz;                                                   //~v970I~
    int linecols;                                                  //~v970I~
    int swdetermined=0;                                            //~v987I~
//********************************                                 //~v970I~
    UTRACEP("\n%s:createlogfont hmi=%d,vmi=%d,maxcol=%d,maxline=%d,phase2sw=%d,header1len=%d\n",UTT,Phmi,Pvmi,maxcol,maxline,phase2sw,header1len);//~v970R~//~v9i0R~
    UTRACED("createlogfont header1",header1,header1len);           //~v970I~
	doublesw=(UCBITCHK(swsw3,SW3WIN2P)!=0);                        //~v970I~
	linecols=header1len-1-(LINENOSZ+1)*(lineprefixsw==0);          //~v970I~
#ifdef AAA                                                         //~v970I~
    Slinewidthf=PANGO_SCALE_FLOOR_INT(Spagewidth-(Sleftmargin+Srightmargin));//~v970I~
    UTRACEP("floor Slinewidthf=%lf pagewidth=%f\n",Slinewidthf,Spagewidth-(Sleftmargin+Srightmargin));//~v98jR~
    Scharwidthf=Slinewidthf/linecols;	//cell width for monospacing//~v970I~
    UTRACEP("floor Scharwidthf=%lf=Slinewidthf(%lf)/lincols(%d)\n",Scharwidthf,Slinewidthf,linecols);//~v970I~
    Scharwidthf=PANGO_SCALE_FLOOR_DOUBLE(Scharwidthf);             //~v970I~
    Slinewidthf=Scharwidthf*linecols;                              //~v970I~
    UTRACEP("floor Slinewidthf=%lf,Scharwidthf=%lf\n",Slinewidthf,Scharwidthf);//~v970I~
    UTRACEP("linecols=%d,Scharwidthf=%lf,Spagewidth=%d,Slinwidthf=%lf\n",//~v970I~
                linecols,Scharwidthf,Spagewidth,Slinewidthf);      //~v970I~
	if (Phmi<0)	//maxcol parm only(no form,no cpi)                 //~v970I~
    {                                                              //~v970I~
//  	parmmaxcol=-Phmi+(LINENOSZ+1)*lineprefixsw;	//char in a line//~v970I~
      if (doublesw)                                                //~v970I~
      {                                                            //~v970I~
        halfwidth=(Spagewidth-(Sleftmargin+Sleftmargin+Srightmargin))>>1;//~v970I~
//      Scharwidth=(int)(Scharwidthf=halfwidth/(gdouble)parmmaxcol);//~v970I~
        Srightpageposx=Spagewidth-(halfwidth+Srightmargin);        //~v970I~
    	Slinewidthf=PANGO_SCALE_FLOOR_INT(halfwidth);              //~v970I~
        UTRACEP("floor Slinewidthf=%lf halfwidth=%d\n",Slinewidthf,halfwidth);//~v970I~
	    Scharwidthf=Slinewidthf/linecols;	//cell width for monospace//~v970I~
      }                                                            //~v970I~
      else                                                         //~v970I~
      {                                                            //~v970I~
//      Scharwidth=(Spagewidth-(Sleftmargin+Srightmargin))/parmmaxcol;//~v970I~
        Srightpageposx=0;                                          //~v970I~
      }                                                            //~v970I~
    }                                                              //~v970I~
    else                                                           //~v970I~
    {                                                              //~v970I~
//  	Scharwidth=Scharwidthf=(gdouble)(Phmi*Sinchwidthpixel)/720; //by pixel//~v970I~
        ;                                                          //~v970I~
    }                                                              //~v970I~
	if (Pvmi<0)	//maxline parm only(no form,no lpi)                //~v970I~
    {                                                              //~v970I~
    	maxlineparm=(-Pvmi)*(lineskip+1)+3;	//line in a page last 1 line redundancy//~v970I~
//      Slineheight=(Spageheight-Stopmargin-Sbottommargin)/maxlineparm;//~v970I~
        Slineheightf=(Spageheight-Stopmargin-Sbottommargin)/(gdouble)maxlineparm;//~v970I~
    	UTRACEP("page=%d,top=%f,bottom=%f\n",Spageheight,Stopmargin,Sbottommargin);//~v98jR~
    }                                                              //~v970I~
    else                                                           //~v970I~
//  	Slineheight=Slineheightf=(gdouble)(Pvmi*Sinchheightpixel)/720;   //by pixel//~v970I~
    	Slineheightf=(gdouble)Pvmi/10;  //by pixel                 //~v970I~
    UTRACEP("Pvmi=%d,maxlineparm=%d,Slineheightf=%lf,Spageheight=%d\n",//~v970I~
                Pvmi,maxlineparm,Slineheightf,Spageheight);        //~v970I~
    UTRACEP("Scharwidthf=%lf,Slineheightf=%lf,scale=%lf\n",Scharwidthf,Slineheightf,Scharwidthf/Slineheightf);//~v970I~
    Sposy1st=Stopmargin;                                           //~v970I~
    UTRACEP("Sposy1st=%lf\n",Sposy1st);                            //~v970I~
    UTRACEP("lnx_createlogfont fontscale=%lf\n",Sffontscale);      //~v970I~
#endif                                                             //~v970I~
//fontsize set                                                     //~v970I~
  if (doublesw)                                                    //~v97cI~
//  Slinewidthf=(Spagewidth-(Sleftmargin+Sleftmargin+Srightmargin))>>1;//~v98jR~
    Slinewidthf=(Spagewidth-(Sleftmargin+Sleftmargin+Srightmargin))/2.0;//~v98jI~
  else                                                             //~v97cI~
    Slinewidthf=(double)(Spagewidth-(Sleftmargin+Srightmargin));   //~v970I~
    Scharwidthf=Slinewidthf/linecols;	//cell width for monospacing//~v970I~
    UTRACEP("%s:double=%d,linecols=%d,Scharwidthf=%lf,Spagewidth=%d,Slinwidthf=%lf\n",UTT,//~v970I~//~v97cR~//~v9i0R~
                doublesw,linecols,Scharwidthf,Spagewidth,Slinewidthf);      //~v970I~//~v97cR~
    maxlineparm=(maxline+1)+3;	//@@@@test?                        //~v970I~//~v97pR~
    Slineheightf=(Spageheight-Stopmargin-Sbottommargin)/(gdouble)maxlineparm;//~v970I~
    ffontsizeH=Slineheightf/Sfont_height_by_size; //size by line maxline//~v970I~
    ffontsizeW=Scharwidthf/Sfont_width_by_size;   //size by line colwidh//~v970R~
    UTRACEP("%s:lnx_createlogfont ffontsizeH=%lf,ffontsizeW=%lf,Scharwidthf=%lf,Sfont_width_by_size=%lf\n",UTT,ffontsizeH,ffontsizeW,Scharwidthf,Sfont_width_by_size);//~v9i0R~
	if (!Sfontsizespecifiedsw && Sffontscale>0)	//size in font cmd line parameter//~v970I~
    {                                                              //~v970I~
    	if (Pvmi>0)		//line pich specified                      //~v970I~
    		if (Phmi>0)	//char pich specified                      //~v970I~
            {                                                      //~v970I~
            	vv=(gdouble)Pvmi/10;                               //~v970I~
//          	hh=(gdouble)Pvmi/10;                               //~v970I~
            	hh=(gdouble)Phmi/10; //height by point             //~v970I~
//                vh=vv/hh;                                        //~v970I~
//                if (vh>Sffontscale)  //space on right            //~v970I~
//                    ffontsize=hh;                                //~v970I~
//                else                 //space on bottom           //~v970I~
////                  ffontsize=vv;                                //~v970I~
				vv/=Sfont_height_by_size;  //font size of the cell height//~v970I~
				hh/=Sfont_width_by_size;   //font size of the cell width//~v970I~
                if (vv<hh)                                         //~v970I~
                    ffontsize=vv;                                  //~v970I~
                else                                               //~v970I~
                    ffontsize=hh;                                  //~v970I~
        		UTRACEP("both pich vv=%lf,hh=%lf,ffontsz=%lf(Phmi=%d,Pvmi=%d)\n",vv,hh,ffontsize,Phmi,Pvmi);//~v976I~
                Sfontsizespecifiedsw=1;	//fix both direction       //~v970I~
            }                                                      //~v970I~
            else		//linepich only                            //~v970I~
            {                                                      //~v970I~
//          	ffontsize=(gdouble)Pvmi/10;                        //~v970I~
            	ffontsize=(gdouble)Pvmi/10/Sfont_height_by_size;;  //~v970I~
                Sfontsizespecifiedsw='v';	//fix virtical         //~v970I~
        		UTRACEP("lpitch only ffontsz=%lf(Pvmi=%d)\n",ffontsize,Pvmi);//~v976R~
            }                                                      //~v970I~
        else             //no line pichi                           //~v970I~
    		if (Phmi>0)	//char pich specified                      //~v970I~
            {                                                      //~v970I~
//            	ffontsize=(gdouble)Phmi/10/Sffontscale;            //~v970I~
            	ffontsize=(gdouble)Phmi/10/Sfont_width_by_size;    //~v970I~
                Sfontsizespecifiedsw='h';	//fix horizontal       //~v970I~
        		UTRACEP("cpitch only ffontsz=%lf(Phmi=%d)\n",ffontsize,Phmi);//~v976I~
            }                                                      //~v970I~
            else                                                   //~v970I~
            {                                                      //~v970I~
//          	ffontsize=Slineheightf;                            //~v970R~
//  			ffontsize/=Sfont_height_by_size;                   //~v970R~
      		  if (Sotherform && !linespec) //no linepich and no line count is specified//~v987I~//~v988R~
              {                                                    //~v987I~
                ffontsize=ffontsizeW;	//by char width            //~v987I~
                swdetermined=1;                                    //~v987I~
        		UTRACEP("colparm and no lineparm fontsz=%lf\n",ffontsize);//~v987I~
              }                                                    //~v987I~
              else                                                 //~v987I~
              {                                                    //~v987I~
    			ffontsize=ffontsizeH;    //by line height          //~v970R~
        		UTRACEP("no pich ffontsz=%lf(Phmi=%d)\n",ffontsize,Phmi);//~v976I~
              }                                                    //~v987I~
            }                                                      //~v970I~
        UTRACEP("%s:swdetermined=%d,ffontsize=%lf,ffontsizeH=%lf,ffontsizeW=%lf\n",UTT,swdetermined,ffontsize,ffontsizeH,ffontsizeW);//~v9i0R~
      if (!swdetermined)                                           //~v987I~
      {                                                            //~v987I~
        if (ffontsize>ffontsizeH)                                  //~v976I~
            ffontsize=ffontsizeH;                                  //~v976I~
        if (ffontsize>ffontsizeW)                                  //~v976I~
            ffontsize=ffontsizeW;                                  //~v976I~
      }                                                            //~v987I~
        UTRACEP("%s:sw=%x,Sfont_width_by_size=%lf,Sfont_height_by_size=%lf,Slineheightf=%lf,fontsize=%lf\n",UTT,Sfontsizespecifiedsw,Sfont_width_by_size,Sfont_height_by_size,Slineheightf,ffontsize);//~v970I~//~v986R~//~v9i0R~
        ffontsize=PANGO_SCALE_FLOOR_DOUBLE(ffontsize);	//round down by PANGO_SCALE//~v970I~
//      ffontsize=(double)(int)ffontsize;//@@@@TEST                //~v970I~
        UTRACEP("%s:fontsize=%lf\n",UTT,ffontsize);                       //~v970I~//~v9i0R~
#ifdef SSS //@@@@TEST                                              //~v9j3R~
		if (Smonospacefont)                                        //~v970I~
        {                                                          //~v970I~
        	ceilfsz=(int)ffontsize;                                //~v970I~
        	ffontsize=(double)ceilfsz;                             //~v970I~
        }                                                          //~v970I~
#else                                                              //~v9j3R~
        ceilfsz=(int)ffontsize;                                    //~v9j3R~
        if ((double)ceilfsz!=ffontsize)                            //~v9j3R~
        	ceilfsz++;                                             //~v9j3R~
        ffontsize=(double)ceilfsz;                                 //~v9j3R~
#endif                                                             //~v9j3R~
        UTRACEP("%s:Smonospacefont=%d,ffontsize=%lf\n",UTT,Smonospacefont,ffontsize);                   //~v970I~//~v976R~//~v9j1R~
//*createFont                                                      //~v970I~
	  if (!Sflushphase)                                            //~v970I~
//		Spgfont=lnx_createfont(fontstyle,ffontsize);               //~v970I~
		Sppangofd=lnx_createfont(fontstyle,ffontsize);             //~v970I~
    }                                                              //~v970I~
                                                                   //~v970I~
//    UTRACEP("gnome font=%p(%s)\n",Spgfont,fontstyle);            //~v970I~
//	Sppangofd=gnome_font_get_pango_description(Spgfont,dpi); //dpi not used(source chked libgnomeprint 2.18.2)//~v970I~
//  UTRACEP("pangofont desc=%p dpi==%lf PANGO_SCALE=%d\n",Sppangofd,dpi,PANGO_SCALE);//~v970I~//~v97pR~
	lnx_getfontmetrics(Sppangofd,&Sfontw,&Sfonth);                 //~v970I~
    lnx_setscale(Sfontw,linecols);                                 //~v970R~
//    if (Smonospacefont)                                          //~v970I~
//    {                                                            //~v970I~
//        Scharwidthf=Sfontw; //if enlarged,sadjust by xscale      //~v970I~
//        Slinewidthf=Scharwidthf*linecols;                        //~v970I~
//    }                                                            //~v970I~
#ifndef AAA                                                        //~v970I~
//  Slinewidthf=PANGO_SCALE_FLOOR_INT(Spagewidth-(Sleftmargin+Srightmargin));//~v970I~
//  Scharwidthf=Slinewidthf/linecols;	//cell width for monospacing//~v970I~
//	Slinewidthf=Scharwidthf*linecols;                              //~v970I~
//  Scharwidthf=PANGO_SCALE_FLOOR_DOUBLE(Scharwidthf);             //~v970I~
    UTRACEP("doublesw=%d,Scharwidthf=%lf,Slinewidthf(%lf),lincols(%d)\n",doublesw,Scharwidthf,Slinewidthf,linecols);//~v970I~//~v976R~
	if (Phmi<0)	//maxcol parm only(no form,no cpi)                 //~v970I~
    {                                                              //~v970I~
      if (doublesw)                                                //~v970I~
      {                                                            //~v970I~
//      halfwidth=(Spagewidth-(Sleftmargin+Sleftmargin+Srightmargin))>>1;//~v98jR~
//      halfwidth=(Spagewidth-(Sleftmargin+Sleftmargin+Srightmargin))/2.0;//~v98jI~//~v9a0R~
        halfwidth=(int)((Spagewidth-(Sleftmargin+Sleftmargin+Srightmargin))/2.0);//~v9a0I~
//      Srightpageposx=Spagewidth-(halfwidth+Srightmargin);        //~v970I~//~v9a0R~
        Srightpageposx=(int)(Spagewidth-(halfwidth+Srightmargin)); //~v9a0I~
//  	Slinewidthf=PANGO_SCALE_FLOOR_INT(halfwidth);              //~v970I~
//      UTRACEP("floor Slinewidthf=%lf halfwidth=%d\n",Slinewidthf,halfwidth);//~v970I~
//      Scharwidthf=Slinewidthf/linecols;	//cell width for monospace//~v970I~
      }                                                            //~v970I~
      else                                                         //~v970I~
      {                                                            //~v970I~
//      Scharwidth=(Spagewidth-(Sleftmargin+Srightmargin))/parmmaxcol;//~v970I~
        Srightpageposx=0;                                          //~v970I~
      }                                                            //~v970I~
    }                                                              //~v970I~
    else                                                           //~v970I~
    {                                                              //~v970I~
//  	Scharwidth=Scharwidthf=(gdouble)(Phmi*Sinchwidthpixel)/720; //by pixel//~v970I~
        ;                                                          //~v970I~
    }                                                              //~v970I~
	if (Pvmi<0)	//maxline parm only(no form,no lpi)                //~v970I~
    {                                                              //~v970I~
    	maxlineparm=(-Pvmi)*(lineskip+1)+3;	//line in a page last 1 line redundancy//~v970I~
        UTRACEP("Pvmi=%d,Sotherform=%d,linespec=%d,maxline=%d\n",Pvmi,Sotherform,linespec,maxline);//~v987I~
      if (Sotherform && Phmi<0 && !linespec) //no linepich and no line count is specified//~v987R~
      {                                                            //~v987I~
        Slineheightf=Sfonth+1;                                     //~v987I~
//      maxline=(Spageheight-Stopmargin-Sbottommargin)/Slineheightf;//~v987R~//~v9a0R~
        maxline=(int)((Spageheight-Stopmargin-Sbottommargin)/Slineheightf);//~v9a0I~
        maxline=(maxline-3)/(lineskip+1);                          //~v987I~
        UTRACEP("lineheight by font height:%f,new maxline=%d\n",Slineheightf,maxline);//~v987R~
      }                                                            //~v987I~
      else                                                         //~v987I~
      {                                                            //~v987I~
//      Slineheight=(Spageheight-Stopmargin-Sbottommargin)/maxlineparm;//~v970I~
        Slineheightf=(Spageheight-Stopmargin-Sbottommargin)/(gdouble)maxlineparm;//~v970I~
      }                                                            //~v987I~
    	UTRACEP("page=%d,top=%f,bottom=%f\n",Spageheight,Stopmargin,Sbottommargin);//~v98jR~
    }                                                              //~v970I~
    else                                                           //~v970I~
//  	Slineheight=Slineheightf=(gdouble)(Pvmi*Sinchheightpixel)/720;   //by pixel//~v970I~
    	Slineheightf=(gdouble)Pvmi/10;  //by pixel                 //~v970I~
    UTRACEP("Pvmi=%d,maxlineparm=%d,Slineheightf=%lf,Spageheight=%d\n",//~v970I~
                Pvmi,maxlineparm,Slineheightf,Spageheight);        //~v970I~
    UTRACEP("Scharwidthf=%lf,Slineheightf=%lf,scale=%lf\n",Scharwidthf,Slineheightf,Scharwidthf/Slineheightf);//~v970I~
    Sposy1st=Stopmargin;                                           //~v970I~
    UTRACEP("Sposy1st=%lf\n",Sposy1st);                            //~v970I~
    UTRACEP("lnx_createlogfont fontscale=%lf\n",Sffontscale);      //~v970I~
#endif                                                             //~v970I~
    UTRACEP("lnx_createlogfont linecols=%d,Scharwidthf(cellw)=%lf,Slinewidthf=%lf\n",linecols,Scharwidthf,Slinewidthf);//~v970I~
	lnx_setlayoutoption();                                         //~v970I~
//after locale adjust                                              //~v970I~
    if (Gzoomw && Gzoomw!=100)                                     //~v970I~
//	    Scharwidthf=Scharwidthf*Gzoomw/100;                        //~v970I~//~v976R~
  	    Sfscalex=Sfscalex*Gzoomw/100;                              //~v976I~
    if (Gzoomh && Gzoomh!=100)                                     //~v970I~
//	    Slineheightf=Slineheightf*Gzoomh/100;                      //~v970I~//~v976R~
  	    Sfscaley=Sfscaley*Gzoomh/100;                              //~v976I~
    UTRACEP("lnx_createlogfont zoom w=%d,h=%d,scalex=%lf,y=%lf\n",Gzoomw,Gzoomh,Sfscalex,Sfscaley);//~v976I~
    return;                                                        //~v970I~
}//lnx_createlogfont                                               //~v970I~
#endif        //BBB                                                //~v970M~
#else   //!GTKPRINT                                                //~v970R~
//****************************************************************************//~v844I~
//create logfont                                                   //~v844I~
//p1rm1:cell width by 1/720 inch(=0.1 point)                                   //~v844R~//~v970R~
//*OR minus (column parm-LINENOSZ-1) from xppf.c when no form and no cpi and with maxcol//~v874I~
//p1rm2:char height by 1/720 inch                                  //~v844R~
//****************************************************************************//~v844I~
void lnx_createlogfont(int Phmi,int Pvmi)                          //~v92dR~
{                                                                  //~v844I~
    int parmmaxcol=0;                                              //~v966R~
    int maxlineparm=0;                                             //~v966R~
    int doublesw;                                                  //~v904I~
    int halfwidth;                                                 //~v92hI~
    gdouble dpi=1.0;                                               //~v92dR~
    gdouble ffontsize,vv,hh,vh;                                    //~v92dR~
    int linecols;                                                  //~v975I~
//********************************                                 //~v844I~
    UTRACEP("%s:createlogfont hmi=%d,vmi=%d,maxcol=%d,phase2sw=%d\n",UTT,Phmi,Pvmi,maxcol,phase2sw);            //~v951R~//~v975R~//~v970R~//~v9i0R~
    UTRACED("createlogfont header1",header1,header1len);           //~v970R~
	doublesw=(UCBITCHK(swsw3,SW3WIN2P)!=0);                        //~v904I~
	if (Phmi<0)	//maxcol parm only(no form,no cpi)                 //~v92dR~
    {                                                              //~v874I~
    	parmmaxcol=-Phmi+(LINENOSZ+1)*lineprefixsw;	//char in a line//~v92dR~
      if (doublesw)                                                //~v904I~
      {                                                            //~v904I~
        halfwidth=(Spagewidth-(Sleftmargin+Sleftmargin+Srightmargin))>>1;//~v92hR~
        Scharwidth=(int)(Scharwidthf=halfwidth/(gdouble)parmmaxcol);//~v92hR~
        Srightpageposx=Spagewidth-(halfwidth+Srightmargin);        //~v92hR~
	    linecols=parmmaxcol*2;                                     //~v975I~
      }                                                            //~v904I~
      else                                                         //~v904I~
      {                                                            //~v904I~
        Scharwidth=(Spagewidth-(Sleftmargin+Srightmargin))/parmmaxcol;//~v92dR~
        Scharwidthf=(Spagewidth-(Sleftmargin+Srightmargin))/(gdouble)parmmaxcol;//~v92dR~
        Srightpageposx=0;                                          //~v904I~
        UTRACEP("lnx_createlogfont Scharwidthf=%lf=Spagewidth-net(%f)/parmmaxcol(%d)\n",Scharwidthf,(Spagewidth-(Sleftmargin+Srightmargin)),parmmaxcol);//~v970I~//~v98jR~
	    linecols=parmmaxcol;                                       //~v975R~
      }                                                            //~v904I~
    }                                                              //~v874I~
    else                                                           //~v874I~
    {                                                              //~v975I~
    	Scharwidth=Scharwidthf=(gdouble)(Phmi*Sinchwidthpixel)/720; //by pixel//~v92dR~
	    linecols=maxcol;                                           //~v975R~
    }                                                              //~v975I~
    UTRACEP("\n%s:Phmi=%d,linecols=%d,Scharwidthf=%lf,Spagewidth=%d\n",UTT,//~v951R~//~v975R~//~v970R~//~v9i0R~
                Phmi,linecols,Scharwidthf,Spagewidth);            //~v951R~//~v975R~//~v970R~
	if (Pvmi<0)	//maxline parm only(no form,no lpi)                //~v875I~
    {                                                              //~v875I~
    	maxlineparm=(-Pvmi)*(lineskip+1)+3;	//line in a page last 1 line redundancy//~v92dR~
        Slineheight=(Spageheight-Stopmargin-Sbottommargin)/maxlineparm;//~v92dR~
        Slineheightf=(Spageheight-Stopmargin-Sbottommargin)/(gdouble)maxlineparm;//~v92dR~
    	UTRACEP("page=%d,top=%f,bottom=%f\n",Spageheight,Stopmargin,Sbottommargin);//~v98jR~
    }                                                              //~v875I~
    else                                                           //~v875I~
    	Slineheight=Slineheightf=(gdouble)(Pvmi*Sinchheightpixel)/720;   //by pixel//~v92dR~
    UTRACEP("%s:Pvmi=%d,maxlineparm=%d,Slineheightf=%lf,Spageheight=%d\n",UTT,//~v951R~//~v975R~//~v9i0R~
                Pvmi,maxlineparm,Slineheightf,Spageheight);//~v951R~//~v975R~
    UTRACEP("%s:Scharwidthf=%lf,Slineheightf=%lf,scale=%lf\n",UTT,Scharwidthf,Slineheightf,Scharwidthf/Slineheightf);//~v951R~//~v9i0R~
    Sposy1st=Stopmargin;                                           //~v904I~
    UTRACEP("Sposy1st=%lf\n",Sposy1st);                            //~v951R~
    UTRACEP("%s:lnx_createlogfont fontscale=%lf\n",UTT,Sffontscale);      //~v970I~//~v9i0R~
//fontsize set                                                     //~v92dI~
	if (!Sfontsizespecifiedsw && Sffontscale>0)	//size in font cmd line parameter//~v92dI~
    {                                                              //~v92dI~
    	if (Pvmi>0)		//line pich specified                      //~v92dI~
    		if (Phmi>0)	//char pich specified                      //~v92dI~
            {                                                      //~v92dI~
            	vv=(gdouble)Pvmi/10;                               //~v92dI~
//          	hh=(gdouble)Pvmi/10;                               //~v92dI~//~v970R~
            	hh=(gdouble)Phmi/10;                               //~v970I~
                vh=vv/hh;                                          //~v92dR~
                if (vh>Sffontscale)  //space on right              //~v92dI~
                    ffontsize=hh;                                  //~v92dI~
                else                 //space on bottom             //~v92dI~
//                  ffontsize=vv;                                  //~v92dI~//~v970R~
                    ffontsize=vv/Sffontscale;                      //~v970I~
                Sfontsizespecifiedsw=1;	//fix both direction       //~v92dI~
            }                                                      //~v92dI~
            else		//linepich only                            //~v92dI~
            {                                                      //~v92dI~
            	ffontsize=(gdouble)Pvmi/10;                        //~v92dI~//~v970R~
                Sfontsizespecifiedsw='v';	//fix virtical         //~v92dI~
            }                                                      //~v92dI~
        else             //no line pichi                           //~v92dI~
    		if (Phmi>0)	//char pich specified                      //~v92dI~
            {                                                      //~v92dI~
//            	ffontsize=(gdouble)Phmi/10/Sffontscale;            //~v92dR~//~v970R~
            	ffontsize=(gdouble)Phmi/10/Sfont_width_by_size;    //~v970R~
                Sfontsizespecifiedsw='h';	//fix horizontal       //~v92dI~
            }                                                      //~v92dI~
            else	                                               //~v92dI~
            {                                                      //~v970I~
            	ffontsize=Slineheightf;                            //~v92dI~
            }                                                      //~v970I~
        UTRACEP("%s:sw=%c,Sfont_width_by_size=%lf,Sfont_height_by_size=%lf,Slineheightf=%lf,fontsize=%lf\n",UTT,Sfontsizespecifiedsw,Sfont_width_by_size,Sfont_height_by_size,Slineheightf,ffontsize);//~v951R~//~v970R~//~v9i0R~
		Spgfont=lnx_createfont(fontstyle,ffontsize);               //~v92dR~
    }                                                              //~v92dI~
                                                                   //~v92dI~
    UTRACEP("gnome font=%p(%s)\n",Spgfont,fontstyle);              //~v951R~
	Sppangofd=gnome_font_get_pango_description(Spgfont,dpi); //dpi not used(source chked libgnomeprint 2.18.2)//~v92dR~
    UTRACEP("%s:pangofont desc=%p dpi==%lf PANGO_SCALE=%d\n",UTT,Sppangofd,dpi,PANGO_SCALE);//~v951R~//~v9i0R~
	lnx_getfontmetrics(Sppangofd,&Sfontw,&Sfonth);                 //~v92dM~
	lnx_setscale();                                                //~v92dI~
//after locale adjust                                              //~v92dI~
    if (Gzoomw && Gzoomw!=100)                                     //~v92dM~
  	    Scharwidthf=Scharwidthf*Gzoomw/100;                        //~v92dR~//~v976R~
    if (Gzoomh && Gzoomh!=100)                                     //~v92dM~
  	    Slineheightf=Slineheightf*Gzoomh/100;                      //~v92dR~//~v976R~
    return;                                                        //~v844I~
}//lnx_createlogfont                                               //~v92dR~
#endif //!GTKPRINT                                                 //~v970R~
#ifdef GTKPRINT
//===============================================================================//~v92dI~
//adjust scaling                                                   //~v92dI~
//===============================================================================//~v92dI~
void lnx_setscale(int Pfontw,int Plinecols)                                    //~v92dR~//~v970R~
{                                                                  //~v92dI~
    double linewidthfo,linewidthfn,fscalex;                        //~v970R~
    int linecols;                                                  //~v970R~
//************************************                             //~v92dI~
    Sfscaley=1.0;                                              //~v92dR~//~v970M~
    linecols=Plinecols;                                            //~v970R~
    linewidthfo=Slinewidthf;                                       //~v970I~
	Scharwidthf=(double)Pfontw;   //for gauge span                 //~v970R~
    linewidthfn=(double)(Pfontw*linecols);                         //~v970R~
    fscalex=linewidthfo/linewidthfn;                               //~v970R~
    UTRACEP("%s:fscalex=%lf,maxcol=%d,maxline=%d,linecols=%d,widtho(%lf)/widthn(%lf)\n",UTT,maxcol,maxline,linecols,linewidthfo,linewidthfn);//~v970R~//~v9i0R~
    if (fscalex<1.0)      //old<new                                //~v970I~
		Sfscalex=fscalex;                                          //~v970R~
    else                                                           //~v970I~
    	Sfscalex=1.0;                                              //~v970I~
    Scharwidthf_scaled=Scharwidthf;      //after cairo_scale       //~v970I~
    if (Sfscalex<1.0)	//shrink                                   //~v970R~
    	Scharwidthf_scaled=Scharwidthf/Sfscalex;      //after cairo_scale//~v970I~
    UTRACEP("%s:Sfscalex=%lf,y=%lf,Scharwidthf_scaled=%lf,Scharwidthf=%lf\n",UTT,Sfscalex,Sfscaley,Scharwidthf_scaled,Scharwidthf);//~v970R~//~v9i0R~//~v9j4R~
	return;                                                        //~v92dI~
}//lnx_setscale                                                    //~v970R~
#else
//===============================================================================//~v92dI~
//adjust scaling   Not GTKPRINT                                                //~v92dI~//~v9i0R~
//===============================================================================//~v92dI~
void lnx_setscale(void)                                            //~v92dR~
{                                                                  //~v92dI~
	gdouble fcellscale;                                            //~v92dI~
//    gdouble fwfontcell;                                          //~v970R~
//************************************                             //~v92dI~
    UTRACEP("lnx_setscale Sfontsizespecifiedsw=%d,maxcol=%d,maxline=%d,pagewidth=%d,pageheight=%d\n",Sfontsizespecifiedsw,maxcol,maxline,Spagewidth,Spageheight);//~v951R~//~v970R~
    fcellscale=(gdouble)Scharwidthf/(gdouble)Slineheightf; //width/height//~v92dR~
    UTRACEP("lnx_setscale Scharwidthf=%f,Slineheight=%lf\n",Scharwidthf,Slineheightf);//~v970R~
    UTRACEP("lnx_setscale fonth=%d,fontw=%d\n",Sfonth,Sfontw);     //~v970I~
    UTRACEP("cellscale=%lf,fontscale=%lf\n",fcellscale,Sffontscale);//~v970I~
    switch (Sfontsizespecifiedsw)	//fix horizontal               //~v92dR~
    {                                                              //~v92dI~
    case 1:                                                        //~v92dI~
    	Sfscalex=Sfscaley=1.0;                                     //~v92dI~
        break;                                                     //~v92dI~
    case 'v':	//fix line pitch                                   //~v92dI~
    	Sfscaley=1.0;                                              //~v92dI~
    	Sfscalex=fcellscale/Sffontscale;                           //~v92dI~
        break;                                                     //~v92dI~
    case 'h':	//fix char pitch                                   //~v92dI~
    	Sfscalex=1.0;                                              //~v92dI~
//    	Sfscaley=Sffontscale/fcellscale;                           //~v92dR~//~v970R~
	    Sfscaley=1.0;                                              //~v970I~
        break;                                                     //~v92dI~
    default:                                                       //~v92dI~
    	Sfscaley=1.0;                                              //~v92dR~
//    	Sfscalex=fcellscale/Sffontscale;                           //~v92dI~//~v970R~
//        UTRACEP("sw=0 cellscale=%lf,fontscale=%lf\n",fcellscale,Sffontscale);//~v970R~
//        if (fcellscale>Sffontscale && Scharwidth>(double)Sfontw) //~v970R~
//            Sfscalex=1.0;  //keep original shape if not width overflow//~v970R~
//        else                                                     //~v970R~
//        {                                                        //~v970R~
//            Sfscalex=fcellscale/Sffontscale;                     //~v970R~
//            fwfontcell=Scharwidthf/(double)Sfontw; //shlink to cellwidth(fontwidt/cellwidth)//~v970R~
//            UTRACEP("sw=0 Sfscalex=%lf=fcellscale(%lf)/Sffontscale(%lf):fwfntcell(%lf)=Scharwidthf(%lf)/Sfontw(%d)\n",Sfscalex,fcellscale,Sffontscale,fwfontcell,Scharwidthf,Sfontw);//~v970R~
//            if (fwfontcell<Sfscalex)                             //~v970R~
//                Sfscalex=fwfontcell;                             //~v970R~
//        }                                                        //~v970R~
		Sfscalex=getstringxscale();	//chk header1 width            //~v970R~
        if (Sfscalex>1)	//cell is large                             //~v970I~//~v975R~
			Sfscalex=1.0;  //keep original shape if not width overflow//~v970I~
    }                                                              //~v92dI~
    Scharwidthf_scaled=Scharwidthf;      //after cairo_scale       //~v970I~
    if (Sfscalex<1.0)                                              //~v970I~
    	Scharwidthf_scaled=Scharwidthf/Sfscalex;      //after cairo_scale//~v970I~
    UTRACEP("%s:Sfscalex=%lf,y=%lf pageheight=%d,Scharwidthf=%lf,Slinewidthf=%lf,Scharwidthf_scaled=%lf,\n",UTT,Sfscalex,Sfscaley,Spageheight,Scharwidthf,Slinewidthf,Scharwidthf_scaled);//~v970R~//~v9i0R~//+v9j4R~
	return;                                                        //~v92dI~
}//lnx_setscale                                                    //~v970R~
#endif
//****************************************************************************//~v844I~
//get dc inf                                                       //~v844R~
//****************************************************************************//~v844I~
#ifdef GTKPRINT
//=========================================================================
void lnx_getdcinf(void)                                            //~v92dR~
{                                                                  //~v844I~
//  const GnomePrintUnit *pgpupt,*pretunit,*pgpumm,*pgpuin;        //~v970R~
    gdouble ll,ll2,ww,hh;                                          //~v92hR~//~v977R~
//    int rc;                                                      //~v970R~
    int unit=GTK_UNIT_POINTS;                                      //~v970I~//~v977R~
//  ppd_size_t *ppdsz;                                             //~v970R~
    GtkPaperSize *pps;                                             //~v970R~
//  int mt,mb,ml,mr;                                               //~v98jR~
    double mt,mb,ml,mr;                                            //~v98jI~
//********************************                                 //~v92dI~
//	ppdsz=Sppdsz;                                                  //~v970R~
    pps=Sppapersz;                                                 //~v970I~
	hh=gtk_paper_size_get_height(pps,unit);                        //~v977I~
	ww=gtk_paper_size_get_width(pps,unit);                         //~v977I~
  	UTRACEP("%s:name=%s,displayname=%s,gtk_paper_size_get_width=%lf,hh=%lf\n",UTT,gtk_paper_size_get_name(pps),gtk_paper_size_get_display_name(pps),ww);//~v970R~//~v9i0R~
                                                                   //~v977I~
	ll=gtk_paper_size_get_default_left_margin(pps,unit);           //~v970I~
    ll=Sfmargins.left;                                             //~v977I~
  	UTRACEP("lnx_getmargin left margin by point=%lf\n",ll);        //~v970I~
//  ll+=0.9999; //roundup                                          //~v98jR~
	Sleftmargin=ll;                                                //~v970I~
  	UTRACEP("lnx_getmargin left Sleftmargin=%f\n",Sleftmargin);    //~v98jR~
//right                                                            //~v92dI~
//  ll=gtk_paper_size_get_default_right_margin(pps,unit);          //~v970R~//~v977R~
    ll=Sfmargins.right;                                            //~v977I~
  	UTRACEP("lnx_getmargin,right margin by point=%lf\n",ll);       //~v970I~
    ll=ww-ll;                                                      //~v977I~
//  ll+=0.9999; //roundup                                          //~v98jR~
	Srightmargin=ll;                                               //~v970I~
    Srightmargin=max(Srightmargin,MIN_RIGHTM);   //minimum right margin for not monospace font//~v9j1R~
  	UTRACEP("lnx_getmargin,Srightmargin=%f,paperwidth=%lf\n",Srightmargin,ww);//~v98jR~
//top                                                              //~v92dI~
//  ll=gtk_paper_size_get_default_top_margin(pps,unit);            //~v970R~//~v977R~
    ll=Sfmargins.top;                                              //~v977I~
  	UTRACEP("lnx_getmargin,top margin by point=%lf\n",ll);         //~v970I~
    ll=hh-ll;                                                      //~v977I~
//  ll+=0.9999; //roundup                                          //~v98jR~
	Stopmargin=ll;                                                 //~v970I~
  	UTRACEP("lnx_getmargin,top margin Stopmargin=%f,paper height=%lf\n",Stopmargin,hh);//~v98jR~
//bottom                                                           //~v92dI~
//  ll=gtk_paper_size_get_default_bottom_margin(pps,unit);         //~v970R~//~v977R~
    ll=Sfmargins.bottom;                                           //~v977I~
  	UTRACEP("lnx_getmargin bottom margin by point=%lf\n",ll);      //~v970I~
//  ll+=0.9999; //roundup                                          //~v98jR~
	Sbottommargin=ll;                                              //~v970I~
  	UTRACEP("lnx_getmargin bottom margin Sbottommargin=%f\n",Sbottommargin);//~v98jR~
                                                                   //~v977I~
//  Spagewidth=ww;                                                 //~v970I~//~v977R~//~v9a0R~
    Spagewidth=(int)ww;                                            //~v9a0I~
//  Spageheight=hh;                                               //~v970I~//~v977R~//~v9a0R~
    Spageheight=(int)hh;                                           //~v9a0I~
                                                                   //~v977I~
	ll=gtk_paper_size_get_height(pps,GTK_UNIT_INCH);               //~v970R~
    ll2=gtk_print_settings_get_resolution_y(Spsettings);           //~v970I~
	UTRACEP("lnx_getmargin height inch=%lf,y-resolution=%lf\n",ll,ll2);//~v970R~
    ll=ll2/ll;                                                     //~v970I~
    Sinchheightpixel=ll;                                           //~v970I~
	ll=gtk_paper_size_get_width(pps,GTK_UNIT_INCH);                //~v970R~
    ll2=gtk_print_settings_get_resolution_x(Spsettings);           //~v970I~
	UTRACEP("lnx_getmargin width inch=%lf,y-resolution=%lf\n",ll,ll2);//~v970R~//~v98hR~
    ll=ll2/ll;                                                     //~v970I~
    Sinchwidthpixel=ll;                                            //~v970I~
	UTRACEP("lnx_getmargin pix/inch x=%lf,y=%lf\n",Sinchwidthpixel,Sinchheightpixel);//~v970I~
    if (Spagewidth<Spageheight)   //width<height                   //~v970I~
        UCBITON(swsw3,SW3WINTATE);   //maxline*=2                  //~v970I~
    if (Gformtype & PFT_YOKO)   //reverse landscape:top-->left     //~v970R~
#ifdef DDD                                                         //~v97aR~
  	if (!(Gxpotheropt & GOO_NOROTATION))                           //~v97aI~
#endif                                                             //~v97aI~
    {                                                              //~v970I~
    	mt=Spageheight;                                            //~v970I~
        Spageheight=Spagewidth;                                    //~v970R~
//      Spagewidth=mt;                                             //~v970R~//~v9a0R~
        Spagewidth=(int)mt;                                        //~v9a0I~
                                                                   //~v970I~
        mt=Stopmargin;                                             //~v970I~
        mb=Sbottommargin;                                          //~v970I~
        ml=Sleftmargin;                                            //~v970I~
        mr=Srightmargin;                                           //~v970I~
                                                                   //~v970I~
      if (Gformtype & PFT_REVERSE)                                 //~v98iI~
      {                                                            //~v98iI~
        Sleftmargin=mt;                                            //~v970R~
        Srightmargin=mb;                                           //~v970I~
        Stopmargin=mr;                                             //~v970I~
        Sbottommargin=ml;                                          //~v970I~
      }                                                            //~v98iI~
      else                                                         //~v98iI~
      {                                                            //~v98iI~
        Sleftmargin=mb;                                            //~v98iI~
        Srightmargin=mt;                                           //~v98iI~
        Stopmargin=ml;                                             //~v98iR~
        Sbottommargin=mr;                                          //~v98iR~
      }                                                            //~v98iI~
    }                                                              //~v970I~
    else    //portrait                                             //~v98iI~
    {                                                              //~v98iI~
      if (Gformtype & PFT_REVERSE)                                 //~v98iI~
      {                                                            //~v98iI~
        mt=Stopmargin;                                             //~v98iI~
        mb=Sbottommargin;                                          //~v98iI~
        ml=Sleftmargin;                                            //~v98iI~
        mr=Srightmargin;                                           //~v98iI~
                                                                   //~v98iI~
        Sleftmargin=mr;                                            //~v98iR~
        Srightmargin=ml;                                           //~v98iI~
        Stopmargin=mb;                                             //~v98iI~
        Sbottommargin=mt;                                          //~v98iI~
      }                                                            //~v98iI~
    }                                                              //~v98iI~
                                                                   //~v98iI~
    UTRACEP("%s:Gformtyp=%x,Spagewidth=%d,Spageheight=%d\n",UTT,Gformtype,Spagewidth,Spageheight);//~v977I~//~v9i0R~
    UTRACEP("%s:margin t=%f,b=%f,l=%f,r=%f\n",UTT,Stopmargin,Sbottommargin,Sleftmargin,Srightmargin);//~v98jR~//~v9i0R~
    return;                                                        //~v970I~
}//lnx_getdcinf                                                    //~v970R~
#else  //!GTKPRINT
//=========================================================================
void lnx_getdcinf(void)                                            //~v92dR~
{                                                                  //~v844I~
	const GnomePrintUnit *pgpupt,*pretunit,*pgpumm,*pgpuin;        //~v92dR~
    gdouble ll,ll2;                                                //~v92hR~
    int rc;                                                        //~v92dI~
//********************************                                 //~v92dI~
	pgpupt=gnome_print_unit_get_by_name("Point");                  //~v92dR~
	pgpumm=gnome_print_unit_get_by_name("MilliMeter");             //~v92dI~
	pgpuin=gnome_print_unit_get_by_name("Inches");                 //~v92dI~
//  printf("printunit name=%s,unit=%d,unittobase=%lf\n",pgpupt->name,pgpupt->base,pgpupt->unittobase);//~v92hR~
//left                                                             //~v92dI~
    ll=0.0; //should be initialized                                //~v92dI~
    rc=gnome_print_config_get_length(Spgpconfig,GNOME_PRINT_KEY_PAPER_MARGIN_LEFT,&ll,&pretunit);//~v92dR~
  UTRACEP("rc=%d,left margin by mm=%lf\n",rc,ll);                  //~v951R~
    if (ll)                                                        //~v92dI~
	    rc=gnome_print_convert_distance(&ll,pretunit,pgpupt);	//mm-->pt//~v92dI~
    else                                                           //~v92dI~
    {                                                              //~v92dI~
	    ll=Sleftmargin;	//default is by mm                         //~v92dI~
	    rc=gnome_print_convert_distance(&ll,pgpumm,pgpupt);	//mm-->pt//~v92dI~
    }                                                              //~v92dI~
	Sleftmargin=ll;                                                //~v92dI~
  UTRACEP("rc=%d,left margin by point=%lf\n",rc,ll);               //~v951R~
//right                                                            //~v92dI~
    ll=0.0;                                                        //~v92dI~
    rc=gnome_print_config_get_length(Spgpconfig,GNOME_PRINT_KEY_PAPER_MARGIN_RIGHT,&ll,&pretunit);//~v92dR~
  UTRACEP("rc=%d,right margin by mm=%lf\n",rc,ll);                 //~v951R~
    if (ll)                                                        //~v92dI~
	    rc=gnome_print_convert_distance(&ll,pretunit,pgpupt);	//mm-->pt//~v92dI~
    else                                                           //~v92dI~
    {                                                              //~v92dI~
	    ll=Srightmargin;	//default is by mm                     //~v92dI~
	    rc=gnome_print_convert_distance(&ll,pgpumm,pgpupt);	//mm-->pt//~v92dI~
    }                                                              //~v92dI~
	Srightmargin=ll;                                               //~v92dI~
  UTRACEP("rc=%d,right margin by point=%lf\n",rc,ll);              //~v951R~
//top                                                              //~v92dI~
    ll=0.0;                                                        //~v92dI~
    rc=gnome_print_config_get_length(Spgpconfig,GNOME_PRINT_KEY_PAPER_MARGIN_TOP,&ll,&pretunit);//~v92dR~
  UTRACEP("rc=%d,top margin by mm=%lf\n",rc,ll);                   //~v951R~
    if (ll)                                                        //~v92dI~
	    rc=gnome_print_convert_distance(&ll,pretunit,pgpupt);	//mm-->pt//~v92dI~
    else                                                           //~v92dI~
    {                                                              //~v92dI~
	    ll=Stopmargin;	//default is by mm                         //~v92dI~
	    rc=gnome_print_convert_distance(&ll,pgpumm,pgpupt);	//mm-->pt//~v92dI~
    }                                                              //~v92dI~
	Stopmargin=ll;                                                 //~v92dR~
  UTRACEP("rc=%d,top margin by point=%lf\n",rc,ll);                //~v951R~
//bottom                                                           //~v92dI~
    ll=0.0;                                                        //~v92dM~
    rc=gnome_print_config_get_length(Spgpconfig,GNOME_PRINT_KEY_PAPER_MARGIN_BOTTOM,&ll,&pretunit);//~v92dR~
  UTRACEP("rc=%d,bottom margin by mm=%lf\n",rc,ll);                //~v951R~
    if (ll)                                                        //~v92dI~
	    rc=gnome_print_convert_distance(&ll,pretunit,pgpupt);	//mm-->pt//~v92dI~
    else                                                           //~v92dI~
    {                                                              //~v92dI~
	    ll=Sbottommargin;	//default is by mm                     //~v92dI~
	    rc=gnome_print_convert_distance(&ll,pgpumm,pgpupt);	//mm-->pt//~v92dI~
    }                                                              //~v92dI~
	Sbottommargin=ll;                                              //~v92dI~
  UTRACEP("rc=%d,bottom margin by point=%lf\n",rc,ll);             //~v951R~
    ll=0.0;                                                        //~v92dI~
    rc=gnome_print_config_get_length(Spgpconfig,GNOME_PRINT_KEY_PAPER_SIZE,&ll,&pretunit);//~v92dR~
  UTRACEP("rc=%d,papersize by point=%lf\n",rc,ll);                 //~v951R~
#ifdef CCC  //not effected by orientation change                   //~v92hR~
    ll=0.0;                                                        //~v92dI~
    rc=gnome_print_config_get_length(Spgpconfig,GNOME_PRINT_KEY_PAPER_WIDTH,&ll,&pretunit);//~v92dR~
    printf("rc=%d,paper width=%lf\n",rc,ll);                       //~v92dM~
    if (ll)                                                        //~v92dI~
    	rc=gnome_print_convert_distance(&ll,pretunit,pgpupt);	//mm-->pt//~v92dR~
    else                                                           //~v92dI~
    {                                                              //~v92dI~
	    ll=Spagewidth;	//default is by mm                         //~v92dR~
	    rc=gnome_print_convert_distance(&ll,pgpumm,pgpupt);	//mm-->pt//~v92dI~
    }                                                              //~v92dI~
    Spagewidth=ll;                                                 //~v92dR~
  UTRACEP("rc=%d,paper width by point%lf\n",rc,ll);                //~v951R~
#ifndef BBB                                                        //~v92dI~
    ll=Spagewidth;                                                 //~v92dR~
    rc=gnome_print_convert_distance(&ll,pretunit,GNOME_PRINT_PS_UNIT);	//mm-->pt//~v92dR~
//  printf("rc=%d,paper width by PS_UNIT %lf\n",rc,ll);            //~v92hR~
#endif                                                             //~v92dI~
    ll=0.0;                                                        //~v92dI~
    rc=gnome_print_config_get_length(Spgpconfig,GNOME_PRINT_KEY_PAPER_HEIGHT,&ll,&pretunit);//~v92dR~
  UTRACEP("rc=%d,paper height by mm=%lf\n",rc,ll);                 //~v951R~
    if (ll)                                                        //~v92dI~
	    rc=gnome_print_convert_distance(&ll,pretunit,pgpupt);	//mm-->pt//~v92dI~
    else                                                           //~v92dI~
    {                                                              //~v92dI~
	    ll=Spageheight;	//default is by mm                         //~v92dI~
	    rc=gnome_print_convert_distance(&ll,pgpumm,pgpupt);	//mm-->pt//~v92dI~
    }                                                              //~v92dI~
    Spageheight=ll;                                                //~v92dR~
  UTRACEP("rc=%d,paper height by point%lf\n",rc,ll);               //~v951R~
#endif  //CCC                                                      //~v92hI~
    rc=gnome_print_job_get_page_size_from_config(Spgpconfig,&ll,&ll2);//~v92hM~
  UTRACEP("pagesize from config rc=%d,ww=%lf,hh=%lf\n",rc,ll,ll2); //~v951R~
    Spagewidth=ll;                                                 //~v92hI~
    Spageheight=ll2;                                               //~v92hI~
                                                                   //~v92hI~
    ll=0.0;                                                        //~v92dI~
    rc=gnome_print_config_get_length(Spgpconfig,GNOME_PRINT_KEY_RESOLUTION_DPI_X,&ll,&pretunit);//~v92dR~
//  printf("rc=%d,resolution x by point=%lf\n",rc,ll);             //~v92hR~
    ll=0.0;                                                        //~v92dI~
    rc=gnome_print_config_get_length(Spgpconfig,GNOME_PRINT_KEY_RESOLUTION_DPI_Y,&ll,&pretunit);//~v92dR~
//  printf("rc=%d,resolution y by point=%lf\n",rc,ll);             //~v92hR~
    ll=1.0;                                                        //~v92dI~
	rc=gnome_print_convert_distance(&ll,pgpuin,pgpupt);	//inch-->pt//~v92dI~
    Sinchheightpixel=ll;                                           //~v92dM~
    Sinchwidthpixel=ll;                                            //~v92dM~
//  printf("rc=%d,pix/inch%lf\n",rc,ll);                           //~v92hR~
    if (Spagewidth<Spageheight)   //width<height                   //~v92hI~
        UCBITON(swsw3,SW3WINTATE);   //maxline*=2                  //~v92hI~
    rc=rc;	//for compilerwarning:unused-but-set                   //~v964I~
    return;                                                        //~v92dI~
}//lnx_getdcinf                                                    //~v92dR~
#endif //!GTKPRINT
#ifdef GTKPRINT                                                    //~v970I~
//=========================================================================//~v970I~
//int lnx_searchfont(char *Pstr)                                   //~v970R~
int lnx_searchfont(int Popt,char *Pstr)                            //~v970I~
{
//  GList *list,*tmp;                                              //~v92dR~
	gchar *font,*fonto;                                            //~v92dR~
	char *fontfound=NULL;                                          //~v970I~
    int ii=0,jj=0;                                                 //~v92dR~
  	int nfamilies,kk;                                                //~v970I~
  	PangoFontMap *pfm;                                               //~v970I~
	PangoFontFamily **pfamilies;                                     //~v970I~
//***********************************                              //~v92dI~
    UTRACEP("lnx_searchfont\n");                                        //~v92hR~
//  tmp=list=gnome_font_list ();                                   //~v92dI~
    pfm=pango_cairo_font_map_get_default();                        //~v970I~
    pango_font_map_list_families(pfm,&pfamilies,&nfamilies);       //~v970R~
    UTRACEP("lnx_searchfont nfamilies=%d\n",nfamilies);
    fonto="";                                                      //~v92dR~
//  while (tmp)                                                    //~v92dR~
    for (kk=0;kk<nfamilies;kk++)
    {                                                              //~v92dI~
//  	font=tmp->data;                                            //~v92dI~
//  	tmp=tmp->next;                                             //~v92dI~
    	font=(gchar *)pango_font_family_get_name(pfamilies[kk]);   //~v970R~
        if (!strcmp(fonto,font))                                   //~v92dR~
        	continue;                                              //~v92dI~
        fonto=font;                                                //~v92dI~
        ii++;                                                      //~v92dM~
  		UTRACEP("lnx_searchfont font=%s\n",font);                                       //~v92dR~
      if (Popt & SFO_LIST)                                         //~v970I~
      {                                                            //~v970I~
//      if (strstr(font,Pstr))                                     //~v970R~
        if (ustrstri(font,Pstr))                                   //~v970I~
        {                                                          //~v92dI~
			printf("-%s\n",font);                                  //~v92dR~
            jj++;                                                  //~v92dI~
        }                                                          //~v92dI~
      }                                                            //~v970I~
      else	//search                                               //~v970I~
      {                                                            //~v970I~
      	UTRACEP("searchfont entry=%s,req=%s\n",font,Pstr);         //~v975I~
        if (ustrstri(font,Pstr))   //parm:familyname only          //~v970R~
        {                                                          //~v970I~
            jj++;                                                  //~v970I~
            if (fontfound)                                         //~v970I~
            	free(fontfound);                                   //~v970I~
           	fontfound=strdup(font);                                //~v970I~
	        if (!stricmp(font,Pstr)) //completely match             //~v970I~//~v975R~
            {                                                      //~v975I~
                jj=1;   //ignore previously half matched           //~v975I~
            	break;                                             //~v970I~
            }                                                      //~v975I~
        }                                                          //~v970I~
      }                                                            //~v970I~
	}                                                              //~v92dI~
//  gnome_font_list_free(list);                                    //~v92dI~
  if (Popt & SFO_LIST)                                             //~v970I~
    uerrmsg("End Of listup Fontname containing string (\"%s\") %d of total %d",0,//~v92dI~
        			Pstr,jj,ii);                                   //~v92dI~
    UTRACEP("lnx_searchfont match count=%d\n",jj);                 //~v970I~
    if (fontfound)                                                 //~v970I~
    	Sselectedfontface=fontfound;                               //~v970I~
    return jj;                                                     //~v92dR~
}//lnx_searchfont                                                  //~v92dR~
#else  //!GTKPRINT                                                 //~v970I~
//=========================================================================//~v970I~
//***************************************************************************
//*listup font                                                     //~v92dR~
//**************************************************************************
int lnx_searchfont(char *Pstr)                                     //~v92dR~
{
	GList *list,*tmp;                                              //~v92dR~
	gchar *font,*fonto;                                            //~v92dR~
    int ii=0,jj=0;                                                 //~v92dR~
//***********************************                              //~v92dI~
//  printf("searchfont\n");                                        //~v92hR~
	tmp=list=gnome_font_list ();                                   //~v92dI~
    fonto="";                                                      //~v92dR~
	while (tmp)                                                    //~v92dR~
    {                                                              //~v92dI~
		font=tmp->data;                                            //~v92dI~
		tmp=tmp->next;                                             //~v92dI~
        if (!strcmp(fonto,font))                                   //~v92dR~
        	continue;                                              //~v92dI~
        fonto=font;                                                //~v92dI~
        ii++;                                                      //~v92dM~
//		printf("%s\n",font);                                       //~v92dR~
        if (strstr(font,Pstr))                                     //~v92dR~
        {                                                          //~v92dI~
			printf("-%s\n",font);                                  //~v92dR~
            jj++;                                                  //~v92dI~
        }                                                          //~v92dI~
	}                                                              //~v92dI~
	gnome_font_list_free(list);                                    //~v92dI~
    uerrmsg("End Of listup Fontname containing string (\"%s\") %d of total %d",0,//~v92dI~
        			Pstr,jj,ii);                                   //~v92dI~
    return jj;                                                     //~v92dR~
}//lnx_searchfont                                                  //~v92dR~
#endif //!GTKPRINT                                                 //~v970I~
//===============================================================================//~v92dI~
//get font for printer                                             //~v92dI~
//outfontname :se if changed from input                            //~v92dI~
//===============================================================================//~v92dI~
PangoLanguage *lnx_getpangolang(void)                              //~v92dR~
{                                                                  //~v92dI~
	char *plang;                                                   //~v92dI~
    PangoLanguage *pplang;                                         //~v92dR~
//************************                                         //~v92dI~
    plang=setlocale(LC_ALL,"");   //for pango_language_get_default()//~v92dI~
    pplang=pango_language_from_string(plang);                      //~v970I~
  if (Gtraceopt)      //trace option by /Yt                        //~v97pI~
    printf("pangolang=%p(%s)\n",pplang,plang);                     //~v92hR~//~v970R~
    UTRACEP("pangolang=%p(%s)\n",pplang,plang);                    //~v970I~
    return pplang;                                                 //~v92dI~
}                                                                  //~v92dI~
#ifdef GTKPRINT                                                    //~v96cI~//~v970M~
//===============================================================================//~v970I~
//parse parm font "face;style;size" fmt                            //~v970I~
//===============================================================================//~v970I~
void                                                               //~v970I~
lnx_parsefontname(char *Pnm,char **Ppfamily,char **Ppstyle,char **Ppsize)//~v970R~
{                                                                  //~v970I~
	char *pc,*pfamily,*pstyle=0,*psize=0;                          //~v970R~
//************************                                         //~v970I~
	pfamily=Pnm+strspn(Pnm," ");                                   //~v970I~
	pc=strchr(pfamily,';');                                        //~v970R~
    if (pc)                                                        //~v970I~
    {                                                              //~v970I~
    	*pc++=0;                                                   //~v970I~
        pc+=strspn(pc," ");                                        //~v970I~
        pstyle=pc;                                                 //~v970I~
        pc=strchr(pstyle,';');                                     //~v970I~
        if (pc)                                                    //~v970I~
        {                                                          //~v970I~
	    	*pc++=0;                                               //~v970I~
	        pc+=strspn(pc," ");                                    //~v970I~
	        psize=pc;                                              //~v970I~
        }                                                          //~v970I~
    }                                                              //~v970I~
    *Ppfamily=pfamily;                                             //~v970I~
    *Ppstyle=pstyle;                                               //~v970I~
    *Ppsize=psize;                                                 //~v970I~
}//lnx_parsefontname                                               //~v970I~
//===============================================================================//~v970I~
char *                                                             //~v970I~
lnx_lookupenum(GType Pgt,int Pvalue)                               //~v970R~
{                                                                  //~v970I~
  	GEnumClass *pclass;                                            //~v970I~
	GEnumValue *pev;                                               //~v970I~
    const char *pnickname;                                         //~v970I~
//************************************                             //~v970I~
  	pclass=g_type_class_ref(Pgt);                                  //~v970I~
  	pev=g_enum_get_value(pclass,Pvalue);                           //~v970R~
    pnickname=pev->value_nick;                                     //~v970I~
    UTRACEP("lnx_lookupnum GType=%p,class=%p,vale=%d,name=%s\n",(void*)Pgt,pclass,Pvalue,pnickname);//~v970R~
    return (char *)pnickname;                                      //~v970R~
}//lnx_lookupenum                                                  //~v970I~
//===============================================================================//~v970I~
void                                                               //~v970I~
lnx_printfd(PangoFontDescription *Ppfd)
{
	PangoStyle style;                                              //~v970I~
	PangoWeight weight;                                            //~v970I~
    const char *pname,*pstyle,*pweight;                            //~v970I~
    GType gstyle,gweight;                                          //~v970I~
    double sz;
//************************************
    pname=pango_font_description_get_family(Ppfd);                 //~v970I~
    style=pango_font_description_get_style(Ppfd);                  //~v970I~
    weight=pango_font_description_get_weight(Ppfd);                //~v970I~
    sz=pango_font_description_get_size(Ppfd);                      //~v970R~
    sz=sz;                                                         //~v9b0I~
    gstyle=PANGO_TYPE_STYLE;                                       //~v970I~
    gweight=PANGO_TYPE_WEIGHT;                                     //~v970I~
    if (style!=PANGO_STYLE_NORMAL)                                 //~v970I~
		pstyle=lnx_lookupenum(gstyle,style);                       //~v970R~
    else                                                           //~v970I~
		pstyle="";                                                 //~v970I~
    if (weight!=PANGO_WEIGHT_NORMAL)                               //~v970I~
		pweight=lnx_lookupenum(gweight,weight);                    //~v970R~
    else                                                           //~v970I~
		pweight="";                                                //~v970I~
    UTRACEP("Selected font:gstype=%p,gweight=%p,style=%d,weight=%d,sz=%lf\n",gstyle,gweight,style,weight,sz/PANGO_SCALE);//~v970R~
    if (style!=PANGO_STYLE_NORMAL||weight!=PANGO_WEIGHT_NORMAL)    //~v970I~
	    printf("Selected Font:\"%s;%s %s\"\n",pname,pstyle,pweight);//~v970R~
    else                                                           //~v970I~
	    printf("Selected Font:\"%s\"\n",pname);                    //~v970R~
}//lnx_printfd                                                     //~v970I~
//===============================================================================//~v92dI~
//get font for printer                                             //~v92dI~
//outfontname :se if changed from input                            //~v92dI~
//===============================================================================//~v92dI~
PangoFontDescription *lnx_createfont(char *Pfontname,gdouble Pffontsz)//~v970R~
{                                                                  //~v92dI~
//  GnomeFont *pfont;                                              //~v970R~
    PangoFontDescription *pfont;                                   //~v970R~
//    char *pfontname,*pfontname2,*pc,*pc2;                        //~v970R~
    char *pfontname,*pc;                                           //~v970R~
//  int len;                                                       //~v92dI~//~v970R~
    int ctr;                                                       //~v970I~
//    gunichar ch;                                                 //~v970R~
//    gint glyph;                                                  //~v970R~
//    gdouble fglyphsz;                                            //~v970R~
	char *pparsed,*pfamily,*pstyle,*psize;                         //~v970I~
    char fontszwk[32];                                             //~v970I~
//************************************                             //~v92dI~
    if (Pfontname && *Pfontname)                                   //~v92dI~
		pfontname=Pfontname;                                       //~v92dR~
    else                                                           //~v92dI~
		pfontname=DEFAULT_FONTNAME;                                //~v92dI~
   	UTRACEP("%s:parm fontname=%s,size=%lf\n",UTT,pfontname,Pffontsz);//~v970R~//~v9j1R~
//set size if missing                                              //~v92dI~
//    pc=malloc(strlen(pfontname)+10);                               //~v92dR~//~v970R~
//    strcpy(pc,pfontname);                                          //~v92dR~//~v970R~
//    len=ustrrspn(pc," ")+1;  //drop trailer space                  //~v92dR~//~v970R~
//    *(pc+len)=0;                                                   //~v92dR~//~v970R~
//    pc2=strrchr(pc,' ');                                           //~v92dR~//~v970R~
//    if (pc2)                                                       //~v92dR~//~v970R~
//    {                                                              //~v92dR~//~v970R~
//        pc2++;                                                     //~v92dR~//~v970R~
//        if (atoi(pc2)<=0)         //size missing                   //~v92dR~//~v970R~
//        {                                                          //~v92dR~//~v970R~
//            if (Pffontsz>0)     //not initial call                 //~v92dR~//~v970R~
//                sprintf(pc+len," %lf",Pffontsz);   //supply        //~v92dR~//~v970R~
//            else                                                   //~v92hI~//~v970R~
//                sprintf(pc+len," %lf",DEFAULT_FONTSIZE);   //supply//~v92hI~//~v970R~
//            pfontname=pc;                                          //~v92hR~//~v970R~
//            UTRACEP("lnx_createfont fontname %s-->%s\n",Pfontname,pfontname);//~v970R~
//        }                                                          //~v92dR~//~v970R~
//        else                                                       //~v92dI~//~v970R~
//        {                                                          //~v92dI~//~v970R~
//            if (Pffontsz==0)    //initial call                     //~v92dR~//~v970R~
//            {                                                      //~v92dI~//~v970R~
//                if (pfontname!=(char *)DEFAULT_FONTNAME)           //~v92vI~//~v970R~
//                    Sfontsizespecifiedsw=1;                        //~v92dR~//~v970R~
//            }                                                      //~v92dI~//~v970R~
//            else                                                   //~v92dI~//~v970R~
//            {                                                      //~v92dI~//~v970R~
//                sprintf(pc2,"%lf",Pffontsz);   //change            //~v92dI~//~v970R~
//                pfontname=pc;                                      //~v92dI~//~v970R~
//            }                                                      //~v92dI~//~v970R~
//        }                                                          //~v92dI~//~v970R~
//    }                                                              //~v92dI~//~v970R~
    pparsed=strdup(pfontname);                                     //~v970I~
    lnx_parsefontname(pparsed,&pfamily,&pstyle,&psize);    //format "family;style;size"//~v970I~
    ctr=lnx_searchfont(0/*search*/,pfamily);                       //~v970I~
    if (!ctr)                                                      //~v970I~
            uerrexit("Font family %s (of %s) not found",0,         //~v970I~
                    pfamily,pfontname);                            //~v970I~
    if (ctr>1)                                                     //~v970I~
    {                                                              //~v970I~
    	free(Sselectedfontface);                                   //~v970I~
        uerrexit("multiple Fonts family for %s, check by -F\"?%s\"",0,//~v970R~
                    pfamily,pfamily);                              //~v970R~
    }                                                              //~v970I~
    pfamily=Sselectedfontface;                                     //~v970I~
    pc=malloc(strlen(pfontname)+strlen(pfamily)+32);               //~v970R~
    if (!psize)                                                    //~v970I~
    {                                                              //~v970I~
#ifdef SSS                                                         //~v9j4I~
    	if (Pffontsz>0)     //not initial call                     //~v970I~
			sprintf(fontszwk,"%lf",Pffontsz);   //supply           //~v970I~
    	else                                                       //~v970I~
			sprintf(fontszwk,"%lf",DEFAULT_FONTSIZE);   //supply   //~v970I~
#else                                                              //~v9j4I~
    	if (Pffontsz>0)     //not initial call                     //~v9j4I~
			sprintf(fontszwk,"%d",(int)Pffontsz);   //supply       //~v9j4I~
    	else                                                       //~v9j4I~
			sprintf(fontszwk,"%d",(int)DEFAULT_FONTSIZE);   //supply//~v9j4I~
#endif                                                             //~v9j4I~
    }                                                              //~v970I~
    else                                                           //~v970I~
    {                                                              //~v970I~
		if (Pffontsz==0)    //initial call                         //~v970I~
        {                                                          //~v970I~
//  		if (pfontname!=(char *)DEFAULT_FONTNAME)               //~v970R~
//  			Sfontsizespecifiedsw=1;  //ignore user specified size//~v970R~
//          strcpy(fontszwk,psize);                                //~v970R~
			sprintf(fontszwk,"%lf",DEFAULT_FONTSIZE);   //supply   //~v970I~
		}                                                          //~v970I~
        else                                                       //~v970I~
        {                                                          //~v970I~
			if (Sfontsizespecifiedsw==1)	//no user specified size//~v970I~
	            strcpy(fontszwk,psize);                            //~v970I~
            else                                                   //~v970I~
    			sprintf(fontszwk,"%lf",Pffontsz);   //change       //~v970R~//~v975R~
        }                                                          //~v970I~
    }                                                              //~v970I~
    if (pstyle)                                                    //~v970I~
    	sprintf(pc,"%s %s %s",pfamily,pstyle,fontszwk);            //~v970R~
    else                                                           //~v970I~
    	sprintf(pc,"%s %s",pfamily,fontszwk);                      //~v970R~
   	UTRACEP("%s:pfontname with size == %s\n",UTT,pc);                //~v970R~//~v9i0R~//~v9j1R~
    free(pparsed);                                                 //~v970I~
    pfontname=pc;                                                  //~v970I~
//calc font scale(width/height)                                    //~v92dI~
//  Sffontsz=gnome_font_get_size(pfont);                           //~v970R~
//  printf("gnome font sz=%lf\n",Sffontsz);                        //~v92hR~
//  ch='A';                                                        //~v970R~
//  glyph=gnome_font_lookup_default(pfont,ch);                     //~v970R~
//  fglyphsz=gnome_font_get_glyph_width(pfont,glyph);              //~v970R~
//  printf("glyph %x(%d) size=%lf\n",ch,glyph,fglyphsz);           //~v92hR~
//  Sffontscale=fglyphsz/Sffontsz;	//width/height                 //~v970R~
//  printf("fontscale=%lf\n",Sffontscale);                         //~v92hR~
//  printf("color=%x\n",Gprint_color);                             //~v92hR~
    pfont=pango_font_description_from_string(pfontname);           //~v970R~
    if (!pfont)                                                    //~v970I~
    	uerrexit("Font creation(%s) failed",0,                     //~v970I~
        	     pfontname);                                       //~v970I~
	if (!Pffontsz)     //initial call                              //~v970I~
    	lnx_printfd(pfont);                                        //~v970R~
    UTRACEP("lnx_createfont %s size=%lf,getname=%s,gettype=%d\n",pfontname,((gdouble)pango_font_description_get_size(pfont)/PANGO_SCALE),pango_font_description_get_family(pfont),pango_font_description_get_style(pfont));//~v970R~
    return pfont;                                                  //~v92dI~
}//lnx_createfont                                                  //~v92dR~
//===============================================================================
#else  //!GTKPRINT                                                 //~v96cI~
GnomeFont *lnx_createfont(char *Pfontname,gdouble Pffontsz)        //~v92dR~
{                                                                  //~v92dI~
	GnomeFont *pfont;                                              //~v92dI~
    char *pfontname,*pfontname2,*pc,*pc2;                          //~v92dR~
    int len;                                                       //~v92dI~
    gunichar ch;                                                   //~v92dI~
    gint glyph;                                                    //~v92dI~
    gdouble fglyphsz;                                              //~v92dI~
//************************************                             //~v92dI~
    if (Pfontname && *Pfontname)                                   //~v92dI~
		pfontname=Pfontname;                                       //~v92dR~
    else                                                           //~v92dI~
		pfontname=DEFAULT_FONTNAME;                                //~v92dI~
// 	printf("createfont parm == %s\n",pfontname);                   //~v92hR~
//set size if missing                                              //~v92dI~
    pc=malloc(strlen(pfontname)+10);                               //~v92dR~
    strcpy(pc,pfontname);                                          //~v92dR~
    len=ustrrspn(pc," ")+1;  //drop trailer space                  //~v92dR~
    *(pc+len)=0;                                                   //~v92dR~
    pc2=strrchr(pc,' ');                                           //~v92dR~
    if (pc2)                                                       //~v92dR~
    {                                                              //~v92dR~
        pc2++;                                                     //~v92dR~
        if (atoi(pc2)<=0)         //size missing                   //~v92dR~
        {                                                          //~v92dR~
		    if (Pffontsz>0) 	//not initial call                 //~v92dR~
                sprintf(pc+len," %lf",Pffontsz);   //supply        //~v92dR~
            else                                                   //~v92hI~
                sprintf(pc+len," %lf",DEFAULT_FONTSIZE);   //supply//~v92hI~
	        pfontname=pc;                                          //~v92hR~
//          printf("fontname %s-->%s\n",Pfontname,pfontname);      //~v92hR~
        }                                                          //~v92dR~
        else                                                       //~v92dI~
        {                                                          //~v92dI~
		    if (Pffontsz==0) 	//initial call                     //~v92dR~
            {                                                      //~v92dI~
//  			if (pfontname!=DEFAULT_FONTNAME)                   //~v92dI~//~v92vR~
    			if (pfontname!=(char *)DEFAULT_FONTNAME)           //~v92vI~
				    Sfontsizespecifiedsw=1;                        //~v92dR~
            }                                                      //~v92dI~
            else                                                   //~v92dI~
            {                                                      //~v92dI~
                sprintf(pc2,"%lf",Pffontsz);   //change            //~v92dI~
	            pfontname=pc;                                      //~v92dI~
            }                                                      //~v92dI~
        }                                                          //~v92dI~
    }                                                              //~v92dI~
//                                                                 //~v92dI~
// 	printf("createfont with size == %s\n",pfontname);              //~v92hR~
	pfont=gnome_font_find_from_full_name(pfontname);               //~v92dI~
//    if (pfont)                                                   //~v92hR~
//        printf("font=%p for %s,name=%s,family=%s,species=%s,ps=%s\n",pfont,pfontname,//~v92hR~
//                gnome_font_get_name(pfont),                      //~v92hR~
//                gnome_font_get_family_name(pfont),               //~v92hR~
//                gnome_font_get_species_name(pfont),              //~v92hR~
//                gnome_font_get_ps_name(pfont));                  //~v92hR~
    if (!pfont) //not found                                        //~v92dI~
    {                                                              //~v92dI~
        pfont=gnome_font_find_closest_from_full_name(pfontname);   //~v92dR~
        if (!pfont)                                                //~v92dR~
            uerrexit("Font %s not found",0,                        //~v92dR~
                    pfontname);                                    //~v92dR~
        pfontname2=pfontname;                                      //~v92dI~
        pfontname=(char*)gnome_font_get_name(pfont);               //~v92dR~
        uerrmsg("Font \"%s\" not found,closest Font \"%s\" will be selected",0,//~v92dR~
                    pfontname2,pfontname);                         //~v92dR~
    }                                                              //~v92dI~
//calc font scale(width/height)                                    //~v92dI~
    Sffontsz=gnome_font_get_size(pfont);                           //~v92dI~
//  printf("gnome font sz=%lf\n",Sffontsz);                        //~v92hR~
    ch='A';                                                        //~v92dI~
    glyph=gnome_font_lookup_default(pfont,ch);                     //~v92dI~
    fglyphsz=gnome_font_get_glyph_width(pfont,glyph);              //~v92dI~
//  printf("glyph %x(%d) size=%lf\n",ch,glyph,fglyphsz);           //~v92hR~
    Sffontscale=fglyphsz/Sffontsz;	//width/height                 //~v92dI~
//  printf("fontscale=%lf\n",Sffontscale);                         //~v92hR~
//  printf("color=%x\n",Gprint_color);                             //~v92hR~
                                                                   //~v92dI~
    return pfont;                                                  //~v92dI~
}//lnx_createfont                                                  //~v92dR~
#endif //!GTKPRINT                                                 //~v96cI~
//****************************************************************************
//from esccmdsetup at phase2                                       //~v970I~
//from desp_drawpage at flush phase                                //~v970I~
//*setup font and open doc
//*parm1:horizontal width of cell by unit of 1/720(=0.1 point) per inch//~v970R~
//*OR minus (column parm-LINENOSZ-1) from xppf.c when no form and no cpi and with maxcol//~v874I~
//*parm2:vertical  height of cell by unit of 1/720(=0.1 point) per inch        //~v844R~//~v970R~
//*parm3:docname                                                   //~v844I~
//****************************************************************************
#ifdef GTKPRINT
void lnx_opendoc(int Phmi,int Pvmi,char *Pdocname)                 //~v92dR~
{
//********************************
	UTRACEP("%s:lnx_opendoc\n",UTT);                                      //~v970I~//~v9i0R~
	Gxpotheropt&=~GOO_NOPAGEPRINTED;//   0x00000400 //no page oprinted//~v970I~//~v976I~//~v97mM~
	if (Sopendocsw)                                                //~v844I~
    {                                                              //~v97pI~
	  if (Gtraceopt)      //trace option by /Yt                    //~v97pI~
    	printf("duplicated doc open req\n");                       //~v844I~
    }                                                              //~v97pI~
	else                                                           //~v844I~
    {                                                              //~v844I~
	  if (!UCBITCHK(swsw4,SW4OUTSTDO))                             //~v970I~
      {                                                            //~v970I~
		lnx_createlogfont(Phmi,Pvmi);//set Sfscalex etc            //~v970I~
		desp_gtkopendoc(Phmi,Pvmi,Pdocname);                       //~v970I~
      }                                                            //~v970I~
        Sopendocsw=1;                                              //~v844I~
	}//nit opened                                                  //~v844I~
//    if (Gtraceopt)      //trace option by /Yt                    //~v970R~
//        printf("start doc\n");                                   //~v970R~
}//lnx_opendoc                                                     //~v92dR~
//=========================================================================//~v970I~
void lnx_opendoc2printer(int Phmi,int Pvmi,char *Pdocname)         //~v970I~
{                                                                  //~v970I~
//********************************                                 //~v970I~
	UTRACEP("%s:lnx_opendoc2printer\n",UTT);                              //~v970I~//~v9i0R~
	lnx_createlogfont(Phmi,Pvmi);                                  //~v970I~
}//lnx_opendoc                                                     //~v970I~
#else  //!GTKPRINT
//=========================================================================
void lnx_opendoc(int Phmi,int Pvmi,char *Pdocname)                 //~v92dR~
{
//********************************
	if (Sopendocsw)                                                //~v844I~
    {                                                              //~v97pI~
	  if (Gtraceopt)      //trace option by /Yt                    //~v97pI~
    	printf("duplicated doc open req\n");                       //~v844I~
    }                                                              //~v97pI~
	else                                                           //~v844I~
    {                                                              //~v844I~
		lnx_createlogfont(Phmi,Pvmi);                              //~v92dR~
        Sopendocsw=1;                                              //~v844I~
	}//nit opened                                                  //~v844I~
	if (Gtraceopt)		//trace option by /Yt                      //~v889I~
		printf("start doc\n");                                     //~v889R~
}//lnx_opendoc                                                     //~v92dR~
#endif  //!GTKPRINT                                                 //~v96cI~
//**********************************************************************//~v844M~
//* close doc                                                      //~v844I~
//**********************************************************************//~v844M~
#ifdef GTKPRINT                                                    //~v970I~
//=========================================================================//~v970I~
void lnx_closedoc(void)
{
//********************************
//    if (Gtraceopt)      //trace option by /Yt                    //~v970R~
//        printf("EndDoc\n");                                      //~v970R~
	if (UCBITCHK(swsw4,SW4OUTSTDO))                                //~v970I~
    	return;                                                    //~v970I~
    UTRACEP("lnc_closedoc opendocsw=%d,Srealpagectr=%d,Gxpotheropt=%x\n",Sopendocsw,Srealpagectr,Gxpotheropt);                                     //~v970I~//~v97kR~//~v97mR~
  	if (UCBITCHK(swsw3,SW3FORM2P))	//form 2p
		closedoc2p();	//flushout line on 2p work tbl
  if (Gxpotheropt&GOO_NOPAGEPRINTED)//   0x00000400 //no page oprinted//~v970I~//~v976I~//~v97mR~
	Sopendocsw=0;	//avoid duplicated opendoc msg                 //~v97mI~
  else                                                             //~v97mI~
	if (Sopendocsw)
    {
		lnx_closepage();
//        gnome_print_job_close(Spgpjob);                          //~v970R~
//        gnome_print_job_print(Spgpjob);                          //~v970R~
//        g_object_unref(Spgpcontext);                             //~v970R~
//        g_object_unref(Spgpjob);                                 //~v970R~
		lnx_flushprint();	//print_operation_run                  //~v970R~
		Sopendocsw=0;
        totpage+=Gdrawpagectr;                                     //~v97cR~
        printedmsg();                                              //~v97cI~
	}
    UTRACEP("lnc_closedoc Gdrawpagectr=%d,totpage=%d\n",Gdrawpagectr,totpage);//~v97kI~
	return;
}//lnx_closedoc
#else  //!GTKPRINT                                                 //~v970I~
//=========================================================================//~v970I~
void lnx_closedoc(void)                                            //~v92dR~
{                                                                  //~v844M~
//********************************                                 //~v844M~
	if (Gtraceopt)		//trace option by /Yt                      //~v889I~
		printf("EndDoc\n");                                        //~v889R~
  	if (UCBITCHK(swsw3,SW3FORM2P))	//form 2p                      //~v914I~
		closedoc2p();	//flushout line on 2p work tbl             //~v914R~
	if (Sopendocsw)                                                //~v844R~
    {                                                              //~v844I~
		lnx_closepage();                                           //~v92dR~
		gnome_print_job_close(Spgpjob);                            //~v92dI~
		gnome_print_job_print(Spgpjob);                            //~v92dI~
    	g_object_unref(Spgpcontext);                               //~v92dI~
    	g_object_unref(Spgpjob);                                   //~v92dI~
		Sopendocsw=0;                                              //~v844M~
        Srealpagectr=0;                                            //~v970I~
	}                                                              //~v92dR~
	return;                                                        //~v844M~
}//lnx_closedoc                                                    //~v92dR~
#endif //!GTKPRINT                                                 //~v970I~
//****************************************************************************
//start new page
//****************************************************************************
#ifdef GTKPRINT                                                    //~v970I~
//=========================================================================//~v970I~
void lnx_newpage(void)                                             //~v92dR~
{
    int leftpagesw,newpagesw;                                      //~v904R~
#ifdef AAA                                                         //~v970I~
    cairo_t *cr;                                                   //~v970I~
#endif                                                             //~v970I~
//********************************
  if (Gtraceopt)		//trace option by /Yt                      //~v976I~
	printf("NewPage\n");                                           //~v976I~
    UTRACEP("lnx_newpage Sflushphase=%d,Srightpagepos=%d,despageno=%d,breakpage=%d,Sopenpagesw=%d\n",Sflushphase,Srightpageposx,despageno,breakpage,Sopenpagesw);//~v970I~
	if (UCBITCHK(swsw4,SW4OUTSTDO))                                //~v970I~
    {                                                              //~v970I~
		fwrite("\x0c",1,1,stdout);                                 //~v970I~
    	return;                                                    //~v970I~
    }                                                              //~v970I~
    if (Srightpageposx)                                            //~v904R~
    	if (despageno)      //reverse page print                   //~v904I~
        {                                                          //~v904I~
            leftpagesw=((despageno-breakpage)%2==0); //left when residual page is even//~v904R~
            newpagesw=!leftpagesw || (breakpage==1);               //~v904R~
        }                                                          //~v904I~
        else                                                       //~v904I~
            newpagesw=leftpagesw=(breakpage%2!=0);                 //~v904R~
    else                                                           //~v904I~
    	newpagesw=leftpagesw=1;                                    //~v904R~
  if (newpagesw)	//before new page start                        //~v904R~
  {                                                                //~v904I~
	if (Sopenpagesw)                                               //~v844R~
    {
//  	if (Gtraceopt)		//trace option by /Yt                  //~v92dR~//~v976R~
//  		printf("duplicated page open reques\n");               //~v92dR~//~v976R~
    	lnx_closepage();                                           //~v92dR~
	}
    desp_gtknewpage();	//wite index for fseek                     //~v970I~
	if (Gtraceopt)		//trace option by /Yt                      //~v889I~
		printf("StartPage\n");                                     //~v889R~
//    gnome_print_beginpage(Spgpcontext,NULL);                       //~v92dI~//~v970R~
//    gnome_print_setrgbcolor(Spgpcontext,1.0,1.0,1.0);              //~v92fR~//~v970R~
//    gnome_print_setopacity(Spgpcontext,1.0);                       //~v92fR~//~v970R~
  }                                                                //~v904I~
    Sopenpagesw=1;                                                 //~v844R~
    Sposy=Sposy1st;                                                //~v844R~
  if (leftpagesw)                                                  //~v904I~
  {                                                                //~v904I~
    Sposx=Sleftmargin;                                             //~v904I~
//  if (Sfontsizespecifiedsw!=1)	//no user specified size       //~v92dR~//~v970R~
//		gnome_print_scale(Spgpcontext,Sfscalex,Sfscaley);	//required for each page//~v92dR~//~v970R~
  }                                                                //~v904I~
  else                                                             //~v904I~
    Sposx=Srightpageposx;                                          //~v904R~
    UTRACEP("lnx_newpage Sposx=%lf,Sposy=%lf\n",Sposx,Sposy);      //~v970I~
    return;
}//lnx_newpage                                                     //~v951R~
//=========================================================================//~v970I~
//=at drawpage cb                                                  //~v970I~
//=========================================================================//~v970I~
void                                                               //~v970I~
lnx_newpage_flush(void)                                            //~v970I~
{                                                                  //~v970I~
    cairo_t *cr;                                                   //~v970I~
//********************************                                 //~v970I~
    UTRACEP("lnx_newpage_flush Sflushphase=%d,Srightpagepos=%d,despageno=%d,breakpage=%d,Sopenpagesw=%d\n",Sflushphase,Srightpageposx,despageno,breakpage,Sopenpagesw);//~v970I~
    cr=Spcairocontext;                                             //~v970I~
    UTRACEP("lnx_newpage_flush get_font_desc=%p\n",pango_layout_get_font_description(Splayout));//~v970I~
    pango_layout_set_font_description(Splayout,Sppangofd);          //~vamgI~//~v970I~
    pango_layout_set_font_description(SplayoutLineno,Sppangofd);   //~v970R~
    UTRACEP("lnx_newpage_flush get_font_desc font=%s,style=%d\n",pango_font_description_get_family(Sppangofd),pango_font_description_get_style(Sppangofd));//~v970I~
	lnx_setcolorGtk(Spcairocontext);                               //~v970I~
//#ifdef HHH                                                         //~v989I~//~v98aR~
//#ifdef   GTKV2200      //2.20                                      //~v989R~//~v98aR~
//    {                                                              //~v989R~//~v98aR~
//        double fx,fy;                                              //~v989R~//~v98aR~
//        fx=Sleftmargin-Shardmarginl;                               //~v989R~//~v98aR~
//        if (fx<0)                                                  //~v989R~//~v98aR~
//            fx=0;                                                  //~v989R~//~v98aR~
//        fy=Stopmargin-Shardmargint;                                //~v989R~//~v98aR~
//        if (fy<0)                                                  //~v989R~//~v98aR~
//            fy=0;                                                  //~v989R~//~v98aR~
//        cairo_translate(cr,fx,fy);                                 //~v989R~//~v98aR~
//    UTRACEP("lnx_newpage_flush cairo_translate hardl=%f,paperl=%d,hardt=%f,papert=%f\n",Shardmarginl,Sleftmargin,Shardmargint,Stopmargin);//~v989R~//~v98jR~
//    UTRACEP("lnx_newpage_flush cairo_translate x=%f,y=%f\n",fx,fy);//~v989R~//~v98aR~
//    }                                                              //~v989R~//~v98aR~
//#else                                                              //~v989R~//~v98aR~
//    cairo_translate(cr,(gdouble)Sleftmargin,(gdouble)Stopmargin);//~vam0R~//~v970I~//~v98aR~
//    UTRACEP("lnx_newpage_flush cairo_translate x=%f,y=%f\n",Sleftmargin,Stopmargin);//~v970I~//~v98jR~
//#endif                                                             //~v989R~//~v98aR~
//#else  //HHH                         //not use_full_page           //~v989R~//~v98aR~
    {                                                              //~v98aI~
    	double xorg,yorg;                                          //~v98aR~
#ifndef LLL                                                        //~v98aR~
        xorg=(double)Sleftmargin;                                  //~v98aI~
        yorg=(double)Stopmargin;                                   //~v98aI~
        xorg+=Sxshift;                                             //~v98aR~
        yorg+=Syshift;                                             //~v98aR~
	    UTRACEP("lnx_newpage_flush Sxshift=%f,Syshift=%f\n",Sxshift,Syshift);//~v98aI~
    	cairo_translate(cr,xorg,yorg);                             //~v98aR~
	    UTRACEP("lnx_newpage_flush cairo_translate x=%f,y=%f,Sleftmargin=%f,Stopmargin=%f\n",xorg,yorg,Sleftmargin,Stopmargin);//~v98jR~
#else                                                              //~v98aM~
        if (Sxshift||Syshift)                                      //~v98aR~
        {                                                          //~v98aI~
	        xorg=Sxshift;                                          //~v98aI~
        	yorg=Syshift;                                          //~v98aI~
    		cairo_translate(cr,xorg,yorg);                         //~v98aI~
		    UTRACEP("lnx_newpage_flush cairo_translate bu shift x=%f,y=%f,Sleftmargin=%f,Stopmargin=%f\n",xorg,yorg,Sleftmargin,Stopmargin);//~v98jR~
        }                                                          //~v98aI~
#endif                                                             //~v98aM~
    }                                                              //~v98aI~
//#endif                                                             //~v989I~//~v98aR~
//  if (Sfontsizespecifiedsw!=1)	//no user specified size       //~v970R~
    {                                                              //~v970R~
        cairo_scale(cr,Sfscalex,Sfscaley);                         //~v970R~
    	UTRACEP("%s:lnx_newpage_flush cairo_scale Sfscalex=%lf,Sfscaley=%lf,cr=%p\n",UTT,Sfscalex,Sfscaley,cr);//~v970R~//~v9i0R~
	}                                                              //~v970I~
}//lnx_newpage                                                     //~v970I~
#else  //!GTKPRINT                                                 //~v970I~
//=========================================================================//~v970I~
void lnx_newpage(void)                                             //~v92dR~
{
    int leftpagesw,newpagesw;                                      //~v904R~
//********************************
    if (Srightpageposx)                                            //~v904R~
    	if (despageno)      //reverse page print                   //~v904I~
        {                                                          //~v904I~
            leftpagesw=((despageno-breakpage)%2==0); //left when residual page is even//~v904R~
            newpagesw=!leftpagesw || (breakpage==1);               //~v904R~
        }                                                          //~v904I~
        else                                                       //~v904I~
            newpagesw=leftpagesw=(breakpage%2!=0);                 //~v904R~
    else                                                           //~v904I~
    	newpagesw=leftpagesw=1;                                    //~v904R~
  if (newpagesw)	//before new page start                        //~v904R~
  {                                                                //~v904I~
	if (Sopenpagesw)                                               //~v844R~
    {
		if (Gtraceopt)		//trace option by /Yt                  //~v92dR~
			printf("duplicated page open request\n");               //~v92dR~//~v970R~
    	lnx_closepage();                                           //~v92dR~
	}
	if (Gtraceopt)		//trace option by /Yt                      //~v889I~
		printf("StartPage\n");                                     //~v889R~
//  Splayout=gnome_print_pango_create_layout(Spgpcontext);         //~v92dR~
    gnome_print_beginpage(Spgpcontext,NULL);                       //~v92dI~
    gnome_print_setrgbcolor(Spgpcontext,1.0,1.0,1.0);              //~v92fR~
    gnome_print_setopacity(Spgpcontext,1.0);                       //~v92fR~
  }                                                                //~v904I~
    Sopenpagesw=1;                                                 //~v844R~
    Sposy=Sposy1st;                                                //~v844R~
  if (leftpagesw)                                                  //~v904I~
  {                                                                //~v904I~
    Sposx=Sleftmargin;                                             //~v904I~
    if (Sfontsizespecifiedsw!=1)	//no user specified size       //~v92dR~
		gnome_print_scale(Spgpcontext,Sfscalex,Sfscaley);	//required for each page//~v92dR~
    UTRACEP("setscale x=%f,y=%f\n",Sfscalex,Sfscaley);             //~v951I~
  }                                                                //~v904I~
  else                                                             //~v904I~
    Sposx=Srightpageposx;                                          //~v904R~
    return;
}//lnx_newpage                                                     //~v951R~
#endif //!GTKPRINT                                                 //~v970I~
//****************************************************************************
//close page
//****************************************************************************
#ifdef GTKPRINT                                                    //~v970I~
//=========================================================================//~v970I~
void lnx_closepage(void)                                           //~v92dR~
{
//  int rc;                                                        //~v92dI~//~v964R~
//********************************
	if (Gtraceopt)		//trace option by /Yt                      //~v976I~
		UTRACEP("lnx_closepage,openpagesw=%d\n",Sopenpagesw);                                    //~v970I~//~v976R~//~v97kR~
    UTRACEP("lnx_closepage Sflushphase=%d,Sopenpagesw=%d\n",Sflushphase,Sopenpagesw);//~v970I~
	if (!Sopenpagesw)
        return;
    desp_gtkclosepage();	//write recid=CLOSEPAGE                //~v970I~
    Sopenpagesw=0;                                                 //~v844M~
	if (Gtraceopt)		//trace option by /Yt                      //~v889I~
		UTRACEP("EndPage\n");                                       //~v889R~//~v97kR~
//    /*rc=*/gnome_print_showpage(Spgpcontext);                          //~v92dR~//~v964R~//~v970R~
    return;
}//lnx_closepage                                                   //~v92dR~
#else  //!GTKPRINT                                                 //~v970I~
//=========================================================================//~v970I~
void lnx_closepage(void)                                           //~v92dR~
{
//  int rc;                                                        //~v92dI~//~v964R~
//********************************
	if (!Sopenpagesw)
        return;
    Sopenpagesw=0;                                                 //~v844M~
	if (Gtraceopt)		//trace option by /Yt                      //~v889I~
		printf("EndPage\n");                                       //~v889R~
	/*rc=*/gnome_print_showpage(Spgpcontext);                          //~v92dR~//~v964R~
//  printf("showpage rc=%d\n",rc);                                 //~v92hR~
//    if (Splayout)                                                //~v92dR~
//    {                                                            //~v92dR~
//        g_object_unref(Splayout);                                //~v92dR~
//        Splayout=0;                                              //~v92dR~
//    }                                                            //~v92dR~
    return;
}//lnx_closepage                                                   //~v92dR~
#endif //!GTKPRINT                                                 //~v970I~
//****************************************************************************
//write line into DC
//parm1:text addr
//parm2:text len
//****************************************************************************
void lnx_putline(char *Pbuff,unsigned long Plen)                   //~v92dR~
{
    char *ptext,*pc;                                               //~v844R~
    long len;	                                                   //~v844I~
    int  lastcr;                                                   //~v844I~
#ifdef UTF8SUPP                                                    //~v928I~
//  USHORT *pucs,*pucs2;                                           //~v928R~//~v950R~
    WUCS *pucs,*pucs2;                                             //~v950I~
#endif                                                             //~v928I~
//********************************
//  if (*(ptext=Pbuff)==FORMFEED)		//form feed                //~v844R~
UTRACED("lnx_putline buff",Pbuff,(int)Plen);                            //~v955I~//~v9a0R~
    ptext=Pbuff;                                                   //~v844I~
    if (hdr0linesw)		//form feed                                //~v844R~
    {                                                              //~v844I~
    UTRACEP("NEWPAGE\n");                                          //~v951I~
        lnx_newpage();                                             //~v92dR~
    	ptext+=1-skip1stff2+esccmdlen;	//if skip 1st ff,already addr is skipped//~v844R~
//      len=Plen-1+skip1stff2-esccmdlen;                           //~v844R~//~v9a0R~
        len=(int)Plen-1+skip1stff2-esccmdlen;                      //~v9a0I~
	}                                                              //~v844I~
    else                                                           //~v844I~
//  	len=Plen;                                                  //~v844I~//~v9a0R~
    	len=(int)Plen;                                             //~v9a0I~
	if (UCBITCHK(swsw4,SW4OUTSTDO))                                //~v970M~
    {                                                              //~v970M~
//  	fwrite(ptext,1,len,stdout);                                //~v970I~//~v9a0R~
    	fwrite(ptext,1,(size_t)len,stdout);                        //~v9a0I~
    	return;                                                    //~v970M~
    }                                                              //~v970M~
#ifdef UTF8SUPP                                                    //~v928I~
//if (Gxputfstat & GXPUS_UCSLINE)	//data is unicode              //~v928R~//~v955R~
  if (Gxputfstat & (GXPUS_UCSLINE|GXPUS_UCSLINE_EBC))   //data is unicode//~v955I~
  {                                                                //~v928I~
  	if (Gxputfstat & GXPUS_UCSLINE_EBC)   //data is unicode        //~v955I~
    	len/=WUCSSZ;                                               //~v955R~
//	pucs=(USHORT*)(ULONG)ptext;                                    //~v928R~//~v950R~
  	pucs=(WUCS*)(ULONG)ptext;                                      //~v950I~
    while(len && *pucs=='\n')                                      //~v928I~
    {                                                              //~v928I~
        pucs++;                                                    //~v928I~
        len--;                                                     //~v928I~
		Sposy+=Slineheightf;                                       //~v92dR~
    }                                                              //~v928I~
    pucs2=pucs+len-1;                                              //~v928I~
    lastcr=0;                                                      //~v928I~
    while(len && *pucs2=='\n')                                     //~v928I~
    {                                                              //~v928I~
    	len--;                                                     //~v928I~
        lastcr++;                                                  //~v928I~
        pucs2--;                                                   //~v928R~
    }                                                              //~v928I~
	UTRACED("lnx_putline ucs",pucs,(int)len*2);                                    //~v928I~//~v955R~//~v9a1R~
//  lnx_textout(1,Sposx,Sposy,(char *)(ULONG)pucs,len);            //~v92dR~//~v9a1R~
    lnx_textout(1,Sposx,Sposy,(char *)(ULPTR)pucs,(int)len);       //~v9a1I~
  }                                                                //~v928I~
  else                                                             //~v928I~
  {                                                                //~v928I~
#endif                                                             //~v928I~
    while(len && *ptext=='\n')                                     //~v844I~
    {                                                              //~v844I~
        ptext++;                                                   //~v844I~
        len--;                                                     //~v844I~
		Sposy+=Slineheightf;                                       //~v92dR~
    }                                                              //~v844I~
    pc=ptext+len-1;                                                //~v844I~
    lastcr=0;                                                      //~v844I~
    while(len && *pc=='\n')                                        //~v844I~
    {                                                              //~v844I~
    	len--;                                                     //~v844I~
        lastcr++;                                                  //~v844I~
        pc--;                                                      //~v844I~
    }                                                              //~v844I~
//  lnx_textout(0,Sposx,Sposy,ptext,len);                          //~v92dR~//~v9a1R~
    lnx_textout(0,Sposx,Sposy,ptext,(int)len);                     //~v9a1I~
#ifdef UTF8SUPP                                                    //~v928I~
  }                                                                //~v928I~
#endif                                                             //~v928I~
    while(lastcr)                                                  //~v844I~
    {                                                              //~v844I~
    	lastcr--;                                                  //~v844I~
		Sposy+=Slineheightf;                                       //~v92dR~
    }                                                              //~v844I~
}//lnx_putline                                                     //~v92dR~
//**********************************************************************//~v844I~
//* cleanup at end of job                                          //~v844I~
//parm1:end type 0:normal,4:by esc key,8:err                       //~v844R~
//**********************************************************************//~v844I~
#ifdef GTKPRINT
//=========================================================================
void lnx_endjob(int Pendsw)                                        //~v92dR~
{                                                                  //~v844I~
	static int Sendrequested;                                      //~v844R~
//********************************                                 //~v844I~
	UTRACEP("lnx_endjob Sopendocsw=%d\n",Sopendocsw);                                       //~v970I~//~v97kR~//~v97hR~
	if (UCBITCHK(swsw4,SW4OUTSTDO))                                //~v970I~
    	return;                                                    //~v970I~
	if (Gtraceopt)		//trace option by /Yt                      //~v889I~
		printf("endjob sw=%d\n",Pendsw);                           //~v889R~
	if (Sendrequested)	//loop detection                           //~v844I~
    	return;                                                    //~v844I~
	Sendrequested=1;	//loop detection                           //~v844I~
	Sendjobsw=Pendsw;                                              //~v844I~
//    if (!Spgpjob)                                                  //~v92dR~//~v970R~
//        return;                                                    //~v844I~//~v970R~
	lnx_closepage();                                               //~v92dR~
	if (Sopendocsw)                                                //~v844I~
		lnx_closedoc();                                            //~v92dR~
//    Spgpjob=0;                                                     //~v92dR~//~v970R~
	return;                                                        //~v844I~
}//lnx_endjob                                                      //~v92dR~
#else  //!GTKPRINT
//=========================================================================
void lnx_endjob(int Pendsw)                                        //~v92dR~
{                                                                  //~v844I~
	static int Sendrequested;                                      //~v844R~
//********************************                                 //~v844I~
	if (Gtraceopt)		//trace option by /Yt                      //~v889I~
		printf("endjob sw=%d\n",Pendsw);                           //~v889R~
	if (Sendrequested)	//loop detection                           //~v844I~
    	return;                                                    //~v844I~
	Sendrequested=1;	//loop detection                           //~v844I~
	Sendjobsw=Pendsw;                                              //~v844I~
	if (!Spgpjob)                                                  //~v92dR~
    	return;                                                    //~v844I~
	lnx_closepage();                                               //~v92dR~
	if (Sopendocsw)                                                //~v844I~
		lnx_closedoc();                                            //~v92dR~
	Spgpjob=0;                                                     //~v92dR~
	return;                                                        //~v844I~
}//lnx_endjob                                                      //~v92dR~
#endif //!GTKPRINT
//***************************************************************************//~v92dM~
//* printer text write                                             //~v92dM~
//***************************************************************************//~v92dM~
#ifdef GTKPRINT                                                    //~v970I~
//=========================================================================//~v970I~
void lnx_textout(int Popt,gdouble Pposx,gdouble Pposy,char *Pdata,int Plen)//~v92dR~
{                                                                  //~v92dM~
//    GnomeGlyphList *pgl;                                           //~v92dM~//~v970R~
//    GnomeFont *pfont;                                              //~v92dM~//~v970R~
    gdouble yy,xx;                                                 //~v92dR~
    gchar *putf80;                                                 //~v92dM~
    int writelen;                                                  //~v92dR~
	int utfrc=0;                                                //~v966R~//~v970R~
    int flag=0;                                                    //~v970I~
//    static int print_color=0x202020ff;                             //~v92hR~//~v970R~
//*******************************                                  //~v92dM~
    UTRACEP("lnx_textout opt=%x,x=%lf y=%lf len=%d,scalex=%lf,scaley=%lf\n",Popt,Pposx,Pposy,Plen,Sfscalex,Sfscaley);//~v951R~//~v970R~
    UTRACED("lnx_textout",Pdata,Plen);                             //~v951I~
	if (!Plen)                                                     //~v92dM~
    	return;                                                    //~v92dM~
    if (Popt & 0x01) 	//data is ucs2                             //~v92dM~
    {                                                              //~v92dI~
    	lnx_ucs2utf8((WUCS*)(ULONG)Pdata,Plen,&putf80,&writelen);  //~v950I~
    }                                                              //~v92dI~
    else                                                           //~v92dM~
    if ((Gxpotheropt &  GOO_FILENAMEHDR) && (Gxpotheropt & GOO_HEADERUCS))//~v97mI~
    {                                                              //~v97mI~
        UTRACED("lnx_textout hdrucs",header0ucs,header0ucsctr*(int)sizeof(WUCS));//~v97mI~//~v9a0R~
    	lnx_ucs2utf8(header0ucs,header0ucsctr,&putf80,&writelen);  //~v97mR~
        utfrc=1;    //dont free                                    //~v97mI~
    	flag|=GTKTOF_HDR0;                                         //~v97mI~
    }                                                              //~v97mI~
    else                                                           //~v97mI~
    if ((Gxpotheropt &  GOO_FILENAMESUBHDR) && (Gxpotheropt & GOO_HEADERUCS))//~v97mI~
    {                                                              //~v97mI~
        UTRACED("lnx_textout hdrucs",headersucs,headersucsctr*(int)sizeof(WUCS));//~v97mI~//~v9a0R~
    	lnx_ucs2utf8(headersucs,headersucsctr,&putf80,&writelen);  //~v97mI~
        utfrc=1;    //dont free                                    //~v97mI~
    	flag|=GTKTOF_SUBHDR;                                       //~v97mI~
    }                                                              //~v97mI~
    else                                                           //~v97mI~
    {                                                              //~v92dI~
	    utfrc=lnx_locale2utf8(Pdata,Plen,0,&putf80,&writelen);     //~v92dI~
    	if (utfrc>1)                                               //~v92dR~
    		return;                                                //~v92dR~
    }                                                              //~v92dI~
//printf("uprttextout utf8len=%d\n",utf8len);                      //~v92dR~
//    	xx=(gdouble)Pposx/Sfscalex;                                //~v92dR~//~v970R~
    xx=(gdouble)(Pposx-Sleftmargin);		//apply scale at 2printer by cairo_scale//~v970R~
//      yy=(gdouble)(Spageheight-Pposy-Sfontascendant)/Sfscaley;//font baseline pos from origin(set at vieportfile)//~v92dR~//~v970R~
    yy=(gdouble)(Pposy-Stopmargin);	//cairo origin is top-left,baseline is adjusted by cairo//~v970R~
    if (Pdata==header1||Pdata==(header1+LINENOSZ+1))               //~v970R~//~v975R~
    	flag|=GTKTOF_MONOSPACE;                                    //~v970I~
    if (Pdata==Hexline1||Pdata==Hexline2)                          //~v97pI~
    	flag|=GTKTOF_MONOSPACE;                                    //~v97pI~
    if (Gxpotheropt & GOO_MONOSPACELINE)  //by printsubhdr         //~v97hI~
    	flag|=GTKTOF_MONOSPACE;                                    //~v97hI~
    if (Gxpotheropt & GOO_HHEXLINE)                                //~v97pI~
    	flag|=GTKTOF_HHEX;                                         //~v97pI~
    UTRACEP("lnx_textout Gxpotheropt=%x,xx=%f,yy=%f\n",Gxpotheropt,xx,yy);//~v989R~
    desp_gtktextout(flag,xx,yy,putf80,writelen);	//save to work //~v970R~
    if (!(Popt & 0x01)) 	//data is ucs2                         //~v92dR~
		if (!utfrc)                                                //~v92dR~
    		g_free(putf80);                                        //~v92dR~
}//lnx_textout                                                     //~v970I~
#ifdef AAA                                                         //~v97pI~
void setattr(PangoLayout *Pplayout)	                               //~v97pR~
{                                                                  //~v970I~
    PangoAttribute *ppa;                                           //~vXXEI~//~v970I~
    PangoAttrList  *ppal;                                          //~vXXER~//~v970I~
    int fontsize;                                                  //~v970I~
//**********************                                           //~v970I~
	fontsize=10*1024;                                              //~v970I~
    ppa=pango_attr_size_new(fontsize);                             //~vXXER~//~v970I~
    ppa->start_index=0;         //start byte offset                //~vXXEI~//~v970I~
    ppa->end_index=G_MAXINT;    //end                              //~vXXEI~//~v970I~
    ppal=pango_attr_list_new();                                    //~vXXEI~//~v970I~
    pango_attr_list_insert(ppal,ppa);                              //~vXXER~//~v970I~
    pango_layout_set_attributes(Pplayout,ppal);                    //~v970I~
                                                                   //~v970I~
}                                                                  //~v970I~
#endif                                                             //~v97pI~
//*********************************************************************//~v97pI~
//*monospace for hhex dump part                                    //~v97pI~
//*********************************************************************//~v97pI~
void lnx_drawhhexpart(cairo_t *Pctxt,char *Pputf8,int Pu8len,int *Pppos,double *Ppxx,double Pyy,int *Ppreslen)//~v97pR~
{                                                                  //~v97pI~
	int pos,reslen,len;                                            //~v97pR~
    double xx;                                                     //~v97pR~
	cairo_t *cr;                                                   //~v97pI~
//***********************************                              //~v97pI~
	cr=Pctxt;                                                      //~v97pI~
    pos=*Pppos;                                                    //~v97pI~
    xx=*Ppxx;                                                      //~v97pI~
	UTRACEP("drawhhexpart Linecharpos=%d,pos=%dxx=%lf\n",Linecharpos,pos,xx);//~v97pR~
    len=Linecharpos-pos;                                           //~v97pI~
    if (len>0)                                                     //~v97pI~
    {                                                              //~v97pI~
        pango_layout_set_text(Splayout,Pputf8+pos,len);            //~v97pI~
		usetmonospace(0,Splayout,Scharwidthf_scaled);              //~v97pI~
	    pango_cairo_show_layout(cr,Splayout);                      //~v97pI~
		xx=xx+len*Scharwidthf_scaled;                              //~v97pI~
        UTRACEP("lnx_drawhhexpart move len=%d,Scharwidthf_scaled=%lf,xx=%lf,yy=%lf\n",len,Scharwidthf_scaled,xx,Pyy);//~v97pI~
	    cairo_move_to(cr,xx,Pyy);                                  //~v97pI~
        pos+=len;                                                  //~v97pI~
        reslen=max(Pu8len-Linecharpos,0);                          //~v97pI~
    }                                                              //~v97pI~
    else                                                           //~v97pI~
    	reslen=0;                                                  //~v97pI~
    *Ppxx=xx;                                                      //~v97pI~
    *Pppos=pos;                                                    //~v97pI~
    *Ppreslen=reslen;                                              //~v97pI~
	UTRACEP("textout2printer hhex pos=%d,reslen=%d,xx=%lf\n",pos,reslen,xx);//~v97pI~
}//lnx_drawhexpart                                                 //~v97pR~
//*********************************************************************//~v970I~
//*from desp at flush                                              //~v970I~
//*********************************************************************//~v970I~
void lnx_textout2printer(int Pflag,double Pxx,double Pyy,char *Pputf80,int Pwrite)//~v970R~
{                                                                  //~v970I~
	cairo_t *cr;                                                   //~v970R~
    int len,swmonospace,swhhex,pos,reslen;                                           //~v970R~//~v975R~//~v97pR~
    double flinewidth,xx;                                             //~v970I~//~v97pR~
    int swhdr0=0;                                                  //~v97mI~
    char *pc;                                                      //~v97pI~
//*******************************                                  //~v970I~
	UTRACEP("%s:flag=%x,Pwrite=%d\n",UTT,Pflag,Pwrite);                //~v970R~    //~v9i0R~//~v9j1R~
//    pango_layout_set_font_description(Splayout,Sppangofd);//@@@@test//~v970R~
	cr=Spcairocontext;                                             //~v970M~
//	    pfont=Spgfont;                                             //~v92dR~//~v970R~
//      rc=gnome_print_moveto(Spgpcontext,xx,yy);                  //~v92dR~//~v970R~
        UTRACEP("lnx_textout2printer move xx=%lf,yy=%lf\n",Pxx,Pyy);//~v97pR~
        cairo_move_to(cr,Pxx,Pyy);                                 //~v970R~
UTRACEP("lnx_textout2printer pgheight=%d,Sfontascendant=%lf,scaley=%lf\n",Spageheight,Sfontascendant,Sfscaley);//~v970R~
UTRACEP("lnx_textout2printer moveto xx=%lf,yy=%lf\n",Pxx,Pyy);//~v951I~//~v970R~
//      pgl=gnome_glyphlist_from_text_sized_dumb(pfont,Gprint_color,0.0,0.0,putf80,writelen);//kerning=letterspace=0//~v92hR~//~v970R~
UTRACED("lnx_textout2printer",Pputf80,Pwrite);                     //~v970R~
//      gnome_glyphlist_advance (pgl,TRUE);//move pen by cellszw   //~v92dR~//~v970R~
//      rc=gnome_print_glyphlist(Spgpcontext,pgl);                 //~v92dR~//~v970R~
//      printf("print glyphlist rc=%d\n",rc);                      //~v92dR~
//      gnome_glyphlist_unref(pgl);                                //~v92dM~//~v970R~
//  	setattr(Splayout);  //@@@@test                             //~v970I~
	swmonospace=Pflag & GTKTOF_MONOSPACE;                          //~v970I~
	swhhex=(Pflag & GTKTOF_HHEX);                                  //~v97pR~
	if (lineprefixsw && (Pflag & GTKTOF_HDR0))                     //~v97mR~
    {                                                              //~v97mI~
        len=min(LINENOSZ+1,Pwrite);                                //~v97mI~
//      if (umemspnc(Pputf80,' ',len)<len)                         //~v97mI~//~v9a0R~
//      if (umemspnc(Pputf80,' ',(size_t)len)<len)                 //~v9a0I~//~v9a1R~
        if (umemspnc(Pputf80,' ',(unsigned)len)<len)               //~v9a1I~
        	swhdr0=1;                                              //~v97mI~
    }                                                              //~v97mI~
    UTRACEP("textout2printer monospaceline=%d\n",swmonospace);     //~v975I~
//  swmonospace=1;//@@@@test                                       //~v970R~
    UTRACEP("%s:lineprefixsw=%d,swhdr0=%d,swhhex=%d,Scharwidthf_scaled=%lf\n",UTT,lineprefixsw,swhdr0,swhhex,Scharwidthf_scaled);//~v9i0R~//+v9j4R~
//  if (lineprefixsw)                                              //~v970R~//~v97mR~
    if (lineprefixsw && !swhdr0)                                   //~v97mI~
    {                                                              //~v970I~
		len=LINENOSZ+1;                                            //~v970I~
        UTRACED("Prefix and Not hdr lineno",Pputf80,len);          //~v9j1I~
        pango_layout_set_text(SplayoutLineno,Pputf80,len);         //~v970R~
		usetmonospace(0,SplayoutLineno,Scharwidthf_scaled);        //~v970R~
//		chklayoutextent(SplayoutLineno,NULL);//@@@@test                 //~v970R~//~v975R~//~v97pR~
        pango_cairo_show_layout(cr,SplayoutLineno);                //~v970R~
                                                                   //~v970I~
	    flinewidth=len*Scharwidthf_scaled;                         //~v970R~
        UTRACEP("lnx_textout2printer move xx=%lf,yy=%lf\n",Pxx+flinewidth,Pyy);//~v97pI~
        cairo_move_to(cr,Pxx+flinewidth,Pyy);                      //~v970R~
      if (swhhex)                                                  //~v97pI~
      {                                                            //~v97pI~
      	pos=len;                                                   //~v97pI~
        xx=Pxx+flinewidth;                                         //~v97pI~
		lnx_drawhhexpart(cr,Pputf80,Pwrite,&pos,&xx,Pyy,&reslen);  //~v97pR~
        if (reslen>0)                                              //~v97pI~
        {                                                          //~v97pI~
        	pc=Pputf80+Pwrite-reslen;                              //~v97pI~
        	pango_layout_set_text(Splayout,pc,reslen);             //~v97pR~
            UTRACED("2printer hhex charpart",pc,reslen);           //~v97pI~
			if (swmonospace||isallascii(pc,reslen))                //~v97pR~
            {                                                      //~v97pI~
				usetmonospace(0,Splayout,Scharwidthf_scaled);      //~v97pI~
            }                                                      //~v97pI~
	        lnx_showlayout(cr,Splayout,pc,reslen,Slinewidthf-Scharwidthf*(Pwrite-reslen));//~v97pR~
        }                                                          //~v97pI~
      }                                                            //~v97pI~
      else                                                         //~v97pI~
      {                                                            //~v97pI~
        UTRACED("Prefix and Not hdr data",Pputf80+len,Pwrite-len);          //~v9i0I~//~v9j1R~
        pango_layout_set_text(Splayout,Pputf80+len,Pwrite-len);    //~v970M~
		if (swmonospace)                                           //~v970R~
			usetmonospace(0,Splayout,Scharwidthf_scaled);          //~v970R~
        lnx_showlayout(cr,Splayout,Pputf80+len,Pwrite-len,Slinewidthf-Scharwidthf*len);//~v975R~//~v970R~
      }                                                            //~v97pI~
	}                                                              //~v970I~
    else                                                           //~v970I~
    {                                                              //~v970I~
      if (swhhex)                                                  //~v97pI~
      {                                                            //~v97pI~
      	pos=0;                                                     //~v97pI~
        xx=Pxx;                                                    //~v97pI~
		lnx_drawhhexpart(cr,Pputf80,Pwrite,&pos,&xx,Pyy,&reslen);  //~v97pR~
        if (reslen>0)                                              //~v97pI~
        {                                                          //~v97pI~
        	pc=Pputf80+Pwrite-reslen;                              //~v97pI~
        	UTRACED("NoPrefix or hdr hhex",pc,reslen);             //~v9i0I~
        	pango_layout_set_text(Splayout,pc,reslen);             //~v97pR~
			if (swmonospace||isallascii(pc,reslen))                //~v97pR~
				usetmonospace(0,Splayout,Scharwidthf_scaled);      //~v97pI~
	        lnx_showlayout(cr,Splayout,pc,reslen,Slinewidthf-Scharwidthf*(Pwrite-reslen));//~v97pR~
        }                                                          //~v97pI~
      }                                                            //~v97pI~
      else                                                         //~v97pI~
      {                                                            //~v97pI~
        UTRACED("NoPrefix or hdr",Pputf80,Pwrite);                 //~v9i0R~
        pango_layout_set_text(Splayout,Pputf80,Pwrite);            //~v970R~
		if (swmonospace)                                          //~v970I~//~v975R~
			usetmonospace(0,Splayout,Scharwidthf);                 //~v970I~
        lnx_showlayout(cr,Splayout,Pputf80,Pwrite,Slinewidthf);    //~v975R~
      }                                                            //~v97pI~
    }                                                              //~v970I~
    return;                                                        //~v92dM~
}//lnx_textout2printer                                             //~v97mR~
#else  //!GTKPRINT                                                 //~v970I~
//=========================================================================//~v970I~
void lnx_textout(int Popt,gdouble Pposx,gdouble Pposy,char *Pdata,int Plen)//~v92dR~
{                                                                  //~v92dM~
    GnomeGlyphList *pgl;                                           //~v92dM~
    GnomeFont *pfont;                                              //~v92dM~
    gdouble yy,xx;                                                 //~v92dR~
    gchar *putf80;                                                 //~v92dM~
    int writelen;                                                  //~v92dR~
	int utfrc=0,rc;                                                //~v966R~
#ifdef AAA                                                         //~v92dI~
    gint glyph;                                                    //~v92dM~
    int ii;                                                        //~v92dI~
    gunichar ch;                                                   //~v92dM~
    char *putf8,*pc,*putf8next,*pdbcs;                             //~v92dI~
    gdouble dx;                                                    //~v92dI~
#endif                                                             //~v92dI~
//  static int Slinenodbg;                                         //~v963R~
#ifndef BBB                                                        //~v92hR~
#else                                                              //~v92hI~
    static int print_color=0x202020ff;                             //~v92hR~
#endif                                                             //~v92hI~
//*******************************                                  //~v92dM~
//  printf("textout opt=%x,x=%d y=%d len=%d\n",Popt,Pposx,Pposy,Plen);//~v92dR~
    UTRACEP("lnx_textout opt=%x,x=%lf y=%lf len=%d\n",Popt,Pposx,Pposy,Plen);//~v951R~
    UTRACED("lnx_textout",Pdata,Plen);                             //~v951I~
	if (!Plen)                                                     //~v92dM~
    	return;                                                    //~v92dM~
#ifdef UTF8SUPP                                                    //~v92hI~
    if (Popt & 0x01) 	//data is ucs2                             //~v92dM~
    {                                                              //~v92dI~
//  	lnx_ucs2utf8((USHORT*)(ULONG)Pdata,Plen,&putf80,&writelen);//~v92dR~//~v950R~
    	lnx_ucs2utf8((WUCS*)(ULONG)Pdata,Plen,&putf80,&writelen);  //~v950I~
//      utf8len=Plen;                                              //~v92dR~
    }                                                              //~v92dI~
    else                                                           //~v92dM~
    {                                                              //~v92dI~
#endif                                                             //~v92hI~
	    utfrc=lnx_locale2utf8(Pdata,Plen,0,&putf80,&writelen);     //~v92dI~
    	if (utfrc>1)                                               //~v92dR~
    		return;                                                //~v92dR~
//  	utf8len=g_utf8_strlen(putf80,writelen);                    //~v92dR~
#ifdef UTF8SUPP                                                    //~v92hI~
    }                                                              //~v92dI~
#endif                                                             //~v92hI~
//printf("uprttextout utf8len=%d\n",utf8len);                      //~v92dR~
    	xx=(gdouble)Pposx/Sfscalex;                                //~v92dR~
//      yy=(gdouble)(-Pposy-Sfontascendant);//(Mprtrect.top-Pposy);//font baseline pos from origin(set at vieportfile)//~v92dR~
        yy=(gdouble)(Spageheight-Pposy-Sfontascendant)/Sfscaley;//font baseline pos from origin(set at vieportfile)//~v92dR~
	    pfont=Spgfont;                                             //~v92dR~
        rc=gnome_print_moveto(Spgpcontext,xx,yy);                  //~v92dR~
//printf("moveto rc=%d,xx=%lf,yy=%lf color=%x\n",rc,xx,yy,Gprint_color);//~v92hR~
UTRACEP("pgheight=%d,Sfontascendant=%lf,scaley=%lf\n",Spageheight,Sfontascendant,Sfscaley);//~v951I~
UTRACEP("moveto rc=%d,xx=%lf,yy=%lf color=%x\n",rc,xx,yy,Gprint_color);//~v951I~
#ifndef BBB                                                        //~v92hR~
        pgl=gnome_glyphlist_from_text_sized_dumb(pfont,Gprint_color,0.0,0.0,putf80,writelen);//kerning=letterspace=0//~v92hR~
#else                                                              //~v92hI~
        pgl=gnome_glyphlist_from_text_sized_dumb(pfont,print_color,0.0,0.0,putf80,writelen);//kerning=letterspace=0//~v92hI~
//printf("moveto rc=%d,xx=%lf,yy=%lf color=%x\n",rc,xx,yy,print_color);//~v92hR~
//		print_color+=0x01010100;                                   //~v92hR~
#endif                                                             //~v92hI~
//UTRACEP("lineno=%d\n",++Slinenodbg);                             //~v963R~
UTRACED("textdumb",putf80,writelen);                               //~v951I~
        gnome_glyphlist_advance (pgl,TRUE);//move pen by cellszw   //~v92dR~
        rc=gnome_print_glyphlist(Spgpcontext,pgl);                 //~v92dR~
//      printf("print glyphlist rc=%d\n",rc);                      //~v92dR~
        gnome_glyphlist_unref(pgl);                                //~v92dM~
//      if (Pposy>Sposy1st+10 && Pposy<Sposy1st+60)                 //test//~v92dR~
//        	lnx_lineout(xx,yy,xx+150,yy);                          //~v92dR~
//printf("prttext last=(%d,%d)-->(%lf,%lf) dx=%d\n",Pposx,Pposy,xx,yy,Scharwidth);//~v92dR~
    if (!(Popt & 0x01)) 	//data is ucs2                         //~v92dR~
		if (!utfrc)                                                //~v92dR~
    		g_free(putf80);                                        //~v92dR~
    rc=rc;	//for compilerwarning:unused-but-set                   //~v964I~
    return;                                                        //~v92dM~
}//lnx_prttextout                                                  //~v92dI~
#endif //!GTKPRINT                                                 //~v970I~
//***************************************************************************//~v92dI~
//* draw line   (NotUsed)                                                   //~v92dI~//~v975R~
//***************************************************************************//~v92dI~
#ifdef GTKPRINT                                                    //~v970I~
//=========================================================================//~v970I~
void lnx_lineout(gdouble Pposx0,gdouble Pposy0,gdouble Pposx1,gdouble Pposy1)//~v92dI~
{                                                                  //~v970I~
	UTRACEP("lnx_lineout x0=%lf,y0=%lf,x1=%lf,y1=%lf\n",Pposx0,Pposy0,Pposx1,Pposy1);//~v970I~
	desp_gtklineout(Pposx0,Pposy0,Pposx1,Pposy1);                  //~v970I~
}                                                                  //~v970I~
//=========================================================================//~v970I~
void lnx_lineout2printer(double Pposx0,double Pposy0,double Pposx1,double Pposy1)//~v970R~
{                                                                  //~v92dI~
	cairo_t *cr;                                                   //~v970I~
//*******************************                                  //~v92dI~
	UTRACEP("lnx_gtklineout x0=%lf,y0=%lf,x1=%lf,y1=%lf\n",Pposx0,Pposy0,Pposx1,Pposy1);//~v970I~
//  gnome_print_line_stroked(Spgpcontext,Pposx0,Pposy0,Pposx1,Pposy1);//~v92dR~//~v970R~
	cr=Spcairocontext;                                             //~v970R~
    cairo_set_source_rgb(cr,0.0,0.0,0.0);	//black                //~v970I~
    cairo_set_line_width(cr,1);	                                   //~v970I~
    cairo_move_to(cr,Pposx0,Pposy0);                               //~v970I~
    cairo_line_to(cr,Pposx1,Pposy1);                               //~v970I~
    cairo_stroke(cr);                                              //~v970I~
    UTRACEP("%s:lnx_lineout parm=%lf,%lf-->%lf,%lf,cr=%p\n",UTT,Pposx0,Pposy0,Pposx1,Pposy1,cr);//~v92hR~//~v970R~//~v9i0R~
    return;                                                        //~v92dI~
}//lnx_lineout2printr                                              //~v970R~
#else  //!GTKPRINT                                                 //~v970I~
//=========================================================================//~v970I~
void lnx_lineout(gdouble Pposx0,gdouble Pposy0,gdouble Pposx1,gdouble Pposy1)//~v92dI~
{                                                                  //~v92dI~
//*******************************                                  //~v92dI~
    gnome_print_line_stroked(Spgpcontext,Pposx0,Pposy0,Pposx1,Pposy1);//~v92dR~
//	printf("linedraw parm=%lf,%lf-->%lf,%lf\n",Pposx0,Pposy0,Pposx1,Pposy1);//~v92hR~
    return;                                                        //~v92dI~
}//lnx_lineout                                                     //~v92dI~
#endif //!GTKPRINT                                                 //~v970I~
//************************************************************     //~v92dI~
//*rc:4 err,1:ascii(0x00-0x7f) only)dont free utf8 buff)           //~v92dI~
//************************************************************     //~v92dI~
int lnx_locale2utf8(char *Ptext,int Plen,int *Ppreadlen,char **Pputf8,int *Ppwritelen)//~v92dI~
{                                                                  //~v92dI~
#define INVALIDCH '?'                                              //~v92dI~
#define MAXUTF8CHSZ 6                                              //~v92dI~
static char *Sbuff=0;                                              //~v92dI~
static int   Sbufflen=0;                                           //~v92dI~
    gchar *putf8;                                                  //~v92dI~
	UCHAR *pc,*pc2,*pcout;                                         //~v92dR~
	const gchar *pcinvalid;                                        //~v92dI~
//  int readlen,writelen;                                          //~v92vR~
    gsize readlen,writelen;                                        //~v92vI~
    GError *perr;/*=NULL*/                                         //~v92dI~
    int len,reslen,ch,utflen;                                      //~v92dI~
//****************************                                     //~v92dI~
UTRACED("locale2utf8 in",Ptext,Plen);                              //~v92dI~
  if (!Sisutf8)    //current is not utf8                           //~v92dI~
  {                                                                //~v92dI~
    if (Sconverterdescriptor==(GIConv)-1) //no converter           //~v92dI~
        ;                                                          //~v92dI~
    else             	//no conversion                            //~v92dI~
    if (Sconverterdescriptor==0)                                   //~v92dI~
        lnx_utf8init();                                            //~v92dR~
  }                                                                //~v92dI~
	if (Plen>Sbufflen)                                             //~v92dI~
    {                                                              //~v92dI~
    	if (Sbuff)                                                 //~v92dI~
        	free(Sbuff);                                           //~v92dI~
        Sbufflen=0;                                                //~v92dI~
//      Sbuff=malloc(Plen*MAXUTF8CHSZ+1);	//6:max utfcode size   //~v92dI~//~v9a0R~
        Sbuff=malloc((size_t)Plen*MAXUTF8CHSZ+1);	//6:max utfcode size//~v9a0I~
        if (Sbuff)                                                 //~v92dI~
	        Sbufflen=Plen;                                         //~v92dI~
    }                                                              //~v92dI~
    if (!Sbuff)                                                    //~v92dI~
    	return 4;                                                  //~v92dI~
	for (pc=Ptext,pcout=Sbuff,reslen=Plen;reslen>0;)               //~v92dI~
    {                                                              //~v92dI~
        ch=*pc;                                                    //~v92dI~
        if (!ch)                                                   //~v92dI~
        {                                                          //~v92dI~
            *pcout++=' ';                                          //~v92dI~
            pc++;                                                  //~v92dI~
            reslen--;                                              //~v92dI~
            continue;                                              //~v92dI~
        }                                                          //~v92dI~
        if (ch<0x20)    //ctlch                                    //~v92dI~
        {                                                          //~v92dI~
#ifdef AAA                                                         //~v92dI~
        	if ((plinech=Sacsmap[(UINT)(*pc)]))	//line drawing char defined//~v92dI~
            {                                                      //~v92dI~
                linechlen=Sacslentb[(int)(*pc)];                   //~v92dI~
                memcpy(pcout,plinech,linechlen);                   //~v92dI~
                pcout+=linechlen;                                  //~v92dI~
            }                                                      //~v92dI~
            else                                                   //~v92dI~
#endif                                                             //~v92dI~
//            	*pcout++=ch;	//no conversion                    //~v92dI~//~v9a0R~
              	*pcout++=(UCHAR)ch;	//no conversion                //~v9a0I~
            pc++;                                                  //~v92dI~
            reslen--;                                              //~v92dI~
            continue;                                              //~v92dI~
        }//linech defined                                          //~v92dI~
        if (ch<0x80)    //ascii;                                   //~v92dI~
        {                                                          //~v92dI~
//          *pcout++=ch;                                           //~v92dI~//~v9a0R~
            *pcout++=(UCHAR)ch;                                    //~v9a0I~
            pc++;                                                  //~v92dI~
            reslen--;                                              //~v92dI~
            continue;                                              //~v92dI~
        }                                                          //~v92dI~
//**  >=0x80                                                       //~v92dI~
        for (pc2=pc,len=0;len<reslen;len++,pc2++) //search next ascii//~v92dI~
        {                                                          //~v92dI~
            if (*pc2<0x80)                                         //~v92dI~
                break;                                             //~v92dI~
        }                                                          //~v92dI~
        utflen=len;                                                //~v92dI~
        if (Sisutf8)    //current is utf8                          //~v92dI~
        {                                                          //~v92dI~
UTRACED("noconv",pc,len);                                          //~v92dI~
            if (!g_utf8_validate(pc,len,&pcinvalid))    //invalid exist//~v92dI~
//              len=(ULONG)pcinvalid-(ULONG)pc;                    //~v92dI~//~v9a0R~
                len=PTRDIFF(pcinvalid,pc);                         //~v9a0I~
UTRACEP("noconv out len=%d pc=%p,invaplid=%p\n",len,pc,pcinvalid); //~v92dI~
//          memcpy(pcout,pc,len);                                  //~v92dI~//~v9a0R~
            memcpy(pcout,pc,(size_t)len);                          //~v9a0I~
            pcout+=len;                                            //~v92dI~
            reslen-=len;                                           //~v92dI~
            pc+=len;                                               //~v92dI~
            utflen-=len;                                           //~v92dI~
        }                                                          //~v92dI~
        else        //current is not utf8                          //~v92dI~
            if (Sconverterdescriptor!=(GIConv)-1) //converter exist//~v92dI~
            {                                                      //~v92dI~
                perr=NULL;                                         //~v92dI~
UTRACED("conv input",pc,len);                                      //~v92hI~
                putf8=g_convert_with_iconv(pc,len,Sconverterdescriptor,&readlen,&writelen,&perr);//~v92dI~
              if (perr)                                            //~v92mI~
              {                                                    //~v92mI~
               if (!Gl2uconverr)                                   //~v92mR~
               {                                                   //~v92mI~
                PRINTGERR("g_locale_to_utf8",perr);                //~v92nR~
                if (UTF8CHARLEN(*pc))   //valid utf8 top byte      //~v92mR~
                	uerrmsg("locale to utf8 conversion failed; %cMu option required for utf8 file.",0,//~v92mR~//~v97pR~
						CMDFLAG_PREFIX);                           //~v92mI~
                else                                               //~v92mI~
                	uerrmsg("locale to utf8 conversion failed;(warning issued only once)",0);//~v92mI~
               }                                                   //~v92mI~
                Gl2uconverr++;                                     //~v92mR~
              }                                                    //~v92mI~
UTRACEP("iconv out putf8=%p len=%d,readlen=%d,writelen=%d\n",putf8,len,readlen,writelen);//~v92dI~
                if (putf8)                                         //~v92dI~
                {                                                  //~v92dI~
                    memcpy(pcout,putf8,writelen);                  //~v92dI~
                    g_free(putf8);                                 //~v92dI~
UTRACED("iconv out",pcout,(int)writelen);                               //~v92dI~//~v9a0R~
                    pc+=readlen;                                   //~v92dI~
//                  reslen-=readlen;                               //~v92dI~//~v9a0R~
                    reslen-=(int)readlen;                          //~v9a0I~
                    pcout+=writelen;                               //~v92dI~
//                  utflen-=readlen;                               //~v92dI~//~v9a0R~
                    utflen-=(int)readlen;                          //~v9a0I~
                }                                                  //~v92dI~
            }//converter exist                                     //~v92dI~
        if (utflen) // >0x80 invalid utf or no converter           //~v92dI~
        {                                                          //~v92dI~
#ifdef AAA                                                         //~v92dI~
            if ((plinech=Sacsmap[(UINT)(*pc)]))  //line drawing char defined//~v92dI~
            {                                                      //~v92dI~
                linechlen=Sacslentb[(int)(*pc)];                   //~v92dI~
                memcpy(pcout,plinech,linechlen);                   //~v92dI~
                pcout+=linechlen;                                  //~v92dI~
            }                                                      //~v92dI~
            else                                                   //~v92dI~
                *pcout++=INVALIDCH;                                //~v92dI~
#endif                                                             //~v92dI~
            pc++;                                                  //~v92dI~
            reslen--;                                              //~v92dI~
        }                                                          //~v92dI~
    }//reslen                                                      //~v92dI~
    *pcout=0;                                                      //~v92dI~
    *Pputf8=Sbuff;                                                 //~v92dI~
    if (Ppreadlen)                                                 //~v92dI~
    	*Ppreadlen=Plen;                                           //~v92dI~
	writelen=(ULONG)pcout-(ULONG)Sbuff;                            //~v92dI~
    if (Ppwritelen)                                                //~v92dI~
//  	*Ppwritelen=writelen;                                      //~v92dI~//~v9a0R~
    	*Ppwritelen=(int)writelen;                                 //~v9a0I~
UTRACED("locale2utf8 out",Sbuff,(int)writelen);                         //~v92dI~//~v9a0R~
    return 1;       //no not free output addr                      //~v92dI~
}//lnx_locale2utf8                                                 //~v92dI~
#ifdef UTF8SUPP                                                    //~v92hI~
//************************************************************     //~v92dI~
//*rc:4 err,1:ascii(0x00-0x7f) only)dont free utf8 buff)           //~v92dI~
//************************************************************     //~v92dI~
//int lnx_ucs2utf8(USHORT *Ppucs,int Plen,char **Pputf8,int *Ppwritelen)//~v92dR~//~v950R~
int lnx_ucs2utf8(WUCS *Ppucs,int Plen,char **Pputf8,int *Ppwritelen)//~v950I~
{                                                                  //~v92dI~
static char *Sbuffutf=0;                                           //~v92dI~
static int   Sbufflenutf=0;                                        //~v92dI~
	UCHAR *pcout;                                                  //~v92dR~
    int len,ii;                                                    //~v92dR~
//  USHORT *pucs;                                                  //~v92dI~//~v950R~
    WUCS *pucs;                                                    //~v950I~
//****************************                                     //~v92dI~
UTRACED("ucs2utf8 in",Ppucs,Plen*(int)sizeof(WUCS));                               //~v92dI~//~v97mR~//~v9a0R~
	if (Plen>Sbufflenutf)                                          //~v92dI~
    {                                                              //~v92dI~
    	if (Sbuffutf)                                              //~v92dI~
        	free(Sbuffutf);                                        //~v92dI~
        Sbufflenutf=0;                                             //~v92dI~
//      Sbuffutf=malloc(Plen*UTF8_MAXCHARSZ+1);	//6:max utfcode size//~v92dI~//~v9a0R~
        Sbuffutf=malloc((size_t)Plen*UTF8_MAXCHARSZ+1);	//6:max utfcode size//~v9a0I~
        if (Sbuffutf)                                              //~v92dI~
	        Sbufflenutf=Plen;                                      //~v92dI~
    }                                                              //~v92dI~
    if (!Sbuffutf)                                                 //~v92dI~
    	return 4;                                                  //~v92dI~
	for (pucs=Ppucs,pcout=Sbuffutf,ii=0;ii<Plen;ii++,pucs++)       //~v92dR~
    {                                                              //~v92dI~
      if (!*pucs)                                                  //~v97rI~
      {                                                            //~v97rI~
      	*pcout='.';                                                //~v97rR~
        len=1;                                                     //~v97rI~
      }                                                            //~v97rI~
      else                                                         //~v97rI~
    	len=uccvucs2utf(*pucs,pcout);                              //~v92dI~
        pcout+=len;                                                //~v92dI~
    }                                                              //~v92dI~
    *pcout=0;                                                      //~v92dI~
    *Pputf8=Sbuffutf;                                              //~v92dI~
	*Ppwritelen=(int)((ULONG)pcout-(ULONG)Sbuffutf);               //~v92dR~
UTRACED("ucs2utf8 out",Sbuffutf,*Ppwritelen);                   //~v92dI~//~v97mR~
    return 0;       //no not free output addr                      //~v92dI~
}//lnx_ucs2utf8                                                    //~v92dI~
#endif                                                             //~v92hI~
//***************************************************************************//~v92dI~
//init static                                                      //~v92dI~
//***************************************************************************//~v92dI~
int lnx_utf8init(void)                                             //~v92dI~
{                                                                  //~v92dI~
	Sisutf8=g_get_charset(&Scurrent_charsetname);                  //~v92dI~
    if (!ustrstri(Gdefaultlocalecode,"utf"))                       //~v976I~
    {                                                              //~v976I~
		Scurrent_charsetname=strdup(Gdefaultlocalecode);           //~v976I~
    	Sisutf8=0;            //such as ecujp.UTF8                 //~v976I~
    }                                                              //~v976I~
    if (!Sisutf8)    //current is not utf8                         //~v92dI~
    {                                                              //~v92dI~
        Sconverterdescriptor=g_iconv_open("UTF-8",Scurrent_charsetname);//~v92dI~
        if (Sconverterdescriptor==(GIConv)-1)                      //~v92dI~
            uerrmsg("%s to UTF-8 is not supported\n",0,            //~v92dI~
					Scurrent_charsetname);                         //~v92dI~
    }                                                              //~v92dI~
    UTRACEP("utf8mode=%d Gdefaultlocalecode=%s,charset=%s,converter=%p\n",Sisutf8,Gdefaultlocalecode,Scurrent_charsetname,Sconverterdescriptor);//~v92hR~//~v970R~//~v976R~//~v9a1R~
    return 0;                                                      //~v92dI~
}                                                                  //~v92dI~
                                                                   //~v92hI~
//*************************************************************    //~v92dI~
//*print api err message                                           //~v92dI~
//*************************************************************    //~v92dI~
void lnx_printgerror(char *Pfile,int Pline,char *Pcmt,GError *Ppgerr)//~v92dI~
{                                                                  //~v92dI~
    if (Ppgerr==NULL)                                              //~v92dI~
    	return;                                                    //~v92dI~
	printf("\n%s %s:%d %s: %s\n",(char*)utimeedit("HHMMSS.MIL",0),Pfile,Pline,Pcmt,Ppgerr->message);//~v92nR~
    g_error_free(Ppgerr);                                          //~v92dI~
}//lnx_printgerr                                                   //~v970R~
//**********************************************************************//~v92fI~
//* calc maxcol by formtype and char pitch                         //~v92fI~
//**********************************************************************//~v92fI~
int lnx_getmaxcol(int Pformtype,int Pnonumsw,int Ppitch)           //~v92fI~
{                                                                  //~v92fI~
	int maxc,widthbypoint;                                         //~v92fR~
    float fpitch;                                                  //~v92fI~
//********************************                                 //~v92fI~
    if (Ppitch>=15)                                                //~v92fI~
		fpitch=(float)Ppitch*2/10;                                 //~v92fI~
    else                                                           //~v92fI~
		fpitch=(float)Ppitch*2;                                    //~v92fI~
	if (UCBITCHK(swsw3,SW3WIN2P))                                  //~v92fI~
//      widthbypoint=Spagewidth-(Sleftmargin+Sleftmargin+Srightmargin);//~v92hR~//~v9a0R~
        widthbypoint=(int)(Spagewidth-(Sleftmargin+Sleftmargin+Srightmargin));//~v9a0I~
    else                                                           //~v92fI~
//      widthbypoint=Spagewidth-(Sleftmargin+Srightmargin);        //~v92fI~//~v9a0R~
        widthbypoint=(int)(Spagewidth-(Sleftmargin+Srightmargin)); //~v9a0I~
//  maxc=(int)(fpitch*widthbypoint*INCHESBYPOINT);                 //~v92fR~//~v9a0R~
    maxc=(int)(fpitch*(float)widthbypoint*INCHESBYPOINT);          //~v9a0I~
    UTRACEP("getmaxcol SW32p=%x,Pitch=%d,maxcol=%d,pagew=%d\n",swsw3&SW3WIN2P,Ppitch,maxc,widthbypoint);//~v92hR~//~v976R~
    if (!Pnonumsw)                                                 //~v92fI~
    	maxc-=LINENOSZ+1;                                          //~v92fI~
    if (maxc>30)                                                   //~v92fI~
	    maxc=maxc/5*5;                                             //~v92fI~
	return maxc;                                                   //~v92fI~
}//lnx_getmaxcol                                                   //~v92fI~
//**********************************************************************//~v92fI~
//* calc maxline by formtype and line pitch                        //~v92fI~
//**********************************************************************//~v92fI~
int lnx_getmaxline(int Pformtype,int Ppitch)                       //~v92fI~
{                                                                  //~v92fI~
	int maxl,heightbypoint;                                        //~v92fR~
    float fpitch;                                                  //~v92fI~
//********************************                                 //~v92fI~
    if (Ppitch>=15)                                                //~v92fI~
		fpitch=(float)Ppitch/10;                                   //~v92fI~
    else                                                           //~v92fI~
		fpitch=(float)Ppitch;                                      //~v92fI~
//  heightbypoint=Spageheight-Stopmargin-Sbottommargin;            //~v92fI~//~v9a0R~
    heightbypoint=(int)(Spageheight-Stopmargin-Sbottommargin);     //~v9a0I~
//  maxl=(int)(fpitch*heightbypoint*INCHESBYPOINT);                //~v92fR~//~v9a0R~
    maxl=(int)(fpitch*(float)heightbypoint*INCHESBYPOINT);         //~v9a0I~
    UTRACEP("getmaxline maxline=%d,pageh=%d,Pformtype=%d,Ppitch=%d\n",maxl,heightbypoint,Pformtype,Ppitch); //~v92hR~//~v970R~
	return maxl;                                                   //~v92fI~
}//lnx_getmaxline                                                  //~v92fI~
#ifdef GTKPRINT                                                    //~v970I~
#else  //!GTKPRINT                                                 //~v970I~
//===============================================================================//~v944I~
//get default config                                               //~v944I~
//parm1:prev pointer to be freed                                   //~v944I~
//parm2:printer name to be set to config                           //~v944I~
//ret  :new config                                                 //~v944I~
//===============================================================================//~v944I~
void lnx_gtksetprinter(void)                                       //~v944R~
{                                                                  //~v944I~
    GnomePrintConfig *pprtconf;                                    //~v944I~
    char *poldprinter,*pprinter;                                   //~v944R~
//************************************                             //~v944I~
	pprinter=Scupsprinter;                                         //~v944I~
//  printf("gtkset printer printer=%s\n",pprinter);                //~v944R~
//    pprtconf=gnome_print_config_default();                       //~v944R~
    pprtconf=Spprtconf;                                            //~v944I~
    poldprinter=gnome_print_config_get(pprtconf,"Printer");        //~v944I~
//  printf("oldprinter=%s\n",poldprinter);                         //~v944R~
    if (strcmp(pprinter,poldprinter))	//not default              //~v944R~
    {                                                              //~v944I~
        gnome_print_config_set(pprtconf,"Printer",pprinter);       //~v944R~
//      printf("config printer after=%s,qfile=%s\n",gnome_print_config_get(pprtconf,"Printer"),pprinter);//~v944R~
    }                                                              //~v944I~
//  printf("gtksetprinter return \n");                             //~v944R~
	return;                                                        //~v944I~
}//lnx_gtksetprinter                                               //~v944I~
#endif //!GTKPRINT                                                 //~v970I~
//*******************************************************************//~v944I~
//*signal func                                                     //~v944I~
//*******************************************************************//~v944I~
void on_framewindow_realize                 (GtkWidget       *widget,//~v944I~
                                        gpointer         user_data)//~v944I~
{                                                                  //~v944I~
//  printf("realize\n");                                           //~v944R~
#ifdef GTKPRINT                                                    //~v970I~
#else                                                              //~v970I~
    gnome_print_config_default();                                  //~v944I~
#endif //!GTKPRINT                                                 //~v970I~
    return;                                                        //~v944I~
}                                                                  //~v944I~
#ifdef GTKPRINT                                                    //~v970I~
#else  //!GTKPRINT                                                 //~v970I~
//*******************************************************************//~v944I~
//*signal func                                                     //~v944I~
//*******************************************************************//~v944I~
void on_button_ok_clicked          (GtkButton       *button,       //~v944I~
                                        gpointer         user_data)//~v944I~
{                                                                  //~v944I~
//  printf("OK\n");                                                //~v944R~
    lnx_gtksetprinter();                                           //~v944I~
//    printf("on_button_ok\n");//@@@@test                          //~v97dR~
    gtk_main_quit();                                               //~v944I~
    return;                                                        //~v944I~
}                                                                  //~v944I~
#endif //!GTKPRINT                                                 //~v970I~
//*******************************************************************//~v944I~
//*signal func                                                     //~v944I~
//*******************************************************************//~v944I~
void on_button_can_clicked          (GtkButton       *button,      //~v944I~
                                        gpointer         user_data)//~v944I~
{                                                                  //~v944I~
    UTRACEP("CAN\n");                                               //~v944R~//~v970R~
    Sswcancel=1;                                                   //~v944I~
#ifndef GTKPRINT                                                   //~v97dR~
    gtk_main_quit();                                               //~v944I~
#endif                                                             //~v97dI~
    return;                                                        //~v944I~
}                                                                  //~v944I~
//*******************************************************************//~v944I~
//*signal func                                                     //~v944I~
//*******************************************************************//~v944I~
gboolean on_framewindow_destroy           (GtkWidget       *widget,//~v944I~
                                        GdkEvent        *event,    //~v944I~
                                        gpointer         user_data)//~v944I~
{                                                                  //~v944I~
    UTRACEP("on_destroy\n");                                           //~v944R~//~v970R~//~v97mR~
#ifdef GTKPRINT                                                    //~v970I~
    Smainwindow=0;                                                 //~v97mI~
  	if (Sswapply)	//reply OK on printdialog                      //~v970R~
    	return FALSE;                                              //~v970I~
#endif                                                             //~v970I~
    Sswcancel=1;                                                   //~v944I~
//  printf("on_frame_window_destroy\n");//@@@@test               //~v97dR~//~v97mR~//~v97pR~
    gtk_main_quit();                                               //~v944I~
	return FALSE;                                                  //~v944I~
}                                                                  //~v944I~
//**************************************************************** //~v944I~
//*create gtk window for asyncronous get for cups printer          //~v944I~
//**************************************************************** //~v944I~
#ifdef GTKPRINT
void gtkinit()                                                     //~v981I~
{                                                                  //~v981I~
	if (Sgtkinit)                                                  //~v981I~
    	return;                                                    //~v981I~
	gtk_init(NULL/*argc*/,NULL/*argv*/);    //suse?                //~v981I~
    UTRACEP("gtkinit\n");                                          //~v988R~
	Sgtkinit=1;                                                    //~v981I~
}//gtkinit()                                                       //~v981I~
//=========================================================================
GtkWidget *lnx_createfw(void)                                      //~v944R~
{                                                                  //~v944I~
  GtkWidget *framewindow;                                          //~v944I~
//GtkWidget *button_ok,*button_can;                                //~v970R~
  GtkWidget *button_can;                                           //~v970I~
  GtkWidget *hbox,*vbox,*lab;                                      //~v944R~
  char wklab[256];                                                 //~v944I~
//************************                                         //~v944I~
//  gtk_init(NULL/*argc*/,NULL/*argv*/);    //suse?                //~v981R~
	gtkinit();                                                     //~v981R~
  framewindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);               //~v944I~
  gtk_window_set_position (GTK_WINDOW (framewindow), GTK_WIN_POS_CENTER);//~v944I~
#ifndef OPTGTK3                                                    //~v980I~
  vbox = gtk_vbox_new (FALSE, 0);  //false:homogeneous             //~v944R~
#else                                                              //~v980I~
  vbox=gtk_box_new(GTK_ORIENTATION_VERTICAL,0/*spacing*/);         //~v980I~
#endif                                                             //~v980I~
  gtk_widget_show (vbox);                                          //~v944I~
  gtk_container_add (GTK_CONTAINER (framewindow),vbox);            //~v944I~
//*                                                                //~v944I~
//sprintf(wklab,"Printer:%s",Scupsprinter);                        //~v970R~
  if (*docname)	//when lnx_flushprint                              //~v970I~
  	sprintf(wklab,"Printing :%s",docname);                         //~v970I~
  else                                                             //~v970I~
  if (!outdevprn)   //to file                                      //~v970I~
  	sprintf(wklab,"Output file:%s",Sdest);                         //~v970I~
  else                                                             //~v970I~
  	sprintf(wklab,"Printer:%s",Sdest);                             //~v970I~
  lab=gtk_label_new(wklab);  //true:homogeneous                    //~v944I~
  Slabel=GTK_LABEL(lab);                                           //~v97dR~
//  printf("is label=%d\n",GTK_IS_LABEL(Slabel));                  //~v97dR~
  gtk_widget_show (lab);                                           //~v944I~
  gtk_box_pack_start (GTK_BOX (vbox),lab,FALSE, FALSE, 0);         //~v944I~
//*                                                                //~v944I~
#ifndef OPTGTK3                                                    //~v980I~
  hbox = gtk_hbox_new (TRUE, 0);  //true:homogeneous               //~v944R~
#else                                                              //~v980I~
  hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0/*spacing*/);       //~v980I~
  gtk_box_set_homogeneous(GTK_BOX(hbox),TRUE);	                   //~v980I~
#endif                                                             //~v980I~
  gtk_widget_show (hbox);                                          //~v944I~
  gtk_box_pack_start (GTK_BOX (vbox),hbox,FALSE, FALSE, 0);        //~v944I~
//*                                                                //~v944I~
//button_ok = gtk_button_new_from_stock ("gtk-ok");                //~v970R~
//gtk_widget_show (button_ok);                                     //~v970R~
//gtk_box_pack_start (GTK_BOX (hbox),button_ok,FALSE, FALSE, 0);   //~v970R~
#if GTK_CHECK_VERSION(3,10,0)                                      //~v9c0R~
  button_can = gtk_button_new_with_label("Cancel");                //~v9c0R~
#else                                                              //~v9c0R~
  button_can = gtk_button_new_from_stock ("gtk-cancel");           //~v944I~
#endif                                                             //~v9c0R~
  Sbutton_can=button_can;                                          //~v97mI~
  gtk_widget_show (button_can);                                    //~v944I~
  gtk_box_pack_start (GTK_BOX (hbox),button_can,FALSE, FALSE, 0);  //~v944I~
//GTK_WIDGET_SET_FLAGS (button_ok,GTK_CAN_DEFAULT);  //set default active button//~v970R~
//*                                                                //~v944I~
//g_signal_connect ((gpointer) button_ok, "clicked",               //~v970R~
//                  G_CALLBACK (on_button_ok_clicked),             //~v970R~
//                  NULL);                                         //~v970R~
  g_signal_connect ((gpointer) button_can, "clicked",              //~v944I~
                    G_CALLBACK (on_button_can_clicked),            //~v944I~
                    NULL);                                         //~v944I~
  g_signal_connect ((gpointer) framewindow, "realize",             //~v944I~
                    G_CALLBACK (on_framewindow_realize),           //~v944I~
                    NULL);                                         //~v944I~
  g_signal_connect ((gpointer) framewindow, "destroy",             //~v944I~
                    G_CALLBACK (on_framewindow_destroy),           //~v944I~
                    NULL);                                         //~v944I~
  UTRACEP("lxn_createfw window=%p\n",framewindow);                 //~v97mR~
  return framewindow;                                              //~v944I~
}//lnx_createfw                                                    //~v944R~
//**************************************************************** //~v97dI~
void lnx_updatefw(void)                                            //~v97dI~
{                                                                  //~v97dI~
  char wklab[256+_MAX_PATH];                                                 //~v97dI~//~v97mR~
//************************                                         //~v97dI~
  sprintf(wklab,"Printing :%s",docname);                           //~v97dI~
  gtk_label_set_text(Slabel,wklab);                                //~v97dR~
if (Gtraceopt)      //trace option by /Yt                          //~v97pI~
  printf("updatefw doc=%s\n",docname);                             //~v97pR~
}//lnx_updatefw                                                    //~v97dI~
//**************************************************************** //~v97mI~
void lnx_updatefwmsg(char *Pmsg)                                   //~v97mI~
{                                                                  //~v97mI~
  gtk_label_set_text(Slabel,Pmsg);                                 //~v97mI~
}//lnx_updatefwmsg                                                 //~v97mR~
#else  //!GTKPRINT
//=========================================================================
GtkWidget *lnx_createfw(void)                                      //~v944R~
{                                                                  //~v944I~
  GtkWidget *framewindow;                                          //~v944I~
  GtkWidget *button_ok,*button_can;                                //~v944I~
  GtkWidget *hbox,*vbox,*lab;                                      //~v944R~
  char wklab[256];                                                 //~v944I~
//************************                                         //~v944I~
  framewindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);               //~v944I~
  gtk_window_set_position (GTK_WINDOW (framewindow), GTK_WIN_POS_CENTER);//~v944I~
  vbox = gtk_vbox_new (FALSE, 0);  //false:homogeneous             //~v944R~
  gtk_widget_show (vbox);                                          //~v944I~
  gtk_container_add (GTK_CONTAINER (framewindow),vbox);            //~v944I~
//*                                                                //~v944I~
  sprintf(wklab,"Printer:%s",Scupsprinter);                        //~v944I~
  lab=gtk_label_new(wklab);  //true:homogeneous                    //~v944I~
  gtk_widget_show (lab);                                           //~v944I~
  gtk_box_pack_start (GTK_BOX (vbox),lab,FALSE, FALSE, 0);         //~v944I~
//*                                                                //~v944I~
  hbox = gtk_hbox_new (TRUE, 0);  //true:homogeneous               //~v944R~
  gtk_widget_show (hbox);                                          //~v944I~
  gtk_box_pack_start (GTK_BOX (vbox),hbox,FALSE, FALSE, 0);        //~v944I~
//*                                                                //~v944I~
  button_ok = gtk_button_new_from_stock ("gtk-ok");                //~v944I~
  gtk_widget_show (button_ok);                                     //~v944I~
  gtk_box_pack_start (GTK_BOX (hbox),button_ok,FALSE, FALSE, 0);   //~v944I~
  button_can = gtk_button_new_from_stock ("gtk-cancel");           //~v944I~
  gtk_widget_show (button_can);                                    //~v944I~
  gtk_box_pack_start (GTK_BOX (hbox),button_can,FALSE, FALSE, 0);  //~v944I~
  GTK_WIDGET_SET_FLAGS (button_ok,GTK_CAN_DEFAULT);  //set default active button//~v944I~
//*                                                                //~v944I~
  g_signal_connect ((gpointer) button_ok, "clicked",               //~v944I~
                    G_CALLBACK (on_button_ok_clicked),             //~v944I~
                    NULL);                                         //~v944I~
  g_signal_connect ((gpointer) button_can, "clicked",              //~v944I~
                    G_CALLBACK (on_button_can_clicked),            //~v944I~
                    NULL);                                         //~v944I~
  g_signal_connect ((gpointer) framewindow, "realize",             //~v944I~
                    G_CALLBACK (on_framewindow_realize),           //~v944I~
                    NULL);                                         //~v944I~
  g_signal_connect ((gpointer) framewindow, "destroy",             //~v944I~
                    G_CALLBACK (on_framewindow_destroy),           //~v944I~
                    NULL);                                         //~v944I~
  return framewindow;                                              //~v944I~
}//lnx_createfw                                                    //~v944R~
#endif //!GTKPRINT
                                                                   //~v970I~
#ifdef GTKPRINT                                                    //~v970I~
//***************************************************************************//~v970I~
void begin_print (GtkPrintOperation *operation,                    //~v970I~
	     GtkPrintContext   *context,                               //~v970I~
	     gpointer           user_data)                             //~v970I~
{                                                                  //~v970I~
	int pagectr;                                                   //~v970I~
//    GtkPrintSettings *settings;                                  //~v98cR~
//    char *pprintername;                                          //~v98cR~
//***************************                                      //~v970I~
    UTRACEP("begin_print tid=%p\n",ugettid());                     //~v984I~
  	UTRACEP("begin_print,Spagerangectr=%d\n",Spagerangectr);                                      //~v970I~//~v97cR~
#ifdef GTKV2200                                                    //~v98jI~
    {  //@@@@test    from 2.20                                     //~v98jR~
    	double t=0.0,b=0.0,l=0.0,r=0.0;	                           //~v98jR~
        gboolean rc;                                               //~v989R~
        rc=gtk_print_context_get_hard_margins(context,&t,&b,&l,&r);//~v989R~
        rc=rc;                                                     //~v9b0I~
	  	UTRACEP("begin_print,hardmargin rc=%d t=%f,b=%f,l=%f,r=%f\n",rc,t,b,l,r);//~v989R~
    }                                                              //~v989I~
#endif                                                             //~v98jI~
//    settings=gtk_print_operation_get_print_settings(operation);  //~v98cR~
//    UTRACEP("begin_print settings=%p\n",settings);               //~v98cR~
//    pprintername=(char*)gtk_print_settings_get_printer(settings);//~v98cR~
//    UTRACEP("begin_print settings printer=%s,Sdest=%s\n",pprintername,Sdest);//~v98cR~
//    if (!(Gxpotheropt & GOO_PRINTDIALOG))//find_printer is not set//~v98cR~
//    {                                                            //~v98cR~
//        if (strcmp(Sdest,pprintername))                          //~v98cR~
//        {                                                        //~v98cR~
//            gtk_print_settings_set_printer(settings,Sdest);      //~v98cR~
//            UTRACEP("begin_print reset printername=%s\n",gtk_print_settings_get_printer(settings));//~v98cR~
//        }                                                        //~v98cR~
//    }                                                            //~v98cR~
    pagectr=Srealpagectr;                                          //~v970I~
    Spcairocontext=gtk_print_context_get_cairo_context(context);   //~v970I~
	if (UCBITCHK(swsw3,SW3WIN2P))                                  //~v976I~
        pagectr=(pagectr+1)/2;      //                             //~v976I~
  	pagectr=getDialogNpage(pagectr);                               //~v97cR~
  	gtk_print_operation_set_n_pages(Spoperation,pagectr);          //~v970R~
    desp_gtkbeginprint(pagectr);                                   //~v970I~
    Spagestart=0;                                                  //~v97cI~
    Spageend=0;                                                    //~v97cI~
  	UTRACEP("begin_print pagectr=%d,Spcairocontext=%p\n",pagectr,Spcairocontext);//~v970R~//~v988R~
}                                                                  //~v970I~
//***************************************************************************//~v970I~
void draw_page (GtkPrintOperation *operation,                      //~v970I~
	   GtkPrintContext   *context,                                 //~v970I~
	   gint               page_nr,                                 //~v970I~
	   gpointer           user_data)                               //~v970I~
{                                                                  //~v970I~
//*************************************                            //~v970I~
    UTRACEP("draw_page   tid=%p\n",ugettid());                     //~v984I~
  	UTRACEP("draw_page no=%d,cairocontext=%p\n",page_nr,gtk_print_context_get_cairo_context(context));//~v970R~//~v97cR~
  	UTRACEP("draw_page dpix=%f\n",gtk_print_context_get_dpi_x(context));//~v989I~
  	UTRACEP("draw_page dpiy=%f\n",gtk_print_context_get_dpi_y(context));//~v989I~
    {//@@@@test                                                    //~v989I~
    	double ww,hh;                                              //~v989I~
        GtkPageSetup *setup=gtk_print_context_get_page_setup(context);//~v989R~
        ww=gtk_page_setup_get_paper_width(setup,GTK_UNIT_POINTS);  //~v989R~
        hh=gtk_page_setup_get_paper_height(setup,GTK_UNIT_POINTS); //~v989R~
        ww=ww; hh=hh;                                              //~v9b0I~
        UTRACEP("draw_page setup width=%f\n",ww);                  //~v989I~
        UTRACEP("draw_page setup height=%f\n",hh);                 //~v989R~
        UTRACEP("draw_page setup margin top=%f\n",gtk_page_setup_get_top_margin(setup,GTK_UNIT_POINTS));//~v989I~
        UTRACEP("draw_page setup margin bottom=%f\n",gtk_page_setup_get_bottom_margin(setup,GTK_UNIT_POINTS));//~v989I~
        UTRACEP("draw_page setup margin left=%f\n",gtk_page_setup_get_left_margin(setup,GTK_UNIT_POINTS));//~v989R~
        UTRACEP("draw_page setup margin right=%f\n",gtk_page_setup_get_right_margin(setup,GTK_UNIT_POINTS));//~v989R~
//#ifndef HHH                                                      //~v989R~
////      gtk_page_setup_set_top_margin(setup,hh-Sfmargins.top,GTK_UNIT_POINTS);//~v989R~
//        gtk_page_setup_set_top_margin(setup,100.0           ,GTK_UNIT_POINTS);//~v989R~
//        gtk_page_setup_set_left_margin(setup,Sfmargins.left,GTK_UNIT_POINTS);//~v989R~
//        gtk_page_setup_set_bottom_margin(setup,Sfmargins.bottom,GTK_UNIT_POINTS);//~v989R~
//        gtk_page_setup_set_right_margin(setup,ww-Sfmargins.right,GTK_UNIT_POINTS);//~v989R~
//        UTRACEP("draw_page setup margin top=%f\n",gtk_page_setup_get_top_margin(setup,GTK_UNIT_POINTS));//~v989R~
//        UTRACEP("draw_page setup margin bottom=%f\n",gtk_page_setup_get_bottom_margin(setup,GTK_UNIT_POINTS));//~v989R~
//        UTRACEP("draw_page setup margin left=%f\n",gtk_page_setup_get_left_margin(setup,GTK_UNIT_POINTS));//~v989R~
//        UTRACEP("draw_page setup margin right=%f\n",gtk_page_setup_get_right_margin(setup,GTK_UNIT_POINTS));//~v989R~
//#endif                                                           //~v989R~
    }                                                              //~v989I~
    if (!Spagestart)                                               //~v97cI~
    	Spagestart=page_nr+1;                                      //~v97cI~
    Spageend=page_nr+1;                                            //~v97cI~
    if (Spagerangectr)                                             //~v97cI~
  		page_nr=getDialogSelectpage(page_nr);                      //~v97cI~
    desp_gtkdrawpage(page_nr);                                     //~v970R~
	UTRACEP("draw_page exit,page=%d\n",page_nr);                                   //~v970I~//~v97cR~
}                                                                  //~v970I~
//***************************************************************************//~v970I~
void end_print (GtkPrintOperation *operation,                      //~v970I~
	   GtkPrintContext   *context,                                 //~v970I~
	   gpointer           user_data)                               //~v970I~
{                                                                  //~v970I~
  	UTRACEP("end_print\n");                                        //~v970R~//~v988R~
	desp_gtkclosedoc();	//delete work                              //~v970I~
}                                                                  //~v970I~
//***************************************************************************//~v970I~
void done_print (GtkPrintOperation *operation,                     //~v970I~
	   GtkPrintOperationResult   result,                           //~v970I~
	   gpointer           user_data)                               //~v970I~
{                                                                  //~v970I~
//  gtk_main_quit();	//return from gtk_main()                   //~v970R~
#ifdef AAA  //destroy at rc=apply                                  //~v970I~
    Sswapply=1;                                                    //~v970I~
    gtk_widget_destroy(Smainwindow);                               //~v970R~
#endif                                                             //~v970I~
  	UTRACEP("done_print,result=%d\n",result);                      //~v970I~//~v988R~
}                                                                  //~v970I~
//***************************************************************************//~v981I~
void begin_print_init (GtkPrintOperation *operation,               //~v981I~
	     GtkPrintContext   *context,                               //~v981I~
	     gpointer           user_data)                             //~v981I~
{                                                                  //~v981I~
	int pagectr=1;                                                 //~v981I~
//***************************                                      //~v981I~
  	UTRACEP("begin_print_init,Spagerangectr=%d\n",Spagerangectr);  //~v988R~
  	gtk_print_operation_set_n_pages(Spoperation,pagectr);          //~v981I~
}                                                                  //~v981I~
//***************************************************************************//~v981I~
void draw_page_init (GtkPrintOperation *operation,                 //~v981I~
	   GtkPrintContext   *context,                                 //~v981I~
	   gint               page_nr,                                 //~v981I~
	   gpointer           user_data)                               //~v981I~
{                                                                  //~v981I~
  	UTRACEP("draw_page_init no=%d,cairocontext=%p\n",page_nr,gtk_print_context_get_cairo_context(context));//~v988R~
}                                                                  //~v981I~
//***************************************************************************//~v981I~
void end_print_init (GtkPrintOperation *operation,                 //~v981I~
	   GtkPrintContext   *context,                                 //~v981I~
	   gpointer           user_data)                               //~v981I~
{                                                                  //~v981I~
  	UTRACEP("end_print_init\n");                                   //~v988R~
}                                                                  //~v981I~
//***************************************************************************//~v981I~
void done_print_init (GtkPrintOperation *operation,                //~v981I~
	   GtkPrintOperationResult   result,                           //~v981I~
	   gpointer           user_data)                               //~v981I~
{                                                                  //~v981I~
  	UTRACEP("done_print_init,result=%d\n",result);                 //~v988R~
}                                                                  //~v981I~
#ifndef WWW                                                        //~v984R~
#ifdef VVV                                                         //~v9c0I~
//***************************************************************************//~v981I~
gboolean onpreview(GtkPrintOperation *operation,                   //~v981I~
	   GtkPrintOperationPreview  *preview,                         //~v981I~
	   GtkPrintContext   *context,                                 //~v981I~
	   GtkWindow   *parent,                                        //~v981I~
	   gpointer           user_data)                               //~v981I~
{                                                                  //~v981I~
    cairo_t *cr;                                                   //~v984R~
    GdkWindow *gdkw;                                               //~v984R~
#if GTK_CHECK_VERSION(3,22,0)                                      //~v9c0I~
    GdkDrawingContext *gdkdc;                                      //~v9c0I~
    cairo_region_t *preg;                                          //~v9c0I~
    cairo_rectangle_int_t *prect;                                  //~v9c0I~
#endif                                                             //~v9c0I~
//*******************                                              //~v981I~
  	printf("onpreview preview_context=%p,cairo_t*=%p\n",context,gtk_print_context_get_cairo_context(context));//~v981R~
    gdkw=gtk_widget_get_window(GTK_WIDGET(parent));                //~v984R~
#if GTK_CHECK_VERSION(3,22,0)                                      //~v9c0I~
	rect.x=0; rect.y=0; rect.width=0; rect.height=0;               //~v9c0I~
	preg=cairo_region_create_rectangle(&rect);                     //~v9c0I~
	gdkdc=gdk_window_begin_draw_frame(gdkw,preg);                  //~v9c0I~
	cr=gdk_drawing_context_get_cairo_context(gdkdc);               //~v9c0I~
#else                                                              //~v9c0I~
    cr=gdk_cairo_create(gdkw);                                     //~v984R~
#endif                                                             //~v9c0I~
    gtk_print_context_set_cairo_context(context,cr,600.0,600.0);   //~v984R~
    gtk_print_operation_preview_end_preview(preview);              //~v984R~
    printf("onpreview return cr=%p,cairo_t*=%p\n",cr,gtk_print_context_get_cairo_context(context));//~v984R~
#if GTK_CHECK_VERSION(3,22,0)                                      //~v9c0I~
	cairo_region_destroy(preg);                                    //~v9c0I~
#endif                                                             //~v9c0I~
    return TRUE;                                                   //~v984R~
//    gtk_print_operation_preview_end_preview(preview);            //~v984R~
//    return FALSE;                                                //~v984R~
}                                                                  //~v981I~
#endif  //VVV                                                      //~v9c0I~
#endif  //WWW                                                      //~v9c0R~
//***************************************************************************//~v970I~
GtkPrintSettings *lnx_settings(GtkPrintOperation *Pppo)            //~v970R~
{                                                                  //~v970I~
    GtkPrintSettings *settings;                                    //~v970M~
//********************                                             //~v970I~
  	UTRACEP("lnx_settings Spsettings=%p\n",Spsettings);            //~v970R~
    if (Spsettings) //by dialog                                    //~v970I~
        settings=Spsettings;                                       //~v970I~
    else                                                           //~v970I~
    	settings = gtk_print_settings_new ();	//dummy            //~v970R~
    UTRACEP("lnx_settings settings=%p,Spsettings=%p\n",settings,Spsettings);//~v970I~
    gtk_print_operation_set_print_settings(Pppo,settings);         //~v970I~
    if (!Spsettings) //by dialog                                   //~v970I~
    	lnx_initdm(Pppo,settings);	//initial set dislog from parm //~v970R~
    return settings;                                               //~v970R~
}                                                                  //~v970I~
#ifdef VVV                                                         //~v985I~
//=========================================================================//~v981I~
//open print dialog at initial req by cmdline parm                 //~v981R~
//set signal;if not get rc:canceled                                //~v985R~
//set/get to dialog using GtkPageSetup                             //~v985I~
//=========================================================================//~v981I~
void                                                               //~v981R~
printdialogGtk_initial(int Popt,GtkWidget *Pparent,GtkPrintOperation *Ppoperation,//~v981R~
						GtkPrintSettings *Ppsettings,GtkPaperSize *Ppps)//~v981R~
{                                                                  //~v981I~
    GtkPrintOperation *operation;                                  //~v981I~
    GtkPageSetup *setup;                                           //~v981M~
	GtkPrintSettings *settings;                                    //~v981I~
	GtkPageOrientation ori;                                        //~v981R~
    gpointer data=NULL;                                            //~v981I~
    GtkPaperSize *pps;                                             //~v981I~
//********************                                             //~v981I~
    operation=Ppoperation;                                         //~v981R~
    g_signal_connect (G_OBJECT (operation), "begin-print",         //~v981I~
              G_CALLBACK (begin_print_init),data);                 //~v981I~
    g_signal_connect (G_OBJECT (operation), "draw-page",           //~v981I~
              G_CALLBACK (draw_page_init), data);                  //~v981I~
    g_signal_connect (G_OBJECT (operation), "end-print",           //~v981I~
              G_CALLBACK (end_print_init), data);                  //~v981I~
    g_signal_connect (G_OBJECT (operation), "done",                //~v981I~
              G_CALLBACK (done_print_init), data);                 //~v981I~
#ifndef WWW                                                        //~v984R~
    g_signal_connect (G_OBJECT (operation), "preview",             //~v981I~
              G_CALLBACK (onpreview),data);                        //~v981I~
#endif                                                             //~v981I~
    gtk_print_operation_set_use_full_page(operation,TRUE);         //~v981I~
    gtk_print_operation_set_unit (operation,GTK_UNIT_POINTS);      //~v981I~
    gtk_print_operation_set_embed_page_setup(operation,TRUE);      //~v981I~
   	if (Gxpotheropt & GOO_PRINTDIALOG)                             //~v981I~
    	return;                                                    //~v981R~
//set pagesetup to settings                                        //~v981I~
    settings=Ppsettings;                                           //~v981R~
    UTRACEP("initial before run settings=%p,pps=%p\n",settings,gtk_print_settings_get_paper_size(settings));//~v988R~
    ori=gtk_print_settings_get_orientation(settings);              //~v981R~
	pps=Ppps;	//paper size                                       //~v981R~
    setup=gtk_page_setup_new();                                    //~v981R~
    gtk_page_setup_set_paper_size(setup,pps);                      //~v981R~
    gtk_page_setup_set_orientation(setup,ori);                     //~v981I~
    gtk_print_operation_set_default_page_setup(operation,setup);   //~v981R~
	UTRACEP("before run setup=%p,pps=%p=%s\n",setup,pps,gtk_paper_size_get_display_name(pps)); //@@@@test//~v988R~
}//printdialogGtk_initial                                          //~v981I~
#endif                                                             //~v985I~
//=========================================================================//~v970I~
//open print dialog                                                //~v970I~
//=========================================================================//~v970I~
int                                                                //~v970R~
printdialogGtk(int Popt,GtkWidget *Pparent)                        //~v970I~
{                                                                  //~v970I~
    GtkPrintOperation *operation;                                  //~v970I~
    GtkPrintSettings *settings;                                    //~v970I~
    GtkPaperSize *pps,*ppso;                                       //~v970R~
    GError *error = NULL;                                          //~v970I~
    int rc,action;                                                 //~v970R~
    gpointer data=NULL;                                            //~v970I~
    GtkPageSetup *setup;                                           //~v981I~
	GtkPageOrientation ori;                                        //~v981I~
//********************                                             //~v970I~
    operation = gtk_print_operation_new ();                        //~v970I~
    Spoperation=operation;                                         //~v970R~
    if (!(Popt & PDGO_INIT))      //initial open printer dialog    //~v970I~
    {                                                              //~v970I~
        g_signal_connect (G_OBJECT (operation), "begin-print",     //~v970R~
                  G_CALLBACK (begin_print),data);                  //~v970R~
        g_signal_connect (G_OBJECT (operation), "draw-page",       //~v970R~
                  G_CALLBACK (draw_page), data);                   //~v970R~
        g_signal_connect (G_OBJECT (operation), "end-print",       //~v970R~
                  G_CALLBACK (end_print), data);                   //~v970R~
        g_signal_connect (G_OBJECT (operation), "done",            //~v970R~
                  G_CALLBACK (done_print), data);                  //~v970R~
#ifndef LLL                                                        //~v989R~//~v98aR~
        gtk_print_operation_set_use_full_page(operation,TRUE);     //~v98aR~
        UTRACEP("before run fullpage\n");                          //~v989I~
#else                                                              //~v989I~//~v98aR~
        gtk_print_operation_set_use_full_page(operation,FALSE);    //~v98aR~
        UTRACEP("before run not fullpage\n");                      //~v989I~//~v98aR~
#endif                                                             //~v989I~//~v98aR~
        gtk_print_operation_set_unit (operation,GTK_UNIT_POINTS);  //~v970R~
        gtk_print_operation_set_embed_page_setup(operation,TRUE);  //~v970R~
    }                                                              //~v970R~
    settings=lnx_settings(operation);                              //~v970R~
    UTRACEP("resolution=%d\n",gtk_print_settings_get_resolution(settings));//~v970I~
    ppso=gtk_print_settings_get_paper_size(settings);              //~v970I~
    UTRACEP("printdialogGtk settings=%p,ppso=%p\n",settings,ppso); //~v988R~
    UTRACEP("before run settings printer=%s\n",gtk_print_settings_get_printer(settings));//~v98aI~
                                                                   //~v981I~
	UTRACEP("ppso %s %s\n",gtk_paper_size_get_name(ppso),gtk_paper_size_get_display_name(ppso));//~v988R~
//    if ((Gxpotheropt & GOO_PRINTDIALOG))                         //~v98nR~
//    {                                                            //~v98nR~
//    printf("\nSelected paperSize:");                               //~v98aR~//~v98nR~
//    printPaperSize((char*)gtk_paper_size_get_name(ppso),(char*)gtk_paper_size_get_display_name(ppso));//~v98aR~//~v98nR~
//    }                                                            //~v98nR~
    printf("\nSelected paperSize:");                               //~v98qI~
    printPaperSize((char*)gtk_paper_size_get_name(ppso),(char*)gtk_paper_size_get_display_name(ppso));//~v98qI~
	UTRACEP("ppso ww=%f,hh=%f point\n",gtk_paper_size_get_width(ppso,GTK_UNIT_POINTS),gtk_paper_size_get_height(ppso,GTK_UNIT_POINTS));//~v98jR~
    action=GTK_PRINT_OPERATION_ACTION_PRINT;                       //~v970I~
#ifdef VVV                                                         //~v985I~
    if (Popt & PDGO_INIT)      //initial open printer dialog       //~v970I~
    {                                                              //~v981I~
    	if (Gxpotheropt & GOO_PRINTDIALOG)                         //~v970I~
	    	action=GTK_PRINT_OPERATION_ACTION_PRINT_DIALOG;        //~v970R~
		printdialogGtk_initial(Popt,Pparent,operation,settings,ppso);//~v981I~
    }                                                              //~v981I~
#endif                                                             //~v985I~
    UTRACEP("gtk_print_operation_run action=%d,settings=%p,printer=%s\n",action,gtk_print_operation_get_print_settings(operation),//~v970R~
    				gtk_print_settings_get_printer(gtk_print_operation_get_print_settings(operation)));//~v970I~
    Sswapply=0;                                                    //~v970I~
//  settings=gtk_print_operation_get_print_settings(operation);//@@@@test//~v985I~
//  printf("printdialogGtk before run settings=%p,settings-printer=%s\n",settings,gtk_print_settings_get_printer(settings));//~v985I~
//#ifndef HHH                                                        //~v989I~//~v98aR~
	setup=create_pagesetup(settings);                              //~v989R~
    gtk_print_operation_set_default_page_setup(operation,setup);   //~v989I~
//#endif                                                             //~v989I~//~v98aR~
                                                                   //~v989I~
    rc=(int)gtk_print_operation_run(operation,action,GTK_WINDOW(Pparent),&error);//~v970R~
                                                                   //~v989I~
    UTRACEP("gtk_print_operation_run return rc=%d\n",rc);          //~v970R~
    UTRACEP("gtk_print_operation_run return rc=%d\n",rc);          //~v988R~
    if (rc==GTK_PRINT_OPERATION_RESULT_CANCEL)                     //~v970I~
    {                                                              //~v970I~
        uerrexit("\nPrint cancelled",0);                             //~v970I~//~v97dR~
    }                                                              //~v970I~
    if (rc==GTK_PRINT_OPERATION_RESULT_APPLY)//dislog OK           //~v970M~
    {                                                              //~v970M~
        Spsettings=gtk_print_operation_get_print_settings(operation);//~v970M~
        UTRACEP("printdialogGtk rc=Apply,request parent destroy Spsettings=%p,settings-printer=%s\n",Spsettings,gtk_print_settings_get_printer(Spsettings));//~v988R~
        g_object_ref(Spsettings);                                  //~v970M~
//      Sswapply=1;                                                //~v970I~//~v97dR~
//      gtk_widget_destroy(Pparent);                               //~v970I~//~v97dR~
      if (action==GTK_PRINT_OPERATION_ACTION_PRINT_DIALOG)         //~v981I~
      {                                                            //~v981I~
        setup=gtk_print_operation_get_default_page_setup(operation);//~v981I~
        pps=gtk_page_setup_get_paper_size(setup);                  //~v981I~
    	ori=gtk_page_setup_get_orientation(setup);                 //~v981I~
        UTRACEP("after run by setup setup=%p,pps=%p=%s,orientation=%d\n",setup,pps,gtk_paper_size_get_display_name(pps),ori); //@@@@test//~v988R~
    	gtk_print_settings_set_paper_size(Spsettings,pps); //papersize may changed by dialog//~v981R~
    	gtk_print_settings_set_orientation(Spsettings,ori); //orientation may changed by dialog//~v981I~
      }                                                            //~v981I~
      else                                                         //~v981I~
        pps=gtk_print_settings_get_paper_size(Spsettings);         //~v970R~
                                                                   //~v981I~
        if (!pps)                                                  //~v970I~
        {                                                          //~v970I~
        	pps=ppso;                                              //~v970I~
    		gtk_print_settings_set_paper_size(Spsettings,pps);     //~v970I~
        }                                                          //~v970I~
        UTRACEP("printdialogGtk settings=%p,papersize=%p=%s\n",Spsettings,pps,gtk_paper_size_get_display_name(pps)); //@@@@test//~v970I~//~v988R~
        UTRACEP("after run pps=%p\n",pps);                         //~v970I~
//  	if ((Gxpotheropt & GOO_PRINTDIALOG))                       //~v970I~//~v97cR~
	    if (action==GTK_PRINT_OPERATION_ACTION_PRINT_DIALOG)       //~v97cI~
        {                                                          //~v97cI~
	        UTRACEP("Dialog selected printer=%s,paper-size=%s",  //~v988R~//~v98nR~
        			gtk_print_settings_get_printer(Spsettings),gtk_paper_size_get_display_name(pps));//~v970I~
            getDialogPageRange(Spsettings);        	               //~v97cR~
        }                                                          //~v97cI~
    }                                                              //~v970M~
    g_object_unref (operation);                                    //~v970I~
//  if (settings!=Spsettings)                                      //~v970R~
//		g_object_unref (settings);                                 //~v970R~
    if (error)                                                     //~v970I~
    {                                                              //~v970I~
      GtkWidget *dialog;                                           //~v970I~
      dialog = gtk_message_dialog_new (GTK_WINDOW (Pparent),       //~v970R~
				       GTK_DIALOG_DESTROY_WITH_PARENT,             //~v970I~
				       GTK_MESSAGE_ERROR,                          //~v970I~
				       GTK_BUTTONS_CLOSE,                          //~v970I~
				       "%s", error->message);                      //~v970I~
      g_error_free (error);                                        //~v970I~
      g_signal_connect (dialog, "response",                        //~v970I~
			G_CALLBACK (gtk_widget_destroy),dialog);                //~v970I~//~v97mR~
                                                                   //~v970I~
      gtk_widget_show(dialog);                                    //~v970I~//~v97mR~
      rc=-1;                                                       //~v970I~
    }                                                              //~v970I~
    return rc;                                                     //~v970I~
}//printdialogGtk                                                  //~v970I~
//=========================================================================//~v985M~
//printdialog out of printoperation to disable preview             //~v985M~
//=========================================================================//~v985M~
int                                                                //~v985M~
printdialogUnixDialog(GtkWidget *Pparent,GtkPrintOperation *Ppoperation,GtkPaperSize **Pppps,GtkPrintSettings *Ppsettings)//~v985I~
{                                                                  //~v985M~
	GtkPrintUnixDialog *pdlg;                                      //~v985M~
    GtkPrintCapabilities cap;                                      //~v985M~
    GtkPageSetup *setup;                                           //~v985M~
	GtkPageOrientation ori;                                        //~v985M~
    GtkPaperSize *pps;                                             //~v985M~
    GtkPrintSettings *settings;                                    //~v985M~
    GtkPrinter *printer;                                           //~v985M~
    int rc;                                                        //~v985M~
    const char *printername;                                       //~v985M~
//    GtkPrintQuality quality=GTK_PRINT_QUALITY_NORMAL;            //~v985R~
//*****************************	                                   //~v985M~
#ifndef OPTGTK3                                                    //~v985I~
	pdlg=(GtkPrintUnixDialog*)gtk_print_unix_dialog_new("GxpGtk2",GTK_WINDOW(Pparent));//~v985M~//~v98kR~
#else                                                              //~v985I~
	pdlg=(GtkPrintUnixDialog*)gtk_print_unix_dialog_new("GxpGtk3",GTK_WINDOW(Pparent));//~v985I~
#endif                                                             //~v985I~
    settings=Ppsettings;                                           //~v985M~
    UTRACEP("printdialogGtk at entry unixdlg settings=%p,settings-printer=%s\n",settings,gtk_print_settings_get_printer(settings));//~v988R~
	pps=*Pppps;	//paper size                                       //~v985M~
    UTRACEP("initial before run settings=%p,pps=%p\n",settings,gtk_print_settings_get_paper_size(settings));//~v988R~
    ori=gtk_print_settings_get_orientation(settings);              //~v985M~
    setup=gtk_page_setup_new();                                    //~v985M~
    gtk_page_setup_set_paper_size(setup,pps);   //currently no function to set default//~v985M~
    gtk_page_setup_set_orientation(setup,ori);                     //~v985M~
    gtk_print_unix_dialog_set_page_setup(pdlg,setup);              //~v985M~
	UTRACEP("before unix dialog run setup=%p,pps=%p=%s\n",setup,pps,gtk_paper_size_get_display_name(pps)); //@@@@test//~v988R~
  	gtk_print_settings_set_use_color(settings,FALSE);              //~v985R~
// 	gtk_print_settings_set_quality(settings,quality);              //~v985I~
  	gtk_print_unix_dialog_set_settings(pdlg,settings);             //~v985I~
    cap=0                                                          //~v985M~
       | GTK_PRINT_CAPABILITY_PAGE_SET                             //~v985M~
       | GTK_PRINT_CAPABILITY_COPIES                               //~v985M~
       | GTK_PRINT_CAPABILITY_COLLATE                              //~v98jR~
       | GTK_PRINT_CAPABILITY_REVERSE                              //~v985M~
       | GTK_PRINT_CAPABILITY_SCALE                                //~v985M~
//     | GTK_PRINT_CAPABILITY_PREVIEW                              //~v985M~//~v98jR~
//     | GTK_PRINT_CAPABILITY_NUMBER_UP                            //~v985M~//~v98jR~
//     | GTK_PRINT_CAPABILITY_NUMBER_UP_LAYOUT                     //~v985M~//~v98jR~
       ;                                                           //~v985M~
    gtk_print_unix_dialog_set_manual_capabilities(pdlg,cap);       //~v985M~
//  gtk_print_operation_set_use_full_page(operation,TRUE);         //~v985M~
//  gtk_print_operation_set_unit (operation,GTK_UNIT_POINTS);      //~v985M~
    gtk_print_unix_dialog_set_embed_page_setup(pdlg,TRUE);         //~v985M~
    gtk_widget_show_all(GTK_WIDGET(pdlg));                         //~v985M~
    gtk_print_unix_dialog_set_current_page(pdlg,0); //@@@@test     //~v98kI~
//*run                                                             //~v98eI~
    rc=gtk_dialog_run(GTK_DIALOG(pdlg));                           //~v985M~
                                                                   //~v98eI~
    UTRACEP("dialogunix rc=%d\n",rc);                              //~v988R~
    switch(rc)                                                     //~v985M~
    {                                                              //~v985M~
    case GTK_RESPONSE_OK:   //-5                                   //~v985M~
    	rc=GTK_PRINT_OPERATION_RESULT_APPLY;                       //~v985M~
        break;                                                     //~v985M~
    default:                                                       //~v985M~
    	return GTK_PRINT_OPERATION_RESULT_CANCEL;                  //~v985M~
    }                                                              //~v985M~
//set new pps from dialog selection                                //~v985M~
	settings=gtk_print_unix_dialog_get_settings(pdlg);//need unref //~v985M~
    setup=gtk_print_unix_dialog_get_page_setup(pdlg);              //~v985M~
    printer=gtk_print_unix_dialog_get_selected_printer(pdlg);      //~v985M~
    printername=gtk_printer_get_name(printer);//may be free at dialog destroy//~v985M~
    UTRACEP("printdialogUnix printer selected=%s,settings=%p\n",printername,settings);//~v988R~
    pps=gtk_page_setup_get_paper_size(setup);                      //~v985M~
    ori=gtk_page_setup_get_orientation(setup);                     //~v985M~
    UTRACEP("after unixdialog run by setup setup=%p,pps=%p=%s,orientation=%d\n",setup,pps,gtk_paper_size_get_display_name(pps),ori);//~v98hR~
    UTRACEP("after unixdialog run by setup margin t=%f,b=%f,l=%f,r=%f\n",//~v989I~
    		gtk_page_setup_get_top_margin(setup,GTK_UNIT_POINTS),  //~v989I~
    		gtk_page_setup_get_bottom_margin(setup,GTK_UNIT_POINTS),//~v989I~
    		gtk_page_setup_get_left_margin(setup,GTK_UNIT_POINTS), //~v989I~
    		gtk_page_setup_get_right_margin(setup,GTK_UNIT_POINTS));//~v989R~
//#ifndef HHH                                                        //~v989I~//~v98aR~
//    gtk_page_setup_set_top_margin(setup,0.0,GTK_UNIT_POINTS);      //~v989R~//~v98aR~
//    gtk_page_setup_set_bottom_margin(setup,0.0,GTK_UNIT_POINTS);   //~v989R~//~v98aR~
//    gtk_page_setup_set_left_margin(setup,0.0,GTK_UNIT_POINTS);     //~v989R~//~v98aR~
//    gtk_page_setup_set_right_margin(setup,0.0,GTK_UNIT_POINTS);    //~v989R~//~v98aR~
//    UTRACEP("after unixdialog run after set 0 setup margin t=%f,b=%f,l=%f,r=%f\n",//~v989I~//~v98aR~
//            gtk_page_setup_get_top_margin(setup,GTK_UNIT_POINTS),  //~v989I~//~v98aR~
//            gtk_page_setup_get_bottom_margin(setup,GTK_UNIT_POINTS),//~v989I~//~v98aR~
//            gtk_page_setup_get_left_margin(setup,GTK_UNIT_POINTS), //~v989I~//~v98aR~
//            gtk_page_setup_get_right_margin(setup,GTK_UNIT_POINTS));//~v989I~//~v98aR~
//#endif                                                             //~v989I~//~v98aR~
    gtk_print_settings_set_paper_size(settings,pps); //papersize may changed by dialog//~v985M~
    gtk_print_settings_set_orientation(settings,ori); //orientation may changed by dialog//~v985M~
    gtk_print_settings_set_printer(settings,printername);          //~v985M~
    UTRACEP("printdialogGtk at return unixdlg settings=%p,settings-printer=%s\n",settings,gtk_print_settings_get_printer(settings));//~v988R~
    gtk_print_operation_set_print_settings(Ppoperation,settings);  //~v985M~
    *Pppps=pps;                                                    //~v985M~
                                                                   //~v985M~
    gtk_widget_destroy(GTK_WIDGET(pdlg));                          //~v985M~
                                                                   //~v985M~
    UTRACEP("printdialogUnix rc=%d\n",rc);                         //~v988R~
    return rc;                                                     //~v985M~
}//printdialogUnixDialog                                           //~v985I~
//=========================================================================//~v985I~
//open print dialog                                                //~v985I~
//=========================================================================//~v985I~
int                                                                //~v985I~
printdialogGtkUnix(int Popt,GtkWidget *Pparent)                    //~v985I~
{                                                                  //~v985I~
    GtkPrintOperation *operation;                                  //~v985I~
    GtkPrintSettings *settings;                                    //~v985I~
    GtkPaperSize *pps,*ppso;                                       //~v985I~
    GtkPageOrientation ori;                                        //~v98iI~
    int rc;                                                        //~v985R~
    char *pdisplayname,*pname,*pprinter;                           //~v988R~
//  double fww,fhh;                                                //~v988R~
//********************                                             //~v985I~
    operation = gtk_print_operation_new ();                        //~v985I~
    Spoperation=operation;                                         //~v985I~
    settings=lnx_settings(operation);                              //~v985I~
    UTRACEP("printdialogUnix resolution=%d\n",gtk_print_settings_get_resolution(settings));//~v985R~
    ppso=gtk_print_settings_get_paper_size(settings);              //~v985I~
    UTRACEP("printdialogGtk settings=%p,ppso=%p\n",settings,ppso); //~v988R~
                                                                   //~v985I~
	UTRACEP("ppso %s %s\n",gtk_paper_size_get_name(ppso),gtk_paper_size_get_display_name(ppso));//~v988R~
	UTRACEP("ppso ww=%f,hh=%f\n",gtk_paper_size_get_width(ppso,GTK_UNIT_MM),gtk_paper_size_get_height(ppso,GTK_UNIT_MM));//~v988R~
    rc=GTK_PRINT_OPERATION_RESULT_APPLY;//dislog OK                //~v985I~
    if (Gxpotheropt & GOO_PRINTDIALOG)                             //~v985I~
    	rc=printdialogUnixDialog(Pparent,operation,&ppso,settings);//~v985I~
    UTRACEP("gtk_print_operation_run settings=%p,printer=%s\n",gtk_print_operation_get_print_settings(operation),//~v985R~
    				gtk_print_settings_get_printer(gtk_print_operation_get_print_settings(operation)));//~v985I~
    Sswapply=0;                                                    //~v985I~
    if (rc==GTK_PRINT_OPERATION_RESULT_CANCEL)                     //~v985I~
    {                                                              //~v985I~
        uerrexit("\nPrint cancelled",0);                           //~v985I~
    }                                                              //~v985I~
    if (rc==GTK_PRINT_OPERATION_RESULT_APPLY)//dislog OK           //~v985I~
    {                                                              //~v985I~
        Spsettings=gtk_print_operation_get_print_settings(operation);//~v985I~
        UTRACEP("printdialogGtkUnix rc=Apply,request parent destroy Spsettings=%p,settings-printer=%s\n",Spsettings,gtk_print_settings_get_printer(Spsettings));//~v98aR~
        g_object_ref(Spsettings);                                  //~v985I~
        pps=gtk_print_settings_get_paper_size(Spsettings);         //~v985I~
	    Sppapersz=pps;                                             //~v986R~
//  	getpapersizewh(GPS_BOTTOMLEFT,pps,&Sfmargins,&fww,&fhh);//~v986I~//~v988R~
        pdisplayname=(char*)gtk_paper_size_get_display_name(pps);  //~v987R~
        pname=(char*)gtk_paper_size_get_name(pps);                 //~v987R~
        UTRACEP("%s:settings=%p,papersize=%p=%s=%s\n",UTT,Spsettings,pps,pname,pdisplayname);//~v988R~//~v9j4R~
    	pprinter=(char*)gtk_print_settings_get_printer(Spsettings);//~v988R~
        lnx_srchGtkPaperSize(0,pprinter,pname,&Sfmargins);         //~v988R~
//      Sotherform=escformchkGtk(pname,pdisplayname,(gtk_paper_size_get_width(pps,GTK_UNIT_POINTS)>gtk_paper_size_get_height(pps,GTK_UNIT_POINTS))/*landscape*/);//~v988R~//~v98iR~
    	ori=gtk_print_settings_get_orientation(Spsettings);        //~v98iI~
        Sotherform=escformchkGtk(pname,pdisplayname,ori);          //~v98iI~
        UTRACEP("printdialogUnix after dialog run settings=%p,pps=%p\n",Spsettings,pps);//~v985R~
	    if (Gxpotheropt & GOO_PRINTDIALOG)                         //~v985I~
        {                                                          //~v985I~
	        printf("Dialog selected printer=%s,paper-size=",   //~v985I~//~v98nR~
        			gtk_print_settings_get_printer(Spsettings));   //~v98nR~
			printPaperSize((char*)gtk_paper_size_get_name(pps),(char*)gtk_paper_size_get_display_name(pps));//~v98nI~
            getDialogPageRange(Spsettings);                        //~v985I~
        }                                                          //~v985I~
    }                                                              //~v985I~
    g_object_unref (operation);                                    //~v985I~
    return rc;                                                     //~v985I~
}//printdialogGtkUnix                                              //~v985R~
#endif //!GTKPRINT                                                 //~v970I~
                                                                   //~v970I~
//**********************************************************************//~v944I~
//* set printer to default config                                  //~v944I~
//**********************************************************************//~v944I~
int lnx_setconfigprinter(char *Ppprinter)                          //~v944I~
{                                                                  //~v944I~
    GtkWidget *framew;                                             //~v944I~
//************************                                         //~v944I~
	strcpy(Scupsprinter,Ppprinter);                                //~v944I~
    framew=lnx_createfw();                                         //~v944R~
    gtk_widget_show(framew);                                       //~v944I~
    UTRACEP("lnx_setconfigprinter show after create window=%p\n",framew);//~v97mI~
#ifdef GTKPRINT                                                    //~v970I~
	Smainwindow=framew;                                            //~v970I~
//  printdialogGtk(PDGO_INIT,framew);                              //~v985R~
	printdialogGtkUnix(PDGO_INIT,framew);                          //~v985M~
#endif //!GTKPRINT                                                 //~v970I~
#ifdef AAA                                                         //~v970I~
	UTRACEP("lnx_setconfigprinter printer=%s,enter gtk_main\n",Ppprinter);//~v970I~
    gtk_main();                                                    //~v944I~
	UTRACEP("lnx_setconfigprinter returned from gtk_main,Sswcancel=%d\n",Ppprinter,Sswcancel);//~v970R~
#endif                                                             //~v970I~
    if (Sswcancel)                                                 //~v944I~
        uerrexit("\nPrint cancelled",0);                             //~v944I~//~v97dR~
//  printf("end of gtk_main\n");                                   //~v944R~
    return 0;                                                      //~v944I~
}//lnx_setconfigprinter                                            //~v944I~
#ifdef GTKPRINT                                                    //~v970I~
//**********************************************************************//~v970I~
//* open main window                                               //~v970I~
//**********************************************************************//~v970I~
void lnx_startjob(char *Pfnm)                                      //~v970I~
{                                                                  //~v970M~
#ifdef GTKPRINT                                                    //~v97kI~
#else                                                              //~v97kI~
    GtkWidget *framew;                                             //~v970I~
#endif                                                             //~v97kI~
//********************************                                 //~v970M~
	UTRACEP("lnx_startjob input=%s\n",Pfnm);                       //~v970I~
	if (UCBITCHK(swsw4,SW4OUTSTDO))                                //~v970I~
    	return;                                                    //~v970I~
#ifdef GTKPRINT                                                    //~v97cI~
#else                                                              //~v97cI~
    framew=lnx_createfw();                                         //~v970I~
    gtk_widget_show(framew);                                       //~v970I~
	Smainwindow=framew;                                            //~v970I~
#endif                                                             //~v97cI~
}//lnx_startjob                                                    //~v970I~
//**********************************************************************//~v970I~
//* from xprint;before phase2 start notify pagectr for draw_page   //~v970I~
//**********************************************************************//~v970I~
void lnx_startdoc2(int Ppagectr)                                   //~v970I~
{                                                                  //~v970I~
//********************************                                 //~v970I~
	if (UCBITCHK(swsw4,SW4OUTSTDO))                                //~v970I~
    	return;                                                    //~v970I~
    Srealpagectr=Ppagectr;                                        //~v970I~//~v97cR~
	UTRACEP("lnx_startdoc2 pagectr=%d,pagectr of doc=%d\n",Ppagectr,Srealpagectr);//~v970I~
}//lnx_startjob                                                    //~v970I~
//**********************************************************************//~v970I~
//* from closedoc; send work file to printer                       //~v970R~
//* start print_operation_run                                      //~v970I~
//**********************************************************************//~v970I~
int lnx_flushprint()                                               //~v970R~
{                                                                  //~v970I~
//  GtkWidget *framew;                                             //~v970I~//~v97kR~
//************************                                         //~v970I~
    UTRACEP("lnx_flushprint\n");                                   //~v970I~
//    framew=lnx_createfw();                                         //~v970I~//~v97dR~
//    gtk_widget_show(framew);                                       //~v970I~//~v97dR~
//    Smainwindow=framew;                                            //~v970I~//~v97dR~
	lnx_updatefw();                                                //~v97dI~
    Splayout=gtk_widget_create_pango_layout(Smainwindow,NULL);     //~v970I~
	Sflushphase=1;                                                 //~v970M~
	printdialogGtk(0/*not init*/,Smainwindow);                     //~v970R~
	Sflushphase=0;                                                 //~v970M~
#ifdef AAA                                                         //~v970I~
	UTRACEP("lnx_flushptrint enter gtk_main\n");                   //~v970I~
    gtk_main();                                                    //~v970I~
    UTRACEP("lnx_flushprint return cancel=%d\n",Sswcancel);        //~v970I~
#endif                                                             //~v970I~
    if (Sswcancel)                                                 //~v970I~
        uerrexit("\nPrint cancelled",0);                             //~v970I~//~v97dR~
    return 0;                                                      //~v970I~
}//lnx_flushprint                                                  //~v970R~
//=========================================================================//~v970I~
//=get papername from displayname                                  //~v970I~
//=========================================================================//~v970I~
const char *lnx_getcupspapername(char *Ppaperdisplayname)          //~v970I~
{                                                                  //~2B03aI~//~v970I~
	GList *gl,*gl0;                                                //~v970I~
    GtkPaperSize *pps;                                             //~v970I~
    const char *pdisplayname;                                      //~v970I~
    const char *pname;                                             //~v970I~
    int swfound=0;                                                 //~v970I~
//************************************                             //~v970I~
    gl0=gtk_paper_size_get_paper_sizes(FALSE);                     //~v970I~
//  Scupspaperlistsize=g_list_length(gl0);                         //~v973I~//~v9a0R~
    Scupspaperlistsize=(int)g_list_length(gl0);                    //~v9a0I~
    for (gl=g_list_first(gl0);gl!=NULL;gl=gl->next)                //~v984R~
    {                                                              //~v970I~
    	pps=(GtkPaperSize*)gl->data;                               //~v970I~
        pdisplayname=gtk_paper_size_get_display_name(pps);         //~v970I~
        UTRACEP("lnx_getcupspapername name=%s,displayname=%s\n",gtk_paper_size_get_name(pps),pdisplayname);//~v988R~
        if (*Ppaperdisplayname=='?')	//list request             //~v973I~
        {                                                          //~v983I~
        	UTRACEP("%s(%s)\n",pdisplayname,gtk_paper_size_get_name(pps));//~v988R~
            UTRACEP("ww=%f,hh=%f point\n",gtk_paper_size_get_width(pps,GTK_UNIT_POINTS),gtk_paper_size_get_height(pps,GTK_UNIT_POINTS));//~v988R~
            UTRACEP("ww=%f,hh=%f mm\n",gtk_paper_size_get_width(pps,GTK_UNIT_MM),gtk_paper_size_get_height(pps,GTK_UNIT_MM));//~v988R~
        }                                                          //~v983I~
        else                                                       //~v973I~
        if (!stricmp((void*)pdisplayname,Ppaperdisplayname))               //~v970I~//~v976R~//~v970R~
        {                                                          //~v970I~
	        pname=gtk_paper_size_get_name(pps);                    //~v970I~
            swfound=1;                                             //~v970I~
        	break;                                                 //~v970I~
        }                                                          //~v970I~
    }                                                              //~v970I~
    if (!swfound)                                                  //~v970I~
    	pname=NULL;                                                //~v970I~
    UTRACEP("lnx_getcupspapername name=%s\n",pname);               //~v970R~
    return pname;                                                  //~v970I~
}//lnx_getcupspapername                                            //~v970I~
////===============================================================================//~v970R~
////=gdowble width/height of paper by POINTS(include HWmargin)     //~v970R~
////===============================================================================//~v970R~
//void *lnx_getpapersize(int Popt/*free*/,char *Pformtype,gdouble *Ppww,gdouble *Pphh)//~v970R~
//{                                                                //~v970R~
//    GtkPaperSize *pps;                                           //~v970R~
//    const char *pname;                                           //~v970R~
//    gdouble ww,hh;                                               //~v970R~
////*******************************                                //~v970R~
////  pname=Sppdsz->name;                                          //~v970R~
//    pname=gtk_paper_szie_get_name(Sppapersz);                    //~v970I~
//    pps=gtk_paper_size_new(pname);                               //~v970R~
//    ww=gtk_paper_size_get_width(pps,GTK_UNIT_POINTS);            //~v970R~
//    hh=gtk_paper_size_get_height(pps,GTK_UNIT_POINTS);           //~v970R~
//    UTRACEP("lnx_getpapersize new for paper=%s w=%lf Point,h=%lf Point\n",Pformtype,ww,hh);//~v970R~
//    UTRACEP("lnx_getpapersize new name=%s,displayname=%s\n",gtk_paper_size_get_name(pps),gtk_paper_size_get_display_name(pps));//~v970R~
//    UTRACEP("lnx_getpapersize new margin by mm top=%lf,bottom=%lf,left=%lf,right=%lf\n",gtk_paper_size_get_default_top_margin(pps,GTK_UNIT_MM),gtk_paper_size_get_default_bottom_margin(pps,GTK_UNIT_MM),gtk_paper_size_get_default_left_margin(pps,GTK_UNIT_MM),gtk_paper_size_get_default_right_margin(pps,GTK_UNIT_MM));//~v970R~
//    if (Ppww)                                                    //~v970R~
//        *Ppww=ww;                                                //~v970R~
//    if (Pphh)                                                    //~v970R~
//        *Pphh=hh;                                                //~v970R~
//    if (Popt & CSGPS_FREE)                                       //~v970R~
//    {                                                            //~v970R~
//        gtk_paper_size_free(pps);                                //~v970R~
//        pps=NULL;                                                //~v970R~
//    }                                                            //~v970R~
//    return pps;                                                  //~v970R~
//}//lnx_getpapersize                                              //~v970R~
//===============================================================================//~v970I~
//=from lnx_initdm;                                                //~v98mR~
//===============================================================================//~v970I~
void lnx_setpapersize(GtkPrintSettings *Ppsettings)                //~v970R~
{                                                                  //~v970I~
	GtkPaperSize *pps;                                             //~v970I~
    gdouble ww,hh;                                                 //~v970I~
//*******************************                                  //~v970I~
//	pps=(GtkPaperSize*)lnx_getpapersize(0/*no free*/,Pformtype,&ww,&hh);//~v970R~
  	pps=Sppapersz;                                                 //~v970I~
    gtk_print_settings_set_paper_size(Ppsettings,pps);             //~v970R~
    UTRACEP("lnx_setpapersize settings=%p,papersize=%p\n",Ppsettings,pps);//~v98hR~
//  gtk_print_settings_set_paper_width(Ppsettings,ww,GTK_UNIT_POINTS);//~v970R~
//  gtk_print_settings_set_paper_height(Ppsettings,hh,GTK_UNIT_POINTS);//~v970R~
//  UTRACEP("lnx_setpapersize form=%s,w=%lf,h=%lf\n",Pformtype,ww,hh);//~v970R~
    ww=gtk_print_settings_get_paper_width(Ppsettings,GTK_UNIT_POINTS);//~v970R~
    hh=gtk_print_settings_get_paper_height(Ppsettings,GTK_UNIT_POINTS);//~v970R~
    ww=ww; hh=hh;                                                  //~v9b0I~
    UTRACEP("lnx_setpapersize form=%s,w=%lf,h=%lf\n",gtk_paper_size_get_display_name(pps),ww,hh);//~v988R~
    UTRACEP("lnx_getpapersize default margin top=%lf,bottom=%lf,left=%lf,right=%lf\n",gtk_paper_size_get_default_top_margin(pps,GTK_UNIT_POINTS),gtk_paper_size_get_default_bottom_margin(pps,GTK_UNIT_POINTS),gtk_paper_size_get_default_left_margin(pps,GTK_UNIT_POINTS),gtk_paper_size_get_default_right_margin(pps,GTK_UNIT_POINTS));//~v989I~
//  gtk_paper_size_free(pps);                                      //~v970R~
}//lnx_setpapersize                                                //~v970I~
//===============================================================================//~v970I~
void                                                               //~v970R~
lnx_setcolorGtk(cairo_t *Ppct)                                     //~v970I~
{                                                                  //~vam0I~//~v970I~
    UTRACEP("lnx_setcolorGtk\n");                       //~vam0R~ //~vamqR~//~v970I~
//  cairo_set_source_rgb(Ppct,0.01,0.01,0.01);                     //~vam0R~//~v970I~//~v97bR~
    cairo_set_source_rgb(Ppct,0.0,0.0,0.0);                        //~v97bI~
}                                                                  //~vam0I~//~v970I~
//===============================================================================//~va6yI~//~v973I~
//get form supported by the printer                                //~v973I~
//===============================================================================//~va6yI~//~v973I~
#ifdef AAA                                                         //~v9h0R~
ppd_size_t *lnx_srchppdsizePrinter(int Popt,char *Pprinter,char *Ppform)//~va6yI~//~v973R~//~v970R~
{                                                                  //~2B03aI~//~va6yI~//~v973I~
    int ii,formno;                                           //~va6yI~//~v973R~
    char *pdest,*pform,*pppdnm;                            //~va6yR~//~v973R~
    ppd_file_t *ppd;                                               //~va6yI~//~v973I~
    ppd_size_t *ppgsz,*rc=NULL;                                             //~va6yI~//~v973R~
//************************************                             //~va6yI~//~v973I~
    UTRACEP("lnx_chkcupsformPrinter parm printer=%s,form=%s\n",Pprinter,Ppform);//~vam0R~//~v973R~
    if (!Ppform || !*Ppform)                                       //~v970I~
    	Ppform=DEFAULT_PAPER;                                      //~v970I~
    pdest=Pprinter;                                                //~v973I~
    pppdnm=(char *)cupsGetPPD((const char *)pdest);                //~va6yI~//~v973I~
    if (!pppdnm)                                                   //~va6yI~//~v973I~
    	return rc;                                                  //~va6yI~//~v973R~
    ppd=ppdOpenFile(pppdnm);                                       //~va6yI~//~v973I~
    if (!ppd)                                                      //~va6yI~//~v973I~
    	return rc;                                                  //~va6yI~//~v973R~
    formno=ppd->num_sizes;                                         //~va6yI~//~v973I~
    ppgsz=ppd->sizes;                                              //~va6yR~//~v973I~
    Scupspaperlistsize=formno;                                     //~v973I~
    for (ii=formno;ii>0;ii--,ppgsz++)                 //~va6yI~    //~v973I~
    {                                                              //~vam0I~//~v973I~
    	pform=ppgsz->name;                                         //~v973R~
        UTRACEP("lnx_chkcupaformPrinter name=%s\n",pform);         //~v973R~
        if (*Ppform=='?')	//list request                         //~v973I~
        	printf("%s\n",pform);                                  //~v973R~
        else                                                       //~v973I~
        if (!strcmp(pform,Ppform))                                 //~v973R~
        {                                                          //~v973I~
        	rc=ppgsz;                                              //~v973R~
        	break;                                                 //~v973I~
        }                                                          //~v973I~
    }                                                              //~vam0I~//~v973I~
    ppdClose(ppd);                                                 //~va6yI~//~v973I~
    return rc;                                                      //~va6yI~//~v973R~
}//lnx_srchppdsizePrinter                                          //~v970R~
#endif  //AAA                                                      //~v9h0I~
//===============================================================================//~v984I~
//compare papersize name                                           //~v984I~
//rc:0:fullstring match,1:contains parm string,-1:unmatch          //~v985I~
//===============================================================================//~v984I~
int comparePaperSize(char *Pparm,char *Pname,char *Pdisplayname)   //~v984I~
{                                                                  //~v984I~
	int rc=1;//unmatch                                             //~v984I~
//*****************                                                //~v984I~
    if (!stricmp(Pparm,Pname)    //by display name                 //~v984I~
//  ||  (Pdisplayname && !stricmp(Pparm,Pdisplayname)))    //by display name//~v984I~//~v98gR~
	)                                                              //~v98gI~
    	rc=0;                                                      //~v984I~
    else                                                           //~v984I~
    {                                                              //~v984I~
    	if (USTRHEADIS_IC(Pname,"iso_"))                           //~v984R~
        	rc=stricmp(Pparm,Pname+4);                             //~v984I~
        else                                                       //~v984I~
    	if (USTRHEADIS_IC(Pname,"ppd_"))                           //~v984R~
        	rc=stricmp(Pparm,Pname+4);                             //~v984I~
        else                                                       //~v988I~
    	if (USTRHEADIS_IC(Pname,"na_"))                            //~v988I~
        	rc=stricmp(Pparm,Pname+3);                             //~v988I~
    }                                                              //~v984I~
    if (rc)                                                        //~v985I~
    {                                                              //~v985I~
    	rc=-1;                                                     //~v985I~
        if (ustrstri(Pname,Pparm))                                 //~v985I~
        	rc=1;	//partial match                                //~v985I~
        else                                                       //~v985I~
        if (Pdisplayname && ustrstri(Pdisplayname,Pparm))          //~v985R~
        	rc=1;                                                  //~v985I~
    }                                                              //~v985I~
    UTRACEP("comparepaperSize rc=%d,parm=%s,name=%s,display=%s\n",rc,Pparm,Pname,Pdisplayname);//~v986I~
    return rc;                                                     //~v984I~
}//comparePaperSize                                                //~v984I~
//===============================================================================//~v98kI~
//compare papersize name GtkPaperSize and ppd                      //~v98kI~
//rc:0:fullstring match,1:contains parm string,-1:unmatch          //~v98kI~
//===============================================================================//~v98kI~
int comparePaperNameGtkPPD(char *Pgtkname,char *Pppdname)          //~v98kI~
{                                                                  //~v98kI~
	int rc=-1;//unmatch                                            //~v98kI~
    char *gtkname,*ppdname;                                        //~v98kR~
//*****************                                                //~v98kI~
    gtkname=Pgtkname;                                              //~v98kI~
    ppdname=Pppdname;                                              //~v98kI~
    if (!stricmp(gtkname,ppdname))                                 //~v98kI~
    	rc=0;                                                      //~v98kI~
    else                                                           //~v98kI~
    {                                                              //~v98kI~
    	if (USTRHEADIS_IC(Pgtkname,"iso_"))                        //~v98kI~
        	gtkname+=4;                                            //~v98kI~
        else                                                       //~v98kI~
    	if (USTRHEADIS_IC(Pgtkname,"ppd_"))                        //~v98kI~
        	gtkname+=4;                                            //~v98kI~
        else                                                       //~v98kI~
    	if (USTRHEADIS_IC(Pgtkname,"na_"))                         //~v98kI~
        	gtkname+=3;                                            //~v98kI~
                                                                   //~v98kI~
        if (!stricmp(gtkname,ppdname))                             //~v98kR~
        	rc=0;                                                  //~v98kI~
        else                                                       //~v98kI~
        {                                                          //~v98kI~
    		if (USTRHEADIS_IC(Pppdname,"Env"))                     //~v98kI~
        		ppdname+=3;                                        //~v98kI~
	        if (!stricmp(gtkname,ppdname))                         //~v98kI~
        		rc=0;                                              //~v98kI~
        }                                                          //~v98kI~
                                                                   //~v98kM~
    }                                                              //~v98kI~
    if (rc)                                                        //~v98kI~
    {                                                              //~v98kI~
        if (ustrstri(gtkname,ppdname))                             //~v98kI~
        	rc=1;	//partial match                                //~v98kI~
    }                                                              //~v98kI~
    UTRACEP("comparePaperNameGtkPPD rc=%d,parm gtk=%s,ppd=%s,comp gtk=%s,ppd=%s\n",rc,Pgtkname,Pppdname,gtkname,ppdname);//~v98kI~
    return rc;                                                     //~v98kI~
}//comparePaperNameGtkPPD                                          //~v98kI~
//===============================================================================//~v984I~
//print papersize                                                  //~v984I~
//===============================================================================//~v984I~
void printPaperSize(char *Pname,char *Pdisplayname)                //~v984R~
{                                                                  //~v984I~
	char *pc;                                                      //~v984R~
//*****************                                                //~v984I~
//    if (USTRHEADIS_IC(Pname,"iso_"))                               //~v984R~//~v98gR~
//        pc=Pname+4;                                                //~v984I~//~v98gR~
//    else                                                           //~v984I~//~v98gR~
//    if (USTRHEADIS_IC(Pname,"ppd_"))                               //~v984R~//~v98gR~
//        pc=Pname+4;                                                //~v984I~//~v98gR~
//    else                                                           //~v984I~//~v98gR~
    	pc=Pname;                                                  //~v984I~
    if (!Pdisplayname)                                             //~v984I~
    	printf("%s\n",pc);                                         //~v984I~
    else                                                           //~v984I~
    if (!stricmp(pc,Pdisplayname))    //by display name            //~v984R~
    	printf("%s\n",Pdisplayname);                               //~v984I~
    else                                                           //~v984I~
		printf("%s [\"%s\"]\n",pc,Pdisplayname);                   //~v984I~
}//printPaperSize                                                  //~v984I~
#ifdef NNN                                                         //~v98nI~
//===============================================================================//~v985I~
//get papersize Point value,margin width to position value         //~v985R~
//===============================================================================//~v985I~
void getpapersizewh(int Popt,GtkPaperSize *Ppps,FRECT *Ppfrect,double *Ppfwidth,double *Ppfheight)//~v985I~
{                                                                  //~v985I~
	double ww,hh;                                                  //~v985I~
    GtkUnit unit=GTK_UNIT_POINTS;                                  //~v985I~
//*******************	                                           //~v985I~
	Ppfrect->top=gtk_paper_size_get_default_top_margin(Ppps,unit); //~v985I~
    Ppfrect->bottom=gtk_paper_size_get_default_bottom_margin(Ppps,unit);//~v985I~
    Ppfrect->left=gtk_paper_size_get_default_left_margin(Ppps,unit);//~v985I~
    Ppfrect->right=gtk_paper_size_get_default_right_margin(Ppps,unit);//~v985I~
    ww=gtk_paper_size_get_width(Ppps,unit);                        //~v985I~
    hh=gtk_paper_size_get_height(Ppps,unit);                       //~v985I~
    UTRACEP("getpapersize point ww=%f,hh=%f,t=%f,b=%f,l=%f,r=%f\n",ww,hh,Ppfrect->top,Ppfrect->bottom,Ppfrect->left,Ppfrect->right);//~v985M~
    if (Popt & GPS_BOTTOMLEFT)	//convert from GtkPaperSize(TopLeft) to ppd_size_t(BottomLeft)//~v985I~
    {                                                              //~v985I~
    	Ppfrect->top=hh-Ppfrect->top;                              //~v985I~
    	Ppfrect->right=ww-Ppfrect->right;                          //~v985I~
    }                                                              //~v985I~
    if (Ppfwidth)                                                  //~v985I~
    	*Ppfwidth=ww;                                              //~v985I~
    if (Ppfheight)                                                 //~v985I~
    	*Ppfheight=hh;                                             //~v985I~
    UTRACEP("getpapersize out by opt=%d t=%f,b=%f,l=%f,r=%f\n",Popt,Ppfrect->top,Ppfrect->bottom,Ppfrect->left,Ppfrect->right);//~v985I~
}//getpapersize                                                    //~v985I~
#else  //!NNN                                                      //~v98nI~
//===============================================================================//~v98nI~
//get margin/papersize by point                                    //~v98nI~
//===============================================================================//~v98nI~
void getpapermarginwh(GtkPaperSize *Ppps,GtkPageSetup *Ppsetup,FRECT *Ppfrect,double *Ppfwidth,double *Ppfheight)//~v98nI~
{                                                                  //~v98nI~
	double ww,hh,tt,bb,ll,rr;                                      //~v98nR~
    GtkUnit unit=GTK_UNIT_POINTS;                                  //~v98nI~
//*******************                                              //~v98nI~
    tt=gtk_page_setup_get_top_margin(Ppsetup,unit);                //~v98nI~
    bb=gtk_page_setup_get_bottom_margin(Ppsetup,unit);             //~v98nI~
    ll=gtk_page_setup_get_left_margin(Ppsetup,unit);               //~v98nR~
    rr=gtk_page_setup_get_right_margin(Ppsetup,unit);              //~v98nR~
    ww=gtk_paper_size_get_width(Ppps,unit);                        //~v98nI~
    hh=gtk_paper_size_get_height(Ppps,unit);                       //~v98nI~
    UTRACEP("getpapermarginwh name=%s,display=%s,margin t=%f,b=%f,l=%f,r=%f w=%f,h=%f\n",//~v98nR~
    		gtk_paper_size_get_name(Ppps),gtk_paper_size_get_display_name(Ppps),tt,bb,ll,rr,ww,hh);//~v98nR~
    if (Gtraceopt)                                                 //~v98nI~
    	printf("getpapermarginwh name=%s,display=%s,margin t=%f,b=%f,l=%f,r=%f w=%f,h=%f\n",//~v98nR~
    		gtk_paper_size_get_name(Ppps),gtk_paper_size_get_display_name(Ppps),tt,bb,ll,rr,ww,hh);//~v98nI~
//  Ppfrect->top=hh-tt;                                            //~v98nI~//~v9a0R~
    Ppfrect->top=(float)(hh-tt);                                   //~v9a0I~
//  Ppfrect->bottom=bb;                                            //~v98nI~//~v9a0R~
    Ppfrect->bottom=(float)bb;                                     //~v9a0I~
//  Ppfrect->left=ll;                                              //~v98nI~//~v9a0R~
    Ppfrect->left=(float)ll;                                       //~v9a0I~
//  Ppfrect->right=ww-rr;                                          //~v98nI~//~v9a0R~
    Ppfrect->right=(float)(ww-rr);                                 //~v9a0I~
    UTRACEP("getpapermarginwh t=%f,b=%f,l=%f,r=%f\n",Ppfrect->top,Ppfrect->bottom,Ppfrect->left,Ppfrect->right);//~v98nI~
    if (Ppfwidth)                                                  //~v98nI~
    	*Ppfwidth=ww;                                              //~v98nI~
    if (Ppfheight)                                                 //~v98nI~
    	*Ppfheight=hh;                                             //~v98nI~
}//getpapersize                                                    //~v98nI~
#endif //NNN                                                       //~v98nI~
#ifdef GTKV2120                                                    //~v981R~
#ifdef NNN                                                         //~v98nI~
//===============================================================================//~v988I~
PUPPDSZ uppdszalloc(ppd_size_t *Pppdsz,char *Pdisplayname)         //~v988I~
{                                                                  //~v988I~
	int len;                                                       //~v988I~
	PUPPDSZ puppdsz;                                               //~v988I~
//********************                                             //~v988I~
	if (Pdisplayname)                                              //~v988I~
    	len=strlen(Pdisplayname);                                  //~v988I~
    else                                                           //~v988I~
    	len=0;                                                     //~v988I~
    puppdsz=(PUPPDSZ)malloc(len+UPPDSZSIZE);                       //~v988R~
    memcpy(&(puppdsz->UPPDSZppdsz),Pppdsz,sizeof(ppd_size_t));     //~v988R~
	if (Pdisplayname)                                              //~v988I~
    	strcpy(puppdsz->UPPDSZdisplayname,Pdisplayname);           //~v988I~
    else                                                           //~v988I~
    	*puppdsz->UPPDSZdisplayname=0;                             //~v988I~
    return puppdsz;                                                //~v988I~
}//uppdszaloc                                                      //~v988I~
#endif //NNN                                                       //~v98nI~
#ifdef NNN                                                         //~v98nI~
//===============================================================================//~v988I~
void uppdszgetpapersizewh(PUPPDSZ Ppuppdsz,FRECT *Ppfmargin,double *Ppfww,double *Ppfhh)//~v988R~
{                                                                  //~v988I~
    ppd_size_t *ppgsz;
//********************                                             //~v988I~
	ppgsz=&Ppuppdsz->UPPDSZppdsz;                                  //~v988I~
	Ppfmargin->top=ppgsz->top;                                     //~v988R~
	Ppfmargin->bottom=ppgsz->bottom;                               //~v988R~
	Ppfmargin->left=ppgsz->left;                                   //~v988R~
	Ppfmargin->right=ppgsz->right;                                 //~v988R~
	*Ppfww=ppgsz->width;                                           //~v988R~
	*Ppfhh=ppgsz->length;                                          //~v988R~
    UTRACEP("uppdszgetpapersizewh ppdname %s:%s w=%f,h=%f,margin t=%f,b=%f,l=%f,r=%f\n",ppgsz->name,Ppuppdsz->UPPDSZdisplayname,//~v988R~//~v98aR~
                        ppgsz->width,ppgsz->length,                //~v98aR~
                        ppgsz->length-ppgsz->top,ppgsz->bottom,    //~v98aI~
                        ppgsz->left,ppgsz->width-ppgsz->right);
}//uppdszgetpapersizewh                                            //~v988I~
//===============================================================================//~v98kI~
void srchppdszformargin(PUPPDSZ Ppuppdsz,FRECT *Ppfmargin,double *Ppfww,double *Ppfhh,char *Pgtkpapername,GList *Pgl)//~v98kI~
{                                                                  //~v98kI~
    ppd_size_t *ppgsz;                                             //~v98kI~
    char *ppdpapername;                                            //~v98kI~
    GList *gl;                                                     //~v98kI~
	PUPPDSZ puppdsz,puppdszpartial=NULL;                           //~v98kI~
    int rc,rc0,partialmatch=0;                                     //~v98kR~
//********************                                             //~v98kI~
    puppdsz=Ppuppdsz;                                              //~v98kI~
	ppgsz=&puppdsz->UPPDSZppdsz;                                   //~v98kI~
    ppdpapername=ppgsz->name;                                      //~v98kI~
    rc0=comparePaperNameGtkPPD(Pgtkpapername,ppdpapername);        //~v98kR~
    if (rc0==1)	//partial match                                    //~v98kI~
    	rc0=0;	//prefer sequence                                  //~v98kI~
    if (rc0)//unmatch                                              //~v98kI~
    {                                                              //~v98kI~
        for (gl=g_list_first(Pgl);gl;gl=gl->next)                  //~v98kR~
        {                                                          //~v98kI~
        	puppdsz=(PUPPDSZ)(gl->data);                           //~v98kI~
			ppgsz=&puppdsz->UPPDSZppdsz;                           //~v98kI~
		    ppdpapername=ppgsz->name;                              //~v98kI~
			rc=comparePaperNameGtkPPD(Pgtkpapername,ppdpapername); //~v98kI~
			if (!rc)                                               //~v98kI~
            {                                                      //~v98kI~
            	partialmatch=0;                                    //~v98kI~
            	break;                                             //~v98kI~
            }                                                      //~v98kI~
            if (rc==1)	                                           //~v98kI~
            {                                                      //~v98kI~
            	if (!partialmatch)//prefer sequence                //~v98kR~
                	puppdszpartial=puppdsz;                        //~v98kI~
            	partialmatch++;                                    //~v98kI~
            }                                                      //~v98kI~
            puppdsz=NULL;                                          //~v98kI~
        }                                                          //~v98kI~
    	UTRACEP("gtk & ppd sequence error\n");                     //~v98kI~
    	printf("gtk & ppd sequence error\n");   //@@@@test         //~v98kI~
    }                                                              //~v98kI~
    if (!puppdsz)                                                  //~v98kI~
    {                                                              //~v98kI~
    	if (puppdszpartial)                                        //~v98kR~
        {                                                          //~v98kI~
        	puppdsz=puppdszpartial;                                //~v98kR~
			ppgsz=&puppdsz->UPPDSZppdsz;                           //~v98kI~
		    ppdpapername=ppgsz->name;                              //~v98kI~
            if (partialmatch>1)	//multiple                         //~v98kR~
            	printf("Warning multiple ppd entry for %s, %s is selected\n",Pgtkpapername,ppdpapername);//~v98kI~
            else                                                   //~v98kI~
            	printf("Warning no corresponding ppd entry for %s, %s is selected\n",Pgtkpapername,ppdpapername);//~v98kI~
        }                                                          //~v98kI~
    }                                                              //~v98kI~
    if (!puppdsz)                                                  //~v98kI~
    {                                                              //~v98kI~
	    puppdsz=Ppuppdsz;                                          //~v98kI~
        ppgsz=&puppdsz->UPPDSZppdsz;                               //~v98kI~
        ppdpapername=ppgsz->name;                                  //~v98kI~
    	printf("Warning multiple ppd entry for %s, %s is selected\n",Pgtkpapername,ppdpapername);//~v98kI~
    }                                                              //~v98kI~
	uppdszgetpapersizewh(puppdsz,Ppfmargin,Ppfww,Ppfhh);           //~v98kI~
}//srchppdszformargin                                              //~v98kI~
#endif //NNN                                                       //~v98nM~
#ifdef NNN                                                         //~v98nI~
//===============================================================================//~v988I~
//srch paper for the printer                                       //~v988I~
//rc:4: err                                                        //~v988I~
//===============================================================================//~v988I~
GList *lnx_getppdlist(int Popt,char *Pprinter)                     //~v988I~
{                                                                  //~2B03aI~//~v988I~
    int ii=0,formno;                                               //~v988I~
    char *pppdnm;                                                  //~v988I~
    ppd_file_t *ppd=NULL;                                          //~v988I~
    ppd_size_t *ppgsz;                                             //~v988I~
    const char *pname;                                             //~v988I~
    char *pdisplayname;                                            //~v988I~
    GList *gl0=NULL;                                               //~v988R~
    PUPPDSZ puppdsz;                                               //~v988R~
//************************************                             //~v988I~
    UTRACEP("lnx_getppdlist parm opt=%x,printer=%s\n",Popt,Pprinter);//~v988I~
    pppdnm=(char *)cupsGetPPD((const char *)Pprinter);             //~v988I~
    UTRACEP("lnx_getppdlist ppdnm=%s\n",pppdnm);                   //~v988I~
    if (!pppdnm)                                                   //~v988I~
        uerrexit("\"%s\" not found(cupsGetPPD failed or No printer defined)",0,//~v988I~
                    Pprinter);                                     //~v988I~
    ppd=ppdOpenFile(pppdnm);                                       //~v988I~
    if (!ppd)                                                      //~v988I~
//      uerrexit("printer:%s is defined(ppdOpenFile failed)",pppdnm);//~v992R~
        uerrexit("printer:%s is defined(ppdOpenFile failed)",0,pppdnm);//ifdef NNN//~v992I~
    formno=ppd->num_sizes;                                         //~v988I~
    UTRACEP("lnx_getppdlist ppd count=%d\n",formno);         //~v988R~//~v9h0R~
    ppgsz=ppd->sizes;                                              //~v988I~
    if (!formno)                                                   //~v988I~
//      uerrexit("No PaperSize is defined on printer:%s",Pprinter);//~v992R~
        uerrexit("No PaperSize is defined on printer:%s",0,Pprinter); //ifdef NNN//~v992I~
    for (ii=formno;ii>0;ii--,ppgsz++)                              //~v988I~
    {                                                              //~v988I~
        pname=ppgsz->name;                                         //~v988I~
        pdisplayname=getdisplayname(ppd,ppgsz->name);              //~v988I~
        UTRACEP("lnx_getppdlist name=%s=%s,w=%f,h=%f,t=%f,b=%f,l=%f,r=%f\n",pname,pdisplayname,ppgsz->width,ppgsz->length,ppgsz->top,ppgsz->bottom,ppgsz->left,ppgsz->right);//~v988I~
        UTRACEP("ppd %s margin t=%f,b=%f,l=%f,r=%f\n",pname,       //~v988I~
                        ppgsz->length-ppgsz->top,ppgsz->bottom,    //~v988I~
                        ppgsz->left,ppgsz->width-ppgsz->right);    //~v988I~
        puppdsz=uppdszalloc(ppgsz,pdisplayname);                   //~v988I~
        gl0=g_list_append(gl0,puppdsz);                            //~v988I~
    }                                                              //~v988I~
    if (ppd)                                                       //~v988I~
	    ppdClose(ppd);                                             //~vamuI~//~v970I~                   0//~v988I~
    return g_list_first(gl0);                                      //~v988R~
}//lnx_getppdlist                                                  //~v988I~
#endif                                                             //~v98nI~
//===============================================================================//~v981I~
//srch paper for the printer using gtk api(>=2.12)                 //~v981I~
//===============================================================================//~v981I~
int lnx_srchGtkPaperSize_212(int Popt,char *Pprinter,char *Ppform,PFRECT Ppfmargin,GtkPaperSize **Pppps)//~v981R~
{                                                                  //~v981I~
    int ii,formno,rc2,partialmatchctr=0;                                                 //~v981R~//~v985R~
    ppd_size_t ppgsz;                                              //~v981R~
    const char *pname,*pdisplayname;                               //~v984R~
    FRECT fmargin={0.0,0.0,0.0,0.0};                               //~v981I~
    GtkPrinter *pprinter;                                          //~v981I~
	GList *gl0,*gl;                                                //~v981I~
	GtkPageSetup *psetup;                                          //~v981I~
	GtkPaperSize *pps=NULL,*ppsfound=NULL;                         //~v984R~
    double fww,fhh;                                                //~v985I~
#ifdef NNN                                                         //~v98nR~
    GList *gluppdsz0,*gluppdsz;                                    //~v988I~
    UPPDSZ *puppdsz;                                               //~v988R~
#endif                                                             //~v98nM~
//************************************                             //~v981I~
    UTRACEP("%s:srchGtkPaperSize tid=%p\n",UTT,ugettid());                //~v984I~//~v9j4R~
	gtkinit();//for enumprinter                                    //~v981R~
    UTRACEP("%s parm opt=%x,printer=%s,form=%s\n",UTT,Popt,Pprinter,Ppform);//~v984R~//~v9j4R~
	pprinter=srchprinterGtk(Pprinter,NULL/*realname*/);            //~v981R~
#ifdef GTKV2140                                                    //~v98mI~
    if (Popt & SGPSO_GETDEFAULTPAPERSIZE) 	//0x02 get default papersize set by printer setting//~v98mI~
    {                                                              //~v98mI~
		Ppform=get_printer_defaultpapersize(pprinter,Ppform);      //~v98mR~
        strcpy(Sprinterdefaultpapersize,Ppform);                   //~v98mI~
    }                                                              //~v98mI~
#endif                                                             //~v98mI~
	gl0=gl=getcupspaperlistGtk(pprinter);                          //~v981I~
    if (!gl)    //has_detail=FALSE                                 //~v981I~
        return 4;                                                  //~v981I~
#ifdef NNN                                                         //~v98nR~
	gluppdsz0=gluppdsz=lnx_getppdlist(0,Pprinter);                 //~v988R~
    if (!gluppdsz) //has_detail=FALSE                                 //~v988I~//~v98nR~
        return 4;                                                  //~v988I~
#endif  //NNN                                                      //~v98nR~
//  formno=g_list_length(gl);                                      //~v981R~//~v9a0R~
    formno=(int)g_list_length(gl);                                 //~v9a0I~
    Scupspaperlistsize=formno;                                     //~v981R~
    for (ii=formno,gl=g_list_first(gl0);ii>0;ii--,gl=gl->next)     //~v984R~
    {                                                              //~v981R~
        psetup=(GtkPageSetup*)(gl->data);                          //~v981R~
        pps=gtk_page_setup_get_paper_size(psetup);                 //~v981R~
        pname=gtk_paper_size_get_name(pps);                        //~v981R~
        pdisplayname=gtk_paper_size_get_display_name(pps);         //~v984I~
        UTRACEP("%s:name=%s=%s\n",UTT,pname,pdisplayname);//~v988R~//~v9j4R~
//      getpapermarginwh(pps,psetup,&fmargin,&fww,&fhh);    //@@@@test//~v98nR~
        if (*Ppform=='?')                                          //~v981R~
        {                                                          //~v98gI~
            printPaperSize((char*)pname,(char*)pdisplayname);      //~v984R~
  			if (Gtraceopt)      //trace option by /Yt              //~v98gI~
                printf("PaperSize:%s=%s,w=%f,h=%f\n",              //~v98gR~
                			pname,pdisplayname,                    //~v98gI~
            				gtk_paper_size_get_width(pps,GTK_UNIT_POINTS),//~v98gI~
            				gtk_paper_size_get_height(pps,GTK_UNIT_POINTS));//~v98gI~
        }                                                          //~v98gI~
        else                                                       //~v981R~
        {                                                          //~v981R~//~v985M~
        	rc2=comparePaperSize(Ppform,(char*)pname,(char*)pdisplayname);//~v985R~
	        UTRACEP("lnx_srchGtkPaperSize_212 rc=%d,req=%s,name=%s=%s\n",rc2,Ppform,pname,pdisplayname);//~v989R~
          if (!rc2 || (rc2==1 && partialmatchctr==0))              //~v985R~
          {                                                        //~v985I~
//*ppd_size_t:value is by point                                    //~v985I~
//    		getpapersizewh(GPS_BOTTOMLEFT,pps,&fmargin,&fww,&fhh); //~v988R~
#ifdef NNN                                                         //~v98nR~
    		puppdsz=(PUPPDSZ)(gluppdsz->data);                     //~v988I~
//  		uppdszgetpapersizewh(puppdsz,&fmargin,&fww,&fhh);      //~v988I~//~v98kR~
    		srchppdszformargin(puppdsz,&fmargin,&fww,&fhh,(char*)pname,gluppdsz0);//~v98kR~
            {                                                    //~v98gR~//~v98hR~
                double fwwgtk,fhhgtk;                            //~v98gR~//~v98hR~
                fwwgtk=gtk_paper_size_get_width(pps,GTK_UNIT_POINTS);//~v98gR~//~v98hR~
                fhhgtk=gtk_paper_size_get_height(pps,GTK_UNIT_POINTS);//~v98gR~//~v98hR~
                if ((int)(fww-fwwgtk)||(int)(fhh-fhhgtk))        //~v98gR~//~v98hR~
                {                                                //~v98gR~//~v98hR~
//                  pps=gtk_paper_size_new_from_ppd(puppdsz->UPPDSZppdsz.name,puppdsz->UPPDSZdisplayname,fww,fhh);//~v98gR~//~v98hR~
                    pps=getCustomPapersize((char*)pdisplayname,(char*)pname,&puppdsz->UPPDSZppdsz,&fmargin);//~v98gR~//~v98hR~
                    if (Gtraceopt)      //trace option by /Yt    //~v98gR~//~v98hR~
                        printf("papersize reset by ppd name=%s,displayname=%s,old=%f,%f,new=%f,%f\n",//~v98gR~//~v98hR~
                                gtk_paper_size_get_name(pps),gtk_paper_size_get_display_name(pps),//~v98gR~//~v98hR~
                                    fwwgtk,fhhgtk,fww,fhh);      //~v98gR~//~v98hR~
                        printf("papersize reset by ppd name=%s,displayname=%s,dif=%e,%e\n",//~v98gR~//~v98hR~
                                gtk_paper_size_get_name(pps),gtk_paper_size_get_display_name(pps),//~v98gR~//~v98hR~
                                    fwwgtk-fww,fhhgtk-fhh);      //~v98gR~//~v98hR~
                    UTRACEP("reset papersize %s:%s new w=%f,h=%f\n",//~v98gR~//~v98hR~
                                gtk_paper_size_get_name(pps),gtk_paper_size_get_display_name(pps),//~v98gR~//~v98hR~
                                gtk_paper_size_get_width(pps,GTK_UNIT_POINTS),//~v98gR~//~v98hR~
                                gtk_paper_size_get_height(pps,GTK_UNIT_POINTS));//~v98gR~//~v98hR~
                }                                                //~v98gR~//~v98hR~
            }                                                    //~v98gR~//~v98hR~
#else  //!NNN                                                      //~v98nR~
            getpapermarginwh(pps,psetup,&fmargin,&fww,&fhh);       //~v98nR~
#endif //NNN                                                       //~v98nR~
#ifdef MMM                                                         //~v98hI~
            if (Sshiftdirectionorigin)                             //~v98aI~
				shiftpaperorigin(fww,fhh,&Sxshift,&Syshift);       //~v98aI~
#endif                                                             //~v98hI~
            if (Sshiftdirection && !(Popt & SGPSO_NOSHIFT))        //~v981R~
            {                                                      //~v981R~
//              ppgsz.width=fww;                                   //~v985R~//~v9a0R~
                ppgsz.width=(float)fww;                            //~v9a0I~
//              ppgsz.length=fhh;                                  //~v985R~//~v9a0R~
                ppgsz.length=(float)fhh;                           //~v9a0I~
                ppgsz.top=fmargin.top;                             //~v985R~
                ppgsz.bottom=fmargin.bottom;                       //~v985R~
                ppgsz.left=fmargin.left;                           //~v985R~
                ppgsz.right=fmargin.right;                         //~v985R~
                UTRACEP("lnx_srchGtkPaperSize_212 name=%s,w=%f,h=%f,t=%f,b=%f,l=%f,r=%f\n",pname,ppgsz.width,ppgsz.length,ppgsz.top,ppgsz.bottom,ppgsz.left,ppgsz.right);//~v988R~//~v9h0R~
                pps=getCustomPapersize(Ppform,(char *)pname,&ppgsz,&fmargin);//~v981R~
            }                                                      //~v981R~
            ppsfound=pps;                                          //~v984I~
          }                                                        //~v985I~
          if (!rc2)                                                //~v985I~
          {                                                        //~v985I~
	        partialmatchctr=0;                                     //~v985I~
            break;                                                 //~v981R~
          }                                                        //~v985I~
          if (rc2==1)                                              //~v989R~
    	      partialmatchctr++;                                   //~v989R~
        }                                                          //~v981R~
#ifdef NNN                                                         //~v98nR~
	    gluppdsz=gluppdsz->next;                                   //~v988I~
#endif  //NNN                                                      //~v98nR~
    }                                                              //~v981R~
    g_list_free(gl0);                                              //~v981I~
#ifdef NNN                                                         //~v98nI~
    g_list_free(gluppdsz0);                                        //~v988I~
#endif  //NNN                                                      //~v98nI~
    if (*Ppform!='?')                                              //~v981I~
    {                                                              //~v981I~
    	if (partialmatchctr>1)                                     //~v985I~
        	uerrexit("Papersize:\"%s\" is ambiguous(match with multiple papers),\ncheck available paprsize by -e/? option.",0,//~v989R~
            			Ppform);                                   //~v985R~
	    if (Ppfmargin)                                             //~v981I~
        {                                                          //~v98hI~
#ifndef MMM                                                        //~v98hI~
        	if (ppsfound)                                          //~v98hI~
				applyparmmargin(&fmargin,gtk_paper_size_get_width(ppsfound,GTK_UNIT_POINTS),gtk_paper_size_get_height(ppsfound,GTK_UNIT_POINTS));//~v98hR~
#endif                                                             //~v98hI~
    		*Ppfmargin=fmargin;                                    //~v981I~
        }                                                          //~v98hI~
    	UTRACEP("lnx_srchGtkPaperSize_212 iscustom=%d,w=%f point,h=%f point\n",//~v981I~//~v9h0R~
    			pps?gtk_paper_size_is_custom(pps):0,               //~v981I~
				pps?gtk_paper_size_get_width(pps,GTK_UNIT_POINTS):0.0,//~v981I~
				pps?gtk_paper_size_get_height(pps,GTK_UNIT_POINTS):0.0);//~v981I~
    	UTRACEP("lnx_srchGtkPaperSize_212 papersize by mm w~%f,h=%f \n",//~v98aI~//~v9h0R~
				pps?gtk_paper_size_get_width(pps,GTK_UNIT_MM):0.0, //~v98aI~
				pps?gtk_paper_size_get_height(pps,GTK_UNIT_MM):0.0);//~v98aI~
	}                                                              //~v981I~
    *Pppps=ppsfound;                                               //~v984R~
    return 0;                                                      //~v981I~
}//lnx_srchGtkPaperSize_212                                        //~v981R~
#endif	//2.12.0                                                   //~v981R~
//===============================================================================//~v983I~
//get display name                                                 //~v983I~
//*see debug source:gtk+-3.6.4/modules/printbackends/cups/gtkprintbackendcups.c//~v983I~
//===============================================================================//~v983I~
#ifndef NOPPD                                                      //~v9h0I~
char *getdisplayname(ppd_file_t *Pppd,char *Ppapersize)            //~v983R~
{                                                                  //~2B03aI~//~v983I~
    ppd_option_t *ppdoption;//see modules/printbackends/cups/gtkprintbackendcups.c//~v983I~
    ppd_choice_t *ppdchoice;                                       //~v983I~
    char *displayname=NULL;                                        //~v983I~
//***********************************                              //~v983I~
    ppdoption=ppdFindOption(Pppd,"PageSize");                      //~v983I~
    if (ppdoption)                                                 //~v983I~
    {                                                              //~v983I~
        ppdchoice=ppdFindChoice(ppdoption,Ppapersize);             //~v983R~
        if (ppdchoice)                                             //~v983I~
        {                                                          //~v983I~
//          displayname=ppd_text_to_utf8(ppd,ppdchoice->text);     //~v983I~
            displayname=ppdchoice->text;                           //~v983I~
        }                                                          //~v983I~
    }                                                              //~v983I~
    return displayname;                                            //~v983I~
}//getdisplayname                                                  //~v983I~
#endif  //NOPPD                                                    //~v9h0I~
//===============================================================================//~vamuI~//~v970I~
//srch paper for the printer                                       //~v970I~
//rc:4: err                                                        //~vamuI~//~v970I~
//===============================================================================//~vamuI~//~v970I~
#ifndef NOPPD                                                      //~v9h0I~
GtkPaperSize *lnx_srchGtkPaperSize(int Popt,char *Pprinter,char *Ppform,PFRECT Ppfmargin)//~vamuR~//~v970R~//~v977R~
{                                                                  //~2B03aI~//~vamuI~//~v970I~
    int ii=0,formno;                                               //~vamuI~//~v970I~
    char *pppdnm;                                           //~vamuR~//~v970R~
    ppd_file_t *ppd=NULL;                                          //~vamuI~//~v970I~
    ppd_size_t *ppgsz;                                             //~vamuI~//~v970I~
    GtkPaperSize *pps=NULL;                                        //~v970R~
    const char *pname;                                             //~vamuR~//~v970I~
    char *pdisplayname;                                            //~v983R~
    FRECT fmargin={0.0,0.0,0.0,0.0};                               //~v970R~
    int partialmatchctr=0,rc2;                                     //~v988I~
	double fww,fhh;                                                //~v9b0R~
//#ifdef GTKV2120                                                  //~v988R~
//    char *ppsname=NULL;                                          //~v988R~
//    GtkPaperSize *pps212=NULL;                                   //~v988R~
//#endif                                                           //~v988R~
//************************************                             //~vamuI~//~v970I~
    UTRACEP("%s:parm opt=%x,printer=%s,form=%s\n",UTT,Popt,Pprinter,Ppform);//~vamuI~//~v970I~//~v977R~//~v9j4R~
    if (!*Ppform)                                                  //~v98aI~
    	Ppform=DEFAULT_PAPER;                                      //~v98aI~
#ifdef GTKV2120
	if (!lnx_srchGtkPaperSize_212(Popt,Pprinter,Ppform,Ppfmargin,&pps))//~v981R~
    {                                                              //~v988I~
//      if (*Ppform=='?')                                          //~v988R~
  	  if (!(Gtraceopt && *Ppform=='?'))                            //~v98gI~
    	return pps;                                                //~v981I~
//      pps212=pps;                                                //~v988R~
//      if (pps)                                                   //~v988R~
//      {                                                          //~v988R~
//        ppsname=(char*)gtk_paper_size_get_name(pps);             //~v988R~
//        pps=0;                                                   //~v988R~
//      }                                                          //~v988R~
    }                                                              //~v988I~
#endif                                                             //~v985I~
    for (;;)                                                       //~vamuI~//~v970I~
    {                                                              //~vamuI~//~v970I~
        pppdnm=(char *)cupsGetPPD((const char *)Pprinter);            //~vamuI~//~v970I~
        UTRACEP("lnx_srchGtkPaperSize ppdnm=%s\n",pppdnm);//~vamuI~//~v970I~
        if (!pppdnm)                                               //~vamuI~//~v970I~
            uerrexit("\"%s\" not found(cupsGetPPD failed or No printer defined)",0,//~v97bR~
            			Pprinter);                                 //~v970I~
        ppd=ppdOpenFile(pppdnm);                                   //~vamuI~//~v970I~
        if (!ppd)                                                  //~vamuI~//~v970I~
//          uerrexit("printer:%s is defined(ppdOpenFile failed)",pppdnm);//~vamuI~//~v992R~
            uerrexit("printer:%s is defined, but ppdOpenFile failed.",0,Pprinter);//~v992R~
        formno=ppd->num_sizes;                                     //~vamuI~//~v970I~
        UTRACEP("lnx_srchGtkPaperSize ppd count=%d\n",formno);     //~v988R~
        ppgsz=ppd->sizes;                                          //~vamuI~//~v970I~
        if (!formno)                                               //~vamuI~//~v970I~
//          uerrexit("No form is defined on printer:%s",Pprinter);//~vamuI~//~v992R~
            uerrexit("No form is defined on printer:%s",0,Pprinter);//~v992I~
	    Scupspaperlistsize=formno;                                 //~v970I~
        for (ii=formno;ii>0;ii--,ppgsz++)                          //~vamuI~//~v970I~
        {                                                          //~vamuI~//~v970I~
            UTRACEP("lnx_srchGtkPaperSize name=%s,w=%f,h=%f,t=%f,b=%f,l=%f,r=%f\n",ppgsz->name,ppgsz->width,ppgsz->length,ppgsz->top,ppgsz->bottom,ppgsz->left,ppgsz->right);//~vamuI~//~v970I~
            pdisplayname=getdisplayname(ppd,ppgsz->name);          //~v983I~
            pname=ppgsz->name;                                     //~v983I~
            UTRACEP("lnx_srchGtkPaperSize parm=%s,displayname=%s\n",Ppform,pdisplayname);//~v985I~
			UTRACEP("comp %s:%s-%s\n",Ppform,pname,pdisplayname);  //~v988R~
            UTRACEP("ppd %s margin t=%f,b=%f,l=%f,r=%f\n",pname,//~v987I~//~v988I~
                            ppgsz->length-ppgsz->top,ppgsz->bottom,//~v987I~//~v988M~
                            ppgsz->left,ppgsz->width-ppgsz->right);//~v987I~//~v988M~
            if (*Ppform=='?')                                      //~v970I~
            {                                                      //~v983I~
        		UTRACEP("ppd name %s\n",ppgsz->name);                        //~v984R~//~v988R~
				printPaperSize((char*)pname,(char*)pdisplayname);  //~v984R~
  				if (Gtraceopt)      //trace option by /Yt          //~v98gI~
                	printf("ppd PaperSize:%s=%s,w=%f,h=%f,t=%f,b=%f,l=%f,r=%f\n",//~v98gR~
                    		pname,pdisplayname,                    //~v98gI~
            				ppgsz->width,ppgsz->length,            //~v98gI~
                            ppgsz->length-ppgsz->top,ppgsz->bottom,//~v98gI~
                            ppgsz->left,ppgsz->width-ppgsz->right);//~v98gI~
            }                                                      //~v983I~
            else                                                   //~v970I~
          {                                                        //~v988I~
//        	if (!stricmp(Ppform,ppgsz->name))    //by display name  //~vamuI~//~v970I~//~v983R~
//      	if (!comparePaperSize(Ppform,(char*)pname,(char*)pdisplayname))//~v984R~//~v988R~
        	rc2=comparePaperSize(Ppform,(char*)pname,(char*)pdisplayname);//~v988I~
//#ifdef GTKV2120                                                  //~v988R~
//            if (rc2 && pps212)//not fully match                  //~v988R~
//            {                                                    //~v988R~
//                int rc3;                                         //~v988R~
//                rc3=comparePaperSize((char*)pname,ppsname,NULL); //~v988R~
//                if (!rc3) //ppdname is same as papersize on paper list//~v988R~
//                    rc2=0;  //fill margin rect                   //~v988R~
//                else                                             //~v988R~
//                    rc2=-1; //avoid partial match because on paper list//~v988R~
//            }                                                    //~v988R~
//#endif                                                           //~v988R~
            if (!rc2 || (rc2==1 && partialmatchctr==0))            //~v988I~
            {                                                      //~vamuI~//~v970I~
				UTRACEP("paper found %s [\"%s\"]\n",pname,pdisplayname);//~v988R~
				UTRACEP("ww=%f,hh=%f point\n",ppgsz->width,ppgsz->length);//~v983I~//~v985R~
				UTRACEP("ppds margin t=%f,b=%f,l=%f,r=%f\n",ppgsz->top,ppgsz->bottom,ppgsz->left,ppgsz->right);//~v985I~
//*ppd_size_t:value is by point and BottomLeft origin              //~v985R~
                fmargin.top=ppgsz->top;                            //~v970I~//~v977M~
                fmargin.bottom=ppgsz->bottom;                      //~v970I~//~v977M~
                fmargin.left=ppgsz->left;                          //~v970I~//~v977M~
                fmargin.right=ppgsz->right;                        //~v970I~//~v977M~
  				pname=lnx_getcupspapername(Ppform);   //papername from displayname//~v983R~//~v985R~
// 				lnx_getcupspapername("?");   //@@@@test            //~v983I~//~v985R~
//              UTRACEP("lnx_srchGtkPaperSize name=%s\n",pname);   //~v988R~
//              if (pname)                                         //~vamuI~//~v983R~
                {                                                  //~v977I~
				    if (Sshiftdirection && !(Popt & SGPSO_NOSHIFT))//~v977R~
						pps=getCustomPapersize(Ppform,(char *)pname,ppgsz,&fmargin);//~v977R~
                    else                                           //~v977I~
  	    				pps=gtk_paper_size_new(pname);                 //~vamuI~//~v970I~//~v983R~
//	    				pps=gtk_paper_size_new_from_ppd(pname,pdisplayname?pdisplayname:"",ppgsz->width,ppgsz->length);//from ppd is custom//~v983R~
					UTRACEP("ppsnew %s %sn",gtk_paper_size_get_name(pps),gtk_paper_size_get_display_name(pps));//~v988R~
					fww=gtk_paper_size_get_width(pps,GTK_UNIT_MM); //~v98aI~
					fhh=gtk_paper_size_get_height(pps,GTK_UNIT_MM);//~v98aI~
                    fww=fww; fhh=fhh;                              //~v9b0I~
					UTRACEP("ppsnew ww=%f,hh=%f\n",fww,fhh);       //~v98aR~
#ifdef MMM                                                         //~v98hI~
				    if (Sshiftdirectionorigin)                     //~v98aI~
				    	shiftpaperorigin(fww,fhh,&Sxshift,&Syshift);//~v98aI~
#endif                                                             //~v98hI~
                }                                                  //~v977I~
//              else                                               //~vamuI~//~v983R~
//  				pps=getCustomPapersize(Ppform,Ppform,ppgsz,&fmargin);//~v983R~
              if (!rc2)                                            //~v988I~
              {                                                    //~v988I~
	            partialmatchctr=0;	//for the case matched partial at previous iter//~v988I~
            	break;                                             //~vamuI~//~v970I~
              }                                                    //~v988I~
              if (rc2==1)                                          //~v989R~
        	      partialmatchctr++;                               //~v989R~
            }                                                      //~vamuI~//~v970I~
          }//!"?"                                                  //~v988I~
        }                                                          //~vamuI~//~v970I~
        break;                                                     //~vamuI~//~v970I~
    }                                                              //~vamuI~//~v970I~
    if (ppd)                                                       //~vamuI~//~v970I~
	    ppdClose(ppd);                                             //~vamuI~//~v970I~                   0//~v970R~
    if (*Ppform!='?')                                              //~v970I~
    {                                                              //~v970I~
    	if (partialmatchctr>1)                                     //~v988I~
        	uerrexit("Papersize:\"%s\" is ambiguous(match with multiple papers)",0,//~v988I~
            			Ppform);                                   //~v988I~
                                                                   //~v988I~
      if (pps)	//found on ppd                                     //~v988I~
	    if (Ppfmargin)                                             //~v970I~
        {                                                          //~v98hI~
#ifndef MMM                                                        //~v98hI~
			applyparmmargin(&fmargin,gtk_paper_size_get_width(pps,GTK_UNIT_POINTS),gtk_paper_size_get_height(pps,GTK_UNIT_POINTS));//~v98hR~
#endif                                                             //~v98hI~
    		*Ppfmargin=fmargin;                                    //~v970I~
            UTRACEP("lnx_srchGtkPaperSize margin  t=%f,b=%f,l=%f,r=%f\n",fmargin.top,fmargin.bottom,fmargin.left,fmargin.right);//~v98hI~
        }                                                          //~v98hI~
//#ifdef GTKV2120                                                  //~v988R~
//      if (!pps)                                                  //~v988R~
//        pps=pps212;                                              //~v988R~
//#endif                                                           //~v988R~
    	UTRACEP("lnx_srchGtkPaperSize iscustom=%d,w=%f point,h=%f point\n",//~v970I~//~v988R~
    			pps?gtk_paper_size_is_custom(pps):0,               //~v970I~
				pps?gtk_paper_size_get_width(pps,GTK_UNIT_POINTS):0.0,//~v970I~
				pps?gtk_paper_size_get_height(pps,GTK_UNIT_POINTS):0.0);//~v970I~
	}                                                              //~v970I~
    return pps;                                                    //~vamuI~//~v970I~
}//lnx_srchGtkPaperSize                                            //~v970I~
//===============================================================================//~v9h0I~
#else 	//NOPPD                                                    //~v9h0I~
//===============================================================================//~v9h0I~
//************************************************************************************//~v9h0I~
cups_dest_t* xplnxp_cupsGetPPD(char *Pprinter,cups_dest_t **Ppdests,int *Ppctr)//~v9h0R~
{                                                                  //~v9h0I~
	cups_dest_t *dests,*dest;                                      //~v9h0I~
    //*******************                                          //~v9h0I~
    int ctr=cupsGetDests2(CUPS_HTTP_DEFAULT,&dests); /* Number of destinations *///~v9h0I~
    UTRACEP("xplnxp_cupsGetPPD printer=%s,destCtr=%d\n",Pprinter,ctr);//~v9h0I~
    dest=cupsGetDest(Pprinter,NULL/*instancename*/,ctr,dests);     //~v9h0I~
    *Ppdests=dests;                                                //~v9h0R~
    *Ppctr=ctr;                                                    //~v9h0R~
    return dest;                                                   //~v9h0R~
}                                                                  //~v9h0I~
//************************************************************************************//~v9h0I~
void xplnxp_ppdClose(cups_dest_t *Pdests,int Pctr,http_t *Phttp,cups_dinfo_t *Pdinfo)//~v9h0I~
{                                                                  //~v9h0I~
    UTRACEP("xplnxp_ppdClose\n");                                  //~v9h0I~
    if (Pdests)                                                    //~v9h0I~
        cupsFreeDests(Pctr,Pdests);                                //~v9h0I~
	if (Phttp)                                                     //~v9h0I~
	    httpClose(Phttp);                                          //~v9h0I~
	if (Pdinfo)                                                    //~v9h0I~
	    cupsFreeDestInfo(Pdinfo);                                  //~v9h0I~
}                                                                  //~v9h0I~
//************************************************************************************//~v9h0I~
http_t* xplnxp_ppdOpenFile(cups_dest_t *Pdest,cups_dinfo_t **Ppdinfo)//~v9h0R~
{                                                                  //~v9h0I~
  	cups_dinfo_t  *dinfo;         /* Destination info */           //~v9h0I~
	http_t    *http;          /* Connection to destination */      //~v9h0I~
    //******************                                           //~v9h0I~
    UTRACEP("xplnxp_ppdOpenFile\n");                               //~v9h0I~
  	if ((http=cupsConnectDest(Pdest,0/*dflags*/,30000/*timeout*/, NULL, NULL, 0, NULL, NULL)) == NULL)//~v9h0I~
    	return NULL;                                               //~v9h0R~
  	dinfo=cupsCopyDestInfo(http,Pdest);                            //~v9h0I~
    *Ppdinfo=dinfo;                                                //~v9h0I~
    return http;                                                   //~v9h0I~
}                                                                  //~v9h0I~
//************************************************************************************
int getMediaCount(cups_dest_t *Pdest,http_t *Phttp,cups_dinfo_t *Pdinfo)//~v9h0I~
{
	int ctr,flags=0;                                               //~v9h0I~
    //***********************
	ctr=cupsGetDestMediaCount(Phttp,Pdest,Pdinfo,(unsigned)flags); //~v9h0R~
	UTRACEP("getMediaCount mediaCtr=%d\n",ctr);                    //~v9h0I~
    return ctr;                                                    //~v9h0I~
}                                                                  //~v9h0I~
//************************************************************************************//~v9h0I~
PageSize *getPageSize(cups_dest_t *Pdest,http_t *Phttp,cups_dinfo_t *Pdinfo)//~v9h0R~
{                                                                  //~v9h0I~
	int ii,count,flags=0,nondupctr=0;                              //~v9h0I~
    char dupchk[256]={0};                                          //~v9h0I~
  	cups_size_t   size;                                            //~v9h0I~
    PageSize *ppgsz,*ppgsz0;                                       //~v9h0I~
    //***********************                                      //~v9h0I~
	count = cupsGetDestMediaCount(Phttp,Pdest,Pdinfo,(unsigned)flags);//~v9h0R~
	UTRACEP("getPageSize mediaCtr=%d\n",count);                    //~v9h0I~
    for (ii=0;ii<count;ii++)                                       //~v9h0I~
    {                                                              //~v9h0I~
    	if (cupsGetDestMediaByIndex(Phttp,Pdest,Pdinfo,ii,(unsigned)flags,&size))//~v9h0R~
        {                                                          //~v9h0I~
          	if (strcmp(dupchk,size.media))                         //~v9h0I~
            {                                                      //~v9h0I~
	        	UTRACEP("getPageSize  %s (%s)\n", size.media, cupsLocalizeDestMedia(Phttp,Pdest,Pdinfo,(unsigned)flags,&size));//~v9h0R~
                nondupctr++;                                       //~v9h0I~
	            strcpy(dupchk,size.media);                         //~v9h0I~
            }                                                      //~v9h0I~
        }                                                          //~v9h0I~
      	else                                                       //~v9h0I~
	        UTRACEP("getPageSize error");                          //~v9h0I~
    }                                                              //~v9h0I~
    ppgsz0=ppgsz=(PageSize*)umalloc(SZ_PAGESIZE*(size_t)nondupctr);//~v9h0R~
    *dupchk=0;                                                     //~v9h0I~
    for (ii=0;ii<count;ii++)                                       //~v9h0I~
    {                                                              //~v9h0I~
    	if (cupsGetDestMediaByIndex(Phttp,Pdest,Pdinfo,ii,(unsigned)flags, &size))//~v9h0R~
        {                                                          //~v9h0I~
          	if (strcmp(dupchk,size.media))                         //~v9h0I~
            {                                                      //~v9h0I~
            	ppgsz->displayname=(char*)cupsLocalizeDestMedia(Phttp,Pdest,Pdinfo,(unsigned)flags,&size);//~v9h0R~
            	strncpy(ppgsz->ppdsz.name,size.media,sizeof(ppgsz->ppdsz.name));//~v9h0R~
            	ppgsz->ppdsz.width=(float)size.width;              //~v9h0R~
            	ppgsz->ppdsz.length=(float)size.length;            //~v9h0R~
            	ppgsz->ppdsz.top=(float)size.top;                  //~v9h0R~
            	ppgsz->ppdsz.left=(float)size.left;                //~v9h0R~
            	ppgsz->ppdsz.bottom=(float)size.bottom;            //~v9h0R~
            	ppgsz->ppdsz.right=(float)size.right;              //~v9h0R~
                ppgsz++;                                           //~v9h0I~
	            strcpy(dupchk,size.media);                         //~v9h0I~
            }                                                      //~v9h0I~
        }                                                          //~v9h0I~
    }                                                              //~v9h0I~
    return ppgsz0;                                                 //~v9h0R~
}                                                                  //~v9h0I~
//************************************************************************************//~v9h0I~
GtkPaperSize *lnx_srchGtkPaperSize(int Popt,char *Pprinter,char *Ppform,PFRECT Ppfmargin)//~v9h0I~
{                                                                  //~2B03aI~//~v9h0I~
    int ii=0,formno;                                               //~v9h0I~
//  char *pppdnm;                                                  //~v9h0I~
    cups_dest_t *pppdnm,*destS;                                    //~v9h0R~
    int destCtr;                                                   //~v9h0I~
//  ppd_file_t *ppd=NULL;                                          //~v9h0I~
    http_t     *ppd;                                               //~v9h0I~
    cups_dinfo_t  *dinfo;                                          //~v9h0I~
    ppd_size_t *ppgsz;                                             //~v9h0R~
    PageSize *pPageSz,*pPageSz0;                                   //~v9h0R~
    GtkPaperSize *pps=NULL;                                        //~v9h0I~
    const char *pname;                                             //~v9h0I~
    char *pdisplayname;                                            //~v9h0I~
    FRECT fmargin={0.0,0.0,0.0,0.0};                               //~v9h0I~
    int partialmatchctr=0,rc2;                                     //~v9h0I~
	double fww,fhh;                                                //~v9h0I~
//************************************                             //~v9h0I~
    UTRACEP("lnx_srchGtkPaperSize parm opt=%x,printer=%s,form=%s\n",Popt,Pprinter,Ppform);//~v9h0I~
    if (!*Ppform)                                                  //~v9h0I~
    	Ppform=DEFAULT_PAPER;                                      //~v9h0I~
#ifdef GTKV2120                                                    //~v9h0I~
	if (!lnx_srchGtkPaperSize_212(Popt,Pprinter,Ppform,Ppfmargin,&pps))//~v9h0I~
    {                                                              //~v9h0I~
  	  if (!(Gtraceopt && *Ppform=='?'))                            //~v9h0I~
    	return pps;                                                //~v9h0I~
    }                                                              //~v9h0I~
#endif                                                             //~v9h0I~
    for (;;)                                                       //~v9h0I~
    {                                                              //~v9h0I~
//      pppdnm=(char *)cupsGetPPD((const char *)Pprinter);         //~v9h0I~
//      UTRACEP("lnx_srchGtkPaperSize ppdnm=%s\n",pppdnm);         //~v9h0I~
        pppdnm=xplnxp_cupsGetPPD(Pprinter,&destS,&destCtr);	//dest //~v9h0R~
        if (!pppdnm)    //dest                                     //~v9h0R~
            uerrexit("\"%s\" not found(cupsGetPPD failed or No printer defined)",0,//~v9h0I~
            			Pprinter);                                 //~v9h0I~
//      ppd=ppdOpenFile(pppdnm);                                   //~v9h0I~
        ppd=xplnxp_ppdOpenFile(pppdnm,&dinfo);  //http             //~v9h0R~
        if (!ppd)                                                  //~v9h0I~
//          uerrexit("printer:%s is defined, but ppdOpenFile failed.",0,Pprinter);//~v9h0I~
            uerrexit("printer:%s is defined, but connection failed.",0,Pprinter);//~v9h0R~
        if (!dinfo)                                                //~v9h0I~
            uerrexit("printer:connected to %s, but failed to get information.",0,Pprinter);//~v9h0I~
//      formno=ppd->num_sizes;                                     //~v9h0R~
        formno=getMediaCount(pppdnm/*dest*/,ppd/*http*/,dinfo);    //~v9h0R~
        UTRACEP("lnx_srchGtkPaperSize ppd count=%d\n",formno);     //~v9h0I~
//      ppgsz=ppd->sizes;                                          //~v9h0R~
        if (!formno)                                               //~v9h0I~
            uerrexit("No form is defined on printer:%s",0,Pprinter);//~v9h0I~
        pPageSz=getPageSize(pppdnm/*dest*/,ppd/*http*/,dinfo);     //~v9h0R~
//      pPageSz0=pPageSz0;                                         //~v9h0R~
        pPageSz0=pPageSz;                                          //~v9h0I~
	    Scupspaperlistsize=formno;                                 //~v9h0I~
//      for (ii=formno;ii>0;ii--,ppgsz++)                          //~v9h0R~
        for (ii=formno;ii>0;ii--,pPageSz++)                        //~v9h0R~
        {                                                          //~v9h0I~
//          UTRACEP("lnx_srchGtkPaperSize name=%s,w=%f,h=%f,t=%f,b=%f,l=%f,r=%f\n",ppgsz->name,ppgsz->width,ppgsz->length,ppgsz->top,ppgsz->bottom,ppgsz->left,ppgsz->right);//~v9h0R~
//          pdisplayname=getdisplayname(ppd,ppgsz->name);          //~v9h0R~
            pdisplayname=pPageSz->displayname;                     //~v9h0R~
            ppgsz=&(pPageSz->ppdsz);                               //~v9h0R~
            pname=ppgsz->name;                                     //~v9h0I~
            UTRACEP("lnx_srchGtkPaperSize parm=%s,displayname=%s\n",Ppform,pdisplayname);//~v9h0I~
			UTRACEP("comp %s:%s-%s\n",Ppform,pname,pdisplayname);  //~v9h0I~
            UTRACEP("ppd %s margin t=%f,b=%f,l=%f,r=%f\n",pname,   //~v9h0I~
                            ppgsz->length-ppgsz->top,ppgsz->bottom,//~v9h0I~
                            ppgsz->left,ppgsz->width-ppgsz->right);//~v9h0I~
            if (*Ppform=='?')                                      //~v9h0I~
            {                                                      //~v9h0I~
        		UTRACEP("ppd name %s\n",ppgsz->name);              //~v9h0I~
				printPaperSize((char*)pname,(char*)pdisplayname);  //~v9h0I~
  				if (Gtraceopt)      //trace option by /Yt          //~v9h0I~
                	printf("ppd PaperSize:%s=%s,w=%f,h=%f,t=%f,b=%f,l=%f,r=%f\n",//~v9h0I~
                    		pname,pdisplayname,                    //~v9h0I~
            				ppgsz->width,ppgsz->length,            //~v9h0I~
                            ppgsz->length-ppgsz->top,ppgsz->bottom,//~v9h0I~
                            ppgsz->left,ppgsz->width-ppgsz->right);//~v9h0I~
            }                                                      //~v9h0I~
            else                                                   //~v9h0I~
          {                                                        //~v9h0I~
        	rc2=comparePaperSize(Ppform,(char*)pname,(char*)pdisplayname);//~v9h0I~
            if (!rc2 || (rc2==1 && partialmatchctr==0))            //~v9h0I~
            {                                                      //~v9h0I~
				UTRACEP("paper found %s [\"%s\"]\n",pname,pdisplayname);//~v9h0I~
				UTRACEP("ww=%f,hh=%f point\n",ppgsz->width,ppgsz->length);//~v9h0I~
				UTRACEP("ppds margin t=%f,b=%f,l=%f,r=%f\n",ppgsz->top,ppgsz->bottom,ppgsz->left,ppgsz->right);//~v9h0I~
//*ppd_size_t:value is by point and BottomLeft origin              //~v9h0I~
                fmargin.top=ppgsz->top;                            //~v9h0I~
                fmargin.bottom=ppgsz->bottom;                      //~v9h0I~
                fmargin.left=ppgsz->left;                          //~v9h0I~
                fmargin.right=ppgsz->right;                        //~v9h0I~
  				pname=lnx_getcupspapername(Ppform);   //papername from displayname//~v9h0I~
//              {                                                  //~v9h0R~
				    if (Sshiftdirection && !(Popt & SGPSO_NOSHIFT))//~v9h0I~
						pps=getCustomPapersize(Ppform,(char *)pname,ppgsz,&fmargin);//~v9h0I~
                    else                                           //~v9h0I~
  	    				pps=gtk_paper_size_new(pname);             //~v9h0I~
					UTRACEP("ppsnew %s %sn",gtk_paper_size_get_name(pps),gtk_paper_size_get_display_name(pps));//~v9h0I~
					fww=gtk_paper_size_get_width(pps,GTK_UNIT_MM); //~v9h0I~
					fhh=gtk_paper_size_get_height(pps,GTK_UNIT_MM);//~v9h0I~
                    fww=fww; fhh=fhh;                              //~v9h0I~
					UTRACEP("ppsnew ww=%f,hh=%f\n",fww,fhh);       //~v9h0I~
//#ifdef MMM                                                       //~v9h0R~
//                    if (Sshiftdirectionorigin)                   //~v9h0R~
//                        shiftpaperorigin(fww,fhh,&Sxshift,&Syshift);//~v9h0R~
//#endif                                                           //~v9h0R~
//              }                                                  //~v9h0R~
              if (!rc2)                                            //~v9h0I~
              {                                                    //~v9h0I~
	            partialmatchctr=0;	//for the case matched partial at previous iter//~v9h0I~
            	break;                                             //~v9h0I~
              }                                                    //~v9h0I~
              if (rc2==1)                                          //~v9h0I~
        	      partialmatchctr++;                               //~v9h0I~
            }                                                      //~v9h0I~
          }//!"?"                                                  //~v9h0I~
        }                                                          //~v9h0I~
        break;                                                     //~v9h0I~
    }                                                              //~v9h0I~
//  if (ppd)                                                       //~v9h0R~
//      ppdClose(ppd);                                             //~vamuI~//~v970I~                   0//~v9h0R~
    xplnxp_ppdClose(destS,destCtr,ppd,dinfo);                            //~vamuI~//~v970I~                   0//~v9h0R~
    if (*Ppform!='?')                                              //~v9h0I~
    {                                                              //~v9h0I~
    	if (partialmatchctr>1)                                     //~v9h0I~
        	uerrexit("Papersize:\"%s\" is ambiguous(match with multiple papers)",0,//~v9h0I~
            			Ppform);                                   //~v9h0I~
                                                                   //~v9h0I~
      if (pps)	//found on ppd                                     //~v9h0I~
	    if (Ppfmargin)                                             //~v9h0I~
        {                                                          //~v9h0I~
#ifndef MMM                                                        //~v9h0I~
			applyparmmargin(&fmargin,gtk_paper_size_get_width(pps,GTK_UNIT_POINTS),gtk_paper_size_get_height(pps,GTK_UNIT_POINTS));//~v9h0I~
#endif                                                             //~v9h0I~
    		*Ppfmargin=fmargin;                                    //~v9h0I~
            UTRACEP("lnx_srchGtkPaperSize margin  t=%f,b=%f,l=%f,r=%f\n",fmargin.top,fmargin.bottom,fmargin.left,fmargin.right);//~v9h0I~
        }                                                          //~v9h0I~
    	UTRACEP("lnx_srchGtkPaperSize iscustom=%d,w=%f point,h=%f point\n",//~v9h0I~
    			pps?gtk_paper_size_is_custom(pps):0,               //~v9h0I~
				pps?gtk_paper_size_get_width(pps,GTK_UNIT_POINTS):0.0,//~v9h0I~
				pps?gtk_paper_size_get_height(pps,GTK_UNIT_POINTS):0.0);//~v9h0I~
	}                                                              //~v9h0I~
    ufree(pPageSz0);                                               //~v9h0I~
    return pps;                                                    //~v9h0I~
}//lnx_srchGtkPaperSize                                            //~v9h0I~
#endif  //NOPPD                                                    //~v9h0I~
//===============================================================================//~v973I~
//=get printer for formchk                                         //~v973I~
//return default if -q is not yet specified                        //~v973I~
//===============================================================================//~v973I~
int                                                               //~v973I~//~v970R~
lnx_getprinterFormchk()                                            //~v973I~
{                                                                  //~v973I~
	int rc;                                                        //~v970I~
//**************************                                       //~v973I~
    UTRACEP("lnx_getprinterFormchk Sdest=%s\n",Gqparm);            //~v973R~
    if (Gqparm)                                                    //~v973I~
    	UstrncpyZ(Sdest,Gqparm,sizeof(Sdest));                     //~v973R~
	rc=lnx_portchk(Sdest);	//set desfault printer to Sdest            //~v973R~//~v970R~
    if (!rc && Gqparm)                                             //~v970I~
    	uerrexit("%s is invalid destination. (\"%cQ?\" will show destination list.) ",                      //~v970I~//~v979R~
    		      "宛先 %s が見つかりません. (\"%cQ?\" でリストされます)",//~v979I~
            	Gqparm,CMDFLAG_PREFIX);                            //~v970I~//~v979R~
    UTRACEP("lnx_getprinterFormchk rc=%d,Sdest=%s\n",rc,Sdest);             //~v973I~//~v970R~
    return rc;                                                     //~v970I~
}//lnx_getprinterFormchk                                           //~v973I~
//===============================================================================//~v973I~
//=form parm chk                                                   //~v973I~
//chk shift parm and drop it                                       //~v977I~
//rc:0:portrait,1:landscape,-1:err                                 //~v973I~
//===============================================================================//~v973I~
int                                                                //~v973I~
lnx_formchk(char *Pform)                                           //~v973I~
{                                                                  //~v973I~
	int rc=-1;                                                     //~v973R~//~v970R~
    char *pc;                                                 //~v973I~//~v977R~
//  ppd_size_t *ppdsz;                                             //~v973I~//~v970R~
    GtkPaperSize *pps;                                             //~v970R~
//**************************                                       //~v973I~
    UTRACEP("%s:form=%s\n",UTT,Pform);                        //~v973I~//~v9j4R~
    pc=strchr(Pform,'/');                                          //~v977I~
    if (pc)                                                        //~v977I~
    {                                                              //~v977I~
        getshiftparm(pc+1);                                        //~v977R~
    	*pc=0;                                                     //~v977I~
    }                                                              //~v977I~
#ifdef AAA                                                         //~v973I~
	papername=lnx_getcupspapername(Pform);                         //~v973I~
#else  	//search in printer specific papersize                     //~v973I~
	lnx_getprinterFormchk();	//set Sdest (printername)          //~v973I~//~v970R~
//  ppdsz=lnx_srchcupsformPrinter(0/*opt*/,Sdest,Pform);           //~v973R~//~v970R~
    pps=lnx_srchGtkPaperSize(SGPSO_NOSHIFT,Sdest,Pform,NULL);                    //~v970R~//~v977R~
#endif                                                             //~v973I~
    if (*Pform=='?')                                               //~v973I~
    	uerrexit("== for %s, %d paper-size was listed.\n(specify %cQ parameter if the printer is not current destination)",//~v973I~//~v970R~
    	         "== プリンタ:%s, %d 個の用紙サイズをリスト。\n(宛先のプリンタが違う場合は %cQ を指定してください)",//~v970I~
                 Sdest,Scupspaperlistsize,CMDFLAG_PREFIX);//~v973I~//~v970R~
//  if (ppdsz)                                                     //~v973R~//~v970R~
    if (pps)                                                       //~v970I~
    {                                                              //~v973I~
    	pc=strdup(Pform);                                          //~v973I~
        rc=0;	//portrait                                         //~v973I~
    }                                                              //~v973I~
    else                                                           //~v973I~
    if (toupper(*(Pform+strlen(Pform)-1))=='L')                    //~v973I~
    {                                                              //~v973I~
    	pc=strdup(Pform);                                          //~v973I~
        *(pc+strlen(pc)-1)=0;                                      //~v973I~
#ifdef AAA                                                         //~v973I~
		papername=lnx_getcupspapername(pc);                        //~v973I~
#else                                                              //~v973I~
//  	ppdsz=lnx_srchcupsformPrinter(0/*opt*/,Sdest,pc);          //~v973R~//~v970R~
    	pps=lnx_srchGtkPaperSize(SGPSO_NOSHIFT,Sdest,pc,NULL/*margin*/);         //~v970R~//~v977R~
#endif                                                             //~v973I~
//      if (ppdsz)                                                 //~v973R~//~v970R~
        if (pps)                                                   //~v970I~
	    	rc=1; //landscape                                      //~v973R~
    }                                                              //~v973I~//~v977M~
    if (rc==-1)                                                    //~v977R~
            uerrexit("%s is not defined on %s, use %cE/? to list papersize or confirm destination(%cQ).",//~v970I~
                     "%s は %s で定義されていません、%cE/? で用紙をリストするか宛先プリンタ(%cQ)を確認してください",//~v970I~
//                  Pform,Sdest,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX);//~v970I~//~v992R~
                    Pform,Sdest,CMDFLAG_PREFIX,CMDFLAG_PREFIX);    //~v992I~
    Gpapersizeparm=pc;                                             //~v977I~
//  Scupspapersizename=pc;                                         //~v98aR~
    Scupspaperorientation=rc;                                      //~v973I~
    UTRACEP("lnx_formchk Gpapersizeparm=%s Pform=%s Gformtype=%x,rc=%d\n",Gpapersizeparm,Pform,Gformtype,rc);//~v977I~
    return rc;                                                     //~v973I~
}//lnx_formchk                                                     //~v973R~
//===============================================================================//~v970I~
//=form parm chk                                                   //~v970I~
//rc:0:portrait,1:landscape,-1:err                                 //~v970I~
//===============================================================================//~v970I~
void                                                               //~v970I~
lnx_papersizeinit()                                                //~v970I~
{                                                                  //~v970I~
//  ppd_size_t *ppdsz;                                             //~v970R~
    char *pform;                                                   //~v970I~
    GtkPaperSize *pps;                                             //~v970R~
//**************************                                       //~v970I~
	pform=Gpapersizeparm;                                          //~v970R~
    if (!pform || !*pform)                                         //~v970I~
    	pform=DEFAULT_PAPER;                                       //~v970I~
    UTRACEP("%s:form=%s,dest=%s\n",UTT,pform,Sdest);    //~v988R~  //~v9j4R~
//  ppdsz=lnx_srchcupsformPrinter(0/*opt*/,Sdest,pform);           //~v970R~
//  pps=lnx_srchGtkPaperSize(SGPSO_NOSHIFT,Sdest,DEFAULT_PAPER,&SfmarginsA4);//~v977R~//~v98mR~
    pps=lnx_srchGtkPaperSize(SGPSO_NOSHIFT|SGPSO_GETDEFAULTPAPERSIZE,Sdest,DEFAULT_PAPER,&SfmarginsA4);//~v98mI~
	if (!Gpapersizeparm||!*Gpapersizeparm)                         //~v98mR~
    	pform=Sprinterdefaultpapersize;                            //~v98mI~
    UTRACEP("%s:default=%s\n",UTT,gtk_paper_size_get_name(pps));//~v98mI~//~v9j4R~
//  SpagewidthA4=gtk_paper_size_get_width(pps,GTK_UNIT_POINTS);    //~v977R~//~v9a0R~
    SpagewidthA4=(int)gtk_paper_size_get_width(pps,GTK_UNIT_POINTS);//~v9a0I~
//  SpageheightA4=gtk_paper_size_get_height(pps,GTK_UNIT_POINTS);  //~v977R~//~v9a0R~
    SpageheightA4=(int)gtk_paper_size_get_height(pps,GTK_UNIT_POINTS);//~v9a0I~
    UTRACEP("%s:default w=%lf,h=%lf\n",UTT,SpagewidthA4,SpageheightA4);//~v977R~//~v98mR~//~v9j4R~
    pps=lnx_srchGtkPaperSize(0,Sdest,pform,&Sfmargins);              //~v970R~//~v977R~
//  if (!ppdsz)                                                    //~v970R~
    if (!pps)                                                      //~v970I~
    	uerrexit("Paper %s is not available for %s. \"-E/?\" will list available paper size.",//~v976R~
        		"用紙 %s は %s では利用できません. \"-E/?\" で 用紙がリストされます",//~v976I~
        	pform,Sdest);                                          //~v970I~
//  Sppdsz=ppdsz;                                                  //~v970R~
    Sppapersz=pps;                                                 //~v970I~
    UTRACEP("lnx_papersizeinit Spapersize=%s\n",gtk_paper_size_get_name(pps));//~v98mI~
}//lnx_papersizeinit                                               //~v970I~
//===============================================================================//~va20I~//~v970M~
void                                                               //~v970M~
getglyphextent(PangoFont *Ppfont,PangoLayout *Pplayout,char *Putf8,int Plen,PangoRectangle *Pprect)//~v970R~
{                                                                  //~va20I~//~v970M~
#ifndef AAA                                                        //~v970I~
#else                                                              //~v970I~
  	GSList *tmp_list;                                              //~va20I~//~v970M~
  	PangoLayoutIter *iter;                                         //~va20I~//~v970M~
    PangoLayoutLine *line;                                         //~va20I~//~v970M~
    PangoLayoutRun *run;                                           //~va20I~//~v970M~
    PangoGlyphString *pglyphstr;                                   //~va20I~//~v970M~
#endif                                                             //~v970I~
    PangoRectangle inkrect,logicalrect;                            //~v970M~
//******************************                                   //~va20I~//~v970M~
UTRACEP("chkglyphextent str=%s\n",Putf8);                                         //~va20I~//~v970M~
	pango_layout_set_text(Pplayout,Putf8,Plen);                    //~v970M~
#ifndef AAA                                                        //~v970I~
    pango_layout_get_extents(Pplayout,&inkrect,&logicalrect);      //~v97pR~
	UTRACEP("layout inkrect x=%lf,y=%lf,w=%lf,h=%lf\n",(double)inkrect.x/PANGO_SCALE,(double)inkrect.y/PANGO_SCALE,(double)inkrect.width/PANGO_SCALE,(double)inkrect.height/PANGO_SCALE);//~v970I~
	UTRACEP("layout logrect x=%lf,y=%lf,w=%lf,h=%lf\n",(double)logicalrect.x/PANGO_SCALE,(double)logicalrect.y/PANGO_SCALE,(double)logicalrect.width/PANGO_SCALE,(double)logicalrect.height/PANGO_SCALE);//~v970I~
#else                                                              //~v970I~
  	iter = pango_layout_get_iter(Pplayout);                        //~va20I~//~v970M~
    line=pango_layout_iter_get_line (iter);                        //~va20I~//~v970M~
    if (!line)  //split dbcs is set to layout                      //~va20I~//~v970M~
        return;                                                    //~va20I~//~v970M~
    tmp_list=line->runs;                                           //~va20I~//~v970M~
  	while(tmp_list)                                                //~va20I~//~v970M~
  	{                                                              //~va20I~//~v970M~
    	run=tmp_list->data;                                        //~va20I~//~v970M~
		UTRACEP("run @@@=%p\n",run);                               //~va20I~//~v970M~
    	if (!run)  //split dbcs is set to layout                   //~va20I~//~v970M~
        	return;                                                //~va20I~//~v970M~
    	pglyphstr=run->glyphs;                                     //~va20I~//~v970M~
    	if (!pglyphstr)  //split dbcs is set to layout             //~va20I~//~v970M~
        	return;                                                //~va20I~//~v970M~
        pango_glyph_string_extents(pglyphstr,Ppfont,&inkrect,&logicalrect);//~v970I~
		UTRACEP("inkrect x=%lf,y=%lf,w=%lf,h=%lf\n",(double)inkrect.x/PANGO_SCALE,(double)inkrect.y/PANGO_SCALE,(double)inkrect.width/PANGO_SCALE,(double)inkrect.height/PANGO_SCALE);//~v970I~
		UTRACEP("logrect x=%lf,y=%lf,w=%lf,h=%lf\n",(double)logicalrect.x/PANGO_SCALE,(double)logicalrect.y/PANGO_SCALE,(double)logicalrect.width/PANGO_SCALE,(double)logicalrect.height/PANGO_SCALE);//~v970R~
    	tmp_list=tmp_list->next;                                   //~va20I~//~v970M~
	}//runs                                                          //~va20I~//~v970M~
  	pango_layout_iter_free (iter);                                 //~va20I~//~v970M~
#endif                                                             //~v970I~
    if (Pprect)                                                    //~v970I~
	    *Pprect=logicalrect;                                       //~v970I~
  	return;                                                        //~va20I~//~v970M~
}//getglyphextent                                                  //~v970M~//~v975R~
//===============================================================================//~v970M~
void                                                               //~v970M~
chkglyphextent(PangoFontDescription *Ppfd)                         //~v970I~
{                                                                  //~v970M~
    PangoLayout *playout;                                          //~v970I~
    PangoFont *pfont;                                              //~v970I~
//******************************                                   //~v970M~
UTRACEP("chkglyphextent pfd size=%lf\n",(double)pango_font_description_get_size(Ppfd)/PANGO_SCALE);//~v970R~
	pfont=pango_context_load_font(Sppangocontext,Ppfd);            //~v970I~
	playout=pango_layout_new(Sppangocontext);                      //~v970I~
    pango_layout_set_font_description(playout,Ppfd);               //~v970M~
    getglyphextent(pfont,playout,"A",1,NULL);                      //~v970R~
    getglyphextent(pfont,playout,"W",1,NULL);                      //~v970R~
    getglyphextent(pfont,playout,"P",1,NULL);                      //~v970R~
    getglyphextent(pfont,playout,"0",1,NULL);                      //~v970R~
    getglyphextent(pfont,playout,"g",1,NULL);                      //~v976I~
    g_object_unref(playout);                                       //~v970I~
}//chkglyphextent                                                  //~v970M~
//===============================================================================//~v975I~
void                                                               //~v975I~
chkstringextent(char *Pstr,int Plen)                               //~v975I~
{                                                                  //~v975I~
    PangoLayout *playout;                                          //~v975I~
    PangoFont *pfont;                                              //~v975I~
    PangoRectangle rect;                                           //~v975I~
//******************************                                   //~v975I~
	pfont=pango_context_load_font(Sppangocontext,Sppangofd);       //~v975I~
	playout=pango_layout_new(Sppangocontext);                      //~v975I~
    pango_layout_set_font_description(playout,Sppangofd);          //~v975I~
    getglyphextent(pfont,playout,Pstr,Plen,&rect);                 //~v975I~
    g_object_unref(playout);                                       //~v975I~
}//chkstringextent                                                 //~v975I~
//===============================================================================//~v975I~
int                                                                //~v975I~
lnx_ismonospace(PangoFontDescription *Ppfd)                        //~v975R~
{                                                                  //~v975I~
    PangoLayout *playout;                                          //~v975I~
    PangoFont *pfont;                                              //~v975I~
    PangoRectangle rect;                                           //~v975I~
    int ww1,ww2,www,wwz,rc;                                            //~v975I~//~v970R~
//******************************                                   //~v975I~
	pfont=pango_context_load_font(Sppangocontext,Ppfd);            //~v975I~
	playout=pango_layout_new(Sppangocontext);                      //~v975I~
    pango_layout_set_font_description(playout,Sppangofd);          //~v975I~
    getglyphextent(pfont,playout,"fi",2,&rect);                    //~v975I~
    ww2=rect.width;                                                //~v975I~
    getglyphextent(pfont,playout,"f",1,&rect);                     //~v975I~
    ww1=rect.width;                                                //~v975I~
    getglyphextent(pfont,playout,"W",1,&rect);                     //~v975I~
    www=rect.width;                                                //~v975R~
    getglyphextent(pfont,playout,"0",1,&rect);                     //~v970I~
    wwz=rect.width;                                                //~v970R~
    g_object_unref(playout);                                       //~v975I~
    rc=(ww2==ww1*2)&&(www==ww1)&&(www==wwz);                                   //~v975I~//~v970R~
    UTRACEP("lnx_ismonospace rc=%d,fi=%d,f=%d,f*2=%d,www=%d,wwz=%d\n",rc,ww2,ww1,ww1*2,www,wwz);//~v975I~//~v970R~
    return rc;                                                     //~v975I~
}//lnx_ismonospace                                                 //~v975I~
//===============================================================================//~v975I~
//=parm:by pango scale                                             //~v975I~
//===============================================================================//~v975I~
int                                                                //~v975I~
lnx_chkfontsize(int Pmonospace,PangoFontDescription *Ppfd,int *Ppww,int *Pphh)//~v975R~
{                                                                  //~v975I~
    PangoLayout *playout;                                          //~v975I~
    PangoFont *pfont;                                              //~v975I~
    PangoRectangle rect;                                           //~v975I~
    int ww,hh;                                                     //~v975I~
    char *pstr;                                                    //~v975I~
//******************************                                   //~v975I~
	ww=*Ppww;   //by fontmetrix                                    //~v975I~
	hh=*Pphh;                                                      //~v975I~
	pfont=pango_context_load_font(Sppangocontext,Ppfd);            //~v975I~
	playout=pango_layout_new(Sppangocontext);                      //~v975I~
    pango_layout_set_font_description(playout,Sppangofd);          //~v975I~
    if (Pmonospace)                                                //~v975I~
    {                                                              //~v975I~
    	pstr="A";                                                  //~v975I~
	    getglyphextent(pfont,playout,pstr,1,&rect);                //~v975I~
    	ww=rect.width;	                                           //~v975R~
    	UTRACEP("lnx_chkfontsize str=%s ww=%d\n",pstr,ww);         //~v970I~
    }                                                              //~v975I~
    else                                                           //~v975I~
    {                                                              //~v975I~
    	pstr="A";                                               //~v975I~//~v970R~
//      getglyphextent(pfont,playout,pstr,strlen(pstr),&rect);     //~v975I~//~v9a0R~
        getglyphextent(pfont,playout,pstr,(int)strlen(pstr),&rect);//~v9a0I~
//  	ww=rect.width/strlen(pstr);                                //~v975R~//~v9a0R~
    	ww=rect.width/(int)strlen(pstr);                           //~v9a0I~
    	UTRACEP("lnx_chkfontsize str=%s ww=%d\n",pstr,ww);         //~v970I~
    	pstr="W";                                                  //~v970I~
//      getglyphextent(pfont,playout,pstr,strlen(pstr),&rect);     //~v970I~//~v9a0R~
        getglyphextent(pfont,playout,pstr,(int)strlen(pstr),&rect);//~v9a0I~
//  	ww=rect.width/strlen(pstr);                                //~v970I~//~v9a0R~
    	ww=rect.width/(int)strlen(pstr);                           //~v9a0I~
    	UTRACEP("lnx_chkfontsize str=%s ww=%d\n",pstr,ww);         //~v970I~
    	pstr="P";                                                  //~v970I~
//      getglyphextent(pfont,playout,pstr,strlen(pstr),&rect);     //~v970I~//~v9a0R~
        getglyphextent(pfont,playout,pstr,(int)strlen(pstr),&rect);//~v9a0I~
//  	ww=rect.width/strlen(pstr);                                //~v970I~//~v9a0R~
    	ww=rect.width/(int)strlen(pstr);                           //~v9a0I~
    	UTRACEP("lnx_chkfontsize str=%s ww=%d\n",pstr,ww);         //~v970I~
    	pstr="0";                                                  //~v970I~
//	    getglyphextent(pfont,playout,pstr,strlen(pstr),&rect);     //~v970I~//~v9a0R~
  	    getglyphextent(pfont,playout,pstr,(int)strlen(pstr),&rect);//~v9a0I~
//  	ww=rect.width/strlen(pstr);                                //~v970I~//~v9a0R~
    	ww=rect.width/(int)strlen(pstr);                           //~v9a0I~
    	UTRACEP("lnx_chkfontsize str=%s ww=%d\n",pstr,ww);         //~v970I~
    	pstr="g";                                                  //~v976I~
//      getglyphextent(pfont,playout,pstr,strlen(pstr),&rect);     //~v976I~//~v9a0R~
        getglyphextent(pfont,playout,pstr,(int)strlen(pstr),&rect);//~v9a0I~
//  	ww=rect.width/strlen(pstr);                                //~v976I~//~v9a0R~
    	ww=rect.width/(int)strlen(pstr);                           //~v9a0I~
    	UTRACEP("lnx_chkfontsize str=%s ww=%d\n",pstr,ww);         //~v976I~
    	pstr="AWP0";                                               //~v970I~
//      getglyphextent(pfont,playout,pstr,strlen(pstr),&rect);     //~v970I~//~v9a0R~
        getglyphextent(pfont,playout,pstr,(int)strlen(pstr),&rect);//~v9a0I~
//  	ww=rect.width/strlen(pstr);                                //~v970I~//~v9a0R~
    	ww=rect.width/(int)strlen(pstr);                           //~v9a0I~
//        pstr="AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";//~v970R~
//        getglyphextent(pfont,playout,pstr,strlen(pstr),&rect);   //~v970R~
//        ww=rect.width/strlen(pstr);                              //~v970R~
    }                                                              //~v975I~
    g_object_unref(playout);                                       //~v975I~
    UTRACEP("lnx_chkfontsize monospace=%d,ww=%d<-%d,hh=%d<--%d\n",Pmonospace,ww,*Ppww,hh,*Pphh);//~v975I~
    *Ppww=ww;                                                      //~v975I~
    *Pphh=hh;                                                      //~v975I~
    return 0;                                                      //~v975R~
}//lnx_chkfontsize                                                 //~v975I~
//===============================================================================//~v970I~
void                                                               //~v970I~
chklayoutextent(PangoLayout *Pplayout,PangoRectangle *Pprect)                             //~v970I~//~v975R~
{                                                                  //~v970I~
    PangoRectangle inkrect,logicalrect;                            //~v970I~
//******************************                                   //~v970I~
    pango_layout_get_extents(Pplayout,&inkrect,&logicalrect);      //~v97pR~
	UTRACEP("%s:text=%s\n",UTT,pango_layout_get_text(Pplayout));   //~v9i0R~
	UTRACEP("%s:inkrect x=%lf,y=%lf,w=%lf,h=%lf\n",UTT,(double)inkrect.x/PANGO_SCALE,(double)inkrect.y/PANGO_SCALE,(double)inkrect.width/PANGO_SCALE,(double)inkrect.height/PANGO_SCALE);//~v9i0I~
	UTRACEP("%s:logrect x=%lf,y=%lf,w=%lf,h=%lf\n",UTT,(double)logicalrect.x/PANGO_SCALE,(double)logicalrect.y/PANGO_SCALE,(double)logicalrect.width/PANGO_SCALE,(double)logicalrect.height/PANGO_SCALE);//~v970R~//~v9i0R~
    if (Pprect)                                                    //~v975I~
    	*Pprect=logicalrect;                                       //~v975I~
}//chklayoutextent                                                 //~v970I~
//===============================================================================//~v970I~
//adjust scaling at newpage by header1                                                  //~v970I~//~v975R~
//ret linewidth/strwidth(shrink rate)                              //~v975I~
//===============================================================================//~v970I~
double                                                             //~v970I~
getstringxscale()                                                  //~v970I~
{                                                                  //~v970I~
    PangoLayout *playout;                                          //~v970I~
    PangoFont *pfont;                                              //~v970I~
    char *pc,*pc2;                                                 //~v970R~
    int len;                                                       //~v970I~
    PangoRectangle logrect;                                        //~v970R~
    double fstrwidth,frate;                                        //~v970I~//~v975R~
//************************************                             //~v970I~
    if (lineprefixsw)                                              //~v975I~
		pc=header1;                                                    //~v970R~//~v975R~
    else                                                           //~v975I~
		pc=header1+LINENOSZ+1;                                     //~v975I~
    pc2=strchr(pc,CRLF);                                           //~v970I~
    if (pc2)                                                       //~v970I~
    	len=PTRDIFF(pc2,pc);                                       //~v970I~
    else                                                           //~v970I~
//  	len=strlen(pc);                                            //~v970I~//~v9a0R~
    	len=(int)strlen(pc);                                       //~v9a0I~
	pfont=pango_context_load_font(Sppangocontext,Sppangofd);       //~v970R~
	playout=pango_layout_new(Sppangocontext);                      //~v970I~
    pango_layout_set_font_description(playout,Sppangofd);          //~v970I~
UTRACEP("getstringxscale wrap=%d\n",pango_layout_get_wrap(playout));//~v970I~
UTRACEP("getstringxscale iswrap=%d\n",pango_layout_is_wrapped(playout));//~v970I~
UTRACEP("getstringxscale ellipsiz=%d\n",pango_layout_get_ellipsize(playout));//~v970I~
UTRACEP("getstringxscale isllipsize=%d\n",pango_layout_is_ellipsized(playout));//~v970I~
UTRACEP("getstringxscale alligment=%d\n",pango_layout_get_alignment(playout));//~v970R~
UTRACEP("getstringxscale justify=%d\n",pango_layout_get_justify(playout));//~v970I~
UTRACEP("getstringxscale indent=%d\n",pango_layout_get_indent(playout));//~v970I~
UTRACEP("getstringxscale getwidth=%d\n",pango_layout_get_width(playout));//~v970I~
UTRACEP("getstringxscale getheight=%d\n",pango_layout_get_height(playout));//~v970I~
UTRACEP("getstringxscale getspacing=%d\n",pango_layout_get_spacing(playout));//~v970I~
UTRACEP("getstringxscale colwidth=%d\n",(int)(PANGO_SCALE*maxcol*Scharwidthf));//~v98hR~
//  pango_layout_set_width(playout,(int)(PANGO_SCALE*len*Scharwidthf));	//@@@@test//~v970R~//~v975R~
//  pango_layout_set_ellipsize(playout,PANGO_ELLIPSIZE_END);	//@@@@test//~v970R~//~v975R~
	getglyphextent(pfont,playout,pc,len,&logrect);                 //~v970R~
UTRACEP("getstringxscale wrap=%d\n",pango_layout_get_wrap(playout));//~v970I~
UTRACEP("getstringxscale iswrap=%d\n",pango_layout_is_wrapped(playout));//~v970I~
UTRACEP("getstringxscale ellipsiz=%d\n",pango_layout_get_ellipsize(playout));//~v970I~
UTRACEP("getstringxscale isllipsize=%d\n",pango_layout_is_ellipsized(playout));//~v970I~
UTRACEP("getstringxscale alligment=%d\n",pango_layout_get_alignment(playout));//~v970I~
UTRACEP("getstringxscale justify=%d\n",pango_layout_get_justify(playout));//~v970I~
UTRACEP("getstringxscale indent=%d\n",pango_layout_get_indent(playout));//~v970I~
UTRACEP("getstringxscale getwidth=%d\n",pango_layout_get_width(playout));//~v970I~
UTRACEP("getstringxscale getheight=%d\n",pango_layout_get_height(playout));//~v970I~
UTRACEP("getstringxscale getspacing=%d\n",pango_layout_get_spacing(playout));//~v970I~
    fstrwidth=(double)logrect.width/PANGO_SCALE;               //~v970R~//~v975R~
    frate=Slinewidthf/fstrwidth;//>1 line overflow                 //~v975R~
    UTRACEP("getstringxscale ret=%lf=Slinewidthf(%lf)/fstrwidth(%lf)\n",frate,Slinewidthf,fstrwidth);//~v970I~//~v975R~
    g_object_unref(playout);                                       //~v970I~
    return frate;                                                  //~v970R~
}//getstringxscale                                                 //~v970I~
//===============================================================================//~v970I~
//set layout with and wrap mode                                    //~v970I~
//===============================================================================//~v970I~
void                                                               //~v970I~
lnx_setlayoutoption()                                              //~v970R~
{                                                                  //~v970I~
	int linenolen;                                                 //~v970R~
    double flinenowidth,ftextwidth;                                //~v970I~
//*********************************                                //~v970I~
	if (!Sflushphase)                                              //~v970I~
		return;                                                    //~v970I~
	linenolen=LINENOSZ+1;                                          //~v970I~
    SplayoutLineno=pango_layout_copy(Splayout);                    //~v970R~
    flinenowidth=linenolen*Scharwidthf;                            //~v970I~
//  pango_layout_set_width(SplayoutLineno,(int)(flinenowidth*PANGO_SCALE));//~v970R~//~v975R~
//  pango_layout_set_alignment(SplayoutLineno,PANGO_ALIGN_RIGHT);//by glyph monospacing//~v970R~
//*set wrap mode                                                   //~v970I~
    ftextwidth=(Spagewidth-(Sleftmargin+Srightmargin));            //~v970I~
	if (lineprefixsw)                                              //~v970I~
        ftextwidth-=flinenowidth;                                  //~v970I~
//  pango_layout_set_width(Splayout,(int)(ftextwidth*PANGO_SCALE));//no wrap;adjust scale if overflow//~v975R~
	if (Gxpotheropt & GOO_ELLIPSIZE)	//cut if overflow page width//~v975I~
    	pango_layout_set_ellipsize(Splayout,PANGO_ELLIPSIZE_END);      //~v970R~//~v975R~
//  pango_layout_set_wrap(Splayout,PANGO_WRAP_CHAR);//@@@@test     //~v970R~
//*                                                                //~v970I~
	UTRACEP("lnx_setlayoutoption linenoprefixsw=%d,linenowidth=%lf,textwidth=%lf\n",lineprefixsw,flinenowidth,ftextwidth);//~v970I~
}//lnx_setlayoutoption                                             //~v970R~
//===============================================================================//~vX03M~//~v970I~
//set monospaceing(all SBCS)                                                 //~vX03M~//~v970I~
//===============================================================================//~vX03M~//~v970I~
void                                                               //~v970R~
usetmonospace(int Popt,PangoLayout *Pplayout,double Pcellw)        //~v970I~
{                                                                  //~vX03M~//~v970I~
  	GSList *tmp_list;                                              //~vX03M~//~v970I~
  	PangoLayoutIter *iter;                                         //~vX03M~//~v970I~
    PangoLayoutLine *line;                                         //~vX03M~//~v970I~
    PangoLayoutRun *run;                                           //~vX03M~//~v970I~
    PangoGlyphString *pglyphstr;                                   //~vX03M~//~v970I~
    PangoGlyphInfo *pglyphinfo;                                    //~vX03M~//~v970I~
    PangoGlyphGeometry *pgeom;                                     //~vX03M~//~v970I~
    int ii;                                                        //~vX03M~//~v970I~
    int wwpango,oldw;                                              //~v970R~
//  PangoGlyphGeometry *pgeomlast=NULL;                            //~vaffR~//~v980R~
//******************************                                   //~vX03M~//~v970I~
  	iter = pango_layout_get_iter(Pplayout);                        //~vX03R~//~v970I~
    line=pango_layout_iter_get_line (iter);                        //~vX03M~//~v970I~
UTRACEP("usetmonospace opt=%x,cellw=%lf\n",Popt,Pcellw);                //~va30R~//~v970R~
    if (!line)  //split dbcs is set to layout                      //~v69VR~//~v970I~
        return;                                                    //~v69VR~//~v970I~
    tmp_list=line->runs;                                           //~vX03M~//~v970I~
  while(tmp_list)                                                  //~v69VR~//~v970I~
  {                                                                //~v69VI~//~v970I~
    run=tmp_list->data;                                            //~vX03M~//~v970I~
//dprintf("run @@@=%p\n",run);                                     //~v69VR~//~v970I~
    if (!run)  //split dbcs is set to layout                       //~v69VR~//~v970I~
        return;                                                    //~v69VR~//~v970I~
    pglyphstr=run->glyphs;                                         //~vX03M~//~v970I~
    if (!pglyphstr)  //split dbcs is set to layout                 //~v69VR~//~v970I~
        return;                                                    //~v69VR~//~v970I~
	UTRACEP("temp list=%p\n",pglyphstr);                               //~va1cR~//~v970I~
	wwpango=(int)(Pcellw*PANGO_SCALE);                                    //~va30R~//~v970I~
    for (ii=pglyphstr->num_glyphs,pglyphinfo=pglyphstr->glyphs;ii>0;ii--,pglyphinfo++)//~vX03M~//~v970I~
    {                                                              //~vX03M~//~v970I~
        pgeom=&(pglyphinfo->geometry);                             //~vX03M~//~v970I~
//      pgeomlast=pgeom;                                           //~va30R~//~v980R~
UTRACEP("geometry ii=%d,offs_x=%d,offs_y=%d,width=%d new=%d\n",ii,pgeom->x_offset,pgeom->y_offset,pgeom->width,wwpango);//~va1cR~//~v970R~
		oldw=pgeom->width;                                         //~v970I~
	    pgeom->width=wwpango;                                      //~v970R~
        pgeom->x_offset-=(wwpango-oldw)/2;   //shift to left if enlarged,right if shrink//~v970R~
UTRACEP("geometry after,offs_x=%d,offs_y=%d,width=%d new=%d\n",pgeom->x_offset,pgeom->y_offset,pgeom->width,wwpango);//~v970R~
    }                                                              //~vX03M~//~v970I~
    tmp_list=tmp_list->next;                                       //~v69VI~//~v970I~
  }//runs                                                          //~v69VI~//~v970I~
  	pango_layout_iter_free (iter);                                 //~vX03M~//~v970I~
  	return;                                                        //~vX03M~//~v970I~
}//usetmonospace                                                   //~vX03I~//~v970I~
//===============================================================================//~v9i0I~
//trace layout                                                     //~v9i0I~
//===============================================================================//~v9i0I~
int                                                                //~v9j3R~
utracelayout(int Popt,PangoLayout *Pplayout)                       //~v9i0I~
{                                                                  //~v9i0I~
  	GSList *tmp_list;                                              //~v9i0I~
  	PangoLayoutIter *iter;                                         //~v9i0I~
    PangoLayoutLine *line;                                         //~v9i0I~
    PangoLayoutRun *run;                                           //~v9i0I~
    PangoGlyphString *pglyphstr;                                   //~v9i0I~
    PangoGlyphInfo *pglyphinfo;                                    //~v9i0I~
    PangoGlyphGeometry *pgeom;                                     //~v9i0I~
    int ii;                                                        //~v9i0I~
//******************************                                   //~v9i0I~
#ifdef NOTRACE                                                     //~v9j3I~
    if (1)                                                         //~v9j3I~
        return 0;                                                  //~v9j3R~
#endif                                                             //~v9j3I~
	int ww,hh;                                                     //~v9j1I~
	pango_layout_get_size(Pplayout,&ww,&hh);                       //~v9j1I~
	UTRACEP("%s:ww=%d(%d),hh=%d(%d),\ntext=%s\n",UTT,ww,ww/PANGO_SCALE,hh,hh/PANGO_SCALE,(char*)pango_layout_get_text(Pplayout));//~v9i0I~//~v9j1R~
  	iter = pango_layout_get_iter(Pplayout);                        //~v9i0I~
    line=pango_layout_iter_get_line (iter);                        //~v9i0I~
    if (!line)  //split dbcs is set to layout                      //~v9i0I~
        return 0;                                                  //~v9i0I~//~v9j3R~
    int wwtotal=0;                                                 //~v9j3I~
    tmp_list=line->runs;                                           //~v9i0I~
  while(tmp_list)                                                  //~v9i0I~
  {                                                                //~v9i0I~
    run=tmp_list->data;                                            //~v9i0I~
    if (!run)  //split dbcs is set to layout                       //~v9i0I~
        return 0;                                                  //~v9i0I~//~v9j3R~
    pglyphstr=run->glyphs;                                         //~v9i0I~
    if (!pglyphstr)  //split dbcs is set to layout                 //~v9i0I~
        return 0;                                                  //~v9i0I~//~v9j3R~
    for (ii=pglyphstr->num_glyphs,pglyphinfo=pglyphstr->glyphs;ii>0;ii--,pglyphinfo++)//~v9i0I~
    {                                                              //~v9i0I~
        pgeom=&(pglyphinfo->geometry);                             //~v9i0I~
        wwtotal+=pgeom->width;                                     //~v9j3I~
		UTRACEP("%s:geometry ii=%d,offs_x=%d,offs_y=%d,width=%d\n",UTT,ii,pgeom->x_offset,pgeom->y_offset,pgeom->width);//~v9i0R~//~v9j1R~
    }                                                              //~v9i0I~
    tmp_list=tmp_list->next;                                       //~v9i0I~
  }//runs                                                          //~v9i0I~
  	pango_layout_iter_free (iter);                                 //~v9i0I~
	UTRACEP("%s:wwtotal=%d\n",UTT,wwtotal);                            //~v9j3I~//~v9j4R~
  	return wwtotal;                                                        //~v9i0I~//~v9j3R~
}//utracelayout                                                    //~v9i0I~
//===============================================================================//~v975I~
//show layout text line                                            //~v975I~
//===============================================================================//~v975I~
void                                                               //~v975I~
lnx_showlayout(cairo_t *Pcr,PangoLayout *Pplayout,char *Pptext,int Plen,double Plinewidth)//~v975R~
{                                                                  //~v975I~
	PangoRectangle logrect;                                        //~v975I~
    double layoutwidth,pagewidth,scalex,additionalscale;                           //~v975R~//~v970R~
    int swwrap;                                                    //~v975R~
    cairo_matrix_t cm;                                             //~v975I~
//*****************************                                    //~v975I~
	UTRACEP("%s:len=%d,ellipsize cmdlin=%d,linewidth=%lf,cr=%p\n",UTT,Plen,Gxpotheropt&GOO_ELLIPSIZE,Plinewidth,Pcr);//~v975R~//~v9i0R~
	chklayoutextent(Pplayout,&logrect);                            //~v975R~
//    pc=(char*)pango_layout_get_text(Pplayout);                   //~v975R~
//    UTRACED("lnx_showlayout text",pc,strlen(pc));                //~v975R~
//    chkstringextent(pc,strlen(pc));                              //~v975R~
UTRACEP("lnx_showlayout wrap=%d\n",pango_layout_get_wrap(Pplayout));//~v975I~
UTRACEP("iswrap=%d\n",pango_layout_is_wrapped(Pplayout));          //~v975I~
UTRACEP("ellipsiz=%d\n",pango_layout_get_ellipsize(Pplayout));     //~v975I~
UTRACEP("isllipsize=%d\n",pango_layout_is_ellipsized(Pplayout));   //~v975I~
UTRACEP("gwtwidth=%d\n",pango_layout_get_width(Pplayout));         //~v975I~
//  swwrap=pango_layout_is_wrapped(Pplayout);                      //~v975M~
    swwrap=(double)logrect.width/PANGO_SCALE>Plinewidth;           //~v975R~
	UTRACEP("lnx_showlayout swwrap=%d,logrectw=%lf,linew=%lf\n",swwrap,(double)logrect.width/PANGO_SCALE,Plinewidth);//~v975R~
  if (Gtraceopt)      //trace option by /Yt                        //~v97pI~
  {                                                                //~v97pI~
    cairo_get_matrix(Pcr,&cm);            //@@@@test               //~v975I~
    UTRACEP("matrix xx=%lf,yy=%lf,x0=%lf,y0=%lf,xy=%lf,yx=%lf\n",cm.xx,cm.yy,cm.x0,cm.y0,cm.xy,cm.yx);//~v975I~//~v970R~
	utracelayout(0,Pplayout);                                      //~v9i0R~
  }                                                                //~v97pI~
	if (Gxpotheropt & GOO_ELLIPSIZE || !swwrap)	//cut if overflow page width//~v975R~
    {                                                              //~v975I~
        pango_cairo_show_layout(Pcr,Pplayout);                      //~v970M~//~v975I~
        return;                                                    //~v975I~
    }                                                              //~v975I~
#ifdef SSS                                                        //~v9i0I~//~v9j3R~
	UTRACEP("%s:cairo_save\n",UTT);                                //~v9i0I~
    cairo_save(Pcr);	                                           //~v9i0I~
#endif                                                             //~v9i0I~
#ifdef AAA                                                         //~v975I~
    pagewidth=Plen*Scharwidthf;                                    //~v975I~
	chklayoutextent(Pplayout,&logrect);                            //~v975R~
    layoutwidth=(double)logrect.width/PANGO_SCALE;                 //~v975R~
    UTRACEP("lnx_showlayout pagewidth=%lf,layoutwidth=%lf\n",pagewidth,layoutwidth);//~v975R~
    if (layoutwidth>pagewidth)	//lineoverflow                     //~v975I~
    {                                                              //~v975I~
    	scalex=Sfscalex*pagewidth/layoutwidth;                     //~v975I~
	    UTRACEP("%s:lnx_showlayout rescale by scalex(%lf)=Sfscalex(%lf)*pagewidth(%lf)/layoutwidth(%lf),cr=%p\n",UTT,scalex,Sfscalex,pagewidth,layoutwidth,Pcr);//~v975I~//~v9i0R~
        cairo_scale(Pcr,scalex,Sfscaley);                          //~v975R~
    }                                                              //~v975I~
    pango_cairo_show_layout(Pcr,Pplayout);                         //~v975I~
    cairo_scale(Pcr,Sfscalex,Sfscaley);	//restor original          //~v975I~
	UTRACEP("%s:lnx_showlayout restore Sfscalex=%lf,Sfscaley=%lf,cr=%p\n",UTT,Sfscalex,Sfscaley,Pcr);//~v9i0I~
#else                                                              //~v975I~
//  widthold=pango_layout_get_width(Pplayout);	//save width       //~v975R~
//  pango_layout_set_width(Pplayout,-1);	//save width           //~v975R~
//  chklayoutextent(Pplayout,&logrect);                            //~v975R~
    layoutwidth=(double)logrect.width/PANGO_SCALE;                 //~v975I~
    pagewidth=Plinewidth;	//remaining space on the line(points)  //~v975R~
    scalex=pagewidth/layoutwidth;                                  //~v975R~
    UTRACEP("%s:lnx_showlayout pagewidth=%lf,layoutwidth=%lf,scalex=%lf,Sfscalex=%lf\n",UTT,pagewidth,layoutwidth,scalex,Sfscalex);//~v975I~//~v97aI~//~v9i0R~
    if (scalex<Sfscalex)    //set at newpage                       //~v970R~
    {                                                              //~v970I~
        additionalscale=scalex/Sfscalex;                           //~v970R~
      if (Gtraceopt)      //trace option by /Yt                    //~v97pI~
      {                                                            //~v97pI~
    	cairo_get_matrix(Pcr,&cm);  //@@@@test                     //~v970I~
    	UTRACEP("before rescale matrix xx=%lf,yy=%lf,x0=%lf,y0=%lf,xy=%lf,yx=%lf\n",cm.xx,cm.yy,cm.x0,cm.y0,cm.xy,cm.yx);//~v970I~
      }                                                            //~v97pI~
    	cairo_scale(Pcr,additionalscale,1.0);                              //~v975R~//~v970R~//~v976R~
    	UTRACEP("%s:scale additionalscale=%lfcr=%p\n",UTT,additionalscale,Pcr);//~v9i0I~
      if (Gtraceopt)      //trace option by /Yt                    //~v97pI~
      {                                                            //~v97pI~
    	cairo_get_matrix(Pcr,&cm);  //@@@@test                         //~v975R~//~v970R~
    	UTRACEP("after rescale by %lf,matrix xx=%lf,yy=%lf,x0=%lf,y0=%lf,xy=%lf,yx=%lf\n",additionalscale,cm.xx,cm.yy,cm.x0,cm.y0,cm.xy,cm.yx);//~v975R~//~v970R~
      }                                                            //~v97pI~
    }                                                              //~v970I~
    else                                                           //~v970I~
    	additionalscale=1.0;                                       //~v970R~
    pango_cairo_show_layout(Pcr,Pplayout);                         //~v975I~
    if (additionalscale!=1.0)    //set at newpage                  //~v970I~
    {                                                              //~v970I~
		UTRACEP("lnx_showlayout reset rescale by 1.0/scalex=%lf\n",1.0/scalex);//~v975I~//~v970R~
    	cairo_scale(Pcr,1.0/additionalscale,1.0);	//restor original      //~v975R~//~v970R~//~v976R~
    	UTRACEP("%s:scale additionalscale=%lfcr=%p\n",UTT,additionalscale,Pcr);//~v9i0I~
      if (Gtraceopt)      //trace option by /Yt                    //~v97pI~
      {                                                            //~v97pI~
    	cairo_get_matrix(Pcr,&cm);  //@@@@test                         //~v975R~//~v970R~
    	UTRACEP("%s:after reset rescale matrix xx=%lf,yy=%lf,x0=%lf,y0=%lf,xy=%lf,yx=%lf\n",UTT,cm.xx,cm.yy,cm.x0,cm.y0,cm.xy,cm.yx);//~v975I~//~v970R~//~v9i0R~
      }                                                            //~v97pI~
    }                                                              //~v970I~
#endif                                                             //~v975I~
#ifdef SSS                                                        //~v9i0I~//~v9j3R~
	UTRACEP("%s:cairo_restore\n",UTT);                             //~v9i0I~
    cairo_restore(Pcr);                                            //~v9i0I~
#endif                                                             //~v9i0I~
}//lnx_showlayout                                                  //~v975I~
int                                                                //~v970M~
createfontByWidth(PangoFontDescription *Ppfd,double Pcharwidthf,int *Ppfontw,int *Ppfonth)//~v970M~
{                                                                  //~v970M~
	int fonth,fontw,targetw,step,sz;                               //~v970M~
//************************                                         //~v970M~
	UTRACEP("createfontByWidth req=%lf\n",Pcharwidthf);            //~v970M~
    targetw=(int)Pcharwidthf;                                      //~v970M~
    sz=(pango_font_description_get_size(Ppfd)/PANGO_SCALE)*PANGO_SCALE;//~v970M~
	lnx_getfontmetrics(Ppfd,&fontw,&fonth);                        //~v970M~
	UTRACEP("createfontByWidth start sz=%d,fontw=%d point\n",sz,fontw);//~v970M~
    step=PANGO_SCALE/10;                                           //~v970M~
	for (;;)                                                       //~v970M~
    {                                                              //~v970M~
    	if (sz<=0)                                                 //~v970M~
        	break;                                                 //~v970M~
	    if (fontw<targetw)                                         //~v970M~
    		sz+=step;                                              //~v970M~
        else                                                       //~v970M~
	    if (fontw>targetw)                                         //~v970M~
    		sz-=step;                                              //~v970M~
        else                                                       //~v970M~
        	break;                                                 //~v970M~
        pango_font_description_set_size(Ppfd,sz);                  //~v970M~
		lnx_getfontmetrics(Ppfd,&fontw,&fonth);                    //~v970M~
		UTRACEP("createfontByWidth sz=%d,fontw=%d point\n",sz,fontw);//~v970M~
	}                                                              //~v970M~
    *Ppfontw=fontw;                                                //~v970M~
    *Ppfonth=fonth;                                                //~v970M~
	UTRACEP("createfontByWidth return sz=%d,fontw=%d,fonth=%d point\n",sz,fontw,fonth);//~v970M~
    return sz;                                                     //~v970M~
}//createfontByWidth                                               //~v970M~
//===============================================================================//~v98hI~
double getparmmargin(char *Ppc,int Pstrlen,int *Ppnumlen)          //~v98hR~
{                                                                  //~v98hI~
	int numlen,intval;                                             //~v98hI~
    double fval;                                                   //~v98hI~
//*****************                                                //~v98hI~
	numlen=unumlen(Ppc,0,Pstrlen);                                 //~v98hI~
    intval=atoi(Ppc);                                              //~v98hI~
    if (numlen && toupper(*(Ppc+numlen))=='P')                     //~v98hI~
    {                                                              //~v98hI~
    	fval=(double)intval;                                       //~v98hM~
        numlen++;                                                  //~v98hI~
    }                                                              //~v98hI~
    else                                                           //~v98hI~
    {                                                              //~v98hI~
    	fval=MM2POINT(intval);                                     //~v98hI~
    }                                                              //~v98hI~
    UTRACEP("getparmmargin inp=%s,val=%f,numlen=%d\n",Ppc,fval,numlen);//~v98hR~
    *Ppnumlen=numlen;                                              //~v98hI~
    return fval;                                                   //~v98hI~
}//getparmmargin                                                   //~v98hR~
//===============================================================================//~v977M~
//getshift parm                                                    //~v977M~
//{T|B|L|R}[mm]                                                    //~v977M~
//===============================================================================//~v977M~
void                                                               //~v977I~
getshiftparm(char *Pparm)                                          //~v977M~
{                                                                  //~v977M~
    char *pc;                                                      //~v977I~
    int ch=0,ii,len,numlen=0,err=0;                                //~v977R~
#ifdef MMM                                                         //~v98hI~
    int sworigin=0;                                                //~v98aI~
#else                                                              //~v98hR~
    int swmargin=0;                                                //~v98hI~
#endif                                                             //~v98hI~
//**************************                                       //~v977M~
    UTRACEP("getshiftparm parm=%s\n",Pparm);                       //~v977M~
    pc=Pparm;                                                      //~v98aR~
#ifdef MMM                                                         //~v98hI~
    for (ii=0;ii<3;ii++)                                           //~v977I~//~v97aR~
#else                                                              //~v98hI~
    for (ii=0;ii<8;ii++)	//"O", "M", vertical/horizontal shift and 4 direction margin//~v98hR~
#endif                                                             //~v98hI~
    {                                                              //~v977I~
	    ch=toupper(*pc);                                           //~v977I~
    	pc++;                                                      //~v977I~
        if (!ch)                                                   //~v977I~
        	break;                                                 //~v977I~
//      len=strlen(pc);                                            //~v977I~//~v9a0R~
        len=(int)strlen(pc);                                       //~v9a0I~
        switch(ch)                                                 //~v977I~
        {                                                          //~v977I~
#ifdef DDD    //"P" is err                                         //~v97bI~
        case 'P':      //no rotation                               //~v97aI~
			Gxpotheropt|=GOO_NOROTATION;                           //~v97aR~
            break;                                                 //~v97aI~
#endif                                                             //~v97bI~
#ifdef MMM                                                         //~v98hI~
        case 'O':      //shift origin                              //~v98aI~
			sworigin=1;                                            //~v98aI~
#else                                                              //~v98hR~
//			swmargin=0;                                            //~v98hI~//~v9g0R~
#endif                                                             //~v98hI~
//          break;                                                 //~v98aI~//~v9g0R~
#ifndef MMM                                                        //~v98hI~
        case 'M':      //shift origin                              //~v98hI~
			swmargin=1;                                            //~v98hI~
            numlen=0;                                              //~v98jI~
            break;                                                 //~v98hI~
#endif                                                             //~v98hI~
        case 'T':                                                  //~v977I~
#ifndef MMM                                                        //~v98hI~
			if (swmargin)                                          //~v98hI~
            {                                                      //~v98hI~
            	Sparmmargint=getparmmargin(pc,len,&numlen);        //~v98hR~
	            Sshiftdirection|=SD_TOPM;                          //~v98hI~
                break;                                             //~v98hI~
            }                                                      //~v98hI~
#endif                                                             //~v98hI~
            if (Sshiftdirection & (SD_TOP|SD_BOT))                 //~v977I~
            	err=1;                                             //~v977I~
            Sshiftdirection|=SD_TOP;                               //~v977I~
            numlen=unumlen(pc,0,len);                              //~v977R~
            SshiftdistanceV=atoi(pc);   //vertical shift           //~v977I~
            if (numlen && toupper(*(pc+numlen))=='P')              //~v98aI~
            {                                                      //~v98aI~
                SshiftdistanceV=POINT2MM(SshiftdistanceV);         //~v98aR~
                numlen++;                                          //~v98aI~
            }                                                      //~v98aI~
            break;                                                 //~v977I~
        case 'B':                                                  //~v977I~
#ifndef MMM                                                        //~v98hI~
			if (swmargin)                                          //~v98hI~
            {                                                      //~v98hI~
            	Sparmmarginb=getparmmargin(pc,len,&numlen);        //~v98hR~
	            Sshiftdirection|=SD_BOTM;                          //~v98hR~
                break;                                             //~v98hI~
            }                                                      //~v98hI~
#endif                                                             //~v98hI~
            if (Sshiftdirection & (SD_TOP|SD_BOT))                 //~v977I~
            	err=1;                                             //~v977I~
            Sshiftdirection|=SD_BOT;                               //~v977I~
            numlen=unumlen(pc,0,len);                              //~v977I~
            SshiftdistanceV=atoi(pc);   //vertical shift           //~v977I~
            if (numlen && toupper(*(pc+numlen))=='P')              //~v98aI~
            {                                                      //~v98aI~
                SshiftdistanceV=POINT2MM(SshiftdistanceV);         //~v98aI~
                numlen++;                                          //~v98aI~
            }                                                      //~v98aI~
            break;                                                 //~v977I~
        case 'L':                                                  //~v977I~
#ifndef MMM                                                        //~v98hI~
			if (swmargin)                                          //~v98hI~
            {                                                      //~v98hI~
            	Sparmmarginl=getparmmargin(pc,len,&numlen);        //~v98hR~
	            Sshiftdirection|=SD_LEFTM;                         //~v98hI~
                break;                                             //~v98hI~
            }                                                      //~v98hI~
#endif                                                             //~v98hI~
            if (Sshiftdirection & (SD_LEFT|SD_RIGHT))              //~v977I~
            	err=1;                                             //~v977I~
            Sshiftdirection|=SD_LEFT;                              //~v977I~
            numlen=unumlen(pc,0,len);                              //~v977I~
            SshiftdistanceH=atoi(pc);   //horizontak;              //~v977I~
            if (numlen && toupper(*(pc+numlen))=='P')              //~v98aI~
            {                                                      //~v98aI~
                SshiftdistanceH=POINT2MM(SshiftdistanceH);         //~v98aI~
                numlen++;                                          //~v98aI~
            }                                                      //~v98aI~
            break;                                                 //~v977I~
        case 'R':                                                  //~v977I~
#ifndef MMM                                                        //~v98hI~
			if (swmargin)                                          //~v98hI~
            {                                                      //~v98hI~
            	Sparmmarginr=getparmmargin(pc,len,&numlen);        //~v98hR~
	            Sshiftdirection|=SD_RIGHTM;                        //~v98hI~
                break;                                             //~v98hI~
            }                                                      //~v98hI~
#endif                                                             //~v98hI~
            if (Sshiftdirection & (SD_LEFT|SD_RIGHT))              //~v977I~
            	err=1;                                             //~v977I~
            Sshiftdirection|=SD_RIGHT;                             //~v977I~
            numlen=unumlen(pc,0,len);                              //~v977I~
            SshiftdistanceH=atoi(pc);   //horizontak;              //~v977I~
            if (numlen && toupper(*(pc+numlen))=='P')              //~v98aI~
            {                                                      //~v98aI~
                SshiftdistanceH=POINT2MM(SshiftdistanceH);         //~v98aI~
                numlen++;                                          //~v98aI~
            }                                                      //~v98aI~
            break;                                                 //~v977I~
        default:                                                   //~v977I~
            err=1;                                                 //~v977R~
        }                                                          //~v977I~
        UTRACEP("getshiftparm dir=%x,distH=%f,distV=%f\n",Sshiftdirection,SshiftdistanceH,SshiftdistanceV);//~v98aR~
        pc+=numlen;                                                //~v977I~
    }                                                              //~v977I~
    if (ch && *pc)    //redundant                                  //~v977R~
    	err=1;                                                     //~v977I~
    if (err)                                                       //~v977I~
        uerrexit("Shift parameter(%s) error",0,                    //~v977I~
                    Pparm-1);                                      //~v977I~
#ifdef MMM                                                         //~v98hI~
    if (sworigin)                                                  //~v98aI~
    {                                                              //~v98aI~
    	Sshiftdirectionorigin=Sshiftdirection;                     //~v98aI~
    	Sshiftdirection=0;                                         //~v98aI~
    }                                                              //~v98aI~
#endif                                                             //~v98hI~
}//getshiftparm                                                    //~v977M~
//****************************************************************************//~v977I~
//custom papersize                                                 //~v977I~
//****************************************************************************//~v977I~
void shiftpaper(FRECT *Ppfrect,float *Ppwidth,float *Ppheight)     //~v977I~
{                                                                  //~v977I~
    float ww,hh;                                                   //~v977I~
    float shift;                                                   //~v977R~
//*******************************                                  //~v977I~
	ww=*Ppwidth;                                                   //~v977I~
    hh=*Ppheight;                                                  //~v977R~
    UTRACEP("shiftpaper w=%f,h=%f,frect :t=%f,b=%f,l=%f,r=%f\n",   //~v977I~
                ww,hh,Ppfrect->top,Ppfrect->bottom,Ppfrect->left,Ppfrect->right);//~v977R~
    UTRACEP("shiftpaper dest=%x,distance H=%f V=%f mm\n",Sshiftdirection,SshiftdistanceH,SshiftdistanceV);//~v98aR~
    UTRACEP("A4 width=%d,height=%d\n",SpagewidthA4,SpageheightA4); //~v977R~
    shift=MM2POINT(SshiftdistanceV);                               //~v977I~
    if (!shift)	//shift by diff from A$                            //~v977I~
    {                                                              //~v977I~
//    	shift=SpageheightA4-hh;	                                   //~v977R~//~v9a0R~
      	shift=(float)SpageheightA4-hh;                             //~v9a0R~
//  	shift=FMAX(shift,0.0);                                     //~v977I~//~v9a0R~
    	shift=FMAX(shift,(float)(0.0));                            //~v9a0I~
    }                                                              //~v977I~
    UTRACEP("shiftpaper V=%f point\n",shift);                      //~v977R~
    if (Sshiftdirection & SD_TOP)                                  //~v977R~
    {                                                              //~v977I~
    	hh+=shift;                                                 //~v977I~
        Ppfrect->top+=shift; //top margin pos(+height up)          //~v977R~
        Ppfrect->bottom+=shift; //keep ink rect height             //~v977I~
    }                                                              //~v977I~
    else                                                           //~v977R~
    if (Sshiftdirection & SD_BOT)                                  //~v977I~
    {                                                              //~v977I~
    	hh+=shift;                                                 //~v977I~
    }                                                              //~v977I~
    shift=MM2POINT(SshiftdistanceH);                               //~v977I~
    if (!shift)	//shift by diff from A$                            //~v977I~
    {                                                              //~v977I~
//  	shift=SpagewidthA4-ww;                                     //~v977R~//~v9a0R~
    	shift=(float)SpagewidthA4-ww;                              //~v9a0R~
//  	shift=FMAX(shift,0.0);                                     //~v977I~//~v9a0R~
    	shift=FMAX(shift,(float)(0.0));                            //~v9a0I~
    }                                                              //~v977I~
    UTRACEP("shiftpaper H=%f point\n",shift);                      //~v977R~
    if (Sshiftdirection & SD_LEFT)                                 //~v977I~
    {                                                              //~v977I~
    	ww+=shift;   //keep right margin pos(keep ink rect width)  //~v977I~
    }                                                              //~v977I~
    else                                                           //~v977I~
    if (Sshiftdirection & SD_RIGHT)                                //~v977I~
    {                                                              //~v977I~
    	ww+=shift;                                                 //~v977I~
        Ppfrect->left+=shift; //shift right                        //~v977I~
        Ppfrect->right+=shift; //right margin pos up to kep ink rect width//~v977I~
    }                                                              //~v977I~
    UTRACEP("shiftpaper after w=%f,h=%f,frect :t=%f,b=%f,l=%f,r=%f\n",//~v977I~
    			ww,hh,Ppfrect->top,Ppfrect->bottom,Ppfrect->left,Ppfrect->right);//~v977I~
	*Ppwidth=ww;                                                   //~v977I~
    *Ppheight=hh;                                                  //~v977R~
}//shiftpaper                                                      //~v977I~
#ifdef MMM                                                         //~v98hI~
//****************************************************************************//~v98aI~
//get translate value by shift parm                                //~v98aI~
//****************************************************************************//~v98aI~
void shiftpaperorigin(double Pwidth,double Pheight,double *Ppxshift,double *Ppyshift)//~v98aR~
{                                                                  //~v98aI~
    double ww,hh,shift,xshift=0.0,yshift=0.0;                      //~v98aI~
//*******************************                                  //~v98aI~
	UTRACEP("shiftpaper Sshiftdirectionorigin=%d\n",Sshiftdirectionorigin);//~v98aR~
   	if (!Sshiftdirectionorigin)                                    //~v98aR~
    {                                                              //~v98aI~
    	*Ppxshift=*Ppyshift=0.0;                                   //~v98aI~
        return;                                                    //~v98aI~
    }                                                              //~v98aI~
	ww=Pwidth;                                                     //~v98aI~
    hh=Pheight;                                                    //~v98aI~
    UTRACEP("shiftpaper dest=%x,distance H=%f V=%f mm\n",Sshiftdirectionorigin,SshiftdistanceH,SshiftdistanceV);//~v98aR~
    UTRACEP("A4 width=%d,height=%d\n",SpagewidthA4,SpageheightA4); //~v98aI~
    shift=MM2POINT(SshiftdistanceV);                               //~v98aI~
    if (!shift)	//shift by diff from A$                            //~v98aI~
    {                                                              //~v98aI~
    	shift=SpageheightA4-hh;                                    //~v98aI~
    	shift=FMAX(shift,0.0);                                     //~v98aI~
    }                                                              //~v98aI~
    UTRACEP("shiftpaper V=%f point\n",shift);                      //~v98aI~
    if (Sshiftdirectionorigin & SD_TOP)                            //~v98aR~
        yshift=-shift;                                             //~v98aI~
    else                                                           //~v98aI~
    if (Sshiftdirectionorigin & SD_BOT)                            //~v98aR~
        yshift=shift;                                              //~v98aI~
    shift=MM2POINT(SshiftdistanceH);                               //~v98aI~
    if (!shift)	//shift by diff from A$                            //~v98aI~
    {                                                              //~v98aI~
    	shift=SpagewidthA4-ww;                                     //~v98aI~
    	shift=FMAX(shift,0.0);                                     //~v98aI~
    }                                                              //~v98aI~
    UTRACEP("shiftpaper H=%f point\n",shift);                      //~v98aI~
    if (Sshiftdirectionorigin & SD_LEFT)                           //~v98aR~
    	xshift=-shift;                                             //~v98aI~
    else                                                           //~v98aI~
    if (Sshiftdirectionorigin & SD_RIGHT)                          //~v98aR~
    	xshift=shift;                                              //~v98aI~
    UTRACEP("shiftpaper after x=%f,y=%f\n",xshift,yshift);         //~v98aI~
	*Ppxshift=xshift;                                              //~v98aI~
    *Ppyshift=yshift;                                              //~v98aI~
}//shiftpaperorigin                                                      //~v98aI~//~v98hR~
#endif                                                             //~v98hI~
#ifdef DDD                                                         //~v97aR~
//****************************************************************************//~v97aI~
//rotate paper                                                     //~v97aI~
//****************************************************************************//~v97aI~
void rotatepaper(FRECT *Ppfrect,float *Ppwidth,float *Ppheight)    //~v97aI~
{                                                                  //~v97aI~
    float ww,hh;                                                   //~v97aI~
    FRECT frect;                                                   //~v97aI~
//*******************************                                  //~v97aI~
	ww=*Ppwidth;                                                   //~v97aI~
	hh=*Ppheight;                                                  //~v97aI~
    frect=*Ppfrect;                                                //~v97aI~
    *Ppwidth=hh;                                                   //~v97aI~
    *Ppheight=ww;                                                  //~v97aI~
    Ppfrect->top=ww-frect.left;                                    //~v97aR~
    Ppfrect->bottom=ww-frect.right;                                //~v97aR~
    Ppfrect->left=frect.bottom;                                    //~v97aR~
    Ppfrect->right=frect.top;                                      //~v97aR~
    UTRACEP("shiftpaper after rotate w=%f,h=%f,frect :t=%f,b=%f,l=%f,r=%f\n",//~v97aI~
    			*Ppwidth,*Ppheight,Ppfrect->top,Ppfrect->bottom,Ppfrect->left,Ppfrect->right);//~v97aI~
}//rotatepaper                                                     //~v97aI~
#endif                                                             //~v97aI~
//****************************************************************************//~v977I~
//custom papersize                                                 //~v977I~
//****************************************************************************//~v977I~
GtkPaperSize *getCustomPapersize(char *Ppform,char *Pinternalname,ppd_size_t *Pppgsz,FRECT *Ppfrect)//~v977R~
{                                                                  //~v977I~
    float ww,hh;                                                   //~v977I~
    GtkPaperSize *pps;                                             //~v977R~
//*******************************                                  //~v977I~
    UTRACEP("getCustompapersize ppgsz :t=%lf,b=%lf,l=%lf,r=%lf\n", //~v977I~
                Pppgsz->top,Pppgsz->bottom,Pppgsz->left,Pppgsz->right);//~v977I~
    ww=Pppgsz->width;                                              //~v977I~
    hh=Pppgsz->length;                                             //~v977I~
    UTRACEP("custom papersize Ppform=%s,create1  ww=%f,hh=%f\n",Ppform,ww,hh);//~v977R~
    if (Sshiftdirection)                                           //~v977I~
    	shiftpaper(Ppfrect,&ww,&hh);                               //~v977I~
#ifdef DDD                                                         //~v97aR~
  	if ((Gxpotheropt & GOO_NOROTATION))                            //~v97aM~
    	rotatepaper(Ppfrect,&ww,&hh);	//swap w & h               //~v97aI~
#endif                                                             //~v97aM~
    UTRACEP("custom papersize create1  ww=%f,hh=%f\n",ww,hh);      //~v977I~
    pps=gtk_paper_size_new_custom(Pinternalname,Ppform,ww,hh,GTK_UNIT_POINTS);//~v977R~
    UTRACEP("custom papersize created ww=%lf,hh=%lf\n",            //~v97aI~
    	gtk_paper_size_get_width(pps,GTK_UNIT_POINTS),             //~v97aI~
    	gtk_paper_size_get_height(pps,GTK_UNIT_POINTS));           //~v97aI~
    UTRACEP("custom papersize created default margin(mm):t=%lf,b=%lf,l=%lf,r=%lf\n",//~v977R~
                    		gtk_paper_size_get_default_top_margin(pps,GTK_UNIT_MM),//~v977I~
                    		gtk_paper_size_get_default_bottom_margin(pps,GTK_UNIT_MM),//~v977I~
                    		gtk_paper_size_get_default_left_margin(pps,GTK_UNIT_MM),//~v977I~
                    		gtk_paper_size_get_default_right_margin(pps,GTK_UNIT_MM)); // all 0.25 inches//~v977I~
    UTRACEP("custom papersize created default margin(point):t=%lf,b=%lf,l=%lf,r=%lf\n",//~v977I~
                    		gtk_paper_size_get_default_top_margin(pps,GTK_UNIT_POINTS),//~v977I~
                    		gtk_paper_size_get_default_bottom_margin(pps,GTK_UNIT_POINTS),//~v977I~
                    		gtk_paper_size_get_default_left_margin(pps,GTK_UNIT_POINTS),//~v977I~
                    		gtk_paper_size_get_default_right_margin(pps,GTK_UNIT_POINTS)); // all 0.25 inches//~v977I~
    return pps;                                                    //~v977I~
}//getCustomPapersize                                              //~v977I~
//****************************************************************************//~v97cI~
//get page range from dialog                                       //~v97cI~
//****************************************************************************//~v97cI~
void getDialogPageRange(GtkPrintSettings *Ppsettings)              //~v97cR~
{                                                                  //~v97cI~
	GtkPrintPages pagerangeid;                                     //~v97cR~
    GtkPageRange *prange,*prange2;                                 //~v97cR~
    int ii,jj,start,end,start2,end2;                               //~v97cR~
//********************                                             //~v97cI~
	Spagerangectr=0;                                               //~v97cI~
	pagerangeid=gtk_print_settings_get_print_pages(Ppsettings);    //~v97cI~
    if (pagerangeid==GTK_PRINT_PAGES_RANGES)                       //~v97cI~
    {                                                              //~v97cI~
    	if (pagerangectr)           //cmdline parm                 //~v97cI~
        	uerrexit("Dialog Page-Range spcification is not allowed when \"-P\" command line parameter",0);//~v97cR~
		Spagerange=gtk_print_settings_get_page_ranges(Ppsettings,&Spagerangectr);//~v97cR~
    }                                                              //~v97cI~
    UTRACEP("getPageRange ctr=%d\n",Spagerangectr);                //~v97cR~
//dup chk                                                          //~v97cI~
    for (prange=Spagerange,ii=0;ii<Spagerangectr;ii++,prange++)    //~v97cI~
    {                                                              //~v97cI~
    	UTRACEP("PageRange start=%d,end=%d\n",prange->start,prange->end);//~v97cI~
        start=prange->start;                                       //~v97cI~
        end=prange->end;                                           //~v97cI~
        if (start>end)                                             //~v97cI~
	    	uerrexit("Dialog Page-Range spcification error(start(%d)>end(%d))",0,//~v97cR~
            			start+1,end+1);                            //~v97cI~
	    for (prange2=prange+1,jj=ii+1;jj<Spagerangectr;jj++,prange2++)//~v97cI~
        {                                                          //~v97cI~
	        start2=prange2->start;                                 //~v97cR~
    	    end2=prange2->end;                                     //~v97cR~
        	if ((start>=start2 && start<=end2)||(end>=start2 && end<=end2))//~v97cR~
	        	uerrexit("Dialog Page-Range spcification contains duplicated page(%d-%d and %d-%d",0,//~v97cR~
                		start+1,end+1,start2+1,end2+1);            //~v97cI~
        }                                                          //~v97cI~
    }                                                              //~v97cI~
}//getDialogPageRange                                              //~v97cR~
//****************************************************************************//~v97cI~
//modify npage by dialog pagerange specification                   //~v97cI~
//assumption cmdline parameter has no range parm                   //~v97cI~
//parm:npage 0 base pageNo from rangeList( ex for dialog "2-3,6", Pnpage=1,2,5//~v97cI~
//****************************************************************************//~v97cI~
int getDialogNpage(int Pnpage)                                     //~v97cR~
{                                                                  //~v97cI~
    int ii,npage=0,start,end,swpage=0,errstart=0;                  //~v97cR~
    GtkPageRange *prange;                                          //~v97cI~
//********************                                             //~v97cI~
    UTRACEP("getDialogNpage filepage=%d,Spagerangectr=%d\n",Pnpage,Spagerangectr);//~v97cR~
    if (!Spagerangectr)                                            //~v97cR~
    {                                                              //~v97cI~
    	Gdrawpagectr=Pnpage;                                       //~v97cR~
        return Pnpage;                                             //~v97cI~
    }                                                              //~v97cI~
    for (prange=Spagerange,ii=0;ii<Spagerangectr;ii++,prange++)    //~v97cI~
    {                                                              //~v97cI~
    	UTRACEP("PageRange start=%d,end=%d\n",prange->start,prange->end);//~v97cI~
        start=prange->start+1;                                     //~v97cI~
        end=prange->end+1;                                         //~v97cI~
        if (end<=Pnpage)                                           //~v97cI~
        	Gdrawpagectr+=end-start+1;                             //~v97cR~
        else    //end>Pnpage                                       //~v97cI~
        if (start<=Pnpage)    //start<=Pnpage<end                  //~v97cI~
        	Gdrawpagectr+=Pnpage-start+1;                          //~v97cR~
                                                                   //~v97cI~
        npage=min(end,Pnpage);	                                   //~v97cR~
        if (start<=Pnpage)                                         //~v97cI~
        	swpage=1;                                              //~v97cI~
        else                                                       //~v97cI~
            errstart=start;                                        //~v97cI~
    }                                                              //~v97cI~
    if (!swpage)                                                   //~v97cR~
	    uerrexit("Dialog Page-Range spcification is out-of-range(one is start=%d) of total %d pages",0,//~v97cR~
                		errstart,Pnpage);                          //~v97cR~
    UTRACEP("getDialogNpage npage=%d,Gdrawpagectr=%d\n",npage,Gdrawpagectr);//~v97cR~
    return npage;                                                  //~v97cI~
}//getDialogNpage                                                  //~v97cI~
//****************************************************************************//~v97cI~
//select draw_page:PageNo from FilePage                            //~v97cI~
//assumption cmdline parameter has no range parm                   //~v97cI~
//****************************************************************************//~v97cI~
int getDialogSelectpage(int Pdrawpage)                             //~v97cI~
{                                                                  //~v97cI~
#ifdef AAA                                                         //~v97cI~
    int ii,npage=0,npage2,start,end,filepage=0;                    //~v97cR~
    GtkPageRange *prange;                                          //~v97cI~
//********************                                             //~v97cI~
    UTRACEP("Selectpage Pdrawpage=%d\n",Pdrawpage);                //~v97cI~
    for (prange=Spagerange,ii=0;ii<Spagerangectr;ii++,prange++)    //~v97cI~
    {                                                              //~v97cI~
    	UTRACEP("PageRange start=%d,end=%d\n",prange->start,prange->end);//~v97cI~
        start=prange->start;                                       //~v97cI~
        end=prange->end;                                           //~v97cI~
        npage2=npage+end-start;                                    //~v97cR~
    	UTRACEP("PageRange Pdrawpage=%d,npage=%d,npage2=%d\n",Pdrawpage,npage,npage2);//~v97cI~
        if (Pdrawpage>=npage && Pdrawpage<=npage2)                 //~v97cI~
        {                                                          //~v97cI~
        	filepage=start+Pdrawpage-npage;                        //~v97cR~
            break;                                                 //~v97cI~
        }                                                          //~v97cI~
        npage=npage2;                                              //~v97cI~
    }                                                              //~v97cI~
    UTRACEP("getDialogSelectpage filepage=%d,drawpage=%d\n",filepage,Pdrawpage);//~v97cI~
    return filepage;                                               //~v97cI~
#endif                                                             //~v97cI~
	return Pdrawpage;                                              //~v97cI~
}//getDialogSelectpage                                             //~v97cI~
//****************************************************************************//~v97cI~
void printedmsg()                                                  //~v97cI~
{                                                                  //~v97cI~
    if (Spagerangectr)                                             //~v97cI~
    {                                                              //~v97cI~
		if (dbcsenv)	//DBCS mode v4.9a                          //~v97cR~
    		fprintf(Gmsgfile,"\n%s:%s:プリント終了;出力 = %d 頁 (全 %d 頁中 %d-%d の範囲).\n",//v7.26r//~v90mI~//~v97cR~
//      	 pgmid,ver,realpage,page,pagestart,min(pageend,page)); //v4.9a//~v74hR~//~v97cI~
        	 pgmid,ver,Gdrawpagectr,Srealpagectr,Spagestart,Spageend); //v4.9a//~v97cI~
    	else			//SBCS mode v4.9a	                       //~v97cR~
    		fprintf(Gmsgfile,"\n%s:%s:print end;output= %d pages (from range %d-%d of %d pages).\n",//v7.26r//~v90mI~//~v97cR~
//      	 pgmid,ver,realpage,pagestart,min(pageend,page),page); //v4.6a//~v74hR~//~v97cI~
        	 pgmid,ver,Gdrawpagectr,Spagestart,Spageend,Srealpagectr); //v4.6a//~v97cR~
    }                                                              //~v97cI~
    else                                                           //~v97cI~
    {                                                              //~v97cI~
		if (dbcsenv)	//DBCS mode v4.9a                          //~v97cI~
    		fprintf(Gmsgfile,"\n%s:%s:プリント終了;出力 = %d 頁 (全 %d 頁中 %d-%d の範囲).\n",//v7.26r//~v97cI~
        	 pgmid,ver,realpage,page,pagestart,min(pageend,page)); //v4.9a//~v97cI~
    	else			//SBCS mode v4.9a                          //~v97cI~
    		fprintf(Gmsgfile,"\n%s:%s:print end;output= %d pages (from range %d-%d of %d pages).\n",//v7.26r//~v97cI~
        	 pgmid,ver,realpage,pagestart,min(pageend,page),page); //v4.6a//~v97cI~
    }                                                              //~v97cI~
                                                                   //~v97cI~
}//printedmsg                                                      //~v97cI~
//****************************************************************************//~v97mI~
void msgdialog(int Popt,char *Pmsg,GtkWidget *Pparent)            //~v97mR~//~v97pR~
{                                                                  //~v97mI~
	GtkWidget *dialog;                                             //~v97mI~
    int btnopt,msgtype;                                            //~v97mR~
//*************************                                        //~v97mI~
	btnopt=GTK_BUTTONS_CLOSE;                                      //~v97mR~
	msgtype=GTK_MESSAGE_QUESTION;                                  //~v97mR~
    dialog=gtk_message_dialog_new (GTK_WINDOW (Pparent),           //~v97mI~
				       GTK_DIALOG_MODAL|GTK_DIALOG_DESTROY_WITH_PARENT,//~v97mR~
				       msgtype,//  			       GTK_BUTTONS_CLOSE,//~v97mR~
    			       btnopt,                                     //~v97mI~
				       "%s",Pmsg);                                 //~v97mI~
    g_signal_connect(dialog,"response",                            //~v97mI~
			G_CALLBACK(gtk_widget_destroy),dialog);                //~v97mI~
    gtk_widget_show(dialog);                                       //~v97mR~
    gtk_dialog_run(GTK_DIALOG(dialog));                            //~v97mI~
    gtk_widget_destroy(dialog);                                    //~v97mI~
}//msgdialog                                                       //~v97mI~
//****************************************************************************//~v97mI~
void hidewindow(int Popt)                                          //~v97mR~
{                                                                  //~v97mI~
    char *pmsg;                                                    //~v97mR~
////    GdkWindow *pparent;                                        //~v97mR~
//***********************                                          //~v97mR~
    UTRACEP("hidewindow Smainwindow=%p,button=%p\n",Smainwindow,Sbutton_can);//~v97mI~
////    pparent=gtk_widget_get_parent_window(Sbutton_can);         //~v97mR~
//    printf("hidewindow is_toplevl=%d\n",gtk_widget_is_toplevel(Smainwindow));      //@@@@test//~v97mR~
//    printf("hidewindow is_focus=%d\n",gtk_widget_is_focus(Smainwindow));      //@@@@test//~v97mR~
//    printf("hidewindow get_visible=%d\n",gtk_widget_get_visible(Smainwindow));      //@@@@test//~v97mR~
////  gdk_window_hide(pparent);                                    //~v97mR~
//    if (Popt & 0x01)                                             //~v97mR~
//    {                                                            //~v97mR~
//        pmsg="Reply to print confirmation on terminal window";   //~v97mR~
//        lnx_updatefwmsg(pmsg);                                   //~v97mR~
//        printf("set msg\n");                                     //~v97mR~
//    }                                                            //~v97mR~
//    gtk_widget_grab_focus(Smainwindow);                          //~v97mR~
//    gtk_widget_set_visible(Smainwindow,TRUE);                    //~v97mR~
//    printf("after visible TRUE\n");     //@@@@test               //~v97mR~
//    printf("hidewindow is_toplevl=%d\n",gtk_widget_is_toplevel(Smainwindow));      //@@@@test//~v97mR~
//    printf("hidewindow is_focus=%d\n",gtk_widget_is_focus(Smainwindow));      //@@@@test//~v97mR~
//    printf("hidewindow get_visible=%d\n",gtk_widget_get_visible(Smainwindow));      //@@@@test//~v97mR~
//    gtk_widget_set_visible(Smainwindow,FALSE);                   //~v97mR~
//    printf("after visible FALSE\n");     //@@@@test              //~v97mR~
//    printf("hidewindow is_toplevl=%d\n",gtk_widget_is_toplevel(Smainwindow));      //@@@@test//~v97mR~
//    printf("hidewindow is_focus=%d\n",gtk_widget_is_focus(Smainwindow));      //@@@@test//~v97mR~
//    printf("hidewindow get_visible=%d\n",gtk_widget_get_visible(Smainwindow));      //@@@@test//~v97mR~
//    gtk_widget_hide(Smainwindow);                                //~v97mR~
//    printf("after hide\n");     //@@@@test                       //~v97mR~
//    printf("hidewindow is_toplevl=%d\n",gtk_widget_is_toplevel(Smainwindow));      //@@@@test//~v97mR~
//    printf("hidewindow is_focus=%d\n",gtk_widget_is_focus(Smainwindow));      //@@@@test//~v97mR~
//    printf("hidewindow get_visible=%d\n",gtk_widget_get_visible(Smainwindow));      //@@@@test//~v97mR~
//    UTRACEP("hidewindow Smainwindow=%p,button=%p\n",Smainwindow,Sbutton_can);//~v97mR~
//*                                                                //~v97mI~
//    gtk_widget_hide(Smainwindow);                                //~v97mR~
//    Sswapply=1;     //not cancel,but recreate                    //~v97mR~
//    gtk_widget_destroy(Smainwindow);                             //~v97mR~
//*                                                                //~v97mI~
  if (Gtraceopt)      //trace option by /Yt                        //~v97pI~
    printf("showwindow destroy\n");                                //~v97pR~
    gtk_widget_hide(Smainwindow);                                  //~v97mR~
	pmsg="Pending print confirmation.\n"                           //~v97mR~
		  "Close dialog, then reply on terminal window";           //~v97mI~
    msgdialog(0,pmsg,Smainwindow);                                 //~v97mR~
    gtk_widget_show_all(Smainwindow);//to destroy(hide) invisible msg dialog//~v97mR~
}//killfocus                                                       //~v97mI~
//****************************************************************************//~v97mI~
void showwindow(int Popt)                                          //~v97mR~
{                                                                  //~v97mI~
    UTRACEP("showwindow Smainwindow=%p\n",Smainwindow);            //~v97mR~
    gtk_widget_show_all(Smainwindow);//void                        //~v97mR~
//    Smainwindow=lnx_createfw();                                  //~v97mR~
//    gtk_widget_show(Smainwindow);                                //~v97mR~
//    printf("showwindow recreatefw\n");  //@@@@test               //~v97mR~
//    UTRACEP("showwindow recreate Smainwindow=%p\n",Smainwindow); //~v97mR~
//    gtk_widget_destroy(Smsgdialog);                              //~v97mR~
}//killfocus                                                       //~v97mI~
//****************************************************************************//~v97pI~
int                                                                //~v97pI~
isallascii(char *Pputf8,int Plen)                                  //~v97pI~
{                                                                  //~v97pI~
	int utf8len,chrcnt,opt,rc=0;                                   //~v97pI~
//**************                                                   //~v97pI~
	opt=0;                                                         //~v97pI~
	utf8len=utfgetutf8strlen(opt,Pputf8,Plen,&chrcnt);             //~v97pI~
    if (utf8len==Plen)   //all valid utf8                          //~v97pR~
    	if (chrcnt==Plen)    //allascii                            //~v97pR~
        	rc=1;                                                  //~v97pI~
    UTRACEP("isallascii rc=%d\n",rc);                              //~v97pI~
    return rc;                                                     //~v97pI~
}//isallascii                                                      //~v97pI~
//===============================================================================//~v981I~
//= get default printer using Gtk api                              //~v981I~
//===============================================================================//~v981I~
gboolean enumprinter(GtkPrinter *Ppprinter,gpointer *Pudata)       //~v981I~
{                                                                  //~v981I~
	gboolean rc=FALSE;                                             //~v981I~
    char *pdata;                                                   //~v981I~
    const char *pname;                                             //~v981I~
//*******************                                              //~v981I~
    UTRACEP("enumprinter tid=%p\n",ugettid());                     //~v984I~
	if (!Sglprinterinit)	//1st time                             //~v984I~
    {                                                              //~v984I~
    	Sglprinter=g_list_append(Sglprinter,Ppprinter);            //~v984I~
        UTRACEP("enumprinter glist append=%p,ctr=%d,data=%p\n",Ppprinter,g_list_length(Sglprinter),Sglprinter->data);//~v988R~
		g_object_ref(Ppprinter);                                   //~v984I~
        return FALSE;	//continue enum up to list all entry       //~v98eI~
    }                                                              //~v984I~
    pdata=(char*)Pudata;                                           //~v981I~
    pname=gtk_printer_get_name(Ppprinter);                         //~v981I~
    UTRACEP("cb_enumprinter:%s,udata=%s,virtual=%d\n",pname,(pdata?pdata:"NULL"),gtk_printer_is_virtual(Ppprinter));//~v981I~
#ifdef AAA                                                         //~v982I~
    if (!gtk_printer_is_virtual(Ppprinter))                        //~v98hR~
    {                                                              //~v982I~
//        GtkPrintBackend *be;                                     //~v982I~
//        GtkPrinter *ppdprn;                                      //~v982I~
////        GtkPrinterCups *ppdprn2;                               //~v982I~
//        GList *gl;                                               //~v982I~
//        be=gtk_printer_get_backend(Ppprinter);                   //~v982I~
//        ppdprn=gtk_printer_new(pname,be,gtk_printer_is_virtual(Ppprinter));//~v982I~
//        printf("enumprinter backend=%p,newpr=%p,has_detail=%d\n",be,ppdprn,gtk_printer_has_details(ppdprn));//~v982I~
////        ppdprn=gtk_printer_cups_new(pname,be,NULL);            //~v982I~
////        printf("enumprinter newpr=%p,has_detail=%d\n",ppdprn2,gtk_printer_has_details(ppdprn2));//~v982I~
////        printf("getppd %p\n",gtk_printer_cups_get_ppd(ppdprn2));//~v982I~
////        printf("getppdname %s\n",gtk_printer_cups_get_ppd_name(ppdprn2));//~v982I~
//        gl=gtk_print_backend_get_printer_list(be);               //~v982I~
//        printf("backend list %p\n",gl);                          //~v982I~
//          while (gl != NULL)                                     //~v982I~
//        {                                                        //~v982I~
//            printf("backend list data%p\n",gl->data);            //~v982I~
//            ppdprn=(GtkPrinter*)(gl->data);                      //~v982I~
//            printf("enumprinter newpr=%p,has_detail=%d\n",ppdprn,gtk_printer_has_details(ppdprn));//~v982I~
//            printf("backend printername=%s\n",gtk_printer_get_name(ppdprn));//~v982I~
//            gl=gl->next;                                         //~v982I~
//        }                                                        //~v982I~
		printf("enumprinter printer=%p,has_detail=%d\n",Ppprinter,gtk_printer_has_details(Ppprinter));//~v982I~
		if (!gtk_printer_has_details(Ppprinter))                   //~v982I~
        {                                                          //~v982I~
	        g_signal_connect (Ppprinter, "details-acquired",       //~v982I~
                       G_CALLBACK(printer_details_acquired),NULL/*data*/);//~v982I~
        	gtk_printer_request_details(Ppprinter);	//enum callback is another thread,but response delayed after operation_run//~v982I~
        }                                                          //~v982I~
    }                                                              //~v982I~
#endif                                                             //~v982I~
    if (pdata)                                                     //~v981I~
    {                                                              //~v981I~
        if (gtk_printer_is_default(Ppprinter))                     //~v981I~
            SdefaultprinterGtk=Ppprinter;
//      if (!strcmp(pdata,DEF_PRINTER)                             //~v98aR~
        if (!stricmp(pdata,DEF_PRINTER)                            //~v98aI~
        &&  gtk_printer_is_default(Ppprinter))                     //~v981I~
        {                                                          //~v981I~
	        g_object_ref(Ppprinter);                               //~v981I~
            SsrchprinterGtk=Ppprinter;                             //~v981I~
            rc=TRUE;    //stop enum                                //~v981I~
        }                                                          //~v981I~
//      if (!strcmp(pdata,GET_TOP_PRINTER)                         //~v98aR~
        if (!stricmp(pdata,GET_TOP_PRINTER)                        //~v98aI~
        &&  !gtk_printer_is_virtual(Ppprinter))                    //~v981I~
        {                                                          //~v981I~
	        g_object_ref(Ppprinter);                               //~v981I~
            SsrchprinterGtk=Ppprinter;                             //~v981I~
            rc=TRUE;    //stop enum                                //~v981I~
        }                                                          //~v981I~
//      if (!strcmp(pdata,pname))                                  //~v98aR~
        if (!stricmp(pdata,(char*)pname))                          //~v98aR~
        {                                                          //~v981I~
	        g_object_ref(Ppprinter);                               //~v981I~
            SsrchprinterGtk=Ppprinter;                             //~v981I~
            rc=TRUE;    //stop enum                                //~v981I~
        }                                                          //~v981I~
    }                                                              //~v981I~
    else                                                           //~v981I~
        if (gtk_printer_is_default(Ppprinter))                     //~v981I~
        {                                                          //~v981I~
            g_object_ref(Ppprinter);                               //~v981I~
            SdefaultprinterGtk=Ppprinter;                          //~v981I~
            rc=TRUE;    //stop enum                                //~v981I~
        }                                                          //~v981I~
    UTRACEP("enumprinter rc=%d\n",rc);                             //~v98aI~
    return rc;                                                     //~v981I~
}//enumprinter                                                     //~v981I~
//**************************************************************************
//void enumprinters(pfunc,Pprintername)                              //~v984I~//~v991R~
void enumprinters(GtkPrinterFunc pfunc,char *Pprintername)         //~v991I~
{                                                                  //~v984I~
	GList *gl;                                                     //~v984I~
    gboolean rc;                                                   //~v984I~
    GtkPrinter *printer;                                           //~v984I~
//*************************                                        //~v984I~
    UTRACEP("enumprinter 2nd,ctr=%d\n",g_list_length(Sglprinter)); //~v988R~
	for (gl=g_list_first(Sglprinter);gl;gl=gl->next)               //~v984I~
    {                                                              //~v984I~
    	printer=(GtkPrinter*)(gl->data);                           //~v984I~
        UTRACEP("enumprinter 2nd glist printer=%p\n",printer);     //~v988R~
		rc=enumprinter(printer,(gpointer)Pprintername);            //~v984I~
        if (rc)                                                    //~v984I~
        	break;                                                 //~v984I~
    }                                                              //~v984I~
}//enumprinters                                                    //~v984I~
//**************************************************************************//~v981I~
GtkPrinter *srchprinterGtk(char *Pprintername,char *Pprealname)    //~v981I~
{                                                                  //~v981I~
	GtkPrinterFunc pfunc;                                          //~v981I~
//*******************                                              //~v981I~
    pfunc=(GtkPrinterFunc)enumprinter;                             //~v98eI~
	if (!Sglprinter)                                               //~v984I~
    {                                                              //~v98eI~
        Sglprinterinit=0;                                          //~v984I~
		UTRACEP("srchprinterGtkn enum\n");                         //~v98eI~
		gtk_enumerate_printers(pfunc,Pprintername,NULL/*GdestroyNotify*/,TRUE/*wait*/);//create printer list//~v98eI~
    }                                                              //~v98eI~
//  else                                                           //~v984I~//~v98eR~
        Sglprinterinit=1;                                          //~v984I~
	UTRACEP("srchprinterGtk name=%s\n",Pprintername);              //~v988R~
    SsrchprinterGtk=NULL;                                          //~v981I~
//  pfunc=(GtkPrinterFunc)enumprinter;                             //~v981I~//~v98eR~
	if (Pprintername)                                              //~v981I~
    {                                                              //~v981I~
//      if (!Sglprinterinit)                                         //~v984I~//~v98eR~
//      {                                                            //~v984I~//~v98eR~
//        UTRACEP("srchprinterGtkn enum\n");                         //~v988R~//~v98eR~
//        gtk_enumerate_printers(pfunc,Pprintername,NULL/*GdestroyNotify*/,TRUE/*wait*/);//~v981I~//~v98eR~
//      }                                                            //~v984I~//~v98eR~
//      else                                                         //~v984I~//~v98eR~
		enumprinters(pfunc,Pprintername);	//get from GList       //~v984I~
                                                                   //~v984I~
    	UTRACEP("csubsrchprinterGtk req=%s,SsrchprinterGtk=%s\n",Pprintername,(SsrchprinterGtk?gtk_printer_get_name(SsrchprinterGtk):"NULL"));//~v981I~
    }                                                              //~v981I~
    if (!SsrchprinterGtk)	//getdefault or parm printer not found //~v981I~
		SsrchprinterGtk=SdefaultprinterGtk;                        //~v981R~
    if (!SsrchprinterGtk)	//no default defined                   //~v981I~
    {                                                              //~v981I~
		gtk_enumerate_printers(pfunc,GET_TOP_PRINTER/*user data*/,NULL/*GdestroyNotify*/,TRUE/*wait*/);//~v981I~
    	UTRACEP("csubsrchprinterGtk req=%s,SsrchprinterGtk=%s\n",Pprintername,(SsrchprinterGtk?gtk_printer_get_name(SsrchprinterGtk):"NULL"));//~v981I~
    }                                                              //~v981I~
    if (Pprealname)                                                //~v981I~
    {                                                              //~v981I~
	    *Pprealname=0;                                             //~v981I~
    	if (SsrchprinterGtk)                                       //~v981I~
	    	strcpy(Pprealname,gtk_printer_get_name(SsrchprinterGtk));//~v981I~
    }                                                              //~v981I~
    UTRACEP("srchprinterGtk printer=%s backend=%p\n",(SsrchprinterGtk?gtk_printer_get_name(SsrchprinterGtk):"no printer"),(SsrchprinterGtk?gtk_printer_get_backend(SsrchprinterGtk):NULL));//~v984R~
    return SsrchprinterGtk;                                        //~v981I~
}//srchprinterGtk                                                  //~v984R~
#ifdef GTKV2120                                                    //~v981I~
//****************************************************************************//~v984I~
//*wait callback response (on Mainthread)                          //~v984R~
//*(gtkprinter.c)                                                  //~v984I~
//****************************************************************************//~v984I~
void wait_callback()                                               //~v984I~
{                                                                  //~v984I~
    UTRACEP("waitcallback tid=%p\n",ugettid());                    //~v984I~
	UTRACEP("wait_callback\n");                                    //~v988R~
    Sloop=g_main_loop_new (NULL/*context*/,FALSE/*is_running*/);   //~v984I~
//  gdk_threads_leave ();                                          //~v984R~
    g_main_loop_run(Sloop);                                        //~v984I~
//  gdk_threads_enter();                                           //~v984R~
    g_main_loop_unref(Sloop);                                      //~v984I~
    Sloop=0;                                                       //~v984I~
}                                                                  //~v984I~
//****************************************************************************//~v984I~
//*wakeup gtk_main()                                               //~v984I~
//****************************************************************************//~v984I~
void wakeup_wait()                                                 //~v984I~
{                                                                  //~v984I~
    UTRACEP("wakeup tid=%p\n",ugettid());                          //~v984I~
	g_main_loop_quit(Sloop);                                       //~v984I~
}                                                                  //~v984I~
//****************************************************************************//~v984M~
//*callback:request_details                                        //~v984M~
//****************************************************************************//~v984M~
void                                                               //~v984M~
printer_details_acquired (GtkPrinter *printer,gboolean success,gpointer data/*null*/)//~v984M~
{                                                                  //~v984M~
	UTRACEP("printer_detai_acuired success=%d,name=%s\n",success,gtk_printer_get_name(printer));//~v988R~
    Shavedetail=success;                                           //~v984I~
//  gtk_main_quit();                                               //~v984R~
    wakeup_wait();                                                 //~v984I~
	UTRACEP("printer_detai_acuired gtk_main_quit()\n");            //~v988R~
}                                                                  //~v984M~
//=========================================================================//~v984I~
int requestPrinterDetail(GtkPrinter *Ppprinter)                    //~v984I~
{                                                                  //~v984I~
	int rc=0;                                                      //~v984I~
//*********************                                            //~v984I~
	UTRACEP("requestPrinterDetail\n");                             //~v988R~
    if (!gtk_printer_has_details(Ppprinter))                       //~v984I~
    {                                                              //~v984I~
		gtkinit();//for enumprinter                                //~v984I~
    	Shavedetail=-1;                                            //~v984I~
	    g_signal_connect (Ppprinter, "details-acquired",           //~v984I~
                       G_CALLBACK(printer_details_acquired),NULL/*data*/);//~v984I~
		gtk_printer_request_details(Ppprinter);                    //~v984I~
		UTRACEP("requestPrinterDetail before gtkmain()\n");        //~v988R~
//        gtk_main();	                                           //~v984R~
        wait_callback();                                           //~v984I~
		UTRACEP("requestPrinterDetail after gtkmain() Shavedetail=%d\n",Shavedetail);//~v988R~
        if (Shavedetail>0)                                         //~v984I~
        	rc=0;                                                  //~v984I~
        else                                                       //~v984I~
        	rc=4;                                                  //~v984I~
    }                                                              //~v984I~
	UTRACEP("requestPrinterDetail return rc=%d\n",rc);             //~v988R~
    return rc;                                                     //~v984I~
}//requestPrinterDetail                                            //~v984I~
//=========================================================================//~v981I~
GList *getcupspaperlistGtk(GtkPrinter *Ppprinter)                  //~v981I~
{                                                                  //~2B03aI~//~v981I~
	GList *gl0;                                                    //~v981R~
//************************************                             //~v981I~
    UTRACEP("getcupspaperlistGtk printer=%s\n",gtk_printer_get_name(Ppprinter));//~v981I~//~v986R~
    UTRACEP("getcupspaperlistGtk has_detail=%d\n",gtk_printer_has_details(Ppprinter));//~v981I~//~v986R~
    UTRACEP("getcupspaperlistGtk has_detail=%d\n",gtk_printer_has_details(Ppprinter));//~v988R~
                                                                   //~v987I~
    requestPrinterDetail(Ppprinter);                               //~v984I~
                                                                   //~v987I~
    UTRACEP("getcupspaperlistGtk has_detail=%d\n",gtk_printer_has_details(Ppprinter));//~v981I~//~v986R~
    gl0=gtk_printer_list_papers(Ppprinter);                        //~v981I~
    UTRACEP("getcupspaperlistGtk list=%p\n",gl0);                  //~v988R~
    UTRACEP("getcupspaperlistGtk gl0=%p,length=%d\n",gl0,g_list_length(gl0));//~v988R~
                                                                   //~v987I~
#ifdef   GTKV2200      //2.20                                      //~v987I~
    gtk_printer_get_hard_margins(Ppprinter,&Shardmargint,&Shardmarginb,&Shardmarginl,&Shardmarginr);//~v989R~
    UTRACEP("printer hard margin t=%f,b=%f,l=%f,r=%f\n",Shardmargint,Shardmarginb,Shardmarginl,Shardmarginr);//~v989R~
#endif //GTKV2120                                                  //~v987I~
    return gl0;                                                    //~v981I~
}//getcupspaperlistGtk                                             //~v981I~
#endif //GTKV2120                                                  //~v981I~
//=========================================================================//~v989I~
//=print_orientation_run:create_page_setup did not set margin       //~v989I~//~v98hR~
//=========================================================================//~v989I~
GtkPageSetup *create_pagesetup(GtkPrintSettings *Ppsettings)       //~v989R~
{                                                                  //~v989I~
    gdouble ww,hh,mt,mb,ml,mr;                                     //~v989I~
    int unit=GTK_UNIT_POINTS;                                      //~v989I~
    GtkPageSetup *setup;                                           //~v989I~
    GtkPaperSize *pps;                                             //~v989I~
	GtkPageOrientation ori;                                        //~v989I~
//********************************                                 //~v989I~
    pps=gtk_print_settings_get_paper_size(Ppsettings);             //~v989I~
    ori=gtk_print_settings_get_orientation(Ppsettings);            //~v989I~
                                                                   //~v98iI~
    setup=gtk_page_setup_new();                                    //~v989I~
    UTRACEP("create_pagesetup pps=%p,ori=%d\n",pps,ori);           //~v989R~//~v98iR~
    gtk_page_setup_set_paper_size(setup,pps);                      //~v989I~
    gtk_page_setup_set_orientation(setup,ori);                     //~v989I~
	hh=gtk_paper_size_get_height(pps,unit);                        //~v989R~
	ww=gtk_paper_size_get_width(pps,unit);                         //~v989R~
  	UTRACEP("create_pagesetup ww=%f,hh=%f point\n",ww,hh);         //~v98jR~
    ml=Sfmargins.left;                                             //~v989I~
    mr=ww-Sfmargins.right;                                         //~v989I~
    mt=hh-Sfmargins.top;                                           //~v989I~
    mb=Sfmargins.bottom;                                           //~v989I~
    gtk_page_setup_set_top_margin(setup,mt,GTK_UNIT_POINTS);       //~v989R~
    gtk_page_setup_set_bottom_margin(setup,mb,GTK_UNIT_POINTS);    //~v989R~
    gtk_page_setup_set_left_margin(setup,ml,GTK_UNIT_POINTS);      //~v989R~
    gtk_page_setup_set_right_margin(setup,mr,GTK_UNIT_POINTS);     //~v989R~
	UTRACEP("create_pagesetup t=%f,b=%f,l=%f,r=%f\n",mt,mb,ml,mr); //~v989I~
	UTRACEP("create_Sfmargins t=%f,b=%f,l=%f,r=%f\n",Sfmargins.top,Sfmargins.bottom,Sfmargins.left,Sfmargins.right);//~v989I~
    return setup;                                                  //~v989I~
}//create_pagesetup                                                //~v989I~
#ifndef MMM                                                        //~v98hI~
//=========================================================================//~v98hI~
void applyparmmargin(FRECT *Ppfrect,double Pww,double Phh)         //~v98hI~
{                                                                  //~v98hI~
    if (Sshiftdirection & SD_TOPM)                                 //~v98hI~
//      Ppfrect->top=Phh-Sparmmargint;                             //~v98hI~//~v9a0R~
        Ppfrect->top=(float)(Phh-Sparmmargint);                    //~v9a0I~
    if (Sshiftdirection & SD_BOTM)                                 //~v98hR~
//      Ppfrect->bottom=Sparmmarginb;                              //~v98hI~//~v9a0R~
        Ppfrect->bottom=(float)Sparmmarginb;                       //~v9a0I~
    if (Sshiftdirection & SD_LEFTM)                                //~v98hI~
//      Ppfrect->left=Sparmmarginl;                                //~v98hI~//~v9a0R~
        Ppfrect->left=(float)Sparmmarginl;                         //~v9a0I~
    if (Sshiftdirection & SD_RIGHTM)                               //~v98hI~
//      Ppfrect->right=Pww-Sparmmarginr;                           //~v98hI~//~v9a0R~
        Ppfrect->right=(float)(Pww-Sparmmarginr);                  //~v9a0I~
    UTRACEP("applyparmmargin ww=%f,hh=%f,new margin t=%f,b=%f,l=%f,r=%f\n",Pww,Phh,Ppfrect->top,Ppfrect->bottom,Ppfrect->left,Ppfrect->right);//~v98hI~
}//applyparmmargin                                                 //~v98hI~
#endif                                                             //~v98hI~
#ifdef GTKV2140                                                    //~v98mI~
//=========================================================================//~v98mI~
char *get_printer_defaultpapersize(GtkPrinter *Ppprinter,char *Pform)//~v98mR~
{                                                                  //~v98mI~
	GtkPageSetup *setup;                                           //~v98mI~
	GtkPaperSize *pps;                                             //~v98mI~
    char *pname,*pprintername;                                     //~v98mR~
//*************************************                            //~v98mI~
    UTRACEP("get_printer_defaultpapersize form=%s,printer=%s\n",Pform,gtk_printer_get_name(Ppprinter));//~v98mR~
    pprintername=(char*)gtk_printer_get_name(Ppprinter);           //~v98mR~
	requestPrinterDetail(Ppprinter);                               //~v98mI~
	setup=gtk_printer_get_default_page_size(Ppprinter);//v2.14.0   //~v98mR~
    if (!setup)                                                    //~v98mI~
    	return Pform;                                              //~v98mI~
	pps=gtk_page_setup_get_paper_size(setup);                      //~v98mI~
    if (!pps)                                                      //~v98mI~
    	return Pform;                                              //~v98mI~
    pname=(char*)gtk_paper_size_get_name(pps);                     //~v98mI~
	printf("\n%s default papersize setting is:",pprintername);     //~v98nR~
	printPaperSize((char*)gtk_paper_size_get_name(pps),(char*)gtk_paper_size_get_display_name(pps));//~v98nR~
    UTRACEP("get_printer_defaultpapersize name=%s,display=%s,ppdname=%s,margint=%f,b=%f,l=%f,r=%f\n",//~v98mR~
    		pname,gtk_paper_size_get_display_name(pps),gtk_paper_size_get_ppd_name(pps),//~v98mI~
    		gtk_page_setup_get_top_margin(setup,GTK_UNIT_POINTS),  //~v98mI~
    		gtk_page_setup_get_bottom_margin(setup,GTK_UNIT_POINTS),//~v98mI~
    		gtk_page_setup_get_left_margin(setup,GTK_UNIT_POINTS), //~v98mI~
    		gtk_page_setup_get_right_margin(setup,GTK_UNIT_POINTS));//~v98mI~
    return pname;                                                  //~v98mI~
}//get_printer_defaultpapersize                                    //~v98mI~
#endif	//GTKV2140                                                 //~v98mI~
#endif //GTKPRINT                                                  //~v989R~
