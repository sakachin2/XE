//*CID://+v6L4R~:                             update#= 2015;       //~v6L4R~
//*************************************************************
//v6L4:170711 dbcs errmsg corrupted,try outputcharcterw for outputw//~v6L4I~
//v6K7:170327 (LNX)compiler warning;wcwidth not defined            //~v6K7I~
//            wchar.h is included from stdio.h and features.h #undef __USE_XOPEN//~v6K7I~
//            so #define _XOPEN_SOURCE before srdio.h              //~v6K7I~
//v6Hk:170120 (BUG by 6G0) u-c1 is displayed as "A"(best fit) when noligatutre mode;apply 6G0 for only dbcs//~v6HkI~
//v6H0:161224 Axe:compile err                                      //~v6H0I~
//v6G1:161201 WCons:try japanese combineing char u3099,u309a by u309b,u309c-->no effect-->No effect//~v6G1R~
//v6G0:161127 WCons:WriteConsoleOutputW/WriteConsoleOutputCharacterW shrink colomn. Use WriteConsoleOutputChar if avail(when successful cv to locale,also for altch)//~v6G0I~
//            some dbcs is half width if used WriteConsoleOutputW/WriteConsoleOutputCharacterW//~v6G0I~
//v6Fc:160904 in addition to v6F3,also DBCS space altch is changable//~v6FcI~
//v6Fb:160913 support locale ligature mode                         //~v6FbI~
//v6Fa:160913 by v6F7, last dbcs was cut when focus was lost       //~v6FaI~
//v6F9:160912 Cols, Top/End of file, Hex line should not be ligatured//~v6F9I~
//v6F7:160905 (W64) TAB disp char on W64                           //~v6F9I~
//                  TT font:tab skip colomn err,errmsg OK          //~v6F9I~
//                  Laster font tab skip colomn OK,errmsg shorten  //~v6F9I~
//                  Column err by TT font is fixed by change OutputCharacterW+OutputAttribute to OutputW//~v6F9I~
//                  So, remove v6F6(back to old altch of TAB display)//~v6F9I~
//v6Es:160815 (W32)even UNCOMB SPLIT mode,regardress Ligature on/off,display combined char after focus off/on(hide by another window)//~v6EsI~
//v6Er:160814 (Bug:XXE)UNCOMB UNPR was ignored                     //~v6EqI~
//v6Eq:160812 lineopt should be cleared by USDFNCELL               //~v6EqI~
//v6Ep:160812 (WXE)errmsg lineopt;strput called intermediate of errmsg string by attr change,it should not Col but msg len//~v6EpI~
//v6Eo:160811 (XXE)v6ei for XXE(specify ligature on/off,combine on/of line by line(used for edit/filename  panel)//~v6EoI~
//v6En:160808 (LNX:BUG)When UNICOMB ITSELF,combine char loose column(line shift to left)//~v6EnI~
//v6Em:160807 (LNX) v6Ei for LNX(specify ligature on/off,combine on/of line by line(used for edit/filename  panel))//~v6EmI~
//v6Ek:160806 (W32)for xe:b4j(OPT UNICOMP UNPR was effective only for file contents(chk at tabdisplay))//~v6EkI~
//v6Ej:160805 v6Ei for wxe(XE:vb4i)specify ligature on/off,combine on/of line by line//~v6EoI~
//v6Ei:160802 (XE:vb4f)specify ligature on/off,combine on/of line by line(used for edit/filename  panel)//~v6EiI~
//v6Eg:160801 (W32:BUG)A+W(copypaste word);for ASCII(white)+combinening(gree) it was not combined//~v6EgI~
//v6Ef:160801 (W32)for dir list csrpos have to be ignored          //~v6EfI~
//v6Ee:160801 (W32)for xe:vb4e;forceligature option for dirlsit    //~v6EeI~
//v6Ec:160731 (LNX)like as W32(v6D6),ligature on on dirlist(Combine mode depends A+:)//~v6EcI~
//v6Ea:160729 set attr 0x03 for ctl char(A+6=0x17 is not appear when doubled)//~v6EaR~
//v6E8:160726 set cmdline to not combine mode                      //~v6E8I~
//v6E7:160726 (BUG)on GB18030 katakana is 4byte but width is 1 not 2//~v6E7I~
//v6E6:160722 (BUG)cmdline last DBCS is displayed only 1st half    //~v6E6R~
//v6Dh:160621 avoid u-ffff is treated as dbcsspace(tabdisplay set ffff/() for dbcsspace)//~v6DhR~
//v6Dg:160621 (BUG:W32)unprintable was not displayed by altch but by "." when tab off.//~v6DgI~
//v6Dd:160616 (BUG by v6BS);DBCS space did not properly displayed when tab display mode.//~v6DdI~
//v6Dc:160613 use u-25a1 for unprintable dbcs                      //~v6DcI~
//v6Da:160611 (LNX)on dirlist Non printable ucs was dispalyed as sbcs ucs//~v6DaI~
//v6D9:160610 (LNX)when combining char exists under combineing mode,//~v6D9I~
//  		  hdr line filename contains black space after each combining char if ligature off,after string if ligature on.//~v6D9I~
//v6D8:160607 (W32)write different attr space when ligature off(it allows display unprintable(printable on chcp GB19030)//~v6D8I~//~v6D9R~
//v6D7:160529 (BUG)display space after each dbcs on dirlist when ligature off//~v6D7I~
//v6D6:160529 (BUG)invalid char display for non-sjis unicode when ligature off//~v6D6I~
//v6C8:160405 on chcp 54936,top menu "LC :" line leaves dbcs.      //~v6C8I~
//            The reason may be mix use of WriteConsoleOutputW and WriteConsoleOutputCharacter api.//~v6C8I~
//            Use WriteConsoleOutputW.                             //~v6C8I~
//v6C7:160405 No Ligature line option one by one                   //~v6C7I~
//v6BZ:160327 roundup width0 boundary to dbcsid=xx00 to avoid incresing testcase by change of UDBCSCHK_ISUCSWIDTH0//~v6BZI~
//v6BY:160326 not fixed width0 ucs boundary                        //~v6BYI~
//v6BX:160320 (W32:Bug)WriteConsoleOutput update target rect by actual written//~v6BXI~
//v6BW:160320 (W32)try write ucs4 at once when ligature on         //~v6BWI~
//v6BU:160320 (W32:BUG)when ligature on ucs4 is not displayed(tgtrect was not updated)//~v6BUI~
//v6BT:160319 (BUG)isalpha is apply to UCHAR only(UTF_COMBINABLE use it for ucs)//~v6BTI~
//v6BS:160319 (W32)invalid column width for locale not combine mode for GB4//~v6BSI~
//v6BJ:160308 (BUG)uerrmsg display more unpredictable char if contains ucs4//~v6BJI~
//v6By:160212 (W32)compiler warning at w7                          //~v6ByI~
//v6Bi:160212 (W32)compiler warning                                //~v6BiI~
//v6Bh:160212 (LNX)compiler warning                                //~v6BhI~
//v6Bg:160212 (LNXCON)if utfwcwidth=2 and wcwidth=1,set cchar sbcs and space//~v6BgI~
//v6uB:140523 (Win:UNICODE)dbcsid:overflow for ucs4 on Windows     //~v6uBI~
//v6t0:140303 (BUG)"ERR uciom_savecell"( uvio range chk err)       //~v6t0I~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6hd:120616 for VC6:/W4 warning(C4057)                           //~v6hdI~
//v6h9:120612 (FC5)avoid uninitialized variable warning by gcc 4.1.1 on FC5(copile optio -Ox is required also)//~v6h9I~
//v6h7:120609 (VC6)avoid c4701 warning by VC6(used uninitialized variable)//~v6h7I~
//v6f3:120417 (Lnx)option to use ICU as local converter            //~v6f3I~
//v6b9:111117 (gcc4.6)Warning:unused-but-set                       //~v6b9I~
//v6a0:110520 Android porting(-DARM)                               //~v6a0I~
//v68p:100723 (BUG:Linux Console)When Liguture ON EBCDIC unprintable sbcs was dispayed as 0xff(alt ch ID)//~v68pI~
//v68e:100702 for safety ;set out ctr(currently not used if not combile/ligature mode//~v68eI~
//            and combine/ligature is for ddfmt only)              //~v68eI~
//v690:100701 m62(LP64:: int:32, long,void*:64) support (__LP64_)  //~v690I~
//v65p:100401 v65n for LNX                                         //~v65pI~
//v65n:100331 default tab/tab padding is shown by 0xff as data value//~v65nI~
//v65m:100329 to print 0x14 glyph(q:0xb6),use another altchar(0xff)//~v65mI~
//v65k:100329 (BUG of v65i)for DBCS space replaced by unicod remains dbcstbl as DBCS1st;so 2nd byte is not adjacent to first//~v65kI~
//v65i:100327 (WinCons)display 0x1b by unicodwe letterlike symbols u21xx because 0x1b make trouble for line clear//~v65iI~
//v65c:100302 (LNX)UCS4 support                                    //~v65cI~
//v65b:100221 (LNXCON)set green to split combining char for ligture mode(f23 dose not set it anymore)//~v65bI~
//v65a:100221 (BUG:WINCON)combining char is not split when ligature+split mode//~v65aI~
//v659:100221 (WINCON)flicker by scroll page when bg is white      //~v659I~
//v658:100220 simple split mode like as windows. single write combining char when split mode.//~v658I~
//            visibility depends to curses. user select split or combine mode.//~v658I~
//            shadow is another option by A+":"                    //~v658I~
//v656:100212 LNX:Cons try to display combining char with left adjasent byte when split mode//~v656I~
//v654:100210 (BUG:WinConsole)screen write err when vsplit(WIDEAPI is on only when WCDBCS at v124,all the case in v125)//~v654I~
//v653:100209 (LNX)try ligature for also console version           //~v653I~
//v652:100208 (WIN)try ligature for also console version           //~v652I~
//v650:100121 print width=0(combine mode)                          //~v652R~
//v640:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~v640I~
//v635:091115 (UTF8:BUG)display width is invalid for GB4 chars width wcidth=-1//~v635I~
//v631:091114 (UTF8:BUG) SS3 displayed on UTF8(wcwidth=1) but not on EUC(wcwidth=2)//~v631I~
//v62X:091107_compchkm                                             //~v62XI~
//v62U:091030_GB18030 merge                                        //~v62UI~
//v62B:091003_(WIN)print width of 0x80->0x9f is 0.5 when cp is iso8859//~v62BI~
//v62m:090915=(LNX console:BUG)dbcs corrupse sometime              //~v62mI~
//v5nt:081107 (LNX)EUC SS3(0x8f:prefix of 2nd level KANJI(2byte)=total 3 byte) consideration. display Unprintable(1column)+DBCS(2column)//~v5ntI~
//v5nj:081029 (LNX)set unprintable for also >=0x80 (Gpdbcstbl even if DBCS 1st)//~v5njI~
//v5n8:080916 (CJK)IME support for CJK other than Japanese         //~v5n8I~
//*************************************************************
#ifdef LNX                                                         //~v6K7I~
	#define _XOPEN_SOURCE       //for wcwidth                      //~v6K7I~
#endif                                                             //~v6K7I~
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//*******************************************************
	#ifdef W32                           //v3.6a                   //~v022M~
		#include <windows.h>	         //v1.3 add                //~v022M~
		#include <wchar.h>	         //v1.3 add                    //~v6D7I~
	#else                                //v3.6a                   //~v022M~
		#include <iconv.h>	         //v1.3 add                    //~v5n8I~
    #ifdef UTF8SUPPH                                               //~v62XM~
//  	#define __USE_XOPEN         //for wcwidth                  //~v62mM~//~v6K7R~
		#include <wchar.h>                                         //~v62mM~
    #endif                                                         //~v62XI~
#define _XOPEN_SOURCE_EXTENDED		//ncurses define               //~v5n8I~
		#include <ucurses.h>	         //v1.3 add                //~v5n8I~
	#endif                                                         //~v022M~
//*******************************************************
#include <ulib.h>                                                  //~v022R~
#include <ualloc.h>
#include <udbcschk.h>
#include <uvio.h>
#include <uviow.h>                                                 //~v5m7I~
#include <uvio2.h>                                                 //~v044I~
#include <uerr.h>                                                  //~v022I~
#include <uedit.h>                                                 //~v022I~
#include <utrace.h>                                                //~v034I~
#include <ucvebc.h>      //ukbd_w95init                            //~v5n8R~
#include <ucvucs.h>      //ukbd_w95init                            //~v5n8I~
#include <ucvext.h>      //ukbd_w95init                            //~v5n8I~
#define  UVIOW_GBLDEF                                              //~v5n8I~
#include <uviom.h>      //ukbd_w95init                             //~v5n8I~
#ifdef LNX                                                         //~v5n8I~
	#define UVIOL_INTERNAL  //define uviol_cell2attr               //~v5n8I~
	#include <uviol.h>                                             //~v5n8I~
#endif                                                             //~v5n8I~
#ifdef UTF8SUPPH                                                   //~v62XI~
#include <utf.h>                                                   //~v62UR~
#endif                                                             //~v62XI~
#ifdef UTF8UCS2                                                    //~v640I~
#include <utf22.h>                                                 //~v640I~
#endif                                                             //~v640I~
                                                                   //~v62UR~
//*******************************************************
#ifndef XSUB                                                       //~v6hhI~
//*******************************************************
#ifdef WCSUPP                                                      //~v5n8I~
  #ifdef W32                                                       //~v5n8I~
    HANDLE Shconout;                                               //~v5n8R~
    static  int     Stoplineoffs;   //console windows topline in buff//~v5n8M~
    static int Ssplitposx;                                         //~v652I~
   #ifndef WXE                                                     //~v6C7I~
    static int Sdbcsspacealt;                                      //~v6G0I~
    #define MAX_NOLIGATURELINE 8                                   //~v6C7I~
	static int Snoligature_linectr;                                //~v6C7R~
#ifdef PPP                                                         //~v6EiI~
    static int Snoligature_line[MAX_NOLIGATURELINE];               //~v6C7I~
    #define NOLIGID_CMDLINE 0x1000     //id of cmdline             //~v6E8R~
	#define UVMNLLCRC_CMDLINE  2	//c,dline                      //~v6E8I~
#endif                                                             //~v6EiI~
   #endif                                                          //~v6C7I~
//  static int Sswligatureword;	//ligature mode eve if ligature option=ON for dirlist//~v6D6I~//~v6EcR~
  #endif                                                           //~v653I~
//  static int Sswligatureword;	//ligature mode eve if ligature option=ON for dirlist//~v6EiR~
    static int Scsrposx,Scsrposy;                                  //~v652I~
    static int Svhexcsrposx,Svhexcsrposy;                          //~v658I~
//#endif                                                           //~v653R~
    static  int     Sscrwidth;   	//scr line size                //~v5n8I~
    static  int     Sscrsize;   	//col*row                      //~v5n8I~
#ifdef LNX                                                         //~v5n8I~
    static iconv_t *Sconverters;                                   //~v5n8I~
	#ifndef XXE                                                    //~v5n8I~
		static chtype  *Spspaceline;                               //~v5n8R~
		static cchar_t *Spspacelinew,*Spwkcchar;                   //~v5n8I~
		static chtype  *Spcellsv;        //for readcell str        //~v5n8I~
		static int     Scursesver;       //maj*100+Min             //~v656I~
        #define VER_COMBINE   507        //good combining support  //~v656I~
		static int     Scombaltch;                                 //~v658I~
	#endif                                                         //~v5n8I~
#else                                                              //~v5n8I~
    static  ULONG Scodepage;                                       //~v5n8R~
	#ifndef WXE                                                    //~v5n8M~
		int uviowrtcellW1(int Popt,PCHAR_INFO Ppchi,int Plen,UCHAR *Ppdbcs,COORD Psrcbox,COORD Psrcpos,SMALL_RECT *Ptgtrect);//~v5n8R~
	#endif                                                         //~v5n8R~
#endif                                                             //~v5n8I~
#ifdef LNX                                                         //~v5n8I~
  #ifdef CURSESW                                                   //~v5n8I~
//  int uvio_mvaddchnstrW(int Popt,int Prow,int Pcol,chtype *Ppcht,UCHAR *Ppdbcs,int Plen);//~v5n8I~//~v6EmR~
    int uvio_mvaddchnstrW(int Popt,int Plineopt,int Prow,int Pcol,chtype *Ppcht,UCHAR *Ppdbcs,int Plen);//~v6EmI~
//  int uviom_cht2cchar(int Popt,chtype *Ppcht,UCHAR *Ppdbcs,int Plen,cchar_t *Ppcchar);//~v653R~//~v6EmR~
//  int uviom_cht2cchar(int Popt,chtype *Ppcht,UCHAR *Ppdbcs,int Plen,cchar_t *Ppcchar,int Prow,int Pcol,int *Ppoutctr);//~v653I~//~v6EmR~
    int uviom_cht2cchar(int Popt,int Plineopt,chtype *Ppcht,UCHAR *Ppdbcs,int Plen,cchar_t *Ppcchar,int Prow,int Pcol,int *Ppoutctr);//~v6EmI~
	#define UVIOMCCRC_ESC          0x01         //Esc found        //~v5n8I~
	#define UVIOMCCRC_NONASCII     0x02         //non ascii found  //~v5n8I~
	#define UVIOMCCRC_COMBINE      0x04         //combine char     //~v650I~
	#define UVIOMCCRC_DDFMT        0x08         //ddfmt line       //~v653I~
	#define UVIOMCCRC_LIGATUREMODE 0x10         //ligature mode    //~v653I~
                                                                   //~v653I~
//  #define UVIOMATTR_PADDING      0x03         //temporary padding flag//~v653R~
    #define UVIOMATTR_DBCS1        0x01         //1:dbcs1st,2:DBCS2ND//~v653R~
    #define UVIOMATTR_DBCS2        0x02         //1:dbcs1st,2:DBCS2ND//~v653I~
    #define UVIOMATTR_DBCS12       0x03         //1:dbcs1st,2:DBCS2ND//~v653I~
    #define UVIOMATTR_BREAK        0x04         //temporary break ligature flag//~v653I~
    #define UVIOMATTR_PADDING      0x08         //temporary padding flag//~v653I~//~v65bM~
	#define UVIOMATTR_SETATTR      0x10         //for the case ligature not combine mode//~v656I~
	#define UVIOMATTR_BASEDBCS     0x20         //base char is dbcs//~v658I~
	#define UVIOMATTR_SHADOW       0x40         //shadow entry     //~v65bI~
                                                                   //~v653I~
                                                                   //~v653I~
//  int uvio_ddcht2cchar_ligature(int Popt,chtype *Ppcht,UCHAR *Ppdbcs,int Plen,cchar_t *Ppcchar,int Prow,int Pcol,int *Ppoutctr);//~v653R~//~v6EmR~
    int uvio_ddcht2cchar_ligature(int Popt,int Plineopt,chtype *Ppcht,UCHAR *Ppdbcs,int Plen,cchar_t *Ppcchar,int Prow,int Pcol,int *Ppoutctr);//~v6EmI~
                                                                   //~v653I~
  #endif //CURSESW                                                 //~v5n8I~
// #define UVIOM_MAXCOMBINE (CCHARW_MAX-1)  //                     //~v653I~
#endif                                                             //~v5n8I~
#ifdef UTF8UCS2                                                    //~v640M~
	int uvio_mdd2u(int Popt,UCHAR *Ppdata,UCHAR *Ppdbcs,int Plen,WUCS *Ppucs,int Poutbuffsz,int *Ppoutucsctr,int *Ppucsdbcsctr,int *Ppucssbcsctr);//~v640M~
    #define UVIOMD2UO_ERRREP   0xff                                //~v640I~
    #define UVIOMD2UO_VIO      0x0100                              //~v640I~
    #define UVIOM2UO_DDSTR     0x02  //source data/dbcs is ucs     //~v65mI~
    #define UVIOM2UO_MBCS      0x04  //source data is locale str   //~v65mI~
  #ifdef LNX                                                       //~v640M~
   #ifndef XXE                                                     //~v640I~
//	int uvio_ddcht2cchar(int Popt,chtype *Ppcht,UCHAR *Ppdbcs,int Plen,cchar_t *Ppcchar,int *Ppoutctr);//~v640R~//~v653R~
//  	int uvio_ddcht2cchar(int Popt,chtype *Ppcht,UCHAR *Ppdbcs,int Plen,cchar_t *Ppcchar,int Prow,int Pcol,int *Ppoutctr);//~v653I~//~v6EmR~
    	int uvio_ddcht2cchar(int Popt,int Plineopt,chtype *Ppcht,UCHAR *Ppdbcs,int Plen,cchar_t *Ppcchar,int Prow,int Pcol,int *Ppoutctr);//~v6EmI~
//	int uviom_setcombine(int Popt,WUCS Pucs,chtype *Ppcht,cchar_t *Ppcchar0,cchar_t *Ppcchar,UCHAR *Ppdbcs,int Plen,int *Ppcombinectr,int *Ppwritectr);//~v653I~//~v6EmR~
  	int uviom_setcombine(int Popt,int Plineopt,WUCS Pucs,chtype *Ppcht,cchar_t *Ppcchar0,cchar_t *Ppcchar,UCHAR *Ppdbcs,int Plen,int *Ppcombinectr,int *Ppwritectr);//~v6EmI~
	#define UVIOMSCO_FORCEBREAK      0x01                          //~v653I~
//	#define UVIOMSCO_SETBREAKIFTOP   0x02                          //~v653I~//~v658R~
//  #define UVIOMSCO_SETATTR         0x04                          //~v656I~//~v658R~
    #define UVIOMSCO_NOSETATTR       0x08                          //~v658I~
   #endif                                                          //~v640I~
  #endif                                                           //~v640M~
#endif                                                             //~v640M~
//*******************************************************          //~v5n8I~
#ifdef W32                                                         //~v65bI~
int uviom_clearlineW(int Popt,PCHAR_INFO Ppchi,USHORT *Ppattr,int Plen,COORD Ptgtpos);//~v65aI~
#define UVIOMCLO_ATTRSTR         0x01                              //~v65aI~
#define UVIOMCLO_ATTRFILL        0x02                              //~v65aI~
//*******************************************************          //~v65mI~
int uvio_m2us(int Popt,UCHAR *Ppmbs,int Plen,UCHAR *Ppdbcs,WUCS *Ppucs,int Poutbuffsz,int *Poutucsctr);//~v65mR~
#define UVM2USO_ALTDBCSSPACE    0x010000 //back to tabdisplay set for dbcs spcae//~v6FbI~
int uviom_appendspace(PCHAR_INFO Ppchi,SMALL_RECT *Ptgtrect,COORD Psrcbox,COORD Psrcpos,int Pbuffctr);//~v6BXI~
int uvioWriteConsoleOutputW_appendspace(int Popt,HANDLE Phandle,PCHAR_INFO Ppchi,COORD Psrcbox,COORD Psrcpos,SMALL_RECT *Ptgtrect,int Pbuffctr);//~v6BXI~
#define UWCOWO_APPENDSPACE   0x01                                  //~v6BXI~
#endif                                                             //~v65bI~
int uviom_escrep(int Popt,WUCS *Pucs,int Pucsctr);                 //~v65iR~
//#ifdef W32                                                         //~v6BYI~//~v6BZR~
//int uvio_getcombinectrUCS(int Popt,WUCS *Ppucs,int Pchwidth,UCHAR *Ppdbcs,int Plen);//~v6BYR~//~v6BZR~
//#endif                                                             //~v6BYI~//~v6BZR~
#ifdef DDD                                                         //~v6D7I~
#ifndef KKK                                                        //~v6D7I~
int uvioWriteConsoleOutputCharacterW1withAttrCHW(HANDLE Phandle,WUCS *Ppucs,int Pucsctr,int Pchwidth,SMALL_RECT *Ptargetrect,COORD Ptgtpos,int *Ppwritelen,USHORT Pattr);//~v6D7I~
#endif                                                             //~v6D7I~
#endif  //DDD                                                      //~v6D7I~
#ifdef W32                                                         //~v6D6I~
#ifndef WXE                                                        //~v6D6I~
#ifdef DDD                                                         //~v6EcI~
int uviowrtcellW1_ligatureWord(int Popt,PWUCS Pdata,int Pucsctr,UCHAR *Pdbcs,USHORT *Pattr,int Plen,SMALL_RECT *Ptgtrect);//~v6D6I~
#endif                                                             //~v6EcI~
#ifdef DDD                                                         //~v6E6I~
int uviowrtcellW1_ligatureLine(int Popt,PWUCS Pdata,int Pucsctr,UCHAR *Pdbcs,USHORT *Pattr,int Plen,SMALL_RECT *Ptgtrect);//~v6D6I~
#endif  //DDD                                                      //~v6E6I~
//int uviowrtcellW1_NonLigatureLine(int Popt,PWUCS Ppucs,int Pucsctr,char *Ppdbcs,USHORT *Ppattr,int Plen,SMALL_RECT *Pptgtrect);//~v6D7I~//~v6E8R~
//int uviowrtcellW1_NonLigatureLine(int Popt,int Pswcmdline,PWUCS Ppucs,int Pucsctr,char *Ppdbcs,USHORT *Ppattr,int Plen,SMALL_RECT *Pptgtrect);//~v6EiR~
int uviowrtcellW1_NonLigatureLine(int Popt,PWUCS Ppucs,int Pucsctr,char *Ppdbcs,USHORT *Ppattr,int Plen,SMALL_RECT *Pptgtrect);//~v6EiI~
int uvioWriteConsoleOutputCharacterW(HANDLE Phandle,PWUCS Ppucs,int Plen,COORD Ptgtpos,int *Ppwritelen);//~v6FaI~
#endif                                                             //~v6D6I~
int uviowrtcellW1_ligaturestr(int Popt,PWUCS Pdata,int Pucsctr,UCHAR *Pdbcs,USHORT *Pattr,int Plen,SMALL_RECT *Ptgtrect);//~v6D6I~
//#define UWCW1LSO_ATTRALL       0x01       //same attr for the string//~v6EiR~
//#define UWCW1LSO_NOCSRPO       0x02       //ignore csrpos        //~v6EiR~
//#define UWCW1LSO_COMBINEATTR   0x04       //combine if combinable and combining char attr is different//~v6EiR~
#define UWCW1LSO_LINEOPTMASK        UVIOO_MASK  //0xffff     //for UVIOO_xxxx//~v6EiI~
#define UWCW1LSO_ATTRALL            0x010000    //same attr for the string//~v6EiI~
#define UWCW1LSO_COMBINEATTR        0x020000    //combine if combinable and combining char attr is different//~v6EiR~
#define UWCW1LSO_LIGATUREALL        0x040000    //combine if combinable and combining char attr is different//~v6EiI~
#ifdef EEE                                                         //~v6E6I~
int uviowrtcellW1_ligatureLineMixed(int Popt,PWUCS Ppucs,int Pucsctr,char *Ppdbcs,USHORT *Ppattr,int Plen,SMALL_RECT *Pptgtrect);//~v6D6I~
#endif //EEE                                                       //~v6E6I~
#endif                                                             //~v6D6I~//~v6D8M~
#ifdef LNX                                                         //~v6D9I~
#ifndef XXE                                                        //~v6D9I~
int uviom_fillattrspace(int Popt,int Prow,int Pcol,attr_t Pattr,int Pctr);//~v6D9I~
attr_t uviom_set_padattr(int Popt,attr_t Pattr);                   //~v6D9R~
int uviom_setunpucs(int Popt,cchar_t *Ppcchar,int Pucs,int Perrrep,int Papiwidth);//~v6DaR~
#define UVMSUUO_OVF  0x01      //ucs4                              //~v6DaI~
#endif                                                             //~v6D9I~
#endif                                                             //~v6D9I~
#define ATTR_SPACEDELM   0x01                                        //~v6E6R~//~v6E8I~
#define ATTR_UCS         0x02                                      //~v6E8I~
#define ATTR_UCS_R       0x20                                      //~v6E8I~
#define ATTR_WHITE       0x07                                      //~v6E8I~
#define ATTR_WHITE_R     0x70                                      //~v6E8I~
                                                                   //~v6EiI~
#ifdef LNX                                                         //~v6EnI~
#ifndef XXE                                                        //~v6H0I~
attr_t uviom_attr_itself(int Popt,chtype Pchtype);                 //~v6EnR~
#endif                                                             //~v6H0I~
#endif                                                             //~v6EnI~
#if defined(W32) && !defined(XXE)                                  //~v6G0I~
int uviowrtcellW1_localefile(int Popt,WUCS *Ppucs,int Pucsctr,UCHAR *Ppdata,UCHAR *Ppdbcs,USHORT *Ppattr,int Plen,COORD Ptgtpos);//~v6G0R~
int uviowrtcellW1_cpu8file_NoLigatureNoCombine(int Poptligature,WUCS *Ppucs,int Pucsctr,UCHAR *Ppdata,UCHAR *Ppdbcs,USHORT *Ppattr,int Plen,SMALL_RECT *Ptgtrect);//~v6G0R~
int uviowrtcellW1_cpu8file_NoLigatureCombine(int Popt,WUCS *Ppucs,int Pucsctr,UCHAR *Ppdata,UCHAR *Ppdbcs,USHORT *Ppattr,int Plen,SMALL_RECT *Ptgtrect);//~v6G0I~
int uviowrtcellW1_cpu8file_Ligature(int Popt,WUCS *Ppucs,int Pucsctr,UCHAR *Ppdata,UCHAR *Ppdbcs,USHORT *Ppattr,int Plen,SMALL_RECT *Ptgtrect);//~v6G0I~
#endif                                                             //~v6G0I~
#define DBCSJ_BA_COMBINE     0x3099                                //~v6G1I~
#define DBCSJ_BA_STANDALONE  0x309b                                //~v6G1I~
#define DBCSJ_PA_COMBINE     0x309a                                //~v6G1I~
#define DBCSJ_PA_STANDALONE  0x309c                                //~v6G1I~
//*********************************************************************//~v5n8I~
//* get scr info                                                   //~v5n8I~
//*   get dbcstbl addr from xe                                     //~v5n8I~
//*   opt is same as Gudbcschk_flagget dbcstbl addr from xe        //~v5n8I~
//*********************************************************************//~v5n8I~
//void uviom_init(int Popt,ULONG Phconout,int Pscrwidth,int Pscrsize,int Ptoplineoffs)//~v5n8R~//~v6hhR~
void uviom_init(int Popt,ULPTR Phconout,int Pscrwidth,int Pscrsize,int Ptoplineoffs)//~v6hhI~
{                                                                  //~v5n8I~
#ifdef LNX                                                         //~v5n8R~
  #ifndef XXE                                                      //~v5n8I~
	int ii,buffsz,buffszw,buffszc;                                 //~v5n8R~
    chtype *pcht;                                                  //~v5n8R~
    cchar_t *pchtw;                                                //~v5n8I~
    const char *pver;                                              //~v656R~
    char *pc;                                                      //~v656I~
    int vmaj,vmin;                                                 //~v656I~
  #endif                                                           //~v5n8I~
#endif                                                             //~v5n8I~
//*************************                                        //~v5n8I~
#ifdef W32                                                         //~v5n8I~
    Shconout=(HANDLE)Phconout;                                     //~v5n8R~
    Stoplineoffs=Ptoplineoffs;                                     //~v5n8M~
#else                                                              //~v5n8I~
  #ifndef XXE                                                      //~v5n8R~
    pver=curses_version();  //"ncurses 5.5.20051010"               //~v656R~
    pc=strchr(pver,' ');                                           //~v656I~
    pc+=strspn(pc," ");                                            //~v656I~
    vmaj=atoi(pc);                                                 //~v656I~
    pc=strchr(pc,'.');                                             //~v656I~
    vmin=atoi(pc+1);                                               //~v656I~
    Scursesver=vmaj*100+vmin;                                      //~v656I~
   	if (Scursesver>=VER_COMBINE)                                   //~v656I~
		Guviomopt2|=UVIOMO2_NONSPACECOMBINE; //non spacing combining diacritical mark supported//~v656I~
//*FC5 combining char occupy 1 culmn                               //~v656M~
//*FC5 single write request ignored by iswprint err                //~v656I~
//*column is kept, so no break required for data csr pos           //~v656M~
    buffsz=Pscrwidth*(CCTSZ);                                      //~v5n8R~
    buffszw=Pscrwidth*CCHSZ*2;                                     //~v5n8R~
    buffszc=Pscrsize*CCTSZ;          //chtype save for readcellstr //~v5n8I~
    Guviombuffu=UALLOCC(1,((UINT)(buffsz+buffszw+buffszc)));			//attr table for save value//~v5n8R~
//	Spspaceline=(chtype *)(ULONG)Guviombuffu;		//ucs line     //~v5n8R~//~v6BhR~
  	Spspaceline=(chtype *)(ULPTR)Guviombuffu;		//ucs line     //~v6BhI~
    for (pcht=Spspaceline,ii=0;ii<Pscrwidth;ii++)                  //~v5n8I~
    	*pcht++=0x20;                                              //~v5n8I~
//  Spspacelinew=(cchar_t *)((ULONG)Spspaceline+buffsz);		//ucs line//~v5n8I~//~v6BhR~
    Spspacelinew=(cchar_t *)((ULPTR)Spspaceline+(ULPTR)buffsz);		//ucs line//~v6BhR~
    for (pchtw=Spspacelinew,ii=0;ii<Pscrwidth;ii++,pchtw++)        //~v5n8I~
    	pchtw->chars[0]=0x20;                                      //~v5n8I~
	Spwkcchar=Spspacelinew+Pscrwidth;                              //~v5n8R~
//  Spcellsv=(chtype *)(ULONG)(Spwkcchar+Pscrwidth);		//chtype save//~v5n8R~//~v6BhR~
    Spcellsv=(chtype *)(ULPTR)(Spwkcchar+Pscrwidth);		//chtype save//~v6BhI~
  #endif                                                           //~v5n8I~
#endif                                                             //~v5n8I~
    Sscrwidth=Pscrwidth;                                           //~v5n8I~
    Sscrsize=Pscrsize;                                             //~v5n8I~
    return;                                                        //~v5n8I~
}//uviom_init                                                      //~v5n8I~
//*********************************************************************//~v62UR~
//set Guviomopt2: dbcs padding char display                        //~v62UR~
//dispchstr:unpdisp+tabdisp                                        //~v62UR~
//*********************************************************************//~v62UR~
//void uviom_setopt2(int Popt,unsigned char *Ppdispch)             //~v652R~
int uviom_setopt2(int Popt,unsigned char *Ppdispch)                //~v652I~
{                                                                  //~v62UR~
    int ch,altch;                                                  //~v65pI~
//*************************                                        //~v62UR~
	if (Popt & UVIOMO2_NOTIFY_DBCSSPACEALT) // 0x0100 //dbcsspacealt was changed//~v6FcI~
    {                                                              //~v6FcI~
    	ch=*Ppdispch;                                              //~v6FcI~
		Guviomoptstr[3]=(UCHAR)ch;		//padd alt ch              //~v6FcR~
    	if (ch==DEFAULT_ALTCH)                                     //~v6FcI~
    	{                                                          //~v6FcI~
    		if ((altch=UTF_GETALTCH_DBCS())>0)                     //~v6FcI~
        		ch=altch;                                          //~v6FcI~
    	}                                                          //~v6FcI~
    	else                                                       //~v6FcI~
    	if (ch<0x20)                                               //~v6FcI~
    	{                                                          //~v6FcI~
    		if ((altch=UTF_GETALTCH_CTL(ch))>0)                    //~v6FcI~
        		ch=altch;                                          //~v6FcI~
    	}                                                          //~v6FcI~
    	Guviomoptstrucs[3]=(WUCS)ch; //pad alt ch                  //~v6FcI~
        UTRACEP("%s:dbcsspacealtch=%02x,ucs=%04x\n",UTT,*Ppdispch,ch);//~v6FcI~
        return 0;                                                  //~v6FcI~
    }                                                              //~v6FcI~
                                                                   //~v6FcI~
//    if (Popt & UVIOMO2_LIGATURE)                                 //~v653R~
//    {                                                            //~v653R~
//        Guviomopt2^=UVIOMO2_LIGATURE;                            //~v653R~
//        return  (Guviomopt2 & UVIOMO2_LIGATURE);                 //~v653R~
//    }                                                            //~v653R~
//  Guviomopt2=Popt;                                               //~v652R~
    Guviomopt2|=Popt;                                              //~v652I~
    if (Popt & UVIOMO2_PADON)                                      //~v62UR~
		Guviomopt2 &= ~UVIOMO2_PADOFF;                             //~v62UR~
    if (Popt & UVIOMO2_PADOFF)                                     //~v62UR~
		Guviomopt2 &= ~UVIOMO2_PADON;                              //~v62UR~
    if (Ppdispch)                                                  //~v62UR~
    	memcpy(Guviomoptstr,Ppdispch,sizeof(Guviomoptstr));        //~v62UR~
    UTRACED("Guviomoptstr",Guviomoptstr,(int)sizeof(Guviomoptstr));//~v6D8I~
//cv to ucs alt                                                    //~v65pI~
//*unprintable                                                     //~v65pI~
	ch=Guviomoptstr[0];		//unp alt ch                           //~v65pI~
    if (ch==DEFAULT_ALTCH)                                         //~v65pI~
    {                                                              //~v65pI~
    	if ((altch=UTF_GETALTCH_SBCS(DEFAULT_UNPATTR))>0)          //~v65pR~
        	ch=altch;                                              //~v65pI~
    }                                                              //~v65pI~
    else                                                           //~v65pI~
    if (ch<0x20)                                                   //~v65pI~
    {                                                              //~v65pI~
    	if ((altch=UTF_GETALTCH_CTL(ch))>0)                        //~v65pI~
        	ch=altch;                                              //~v65pI~
    }                                                              //~v65pI~
//  Guviomoptstrucs[0]=ch;		//unp alt ch                       //~v65pI~//~v6BiR~
    Guviomoptstrucs[0]=(WUCS)ch;		//unp alt ch               //~v6BiI~
//*tab padding/dbcs padding                                        //~v65pI~
	ch=Guviomoptstr[1];		//padd alt ch                          //~v65pI~
    if (ch==DEFAULT_ALTCH)                                         //~v65pI~
    {                                                              //~v65pI~
    	if ((altch=UTF_GETALTCH_SBCS(UDBCSCHK_TABPADCHAR))>0)      //~v65pR~
        	ch=altch;                                              //~v65pI~
    }                                                              //~v65pI~
    else                                                           //~v65pI~
    if (ch<0x20)                                                   //~v65pI~
    {                                                              //~v65pI~
    	if ((altch=UTF_GETALTCH_CTL(ch))>0)                        //~v65pI~
        	ch=altch;                                              //~v65pI~
    }                                                              //~v65pI~
//  Guviomoptstrucs[1]=ch; //pad alt ch                            //~v65pR~//~v6BiR~
    Guviomoptstrucs[1]=(WUCS)ch; //pad alt ch                      //~v6BiI~
//*dbcsspace                                                       //~v65pI~
	ch=Guviomoptstr[3];		//padd alt ch                          //~v65pI~
    if (ch==DEFAULT_ALTCH)                                         //~v65pI~
    {                                                              //~v65pI~
    	if ((altch=UTF_GETALTCH_DBCS())>0)                         //~v65pR~
        	ch=altch;                                              //~v65pI~
    }                                                              //~v65pI~
    else                                                           //~v65pI~
    if (ch<0x20)                                                   //~v65pI~
    {                                                              //~v65pI~
    	if ((altch=UTF_GETALTCH_CTL(ch))>0)                        //~v65pI~
        	ch=altch;                                              //~v65pI~
    }                                                              //~v65pI~
//  Guviomoptstrucs[3]=ch; //pad alt ch                            //~v65pR~//~v6BiR~
    Guviomoptstrucs[3]=(WUCS)ch; //pad alt ch                      //~v6BiI~
//*                                                                //~v65pI~
                                                                   //~v65pI~
	if (Guviomopt2 & UVIOMO2_PADON)                                //~v62UR~
    	Guviomdbcspad=UVIOM_PADDISPCH;                             //~v62UR~
    else                                                           //~v62UR~
    	Guviomdbcspad=' ';                                         //~v62UR~
UTRACEP("uviom_setopt2 Guviomopt=%x,Guviomopt2=%x,dbcspad=%02x\n",Guviomopt,Guviomopt2,Guviomdbcspad);//~v62UR~//~v6D8R~
UTRACED("Guviomoptstrucs",Guviomoptstrucs,(int)sizeof(Guviomoptstrucs));//~v65pI~//~v6D8R~
//  return;                                                        //~v652R~
    return 0;                                                      //~v652I~
}//uviom_setopt2                                                   //~v62UR~
#ifdef UTF8UCS2                                                    //~v653R~
//*********************************************************************//~v652I~
//notify from xe                                                   //~v652I~
//*********************************************************************//~v652I~
int uviom_notify(int Popt,int P1,int P2)                           //~v652I~
{                                                                  //~v652I~
//*************************                                        //~v652I~
	if (Popt & UVIOMNO_CSRPOS)                                     //~v652I~
    {                                                              //~v652I~
//#ifdef W32                                                         //~v6D8I~//~v6EcR~
//        if (P1<0)   //dirlist                                      //~v6D6I~//~v6EeR~
//            Sswligatureword=P2;                                    //~v6D6R~//~v6EeR~
//        else                                                       //~v6D6I~//~v6EeR~
//            Sswligatureword=0;  //start line of dirlist entry      //~v6D6R~//~v6EeR~
//#endif                                                             //~v6D8I~//~v6EcR~
		Scsrposx=P1;                                               //~v652I~
        Scsrposy=P2;                                               //~v652I~
        UTRACEP("%s:csrpos p1=%d,p2=%d\n",UTT,P1,P2);              //~v6EiR~
        return	0;                                                 //~v652I~
    }                                                              //~v652I~
	if (Popt & UVIOMNO_VHEXCSRPOS)                                 //~v658I~
    {                                                              //~v658I~
		Svhexcsrposx=P1;                                           //~v658I~
        Svhexcsrposy=P2;                                           //~v658I~
        return	0;                                                 //~v658I~
    }                                                              //~v658I~
#ifdef W32                                                         //~v653I~
	if (Popt & UVIOMNO_SPLITPOS)                                   //~v652I~
    {                                                              //~v652I~
		Ssplitposx=P1;                                             //~v652I~
        return	0;                                                 //~v652I~
    }                                                              //~v652I~
#ifndef WXEXXE                                                     //~v6EeI~
#ifdef PPP                                                         //~v6EiI~
	if (Popt & UVIOMNO_FORCELIGATURE)                              //~v6EeI~
    {                                                              //~v6EeI~
//p1:0,active,1:inactive                                           //~v6EeI~
//p2:row of after hdrline(orgy+hdrlineno)                          //~v6EeI~
		Sswligatureword=P2;                                        //~v6EeI~
        UTRACEP("%s:csrpos p1=%d,p2=%d,Sswligatureword=%d\n",UTT,P1,P2,Sswligatureword);//~v6EeI~
        return	0;                                                 //~v6EeI~
    }                                                              //~v6EeI~
#endif //PPP                                                       //~v6EiI~
#endif //!WXEXXE                                                   //~v6EeI~
  #ifndef WXE                                                      //~v6C7I~
//  if (Popt & UVIOMNO_NOLIGATURE)                                 //~v6C7I~//~v6E8R~
#ifdef PPP                                                         //~v6EiI~
    if (Popt & (UVIOMNO_NOLIGATURE|UVIOMNO_NOLIGATURE_CMDLINE))    //~v6E8I~
    {                                                              //~v6C7I~
        if (P1==0)                                                 //~v6C7I~
        {                                                          //~v6C7I~
            UTRACEP("%s:reset ctr=%d\n",UTT,Snoligature_linectr);  //~v6C7R~
			Snoligature_linectr=0;                                 //~v6C7I~
			Sswligatureword=0;                                     //~v6EeI~
        }                                                          //~v6C7I~
        else                                                       //~v6C7I~
        {                                                          //~v6C7I~
			if (Snoligature_linectr==MAX_NOLIGATURELINE)           //~v6C7I~
            	return -1;                                         //~v6C7I~
		  if (Popt & UVIOMNO_NOLIGATURE_CMDLINE)                   //~v6E8I~
            Snoligature_line[Snoligature_linectr++]=(Stoplineoffs+P2)|NOLIGID_CMDLINE;//~v6E8R~
          else                                                     //~v6E8I~
            Snoligature_line[Snoligature_linectr++]=Stoplineoffs+P2;//~v6C7I~
            UTRACEP("%s:ctr=%d,line buffpos=%d,row=%d\n",UTT,Snoligature_linectr,Stoplineoffs+P2,P2);//~v6C7I~
        }                                                          //~v6C7I~
        return	0;                                                 //~v6C7I~
    }                                                              //~v6C7I~
#endif //PPP                                                       //~v6EiI~
  #endif //!WXE                                                    //~v6C7I~
#endif                                                             //~v653I~
#ifdef LNX                                                         //~v658I~
//#ifndef XXE                                                      //~v6EqR~
	if (Popt & UVIOMNO_ALTCH)                                      //~v658I~
    {                                                              //~v658I~
    #ifdef XXE                                                     //~v6EqI~
		Gutfcombaltch=(WUCS)P1;                                    //~v6EqI~
    #else                                                          //~v6EqI~
		Scombaltch=P1;                                             //~v658I~
    #endif                                                         //~v6EqI~
        return	0;                                                 //~v658I~
    }                                                              //~v658I~
//#endif                                                           //~v6EqR~
#endif                                                             //~v658I~
#ifdef W32                                                         //~v6EkI~
	if (Popt & UVIOMNO_ALTCH)                                      //~v6EkI~
    {                                                              //~v6EkI~
		Gutfcombaltch=(WUCS)P1;                                    //~v6EkR~
        return	0;                                                 //~v6EkI~
    }                                                              //~v6EkI~
#endif                                                             //~v6EkI~
UTRACEP("uviom_notify opt=x,p1=%x,p2=%x\n",Popt,P1,P2);            //~v652I~
    return 0;                                                      //~v652I~
}//uviom_notify                                                    //~v652I~
#ifdef W32                                                         //~v6C8I~
#ifndef WXE                                                        //~v6C7I~
#ifdef PPP                                                         //~v6EiI~
//**************************************************               //~v6C7I~
//*serch noligature line                                           //~v6C7I~
//**************************************************               //~v6C7I~
int uviom_noligature_linechk(int Pline)                            //~v6C7I~
{                                                                  //~v6C7I~
	int ii,rc=0;                                                   //~v6C7I~
//***********************                                          //~v6C7I~
	for (ii=0;ii<Snoligature_linectr;ii++)                         //~v6C7I~
    {                                                              //~v6E8I~
//  	if (Pline==Snoligature_line[ii])                           //~v6C7I~//~v6E8R~
    	if (Pline==(Snoligature_line[ii] & ~NOLIGID_CMDLINE))    //id of cmdline//~v6E8R~
        {                                                          //~v6C7I~
    	  if (Snoligature_line[ii] & NOLIGID_CMDLINE)              //~v6E8R~
        	rc=UVMNLLCRC_CMDLINE;	//2                            //~v6E8I~
          else                                                     //~v6E8I~
        	rc=1;                                                  //~v6C7I~
            break;                                                 //~v6C7I~
        }                                                          //~v6C7I~
    }                                                              //~v6E8I~
    UTRACEP("%s:parm line=%d,rc=%d\n",UTT,Pline,rc);               //~v6C7I~
    return rc;                                                     //~v6C7I~
}//uviom_noligature_linechk                                        //~v6C7I~
#endif  //PPP                                                      //~v6EiI~
#endif //!WXE                                                      //~v6C7I~
#endif //W32                                                       //~v6C8I~
#endif                                                             //~v6C8R~
//**************************************************               //~v5n8I~
//*uvio_localeinit                                                 //~v5n8I~
//*parm :none                                                      //~v5n8I~
//*rc   :none                                                      //~v5n8I~
//**************************************************               //~v5n8I~
int uvio_wcinit(int Popt,ULONG Pcodepage)                          //~v5n8I~
{                                                                  //~v5n8I~
//***************************************                          //~v5n8I~
    Guviomopt|=Popt;   //or CLEADBCS?                              //~v5n8R~
	if (Pcodepage)                                                 //~v5n8I~
#ifdef LNX                                                         //~v5n8I~
		Sconverters=(iconv_t *)Pcodepage;                          //~v5n8R~
#else                                                              //~v5n8I~
		Scodepage=Pcodepage;                                       //~v5n8R~
#endif                                                             //~v5n8I~
    UTRACEP("uvio wcinit stat=%x\n",Guviomopt);                    //~v5n8R~
    return 0;                                                      //~v5n8I~
}//uvio_wcinit                                                     //~v5n8I~
#ifdef W32                                                         //~v5n8M~
#ifndef WXE                                                        //~v5n8M~
//*******************************************************          //~v656I~
//*write cell using Widechar API                                   //~v656I~
//*rc:TRUE/FALSE                                                   //~v656I~
//*******************************************************          //~v656I~
int uvioWriteConsoleOutputW(HANDLE Phandle,PCHAR_INFO Ppchi,COORD Psrcbox,COORD Psrcpos,SMALL_RECT *Ptgtrect)//~v656I~
{                                                                  //~v656I~
	int rc;                                                        //~v656I~
//***********                                                      //~v656I~
    UTRACEP("%s:srcboX=%d,srcposX=%d,Top=%d,left=%d,bottom=%d,right=%d,len=%d\n",UTT,Psrcbox.X,Psrcpos.X,//~v656R~//~v6BZR~
				Ptgtrect->Top,Ptgtrect->Left,Ptgtrect->Bottom,Ptgtrect->Right,Psrcbox.X);//~v656R~
    UTRACED("input pchi",Ppchi,Psrcbox.X*sizeof(CHAR_INFO));//~v656M~//~v6BZR~
	rc=WriteConsoleOutputW(Phandle,		//rc=TRUE/FALSE            //~v656I~
							Ppchi,				//CHAR_INFO        //~v656I~
                            Psrcbox,                               //~v656I~
                            Psrcpos,                               //~v656I~
                            Ptgtrect);      //target rectangle     //~v656I~
    UTRACEP("WriteConsoleOutputW rc=%d,written Top=%d,left=%d,bottom=%d,right=%d\n",rc,Ptgtrect->Top,Ptgtrect->Left,Ptgtrect->Bottom,Ptgtrect->Right);//~v656I~//~v6BXR~
    if (!rc)                                                       //~v656R~
        uerrapi0("WriteConsoleOutputW",GetLastError());            //~v656I~
    return rc;                                                     //~v656I~
}//uvioWriteConsoleOutputW                                         //~v656I~
//*******************************************************          //~v6BXI~
//*write cell using Widechar API                                   //~v6BXI~
//*rc:TRUE/FALSE                                                   //~v6BXI~
//*******************************************************          //~v6BXI~
int uvioWriteConsoleOutputW_appendspace(int Popt,HANDLE Phandle,PCHAR_INFO Ppchi,COORD Psrcbox,COORD Psrcpos,SMALL_RECT *Ptgtrect,int Pbuffctr)//~v6BXI~
{                                                                  //~v6BXI~
	int rc,appendctr;                                              //~v6BXR~
    SMALL_RECT tgtrect;                                            //~v6BXR~
    COORD srcbox;                                                  //~v6BXI~
//***********                                                      //~v6BXI~
    tgtrect=*Ptgtrect;                                             //~v6BXI~
    UTRACEP("%s:entry Top=%d,left=%d,bottom=%d,right=%d,srcbox=%08x\n",UTT,tgtrect.Top,tgtrect.Left,tgtrect.Bottom,tgtrect.Right,Psrcbox);//~v6BXR~
    UTRACED("input pchi",Ppchi,Psrcbox.X*sizeof(CHAR_INFO));       //~v6BZI~
//#ifdef AAA   //@@@@test                                          //~v6C8R~
    if (Popt & UWCOWO_APPENDSPACE)	//   0x01                      //~v6BXR~
	    appendctr=uviom_appendspace(Ppchi,&tgtrect,Psrcbox,Psrcpos,Pbuffctr);//~v6BXR~
    else                                                           //~v6BXR~
    	appendctr=0;                                               //~v6BXR~
//#else                                                            //~v6C8R~
//    appendctr=uviom_appendspace(Ppchi,&tgtrect,Psrcbox,Psrcpos,Pbuffctr);//~v6C8R~
//    UTRACEP("%s:diff=%d\n",UTT,appendctr);                       //~v6C8R~
//#endif                                                           //~v6C8R~
    srcbox=Psrcbox;                                                //~v6BXI~
    srcbox.X+=(SHORT)appendctr;                                    //~v6BXR~
//#ifdef AAA                                                       //~v6C8R~
//#else       //@@@@test                                           //~v6C8R~
//    appendctr=-(tgtrect.Right-tgtrect.Left+1)+(Psrcbox.X-Psrcpos.X);//~v6C8R~
//    tgtrect.Right+=(USHORT)appendctr;                            //~v6C8R~
//    UTRACEP("%s:diff=%d\n",UTT,appendctr);                       //~v6C8R~
//#endif                                                           //~v6C8R~
	rc=uvioWriteConsoleOutputW(Phandle,Ppchi,srcbox,Psrcpos,&tgtrect);//~v6BXR~
    UTRACEP("%s:opt=%x,rc=%d,written Top=%d,left=%d,bottom=%d,right=%d,diffX=%d\n",UTT,Popt,rc,tgtrect.Top,tgtrect.Left,tgtrect.Bottom,tgtrect.Right,tgtrect.Right-Ptgtrect->Right);//~v6BXR~
    return rc;                                                     //~v6BXI~
}//uvioWriteConsoleOutputW_appendspace                             //~v6BXR~
#ifdef AAA                                                         //~v6C8I~
//*******************************************************          //~v6C8I~
//*write cell using Widechar API                                   //~v6C8I~
//*rc:TRUE/FALSE                                                   //~v6C8I~
//*******************************************************          //~v6C8I~
int uvioWriteConsoleOutputW_dbcschk(int Popt,HANDLE Phandle,PCHAR_INFO Ppchi,COORD Psrcbox,COORD Psrcpos,SMALL_RECT *Ptgtrect,char *Ppdbcs)//~v6C8I~
{                                                                  //~v6C8I~
	CHAR_INFO wkchi[UVIOM_MAXCOL],*pchi,*pwkchi;                   //~v6C8I~
	int ii,rc,appendctr,srclen,tgtlen;                             //~v6C8I~
    SMALL_RECT tgtrect;                                            //~v6C8I~
    COORD srcbox,srcpos;                                           //~v6C8I~
    char *pcd,*pcd0,dbcsid;                                        //~v6C8R~
//***********                                                      //~v6C8I~
    tgtrect=*Ptgtrect;                                             //~v6C8I~
	tgtlen=tgtrect.Right-tgtrect.Left+1;                           //~v6C8I~
	srclen=Psrcbox.X-Psrcpos.X;                                    //~v6C8I~
    pcd0=Ppdbcs+tgtrect.Left;                                      //~v6C8I~
    UTRACEP("%s:entry Top=%d,left=%d,bottom=%d,right=%d,srcbox=%08x\n",UTT,tgtrect.Top,tgtrect.Left,tgtrect.Bottom,tgtrect.Right,Psrcbox);//~v6C8I~
    UTRACED("input pchi",Ppchi,Psrcbox.X*(int)sizeof(CHAR_INFO));  //~v6C8I~
    UTRACED("input dbcs",pcd0,tgtlen);                             //~v6C8I~
	appendctr=tgtlen-srclen;                                       //~v6C8I~
    UTRACEP("%s:diff=%d\n",UTT,appendctr);                         //~v6C8I~
    if (!appendctr)                                                //~v6C8I~
		rc=uvioWriteConsoleOutputW(Phandle,Ppchi,Psrcbox,Psrcpos,&tgtrect);//~v6C8I~
    else                                                           //~v6C8I~
    {                                                              //~v6C8I~
        for (ii=0,pchi=Ppchi+Psrcpos.X,pwkchi=wkchi,pcd=pcd0;ii<srclen;ii++)//~v6C8I~
        {                                                          //~v6C8I~
            *pwkchi++=*pchi++;                                     //~v6C8I~
            dbcsid=*pcd++;                                         //~v6C8I~
            if (UDBCSCHK_DBCS1STU(dbcsid))                         //~v6C8I~
            {                                                      //~v6C8I~
//          	(pwkchi-1)->Attributes|=COMMON_LVB_LEADING_BYTE;   //~v6C8R~
	            *pwkchi=*(pchi-1);                                 //~v6C8R~
//  			pwkchi->Char.UnicodeChar=' ';                      //~v6C8R~
    			pwkchi->Char.UnicodeChar=0;                        //~v6C8I~
//          	pwkchi->Attributes|=COMMON_LVB_TRAILING_BYTE;      //~v6C8R~
            	pwkchi->Attributes=0;                              //~v6C8I~
                pwkchi++;                                          //~v6C8I~
                pcd++;                                             //~v6C8I~
            }                                                      //~v6C8I~
        }                                                          //~v6C8I~
        UTRACED("wkchi",wkchi,(srclen+appendctr)*(int)sizeof(CHAR_INFO));//~v6C8I~
	    srcbox=Psrcbox;                                            //~v6C8I~
    	srcbox.X+=(SHORT)appendctr;                                //~v6C8R~
	    srcpos=Psrcpos;                                            //~v6C8I~
    	srcpos.X=0;                                                //~v6C8I~
		rc=uvioWriteConsoleOutputW(Phandle,wkchi,srcbox,srcpos,&tgtrect);//~v6C8I~
		UTRACEP("%s:srcbox=%08x,srcpos=%08x,rc=%d\n",UTT,srcbox,srcpos,rc);//~v6C8I~
    }                                                              //~v6C8I~
    return rc;                                                     //~v6C8I~
}//uvioWriteConsoleOutputW_appendspace                             //~v6C8I~
#endif //AAA                                                       //~v6C8I~
#ifdef DDD                                                         //~v6D7I~
//*****************************************************************//~v6C8R~
//*write 1/2 ucs using cell                                        //~v6C8R~
//*rc:TRUE/FALSE                                                   //~v6C8R~
//*****************************************************************//~v6C8R~
int uvioWriteConsoleOutputCharacterW1withAttr(HANDLE Phandle,WUCS *Ppucs,int Pucsctr,SMALL_RECT *Ptargetrect,COORD Ptgtpos,int *Ppwritelen,USHORT Pattr)//~v6C8R~
{                                                                  //~v6C8R~
	SMALL_RECT targetrect;                                         //~v6C8R~
    CHAR_INFO wkchi[2];                                            //~v6C8R~
    COORD posinsrcbuff={0,0};                                      //~v6C8R~
    COORD srcbuffsz={1,1};                                         //~v6C8R~
    int rc;                                                        //~v6C8R~
//***********                                                      //~v6C8R~
    UTRACEP("%s:unicode=%04x,attr=%04x,tgtpos=%d,tgtrect.Left=%d,right=%d\n",UTT,*Ppucs,Pattr,Ptgtpos.X,Ptargetrect->Left,Ptargetrect->Right);//~v6C8R~
	wkchi[0].Char.UnicodeChar=Ppucs[0];                            //~v6C8R~
    wkchi[0].Attributes=Pattr;                                     //~v6C8R~
    targetrect=*Ptargetrect;                                       //~v6C8R~
    targetrect.Left  =Ptgtpos.X;                                   //~v6C8R~
    targetrect.Right =Ptgtpos.X;                                   //~v6C8R~
    srcbuffsz.X  =(SHORT)Pucsctr;                                  //~v6C8R~
    srcbuffsz.Y  =1;                                               //~v6C8R~
    if (Pucsctr==2)                                                //~v6C8I~
    {                                                              //~v6C8I~
		wkchi[1].Char.UnicodeChar=Ppucs[1];                        //~v6C8I~
    	wkchi[1].Attributes=Pattr;                                 //~v6C8I~
	    targetrect.Right++;                                        //~v6C8I~
    }                                                              //~v6C8I~
	rc=uvioWriteConsoleOutputW(Phandle,wkchi,srcbuffsz,posinsrcbuff,&targetrect);//~v6C8R~
    if (rc)                                                        //~v6C8I~
    	*Ppwritelen=Pucsctr;                                       //~v6C8I~
    else                                                           //~v6C8I~
    	*Ppwritelen=0;                                             //~v6C8I~
    return rc;                                                     //~v6C7I~
}//uvioWriteConsoleOutputCharacterW1withAttr                       //~v6C7M~
#endif //DDD                                                       //~v6F7R~
#ifndef NNN                                                        //~v6F7R~
//*****************************************************************//~v6C8I~
//*write n ucs using cell                                          //~v6C8I~
//*rc:TRUE/FALSE                                                   //~v6C8I~
//*****************************************************************//~v6C8I~
//int uvioWriteConsoleOutputCharacterW1withAttrN(HANDLE Phandle,WUCS *Ppucs,int Pucsctr,USHORT *Pattr,SMALL_RECT *Ptargetrect,COORD Ptgtpos,int *Ppwritelen)//~v6F9R~
int uvioWriteConsoleOutputCharacterW1withAttrN(int Popt,HANDLE Phandle,WUCS *Ppucs,int Pucsctr,USHORT *Pattr,SMALL_RECT *Ptargetrect,COORD Ptgtpos,int *Ppwritelen)//~v6F9I~
{                                                                  //~v6C8I~
	CHAR_INFO wkchi[UVIOM_MAXCOL],*pchi;                           //~v6C8I~
    WUCS *pucs;                                                    //~v6C8I~
    int ii,rc;                                                     //~v6C8R~
    USHORT *pattr;                                                 //~v6C8I~
    COORD posinsrcbuff={0,0};                                      //~v6C8I~
    COORD srcbuffsz={1,1};                                         //~v6C8I~
	SMALL_RECT targetrect;                                         //~v6C8I~
    int writectr,rc2,swligature=0;                                 //~v6F9I~
//********************                                             //~v6C8I~
    UTRACEP("%s:Popt=%04x\n",UTT,Popt);                            //~v6F9I~
    UTRACED("Ppucs",Ppucs,Pucsctr*2);                              //~v6F9I~
    if (LIGATUREMODE(Popt))                                        //~v6F9R~
  		if (Popt & UVIOO_CSRPOSCHK)       // file data line        //~v6F9I~
        	swligature=1;                                          //~v6F9I~
    if (!swligature)                                               //~v6F9I~
    {                                                              //~v6F9I~
        UTRACEP("%s:non ligature write 1 by 1\n",UTT);             //~v6F9I~
        srcbuffsz.X  =1;                                           //~v6F9I~
        srcbuffsz.Y  =1;                        //rect of parm buff,height//~v6F9I~
        targetrect=*Ptargetrect;                                   //~v6F9I~
        writectr=0;                                                //~v6F9I~
        rc=1;                                                      //~v6F9I~
        for (ii=0,pucs=Ppucs,pchi=wkchi,pattr=Pattr;ii<Pucsctr;ii++)//~v6F9I~
        {                                                          //~v6F9I~
            pchi->Char.UnicodeChar=*pucs++;                        //~v6F9I~
            pchi->Attributes=*pattr++;                             //~v6F9I~
        	targetrect.Right=targetrect.Left;                      //~v6F9I~
        	rc2=uvioWriteConsoleOutputW(Shconout,wkchi,srcbuffsz,posinsrcbuff,&targetrect);//~v6F9I~
            if (rc2)                                               //~v6F9I~
            	writectr++;                                        //~v6F9I~
            else                                                   //~v6F9I~
            {                                                      //~v6F9I~
            	rc=0;                                              //~v6F9I~
            	break;                                             //~v6F9I~
            }                                                      //~v6F9I~
        	targetrect.Left++;                                     //~v6F9I~
        }                                                          //~v6F9I~
        *Ppwritelen=writectr;                                      //~v6F9I~
    	return rc;                                                 //~v6F9I~
    }                                                              //~v6F9I~
    UTRACEP("%s:ligature all at once\n",UTT);                      //~v6F9I~
	for (ii=0,pucs=Ppucs,pchi=wkchi,pattr=Pattr;ii<Pucsctr;ii++,pchi++)//~v6C8I~
    {                                                              //~v6C8I~
		pchi->Char.UnicodeChar=*pucs++;                            //~v6C8I~
    	pchi->Attributes=*pattr++;                                 //~v6C8I~
    }                                                              //~v6C8I~
    srcbuffsz.X  =(SHORT)Pucsctr;  				//rect of parm buff,width//~v6C8R~
    srcbuffsz.Y  =1;       					//rect of parm buff,height//~v6C8R~
    targetrect=*Ptargetrect;                                       //~v6C8R~
	targetrect.Right+=(USHORT)(Pucsctr-1);                         //~v6C8R~
    rc=uvioWriteConsoleOutputW(Shconout,wkchi,srcbuffsz,posinsrcbuff,&targetrect);//~v6C8R~
    if (rc)                                                        //~v6C8I~
    	*Ppwritelen=Pucsctr;                                       //~v6C8I~
    else                                                           //~v6C8I~
    	*Ppwritelen=0;                                             //~v6C8I~
    return rc;                                                     //~v6C8I~
}//uvioWriteConsoleOutputCharacterW1withAttrN                      //~v6C8I~
//*****************************************************************//~v6F7R~
//*write 1 ucs using cell                                          //~v6F7R~
//*rc:TRUE/FALSE                                                   //~v6F7R~
//*****************************************************************//~v6F7R~
int uvioWriteConsoleOutputCharacterW1withAttr1(int Popt,HANDLE Phandle,WUCS *Ppucs,int Pucsctr,COORD Ptgtpos,int *Ppwritelen,SMALL_RECT *Pptargetrect,USHORT *Pattr,int Pchwidth)//~v6F7R~
{                                                                  //~v6F7R~
	CHAR_INFO wkchi[2];                                            //~v6F7R~
    int rc,sw2ucs=0,swdbcs,swascii;                                //~v6FaR~
    COORD posinsrcbuff={0,0};                                      //~v6F7R~
    COORD srcbuffsz={1,1};                                         //~v6F7R~
	SMALL_RECT targetrect;                                         //~v6F7R~
//********************                                             //~v6F7R~
    UTRACEP("%s:Popt=%x,chwidth=%d,ucsctr=%d,tgtpos=%d,ucs=%04x-%04x\n",UTT,Popt,Pchwidth,Pucsctr,Ptgtpos.X,*Ppucs,(Pucsctr>1?*(Ppucs+1):0));//~v6F7R~
    swdbcs=Pchwidth>1;                                             //~v6F7I~
    swascii=Pucsctr==1 && UTF8ISASCII(*Ppucs);                     //~v6FaI~
  if (swdbcs||swascii)                                             //~v6FaR~
  {                                                                //~v6FaI~
    rc=uvioWriteConsoleOutputCharacterW(Shconout,Ppucs,Pucsctr,Ptgtpos,Ppwritelen); //len written//~v6FaI~
    UTRACEP("%s:DBCS OutputCharcterW rc=%d\n",UTT,rc);             //~v6FaI~
  }                                                                //~v6FaI~
  else                                                             //~v6FaI~
  {                                                                //~v6FaI~
	wkchi[0].Char.UnicodeChar=*Ppucs;                              //~v6F7R~
	wkchi[0].Attributes=*Pattr;                                    //~v6F7R~
    if (Pucsctr>1)                                                 //~v6F7R~
    {                                                              //~v6F7R~
        sw2ucs=1;                                                  //~v6F7R~
		wkchi[1].Char.UnicodeChar=*(Ppucs+1);                      //~v6F7R~
		wkchi[1].Attributes=*Pattr;                                //~v6F7R~
    }                                                              //~v6F7R~
    targetrect=*Pptargetrect;                                      //~v6F7R~
	targetrect.Left=Ptgtpos.X;                                     //~v6F7R~
	targetrect.Right=Ptgtpos.X+(SHORT)swdbcs;                      //~v6F7R~
    srcbuffsz.X  =(SHORT)(1+sw2ucs);                               //~v6F7R~
    srcbuffsz.Y  =1;       					//rect of parm buff,height//~v6F7R~
    rc=uvioWriteConsoleOutputW(Shconout,wkchi,srcbuffsz,posinsrcbuff,&targetrect);//~v6F7R~
    UTRACEP("%s:SBCS OutputW rc=%d\n",UTT,rc);                     //~v6FaI~
    if (rc)                                                        //~v6F7R~
    	*Ppwritelen=1+sw2ucs;                                      //~v6F7R~
    else                                                           //~v6F7R~
    	*Ppwritelen=0;                                             //~v6F7R~
  }                                                                //~v6FaI~
    return rc;                                                     //~v6F7R~
}//uvioWriteConsoleOutputCharacterW1withAttr1                      //~v6F7R~
#endif //DDD                                                       //~v6D7I~
//*******************************************************          //~v656I~
//*write wide char                                                 //~v656I~
//*rc:TRUE/FALSE                                                   //~v656I~
//*******************************************************          //~v656I~
int uvioWriteConsoleOutputCharacterW(HANDLE Phandle,PWUCS Ppucs,int Plen,COORD Ptgtpos,int *Ppwritelen)//~v656I~
{                                                                  //~v656I~
	int rc;                                                        //~v656I~
    DWORD dwlen;                                                   //~v6hdI~
//**********************                                           //~v656I~
    rc=WriteConsoleOutputCharacterW(Phandle,                       //~v656I~
                                    	Ppucs,                     //~v656R~
//                                  	Plen,    //charcnt         //~v656I~//~v6hdR~
                                    	(DWORD)Plen,    //charcnt  //~v6hdI~
                                    	Ptgtpos, //pos write into  //~v656I~
//                                  	Ppwritelen);//len written  //~v656R~//~v6hdR~
                                    	&dwlen);//len written      //~v6hdI~
    if (!rc)                                                       //~v656I~
    	uerrapi0("WriteConsoleOutputCharacterW",GetLastError());   //~v656I~
    *Ppwritelen=dwlen;                                             //~v6hdI~
    UTRACEP("%s:rc=%d,outlen=%d,inplen=%d,posx=%d,posy=%d,ucs[0]=%04x\n",UTT,rc,dwlen,Plen,Ptgtpos.X,Ptgtpos.Y,*Ppucs);//~v6BXR~//~v6D7R~
    UTRACED("Ppucs",Ppucs,ctr2szW(Plen));                          //~v6D6R~
    return rc;                                                     //~v656I~
}//uvioWriteConsoleOutputCharacterW                                //~v656I~
//*******************************************************          //~v656I~
//*fill char                                                       //~v656I~
//*rc:TRUE/FALSE                                                   //~v656I~
//*******************************************************          //~v656I~
int uvioFillConsoleOutputCharacter(HANDLE Phandle,UCHAR Pchar,int Plen,COORD Ptgtpos,int *Ppwritelen)//~v656R~
{                                                                  //~v656I~
	int rc;                                                        //~v656I~
    DWORD dwlen;                                                   //~v6hdI~
//**********************                                           //~v656I~
    rc=FillConsoleOutputCharacter(Phandle,//fill by char           //~v656I~
                                    Pchar,        //clear for half width char//~v656I~
//                                  Plen,           //output len   //~v656I~//~v6hdR~
                                    (DWORD)Plen,           //output len//~v6hdI~
                                    Ptgtpos,     //upper left pos in source buff//~v656I~
//                                  Ppwritelen);      //source rectangle//~v656I~//~v6hdR~
                                    &dwlen);//len written          //~v6hdI~
    if (!rc)  //false                                              //~v656I~
        uerrapi0("FillConsoleOutputCharacter",GetLastError());     //~v656I~
    *Ppwritelen=dwlen;                                             //~v6hdI~
    return rc;                                                     //~v656I~
}//uvioFillConsoleOutputCharacter                                  //~v656I~
//*******************************************************          //~v656I~
//*fill char                                                       //~v656I~
//*rc:TRUE/FALSE                                                   //~v656I~
//*******************************************************          //~v656I~
int uvioFillConsoleOutputCharacterW(HANDLE Phandle,WUCS Pchar,int Plen,COORD Ptgtpos,int *Ppwritelen)//~v656R~
{                                                                  //~v656I~
	int rc;                                                        //~v656I~
    DWORD dwlen;                                                   //~v6hdI~
//**********************                                           //~v656I~
    rc=FillConsoleOutputCharacterW(Phandle,//fill by char          //~v656I~
                                    Pchar,        //clear for half width char//~v656I~
//                                  Plen,           //output len   //~v656I~//~v6hdR~
                                    (DWORD)Plen,           //output len//~v6hdI~
                                    Ptgtpos,     //upper left pos in source buff//~v656I~
//                                  Ppwritelen);      //source rectangle//~v656I~//~v6hdR~
                                    &dwlen);      //source rectangle//~v6hdI~
    if (!rc)  //false                                              //~v656R~
        uerrapi0("FillConsoleOutputCharacterW",GetLastError());    //~v656I~
    *Ppwritelen=dwlen;                                             //~v6hdI~
    return rc;                                                     //~v656I~
}//uvioFillConsoleOutputCharacterW                                 //~v656I~
//*******************************************************          //~v5n8I~
//*write cell using Widechar API                                   //~v5n8I~
//*srcbox:Pchi,Ppdbcs size                                         //~v653I~
//*srcpos:start pos in srcbox                                      //~v653I~
//*******************************************************          //~v5n8I~
int uviowrtcellW(int Popt,PCHAR_INFO Ppchi,int Plen,UCHAR *Ppdbcs,COORD Psrcbox,COORD Psrcpos,SMALL_RECT *Pptgtrect)//~v5n8R~
{                                                                  //~v5n8I~
    PCHAR_INFO pchi;                                               //~v5n8R~
    UCHAR *pdbcs;                                                  //~v5n8R~
	SMALL_RECT  tgtrect;                                           //~v5n8I~
    COORD srcpos,srcbox;                                           //~v5n8I~
    int rc=0,lineno,ii,posx,left,len,rlen;                         //~v5n8R~
    int lenl,lenr,lenline,lenrr,lenll;                             //~v653R~
    int opt;                                                       //~v6EiI~
//*****************                                                //~v5n8I~
    UTRACEP("%s:opt=%04x,len=%d,pos=%08x,box=%08x\n",UTT,Popt,Plen,Psrcpos,Psrcbox);//~v6EiR~
    UTRACED("tgtrect",Pptgtrect,sizeof(SMALL_RECT));               //~v5n8M~
    UTRACED("uviowrtcellW inp ucsbuff",Ppchi,Plen*sizeof(CHAR_INFO));//~v5n8I~
    opt=Popt;                                                      //~v6EiI~
    tgtrect=*Pptgtrect;                                            //~v5n8I~
    srcpos=Psrcpos;                                                //~v5n8I~
    srcbox=Psrcbox;                                                //~v5n8I~
    lineno=srcbox.Y;                                               //~v5n8I~
    posx=srcpos.X;                                                 //~v5n8I~
    left=tgtrect.Left;                                             //~v5n8I~
    if (Ssplitposx) //vsplit                                       //~v653I~
    	lenl=Ssplitposx;	//left half width                      //~v653I~
    else                                                           //~v653I~
    	lenl=Sscrwidth;                                            //~v653I~
    lenr=Sscrwidth-lenl;                                           //~v653R~
//  for (ii=0,pchi=Ppchi,pdbcs=Ppdbcs,rlen=Plen;ii<lineno;ii++)    //~v654I~
    pchi=Ppchi+posx;//posinsrc;uviol type=6 set pos but pchi is top of line//~v654I~
    rlen=Plen-posx;                                                //~v654I~
	for (ii=0,pdbcs=Ppdbcs;ii<lineno;ii++)                         //~v654R~
    {                                                              //~v5n8I~
    	len=Sscrwidth-posx;                                        //~v653R~
        len=min(len,rlen);                                         //~v5n8I~
        lenline=len;                                               //~v653M~
//      srcbox.X=len;                                              //~v5n8I~//~v6BiR~
        srcbox.X=(SHORT)len;                                       //~v6BiR~
        srcbox.Y=1;                                                //~v5n8I~
//      srcpos.X=posx;                                             //~v5n8I~//~v6BiR~
        srcpos.X=(SHORT)posx;                                      //~v6BiI~
        srcpos.Y=0;                                                //~v5n8I~
        tgtrect.Bottom=tgtrect.Top;                                //~v5n8I~
//      tgtrect.Left=left;                                         //~v5n8I~//~v6BiR~
        tgtrect.Left=(SHORT)left;                                  //~v6BiI~
//      tgtrect.Right=posx+len-1;                                  //~v653R~
      if (left<lenl)                                               //~v653R~
      {                                                            //~v653M~
      	len=min(lenl-left,lenline);                                //~v653R~
        lenrr=lenline-len;    //remaining lenhgth                  //~v653I~
        lenll=len;   //written length                              //~v653I~
//      tgtrect.Right=tgtrect.Left+len-1;                          //~v653I~//~v6BiR~
        tgtrect.Right=tgtrect.Left+(SHORT)len-1;                   //~v6BiI~
        UTRACEP("%s:buff left len=%d,top=%d,left=%d\n",UTT,len,tgtrect.Top,tgtrect.Left);//~v6EiR~
        UTRACED("wrtcellWvsplit left chi",pchi,len*sizeof(CHAR_INFO));//~v653R~
//  	rc+=uviowrtcellW1(Popt,pchi,len,pdbcs,srcbox,srcpos,&tgtrect);//~v6EiR~
        if (Popt & UVIOO_BUFFWRITE)                                //~v6EiR~
//          opt=uvio_getbufflineopt(UVGBLOO_TGTTOP,tgtrect.Top,0); //~v6EpR~
            opt=uvio_getbufflineopt(UVGBLOO_TGTTOP,tgtrect.Top,0,tgtrect.Left);//~v6EqR~
    	rc+=uviowrtcellW1(opt,pchi,len,pdbcs,srcbox,srcpos,&tgtrect);//~v6EiI~
      }                                                            //~v653I~
      else                                                         //~v653I~
      {                                                            //~v653I~
      	lenrr=lenline;                                             //~v653I~
        lenll=0;                                                   //~v653I~
      }                                                            //~v653I~
        if (lenrr>0)	//vsplit right half                        //~v653R~
        {                                                          //~v653R~
//      	srcbox.X-=lenll;                                       //~v653I~//~v6BiR~
        	srcbox.X-=(SHORT)lenll;                                //~v6BiI~
//          tgtrect.Left+=lenll;                                   //~v653R~//~v6BiR~
            tgtrect.Left+=(SHORT)lenll;                            //~v6BiI~
//          tgtrect.Right=tgtrect.Left+lenrr-1;                    //~v653R~//~v6BiR~
            tgtrect.Right=tgtrect.Left+(SHORT)lenrr-1;             //~v6BiI~
        UTRACEP("%s:buff right len=%d,left=%d,pos=%d\n",UTT,lenrr,tgtrect.Left,lenll);//~v6EiR~
        UTRACED("wrtcellWvsplit right chi",pchi+lenll,lenrr*sizeof(CHAR_INFO));//~v653R~
//  		rc+=uviowrtcellW1(Popt,pchi+lenll,lenrr,pdbcs+lenll,srcbox,srcpos,&tgtrect);//~v6EiR~
	        if (Popt & UVIOO_BUFFWRITE)                            //~v6EiR~
//  	        opt=uvio_getbufflineopt(UVGBLOO_TGTTOP,tgtrect.Top,UVIOO_VSPLIT2ND);//~v6EpR~
    	        opt=uvio_getbufflineopt(UVGBLOO_TGTTOP,tgtrect.Top,UVIOO_VSPLIT2ND,tgtrect.Left);//~v6EqR~
    		rc+=uviowrtcellW1(opt,pchi+lenll,lenrr,pdbcs+lenll,srcbox,srcpos,&tgtrect);//~v6EiI~
        }                                                          //~v653R~
        len=lenline;                                               //~v653I~
        posx=0;           //2nd line                               //~v5n8I~
        left=0;                                                    //~v5n8I~
        tgtrect.Top++;                                             //~v5n8I~
        rlen-=len;                                                 //~v5n8I~
        pdbcs+=len;                                                //~v5n8I~
        pchi+=len;                                                 //~v5n8I~
    }                                                              //~v5n8I~
    return rc;                                                     //~v5n8I~
}//uviowrtcellW                                                    //~v5n8R~
#ifdef AAA                                                         //~v5n8I~
//*******************************************************          //~v5n8I~
//*write cell 1 line using WideChar API                            //~v5n8R~
//*******************************************************          //~v5n8I~
int uviowrtcellW1(int Popt,PCHAR_INFO Ppchi,int Plen,UCHAR *Ppdbcs,COORD Psrcbox,COORD Psrcpos,SMALL_RECT *Ptgtrect)//~v5n8I~
{                                                                  //~v5n8I~
	int rc,rc2,ii,len,opt,chklen,ucsctr=0,ch,shrink;               //~v5n8R~
    PCHAR_INFO pchi,pcho;                                          //~v5n8I~
    CHAR_INFO chspace={' ',0x07/*bg+fc*/};                         //~v5n8I~
    COORD srcbox;                                                  //~v5n8I~
    WUCS  ucs;                                                     //~v5n8R~
    UCHAR mbs[2],*pdbcs;                                           //~v5n8I~
//*****************                                                //~v5n8I~
    UTRACEP("wrtcellW1 len=%d,src pos=%08x,box=%08x\n",Plen,Psrcpos,Psrcbox);//~v5n8R~
    UTRACED("tgtrectW1",Ptgtrect,sizeof(SMALL_RECT));              //~v5n8I~
    UTRACED("uviowrtcellW1 inp char_info",Ppchi,Plen*sizeof(CHAR_INFO));//~v5n8R~
    srcbox=Psrcbox;                                                //~v5n8I~
	for (ii=0,pchi=pcho=Ppchi,pdbcs=Ppdbcs;ii<Plen;ii+=chklen,ucsctr++,pchi+=chklen,pcho++,pdbcs+=chklen)//~v5n8R~
    {                                                              //~v5n8I~
    	ch=pchi->Char.AsciiChar;                                   //~v5n8I~
        if (ch<0x7f)	//ASCII                                    //~v5n8I~
        {                                                          //~v5n8I~
        	chklen=1;                                              //~v5n8I~
        	*pcho=*pchi;                                           //~v5n8I~
        	continue;                                              //~v5n8I~
        }                                                          //~v5n8I~
//#ifdef AAA    no GB4support  UDBCSCHK_DBCS                       //~v62UR~
    	if ((*pdbcs==UDBCSCHK_DBCS1ST)                             //~v5n8I~
        &&  (ii+1<Plen && *(pdbcs+1)==UDBCSCHK_DBCS2ND)            //~v5n8I~
        )                                                          //~v5n8I~
        {                                                          //~v5n8I~
    		mbs[0]=ch;                                             //~v5n8I~
            mbs[1]=(pchi+1)->Char.AsciiChar;                       //~v5n8I~
            len=2;                                                 //~v5n8I~
        	opt=UVIOM2UO_DBCS;                                     //~v5n8I~
        }                                                          //~v5n8I~
        else                                                       //~v5n8I~
        {                                                          //~v5n8I~
        	len=1;                                                 //~v5n8I~
        	opt=0;                                                 //~v5n8I~
        }                                                          //~v5n8I~
		rc2=uvio_m2u(opt,mbs,len,&ucs,&chklen);                    //~v5n8R~
        *pcho=*pchi;                                               //~v5n8I~
        pcho->Char.UnicodeChar=ucs;                                //~v5n8I~
        if (rc2                                                    //~v5n8I~
        &&	opt & UVIOM2UO_DBCS)                                   //~v5n8I~
        {                                                          //~v5n8I~
        	ucsctr++;                                              //~v5n8I~
	        *(pcho+1)=*pcho++;                                     //~v5n8I~
        }                                                          //~v5n8I~
    }                                                              //~v5n8I~
    shrink=(Plen-ucsctr);                                          //~v5n8R~
#ifdef AAA                                                         //~v5n8I~
    srcbox.X-=shrink;                                              //~v5n8I~
#else                                                              //~v5n8I~
    for (ii=0;ii<shrink;ii++)                                      //~v5n8R~
        *pcho++=chspace;                                           //~v5n8R~
#endif                                                             //~v5n8I~
    UTRACEP("uviowrtcellW1 ucsctr=%d,shrink=%d,inplen=%d,out box=%x\n",ucsctr,shrink,Plen,srcbox);//~v656I~
	rc=!uvioWriteConsoleOutputW(Shconout,Ppchi,srcbox,Psrcpos,Ptgtrect);//~v656I~
    return rc;                                                     //~v5n8I~
}//uviowrtcellW1                                                   //~v5n8I~
#else //!AAA                                                       //~v5n8R~
//*******************************************************          //~v659I~
//*line clear before write                                         //~v659I~
//*ret  :rc                                                        //~v659I~
//*******************************************************          //~v659I~
//#ifdef BBB                                                       //~v6C8R~
int uviom_clearlineW(int Popt,PCHAR_INFO Ppchi,USHORT *Ppattr,int Plen,COORD Ptgtpos)//~v659R~
{                                                                  //~v659I~
//  CHAR_INFO wkchi[UVIOM_MAXCOL];                                 //~v659R~
    WUCS wucsspace=' ';                                            //~v659I~
    int rc=0,rc2,writelen;                                         //~v659I~
    DWORD dwlen;                                                   //~v6hdI~
//********************************                                 //~v659I~
	if (Popt & UVIOMCLO_ATTRSTR)                                   //~v659I~
    {                                                              //~v659I~
//  	rc2=WriteConsoleOutputAttribute(Shconout,Ppattr,Plen,Ptgtpos,&writelen)==0;			//writelen//~v659I~//~v6hdR~
    	rc2=WriteConsoleOutputAttribute(Shconout,Ppattr,(DWORD)Plen,Ptgtpos,&dwlen)==0;			//writelen//~v6hdI~
        writelen=(int)dwlen;                                       //~v6hdI~
        if (rc2)                                                   //~v659I~
        {                                                          //~v659I~
            uerrapi0("clearline WriteConsoleOutputAttribute",GetLastError());//~v659I~
            rc++;                                                  //~v659I~
        }                                                          //~v659I~
        UTRACEP("clearline writeattr rc2=%d,row=%d,col=%d,Plen=%d,writelen=%d\n",rc2,Ptgtpos.Y,Ptgtpos.X,Plen,writelen);//~v659R~
        UTRACED("clearline writeattr",Ppattr,Plen*sizeof(USHORT)); //~v65aR~
    }                                                              //~v659I~
	if (Popt & UVIOMCLO_ATTRFILL)                                  //~v65aI~
    {                                                              //~v65aI~
//      rc2=FillConsoleOutputAttribute(Shconout,*Ppattr,Plen,Ptgtpos,&writelen)==0;     //clear also attr(else remains previous attr after this times 0x1b)//~v65aR~//~v6hdR~
        rc2=FillConsoleOutputAttribute(Shconout,*Ppattr,(DWORD)Plen,Ptgtpos,&dwlen)==0;     //clear also attr(else remains previous attr after this times 0x1b)//~v6hdI~
        writelen=(int)dwlen;                                       //~v6hdI~
        if (rc2)                                                   //~v65aR~
        {                                                          //~v65aI~
            uerrapi0("clear line FillConsoleOutputAttribute",GetLastError());//~v65aI~
            rc++;                                                  //~v65aI~
        }                                                          //~v65aI~
        UTRACEP("clearline fillattr rc=%d,attr=%x,Plen=%d,writelen=%d\n",rc2,*Ppattr,Plen,writelen);//~v65aR~
    }                                                              //~v65aI~
	rc2=uvioFillConsoleOutputCharacterW(Shconout,wucsspace,Plen,Ptgtpos,&writelen)==0;//~v659I~
    if (rc2)                                                       //~v659I~
        rc++;                                                      //~v659I~
    UTRACEP("clearline fillspace rc2=%d,row=%d,col=%d,Plen=%d,writelen=%d\n",rc2,Ptgtpos.Y,Ptgtpos.X,Plen,writelen);//~v659R~
    return rc;                                                     //~v659I~
}//uviom_clearlineW                                                //~v659I~
//#else   //!BBB                                                   //~v6C8R~
//int uviom_clearlineW(int Popt,PCHAR_INFO Ppchi,USHORT *Ppattr,int Plen,COORD Ptgtpos)//~v6C8R~
//{                                                                //~v6C8R~
////  CHAR_INFO wkchi[UVIOM_MAXCOL];                               //~v6C8R~
//    WUCS wucsspace=' ';                                          //~v6C8R~
//    int rc=0,rc2,writelen;                                       //~v6C8R~
//    DWORD dwlen;                                                 //~v6C8R~
////********************************                               //~v6C8R~
//    rc2=uvioFillConsoleOutputCharacterW(Shconout,wucsspace,Plen,Ptgtpos,&writelen)==0;//~v6C8R~
//    if (rc2)                                                     //~v6C8R~
//        rc++;                                                    //~v6C8R~
//    UTRACEP("%s:fillspace rc2=%d,row=%d,col=%d,Plen=%d,writelen=%d\n",UTT,rc2,Ptgtpos.Y,Ptgtpos.X,Plen,writelen);//~v6C8R~
//    if (Popt & UVIOMCLO_ATTRSTR)                                 //~v6C8R~
//    {                                                            //~v6C8R~
//        rc2=WriteConsoleOutputAttribute(Shconout,Ppattr,(DWORD)Plen,Ptgtpos,&dwlen)==0;         //writelen//~v6C8R~
//        writelen=(int)dwlen;                                     //~v6C8R~
//        if (rc2)                                                 //~v6C8R~
//        {                                                        //~v6C8R~
//            uerrapi0("clearline WriteConsoleOutputAttribute",GetLastError());//~v6C8R~
//            rc++;                                                //~v6C8R~
//        }                                                        //~v6C8R~
//        UTRACEP("%s writeattr rc2=%d,row=%d,col=%d,Plen=%d,writelen=%d\n",UTT,rc2,Ptgtpos.Y,Ptgtpos.X,Plen,writelen);//~v6C8R~
//        UTRACED("writeattr",Ppattr,Plen*sizeof(USHORT));         //~v6C8R~
//    }                                                            //~v6C8R~
//    if (Popt & UVIOMCLO_ATTRFILL)                                //~v6C8R~
//    {                                                            //~v6C8R~
//        rc2=FillConsoleOutputAttribute(Shconout,*Ppattr,(DWORD)Plen,Ptgtpos,&dwlen)==0;     //clear also attr(else remains previous attr after this times 0x1b)//~v6C8R~
//        writelen=(int)dwlen;                                     //~v6C8R~
//        if (rc2)                                                 //~v6C8R~
//        {                                                        //~v6C8R~
//            uerrapi0("clear line FillConsoleOutputAttribute",GetLastError());//~v6C8R~
//            rc++;                                                //~v6C8R~
//        }                                                        //~v6C8R~
//        UTRACEP("%s:fillattr rc=%d,attr=%x,Plen=%d,writelen=%d\n",UTT,rc2,*Ppattr,Plen,writelen);//~v6C8R~
//    }                                                            //~v6C8R~
//    return rc;                                                   //~v6C8R~
//}//uviom_clearlineW                                              //~v6C8R~
//#endif  //!BBB                                                   //~v6C8R~
//*******************************************************          //~v6BXI~
int uviom_appendspace(PCHAR_INFO Ppchi,SMALL_RECT *Ptgtrect,COORD Psrcbox,COORD Psrcpos,int Pbuffctr)//~v6BXI~
{                                                                  //~v6BXI~
	int tgtctr,srcctr,resctr,spacectr,ii;                          //~v6BXR~
	PCHAR_INFO pchi;                                               //~v6BXI~
    CHAR_INFO chispace={{L' '},0/*attr*/};                         //~v6BXR~
//****************************                                     //~v6BXI~
	tgtctr=Ptgtrect->Right-Ptgtrect->Left+1;                       //~v6BXI~
	srcctr=Psrcbox.X-Psrcpos.X;                                    //~v6BXR~
    spacectr=tgtctr-srcctr;                                        //~v6BXI~
    resctr=Pbuffctr-Psrcpos.X;                                     //~v6BXI~
    if (spacectr<=0||resctr<=0)                                    //~v6BXI~
    	return 0;                                                  //~v6BXI~
    if (spacectr>resctr)                                           //~v6BXI~
    	spacectr=resctr;                                           //~v6BXI~
    UTRACEP("%s:srcboX=%d,srcposX=%d,Top=%d,left=%d,bottom=%d,right=%d,len=%d\n",UTT,Psrcbox.X,Psrcpos.X,//~v6BXI~
				Ptgtrect->Top,Ptgtrect->Left,Ptgtrect->Bottom,Ptgtrect->Right,Psrcbox.X);//~v6BXI~
    UTRACEP("%s:spacectr=%d\n",UTT,spacectr);                      //~v6BXR~
    chispace.Attributes=(Ppchi+Psrcbox.X-1)->Attributes;           //~v6BXI~
    for (ii=0,pchi=Ppchi+Psrcbox.X;ii<spacectr;ii++)               //~v6BXR~
    	*pchi++=chispace;                                          //~v6BXR~
    UTRACED("appended",Ppchi+Psrcpos.X,(srcctr+spacectr)*(int)sizeof(CHAR_INFO));//~v6BXI~
    return spacectr;                                               //~v6BXI~
}//uviom_appendspace                                               //~v6BXI~
//*******************************************************          //~v652I~
//*draw utf8 file string with ligature option                      //~v652R~
//*ret  :rc                                                        //~v652I~
//*******************************************************          //~v652I~
int uviowrtcellW1_ligaturestr(int Popt,PWUCS Pdata,int Pucsctr,UCHAR *Pdbcs,USHORT *Pattr,int Plen,SMALL_RECT *Ptgtrect)//~v652R~
{                                                                  //~v652I~
    char *pdbcs;                                                   //~v652I~
	int rc=0,rc2,ii,dbcsid,ligucsctr=0,dbcssw,dbcssz,chtype,chtypeo,swcombinable=0;//~v656R~
    int ligstrlen=0,col;                                           //~v656R~
    int row;                                                       //~v65aI~
	COORD srcbufsz={0,1/*row count*/},posinsrcbuff={0,0};          //~v656R~
	COORD tgtpos;                                                  //~v65aI~
    WUCS ucs,*pucs;                                                //~v652I~
	SMALL_RECT tgtrect;                                            //~v652I~
    USHORT *pattr;                                                 //~v652R~
    CHAR_INFO wkchi[2][UVIOM_MAXCOL],*pwkchi;                      //~v652R~
#ifdef UTF8UTF16                                                   //~v6uBI~
	int swovf;                                                     //~v6uBI~
#endif                                                             //~v6uBI~
    USHORT attrall;                                                //~v6D6I~
#ifndef SSS                                                        //~v6DhI~
    int swdbcsspaceutf8;                                           //~v6DhI~
#endif                                                             //~v6DhI~
	WUCS altdbcsspace;                                             //~v6FbI~
//**********************                                           //~v652I~
	if (Popt & UWCW1LSO_ATTRALL)      //same attr for the string   //~v6D6I~
    	attrall=*Pattr;                                            //~v6D6I~
    else                                                           //~v6D6I~
    	attrall=0;                                                 //~v6D6I~
    UTRACEP("%s:attrall=%x,ucsctr=%d,Plen=%d\n",UTT,attrall,Pucsctr,Plen);                        //~v6D6I~//~v6E6R~
	tgtrect=*Ptgtrect;                                             //~v656I~
    col=Ptgtrect->Left;                                            //~v656R~
    row=Ptgtrect->Top;                                             //~v65aI~
//  tgtpos.X=col;                                                  //~v65aI~//~v6BiR~
    tgtpos.X=(SHORT)col;                                           //~v6BiI~
//  tgtpos.Y=row;                                                  //~v65aI~//~v6BiR~
    tgtpos.Y=(SHORT)row;                                           //~v6BiI~
    uviom_clearlineW(UVIOMCLO_ATTRFILL,0/*data*/,Pattr,Plen,tgtpos);//~v65aR~
    UTRACEP("%s,col=%d,tgt.Right=%d,ucsctr=%d,dbcstblen=%d\n",UTT,col,Ptgtrect->Right,Pucsctr,Plen);//~v656R~//~v6D6R~
UTRACED("Pdata",Pdata,Pucsctr*2);                                  //~v6uBI~
UTRACED("Pdbcs",Pdbcs,Plen);                                       //~v6uBI~
    chtypeo=-2;                                                    //~v652I~
    altdbcsspace=(WUCS)(Guviomoptstr[3]<<8|Guviomoptstr[3]);	   //~v6FbI~
    for (ii=0,pucs=Pdata,pdbcs=Pdbcs,pattr=Pattr;                  //~v656R~
			ii<Pucsctr;                                            //~v656I~
			ii++,pucs++,pdbcs+=dbcssz,pattr+=dbcssz,col+=dbcssz)   //~v656I~
    {                                                              //~v652I~
        ucs=*pucs;                                                 //~v652I~
        dbcsid=*pdbcs;                                             //~v652I~
	    dbcssw=UDBCSCHK_DBCS1STL(dbcsid);	//locale dbcsid:"1"    //~v6E6I~
      if (!dbcssw)                                                 //~v6E6I~
        dbcssw=UDBCSCHK_DBCS1STUCS2NW(dbcsid);                     //~v652R~
#ifndef SSS                                                        //~v6DhI~
    	swdbcsspaceutf8=0;                                         //~v6DhI~
//    	if (ucs==DBCSSPACE_ALT2   //ffff                           //~v6FbR~
//  	&&  dbcsid==UDBCSCHK_DBCS1STUCS)	//tabdisplay set ffff/() for dbcsspace//~v6FbM~
    	if ( (   dbcsid==UDBCSCHK_DBCS1STUCS	//utf8 file, tabdisplay set ffff/() for dbcsspace//~v6FbI~
      	      && ucs==DBCSSPACE_ALT2)   //ffff                     //~v6FbI~
    	||   (   dbcsid==UDBCSCHK_DBCS1ST	//local file,tabdisplay set ffff of ascii altch//~v6FbI~
      	      && (ucs==DBCSSPACE_ALT2||ucs==altdbcsspace))   //ffff//~v6FbI~
        )                                                          //~v6FbI~
        {                                                          //~v6DhI~
    		swdbcsspaceutf8=1;                                     //~v6DhI~
          if (ucs==DBCSSPACE_ALT2)                                 //~v6FbI~
          	ucs=(WUCS)UTF_GETALTCH_DBCS();                         //~v6DhI~
          else                                                     //~v6FbI~
          	ucs=(WUCS)(altdbcsspace>>8);                           //~v6FbI~
			UTRACEP("%s:dbcsspaceutf8 ucs=%04x,->%04x,ucsctr=%d,dbcsid=%02x\n",UTT,*pucs,ucs,ii,dbcsid);//~v6DhI~
	    }                                                          //~v6DhI~
#endif                                                             //~v6DhI~
#ifdef UTF8UTF16                                                   //~v6uBI~
		swovf=0;                                                   //~v6uBI~
		if (UDBCSCHK_ISUCSOVF1ST(dbcsid)) //ucs4                   //~v6uBI~
        {                                                          //~v6uBI~
        	swovf=1;                                               //~v6uBI~
          	dbcssw=1;                                              //~v6uBI~
        }                                                          //~v6uBI~
#endif                                                             //~v6uBI~
        UTRACEP("%s: combined ucs ii=%d,col=%d,dbcsid=%02x,dbcssw=%d,ucs=%04x,ligucsctr=%d\n",UTT,ii,col,dbcsid,dbcssw,*pucs,ligucsctr);//~v656R~
        dbcssz=1+dbcssw;                                           //~v652I~
//        if (UTF_COMBINABLE(ucs))                                 //~v65aR~
//        {                                                        //~v65aR~
//            chtype=1;       //LTR or RTL                         //~v65aR~
//            swcombinable=1;                                      //~v65aR~
//        }                                                        //~v65aR~
//        else                                                     //~v65aR~
//        {                                                        //~v65aR~
#ifdef AAA                                                         //~v6BWR~
#ifdef UTF8UTF16                                                   //~v6uBI~
		  if (swovf)                                               //~v6uBI~
          	chtype=-1;					//single write             //~v6uBI~
          else                                                     //~v6uBI~
#endif                                                             //~v6uBI~
#endif //AAA                                                       //~v6BWR~
#ifndef SSS                                                        //~v6DhI~
    	  if (swdbcsspaceutf8)                                     //~v6DhI~
          {                                                        //~v6DhI~
          	chtype=-1;					//single write             //~v6DhI~
          }                                                        //~v6DhI~
          else                                                     //~v6DhI~
#endif                                                             //~v6DhI~
          {                                                        //~v6uBI~
//#ifdef WWW                                                         //~v6BYI~//~v6BZR~
        	if (UDBCSCHK_ISUCSWIDTH0(dbcsid))	//combine char     //~v652I~
//#else                                                              //~v6BYI~//~v6BZR~
//            if (UTF_ISUCSWIDTH0(ucs))   //combine char             //~v6BYI~//~v6BZR~
//#endif                                                             //~v6BYI~//~v6BZR~
            {                                                      //~v652I~
//      		if (swcombinable && UTF_COMBINEMODE())             //~v6EiR~
        		if (swcombinable && COMBINEMODE(Popt))             //~v6EiI~
                {                                                  //~v652I~
            		chtype=1;					//add to LTR/RTL group//~v652I~
                }                                                  //~v652I~
            	else                                               //~v652I~
                {                                                  //~v6EkI~
                  if (UTF_COMBINEMODE_NP() && Gutfcombaltch)       //~v6EkR~
                  {                                                //~v6EkI~
                  	UTRACEP("%s:write Gutfcombaltch=%04x\n",UTT,Gutfcombaltch);//~v6EkR~
                    *pucs=ucs=(WUCS)Gutfcombaltch;                 //~v6EkR~
                    chtype=1;                                      //~v6EkI~
                  }                                                //~v6EkI~
                  else                                             //~v6EkI~
            		chtype=-1;					//single write     //~v652I~
                }                                                  //~v6EkI~
            }                                                      //~v652I~
        	else                                                   //~v652I~
            {                                                      //~v652I~
        		chtype=1;						//mix all          //~v652I~
              if (UTF_COMBINABLE(ucs))                             //~v65aI~
	            swcombinable=1;                                    //~v65aI~
	          else                                                 //~v65aI~
				swcombinable=0;                                    //~v652I~
            }                                                      //~v652I~
          }                                                        //~v6uBI~
//        }                                                        //~v65aR~
UTRACEP("wrtcellW1_ligature chtype=%d,old=%d,ucs=%04x,dbcssw=%d,combinable=%d\n",chtype,chtypeo,ucs,dbcssw,swcombinable);//~v65aR~
        if (chtype<0||(ligucsctr && chtype!=chtypeo))	//breaker  //~v652R~
        {                                                          //~v652I~
            if (ligucsctr)                                         //~v652I~
            {                                                      //~v652I~
#ifdef AAA                                                         //~v656I~
                tgtrect.Right =col-1; //column width               //~v656R~
                srcbufsz.X  =ligstrlen;    //rect of parm buff may be cut by tgtrect//~v656R~
#else                                                              //~v656I~
//              tgtrect.Right =col-1; //column width               //~v656R~//~v6BiR~
                tgtrect.Right =(SHORT)col-1; //column width        //~v6BiI~
//              srcbufsz.X  =ligucsctr;    //rect of parm buff may be cut by tgtrect//~v656I~//~v6BiR~
                srcbufsz.X  =(SHORT)ligucsctr;    //rect of parm buff may be cut by tgtrect//~v6BiI~
#endif                                                             //~v656I~
            	pwkchi=wkchi[chtypeo];                             //~v652I~
UTRACEP("ligature breaked col=%d,ucsctr=%d,chtype=%d\n",col,ligucsctr,chtypeo);//~v656R~
//          	rc2=uvioWriteConsoleOutputW(Shconout,pwkchi,srcbufsz,posinsrcbuff,&tgtrect);//len written//~v656I~//~v6BXR~
            	rc2=uvioWriteConsoleOutputW_appendspace(0,Shconout,pwkchi,srcbufsz,posinsrcbuff,&tgtrect,UVIOM_MAXCOL);//len written//~v6BXR~
        UTRACED("pchi ligucsctr>0",pwkchi,ligucsctr*sizeof(CHAR_INFO));//~v6uBI~//~v6BTR~
        UTRACED("tgtrect",&tgtrect,(int)sizeof(tgtrect));          //~v6BTR~
//              tgtrect.Left=col; //column width                   //~v656I~//~v6BiR~
                tgtrect.Left=(SHORT)col; //column width            //~v6BiI~
            }                                                      //~v652I~
            if (chtype<0)                                          //~v652I~
            {                                                      //~v652I~
#ifndef SSS                                                        //~v6DhI~
    	  	  if (swdbcsspaceutf8)                                 //~v6DhI~
          	  {                                                    //~v6DhI~
                tgtrect.Right =(SHORT)col+1; //1column for combine char//~v6DhI~
                srcbufsz.X  =2;    //rect of parm buff,width       //~v6DhI~
            	pwkchi=wkchi[0];    //chtypeo is -2 if top         //~v6DhI~
				pwkchi->Char.UnicodeChar=ucs;                      //~v6DhI~
              	if (attrall)                                       //~v6DhI~
	    			pwkchi->Attributes=attrall;                    //~v6DhI~
              	else                                               //~v6DhI~
	    			pwkchi->Attributes=*pattr;                     //~v6DhI~
                *(pwkchi+1)=*pwkchi;                               //~v6DhI~
              }                                                    //~v6DhI~
              else                                                 //~v6DhI~
#endif                                                             //~v6DhI~
              {                                                    //~v6DhI~
//          	TextOutW(Phdc,xx,Py,pucs,1);                       //~v652M~
#ifdef AAA                                                         //~v656I~
                tgtrect.Right =col+dbcssw; //1column for combine char//~v656R~
                srcbufsz.X  =1;    //rect of parm buff,width       //~v656I~
#else                                                              //~v656I~
//              tgtrect.Right =col; //1column for combine char     //~v656I~//~v6BiR~
                tgtrect.Right =(SHORT)col; //1column for combine char//~v6BiI~
                srcbufsz.X  =1;    //rect of parm buff,width       //~v652I~
#endif                                                             //~v656M~
//          	pwkchi=wkchi[chtypeo];                             //~v65aR~
            	pwkchi=wkchi[0];    //chtypeo is -2 if top         //~v65aI~
				pwkchi->Char.UnicodeChar=ucs;                      //~v652I~
              if (attrall)                                         //~v6D6I~
	    		pwkchi->Attributes=attrall;                        //~v6D6I~
              else                                                 //~v6D6I~
	    		pwkchi->Attributes=*pattr;                         //~v652I~
#ifdef UTF8UTF16                                                   //~v6uBI~
		  		if (swovf)                                         //~v6uBI~
                {                                                  //~v6uBI~
	                srcbufsz.X++;    //output ucsctr               //~v6uBI~
	                tgtrect.Right++; //output rect                 //~v6BUI~
					(pwkchi+1)->Char.UnicodeChar=*(pucs+1);        //~v6uBI~
              	  if (attrall)                                     //~v6D6I~
	    			(pwkchi+1)->Attributes=attrall;                //~v6D6I~
                  else                                             //~v6D6I~
	    			(pwkchi+1)->Attributes=*pattr;                 //~v6uBI~
                }                                                  //~v6uBI~
#endif                                                             //~v6uBI~
              }                                                    //~v6DhI~
				UTRACEP("ligature breaker pos xx=%d\n",col);       //~v656R~
//          	rc2=uvioWriteConsoleOutputW(Shconout,pwkchi,srcbufsz,posinsrcbuff,&tgtrect);//~v656I~//~v6BXR~
            	rc2=uvioWriteConsoleOutputW_appendspace(0,Shconout,pwkchi,srcbufsz,posinsrcbuff,&tgtrect,UVIOM_MAXCOL);//~v6BXR~
        UTRACED("pchi chtype<0",pwkchi,srcbufsz.X*sizeof(CHAR_INFO));//~v6uBI~//~v6BTR~
        UTRACED("tgtrect",&tgtrect,(int)sizeof(tgtrect));          //~v6BTR~
//              tgtrect.Left=col+dbcssz; //1column for combine char//~v656I~//~v6BiR~
                tgtrect.Left=(SHORT)(col+dbcssz); //1column for combine char//~v6BiI~
            }                                                      //~v652I~
#ifdef UTF8UTF16                                                   //~v6uBI~
		  	if (swovf)                                             //~v6uBI~
          		pucs++,ii++;                                       //~v6uBI~
#endif                                                             //~v6uBI~
            ligucsctr=0;                                           //~v652I~
            ligstrlen=0;                                           //~v656I~
            if (chtype<0)                                          //~v652I~
            	continue;                                          //~v652I~
        }                                                          //~v652I~
        chtypeo=chtype;                                            //~v652I~
        pwkchi=&wkchi[chtype][ligucsctr++];                        //~v652R~
		pwkchi->Char.UnicodeChar=ucs;                              //~v652I~
      if (attrall)                                                 //~v6D6I~
	    pwkchi->Attributes=attrall;                                //~v6D6I~
      else                                                         //~v6D6I~
	    pwkchi->Attributes=*pattr;                                 //~v652R~
		if (swovf)                                                 //~v6BWI~
        {                                                          //~v6BWI~
          	pucs++,ii++;                                           //~v6BWI~
            ligucsctr++;                                           //~v6BWI~
            *(pwkchi+1)=*pwkchi;                                   //~v6BWI~
			(pwkchi+1)->Char.UnicodeChar=*pucs;                    //~v6BWR~
        }                                                          //~v6BWI~
        ligstrlen+=dbcssz;                                         //~v656I~
    }                                                              //~v652I~
    if (ligucsctr)                                                 //~v652I~
    {                                                              //~v652I~
#ifdef AAA                                                         //~v656I~
        tgtrect.Left  =tgtpos.X;                                   //~v656I~
        tgtrect.Right =tgtpos.X+max(0,ligchsz-1);                  //~v656I~
#else                                                              //~v656I~
//      tgtrect.Right =col-1;                                      //~v656R~//~v6BiR~
        tgtrect.Right =(SHORT)col-1;                               //~v6BiI~
//      srcbufsz.X  =ligucsctr;    //rect of parm buff,width       //~v656I~//~v6BiR~
        srcbufsz.X  =(SHORT)ligucsctr;    //rect of parm buff,width//~v6BiI~
#endif                                                             //~v656I~
        pwkchi=wkchi[chtypeo];                                     //~v652I~
//      rc2=uvioWriteConsoleOutputW(Shconout,pwkchi,srcbufsz,posinsrcbuff,&tgtrect);//~v656I~//~v6BXR~
//#ifdef AAA //@@@@test                                            //~v6C8R~
        rc2=uvioWriteConsoleOutputW_appendspace(0,Shconout,pwkchi,srcbufsz,posinsrcbuff,&tgtrect,UVIOM_MAXCOL);//~v6BXR~
//#else                                                            //~v6C8R~
//        rc2=uvioWriteConsoleOutputW_dbcschk(0,Shconout,pwkchi,srcbufsz,posinsrcbuff,&tgtrect,Pdbcs);//~v6C8R~
//#endif                                                           //~v6C8R~
        UTRACED("pchi last",pwkchi,ligucsctr*sizeof(CHAR_INFO));//~v6uBI~//~v6BTR~
        UTRACED("tgtrect",&tgtrect,(int)sizeof(tgtrect));          //~v6BTR~
    }                                                              //~v652I~
UTRACEP("%s:return rc=%d\n",UTT,rc);                             //~v652I~//~v6EgR~
    return rc;                                                     //~v652I~
}//uviowrtcellW1_ligaturestr                                       //~v652R~
//*******************************************************          //~v652I~
//*utf8 file output with ligature option                           //~v6uBI~
//*ret  :rc                                                        //~v652I~
//*******************************************************          //~v652I~
int uviowrtcellW1_ligature(int Popt,PWUCS Pdata,int Pucsctr,UCHAR *Pdbcs,USHORT *Pattr,int Plen,SMALL_RECT *Ptgtrect)//~v652I~
{                                                                  //~v652I~
    char *pdbcs;                                                   //~v652I~
	int rc=0,rc2,ii,swbreakch/*,writelen*/,dbcsid,ucsctr=0,dbcssw,dbcssz,strsz=0;//~v659R~
    int col,row,posb,posc,posa;                                    //~v652I~
    int posbvhex=-1,poscvhex=-1,swbreakvhex;                       //~v658I~
    int chwidth;                                                   //~v656R~
	COORD tgtpos;                                                  //~v652R~
    WUCS ucs,*pucs;                                                //~v652I~
	SMALL_RECT tgtrect;                                            //~v652I~
    USHORT *pattr/*,attrnull=0*/,attro,attrn;                      //~v659R~
#ifdef UTF8UTF16                                                   //~v6uBI~
	int swovf;                                                     //~v6uBI~
#endif                                                             //~v6uBI~
	int swcombineattr,swcombineattrchk=0;                          //~v6EiR~
//**********************                                           //~v652I~
UTRACED("Pdata",Pdata,Pucsctr*2);                                  //~v6uBI~
UTRACED("Pdbcs",Pdbcs,Plen);                                       //~v6uBI~
UTRACED("Pattr",Pattr,Plen*2);                                     //~v6BWR~
    if (Popt & UWCW1LSO_COMBINEATTR)//   0x04       //combine if combinable and combining char attr is different//~v6EiR~
//  	if (UTF_COMBINEMODE())                                     //~v6EiR~
    	if (COMBINEMODE(Popt))                                     //~v6EiI~
        	swcombineattrchk=1;                                    //~v6EgI~
//*clear line                                                      //~v652I~
    tgtpos.X=Ptgtrect->Left;                                       //~v652I~
    tgtpos.Y=Ptgtrect->Top;                                        //~v652I~
//    UTRACEP("wrtcellW1_ligature,xx=%d,yy=%d,ucsctr=%d,dbcslen=%d\n",tgtpos.X,tgtpos.Y,Pucsctr,Plen);//~v659R~
//    rc2=uvioFillConsoleOutputCharacter(Shconout,' ',Plen,tgtpos,&writelen);//~v659R~
//    if (!rc2)  //false                                           //~v659R~
//        rc++;                                                    //~v659R~
//    UTRACEP("fillchar rc=%d,Plen=%d,writelen=%d\n",rc2,Plen,writelen);//~v659R~
//    rc2=FillConsoleOutputAttribute(Shconout,//fill by char       //~v659R~
//                                attrnull,                        //~v659R~
//                                Plen,           //output len     //~v659R~
//                                tgtpos,     //upper left pos in source buff//~v659R~
//                                &writelen);     //clear also attr(else remains previous attr after this times 0x1b)//~v659R~
//    if (!rc2)                                                    //~v659R~
//    {                                                            //~v659R~
//        uerrapi0("FillConsoleOutputAttribute",GetLastError());   //~v659R~
//        rc++;                                                    //~v659R~
//    }                                                            //~v659R~
//    UTRACEP("fillattr rc=%d,Plen=%d,writelen=%d\n",rc2,Plen,writelen);//~v659R~
//substr write                                                     //~v652I~
    row=tgtpos.Y;                                                  //~v652I~
    col=tgtpos.X;                                                  //~v652I~
    posb=posc=posa=-1;                                             //~v652I~
//if (!(Popt & UWCW1LSO_NOCSRPO))   //       0x02       //ignore csrpos//~v6EiR~
  if (Popt & UVIOO_CSRPOSCHK)       // file data line              //~v6EiI~
  {                                                                //~v6E6I~
   	if (row==Scsrposy+Stoplineoffs)	//csr line                     //~v652R~
    {                                                              //~v652I~
        UTRACEP(" csrline Y=%d top=%d,csrY=%d\n",row,Stoplineoffs,Scsrposy);//~v652I~
#ifdef AAA                                                         //~v6FbI~
		utfddgetcsrposbca(0,Pdbcs-col,Plen+col,Scsrposx,&posb,&posc,&posa);//~v652R~
#else                                                              //~v6FbI~
		utfddgetcsrposbca(UTFDDGSP_ALSOLOCAL,Pdbcs-col,Plen+col,Scsrposx,&posb,&posc,&posa);//~v6FbI~
#endif                                                             //~v6FbI~
    }                                                              //~v652I~
   	if (row==Svhexcsrposy+Stoplineoffs)	//csr line                 //~v658I~
    {                                                              //~v658I~
#ifdef AAA                                                         //~v6FbI~
		utfddgetcsrposbca(0,Pdbcs-col,Plen+col,Svhexcsrposx,&posbvhex,&poscvhex,0/*after*/);//~v658I~
#else                                                              //~v6FbI~
		utfddgetcsrposbca(UTFDDGSP_ALSOLOCAL,Pdbcs-col,Plen+col,Svhexcsrposx,&posbvhex,&poscvhex,0/*after*/);//~v6FbR~
#endif                                                             //~v6FbI~
    }                                                              //~v658I~
  }                                                                //~v6E6I~
    tgtrect=*Ptgtrect;                                             //~v652M~
    attro=0;                                                       //~v652R~
    for (ii=0,pucs=Pdata,pdbcs=Pdbcs,pattr=Pattr;ii<Pucsctr;ii++,pucs++,pdbcs+=dbcssz,pattr+=dbcssz,col+=dbcssz)//~v653R~
    {                                                              //~v652I~
        ucs=*pucs;                                                 //~v652I~
        dbcsid=*pdbcs;                                             //~v652I~
	    dbcssw=UDBCSCHK_DBCS1STL(dbcsid);	//locale dbcsid:"1"    //~v6E6I~
      if (!dbcssw)                                                 //~v6E6I~
        dbcssw=UDBCSCHK_DBCS1STUCS2NW(dbcsid); //np ucs is 2 ucs alt char//~v652R~
#ifdef UTF8UTF16                                                   //~v6uBI~
		swovf=0;                                                   //~v6uBI~
		if (UDBCSCHK_ISUCSOVF1ST(dbcsid)) //ucs4                   //~v6uBI~
        {                                                          //~v6uBI~
        	swovf=1;                                               //~v6uBI~
          	dbcssw=1;                                              //~v6uBI~
        }                                                          //~v6uBI~
#endif                                                             //~v6uBI~
        dbcssz=1+dbcssw;                                           //~v652I~
//#ifdef WWW                                                         //~v6BYI~//~v6BZR~
        if (UDBCSCHK_ISUCSWIDTH0(dbcsid))                          //~v652I~
//#else                                                              //~v6BYI~//~v6BZR~
//        if (UTF_ISUCSWIDTH0(ucs))                                  //~v6BYI~//~v6BZR~
//#endif                                                             //~v6BYI~//~v6BZR~
        	chwidth=0;                                             //~v652I~
        else                                                       //~v652I~
        	chwidth=dbcssz;	//tgt positioning                      //~v652I~
//    if (swcombineattr)                                           //~v6EiR~
//  	attrn=(USHORT)swcombineattr;   //get attr without replacing source fld//~v6EiR~
//    else                                                         //~v6EiR~
        attrn=*pattr;                                              //~v652I~
        swcombineattr=0;                                           //~v6EiM~
        swbreakch=(ucs==0x1b)                                      //~v652R~
#ifdef AAA                                                         //~v6BWI~
#ifdef UTF8UTF16                                                   //~v6uBI~
                 || swovf                                          //~v6uBI~
#endif                                                             //~v6uBI~
#endif //AAA                                                       //~v6BWI~
                 ||(col==posb||col==posc||col==posa)               //~v652R~
                 ;                                                 //~v652I~
        swbreakvhex=(col==posbvhex||col==poscvhex);                //~v658R~
        UTRACEP("ii=%d,col=%d,ucs=%x,swbreak=%d,dbcssw=%d,vhex=%d,attrp=%x,attrn=%x\n",ii,col,ucs,swbreakch,dbcssw,swbreakvhex,attro,attrn);//~v6uBI~
        UTRACEP("%s:&attr=%p,dbcsid=%x,ucs=%04x\n",UTT,pattr,dbcsid,ucs);//~v6BWI~
        swbreakch|=swbreakvhex;                                    //~v658I~
//combine attr for combining attr is different to combinable       //~v6EgI~
        if (swcombineattrchk && ii+1<Pucsctr)                      //~v6EgI~
        {                                                          //~v6EgI~
        	if (attrn!=*(pattr+1)                                  //~v6EgI~
      		&&  UTF_COMBINABLE(ucs)                                //~v6EgI~
        	&&  COMBINEMODE(Popt)                                  //~v6EiI~
	        &&  UDBCSCHK_ISUCSWIDTH0(*(pdbcs+1))	//next is combine char with different attr//~v6EgI~
            )                                                      //~v6EgI~
            {                                                      //~v6EgR~
                attrn=((attrn & 0xf0) | *(pattr+1) & 0x0f);        //~v6EgR~
                swcombineattr=1;                                   //~v6EiR~
//              swcombineattr=attrn;   //get attr without replacing source fld//~v6EiR~
                UTRACEP("%s:attrn=%02x,attr_next=%02x,attrn=%02x,ucs=%04x,ucs_next=%04x,dbcs=%02x,dbcs_next=%02x\n",UTT,*pattr,*(pattr+1),attrn,ucs,*(pucs+1),dbcsid,*(pdbcs+1));//~v6EgR~
                *pattr=attrn;   //rep for next string              //~v6EiR~
            }                                                      //~v6EgR~
        }                                                          //~v6EgI~
        if (swbreakch                                              //~v652I~
//      ||  (ucsctr && attrn!=attro)                               //~v6EiR~
//      ||  swcombineattr                                          //~v6EiI~
        ||  (  !(Popt & UWCW1LSO_LIGATUREALL)                      //~v6EiI~
             && (  (ucsctr && attrn!=attro)                        //~v6EiI~
                || swcombineattr                                   //~v6EiR~
                )                                                  //~v6EiI~
            )                                                      //~v6EiI~
        )                                                          //~v652I~
        {                                                          //~v652I~
            if (ucsctr)                                            //~v652R~
            {                                                      //~v652I~
//              tgtrect.Right=col-1;                               //~v656R~//~v6BiR~
                tgtrect.Right=(SHORT)col-1;                        //~v6BiI~
				rc2=uviowrtcellW1_ligaturestr(Popt,pucs-ucsctr,ucsctr,pdbcs-strsz,pattr-strsz,strsz,&tgtrect);//~v652I~
		        rc+=rc2;                                           //~v652I~
//              tgtrect.Left=col;                                  //~v656R~//~v6BiR~
                tgtrect.Left=(SHORT)col;                           //~v6BiI~
            }                                                      //~v652I~
#ifdef AAA                                                         //~v6BWI~
#ifdef UTF8UTF16                                                   //~v6uBI~
        	if (swovf)                                             //~v6uBI~
            {                                                      //~v6uBI~
//              tgtrect.Right=col+dbcssw;                          //~v6uBI~//~v6BiR~
                tgtrect.Right=(SHORT)(col+dbcssw);                 //~v6BiI~
                UTRACEP("OVF breakchar=%04x-%04x\n",ucs,*(pucs+1));//~v6uBI~
				rc2=uviowrtcellW1_ligaturestr(Popt,pucs,2,pdbcs,pattr,dbcssz,&tgtrect);//~v6uBI~
//              tgtrect.Left=col+dbcssz;                           //~v6uBI~//~v6BiR~
                tgtrect.Left=(SHORT)(col+dbcssz);                  //~v6BiI~
                rc+=rc2;                                           //~v6uBI~
                pucs++;	//2 ucs2 for surrogate pair                //~v6uBI~
                ii++;                                              //~v6uBI~
            }                                                      //~v6uBI~
            else                                                   //~v6uBI~
#endif                                                             //~v6uBI~
#endif //AAA                                                       //~v6BWI~
            if (swbreakch)                                         //~v652R~
            {                                                      //~v652I~
//              tgtrect.Right=col+dbcssw;                          //~v656R~//~v6BiR~
                tgtrect.Right=(SHORT)(col+dbcssw);                 //~v6BiI~
                UTRACEP("breakchar=%04x\n",ucs);                   //~v656R~
//  			rc2=uviowrtcellW1_ligaturestr(Popt,pucs,1,pdbcs,pattr,dbcssz,&tgtrect);//~v652I~//~v6BWR~
//  			rc2=uviowrtcellW1_ligaturestr(Popt,pucs,1,pdbcs,pattr,dbcssz,&tgtrect);//~v6BWI~
    			rc2=uviowrtcellW1_ligaturestr(Popt,pucs,1+swovf,pdbcs,pattr,dbcssz,&tgtrect);//~v6BWI~
//              tgtrect.Left=col+dbcssz;                           //~v656R~//~v6BiR~
                tgtrect.Left=(SHORT)(col+dbcssz);                  //~v6BiI~
                rc+=rc2;                                           //~v652I~
        		if (swovf)                                         //~v6BWI~
                {                                                  //~v6BWI~
	                pucs++;	//2 ucs2 for surrogate pair            //~v6BWI~
    	            ii++;                                          //~v6BWI~
                }                                                  //~v6BWI~
            }                                                      //~v652I~
            ucsctr=0;                                              //~v652R~
            strsz=0;                                               //~v652R~
            if (swbreakch)                                         //~v652R~
            	continue;                                          //~v652I~
        }                                                          //~v652I~
        attro=attrn;                                               //~v652I~
        ucsctr++;                                                  //~v652R~
        strsz+=dbcssz;                                             //~v652R~
        if (swovf)                                                 //~v6BWI~
        {                                                          //~v6BWI~
            pucs++;                                                //~v6BWI~
            ucsctr++;                                              //~v6BWI~
            ii++;                                                  //~v6BWI~
        }                                                          //~v6BWI~
    }                                                              //~v652I~
    if (ucsctr)                                                    //~v652R~
    {                                                              //~v652I~
//      tgtrect.Right =col-1;                                      //~v656R~//~v6BiR~
        tgtrect.Right =(SHORT)(col-1);                             //~v6BiI~
		rc2=uviowrtcellW1_ligaturestr(Popt,pucs-ucsctr,ucsctr,pdbcs-strsz,pattr-strsz,strsz,&tgtrect);//~v652R~
        rc+=rc2;                                                   //~v652I~
    }                                                              //~v652I~
UTRACEP("%s: return rc=%d\n",UTT,rc);                              //~v6uBI~
    return rc;                                                     //~v652I~
}//uviowrtcellW1_ligature                                          //~v652I~
//*******************************************************          //~v6BSI~
int uviom_displaydbcspad(SMALL_RECT *Ptgtrect,int Pposx,int Plen)  //~v6BSR~
{                                                                  //~v6BSI~
    int len=1,rc;                                                  //~v6BSR~
	CHAR_INFO wkcombinechi[4],*pwchi;                              //~v6BSI~
	SMALL_RECT	targetrect;                                        //~v6BSI~
	COORD  srcbufsz,posinsrcbuff;                                  //~v6BSI~
//****************************                                     //~v6BSI~
    pwchi=wkcombinechi;                                            //~v6BSI~
    pwchi->Char.UnicodeChar=Guviomdbcspad;                         //~v6BSI~
    if (Guviomdbcspad!=' ')	//tab display                          //~v6BSI~
	    pwchi->Attributes=UVIOM_PADATTR;                           //~v6BSR~
    else                                                           //~v6BSI~
	    pwchi->Attributes=0;                                       //~v6BSI~
    if (Plen>1)                                                    //~v6BSI~
    {                                                              //~v6BSI~
    	*(pwchi+1)=*pwchi;                                         //~v6BSI~
        len++;                                                     //~v6BSM~
        if (Plen>2)                                                //~v6E7I~
        {                                                          //~v6E7I~
    		*(pwchi+2)=*pwchi;                                     //~v6E7I~
        	len++;                                                 //~v6E7I~
        }                                                          //~v6E7I~
    }                                                              //~v6BSI~
    targetrect=*Ptgtrect;                                          //~v6BSI~
    targetrect.Left  =(SHORT)Pposx;                                //~v6BSR~
    targetrect.Right =(SHORT)(Pposx+len-1);                        //~v6BSR~
    posinsrcbuff.X  =0;     				//pos in parm buff     //~v6BSI~
    posinsrcbuff.Y  =0;                     //pos in parm buff     //~v6BSI~
    srcbufsz.X  =(SHORT)len;                                       //~v6BSI~
    srcbufsz.Y  =1;       //rect of parm buff,height               //~v6BSI~
    rc=uvioWriteConsoleOutputW(Shconout,wkcombinechi,srcbufsz,posinsrcbuff,&targetrect);//~v6BSR~
    UTRACEP("%s:posx=%d,len=%d,rc=%d\n",UTT,Pposx,Plen,rc);        //~v6BSR~
    return rc;                                                     //~v6BSI~
}//uviom_displaydbcspad                                            //~v6BSI~
//*******************************************************          //~v5n8I~
//*uvio_w95writecellW1                                             //~v6EkR~
//*use not outputW but outputcharactersW and outputattribute       //~v5n8I~
//*(output corrupt screen when attr is changed at intermediate)    //~v5n8I~
//*(write 1 by 1 for the case font size is medium of fullwidth and half width.//~v5n8I~
//* And,hangul is full-width but cursor is half.string length is shorten.//~v5n8I~
//*ret  :rc                                                        //~v5n8I~
//*******************************************************          //~v5n8I~
int uviowrtcellW1(int Popt,PCHAR_INFO Ppchi,int Plen,UCHAR *Ppdbcs,COORD Psrcbox,COORD Psrcpos,SMALL_RECT *Ptgtrect)//~v5n8I~
{                                                                  //~v5n8I~
    int rc=0;                                                      //~v5n8I~
	COORD tgtpos;                                                  //~v5n8I~
//  int writelen,ucsctr,shrinkctr,escsw=0;                         //~v5n8R~//~v6h7R~
    int writelen=0,ucsctr,shrinkctr,escsw=0;                       //~v6h7I~
    UCHAR *pdbcs,*pdata,*pdata0,ch;                                //~v5n8R~
    WUCS  *pucs,*pucs0;                                            //~v5n8R~
    USHORT *pattr,*pattr0;                                         //~v5n8R~
    PCHAR_INFO pchi;                                               //~v5n8I~
    int ii,chwidth,writelend=0,writelena=0;                        //~v5n8I~
    int sw8859unp=0;		//unprintable iso8859                  //~v62mI~
    DWORD dwlen;                                                   //~v6hdI~
#ifdef UTF8UCS2                                                    //~v640I~
    int m2uopt=0;                                                  //~v640R~
//  WUCS wucsspace=' ';                                            //~v640I~//~v6hdR~
//  USHORT attrnull=0;                                             //~v659R~
//  int rc2,combinectr=0,jj;                                       //~v650R~//~v6h7R~
    int rc2=0,combinectr=0,jj;                                     //~v6h7I~
	CHAR_INFO wkcombinechi[(UVIOM_MAXCOMBINE+1)*2],*pwchi;         //~v650R~
    USHORT attrcmb;                                                //~v650I~
    WUCS   *pucscmb;                                               //~v650R~
//  WUCS   wkucscombine[UVIOM_MAXCOMBINE];                         //~v652R~
	COORD  srcbufsz,posinsrcbuff;                                  //~v650I~
//  COORD tgtpospadding;                                           //~v652R~
	SMALL_RECT	targetrect;                                        //~v650I~
    int chictr;                                                    //~v650I~
    int posa,posc,posb,swcombinemode,col,combpos;                  //~v656R~
    int posbvhex=-1,poscvhex=-1;                                   //~v658I~
    USHORT attr,attro=0;                                           //~v652R~
#endif                                                             //~v640I~
#ifdef UTF8UTF16                                                   //~v6uBI~
	int swovf;                                                     //~v6uBI~
#endif                                                             //~v6uBI~
    UCHAR *pdbcsend;                                               //~v6BSI~
#ifndef SSS                                                        //~v6DhI~
    int swdbcsspaceutf8;                                           //~v6DhI~
    WUCS   wkaltch[2];                                             //~v6DhI~
#endif                                                             //~v6DhI~
    int fontflag;                                                  //~v6E7I~
    WUCS   ucs;                                                    //~v6E7I~
    int noligid;                                                   //~v6E8I~
    int rc3=0;                                                     //~v6EaR~
    int optligature;                                               //~v6EiI~
  	int optm2us=0;                                                 //~v6FbM~
//************************                                         //~v5n8I~
    UTRACEP("%s:Popt=%04x,len=%d,src pos=%08x,box=%08x\n",UTT,Popt,Plen,Psrcpos,Psrcbox);//~v6EiR~
    UTRACED("tgtrectW1",Ptgtrect,sizeof(SMALL_RECT));              //~v5n8I~
    UTRACED("writecellW1 srcbox",&Psrcbox,sizeof(COORD));          //~v650R~
    UTRACED("writecellW1 srcpos",&Psrcpos,sizeof(COORD));          //~v650R~
    UTRACED("uviowrtcellW1 inp chibuff",Ppchi,Plen*sizeof(CHAR_INFO));//~v5n8I~//~v65kR~
	if (!Sdbcsspacealt)                                            //~v6G0M~
    	Sdbcsspacealt=UTF_GETALTCH_DBCS();                         //~v6G0M~
    tgtpos.X=Ptgtrect->Left;                                       //~v5n8I~
    tgtpos.Y=Ptgtrect->Top;                                        //~v5n8I~
//get mbs and attr                                                 //~v5n8I~
//	pdata0=pdata=(UCHAR*)(ULONG)Ppchi;                             //~v5n8R~//~v6hhR~
	pdata0=pdata=(UCHAR*)(ULPTR)Ppchi;                             //~v6hhI~
    pattr0=pattr=Guviombuffu;                                      //~v5n8R~
    UTRACED("uviowrtcellW1 pattr0",pattr0,Plen*2);                 //~v650I~
    pucs0=pattr+Plen;                                              //~v5n8I~
    pdbcs=Ppdbcs;                                                  //~v62BI~
    pdbcsend=pdbcs+Plen;                                           //~v6BSI~
#ifndef JJJ                                                        //~v6EaR~
//  noligid=uviom_noligature_linechk(tgtpos.Y);                    //~v6EiR~
    noligid=(Popt & UVIOO_LIGATURE2);                              //~v6EiR~
#endif                                                             //~v6EaR~
#ifdef UTF8UCS2                                                    //~v640I~
    if (utfchkdd(0,pdbcs,Plen))                                    //~v640R~
    {                                                              //~v640I~
    	m2uopt|=UVIOM2UO_DDSTR;                                    //~v640I~
    }                                                              //~v640I~
#endif                                                             //~v640I~
    for (ii=0,pchi=Ppchi;ii<Plen;ii++,pchi++)                      //~v5n8I~
    {                                                              //~v5n8I~
    	ch=pchi->Char.AsciiChar;                                   //~v5n8R~
        if (ch==0x1b)                                              //~v5n8I~
//      	escsw=1;                                               //~v5n8I~//~v65iR~
        	escsw|=1;                                              //~v65iR~
#ifdef UTF8UCS2                                                    //~v640I~
        if (!ch)                                                   //~v640I~
        	if (!*pdbcs)	//sbcs                                 //~v640I~
                ch=' ';                                            //~v640I~
#endif                                                             //~v640I~
		if (ch<0x20)                                               //~v65iM~
        	escsw|=2;                                              //~v65iM~
        else                                                       //~v65iI~
        if (ch>=0x80)                                   //~v62mI~  //~v62BR~
        	if (!*pdbcs)	//sbcs                                 //~v62BI~
//*for ddfmt, pdbcs!=0 for ch>0x80;so this logic applied to locale file only ***//~v68pR~
            	if (!iswprint(ch))                                     //~v62mR~//~v62BR~
                {                                                  //~v62BI~
//          		sw8859unp=1;		//unprintable in >=0x80; iso8859          //~v62mI~//~v62BR~
                    ch=UVIO_ERRREP2;                               //~v62BR~
                }                                                  //~v62BI~
    	*pdata++=ch;                                               //~v5n8I~
#ifndef JJJ                                                        //~v6EaR~
	  if (ch<0x20 && noligid)                                      //~v6EaR~
    	*pattr++=(pchi->Attributes & 0xf0)|ATTR_CTLCHAR_FG;        //~v6EaR~
      else                                                         //~v6EaR~
#endif                                                             //~v6EaR~
    	*pattr++=pchi->Attributes;                                 //~v5n8R~
        pdbcs++;                                                   //~v62BI~
    }                                                              //~v5n8I~
#ifdef UTF8UCS2                                                    //~v640I~
  if (m2uopt)                                                      //~v640I~
	uvio_mdd2u(m2uopt,pdata0,Ppdbcs,Plen,pucs0,Plen*WUCSSZ,&ucsctr,0/*outdbcsucsctr*/,0/*outsbcsucsctr*/);//~v640R~
  else                                                             //~v640I~
#endif                                                             //~v640I~
  {                                                                //~v65iI~
//  uvio_m2us(0,pdata0,Plen,Ppdbcs,pucs0,Plen*WUCSSZ,&ucsctr);     //~v6FbR~
    if (LIGATUREMODE(Popt) && (Popt & UVIOO_CSRPOSCHK))       // file data line//~v6FbI~
        optm2us=UVM2USO_ALTDBCSSPACE; //      0x01 //back to tabdisplay set for dbcs spcae//~v6FbR~
    uvio_m2us(optm2us,pdata0,Plen,Ppdbcs,pucs0,Plen*WUCSSZ,&ucsctr);//~v6FbI~
    if (escsw)	//for dd fmt,it was done at uviom_mdd2u-->utf22    //~v65iI~
      rc3=			//altch rep failed                             //~v6EaR~
        uviom_escrep(escsw,pucs0,ucsctr);	//replace 0x1b to some symbol//~v65iR~//~v6E6R~
  }                                                                //~v65iI~
    escsw=0;                                                       //~v65iI~
    shrinkctr=Plen-ucsctr;                                         //~v5n8R~
UTRACEP("uviowrtcellw1 len=%d,ucsctr=%d,shrinkctr=%d,swunprintable8859=%d\n",Plen,ucsctr,shrinkctr,sw8859unp);//~v5n8I~//~v62BR~
UTRACED("uviowrtcellw1 pdata",pdata0,Plen);                        //~v5n8I~
UTRACED("uviowrtcellw1 pdbcs",Ppdbcs,Plen);                        //~v5n8I~
UTRACED("uviowrtcellw1 ucs",pucs0,ucsctr*WUCSSZ);                    //~v5n8R~//~v65mR~
UTRACED("uviowrtcellw1 attr",pattr0,Plen*2);                       //~v5n8I~
    if (!m2uopt	//not dd fmt                                       //~v6G0M~
    )                                                              //~v6G0M~
    {                                                              //~v6G0M~
    	rc=uviowrtcellW1_localefile(0,pucs0,ucsctr,pdata0,Ppdbcs,pattr0,Plen,tgtpos);//~v6G0M~
    }                                                              //~v6G0M~
    else                                                           //~v6G0M~
//	if (!shrinkctr)		//all sbcs                                 //~v5n8I~//~v62BR~
#ifdef UTF8UCS2                                                    //~v640I~
    if (!sw8859unp && !shrinkctr                                   //~v640I~
    &&  !m2uopt                                                    //~v640I~
    )                                                              //~v640I~
#else                                                              //~v640I~
    if (!sw8859unp && !shrinkctr)                                  //~v62mI~//~v62BM~
#endif                                                             //~v640I~
  	{                                        //write once for performance//~v5n8I~
		if (escsw)                                                 //~v5n8R~
        {                                                          //~v5n8I~
//        if (!uvioFillConsoleOutputCharacterW(Shconout,wucsspace,Plen,tgtpos,&writelen))//~v659R~
//            rc++;                                                //~v659R~
//#ifdef UTF8UCS2                                                  //~v659R~
////*if not colr vsplit line remains when screen split change V-->H//~v659R~
//            if (FillConsoleOutputAttribute(Shconout,//fill by char//~v659R~
//                                        attrnull,                //~v659R~
//                                        Plen,           //output len//~v659R~
//                                        tgtpos,     //upper left pos in source buff//~v659R~
//                                        &writelena)==0)     //clear also attr(else remains previous attr after this times 0x1b)//~v659R~
//            {                                                    //~v659R~
//                uerrapi0("FillConsoleOutputAttribute",GetLastError());//~v659R~
//                rc++;                                            //~v659R~
//            }                                                    //~v659R~
//            UTRACEP("fillattr Plen=%d,writelen=%d\n",Plen,writelena);//~v659R~
//#endif                                                           //~v659R~
            uviom_clearlineW(UVIOMCLO_ATTRSTR,0/*data*/,pattr0,Plen,tgtpos);//~v659I~
    	}                                                          //~v5n8I~
#ifdef DDD    	                                                   //~v6D7I~
#ifdef AAA                                                         //~v6C8I~
    	if (!uvioWriteConsoleOutputCharacterW(Shconout,pucs0,Plen,tgtpos,&writelend)) //len written//~v656I~
            rc++;                                                  //~v656I~
        UTRACED("outputchar ascii",pucs0,Plen*2);                  //~v640I~
        UTRACEP("writelen=%d\n",writelend);                        //~v640I~
	  if (!escsw)   //attr not yet writtenn by clearline           //~v659I~
      {                                                            //~v659I~
		if (WriteConsoleOutputAttribute(Shconout,		//write to buffer//~v5n8R~
										pattr0,		//attribute    //~v5n8I~
//                                		Plen,                      //~v5n8I~//~v6hdR~
                                		(DWORD)Plen,               //~v6hdI~
                                		tgtpos,                    //~v5n8I~
//                          			&writelena)==0)			//writelen//~v5n8R~//~v6hdR~
                            			&dwlen)==0)			//writelen//~v6hdI~
        {                                                          //~v5n8I~
            uerrapi0("WriteConsoleOutputAttribute-uviowrtcellW-1",GetLastError());//~v5n8I~
            rc++;                                                  //~v5n8I~
        }                                                          //~v5n8I~
        writelena=(int)dwlen;                                      //~v6hdI~
        UTRACED("outputattr ascii",pattr0,Plen*2);                 //~v640I~
        UTRACEP("writelen=%d\n",writelena);                        //~v640I~
      }                                                            //~v659I~
#else                                                              //~v6C8M~
        dwlen=Plen;                                                //~v6C8I~
	  if (escsw)   //attr not yet writtenn by clearline            //~v6C8M~
      {                                                            //~v6C8M~
    	if (!uvioWriteConsoleOutputCharacterW(Shconout,pucs0,dwlen,tgtpos,&writelend)) //len written//~v6C8R~
            rc++;                                                  //~v6C8M~
        UTRACED("outputchar ascii",pucs0,Plen*2);                  //~v6C8M~
        UTRACEP("%s:escsw on writelen=%d\n",UTT,writelend);        //~v6C8M~
      }                                                            //~v6C8M~
      else                                                         //~v6C8M~
      {                                                            //~v6C8M~
        targetrect=*Ptgtrect;                                      //~v6C8M~
        if (!uvioWriteConsoleOutputCharacterW1withAttrN(Shconout,pucs0,Plen,pattr0,&targetrect,tgtpos,&dwlen))//~v6C8R~
            rc++;                                                  //~v6C8M~
        writelend=dwlen;                                           //~v6C8R~
        writelena=dwlen;                                           //~v6C8I~
        UTRACEP("%s:escsw off writelen=%d\n",UTT,writelend);       //~v6C8M~
      }                                                            //~v6C8M~
#endif                                                             //~v6C8M~
#else	//!DDD                                                     //~v6D7I~
     if (rc3 & 0x02	//ctlchar remains                              //~v6EaR~
#ifdef JJJ                                                         //~v6EaR~
     &&  uviom_noligature_linechk(tgtpos.Y)==UVMNLLCRC_CMDLINE)    //~v6EiR~
     {                                                             //~v6EaR~
    	rc=uviowrtcellW1_NonLigatureLine(Popt,1/*cmdline*/,pucs0,ucsctr,Ppdbcs,pattr0,Plen,Ptgtrect);//~v6EiR~
#else                                                              //~v6EaR~
     &&  noligid)                                                  //~v6EaR~
     {                                                             //~v6EaR~
//  	rc=uviowrtcellW1_NonLigatureLine(Popt,noligid,pucs0,ucsctr,Ppdbcs,pattr0,Plen,Ptgtrect);//~v6EiR~
    	rc=uviowrtcellW1_NonLigatureLine(Popt,pucs0,ucsctr,Ppdbcs,pattr0,Plen,Ptgtrect);//~v6EiI~
#endif                                                             //~v6EaR~
     }                                                             //~v6EaR~
     else                                                          //~v6EaR~
     {                                                             //~v6EaR~
#ifdef NNN                                                         //~v6F7R~
    	if (!uvioWriteConsoleOutputCharacterW(Shconout,pucs0,Plen,tgtpos,&writelend)) //len written//~v6D7I~
            rc++;                                                  //~v6D7I~
        UTRACED("outputchar ascii",pucs0,Plen*2);                  //~v6D7I~
        UTRACEP("writelen=%d\n",writelend);                        //~v6D7I~
	  if (!escsw)   //attr not yet writtenn by clearline           //~v6D7I~
      {                                                            //~v6D7I~
		if (WriteConsoleOutputAttribute(Shconout,		//write to buffer//~v6D7I~
										pattr0,		//attribute    //~v6D7I~
                                		(DWORD)Plen,               //~v6D7I~
                                		tgtpos,                    //~v6D7I~
                            			&dwlen)==0)			//writelen//~v6D7I~
        {                                                          //~v6D7I~
            uerrapi0("WriteConsoleOutputAttribute-uviowrtcellW-1",GetLastError());//~v6D7I~
            rc++;                                                  //~v6D7I~
        }                                                          //~v6D7I~
        writelena=(int)dwlen;                                      //~v6D7I~
        UTRACED("outputattr ascii",pattr0,Plen*2);                 //~v6D7I~
        UTRACEP("writelen=%d\n",writelena);                        //~v6D7I~
      }                                                            //~v6D7I~
#else                                                              //~v6F7R~
        targetrect=*Ptgtrect;                                      //~v6F7R~
//      if (!uvioWriteConsoleOutputCharacterW1withAttrN(Shconout,pucs0,Plen,pattr0,&targetrect,tgtpos,&dwlen))//~v6F9R~
        if (!uvioWriteConsoleOutputCharacterW1withAttrN(Popt,Shconout,pucs0,Plen,pattr0,&targetrect,tgtpos,&dwlen))//~v6F9I~
            rc++;                                                  //~v6F7R~
        writelend=dwlen;                                           //~v6F7R~
        writelena=dwlen;                                           //~v6F7R~
        UTRACEP("%s:escsw off writelen=%d\n",UTT,writelend);       //~v6F7R~
#endif                                                             //~v6F7R~
     }//ctlchar                                                    //~v6EaR~
#endif                                                             //~v6D7I~
	}                                                              //~v5n8I~
  	else	//not all ascii                                        //~v5n8I~
    {                                                              //~v5n8I~
    	UTRACEP("%s:tgtrect top=%d,toplineoffs=%d\n",UTT,Ptgtrect->Top,Stoplineoffs);//~v6EiR~
#ifdef QQQ                                                         //~v6G0R~
//*if dbcs by locale code,valid for half DBCS but no ligature for dbcs//~v6G0I~
//*if dbcs by cpu8(prev style),do ligature but shrink at half width DBCS(shrink by XcharcterW api)//~v6G0I~
      if (m2uopt                                                   //~v6G0M~
      &&  Popt & UVIOO_CSRPOSCHK         //file edit panel         //~v6G0M~
      &&  LIGATUREMODE(Popt)                                       //~v6G0M~
	  )                                                            //~v6G0M~
      {                                                            //~v6G0M~
		rc=uviowrtcellW1_cpu8file_Ligature(Popt,pucs0,ucsctr,pdata0,Ppdbcs,pattr0,Plen,Ptgtrect);//~v6G0M~
      }                                                            //~v6G0M~
      else                                                         //~v6G0M~
#endif    //QQQ    by lineopt                                      //~v6G0I~
#ifdef PPP                                                         //~v6EiI~
      if (Sswligatureword && Ptgtrect->Top-Stoplineoffs>=Sswligatureword)	//dirlist entry(except errmsg/filename and cmdline)//~v6D6R~
      {                                                            //~v6D6I~
//  	rc=uviowrtcellW1_ligature(Popt,pucs0,ucsctr,Ppdbcs,pattr0,Plen,Ptgtrect);//~v6D7I~//~v6EfR~
    	rc=uviowrtcellW1_ligature(Popt|UWCW1LSO_NOCSRPO,pucs0,ucsctr,Ppdbcs,pattr0,Plen,Ptgtrect);//~v6EfI~
      }                                                            //~v6D6I~
#else     //!PPP   by lineopt                                      //~v6EiI~
      if (Popt & UVIOO_LIGATURE2)	//hdr,cmdline LC: line(uerrmsg has NON_LIGATURE and FORCELIGATURE)//~v6EiI~
      {                                                            //~v6EiI~
    	UTRACEP("%s:ligature no row=%d\n",UTT,Ptgtrect->Top-Stoplineoffs);//~v6EiI~
    	rc=uviowrtcellW1_NonLigatureLine(Popt,pucs0,ucsctr,Ppdbcs,pattr0,Plen,Ptgtrect);//~v6EiI~
      }                                                            //~v6EiI~
      else                                                         //~v6EiI~
      if (Popt & UVIOO_FORCELIGATURE)	//dirlist entry            //~v6EiI~
      {                                                            //~v6EiI~
    	UTRACEP("%s:ligature force row=%d\n",UTT,Ptgtrect->Top-Stoplineoffs);//~v6EiI~
    	optligature=Popt & UVIOO_MASK;                             //~v6EiI~
    	rc=uviowrtcellW1_ligature(optligature,pucs0,ucsctr,Ppdbcs,pattr0,Plen,Ptgtrect);//~v6EiI~
      }                                                            //~v6EiI~
      else                                                         //~v6D6I~
#endif    //!PPP                                                   //~v6EiM~
#ifdef PPP                                                         //~v6EiI~
//    if (uviom_noligature_linechk(tgtpos.Y))                      //~v6D6I~//~v6E8R~
      if (noligid=uviom_noligature_linechk(tgtpos.Y),noligid)      //~v6E8I~
      {                                                            //~v6D6I~
    	UTRACEP("%s:noligatureline tgtpos=%d\n",UTT,Ptgtrect->Top);//~v6D6I~
//  	rc=uviowrtcellW1_NonLigatureLine(Popt,pucs0,ucsctr,Ppdbcs,pattr0,Plen,Ptgtrect);//~v6D7I~//~v6E8R~
    	rc=uviowrtcellW1_NonLigatureLine(Popt,noligid==UVMNLLCRC_CMDLINE,pucs0,ucsctr,Ppdbcs,pattr0,Plen,Ptgtrect);//~v6E8R~
#else     //!PPP   by lineopt                                      //~v6EiI~
//      if (Popt & UVIOO_LIGATURE2)   //hdr,cmdline LC: line(uerrmsg has NON_LIGATURE and FORCELIGATURE)//~v6EiR~
//      {                                                          //~v6EiR~
//        UTRACEP("%s:ligature no row=%d\n",UTT,Ptgtrect->Top-Stoplineoffs);//~v6EiR~
////      rc=uviowrtcellW1_NonLigatureLine(Popt,noligid==UVMNLLCRC_CMDLINE,pucs0,ucsctr,Ppdbcs,pattr0,Plen,Ptgtrect);//~v6EiR~
//        rc=uviowrtcellW1_NonLigatureLine(Popt,pucs0,ucsctr,Ppdbcs,pattr0,Plen,Ptgtrect);//~v6EiR~
#endif    //!PPP                                                   //~v6EiI~
//      }                                                          //~v6EiR~
//      else                                                       //~v6EiR~
#ifdef PPP                                                         //~v6EiI~
//    if (m2uopt && UTF_LIGATUREMODE()) //ligature on              //~v652I~//~v6C7R~
      if (m2uopt && UTF_LIGATUREMODE() //ligature on               //~v6C7I~
#ifndef WXE                                                        //~v6C7I~
	  &&  !uviom_noligature_linechk(tgtpos.Y)                      //~v6C7I~
#endif                                                             //~v6C7I~
#else //!PPP                                                       //~v6EiI~
//    if (m2uopt && LIGATUREMODE(Popt) //ligature on               //~v6FbR~
      if (                                                         //~v6FbI~
			 LIGATUREMODE(Popt) //ligature on                      //~v6FbI~
          && (Popt & UVIOO_CSRPOSCHK)                              //~v6FbI~
#endif                                                             //~v6EiI~
	  )                                                            //~v6C7I~
      {                                                            //~v652M~
    	UTRACEP("%s:ligature optional row=%d\n",UTT,Ptgtrect->Top-Stoplineoffs);//~v6EiI~
//      uviom_clearlineW(UVIOMCLO_ATTRSTR,0/*data*/,pattr0,Plen,tgtpos);//~v65aR~
//  	rc=uviowrtcellW1_ligature(Popt,pucs0,ucsctr,Ppdbcs,pattr0,Plen,Ptgtrect);//~v6EiR~
    	optligature=Popt & UVIOO_MASK;                             //~v6EiI~
    	rc=uviowrtcellW1_ligature(optligature,pucs0,ucsctr,Ppdbcs,pattr0,Plen,Ptgtrect);//~v6EiI~
      }                                                            //~v652M~
      else                                                         //~v652M~
#ifndef QQQ                                                        //~v6G0I~
      if (m2uopt                                                   //~v6G0R~
      &&  Popt & UVIOO_CSRPOSCHK         //file edit panel         //~v6G0I~
      &&  !LIGATUREMODE(Popt)                                      //~v6G0I~
	  )                                                            //~v6G0I~
      {                                                            //~v6G0I~
		if (COMBINEMODE(Popt))  //combine                          //~v6G0I~
			rc=uviowrtcellW1_cpu8file_NoLigatureCombine(Popt,pucs0,ucsctr,pdata0,Ppdbcs,pattr0,Plen,Ptgtrect);//~v6G0R~
        else                                                       //~v6G0I~
    		rc=uviowrtcellW1_cpu8file_NoLigatureNoCombine(Popt,pucs0,ucsctr,pdata0,Ppdbcs,pattr0,Plen,Ptgtrect);//~v6G0R~
      }                                                            //~v6G0I~
      else                                                         //~v6G0I~
#endif                                                             //~v6G0I~
      {                                                            //~v652M~
      	UTRACEP("%s:not uviowrtcellW1_ligature\n",UTT);            //~v6C7I~
      	posa=posb=posc=-1;                                         //~v652I~
//      swcombinemode=(m2uopt && UTF_COMBINEMODE());//utf8 combine mode//~v6EiR~
        swcombinemode=(m2uopt && COMBINEMODE(Popt));//utf8 combine mode//~v6EiI~
        if (swcombinemode) //ligature on                           //~v652I~
        {                                                          //~v658I~
   			if (tgtpos.Y==Scsrposy+Stoplineoffs)	//csr line     //~v652I~
    		{                                                      //~v652I~
        		UTRACEP(" line Y=%d X=%d,top=%d,csrY=%d\n",tgtpos.Y,tgtpos.X,Stoplineoffs,Scsrposy);//~v652I~
				utfddgetcsrposbca(0,Ppdbcs-tgtpos.X,Plen+tgtpos.X,Scsrposx,&posb,&posc,&posa);//~v652R~
    		}                                                      //~v652I~
   			if (tgtpos.Y==Svhexcsrposy+Stoplineoffs)	//csr line //~v658I~
    		{                                                      //~v658I~
				utfddgetcsrposbca(0,Ppdbcs-tgtpos.X,Plen+tgtpos.X,Svhexcsrposx,&posbvhex,&poscvhex,0/*after*/);//~v658I~
    		}                                                      //~v658I~
        }                                                          //~v658I~
//        if (!uvioFillConsoleOutputCharacter(Shconout,' ',Plen,tgtpos,&writelen))//~v659R~
//            rc++;                                                //~v659R~
//        if (WriteConsoleOutputAttribute(Shconout,       //write to buffer//~v659R~
//                                        pattr0,                  //~v659R~
//                                        Plen,                    //~v659R~
//                                        tgtpos,                  //~v659R~
//                                        &writelen)==0)          //writelen//~v659R~
//        {                                                        //~v659R~
//            uerrapi0("WriteConsoleOutputAttribute-uviowrtcellW-2",GetLastError());//~v659R~
//            rc++;                                                //~v659R~
//        }                                                        //~v659R~
//UTRACEP("uviowrtcellW1 attr rc=%d,len=%d,writelen=%d\n",rc,Plen,writelen);//~v659R~
//UTRACED("uviowrtcellW1 attr",pattr0,Plen*2);                     //~v659R~
#ifndef LLL //@@@@test                                              //~v6D7I~//~v6D6R~
        uviom_clearlineW(UVIOMCLO_ATTRSTR,0/*data*/,pattr0,Plen,tgtpos);//~v659I~
#else                                                              //~v6D7I~
        uviom_clearlineW(UVIOMCLO_ATTRFILL,0/*data*/,pattr0,Plen,tgtpos);//~v6D7I~
#endif                                                             //~v6D7I~
        col=0;  //start col                                        //~v653I~
//**************************************************               //~v656I~
        pdata=pdata0;                                              //~v65kI~
#ifndef NNN                                                        //~v6F7R~
        pattr=pattr0;                                              //~v6F7R~
#endif                                                             //~v6F7R~
        for (rc=0,ii=0,pucs=pucs0,pdbcs=Ppdbcs;ii<ucsctr;ii++,pucs++)//~v5n8R~
        {                                                          //~v5n8I~
            ucs=*pucs;                                             //~v6E7I~
//#Windows    no GB4support  UDBCSCHK_DBCS                         //~v62UR~
#ifdef UTF8UCS2                                                    //~v640I~
#ifdef UTF8UTF16                                                   //~v6uBI~
			swovf=0;                                               //~v6uBI~
#endif                                                             //~v6uBI~
#ifndef SSS                                                        //~v6DhI~
    		swdbcsspaceutf8=0;                                     //~v6DhI~
#endif                                                             //~v6DhI~
          if (m2uopt)	//cpu8 file                                //~v640I~
          {                                                        //~v640I~
           if (Guviomopt & UDCWCIO_XEACB) 	                       //~v640I~
            chwidth=UDBCSCHK_DBCS1STUCS2NWP(*pdbcs)+1;             //~v640I~
           else                                                    //~v640I~
          	chwidth=UDBCSCHK_DBCS1STUCS2NW(*pdbcs)+1;              //~v640R~
#ifdef UTF8UTF16                                                   //~v6uBI~
			if (UDBCSCHK_ISUCSOVF1ST(*pdbcs)) //ucs4               //~v6uBI~
            {                                                      //~v6uBI~
            	swovf=1;                                           //~v6uBI~
          		chwidth++;                                         //~v6uBI~
            }                                                      //~v6uBI~
#endif                                                             //~v6uBI~
#ifndef SSS                                                        //~v6DhI~
    		if (*pucs==DBCSSPACE_ALT2   //ffff                     //~v6DhR~
			&&  *pdbcs==UDBCSCHK_DBCS1STUCS)	//tabdisplay set ffff/() for dbcsspace//~v6DhI~
    			swdbcsspaceutf8=1;			                       //~v6DhI~
#endif                                                             //~v6DhI~
          }                                                        //~v640I~
		  else	                                                   //~v640I~
#endif                                                             //~v640I~
//          chwidth=(*pdbcs==UDBCSCHK_DBCS1ST)&& (*pucs>=0x80/*not dbcserr*/) ? 2 : 1;//~v5n8I~//~v65kR~
//          chwidth=(*pdbcs==UDBCSCHK_DBCS1ST)&& (*pdata>=0x80/*not dbcserr*/) ? 2 : 1;//~v65kI~//~v65mR~
//          chwidth=(*pdbcs==UDBCSCHK_DBCS1ST)&& (*pdata>=0x80/*not dbcserr*/) && (*pdata!=DBCSSPACE_ALT/*0xff*/)? 2 : 1;//~v65nR~
//          chwidth=(*pdbcs==UDBCSCHK_DBCS1ST)&& (*pdata>=0x80/*not dbcserr*/) && (*pdata!=DEFAULT_ALTCH/*0xff*/)? 2 : 1;//~v65nI~//~v6BSR~
//          chwidth=(*pdbcs==UDBCSCHK_DBCS1ST ? UDBCSCHK_PCD_MBCHSZ(pdbcs,PTRDIFF(pdbcsend,pdbcs)):1);//~v6BSI~//~v6DdR~
			chwidth=1;                                             //~v6DdI~
          	if (*pdbcs==UDBCSCHK_DBCS1ST)                          //~v6DdI~
            {                                                      //~v6DdI~
				if (*pdata!=DEFAULT_ALTCH/*0xff*/)	//by tabdisplay for dbcs space//~v6DdR~
					chwidth=UDBCSCHK_PCD_MBCHSZ(pdbcs,PTRDIFF(pdbcsend,pdbcs));//~v6DdI~
            }                                                      //~v6DdI~
            UTRACEP("%s:W1 m2uopt=%d,chwidth=%d,data=%x,dbcs=%x,ucs=%x\n",UTT,m2uopt,chwidth,*pdata,*pdbcs,*pucs);//~v6uBI~
#ifndef SSS                                                        //~v6DhI~
    	  if (swdbcsspaceutf8)                                     //~v6DhI~
          {                                                        //~v6DhI~
          		chwidth=2;                                         //~v6DhI~
          		wkaltch[0]=(WUCS)UTF_GETALTCH_DBCS();              //~v6DhR~
          		wkaltch[1]=wkaltch[0];                             //~v6DhR~
#ifndef NNN                                                        //~v6F7R~
            	if (!uvioWriteConsoleOutputCharacterW1withAttr1(0,Shconout,wkaltch,2,tgtpos,&writelen,Ptgtrect,pattr,chwidth)) //len written//~v6F7R~
#else                                                              //~v6F7R~
            	if (!uvioWriteConsoleOutputCharacterW(Shconout,wkaltch,2,tgtpos,&writelen)) //len written//~v6DhI~
#endif                                                             //~v6F7R~
                	rc++;                                          //~v6DhI~
UTRACEP("%s:write dbcsspaceutf8F ucs=%04x,col=%d\n",UTT,*pucs,tgtpos.X);//~v6DhI~
            	writelend+=writelen;                               //~v6DhI~
            	pdbcs+=chwidth;                                    //~v6DhI~
            	pdata+=chwidth;                                    //~v6DhI~
            	tgtpos.X+=(SHORT)chwidth;                          //~v6DhI~
#ifndef NNN                                                        //~v6F7R~
        		pattr+=chwidth;                                    //~v6F7R~
#endif                                                             //~v6F7R~
          }                                                        //~v6DhI~
          else                                                     //~v6DhI~
#endif                                                             //~v6DhI~
#ifdef UTF8UCS2                                                    //~v650I~
//        if (UTF_COMBINEMODE())                                   //~v652R~
#ifdef UTF8UTF16                                                   //~v6uBI~
          if (swcombinemode && !swovf)//utf8 combine mode          //~v6uBI~
#else                                                              //~v6uBI~
          if (swcombinemode)//utf8 combine mode                    //~v652I~
#endif                                                             //~v6uBI~
          {                                                        //~v650I~
	        attr=pattr0[col];                                      //~v653R~
//* after fill space and WriteConsoleOutputAttribute for the line  //~v650I~
//* write non space padding for combining char                     //~v650I~
//* then use WiriteConsoleOutput(char+attr) for base+combining char//~v650R~
            if (combinectr)                                        //~v650I~
            {                                                      //~v650I~
                combinectr--;                                      //~v650I~
            }                                                      //~v650I~
            else                                                   //~v650I~
            {                                                      //~v650I~
                if (attr==attro)                                   //~v656I~
                {                                                  //~v656I~
//#ifdef WWW                                                         //~v6BYI~//~v6BZR~
	            	combinectr=uvio_getcombinectr(0,*pucs,chwidth,pdbcs,ucsctr-ii);//~v656R~
//#else                                                              //~v6BYI~//~v6BZR~
//                    combinectr=uvio_getcombinectrUCS(0,pucs,chwidth,pdbcs,ucsctr-ii);//~v6BYI~//~v6BZR~
//#endif                                                             //~v6BYI~//~v6BZR~
                    if (combinectr)                                //~v656I~
                    {                                              //~v656I~
                		for (jj=1;jj<=combinectr;jj++)             //~v656R~
							if (attr!=pattr0[col+jj])              //~v656I~
                        	{                                      //~v656I~
                            	combinectr=jj-1;                   //~v656R~
                                break;                             //~v656I~
                            }                                      //~v656I~
                    }                                              //~v656I~
                }                                                  //~v656I~
                else                                               //~v656I~
                	combinectr=0;                                  //~v656I~
UTRACEP("combinectr=%d,atto=%d,attrn=%d,col=%d,rcol=%d\n",combinectr,attro,attr,tgtpos.X,col);//~v656M~
                if (combinectr)                                    //~v652I~
                {                                                  //~v652I~
                    combpos=tgtpos.X+1;                            //~v656R~
                    for (jj=1;jj<=combinectr;jj++,combpos++)       //~v656I~
                    {                                              //~v658I~
                        if (combpos==posb||combpos==posc||combpos==posa)//~v656R~
                        {                                          //~v656I~
                            combinectr=jj-1;                       //~v656I~
                            break;                                 //~v656I~
                        }                                          //~v656I~
                        if (combpos==posbvhex||combpos==poscvhex)  //~v658I~
                        {                                          //~v658I~
                            combinectr=jj-1;                       //~v658I~
                            break;                                 //~v658I~
                        }                                          //~v658I~
                    }                                              //~v658I~
UTRACEP("combinectr=%d,combpos=%d,posb=%d,posc=%d,posa=%d\n",combinectr,combpos,posb,posc,posa);//~v656R~
                }                                                  //~v652I~
                  if (combinectr) //acceptable combine             //~v656R~
                  {                                                //~v656R~
                    if (Guviomdbcspad!=' ')                        //~v656R~
                    {                                              //~v656R~
                        pwchi=wkcombinechi;                        //~v656R~
                        for(jj=0;jj<combinectr;jj++,pwchi++)       //~v656R~
                        {                                          //~v656R~
                            pwchi->Char.UnicodeChar=Guviomdbcspad; //~v656R~
//                          attrcmb=pattr0[tgtpos.X+chwidth+jj];   //~v656R~
                            attrcmb=pattr0[col+chwidth+jj];        //~v656R~
                            pwchi->Attributes=(attrcmb&0xf0)/*bg*/|UVIOM_PADATTR/*fg*/;//~v656R~
                        }                                          //~v656R~
                        targetrect=*Ptgtrect;                      //~v656R~
//                      targetrect.Left  =tgtpos.X+chwidth;        //~v656R~//~v6BiR~
                        targetrect.Left  =tgtpos.X+(SHORT)chwidth; //~v6BiI~
//                      targetrect.Right =tgtpos.X+chwidth+combinectr-1;//~v656R~//~v6BiR~
                        targetrect.Right =tgtpos.X+(SHORT)(chwidth+combinectr-1);//~v6BiI~
                        posinsrcbuff.X  =0;                     //pos in parm buff//~v656R~
                        posinsrcbuff.Y  =0;                     //pos in parm buff//~v656R~
//                      srcbufsz.X  =combinectr;    //rect of parm buff,width//~v656R~//~v6BiR~
                        srcbufsz.X  =(SHORT)combinectr;    //rect of parm buff,width//~v6BiI~
                        srcbufsz.Y  =1;       //rect of parm buff,height//~v656R~
                        UTRACEP("combined combinectr=%d,chwidth=%d\n",combinectr,chwidth);//~v656R~
                        rc2=uvioWriteConsoleOutputW(Shconout,wkcombinechi,srcbufsz,posinsrcbuff,&targetrect);//~v656R~
                    }                                              //~v656R~
                	pucscmb=pucs;                                  //~v650I~
                	pwchi=wkcombinechi;                            //~v650I~
                    pwchi->Char.UnicodeChar=*pucscmb++;            //~v650I~
//                  attrcmb=pattr0[tgtpos.X];                      //~v653R~
                    attrcmb=pattr0[col];                           //~v653I~
                    pwchi->Attributes=attrcmb;                     //~v650R~
//#ifdef AAA //@@@@test  not combined if attr is not same          //~v6EsR~
//#else                                                            //~v6EsR~
//                    attrcmb=(attrcmb & 0xf0)|ATTR_COMBINENP_FG;  //~v6EsR~
//#endif                                                           //~v6EsR~
                	for(jj=0,pwchi++;jj<combinectr;jj++,pwchi++)   //~v650I~
                    {                                              //~v650I~
	                    pwchi->Char.UnicodeChar=*pucscmb++;        //~v650I~
////                            wkucscombine[jj]=Guviomdbcspad;    //~v656I~
	                    pwchi->Attributes=attrcmb;                 //~v650R~
                    }                                              //~v650I~
//                  attrcmb=pattr0[tgtpos.X+chwidth];              //~v653R~
                    chictr=1+combinectr;                           //~v650I~
//                    if (Guviomdbcspad!=' ')                      //~v656R~
//                    {                                            //~v656R~
//                        for(jj=0;jj<combinectr;jj++,pwchi++)     //~v656R~
//                        {                                        //~v656R~
//                            pwchi->Char.UnicodeChar=Guviomdbcspad;//~v656R~
//                            attrcmb=pattr0[col+chwidth+jj];      //~v656R~
//                            attrcmb=(attrcmb&0xf0)/*bg*/|UVIOM_PADATTR/*fg*/;//~v656R~
//                            pwchi->Attributes=attrcmb;           //~v656R~
//                        }                                        //~v656R~
//                        chictr+=combinectr;                      //~v656R~
//                    }                                            //~v656R~
//                    UTRACEP("combineMode combinectr=%d,writelen=%d\n",combinectr,chictr);//~v656R~
                    targetrect=*Ptgtrect;                          //~v650I~
    				targetrect.Left  =tgtpos.X;                    //~v650I~
//  				targetrect.Right =tgtpos.X+chwidth+chictr-1;   //~v656R~
//  				targetrect.Right =tgtpos.X+chictr-1;  //ucs ctr//~v656R~//~v6BiR~
    				targetrect.Right =tgtpos.X+(SHORT)chictr-1;  //ucs ctr//~v6BiI~
    				posinsrcbuff.X  =0;     				//pos in parm buff//~v650I~
    				posinsrcbuff.Y  =0;                     //pos in parm buff//~v650I~
//  				srcbufsz.X  =chictr;    //rect of parm buff,width//~v650R~//~v6BiR~
    				srcbufsz.X  =(SHORT)chictr;    //rect of parm buff,width//~v6BiI~
    				srcbufsz.Y  =1;       //rect of parm buff,height//~v650I~
					UTRACEP("uviowrtcellW1 combine ucs=%04x-%04x,col=%d,chwidth=%d\n",*pucs,*(pucs+1),tgtpos.X,chwidth);//~v656I~
//#ifdef AAA //@@@@test                                            //~v6EsR~
            		rc2=uvioWriteConsoleOutputW(Shconout,wkcombinechi,srcbufsz,posinsrcbuff,&targetrect);//~v656I~
//#else                                                            //~v6EsR~
//#ifdef BBB                                                       //~v6EsR~
//                    wkcombinechi[chictr].Char.UnicodeChar=' ';   //~v6EsR~
//                    wkcombinechi[chictr].Attributes=1;           //~v6EsR~
//                    srcbufsz.X++;                                //~v6EsR~
//                    targetrect.Right =tgtpos.X+(SHORT)chictr;  //ucs ctr//~v6EsR~
//                    rc2=uvioWriteConsoleOutputW(Shconout,wkcombinechi,srcbufsz,posinsrcbuff,&targetrect);//~v6EsR~
//                    targetrect.Right =tgtpos.X+(SHORT)chictr-1;  //ucs ctr//~v6EsR~
//                    srcbufsz.X--;                                //~v6EsR~
//#else                                                            //~v6EsR~
//                    wkcombinechi[chictr-1].Attributes=0x0a;      //~v6EsR~
//                    rc2=uvioWriteConsoleOutputW(Shconout,wkcombinechi,srcbufsz,posinsrcbuff,&targetrect);//~v6EsR~
//#endif                                                           //~v6EsR~
//#endif                                                           //~v6EsR~
                }                                                  //~v650I~
                else                                               //~v650I~
                {                                                  //~v650I~
#ifdef DDD                                                         //~v6D7I~
#ifdef AAA                                                         //~v6C8R~
            		rc2=uvioWriteConsoleOutputCharacterW(Shconout,pucs,1,tgtpos,&writelen);//~v656I~
#else                                                              //~v6C7I~
#ifdef KKK                                                         //~v6D7I~
            		rc2=uvioWriteConsoleOutputCharacterW1withAttr(Shconout,pucs,1,Ptgtrect,tgtpos,&writelen,pattr0[tgtpos.X]);//~v6C7R~//~v6C8R~
#else                                                              //~v6D7I~
            		rc2=uvioWriteConsoleOutputCharacterW1withAttrCHW(Shconout,pucs,1,chwidth,Ptgtrect,tgtpos,&writelen,pattr0[tgtpos.X]);//~v6D7I~
#endif                                                             //~v6D7I~
#endif                                                             //~v6C7I~
#else  //!DDD                                                      //~v6D7I~
	#ifndef NNN                                                    //~v6F7R~
            	    rc2=uvioWriteConsoleOutputCharacterW1withAttr1(0,Shconout,pucs,1,tgtpos,&writelen,Ptgtrect,pattr,chwidth); //len written//~v6F7R~
	#else                                                          //~v6F7R~
            		rc2=uvioWriteConsoleOutputCharacterW(Shconout,pucs,1,tgtpos,&writelen);//~v6D7I~
	#endif                                                         //~v6F7R~
#endif                                                             //~v6D7I~
UTRACEP("%s: combine normal ucs=%04x,col=%d,chwidth=%d\n",UTT,*pucs,tgtpos.X,chwidth);//~v6C7I~
                }                                                  //~v650I~
            }                                                      //~v650I~
            if (!rc2)                                              //~v650I~
            {                                                      //~v650I~
//              uerrapi0("WriteConsoleOutputCharacterW-combine",GetLastError());//~v656R~
                rc++;                                              //~v650I~
            }                                                      //~v650I~
            writelend+=writelen;                                   //~v650I~
            pdbcs+=chwidth;                                        //~v650I~
#ifndef NNN                                                        //~v6F7R~
        	pattr+=chwidth;                                        //~v6F7R~
#endif                                                             //~v6F7R~
            pdata+=chwidth;                                        //~v65kI~
//          tgtpos.X+=chwidth;                                     //~v650I~//~v6BiR~
            tgtpos.X+=(SHORT)chwidth;                              //~v6BiI~
            col+=chwidth;                                          //~v653M~
            attro=attr;                                            //~v652I~
          }                                                        //~v650I~
          else                                                     //~v650I~
//*not combinemode                                                 //~v652I~
#endif                                                             //~v650I~
          {                                                        //~v650I~
#ifdef UTF8UTF16                                                   //~v6uBI~
		   if (swovf) //ucs4                                       //~v6uBI~
           {                                                       //~v6uBI~
#ifdef DDD                                                         //~v6D7I~
#ifdef AAA                                                         //~v6C8I~
            if (!uvioWriteConsoleOutputCharacterW(Shconout,pucs,2,tgtpos,&writelen)) //len written//~v6uBI~
#else                                                              //~v6C8I~
#ifdef KKK                                                         //~v6D7I~
            if (!uvioWriteConsoleOutputCharacterW1withAttr(Shconout,pucs,2,Ptgtrect,tgtpos,&writelen,pattr0[tgtpos.X])) //len written//~v6C8I~
#else                                                              //~v6D7I~
            if (!uvioWriteConsoleOutputCharacterW1withAttrCHW(Shconout,pucs,2,chwidth,Ptgtrect,tgtpos,&writelen,pattr0[tgtpos.X])) //len written//~v6D7I~
#endif                                                             //~v6D7I~
#endif                                                             //~v6C8I~
#else    //!DDD                                                    //~v6D7I~
	#ifndef NNN                                                    //~v6F7R~
            if (!uvioWriteConsoleOutputCharacterW1withAttr1(0,Shconout,pucs,2,tgtpos,&writelen,Ptgtrect,pattr,chwidth)) //len written//~v6F7R~
	#else                                                          //~v6F7R~
            if (!uvioWriteConsoleOutputCharacterW(Shconout,pucs,2,tgtpos,&writelen)) //len written//~v6D7I~
	#endif                                                         //~v6F7R~
#endif                                                             //~v6D7I~
                rc++;                                              //~v6uBI~
UTRACEP("%s: not combinemode OVF ucs=%04x-%04x,col=%d,chwidth=%d\n",UTT,*pucs,*(pucs+1),tgtpos.X,chwidth);//~v6uBI~
            ii++;    //vs. loop limit ucsctr                       //~v6BJI~
            pucs++; //printed 2 ucs2                               //~v6uBI~
                                                                   //~v6uBI~
           }                                                       //~v6uBI~
           else                                                    //~v6uBI~
#endif                                                             //~v6uBI~
           {                                                       //~v6BSI~
//locale code                                                      //~v6BSI~
            if (ii+1<ucsctr && IS_UTF16_PAIR(*pucs,*(pucs+1)))     //~v6BSI~
            {                                                      //~v6BSI~
#ifdef DDD                                                         //~v6D7I~
#ifdef AAA                                                         //~v6C8I~
            	if (!uvioWriteConsoleOutputCharacterW(Shconout,pucs,2,tgtpos,&writelen)) //len written//~v6BSR~
#else                                                              //~v6C8I~
#ifdef KKK                                                         //~v6D7I~
            	if (!uvioWriteConsoleOutputCharacterW1withAttr(Shconout,pucs,2,Ptgtrect,tgtpos,&writelen,pattr0[tgtpos.X])) //len written//~v6C8I~
#else                                                              //~v6D7I~
            	if (!uvioWriteConsoleOutputCharacterW1withAttrCHW(Shconout,pucs,2,chwidth,Ptgtrect,tgtpos,&writelen,pattr0[tgtpos.X])) //len written//~v6D7I~
#endif                                                             //~v6D7I~
#endif                                                             //~v6C8I~
#else    //!DDD                                                    //~v6D7I~
	#ifndef NNN                                                    //~v6F7R~
                if (!uvioWriteConsoleOutputCharacterW1withAttr1(0,Shconout,pucs,2,tgtpos,&writelen,Ptgtrect,pattr,chwidth)) //len written//~v6F7R~
	#else                                                          //~v6F7R~
            	if (!uvioWriteConsoleOutputCharacterW(Shconout,pucs,2,tgtpos,&writelen)) //len written//~v6D7I~
	#endif                                                         //~v6F7R~
#endif                                                             //~v6D7I~
                	rc++;                                          //~v6BSI~
                ii++;                                              //~v6BSI~
                pucs++;                                            //~v6BSI~
            }                                                      //~v6BSI~
            else                                                   //~v6BSI~
        	if (m2uopt                                             //~v6EkI~
        	&&  UDBCSCHK_ISUCSWIDTH0(*pdbcs)                       //~v6EkI~
//          &&  UTF_COMBINEMODE_NP() && Gutfcombaltch)             //~v6EsR~
            &&  !COMBINEMODE(Popt)                                 //~v6EsI~
            )                                                      //~v6EsI~
            {                                                      //~v6EkI~
             {                                                     //~v6EsI~
            	UTRACEP("%s:write Gutfcombaltch=%04x\n",UTT,Gutfcombaltch);//~v6EkR~
              if (UTF_COMBINEMODE_NP() && Gutfcombaltch)           //~v6EsI~
            	ucs=(WUCS)Gutfcombaltch;                           //~v6EkR~
	#ifndef NNN                                                    //~v6F7R~
                if (!uvioWriteConsoleOutputCharacterW1withAttr1(0,Shconout,&ucs,1,tgtpos,&writelen,Ptgtrect,pattr,chwidth)) //len written//~v6F7R~
	#else                                                          //~v6F7R~
            	if (!uvioWriteConsoleOutputCharacterW(Shconout,&ucs,1,tgtpos,&writelen)) //len written//~v6EkI~
    #endif                                                         //~v6F7R~
	                rc++;                                          //~v6EkI~
//              attr=ATTR_COMBINENP_FG;// 0x0E   //for combine altch//~v6EkR~
                attr=(pattr0[tgtpos.X] & 0xf0)|ATTR_COMBINENP_FG;  //~v6EkI~
    			rc+=WriteConsoleOutputAttribute(Shconout,&attr,1,tgtpos,&writelen)==0;			//writelen//~v6EkI~
             }                                                     //~v6EsI~
            }                                                      //~v6EkI~
            else                                                   //~v6EkI~
	#ifndef NNN                                                    //~v6F7R~
            if (!uvioWriteConsoleOutputCharacterW1withAttr1(0,Shconout,pucs,1,tgtpos,&writelen,Ptgtrect,pattr,chwidth)) //len written//~v6F7R~
	#else                                                          //~v6F7R~
            if (!uvioWriteConsoleOutputCharacterW(Shconout,pucs,1,tgtpos,&writelen)) //len written//~v6D7I~
    #endif                                                         //~v6F7R~
                rc++;                                              //~v656I~
                if (chwidth>2)                                     //~v6BSI~
                {                                                  //~v6BSI~
                  if (chwidth==4   //gb18030                       //~v6E7R~
				  &&  !IS_UTF16_HIGH(ucs)                          //~v6E7R~
                  &&  utfwcwidth(0,(ULONG)ucs,&fontflag)==1)       //~v6E7R~
                  {                                                //~v6E7I~
                    if (!uviom_displaydbcspad(Ptgtrect,tgtpos.X+1,chwidth-1))//~v6E7I~
                    	rc++;                                      //~v6E7I~
                    writelend+=chwidth-1;                          //~v6E7I~
                  }                                                //~v6E7I~
                  else                                             //~v6E7I~
                  {                                                //~v6E7I~
                    if (!uviom_displaydbcspad(Ptgtrect,tgtpos.X+2,chwidth-2))//~v6BSR~
                    	rc++;                                      //~v6BSI~
                    writelend+=chwidth-2;                          //~v6BSR~
                  }                                                //~v6E7I~
                }                                                  //~v6BSI~
           }                                                       //~v6BSI~
UTRACEP("uviowrtcellW1 not combinemode ucs=%04x,col=%d,chwidth=%d\n",*pucs,tgtpos.X,chwidth);//~v5n8R~//~v650R~
            writelend+=writelen;                                   //~v5n8I~
            pdbcs+=chwidth;                                        //~v5n8I~
#ifndef NNN                                                        //~v6F7R~
        	pattr+=chwidth;                                        //~v6F7R~
#endif                                                             //~v6F7R~
            pdata+=chwidth;                                        //~v65kI~
//          tgtpos.X+=chwidth;                                     //~v5n8I~//~v6BiR~
            tgtpos.X+=(SHORT)chwidth;                              //~v6BiI~
          }                                                        //~v650I~
        }                                                          //~v5n8I~
      }//not ligature                                              //~v652I~
    }                                                              //~v5n8I~
UTRACEP("uviowrtcellW1 return len=%d,ucsctr=%d,rc=%d,outlend=%d\n",Plen,ucsctr,rc,writelend);//~v5n8R~//~v62BR~
    return rc;                                                     //~v5n8I~
}//uviowrtcellW1                                                   //~v5n8I~
#endif                                                             //~v5n8I~
//*******************************************************          //~v5n8I~
//*write char string using Widechar API                            //~v5n8I~
//*******************************************************          //~v5n8I~
int uviowrtcharstrW(int Popt,UCHAR *Ppstr,int Plen,UCHAR *Ppdbcs,COORD Ptgtcoord)//~v5n8R~
{                                                                  //~v5n8I~
	int rc,ucsctr,len;                                             //~v5n8R~
//*****************                                                //~v5n8I~
//	uvio_m2us(Popt,Ppstr,Plen,Ppdbcs,Guviombuffu,Sscrsize*WUCSSZ,&ucsctr);//~v6FbR~
  	uvio_m2us(0,Ppstr,Plen,Ppdbcs,Guviombuffu,Sscrsize*WUCSSZ,&ucsctr);//~v6FbI~
    rc=!uvioWriteConsoleOutputCharacterW(Shconout,Guviombuffu,ucsctr,Ptgtcoord,&len);//~v656I~
    UTRACEP("uviowrtcharstrW rc=%d,inplen=%d,outlen=%d\n",rc,ucsctr,len);//~v5n8R~
    UTRACED("uviowrtcharstrW ucsbuff",Guviombuffu,ucsctr*WUCSSZ);  //~v5n8R~
    return rc;                                                     //~v5n8I~
}//uviowrtcharstrW                                                 //~v5n8R~
//*******************************************************          //~v5n8M~
//*write ucs string                                                //~v5n8R~
//*******************************************************          //~v5n8M~
UINT uviowrtucsstr(WUCS *Ppucs,int Plen,int Prow,int Pcol)         //~v5n8R~
{                                                                  //~v5n8M~
	COORD 		coord;				//read pos                     //~v5n8M~
    DWORD       len;                                               //~v5n8M~
    int rc=0;                                                        //~v5n8M~//~v6h7R~
//*********************************                                //~v5n8M~
    coord.X  =(SHORT)Pcol;                  //pos x                //~v5n8M~
    coord.Y  =(SHORT)(Prow+Stoplineoffs);                   //pos y//~v5n8M~
    if (WriteConsoleOutputCharacterW(Shconout,                     //~v5n8I~
        								Ppucs,	//buff write from  //~v5n8M~
        								Plen,	//write ucs count  //~v5n8M~
        								coord,	//pos write into   //~v5n8M~
                                        &len)==0)	//len written  //~v5n8I~
    {                                                              //~v5n8I~
        rc=GetLastError();                                         //~v5n8I~
        uerrapi0("WriteConsoleOutputCharacterW-uviowrtucsstr",rc); //~v5n8R~
    }                                                              //~v5n8I~
//UTRACEP("uviowrtucsstr  rc=%d,pos x=%d,y=%d\n",rc,coord.X,coord.Y);//~v5n8R~//~v6h7R~
UTRACED("uviowrtucsstr WriteConsoleOutputCharacterW",Ppucs,Plen*2);//~v5n8R~
    return rc;                                                     //~v5n8M~
}//uviowrtucsstr                                                   //~v5n8R~
#ifdef UTF8UCS2 //uvio_m2u not used                                //~v640I~
#else                                                              //~v640I~
//**************************************************               //~v5n8I~
//*uvio multibyte to unicode                                       //~v5n8I~
//*parm :none                                                      //~v5n8I~
//*rc   :none                                                      //~v5n8I~
//**************************************************               //~v5n8I~
int uvio_m2u(int Popt,UCHAR *Ppmbs,int Plen,USHORT *Ppucs,int *Ppchklen)//~v5n8R~
{                                                                  //~v5n8I~
	int len,rc,opt;                                                //~v5n8R~
//***************************************                          //~v5n8I~
	if (Popt & UVIOM2UO_DBCS)                                      //~v5n8I~
    {                                                              //~v5n8I~
	 	opt=UCVUCS_MBDBCS;                                         //~v5n8R~
        len=min(2,Plen);                                           //~v5n8R~
    }                                                              //~v5n8I~
    else                                                           //~v5n8I~
    {                                                              //~v5n8I~
	 	opt=0;                                                     //~v5n8I~
        len=1;                                                     //~v5n8I~
    }                                                              //~v5n8I~
    *Ppchklen=0;                                                   //~v5n8I~
	rc=ucvext_wincp2ucs1(opt,Scodepage,Ppmbs,len,Ppucs,Ppchklen);  //~v5n8R~
	if (rc)                                                        //~v5n8R~
        *Ppucs=UVIO_ERRREP;                                        //~v5n8R~
    if (*Ppchklen<1)                                               //~v5n8I~
    	*Ppchklen=1;                                               //~v5n8I~
UTRACEP("uvio_m2u rc=%d,chklen=%d\n",rc,*Ppchklen);                //~v5n8I~
    return rc;                                                     //~v5n8I~
}//uvio_m2u                                                        //~v5n8I~
#endif                                                             //~v640I~
//**************************************************               //~v5n8I~
//*uvio multibyte to unicode                                       //~v5n8I~
//*parm :none                                                      //~v5n8I~
//*rc   :none                                                      //~v5n8I~
//**************************************************               //~v5n8I~
int uvio_m2us(int Popt,UCHAR *Ppmbs,int Plen,UCHAR *Ppdbcs,WUCS *Ppucs,int Poutbuffsz,int *Poutucsctr)//~v5n8I~
{                                                                  //~v5n8I~
	int rc=0,opt;                                                    //~v5n8I~//~v65mR~
    WUCS *pucs;                                                    //~v65mI~
    UCHAR *pc,*pcd,*pc2,*pc3,*pcd2,*pcd3,*pce;                     //~v65mR~
//  int reslen,outucsctr=0,ucsctr,reslen2,resleno,len,altch;       //~v65mR~//~v6h7R~
    int reslen,outucsctr=0,ucsctr,reslen2,resleno,len,altch=0;     //~v6h7I~
    int swdbcsspace;                                               //~v65nR~
    int dbcsspacealt;                                              //~v6FbI~
    UCHAR *pc4;                                                    //~v6FbI~
//***************************************                          //~v5n8I~
	UTRACEP("%s:opt=%04x\n",UTT,Popt);                             //~v6FbI~
	opt=UVIO_ERRREP;	//repch                                    //~v5n8I~
  if (Guviomopt2 & UVIOMO2_PADON)                                  //~v65mI~
  {                                                                //~v65mI~
    dbcsspacealt=Guviomoptstr[3];                                  //~v6FbI~
  	pce=Ppmbs+Plen;                                                //~v65mI~
  	for (reslen=Plen,pc=Ppmbs,pcd=Ppdbcs,pucs=Ppucs,resleno=Poutbuffsz;reslen>0;)//~v65mI~
    {                                                              //~v65mI~
    	swdbcsspace=0;                                             //~v65nR~
    	for (pc2=pc,pcd2=pcd,reslen2=reslen;;)                     //~v65mI~
        {                                                          //~v65mI~
//  		pc3=memchr(pc2,DBCSSPACE_ALT,reslen2);                 //~v65nR~
    		pc3=memchr(pc2,DEFAULT_ALTCH,reslen2);                 //~v65nI~
            pc4=0;  //ascii altch pos                              //~v6FbI~
            if (dbcsspacealt!=DEFAULT_ALTCH)                       //~v6FbI~
            {                                                      //~v6FbI~
                pc4=memchr(pc2,dbcsspacealt,reslen2);              //~v6FbI~
                if (pc4 && (!pc3||pc4<pc3))                        //~v6FbR~
                    pc3=pc4;                                       //~v6FbI~
            }                                                      //~v6FbI~
            if (!pc3)                                              //~v65mI~
            	break;                                             //~v65mI~
//        	len=(ULONG)pc3-(ULONG)pc2;                             //~v65mI~//~v6hhR~
//        	len=(ULPTR)pc3-(ULPTR)pc2;                             //~v6hhI~//~v6ByR~
          	len=PTRDIFF(pc3,pc2);                                  //~v6ByI~
            pcd3=pcd2+len;                                         //~v65mI~
            swdbcsspace=0;                                         //~v65nR~
            if (*pcd3==UDBCSCHK_DBCS1ST)                           //~v65mI~
            {                                                      //~v65nI~
//              if (pc3+1<pce && *(pc3+1)==DBCSSPACE_ALT)	//0xffff by tabdisplay//~v65nR~
//              if (pc3+1<pce && *(pc3+1)==DEFAULT_ALTCH)	//0xffff by tabdisplay//~v6FbR~
                if (pc3+1<pce                                      //~v6FbI~
                && *(pc3)==dbcsspacealt     //DEFAULT_ALTCH or ascii//~v6FbR~
                && *(pc3+1)==dbcsspacealt                          //~v6FbR~
                )                                                  //~v6FbI~
                {                                                  //~v65nI~
                	swdbcsspace=1;                                 //~v65nR~
                  if (dbcsspacealt==DEFAULT_ALTCH) //ff            //~v6FbI~
        			altch=UTF_GETALTCH_DBCS();                     //~v65nR~
                  else                                             //~v6FbI~
                    altch=dbcsspacealt;                            //~v6FbI~
            		break;                                         //~v65mR~
                }                                                  //~v65nI~
            }                                                      //~v65nI~
            else                                                   //~v65nI~
            if (pc3!=pc4)   //not dbcsspacealt                     //~v6FbI~
            {                                                      //~v65nI~
            	altch=UTF_GETALTCH_SBCS(*pcd3);                    //~v65nI~
            	if (altch>0)                                       //~v65nI~
                	break;                                         //~v65nI~
            }                                                      //~v65nI~
            pc2=pc3+1;                                             //~v65mI~
            pcd2=pcd3+1;                                           //~v65mI~
            reslen2-=len+1;                                        //~v65mI~
        }                                                          //~v65mI~
        if (pc3)                                                   //~v65mI~
//        	len=(ULONG)pc3-(ULONG)pc;                              //~v65mI~//~v6hhR~
//      	len=(ULPTR)pc3-(ULPTR)pc;                              //~v6hhI~//~v6ByR~
        	len=PTRDIFF(pc3,pc);                                   //~v6ByI~
        else                                                       //~v65mI~
        	len=reslen;                                            //~v65mI~
        if (len>0)                                                 //~v65mI~
        {                                                          //~v65mI~
			rc|=ucvext_wincp2ucss(opt,Scodepage,pc,pcd,len,pucs,resleno,&ucsctr);//~v65mR~
    	    outucsctr+=ucsctr;                                     //~v65mI~
        }                                                          //~v65mI~
        else                                                       //~v65mI~
            ucsctr=0;                                              //~v65mI~
        if (!pc3)                                                  //~v65mI~
        	break;                                                 //~v65mI~
        pc=pc3;                                                    //~v65mI~
        pcd+=len;                                                  //~v65mI~
        pucs+=ucsctr;                                              //~v65mI~
        resleno-=ucsctr*WUCSSZ;                                    //~v65mI~
        reslen-=len;                                               //~v65mI~
        if (resleno<=0)                                            //~v65mI~
        	break;                                                 //~v65mI~
//      altch=utfgetvisiblealtch(0,DBCSSPACE_ALT);                 //~v65nR~
//      altch=utfgetvisiblealtch(optaltch,DEFAULT_ALTCH);          //~v65nR~
        if (altch<=0)                                              //~v65mI~
        	altch=UVIO_ERRREP;                                     //~v65mI~
      if (swdbcsspace)                                             //~v65nR~
      {                                                            //~v65nI~
        pc+=2;                                                     //~v65mI~
        pcd+=2;                                                    //~v65mI~
        reslen-=2;                                                 //~v65mI~
	   if (Popt & UVM2USO_ALTDBCSSPACE) //back to tabdisplay set for dbcs spcae//~v6FbI~
       {                                                           //~v6FbI~
//      	altch=DBCSSPACE_ALT2;   //ffff;same as utf8 file       //~v6FbR~
            altch=(dbcsspacealt<<8)|dbcsspacealt;                  //~v6FbR~
       }                                                           //~v6FbI~
       else                                                        //~v6FbI~
       {                                                           //~v6FbI~
//      *pucs++=altch;                                             //~v65mR~//~v6BiR~
        *pucs++=(WUCS)altch;                                       //~v6BiI~
        outucsctr++;                                               //~v65mI~
        resleno-=WUCSSZ;                                           //~v65mI~
        if (resleno<=0)                                            //~v65mI~
        	break;                                                 //~v65mI~
       }                                                           //~v6FbI~
      }                                                            //~v65nI~
      else                                                         //~v65nI~
      {                                                            //~v65nI~
        pc++;                                                      //~v65nI~
        pcd++;                                                     //~v65nI~
        reslen--;                                                  //~v65nI~
      }                                                            //~v65nI~
//      *pucs++=altch;                                             //~v65mR~//~v6BiR~
        *pucs++=(WUCS)altch;                                       //~v6BiI~
        outucsctr++;                                               //~v65mI~
        resleno-=WUCSSZ;                                           //~v65mI~
    }                                                              //~v65mI~
    *Poutucsctr=outucsctr;                                         //~v65mI~
  }                                                                //~v65mI~
  else                                                             //~v65mI~
  {                                                                //~v6DgI~
//  rc=ucvext_wincp2ucss(opt,Scodepage,Ppmbs,Ppdbcs,Plen,Ppucs,Poutbuffsz,Poutucsctr);//~v5n8R~//~v6DgR~
  	pce=Ppmbs+Plen;                                                //~v6DgI~
  	for (reslen=Plen,pc=Ppmbs,pcd=Ppdbcs,pucs=Ppucs,resleno=Poutbuffsz;reslen>0;)//~v6DgI~
    {                                                              //~v6DgI~
//  	swdbcsspace=0;                                             //~v6DgI~
    	for (pc2=pc,pcd2=pcd,reslen2=reslen;;)                     //~v6DgI~
        {                                                          //~v6DgI~
    		pc3=memchr(pc2,DEFAULT_ALTCH,reslen2);                 //~v6DgI~
            if (!pc3)                                              //~v6DgI~
            	break;                                             //~v6DgI~
          	len=PTRDIFF(pc3,pc2);                                  //~v6DgI~
            pcd3=pcd2+len;                                         //~v6DgI~
//          swdbcsspace=0;                                         //~v6DgI~
//            if (*pcd3==UDBCSCHK_DBCS1ST)                         //~v6DgI~
//            {                                                    //~v6DgI~
//                if (pc3+1<pce && *(pc3+1)==DEFAULT_ALTCH)   //0xffff by tabdisplay//~v6DgI~
//                {                                                //~v6DgI~
//                    swdbcsspace=1;                               //~v6DgI~
//                    altch=UTF_GETALTCH_DBCS();                   //~v6DgI~
//                    break;                                       //~v6DgI~
//                }                                                //~v6DgI~
//            }                                                    //~v6DgI~
//            else                                                 //~v6DgI~
            {                                                      //~v6DgI~
            	altch=UTF_GETALTCH_SBCS(*pcd3);                    //~v6DgI~
            	if (altch>0)                                       //~v6DgI~
                	break;                                         //~v6DgI~
            }                                                      //~v6DgI~
            pc2=pc3+1;                                             //~v6DgI~
            pcd2=pcd3+1;                                           //~v6DgI~
            reslen2-=len+1;                                        //~v6DgI~
        }                                                          //~v6DgI~
        if (pc3)                                                   //~v6DgI~
        	len=PTRDIFF(pc3,pc);                                   //~v6DgI~
        else                                                       //~v6DgI~
        	len=reslen;                                            //~v6DgI~
        if (len>0)                                                 //~v6DgI~
        {                                                          //~v6DgI~
			rc|=ucvext_wincp2ucss(opt,Scodepage,pc,pcd,len,pucs,resleno,&ucsctr);//~v6DgI~
    	    outucsctr+=ucsctr;                                     //~v6DgI~
        }                                                          //~v6DgI~
        else                                                       //~v6DgI~
            ucsctr=0;                                              //~v6DgI~
        if (!pc3)                                                  //~v6DgI~
        	break;                                                 //~v6DgI~
        pc=pc3;                                                    //~v6DgI~
        pcd+=len;                                                  //~v6DgI~
        pucs+=ucsctr;                                              //~v6DgI~
        resleno-=ucsctr*WUCSSZ;                                    //~v6DgI~
        reslen-=len;                                               //~v6DgI~
        if (resleno<=0)                                            //~v6DgI~
        	break;                                                 //~v6DgI~
        if (altch<=0)                                              //~v6DgI~
        	altch=UVIO_ERRREP;                                     //~v6DgI~
//      if (swdbcsspace)                                           //~v6DgI~
//      {                                                          //~v6DgI~
//        pc+=2;                                                   //~v6DgI~
//        pcd+=2;                                                  //~v6DgI~
//        reslen-=2;                                               //~v6DgI~
//        *pucs++=(WUCS)altch;                                     //~v6DgI~
//        outucsctr++;                                             //~v6DgI~
//        resleno-=WUCSSZ;                                         //~v6DgI~
//        if (resleno<=0)                                          //~v6DgI~
//            break;                                               //~v6DgI~
//      }                                                          //~v6DgI~
//      else                                                       //~v6DgI~
//      {                                                          //~v6DgI~
        pc++;                                                      //~v6DgI~
        pcd++;                                                     //~v6DgI~
        reslen--;                                                  //~v6DgI~
//      }                                                          //~v6DgI~
        *pucs++=(WUCS)altch;                                       //~v6DgI~
        outucsctr++;                                               //~v6DgI~
        resleno-=WUCSSZ;                                           //~v6DgI~
    }                                                              //~v6DgI~
    *Poutucsctr=outucsctr;                                         //~v6DgI~
  }                                                                //~v6DgI~
    UTRACEP("uvio_m2us rc=%d\n",rc);                               //~v65mI~
    UTRACED("uvio_m2us outucs",Ppucs,*Poutucsctr*WUCSSZ);          //~v65mI~
    return rc;                                                     //~v5n8I~
}//uvio_m2us                                                       //~v5n8I~
#endif //!WXE                                                      //~v5n8I~
#endif  //W32                                                      //~v5n8M~
                                                                   //~v5n8I~
#ifdef LNX                                                         //~v5n8R~
#ifndef XXE                                                        //~v5n8I~
#ifdef CURSESW                                                     //~v5n8I~
//*******************************************************          //~v5n8I~
//*uviom_savecell                                                  //~v5n8I~
//save multibyte data for later read cell                          //~v5n8I~
//*******************************************************          //~v5n8I~
int uviom_savecell(int Popt,int Prow,int Pcol,chtype *Ppcht,int Plen)//~v5n8I~
{                                                                  //~v5n8I~
	chtype *pcht;                                                  //~v5n8R~
    int pos;                                                       //~v5n8I~
//************************                                         //~v5n8I~
//    UTRACEP("savecell row=%d,col=%d,len=%d\n",Prow,Pcol,Plen);     //~v5n8I~//~v6hhR~
	pos=Prow*Sscrwidth+Pcol;                                       //~v5n8I~
//  if (pos+Plen>=Sscrsize)                                        //~v6t0R~
    if (pos+Plen>Sscrsize)                                         //~v6t0I~
    {                                                              //~v5n8I~
    	UTRACEP("ERR uviom_savecell overflow scrsize=%d,row=%d,col=%d,len=%d\n",Sscrsize,Prow,Pcol,Plen);//~v6t0R~
    	return 4;                                                  //~v5n8I~
    }                                                              //~v5n8I~
	pcht=Spcellsv+pos;                                             //~v5n8I~
//  memcpy(pcht,Ppcht,Plen*CCTSZ);                                 //~v5n8I~//~v6BhR~
    memcpy(pcht,Ppcht,(size_t)(Plen*CCTSZ));                       //~v6BhI~
//	UTRACED("uviom_savecell",pcht,Plen*CCTSZ);                     //~v5n8I~//~v6hhR~
    return 0;                                                      //~v5n8I~
}//uviom_savecell                                                  //~v5n8I~
//*******************************************************          //~v5n8I~
//*uviom_readcell                                                  //~v5n8I~
//save multibyte data for later read cell                          //~v5n8I~
//*******************************************************          //~v5n8I~
int uviom_readcell(int Popt,int Prow,int Pcol,chtype *Ppcht,int Plen)//~v5n8R~
{                                                                  //~v5n8I~
	chtype *pcht;                                                  //~v5n8R~
    int pos;                                                       //~v5n8I~
//************************                                         //~v5n8I~
    UTRACEP("readcell row=%d,col=%d,len=%d\n",Prow,Pcol,Plen);     //~v5n8I~
	pos=Prow*Sscrwidth+Pcol;                                       //~v5n8I~
//  if (pos+Plen>=Sscrsize)                                        //~v6t0R~
    if (pos+Plen>Sscrsize)                                         //~v6t0I~
    {                                                              //~v5n8I~
    	UTRACEP("ERR uviom_readcell overflow scrsize=%d,row=%d,col=%d,len=%d\n",Sscrsize,Prow,Pcol,Plen);//~v6t0R~
    	return 4;                                                  //~v5n8I~
    }                                                              //~v5n8I~
	pcht=Spcellsv+pos;                                             //~v5n8I~
//  memcpy(Ppcht,pcht,Plen*CCTSZ);                                 //~v5n8I~//~v6BhR~
    memcpy(Ppcht,pcht,(size_t)(Plen*CCTSZ));                       //~v6BhI~
	UTRACED("uviom_readcell",pcht,Plen*CCTSZ);                     //~v5n8R~
	UTRACED("uviom_readcell",Ppcht,Plen*CCTSZ);                    //~v5n8I~
    return 0;                                                      //~v5n8I~
}//uviom_readcell                                                  //~v5n8I~
//*******************************************************          //~v5n8I~
//*uvio_mvaddchnstrF                                               //~v5n8R~
//write by multibyte/utf8                                          //~v5n8I~
//* mb->mb, utf8->utf8(using addchnstr(no unicode))                //~v5n8R~
//* mb->unicode (by uvio_mvaddchnstrW);                            //~v5n8I~
//*ret  :rc                                                        //~v5n8I~
//*******************************************************          //~v5n8I~
//int uvio_mvaddchnstrF(int Popt,int Prow,int Pcol,chtype *Ppcht,UCHAR *Ppdbcs,int Plen)//~v5n8R~//~v6EmR~
int uvio_mvaddchnstrF(int Popt,int Plineopt,int Prow,int Pcol,chtype *Ppcht,UCHAR *Ppdbcs,int Plen)//~v6EmI~
{                                                                  //~v5n8I~
    int rc=0,ch,escsw,noasciisw,ii,linewidth,mbslen,poss,pos,errrep;//~v5n8R~
    int hankanasw,chtlen,dbcssw,reslen;                        //~v5n8R~//~v5ntR~
#ifdef AAA	//uvio_mvaddchnstrW will process mb->utf8 by mb->unicode//~v5n8I~
    int utf8viosw,rc2;                                             //~v5n8R~
    UCHAR wkutf8str[UTF8_MAXCHARSZ],*pc;                           //~v5n8I~
    WUCS   ucs;                                                    //~v5n8M~
#endif                                                             //~v5n8I~
    UCHAR  mbs[MAX_MBCSLEN],*pdbcs;                                //~v5n8R~
    chtype wkcht[UTF8_MAXCHARSZ],*pcht,attr,*pchts;                //~v5n8R~
    int ss3sw;                                                     //~v5ntR~
//************************                                         //~v5n8I~
//  UTRACEP("uvio_mvaddchnstrF opt=%x,len=%d,row=%d,col=%d\n",Popt,Plen,Prow,Pcol);//~v5n8R~//~v6hhR~
//  UTRACED("chtype",Ppcht,Plen*CCTSZ);                            //~v5n8R~//~v6hhR~
//  UTRACED("dbcs",Ppdbcs,Plen);                                   //~v5n8I~//~v6hhR~
    uviom_savecell(Popt,Prow,Pcol,Ppcht,Plen);                     //~v5n8I~
    if (Popt & UVIOMWFO_MBIN)  //source is multibyte under UTF8 env,write by unicode//~v5n8R~
//    	return uvio_mvaddchnstrW(Popt,Prow,Pcol,Ppcht,Ppdbcs,Plen);//~v5n8I~//~v6EmR~
      	return uvio_mvaddchnstrW(Popt,Plineopt,Prow,Pcol,Ppcht,Ppdbcs,Plen);//~v6EmI~
//*UVIOMWFO_MBIN is off when from  xekbchk                         //~v640I~
    errrep=UVIO_ERRREP;                                            //~v5n8I~
#ifdef AAA	//uvio_mvaddchnstrW will process mb->utf8 by mb->unicode//~v5n8I~
    utf8viosw=Popt & UVIOMWFO_UTF8OUT;    //env is utf8            //~v5n8R~
#endif                                                             //~v5n8I~
    linewidth=min(Plen,Sscrwidth);                                 //~v5n8I~
    for (ii=0,noasciisw=0,escsw=0,pcht=Ppcht;ii<linewidth;ii++,pcht++)//~v5n8R~
    {                                                              //~v5n8I~
	    ch=(*pcht & A_CHARTEXT);                                   //~v5n8R~
        if (ch>=0x80)                                              //~v5n8I~
        	noasciisw=1;                                           //~v5n8I~
        else                                                       //~v5n8I~
        if (Gpdbcstbl[ch]&UDBCSCHK_TYPEUNP)	//unprintable ascii    //~v5n8R~
//        	*pcht=(*pcht & ~(A_CHARTEXT|A_ALTCHARSET))|errrep; //reset uviol_altcharset's setting//~v5n8R~//~v6BhR~
          	*pcht=(*pcht & ~(A_CHARTEXT|A_ALTCHARSET))|(chtype)errrep; //reset uviol_altcharset's setting//~v6BhI~
        else                                                       //~v5n8I~
        if (ch==0x1b)                                              //~v5n8R~
        	escsw=1;                                               //~v5n8I~
    }                                                              //~v5n8I~
	UTRACEP("noasciisw=%d escsw=%d\n",noasciisw,escsw);            //~v5n8I~
	if (!noasciisw  //all ascii                                    //~v5n8R~
    ||  Popt & UVIOMWFO_UTF8IN     //utf8->utf8                    //~v5n8R~
    )                                                              //~v5n8I~
    {                                                              //~v5n8M~
		if (escsw)                                                 //~v5n8I~
			mvaddchnstr(Prow,Pcol,Spspaceline,linewidth);          //~v5n8R~
		mvaddchnstr(Prow,Pcol,Ppcht,linewidth);                    //~v5n8R~
UTRACED("uviom_mvaddchnstrF:mvaddchnstr",Ppcht,linewidth*(int)sizeof(chtype));//~v62UR~//~v6BhR~//~v6D9R~
        return 0;                                                  //~v5n8M~
    }                                                              //~v5n8M~
    if (!(Popt & UVIOMWFO_NODBCSCLEAR))       //NOT no need to clear dbcs line//~v5n8I~
		mvaddchnstr(Prow,Pcol,Spspaceline,linewidth);              //~v5n8R~
    for (pchts=0,pcht=Ppcht,pdbcs=Ppdbcs,pos=Pcol,poss=0,ii=0;     //~v5n8R~
			ii<linewidth;ii+=mbslen,pdbcs+=mbslen,pos+=mbslen)     //~v5n8R~
    {                                                              //~v5n8R~
        wkcht[0]=*pcht++;                                          //~v5n8R~
	    ch=(wkcht[0] & A_CHARTEXT);                                //~v5n8R~
        attr=(wkcht[0] & ~A_CHARTEXT);                             //~v5n8I~
        mbslen=1;                                                  //~v5n8I~
        if (ch>=0x80)                                              //~v5n8R~
        {                                                          //~v5n8I~
        	if (pchts)//preceding asccii string                    //~v5n8I~
            {                                                      //~v5n8I~
				mvaddchnstr(Prow,poss,pchts,pos-poss);             //~v5n8R~
	UTRACEP("sbcs row=%d,col=%d,len=%d\n",Prow,poss,pos-poss);     //~v5n8R~
	UTRACED("sbcs mvaddchnstr",pchts,(pos-poss)*CCTSZ);                //~v5n8R~//~v6D9R~
    			pchts=0;                                           //~v5n8I~
            }                                                      //~v5n8I~
//          mbs[0]=ch;                                             //~v5n8I~//~v6BhR~
            mbs[0]=(UCHAR)ch;                                      //~v6BhI~
            hankanasw=0;                                           //~v5n8R~
            ss3sw=0;                                               //~v5ntR~
//#case of kbd input is UTF8,   no GB4support  UDBCSCHK_DBCS       //~v62UR~
	    	dbcssw=(*pdbcs==UDBCSCHK_DBCS1ST);                     //~v5n8R~
//	    	opt=((dbcssw)?EBC2ASC_STAT_SO:0);                      //~v5n8I~//~v5ntR~
            reslen=linewidth-ii;                                   //~v5n8I~
            if (dbcssw && reslen>1)                                //~v5n8I~
            {                                                      //~v5n8I~
            	wkcht[1]=*pcht++;                                  //~v5n8I~
			    mbs[1]=(wkcht[1] & A_CHARTEXT);                    //~v5n8R~
                mbslen=2;                                          //~v5n8I~
            }                                                      //~v5n8I~
            else                                                   //~v5n8I~
            if (ch==SS2 && reslen>1                                //~v5n8I~
//          && (Gudbcschk_flag & (UDBCSCHK_EUC|UDBCSCHK_UTF8J)))    //EUC hankaku-katakanakana//~v5n8R~//~v5ntR~
            &&  UDBCSCHK_ISEUCJ()    //euc(/+utf8)                 //~v5ntI~
            )                                                      //~v5ntI~
            {                                                      //~v5n8I~
                wkcht[1]=*pcht++;                                  //~v5n8I~
                mbs[1]=wkcht[1] & A_CHARTEXT;                      //~v5n8R~
                if (HANKATA(mbs[1]))                               //~v5n8R~
                {                                                  //~v5n8I~
                	hankanasw=1;                                   //~v5n8I~
                }                                                  //~v5n8I~
                else                                               //~v5n8I~
                {                                                  //~v5n8I~
//                  wkcht[1]=wkcht[0]=attr|errrep;                 //~v5n8R~//~v6BhR~
                    wkcht[1]=wkcht[0]=attr|(chtype)errrep;         //~v6BhR~
                }                                                  //~v5n8I~
                mbslen=2;                                          //~v5n8I~
            }                                                      //~v5n8I~
            else                                                   //~v5ntR~
            if (ch==SS3 && reslen>=3                               //~v5ntR~
//          && (Gudbcschk_flag & (UDBCSCHK_EUC))    //EUC(no UTF8 env)//~v5ntR~
            &&  UDBCSCHK_ISEUCJ()    //euc(/+utf8)                 //~v5ntI~
            )                                                      //~v5ntR~
            {                                                      //~v5ntR~
//#input is not UTF8,   no GB4support  UDBCSCHK_DBCS               //~v62UR~
                if (*(pdbcs+1)==UDBCSCHK_DBCS1ST)                  //~v5ntR~
                {                                                  //~v5ntR~
        	        wkcht[1]=*pcht++;                              //~v5ntR~
            	    mbs[1]=wkcht[1] & A_CHARTEXT;                  //~v5ntR~
        	        wkcht[2]=*pcht++;                              //~v5ntR~
            	    mbs[2]=wkcht[2] & A_CHARTEXT;                  //~v5ntR~
                	ss3sw=1;                                       //~v5ntR~
	                mbslen=3;                                      //~v5ntR~
                }                                                  //~v5ntR~
                else                                               //~v5ntR~
                {                                                  //~v5ntR~
//                  wkcht[0]=attr|errrep;                          //~v5ntR~//~v6BhR~
                    wkcht[0]=attr|(chtype)errrep;                  //~v6BhR~
                }                                                  //~v5ntR~
            }                                                      //~v5ntR~
            else                                                   //~v5njI~
        	if (Gpdbcstbl[ch]&UDBCSCHK_TYPEUNP)	//unprintable ascii//~v5njI~
//        		wkcht[0]=(wkcht[0] & ~(A_CHARTEXT|A_ALTCHARSET))|errrep; //reset uviol_altcharset's setting//~v5njI~//~v6BhR~
          		wkcht[0]=(wkcht[0] & ~(A_CHARTEXT|A_ALTCHARSET)) | (chtype)errrep; //reset uviol_altcharset's setting//~v6BhI~
            chtlen=mbslen;                                         //~v5n8I~
#ifdef AAA	//uvio_mvaddchnstrW will process mb->utf8 by mb->unicode//~v5n8I~
            if (utf8viosw)//env is utf8,write by utf8              //~v5n8R~
            {                                                      //~v5n8I~
				opt=EBC2ASC_PARMUCVEXT|UCVEXTO_CHARLEN; //len parm is for one char(for 3 byte euc char)//~v5ntR~
                rc2=ucvext_iconvlocal2ucs1(opt,(ULONG)Sconverters,mbs,mbslen,0/*chklen output*/,&ucs);//~v5n8R~
                if (rc2)                                           //~v5n8R~
                {                                                  //~v5n8R~
                    wkcht[0]=attr|errrep;                          //~v5n8R~
                    if (mbslen>1)                                  //~v5n8R~
                        wkcht[1]=wkcht[0];                         //~v5n8R~
                }                                                  //~v5n8R~
                else                                               //~v5n8R~
                {                                                  //~v5n8R~
                    chtlen=uccvucs2utf((ULONG)ucs,wkutf8str);      //~v5n8R~
                    for (ii=0,pc=wkutf8str;ii<chtlen;ii++)         //~v5n8R~
                        wkcht[ii]=attr|*pc++;                      //~v5n8R~
                }                                                  //~v5n8R~
            }                                                      //~v5n8I~
            else	//env is non utf8,write by multibyte(from multibyte)//~v5n8R~
            {                                                      //~v5n8I~
#endif                                                             //~v5n8I~
                if (hankanasw)                                     //~v5n8I~
                {                                                  //~v5n8I~
//              	wkcht[2]=attr|errrep;                          //~v5n8R~//~v6BhR~
                	wkcht[2]=attr|(chtype)errrep;                  //~v6BhR~
                    chtlen=3;                                      //~v5n8I~
                }                                                  //~v5n8I~
                if (ss3sw)                                         //~v5ntR~
                {                                                  //~v5ntR~
//              	wkcht[3]=attr|errrep;                          //~v5ntR~//~v6BhR~
                	wkcht[3]=attr|(chtype)errrep;                  //~v6BhR~
                    chtlen=4;                                      //~v5ntR~
                }                                                  //~v5ntR~
#ifdef AAA	//uvio_mvaddchnstrW will process mb->utf8 by mb->unicode//~v5n8I~
            }                                                      //~v5n8I~
#endif                                                             //~v5n8I~
			mvaddchnstr(Prow,pos,wkcht,chtlen);                    //~v5n8R~
	UTRACEP("dbcs/hankana row=%d,col=%d,len=%d\n",Prow,pos,chtlen);//~v5n8R~
	UTRACED("dbcs/hankana mvaddchnstr",wkcht,chtlen*CCTSZ);                    //~v5n8R~//~v6D9R~
        }                                                          //~v5n8I~
        else                                                       //~v5n8I~
        {                                                          //~v5n8I~
        	if (!pchts)   	//1st ascii                            //~v5n8I~
            {                                                      //~v5n8I~
            	pchts=pcht-1;                                      //~v5n8R~
                poss=pos;	//ascii start col                      //~v5n8I~
            }                                                      //~v5n8I~
        }                                                          //~v5n8I~
    }                                                              //~v5n8I~
    if (pchts)//preceding asccii string                            //~v5n8I~
    {                                                              //~v5n8I~
        mvaddchnstr(Prow,poss,pchts,pos-poss);                     //~v5n8I~
UTRACED("sbcs LASTF mvaddchnstr",pchts,(pos-poss)*CCTSZ);                    //~v5n8R~//~v6D9R~
    }                                                              //~v5n8I~
//UTRACEP("uvio_mvaddchnstrF return rc=%d\n",rc);                    //~v5n8R~//~v6hhR~
    return rc;                                                     //~v5n8I~
}//uvio_mvaddchnstrF                                               //~v5n8R~
//*******************************************************          //~v5n8I~
//*uviom_mvaddwchnstr                                              //~v5n8I~
//*******************************************************          //~v5n8I~
int uviom_mvaddwchnstr(int Prow,int Pcol,cchar_t *Ppcchar,int Plen)//~v5n8R~
{                                                                  //~v5n8I~
	int rc;                                                        //~v5n8I~
//********************                                             //~v5n8I~
  if (Pcol>=0)	                                                   //~v656R~
    move(Prow,Pcol);    //mvaddchnstr miss current pos             //~v5n8I~
	rc=add_wchnstr(Ppcchar,Plen);                                  //~v5n8I~
UTRACEP("uviom_mvaddwchnstr rc=%d,row=%d,col=%d,len=%d\n",rc,Prow,Pcol,Plen);//~v5n8I~//~v6hhR~//~v6uBR~
UTRACED("uviom_mvaddwchnstr add_wchnstr cchar",Ppcchar,Plen*CCHSZ);            //~v5n8I~//~v6hhR~//~v6uBR~//~v6D9R~
	return rc;                                                     //~v5n8I~
}//uviom_mvaddwchnstr                                              //~v5n8I~
//*******************************************************          //~v653I~
//*utf8 file output with ligature opption                          //~v653I~
//*ret  :rc                                                        //~v653I~
//*******************************************************          //~v653I~
int uvio_mvaddchnstrW_ligature(int Popt,cchar_t *Pcchar,int Pctr,int Pwidth,int Prow,int Pcol)//~v653R~
{                                                                  //~v653I~
	int rc=0,ii,jj,swbreakch,ucsctr,strsz=0;                       //~v653R~
//  int col,chsz,attr,/*attrn,attro,*/dbcssw,dbcssz;                   //~v653R~//~v65bR~//~v6BhR~
    int col,chsz,dbcssw,dbcssz;                                    //~v6BhI~
    attr_t attr;                                                   //~v6BhI~
    int swshadow;                                                  //~v65bI~
    cchar_t *pch;                                                  //~v653I~
//  ULONG *pucs;                                                   //~v690R~
    UWCHART *pucs;                                                 //~v690I~
//**********************                                           //~v653I~
//*clear line                                                      //~v653I~
    UTRACEP("%s:opt=%x,ctr=%d,len=%d,row=%d,col=%d\n",UTT,Popt,Pctr,Pwidth,Prow,Pcol);//~v653I~//~v6hhR~//~v6D9R~
    UTRACED("Pcchar",Pcchar,Pctr*(int)sizeof(cchar_t));            //~v6D9R~
//  if (!(Popt & UVIOMWFO_NODBCSCLEAR)) //flag is on when no DBCS lang(xescr,uviol) but clear required for UTF8 file for ligature//~v653R~
    {                                                              //~v653I~
//        for (pch=Spspacelinew,ii=0;ii<Pwidth;ii++,pch++)         //~v653R~
//        {                                                        //~v653R~
//            pch->chars[0]=' ';                                   //~v653R~
//            pch->attr=0;                                         //~v653R~
//        }                                                        //~v653R~
        uviom_mvaddwchnstr(Prow,Pcol,Spspacelinew,Pwidth);         //~v653I~
        UTRACED("ligaturemode space clear",Spspacelinew,Pwidth*(int)sizeof(cchar_t));//~v653I~//~v6BhR~
    }                                                              //~v653I~
//substr write                                                     //~v653I~
    col=Pcol;                                                      //~v653I~
    for (ii=0,ucsctr=0,pch=Pcchar;ii<Pctr;ii+=dbcssz,pch+=dbcssz)  //~v653R~
    {                                                              //~v653I~
        attr=pch->attr;                                            //~v65bM~
      	swbreakch=(attr & UVIOMATTR_BREAK);                        //~v653I~//~v65bR~
      	swshadow=attr & UVIOMATTR_SHADOW;                          //~v65bI~
	  if (swshadow)                                                //~v65bI~
        chsz=1;                                                    //~v65bI~
      else                                                         //~v65bI~
      {                                                            //~v65bI~
//  	pucs=(ULONG*)(pch->chars+1);                               //~v690R~
    	pucs=(UWCHART*)(pch->chars+1);                             //~v690I~
    	for (jj=0;jj<UVIOM_MAXCOMBINE;jj++)                        //~v653I~
        	if (!(*pucs++))                                        //~v653I~
            	break;                                             //~v653I~
        chsz=1+jj;                                                 //~v653I~
      }                                                            //~v65bI~
    	dbcssw=(attr & UVIOMATTR_DBCS1)!=0;                        //~v653I~
        dbcssz=1+dbcssw;                                           //~v653I~
        chsz+=dbcssw;                                              //~v653I~
//      attr &= ~UVIOMATTR_BREAK;                                  //~v653I~//~v65bR~
//      attr &= ~(UVIOMATTR_BREAK|UVIOMATTR_SHADOW);               //~v65bI~//~v6BhR~
        attr &= (attr_t)(~(UVIOMATTR_BREAK|UVIOMATTR_SHADOW));     //~v6BhI~
        pch->attr=attr;                                            //~v653I~
//      attrn=attr&~UVIOMATTR_DBCS12;                              //~v653R~//~v65bR~
        UTRACEP("ii=%d,ucs=%x,swbreak=%d,chsz=%d\n",ii,pch->chars[0],swbreakch,chsz);//~v653I~//~v65bR~
        if (swbreakch                                              //~v653I~
//      ||  (ucsctr && attrn!=attro)                               //~v653I~//~v658R~
//      ||  (ii && attrn!=attro)                                   //~v658I~//~v65bR~
        )                                                          //~v653I~
        {                                                          //~v653I~
            if (ucsctr)                                            //~v653I~
            {                                                      //~v653I~
                UTRACEP("ligature substr ucsctr=%d,col=%d\n",ucsctr,col);//~v653I~
				uviom_mvaddwchnstr(Prow,col,pch-ucsctr,ucsctr);    //~v653R~
	            if (strsz>ucsctr)                                  //~v6D9I~
        	        uviom_fillattrspace(0,Prow,col+ucsctr,attr,strsz-ucsctr);	//fill space shrinked by ligature//~v6D9I~
		  		if (!UVIOM_NONSPACECOMBINEMODE()) //non spacing combining diacritical mark supported//~v656R~
                	uviol_refresh();                               //~v656I~
                col+=strsz;                                        //~v653I~
            }                                                      //~v653I~
#ifdef BBB                                                         //~v65bI~
            if (swbreakch)                                         //~v653I~
            {                                                      //~v653I~
                UTRACEP("ligature break substr col=%d,len=%d\n",col,1+dbcssw);//~v653R~
				uviom_mvaddwchnstr(Prow,col,pch,dbcssz);           //~v653R~
		  		if (!UVIOM_NONSPACECOMBINEMODE()) //non spacing combining diacritical mark supported//~v656R~
                	uviol_refresh();                               //~v656I~
                col+=1+dbcssw;                                     //~v653R~
            }                                                      //~v653I~
#endif                                                             //~v65bI~
            ucsctr=0;                                              //~v653I~
            strsz=0;                                               //~v653I~
#ifdef BBB                                                         //~v65bI~
            if (swbreakch)                                         //~v653I~
            	continue;                                          //~v653I~
#endif                                                             //~v65bI~
        }                                                          //~v653I~
//      attro=attrn;                                               //~v653I~//~v65bR~
        ucsctr+=dbcssz;                                            //~v653R~
        strsz+=chsz;	//column                                   //~v653R~
    }                                                              //~v653I~
    if (ucsctr)                                                    //~v653I~
    {                                                              //~v653I~
		uviom_mvaddwchnstr(Prow,col,pch-ucsctr,ucsctr);            //~v653R~
        UTRACED("ligature substr last",pch-ucsctr,ucsctr*(int)sizeof(cchar_t));//~v653R~//~v6BhR~
    }                                                              //~v653I~
	if (!UVIOM_NONSPACECOMBINEMODE()) //non spacing combining diacritical mark supported//~v656I~
//      wnoutrefresh(stdscr);    //NO EFFECT                       //~v656I~
    	uviol_refresh();    //for virtical line draw column        //~v656R~
UTRACEP("ligaturemode return rc=%d\n",rc);                         //~v653I~
    return rc;                                                     //~v653I~
}//uvio_mvaddchnstrW_ligature                                      //~v653I~
//*******************************************************          //~v656I~
//*uvio_mvaddchnstrW_combine                                       //~v656R~
//*combine under NonLigature mode                                  //~v6EmI~
//*ret  :rc                                                        //~v656I~
//*******************************************************          //~v656I~
int uvio_mvaddchnstrW_combine(int Popt,cchar_t *Pcchar,int Pctr,int Pwidth,int Prow,int Pcol,//~v656I~
								chtype *Ppcht,UCHAR *Ppdbcs)       //~v656R~
                                                                   //~v656I~
{                                                                  //~v656I~
    int rc=0,/*ch,*/ii,ccharlen,poss=0,pos;                              //~v656R~//~v6b9R~//~v6h9R~
    int dbcssw;                                                    //~v656I~
    int /*paddingsw,*/breaksw;                                         //~v656I~//~v6b9R~
    cchar_t *pcchar,*pcchars;                                      //~v656I~
    cchar_t *pchtw;                                                //~v656R~
    int combinectr,substrctr=0;                                    //~v656R~
//************************                                         //~v656I~
//  UTRACEP("mvaddchnstrW_combine row=%d,ctr=%d,width=%d\n",Prow,Pctr,Pwidth);//~v656R~//~v6hhR~
    uviom_mvaddwchnstr(Prow,Pcol,Spspacelinew,Pwidth);             //~v656I~
    UTRACED("combinemode space clear",Spspacelinew,Pwidth*(int)sizeof(cchar_t));//~v656I~//~v6BhR~
    UTRACED("Pcchar",Pcchar,Pctr*(int)sizeof(cchar_t));            //~v6EmI~
//  uviol_refresh();                                               //~v656R~
    for (pcchars=0,pcchar=Spwkcchar,pos=Pcol,ii=0;                 //~v656I~
			ii<Pctr;                                               //~v656R~
			ii+=ccharlen,pos+=ccharlen,pcchar+=ccharlen)           //~v656I~
    {                                                              //~v656I~
//      ch=pcchar->chars[0];                                       //~v656I~//~v6b9R~
        ccharlen=1;                                                //~v656I~
//      paddingsw=0;                                               //~v656I~//~v6b9R~
        breaksw=0;                                                 //~v656I~
        if (pcchar->attr & UVIOMATTR_SHADOW)                       //~v65bI~
        {                                                          //~v65bI~
            pcchar->attr &= (attr_t)(~UVIOMATTR_SHADOW);                     //~v65bI~//~v6BhR~
            breaksw=1;                                             //~v65bI~
        }                                                          //~v65bI~
//      paddingsw=(pcchar->attr & UVIOMATTR_PADDING);              //~v656R~//~v658R~
        if (pcchar->attr & UVIOMATTR_BREAK)                        //~v656R~
        {                                                          //~v656R~
//          pcchar->attr &= ~UVIOMATTR_BREAK;                      //~v656R~//~v6BhR~
            pcchar->attr &= (attr_t)(~UVIOMATTR_BREAK);            //~v6BhI~
            breaksw=1;                                             //~v656R~
        }                                                          //~v656R~
        else                                                       //~v656I~
        if (pcchar->chars[1] 	//combined char                    //~v656I~
//  	&&  UVIOM_SPLITMODE())                                     //~v656I~//~v658R~
        )                                                          //~v658I~
            breaksw=1;                                             //~v656I~
//      else                                                       //~v656I~//~v658R~
//      	breaksw|=( (pcchar->chars[1]!=0) || paddingsw);        //~v656I~//~v658R~
//      UTRACEP("attr=%x,breaksw=%d at col=%d ch=%x\n",pcchar->attr,breaksw,paddingsw,pos,ch);//~v656R~//~v6b9R~
        if (!breaksw)                                              //~v656R~
        {                                                          //~v656M~
        	if (!pcchars)   	//1st ascii                        //~v656M~
            {                                                      //~v656M~
            	pcchars=pcchar;                                    //~v656M~
                poss=pos;	//ascii start col                      //~v656M~
            }                                                      //~v656M~
            substrctr++;                                           //~v656I~
        }                                                          //~v656M~
        else                                                       //~v656M~
        {                                                          //~v656I~
        	if (pcchars)//preceding asccii string                  //~v656I~
            {                                                      //~v656I~
				uviom_mvaddwchnstr(Prow,poss,pcchars,substrctr);   //~v656R~
	UTRACEP("sbcs row=%d,col=%d,len=%d\n",Prow,poss,substrctr);    //~v656R~
	UTRACED("sbcs        ",pcchars,(pos-poss)*CCHSZ);              //~v656I~
    			pcchars=0;                                         //~v656I~
                substrctr=0;                                       //~v656I~
            }                                                      //~v656I~
//      UTRACEP("paddingsw=%d ch=%04x\n",paddingsw,ch);            //~v656I~//~v6b9R~
//        if (!(paddingsw && ch==Guviomdbcspad)) //write width0 when not combining(start from width0)//~v656I~//~v658R~
//        {                                                        //~v656I~//~v658R~
//        	if (paddingsw)                                         //~v656I~//~v658R~
//             pcchar->attr &= ~UVIOMATTR_PADDING;	//start from width0//~v656I~//~v658R~
	    	dbcssw=(pcchar->attr & 0x01);	//dbcs 1st             //~v656I~
            ccharlen+=dbcssw;                                      //~v656I~
    UTRACEP("uviom dbcs %x:wcwidth=%d\n",pcchar->chars[0],wcwidth((wchar_t)pcchar->chars[0]));//~v656I~
            combinectr=0;                                          //~v656I~
            if (pcchar->chars[1])   //combined                     //~v656I~
//              if (UVIOM_COMBINEMODE())//combine mode or fc5      //~v656R~//~v658R~
                {                                                  //~v656I~
                    pchtw=pcchar+1;                                //~v656I~
                    if (pcchar->attr & 0x01)  //dbcs               //~v656I~
                        pchtw++;                                   //~v656I~
                    for (combinectr=0;combinectr<UVIOM_MAXCOMBINE;combinectr++,pchtw++)//~v656I~
                    {                                              //~v656I~
                        if (!pcchar->chars[1+combinectr]) //nomore combining//~v656I~
                            break;                                 //~v656I~
						if (UVIOM_NONSPACECOMBINEMODE()) //non spacing combining diacritical mark supported//~v656R~
                        {                                          //~v656I~
                        	if (!(pchtw->attr & UVIOMATTR_PADDING)) //not combine padding set at setcombine;may be for gb4//~v656I~
                            	break;                             //~v656I~
//                      	pchtw->attr &= ~UVIOMATTR_PADDING;  //write width combine char//~v656I~//~v6BhR~
                        	pchtw->attr &= (attr_t)(~UVIOMATTR_PADDING);  //write width combine char//~v6BhI~
                        }                                          //~v656I~
                    }                                              //~v656I~
                }                                                  //~v656I~
	UTRACEP("nonascii ucs row=%d,col=%d,len=%d,dbcssw=%d,combinectr=%d\n",Prow,pos,ccharlen,dbcssw,combinectr);//~v656I~
		  	if (UVIOM_NONSPACECOMBINEMODE()) //non spacing combining diacritical mark supported//~v656R~
          	{                                                      //~v656R~
            	uviom_mvaddwchnstr(Prow,pos,pcchar,ccharlen+combinectr);//~v656R~
            	ccharlen+=combinectr;                              //~v656R~
          	}                                                      //~v656R~
          	else                                                   //~v656R~
          	{                                                      //~v656R~
            	uviom_mvaddwchnstr(Prow,pos,pcchar,ccharlen);      //~v656R~
                uviol_refresh();                                   //~v656R~
              	pos+=combinectr;    //advance step                 //~v656R~
          	}                                                      //~v656R~
//        }//not padding char                                      //~v656I~//~v658R~
        }//breaksw                                                 //~v656R~
    }//for                                                         //~v656R~
    if (pcchars)//preceding asccii string                          //~v656I~
    {                                                              //~v656I~
        uviom_mvaddwchnstr(Prow,poss,pcchars,substrctr);           //~v656R~
UTRACED("sbcs LASTW  ",pcchars,substrctr*CCHSZ);                   //~v656R~
    }                                                              //~v656I~
	if (!UVIOM_NONSPACECOMBINEMODE()) //non spacing combining diacritical mark supported//~v656I~
    	uviol_refresh();    //for virtical line draw column        //~v656I~
//UTRACEP("uvio_mvaddchnstrW return rc=%d\n",rc);                    //~v656I~//~v6hhR~
    return rc;                                                     //~v656I~
}//uvio_mvaddchnstrW_combine                                       //~v656I~
//*******************************************************          //~v5n8I~
//*uvio_mvaddchnstrW                                               //~v5n8R~
//*write multibyte using add_wchnstr(unicode char string write)    //~v5n8I~//~v6E6R~
//*ret  :rc                                                        //~v5n8I~
//*******************************************************          //~v5n8I~
//int uvio_mvaddchnstrW(int Popt,int Prow,int Pcol,chtype *Ppcht,UCHAR *Ppdbcs,int Plen)//~v5n8I~//~v6EmR~
int uvio_mvaddchnstrW(int Popt,int Plineopt,int Prow,int Pcol,chtype *Ppcht,UCHAR *Ppdbcs,int Plen)//~v6EmI~
                                                                   //~v5n8I~
{                                                                  //~v5n8I~
//  int rc=0,rc2,ch,ii,linewidth,ccharlen,poss,pos;                //~v5n8I~//~v6h9R~
    int rc=0,rc2,ch,ii,linewidth,ccharlen,poss=0,pos;              //~v6h9I~
    int dbcssw;                                                    //~v5n8R~
    cchar_t *pcchar,*pcchars;                                      //~v5n8R~
    int outctr;                                                    //~v653I~
//************************                                         //~v5n8I~
//    UTRACEP("uvio_mvaddchnstrW opt=%x,len=%d,row=%d,col=%d\n",Popt,Plen,Prow,Pcol);//~v5n8I~//~v6hhR~
//    UTRACED("chtype",Ppcht,Plen*CCTSZ);                            //~v5n8R~//~v6hhR~
//    UTRACED("dbcs",Ppdbcs,Plen);                                   //~v5n8I~//~v6hhR~
    linewidth=min(Plen,Sscrwidth);                                 //~v5n8I~
//  rc2=uviom_cht2cchar(Popt,Ppcht,Ppdbcs,linewidth,Spwkcchar);    //~v653R~
//  rc2=uviom_cht2cchar(Popt,Ppcht,Ppdbcs,linewidth,Spwkcchar,Prow,Pcol,&outctr);//~v653I~//~v6EmR~
    rc2=uviom_cht2cchar(Popt,Plineopt,Ppcht,Ppdbcs,linewidth,Spwkcchar,Prow,Pcol,&outctr);//~v6EmI~
    if (rc2 & UVIOMCCRC_LIGATUREMODE)                              //~v653I~
    {                                                              //~v653I~
		rc=uvio_mvaddchnstrW_ligature(Popt,Spwkcchar,outctr,linewidth,Prow,Pcol);//~v653R~
        return rc;                                                 //~v653I~
    }                                                              //~v653I~
    if ((rc2 & UVIOMCCRC_COMBINE))	//0x1b found,combined          //~v656R~
    {                                                              //~v656I~
		rc2=uvio_mvaddchnstrW_combine(Popt,Spwkcchar,outctr,linewidth,Prow,Pcol,Ppcht,Ppdbcs);//~v656R~
        return rc;                                                 //~v656I~
    }                                                              //~v656I~
    if (rc2)	//esc or non ascii found                           //~v5n8I~
    {                                                              //~v5n8I~
        if ((rc2 & UVIOMCCRC_ESC)	//0x1b found                   //~v5n8I~//~v650R~//~v656R~
        ||  !(Popt & UVIOMWFO_NODBCSCLEAR))       //NOT no need to clear dbcs line//~v5n8I~
        {                                                          //~v5n8I~
			uviom_mvaddwchnstr(Prow,Pcol,Spspacelinew,linewidth);  //~v5n8R~
			UTRACEP("space clear by rc=%d\n",rc2);                 //~v5n8R~
			UTRACED("space clear",Spspacelinew,linewidth*(int)sizeof(cchar_t));//~v650R~//~v6BhR~
        }                                                          //~v5n8I~
    }                                                              //~v5n8I~
    UTRACEP("cusrseW write row=%d\n",Prow);                        //~v656I~
    for (pcchars=0,pcchar=Spwkcchar,pos=Pcol,ii=0;                 //~v5n8I~
			ii<linewidth;                                          //~v5n8I~
			ii+=ccharlen,pos+=ccharlen,pcchar+=ccharlen)           //~v5n8I~
    {                                                              //~v5n8I~
        ch=pcchar->chars[0];                                       //~v5n8I~
        ccharlen=1;                                                //~v5n8I~
        if (ch>=0x80)                                              //~v5n8I~//~v650R~//~v656R~
        {                                                          //~v5n8I~
        	if (pcchars)//preceding asccii string                  //~v5n8I~
            {                                                      //~v5n8I~
				uviom_mvaddwchnstr(Prow,poss,pcchars,pos-poss);    //~v5n8R~
	UTRACEP("sbcs row=%d,col=%d,len=%d\n",Prow,poss,pos-poss);     //~v62mR~
	UTRACED("sbcs        ",pcchars,(pos-poss)*CCHSZ);              //~v5n8R~
    			pcchars=0;                                         //~v5n8R~
            }                                                      //~v5n8I~
//some char is wcwidth=2 but displayed by single width             //~v5n8I~
//that cause vsplitline column shift,invalid update postion        //~v5n8I~
//but write 1 by 1 coluld not display those char. I accept it.     //~v5n8I~
	    	dbcssw=(pcchar->attr & 0x01);	//dbcs 1st             //~v5n8R~
            ccharlen+=dbcssw;                                      //~v5n8I~
//#ifdef UTF8UCS2                                                  //~v653R~
////#ifdef CCC                                                     //~v653R~
////            if (pcchar->attr & 0x02)    //sbcs of wcwidth==2 by ddcht2cchar//~v653R~
////            {                                                  //~v653R~
////                pcchar->attr &= ~0x02;                         //~v653R~
////                dbcssw=2;                                      //~v653R~
////            }                                                  //~v653R~
////#endif                                                         //~v653R~
//#endif  //UTF8UCS2                                               //~v653R~
//#ifdef EEE                                                       //~v653R~
////#ifdef CCC                                                         //~v5n8I~//~v653R~
////            uviom_mvaddwchnstr(Prow,pos,pcchar,ccharlen);      //~v653R~
////#else    //ncursesw fille 2 column by 1 cchar                  //~v653R~
//////#ifdef DDD                                                   //~v653R~
//////            dbcssw=(pcchar->attr & ~0x01);  //dbcs 1st       //~v653R~
//////#else                                                        //~v653R~
////////          pcchar->attr &= ~0x01;  //drop dbcs bit          //~v653R~
//////#endif                                                       //~v653R~
////            uviom_mvaddwchnstr(Prow,pos,pcchar,1);             //~v653R~
////#endif                                                         //~v653R~
//#else                                                            //~v653R~
    UTRACEP("uviom dbcs %x:wcwidth=%d\n",pcchar->chars[0],wcwidth((wchar_t)pcchar->chars[0]));//~v62mM~
//    #ifdef EEE                                                   //~v653R~
//            if (wcwidth((wchar_t)pcchar->chars[0])==1)           //~v653R~
//            {                                                    //~v653R~
//            pcchar->attr &= ~0x01;  //drop dbcs bit              //~v653R~
//            uviom_mvaddwchnstr(Prow,pos,pcchar,1);               //~v653R~
//            (pcchar+1)->attr &= ~0x02;  //drop dbcs bit          //~v653R~
//            uviom_mvaddwchnstr(Prow,pos+1,(pcchar+1),1);         //~v653R~
//            }                                                    //~v653R~
//            else                                                 //~v653R~
//    #endif                                                       //~v653R~
    		uviom_mvaddwchnstr(Prow,pos,pcchar,ccharlen);          //~v653R~//~v656R~
//#endif                                                           //~v653R~
//	UTRACED("combinewrite",pcchar,(ccharlen+combinectr)*CCHSZ);    //~v656R~
//#ifdef UTF8UCS2                                                  //~v653R~
////#ifdef CCC                                                     //~v653R~
////            if (dbcssw==2)                                     //~v653R~
////            {                                                  //~v653R~
//////              uviom_mvaddwchnstr(Prow,pos+2,pcchar+2,1);     //~v653R~
////                ccharlen=1;                                    //~v653R~
////                pcchar++;   //advance only cchar               //~v653R~
////       //       pos++;                                         //~v653R~
////            }                                                  //~v653R~
////#endif                                                         //~v653R~
//#endif                                                           //~v653R~
        }                                                          //~v5n8I~
        else                                                       //~v5n8I~
        {                                                          //~v5n8I~
        	if (!pcchars)   	//1st ascii                        //~v5n8I~
            {                                                      //~v5n8I~
            	pcchars=pcchar;                                    //~v5n8I~
                poss=pos;	//ascii start col                      //~v5n8I~
            }                                                      //~v5n8I~
        }                                                          //~v5n8I~
    }                                                              //~v5n8I~
    if (pcchars)//preceding asccii string                          //~v5n8I~
    {                                                              //~v5n8I~
        uviom_mvaddwchnstr(Prow,poss,pcchars,pos-poss);            //~v5n8R~
//UTRACED("sbcs LASTW  ",pcchars,(pos-poss)*CCHSZ);                  //~v5n8R~//~v6hhR~
    }                                                              //~v5n8I~
//UTRACEP("uvio_mvaddchnstrW return rc=%d\n",rc);                    //~v62mR~//~v6hhR~
    return rc;                                                     //~v5n8I~
}//uvio_mvaddchnstrW                                               //~v5n8I~
//*******************************************************          //~v5n8I~
//*chtype->cchar_t                                                 //~v5n8I~
//*EUC hankaku katakana is treated as DBCS(2 column position) when UTF8 env//~v5n8I~
//*when EUC env,xesub treate it as 2 byte err because char width and byte count unmatch.//~v5n8I~
//*ret  :rc 0x01:esc found,0x02:non ascii found                    //~v5n8I~
//*******************************************************          //~v5n8I~
//int uviom_cht2cchar(int Popt,chtype *Ppcht,UCHAR *Ppdbcs,int Plen,cchar_t *Ppcchar)//~v653R~
int uviom_cht2cchar(int Popt,int Plineopt,chtype *Ppcht,UCHAR *Ppdbcs,int Plen,cchar_t *Ppcchar,int Prow,int Pcol,int *Ppoutctr)//~v653I~//~v6EmR~
{                                                                  //~v5n8I~
//  int ii,rc2,rc=0,opt,errsw,mblen,dbcssw,errrep,ch,attr;         //~v5n8R~//~v6BhR~
    int ii,rc2,rc=0,opt,errsw,mblen,dbcssw,errrep,ch;              //~v6BhI~
    attr_t attr;                                                   //~v6BhI~
    cchar_t *pcchar;                                               //~v5n8I~
    chtype  *pcht;                                                 //~v5n8I~
    UCHAR *pdbcs;                                                  //~v5n8R~
    UCHAR mbs[MAX_MBCSLEN];                                        //~v5n8I~
    ULONG   acs;                                                   //~v5n8R~
    WUCS    ucs;                                                   //~v5n8I~
    UWUCS   uwucs; //UINT4, WUCS is wchar_t                        //~v6BhI~
//#define DDD                                                      //~v62UR~
//#ifdef DDD                                                       //~v62UR~
    int hankanasw;                                                 //~v5ntI~
//#endif                                                           //~v62UR~
	int ch2,width,fontflag,jj;                                     //~v62UR~
#ifdef UTF8SUPPH                                                   //~v62UR~
//  int attrdbcspad;                                               //~v62UR~//~v6BhR~
    attr_t attrdbcspad;                                            //~v6BhI~
    int apiwidth=0;                                                  //~v635I~//~v6h9R~
#endif                                                             //~v62UR~
	int altch;                                                     //~v65iI~
    int dbcsid;                                                    //~v65nI~
    int outctr;                                                    //~v68eI~
//*********************************                                //~v5n8I~
    errrep=UVIO_ERRREP;                                            //~v5n8R~
//  memset(Ppcchar,0,Plen*CCHSZ);                                  //~v5n8R~//~v6BhR~
    memset(Ppcchar,0,(size_t)(Plen*CCHSZ));                        //~v6BhI~
#ifdef UTF8UCS2                                                    //~v640M~
    if (utfchkdd(0,Ppdbcs,Plen))	//source is DD fmt             //~v640M~
    {                                                              //~v653I~
//  	return uvio_ddcht2cchar(0,Ppcht,Ppdbcs,Plen,Ppcchar,0);    //~v653R~
//		if (Guviomopt2 & UVIOMO2_LIGATURE)                         //~v653R~
//		if (UTF_LIGATUREMODE())                                    //~v653I~//~v6EmR~
		if (LIGATUREMODE(Plineopt))                                //~v6EmI~
//	    	return uvio_ddcht2cchar_ligature(0,Ppcht,Ppdbcs,Plen,Ppcchar,Prow,Pcol,Ppoutctr);//~v653R~//~v6EmR~
  	    	return uvio_ddcht2cchar_ligature(0,Plineopt,Ppcht,Ppdbcs,Plen,Ppcchar,Prow,Pcol,Ppoutctr);//~v6EmI~
//      else                                                       //~v6EcI~//~v6EmR~
//      if (Sswligatureword && Prow>Sswligatureword)	//dirlist entry(except errmsg/filename and cmdline)//~v6EcI~//~v6EmR~
//      	return uvio_ddcht2cchar_ligature(0,Ppcht,Ppdbcs,Plen,Ppcchar,Prow,Pcol,Ppoutctr);//~v6EcI~//~v6EmR~
//  	return uvio_ddcht2cchar(0,Ppcht,Ppdbcs,Plen,Ppcchar,Ppoutctr);//~v653R~
//  	return uvio_ddcht2cchar(0,Ppcht,Ppdbcs,Plen,Ppcchar,Prow,Pcol,Ppoutctr);//~v653R~//~v6EmR~
    	return uvio_ddcht2cchar(0,Plineopt,Ppcht,Ppdbcs,Plen,Ppcchar,Prow,Pcol,Ppoutctr);//~v6EmI~
    }                                                              //~v653I~
#endif                                                             //~v640M~
    for (pcchar=Ppcchar,ii=Plen,pdbcs=Ppdbcs,pcht=Ppcht;           //~v5n8R~
    			ii>0;                                              //~v5n8I~
				ii-=mblen,pcht+=mblen,pcchar+=mblen,pdbcs+=mblen)  //~v5n8I~
    {                                                              //~v5n8I~
	    ch=*pcht & A_CHARTEXT;                                     //~v5n8I~
    	dbcsid=*pdbcs;                                             //~v65nI~
        attr=*pcht & ~(A_CHARTEXT);                                //~v5n8R~
#ifdef UTF8SUPPH                                                   //~v62UR~
//		attrdbcspad=(attr & (~0x0700)/*clear fg bit in the COLOR_PAIR*/)|(UVIOM_PADATTR/*fg*/<<8);//~v62UR~//~v6BhR~
// 		attrdbcspad=(attr & (attr_t)(~0x0700)/*clear fg bit in the COLOR_PAIR*/)|(attr_t)(UVIOM_PADATTR/*fg*/<<8);//~v6BhR~//~v6D9R~
   		attrdbcspad=uviom_set_padattr(0,attr);                     //~v6D9R~
		attrdbcspad&=~A_BOLD;   //reset effect of HIGHLIGHT_FG     //~v62UR~
#endif                                                             //~v62UR~
//for utf8 file,call ddcht2cchar                                   //~v640I~
    	dbcssw=(*pdbcs==UDBCSCHK_DBCS1ST);                         //~v5n8I~
//#ifdef DDD                                                       //~v62UR~
            hankanasw=0;                                           //~v5ntI~
//#endif                                                           //~v62UR~
        mblen=1;                                                   //~v5n8I~
      if (Popt & UVIOMWFO_CHKACS)  //not yet ACS trnslated         //~v5n8I~
      {                                                            //~v5n8I~
//      if (!dbcssw && ((acs=uviol_altcharset(ch,0))&A_CHARTEXT)!=ch)//acs defined//~v5n8R~//~v6BhR~
        if (!dbcssw && ((acs=uviol_altcharset((chtype)ch,0))&A_CHARTEXT)!=ch)//acs defined//~v6BhI~
        {                                                          //~v5n8I~
        	ch=acs&A_CHARTEXT;                                     //~v5n8R~
        	attr|=A_ALTCHARSET;	//ACS                              //~v5n8I~
            UTRACEP("ACS acs=%x,ch=%x\n",acs,ch);                  //~v65pI~
        }                                                          //~v5n8I~
        else                                                       //~v5n8I~
        	attr&=~(A_ALTCHARSET);	//ALTCHARSET cause uxpected effect(set for ctl chatr at uviol_altcharset)//~v5n8I~
      }                                                            //~v5n8I~
        pcchar->attr=attr;                                         //~v5n8M~
        if (!ch)                                                   //~v5n8R~
            pcchar->chars[0]=' ';    //null is used not only file area but anywhere//~v5n8R~
        else                                                       //~v5n8I~
        if (ch<0x80)                                               //~v5n8I~
        {                                                          //~v5n8I~
        	if (ch<0x20)                                           //~v65iI~
            	if ((altch=UTF_GETALTCH_CTL(ch))>0)                //~v65nR~
            		ch=altch;                                      //~v65iI~
          if (ch<0x80)//after altch conversion                     //~v65iI~
            if (Gpdbcstbl[ch] & UDBCSCHK_TYPEUNP)   //unprintable  //~v5n8I~
            	ch=errrep;                                         //~v5n8I~
    	    pcchar->chars[0]=ch;                                   //~v5n8R~
            if (ch==0x1b)                                          //~v5n8I~
	        	rc|=UVIOMCCRC_ESC;                                 //~v5n8I~
        }                                                          //~v5n8I~
        else	                                                   //~v5n8I~
        {                                                          //~v5n8I~
            errsw=0;                                               //~v65pI~
          if (!dbcssw)                                             //~v6DdI~
            if (ch==DEFAULT_ALTCH)//0xff                           //~v65pR~
            {                                                      //~v65pR~
                altch=UTF_GETALTCH_SBCS(dbcsid);                   //~v65pR~
                if (altch>0)                                       //~v65pR~
                {                                                  //~v65pI~
    			    pcchar->chars[0]=ch=altch;                     //~v65pI~
                    errsw=1;                                       //~v65pR~
                }                                                  //~v65pI~
            }                                                      //~v65pR~
          if (ch>=0x80)                                            //~v65pR~
        	rc|=UVIOMCCRC_NONASCII;                                //~v5n8I~
//          errsw=0;                                               //~v65pR~
            if (dbcssw && ii>1)                                    //~v62UR~
            {                                                      //~v62UR~
	    		ch2=*(pcht+1) & A_CHARTEXT;                        //~v62UR~
                if (ch==DEFAULT_ALTCH && ch2==DEFAULT_ALTCH    //default dbcsspace relaced by tabdisplay//~v65nR~
            	&& ((altch=UTF_GETALTCH_DBCS())>0)                 //~v65nR~
                )              //dbcs space                        //~v65mI~
                {                                                  //~v65mI~
    			    pcchar->chars[0]=ch=altch;                     //~v65mI~
    			    *(pcchar+1)=*pcchar;                           //~v65mR~
//#ifdef AAA  //@@@@test                                           //~v6DdR~
//                    (pcchar+1)->chars[0]=' ';                    //~v6DdR~
//#endif                                                           //~v6DdR~
//#ifndef SSS                                                      //~v6DhR~
//                    (pcchar+1)->chars[0]=' ';                    //~v6DhR~
//#endif                                                           //~v6DhR~
                    mblen=2;                                       //~v65mI~
                    errsw=1;	//continue to next input           //~v65mI~
                    UTRACEP("%s:DBCSSPACE ii=%d\n",UTT,ii);//~v65mI~//~v6hhR~//~v6DdR~
                }                                                  //~v65mI~
                else                                               //~v65mI~
                if (UDBCSCHK_ISGB42ND(ch2))                        //~v62UR~
                {                                                  //~v62UR~
                    if (UDBCSCHK_DBCSPAD_ISGB4(pdbcs,ii))          //~v62UR~
                    {                                              //~v62UR~
//                      mbs[0]=ch;                                 //~v62UR~//~v6BhR~
                        mbs[0]=(UCHAR)ch;                          //~v6BhI~
//                      mbs[1]=ch2;                                //~v62UR~//~v6BhR~
                        mbs[1]=(UCHAR)ch2;                         //~v6BhI~
                        mbs[2]=*(pcht+2) & A_CHARTEXT;             //~v62UR~
                        mbs[3]=*(pcht+3) & A_CHARTEXT;             //~v62UR~
                        mblen=4;                                   //~v62UR~
			            dbcssw=3;   //+1--.iconv len               //~v62UR~
UTRACED("gb4sw mbs",mbs,4);                                        //~v62UR~
					}                                              //~v62UR~
                    else                                           //~v62UR~
                    {                                              //~v62UR~
                    	errsw=1;                                   //~v62UR~
                        mblen=min(ii,4);                           //~v62UR~
	                    pcchar->chars[0]=errrep;                   //~v62UR~
                        for (jj=1;jj<mblen;jj++)                   //~v62UR~
  		                  	*(pcchar+jj)=*pcchar;                  //~v62UR~
                    }                                              //~v62UR~
                }//gb4 2nd                                         //~v62UR~
                else                                               //~v62UR~
            	if (ISSS3(ch))                                     //~v62UR~
                {                                                  //~v62UR~
                    if (UDBCSCHK_DBCSPAD_SS3(pdbcs,ii))//dbcstbl="d2" pattern//~v62UR~
                    {                                              //~v62UR~
			            dbcssw=2;   //+1--.iconv len               //~v62UR~
//                      mbs[0]=ch;                                 //~v62UR~//~v6BhR~
                        mbs[0]=(UCHAR)ch;                          //~v6BhI~
//                      mbs[1]=ch2;                                //~v62UR~//~v6BhR~
                        mbs[1]=(UCHAR)ch2;                         //~v6BhI~
                        mbs[2]=*(pcht+2) & A_CHARTEXT;             //~v62UR~
                        mblen=3;                                   //~v62UR~
                    }                                              //~v62UR~
                    else                                           //~v62UR~
                    {                                              //~v62UR~
                    	errsw=1;                                   //~v62UR~
                        mblen=min(ii,3);                           //~v62UR~
	                    pcchar->chars[0]=errrep;                   //~v62UR~
                        for (jj=1;jj<mblen;jj++)                   //~v62UR~
  		                  	*(pcchar+jj)=*pcchar;                  //~v62UR~
                    }                                              //~v62UR~
                }                                                  //~v62UR~
            }//dbcssw                                              //~v62UR~
          if (!errsw)	//no ss3,gb4 length err                    //~v62UR~
          {                                                        //~v62UR~
 	        if (dbcssw>1)  //ss3 or gb4                            //~v62UR~
                ;                                                  //~v62UR~
            else                                                   //~v62UR~
            if (dbcssw)     //2byte dbcs                           //~v62UR~
            {                                                      //~v5n8I~
                if (ii>1)                                          //~v5n8R~
                {                                                  //~v5n8I~
//                  mbs[0]=ch;                                     //~v5n8I~//~v6BhR~
                    mbs[0]=(UCHAR)ch;                              //~v6BhI~
                    ch=*(pcht+1) & A_CHARTEXT;                     //~v5n8I~
//                  mbs[1]=ch;                                     //~v5n8I~//~v6BhR~
                    mbs[1]=(UCHAR)ch;                              //~v6BhI~
                    mblen=2;                                       //~v5n8I~
//#ifdef DDD                                                       //~v62UR~
            	if (mbs[0]==SS2                                    //~v5ntR~
            	&&  UDBCSCHK_ISEUCJ()    //euc(/+utf8)             //~v5ntI~
            	)    //EUC hankaku-katakanakana                    //~v5ntI~
                	hankanasw=1;                                   //~v5ntI~
//#endif                                                           //~v62UR~
                }                                                  //~v5n8I~
                else                                               //~v5n8I~
                {                                                  //~v5n8I~
                    pcchar->chars[0]=errrep;                       //~v5n8I~
                    errsw=1;                                       //~v5n8I~
                }                                                  //~v5n8I~
            }                                                      //~v5n8I~
            else                                                   //~v5n8I~
            if (ch==SS2                                            //~v5n8I~
//          &&  (Gudbcschk_flag & (UDBCSCHK_EUC|UDBCSCHK_UTF8J))   //~v5n8R~//~v5ntR~
//          &&  UDBCSCHK_ISEUCJ()    //euc(/+utf8)                 //~v62UR~
              &&  (Gudbcschk_flag & UDBCSCHK_LANGEUC)    //euc(/+utf8) may not be JP//~v62UR~
            )    //EUC hankaku-katakanakana                        //~v5n8I~
            {      //DDD:this path has no case because hankana is set as dbcs                                                //~v5n8I~//~v5ntR~
                if (ii>1)                                          //~v5n8R~
                {                                                  //~v5n8I~
        	        mbs[0]=(UCHAR)ch;                              //~v5n8I~
                    ch=*(pcht+1) & A_CHARTEXT;                     //~v5n8I~
//                  mbs[1]=ch;                                     //~v5n8R~//~v6BhR~
                    mbs[1]=(UCHAR)ch;                              //~v6BhI~
                    mblen=2;                                       //~v5n8I~
                }                                                  //~v5n8I~
                else                                               //~v5n8I~
                {                                                  //~v5n8I~
                    pcchar->chars[0]=errrep;                       //~v5n8I~
                    errsw=1;                                       //~v5n8I~
                }                                                  //~v5n8I~
            }                                                      //~v5n8I~
            else                                                   //~v5n8I~
#ifdef AAA  //SS3 processed already                                //~v62UR~
            if (ch==SS3                                            //~v5ntR~
//            &&  UDBCSCHK_ISEUCJ()    //euc(/+utf8)               //~v62UR~
              &&  (Gudbcschk_flag & UDBCSCHK_LANGEUC)    //euc(/+utf8) may not be JP//~v62UR~
            )    //EUC 2nd level kanji                             //~v5ntR~
            {                                                      //~v5ntR~
//*AAA                                                             //~v640I~
                if (ii>=3 && *(pdbcs+1)==UDBCSCHK_DBCS1ST)         //~v5ntR~
                {                                                  //~v5ntR~
        	        mbs[0]=(UCHAR)ch;                              //~v5ntR~
                    ch=*(pcht+1) & A_CHARTEXT;                     //~v5ntR~
                    mbs[1]=ch;                                     //~v5ntR~
                    ch=*(pcht+2) & A_CHARTEXT;                     //~v5ntR~
                    mbs[2]=ch;                                     //~v5ntR~
                    mblen=3;      //output 3 cchar                 //~v5ntR~
                    dbcssw=2;    //parm to iconv_local2ucs1(mblen) //~v5ntR~
                }                                                  //~v5ntR~
                else                                               //~v5ntR~
                {                                                  //~v5ntR~
                    pcchar->chars[0]=errrep;                       //~v5ntR~
                    errsw=1;                                       //~v5ntR~
                }                                                  //~v5ntR~
            }                                                      //~v5ntR~
            else                                                   //~v5ntR~
#endif                                                             //~v62UR~
            if (Gpdbcstbl[ch] & UDBCSCHK_TYPEUNP)   //unprintable  //~v5njI~
            {                                                      //~v5njI~
                pcchar->chars[0]=errrep;                           //~v5njI~
                errsw=1;                                           //~v5njI~
            }                                                      //~v5njI~
            else                                                   //~v5njI~
                mbs[0]=(UCHAR)ch;                                  //~v5n8R~
          }//!errsw                                                //~v62UR~
            if (!errsw)                                            //~v5n8I~
            {                                                      //~v5n8I~
//  	    	opt=((dbcssw)?EBC2ASC_STAT_SO:0);                  //~v5n8I~//~v5ntR~
				opt=EBC2ASC_PARMUCVEXT|UCVEXTO_CHARLEN; //len parm is for one char(for 3 byte euc char)//~v5ntI~
			  if (UDBCSCHK_IS_LOCALICU())                          //~v6f3I~
              {                                                    //~v6f3I~
				opt=UCVEXTO_SETSUBCHRC;                            //~v6f3I~
//				rc2=ucvext_icumb2ucs1(opt,*(ULONG*)Sconverters,mbs,dbcssw+1,0/*chklen*/,(UWUCS*)(ULONG)(&ucs));//WUCS is ucs4 on Linux//~v6f3R~//~v6BhR~
  				rc2=ucvext_icumb2ucs1(opt,*(ULONG*)Sconverters,mbs,dbcssw+1,0/*chklen*/,&uwucs);//WUCS is ucs4 on Linux//~v6BhR~
                ucs=(WUCS)uwucs;	//wchar_t <--UINT4             //~v6BhI~
    		  }                                                    //~v6f3I~
              else                                                 //~v6f3I~
                rc2=ucvext_iconvlocal2ucs1(opt,(ULONG)Sconverters,mbs,dbcssw+1,0/*chklen output*/,&ucs);//~v5n8I~
                if (!rc2)                                          //~v635I~
                {                                                  //~v635I~
	                apiwidth=wcwidth(ucs);                         //~v635I~
UTRACEP("UVIOM WCWIDTH=%d,ucs=%08x\n",apiwidth,ucs);               //~v6f3I~
                    if (apiwidth<=0)                               //~v635I~
                    	rc2=8;                                     //~v635I~
                }                                                  //~v635I~
UTRACEP("UVIOM ICONV rc=%d,dbcssw=%d,ucs=%08x,errrep=%x,wcwidth=%d\n",rc2,dbcssw,ucs,errrep,apiwidth);//~v62UR~//~v635R~
                if (rc2)                                           //~v5n8I~
                {                                                  //~v5n8I~
                    pcchar->chars[0]=errrep;                       //~v5n8I~
                    if (mblen>1)    //dbcs or hankana              //~v5n8I~
                    {                                              //~v635I~
//                      *(pcchar+1)=*pcchar;                       //~v5n8R~//~v635R~
                        (pcchar+1)->chars[0]=Guviomdbcspad;        //~v635R~
        				(pcchar+1)->attr=attrdbcspad;              //~v635I~
                    }                                              //~v635I~
                    if (mblen>2)    //SS3+DBCS                     //~v5ntR~
//                      *(pcchar+2)=*pcchar;                       //~v5ntR~//~v635R~
                        *(pcchar+2)=*(pcchar+1);                   //~v635I~
                    if (mblen>3)    //GB4                          //~v62UR~
//                      *(pcchar+3)=*pcchar;                       //~v62UR~//~v635R~
                        *(pcchar+3)=*(pcchar+1);                   //~v635I~
                }                                                  //~v5n8I~
                else                                               //~v5n8I~
                {                                                  //~v5n8I~
//                  width=utfwcwidth(0,ucs,&fontflag);             //~v62UR~//~v6BhR~
                    width=utfwcwidth(0,(ULONG)ucs,&fontflag);      //~v6BhI~
                  if (dbcssw==3) //GB4                             //~v62UR~
                  {                                                //~v62UR~
#ifdef UTF8UCS2                                                    //~v640I~
                    if (fontflag & UTFWWF_F1C1)	//not narrow dbcs(hankana)//~v640R~
                    	width=1;                                   //~v640I~
#endif                                                             //~v640M~
                    if (width==2)                                  //~v62UR~
                    { //               ucs1+ucs2+.+.               //~v62UR~
                    	pcchar->chars[0]=ucs;                      //~v62UR~
                    	*(pcchar+1)=*pcchar;                       //~v62UR~
                    	(pcchar+0)->attr|=1;                       //~v62UR~
                    	(pcchar+1)->attr|=2;                       //~v62UR~
                        if (fontflag & UTFWWF_F2C1)	//curses column=1//~v62UR~
                        {   //          (ucs1+' ')+(ucs2+' ')+.+.  //~v62UR~
#ifdef AAA                                                         //~v62UR~
                    		(pcchar+0)->chars[1]=ucs;  //curses advance 1 column//~v62UR~
                    		(pcchar+1)->chars[1]=ucs;              //~v62UR~
#endif                                                             //~v62UR~
                    		(pcchar+0)->chars[1]=' ';  //curses advance 1 column//~v62UR~
                    		(pcchar+1)->chars[1]=' ';              //~v62UR~
                    	}                                          //~v62UR~
                    	(pcchar+2)->chars[0]=Guviomdbcspad;        //~v62UR~
                    	(pcchar+2)->attr=attrdbcspad;              //~v62UR~
                    	*(pcchar+3)=*(pcchar+2);                   //~v62UR~
                    }                                              //~v62UR~
                    else                                           //~v62UR~
                    if (width==1)                                  //~v62UR~
                    {    //       ucs1+.+.+.                       //~v631R~
                      if (apiwidth==1)//system requires sbcs mode//~v631I~//~v635R~
                      {                                            //~v631I~
                    	(pcchar+0)->chars[0]=ucs;    //uc1+ucs2+(..)//~v631I~
                    	(pcchar+1)->chars[0]=Guviomdbcspad;        //~v631I~
                    	(pcchar+1)->attr=attrdbcspad;              //~v631I~
                    	*(pcchar+2)=*(pcchar+1);                   //~v631I~
                    	*(pcchar+3)=*(pcchar+1);                   //~v631I~
                      }	//wcwidth==1                               //~v631I~
                      else	//wcwidth==2;display width=1 but system requires dbcs mode//~v631I~
                      {                                            //~v631I~
#ifdef AAA                                                         //~v631R~
                    	pcchar->chars[0]=ucs;                      //~v62UR~
                    	pcchar->chars[1]=Guviomdbcspad;            //~v62UR~
                    	*(pcchar+1)=*pcchar;                       //~v62UR~
                    	(pcchar+0)->attr|=1;                       //~v62UR~
                    	(pcchar+1)->attr|=2;                       //~v62UR~
                    	(pcchar+2)->chars[0]=Guviomdbcspad;        //~v62UR~
        				(pcchar+2)->attr=attrdbcspad;              //~v62UR~
                    	*(pcchar+3)=*(pcchar+2);                   //~v62UR~
#else                                                              //~v631I~
                        //ucs1+ucs2+(..)+(.)                       //~v631I~
                    	pcchar->chars[0]=ucs;                      //~v631I~
                    	*(pcchar+1)=*pcchar;                       //~v631I~
                    	(pcchar+0)->attr|=1;                       //~v631I~
                    	(pcchar+1)->attr|=2;                       //~v631I~
                    	(pcchar+2)->chars[0]=Guviomdbcspad;        //~v631I~
//                    	(pcchar+2)->chars[1]=Guviomdbcspad;        //~v631R~
        				(pcchar+2)->attr=attrdbcspad;              //~v631I~
                    	(pcchar+3)->chars[0]=Guviomdbcspad;        //~v631I~
                    	(pcchar+3)->chars[1]=Guviomdbcspad;        //~v631I~
        				(pcchar+3)->attr=attrdbcspad;              //~v631I~
#endif                                                             //~v631I~
                      }                                            //~v631I~
                    }                                              //~v62UR~
                    else//err print 4 errch                        //~v62UR~
                    {                                              //~v62UR~
                    	pcchar->chars[0]=errrep;                   //~v62UR~
	                    *(pcchar+1)=*pcchar;                       //~v62UR~
    	                *(pcchar+2)=*pcchar;                       //~v62UR~
        	            *(pcchar+3)=*pcchar;                       //~v62UR~
                    }                                              //~v62UR~
                  }                                                //~v62UR~
                  else                                             //~v62UR~
//                if (dbcssw>1)	//SS3                              //~v62UR~
                  if (dbcssw==2)    //8fxxxx                       //~v62UR~
                  {                                                //~v5ntR~
UTRACEP("SS3 ucs=%x,width=%d,wcwidth=%d\n",ucs,width,wcwidth(ucs));//~v62XI~
                   if (width==1)//display width=1                  //~v62UR~
                   {                                               //~v62UR~
                    	if (apiwidth==1)//system requires sbcs mode//~v631I~//~v635R~
                    	{                                          //~v631M~
                    (pcchar+0)->chars[0]=ucs;     //ucs+.+.        //~v62UR~
                    (pcchar+1)->chars[0]=Guviomdbcspad;            //~v62UR~
                    (pcchar+1)->attr=attrdbcspad;                  //~v62UR~
                    *(pcchar+2)=*(pcchar+1);                       //~v62UR~
                    	}   //wcwidth=1                            //~v631M~
                    	else	//wcwidth==2;display width=1 but system requires dbcs mode//~v631I~
                    	{                                          //~v631R~
                    		(pcchar+0)->chars[0]=ucs;    //uc1+ucs2+(..)//~v631R~
                    		*(pcchar+1)=*(pcchar+0);               //~v631M~
                    		(pcchar+0)->attr|=1;                   //~v631M~
                    		(pcchar+1)->attr|=2;                   //~v631M~
                    		(pcchar+2)->chars[0]=Guviomdbcspad;    //~v631M~
                    		(pcchar+2)->chars[1]=Guviomdbcspad;    //~v631M~
                    		(pcchar+2)->attr=attrdbcspad;          //~v631M~
                    	}	//wcwidth==2                           //~v631M~
                   }                                               //~v62UR~
                   else                                            //~v62UR~
                   {                                               //~v62UR~
                    (pcchar+0)->chars[0]=ucs;    //uc1+ucs2+.      //~v62UR~
                    *(pcchar+1)=*(pcchar+0);                       //~v62UR~
                    (pcchar+0)->attr|=1;                           //~v62UR~
                    (pcchar+1)->attr|=2;                           //~v62UR~
                    (pcchar+2)->chars[0]=Guviomdbcspad;            //~v62UR~
                    (pcchar+2)->attr=attrdbcspad;                  //~v62UR~
                   }                                               //~v62UR~
                  }                                                //~v5ntR~
                  else                                             //~v5ntR~
                  {                                                //~v5ntR~
                    pcchar->chars[0]=ucs;                          //~v5n8I~
//#ifdef DDD                                                       //~v62UR~
    				if (hankanasw)                                 //~v5ntM~
                    {                                              //~v5ntM~
#ifdef UTF8SUPPH                                                   //~v62UR~
                    	(pcchar+1)->chars[0]=Guviomdbcspad;        //~v62UR~
                    	(pcchar+1)->attr=attrdbcspad;              //~v62UR~
#else                                                              //~v62UR~
                        *(pcchar+1)=*pcchar;                       //~v5ntI~
                        pcchar->chars[0]=errrep;                   //~v5ntR~
#endif                                                             //~v62UR~
                    }                                              //~v5ntM~
                    else                                           //~v5ntI~
//#endif                                                           //~v62UR~
                    if (dbcssw)                                    //~v5n8I~
                    {                                              //~v5n8I~
                    //utfwcwidth may be 1 or 2                     //~v62UR~
                        *(pcchar+1)=*pcchar;                       //~v5n8R~
                      if (width==1                                 //~v62UR~
                      ||  fontflag & UTFWWF_F1C1                   //~v62UR~
                      )                                            //~v62UR~
                      {                                            //~v62UR~
                    	(pcchar+1)->chars[0]=Guviomdbcspad; // sbcs+.//~v62UR~
                        (pcchar+1)->attr=attrdbcspad;              //~v62UR~
                      }                                            //~v62UR~
                      else                                         //~v62UR~
                      {                                            //~v62UR~
                        pcchar->attr|=1;    //1st of dbcs          //~v5n8I~
                        (pcchar+1)->attr|=2;    //1st of dbcs      //~v5n8I~
                      }                                            //~v62UR~
                    }                                              //~v5n8I~
                  }                                                //~v5ntR~
                }                                                  //~v5n8I~
            }//errsw                                               //~v5n8I~
		}//not ascii                                               //~v5n8I~
    }//for                                                         //~v5n8I~
//  outctr=((ULONG)pcchar-(ULONG)Ppcchar)/CCHSZ;                   //~v68eI~//~v6BhR~
    outctr=(int)((ULPTR)pcchar-(ULPTR)Ppcchar)/CCHSZ;              //~v6BhR~
    if (Ppoutctr)                                                  //~v68eI~
    	*Ppoutctr=outctr;                                          //~v68eI~
UTRACED("inp cht",Ppcht,Plen*CCTSZ);                     //~v640R~//~v6hhR~//~v6D9R~
UTRACED("inp dbcs",Ppdbcs,Plen);                         //~v640R~//~v6hhR~//~v6D9R~
UTRACED("out cchar",Ppcchar,Plen*CCHSZ);                 //~v640R~//~v6hhR~//~v6D9R~
    return rc;                                                     //~v5n8I~
}//uviom_cht2cchar                                                 //~v640R~
#endif //CURSESW                                                   //~v5n8R~
#endif //!XXE                                                      //~v5n8I~
#endif  //LNX                                                      //~v5n8I~
#endif //WCSUPP                                                    //~v5n8R~
                                                                   //~v640I~
#ifdef UTF8UCS2                                                    //~v640I~
#ifdef LNX                                                         //~v640I~
#ifndef XXE                                                        //~v640I~
//#ifdef AAA                                                       //~v653R~
////*******************************************************          //~v650I~//~v653R~
////*process combining char                                          //~v650I~//~v653R~
////*ret  :rc 0x01 detected combining char                           //~v650I~//~v653R~
////*******************************************************          //~v650I~//~v653R~
//int uviom_setcombine(int Popt,WUCS Pucs,int Pchsz,chtype *Ppcht,cchar_t *Ppcchar,UCHAR *Ppdbcs,int Plen,int *Ppcombinectr)//~v650R~//~v653R~
//{                                                                  //~v650I~//~v653R~
//    int combinectr=0,ii,attr,rc=0;                                 //~v650R~//~v653R~
//    UCHAR *pdbcs;                                                  //~v650I~//~v653R~
//    chtype  *pcht;                                                 //~v650I~//~v653R~
//    cchar_t *pcchar;                                               //~v650I~//~v653R~
//    WUCS    ucs;                                                   //~v650I~//~v653R~
//    UCHAR ch;                                                      //~v650I~//~v653R~
////**************************                                       //~v650I~//~v653R~
//UTRACEP("setcombine entry chsz=%d,len=%d,ucs=%04x,dbcsid=%x\n",Pchsz,Plen,Pucs,*Ppdbcs);//~v650R~//~v653R~
//    if (Pchsz<0)    //unprintable                                  //~v650R~//~v653R~
//        return 0;                                                  //~v650I~//~v653R~
//    pcchar=Ppcchar;                                                //~v650M~//~v653R~
//    pcht=Ppcht;                                                    //~v650I~//~v653R~
//    if (UDBCSCHK_ISUCSWIDTH0(*Ppdbcs))  //start by width 0,non combinemode or combine count overflow//~v650R~//~v653R~
//    {                                                              //~v650I~//~v653R~
//        ch=*pcht & A_CHARTEXT;                                     //~v650R~//~v653R~
//        ucs=UTF_GETUCSSBCS(&ch,Ppdbcs);                            //~v650I~//~v653R~
//        pcchar->chars[0]=ucs;     //ncurses write if wcrtomb success(See PUTC macro on curses.priv.h)//~v650R~//~v653R~
//        pcchar->attr|=UVIOMATTR_PADDING;         //temporary padding flag//~v650R~//~v653R~
//        combinectr=1-Pchsz; //advance step at caller               //~v650I~//~v653R~
//UTRACEP("setcombine top combine char,ch=%x,ucs=%x\n",ch,ucs);      //~v650R~//~v653R~
//        rc=1;   //processed                                        //~v650R~//~v653R~
//    }                                                              //~v650I~//~v653R~
//    else                                                           //~v650I~//~v653R~
//    if (UTF_COMBINEMODE())                                         //~v650I~//~v653R~
//    {                                                              //~v650I~//~v653R~
//        combinectr=uvio_getcombinectr(0,Pucs,Pchsz,Ppdbcs,Plen);   //~v650R~//~v653R~
//        if (!combinectr)                                           //~v650R~//~v653R~
//        {                                                          //~v650I~//~v653R~
//UTRACEP("setcombine no combine followed\n");                       //~v650I~//~v653R~
//            return 0;                                              //~v650R~//~v653R~
//        }                                                          //~v650I~//~v653R~
//        pcchar->chars[0]=Pucs;                                     //~v650R~//~v653R~
//        for (pcht=Ppcht+1,pdbcs=Ppdbcs+Pchsz,ii=1;ii<=combinectr;ii++,pcht++)//~v653R~
//        {                                                          //~v650R~//~v653R~
//            ch=*pcht & A_CHARTEXT;                                 //~v650R~//~v653R~
//            ucs=UTF_GETUCSSBCS(&ch,pdbcs);                         //~v650R~//~v653R~
//            pcchar->chars[ii]=ucs;                                 //~v650R~//~v653R~
//        }                                                          //~v650R~//~v653R~
//        if (Pchsz==2)   //dbcs                                     //~v650R~//~v653R~
//        {                                                          //~v650R~//~v653R~
//            *(pcchar+1)=*pcchar;                                   //~v650R~//~v653R~
//            pcchar->attr|=UVIOMATTR_DBCS1;         //temporary padding flag//~v653R~
//            pcchar++;                                              //~v650R~//~v653R~
//            pcchar->attr|=UVIOMATTR_DBCS2;         //temporary padding flag//~v653R~
//        }                                                          //~v650R~//~v653R~
//        attr=(*(Ppcht+Pchsz) & ~(A_CHARTEXT))>>8;                //~v653R~
//        attr=UVIOM_ATTRBG(attr)/*bg*/|UVIOM_PADATTR/*fg*/;       //~v653R~
//        attr<<=8;                                                //~v653R~
//        attr|=UVIOMATTR_PADDING;         //temporary padding flag//~v653R~
//        for (pcchar++,ii=0;ii<combinectr;ii++,pcchar++)            //~v650R~//~v653R~
//        {                                                          //~v650R~//~v653R~
//            pcchar->attr=attr;                                     //~v650R~//~v653R~
//            pcchar->chars[0]=Guviomdbcspad; //PADDING              //~v650R~//~v653R~
//        }                                                          //~v650R~//~v653R~
//        rc=1;                                                      //~v650I~//~v653R~
//    }                                                              //~v650I~//~v653R~
//    *Ppcombinectr=combinectr;                                      //~v650I~//~v653R~
//UTRACEP("setcombine rc=%d,chsz=%d,len=%d,ucs=%04x,combinectr=%d\n",rc,Pchsz,Plen,Pucs,combinectr);//~v650R~//~v653R~
//UTRACED("setcombine",Ppcchar,(combinectr+Pchsz)*sizeof(cchar_t));//~v653R~
//    return rc;                                                     //~v650R~//~v653R~
//}//uviom_setcombine                                                //~v650I~//~v653R~
//#else   //for performance ;called only whe combining char detected//~v653R~
//*******************************************************          //~v653I~
//*display combine char as it is                                   //~v653I~
//*******************************************************          //~v653I~
//int uviom_setcombine1(int Popt,WUCS Pucs,WUCS Pucsbase,chtype *Ppcht,cchar_t *Ppcchar)//~v653I~//~v6EmR~
int uviom_setcombine1(int Popt,int Plineopt,WUCS Pucs,WUCS Pucsbase,chtype *Ppcht,cchar_t *Ppcchar)//~v6EmI~
{                                                                  //~v653I~
//  int attr,attropt;                                                      //~v653I~//~v656R~//~v6BhR~
    int attropt;                                                   //~v6BhI~
    attr_t attr;                                                   //~v6BhI~
#define UVIOM_DUMMYBASE  0xfeff //0x00a0 //0x200b                  //~v658R~
//************************                                         //~v653I~
UTRACEP("%s:entry ucs=%04x,ucsbase=%04x\n",UTT,Pucs,Pucsbase);     //~v6D9I~
	attropt=Popt & UVIOMATTR_BREAK;                                //~v656I~
  if (Popt & UVIOMATTR_SETATTR)   //for the case ligature not combine mode//~v656I~
  {                                                                //~v656I~
//  attr=(*Ppcht & ~(A_CHARTEXT))>>8;                              //~v653I~//~v6D9R~
//	attr=UVIOM_ATTRBG(attr)|UVIOM_PADATTR;                         //~v656R~//~v6D9R~
   if (COMBINEMODE(Plineopt))                                      //~v6EmI~
	attr=uviom_set_padattr(0,*Ppcht & A_COLOR)>>8;                 //~v6D9R~
   else                                                            //~v6EmI~
   {                                                               //~v6EmI~
    attr=(attr_t)uviol_repfg((int)*Ppcht,ATTR_COMBINENP_FG);       //~v6EmR~
    UTRACEP("%s:attr rep=%04x\n",UTT,attr);                        //~v6EmR~
   }                                                               //~v6EmI~
  }                                                                //~v6EmM~
  else                                                             //~v656I~=
    attr=(*Ppcht & ~(A_CHARTEXT))>>8;                              //~v656I~
                                                                   //~v656I~
//  Ppcchar->attr=(attr<<8)|attropt;//break flag                   //~v656I~//~v6BhR~
    Ppcchar->attr=(attr<<8)|(attr_t)attropt;//break flag           //~v6BhI~
//  if (!UVIOM_NONSPACECOMBINEMODE()) //fc5                          //~v656R~//~v658R~
//	Ppcchar->chars[0]=Pucs; // Guviomdbcspad;                               //~v656I~//~v658R~
//  else                                                             //~v656I~//~v658R~
//  if (!(Popt & UVIOMATTR_BREAK))   //not around csr column         //~v656R~//~v658R~
//    Ppcchar->chars[0]=Guviomdbcspad;                               //~v656I~//~v658R~
//  else                                                             //~v656I~//~v658R~
  if (Popt & UVIOMATTR_BASEDBCS) //base is dbcs                    //~v658I~
  {                                                                //~v658I~
    Ppcchar->chars[0]=Guviomdbcspad;                               //~v658I~
  }                                                                //~v658I~
  else                                                             //~v658I~
  if (UTF_COMBINABLE(Pucsbase))                                    //~v656R~
  {                                                                //~v656I~
//   if (!UVIOM_NONSPACECOMBINEMODE()) //fc5                       //~v658R~
   if (Scombaltch==UVIOM_ALTCHPADDING)                             //~v658I~
	Ppcchar->chars[0]=Guviomdbcspad;                               //~v658I~
   else                                                            //~v658I~
   if (Scombaltch==UVIOM_ALTCHSHADOW)                              //~v658I~
   {                                                               //~v658I~
    Ppcchar->chars[0]=Pucsbase;	//shadow base                                         //~v653I~//~v652R~//~v656I~//~v658R~
//  Ppcchar->chars[0]=UVIOM_DUMMYBASE;                             //~v658R~
    Ppcchar->chars[1]=Pucs;     //combining char                                   //~v653I~//~v656I~
    Ppcchar->attr|=UVIOMATTR_SHADOW;                               //~v65bR~
   }                                                               //~v658I~
   else                                                            //~v658I~
   if (Scombaltch==UVIOM_ALTCHITSELF)                              //~v658R~
   {                                                               //~v6EmI~
    Ppcchar->chars[0]=Pucs;     //combining char itself            //~v658I~
   if (!(Plineopt & UVIOO_CSRPOSCHK))       // file data line      //~v6EnR~
    Ppcchar->attr=uviom_attr_itself(Plineopt,*Ppcht)|(attr_t)attropt;//~v6EnR~
   }                                                               //~v6EmI~
   else                                                            //~v658I~
   if (UTF_COMBINEMODE())   //entered to combine1 by lineopt,same as itself//~v6EnI~
   {                                                               //~v6EnI~
    Ppcchar->chars[0]=Pucs;     //combining char itself            //~v6EnI~
   if (!(Plineopt & UVIOO_CSRPOSCHK))       // file data line      //~v6EnR~
    Ppcchar->attr=uviom_attr_itself(Plineopt,*Ppcht)|(attr_t)attropt;//~v6EnI~
   }                                                               //~v6EnI~
   else                                                            //~v6EnI~
    Ppcchar->chars[0]=Scombaltch;     //combining char special parm//~v658I~
  }                                                                //~v656I~
  else                                                             //~v656I~
  if (Pucsbase<0x80)    //not combinable ascii                     //~v656R~
  {                                                                //~v656I~
    Ppcchar->chars[0]=Guviomdbcspad;                               //~v656I~
  }                                                                //~v656I~
  else                                                             //~v656I~
    Ppcchar->chars[0]=Pucs;                                        //~v653M~
UTRACEP("%s:single combine parm=%x,opt=%x,char ucs=%x,prevucs=%x,chtype=%x\n",UTT,Scombaltch,Popt,Pucs,Pucsbase,*Ppcht);           //~v653I~//~v656R~//~v658R~//~v6BZR~
UTRACED("out Ppcchar",Ppcchar,CCHSZ);                      //~v653R~//~v6BZR~
    return 0;                                                      //~v653R~
}//uviom_setcombine1                                               //~v653I~
//*******************************************************          //~v653I~
//*process combining char                                          //~v653I~
//*ret  :rc 0x01 detected combining char                           //~v653I~
//*******************************************************          //~v653I~
//int uviom_setcombine(int Popt,WUCS Pucs,chtype *Ppcht,cchar_t *Ppcchar0,cchar_t *Ppcchar,UCHAR *Ppdbcs,int Plen,int *Ppcombinectr,int *Ppwritectr)//~v653R~//~v6EmR~
int uviom_setcombine(int Popt,int Plineopt,WUCS Pucs,chtype *Ppcht,cchar_t *Ppcchar0,cchar_t *Ppcchar,UCHAR *Ppdbcs,int Plen,int *Ppcombinectr,int *Ppwritectr)//~v6EmI~
{                                                                  //~v653I~
//  int combinectr=0,ii,attr,rc=0,outctr=0,dbcssw=0,dbcssz,opt;    //~v653R~//~v6BhR~
    int combinectr=0,ii,rc=0,outctr=0,dbcssw=0,dbcssz,opt;         //~v6BhI~
//  int attro,attrn;                                               //~v656I~//~v6BhR~
    attr_t attr,attro,attrn;                                       //~v6BhI~
    int setbreak=0;                                                //~v656I~
    UCHAR *pcd;                                                    //~v653I~
    chtype  *pct;                                                  //~v653I~
    cchar_t *pcc,*pccpadd,*pccprev;                                         //~v653R~//~v656R~
    WUCS    ucs,prevucs=0;                                           //~v653I~//~v656R~
    UCHAR ch;                                                      //~v653I~
//**************************                                       //~v653I~
UTRACEP("setcombine entry opt=%x,len=%d,ucs=%04x,dbcsid=%x\n",Popt,Plen,Pucs,*Ppdbcs);//~v653R~//~v656R~
	pcc=Ppcchar;	//output                                       //~v653R~
	pct=Ppcht;	//input                                            //~v653I~
	pcd=Ppdbcs;                                                    //~v653I~
    for (;;)                                                       //~v653I~
    {                                                              //~v653I~
    	if (pcc==Ppcchar0                                          //~v656R~
        ||  (Popt & UVIOMSCO_FORCEBREAK)                           //~v656I~
        ||  ((pcc-1)->attr & UVIOMATTR_BREAK)   //prev is single combine//~v656I~
    	)                                                          //~v656I~
        {                                                          //~v656I~
        	setbreak=1;                                            //~v656I~
        	break;                                                 //~v656I~
        }                                                          //~v656I~
//    	if (UVIOM_SPLITMODE())                                     //~v656M~//~v658R~
//  	if (!UTF_COMBINEMODE())	//split mode                       //~v658I~//~v6EmR~
    	if (!COMBINEMODE(Plineopt))	//split mode                   //~v6EmI~
        {                                                          //~v6EnI~
        	setbreak=1;	//keep colomn for Altch especially ITSELF mode//~v6EnI~
        	break;                                                 //~v656M~
        }                                                          //~v6EnI~
    	pcc--;                                                     //~v653I~
        pct--;                                                     //~v653I~
        pcd--;                                                     //~v653I~
        dbcssw=((pcc->attr & UVIOMATTR_DBCS2)!=0);         //temporary padding flag//~v653I~//~v656R~
        if (dbcssw)                                                //~v653I~
        {                                                          //~v653I~
        	pcc--;                                                 //~v653I~
            pct--;                                                 //~v653I~
            pcd--;                                                 //~v653I~
        }                                                          //~v653I~
        dbcssz=1+dbcssw;                                           //~v653I~
        prevucs=pcc->chars[0];                                     //~v653I~
//#ifdef WWW                                                         //~v6BYI~//~v6BZR~
        combinectr=uvio_getcombinectr(0,prevucs,dbcssz,pcd,Plen);//~v653I~//~v656R~
//#else                                                              //~v6BYI~//~v6BZR~
//        combinectr=uvio_getcombinectr(0,prevucs,dbcssz,pct,pcd,Plen);//~v6BYI~//~v6BZR~
//#endif                                                             //~v6BYI~//~v6BZR~
        attro=(*pct & (A_ATTRIBUTES));                             //~v656R~
        for (pct=Ppcht,ii=0;ii<combinectr;ii++,pct++)              //~v656I~
        {                                                          //~v656I~
	        attrn=(*pct & (A_ATTRIBUTES));                         //~v656R~
UTRACEP("setcombine combctr=%d,attro=%x,attrn=%x\n",ii,attro,attrn);//~v656I~
            if (attrn!=attro)                                      //~v656R~
            {                                                      //~v656I~
            	combinectr=ii;                                     //~v656R~
            	break;                                             //~v656I~
            }                                                      //~v656I~
        }                                                          //~v656I~
        if (!combinectr)                                           //~v653I~
        	break;                                                 //~v653I~
//set combine to base char                                         //~v658I~
        for (pct=Ppcht,pccpadd=Ppcchar,pcd=Ppdbcs,ii=1;ii<=combinectr;ii++,pcd++,pct++)//~v653R~
        {                                                          //~v653I~
            ch=*pct & A_CHARTEXT;                                  //~v653I~
//          ucs=UTF_GETUCSSBCS(&ch,pcd);                           //~v653I~//~v6BhR~
            ucs=(WUCS)UTF_GETUCSSBCS(&ch,pcd);                     //~v6BhI~
            pcc->chars[ii]=ucs;                                    //~v653I~
            if (dbcssw)                                            //~v653I~
	            (pcc+1)->chars[ii]=ucs;                            //~v653I~
//add padding char                                                 //~v656I~//~v658R~
          if (UVIOM_NONSPACECOMBINEMODE()) //non spacing combining diacritical mark supported//~v656R~
          {                                                        //~v656I~
//	        attr=(*pct & ~(A_ATTRIBUTES))>>8;                      //~v656R~//~v6D9R~
//	    	attr=UVIOM_ATTRBG(attr)/*bg*/|UVIOM_PADATTR/*fg*/;     //~v653I~//~v6D9R~
//          attr<<=8;                                              //~v6D9I~
  	        attr=(*pct & A_ATTRIBUTES);                            //~v6D9I~
	    	attr=uviom_set_padattr(0,attr);                        //~v6D9R~
        	attr|=UVIOMATTR_PADDING;         //temporary padding flag//~v653I~
            pccpadd->attr=attr;	//padding attr                     //~v653R~
            pccpadd->chars[0]=Guviomdbcspad; //PADDING             //~v653R~
            pccpadd++;                                             //~v653R~
            outctr++;                                              //~v653R~
          }//fc5 need 1 column for nonspace char                   //~v656I~
        }                                                          //~v653I~
UTRACED("setcombine",Ppcchar-dbcssz,(outctr+dbcssz)*(int)sizeof(cchar_t));//~v653R~//~v6BhR~
        rc=1;                                                      //~v653I~
        break;                                                     //~v653I~
    }                                                              //~v653I~
    if (!rc)                                                       //~v653I~
    {                                                              //~v653I~
    	opt=0;                                                     //~v653I~
        if (setbreak)                                              //~v656R~
	        opt|=UVIOMATTR_BREAK;                                  //~v653I~
//      if (Popt & UVIOMSCO_SETATTR)                               //~v656I~//~v658R~
//      if (UTF_COMBINEMODE())	//f23 set green if split mode      //~v658I~//~v6EmR~
//      if (COMBINEMODE(Plineopt))	//f23 set green if split mode  //~v6EmR~
      	  if (!(Popt & UVIOMSCO_NOSETATTR))                        //~v658I~
	        opt|=UVIOMATTR_SETATTR;	//set fg:green                 //~v656M~
        for (pccprev=Ppcchar-1;pccprev>=Ppcchar0;pccprev--)        //~v656I~
        {                                                          //~v656I~
            prevucs=pccprev->chars[0];                             //~v656I~
        	if (UTF_COMBINABLE(prevucs))                           //~v656R~
            {                                                      //~v658I~
                if (pccprev->attr & UVIOMATTR_DBCS12)  //dbcs      //~v658R~
					opt|=UVIOMATTR_BASEDBCS;                       //~v658I~
                break;                                             //~v656I~
            }                                                      //~v658I~
            prevucs=0;                                             //~v656I~
        }                                                          //~v656I~
//      uviom_setcombine1(opt,Pucs,prevucs,Ppcht,Ppcchar);                 //~v653R~//~v6EmR~
        uviom_setcombine1(opt,Plineopt,Pucs,prevucs,Ppcht,Ppcchar);//~v6EmI~
        combinectr=1;   //loop ctr;                                //~v653R~
        outctr=1;                                                  //~v653I~
    }                                                              //~v653I~
    *Ppcombinectr=combinectr;                                      //~v653R~
    *Ppwritectr=outctr;                                            //~v653R~
UTRACEP("setcombine rc=%d,len=%d,ucs=%04x,combinectr=%d,dbcssw=%d,outctr=%d\n",rc,Plen,Pucs,combinectr,dbcssw,outctr);//~v653R~
    return rc;                                                     //~v653I~
}//uviom_setcombine                                                //~v653I~
//#endif                                                           //~v653R~
//*******************************************************          //~v640I~
//*chtype->cchar_t from DD fmt source                              //~v640I~
//*ret  :rc 0x01:esc found,0x02:non ascii found                    //~v640I~
//*******************************************************          //~v640I~
//int uvio_ddcht2cchar(int Popt,chtype *Ppcht,UCHAR *Ppdbcs,int Plen,cchar_t *Ppcchar,int *Ppoutctr)//~v640R~//~v653R~
//int uvio_ddcht2cchar(int Popt,chtype *Ppcht,UCHAR *Ppdbcs,int Plen,cchar_t *Ppcchar,int Prow,int Pcol,int *Ppoutctr)//~v653I~//~v6EmR~
int uvio_ddcht2cchar(int Popt,int Plineopt,chtype *Ppcht,UCHAR *Ppdbcs,int Plen,cchar_t *Ppcchar,int Prow,int Pcol,int *Ppoutctr)//~v6EmI~
{                                                                  //~v640I~
//  int ii,rc=0,mblen,/*dbcssw,*/errrep,ch,attr,chsz,ucssbcsctr=0,ucsdbcsctr=0;//~v640R~//~v6b9R~//~v6BhR~
    int ii,rc=0,mblen,/*dbcssw,*/errrep,ch,chsz,ucssbcsctr=0,ucsdbcsctr=0;//~v6BhI~
    attr_t attr;                                                   //~v6BhI~
//  int swbreak,attro=0,opt;                                         //~v653R~//~v6h9R~//~v6BhR~
    int swbreak,opt;                                               //~v6BhI~
    attr_t attro=0;                                                //~v6BhI~
    int posb=-1,posc=-1,posa=-1,swcsrline,col;                     //~v653R~
    int posbvhex=-1,poscvhex=-1,/*swvhexcsrbreak,*/swvhexcsrline;      //~v658R~//~v6b9R~
    int apiwidth,outctr;                                           //~v640R~
    int combinectr;                                                //~v650I~
    cchar_t *pcchar;                                               //~v640I~
    chtype  *pcht;                                                 //~v640I~
    UCHAR *pdbcs;                                                  //~v640R~
    WUCS    ucs;                                                   //~v640R~
    int writectr;                                                  //~v653I~
    int jj,reslen;                                                 //~v656R~
    UCHAR dbcswk[2],dbcsid;                                        //~v640R~
    int altch;                                                     //~v65iI~
    int swdbcsspace;                                               //~v65mI~
    int swaltsbcs;                                                 //~v65pI~
//#ifdef WWW                                                         //~v6BYI~//~v6BZR~
//#else                                                              //~v6BYI~//~v6BZR~
//    char chcombine;                                                //~v6BYI~//~v6BZR~
//#endif                                                             //~v6BYI~//~v6BZR~
//*********************************                                //~v640I~
    UTRACEP("ddcht2cchar row=%d,csr=%d\n",Prow,Scsrposy);          //~v653I~
UTRACED("cht2cchar inp cht",Ppcht,Plen*CCTSZ);                     //~v640I~//~v6DhM~
UTRACED("cht2cchar inp dbcs",Ppdbcs,Plen);                         //~v640I~//~v6DhM~
  if (Plineopt & UVIOO_CSRPOSCHK)       // file data line          //~v6EnR~
  {                                                                //~v6EmI~
	if ((swcsrline=(Prow==Scsrposy))                               //~v653I~
    &&  (Scsrposx>=Pcol && Scsrposx<Pcol+Plen)	//csr line         //~v653I~
    )                                                              //~v653I~
    {                                                              //~v653I~
		utfddgetcsrposbca(0,Ppdbcs,Plen+Pcol,Scsrposx,&posb,&posc,&posa);//~v653R~
    }                                                              //~v653I~
	if ((swvhexcsrline=(Prow==Svhexcsrposy))                       //~v658I~
    &&  (Svhexcsrposx>=Pcol && Svhexcsrposx<Pcol+Plen)	//csr line //~v658I~
    )                                                              //~v658I~
    {                                                              //~v658I~
		utfddgetcsrposbca(0,Ppdbcs,Plen+Pcol,Svhexcsrposx,&posbvhex,&poscvhex,0/*after*/);//~v658R~
    }                                                              //~v658I~
  }                                                                //~v6EmI~
    errrep=UVIO_ERRREP;                                            //~v640I~
    col=Pcol;                                                      //~v653I~
    for (pcchar=Ppcchar,ii=Plen,pdbcs=Ppdbcs,pcht=Ppcht;           //~v640I~
    			ii>0;                                              //~v640I~
                col+=mblen,                                        //~v653I~
				ii-=mblen,pcht+=mblen,pcchar+=mblen,pdbcs+=mblen)  //~v640I~
    {                                                              //~v640I~
	    ch=*pcht & A_CHARTEXT;                                     //~v640I~
        attr=*pcht & ~(A_CHARTEXT);                                //~v640I~
//  	dbcssw=0;                                                  //~v640I~//~v6b9R~
        swdbcsspace=0;                                             //~v65mI~
        swaltsbcs=0;                                               //~v65pI~
        chsz=1;                                                    //~v640I~
        dbcsid=*pdbcs;                                             //~v640I~
    	if (UDBCSCHK_ISUCSSBCS(dbcsid))                            //~v640R~
        {                                                          //~v640I~
//        	dbcswk[0]=ch;                                          //~v640I~//~v6BhR~
          	dbcswk[0]=(UCHAR)ch;                                   //~v6BhI~
//      	ucs=UTF_GETUCSSBCS(dbcswk,pdbcs);                      //~v640R~//~v6BhR~
        	ucs=(WUCS)UTF_GETUCSSBCS(dbcswk,pdbcs);                //~v6BhI~
            ucssbcsctr++;                                          //~v640I~
        }                                                          //~v640I~
        else                                                       //~v640I~
//  	if (UDBCSCHK_DBCS1STUCS2NW(dbcsid))//usual, narrow and wide dbcs//~v640R~//~v6DaR~
//    	if (UDBCSCHK_DBCS1STUCS2NWP(dbcsid))//usual, narrow and wide dbcs//~v6DaI~//~v6DdR~
      	if (UDBCSCHK_DBCS1STUCS2NW(dbcsid))//usual, narrow and wide dbcs;NP contains dbcsspace for utf8 file//~v6DdI~
        {                                                          //~v640I~
        	if (ii==1)	//split by EOL                             //~v640R~
            	chsz=-1;	//errid                                //~v640I~
            else                                                   //~v640I~
            {                                                      //~v640I~
//          	dbcssw=1;                                          //~v640I~//~v6b9R~
//          	dbcswk[0]=ch;                                      //~v640I~//~v6BhR~
            	dbcswk[0]=(UCHAR)ch;                               //~v6BhI~
            	dbcswk[1]=*(pcht+1) & A_CHARTEXT;                  //~v640I~
        		ucs=UTF_GETUCSDBCS(dbcswk);                        //~v640R~
            	ucsdbcsctr++;                                      //~v640I~
            	chsz=2;                                            //~v640I~
#ifndef SSS                                                        //~v6DhI~
    			if (ucs==DBCSSPACE_ALT2   //ffff                   //~v6DhI~
		        &&  dbcsid==UDBCSCHK_DBCS1STUCS)	//tabdisplay set ffff/() for dbcsspace//~v6DhI~
          		{                                                  //~v6DhI~
          			swdbcsspace=1;                                 //~v6DhI~
          			ucs=UTF_GETALTCH_DBCS();                       //~v6DhI~
            	}                                                  //~v6DhI~
#endif //SSS                                                       //~v6DhI~
            }                                                      //~v640I~
        }                                                          //~v640I~
        else                                                       //~v640I~
#ifdef UTF8UCS4                                                    //~v65cI~
//*LNX                                                             //~v6uBI~
    	if (UDBCSCHK_ISUCSOVF1ST(dbcsid))                          //~v65cI~
        {                                                          //~v65cI~
        	if (ii==1)	//split by EOL                             //~v65cI~
            	chsz=-1;	//errid                                //~v65cI~
            else                                                   //~v65cI~
            {                                                      //~v65cI~
//          	dbcssw=1;                                          //~v65cI~//~v6b9R~
//          	dbcswk[0]=ch;                                      //~v65cI~//~v6BhR~
            	dbcswk[0]=(UCHAR)ch;                               //~v6BhI~
            	dbcswk[1]=*(pcht+1) & A_CHARTEXT;                  //~v65cI~
        		ucs=UTF_GETUCSDBCSOVF(dbcswk,pdbcs);               //~v65cI~
            	ucsdbcsctr++;                                      //~v65cI~
            	chsz=2;                                            //~v65cI~
            }                                                      //~v65cI~
        }                                                          //~v65cI~
        else                                                       //~v65cI~
#endif                                                             //~v65cI~
#ifdef UTF8UCS4                                                    //~v65cI~
//*LNX                                                             //~v6uBI~
    	if (UDBCSCHK_DBCS2NDUCS2NWO(dbcsid))   //dbcs split at TOL or invalid fmt//~v65cI~
#else                                                              //~v65cI~
    	if (UDBCSCHK_DBCS2NDUCS2NW(dbcsid))   //dbcs split at TOL or invalid fmt//~v640R~
#endif                                                             //~v65cI~
        {                                                          //~v640I~
            chsz=-1;	//errid                                    //~v640I~
        }                                                          //~v640I~
        else                                                       //~v640I~
        {                                                          //~v65mI~
#ifdef SSS                                                         //~v6DhI~
          if (ch==DEFAULT_ALTCH		//default DBCSSPACE alt ch     //~v65nR~
          &&  UDBCSCHK_ISUCSNP1ST(dbcsid) //NP set by tabdisplay   //~v65mI~
          && ii+1<Plen                                             //~v65mI~
          &&  (*(pcht+1) & A_CHARTEXT)==DEFAULT_ALTCH //ffff       //~v65nR~
//        && ((altch=utfgetvisiblealtch(0,ch))>0)                  //~v65nR~
          && ((altch=UTF_GETALTCH_DBCS())>0)                       //~v65nI~
          )                                                        //~v65mI~
          {                                                        //~v65mI~
//          dbcssw=1;                                              //~v65mI~//~v6b9R~
            chsz=2;                                                //~v65mI~
          	swdbcsspace=1;                                         //~v65mI~
            ucs=altch;                                             //~v65mI~
          }                                                        //~v65mI~
          else                                                     //~v65mI~
#endif                                                             //~v6DhI~
//          if (UDBCSCHK_ISUCSNP1ST(dbcsid) //NP set by tabdisplay //~v6DdR~
//          && ((altch=UTF_GETALTCH_DBCS())>0)                     //~v6DdR~
//          )                                                      //~v6DdR~
//          {                                                      //~v6DdR~
//            chsz=2;                                              //~v6DdR~
//            ucs=altch;                                           //~v6DdR~
//          }                                                      //~v6DdR~
//          else                                                   //~v6DdR~
          {                                                        //~v65pI~
            if (ch==DEFAULT_ALTCH)//0xff                           //~v65pI~
            {                                                      //~v65pI~
                altch=UTF_GETALTCH_SBCS(dbcsid);                   //~v65pI~
                if (altch>0)                                       //~v65pI~
                {                                                  //~v65pI~
                    swaltsbcs=1;                                   //~v65pI~
                    ch=altch;                                      //~v65pI~
                }                                                  //~v65pI~
            }                                                      //~v65pI~
        	ucs=ch;                                                //~v640R~
          }                                                        //~v65pI~
        }                                                          //~v65mI~
        mblen=chsz;                                                //~v640I~
        if (chsz<0) //err data                                     //~v640I~
        {                                                          //~v640I~
            mblen=1;                                               //~v640I~
            ucs=errrep;    //display "."                           //~v640I~
        }                                                          //~v640I~
        ch=ucs;                                                    //~v640I~
        pcchar->attr=attr;                                         //~v640I~
        swbreak=(ii!=Plen && attr!=attro);                         //~v653I~//~v656R~
        UTRACEP("ddcht2cchar ii=%d,col=%d,ucs=%x,attr=%x,attro=%x,swbreak=%d\n",ii,col,ch,attr,attro,swbreak);//~v653R~
        attro=attr;                                                //~v653I~
        if (!ch)                                                   //~v640I~
            pcchar->chars[0]=' ';    //null is used not only file area but anywhere//~v640I~
        else                                                       //~v640I~
//     	if (uviom_setcombine(0,ucs,chsz,pcht,pcchar,pdbcs,ii,&combinectr))//~v653I~
//#ifdef WWW                                                         //~v6BYI~//~v6BZR~
        if (UDBCSCHK_ISUCSWIDTH0(dbcsid))                          //~v653R~
//#else                                                              //~v6BYI~//~v6BZR~
//        if (UTF_ISUCSWIDTH0(ucs))                                  //~v6BYI~//~v6BZR~
//#endif                                                             //~v6BYI~//~v6BZR~
        {                                                          //~v650I~
//          opt=UVIOMSCO_SETBREAKIFTOP;                            //~v653I~//~v658R~
            opt=0;                                                 //~v658I~
//          swvhexcsrbreak=0;                                      //~v658I~//~v6b9R~
            reslen=ii;                                             //~v656I~
//          if (swcsrline && UVIOM_NONSPACECOMBINEMODE())//not fc5 //~v656R~//~v658R~
//          if (swcsrline)                                         //~v658R~
            if (swcsrline||swvhexcsrline)                          //~v658I~
            {                                                      //~v656I~
            	for (combinectr=0;combinectr<UVIOM_MAXCOMBINE;combinectr++)//~v656R~
                {                                                  //~v656I~
//#ifdef WWW                                                         //~v6BYI~//~v6BZR~
			        if (!UDBCSCHK_ISUCSWIDTH0(*(pdbcs+combinectr)))//~v656R~
//#else                                                              //~v6BYI~//~v6BZR~
//                    chcombine=(char)(*(pcht+combinectr) & A_CHARTEXT);//~v6BYI~//~v6BZR~
//                    if (!UDBCSCHK_ISDDWIDTH0(&chcombine,pdbcs+combinectr,1,0))//~v6BYI~//~v6BZR~
//#endif                                                             //~v6BYI~//~v6BZR~
                    	break;                                     //~v656I~
                    jj=col+combinectr;                             //~v656I~
		            if (jj==posb||jj==posc||jj==posa)              //~v656R~
                      if (swcsrline)                               //~v658I~
                    	break;                                     //~v656I~
		            if (jj==poscvhex||jj==posbvhex)                //~v658R~
						if (swvhexcsrline)                         //~v658I~
                        {                                          //~v658R~
				            if (jj==poscvhex)                      //~v658I~
	                            opt|=UVIOMSCO_NOSETATTR;    //avoid set attr for vhex pos//~v658R~
                            break;                                 //~v658R~
                        }                                          //~v658R~
                }                                                  //~v656I~
                if (combinectr)                                    //~v656I~
                	reslen=combinectr; //combine limit             //~v656I~
                else                                               //~v656I~
                	swbreak=1;	//set FORCEBREAK;                  //~v656I~
            	UTRACEP("csrbreakchk col=%d,combinectr=%d\n",col,combinectr);//~v656I~
            }                                                      //~v656M~
        	if (swbreak)                                           //~v653R~
            	opt|=UVIOMSCO_FORCEBREAK;                          //~v656R~
//          else                                                   //~v656I~//~v658R~
//          	opt|=UVIOMSCO_SETATTR;	//by csr column            //~v656I~//~v658R~
//  		uviom_setcombine(opt,ucs,pcht,Ppcchar,pcchar,pdbcs,reslen,&combinectr,&writectr);//~v656R~//~v6EmR~
    		uviom_setcombine(opt,Plineopt,ucs,pcht,Ppcchar,pcchar,pdbcs,reslen,&combinectr,&writectr);//~v6EmI~
        	mblen=combinectr;                                      //~v653R~
            pcchar+=writectr-mblen; //mblen for loop ctl           //~v656R~
        	rc|=UVIOMCCRC_NONASCII|UVIOMCCRC_COMBINE;              //~v650I~
        }                                                          //~v650I~
        else                                                       //~v650I~
        if (swdbcsspace)                                           //~v65mI~
        {                                                          //~v65mI~
    	    pcchar->chars[0]=ch;                                   //~v65mI~
            *(pcchar+1)=*pcchar;                                   //~v65mI~
//#ifndef SSS                                                      //~v6DhR~
//            (pcchar+1)->chars[0]=' ';                            //~v6DhR~
//#endif                                                           //~v6DhR~
            UTRACEP("%s:DBCSSPACE\n",UTT);                                //~v65mI~//~v6DhR~
        }                                                          //~v65mI~
        else                                                       //~v65mI~
        if (ch<0x80)                                               //~v640I~
        {                                                          //~v640I~
        	if (ch<0x20)                                           //~v65iI~
            	if ((altch=UTF_GETALTCH_CTL(ch))>0)                //~v65nR~
            		ch=altch;                                      //~v65iI~
          if (ch<0x80)//after altch conversion                     //~v65iI~
            if (Gpdbcstbl[ch] & UDBCSCHK_TYPEUNP)   //unprintable  //~v640I~
            	ch=errrep;                                         //~v640I~
    	    pcchar->chars[0]=ch;                                   //~v640I~
            if (ch==0x1b)                                          //~v640I~
	        	rc|=UVIOMCCRC_ESC;                                 //~v640I~
        }                                                          //~v640I~
        else                                                       //~v640I~
        {                                                          //~v640I~
        	rc|=UVIOMCCRC_NONASCII;                                //~v640I~
            if (swaltsbcs)                                         //~v65pI~
                pcchar->chars[0]=ch;                               //~v65pI~
            else                                                   //~v65pI~
//          if (ch <0x100 && Gpdbcstbl[ch] & UDBCSCHK_TYPEUNP)   //unprintable//~v640I~//~v6DaR~
            if (ch <0x100 && Gpdbcstbl[ch] & UDBCSCHK_TYPEUNP   //unprintable//~v6DaI~
            &&  !UDBCSCHK_ISUCSNP1ST(dbcsid))   //chsz is 2,avoid set 2 entry of errrep and 0x00//~v6DaI~
            {                                                      //~v640I~
                pcchar->chars[0]=errrep;                           //~v640I~
            }                                                      //~v640I~
            else                                                   //~v640I~
            {                                                      //~v640I~
            	apiwidth=wcwidth(ucs);	//curses expection         //~v640I~
//UTRACEP("ucs=%x,apiwidth=%d,dbcssw=%d\n",ucs,apiwidth,dbcssw);     //~v640I~//~v6b9R~
                if (UDBCSCHK_ISUCS_DBCS1STW(dbcsid))   //wide sbcs //~v640R~
                {                                                  //~v640I~
                	if (apiwidth==2)     //(u1+' ')+(u2+' ')       //~v640R~
                    {                                              //~v640I~
			    	    pcchar->chars[0]=ch;                       //~v640I~
			    	    pcchar->chars[1]=' ';                      //~v640I~
                        *(pcchar+1)=*pcchar;                       //~v640I~
                        pcchar->attr|=1;    //1st of dbcs          //~v640I~
                        (pcchar+1)->attr|=2;    //1st of dbcs      //~v640I~
                    }                                              //~v640I~
                    else                 //u                       //~v640R~
                    {                                              //~v640I~
			    	    pcchar->chars[0]=ch;                       //~v640I~
			    	    (pcchar+1)->chars[0]=' ';                  //~v640I~
			    	    (pcchar+1)->attr=attr;                     //~v640I~
                    }                                              //~v640I~
                }                                                  //~v640I~
                else                                               //~v640I~
                if (UDBCSCHK_ISUCS_DBCS1STN(dbcsid))   //narrow Dbcs(also wcwidth=2)//~v640R~
                {                                                  //~v640I~
                    pcchar->chars[0]=ch;                           //~v640I~
                    pcchar->chars[1]=' ';//Guviomdbcspad;          //~v640R~
                    *(pcchar+1)=*pcchar;                           //~v640I~
                    pcchar->attr|=1;    //1st of dbcs              //~v640I~
                    (pcchar+1)->attr|=2;    //1st of dbcs          //~v640I~
                }                                                  //~v640I~
                else                                               //~v640I~
                if (UDBCSCHK_DBCS1STUCS2(dbcsid))   //usual DBCS(wcwidt=1/2)//~v640R~
                {                                                  //~v640R~
                  if (apiwidth==2)                                 //~v6BgI~
                  {                                                //~v6BgI~
                    pcchar->chars[0]=ch;                           //~v640I~
                    *(pcchar+1)=*pcchar;                           //~v640I~
                    pcchar->attr|=1;    //1st of dbcs              //~v640I~
                    (pcchar+1)->attr|=2;    //1st of dbcs          //~v640I~
                  }                                                //~v6BgI~
                  else                                             //~v6BgI~
                  {                                                //~v6BgI~
                    pcchar->chars[0]=ch;                           //~v6BgI~
                    *(pcchar+1)=*pcchar;                           //~v6BgI~
			    	(pcchar+1)->chars[0]=' ';                      //~v6BgI~
                    UTRACEP("%s:apiwidth=1 for dbcsid=%c ucs=%x\n",UTT,dbcsid,ch);//~v6BgI~//~v6DdR~
                  }                                                //~v6BgI~
                }                                                  //~v640I~
                else								//usial SBCS(also wcwidt=1)//~v640I~
#ifdef UTF8UCS4                                                    //~v65cI~
//*LNX                                                             //~v6uBI~
#ifdef SSS                                                         //~v6DhI~
                if (UDBCSCHK_ISUCSNP1ST(dbcsid))   //unprintable   //~v6DaI~
                {                                                  //~v6DaI~
					uviom_setunpucs(0,pcchar,ch,errrep,apiwidth);  //~v6DaR~
                }                                                  //~v6DaI~
#else                                                              //~v6DhI~
                if (UDBCSCHK_ISUCSNP(dbcsid))   //unprintable NP1 or NP2//~v6DhI~
                {                                                  //~v6DhI~
        			altch=UTF_GETALTCH_SBCS(DEFAULT_UNPATTR);      //~v6DhI~
                    pcchar->chars[0]=altch;                        //~v6DhI~
                }                                                  //~v6DhI~
#endif                                                             //~v6DhI~
                else                                               //~v6DaI~
                if (UDBCSCHK_ISUCSOVF1ST(dbcsid))   //usual DBCS(wcwidt=1/2)//~v65cI~
                {                                                  //~v65cI~
//                    if (apiwidth==2)                               //~v65cI~//~v6DaR~
//                    {                                              //~v65cI~//~v6DaR~
//                        pcchar->chars[0]=ch;                       //~v65cI~//~v6DaR~
//                        *(pcchar+1)=*pcchar;                       //~v65cI~//~v6DaR~
//                        pcchar->attr|=1;    //1st of dbcs          //~v65cI~//~v6DaR~
//                        (pcchar+1)->attr|=2;    //1st of dbcs      //~v65cI~//~v6DaR~
//                    }                                              //~v65cI~//~v6DaR~
//                    else                                           //~v65cI~//~v6DaR~
//                    {                                              //~v65cI~//~v6DaR~
//                        pcchar->chars[0]=ch;                       //~v65cI~//~v6DaR~
//                        *(pcchar+1)=*pcchar;                       //~v65cI~//~v6DaR~
//                        (pcchar+1)->chars[0]=Guviomdbcspad;        //~v65cR~//~v6DaR~
////                      (pcchar+1)->attr=UVIOM_SET_PADATTR((pcchar+1)->attr);//~v65cI~//~v6D9R~//~v6DaR~
//                        (pcchar+1)->attr=uviom_set_padattr(0,pcchar->attr);//~v6D9R~//~v6DaR~
//                    }                                              //~v65cI~//~v6DaR~
					uviom_setunpucs(UVMSUUO_OVF,pcchar,ch,errrep,apiwidth);//~v6DaI~
                }                                                  //~v65cI~
                else                                               //~v65cI~
#endif                                                             //~v65cI~
                {                                                  //~v640I~
                    pcchar->chars[0]=ch;                           //~v640I~
                }                                                  //~v640I~
            }//errsw                                               //~v640I~
		}//not ascii                                               //~v640I~
    }//for                                                         //~v640I~
//  outctr=((ULONG)pcchar-(ULONG)Ppcchar)/CCHSZ;                   //~v640R~//~v6BhR~
    outctr=(int)((ULPTR)pcchar-(ULPTR)Ppcchar)/CCHSZ;              //~v6BhR~
    if (Ppoutctr)                                                  //~v640I~
    	*Ppoutctr=outctr;                                          //~v640R~
UTRACEP("ddcht2cchar outctr=%d,inctr=%d\n",outctr,Plen);           //~v640I~
UTRACED("cht2cchar out cchar",Ppcchar,outctr*CCHSZ);               //~v640R~
    return rc;                                                     //~v640I~
}//uvio_ddcht2cchar                                                //~v640R~
//*******************************************************          //~v653I~
//*chtype->cchar_t from DD fmt source                              //~v653I~
//*ret  :rc 0x01:esc found,0x02:non ascii found                    //~v653I~
//*******************************************************          //~v653I~
//int uvio_ddcht2cchar_ligature(int Popt,chtype *Ppcht,UCHAR *Ppdbcs,int Plen,cchar_t *Ppcchar,int Prow,int Pcol,int *Ppoutctr)//~v653R~//~v6EmR~
int uvio_ddcht2cchar_ligature(int Popt,int Plineopt,chtype *Ppcht,UCHAR *Ppdbcs,int Plen,cchar_t *Ppcchar,int Prow,int Pcol,int *Ppoutctr)//~v6EmI~
{                                                                  //~v653I~
//  int ii,mblen,dbcssw,errrep,ch,attr,chsz;                       //~v653R~//~v6BhR~
    int ii,mblen,dbcssw,errrep,ch,chsz;                            //~v6BhI~
    attr_t attr;                                                   //~v6BhI~
//  int attro=0,attrn;                                               //~v653I~//~v6h9R~//~v6BhR~
    attr_t attro=0,attrn;                                          //~v6BhI~
    int outctr;                                                    //~v653R~
    cchar_t *pcchar;                                               //~v653I~
    chtype  *pcht;                                                 //~v653I~
    UCHAR *pdbcs;                                                  //~v653I~
    WUCS    ucs;                                                   //~v653I~
    WUCS    prevucs=0;                                             //~v656I~
    UCHAR dbcswk[2],dbcsid;                                        //~v653I~
	int rc=UVIOMCCRC_LIGATUREMODE,col;                             //~v653R~
    int posb=-1,posc=-1,posa=-1,swcombine,swbreak,swcsrline,combinectr=0;//~v653R~
    int poscvhex=-1,posbvhex=-1,swvhexcsrline,swvhexcsrbreak;      //~v658R~
    int opt,swcsrbreak,swprevdbcs=0;                                            //~v656R~//~v658R~
//  int baseattr=0;                                                //~v65bI~//~v6BhR~
    attr_t baseattr=0;                                             //~v6BhI~
    int altch;                                                     //~v65iI~
    int swdbcsspace;                                               //~v65mI~
    int swaltsbcs;                                                 //~v68pI~
    int apiwidth;                                                  //~v6DaI~
//*********************************                                //~v653I~
    UTRACEP("%s:row=%d,csrline=%d\n",UTT,Prow,Scsrposy);//~v653R~  //~v6DdR~
UTRACED("cht2cchar inp cht",Ppcht,Plen*CCTSZ);                     //~v653I~//~v6DhM~
UTRACED("cht2cchar inp dbcs",Ppdbcs,Plen);                         //~v653I~//~v6DhM~
  if (Plineopt & UVIOO_CSRPOSCHK)       // file data line          //~v6EnR~
  {                                                                //~v6EmI~
	if ((swcsrline=(Prow==Scsrposy))                               //~v653I~
    &&  (Scsrposx>=Pcol && Scsrposx<Pcol+Plen)	//csr line         //~v653I~
    )                                                              //~v653I~
    {                                                              //~v653I~
		utfddgetcsrposbca(0,Ppdbcs,Plen+Pcol,Scsrposx,&posb,&posc,&posa);//~v653R~
    }                                                              //~v653I~
	if ((swvhexcsrline=(Prow==Svhexcsrposy))                       //~v658I~
    &&  (Svhexcsrposx>=Pcol && Svhexcsrposx<Pcol+Plen)	//csr line //~v658I~
    )                                                              //~v658I~
    {                                                              //~v658I~
		utfddgetcsrposbca(0,Ppdbcs,Plen+Pcol,Svhexcsrposx,&posbvhex,&poscvhex,0/*after*/);//~v658R~
    }                                                              //~v658I~
  }                                                                //~v6EmI~
    errrep=UVIO_ERRREP;                                            //~v653I~
    for (pcchar=Ppcchar,ii=0,pdbcs=Ppdbcs,pcht=Ppcht,col=Pcol;     //~v653R~
    			ii<Plen;                                           //~v653I~
				ii+=mblen,pcht+=mblen,pdbcs+=mblen,pcchar+=1+dbcssw,col+=mblen)//~v653R~
    {                                                              //~v653I~
	    ch=*pcht & A_CHARTEXT;                                     //~v653I~
        attr=*pcht & ~(A_CHARTEXT);                                //~v653I~
    	dbcssw=0;                                                  //~v653I~
        chsz=1;                                                    //~v653I~
        dbcsid=*pdbcs;                                             //~v653I~
        swcombine=0;                                               //~v653I~
        swdbcsspace=0;                                             //~v65mI~
        swaltsbcs=0;                                               //~v68pI~
    	if (UDBCSCHK_ISUCSSBCS(dbcsid))                            //~v653I~
        {                                                          //~v653I~
//      	dbcswk[0]=ch;                                          //~v653I~//~v6BhR~
        	dbcswk[0]=(UCHAR)ch;                                   //~v6BhI~
//        	ucs=UTF_GETUCSSBCS(dbcswk,pdbcs);                      //~v653I~//~v6BhR~
          	ucs=(WUCS)UTF_GETUCSSBCS(dbcswk,pdbcs);                //~v6BhI~
//#ifdef WWW                                                         //~v6BYI~//~v6BZR~
        	swcombine=UDBCSCHK_ISUCSWIDTH0(dbcsid);                //~v653R~
//#else                                                              //~v6BYI~//~v6BZR~
//            swcombine=UTF_ISUCSWIDTH0(ucs);                        //~v6BYI~//~v6BZR~
//#endif                                                             //~v6BYI~//~v6BZR~
        }                                                          //~v653I~
        else                                                       //~v653I~
//  	if (UDBCSCHK_DBCS1STUCS2NW(dbcsid))//usual, narrow and wide dbcs//~v653I~//~v6DaR~
//  	if (UDBCSCHK_DBCS1STUCS2NWP(dbcsid))//usual, narrow and wide dbcs//~v6DaI~//~v6DdR~
    	if (UDBCSCHK_DBCS1STUCS2NW(dbcsid))//usual, narrow and wide dbcs//~v6DdI~
        {                                                          //~v653I~
        	if (ii+1>=Plen)	//split by EOL                         //~v653I~
            	chsz=-1;	//errid                                //~v653I~
            else                                                   //~v653I~
            {                                                      //~v653I~
            	dbcssw=1;                                          //~v653I~
//          	dbcswk[0]=ch;                                      //~v653I~//~v6BhR~
            	dbcswk[0]=(UCHAR)ch;                               //~v6BhI~
            	dbcswk[1]=*(pcht+1) & A_CHARTEXT;                  //~v653I~
        		ucs=UTF_GETUCSDBCS(dbcswk);                        //~v653I~
            	chsz=2;                                            //~v653I~
#ifndef SSS                                                        //~v6DhI~
    			if (ucs==DBCSSPACE_ALT2   //ffff                   //~v6DhI~
		        &&  dbcsid==UDBCSCHK_DBCS1STUCS)	//tabdisplay set ffff/() for dbcsspace//~v6DhI~
          		{                                                  //~v6DhI~
          			swdbcsspace=1;                                 //~v6DhI~
          			ucs=UTF_GETALTCH_DBCS();                       //~v6DhI~
            	}                                                  //~v6DhI~
#endif //SSS                                                       //~v6DhI~
            }                                                      //~v653I~
        }                                                          //~v653I~
        else                                                       //~v653I~
#ifdef UTF8UCS4                                                    //~v65cI~
//*LNX                                                             //~v6uBI~
    	if (UDBCSCHK_ISUCSOVF1ST(dbcsid))                          //~v65cI~
        {                                                          //~v65cI~
        	if (ii+1>=Plen)	//split by EOL                         //~v65cI~
            	chsz=-1;	//errid                                //~v65cI~
            else                                                   //~v65cI~
            {                                                      //~v65cI~
            	dbcssw=1;                                          //~v65cI~
//          	dbcswk[0]=ch;                                      //~v65cI~//~v6BhR~
            	dbcswk[0]=(UCHAR)ch;                               //~v6BhI~
            	dbcswk[1]=*(pcht+1) & A_CHARTEXT;                  //~v65cI~
        		ucs=UTF_GETUCSDBCSOVF(dbcswk,pdbcs);               //~v65cI~
            	chsz=2;                                            //~v65cI~
            }                                                      //~v65cI~
        }                                                          //~v65cI~
        else                                                       //~v65cI~
#endif                                                             //~v65cI~
#ifdef UTF8UCS4                                                    //~v65cI~
//*LNX                                                             //~v6uBI~
    	if (UDBCSCHK_DBCS2NDUCS2NWO(dbcsid))   //dbcs split at TOL or invalid fmt//~v65cI~
#else                                                              //~v65cI~
    	if (UDBCSCHK_DBCS2NDUCS2NW(dbcsid))   //dbcs split at TOL or invalid fmt//~v653I~
#endif                                                             //~v65cI~
        {                                                          //~v653I~
            chsz=-1;	//errid                                    //~v653I~
        }                                                          //~v653I~
        else                                                       //~v653I~
        {                                                          //~v65mI~
#ifdef SSS                                                         //~v6DhI~
          if (ch==DEFAULT_ALTCH		//default DBCSSPACE alt ch     //~v65nR~
          &&  UDBCSCHK_ISUCSNP1ST(dbcsid) //NP set by tabdisplay   //~v65mI~
          && ii+1<Plen                                             //~v65mI~
          &&  (*(pcht+1) & A_CHARTEXT)==DEFAULT_ALTCH //ffff       //~v65nR~
//        && ((altch=utfgetvisiblealtch(0,ch))>0)                  //~v65nR~
          && ((altch=UTF_GETALTCH_DBCS())>0)                       //~v65nR~
          )                                                        //~v65mI~
          {                                                        //~v65mI~
            dbcssw=1;                                              //~v65mI~
            chsz=2;                                                //~v65mI~
          	swdbcsspace=1;                                         //~v65mI~
            ucs=altch;                                             //~v65mI~
          }                                                        //~v65mI~
          else                                                     //~v65mI~
#endif                                                             //~v6DhI~
          {                                                        //~v68pI~
            if (ch==DEFAULT_ALTCH)//0xff                           //~v68pI~
            {                                                      //~v68pI~
                altch=UTF_GETALTCH_SBCS(dbcsid);                   //~v68pI~
                if (altch>0)                                       //~v68pI~
                {                                                  //~v68pI~
                    swaltsbcs=1;                                   //~v68pI~
                    ch=altch;                                      //~v68pI~
                }                                                  //~v68pI~
            }                                                      //~v68pI~
        	ucs=ch;                                                //~v653I~
          }                                                        //~v68pI~
        }                                                          //~v65mI~
        mblen=chsz;                                                //~v653I~
        if (chsz<0) //err data                                     //~v653I~
        {                                                          //~v653I~
            mblen=1;                                               //~v653I~
            ucs=errrep;    //display "."                           //~v653I~
        }                                                          //~v653I~
        ch=ucs;                                                    //~v653I~
        if (!ch)                                                   //~v653I~
            ch=' ';    //null is used not only file area but anywhere//~v653I~
        if (!swcombine)                                            //~v656I~
        {                                                          //~v658I~
        	prevucs=ucs;	//base of combinechar is not combinemode//~v656I~
        	swprevdbcs=(chsz==2);	//base of combinechar is not combinemode//~v658I~
            baseattr=attr;                                         //~v65bI~
        }                                                          //~v658I~
        pcchar->attr=attr;                                         //~v653I~
//      attrn=attr & ~UVIOMATTR_DBCS12;                            //~v653R~//~v6BhR~
        attrn=attr & (attr_t)(~UVIOMATTR_DBCS12);                  //~v6BhI~
        swbreak=(ii>0 && attrn!=attro);                                    //~v653R~//~v656R~
//    if (!UVIOM_NONSPACECOMBINEMODE())  //fc5                     //~v656R~//~v658R~
//      swcsrbreak=0;                                              //~v656I~//~v658R~
//    else                                                         //~v656I~//~v658R~
        swcsrbreak=(swcsrline && (col==posb||col==posc||col==posa));   //~v653I~//~v656R~
        swcsrbreak|=(swvhexcsrline && col==posbvhex);              //~v658I~
        swbreak|=swcsrbreak;                                       //~v656I~
        swvhexcsrbreak=swvhexcsrline && col==poscvhex;             //~v658R~
        swbreak|=swvhexcsrbreak;                                   //~v658I~
        UTRACEP("breaksw=%d ii=%d,ucs=%x,dbcssw=%d,attrn=%x,attro=%x,mblen=%d,swcombine=%d\n",swbreak,ii,ch,dbcssw,attr,attro,mblen,swcombine);//~v653R~
        attro=attrn;                                               //~v653I~
        if (swcombine)//sbcs width0                                //~v653I~
        {                                                          //~v653I~
        	rc|=UVIOMCCRC_NONASCII|UVIOMCCRC_COMBINE;              //~v653I~
           	if (pcchar==Ppcchar                                    //~v656I~
           	||  (pcchar-1)->attr & UVIOMATTR_BREAK)                //~v656I~
            	swbreak=1;  //after single combine vhar            //~v656I~
//        if (UVIOM_COMBINEMODE())   //combine mode or fc5                                //~v653I~//~v656R~//~v658R~
//        if (UTF_COMBINEMODE())   //combine mode or fc5           //~v658I~//~v6EmR~
          if (COMBINEMODE(Plineopt))   //combine mode or fc5       //~v6EmI~
          {                                                        //~v656I~
        	if (!swbreak && combinectr<UVIOM_MAXCOMBINE)           //~v653R~
            {                                                      //~v653I~
            	pcchar--;                                          //~v653R~
                combinectr++;                                      //~v653I~
                pcchar->chars[combinectr]=ch;                      //~v653I~
                if (pcchar->attr & 0x02)	//dbcs2nd              //~v653I~
	                (pcchar-1)->chars[combinectr]=ch;              //~v653I~
        UTRACEP("combined pcchar=%p,combinectr=%d\n",pcchar,combinectr);//~v653I~
                continue;                                          //~v653I~
            }                                                      //~v653I~
            swbreak=1;  //overflow case                            //~v658I~
          }                                                        //~v656I~
            opt=0;                                                 //~v656R~
//          if (swcsrbreak)                                        //~v656I~//~v658R~
//              opt|=UVIOMATTR_SETATTR;          //for the case ligature not combine mode//~v656I~//~v658R~
            if (swbreak)                                           //~v656I~//~v658R~
            {                                                      //~v658I~
    	        opt|=UVIOMATTR_BREAK;		//shadow               //~v656R~//~v658R~
                if (!swvhexcsrbreak)		//NOT data csr pos of vhex csr//~v658I~//~v65bR~
    	        	opt|=UVIOMATTR_SETATTR;		//shadow           //~v658R~//~v65bR~
            }                                                      //~v658I~
//          else                                                   //~v656I~//~v658R~
//  			opt|=UVIOMATTR_SETATTR;          //for the case ligature not combine mode//~v656R~//~v658R~
//          swbreak=1;  //overflow case                            //~v653I~//~v658R~
            if (attr==baseattr) //NOT data csr pos of vhex csr     //~v65bI~
    	        opt|=UVIOMATTR_SETATTR;		//shadow               //~v65bI~
			if (swprevdbcs)                                        //~v658I~
  				opt|=UVIOMATTR_BASEDBCS;          //for the case ligature not combine mode//~v658I~
//			uviom_setcombine1(opt,(WUCS)ch,prevucs,pcht,pcchar);             //~v653I~//~v6EmR~
  			uviom_setcombine1(opt,Plineopt,(WUCS)ch,prevucs,pcht,pcchar);//~v6EmI~
            UTRACEP("combine ii=%d,ucs=%x,combinectr=%d\n",ii,ch,combinectr);//~v653I~
        }                                                          //~v653I~
        else                                                       //~v653I~
        {//swcombine                                               //~v656I~
        if (swdbcsspace)                                           //~v65mI~
        {                                                          //~v65mI~
    	    pcchar->chars[0]=ch;                                   //~v65mI~
            *(pcchar+1)=*pcchar;                                   //~v65mI~
//#ifndef SSS                                                      //~v6DhR~
//            (pcchar+1)->chars[0]=' ';                            //~v6DhR~
//#endif                                                           //~v6DhR~
            UTRACEP("%s:DBCSSPACE\n",UTT);                                //~v65mI~//~v6DhR~
        }                                                          //~v65mI~
        else                                                       //~v65mI~
        if (ch<0x80)                                               //~v653I~
        {                                                          //~v653I~
        	if (ch<0x20)                                           //~v65iI~
            	if ((altch=UTF_GETALTCH_CTL(ch))>0)                //~v65nR~
            		ch=altch;                                      //~v65iI~
          if (ch<0x80)//after altch conversion                     //~v65iI~
            if (Gpdbcstbl[ch] & UDBCSCHK_TYPEUNP)   //unprintable  //~v653I~
            	ch=errrep;                                         //~v653I~
    	    pcchar->chars[0]=ch;                                   //~v653I~
            if (ch==0x1b)                                          //~v653I~
	        	rc|=UVIOMCCRC_ESC;                                 //~v653I~
        }                                                          //~v653I~
        else                                                       //~v653I~
        {                                                          //~v653I~
        	rc|=UVIOMCCRC_NONASCII;                                //~v653I~
            if (swaltsbcs)                                         //~v68pI~
                pcchar->chars[0]=ch;                               //~v68pI~
            else                                                   //~v68pI~
//          if (ch <0x100 && Gpdbcstbl[ch] & UDBCSCHK_TYPEUNP)   //unprintable//~v653I~//~v6DaR~
            if (ch <0x100 && Gpdbcstbl[ch] & UDBCSCHK_TYPEUNP   //unprintable//~v6DaI~
            &&  !UDBCSCHK_ISUCSNP1ST(dbcsid))   //chsz is 2,avoid set 2 entry of errrep and 0x00//~v6DaI~
            {                                                      //~v653I~
                pcchar->chars[0]=errrep;                           //~v653I~
            }                                                      //~v653I~
            else                                                   //~v653I~
            {                                                      //~v653I~
#ifdef SSS                                                         //~v6DhI~
                if (UDBCSCHK_ISUCSNP1ST(dbcsid))   //unprintable   //~v6DaI~
                {                                                  //~v6DaI~
	            	apiwidth=wcwidth(ucs);	//curses expection     //~v6DaI~
					uviom_setunpucs(0,pcchar,ch,errrep,apiwidth);  //~v6DaR~
                }                                                  //~v6DaI~
#else                                                              //~v6DhI~
                if (UDBCSCHK_ISUCSNP(dbcsid))   //unprintable NP1 or NP2//~v6DhI~
                {                                                  //~v6DhI~
        			altch=UTF_GETALTCH_SBCS(DEFAULT_UNPATTR);      //~v6DhI~
                    pcchar->chars[0]=altch;                        //~v6DhI~
                }                                                  //~v6DhI~
#endif                                                             //~v6DhI~
                else                                               //~v6DaI~
                if (UDBCSCHK_ISUCSOVF1ST(dbcsid))   //usual DBCS(wcwidt=1/2)//~v6DaI~
                {                                                  //~v6DaI~
	            	apiwidth=wcwidth(ucs);	//curses expection     //~v6DaI~
					uviom_setunpucs(UVMSUUO_OVF,pcchar,ch,errrep,apiwidth);//~v6DaI~
                }                                                  //~v6DaI~
                else                                               //~v6DaI~
                if (dbcssw)   //usual DBCS(wcwidt=1/2)             //~v653I~
                {                                                  //~v653I~
                    pcchar->chars[0]=ch;                           //~v653I~
                    *(pcchar+1)=*pcchar;                           //~v653I~
                    pcchar->attr|=1;    //1st of dbcs              //~v653I~
                    (pcchar+1)->attr|=2;    //1st of dbcs          //~v653I~
                }                                                  //~v653I~
                else								//usial SBCS(also wcwidt=1)//~v653I~
                {                                                  //~v653I~
                    pcchar->chars[0]=ch;                           //~v653I~
                }                                                  //~v653I~
            }//errsw                                               //~v653I~
		}//not ascii                                               //~v653I~
        	if (swbreak)                                           //~v656I~
            	pcchar->attr|=UVIOMATTR_BREAK;	//substring breaker//~v656I~
        }//swcombine                                               //~v656I~
        combinectr=0;                                              //~v653I~
    }//for                                                         //~v653I~
//  outctr=((ULONG)pcchar-(ULONG)Ppcchar)/CCHSZ;                   //~v653I~//~v6BhR~
    outctr=(int)((ULPTR)pcchar-(ULPTR)Ppcchar)/CCHSZ;              //~v6BhR~
    if (Ppoutctr)                                                  //~v653I~
    	*Ppoutctr=outctr;                                          //~v653I~
UTRACEP("ddcht2cchar_ligature outctr=%d,inctr=%d\n",outctr,Plen);  //~v653I~
UTRACED("cht2cchar out cchar",Ppcchar,outctr*CCHSZ);               //~v653I~
    return rc;                                                     //~v653I~
}//uvio_ddcht2cchar_ligature                                       //~v653R~
#endif //!XXE                                                      //~v640I~
#endif //LNX                                                       //~v640I~
#ifdef W32                                                         //~v640I~
//**************************************************               //~v640I~
//*get ucs2 string from data/dbcs                                  //~v640I~
//**************************************************               //~v640I~
int uvio_mdd2u(int Popt,UCHAR *Ppdata,UCHAR *Ppdbcs,int Plen,WUCS *Ppucs,int Poutbuffsz,int *Ppoutucsctr,int *Ppucsdbcsctr,int *Ppucssbcsctr)//~v640R~
{                                                                  //~v640I~
    int opt;                                                       //~v640I~
//******************                                               //~v640I~
	if (Popt & UVIOM2UO_DDSTR   //already utfchkdd done            //~v640R~
    ||  (!(Popt & UVIOM2UO_MBCS) && utfchkdd(0,Ppdbcs,Plen))       //~v640R~
    )                                                              //~v640I~
    {                                                              //~v640I~
      if (Guviomopt & UDCWCIO_XEACB) 	                           //~v640I~
        opt=Popt|UVIO_ERRREP;   //write unprintable to screen as is//~v640I~
      else                                                         //~v640I~
        opt=Popt|UVIO_ERRREP|UTFDD2UO_VIO;                         //~v640R~
    	return utfdd2u(opt,Ppdata,Ppdbcs,Plen,Ppucs,Poutbuffsz,Ppoutucsctr,Ppucsdbcsctr,Ppucssbcsctr);//~v640R~
    }                                                              //~v640I~
	opt=UVIO_ERRREP;	//repch                                    //~v640I~
	return ucvext_wincp2ucss(opt,Scodepage,Ppdata,Ppdbcs,Plen,Ppucs,Poutbuffsz,Ppoutucsctr);//~v640R~
}//uvio_mdd2u                                                      //~v640I~
#endif                                                             //~v640I~
//#ifdef LNX                                                         //~v6BYI~//~v6BZR~
//#ifndef XXE                                                        //~v6BYI~//~v6BZR~
//**************************************************               //~v650I~
//*get combine ctr                                                 //~v650I~
//**************************************************               //~v650I~
//int uvio_getcombinectr(int Popt,int Pucs,int Pchwidth,UCHAR *Ppdbcs,int Plen)//~v650R~//~v6BTR~
//#ifdef WWW                                                         //~v6BYI~//~v6BZR~
int uvio_getcombinectr(int Popt,WUCS Pucs,int Pchwidth,UCHAR *Ppdbcs,int Plen)//~v6BTI~
//#else                                                              //~v6BYI~//~v6BZR~
//int uvio_getcombinectr(int Popt,WUCS Pucs,int Pchwidth,chtype Pcht,UCHAR *Ppdbcs,int Plen)//~v6BYI~//~v6BZR~
//#endif                                                             //~v6BYI~//~v6BZR~
{                                                                  //~v650I~
	int combinectr=0,ii;                                           //~v650R~
    UCHAR *pcd;                                                    //~v650I~
//#ifdef WWW                                                         //~v6BYI~//~v6BZR~
//#else                                                              //~v6BYI~//~v6BZR~
//    char dbcswk[1];                                                //~v6BYI~//~v6BZR~
//    chtype pcht;                                                   //~v6BYI~//~v6BZR~
//#endif                                                             //~v6BYI~//~v6BZR~
//***********************                                          //~v650I~
    pcd=Ppdbcs;                                                    //~v650R~
    if (UTF_COMBINABLE(Pucs)                                       //~v650R~
//#ifdef WWW                                                         //~v6BYI~//~v6BZR~
    && !UDBCSCHK_ISUCSWIDTH0(*pcd))	//acceptable combine           //~v650I~
//#else                                                              //~v6BYI~//~v6BZR~
//    && !UTF_ISUCSWIDTH0(Pucs))  //acceptable combine               //~v6BYI~//~v6BZR~
//#endif                                                             //~v6BYI~//~v6BZR~
    {                                                              //~v650I~
//#ifdef WWW                                                         //~v6BYI~//~v6BZR~
        for(pcd+=Pchwidth,ii=0;ii<Plen && combinectr<UVIOM_MAXCOMBINE;ii++,pcd++)//~v653R~
//#else                                                              //~v6BYI~//~v6BZR~
//        for(pcd+=Pchwidth,pcht=Pcht+Pchwidth,ii=0;ii<Plen && combinectr<UVIOM_MAXCOMBINE;ii++,pcd++,pcht++)//~v6BYI~//~v6BZR~
//#endif                                                             //~v6BYI~//~v6BZR~
        {                                                          //~v650I~
UTRACEP("%s: chk dbcs=%x\n",UTT,*pcd);                             //~v6G0R~
//#ifdef WWW                                                         //~v6BYI~//~v6BZR~
            if (!UDBCSCHK_ISUCSWIDTH0(*pcd))   //acceptable combine//~v650I~
//#else                                                              //~v6BYI~//~v6BZR~
//            dbcswk[0]=(char)(*pcht & A_CHAR_TEXT);                 //~v6BYI~//~v6BZR~
//            if (!UTF_ISDDWIDTH0(dbcswk,pcd,1,0/*pddwidth*/))   //acceptable combine//~v6BYI~//~v6BZR~
//#endif                                                             //~v6BYI~//~v6BZR~
                break;                                             //~v650I~
            combinectr++;                                          //~v650I~
        }                                                          //~v650I~
    }                                                              //~v650I~
UTRACEP("%s: ucs=%04x,rc=%d\n",UTT,Pucs,combinectr);                     //~v656I~//~v6BZR~
    return combinectr;                                             //~v650I~
}//uvio_getcombinectr                                              //~v650I~
//#endif //!XXE                                                      //~v6BYI~//~v6BZR~
//#endif //!LNX                                                      //~v6BYI~//~v6BZR~
//#ifdef W32                                                         //~v6BYI~//~v6BZR~
////**************************************************               //~v6BYI~//~v6BZR~
////*get combine ctr                                                 //~v6BYI~//~v6BZR~
////**************************************************               //~v6BYI~//~v6BZR~
//int uvio_getcombinectrUCS(int Popt,WUCS *Ppucs,int Pchwidth,UCHAR *Ppdbcs,int Plen)//~v6BYI~//~v6BZR~
//{                                                                  //~v6BYI~//~v6BZR~
//    int combinectr=0,ii;                                           //~v6BYI~//~v6BZR~
//    UCHAR *pcd;                                                    //~v6BYI~//~v6BZR~
//    WUCS *pucs,ucs;                                                //~v6BYI~//~v6BZR~
////***********************                                          //~v6BYI~//~v6BZR~
//    pucs=Ppucs;                                                    //~v6BYI~//~v6BZR~
//    ucs=*pucs;                                                     //~v6BYI~//~v6BZR~
//    pcd=Ppdbcs;                                                    //~v6BYI~//~v6BZR~
//    if (UTF_COMBINABLE(ucs)                                        //~v6BYI~//~v6BZR~
//    && !UTF_ISUCSWIDTH0(ucs))   //acceptable combine               //~v6BYI~//~v6BZR~
//    {                                                              //~v6BYI~//~v6BZR~
//        for(pcd+=Pchwidth,pucs++,ii=0;ii<Plen && combinectr<UVIOM_MAXCOMBINE;ii++,pcd++,pucs++)//~v6BYI~//~v6BZR~
//        {                                                          //~v6BYI~//~v6BZR~
//UTRACEP("%s:chk ucs=%04x,dbcs=%x\n",UTT,*pucs,*pcd);               //~v6BYI~//~v6BZR~
//            if (!UTF_ISUCSWIDTH0(*pucs))   //acceptable combine    //~v6BYI~//~v6BZR~
//                break;                                             //~v6BYI~//~v6BZR~
//            combinectr++;                                          //~v6BYI~//~v6BZR~
//        }                                                          //~v6BYI~//~v6BZR~
//    }                                                              //~v6BYI~//~v6BZR~
//UTRACEP("%s: rc%d\n",UTT,combinectr);                              //~v6BYI~//~v6BZR~
//    return combinectr;                                             //~v6BYI~//~v6BZR~
//}//uvio_getcombinectrUCS                                           //~v6BYI~//~v6BZR~
//#endif //W32                                                       //~v6BYI~//~v6BZR~
//**************************************************               //~v65iI~
//*replace 0x1b to unicode printable                               //~v65iI~
//rc:0: all replaced                                               //~v6EaR~
//  0x01:esc char remains                                          //~v6G0I~
//  0x02:ctl char remains                                          //~v6G0I~
//  0x04:ctl char replaced                                         //~v6G0I~
//  0x08:esc char replaced                                         //~v6G0I~
//**************************************************               //~v65iI~
int uviom_escrep(int Popt,WUCS *Pucs,int Pucsctr)                  //~v65iR~
{                                                                  //~v65iI~
	int rc=0,reslen,pos,altch;                                     //~v65iR~
    WUCS *pucs,*pucse,ucs;                                         //~v65iR~
    char *pc;                                                      //~v65iI~
//***********************                                          //~v65iI~
UTRACED("uviom_escrep",Pucs,Pucsctr*(int)WUCSSZ);                       //~v65iR~//~v6BhR~
	if (Popt & 0x02)	//ctl char exist                           //~v65iI~
    {                                                              //~v65iI~
        for (pucs=Pucs,pucse=pucs+Pucsctr;pucs<pucse;pucs++)       //~v65iR~
        {                                                          //~v65iI~
        	ucs=*pucs;                                             //~v65iR~
            if (ucs>=0x20)                                         //~v65iR~
            	continue;                                          //~v65iI~
            if ((altch=UTF_GETALTCH_CTL(ucs))<=0)                  //~v65nR~
            {                                                      //~v6EaR~
                rc|=0x02;	//ctl char remains                     //~v6EaR~
            	continue;                                          //~v65iI~
            }                                                      //~v6EaR~
//          *pucs=altch;                                           //~v65iI~//~v6BiR~
            *pucs=(WUCS)altch;                                     //~v6BiI~
            rc|=0x04;                                              //~v6G0I~
        }                                                          //~v65iI~
    }                                                              //~v65iI~
    else                                                           //~v65iI~
	if (Popt &0x01)	//esc exist                                    //~v65iI~
        for (pucs=Pucs,pucse=pucs+Pucsctr;pucs<pucse;)             //~v65iR~
        {                                                          //~v65iR~
//          reslen=((ULONG)pucse-(ULONG)pucs);                     //~v65iR~//~v6hhR~
//          reslen=((ULPTR)pucse-(ULPTR)pucs);                     //~v6hhI~//~v6BhR~
            reslen=(int)((ULPTR)pucse-(ULPTR)pucs);                //~v6BhI~
//          pc=memchr(pucs,UVIOM_ESC_CHAR,reslen);                 //~v65iR~//~v6BhR~
            pc=memchr(pucs,UVIOM_ESC_CHAR,(size_t)reslen);         //~v6BhI~
            if (!pc)                                               //~v65iR~
                break;                                             //~v65iR~
//          pos=((ULONG)pc-(ULONG)Pucs)/sizeof(WUCS);              //~v65iR~//~v6hhR~
//          pos=((ULPTR)pc-(ULPTR)Pucs)/sizeof(WUCS);              //~v6hhI~//~v6BhR~
            pos=(int)(((ULPTR)pc-(ULPTR)Pucs)/sizeof(WUCS));       //~v6BhI~
            pucs=Pucs+pos;                                         //~v65iR~
            if (*pucs==UVIOM_ESC_CHAR)                             //~v65iR~
            {                                                      //~v65iR~
                if ((altch=UTF_GETALTCH_CTL(UVIOM_ESC_CHAR))>0)    //~v65nR~
                {                                                  //~v65iR~
//                  *pucs=altch;                                   //~v65iR~//~v6BiR~
                    *pucs=(WUCS)altch;                             //~v6BiI~
	                rc|=0x08;  	//esc rep                          //~v6G0I~
//                  rc++;                                          //~v65iR~//~v6EaR~
                }                                                  //~v65iR~
                else                                               //~v6EaR~
	                rc|=0x01;  	//esc remains                      //~v6EaR~
            }                                                      //~v65iR~
            pucs++;                                                //~v65iR~
        }                                                          //~v65iR~
UTRACED("uviom_escrep",Pucs,Pucsctr*(int)WUCSSZ);                       //~v65iR~//~v6BhR~
UTRACEP("uviom_escrep rc=%d\n",rc);                                //~v65iR~
	return rc;                                                     //~v65iI~
}//uviom_escrep                                                    //~v65iR~
#endif                                                             //~v640I~
#endif //XSUB                                                      //~v6hhI~
#ifdef DDD                                                         //~v6D7I~
#ifndef KKK                                                        //~v6D7I~
//*****************************************************************//~v6D7I~
//*write 1/2 ucs using cell                                        //~v6D7I~
//*rc:TRUE/FALSE                                                   //~v6D7I~
//*****************************************************************//~v6D7I~
int uvioWriteConsoleOutputCharacterW1withAttrCHW(HANDLE Phandle,WUCS *Ppucs,int Pucsctr,int Pchwidth,SMALL_RECT *Ptargetrect,COORD Ptgtpos,int *Ppwritelen,USHORT Pattr)//~v6D7I~
{                                                                  //~v6D7I~
#ifdef AAA                                                         //~v6D7R~
	int rc,ucsctr,writelen;                                        //~v6D7I~
    WUCS  *pucs,wkucs[4];                                          //~v6D7I~
//***********                                                      //~v6D7I~
    UTRACEP("%s:ucsctr=%d,unicode=%04x-%04x,attr=%04x,tgtpos=%d,tgtrect.Left=%d,right=%d\n",UTT,Pucsctr,*Ppucs,(Pucsctr>1?*(Ppucs+1):0),Pattr,Ptgtpos.X,Ptargetrect->Left,Ptargetrect->Right);//~v6D7R~
    pucs=Ppucs;                                                    //~v6D7I~
    ucsctr=Pucsctr;                                                //~v6D7I~
    if (Pchwidth>1)                                                //~v6D7I~
    {                                                              //~v6D7I~
    	wkucs[0]=*Ppucs;                                           //~v6D7I~
        if (ucsctr>1)                                              //~v6D7I~
	    	wkucs[1]=*(Ppucs+1);                                   //~v6D7I~
        wkucs[ucsctr]=' ';	//append space                         //~v6D7I~
        ucsctr++;                                                  //~v6D7I~
	    pucs=wkucs;                                                //~v6D7I~
    }                                                              //~v6D7I~
    rc=uvioWriteConsoleOutputCharacterW(Phandle,pucs,ucsctr,Ptgtpos,&writelen); //len written//~v6D7R~
    UTRACEP("%s:rc=%d,writelen=%d\n",UTT,rc,writelen);             //~v6D7I~
    *Ppwritelen=writelen;                                          //~v6D7I~
    return rc;                                                     //~v6D7I~
#else                                                              //~v6D7I~
	SMALL_RECT targetrect;                                         //~v6D7I~
    CHAR_INFO wkchi[4];                                            //~v6D7I~
    COORD posinsrcbuff={0,0};                                      //~v6D7I~
    COORD srcbuffsz={1,1};                                         //~v6D7I~
    int rc;                                                        //~v6D7I~
//***********                                                      //~v6D7I~
    UTRACEP("%s:unicode=%04x,attr=%04x,tgtpos=%d,chwidth=%d,tgtrect.Left=%d,right=%d\n",UTT,*Ppucs,Pattr,Ptgtpos.X,Pchwidth,Ptargetrect->Left,Ptargetrect->Right);//~v6D7R~
	wkchi[0].Char.UnicodeChar=Ppucs[0];                            //~v6D7I~
    wkchi[0].Attributes=Pattr;                                     //~v6D7I~
    targetrect=*Ptargetrect;                                       //~v6D7I~
    targetrect.Left  =Ptgtpos.X;                                   //~v6D7I~
    targetrect.Right =Ptgtpos.X+(SHORT)(Pchwidth>1);               //~v6D7R~
    srcbuffsz.X  =(SHORT)Pucsctr;                                  //~v6D7I~
    srcbuffsz.Y  =1;                                               //~v6D7I~
    if (Pucsctr==2)                                                //~v6D7I~
    {                                                              //~v6D7I~
		wkchi[1].Char.UnicodeChar=Ppucs[1];                        //~v6D7I~
    	wkchi[1].Attributes=Pattr;                                 //~v6D7I~
	    targetrect.Right++;                                        //~v6D7I~
    }                                                              //~v6D7I~
    if (Pchwidth>1)                                                //~v6D7I~
    {                                                              //~v6D7I~
		wkchi[Pucsctr].Char.UnicodeChar=' ';                       //~v6D7I~
    	wkchi[Pucsctr].Attributes=Pattr;                           //~v6D7I~
	    srcbuffsz.X  =(SHORT)(Pucsctr+1);                          //~v6D7I~
    }                                                              //~v6D7I~
	rc=uvioWriteConsoleOutputW(Phandle,wkchi,srcbuffsz,posinsrcbuff,&targetrect);//~v6D7I~
    if (rc)                                                        //~v6D7I~
    	*Ppwritelen=Pucsctr;                                       //~v6D7I~
    else                                                           //~v6D7I~
    	*Ppwritelen=0;                                             //~v6D7I~
    return rc;                                                     //~v6D7I~
#endif                                                             //~v6D7I~
}//uvioWriteConsoleOutputCharacterW1withAttr                       //~v6D7I~
#endif //!KKK                                                      //~v6D7I~
#endif //DDD                                                       //~v6D7I~
#ifdef W32                                                         //~v6D6I~
#ifndef WXE                                                        //~v6D6I~
//*******************************************************          //~v6E8I~
//* change color of combine char 03/06 alternatively to protect combined and keep column//~v6EiI~
//*******************************************************          //~v6EiI~
int uviowrtcellW1_NonLigatureLineCmd(int Popt,WUCS *Ppucs,int Pucsctr,char *Ppdbcs,USHORT *Ppattr,int Plen,SMALL_RECT *Pptgtrect)//~v6E8I~
{                                                                  //~v6E8I~
	CHAR_INFO wkchi[UVIOM_MAXCOL],*pchi;                           //~v6E8I~
	CHAR_INFO wkchi_combine;                                       //~v6E8I~
	CHAR_INFO *pchi_substr=0;                                      //~v6E8I~
	WUCS *pucs,ucs;                                                //~v6E8I~
    char *pdbcs,dbcsid;                                            //~v6E8I~
    USHORT *pattr,attr,attro;                                      //~v6E8R~
    int ii,chsz,swovf,rc=0;                                        //~v6E8I~
	COORD srcpos={0,0},srcbox={1,1};                               //~v6E8I~
    int swcombine,strsz=0,substrctr;                               //~v6E8I~
    SMALL_RECT tgtrect,tgtrect2;                                   //~v6E8I~
    int combinectr=0;                                              //~v6E8R~
    COORD tgtpos;                                                  //~v6E8I~
//**********************                                           //~v6E8I~
	UTRACEP("%s:opt=%x,left=%d,right=%d,len=%d\n",UTT,Popt,Pptgtrect->Left,Pptgtrect->Right,Plen);//~v6E8I~
	UTRACED("ucs",Ppucs,ctr2szW(Pucsctr));                         //~v6E8I~
	UTRACED("dbcs",Ppdbcs,Plen);                                   //~v6E8I~
	UTRACED("attr",Ppattr,Plen*2);                                 //~v6E8I~
    tgtrect=*Pptgtrect;                                            //~v6E8I~
    tgtpos.X=0;                                                    //~v6E8I~
    tgtpos.Y=Pptgtrect->Top;                                       //~v6E8I~
    attro=*Ppattr;                                                 //~v6E8I~
    for (ii=0,pucs=Ppucs,pdbcs=Ppdbcs,pchi=wkchi,pattr=Ppattr;ii<Pucsctr;ii++,pucs++,pattr+=chsz,pdbcs+=chsz)//~v6E8I~
    {                                                              //~v6E8I~
        ucs=*pucs;                                                 //~v6E8I~
    	dbcsid=*pdbcs;                                             //~v6E8I~
    	attr=*pattr;                                               //~v6E8I~
		swovf=IS_UTF16_HIGH(ucs);                                  //~v6E8I~
        swcombine=0;                                               //~v6E8I~
        if (swovf)                                                 //~v6E8I~
        	chsz=2;                                                //~v6E8I~
        else                                                       //~v6E8I~
	    if (UDBCSCHK_DBCS1STL(dbcsid) || UDBCSCHK_DBCS1STUCS2NWPO(dbcsid) || UDBCSCHK_ISUCSOVF1ST(dbcsid))//~v6E8I~
            chsz=2;                                                //~v6E8I~
        else                                                       //~v6E8I~
        {                                                          //~v6E8I~
            chsz=1;                                                //~v6E8I~
	    	if (UDBCSCHK_ISUCSWIDTH0(dbcsid))  //acceptable combine//~v6E8R~
            {                                                      //~v6E8I~
	    		swcombine=1;                                       //~v6E8I~
				UTRACEP("%s:swcombine=%d for ucs=%04x,dbcsid=%02x,attr=%02x\n",UTT,swcombine,ucs,dbcsid,attr);//~v6E8I~
            }                                                      //~v6E8I~
        }                                                          //~v6E8I~
//      if (attr!=attro || swcombine)                              //~v6E8I~//~v6EaR~
#ifdef JJJ                                                         //~v6EaR~
        if (attr!=attro || swcombine || ucs<0x20)                  //~v6EaR~
#else                                                              //~v6EaR~
        if (attr!=attro || swcombine)                              //~v6EaR~
#endif        	                                                   //~v6EaR~
        {                                                          //~v6E8I~
            if (pchi_substr)                                       //~v6E8R~
            {                                                      //~v6E8R~
    			tgtpos.X=tgtrect.Left;                             //~v6E8I~
    			uviom_clearlineW(UVIOMCLO_ATTRFILL,0/*data*/,&attro,strsz,tgtpos);//~v6E8I~
                substrctr=PTRDIFF(pchi,pchi_substr)/(int)sizeof(wkchi[0]);//~v6E8R~
                srcbox.X=(USHORT)substrctr;                        //~v6E8R~
                tgtrect.Right=tgtrect.Left+(USHORT)strsz-1;        //~v6E8R~
                tgtrect2=tgtrect;                                  //~v6E8R~
                rc+=!uvioWriteConsoleOutputW(Shconout,pchi_substr,srcbox,srcpos,&tgtrect2);//~v6E8R~
                tgtrect.Left=tgtrect.Right+1;                      //~v6E8R~
                pchi_substr=0;                                     //~v6E8R~
	            strsz=0;                                           //~v6E8I~
            }                                                      //~v6E8R~
#ifdef JJJ                                                         //~v6EaR~
	        if (ucs<0x20)                                          //~v6EaR~
            {                                                      //~v6EaR~
            	wkchi_combine.Char.UnicodeChar=ucs;                //~v6EaR~
                wkchi_combine.Attributes=(attr&0xf0) | ATTR_CTLCHAR_FG;//~v6EaR~
                srcbox.X=1;                                        //~v6EaR~
                tgtrect.Right=tgtrect.Left;                        //~v6EaR~
                tgtrect2=tgtrect;                                  //~v6EaR~
    			tgtpos.X=tgtrect.Left;                             //~v6EaR~
    			uviom_clearlineW(UVIOMCLO_ATTRFILL,0/*data*/,&attr,1,tgtpos);//~v6EaR~
                rc+=!uvioWriteConsoleOutputW(Shconout,&wkchi_combine,srcbox,srcpos,&tgtrect2);//~v6EaR~
                tgtrect.Left++;                                    //~v6EaR~
		        attro=wkchi_combine.Attributes;                    //~v6EaR~
                continue;                                          //~v6EaR~
            }                                                      //~v6EaR~
#endif                                                             //~v6EaR~
            if (swcombine)                                         //~v6E8I~
            {                                                      //~v6E8I~
              if (UTF_COMBINEMODE_NP() && Gutfcombaltch)           //~v6EkR~
              {                                                    //~v6EkI~
            	wkchi_combine.Char.UnicodeChar=(WCHAR)Gutfcombaltch;//~v6EkR~
                wkchi_combine.Attributes=(attr & 0xf0)|ATTR_COMBINENP_FG;//~v6EkR~
//              wkchi_combine.Attributes=(attr & 0x70)|ATTR_COMBINENP_FG;   //drop bg highlight for visibility//~v6EkR~
              }                                                    //~v6EkI~
              else                                                 //~v6EkI~
              {                                                    //~v6EkI~
            	wkchi_combine.Char.UnicodeChar=ucs;                //~v6E8R~
            	if (combinectr++%2)     //      03,01,03,01,...    //~v6E8R~
                	wkchi_combine.Attributes=(attr & 0xf0)|ATTR_COMBINE_FG2;//~v6E8R~
            	else                                               //~v6E8R~
                	wkchi_combine.Attributes=(attr & 0xf0)|ATTR_COMBINE_FG;//~v6E8R~
              }                                                    //~v6EkI~
                srcbox.X=1;                                        //~v6E8R~
                tgtrect.Right=tgtrect.Left;                        //~v6E8R~
                tgtrect2=tgtrect;                                  //~v6E8R~
    			tgtpos.X=tgtrect.Left;                             //~v6E8I~
    			uviom_clearlineW(UVIOMCLO_ATTRFILL,0/*data*/,&attr,1,tgtpos);//~v6E8I~
                rc+=!uvioWriteConsoleOutputW(Shconout,&wkchi_combine,srcbox,srcpos,&tgtrect2);//~v6E8R~
                tgtrect.Left++;                                    //~v6E8R~
		        attro=wkchi_combine.Attributes;                    //~v6EaR~
                continue;                                          //~v6E8I~
            }                                                      //~v6E8I~
        }                                                          //~v6E8I~
      	if (!pchi_substr)                                          //~v6E8I~
        	pchi_substr=pchi;                                      //~v6E8I~
        pchi->Char.UnicodeChar=ucs;                                //~v6E8I~
        pchi->Attributes=attr;                                     //~v6E8I~
        attro=attr;                                                //~v6E8I~
        pchi++;                                                    //~v6E8I~
        if (swovf)                                                 //~v6E8I~
        {                                                          //~v6E8I~
            pucs++,ii++;                                           //~v6E8I~
            pchi->Char.UnicodeChar=*pucs;                          //~v6E8I~
            pchi->Attributes=attr=*(pattr+1);                      //~v6E8I~
        	pchi++;                                                //~v6E8I~
        }                                                          //~v6E8I~
	    strsz+=chsz;                                               //~v6E8I~
    }                                                              //~v6E8I~
    if (pchi_substr)                                               //~v6E8I~
    {                                                              //~v6E8I~
    	tgtpos.X=tgtrect.Left;                                     //~v6E8I~
    	uviom_clearlineW(UVIOMCLO_ATTRFILL,0/*data*/,&attro,strsz,tgtpos);//~v6E8I~
	    substrctr=PTRDIFF(pchi,pchi_substr)/(int)sizeof(wkchi[0]); //~v6E8I~
	    srcbox.X=(USHORT)substrctr;                                //~v6E8I~
        tgtrect.Right=tgtrect.Left+(USHORT)strsz-1;                //~v6E8I~
        tgtrect2=tgtrect;                                          //~v6E8I~
		rc+=!uvioWriteConsoleOutputW(Shconout,pchi_substr,srcbox,srcpos,&tgtrect2);//~v6E8I~
    }                                                              //~v6E8I~
    return rc;                                                     //~v6E8I~
}//uviowrtcellW1_NonLigatureLineCmd                                //~v6E8R~
//*******************************************************************************//~v6L4I~
int uviowrtcellW1_Errmsg(int Popt,PWUCS Ppucs,int Pucsctr,char *Ppdbcs,USHORT *Ppattr,int Plen,SMALL_RECT *Pptgtrect)//~v6L4I~
{                                                                  //~v6L4I~
	int ii,wrtlen;                                                 //~v6L4R~
    USHORT *pattr,attr;                                            //~v6L4R~
    COORD tgtpos;                                                  //~v6L4I~
//*******************************                                  //~v6L4I~
	UTRACEP("%s:ucsctr=%d,len=%d\n",UTT,Pucsctr,Plen);             //+v6L4R~
	pattr=Ppattr;                                                  //~v6L4I~
	attr=*pattr++;                                                 //~v6L4I~
	for (ii=1;ii<Plen;ii++)                                        //~v6L4I~
    	if (*pattr!=attr)                                          //~v6L4I~
        	break;                                                 //~v6L4I~
    if (ii<Plen)                                                   //~v6L4I~
		return uviowrtcellW1_NonLigatureLineCmd(Popt,Ppucs,Pucsctr,Ppdbcs,Ppattr,Plen,Pptgtrect);//~v6L4I~
    tgtpos.X=Pptgtrect->Left;                                      //~v6L4I~
    tgtpos.Y=Pptgtrect->Top;                                       //~v6L4I~
    uviom_clearlineW(UVIOMCLO_ATTRFILL,0/*data*/,&attr,Plen,tgtpos);//~v6L4I~
	return uvioWriteConsoleOutputCharacterW(Shconout,Ppucs,Pucsctr,tgtpos,&wrtlen)==0;//+v6L4R~
}//uviowrtcellW1_Errmsg                                            //~v6L4I~
//*******************************************************          //~v6E8I~
//*draw line by one OutputCharacterW if attr indicate printable,else Ligature//~v6E8I~
//*because OutputCharacter 1 by 1 inserts space between each dbcs  //~v6E8I~
//*ret  :rc                                                        //~v6E8I~
//*******************************************************          //~v6E8I~
//int uviowrtcellW1_NonLigatureLine(int Popt,PWUCS Ppucs,int Pucsctr,char *Ppdbcs,USHORT *Ppattr,int Plen,SMALL_RECT *Pptgtrect)//~v6E8I~
//int uviowrtcellW1_NonLigatureLine(int Popt,int Pswcmdline,PWUCS Ppucs,int Pucsctr,char *Ppdbcs,USHORT *Ppattr,int Plen,SMALL_RECT *Pptgtrect)//~v6EiR~
int uviowrtcellW1_NonLigatureLine(int Popt,PWUCS Ppucs,int Pucsctr,char *Ppdbcs,USHORT *Ppattr,int Plen,SMALL_RECT *Pptgtrect)//~v6EiI~
{                                                                  //~v6E8I~
#define ATTR_LCERR     0x02                                        //~v6E8I~
#define ATTR_LCERR_R   0xf2                                        //~v6E8I~
    int swligature=0;     //@@@@test                               //~v6E8I~
    int rc,ii;                                                     //~v6E8I~
	COORD tgtpos;                                                  //~v6E8I~
    USHORT *pattr;                                                 //~v6E8I~
    int ucsctr;                                                    //~v6E8I~
	WUCS *pucs,ucs;                                                //~v6E8I~
	COORD srcpos={0,0},srcbox;                                     //~v6E8I~
	SMALL_RECT tgtrect;                                            //~v6E8I~
    CHAR_INFO wkchi[UVIOM_MAXCOL],*pchi;                           //~v6E8I~
    SHORT attr=0;                                                  //~v6E8I~
    SHORT wkattr[UVIOM_MAXCOL];                                    //~v6E8I~
//  int optl=UWCW1LSO_NOCSRPO;  //   0x02       //ignore csrpos    //~v6EiR~
    int optl;                                                      //~v6EiI~
    int swattrcombine=0;                                           //~v6EiR~
//**********************                                           //~v6E8I~
	UTRACEP("%s:opt=%04x,posx=%d,posy=%d,ucsctr=%d,len=%d\n",UTT,Popt,Pptgtrect->Left,Pptgtrect->Top,Pucsctr,Plen);//~v6EiR~
	UTRACED("ucs",Ppucs,ctr2szW(Pucsctr));                         //~v6E8I~
	UTRACED("dbcs",Ppdbcs,Plen);                                   //~v6E8I~
	UTRACED("attr",Ppattr,Plen*2);                                 //~v6E8I~
    tgtpos.X=Pptgtrect->Left;                                      //~v6E8I~
    tgtpos.Y=Pptgtrect->Top;                                       //~v6E8I~
    optl=Popt & UVIOO_MASK;                                        //~v6EiR~
    for (pattr=Ppattr,ii=0;ii<Plen;ii++)                           //~v6E8I~
    {                                                              //~v6E8I~
//      if ((*pattr++ & 0x0f)==0x02)    //fg:green                 //~v6E8I~//~v6EgR~
    	attr=*pattr++;                                             //~v6EgI~
        if ((attr & 0x0f)==0x02)    //fg:green                     //~v6EgI~
        {                                                          //~v6E8I~
            swligature=1;                                          //~v6E8I~
          if (Popt & UVIOO_FORCELIGATURE)	//for errmsg,no split by attr change//~v6EiI~
          {                                                        //~v6EiI~
            optl|=UWCW1LSO_COMBINEATTR;//              //combine if combinable and combining char attr is different//~v6EiR~
//          optl|=UWCW1LSO_LIGATUREALL;//if not break by attr change,dbcs overridden by next different attr char//~v6EiR~
            swattrcombine=1;                                       //~v6EiR~
          }                                                        //~v6EiI~
            break;                                                 //~v6E8I~
        }                                                          //~v6E8I~
#ifndef JJJ                                                        //~v6EaR~
//      if ((*pattr++ & 0x0f)==0x03)    //ctlchar                  //~v6EaR~//~v6EgR~
        if ((attr & 0x0f)==0x03)    //ctlchar                      //~v6EgI~
        {                                                          //~v6EaR~
            swligature=1;                                          //~v6EaR~
            break;                                                 //~v6EaR~
        }                                                          //~v6EaR~
#endif                                                             //~v6EaR~
    }                                                              //~v6E8I~
    pattr=Ppattr;                                                  //~v6E8I~
    if (!swligature)                                               //~v6E8I~
    {                                                              //~v6E8I~
        pucs=Ppucs+Pucsctr-1;                                      //~v6E8I~
        if (*pucs==' ')                                            //~v6E8I~
        {                                                          //~v6E8I~
            swligature=2;                                          //~v6E8I~
        	memcpy(wkattr,Ppattr,Plen*sizeof(SHORT));              //~v6E8I~
            for (pattr=wkattr+Plen-1,ii=Plen-1;ii>=0 && *pucs==' ';ii--,pucs--)//~v6E8I~
            {                                                      //~v6E8I~
            	*pattr--=0x02;                                     //~v6E8I~
            }                                                      //~v6E8I~
    		pattr=wkattr;                                          //~v6E8I~
        }                                                          //~v6E8I~
    }                                                              //~v6E8I~
//  if (Pswcmdline)                                                //~v6EiR~
    if (Popt & UVIOO_CMDLINE)                                      //~v6EiR~
    {                                                              //~v6EiI~
        UTRACEP("%s:cmdline\n",UTT);                               //~v6EiI~
		return uviowrtcellW1_NonLigatureLineCmd(Popt,Ppucs,Pucsctr,Ppdbcs,pattr,Plen,Pptgtrect);//~v6E8R~
    }                                                              //~v6EiI~
    if (Popt & UVIOO_ERRMSG)                                       //~v6EiI~
    {                                                              //~v6EiI~
        UTRACEP("%s:uerrmsg len=%d\n",UTT,Plen);                               //~v6EiI~//~v6L4R~
//  	return uviowrtcellW1_NonLigatureLineCmd(Popt,Ppucs,Pucsctr,Ppdbcs,pattr,Plen,Pptgtrect);//~v6EiI~//~v6L4R~
    	return uviowrtcellW1_Errmsg(Popt,Ppucs,Pucsctr,Ppdbcs,pattr,Plen,Pptgtrect);//~v6L4I~
    }                                                              //~v6EiI~
    if (swligature)                                                //~v6E8I~
    {                                                              //~v6EgI~
//  	if (optl & UWCW1LSO_COMBINEATTR)//   0x04       //combine if combinable and combining char attr is different//~v6EiR~
        if (swattrcombine)                                         //~v6EiR~
        {                                                          //~v6EiR~
        	memcpy(wkattr,Ppattr,Plen*sizeof(SHORT));              //~v6EiR~
        	pattr=wkattr;                                          //~v6EiR~
        }                                                          //~v6EiR~
    	return uviowrtcellW1_ligature(optl,Ppucs,Pucsctr,Ppdbcs,pattr,Plen,Pptgtrect);//~v6E8R~
    }                                                              //~v6EgI~
	uviom_clearlineW(UVIOMCLO_ATTRSTR,0/*data*/,Ppattr,Plen,tgtpos);//~v6E8I~
    for (ii=0,pucs=Ppucs,pattr=Ppattr,pchi=wkchi;ii<Pucsctr;ii++)  //~v6E8I~
    {                                                              //~v6E8I~
    	attr=*pattr++;                                             //~v6E8I~
    	ucs=*pucs++;                                               //~v6E8I~
        pchi->Char.UnicodeChar=ucs;                                //~v6E8I~
        pchi->Attributes=attr;                                     //~v6E8I~
        pchi++;                                                    //~v6E8I~
    }                                                              //~v6E8I~
    ucsctr=Pucsctr;                                                //~v6E8I~
    srcbox.X=(SHORT)ucsctr;                                        //~v6E8I~
    srcbox.Y=1;                                                    //~v6E8I~
    tgtrect=*Pptgtrect;                                            //~v6E8I~
    tgtrect.Right=tgtrect.Left+(SHORT)Plen-1;                      //~v6E8I~
    rc=!uvioWriteConsoleOutputW(Shconout,wkchi,srcbox,srcpos,&tgtrect);//~v6E8I~
    UTRACEP("%s:rc=%d\n",UTT,rc);                                  //~v6E8I~
    return rc;                                                     //~v6E8I~
}//uviowrtcellW1_NonLigatureLine                                   //~v6E8I~
#endif //W32                                                       //~v6D6I~
#endif //!WXE                                                      //~v6D6I~
#ifdef LNX                                                         //~v6D9I~
#ifndef XXE                                                        //~v6D9I~
//*******************************************************          //~v6D9M~
attr_t uviom_set_padattr(int Popt,attr_t Pattr)                    //~v6D9R~
{                                                                  //~v6D9M~
	int colno,pairno;                                              //~v6D9R~
    attr_t attr;                                                   //~v6D9M~
//**********************************                               //~v6D9M~
	pairno=PAIR_NUMBER(Pattr);	// (Pattr & A_COLOR)>>8            //~v6D9M~
	colno=uviol_set_padattrsub(Popt,pairno);                       //~v6D9M~
    colno<<=NCURSES_ATTR_SHIFT;                                    //~v6D9M~
    attr=(Pattr & ~A_COLOR)|(attr_t)colno;                         //~v6D9R~
    UTRACEP("%s:input inp attr=%08x,out attr==%08x\n",UTT,Pattr,attr);//~v6D9M~
    return attr;                                                   //~v6D9M~
}//uviom_set_padattr                                               //~v6D9R~
//*******************************************************          //~v6D9I~
//*fill space after ligature string                                //~v6D9I~
//*ret  :rc                                                        //~v6D9I~
//*******************************************************          //~v6D9I~
int uviom_fillattrspace(int Popt,int Prow,int Pcol,attr_t Pattr,int Pctr)//~v6D9I~
{                                                                  //~v6D9I~
	cchar_t wkcch[UVIOM_MAXCOL],*pcch;                             //~v6D9R~
    int ii,rc;                                                     //~v6D9R~
//************************                                         //~v6D9I~
    memset(wkcch,0,(size_t)Pctr*sizeof(cchar_t));                  //~v6D9R~
	for (pcch=wkcch,ii=0;ii<Pctr;ii++,pcch++)                      //~v6D9I~
    {                                                              //~v6D9I~
		pcch->chars[0]=' ';                                        //~v6D9R~
        pcch->attr=Pattr;                                          //~v6D9R~
    }                                                              //~v6D9I~
    rc=uviom_mvaddwchnstr(Prow,Pcol,wkcch,Pctr);                   //~v6D9R~
    UTRACED("space-attr clear",wkcch,Pctr*(int)sizeof(cchar_t));   //~v6D9R~
    return rc;                                                     //~v6D9I~
}//uviom_fillattrspace                                             //~v6D9I~
//*******************************************************          //~v6DaI~
//*setup cchar_t for unprintable                                   //~v6DaI~
//*ret  :ctr                                                       //~v6DaR~
//*******************************************************          //~v6DaI~
int uviom_setunpucs(int Popt,cchar_t *Ppcchar,int Pucs,int Perrrep,int Papiwidth)//~v6DaR~
{                                                                  //~v6DaI~
	cchar_t *pcchar;                                               //~v6DaR~
    int ctr,ch1,ch2;                                               //~v6DaR~
    int altch,errrep;                                              //~v6DaI~
//************************                                         //~v6DaI~
    UTRACEP("%s:opt=%x,ucs=%04x,errrep=%04x,apiwidth=%d\n",UTT,Popt,Pucs,Perrrep,Papiwidth);//~v6DaR~
	pcchar=Ppcchar;                                                //~v6DaM~
    ch1=Pucs>>8;           //! as unprintable ucs by tabdisplay    //~v6DaI~
    ch2=Pucs&0xff;         //"                                     //~v6DaI~
	if (!(Popt & UVMSUUO_OVF)                                      //~v6DaI~
	&&  ch1==UDBCSCHK_ERRREPCH_NPUCS 	//      ':'      //unplitable char rep by tabdisplay//~v6DaR~
	&&  ch2==UDBCSCHK_ERRREPCH_NPUCSW)	//      ';'                //~v6DaI~
    {                                                              //~v6DaI~
        pcchar->chars[0]=ch1;                                      //~v6DaR~
        pcchar->attr=uviom_set_padattr(0,pcchar->attr);            //~v6DaR~
        *(pcchar+1)=*pcchar;                                       //~v6DaR~
        pcchar++;                                                  //~v6DaR~
        pcchar->chars[0]=ch2;                                      //~v6DaR~
    }                                                              //~v6DaI~
    else                                                           //~v6DaI~
    {                                                              //~v6DaI~
        altch=UTF_GETALTCH_SBCS(DEFAULT_UNPATTR);                  //~v6DaI~
        errrep=altch>0?altch:Perrrep;                              //~v6DaI~
        pcchar->chars[0]=Pucs;                                     //~v6DaI~
        if (Papiwidth==2)                                          //~v6DaR~
        {                                                          //~v6DaI~
        	*(pcchar+1)=*pcchar;                                   //~v6DaI~
            pcchar->attr|=1;    //1st of dbcs                      //~v6DaI~
            pcchar++;                                              //~v6DaI~
            pcchar->attr|=2;    //1st of dbcs                  //~v6DaI~//~v6DcR~
        }                                                          //~v6DaI~
        else                                                       //~v6DaI~
        if (Papiwidth==1)                                          //~v6DaR~
        {                                                          //~v6DaI~
        	*(pcchar+1)=*pcchar;                                   //~v6DaI~
            pcchar++;                                              //~v6DaI~
           	pcchar->chars[0]=errrep;                               //~v6DaR~
           	pcchar->attr=uviom_set_padattr(0,pcchar->attr);        //~v6DaI~
        }                                                          //~v6DaI~
        else                                                       //~v6DaI~
        {                                                          //~v6DaI~
	      if (Popt & UVMSUUO_OVF)                                  //~v6DaR~
          {                                                        //~v6DaI~
//         	pcchar->chars[0]=CHAR_UCS_DBCS_ERR;                    //~v6DaI~//~v6DcR~
           	pcchar->chars[0]=UTF_UNPDBCS;   //square               //~v6DcI~
        	*(pcchar+1)=*pcchar;                                   //~v6DaI~
            pcchar->attr|=1;    //1st of dbcs                      //~v6DaI~
            (pcchar+1)->attr|=2;    //1st of dbcs                  //~v6DaM~
            pcchar++;                                              //~v6DaI~
          }                                                        //~v6DaI~
          else                                                     //~v6DaI~
          {                                                        //~v6DaI~
           	pcchar->chars[0]=errrep;                               //~v6DaR~
           	pcchar->attr=uviom_set_padattr(0,pcchar->attr);        //~v6DaI~
        	*(pcchar+1)=*pcchar;                                   //~v6DaI~
            pcchar++;                                              //~v6DaI~
          }                                                        //~v6DaI~
        }                                                          //~v6DaI~
    }                                                              //~v6DaI~
    pcchar++;                                                      //~v6DaI~
    ctr=PTRDIFF(pcchar,Ppcchar)/CCHSZ;                             //~v6DaR~
    UTRACED("out cchar_t",Ppcchar,ctr*CCHSZ);                      //~v6DaR~
    return ctr;                                                    //~v6DaI~
}//uviom_setunpucs                                                 //~v6DaI~
#endif                                                             //~v6D9I~
#endif                                                             //~v6D9I~
#ifdef LNX                                                         //~v6EnI~
   #ifndef XXE                                                     //~v6EoI~
//*******************************************************          //~v6EnI~
//*setup attr for UNICOMB ITSELF when not ligature mode            //~v6EnR~
//*ret  :ctr                                                       //~v6EnI~
//*******************************************************          //~v6EnI~
attr_t uviom_attr_itself(int Popt,chtype Pchtype)                  //~v6EnR~
{                                                                  //~v6EnI~
    int attrold,attrnew,bgfg,bg,fg;                                //~v6EnI~
//****************                                                 //~v6EnI~
    attrold=(int)(Pchtype & A_ATTRIBUTES);                         //~v6EnR~
    UTRACEP("%s:Pattr=%08x,colorold=%04x\n",UTT,(int)Pchtype,attrold);//~v6EnR~
//  if (Popt & UVIOO_LIGATURE)	//file contents                    //~v6EnR~
//  	return attrold;                                            //~v6EnR~
	bgfg=uviol_attr2cell((chtype)attrold);                         //~v6EnI~
    UTRACEP("%s:bgfg=%08x,colorold=%04x\n",UTT,bgfg);              //~v6EnI~
    fg=bgfg & 0x0f;                                                //~v6EnR~
    bg=bgfg & 0xf0;                                                //~v6EnI~
    if (bg)                                                        //~v6EnI~
    	return (attr_t)attrold;                                    //~v6EnR~
    bg=0x70;                                                       //~v6EnI~
    bgfg=bg|fg;                                                    //~v6EnR~
    attrnew=(int)uviol_cell2attr((USHORT)(bgfg<<8));               //~v6EnI~
    UTRACEP("%s:return attr=%08x for %02x\n",UTT,attrnew,bgfg);    //~v6EnI~
    return (attr_t)attrnew;                                        //~v6EnR~
}                                                                  //~v6EnI~
	#endif//!XXE                                                   //~v6EoI~
#endif                                                             //~v6EnI~
//#ifdef W32                                                       //~v6EoR~
#if defined(W32)||defined(XXE)                                     //~v6EoR~
//*******************************************************          //~v6EiI~
//int uvio_getbufflineopt(int Popt,int Prow,int Plineopt)          //~v6EpR~
int uvio_getbufflineopt(int Popt,int Prow,int Plineopt,int Pcol)   //~v6EpI~
{                                                                  //~v6EiI~
	int row,opt,swv2nd;                                            //~v6EiR~
    int pos;                                                       //~v6EpI~
#ifdef WXEXXE                                                      //~v6EqR~
    int rowerrmsg,errmsgopt,colerrmsg,lenerrmsg;                   //~v6EpR~
#endif //WXE                                                       //~v6EpI~
//*********************************                                //~v6EiI~
#ifndef XXE                                                        //~v6EoI~
	if (Popt & UVGBLOO_TGTTOP)                                     //~v6EiI~
    	row=Prow-Stoplineoffs;                                     //~v6EiI~
    else                                                           //~v6EiI~
#endif //!XXE                                                      //~v6EoR~
    	row=Prow;                                                  //~v6EiI~
    swv2nd=(Plineopt & UVIOO_VSPLIT2ND)!=0;                        //~v6EiR~
//  opt=Sw95buffopt[row+row+swv2nd];                               //~v6EoR~
//  opt=Gw95buffopt[row+row+swv2nd];                               //~v6EpR~
    pos=(row+2)*2+swv2nd;                                          //~v6EpI~
#ifdef WXEXXE                                                      //~v6EqR~
//errmsg   //0: row+len, 1:col+len(vsplit2nd), 2/3: for errmsg2    //~v6EpI~
	if (swv2nd)                                                    //~v6EpI~
    {                                                              //~v6EpI~
    	if (Prow==0)                                               //~v6EpI~
        {                                                          //~v6EpI~
	    	errmsgopt=Gw95buffopt[1];                              //~v6EpI~
    		colerrmsg=errmsgopt>>UVIOO_ERRMSGSHIFT_ROW;            //~v6EpI~
    		lenerrmsg=(errmsgopt>>UVIOO_ERRMSGSHIFT_LEN) & 0xff;   //~v6EpI~
        	if (Pcol>=colerrmsg && Pcol<(colerrmsg+lenerrmsg))     //~v6EpI~
            {                                                      //~v6EpI~
        		pos=1;                                             //~v6EpI~
			    UTRACEP("%s:vsplit errmsg1 pos=%d,errmsgopt=%08x\n",UTT,pos,errmsgopt);//~v6EpI~
            }                                                      //~v6EpI~
        }                                                          //~v6EpI~
        else                                                       //~v6EpI~
    	if (Prow==1)                                               //~v6EpI~
        {                                                          //~v6EpI~
		    errmsgopt=Gw95buffopt[3];                              //~v6EpI~
	    	colerrmsg=errmsgopt>>UVIOO_ERRMSGSHIFT_ROW;            //~v6EpI~
    		lenerrmsg=(errmsgopt>>UVIOO_ERRMSGSHIFT_LEN) & 0xff;   //~v6EpI~
	        if (Pcol>=colerrmsg && Pcol<(colerrmsg+lenerrmsg))     //~v6EpI~
            {                                                      //~v6EpI~
    	    	pos=3;                                             //~v6EpI~
			    UTRACEP("%s:vsplit errmsg2 pos=%d,errmsgopt=%08x\n",UTT,pos,errmsgopt);//~v6EpI~
            }                                                      //~v6EpI~
        }                                                          //~v6EpI~
    }                                                              //~v6EpI~
    else                                                           //~v6EpI~
    {                                                              //~v6EpI~
	    errmsgopt=Gw95buffopt[0];                                  //~v6EpI~
    	rowerrmsg=errmsgopt>>UVIOO_ERRMSGSHIFT_ROW;                //~v6EpI~
    	lenerrmsg=(errmsgopt>>UVIOO_ERRMSGSHIFT_LEN) & 0xff;       //~v6EpI~
    	if (Prow==rowerrmsg && Pcol<lenerrmsg)                     //~v6EpI~
        {                                                          //~v6EpI~
        	pos=0;                                                 //~v6EpI~
			UTRACEP("%s:not vsplit errmsg1 pos=%d,errmsgopt=%08x\n",UTT,pos,errmsgopt);//~v6EpI~
        }                                                          //~v6EpI~
        else                                                       //~v6EpI~
        {                                                          //~v6EpI~
		    errmsgopt=Gw95buffopt[2];                              //~v6EpI~
	    	rowerrmsg=errmsgopt>>UVIOO_ERRMSGSHIFT_ROW;            //~v6EpI~
    		lenerrmsg=(errmsgopt>>UVIOO_ERRMSGSHIFT_LEN) & 0xff;   //~v6EpI~
	    	if (Prow==rowerrmsg && Pcol<lenerrmsg)                 //~v6EpI~
	        {                                                      //~v6EpI~
    	    	pos=2;                                             //~v6EpI~
				UTRACEP("%s:not vsplit errmsg2 pos=%d,errmsgopt=%08x\n",UTT,pos,errmsgopt);//~v6EpI~
        	}                                                      //~v6EpI~
        }                                                          //~v6EpI~
    }                                                              //~v6EpI~
#endif //WXE                                                       //~v6EpI~
    opt=Gw95buffopt[pos] & UVIOO_MASK;                             //~v6EpI~
    UTRACEP("%s:Popt=%04x,Prow=%d,Pcol=%d,Plineopt=%04x,rrow=%d,pos=%d,rc:opt=%04x,v2nd=%d\n",UTT,Popt,Prow,Pcol,Plineopt,row,pos,opt,swv2nd);//~v6EqR~
    return opt;                                                    //~v6EiI~
}//uvio_getbufflineopt                                             //~v6EiI~
//*******************************************************          //~v6EiI~
//int uvio_setbufflineopt(int Popt,int Prow,int Plineopt)          //~v6EpR~
int uvio_setbufflineopt(int Popt,int Prow,int Plineopt,int Pcol,int Plen)//~v6EpR~
{                                                                  //~v6EiI~
	int swv2nd,lineopt;                                            //~v6EjR~
    int pos;                                                       //~v6EpI~
#ifdef WXEXXE                                                      //~v6EqR~
//    int opthdr;                                                  //~v6EpR~
    int swerrmsg,swerrmsg2,rowerrmsg;                              //~v6EpI~
#endif                                                             //~v6EpR~
//*********************************                                //~v6EiI~
//#ifdef WXE                                                       //~v6EpR~
//    if (Plineopt & UVIOO_ERRMSG)                                 //~v6EpI~
//    {                                                            //~v6EpR~
//        opthdr=uvio_getbufflineopt(0,Prow,Plineopt);             //~v6EpR~
//        lineopt=(Plineopt<<16)|(opthdr & UVIOO_MASK);            //~v6EpR~
//    }                                                            //~v6EpR~
//    else                                                         //~v6EpR~
//#endif                                                           //~v6EpR~
	if (Plineopt & UVIOO_NOSAVE)                                   //~v6EqI~
    {                                                              //~v6EqI~
    	UTRACEP("%s:no save row=%d,col=%d,len=%d\n",UTT,Prow,Pcol,Plen);//~v6EqI~
        return 0;                                                  //~v6EqI~
    }                                                              //~v6EqI~
    swv2nd=(Plineopt & UVIOO_VSPLIT2ND)!=0;                        //~v6EiR~
#ifdef WXEXXE                                                      //~v6EqR~
	swerrmsg=(Plineopt & UVIOO_ERRMSG)!=0;	                       //~v6EpM~
    if (swerrmsg)                  //0: row+len, 1: hsplit:row+len, vsplit=col+len, 2/3: for errmsg2//~v6EpI~
    {                                                              //~v6EpI~
		swerrmsg2=(Plineopt & UVIOO_ERRMSG2)!=0;                   //~v6EpI~
        if (swv2nd)                                                //~v6EpI~
        	lineopt=Plineopt|((Pcol<<UVIOO_ERRMSGSHIFT_ROW)|(Plen<<UVIOO_ERRMSGSHIFT_LEN));	//save errmsglen//~v6EpI~
        else                                                       //~v6EpI~
        	lineopt=Plineopt|((Prow<<UVIOO_ERRMSGSHIFT_ROW)|(Plen<<UVIOO_ERRMSGSHIFT_LEN));	//save errmsglen//~v6EpI~
		pos=swerrmsg2*2+swv2nd;                                    //~v6EpI~
    }                                                              //~v6EpI~
    else                                                           //~v6EpI~
#endif                                                             //~v6EpI~
    {                                                              //~v6EpI~
		lineopt=Plineopt;                                          //~v6EpM~
		pos=(Prow+2)*2+swv2nd;                                     //~v6EpI~
    }                                                              //~v6EpI~
//  Sw95buffopt[Prow+Prow+swv2nd]=lineopt;                         //~v6EoR~
//  Gw95buffopt[Prow+Prow+swv2nd]=lineopt;                         //~v6EpR~
    Gw95buffopt[pos]=lineopt;                                      //~v6EpI~
#ifdef WXEXXE                                                      //~v6EqR~
    if (!swerrmsg)                                                 //~v6EpI~
    {                                                              //~v6EpI~
    	if (swv2nd)                                                //~v6EpI~
        	rowerrmsg=0;                                           //~v6EpI~
        else                                                       //~v6EpI~
    		rowerrmsg=Gw95buffopt[0]>>UVIOO_ERRMSGSHIFT_ROW;	//errmsgrow//~v6EpI~
        if (Prow==rowerrmsg)                                       //~v6EpI~
        {                                                          //~v6EpI~
		    UTRACEP("%s:clear errmsg1 row=%d,pos=%d,old=%08x\n",UTT,Prow,swv2nd,Gw95buffopt[swv2nd]);//~v6EqR~
	    	Gw95buffopt[swv2nd]=0;                                 //~v6EpI~
        }                                                          //~v6EpI~
        else                                                       //~v6EpI~
        {                                                          //~v6EpI~
	    	if (swv2nd)                                            //~v6EpI~
    	    	rowerrmsg=1;                                       //~v6EpI~
        	else                                                   //~v6EpI~
    			rowerrmsg=Gw95buffopt[2]>>UVIOO_ERRMSGSHIFT_ROW;	//errmsgrow//~v6EpI~
            if (Prow==rowerrmsg)                                   //~v6EpI~
            {                                                      //~v6EpI~
                UTRACEP("%s:clear errmsg2 row=%d,pos=%d,old=%08x\n",UTT,Prow,2+swv2nd,Gw95buffopt[2+swv2nd]);//~v6EqR~
                Gw95buffopt[2+swv2nd]=0;                           //~v6EpI~
            }                                                      //~v6EpI~
        }                                                          //~v6EpI~
    }                                                              //~v6EpI~
#endif                                                             //~v6EpI~
    UTRACEP("%s:Popt=%04x,Prow=%d,Pcol=%d,Plen=%d,Plineopt=%04x,index=%d,lineopt=%04x,swv2nd=%d\n",UTT,Popt,Prow,Pcol,Plen,Plineopt,pos,lineopt,swv2nd);//~v6EqR~
    return Plineopt;                                               //~v6EiI~
}//uvio_setbufflineopt                                             //~v6EiI~
#endif //defined(W32)||defined(XXE)                                //~v6EoR~
#if defined(W32) && !defined(WXE)                                  //~v6G1R~
//*********************************************************************************//~v6G0I~
//*rc:true/false                                                   //~v6G0I~
//*********************************************************************************//~v6G0I~
int uvioWriteConsoleOutputCharacter(HANDLE Phandle,UCHAR *Ppdata,int Plen,COORD Ptgtpos,int *Pwrtlen)//~v6G0R~
{                                                                  //~v6G0I~
	int rc;                                                        //~v6G0R~
//*****************                                                //~v6G0I~
    UTRACEP("%s:ulen=%d,tgtpos=(%d,%d)\n",UTT,Plen,Ptgtpos.X,Ptgtpos.Y);//~v6G0I~
    UTRACED("data",Ppdata,Plen);                                   //~v6G0I~
	rc=WriteConsoleOutputCharacter(Phandle,Ppdata,Plen,Ptgtpos,Pwrtlen);//~v6G0R~
    return rc;                                                     //~v6G0I~
}                                                                  //~v6G0I~
//*********************************************************************************//~v6G0I~
//*chk ucs2 is printable by default cp                             //~v6G0R~
//*rc:true/false                                                   //~v6G0I~
//*********************************************************************************//~v6G0I~
int uvioWriteConsoleOutputCharacterUCS1(HANDLE Phandle,WUCS Pucs,COORD Ptgtpos,int *Pwrtlen)//~v6G0I~
{                                                                  //~v6G0I~
	int rc,mblen;                                                  //~v6G0I~
    char wkmb[8];                                                  //~v6G0I~
#ifdef AAA                                                         //~v6G1I~
    WUCS ucs2;                                                     //~v6G1I~
#endif                                                             //~v6G1I~
	int opt;                                                       //~v6HkI~
//*****************                                                //~v6G0I~
#ifdef AAA                                                         //~v6G1I~
    if (Pucs==DBCSJ_BA_COMBINE)  //u-3099                          //~v6G1R~
    	ucs2=DBCSJ_BA_STANDALONE;  //u-309b                        //~v6G1I~
    else                                                           //~v6G1I~
    if (Pucs==DBCSJ_PA_COMBINE)  //u-309a                          //~v6G1R~
    	ucs2=DBCSJ_PA_STANDALONE;  //u-309c                        //~v6G1I~
    else                                                           //~v6G1I~
    	ucs2=0;                                                    //~v6G1I~
#endif                                                             //~v6G1I~
    if (UTF8ISASCII(Pucs))                                         //~v6G0I~
    {                                                              //~v6G0I~
    	mblen=1;                                                   //~v6G0I~
        wkmb[0]=(char)Pucs;                                        //~v6G0I~
    }                                                              //~v6G0I~
#ifdef AAA                                                         //~v6G1I~
    else                                                           //~v6G1I~
    if (ucs2)                                                      //~v6G1I~
    {                                                              //~v6G1I~
    	mblen=uwctombW(0,ucs2,wkmb);                               //~v6G1I~
    }                                                              //~v6G1I~
#endif                                                             //~v6G1I~
    else                                                           //~v6G0I~
    {                                                              //~v6G0I~
//  	mblen=uwctombW(0,Pucs,wkmb);                               //~v6G0R~//~v6HkR~
    	opt=UW2MWO_NOBESTFIT|UW2MWO_SUBCHRC;                       //~v6HkR~
    	mblen=uwctombW(opt,Pucs,wkmb);                             //~v6HkI~
    }                                                              //~v6G0I~
#ifdef AAA                                                         //~v6G1I~
    if (ucs2)                                                      //~v6G1I~
    {                                                              //~v6G1I~
		rc=WriteConsoleOutputCharacterW(Phandle,&Pucs,1,Ptgtpos,Pwrtlen);//~v6G1I~
        if (Pwrtlen)                                               //~v6G1I~
	    	*Pwrtlen=1;	//step 1 col                               //~v6G1I~
    }                                                              //~v6G1I~
    else                                                           //~v6G1I~
#endif                                                             //~v6G1I~
    if (mblen>0)                                                   //~v6G0I~
		rc=WriteConsoleOutputCharacter(Phandle,wkmb,mblen,Ptgtpos,Pwrtlen);//~v6G0R~
    else                                                           //~v6G0I~
		rc=WriteConsoleOutputCharacterW(Phandle,&Pucs,1,Ptgtpos,Pwrtlen);//~v6G0I~
    UTRACEP("%s:ucs=%x,tgtpos=(%d,%d),mblen=%d,wrtlen=%d\n",UTT,Pucs,Ptgtpos.X,Ptgtpos.Y,mblen,Pwrtlen?*Pwrtlen:0);//~v6G1R~
    return rc;                                                     //~v6G0I~
}//uvioWriteConsoleOutputCharacterUCS1                             //~v6G0R~
//*******************************************************          //~v6G0I~
int uviom_displaydbcspadCharacterW(int Popt,COORD Ptgtpos,int Plen)//~v6G0I~
{                                                                  //~v6G0I~
	WUCS  wkucs[4];                                                //~v6G0I~
    int ucsctr,rc,wrtlen;                                          //~v6G0R~
//****************************                                     //~v6G0I~
	for (ucsctr=0;ucsctr<Plen && ucsctr<(int)sizeof(wkucs);ucsctr++)//~v6G0I~
    	wkucs[ucsctr]=(WUCS)Guviomdbcspad;                         //~v6G0I~
    rc=FillConsoleOutputAttribute(Shconout,UVIOM_PADATTR,(DWORD)ucsctr,Ptgtpos,&wrtlen)==0;//~v6G0R~
	rc+=uvioWriteConsoleOutputCharacterW(Shconout,wkucs,ucsctr,Ptgtpos,&wrtlen)==0;//~v6G0R~
    UTRACEP("%s:posX=%d,len=%d,rc=%d\n",UTT,Ptgtpos.X,Plen,rc);    //~v6G0I~
    return rc;                                                     //~v6G0I~
}//uviom_displaydbcspadCharacterW                                  //~v6G0R~
//*********************************************************************************//~v6G0I~
//*by WriteOutputCharcter for locale file                          //~v6G0I~
//*********************************************************************************//~v6G0I~
int uviowrtcellW1_localefile(int Popt,WUCS *Ppucs,int Pucsctr,UCHAR *Ppdata,UCHAR *Ppdbcs,USHORT *Ppattr,int Plen,COORD Ptgtpos)//~v6G0R~
{                                                                  //~v6G0I~
	int rc=0,wrtlen;                                               //~v6G0R~
    int ii,len,swsbcs,dbcssz;                                      //~v6G0R~
    char *pdbcs,*pdata,*pdatao;                                    //~v6G0R~
    WUCS *pucs,ucs2;                                               //~v6G0R~
    UWUCS ucs4;                                                    //~v6G0I~
    WUCS *pucso=0;                                                 //~v6G0I~
    COORD tgtpos;                                                  //~v6G0I~
    int ucsctr=0,padctr;                                           //~v6G0R~
    WUCS   wkaltch[2];                                             //~v6G0I~
//*****************                                                //~v6G0I~
    UTRACEP("%s:ucsctr=%d,len=%d,tgtpos=(%d,%d),dbcsspacealt=%x\n",UTT,Pucsctr,Plen,Ptgtpos.X,Ptgtpos.Y,Sdbcsspacealt);//~v6G0R~
    UTRACED("ucs",Ppucs,Pucsctr*(int)sizeof(WUCS));                //~v6G0I~
    UTRACED("attr",Ppattr,Plen*(int)sizeof(USHORT));               //~v6G0I~
    UTRACED("daat",Ppdata,Plen);                                   //~v6G0I~
    UTRACED("dbcs",Ppdbcs,Plen);                                   //~v6G0I~
    uviom_clearlineW(UVIOMCLO_ATTRSTR,0/*data*/,Ppattr,Plen,Ptgtpos);//~v6G0R~
//  rc=uvioWriteConsoleOutputCharacterW(Shconout,Ppucs,Pucsctr,Ptgtpos,&wrtlen);//~v6G0R~
    for (ii=0,len=0,pdatao=0,pdata=Ppdata,pdbcs=Ppdbcs,tgtpos=Ptgtpos,pucs=Ppucs;ii<Pucsctr;ii++,pdata++,pdbcs++,pucs++)//~v6G0R~
    {                                                              //~v6G0I~
    	if (!pdatao)                                               //~v6G0I~
        	pdatao=pdata;                                          //~v6G0I~
    	if (!pucso)                                                //~v6G0I~
        	pucso=pucs;                                            //~v6G0R~
        ucs2=*pucs;                                                //~v6G0I~
        UTRACEP("%s:pucs=%x,pdata=%x,pdbcs=%x,len=%d,ucsctr=%d\n",UTT,*pucs,*pdata,*pdbcs,len,ucsctr);//~v6G0R~
        if (*pdbcs==UDBCSCHK_DBCS1ST)                              //~v6G0I~
			swsbcs=(ucs2==DBCSSPACE_ALT2||ucs2==Sdbcsspacealt)? 2 : 0;//~v6G0R~
        else                                                       //~v6G0I~
        	swsbcs=1;                                              //~v6G0I~
        ucs4=(UWUCS)ucs2;                                          //~v6G0R~
        if (IS_UTF16_HIGH(ucs4) && (ii+1)<Pucsctr && IS_UTF16_PAIR(ucs4,*(pucs+1)))//~v6G0R~
        {                                                          //~v6G0I~
            ucs4=UTF16_TO_UCS4(ucs4,*(pucs+1));                    //~v6G0I~
            pucs++;                                                //~v6G0I~
            ii++;                                                  //~v6G0I~
            ucsctr++;                                              //~v6G0I~
        }                                                          //~v6G0I~
        if (swsbcs)                                                //~v6G0I~
        {                                                          //~v6G0I~
        	if (ucs4!=*pdata)          //tab,esc rep or unprintable//~v6G0R~
            {                                                      //~v6G0I~
            	if (len)                                           //~v6G0I~
                {                                                  //~v6G0I~
					if (Gudbcschk_flag & UDBCSCHK_DBCSJ)	//Japanese//~v6G0R~
						rc+=uvioWriteConsoleOutputCharacter(Shconout,pdatao,len,tgtpos,&wrtlen)==0;//~v6G0R~
					else                                           //~v6G0R~
						rc+=uvioWriteConsoleOutputCharacterW(Shconout,pucso,ucsctr,tgtpos,&wrtlen)==0;//~v6G0R~
                    tgtpos.X+=(SHORT)len;                          //~v6G0R~
                }                                                  //~v6G0I~
                if (swsbcs==2) //altch for dbcsspace               //~v6G0R~
                {                                                  //~v6G0I~
                	if (ucs2==(WUCS)Sdbcsspacealt)  //2 altch was set already when lig off//~v6G0R~
                    {                                              //~v6G0I~
						rc+=uvioWriteConsoleOutputCharacterW(Shconout,pucs,2,tgtpos,&wrtlen)==0;//~v6G0I~
    	                ii++;                                      //~v6G0I~
        	            pucs++;                                    //~v6G0I~
                    }                                              //~v6G0I~
                    else                    //1 ucs=ffff is set when lig on//~v6G0R~
                    {                                              //~v6G0I~
    		        	wkaltch[0]=(WUCS)Sdbcsspacealt;            //~v6G0R~
            			wkaltch[1]=wkaltch[0];                     //~v6G0R~
						rc+=uvioWriteConsoleOutputCharacterW(Shconout,wkaltch,2,tgtpos,&wrtlen)==0;//~v6G0R~
                    }                                              //~v6G0I~
	                tgtpos.X++;                                    //~v6G0M~
                    pdata++;                                       //~v6G0M~
                    pdbcs++;                                       //~v6G0M~
                }                                                  //~v6G0I~
                else                                               //~v6G0I~
					rc+=uvioWriteConsoleOutputCharacterW(Shconout,pucs,1,tgtpos,&wrtlen)==0;//~v6G0R~
                len=0;                                             //~v6G0M~
                ucsctr=0;                                          //~v6G0I~
                tgtpos.X++;                                        //~v6G0I~
                pdatao=pdata+1;                                    //~v6G0I~
                pucso=pucs+1;                                      //~v6G0I~
            }                                                      //~v6G0I~
            else                                                   //~v6G0I~
            {                                                      //~v6G0I~
            	len++;                                             //~v6G0I~
                ucsctr++;                                          //~v6G0I~
            }                                                      //~v6G0I~
        }                                                          //~v6G0I~
        else                                                       //~v6G0I~
        {                                                          //~v6G0I~
            for (dbcssz=1;ii+dbcssz<Plen;dbcssz++)                 //~v6G0I~
            {                                                      //~v6G0M~
                if (*(pdbcs+dbcssz)==UDBCSCHK_DBCS2ND)             //~v6G0I~
                    break;                                         //~v6G0M~
            }                                                      //~v6G0M~
        	UTRACEP("%s:dbcssz=%d\n",UTT,dbcssz);                  //~v6G0R~
            pdata+=dbcssz;  //1                                    //~v6G0R~
           	pdbcs+=dbcssz;                                         //~v6G0R~
            ucsctr++;                                              //~v6G0I~
            len+=2;                                                //~v6G0I~
            dbcssz++;   //1-->2                                    //~v6G0I~
            if (dbcssz>2) //write dbcs padding                     //~v6G0I~
            {                                                      //~v6G0M~
                rc+=uvioWriteConsoleOutputCharacterW(Shconout,pucso,ucsctr,tgtpos,&wrtlen)==0;//~v6G0R~
                tgtpos.X+=(SHORT)len;                              //~v6G0I~
                padctr=dbcssz-2;                                   //~v6G0M~
				rc+=uviom_displaydbcspadCharacterW(0,tgtpos,padctr);//~v6G0M~
                len=0;                                             //~v6G0M~
                ucsctr=0;                                          //~v6G0M~
                tgtpos.X+=(SHORT)padctr;                           //~v6G0M~
                pdatao=pdata+dbcssz;                               //~v6G0M~
                pucso=pucs+1;                                      //~v6G0M~
			}                                                      //~v6G0M~
        }                                                          //~v6G0I~
    }                                                              //~v6G0I~
    if (len)                                                       //~v6G0I~
		if (Gudbcschk_flag & UDBCSCHK_DBCSJ)	//Japanese         //~v6G0I~
			rc+=uvioWriteConsoleOutputCharacter(Shconout,pdatao,len,tgtpos,&wrtlen);//~v6G0R~
        else                                                       //~v6G0I~
			rc+=uvioWriteConsoleOutputCharacterW(Shconout,pucso,ucsctr,tgtpos,&wrtlen);//~v6G0R~
    return rc;                                                     //~v6G0I~
}//uviowrtcellW1_localefile                                        //~v6G0I~
//*********************************************************************************//~v6G0I~
//*combine and no combine *********************************************************//~v6G0I~
//*********************************************************************************//~v6G0I~
//        UTRACEP("%s:not uviowrtcellW1_ligature\n",UTT);          //~v6G0I~
//        posa=posb=posc=-1;                                       //~v6G0I~
//        swcombinemode=(m2uopt && COMBINEMODE(Popt));//utf8 combine mode//~v6G0I~
//        if (swcombinemode) //ligature on                         //~v6G0I~
//        {                                                        //~v6G0I~
//            if (tgtpos.Y==Scsrposy+Stoplineoffs)    //csr line   //~v6G0I~
//            {                                                    //~v6G0I~
//                UTRACEP(" line Y=%d X=%d,top=%d,csrY=%d\n",tgtpos.Y,tgtpos.X,Stoplineoffs,Scsrposy);//~v6G0I~
//                utfddgetcsrposbca(0,Ppdbcs-tgtpos.X,Plen+tgtpos.X,Scsrposx,&posb,&posc,&posa);//~v6G0I~
//            }                                                    //~v6G0I~
//            if (tgtpos.Y==Svhexcsrposy+Stoplineoffs)    //csr line//~v6G0I~
//            {                                                    //~v6G0I~
//                utfddgetcsrposbca(0,Ppdbcs-tgtpos.X,Plen+tgtpos.X,Svhexcsrposx,&posbvhex,&poscvhex,0/*after*/);//~v6G0I~
//            }                                                    //~v6G0I~
//        }                                                        //~v6G0I~
//        uviom_clearlineW(UVIOMCLO_ATTRSTR,0/*data*/,pattr0,Plen,tgtpos);//~v6G0I~
//        col=0;  //start col                                      //~v6G0I~
////**************************************************             //~v6G0I~
//        pdata=pdata0;                                            //~v6G0I~
//        pattr=pattr0;                                            //~v6G0I~
//        for (rc=0,ii=0,pucs=pucs0,pdbcs=Ppdbcs;ii<ucsctr;ii++,pucs++)//~v6G0I~
//        {                                                        //~v6G0I~
//            ucs=*pucs;                                           //~v6G0I~
////#Windows    no GB4support  UDBCSCHK_DBCS                       //~v6G0I~
//            swovf=0;                                             //~v6G0I~
//            swdbcsspaceutf8=0;                                   //~v6G0I~
//          if (m2uopt)   //cpu8 file                              //~v6G0I~
//          {                                                      //~v6G0I~
//           if (Guviomopt & UDCWCIO_XEACB)                        //~v6G0I~
//            chwidth=UDBCSCHK_DBCS1STUCS2NWP(*pdbcs)+1;           //~v6G0I~
//           else                                                  //~v6G0I~
//            chwidth=UDBCSCHK_DBCS1STUCS2NW(*pdbcs)+1;            //~v6G0I~
//            if (UDBCSCHK_ISUCSOVF1ST(*pdbcs)) //ucs4             //~v6G0I~
//            {                                                    //~v6G0I~
//                swovf=1;                                         //~v6G0I~
//                chwidth++;                                       //~v6G0I~
//            }                                                    //~v6G0I~
//            if (*pucs==DBCSSPACE_ALT2   //ffff                   //~v6G0I~
//            &&  *pdbcs==UDBCSCHK_DBCS1STUCS)    //tabdisplay set ffff/() for dbcsspace//~v6G0I~
//                swdbcsspaceutf8=1;                               //~v6G0I~
//          }                                                      //~v6G0I~
//          else                                                   //~v6G0I~
//            chwidth=1;                                           //~v6G0I~
//            if (*pdbcs==UDBCSCHK_DBCS1ST)                        //~v6G0I~
//            {                                                    //~v6G0I~
//                if (*pdata!=DEFAULT_ALTCH/*0xff*/)  //by tabdisplay for dbcs space//~v6G0I~
//                    chwidth=UDBCSCHK_PCD_MBCHSZ(pdbcs,PTRDIFF(pdbcsend,pdbcs));//~v6G0I~
//            }                                                    //~v6G0I~
//            UTRACEP("%s:W1 m2uopt=%d,chwidth=%d,data=%x,dbcs=%x,ucs=%x\n",UTT,m2uopt,chwidth,*pdata,*pdbcs,*pucs);//~v6G0I~
//          if (swdbcsspaceutf8)                                   //~v6G0I~
//          {                                                      //~v6G0I~
//                chwidth=2;                                       //~v6G0I~
//                wkaltch[0]=(WUCS)UTF_GETALTCH_DBCS();            //~v6G0I~
//                wkaltch[1]=wkaltch[0];                           //~v6G0I~
//                if (!uvioWriteConsoleOutputCharacterW1withAttr1(0,Shconout,wkaltch,2,tgtpos,&writelen,Ptgtrect,pattr,chwidth)) //len written//~v6G0I~
//                    rc++;                                        //~v6G0I~
//UTRACEP("%s:write dbcsspaceutf8F ucs=%04x,col=%d\n",UTT,*pucs,tgtpos.X);//~v6G0I~
//                writelend+=writelen;                             //~v6G0I~
//                pdbcs+=chwidth;                                  //~v6G0I~
//                pdata+=chwidth;                                  //~v6G0I~
//                tgtpos.X+=(SHORT)chwidth;                        //~v6G0I~
//                pattr+=chwidth;                                  //~v6G0I~
//          }                                                      //~v6G0I~
//          else                                                   //~v6G0I~
//          if (swcombinemode && !swovf)//utf8 combine mode        //~v6G0I~
//          {                                                      //~v6G0I~
//            attr=pattr0[col];                                    //~v6G0I~
////* after fill space and WriteConsoleOutputAttribute for the line//~v6G0I~
////* write non space padding for combining char                   //~v6G0I~
////* then use WiriteConsoleOutput(char+attr) for base+combining char//~v6G0I~
//            if (combinectr)                                      //~v6G0I~
//            {                                                    //~v6G0I~
//                combinectr--;                                    //~v6G0I~
//            }                                                    //~v6G0I~
//            else                                                 //~v6G0I~
//            {                                                    //~v6G0I~
//                if (attr==attro)                                 //~v6G0I~
//                {                                                //~v6G0I~
//                    combinectr=uvio_getcombinectr(0,*pucs,chwidth,pdbcs,ucsctr-ii);//~v6G0I~
//                    if (combinectr)                              //~v6G0I~
//                    {                                            //~v6G0I~
//                        for (jj=1;jj<=combinectr;jj++)           //~v6G0I~
//                            if (attr!=pattr0[col+jj])            //~v6G0I~
//                            {                                    //~v6G0I~
//                                combinectr=jj-1;                 //~v6G0I~
//                                break;                           //~v6G0I~
//                            }                                    //~v6G0I~
//                    }                                            //~v6G0I~
//                }                                                //~v6G0I~
//                else                                             //~v6G0I~
//                    combinectr=0;                                //~v6G0I~
//UTRACEP("combinectr=%d,atto=%d,attrn=%d,col=%d,rcol=%d\n",combinectr,attro,attr,tgtpos.X,col);//~v6G0I~
//                if (combinectr)                                  //~v6G0I~
//                {                                                //~v6G0I~
//                    combpos=tgtpos.X+1;                          //~v6G0I~
//                    for (jj=1;jj<=combinectr;jj++,combpos++)     //~v6G0I~
//                    {                                            //~v6G0I~
//                        if (combpos==posb||combpos==posc||combpos==posa)//~v6G0I~
//                        {                                        //~v6G0I~
//                            combinectr=jj-1;                     //~v6G0I~
//                            break;                               //~v6G0I~
//                        }                                        //~v6G0I~
//                        if (combpos==posbvhex||combpos==poscvhex)//~v6G0I~
//                        {                                        //~v6G0I~
//                            combinectr=jj-1;                     //~v6G0I~
//                            break;                               //~v6G0I~
//                        }                                        //~v6G0I~
//                    }                                            //~v6G0I~
//UTRACEP("combinectr=%d,combpos=%d,posb=%d,posc=%d,posa=%d\n",combinectr,combpos,posb,posc,posa);//~v6G0I~
//                }                                                //~v6G0I~
//                  if (combinectr) //acceptable combine           //~v6G0I~
//                  {                                              //~v6G0I~
//                    if (Guviomdbcspad!=' ')                      //~v6G0I~
//                    {                                            //~v6G0I~
//                        pwchi=wkcombinechi;                      //~v6G0I~
//                        for(jj=0;jj<combinectr;jj++,pwchi++)     //~v6G0I~
//                        {                                        //~v6G0I~
//                            pwchi->Char.UnicodeChar=Guviomdbcspad;//~v6G0I~
//                            attrcmb=pattr0[col+chwidth+jj];      //~v6G0I~
//                            pwchi->Attributes=(attrcmb&0xf0)/*bg*/|UVIOM_PADATTR/*fg*/;//~v6G0I~
//                        }                                        //~v6G0I~
//                        targetrect=*Ptgtrect;                    //~v6G0I~
//                        targetrect.Left  =tgtpos.X+(SHORT)chwidth;//~v6G0I~
//                        targetrect.Right =tgtpos.X+(SHORT)(chwidth+combinectr-1);//~v6G0I~
//                        posinsrcbuff.X  =0;                     //pos in parm buff//~v6G0I~
//                        posinsrcbuff.Y  =0;                     //pos in parm buff//~v6G0I~
//                        srcbufsz.X  =(SHORT)combinectr;    //rect of parm buff,width//~v6G0I~
//                        srcbufsz.Y  =1;       //rect of parm buff,height//~v6G0I~
//                        UTRACEP("combined combinectr=%d,chwidth=%d\n",combinectr,chwidth);//~v6G0I~
//                        rc2=uvioWriteConsoleOutputW(Shconout,wkcombinechi,srcbufsz,posinsrcbuff,&targetrect);//~v6G0I~
//                    }                                            //~v6G0I~
//                    pucscmb=pucs;                                //~v6G0I~
//                    pwchi=wkcombinechi;                          //~v6G0I~
//                    pwchi->Char.UnicodeChar=*pucscmb++;          //~v6G0I~
//                    attrcmb=pattr0[col];                         //~v6G0I~
//                    pwchi->Attributes=attrcmb;                   //~v6G0I~
//                    for(jj=0,pwchi++;jj<combinectr;jj++,pwchi++) //~v6G0I~
//                    {                                            //~v6G0I~
//                        pwchi->Char.UnicodeChar=*pucscmb++;      //~v6G0I~
//                        pwchi->Attributes=attrcmb;               //~v6G0I~
//                    }                                            //~v6G0I~
//                    chictr=1+combinectr;                         //~v6G0I~
//                    targetrect=*Ptgtrect;                        //~v6G0I~
//                    targetrect.Left  =tgtpos.X;                  //~v6G0I~
//                    targetrect.Right =tgtpos.X+(SHORT)chictr-1;  //ucs ctr//~v6G0I~
//                    posinsrcbuff.X  =0;                     //pos in parm buff//~v6G0I~
//                    posinsrcbuff.Y  =0;                     //pos in parm buff//~v6G0I~
//                    srcbufsz.X  =(SHORT)chictr;    //rect of parm buff,width//~v6G0I~
//                    srcbufsz.Y  =1;       //rect of parm buff,height//~v6G0I~
//                    UTRACEP("uviowrtcellW1 combine ucs=%04x-%04x,col=%d,chwidth=%d\n",*pucs,*(pucs+1),tgtpos.X,chwidth);//~v6G0I~
//                    rc2=uvioWriteConsoleOutputW(Shconout,wkcombinechi,srcbufsz,posinsrcbuff,&targetrect);//~v6G0I~
//                }                                                //~v6G0I~
//                else                                             //~v6G0I~
//                {                                                //~v6G0I~
//                    rc2=uvioWriteConsoleOutputCharacterW1withAttr1(0,Shconout,pucs,1,tgtpos,&writelen,Ptgtrect,pattr,chwidth); //len written//~v6G0I~
//UTRACEP("%s: combine normal ucs=%04x,col=%d,chwidth=%d\n",UTT,*pucs,tgtpos.X,chwidth);//~v6G0I~
//                }                                                //~v6G0I~
//            }                                                    //~v6G0I~
//            if (!rc2)                                            //~v6G0I~
//            {                                                    //~v6G0I~
//                rc++;                                            //~v6G0I~
//            }                                                    //~v6G0I~
//            writelend+=writelen;                                 //~v6G0I~
//            pdbcs+=chwidth;                                      //~v6G0I~
//            pattr+=chwidth;                                      //~v6G0I~
//            pdata+=chwidth;                                      //~v6G0I~
//            tgtpos.X+=(SHORT)chwidth;                            //~v6G0I~
//            col+=chwidth;                                        //~v6G0I~
//            attro=attr;                                          //~v6G0I~
//          }                                                      //~v6G0I~
//          else                                                   //~v6G0I~
////*not combinemode                                               //~v6G0I~
//          {                                                      //~v6G0I~
//           if (swovf) //ucs4                                     //~v6G0I~
//           {                                                     //~v6G0I~
//            if (!uvioWriteConsoleOutputCharacterW1withAttr1(0,Shconout,pucs,2,tgtpos,&writelen,Ptgtrect,pattr,chwidth)) //len written//~v6G0I~
//                rc++;                                            //~v6G0I~
//UTRACEP("%s: not combinemode OVF ucs=%04x-%04x,col=%d,chwidth=%d\n",UTT,*pucs,*(pucs+1),tgtpos.X,chwidth);//~v6G0I~
//            ii++;    //vs. loop limit ucsctr                     //~v6G0I~
//            pucs++; //printed 2 ucs2                             //~v6G0I~
//                                                                 //~v6G0I~
//           }                                                     //~v6G0I~
//           else                                                  //~v6G0I~
//           {                                                     //~v6G0I~
////locale code                                                    //~v6G0I~
//            if (ii+1<ucsctr && IS_UTF16_PAIR(*pucs,*(pucs+1)))   //~v6G0I~
//            {                                                    //~v6G0I~
//                if (!uvioWriteConsoleOutputCharacterW1withAttr1(0,Shconout,pucs,2,tgtpos,&writelen,Ptgtrect,pattr,chwidth)) //len written//~v6G0I~
//                    rc++;                                        //~v6G0I~
//                ii++;                                            //~v6G0I~
//                pucs++;                                          //~v6G0I~
//            }                                                    //~v6G0I~
//            else                                                 //~v6G0I~
//            if (m2uopt                                           //~v6G0I~
//            &&  UDBCSCHK_ISUCSWIDTH0(*pdbcs)                     //~v6G0I~
//            &&  !COMBINEMODE(Popt)                               //~v6G0I~
//            )                                                    //~v6G0I~
//            {                                                    //~v6G0I~
//             {                                                   //~v6G0I~
//                UTRACEP("%s:write Gutfcombaltch=%04x\n",UTT,Gutfcombaltch);//~v6G0I~
//              if (UTF_COMBINEMODE_NP() && Gutfcombaltch)         //~v6G0I~
//                ucs=(WUCS)Gutfcombaltch;                         //~v6G0I~
//                if (!uvioWriteConsoleOutputCharacterW1withAttr1(0,Shconout,&ucs,1,tgtpos,&writelen,Ptgtrect,pattr,chwidth)) //len written//~v6G0I~
//                    rc++;                                        //~v6G0I~
//                attr=(pattr0[tgtpos.X] & 0xf0)|ATTR_COMBINENP_FG;//~v6G0I~
//                rc+=WriteConsoleOutputAttribute(Shconout,&attr,1,tgtpos,&writelen)==0;          //writelen//~v6G0I~
//             }                                                   //~v6G0I~
//            }                                                    //~v6G0I~
//            else                                                 //~v6G0I~
//            if (!uvioWriteConsoleOutputCharacterW1withAttr1(0,Shconout,pucs,1,tgtpos,&writelen,Ptgtrect,pattr,chwidth)) //len written//~v6G0I~
//                rc++;                                            //~v6G0I~
//                if (chwidth>2)                                   //~v6G0I~
//                {                                                //~v6G0I~
//                  if (chwidth==4   //gb18030                     //~v6G0I~
//                  &&  !IS_UTF16_HIGH(ucs)                        //~v6G0I~
//                  &&  utfwcwidth(0,(ULONG)ucs,&fontflag)==1)     //~v6G0I~
//                  {                                              //~v6G0I~
//                    if (!uviom_displaydbcspad(Ptgtrect,tgtpos.X+1,chwidth-1))//~v6G0I~
//                        rc++;                                    //~v6G0I~
//                    writelend+=chwidth-1;                        //~v6G0I~
//                  }                                              //~v6G0I~
//                  else                                           //~v6G0I~
//                  {                                              //~v6G0I~
//                    if (!uviom_displaydbcspad(Ptgtrect,tgtpos.X+2,chwidth-2))//~v6G0I~
//                        rc++;                                    //~v6G0I~
//                    writelend+=chwidth-2;                        //~v6G0I~
//                  }                                              //~v6G0I~
//                }                                                //~v6G0I~
//           }                                                     //~v6G0I~
//UTRACEP("uviowrtcellW1 not combinemode ucs=%04x,col=%d,chwidth=%d\n",*pucs,tgtpos.X,chwidth);//~v5n8R~//~v6G0I~
//            writelend+=writelen;                                 //~v6G0I~
//            pdbcs+=chwidth;                                      //~v6G0I~
//            pattr+=chwidth;                                      //~v6G0I~
//            pdata+=chwidth;                                      //~v6G0I~
//            tgtpos.X+=(SHORT)chwidth;                            //~v6G0I~
//          }                                                      //~v6G0I~
//        }                                                        //~v6G0I~
//*********************************************************************************//~v6G0I~
//*by WriteOutputCharcter for cpu8 file                            //~v6G0I~
//*********************************************************************************//~v6G0I~
int uviowrtcellW1_cpu8file_NoLigatureNoCombine(int Popt,WUCS *Ppucs,int Pucsctr,UCHAR *Ppdata,UCHAR *Ppdbcs,USHORT *Ppattr,int Plen,SMALL_RECT *Ptgtrect)//~v6G0R~
{                                                                  //~v6G0I~
    int rc=0;                                                      //~v6G0I~
	COORD tgtpos;                                                  //~v6G0I~
    int writelen=0;                                                //~v6G0R~
    UCHAR *pdbcs,*pdata;                                           //~v6G0R~
    WUCS  *pucs;                                                   //~v6G0R~
    USHORT *pattr;                                                 //~v6G0R~
    int ii,chwidth,writelend=0;                                    //~v6G0R~
    int col;                                                       //~v6G0R~
    USHORT attr;                                                   //~v6G0R~
    UCHAR *pdbcsend;                                               //~v6G0I~
    int swdbcsspaceutf8;                                           //~v6G0I~
    WUCS   wkaltch[2];                                             //~v6G0I~
    WUCS   ucs;                                                    //~v6G0I~
//********************************                                 //~v6G0I~
    UTRACEP("%s:opt=%x,ucsctr=%d,len=%d,x=%d,y=%d\n",UTT,Popt,Pucsctr,Plen,Ptgtrect->Left,Ptgtrect->Top);//~v6G0R~
    UTRACED("ucs",Ppucs,Pucsctr*(int)sizeof(WUCS));                //~v6G0R~
    UTRACED("data",Ppdata,Plen);                                   //~v6G0R~
    UTRACED("dbcs",Ppdbcs,Plen);                                   //~v6G0R~
    UTRACED("attr",Ppattr,(int)sizeof(USHORT)*Plen);               //~v6G0R~
    tgtpos.X=Ptgtrect->Left;                                       //~v6G0R~
    tgtpos.Y=Ptgtrect->Top;                                        //~v6G0R~
    uviom_clearlineW(UVIOMCLO_ATTRSTR,0/*data*/,Ppattr,Plen,tgtpos);//~v6G0R~
    col=0;  //start col                                            //~v6G0R~
    pdata=Ppdata;                                                  //~v6G0R~
    pattr=Ppattr;                                                  //~v6G0R~
    pdbcsend=Ppdbcs+Plen;                                          //~v6G0R~
    for (rc=0,ii=0,pucs=Ppucs,pdbcs=Ppdbcs;ii<Pucsctr;ii++,pucs++) //~v6G0R~
    {                                                              //~v6G0R~
        ucs=*pucs;                                                 //~v6G0R~
        UTRACEP("%s:ucs=%x,attrr=%x,dbcsid=%x,data=%x\n",UTT,*pucs,*pattr,*pdbcs,*pdata);//~v6G0R~
//#Windows    no GB4support  UDBCSCHK_DBCS                         //~v6G0I~
        swdbcsspaceutf8=0;                                         //~v6G0R~
                                                                   //~v6G0I~
//      chwidth=UDBCSCHK_DBCS1STUCS2NW(*pdbcs)+1;                  //~v6G0R~
        chwidth=UDBCSCHK_DBCS1STUCS2NWO(*pdbcs)+1;                 //~v6G0I~
        if (*pucs==DBCSSPACE_ALT2   //ffff                         //~v6G0R~
        &&  *pdbcs==UDBCSCHK_DBCS1STUCS)    //tabdisplay set ffff/() for dbcsspace//~v6G0R~
            swdbcsspaceutf8=1;                                     //~v6G0R~
        UTRACEP("%s:W1 chwidth=%d,data=%x,dbcs=%x,ucs=%x\n",UTT,chwidth,*pdata,*pdbcs,*pucs);//~v6G0R~
        if (swdbcsspaceutf8)                                       //~v6G0R~
        {                                                          //~v6G0R~
            chwidth=2;                                             //~v6G0R~
            wkaltch[0]=(WUCS)Sdbcsspacealt;                        //~v6G0R~
            wkaltch[1]=wkaltch[0];                                 //~v6G0R~
//          if (!uvioWriteConsoleOutputCharacterW1withAttr1(0,Shconout,wkaltch,2,tgtpos,&writelen,Ptgtrect,pattr,chwidth)) //len written//~v6G0R~
//              rc++;                                              //~v6G0R~
			rc+=uvioWriteConsoleOutputCharacterW(Shconout,wkaltch,2,tgtpos,&writelen)==0;//~v6G0R~
UTRACEP("%s:write dbcsspaceutf8 ucs=%04x,col=%d\n",UTT,ucs,tgtpos.X);//~v6G0R~
            writelend+=writelen;                                   //~v6G0R~
            pdbcs+=chwidth;                                        //~v6G0R~
            pdata+=chwidth;                                        //~v6G0R~
            tgtpos.X+=(SHORT)chwidth;                              //~v6G0R~
            pattr+=chwidth;                                        //~v6G0R~
        }                                                          //~v6G0R~
        else                                                       //~v6G0R~
//*not dbcsspace                                                   //~v6G0R~
        {                                                          //~v6G0R~
            if (ii+1<Pucsctr && IS_UTF16_PAIR(*pucs,*(pucs+1)))    //~v6G0R~
            {                                                      //~v6G0I~
//              if (!uvioWriteConsoleOutputCharacterW1withAttr1(0,Shconout,pucs,2,tgtpos,&writelen,Ptgtrect,pattr,chwidth)) //len written//~v6G0R~
//                  rc++;                                          //~v6G0R~
				rc+=uvioWriteConsoleOutputCharacterW(Shconout,pucs,2,tgtpos,&writelen)==0;//~v6G0R~
                ii++;                                              //~v6G0I~
                pucs++;                                            //~v6G0I~
            }                                                      //~v6G0I~
            else                                                   //~v6G0I~
            if (                                                   //~v6G0R~
                UDBCSCHK_ISUCSWIDTH0(*pdbcs)                       //~v6G0R~
            )                                                      //~v6G0I~
            {                                                      //~v6G0I~
            //*width0 under no combinemode                         //~v6G0I~
                UTRACEP("%s:write Gutfcombaltch=%04x\n",UTT,Gutfcombaltch);//~v6G0I~
                if (UTF_COMBINEMODE_NP() && Gutfcombaltch)         //~v6G0R~
                	ucs=(WUCS)Gutfcombaltch;                       //~v6G0R~
//              if (!uvioWriteConsoleOutputCharacterW1withAttr1(0,Shconout,&ucs,1,tgtpos,&writelen,Ptgtrect,pattr,chwidth)) //len written//~v6G0R~
//                  rc++;                                          //~v6G0R~
                attr=(Ppattr[tgtpos.X] & 0xf0)|ATTR_COMBINENP_FG;  //~v6G0R~
                rc+=WriteConsoleOutputAttribute(Shconout,&attr,1,tgtpos,&writelen)==0;          //writelen//~v6G0I~
				rc+=uvioWriteConsoleOutputCharacterUCS1(Shconout,ucs,tgtpos,&writelen)==0;//~v6G0I~
            }                                                      //~v6G0I~
            else                                                   //~v6G0I~
//          if (!uvioWriteConsoleOutputCharacterW1withAttr1(0,Shconout,pucs,1,tgtpos,&writelen,Ptgtrect,pattr,chwidth)) //len written//~v6G0R~
//              rc++;                                              //~v6G0R~
				rc+=uvioWriteConsoleOutputCharacterUCS1(Shconout,ucs,tgtpos,&writelen)==0;//~v6G0I~
                                                                   //~v6G0I~
UTRACEP("%s: not combinemode ucs=%04x,col=%d,chwidth=%d\n",UTT,*pucs,tgtpos.X,chwidth);//~v6G0R~
            writelend+=writelen;                                   //~v6G0I~
            pdbcs+=chwidth;                                        //~v6G0I~
            pattr+=chwidth;                                        //~v6G0I~
            pdata+=chwidth;                                        //~v6G0I~
            tgtpos.X+=(SHORT)chwidth;                              //~v6G0R~
        }//not dbcsspace                                           //~v6G0R~
    }//for                                                         //~v6G0R~
    return rc;                                                     //~v6G0R~
}//uviowrtcellW1_cpu8file_NonLigatureNoCombine                     //~v6G0R~
//*********************************************************************************//~v6G0I~
//*lig:off display combined char under combinemode                 //~v6G0R~
//*********************************************************************************//~v6G0I~
int uviowrtcellW1_cpu8file_NoLigatureCombinedString(int Popt,WUCS *Ppucs,int Pucsctr,USHORT *Ppattr,SMALL_RECT *Ptgtrect)//~v6G0I~
{                                                                  //~v6G0I~
    WUCS   wkucs[UVIOM_MAXCOMBINE];                                //~v6G0I~
    COORD  tgtpos;                                                 //~v6G0I~
    int ii,wrtlen,rc=0,ucsctr,len;                                 //~v6G0R~
    USHORT attr;                                                   //~v6G0I~
//**************************************                           //~v6G0I~
	tgtpos.X=Ptgtrect->Left;                                       //~v6G0R~
	tgtpos.Y=Ptgtrect->Top;                                        //~v6G0R~
    len=Ptgtrect->Right-Ptgtrect->Left+1;                          //~v6G0I~
UTRACEP("%s:ucsctr=%d,X=%d,Y=%d,Guviomdbcspad=%x\n",UTT,Pucsctr,tgtpos.X,tgtpos.Y,Guviomdbcspad);//~v6G0R~
	ucsctr=min((int)sizeof(wkucs),Pucsctr);                        //~v6G0I~
	if (Guviomdbcspad!=' ')                                        //~v6G0I~
    {                                                              //~v6G0I~
		for (ii=0;ii<len;ii++)                                     //~v6G0R~
    		wkucs[ii]=Guviomdbcspad;                               //~v6G0R~
        attr=(*Ppattr & 0xf0)/*bg*/|UVIOM_PADATTR/*fg*/;           //~v6G0I~
    	uviom_clearlineW(UVIOMCLO_ATTRFILL,0/*data*/,&attr,len,tgtpos);//~v6G0R~
		rc+=uvioWriteConsoleOutputCharacterW(Shconout,wkucs,len,tgtpos,&wrtlen)==0;//~v6G0R~
    }                                                              //~v6G0I~
	uviom_clearlineW(UVIOMCLO_ATTRSTR,0/*data*/,Ppattr,len,tgtpos);//~v6G0R~
	rc+=uvioWriteConsoleOutputCharacterW(Shconout,Ppucs,ucsctr,tgtpos,&wrtlen)==0;//~v6G0R~
    UTRACEP("%s:return rc=%d\n",UTT,rc);                           //~v6G0R~
    return rc;                                                     //~v6G0I~
}//uviowrtcellW1_cpu8file_NoLigatureCombinedString                 //~v6G0I~
//*********************************************************************************//~v6G0I~
//*lig:off and combine mode(string split by csrpos)                //~v6G0R~
//*********************************************************************************//~v6G0I~
int uviowrtcellW1_cpu8file_NoLigatureCombineColSplit(int Popt,WUCS *Ppucs,int Pucsctr,UCHAR *Ppdata,UCHAR *Ppdbcs,USHORT *Ppattr,int Plen,SMALL_RECT *Ptgtrect)//~v6G0R~
{                                                                  //~v6G0I~
    WUCS   *pucs,ucs2;                                             //~v6G0R~
    SMALL_RECT tgtrect;                                            //~v6G0I~
    int ii,len,rc=0,col,pos,poso,colo,ucsctr,chwidth,combinectr,left;//~v6G0R~
    UCHAR *pdata,*pdbcs;                                           //~v6G0I~
//************************                                         //~v6G0I~
    left=Ptgtrect->Left;                                           //~v6G0R~
    UTRACEP("%s:ucsctr=%d,len=%d,xx=%d\n",UTT,Pucsctr,Plen,left);  //~v6G0I~
    UTRACED("ucs",Ppucs,Pucsctr*(int)sizeof(WUCS));                //~v6G0I~
    UTRACED("data",Ppdata,Plen);                                   //~v6G0I~
    UTRACED("dbcs",Ppdbcs,Plen);                                   //~v6G0I~
    UTRACED("attr",Ppattr,Plen*(int)sizeof(USHORT));               //~v6G0I~
    tgtrect=*Ptgtrect;                                             //~v6G0I~
   	for (ii=0,poso=-1,colo=0,col=0,pos=0,pucs=Ppucs,pdata=Ppdata,pdbcs=Ppdbcs;ii<Pucsctr;ii++,pucs++,pos++)//~v6G0R~
    {                                                              //~v6G0I~
    	if (poso<0)                                                //~v6G0R~
        {                                                          //~v6G0I~
        	poso=pos;                                              //~v6G0I~
            colo=col;                                              //~v6G0I~
        }                                                          //~v6G0I~
	    if (UDBCSCHK_ISUCSWIDTH0(*pdbcs))   //split at combining char//~v6G0R~
        {                                                          //~v6G0I~
	   		UTRACEP("%s:cpos width0 col=%d\n",UTT,col);            //~v6G0R~
            tgtrect.Left=(SHORT)(left+col);                        //~v6G0R~
            tgtrect.Right=(SHORT)(left+col);                       //~v6G0R~
			rc+=uviowrtcellW1_cpu8file_NoLigatureCombinedString(Popt,pucs,1,Ppattr+col,&tgtrect);//~v6G0I~
            chwidth=1;                                             //~v6G0I~
        }                                                          //~v6G0I~
        else                                                       //~v6G0I~
        {                                                          //~v6G0I~
            ucs2=*pucs;                                            //~v6G0R~
            chwidth=UDBCSCHK_DBCS1STUCS2NWO(*pdbcs)+1;             //~v6G0R~
            if (ii+1<Pucsctr)                                      //~v6G0R~
                combinectr=uvio_getcombinectr(0,ucs2,chwidth,pdbcs,Pucsctr-ii);//~v6G0R~
            else                                                   //~v6G0R~
                combinectr=0;                                      //~v6G0R~
            UTRACEP("%s:ucs=%x,combinectr=%d,pdbcs=%p\n",UTT,ucs2,combinectr,pdbcs);//~v6G0R~
            if (combinectr)                                        //~v6G0R~
            {                                                      //~v6G0R~
                ucsctr=pos-poso;                                   //~v6G0R~
                if (ucsctr>0)                                      //~v6G0R~
                {                                                  //~v6G0R~
                    len=col-colo;                                  //~v6G0R~
                    tgtrect.Left=(SHORT)(left+colo);               //~v6G0R~
                    tgtrect.Right=tgtrect.Left+(SHORT)len-1;       //~v6G0R~
                    rc+=uviowrtcellW1_cpu8file_NoLigatureNoCombine(Popt,Ppucs+poso,ucsctr,Ppdata+colo,Ppdbcs+colo,Ppattr+colo,len,&tgtrect);//~v6G0R~
                }                                                  //~v6G0I~
                len=chwidth+combinectr;                            //~v6G0I~
                tgtrect.Left=(SHORT)(left+col);                    //~v6G0R~
                tgtrect.Right=tgtrect.Left+(SHORT)(len-1);         //~v6G0R~
                ucsctr=combinectr+1;                               //~v6G0R~
                rc+=uviowrtcellW1_cpu8file_NoLigatureCombinedString(Popt,pucs,ucsctr,Ppattr+col,&tgtrect);//~v6G0R~
                poso=-1;                                           //~v6G0R~
                colo=0;                                            //~v6G0R~
                col+=combinectr;  //colomn                         //~v6G0R~
                pdbcs+=combinectr;                                 //~v6G0R~
                ii+=combinectr;                                    //~v6G0I~
                pucs+=combinectr;                                  //~v6G0I~
                pos+=combinectr;   //ucs pos                       //~v6G0R~
            }                                                      //~v6G0R~
        }                                                          //~v6G0I~
        col+=chwidth;                                              //~v6G0R~
        pdbcs+=chwidth;                                            //~v6G0I~
        if (ii+1<Pucsctr && IS_UTF16_PAIR(*pucs,*(pucs+1)))        //~v6G0I~
        {                                                          //~v6G0I~
            ii++;                                                  //~v6G0I~
            pos++;                                                 //~v6G0I~
            pucs++;                                                //~v6G0I~
        }                                                          //~v6G0I~
    }                                                              //~v6G0I~
    ucsctr=Pucsctr-poso;                                           //~v6G0I~
    if (poso>=0 && ucsctr>0)                                       //~v6G0R~
    {                                                              //~v6G0I~
        len=col-colo;                                              //~v6G0R~
        tgtrect.Left=(SHORT)(left+colo);                           //~v6G0R~
        tgtrect.Right=tgtrect.Left+(SHORT)len-1;                   //~v6G0I~
        rc+=uviowrtcellW1_cpu8file_NoLigatureNoCombine(Popt,Ppucs+poso,ucsctr,Ppdata+colo,Ppdbcs+colo,Ppattr+colo,len,&tgtrect);//~v6G0I~
    }                                                              //~v6G0I~
    UTRACEP("%s:return rc=%d\n",UTT,rc);                           //~v6G0R~
    return rc;                                                     //~v6G0I~
}//uviowrtcellW1_cpu8file_NoLigatureCombineColSplit                //~v6G0R~
//*********************************************************************************//~v6G0I~
//*lig:off and combine mode                                        //~v6G0I~
//*********************************************************************************//~v6G0I~
int uviowrtcellW1_cpu8file_NoLigatureCombine(int Popt,WUCS *Ppucs,int Pucsctr,UCHAR *Ppdata,UCHAR *Ppdbcs,USHORT *Ppattr,int Plen,SMALL_RECT *Ptgtrect)//~v6G0I~
{                                                                  //~v6G0I~
	int posa,posb,posc=-1,posbvhex,poscvhex=-1,col,ii,chwidth,len,ucsctr,rc=0,xx,yy;//~v6G0R~
    UCHAR *pdbcs;                                                  //~v6G0I~
    SMALL_RECT tgtrect;                                            //~v6G0I~
    WUCS *pucs;                                                    //~v6G0I~
//**************************************************               //~v6G0M~
    xx=Ptgtrect->Left;                                             //~v6G0I~
    yy=Ptgtrect->Top;                                              //~v6G0I~
    UTRACEP("%s:xx=%d,yy=%d,Scsrposx=%d,Svhexcsrposx=%d,Scsrposy=%d,Svhexcsrposy=%d\n",UTT,xx,yy,Scsrposx,Svhexcsrposx,Scsrposy,Svhexcsrposy);//~v6G0I~
    if (yy==Scsrposy+Stoplineoffs)    //csr line                   //~v6G0R~
    {                                                              //~v6G0I~
        utfddgetcsrposbca(0,Ppdbcs-xx,Plen+xx,Scsrposx,&posb,&posc,&posa);//~v6G0R~
        UTRACEP("%s:line Y=%d X=%d,top=%d,csrY=%d posb=%d,posc=%d,posa=%d\n",UTT,yy,xx,Stoplineoffs,Scsrposy,posb,posc,posa);//~v6G0R~
    }                                                              //~v6G0I~
    if (yy==Svhexcsrposy+Stoplineoffs)    //csr line               //~v6G0R~
    {                                                              //~v6G0I~
        utfddgetcsrposbca(0,Ppdbcs-xx,Plen+xx,Svhexcsrposx,&posbvhex,&poscvhex,0/*after*/);//~v6G0R~
        UTRACEP("%s:line Y=%d X=%d,top=%d,csrY=%d xposb=%d,xposc=%d\n",UTT,yy,xx,Stoplineoffs,Scsrposy,posbvhex,poscvhex);//~v6G0R~
    }                                                              //~v6G0I~
	if (posc>=0 || poscvhex>=0)                                    //~v6G0R~
    {                                                              //~v6G0I~
    	for (ii=0,col=0,pucs=Ppucs,pdbcs=Ppdbcs;ii<Pucsctr;ii++,pucs++)//~v6G0R~
    	{                                                          //~v6G0I~
    		if (col==posc || col==poscvhex)                        //~v6G0I~
            	break;                                             //~v6G0I~
	        chwidth=UDBCSCHK_DBCS1STUCS2NWO(*pdbcs)+1;             //~v6G0I~
        	UTRACEP("%s:chwidth=%d ucs=%x dbcs=%x\n",UTT,chwidth,*(Ppucs+ii),*pdbcs);//~v6G0R~
            pdbcs+=chwidth;                                        //~v6G0I~
            col+=chwidth;                                          //~v6G0I~
            if (ii+1<Pucsctr && IS_UTF16_PAIR(*pucs,*(pucs+1)))    //~v6G0I~
            {                                                      //~v6G0I~
                ii++;                                              //~v6G0I~
                pucs++;                                            //~v6G0I~
            }                                                      //~v6G0I~
        }                                                          //~v6G0I~
        if (col)                                                   //~v6G0I~
        {                                                          //~v6G0I~
        	ucsctr=ii;                                             //~v6G0I~
        	len=col;                                               //~v6G0I~
	        tgtrect=*Ptgtrect;                                     //~v6G0I~
            tgtrect.Right=(SHORT)col-1;                            //~v6G0R~
			rc+=uviowrtcellW1_cpu8file_NoLigatureCombineColSplit(Popt,Ppucs,ucsctr,Ppdata,Ppdbcs,Ppattr,len,&tgtrect);//~v6G0R~
        }                                                          //~v6G0I~
        ucsctr=Pucsctr-ii;                                         //~v6G0I~
        len=Plen-col;                                              //~v6G0I~
        tgtrect=*Ptgtrect;                                         //~v6G0I~
        tgtrect.Left=(SHORT)col;                                   //~v6G0R~
		rc+=uviowrtcellW1_cpu8file_NoLigatureCombineColSplit(Popt,Ppucs+ii,ucsctr,Ppdata+col,Ppdbcs+col,Ppattr+col,len,&tgtrect);//~v6G0R~
    }                                                              //~v6G0I~
    else                                                           //~v6G0I~
		rc+=uviowrtcellW1_cpu8file_NoLigatureCombineColSplit(Popt,Ppucs,Pucsctr,Ppdata,Ppdbcs,Ppattr,Plen,Ptgtrect);//~v6G0R~
    return rc;                                                     //~v6G0I~
}//uviowrtcellW1_cpu8file_NoLigatureCombine                        //~v6G0I~
#ifdef QQQ                                                         //~v6G0I~
//*********************************************************************************//~v6G0I~
//*lig:on display combined char on cursor                          //~v6G0R~
//*********************************************************************************//~v6G0I~
int uviowrtcellW1_cpu8file_LigatureCombinedSplitString(int Popt,WUCS *Ppucs,int Pucsctr,UCHAR *Ppdbcs,USHORT *Ppattr,SMALL_RECT *Ptgtrect,int *Ppwrtctr,int *Ppwrtlen)//~v6G0R~
{                                                                  //~v6G0I~
    WUCS   *pucs,wkucs[2];                                         //~v6G0R~
    COORD  tgtpos;                                                 //~v6G0I~
    int ii,rc=0,ucsctr,wrtlen=0,chwidth,wrtctr=0,totlen=0;         //~v6G0R~
    USHORT attr,*pattr;                                            //~v6G0R~
    UCHAR *pdbcs;                                                  //~v6G0I~
//**************************************                           //~v6G0I~
	tgtpos.X=Ptgtrect->Left;                                       //~v6G0I~
	tgtpos.Y=Ptgtrect->Top;                                        //~v6G0I~
	UTRACEP("%s:ucsctr=%d,X=%d,Y=%d\n",UTT,Pucsctr,tgtpos.X,tgtpos.Y);//~v6G0I~
    pucs=Ppucs;                                                    //~v6G0I~
    pdbcs=Ppdbcs;                                                  //~v6G0I~
    pattr=Ppattr;                                                  //~v6G0I~
    ucsctr=Pucsctr;                                                //~v6G0I~
	if (!UDBCSCHK_ISUCSWIDTH0(*pdbcs))   //top is not combining    //~v6G0I~
    {                                                              //~v6G0I~
        chwidth=UDBCSCHK_DBCS1STUCS2NWO(*pdbcs)+1;                 //~v6G0M~
    	uviom_clearlineW(UVIOMCLO_ATTRFILL,0/*data*/,pattr,chwidth,tgtpos);//~v6G0R~
		rc+=uvioWriteConsoleOutputCharacterW(Shconout,pucs,1,tgtpos,&wrtlen)==0;//~v6G0I~
        pucs++;                                                    //~v6G0I~
        ucsctr--;                                                  //~v6G0I~
        pdbcs+=chwidth;                                            //~v6G0I~
        pattr+=chwidth;                                            //~v6G0I~
		tgtpos.X+=(SHORT)chwidth;                                  //~v6G0R~
        wrtctr=1;                                                  //~v6G0R~
        totlen+=chwidth;                                           //~v6G0I~
    }                                                              //~v6G0I~
    for (ii=0;ii<ucsctr;ii++,pucs++,pdbcs++,pattr++)               //~v6G0R~
    {                                                              //~v6G0I~
        if (!UDBCSCHK_ISUCSWIDTH0(*pdbcs))   //split at combining char by UFCleft or after posincombine//~v6G0I~
            break;                                                 //~v6G0I~
        if (UTF_COMBINEMODE_NP() && Gutfcombaltch)                 //~v6G0I~
        {                                                          //~v6G0I~
    		wkucs[0]=Gutfcombaltch;                                //~v6G0I~
            attr=(*pattr & 0xf0)|ATTR_COMBINE_FG;                  //~v6G0I~
        }                                                          //~v6G0I~
        else                                                       //~v6G0I~
        {                                                          //~v6G0I~
    		wkucs[0]=*pucs;                                        //~v6G0I~
        	if (ii%2)     //      03,01,03,01,...                  //~v6G0R~
        		attr=(*pattr & 0xf0)|ATTR_COMBINE_FG2;             //~v6G0R~
        	else                                                   //~v6G0R~
            	attr=(*pattr & 0xf0)|ATTR_COMBINE_FG;              //~v6G0R~
        }                                                          //~v6G0I~
	    uviom_clearlineW(UVIOMCLO_ATTRFILL,0/*data*/,&attr,1,tgtpos);//~v6G0I~
		rc+=uvioWriteConsoleOutputCharacterW(Shconout,wkucs,1,tgtpos,&wrtlen)==0;//~v6G0I~
		tgtpos.X++;                                                //~v6G0I~
        wrtctr++;                                                  //~v6G0R~
        totlen++;                                                  //~v6G0I~
    }                                                              //~v6G0I~
    *Ppwrtctr=wrtctr;                                              //~v6G0I~
    *Ppwrtlen=totlen;                                              //~v6G0I~
    UTRACEP("%s:return rc=%d,wrtctr=%d,writelen=%d\n",UTT,rc,wrtctr,totlen);//~v6G0R~
    return rc;                                                     //~v6G0I~
}//uviowrtcellW1_cpu8file_LigatureCombinedSplitString              //~v6G0I~
//*********************************************************************************//~v6G0I~
//*lig:on (string split by csrpos)                                 //~v6G0I~
//*********************************************************************************//~v6G0I~
int uviowrtcellW1_cpu8file_LigatureColSplitDBCS(int Popt,WUCS *Ppucs,int Pucsctr,UCHAR *Ppdata,UCHAR *Ppdbcs,USHORT *Ppattr,int Plen,SMALL_RECT *Ptgtrect,int Pposincombine)//~v6G0R~
{                                                                  //~v6G0I~
    WUCS   *pucs,ucs2;                                             //~v6G0I~
    int ii,jj,rc=0,chwidth,combinectr,writelen,wrtctr,pos,offs=0,adducsctr=0;//~v6G0R~
    UCHAR *pdbcs;                                                  //~v6G0R~
    USHORT wkattr[UVIOM_MAXCOL],*pattr,*pattro,attr,attr2;         //~v6G0R~
    WUCS  wkucs[UVIOM_MAXCOL],*pucso;                              //~v6G0R~
    COORD tgtpos;                                                  //~v6G0R~
    SMALL_RECT tgtrect;                                            //~v6G0I~
//************************                                         //~v6G0I~
    UTRACEP("%s:ucsctr=%d,len=%d,left=%d,posincombine=%d\n",UTT,Pucsctr,Plen,Ptgtrect->Left,Pposincombine);//~v6G0I~
    UTRACED("ucs",Ppucs,Pucsctr*(int)sizeof(WUCS));                //~v6G0I~
    UTRACED("data",Ppdata,Plen);                                   //~v6G0I~
    UTRACED("dbcs",Ppdbcs,Plen);                                   //~v6G0I~
    UTRACED("attr",Ppattr,Plen*(int)sizeof(USHORT));               //~v6G0I~
    tgtrect=*Ptgtrect;                                             //~v6G0I~
    pucs=Ppucs; pdbcs=Ppdbcs; pattr=Ppattr;                        //~v6G0I~
    pos=0;                                                         //~v6G0I~
    if (Pposincombine)   //top is combining string and cpos is on width0 char//~v6G0R~
    {                                                              //~v6G0I~
    	UTRACEP("%s:top combine posincombine\n",UTT);              //~v6G0R~
		rc+=uviowrtcellW1_cpu8file_LigatureCombinedSplitString(Popt,pucs,Pucsctr,pdbcs,pattr,&tgtrect,&wrtctr,&writelen);//~v6G0R~
        pucs+=wrtctr;                                              //~v6G0I~
        offs+=writelen;                                            //~v6G0I~
        pos=wrtctr;                                                //~v6G0I~
        tgtrect.Left+=(SHORT)writelen;                             //~v6G0R~
        chwidth=UDBCSCHK_DBCS1STUCS2NWO(*pdbcs)+1;                 //~v6G0M~
        pdbcs+=writelen;                                           //~v6G0R~
        pattr+=writelen;                                           //~v6G0R~
    }                                                              //~v6G0I~
    else                                                           //~v6G0I~
    if (UDBCSCHK_ISUCSWIDTH0(*pdbcs))   //split at combining char by UFCleft//~v6G0I~
    {                                                              //~v6G0I~
    	UTRACEP("%s:top split combine\n",UTT);                     //~v6G0R~
		rc+=uviowrtcellW1_cpu8file_LigatureCombinedSplitString(Popt,pucs,Pucsctr,pdbcs,pattr,&tgtrect,&wrtctr,&writelen);//~v6G0R~
    	pucs+=wrtctr;                                              //~v6G0I~
        offs+=writelen;                                            //~v6G0I~
    	pos=wrtctr;                                                //~v6G0I~
        tgtrect.Left+=(SHORT)writelen;                             //~v6G0I~
   		pdbcs+=wrtctr;                                             //~v6G0I~
    	pattr+=wrtctr;                                             //~v6G0I~
    }//                                                            //~v6G0I~
   	for (ii=pos,pucso=wkucs,pattro=wkattr;ii<Pucsctr;ii++,pucs++)  //~v6G0R~
    {                                                              //~v6G0I~
    	ucs2=*pucs;                                                //~v6G0I~
    	attr=*pattr;                                               //~v6G0I~
        chwidth=1;                                                 //~v6G0I~
    	UTRACEP("%s:ii=%d,ucs=%x,attr=%x,dbcs=%x\n",UTT,ii,ucs2,attr,*pdbcs);//~v6G0R~
        chwidth=UDBCSCHK_DBCS1STUCS2NWO(*pdbcs)+1;                 //~v6G0R~
      	if (ucs2==DBCSSPACE_ALT2   //ffff                          //~v6G0I~
    	&&  *pdbcs==UDBCSCHK_DBCS1STUCS)	//utf8 file, tabdisplay set ffff/() for dbcsspace//~v6G0I~
        {                                                          //~v6G0I~
            *pucso++=(WUCS)Sdbcsspacealt;                          //~v6G0I~
            *pucso++=(WUCS)Sdbcsspacealt;                          //~v6G0I~
            *pattro++=attr;                                        //~v6G0I~
            *pattro++=*(pattr+1);                                  //~v6G0I~
            adducsctr++;	//count up                             //~v6G0I~
        }                                                          //~v6G0I~
        else                                                       //~v6G0I~
        if (!COMBINEMODE(Popt))                                    //~v6G0R~
        {                                                          //~v6G0R~
            if (ii+1<Pucsctr)                                      //~v6G0R~
                combinectr=uvio_getcombinectr(0,ucs2,chwidth,pdbcs,Pucsctr-ii);//~v6G0R~
            else                                                   //~v6G0R~
                combinectr=0;                                      //~v6G0R~
            UTRACEP("%s:ucs=%x,combinectr=%d,pdbcs=%p\n",UTT,ucs2,combinectr,pdbcs);//~v6G0R~
            *pucso++=ucs2;                                         //~v6G0R~
            *pattro++=attr;                                        //~v6G0R~
            if (chwidth>1)                                         //~v6G0I~
    	        *pattro++=*(pattr+1);                              //~v6G0I~
            if (combinectr)                                        //~v6G0M~
            {                                                      //~v6G0M~
                for (jj=0;jj<combinectr;jj++)                      //~v6G0R~
                {                                                  //~v6G0R~
                    attr2=*(pattr+chwidth+jj);                     //~v6G0M~
                    if (UTF_COMBINEMODE_NP() && Gutfcombaltch)     //~v6G0R~
                    {                                              //~v6G0I~
                        *pucso++=(WUCS)Gutfcombaltch;              //~v6G0R~
            			*pattro++=(attr2 & 0xf0)|ATTR_COMBINE_FG;  //~v6G0I~
                    }                                              //~v6G0I~
                    else                                           //~v6G0R~
                    {                                              //~v6G0I~
                        *pucso++=*(pucs+jj+1);                     //~v6G0R~
        				if (jj%2)     //      03,01,03,01,...      //~v6G0R~
        					*pattro++=(attr2 & 0xf0)|ATTR_COMBINE_FG2;//~v6G0R~
        				else                                       //~v6G0R~
            				*pattro++=(attr2 & 0xf0)|ATTR_COMBINE_FG;//~v6G0R~
                    }                                              //~v6G0I~
                }                                                  //~v6G0R~
                pucs+=combinectr;                                  //~v6G0R~
                ii+=combinectr;                                    //~v6G0R~
                pdbcs+=combinectr;                                 //~v6G0R~
                pattr+=combinectr;                                 //~v6G0R~
            }                                                      //~v6G0M~
        }                                                          //~v6G0R~
        else                                                       //~v6G0R~
        {                                                          //~v6G0R~
            *pucso++=ucs2;                                         //~v6G0R~
            *pattro++=attr;                                        //~v6G0R~
            if (chwidth>1)                                         //~v6G0R~
                *pattro++=*(pattr+1);                              //~v6G0R~
        }                                                          //~v6G0R~
        if (ii+1<Pucsctr && IS_UTF16_PAIR(*pucs,*(pucs+1)))        //~v6G0I~
        {                                                          //~v6G0I~
            ii++;                                                  //~v6G0I~
            *pucso++=*++pucs;                                      //~v6G0R~
        }                                                          //~v6G0I~
        pdbcs+=chwidth;                                            //~v6G0I~
        pattr+=chwidth;                                            //~v6G0I~
    }                                                              //~v6G0I~
    tgtpos.X=tgtrect.Left;                                         //~v6G0R~
    tgtpos.Y=tgtrect.Top;                                          //~v6G0R~
    uviom_clearlineW(UVIOMCLO_ATTRSTR,0/*data*/,wkattr,Plen-offs,tgtpos);//~v6G0R~
    rc+=uvioWriteConsoleOutputCharacterW(Shconout,wkucs,Pucsctr-pos+adducsctr,tgtpos,&writelen)==0; //len written//~v6G0R~
    UTRACEP("%s:return rc=%d,adducsctr=%d\n",UTT,rc,adducsctr);    //~v6G0R~
    return rc;                                                     //~v6G0I~
}//uviowrtcellW1_cpu8file_LigatureColSplitDBCS                     //~v6G0R~
//*********************************************************************************//~v6G0I~
//*lig:on (string split by csrpos)                                 //~v6G0I~
//*********************************************************************************//~v6G0I~
int uviowrtcellW1_cpu8file_LigatureColSplit(int Popt,WUCS *Ppucs,int Pucsctr,UCHAR *Ppdata,UCHAR *Ppdbcs,USHORT *Ppattr,int Plen,SMALL_RECT *Ptgtrect,int Pposincombine)//~v6G0R~
{                                                                  //~v6G0I~
    WUCS   ucs2,*pucs,*pucsdbcs=0,*pucscpu8=0;                     //~v6G0R~
    int ii,rc=0,chwidth,dbcsid,wrtlen,ucsctr,mblen,left,len,posincombine,swlocale;//~v6G0R~
    UCHAR *pdbcs,*pdata,*pdatacpu8,*pdbcscpu8,*pdatadbcs,*pdbcsdbcs;//~v6G0R~
    UCHAR wkmbs[UVIOM_MAXCOL],*pco;                                //~v6G0R~
    USHORT *pattr,*pattrcpu8,*pattrdbcs,attrn,attro;               //~v6G0R~
    SMALL_RECT tgtrect;                                            //~v6G0I~
    COORD tgtpos;                                                  //~v6G0I~
//************************                                         //~v6G0I~
    UTRACEP("%s:ucsctr=%d,len=%d,left=%d,posincombine=%d\n",UTT,Pucsctr,Plen,Ptgtrect->Left,Pposincombine);//~v6G0I~
    UTRACED("ucs",Ppucs,Pucsctr*(int)sizeof(WUCS));                //~v6G0I~
    UTRACED("data",Ppdata,Plen);                                   //~v6G0I~
    UTRACED("dbcs",Ppdbcs,Plen);                                   //~v6G0I~
    UTRACED("attr",Ppattr,Plen*(int)sizeof(USHORT));               //~v6G0I~
    posincombine=Pposincombine;                                    //~v6G0I~
    tgtrect=*Ptgtrect;                                             //~v6G0I~
    left=tgtrect.Left;                                             //~v6G0I~
    tgtpos.Y=tgtrect.Top;                                          //~v6G0I~
    attrn=*Ppattr;                                                 //~v6G0I~
    for (ii=0,pucs=Ppucs,pdata=Ppdata,pdbcs=Ppdbcs,pattr=Ppattr,pco=wkmbs;ii<Pucsctr;ii++,pucs++)//~v6G0I~
    {                                                              //~v6G0I~
    	ucs2=*pucs;                                                //~v6G0I~
    	dbcsid=*pdbcs;                                             //~v6G0I~
        attro=attrn;                                               //~v6G0I~
    	attrn=*pattr;                                              //~v6G0I~
        chwidth=UDBCSCHK_DBCS1STUCS2NWO(dbcsid)+1;                 //~v6G0I~
        mblen=0;                                                   //~v6G0I~
        if (UDBCSCHK_DBCS1STUCS2(dbcsid))	//not ovf,printable dbcs//~v6G0I~
        {                                                          //~v6G0I~
      		if (ucs2==DBCSSPACE_ALT2   //ffff                      //~v6G0I~
    		&&  dbcsid==UDBCSCHK_DBCS1STUCS)	//utf8 file, tabdisplay set ffff/() for dbcsspace//~v6G0I~
            	;                                                  //~v6G0I~
            else                                                   //~v6G0I~
		    	mblen=uwctombW(0,ucs2,pco);                        //~v6G0R~
        }                                                          //~v6G0I~
        swlocale=mblen>0;                                          //~v6G0I~
        if (swlocale)                                              //~v6G0I~
        {                                                          //~v6G0I~
            if (ii+1<Pucsctr)                                      //~v6G0I~
                if (UDBCSCHK_ISUCSWIDTH0(*(pdbcs+2)))   //dbcs combining char//~v6G0I~
                	swlocale=0;                                    //~v6G0I~
        }                                                          //~v6G0I~
        if (swlocale)                                              //~v6G0R~
        {                                                          //~v6G0I~
            UTRACEP("%s:locale char col=%d,ucs=%x,dbcs=%x,attro=%x,attrn=%x,pattr=%p\n",UTT,PTRDIFF(pdbcs,Ppdbcs)+left,ucs2,*pdbcs,attro,attrn,pattr);//~v6G0R~
        	if (!pucsdbcs)	//1st w2m dbcs                         //~v6G0I~
            {                                                      //~v6G0I~
            	if (pucscpu8)	//not top of line                  //~v6G0I~
            	{                                                  //~v6G0I~
                	UTRACEP("%s:locale start out cpu8 col=%d,ucs=%x,dbcs=%x\n",UTT,PTRDIFF(pdbcs,Ppdbcs)+left,ucs2,*pdbcs);//~v6G0R~
            		ucsctr=PTRDIFF(pucs,pucscpu8)/(int)sizeof(WUCS);//~v6G0I~
                    len=PTRDIFF(pdbcs,pdbcscpu8);                  //~v6G0I~
	                tgtrect.Right=tgtrect.Left+(short)len-1;       //~v6G0R~
					rc+=uviowrtcellW1_cpu8file_LigatureColSplitDBCS(Popt,pucscpu8,ucsctr,pdatacpu8,pdbcscpu8,pattrcpu8,len,&tgtrect,posincombine);//~v6G0R~
                    pucscpu8=0;                                    //~v6G0I~
                    posincombine=0;                                //~v6G0R~
                }                                                  //~v6G0I~
            	pucsdbcs=pucs;                                     //~v6G0I~
            	pdatadbcs=pdata;                                   //~v6G0I~
            	pdbcsdbcs=pdbcs;                                   //~v6G0I~
            	pattrdbcs=pattr;                                   //~v6G0I~
                tgtrect.Left=(SHORT)(left+PTRDIFF(pdbcs,Ppdbcs));  //~v6G0R~
            }                                                      //~v6G0I~
            else    //2nd dbcs                                     //~v6G0I~
            if (attro!=attrn)    //attr change                     //~v6G0I~
            {                                                      //~v6G0I~
                UTRACEP("%s:locale attr chng col=%d,ucs=%x,attrn=%x,attro=%x\n",UTT,PTRDIFF(pdbcs,Ppdbcs)+left,ucs2,attrn,attro);//~v6G0R~
                ucsctr=PTRDIFF(pucs,pucsdbcs)/(int)sizeof(WUCS);   //~v6G0I~
                len=PTRDIFF(pco,wkmbs);                            //~v6G0I~
                tgtpos.X=tgtrect.Left;                             //~v6G0I~
                uviom_clearlineW(UVIOMCLO_ATTRSTR,0/*data*/,pattrdbcs,len,tgtpos);//~v6G0I~
                rc+=uvioWriteConsoleOutputCharacter(Shconout,wkmbs,len,tgtpos,&wrtlen)==0;//~v6G0I~
                memcpy(wkmbs,pco,mblen);    //cuurent dbcs         //~v6G0I~
                pco=wkmbs;                                         //~v6G0I~
            	pucsdbcs=pucs;                                     //~v6G0I~
            	pdatadbcs=pdata;                                   //~v6G0I~
            	pdbcsdbcs=pdbcs;                                   //~v6G0I~
            	pattrdbcs=pattr;                                   //~v6G0I~
                tgtrect.Left=(SHORT)(left+PTRDIFF(pdbcs,Ppdbcs));  //~v6G0I~
            }                                                      //~v6G0I~
            pco+=mblen;                                            //~v6G0I~
        }                                                          //~v6G0I~
        else      //cpu8 char                                      //~v6G0R~
        {                                                          //~v6G0I~
        	if (!pucscpu8)  //1st cpu8                             //~v6G0I~
            {                                                      //~v6G0I~
            	if (pucsdbcs)	//not top of line                  //~v6G0I~
            	{                                                  //~v6G0I~
                	UTRACEP("%s:cpu8 out locale col=%d,ucs=%x,dbcs=%x\n",UTT,PTRDIFF(pdbcs,Ppdbcs)+left,ucs2,*pdbcs);//~v6G0R~
            		ucsctr=PTRDIFF(pucs,pucsdbcs)/(int)sizeof(WUCS);//~v6G0I~
                    len=PTRDIFF(pco,wkmbs);                        //~v6G0I~
                    tgtpos.X=tgtrect.Left;                         //~v6G0I~
				    uviom_clearlineW(UVIOMCLO_ATTRSTR,0/*data*/,pattrdbcs,len,tgtpos);//~v6G0I~
					rc+=uvioWriteConsoleOutputCharacter(Shconout,wkmbs,len,tgtpos,&wrtlen)==0;//~v6G0I~
                    pucsdbcs=0;                                    //~v6G0I~
                    pco=wkmbs;                                     //~v6G0I~
                }                                                  //~v6G0I~
            	pucscpu8=pucs;                                     //~v6G0I~
            	pdatacpu8=pdata;                                   //~v6G0I~
            	pdbcscpu8=pdbcs;                                   //~v6G0I~
            	pattrcpu8=pattr;                                   //~v6G0I~
                tgtrect.Left=(SHORT)(left+PTRDIFF(pdbcs,Ppdbcs));  //~v6G0R~
            }                                                      //~v6G0I~
            else    //2nd cpu8                                     //~v6G0I~
            if (attro!=attrn)    //attr change                     //~v6G0I~
            {                                                      //~v6G0I~
                UTRACEP("%s:attr cpu8 attr chng col=%d,ucs=%x,attrn=%x,attro=%x\n",UTT,PTRDIFF(pdbcs,Ppdbcs)+left,ucs2,attrn,attro);//~v6G0R~
                ucsctr=PTRDIFF(pucs,pucscpu8)/(int)sizeof(WUCS);   //~v6G0I~
                len=PTRDIFF(pdbcs,pdbcscpu8);                      //~v6G0I~
                tgtrect.Right=tgtrect.Left+(short)len-1;           //~v6G0I~
                rc+=uviowrtcellW1_cpu8file_LigatureColSplitDBCS(Popt,pucscpu8,ucsctr,pdatacpu8,pdbcscpu8,pattrcpu8,len,&tgtrect,posincombine);//~v6G0I~
                posincombine=0;                                    //~v6G0I~
            	pucscpu8=pucs;                                     //~v6G0I~
            	pdatacpu8=pdata;                                   //~v6G0I~
            	pdbcscpu8=pdbcs;                                   //~v6G0I~
            	pattrcpu8=pattr;                                   //~v6G0I~
                tgtrect.Left=(SHORT)(left+PTRDIFF(pdbcs,Ppdbcs));  //~v6G0I~
            }                                                      //~v6G0I~
        }                                                          //~v6G0I~
        if (ii+1<Pucsctr && IS_UTF16_PAIR(*pucs,*(pucs+1)))        //~v6G0I~
        {                                                          //~v6G0I~
            ii++;                                                  //~v6G0I~
            pucs++;                                                //~v6G0I~
        }                                                          //~v6G0I~
        pdata+=chwidth;                                            //~v6G0I~
        pdbcs+=chwidth;                                            //~v6G0I~
        pattr+=chwidth;                                            //~v6G0I~
    }                                                              //~v6G0I~
    if (pucscpu8)   //remaining cpu8 string                        //~v6G0I~
    {                                                              //~v6G0I~
        ucsctr=PTRDIFF(pucs,pucscpu8)/(int)sizeof(WUCS);           //~v6G0I~
        len=PTRDIFF(pdbcs,pdbcscpu8);                              //~v6G0I~
        tgtrect.Right=tgtrect.Left+(short)len-1;                   //~v6G0I~
        rc+=uviowrtcellW1_cpu8file_LigatureColSplitDBCS(Popt,pucscpu8,ucsctr,pdatacpu8,pdbcscpu8,pattrcpu8,len,&tgtrect,Pposincombine);//~v6G0I~
    }                                                              //~v6G0I~
    if (pucsdbcs)   //not top of line                              //~v6G0I~
    {                                                              //~v6G0I~
        ucsctr=PTRDIFF(pucs,pucsdbcs)/(int)sizeof(WUCS);           //~v6G0I~
        len=PTRDIFF(pco,wkmbs);                                    //~v6G0I~
        tgtpos.X=tgtrect.Left;                                     //~v6G0I~
        uviom_clearlineW(UVIOMCLO_ATTRSTR,0/*data*/,pattrdbcs,len,tgtpos);//~v6G0I~
        rc+=uvioWriteConsoleOutputCharacter(Shconout,wkmbs,len,tgtpos,&wrtlen)==0;//~v6G0I~
    }                                                              //~v6G0I~
    UTRACEP("%s:return rc=%d\n",UTT,rc);                           //~v6G0R~
    return rc;                                                     //~v6G0I~
}//uviowrtcellW1_cpu8file_LigatureColSplit                         //~v6G0R~
//*********************************************************************************//~v6G0I~
//*lig:on                                                          //~v6G0R~
//*********************************************************************************//~v6G0I~
int uviowrtcellW1_cpu8file_Ligature(int Popt,WUCS *Ppucs,int Pucsctr,UCHAR *Ppdata,UCHAR *Ppdbcs,USHORT *Ppattr,int Plen,SMALL_RECT *Ptgtrect)//~v6G0R~
{                                                                  //~v6G0I~
	int posa,posb,posc=-1,posbvhex,poscvhex=-1,col,ii,chwidth,len,ucsctr,rc=0,xx,yy;//~v6G0I~
	int poschkcombine,posincombine=0,combinectr,chwidth2;          //~v6G0R~
    UCHAR *pdbcs;                                                  //~v6G0I~
    SMALL_RECT tgtrect;                                            //~v6G0I~
    WUCS *pucs,ucs2;                                               //~v6G0R~
    COORD tgtpos;                                                  //~v6G0I~
    USHORT attr;                                                   //~v6G0R~
//**************************************************               //~v6G0I~
    xx=Ptgtrect->Left;                                             //~v6G0I~
    yy=Ptgtrect->Top;                                              //~v6G0I~
    UTRACEP("%s:xx=%d,yy=%d,Scsrposx=%d,Svhexcsrposx=%d,Scsrposy=%d,Svhexcsrposy=%d\n",UTT,xx,yy,Scsrposx,Svhexcsrposx,Scsrposy,Svhexcsrposy);//~v6G0M~
    tgtpos.X=(SHORT)xx;                                            //~v6G0R~
    tgtpos.Y=(SHORT)yy;                                            //~v6G0R~
    attr=0x0f;//bg=0,fg=f white on black                           //~v6G0I~
    uviom_clearlineW(UVIOMCLO_ATTRFILL,0/*data*/,&attr,Plen,tgtpos);//~v6G0I~
    if (yy==Scsrposy+Stoplineoffs)    //csr line                   //~v6G0I~
    {                                                              //~v6G0I~
        utfddgetcsrposbca(0,Ppdbcs-xx,Plen+xx,Scsrposx,&posb,&posc,&posa);//~v6G0I~
        UTRACEP("%s:line Y=%d X=%d,top=%d,csrY=%d posb=%d,posc=%d,posa=%d\n",UTT,yy,xx,Stoplineoffs,Scsrposy,posb,posc,posa);//~v6G0I~
    }                                                              //~v6G0I~
    if (yy==Svhexcsrposy+Stoplineoffs)    //csr line               //~v6G0I~
    {                                                              //~v6G0I~
        utfddgetcsrposbca(0,Ppdbcs-xx,Plen+xx,Svhexcsrposx,&posbvhex,&poscvhex,0/*after*/);//~v6G0I~
        UTRACEP("%s:line Y=%d X=%d,top=%d,csrY=%d xposb=%d,xposc=%d\n",UTT,yy,xx,Stoplineoffs,Scsrposy,posbvhex,poscvhex);//~v6G0I~
    }                                                              //~v6G0I~
	if (posc>=0 || poscvhex>=0)                                    //~v6G0I~
    {                                                              //~v6G0I~
        poschkcombine=posc-UVIOM_MAXCOMBINE;                       //~v6G0I~
    	for (ii=0,col=0,pucs=Ppucs,pdbcs=Ppdbcs;ii<Pucsctr;ii++,pucs++)//~v6G0I~
    	{                                                          //~v6G0I~
        	ucs2=*pucs;                                            //~v6G0R~
	        chwidth=UDBCSCHK_DBCS1STUCS2NWO(*pdbcs)+1;             //~v6G0M~
            combinectr=0;                                          //~v6G0M~
            if (col>poschkcombine)                                 //~v6G0R~
            	if (ii+1<Pucsctr)                                  //~v6G0I~
	                combinectr=uvio_getcombinectr(0,ucs2,chwidth,pdbcs,Pucsctr-ii);//~v6G0R~
            UTRACEP("%s:ucs=%x,combinectr=%d,col=%d,posc=%d\n",UTT,ucs2,combinectr,col,posc);//~v6G0I~
            if (combinectr)                                        //~v6G0I~
            {                                                      //~v6G0I~
                if (UDBCSCHK_ISUCSWIDTH0(*pdbcs))   //dbcs combining char//~v6G0I~
                	chwidth2=0;                                    //~v6G0I~
                else                                               //~v6G0I~
                	chwidth2=chwidth;                              //~v6G0I~
            	if (col+combinectr+chwidth2>posc)	//cpos is combine char//~v6G0R~
                {                                                  //~v6G0I~
                	posincombine=posc-col;	//if not 0, splitmode  //~v6G0I~
                	break;                                         //~v6G0I~
                }                                                  //~v6G0I~
            }                                                      //~v6G0I~
            else                                                   //~v6G0I~
            {                                                      //~v6G0I~
    			if (col==posc || col==poscvhex)                    //~v6G0R~
            		break;                                         //~v6G0R~
            }                                                      //~v6G0I~
        	UTRACEP("%s:chwidth=%d ucs=%x dbcs=%x\n",UTT,chwidth,*(Ppucs+ii),*pdbcs);//~v6G0I~
            pdbcs+=chwidth;                                        //~v6G0I~
            col+=chwidth;                                          //~v6G0I~
            if (ii+1<Pucsctr && IS_UTF16_PAIR(*pucs,*(pucs+1)))    //~v6G0I~
            {                                                      //~v6G0I~
                ii++;                                              //~v6G0I~
                pucs++;                                            //~v6G0I~
            }                                                      //~v6G0I~
        }                                                          //~v6G0I~
        if (col)                                                   //~v6G0I~
        {                                                          //~v6G0I~
        	ucsctr=ii;                                             //~v6G0I~
        	len=col;                                               //~v6G0I~
	        tgtrect=*Ptgtrect;                                     //~v6G0I~
            tgtrect.Right=(SHORT)col-1;                            //~v6G0I~
			rc+=uviowrtcellW1_cpu8file_LigatureColSplit(Popt,Ppucs,ucsctr,Ppdata,Ppdbcs,Ppattr,len,&tgtrect,0);//~v6G0R~
        }                                                          //~v6G0I~
        ucsctr=Pucsctr-ii;                                         //~v6G0I~
        len=Plen-col;                                              //~v6G0I~
        tgtrect=*Ptgtrect;                                         //~v6G0I~
        tgtrect.Left=(SHORT)col;                                   //~v6G0I~
		rc+=uviowrtcellW1_cpu8file_LigatureColSplit(Popt,Ppucs+ii,ucsctr,Ppdata+col,Ppdbcs+col,Ppattr+col,len,&tgtrect,posincombine);//~v6G0R~
    }                                                              //~v6G0I~
    else                                                           //~v6G0I~
		rc+=uviowrtcellW1_cpu8file_LigatureColSplit(Popt,Ppucs,Pucsctr,Ppdata,Ppdbcs,Ppattr,Plen,Ptgtrect,0);//~v6G0R~
    return rc;                                                     //~v6G0I~
}//uviowrtcellW1_cpu8file_Ligature                                 //~v6G0R~
#endif//QQQ                                                        //~v6G0I~
#endif                                                             //~v6G0I~
