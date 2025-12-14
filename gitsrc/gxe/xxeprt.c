//*CID://+@@@@R~: update#=  247;                                   //~@@@@R~
//******************************************************************************//~v003I~
//var8:140127 gtk3 suppott                                         //~@@@@I~
//vap1:131220 (LNX)configure aupports NOPRINT for RedHat5.8        //~vap1I~
//vamv:131017 2p print for lc file,right half top colomn is differ for each line by ligature(katakana is dbcs but gliph width is not wide.//~vamsI~
//vamt:131015 (GtkPrint)accept minus value of margin to adjust origin for each printer's paper folder shift attachment.(case of that b5 origin is relativ to a4 origin)//~vamtI~
//vams:131010 Ligature off when Bin,VHEX,HEX mode                  //~vampI~
//vamp:131007 del vamk by vamm                                     //~vampI~
//vamn:131007 (Gnomeprint:Bug) rc=0(FALSE) for gnome_print_config_set(Gpprtconf,GNOME_PRINT_KEY_PAGE_ORIENTATION,pori),use gnome_print_rotate//~vamnI~
//vamm:131007 (Bug)Gnomeprint:missig set papersize to config,reason of B5 print range err is this and not of vami//~vamkI~
//vamk:131006 margin not by int but by gdouble for accuracy        //~vamkR~
//vamj:131006 vama is for landscape only                           //~vamjI~
//vami:131006 page origin affected by scale(gnomeprint for B5)(cairo_translate is independent from scale)//~vamiI~
//vamd:131002 (BUG)hardcopy:so not rounddown which ignore fullpage wysiwyg//~vamdI~
//vamc:131002 (BUG)should sw margin top and left when landscape    //~vamcI~
//vam5:130928 (BUG)scale to fontsize is not to fonth or fontw but to size itself//~vam5I~
//vam2:130927 page dialog margin should be additional to hardware margin//~vam2I~
//vam0:130911 for distro removed gnome-print,use GTKprint          //~vam0I~
//vaff:120613 (FC12)avoid uninitialized variable warning by gcc 4.4.4 on FC12(compile optio -Ox is required also)//~vaffI~
//va8a:100926 (WXE)end wxp work at end print                       //~va8aI~
//va88:100926 (WXE)2p print;right half contline dbcs override left half lineno fld//~va88I~
//va80:100917 (WXEXXE)print ebcfile by ucs                         //~va80I~
//va6y:000706 CUPs default printer is not same as gnome default    //~va6yI~
//va49:100406 (WXE:BUG)wxe print abend when VHEX and HHEX.         //~va49I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//v75X:070526 (XXE:BUG)assertion fail face!=NULL, gnome_font_find  //~v75XI~
//v685:060322 dnd support "file copy into the dir slected" and even in inter-split-screen.//~v685I~
//v666:050817 (XXE)for FC4:libgnome default setting is not syncronouse;so request gnome_print config_default twice after gtkmain//~v666I~
//v004:050802 (BUG:WXE)hardcopy;fullpage is allways effective      //~vX04I~
//vXXE:050611 new for XXE                                          //~vXXEI~
//v62W:050422 (WXE)maximum cell height definition for small doc    //~v62WI~
//v62M:050417 (WXE)more ajust when calcurated maxrow is minus when no parm specified//~v62MI~
//            (reduce font width by expanding maxrow)              //~v62MI~
//v627:050309 (WXE)vhex print support                              //~v627I~
//v53q:030930 (WXE:BUG) area not freed when print canceled because endprinting is not called//~v53qI~
//v51h:030525 (WXE)col/row by font size specification              //~v51hI~
//******************************************************************************//~v003I~
#include <stdio.h>                                                 //~@@@@R~
#include <stdlib.h>                                                //~@@@@R~
#include <string.h>                                                //~@@@@R~
#ifndef OPTGTK3                                                    //~@@@@R~
#include <gnome.h>                                                 //~vXXEI~
#else                                                              //~@@@@R~
#include <gtk/gtk.h>                                               //~@@@@R~
#include <gdk/gdkx.h>                                              //~@@@@R~
#endif                                                             //~@@@@R~
#ifndef NOPRINT                                                    //~vam0R~
	#ifdef GTKPRINT
		#ifndef OPTGTK3                                            //~@@@@R~
#include <gtk/gtkprinter.h>                                        //~vam0I~
		#else                                                      //~@@@@R~
			#include <gtk/gtkunixprint.h>                          //~@@@@R~
		#endif                                                     //~@@@@R~
	#else    //!GTKPRINT
#include <libgnomeprint/gnome-print.h>                             //~vXXEI~
#include <libgnomeprint/gnome-print-job.h>                         //~vXXER~
	#endif   //!GTKPRINT
#endif //!NOGOMEPRINT                                              //~vam0I~
                                                                   //~vXXEI~
#include    "ulib.h"                                               //~vXXEM~
#include    "udbcschk.h"                                           //~vXXEM~
#include    "utrace.h"                                             //~vXXEM~
#include    "ustring.h"                                            //~vamsI~
                                                                   //~vXXEI~
#include    "gxe.h"                                                //~vXXEI~
#include    "xxeres.h"                                             //~vXXER~
#include    "xxedef.h"                                             //~vXXEI~
#include    "xxemain.h"                                            //~vXXEI~
#include    "xxecsub.h"                                            //~vXXEI~
#include    "gxepage.h"                                            //~vXXER~
#include    "xxexei.h"                                             //~vXXEI~
                                                                   //~vXXEI~
                                                                   //~v003I~
//===============================================================================//~2B09I~
//define MM2POINT(mm)    ((float)(((float)mm)*72/25.4)) //1inch=72point=25.4mm//~va6yR~
#ifdef UTF8UCS2                                                    //~va20I~
#define VHEXLINEID      0xff     //vhexline of pagewk              //~va20I~
#endif                                                             //~va20I~
//===============================================================================//~2B18I~
#ifndef XXE                                                        //~vXXEI~
#define FORM_CTR 7                                                 //~2B09I~
#define FORM_DEFAULT_INDX 1 // A4                                  //~2B09I~
	static char *Sformtbl[FORM_CTR]={"A3","A4","A5","B4","B5","Letter","Leagal"};//~2B09I~
    static int   Sformsz[FORM_CTR][2]={                            //~2B09I~
					{297,420},	//A3                               //~2B09I~
					{210,297},	//A4                               //~2B09I~
					{148,210},	//A5                               //~2B09I~
					{257,364},	//B4                               //~2B09I~
					{182,257},	//B5                               //~2B09I~
					{216,279},	//letter                           //~2B09I~
					{216,355} 	//leagal                           //~2B09I~
                    };                                             //~2B09I~
    static int   Sdmformtype[FORM_CTR]={//for devmode chng         //~2B24I~
					DMPAPER_A3,                                    //~2B24I~
					DMPAPER_A4,                                    //~2B24I~
					DMPAPER_A5,                                    //~2B24I~
					DMPAPER_B4,                                    //~2B24I~
					DMPAPER_B5,                                    //~2B24I~
					DMPAPER_LETTER,   // 8.5*11 inch               //~2B24R~
					DMPAPER_LEGAL};   // 8.5*14                    //~2B24R~
#endif                                                             //~vXXER~
//===============================================================================//~vXXEI~
#ifndef NOPRINT                                                    //~vam0I~
static  int  Mprtclineno;   	    	//current lineno           //~vXXEI~
//static  CFont *Mpprtfont;                                        //~vXXEI~
static  int  Mprttype;         	//print screen type 'D'/'F'        //~vXXEI~
static  char Mprtfnm[_MAX_PATH];	//filename to print            //~vXXEI~
static  int  Mprtlinenosz;       	//lineno fldsz                 //~vXXEI~
static  char Mprtlinenoedit[8];  	//lineno edit fmt              //~vXXEI~
#endif //!NOGOMEPRINT                                              //~vam0I~
static  char *Mprtlinework;       	//print line work to edit lineno//~vXXEI~
static  char *Mprtpagework;       	//print page work to edit 2p form//~vXXEI~
#ifndef NOPRINT                                                    //~vam0I~
static  char Mprtftime[32];			//filetime to print            //~vXXEI~
static  char Mprtsystime[32];		//current time to print        //~vXXEI~
static  int  Mpfontoffsx,Mpfontoffsy;	//font position in cell    //~vXXEI~
static  int  Mformszh,Mformszw;	//form size                        //~vXXER~
//static  CDocument *Mpdoc;                                        //~vXXEI~
static GdkColor Sprtbgcolor=COLOR_WHITE,Sprtfgcolor=COLOR_BLACK;   //~vXXER~
static gdouble Sfmm2pt=2.834646;// 1mm is 2.8point                 //~vXXER~
#endif //!NOGOMEPRINT                                              //~vam0M~
void prtgetcupsorgt(RECT *Pprect,RECT *Porg,int *Ppwidth,int *Pphight);//~vamdI~
//===============================================================================//~vXXEI~
//  void afterprint(void);                                         //~vXXEM~//~va8aR~
//	int  prtgetformsz(int Plandscape,char *Pform,int *Ppw,int *Pph);//~vXXEI~
//	int prtgetformtype(char ***Ppformtbl);                         //~vXXEI~
	int  prtscr(void);                                             //~vXXER~
	int  prtfile(void);                                            //~vXXER~
	int  prttextout(/*CDC *Pdc,*/int Pyy,char *Pdata,int Plen);    //~vXXER~
	int  prttextout_NoLigature(int Pyy,char *Pdata,int Plen);      //~vampI~
	void prttextout2p(int Popt,int Pyy,char *Pdata,int Plen,int Plinenofldlen,int Pposr,int Pposhhexl,int Pposhexr);//~vamsR~
    #define PRTTO2PO_VHEXLINE_L   0x01   //left is vhexline        //~vamsI~
    #define PRTTO2PO_VHEXLINE_R   0x02   //right is vhexline       //~vamsI~
#ifdef UTF8UCS2                                                    //~va20I~
	int  prttextoutw(int Popt,int Pyy,int Pcol,char *Pdata,char *Pdbcs,int Plen,int Plinenofldlen);//~va20R~
    #define PRTTOWO_PREVIEW    0x01                                //~va80I~
    #define PRTTOWO_HHEX       0x02                                //~va80I~
    #define PRTTOWO_VHEXLINE   0x04   //when M2P                   //~va80I~
    #define PRTTOWO_LRECLMASK  0xff00                              //~va80I~
    #define PRTTOWO_LRECLMASKSHIFT  8                              //~va80I~
#endif                                                             //~va20I~
	int  prtlineout(int Pyy,int Plen);                             //~vXXER~
#ifndef NOPRINT                                                    //~vam0R~
	#ifdef GTKPRINT
	void prtviewporthcopyGtkPrint();                               //~vam0I~
	void prtviewportfileGtkPrint();                                //~vam0I~
	#else    //!GTKPRINT
	void prtviewporthcopy(GnomePrintContext *Ppprtctxt);           //~vXXER~
	void prtviewportfile(GnomePrintContext *Ppprtctxt);            //~vXXER~
	#endif   //!GTKPRINT
#endif //!NOGOMEPRINT                                              //~vam0I~
//	void prtmarginrect(/*CDC *Pdc,*/RECT *Pprect);                 //~vamkR~
//	void prtmarginrect(/*CDC *Pdc,*/RECT *Pprect,gdouble *Pptblr); //~vamkR~//~vampR~
	void prtmarginrect(/*CDC *Pdc,*/RECT *Pprect);                 //~vampI~
	void prtscrbgrect(void);                                       //~vXXER~
	int  prtcreatefont(void);                                      //~vXXEI~
//===============================================================================//~vXXEI~
//                                                                 //~vXXEI~
//===============================================================================//~vXXEI~
#ifndef NOPRINT                                                    //~vam0R~
	#ifdef GTKPRINT                                                //~vam0I~
void  xxemain_prtinit(void)                                        //~vXXEI~
{                                                                  //~vXXER~
//	GList *pgl;                                                    //~vXXER~
//	const GnomePrintUnit *pgpumm,*pgpupt;                          //~vXXER~
//  gdouble fbase2mm=0,fbase2pt=0;                                 //~vXXER~
//************************************                             //~vXXEI~
#ifndef OPTGTK3                                                    //~@@@@R~
    Gpprtgc=gdk_gc_new(Gpview->window);                            //~vXXEI~
#else	//done at scrinit                                          //~@@@@R~
#endif                                                             //~@@@@R~
//color                                                            //~vXXEI~
    gdk_colormap_alloc_color(Gpcolormap,&Sprtbgcolor,FALSE,TRUE);//writeable?,bestmatch?//~vXXER~
    gdk_colormap_alloc_color(Gpcolormap,&Sprtfgcolor,FALSE,TRUE);//writeable?,bestmatch?//~vXXER~
    gdk_gc_set_foreground(Gpprtgc,&Sprtfgcolor);                   //~vXXER~
    gdk_gc_set_background(Gpprtgc,&Sprtbgcolor);                   //~vXXER~
//gnomeprint                                                       //~vXXEI~
    dprintf("prt_init\n");                                         //~v666R~
//  csubgetdefaultprinter(0);	//get default dest by cups to Mprinter_cupsdefault for uprtgetconfig//~vam0R~
//    uprtgetconfig((void*)Gpprtconf,0);  //avoid "WARNING could not GPAreference Printer"//~va6yR~//~vam0R~
//    pgpumm=gnome_print_unit_get_by_name("MilliMeter");             //~vXXER~//~vam0R~
//    pgpupt=gnome_print_unit_get_by_name("Point");                  //~vXXEI~//~vam0R~
//    Sfmm2pt=1.0;                                                   //~vXXEI~//~vam0R~
//    gnome_print_convert_distance(&Sfmm2pt,pgpumm,pgpupt);   //mm-->pt//~vXXEI~//~vam0R~
//    dprintf("1mm->%lfPoint\n",Sfmm2pt);                            //~v666R~//~vam0R~
    Sfmm2pt=MM2POINT(1); //360.0f/127.0f;  //2.8point/mm;1point=127/360mm         //~vam0R~//~vam2R~
	return;                                                        //~vXXEI~
}//xxemain_prtinit                                                 //~vXXEI~
	#else    //!GTKPRINT                                           //~vam0I~
void  xxemain_prtinit(void)                                        //~vXXEI~
{                                                                  //~vXXER~
//	GList *pgl;                                                    //~vXXER~
	const GnomePrintUnit *pgpumm,*pgpupt;                          //~vXXER~
//  gdouble fbase2mm=0,fbase2pt=0;                                 //~vXXER~
//************************************                             //~vXXEI~
    Gpprtgc=gdk_gc_new(Gpview->window);                            //~vXXEI~
//color                                                            //~vXXEI~
    gdk_colormap_alloc_color(Gpcolormap,&Sprtbgcolor,FALSE,TRUE);//writeable?,bestmatch?//~vXXER~
    gdk_colormap_alloc_color(Gpcolormap,&Sprtfgcolor,FALSE,TRUE);//writeable?,bestmatch?//~vXXER~
    gdk_gc_set_foreground(Gpprtgc,&Sprtfgcolor);                   //~vXXER~
    gdk_gc_set_background(Gpprtgc,&Sprtbgcolor);                   //~vXXER~
//gnomeprint                                                       //~vXXEI~
    dprintf("prt_init\n");                                         //~v666R~
    csubgetdefaultprinter(0);	//get default dest by cups to Mprinter_cupsdefault for uprtgetconfig//~va6yR~
    uprtgetconfig((void*)Gpprtconf,0);	//avoid "WARNING could not GPAreference Printer"//~va6yR~
//conversion ratio of margin                                       //~vXXEI~
//    pgl=gnome_print_unit_get_list(GNOME_PRINT_UNIT_ABSOLUTE);    //~vXXER~
//    while(pgl!=NULL)                                             //~vXXER~
//    {                                                            //~vXXER~
//        ppu=(GnomePrintUnit*)pgl->data;                          //~vXXER~
//        dprintf("list base=%d unittobase=%lf,name=%s,abbr=%s,plural=%s,abbr_plural=%s\n",ppu->base,ppu->unittobase,ppu->name,ppu->abbr,ppu->plural,ppu->abbr_plural);//~v666R~
//        if (!strcmp(ppu->abbr,"mm"))    //milimeter              //~vXXER~
//            fbase2mm=ppu->unittobase;       //1mm is n baseunit  //~vXXER~
//        else                                                     //~vXXER~
//        if (!strcmp(ppu->abbr,"Pt"))            //Point          //~vXXER~
//            fbase2pt=ppu->unittobase;       //1point is n baseunit//~vXXER~
//        pgl=pgl->next;                                           //~vXXER~
//    }                                                            //~vXXER~
//    gnome_print_unit_free_list(pgl);                             //~vXXER~
//    if (fbase2mm && fbase2pt)                                    //~vXXER~
//        Sfpt2mm=fbase2mm/fbase2pt;                               //~vXXER~
	pgpumm=gnome_print_unit_get_by_name("MilliMeter");             //~vXXER~
	pgpupt=gnome_print_unit_get_by_name("Point");                  //~vXXEI~
    Sfmm2pt=1.0;	                                               //~vXXEI~
    gnome_print_convert_distance(&Sfmm2pt,pgpumm,pgpupt);	//mm-->pt//~vXXEI~
    dprintf("1mm->%lfPoint\n",Sfmm2pt);                            //~v666R~
	return;                                                        //~vXXEI~
}//xxemain_prtinit                                                 //~vXXEI~
	#endif   //!GTKPRINT                                           //~vam0I~
#endif //!NOGOMEPRINT                                              //~vam0I~
//===============================================================================//~2B02I~
//called once first at print start                                 //~2B02R~
//parm:pinfo;0 if preview                                          //~2B04I~
//rc:   FALSE:print skip                                           //~2B10I~
//===============================================================================//~2B02I~
#ifndef NOPRINT                                                    //~vam0I~
int xxemain_onprepareprinting(int Pnotpreviewsw)                   //~vam0R~
{                                                                  //~2B02I~
	int maxpage=1,totline,formw,formh,linenofw,col2p,totrow;       //~2C01R~
    int rc=TRUE,len,len2;                                          //~vXXER~
    int /*pfontsz,*/fonth,fontw;                                   //~v51hR~
    void *pfh;                                                     //~2B09I~
    void *pcw=0;                                                   //~v627I~
#ifdef UTF8UCS2                                                    //~va20I~
    int swutf8file;                                                //~va20I~
#endif                                                             //~va20I~
	int allowance=256;                                             //~va80I~
//************************************                             //~2B02I~
//  Mprtlinework=0;                                                //~v53qR~
//  Mprtpagework=0;                                                //~v53qR~
//  afterprint();                                                  //~v53qI~//~va8aR~
  	afterprint(0);                                                 //~va8aI~
    Mprtclineno=0;                                                 //~2B04I~
//set Mhcopysw now,not later                                       //~vX04I~
	if (!Mhcopysw)                                                 //~vX04I~
    {                                                              //~va8aI~
		if (wxe_getpcw(0)==PRTTYPE_HCOPY)                          //~vX04I~
        	Mhcopysw=1;                                            //~vX04I~
    }                                                               //~vX04I~//~va8aR~
//create printer font                                              //~v51hI~
    if (prtcreatefont()) //font not found                          //~vXXER~
    	return FALSE;	//bypass print                             //~vXXEI~
    if (Mchkpfontsz)    //fontsize specified                       //~vX04R~
    {                                                              //~v51hI~
        fonth=Mpfontszh,fontw=Mpfontszw,                           //~v51hR~
        Mdrawcellh=Mpcellszh,Mdrawcellw=Mpcellszw;                 //~v51hR~
        if (!Mdrawcellh)        //if cellh=0                       //~v51hR~
        	Mdrawcellh=fonth;	//same as font height              //~v51hR~
        if (!Mdrawcellw)        //if cellh=0                       //~vXXEI~
        	Mdrawcellw=fontw;	//same as font height              //~vXXER~
    }                                                              //~v51hI~
    else                                                           //~v51hR~
    {                                                              //~v51hI~
//      fonth=Mfontheight,fontw=Mfontwidth,                        //~vXXER~
//      Mdrawcellh=Mcellh,Mdrawcellw=Mcellw;                       //~vXXER~
        fonth=Mpfontszh,fontw=Mpfontszw,                           //~vXXEI~
        Mdrawcellh=fonth,Mdrawcellw=fontw;                         //~vXXER~
    }                                                              //~v51hI~
//  formid=prtgetformsz(Mlandscape,Mformtype,&formw,&formh);       //~vXXER~
    gxepage_prtgetformsz(Mlandscape,Mformtype,&Mformszw,&Mformszh);//~vXXER~
    formw=Mformszw; formh=Mformszh;                                //~vXXEI~
dprintf("prepare print formsz=%s,land=%d\n",Mformtype,Mlandscape); //~v666R~
	if (!Mhcopysw)	//not printscreen                              //~2B23R~
    {                                                              //~2B07I~
//  	Mprttype=prtgetscrdata(0,Mwwscrprt,&pfh,Mprtfnm,           //~v627R~
    	Mprttype=xxemain_prtgetscrdata(0,Mwwscrprt,&pcw,&pfh,Mprtfnm,//~vXXER~
					&totline,&Mprtmaxlrecl,&Mprtlinenosz,&Mprtcmaxlrecl,&Mprtlnotype);//~2C07R~
#ifdef UTF8UCS2                                                    //~va20I~
        swutf8file=WXEPRINT_UTF8MODE();                            //~va20I~
#endif                                                             //~va20I~
    	if (Mprttype>0)	//file/dir screen                          //~2B30R~
    	{                                                          //~2B09M~
            Mprtdatamaxcol=                                        //~v51hI~
            Mprtcmaxcol=Mprtcol;                                   //~2B09R~
            Mprtdatamaxrow=                                        //~v51hI~
            Mprtcmaxrow=Mprtrow;                                   //~2B09R~
            UTRACEP("xxemain_onprepareprinting Mprtcol=%d,Mprtrow=%d\n",Mprtcol,Mprtrow);//~vamdI~
            if (Mprttype==PRTTYPE_VHEXTEXT                         //~v627R~
            ||  Mprttype==PRTTYPE_VHEXHHEX                         //~va49I~
            ||  Mprttype==PRTTYPE_VHEXBIN)                         //~v627R~
            {                                                      //~v627I~
                if (Mprtdatamaxrow>=3)                             //~v627I~
                    Mprtdatamaxrow=(Mprtdatamaxrow/3)*3;    //multiple of 3 line//~v627R~
            UTRACEP("xxemain_onprepareprinting vhex Mprtdatamaxrow=%d,Mprtrow=%d\n",Mprtdatamaxrow);//~vamdI~
            }                                                      //~v627I~
            if (Mlinenumber)                                       //~2B17I~
                linenofw=Mprtlinenosz+1;                           //~2B17I~
            else                                                   //~2B17I~
                linenofw=0;                                        //~2B17I~
//          if (!Mprtcol || !Mprtrow)                              //~v51hR~
            if (!Mprtcol || !Mprtrow || Mchkpfontsz)               //~v51hI~
            {                                                      //~2B09R~
//              gxepage_getformsz(Mlandscape,Mformtype,&formw,&formh);//~vXXER~
                formw-=max(Mmarginl,MARGIN_FORM_CLIP)+max(Mmarginr,MARGIN_FORM_CLIP);//~2B23R~
                formh-=max(Mmargint,MARGIN_FORM_CLIP)+max(Mmarginb,MARGIN_FORM_CLIP);//~2B23R~
		        if (M2p)                                           //~2B09I~
        		    col2p=Mprt2pcol;                               //~2B09R~
        		else                                               //~2B09I~
            		col2p=0;                                       //~2B09I~
//                if (Mchkpfontsz)                                 //~v51hR~
//                    pfontsz=(Mpfontszw<<16)|Mpfontszh;           //~v51hR~
//                else                                             //~v51hR~
//                    pfontsz=0;                                   //~v51hR~
//              if (prtajustcolrow(Mprttype,formw,formh,Mheader+Mfooter,Mcellw,Mcellh,//~v51hR~
                if (xxemain_prtajustcolrow(Mprttype,formw,formh,Mheader+Mfooter,Mdrawcellw,Mdrawcellh,//~vXXER~
//                              Mprtcmaxlrecl,totline,linenofw,col2p,&Mprtcmaxcol,&Mprtcmaxrow);//~v51hR~
                                Mprtcmaxlrecl,totline,linenofw,col2p,&Mprtcmaxcol,&Mprtcmaxrow,//~v51hR~
//								Mchkpfontsz,&Mprtdatamaxcol,&Mprtdatamaxrow))//~v62WR~
								Mchkpfontsz,Mpcellszhmax,&Mprtdatamaxcol,&Mprtdatamaxrow))//~v62WI~
                    return FALSE;//skip print by parm err          //~v51hI~
            }                                                      //~2B09R~
//  		maxpage=wxe_prtgetmaxpage(pfh,&Mprtcmaxlrecl,&Mprtcmaxcol,Mprtcmaxrow,&totrow);//~v51hR~
//     		maxpage=wxe_prtgetmaxpage(pfh,&Mprtcmaxlrecl,&Mprtcmaxcol,//~v627R~
     		maxpage=wxe_prtgetmaxpage(pcw,pfh,&Mprtcmaxlrecl,&Mprtcmaxcol,//~v627I~
										&Mprtdatamaxcol,Mprtdatamaxrow,&totrow);//~v51hR~
            switch(Mprtlnotype)                                    //~2C07R~
            {                                                      //~2B30I~
            case PRTLNOTYPE_HEX:                                   //~2C07R~
                sprintf(Mprtlinenoedit,"%%0%dX ",Mprtlinenosz);    //~2B30I~
                break;                                             //~2B30I~
            case PRTLNOTYPE_hex:                                   //~2C07I~
                sprintf(Mprtlinenoedit,"%%0%dx ",Mprtlinenosz);    //~2B30I~
                break;                                             //~2B30I~
            default:                                               //~2B30I~
                sprintf(Mprtlinenoedit,"%%0%dd ",Mprtlinenosz);    //~2B30R~
            }                                                      //~2B30I~
            Mprtlinenosz++;                                        //~2B04I~
            if (Mprttype==PRTTYPE_DIR)                             //~2C07I~
            {                                                      //~2C08I~
		        len=Mprtmaxlrecl;	//dirlist entry full size      //~2C08R~
		        len2=len+len;        //for dbcs chk                //~2C08I~
            }                                                      //~2C08I~
            else                                                   //~2C07I~
            {                                                      //~2C08I~
		        len2=len=Mprtcmaxcol;	//len2:for lineworksz,len:for 2p work sz//~2C07R~
                switch(Mprttype)                                   //~2C08R~
                {                                                  //~2C08R~
                case PRTTYPE_VHEXTEXT:                             //~v627R~
                case PRTTYPE_VHEXBIN:                              //~v627I~
                    len2+=len+len;  //3line mode(data+hex1+hex2)   //~v627I~
#ifdef UTF8UCS2                                                    //~va20I~
            		if (swutf8file)                                //~va20I~
                    	len2+=len;	//dbcs                         //~va20I~
                    else                                           //~va80I~
					if (WXEPRINT_EBCBYUCS())                       //~va80I~
                    	len2+=len;	//dbcs                         //~va80I~
#endif                                                             //~va20I~
                    break;                                         //~v627I~
                case PRTTYPE_BIN:                                  //~2C08R~
                    len2+=len;  //data and dbcs for tabdisplay call//~2C08R~
                    break;                                         //~2C08R~
                case PRTTYPE_HEX:                                  //~2C08R~
                case PRTTYPE_VHEXHHEX:  //hhex+vhex                //~va49I~
                    len2+=(Mprtmaxlrecl+Mprtmaxlrecl)+Mprtmaxlrecl;//hexeditwk+dbcs//~2C08R~
                    break;                                         //~2C08R~
#ifdef UTF8UCS2                                                    //~va20I~
                default:                                           //~va20I~
            		if (swutf8file)                                //~va20I~
                    	len2+=len;       //dbcs                    //~va20I~
                    else                                           //~va80I~
					if (WXEPRINT_EBCBYUCS())                       //~va80I~
                    	len2+=len;       //dbcs                    //~va80I~
#endif                                                             //~va20I~
                }                                                  //~2C08R~
            }                                                      //~2C08I~
            len+=linenofw;                                         //~2B30R~
            len2+=linenofw; 	//line work sz                     //~2B30I~
//          Mprtlinework=(char*)umemalloc(len2);                   //~2B30R~//~va80R~
            Mprtlinework=(char*)umemalloc(len2+allowance);         //~va80I~
UTRACEP("Mprtlinework len=x%x,len2=x%x,addr=%p,swbyucs=%x\n",len,len2,Mprtlinework,WXEPRINT_EBCBYUCS());//~va80I~
            if (M2p)	                                           //~2B04I~
            {                                                      //~2B17I~
            	len+=len+Mprt2pcol;                                //~2B17R~
#ifdef UTF8UCS2                                                    //~va20I~
	          	len+=len;	//dbcstbl                              //~va20I~
#endif                                                             //~va20I~
                len*=(Mprtcmaxrow+(Mheader+Mfooter)*2);            //~2B17R~
                Mprtpagework=(char*)umemalloc(len);                //~2B17I~
            	maxpage=(maxpage+1)>>1;                            //~2B04I~
            }                                                      //~2B17I~
            wxe_prtgetftime(pfh,Mprtftime,Mprtsystime);            //~2B09R~
    	}                                                          //~2B02I~
//      else                                                       //~vX04R~
//      if (Mprttype==PRTTYPE_HCOPY)	//pannel                   //~vX04R~
//      	Mhcopysw=1;                                            //~vX04R~
        else                    //file in bin/hex mode             //~2B10I~
        	rc=FALSE;           //bypass print                     //~2B10I~
    }                                                              //~2B07I~
    Mprtmaxpage=maxpage;                                           //~2B02I~
    if (Mhcopysw)                                                  //~2B23R~
		strcpy(Mprtfnm,PRTSCRID);                                  //~2B09R~
	return rc;                                                     //~2B10R~
}//onprepareprinting                                               //~2B02R~
#endif //!NOGOMEPRINT                                              //~vam0I~
//===============================================================================//~2B07I~
//get print data for current scr                                   //~2B10R~
//maxlrecl :output max lrecl of plh                                //~2C07I~
//cmaxlrecl:output max lrecl to be printed ajusted for bin file by width open parm//~2C07I~
//ret :scr type 'F':fie,'D':dir,-1:other panel                     //~2B07I~
//===============================================================================//~2B07I~
int xxemain_prtgetscrdata(int Phcopysw,BOOL Pwwscrprt,void **Pppcw,void **Pppfh,char *Poutfnm,//~vXXER~
					int *Pptotlineno,int *Ppmaxlrecl,int *Pplinenodigit,int *Ppcmaxlrecl,int *Pplnotype)//~2C07R~
{                                                                  //~2B07I~
	int  maxlen,totline=0,scrtype,linenosz,pfhwidth;               //~vXXER~
//************************************                             //~2B07I~
    *Pplnotype=0;                                                  //~2C07I~
	if (Phcopysw)                                                  //~2B24R~
    {                                                              //~v627I~
    	scrtype=PRTTYPE_HCOPY;                                     //~2B30R~
        *Pppcw=0;                                                  //~v627I~
    }                                                              //~v627I~
    else                                                           //~2B10I~
//  	scrtype=wxe_prtgetfnm(Poutfnm,Pppfh,Pplnotype);	//file/dir/screen//~v627R~
    	scrtype=wxe_prtgetfnm(Poutfnm,Pppcw,Pppfh,Pplnotype);	//file/dir/screen//~v627I~
    if (scrtype<0)                                                 //~2B07I~
    {                                                              //~2B10I~
        if (scrtype!=PRTTYPE_HCOPY)                                //~2B30R~
//      	umsgbox("Not supported edit mode");                    //~v685R~
        	umsgbox("Not supported edit mode",MB_OK);              //~v685I~
        else                                                       //~2B10I~
        {                                                          //~2B10I~
            *Pppfh=0;                                              //~2B10R~
            strcpy(Poutfnm,PRTSCRID);                              //~2B10R~
//            if (Pwwscrprt)      //wiswyg                         //~2B24R~
//            {                                                    //~2B24R~
//                maxlen=GetSystemMetrics(SM_CXSCREEN);            //~2B24R~
//                maxlen/=Mcellw;                                  //~2B24R~
//                maxlen++;                                        //~2B24R~
//                totline=GetSystemMetrics(SM_CYSCREEN);           //~2B24R~
//                totline/=Mcellh;                                 //~2B24R~
//                totline++;                                       //~2B24R~
//            }                                                    //~2B24R~
//            else                                                 //~2B24R~
//            {                                                    //~2B24R~
                totline=Mscrcmaxrow;                               //~2B10R~
                maxlen=Mscrcmaxcol;                                //~2B10R~
//            }                                                    //~2B24R~
            linenosz=0;                                            //~2B10R~
        }                                                          //~2B10I~
    }                                                              //~2B10I~
    else                                                           //~2B10I~
//  	totline=wxe_prtinit(*Pppfh,&maxlen,&linenosz,&pfhwidth);   //~v627R~
    	totline=wxe_prtinit(*Pppcw,*Pppfh,&maxlen,&linenosz,&pfhwidth);//~v627R~
    *Pptotlineno=totline;                                          //~2B09I~
    *Ppmaxlrecl=maxlen;                                            //~2B09R~
    *Pplinenodigit=linenosz;                                       //~2B09I~
    if (scrtype==PRTTYPE_HEX                                       //~2C01I~
    ||  scrtype==PRTTYPE_VHEXBIN                                   //~v627I~
    ||  scrtype==PRTTYPE_VHEXHHEX                                  //~va49I~
    ||  scrtype==PRTTYPE_BIN)                                      //~2C07R~
        *Ppcmaxlrecl=pfhwidth;                                     //~2C01I~
    else                                                           //~2C01I~
        *Ppcmaxlrecl=maxlen;                                       //~2C01I~
	return scrtype;                                                //~2B07I~
}//xxemain_prtgetscrdata                                           //~vXXER~
//===============================================================================//~2B09I~
//ajust row and col by form size and cellh/cellw for the case maxcol or maxrow is 0//~2B09I~
//===============================================================================//~2B09I~
int  xxemain_prtajustcolrow(int Pscrtype,int Pformw,int Pformh,int Phdrftr,int Pcellw,int Pcellh,//~vXXEI~
							  int Pmaxlrecl,int Ptotlineno,int Plinenofw,int Pcol2p,//~v51hR~
							  int *Ppcmaxcol,int *Ppcmaxrow,int Pchkpfontsz,//~v51hR~
                              int Ppcellszhmax,                    //~v62WI~
							  int *Ppdatamaxcol,int *Ppdatamaxrow) //~v51hI~
{                                                                  //~2B09I~
	int logicalw,cmaxcol,cmaxrow;                                  //~vXXER~
    int datamaxrow,datamaxcol,fontmaxrow=0,fontmaxcol=0;           //~vXXER~
	float fprtcellh,fprtcellw;                                     //~2B17I~
    float wkf;                                                     //~v51hI~
//************************************                             //~2B09I~
    if (Pchkpfontsz>0)  //id of fixed fontsz                       //~v51hR~
    {                                                              //~v51hI~
//        pfontszw=Ppfontsz>>16;                                   //~v51hR~
//        pfontszh=Ppfontsz&0xffff;                                //~v51hR~
//        if (!pfontszw)                                           //~v51hR~
//            pfontszw=pfontszh>>1;                                //~v51hR~
        if (!Pcellw)                                               //~v51hI~
        	Pcellw=Pcellh>>1;                                      //~v51hI~
  		wkf=(float)Pformw;                                         //~v51hM~
//      wkf=MM2POINT(wkf);                                         //~vXXER~
  		fontmaxcol=(int)(wkf/Pcellw);                              //~v51hR~
        fontmaxcol-=Plinenofw;   //text width                      //~v51hI~
        if (Pcol2p) //2p and inter space                           //~v51hM~
            fontmaxcol=(fontmaxcol-Pcol2p)/2;                      //~v51hI~
  		wkf=(float)Pformh;                                         //~v51hM~
//      wkf=MM2POINT(wkf);                                         //~vXXER~
  		fontmaxrow=(int)(wkf/Pcellh);                              //~v51hR~
        fontmaxrow-=Phdrftr+Phdrftr;                               //~v51hI~
    }                                                              //~v51hI~
    if (Pscrtype<0)                                                //~2B10R~
    {                                                              //~2B10M~
    	datamaxcol=                                                //~v51hI~
		cmaxcol=Pmaxlrecl;                                         //~2C01R~
    	datamaxrow=                                                //~v51hI~
		cmaxrow=Ptotlineno;                                        //~2B10I~
    }                                                              //~2B10I~
    else         //file print                                      //~2B10R~
    {                                                              //~2B10I~
		cmaxcol=*Ppcmaxcol;                                        //~2B10R~
		cmaxrow=*Ppcmaxrow;                                        //~2B10R~
        if (Pchkpfontsz)	//font size parm specified             //~v51hR~
        {                                                          //~v51hI~
            if (!cmaxcol && !cmaxrow)//no col/row parm             //~v51hR~
            {                                                      //~v51hI~
            	cmaxcol=fontmaxcol;	//use count by font size       //~v51hI~
            	cmaxrow=fontmaxrow;	//use count by font size       //~v51hI~
            }                                                      //~v51hI~
        }                                                          //~v51hI~
        if (!cmaxcol)                                              //~2B10R~
        {                                                          //~2B10R~
            if (Pmaxlrecl)                                         //~2C01R~
            {                                                      //~va49I~
    			if (Pscrtype==PRTTYPE_HEX)                         //~2C07R~
		            cmaxcol=GET_HEXDISPLAYLINESZ(Pmaxlrecl);       //~2C01R~
                else                                               //~2C01I~
    			if (Pscrtype==PRTTYPE_VHEXHHEX)                    //~va49I~
		            cmaxcol=GET_HEXDISPLAYLINESZ(Pmaxlrecl); //lrecl+margin+hex part len//~va49I~
                else                                               //~va49I~
                	cmaxcol=Pmaxlrecl;                             //~2C01R~
            }                                                      //~va49I~
            else                                                   //~2B10R~
                cmaxcol=DEF_COLFORLRECL0;                          //~2B10R~
        }                                                          //~2B10R~
        if (!cmaxrow)                                              //~2B10R~
        {                                                          //~2B10R~
            logicalw=cmaxcol+Plinenofw;   //text width             //~2B17R~
            if (Pcol2p) //2p and inter space                       //~2B10R~
                logicalw+=logicalw+Pcol2p;                         //~2B17R~
            fprtcellw=(float)Pformw/logicalw;//cell width by mm    //~2B23R~
//          fprtcellh=fprtcellw*Mcellh/Mcellw;              //cell height by mm//~v51hR~
            fprtcellh=fprtcellw*Pcellh/Pcellw;              //cell height by mm//~v51hI~
UTRACEP("adjust fprtcellw=%f=Pformw(%d)/logicalw(%d)\n",fprtcellw,Pformw,logicalw);//~vamdI~
UTRACEP("adjust fprtcellh=%f=fprtcellw(%f)*Pcellh(%d)/Pcellw(%d)\n",fprtcellh,fprtcellw,Pcellh,Pcellw);//~vamdI~
dprintf("adjust fprtcellw=%f=Pformw(%d)/logicalw(%d)\n",fprtcellw,Pformw,logicalw);//~@@@@R~
dprintf("adjust fprtcellh=%f=fprtcellw(%f)*Pcellh(%d)/Pcellw(%d)\n",fprtcellh,fprtcellw,Pcellh,Pcellw);//~@@@@R~
//  		wkf=MM2POINT(fprtcellh);	//cellh by point           //~vXXER~
    		wkf=fprtcellh;	//cellh by point                       //~vXXEI~
	        if (Ppcellszhmax && wkf>Ppcellszhmax) //push under max cell height//~v62WR~
            {                                                      //~v62WI~
    			if (!Pchkpfontsz   //font size parm not specified  //~v62WI~
				&&  *Ppcmaxcol==0)	//col not specified            //~v62WI~
//get col/max by maxfontsz                                         //~v62WI~
//  				return xxemain_prtajustcolrow(Pscrtype,Pformw,Pformh,Phdrftr,Pcellw,Ppcellszhmax,//~vXXER~
    				return xxemain_prtajustcolrow(Pscrtype,Pformw,Pformh,Phdrftr,Ppcellszhmax/2,Ppcellszhmax,//~vXXEI~
							  Pmaxlrecl,Ptotlineno,Plinenofw,Pcol2p,//~v62WI~
							  Ppcmaxcol,Ppcmaxrow,1,	//Pchkfontsz=1//~v62WR~
                              Ppcellszhmax,                        //~v62WI~
							  Ppdatamaxcol,Ppdatamaxrow);          //~v62WI~
            }                                                      //~v62WI~
            cmaxrow=(int)(Pformh/fprtcellh);                       //~2B23R~
            cmaxrow-=Phdrftr+Phdrftr;                              //~2B10R~
UTRACEP("adjust logicalw=%d,cellh=%d,cellw=%d,form=(w=%d,h=%d),cmaxrow=%d\n",//~vamdI~
            logicalw,Pcellh,Pcellw,Pformw,Pformh,cmaxrow);         //~vXXER~
			if (cmaxrow<=0 && *Ppcmaxcol==0)	//calculated fontcellh is too large//~v62MI~
            {                                                      //~v62MI~
            	fprtcellh=(float)Pformh/(Phdrftr+Phdrftr+1);	//minimum 1//~v62WR~
            	fprtcellw=fprtcellh*Pcellw/Pcellh;                 //~v62MI~
            	logicalw=(int)(Pformw/fprtcellw);                  //~v62MR~
            	if (Pcol2p) //2p and inter space                   //~v62MI~
                	logicalw=(logicalw-Pcol2p)/2;                  //~v62MI~
                logicalw=max(Plinenofw+1,logicalw);                //~v62WI~
            	cmaxcol=logicalw-Plinenofw;                        //~v62MI~
            	cmaxrow=1;                                         //~v62WR~
            }                                                      //~v62MI~
        }                                                          //~2B10R~
        datamaxrow=cmaxrow;                                        //~v51hI~
        datamaxcol=cmaxcol;                                        //~v51hI~
UTRACEP("adjust datamaxrow=%d,datamaxcol=%d\n",datamaxrow,datamaxcol);//~vamdI~
    }                                                              //~2B10I~
    if (Pchkpfontsz)   //font size parm specified                  //~v51hR~
    {                                                              //~v51hI~
        if (cmaxcol<=fontmaxcol) //small font                      //~v51hR~
        {                                                          //~v51hI~
            datamaxcol=cmaxcol; //data count                       //~v51hI~
            cmaxcol=fontmaxcol; //page width                       //~v51hI~
        }                                                          //~v51hI~
        else                                                       //~v51hI~
            datamaxcol=cmaxcol=fontmaxcol;	//use by font sz       //~v51hI~
        if (cmaxrow<=fontmaxrow)  //small font                     //~v51hR~
        {                                                          //~v51hI~
            datamaxrow=cmaxrow; //data count                       //~v51hI~
            cmaxrow=fontmaxrow; //page width                       //~v51hI~
        }                                                          //~v51hI~
        else                                                       //~v51hI~
            datamaxrow=cmaxrow=fontmaxrow;	//use by font sz       //~v51hI~
    }                                                              //~v51hI~
UTRACEP("data=(c=%d,r=%d),page=(c=%d,r=%d)\n",datamaxcol,datamaxrow,cmaxcol,cmaxrow);//~vamdR~
    if (cmaxcol<=0||cmaxrow<=0||datamaxcol<=0||datamaxrow<=0)      //~v51hR~
    {                                                              //~v51hM~
    	uerrmsgbox("invalid Col,Row or Fontsz parm",0);            //~v51hR~
        return 4;                                                  //~v51hM~
    }                                                              //~v51hM~
    *Ppcmaxcol=cmaxcol;                                            //~2B09M~
    *Ppcmaxrow=cmaxrow;                                            //~2B09R~
    *Ppdatamaxcol=datamaxcol;                                      //~v51hI~
    if (Pscrtype==PRTTYPE_VHEXTEXT                                 //~v627I~
    ||  Pscrtype==PRTTYPE_VHEXHHEX                                 //~va49I~
    ||  Pscrtype==PRTTYPE_VHEXBIN)                                 //~v627I~
    {                                                              //~v627I~
    	if (datamaxrow>=3)                                         //~v627I~
	        datamaxrow=(datamaxrow/3)*3;	//multiple of 3 line   //~v627I~
    }                                                              //~v627I~
    *Ppdatamaxrow=datamaxrow;                                      //~v51hI~
	return 0;                                                      //~v51hR~
}//prtajustcolrow                                                  //~2B09I~
//===============================================================================//~2B04I~
//called once at last of print after enddoc                        //~2B04I~
//parm:pInfo is 0 when preview call                                //~2B24I~
//===============================================================================//~2B04I~
void xxemain_onendprinting(void)                                   //~vXXER~
{                                                                  //~2B04I~
//  afterprint();                                                  //~v53qI~//~va8aR~
  if (!Mpreviewmode)                                               //~va8aR~
    afterprint(1);     //endprint                                  //~va8aM~
  else                                                             //~va8aI~
    afterprint(0);    //endprint                                   //~va8aI~
}//xxemain_onendprinting                                           //~vXXER~
//===============================================================================//~v53qI~
//free resource after printed                                      //~v53qI~
//opt: 1:endprint,2:cancel print,0:before print                    //~va8aI~
//===============================================================================//~v53qI~
//void afterprint(void)                                              //~vXXEI~//~va8aR~
void afterprint(int Popt)                                          //~va8aI~
{                                                                  //~v53qI~
//************************************                             //~2B04I~
	if (Mprtlinework)                                              //~2B04R~
    {                                                              //~2B04I~
        umemfree(Mprtlinework);                                    //~2B04I~
	    Mprtlinework=0;                                            //~2B04I~
    }                                                              //~2B04I~
	if (Mprtpagework)                                              //~2B17I~
    {                                                              //~2B17I~
        umemfree(Mprtpagework);                                    //~2B17I~
	    Mprtpagework=0;                                            //~2B17I~
    }                                                              //~2B17I~
	if (Mpreviewmode)                                              //~vam5I~
		upreviewresetfontscalePango160(); //csub2                  //~vam5R~
    if (Popt & 0x03)                                               //~va8aI~
    {                                                              //~va8aI~
	    wxe_endprint(0);                                           //~va8aI~
    	xxemain_scrinvalidate(0);                                  //~va8aI~
    }                                                              //~va8aI~
	return;                                                        //~2B04I~
}//afterprint                                                      //~v53qR~
//===============================================================================//~2B02I~
//called first of each page start                                  //~2B02R~
//warning:twice called by the reason odf MFC                       //~2B02I~
//===============================================================================//~2B02I~
void xxemain_prtpreparedc(int Pcurpageno)                          //~vXXEI~
{                                                                  //~2B02I~
//************************************                             //~2B02I~
//	Mprtcurpage=pInfo->m_nCurPage;                                 //~vXXER~
 	Mprtcurpage=Pcurpageno;                                        //~vXXEI~
	return;                                                        //~2B02I~
}//prtpreparedc                                                    //~2B02I~
//===============================================================================//~2A20I~
//print cmd                                                        //~2A20I~
//===============================================================================//~2A20I~
#ifndef NOPRINT                                                    //~vam0I~
int  xxemain_onprint(void)                                         //~vXXEI~
{                                                                  //~2A20I~
//************************************                             //~2A20I~
	if (Mhcopysw)	//printscreen                                  //~2B23R~
//      return prtscr(Pdc,Mpfont,0,0,0,0);                         //~v51hR~
//      return prtscr(Pdc,Mpprtfont,0,0,0,0);                      //~vXXER~
        return prtscr();                                           //~vXXER~
//  return prtfile(Pdc,Mpfont,0,0,0,0);	//0:not preview            //~v51hR~
//  return prtfile(Pdc,Mpprtfont,0,0,0,0);	//0:not preview        //~vXXER~
//#ifdef CCC                                                       //~vamdR~
//    gnome_print_translate(Gpprtctxt,20.0,694.0); //@@@@test      //~vamdR~
//    UTRACEP("xxemain_onprint translate\n");                      //~vamdR~
//#endif                                                           //~vamdR~
//#ifdef CCC                                                       //~vamdR~
//    gnome_print_scale(Gpprtctxt,0.818,0.818); //@@@@test         //~vamdR~
//    UTRACEP("xxemain_onprint scale\n");                          //~vamdR~
//#endif                                                           //~vamdR~
    return prtfile();                                              //~vXXER~
}//onprint                                                         //~2B02R~
#endif //!NOGOMEPRINT                                              //~vam0I~
//===============================================================================//~2B02I~
//screen print                                                     //~2B02R~
//===============================================================================//~2B02I~
#ifndef NOPRINT                                                    //~vam0R~
int  prtscr(void)                                                  //~vXXEI~
{                                                                  //~2B02I~
//  CFont *poldfont;                                               //~vXXER~
//************************************                             //~2B02I~
    Mhcopysw=0;                                                    //~2B23R~
    if (!Mscrcmaxrow || !Mscrcmaxcol)                              //~2B02I~
    	return 4;                                                  //~2B02I~
//  prtviewporthcopy(Pdc,Ppreviewwidth,Ppreviewheight,Pprevieworgx,Pprevieworgy);//~vXXER~
#ifdef GTKPRINT                                                    //~vam0I~
    prtviewporthcopyGtkPrint();                                    //~vam0I~
#else    //!GTKPRINT                                               //~vam0I~
    prtviewporthcopy(Gpprtctxt);                                   //~vXXER~
#endif   //!GTKPRINT                                               //~vam0I~
    Mfulldrawsw=1;                                                 //~2B02I~
//	scrupdate(Pdc,1);                                              //~vXXER~
 	xxemain_scrupdate(Gppixmapprtscr,1);	//1:by print,write to Gppixmapprtscr//~vXXER~
 	prtscrbgrect(); //boudary line draw                            //~vXXEI~
	return 0;                                                      //~2B02I~
}//prtscr                                                          //~2B02I~
#endif //!NOGOMEPRINT                                              //~vam0I~
//===============================================================================//~vXXEI~
//draw background rectangle of prtscr                              //~vXXEI~
//===============================================================================//~vXXEI~
#ifndef NOPRINT                                                    //~vam0I~
void  prtscrbgrect(void)                                           //~vXXER~
{                                                                  //~vXXEI~
    int hh,ww;                                                     //~vXXEI~
//************************************                             //~vXXEI~
    ww=Mscrwidth;                                                  //~vXXEI~
    hh=Mscrheight;                                                 //~vXXEI~
    if (Mimageprtscr)                                              //~vXXEI~
    {                                                              //~vXXEI~
    	gdk_gc_set_foreground(Gpprtgc,&Gprintbg);                  //~vXXER~
    	gdk_draw_rectangle(Gppixmapprtscr,Gpprtgc,TRUE,0,0,ww,hh);//fill;TRUE//~vXXER~
    	gdk_gc_set_foreground(Gpprtgc,&Gprintfg);                  //~vXXER~
    	gdk_draw_rectangle(Gppixmapprtscr,Gpprtgc,FALSE,0,0,ww-1,hh-1);//fill:FALSE//~vXXER~
    }                                                              //~vXXEI~
    else                                                           //~vXXEI~
    {                                                              //~vXXEI~
    	ww=Mscrcmaxcol*Mcellw+1;                                   //~vXXER~
    	hh=Mscrcmaxrow*Mcellh+1;                                   //~vXXER~
    	uprtlineout(-1,  0, ww,  0);                               //~vXXER~
    	uprtlineout(ww, 0,  ww, hh);                               //~vXXEI~
    	uprtlineout(ww, hh, -1,  hh);                              //~vXXER~
    	uprtlineout(-1,  hh,-1,  0);                               //~vXXER~
        UTRACEP("scrbgrect ww=%d,hh=%d\n",ww,hh);                  //~@@@@R~
    }                                                              //~vXXEI~
	return;                                                        //~vXXEI~
}//prtscrbgrect                                                    //~@@@@R~
#endif //!NOGOMEPRINT                                              //~vam0I~
//===============================================================================//~2A27I~
//setup viewport for hcopy                                         //~2B24R~
//===============================================================================//~2A27I~
#ifndef NOPRINT                                                    //~vam0R~
	#ifdef GTKPRINT
void  prtviewporthcopyGtkPrint()               //~vXXER~           //~vam0R~
{                                                                  //~2A27I~
    RECT rect;                                                     //~2B23I~
	int prnh,prnw,scrw,scrh,orgx,orgy;                             //~2B23R~
    gdouble fscalex,fscaley;                                       //~vXXEI~
	float fhbwp,fhbws;                                             //~2B23R~
    cairo_t    *pcairocontext=NULL;                                //~vam0R~
//************************************                             //~2A27M~
    if (Mwwscrprt)          //Wysiwig print                        //~2B24I~
    {                                                              //~2B24I~
        scrh=Mwinexth;  //range of logical axis by max display size//~2B24I~
        scrw=Mwinextw;  //range of logical axis by max display size//~2B24I~
    }                                                              //~2B24I~
    else                                                           //~2B24I~
    {                                                              //~2B24I~
        scrh=Mscrcmaxrow*Mcellh;    //range of logical axis by max display size//~vXXEI~
        scrw=Mscrcmaxcol*Mcellw;    //range of logical axis by max display size//~vXXEI~
		if (Mpreviewmode)                                          //~vXXEI~
        {                                                          //~vXXEI~
	        scrh+=Mcellh;    //for boudary line                    //~vXXEI~
	        scrw+=Mcellw;    //                                    //~vXXEI~
        }                                                          //~vXXEI~
    }                                                              //~2B24I~
UTRACEP("prtviewporthcopyGtkPrint:prtscr Mwwscrprt=%d,scr w=%d,h=%d,maxrow=%d,maxcol=%d\n",Mwwscrprt,scrw,scrh,Mscrcmaxrow,Mscrcmaxcol);         //~v666R~//~vamdR~
        rect.left  =Mmarginl;                                      //~2B24R~
        rect.top   =Mmargint;                                      //~2B24R~
        rect.right =Mmarginr;                                      //~2B24R~
        rect.bottom=Mmarginb;                                      //~2B24R~
//      prtmarginrect(/*Pdc,*/&rect);   //print rect by margin     //~vamkR~
//      prtmarginrect(/*Pdc,*/&rect,NULL);   //print rect by margin//~vamkI~//~vampR~
        prtmarginrect(/*Pdc,*/&rect);   //print rect by margin     //~vampI~
        orgx=rect.left;                                            //~2B24R~
        orgy=rect.top;                                             //~2B24R~
        prnw=rect.right-rect.left;                                 //~2B24R~
        prnh=rect.bottom-rect.top;                                 //~2B24R~
UTRACEP("prtviewporthcopyGtkPrint:ww prt ajust orgx=%d,orgy=%d,w=%d,h=%d\n",orgx,orgy,prnw,prnh);//~vam2I~
    if (Mwwscrprt||!Mfullpage||Mchkpfontsz)          //Wysiwig print//~vX04R~
    {                                                              //~2B30I~
        fhbwp=(float)prnh/prnw;                                    //~2B30I~
        fhbws=(float)scrh/scrw;                                    //~2B30I~
        if (fhbwp<fhbws)      //printer is wider                   //~2B30I~
            prnw=prnh*scrw/scrh;                                   //~2B30I~
        else                    //screen is wider                  //~2B30I~
            prnh=prnw*scrh/scrw;                                   //~2B30I~
    }                                                              //~2B30I~
//      prnh=prnh/Mscrcmaxrow*Mscrcmaxrow;                         //~2B30I~//~vamdR~
//      prnw=prnw/Mscrcmaxcol*Mscrcmaxcol;                         //~2B30I~//~vamdR~
      prnh=prnh/(Mscrcmaxrow+1)*(Mscrcmaxrow+1);                   //~vamdI~
      prnw=prnw/(Mscrcmaxcol+1)*(Mscrcmaxcol+1);                   //~vamdI~
UTRACEP("prtviewporthcopyGtkPrint rounddown:prnw=%d,prnh=%d\n",prnw,prnh);//~v666R~//~vamdR~
	if (Mpreviewmode)                                              //~vXXEI~
    {                                                              //~vXXEI~
	    Mprevieworgx=(gdouble)orgx;                                //~vXXEI~
	    Mprevieworgy=(gdouble)orgy;                                //~vXXEI~
    }                                                              //~vXXEI~
    else                                                           //~vXXEI~
    {                                                              //~vam0I~
//      gnome_print_translate(Ppprtctxt,(gdouble)orgx,Mformszh-(gdouble)orgy);//~vXXER~//~vam0R~
	pcairocontext=gtk_print_context_get_cairo_context(Gpgtkprtctxt);//~vam0M~
        if (Mmarginshift)                                          //~vamtI~
        {                                                          //~vamtI~
            gxepage_papershift(&orgx,&orgy);                       //~vamtI~
        }                                                          //~vamtI~
        cairo_translate(pcairocontext,(gdouble)orgx,(gdouble)orgy);//~vam0R~
    }                                                              //~vam0I~
    fscalex=(gdouble)prnw/scrw;                                    //~vXXEI~
    fscaley=(gdouble)prnh/scrh;                                    //~vXXEI~
//#ifdef AAA                                                       //~@@@@R~
//    if (Mwwscrprt && !Mfullpage)      //relative to display width/height//~@@@@R~
//    {                                                            //~@@@@R~
//        float fh,fw,fwhmin;                                      //~@@@@R~
//        fw=(float)scrw/Mwinextw;                                 //~@@@@R~
//        fh=(float)scrh/Mwinexth;                                 //~@@@@R~
//        if (fw<fh)                                               //~@@@@R~
//            fwhmin=fh;                                           //~@@@@R~
//        else                                                     //~@@@@R~
//            fwhmin=fw;                                           //~@@@@R~
//        UTRACEP("prtviewporthcopyGtkPrint WWscrprt scale old  x=%f,y=%f\n",fscalex,fscaley);//~@@@@R~
//        fscalex*=fwhmin;                                         //~@@@@R~
//        fscaley*=fwhmin;                                         //~@@@@R~
//        UTRACEP("prtviewporthcopyGtkPrint WWscrprt display w=%d,h=%d\n",Mwinextw,Mwinexth);//~@@@@R~
//        UTRACEP("prtviewporthcopyGtkPrint WWscrprt scr     w=%d,h=%d\n",scrw,scrh);//~@@@@R~
//        UTRACEP("prtviewporthcopyGtkPrint WWscrprt rate    w=%f,h=%f,min=%f\n",fw,fh,fwhmin);//~@@@@R~
//        UTRACEP("prtviewporthcopyGtkPrint WWscrprt scale   x=%f,y=%f\n",fscalex,fscaley);//~@@@@R~
//    }                                                            //~@@@@R~
//#endif                                                           //~@@@@R~
    UTRACEP("prtviewporthcopyGtkPrint orgx=%d,orgy=%d,scrw=%d,scrh=%d,prnw=%d,prnh=%d,scalex=%lf,scaley=%lf\n",orgx,orgy,scrw,scrh,prnw,prnh,fscalex,fscaley);//~v666R~//~vam2R~
    UTRACEP("prtviewporthcopyGtkPrint col=%d,row=%d,cellw=%d,cellh=%d\n",Mscrcmaxcol,Mscrcmaxrow,Mcellw,Mcellh);//~v666R~//~vam2R~
	if (Mpreviewmode)                                              //~vXXER~
    {                                                              //~vXXEI~
	    Mpreviewscalex=(gdouble)fscalex;                           //~vXXER~
	    Mpreviewscaley=(gdouble)fscaley;                           //~vXXER~
        upreviewsetfontscale(1,Mcellw,Mcellh,fscalex,fscaley);//1:prtscr,set font scale//~vXXER~
	    UTRACEP("prtviewporthcopyGtkPrint preview scale=(%lf,%lf)\n",fscalex,fscaley);//~vam2I~
    }                                                              //~vXXEI~
    else                                                           //~vXXEI~
    {                                                              //~vamtI~
//      gnome_print_scale(Ppprtctxt,fscalex,fscaley); //requred    //~vXXER~//~vam0R~
        cairo_scale(pcairocontext,fscalex,fscaley); //requred      //~vam0R~
    }                                                              //~vamtI~
    return;                                                        //~2A27I~
}//prtviewporthcopyGtkPrint                                        //~2B24R~//~vam0R~
	#else    //!GTKPRINT
//=========================================================================
void  prtviewporthcopy(GnomePrintContext *Ppprtctxt)               //~vXXER~
{                                                                  //~2A27I~
    RECT rect;                                                     //~2B23I~
	int prnh,prnw,scrw,scrh,orgx,orgy;                             //~2B23R~
    gdouble fscalex,fscaley;                                       //~vXXEI~
	float fhbwp,fhbws;                                             //~2B23R~
//************************************                             //~2A27M~
//  int mapmode=Pdc->GetMapMode();                                 //~2B10R~
//  CPoint cp=Pdc->GetWindowOrg();                                 //~2B10R~
//  CPoint cp2=Pdc->GetViewportOrg();                              //~2B10R~
//  CSize  cs=Pdc->GetWindowExt();                                 //~2B10R~
//  CSize  cs2=Pdc->GetViewportExt();                              //~2B10R~
//  if (Mfullpage)                                                 //~v51hR~
    if (Mwwscrprt)          //Wysiwig print                        //~2B24I~
    {                                                              //~2B24I~
        scrh=Mwinexth;  //range of logical axis by max display size//~2B24I~
        scrw=Mwinextw;  //range of logical axis by max display size//~2B24I~
    }                                                              //~2B24I~
    else                                                           //~2B24I~
    {                                                              //~2B24I~
//      scrh=Mscrcmaxrow*Mcellh;    //range of logical axis by max display size//~v51hR~
//      scrw=Mscrcmaxcol*Mcellw;    //range of logical axis by max display size//~v51hR~
//      scrh=Mscrcmaxrow*Mdrawcellh;    //range of logical axis by max display size//~vXXER~
//      scrw=Mscrcmaxcol*Mdrawcellw;    //range of logical axis by max display size//~vXXER~
        scrh=Mscrcmaxrow*Mcellh;    //range of logical axis by max display size//~vXXEI~
        scrw=Mscrcmaxcol*Mcellw;    //range of logical axis by max display size//~vXXEI~
		if (Mpreviewmode)                                          //~vXXEI~
        {                                                          //~vXXEI~
	        scrh+=Mcellh;    //for boudary line                    //~vXXEI~
	        scrw+=Mcellw;    //                                    //~vXXEI~
        }                                                          //~vXXEI~
    }                                                              //~2B24I~
dprintf("viewporthcopy:prtscr scr w=%d,h=%d\n",scrw,scrh);         //~v666R~
UTRACEP("viewporthcopy:prtscr scr w=%d,h=%d\n",scrw,scrh);         //~@@@@R~
        rect.left  =Mmarginl;                                      //~2B24R~
        rect.top   =Mmargint;                                      //~2B24R~
        rect.right =Mmarginr;                                      //~2B24R~
        rect.bottom=Mmarginb;                                      //~2B24R~
//      prtmarginrect(/*Pdc,*/&rect);   //print rect by margin     //~vamkR~
//      prtmarginrect(/*Pdc,*/&rect,NULL);   //print rect by margin//~vamkI~//~vampR~
        prtmarginrect(/*Pdc,*/&rect);   //print rect by margin     //~vampI~
        orgx=rect.left;                                            //~2B24R~
        orgy=rect.top;                                             //~2B24R~
        prnw=rect.right-rect.left;                                 //~2B24R~
        prnh=rect.bottom-rect.top;                                 //~2B24R~
    if (Mwwscrprt||!Mfullpage||Mchkpfontsz)          //Wysiwig print//~vX04R~
    {                                                              //~2B30I~
        fhbwp=(float)prnh/prnw;                                    //~2B30I~
        fhbws=(float)scrh/scrw;                                    //~2B30I~
        if (fhbwp<fhbws)      //printer is wider                   //~2B30I~
            prnw=prnh*scrw/scrh;                                   //~2B30I~
        else                    //screen is wider                  //~2B30I~
            prnh=prnw*scrh/scrw;                                   //~2B30I~
    }                                                              //~2B30I~
	    prnh=prnh/Mscrcmaxrow*Mscrcmaxrow;                         //~2B30I~
    	prnw=prnw/Mscrcmaxcol*Mscrcmaxcol;                         //~2B30I~
dprintf("viewporthcopy:ww prt ajust orgx=%d,orgy=%d,w=%d,h=%d\n",orgx,orgy,prnw,prnh);//~v666R~
UTRACEP("viewporthcopy:ww prt ajust orgx=%d,orgy=%d,w=%d,h=%d\n",orgx,orgy,prnw,prnh);//~@@@@R~
//  prnw-=PRINT_MARGIN_RIGHT_SAFETY;                               //~2B17R~
	if (Mpreviewmode)                                              //~vXXEI~
    {                                                              //~vXXEI~
	    Mprevieworgx=(gdouble)orgx;                                //~vXXEI~
	    Mprevieworgy=(gdouble)orgy;                                //~vXXEI~
    }                                                              //~vXXEI~
    else                                                           //~vXXEI~
	    gnome_print_translate(Ppprtctxt,(gdouble)orgx,Mformszh-(gdouble)orgy);//~vXXER~
    fscalex=(gdouble)prnw/scrw;                                    //~vXXEI~
    fscaley=(gdouble)prnh/scrh;                                    //~vXXEI~
    dprintf("orgx=%d,orgy=%d,scrw=%d,scrh=%d,prnw=%d,prnh=%d,scalex=%lf,scaley=%lf\n",orgx,orgy,scrh,scrw,prnw,prnh,fscalex,fscaley);//~v666R~
    dprintf("col=%d,row=%d,cellw=%d,cellh=%d\n",Mscrcmaxcol,Mscrcmaxrow,Mcellw,Mcellh);//~v666R~
    UTRACEP("orgx=%d,orgy=%d,scrw=%d,scrh=%d,prnw=%d,prnh=%d,scalex=%lf,scaley=%lf\n",orgx,orgy,scrh,scrw,prnw,prnh,fscalex,fscaley);//~@@@@R~
    UTRACEP("col=%d,row=%d,cellw=%d,cellh=%d\n",Mscrcmaxcol,Mscrcmaxrow,Mcellw,Mcellh);//~@@@@R~
	if (Mpreviewmode)                                              //~vXXER~
    {                                                              //~vXXEI~
	    Mpreviewscalex=(gdouble)fscalex;                           //~vXXER~
	    Mpreviewscaley=(gdouble)fscaley;                           //~vXXER~
        upreviewsetfontscale(1,Mcellw,Mcellh,fscalex,fscaley);//1:prtscr,set font scale//~vXXER~
    }                                                              //~vXXEI~
    else                                                           //~vXXEI~
	    gnome_print_scale(Ppprtctxt,fscalex,fscaley); //requred    //~vXXER~
//  int mapmode3=Pdc->GetMapMode();                                //~2B10R~
//  CPoint cp3=Pdc->GetWindowOrg();                                //~2B10R~
//  CPoint cp32=Pdc->GetViewportOrg();                             //~2B10R~
//  CSize  cs3=Pdc->GetWindowExt();                                //~2B10R~
//  CSize  cs32=Pdc->GetViewportExt();                             //~2B10R~
    return;                                                        //~2A27I~
}//prtviewporthcopy                                                //~2B24R~
	#endif   //!GTKPRINT
#endif //!NOGOMEPRINT                                              //~vam0I~
//===============================================================================//~2B02I~
//file print                                                       //~2B02I~
//===============================================================================//~2B02I~
#ifndef NOPRINT                                                    //~vam0R~
int  prtfile(void)                                                 //~vXXER~
{                                                                  //~2B02I~
	char *pdata,*pagewk,*pagewk2,*linewk;                          //~2B24R~
	int  svch,len,ii,jj,yy,yy0,pos,pos2,rc=0,logicalw,logicalh,lrecl;//~vXXER~
    int  kk;                                                       //~v627I~
	int  pos2px,pos2px0=0,curpage,skiplineno,posyfooter,previewsw; //~vXXER~
	int  swhexlineno=0;                                            //~2C07R~
    int  datalen;                                                  //~v627I~
    char footer[16];                                               //~2B02I~
    char footerp[16];                                              //~2B02I~
//  CFont *poldfont;                                               //~vXXER~
//	TEXTMETRIC  metric;int rc2;                                    //~2C07R~
#ifdef UTF8UCS2                                                    //~va20I~
//  int swutf8file,linenofldsz,dbcsoffspgwk,dbcsoffslinewk=0,logicalwu8,vhexlen,pos2px0u8;//~va20I~//~vaffR~
    int swutf8file,linenofldsz=0,dbcsoffspgwk=0,dbcsoffslinewk=0,logicalwu8=0,vhexlen,pos2px0u8=0;//~vaffI~
    char *pc,*pdbcs;                                               //~va20I~
    int rowlen[PRINTROW_MAX][2];                                   //~va20I~
    int rowlenhhexlrecl[PRINTROW_MAX][2]; //m2p lrecl of hhex mode for ebcdic file dd fmt//~va80I~
#endif                                                             //~va20I~
    int swebcbyucs,swucsprint,opttow,hhexlrecl;                    //~va80I~
    int opt2p[PRINTROW_MAX];                                       //~vamsI~
//************************************                             //~2B02I~
    if (Mprtlnotype==PRTLNOTYPE_HEX                                //~2C07I~
    ||  Mprtlnotype==PRTLNOTYPE_hex)                               //~2C07I~
        swhexlineno=1;                                             //~2C07M~
//        Pdc->GetTextMetrics(&metric);                            //~2B30R~
//UTRACEP("textmetric h=%d,avw=%d,maxw=%d\n",                      //~2B30R~
//                metric.tmHeight,metric.tmAveCharWidth,metric.tmMaxCharWidth);//~2B30R~
//      Pdc->GetOutputTextMetrics(&metric);                        //~2C07R~
//UTRACEP("outtextmetric h=%d,avw=%d,maxw=%d,charset=%x,pich=%2x\n",//~2C07R~
//                metric.tmHeight,metric.tmAveCharWidth,metric.tmMaxCharWidth,metric.tmCharSet,metric.tmPitchAndFamily);//~2C07R~
//        rc2=Pdc->GetTextCharacterExtra();                        //~2C03R~
	previewsw=Mpreviewmode;//(Ppreviewheight!=0);                  //~vXXER~
#ifdef GTKPRINT                                                    //~vam0I~
    prtviewportfileGtkPrint();                                     //~vam0I~
#else    //!GTKPRINT                                               //~vam0I~
    prtviewportfile(Gpprtctxt);	//scale/tarslate set requred for each page//~vXXER~
#endif   //!GTKPRINT                                               //~vam0I~
	logicalw=Mprtcmaxcol+Mprtlinenosz*(Mlinenumber==TRUE);//line width//~2B17I~
    if (M2p)                                                       //~2B17I~
    {                                                              //~2B17I~
	    pos2px0=logicalw+Mprt2pcol;                                //~2B17R~
        logicalw=pos2px0+logicalw;	//line width                   //~2B17R~
    }                                                              //~2B17I~
#ifdef UTF8UCS2                                                    //~va20I~
	swutf8file=WXEPRINT_UTF8MODE();                                //~va20I~
	swebcbyucs=WXEPRINT_EBCBYUCS();                                //~va80I~
    swucsprint=swutf8file || swebcbyucs;	//ucs print(TextoutW)  //~va80I~
//  if (swutf8file)                                                //~va20I~//~va80R~
    if (swucsprint)                                                //~va80I~
    {                                                              //~va20I~
    	linenofldsz=Mprtlinenosz*(Mlinenumber==TRUE);              //~va20I~
		logicalwu8=Mprtcmaxcol+linenofldsz;                        //~va20I~
        dbcsoffspgwk=dbcsoffslinewk=logicalwu8;//line width        //~va20I~
        if (Mprttype==PRTTYPE_VHEXTEXT                             //~va20I~
        ||  Mprttype==PRTTYPE_VHEXBIN)                             //~va20I~
        	dbcsoffslinewk+=Mprtcmaxcol*2;                         //~va20I~
        else                                                       //~va80I~
		if (swebcbyucs && Mprttype==PRTTYPE_VHEXHHEX)  //hhex+vhex for EBC file//~va80I~
        	dbcsoffslinewk+=Mprtcmaxcol*2;                         //~va80I~
        if (M2p)                                                   //~va20I~
        {                                                          //~va20I~
        	logicalwu8=dbcsoffspgwk+Mprtcmaxcol;	//half         //~va20I~
		    pos2px0u8=logicalwu8+Mprt2pcol;                        //~va20I~
        	logicalwu8+=pos2px0u8;                                 //~va20I~
        }                                                          //~va20I~
    }                                                              //~va20I~
    else                                                           //~vamsI~
    	linenofldsz=Mprtlinenosz*(Mlinenumber==TRUE);              //~vamsI~
#endif                                                             //~va20I~
    yy=0;                                                          //~2B03I~
    logicalh=0;                                                    //~2B17I~
    pagewk=Mprtpagework;                                           //~2B17I~
    if (Mheader)                                                   //~2B03I~
    {                                                              //~2B03I~
		len=strlen(Mprtfnm);                                       //~2B03R~
        len=min(len,logicalw);                                     //~2B17R~
        if (M2p)                                                   //~2B17I~
        	linewk=pagewk;                                         //~2B24I~
        else                                                       //~2B24I~
        	linewk=Mprtlinework;                                   //~2B24I~
        memset(linewk,' ',logicalw);                               //~2B24R~
        memcpy(linewk,Mprtfnm,len);                                //~2B24R~
        if (Mfiletime)                                             //~2B03I~
        {                                                          //~2B04I~
            pos=(len+4);                                           //~2B04I~
            len=strlen(Mprtftime);                                 //~2B04I~
            len=min(len,logicalw-pos);                             //~2B17R~
            if (len>0)                                             //~2B04I~
        		memcpy(linewk+pos,Mprtftime,len);                  //~2B24R~
        }                                                          //~2B04I~
        if (!M2p)                                                  //~2B24I~
        {                                                          //~vXXEI~
			prttextout(/*Pdc,*/yy,linewk,logicalw);                //~vXXER~
    		prtlineout(yy+Mdrawcellh+Mdrawcellh/2,logicalw);//center line//~vXXER~
        }                                                          //~vXXEI~
//      yy+=Mcellh+Mcellh;                                         //~v51hR~
        yy+=Mdrawcellh+Mdrawcellh;                                 //~v51hR~
        logicalh=2;                                                //~2B04I~
        if (M2p)                                                   //~2B17I~
        {                                                          //~2B17I~
        	pagewk+=logicalw;                                      //~2B17R~
        	memset(pagewk,' ',logicalw);                           //~2B17R~
        	pagewk+=logicalw;                                      //~2B17R~
        }                                                          //~2B17I~
    }                                                              //~2B03I~
    yy0=yy;                                                        //~2B04I~
    pagewk2=pagewk;		//after header                             //~2B17I~
    pos2px=0;                                                      //~2B17R~
//  posyfooter=logicalh+Mprtcmaxrow+1;                             //~v51hR~
    posyfooter=logicalh+Mprtdatamaxrow+1;                          //~v51hI~
    for (jj=0;jj<2;jj++)	//for 2p                               //~2B04I~
    {                                                              //~2B04I~
//      for (ii=0,yy=yy0;ii<Mprtcmaxrow;ii++,yy+=Mcellh)           //~v51hR~
//      for (ii=0,yy=yy0;ii<Mprtdatamaxrow;ii++,yy+=Mcellh)        //~v51hR~
        for (ii=0,yy=yy0;ii<Mprtdatamaxrow;ii++,yy+=Mdrawcellh)    //~v51hR~
        {                                                          //~2B04R~
            if (M2p)                                               //~2B04I~
            	curpage=Mprtcurpage+Mprtcurpage+jj-1;              //~2B16R~
            else                                                   //~2B04I~
	        	curpage=Mprtcurpage;                               //~2B04I~
#ifdef UTF8UCS2                                                    //~va20I~
		  if (dbcsoffslinewk)                                      //~va80I~
            pdbcs=Mprtlinework+dbcsoffslinewk;    //addr to set dir data//~va20I~
          else                                                     //~va80I~
            pdbcs=0;                                               //~va80I~
#endif                                                             //~va20I~
            if (Mlinenumber)                                       //~2C07R~
                pdata=Mprtlinework+Mprtlinenosz;    //addr to set dir data//~2C07R~
            else                                                   //~2C07R~
                pdata=Mprtlinework; //addr to set dir data         //~2C07R~
//          if ((rc=wxe_prtgetline(curpage,Mprtcmaxlrecl,Mprtcmaxrow,pdata,&lrecl,&skiplineno,&len))<0)//eof//~v51hR~
#ifdef UTF8UCS2                                                    //~va20I~
            if ((rc=wxe_prtgetline(curpage,Mprtcmaxlrecl,Mprtdatamaxrow,pdata,pdbcs,&vhexlen,&lrecl,&skiplineno,&len))<0)//eof//~va20I~
#else                                                              //~va20I~
            if ((rc=wxe_prtgetline(curpage,Mprtcmaxlrecl,Mprtdatamaxrow,pdata,&lrecl,&skiplineno,&len))<0)//eof//~v51hI~
#endif                                                             //~va20I~
                break;                                             //~2B23R~
            UTRACEP("prtfile getline jj=%d,ii=%d,rc=%d,lrecl=%d,skiplineo=%d,logicalh=%d\n",jj,ii,rc,lrecl,skiplineno,logicalh);//~vamsR~
            datalen=len;                                           //~v627I~
            if (Mlinenumber)                                       //~2B04R~
            {                                                      //~2B04R~
                Mprtclineno+=skiplineno;                           //~2B04M~
                if (rc) //cont line                                //~2B04R~
                {                                                  //~2B04R~
                    memset(Mprtlinework,' ',Mprtlinenosz);         //~2B04R~
                    *(Mprtlinework+Mprtlinenosz-2)='-'; //cont id  //~2B04R~
                }                                                  //~2B04R~
                else                                               //~2B04R~
                {                                                  //~2B04R~
                	if (!swhexlineno)                              //~2B30I~
                    	Mprtclineno++;                             //~2B30R~
					svch=*(Mprtlinework+Mprtlinenosz);	//for sprinf last null//~2B06I~
                    sprintf(Mprtlinework,Mprtlinenoedit,Mprtclineno);//~2B04R~
					*(Mprtlinework+Mprtlinenosz)=svch;             //~2B06I~
                }                                                  //~2B04R~
                if (swhexlineno)                                   //~2B30I~
                    Mprtclineno+=lrecl;   //offset in the file     //~2C01R~
                pdata=Mprtlinework;                                //~2B16R~
				len+=Mprtlinenosz;                                 //~2B06I~
            }                                                      //~2B04R~
        	if (M2p)                                               //~2B17R~
            {                                                      //~2B17I~
            	if (!jj)	//	left half                          //~2C01R~
                {                                                  //~2B17I~
                	logicalh++;     //count line in page           //~2C01R~
#ifdef UTF8UCS2                                                    //~va20I~
//            	  if (swutf8file)                                  //~va20I~//~va80R~
              	  if (swucsprint)                                  //~va80I~
                  {                                                //~va80I~
              	  	rowlen[ii][1]=0;	//clear right half len     //~va20I~
              	  	rowlenhhexlrecl[ii][1]=0;	//clear right half len//~va80I~
                  }                                                //~va80I~
                  else                                             //~va20I~
#endif                                                             //~va20I~
                  {                                                //~vamsI~
                	memset(pagewk,' ',logicalw);                   //~2B17M~
                    opt2p[ii]=0;                                   //~vamsR~
              	  	rowlenhhexlrecl[ii][1]=0;	//clear right half len//~vamsI~
                  }                                                //~vamsI~
                }                                                  //~2B17I~
                memcpy(pagewk+pos2px,pdata,(UINT)len);             //~2B24R~
#ifdef UTF8UCS2                                                    //~va20I~
//            if (swutf8file)                                      //~va20I~//~va80R~
              if (swucsprint)                                      //~va80I~
              {                                                    //~va20I~
              	rowlen[ii][jj]=len;                                //~va20I~
              	rowlenhhexlrecl[ii][jj]=lrecl;                     //~va80I~
//              memcpy(pagewk+pos2px+dbcsoffspgwk,pdbcs,(UINT)len);//~va20I~//~va88R~
                memcpy(pagewk+pos2px+dbcsoffspgwk,pdbcs,(UINT)lrecl);//~va88I~
                pagewk+=logicalwu8;                                //~va20I~
              }                                                    //~va20I~
              else                                                 //~va20I~
#endif                                                             //~va20I~
              {                                                    //~vamsI~
              	rowlenhhexlrecl[ii][jj]=lrecl;                     //~vamsI~
                pagewk+=logicalw;                                  //~2B17I~
              }                                                    //~vamsI~
            }                                                      //~2B17I~
            else                                                   //~2B17I~
            {                                                      //~va20I~
#ifdef UTF8UCS2                                                    //~va20I~
//            if (swutf8file)                                      //~va20I~//~va80R~
              if (swucsprint)                                      //~va80I~
              {                                                    //~va80I~
        		opttow=previewsw;                                  //~va80I~
    			if (Mprttype==PRTTYPE_HEX                          //~va80I~
    			||  Mprttype==PRTTYPE_VHEXHHEX  //hhex+vhex        //~va80I~
    			)                                                  //~va80I~
                {                                                  //~va80I~
        			opttow|=PRTTOWO_HHEX|((lrecl<<PRTTOWO_LRECLMASKSHIFT) & PRTTOWO_LRECLMASK);//~va80I~
                }                                                  //~va80I~
//  			prttextoutw(0,yy,0/*xx*/,pdata,pdbcs,len,linenofldsz);//~va20R~//~va80R~
    			prttextoutw(opttow,yy,0/*xx*/,pdata,pdbcs,len,linenofldsz);//~va80R~
              }                                                    //~va80I~
              else                                                 //~va20I~
#endif                                                             //~va20I~
                                                                   //~vampI~
              if (Mprttype==PRTTYPE_HEX         //hhex             //~vampR~
              ||  Mprttype==PRTTYPE_VHEXHHEX     //h+v             //~vampR~
              ||  Mprttype==PRTTYPE_BIN         //bin              //~vampI~
              ||  Mprttype==PRTTYPE_VHEXBIN)	//bin vhex-dataline//~vampI~
				prttextout_NoLigature(yy,pdata,len);               //~vampI~
              else                                                 //~vampI~
				prttextout(/*Pdc,*/yy,pdata,len);                  //~vXXER~
            }                                                      //~va20I~
            if (Mprttype==PRTTYPE_VHEXTEXT                         //~v627I~
            ||  Mprttype==PRTTYPE_VHEXHHEX  //hhex+vhex            //~va49I~
            ||  Mprttype==PRTTYPE_VHEXBIN)                         //~v627I~
            {                                                      //~v627I~
                pdata=Mprtlinework; 	//top                      //~v627I~
                for (kk=0;kk<2;kk++)                               //~v627R~
                {                                                  //~v627I~
#ifdef UTF8UCS2                                                    //~va20I~
//  		      if (swutf8file)                                  //~va20I~//~va80R~
    		      if (swucsprint)                                  //~va80I~
                  {                                                //~va20I~
                  	if (!kk)                                       //~va20I~
                		pdata+=datalen;                            //~va20I~
                    else                                           //~va20I~
                		pdata+=vhexlen;                            //~va20I~
                    len=vhexlen;                                   //~va20I~
                  }                                                //~va20I~
                  else                                             //~va20I~
#endif                                                             //~va20I~
            	  if (Mprttype==PRTTYPE_VHEXHHEX)                  //~va49I~
                  {                                                //~va49I~
                  	if (!kk)                                       //~va49I~
                		pdata+=datalen; //hhex line data length    //~va49I~
                    else                                           //~va49I~
                		pdata+=vhexlen;                            //~va49I~
                    len=vhexlen;                                   //~va49I~
                  }                                                //~va49I~
                  else                                             //~va49I~
                  {                                                //~va20I~
	                len=datalen;                                   //~v627I~
                	pdata+=len;                                    //~v627I~
                  }                                                //~va20I~
					yy+=Mdrawcellh;                                //~v627I~
					ii++;                                          //~v627I~
                    if (Mlinenumber)                               //~v627I~
                    {                                              //~v627I~
                        memset(pdata,' ',Mprtlinenosz);            //~v627I~
                        *(pdata+Mprtlinenosz-2)='.'; //hex line id //~v627I~
                        len+=Mprtlinenosz;                         //~v627I~
                    }                                              //~v627I~
                    if (M2p)                                       //~v627I~
                    {                                              //~v627I~
                        if (!jj)    //  left half                  //~v627I~
                        {                                          //~v627I~
                            logicalh++;     //count line in page   //~v627I~
#ifdef UTF8UCS2                                                    //~va20I~
//  					  if (swutf8file)                          //~va20I~//~va80R~
    					  if (swucsprint)                          //~va80I~
                          {                                        //~va80I~
              	  		  	rowlen[ii][1]=0;	//clear right half len//~va20I~
              	  		  	rowlenhhexlrecl[ii][1]=0;	//clear right half len//~va80I~
                          }                                        //~va80I~
                          else                                     //~va20I~
#endif                                                             //~va20I~
                          {                                        //~vamsI~
                            memset(pagewk,' ',logicalw);           //~v627I~
              	  		  	rowlenhhexlrecl[ii][1]=0;	//clear right half len//~vamsI~
                          }                                        //~vamsI~
                        }                                          //~v627I~
                        memcpy(pagewk+pos2px,pdata,(UINT)len);     //~v627I~
#ifdef UTF8UCS2                                                    //~va20I~
//                    if(swutf8file)                               //~va20I~//~va80R~
                      if(swucsprint)                               //~va80I~
                      {                                            //~va20I~
		              	rowlen[ii][jj]=len;                        //~va20I~
		              	rowlenhhexlrecl[ii][jj]=-1; //vhexlineid   //~va80I~
                        *(pagewk+pos2px+dbcsoffspgwk)=VHEXLINEID;	//vhexlineid//~va20I~
                        pagewk+=logicalwu8;                        //~va20I~
                      }                                            //~va20I~
                      else                                         //~va20I~
#endif                                                             //~va20I~
                      {                                            //~vamsI~
                      	opt2p[ii]|=jj==0?PRTTO2PO_VHEXLINE_L:PRTTO2PO_VHEXLINE_R;//~vamsR~
		              	rowlenhhexlrecl[ii][jj]=-1; //vhexlineid   //~vamsI~
                        pagewk+=logicalw;                          //~v627I~
                      }                                            //~vamsI~
                    }                                              //~v627I~
                    else                                           //~v627I~
//                      prttextout(/*Pdc,*/yy,pdata,len);          //~vXXER~//~vampR~
                        prttextout_NoLigature(/*Pdc,*/yy,pdata,len);//~vampI~
        	    }//for kk                                          //~v627R~
            }//vhex                                                //~v627I~
        }                                                          //~2B04R~
        if (!M2p)                                                  //~2B04R~
        	break;                                                 //~2B04I~
        if (rc<0)                                                  //~2B04I~
        	break;                                                 //~2B04I~
	    pagewk=pagewk2;		//after header                         //~2B17I~
#ifdef UTF8UCS2                                                    //~va20I~
//    if (swutf8file)                                              //~va20I~//~va80R~
      if (swucsprint)                                              //~va80I~
    	pos2px=pos2px0u8;                                          //~va20I~
      else                                                         //~va20I~
#endif                                                             //~va20I~
    	pos2px=pos2px0;                                            //~2B17I~
    }//2p                                                          //~2B04I~
    if (M2p)                                                       //~2B17M~
    {                                                              //~va20I~
#ifdef UTF8UCS2                                                    //~va20I~
//    if (swutf8file)                                              //~va20I~//~va80R~
      if (swucsprint)                                              //~va80I~
      {                                                            //~va20I~
	    pagewk=Mprtpagework;                                       //~va20I~
        yy=0;                                                      //~va20I~
        jj=logicalh;                                               //~va20I~
    	if (Mheader)                                               //~va20I~
        {                                                          //~va20I~
			prttextout(0/*yy*/,pagewk,logicalw);                   //~va20R~
            pagewk+=logicalw;                                      //~va20I~
//  		prttextout(Mdrawcellh/*yy*/,pagewk,logicalw);          //~va20R~
            yy=Mdrawcellh;                                         //~va20I~
    		prtlineout(yy+Mdrawcellh/2,logicalw);//center line     //~va20I~
            pagewk+=logicalw;                                      //~va20I~
            yy=2*Mdrawcellh;                                       //~va20I~
            jj-=2;                                                 //~va20I~
        }                                                          //~va20I~
	    for (ii=0;                                                 //~va20I~
				ii<jj;                                             //~va20I~
					ii++,pagewk+=logicalwu8,yy+=Mdrawcellh)        //~va20I~
        {                                                          //~va20I~
        	len=rowlen[ii][0];                                     //~va20I~
            if (len)                                               //~va20I~
            {                                                      //~va80I~
//  			prttextoutw(0,yy,0/*xx*/,pagewk,pagewk+dbcsoffspgwk,len,linenofldsz);//~va20R~//~va80R~
                opttow=previewsw;                                  //~va80I~
                hhexlrecl=rowlenhhexlrecl[ii][0];                  //~va80I~
                if (hhexlrecl<0)    //vhexline                     //~va80I~
                    opttow|=PRTTOWO_VHEXLINE;                      //~va80I~
    			if (Mprttype==PRTTYPE_HEX                          //~va80I~
    			||  Mprttype==PRTTYPE_VHEXHHEX  //hhex+vhex        //~va80I~
    			)                                                  //~va80I~
                {                                                  //~va80I~
                    if (hhexlrecl>0)    //not vhexline             //~va80I~
        				opttow|=PRTTOWO_HHEX|((hhexlrecl<<PRTTOWO_LRECLMASKSHIFT) & PRTTOWO_LRECLMASK);//~va80I~
                }                                                  //~va80I~
    			prttextoutw(opttow,yy,0/*xx*/,pagewk,pagewk+dbcsoffspgwk,len,linenofldsz);//~va80R~
            }                                                      //~va80I~
	        pc=pagewk+pos2px0u8;                                   //~va20I~
        	len=rowlen[ii][1];                                     //~va20I~
        	hhexlrecl=rowlenhhexlrecl[ii][1];                      //~va80I~
            if (len)                                               //~va20I~
            {                                                      //~va80I~
//  			prttextoutw(0,yy,pos2px0,pc,pc+dbcsoffspgwk,len,linenofldsz);//~va20R~//~va80R~
                opttow=previewsw;                                  //~va80I~
                hhexlrecl=rowlenhhexlrecl[ii][1];                  //~va80I~
                if (hhexlrecl<0)    //vhexline                     //~va80I~
                    opttow|=PRTTOWO_VHEXLINE;                      //~va80I~
    			if (Mprttype==PRTTYPE_HEX       //no hhex case for utf8 file//~va80I~
    			||  Mprttype==PRTTYPE_VHEXHHEX  //hhex+vhex        //~va80I~
    			)                                                  //~va80I~
                {                                                  //~va80I~
                    if (hhexlrecl>0)    //not vhexline             //~va80I~
        				opttow|=PRTTOWO_HHEX|((hhexlrecl<<PRTTOWO_LRECLMASKSHIFT) & PRTTOWO_LRECLMASK);//~va80I~
                                                                   //~va80I~
                }                                                  //~va80I~
    			prttextoutw(opttow,yy,pos2px0,pc,pc+dbcsoffspgwk,len,linenofldsz);//~va80R~
            }                                                      //~va80I~
        }                                                          //~va20I~
      }                                                            //~va20I~
      else                                                         //~va20I~
#endif                                                             //~va20I~
      {//lc                                                        //~vamsI~
        kk=0;  //opt2p/rowlenhexlrecl index                        //~vamsI~
	    for (yy=0,pagewk=Mprtpagework,ii=logicalh;                 //~2B17I~
				ii>0;                                              //~2B17M~
//  				ii--,pagewk+=logicalw,yy+=Mcellh)              //~v51hR~
					ii--,pagewk+=logicalw,yy+=Mdrawcellh)          //~v51hR~
        {                                                          //~vXXEM~
        	UTRACEP("prtfile lc ii=%d\n",logicalh-ii);             //~vamsI~
    	  if ((ii==logicalh-1) && Mheader)                         //~vXXER~
    		prtlineout(yy+Mdrawcellh/2,logicalw);//center line     //~vXXER~
          else                                                     //~vXXEI~
          {                                                        //~vamsI~
           if (ii==logicalh && Mheader)	//dsname line              //~vamsI~
    		prttextout_NoLigature(yy,pagewk,logicalw);             //~vamsR~
           else                                                    //~vamsI~
           {                                                       //~vamsI~
			prttextout2p(opt2p[kk],yy,pagewk,logicalw,linenofldsz,pos2px0,rowlenhhexlrecl[kk][0],rowlenhhexlrecl[kk][1]);//~vamsR~
            kk++;                                                  //~vamsI~
           }                                                       //~vamsI~
          }                                                        //~vamsI~
        }                                                          //~vXXEI~
      }//lc                                                        //~vamsI~
    }//M2p                                                         //~va20I~
//footer                                                           //~2B17I~
    if (Mfooter)                                                   //~2B03I~
    {                                                              //~2B03I~
    	len=sprintf(footer,"%d",Mprtmaxpage);                      //~2B17M~
    	sprintf(footerp,"%% %dd / %%d",len);                       //~2B17M~
    	len=sprintf(footer,footerp,Mprtcurpage,Mprtmaxpage);       //~2B17M~
        pos=(logicalw-len)/2;                                      //~2B17I~
//      yy=posyfooter*Mcellh; //1 space line                       //~v51hR~
        yy=posyfooter*Mdrawcellh; //1 space line                   //~v51hR~
        if (M2p)                                                   //~2B24I~
        	linewk=pagewk;                                         //~2B24I~
        else                                                       //~2B24I~
	        linewk=Mprtlinework;                                   //~2B24R~
        memset(linewk,' ',logicalw);                               //~v62WI~
//      if (pos>0)                                                 //~v62WR~
        if (pos>=0)                                                //~v62WI~
        {                                                          //~2B24R~
//          memset(linewk,' ',logicalw);                           //~v62WR~
            memcpy(linewk+pos,footer,len);                         //~2B24I~
            pos2=pos+len;                                          //~2C07I~
            if (Msystime)                                          //~2C07R~
            {                                                      //~2C07R~
                len=strlen(Mprtsystime);                           //~2C07R~
                pos=logicalw-len;                                  //~2C07R~
                if (pos>pos2)                                      //~2C07R~
                    memcpy(linewk+pos,Mprtsystime,len);            //~2C07R~
            }                                                      //~2C07R~
        }                                                          //~2C07M~
UTRACEP("footer line y=%d,txt=%d\n",yy-Mdrawcellh/2,yy);           //~vamdR~
    	prtlineout(yy-Mdrawcellh/2,logicalw);	//center line      //~vXXER~
		prttextout(/*Pdc,*/yy,linewk,logicalw);                    //~vXXER~
    }                                                              //~2B03I~
	return 0;                                                      //~2B02I~
}//prtfile                                                         //~2B02R~
#endif //!NOGOMEPRINT                                              //~vam0I~
//===============================================================================//~2B24I~
//file preview text line print                                     //~2B24I~
//===============================================================================//~2B24I~
#ifndef NOPRINT                                                    //~vam0I~
int  prttextout(int Pyy,char *Pdata,int Plen)                      //~vXXER~
{                                                                  //~2B24I~
//  int ii,xx;                                                     //~vXXER~
//  char *pc;                                                      //~vXXER~
//  CSize sz,sz2;                                                  //~vXXER~
//************************************                             //~2B24I~
	if (!Plen)                                                     //~2B24R~
    	return 0;                                                  //~2B24I~
//  	Pdc->TextOut(0,Pyy,Pdata,Plen);                            //~vXXER~
UTRACEP("prttextout yy=%d,len=%d\n",Pyy,Plen);                        //~va20I~//~vampR~
UTRACED("prttextout",Pdata,Plen);                                     //~va20I~//~vampR~
        uprttextout(0,Pyy,Pdata,Plen);                             //~vXXEI~
    return 0;                                                      //~2B24I~
}//prttextout                                                      //~2B24I~
int  prttextout_NoLigature(int Pyy,char *Pdata,int Plen)           //~vampI~
{                                                                  //~vampI~
//************************************                             //~vampI~
	if (!Plen)                                                     //~vampI~
    	return 0;                                                  //~vampI~
UTRACEP("prttextout_NoLigature yy=%d,len=%d\n",Pyy,Plen);          //~vampI~
UTRACED("prttextout_NoLigature",Pdata,Plen);                       //~vampI~
        uprttextout_NoLigature(0,Pyy,Pdata,Plen);                  //~vampI~
    return 0;                                                      //~vampI~
}//prttextout                                                      //~vampI~
#endif //!NOGOMEPRINT                                              //~vam0I~
//===============================================================================//~vamsI~
//2p lc file                                                       //~vamsI~
//===============================================================================//~vamsI~
#ifndef NOPRINT                                                    //~vamsI~
void  prttextout2p(int Popt,int Pyy,char *Pdata,int Plen,int Plinenofldlen,int Pposr,int PlreclL,int PlreclR)//~vamsR~
{                                                                  //~vamsI~
    char *pc;                                                      //~vamsR~
    int xx,swnoligature,len;                                       //~vamsR~
//************************************                             //~vamsI~
UTRACEP("prttextout2p yy=%d,len=%d,linenosz=%d,posr=%d,;reclL=%d,lreclR=%d\n",Pyy,Plen,Plinenofldlen,Pposr,PlreclL,PlreclR);//~vamsR~
	if (!Plen)                                                     //~vamsI~
    	return;                                                    //~vamsR~
UTRACED("prttextout2p data",Pdata,Plen);                           //~vamsI~
    swnoligature=Mprttype==PRTTYPE_HEX         //hhex              //~vamsI~
    		   ||Mprttype==PRTTYPE_VHEXHHEX     //h+v              //~vamsI~
               ||Mprttype==PRTTYPE_BIN         //bin               //~vamsI~
               ||Mprttype==PRTTYPE_VHEXBIN;	//bin vhex-dataline    //~vamsI~
    xx=0;                                                          //~vamsI~
    pc=Pdata;                                                      //~vamsI~
    if (Plinenofldlen)                                             //~vamsI~
    {                                                              //~vamsI~
		uprttextout_NoLigature(xx,Pyy,pc,Plinenofldlen);           //~vamsI~
        xx+=Plinenofldlen*Mdrawcellw;                              //~vamsI~
        pc+=Plinenofldlen;                                         //~vamsI~
    }                                                              //~vamsI~
    if (PlreclL>0) //-1 for vhex line                              //~vamsR~
    {                                                              //~vamsI~
    	len=PlreclL+umemspnc(pc+PlreclL,' ',Pposr-Plinenofldlen-PlreclL);//~vamsR~
        UTRACEP("prttextout2P umemspncL pos=%p,chklen=%d,len=%d\n",pc+PlreclL,Pposr-Plinenofldlen-PlreclL,len);//~vamsI~
    }                                                              //~vamsI~
    else                                                           //~vamsI~
	    len=Pposr-Plinenofldlen;                                   //~vamsR~
    if (Popt & PRTTO2PO_VHEXLINE_L || swnoligature)   //left is vhexline//~vamsI~
    	uprttextout_NoLigature(xx,Pyy,pc,len);                     //~vamsI~
    else                                                           //~vamsI~
    	uprttextout(xx,Pyy,pc,len);                                //~vamsI~
    xx+=len*Mdrawcellw;                                            //~vamsI~
	pc+=len;                                                       //~vamsI~
    if (PlreclL>0)                                                 //~vamsR~
    {                                                              //~vamsI~
        len=Pposr-Plinenofldlen-len;                               //~vamsI~
    	uprttextout_NoLigature(xx,Pyy,pc,len);                     //~vamsI~
	    xx+=len*Mdrawcellw;                                        //~vamsI~
		pc+=len;                                                   //~vamsI~
    }                                                              //~vamsI~
//right                                                            //~vamsI~
    if (Plinenofldlen)                                             //~vamsI~
    {                                                              //~vamsI~
		uprttextout_NoLigature(xx,Pyy,pc,Plinenofldlen);           //~vamsI~
        xx+=Plinenofldlen*Mdrawcellw;                              //~vamsI~
        pc+=Plinenofldlen;                                         //~vamsI~
    }                                                              //~vamsI~
    if (PlreclR>0)                                                 //~vamsR~
    {                                                              //~vamsI~
    	len=PlreclR+umemspnc(pc+PlreclR,' ',Plen-Pposr-Plinenofldlen-PlreclR);//~vamsR~
        UTRACEP("prttextout2P umemspncR pos=%p,chklen=%d,len=%d\n",pc+PlreclR,Plen-Pposr-Plinenofldlen-PlreclR,len);//~vamsI~
    }                                                              //~vamsI~
    else                                                           //~vamsI~
	    len=Plen-Pposr-Plinenofldlen;                              //~vamsR~
    if (Popt & PRTTO2PO_VHEXLINE_R || swnoligature)                //~vamsI~
    	uprttextout_NoLigature(xx,Pyy,pc,len);                     //~vamsI~
    else                                                           //~vamsI~
    	uprttextout(xx,Pyy,pc,len);                                //~vamsI~
    if (PlreclR>0)                                                 //~vamsR~
    {                                                              //~vamsI~
	    xx+=len*Mdrawcellw;                                        //~vamsI~
		pc+=len;                                                   //~vamsI~
        len=(Plen-Pposr)-Plinenofldlen-len;                        //~vamsI~
    	uprttextout_NoLigature(xx,Pyy,pc,len);                     //~vamsI~
    }                                                              //~vamsI~
}//prttextout2p                                                    //~vamsI~
#endif                                                             //~vamsI~
#ifdef UTF8UCS2                                                    //~va20I~
//===============================================================================//~va20I~
//utf8 file print                                                  //~va20I~
//data/dbcs is dd fmt                                              //~va20I~
//===============================================================================//~va20I~
#ifndef NOPRINT                                                    //~vam0I~
int  prttextoutw(int Popt,int Pyy,int Pcol,char *Pdata,char *Pdbcs,int Plen,int Plinenofldlen)//~va20R~
{                                                                  //~va20I~
    int reslen,xx;                                                 //~va20I~
    char *pc;                                                      //~va20R~
    int opttow,reslenhhex,hhexlen;                                 //~va80I~
//************************************                             //~va20I~
    opttow=Popt;                                                   //~va80R~
    Popt&=PRTTOWO_PREVIEW;                                         //~va80R~
UTRACEP("textoutw yy=%d,xcol=%d,linenosz=%d,len=%d\n",Pyy,Pcol,Plinenofldlen,Plen);//~va20M~
	if (!Plen)                                                     //~va20I~
    	return 0;                                                  //~va20I~
UTRACEP("prttextoutw opt=%x,yy=%d,xcol=%d,linenosz=%d,len=%d\n",opttow,Pyy,Pcol,Plinenofldlen,Plen);//~va80I~
UTRACED("prttextoutw data",Pdata,Plen);                            //~va80I~
UTRACED("textoutw",Pdbcs,Plen);                                    //~va20I~
//  if (*Pdbcs==VHEXLINEID)	//vhexline                             //~va20I~//~va80R~
    if (opttow & PRTTOWO_VHEXLINE)	//vhexline,dont depend on dbcsid==ff//~va80I~
    {                                                              //~va20I~
//  	uprttextout(Pcol*Mdrawcellw,Pyy,Pdata,Plen);               //~va20I~//~vampR~
    	uprttextout_NoLigature(Pcol*Mdrawcellw,Pyy,Pdata,Plen);    //~vampI~
        return 0;                                                  //~va20I~
    }                                                              //~va20I~
    xx=Pcol*Mdrawcellw;                                            //~va20I~
    pc=Pdata;                                                      //~va20I~
    reslen=Plen;                                                   //~va20I~
    if (Plinenofldlen)                                             //~va20I~
    {                                                              //~va20I~
		uprttextout_NoLigature(xx,Pyy,Pdata,Plinenofldlen);                   //~va20R~//~vamsR~
        xx+=Plinenofldlen*Mdrawcellw;                              //~va20I~
        pc+=Plinenofldlen;                                         //~va20I~
        reslen-=Plinenofldlen;                                     //~va20I~
    }                                                              //~va20I~
    if (opttow & PRTTOWO_HHEX)                                     //~va80I~
    {                                                              //~va80I~
		hhexlen=((opttow & PRTTOWO_LRECLMASK)>>PRTTOWO_LRECLMASKSHIFT);//~va80I~
    	reslenhhex=reslen-hhexlen;                                 //~va80I~
        reslen=hhexlen;                                            //~va80I~
UTRACED("prttextoutw dbcs",Pdbcs,hhexlen);                         //~va80I~
    	if (reslenhhex)                                            //~va80I~
        {                                                          //~va80I~
//  		uprttextout(xx+Mdrawcellw*reslen,Pyy,pc+reslen,reslenhhex);//~va80R~//~vampR~
    		uprttextout_NoLigature(xx+Mdrawcellw*reslen,Pyy,pc+reslen,reslenhhex);//~vampI~
            UTRACEP("prttextoutw hhex xx%d\n",xx);                 //~va80I~
            UTRACED("prttextoutw hhex",pc,reslenhhex);             //~va80I~
        }                                                          //~va80I~
    }                                                              //~va80I~
	uprttextoutw(0,xx,Pyy,pc,Pdbcs,reslen);                        //~va20I~
    return 0;                                                      //~va20I~
}//prttextoutw                                                     //~va20I~
#endif //!NOGOMEPRINT                                              //~vam0I~
#endif                                                             //~va20I~
//===============================================================================//~vXXEI~
//line draw                                                        //~vXXEI~
//===============================================================================//~vXXEI~
#ifndef NOPRINT                                                    //~vam0I~
int  prtlineout(int Pyy,int Plen)                                  //~vXXER~
{                                                                  //~vXXEI~
//************************************                             //~vXXEI~
	if (!Plen)                                                     //~vXXEI~
    	return 0;                                                  //~vXXEI~
        uprtlineout(0,Pyy,Plen*Mdrawcellw,Pyy);                    //~vXXER~
    return 0;                                                      //~vXXEI~
}//prtlineout                                                      //~vamdR~
#endif //!NOGOMEPRINT                                              //~vam0I~
//===============================================================================//~2B02I~
//file print                                                       //~2B02I~
//===============================================================================//~2B02I~
#ifndef NOPRINT                                                    //~vam0R~
	#ifdef GTKPRINT
//===============================================================================
void prtviewportfileGtkPrint()                 //~vXXER~           //~vam0R~
{                                                                  //~2B02I~
	int  prnw,prnh,logicalw,logicalh;                              //~2B23R~
	int  orgx,orgy,cellw,cellh;                                    //~2B23R~
    gdouble fmaxextx,fmaxexty,fscalex,fscaley;                     //~vXXEI~
    RECT rect;                                                     //~vXXER~
    cairo_t    *pcairocontext=NULL;                                //~vam0I~
//************************************                             //~2B02I~
    dprintf("prtviewportfileGtkPrint\n");                          //~vam0I~
    logicalw=Mprtcmaxcol+Mprtlinenosz*(Mlinenumber==TRUE);         //~2B04R~
    if (M2p)                                                       //~2B04R~
    	logicalw+=logicalw+Mprt2pcol;                              //~2B17R~
    logicalh=Mprtcmaxrow+(Mfooter+Mheader)*2;                      //~2B17I~
    cellw=Mdrawcellw;                                              //~v51hR~
    cellh=Mdrawcellh;                                              //~v51hR~
    	rect.left  =Mmarginl;                                      //~2B23I~
    	rect.top   =Mmargint;                                      //~2B23I~
    	rect.right =Mmarginr;                                      //~2B23I~
    	rect.bottom=Mmarginb;                                      //~2B23I~
//      prtmarginrect(/*Pdc,*/&rect,NULL);   //print rect by margin//~vamkR~//~vampR~
        prtmarginrect(/*Pdc,*/&rect);   //print rect by margin     //~vampI~
	    orgx=rect.left;                                            //~2B23R~
	    orgy=rect.top;                                             //~2B23R~
        prnw=rect.right-rect.left;                                 //~2B23R~
        prnh=rect.bottom-rect.top;                                 //~2B23R~
    fmaxextx=(gdouble)(logicalw)*cellw;                            //~vXXER~
    fmaxexty=(gdouble)(logicalh)*cellh;                            //~vXXER~
    fscalex=prnw/fmaxextx;                                         //~vXXEI~
    fscaley=prnh/fmaxexty;                                         //~vXXEI~
    UTRACEP("prtviewportfile prnh=%d/%lf-->scaley=%lf\n",prnh,fmaxexty,fscaley);                 //~v666R~//~vam0R~
    UTRACEP("prtviewportfile prnw=%d/%lf-->scalex=%lf\n",prnw,fmaxextx,fscalex);                 //~v666R~//~vam0R~
	if (Mpreviewmode)   //translate at gxepage                     //~vXXER~
    {                                                              //~vXXEI~
    	Mprevieworgx=(gdouble)orgx;                                //~vXXEI~
    	Mprevieworgy=(gdouble)orgy;                                //~vXXEI~
    }                                                              //~vXXEI~
    else                                                           //~vXXEI~
    {                                                              //~vXXEI~
//      gnome_print_translate(Ppprtctxt,(gdouble)orgx,(gdouble)(Mformszh-orgy));//~vXXER~//~vam0R~
		pcairocontext=gtk_print_context_get_cairo_context(Gpgtkprtctxt);//~vam0I~
        if (Mmarginshift)                                          //~vamtR~
        {                                                          //~vamtR~
            gxepage_papershift(&orgx,&orgy);                       //~vamtR~
        }                                                          //~vamtR~
        cairo_translate(pcairocontext,(gdouble)orgx,(gdouble)orgy);//~vam0R~
        UTRACEP("viewportfile trans orgx=%lf,orgy=%lf\n",(gdouble)orgx,(gdouble)orgy);//~v666R~//~vam0R~
    }                                                              //~vXXEI~
    if (!Mfullpage)                                                //~vXXEI~
    {                                                              //~vXXEI~
    	if (fscalex>fscaley)	//                                 //~vXXEI~
        	fscalex=fscaley;	//isotropic                        //~vXXEI~
        else                    //x<y                              //~vXXEI~
        	fscaley=fscalex;	//isotropic                        //~vXXEI~
    }                                                              //~vXXER~
    dprintf("viewport max-ext(x=%lf(col=%d),y=%lf(row=%d)),scalex=%lf,scaley=%lf\n",fmaxextx,logicalw,fmaxexty,logicalh,fscalex,fscaley);//~v666R~
    UTRACEP("viewport max-ext(x=%lf(col=%d),y=%lf(row=%d)),scalex=%lf,scaley=%lf\n",fmaxextx,logicalw,fmaxexty,logicalh,fscalex,fscaley);//~va6yI~
	if (Mpreviewmode)                                              //~vXXER~
    {                                                              //~vXXEI~
    	Mpreviewscalex=(gdouble)fscalex;                           //~vXXEI~
    	Mpreviewscaley=(gdouble)fscaley;                           //~vXXEI~
        upreviewsetfontscale(0,cellw,cellh,fscalex,fscaley);//0:file preview,set font scale//~vXXER~
    }                                                              //~vXXEI~
    else                                                           //~vXXEI~
    {                                                              //~vXXEI~
//	    gnome_print_scale(Ppprtctxt,fscalex,fscaley); //requred    //~vXXER~//~vam0R~
   	    cairo_scale(pcairocontext,fscalex,fscaley); //requred      //~vam0I~
        dprintf("viewportfile scale x=%lf,y=%lf\n",fscalex,fscaley);//~vamdR~
    }                                                              //~vXXEI~
UTRACEP("file viewport org=(%d,%d),logicalext=(%lf,%lf),form=(%d,%d),scale=(%lf,%lf)\n",orgx,orgy,fmaxextx,fmaxexty,prnw,prnh,fscalex,fscaley);//~va6yI~
	return;                                                        //~2B02R~
}//prtviewportfileGtkPrint                                                 //~2B24R~//~vam0R~
	#else    //!GTKPRINT
//===============================================================================
void prtviewportfile(GnomePrintContext *Ppprtctxt)                 //~vXXER~
{                                                                  //~2B02I~
	int  prnw,prnh,logicalw,logicalh;                              //~2B23R~
	int  orgx,orgy,cellw,cellh;                                    //~2B23R~
    gdouble fmaxextx,fmaxexty,fscalex,fscaley;                     //~vXXEI~
    RECT rect;                                                     //~vXXER~
//#ifdef CCC                                                       //~vamkR~
//#else                                                            //~vamkR~
//    gdouble scaled_orgx,scaled_orgy;                             //~vamkR~
//    int marginb;                                                 //~vamkR~
//#endif                                                           //~vamkR~
//  gdouble tblr[4];                                               //~vamkI~//~vampR~
//    gdouble fprnh,fprnw,forgx,forgy;                      //~vamkI~//~vamnR~//~vampR~
    int rc;                                                        //~vamnI~
    gdouble ftheta=0.0;                                            //~vamnR~
//************************************                             //~2B02I~
//    CPoint cp=Pdc->GetWindowOrg();                               //~2B23R~
//    CPoint cp2=Pdc->GetViewportOrg();                            //~2B23R~
//    CSize  cs=Pdc->GetWindowExt();                               //~2B23R~
//    CSize  cs2=Pdc->GetViewportExt();                            //~2B23R~
//  if (Mfullpage)                                                 //~v51hR~
    logicalw=Mprtcmaxcol+Mprtlinenosz*(Mlinenumber==TRUE);         //~2B04R~
    if (M2p)                                                       //~2B04R~
    	logicalw+=logicalw+Mprt2pcol;                              //~2B17R~
    logicalh=Mprtcmaxrow+(Mfooter+Mheader)*2;                      //~2B17I~
//  cellw=Mcellw;                                                  //~v51hR~
//  cellh=Mcellh;                                                  //~v51hR~
    cellw=Mdrawcellw;                                              //~v51hR~
    cellh=Mdrawcellh;                                              //~v51hR~
//dprintf("textout cell=%d,%d,-->windext=%d,%d\n",                 //~v666R~
//				Mdrawcellw,Mdrawcellh,logicalw*cellw,logicalh*cellh);//~v666R~
    	rect.left  =Mmarginl;                                      //~2B23I~
    	rect.top   =Mmargint;                                      //~2B23I~
    	rect.right =Mmarginr;                                      //~2B23I~
    	rect.bottom=Mmarginb;                                      //~2B23I~
//        tblr[0]=(gdouble)Mmargint;                                 //~vamkI~//~vampR~
//        tblr[1]=(gdouble)Mmarginb;                                 //~vamkI~//~vampR~
//        tblr[2]=(gdouble)Mmarginl;                                 //~vamkI~//~vampR~
//        tblr[3]=(gdouble)Mmarginr;                                 //~vamkI~//~vampR~
//      prtmarginrect(/*Pdc,*/&rect);   //print rect by margin     //~vamkR~
//      prtmarginrect(/*Pdc,*/&rect,tblr);   //print rect by margin//~vamkI~//~vampR~
        prtmarginrect(/*Pdc,*/&rect);   //print rect by margin     //~vampI~
//#ifndef CCC                                                      //~vamdR~
      if (!Mpreviewmode && Mlandscape)	//-R90:clockwize, org is top-right//~vamnR~
      {                                                            //~vamnI~
	   if (MlandscapeR<0)                  //-R90                  //~vamnR~
       {                                                           //~vamnI~
	    orgx=-(Mformszw-rect.left); //from bottom edge of portrait     land:left=port:top//~vamnR~
	    orgy=Mformszh-rect.top;  //from left edge of portrait   land:top=port:right//~vamnR~
//        forgx=-(Mformszw-tblr[2]);                                 //~vamnR~//~vampR~
//        forgy=Mformszh-tblr[0];                                    //~vamnR~//~vampR~
	    ftheta=-90.0;  //land:top is port:left                     //~vamnI~
       }                                                           //~vamnI~
	   else                        //R90                           //~vamnR~
       {                                                           //~vamnI~
	    orgx=rect.left;                                            //~vamnR~
	    orgy=-rect.top;                                            //~vamnR~
//        forgx=tblr[2];                                             //~vamnR~//~vampR~
//        forgy=-tblr[0];                                            //~vamnR~//~vampR~
	    ftheta=90.0;   //land:top is port:left                     //~vamnI~
       }                                                           //~vamnI~
		orgy=Mformszh-orgy; //later translate by (Mformszh-orgy)   //~vamnI~
      }                                                            //~vamnI~
      else                                                         //~vamnI~
      {                                                            //~vamnI~
	    orgx=rect.left;                                            //~2B23R~
  	    orgy=rect.top;                                             //~2B23R~//~vamnR~
//        forgx=tblr[2];                                             //~vamkI~//~vamnM~//~vampR~
//        forgy=tblr[0];                                             //~vamkI~//~vamnR~//~vampR~
      }                                                            //~vamnM~
        prnw=rect.right-rect.left;                                 //~2B23R~
        prnh=rect.bottom-rect.top;                                 //~2B23R~
//        fprnw=tblr[3]-tblr[2];                                     //~vamkI~//~vampR~
//        fprnh=tblr[1]-tblr[0];                                     //~vamkI~//~vampR~
//#ifdef CCC                                                       //~vamkR~
//#else                                                            //~vamkR~
//        marginb=Mformszh-rect.bottom;                            //~vamkR~
//        fmarginb=(gdouble)Mformszh-tblr[1];                      //~vamkR~
//#endif                                                           //~vamkR~
//#else                                                            //~vamdR~
//    prtgetcupsorgt(&rect,&rect,&prnw,&prnh);                     //~vamdR~
//#endif                                                           //~vamdR~
//  prnw-=PRINT_MARGIN_RIGHT_SAFETY;                               //~2B16R~
//by print coordinate (y orign is at bootom),to uprttextout        //~vXXER~
//    Pprect->top=Mformszh-orgy;                                   //~vXXER~
//    Pprect->bottom=Mformszh-orgy-prnh;                           //~vXXER~
//    Pprect->left=orgx;                                           //~vXXER~
//    Pprect->right=orgx+prnw;                                     //~vXXER~
    fmaxextx=(gdouble)(logicalw)*cellw;                            //~vXXER~
    fmaxexty=(gdouble)(logicalh)*cellh;                            //~vXXER~
    fscalex=prnw/fmaxextx;                                         //~vamkR~//~vamnR~
    fscaley=prnh/fmaxexty;                                         //~vamkR~//~vamnR~
//  fscalex=fprnw/fmaxextx;                                        //~vamkI~//~vamnR~
//  fscaley=fprnh/fmaxexty;                                        //~vamkI~//~vamnR~
    UTRACEP("%d(prnh)/%lf(fmaxecty)=%lf(fscaley)\n",prnh,fmaxexty,fscaley);//~vamkR~//~vamnR~
    UTRACEP("%d/(prnw)%lf(fmaxextx)=%lf(fscalex)\n",prnw,fmaxextx,fscalex);//~vamkR~//~vamnR~
	if (Mpreviewmode)   //translate at gxepage                     //~vXXER~
    {                                                              //~vXXEI~
    	Mprevieworgx=(gdouble)orgx;                                //~vXXEI~
    	Mprevieworgy=(gdouble)orgy;                                //~vXXEI~
    }                                                              //~vXXEI~
    else                                                           //~vXXEI~
    {                                                              //~vXXEI~
  	    gnome_print_translate(Ppprtctxt,(gdouble)orgx,(gdouble)(Mformszh-orgy));//~vXXER~//~vamnR~//~vampM~
        UTRACEP("viewportfile(GnomePrint) trans Mlandscape=%d,MlandscapeR=%d,orgx=%lf,orgy=%lf,Mformszh=%d\n",Mlandscape,MlandscapeR,(gdouble)orgx,(gdouble)Mformszh-orgy,Mformszh);//~vamdR~//~vamnR~//~vampM~
	    rc=gnome_print_rotate(Ppprtctxt,ftheta);  //land:top is port:left//~vamnI~
		UTRACEP("file viewport gnome_print_rotate rc=%d rotate=%lf\n",rc,ftheta);//~vamnI~//~vampR~
    }                                                              //~vXXEI~
    if (!Mfullpage)                                                //~vXXEI~
    {                                                              //~vXXEI~
    	if (fscalex>fscaley)	//                                 //~vXXEI~
        	fscalex=fscaley;	//isotropic                        //~vXXEI~
        else                    //x<y                              //~vXXEI~
        	fscaley=fscalex;	//isotropic                        //~vXXEI~
    }                                                              //~vXXER~
    dprintf("viewport max-ext(x=%lf(col=%d),y=%lf(row=%d)),scalex=%lf,scaley=%lf\n",fmaxextx,logicalw,fmaxexty,logicalh,fscalex,fscaley);//~v666R~
    UTRACEP("viewport max-ext(x=%lf(col=%d),y=%lf(row=%d)),scalex=%lf,scaley=%lf\n",fmaxextx,logicalw,fmaxexty,logicalh,fscalex,fscaley);//~va6yI~
	if (Mpreviewmode)                                              //~vXXER~
    {                                                              //~vXXEI~
    	Mpreviewscalex=(gdouble)fscalex;                           //~vXXEI~
    	Mpreviewscaley=(gdouble)fscaley;                           //~vXXEI~
        upreviewsetfontscale(0,cellw,cellh,fscalex,fscaley);//0:file preview,set font scale//~vXXER~
    }                                                              //~vXXEI~
    else                                                           //~vXXEI~
    {                                                              //~vXXEI~
//#ifdef CCC                                                       //~vamkR~
//#else                                                            //~vamkR~
////      scaled_orgx=orgx/fscalex;                                //~vamkR~
////      scaled_orgy=fmaxexty+marginb/fscaley;                    //~vamkR~
////      scaled_orgx=forgx/fscalex;                               //~vamkR~
////      scaled_orgy=fmaxexty+fmarginb/fscaley;                   //~vamkR~
//        scaled_orgx=forgx;                                       //~vamkR~
//        scaled_orgy=Mformszh-forgy;                              //~vamkR~
//        gnome_print_translate(Ppprtctxt,scaled_orgx,scaled_orgy);//~vamkR~
//        UTRACEP("viewportfile(GnomePrint) trans scaled_orgx=%lf,scaled_orgy=%lf,forgx=%lf,Mmarginl=%d,forgy=%lf,margint=%d,fmarginb=%lf,Mformszh=%d\n",scaled_orgx,scaled_orgy,forgx,Mmarginl,forgy,Mmargint,fmarginb,Mformszh);//~vamkR~
//#endif                                                           //~vamkR~
	    gnome_print_scale(Ppprtctxt,fscalex,fscaley); //requred    //~vXXER~
        UTRACEP("prtviewportfile(Gnome) set scale context=%p,x=%lf,y=%lf\n",Ppprtctxt,fscalex,fscaley);//~vamdR~
    }                                                              //~vXXEI~
dprintf("file viewport org=(%d,%d),logicalext=(%lf,%lf),form=(%d,%d),scale=(%lf,%lf)\n",orgx,orgy,fmaxextx,fmaxexty,prnw,prnh,fscalex,fscaley);//~v666R~
UTRACEP("file viewport org=(%d,%d),logicalext=(%lf,%lf),form=(%d,%d),scale=(%lf,%lf)\n",orgx,orgy,fmaxextx,fmaxexty,prnw,prnh,fscalex,fscaley);//~va6yI~
	return;                                                        //~2B02R~
}//prtviewportfile                                                 //~2B24R~
	#endif   //!GTKPRINT
#endif //!NOGOMEPRINT                                              //~vam0I~
#ifndef NOPRINT                                                    //~vam0I~
//===============================================================================//~2B23I~
//file print                                                       //~2B23I~
//output coordinate by top-left origin                             //~vamkR~
//===============================================================================//~2B23I~
//void prtmarginrect(/*CDC *Pdc,*/RECT *Pprect)                    //~vamkR~
//void prtmarginrect(/*CDC *Pdc,*/RECT *Pprect,gdouble *Pptblr)      //~vamkI~//~vampR~
void                                                               //~vampI~
prtmarginrect(/*CDC *Pdc,*/RECT *Pprect)                           //~vampI~
{                                                                  //~2B23I~
	int  prnw,prnh,/*prnwmm,prnhmm,*/margin,top,left,bottom,right; //~vXXER~
//    int  maxtb,maxlr;                                              //~vamjI~//~vamnR~
    float fwpixbymm,fhpixbymm;                                     //~2B23I~
    RECT defmargin;                                                //~vXXEI~
//    gdouble deftblr[4];                                            //~vamkI~//~vampR~
//    gdouble wktblr[4];                                             //~vamkI~//~vampR~
//    gdouble fmaxtb,fmaxlr;                                         //~vamkI~//~vampR~
//************************************                             //~2B23I~
	UTRACEP("xxeprt.prtmarginrect parm l=%d,r=%d,t=%d,b=%d\n",Pprect->left,Pprect->right,Pprect->top,Pprect->bottom);//+@@@@R~
//  xxemain_prtdefaultmarginrect(&defmargin);                      //~vamkR~
//  xxemain_prtdefaultmarginrect(&defmargin,deftblr);              //~vamkI~//~vampR~
    xxemain_prtdefaultmarginrect(&defmargin);	//unit:mm                      //~vampI~//+@@@@R~
	UTRACEP("xxeprt.prtmarginrect default l=%d,r=%d,t=%d,b=%d\n",defmargin.left,defmargin.right,defmargin.top,defmargin.bottom);//+@@@@R~
//  fwpixbymm=(float)prnw/prnwmm;                                  //~vXXER~
//  fhpixbymm=(float)prnh/prnhmm;                                  //~vXXER~
#ifndef AAA                                                        //~vam2R~
	if (!Pprect->left)                                             //~vXXEI~
    {                                                              //~vamkI~
    	Pprect->left=defmargin.left;                               //~vXXEI~
//        Pptblr[2]=deftblr[2];                                      //~vamkM~//~vampR~
    }                                                              //~vamkI~
	if (!Pprect->right)                                            //~vXXEI~
    {                                                              //~vamkI~
    	Pprect->right=defmargin.right;                             //~vXXEI~
//        Pptblr[3]=deftblr[3];                                      //~vamkM~//~vampR~
    }                                                              //~vamkI~
	if (!Pprect->top)                                              //~vXXEI~
    {                                                              //~vamkI~
    	Pprect->top=defmargin.top;                                 //~vXXEI~
//        Pptblr[0]=deftblr[0];                                      //~vamkM~//~vampR~
    }                                                              //~vamkI~
	if (!Pprect->bottom)                                           //~vXXEI~
    {                                                              //~vamkI~
    	Pprect->bottom=defmargin.bottom;                           //~vXXEI~
//        Pptblr[1]=deftblr[1];                                      //~vamkM~//~vampR~
    }                                                              //~vamkI~
#else                                                              //~vam2M~
    Pprect->left+=defmargin.left;                                  //~vam2M~
    Pprect->right+=defmargin.right;                                //~vam2M~
    Pprect->top+=defmargin.top;                                    //~vam2M~
    Pprect->bottom+=defmargin.bottom;                              //~vam2M~
#endif                                                             //~vam2M~
    prnh=Mformszh;                                                 //~vXXEI~
    prnw=Mformszw;                                                 //~vXXEI~
	UTRACEP("prtmarginrect margin mm left=%d,right=%d,top=%d,bot=%d\n",//~vam2R~
    			Pprect->left,Pprect->right,Pprect->top,Pprect->bottom);//~vam2R~
//    UTRACEP("prtmarginrect margin mm left=%lf,right=%lf,top=%lf,bot=%lf\n",//~vamkI~//~vampR~
//                Pptblr[2],Pptblr[3],Pptblr[0],Pptblr[1]);          //~vamkI~//~vampR~
	fwpixbymm=Sfmm2pt;		//point per mm                         //~vXXER~
	fhpixbymm=Sfmm2pt;		//point per mm                         //~vXXER~
//	margin=max(0,Pprect->left-MARGIN_FORM_CLIP);                   //~vXXER~
	margin=Pprect->left;                                           //~vXXER~
	left=(int)(margin*fwpixbymm+(margin!=0));                      //~2B23I~
//	margin=max(0,Pprect->top-MARGIN_FORM_CLIP);                    //~vXXER~
  	margin=Pprect->top;                                            //~vXXER~
	top=(int)(margin*fhpixbymm+(margin!=0));                       //~2B23I~
//  margin=max(0,Pprect->right-MARGIN_FORM_CLIP);                  //~vXXER~
    margin=Pprect->right;                                          //~vXXER~
	right=(int)(margin*fwpixbymm+(margin!=0));   //right margin pos by pixel//~2B23I~
//  margin=max(0,Pprect->bottom-MARGIN_FORM_CLIP);                 //~vXXER~
    margin=Pprect->bottom;                                         //~vXXER~
	bottom=(int)(margin*fhpixbymm+(margin!=0));   //bottom margin pos by pixel//~2B23I~
//                                                                 //~vamkI~
//    wktblr[0]=Pptblr[0]*fwpixbymm;                                 //~vamkR~//~vampR~
//    wktblr[1]=Pptblr[1]*fwpixbymm;                                 //~vamkR~//~vampR~
//    wktblr[2]=Pptblr[2]*fwpixbymm;                                 //~vamkR~//~vampR~
//    wktblr[3]=Pptblr[3]*fwpixbymm;                                 //~vamkR~//~vampR~
  if (Mlandscape)                                                  //~vamcI~
  {                                                                //~vamcM~
#ifdef AAA                                                         //~vamnI~
  	maxtb=max(top,bottom);                                         //~vamjI~
  	maxlr=max(left,right);                                         //~vamjI~
    top=maxtb;                                                     //~vamjI~
    bottom=maxtb;                                                  //~vamjI~
    left=maxlr;                                                    //~vamjI~
    right=maxlr;                                                   //~vamjI~
	Pprect->top =left;                                             //~vamcI~
	Pprect->left=top;                                              //~vamcM~
	Pprect->bottom=prnh-right;     //prnh=Mformszh:landscape value //~vamkR~//~vammR~
	Pprect->right =prnw-bottom;                                    //~vamkR~//~vammR~
#else       //-R90:top=left                                        //~vamnI~
  if (MlandscapeR<0)                                               //~vamnI~
  {                                                                //~vamnI~
	Pprect->top =right;                                            //~vamnI~
	Pprect->left=top;                                              //~vamnI~
	Pprect->bottom=prnh-left;    //prnh=Mformszh:landscape value   //~vamnI~
	Pprect->right =prnw-bottom;                                    //~vamnI~
  }                                                                //~vamnI~
  else         //bottom:left                                       //~vamnI~
  {                                                                //~vamnI~
	Pprect->top =left;                                             //~vamnI~
	Pprect->left=bottom;                                           //~vamnR~
	Pprect->bottom=prnh-right;    //prnh=Mformszh:landscape value  //~vamnI~
	Pprect->right =prnw-top;                                       //~vamnI~
  }                                                                //~vamnI~
#endif                                                             //~vamnI~
//    if (wktblr[0]<wktblr[1])                                       //~vamkI~//~vampR~
//        fmaxtb=wktblr[1];                                          //~vamkR~//~vampR~
//    else                                                           //~vamkI~//~vampR~
//        fmaxtb=wktblr[0];                                          //~vamkR~//~vampR~
//    if (wktblr[2]<wktblr[3])                                       //~vamkI~//~vampR~
//        fmaxlr=wktblr[3];                                          //~vamkR~//~vampR~
//    else                                                           //~vamkI~//~vampR~
//        fmaxlr=wktblr[2];                                          //~vamkR~//~vampR~
//    Pptblr[0]=fmaxlr;  //top                                       //~vamkI~//~vampR~
//    Pptblr[2]=fmaxtb;                                              //~vamkI~//~vampR~
//    Pptblr[1]=prnh-fmaxlr;                                         //~vamkI~//~vammR~//~vampR~
//    Pptblr[3]=prnw-fmaxtb;                                         //~vamkI~//~vammR~//~vampR~
  }                                                                //~vamcM~
  else                                                             //~vamcM~
  {                                                                //~vamcI~
	Pprect->top =top;                                              //~2B23I~
	Pprect->left=left;                                             //~2B23I~
	Pprect->bottom=prnh-bottom;                                    //~2B23I~
	Pprect->right =prnw-right;                                     //~2B23I~
//    Pptblr[0]=wktblr[0];                                           //~vamkI~//~vampR~
//    Pptblr[2]=wktblr[2];                                           //~vamkI~//~vampR~
//    Pptblr[1]=(gdouble)prnh-wktblr[1];                             //~vamkI~//~vampR~
//    Pptblr[3]=(gdouble)prnw-wktblr[3];                             //~vamkI~//~vampR~
  }                                                                //~vamcI~
	UTRACEP("prtmarginrect point:Mlandscape=%d,prnh=%d,prnw=%d,t=%d,l=%d,b=%d,r=%d\n",              //~v666R~//~vamcR~
	Mlandscape,prnh,prnw,Pprect->top,Pprect->left,Pprect->bottom,Pprect->right);//~vamcR~
//    UTRACEP("prtmarginrect pointF:t=%lf,l=%lf,b=%lf,r=%lf\n",      //~vamkI~//~vampR~
//        Pptblr[0],Pptblr[2],Pptblr[1],Pptblr[3]);                  //~vamkI~//~vampR~
    return;                                                        //~2B23I~
}//prtmarginrect                                                    //~2B23I~//~vam2R~
#endif //!NOGOMEPRINT                                              //~vam0I~
//===============================================================================//~vamdI~
//get org position and box range from edge margin                  //~vamdI~
//===============================================================================//~vamdI~
#ifndef NOPRINT                                                    //~vap1I~
void                                                               //~vamdI~
prtgetcupsorgt(RECT *Pprect,RECT *Porg,int *Ppwidth,int *Ppheight) //~vamdR~
{                                                                  //~vamdI~
	int  ll,rr,tt,bb,prnh,prnw,ww,hh;                              //~vamdI~
//************************************                             //~vamdI~
    prnh=Mformszh;                                                 //~vamdI~
    prnw=Mformszw;                                                 //~vamdI~
    ll=Pprect->left;                                               //~vamdI~
    rr=Pprect->right;                                              //~vamdI~
    tt=Pprect->top;                                                //~vamdI~
    bb=Pprect->bottom;                                             //~vamdI~
    UTRACEP("prtgetcupsorg input (%d,%d)--(%d,%d) Mformszw=%d,Mformszh=%d\n",ll,tt,rr,bb,prnw,prnh);//~vamdI~
    if (Mlandscape)         //rotated left90 but left==right,top==bottom for both case//~vamdI~
    {                                                              //~vamdI~
      	Porg->left=tt;          //==bottom                         //~vamdI~
      	Porg->right=prnh-bb;	//right pos                        //~vamdI~
      	Porg->top=prnw-rr;      //top pos,rotate left90 ==prnw-right,top>bottom//~vamdI~
      	Porg->bottom=ll;        //bottom pos                       //~vamdI~
        ww=prnh-tt-bb;                                             //~vamdI~
        hh=prnw-ll-rr;                                             //~vamdI~
    }                                                              //~vamdI~
    else                                                           //~vamdI~
    {                                                              //~vamdI~
      	Porg->left=ll;            //left pos                       //~vamdI~
      	Porg->right=prnw-rr;      //right pos                      //~vamdI~
      	Porg->top=prnh-tt;        //top pos, top>bottom            //~vamdI~
      	Porg->bottom=bb;          //botom pos                      //~vamdI~
        ww=prnw-ll-rr;                                             //~vamdI~
        hh=prnh-tt-bb;                                             //~vamdI~
    }                                                              //~vamdI~
    if (Ppwidth)                                                   //~vamdI~
	    *Ppwidth=ww;                                               //~vamdI~
    if (Ppheight)                                                  //~vamdR~
	    *Ppheight=hh;                                              //~vamdI~
    UTRACEP("prtgetcupsorg output (%d,%d)--(%d,%d)  ww=%d,hh=%d\n",Porg->left,Porg->top,Porg->right,Porg->bottom,ww,hh);//~vamdR~
                                                                   //~vamdI~
}//prtgetcupsorg                                                   //~vamdI~
#endif //!NOPRINT                                                  //~vap1I~
//===============================================================================//~vXXEI~
//get default page margin(unit:milimeter)                          //~vXXEI~
//===============================================================================//~vXXEI~
#ifndef NOPRINT                                                    //~vam0R~
	#ifdef GTKPRINT
//===============================================================================
//=get margin of Mformtype of Mprinter                             //~vamcI~
//===============================================================================//~vamcI~
//void xxemain_prtdefaultmarginrect(RECT *Pprect)                  //~vamkR~
//void xxemain_prtdefaultmarginrect(RECT *Pprect,gdouble *Pptbrl)    //~vamkI~//~vampR~
void                                                               //~vampI~
xxemain_prtdefaultmarginrect(RECT *Pprect)                         //~vampI~
{                                                                  //~vXXEI~
//  const GnomePrintUnit *pgpumm,*pgpu;                            //~vXXEI~//~vam0R~
//  gdouble fmr,fml,fmt,fmb;                                       //~vXXER~//~vam0R~
//  GnomePrintConfig *pprtconf; //default printer may change       //~v666I~//~vam0R~
//************************************                             //~vXXEI~
    UTRACEP("xxemain_prtdefaultmarginrect\n");                                       //~v666R~//~vamkR~
//if (csubgetcupspagesz(0,Pprect,0/*form*/))	//get printer margin by cups//~vamkR~
//if (csubgetcupspagesz(0,Pprect,0/*form*/,Pptbrl))	//get printer margin by cups//~vamkI~//~vampR~
  if (csubgetcupspagesz(0,Pprect,0/*form*/))	//get printer margin by cups//~vampI~
  {                                                                //~va6yI~
//  pprtconf=0;                                                    //~v666I~//~vam0R~
//  pprtconf=(GnomePrintConfig*)uprtgetconfig((void*)pprtconf,Mprinter);//~v666R~//~vam0R~
//  pgpumm=gnome_print_unit_get_by_name("MilliMeter");             //~vXXER~//~vam0R~
//    gnome_print_config_get_length(pprtconf,GNOME_PRINT_KEY_PAGE_MARGIN_LEFT,&fml,&pgpu);//~v666I~//~vam0R~
//    gnome_print_convert_distance(&fml,pgpu,pgpumm);//convert to mm //~vXXEI~//~vam0R~
//    gnome_print_config_get_length(pprtconf,GNOME_PRINT_KEY_PAGE_MARGIN_RIGHT,&fmr,&pgpu);//~v666I~//~vam0R~
//    gnome_print_convert_distance(&fmr,pgpu,pgpumm);                //~vXXEI~//~vam0R~
//    gnome_print_config_get_length(pprtconf,GNOME_PRINT_KEY_PAGE_MARGIN_TOP,&fmt,&pgpu);//~v666I~//~vam0R~
//    gnome_print_convert_distance(&fmt,pgpu,pgpumm);                //~vXXEI~//~vam0R~
//    gnome_print_config_get_length(pprtconf,GNOME_PRINT_KEY_PAGE_MARGIN_BOTTOM,&fmb,&pgpu);//~v666I~//~vam0R~
//    gnome_print_convert_distance(&fmb,pgpu,pgpumm);                //~vXXEI~//~vam0R~
//    dprintf("page margin mm l=%lf,r=%lf,t=%lf,b=%lf\n",fml,fmr,fmt,fmb);//~v666R~//~vam0R~
//    Pprect->top =(int)(fmt+0.9999);                                //~vXXEI~//~vam0R~
//    Pprect->left=(int)(fml+0.9999);                                //~vXXEI~//~vam0R~
//    Pprect->bottom=(int)(fmb+0.9999);                              //~vXXEI~//~vam0R~
//    Pprect->right =(int)(fmr+0.9999);                              //~vXXEI~//~vam0R~
	Pprect->top=0;                                                 //~vam0I~
    Pprect->left=0;                                                //~vam0I~
    Pprect->bottom=0;                                              //~vam0I~
    Pprect->right=0;                                               //~vam0I~
    dprintf("csubgetcupspagesize failed,margin forced to 0\n");    //~vam0I~
//  gnome_print_config_unref(pprtconf);                            //~v666I~//~vam0R~
  }                                                                //~va6yI~
    return;                                                        //~vXXEI~
}//xxemain_prtdefaultmarginrect                                    //~va6yR~
	#else    //!GTKPRINT
//===============================================================================
//=unit:mm                                                         //+@@@@I~
//===============================================================================//+@@@@I~
//void xxemain_prtdefaultmarginrect(RECT *Pprect)                  //~vamkR~
//void xxemain_prtdefaultmarginrect(RECT *Pprect,gdouble *Pptbrl)    //~vamkI~//~vampR~
void                                                               //~vampI~
xxemain_prtdefaultmarginrect(RECT *Pprect)                         //~vampI~
{                                                                  //~vXXEI~
    const GnomePrintUnit *pgpumm,*pgpu;                            //~vXXEI~
    gdouble fmr,fml,fmt,fmb;                                       //~vXXER~
    GnomePrintConfig *pprtconf; //default printer may change       //~v666I~
//************************************                             //~vXXEI~
    dprintf("marginrect\n");                                       //~v666R~
//if (csubgetcupspagesz(0,Pprect,0/*form*/))	//get printer margin by cups//~vamkR~
//if (csubgetcupspagesz(0,Pprect,0/*form*/,Pptbrl))	//get printer margin by cups//~vamkI~//~vampR~
  if (csubgetcupspagesz(0,Pprect,0/*form*/))	//get printer margin by cups//~vampI~
  {                                                                //~va6yI~
    pprtconf=0;                                                    //~v666I~
    pprtconf=(GnomePrintConfig*)uprtgetconfig((void*)pprtconf,Mprinter);//~v666R~
	pgpumm=gnome_print_unit_get_by_name("MilliMeter");             //~vXXER~
//  gnome_print_config_get_length(Gpprtconf,GNOME_PRINT_KEY_PAGE_MARGIN_LEFT,&fml,&pgpu);//~v666R~
    gnome_print_config_get_length(pprtconf,GNOME_PRINT_KEY_PAGE_MARGIN_LEFT,&fml,&pgpu);//~v666I~
    gnome_print_convert_distance(&fml,pgpu,pgpumm);//convert to mm //~vXXEI~
//  gnome_print_config_get_length(Gpprtconf,GNOME_PRINT_KEY_PAGE_MARGIN_RIGHT,&fmr,&pgpu);//~v666R~
    gnome_print_config_get_length(pprtconf,GNOME_PRINT_KEY_PAGE_MARGIN_RIGHT,&fmr,&pgpu);//~v666I~
    gnome_print_convert_distance(&fmr,pgpu,pgpumm);                //~vXXEI~
//  gnome_print_config_get_length(Gpprtconf,GNOME_PRINT_KEY_PAGE_MARGIN_TOP,&fmt,&pgpu);//~v666R~
    gnome_print_config_get_length(pprtconf,GNOME_PRINT_KEY_PAGE_MARGIN_TOP,&fmt,&pgpu);//~v666I~
    gnome_print_convert_distance(&fmt,pgpu,pgpumm);                //~vXXEI~
//  gnome_print_config_get_length(Gpprtconf,GNOME_PRINT_KEY_PAGE_MARGIN_BOTTOM,&fmb,&pgpu);//~v666R~
    gnome_print_config_get_length(pprtconf,GNOME_PRINT_KEY_PAGE_MARGIN_BOTTOM,&fmb,&pgpu);//~v666I~
    gnome_print_convert_distance(&fmb,pgpu,pgpumm);                //~vXXEI~
    dprintf("page margin l=%lf,r=%lf,t=%lf,b=%lf\n",fml,fmr,fmt,fmb);//~v666R~
	Pprect->top =(int)(fmt+0.9999);                                //~vXXEI~
	Pprect->left=(int)(fml+0.9999);                                //~vXXEI~
	Pprect->bottom=(int)(fmb+0.9999);                              //~vXXEI~
	Pprect->right =(int)(fmr+0.9999);                              //~vXXEI~
    gnome_print_config_unref(pprtconf);                            //~v666I~
  }                                                                //~va6yI~
    return;                                                        //~vXXEI~
}//xxemain_prtdefaultmarginrect                                    //~va6yR~
	#endif   //!GTKPRINT
#endif //!NOGOMEPRINT                                              //~vam0I~
#ifndef NOPRINT                                                    //~vam0I~
//===============================================================================//~2B23R~
//preview of page setup dialog                                     //~2C03R~
//===============================================================================//~2B23R~
int xxemain_prtpreview(int Phcopysw,int Pcurpage)                  //~vXXER~
{                                                                  //~2B23R~
    int /*orgx,orgy,width,height,*/rc=0;                           //~vXXER~
//  CFont *pnewfont;                                               //~v51hR~
//************************************                             //~2B23R~
    Mpreviewmode=1;                                                //~vXXEM~
	Mhcopysw=Phcopysw;                                             //~2B23M~
	Mprtcurpage=Pcurpage;                                          //~2C14R~
//  pnewfont=createfontsub(Mcharset,Mfontstyle,Mttfont,Mfontheight,Mfontwidth,0);//~2C03R~
//  pnewfont=createfontsub(Mcharset,NULL,Mttfont,fonth,fontw,0);//try default font//~v51hI~
    xxemain_onprepareprinting(0);   //0:preview id                 //~vXXER~
    if (Mhcopysw)                                                  //~2B24M~
//      prtscr(/*Pdc,Mpprtfont,*/width,height,orgx,orgy);          //~vXXER~
        prtscr();	//1:preview                                    //~vXXEI~
    else                                                           //~2B24I~
//      rc=prtfile(/*Pdc,Mpprtfont,*/width,height,orgx,orgy);      //~vXXER~
        rc=prtfile();  //1:preview                                 //~vXXEI~
//  Mpreviewmode=0;                                                //~vXXEI~//~va8aR~
	xxemain_onendprinting(/*Pdc,0*/);	//free work                //~vXXER~
    Mpreviewmode=0;                                                //~va8aI~
//  pnewfont->DeleteObject();                                      //~v51hR~
    return rc;                                                     //~2B23I~
}//xxemain_prtpreview                                              //~vXXER~
#endif //!NOGOMEPRINT                                              //~vam0I~
//===============================================================================//~vXXEI~
//get font for printer                                             //~vXXER~
//===============================================================================//~vXXEI~
#ifndef NOPRINT                                                    //~vam0R~
	#ifdef GTKPRINT
//===============================================================================//~vam0I~
int  prtcreatefont(void)                                           //~vXXER~
{                                                                  //~vXXEI~
    char *pfontname;                                               //~vXXER~
    PangoFontMetrics *pfm;                                         //~vam0R~
//************************************                             //~vXXEI~
	if (Mhcopysw)                                                  //~vXXEI~
		pfontname=Mfontstyle;                                      //~vXXER~
    else                                                           //~vXXEI~
		pfontname=Mprtfontstyle;                                   //~vXXER~
//  Mpprtfont=uprtcreatefont(pfontname,&Mpfontszw,&Mpfontszh,0);   //~v75XR~//~vam0R~
    pfm=uprtcreatefontGtkPrint(pfontname,&Mpfontszw,&Mpfontszh);   //~vam0R~
//  if (!Mpprtfont)                                                //~vXXEI~//~vam0R~
//      return 4;                                                  //~vXXEI~//~vam0R~
//	Mprtfontascendant=gnome_font_get_ascender(Mpprtfont);          //~vXXEI~//~vam0R~
	Mprtfontascendant=pango_font_metrics_get_ascent(pfm);          //~vam0R~
	Mprtfontascendant=PANGO_PIXELS(Mprtfontascendant);//by point   //~vam0R~
	if (Mpfontszh<Mpcellszh-DEF_TEXTCSR_HEIGHT)                    //~vXXEI~
    {                                                              //~vXXEI~
        Mpfontoffsy=(Mpcellszh-DEF_TEXTCSR_HEIGHT-Mpfontszh);      //~vXXEI~
    }                                                              //~vXXEI~
    else                                                           //~vXXEI~
    	Mpfontoffsy=0;                                             //~vXXEI~
    if (Mpfontszw<Mpcellszw)                                       //~vXXEI~
    	Mpfontoffsx=(Mpcellszw-Mpfontszw)/2;                       //~vXXEI~
    else                                                           //~vXXEI~
    	Mpfontoffsx=0;                                             //~vXXEI~
    UTRACEP("prtcreatefont(Gtk) print font name=%s,w=%d,h=%d,offsx=%d,offsy=%d\n",pfontname,Mpfontszw,Mpfontszh,Mpfontoffsx,Mpfontoffsy);//~vamdR~
	return 0;                                                      //~vXXEI~
}//prtcreatefont                                              //~vXXER~//~vam0R~
	#else    //!GTKPRINT
//===============================================================================//~vam0I~
int  prtcreatefont(void)                                           //~vXXER~
{                                                                  //~vXXEI~
    char *pfontname;                                               //~vXXER~
//************************************                             //~vXXEI~
	if (Mhcopysw)                                                  //~vXXEI~
		pfontname=Mfontstyle;                                      //~vXXER~
    else                                                           //~vXXEI~
		pfontname=Mprtfontstyle;                                   //~vXXER~
//  Mpprtfont=uprtcreatefont(pfontname,&Mpfontszw,&Mpfontszh);     //~v75XR~
    Mpprtfont=uprtcreatefont(pfontname,&Mpfontszw,&Mpfontszh,0);   //~v75XR~
    if (!Mpprtfont)                                                //~vXXEI~
        return 4;                                                  //~vXXEI~
	Mprtfontascendant=gnome_font_get_ascender(Mpprtfont);          //~vXXEI~
	if (Mpfontszh<Mpcellszh-DEF_TEXTCSR_HEIGHT)                    //~vXXEI~
    {                                                              //~vXXEI~
        Mpfontoffsy=(Mpcellszh-DEF_TEXTCSR_HEIGHT-Mpfontszh);      //~vXXEI~
    }                                                              //~vXXEI~
    else                                                           //~vXXEI~
    	Mpfontoffsy=0;                                             //~vXXEI~
    if (Mpfontszw<Mpcellszw)                                       //~vXXEI~
    	Mpfontoffsx=(Mpcellszw-Mpfontszw)/2;                       //~vXXEI~
    else                                                           //~vXXEI~
    	Mpfontoffsx=0;                                             //~vXXEI~
    UTRACEP("create print font name=%s,w=%d,h=%d,offsx=%d,offsy=%d\n",pfontname,Mpfontszw,Mpfontszh,Mpfontoffsx,Mpfontoffsy);//~vamdR~
//  pango_layout_set_font_description(Gpprtlayout,Gfontdata[1].FDfontdesc);//~vXXER~
	return 0;                                                      //~vXXEI~
}//prtcreatefont                                              //~vXXER~//~vam0R~
	#endif   //!GTKPRINT
#endif //!NOGOMEPRINT                                              //~vam0I~
