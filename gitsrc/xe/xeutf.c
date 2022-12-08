//*CID://+vbkbR~:                            update#= 1534;        //~vbkbR~
//*************************************************************    //~v904I~
//* xeutf.c                                                        //~v904I~
//*************************************************************    //~v904I~
//vbkb:180618 uvbka but cs4(ddfmtlen=2) and errrep(lclen=1) cause err; xeutf_cvf2dd-->utfcvf2dd  may change ddlen=2 to lclen=1, it append 1  slag byte to filename//~vbkaI~
//            pancmdlf2dd-->xeutf_cvf2dd(lclen=1 of byte one "?")-->utfcvf2dd:lclen short because ddlen=2//~vbkaI~
//            set dbcs "?" for errrep of ddlen=2 at utfcvf2dd      //~vbkaI~
//vbka:180617 (BUG)ucs4; f2l may change ddlen=2 to lclen=1, it append 1  slag byte to filename//~vbiaI~
//vbi4:180217 set dbcs '?' when f2l err of dbcs(if sbcs '?' err at funcsetlongcmdfromstack xeutf_setbyu8lc->xeutfcvf2dd)//~vbi4I~
//vb7d:170108 (BUG)malloc size is too large;linux crush by _MAX_PATH=4096//~vb7dI~
//vb4c:160730 display altch for also cmdline/errmsg                //~vb2HI~
//vb2H:160307 (W32)UWCHART cut ucs4                                //~vb2HI~
//vb2E:160229 LNX64 compiler warning                               //~vb2EI~
//vb2k:160130 membername on dirlist is FNLC but edit panelfile name is FNU8.//~vb2kI~
//            dirsetlocalename call dirsetddfmtname(DSDFO_L2DD) if not all utf8,//~vb2kI~
//            fileutf8setfilenamecodetype call xeutf_getlocalepathname and GUM_MIXWORDMODE allow UTF8/LC mixed in a pathname.//~vb2kI~
//            Now xeutf_getlocalepathname pre-chk all utf8 and accept the path is utf8.//~vb2kI~
//vb01:150311 debug msg(heap corrupted) fo utf BUFF3               //~vb01I~
//vaz8:150109 C4244 except ULPTR and ULONG                         //~vaz8I~
//vax1:140625 (BUG:Win)find ucs2 failes(searchs ucs4)              //~vax1I~
//vawH:140621 (LNX:BUG of vava)IWF not found masg contains UD_LC   //~vawHI~
//vawE:140613 (BUG)paste UTF8/EBC data to bin file,dd2l was done(lcmd copy or paste line dose not translate)//~vawEI~
//vawB:140612 (BUG)too long renamesv was displayed by LC because getmixedstr returns LC when output area ovf.//~vawBI~
//vawx:140611 (W32UNICODE:BUG)at cmdline,when surrogate pair was deleted ct:2nd green char remains//~vawxI~
//            xeutfdd2lc trans to dbcs errrep like as utfcvf2l     //~vawxI~
//vawv:140610 (W32UNICODE)for ftp,enclose utf8 membname on UDHname //~vawvI~
//vawr:140608 getmixedstr:select UTF8 when env is utf8             //~vawrI~
//vawp:140607 (BUG)ddfmt display err for expand1 wildcard          //~vawpI~
//vawj:140605 (BUG:LNX)paste to rename fld;when l2f to katakana ct is 3 byte CTUTF8,it should be chked at l2fbyct//~vawjI~
//            no problem when ct is from cmd buff(fcmdcvl2fsrchstr,utfgetddstr)//~vawjI~
//vaw5:140529 (BUG) translation failed msg for Find with U option  //~vaw5I~
//vaw1:140523 (Win:UNICODE)dbcsid:overflow for ucs4 on Windows     //~vaw1I~
//vavL:140405 invalid cmd is not by utf8 after C+W copy cmd        //~vavLI~
//vavG:140401 (W32UNICODE) MultiByte2WideChar failes by 0xfdff(cp)-->f8f1+f8f3(ucs2) by MB_ERR_INVALID_CHARS;hdrname truncated by l2u err//~vavGI~
//vavE:140401 (W32UNICODE)getmixedstr should chk UD                //~vavEI~
//vavs:140426 xeutfcvlf2ddAdjust fail, filenamelist copy to cmdline by enter key and enter fail by shoten filenam by this function err
//vavp:140426 (vaub for Win)maintain ddfmt for pan fnmlist and util panel//~vavpI~
//vavj:140424 (BUG)surrogate pair                                  //~vavjI~
//vavi:140424 (BUG)u8lccomp/f2lc may used dbcs errrep              //~vaviI~
//vavc:140421 (Win)unicode support(UD fmt string)                  //~vavcI~
//vava:140410 (Win)unicode support(UD fmt string)                  //~vavaI~
//vav9:140410 (Win)unicode support(UD fmt string,_MAX_PATH changes)//~vav9I~
//vauJ:140317 (BUG)UFHfilename:membername ct of fpath should not apply to pathname//~vauJI~
//vauE:140316 (Win)use ddfmt for dirlist;On cmd-prompt with setcp=65001,f2l dosenot change length but Windows display line shrinked//~vauEI~
//            use ddfmt to set USDfdata                            //~vauEI~
//vauD:140315 (Win BUG)Ctl+W(copyword to cmdline) from dirlist;keep original u8/lc and ignore kbd mode.//~vauDI~
//vaum:140313 (BUG)same as vau2,occurs on retrieve cmd over session//~vaumI~
//vaue:140310 reduce utf8 word tbl for errmsg 16K->256             //~vaueI~
//vaub:140306 maintain ddfmt for pan fnmlist and util panel        //~vauaI~
//vaua:140306 getmixwdword output dddata and dddbcs                //~vauaI~
//vau9:140305 change getmixedtring default to utf8 for linux by env utf8//~vau9I~
//vau7:140303 keep ddfmt on pfh(yet remains dbcs and lcname)       //~vau7I~
//vau6:140303 (BUG)Find cmd utf8 result msg "Not found";err msg utf8 corrupted//~vau6I~
//vau5:140228 (BUG)like as vau0,C+w/A+w and A+Ins(paste to cmdline) colomn err for germany//~vau5I~
//vau2:140227 (BUG)u8 string on cmdline;corrupted display          //~vau2I~
//vamC:131107 (BUG)For localecode on errmsg contains utf8 filename may not translated to ddfmt by the reason of lclen>utf8len//~vamCI~
//vak5:130816 compiler warning;set but not used                    //~vak5I~
//vagE:120918 apply cmdline option /U{N|F}{8|L} to also edit/browse cmd//~vagEI~
//vagw:120915 (BUG)abend when S+F10(display desk) on dirlist       //~vagvI~
//vagv:120915 delete unused function; filesetdbcstblu,xeutfcvl2f   //~vagvI~
//vagu:120915 getmixedword;confirm output buffsize(currently safe by outu8size chk)//~vaguI~
//vagt:120915 (BUG)getmixedword chk dbcs but it was not set        //~vagtI~
//vags:120915 (BUG)getmixedword overflow write oututf8 area when called from dirsetflddata_f2l//~vagvI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vafc:120607 C4701 warning(used uninitialized variable) by VC6    //~vafcI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//vaf8:120607 (WTL)Bug found by vs2010exp(used uninitialized variable)//~vaf8I~
//vaaq:111231 (BUG)errmsg attr:green(utf8) position shifted by l2f //~vaaqI~
//vaam:111229 (BUG)errmsg follows invalid str when misxed string is shrinked by l2dd//~vaamI~
//vaa7:111117 (gcc4.6)Warning:unused-but-set                       //~vaa7I~
//va8f:101003 (BUG)lcmd "=" fail by tab compare(l2dd drop tab attr)//~va8fI~
//va7y:100823 EBC:handle support for cap                           //~va7wI~
//va6w:000627 lcmd comp("=") support among locale,utf8 and ebc file//~va6wI~
//va5J:100522 (BUG)mixedstrupdate shrink case;set invalid utf8 code at eol//~va5JI~
//va5H:100521 (BUG of dd fmt display of mixed str)setdbcstbl miss to set dbcs for f2l err(panfld update err by codetble misunderstanding)//~va5HI~
//va5E:100521 DBCS errrep when b2f err for C&P                     //~va5EI~
//va5w:100517 panutil:keep utf8 codetype over session              //~va5wI~
//va5u:100515 display err by dd fmt                                //~va5uI~
//va5r:100512 (BUG)cmd stack u8 codetype will be lost              //~va5rI~
//va5n:100510 (BUG)cvl2fbyct return rc=4                           //~va5nI~
//va54:100424 (BUG)copy line u8 to lc,invalid process "keep org value when cv err" by char size difference between u8 and lc//~va54I~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va3M:100318 getmixedword:chk dbcstbl when f2l validity chk       //~va3MI~
//va3x:100302 (LNX)UCS4 support                                    //~va3xI~
//            getmixedword accept f2l err as utf8 if valid as utf8 //~va3xI~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//va1L:091120 retry whe cpu8 err if not CPU8 specified because en_US is utf8 but file may not be utf text//~va1LI~
//va1E:091116 optionaly(default) keep original value when UTF8 code err at load//~va1EI~
//va1C:091112 (UTF8)reffer pfh for filename codetype on errmsg     //~va1CI~
//va1y:091108_(UTF8)like as cmd string,stack filename list with lc //~va1yI~
//va1r:091108_(UTF8)cmd string get/set by all of lc, u8 and ct to avoid miss interpretation//~va1rI~
//va1q:091107 compchkm                                             //~va1qI~
//va1p:091104_(UTF8)file/dir default encoding option by UTF cmd    //~va1pI~
//va1n:091103_(UTF8)cmdline parm for filename encoding             //~va1nI~
//va1m:091102_(UTF8)cmdline parm to force file encoding is locale code//~va1mI~
//va1f:091101_(UTF8:BUG) abend by A+Ins(paste) destroy dbcs area by f2l expansion//~va1fI~
//va1d:091101_(UTF8:BUG) edirlist edscription dispay size is short when F2l is done//~va1dI~
//va1c:091030_merge GB18030 support                                //~va1cI~
//va19:091026(BUG)abend at xeutfgetmiedword                        //~va19I~
//va10:091008!(XXE) treate input string as UTF8 or LOCALE for a line//~va0PI~
//                      Mixed string word by word                  //~va10I~
//va0P:091003!(WIN:BUG) getmixedstr returns "?" when f2l translation err//~va0PI~
//va0N:091002!(WIN:BUG) C(J)K console kbd input is utf8,treate as locale code//~va0NI~
//va0M:091002!(BUG)xeutf_dbcssplit abend when utf8str is locale on cmdline//~va0MI~
//va0L:091001!(BUG)charfldedit lastbyte to be cleared when utf8 is replaced by ascii//~va0LI~
//va0H:090726!getmixedstring chk utf8 after lc                     //~va0HI~
//va0w:090919!assume locale if lognger than utf8 translation       //~va0wI~
//va00:090510 merge utf8 version                                   //~va00I~
//            del not used xeutf_lcudl/xeutf_setdbcstblmix(call xeutf_getutf8str)//~va00I~
//            conv utf8 to locale                                  //~va00I~
//            always XEUTF8MODE if LNX                             //~va00I~
//            locale/utf8 mixed errmsg                             //~va00I~
//v7aw:090411-(UTF8:BUG)may abend when csr pos is at EOL           //~v7awI~
//v92r:080802 (UTF:BUG)xeutf_getlocalestr miss to set length output when all ascii//~v92rI~
//v92n:080802 (UTF)add  [cplc|cpu8] option for save cmd            //~v92nI~
//v91Z:080105 (UTF:LNX:BUG)hdr line attr:green is not drawn        //~v91ZI~
//v91Y:080104 (UTF:BUG)abend;tflow with BNDS for non-utff8 file    //~v91YI~
//v91V:071229 (UTF:BUG)bug of v91w:for LNX,sjis2euc is required for errmsg//~v91VI~
//v77g:071227 (UTF)re-evaluate utf8 char after join-line           //~v77gI~
//v91M:071224 (UTF:BUG)chng cmd on bin file(spanned case)          //~v91MI~
//v91z:071219 (UTF8:BUG)tab is not displayed for non-utf file      //~v91zI~
//v91w:071216 (UTF8)mixed code for errmsg                          //~v91wI~
//v91q:071214 (UTF8:BUG)calc abend for ascii chof                  //~v91qI~
//v91m:071213 (UTF8)mix code on util panel                         //~v91mI~
//v91e:071206 (UTF8)setdbcstbl dose not reset dbcserr(need when utf8 byte input one by one from hexkbd)//~v91cI~
//v91c:071205 (UTF8)display mixed code on cmdline                  //~v91cI~
//v918:071130 (UTF8:BUG)dirlist rename fld by utf8                 //~v918I~
//v911:071128 (UTF8:BUG)mode cplc display invalid char when cv l2f failed//~v911I~
//v910:071128 (UTF8)kbd accept both utf and locale(sjis etc)       //~v90yI~
//v90y:071126 (UTF8:BUG) filetabexp parm:len is lenc               //~v90yI~
//v90x:071126 (UTF8) U8/LC cmd(convert cmd string to UTF8/LOCALE)  //~v90xI~
//v90t:071115 (UTF8) errmsg operand may utf8                       //~v90tI~
//v90r:071113 (UTF8) display filename by utf8                      //~v90rI~
//v90n:071026 (UTF8) utf is option for each file                   //~v90nI~
//v90g:071019 (UTF:LNX)not printable(all byte are displayed as unprintable) and width<0(1 unpritable) is not same//~v90gI~
//v90d:071016 (UTF8)display dirlist by utf8 if valid locale encoded filename//~v90dI~
//v905:070918 (UTF8:LNX)                                           //~v905I~
//v904:070804 (UTF8)define as not PUTCHARS but UTCHARS             //~v904I~
//v901:070710 (UTF8)utf8 support                                   //~v904I~
//*************************************************************    //~v904I~
#include <time.h>                                                  //~v904I~
#include <stdio.h>                                                 //~v904I~
#include <stddef.h>                                                //~v904I~
#include <stdlib.h>                                                //~v904I~
#include <ctype.h>                                                 //~v904I~
#include <string.h>                                                //~v904I~
//*************************************************************    //~v904I~
//*******************************************************          //~v904I~
#include <ulib.h>                                                  //~v904I~
#include <uerr.h>                                                  //~v904I~
#include <uque.h>                                                  //~v904I~
#include <udbcschk.h>                                              //~v904I~
#include <ustring.h>                                               //~v904I~
#include <ufile.h>                                                 //~v904I~
#include <utf.h>                                                   //~v904I~
#include <utf2.h>                                                  //~v904I~
#include <utf22.h>                                                 //~va20I~
#include <ucvucs.h>                                                //~v904I~
#include <ualloc.h>                                                //~v904I~
#include <utrace.h>                                                //~v904I~
#include <uftp.h>                                                  //~v90xI~
#include <ufilew.h>                                                //~vavaI~
                                                                   //~v904I~
#include "xe.h"                                                    //~v904I~
#include "xescr.h"                                                 //~v904I~
#include "xepan.h"                                                 //~v904I~
#include "xefile.h"                                                //~v904I~
#include "xefile42.h"                                              //~v904I~
#include "xefile6.h"                                               //~v904I~
#include "xeerr.h"                                                 //~v904I~
#include "xesub.h"                                                 //~v904I~
#ifdef UTF8SUPPH                                                   //~va1qI~
#include "xesub2.h"                                                //~va1cR~
#endif                                                             //~va1qI~
#define GLOBAL_XEUTF                                               //~v90tI~
#include "xeutf.h"                                                 //~v904I~
#include "xechar.h"                                                //~v904I~
#include "xeundo.h"                                                //~v904I~
#include "xeopt.h"                                                 //~v90yI~
#ifdef UTF8SUPPH                                                   //~va00I~
	#include "xechar12.h"                                          //~va00I~
#endif                                                             //~va00I~
#ifdef UTF8UCS2                                                    //~va20I~
	#include "xeutf2.h"                                            //~va20I~
#endif                                                             //~va20I~
#include "xeebc.h"                                                 //~va50I~
                                                                   //~v904I~
//*******************************************************          //~va1CI~
#ifdef UTF8SUPPH                                                   //~va1CM~
#ifdef UTF8UCS2                                                    //~va20I~
    #define XEUTF_MAXSVTEXT   8 //[0,1] for 1st opd, [2,3]  for filename,[4,5] for 2nd opd(AND search etc)//~va20I~
#else                                                              //~va20I~
    #define XEUTF_MAXSVTEXT   4 //[0,1] for 1st opd, [2,3]  for filename//~va1CR~
#endif                                                             //~va20I~
#define MAX_ERRSAVETEXTSZ 256                                      //~vaueI~
//	static char Stextu8[XEUTF_MAXSVTEXT][_MAX_PATH*UTF8_F2LMAXRATE];//~vau7R~
//	static char Stextu8[XEUTF_MAXSVTEXT][_MAX_PATH*UTF8_MAXCHARSZ];//~vaueR~
  	static char Stextu8[XEUTF_MAXSVTEXT][MAX_ERRSAVETEXTSZ*UTF8_MAXCHARSZ];//~vaueI~
//#ifdef LNX                                                         //~vau7I~//~vauER~
//  static char Stextdd[XEUTF_MAXSVTEXT][_MAX_PATH*2];             //~vaueR~
//  static char Stextdddbcs[XEUTF_MAXSVTEXT][_MAX_PATH*2];         //~vaueR~
//  static char Stextct[XEUTF_MAXSVTEXT][_MAX_PATH*2];             //~vaueR~
    static char Stextdd[XEUTF_MAXSVTEXT][MAX_ERRSAVETEXTSZ*2];     //~vaueI~
    static char Stextdddbcs[XEUTF_MAXSVTEXT][MAX_ERRSAVETEXTSZ*2]; //~vaueI~
    static char Stextct[XEUTF_MAXSVTEXT][MAX_ERRSAVETEXTSZ*2];     //~vaueI~
  	static char Stextu8[XEUTF_MAXSVTEXT][MAX_ERRSAVETEXTSZ*UTF8_MAXCHARSZ];//~vauEI~
#ifdef LNX                                                         //~vauEI~
#else                                                              //~vau7I~
//#ifdef CCC                                                         //~vauEI~//~vav9R~
//    static char Stextlc[XEUTF_MAXSVTEXT][_MAX_PATH*UTF8_F2LMAXRATE];//~va1CR~//~vav9R~
//    static char Stextct[XEUTF_MAXSVTEXT][_MAX_PATH*UTF8_F2LMAXRATE];//~va1CR~//~vav9R~
//#endif                                                             //~vauEI~//~vav9R~
#endif                                                             //~vau7I~
	static int  Stextu8len[XEUTF_MAXSVTEXT];                       //~va1CM~
//#ifdef LNX                                                         //~vau7I~//~vauER~
	static int  Stextddlen[XEUTF_MAXSVTEXT];                       //~vau7M~
#ifdef LNX                                                         //~vauEI~
#else                                                              //~vau7I~
#ifdef CCC                                                         //~vauEI~
	static int  Stextlclen[XEUTF_MAXSVTEXT];                       //~va1CM~
#endif                                                             //~vauEI~
#endif                                                             //~vau7I~
#endif                                                             //~va1CI~
//*******************************************************          //~va10I~
int xeutf_getmixedword(int Popt,int *Ppcodetype,char *Pdata,int Pdatalen,char *Poutbuff,int Poutbuffsz,char *Poututf8,int Poututf8sz,//~va10I~
//  					char *Pcodetypetbl,int *Ppchklen,int *Ppoutlen,int *Ppoututf8len);//~vauaR~
    					char *Pcodetypetbl,int *Ppchklen,int *Ppoutlen,int *Ppoututf8len,char *Pdddata,char *Pdddbcs,char *Pddcode,int Pddbuffsz,int *Ppddlen);//~vauaR~
//#ifdef LNX                                                         //~vaumI~//~vavaR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaI~
int xeutfcvf2lDDW(int Popt,char *Pdata,int Pdatalen,char *Poutbuff,int Poutbuffsz,int *Ppoutlen);//~vauaR~
#endif                                                             //~vaumI~
#ifdef W32UNICODE                                                  //~vavsI~
int xeutfcvf2lDDWct(int Popt,char *Pdata,int Pdatalen,char *Poutbuff,int Poutbuffsz,int *Ppoutlen,char *Poutct);//~vavsI~
#endif                                                             //~vavsI~
int xeutf_seterrmsgctopd2(int Popt,char *Ppu8,int Plenu8,char *Pdddata,char *Pdddbcs,char *Ppct,int Pbuffsz,int *Pplenlc);//~vawrI~
int xeutf_dbcssubcharcmp(int Popt,char *Plc,int Plen);             //~vbi4I~
//*******************************************************          //~va10I~
                                                                   //~va10I~
#ifdef UTF8SUPPH                                                   //~va00R~
//*******************************************************          //~va00I~
//*utf gbl init                                                    //~va00I~
//*******************************************************          //~va00I~
void xeutf_init(int Popt)                                          //~va00I~
{                                                                  //~va00I~
//*****************                                                //~va00I~
	if (Popt & XEUTFIO_RESET)	//termination                      //~va00I~
    {                                                              //~va00I~
        xeutf_buffget(XEUTF_BUFFFREE,0);                           //~va00I~
    	return;                                                    //~va00I~
    }                                                              //~va00I~
    Gutfmode2|=GUM2_UTF8VERSIONMODE;	//utf8 filename/file data  //~va00I~
    if (Popt & XEUTFIO_FILE)                                       //~va00I~
    	Gutfmode2|=GUM2_ALLFILEUTF8CLP;	//cmdlineparm              //~va00I~
    if (Popt & XEUTFIO_FILELC)                                     //~va1mI~
    	Gutfmode2|=GUM2_ALLFILELCCLP;	//default is locale code by cmdlineparm//~va1mI~
    if (Popt & XEUTFIO_DIRU8)       //filename is                  //~va1nI~
    	Gutfmode2|=GUM2_DIRU8CLP;	//utf8 encoding as default     //~va1nI~
    else                                                           //~va1nI~
    if (Popt & XEUTFIO_DIRLC)                                      //~va1nI~
    	Gutfmode2|=GUM2_DIRLCCLP;                                  //~va1nI~
//  utfcvlocaleinit(UTFCLIO_DEFAULTCHK,Gdefaultlocalecode);	//get default localecode//~va00R~
	Gutfmode=UTF8MODE();               //env and force flag        //~va00I~
#ifdef W32                                                         //~va0NM~
    if (Gudbcschk_flag & UDBCSCHK_WINUTF8)//  0x020000  //windows kbd input by wide api//~va0NM~
    	Gutfmode2|=GUM2_WINKBDUTF8;			//for charfldeditu8    //~va0NM~
#endif                                                             //~va0NM~
    Gutfmode2|=GUM2_MIXEDWORDMODE;			//allow UTF8/LOCALE word by word//~va10I~
    Gutfmode2|=GUM2_KEEPIFCVERR;  			//allow UTF8/LOCALE word by word//~va1EI~
//  Gutfmode2|=GUM2_NORETRYCPU8ERR;   //no retry when cpu8 err at fileload//~va1LR~
    return;                                                        //~va00I~
}//xeutf_init                                                      //~va00I~
#endif                                                             //~va00I~
#ifdef UTF8SUPPH                                                   //~va00I~
//*******************************************************          //~v90nI~
// allocate buff                                                   //~v90nI~
//* return UALLOC_FAILED                                           //~v90nI~
//*******************************************************          //~v90nI~
char *xeutf_buffget(int Pbuffid,int Plen)                          //~v90nI~
{                                                                  //~v90nI~
static int Sxeutfbufflen[XEUTF_MAXBUFFID];                         //~v90nI~
static char *Sxeutfbuff[XEUTF_MAXBUFFID];                          //~v90nI~
	int ii;                                                        //~v90nI~
    char *pc;                                                      //~v90nI~
//**********************                                           //~v90nI~
	if (Pbuffid==XEUTF_BUFFFREE)                                   //~v90nI~
    {                                                              //~v90nI~
    	for (ii=0;ii<XEUTF_MAXBUFFID;ii++)                         //~v90nI~
        {                                                          //~v90nI~
            UFREECLEARIFNZ(Sxeutfbuff[ii])                         //~v90nR~
        }                                                          //~v90nI~
        return 0;                                                  //~v90nI~
    }                                                              //~v90nI~
    if (Pbuffid>=XEUTF_MAXBUFFID)                                  //~v90nI~
    	return 0;                                                  //~v90nI~
    if (Plen<=Sxeutfbufflen[Pbuffid])                              //~v90nI~
    	return Sxeutfbuff[Pbuffid];                                //~v90nR~
    pc=umalloc((UINT)Plen);                                        //~v90nI~
    if (!pc)                                                       //~v90nI~
    	return 0;                                                  //~v90nI~
    Sxeutfbufflen[Pbuffid]=Plen;                                   //~v90nI~
    UFREEIFNZ(Sxeutfbuff[Pbuffid]);	//free old                     //~v90nR~
    Sxeutfbuff[Pbuffid]=pc;                                        //~v90nI~
    return pc;                                                     //~v90nI~
}//xeutf_buffget                                                   //~v90nI~
#endif                                                             //~va00I~
//**************************************************************** //~vawpR~
// xeutf_getlocalepathname                                         //~vawpR~
//	conv utf8->locale for each path with different encoding        //~vawpR~
//ret:4:required conversion for displayall ascii,0x01:contains originally utf path,0x02:locale converted to utf8//~vawpR~
// when utf2locale 0x01:utf8 conved to lc,0x02:no conversion       //~vawpR~
//**************************************************************** //~vawpR~
int xeutfgetmixstrctopt(int Popt,PUFILEH Ppfh)                     //~vawpR~
{                                                                  //~vawpR~
    int membercodetype,bettercodetype,opt,rc;                      //~vawpR~
//*****************                                                //~vawpR~
	opt=0;                                                         //~vawpR~
//    if (UCBITCHK(Ppfh->UFHflag13,UFHF13SELECTFNU8)) //utf8 filename on dirlist//~vawpR~
//        opt|=XEUTFGLPNO_FNU8MEMB;   //select utf8 for member encoding if both utf8 and locale is valid//~vawpR~
//    else                                                         //~vawpR~
//    if (UCBITCHK(Ppfh->UFHflag13,UFHF13SELECTFNLC))              //~vawpR~
//        opt|=XEUTFGLPNO_FNLCMEMB;   //select utf8 for membername encoding if both utf8 and locale is valid//~vawpR~
    if (UCBITCHK(Ppfh->UFHflag12,UFHF12FNU8))                      //~vawpR~
       	opt|=XEUTFGLPNO_FNU8;	//select utf8 for filename encoding if both utf8 and locale is valid//~vawpR~
    else                                                           //~vawpR~
    if (UCBITCHK(Ppfh->UFHflag12,UFHF12FNLC))                      //~vawpR~
       	opt|=XEUTFGLPNO_FNLC;	//select localecode for filename encoding if both utf8 and locale is valid//~vawpR~
#ifdef W32UNICODE                                                  //~vawpM~
    if (FILEISREMOTE(Ppfh))                                        //~vawpR~
    	opt|=XEUTFGLPNO_REMOTE;                                    //~vawpR~
    if (opt & XEUTFGLPNO_REMOTE)                                   //~vawpR~
    {                                                              //~vawpR~
        if (opt & XEUTFGLPNO_FNU8)             //cmd optionFNU8    //~vawpR~
            bettercodetype=XEUTFCT_UTF8;                           //~vawpR~
        else                                                       //~vawpR~
        if (opt & XEUTFGLPNO_FNLC)             //FNLC              //~vawpR~
            bettercodetype=XEUTFCT_LC;                             //~vawpR~
        else                                                       //~vawpR~
        if (Gutfmode2 & GUM2_DIRU8CLP)          //cmdline parm /UN8//~vawpR~
            bettercodetype=XEUTFCT_UTF8;                           //~vawpR~
        else                                                       //~vawpR~
        if (Gutfmode2 & GUM2_DIRLCCLP)          // /UNL            //~vawpR~
            bettercodetype=XEUTFCT_LC  ;                           //~vawpR~
        else                                                       //~vawpR~
        if (Goptopt2 & GOPT2_ALLFNUTF8)         //UTF cmd, UTF FN CPU8//~vawpR~
            bettercodetype=XEUTFCT_UTF8;                           //~vawpR~
        else                                                       //~vawpR~
        if (Goptopt2 & GOPT2_ALLFNLOCALE)       // UTF FN CPLC     //~vawpR~
            bettercodetype=XEUTFCT_LC;                             //~vawpR~
        else                                                       //~vawpR~
        	bettercodetype=XEUTFCT_UTF8;                           //~vawpR~
    }                                                              //~vawpR~
    else    //local                                                //~vawpR~
    {                                                              //~vawpR~
    	bettercodetype=XEUTFCT_LC; //windows native is LC2W        //~vawpR~
//  	opt2|=XEUTFGLSMO_LCPRIMARY; //apply LC for W32 local       //~vawpR~
    }                                                              //~vawpR~
#else                                                              //~vawpR~
  	if (opt & XEUTFGLPNO_FNU8)             //FNU8 option specified //~vawpR~
    	bettercodetype=XEUTFCT_UTF8;   //primarily apply UTF8 if both is valid//~vawpR~
  	else                                                           //~vawpR~
  	if (opt & XEUTFGLPNO_FNLC)             //FNU8 option specified //~vawpR~
    	bettercodetype=XEUTFCT_LC;     //primarily apply locale code if both is valid//~vawpR~
  	else                                                           //~vawpR~
  	if (Gutfmode2 & GUM2_DIRU8CLP)                                 //~vawpR~
    	bettercodetype=XEUTFCT_UTF8;   //primarily apply UTF8 if both is valid//~vawpR~
  	else                                                           //~vawpR~
  	if (Gutfmode2 & GUM2_DIRLCCLP)                                 //~vawpR~
    	bettercodetype=XEUTFCT_LC  ;   //primarily apply locale code//~vawpR~
  	else                                                           //~vawpR~
  	if (Goptopt2 & GOPT2_ALLFNUTF8)                                //~vawpR~
    	bettercodetype=XEUTFCT_UTF8;   //primarily apply UTF8 if both is valid//~vawpR~
  	else                                                           //~vawpR~
  	if (Goptopt2 & GOPT2_ALLFNLOCALE)                              //~vawpR~
    	bettercodetype=XEUTFCT_LC;   //primarily apply UTF8 if both is valid//~vawpR~
  	else                                                           //~vawpR~
  	if (XEUTF8MODE_ENV_FORCE()) //env=utf8 required for =6 file    //~vawpR~
    	bettercodetype=XEUTFCT_UTF8;   //primarily apply UTF8 if both is valid//~vawpR~
  	else                                                           //~vawpR~
    	bettercodetype=XEUTFCT_LC;   //primarily apply UTF8 if both is valid//~vawpR~
#endif  //LNX                                                      //~vawpR~
  	if (opt & XEUTFGLPNO_FNU8MEMB)             //FNU8 option specified//~vawpR~
    	membercodetype=XEUTFCT_UTF8;   //apply UTF8 if both is valid for membername//~vawpR~
  	else                                                           //~vawpR~
  	if (opt & XEUTFGLPNO_FNLCMEMB)             //FNU8 option specified//~vawpR~
    	membercodetype=XEUTFCT_LC;     //apply locale code if both is valid for membername//~vawpR~
  	else                                                           //~vawpR~
    	membercodetype=0;     //primarily apply locale code if both is valid//~vawpR~
    if (membercodetype)                                            //~vawpR~
    	bettercodetype=membercodetype;   //primarily apply UTF8 if both is valid//~vawpR~
    rc=Popt;                                                       //~vawpI~
    if (bettercodetype==XEUTFCT_UTF8)                              //~vawpI~
    	rc|=XEUTFGLSMO_UTF8;//apply utf8 if both u8/lc ok          //~vawpR~
    else                                                           //~vawpI~
    if (bettercodetype==XEUTFCT_LC)                                //~vawpI~
    	rc|=XEUTFGLSMO_LC;	//apply utf8 if both u8/lc ok          //~vawpI~
    UTRACEP("%s:rc=%x,fnm=%s\n",UTT,rc,Ppfh->UFHfilename);         //~vawpR~
    return rc;                                                     //~vawpI~
}//xeutfgetmixstrctopt                                             //~vawpR~
#ifdef UTF8SUPPH                                                   //~va00I~
//**************************************************************** //~v90tI~
// xeutf_getlocalepathname                                           //~v90tI~//~va10R~
//	conv utf8->locale for each path with different encoding        //~va00R~
//ret:4:required conversion for displayall ascii,0x01:contains originally utf path,0x02:locale converted to utf8//~v90tI~
// when utf2locale 0x01:utf8 conved to lc,0x02:no conversion       //~v90xI~
//**************************************************************** //~v90tI~
//int xeutf_getlocalepathname(int Popt,char *Pfpath,int Ppathlen,char *Poutbuff,char *Pcodetype,int Poutbuffsz,int *Ppoutlen)//~vauaR~
int xeutf_getlocalepathname(int Popt,char *Pfpath,int Ppathlen,char *Poutbuff,char *Pcodetype,int Poutbuffsz,int *Ppoutlen,//~vauaI~
				char *Pdddata,char *Pdddbcs,char* Pddcode,int Pddbuffsz,int *Ppddlen)//~vauaI~
{                                                                  //~v90tI~
//  char *pco,*pc,*pc2,*pcn,utf8wk[_MAX_PATH*UTF8_MAXCHARSZMAX+1]; //~va1cR~//~vav9R~
    char *pco,*pc,*pc2,*pcn,utf8wk[_MAX_PATHU8+1];                 //~vav9I~
    int rc=0,len,reslen,resleno,wrtlen,chklen;                     //~va00I~
    int codetype=XEUTFCT_ASCII,opt,utf8len,outlen,chrcnt;                        //~va00R~//~vafcR~
    int dirsepc,tailsz;                                            //~va00R~
    int oldcodetype,bettercodetype,opt2,rc2;                       //~va10R~
    char *pdddata,*pdddbcs,*pddcode;                               //~vauaI~
    int totddlen=0,ddlen,reslendd;                                 //~vauaR~
    char *pmember;                                                 //~vauJI~
    int membercodetype,pathlen;                                    //~vauJI~
#ifdef LNX                                                         //~vb2kI~
    int swnewpath=1;                                               //~vb2kI~
    char *ppathend=0;                                              //~vb2kI~
	int swendsepc;                                                 //~vb2HI~
#endif                                                             //~vb2kI~
//*****************                                                //~v90tI~
    UTRACEP("%s:opt=%x\n",UTT,Popt);                               //~vb2kI~
  if (Popt & XEUTFGLPNO_MEMBNAME)                                  //~va10I~
    dirsepc=0xff;                                                  //~va10I~
  else                                                             //~va10I~
  {                                                                //~va10I~
	if (uftpisremote(Pfpath,0))                                    //~va00R~
    	dirsepc=FTP_DIR_SEPC;                                      //~va00I~
    else                                                           //~va00I~
    	dirsepc=DIR_SEPC;                                          //~va00R~
  }                                                                //~va10I~
  	if (!(len=Ppathlen))                                           //~va00R~
//		len=strlen(Pfpath);                                        //~vb01R~
		len=(int)strlen(Pfpath);                                   //~vb01I~
	if (Popt & XEUTFGLPNO_TAIL)	//trailing ascii data length is on parm//~va00I~
    	tailsz=((Popt & XEUTFGLPNO_TAILLENMASK)>>8);               //~va00I~
    else                                                           //~va00I~
    	tailsz=0;                                                  //~va00I~
    len-=tailsz;                                                   //~va00I~
    resleno=Poutbuffsz;                                            //~va00I~
    if (Popt & XEUTFGLPNO_STRZ)                                    //~va00R~
    	resleno--;                                                 //~va00I~
    opt2=XEUTFGLSMO_KEEPLC|XEUTFGLSMO_FILEPATH; //output source locale code to Poututf8//~va10R~
#ifdef LNX                                                         //~vb2kI~
  	if (Popt & XEUTFGLPNO_ERRREPLC)                                //~vb2kI~
    	opt2|=XEUTFGLSMO_ERRREPLC;  //KEEPLC is ignored because chklen!=0 is returned by l2f//~vb2kR~
#endif                                                             //~vb2kI~
//#ifdef LNX                                                         //~vauaI~//~vavaR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaI~
    if (Popt & XEUTFGLPNO_LCWIDTHBYDDWIDTH)	//rep by "?" when lcwidth!=ddwidth for ddfmt field//~vauaI~
    	opt2|=XEUTFGLSMO_LCWIDTHBYDDWIDTH;                         //~vauaI~
#endif                                                             //~vauaI~
#ifdef W32UNICODE                                                  //~vavGI~
    if (Popt & XEUTFGLPNO_ALLOWSUBCH)                              //~vavGR~
    	opt2|=XEUTFGLSMO_ALLOWSUBCH;                               //~vavGR~
#endif                                                             //~vavGI~
	opt2|=(dirsepc<<16); //seperator                               //~va10R~
//    if (XEUTF8MODE_ENV_FORCE()) //env is utf8                    //~va10R~
//        bettercodetype=XEUTFCT_UTF8;    //if encoding chk ok for both UTF8 and LOCALE//~va10R~
//    else                                                         //~va10R~
//        bettercodetype=XEUTFCT_LC;      //if encoding chk ok for both UTF8 and LOCALE//~va10R~
//*FIXME test for remote                                           //~vaw1R~
#ifdef W32UNICODE                                                  //~vavcR~
    if (Popt & XEUTFGLPNO_REMOTE)                                  //~vavcR~
    {                                                              //~vavcR~
        if (Popt & XEUTFGLPNO_FNU8)             //cmd optionFNU8   //~vavcR~
            bettercodetype=XEUTFCT_UTF8;                           //~vavcR~
        else                                                       //~vavcR~
        if (Popt & XEUTFGLPNO_FNLC)             //FNLC             //~vavcR~
            bettercodetype=XEUTFCT_LC;                             //~vavcR~
        else                                                       //~vavcR~
        if (Gutfmode2 & GUM2_DIRU8CLP)          //cmdline parm /UN8//~vavcR~
            bettercodetype=XEUTFCT_UTF8;                           //~vavcR~
        else                                                       //~vavcR~
        if (Gutfmode2 & GUM2_DIRLCCLP)          // /UNL            //~vavcR~
            bettercodetype=XEUTFCT_LC  ;                           //~vavcR~
        else                                                       //~vavcR~
        if (Goptopt2 & GOPT2_ALLFNUTF8)         //UTF cmd, UTF FN CPU8//~vavcR~
            bettercodetype=XEUTFCT_UTF8;                           //~vavcR~
        else                                                       //~vavcR~
        if (Goptopt2 & GOPT2_ALLFNLOCALE)       // UTF FN CPLC     //~vavcR~
            bettercodetype=XEUTFCT_LC;                             //~vavcR~
        else                                                       //~vavcR~
//        if (XEUTF8MODE_ENV_FORCE())             //env=utf8       //~vavcR~
//            bettercodetype=XEUTFCT_UTF8;                         //~vavcR~
//        else                                                     //~vavcR~
//            bettercodetype=XEUTFCT_LC;   //primarily apply UTF8 if both is valid//~vavcR~
        	bettercodetype=XEUTFCT_UTF8;                           //~vavcI~
    }                                                              //~vavcI~
    else    //local                                                //~vavcI~
    {                                                              //~vavcI~
    	bettercodetype=XEUTFCT_LC; //windows native is LC2W        //~vavcR~
		opt2|=XEUTFGLSMO_LCPRIMARY; //apply LC for W32 local       //~vavcI~
    }                                                              //~vavcR~
#else                                                              //~vavcR~
  if (Popt & XEUTFGLPNO_FNU8)             //FNU8 option specified  //~vagEI~
    bettercodetype=XEUTFCT_UTF8;   //primarily apply UTF8 if both is valid//~vagEI~
  else                                                             //~vagEI~
  if (Popt & XEUTFGLPNO_FNLC)             //FNU8 option specified  //~vagEI~
    bettercodetype=XEUTFCT_LC;     //primarily apply locale code if both is valid//~vagEI~
  else                                                             //~vagEI~
  if (Gutfmode2 & GUM2_DIRU8CLP)                                   //~va1nI~
    bettercodetype=XEUTFCT_UTF8;   //primarily apply UTF8 if both is valid//~va1nI~
  else                                                             //~va1nI~
  if (Gutfmode2 & GUM2_DIRLCCLP)                                   //~va1nI~
    bettercodetype=XEUTFCT_LC  ;   //primarily apply locale code   //~va1nI~
  else                                                             //~va1nI~
  if (Goptopt2 & GOPT2_ALLFNUTF8)                                  //~va1pR~
    bettercodetype=XEUTFCT_UTF8;   //primarily apply UTF8 if both is valid//~va1pI~
  else                                                             //~va1pI~
  if (Goptopt2 & GOPT2_ALLFNLOCALE)                                //~va1pR~
    bettercodetype=XEUTFCT_LC;   //primarily apply UTF8 if both is valid//~va1pI~
  else                                                             //~va1pI~
  if (XEUTF8MODE_ENV_FORCE()) //env=utf8 required for =6 file      //~va1pI~
    bettercodetype=XEUTFCT_UTF8;   //primarily apply UTF8 if both is valid//~va1pI~
  else                                                             //~va1pI~
    bettercodetype=XEUTFCT_LC;   //primarily apply UTF8 if both is valid//~va1pI~
//  bettercodetype=0;   //depend on A+u status                     //~va10I~//~va1pR~
#endif  //LNX                                                      //~vavcR~
  	if (Popt & XEUTFGLPNO_FNU8MEMB)             //FNU8 option specified//~vauJR~
    	membercodetype=XEUTFCT_UTF8;   //apply UTF8 if both is valid for membername//~vauJI~
  	else                                                           //~vauJI~
  	if (Popt & XEUTFGLPNO_FNLCMEMB)             //FNU8 option specified//~vauJR~
    	membercodetype=XEUTFCT_LC;     //apply locale code if both is valid for membername//~vauJI~
  	else                                                           //~vauJI~
    	membercodetype=0;     //primarily apply locale code if both is valid//~vauJI~
    pmember=NULL;                                                  //~vauJI~
    if (membercodetype)                                            //~vauJI~
    {                                                              //~vauJI~
    	pathlen=PATHLEN(Pfpath);	                               //~vauJI~
        if (pathlen<=0)                                            //~vauJI~
        {                                                          //~vauJI~
        	bettercodetype=membercodetype;                         //~vauJI~
        	membercodetype=0;                                      //~vauJR~
        }                                                          //~vauJI~
        else                                                       //~vauJI~
        	pmember=Pfpath+pathlen;                                //~vauJI~
        UTRACEP("xeutf_getlocalepathname member ct=%d,name=%s\n",membercodetype,pmember);//~vauJR~
    }                                                              //~vauJI~
	pdddata=Pdddata,pdddbcs=Pdddbcs,pddcode=Pddcode;               //~vauaI~
    reslendd=Pddbuffsz;                                            //~vauaI~
    for (pc=Pfpath,pco=Poutbuff,pcn=Pcodetype,reslen=len;          //~va00I~
			reslen>0 && resleno>0;                                 //~va00I~
            reslen-=chklen,resleno-=wrtlen,pc+=chklen,pco+=wrtlen) //~va00I~
    {                                                              //~va00I~
      if (Gutfmode2 & GUM2_MIXEDWORDMODE)                          //~va10I~
      {                                                            //~va10I~
        oldcodetype=bettercodetype;                                //~va10I~
        if (pmember && pc>=pmember)                                //~vauJI~
        	oldcodetype=membercodetype;                            //~vauJI~
#ifdef LNX                                                         //~vb2kI~
//*chk the path is all utf8                                        //~vb2kI~
        swendsepc=0;	//last is dirsepc                          //~vb2HI~
        if (swnewpath)                                             //~vb2kI~
        {                                                          //~vb2kI~
            swnewpath=0;                                           //~vb2kI~
            pc2=umemchr2(pc,(char)dirsepc,(size_t)reslen);         //~vb2kR~
            if (!pc2)                                              //~vb2kR~
                len=reslen;                                        //~vb2kR~
            else                                                   //~vb2kR~
            {                                                      //~vb2HI~
                len=(int)PTRDIFF(pc2,pc)+1;                        //~vb2kR~
                swendsepc=1;	//last is dirsepc                  //~vb2HI~
            }                                                      //~vb2HI~
            ppathend=pc+len;                                       //~vb2kR~
            opt=0;                                                 //~vb2kR~
            utf8len=utfgetutf8strlen(opt,pc,len,&chrcnt);          //~vb2kR~
            if (utf8len!=len)   //not all valid utf8               //~vb2kR~
            {                                                      //~vb2kR~
                opt2|=XEUTFGLSMO_NOTUTF8PATH;   //the path name is not valid utf8 string(not also all ascii)//~vb2kR~
                oldcodetype=XEUTFCT_LC  ;   //primarily apply locale code//~vb2kR~
            }                                                      //~vb2kR~
        }                                                          //~vb2kI~
        else                                                       //~vb2kI~
        {                                                          //~vb2kI~
        	if (opt2 & XEUTFGLSMO_NOTUTF8PATH)   //the path name is not valid utf8 string(not also all ascii)//~vb2kI~
                oldcodetype=XEUTFCT_LC  ;   //primarily apply locale code//~vb2kI~
        }                                                          //~vb2kI~
#endif                                                             //~vb2kI~
//		rc2=xeutf_getmixedword(opt2,&oldcodetype,pc,reslen,pco,resleno,0/*oututf8*/,0/*oututf8 buffsz*/,pcn,&chklen,&wrtlen,0/*oututf8len*/);//chk 1 level path//~vauaR~
  		rc2=xeutf_getmixedword(opt2,&oldcodetype,pc,reslen,pco,resleno,0/*oututf8*/,0/*oututf8 buffsz*/,pcn,&chklen,&wrtlen,0/*oututf8len*/,pdddata,pdddbcs,pddcode,reslendd,&ddlen);//chk 1 level path//~vauaR~
#ifdef LNX                                                         //~vb2kI~
		if (swendsepc)                                             //~vb2HI~
        	if (pddcode && ddlen>0)                                //~vb2HI~
	        	*(pddcode+ddlen-1)=0;                              //~vb2HI~
		if ((pc+chklen)>=ppathend)                                 //~vb2kI~
            swnewpath=1;	//next is next path top                //~vb2kI~
        UTRACEP("%x:after xeutf_getmixedword rc=%d,swnewpath=%d,pc+chklen=%p,ppathend=%p\n",UTT,rc2,swnewpath,pc+chklen,ppathend);//~vb2kI~
#endif                                                             //~vb2kI~
        UTRACED("getmixedword data",pdddata,ddlen);//~vauJI~       //~vavGR~
        UTRACED("getmixedword code",pddcode,ddlen);//~vauJI~       //~vavGR~
        if (Pdddata)                                               //~vauaI~
        {                                                          //~vauaI~
        	totddlen+=ddlen;                                       //~vauaI~
        	reslendd-=ddlen;                                       //~vauaI~
        	pdddata+=ddlen;                                        //~vauaI~
        	pdddbcs+=ddlen;                                        //~vauaI~
        	pddcode+=ddlen;                                        //~vauaI~
        }                                                          //~vauaI~
        if (rc2==UALLOC_FAILED)                                    //~va10I~
        	return rc2;                                            //~va10I~
//#ifdef W32UNICODE                                                  //~vavaI~//~vavcR~
//        rc|=rc2 & (XEUTFGU8MRC_UTF8|XEUTFGU8MRC_LC|]EUTFGU8MRC_UTF8SUBC);//~vavaR~//~vavcR~
//*no user for XEUTFGU8MRC_UTF8SUBC;                               //~vavcI~
//#else                                                              //~vavaI~//~vavcR~
        rc|=rc2 & (XEUTFGU8MRC_UTF8|XEUTFGU8MRC_LC);               //~va10I~
//#endif                                                             //~vavaI~//~vavcR~
        if (Pcodetype)                                             //~va10I~
            pcn+=wrtlen;                                           //~va10I~
      }                                                            //~va10I~
      else  //old version                                          //~va10I~
      {                                                            //~va10I~
//search on utf8 code                                              //~va5nI~
//      pc2=umemchr2(pc,(char)dirsepc,reslen);                     //~vb01R~
        pc2=umemchr2(pc,(char)dirsepc,(size_t)reslen);             //~vb01I~
        if (!pc2)                                                  //~va00M~
	        len=reslen;                                            //~va00R~
        else                                                       //~va00M~
//          len=(int)((ULONG)pc2-(ULONG)pc)+1;                     //~va00I~//~vafkR~
            len=(int)((ULPTR)pc2-(ULPTR)pc)+1;                     //~vafkI~
        opt=0;                                                     //~va00R~
		utf8len=utfgetutf8strlen(opt,pc,len,&chrcnt);              //~va00R~
        if (utf8len==len)   //all valid utf8                       //~va00I~
    	{                                                          //~va00I~
            if (chrcnt==len)    //allascii                         //~va00I~
            {                                                      //~va00I~
                codetype=XEUTFCT_ASCII;         //utf8 str         //~va00I~
            	wrtlen=min(resleno,len);                           //~va00I~
        	    chklen=len;                                        //~va00I~
            	memcpy(pco,pc,(UINT)wrtlen);	//copy input locale str//~va00I~
            }                                                      //~va00I~
            else                                                   //~va00I~
            {                                                      //~va00I~
                opt=UTFCVO_ERRREP|(XEUTF_ERRREPCH<<8);             //~va00R~
                utfcvf2l(opt,pco,pc,utf8len,&chklen,&wrtlen,0/*Ppcharwidth*/);//~va00R~
                rc|=XEUTFGU8MRC_UTF8;                              //~va00R~
                codetype=XEUTFCT_UTF8;          //utf8 str         //~va00R~
            }                                                      //~va00I~
	    }                                                          //~va00I~
	    else    //locale->utf8                                     //~va00I~
    	{                                                          //~va00I~
			opt=0;                                                 //~va00I~
      		utfcvl2f(opt,utf8wk,pc,0/*init offs*/,len,0/*out choftbl*/,0/*out dbcstbl*/,&chklen,0/*outlen*/,0/*pcharcnt*/,0/*char width*/);//locale coed validity chk//~va00I~
            wrtlen=chklen;                                         //~va00I~
            if (wrtlen)                                            //~va00I~
            {                                                      //~va00I~
            	wrtlen=min(resleno,wrtlen);                        //~va00I~
            	memcpy(pco,pc,(UINT)wrtlen);	//copy input locale str//~va00I~
            	codetype=XEUTFCT_LC; //locale str                  //~va00I~
				rc|=XEUTFGU8MRC_LC;                                //~va00I~
            }                                                      //~va00I~
	    }                                                          //~va00I~
        if (Pcodetype)                                             //~va00I~
        {                                                          //~va00I~
        	memset(pcn,codetype,(UINT)wrtlen);                     //~va00I~
            pcn+=wrtlen;                                           //~va00I~
            if (pc2)                                               //~va00I~
            	*(pcn-1)=XEUTFCT_ASCII;                            //~va00I~
        }                                                          //~va00I~
      }//old logic                                                 //~va10I~
    }                                                              //~va00I~
    if (tailsz)                                                    //~va00I~
    {                                                              //~va00I~
        wrtlen=min(resleno,tailsz);                                //~va00I~
        if (wrtlen>0)                                              //~va00R~
        {                                                          //~va00I~
        	memcpy(pco,pc,(UINT)wrtlen);	//copy input locale str//~va00I~
            pco+=wrtlen;                                           //~va00R~
    	    if (Pcodetype)                                         //~va00I~
            {                                                      //~va00I~
    			memset(pcn,XEUTFCT_ASCII,(UINT)wrtlen);            //~va00I~
            	pcn+=wrtlen;                                       //~va00R~
            }                                                      //~va00I~
            if (Pdddata)                                           //~vauaI~
            {                                                      //~vauaI~
        		memcpy(pdddata,pc,(UINT)wrtlen);	//copy input locale str//~vauaI~
        		memset(pdddbcs,0,(UINT)wrtlen);	//copy input locale str//~vauaI~
        		memset(pddcode,0,(UINT)wrtlen);	//copy input locale str//~vauaI~
                totddlen+=wrtlen;                                  //~vauaI~
                reslendd-=wrtlen;                                  //~vauaI~
                pdddata+=wrtlen;                                   //~vauaI~
                pdddbcs+=wrtlen;                                   //~vauaI~
                pddcode+=wrtlen;                                   //~vauaI~
            }                                                      //~vauaI~
        }                                                          //~va00I~
    }                                                              //~va00I~
    if (Popt & XEUTFGLPNO_STRZ)                                    //~va00R~
        *pco=0;                                                    //~va00I~
//  outlen=(int)((ULONG)pco-(ULONG)Poutbuff);                      //~va00I~//~vafkR~
    outlen=(int)((ULPTR)pco-(ULPTR)Poutbuff);                      //~vafkI~
    if (Ppoutlen)                                                  //~va00I~
	    *Ppoutlen=outlen;                                          //~va00I~
    if (Ppddlen)                                                   //~vauaI~
	    *Ppddlen=totddlen;                                         //~vauaI~
	UTRACED("pout",Poutbuff,outlen);                               //~va00I~
    UTRACED("codetbl",Pcodetype,outlen);                           //~vauaR~
    UTRACED("dddata",Pdddata,totddlen);                            //~vauaI~
    UTRACED("dddbcs",Pdddbcs,totddlen);                            //~vauaI~
    UTRACED("ddcode",Pddcode,totddlen);                            //~vauaI~
    return rc;                                                     //~va00I~
}//xeutf_getlocalepathname                                         //~va00R~
#endif                                                             //~va00I~
#ifdef UTF8SUPPH                                                   //~va00I~
#ifdef AAA                                                         //~vagvI~
//**************************************************************** //~v90dM~
//!xeutf_getutf8str                                                //~v90xR~
//get utf8string                                                   //~va20R~
//optionaly  get converted locale string from utf8+ascii string    //~va00I~
//datalen:do strlen if 0                                           //~v90nI~
//outbuff:return malloced addr if 0                                //~v90nI~
//outbufflen:alloc(utflen+1) if 0                                  //~v90nI~
//outcharcnt:char width                                            //~v90rI~
//ret:-1:all ascii,0:all valid utf8,else converted out addr        //~v90nI~
//    -2:utf8 breaked by ascii char when ASCIIRET opt              //~v91cI~
//**************************************************************** //~v90dM~
char *xeutf_getutf8str(int Popt,char *Pstr,int Pdatalen,char *Poutbuff,PCHOFTYPE Ppchof,char *Ppdbcs,int Pbufflen,int *Ppreadlen,int *Pputflen,int *Ppcharcnt)//~v91cR~
{                                                                  //~v90dM~
//  char *pout,wk[_MAX_PATH*UTF8_MAXCHARSZ];                       //~v90dM~//~vav9R~
    char *pout,wk[_MAX_PATHU8];                                    //~vav9I~
    int rc,utflen,bufflen,repch,opt=0;                             //~v918R~
#ifdef UTF8SUPPH                                                   //~va00I~
    int charwidth;                                                 //~va00I~
#endif                                                             //~va00I~
//****************************                                     //~v90dM~
UTRACEP("xeutf_getutf8str\n");                                     //~v90nR~
	repch=(XEUTF_ERRREPCH<<8);                                                //~v90nR~//~va00R~
	opt=repch|UTFGUSO_OUTSTRZ;	//   0x0001    //set strz for output when conversion occured//~v918R~
    if (Popt & XEUTFGUO_ASCIIDELM) //exclude ascii as utf8 code    //~v91cI~
    	opt|=UTFGUSO_ASCIIRET;    //break reached to ascii         //~v91cI~
    if (Popt & XEUTFGUO_NOLOCALEDBCSTB) //exclude ascii as utf8 code//~v91cI~
    	opt|=UTFGUSO_NOLOCALEDBCSTB;    //break reached to ascii   //~v91cI~
#ifdef UTF8SUPPH                                                   //~va00I~
	rc=utfgetutf8str(opt,Pstr,Pdatalen,wk,Ppdbcs,Ppchof,Ppreadlen,&utflen,&charwidth);//~va00I~
    if (Ppcharcnt)                                                 //~va00I~
    	*Ppcharcnt=charwidth;                                      //~va00I~
#else                                                              //~va00R~
	rc=utfgetutf8str(opt,Pstr,Pdatalen,wk,Ppdbcs,Ppchof,Ppreadlen,&utflen,Ppcharcnt);//~v91cR~
#endif                                                             //~va00I~
//  if (rc==UTFGUSRC_ALLASCII||rc==UTFGUSRC_ALLUTF8)               //~v91cR~
    if (rc==UTFGUSRC_ALLASCII||rc==UTFGUSRC_ALLUTF8||rc==UTFGUSRC_ASCIIRETU8)//~v91cR~
    {                                                              //~v918I~
    	if (Pputflen)                                              //~v918I~
    		*Pputflen=utflen;                                      //~v918R~
#ifdef UTF8SUPPH                                                   //~va00I~
        if (Poutbuff && (Poutbuff!=Pstr||rc!=UTFGUSRC_ALLASCII))   //~va00I~
        	memcpy(Poutbuff,wk,(UINT)charwidth);		//copy locale code data//~va00R~
#endif                                                             //~va00I~
	    if (rc==UTFGUSRC_ALLASCII)                                 //~v918I~
//      	return (char*)(-1);                                    //~v918I~//~vafkR~
        	return (char*)(ULPTR)(-1);                             //~vafkI~
	    if (rc==UTFGUSRC_ASCIIRETU8)                               //~v91cR~
//	    	return (char*)(-2);                                    //~v91cI~//~vafkR~
	    	return (char*)(ULPTR)(-2);                             //~vafkI~
    	return 0;                //source is valid utf             //~v918I~
    }                                                              //~v918I~
//  if (rc==UTFGUSRC_ASCIIRETLC)                                   //~v91cI~
//      return (char*)(-3);        //chk it by readlen<Pdatalen    //~v91cI~
    if (Pbufflen)                                                  //~v90dM~
    	bufflen=Pbufflen;                                          //~v90dM~
    else                                                           //~v90dM~
    	bufflen=utflen+1;                                          //~v90dM~
  if (Poutbuff)                                                    //~v90nI~
    pout=Poutbuff;                                                 //~v90nI~
  else                                                             //~v90nI~
    pout=umalloc((UINT)bufflen);                                   //~v90dM~
    if (!pout)                                                     //~v90dM~
    	return 0;                                                  //~v90dM~
    memset(pout,0,(UINT)bufflen);                                  //~v90dM~
    utflen=min(utflen,bufflen-1);                                  //~v90yI~
    memcpy(pout,wk,(UINT)utflen);                                  //~v90dM~
    if (Pputflen)                                                  //~v90dM~
    	*Pputflen=utflen;                                          //~v90dM~
	UTRACED("pout",pout,utflen);                                   //~v90dR~
    return pout;                                                   //~v90dM~
}//xeutf_getutf8str                                                //~v90nR~
#endif  //AAA                                                      //~vagvI~
#ifdef AAA                                                         //~vagvI~
//**************************************************************** //~v918I~
//!xeutf_getutf8strm                                               //~v918I~
//get utf8 string(string separated by delm=" ,;'\"\\")             //~v918R~
//datalen:do strlen if 0                                           //~v918I~
//outcharcnt:char width                                            //~v918I~
//ret:0:all ascii,0x01:contains utf8,0x02 contains converted locale str//~v918I~
//**************************************************************** //~v918I~
int xeutf_getutf8strm(int Popt,char *Pstr,int Pdatalen,char *Ppdelmstr,char *Poutbuff,char *Pcodetype,int Poutbuffsz,int *Ppoutlen,int *Pplenc)//~v91cR~
{                                                                  //~v918I~
	char *pco,*pc,*pc2,*pcn,*pdelmstr,*putf8str;                   //~v918R~
    int rc=0,twidth=0,len,outlen,lenc,/*repch,*/reslen,resleno,wrtlen,chklen;//~v91cR~//~vaa7R~
    int codetype;                                                  //~v918I~
//****************************                                     //~v918I~
UTRACED("xeutf_getutf8strm data",Pstr,Pdatalen);                   //~v91cI~
//  repch=(XEUTF_ERRREPCH<<8);                                                //~v918I~//~va00R~//~vaa7R~
  	if (!(len=Pdatalen))                                           //~v918I~
		len=strlen(Pstr);                                          //~v918I~
    if (!(pdelmstr=Ppdelmstr))                                     //~v918I~
        pdelmstr=" ,;'\"\\";                                       //~v918R~
    for (pc=Pstr,pco=Poutbuff,pcn=Pcodetype,reslen=len,resleno=Poutbuffsz-1;reslen>0 && resleno>0;)//~v918R~
    {                                                              //~v918I~
    	if (*pc<0x80)                                              //~v918I~
        {                                                          //~v918I~
            twidth++;                                              //~v918I~
          if (Pcodetype)                                           //~v91cI~
            *pcn++=0;		//ascii id                             //~v918I~
        	*pco++=*pc++;                                          //~v918I~
            resleno--;                                             //~v918I~
            reslen--;                                              //~v918I~
            continue;                                              //~v918I~
        }                                                          //~v918I~
      if (Popt & XEUTFGUO_ASCIIDELM) //exclude ascii as utf8 code  //~v91cI~
        len=reslen;                                                //~v91cI~
      else                                                         //~v91cI~
      {                                                            //~v91cI~
//*search in utf8 code                                             //~va5nI~
        pc2=umempbrk(pc,pdelmstr,reslen);                          //~v918I~
        if (pc2)                                                   //~v918I~
//      	len=(int)((ULONG)pc2-(ULONG)pc);                       //~v918I~//~vafkR~
        	len=(int)((ULPTR)pc2-(ULPTR)pc);                       //~vafkI~
        else                                                       //~v918I~
        	len=reslen;                                            //~v918I~
      }                                                            //~v91cI~
		putf8str=xeutf_getutf8str(Popt,pc,len,pco,0 /*out chof*/,0 /*out dbcs*/,resleno,&chklen,&wrtlen,&lenc);//~v91cR~
        len=chklen;                                                //~v91cI~
//      if (putf8str==(char*)-2)	//utf8 breaked by ascii        //~v91cR~//~vafkR~
        if (putf8str==(char*)(ULPTR)-2)	//utf8 breaked by ascii    //~vafkI~
        {                                                          //~v91cI~
	        memcpy(pco,pc,(UINT)wrtlen);                           //~v91cI~
            codetype=1;                                            //~v91cI~
			rc|=XEUTFGU8MRC_UTF8;                                  //~v91cI~
        }                                                          //~v91cI~
        else                                                       //~v91cI~
        if (!putf8str)	//src is all utf8                          //~v918R~
        {                                                          //~v918I~
	        memcpy(pco,pc,(UINT)len);                              //~v918I~
        	wrtlen=len;                                            //~v918I~
            codetype=1;                                            //~v918I~
			rc|=XEUTFGU8MRC_UTF8;                                  //~v918I~
        }                                                          //~v918I~
        else                                                       //~v918I~
        {                                                          //~v918I~
            codetype=2;                                            //~v918I~
			rc|=XEUTFGU8MRC_LC;                                    //~v918I~
        }                                                          //~v918I~
//      if (pcn)                                                   //~v91cR~
        if (Pcodetype)                                             //~v91cI~
        {                                                          //~v918I~
            memset(pcn,codetype,(UINT)lenc);                       //~v918I~
            pcn+=lenc;                                             //~v918I~
        }                                                          //~v918I~
        twidth+=lenc;                                              //~v918I~
        pc+=len;                                                   //~v918I~
        pco+=wrtlen;                                               //~v918R~
        reslen-=len;                                               //~v918I~
        resleno-=wrtlen;                                           //~v918I~
    }                                                              //~v918I~
    if (Pplenc)                                                    //~v918I~
    	*Pplenc=twidth;                                            //~v918I~
//  outlen=(int)((ULONG)pco-(ULONG)Poutbuff);                      //~v918R~//~vafkR~
    outlen=(int)((ULPTR)pco-(ULPTR)Poutbuff);                      //~vafkI~
    *pco=0;                                                        //~v918I~
    if (Ppoutlen)                                                  //~v918I~
    	*Ppoutlen=outlen;                                          //~v918R~
	UTRACED("pout",Poutbuff,outlen);                               //~v918R~
    UTRACEDIFNZ("codetbl",Pcodetype,twidth);                       //~v918R~
    return rc;                                                     //~v918R~
}//xeutf_getutf8strm                                               //~v918R~
#endif                                                             //~vagvI~
//**************************************************************** //~v90xI~
//!xeutf_getlocalestr                                              //~v90xI~
//get utf8 filename from locale string                             //~v90xI~
//datalen:do strlen if 0                                           //~v90xI~
//outbuff:return malloced addr if 0                                //~v90xI~
//outbufflen:alloc(utflen+1) if 0                                  //~v90xI~
//outcharcnt:char width                                            //~v90xI~
//ret:-1:all ascii,converted out addr or 0:no conversion done      //~v90xI~
//**************************************************************** //~v90xI~
char *xeutf_getlocalestr(char *Pstr,int Pdatalen,char *Poutbuff,int Pbufflen,int *Pputflen,int *Ppcharcnt)//~v90xI~
{                                                                  //~v90xI~
//  char *pout,wk[_MAX_PATH*UTF8_MAXCHARSZ];                       //~v90xI~//~vav9R~
    char *pout,wk[_MAX_PATHU8];                                    //~vav9I~
    int len,rc,utflen,bufflen,opt=0,chklen,errctr;                 //~v90xR~
//****************************                                     //~v90xI~
UTRACEP("xeutf_getlocalestr\n");                                     //~v90xI~//~va00R~
  	if (!(len=Pdatalen))                                           //~v90xI~
//  	len=strlen(Pstr);                                          //~vb01R~
    	len=(int)strlen(Pstr);                                     //~vb01I~
  	else                                                           //~v90xI~
		opt=UTFCVO_EOLSPLITOK;  //allow last char cut by length    //~v91cR~
  	rc=utfisvalidutf8(opt,Pstr,len,0/*dbcs*/,0/*chof*/,0/*readlen*/,0/*ucscnt*/,Ppcharcnt);//~v91cR~
    if (rc==2)	//all ascii                                        //~v90xI~
    {                                                              //~v92rI~
    	if (Pputflen)                                              //~v92rI~
    		*Pputflen=len;                                         //~v92rI~
//      return (char*)(-1);                                        //~v90xI~//~vafkR~
        return (char*)(ULPTR)(-1);                                 //~vafkI~
    }                                                              //~v92rI~
    if (!rc              //source is invalid utf                   //~v911R~
//#ifdef LNX                                                       //~v91cR~
//    ||  !UCBITCHK(Gscrstatus,GSCRSDBCS) //Japanese               //~v91cR~
//#endif                                                           //~v91cR~
    )                                                              //~v90xI~
    {                                                              //~va1dI~
    	if (Pputflen)                                              //~va1dI~
    		*Pputflen=len;                                         //~va1dI~
    	return 0;   //                                             //~v90xI~
    }                                                              //~va1dI~
	opt|=UCVUCS_NOERRMSG;                                          //~v90xI~
#ifdef LNX                                                         //~v90xI~
  if (!UCBITCHK(Gscrstatus,GSCRSDBCS))//not Japanese               //~v91cR~
  {                                                                //~v91cI~
    	opt=UTFCVO_ERRREP|(XEUTF_ERRREPCH<<8);                                //~v91cR~//~va00R~
		utfcvf2l(opt,wk,Pstr,len,                                  //~v91cR~
			&chklen,&utflen,0/*Ppcharwidth*/);                     //~v91cR~
  }                                                                //~v91cI~
  else                                                             //~v91cI~
  {                                                                //~v91cI~
    opt|=UCVUCS_EUC;                                               //~v90xI~
#endif                                                             //~v90xI~
//  ucvsutf2sjis(0,opt,Pstr,len,wk,sizeof(wk),&chklen,&utflen,&errctr);//~vb01R~
    ucvsutf2sjis(0,(ULONG)opt,Pstr,len,wk,(int)sizeof(wk),&chklen,&utflen,&errctr);//~vb01R~
#ifdef LNX                                                         //~v91cI~
  }                                                                //~v91cI~
#endif                                                             //~v91cI~
    len=utflen;                                                    //~v90xI~
//  if (Pputflen)                                                  //~v90xI~//~vagwR~
//  	*Pputflen=len;                                             //~v90xI~//~vagwR~
    if (Pbufflen)                                                  //~v90xI~
    	bufflen=Pbufflen;                                          //~v90xI~
    else                                                           //~v90xI~
    	bufflen=len+1;                                             //~v90xI~
  	if (Poutbuff)                                                  //~v90xI~
    	pout=Poutbuff;                                             //~v90xI~
  	else                                                           //~v90xI~
    	pout=umalloc((UINT)bufflen);                               //~v90xI~
    if (!pout)                                                     //~v90xI~
    	return Pstr;                                               //~v90xI~
    memset(pout,0,(UINT)bufflen);                                  //~v90xI~
    utflen=min(bufflen,utflen);                                    //~vagwR~
    if (Pputflen)                                                  //~vagwR~
  	  	*Pputflen=utflen;                                          //~vagwR~
    memcpy(pout,wk,(UINT)utflen);                                  //~v90xI~
    return pout;                                                   //~v90xI~
}//xeutf_getlocalestr                                              //~v90xI~
//**************************************************************** //~va3MI~
//locale code chk; dbcs and unprintable                            //~va3MI~
//rc :0x08 dbcd err,0x04:unprintable                               //~va3MI~
//**************************************************************** //~va3MI~
int xeutfdbcsnpchk(int Popt,char *Pdata,char *Pdbcs,int Plen,int *Pplen)//~va3MR~
{                                                                  //~va3MI~
	int rc=0,lenok=0,ii;                                           //~va3MR~
    char *pc,*pcd;                                                 //~va3MI~
//********************                                             //~va3MI~
	setdbcstbl(Pdata,Pdbcs,Plen);                                  //~va3MI~
    for (ii=0,pc=Pdata,pcd=Pdbcs;ii<Plen;ii++,pc++,pcd++)          //~va3MI~
    {                                                              //~va3MI~
    	if (*pcd==UDBCSCHK_HKDBCSERR)                              //~va3MR~
    		rc|=0x08;                                              //~va3MI~
        else                                                       //~va3MI~
    	if (!*pcd)	//sbcs                                         //~va3MR~
        	if (!UDBCSCHK_ISPRINT(*pc))                            //~va3MI~
	    		rc|=0x04;                                          //~va3MI~
        if (!rc)                                                   //~va3MR~
        	lenok++;                                               //~va3MI~
    }                                                              //~va3MI~
    if (Pplen)                                                     //~va3MI~
    	*Pplen=lenok;                                              //~va3MI~
    UTRACED("xeutfdbcsnpchk pc  ",Pdata,Plen);                     //~va3MI~
    UTRACED("xeutfdbcsnpchk dbcs",Pdbcs,Plen);                     //~va3MI~
    UTRACEP("xeutfdbcsnpchk rc=%d,lenok=%d\n",rc,lenok);           //~va3MI~
    return rc;                                                     //~va3MI~
}//xeutfdbcsnpchk                                                  //~va3MI~
//#ifdef LNX                                                       //~vavpR~
//#ifdef AAA                                                       //~vavpR~
////****************************************************************//~vavpR~
////locale code chk; dbcs and unprintable                          //~vavpR~
////rc :0x08 dbcd err,0x04:unprintable                             //~vavpR~
////****************************************************************//~vavpR~
//int xeutfdbcsnpchkDDFMT(int Popt,char *Pdddata,char *Pdddbcs,int Plen)//~vavpR~
//{                                                                //~vavpR~
//    int rc=0,ii;                                                 //~vavpR~
//    char *pc,*pcd,cht;                                           //~vavpR~
////********************                                           //~vavpR~
//    for (ii=0,pc=Pdddata,pcd=Pdddbcs;ii<Plen;ii++,pc++,pcd++)    //~vavpR~
//    {                                                            //~vavpR~
//        cht=*pcd;                                                //~vavpR~
//        switch(cht)                                              //~vavpR~
//        {                                                        //~vavpR~
//        case UDBCSCHK_DBCS1STUCS_CASE():                         //~vavpR~
//            if (cht==UDBCSCHK_NPUCS1)                            //~vavpR~
//                rc|=0x08;                                        //~vavpR~
//            pc++;                                                //~vavpR~
//            pcd++;                                               //~vavpR~
//            ii++;                                                //~vavpR~
//            break;                                               //~vavpR~
//        case UDBCSCHK_DBCS2NDUCS_CASE():                         //~vavpR~
//            rc|=0x08;                                            //~vavpR~
//            break;                                               //~vavpR~
//        default:    //sbcs                                       //~vavpR~
//            if (!UDBCSCHK_ISPRINT(*pc))                          //~vavpR~
//                rc|=0x04;                                        //~vavpR~
//        }                                                        //~vavpR~
//    }                                                            //~vavpR~
//    UTRACED("xeutfdbcsnpchkDDFMT pc",Pdddata,Plen);              //~vavpR~
//    UTRACED("xeutfdbcsnpchkDDFMT dbcs",Pdddbcs,Plen);            //~vavpR~
//    UTRACEP("xeutfdbcsnpchkDDFMT rc=%d\n",rc);                   //~vavpR~
//    return rc;                                                   //~vavpR~
//}//xeutfdbcsnpchkDDFMT                                           //~vavpR~
//#endif //AAA                                                     //~vavpR~
//#ifdef AAA                                                       //~vavpR~
////****************************************************************//~vavpR~
////!xeutf_getmixedword                                            //~vavpR~
////translate locale and utf8 mixed string to ddfmt                //~vavpR~
////try f2l and l2f                                                //~vavpR~
////   if both ok :1st call:depends kbdmode                        //~vavpR~
////              :2nd call:same as previos mode                   //~vavpR~
////   if both err:it is locale word                               //~vavpR~
////ret:0:all ascii,0x01:contains utf8 str(cv to ddfmt),0x02 contains locale str(cv to ddfmt)//~vavpR~
////    UALLOC FAILED                                              //~vavpR~
////****************************************************************//~vavpR~
//int xeutf_getmixedwordDDFMT(int Popt,int *Ppcodetype,char *Pdata,int Pdatalen,char *Poutbuff/*outdddata*/,int Poutbuffsz,char *Poutdddbcs,//~vavpR~
//                        char *Pcodetypetbl,int *Ppchklen,int *Ppoutlen)//~vavpR~
//{                                                                //~vavpR~
//    char *pco,*pci,*pc2,*pcto,*pcdo;                             //~vavpR~
//    UCHAR *pdddataf2dd,*pdddbcsf2dd,*pdddatal2dd,*pdddbcsl2dd;   //~vavpR~
//    UCHAR *pwkdddata,*pwkdddbcs;                                 //~vavpR~
//    int rc=0,reslen,resleno,wrtlen,wrtlenl2dd,wrtlenf2dd,chklen,rc2,swerrf2l=1,swerrl2f=0;//~vavpR~
//    int opt,outlen,reslen2,buffsz;                               //~vavpR~
//    int oldcodetype,newcodetype,swallascii,readlen;              //~vavpR~
////*****************************                                  //~vavpR~
//    oldcodetype=*Ppcodetype;                                     //~vavpR~
//UTRACEP("getmixedwordDDFMT oldcodetype=%d\n",oldcodetype);       //~vavpR~
//UTRACED("getmixedwordDDFMT input",Pdata,Pdatalen);               //~vavpR~
//    buffsz=Pdatalen*2;      //max dd char=2                      //~vavpR~
//    pwkdddata=xeutf_buffget(XEUTF_BUFFMIXWORD,buffsz*2);   //data&dbcs//~vavpR~
//    pwkdddbcs=pwkdddata+buffsz;                                  //~vavpR~
//    swallascii=1;                                                //~vavpR~
//    pci=Pdata;                                                   //~vavpR~
//    reslen=Pdatalen;                                             //~vavpR~
//    for (pci=Pdata,reslen=Pdatalen;reslen>0;pci++,reslen--)      //~vavpR~
//    {                                                            //~vavpR~
//        if (!UTF8ISASCII(*pci))                                  //~vavpR~
//            break;                                               //~vavpR~
//    }                                                            //~vavpR~
//    chklen=Pdatalen-reslen;                                      //~vavpR~
//    pco=Poutbuff;                                                //~vavpR~
//    pcdo=Poutdddbcs;                                             //~vavpR~
//    pcto=Pcodetypetbl;                                           //~vavpR~
//    resleno=Poutbuffsz;                                          //~vavpR~
//    if (chklen)                                                  //~vavpR~
//    {                                                            //~vavpR~
//        chklen=min(resleno,chklen);                              //~vavpR~
//        wrtlen=chklen;                                           //~vavpR~
//        memcpy(pco,pci,(UINT)wrtlen);                            //~vavpR~
//        memset(pcdo,0,(UINT)wrtlen);                             //~vavpR~
//        pco+=wrtlen;                                             //~vavpR~
//        pcdo+=wrtlen;                                            //~vavpR~
//        resleno-=wrtlen;                                         //~vavpR~
//        if (Pcodetypetbl)                                        //~vavpR~
//        {                                                        //~vavpR~
//            memset(pcto,XEUTFCT_ASCII,(UINT)wrtlen); //input is valid utf8//~vavpR~
//            pcto+=wrtlen;                                        //~vavpR~
//        }                                                        //~vavpR~
//    }                                                            //~vavpR~
//    readlen=chklen;                                              //~vavpR~
//    outlen=chklen;                                               //~vavpR~
//    if (reslen)                                                  //~vavpR~
//        swallascii=0;                                            //~vavpR~
//    if (swallascii)                                              //~vavpR~
//        newcodetype=oldcodetype;   //select l2f                  //~vavpR~
//    else                                                         //~vavpR~
//    {                                                            //~vavpR~
//        swallascii=0;                                            //~vavpR~
//        for (pc2=pci,reslen2=reslen;reslen2>0;pc2++,reslen2--)// //~vavpR~
//        {                                                        //~vavpR~
//            if (UTF8ISASCII(*pc2))                               //~vavpR~
//                break;                                           //~vavpR~
//        }                                                        //~vavpR~
//        reslen-=reslen2;    //non ascii part                     //~vavpR~
//        readlen+=reslen;                                         //~vavpR~
//        opt=0;                                                   //~vavpR~
//        chklen=utfgetutf8strlen(opt,pci,reslen,0/*out ucscount*/);//~vavpR~
//        if (chklen==reslen) //all valid utf8                     //~vavpR~
//        {                                                        //~vavpR~
//            xeutf_cvf2dd(0,pci,chklen,&pdddataf2dd,&pdddbcsf2dd,&wrtlenf2dd);//~vavpR~
//            swerrf2l=0;                                          //~vavpR~
//            memcpy(pwkdddata,pdddataf2dd,wrtlenf2dd);            //~vavpR~
//            memcpy(pwkdddbcs,pdddbcsf2dd,wrtlenf2dd);            //~vavpR~
//        }                                                        //~vavpR~
////*try locale code                                               //~vavpR~
//        opt=UTFCVO_ERRRET|UTFCVO_ASCIIRET;                       //~vavpR~
//        rc2=xeutfcvl2dd(opt,pci,reslen,&pdddatal2dd,&pdddbcsl2dd,&wrtlenl2dd);//~vavpR~
//        if (rc2==UALLOC_FAILED)                                  //~vavpR~
//            return UALLOC_FAILED;                                //~vavpR~
//        if (!swerrf2l)  //f2l ok                                 //~vavpR~
//        {                                                        //~vavpR~
//            if (xeutfdbcsnpchkDDFMT(0,pdddatal2dd,pdddbcsl2dd,wrtlenl2dd))//~vavpR~
//               swerrl2f=1;  //select utf8                        //~vavpR~
//        }                                                        //~vavpR~
//UTRACEP("utfgetnmixedwordDDFMT swallascii=%d,errf2l=%d,errl2f=%d\n",swallascii,swerrf2l,swerrl2f);//~vavpR~
////select utf8 or locale                                          //~vavpR~
//        if (swerrf2l)   //fl2 err                                //~vavpR~
//            newcodetype=XEUTFCT_LC;   //select l2f               //~vavpR~
//        else                                                     //~vavpR~
//        {                                                        //~vavpR~
//            if (swerrl2f)        //f2l ok,l2f ng                 //~vavpR~
//                newcodetype=XEUTFCT_UTF8;       //select f2l     //~vavpR~
//            else                 //both ok                       //~vavpR~
//            {                                                    //~vavpR~
//                if (oldcodetype==XEUTFCT_LC)                     //~vavpR~
//                    newcodetype=XEUTFCT_LC;                      //~vavpR~
//                else                                             //~vavpR~
//                if (oldcodetype==XEUTFCT_UTF8)                   //~vavpR~
//                    newcodetype=XEUTFCT_UTF8;                    //~vavpR~
//                else                                             //~vavpR~
//                    if (Gutfmode2 & GUM2_KBDUTF8)                //~vavpR~
//                        newcodetype=XEUTFCT_UTF8;                //~vavpR~
//                    else                                         //~vavpR~
//#ifdef LNX                                                       //~vavpR~
//                    if (UDBCSCHK_ISUTF8())                       //~vavpR~
//                        newcodetype=XEUTFCT_UTF8;                //~vavpR~
//                    else                                         //~vavpR~
//#endif                                                           //~vavpR~
//                        newcodetype=XEUTFCT_LC;                  //~vavpR~
//            }                                                    //~vavpR~
//        }                                                        //~vavpR~
//        if (newcodetype==XEUTFCT_UTF8)   //determined UTF8 word  //~vavpR~
//        {                                                        //~vavpR~
//            wrtlen=wrtlenf2dd;                                   //~vavpR~
//            memcpy(pco,pwkdddata,wrtlen);                        //~vavpR~
//            memcpy(pcdo,pwkdddbcs,wrtlen);                       //~vavpR~
//            rc|=XEUTFGU8MRC_UTF8;                                //~vavpR~
//        }                                                        //~vavpR~
//        else                                                     //~vavpR~
//        {                                                        //~vavpR~
//            wrtlen=wrtlenl2dd;                                   //~vavpR~
//            memcpy(pco,pdddatal2dd,wrtlen);                      //~vavpR~
//            memcpy(pcdo,pdddbcsl2dd,wrtlen);                     //~vavpR~
//            rc|=XEUTFGU8MRC_LC;                                  //~vavpR~
//        }                                                        //~vavpR~
//        outlen+=wrtlen;                                          //~vavpR~
//        if (Pcodetypetbl)                                        //~vavpR~
//            memset(pcto,newcodetype,wrtlen);                     //~vavpR~
//    }//!allascii                                                 //~vavpR~
//    if (Ppchklen)                                                //~vavpR~
//        *Ppchklen=readlen;                                       //~vavpR~
//    if (Ppoutlen)                                                //~vavpR~
//        *Ppoutlen=outlen;                                        //~vavpR~
//    UTRACEP("utfgetmixedwordDDFMT rc=%d,newcodetype=%d\n",rc,newcodetype);//~vavpR~
//    UTRACED("utfgetmixedwordDDFMT pco",Poutbuff,outlen);         //~vavpR~
//    UTRACED("utfgetmixedwordDDFMT pcdo",Poutdddbcs,outlen);      //~vavpR~
//    UTRACEDIFNZ("utfgetmixedwordDDFMT codetbl",Pcodetypetbl,outlen);//~vavpR~
//    return rc;                                                   //~vavpR~
//}//xeutf_getmixedwordDDFMT                                       //~vavpR~
//#endif //AAA                                                     //~vavpR~
//#endif  //LNX                                                    //~vavpR~
//**************************************************************** //~va10I~
//!xeutf_getmixedword                                              //~va10I~
//translate locale and utf8 mixed string to locale and utf8 string //~va10I~
//try f2l and l2f                                                  //~va10I~
//   if both ok :1st call:depends kbdmode                          //~va10I~
//              :2nd call:same as previos mode                     //~va10I~
//   if both err:it is locale word                                 //~va10I~
//ret:0:all ascii,0x01:contains utf8 str(cv to locale),0x02 contains locale str//~va10I~
//    0x04:contain UD fmt str                                      //~vavaI~
//    UALLOC FAILED                                                //~va10I~
//**************************************************************** //~va10I~
int xeutf_getmixedword(int Popt,int *Ppcodetype,char *Pdata,int Pdatalen,char *Poutbuff,int Poutbuffsz,char *Poututf8,int Poututf8sz,//~va10R~
//  					char *Pcodetypetbl,int *Ppchklen,int *Ppoutlen,int *Ppoututf8len)//~vauaR~
    					char *Pcodetypetbl,int *Ppchklen,int *Ppoutlen,int *Ppoututf8len,char *Pdddata,char *Pdddbcs,char *Pddcode,int Pddbuffsz,int *Ppddlen)//~vauaR~
{                                                                  //~va10I~
	char *pco,*pc,*pc2,*pct;                                       //~va10R~
    char *pcou8,*pwkct,*pwku8,*pwklc;                              //~va10R~
    char *pwkdbcs;                                                 //~va3MR~
    int rc=0,reslen,resleno,wrtlen,chklen,rc2,swdelm,swerrf2l,swerrl2f;//~va10R~
    int opt,utf8len,outlen=0,oututf8len=0,reslen2,outlenf2l,oututf8lenf2l;//~vaf9R~
    int oldcodetype,wkbuffsz,reslenou8,newcodetype,swallascii,readlen=0,readlenf2l;//~vaf9R~
    int ch;                                                        //~va10I~
    int dirsepc;                                                   //~va10I~
    int wkallocsz,ddbuffsz,ddlenu8=0,ddlenlc=0,ddlen;              //~vauaR~
    char *pdddata,*pdddbcs,*pddcode,*pwkdddatau8,*pwkdddbcsu8,*pwkddcodeu8,*pwkdddatalc,*pwkdddbcslc,*pwkddcodelc;//~vauaR~
//#ifdef LNX                                                         //~vauaI~//~vavaR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaI~
    int swkeeplcwidth;                                             //~vauaI~
#endif                                                             //~vauaI~
#ifdef W32UNICODE                                                  //~vavaI~
	char *pcud,*pc3;                                               //~vavaI~
    int udlen,swudu8;                                              //~vavaR~
	int swmixedstrUD;                                              //~vavEI~
#endif                                                             //~vavaI~
//*****************************                                    //~va10I~
//#ifdef LNX                                                         //~vauaI~//~vavaR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaI~
    swkeeplcwidth=(Popt & XEUTFGLSMO_LCWIDTHBYDDWIDTH);            //~vauaI~
#endif                                                             //~vauaI~
	oldcodetype=*Ppcodetype;                                       //~va10R~
    if (Popt & XEUTFGLSMO_FILEPATH)                                //~va10I~
	    dirsepc=(Popt & XEUTFGLSMO_SEPCMASK)>>16;                  //~va10I~
    else                                                           //~va10I~
    	dirsepc=0;                                                 //~va10I~
#ifdef W32UNICODE                                                  //~vavEI~
	swmixedstrUD=Popt & XEUTFGLSMO_MIXEDUDSTR; //0x0200	//from getmisexstring to getmixedword,regardless seperator of dirsepc//~vavEI~
    if (swmixedstrUD)                                              //~vavEI~
	    dirsepc=UD_NOTLC;	//force chk UD str	                   //~vavER~
#endif                                                             //~vavEI~
UTRACEP("%s:opt=%x,oldcodetype=%d\n",UTT,Popt,oldcodetype);              //~va10R~//~vb2kR~
UTRACED("getmixedword input",Pdata,Pdatalen);                      //~va10I~
	wkbuffsz=Pdatalen+1;                                           //~va10I~
//  pwklc=xeutf_buffget(XEUTF_BUFFMIXWORD,wkbuffsz*(2+UTF8_MAXCHARSZMAX));//~va1cR~
//  pwklc=xeutf_buffget(XEUTF_BUFFMIXWORD,wkbuffsz*(UTF8_F2LMAXRATE+UTF8_F2LMAXRATE+UTF8_MAXCHARSZMAX));//~va1cR~//~va3MR~
//  pwklc=xeutf_buffget(XEUTF_BUFFMIXWORD,wkbuffsz*(UTF8_F2LMAXRATE+UTF8_F2LMAXRATE+UTF8_MAXCHARSZMAX+1));//~vauaR~
    wkallocsz=wkbuffsz*(UTF8_F2LMAXRATE+UTF8_F2LMAXRATE+UTF8_MAXCHARSZMAX+UTF8_F2LMAXRATE);	//lc,ct,u8,dbcs//~vauaR~
    ddbuffsz=wkbuffsz*2;   //ddfmt char sz                         //~vauaR~
    if (Pdddata)                                                   //~vauaM~
    	wkallocsz+=ddbuffsz*6;		//dddata,dddbcs,ddct *ddfmtsz*for selected u8/lc//~vauaI~
//  pwklc=xeutf_buffget(XEUTF_BUFFMIXWORD,wkbuffsz*wkallocsz);     //~vauaI~//~vb7dR~
    pwklc=xeutf_buffget(XEUTF_BUFFMIXWORD,wkallocsz);              //~vb7dI~
	UALLOCCHK(pwklc,UALLOC_FAILED);                                //~va10I~
//  pwkct=pwklc+wkbuffsz;                                          //~va1cR~
    pwkct=pwklc+wkbuffsz*UTF8_F2LMAXRATE;                          //~va1cR~
//  pwku8=pwkct+wkbuffsz;                                          //~va1cR~
    pwku8=pwkct+wkbuffsz*UTF8_F2LMAXRATE;                          //~va1cR~
    pwkdbcs=pwku8+wkbuffsz*UTF8_MAXCHARSZMAX;                      //~va3MI~
    if (Pdddata)                                                   //~vauaI~
    {                                                              //~vauaI~
    	pwkdddatau8=pwkdbcs+wkbuffsz*UTF8_F2LMAXRATE;		//dddata,dddbcs,ddct *ddfmtsz//~vauaI~
    	pwkdddbcsu8=pwkdddatau8+ddbuffsz;		//dddata,dddbcs,ddct *ddfmtsz//~vauaR~
    	pwkddcodeu8=pwkdddbcsu8+ddbuffsz;		//dddata,dddbcs,ddct *ddfmtsz//~vauaR~
    	pwkdddatalc=pwkddcodeu8+ddbuffsz;		//dddata,dddbcs,ddct *ddfmtsz//~vauaR~
    	pwkdddbcslc=pwkdddatalc+ddbuffsz;		//dddata,dddbcs,ddct *ddfmtsz//~vauaR~
    	pwkddcodelc=pwkdddbcslc+ddbuffsz;		//dddata,dddbcs,ddct *ddfmtsz//~vauaR~
    }                                                              //~vauaI~
    else                                                           //~vauaI~
    	pwkdddatau8=pwkdddbcsu8=pwkddcodeu8=pwkdddatalc=pwkdddbcslc=pwkddcodelc=NULL;//~vauaR~
    swallascii=1;                                                  //~va10I~
//try utf8                                                         //~va10I~
    pdddata=pwkdddatau8;                                           //~vauaI~
    pdddbcs=pwkdddbcsu8;                                           //~vauaI~
    pddcode=pwkddcodeu8;                                           //~vauaI~
    swdelm=0;                                                      //~va10I~
#ifdef W32UNICODE                                                  //~vaw1I~
    pcud=NULL;                                                     //~vavaI~
    swudu8=0;                                                      //~vavaI~
    udlen=0;                                                       //~vavaI~
#endif                                                             //~vaw1I~
    for (pc=Pdata,pco=pwklc,pct=pwkct,pcou8=pwku8,reslen=Pdatalen, //~va10R~
            resleno=min(wkbuffsz,Poutbuffsz),reslenou8=min(wkbuffsz*UTF8_MAXCHARSZMAX,Poututf8sz);//~va10R~
			!swdelm && reslen>0 && resleno>0;                      //~va10R~
            reslen-=chklen,resleno-=wrtlen,pc+=chklen,pco+=wrtlen) //~va10I~
    {                                                              //~va10I~
#ifdef LNX                                                         //~vb2kI~
		if (Popt & XEUTFGLSMO_NOTUTF8PATH)	//no try to chk utf8   //~vb2kI~
        {                                                          //~vb2kI~
        	swallascii=0;                                          //~vb2kI~
        	break;                                                 //~vb2kI~
        }                                                          //~vb2kI~
#endif                                                             //~vb2kI~
//  	for (pc2=pc,reslen2=reslen;!swdelm;pc2++,reslen2--)        //~va19R~
    	for (pc2=pc,reslen2=reslen;!swdelm && reslen2>0;pc2++,reslen2--)//~va19I~
        {                                                          //~va10I~
    		if (!UTF8ISASCII(*pc2))                                //~va10R~
            	break;                                             //~va10I~
            ch=*pc2;                                               //~va10I~
          if (dirsepc)                                             //~va10R~
          {//getlocalepath                                         //~vavaR~
#ifdef W32UNICODE                                                  //~vavaI~
            if (ch==UD_NOTLC && reslen2>=3)   //UDfmt              //~vavaI~
            {                                                      //~vavaI~
            	pc3=pc2+1;                                         //~vavaI~
//          	if (*pc3==UD_UTF8SUBC)                             //~vavaR~
            	if (*pc3==UD_UTF8WCSUBC||*pc3==UD_UTF8WC)          //~vavaR~
                {                                                  //~vavaI~
                    swudu8=*pc3;                                   //~vavcI~
                    pc3=memchr(pc3,UD_NOTLC,reslen-1);             //~vavaI~
                    if (pc3)                                       //~vavaI~
                    {                                              //~vavaI~
                        pcud=pc2;   //start of UD string           //~vavaI~
                        udlen=PTRDIFF(pc3,pc2)+1;                  //~vavaI~
					  if (swmixedstrUD)                            //~vavEI~
                        swdelm=1;                                  //~vavEI~
                      else                                         //~vavEI~
                        swdelm=(*(pc3+1)==dirsepc);                //~vavaI~
//                      udlen+=swdelm; //loop if include delm because next is not ascii(break with chkle=0)//~vavsR~
//                      swudu8=*pc3;                               //~vavaI~//~vavcR~
                        break;                                     //~vavaI~
                    }                                              //~vavaI~
                }                                                  //~vavaI~
            }                                                      //~vavaI~
#endif                                                             //~vavaI~
            swdelm=(ch==dirsepc);                                  //~va10R~
          }                                                        //~vavaI~
          else                                                     //~va10I~
#ifdef W32                                                         //~va10I~
//*!ebc                                                            //~va50I~
            swdelm=(ch==' ')||ispunct(ch)||(ch=='\\');             //~va10R~
#else                                                              //~va10I~
            swdelm=(ch==' ')||ispunct(ch);                         //~va10I~
#endif                                                             //~va10I~
        }                                                          //~va10I~
        chklen=reslen-reslen2;                                     //~va10I~
        if (chklen)                                                //~va10I~
        {                                                          //~va10I~
        	chklen=min(resleno,chklen);                            //~va10I~
        	wrtlen=chklen;                                         //~va10I~
            memcpy(pco,pc,(UINT)wrtlen);                           //~va10I~
	        if (Pcodetypetbl)                                      //~va10R~
        	{                                                      //~va10I~
    	    	memset(pct,XEUTFCT_ASCII,(UINT)wrtlen);	//input is valid utf8//~va10I~
            	pct+=wrtlen;                                       //~va10I~
        	}                                                      //~va10I~
            if (Poututf8)                                          //~va10I~
            {                                                      //~va10I~
            	utf8len=min(reslenou8,chklen);                     //~va10I~
            	memcpy(pcou8,pc,(UINT)utf8len);                    //~va10R~
	            pcou8+=utf8len;                                    //~va10R~
                reslenou8-=utf8len;                                //~va10I~
            }                                                      //~va10I~
		    if (Pdddata)                                           //~vauaI~
            {                                                      //~vauaI~
            	memcpy(pdddata,pc,(UINT)chklen);                   //~vauaI~
    	    	memset(pdddbcs,0,(UINT)wrtlen);	//input is valid utf8//~vauaI~
    	    	memset(pddcode,XEUTFCT_ASCII,(UINT)wrtlen);	//input is valid utf8//~vauaI~
	            pdddata+=chklen;                                   //~vauaI~
	            pdddbcs+=wrtlen;                                   //~vauaI~
	            pddcode+=wrtlen;                                   //~vauaI~
                ddlenu8+=wrtlen;                                   //~vauaR~
            }                                                      //~vauaI~
            continue;                                              //~va10I~
        }                                                          //~va10I~
        swallascii=0;                                              //~va10M~
//  	opt=UTFCVO_ASCIIRET|UTFCVO_ERRRET;	//return if translation err//~va10I~//~va3xR~
//    	rc2=utfcvf2l(opt,pco,pc,reslen,&chklen,&wrtlen,0/*Ppcharwidth*/);//~va10I~//~va3xR~
//  	if (rc2>=UTFCVRC_ERR)                                      //~va10I~//~va3xR~
//      	break;                                                 //~va10I~//~va3xR~
#ifdef W32UNICODE                                                  //~vavaI~
      if (pcud)                                                    //~vavaI~
      {                                                            //~vavaI~
//        opt=0;  //return if ascii detected                         //~vavaI~//~vavcR~
//        chklen=utfgetutf8strlen(opt,pc,udlen,0/*out ucscount*/);   //~vavaI~//~vavcR~
    	chklen=udlen;                                              //~vavcI~
      }                                                            //~vavaI~
      else                                                         //~vavaI~
#endif                                                             //~vavaI~
      {                                                            //~vavaI~
    	opt=UTFCVO_ASCIIRET;	//return if ascii detected         //~va3xI~
    	chklen=utfgetutf8strlen(opt,pc,reslen,0/*out ucscount*/);  //~va3xI~
      }                                                            //~vavaI~
//      if (!chklen || !UTF8ISASCII(*(pc+chklen)))                 //~va3xI~//~vagvR~
        if (!chklen || (chklen<reslen && !UTF8ISASCII(*(pc+chklen))))//~vagvI~
        	break;	//breaked by not ascii char                    //~va3xI~
//  	opt=UTFCVO_ASCIIRET|UTFCVO_ERRREP|(XEUTF_ERRREPCH_F2LFILE<<8);//~vauaR~
#ifdef W32UNICODE                                                  //~vaw1I~
      if (pcud)                                                    //~vavEI~
    	opt=UTFCVO_ERRREP|(XEUTFDD2LC_REPERR<<8);                  //~vavEI~
      else                                                         //~vavEI~
#endif                                                             //~vaw1I~
    	opt=UTFCVO_ASCIIRET|UTFCVO_ERRREP|(XEUTFDD2LC_REPERR<<8);  //~vauaI~
//#ifdef LNX                                                         //~vauaI~//~vavaR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaI~
	  if (swkeeplcwidth)                                           //~vauaI~
      {                                                            //~vavsI~
#ifdef W32UNICODE                                                  //~vavsI~
	   if (Pcodetypetbl && !(Popt & XEUTFGLSMO_SETINPATHALL))	//set XEUTFCT_UTF8 all char in the path//~vavsI~
		xeutfcvf2lDDWct(Popt,pc,chklen,pco,resleno,&wrtlen,pct);   //~vavsI~
       else                                                        //~vavsI~
#endif                                                             //~vavsI~
		xeutfcvf2lDDW(Popt,pc,chklen,pco,resleno,&wrtlen);         //~vauaI~
      }                                                            //~vavsI~
      else                                                         //~vauaI~
#endif                                                             //~vauaI~
      {                                                            //~vaumI~
#ifdef W32UNICODE                                                  //~vavsI~
	   if (Pcodetypetbl && !(Popt & XEUTFGLSMO_SETINPATHALL))	//set XEUTFCT_UTF8 all char in the path//~vavsI~
       {                                                           //~vavEI~
       	int opt2;                                                  //~vavEI~
    	opt2=XEUTFF2LCO_ERRREP;                                    //~vavER~
      	rc2=xeutfcvf2lc(opt2,pc,chklen,pco,pct,resleno,&wrtlen,NULL/*chklen*/);//~vavsR~//~vavER~
       }                                                           //~vavEI~
       else                                                        //~vavsI~
#endif                                                             //~vavsI~
      	rc2=utfcvf2l(opt,pco,pc,chklen,0/*chklen*/,&wrtlen,0/*Ppcharwidth*/);//~va3xI~
UTRACEP("getmixedword utfcvf2l rc=%d,datalen=%d,chklen=%d,wrtlen=%d\n",rc2,reslen,chklen,wrtlen);//~va10R~//~va3xM~
      }                                                            //~vaumI~
        if (Pcodetypetbl)                                          //~va10M~
        {                                                          //~va10M~
#ifdef W32UNICODE                                                  //~vavsI~
	     if ((Popt & XEUTFGLSMO_SETINPATHALL))	//set XEUTFCT_UTF8 all char in the path//~vavsI~
#endif                                                             //~vavsI~
        	memset(pct,XEUTFCT_UTF8,(UINT)wrtlen);	//input is valid utf8//~va10M~
            pct+=wrtlen;                                           //~va10M~
        }                                                          //~va10M~
        if (Poututf8)                                              //~va10I~
        {                                                          //~va10I~
        	utf8len=min(chklen,reslenou8);                         //~va10I~
	        memcpy(pcou8,pc,(UINT)utf8len);	//input is valid utf8  //~va10R~
	        pcou8+=utf8len;                                        //~va10R~
            reslenou8-=utf8len;                                    //~va10I~
        }                                                          //~va10I~
        if (Pdddata)  //output by ddfmt                            //~vauaI~
        {                                                          //~vauaI~
			utfcvf2dd(0,pc,chklen,pdddata,pdddbcs,ddbuffsz-PTRDIFF(pdddata,pwkdddatau8),&ddlen);//~vauaR~
        	memset(pddcode,XEUTFCT_UTF8,(UINT)wrtlen);	//input is valid utf8//~vauaR~
            pdddata+=ddlen;                                        //~vauaR~
            pdddbcs+=ddlen;                                        //~vauaR~
            pddcode+=ddlen;                                        //~vauaR~
            ddlenu8+=ddlen;                                        //~vauaR~
        }                                                          //~vauaI~
    }                                                              //~va10I~
//*utf8 loop end                                                   //~vb2kI~
//  readlenf2l=(int)((ULONG)pc-(ULONG)Pdata);                      //~va10R~//~vafkR~
    readlenf2l=(int)((ULPTR)pc-(ULPTR)Pdata);                      //~vafkI~
//  outlenf2l=(int)((ULONG)pco-(ULONG)pwklc);                      //~va10R~//~vafkR~
    outlenf2l=(int)((ULPTR)pco-(ULPTR)pwklc);                      //~vafkI~
//  oututf8lenf2l=(int)((ULONG)pcou8-(ULONG)pwku8);                //~va10R~//~vafkR~
    oututf8lenf2l=(int)((ULPTR)pcou8-(ULPTR)pwku8);                //~vafkI~
  if (Popt & XEUTFGLSMO_ALLOWF2LOUTOVF)	//not f2lerr when output overflow//~vawBI~
    swerrf2l=(resleno>0) && (reslen>0) && !swdelm;                 //~vawBI~
  else                                                             //~vawBI~
    swerrf2l=(reslen>0)&&!swdelm;                                  //~va10R~
    UTRACEP("%s:try l2f swerrf2l=%d,swallascii=%d\n",UTT,swerrf2l,swallascii);//~vb2kR~
//try locale code *********************************************                                                  //~va10I~//~vavcR~
    pdddata=pwkdddatalc;                                           //~vauaI~
    pdddbcs=pwkdddbcslc;                                           //~vauaI~
    pddcode=pwkddcodelc;                                           //~vauaI~
	if (swallascii)                                                //~va10I~
        newcodetype=oldcodetype;   //select l2f                    //~va10M~
    else                                                           //~va10I~
    {                                                              //~va10I~
#ifdef W32UNICODE                                                  //~vavaI~
		UTRACEP("%s:try ascii pcud=%p\n",UTT,pcud);                //~vavGI~
  	  if (pcud)	//UD fmt                                           //~vavaI~
  	  {                                                            //~vavaI~
        swerrf2l=1;   //fl2 err                                    //~vavaI~
      	newcodetype=XEUTFCT_UTF8;                                  //~vavaI~
//      if (swudu8==UD_UTF8WCSUBC)                                 //~vavaR~//~vavcR~
//      	rc|=XEUTFGU8MRC_UTF8|XEUTFGU8MRC_UTF8SUBC;  //caller chk _UTF8 only now//~vavcR~
        	rc|=XEUTFGU8MRC_UTF8;  //caller chk _UTF8 only now     //~vavcI~
      }                                                            //~vavaI~
      else                                                         //~vavaI~
#endif                                                             //~vavaI~
      {//not UD fmt                                                //~vavaI~
        swdelm=0;                                                  //~va10R~
        rc2=0;                                                     //~va10R~
        for (pc=Pdata,pco=Poutbuff,pct=Pcodetypetbl,pcou8=Poututf8,reslen=Pdatalen,resleno=Poutbuffsz,reslenou8=Poututf8sz;//~va10R~
                !swdelm                                            //~va10R~
                && rc2<UTFCVRC_ERR                                 //~va10R~
                && reslen>0 && resleno>0;                          //~va10R~
                reslen-=chklen,resleno-=wrtlen,pc+=chklen,pco+=wrtlen)//~va10R~
        {                                                          //~va10R~
//          for (pc2=pc,reslen2=reslen;!swdelm;pc2++,reslen2--)    //~va19R~
            for (pc2=pc,reslen2=reslen;!swdelm && reslen2>0;pc2++,reslen2--)//~va19I~
            {                                                      //~va10R~
                if (!UTF8ISASCII(*pc2))                            //~va10R~
                    break;                                         //~va10R~
                ch=*pc2;                                           //~va10R~
              if (dirsepc)                                         //~va10R~
                swdelm=(ch==dirsepc);                              //~va10R~
              else                                                 //~va10R~
#ifdef W32                                                         //~va10R~
//*!ebc                                                            //~va50I~
                swdelm=(ch==' ')||ispunct(ch)||(ch=='\\');         //~va10R~
#else                                                              //~va10R~
                swdelm=(ch==' ')||ispunct(ch);                     //~va10R~
#endif                                                             //~va10R~
            }                                                      //~va10R~
            chklen=reslen-reslen2;                                 //~va10R~
            if (chklen)                                            //~va10R~
            {                                                      //~va10R~
                chklen=min(chklen,resleno);                        //~va10R~
                wrtlen=chklen;                                     //~va10R~
                memcpy(pco,pc,(UINT)wrtlen);                       //~va10R~
                if (Pcodetypetbl)                                  //~va10R~
                {                                                  //~va10R~
                    memset(pct,XEUTFCT_ASCII,(UINT)wrtlen); //input is valid utf8//~va10R~
                    pct+=wrtlen;                                   //~va10R~
                }                                                  //~va10R~
                if (Poututf8)                                      //~va10R~
                {                                                  //~va10R~
                    utf8len=min(chklen,reslenou8);                 //~va10R~
                    memcpy(pcou8,pc,(UINT)utf8len);                //~va10R~
                    pcou8+=utf8len;                                //~va10R~
                    reslenou8-=utf8len;                            //~va10R~
                }                                                  //~va10R~
                if (Pdddata)                                       //~vauaI~
                {                                                  //~vauaI~
                    memcpy(pdddata,pc,(UINT)chklen);               //~vauaI~
                    memset(pdddbcs,0,(UINT)wrtlen); //input is valid utf8//~vauaI~
                    memset(pddcode,XEUTFCT_ASCII,(UINT)wrtlen); //input is valid utf8//~vauaI~
                    pdddata+=chklen;                               //~vauaI~
                    pdddbcs+=wrtlen;                               //~vauaI~
                    pddcode+=wrtlen;                               //~vauaI~
            		ddlenlc+=wrtlen;                               //~vauaR~
                }                                                  //~vauaI~
                continue;                                          //~va10R~
            }                                                      //~va10R~
            swallascii=0;                                          //~va10R~
#ifdef LNX                                                         //~vb2kI~
    	  if (Popt & XEUTFGLSMO_ERRREPLC)                          //~vb2kI~
	        opt=UTFCVO_ERRREP|(XEUTF_ERRREPCH<<8)|UTFCVO_ASCIIRET; //~vb2kR~
          else                                                     //~vb2kI~
#endif                                                             //~vb2kI~
            opt=UTFCVO_ERRRET|UTFCVO_ASCIIRET;                     //~va10R~
#ifdef W32UNICODE                                                  //~vavGI~
    		if (Popt & XEUTFGLSMO_ALLOWSUBCH)                      //~vavGI~
	            opt|=UTFCVO_ALLOWSUBCH;                            //~vavGR~
#endif                                                             //~vavGI~
            if (!Poututf8)                                         //~va10R~
                pcou8=pwku8;                                       //~va10R~
            else                                                   //~vagsI~
            {                                                      //~vagsI~
            	opt|=UTFCVO_BUFFSZPARM;	//chk outbuffsz overflow   //~vagsI~
                utf8len=reslenou8;                                 //~vagsI~
            }                                                      //~vagsI~
//          rc2=utfcvl2f(opt,pcou8,pc,0/*init offs*/,reslen,0/*out choftbl*/,0/*out dbcstbl*/,&chklen,&utf8len,0/*pcharcnt*/,0/*char width*/);//locale coed validity chk//~va10R~//~vagtR~
            rc2=utfcvl2f(opt,pcou8,pc,0/*init offs*/,reslen,0/*out choftbl*/,pwkdbcs,&chklen,&utf8len,0/*pcharcnt*/,0/*char width*/);//locale coed validity chk//~vagtI~
            if (!swerrf2l)	//f2l ok	                           //~va3MI~
            {                                                      //~va3MI~
#ifdef W32UNICODE  //FIXME teston LNX:Win only:FIXED               //~vaw1I~//~vawrR~
			  if (!(Popt & XEUTFGLSMO_LCPRIMARY)) //apply LC for W32 local//~vavcI~
#endif                                                             //~vaw1I~
              {                                                    //~vavcI~
//  			if (xeutfdbcsnpchk(0,pc,pwkdbcs,reslen,0/*oklen*/))//~vauaR~
    			if (xeutfdbcsnpchk(0,pc,pwkdbcs,chklen,0/*oklen*/))//~vauaI~
                	break;	//select utf8                          //~va3MI~
              }//ignore unprintable for W32 local                  //~vaw1R~
            }                                                      //~va3MI~
            if (Pdddata)  //output by ddfmt                        //~vauaI~
            {                                                      //~vauaI~
                utfcvf2dd(0,pcou8,utf8len,pdddata,pdddbcs,ddbuffsz-PTRDIFF(pdddata,pwkdddatalc),&ddlen);//~vauaR~
                memset(pddcode,XEUTFCT_LC,(UINT)ddlen);  //input is valid utf8//~vauaR~
                pdddata+=ddlen;                                    //~vauaR~
                pdddbcs+=ddlen;                                    //~vauaR~
                pddcode+=ddlen;                                    //~vauaR~
            	ddlenlc+=ddlen;                                    //~vauaR~
            }                                                      //~vauaI~
            wrtlen=max(1,chklen);   //output 1 byte if chklen=0    //~va10R~
            wrtlen=min(resleno,wrtlen);                            //~va10R~
            memcpy(pco,pc,(UINT)wrtlen);    //copy input locale str//~va10R~
            if (Pcodetypetbl)                                      //~va10R~
            {                                                      //~va10R~
                memset(pct,XEUTFCT_LC,(UINT)wrtlen);    //input is locale//~va10R~
                pct+=wrtlen;                                       //~va10R~
            }                                                      //~va10R~
            if (Poututf8)                                          //~va10R~
            {                                                      //~va10R~
                if (Popt & XEUTFGLSMO_KEEPLC)      //output source locale code to Poututf8//~va10R~
                {                                                  //~va10R~
                    utf8len=max(1,chklen);                         //~va10R~
                    utf8len=min(reslenou8,utf8len);                //~va10R~
                    memcpy(pcou8,pc,(UINT)utf8len);  //output original locale code as mixed string//~va10R~
                }                                                  //~va10R~
                else                                               //~va10R~
                {                                                  //~va10R~
                    utf8len=min(reslenou8,utf8len);                //~va10R~
                }                                                  //~va10R~
                pcou8+=utf8len;                                    //~va10R~
                reslenou8-=utf8len;                                //~va10R~
            }                                                      //~va10R~
            chklen=max(1,chklen);                                  //~va10R~
        }                                                          //~va10R~
//      readlen=(int)((ULONG)pc-(ULONG)Pdata);                     //~va10R~//~vafkR~
        readlen=(int)((ULPTR)pc-(ULPTR)Pdata);                     //~vafkI~
//      outlen=(int)((ULONG)pco-(ULONG)Poutbuff);                  //~va10R~//~vafkR~
        outlen=(int)((ULPTR)pco-(ULPTR)Poutbuff);                  //~vafkI~
//      oututf8len=(int)((ULONG)pcou8-(ULONG)Poututf8);            //~va10R~//~vafkR~
        oututf8len=(int)((ULPTR)pcou8-(ULPTR)Poututf8);            //~vafkI~
      if (Popt & XEUTFGLSMO_ALLOWF2LOUTOVF)	//not f2lerr when output overflow//~vawBI~
        swerrl2f=(resleno>0) && (reslen>0) && !swdelm;             //~vawBI~
      else                                                         //~vawBI~
        swerrl2f=(reslen>0)&&!swdelm;                              //~va10R~
UTRACEP("utfgetnmixedword swallascii=%d,swdelm=%d,errf2l=%d,errl2f=%d\n",swallascii,swdelm,swerrf2l,swerrl2f);//~va10I~
//select utf8 or locale                                            //~va10I~
        if (swerrf2l)   //fl2 err                                  //~va10R~
            newcodetype=XEUTFCT_LC;   //select l2f                 //~va10R~
        else                                                       //~va10R~
        {                                                          //~va10R~
            if (swerrl2f)        //f2l ok,l2f ng                   //~va10R~
                newcodetype=XEUTFCT_UTF8;       //select f2l       //~va10R~
            else                 //both ok                         //~va10R~
            {                                                      //~va10R~
                if (oldcodetype==XEUTFCT_LC)                       //~va10R~
                    newcodetype=XEUTFCT_LC;                        //~va10R~
                else                                               //~va10R~
                if (oldcodetype==XEUTFCT_UTF8)                     //~va10R~
                    newcodetype=XEUTFCT_UTF8;                      //~va10R~
                else                                               //~va10R~
                    if (Gutfmode2 & GUM2_KBDUTF8)                  //~va10R~
                        newcodetype=XEUTFCT_UTF8;                  //~va10R~
                    else                                           //~va10R~
  					if (XEUTF8MODE_ENV_FORCE()) //env=utf8 required for =6 file//~vawrI~
                        newcodetype=XEUTFCT_UTF8;                  //~vawrI~
  					else                                           //~vawrI~
                        newcodetype=XEUTFCT_LC;                    //~va10R~
            }                                                      //~va10R~
        }                                                          //~va10R~
      }//not UD fmt                                                //~vavaI~
    }//!allascii                                                   //~va10M~
	if (swallascii                                                 //~va10I~
    ||  newcodetype==XEUTFCT_UTF8)   //determined UTF8 word        //~va10R~
    {                                                              //~va10R~
        readlen=readlenf2l;                                        //~va10R~
        outlen=outlenf2l;                                          //~va10R~
        outlen=min(outlen,Poutbuffsz);                             //~vaguI~
        memcpy(Poutbuff,pwklc,(UINT)outlen);                       //~va10R~
        if (Pcodetypetbl)                                          //~va10R~
        {                                                          //~va1qI~
          if (swallascii)                                          //~va1nI~
            memset(Pcodetypetbl,0,(UINT)outlen);                   //~va1nI~
          else                                                     //~va1nI~
#ifdef W32UNICODE                                                  //~vaw1I~
	      if (!(Popt & XEUTFGLSMO_SETINPATHALL))	//set XEUTFCT_UTF8 all char in the path//~vavsI~
            memcpy(Pcodetypetbl,pwkct,(UINT)outlen);               //~vavsI~
          else                                                     //~vavsI~
#endif                                                             //~vaw1I~
    	   if (Popt & XEUTFGLSMO_FILEPATH)                         //~vauaI~
           {                                                       //~vauaI~
           	if (swdelm)                                            //~vauaI~
            {                                                      //~vauaI~
                if (outlen)                                        //~vauaI~
                {                                                  //~vauaI~
            		memset(Pcodetypetbl,XEUTFCT_UTF8,(UINT)(outlen-1));//~vauaR~
            		*(Pcodetypetbl+outlen-1)=XEUTFCT_ASCII;        //~vauaI~
                }                                                  //~vauaI~
            }                                                      //~vauaI~
            else                                                   //~vauaI~
            	memset(Pcodetypetbl,XEUTFCT_UTF8,(UINT)outlen);    //~vauaI~
           }                                                       //~vauaI~
           else                                                    //~vauaI~
            memcpy(Pcodetypetbl,pwkct,(UINT)outlen);               //~va10R~
        }                                                          //~va1qI~
        if (Poututf8)                                              //~va10R~
        {                                                          //~va10R~
            oututf8len=oututf8lenf2l;                              //~va10R~
            memcpy(Poututf8,pwku8,(UINT)oututf8len);               //~va10R~
        }                                                          //~va10R~
      if (!swallascii)                                             //~va1nI~
    	if (newcodetype==XEUTFCT_UTF8)   //determined UTF8 word    //~va10I~
        	rc|=XEUTFGU8MRC_UTF8;                                  //~va10R~
    }                                                              //~va10R~
    else                                                           //~va10R~
        rc|=XEUTFGU8MRC_LC;                                        //~va10R~
    if (Pdddata)                                                   //~vauaI~
    {                                                              //~vauaI~
        if (swallascii                                             //~vauaI~
        ||  newcodetype==XEUTFCT_UTF8)   //determined UTF8 word    //~vauaI~
        {                                                          //~vauaI~
        	ddlen=min(Pddbuffsz,ddlenu8);                          //~vauaR~
//      	memcpy(Pdddata,pwkdddatau8,ddlen);                     //~vb01R~
        	memcpy(Pdddata,pwkdddatau8,(size_t)ddlen);             //~vb01I~
//      	memcpy(Pdddbcs,pwkdddbcsu8,ddlen);                     //~vb01R~
        	memcpy(Pdddbcs,pwkdddbcsu8,(size_t)ddlen);             //~vb01I~
    	  if (Popt & XEUTFGLSMO_FILEPATH                           //~vauaM~
          && !swallascii)   //determined UTF8 word                 //~vauaI~
          {                                                        //~vauaI~
          	if (swdelm)                                            //~vauaI~
            {                                                      //~vauaI~
            	if (ddlen)                                         //~vauaI~
                {                                                  //~vauaI~
//	        		memset(Pddcode,XEUTFCT_UTF8,ddlen-1);          //~vb01R~
  	        		memset(Pddcode,XEUTFCT_UTF8,(size_t)ddlen-1);  //~vb01I~
	        		*(Pddcode+ddlen-1)=XEUTFCT_ASCII;              //~vauaI~
                }                                                  //~vauaI~
            }                                                      //~vauaI~
            else                                                   //~vauaI~
//      		memset(Pddcode,XEUTFCT_UTF8,ddlen);                //~vb01R~
        		memset(Pddcode,XEUTFCT_UTF8,(size_t)ddlen);        //~vb01I~
#ifdef W32UNICODE                                                  //~vavsI~
			if (!(Popt & XEUTFGLSMO_SETINPATHALL))	//set XEUTFCT_UTF8 all char in the path//~vavsI~
            	ufilew_setctDD(0,XEUTFCT_UTF8,Pdddata,Pdddbcs,ddlen,Pddcode,ddlen);//~vavsR~
#endif                                                             //~vavsI~
          }                                                        //~vauaI~
          else                                                     //~vauaM~
//      	memcpy(Pddcode,pwkddcodeu8,ddlen);                     //~vb01R~
        	memcpy(Pddcode,pwkddcodeu8,(size_t)ddlen);             //~vb01I~
        }                                                          //~vauaI~
        else                                                       //~vauaI~
        {                                                          //~vauaI~
        	ddlen=min(Pddbuffsz,ddlenlc);                          //~vauaR~
//        	memcpy(Pdddata,pwkdddatalc,ddlen);                     //~vb01R~
          	memcpy(Pdddata,pwkdddatalc,(size_t)ddlen);             //~vb01I~
//      	memcpy(Pdddbcs,pwkdddbcslc,ddlen);                     //~vb01R~
        	memcpy(Pdddbcs,pwkdddbcslc,(size_t)ddlen);             //~vb01I~
//        	memcpy(Pddcode,pwkddcodelc,ddlen);                     //~vb01R~
          	memcpy(Pddcode,pwkddcodelc,(size_t)ddlen);             //~vb01I~
        }                                                          //~vauaI~
        *Ppddlen=ddlen;                                            //~vauaI~
		UTRACED("pdddata",Pdddata,ddlen);                          //~vauaI~
		UTRACED("pdddbcs",Pdddbcs,ddlen);                          //~vauaI~
		UTRACED("pddcode",Pddcode,ddlen);                          //~vauaI~
    }                                                              //~vauaI~
    *Ppcodetype=newcodetype;                                       //~va10I~
    if (!readlen)                                                  //~vavsI~
    {                                                              //~vavsI~
    	readlen=1;	//protext loop anyway                          //~vavsI~
    	UTRACEP("%s:ERROR readlen=0\n",UTT);                       //~vavsI~
    }                                                              //~vavsI~
    if (Ppchklen)                                                  //~va10I~
	    *Ppchklen=readlen;                                         //~va10I~
    if (Ppoutlen)                                                  //~va10I~
	    *Ppoutlen=outlen;                                          //~va10I~
    if (Ppoututf8len)                                              //~va10I~
	    *Ppoututf8len=oututf8len;                                  //~va10I~
    UTRACEP("utfgetmixedword rc=%d,newcodetype=%d\n",rc,newcodetype);//~va10R~
	UTRACED("utfgetmixedword pout",Poutbuff,outlen);               //~va10R~
    UTRACEDIFNZ("utfgetmixedword codetbl",Pcodetypetbl,outlen);    //~va10R~
    UTRACEDIFNZ("utfgetmixedword outouf8",Poututf8,oututf8len);    //~va10R~
    return rc;                                                     //~va10I~
}//xeutf_getmixedword                                              //~va10I~
#ifdef UTF8UCS2                                                    //~va20I~
//**************************************************************** //~va20I~
//!xeutfcvf2lc                                                     //~va20I~
//utf8->locale and codetype                                        //~va20I~
//**************************************************************** //~va20I~
int xeutfcvf2lc(int Popt,char *Pdata,int Pdatalen,char *Poutbuff,char *Pcodetypetbl,int Poutbuffsz,int *Ppoutlen,int *Ppchklen)//~va20R~
{                                                                  //~va20I~
	char *pco,*pc,*pc2,*pct;                                       //~va20I~
    int rc=0,reslen,resleno,wrtlen,chklen,rc2,opt,outlen,reslen2;  //~va20R~
//*****************************                                    //~va20I~
UTRACED("xeutfcvf2lc input",Pdata,Pdatalen);                       //~va20I~
    for (pc=Pdata,pco=Poutbuff,pct=Pcodetypetbl,reslen=Pdatalen,resleno=Poutbuffsz;//~va20R~
			reslen>0 && resleno>0;                                 //~va20I~
            reslen-=chklen,resleno-=wrtlen,pc+=chklen,pco+=wrtlen) //~va20I~
    {                                                              //~va20I~
    	for (pc2=pc,reslen2=reslen;reslen2>0;pc2++,reslen2--)      //~va20I~
        {                                                          //~va20I~
    		if (!UTF8ISASCII(*pc2))                                //~va20I~
            	break;                                             //~va20I~
        }                                                          //~va20I~
        chklen=reslen-reslen2;                                     //~va20I~
        if (chklen)                                                //~va20I~
        {                                                          //~va20I~
        	chklen=min(resleno,chklen);                            //~va20I~
        	wrtlen=chklen;                                         //~va20I~
            memcpy(pco,pc,(UINT)wrtlen);                           //~va20I~
	        if (Pcodetypetbl)                                      //~va20I~
        	{                                                      //~va20I~
    	    	memset(pct,XEUTFCT_ASCII,(UINT)wrtlen);	//input is valid utf8//~va20I~
            	pct+=wrtlen;                                       //~va20I~
        	}                                                      //~va20I~
            continue;                                              //~va20I~
        }                                                          //~va20I~
  	  	if (Popt & XEUTFF2LCO_ERRREP)//        0x10 //input is ascii and utf8 only//~va20R~
    		opt=(UTFCVO_ASCIIRET|UTFCVO_ERRREP)|(XEUTF_ERRREPCH_F2LFILE<<8);	//return if translation err//~va20I~
      	else                                                       //~va20I~
    		opt=UTFCVO_ASCIIRET|UTFCVO_ERRRET;	//return if translation err//~va20I~
        rc|=XEUTFF2LCRC_UTF8;                                      //~va20I~
    	rc2=utfcvf2l(opt,pco,pc,reslen,&chklen,&wrtlen,0/*Ppcharwidth*/);//~va20I~
UTRACEP("xeutfcvf2lc utfcvf2l rc=%d,datalen=%d,chklen=%d,wrtlen=%d\n",rc2,reslen,chklen,wrtlen);//~va20R~
//  	if (rc2>=UTFCVRC_ERR)                                      //~va20I~//~vavER~
    	if (rc2>=UTFCVRC_ERRSTOP)                                  //~vavER~
        {                                                          //~va20I~
        	rc|=XEUTFF2LCRC_UTF8ERR;                               //~va20I~
//    	  	if (!(Popt & XEUTFF2LCO_ERRREP))// UTFCVRC_ERRSTOP>UTFCVRC_ERR when ERRREP off//~vavER~
        		break;                                             //~va20I~
        }                                                          //~va20I~
        if (Pcodetypetbl)                                          //~va20I~
        {                                                          //~va20I~
        	memset(pct,XEUTFCT_UTF8,(UINT)wrtlen);	//input is valid utf8//~va20I~
            pct+=wrtlen;                                           //~va20I~
        }                                                          //~va20I~
    }                                                              //~va20I~
    if (reslen>0 && resleno<=0)                                    //~va20I~
        rc|=XEUTFF2LCRC_OVF;                                       //~va20I~
//  chklen=(int)((ULONG)pc-(ULONG)Pdata);                          //~va20R~//~vafkR~
    chklen=(int)((ULPTR)pc-(ULPTR)Pdata);                          //~vafkI~
//  outlen=(int)((ULONG)pco-(ULONG)Poutbuff);                      //~va20I~//~vafkR~
    outlen=(int)((ULPTR)pco-(ULPTR)Poutbuff);                      //~vafkI~
    if (Ppchklen)                                                  //~va20I~
	    *Ppchklen=chklen;                                          //~va20R~
    if (Ppoutlen)                                                  //~va20I~
	    *Ppoutlen=outlen;                                          //~va20I~
    if (outlen<Poutbuffsz)                                         //~vawjI~
        *(Poutbuff+outlen)=0;//for debug purpose                   //~vawjI~
    UTRACEP("utfcvf2lc rc=%d\n",rc);                               //~va20I~
	UTRACED("utfcvf2lc lc",Poutbuff,outlen);                       //~va20I~
	UTRACEDIFNZ("utfcvf2lc ct",Pcodetypetbl,outlen);               //~va20R~
    return rc;                                                     //~va20I~
}//xeutfcvf2lc                                                     //~va20I~
//#ifdef LNX                                                         //~vauaI~//~vavaR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaI~
//**************************************************************** //~vau5I~
//!xeutfcvf2lDDW                                                   //~vau5I~
//all utf8 is already confirmed                                    //~vauaI~
//utf8->locale checking DDfmt char width                           //~vau5I~
//rc:1:errrep                                                      //~vauaI~
//**************************************************************** //~vau5I~
int xeutfcvf2lDDW(int Popt,char *Pdata,int Pdatalen,char *Poutbuff,int Poutbuffsz,int *Ppoutlen)//~vauaR~
{                                                                  //~vau5I~
	char *pco,*pc/*,*pct*/;                                            //~vau5I~//~vavaR~
    int rc=0,reslen,resleno,chklen,wrtlen,opt,outlen,chklen2,wrtlen2,u8len;//~vavjR~
    int swerr,rc2;                                                 //~vau5I~
    char wkdd[4],wkdddbcs[4];                                      //~vau5I~
//*****************************                                    //~vau5I~
UTRACED("xeutfcvf2lDDW input",Pdata,Pdatalen);                     //~vau5R~
	opt=UTFCVO_ERRREP|(XEUTFDD2LC_REPERR<<8); //"?"                //~vavjI~
    for (pc=Pdata,pco=Poutbuff,reslen=Pdatalen,resleno=Poutbuffsz; //~vauaR~
			reslen>0 && resleno>0;                                 //~vau5I~
            reslen-=chklen,resleno-=wrtlen,pc+=chklen,pco+=wrtlen/*,pct+=wrtlen*/)//~vau5I~//~vavaR~
    {                                                              //~vau5I~
        u8len=UTF8CHARLEN(*pc);                                    //~vau5R~
        swerr=0;                                                   //~vau5I~
        utfcvf2dd(opt,pc,u8len,wkdd,wkdddbcs,sizeof(wkdd),&wrtlen);//~vauaI~
    	rc2=utfcvf2l(opt,pco,pc,u8len,&chklen2,&wrtlen2,0/*Ppcharwidth*/);//~vauaR~
//      if (rc2||chklen2!=u8len||wrtlen2!=wrtlen)                  //~vauaR~//~vbkaR~
        if (rc2||chklen2!=u8len)                                   //~vbkaI~
        	swerr=1;                                               //~vauaR~
        chklen=u8len;                                              //~vau5I~
        if (swerr)                                                 //~vau5I~
        {                                                          //~vauaI~
//            *pco=XEUTFDD2LC_REPERR; //"."                        //~vavjR~
//            if (wrtlen>1)                                        //~vavjR~
//                *(pco+1)=XEUTFDD2LC_REPERR; //"."                //~vavjR~
            rc=1;                                                  //~vauaI~
        }                                                          //~vau5I~
        wrtlen=wrtlen2;    //lclen                                 //~vbkaI~
    }                                                              //~vau5I~
    outlen=(int)((ULPTR)pco-(ULPTR)Poutbuff);                      //~vau5I~
    if (Ppoutlen)                                                  //~vau5I~
	    *Ppoutlen=outlen;                                          //~vau5I~
    UTRACEP("utfcvflDDW rc=%d\n",rc);                              //~vau5I~
	UTRACED("utfcvflDDW lc",Poutbuff,outlen);                      //~vau5I~
    return rc;                                                     //~vau5I~
}//xeutfcvf2lDDW                                                   //~vau5I~
#endif //LNX                                                       //~vauaI~
#ifdef W32UNICODE                                                  //~vavsI~
//**************************************************************** //~vavsI~
//!xeutfcvf2lDDW                                                   //~vavsI~
//all utf8 is already confirmed                                    //~vavsI~
//utf8->locale checking DDfmt char width                           //~vavsI~
//rc:1:errrep                                                      //~vavsI~
//**************************************************************** //~vavsI~
int xeutfcvf2lDDWct(int Popt,char *Pdata,int Pdatalen,char *Poutbuff,int Poutbuffsz,int *Ppoutlen,char *Poutct)//~vavsI~
{                                                                  //~vavsI~
	char *pco,*pc,*pct;                                            //~vavsI~
    int rc=0,reslen,resleno,chklen,wrtlen,opt,outlen,chklen2,wrtlen2,u8len;//~vavsI~
    int swerr,rc2;                                                 //~vavsI~
    char wkdd[4],wkdddbcs[4];                                      //~vavsI~
//*****************************                                    //~vavsI~
UTRACED("input",Pdata,Pdatalen);                                   //~vavsI~
	opt=UTFCVO_ERRREP|(XEUTFDD2LC_REPERR<<8); //"?"                //~vavsI~
    for (pc=Pdata,pco=Poutbuff,reslen=Pdatalen,resleno=Poutbuffsz,pct=Poutct;//~vavsR~
			reslen>0 && resleno>0;                                 //~vavsI~
            reslen-=chklen,resleno-=wrtlen,pc+=chklen,pco+=wrtlen,pct+=wrtlen)//~vavsI~
    {                                                              //~vavsI~
        u8len=UTF8CHARLEN(*pc);                                    //~vavsI~
        swerr=0;                                                   //~vavsI~
        utfcvf2dd(opt,pc,u8len,wkdd,wkdddbcs,sizeof(wkdd),&wrtlen);//~vavsI~
    	rc2=utfcvf2l(opt,pco,pc,u8len,&chklen2,&wrtlen2,0/*Ppcharwidth*/);//~vavsI~
//      if (rc2||chklen2!=u8len||wrtlen2!=wrtlen)                  //~vavsI~//~vbkaR~
        if (rc2||chklen2!=u8len)                                   //~vbiaI~
        	swerr=1;                                               //~vavsI~
        chklen=u8len;                                              //~vavsI~
        if (swerr)                                                 //~vavsI~
        {                                                          //~vavsI~
            rc=1;                                                  //~vavsI~
        }                                                          //~vavsI~
        if (u8len>1)	//utf8                                     //~vavsI~
        {                                                          //~vavsI~
        	*pct=XEUTFCT_UTF8;                                     //~vavsI~
//          if (wrtlen>1)                                          //~vavsI~//~vbkaR~
            if (wrtlen2>1)                                         //~vbiaI~
	        	*(pct+1)=XEUTFCT_UTF8;                             //~vavsI~
        }                                                          //~vavsI~
        else                                                       //~vavsI~
        	*pct=0;                                                //~vavsI~
        wrtlen=wrtlen2;                                            //~vbkaR~
    }                                                              //~vavsI~
    outlen=(int)((ULPTR)pco-(ULPTR)Poutbuff);                      //~vavsI~
    if (Ppoutlen)                                                  //~vavsI~
	    *Ppoutlen=outlen;                                          //~vavsI~
    UTRACEP("%s:rc=%d\n",UTT,rc);                                  //~vavsI~
	UTRACED("lc",Poutbuff,outlen);                                 //~vavsI~
	UTRACED("lcct",Poutct,outlen);                                 //~vavsR~
    return rc;                                                     //~vavsI~
}//xeutfcvf2lDDWct                                                 //~vavsI~
#endif //W32UNICODE                                                //~vaw1R~
//#ifdef LNX                                                         //~vau7I~//~vauER~
//**************************************************************** //~vau7R~
//!xeutfcvlf2ddAdjust                                              //~vau7R~
//Adjust ct created by f2l(mistranslate Germany to Japanese:katakana(3byte UTF8 on ct))//~vau7R~
//*rc:0 1:already adjusted,2:already adjust and valid reperr       //~vaumR~
//**************************************************************** //~vau7R~
//int xeutfcvlf2ddAdjust(int Popt,char *Ppu8,int Pu8len,char *Pct,int Plclen,//~vaumR~
int xeutfcvlf2ddAdjust(int Popt,char *Ppu8,int Pu8len,char *Plc,char *Pct,int Plclen,//~vaumI~
					char *Pdddata,char *Pdddbcs,char *Pddct,int Pbuffsz,int *Ppddlen)//~vau7R~
{                                                                  //~vau7R~
	char *pco,*pc,*pct,*pcto,*pcdo;                                //~vau7R~
    char *plc;                                                     //~vaumI~
	UCHAR *pl2dddata,*pl2dddbcs;                                   //~vau7I~
    int rc=0,reslen,resleno,chklen=0,wrtlen=0,opt,outlen,chklenct=0,readlen,lclen,ddlen;//~vau7R~//~vauER~
    char wkdd[4],wkdddbcs[4],wklc[8];                              //~vau7R~
    int swerr=0;    //loop protection                              //~vau7I~
//*****************************                                    //~vau7R~
	UTRACED("xeutfcvlf2ddAdjust input data",Ppu8,Pu8len);          //~vau7R~
	UTRACED("xeutfcvlf2ddAdjust input ct",Pct,Plclen);             //~vau7I~
//  for (pc=Ppu8,pct=Pct,pco=Pdddata,pcdo=Pdddbcs,pcto=Pddct,reslen=Pu8len,resleno=Pbuffsz;//~vaumR~
    for (pc=Ppu8,plc=Plc,pct=Pct,pco=Pdddata,pcdo=Pdddbcs,pcto=Pddct,reslen=Pu8len,resleno=Pbuffsz;//~vaumR~
			reslen>0 && resleno>0;                                 //~vau7R~
//          reslen-=chklen,resleno-=wrtlen,pc+=chklen,pct+=chklenct,pco+=wrtlen,pcdo+=wrtlen,pcto+=wrtlen)//~vaumR~
//#ifdef W32UNICODE     //@@@@test                                 //~vawrR~
////FIXME test on lnx   :FIXED                                     //~vavsR~//~vawrR~
//          reslen-=chklen,resleno-=wrtlen,pc+=chklen,plc+=chklenct,pct+=chklen,pco+=wrtlen,pcdo+=wrtlen,pcto+=wrtlen)//~vavsR~//~vawrR~
//#else                                                            //~vavsR~
            reslen-=chklen,resleno-=wrtlen,pc+=chklen,plc+=chklenct,pct+=chklenct,pco+=wrtlen,pcdo+=wrtlen,pcto+=wrtlen)//~vaumI~//~vavsR~
//#endif                                                           //~vavsR~
    {                                                              //~vau7R~
    	switch(*pct)                                               //~vau7R~
        {                                                          //~vau7R~
        case XEUTFCT_ASCII:	//ascii                                //~vau7R~
    		if (!UTF8ISASCII(*pc))                                 //~vau7I~
            {                                                      //~vau7I~
            	swerr=1;	//already ct adjusted                  //~vau7I~
                break;                                             //~vau7I~
            }                                                      //~vau7I~
        	chklen=1;                                              //~vau7R~
        	chklenct=1;                                            //~vau7R~
            wrtlen=1;                                              //~vau7R~
            *pco=*pc;                                              //~vau7R~
            *pcdo=0;                                               //~vau7R~
            *pcto=0;                                               //~vau7R~‚¨‚†
            break;                                                 //~vau7R~
        case XEUTFCT_UTF8:	//                                     //~vau7R~
	        chklen=UTF8CHARLEN(*pc);                               //~vau7R~
    		if (chklen<=1)	//ascii or dbcs                        //~vau7I~
            {                                                      //~vau7I~
            	swerr=1;	//already adjusted                     //~vau7I~
                break;                                             //~vau7I~
            }                                                      //~vau7I~
            opt=0;                                                 //~vau7R~
            utfcvf2dd(opt,pc,chklen,wkdd,wkdddbcs,sizeof(wkdd),&ddlen);//~vau7R~
		  if (Popt & XEUTFCVLF2DAO_CHKERRREP && *plc==XEUTFDD2LC_REPERR) //"."//~vaumI~
          {                                                        //~vaumI~
          	lclen=1;                                               //~vaumI~
            if (ddlen>1)                                           //~vaumI~
            {                                                      //~vaumI~
//#ifdef W32UNICODE                                                //~vaw1R~
//                if (ddlen==4)   //surrogate pair                 //~vaw1R~
//                    lclen=4;                                     //~vaw1R~
//                else                                             //~vaw1R~
//#endif                                                           //~vaw1R~
            	if (*(plc+1)==XEUTFDD2LC_REPERR && *(pct+1)==XEUTFCT_UTF8) //ucs dbcs//~vaumI~
            		lclen=2;                                       //~vaumI~
//*utfcvf2dd translate u-10a01(ddlen=2,mk_width=0)  to 1 byte "?"; it is not err//~vbkaI~
//              else                                               //~vaumI~//~vbkaR~
//              {                                                  //~vaumI~//~vbkaR~
//          		swerr=1;	//already adjusted                 //~vaumI~//~vbkaR~
//              	break;                                         //~vaumI~//~vbkaR~
//              }                                                  //~vaumI~//~vbkaR~
            }                                                      //~vaumI~
            rc=2;                                                  //~vaumI~
          }                                                        //~vaumI~
          else                                                     //~vaumI~
          {                                                        //~vaumI~
	    	opt=UTFCVO_ERRREP|(XEUTF_ERRREPCH_F2LFILE<<8);         //~vau7R~
            utfcvf2l(opt,wklc,pc,chklen,&readlen,&lclen,0/*Ppcharwidth*/);//~vau7R~
          }                                                        //~vaumI~
            chklenct=lclen;                                        //~vaumR~
            wrtlen=ddlen;                                          //~vau7R~
	        *pco=wkdd[0];                                          //~vau7R~
    	    *pcdo=wkdddbcs[0];                                     //~vau7R~
        	*pcto=XEUTFCT_UTF8;                                    //~vau7R~
            if (wrtlen>1)                                          //~vau7R~
            {                                                      //~vau7R~
		        *(pco+1)=wkdd[1];                                  //~vau7R~
    		    *(pcdo+1)=wkdddbcs[1];                             //~vau7R~
        		*(pcto+1)=XEUTFCT_UTF8;                            //~vau7R~
//#ifdef W32UNICODE                                                //~vaw1R~
//                if (wrtlen==4)  //surrogate pair                 //~vaw1R~
//                {                                                //~vaw1R~
//                    *(pco+2)=wkdd[2];                            //~vaw1R~
//                    *(pcdo+2)=wkdddbcs[2];                       //~vaw1R~
//                    *(pcto+2)=XEUTFCT_UTF8;                      //~vaw1R~
//                    *(pco+3)=wkdd[3];                            //~vaw1R~
//                    *(pcdo+3)=wkdddbcs[3];                       //~vaw1R~
//                    *(pcto+3)=XEUTFCT_UTF8;                      //~vaw1R~
//                }                                                //~vaw1R~
//#endif                                                           //~vaw1R~
            }                                                      //~vau7R~
            break;                                                 //~vau7R~
        default:			//loxcalecode                          //~vau7R~
//      	lclen=umemspnc(pct,XEUTFCT_LC,reslen);                 //~vb01R~
//      	lclen=(int)umemspnc(pct,XEUTFCT_LC,(size_t)reslen);    //~vb01I~//~vb2ER~
        	lclen=(int)umemspnc(pct,XEUTFCT_LC,(UINT)reslen);      //~vb2EI~
    		if (!lclen)	//ascii or dbcs                            //~vau7R~
            {                                                      //~vau7I~
            	swerr=1;	//already adjusted                     //~vau7I~
                break;                                             //~vau7I~
            }                                                      //~vau7I~
            chklen=lclen;                                          //~vau7R~
            chklenct=lclen;                                        //~vau7R~
            opt=0;                                                 //~vau7R~
            if (XEUTFGLSMO_ERRMSG) //      0x04 //source is for errmsg display//~vb4cR~
            	opt|=XEUTFCVL2DDO_ERRREP; //      0x01  //rep by '.' if l2f err//~vb4cR~
			xeutfcvl2dd(opt,pc,lclen,&pl2dddata,&pl2dddbcs,&ddlen);//~vau7R~
            wrtlen=min(ddlen,resleno);                             //~vau7R~
//          memcpy(pco,pl2dddata,ddlen);                           //~vau7R~//~vb01R~
//          memcpy(pcdo,pl2dddbcs,ddlen);                          //~vau7R~//~vb01R~
//          memset(pcto,XEUTFCT_LC,ddlen);                         //~vau7I~//~vb01R~
//          memcpy(pco,pl2dddata,wrtlen);                          //~vb01R~
            memcpy(pco,pl2dddata,(size_t)wrtlen);                  //~vb01I~
//          memcpy(pcdo,pl2dddbcs,wrtlen);                         //~vb01R~
            memcpy(pcdo,pl2dddbcs,(size_t)wrtlen);                 //~vb01I~
//          memset(pcto,XEUTFCT_LC,wrtlen);                        //~vb01R~
            memset(pcto,XEUTFCT_LC,(size_t)wrtlen);                //~vb01I~
        }                                                          //~vau7R~
        if (swerr)                                                 //~vau9I~
            break;                                                 //~vau9I~
    }                                                              //~vau7R~
    if (swerr)                                                     //~vau7I~
    {                                                              //~vau7I~
    	rc=1;	//already adjusted                                 //~vau7I~
    }                                                              //~vau7I~
    outlen=(int)((ULPTR)pco-(ULPTR)Pdddata);                       //~vau7R~
	*Ppddlen=outlen;                                               //~vau7R~
    UTRACEP("utfcvlf2ddAdjust rc=%d\n",rc);                        //~vau7R~
	UTRACED("utfcvlf2ddAdjust dddata",Pdddata,outlen);             //~vau7R~
	UTRACED("utfcvlf2ddAdjust ddbcs",Pdddbcs,outlen);              //~vau7R~
	UTRACEDIFNZ("utfcvlf2ddAdjus ct",Pddct,outlen);                //~vau7R~
    return rc;                                                     //~vau7R~
}//xeutfcvlf2ddAdjust                                              //~vau7R~
//#endif  //LNX                                                      //~vaumR~//~vauER~
//**************************************************************** //~vau5I~
//!xeutfcvdd2lc                                                    //~vau5I~
//utf8->locale and codetype using dddbcs to avoid dd->u8->locale conversion err aroud char width for other language//~vau6R~
//**************************************************************** //~vau5I~
int xeutfcvdd2lc(int Popt,char *Pdata,int Pdatalen,char *Pdbcs,char *Poutbuff,char *Pcodetypetbl,int Poutbuffsz,int *Ppoutlen)//~vau5I~
{                                                                  //~vau5I~
	char *pco,*pc,*pct,*pcd;                                       //~vau5I~
    int rc=0,reslen,resleno,chklen,opt=0,outlen,mblen,swerr;       //~vau5R~
    char mbwk[8];                                                  //~v61gR~//~vau5I~
    ULONG ucs;                                                     //~vau5I~
//*****************************                                    //~vau5I~
UTRACED("xeutfcvdd2lc input",Pdata,Pdatalen);                      //~vau5I~
    for (pc=Pdata,pcd=Pdbcs,pco=Poutbuff,pct=Pcodetypetbl,reslen=Pdatalen,resleno=Poutbuffsz;//~vau5R~
			reslen>0 && resleno>0;                                 //~vau5I~
            reslen-=chklen,resleno-=chklen,pc+=chklen,pcd+=chklen,pco+=chklen,pct+=chklen)//~vau5I~
    {                                                              //~vau5I~
        if (!*pcd)                                                 //~vau5I~
        {                                                          //~vau5I~
        	chklen=1;                                              //~vau5I~
            *pco=*pc;                                              //~vau5I~
            *pct=0;                                                //~vau5I~
            continue;                                              //~vau5I~
        }                                                          //~vau5I~
//      ucs=utfdd2u1chsz(opt,pc,pcd,reslen,&chklen);               //~vb01R~
        ucs=(ULONG)utfdd2u1chsz(opt,pc,pcd,reslen,&chklen);        //~vb01I~
        swerr=0;                                                   //~vau5I~
        if (chklen<0)                                              //~vau5I~
        {                                                          //~vau5I~
        	chklen=-chklen;                                        //~vau5I~
            swerr=1;                                               //~vau5I~
        }                                                          //~vau5I~
        *pct=XEUTFCT_UTF8;                                         //~vau5I~
        if (!swerr)                                                //~vau5I~
        {                                                          //~vau5I~
//  		if (utfcvu2lany1mb(0,ucs,mbwk,&mblen))                 //~vaz8R~
//  		if (utfcvu2lany1mb(0,(UWCHART)ucs,mbwk,&mblen))        //~vaz8I~//~vb2HR~
    		if (utfcvu2lany1mb(0,(UWUCS)ucs,mbwk,&mblen))          //~vb2HI~
            	swerr=1;                                           //~vau5I~
            else                                                   //~vau5I~
            if (mblen!=chklen)                                     //~vau5I~
            	swerr=1;                                           //~vau5I~
        }                                                          //~vau5I~
        if (swerr)                                                 //~vau5I~
        {                                                          //~vau5I~
        	*pco=XEUTFDD2LC_REPERR; //"."                          //~vau7R~
            rc|=XEUTFDD2LCRC_UTF8ERR;   //1                        //~vau5R~
        }                                                          //~vau5I~
        else                                                       //~vau5I~
        	*pco=*mbwk;                                            //~vau5R~
        if (chklen==2)                                             //~vau5I~
        {                                                          //~vau5I~
            *(pct+1)=XEUTFCT_UTF8;                                 //~vau5I~
        	if (swerr)                                             //~vau5I~
//          	*(pco+1)=XEUTFDD2LC_REPERR;                        //~vau7R~//~vawxR~
				utf_setsubchar_dbcs(0,pco);	//set dbcs errrep if avail//~vawxI~
            else                                                   //~vau5I~
            	*(pco+1)=*(mbwk+1);                                //~vau5R~
        }                                                          //~vau5I~
    }                                                              //~vau5I~
    outlen=(int)((ULPTR)pco-(ULPTR)Poutbuff);                      //~vau5I~
    if (Ppoutlen)                                                  //~vau5I~
	    *Ppoutlen=outlen;                                          //~vau5I~
    UTRACEP("utfcvdd2lc rc=%d\n",rc);                              //~vau5I~
	UTRACED("utfcvdd2lc lc",Poutbuff,outlen);                      //~vau5I~
	UTRACEDIFNZ("utfcvdd2lc ct",Pcodetypetbl,outlen);              //~vau5I~
    return rc;                                                     //~vau5I~
}//xeutfcvdd2lc                                                    //~vau5I~
#endif                                                             //~va20I~
//**************************************************************** //~va00I~
//!xeutf_getmixedstr                                               //~va00R~
//get locale string from locale and utf8 mixed string for errormsg //~va00I~
//pdbcs:optional output                                            //~va00I~
//*try utf8 at first                                               //~va0HI~
//ret:0:all ascii,0x01:contains utf8 str(cv to locale),0x02 contains locale str//~va00I~
//     UALLOC_FAILED                                               //~va10I~
//**************************************************************** //~va00I~
int xeutf_getmixedstr(int Popt,char *Pstr,int Pdatalen,char *Poutbuff,char *Pdbcs,char *Pcodetype,int Poutbuffsz,int *Ppoutlen,//~va00R~
                        char *Poututf8,int Poututf8sz,int *Ppoututf8len)//~va00I~
{                                                                  //~va00I~
//  char *pco,*pc,*pcn,utf8wk[_MAX_PATH+_MAX_PATH];                //~va1cR~
//  char *pco,*pc,*pcn,utf8wk[_MAX_PATH*UTF8_F2LMAXRATE];          //~va1cR~//~vav9R~
    char *pco,*pc,*pcn,utf8wk[_MAX_PATHF2L];                       //~vav9I~
    char *pcou8,*pcou8e;                                           //~va00R~
    int rc=0,len,reslen,resleno,wrtlen,chklen;                     //~va00R~
//  int codetype,opt,utf8len,outlen,oututf8len=0;                  //~va00R~//~vafcR~
    int codetype=XEUTFCT_ASCII,opt,utf8len,outlen,oututf8len=0;    //~vafcI~
    int swiflong;                                                  //~va0HI~
    int oldcodetype,reslenou8;                                     //~va10R~//~vafcR~
    int rc2;                                                       //~va10I~
//#ifdef LNX                                                       //~vau7R~
//    char *pcdo;                                                  //~vau7R~
//#endif                                                           //~vau7R~
#ifdef W32UNICODE                                                  //~vavER~
	int udlen;                                                     //~vavEI~
	int beforeudlen;                                               //~vaw1I~
#endif                                                             //~vavEI~
//*****************************                                    //~va00R~
UTRACEP("%s:entry opt=%x\n",UTT,Popt);                             //~vb2kR~
UTRACED("xeutf_getmixedstr data",Pstr,Pdatalen);                   //~vb2kI~
//#ifdef LNX                                                       //~vau7R~
//    if (Popt & XEUTFGLSMO_DDFMT)                                 //~vau7R~
//    {                                                            //~vau7R~
//        Poututf8=NULL;  //output dbcs                            //~vau7R~
//        Ppoututf8len=NULL;                                       //~vau7R~
//    }                                                            //~vau7R~
//#endif                                                           //~vau7R~
    if (UDBCSCHK_ISDBCSJ()   //Japanese(SJIS,EUCJ,EUCJ-UTF8)       //~va0wR~
    ||  UDBCSCHK_ISWCDBCS()   //otther DBCS(+UTF8)                 //~va0wI~
    )                                                              //~va0wI~
    	swiflong=1;    //assume locale if longer than utf8 code    //~va0wR~
    else                                                           //~va0wR~
        swiflong=0;                                                //~va0wI~
  	if (!(len=Pdatalen))                                           //~va00I~
//  	len=strlen(Pstr);                                          //~vb01R~
    	len=(int)strlen(Pstr);                                     //~vb01I~
    resleno=Poutbuffsz;                                            //~va00I~
    pcou8=Poututf8;                                                //~va00I~
    pcou8e=pcou8+Poututf8sz;                                       //~va00I~
    if (Popt & XEUTFGLSMO_STRZ)                                    //~va00I~
    {                                                              //~va00I~
    	resleno--;                                                 //~va00I~
        pcou8e--;                                                  //~va00R~
    }                                                              //~va00I~
  if (Popt & XEUTFGLSMO_UTF8)                                      //~vauDI~
	oldcodetype=XEUTFCT_UTF8;                                      //~vauDI~
  else                                                             //~vauDI~
  if (Popt & XEUTFMSUO_LC)                                         //~vauDI~
	oldcodetype=XEUTFCT_LC;                                        //~vauDI~
  else                                                             //~vauDI~
    oldcodetype=XEUTFCT_ASCII;                                     //~va10I~
//#ifdef LNX                                                       //~vau7R~
//    pcdo=Pdbcs;                                                  //~vau7R~
//#endif                                                           //~vau7R~
    for (pc=Pstr,pco=Poutbuff,pcn=Pcodetype,reslen=len;            //~va00R~
			reslen>0 && resleno>0;                                 //~va00I~
            reslen-=chklen,resleno-=wrtlen,pc+=chklen,pco+=wrtlen) //~va00I~
    {                                                              //~va00I~
#ifdef W32UNICODE                                                  //~vavER~
		udlen=0;                                                   //~vavEI~
		beforeudlen=0;                                             //~vaw1I~
        if (*pc==UD_NOTLC && reslen>3)                             //~vavEI~
        {                                                          //~vavEI~
        	char *pc2;                                             //~vavEI~
            USUBSTRLEN(pc+1,UD_NOTLC,reslen-1,&pc2,&udlen);        //~vavEI~
            if (!pc2)   //fmt err                                  //~vavEI~
            	udlen=0;                                           //~vavEI~
        }                                                          //~vavEI~
        else                                                       //~vaw1I~
        {                                                          //~vaw1I~
        	char *pc2;                                             //~vaw1I~
            USUBSTRLEN(pc,UD_NOTLC,reslen,&pc2,&beforeudlen);      //~vaw1I~
        }                                                          //~vaw1I~
      if (!udlen)                                                  //~vavEI~
#endif                                                             //~vavEI~
    	if (*pc<0x80)                                              //~va00I~
        {                                                          //~va00I~
        	if (Pcodetype)                                         //~va00I~
        	    *pcn++=XEUTFCT_ASCII;		//ascii id             //~va00R~
        	*pco=*pc;                                              //~va00R~
            chklen=1;                                              //~va00I~
            wrtlen=1;                                              //~va00I~
//#ifdef LNX                                                       //~vau7R~
//            if (Popt & XEUTFGLSMO_DDFMT)                         //~vau7R~
//                *pcdo++=0;                                       //~vau7R~
//#endif                                                           //~vau7R~
            if (Poututf8)                                          //~va00R~
            {                                                      //~va00I~
                if (pcou8>=pcou8e)                                 //~va00I~
                    break;                                         //~va00I~
                *pcou8++=*pc;                                      //~va00I~
            }                                                      //~va00I~
            continue;                                              //~va00I~
        }                                                          //~va00I~
      if (Gutfmode2 & GUM2_MIXEDWORDMODE)                          //~va10I~
      {                                                            //~va10I~
//    	reslenou8=(int)((ULONG)pcou8e-(ULONG)pcou8);               //~va10R~//~vafkR~
      	reslenou8=(int)((ULPTR)pcou8e-(ULPTR)pcou8);               //~vafkI~
        opt=Popt;                                                  //~va10I~
#ifdef W32UNICODE                                                  //~vavER~
		if (udlen)                                                 //~vavEI~
	        opt|=XEUTFGLSMO_MIXEDUDSTR; //0x0200	//from getmisexstring to getmixedword,regardless seperator of dirsepc//~vavEI~
#endif                                                             //~vavEI~
        codetype=oldcodetype;	//mode continues                   //~va10I~
//#ifdef LNX                                                       //~vau7R~
//      if (Popt & XEUTFGLSMO_DDFMT)                               //~vau7R~
//      {                                                          //~vau7R~
//        rc2=xeutf_getmixedwordDDFMT(opt,&codetype,pc,reslen,pco,resleno,pcdo,pcn,&chklen,&wrtlen);//~vau7R~
//        pcdo+=wrtlen;                                            //~vau7R~
//      }                                                          //~vau7R~
//      else                                                       //~vau7R~
//#endif                                                           //~vau7R~
//  	rc2=xeutf_getmixedword(opt,&codetype,pc,reslen,pco,resleno,pcou8,reslenou8,pcn,&chklen,&wrtlen,&utf8len);//~vauaR~
#ifdef W32UNICODE                                                  //~vaw1I~
	  if (beforeudlen)                                             //~vaw1I~
    	rc2=xeutf_getmixedword(opt,&codetype,pc,beforeudlen,pco,resleno,pcou8,reslenou8,pcn,&chklen,&wrtlen,&utf8len,NULL/*dddata*/,NULL/*dddbcs*/,NULL/*ddcode*/,0/*ddbuffsz*/,NULL/*Ppddlen*/);//~vaw1I~
      else                                                         //~vaw1I~
#endif                                                             //~vaw1R~
    	rc2=xeutf_getmixedword(opt,&codetype,pc,reslen,pco,resleno,pcou8,reslenou8,pcn,&chklen,&wrtlen,&utf8len,NULL/*dddata*/,NULL/*dddbcs*/,NULL/*ddcode*/,0/*ddbuffsz*/,NULL/*Ppddlen*/);//~vauaR~
        if (rc2==UALLOC_FAILED)                                    //~va10I~
        	return rc2;                                            //~va10I~
//#ifdef W32UNICODE                                                  //~vavaI~//~vavcR~
//        rc|=rc2 & (XEUTFGU8MRC_UTF8|XEUTFGU8MRC_LC|XEUTFGU8MRC_UTF8SUBC);//~vavaR~//~vavcR~
//#else                                                              //~vavaI~//~vavcR~
        rc|=rc2 & (XEUTFGU8MRC_UTF8|XEUTFGU8MRC_LC);               //~va10I~
//#endif                                                             //~vavaI~//~vavcR~
        oldcodetype=codetype;	//for next call                    //~va10I~
        if (Poututf8)                                              //~va10I~
            pcou8+=utf8len;                                        //~va10I~
        if (Pcodetype)                                             //~va10I~
            pcn+=wrtlen;                                           //~va10I~
      }                                                            //~va10I~
      else  //old version                                          //~va10I~
      {                                                            //~va10I~
//      opt=UTFCVO_ASCIIRET;                                       //~va00I~//~va0PR~
//  	utf8len=utfgetutf8strlen(opt,pc,reslen,0/*out ucscnt*/);   //~va00R~//~va0PR~
    	opt=UTFCVO_ASCIIRET|UTFCVO_ERRRET;	//return if translation err//~va0PR~
      	utfcvf2l(opt,pco,pc,reslen,&chklen,&wrtlen,0/*Ppcharwidth*/);//~va0PI~
UTRACEP("getmixedstr utfcvf2l chklen=%d,reslen=%d,wrtlen=%d\n",chklen,reslen,wrtlen);//~va0PI~
//      if (utf8len)	//detected UTF8 strining                   //~va0HI~//~va0PR~
        if (chklen)	//detected UTF8 strining                       //~va0PI~
    	{                                                              //~v92nI~//~va00I~
//  		opt=UTFCVO_ERRREP|(XEUTF_ERRREPCH<<8);                                //~v92nI~//~va00R~//~va0PR~
//    		utfcvf2l(opt,pco,pc,utf8len,&chklen,&wrtlen,0/*Ppcharwidth*/);//~va00I~//~va0PR~
			rc|=XEUTFGU8MRC_UTF8;                                  //~va00I~
            codetype=XEUTFCT_UTF8;          //utf8 str             //~va00R~
            if (Poututf8)                                          //~va00R~
            {                                                      //~va00I~
                if (pcou8+chklen>pcou8e)                           //~va00I~
                    break;                                         //~va00I~
                memcpy(pcou8,pc,(UINT)chklen);                     //~va00R~
                pcou8+=chklen;                                     //~va00I~
            }                                                      //~va00I~
	    }                                                              //~v92nI~//~va00I~
	    else    //locale->utf8                                         //~v92nI~//~va00I~
    	{                                                              //~v92nI~//~va00I~
          {                                                        //~va0wI~
			opt=UTFCVO_ERRRET|UTFCVO_ASCIIRET;                    //~v92nI~//~va00I~
    	    if (swiflong)                                          //~va0HR~
	            opt|=UTFCVO_UTF8RET;    //chk utf if lc err        //~va0HI~
//          len=min(reslen,sizeof(utf8wk));                        //~vb01R~
            len=min(reslen,(int)sizeof(utf8wk));                   //~vb01I~
      		utfcvl2fmix(opt,utf8wk,pc,0/*init offs*/,len,0/*out choftbl*/,0/*out dbcstbl*/,&chklen,&utf8len,0/*pcharcnt*/,0/*char width*/);//locale coed validity chk//~va00R~//~va0HR~
            wrtlen=chklen;                                         //~va00I~
          }                                                        //~va0wI~
            if (wrtlen)                                            //~va00I~
            {                                                      //~va00I~
            	wrtlen=min(resleno,wrtlen);                        //~va00I~
            	memcpy(pco,pc,(UINT)wrtlen);	//copy input locale str//~va00R~
            	codetype=XEUTFCT_LC; //locale str                  //~va00R~
				rc|=XEUTFGU8MRC_LC;                                //~va00R~
            }                                                      //~va00I~
            if (Poututf8)                                          //~va00R~
            {                                                      //~va00I~
              if (Popt & XEUTFGLSMO_KEEPLC)      //output source locale code to Poututf8//~va00R~
              {                                                    //~va00I~
                if (pcou8+wrtlen>pcou8e)                           //~va00I~
                    break;                                         //~va00I~
                memcpy(pcou8,pc,(UINT)wrtlen);	//output original locale code as mixed string//~va00I~
                pcou8+=wrtlen;                                     //~va00I~
              }                                                    //~va00I~
              else                                                 //~va00I~
              {                                                    //~va00I~
                if (pcou8+utf8len>pcou8e)                          //~va00I~
                    break;                                         //~va00I~
                memcpy(pcou8,utf8wk,(UINT)utf8len);                //~va00R~
                pcou8+=utf8len;                                    //~va00I~
              }                                                    //~va00I~
            }                                                      //~va00I~
	    }                                                              //~v92nI~//~va00I~
        if (!chklen)	//err	                                   //~va00I~
        {                                                          //~va00I~
            codetype=XEUTFCT_ASCII;                                //~va00R~
        	*pco=*pc;                                              //~va00I~
            chklen=1;                                              //~va00I~
            wrtlen=1;                                              //~va00I~
            if (Poututf8)                                          //~va00R~
            {                                                      //~va00I~
                if (pcou8>=pcou8e)                                 //~va00I~
                    break;                                         //~va00I~
                *pcou8++=*pc;                                      //~va00I~
            }                                                      //~va00I~
        }                                                          //~va00I~
        if (Pcodetype)                                             //~va00I~
        {                                                          //~va00I~
        	memset(pcn,codetype,(UINT)wrtlen);                     //~va00I~
            pcn+=wrtlen;                                           //~va00I~
        }                                                          //~va00I~
      }//old version no word consideration                         //~va10M~
    }                                                              //~va00I~
    if (Popt & XEUTFGLSMO_STRZ)                                    //~va00I~
    {                                                              //~va00I~
    	if (Poututf8)                                              //~va00R~
        	*pcou8=0;                                              //~va00I~
        *pco=0;                                                    //~va00I~
    }                                                              //~va00I~
//  outlen=(int)((ULONG)pco-(ULONG)Poutbuff);                      //~va00I~//~vafkR~
    outlen=(int)((ULPTR)pco-(ULPTR)Poutbuff);                      //~vafkI~
//#ifdef LNX                                                       //~vau7R~
//  if (!(Popt & XEUTFGLSMO_DDFMT))                                //~vau7R~
//#endif                                                           //~vau7R~
    if (Pdbcs)                                                     //~va00I~
    	setdbcstbl(Poutbuff,Pdbcs,outlen);             //reset dbcstbl//~va00I~
    if (Ppoutlen)                                                  //~va00R~
	    *Ppoutlen=outlen;                                          //~va00R~
//  oututf8len=(int)((ULONG)pcou8-(ULONG)Poututf8);                //~va00I~//~vafkR~
    oututf8len=(int)((ULPTR)pcou8-(ULPTR)Poututf8);                //~vafkI~
    if (Ppoututf8len)                                              //~va00I~
	    *Ppoututf8len=oututf8len;                                  //~va00I~
	UTRACED("pout",Poutbuff,outlen);                               //~va00I~
    UTRACEDIFNZ("codetbl",Pcodetype,outlen);                       //~va00R~
    UTRACEDIFNZ("outouf8",Poututf8,oututf8len);                    //~va00I~
    UTRACEDIFNZ("outdbcs",Pdbcs,outlen);                           //~vau5I~
    UTRACEP("xeutf_getmixedstr rc=%d\n",rc);                       //~vau7I~
    return rc;                                                     //~va00I~
}//xeutf_getmixedstr                                               //~va00R~
//#ifdef LNX                                                         //~vau7I~//~vauER~
//**************************************************************** //~vau7I~
//!xeutf_getmixedstrDDFMT                                          //~vauaR~
//output is ddfmt                                                  //~vau7I~
//     UALLOC_FAILED,2:ddfmt,0:all ascii                           //~vau7I~
//**************************************************************** //~vau7I~
int xeutf_getmixedstrDDFMT(int Popt,char *Pstr,int Pdatalen,char *Poutbuff,char *Pdbcs,char *Pcodetype,int Poutbuffsz,int *Ppoutlen)//~vau7I~
{                                                                  //~vau7I~
    char *pwkoutct;                                                //~vau7R~
    int rc=0,ddlen,rc2,outlen;                                     //~vau7R~
    int buffsz;                                                    //~vb01I~
//*****************************                                    //~vau7I~
UTRACED("xeutf_getmixedstrDDFMT data",Pstr,Pdatalen);              //~vau7I~
UTRACED("xeutf_getmixedstrDDFMT ctin ",Pcodetype,Pdatalen);        //~vau7I~
//  pwkoutct=xeutf_buffget(XEUTF_BUFF3,Pdatalen+1);                //~vau7I~//~vb01R~
    buffsz=max(Pdatalen,Poutbuffsz)+1;                             //~vb01I~
    pwkoutct=xeutf_buffget(XEUTF_BUFF3,buffsz);                    //~vb01I~
    UALLOCCHK(pwkoutct,UALLOC_FAILED);                             //~vau7I~
	rc2=xeutf_getmixedstr(Popt,Pstr,Pdatalen,Poutbuff/*outlc*/,NULL/*pdbcs*/,Pcodetype,Poutbuffsz,&outlen,NULL/*outu8*/,0/*outbuffsz*/,NULL/*outu8len*/);//~vau7I~
	if (rc2==UALLOC_FAILED)                                        //~vau7I~
    	return rc2;                                                //~vau7I~
    if (rc2 & (XEUTFGU8MRC_UTF8|XEUTFGU8MRC_LC))                   //~vau7I~
    {                                                              //~vau7I~
//		xeutfcvlf2ddAdjust(0,Pstr,Pdatalen,Pcodetype,outlen,Poutbuff,Pdbcs,pwkoutct,Poutbuffsz,&ddlen);//~vaumR~
  		xeutfcvlf2ddAdjust(0,Pstr,Pdatalen,Poutbuff,Pcodetype,outlen,Poutbuff,Pdbcs,pwkoutct,Poutbuffsz,&ddlen);//~vaumI~
        outlen=min(ddlen,Poutbuffsz);                              //~vau7I~
//      memcpy(Pcodetype,pwkoutct,outlen);                         //~vb01R~
        memcpy(Pcodetype,pwkoutct,(size_t)outlen);                 //~vb01I~
        rc=2;                                                      //~vau7I~
    }                                                              //~vau7I~
    else                                                           //~vau7I~
    {                                                              //~vau7I~
//      memset(Pdbcs,0,outlen);                                    //~vb01R~
        memset(Pdbcs,0,(size_t)outlen);                            //~vb01I~
        rc=0;                                                      //~vau7I~
    }                                                              //~vau7I~
	*Ppoutlen=outlen;                                              //~vau7R~
	UTRACED("xeutf_getmixedstrDDFMT dddata",Poutbuff,outlen);      //~vau7I~
	UTRACED("xeutf_getmixedstrDDFMT dddbcs",Pdbcs,outlen);         //~vau7I~
	UTRACED("xeutf_getmixedstrDDFMT ct",Pcodetype,outlen);         //~vau7I~
    return rc;                                                     //~vau7I~
}//xeutf_getmixedstrDDFMT                                          //~vau7I~
//#endif    //LNX                                                   //~vau7I~//~vauER~
#endif  //UTF8SUPPH                                                //~va00I~
#ifdef UTF8UCS2                                                    //~va20I~
//**************************************************************** //~va20I~
//!xeutf_modechng                                                  //~va20I~
//chng dbcs/chof utf8<-->nonutf8                                   //~va20I~
//src pfh is 0 when from charcap2                                  //~va20I~
//tab is cleared                                                   //~va20R~
//rc:0:no change,1:utf8-->non utf8,  2:non utf8-->utf8,UALLOC_FAILED//~va20I~
//**************************************************************** //~va20I~
int xeutf_modechng(int Popt,PUFILEH Ppfhd,PUFILEH Ppfhs,UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen,//~va20I~
					UCHAR **Ppoutdata,UCHAR **Ppoutdbcs,int *Ppoutlen)//~va20I~
{                                                                  //~va20I~
    int rc,rc2,tgtutf8mode,srcutf8mode,outlen,swasciichk=1;        //~va20R~
    UCHAR  *pdbcs;                                                 //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    int swebcfiled,swebcfiles,opt;                                 //~va50R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    int handled,handles=0;                                         //~vaf9R~
//****************************                                     //~va20I~
	tgtutf8mode=(FILEUTF8MODE(Ppfhd)!=0);                          //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    swebcfiled=PFH_ISEBC(Ppfhd);                                   //~va50I~
    handled=Ppfhd->UFHhandle;                                      //~va7wI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    if (Ppfhs)                                                     //~va20I~
    {                                                              //~va50I~
	    srcutf8mode=(FILEUTF8MODE(Ppfhs)!=0);                      //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    	swebcfiles=PFH_ISEBC(Ppfhs);                               //~va50I~
    	handles=Ppfhs->UFHhandle;                                  //~va7wI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    }                                                              //~va50I~
    else                                                           //~va20I~
    {                                                              //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
        srcutf8mode=0;                                             //~va50I~
        swebcfiles=0;                                              //~va50I~
        if (Popt & XEUTFMCO_SRCEB)                                 //~va50I~
        {                                                          //~va7wI~
	    	swebcfiles=1;	//src ebc                              //~va50I~
            if (Popt & XEUTFMCO_EBCHANDLEP)                        //~va7wI~
            	handles=XEUTFMCO_GETHANDLE(Popt);                  //~va7wI~
            else                                                   //~va7wI~
            	handles=handled;                                   //~va7wI~
        }                                                          //~va7wI~
        else                                                       //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    	                                                           //~va50I~
        if (Popt & XEUTFMCO_SRCU8)                                 //~va20I~
	    	srcutf8mode=1;	//ddstr                                //~va20I~
        else                                                       //~va20I~
        if (Popt & XEUTFMCO_SRCLC)                                 //~va20I~
	    	srcutf8mode=0;	//locale str                           //~va20I~
        else                                                       //~va20I~
        {                                                          //~va20I~
			rc2=utfddisasciistr(UTFDDIASO_M1RCIFDD,Pdata,Pdbcs,Pdatalen); //src is all ascii//~va20R~
        	if (rc2==1)	//all ascii                                //~va20R~
        		return 0;                                          //~va20R~
	    	srcutf8mode=(rc2==-1);	//ddstr                        //~va20R~
            swasciichk=0;                                          //~va20I~
        }                                                          //~va20I~
    }                                                              //~va20I~
UTRACEP("modechngs tgtu8=%x,srcu8=%x,tgtebc=%x,srcebc=%x\n",srcutf8mode,tgtutf8mode,swebcfiled,swebcfiles);  //~va20I~//~va50R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
  	if (swebcfiled||swebcfiles)                                    //~va50I~
    {                                                              //~va50I~
        if (UCBITCHK(Ppfhd->UFHflag4,UFHF4BIN))   //target is bin mode(src:EBC)//~vawEI~
        	return 0;                                              //~vawEI~
        opt=0;                                                     //~va7wI~
		if (swebcfiled==swebcfiles)                                //~va50I~
        {                                                          //~va50I~
          if (handled==handles)                                    //~va7wI~
          {                                                        //~va7wI~
UTRACEP("NO modechngs EBC\n");                                     //~va50I~
  		  	return 0;                                              //~va50I~
          }                                                        //~va7wI~
          opt|=XEEBCO_B2B;  //ebc codepage change                  //~va7wI~
        }                                                          //~va50I~
//      opt=0;                                                     //~va50I~//~va7wR~
	    if (srcutf8mode)                                           //~va50I~
        	opt|=XEEBCO_DD2B;                                      //~va50R~
	    if (tgtutf8mode)                                           //~va50I~
        	opt|=XEEBCO_B2DD;                                      //~va50R~
        opt|=XEEBCO_ERRREP;                                        //~va5EI~
//  	return xeebc_modechng(opt,Ppfhd,Ppfhs,Pdata,Pdbcs,Pdatalen,Ppoutdata,Ppoutdbcs,Ppoutlen);//~va50I~//~va7wR~
    	return xeebc_modechng(opt,Ppfhd,Ppfhs,handles,Pdata,Pdbcs,Pdatalen,Ppoutdata,Ppoutdbcs,Ppoutlen);//~va7wI~
    }                                                              //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
	if (tgtutf8mode==srcutf8mode)                                  //~va20I~
    {                                                              //~va20I~
UTRACEP("NO modechngs\n");                                         //~va20R~
    	return 0;                                                  //~va20I~
    }                                                              //~va20I~
    if (swasciichk)	//mode determined by pfh or parm               //~va20R~
    {                                                              //~va20I~
		if (utfddisasciistr(0,Pdata,Pdbcs,Pdatalen)) //src is all ascii//~va20I~
        	return 0;                                              //~va20I~
    }                                                              //~va20I~
    if (tgtutf8mode)          //non utf8-->utf8                    //~va20I~
    {                                                              //~va20I~
		rc2=xeutfcvl2dd(0,Pdata,Pdatalen,Ppoutdata,&pdbcs,&outlen);//~va20I~
        UALLOCCHKRC(rc2);                                          //~va20I~
        rc=2;                                                      //~va20I~
    }                                                              //~va20I~
    else					//utf8-->non utf8;                     //~va20I~
    {                                                              //~va20I~
      if (UCBITCHK(Ppfhd->UFHflag4,UFHF4BIN))   //target is bin mode//~vawEI~
      {                                                            //~vawEI~
        int optdd2f=XEUTFDD2FO_SETDBCSTBL; //setdbcstbl as bin file//~vawEI~
		rc2=xeutfcvdd2f(optdd2f,Pdata,Pdbcs,Pdatalen,Ppoutdata,&outlen,&pdbcs);//~vawER~
      }                                                            //~vawEI~
      else                                                         //~vawEI~
		rc2=xeutfcvdd2ldbcs(0,Pdata,Pdbcs,Pdatalen,Ppoutdata,&pdbcs,&outlen);//~va20R~
        UALLOCCHKRC(rc2);                                          //~va20I~
		rc=1;                                                      //~va20I~
    }                                                              //~va20I~
    chartabclear(pdbcs,outlen);                                    //~va20R~
    *Ppoutdbcs=pdbcs;                                              //~va20I~
    *Ppoutlen=outlen;                                              //~va20I~
UTRACED("inp data",Pdata,Pdatalen);                                //~va20R~
UTRACED("inp dbcs",Pdbcs,Pdatalen);                                //~va20I~
UTRACED("out data",*Ppoutdata,outlen);                             //~va20R~
UTRACED("out dbcs",pdbcs,outlen);                                  //~va20I~
    return rc;                                                     //~va20I~
}//xeutf_modechng                                                  //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8UCS2                                                    //~va20I~
#ifdef AAA                                                         //~vagvI~
//**************************************************************** //~va20I~
//!xeutfcvl2f                                                      //~va20I~
//utf8<--locale data conversion                                    //~va20I~
//rc:0,XEUTFCVRC_ALLASCII,UALLOC_FAILED(if XEUTFCVO_OUTPARM is off)//~va20I~
//**************************************************************** //~va20I~
int xeutfcvl2f(int Popt,char *Pinp,int Pinplen,UCHAR **Ppout,int *Ppoutlen)//~va20R~//~va5wR~
{                                                                  //~va20I~
	int opt,rc=0;                                                  //~va20R~
//****************************                                     //~va20I~
    opt=Popt & ~XEUTFCVO_CPLC;   //deny utf8->locale               //~va20I~
	rc=xeutf_cvdata(opt,Pinp,Pinplen,Ppout,Ppoutlen);              //~va20I~
    return rc;                                                     //~va20I~
}//xeutfcvl2f                                                      //~va20I~
#endif                                                             //~vagvI~
#endif                                                             //~va20I~
#ifdef UTF8SUPPH                                                   //~va00I~
//**************************************************************** //~v92nI~
//!xeutf_cvdata                                                    //~v92nI~
//utf8<->locale data conversion                                    //~v92nI~
//rc:0,XEUTFCVRC_ALLASCII,UALLOC_FAILED(if XEUTFCVO_OUTPARM is off)//~va00I~
//**************************************************************** //~v92nI~
int xeutf_cvdata(int Popt,char *Pinp,int Pinplen,UCHAR **Ppout,int *Ppoutlen)//~v92nR~//~va5wR~
{                                                                  //~v92nI~
	int len,opt,outlen,chklen,rc=0;                                //~v92nR~
    int rc2;                                                       //~va00I~
    char *poutdata;                                                //~v92nI~
//****************************                                     //~v92nI~
	UTRACED("xeutf_cvdata Pinp",Pinp,Pinplen);                          //~v92nI~//+vbkbR~
  if (Popt & XEUTFCVO_OUTPARM)   //Ppout is input(output area addr)//~va00I~
	poutdata=*Ppout;                                               //~va00I~
  else                                                             //~va00I~
  {                                                                //~va00I~
	if (Popt & XEUTFCVO_CPLC)                                      //~v92nI~
//  	len=Pinplen;                                               //~va1cR~
    	len=Pinplen*UTF8_F2LMAXRATE; //utf8->gb18030 my expand by 4byte code//~va1cR~
    else                                                           //~v92nI~
    	len=Pinplen*UTF8_MAXCHARSZ;                                //~v92nI~
	poutdata=xeutf_buffget(XEUTF_BUFFDATA,len+1);                    //~v92nI~//~va00R~
	UALLOCCHK(poutdata,UALLOC_FAILED);                             //~v92nI~
  }                                                                //~va00I~
	if (Popt & XEUTFCVO_NOERRREP)   //no set err replacing char    //~va00I~
    	opt=0;                                                     //~va00I~
    else                                                           //~va00I~
	if (Popt & XEUTFCVO_ERRREPQM)   //no set err replacing char    //~va00I~
    	opt=UTFCVO_ERRREP|(XEUTF_ERRREPCH_F2LFILE<<8);             //~va00I~
    else                                                           //~va00I~
    	opt=UTFCVO_ERRREP|(XEUTF_ERRREPCH<<8);                     //~va00I~
	if (Popt & XEUTFCVO_CPLC)   //utf8->locale                     //~v92nI~
    {                                                              //~v92nI~
      rc2=                                                         //~va00I~
		utfcvf2l(opt,poutdata,Pinp,Pinplen,&chklen,&outlen,0/*Ppcharwidth*/);//~v92nR~
    }                                                              //~v92nI~
    else    //locale->utf8                                         //~v92nI~
    {                                                              //~v92nI~
                                                                   //~va00I~
		opt|=UTFCVO_2UTF;                    //~v92nI~             //~va00R~
      rc2=                                                         //~va00I~
		utfcvl2f(opt,poutdata,Pinp,0/*init offs*/,Pinplen,0/*out choftbl*/,0/*out dbcstbl*/,0/*readlen*/,&outlen,0/*pcharcnt*/,0/*char width*/);//~v92nR~
    }                                                              //~v92nI~
	if (Popt & XEUTFCVO_STRZ)   //append 0                         //~va00I~
        *(poutdata+outlen)=0;                                      //~va00I~
    if (rc2==UTFCVRC_ALLASCII)                                     //~va00I~
    {                                                              //~va00I~
        if (Popt & XEUTFCVO_RETALLASCII)                           //~va00I~
            rc=XEUTFCVRC_ALLASCII;                                 //~va00I~
    }                                                              //~va00I~
    else                                                           //~va00I~
    if (rc2>=UTFCVRC_ERR)                                          //~va00R~
    	rc=XEUTFCVRC_ERR;                                          //~va00I~
  if (Ppoutlen)                                                    //~va00I~
    *Ppoutlen=outlen;                                              //~v92nI~
  if (Ppout)                                                       //~va00I~
   if (!(Popt & XEUTFCVO_OUTPARM))   //Ppout is input(output area addr)//~va00I~
    *Ppout=poutdata;                                               //~v92nI~
	UTRACED("xeutf_cvdata",poutdata,outlen);                       //~v92nR~//~va0wM~
	UTRACEP("xeutf_cvdata rc=%d\n",rc);                            //~v92nI~
    return rc;                                                     //~v92nI~
}//xeutf_cvdata                                                    //~va00R~
//**************************************************************** //~va1EI~
//!xeutf_cvdatawb                                                  //~va1EI~
//utf8<--locale data conversion saveing original trans err code    //~va1EI~
//rc:0,XEUTFCVRC_ALLASCII,UALLOC_FAILED(if XEUTFCVO_OUTPARM is off)//~va1EI~
//**************************************************************** //~va1EI~
int xeutf_cvdatawb(int Popt,char *Pinp,int Pinplen,UCHAR **Ppout,int *Ppoutlen,UCHAR *Pdbcs,int Pdbcstblen)//~va1EI~//~va5wR~
{                                                                  //~va1EI~
	int len,opt,outlen,rc=0,rc2,errsw=0,reslen,reslendbcs,lenu8;   //~va1ER~
    char *pco,*pcerr,*pci,*pcd;                          //~va1ER~ //~va20R~
    UCHAR *poutdata;                                               //~va20I~
//****************************                                     //~va1EI~
	UTRACED("xeutf_cvdatawb inp data",Pinp,Pinplen);               //~va1EI~
	UTRACED("xeutf_cvdatawb inp dbcs",Pdbcs,Pdbcstblen);           //~va1EI~
	if (!(Gutfmode2 & GUM2_KEEPIFCVERR))   //NOT keep original value even when f2l cv err at load//~va1EI~
		return xeutf_cvdata(Popt,Pinp,Pinplen,Ppout,Ppoutlen);     //~va1ER~
#ifdef UTF8UCS2                                                    //~va20I~
 if (Popt & XEUTFCVO_CPLCUCS2)   //dd2l                            //~va20I~
 {                                                                 //~va20I~
  	opt=XEUTFDD2LO_CRLF; //malloc more 2 byte for crlf padding     //~va20I~
//  if (!(Popt & XEUTFCVO_ERRREPQM))                               //~va20R~
//    	opt=XEUTFDD2LO_ERRRET; //return if cverr //write ? if no "IE" specified//~va20R~
	rc2=xeutfcvdd2l(opt,Pinp,Pdbcs,Pdbcstblen,&poutdata,&outlen);  //~va20I~
//    if (Popt & XEUTFCVO_ERRREPQM)                                //~va20R~
//    {                                                            //~va20R~
//        if (rc2>=XEUTFF2LCRC_ERR)                                //~va20R~
//            rc=XEUTFCVRC_ERR;                                    //~va20R~
//    }                                                            //~va20R~
//    else                                                         //~va20R~
    {                                                              //~va20I~
    	if (rc2>=XEUTFF2LCRC_UTF8ERR)   //f2l cverr                //~va20I~
        	rc=XEUTFCVRC_ERR;                                      //~va20I~
    }                                                              //~va20I~
    if ((len=(Pinplen-Pdbcstblen))>0)   //crlf data                //~va20R~
    {                                                              //~va20R~
        memcpy(poutdata+outlen,Pinp+Pdbcstblen,(UINT)len);  //append crlf//~va20R~
        outlen+=len;                                               //~va20R~
    }                                                              //~va20R~
 }                                                                 //~va20I~
 else                                                              //~va20I~
#endif                                                                   //~va1EI~//~va20R~
 {                                                                 //~va20I~
    len=Pinplen*UTF8_MAXCHARSZ;                                    //~va1EI~
	poutdata=xeutf_buffget(XEUTF_BUFFDATA,len+1);                  //~va1EI~
	UALLOCCHK(poutdata,UALLOC_FAILED);                             //~va1EI~
#ifdef UTF8UCS2                                                    //~va20I~
  if (Popt & XEUTFCVO_CPU8UCS2)   //no set err replacing char      //~va20I~
  {                                                                //~va20I~
  	opt=0;                                                         //~va20I~
	rc=utfcvdd2f(opt,Pinp,Pdbcstblen,Pdbcs,poutdata,len+1,&outlen,0/*outdbcs*/);//~va20R~
    if ((len=(Pinplen-Pdbcstblen))>0)	//crlf data                //~va20R~
    {                                                              //~va20I~
    	memcpy(poutdata+outlen,Pinp+Pdbcstblen,(UINT)len);	//append crlf//~va20I~
        outlen+=len;                                               //~va20I~
    }                                                              //~va20I~
    if (rc>=UTFDD2FRC_ERR)                                         //~va20R~
    	rc=XEUTFCVRC_ERR;                                          //~va20I~
    else                                                           //~va20I~
    	rc=0;                                                      //~va20I~
  }                                                                //~va20I~
  else                                                             //~va20I~
#endif                                                             //~va20I~
  {                                                                //~va20I~
	if (Popt & XEUTFCVO_NOERRREP)   //no set err replacing char    //~va1EI~
    	opt=0;                                                     //~va1EI~
    else                                                           //~va1EI~
	if (Popt & XEUTFCVO_ERRREPQM)   //no set err replacing char    //~va1EI~
    	opt=UTFCVO_ERRREP|(XEUTF_ERRREPCH_F2LFILE<<8);             //~va1EI~
    else                                                           //~va1EI~
    	opt=UTFCVO_ERRREP|(XEUTF_ERRREPCH<<8);                     //~va1EI~
                                                                   //~va1EI~
	opt|=UTFCVO_2UTF;   //l2f                                      //~va1ER~
    for (pco=poutdata,pci=Pinp,pcd=Pdbcs,reslen=Pinplen,reslendbcs=Pdbcstblen;//~va1EI~
    		reslen>0;)                                             //~va1EI~
    {                                                              //~va1EI~
    	if (reslendbcs>0)                                          //~va1EI~
        {                                                          //~va1EI~
//search on pcd                                                    //~va5nI~
        	pcerr=memchr(pcd,UDBCSCHK_F2LERR,(UINT)reslendbcs);    //~va1EI~
            if (pcerr)                                             //~va1EI~
//          	len=(int)((ULONG)pcerr-(ULONG)pcd);                //~va1EI~//~vafkR~
            	len=(int)((ULPTR)pcerr-(ULPTR)pcd);                //~vafkI~
            else                                                   //~va1EI~
            	len=reslen;	//beyond dbcst,assume no trans err contained//~va1EI~
        }                                                          //~va1EI~
        else                                                       //~va1EI~
        {                                                          //~va1EI~
    		pcerr=0;                                               //~va1EI~
            len=reslen;	//beyond dbcst,assume no trans err contained//~va1EI~
        }                                                          //~va1EI~
    	rc2=utfcvl2f(opt,pco,pci,0/*init offs*/,len,0/*out choftbl*/,0/*out dbcstbl*/,0/*readlen*/,&lenu8,0/*pcharcnt*/,0/*char width*/);//~va1EI~
	    if (rc2>=UTFCVRC_ERR)                                      //~va1EI~
        	errsw=1;                                               //~va1EI~
		pci+=len;                                                  //~va1EI~
        pcd+=len;                                                  //~va1EI~
        reslen-=len;                                               //~va1EI~
		reslendbcs-=len;                                           //~va1ER~
        pco+=lenu8;                                                //~va1EI~
        if (pcerr)                                                 //~va1EI~
        {                                                          //~va1EI~
        	for (;reslen>0 && reslendbcs>0;pcd++,reslen--,--reslendbcs)//~va1EI~
            {                                                      //~va1EI~
	        	if (*pcd!=UDBCSCHK_F2LERR)                         //~va1EI~
                	break;                                         //~va1EI~
                *pco++=*pci++;                                     //~va1ER~
            }                                                      //~va1EI~
        }                                                          //~va1EI~
    }                                                              //~va1EI~
//  outlen=(int)((ULONG)pco-(ULONG)poutdata);                      //~va1EI~//~vafkR~
    outlen=(int)((ULPTR)pco-(ULPTR)poutdata);                      //~vafkI~
    if (errsw)                                                     //~va1EI~
    	rc=XEUTFCVRC_ERR;                                          //~va1EI~
  }//!ucs2                                                         //~va20I~
 }//!CPLCUCS2                                                      //~va20I~
    *Ppoutlen=outlen;                                              //~va1EI~
    *Ppout=poutdata;                                               //~va1EI~
	UTRACED("xeutf_cvdatawb",poutdata,outlen);                     //~va1EI~
	UTRACEP("xeutf_cvdatawb rc=%d\n",rc);                          //~va1EI~
    return rc;                                                     //~va1EI~
}//xeutf_cvdatawb                                                  //~va1EI~
//**************************************************************** //~va00I~
//!xeutf_cvf2lsetdbcs                                              //~va00I~
//utf8->locale data conversion with dbcstbl setting                //~va00I~
//rc:0,01:cv done, 0x02:dbcs,0x04:conv err                         //~va00R~
//   UALLOC failed if *Ppout=0;                                    //~va00I~
//**************************************************************** //~va00I~
//int xeutf_cvf2lsetdbcs(int Popt,char *Pinp,int Pinplen,char **Ppout,char *Pdbcs,int *Ppoutlen)//~va1cR~
int xeutf_cvf2lsetdbcs(int Popt,char *Pinp,int Pinplen,UCHAR **Ppout,UCHAR **Ppdbcs,int *Ppoutlen)//~va1cR~//~va5wR~
{                                                                  //~va00I~
	int opt,lenlc,chsz,rc=0,rc2;                                   //~va00R~
    char *pdbcs=0,*pu8=0,*plc,*plce;                               //~vaf9R~
    char *pdbcs0;                                                  //~va1cR~
    int dbcssz;                                                    //~va1cR~
    int cverrchctr=0;                                              //~va1EI~
    ULONG ucs4;                                                    //~va54I~
    int reslen,chszerr,chszu8,ii;                                  //~va54R~
//****************************                                     //~va00I~
#ifdef UTF8UCS2                                                    //~va1LI~
	if (Popt & XEUTFF2LO_DDFMT)	//cv to ucs2                       //~va1LI~
		return xeutf_cvf2dd(Popt,Pinp,Pinplen,Ppout,Ppdbcs,Ppoutlen);//~va1LI~
#endif                                                             //~va1LI~
	UTRACED("xeutf_cvf2lsetdbcs",Pinp,Pinplen);                    //~va00I~
	opt=XEUTFCVO_CPLC;  //utf-->lc                                 //~va00R~
    if (*Ppout)                                                    //~va00I~
		opt=XEUTFCVO_OUTPARM;   //Ppout is input(output area addr) //~va00I~
	rc2=xeutf_cvdata(opt,Pinp,Pinplen,Ppout,&lenlc);               //~va00R~
    pdbcs0=*Ppdbcs;                                                //~va1cR~
    if (!pdbcs0)                                                   //~va1cR~
    {                                                              //~va1cR~
		pdbcs0=xeutf_buffget(XEUTF_BUFF2,lenlc);                   //~va1cR~
		UALLOCCHK(pdbcs0,UALLOC_FAILED);                           //~va1cR~
        *Ppdbcs=pdbcs0;                                            //~va1cR~
    }                                                              //~va1cR~
//  memset(Pdbcs,0,(UINT)lenlc);                                   //~va1cR~
    memset(pdbcs0,0,(UINT)lenlc);                                  //~va1cR~
    plc=*Ppout;                                                    //~va00M~
    if (rc2!=XEUTFCVRC_ALLASCII)                                   //~va00I~
    {                                                              //~va00I~
        rc|=XEUTFF2LRC_UTF8;	//1                                //~va00I~
//  	setdbcstbl(plc,Pdbcs,lenlc);                               //~va1cR~
    	setdbcstbl(plc,pdbcs0,lenlc);                              //~va1cR~
UTRACED("xeutf_cvf2lsetdbcs inp",plc,lenlc);                       //~va1cR~
UTRACED("xeutf_cvf2lsetdbcs dbcs out",pdbcs0,lenlc);               //~va1cR~
//    	for (pu8=Pinp,pdbcs=Pdbcs,plce=plc+lenlc;plc<plce;plc++,pdbcs++,pu8+=chsz)//~va1cR~
      	for (pu8=Pinp,pdbcs=pdbcs0,plce=plc+lenlc;plc<plce;plc++,pdbcs++,pu8+=chsz)//~va1cR~
        {                                                          //~va00I~
        	if (*pu8!=XEUTF_ERRREPCH && *plc==XEUTF_ERRREPCH)	//err replaced//~va00I~
            {                                                      //~va00I~
                rc|=XEUTFF2LRC_ERR;	//4                            //~va00M~
	        	if (Popt & XEUTFF2LO_KEEPIFCVERR)	               //~va00I~
                {                                                  //~va00I~
	                rc|=XEUTFF2LRC_ERRKEPTORG;	//8                //~va00I~
                    break;                                         //~va00I~
                }                                                  //~va00I~
    		  if (Popt & XEUTFF2LO_SAVECVERRCH) //setdbcs by org char if cverr//~va1EI~
              {                                                    //~va1EI~
            	*pdbcs=UDBCSCHK_F2LERR;                            //~va1EI~
                *plc=*pu8;	//back to original byte code           //~va1EI~
                cverrchctr++;                                      //~va1EI~
              }                                                    //~va1EI~
              else                                                 //~va1EI~
              {                                                    //~va1EI~
            	*pdbcs=UDBCSCHK_HKDBCSERR;                         //~va00I~
                *plc=XEUTF_ERRREPCH_F2LFILE;/* =*pu8;org char */ //    '?'      //f2l err replace on plh//~va00R~
              }                                                    //~va1EI~
            	chsz=1;                                            //~va00I~
//              reslen=Pinplen-((ULONG)pu8-(ULONG)Pinp);           //~va54I~//~vafkR~
//              reslen=Pinplen-((ULPTR)pu8-(ULPTR)Pinp);           //~vb01R~
                reslen=Pinplen-(int)((ULPTR)pu8-(ULPTR)Pinp);      //~vb01I~
                if (!utfgetwc(pu8,reslen,&ucs4,&chszu8))	//valid utf8 code//~va54I~
             	{                                                  //~va54I~
	                utfgetwcw(UTFGWCWO_INPUTUCS,pu8,0/*len*/,&ucs4,0/*chklen*/,&chszerr);//~va54I~
                    chsz=chszu8;    //to next u8char               //~va54I~
#ifdef AAA                                                         //~va54I~
		    		if (Popt & XEUTFF2LO_SAVECVERRCH) //setdbcs by org char if cverr//~va54I~
                    {                                              //~va54I~
	                    shiftctr=chszu8-chszerr;                   //~va54I~
		                reslen=(ULONG)plce-(ULONG)plc-chszerr;     //~va54I~
    	                if (shiftctr>0)                            //~va54I~
        	            	memmove(plc+chszerr+shiftctr,plc+chszerr,reslen);//~va54I~
                        plce+=shiftctr;                            //~va54I~
                    	for (ii=1;ii<chszu8;ii++)                  //~va54I~
                    	{                                          //~va54I~
            				*(++pdbcs)=UDBCSCHK_F2LERR;            //~va54I~
                			*(++plc)=*(pu8+ii);	//back to original byte code//~va54I~
              			}                                          //~va54I~
                    }                                              //~va54I~
                    else                                           //~va54I~
                    {                                              //~va54I~
                    	for (ii=1;ii<chszerr;ii++)                 //~va54I~
                    	{                                          //~va54I~
			            	*(++pdbcs)=UDBCSCHK_HKDBCSERR;         //~va54I~
                			*(++plc)=XEUTF_ERRREPCH_F2LFILE;       //~va54I~
              			}                                          //~va54I~
                    }                                              //~va54I~
#else               //no set utf8 code to keep column,keep org value is now no meaning//~va54I~
                    for (ii=0;ii<chszerr;ii++)                     //~va54R~
                    {                                              //~va54I~
                    	*pdbcs++=UDBCSCHK_HKDBCSERR;               //~va54I~
                        *plc++=XEUTF_ERRREPCH_F2LFILE;/* =*pu8;org char */ //    '?'      //f2l err replace on plh//~va54I~
                    }                                              //~va54I~
                    pdbcs--;    //for loop ctl                     //~va54I~
                    plc--;                                         //~va54I~
#endif                                                             //~va54I~
             	}//valid utf8 code                                 //~va54I~
            }                                                      //~va00I~
            else                                                   //~va00I~
            {                                                      //~va00I~
        		chsz=UTF8CHARLEN(*pu8);                            //~va00I~
                if (*pdbcs==UDBCSCHK_DBCS1ST)                      //~va00I~
                {                                                  //~va00I~
//                	plc++;                                         //~va1cR~
//                  pdbcs++;                                       //~va1cR~
//  				dbcssz=XESUB_DBCSSPLITCTR(pdbcs,(int)((ULONG)plce-(ULONG)plc) ,0/*pos*/)-1;//~va1cR~//~vafkR~
    				dbcssz=XESUB_DBCSSPLITCTR(pdbcs,(int)((ULPTR)plce-(ULPTR)plc) ,0/*pos*/)-1;//~vafkI~
UTRACEP("dbcs pu8=%p,dbcssz=%d\n",pu8,dbcssz+1);                   //~va1cR~
                    plc+=dbcssz;                                   //~va1cR~
                    pdbcs+=dbcssz;                                 //~va1cR~
	                rc|=XEUTFF2LRC_DBCS;	//2                    //~va00I~
                }                                                  //~va00I~
            }                                                      //~va00I~
        }                                                          //~va00I~
    }                                                              //~va00I~
UTRACEP("xeutf_cvf2lsetdbcs loop end putf8=%p,plc=%p,pdbcs=%p\n",pu8,plc,pdbcs);//~va1cR~
	if (rc & XEUTFF2LRC_ERRKEPTORG)                                //~va00I~
    {                                                              //~va00I~
//  	setdbcstbl(Pinp,Pdbcs,Pinplen);                            //~va1cR~
    	setdbcstbl(Pinp,pdbcs0,Pinplen);                           //~va1cR~
        lenlc=Pinplen;                                             //~va00I~
    }                                                              //~va00I~
    if (cverrchctr)                                                //~va1EI~
    	rc|=XEUTFF2LRC_SAVEERRCH;  //left org byte code by trans err//~va1EI~
    if (Ppoutlen)                                                  //~va00I~
        *Ppoutlen=lenlc;                                           //~va00I~
	UTRACEP("xeutf_cvf2lsetdbcs rc=%d\n",rc);                      //~va00I~
	UTRACED("xeutf_cvf2lsetdbcs lc out ",*Ppout,lenlc);            //~va1cR~
	UTRACED("xeutf_cvf2lsetdbcs dbcs out",pdbcs0,lenlc);           //~va1cR~
    return rc;                                                     //~va00I~
}//xeutf_cvf2lsetdbcs                                              //~va00I~
//**************************************************************** //~va00I~
//!xeutf_islocalestr                                               //~va00I~
//chk locale code string   rc:0:ascii,1:locale string under locale CP,2:locale str under UTF8 CP//~va00R~
//UALOC_FAILED if XEUTFCVO_OUTPARM is off                          //~va00I~
//0:allascii,1:locale,2:locale under utf8 env                      //~va00I~
//**************************************************************** //~va00I~
int xeutf_islocalestr(int Popt,char *Pinp,int Pinplen,UCHAR **Pputf8,int *Pputflen)//~va00R~//~va5wR~
{                                                                  //~va00I~
	int opt,rc;                                                    //~va00R~
//****************************                                     //~va00I~
	UTRACED("xeutf_islocalestr",Pinp,Pinplen);                     //~va00I~
    opt=Popt|(XEUTFCVO_RETALLASCII|XEUTFCVO_CPU8);                 //~va00R~
	rc=xeutf_cvdata(opt,Pinp,Pinplen,Pputf8,Pputflen);             //~va00R~
	UTRACEP("xeutf_islocalestr cvdata rc=%d\n",rc);                //~va00I~
	if (rc==UALLOC_FAILED)                                         //~va00I~
    	return rc;                                                 //~va00I~
    rc=(rc!=XEUTFCVRC_ALLASCII);                                   //~va00R~
	if (rc)                                                        //~va00R~
    {                                                              //~va00I~
    	if (Popt & XEUTFCVO_ENVCHK)                                //~va00I~
			if (XEUTF8MODE_ENV_FORCE())                            //~va00I~
    			rc=XEUTFILRC_UTF8;                                 //~va00R~
    }                                                              //~va00I~
	UTRACEP("xeutf_islocalestr rc=%d\n",rc);                       //~va00I~
    return rc;                                                     //~va00I~
}//xeutf_islocalestr                                               //~va00I~
//*******************************************************          //~va00I~
//*lcale to utf8 if env is utf8                                    //~va00I~
//*dbcstbl:input                                                   //~va00R~
//*codetype:output                                                 //~va00I~
//*utf8str:output                                                  //~va00I~
//*if no utf8 code,set null to output utf8 str                     //~va00I~
//*return 0:allascii,1:all locale or noutf env ,2:utf8 conv done   //~va00R~
//*       UALLOC_FAILED if no OUTPARM                              //~va00I~
//      1:XEUTFILRC_LC     locale string                           //~va00I~
//      2:XEUTFILRC_UTF8   locale string under UTF8 env            //~va00I~
//*******************************************************          //~va00I~
int xeutf_fldl2f(int Popt,char *Pdata,char *Pdbcs,char *Pwk,int Plen,char *Pcodetype,char *Putf8,int *Pputf8len)//~va00R~
{                                                                  //~va00I~
    UCHAR *pwk,*pdata,*pct,*pct0,*putf8,*pdbcs;                     //~va00R~//~va5wR~
	int ii,inplen,outlen,rc,opt;                                   //~va00R~
//************************                                         //~va00I~
    pwk=Pwk;                                                       //~va00I~
    putf8=Putf8;                                                   //~va00I~
    pct0=Pcodetype;                                                //~va00I~
    pdata=Pdata;                                                   //~va00I~
    pdbcs=Pdbcs;                                                   //~va00I~
    if (!(inplen=Plen))                                            //~va00I~
	    inplen=(int)strlen(pdata);                                 //~va00I~
    *putf8=0;                                                      //~va00I~
    outlen=0;                                                      //~va00I~
    rc=XEUTFILRC_ALLASCII;                                         //~va00I~
    if (inplen)                                                    //~va00I~
    {                                                              //~va00I~
        opt=XEUTFCVO_ENVCHK|XEUTFCVO_STRZ;                         //~va00I~
    	if (pwk)                                                   //~va00I~
        	opt|=XEUTFCVO_OUTPARM;                                 //~va00I~
        rc=xeutf_islocalestr(opt,pdata,inplen,&pwk,&outlen); //l2f //~va00R~
        if (rc==XEUTFILRC_UTF8)   //locale string under UTF8 env   //~va00R~
        {                                                          //~va00I~
            memcpy(putf8,pwk,(UINT)outlen+1);                      //~va00I~
            for (pct=pct0,ii=0;ii<inplen;ii++,pdata++)             //~va00R~
            {                                                      //~va00I~
                if (*pdbcs++)                                      //~va00I~
                    *pct++=XEUTFCT_UTF8;                           //~va00I~
                else                                               //~va00I~
                	if (*pdata<0x80)                               //~va00R~
	                    *pct++=XEUTFCT_ASCII;                      //~va00R~
                    else                                           //~va00I~
	                    *pct++=XEUTFCT_UTF8;                       //~va00I~
            }                                                      //~va00I~
        }                                                          //~va00I~
        else                                                       //~va00I~
		if (Popt & XEUTFCVO_SETCT)  //setup utf8/codetype even when no utf8 contains//~va00R~
        {                                                          //~va00I~
            memcpy(putf8,pwk,(UINT)outlen+1);                      //~va00I~
            for (pct=pct0,ii=0;ii<inplen;ii++,pdata++)             //~va00R~
            {                                                      //~va00I~
                if (*pdbcs++)                                      //~va00I~
                    *pct++=XEUTFCT_LC;                             //~va00I~
                else                                               //~va00I~
                	if (*pdata<0x80)                               //~va00I~
	                    *pct++=XEUTFCT_ASCII;                      //~va00I~
                    else                                           //~va00I~
	                    *pct++=XEUTFCT_LC;                         //~va00I~
            }                                                      //~va00I~
        }                                                          //~va00I~
    }                                                              //~va00I~
    if (Pputf8len)                                                 //~va00I~
        *Pputf8len=outlen;                                         //~va00I~
    return rc;                                                     //~va00R~
}//xeutf_fldl2f                                                    //~va00I~
//**************************************************************** //~va00I~
//!xeutf_getucsstr                                                 //~va00I~
//get ucs2 string from locale/utf8 str                             //~va00I~
//**************************************************************** //~va00I~
int xeutf_getucsstr(int Popt,char *Pinp,int Pinplen,char *Pout,int Poutbufflen,int *Ppoutlen)//~va00I~
{                                                                  //~va00I~
	UCHAR *putf8;                                                   //~va00R~//~va5wR~
	int opt,optle,rc,chklen,errctr,utflen;                         //~va00R~
//****************************                                     //~va00I~
    opt=UCVUCS_FULLREC|UCVUCS_ERRSTOP;                             //~va00I~
    optle=((Popt & XEUTFCVO_UCSLE)!=0)*UCVUCS_LE;                  //~va00I~
    opt|=optle;                                                    //~va00I~
    if (Popt & XEUTFCVO_RETALLASCII)                               //~va00I~
        opt|=UCVUCS_RETALLA;                                       //~va00I~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vavLR~
#ifdef UTF8UCS416                                                  //~vavLI~
  if (Popt & XEUTFCVO_UCS4)                                        //~vax1R~
    opt|=UCVUCS_UCS4;                                              //~va3xI~
#endif                                                             //~va3xI~
//  rc=ucvsutf2ucs(0/*errfunc*/,opt,Pinp,Pinplen,Pout,Poutbufflen,&chklen,Ppoutlen,&errctr);//~vb01R~
    rc=ucvsutf2ucs(0/*errfunc*/,(ULONG)opt,Pinp,Pinplen,Pout,Poutbufflen,&chklen,Ppoutlen,&errctr);//~vb01I~
    if (rc==UCVUCS_ALLASCII)                                       //~va00I~
        return XEUTFCVRC_ALLASCII;                                 //~va00I~
    if (!rc)                                                       //~va00I~
    	return 0;                                                  //~va00I~
//not all utf8(or all ascii)                                       //~va00I~
	opt=UTFCVO_STRZ;     //set last null                           //~va00I~
#ifdef UTF8UCS416                                                  //~vaw1I~
  if (Popt & XEUTFCVO_UCS4)                                        //~vax1R~
    opt|=UCVUCS_UCS4;                                              //~vaw1I~
#endif                                                             //~vaw1I~
	rc=xeutf_islocalestr(opt,Pinp,Pinplen,&putf8,&utflen);         //~va00I~
//  if (!rc)    //valid locale                                     //~va00I~//~vaw5R~
    if (rc==1)    //not ascii and not envu8                        //~vaw5I~
    {                                                              //~va00I~
    	opt=optle;                                                 //~va00I~
//  	ucvsutf2ucs(0/*errfunc*/,opt,putf8,utflen,Pout,Poutbufflen,&chklen,Ppoutlen,&errctr);//~vb01R~
    	ucvsutf2ucs(0/*errfunc*/,(ULONG)opt,putf8,utflen,Pout,Poutbufflen,&chklen,Ppoutlen,&errctr);//~vb01I~
        rc=0;                                                      //~vaw5I~
    }                                                              //~va00I~
    return rc;                                                     //~va00I~
}//xeutf_getucsstr;                                                //~va00I~
#ifdef UTF8UCS2                                                    //~va20I~
//**************************************************************** //~va20I~
//!xeutf_cvl2fbyct                                                 //~va5uR~
//get utf8 string from locale/utf8 mixed str using codetype tbl    //~va20R~
//input dbcstb may be 0 , then calc lclen by utf code              //~va5uI~
//rc:UALLOC_FAILED                                                 //~va20I~
//**************************************************************** //~va20I~
int xeutf_cvl2fbyct(int Popt,char *Pinp,int Pinplen,char *Pdbcs,char *Pcodetype,int Plclen,char *Pout,int Poutbuffsz,int *Ppoutlen)//~va20R~
{                                                                  //~va20I~
	UCHAR *pc,*pcd,*pct,*pctn,*pu8,*pu8w;                           //~va20R~//~va5wR~
	int len,opt,rc2=0,lclen,resleno,reslenlc,reslenu8,outlen,ch,u8len;//~vaf9R~
    ULONG ucs;                                                     //~va5uI~
    int opt2,swchkbyf2l;                                           //~vawjI~
//****************************                                     //~va20I~
	swchkbyf2l=Popt & XEUTFL2FBCO_CHKLCLENBYF2L;   //advance ct by the length of F2L outlen//~vawjI~
    UTRACEP("xeutf_cvl2fbyct opt=%x\n",Popt);                      //~vaaqI~
    UTRACED("xeutf_cvl2fbyct data",Pinp,Pinplen);                  //~vaaqI~
    UTRACED("xeutf_cvl2fbyct dbcs",Pdbcs,Plclen);                  //~vaaqI~
    UTRACED("xeutf_cvl2fbyct codet",Pcodetype,Plclen);             //~vaaqR~
    for(reslenu8=Pinplen,reslenlc=Plclen,resleno=Poutbuffsz,pct=Pcodetype,pc=Pinp,pcd=Pdbcs,pu8=Pout;//~va20R~
			reslenlc>0&&reslenu8>0&&resleno>0;                     //~va20I~
		)                                                          //~va20I~
    {                                                              //~va20I~
    	rc2=0;                                                     //~va20I~
//search on pct                                                    //~va5nI~
        pctn=memchr(pct,XEUTFCT_UTF8,(UINT)reslenlc);              //~va20R~
        if (pctn)                                                  //~va20I~
//      	lclen=(int)((ULONG)pctn-(ULONG)pct);                   //~va20I~//~vafkR~
        	lclen=(int)((ULPTR)pctn-(ULPTR)pct);                   //~vafkI~
        else                                                       //~va20I~
        	lclen=reslenlc;                                        //~va20R~
        if (lclen)   //locale strlen                               //~va20R~
        {                                                          //~va20I~
        	opt=0;                                                 //~va20I~
            lclen=min(reslenu8,lclen);  //protect 0c4 when short pu8//~va5wI~
			rc2=xeutf_islocalestr(opt,pc,lclen,&pu8w,&u8len);      //~va20I~
            if (rc2>=4)                                            //~va20I~
            	break;                                             //~va20I~
            pc+=lclen;                                             //~va20R~
            pcd+=lclen;                                            //~va20R~
            pct+=lclen;                                            //~va20R~
            reslenlc-=lclen;                                       //~va20R~
            reslenu8-=lclen;                                       //~va20R~
            len=min(resleno,u8len);                                //~va20I~
            memcpy(pu8,pu8w,(UINT)len);                            //~va20I~
            pu8+=len;                                              //~va20I~
            resleno-=len;                                          //~va20I~
            if (!pctn)                                             //~va20I~
            	break;                                             //~va20I~
        }                                                          //~va20I~
        for (;*pct==XEUTFCT_UTF8 && reslenlc>0 && reslenu8>0 && resleno>0;)//~va20I~
        {                                                          //~va20I~
        	ch=*pc;                                                //~va20I~
        	u8len=UTF8CHARLEN(ch);                                 //~va20R~
            if (!u8len)                                            //~va20R~
            {                                                      //~va20I~
            	rc2=4;                                             //~va20I~
            	break;                                             //~va20I~
            }                                                      //~va20I~
         if (swchkbyf2l)                                           //~vawjI~
         {                                                         //~vawjI~
         	char wklc[MAX_MBCSLENLC];                              //~vawjI~
            int chklen;                                            //~vawjI~
    		opt2=(UTFCVO_ASCIIRET|UTFCVO_ERRREP)|(XEUTF_ERRREPCH_F2LFILE<<8);	//return if translation err//~vawjI~
    		if (utfcvf2l(opt2,wklc,pc,u8len,&chklen,&lclen,0/*Ppcharwidth*/)>UTFCVRC_ERR)//UTFCVRC_ERR is errrep case//~vawjR~
                lclen=1;                                           //~vawjI~
         }                                                         //~vawjI~
         else                                                      //~vawjI~
         if (Pdbcs)                                                //~va5uI~
         {                                                         //~va5uI~
          if (UDBCSCHK_DBCS1STLU(*pcd))                            //~va5nI~
            lclen=XESUB_DBCSSPLITCTR(Pdbcs,Plclen,Plclen-reslenlc/*pos*/);//~va20R~
          else                                                     //~va5nI~
          	lclen=1;                                               //~va5nI~
         }                                                         //~va5uI~
         else                                                      //~va5uI~
         {                                                         //~va5uI~
         	utfgetwcw(0,pc,u8len,&ucs,0/*chklen*/,&lclen);         //~va5uI~
         }                                                         //~va5uI~
            len=min(resleno,u8len);                                //~va20M~
            memcpy(pu8,pc,(UINT)len);                              //~va20M~
            pu8+=len;                                              //~va20M~
            resleno-=len;                                          //~va20M~
            pc+=u8len;                                             //~va20R~
            pcd+=lclen;                                            //~va20R~
            pct+=lclen;                                            //~va20R~
            reslenlc-=lclen;                                       //~va20R~
            reslenu8-=u8len;                                       //~va20I~
        }                                                          //~va20I~
        if (rc2>=4)                                                //~va20R~
        	break;                                                 //~va20I~
    }                                                              //~va20I~
//  outlen=(int)((ULONG)pu8-(ULONG)Pout);                          //~va20R~//~vafkR~
    outlen=(int)((ULPTR)pu8-(ULPTR)Pout);                          //~vafkI~
    if (Ppoutlen)                                                  //~va20I~
    	*Ppoutlen=outlen;                                          //~va20I~
    UTRACED("xeutf_cvl2fbyct out",Pout,outlen);                    //~vaaqI~
    if (rc2>=4)                                                    //~va20R~
    	return 4;                                                  //~va20M~
    return 0;                                                      //~va20I~
}//xeutf_cvl2fbyct                                                 //~va20R~
//**************************************************************** //~va5wI~
//!xeutf_cvf2lbyct                                                 //~va5wI~
//get locale string from locale/utf8 mixed str using codetype tbl  //~va5wI~
//input dbcstb may be 0 , then calc lclen by utf code              //~va5wI~
//rc:1:utf8 code detected,4:err                                    //~va5wI~
//**************************************************************** //~va5wI~
int xeutf_cvlf2lbyct(int Popt,char *Pinp,int Pinplen,char *Pcodetype,int Plclen,char *Pout,int Poutbuffsz,int *Ppoutlen)//~va5wR~
{                                                                  //~va5wI~
	char *pc,*pct,*pctn,*pco,rc=0;                                 //~va5wR~
	int len,opt,rc2=0,lclen,resleno,reslenct,reslenu8,outlen,ch,u8len;//~vaf8R~
    char wklc[MAX_MBCSLEN];                                        //~va5wI~
//****************************                                     //~va5wI~
    for(reslenu8=Pinplen,reslenct=Plclen,resleno=Poutbuffsz,pct=Pcodetype,pc=Pinp,pco=Pout;//~va5wR~
			reslenct>0&&reslenu8>0&&resleno>0;                     //~va5wR~
		)                                                          //~va5wI~
    {                                                              //~va5wI~
    	rc2=0;                                                     //~va5wI~
        pctn=memchr(pct,XEUTFCT_UTF8,(UINT)reslenct);              //~va5wR~
        if (pctn)                                                  //~va5wI~
//      	lclen=(int)((ULONG)pctn-(ULONG)pct);                   //~va5wI~//~vafkR~
        	lclen=(int)((ULPTR)pctn-(ULPTR)pct);                   //~vafkI~
        else                                                       //~va5wI~
        	lclen=reslenct;                                        //~va5wR~
        if (lclen)   //locale strlen                               //~va5wI~
        {                                                          //~va5wI~
            len=min(resleno,lclen);                                //~va5wI~
            memcpy(pco,pc,(UINT)len);                              //~va5wI~
            pc+=len;                                               //~va5wI~
            pct+=len;                                              //~va5wI~
            pco+=len;                                              //~va5wI~
            resleno-=len;                                          //~va5wI~
            reslenct-=len;                                         //~va5wI~
            reslenu8-=len;                                         //~va5wI~
            if (!pctn)                                             //~va5wI~
            	break;                                             //~va5wI~
        }                                                          //~va5wI~
        rc|=1;		//utf8 found                                   //~va5wI~
        for (;*pct==XEUTFCT_UTF8 && reslenct>0 && reslenu8>0 && resleno>0;)//~va5wI~
        {                                                          //~va5wI~
        	ch=*pc;                                                //~va5wI~
        	u8len=UTF8CHARLEN(ch);                                 //~va5wI~
            if (!u8len)                                            //~va5wI~
            {                                                      //~va5wI~
            	rc2=4;                                             //~va5wI~
            	break;                                             //~va5wI~
            }                                                      //~va5wI~
    		opt=UTFCVO_ERRREP|(XEUTF_ERRREPCH_F2LFILE<<8);  //doubled "?" for err dbcs//~va5wR~
    		rc2=utfcvf2l(opt,wklc,pc,u8len,0/*chklen*/,&lclen,0/*Ppcharwidth*/);//~va5wI~
        	if (rc2==UTFCVRC_ERR)                         //~va5wI~//~va5HR~
                rc2=0;                                             //~va5HI~
        	if (rc2)                                               //~va5HI~
            {	                                                   //~va5wI~
            	rc2=4;                                             //~va5wI~
        		break;                                             //~va5wI~
            }                                                      //~va5wI~
            len=min(resleno,lclen);                                //~va5wI~
            memcpy(pco,wklc,(UINT)len);                            //~va5wI~
            pc+=u8len;                                             //~va5wI~
            pct+=lclen;                                            //~va5wI~
            pco+=len;                                              //~va5wI~
            reslenu8-=u8len;                                       //~va5wR~
            reslenct-=lclen;                                       //~va5wI~
            resleno-=len;                                          //~va5wI~
        }                                                          //~va5wI~
        if (rc2>=4)                                                //~va5wI~
        {                                                          //~va5wI~
        	rc=4;                                                  //~va5wI~
        	break;                                                 //~va5wI~
        }                                                          //~va5wI~
    }                                                              //~va5wI~
//  outlen=(int)((ULONG)pco-(ULONG)Pout);                          //~va5wI~//~vafkR~
    outlen=(int)((ULPTR)pco-(ULPTR)Pout);                          //~vafkI~
    *pco++=0;                                                      //~va5wR~
    if (Ppoutlen)                                                  //~va5wI~
    	*Ppoutlen=outlen;                                          //~va5wI~
    if (rc2>=4)                                                    //~va5wI~
    	return 4;                                                  //~va5wI~
    return rc;                                                     //~va5wR~
}//xeutf_cvlf2lbyct                                                //~va5wI~
//#ifdef LNX                                                         //~vauaI~//~vavpR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaI~//~vavpI~
//**************************************************************** //~vauaI~
//!xeutf_cvf2lbyctDDW                                              //~vauaI~
//get locale string from locale/utf8 mixed str using codetype tbl  //~vauaI~
//input dbcstb may be 0 , then calc lclen by utf code              //~vauaI~
//codetypetbl by mean of ddfmt width for utf8                      //~vauaI~
//rc:1:utf8 code detected,4:err                                    //~vauaI~
//**************************************************************** //~vauaI~
int xeutf_cvlf2lbyctDDW(int Popt,char *Pinp,int Pinplen,char *Pcodetype,int Plclen,char *Pout,int Poutbuffsz,int *Ppoutlen)//~vauaI~
{                                                                  //~vauaI~
	char *pc,*pct,*pco,rc=0;                                       //~vauaR~
	int len,opt,rc2=0,lclen,resleno,reslenct,reslenu8,outlen,ch,u8len;//~vauaI~
    char wklc[MAX_MBCSLEN];                                        //~vauaI~
//****************************                                     //~vauaI~
    UTRACEP("xeutf_cvlf2lbyctDDW outbuffsz=%d\n",Poutbuffsz);      //~vauaI~
    UTRACED("u8",Pinp,Pinplen);                                    //~vauaI~
    UTRACED("ct",Pcodetype,Plclen);                                //~vauaI~
    for(reslenu8=Pinplen,reslenct=Plclen,resleno=Poutbuffsz,pct=Pcodetype,pc=Pinp,pco=Pout;//~vauaI~
			reslenct>0&&reslenu8>0&&resleno>0;                     //~vauaI~
		)                                                          //~vauaI~
    {                                                              //~vauaI~
        ch=*pc;                                                    //~vauaI~
    	if (UTF8ISASCII(ch)                                        //~vauaI~
        ||  *pct==XEUTFCT_LC)                                      //~vauaI~
        {                                                          //~vauaI~
            *pco++=*pc++;                                          //~vauaI~
            pct++;                                                 //~vauaI~
            reslenu8--;                                            //~vauaI~
            reslenct--;                                            //~vauaR~
            resleno--;                                             //~vauaI~
            continue;                                              //~vauaI~
        }                                                          //~vauaI~
    	rc2=0;                                                     //~vauaI~
        rc|=1;		//utf8 found                                   //~vauaI~
        u8len=UTF8CHARLEN(ch);                                     //~vauaR~
        if (u8len>reslenu8)                                        //~vauaR~
        {                                                          //~vauaR~
            rc2=4;                                                 //~vauaR~
            break;                                                 //~vauaR~
        }                                                          //~vauaR~
        opt=0;                                                     //~vauaR~
        xeutfcvf2lDDW(opt,pc,u8len,wklc,sizeof(wklc),&lclen);      //~vauaR~
        len=min(resleno,lclen);                                    //~vauaR~
        memcpy(pco,wklc,(UINT)len);                                //~vauaR~
        pc+=u8len;                                                 //~vauaR~
        pct+=lclen;                                                //~vauaR~
        pco+=len;                                                  //~vauaR~
        reslenu8-=u8len;                                           //~vauaR~
        reslenct-=lclen;                                           //~vauaR~
        resleno-=len;                                              //~vauaR~
    }                                                              //~vauaI~
    outlen=(int)((ULPTR)pco-(ULPTR)Pout);                          //~vauaI~
    UTRACED("out lc",Pout,outlen);                                 //~vauaM~
    *pco++=0;                                                      //~vauaI~
    if (Ppoutlen)                                                  //~vauaI~
    	*Ppoutlen=outlen;                                          //~vauaI~
    if (rc2>=4)                                                    //~vauaM~
    	rc=4;                                                      //~vauaI~
    UTRACEP("xeutf_cvlf2lbyctDDW rc=%d\n",rc);                     //~vauaM~
    return rc;                                                     //~vauaI~
}//xeutf_cvlf2lbyctDDW                                             //~vauaI~
#endif	//LNX                                                      //~vauaI~
//#ifdef AAA                                                         //~vak5I~//~vau2R~
//**************************************************************** //~vaaqI~
//!xeutf_strlenu8byct                                              //~vaaqI~
//get utf8 string length by ct                                     //~vaaqI~
//Pdbcs my be null                                                 //~vau2I~
//rc:4:utf8 fmt err                                                //~vaaqI~
//**************************************************************** //~vaaqI~
int xeutf_strlenu8byct(int Popt,char *Pinp,int Pinplen,char *Pdbcs,char *Pcodetb,int Plclen,int *Ppu8len,int *Pplclen)//~vaaqR~
{                                                                  //~vaaqI~
	char *pc,*pct,*pcd,rc=0;                                       //~vaaqR~
	int lclen=0,reslenlc,reslenu8,u8len=0,codetype;                //~vaumR~
//    char wkdd[4],wkdbcs[4];;                                       //~vau2I~//~vbkaR~
    char wkdd[4],wkdbcs[4];;                                       //~vbkbI~
//    char wklc[MAX_MBCSLEN];                                        //~vbkaI~//~vbkbR~
//****************************                                     //~vaaqI~
	UTRACED("xeutf_strlenu8byct data",Pinp,Pinplen);               //~vaaqR~
	UTRACED("xeutf_strlenu8byct dbcs",Pdbcs,Plclen);               //~vaaqR~
	UTRACED("xeutf_strlenu8byct codetb",Pcodetb,Plclen);           //~vaaqR~
    for(reslenu8=Pinplen,reslenlc=Plclen,pct=Pcodetb,pc=Pinp,pcd=Pdbcs;//~vaaqR~
            reslenlc>0 && reslenu8>0;                              //~vaaqR~
//          pc+=u8len,pct+=lclen,pcd+=lclen,reslenu8-=u8len,reslenlc-=lclen//~vaaqR~//~vau2R~
            pc+=u8len,pct+=lclen,                                  //~vau2I~
            pcd+=(Pdbcs?lclen:0),                                  //~vau2R~
            reslenu8-=u8len,reslenlc-=lclen                        //~vau2I~
        )                                                          //~vaaqI~
    {                                                              //~vaaqI~
    	codetype=*pct;                                             //~vaaqI~
    	if (codetype==XEUTFCT_LC)                                  //~vaaqI~
        	break;                                                 //~vaaqI~
        if (codetype==XEUTFCT_UTF8)                                //~vaaqI~
        {                                                          //~vaaqI~
            u8len=UTF8CHARLEN(*pc);                                //~vaaqI~
            if (!u8len)                                            //~vaaqI~
            {                                                      //~vaaqI~
                rc=4;                                              //~vaumR~
                break;                                             //~vaaqI~
            }                                                      //~vaaqI~
//          if (UDBCSCHK_DBCS1STU(*pcd))                           //~vaaqR~//~vau2R~
//          	lclen=2;                                           //~vaaqI~//~vau2R~
          if (Pdbcs)	//dbcs parm                                //~vau2R~
          {                                                        //~vau2I~
            if (*pcd)  //dbcstbl is by lc                          //~vau2I~
            	lclen=XESUB_DBCSSPLITCTR(pcd,reslenlc,0/*pos from pcd*/);//~vau2R~
            else                                                   //~vaaqI~
            	lclen=1;                                           //~vaaqI~
          }                                                        //~vau2I~
          else                                                     //~vau2I~
          {                                                        //~vau2I~
//        	utfcvf2dd(0,pc,u8len,wkdd,wkdbcs,sizeof(wkdd),&lclen); //~vau2I~//~vbkaR~
//  		xeutfcvf2lDDW(0,pc,u8len,wklc,sizeof(wklc),&lclen);    //~vbkbR~
          	utfcvf2dd(0,pc,u8len,wkdd,wkdbcs,sizeof(wkdd),&lclen); //~vbkbR~
            if (!lclen)                                            //~vau2I~
	          	lclen=1;                                           //~vau2I~
          }                                                        //~vau2I~
        }                                                          //~vaaqI~
        else	//ascii                                            //~vaaqI~
        {                                                          //~vaaqI~
        	u8len=1;                                               //~vaaqI~
        	lclen=1;                                               //~vaaqI~
        }                                                          //~vaaqI~
    }                                                              //~vaaqI~
//  u8len=(int)((ULONG)pc-(ULONG)Pinp);                            //~vaaqI~//~vafkR~
    u8len=(int)((ULPTR)pc-(ULPTR)Pinp);                            //~vafkI~
//  lclen=(int)((ULONG)pct-(ULONG)Pcodetb);                        //~vaaqR~//~vafkR~
    lclen=(int)((ULPTR)pct-(ULPTR)Pcodetb);                        //~vafkI~
    *Ppu8len=u8len;                                                //~vaaqI~
    *Pplclen=lclen;                                                //~vaaqI~
	UTRACEP("xeutf_strlenu8byct inplen=%d,inplclen=%d,outu8len=%d,outlclen=%d\n",Pinplen,Plclen,u8len,lclen);//~vaaqR~
    return rc;                                                     //~vaaqI~
}//xeutf_strlenu8byct                                              //~vaaqR~
//#endif                                                             //~vak5I~//~vau2R~
//**************************************************************** //~vaaqI~
//!xeutf_strlenu8byct                                              //~vaaqI~
//get utf8/ascii string length by ct                               //~vaaqR~
//rc:utf8 code len                                                 //~vamCR~
//**************************************************************** //~vaaqI~
int xeutf_strwidthu8byct(int Popt,char *Pcodetb,int Pctlen)        //~vaaqR~
{                                                                  //~vaaqI~
	char *pct;                                                     //~vaaqI~
	int reslenct,ctlen;                                            //~vaaqR~
//****************************                                     //~vaaqI~
	UTRACED("xeutf_strwidthu8byct codetb",Pcodetb,Pctlen);         //~vaaqR~
    for(reslenct=Pctlen,pct=Pcodetb;reslenct>0;pct++,reslenct--)   //~vaaqR~
    {                                                              //~vaaqI~
    	if (*pct==XEUTFCT_LC)                                      //~vaaqI~
        	break;                                                 //~vaaqI~
    }                                                              //~vaaqI~
    ctlen=Pctlen-reslenct;                                         //~vaaqI~
	UTRACEP("xeutf_strwidthh8byct inpctlen=%d,outctlen=%d\n",Pctlen,ctlen);//~vaaqR~
    return ctlen;                                                  //~vaaqR~
}//xeutf_strwidthu8byct                                            //~vaaqI~
//**************************************************************** //~vaaqI~
//!xeutf_strlenlcbyct                                              //~vaaqI~
//get locale dbcs string length by ct                              //~vaaqR~
//rc:4:utf8 fmt err                                                //~vaaqI~
//**************************************************************** //~vaaqI~
int xeutf_strwidthlcbyct(int Popt,char *Pcodetb,int Pctlen)        //~vaaqI~
{                                                                  //~vaaqI~
	char *pct;                                                     //~vaaqI~
	int reslenct,ctlen;                                            //~vaaqI~
//****************************                                     //~vaaqI~
	UTRACED("xeutf_strwidthlcbyct codetb",Pcodetb,Pctlen);         //~vaaqI~
    for(reslenct=Pctlen,pct=Pcodetb;reslenct>0;pct++,reslenct--)   //~vaaqI~
    {                                                              //~vaaqI~
    	if (*pct!=XEUTFCT_LC)                                      //~vaaqR~
        	break;                                                 //~vaaqI~
    }                                                              //~vaaqI~
    ctlen=Pctlen-reslenct;                                         //~vaaqI~
	UTRACEP("xeutf_strwidthh8byct inpctlen=%d,outctlen=%d\n",Pctlen,ctlen);//~vaaqI~
    return ctlen;                                                  //~vaaqI~
}//xeutf_strwidthlcbyct                                            //~vaaqI~
#endif                                                             //~va20I~
//**************************************************               //~va00I~
//replace split dbcs                                               //~va00I~
//tgtutf8len:replaced if split occures                             //~va00I~
//rc:1:split done,4:pos is outof range                             //~va00I~
//**************************************************               //~va00I~
int xeutf_dbcssplit(int Popt,char *Plc,char *Putf8,char *Pcodetype,char *Pdbcs,int Ppos,int *Pputf8len,int *Pputf8offs)//~va00I~
{                                                                  //~va00I~
    int ch,utf8chsz,utf8inplen,utf8offs,rc,len;                    //~va00R~
    int codetype;                                                  //~va0MI~
    char *pc;                                                      //~va00R~
//****************************                                     //~va00I~
    if (!(utf8inplen=*Pputf8len))                                  //~va00I~
//      utf8inplen=strlen(Putf8);                                  //~vb01R~
        utf8inplen=(int)strlen(Putf8);                             //~vb01I~
	if (Pputf8offs)                                                //~va00I~
    	*Pputf8offs=0;                                             //~va00I~
	if (Ppos<0)                                                    //~va00R~
    	return 4;                                                  //~va00R~
	if (Ppos==0)                                                   //~va00I~
    	return 0;                                                  //~va00I~
	rc=utfpos2offs(0,Putf8,Pdbcs,Pcodetype,Ppos,utf8inplen,&utf8offs);//~va00R~
UTRACEP("xeutf_dbcssplit rc=%d,pos=%d,offs=%d\n",rc,Ppos,utf8offs);//~va00I~
	if (Pputf8offs)                                                //~va00I~
    	*Pputf8offs=utf8offs;                                      //~va00R~
    if (rc!=1)	//not dbcs split                                   //~va00I~
    	return rc;                                                 //~va00I~
	if (Pputf8offs)                                                //~va00I~
    	*Pputf8offs=utf8offs+1;	//pos on 2nd byte replaced to space//~va00R~
    pc=Plc+Ppos-1;                                                 //~va00I~
//!ebc                                                             //~va50I~
    *pc++=' ';                                                     //~va00I~
    *pc=' ';                                                       //~va00I~
    pc=Pdbcs+Ppos-1;                                               //~va00I~
    *pc++=0;                                                       //~va00I~
    *pc=0;                                                         //~va00I~
    pc=Pcodetype+Ppos-1;                                           //~va00I~
    codetype=*pc;                                                  //~va0MI~
    *pc++=XEUTFCT_ASCII;                                           //~va00I~
    *pc=XEUTFCT_ASCII;                                             //~va00I~
    pc=Putf8+utf8offs;                                             //~va00I~
    ch=*pc;                                                        //~va00I~
    utf8chsz=UTF8CHARLEN(ch);                                      //~va00M~
//!ebc                                                             //~va50I~
    *pc++=' ';                                                     //~va00I~
    *pc++=' ';                                                     //~va00I~
//if (codetype==XEUTFCT_UTF8)                                      //~va0MI~//~va5wR~
  if (codetype==XEUTFCT_UTF8 && utf8chsz>2)	//protect abend when code table corrupted case//~va5wR~
  {                                                                //~va0MI~
    len=utf8inplen-utf8offs-utf8chsz;                              //~va00I~
    memcpy(pc,pc+utf8chsz-2,(UINT)len);                            //~va00R~
    *Pputf8len=utf8inplen+2-utf8chsz;                              //~va00R~
//  if (Popt & XEUTFDSO_STRZ)                                      //~va00I~//~va0LR~
//  {                                                              //~va0LR~
//      *(pc+len)=0;                                               //~va00I~//~va0LR~
//  }                                                              //~va0LR~
//   memset(pc+len,0,utf8chsz-2);                                  //~vb01R~
     memset(pc+len,0,(size_t)(utf8chsz-2));                        //~vb01I~
   }                                                               //~va0MI~
UTRACED("out utf8",Putf8,*Pputf8len);                              //~va00R~
    return 1;                                                      //~va00I~
}//xeutf_dbcssplit                                                 //~va00I~
//**************************************************               //~va00I~
//manipulate mixed string                                          //~va00I~
//len:input,if <0,get by strlen                                    //~va00I~
//*dbcstbl:input                                                   //~va00I~
//*codetype:input/output                                           //~va00I~
//*utf8str:input/output                                            //~va00I~
//rc:UALLOC_FAILED,4:pos out of range                              //~va00R~
//**************************************************               //~va00I~
int xeutf_mixedstrupdate(int Popt,char *Ptgtlc,char *Ptgtutf8,char *Ptgtcodetype,char *Ptgtdbcs,int Ptgtlclen,int *Pptgtlclen,int *Pptgtutf8len,//~va00R~
							int Ptgtpos,int Ptgtwidth,             //~va00I~
							char *Psrclc,char *Psrcutf8,char *Psrccodetype,char *Psrcdbcs,int Psrclclen,int Psrcutf8len,int Psrcutf8buffsz)//~va00R~
{                                                                  //~va00I~
    int srclclen,tgtlclen,tgtutf8len,srcutf8len,overwraplen,rc2;   //~va00R~
    int utf8offs1=0,utf8offs2=0,pos,expandlen,len,lenutf8,width;   //~va00R~
    int strzsw,cutlen,cutlenutf8,opt,srclcwklen;                   //~va00R~
    char *tgtlc,*tgtcodetype,*tgtdbcs,*tgtutf8,*srclc,*srclcwk;    //~va00R~
    char *srcdbcs,*srccodetype,*srcdbcswk,*srccodetypewk;          //~va1fI~
//****************************                                     //~va00I~
	width=Ptgtwidth;                                               //~va00I~
    srclc=Psrclc;                                                  //~va00I~
    if (Popt & XEUTFMSUO_STRZ)                                     //~va00I~
    	width--;                                                   //~va00I~
    if (Ptgtpos>=width)                                            //~va00I~
    	return 4;		//out of field width                       //~va00I~
	if (tgtlclen=Ptgtlclen,tgtlclen<0)                             //~va00R~
		tgtlclen=(int)strlen(Ptgtlc);    	                       //~va00I~
	if (srclclen=Psrclclen,srclclen<0)                             //~va00R~
		srclclen=(int)strlen(srclc);                               //~va00R~
    if (!*Ptgtutf8 && tgtlclen)    //not yet evaluated codetype    //~va00R~
    {                                                              //~va00I~
    	opt=XEUTFCVO_SETCT;  //setup utf8/codetype even when no utf8 contains//~va00I~
		rc2=xeutf_fldl2f(opt,Ptgtlc,Ptgtdbcs,0/*wk*/,tgtlclen,Ptgtcodetype,Ptgtutf8,&tgtutf8len);//~va00R~
        if (rc2==UALLOC_FAILED)                                    //~va00I~
        	return rc2;                                            //~va00I~
    }                                                              //~va00I~
    else                                                           //~va00I~
    {                                                              //~va00I~
    	if (!tgtlclen)                                             //~va00I~
        	tgtutf8len=0;                                          //~va00I~
        else                                                       //~va00I~
    	if (!Pptgtutf8len)                                         //~va00R~
    		tgtutf8len=(int)strlen(Ptgtutf8);                      //~va00I~
        else                                                       //~va00I~
    	if (tgtutf8len=*Pptgtutf8len,tgtutf8len<0)                 //~va00I~
    		tgtutf8len=(int)strlen(Ptgtutf8);                      //~va00R~
    }                                                              //~va00I~
    srcdbcs=Psrcdbcs;                                              //~va1fI~
    srccodetype=Psrccodetype;                                      //~va1fI~
    if (!*Psrcutf8 && srclclen)    //not yet evaluated codetype    //~va00R~
    {                                                              //~va00I~
#ifdef AAA                                                         //~va00R~
    	opt=XEUTFCVO_SETCT;  //setup utf8/codetype even when no utf8 contains//~va00I~
		rc2=xeutf_fldl2f(opt,Psrclc,Psrcdbcs,0/*wk*/,srclclen,Psrccodetype,Psrcutf8,&srcutf8len);//~va00R~
        if (rc2==UALLOC_FAILED)                                    //~va00I~
        	return rc2;                                            //~va00I~
#else                                                              //~va00I~
//  	srclcwk=xeutf_buffget(XEUTF_BUFFMULC,srclclen+1); //get buff for f2l//~va1cR~
//  	srclcwk=xeutf_buffget(XEUTF_BUFFMULC,srclclen*UTF8_F2LMAXRATE+1); //get buff for f2l//~va1cR~//~va1fR~
    	srclcwk=xeutf_buffget(XEUTF_BUFFMULC,(srclclen*UTF8_F2LMAXRATE+1)*3); //get buff for f2l//~va1fI~
        srcdbcswk=srclcwk+(srclclen*UTF8_F2LMAXRATE+1); //for update by getmixedstr//~va1fI~
        srccodetypewk=srcdbcswk+(srclclen*UTF8_F2LMAXRATE+1); //for update//~va1fR~
		UALLOCCHK(srclcwk,UALLOC_FAILED);                          //~va00I~
        opt=XEUTFGLSMO_KEEPLC; //output source locale code to Poututf8//~va00I~
//  	rc2=xeutf_getmixedstr(opt,srclc,srclclen,srclcwk,Psrcdbcs,Psrccodetype,srclclen+1,&srclcwklen,//~va00R~//~va1fR~
//#ifdef LNX                                                         //~vaumI~//~vavaR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaI~
    	opt|=XEUTFGLSMO_LCWIDTHBYDDWIDTH;                          //~vaumI~
#endif                                                             //~vaumI~
		if (Popt & XEUTFMSUO_UTF8)                                 //~vauDI~
        	opt|=XEUTFGLSMO_UTF8;                                  //~vauDI~
        else                                                       //~vauDI~
		if (Popt & XEUTFMSUO_LC)                                   //~vauDI~
        	opt|=XEUTFGLSMO_LC;                                    //~vauDI~
		rc2=xeutf_getmixedstr(opt,srclc,srclclen,srclcwk,srcdbcswk,srccodetypewk,srclclen+1,&srclcwklen,//~va1fI~
                        	Psrcutf8,Psrcutf8buffsz,&srcutf8len);  //~va00I~
		if (rc2 & XEUTFGU8MRC_UTF8)	//contains utf8 coed           //~va00I~
        {                                                          //~va00I~
        	srclc=srclcwk;                                         //~va00I~
            srclclen=srclcwklen;	                               //~va00R~
        }	                                                       //~va00I~
        srcdbcs=srcdbcswk;                                         //~va1fI~
        srccodetype=srccodetypewk;                                 //~va1fI~
#endif                                                             //~va00I~
    }                                                              //~va00I~
    else                                                           //~va00I~
    {                                                              //~va00I~
    	if (srcutf8len=Psrcutf8len,srcutf8len<0)                   //~va00I~
    		srcutf8len=(int)strlen(Psrcutf8);                      //~va00I~
    }                                                              //~va00I~
UTRACEP("xeutf_mixedstrupdate in lclen=%d,utf8len=%d,srclclen=%d,srcutf8len=%d,pos=%d\n",tgtlclen,tgtutf8len,srclclen,srcutf8len,Ptgtpos);//~va00M~
UTRACED("tgtLC",Ptgtlc,tgtlclen);                                  //~va00M~
UTRACED("tgtCODETYPE",Ptgtcodetype,tgtlclen);                      //~va00M~
UTRACED("tgtDBCS",Ptgtdbcs,tgtlclen);                              //~va00M~
UTRACED("tgtUTF8",Ptgtutf8,tgtutf8len);                            //~va00M~
UTRACED("srcLC",srclc,srclclen);                                   //~va00R~
UTRACED("srcCODETYPE",srccodetype,srclclen);                      //~va00M~//~va1fR~
UTRACED("srcDBCS",srcdbcs,srclclen);                              //~va00M~//~va1fR~
UTRACED("srcUTF8",Psrcutf8,srcutf8len);                            //~va00M~
    tgtlc=Ptgtlc+Ptgtpos;                                          //~va00I~
    tgtdbcs=Ptgtdbcs+Ptgtpos;                                      //~va00R~
    tgtcodetype=Ptgtcodetype+Ptgtpos;                              //~va00I~
    overwraplen=tgtlclen-Ptgtpos;                                  //~va00I~
    strzsw=1;                                                      //~va00I~
    if (overwraplen<=0)	//append case                              //~va00I~
    {                                                              //~va00I~
    	overwraplen=-overwraplen;                                  //~va00I~
	    tgtutf8=Ptgtutf8+tgtutf8len;                               //~va00I~
        if (overwraplen)                                           //~va00R~
        {                                                          //~va00I~
//*!ebc                                                            //~va50I~
            memset(tgtlc-overwraplen,' ',(UINT)overwraplen);       //~va00R~
            memset(tgtdbcs-overwraplen,0,(UINT)overwraplen);       //~va00R~
            memset(tgtcodetype-overwraplen,XEUTFCT_ASCII,(UINT)overwraplen);//~va00R~
//*!ebc                                                            //~va50I~
            memset(tgtutf8,' ',(UINT)overwraplen);                 //~va00R~
            tgtutf8+=overwraplen;                                  //~va00R~
        }                                                          //~va00I~
        tgtlclen+=overwraplen+srclclen;                            //~va00M~
        tgtutf8len+=overwraplen+srcutf8len;                        //~va00I~
    }                                                              //~va00I~
    else                                                           //~va00I~
    {                                                              //~va00I~
        if (Ptgtpos)                                               //~va00I~
    		xeutf_dbcssplit(0,Ptgtlc,Ptgtutf8,Ptgtcodetype,Ptgtdbcs,Ptgtpos,&tgtutf8len,&utf8offs1);	//rep by space if dbcs is split//~va00R~
        tgtutf8=Ptgtutf8+utf8offs1;                                //~va00I~
    	if (Popt & XEUTFMSUO_INS)                                  //~va00I~
        {                                                          //~va00I~
        	cutlen=cutlenutf8=0;                                   //~va00I~
        	if (Ptgtpos+srclclen<width) 	//remains to be shift  //~va00I~
            {                                                      //~va00I~
                len=tgtlclen-Ptgtpos;   //right half               //~va00I~
                if (tgtlclen+srclclen>width)	//overflow by shift//~va00I~
                {                                                  //~va00I~
                	cutlen=tgtlclen+srclclen-width;                //~va00I~
                	len-=cutlen;                                   //~va00I~
                }                                                  //~va00I~
                if (len>0)                                         //~va00I~
                {                                                  //~va00I~
                	memmove(tgtlc+srclclen,tgtlc,(UINT)len);       //~va00R~
                	memmove(tgtdbcs+srclclen,tgtdbcs,(UINT)len);   //~va00R~
                	memmove(tgtcodetype+srclclen,tgtcodetype,(UINT)len);//~va00R~
                }                                                  //~va00I~
    			if (Popt & XEUTFMSUO_STRZ)                         //~va00M~
	                *(tgtlc+srclclen+len)=0;                       //~va00M~
                lenutf8=tgtutf8len-utf8offs1;                      //~va00I~
                if (cutlen)                                        //~va00I~
                {                                                  //~va00I~
                	utfpos2offs(0,Ptgtutf8,Ptgtdbcs,Ptgtcodetype,Ptgtpos+len,tgtutf8len,&utf8offs2);//~va00R~
	                cutlenutf8=tgtutf8len-utf8offs2;               //~va00I~
                }                                                  //~va00I~
                memmove(tgtutf8+srcutf8len,tgtutf8,(UINT)lenutf8); //~va00I~
    			if (Popt & XEUTFMSUO_STRZ)                         //~va00I~
	                *(tgtutf8+srcutf8len+lenutf8)=0;               //~va00I~
                strzsw=0;                                          //~va00I~
            }                                                      //~va00I~
            tgtlclen+=srclclen;                                    //~va00R~
            tgtutf8len+=srcutf8len;                                //~va00I~
            tgtlclen-=cutlen;                                      //~va00I~
            tgtutf8len-=cutlenutf8;                                //~va00I~
        }                                                          //~va00I~
        else	//override                                         //~va00R~
        {                                                          //~va00I~
        	pos=Ptgtpos+srclclen; //right end                      //~va00R~
            if (pos<tgtlclen)	//in the fld width                 //~va00I~
            {                                                      //~va00I~
            	if (pos)                                           //~va00I~
		    		xeutf_dbcssplit(0,Ptgtlc,Ptgtutf8,Ptgtcodetype,Ptgtdbcs,pos,&tgtutf8len,&utf8offs2);	//rep by space if dbcs is split//~va00R~
            	overwraplen=utf8offs2-utf8offs1;                   //~va00R~
                expandlen=srcutf8len-overwraplen;                  //~va00R~
                if (expandlen<0)	//shrink                       //~va00I~
//              	memcpy(tgtutf8+overwraplen+expandlen,tgtutf8+overwraplen,tgtutf8len-utf8offs2);//~vb01R~
                	memcpy(tgtutf8+overwraplen+expandlen,tgtutf8+overwraplen,(size_t)(tgtutf8len-utf8offs2));
                else                                               //~va00I~
                if (expandlen>0)	//expand                       //~va00I~
//              	memmove(tgtutf8+overwraplen+expandlen,tgtutf8+overwraplen,tgtutf8len-utf8offs2);//~vb01R~
                	memmove(tgtutf8+overwraplen+expandlen,tgtutf8+overwraplen,(size_t)(tgtutf8len-utf8offs2));
//  	        tgtutf8len+=expandlen;                             //~va00I~//~va5JR~
    			if (Popt & XEUTFMSUO_STRZ)                         //~va00I~
                	*(tgtutf8+overwraplen+expandlen+tgtutf8len-utf8offs2)=0;//~va00I~
    	        tgtutf8len+=expandlen;                             //~va5JI~
                strzsw=0;                                          //~va00I~
            }                                                      //~va00I~
            else  //overwrite tgt end of line                      //~va00R~
            {                                                      //~va00I~
		        tgtlclen=Ptgtpos+srclclen;                         //~va00R~
		        tgtutf8len=utf8offs1+srcutf8len;                   //~va00R~
            }                                                      //~va00I~
        }                                                          //~va00I~
    }                                                              //~va00I~
    if (srclclen>width-Ptgtpos)     //overflow                     //~va00R~
    {                                                              //~va00R~
        len=width-Ptgtpos;                                         //~va00I~
//      utfpos2offs(0,Psrcutf8,Psrcdbcs,Psrccodetype,len,srcutf8len,&lenutf8);//~va00R~//~va1fR~
        utfpos2offs(0,Psrcutf8,srcdbcs,srccodetype,len,srcutf8len,&lenutf8);//~va1fI~
        tgtlclen-=srclclen-len;                                    //~va00I~
        tgtutf8len-=srcutf8len-lenutf8;                            //~va00I~
    }                                                              //~va00I~
    else                                                           //~va00I~
    {                                                              //~va00I~
        len=srclclen;                                              //~va00I~
        lenutf8=srcutf8len;                                        //~va00I~
    }                                                              //~va00I~
    if (len>0)                                                     //~va00I~
    {                                                              //~va00I~
    	memcpy(tgtlc,srclc,(UINT)len);                             //~va00R~
//  	memcpy(tgtdbcs,Psrcdbcs,(UINT)len);                        //~va00R~//~va1fR~
    	memcpy(tgtdbcs,srcdbcs,(UINT)len);                         //~va1fI~
		chartabclear(tgtdbcs,len);                                 //~va00I~
//    	memcpy(tgtcodetype,Psrccodetype,(UINT)len);                //~va00R~//~va1fR~
      	memcpy(tgtcodetype,srccodetype,(UINT)len);                 //~va1fI~
    	memcpy(tgtutf8,Psrcutf8,(UINT)lenutf8);                    //~va00I~
    }                                                              //~va00I~
    if (Pptgtutf8len)                                              //~va00I~
	    *Pptgtutf8len=tgtutf8len;                                  //~va00R~
    if (Pptgtlclen)                                                //~va00I~
	    *Pptgtlclen=tgtlclen;                                      //~va00R~
    if (strzsw && Popt & XEUTFMSUO_STRZ)                           //~va00R~
    {                                                              //~va00I~
       *(Ptgtlc+tgtlclen)=0;                                       //~va00R~
       *(Ptgtutf8+tgtutf8len)=0;                                   //~va00I~
    }                                                              //~va00I~
UTRACEP("xeutf_mixedstrupdate out lclen=%d,utf8len=%d\n",tgtlclen,tgtutf8len);//~va00I~
UTRACED("LC",Ptgtlc,tgtlclen);                                     //~va00I~
UTRACED("CODETYPE",Ptgtcodetype,tgtlclen);                         //~va00I~
UTRACED("DBCS",Ptgtdbcs,tgtlclen);                                 //~va00R~
UTRACED("UTF8",Ptgtutf8,tgtutf8len);                               //~va00I~
	if (Popt & XEUTFMSUO_SETUTF8RC)   	//return rc=1 if utf8 code contained//~va00I~
    {                                                              //~va00I~
    	if (tgtlclen)                                              //~va00I~
//search on pct                                                    //~va5nI~
//  		if (memchr(Ptgtcodetype,XEUTFCT_UTF8,tgtlclen))        //~vb01R~
    		if (memchr(Ptgtcodetype,XEUTFCT_UTF8,(size_t)tgtlclen))//~vb01I~
				return XEUTFMSURC_UTF8;	// 1target contains utf8 coed//~va00I~
    }                                                              //~va00I~
	return 0;                                                      //~va00R~
}//xeutf_mixedstrupdate                                            //~va00I~
//**************************************************               //~va1rI~
//set codetable by u8 and lc str                                   //~va1rI~
//valid when dd21fl err char (".")                                 //~vau7I~
//rc 4:not same string after f2l                                   //~va1rI~
//rc 1:dd2l errrep detected                                        //~vau7I~
//**************************************************               //~va1rI~
int xeutf_setctbyu8lc(int Popt,char *Ppu8,int Plenu8,char *Pplc,int Plenlc,char *Ppct,int Pctbuffsz)//~va1rI~
{                                                                  //~va1rI~
    int chklenlc,chklenu8,reslenu8,reslenlc,reslenct,dbcssz,rc;    //~va1rR~
    char *pu8,*plc,*pct;                                           //~va1rI~
    char wklc[MAX_MBCSLEN];                                        //~va1rI~
    int rc2,opt,swrepchok;                                         //~va5rR~
//#ifdef LNX                                                       //~vavpR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavpR~
    int swrepchkokdd=0;                                            //~vau7R~
#endif                                                             //~vau7I~
//****************************                                     //~va1rI~
	swrepchok=Popt & XEUTFSCBULO_ALLOWREPCH;                       //~va5rR~
    for (pu8=Ppu8,plc=Pplc,reslenu8=Plenu8,reslenlc=Plenlc,pct=Ppct,reslenct=Pctbuffsz;//~va1rI~
    		reslenu8>0 && reslenlc>0 && reslenct>0;                //~va1rI~
        	pu8+=chklenu8,reslenu8-=chklenu8,plc+=chklenlc,reslenlc-=chklenlc,pct+=chklenlc,reslenct-=chklenlc)//~va1rI~
    {                                                              //~va1rI~
    	chklenu8=1;                                                //~va1rI~
    	chklenlc=1;                                                //~va1rI~
//      if (*pu8==*plc)	//not utf8 char                            //~va1rI~//~vawvR~
        if (*pu8==*plc 	//not utf8 char                            //~vawvI~
        ||  ((*pu8=='\\' && *plc=='/')||(*pu8=='/' && *plc=='\\')) //for ftp consideration//~vawvI~//~vawxR~
        )                                                          //~vawvI~
        {                                                          //~va1rI~
        	if (!UDBCSCHK_ISDBCS1ST(*plc))                         //~va1rI~
            {                                                      //~va1rI~
            	*pct=0;                                            //~va1rI~
                continue;                                          //~va1rI~
            }                                                      //~va1rI~
			if (udbcschk_getmblen(0,plc,reslenlc,&dbcssz)>UDCGMLRC_ERR)//~va1rI~
            	break;	//err                                      //~va1rI~
            if (reslenu8<dbcssz)                                   //~va1rI~
            	break;	//err                                      //~va1rI~
            if (memcmp(pu8,plc,(UINT)dbcssz))                      //~va1rI~
            	break;	//err                                      //~va1rI~
            chklenu8=dbcssz;                                       //~va1rI~
            chklenlc=dbcssz;                                       //~va1rI~
            if (dbcssz>reslenct)                                   //~va1rI~
            	break;                                             //~va1rI~
            memset(pct,XEUTFCT_LC,(UINT)dbcssz);                   //~va1rI~
            continue;                                              //~va1rI~
        }                                                          //~va1rI~
//utf8 str                                                         //~va1rI~
		chklenu8=UTF8CHARLEN(*pu8);                                //~va1rR~
        if (!chklenu8)	//not valid utf8                           //~va1CI~
        	break;                                                 //~va1CI~
        if (chklenu8>reslenu8)                                     //~va1rR~
        	break;                                                 //~va1rI~
//#ifdef LNX                                                       //~vavpR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavpR~
        if (*plc==XEUTFDD2LC_REPERR)                               //~vau7I~
        {                                                          //~vau7I~
        	UCHAR *pdddata,*pdddbcs;                               //~vau7R~
            int ddlen2;                                            //~vau7I~
        //*****************                                        //~vau7I~
        	chklenlc=1;                                            //~vau7I~
			xeutf_cvf2dd(0,pu8,chklenu8,&pdddata,&pdddbcs,&ddlen2);//~vau7R~
            if (ddlen2==2)                                         //~vau7I~
            {                                                      //~vau7I~
	        	if (*(plc+1)!=XEUTFDD2LC_REPERR)                   //~vau7I~
                {                                                  //~vbkaI~
//              	break;                                         //~vbkaR~
//              chklenlc=2;                                        //~vbkaR~
                  chklenlc=1;                                      //~vbkaI~
                }                                                  //~vbkaI~
            }                                                      //~vau7I~
            swrepchkokdd=1;                                        //~vau7I~
	        memset(pct,XEUTFCT_UTF8,(UINT)chklenlc);               //~vau7I~
            continue;                                              //~vau7I~
        }                                                          //~vau7I~
        if (!xeutf_dbcssubcharcmp(0,plc,reslenlc))                 //~vbi4R~
        {                                                          //~vbi4I~
    		opt=UTFCVO_ERRRET;  //doubled "?" for err dbcs         //~vbi4I~
	    	rc2=utfcvf2l(opt,wklc,pu8,chklenu8,0/*chklen*/,&chklenlc,0/*Ppcharwidth*/);//~vbi4I~
			if (rc2==UTFCVRC_ERRSTOP)                              //~vbi4I~
            {                                                      //~vbi4I~
	            swrepchkokdd=1;                                    //~vbi4I~
	        	chklenlc=2;                                        //~vbi4I~
		        memset(pct,XEUTFCT_UTF8,(UINT)chklenlc);           //~vbi4I~
	            continue;                                          //~vbi4I~
            }                                                      //~vbi4I~
        }                                                          //~vbi4I~
#endif                                                             //~vau7I~
//  	if (utfcvf2l(0,wklc,pu8,chklenu8,0/*chklen*/,&chklenlc,0/*Ppcharwidth*/))//~va5rR~
//      	break;                                                 //~va5rR~
		opt=0;                                                     //~va5rR~
		if (swrepchok) //accept repch "?" as valid for cmd retrieve chk//~va5rR~
    		opt|=UTFCVO_ERRREP|(XEUTF_ERRREPCH_F2LFILE<<8);  //doubled "?" for err dbcs//~va5rR~
    	rc2=utfcvf2l(opt,wklc,pu8,chklenu8,0/*chklen*/,&chklenlc,0/*Ppcharwidth*/);//~va5rR~
        if (rc2 && (rc2!=UTFCVRC_ERR||!swrepchok))                 //~va5rR~
        	break;                                                 //~va5rR~
        if (chklenlc>reslenct)                                     //~va1rI~
           	break;                                                 //~va1rI~
        if (memcmp(plc,wklc,(UINT)chklenlc))                       //~va1rR~
        	break;                                                 //~va1rI~
        memset(pct,XEUTFCT_UTF8,(UINT)chklenlc);                   //~va1rR~
    }                                                              //~va1rI~
    if (reslenu8>0||reslenlc>0)                                    //~va1rI~
    	rc=4;                                                      //~va1rI~
    else                                                           //~va1rI~
//#ifdef LNX                                                       //~vavpR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavpR~
	if (swrepchkokdd)                                              //~vau7R~
    	rc=1;                                                      //~vau7I~
    else                                                           //~vau7I~
#endif                                                             //~vau7I~
    	rc=0;                                                      //~va1rI~
UTRACEP("xeutf_setctbyu8lc rc=%d\n",rc);                           //~va1rI~
UTRACED("inpu8",Ppu8,Plenu8);                                      //~va1rI~
UTRACED("inplc",Pplc,Plenlc);                                      //~va1rI~
UTRACED("out CODETYPE",Ppct,Pctbuffsz-reslenct);                   //~va1rI~
	return rc;                                                     //~va1rI~
}//xeutf_setctbyu8lc                                               //~va1rR~
//**************************************************               //~va50I~
//set dbcstable by ct for u8(mixed)str(set dbcsid=0 for locale str)//~va50I~
//rc:1 utf8 detected,2:dbcs detected,4:err,8 ovf                   //~va50I~
//**************************************************               //~va50I~
int xeutf_setdbcstblbyct(int Popt,UCHAR *Psrch,int Psrchlen,UCHAR *Pct,UCHAR *Pdbcs,int Pbuffsz,int *Ppctlen)//~va50I~
{                                                                  //~va50I~
	int /*swu8,*/lcchsz,utf8chsz,rc=0,ctlen,reslen;                    //~va50R~//~vaa7R~
	UCHAR *pc,*pce,*pdbcs,*pdbcse,*pct;                            //~va50I~
    ULONG ucs;                                                     //~va50I~
//******************                                               //~va50I~
//	memset(Pdbcs,0,Pbuffsz);                                       //~vb01R~
  	memset(Pdbcs,0,(size_t)Pbuffsz);                               //~vb01I~
    for (/*swu8=0,*/pc=Psrch,pce=pc+Psrchlen,pct=Pct,pdbcs=Pdbcs,pdbcse=pdbcs+Pbuffsz;//~va50R~//~vaa7R~
            pc<pce;                                                //~va50I~
            pc+=utf8chsz,pct+=lcchsz)                              //~va50I~
    {                                                              //~va50I~
        if (*pct==XEUTFCT_UTF8)                                    //~va50I~
        {                                                          //~va50I~
//      	reslen=(ULONG)pce-(ULONG)pc;                           //~va50I~//~vafkR~
//      	reslen=(ULPTR)pce-(ULPTR)pc;                           //~vb01R~
        	reslen=(int)((ULPTR)pce-(ULPTR)pc);                    //~vb01I~
            if (utfgetwcw(0,pc,reslen,&ucs,&utf8chsz,&lcchsz))     //~va50R~
            {                                                      //~va50I~
            	rc=4;                                              //~va50I~
            	break;                                             //~va50I~
            }                                                      //~va50I~
            if (pdbcs+lcchsz>pdbcse)                               //~va50R~
            {                                                      //~va50I~
            	rc=8;                                              //~va50I~
            	break;                                             //~va50I~
            }                                                      //~va50I~
            *pdbcs++=UDBCSCHK_DBCS1ST;                             //~va50I~
            if (lcchsz>2)                                          //~va50I~
            	*pdbcs++=UDBCSCHK_DBCSPAD;                         //~va50I~
            if (lcchsz>3)                                          //~va50I~
            	*pdbcs++=UDBCSCHK_DBCSPAD;                         //~va50I~
            *pdbcs++=UDBCSCHK_DBCS2ND;                             //~va50I~
            rc|=1;                                                 //~va50I~
            if (lcchsz>1)                                          //~va50I~
	            rc|=2;                                             //~va50I~
        }                                                          //~va50I~
        else                                                       //~va50I~
        {                                                          //~va50I~
        	utf8chsz=lcchsz=1;                                     //~va50I~//~va5wR~
            pdbcs++;                                               //~va50I~
        }                                                          //~va50I~
    }                                                              //~va50I~
    if (rc<4)                                                      //~va50R~
//      ctlen=(ULONG)pdbcs-(ULONG)Pdbcs;                           //~va50I~//~vafkR~
//      ctlen=(ULPTR)pdbcs-(ULPTR)Pdbcs;                           //~vb01R~
        ctlen=(int)((ULPTR)pdbcs-(ULPTR)Pdbcs);                    //~vb01I~
    else                                                           //~va50I~
    	ctlen=0;                                                   //~va50I~
    *Ppctlen=ctlen;                                                //~va50I~
    return rc;                                                     //~va50I~
}//xeutf_setdbcstblbyct                                            //~va50I~
//**************************************************               //~va1rI~
//compare u8 and lc string                                         //~va1rI~
//rc 0:match,1 unmatch                                             //~va1rR~
//**************************************************               //~va1rI~
//int xeutf_memcmpu8lc(int Popt,char *Ppu8,int Plenu8,char *Pplc,int Plenlc)//~va1rI~//~va1yR~
int xeutf_memcmpu8lc(int Popt,char *Ppu8,int Plenu8,char *Pplc,int Plenlc,int *Pplenlc)//~va1yI~
{                                                                  //~va1rI~
    int chklenlc,chklenu8,reslenu8,reslenlc,rc,dbcssz;             //~va1rR~
    char *pu8,*plc;                                                //~va1rR~
    char wklc[MAX_MBCSLEN];                                        //~va1rI~
    int rc2,opt,swrepchok;                                         //~va5rI~
//****************************                                     //~va1rI~
	swrepchok=Popt & XEUTFMC8LO_ALLOWREPCH;  //accept repch "?" as valid for cmd retrieve chk//~va5rI~
    for (pu8=Ppu8,plc=Pplc,reslenu8=Plenu8,reslenlc=Plenlc;        //~va1rI~
    		reslenu8>0 && reslenlc>0;                              //~va1rI~
        	pu8+=chklenu8,reslenu8-=chklenu8,plc+=chklenlc,reslenlc-=chklenlc)//~va1rI~
    {                                                              //~va1rI~
    	chklenu8=1;                                                //~va1rI~
    	chklenlc=1;                                                //~va1rI~
        if (*pu8==*plc)	//not utf8 char                            //~va1rI~
        {                                                          //~va1rI~
        	if (!UDBCSCHK_ISDBCS1ST(*plc))                         //~va1rI~
                continue;                                          //~va1rI~
			if (udbcschk_getmblen(0,plc,reslenlc,&dbcssz)>UDCGMLRC_ERR)//~va1rI~
            	break;	//err                                      //~va1rI~
            if (reslenu8<dbcssz)                                   //~va1rI~
            	break;	//err                                      //~va1rI~
            if (memcmp(pu8,plc,(UINT)dbcssz))                      //~va1rI~
            	break;	//err                                      //~va1rI~
            chklenu8=dbcssz;                                       //~va1rI~
            chklenlc=dbcssz;                                       //~va1rI~
            continue;                                              //~va1rI~
        }                                                          //~va1rI~
//utf8 str                                                         //~va1rI~
		chklenu8=UTF8CHARLEN(*pu8);                                //~va1rR~
        if (!chklenu8)	//not valid utf8                           //~va1CI~
        	break;                                                 //~va1CI~
        if (chklenu8>reslenu8)                                     //~va1rR~
        	break;                                                 //~va1rI~
//  	if (utfcvf2l(0,wklc,pu8,chklenu8,0/*chklen*/,&chklenlc,0/*Ppcharwidth*/))//~va5rR~
//      	break;                                                 //~va5rR~
		opt=0;                                                     //~va5uI~
#ifdef LNX                                                         //~vaumI~
	  if (Popt & XEUTFMC8LO_DDWREPCH)  //accept repch "?" as valid for cmd retrieve chk by DDW mode//~vaumI~
      {                                                            //~vaumI~
		xeutfcvf2lDDW(0,pu8,chklenu8,wklc,sizeof(wklc),&chklenlc); //~vaumR~
      }                                                            //~vaumI~
      else                                                         //~vaumI~
#endif                                                             //~vaumI~
	  {                                                            //~vaumI~
		if (swrepchok) //accept repch "?" as valid for cmd retrieve chk//~va5rI~
    		opt|=UTFCVO_ERRREP|(XEUTF_ERRREPCH_F2LFILE<<8);  //doubled "?" for err dbcs//~va5rI~
    	rc2=utfcvf2l(opt,wklc,pu8,chklenu8,0/*chklen*/,&chklenlc,0/*Ppcharwidth*/);//~va5rI~
        if (rc2 && (rc2!=UTFCVRC_ERR||!swrepchok))                 //~va5rI~
        	break;                                                 //~va5rI~
      }                                                            //~vaumI~
        if (memcmp(plc,wklc,(UINT)chklenlc))	//com after trans  //~va1rR~
        {                                                          //~vaviI~
          if (chklenlc==1  //dbcs                                  //~vaviR~
          || utf_subcharcmp(0,XEUTF_ERRREPCH_F2LFILE,plc,wklc,chklenlc))//chk dbcserrrep by utfcvf2l//~vaviI~
        	break;                                                 //~va1rI~
        }                                                          //~vaviI~
    }                                                              //~va1rI~
  if (Popt & XEUTFMC8LO_CHKLCLEN)  //utf8 string is part of locale str to be chked,return lclen if matched//~va1yI~
  {                                                                //~va1yI~
    if (reslenu8>0)                                                //~va1yI~
    	rc=1;                                                      //~va1yI~
    else                                                           //~va1yI~
    {                                                              //~va1yI~
    	rc=0;	//match                                            //~va1yI~
        *Pplenlc=Plenlc-reslenlc;                                  //~va1yR~
    }                                                              //~va1yI~
  }                                                                //~va1yI~
  else                                                             //~va1yI~
  {                                                                //~va1yI~
    if (reslenu8>0||reslenlc>0)                                    //~va1rI~
    	rc=1;                                                      //~va1rR~
    else                                                           //~va1rI~
    	rc=0;	//match                                            //~va1rR~
  }                                                                //~va1yI~
UTRACEP("xeutf_memcmpu8lc rc=%d\n",rc);                           //~va1rI~//~va6wR~
UTRACED("inpu8",Ppu8,Plenu8);                                      //~va1rI~
UTRACED("inplc",Pplc,Plenlc);                                      //~va1rI~
	return rc;                                                     //~va1rI~
}//xeutf_memcmpu8lc                                                //~va1rR~
//**************************************************               //~va6wI~
//compare dd fmt and locale string(after l2dd)                     //~va6wI~
//rc 0:match,1 unmatch                                             //~va6wI~
//**************************************************               //~va6wI~
int xeutf_memcmpddlc(int Popt,UCHAR *Pdddata,UCHAR *Pdddbcs,int Pddlen,UCHAR *Plcdata,UCHAR *Plcdbcs,int Plclen,int *Pppos1,int *Pppos2)//~va6wR~
{                                                                  //~va6wI~
    UCHAR *plc2dddata,*plc2dddbcs,*pc1,*pc2,*pcd1,*pcd2,*pc3,*pcd3;//~va6wI~
    int lc2ddlen,len,opt,rc,chsz2,chsz3,dbcsid,reslen,reslen3,reslen2,pos1=0,pos2=0;//~vaf9R~
    int pos3=0;                                                    //~vaf9R~
//****************************                                     //~va6wI~
    if (Pppos1) //dddata                                           //~va6wR~
        *Pppos1=Pddlen;                                            //~va6wR~
    if (Pppos2)                                                    //~va6wI~
        *Pppos2=Plclen;                                            //~va6wR~
//  opt=0;                                                         //~va6wI~//~va8fR~
    opt=XEUTFCVO_SETTABCHAR;                                       //~va8fI~
//  rc=xeutfcvl2dd(opt,Plcdata,Plclen,&plc2dddata,&plc2dddbcs,&lc2ddlen);//~va6wR~//~va8fR~
    rc=xeutfcvl2ddtab(opt,Plcdata,Plcdbcs,Plclen,&plc2dddata,&plc2dddbcs,&lc2ddlen);//~va8fI~
	UALLOCCHKRC(rc);                                               //~va6wI~
    if (!Pppos1 && !Pppos2)	//no request to return unmatch pos     //~va6wR~
    {                                                              //~va6wI~
    	if (lc2ddlen!=Pddlen                                       //~va6wR~
    	||  memcmp(Pdddata,plc2dddata,(UINT)Pddlen)                //~va6wR~
    	||  memcmp(Pdddbcs,plc2dddbcs,(UINT)Pddlen)                //~va6wR~
        )                                                          //~va6wI~
        	rc=1;	//unmatch                                      //~va6wI~
        else                                                       //~va6wI~
        	rc=0;                                                  //~va6wI~
    }                                                              //~va6wI~
    else                                                           //~va6wI~
    {                                                              //~va6wI~
    	rc=0;                                                      //~va6wI~
    	len=min(Pddlen,lc2ddlen);                                  //~va6wR~
        for (pc1=Pdddata,pcd1=Pdddbcs,pc2=plc2dddata,pcd2=plc2dddbcs,reslen=len;//~va6wI~
                reslen>0;                                          //~va6wR~
				reslen--,pc1++,pc2++,pcd1++,pcd2++)                //~va6wR~
        {                                                          //~va6wI~
//          if (*pc1==*pc2 && *pcd1==*pcd2)                        //~va6wR~//~va8fR~
            if (*pc1==*pc2)                                        //~va8fI~
            {                                                      //~va8fI~
              if (*pcd1==*pcd2)                                    //~va8fI~
            	continue;                                          //~va6wI~
              if (*pc1==' ')                                       //~va8fI~
              {                                                    //~va8fI~
				if (*pcd1==UDBCSCHK_TABPADCHAR && !*pcd2)          //~va8fI~
            		continue;	//0x09 and space is remains as unmatch//~va8fI~
				if (*pcd2==UDBCSCHK_TABPADCHAR && !*pcd1)          //~va8fI~
            		continue;	//0x09 and space is remains as unmatch//~va8fI~
              }                                                    //~va8fI~
            }                                                      //~va8fI~
                                                                   //~va8fI~
            rc=1;	//unmatch                                      //~va6wI~
            break;                                                 //~va6wI~
        }                                                          //~va6wI~
        if (!rc)                                                   //~va6wI~
        	if (lc2ddlen>Pddlen)                                   //~va6wR~
            	rc=1;	//unmatch,search on lc data corresponding l2dd data//~va6wI~
        if (rc)	//unmatch                                          //~va6wI~
        {                                                          //~va6wI~
//      	pos1=(ULONG)pc1-(ULONG)Pdddata;                        //~va6wI~//~vafkR~
//      	pos1=(ULPTR)pc1-(ULPTR)Pdddata;                        //~vb01R~
        	pos1=(int)((ULPTR)pc1-(ULPTR)Pdddata);                 //~vb01I~
            dbcsid=*pcd1;                                          //~va6wI~
            if (pos1>0 && UDBCSCHK_DBCS2NDU(dbcsid))               //~va6wI~
            	pos1--;                                            //~va6wI~
//      	pos2=(ULONG)pc2-(ULONG)plc2dddata;                     //~va6wI~//~vafkR~
//      	pos2=(ULPTR)pc2-(ULPTR)plc2dddata;                     //~vb01R~
        	pos2=(int)((ULPTR)pc2-(ULPTR)plc2dddata);              //~vb01I~
            dbcsid=*pcd2;                                          //~va6wI~
            if (pos2>0 && UDBCSCHK_DBCS2NDU(dbcsid))               //~va6wI~
            	pos2--;                                            //~va6wI~
        	for (pc3=Plcdata,pcd3=Plcdbcs,pc2=plc2dddata,pcd2=plc2dddbcs,reslen2=pos2,reslen3=Plclen;//~va6wR~
					reslen2>0;   //serch on lc data corresponding l2dd pos//~va6wR~
					reslen2-=chsz2,reslen3-=chsz3,pc2+=chsz2,pcd2+=chsz2,pc3+=chsz3,pcd3+=chsz3)//~va6wI~
            {                                                      //~va6wI~
	            dbcsid=*pcd2;                                      //~va6wI~
            	chsz2=1+(UDBCSCHK_DBCS1STU(dbcsid)!=0);            //~va6wI~
                dbcsid=*pcd3;                                      //~va6wI~
            	if (UDBCSCHK_DBCS1STL(dbcsid))                     //~va6wI~
                	chsz3=XESUB_DBCSSPLITCTR(Plcdbcs,Plclen,Plclen-reslen3);//~va6wR~
                else                                               //~va6wI~
                	chsz3=1;                                       //~va6wI~
                if (chsz3>reslen3)                                 //~va6wI~
                	break;                                         //~va6wI~
            }                                                      //~va6wI~
            pos3=Plclen-reslen3;                                   //~va6wR~
        }//unmatch                                                 //~va6wI~
        else	//match                                            //~va6wI~
        if (lc2ddlen<Pddlen)                                       //~va6wR~
        {                                                          //~va6wI~
            rc=1;                                                  //~va6wI~
//      	pos1=(ULONG)pc1-(ULONG)Pdddata;                        //~va6wI~//~vafkR~
//      	pos1=(ULPTR)pc1-(ULPTR)Pdddata;                        //~vb01R~
        	pos1=(int)((ULPTR)pc1-(ULPTR)Pdddata);                 //~vb01I~
            dbcsid=*pcd1;                                          //~va6wI~
            if (pos1>0 && UDBCSCHK_DBCS2NDU(dbcsid))               //~va6wI~
            	pos1--;                                            //~va6wI~
            pos3=Plclen;                                           //~va6wI~
        }                                                          //~va6wI~
        if (rc)                                                    //~va6wR~
        {                                                          //~va6wI~
        	if (Pppos1)                                            //~va6wR~
            	*Pppos1=pos1;   //dd                               //~va6wR~
        	if (Pppos2)                                            //~va6wR~
            	*Pppos2=pos3;   //lc                               //~va6wR~
        }                                                          //~va6wI~
	}                                                              //~va6wI~
UTRACEP("xeutf_memcmpddlc rc=%d,pos1=%d(dd1),pos2(dd2)=%d,pos3(lc2)=%d\n",rc,pos1,pos2,pos3);//~va6wI~
UTRACED("inp dd data",Pdddata,Pddlen);                             //~va6wR~
UTRACED("inp dd dbcs",Pdddbcs,Pddlen);                             //~va6wR~
UTRACED("inp lc data",Plcdata,Plclen);                             //~va6wR~
UTRACED("inp lc dbcs",Plcdbcs,Plclen);                             //~va6wR~
	return rc;                                                     //~va6wI~
}//xeutf_cvmemcmpddlc                                              //~va6wR~
//**************************************************               //~va1CI~
//save codetype for errmsg                                         //~va1CI~
//rc:1:saved,0:not saved                                           //~va1CI~
//**************************************************               //~va1CI~
//int xeutf_savelcctforerrmsg(int Popt,char *Ppu8,int Plenu8,char *Pplc,char *Ppct,int Plenlc)//~vau7R~
int xeutf_savelcctforerrmsg(int Popt,char *Ppu8,int Plenu8,char *Pplc,char *Pdddbcs,char *Ppct,int Plenlc)//~vau7I~
{                                                                  //~va1CI~
	int idx,len,buffsz;                                            //~va1CI~
//#ifdef LNX                                                         //~vau7I~//~vauER~
	UCHAR wkdddata[sizeof(Stextdd[0])];                            //~vau7I~
	UCHAR wkdddbcs[sizeof(Stextdd[0])];                            //~vau7I~
	UCHAR wkct[sizeof(Stextdd[0])];                                //~vau7I~
	UCHAR *pdddata,*pdddbcs,*pddct,*pct;                           //~vau7R~
    int ddlen,offs,ii,tail;                                        //~vau7R~
//#endif                                                             //~vaumR~//~vauER~
//****************************                                     //~va1CI~
    if (!Plenu8)                                                   //~va1CI~
    	return 0;		//no need to save ascii                    //~va1CI~
    UTRACEP("xeutf_savelcctforerrmsg opt=%xmpu8=%s\n",Popt,Ppu8);    //~vauDR~//~vawxR~
    UTRACED("save pu8",Ppu8,Plenu8);                               //~vauDI~
//search on pct                                                    //~va5nI~
    if (!memchr(Ppct,XEUTFCT_UTF8,(UINT)Plenlc)                    //~va1CR~
    &&  !memchr(Ppct,XEUTFCT_LC,(UINT)Plenlc))                     //~va1CR~
    	return 0;		//no need to save ascii                    //~va1CI~
//#ifdef LNX                                                         //~vaumR~//~vauER~
//*all current user use DDFMT                                      //~vaumI~
	if (Popt & XEUTFSLCFEO_DDFMT)   //parameter is ddfmt           //~vau7I~
    {                                                              //~vau7I~
        pdddata=Pplc,pdddbcs=Pdddbcs,pddct=Ppct;                   //~vau7I~
        ddlen=Plenlc;                                              //~vau7I~
    }                                                              //~vau7I~
    else                                                           //~vau7I~
    {                                                              //~vau7I~
//  	if(xeutfcvlf2ddAdjust(0,Ppu8,Plenu8,Ppct,Plenlc,wkdddata,wkdddbcs,wkct,sizeof(wkct),&ddlen))//~vaumR~
    	if(xeutfcvlf2ddAdjust(0,Ppu8,Plenu8,Pplc,Ppct,Plenlc,wkdddata,wkdddbcs,wkct,sizeof(wkct),&ddlen))//~vaumI~
        	return 0;	//fmt err,ignore                           //~vauaI~
        pdddata=wkdddata,pdddbcs=wkdddbcs,pddct=wkct;              //~vau7I~
    }                                                              //~vau7I~
    for (pct=pddct,ii=0,offs=0;ii<ddlen;ii++,pct++)//drop prefix ascii//~vau7M~
//      if (*pct)                                                  //~vau7M~//~vavLR~
        if (*pct && pdddbcs[ii])                                   //~vavLR~
        {                                                          //~vau7M~
        	offs=ii;                                               //~vau7M~
            break;                                                 //~vau7M~
        }                                                          //~vau7M~
    tail=0;                                                        //~vau7I~
    if (ii<ddlen)                                                  //~vau7M~
    {                                                              //~vau7M~
    	for (pct=pddct+ddlen-1,ii=0;ii<ddlen;ii++,pct--)//drop prefix ascii//~vau7M~
//        	if (*pct)                                              //~vau7M~//~vavLR~
            if (*pct && pdddbcs[ddlen-1-ii])  //not ascii          //~vavLR~
            {                                                      //~vau7M~
            	tail=ii;                                           //~vau7I~
            	break;                                             //~vau7M~
            }                                                      //~vau7M~
    }                                                              //~vau7M~
//#endif                                                             //~vaumR~//~vauER~
	buffsz=sizeof(Stextu8[0]);                                     //~va1CI~
	idx=Popt & XEUTFSLCFEO_INDEXMASK;                              //~va1CR~
//#ifdef LNX                                                         //~vau7M~//~vauER~
#ifdef AAA                                                         //~vavLI~
    len=Plenu8-offs-tail;                                          //~vau7I~
//  len=min(buffsz-1,len);                                         //~vaueR~
	if (len>(buffsz-1))                                            //~vaueI~
    	return 0;		                                           //~vaueI~
    Stextu8len[idx]=len;                                           //~vau7I~
    UmemcpyZ(Stextu8[idx],Ppu8+offs,(UINT)len);                    //~vau7I~
#endif                                                             //~vavLI~
	buffsz=sizeof(Stextdd[0]);                                     //~vau7M~
    len=ddlen-offs-tail;                                           //~vau7I~
//  len=min(buffsz,len);                                           //~vaueR~
	if (len>buffsz)                                                //~vaueI~
    {                                                              //~vaueI~
	    Stextu8len[idx]=0;                                         //~vaueI~
	    *Stextu8[idx]=0;                                           //~vaueI~
    	return 0;		                                           //~vaueI~
    }                                                              //~vaueI~
    Stextddlen[idx]=len;                                           //~vau7M~
    memcpy(Stextdd[idx],pdddata+offs,(UINT)len);                   //~vau7M~
    memcpy(Stextdddbcs[idx],pdddbcs+offs,(UINT)len);               //~vau7M~
    memcpy(Stextct[idx],pddct+offs,(UINT)len);                     //~vau7M~
#ifndef AAA                                                        //~vavLI~
	utfcvdd2f(0,pdddata+offs,len,pdddbcs+offs,Stextu8[idx],sizeof(Stextu8[0])-1,&Stextu8len[idx],NULL/*outdbcs*/);//~vavLR~
	*(Stextu8[idx]+Stextu8len[idx])=0;                             //~vavLI~
#endif                                                             //~vavLI~
    UTRACED("save lc u8",Stextu8[idx],Stextu8len[idx]);            //~vau7I~
    UTRACED("save lc dddata",Stextdd[idx],len);                    //~vau7I~
    UTRACED("save lc dddbcs",Stextdddbcs[idx],len);                //~vau7M~
    UTRACED("save lc ct",Stextct[idx],len);                        //~vau7M~
//#ifdef LNX                                                       //~vavpR~
//#else                                                            //~vavpR~
//#ifdef CCC                                                       //~vavpR~
//    len=min(buffsz-1,Plenu8);                                    //~vavpR~
//    Stextu8len[idx]=len;                                         //~vavpR~
//    UmemcpyZ(Stextu8[idx],Ppu8,(UINT)len);                       //~vavpR~
//    buffsz=sizeof(Stextlc[0]);                                   //~vavpR~
//    len=min(buffsz,Plenlc);                                      //~vavpR~
//    Stextlclen[idx]=len;                                         //~vavpR~
//    memcpy(Stextlc[idx],Pplc,(UINT)len);                         //~vavpR~
//    memcpy(Stextct[idx],Ppct,(UINT)len);                         //~vavpR~
//    UTRACED("save lc",Pplc,len);                                 //~vavpR~
//    UTRACED("save ct",Ppct,len);                                 //~vavpR~
//#endif                                                           //~vavpR~
//#endif                                                           //~vavpR~
    return 1;                                                      //~va1CI~
}//xeutf_savelcctforerrmsg                                         //~va1CI~
//**************************************************               //~va1CM~
//save codetype for errmsg                                         //~va1CM~
//**************************************************               //~va1CM~
int xeutf_savefnmforerrmsg(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh)  //~va1CR~
{                                                                  //~va1CM~
	int idx,lenlc,lenu8;                                           //~va1CR~
    char *pu8,*plc,*pct;                                           //~va1CR~
    char *pcd;                                                     //~vau7I~
    int opt;                                                       //~vaumI~
//****************************                                     //~va1CM~
	idx=Ppcw->UCWsplitid;                                          //~va1CI~
    pu8=Ppfh->UFHfilename;                                         //~va1CR~
//  lenu8=strlen(pu8);                                             //~vb01R~
    lenu8=(int)strlen(pu8);                                        //~vb01I~
//#ifdef LNX                                                       //~vavpR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavpI~
    lenlc=Ppfh->UFHfilenameddlen;                                  //~vauaM~
  if (lenlc)                                                       //~vauaI~
  {                                                                //~vauaI~
    plc=Ppfh->UFHfilenamedddata;                                   //~vau7R~
    pcd=Ppfh->UFHfilenamedddbcs;                                   //~vau7I~
    pct=Ppfh->UFHfilenameddct;                                     //~vau7I~
  }                                                                //~vauaI~
  else                                                             //~vauaI~
#endif                                                             //~vauaR~
  {                                                                //~vauaI~
    plc=Ppfh->UFHfilenamebylc;                                     //~va1CM~
    pct=Ppfh->UFHfilenamecodetype;                                 //~va1CM~
    lenlc=Ppfh->UFHfilenamebylclen;                                //~va1CM~
    pcd=NULL;                                                      //~vau7I~
  }                                                                //~vauaR~
    UTRACEP("xeutf_savefnmforerrmsg u8=%s,lc=%s\n",pu8,plc);       //~vak5R~
    UTRACED("xeutf_savefnmforerrmsg pct",pct,lenlc);               //~vak5I~
    if (!plc)                                                      //~va1CI~
    	return 0;                                                  //~va1CI~
//	return xeutf_savelcctforerrmsg(idx|XEUTFSLCFEO_FILENAME,pu8,lenu8,plc,pct,lenlc);//~vau7R~
  	opt=idx|XEUTFSLCFEO_FILENAME;                                  //~vaumR~
//#ifdef LNX                                                       //~vavpR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavpI~
  	opt|=XEUTFSLCFEO_DDFMT;                                        //~vaumI~
#endif                                                             //~vaumI~
  	return xeutf_savelcctforerrmsg(opt,pu8,lenu8,plc,pcd,pct,lenlc);//~vaumI~
}//xeutf_savefnmforerrmsg                                          //~va1CR~
//**************************************************               //~va1CM~
//chk saved locale code for errmsg codetype chk                    //~va1CM~
//**************************************************               //~va1CM~
int xeutf_chksaveedlcct(int Popt,char *Ppu8,int Plenu8,int *Ppoffs)//~va1CM~
{                                                                  //~va1CM~
	char *pc,*substr=0;                                            //~vaf9R~
    int substrlen=0,ii;                                            //~vaf9R~
//****************************                                     //~va1CM~
    UTRACEP("srch pu8=%s,len=%d\n",Ppu8,Plenu8);                   //~vau5R~
	for (ii=0,pc=0;ii<XEUTF_MAXSVTEXT;ii++)                        //~va1CM~
    {                                                              //~va1CM~
    	substr=Stextu8[ii];                                        //~va1CM~
    	substrlen=Stextu8len[ii];                                  //~va1CM~
    	if (substrlen                                              //~va1CM~
    	&&  Plenu8>=substrlen                                      //~vau5R~
//      &&  (pc=umemmem(Ppu8,substr,Plenu8,substrlen)))            //~vb01R~
//      &&  (pc=umemmem(Ppu8,substr,(size_t)Plenu8,(size_t)substrlen)))//~vb01R~//~vb2ER~
        &&  (pc=umemmem(Ppu8,substr,(UINT)Plenu8,(UINT)substrlen)))//~vb2EI~
        	break;                                                 //~va1CM~
    	UTRACEP("srch pu8 idx=%d=%s\n",ii,substr);                 //~vau5R~
    }                                                              //~va1CM~
    if (!pc)                                                       //~va1CM~
    	return -1;                                                 //~va1CM~
    UTRACED("srch found pu8",substr,substrlen);                    //~va1CR~
//  *Ppoffs=(int)((ULONG)pc-(ULONG)Ppu8);                          //~va1CM~//~vafkR~
    *Ppoffs=(int)((ULPTR)pc-(ULPTR)Ppu8);                          //~vafkI~
    UTRACEP("srch found idx=%d,offs=%d\n",ii,*Ppoffs);             //~va1CI~
    return ii;                                                     //~va1CM~
}//xeutf_chksaveedlcct                                             //~va1CM~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50R~//~va54I~
//**************************************************               //~va54I~
//*xeutf_seterrmsgct                                               //~va54I~
#ifdef BBB                                                         //~va50I~
//set codetype tbl for errmsg                                      //~va54I~
#else                                                              //~va50I~
//set dd fmt for errmsg                                            //~va50I~
#endif                                                             //~va50I~
//ret :2 for ddfmt                                                 //~va50I~
//**************************************************               //~va54I~
#ifdef BBB                                                         //~va50I~
int xeutf_seterrmsgct_forxeerrmsg(int Popt,char *Ppu8,int Plenu8,char *Pplc,char *Ppct,int Pbuffsz,int *Pplenlc)//~va54R~
#else                                                              //~va50I~
int xeutf_seterrmsgct_forxeerrmsg(int Popt,char *Ppu8,int Plenu8,char *Pplc,char *Pdbcs,char *Ppct,int Pbuffsz,int *Pplenlc)//~va50I~
#endif                                                             //~va50I~
{                                                                  //~va54I~
	char *plc,*pct,*pu8,*pu8e,*pc,*pc2;                            //~va54I~
    int resleno,len,ct,reslen,rc=2;                                //~va50R~
//#ifdef BBB                                                         //~va50I~//~vavaR~
//#else                                                              //~va50I~//~vavaR~
	UCHAR *pcd,*pdddata,*pdddbcs;                                   //~va50R~//~va5wR~
    int opt,rc2,outlen,ii;                                         //~va50R~
//#endif                                                             //~va50I~//~vavaR~
//**************************************************               //~va54I~
//	memset(Ppct,0,Plenu8);                                         //~vb01R~
  	memset(Ppct,0,(size_t)Plenu8);                                 //~vb01I~
//#ifdef BBB                                                         //~va50I~//~vavaR~
//#else                                                              //~va50I~//~vavaR~
	pcd=Pdbcs;                                                     //~va50I~
//#endif                                                             //~va50I~//~vavaR~
	for (pu8=Ppu8,pu8e=pu8+Plenu8,plc=Pplc,pct=Ppct,resleno=Pbuffsz;pu8<pu8e && resleno>0;)//~va54I~
    {                                                              //~va54I~
//  	reslen=(ULONG)pu8e-(ULONG)pu8;                             //~va54I~//~vafkR~
//  	reslen=(ULPTR)pu8e-(ULPTR)pu8;                             //~vb01R~
    	reslen=(int)((ULPTR)pu8e-(ULPTR)pu8);                      //~vb01I~
//search on pct                                                    //~va5nI~
//  	pc=memchr(pu8,XEERMCT_NOTLC,reslen);                       //~vb01R~
    	pc=memchr(pu8,XEERMCT_NOTLC,(size_t)reslen);               //~vb01I~
        if (!pc)                                                   //~va54I~
        	len=min(reslen,resleno);                               //~va54I~
        else                                                       //~va50I~
        {                                                          //~va50I~
//      	len=(ULONG)pc-(ULONG)pu8;                              //~va50I~//~vafkR~
//        	len=(ULPTR)pc-(ULPTR)pu8;                              //~vb01R~
          	len=(int)((ULPTR)pc-(ULPTR)pu8);                       //~vb01I~
        	len=min(len,resleno);                                  //~va50I~
        }                                                          //~va50I~
//#ifdef BBB                                                         //~va50I~//~vavaR~
//        memcpy(plc,pu8,len);                                   //~va54R~//~va50R~//~vavaR~
//#else                                                              //~va50I~//~vavaR~
#ifdef W32UNICODE                                                  //~vawvI~
		opt=Popt;	//STRZ|ERRMSG                                  //~vawvI~
	  if (xeutf_seterrmsgctopd2(Popt,pu8,len,plc/*dddata*/,pcd/*dddbcs*/,pct,resleno/*of plc*/,&len)>=4)//no 2nd u8 opd//~vawvR~
#endif                                                             //~vawvI~
      {                                                            //~vawvI~
        opt=0;                                                     //~va50I~
        xeutfcvl2dd(opt,pu8,len,&pdddata,&pdddbcs,&outlen);        //~va50I~
        len=min(outlen,resleno);                                   //~va50I~
//      memcpy(plc,pdddata,len);                                   //~vb01R~
        memcpy(plc,pdddata,(size_t)len);                           //~vb01I~
//      memcpy(pcd,pdddbcs,len);                                   //~vb01R~
        memcpy(pcd,pdddbcs,(size_t)len);                           //~vb01I~
      }                                                            //~vawvI~
		pcd+=len;                                                  //~va50I~
//#endif                                                             //~va50I~//~vavaR~
        plc+=len;                                              //~va54I~//~va50R~
        pct+=len;                                                  //~va50I~
        resleno-=len;                                              //~va50I~
        if (!pc)                                                   //~va50I~
            break;                                                 //~va50I~
        if (resleno<=0)                                            //~va50I~
        	break;                                                 //~va50I~
        pc++;                                                      //~va54I~
        ct=*pc++;                                                  //~va54R~
//  	reslen=(ULONG)pu8e-(ULONG)pc;                              //~va54I~//~vafkR~
//  	reslen=(ULPTR)pu8e-(ULPTR)pc;                              //~vb01R~
    	reslen=(int)((ULPTR)pu8e-(ULPTR)pc);                       //~vb01I~
        if (reslen<=0)       //fmt err                             //~va54I~
        {                                                          //~va50I~
        	rc=4;                                                  //~va50I~
        	break;                                                 //~va54I~
        }                                                          //~va50I~
//search on pct                                                    //~va5nI~
//  	pc2=memchr(pc,XEERMCT_NOTLC,reslen);                       //~vb01R~
    	pc2=memchr(pc,XEERMCT_NOTLC,(size_t)reslen);               //~vb01I~
        if (!pc2) 	//fmt err                                      //~va54I~
        {                                                          //~va50I~
        	rc=4;                                                  //~va50I~
        	break;                                                 //~va54I~
        }                                                          //~va50I~
//      len=(ULONG)pc2-(ULONG)pc;                                  //~va54R~//~vafkR~
//      len=(ULPTR)pc2-(ULPTR)pc;                                  //~vb01R~
        len=(int)((ULPTR)pc2-(ULPTR)pc);                           //~vb01I~
//#ifdef BBB                                                         //~va50I~//~vavaR~
//        switch(ct)                                                 //~va54I~//~vavaR~
//        {                                                          //~va54I~//~vavaR~
//        case XEERMCT_UTF8:                                         //~va54I~//~vavaR~
//            len=min(len,resleno);                                  //~va50I~//~vavaR~
//            memset(pct,XEUTFCT_UTF8,len);                          //~va54I~//~vavaR~
//            memcpy(plc,pc,len);                                    //~va54I~//~vavaR~
//            plc+=len;                                              //~va54I~//~vavaR~
//            pct+=len;                                              //~va54I~//~vavaR~
//            resleno-=len;                                          //~va54I~//~vavaR~
//            break;                                                 //~va54I~//~vavaR~
//        case XEERMCT_EBC:                                          //~va54I~//~vavaR~
//            len=min(len,resleno);                                  //~va50I~//~vavaR~
//            memset(pct,XEUTFCT_UTF8,len);                          //~va54I~//~vavaR~
//            memcpy(plc,pc,len);                                    //~va54I~//~vavaR~
//            plc+=len;                                              //~va54I~//~vavaR~
//            pct+=len;                                              //~va54I~//~vavaR~
//            resleno-=len;                                          //~va54I~//~vavaR~
//            break;                                                 //~va54I~//~vavaR~
//        }                                                          //~va54I~//~vavaR~
//#else       //set ddfmt from utf8                                  //~va50R~//~vavaR~
//      if (ct==XEERMCT_UTF8                                       //~va50I~//~vavcR~
//      if (ct==XEERMCT_UTF8CODE                                   //~vavcI~//~vawrR~
        if (0                                                      //~vawrI~
//#ifdef W32UNICODE        //linux use _UTF8WC at xefcmd24:IWF not found for cpu8 file//~vawHR~
//      ||  ct==XEERMCT_UTF8SUBC                                   //~vavaR~//~vavcR~
        ||  ct==XEERMCT_UTF8WC                                     //~vaw1I~
#ifdef W32UNICODE        //linux use _UTF8WC at xefcmd24:IWF not found for cpu8 file//~vawHI~
        ||  ct==XEERMCT_UTF8WCSUBC                                 //~vavcI~
#endif                                                             //~vawHR~
        ||  ct==XEERMCT_EBC                                        //~va50I~
        )                                                          //~va50I~
        {                                                          //~va50I~
        	opt=0;                                                 //~va50I~
			rc2=xeutf_cvf2dd(opt,pc,len,&pdddata,&pdddbcs,&outlen);//~va50I~
        	UALLOCCHKRC(rc2);                                      //~va50I~
	        len=min(outlen,resleno);                               //~va50I~
//          memcpy(plc,pdddata,len);                               //~vb01R~
            memcpy(plc,pdddata,(size_t)len);                       //~vb01I~
//      	memcpy(pcd,pdddbcs,len);                               //~vb01R~
        	memcpy(pcd,pdddbcs,(size_t)len);                       //~vb01I~
            plc+=len;                                              //~va50M~
            resleno-=len;                                          //~va50M~
#ifdef W32UNICODE                                                  //~vavaI~
//      	if (ct==XEERMCT_UTF8SUBC)                              //~vavaR~//~vavcR~
        	if (ct==XEERMCT_UTF8WCSUBC)                            //~vavcI~
                for (ii=0;ii<len;ii++,pcd++,pct++)                 //~vavaI~
                {                                                  //~vavaI~
                  if (*pcd)	//utf8 only                            //~vavLI~
                    *pct=XEUTFCT_UTF8;  //all in the path          //~vavaI~
                }                                                  //~vavaI~
            else                                                   //~vavaI~
#endif                                                             //~vavaR~
//      	if (ct==XEERMCT_UTF8)                                  //~va50I~//~vavcR~
//      	if (ct==XEERMCT_UTF8CODE)                              //~vavcI~//~vawrR~
        	if (ct==XEERMCT_UTF8WC)                                //~vawrI~
                for (ii=0;ii<len;ii++,pcd++,pct++)                 //~va50I~
                {                                                  //~va50I~
                	if (*pcd)                                      //~va50I~
                    	*pct=XEUTFCT_UTF8;                         //~va50I~
                }                                                  //~va50I~
            else                                                   //~va50I~
            {                                                      //~va50I~
	        	pct+=len;                                          //~va50I~
	            pcd+=len;                                          //~va50I~
            }                                                      //~va50I~
        }                                                          //~va50I~
        else                                                       //~va50I~
        {                                                          //~va50I~
        	rc=4;      //not xeerrmsg fmt                          //~va50I~
            break;                                                 //~va50I~
        }                                                          //~va50I~
//#endif                                                             //~va50I~//~vavaR~
        pu8=pc2+1;                                                 //~va54I~
    }                                                              //~va54I~
//  len=(ULONG)plc-(ULONG)Pplc;                                    //~va54I~//~vafkR~
//  len=(ULPTR)plc-(ULPTR)Pplc;                                    //~vb01R~
    len=(int)((ULPTR)plc-(ULPTR)Pplc);                             //~vb01I~
    if (Popt & XEUTFGLSMO_STRZ && resleno>0)                       //~va54I~
        *plc=0;                                                    //~va54I~
    *Pplenlc=len;                                                  //~va54I~
    return rc;                                                      //~va54I~//~va50R~
}//xeutf_seterrmsgct_forxeerrmsg                                   //~va54R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~//~va54I~
//**************************************************               //~va1CI~
//*xeutf_seterrmsgct                                               //~va54R~
//set codetype tbl for errmsg                                      //~va54I~
//called from xescr only                                           //~vau5I~
//output ddfmt for mistranslation by translation through f2l(germany by japanese)//~vau5I~
//**************************************************               //~va1CI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
int xeutf_seterrmsgct(int Popt,char *Ppu8,int Plenu8,char *Pplc,char *Pdbcs,char *Ppct,int Pbuffsz,int *Pplenlc)//~va50I~
#else                                                              //~va50I~
int xeutf_seterrmsgct(int Popt,char *Ppu8,int Plenu8,char *Pplc,char *Pdbcs,char *Ppct,int Pbuffsz,int *Pplenlc)//~va1CR~//~va50R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
{                                                                  //~va1CI~
	char *plc,*pct,*pu8,*pc,*pce;                                  //~va1CR~
//  char wkfpathlc[2][_MAX_PATH*UTF8_F2LMAXRATE];                  //~va1CI~//~vav9R~
//  char wkfpathct[2][_MAX_PATH*UTF8_F2LMAXRATE];                  //~va1CI~//~vav9R~
    char wkfpathlc[2][_MAX_PATHF2L];                               //~vav9I~
    char wkfpathct[2][_MAX_PATHF2L];                               //~vav9I~
    int idx,buffsz,lenu8,lenlc1,lenlc,lenlc2,offs,offs2,reslen,len,totlen;//~va1CR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	int rc2;                                                       //~va50I~//~vau7R~
    UCHAR *pdddbcs;                                        //~va5uR~//~vau7R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//#ifdef LNX                                                       //~vavpR~
//#else                                                            //~vavpR~
//#ifdef CCC                                                       //~vavpR~
//    int swu8fnm;                                                 //~vavpR~
//    char *pu82;                                                  //~vavpR~
//    int outlen;                                                  //~vavpR~
//    int ii;                                                      //~vavpR~
//    char *pct2;                                                  //~vavpR~
//    UCHAR *pdddata;                                              //~vavpR~
//    int u8chsz;                                                    //~vauDI~//~vavpR~
//#endif                                                           //~vavpR~
//#endif                                                           //~vavpR~
//**************************************************               //~va1CI~
//#ifdef LNX                                                       //~vau7R~
//    Popt|=XEUTFGLSMO_DDFMT;                                      //~vau7R~
//#endif                                                           //~vau7R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50R~//~va54I~
//search on pct                                                    //~va5nI~
//  if (memchr(Ppu8,XEERMCT_NOTLC,Plenu8))                         //~vb01R~
    if (memchr(Ppu8,XEERMCT_NOTLC,(size_t)Plenu8))                 //~vb01I~
    {                                                              //~va50I~
        rc2=xeutf_seterrmsgct_forxeerrmsg(Popt,Ppu8,Plenu8,Pplc,Pdbcs,Ppct,Pbuffsz,Pplenlc);//~va54R~//~va50R~
        if (rc2==2)                                                //~va50I~
        	return rc2;                                            //~va50I~
    }                                                              //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~//~va54I~
    UTRACED("xeutf_seterrmsgct inp u8",Ppu8,Plenu8);               //~vak5I~
    for (pc=Ppu8,pce=pc+Plenu8;pc<pce;pc++)                        //~va1CI~
    	if (!UTF8ISASCII(*pc))                                     //~va1CI~
        	break;                                                 //~va1CI~
    if (pc>=pce)                                                   //~va1CI~
    	return 0;	//all ascii                                    //~va1CI~
	idx=xeutf_chksaveedlcct(0,Ppu8,Plenu8,&offs);                  //~va1CI~
    UTRACEP("xeutf_seterrmsgct chksavedlcct idx=%d\n",idx);        //~vau5I~
    if (idx<0)	//not found                                        //~va1CR~
//#ifdef LNX                                                       //~vavpR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavpI~
	{                                                              //~vau5M~
//        rc2=xeutf_getmixedstr(Popt,Ppu8,Plenu8,Pplc,Pdbcs,Ppct,Pbuffsz,Pplenlc,0/*oututf8str*/,0/*oututf8buffsz*/,0/*out utf8len*/);//~vau7R~
//        if (rc2 & (XEUTFGU8MRC_UTF8|XEUTFGU8MRC_LC))             //~vau7R~
//            return 2;   //ddfmt                                  //~vau7R~
//        return rc2;                                              //~vau7R~
    	return xeutf_getmixedstrDDFMT(Popt,Ppu8,Plenu8,Pplc,Pdbcs,Ppct,Pbuffsz,Pplenlc);//~vau7R~
                                                                   //~vau7I~
    }                                                              //~vau5M~
#else                                                              //~vau5M~
    	return (xeutf_getmixedstr(Popt,Ppu8,Plenu8,Pplc,0/*dbcs*/,Ppct,Pbuffsz,Pplenlc,//~va1CI~
    							0/*oututf8str*/,0/*oututf8buffsz*/,0/*out utf8len*/) & XEUTFGU8MRC_UTF8);	//contains utf8 str//~va1CI~
#endif                                                             //~vau5I~
    lenu8=Stextu8len[idx];                                         //~va1CI~
//#ifdef LNX                                                         //~vau7M~//~vauER~
    lenlc=Stextddlen[idx];                                         //~vau7I~
//#ifdef LNX                                                       //~vavpR~
//#else                                                            //~vavpR~
//#ifdef CCC                                                       //~vavpR~
//    lenlc=Stextlclen[idx];                                       //~vavpR~
//    swu8fnm=0;                                                   //~vavpR~
//#endif                                                           //~vavpR~
//#endif                                                           //~vavpR~
//  if (!memchr(Stextct[idx],XEUTFCT_LC,lenlc)//no locale          //~vb01R~
    if (!memchr(Stextct[idx],XEUTFCT_LC,(size_t)lenlc)//no locale  //~vb01I~
//  &&   memchr(Stextct[idx],XEUTFCT_UTF8,lenlc))  //contains utf8 //~vb01R~
    &&   memchr(Stextct[idx],XEUTFCT_UTF8,(size_t)lenlc))  //contains utf8//~vb01I~
    {                                                              //~vamCI~
//#ifdef LNX                                                       //~vavpR~
//#else                                                            //~vavpR~
//#ifdef CCC                                                       //~vavpR~
//        swu8fnm=1;                                               //~vavpR~
////      lenlc=lenu8;                                               //~vamCI~//~vavpR~
//#endif                                                           //~vavpR~
//#endif                                                           //~vavpR~
    }                                                              //~vamCI~
    UTRACEP("xeutf_seterrmsgct chksave idx=%d,offs=%d,lenu8=%d,lenlc=%d\n",idx,offs,lenu8,lenlc);//~vak5I~
    UTRACED("xeutf_seterrmsgct textu8",Stextu8[idx],lenu8);        //~vak5I~
    UTRACED("xeutf_seterrmsgct ct",Stextct[idx],lenlc);            //~vak5I~
                                                                   //~va1CI~
    pu8=Ppu8;                                                      //~va1CI~
    buffsz=sizeof(wkfpathlc[0]);                                   //~va1CI~
    if (offs)                                                      //~va1CI~
    {                                                              //~va1CI~
        plc=wkfpathlc[0];       //locale                           //~va1CI~
        pct=wkfpathct[0];   //codetype                             //~va1CI~
//#ifdef LNX                                                         //~vau7R~//~vauER~
        pdddbcs=Pdbcs;                                             //~vau7I~
    	xeutf_getmixedstrDDFMT(Popt,pu8,offs,plc,pdddbcs,pct,buffsz,&lenlc1);	//lc2dd for before found word//~vau7I~
//#ifdef LNX                                                       //~vavpR~
//#else                                                            //~vavpR~
//#ifdef CCC                                                       //~vavpR~
//        xeutf_getmixedstr(Popt,pu8,offs,plc,0/*dbcs*/,pct,buffsz,&lenlc1,//~vavpR~
//                            0/*oututf8str*/,0/*oututf8buffsz*/,0/*out utf8len*/);//~vavpR~
//#endif                                                           //~vavpR~
//#endif                                                           //~vavpR~
    	UTRACED("xeutf_seterrmsgct 1st half ct",pct,lenlc1);       //~vaumI~
    }                                                              //~va1CI~
    else                                                           //~va1CI~
        lenlc1=0;                                                  //~va1CI~
    UTRACED("xeutf_seterrmsgct 1st half pu8",pu8,offs);            //~vau5I~
    UTRACED("xeutf_seterrmsgct 1st half dbcs",Pdbcs,lenlc1);       //~vau7R~
//#ifdef LNX                                                       //~vavpR~
//#else                                                            //~vavpR~
//#ifdef CCC                                                       //~vavpR~
////  pu82=pu8;   //lenu8 start                                                               //~va1CI~//~vamCR~//~vavpR~
//    pu82=pu8+offs;  //lenu8 start                                //~vavpR~
//#endif                                                           //~vavpR~
//#endif                                                           //~vavpR~
    offs2=offs+lenu8;                                              //~va1CR~
    pu8+=offs2;                                                    //~va1CI~
    reslen=Plenu8-offs2;                                           //~va1CI~
    UTRACEP("xeutf_seterrmsgct getmix pu8=%s,reslen=%d\n",pu8,reslen);//~vau9R~
    if (reslen>0)                                                  //~va1CI~
    {                                                              //~va1CI~
        plc=wkfpathlc[1];       //locale                           //~va1CI~
        pct=wkfpathct[1];   //codetype                             //~va1CI~
//#ifdef LNX                                                         //~vau7R~//~vauER~
        pdddbcs=Pdbcs+lenlc1+lenlc;                                //~vau7R~
      if (xeutf_seterrmsgctopd2(Popt,pu8,reslen,plc,pdddbcs,pct,buffsz/*of plc*/,&lenlc2)>=4)//no 2nd u8 opd//~vawrI~
    	xeutf_getmixedstrDDFMT(Popt,pu8,reslen,plc,pdddbcs,pct,buffsz,&lenlc2);	//lc2dd for before found word//~vau7I~
//#ifdef LNX                                                       //~vavpR~
//#else                                                            //~vavpR~
//#ifdef CCC                                                       //~vavpR~
//        xeutf_getmixedstr(Popt,pu8,reslen,plc,0/*dbcs*/,pct,buffsz,&lenlc2,//~vavpR~
//                            0/*oututf8str*/,0/*oututf8buffsz*/,0/*out utf8len*/);//~vavpR~
//#endif                                                           //~vavpR~
//#endif                                                           //~vavpR~
    	UTRACED("xeutf_seterrmsgct last ct",pct,lenlc2);           //~vaumI~
    }                                                              //~va1CI~
    else                                                           //~va1CI~
        lenlc2=0;                                                  //~va1CI~
    UTRACED("xeutf_seterrmsgct last pu8",pu8,reslen);              //~vau5I~
    UTRACED("xeutf_seterrmsgct last dbcs",Pdbcs+lenlc1+lenlc,lenlc2);//~vau5I~
                                                                   //~va1CI~
    totlen=lenlc1+lenlc+lenlc2;                                    //~va1CI~
    if (Popt & XEUTFGLSMO_STRZ)                                    //~va1CI~
    {                                                              //~va1CI~
    	if (Pbuffsz<=totlen)	//buff overflow                    //~va1CR~
	    	return 0;                                              //~va1CR~
    }                                                              //~va1CI~
    else                                                           //~va1CI~
    	if (Pbuffsz<totlen)	//buff overflow                        //~va1CI~
	    	return 0;                                              //~va1CI~
    len=lenlc1;                                                    //~va1CI~
    plc=Pplc;                                                      //~va1CI~
    pct=Ppct;                                                      //~va1CI~
    if (len>0)                                                     //~va1CI~
    {                                                              //~va1CI~
    	memcpy(plc,wkfpathlc[0],(UINT)len);                        //~va1CI~
    	memcpy(pct,wkfpathct[0],(UINT)len);                        //~va1CI~
        plc+=len;                                                  //~va1CI~
        pct+=len;                                                  //~va1CI~
    }                                                              //~va1CI~
                                                                   //~va1CI~
    len=lenlc;                                                     //~va1CR~
//#ifdef LNX                                                         //~vau7I~//~vauER~
    pdddbcs=Pdbcs+lenlc1;                                          //~vau7I~
    memcpy(plc,Stextdd[idx],(UINT)len);                            //~vau7I~
    memcpy(pct,Stextct[idx],(UINT)len);                            //~vau7I~
    memcpy(pdddbcs,Stextdddbcs[idx],(UINT)len);                    //~vau7I~
//#ifdef LNX                                                       //~vavpR~
//#else                                                            //~vavpR~
//#ifdef CCC                                                       //~vavpR~
//  if (swu8fnm)  //no locale code,ascii and utf8                  //~vavpR~
//  {                                                              //~vavpR~
//    //*plc will be reset laster by ddfmt                         //~vavpR~
//    UTRACED("xeutf_seterrmsgct by u8,u8",pu82,len);              //~vavpR~
////  for (ii=0,pct2=pct;ii<len;ii++,pct2++,pu82++)                  //~vamCR~//~vavpR~
//    for (ii=0,pct2=pct;ii<len;ii++,pct2++,pu82+=u8chsz)          //~vavpR~
//    {                                                            //~vavpR~
//        if (UTF8ISASCII(*pu82))                                  //~vavpR~
//        {                                                        //~vavpR~
//            *pct2=0;                                             //~vavpR~
//            u8chsz=1;                                            //~vavpR~
//        }                                                        //~vavpR~
//        else                                                     //~vavpR~
//        {                                                        //~vavpR~
//            *pct2=XEUTFCT_UTF8;                                  //~vavpR~
//            u8chsz=UTF8CHARLEN(*pu82);                           //~vavpR~
//        }                                                        //~vavpR~
//    }                                                            //~vavpR~
//     UTRACED("xeutf_seterrmsgct by u8,ct",pct,len);              //~vavpR~
//  }                                                              //~vavpR~
//  else                                                           //~vavpR~
//  {                                                              //~vavpR~
//    memcpy(plc,Stextlc[idx],(UINT)len);                          //~vavpR~
//    memcpy(pct,Stextct[idx],(UINT)len);                          //~vavpR~
//  }                                                              //~vavpR~
//#endif                                                           //~vavpR~
//#endif                                                           //~vavpR~
    UTRACED("xeutf_seterrmsgct found lc",plc,len);                 //~vau7I~
    UTRACED("xeutf_seterrmsgct found ct",pct,len);                 //~vau7I~
    plc+=len;                                                      //~va1CI~
    pct+=len;                                                      //~va1CI~
                                                                   //~va1CI~
    len=lenlc2;                                                    //~va1CR~
    if (len>0)                                                     //~va1CI~
    {                                                              //~va1CI~
    	memcpy(plc,wkfpathlc[1],(UINT)len);                        //~va1CI~
    	memcpy(pct,wkfpathct[1],(UINT)len);                        //~va1CI~
        plc+=len;                                                  //~va1CI~
    }                                                              //~va1CI~
    if (Popt & XEUTFGLSMO_STRZ)                                    //~va1CI~
        *plc=0;                                                    //~va1CI~
    *Pplenlc=totlen;                                               //~va1CR~
//#ifdef LNX                                                         //~vau7I~//~vauER~
//  if (memchr(Ppct,XEUTFCT_UTF8,totlen)//contains utf8 code       //~vb01R~
    if (memchr(Ppct,XEUTFCT_UTF8,(size_t)totlen)//contains utf8 code//~vb01I~
//  ||  memchr(Ppct,XEUTFCT_LC,totlen)) //contains dbcs code       //~vb01R~
    ||  memchr(Ppct,XEUTFCT_LC,(size_t)totlen)) //contains dbcs code//~vb01I~
    {                                                              //~vau7I~
    	UTRACED("xeutf_seterrmsgct rc=2 pu8",Ppu8,Plenu8);         //~vau7I~
    	UTRACED("xeutf_seterrmsgct  plc",Pplc,totlen);             //~vau7I~
    	UTRACED("xeutf_seterrmsgct dbcs",Pdbcs,totlen);            //~vau7I~
    	UTRACED("xeutf_seterrmsgct ct",Ppct,totlen);               //~vau7I~
    	return 2;		//id of dd fmt                             //~vau7I~
    }                                                              //~vau7I~
//#ifdef LNX                                                       //~vavpR~
//#else                                                            //~vavpR~
//#ifdef CCC                                                       //~vavpR~
//    if (memchr(Ppct,XEUTFCT_UTF8,totlen))//contains utf8 code    //~vavpR~
//    {                                                            //~vavpR~
////      if (xeutfcvlf2dd(0,Ppu8,Plenu8,0/*pdbcs*/,Ppct,totlen,&pdddata,&pdddbcs,Pbuffsz,&outlen) & XEUTFF2LRC_UTF8)  //not utf8 code detected//~va5uR~//~vavpR~
//        if (xeutfcvlf2dd_updatect(0,Ppu8,Plenu8,0/*pdbcs*/,Ppct,totlen,&pdddata,&pdddbcs,Pbuffsz,&outlen) & XEUTFF2LRC_UTF8)  //not utf8 code detected//~vavpR~
//        {                                                        //~vavpR~
//            memcpy(Pplc,pdddata,outlen);   //ddstr               //~vavpR~
//            memcpy(Pdbcs,pdddbcs,outlen);   //ddstr              //~vavpR~
//            *Pplenlc=outlen;                                     //~vavpR~
//    UTRACED("xeutf_seterrmsgct rc=2 pu8",Ppu8,Plenu8);           //~vavpR~
//    UTRACED("xeutf_seterrmsgct rc=2 plc",Pplc,outlen);           //~vavpR~
//    UTRACED("xeutf_seterrmsgct dbcs",Pdbcs,outlen);              //~vavpR~
//    UTRACED("xeutf_seterrmsgct ct",Ppct,outlen);                 //~vavpR~
//            return 2;       //id of dd fmt                       //~vavpR~
//        }                                                        //~vavpR~
//    }                                                            //~vavpR~
//#endif                                                           //~vavpR~
//#endif                                                           //~vavpR~
    UTRACEP("xeutf_seterrmsgct rc=1\n");                           //~vau5R~
    return 1;                                                      //~va1CI~
}//xeutf_seterrmsgct                                               //~va1CI~
#endif //UTF8SUPPH                                                 //~v904I~//~va00R~
//**************************************************               //~vawrI~
//*xeutf_seterrmsgct2nd                                            //~vawrI~
//set codetype tbl for errmsg                                      //~vawrI~
//output ddfmt for mistranslation by translation through f2l(germany by japanese)//~vawrI~
//*rc:1:done cv2dd for 2nd opd                                     //~vawrI~
//**************************************************               //~vawrI~
int xeutf_seterrmsgctopd2(int Popt,char *Ppu8,int Plenu8,char *Pdddata,char *Pdddbcs,char *Ppct,int Pbuffsz,int *Pplenlc)//~vawrI~
{                                                                  //~vawrI~
	char *plc,*pct,*pu8;                                           //~vawrR~
    char wkdddata[2][_MAX_PATHF2L];                                //~vawrR~
    char wkddct[2][_MAX_PATHF2L];                                  //~vawrR~
    int idx,buffsz,lenu8,lenlc1,lenlc,lenlc2,offs,offs2,reslen,len,totlen;//~vawrI~
    UCHAR *pdddbcs;                                                //~vawrI~
//**************************************************               //~vawrI~
	idx=xeutf_chksaveedlcct(0,Ppu8,Plenu8,&offs);                  //~vawrI~
    UTRACEP("%s:xeutf_seterrmsgct chksavedlcct idx=%d\n",UTT,idx); //~vawrI~
    if (idx<0)	//not found                                        //~vawrI~
    	return 4;  //do xeutf_getmixedstrDDFMT for all remaining   //~vawrI~
    lenu8=Stextu8len[idx];                                         //~vawrI~
    lenlc=Stextddlen[idx];                                         //~vawrI~
    UTRACEP("%s:xeutf_seterrmsgct chksave idx=%d,offs=%d,lenu8=%d,lenlc=%d\n",UTT,idx,offs,lenu8,lenlc);//~vawrI~
    UTRACED("xeutf_seterrmsgct textu8",Stextu8[idx],lenu8);        //~vawrI~
    UTRACED("xeutf_seterrmsgct ct",Stextct[idx],lenlc);            //~vawrI~
                                                                   //~vawrI~
    pu8=Ppu8;                                                      //~vawrI~
    buffsz=sizeof(wkdddata[0]);                                    //~vawrR~
    if (offs)                                                      //~vawrI~
    {                                                              //~vawrI~
        plc=wkdddata[0];       //locale                            //~vawrR~
        pct=wkddct[0];   //codetype                                //~vawrR~
        pdddbcs=Pdddbcs;                                           //~vawrR~
    	xeutf_getmixedstrDDFMT(Popt,pu8,offs,plc,pdddbcs,pct,buffsz,&lenlc1);	//lc2dd for before found word//~vawrI~
    	UTRACED("xeutf_seterrmsgct 1st half ct",pct,lenlc1);       //~vawrI~
    }                                                              //~vawrI~
    else                                                           //~vawrI~
        lenlc1=0;                                                  //~vawrI~
    UTRACED("xeutf_seterrmsgct 1st half pu8",pu8,offs);            //~vawrI~
    UTRACED("xeutf_seterrmsgct 1st half dbcs",Pdddbcs,lenlc1);     //~vawrR~
    offs2=offs+lenu8;                                              //~vawrI~
    pu8+=offs2;                                                    //~vawrI~
    reslen=Plenu8-offs2;                                           //~vawrI~
    UTRACEP("xeutf_seterrmsgct getmix pu8=%s,reslen=%d\n",pu8,reslen);//~vawrI~
    if (reslen>0)                                                  //~vawrI~
    {                                                              //~vawrI~
        plc=wkdddata[1];       //locale                            //~vawrR~
        pct=wkddct[1];   //codetype                                //~vawrR~
        pdddbcs=Pdddbcs+lenlc1+lenlc;                              //~vawrR~
    	xeutf_getmixedstrDDFMT(Popt,pu8,reslen,plc,pdddbcs,pct,buffsz,&lenlc2);	//lc2dd for before found word//~vawrI~
    	UTRACED("xeutf_seterrmsgct last ct",pct,lenlc2);           //~vawrI~
    }                                                              //~vawrI~
    else                                                           //~vawrI~
        lenlc2=0;                                                  //~vawrI~
    UTRACED("xeutf_seterrmsgct last pu8",pu8,reslen);              //~vawrI~
    UTRACED("xeutf_seterrmsgct last dbcs",Pdddbcs+lenlc1+lenlc,lenlc2);//~vawrR~
                                                                   //~vawrI~
    totlen=lenlc1+lenlc+lenlc2;                                    //~vawrI~
    if (Popt & XEUTFGLSMO_STRZ)                                    //~vawrI~
    {                                                              //~vawrI~
    	if (Pbuffsz<=totlen)	//buff overflow                    //~vawrI~
	    	return 4;                                              //~vawrI~
    }                                                              //~vawrI~
    else                                                           //~vawrI~
    	if (Pbuffsz<totlen)	//buff overflow                        //~vawrI~
	    	return 4;                                              //~vawrI~
    len=lenlc1;                                                    //~vawrI~
    plc=Pdddata;                                                   //~vawrR~
    pct=Ppct;                                                      //~vawrI~
    if (len>0)                                                     //~vawrI~
    {                                                              //~vawrI~
    	memcpy(plc,wkdddata[0],(UINT)len);                         //~vawrR~
    	memcpy(pct,wkddct[0],(UINT)len);                           //~vawrR~
        plc+=len;                                                  //~vawrI~
        pct+=len;                                                  //~vawrI~
    }                                                              //~vawrI~
                                                                   //~vawrI~
    len=lenlc;                                                     //~vawrI~
    pdddbcs=Pdddbcs+lenlc1;                                        //~vawrI~
    memcpy(plc,Stextdd[idx],(UINT)len);                            //~vawrI~
    memcpy(pct,Stextct[idx],(UINT)len);                            //~vawrI~
    memcpy(pdddbcs,Stextdddbcs[idx],(UINT)len);                    //~vawrI~
    UTRACED("xeutf_seterrmsgct found lc",plc,len);                 //~vawrI~
    UTRACED("xeutf_seterrmsgct found ct",pct,len);                 //~vawrI~
    plc+=len;                                                      //~vawrI~
    pct+=len;                                                      //~vawrI~
                                                                   //~vawrI~
    len=lenlc2;                                                    //~vawrI~
    if (len>0)                                                     //~vawrI~
    {                                                              //~vawrI~
    	memcpy(plc,wkdddata[1],(UINT)len);                         //~vawrR~
    	memcpy(pct,wkddct[1],(UINT)len);                           //~vawrR~
        plc+=len;                                                  //~vawrI~
    }                                                              //~vawrI~
    if (Popt & XEUTFGLSMO_STRZ)                                    //~vawrI~
        *plc=0;                                                    //~vawrI~
    *Pplenlc=totlen;                                               //~vawrI~
//  if (memchr(Ppct,XEUTFCT_UTF8,totlen)//contains utf8 code       //~vb01R~
    if (memchr(Ppct,XEUTFCT_UTF8,(size_t)totlen)//contains utf8 code//~vb01I~
//  ||  memchr(Ppct,XEUTFCT_LC,totlen)) //contains dbcs code       //~vb01R~
    ||  memchr(Ppct,XEUTFCT_LC,(size_t)totlen)) //contains dbcs code//~vb01I~
    {                                                              //~vawrI~
    	UTRACED("xeutf_seterrmsgct rc=2 pu8",Ppu8,Plenu8);         //~vawrI~
    	UTRACED("xeutf_seterrmsgct  plc",Pdddata,totlen);          //~vawrR~
    	UTRACED("xeutf_seterrmsgct dbcs",Pdddbcs,totlen);          //~vawrR~
    	UTRACED("xeutf_seterrmsgct ct",Ppct,totlen);               //~vawrI~
    	return 2;		//id of dd fmt                             //~vawrI~
    }                                                              //~vawrI~
    UTRACEP("%s:xeutf_seterrmsgct rc=1\n",UTT);                    //~vawrI~
    return 1;                                                      //~vawrI~
}//xeutf_seterrmsgctopd2                                           //~vawrI~
//**************************************************************** //~v6ufI~//~vbi4I~
//*chk dbcs errrep and 2 sbcs err,under the condition 2 string is unmatch//~v6ufI~//~vbi4I~
//*ret 1:unmatch,0:match                                           //~v6ufI~//~vbi4I~
//**************************************************************** //~v6ufI~//~vbi4I~
int xeutf_dbcssubcharcmp(int Popt,char *Plc,int Plen)//~v6ufI~     //~vbi4I~
{                                                                  //~v6ufI~//~vbi4I~
static char Sdbcssubchar[2];                                       //~vbi4R~
    int rc=1;                                                      //~v6ufI~//~vbi4I~
//*************                                                    //~v6ufI~//~vbi4I~
	if (!Sdbcssubchar[0])                                          //~vbi4I~
		if (!utf_setsubchar_dbcs(0,Sdbcssubchar))//no dbcs subchar      //~v6ufI~//~vbi4I~
    		return 1;                                                  //~v6ufI~//~vbi4I~
	if (Plen>=2)                                                   //~v6ufR~//~vbi4I~
    {                                                              //~v6ufI~//~vbi4I~
		if (Plc[0]==Sdbcssubchar[0]                               //~v6ufI~//~vbi4I~
		&&  Plc[1]==Sdbcssubchar[1]                               //~v6ufR~//~vbi4I~
        )                                                          //~v6ufI~//~vbi4I~
            rc=0;   //match                                        //~v6ufI~//~vbi4I~
    }                                                              //~v6ufI~//~vbi4I~
    return rc;                                                     //~v6ufI~//~vbi4I~
}//utf_subcharcmp                                                  //~v6ufI~//~vbi4I~
