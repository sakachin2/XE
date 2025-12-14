//*CID://+v7f0R~:                             update#=  405;       //~vbDsR~//~v7f0R~
//*********************************************************************//~2818I~
//* wxecsub.h                                                      //~2818I~
//*********************************************************************//~2818I~
//v7f4:251007 (LNX)by v7f1, w0 NoComb(including format)  was not displayed by altchFormat('='). ifndef JJJ//~v7f0I~
//vbDs:250730 (gxe)vbDp for gxe(split combining,vhex csr data color)//~vbDsI~
//vbBz:241219 (gxe:bug) when sudo panel height shrink; get_window_size is available with gtk_windw_set_default_size to save/restore window size.//~vbBzI~
//vbAh:240616 (gxe)display split combining(lig on and off). when added non space(for ex 'A') after combining half width shadow appears. use this effect.//~vbAhI~
//vbA3:240531 (Bug:gxe)SCM remaining char shown by altch color     //~vbA3I~
//vbA2:240529 (gxe) gdk_color_to_string was deprecated             //~vbA2I~
//vbzb:240129 (XXE:Bug)cursor hides background text                //~vbzbI~
//vbz5:240120 try vbz3 to XXE(apichk by char extent)               //~vbz5I~
//vbmf:180803 show altch for SCM when COMBINE_NP                   //~vbmfI~
//vbme:180731 (gxe)multiple SCM support                            //~vbmeI~
//vbmc:180730 (gxe/wxe)attr:green for combining after unprintable like as console version//~vbmbI~
//vbmb:180723 (gxe:bug of vbma)unicomb:NP dose not show altch      //~vbmbI~
//vbm8:180716 (gxe:Bug)combine may reduce glyphctr(u306f+u399a)    //~vbm8I~
//vbkw:180704 (gxe)try to keep col width for the case of u-0327 has 2 glyph(width=xx and width=0)//~vbkwI~
//vbkq:180628 (XXE)for also nocombine mode Spacing Combining Marks(SCM) unicode(if not combined,it becomes glyphctr=2)//~vbkqI~
//vbkp:180627 (gxe)do ligature for also width0 under COMBINE_NP mode//~vbkpI~
//vbkn:180627 (gxe)width=0 char over 0x20000 was not treated as combining//~vbknI~
//vbk6:180612 (XXE)Spacing Combining Marks unicode(if not combined,it becomes glyphctr=2)//~vbk4I~
//vbk4:180611 (XXE)when Ligature:OFF unicomb:COM,combining char was separated because geometry->width!=0 for combining char//~vbk4I~
//vbi9:180221 (GTK3:bug)window size recovery err                   //~vbi9I~
//vbi7:180221 (gxe)cupsGetDest is time consuming,change to cupsServer() for cups active chk;see vat0(enumprinter hung if cups not running)//~vbi7I~
//vb7z:170131 (gxe:bug)dirlist file drag cause scroll              //~vb7zI~
//vb4A:160815 if UNICOMB UNPR mode and LIGATURE ON, write altch just after base char using GetTextExtentPoint32W//~vb4AI~
//varc:140215 add resizehint option  --gh={Y|n}                    //~varcI~
//var8:140127 gtk3 suppott                                         //~var8I~
//var4:140118 set transient for msgbox from dialog to pretect heide msgbox behind dialog//~var4I~
//vamu:131015 (GtkPrint)"B5JIS" is not defind on gtk_paper_size_get_papername()//~vamuI~
//vams:131010 Ligature off when Bin,VHEX,HEX mode                  //~vamsI~
//vamq:131007 (GtkPrint)(BUG) x00 terminates string,print by altch //~vamqI~
//vamk:131006 margin not by int but by gdouble for acuracy         //~vamkI~
//vam5:130928 (BUG)scale to fontsize is not to fonth or fontw but to size itself//~vam5I~
//vam0:130911 for distro removed gnome-print,use GTKprint          //~vam0I~
//vaf5:120604 (WXE/XXE) msgbox for uerrexit by inifile version unmatch//~vaf5I~
//va6y:000706 CUPs default printer is not same as gnome default    //~va6yI~
//va6p:000623 (LNX:BUG) ligature ignored for locale file           //~va6pI~
//va3b:100205 (GXE)no ligature for hex edit(HEX mode and EH cmd)   //~va30I~
//va30:100126 combine mode of diacritical marks by A+/(saved to ini)//~va30I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//va1D:091115 gxeprint:2column print for 4byte dbcs if wysiwig is off//~va1DI~
//va1c:091030_merge GB18030 support                                //~va1cI~
//v79Q:081027 (XXE:BUG)0x0a or 0x0d is cause of line is not drawn;replace it by unprintable id//~v79QI~
//v79z:080916 DBCS tbl for C and K of CJK                          //~v79zI~
//v780:080212 syntaxhighlight support (SYN cmd,C+s func key)       //~v780I~
//v76c:070617 (XXE)paste from PRIMARY clipboard by middle button down//~v76cI~
//v75X:070526 (XXE:BUG)assertion fail face!=NULL, gnome_font_find  //~v75XI~
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
//v69s:060531 (XXE:fc5)g_locale_to_utf8 return error if null char contained//~v69sI~
//v69r:060531 (XXE)print debug message by GError                   //~v69rI~
//v68j:060404 (XXE)gtk dmsgdialog okcan button default is cancel,force ok as default like as Windows//~v68jI~
//v68i:060331 (WXEXXE)activate window when dropped                 //~v68iI~
//v686:060323 dnd support by paste(edit:pastev,ins=paste-ins,rep=paste-rep)//~v686I~
//v685:060322 dnd support "file copy into the dir slected" and even in inter-split-screen.//~v685I~
//v66A:051220 dialog to confirm wxe/gxe termination when func-key used//~v66AI~
//v667:050823 (XXE)add printer selection dropdown list(effective only for CUPS)//~v667I~
//vXXE:050611 new for XXE                                          //~vXXEI~
//v560:040324 (WIN)break sleep by esc*2                            //~v560I~
//v55Z:040324 (WXE)ctl multicmd by wxe to display intermediate screen//~v55ZI~
//v55W:040322 (WXE)AT cmd support;"AT(&) interval,count;cmd"       //~v55DI~
//v55D:040307 (WXE)kick wxe.hlp by help cmd                        //~v55DI~
//v55u:040229 (WXE)add open with for dir-list                      //~v55uI~
//v55c:040208 (WXE)distingush L-CTL/R-CTL                          //~v55cI~
//v54y:040118 (WXE)wxp cmd support(send file to wxe for print by wxe)//~v54yI~
//v53t:031004 (WXE:BUG)not freed area exist                        //~v53tI~
//*********************************************************************//~v53tI~
#define INI_FILENAME   "xxeg.ini"                                  //~vXXER~
#define INI_ACRNM   INI_FILENAME "----!!\n"                        //~2907R~
                                                                   //~vXXEI~
#define PRINTGERR(comment,pgerr) {if (pgerr!=NULL) csubprintgerror((char*)__FUNCTION__,__LINE__,comment,pgerr);}//~v705R~
                                                                   //~v69rI~
#define TEXTFILEID     "file://"                                   //~vXXEM~
#define TEXTFILEIDLEN  7                                           //~vXXEM~
#define COPYFILEID     "copy\n"                                    //~vXXER~
#define COPYFILEIDLEN  5                                           //~vXXER~
#define CUTFILEID     "cut\n"                                      //~v686I~
#define CUTFILEIDLEN   4                                           //~v686I~
                                                                   //~2907I~
typedef int (TIMERCALLBACK)(void *Pdata);                          //~vXXEI~
                                                                   //~vXXEI~
#ifdef __cplusplus                                                 //~2818I~
extern  "C"                                                        //~2818I~
{                                                                  //~2818I~
#endif                                                             //~2818I~
                                                                   //~2818I~
typedef struct _GDRECT{gdouble top,bottom,left,right;} GDRECT,*PGDRECT;//~vamuR~
typedef struct _FRECT{float top,bottom,left,right;} FRECT,*PFRECT; //~vamuR~
	int ugetinidata(PWXEINIDATA Ppwxeini);                         //~vXXER~
	int uputinidata(PWXEINIDATA Ppwxeini);                         //~vXXER~
	int csubinit1(HWND Phwnd);                                     //~vXXEM~
	void csubinit3();                                              //~vbz5I~
	int uactivate_menuitem(char *Pobjectname);                     //~vXXER~
	int uclick_toolbarbutton(char *Pobjectname);                   //~vXXEI~
	int uerrmsgbox(char *,char *,... );                            //~vXXEM~
	int uerrmsgboxokcan(char * Pemsg,char * Pjmsg,... );           //~v66AI~
	int umsgboxlocalemsg(char * Pmsg,int Pflag);                   //~vaf5I~
//	int umsgbox(char *Ppmsg);                                      //~v685R~
  	int umsgbox(char *Ppmsg,int Pflag);                            //~v685I~
#define MB_OK          GTK_BUTTONS_OK                              //~v685R~
#define MB_YESNO       GTK_BUTTONS_YES_NO                          //~v686I~
#define MB_OKCANCEL    GTK_BUTTONS_OK_CANCEL                       //~v68jI~
#define MB_YESNOCANCEL 101		//not supported                    //~v686R~
                                                                   //~v685I~
#define IDOK     GTK_RESPONSE_OK                                   //~v685I~
#define IDYES    GTK_RESPONSE_YES                                  //~v685I~
#define IDCLOSE  GTK_RESPONSE_CLOSE                                //~v685I~
#define IDCANCEL GTK_RESPONSE_CANCEL                               //~v685I~
                                                                   //~v685I~
	int umsgbox2(char *Ppmsg,int Pmessagetype,int Pbuttontype);    //~v66AR~
	int umsgbox_modalinparent(GtkWidget *Ppwidget,char *Ppmsg,int Pflag);//~var4I~
	void usettitle(char *Ptitle);                                  //~vXXEI~
	int  ugetcpath(char *Ppath);                                   //~vXXEM~
	int usetcaret(int Pheightrate,int Pcellw,int Pcellh,int Pfonth);//~vXXER~
	int ushowcaret(void);                                          //~vXXEM~
	int uhidecaret(void);                                          //~vXXEM~
	int ugetcaretpos(int *Pprow,int *Ppcol);	//client axis      //~vXXEM~
	int usetcaretpos(int Prow,int Pcol);                           //~vXXEM~
	void usetpalettecolor(int Pmaxpal,int *Pprgb);                 //~vXXEI~
	void usetsynpalettecolor();                                    //~v780I~
	int uinvalidate(int Popt);                                     //~vXXER~
#define UINVO_SYNC  0x01                                           //~vXXEI~
	UINT usettimer(UINT Ptimerid,int Pintvlms,void *Pcallback);    //~vXXER~
    int ukilltimer(UINT Ptimerid);                                 //~vXXEM~
#ifdef UTF8UCS2                                                    //~va20M~
	int uclipboard_settext(int Popt,char *Putf8,int Plen);         //~va20I~
    #define  UCSTO_SRCUTF8        0x01   //data is utf8 encoded    //~va20I~
#else                                                              //~va20I~
	int uclipboard_settext(char *Ptext,int Plen);                  //~vXXEM~
#endif                                                             //~va20I~
//  int uclipboard_gettext(char **Pptext,int *Pplen);              //~v76cR~
    int uclipboard_gettext(int Popt,char **Pptext,int *Pplen,GtkClipboardTextReceivedFunc Ppcbfunc);//~v76cM~
#define UCBGT_PRIMARY 0x01   //GDK_SELECTION_PRIMARY               //~v76cI~
#define UCBGT_SETCB   0x02   //async process,set callback func     //~v76cI~
#define UCBGT_CBDATA  0x04   //process of callback data            //~v76cI~
	int uclipboard_setcopyfile(char *Pptext,int Plen);             //~vXXER~
	void uclipboard_memfree(char *Pmem);                           //~vXXEM~
	void *umemalloc(int Plen);                                     //~vXXEM~
	void umemfree(void *Paddr);                                    //~vXXEM~
	void *wxemalloc(int Plen);                                     //~vXXEM~
	void wxefree(void *Paddr);                                     //~vXXEM~
	int uuridecode(char *Puri,char *Pdecoded,int Pobuffsz);        //~vXXEI~
	char *usetupuri(int Popt,char *Pstrlist);                      //~vXXER~
#define USUO_COPYFILE 0x01		//cut&paste copy file format       //~vXXER~
	void udragbegin(int Ptimeouttseconds);                         //~vXXER~
	void udragend(void);                                           //~vXXEI~
	void udragdestset(void);                                       //~vXXEI~
	void upopupmenu_menuitem_enable(int Pmenuitemid,int Penable);  //~vXXER~
	void upopupmenu_popup(CPoint Ppoint);                          //~vXXER~
//	void ugetfontmetrics(PangoFontDescription *Pfontdesc,int *Ppwidth,int *Ppheight,int *Ppmonospace);//~vXXER~//~vam0R~
PangoFontMetrics *ugetfontmetrics(PangoFontDescription *Pfontdesc,int *Ppwidth,int *Ppheight,int *Ppmonospace);//~vam0I~
//  GnomeFont *uprtcreatefont(char *Pfontname,int *Ppfontw,int *Ppfonth);//~v75XR~
#ifndef NOPRINT                                                    //~vam0R~
	#ifdef GTKPRINT                                                //~vam0I~
	PangoFontMetrics *uprtcreatefontGtkPrint(char *Pfontname,int *Ppfontw,int *Ppfonth);//~vam0I~
	#else    //!GTKPRINT                                           //~vam0I~
    GnomeFont *uprtcreatefont(char *Pfontname,int *Ppfontw,int *Ppfonth,char *Poutfontname);//~v75XI~
	void ugetprtfontmetrics(GnomeFont *Ppgfont,int *Ppwidth,int *Ppheight);//~vXXEI~
	#endif   //!GTKPRINT                                           //~vam0I~
#endif //!NOGOMEPRINT                                              //~vam0M~
	void uprttextout(int Pposx,int Pposy,char *Pdata,int Plen);    //~vXXEM~
	void uprttextout_NoLigature(int Pposx,int Pposy,char *Pdata,int Plen);//~vamsR~
#ifdef UTF8UCS2                                                    //~va20I~
	int uprttextoutw(int Popt,int Pxx,int Pyy,char *Pdata,char *Pdbcs,int Plen);//~va20I~
#endif                                                             //~va20I~
	void uprtlineout(int Pposx0,int Pposy0,int Pposx1,int Pposy1); //~vXXEI~
	void uprtscrtextout(char *Pputf8str,int Pposx,int Pposy,int Plen);//~vXXEI~
	void upreviewsetfontscale(int Phcopysw,int Pcellw,int Pcellh,gdouble Pfscalex,gdouble Pfscaley);//~vXXER~
//	void usetmonospace(PangoLayout *Pplayout,char *Ppdbcs,int Plen,int Pcellw);//~v79zR~
//	void usetmonospace(PangoLayout *Pplayout,char *Ppdata,char *Ppdbcs,int Plen,int Pcellw);//~va1DR~
  	void usetmonospace(int Popt,PangoLayout *Pplayout,char *Ppdata,char *Ppdbcs,int Plen,int Pcellw);//~va1DI~
    #define USMSO_WWSCRPRT  0x01   //space print by dbcs padding   //~va1DI~
#ifdef UTF8UCS2                                                    //~va20I~
    #define USMSO_DDFMT     0x02   //scr data is dd fmt            //~va20I~
    #define USMSO_COMBINEON 0x04   //scr combine mode              //~va30R~
    #define USMSO_COMBINEOF 0x08   //scr no combine mode           //~va30R~
    #define USMSO_COMBINESP 0x10   //widen width for the string if ligature occured//~va30R~
#endif                                                             //~va20I~
//    #define USMSO_SCM       0x20   //may contain Spacing Combining Mark(gliphctr>1)//~vbk4I~//~vbkqR~
    #define USMSO_VHEXDATACPOS 0x20   //data line pos corresponding vhex line csr pos//~vbDsI~
    #define USMSO_UCS4W0NP  0x40   //contains combining:>0x20000 under COMBINE_NP mode//~vbknI~
    #define USMSO_RTL       0x80   //rtl                           //~vbkqI~
    #define USMSO_SBCSCOMBSPLIT 0x0100 //sbcs combining char under split mode//~vbkwR~
#ifndef JJJ                                                        //~vbm8I~
    #define USMSO_NOCOMBINESTR  0x0200 //str dose not contains combine char//~vbm8I~
    #define USMSO_COMBINESTR    0x0400 //str is combineing str( [base+] combining chars )//~vbm8I~
#endif                                                             //~vbm8I~
    #define USMSO_NOTCOMBINABLE 0x0800 //previous char is not combinable//~vbmbI~
    #define USMSO_WITHSCMBASE   0x1000 //put scm string with base  //~vbmeI~
    #define USMSO_SPLITPADDED   0x2000 //split combining with dummy trailer padding//~vbAhI~
	int usetmonospace_ligature(int Popt,PangoLayout *Pplayout,char *Ppdata,char *Ppdbcs,//~va3bI~
//							int Plen/*column width*/,int Pcellw);  //~vb4AR~
  							int Plen/*column width*/,int Pcellw,int *Pstrwidth);//~vb4AR~
	void *uprtgetconfig(void *Ppprtconf,char *Ppprinter);          //~v667I~
    int csubgetdefaultprinter(int Popt);                           //~vamkR~
//	int csubgetcupspagesz(int Popt,RECT *Pprect,char *Pform);      //~vamkR~
//	int csubgetcupspagesz(int Popt,RECT *Pprect,char *Pform,gdouble *Pptblr);//~vamkR~
  	int csubgetcupspagesz(int Popt,RECT *Pprect,char *Pform);      //~vamkI~
	int csubgetcupsform(int Popt,char *Ppdest,char **Ppform,int *Ppformctr,int *Ppentsz);//~va6yI~
    #define CGCPOHW     0x01	//get width and height             //~va6yR~
	GtkSelectionData *uclipboard_getfileselection(void);           //~v686R~
	int uclipboard_getcopyfile(char **Pfilenames,int *Pfilectr,int *Pplen);//~v685R~
	int uclipboard_getcopyfilesub(int Popt,GtkSelectionData *Pseldata,char **Pfilenames,int *Pfilectr,int *Pplen);//~v685R~
    #define UCLIPBOARD_FREESELECTION   0x01   //free selection data//~v686I~
	void usetfocus(void);                                          //~v68iI~
	int upostmsg(UINT Pmsg,ULONG Pwparm, ULONG Plparm);            //~v685M~
	void csubprintgerror(char *Pfile,int Pline,char *Pcmt,GError *Ppgerr);//~v69rR~
//  char *csublocale2utf8(char *Ptext,int Plen,int *Ppreadlen,int *Ppwritelen);//~v69VR~
//  int csublocale2utf8(char *Ptext,int Plen,int *Ppreadlen,char **Putf8,int *Ppwritelen);//~v79zR~
    int csublocale2utf8(int Popt,char *Ptext,int Plen,int *Ppreadlen,char **Putf8,int *Ppwritelen);//~v79zI~
#define CSL2UO_ENCENV    0x01    //source encoding is of environment//~v79zI~
#define CSL2UO_REP0a0d   0x02    //replace 0x0a and 0x0d by unprintable//~v79QI~
#define CSL2UO_LIGATURE  0x04    //ligature mode                   //~va6pI~
#define CSL2UO_NULLALT   0x08    //rep null by '.' for gtkprint    //~vamqI~
	int csublocale2utf8scr(int Popt,char *Ptext,char *Pdbcs,int Plen,//~va1cR~
						int *Ppreadlen,char **Pputf8,              //~va1cR~
						char **Ppdata,char **Ppdbcs,USHORT **Ppoffst,//~va1cR~
						int *Ppwritelen,int *Pplclen,int *Ppslno); //~va1cR~
	int csublinechinit(UCHAR **Plinechmap);                        //~v69XI~
	void usetresizehint(int Pwidth,int Pheight,int Pcol,int Prow); //~v69VI~
	void csubacssetup(int Psetsw,int Pentno,UCHAR *Pacstbl,int *Pplentb,char **Pdispstr);//~v705I~
	int ugconfgetkbdrate(int *Ppdelay,int *Pprate);                //~v76cR~
#ifdef UTF8UCS2                                                    //~va20I~
//int csubtextoutw(int Popt,HDC Phdc,int Px,int Py,char *Pddata,char *Pdbcs,int Plen,int Pcellw);//~va20R~
#define CSTOWO_PRINT        0x01 //write a line at once            //~va20I~
//int csubtextoutw1(int Popt,HDC Phdc,int Pxx,int Pyy,char *Pdata,char *Pdbcs,int Plen);//~va20R~
int csubchkdd(int Popt,char *Pdbcs,int Plen);                      //~va20I~
int csubddcombine(int Popt,char *Pdata,char *Pdbcs,char *Pcombineid,int Plen,int *Ppstarterrctr,int *Ppendcombinectr);//~va30R~
void utracelayout(PangoLayout *Pplayout);                          //~va30R~
void utracelayoutAttr(PangoLayout *Pplayout);                      //~vbA2I~
#ifdef NOTRACE                                                     //~va30I~
	#define UTRACELAYOUT(playout)                                  //~va30I~
	#define UTRACELAYOUT_ATTR(playout)                             //~vbA2I~
#else                                                              //~va30I~
	#define UTRACELAYOUT(playout) utracelayout(playout)            //~va30I~
	#define UTRACELAYOUT_ATTR(playout) utracelayoutAttr(playout)   //~vbA2I~
#endif                                                             //~va30I~
	#define COLOR2STRING(pgdkcolor) csub_GdkColorToString(pgdkcolor)//~vbA2I~
int csublyoutinfo(int Popt,PangoLayout *Pplayout,int *Pretinfo);   //~va30R~
#define CSUBLI_CTR   0                                             //~va30R~
#define CSUBLI_MAX   1      //output fld counter                   //~va30R~
int csubgetcsrposbf(int Popt,char *Pdbcs,int Plen,int Ppos,int *Ppposb,int *Pposc,int *Ppposa);//~va3bR~
#endif                                                             //~va20I~
#ifdef GTKPRINT                                                    //~vam0I~
	/*GtkPrinter*/void *csubgetdefaultprinterGtk();                //~vam0R~
	/*GtkPrinter*/void *csubsrchprinterGtk(char *Pprinternam,char *Pprealname);//~vam0R~
	GList *csubgetpaperlistGtk();                                  //~vam0I~
	const char *csubgetcupspapername(char *Ppaperdisplayname);     //~vam0R~
	void *csubgetpapersizeGtk(int Popt/*free*/,char *Pformtype,gdouble *Ppww,gdouble *Pphh);//~vam0R~
    #define CSGPS_FREE 0x01                                        //~vam0I~
	void csubsetpapersizeGtk(char *Pformtype);                     //~vam0R~
	void csub_setcolorGtk(cairo_t *Ppct);                              //~vam0I~//~vamuI~
#endif   //!GTKPRINT                                               //~vam0I~
void upreviewresetfontscalePango160();                             //~vam5I~
#ifndef OPTGTK3                                                    //~var8R~
#else   //OPTGTK3                                                  //~var8R~
Display *open_display(void);                                       //~var8R~
int close_display(Display *Ppdisplay);                             //~var8R~
#endif                                                             //~var8R~
                                                                   //~var8R~
#if GTK_CHECK_VERSION(2,18,0)                                      //~vbi9I~
	void csub_get_widget_allocation_wh(GtkWidget *Ppwidget,int *Ppww,int *Pphh);//~vbi9R~
#endif                                                             //~vbi9I~
#ifndef OPTGTK3                                                    //~var8R~
#else                                                              //~var8R~
	void csub_get_widget_size(GtkWidget *Ppwidget,int *Ppww,int *Pphh);//~vbBzI~
	void csub_gdk_gc_set_rgb(GdkGC *Ppgc,GdkColor *Ppcolor);       //~var8R~
	GdkGC *csub_gc_new(GtkWidget *Ppwidget);                       //~var8R~
	GdkGC *csub_gc_new_pixmap(GtkWidget *Ppwidget,GdkPixmap * Pppixmap);//~var8R~
	GdkRGBA *csub_gdkColor2RGBA(GdkColor *Ppcolor,int Palpha);     //~var8R~
	void csub_gdk_draw_rectangle_direct(GtkWidget *Ppwidget,GdkColor *Ppcolor,gboolean Pfill,int Pxx,int Pyy,int Pww,int Phh);//~var8R~
	void csub_gdk_draw_line_direct(GdkGC *Ppgc,GdkGC *Ppgcsource,int Px1,int Py1,int Px2,int Py2);//~var8R~
	void csub_draw_pixmap_to_screen(cairo_t *Pcr,GdkPixmap *Ppixmap);//~var8R~
	void csub_pixmap_destroy(GdkPixmap *Pppixmap);                 //~var8R~
    cairo_surface_t *csub_pixmap_new(GtkWidget *Ppwidget,int Pwidth,int Pheight,int Pdepth);//~var8R~
	void csub_gc_destroy_pixmap(GdkGC *Ppgc,GdkPixmap *Pppixmap);  //~var8R~
	void csub_layout_set_textcolor(PangoLayout *Pplayout,GdkColor *Ppfg,GdkColor *Ppbg);//~var8R~
//  void csub_get_widget_allocation_wh(GtkWidget *Ppwidget,int *Ppww,int *Pphh);//~var8R~//~vbi9R~
	GdkColor *csub_gdkRGBA2Color(GdkRGBA *Pprgba,GdkColor *Ppcolor);//~var8R~
    //********                                                     //~var8R~
	#define gdk_draw_lines csub_gdk_draw_lines                     //~var8R~
		void csub_gdk_draw_lines(GdkPixmap *Pppixmap,GdkGC *Ppgc,GdkPoint *Ppoint,int Pctr);//~var8R~
	void csub_gdk_draw_drawable(GtkWidget *Ppwidget,GdkPixmap *Pppixmap,int Pxxsrc,int Pyysrc,int Pxxdest,int Pyydest,int Pww,int Phh);//~var8R~
	#define gdk_draw_rectangle csub_gdk_draw_rectangle             //~var8R~
		void csub_gdk_draw_rectangle(GdkPixmap *Pppixmap,GdkGC *Ppgc,gboolean Pfill,int Pxx,int Pyy,int Pww,int Phh);//~var8R~
	#define gdk_draw_layout  csub_gdk_draw_layout                  //~var8R~
		void csub_gdk_draw_layout(GdkPixmap *Pppixmap,GdkGC *Ppgc,int Pxx,int Pyy,PangoLayout *Pplayout);//~var8R~
	#define gdk_gc_set_foreground csub_gdk_gc_set_foreground       //~var8R~
		void csub_gdk_gc_set_foreground(GdkGC *Ppgc,GdkColor *Ppfg);//~var8R~
	void csub_gdk_gc_set_foregroundA(GdkGC *Ppgc,GdkColor *Ppfg,int PopaqRate);//~vbzbI~
	#define gdk_gc_set_background csub_gdk_gc_set_background       //~var8R~
		void csub_gdk_gc_set_background(GdkGC *Ppgc,GdkColor *Ppfg);//~var8R~
	#define gdk_gc_unref csub_gdk_gc_unref                         //~var8R~
		void csub_gdk_gc_unref(GdkGC *Ppgc);                       //~var8R~
	void csub_gtk_combo_set_popdown_strings(GtkComboBoxText *Ppwidget,GList *Pplist);//~var8R~
	#define gdk_gc_set_line_attributes 	csub_gdk_gc_set_line_attributes//~var8R~
		void csub_gdk_gc_set_line_attributes(GdkGC *,gint,GdkLineStyle,GdkCapStyle,GdkJoinStyle);//~var8R~
	#define gtk_signal_emit_by_name csub_gtk_signal_emit_by_name   //~var8R~
		void csub_gtk_signal_emit_by_name(GtkObject *Ppwidget,const gchar *Psigname,gchar *Pparm);//~var8R~
    #define gtk_widget_get_child_requisition csub_gtk_widget_get_child_requisition//~var8R~
	    void csub_gtk_widget_get_child_requisition(GtkWidget*,GtkRequisition*);//~var8R~
	#define gdk_draw_line csub_gdk_draw_line                       //~var8R~
		void csub_gdk_draw_line(GdkPixmap *Pppixmap,GdkGC *Ppgc,int Px1,int Py1,int Px2,int Py2);//~var8R~
	#define csub_gdk_gc_new_with_values csub_gdk_gc_new_with_values//~var8R~
		GdkGC *csub_gdk_gc_new_with_values(GtkWidget *Ppwidget,GdkGCValues *Ppgcvalues,GdkGCValuesMask Pflag);//~var8R~
	#define gdk_gc_set_function csub_gdk_gc_set_function           //~var8R~
		int csub_gdk_gc_set_function(GdkGC *Ppgc,GdkFunction Pfunc);//~var8R~
	#define gdk_draw_layout_with_colors csub_gdk_draw_layout_with_colors//~var8R~
		void csub_gdk_draw_layout_with_colors(GdkPixmap *Pppixmap,GdkGC *Ppgc,int Pxx,int Pyy,PangoLayout *Pplayout,GdkColor *Ppfg,GdkColor *Ppbg);//~var8R~
	#define gdk_pixmap_get_size  csub_gdk_pixmap_get_size          //~var8R~
		void csub_gdk_pixmap_get_size(GdkPixmap *Pppixmap,int *Ppwidth,int *Ppheight);//~var8R~
	#define gdk_colormap_alloc_color csub_gdk_colormap_alloc_color //~var8R~
		void csub_gdk_colormap_alloc_color(GdkColormap */*GdkVisual*/,GdkColor *,gboolean,gboolean);//~var8R~
	#define gdk_pointer_is_grabbed csub_gdk_pointer_is_grabbed     //~var8R~
		gboolean csub_gdk_pointer_is_grabbed();                    //~var8R~
	#define gdk_pointer_ungrab csub_gdk_pointer_ungrab             //~var8R~
		void csub_gdk_pointer_ungrab(guint32);                     //~var8R~
	#define gdk_keyboard_ungrab csub_gdk_keyboard_ungrab           //~var8R~
		void csub_gdk_keyboard_ungrab(guint32);                    //~var8R~
#endif                                                             //~var8R~
#if defined(OPTGTK3) && !defined(YYY)                              //~vb4AI~
	int uclipboard_getfileselection_Received(int Popt,char **Ppuris,char *Puserdata);//~vb4AI~
	int uclipboard_getfileselection_Clear(int Popt);               //~vb4AI~
#endif                                                             //~vb4AI~
int csub_get_mouse_status(int Popt,int *Ppx,int *Ppy,int *Ppmod);  //~vb7zR~
void usetresizehint2(int Pscrwidth,int Pscrheight,int Pmaxcol,int Pmaxrow);//@@@@test//~varcI~
#ifdef GTKPRINT                                                    //~vbi7I~
int csublistprinter(char **Pplist,int *Ppdefaultindex);            //~vbi7R~
#endif                                                             //~vbi7I~
//void csub_setcombineLayout(int Popt,PangoLayout *Pplayout,char *Ppdddata,char *Ppdddbcs,int Plen);//~vbk4R~//~vbk6R~
#ifdef AAA                                                         //~vbkqI~
void csub_setcombineLayout(int Popt,PangoLayout *Pplayout,char *Ppdddata,char *Ppdddbcs,int Plen,int Pgliphctr,int Pscmctr);//~vbk6R~
#else                                                              //~vbkqI~
void csub_setcombineLayout(int Popt,PangoLayout *Pplayout,char *Ppdddata,char *Ppdddbcs,int Plen);//~vbkqI~
#endif                                                             //~vbkqI~
#define CSUB_GEOMID_WIDTH_MASK     0x00ffffff                      //~vbk4I~
#define CSUB_GEOMID_COMBINE        0x01000000                      //~vbk4I~
//#define CSUB_GEOMID_SCM1           0x02000000   //1st glyph of spacing combining mark//~vbk6R~//~vbkqR~
//#define CSUB_GEOMID_SCM2           0x04000000   //2nd glyph        //~vbk6I~//~vbkqR~
                                                                   //~var8R~
int csub_iswidth0(int Popt,UCHAR *Ppdddata,UCHAR *Ppdddbcs,int Plen,gunichar *Ppucs,int *Ppchsz);//~vbkpI~
//*                                                                //~v7f0I~
int csub_iscombining(int Popt,UCHAR *Ppdddata,UCHAR *Ppdddbcs,int Plen,gunichar *Ppucs,int *Ppchsz);//~vbmfI~
#define CICO_RCNOCOMB 0x01	//chk w0 formt                         //~v7f0R~
//*                                                                //~v7f0I~
int csub_isSpacingCombiningMark(int Popt,gunichar Pucs);           //~vbkpI~
int usetmonospace_SCM(int Popt,PangoLayout *Pplayout,int Pucsctr,int Pcellw);//~vbkqI~
int csubGetLayoutTextLen(int Popt,PangoLayout *Pplayout);          //~vbAhI~
//***********************                                          //~v7f0I~
#ifndef JJJ                                                        //~vbm8I~
//int csub_GetCombineStrTbl(int Popt,char *Ppu8,int Pu8len,char *Ppdddata,char *Ppdddbcs,int Pddlen,int *Ppu8idxtbl,int *Ppddidxtbl); //~vbm8R~//~vbmbR~
int csub_GetCombineStrTbl(int Popt,char *Ppu8,int Pu8len,char *Ppdddata,char *Ppdddbcs,int Pddlen,int *Ppu8idxtbl,int *Ppddidxtbl,char *Ppw0tbl);//~vbmbR~
#define ID_W0NOCOMB   5                                            //~v7f4I~//~v7f0M~
//***********************                                          //~v7f0I~
int usetmonospaceCombineStr(int Popt,PangoLayout *Pplayout,char *Ppdata,char *Ppdbcs,int Plen,int Pcellw);//~vbm8R~
#endif                                                             //~vbm8I~
int csubGetCursorPos(int Popt,ULONG Pucs);                         //~vbz5I~
void csub_set_function(GdkGC Pgc);                                 //~vbzbI~
char *csub_GdkColorToString(GdkColor *Ppcolor);                    //~vbA2I~
void csubDrawLayoutTempColor(GdkPixmap *Pppixmap,GdkGC *Ppgc,int Pxx,int Pyy,PangoLayout *Pplayout,GdkColor *PpfgTemp,GdkColor *Ppfg,GdkColor *Ppbg);//~vbA3R~
#ifdef __cplusplus                                                 //~2818I~
}                                                                  //~2818I~
#endif                                                             //~2818I~
