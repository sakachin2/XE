//*CID://+v79MR~:                             update#=  659;       //~v79MR~
//*********************************************************************//~7712I~
//utf22.c                                                           //~7716R~//~vbz3R~
//* utf8 data manipulation:process using chof                      //~7712I~
//*********************************************************************//~7712I~
//v79M:240213 isolated combining character;defines it starting,ctrl and format.//~v79MI~
//v79L:240213 (Bug) base for combining; !isctrl & isalpha is not same.(it should be allowed 00a0)//~v79LI~
//v79F:240210 (Bug:LNX) ambiguous chk missing                      //~v79FI~
//v79E:240209 LNX:like v79C, no tbl reference for xe/gxe.          //~v79EI~
//            xe;-Nv:ambigous is all width=2, -Yv:ambiguous is all width=1//~v79EI~
//v79C:240208 W32:unicode display width;when ambigous char is written by 2 cell,it consume 3 cell.//~v79CI~
//            Those shows half width glyph if written by 1 cell even full width when written by 2 cells.//~v79CI~
//            Finally I decided that write all ambiguous(including WIDE and F2C1 previously defined) by 1 cell except defined as DBCS.//~v79CI~
//            No adjusting tbl is not required.                    //~v79CI~
//            P.S) No tbl use but ambiguous draw by 2 cells if /Nv option//~v79CI~
//v79r:240205 (WXE/XXE)fpr mapinit performance return always 1 at before HDC init//~v79rR~
//v79m:240131 (W32)try cursor chk for console xe                   //~v79mI~
//v79d:240123 (LNX & not ARM:Bug?)UTFWWO_API0 is not accompanied by UTFWWO_MK_WCWIDTH. it misses width=0 for wcwidth()=0.//~v79dI~
//vbz5:240120 try vbz3 to XXE(apichk by char extent)               //~vbz5I~
//v79a:240120 (Bug)mapwidth0 issue warning even if sbcsid remains. //~v79aI~
//vbz4:240120 try vbz3 to WXE                                      //~vbz4I~
//vbz3:240119 optionally chk wcwidth by cursor.  /Yv(default)      //~vbz3I~
//v799:240119 v798 by table(kanji is not ambiguout)                //~v799I~
//v798:240118 try v796 for ambigupus. 00a7,00a8,01cd,...           //~v798I~
//v796:240118 W32:try to chk cursor step for cpu8 file.            //~v796I~
//            Adjust culumn width by uftwcwidth for cursor width is single column to avoid column string move by cursor position//~v796I~
//v740:201221 modify "mapping tbl overflow" msg                    //~v70mI~
//v70m:200820 (ARM:BUG)save and load ucsmap missing width0top      //~v70mI~
//v70i:200716 Ucs.java' wcwidth is proper than adjsbcs             //~v70iI~
//v70h:200716 (BUG)if width0ctr==0, all non dbcs ucs is determined as width0//~v70hI~
//vc1c 2020/06/19 ARM;/proc/version access denied, use Build.VERSION.SDK_INT R RELEASE//~vc1cI~
//v708:200616 ARM:fopen(/proc/version) failed and signal(6) caused //~v708I~
//v700:200610 Axe:chtype not defined                               //~v700I~
//v6Y0:180823 additional to v6Xc,accept unicode specification as \uxxxx,add utfcvu2dd()//~v6Y0I~
//v6X5:180818 (LNX:xe)column shring COMB2SCM(036f+0390) even SPLIT mode,//~v6X5I~
//v6Wv:180807 (W32:Bug) console version on chcp=50221, utfcvf2l output string is over MACMBCSLEN by esc seq such as "Esc$B!)"//~v6WvI~
//v6Wu:180806 for also console version:set altch for SCM when COMBINE_NP,green if not adter combinable.//~v6WuI~
//v6Wt:180806 SCM is not combinable                                //~v6WtI~
//v6Wr:180804 process SCM same as NSM(NonSpacing Mark)             //~v6WrI~
//v6Wm:180724 utfwcwidth return len=1 for Category "Cf"(wcwidth=0)  if ucs<ENTNO(2 if ucs>=ENTNO).//~v6WmI~
//            determin combining for ucs>=ENTNOv should not use wcwidth==0 but combining definition//~v6WmI~
//v6Wi:180722 u+ad(Soft Hyphen) is wcwidth=0,bu combineprocess A0+ad show on 2 col. trate it as utfwcwidth=1//~v6WiI~
//v6W9:180708 dbcs combining char such as u309a(u306f+u309a) exists.//~v6W9I~
//v6W8:180708 (LNX)try dbcs+combining                              //~v6W8I~
//v6Vz:180626 (LNX:BUG)UTF_GETDDUCS1(utfdd2u1) returns ":;" for unprintable,add UTF_GETDDUCS1NP//~v6VzI~
//v6Vy:180626 (LNX:BUG)upto u20000,sbcs is dbcswidth=1(combineNP should replace to single byte)//~v6VyI~
//v6Vs:180622 allow dbcs to UTF_COMBINABLE                         //~v6VsI~
//v6Vq:180622 add utf22_isucswidth0(ucs)                           //~v6VqI~
//v6Vp:180621 (BUG)utfwcwidth returns 1 for combining char         //~v6VpI~
//v6Vm:180620 (W32)when surrogate pair err,use utfcvucs2u8(WideCharToMultibyte dose not notify err,but set utf8 of u-fffd)//~v6VmI~
//v6Vk:180620 (W32)when surrogate pair err,try to set sbcsid.(xe dirlist display fffd)//~v6VkI~
//v6Vg:180531 (Win) like as (LNX)v6V5, show org ucs for width0 ucs4(>=map entry)//~v6VgI~
//v6Vf:180615 (LNX:Bug)like v6Ve sbcsid=SBCS(DBCS is ok) of 0x010000<ucs<0x20000, cut dd value (ddlen=2-->1)//~v6VfI~
//v6Ve:180614 (LNX:Bug)utfcvu2dd1:xechar:makeucs4 fail for 0x010000<ucs<0x2000o//~v6VeI~
//v6Vb:180612 add isSpacingCombiningmark                           //~v6VbI~
//v6Va:180609 (LNX)when wcwidth=2 for defined as WIDE sbcs, displayed by 3 column,so reset wide to normal dbcs//~v6VaI~
//v6V7:180606 do not modify by wcwidth api,acept it only for return by mk_wcwidth//~v6V7I~
//v6V5:180531 show org ucs for width0 ucs4(>=map entry)            //~v6V5I~
//v6V4:180531 apply mk_wcwidth also for ucs4(>=map entry)          //~v6V4I~
//v6V1:180518 char width adjust to ubuntu 17.10(kernel 4.13.0)     //~v6V1I~
//            (LNX)set width=0 when wcwidth=0 if not defined as combinable on utf4//~v6V1I~
//v6T7:180220 stack errmsg to errmsg.<pid> and issue notification at initcomp//~v6T7I~
//v6T5:180217 WCons:Cmdline,WriteConsoleOutputW/WriteConsoleOutputCharacterW shrink colomn. Use WriteConsoleOutputChar if avail(when successful cv to locale,also for altch)//~v6T5R~
//v6K7:170327 (LNX)compiler warning;wcwidth not defined            //~v6K7I~
//            wchar.h is included from stdio.h and features.h #undef __USE_XOPEN//~v6K7I~
//            so #define _XOPEN_SOURCE before srdio.h              //~v6K7I~
//v6K0:170224 (BUG)compile err at arm                              //~v6K0I~
//v6Fc:160904 in addition to v6F3,also DBCS space altch is changable//~v6FcI~
//v6F4:160905 write default tab altch to ini file                  //~v6F4I~
//v6F3:160904 function to update visible altch for TAB/TABPAD      //~v6F3I~
//v6E9:160729 add strz option to utfcvdd2f                         //~v6E9I~
//v6E0:160717 (W32)chk printable by iswprint for dbcs              //~v6E0I~
//v6Dh:160621 avoid u-ffff is treated as dbcsspace(tabdisplay set ffff/() for dbcsspace//~v6DhR~
//v6Df:160618 del v6De,invalid effect to edit panel when tab off   //~v6DfI~
//v6De:160616 on dirlist dpcsspace id not drawn by altch(draw 2 space)//~v6DeI~
//v6Dd:160616 (BUG by v6BS);DBCS space did not properly displayed when tab display mode.(tabdsiplay set 0xff for dbcsspace)//~v6DdI~
//v6Dc:160613 use u-25a1 for unprintable dbcs                      //~v6DcI~
//v6Db:160613 (XXE)on dirlist Non printable ucs was dispalyed as sbcs-altch + ucs 2nd byte//~v6DbI~
//v6C4:160331 change modify parameter range err msg                //~v6C4I~
//v6C2:160328 consideration for dbcssz>2 case(UDBCSCHK_DBCSPAD chk )//~v6C2I~
//v6C0:160328 LNX wcwidth returns -1 for non-character(0xfffe/0xffff/0x1ffe/...), do also on Windows.//~v6C0I~
//v6BZ:160327 roundup width0 boundary to dbcsid=xx00 to avoid increasing testcase by change of UDBCSCHK_ISUCSWIDTH0//~v6BZR~
//v6BY:160326 not fixed width0 ucs boundary                        //~v6BYI~
//v6BP:160313 (W32)utf162ucs4 for wxe                              //~v6BPI~
//v6BM:160308 add utfdd2u4 for xprint                              //~v6BMI~
//v6BC:160306 W32:iswprint support BMP(ucs2) only                  //~v6BCI~
//v6Bx:160212 (LNX)compiler warning at suse64                      //~v6BxI~
//v6Bk:160220 (LNX)compiler warning                                //~v6BkI~
//v6B4:160116 Lnx compiler warning                                 //~v6B4I~
//v6B3:160116 Win compiler warning                                 //~v6B3I~
//v6x8:150110 (warning C4244) not about ULPTR                      //~v6x8I~
//v6uL:140603 split next option for utfddpos2offs(3byte advance for ucs4)//~v6uLI~
//v6uB:140523 (Win:UNICODE)dbcsid:overflow for ucs4 on Windows     //~v6uBI~
//v6um:140502 add utfddicmp                                        //~v6umI~
//v6uf:140424 (BUG)f2l compare should chk dbcs subchr              //~v6ufI~
//v6ue:140423 (Win:BUG)See v6u7;surrogate pair support (!UTF8UCS4 but UCS4(WUCS is 4 byte when UTF8UCS4)),treate as 2 unprintable//~v6ueR~
//v6ua:140410 (Win)use UNICODE Api;apply WIN32_FIND_DATAW by "#ifdef W32UNICODE" 
//v6p2:131008 dd2f option;rep null by altch for gtkprint           //~v6p2I~
//v6k1:130524 (Axe)sbcsmap tbl recreate option(test use)           //~v6k1R~
//v6hr:120714 suse64:unused warning                                //~v6hrI~
//v6hp:120704 (BUG:XXE) display altch for null(if dbcs exists on 1/2/3.12/3.14 panel//~v6hpI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6h7:120609 (VC6)avoid c4701 warning by VC6(used uninitialized variable)//~v6h7I~
//v6h4:120604 (WTL)vs2010exp stop if used uninitialized variable   //~v6h4I~
//v6c7:120127 try save/restore sbcstbl for quick startup           //~v6c7I~
//v6c5:120121 (Axe)no mk_wcwidth,completeley depends to wcwwidth(Java getTextWidths)(but allow adjust by parameter file)//~v6c5I~
//v6bt:111230 utfcvf2dd:add option to return chklen if reached outwidth//~v6b9I~
//v6b9:111117 (gcc4.6)Warning:unused-but-set                       //~v6b9I~
//v6a0:110520 Android porting(-DARM)                               //~v6a0I~
//v69z:101003 l2ddtab(chk dbcstbl for tab)                         //~v69zI~
//v69b:100808 sbcsid overflow;fix of v69a; expand start point from 0x__30-->0x__21 for sbcsid//~v69bI~
//v69a:100808 sbcsid overflow;temporary(HHH) expand to 6800-->6c00; target is assigning from >0x__20//~v69aI~
//            current status by /c850 width0=6c00->6fe4(x1b remains),sbcs:0100-->6bed(x12 remains)//~v69aI~
//            Lnx reduce by chking wcwidth=-1,Win has no wcwidth and iswprint redule large number containing actualy printable//~v69aI~
//v697:100807 (W32)sbcs map tbl overflow for non CJK; chk printable because win has no wcwidth which linux has.//~v697I~
//v68f:100707 (BUG)ddfmt punctuation chk is not chked TAB(err IWF func)//~v68fI~
//v67Z:100615 (LNX)sbcsid overflowed at ub9(ue000-u8ff private area is assigbed as sbcs)//~v67ZI~
//            remap should reassign for overflowed ucs             //~v67ZI~
//v66m:100529 (LNX:BUG)SO/SI chk only for dbcs converter           //~v66mI~
//v66e:100522 set dbcs errrep to f2l/dd2l for mixedstrupdate(rep to sbcs "?" will loose dbcsid on dbcstbl)//~v66eI~
//v66d:100521 nullrep option for dd2u for wxe C&P                  //~v66dI~
//v667:100510 utf8 sbcs support for pbrk,memchr                    //~v667I~
//v665:100510 add UTF_umemrpbrk                                    //~v665I~
//v664:100502 (BUG) DD chk miss if >0x80 is detected before DD fmt chk//~v664I~
//v663:100501 (BUG) punc chk faile for 0x2020 (utf8 dbcs) when csr is on 1st 20//~v663I~
//v660:100325 local EBCDIC translation support                     //~v660I~
//v65p:100401 v65n for LNX                                         //~v65pI~
//v65n:100331 default tab/tab padding is shown by 0xff as data value//~v65nI~
//v65m:100329 to print 0x14 glyph(q:0xb6),use another altchar(0xff)//~v65mI~
//v65i:100327 (WinCons)display 0x1b by unicodwe letterlike symbols u21xx because 0x1b make trouble for line clear//~v65gI~
//v65g:100320 compare utf8 dbcs split string option                //~v65gI~
//v65f:100314 (gxe)dbcs space is nor replaced by tab char          //~v65fI~
//v65c:100302 (LNX)UCS4 support                                    //~v65cI~
//v650:100121 print width=0                                        //~v650I~
//v640:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~v640I~
// ucs2 vio                                                        //~v640I~
//   usual sbcs   : if wcwidth=2 -->narrow   (u1+' ')+(u2+' ')     //~v640R~
//                  (to use two char_t, keep chsz=2)               //~v640I~
//                  if wcwidth=1              u1                   //~v640I~
//   usual dbcs   : if wcwidth=2             u1+u2                 //~v640I~
//                  if wcwidth=1             u1+u2                 //~v640I~
//   wide  sbcs   : ex) u00a3(Pond currency), u01f1(DZ)            //~v640I~
//                  if wcwidth=2              (u1+' ')+(u2+' ')    //~v640R~
//                  if wcwidth=1              u+' '                //~v640R~
//   narrow dbcs  : ex) u-ff70(katakana-a)                         //~v640I~
//                  if wcwidth=2             (u1+' ')+(u2+' ')     //~v640I~
//                  if wcwidth=1              no case(change to len=1(sbcs))//~v640R~
//*********************************************************************//~7712I~
#ifdef UTF8UCS2                                                    //~v640I~
	#ifdef W32                           //v3.6a                   //~v022M~//~v640I~
		#include <windows.h>	         //v1.3 add                //~v022M~//~v640I~
    #endif                                                         //~v640I~
#endif                                                             //~v640I~
#ifdef LNX                                                         //~v6K7R~
 	#define _XOPEN_SOURCE       //set before first include wchar.h //~v6K7R~
#endif                                                             //~v6K7R~
#include <stdio.h>                                                 //~7712I~
#include <stdlib.h>                                                //~7712I~
#include <ctype.h>                                                 //~7712I~
#include <string.h>                                                //~7712I~
#include <errno.h>                                                 //~7712I~
#ifdef LNX                                                         //~7712I~
	#include <iconv.h>                                             //~v61bI~
// 	#define __USE_XOPEN         //for wcwidth                      //~v640I~//~v6K7R~
    #include <wchar.h>                                             //~7712I~
//  #include <langinfo.h>                                          //~v6a0R~
#endif                                                             //~7712I~
	#ifdef LNX                                                     //~v640M~
		#define _XOPEN_SOURCE_EXTENDED		//ncurses define       //~v640M~
		#include <ucurses.h>	         //v1.3 add                //~v640M~
    #endif                                                         //~v640M~
#include <locale.h>                                                //~v61bI~
//*******************************************************          //~7712I~
#include <ulib.h>                                                  //~7712I~
#include <ualloc.h>                                                //~7824I~
#include <udbcschk.h>                                              //~v60aI~
#include <uque.h>                                                  //~7712I~
#include <ucvucs.h>                                                //~7712I~
#include <utf.h>                                                   //~7712I~
#include <ustring.h>                                               //~v61bI~
#include <utrace.h>                                                //~7712I~
#include <uerr.h>                                                  //~7712I~
#include <utf.h>                                                   //~7712I~
#include <utf2.h>                                                  //~7712I~
#define UTF22_GBL                                                  //~v640I~
#include <uedit.h>                                                 //~v640R~
#include <utf22.h>                                                 //~v640I~
#include <uvio.h>                                                  //~v640R~
#include <uvio2.h>                                                 //~v796I~
#ifdef LNX                                                         //~v6V5R~//~v700I~
    #ifndef XXE                                                    //~v6V5I~//~v700I~
		#ifndef NOCURSES                                                   //~v6a0I~//~v700I~
#include <uviom.h>                                                 //~v640I~
	    #endif                                                     //~v700I~
    #endif                                                         //~v6V5I~//~v700I~
#endif                                                              //~v6V5R~//~v700R~
#ifdef W32                                                         //~v6c7I~
	#include <udos.h>                                              //~v6c7I~
    #ifdef WXE                                                     //~vbz4I~
		#include <wxexei.h>                                        //~vbz4I~
    #endif                                                         //~vbz4I~
#else                                                              //~vbz5I~
    #ifdef XXE                                                     //~vbz5R~
		#include <xxexei.h>                                        //~vbz5I~
    #endif                                                         //~vbz5I~
#endif                                                             //~v6c7I~
#include <ulibarm.h>                                               //~v6k1I~
#include <ucvebc.h>                                                //~v6DbI~
//**************************************************               //~v61bI~
//#define PRIVATE_REGION(ucs) (ucs>=0xe000 && ucs<0xf900)          //~v798R~//~v799R~
//#define KANJI_REGION(ucs) (ucs>=0x2e80 && ucs<0xa000)            //~v798R~//~v799R~
//#define DBCS_REGION(ucs) (PRIVATE_REGION(ucs)||KANJI_REGION(ucs)) //~v798R~//~v799R~
typedef struct _SAVESBCSTB                                         //~v6c7I~
{                                                                  //~v6c7I~
	int SSTversion;                                                //~v6c7I~
	int SSTflag;                                                   //~v6c7I~
	int SSTseqno;                                                  //~v6c7I~
    int SSTsbcsctr;                                                //~v6c7I~
                                                                   //~v6c7I~
	int SSTovfctr;                                                 //~v6c7I~
    int SSTovfucs;                                                 //~v6c7I~
    int SSTovfucslast;                                             //~v6c7I~
	int SSTovfctrw0;                                               //~v6c7I~
                                                                   //~v6c7I~
    int SSTovfucsw0;                                               //~v6c7I~
    int SSTovfucsw0last;                                           //~v6c7I~
	int SSTlength1;                                                //~v6c7I~
	int SSTlength2;                                                //~v6c7I~
//  int SSTrsv[8];                                                 //~v6c7I~//~v70mR~
	int SSTwidth0top;                                              //~v70mI~
    int SSTrsv[4];                                                 //~v70mI~
} SAVESBCSTB, *PSAVESBCSTB;                                        //~v6c7R~
static int Stabs[]={                                               //~v6F3M~
#ifdef LNX                                                         //~v6F3M~
//                  0x2191,0x21be,'^',0,'^',  //up allow for TAB   //~v6F4R~
//                  0x2192,0x21c0,',',0,',',  //right allow for TAB PADDING//~v6F4R~
             UTF22_TABALT1,0     ,'^',0,'^',  //up allow for TAB   //~v6F4I~
             UTF22_TABALT2,0     ,',',0,',',  //right allow for TAB PADDING//~v6F4I~
//                  0x2591,0,     '!',0,'!',  //for DBCS space     //~v6FcR~
             UTF22_DBCSSPACEALT,0,'!',0,'!',  //for DBCS space     //~v6FcI~
                    0x25aa,0,     '.',0,'.',  //for unprintabe     //~v6F3M~
#else                                                              //~v6F3M~
//                  0x2191,0x21be,'^',0,0x181c,  //up allow for TAB eng+jpn//~v6F3M~
//                  0x2192,0x21c0,',',0,0x1a1e,  //right allow for TAB PADDING//~v6F3M~
//                  0x2191,0x21be,'^',0,0x1818,  //up allow for TAB eng+jpn//~v6F4R~
//                  0x2192,0x21c0,',',0,0x1a1a,  //right allow for TAB PADDING//~v6F4R~
             UTF22_TABALT1,0     ,'^',0,0x1818,  //up allow for TAB eng+jpn//~v6F4I~
             UTF22_TABALT2,0     ,',',0,0x1a1a,  //right allow for TAB PADDING//~v6F4I~
//                  0x2591,0,     '!',0,0xb114, //for DBCS space english:b1,japanese:14//~v6FcR~
             UTF22_DBCSSPACEALT,0,'!',0,0xb114, //for DBCS space english:b1,japanese:14//~v6FcI~
                    0x25aa,0,     '.',0,0x2e2e, //for unprintabe   //~v6F3M~
#endif                                                             //~v6F3M~
                    0                                              //~v6F3M~
                    };                                             //~v6F3M~
  static int Sinitsw;                                              //~v6F3I~
//#define OVFMSG   	"UCS map tbl overflow"                         //~v67ZR~//~v697R~
//#define OVFMSG   	"Warning:UCS map tbl overflow. Treate this range as DBCS(adjustable by ini file)."//~v697R~//~v6BYR~
//#define OVFMSG      "Warning:UCS map tbl overflow. Treated this range as DBCS(adjustable by ini file)."//~v6BYI~//~v70mR~
#define OVFMSG      "Info:UCS map tbl overflow. This range is treated as DBCS."//~v70mR~
static int Sasciilen;                                              //~v640I~
static char *Ssbcstbfnm;                                           //~v6c7I~
//static int Slastsbcsid;                                          //~v67ZR~
//static int Slastsbcsidw0;                                        //~v67ZR~
int utfucsloadmap(int Popt,PSAVESBCSTB Ppsbcstbhdr);               //~v6c7I~
int utfucssavemap(int Popt,PSAVESBCSTB Ppsbcstbhdr);               //~v6c7I~
//ULONG utf22_setunpucsvio(int Popt,ULONG Pucs,int Pdbcsid,int *Prc);//~v6DbR~//~v6T5R~
#define  UT22SUUVO_OVF            0x01    //dbcsid:OVF             //~v6DbR~
int utf22_setdbcsspacealt(int Popt,UWUCS Pucs,char *Ppdbcs,int Preslen,int *Ppaltch);//~v6DdR~
//**************************************************               //~7801M~
#ifdef UTF8UCS2                                                    //~v640R~
#ifdef LNX                                                         //~v640M~
//***************************************************************************//~vbz5I~
//***************************************************************************//~vbz5I~
#ifdef XXE                                                         //~vbz5I~
int utfwwapichkCursorXXE(int Popt,ULONG Pucs,int Pmkwidth,int *Ppflag)//~vbz5I~
{                                                                  //~vbz5I~
	int flag,width,cursorstep,swcallxxe;                           //~vbz5R~
#ifndef NOTRACE                                                    //~vbz5I~
    UCHAR utf8[12];                                                //~vbz5I~
    int u8len;                                                     //~vbz5I~
#endif    	                                                       //~vbz5I~
//*************************                                        //~vbz5I~
	flag=*Ppflag;                                                  //~vbz5I~
    width=Pmkwidth;                                                //~vbz5I~
    if (!(Gulibutfmode & GULIBUTF_APICHK_CSR)) //0x08000000  //utfwcwidth chr cursor step//~vbz5I~
    	return width;                                              //~vbz5I~
    if (!(Gulibutfmode & GULIBUTF_APICHK_CSR2)) //after Font init  //~vbz5R~
    	return width;                                              //~vbz5I~
    if (IS_UTF16_HIGH(Pucs)||IS_UTF16_LOW(Pucs))  //UTF16 pair     //~vbz5R~
    	return width;                                              //~vbz5I~
    UTRACEP("%s:entry ucs=0x%04x,utf8=(  %s  ),wcwidth=%d,Pmkwidth=%d,flag=0x%04x\n",UTT,Pucs,(u8len=uccvucs2utf((UWUCS)Pucs,utf8),utf8[u8len]=0,utf8),wcwidth((wchar_t)Pucs),width,flag);//~vbz5R~
    if (width==0 || width==-1)                                     //~vbz5I~
        return width;                                              //~vbz5I~
    swcallxxe=0;                                                   //~vbz5I~
	if (flag & UTFWWO_MK_AMBIGUOUS)  //x2000   //by mk_wcwidth() adjustable by wcwidth()//~vbz5I~
        if (wcwidth((wchar_t)Pucs)!=2)                             //~vbz5I~
    		swcallxxe=1;                                           //~vbz5I~
    if (flag & UTFWWF_F2C1)  //  0x80   //WideSBCS; font width=2,distance to next column=1//~vbz5I~
    	swcallxxe=1;                                               //~vbz5I~
    if (swcallxxe)                                                 //~vbz5I~
    {                                                              //~vbz5I~
	    if (flag & UTFWWO_MK_AMBIGUOUS)  //x2000   //by mk_wcwidth() adjustable by wcwidth()//~vbz5R~
        	if (wcwidth((wchar_t)Pucs)==2)                         //~vbz5R~
            	return width;    //2                               //~vbz5R~
        cursorstep=xxe_GetCursorWidth(0,Pucs);                     //~vbz5R~
        if (cursorstep>0 && cursorstep!=width)                     //~vbz5R~
        {                                                          //~vbz5R~
            *Ppflag=0;                                             //~vbz5R~
            width=cursorstep;                                      //~vbz5R~
        }                                                          //~vbz5R~
        UTRACEP("%s:callxxe ucs=x%04x,utf8=(  %s  ),width=%d->%d,wcwidth()=%d,flag=0x%04x,updated=%s\n",UTT,Pucs,(u8len=uccvucs2utf((UWUCS)Pucs,utf8),utf8[u8len]=0,utf8),Pmkwidth,width,wcwidth((wchar_t)Pucs),flag,Pmkwidth==width?"N":"Y");//~vbz5R~
    }                                                              //~vbz5I~
    return width;                                                  //~vbz5I~
}//utfwwapichkCursorXXE                                            //~vbz5R~
#endif  //XXE                                                      //~vbz5I~
//*******************************************************          //~v640M~
//*set flag by wcwidth return code                                 //~v640M~
//*for ucs which utfwcwidthsub determind printable(rc>=0)          //~v6c5I~
//*for ARM4,edtermin from wcwidth() at first                       //~v6c5I~
//*******************************************************          //~v640M~
int utfwwapichk(int Popt,ULONG Pucs,int Pmkwidth,int *Ppflag/*masked*/,int *Ppwcwidth)//~v640M~//~vbz3R~
{                                                                  //~v640M~
	int wcw,flag,width;                                            //~v640M~
#ifndef XXX                                                        //~v6WvI~
    int rc2;                                                       //~v6WvI~
#endif                                                             //~v6WvI~
#ifndef NOTRACE                                                    //~vbz5I~
    UCHAR utf8[12];                                                //~vbz5I~
    int u8len;                                                     //~vbz5I~
#endif                                                             //~vbz5I~
	int swAmbigChange;                                             //~v79EI~
//*************************                                        //~v640M~
    if (Pucs==(ULONG)GutfTestUcs)                                  //~v79FI~
    {                                                              //~v79FI~
        UTRACEP("%s:Debug trap by GutfTestUcs ucs=%04x\n",UTT,Pucs);	//@@@@test//~v79FI~
    }                                                              //~v79FI~
	flag=*Ppflag;                                                  //~v640M~
    width=Pmkwidth;                                                //~v640M~
//  wcw=wcwidth((wchar_t)Pucs);   //better to return large value even displayed 1 cell on english terminal//~v640M~//~v6a0R~
    wcw=wcwidth((UWCHART)Pucs);   //better to return large value even displayed 1 cell on english terminal//~v6a0I~
    if (Ppwcwidth)                                                 //~v640M~
        *Ppwcwidth=wcw;                                            //~v640M~
    if (wcw>0)                                                     //~v640M~
    {                                                              //~v640M~
#ifdef ARM	//adjsbcs set Pmkwcwidth to reduce sbcs                //~v70iM~
		if (wcw==2 || Pmkwidth==2)	//by Ucs.java or adjsbcs       //~v70iI~
        	width=2;                                               //~v70iR~
        else                                                       //~v70iI~
        	width=1;                                               //~v70iI~
#else  //!ARM                                                      //~v70iI~
        if (flag & UTFWWF_F1C1)      //Narrow DBCS                 //~v640M~
        {                                                          //~v640M~
            if (wcw==1)  //wcwidth=1                               //~v640M~
            {                                                      //~v640I~
            	width=1;			//same as sbcs when wcwidth=1  //~v640M~
        		flag &= ~UTFWWF_F1C1;      //usual SBCS            //~v640I~
            }                                                      //~v640I~
        }                                                          //~v640M~
        else                                                       //~v640M~
        if (!(flag & UTFWWF_F2C1))   //no tbl defintion            //~v640M~
        {                                                          //~v640M~
        	swAmbigChange=0;                                       //~v79EI~
    	    if ((flag & UTFWWO_MK_AMBIGUOUS)                       //~v79FR~
            &&  wcw==1                                             //~v79EI~
            &&  Pmkwidth==2)                                       //~v79EI~
            {                                                      //~v79EI~
#ifdef XXE            	                                           //~v79EI~
#else                                                              //~v79EI~
				if (UTF_AMBIG2CELLMODE())	//1 cell mode for ambiguous//~v79EI~
                	width=2;                                       //~v79EI~
                else                                               //~v79EI~
                	width=1;                                       //~v79EI~
#endif                                                             //~v79EI~
	        	swAmbigChange=1;                                   //~v79EI~
            }                                                      //~v79EI~
            if (swAmbigChange)                                     //~v79EI~
            {                                                      //~v79EI~
                UTRACEP("%s:ambigous ucs=0x%04x(%s),wcwidth()=%d,Pmkwidth=%d,set width=%d\n",//~v79ER~
						UTT,Pucs,UTF_GETUTF8STR(Pucs,utf8,u8len),wcw,Pmkwidth,width);//~v79ER~
            }                                                      //~v79EI~
//          else                                                   //~v79EI~//~v79FR~
//  	    if ((Popt & UTFWWO_MK_AMBIGUOUS) 	//ARM4             //~v6V7I~//~v79FR~
//    	    if ((flag & UTFWWO_MK_AMBIGUOUS)                       //~v79FR~
//          &&  wcw==0                      !! NO path by wcw=0    //~v79FR~
//          &&  Pmkwidth!=wcw)                                     //~v6V7I~//~v79FR~
//          {                                                      //~v6V7I~//~v79FR~
//          	width=wcw;                                         //~v6V7I~//~v79FR~
//              UTRACEP("%s:ambiguous wcw=0 wcwidth()=%d,utfwcw=%d,return width=%d\n",UTT,wcw,Pmkwidth,width);//~v6V7I~//~v79FR~
//          }                                                      //~v6V7I~//~v79FR~
            else                                                   //~v6V7I~
    	    if ((Popt & UTFWWO_MK_WCWIDTH) 	//ARM4                 //~v6V7I~
            &&  Pmkwidth!=wcw)                                     //~v6V7I~
            {                                                      //~v6V7I~
//  		  if (!(Popt & UTFWWO_MK_COMB))   //combining definition//~v6W9R~//~v6WmR~
    		  if (!(flag & UTFWWF_COMB))   //combining definition  //~v6WmR~
              {                                                    //~v6WiI~
            	width=wcw;                                         //~v6V7I~
                UTRACEP("%s:unmatch wcwidth()=%d,mk_wcwidth()=%d,return width=%d\n",UTT,wcw,Pmkwidth,width);//~v6V7I~
              }                                                    //~v6WiI~
            }                                                      //~v6V7I~
            else                                                   //~v6VaI~
            if (Pmkwidth==1 && wcw==2)  //sbcs but wcwidth=2       //~v640M~
            {                                                      //~v640M~
        	  if (!(flag & UTFWWF_SBCSF))   //no tbl defintion     //~v6WiI~
              {                                                    //~v6WiI~
                flag|=UTFWWF_F1C1;      //Narrow DBCS when wcwcidth=2//~v640M~
                width=2;                //occupy 2 column          //~v640M~
                UTRACEP("%s:%04x change width 1 to 2 by wcwidth()\n",UTT);//~v6WiI~//~v70hR~
              }                                                    //~v6WiI~
            }                                                      //~v640M~
//            else                                                 //~v640R~
//            if (Pmkwidth==2 && wcw==1)  //dbcd but wcwidth=1     //~v640R~
//            {                                                    //~v640R~
//                width=1;                //occupy 1 column        //~v640R~
//            }                                                    //~v640R~
        }                                                          //~v640M~
        else //F2C1 Wide sbcs                                      //~v6VaI~
        {                                                          //~v6VaI~
            if (wcw==2 && Pmkwidth==2)	//dbcs                     //~v6VaI~
                flag&=~UTFWWF_F2C1;      //reset WIDE sbcs         //~v6VaR~
        }                                                          //~v6VaI~
#endif //!ARM                                                      //~v70iI~
    }                                                              //~v640M~
    else                                                           //~v640I~
    if (wcw)                                                       //~v650I~
    {                                                              //~v6BZI~
		UTRACEP("%s:wcwidth err rc=%d for ucs=%04x\n",UTT,wcw,Pucs);//~v6BZI~
    	width=-1;                                                  //~v640I~
    }                                                              //~v6BZI~
    else                                                           //~v650I~
    {                                                              //~v6c5I~
//      flag|=UTFWWF_WIDTH0;    //combining char                   //~v650I~//~v6V7R~
//  	if (Popt & UTFWWO_APIW0)	//ARM4                         //~v6c5R~//~v6V7R~
//  	if (Popt & (UTFWWO_APIW0|UTFWWO_MK_WCWIDTH))	//ARM4     //~v6V7I~//~v6VpR~
//    	if (Pmkwidth && (Popt & (UTFWWO_APIW0|UTFWWO_MK_WCWIDTH)))	//ARM4//~v6VpI~//~v6WiR~
#ifdef ARM                                                         //~v70iI~
        width=0;                //accept result of wcwidth(),get sbcsid for width0//~v70iI~
        flag|=UTFWWF_WIDTH0;    //combining char                   //~v70iI~
        UTRACEP("%s:wcwidth()=%d,mk_wcwidth()=%d,return width=%d,flag=%x\n",UTT,wcw,Pmkwidth,width,flag);//~v70iI~
#else                                                              //~v70iI~
      if (!(Popt & UTFWWO_FORMAT))                                 //~v6WiR~
      {                                                            //~v6WiI~
//     	if (Pmkwidth && (Popt & (UTFWWO_APIW0|UTFWWO_MK_WCWIDTH))==(UTFWWO_APIW0|UTFWWO_MK_WCWIDTH))//ARM4//~v6WiI~//~v79dR~
      	if (Pmkwidth && (Popt & UTFWWO_APIW0))                     //~v79dR~
        {                                                          //~v6V7I~
        	width=0;				//accept result of wcwidth(),get sbcsid for width0//~v6c5I~
			flag|=UTFWWF_WIDTH0;    //combining char               //~v6V7I~
            UTRACEP("%s:@@@@set ucs=0x%04x,width=0 by unmatch wcwidth()=%d,mk_wcwidth()=%d,return width=%d,flag=%x\n",UTT,Pucs,wcw,Pmkwidth,width,flag);//~v6V7I~//~v6VpM~//~v79dI~//~vbz5R~
        }                                                          //~v6V7I~//~v6VpM~
        UTRACEP("%s:%06x unmatch wcwidth()=%d not Format ,mk_wcwidth()=%d,return width=%d,flag=0x%04x\n",UTT,Pucs,wcw,Pmkwidth,width,flag);//~v6WiR~//~vbz5R~
      }                                                            //~v6WiI~
      else                                                         //~v79dI~
        UTRACEP("%s:@@@@FORMAT ucs=0x%04x wcwidth()=%d ,mk_wcwidth()=%d,return width=%d,flag=0x%04x\n",UTT,Pucs,wcw,Pmkwidth,width,flag);//~v79dR~//~vbz5R~
#endif                                                             //~v70iI~
    }                                                              //~v6c5I~
//UTRACEP("apichk sizeof uwchart=%d,ucs=%4x,wcwidth=%d,mkw=%d,ret-width=%d,flag=0x%04x->0x%04x\n",sizeof(UWCHART),Pucs,wcw,Pmkwidth,width,*Ppflag,flag);//~v6a0R~//~v6b9R~//~v6c5R~//~v6p2R~//~vbz5R~
#ifdef XXX                                                         //~v6WvI~
	if (!flag && (width==1||width==2))                             //~v6VbR~
#else                                                              //~v6WvI~
	if (width>=0 && width<=2)                                      //~v6WvR~
#endif                                                             //~v6WvI~
    {                                                              //~v6VbR~
#ifdef XXX                                                         //~v6WvI~
		if (utf4_isSpacingCombiningMark(0,(UWUCS)Pucs))            //~v6VbR~
#else                                                              //~v6WvI~
		if (rc2=utf4_isSpacingCombiningMark(UTF4ISCMO_WIDTHPARM|width,(UWUCS)Pucs),rc2)//~v6WvI~
#endif                                                             //~v6WvI~
        {                                                          //~v6VbR~
			UTRACEP("%s:SCM ucs=%04x,wcw=%d,Pmkwidth=%d,flag=%x\n",UTT,Pucs,wcw,Pmkwidth,flag);//~v6VbR~
#ifndef XXX                                                        //~v6WvI~
          	if (rc2==2)	//combining2scm                            //~v6WvI~
            {                                                      //~v6WvI~
				flag|=UTFWWF_COMB2SCM;    //assume combining as spacing combining char//~v6WvR~
				flag&=~UTFWWF_COMB;                                //~v6WvI~
            }                                                      //~v6WvI~
#endif                                                             //~v6WvI~
			flag|=UTFWWF_SCM;    //spacing combining char          //~v6VbR~
            width=2;                                               //~v6VbR~
			UTRACEP("%s:SCM set DBCS ucs=%04x,wcw=%d,Pmkwidth=%d,out width=%d,flag=%x\n",UTT,Pucs,wcw,Pmkwidth,width,flag);//~v6VbR~
        }                                                          //~v6VbR~
    }                                                              //~v6VbR~
#ifdef XXE                                                         //~vbz5R~
    width=utfwwapichkCursorXXE(Popt,Pucs,width,&flag);             //~vbz5R~
#endif                                                             //~vbz5R~
	UTRACEP("%s:return ucs=0x%04x,(  %s  ),newwidth=%d,mkwidth=%d,wcwidth()=%d,flag=0x%04x-->0x%04x,%s\n",UTT,Pucs,//~vbz5R~//~v79CI~
			    (u8len=uccvucs2utf((UWUCS)Pucs,utf8),utf8[u8len]=0,utf8),//~vbz5I~//~v79CM~
				width,Pmkwidth,wcw,*Ppflag,flag,(width!=Pmkwidth?"updated":"same"));//~vbz5R~//~v79CI~
    *Ppflag=flag;                                                  //~v640M~
    return width;                                                  //~v640M~
}//utfwwapichk                                                     //~v640M~
#else	//WIN                                                      //~v697I~
//*******************************************************          //~v796I~
#ifndef WXE                                                        //~v796I~
//*******************************************************          //~vbz4R~
//bypass for w32 console                                           //~vbz4R~
//*******************************************************          //~v79mR~
int utfwwapichkCursorW32(int Popt,ULONG Pucs,int Pmkwidth,int *Ppflag)//~v796I~//~v79mR~
{                                                                  //~v796I~//~v79mR~
    int flag,width;                                                //~v79mR~
//  int cursorstep;                                                //~v79mI~
#ifndef NOTRACE                                                    //~v79mI~
	char wku8[12];                                                 //~v79mI~
	int u8len;                                                     //~v79mI~
#endif                                                             //~v79mI~
//*************************                                        //~v796I~//~v79mR~
    flag=*Ppflag;                                                  //~v796I~//~v79mR~
    width=Pmkwidth;                                                //~v796I~//~v79mR~
//    if (flag==UTFWWF_F2C1  //  0x80   //WideSBCS; font width=2,distance to next column=1//~v796R~//~v798R~//~v79mR~
////  ||  width==2 && (flag & UTFWWO_MK_AMBIGUOUS) && !DBCS_REGION(Pucs))  //x2000   //by mk_wcwidth() adjustable by wcwidth() //~v798R~//~v799R~//~v79mR~
//    ||  width==2 && (flag & UTFWWO_MK_AMBIGUOUS))  //x2000   //by mk_wcwidth() adjustable by wcwidth() //~v798I~//~v799R~//~v79mR~
//    {                                                              //~v796I~//~v79mR~
    if (IS_UTF16_HIGH(Pucs)||IS_UTF16_LOW(Pucs))  //UTF16 pair     //~v79mI~
    	return width;                                              //~v79mI~
    UTRACEP("%s:entry ucs=x%04x( %s ),width=%d,flag=0x%04x\n",UTT,Pucs,UTF_GETUTF8STR_TRACE(Pucs,wku8,u8len),width,*Ppflag);//~v798I~//~v79mR~//~v79MR~
    if (width==0 || width==-1)                                     //~v79mI~
        return width;                                              //~v79mI~
	if (width==2                                                   //~v79CI~
	&&  flag==UTFWWO_MK_AMBIGUOUS  //x2000   //ambiguous only(exclude space combining)//~v79CI~
    )                                                              //~v79CI~
    {                                                              //~v79CI~
		if (!UTF_AMBIG2CELLMODE())	//1 cell mode for ambiguous    //~v79CI~
        {                                                          //~v79CI~
            flag &=~UTFWWO_MK_AMBIGUOUS; //x2000                   //~v79CI~
            *Ppflag=flag;                                          //~v79CI~
            return 1;                  //use 1 cell if 2cellmode off//~v79CI~
        }                                                          //~v79CI~
    }                                                              //~v79CI~
//*** flag0080(F2C1) and flag0x2000(Ambiguous) of step=1 have both type of 1/2 cell drawing.//~v79mI~
//*** uvioGetCursorWidth can not determines drawing width          //~v79mI~
//*** It may be cursor step depend to cell attribute of 0x01xx(DBCS1st) 0x02xx(DBCS2nd cell) and not to glyph width.//~v79mI~
//        cursorstep=uvioGetCursorWidth(0,Pucs); //uvio2                    //~v796I~//~v79mR~
//        if (cursorstep>0 && cursorstep!=width)                     //~v796R~//~v79mR~
//        {                                                          //~v796I~//~v79mR~
//            *Ppflag=0;                                             //~v796I~//~v79mR~
//            width=cursorstep;                                      //~v796I~//~v79mR~
//            UTRACEP("%s:updated ucs=x%04x,width=%d->%d,flag=0x%04x->0x%04x\n",UTT,Pucs,Pmkwidth,width,flag,*Ppflag);//~v796R~//~v79mR~
//        }                                                          //~v796I~//~v79mR~
//    UTRACEP("%s:ucs=x%04x ( %s ),width=%d-->%d,old flag=0x%04x,update=%c\n",UTT,Pucs,UTF_GETUTF8STR(Pucs,wku8,u8len),Pmkwidth,width,flag,(width!=Pmkwidth?'Y':'N'));//~v796R~//~v798R~//~v79mI~
//    }                                                              //~v796I~//~v79mR~
    return width;                                                  //~v796I~//~v79mR~
}//utfwwapichkCursorw32                                            //~v796R~//~v79mR~
#else //WXE                                                        //~v79mR~
//*******************************************************          //~v79mR~
int utfwwapichkCursorWXE(int Popt,ULONG Pucs,int Pmkwidth,int *Ppflag)//~vbz4R~
{                                                                  //~vbz4I~
	int flag,width,cursorstep;                                     //~vbz4I~
#ifndef NOTRACE                                                    //~vbz4I~
    UCHAR utf8[12];                                                //~vbz4I~
    int u8len;                                                     //~vbz4I~
#endif                                                             //~vbz4I~
//*************************                                        //~vbz4I~
    	                                                           //~vbz4I~
	flag=*Ppflag;                                                  //~vbz4I~
    width=Pmkwidth;                                                //~vbz4I~
	if (width==2                                                   //~v79CI~
	&&  flag==UTFWWO_MK_AMBIGUOUS  //x2000   //ambiguous only(exclude space combining)//~v79CI~
    )                                                              //~v79CI~
    {                                                              //~v79CI~
		if (UTF_AMBIG2CELLMODE())	//2 cell mode for ambiguous    //~v79CI~
        {                                                          //~v79CI~
            return width;                  //else(1 cellmode) chkcursor//~v79CI~
        }                                                          //~v79CI~
    }                                                              //~v79CI~
    if (!(Gulibutfmode & GULIBUTF_APICHK_CSR)) //0x08000000  //utfwcwidth chr cursor step//~vbz4I~
    	return width;                                              //~vbz4R~
    if (!(Gulibutfmode & GULIBUTF_APICHK_CSR2)) //after HDC        //~vbz4I~
    	return width;                                              //~vbz4R~
    UTRACEP("%s:entry ucs=x%04x ( %s ),width=%d,flag=0x%04x\n",UTT,Pucs,//~vbz4M~
//  		    (u8len=uccvucs2utf((UWUCS)Pucs,utf8),utf8[u8len]=0,utf8),//~vbz4M~//~v79MR~
    		    UTF_GETUTF8STR_TRACE(Pucs,utf8,u8len),             //+v79MR~
				width,*Ppflag);                                    //~vbz4M~
    if ((flag & UTFWWF_F2C1)  //  0x80   //WideSBCS; font width=2,distance to next column=1//~vbz4R~
    ||  width==2 && (flag & UTFWWO_MK_AMBIGUOUS))  //x2000   //by mk_wcwidth() adjustable by wcwidth()//~vbz4I~
    {                                                              //~vbz4I~
    	UTRACEP("%s:callwxe getcursorwidth ucs=x%04x ( %s ),width=%d,flag=0x%04x\n",UTT,Pucs,//~vbz4R~
//  		    (u8len=uccvucs2utf((UWUCS)Pucs,utf8),utf8[u8len]=0,utf8),//~vbz4I~//~v79MR~
    		    UTF_GETUTF8STR_TRACE(Pucs,utf8,u8len),             //~v79MR~
				width,*Ppflag);                                    //~vbz4I~
        cursorstep=wxe_GetCursorWidth(0,Pucs);                     //~vbz4R~
        if (cursorstep>0 && cursorstep!=width)                     //~vbz4R~
        {                                                          //~vbz4R~
            *Ppflag=0;                                             //~vbz4R~
            width=cursorstep;                                      //~vbz4R~
            UTRACEP("%s:updated ucs=0x%04x (%s ),width=%d->%d,flag=0x%04x->0x%04x\n",//~vbz4R~
					UTT,Pucs,                                      //~vbz4I~
    			    UTF_GETUTF8STR_TRACE(Pucs,utf8,u8len),         //~v79MR~
					Pmkwidth,width,flag,*Ppflag);                  //~vbz4I~
        }                                                          //~vbz4R~
    }                                                              //~vbz4I~
    return width;                                                  //~vbz4I~
}//utfwwapichkCursorWXE                                            //~vbz4R~
                                                                   //~vbz4I~
#endif                                                             //~v796I~
//*******************************************************          //~v697I~
//*(WIN)set flag by wcwidth return code                            //~v697I~
//*******************************************************          //~v697I~
int utfwwapichk(int Popt,ULONG Pucs,int Pmkwidth,int *Ppflag,int *Ppwcwidth)//~v697I~
{                                                                  //~v697I~
	int flag,width;                                                //~v697R~
#ifndef XXX                                                        //~v6WvI~
    int rc2;                                                       //~v6WvI~
#endif                                                             //~v6WvI~
//*************************                                        //~v697I~
	flag=*Ppflag;                                                  //~v697I~
    width=Pmkwidth;                                                //~v697I~
    if (UCSIS_NONCHARACTER(Pucs))                                  //~v6C0I~
    	width=-1;                                                  //~v6C0I~
    else                                                           //~v6C0I~
    if (!UDBCSCHK_ISDBCSJ())	//japanese  sjis or jp.utf8        //~v697I~
//  	if (width==1 && !iswprint((WUCS)Pucs)) //reduce mapping tbl by chking sbcs unprintable//~v697I~//~v6BCR~
    	if (width==1 && !ISWPRINT((UWUCS)Pucs)) //reduce mapping tbl by chking sbcs unprintable UCS4 is unprintable//~v6BCR~
        {                                                          //~v697I~
#ifdef HHH                                                         //~v69aR~
        	flag=0;                                                //~v697I~
			width=-1;                                              //~v697I~
#else                                                              //~v69aR~
//  		UTRACEP("WIN apichk ucs=%x,width=-1 unprintable sbcs\n",Pucs);//~v69aR~//~v6C4R~
            ;                                                      //~v69aR~
#endif                                                             //~v69aR~
        }                                                          //~v697I~
//UTRACEP("%s:WIN apichk ucs=%x,width=%d->%d,flag=%x->%x,ISWPRINT=%d\n",UTT,Pucs,Pmkwidth,width,*Ppflag,flag,ISWPRINT((UWUCS)Pucs));//~v6a0R~//~v6C0R~//~v6C4R~
#ifndef XXX                                                        //~v6WvI~
		if (width>=0 && width<=2)                                  //~v6WvR~
        {                                                          //~v6WvI~
			if (rc2=utf4_isSpacingCombiningMark(UTF4ISCMO_WIDTHPARM|width,(UWUCS)Pucs),rc2)//~v6WvI~
        	{                                                      //~v6WvI~
				UTRACEP("%s:SCM ucs=%04x,rc2=%d,Pmkwidth=%d,flag=%x\n",UTT,Pucs,Pmkwidth,flag);//~v6WvR~//~v79mR~
          		if (rc2==2)	//combining2scm                        //~v6WvI~
            	{                                                  //~v6WvI~
					flag|=UTFWWF_COMB2SCM;    //assume combining as spacing combining char//~v6WvI~
					flag&=~UTFWWF_COMB;                            //~v6WvI~
	            }                                                  //~v6WvI~
				flag|=UTFWWF_SCM;    //spacing combining char      //~v6WvI~
            	width=2;                                           //~v6WvI~
            }                                                      //~v6WvI~
        }                                                          //~v6WvI~
#endif                                                             //~v6WvI~
#ifndef WXE                                                   //~v570I~//~v796I~
    width=utfwwapichkCursorW32(Popt,Pucs,width,&flag);             //~vbz4R~
#else                                                              //~vbz4I~
    width=utfwwapichkCursorWXE(Popt,Pucs,width,&flag);             //~vbz4R~
#endif                                                             //~v796I~
    *Ppflag=flag;                                                  //~v697I~
    if (Ppwcwidth)                                                 //~v697I~
        *Ppwcwidth=width;                                          //~v697I~
    return width;                                                  //~v697I~
}//utfwwapichk                                                     //~v697I~
//*******************************************************          //~v6V4I~
//*(WIN) for ucs4                                                  //~v6V4I~
//*******************************************************          //~v6V4I~
int utfwwapichkWucs4(int Popt,ULONG Pucs,int Pmkwidth,int *Ppflag,int *Ppwcwidth)//~v6V4I~
{                                                                  //~v6V4I~
    return Pmkwidth;                                               //~v6V4I~
}//utfwwapichkWucs4                                                //~v6V4I~
#endif	//W32                                                      //~v79mR~
//*******************************************************          //~v640I~
//*get sbcsid from utfwcwidth flag                                 //~v640I~
//*rc1:1:sbcsid was set                                            //~v640I~
//*******************************************************          //~v640I~
int utfddflag2sbcsid(int Popt,int Pflag,int Pwidth,int *Ppsbcsid)  //~v640I~
{                                                                  //~v640I~
	int sbcsid;                                                    //~v640I~
//*************************                                        //~v640I~
	if (Pflag & UTFWWF_F2C1)      //WideSbcs                       //~v640R~
    	sbcsid=UCSDDID_WIDESBCS;      //wcwidth=3                  //~v640R~
    else                                                           //~v640I~
	if (Pflag & UTFWWF_F1C1)      //narrowDBCS                     //~v640R~
        sbcsid=UCSDDID_NARROWDBCS;    //wcwidth=4                  //~v640R~
    else                                                           //~v640I~
//#ifdef UTF8UCS4                                                    //~v65cI~//~v6uBR~
#ifdef UTF8UCS416                                                  //~v6uBI~
	if (Pflag & UTFWWF_SBCSOVF)   //ucs4                           //~v65cI~
        sbcsid=UCSDDID_OVERFLOW;                                   //~v65cI~
    else                                                           //~v65cI~
#endif                                                             //~v65cI~
        return 0;               //nothing to do                    //~v640I~
//UTRACEP("%s:flag=%x,width=%d,sbcsid=%d\n",UTT,Pflag,Pwidth,sbcsid);//~v640I~//~v740R~
    *Ppsbcsid=sbcsid;                                              //~v640I~
    return 1;                                                      //~v640I~
}//utfddflag2sbcsid                                                //~v640I~
//*******************************************************          //~v640I~
//*set flag from sbcsid                                            //~v640I~
//* called from utfwcwidth after mapinit                           //~v65cI~
//*******************************************************          //~v640I~
int utfddgetlenflag(int Popt,ULONG Pucs,int *Pplen,int *Ppflag)    //~v640I~
{                                                                  //~v640I~
	int len,flag,sbcsid;                                           //~v640I~
#ifndef XXX                                                        //~v6WvI~
    int rc2;                                                       //~v6WvI~
#endif                                                             //~v6WvI~
//*************************                                        //~v640I~
	flag=0;                                                        //~v640I~
    sbcsid=0;   //for compiler warning                             //~v6VbI~
  if (Pucs<0x80)                                                   //~v650I~
    len=1;                                                         //~v650I~
//#ifdef UTF8UCS4                                                    //~v65cI~//~v6uBR~
#ifdef UTF8UCS416                                                  //~v6uBI~
  else                                                             //~v65cI~
  if (Pucs>=UCS2DDMAP_ENTNO)	//no ucs->sbcsid mapping entry     //~v65cI~
  {                                                                //~v65cI~
#ifdef UTF8UTF16     //W32                                         //~v6uBI~
//  len=2;    //set UTFWWF_SBCSOVF                                 //~v6uBI~//~v6V4R~
	len=utfwcwidthNoMap(Popt,Pucs,&flag);                          //~v6V4I~
  	if (len==1)	//not width0/dbcs by utfwcwidthNoMap               //~v6V4I~
  	{                                                              //~v6V4I~
		flag|=UTFWWF_SBCSOVF;	//use 2 column                     //~v6V4I~
    	len=2;                                                     //~v6V4I~
  	}                                                              //~v6V4I~
#else                                                              //~v6uBI~
	len=utfwcwidthNoMap(Popt,Pucs,&flag);                          //~v6V4R~
  if (len==1)	//not width0/dbcs by utfwcwidthNoMap               //~v6V4I~
  {                                                                //~v6V4I~
    if (Popt & UTFWWO_APICHK4)                                     //~v65cI~
//		len=wcwidth(Pucs);	//try each time	                       //~v65cR~//~v6B4R~
  		len=wcwidth((wchar_t)Pucs);	//try each time                //~v6B4I~
    else                                                           //~v65cI~
//category:"Cf"(Format) len=1 will be changed to 2(to use 2 cell) for ucs4>ENTNO//~v6WmI~
    	len=2;                                                     //~v65cI~
  }                                                                //~v6V4I~
#endif                                                             //~v6uBI~
    if (len==0)                                                    //~v6V4I~
    	flag|=UTFWWF_WIDTH0|UTFWWF_SBCSOVF;	//use 2 column         //~v6V4I~
    else                                                           //~v6V4I~
    if (len==2)                                                    //~v6V4I~
    	;                                                          //~v6V4I~
    else                                                           //~v6V4I~
    if (len<=0)        //unprintable,also for width=0	           //~v65cR~
        len=-1;                                                    //~v65cI~
    else                                                           //~v65cI~
    {                                                              //~v65cI~
		flag|=UTFWWF_SBCSOVF;	//use 2 column                     //~v65cI~
        len=2;	//for also sbcs                                    //~v65cR~
    }                                                              //~v65cI~
  }                                                                //~v65cI~
#endif                                                             //~v65cI~
  else                                                             //~v650I~
  {                                                                //~v650I~
	sbcsid=Gucs2ddmap[(int)Pucs].UCS2DDsbcsid;                     //~v640I~
//  UTRACEP("%s: from map ucs=%04x,sbcsid=%x\n",UTT,Pucs,sbcsid);                 //~v640I~//~v740R~
    switch(sbcsid)                                                 //~v640I~
    {                                                              //~v640I~
    case UCSDDID_UNP:                                              //~v640I~
        len=-1;                                                    //~v640I~
        break;                                                     //~v640I~
//  case UCSDDID_NONSPACE:                                         //~v640I~//~v650R~
//      len=0;                                                     //~v640I~//~v650R~
//      break;                                                     //~v640I~//~v650R~
    case UCSDDID_DBCS:                                             //~v640I~
    case UCSDDID_OVERFLOW:                                         //~v640I~
    case UCSDDID_OVERFLOWW0: //width 0 tbl overflow                //~v67ZI~
        len=2;                                                     //~v640I~
        break;                                                     //~v640I~
    case UCSDDID_WIDESBCS:         //wcwidth=1,wide SBCS           //~v640R~
		flag|=UTFWWF_F2C1;      //wide font SBCS                   //~v640R~
//      UTRACEP("%s:@@@@F2C1 ucs=0x%04x\n",UTT,Pucs);              //~vbz5R~
        len=2;                                                     //~v640I~
        break;                                                     //~v640I~
    case UCSDDID_NARROWDBCS:         //wcwidth=2,narrow dbcs       //~v640R~
		flag|=UTFWWF_F1C1;      //narrow dbcs                      //~v640R~
        len=2;                                                     //~v640I~
        break;                                                     //~v640I~
    default:                                                       //~v640I~
#ifdef WWW    	                                                   //~v6BYI~
        if (sbcsid>=UCSDDID_STARTWIDTH0)                           //~v650R~
#else                                                              //~v6BYI~
        if (sbcsid>=Gudbcschk_width0top)                           //~v6BYI~
#endif                                                             //~v6BYI~
		{                                                          //~v6VmI~
        	flag|=UTFWWF_WIDTH0;                                   //~v650I~
            len=0;                                                 //~v6VmI~
        }                                                          //~v6VmI~
        else                                                       //~v6VmI~
        len=1;                                                     //~v640I~
    }                                                              //~v640I~
//#ifdef UTF8UCS4                                                    //~v65cI~//~v6uBR~
#ifdef UTF8UCS416                                                  //~v6uBI~
//  if (Pucs>=UCS4_START	//ucs4; treate as dbcs except ucs sbcsid was set//~v65cI~//~v6VyR~
    if (Pucs>=UCS2DDMAP_ENTNO	//no ucs->sbcsid mapping entry     //~v6VyI~
    ||  sbcsid==UCSDDID_OVERFLOWW0                                 //~v67ZI~
    ||  sbcsid==UCSDDID_OVERFLOW)                                  //~v65cI~
    {                                                              //~v65cI~
#ifdef UTF8UTF16                                                   //~v6uBI~
    	if (!(sbcsid==UCSDDID_UNP))	//requested return unprintable //~v6uBI~
#else                                                              //~v6uBI~
    	if (!(Popt & UTFWWO_APICHK4 && sbcsid==UCSDDID_UNP))	//requested return unprintable//~v65cI~
#endif                                                             //~v6uBI~
            if (len!=1) //not sbcs      //no representative bit remains for ucs4//~v65cR~
            {                                                      //~v65cR~
                flag=UTFWWF_SBCSOVF;    //use 2 column             //~v65cR~
                len=2;  //for also sbcs                            //~v65cR~
            }                                                      //~v65cR~
    }                                                              //~v65cI~
#endif                                                             //~v65cI~
  }                                                                //~v650I~
#ifdef XXX                                                         //~v6WvI~
    if (sbcsid==UCSDDID_DBCS)                                      //~v6VbI~
#else                                                              //~v6WvI~
    if (len>=0 && len<=2)                                          //~v6WvR~
#endif                                                             //~v6WvI~
    {                                                              //~v6VbI~
#ifdef XXX                                                         //~v6WvI~
		if (utf4_isSpacingCombiningMark(0,(UWUCS)Pucs))            //~v6VbI~
#else                                                              //~v6WvI~
        if (rc2=utf4_isSpacingCombiningMark(UTF4ISCMO_WIDTHPARM|len,(UWUCS)Pucs),rc2)//~v6WvI~
#endif                                                             //~v6WvI~
        {                                                          //~v6VbI~
#ifndef XXX                                                        //~v6WvI~
            if (rc2==2) //combining2scm                            //~v6WvI~
            {                                                      //~v6WvI~
                flag|=UTFWWF_COMB2SCM;    //assume combining as spacing combining char//~v6WvR~
				flag&=~UTFWWF_COMB;                                //~v6WvI~
            }                                                      //~v6WvI~
#endif                                                             //~v6WvI~
			flag|=UTFWWF_SCM;    //spacing combining char          //~v6VbI~
			UTRACEP("%s:SCM set SCM flag ucs=%04x,flag=%x,sbcsid=%x\n",UTT,Pucs,flag,sbcsid);//~v6VbI~
        }                                                          //~v6VbI~
    }                                                              //~v6VbI~
    if (Ppflag)                                                    //~v640I~
	    *Ppflag=flag;                                              //~v640I~
    *Pplen=len;                                                    //~v640I~
    UTRACEP("utfddgetlenflag ucs=0x%04x,flag=0x%04x,len=%d\n",Pucs,flag,len);          //~v740R~//~vbz5R~
    return 0;                                                      //~v640I~
}//utfddgetlenflag                                                 //~v640I~
#ifdef WWW                                                         //~v6BYI~
#else                                                              //~v6BYI~
//*******************************************************          //~v6BZI~
//*SBCS mapping tabl init width0 ucs                               //~v6BZI~
//*******************************************************          //~v6BZI~
int utf22_mapwidth0_rounddown(int Popt,int *Ppovfucs,int *Ppovfucslast,int *Ppovfctr)//~v6BZI~
{                                                                  //~v6BZI~
	int seqnow0;                                                   //~v6BZI~
    WUCS ucs2sbcs;                                               //~v6BZI~
//********************                                             //~v6BZI~
//round down sbcsid to xx00                                        //~v6BZI~
    for (seqnow0=Gudbcschk_width0top;seqnow0>=UCSDDID_STARTUCS;)   //~v6BZI~
    {                                                              //~v6BZI~
        UTRACEP("%s:seqnow0=%04x\n",UTT,seqnow0);                  //~v6BZI~
        if ((seqnow0 & 0xff)==UDBCSCHK_SBCSIDWRAP) // <=0x21       //~v6BZI~
        	break;                                                 //~v6BZI~
  		seqnow0--;                                                 //~v6BZI~
    	ucs2sbcs=Gucs2ddmap_i2u[seqnow0];                          //~v6BZI~
        UTRACEP("%s:seqnow0-1=%04x,olducs=%04x\n",UTT,seqnow0,ucs2sbcs);//~v6BZI~
        if (ucs2sbcs>=UCSDDID_STARTUCS)  //sbcsid is already assigned//~v6BZI~
        {                                                          //~v6BZI~
            Gucs2ddmap[ucs2sbcs].UCS2DDsbcsid=UCSDDID_OVERFLOW;   //change to SBCS overflow//~v6BZI~
            if (!*Ppovfucs || *Ppovfucs>ucs2sbcs)                  //~v6BZI~
            	*Ppovfucs=ucs2sbcs;                                //~v6BZI~
            if (!*Ppovfucs || *Ppovfucslast<ucs2sbcs)              //~v6BZI~
            	*Ppovfucslast=ucs2sbcs;                            //~v6BZI~
            *Ppovfctr=*Ppovfctr+1;                                 //~v6BZI~
	    	Gucs2ddmap_i2u[seqnow0]=0; //free entry                //~v6BZI~
            UTRACEP("%s:round down replace sbcsid to free olducs=%04x,sbcsid=%04x,ovfctr=%d,ovfucs=%04x,ovfucslast=%04x\n",UTT,ucs2sbcs,seqnow0,*Ppovfctr,*Ppovfucs,*Ppovfucslast);//~v6BZI~
        }                                                          //~v6BZI~
    }                                                              //~v6BZI~
    UTRACEP("%s:round down rc=%04x\n",UTT,seqnow0);                //~v6BZI~
    return seqnow0;                                                //~v6BZI~
}//utf22_mapwidth0_rounddown                                       //~v6BZI~
//*******************************************************          //~v6BYI~
//*SBCS mapping tabl init width0 ucs                               //~v6BYR~
//*******************************************************          //~v6BYI~
int utf22_mapwidth0(WUCS *Plist_width0,int Psbcsw0ctr,int *Ppovfucs,int *Ppovfucslast,int *Ppovfctr)//~v6BYR~
{                                                                  //~v6BYI~
	int sbcsw0ctr,seqnow0,ii;                                      //~v6BYR~
    WUCS *plist_width0;                                          //~v6BYI~
    WUCS ucs2sbcs,ucs2w0;                                        //~v6BYI~
//********************                                             //~v6BYI~
    UTRACEP("%s:before apply width0,width0ctr=0x%x,ovfctr=0x%x,ovfucs=%04x,ovflast=%04x\n",UTT,Psbcsw0ctr,*Ppovfctr,*Ppovfucs,*Ppovfucslast);//~v6BYR~//~v@@@R~
    UTRACED("before width0 u2i",Gucs2ddmap,sizeof(Gucs2ddmap));    //~v6BYM~
    UTRACED("before width0 i2u",Gucs2ddmap_i2u,sizeof(Gucs2ddmap_i2u));//~v6BYM~
    UTRACED("before width0 LIST",Plist_width0,(int)sizeof(Plist_width0[0])*Psbcsw0ctr);//~v6BYR~
	sbcsw0ctr=Psbcsw0ctr;                                          //~v6BYM~
//search start point of width0                                     //~v6BYM~
    for (seqnow0=UCS2DDMAXSBCSID+1/*6fff+1*/,ii=0;seqnow0>=UCSDDID_STARTUCS && ii<sbcsw0ctr/*+UCSDD_MAX_WIDTH0_MODIFY*/;ii++)//~v6BYR~
    {                                                              //~v6BYM~
        if ((seqnow0 & 0xff)==UDBCSCHK_SBCSIDWRAP) // <=0x21       //~v6BYR~
        	seqnow0=(seqnow0 & 0xff00)-1;	               //keep 0x00--<0x20 as free//~v6BYR~
        else                                                       //~v6BYM~
  		  	seqnow0--;                                             //~v6BYM~
        UTRACEP("%s:ii=%d,seqnow0=%04x\n",UTT,ii,seqnow0);         //~v6BYR~//~vbz4R~
    }                                                              //~v6BYM~
  if (!seqnow0)                                                    //~v70hR~
    Gudbcschk_width0top=UCS4_MAX;	//width0 start sbcsid          //~v70hI~
  else                                                             //~v70hI~
    Gudbcschk_width0top=seqnow0;	//width0 start sbcsid          //~v6BYM~
    UTRACEP("%s:width0Top sbcsid=0x%04x,sbcs0ctr=0x%04x\n",UTT,Gudbcschk_width0top,sbcsw0ctr);//~vbz4R~
//update sbcsid for width0                                         //~v6BYM~
    for (ii=0,plist_width0=Plist_width0;ii<sbcsw0ctr;ii++)         //~v6BYR~
    {                                                              //~v6BYM~
    	ucs2w0=*plist_width0++;                                    //~v6BYM~
    	ucs2sbcs=Gucs2ddmap_i2u[seqnow0];                          //~v6BYM~
      if (ucs2sbcs>=UCSDDID_STARTUCS)  //sbcsid is already assigned for Not width0//~v79aI~
        if (ucs2sbcs>=UCSDDID_STARTUCS)  //sbcsid is already assigned//~v6BYR~
        {                                                          //~v6BYM~
            Gucs2ddmap[ucs2sbcs].UCS2DDsbcsid=UCSDDID_OVERFLOW;   //change to SBCS overflow//~v6BYM~
            if (!*Ppovfucs || *Ppovfucs>ucs2sbcs)                  //~v6BYR~
            	*Ppovfucs=ucs2sbcs;                                //~v6BYR~
            if (!*Ppovfucs || *Ppovfucslast<ucs2sbcs)              //~v6BYR~
            	*Ppovfucslast=ucs2sbcs;                            //~v6BYR~
            *Ppovfctr=*Ppovfctr+1;                                 //~v6BYR~
            UTRACEP("%s:replace sbcsid to width0 olducs=%04x,newucs=%04x,sbcsid=%04x,ovfctr=%d,ovfucs=%04x,ovfucslast=%04x\n",UTT,ucs2sbcs,ucs2w0,seqnow0,*Ppovfctr,*Ppovfucs,*Ppovfucslast);//~v6BYI~
        }                                                          //~v6BYM~
        Gucs2ddmap_i2u[seqnow0]=ucs2w0;                            //~v6BYM~
        Gucs2ddmap[ucs2w0].UCS2DDsbcsid=(USHORT)seqnow0;           //~v6BYM~
        UTRACEP("%s:set sbcsid width0 olducs=%04x,newucs=%04x,sbcsid=%04x\n",UTT,ucs2sbcs,ucs2w0,seqnow0);//~v6BYR~
        seqnow0++;                                                 //~v6BYI~
    	if (!(seqnow0 & 0xff)) //low byte<0x30                     //~v6BYM~
        	seqnow0+=UDBCSCHK_SBCSIDWRAP;  //leave "<=0x20" unused for sbcsid for data scan//~v6BYM~
    }                                                              //~v6BYM~
	seqnow0=utf22_mapwidth0_rounddown(0,Ppovfucs,Ppovfucslast,Ppovfctr);//~v6BZI~
    UTRACEP("%s:width0top=%04x,ovfctr=%d,ovfucs=%04x,ovflast=%04x,top width0=%04x:%04x\n",UTT,Gudbcschk_width0top,*Ppovfctr,*Ppovfucs,*Ppovfucslast,seqnow0,Gudbcschk_width0top);//~v6BYR~//~v6BZR~
    UTRACED("after  width0 u2i",Gucs2ddmap,sizeof(Gucs2ddmap));    //~v6BYI~
    UTRACED("after  width0 i2u",Gucs2ddmap_i2u,sizeof(Gucs2ddmap_i2u));//~v6BYM~
    return seqnow0;                                                //~v6BYI~
}//utf22_mapwidth0                                                 //~v6BYI~
////********************************************************************************//~v6BYI~//~v6BZR~
////*SBCS mapping tabl width0 modification by inifile "UnicodeTbl" parm//~v6BYI~//~v6BZR~
////********************************************************************************//~v6BYI~//~v6BZR~
//int utf22_mapwidth0_modify(int Pucs)                               //~v6BYR~//~v6BZR~
//{                                                                  //~v6BYI~//~v6BZR~
//    int seqnow0,oldsbcsid;                                         //~v6BYR~//~v6BZR~
//    PUCS2DDMAP pud;                                                //~v6BYI~//~v6BZR~
//    static int Smodw0ctr=0;                                        //~v6BYI~//~v6BZR~
////********************                                             //~v6BYI~//~v6BZR~
//    Smodw0ctr++;                                                   //~v6BYI~//~v6BZR~
//    pud=Gucs2ddmap+Pucs;                                           //~v6BYR~//~v6BZR~
//    oldsbcsid=pud->UCS2DDsbcsid;  //old sbcsid                     //~v6BYR~//~v6BZR~
//    seqnow0=Gudbcschk_width0top;                                   //~v6BYI~//~v6BZR~
//    UTRACEP("%s:modctr=%d,ucs=%04x,oldsbcsid=%04x,w0top=%04x\n",UTT,Smodw0ctr,Pucs,oldsbcsid,seqnow0);//~v6BYR~//~v6BZR~
//    if ((seqnow0 & 0xff)==UDBCSCHK_SBCSIDWRAP) // <=0x21           //~v6BYI~//~v6BZR~
//        seqnow0=(seqnow0 & 0xff00)-1;                  //keep 0x00--<0x20 as free//~v6BYI~//~v6BZR~
//    else                                                           //~v6BYI~//~v6BZR~
//        seqnow0--;                                                 //~v6BYI~//~v6BZR~
//    if (seqnow0<UCSDDID_STARTUCS)                                  //~v6BYI~//~v6BZR~
//    {                                                              //~v6BYI~//~v6BZR~
//        uerrexit("Too many width0 specification, overflow at ucs=%04x ctr=%d(0x%04x)",0,Pucs,Smodw0ctr,Smodw0ctr);//~v6BYR~//~v6BZR~
//    }                                                              //~v6BYI~//~v6BZR~
//    if (oldsbcsid>=UCSDDID_STARTUCS)  //sbcsid is already assigned //~v6BYR~//~v6BZR~
//    {                                                              //~v6BYI~//~v6BZR~
//        Gucs2ddmap_i2u[oldsbcsid]=0;   //unused sbcsid             //~v6BYR~//~v6BZR~
//    }                                                              //~v6BYM~//~v6BZR~
//    Gudbcschk_width0top=seqnow0;    //width0 start sbcsid          //~v6BYR~//~v6BZR~
//    pud->UCS2DDsbcsid=(USHORT)seqnow0;                             //~v6BYR~//~v6BZR~
//    Gucs2ddmap_i2u[seqnow0]=(WUCS)Pucs;                            //~v6BYR~//~v6BZR~
//    UTRACEP("%s:ucs=%04x,newsbcsid=%04x\n",UTT,Pucs,seqnow0);      //~v6BYR~//~v6BZR~
//    return seqnow0;                                                //~v6BYI~//~v6BZR~
//}//utf22_mapwidth0_modify                                          //~v6BYI~//~v6BZR~
#endif //!WWW                                                      //~v6BYI~
#ifdef W32                                                         //~vbz4I~
	#ifdef WXE                                                     //~vbz4I~
//*******************************************************          //~vbz4I~
//*SBCS mapping tabl init for u0000-uffff                          //~vbz4I~
//aftr HDC created to adjust by textextent                         //~vbz4I~
//*******************************************************          //~vbz4I~
void utfucsmapinitWXE()                                            //~vbz4I~
{                                                                  //~vbz4I~
	UTRACEP("%s Gulibutfmode APICHK_CSR=%s\n",UTT,((Gulibutfmode & GULIBUTF_APICHK_CSR)?"ON":"OFF"));//~vbz4I~
	if (!(Gulibutfmode & GULIBUTF_APICHK_CSR))                     //~vbz4I~
    	return;                                                    //~vbz4I~
	if ((Gulibutfmode & GULIBUTF_APICHK_CSR2))                     //~vbz4I~
    	return;	//dup scrinit                                      //~vbz4I~
	Gulibutfmode |= GULIBUTF_APICHK_CSR2;	//after HDC init       //~vbz4I~
	Gulibutfmode&=~GULIBSETUCS2MAP;	//redo mapinit                 //~vbz4I~
    memset(Gucs2ddmap,0,sizeof(Gucs2ddmap));                       //~v79aI~
    memset(Gucs2ddmap_i2u,0,sizeof(Gucs2ddmap_i2u));               //~v79aI~
	utfucsmapinit(0);                                              //~vbz4R~
}//utfucsmapinitWXE()                                              //~vbz4I~
    #endif                                                         //~vbz4I~
#else                                                              //~vbz5I~
	#ifdef XXE                                                     //~vbz5I~
//*******************************************************          //~vbz5I~
//*SBCS mapping tabl init for u0000-uffff                          //~vbz5I~
//aftr HDC created to adjust by textextent                         //~vbz5I~
//*******************************************************          //~vbz5I~
void utfucsmapinitXXE()                                            //~vbz5I~
{                                                                  //~vbz5I~
	UTRACEP("%s Gulibutfmode APICHK_CSR=%s\n",UTT,((Gulibutfmode & GULIBUTF_APICHK_CSR)?"ON":"OFF"));//~vbz5I~
	if (!(Gulibutfmode & GULIBUTF_APICHK_CSR))                     //~vbz5I~
    	return;                                                    //~vbz5I~
	if ((Gulibutfmode & GULIBUTF_APICHK_CSR2))                     //~vbz5I~
    	return;	//dup scrinit                                      //~vbz5I~
	Gulibutfmode |= GULIBUTF_APICHK_CSR2;	//after HDC init       //~vbz5I~
	Gulibutfmode&=~GULIBSETUCS2MAP;	//redo mapinit                 //~vbz5I~
    memset(Gucs2ddmap,0,sizeof(Gucs2ddmap));                       //~vbz5I~
    memset(Gucs2ddmap_i2u,0,sizeof(Gucs2ddmap_i2u));               //~vbz5I~
	utfucsmapinit(0);                                              //~vbz5I~
}//utfucsmapinitWXE()                                              //~vbz5I~
    #endif  //XXE                                                  //~vbz5I~
#endif                                                             //~vbz4I~
//*******************************************************          //~v640I~
//*SBCS mapping tabl init for u0000-uffff                          //~v640I~
//unicode map to ddfmt unicodeid                                   //~v640I~
//*******************************************************          //~v640I~
int utfucsmapinit(int Popt)                                        //~v640I~
{                                                                  //~v640I~
	int ii,width,opt,sbcsid,seqno=UCSDDID_STARTSBCSID,flag;        //~v640R~
#ifdef WWW                                                         //~v6BYI~
    int seqnow0=UCSDDID_STARTWIDTH0,ovfctr=0,ovfctrw0=0;           //~v650R~
#else                                                              //~v6BYI~
    int /*seqnow0=0,*/ovfctr=0,ovfctrw0=0;                             //~v6BYR~//~v6DhR~
#endif                                                             //~v6BYI~
    PUCS2DDMAP pud;                                                //~v640R~
    int ovfucs=0,ovfucsw0=0,ovfucslast=0,ovfucsw0last=0;           //~v6h4R~
    int sbcsctr=0;                                                 //~v67ZI~
    int sbcsw0ctr=0;                                               //~v69bI~
    SAVESBCSTB savehdr;                                            //~v6c7I~
    int loaded=0;                                                  //~v6c7I~
#ifdef WWW                                                         //~v6BYI~
#else                                                              //~v6BYI~
    WUCS *plist_width0,*plist_width00;                             //~v6BYR~
    int plist_width0_size;                                         //~v6BYR~
#endif                                                             //~v6BYI~
	int unpctr=0,dbcsctr=0,sbcsidctr=0;                            //~v@@@R~
//*********************                                            //~v640I~
#ifdef WXEXXE                                                      //~v79rR~
    if (Gulibutfmode & GULIBUTF_APICHK_CSR) //csr chk option by xe.c//~v79rI~
    {                                                              //~v79rI~
        if (!(Gulibutfmode & GULIBUTF_APICHK_CSR2)) //before HDC init//~v79rI~
        {                                                          //~v79rI~
            UTRACEP("%s:NOP before mapinit with /Yv option\n",UTT);//~v79rR~
            return 0;   //for errmsg, maybe no dbcd chk required   //~v79rI~
        }                                                          //~v79rI~
    }                                                              //~v79rI~
#endif                                                             //~v79rI~
	if (Gulibutfmode & GULIBSETUCS2MAP)  //dup call                //~v640I~
    	return 4;                                                  //~v640I~
#ifdef UB1710	//test under ub17.10(kernel4.13.0)                 //~v6V1R~
	Gulibutfmode|=GULIBUTFAPIWIDTH0; //0x02000000  //accept wcwidth()=0 for not on utf4:combine tbl//~v6V1R~
#endif                                                             //~v6V1R~
    opt=0;                                                         //~v6c7I~
  if (!utfucsloadmap(opt,&savehdr))                                //~v6c7I~
  {                                                                //~v6c7I~
  	seqno=savehdr.SSTseqno;                                        //~v6c7I~
    ovfctr=savehdr.SSTovfctr;                                      //~v6c7I~
    ovfctrw0=savehdr.SSTovfctrw0;                                  //~v6c7I~
    ovfucs=savehdr.SSTovfucs;                                      //~v6c7I~
    ovfucslast=savehdr.SSTovfucslast;                              //~v6c7I~
    sbcsctr=savehdr.SSTsbcsctr;                                    //~v6c7I~
    ovfucsw0=savehdr.SSTovfucsw0;                                  //~v6c7I~
    ovfucsw0last=savehdr.SSTovfucsw0last;                          //~v6c7R~
	Gulibutfmode|=(savehdr.SSTflag & GULIBUTFSBCSIDOVF); //mapinit SBCSid overflow//~v6c7I~
    Gudbcschk_width0top=savehdr.SSTwidth0top;                      //~v70mR~
    loaded=1;                                                      //~v6c7I~
  }                                                                //~v6c7I~
  else                                                             //~v6c7I~
  {                                                                //~v6c7I~
#ifdef WWW                                                         //~v6BYI~
#else                                                              //~v6BYI~
    plist_width0_size=UCS2DDMAP_ENTNO*(int)sizeof(plist_width0[0]);         //~v6BYR~
    plist_width00=plist_width0=umalloc((UINT)plist_width0_size);   //~v6BYR~
#endif                                                             //~v6BYI~
    UTRACEP("%s:start\n",UTT);                                   //~v6a0R~//~v6b9R~//~vbz4R~
#ifdef W32	                                                       //~v796I~
	#ifndef WXE                                                    //~v796I~
//    	Gulibutfmode|=GULIBUTF_APICHK_CSR; //0x08000000  //utfwcwidth chr cursor step;xe.c set this optionally //~v796I~//~vbz3R~
        UTRACEP("%s:Gulibutfmode:APICHK_CSR=0x%08x\n",UTT,Gulibutfmode & GULIBUTF_APICHK_CSR);//~vbz3I~
  		uvioGetCursorWidth(UVGCWO_OPEN,0);                         //~v796I~//~v798R~
    #endif                                                         //~v796I~
#endif                                                             //~v796I~
    opt=UTFWWO_UTF8UCS2;                                           //~v640R~
//#ifdef LNX                                                       //~v640R~
//    opt|=UTFWWO_APIONLY;    //anyway                             //~v640R~
//#endif                                                           //~v640R~
	for (ii=UCSDDID_STARTUCS,pud=Gucs2ddmap+ii;ii<UCS2DDMAP_ENTNO;ii++,pud++)//~v640R~
    {                                                              //~v640I~
//#ifdef TEST                                                      //~v@@@R~
        if (ii==0xa7||ii==0xad||ii==0xb1||ii==0x01c4||ii==0x0300||ii==0x0389||ii==0x0391||ii==0x0488||ii==0x0816||ii==0x093b||ii==0x1160||ii==0x2020||ii==0x2025||ii==0x2191||ii==0x223c||ii==0x231a||ii==0x25fd||ii==0x25fe||ii==0x2614||ii==0x2642||ii==0x2661||ii==0x2705||ii==0x2b55||ii==0x303f||ii==0x309a||ii==0xa960||ii==0xd7b0||ii==0xfffc||ii==0xfffd||ii==0x100e0||ii==0x10190||ii==0x10a01||ii==0x01d16d)////~v6V1R~//~v6V5R~//~v6V7R~//~v6VaR~//~v6VmR~//~v6VsR~//~v6W9R~//~v6WiR~//~v740R~
        {                                                          //~v@@@I~
        	UTRACEP("%s:trap\n",UTT);	//@@@@test                 //~v@@@I~
        }                                                          //~v@@@I~
        if (ii==0x0313||ii==0x2033||ii==0x2032||ii==0x10330)                              //~v6WiI~//~v6WmR~//~v740R~
        {                                                          //~v6WiI~
        	UTRACEP("%s:trap\n",UTT);	//@@@@test                 //~v6WiI~
        }                                                          //~v6WiI~
        if (ii>=0x0300 && ii<=0x030f)     //width0                 //~v70hR~
        {                                                          //~v70hI~
        	UTRACEP("%s:trap ucs=x%x\n",UTT,ii);	//TODO test    //~v70hI~
        }                                                          //~v70hI~
//#endif                                                           //~v@@@R~
//  	width=utfwcwidth(opt,ii,&flag);                            //~v640R~//~v6B4R~
    	width=utfwcwidth(opt,(ULONG)ii,&flag);                     //~v6B4I~
//      UTRACEP("%s:ucs=%04x=width=%2d\n",UTT,ii,width);           //~v6BYR~//~v@@@R~//~v6Y0R~//~vc1cR~
        if (width<0)                                               //~v640I~
        {                                                          //~v640I~
	        sbcsid=UCSDDID_UNP;                                    //~v640R~
            unpctr++;                                              //~v@@@I~
        }                                                          //~v640I~
        else                                                       //~v640I~
        if (!width)                                                //~v640I~
        {                                                          //~v650I~
#ifdef WWW                                                         //~v6BYI~
//      	sbcsid=UCSDDID_NONSPACE;                               //~v640R~//~v650R~
        	if (seqnow0>=UCSDDID_ENDWIDTH0)	//reached to width=1 sbcsid//~v650R~
            {                                                      //~v650I~
                if (!ovfctrw0)                                     //~v67ZI~
                	ovfucsw0=ii;                                   //~v67ZI~
                ovfucsw0last=ii;                                   //~v67ZI~
//          	sbcsid=UCSDDID_OVERFLOW;                           //~v67ZR~
            	sbcsid=UCSDDID_OVERFLOWW0; //used at remap         //~v67ZI~
                ovfctrw0++;                                        //~v650I~
            }                                                      //~v650I~
            else                                                   //~v650I~
            {                                                      //~v650I~
//  			if ((seqnow0 & 0xff)<0x30) //low byte<0x30         //~v650I~//~v69bR~
//              	seqnow0+=0x30;                                 //~v650I~//~v69bR~
    			if (!(seqnow0 & 0xff)) //leave "<=0x20" unused for sbcsid for data scan//~v69bR~
                	seqnow0+=UDBCSCHK_SBCSIDWRAP;  //leave "<=0x20" unused for sbcsid for data scan//~v69bI~
        		sbcsid=seqnow0++;                                  //~v650I~
//#ifdef UTF8UCS4                                                    //~v65cI~//~v67ZR~
            	Gucs2ddmap_i2u[sbcsid]=(WUCS)ii;	//reverse map  //~v65cI~
//#else                                                              //~v65cI~//~v67ZR~
//                Gucs2ddmap[sbcsid].UCS2DDucs=(WUCS)ii;  //reverse map//~v650I~//~v67ZR~
//#endif                                                             //~v65cI~//~v67ZR~
//UTRACEP("mapinit width=0:sbcsid ucs=%04x,sbcsid=%04x\n",ii,sbcsid);//~v6a0R~
            }                                                      //~v650I~
            sbcsw0ctr++;                                             //~v67ZI~//~v69bR~
#else   //!WWW not fixed width0 boundary                           //~v6BYI~
            *plist_width0++=(WUCS)ii;	                           //~v6BYR~
            sbcsw0ctr++;                                           //~v6BYI~
            sbcsid=0;                                              //~v6BYI~
    		UTRACEP("%s:width0ctr=%04d=%04x\n",UTT,sbcsw0ctr,ii);  //~v6BYR~//~v70hR~//~v70iR~
#endif //!WWW not fixed width0 boundary                            //~v6BYI~
        }                                                          //~v650I~
        else                                                       //~v640I~
    	if (utfddflag2sbcsid(0,flag,width,&sbcsid))                //~v640I~
        {                                                          //~v@@@I~
        	sbcsidctr++                                            //~v@@@I~
        	;                                                      //~v640M~
        }                                                          //~v@@@I~
        else                                                       //~v640M~
        if (width==1)                                              //~v640I~
        {                                                          //~v640I~
        	if (seqno==UCS2DDMAXSBCSID)	//sbcs count reached mas   //~v640I~//~v650R~
            {                                                      //~v650I~
            	sbcsid=UCSDDID_OVERFLOW;                           //~v640I~
                if (!ovfctr)                                       //~v67ZI~
                	ovfucs=ii;                                     //~v67ZI~
                ovfucslast=ii;                                     //~v67ZI~
                ovfctr++;                                          //~v650I~
            }                                                      //~v650I~
            else                                                   //~v640I~
            {                                                      //~v640I~
            	if (ii<UCSDDID_STARTSBCSID)	//range avoid mapping  //~v640R~
                {                                                  //~v650I~
                	sbcsid=ii;                                     //~v640I~
            	}                                                  //~v650I~
                else                                               //~v640I~
                {                                                  //~v640I~
//  			 	if ((seqno & 0xff)<0x30) //low byte<0x30       //~v640R~//~v69bR~
//                		seqno+=0x30;                               //~v640R~//~v69bR~
    			 	if (!(seqno & 0xff)) //low byte<0x30           //~v69bI~
                  		seqno+=UDBCSCHK_SBCSIDWRAP;  //leave "<=0x20" unused for sbcsid for data scan//~v69bI~
        			sbcsid=seqno++;                                //~v640R~
                }                                                  //~v640I~
//#ifdef UTF8UCS4                                                    //~v65cI~//~v67ZR~
            	Gucs2ddmap_i2u[sbcsid]=(WUCS)ii;	//reverse map  //~v65cI~
//#else                                                              //~v65cI~//~v67ZR~
//                Gucs2ddmap[sbcsid].UCS2DDucs=(WUCS)ii;  //reverse map//~v640R~//~v67ZR~
//#endif                                                             //~v65cI~//~v67ZR~
            }                                                      //~v640I~
            sbcsctr++;                                             //~v67ZI~
        }                                                          //~v640I~
        else                                                       //~v640I~
        {                                                          //~v@@@I~
        	sbcsid=UCSDDID_DBCS;                                   //~v640I~
            dbcsctr++;                                             //~v@@@I~
        }                                                          //~v@@@I~
//UTRACEP("%s:sbcsid ucs=%04x,sbcsid=%04x,width=%d,flag=x%x\n",UTT,ii,sbcsid,width,flag);//~v@@@R~//~v6Y0R~
//      pud->UCS2DDsbcsid=(WUCS)sbcsid;                            //~v640I~//~v6B4R~
        pud->UCS2DDsbcsid=(USHORT)sbcsid;                          //~v6B4I~
    }                                                              //~v640I~
#ifdef WWW                                                         //~v6BYM~
#else   //!WWW not fixed width0 boundary                           //~v6BYM~
	UTRACEP("%s:total width0ctr=%04d\n",UTT,sbcsw0ctr);            //~v6BYI~
    UTRACEP("%s:last sbcsid=%04x,sbcsctr=%06x,sbcsidctr=0x%x,dbcsctr=0x%x,unprintable=0x%x/0x%x\n",UTT,seqno,sbcsctr,sbcsidctr,dbcsctr,unpctr,UCS2DDMAP_ENTNO);//~v6BYR~//~v@@@R~
	utf22_mapwidth0(plist_width00,sbcsw0ctr,&ovfucs,&ovfucslast,&ovfctr);//~v6BYR~
    ufree(plist_width00);                                          //~v6BYM~
#endif //!WWW not fixed width0 boundary                            //~v6BYM~
#ifdef W32                                                         //~v796I~
	#ifndef WXE                                                    //~v796I~
		uvioGetCursorWidth(UVGCWO_CLOSE,0);                        //~v796I~
    #endif                                                         //~v796I~
#endif                                                             //~v796I~
  }//tbl not loaded                                                //~v6c7I~
	Gulibutfmode|=GULIBSETUCS2MAP;  //map for utfwcwidth was initialized//~v640I~
//  Slastsbcsid=seqno;                                             //~v67ZR~
//  Slastsbcsidw0=seqnow0;                                         //~v67ZR~
	UTRACEP("%s:ovfctr=%d,ovfctrw=%d,ovfucs=0x%04x\n",UTT,ovfctr,ovfctrw0,ovfucs);//~v79aI~
    if (ovfctr||ovfctrw0)                                          //~v650I~
    {                                                              //~v67ZI~
//    	uerrmsg("sbcs map overflow ovfctr=%x(max=%x), for width0:%x(max=%x)",0,//~v67ZR~
//        			ovfctr,UCS2DDMAXSBCSID,ovfctrw0,UCSDDID_ENDWIDTH0);//~v67ZR~
    	if (ovfctr)                                                //~v67ZI~
//        	uerrmsg("%s. u-%06x-->u-%06x(x%04x of x%04x ucs).",0,  //~v67ZR~//~v697R~
//        	uerrmsg("%s. u-%06x-->u-%06x(x%04x of x%04x SBCS).",0, //~v697R~//~v6BYR~
#ifdef AAA                                                         //~v6T7I~
          	uerrmsg("%s. u-%06x-->u-%06x(0x%04x SBCSs of total 0x%04x).",0,//~v6BYI~
                    OVFMSG,                                        //~v67ZI~
          			ovfucs,ovfucslast,ovfctr,sbcsctr);             //~v67ZR~
    	if (ovfctrw0)                                              //~v67ZR~
	      	uerrmsgcat(";%s. u-%06x-->u-%06x(x%04x ucs) for width=0.",0,//~v67ZR~
                    OVFMSG,                                        //~v67ZI~
          			ovfucsw0,ovfucsw0last,ovfctrw0);               //~v67ZI~
    	if (loaded)                                                //~v6c7I~
	      	uerrmsgcat(";(W)try to clear ::%s.xxx",0,                 //~v6c7R~//~v740R~
            			SBCSTBFNM);                                //~v6c7I~
#else                                                              //~v6T7I~
         {                                                         //~vbz4I~
//         	printf("%s",uerrsprintf("%s. u-%06x-->u-%06x(0x%04x SBCSs of total 0x%04x,unprintable=%d/%d).\n",0,//~v6T7R~//~v740R~
           	printf("%s",uerrsprintf("%s. u-%06x-->u-%06x(%d SBCSs of total %d,unprintable=%d/%d).\n",0,//~v740I~
                    OVFMSG,                                        //~v6T7I~
          			ovfucs,ovfucslast,ovfctr,sbcsctr,unpctr,UCS2DDMAP_ENTNO));            //~v6T7I~//~v@@@R~
           	UTRACEP("%s:@@@@Warn %s\n",UTT,uerrsprintf("%s. u-%06x-->u-%06x(%d SBCSs of total %d,unprintable=%d/%d).\n",0,//~vbz4I~
                    OVFMSG,                                        //~vbz4I~
          			ovfucs,ovfucslast,ovfctr,sbcsctr,unpctr,UCS2DDMAP_ENTNO));//~vbz4I~
         }                                                         //~vbz4I~
       if (ovfucs)                                                 //~v79aI~
         if (ovfucs<UCS2DDMAP_ENTNO)	//mapmodify reject if over //~v740I~
         {                                                         //~vbz4I~
          	printf("%s",uerrsprintf("Note:Unicode u-%06x-->u-%06x occupies 2 columns.(Adjustable by UnicodeTbl option of ini file if you want)\n",//~v740R~
          							"注意:u-%06x-->u-%06xのユニコードは２桁\x95\\示になります.(不都合ならiniファイルのUnicodeTblパラメータで調整できます)",//~v740R~
          			ovfucs,ovfucslast));                           //~v70mI~
          	UTRACEP("%s:@@@@Warn %s\n",UTT,uerrsprintf("Note:Unicode u-%06x-->u-%06x occupies 2 columns.(Adjustable by UnicodeTbl option of ini file if you want)\n",//~vbz4I~
          							"注意:u-%06x-->u-%06xのユニコードは２桁\x95\\示になります.(不都合ならiniファイルのUnicodeTblパラメータで調整できます)",//~vbz4I~
          			ovfucs,ovfucslast));                           //~vbz4I~
        }                                                          //~vbz4I~
    	if (ovfctrw0)                                              //~v6T7I~
        {                                                          //~vbz4I~
	      	printf("%s",uerrsprintf(";%s. u-%06x-->u-%06x(x%04x ucs) for width=0.",0,//~v6T7I~
                    OVFMSG,                                        //~v6T7I~
          			ovfucsw0,ovfucsw0last,ovfctrw0));              //~v6T7I~
	      	UTRACEP("%s:@@@@Warn %s\n",UTT,uerrsprintf(";%s. u-%06x-->u-%06x(x%04x ucs) for width=0.",0,//~vbz4I~
                    OVFMSG,                                        //~vbz4I~
          			ovfucsw0,ovfucsw0last,ovfctrw0));              //~vbz4I~
        }                                                          //~vbz4I~
    	if (loaded)                                                //~v6T7I~
	      	printf("%s",uerrsprintf(";(Warning)try to clear ::%s.xxx",0,    //~v6T7I~//~v740R~
            			SBCSTBFNM));                               //~v6T7I~
          	printf("\n");                                          //~v6T7I~
#endif                                                             //~v6T7I~
	Gulibutfmode|=GULIBUTFSBCSIDOVF; //mapinit SBCSid overflow     //~v67ZI~
    }                                                              //~v67ZI~
    UTRACEP("seqno=%d,Max=%d,sbcsctr=0x%06x,sbcsw0ctr=0x%06x,ovfucs=0x%04x,ovfctrw0=0x%04x\n",seqno,UCS2DDMAXSBCSID,sbcsctr,sbcsw0ctr,ovfucs,ovfctrw0);//~vbz4R~
    UTRACEP("sbcscount=0x%x-0x%x,width0top=0x%04x,end=0x%04x\n",UCSDDID_STARTSBCSID,seqno,/*UCSDDID_STARTWIDTH0*/Gudbcschk_width0top,UCS2DDMAXSBCSID);//~v6BYR~
//  UTRACED("mapinit",Gucs2ddmap,sizeof(Gucs2ddmap));              //~v6a0R~
//#ifdef UTF8UCS4                                                    //~v65cI~//~v67ZR~
//  UTRACED("mapiniti2u",Gucs2ddmap_i2u,sizeof(Gucs2ddmap_i2u));   //~v6a0R~
//#endif                                                             //~v65cI~//~v67ZR~
//    UTRACEPF("mapinit test\n");                                  //~v6a0R~
////@@@@ test                                                      //~v6a0R~
//    for (ii=0;ii<0x20000;ii++)                                   //~v6a0R~
//    {                                                            //~v6a0R~
//        width=utfwcwidth(0,ii,&flag);                            //~v6a0R~
//        UTRACEP("utfwcwidth@ ucs=%x,width=%d,flag=%x\n",ii,width,flag);//~v6a0R~
//    }                                                            //~v6a0R~
//  UTRACEPF("mapinit end\n");                                     //~v6a0R~//~v6b9R~
    if (!loaded)                                                   //~v6c7I~
    {                                                              //~v6c7I~
        memset(&savehdr,0,sizeof(savehdr));                        //~v6c7R~
        savehdr.SSTseqno=seqno;                                    //~v6c7R~
        savehdr.SSTovfctr=ovfctr;                                  //~v6c7R~
        savehdr.SSTovfctrw0=ovfctrw0;                              //~v6c7R~
        savehdr.SSTovfucs=ovfucs;                                  //~v6c7R~
        savehdr.SSTovfucslast=ovfucslast;                          //~v6c7R~
        savehdr.SSTsbcsctr=sbcsctr;                                //~v6c7R~
        savehdr.SSTovfucsw0=ovfucsw0;                              //~v6c7R~
        savehdr.SSTovfucsw0last=ovfucsw0last;                      //~v6c7R~
        savehdr.SSTflag=Gulibutfmode;                              //~v6c7R~
        savehdr.SSTwidth0top=Gudbcschk_width0top;                  //~v70mR~
        opt=0;                                                     //~v6c7R~
        utfucssavemap(opt,&savehdr);                               //~v6c7R~
    }                                                              //~v6c7I~
    UTRACEP("%s:completed",UTT);                                   //~v79rI~
    return seqno;                                                  //~v640I~
}//utfucsmapinit                                                   //~v640I~
//*******************************************************          //~v6c7I~
//*SBCS mapping tbl load                                           //~v6c7I~
//*for ARM:from xemain                                             //~v70mI~
//*******************************************************          //~v6c7I~
int utf22setworkdir(int Popt,char *Pworkdir,char *Psuffix)         //~v6c7R~
{                                                                  //~v6c7I~
	char *pc;                                                      //~v6c7I~
//*******************                                              //~v6c7I~
    UTRACEP("utf22setworkdir wkdir=%s,suffix=%s,Ssbcsfnm=%s\n",Pworkdir,Psuffix,Ssbcstbfnm);//~v6k1I~
	if (Psuffix)	//append lang suufix                           //~v6c7R~
    {                                                              //~v6c7I~
    	if (!*Psuffix)                                             //~v6c7I~
        	return 4;                                              //~v6c7I~
        if (!Ssbcstbfnm)                                           //~v6c7I~
        	return 4;                                              //~v6c7I~
    	pc=malloc(strlen(Ssbcstbfnm)+strlen(Psuffix)+8);           //~v6c7R~
#ifdef WXE                                                         //~v6c7I~
	    sprintf(pc,"%s.%s.wxe",Ssbcstbfnm,Psuffix);                //~v6c7I~
#else                                                              //~v6c7I~
#ifdef XXE                                                         //~v6c7I~
	#ifdef ARM                                                     //~v6c7I~
	    sprintf(pc,"%s.%s.arm",Ssbcstbfnm,Psuffix);                //~v6c7I~
    #else                                                          //~v6c7I~
	    sprintf(pc,"%s.%s.xxe",Ssbcstbfnm,Psuffix);                //~v6c7R~
    #endif                                                         //~v6c7I~
#else                                                              //~v6c7I~
	    sprintf(pc,"%s.%s",Ssbcstbfnm,Psuffix);                    //~v6c7I~
#endif                                                             //~v6c7I~
#endif                                                             //~v6c7I~
        free(Ssbcstbfnm);                                          //~v6c7I~
        Ssbcstbfnm=pc;                                             //~v6c7I~
        return 0;                                                  //~v6c7I~
    }                                                              //~v6c7I~
	if (!Pworkdir || !*Pworkdir)                                   //~v6c7I~
    	return 4;                                                  //~v6c7I~
    Ssbcstbfnm=malloc(strlen(Pworkdir)+sizeof(SBCSTBFNM)+4);       //~v6c7I~
    if (*(Pworkdir+strlen(Pworkdir)-1)==DIR_SEPC)                  //~v6c7I~
    	sprintf(Ssbcstbfnm,"%s%s",Pworkdir,SBCSTBFNM);             //~v6c7R~
    else                                                           //~v6c7I~
    	sprintf(Ssbcstbfnm,"%s%c%s",Pworkdir,DIR_SEPC,SBCSTBFNM);  //~v6c7R~
    UTRACEP("utf22setworkdir out Ssbcsfnm=%s\n",Ssbcstbfnm);       //~v6k1I~
    return 0;                                                      //~v6c7I~
}                                                                  //~v6c7I~
//*******************************************************          //~v6c7I~
//*/proc/version chk for re-create sbcsid tbl                      //~v6c7I~
//*rc:0 same version                                               //~v6c7I~
//*******************************************************          //~v6c7I~
int utf22versionchk(int Popt)                                      //~v6c7I~
{                                                                  //~v6c7I~
    FILE *fh1=0,*fh3;                                              //~v6c7I~
#ifdef LNX                                                         //~v6c7I~
    FILE *fh2;                                                     //~v6c7R~
  #ifndef ARM                                                      //~vc1cI~
    char *sysver="/proc/version";                                  //~v6c7M~
  #endif                                                           //~vc1cI~
#else                                                              //~v6c7I~
    int maj,min,info;                                              //~v6c7I~
#endif                                                             //~v6c7I~
    char vfnm[_MAX_PATH];                                          //~v6c7R~
    int rc=0;                                                      //~v6c7I~
#define BUFFSZ 4096                                                //~v6c7I~
    char buff1[BUFFSZ],buff2[BUFFSZ];                              //~v6c7I~
//*********************                                            //~v6c7I~
	sprintf(vfnm,"%s.version",Ssbcstbfnm);                         //~v6c7I~
#ifdef W32                                                         //~v6c7I~
	udos_version(&maj,&min,&info);                                 //~v6c7I~
    sprintf(buff2,"%d-%d-%d",maj,min,info);                        //~v6c7M~
#else                                                              //~v6c7M~
  #ifdef ARM                                                       //~vc1cI~
    sprintf(buff2,"%d-%d",GarmApiLevel,GarmApiRelease);                //~vc1cI~
    fh2=NULL;                                                      //~vc1cI~
  #else                                                            //~vc1cI~
	fh2=fopen(sysver,"r");                                         //~v6c7I~
    if (!fh2)                                                      //~v6c7I~
    {                                                              //~v6c7I~
        UTRACEP("%s:fopen(%s) faled errno=%d\n",UTT,sysver,errno); //~v708R~
//  	fclose(fh2);                                               //~v6c7R~//~v708R~
    	return 8;                                                  //~v6c7I~
    }                                                              //~v6c7I~
    if (!fgets(buff2,BUFFSZ,fh2))                                  //~v6c7I~
    	rc=16;                                                     //~v6c7I~
    else                                                           //~v6c7I~
  #endif                                                           //~vc1cI~
#endif                                                             //~v6c7I~
    {                                                              //~v6c7I~
		fh1=fopen(vfnm,"r");                                       //~v6c7I~
        UTRACEP("%s:vfnm=%s open fh=%p\n",UTT,vfnm,fh1);            //~vc1cI~
    	if (!fh1                                                   //~v6c7R~
    	||  !fgets(buff1,BUFFSZ,fh1))                              //~v6c7R~
        {                                                          //~vc1cI~
	        UTRACEP("%s:vfnm=%s ,file open/read err\n",UTT,vfnm);   //~vc1cI~
        	rc=4;                                                  //~v6c7I~
        }                                                          //~vc1cI~
        else                                                       //~v6c7I~
    	if (strcmp(buff1,buff2))                                   //~v6c7R~
        {                                                          //~v6c7I~
            uerrmsgcat("System Version update detected for Sbcsid table.",0);//~v6c7R~
        	rc=24;                                                 //~v6c7R~
        }                                                          //~v6c7I~
        UTRACEP("%s:rc=%d,vfnm=%s,file saved version=%s,curr version=%s\n",UTT,rc,vfnm,buff1,buff2);//~vc1cI~
        if (rc)                                                    //~v6c7I~
        {                                                          //~v6c7I~
            fh3=fopen(vfnm,"w");                                   //~v6c7R~
            if (!fh3)                                              //~v6c7R~
                rc=28;                                             //~v6c7R~
            else                                                   //~v6c7R~
            {                                                      //~v6c7R~
                fputs(buff2,fh3);                                  //~v6c7R~
                fclose(fh3);                                       //~v6c7R~
            }                                                      //~v6c7R~
        }                                                          //~v6c7I~
    }                                                              //~v6c7R~
    if (fh1)                                                       //~v6c7I~
	    fclose(fh1);                                               //~v6c7R~
#ifdef W32                                                         //~v6c7I~
#else                                                              //~v6c7I~
  if (fh2)                                                         //~vc1cI~
    fclose(fh2);                                                   //~v6c7I~
#endif                                                             //~v6c7I~
    UTRACEP("%s:rc=%d\n",UTT,rc);                                  //~v70mI~
    return rc;                                                     //~v6c7I~
}                                                                  //~v6c7I~
//*******************************************************          //~v6c7I~
//*SBCS mapping tbl load                                           //~v6c7I~
//*******************************************************          //~v6c7I~
int utfucsloadmap(int Popt,PSAVESBCSTB Ppsbcstbhdr)                //~v6c7I~
{                                                                  //~v6c7I~
    FILE *fh;                                                      //~v6c7I~
    int sz1=0,sz2=0;                                               //~v6h4R~
    char *locale;                                                  //~v6c7R~
    int rc;                                                        //~v6c7R~
//*********************                                            //~v6c7I~
    UTRACEP("%s:entry Ssbcstbfnm=%s\n",UTT,Ssbcstbfnm);                              //~v6k1I~//~v70mR~
    if (!Ssbcstbfnm)                                               //~v6c7R~
    {                                                              //~v70mI~
	    UTRACEP("%s:skip load\n",UTT);                             //~v70mI~
    	return 4;                                                  //~v6c7R~
    }                                                              //~v70mI~
    locale=udbcschk_setlocale(0,LC_ALL,0);                         //~v6c7R~
    UTRACEP("utfucsloadmap locale=%s\n",locale);                   //~v6k1I~
    rc=utf22versionchk(0);    //version changed,version file is without no locale suffix//~v6c7I~
    UTRACEP("utfucsloadmap parm locale=%s\n",locale);              //~v6k1I~
	utf22setworkdir(0,0,locale);                                   //~v6c7R~
#ifdef ARM                                                         //~v6k1I~
	if (Gjniopt & GJNIO_RELOADSBCSMAP)	//jnij2c set               //~v6k1M~
    	return 1;                                                  //~v6k1M~
#endif                                                             //~v6k1I~
    if (rc)	//after appended locale suffix to Sbcstbl filename     //~v6c7I~
    	return 4;                                                  //~v6c7M~
    UTRACEP("utfucsloadmap open=%s\n",Ssbcstbfnm);                 //~v6k1I~
	fh=fopen(Ssbcstbfnm,"rb");                                     //~v6c7R~
    if (!fh)                                                       //~v6c7I~
    {                                                              //~v6c7I~
  		uerrmsgcat("Sbcsmap table file(%s) is not found.",0,       //~v6c7R~
        			Ssbcstbfnm);                                   //~v6c7R~
    	return 8;                                                  //~v6c7I~
    }                                                              //~v6c7I~
    if (!fread(Ppsbcstbhdr,sizeof(SAVESBCSTB),1,fh))               //~v6c7R~
    {                                                              //~v6c7I~
    	rc=4;                                                      //~v6c7R~
    }                                                              //~v6c7I~
    else                                                           //~v6c7I~
    {                                                              //~v6c7I~
        sz1=sizeof(Gucs2ddmap);                                    //~v6c7R~
        sz2=sizeof(Gucs2ddmap_i2u);                                //~v6c7R~
    	UTRACEP("%s:sz1=0x%x,sz2=0x%x,SSTlength1=0x%x,SSTlength2=0x%x\n",UTT,sz1,sz2,Ppsbcstbhdr->SSTlength1,Ppsbcstbhdr->SSTlength2);//~v740I~
        if (sz1!=Ppsbcstbhdr->SSTlength1                           //~v6c7R~
        ||  sz2!=Ppsbcstbhdr->SSTlength2)                          //~v6c7R~
        {                                                          //~v740I~
	    	UTRACEP("%s:rc=4 by size unmatch\n");                  //~v740I~
            rc=4;                                                  //~v6c7R~
        }                                                          //~v740I~
    }                                                              //~v6c7I~
    if (!rc)                                                       //~v6c7I~
    {                                                              //~v6c7I~
//      if (!fread(Gucs2ddmap,sz1,1,fh))                           //~v6c7R~//~v6B4R~
        if (!fread(Gucs2ddmap,(size_t)sz1,1,fh))                   //~v6B4I~
        {                                                          //~v6c7R~
//          memset(Gucs2ddmap,0,sz1);                              //~v6c7R~//~v6B4R~
            memset(Gucs2ddmap,0,(size_t)sz1);                      //~v6B4I~
            rc=4;                                                  //~v6c7R~
        }                                                          //~v6c7R~
    	else                                                       //~v6c7I~
//      if (!fread(Gucs2ddmap_i2u,sz2,1,fh))                       //~v6c7R~//~v6B4R~
        if (!fread(Gucs2ddmap_i2u,(size_t)sz2,1,fh))               //~v6B4I~
        {                                                          //~v6c7R~
//          memset(Gucs2ddmap,0,sz1);                              //~v6c7R~//~v6B4R~
            memset(Gucs2ddmap,0,(size_t)sz1);                      //~v6B4I~
//          memset(Gucs2ddmap_i2u,0,sz2);                          //~v6c7R~//~v6B4R~
            memset(Gucs2ddmap_i2u,0,(size_t)sz2);                  //~v6B4I~
            rc=4;                                                  //~v6c7R~
        }                                                          //~v6c7R~
        UTRACED("utfucsloadmap Gucs2ddmap",Gucs2ddmap,sz1);        //~vc1cI~
        UTRACED("utfucsloadmap Gucs2ddmap_i2u",Gucs2ddmap,sz2);    //~vc1cI~
    }                                                              //~v6c7I~
    fclose(fh);                                                    //~v6c7I~
    UTRACEP("utfucsloadmap rc=%d\n",rc);                           //~vc1cI~
    return rc;                                                     //~v6c7R~
}//utfucsloadmap                                                   //~v6c7I~
//*******************************************************          //~v6c7I~
//*SBCS mapping tabl write to workdir                              //~v6c7I~
//*******************************************************          //~v6c7I~
int utfucssavemap(int Popt,PSAVESBCSTB Ppsbcstbhdr)                //~v6c7I~
{                                                                  //~v6c7I~
    FILE *fh;                                                      //~v6c7I~
    int rc=0;                                                      //~v6c7I~
//*********************                                            //~v6c7I~
    if (!Ssbcstbfnm)                                               //~v6c7R~
    	return 4;                                                  //~v6c7R~
	Ppsbcstbhdr->SSTlength1=sizeof(Gucs2ddmap);                    //~v6c7I~
	Ppsbcstbhdr->SSTlength2=sizeof(Gucs2ddmap_i2u);                //~v6c7I~
    UTRACEP("utfucssavemap fnm=%s\n",Ssbcstbfnm);                  //~v6k1I~
	fh=fopen(Ssbcstbfnm,"wb");                                     //~v6c7R~
    if (!fh)                                                       //~v6c7I~
    	rc=4;                                                      //~v6c7R~
    if (!rc)                                                       //~v6c7I~
    	if (!fwrite(Ppsbcstbhdr,sizeof(SAVESBCSTB),1,fh))          //~v6c7R~
    		rc=4;                                                  //~v6c7R~
    if (!rc)                                                       //~v6c7I~
//  	if (!fwrite(Gucs2ddmap,Ppsbcstbhdr->SSTlength1,1,fh))      //~v6c7R~//~v6B4R~
    	if (!fwrite(Gucs2ddmap,(size_t)Ppsbcstbhdr->SSTlength1,1,fh))//~v6B4I~
    		rc=4;                                                  //~v6c7R~
    if (!rc)                                                       //~v6c7I~
//  	if (!fwrite(Gucs2ddmap_i2u,Ppsbcstbhdr->SSTlength2,1,fh))  //~v6c7R~//~v6B4R~
    	if (!fwrite(Gucs2ddmap_i2u,(size_t)Ppsbcstbhdr->SSTlength2,1,fh))//~v6B4I~
    		rc=4;                                                  //~v6c7R~
    if (rc)                                                        //~v6c7I~
//		uerrmsgcat("Sbcsmap table file write failed",0);           //~v6k1R~
  		uerrmsgcat("Sbcsmap table file write failed(%s)",0,        //~v6k1I~
        	Ssbcstbfnm);                                           //~v6k1I~
    else                                                           //~v6c7I~
    {                                                              //~v740I~
//		uerrmsgcat("Sbcsmap table file was created",0);            //~v6k1R~
//		uerrmsgcat("Sbcsmap table file was created(%s)",0,         //~v6k1R~//~v740R~
//      	Ssbcstbfnm);                                           //~v6k1I~//~v740R~
  		UTRACEP("%s:Sbcsmap table file was created(%s)\n",UTT,Ssbcstbfnm);//~v740I~
    }                                                              //~v740I~
    fclose(fh);                                                    //~v6c7I~
    return rc;                                                     //~v6c7R~
}//utfucssavemap                                                   //~v6c7I~
//#ifdef AAA                                                         //~v67ZI~//~v6uBR~
////*******************************************************          //~v640I~//~v6uBR~
////*SBCS mapping tabl init for u0000-uffff                          //~v640I~//~v6uBR~
////unicode map to ddfmt unicodeid                                   //~v640I~//~v6uBR~
////*******************************************************          //~v640I~//~v6uBR~
//int utfucsmapmodify(int Popt,int Pdatatype,int Pstartucs,int Penducs)//~v640R~//~v6uBR~
//{                                                                  //~v640I~//~v6uBR~
//    int ii,sbcsid,seqno,oldsbcsid;                                 //~v640I~//~v6uBR~
//    int seqnow0;                                                   //~v650I~//~v6uBR~
//    PUCS2DDMAP pud;                                                //~v640I~//~v6uBR~
////*********************                                            //~v640I~//~v6uBR~
//    if (Pstartucs>Penducs)                                         //~v640I~//~v6uBR~
//        return 4;                                                  //~v640I~//~v6uBR~
//UTRACEP("mapmodify last sbcsid=%04x,start=%04x,end=%04x,datatype=%d\n",Slastsbcsid,Pstartucs,Penducs,Pdatatype);//~v640R~//~v6uBR~
//    seqnow0=Slastsbcsidw0;                                         //~v650I~//~v6uBR~
//    for (ii=Pstartucs,seqno=Slastsbcsid;ii<=Penducs;ii++)          //~v640I~//~v6uBR~
//    {                                                              //~v640I~//~v6uBR~
//        if (ii<UCSDDID_STARTUCS)    //ascii                        //~v640I~//~v6uBR~
//            continue;                                              //~v640I~//~v6uBR~
//#ifdef UTF8UCS4                                                    //~v65cI~//~v6uBR~
//        if (ii>=UCS2DDMAP_ENTNO)    //this range is all dbcs       //~v65cI~//~v6uBR~
//        {                                                          //~v65cI~//~v6uBR~
//            uerrmsg("UCS should be < %x",0,                        //~v65cI~//~v6uBR~
//                        UCS2DDMAP_ENTNO);                          //~v65cR~//~v6uBR~
//            continue;                                              //~v65cI~//~v6uBR~
//        }                                                          //~v65cI~//~v6uBR~
//#endif                                                             //~v65cI~//~v6uBR~
//        pud=Gucs2ddmap+ii;                                         //~v640I~//~v6uBR~
//        oldsbcsid=pud->UCS2DDsbcsid;                               //~v640I~//~v6uBR~
//UTRACEP("mapmodify oldsbcsid=%04x for ucs=%04x\n",oldsbcsid,ii);   //~v650R~//~v6uBR~
//UTRACED("mapmodify old pud",pud,UCS2DDMAPSZ);                      //~v640I~//~v6uBR~
//        if (Pdatatype==1)   //new sbcs                             //~v640I~//~v6uBR~
//        {                                                          //~v640I~//~v6uBR~
////          if (oldsbcsid<UCSDDID_STARTSBCSID)  //not sbcs->sbcs   //~v640I~//~v650R~//~v6uBR~
//            if (oldsbcsid<UCSDDID_STARTSBCSID   //not sbcs->sbcs   //~v650I~//~v6uBR~
//            ||  oldsbcsid>=UCSDDID_STARTWIDTH0  //width0->normal SBCS//~v650I~//~v6uBR~
//            )                                                      //~v650I~//~v6uBR~
//            {                                                      //~v640I~//~v6uBR~
//                if (seqno==UCS2DDMAXSBCSID) //sbcs count reached mas//~v640I~//~v6uBR~
//                {                                                  //~v650I~//~v6uBR~
//                    sbcsid=UCSDDID_OVERFLOW;                       //~v640I~//~v6uBR~
//#ifdef UTF8UCS4                                                    //~v65cI~//~v6uBR~
//                    uerrmsg("SBCS tbl overflow for %08x(max:%d),treated as DBCS",0,//~v65cI~//~v6uBR~
//                        ii,UCSDDID_STARTWIDTH0);                   //~v65cR~//~v6uBR~
//#else                                                              //~v65cI~//~v6uBR~
//                    uerrexit("SBCS tbl overflow from x%04x to x%04x",0,//~v650I~//~v6uBR~
//                        UCSDDID_STARTSBCSID,UCS2DDMAXSBCSID);      //~v650I~//~v6uBR~
//#endif                                                             //~v65cI~//~v6uBR~
//                }                                                  //~v650I~//~v6uBR~
//                else                                               //~v640I~//~v6uBR~
//                {                                                  //~v640I~//~v6uBR~
//                    if (ii<UCSDDID_STARTSBCSID) //range avoid mapping//~v640I~//~v6uBR~
//                        sbcsid=ii;                                 //~v640I~//~v6uBR~
//                    else                                           //~v640I~//~v6uBR~
//                    {                                              //~v640I~//~v6uBR~
////                      if ((seqno & 0xff)<0x30) //low byte<0x30   //~v640I~//~v69bR~//~v6uBR~
////                          seqno+=0x30;                           //~v640I~//~v69bR~//~v6uBR~
//                        if (!(seqno & 0xff)) //low byte<0x30       //~v69bI~//~v6uBR~
//                            seqno+=UDBCSCHK_SBCSIDWRAP;  //leave "<=0x20" unused for sbcsid for data scan//~v69bI~//~v6uBR~
//                        sbcsid=seqno++;                            //~v640I~//~v6uBR~
//                    }                                              //~v640I~//~v6uBR~
//#ifdef UTF8UCS4                                                    //~v65cI~//~v6uBR~
//                    Gucs2ddmap_i2u[sbcsid]=(WUCS)ii;    //reverse map//~v65cI~//~v6uBR~
//#else                                                              //~v65cI~//~v6uBR~
//                    Gucs2ddmap[sbcsid].UCS2DDucs=(WUCS)ii;  //reverse map//~v640I~//~v6uBR~
//#endif                                                             //~v65cI~//~v6uBR~
//UTRACEP("mapmodify sbcsid ucs=%04x,newsbcsid=%04x\n",ii,sbcsid);   //~v650R~//~v6uBR~
//                }                                                  //~v640I~//~v6uBR~
//                pud->UCS2DDsbcsid=(WUCS)sbcsid;                    //~v640R~//~v6uBR~
//            }                                                      //~v640I~//~v6uBR~
//        }                                                          //~v640I~//~v6uBR~
//        else                                                       //~v640I~//~v6uBR~
//        if (Pdatatype==0)   //width=0 SBCS                         //~v650I~//~v6uBR~
//        {                                                          //~v650I~//~v6uBR~
//            if (oldsbcsid<UCSDDID_STARTWIDTH0)  //new width0 sbcsid assign required//~v650I~//~v6uBR~
//            {                                                      //~v650I~//~v6uBR~
//                if (seqnow0==UCSDDID_ENDWIDTH0) //reached to width=1 sbcsid//~v650I~//~v6uBR~
//                {                                                  //~v650I~//~v6uBR~
//                    sbcsid=UCSDDID_OVERFLOW;                       //~v650I~//~v6uBR~
//#ifdef UTF8UCS4                                                    //~v65cI~//~v6uBR~
//                    uerrmsg("SBCS(Width=0) tbl overflow for %08x(max:%d),treated as DBCS",0,//~v65cI~//~v6uBR~
//                        ii,UCSDDID_ENDWIDTH0-UCSDDID_STARTWIDTH0); //~v65cI~//~v6uBR~
//#else                                                              //~v65cI~//~v6uBR~
//                    uerrexit("SBCS(Width=0) tbl overflow from x%04x to x%04x",0,//~v650I~//~v6uBR~
//                        UCSDDID_STARTSBCSID,UCS2DDMAXSBCSID);      //~v650I~//~v6uBR~
//#endif                                                             //~v65cI~//~v6uBR~
//                }                                                  //~v650I~//~v6uBR~
//                else                                               //~v650I~//~v6uBR~
//                {                                                  //~v650I~//~v6uBR~
////                  if ((seqnow0 & 0xff)<0x30) //low byte<0x30     //~v650I~//~v69bR~//~v6uBR~
////                      seqnow0+=0x30;                             //~v650I~//~v69bR~//~v6uBR~
//                    if (!(seqnow0 & 0xff)) //low byte<0x30         //~v69bI~//~v6uBR~
//                        seqnow0+=UDBCSCHK_SBCSIDWRAP;  //leave "<=0x20" unused for sbcsid for data scan//~v69bI~//~v6uBR~
//                    sbcsid=seqnow0++;                              //~v650I~//~v6uBR~
//#ifdef UTF8UCS4                                                    //~v65cI~//~v6uBR~
//                    Gucs2ddmap_i2u[sbcsid]=(WUCS)ii;    //reverse map//~v65cI~//~v6uBR~
//#else                                                              //~v65cI~//~v6uBR~
//                    Gucs2ddmap[sbcsid].UCS2DDucs=(WUCS)ii;  //reverse map//~v650I~//~v6uBR~
//#endif                                                             //~v65cI~//~v6uBR~
//UTRACEP("mapmodify sbcsid width=0, ucs=%04x,newsbcsid=%04x\n",ii,sbcsid);//~v650I~//~v6uBR~
//                }                                                  //~v650I~//~v6uBR~
//                pud->UCS2DDsbcsid=(WUCS)sbcsid;                    //~v650I~//~v6uBR~
//            }                                                      //~v650I~//~v6uBR~
//        }                                                          //~v650I~//~v6uBR~
//        else                                                       //~v650I~//~v6uBR~
//        {                                                          //~v640I~//~v6uBR~
//            if (Pdatatype==2)   //new dbcs                         //~v640I~//~v6uBR~
//                pud->UCS2DDsbcsid=UCSDDID_DBCS;  //change to dbcs  //~v640I~//~v6uBR~
//            else                                                   //~v640I~//~v6uBR~
//                pud->UCS2DDsbcsid=UCSDDID_UNP;   //change to unprintable//~v640I~//~v6uBR~
//            if (oldsbcsid>=UCSDDID_STARTSBCSID) //sbcs->dbcs       //~v640I~//~v6uBR~
//#ifdef UTF8UCS4                                                    //~v65cI~//~v6uBR~
//                Gucs2ddmap_i2u[oldsbcsid]=0;    //reverse map      //~v65cI~//~v6uBR~
//#else                                                              //~v65cI~//~v6uBR~
//                Gucs2ddmap[oldsbcsid].UCS2DDucs=0;        //old sbcsid was freed//~v640I~//~v6uBR~
//#endif                                                             //~v65cI~//~v6uBR~
//        }                                                          //~v640I~//~v6uBR~
//UTRACED("mapmodify new pud",pud,UCS2DDMAPSZ);                      //~v640I~//~v6uBR~
//    }                                                              //~v640I~//~v6uBR~
//    Slastsbcsid=seqno;                                             //~v640I~//~v6uBR~
//    UTRACED("mapmodify",Gucs2ddmap,sizeof(Gucs2ddmap));            //~v640I~//~v6uBR~
//    UTRACEP("sbcscount=%04x\n",seqno);                             //~v640R~//~v6uBR~
//    return 0;                                                      //~v640I~//~v6uBR~
//}//utfucsmapmodify                                                 //~v640I~//~v6uBR~
//#else                                                              //~v67ZI~//~v6uBR~
//*******************************************************          //~v67ZI~
//*SBCS mapping tabl remap                                         //~v67ZI~
//unicode map to ddfmt unicodeid                                   //~v67ZI~
//*******************************************************          //~v67ZI~
int utfucsmapinit_remap(int Popt)                                  //~v67ZI~
{                                                                  //~v67ZI~
	int ii,sbcsid,seqno=UCSDDID_STARTSBCSID;                       //~v67ZR~
#ifdef WWW                                                         //~v6BYI~
    int seqnow0=UCSDDID_STARTWIDTH0,ovfctr=0,ovfctrw0=0;           //~v67ZI~
#else                                                              //~v6BYI~
    int /*seqnow0=0,*/ovfctr=0,ovfctrw0=0;                             //~v6BYR~//~v6DhR~
    WUCS *plist_width0,*plist_width00;                             //~v6BYI~
    int plist_width0_size;                                         //~v6BYI~
    int sbcsw0ctr=0;                                               //~v6BYI~
#endif                                                             //~v6BYI~
    PUCS2DDMAP pud;                                                //~v67ZI~
    int ovfucs=0,ovfucsw0=0,ovfucslast=0,ovfucsw0last=0,oldsbcsid; //~v6h4R~
    char *pemsg;                                                   //~v67ZI~
    int sbcsctr=0;                                                 //~v67ZI~
//*********************                                            //~v67ZI~
    UTRACED("before u2i",Gucs2ddmap,sizeof(Gucs2ddmap));           //~v6BZI~
    UTRACED("before i2u",Gucs2ddmap_i2u,sizeof(Gucs2ddmap_i2u));   //~v6BZI~
#ifdef WWW                                                         //~v6BYI~
#else                                                              //~v6BYI~
    plist_width0_size=UCS2DDMAP_ENTNO*(int)sizeof(plist_width0[0]);//~v6BYI~
    plist_width00=plist_width0=umalloc((UINT)plist_width0_size);   //~v6BYI~
    memset(Gucs2ddmap_i2u,0,sizeof(Gucs2ddmap_i2u));               //~v6BYI~
#endif                                                             //~v6BYI~
	for (ii=UCSDDID_STARTUCS,pud=Gucs2ddmap+ii;ii<UCS2DDMAP_ENTNO;ii++,pud++)//~v67ZI~
    {                                                              //~v67ZI~
        UTRACEP("utfremap ucs=%06x sbcsid=%04x\n",ii,pud->UCS2DDsbcsid);//~v67ZI~//~v6BYM~
    	oldsbcsid=pud->UCS2DDsbcsid;                               //~v67ZI~
#ifdef WWW                                                         //~v6BYI~
        if (oldsbcsid>=UCSDDID_STARTWIDTH0	//sbcs                 //~v67ZR~
        ||  oldsbcsid==UCSDDID_OVERFLOWW0)	//width=0 sbcs overflow previousely//~v67ZI~
        {                                                          //~v67ZI~
        	if (seqnow0==UCSDDID_ENDWIDTH0)	//reached to width=1 sbcsid//~v67ZI~//~v6BYR~
            {                                                      //~v67ZI~
                if (!ovfctrw0)                                     //~v67ZI~
                	ovfucsw0=ii;                                   //~v67ZI~
                ovfucsw0last=ii;                                   //~v67ZI~
            	sbcsid=UCSDDID_OVERFLOWW0;                         //~v67ZR~
                ovfctrw0++;                                        //~v67ZI~
            }                                                      //~v67ZI~
            else                                                   //~v67ZI~
            {                                                      //~v67ZI~
//  			if ((seqnow0 & 0xff)<0x30) //low byte<0x30         //~v67ZI~//~v69bR~
//              	seqnow0+=0x30;                                 //~v67ZI~//~v69bR~
    			if (!(seqnow0 & 0xff)) //low byte<0x30             //~v69bR~
                	seqnow0+=UDBCSCHK_SBCSIDWRAP;  //leave "<=0x20" unused for sbcsid for data scan//~v69bI~
        		sbcsid=seqnow0++;                                  //~v67ZI~
            	Gucs2ddmap_i2u[sbcsid]=(WUCS)ii;	//reverse map  //~v67ZI~
//UTRACEP("mapinit width=0:sbcsid ucs=%04x,sbcsid=%04x\n",ii,sbcsid);//~v6a0R~
            }                                                      //~v67ZI~
//          pud->UCS2DDsbcsid=(WUCS)sbcsid;                        //~v67ZI~//~v6B4R~
            pud->UCS2DDsbcsid=(USHORT)sbcsid;                      //~v6B4I~
            sbcsctr++;                                             //~v67ZI~
        }                                                          //~v67ZI~
        else                                                       //~v67ZI~
#else                                                              //~v6BYI~
        sbcsid=oldsbcsid;   //for trace                            //~v6BYI~
        if (oldsbcsid & UCSDDID_WIDTH0_MODIFY	//width0 modification//~v6BYI~
        ||  oldsbcsid>=Gudbcschk_width0top)  	//originally width0 modification//~v6BYI~
        {                                                          //~v6BYI~
            *plist_width0++=(WUCS)ii;                            //~v6BYI~
            sbcsw0ctr++;                                           //~v6BYR~
        	pud->UCS2DDsbcsid=0;	//once clear                   //~v6BYR~
            sbcsid=0;   //for trace                                //~v6BYI~
        }                                                          //~v6BYI~
        else                                                       //~v6BYI~
#endif                                                             //~v6BYI~
        if (oldsbcsid>=UCSDDID_STARTUCS	//sbcs                     //~v67ZR~
        ||  oldsbcsid==UCSDDID_OVERFLOW)	//sbcs overflow previousely//~v67ZI~
        {                                                          //~v67ZI~
        	if (seqno==UCS2DDMAXSBCSID)	//sbcs count reached max   //~v67ZI~
            {                                                      //~v67ZI~
            	sbcsid=UCSDDID_OVERFLOW;                           //~v67ZI~
                if (!ovfctr)                                       //~v67ZI~
                	ovfucs=ii;                                     //~v67ZI~
                ovfucslast=ii;                                     //~v67ZI~
                ovfctr++;                                          //~v67ZI~
            }                                                      //~v67ZI~
            else                                                   //~v67ZI~
            {                                                      //~v67ZI~
            	if (ii<UCSDDID_STARTSBCSID)	//range avoid mapping  //~v67ZI~
                {                                                  //~v67ZI~
                	sbcsid=ii;                                     //~v67ZI~
            	}                                                  //~v67ZI~
                else                                               //~v67ZI~
                {                                                  //~v67ZI~
//  			 	if ((seqno & 0xff)<0x30) //low byte<0x30       //~v67ZI~//~v69bR~
//                		seqno+=0x30;                               //~v67ZI~//~v69bR~
    			 	if (!(seqno & 0xff)) //low byte<0x30           //~v69bI~
                  		seqno+=UDBCSCHK_SBCSIDWRAP;  //leave "<=0x20" unused for sbcsid for data scan//~v69bI~
        			sbcsid=seqno++;                                //~v67ZI~
                }                                                  //~v67ZI~
            	Gucs2ddmap_i2u[sbcsid]=(WUCS)ii;	//reverse map  //~v67ZI~
            }                                                      //~v67ZI~
//          pud->UCS2DDsbcsid=(WUCS)sbcsid;                        //~v67ZI~//~v6B4R~
            pud->UCS2DDsbcsid=(USHORT)sbcsid;                      //~v6B4I~
            sbcsctr++;                                             //~v67ZI~
        }                                                          //~v67ZI~
UTRACEP("REmapinit sbcsid ucs=%04x,sbcsid=%04x\n",ii,sbcsid);      //~v6BYM~
    }                                                              //~v67ZI~
#ifdef WWW                                                         //~v6BYI~
#else                                                              //~v6BYI~
	UTRACEP("%s:total width0ctr=%04d\n",UTT,sbcsw0ctr);            //~v6BYI~
    UTRACEP("%s:last sbcsid=%04x,sbcsctr=%06x\n",UTT,seqno,sbcsctr);//~v6BYI~
	utf22_mapwidth0(plist_width00,sbcsw0ctr,&ovfucs,&ovfucslast,&ovfctr);//~v6BYI~
    ufree(plist_width00);                                          //~v6BYI~
#endif                                                             //~v6BYI~
//    Slastsbcsid=seqno;                                           //~v67ZR~
//    Slastsbcsidw0=seqnow0;                                       //~v67ZR~
    if (ovfctr||ovfctrw0)                                          //~v67ZI~
    {                                                              //~v67ZI~
    	if (ovfctr)                                                //~v67ZI~
//	      	uerrmsg("%s even after REMAP. u-%06x-->u-%06x(x%04x of x%04x ucs).",0,//~v740R~
  	      	uerrmsg("%s even after REMAP. u-%06x-->u-%06x(%d of %d ucs).",0,//~v740I~
                    OVFMSG,                                        //~v67ZI~
          			ovfucs,ovfucslast,ovfctr,sbcsctr);             //~v67ZI~
    	if (ovfctrw0)                                              //~v67ZI~
	      	uerrmsgcat(";%s. u-%06x-->u-%06x(x%04x ucs) for width=0.",0,//~v67ZR~
                    OVFMSG,                                        //~v67ZI~
          			ovfucsw0,ovfucsw0last,ovfctrw0);               //~v67ZI~
		Gulibutfmode |= GULIBUTFSBCSIDOVF; //mapinit SBCSid overflow//~v67ZI~
    }                                                              //~v67ZI~
    else                                                           //~v67ZI~
    {                                                              //~v67ZI~
		if (Gulibutfmode & GULIBUTFSBCSIDOVF) //mapinit SBCSid overflow//~v67ZI~
        {                                                          //~v67ZI~
            pemsg=ugeterrmsg2();  //widthout clear                 //~v67ZR~
			if (!pemsg || memcmp(pemsg,OVFMSG,sizeof(OVFMSG)-1))   //~v67ZR~
	      		uerrmsg("sbcs map was overflow released",0);       //~v67ZR~
            else                                                   //~v67ZI~
            {                                                      //~v67ZI~
	      		uerrmsg("sbcs map was overflow released",0);    //log to console//~v67ZR~
            	pemsg=ugeterrmsg();  //clear                       //~v67ZI~
            }                                                      //~v67ZI~
			Gulibutfmode &= ~GULIBUTFSBCSIDOVF; //mapinit SBCSid overflow//~v67ZI~
        }                                                          //~v67ZI~
    }                                                              //~v67ZI~
	Gulibutfmode|=GULIBUTFSBCSIDREMAP;  //mapinit SBCSid overflow  //~v67ZI~
    UTRACEP("sbcs ctr=%d,0x%x-0x%x,%04x-\n",sbcsctr,UCSDDID_STARTSBCSID,seqno,Gudbcschk_width0top);//~v67ZI~//~v6BYR~//~v6BZR~//~v6DhR~
    UTRACED("after u2i",Gucs2ddmap,sizeof(Gucs2ddmap));              //~v67ZI~//~v6BZR~
    UTRACED("after i2u",Gucs2ddmap_i2u,sizeof(Gucs2ddmap_i2u));   //~v67ZI~//~v6BZR~
    return seqno;                                                  //~v67ZI~
}//utfucsmapinit_remap                                             //~v67ZI~
//*******************************************************          //~v67ZI~
//*SBCS mapping tabl init for u0000-uffff                          //~v67ZI~
//unicode map to ddfmt unicodeid                                   //~v67ZI~
//*******************************************************          //~v67ZI~
int utfucsmapmodify(int Popt,int Pdatatype,int Pstartucs,int Penducs)//~v67ZI~
{                                                                  //~v67ZI~
	int ii/*,oldsbcsid*/;                                              //~v67ZI~//~v6b9R~
    PUCS2DDMAP pud;                                                //~v67ZI~
//*********************                                            //~v67ZI~
	if (Popt & 0x01)	//end of list,update all                   //~v67ZI~
    	return utfucsmapinit_remap(0);                             //~v67ZR~
	if (Pstartucs>Penducs)                                         //~v67ZI~
    	return 4;                                                  //~v67ZI~
UTRACEP("mapmodify start=%04x,end=%04x,datatype=%d\n",Pstartucs,Penducs,Pdatatype);//~v67ZR~
	for (ii=Pstartucs;ii<=Penducs;ii++)                            //~v67ZI~
    {                                                              //~v67ZI~
    	if (ii<UCSDDID_STARTUCS)	//ascii                        //~v67ZI~
        	continue;                                              //~v67ZI~
    	if (ii>=UCS2DDMAP_ENTNO)	//this range is all dbcs u20000//~v67ZI~
        {                                                          //~v67ZI~
//          uerrmsg("UCS should be < %x",0,                        //~v67ZI~//~v6C4R~
//  		        	UCS2DDMAP_ENTNO);                          //~v67ZI~//~v6C4R~
#ifdef W32                                                         //~v6C4I~
            uerrmsg("Unicode err in the file of UnicodeTbl parameter of ini file, u-%06x is over limit(<u-%06x on Windows)",0,//~v6C4R~
    		        	ii,UCS2DDMAP_ENTNO);                       //~v6C4R~
#else                                                              //~v6C4I~
            uerrmsg("Unicode err in the file of UnicodeTbl parameter of ini file, u-%06x is over limit(<u-%06x on Linux)",0,//~v6C4R~
    		        	ii,UCS2DDMAP_ENTNO);                       //~v6C4R~
#endif                                                             //~v6C4I~
        	continue;                                              //~v67ZI~
        }                                                          //~v67ZI~
		pud=Gucs2ddmap+ii;                                         //~v67ZI~
//      oldsbcsid=pud->UCS2DDsbcsid;                               //~v67ZI~//~v6b9R~
UTRACEP("mapmodify oldsbcsid=%04x for ucs=%04x\n",/*oldsbcsid*/pud->UCS2DDsbcsid,ii);   //~v67ZI~//~v6b9R~
UTRACED("mapmodify old pud",pud,UCS2DDMAPSZ);                      //~v67ZI~
        if (Pdatatype==1)	//new sbcs                             //~v67ZI~
        {                                                          //~v67ZI~
         	pud->UCS2DDsbcsid=UCSDDID_STARTUCS;                    //~v67ZR~
        }                                                          //~v67ZI~
        else                                                       //~v67ZI~
        if (Pdatatype==0)	//width=0 SBCS                         //~v67ZI~
        {                                                          //~v67ZI~
#ifdef WWW                                                         //~v6BYI~
        	pud->UCS2DDsbcsid=UCSDDID_STARTWIDTH0;                 //~v67ZI~
#else                                                              //~v6BYI~
			UTRACEP("%s:oldsbcsid=%04x,top=%04x\n",UTT,pud->UCS2DDsbcsid,Gudbcschk_width0top);//~v6BYI~
			if (pud->UCS2DDsbcsid>=Gudbcschk_width0top)	//already width0//~v6BYR~
            	continue;                                          //~v6BYI~
        	pud->UCS2DDsbcsid|=UCSDDID_WIDTH0_MODIFY;    //temp id for utfucsmapinit_remap//~v6BYR~
#endif                                                             //~v6BYI~
        }                                                          //~v67ZI~
        else                                                       //~v67ZI~
        {                                                          //~v67ZI~
	        if (Pdatatype==2)	//new dbcs                         //~v67ZI~
            	pud->UCS2DDsbcsid=UCSDDID_DBCS;  //change to dbcs  //~v67ZI~
            else                                                   //~v67ZI~
            	pud->UCS2DDsbcsid=UCSDDID_UNP;   //change to unprintable//~v67ZI~
        }                                                          //~v67ZI~
UTRACED("mapmodify new pud",pud,UCS2DDMAPSZ);                      //~v67ZI~
    }                                                              //~v67ZI~
    UTRACED("mapmodify u2i",Gucs2ddmap,sizeof(Gucs2ddmap));            //~v67ZI~//~v6BZR~
    return 0;                                                      //~v67ZI~
}//utfucsmapmodify                                                 //~v67ZI~
//#endif                                                             //~v67ZI~//~v6uBR~
//*******************************************************          //~v640I~
//*map unicode to sbcsid                                           //~v640I~
//*rc:0:sbcs,1:dbcs,4:unprintable                                  //~v640I~
//*******************************************************          //~v640I~
int utfmapucs2dd(int Popt,ULONG Pucs,WUCS *Ppsbcsid)               //~v640I~
{                                                                  //~v640I~
    PUCS2DDMAP pud;                                                //~v640I~
    WUCS sbcsid;                                                   //~v640I~
    int rc=0;                                                      //~v640I~
//*********************                                            //~v640I~
    *Ppsbcsid=(WUCS)Pucs; //output anyway for err case             //~v640I~
	if (Pucs>=UCS2DDMAP_ENTNO)                                     //~v640I~
    	rc=8;                                                      //~v640I~
    else                                                           //~v640I~
    {                                                              //~v640I~
    	pud=Gucs2ddmap+(int)Pucs;                                  //~v640R~
        sbcsid=pud->UCS2DDsbcsid;                                  //~v640I~
        if (sbcsid==2)                                             //~v640I~
        {                                                          //~v640I~
            rc=2;                                                  //~v640I~
        }                                                          //~v640I~
        else                                                       //~v640I~
        if (sbcsid<UCSDDID_STARTUCS)	//err                      //~v640R~
        	rc=4;                                                  //~v640I~
        else                                                       //~v640I~
        	*Ppsbcsid=sbcsid;                                      //~v640I~
    }                                                              //~v640I~
    UTRACEP("map u2dd rc=%d,ucs=%08x,sbcsid=%04x\n",rc,Pucs,*Ppsbcsid);//~v640I~
	return rc;                                                     //~v640I~
}//utfmapucs2dd                                                    //~v640R~
//*******************************************************          //~v640I~
//*map sbcsid to unicode                                           //~v640I~
//*rc:0:sbcs,1:dbcs                                                //~v640I~
//*******************************************************          //~v640I~
int utfmapdd2ucs(int Popt,ULONG Psbcsid,ULONG *Ppucs)              //~v640R~
{                                                                  //~v640I~
//#ifdef UTF8UCS4                                                    //~v65cI~//~v67ZR~
//#else                                                              //~v65cI~//~v67ZR~
//    PUCS2DDMAP pud;                                                //~v640I~//~v67ZR~
//#endif                                                             //~v65cI~//~v67ZR~
    WUCS ucs;                                                      //~v640I~
    int rc=0;                                                      //~v640I~
//*********************                                            //~v640I~
	if (Psbcsid>=UCS2DDMAP_ENTNO)                                  //~v640I~
    	rc=8;                                                      //~v640I~
    else                                                           //~v640I~
    {                                                              //~v640I~
//#ifdef UTF8UCS4                                                    //~v65cI~//~v67ZR~
        ucs=Gucs2ddmap_i2u[Psbcsid];	//reverse map              //~v65cI~
//#else                                                              //~v65cI~//~v67ZR~
//        pud=Gucs2ddmap+(int)Psbcsid;                               //~v640R~//~v67ZR~
//        ucs=pud->UCS2DDucs;                                        //~v640I~//~v67ZR~
//#endif                                                             //~v65cI~//~v67ZR~
        if (!ucs)	//not sbcs                                     //~v640I~
        	rc=4;                                                  //~v640I~
        else                                                       //~v640I~
        	*Ppucs=(ULONG)ucs;                                     //~v640I~
    }                                                              //~v640I~
    UTRACEP("%s:rc=%d,sbcsid=%04x,ucs=%08x\n",UTT,rc,Psbcsid,*Ppucs);//~v640I~//~v6DhR~
	return rc;                                                     //~v640I~
}//utfmapdd2ucs                                                    //~v640R~
//*******************************************************          //~v640I~
//*set dd from sbcs ucs                                            //~v640I~
//*rc:0:ascii,1:sbcs,4:err                                         //~v640I~
//*******************************************************          //~v640I~
int utfddsetsbcs(int Popt,ULONG Pucs,UCHAR *Ppdata,UCHAR *Ppdbcs)  //~v640R~
{                                                                  //~v640I~
	int rc=0,rc2;                                                  //~v640I~
	WUCS sbcsid;                                                   //~v640I~
//*********************                                            //~v640I~
	if (Pucs<0x80) /*ascii*/                                       //~v640R~
    {                                                              //~v640I~
		*Ppdbcs=0;                                                 //~v640I~
		*Ppdata=(UCHAR)Pucs;                                       //~v640I~
	}                                                              //~v640I~
    else                                                           //~v640I~
    {                                                              //~v640I~
		rc2=utfmapucs2dd(0,Pucs,&sbcsid);                          //~v640R~
        if (!rc2)	//sbcs                                         //~v640I~
        {                                                          //~v640I~
			*Ppdbcs=(UCHAR)((sbcsid>>8)|UDBCSCHK_SBCSUCSID);       //~v640I~
			*Ppdata=(UCHAR)(sbcsid & 0xff);                        //~v640I~
            rc=1;                                                  //~v640I~
        }                                                          //~v640I~
        else                                                       //~v640I~
        	rc=4;                                                  //~v640I~
    }                                                              //~v640I~
    return rc;                                                     //~v640I~
}//utfddsetsbcs                                                    //~v640I~
//*******************************************************          //~v640I~
//*get sbcs unicode from dd                                        //~v640I~
//*rc:0:ascii,1:sbcs,4:err                                         //~v640I~
//*******************************************************          //~v640I~
ULONG utfddgetsbcs(int Popt,UCHAR *Ppdata,UCHAR *Ppdbcs)           //~v640I~
{                                                                  //~v640I~
	WUCS sbcsid;                                                   //~v640I~
    ULONG ucs=0;                                                   //~v6hrR~
//*********************                                            //~v640I~
    sbcsid=(WUCS)((UTF_GETUCSSBCS_HIGH(Ppdbcs)<<8)|*Ppdata);       //~v640R~
//  utfmapdd2ucs(0,sbcsid,&ucs);                                   //~v640I~//~v6B4R~
    utfmapdd2ucs(0,(ULONG)sbcsid,&ucs);                            //~v6B4I~
    return ucs;                                                    //~v640I~
}//utfddgetsbcs                                                    //~v640I~
//*******************************************************          //~v640M~
//*get ucs2 and width from utf8                                    //~v640R~
//*!!! Ppwidth:set 1 for width0, it is used as loop ctl            //~v6VpI~
//*******************************************************          //~v640M~
int utfgetwcw(int Popt,UCHAR *Pdata,int Plen,ULONG *Ppucs,int *Ppchklen,int *Ppwidth)//~v640I~
{                                                                  //~v640M~
//	int rc=0,width,opt=0,flag,sbcsid,chklen=0;                     //~v6h4R~
  	int rc=0,width=0,opt=0,flag,sbcsid,chklen=0;                   //~v6h4I~
    ULONG wc;                                                      //~v640I~
//**************************************                           //~v640M~
	if (Popt & UTFGWCWO_INPUTUCS)    //input is not utf but ucs    //~v640I~
    	wc=*Ppucs;                                                 //~v640I~
    else                                                           //~v640I~
		rc=utfgetwc(Pdata,Plen,&wc,&chklen);                       //~v640R~
	if (!rc)                                                       //~v640I~
    {                                                              //~v640M~
	    if (Ppwidth)                                               //~v640M~
    	{                                                          //~v640M~
//#ifdef W32UNICODE                                                  //~v6ueI~//~v6uBR~
//         if (IS_UTF16(wc))                                         //~v6ueI~//~v6uBR~
//         {                                                         //~v6ueI~//~v6uBR~
//            width=0;    //narrow dbcs                              //~v6ueI~//~v6uBR~
//         }                                                         //~v6ueI~//~v6uBR~
//         else                                                      //~v6ueI~//~v6uBR~
//#endif                                                             //~v6ueI~//~v6uBR~
         {                                                         //~v6ueI~
    		opt|=UTFWWO_UTF8UCS2;                                  //~v640R~
    		width=utfwcwidth(opt,wc,&flag);                        //~v640R~
            if (!width)                                            //~v6VpI~
				width=1;	//utfcvu2dd1w generate bscs dddata/dddbcs, other use width as loop ctl//~v6VpI~
	      if (Popt & UTFGWCWO_GETSBCSID)    //input is not utf but ucs//~v640I~
          {                                                        //~v640I~
    		if (utfddflag2sbcsid(0,flag,width,&sbcsid))	//flag was set//~v640I~
            	width=-sbcsid;                                     //~v640I~
          }                                                        //~v640I~
         }//!surrogate                                             //~v6ueI~
        	*Ppwidth=width;                                        //~v640M~
    	}                                                          //~v640M~
    }                                                              //~v640M~
    *Ppucs=wc;                                                     //~v640I~
    if (Ppchklen)                                                  //~v640I~
        *Ppchklen=chklen;                                          //~v640I~
//  UTRACEDIFNZ("utfgetwc2 inpdata",Pdata,chklen);                 //~v740R~
#ifdef LNX                                                         //~v640M~
//  UTRACEP("%s: rc=%d,inplen=%d,chklen=%d,width=%d,apiwidth=%d,ucs=%x\n",UTT,rc,Plen,chklen,width,wcwidth((wchar_t)wc),wc);//~v640R~//~v6ueR~//~v740R~
#else                                                              //~v640M~
//  UTRACEP("%s: inpucs=%x,rc=%d,inplen=%d,chklen=%d,width=%d,ucs=%x\n",UTT,*Ppucs,rc,Plen,chklen,width,wc);//~v640R~//~v6ueR~//~v740R~
#endif                                                             //~v640M~
	return rc;                                                     //~v640M~
}//utfgetwcw                                                       //~v640I~
#ifdef W32UNICODE                                                  //~v6ueI~
//*******************************************************          //~v6ueI~
//*Win:ucs4 to dd                                                  //~v6uBI~
//*as overflow                                                     //~v6uBI~
//*******************************************************          //~v6ueI~
#ifdef UTF8UTF16                                                   //~v6uBI~
int utfcvu2dd1wSurrogate(int Popt,ULONG Pucs4,char *Pdddata,char *Pdddbcs,int *Ppoutlen)//~v6uBI~
{                                                                  //~v6uBI~
    int rc;                                                        //~v6uBI~
    char *pco,*pcdo;                                               //~v6uBI~
    ULONG ucs1,ucs11,ucs12;                                        //~v6uBI~
//*******************************                                  //~v6uBI~
    UTRACEP("%s:Pucs=%x\n",UTT,Pucs4);                             //~v6uBI~
    pco=Pdddata,pcdo=Pdddbcs;                                      //~v6uBI~
    ucs1=Pucs4>>16;             //hh of 0x00hhmmll                 //~v6uBI~
    ucs11=ucs1>>3;            //pq of 000p.qrrr(mask:0x1f)         //~v6uBI~
    ucs12=ucs1 & 0x07;        //rrr                                //~v6uBI~
    *pco++=(UCHAR)((Pucs4>>8) & 0xff); //mm                        //~v6uBI~
    *pco=(UCHAR)(Pucs4 & 0xff);        //ll                        //~v6uBI~
//  *pcdo++=UDBCSCHK_UCS41|ucs11;                                  //~v6x8R~
    *pcdo++=(CHAR)(UDBCSCHK_UCS41|ucs11);                          //~v6x8I~
//  *pcdo=UDBCSCHK_UCS42|ucs12;                                    //~v6x8R~
    *pcdo=(UCHAR)(UDBCSCHK_UCS42|ucs12);                           //~v6x8I~
    if (Ppoutlen)                                                  //~v6uBI~
    	*Ppoutlen=2;                                               //~v6uBI~
    UTRACED("outdddata",Pdddata,2);                                //~v6uBI~
    UTRACED("outdddbcs",Pdddbcs,2);                                //~v6uBI~
	rc=UTFCVFDRC_DBCS|UTFCVFDRC_UTF8;   //valid utf8 char          //~v6uBI~
    return rc;                                                     //~v6uBR~
}//utfcvu2dd1wSurrogate                                            //~v6uBI~
#else                                                              //~v6uBI~
int utfcvu2dd1wSurrogate(int Popt,WUCS Pucs2,char *Pdddata,char *Pdddbcs//~v6ueI~
)                                                                  //~v6ueI~
{                                                                  //~v6ueI~
    int rc;                                                        //~v6ueI~
    char *pco,*pcdo;                                               //~v6ueI~
//*******************************                                  //~v6ueI~
    UTRACEP("%s:Pucs=%x\n",UTT,Pucs2);                             //~v6ueR~
    pco=Pdddata;                                                   //~v6ueI~
    pcdo=Pdddbcs;                                                  //~v6ueI~
    *pco++=(UCHAR)(Pucs2>>8);                                      //~v6ueR~
    *pco++=(UCHAR)(Pucs2&0xff);   //big endian ucs                 //~v6ueR~
	rc=UTFCVFDRC_DBCS|UTFCVFDRC_UTF8;   //valid utf8 char          //~v6ueI~
    *pcdo++=UDBCSCHK_NDBCSUCS1;    //narrow dbcs upper             //~v6ueI~
    *pcdo=UDBCSCHK_NDBCSUCS2;    //narrow dbcs lower               //~v6ueI~
    UTRACED("outdddata",Pdddata,2);                                //~v6ueI~
    UTRACED("outdddbcs",Pdddbcs,2);                                //~v6ueI~
    return rc;                                                     //~v6ueI~
}//utfcvu2dd1wSurrogate                                            //~v6VfR~
#endif                                                             //~v6uBI~
//*******************************************************          //~v6ueI~
//*convert ucs4(16H-16L fmt) to ddfmt                              //~v6ueR~
//*must prepare 4 byte output                                      //~v6ueI~
//*******************************************************          //~v6ueI~
//int utfcvu2dd1wUCS4(int Popt,ULONG Pulucs,UCHAR *Ppoutdata,UCHAR *Ppoutdbcs,int Pbuffsz,int *Ppoutlen)//~v6ueR~//~v6uBR~
int utfcvu2dd1wUCS4(int Popt,ULONG Pulucs,UCHAR *Ppoutdata,UCHAR *Ppoutdbcs,int *Ppoutlen)//~v6uBI~
{                                                                  //~v6ueI~
    int rc;                                                        //~v6ueR~
//  WUCS wkwucs[2];                                                //~v6ueI~//~v6uBR~
//****************************                                     //~v6ueI~
#ifdef UTF8UTF16                                                   //~v6uBI~
    if (UTF_ISUCS4(Pulucs))                                        //~v6uBR~
		rc=utfcvu2dd1wSurrogate(Popt,Pulucs,Ppoutdata,Ppoutdbcs,Ppoutlen);//~v6uBR~
    else                                                           //~v6uBI~
		rc=utfcvu2dd1(Popt,(WUCS)Pulucs,Ppoutdata,Ppoutdbcs,Ppoutlen);//~v6uBI~
#else                                                              //~v6uBI~
	if (Pbuffsz<4)                                                 //~v6ueI~
    	return UTFCVFDRC_OVF;                                      //~v6ueI~
//  UCS4_TO_UTF16(Pulucs,wkwucs,&wrtlen);                          //~v6ueR~
	wkwucs[0]=Pulucs>>16;                                          //~v6ueI~
	wkwucs[1]=Pulucs & 0xffff;                                     //~v6ueI~
	rc=utfcvu2dd1wSurrogate(Popt,wkwucs[0],Ppoutdata,Ppoutdbcs);   //~v6ueR~
	rc|=utfcvu2dd1wSurrogate(Popt,wkwucs[1],Ppoutdata+2,Ppoutdbcs+2);//~v6ueR~
    if (Ppoutlen)                                                  //~v6ueI~
	    *Ppoutlen=4;                                               //~v6ueI~
#endif                                                             //~v6uBI~
    return rc;                                                     //~v6ueI~
}//utfcvu2dd1wUCS4                                                 //~v6ueI~
#endif                                                             //~v6ueI~
//*******************************************************          //~v640I~
//*convert ucs/dbcsid to dd fmt                                    //~v640I~
//*******************************************************          //~v640I~
int utfcvu2dd1w(int Popt,WUCS Pucs,int Pdbcsid,UCHAR *Ppoutdata,UCHAR *Ppoutdbcs)//~v640I~
{                                                                  //~v640I~
    ULONG ucs;                                                     //~v640I~
    int rc=0;                                                      //~v640R~
    UCHAR *pco,*pcdo;                                              //~v640R~
//#ifdef UTF8UCS4                                                    //~v65cI~//~v6uBR~
#ifdef UTF8UCS416                                                  //~v6uBI~
    ULONG ucs1,ucs11,ucs12;                                        //~v65cI~
#endif                                                             //~v65cI~
//****************************                                     //~v640I~
//  ucs=Pucs;                                                      //~v640I~//~v6B4R~
    ucs=(ULONG)Pucs;                                               //~v6B4I~
	pco=Ppoutdata;                                                 //~v640I~
    pcdo=Ppoutdbcs;                                                //~v640R~
    if (ucs<0x80)                                                  //~v640R~
    {                                                              //~v640I~
    	*pco=(UCHAR)ucs;                                           //~v640I~
        *pcdo=0;                                                   //~v640I~
    }                                                              //~v640I~
//#ifdef W32UNICODE                                                  //~v6ueI~//~v6uBR~
//    else                                                           //~v6ueI~//~v6uBR~
//    if (Gulibutfmode & GULIBUTF_WINSURROGATE    //always support surrogate pair//~v6ueI~//~v6uBR~
//    &&  IS_UTF16(Pucs))    //surrogate high or low                 //~v6ueI~//~v6uBR~
//    {                                                              //~v6ueI~//~v6uBR~
//        rc=utfcvu2dd1wSurrogate(Popt,Pucs,Ppoutdata,Ppoutdbcs);    //~v6ueI~//~v6uBR~
//    }                                                              //~v6ueI~//~v6uBR~
//#endif                                                             //~v6ueI~//~v6uBR~
    else                                                           //~v640I~
    {                                                              //~v640I~
#ifdef LNX                                                         //~v6V4I~
//      if (ucs>=UCS2DDMAP_ENTNO) //0x020000                       //~v6V4I~//~v6VeR~
        if (ucs>=UCS4_START) //UCS41+UCS42 for 0x010000            //~v6VeI~
        {                                                          //~v6V4I~
		  if (ucs<UCS2DDMAP_ENTNO //0x020000<-0x010000             //~v6VyI~
          &&  Pdbcsid==1    //keep sbcsid on pdbcs                 //~v6VyI~
          )                                                        //~v6VyI~
          	;                                                      //~v6VyI~
          else                                                     //~v6VyI~
          {                                                        //~v6VyI~
//        	if (Pdbcsid==2)	//dbcs                                 //~v6V4I~//~v6VeR~
//        		Pdbcsid=-UCSDDID_OVERFLOW;	//ucs4>=0x20000 or sbcid overflow//~v6V4I~//~v6VeR~
//          else                                                   //~v6V4I~//~v6VeR~
        	if (Pdbcsid==0)	//width0                               //~v6V4I~
				Pdbcsid=-UCSDDID_OVERFLOWW0;	//ucs4>=0x20000 or sbcid overflow//~v6V4I~
            else                                                   //~v6VeI~
        		Pdbcsid=-UCSDDID_OVERFLOW;	//even for unprintable //~v6VeI~
          }                                                        //~v6VyI~
        }                                                          //~v6V4I~
#endif                                                             //~v6V4I~
        switch(Pdbcsid)                                            //~v640I~
        {                                                          //~v640I~
        case 1: //sbcs                                             //~v640I~
            UTF_UCS2DDSBCS(ucs,pco,pcdo);                          //~v640I~
            rc=UTFCVFDRC_UTF8;   //valid utf8 char                 //~v640I~
            break;                                                 //~v640I~
        case 2: //dbcs                                             //~v640I~
            *pco++=(UCHAR)(ucs>>8);                                //~v640I~
            *pco=(UCHAR)(ucs&0xff);   //big endian ucs             //~v640R~
#ifdef W32                                                         //~v6E0I~
          if (Popt & U162DO_CHKDBCSPRINT   //   0x01    //chk iswprint for dbcs//~v6E0I~
          &&  !iswprint((wint_t)ucs))                              //~v6E0R~
          {                                                        //~v6E0I~
          	UTRACEP("%s:ucs(x%04x) is unprintable dbcs\n",UTT,ucs);//~v6E0I~
            *pcdo++=UDBCSCHK_NPUCS1;    //non printable but back to file//~v6E0I~
            *pcdo=UDBCSCHK_NPUCS2;                                 //~v6E0I~
	        rc=UTFCVFDRC_DBCS|UTFCVFDRC_UTF8;   //valid utf8 char  //~v6E0I~
	        rc|=UTFCVFDRC_UTF8UNP;                                 //~v6E0I~
          }                                                        //~v6E0I~
          else                                                     //~v6E0I~
#endif                                                             //~v6E0I~
          {                                                        //~v6E0I~
            *pcdo++=UDBCSCHK_DBCS1STUCS;                           //~v640R~
            *pcdo=UDBCSCHK_DBCS2NDUCS;                             //~v640I~
            rc=UTFCVFDRC_DBCS|UTFCVFDRC_UTF8;   //valid utf8 char  //~v640I~
          }                                                        //~v6E0I~
            break;                                                 //~v640I~
//#ifdef UTF8UCS4                                                    //~v65cM~//~v6uBR~
#ifdef UTF8UCS416                                                  //~v6uBI~
        case -UCSDDID_OVERFLOW:	//ucs4>=0x20000 or sbcid overflow  //~v65cI~
        case -UCSDDID_OVERFLOWW0:	//ucs4>=0x20000 or sbcid overflow//~v67ZI~
            ucs1=ucs>>16;             //hh of 0x00hhmmll           //~v65cI~
            ucs11=ucs1>>3;            //pq of 000p.qrrr(mask:0x1f) //~v65cI~
            ucs12=ucs1 & 0x07;        //rrr                        //~v65cI~
            *pco++=(UCHAR)((ucs>>8) & 0xff); //mm                  //~v65cI~
            *pco=(UCHAR)(ucs & 0xff);        //ll                  //~v65cI~
//          *pcdo++=UDBCSCHK_UCS41|ucs11;                          //~v6x8R~
            *pcdo++=(UCHAR)(UDBCSCHK_UCS41|ucs11);                 //~v6x8I~
//          *pcdo=UDBCSCHK_UCS42|ucs12;                            //~v6x8R~
            *pcdo=(UCHAR)(UDBCSCHK_UCS42|ucs12);                   //~v6x8I~
	        rc=UTFCVFDRC_DBCS|UTFCVFDRC_UTF8;   //valid utf8 char  //~v65cI~
            break;                                                 //~v65cI~
#endif                                                             //~v65cM~
        default:                                                   //~v640I~
            *pco++=(UCHAR)(ucs>>8);                                //~v640I~
            *pco++=(UCHAR)(ucs&0xff);   //big endian ucs           //~v640I~
	        rc=UTFCVFDRC_DBCS|UTFCVFDRC_UTF8;   //valid utf8 char  //~v640I~
            if (Pdbcsid==-UCSDDID_WIDESBCS) //wide char but wcwidth=1//~v640I~
            {                                                      //~v640I~
                *pcdo++=UDBCSCHK_WSBCSUCS1;    //narrow dbcs upper //~v640R~
                *pcdo=UDBCSCHK_WSBCSUCS2;    //narrow dbcs lower   //~v640I~
            }                                                      //~v640I~
            else                                                   //~v640I~
            if (Pdbcsid==-UCSDDID_NARROWDBCS)   //sbcs of wcwidth=2//~v640I~
            {                                                      //~v640I~
                *pcdo++=UDBCSCHK_NDBCSUCS1;    //narrow dbcs upper //~v640R~
                *pcdo=UDBCSCHK_NDBCSUCS2;    //narrow dbcs lower   //~v640I~
            }                                                      //~v640I~
            else                                                   //~v640I~
            {                                                      //~v640I~
                *pcdo++=UDBCSCHK_NPUCS1;    //non printable but back to file//~v640R~
                *pcdo=UDBCSCHK_NPUCS2;                             //~v640I~
	            rc|=UTFCVFDRC_UTF8UNP;                             //~v640I~
            }                                                      //~v640I~
        }                                                          //~v640I~
    }                                                              //~v640I~
	return rc;                                                     //~v640I~
}//utfcvu2dd1w                                                     //~v640R~
//*******************************************************          //~v640I~
//*convert utf8string to ucs string DD fmt                         //~v640I~
//*set UDBCSCHK_DBCS1STUCS,2NDUCS,NPUCS1,NPUCS2,HKDBCSERR,SBCSUCSID(0x80)//~v640I~
//*rc:0:ascii,else ucsid                                           //~v640R~
//*******************************************************          //~v640I~
int utfcvu2dd1(int Popt,WUCS Pucs,UCHAR *Ppoutdata,UCHAR *Ppoutdbcs,int *Ppoutlen)//~v640R~
{                                                                  //~v640I~
    ULONG ucs;                                                     //~v640I~
    int opt,charwidth,rc=0,outlen=1;                               //~v640R~
    UCHAR *pc="";                                                  //~v640R~
//****************************                                     //~v640I~
    ucs=(ULONG)Pucs;                                               //~v640I~
    if (ucs<0x80)                                                  //~v640R~
    {                                                              //~v640I~
    	*Ppoutdata=(UCHAR)ucs;                                     //~v640R~
        *Ppoutdbcs=0;                                              //~v640R~
    }                                                              //~v640I~
    else                                                           //~v640I~
    {                                                              //~v640I~
		opt=UTFGWCWO_INPUTUCS|UTFGWCWO_GETSBCSID;    //input is not utf but ucs//~v640R~
    	utfgetwcw(opt,pc,0/*len*/,&ucs,0/*chklen*/,&charwidth);//get width//~v640R~
		rc=utfcvu2dd1w(0,(WUCS)ucs,charwidth,Ppoutdata,Ppoutdbcs); //~v640R~
        if (rc & UTFCVFDRC_DBCS)                                   //~v640I~
        	outlen=2;                                              //~v640I~
    }                                                              //~v640I~
    if (Ppoutlen)                                                  //~v640I~
	    *Ppoutlen=outlen;                                          //~v640I~
UTRACEP("utfcvu2dd1 rc=%d,ucs=%x out data=%x,dbcs=%x,outtlen=%d\n",rc,Pucs,*Ppoutdata,*Ppoutdbcs,outlen);//~v640R~//~v667R~
    return rc;                                                     //~v640I~
}//utfcvu2dd1                                                      //~v640R~
//*******************************************************          //~v640I~
//*convert utf8string to ucs string DD fmt                         //~v640I~
//*set UDBCSCHK_DBCS1STUCS,2NDUCS,NPUCS1,NPUCS2,HKDBCSERR,SBCSUCSID(0x80)//~v640I~
//*rc:buff overflow,dbcs,utf8,errutf8                              //~v640R~
//*******************************************************          //~v640I~
int utfcvf2dd(int Popt,UCHAR *Ppdata,int Plen,UCHAR *Ppoutdata,UCHAR *Ppoutdbcs,int Poutbuffsz,int *Ppoutlen)//~v640I~
{                                                                  //~v640I~
    ULONG ucs;                                                     //~v640I~
    int chklen,charwidth,rc=0,reslen,outreslen,outlen,opt;         //~v640R~
    UCHAR *pc,*pco,*pcdo;                                          //~v640I~
    UCHAR wcdbcs[2],wcdata[2];                                     //~v640R~
    int rc2;                                                       //~v6VfI~
//****************************                                     //~v640I~
UTRACED("utfcvf2dd input   ",Ppdata,Plen);                         //~v640I~
    pco=Ppoutdata;                                                 //~v640I~
    pcdo=Ppoutdbcs;                                                //~v640I~
    pc=Ppdata;                                                     //~v640I~
    opt=UTFGWCWO_GETSBCSID;    //input is not utf but ucs          //~v640R~
    for (reslen=Plen,outreslen=Poutbuffsz;reslen>0 && outreslen>0;pc+=chklen,reslen-=chklen,outreslen--)//~v640R~
    {                                                              //~v640I~
        if (UTF8ISASCII(*pc))                                      //~v640R~
        {                                                          //~v640I~
          if (*pc==UDBCSCHK_TABCHAR && Popt & UTFCVO_SETTABCHAR)   //~v69zI~
          {                                                        //~v69zI~
        	*pco++=' ';                                            //~v69zI~
            *pcdo++=UDBCSCHK_TABCHAR;                              //~v69zI~
          }                                                        //~v69zI~
          else                                                     //~v69zI~
          {                                                        //~v69zI~
        	*pco++=*pc;                                            //~v640I~
            *pcdo++=0;                                             //~v640I~
          }                                                        //~v69zI~
            chklen=1;                                              //~v640I~
            continue;                                              //~v640I~
        }                                                          //~v640I~
        if (utfgetwcw(opt,pc,reslen,&ucs,&chklen,&charwidth))//get ucs2 and width//~v640R~
        {                                                          //~v640I~
            *pco++=*pc;                                            //~v640I~
            *pcdo++=UDBCSCHK_F2LERR;                               //~v640R~
            chklen=1;                                              //~v640I~
            rc|=UTFCVFDRC_UTF8ERR;   //invalid utf8 char           //~v640I~
        }                                                          //~v640I~
        else                                                       //~v640I~
        {                                                          //~v640I~
//#ifdef W32UNICODE                                                  //~v6ueI~//~v6uBR~
#ifdef UTF8UTF16                                                   //~v6uBI~
		  if (ucs>UTF_UCS2MAX)                                     //~v6ueR~
          {                                                        //~v6ueI~
//  		rc|=utfcvu2dd1wUCS4(0,ucs,pco,pcdo,outreslen,&charwidth);//~v6ueR~//~v6uBR~
			rc|=utfcvu2dd1wUCS4(0,ucs,pco,pcdo,&charwidth);        //~v6uBI~
			if (rc & UTFCVFDRC_OVF)                                //~v6ueI~
            	break;                                             //~v6ueI~
            outreslen-=charwidth-1;//out ddlen                     //~v6ueR~
            pco+=charwidth;                                        //~v6ueI~
            pcdo+=charwidth;                                       //~v6ueI~
          }                                                        //~v6ueI~
          else                                                     //~v6ueI~
#endif                                                             //~v6ueI~
		  {	                                                       //~v6ueI~
//			rc|=utfcvu2dd1w(0,(WUCS)ucs,charwidth,wcdata,wcdbcs);  //~v640I~//~v6VfR~
  			rc2=utfcvu2dd1w(0,(WUCS)ucs,charwidth,wcdata,wcdbcs);  //~v6VfI~
			rc|=rc2;                                               //~v6VfI~
//*under the condition of UCS2 range                               //~v6uBI~
            *pco++=wcdata[0];                                      //~v640I~
            *pcdo++=wcdbcs[0];                                     //~v640I~
//        	if (charwidth!=1)	//not sbcs                         //~v640R~//~v6VfR~
            if (rc2 & UTFCVFDRC_DBCS)                              //~v6VfI~
            {                                                      //~v640I~
            	if (outreslen<=1)                                  //~v640I~
                    break;                                         //~v640I~
	            outreslen--;                                       //~v640I~
            	*pco++=wcdata[1];	//big endian ucs               //~v640R~
                *pcdo++=wcdbcs[1];                                 //~v640R~
            }                                                      //~v640I~
          }                                                        //~v6ueI~
        }                                                          //~v640I~
    }                                                              //~v640I~
    if (reslen)                                                    //~v640I~
		rc|=UTFCVFDRC_OVF;   //buffser overflow                    //~v640I~
//  outlen=(int)((ULONG)pco-(ULONG)Ppoutdata);                     //~v640R~//~v6hhR~
    outlen=(int)((ULPTR)pco-(ULPTR)Ppoutdata);                     //~v6hhI~
    if (Ppoutlen)                                                  //~v640I~
    {                                                              //~v6b9I~
  	  if (Popt & UTFCVO_OUTWIDTH && rc & UTFCVFDRC_OVF)            //~v6btR~
	    *Ppoutlen=Plen-reslen;                                     //~v6btR~
      else                                                         //~v6btR~
	    *Ppoutlen=outlen;                                          //~v640R~
    }                                                              //~v6b9I~
//UTRACED("utfcvf2dd out data",Ppoutdata,outlen);                  //~v740R~
//UTRACED("utfcvf2dd out dbcs",Ppoutdbcs,outlen);                  //~v740R~
    return rc;                                                     //~v640I~
}//utfcvf2dd                                                       //~v640I~
//*******************************************************          //~v6Y0I~
//*UINT4 ucs2dd                                                    //~v6Y0I~
//*******************************************************          //~v6Y0I~
int utfcvu2dd1UWUCS(int Popt,UWUCS Pucs,UCHAR *Ppdddata,UCHAR *Ppdddbcs,int *Ppoutlen)//~v6Y0I~
{                                                                  //~v6Y0I~
	int charwidth,rc;                                              //~v6Y0R~
//*********************                                            //~v6Y0I~
#ifdef UTF8UTF16	//W32                                          //~v6Y0R~
	if (Pucs>UTF_UCS2MAX)                                          //~v6Y0I~
		rc=utfcvu2dd1wUCS4(0,(ULONG)Pucs,Ppdddata,Ppdddbcs,&charwidth);//~v6Y0I~
    else                                                           //~v6Y0I~
#endif                                                             //~v6Y0I~
		rc=utfcvu2dd1(Popt,(WUCS)Pucs,Ppdddata,Ppdddbcs,&charwidth);//~v6Y0R~
    UTRACEP("%s:rc=%d,ucs=x%04x,outlen=%d\n",UTT,rc,Pucs,charwidth);//~v6Y0I~
    UTRACED("dddata",Ppdddata,charwidth);                          //~v6Y0I~
    UTRACED("dddbcs",Ppdddbcs,charwidth);                          //~v6Y0I~
    *Ppoutlen=charwidth;                                           //~v6Y0I~
    return rc;                                                     //~v6Y0I~
}//utfcvu2dd1UWUCS                                                 //~v6Y0I~
//*******************************************************          //~v6Y0I~
//*convert ucs(UINT4) string to  DD fmt                            //~v6Y0I~
//*rc:buff overflow,dbcs,unp,utf8                                  //~v6Y0I~
//*******************************************************          //~v6Y0I~
int utfcvu2dd(int Popt,UWUCS/*UINT4*/*Ppucs,int Pucsctr,UCHAR *Ppoutdata,UCHAR *Ppoutdbcs,int Poutbuffsz,int *Ppoutlen)//~v6Y0I~
{                                                                  //~v6Y0I~
    UWUCS ucs,*pucs;                                               //~v6Y0R~
    int ii,rc=0,reslen,outlen,ddlen;                               //~v6Y0R~
    UCHAR *pco,*pcdo;                                              //~v6Y0R~
    UCHAR wcdbcs[2],wcdata[2];                                     //~v6Y0I~
//****************************                                     //~v6Y0I~
UTRACED("input   ",Ppucs,Pucsctr*(int)sizeof(UWUCS));              //~v6Y0I~
    pco=Ppoutdata;                                                 //~v6Y0I~
    pcdo=Ppoutdbcs;                                                //~v6Y0I~
    for (pucs=Ppucs,ii=0,reslen=Poutbuffsz;ii<Pucsctr;ii++,pucs++) //~v6Y0I~
    {                                                              //~v6Y0I~
    	ucs=*pucs;                                                 //~v6Y0I~
		rc|=utfcvu2dd1UWUCS(Popt,ucs,wcdata,wcdbcs,&ddlen);        //~v6Y0R~
        reslen-=ddlen;                                             //~v6Y0I~
        if (reslen<0)                                              //~v6Y0I~
        {	                                                       //~v6Y0I~
			rc|=UTFCVFDRC_OVF;   //buffser overflow                //~v6Y0I~
            break;                                                 //~v6Y0I~
        }                                                          //~v6Y0I~
        *pco++=wcdata[0];                                          //~v6Y0I~
        *pcdo++=wcdbcs[0];                                         //~v6Y0I~
        if (ddlen>1)                                               //~v6Y0I~
        {                                                          //~v6Y0I~
	        *pco++=wcdata[1];                                      //~v6Y0I~
    	    *pcdo++=wcdbcs[1];                                     //~v6Y0I~
        }                                                          //~v6Y0I~
    }                                                              //~v6Y0I~
    outlen=PTRDIFF(pco,Ppoutdata);                                 //~v6Y0I~
    if (Ppoutlen)                                                  //~v6Y0I~
	    *Ppoutlen=outlen;                                          //~v6Y0I~
UTRACEP("%S:rc=%d\n",UTT,rc);                                      //~v6Y0I~
UTRACED("out data",Ppoutdata,outlen);                              //~v6Y0I~
UTRACED("out dbcs",Ppoutdbcs,outlen);                              //~v6Y0I~
    return rc;                                                     //~v6Y0I~
}//utfcvu2dd                                                       //~v6Y0I~
//**************************************************               //~v640I~
//*get 1 ucs from data/dbcs DDucs format                           //~v640I~
//*re ucs                                                          //~v640I~
//**************************************************               //~v640I~
#ifdef UTF8UTF16                                                   //~v6uBI~
UWUCS utfdd2u1(int Popt,UCHAR *Ppdata,UCHAR *Ppdbcs,int Plen)      //~v6uBI~
#else                                                              //~v6uBI~
WUCS utfdd2u1(int Popt,UCHAR *Ppdata,UCHAR *Ppdbcs,int Plen)       //~v640R~
#endif                                                             //~v6uBI~
{                                                                  //~v640I~
#ifdef UTF8UTF16                                                   //~v6uBI~
	WUCS ucsutf16[2];   //for surrogate pair                       //~v6uBI~
    UWUCS uwucs;                                                   //~v6uBI~
    int ucsctr;                                                    //~v6uBI~
#else                                                              //~v6uBI~
	WUCS ucs;                                                      //~v640R~
#endif                                                             //~v6uBI~
//******************                                               //~v640I~
#ifdef UTF8UTF16                                                   //~v6uBI~
	utfdd2u(Popt|UTFDD2UO_UCS1,Ppdata,Ppdbcs,Plen,ucsutf16,sizeof(ucsutf16)/*Poutbuffsz*/,&ucsctr,0/*Ppucsdbcsctr*/,0/*Ppucssbcsctr*/);//~v6uBI~
    if (ucsctr==2)                                                 //~v6uBI~
    	uwucs=(UWUCS)UTF16_TO_UCS4(ucsutf16[0],ucsutf16[1]);       //~v6uBI~
    else                                                           //~v6uBI~
    	uwucs=(UWUCS)ucsutf16[0];                                  //~v6uBI~
    return uwucs;                                                  //~v6uBI~
#else                                                              //~v6uBI~
#ifdef UTF8UCS4                                                    //~v65cR~
	utfdd2u(Popt|UTFDD2UO_UCS1,Ppdata,Ppdbcs,Plen,&ucs,sizeof(ucs)/*Poutbuffsz*/,0/*Ppucsctr*/,0/*Ppucsdbcsctr*/,0/*Ppucssbcsctr*/);//~v65cI~
#else                                                              //~v65cI~
	utfdd2u(Popt|UTFDD2UO_UCS1,Ppdata,Ppdbcs,Plen,&ucs,2/*Poutbuffsz*/,0/*Ppucsctr*/,0/*Ppucsdbcsctr*/,0/*Ppucssbcsctr*/);//~v640R~
#endif                                                             //~v65cI~
    return ucs;                                                    //~v640I~
#endif                                                             //~v6uBI~
}//utfdd2u1                                                        //~v640I~
//**************************************************               //~v6VzR~
//*get 1 ucs from data/dbcs DD format for vio                      //~v6VzR~
// unprintable ucs is replaced already, return the repch           //~v6VzR~
// chsz: 1 or 2, if spliterr or ucsNP set 1                        //~v6VzR~
//**************************************************               //~v6VzR~
int utfdd2u1vio(int Popt,UCHAR *Ppdata,UCHAR *Ppdbcs,int Plen,int *Ppchsz)//~v6VzR~
{                                                                  //~v6VzR~
	int ucs,ucs2,dbcsid,chsz;                                      //~v6VzR~
//********************                                             //~v6VzR~
	ucs=*Ppdata;                                                   //~v6VzR~
    dbcsid=*Ppdbcs;                                                //~v6VzR~
    if ((ucs==UDBCSCHK_ERRREPCH_NPUCS && UDBCSCHK_ISUCSNP1ST(dbcsid))//~v6VzR~
    ||  (ucs==UDBCSCHK_ERRREPCH_NPUCSW && UDBCSCHK_ISUCSNP2ND(dbcsid))//~v6VzR~
    )                                                              //~v6VzR~
    	chsz=1;                                                    //~v6VzR~
    else                                                           //~v6VzR~
    {                                                              //~v6VzR~
		ucs2=(int)utfdd2u1chsz(Popt,Ppdata,Ppdbcs,Plen,&chsz);     //~v6VzR~
        if (chsz>0)                                                //~v6VzR~
        	ucs=ucs2;	                                           //~v6VzR~
        else                                                       //~v6VzR~
        	chsz=1;                                                //~v6VzR~
    }                                                              //~v6VzR~
    if (Ppchsz)                                                    //~v6VzR~
    	*Ppchsz=chsz;                                              //~v6VzR~
    return ucs;                                                    //~v6VzR~
}//utfdd2u1vio                                                     //~v6VzR~
#ifdef UTF8EBCD                                                    //~v660I~
//**************************************************               //~v65pI~
//*get 1 ucs from data/dbcs DDucs format(no errrep)                //~v65pI~
//*ret chsz:1,2,-1(data split)                                     //~v65pI~
//**************************************************               //~v65pI~
#ifdef UTF8UTF16                                                   //~v6uBI~
UWUCS/*ucs4*/ utfdd2u1chsz(int Popt,UCHAR *Ppdata,UCHAR *Ppdbcs,int Plen,int *Ppchsz)//~v6uBI~
#else                                                              //~v6uBI~
WUCS utfdd2u1chsz(int Popt,UCHAR *Ppdata,UCHAR *Ppdbcs,int Plen,int *Ppchsz)//~v65pI~
#endif                                                             //~v6uBI~
{                                                                  //~v65pI~
#ifdef UTF8UTF16                                                   //~v6uBI~
	UWUCS ucs;                                                     //~v6uBI~
#else                                                              //~v6uBI~
	WUCS ucs;                                                      //~v65pI~
#endif                                                             //~v6uBI~
    int chsz,dbcsid;                                               //~v660R~
//******************                                               //~v65pI~
    dbcsid=*Ppdbcs;                                                //~v660R~
    chsz=1;                                                        //~v65pI~
    ucs=*Ppdata;                                                   //~v66mI~
    if (UDBCSCHK_ISUCSSBCS(dbcsid))                                //~v65pI~
    	ucs=(WUCS)UTF_GETUCSSBCS(Ppdata,Ppdbcs);                   //~v660R~
    else                                                           //~v65pI~
    if (UDBCSCHK_DBCS1STUCS2NWP(dbcsid))                           //~v65pI~
    {                                                              //~v65pI~
        if (Plen==1)	//split by EOL                             //~v660R~
            chsz=-1;	//errid                                    //~v65pI~
        else                                                       //~v65pI~
        {                                                          //~v65pI~
        	ucs=UTF_GETUCSDBCS(Ppdata);                            //~v660R~
          if (UDBCSCHK_ISUCSNP1ST(dbcsid))  //unprintable          //~v66mI~
        	chsz=-2;    //unprintable id                           //~v66mI~
          else                                                     //~v66mI~
        	chsz=2;                                                //~v65pI~
        }                                                          //~v65pI~
    }                                                              //~v65pI~
    else                                                           //~v65pI~
//#ifdef UTF8UCS4                                                    //~v660I~//~v6uBR~
#ifdef UTF8UCS416                                                  //~v6uBI~
    if (UDBCSCHK_ISUCSOVF1ST(dbcsid))                              //~v65pI~
    {                                                              //~v65pI~
        if (Plen==1)	//split by EOL                             //~v660R~
            chsz=-1;	//errid                                    //~v65pI~
        else                                                       //~v65pI~
        {                                                          //~v65pI~
        	ucs=UTF_GETUCSDBCSOVF(Ppdata,Ppdbcs);                  //~v660R~
        	chsz=2;                                                //~v65pI~
        }                                                          //~v65pI~
    }                                                              //~v65pI~
    else                                                           //~v65pI~
#endif                                                             //~v660I~
    if (UDBCSCHK_DBCS2NDU(dbcsid))          //dbcs split at TOL or invalid fmt//~v65pI~
    	chsz=-1;	//errid                                        //~v65pI~
//  else                                                           //~v65pI~//~v66mR~
//      ucs=*Ppdata;                                               //~v660R~//~v66mR~
//  if (chsz<0)                                                    //~v65pI~//~v66mR~
//      ucs=*Ppdata;                                               //~v660R~//~v66mR~
    if (Ppchsz)                                                    //~v65pI~
    	*Ppchsz=chsz;                                              //~v65pI~
UTRACED("utfdd2u1chsz inp data",Ppdata,Plen);                      //~v660I~
UTRACED("utfdd2u1chsz inp dbcs",Ppdbcs,Plen);                      //~v660I~
UTRACEP("utfdd2u1chsz ret ucs=%x chsz=%d\n",ucs,chsz);             //~v660I~
    return ucs;                                                    //~v65pI~
}//utfdd2u1chsz                                                    //~v660R~
#endif                                                             //~v660I~
//**************************************************               //~v640M~
//*get ucs2 string from data/dbcs DDucs format                     //~v640M~
//*output buff is optional(return length)                          //~v640I~
//*!! output is UCS2                                               //~v6BCI~
//*ret:4:outbuff overflow                                          //~v640M~
//**************************************************               //~v640M~
int utfdd2u(int Popt,UCHAR *Ppdata,UCHAR *Ppdbcs,int Plen,WUCS *Ppucs,int Poutbuffsz,int *Ppucsctr,int *Ppucsdbcsctr,int *Ppucssbcsctr)//~v640I~
{                                                                  //~v640M~
	WUCS ucs=0,*pucs;                                              //~v6h4R~
	UCHAR *pdata,*pdbcs,dbcsid;                                    //~v640R~
    int ucsctr=0,ucsdbcsctr=0,ucssbcsctr=0,reslen,resleno,chsz,rc=0;//~v640R~
    int errrep;                                                    //~v640I~
    int altch;                                                     //~v65iI~
//  int swdbcsspace;                                               //~v65mI~//~v6b9R~
    int swdbcsspace;                                               //~v6DdI~
#ifdef UTF8UTF16                                                   //~v6uBI~
	UWUCS uwucs;                                                   //~v6uBI~
#endif                                                             //~v6uBI~
//******************                                               //~v640M~
    errrep=Popt & UTFDD2UO_ERRREP;                                 //~v640I~
UTRACEP("%s:opt=%x,len=%d,buffsz=%d\n",UTT,Popt,Plen,Poutbuffsz);  //~v6BMI~
UTRACED("utfdd2u inp data",Ppdata,Plen);                           //~v640R~
UTRACED("utfdd2u inp dbcs",Ppdbcs,Plen);                           //~v640R~
	for (pdata=Ppdata,pdbcs=Ppdbcs,pucs=Ppucs,reslen=Plen,resleno=Poutbuffsz;//~v640M~
		reslen>0;                                                  //~v640M~
		pdata+=chsz,pdbcs+=chsz,reslen-=chsz)                      //~v640M~
    {                                                              //~v640M~
        chsz=1;                                                    //~v640M~
        dbcsid=*pdbcs;                                             //~v640I~
//      swdbcsspace=0;                                             //~v65mI~//~v6b9R~
		swdbcsspace=0;                                             //~v6DdI~
#ifdef UTF8UTF16                                                   //~v6uBI~
        uwucs=0;                                                   //~v6uBI~
#endif                                                             //~v6uBI~
    	if (UDBCSCHK_ISUCSSBCS(dbcsid))                            //~v640R~
        {                                                          //~v640M~
        	ucs=(WUCS)UTF_GETUCSSBCS(pdata,pdbcs);                 //~v640R~
            ucssbcsctr++;                                          //~v640M~
        }                                                          //~v640M~
        else                                                       //~v640M~
        if (UDBCSCHK_ISUCSNP(dbcsid)                               //~v640R~
        &&  Popt & UTFDD2UO_VIO     //for vio,errdata              //~v640I~
    	)                                                          //~v640I~
        {                                                          //~v640I~
            ucs=*pdata;	//errid                                    //~v640R~
#ifdef AAA                                                         //~v6DbI~
#ifdef AAA                                                         //~v6DbI~
//          if (ucs<0x20||ucs==DBCSSPACE_ALT)//0xff by tabdisplay default for dbcsspace//~v65nR~
//          if (ucs<0x20||ucs==DEFAULT_ALTCH)//0xff by tabdisplay default for dbcsspace//~v65nR~
//  			if ((altch=utfgetvisiblealtch(0,ucs))>0)   //~v65iR~//~v65nR~
            if (ucs<0x20)                                          //~v65nR~
//              ucs=((altch=UTF_GETALTCH_CTL(ucs))>0 ? altch:ucs); //~v65nI~//~v6B3R~
                ucs=(WUCS)((altch=UTF_GETALTCH_CTL(ucs))>0 ? altch:ucs);//~v6B3I~
            else                                                   //~v65nI~
            if (ucs==DEFAULT_ALTCH)                                //~v65nI~
//              ucs=((altch=UTF_GETALTCH_DBCS())>0 ? altch:ucs);   //~v65nI~//~v6B3R~
                ucs=(WUCS)((altch=UTF_GETALTCH_DBCS())>0 ? altch:ucs);//~v6B3I~
            chsz=1;                                                //~v640R~
#else                                                              //~v6DbI~
          	if ((ucs==UDBCSCHK_ERRREPCH_NPUCS && UDBCSCHK_ISUCSNP1ST(dbcsid))//~v6DbI~
          	||  (ucs==UDBCSCHK_ERRREPCH_NPUCSW && UDBCSCHK_ISUCSNP2ND(dbcsid))//~v6DbI~
          	)                                                      //~v6DbI~
          	{                                                      //~v6DbI~
            	UTRACEP("%s:vio ucsnp set by tabdisplay ucs=%04x,dbcsid=%02x\n",UTT,ucs,dbcsid);//~v6DbR~
          	}                                                      //~v6DbI~
          	else                                                   //~v6DbI~
          	if ((altch=UTF_GETALTCH_SBCS(DEFAULT_UNPATTR))>0)      //~v6DbI~
          	{                                                      //~v6DbI~
            	UTRACEP("%s:vio ucsnp set altchar ucs=%04x,dbcsid=%02x,altch=%04x\n",UTT,ucs,dbcsid,altch);//~v6DbR~
            	ucs=(WUCS)altch;	//errid                        //~v6DbR~
          	}                                                      //~v6DbI~
            else                                                   //~v6DbI~
            {                                                      //~v6DbI~
        		ucs='.';                                           //~v6DbR~
            }                                                      //~v6DbI~
#endif                                                             //~v6DbI~
#else                                                              //~v6DbI~
    #ifdef SSS                                                     //~v6DhI~
          if (ucs==DEFAULT_ALTCH &&  UDBCSCHK_ISUCSNP1ST(dbcsid)   //~v6DdR~
          &&  reslen>1 && *(pdata+1)==ucs && UDBCSCHK_ISUCSNP2ND(*(pdbcs+1))//~v6DdI~
          &&  (altch=UTF_GETALTCH_DBCS())>0                        //~v6DdI~
          )                                                        //~v6DdI~
          {                                                        //~v6DdI~
              UTRACEP("%s:ucs %04x,alt=%04x,dbcsspace\n",UTT,ucs,altch);//~v6DhI~
              ucs=(WUCS)altch;                                     //~v6DdI~
              swdbcsspace=1;                                       //~v6DdR~
              chsz=2;                                              //~v6DdI~
          }                                                        //~v6DdI~
          else                                                     //~v6DdI~
    #endif                                                         //~v6DhM~
			ucs=(WUCS)utf22_setunpucsvio(0,(ULONG)ucs,dbcsid,0/*Pprc*/);//~v6DbR~
#endif                                                             //~v6DbI~
        }                                                          //~v640I~
        else                                                       //~v640I~
    	if (UDBCSCHK_DBCS1STUCS2NWP(dbcsid))                       //~v640R~
        {                                                          //~v640M~
        	if (reslen==1)	//split by EOL                         //~v640M~
            	chsz=-1;	//errid                                //~v640M~
            else                                                   //~v640M~
            {                                                      //~v640M~
        		ucs=UTF_GETUCSDBCS(pdata);                         //~v640R~
//              if (Popt & UTFDD2UO_VIO)                             //~v6DeR~//~v6DfR~
//                  if ((swdbcsspace=utf22_setdbcsspacealt(0,(UWUCS)ucs,pdbcs,reslen,&altch)))//~v6DeR~//~v6DfR~
//                      ucs=(WUCS)altch;                             //~v6DeR~//~v6DfR~
//#ifndef SSS                                                      //~v6DhR~
//                if (Popt & UTFDD2UO_VIO)                         //~v6DhR~
//                    if ((swdbcsspace=utf22_setdbcsspacealt(0,(UWUCS)ucs,pdbcs,reslen,&altch)))//~v6DhR~
//                        ucs=(WUCS)altch;                         //~v6DhR~
//#endif                                                           //~v6DhR~
            	ucsdbcsctr++;                                      //~v640M~
            	chsz=2;                                            //~v640M~
            }                                                      //~v640M~
        }                                                          //~v640M~
        else                                                       //~v640M~
//#ifdef UTF8UCS4                                                    //~v65cI~//~v6uBR~
#ifdef UTF8UCS416                                                  //~v6uBI~
    	if (UDBCSCHK_ISUCSOVF1ST(dbcsid))                          //~v65cR~
        {                                                          //~v65cI~
        	if (reslen==1)	//split by EOL                         //~v65cI~
            	chsz=-1;	//errid                                //~v65cI~
            else                                                   //~v65cI~
            {                                                      //~v65cI~
#ifdef UTF8UTF16                                                   //~v6uBI~
                uwucs=UTF_GETUCSDBCSOVF(pdata,pdbcs);   //ucs4     //~v6uBI~
#else                                                              //~v6uBI~
        		ucs=UTF_GETUCSDBCSOVF(pdata,pdbcs);                //~v65cR~
#endif                                                             //~v6uBI~
				ucs=(WUCS)utf22_setunpucsvio(UT22SUUVO_OVF,(ULONG)ucs,dbcsid,0/*Pprc*/);//~v6DbR~
            	ucsdbcsctr++;                                      //~v65cI~
            	chsz=2;                                            //~v65cI~
            }                                                      //~v65cI~
        }                                                          //~v65cI~
        else                                                       //~v65cI~
#endif                                                             //~v65cI~
//#ifdef UTF8UCS4                                                    //~v65cI~//~v6uBR~
#ifdef UTF8UCS416                                                  //~v6uBI~
    	if (UDBCSCHK_DBCS2NDU(dbcsid))    		//dbcs split at TOL or invalid fmt//~v65cI~
#else                                                              //~v65cI~
    	if (UDBCSCHK_DBCS2NDUCS2NWP(dbcsid))    //dbcs split at TOL or invalid fmt//~v640R~
#endif                                                             //~v65cI~
        {                                                          //~v640M~
            chsz=-1;	//errid                                    //~v640M~
        }                                                          //~v640M~
        else                                                       //~v640M~
        {                                                          //~v65gI~
        	ucs=*pdata;                                            //~v640M~
        	if (Popt & UTFDD2UO_VIO)     //for screen write        //~v65iR~
            {                                                      //~v65iR~
                if (ucs==DEFAULT_ALTCH) //0xff                     //~v65nI~
                {                                                  //~v65nI~
					if ((altch=UTF_GETALTCH_SBCS(dbcsid))>0)       //~v65nR~
//  					ucs=altch;                                 //~v65nR~//~v6B3R~
    					ucs=(WUCS)altch;                           //~v6B3I~
                }                                                  //~v65nI~
                else                                               //~v65nI~
            	if (ucs<0x20)                                      //~v65iI~
                {                                                  //~v66dI~
        	        if (!ucs && Popt & UTFDD2UO_NULLREP)     //for screen write//~v66dI~
	        			ucs=' ';                                   //~v66dI~
                    else                                           //~v66dI~
					if ((altch=UTF_GETALTCH_CTL(ucs))>0)           //~v65nR~
//                  	ucs=altch;                                 //~v65iI~//~v6B3R~
                    	ucs=(WUCS)altch;                           //~v6B3I~
                }                                                  //~v66dI~
            }                                                      //~v65gI~
        	if (!ucs && Popt & UTFDD2UO_NULLREP)     //for screen write//~v66dR~
//          	ucs=errrep;                                        //~v66dI~//~v6B3R~
            	ucs=(WUCS)errrep;                                  //~v6B3I~
        }                                                          //~v65gI~
        if (chsz<0) //err data                                     //~v640M~
        {                                                          //~v640M~
            chsz=1;                                                //~v640M~
//          ucs=errrep;    //display "."                           //~v640R~//~v6B3R~
            ucs=(WUCS)errrep;    //display "."                     //~v6B3I~
        }                                                          //~v640M~
        if (Ppucs)                                                 //~v640I~
        {                                                          //~v640I~
#ifdef UTF8UTF16                                                   //~v6uBI~
		  if (UTF_ISUCS4(uwucs))                                   //~v6uBI~
		  {                                                        //~v6uBI~
          	int utf16ctr;                                          //~v6uBI~
        	if (resleno<WUCSSZ*2)                                  //~v6uBI~
        	{                                                      //~v6uBI~
        		rc=4;                                              //~v6uBI~
        		break;                                             //~v6uBI~
        	}                                                      //~v6uBI~
            UCS4_TO_UTF16(uwucs,pucs,&utf16ctr);                   //~v6uBI~
            pucs+=2;                                               //~v6uBI~
	        resleno-=WUCSSZ*2;                                     //~v6uBI~
          }                                                        //~v6uBI~
          else                                                     //~v6uBI~
#endif                                                             //~v6uBI~
		  {                                                        //~v6uBI~
        	if (resleno<WUCSSZ)                                    //~v640R~
        	{                                                      //~v640R~
        		rc=4;                                              //~v640R~
        		break;                                             //~v640R~
        	}                                                      //~v640R~
        	*pucs++=ucs;                                           //~v640R~
//          resleno-=WUCSSZ;                                       //~v640I~//~v6B4R~
            resleno-=(int)WUCSSZ;                                  //~v6B4I~
          }                                                        //~v6uBI~
          if (swdbcsspace)                                         //~v6DdI~
          {                                                        //~v6DdI~
          	if (resleno<WUCSSZ)                                    //~v6DdI~
            {                                                      //~v6DdI~
            	rc=4;                                              //~v6DdI~
                break;                                             //~v6DdI~
            }                                                      //~v6DdI~
            *pucs++=ucs;                                           //~v6DdI~
            resleno-=(int)WUCSSZ;                                  //~v6DdI~
            ucsctr++;                                              //~v6DdI~
          }                                                        //~v6DdI~
        }                                                          //~v640I~
        ucsctr++;                                                  //~v640M~
#ifdef UTF8UTF16                                                   //~v6uBI~
        if (UTF_ISUCS4(uwucs))                                     //~v6uBI~
          	ucsctr++;   //1 more later                             //~v6uBI~
#endif                                                             //~v6uBI~
		if (Popt & UTFDD2UO_UCS1)	//get 1 ucs                    //~v640I~
        	break;                                                 //~v640I~
    }                                                              //~v640M~
    if (Ppucsctr)                                                  //~v640M~
        *Ppucsctr=ucsctr;                                          //~v640M~
    if (Ppucssbcsctr)                                              //~v640M~
        *Ppucssbcsctr=ucssbcsctr;                                  //~v640M~
    if (Ppucsdbcsctr)                                              //~v640M~
        *Ppucsdbcsctr=ucsdbcsctr;                                  //~v640M~
UTRACEP("utfdd2u inplen=%d,rc=%d,ucsctr=%d\n",Plen,rc,ucsctr);     //~v640R~
UTRACEDIFNZ("utfdd2u out ucs ",Ppucs,ucsctr*(int)WUCSSZ);               //~v640R~//~v6B4R~
    return rc;                                                     //~v640M~
}//utfdd2u                                                         //~v640I~
#ifdef AAA //no caller                                             //~v6DbI~
//**************************************************               //~v640M~//~v6BMI~
//*get ucs2 string from data/dbcs DDucs format                     //~v640M~//~v6BMI~
//*output buff is optional(return length)                          //~v640I~//~v6BMI~
//*!! output is UCS2                                               //~v6BCI~//~v6BMI~
//*ret:4:outbuff overflow                                          //~v640M~//~v6BMI~
//**************************************************               //~v640M~//~v6BMI~
int utfdd2u4(int Popt,UCHAR *Ppdata,UCHAR *Ppdbcs,int Plen,UWUCS *Ppucs,int Poutbuffsz,int *Ppucsctr,int *Ppucsdbcsctr,int *Ppucssbcsctr)//~v640I~//~v6BMR~
{                                                                  //~v640M~//~v6BMI~
	UWUCS ucs=0,*pucs;                                              //~v6h4R~//~v6BMR~
	UCHAR *pdata,*pdbcs,dbcsid;                                    //~v640R~//~v6BMI~
    int ucsctr=0,ucsdbcsctr=0,ucssbcsctr=0,reslen,resleno,chsz,rc=0;//~v640R~//~v6BMI~
    int errrep;                                                    //~v640I~//~v6BMI~
    int altch;                                                     //~v65iI~//~v6BMI~
//******************                                               //~v640M~//~v6BMI~
    errrep=Popt & UTFDD2UO_ERRREP;                                 //~v640I~//~v6BMI~
UTRACED("utfdd2u inp data",Ppdata,Plen);                           //~v640R~//~v6BMI~
UTRACED("utfdd2u inp dbcs",Ppdbcs,Plen);                           //~v640R~//~v6BMI~
	for (pdata=Ppdata,pdbcs=Ppdbcs,pucs=Ppucs,reslen=Plen,resleno=Poutbuffsz;//~v640M~//~v6BMI~
		reslen>0;                                                  //~v640M~//~v6BMI~
		pdata+=chsz,pdbcs+=chsz,reslen-=chsz)                      //~v640M~//~v6BMI~
    {                                                              //~v640M~//~v6BMI~
        chsz=1;                                                    //~v640M~//~v6BMI~
        dbcsid=*pdbcs;                                             //~v640I~//~v6BMI~
    	if (UDBCSCHK_ISUCSSBCS(dbcsid))                            //~v640R~//~v6BMI~
        {                                                          //~v640M~//~v6BMI~
        	ucs=(UWUCS)UTF_GETUCSSBCS(pdata,pdbcs);                 //~v640R~//~v6BMR~
            ucssbcsctr++;                                          //~v640M~//~v6BMI~
        }                                                          //~v640M~//~v6BMI~
        else                                                       //~v640M~//~v6BMI~
        if (UDBCSCHK_ISUCSNP(dbcsid)                               //~v640R~//~v6BMI~
        &&  Popt & UTFDD2UO_VIO     //for vio,errdata              //~v640I~//~v6BMI~
    	)                                                          //~v640I~//~v6BMI~
        {                                                          //~v640I~//~v6BMI~
            ucs=*pdata;	//errid                                    //~v640R~//~v6BMI~
#ifdef AAA                                                         //~v6DbI~
            if (ucs<0x20)                                          //~v65nR~//~v6BMI~
                ucs=(UWUCS)((altch=UTF_GETALTCH_CTL(ucs))>0 ? altch:ucs);//~v6B3I~//~v6BMR~
            else                                                   //~v65nI~//~v6BMI~
            if (ucs==DEFAULT_ALTCH)                                //~v65nI~//~v6BMI~
                ucs=(UWUCS)((altch=UTF_GETALTCH_DBCS())>0 ? altch:ucs);//~v6B3I~//~v6BMR~
            chsz=1;                                                //~v640R~//~v6BMI~
#else                                                              //~v6DbI~
          if ((ucs==UDBCSCHK_ERRREPCH_NPUCS && UDBCSCHK_ISUCSNP1ST(dbcsid))//~v6DbI~
          ||  (ucs==UDBCSCHK_ERRREPCH_NPUCSW && UDBCSCHK_ISUCSNP2ND(dbcsid))//~v6DbI~
          )                                                        //~v6DbI~
          {                                                        //~v6DbI~
            UTRACEP("%s:vio ucsnp set by tabdisplay ucs=%04x,dbcsid=%02x\n",UTT,ucs,dbcsid);//~v6DbR~
          	chsz=1;                                                //~v6DbI~
          }                                                        //~v6DbI~
          else                                                     //~v6DbI~
          if ((altch=UTF_GETALTCH_SBCS(DEFAULT_UNPATTR))>0)        //~v6DbI~
          {                                                        //~v6DbI~
            UTRACEP("%s:vio ucsnp set altchar ucs=%04x,dbcsid=%02x,altch=%04x\n",UTT,ucs,dbcsid,altch);//~v6DbR~
            ucs=(UWUCS)altch;	//errid                            //~v6DbR~
            chsz=1;                                                //~v6DbI~
          }                                                        //~v6DbI~
#endif                                                             //~v6DbI~
        }                                                          //~v640I~//~v6BMI~
        else                                                       //~v640I~//~v6BMI~
    	if (UDBCSCHK_DBCS1STUCS2NWP(dbcsid))                       //~v640R~//~v6BMI~
        {                                                          //~v640M~//~v6BMI~
        	if (reslen==1)	//split by EOL                         //~v640M~//~v6BMI~
            	chsz=-1;	//errid                                //~v640M~//~v6BMI~
            else                                                   //~v640M~//~v6BMI~
            {                                                      //~v640M~//~v6BMI~
        		ucs=UTF_GETUCSDBCS(pdata);                         //~v640R~//~v6BMI~
            	ucsdbcsctr++;                                      //~v640M~//~v6BMI~
            	chsz=2;                                            //~v640M~//~v6BMI~
            }                                                      //~v640M~//~v6BMI~
        }                                                          //~v640M~//~v6BMI~
        else                                                       //~v640M~//~v6BMI~
    	if (UDBCSCHK_ISUCSOVF1ST(dbcsid))                          //~v65cR~//~v6BMI~
        {                                                          //~v65cI~//~v6BMI~
        	if (reslen==1)	//split by EOL                         //~v65cI~//~v6BMI~
            	chsz=-1;	//errid                                //~v65cI~//~v6BMI~
            else                                                   //~v65cI~//~v6BMI~
            {                                                      //~v65cI~//~v6BMI~
        		ucs=UTF_GETUCSDBCSOVF(pdata,pdbcs);                //~v65cR~//~v6BMI~
            	ucsdbcsctr++;                                      //~v65cI~//~v6BMI~
            	chsz=2;                                            //~v65cI~//~v6BMI~
            }                                                      //~v65cI~//~v6BMI~
        }                                                          //~v65cI~//~v6BMI~
        else                                                       //~v65cI~//~v6BMI~
    	if (UDBCSCHK_DBCS2NDU(dbcsid))    		//dbcs split at TOL or invalid fmt//~v65cI~//~v6BMI~
        {                                                          //~v640M~//~v6BMI~
            chsz=-1;	//errid                                    //~v640M~//~v6BMI~
        }                                                          //~v640M~//~v6BMI~
        else                                                       //~v640M~//~v6BMI~
        {                                                          //~v65gI~//~v6BMI~
        	ucs=*pdata;                                            //~v640M~//~v6BMI~
        	if (Popt & UTFDD2UO_VIO)     //for screen write        //~v65iR~//~v6BMI~
            {                                                      //~v65iR~//~v6BMI~
                if (ucs==DEFAULT_ALTCH) //0xff                     //~v65nI~//~v6BMI~
                {                                                  //~v65nI~//~v6BMI~
					if ((altch=UTF_GETALTCH_SBCS(dbcsid))>0)       //~v65nR~//~v6BMI~
    					ucs=(UWUCS)altch;                           //~v6B3I~//~v6BMR~
                }                                                  //~v65nI~//~v6BMI~
                else                                               //~v65nI~//~v6BMI~
            	if (ucs<0x20)                                      //~v65iI~//~v6BMI~
                {                                                  //~v66dI~//~v6BMI~
        	        if (!ucs && Popt & UTFDD2UO_NULLREP)     //for screen write//~v66dI~//~v6BMI~
	        			ucs=' ';                                   //~v66dI~//~v6BMI~
                    else                                           //~v66dI~//~v6BMI~
					if ((altch=UTF_GETALTCH_CTL(ucs))>0)           //~v65nR~//~v6BMI~
                    	ucs=(UWUCS)altch;                           //~v6B3I~//~v6BMR~
                }                                                  //~v66dI~//~v6BMI~
            }                                                      //~v65gI~//~v6BMI~
        	if (!ucs && Popt & UTFDD2UO_NULLREP)     //for screen write//~v66dR~//~v6BMI~
            	ucs=(UWUCS)errrep;                                  //~v6B3I~//~v6BMR~
        }                                                          //~v65gI~//~v6BMI~
        if (chsz<0) //err data                                     //~v640M~//~v6BMI~
        {                                                          //~v640M~//~v6BMI~
            chsz=1;                                                //~v640M~//~v6BMI~
            ucs=(UWUCS)errrep;    //display "."                     //~v6B3I~//~v6BMR~
        }                                                          //~v640M~//~v6BMI~
        if (Ppucs)                                                 //~v640I~//~v6BMI~
        {                                                          //~v640I~//~v6BMI~
        	if (resleno<UWUCSSZ)                                    //~v640R~//~v6BMR~
        	{                                                      //~v640R~//~v6BMI~
        		rc=4;                                              //~v640R~//~v6BMI~
        		break;                                             //~v640R~//~v6BMI~
        	}                                                      //~v640R~//~v6BMI~
        	*pucs++=ucs;                                           //~v640R~//~v6BMI~
            resleno-=(int)UWUCSSZ;                                  //~v6B4I~//~v6BMR~
        }                                                          //~v640I~//~v6BMI~
        ucsctr++;                                                  //~v640M~//~v6BMI~
		if (Popt & UTFDD2UO_UCS1)	//get 1 ucs                    //~v640I~//~v6BMI~
        	break;                                                 //~v640I~//~v6BMI~
    }                                                              //~v640M~//~v6BMI~
    if (Ppucsctr)                                                  //~v640M~//~v6BMI~
        *Ppucsctr=ucsctr;                                          //~v640M~//~v6BMI~
    if (Ppucssbcsctr)                                              //~v640M~//~v6BMI~
        *Ppucssbcsctr=ucssbcsctr;                                  //~v640M~//~v6BMI~
    if (Ppucsdbcsctr)                                              //~v640M~//~v6BMI~
        *Ppucsdbcsctr=ucsdbcsctr;                                  //~v640M~//~v6BMI~
UTRACEP("utfdd2u inplen=%d,rc=%d,ucsctr=%d\n",Plen,rc,ucsctr);     //~v640R~//~v6BMI~
UTRACEDIFNZ("utfdd2u out ucs ",Ppucs,ucsctr*(int)UWUCSSZ);               //~v640R~//~v6B4R~//~v6BMR~
    return rc;                                                     //~v640M~//~v6BMI~
}//utfdd2u4                                                        //~v640I~//~v6BMI~//~v6DbR~
#endif                                                             //~v6DbI~
//**************************************************               //~v6BMI~
//*ucs4-->utf16                                                    //~v6BMI~
//**************************************************               //~v6BMI~
int utfucs42utf16(int Popt,UWUCS *Pucs4,int Pucs4ctr,WUCS *Pucs2,int Pbuffsz,int *Ppoutctr)//~v6BMR~
{                                                                  //~v6BMI~
	WUCS  *pucs2;                                                  //~v6BMR~
	UWUCS *pucs4,ucs4;                                             //~v6BMR~
    int rc=0,outctr,ii,resleno,utf16ctr;                           //~v6BMR~
//******************                                               //~v6BMI~
	outctr=0;                                                      //~v6BMI~
	for (pucs4=Pucs4,pucs2=Pucs2,ii=0,resleno=Pbuffsz;ii<Pucs4ctr;pucs4++,ii++)//~v6BMR~
    {                                                              //~v6BMI~
    	ucs4=*pucs4;                                               //~v6BMI~
		if (UTF_ISUCS4(ucs4))                                      //~v6BMI~
		{                                                          //~v6BMI~
        	if (resleno<WUCSSZ*2)                                  //~v6BMI~
        	{                                                      //~v6BMI~
        		rc=4;                                              //~v6BMI~
        		break;                                             //~v6BMI~
        	}                                                      //~v6BMI~
            UCS4_TO_UTF16(ucs4,pucs2,&utf16ctr);                   //~v6BMI~
        }                                                          //~v6BMI~
        else                                                       //~v6BMI~
		{                                                          //~v6BMI~
        	if (resleno<WUCSSZ)                                    //~v6BMI~
        	{                                                      //~v6BMI~
        		rc=4;                                              //~v6BMI~
        		break;                                             //~v6BMI~
        	}                                                      //~v6BMI~
        	*pucs2=(WUCS)ucs4;                                     //~v6BMI~
            utf16ctr=1;                                            //~v6BMI~
        }                                                          //~v6BMI~
        pucs2+=utf16ctr;                                           //~v6BMI~
	    resleno-=WUCSSZ*utf16ctr;                                  //~v6BMI~
        outctr+=utf16ctr;                                          //~v6BMI~
    }                                                              //~v6BMI~
    if (Ppoutctr)                                                  //~v6BMR~
        *Ppoutctr=outctr;                                          //~v6BMR~
UTRACEP("%s:rc=%d,ucs4 ctr=%d,ucs2 ctr=%d\n",UTT,rc,Pucs4ctr,outctr);//~v6BMI~
UTRACED("inp ucs4",Pucs4,Pucs4ctr*(int)UWUCSSZ);                   //~v6BMI~
UTRACED("out ucs2",Pucs2,outctr*(int)WUCSSZ);                      //~v6BMI~
    return rc;                                                     //~v6BMI~
}//utfucs42utf16                                                   //~v6BMI~
//**************************************************               //~v6b9I~
//*get ucsctr of ddfmt                                             //~v6b9I~
//*ret:4:ddfmt err,last 1 split                                    //~v6b9R~
//**************************************************               //~v6b9I~
int utfddgetucsctr(int Popt,UCHAR *Ppdbcs,int Plen,int Ppos,int *Ppucsctr)//~v6b9I~
{                                                                  //~v6b9I~
	UCHAR *pdbcs,dbcsid;                                           //~v6b9I~
    int ucsctr=0,reslen,chsz=0,rc=0;                               //~v6b9R~
//******************                                               //~v6b9I~
	UTRACED("utfddgetucsctr",Ppdbcs,Plen);                         //~v6b9I~
    reslen=min(Plen,Ppos);                                         //~v6b9I~
	for (pdbcs=Ppdbcs;reslen>0;pdbcs+=chsz,reslen-=chsz,ucsctr++)  //~v6b9I~
    {                                                              //~v6b9I~
        dbcsid=*pdbcs;                                             //~v6b9I~
        chsz=1;                                                    //~v6b9I~
    	if (UDBCSCHK_DBCS1STU(dbcsid))                             //~v6b9I~
        {                                                          //~v6b9I~
            chsz=2;                                                //~v6b9I~
        	if (reslen==1)	//split by EOL                         //~v6b9I~
            {                                                      //~v6b9I~
            	rc=1;	//dbcssplit                                //~v6b9I~
            	break;                                             //~v6b9I~
            }                                                      //~v6b9I~
        }                                                          //~v6b9I~
        else                                                       //~v6b9M~
    	if (UDBCSCHK_DBCS2NDU(dbcsid))                             //~v6b9M~
        {                                                          //~v6b9M~
        	rc=4;                                                  //~v6b9M~
            break;                                                 //~v6b9M~
        }                                                          //~v6b9M~
    }                                                              //~v6b9I~
    if (Ppucsctr)                                                  //~v6b9I~
        *Ppucsctr=ucsctr;                                          //~v6b9I~
UTRACEP("utfddgetucsctr rc=%d,ucsctr=%d,pos=%d\n",rc,ucsctr,Ppos); //~v6b9I~
    return rc;                                                     //~v6b9I~
}//utfddgetucsctr                                                  //~v6b9I~
#ifdef LNX	//win use UTF162dd                                     //~v6uLI~
//*******************************************************          //~v640I~
//*convert utf8string to ucs string DD fmt                         //~v640I~
//*set UDBCSCHK_DBCS1STUCS,2NDUCS,NPUCS1,NPUCS2,HKDBCSERR,SBCSUCSID(0x80)//~v640I~
//*rc:buff overflow,dbcs,utf8,errutf8                              //~v640I~
//*******************************************************          //~v640I~
int utfu2dd(int Popt,PWUCS Ppdata,int Plen,UCHAR *Ppoutdata,UCHAR *Ppoutdbcs,int Poutbuffsz,int *Ppoutlen)//~v640I~
{                                                                  //~v640I~
    ULONG ucs;                                                     //~v640I~
    int charwidth,rc=0,reslen,outreslen,outlen,opt;                //~v640R~
    UCHAR *pco,*pcdo;                                              //~v640I~
    UCHAR wcdbcs[2],wcdata[2];                                     //~v640I~
    PWUCS pucs;                                                    //~v640I~
    int rc2;                                                       //~v6VfI~
//****************************                                     //~v640I~
UTRACED("input WUCS",Ppdata,Plen);                         //~v640I~//~v6BMR~
    pco=Ppoutdata;                                                 //~v640I~
    pcdo=Ppoutdbcs;                                                //~v640I~
    pucs=Ppdata;                                                   //~v640I~
	opt=UTFGWCWO_INPUTUCS|UTFGWCWO_GETSBCSID;    //input is not utf but ucs,return sbcsid to charwidth//~v640I~
    for (reslen=Plen/2,outreslen=Poutbuffsz;reslen>0 && outreslen>0;pucs++,reslen--,outreslen--)//~v640R~
    {                                                              //~v640I~
        ucs=(ULONG)*pucs;                                          //~v640I~
        if (UTF8ISASCII(ucs))                                      //~v640I~
        {                                                          //~v640I~
        	*pco++=(UCHAR)ucs;                                     //~v640R~
            *pcdo++=0;                                             //~v640I~
            continue;                                              //~v640I~
        }                                                          //~v640I~
//      utfgetwcw(opt,(UCHAR*)(ULONG)pucs,0/*reslen*/,&ucs,0/*chklen*/,&charwidth);//get ucs2 and sbcsid,always rc=0//~v640R~//~v6hhR~
        utfgetwcw(opt,(UCHAR*)(ULPTR)pucs,0/*reslen*/,&ucs,0/*chklen*/,&charwidth);//get ucs2 and sbcsid,always rc=0//~v6hhI~
//*WUCS:safe by AAA                                                //~v6uBI~
//      rc|=utfcvu2dd1w(0,(WUCS)ucs,charwidth,wcdata,wcdbcs);      //~v640I~//~v6VfR~
        rc2=utfcvu2dd1w(0,(WUCS)ucs,charwidth,wcdata,wcdbcs);      //~v6VfI~
        rc|=rc2;                                                   //~v6VfI~
        *pco++=wcdata[0];                                          //~v640I~
        *pcdo++=wcdbcs[0];                                         //~v640I~
//      if (charwidth!=1)   //not sbcs                             //~v640I~//~v6VfR~
        if (rc2 & UTFCVFDRC_DBCS)                                  //~v6VfI~
        {                                                          //~v640I~
            if (outreslen<=1)                                      //~v640I~
                break;                                             //~v640I~
            outreslen--;                                           //~v640I~
            *pco++=wcdata[1];   //big endian ucs                   //~v640I~
            *pcdo++=wcdbcs[1];                                     //~v640I~
        }                                                          //~v640I~
    }                                                              //~v640I~
    if (reslen>0)                                                  //~v640R~
		rc|=UTFCVFDRC_OVF;   //buffser overflow                    //~v640I~
//  outlen=(int)((ULONG)pco-(ULONG)Ppoutdata);                     //~v640I~//~v6hhR~
    outlen=(int)((ULPTR)pco-(ULPTR)Ppoutdata);                     //~v6hhI~
    if (Ppoutlen)                                                  //~v640I~
	    *Ppoutlen=outlen;                                          //~v640I~
UTRACED("utfu2dd out data",Ppoutdata,outlen);                      //~v640I~
UTRACED("utfu2dd out dbcs",Ppoutdbcs,outlen);                      //~v640I~
    return rc;                                                     //~v640I~
}//utfu2dd                                                         //~v640I~
#endif //LNX                                                       //~v6uLI~
#ifdef W32UNICODE                                                         //~v6u0I~//~v6uaR~
//*******************************************************          //~v6u0I~
//*convert utf16 to DD fmt                                         //~v6uaR~
//*rc:buff overflow,1:utf8,2:dbcs                                  //~v6uaR~
//*******************************************************          //~v6uaR~
int utf162dd(int Popt,PUWCH Ppdata,int Pctr,UCHAR *Ppoutdata,UCHAR *Ppoutdbcs,int Poutbuffsz,int *Ppoutlen)//~v6uaR~
{                                                                  //~v6uaR~
    ULONG ulucs;                                                   //~v6uaR~
//  UWCH  u16L,u16H;                                               //~v6uaR~//~v6ueR~
    UWCH  u16L,u16H;                                               //~v6uBI~
//  int charwidth,rc=0,reslen,outreslen,outlen,opt/*,swerr*/;          //~v6uaR~//~v6ueR~//~v6uBR~
    int charwidth,rc=0,reslen,outreslen,outlen,opt,swerr;          //~v6uBI~
    UCHAR *pco,*pcdo;                                              //~v6uaR~
    UCHAR wcdbcs[2],wcdata[2];                                     //~v6uaR~
    PWCH pucs;                                                     //~v6uaR~
    int rc2;                                                       //~v6VfI~
//****************************                                     //~v6uaR~
UTRACED("utf162dd input   ",Ppdata,ctr2szW(Pctr));                 //~v6uaR~
    pco=Ppoutdata;                                                 //~v6uaR~
    pcdo=Ppoutdbcs;                                                //~v6uaR~
    pucs=Ppdata;                                                   //~v6uaR~
	opt=UTFGWCWO_INPUTUCS|UTFGWCWO_GETSBCSID;    //input is not utf but ucs,return sbcsid to charwidth//~v6uaR~
//  opt2=UTFCVO_UCS4W;                                             //~v6u7I~//~v6uaR~
//  opt2=0;                                                        //~v6uaR~
    for (reslen=Pctr,outreslen=Poutbuffsz;reslen>0 && outreslen>0;pucs++,reslen--,outreslen--)//~v6uaR~
    {                                                              //~v6uaR~
//#ifdef AAA                                                         //~v6ueI~//~v6uBR~
#ifdef UTF8UTF16                                                   //~v6uBI~
        u16H=*pucs;                                                //~v6uaR~
        u16L=0;                                                    //~v6ueI~
        ulucs=(ULONG)u16H;                                         //~v6uaR~
        swerr=1;                                                   //~v6uaR~
//      if (u16H>=0xD800 && u16H<0xDC00) //suurogate 1st           //~v6uaR~
        if (IS_UTF16_HIGH(u16H))                                   //~v6uaR~
        {                                                          //~v6uaR~
//          if (reslen>0)                                          //~v6uaR~//~v6VmR~
            if (reslen>1)                                          //~v6VmI~
            {                                                      //~v6uaR~
                u16L=*(pucs+1);                                    //~v6uaR~
//              if (u16L>=0xDC00 && u16H<0xE000)     //suurogate 2nd//~v6uaR~
				if (IS_UTF16_LOW(u16L))                            //~v6uaR~
                {                                                  //~v6uaR~
//                  ulucs=0x10000+(u16H-0xD800)*0x0400+(u16L-0xDC00);//~v6uaR~
                    ulucs=UTF16_TO_UCS4(u16H,u16L);                //~v6uaR~
                    reslen--;                                      //~v6uaR~
                    pucs++;                                        //~v6uaR~
                    swerr=0;                                       //~v6uaR~
                }                                                  //~v6uaR~
#ifdef MMM                                                         //~v6VkI~
#else                                                              //~v6VkI~
                else                                               //~v6VkI~
                    swerr=2;    //surrogate pair err               //~v6VkI~
#endif                                                             //~v6VkI~
            }                                                      //~v6uaR~
#ifdef MMM                                                         //~v6VkI~
#else                                                              //~v6VkI~
            else                                                   //~v6VkI~
                swerr=2;    //surrogate pair err                   //~v6VkI~
#endif                                                             //~v6VkI~
        }                                                          //~v6uaR~
        else                                                       //~v6uaR~
//      if (u16H<0xDC00 || u16H>=0xE000) //not suurogate 2nd       //~v6uaR~
		if (!IS_UTF16_LOW(u16H))                                   //~v6uaR~
        	swerr=0;                                               //~v6uaR~
#ifdef MMM                                                         //~v6VkI~
#else                                                              //~v6VkI~
        else                                                       //~v6VkI~
            swerr=2;    //surrogate pair err                       //~v6VkI~
#endif                                                             //~v6VkI~
        if (swerr)                                                 //~v6uaR~
        {                                                          //~v6uaR~
        	ulucs='.';                                             //~v6uaR~
#ifdef MMM                                                         //~v6VkI~
#else                                                              //~v6VkI~
            if (Popt & U162DO_REPUCS)    //err rep to fffd         //~v6VkI~
        		ulucs=UDBCSCHK_SUBCHAR_DBCS;                       //~v6VkI~
            if (swerr==2)   //surrogate pair err                   //~v6VkI~
            {                                                      //~v6VkI~
                ulucs=u16H;                                        //~v6VkR~
            }                                                      //~v6VkI~
#endif                                                             //~v6VkI~
        	rc=4;                                                  //~v6uaR~
        }                                                          //~v6uaR~
#else                                                              //~v6ueI~
        ulucs=*pucs;                                               //~v6ueI~
#endif                                                             //~v6ueI~
        utfgetwcw(opt,(UCHAR*)(ULPTR)(&ulucs),0/*reslen*/,&ulucs,0/*chklen*/,&charwidth);//get ucs2 and sbcsid,always rc=0//~v6uaR~
	  if (UTF_ISUCS4(ulucs))                                       //~v6uBI~
//		rc|=utfcvu2dd1wSurrogate(0,ulucs,wcdata,wcdbcs,&charwidth);//~v6uBI~//~v6VfR~
  		rc2=utfcvu2dd1wSurrogate(0,ulucs,wcdata,wcdbcs,&charwidth);//~v6VfI~
      else                                                         //~v6uBI~
//      rc|=utfcvu2dd1w(0,ulucs,charwidth,wcdata,wcdbcs);          //~v6uaI~//~v6x8R~
//      rc|=utfcvu2dd1w(0,(WUCS)ulucs,charwidth,wcdata,wcdbcs);    //~v6x8I~//~v6E0R~
//      rc|=utfcvu2dd1w(Popt,(WUCS)ulucs,charwidth,wcdata,wcdbcs); //~v6E0I~//~v6VfR~
        rc2=utfcvu2dd1w(Popt,(WUCS)ulucs,charwidth,wcdata,wcdbcs); //~v6VfI~
                                                                   //~v6VfI~
        rc|=rc2;                                                   //~v6VfI~
        *pco++=wcdata[0];                                          //~v6uaR~
        *pcdo++=wcdbcs[0];                                         //~v6uaR~
//      if (charwidth!=1)   //not sbcs                             //~v6uaR~//~v6VfR~
        if (rc2 & UTFCVFDRC_DBCS)                                  //~v6VfI~
        {                                                          //~v6uaR~
            if (outreslen<=1)                                      //~v6uaR~
                break;                                             //~v6uaR~
            outreslen--;                                           //~v6uaR~
            *pco++=wcdata[1];   //big endian ucs                   //~v6uaR~
            *pcdo++=wcdbcs[1];                                     //~v6uaR~
        }                                                          //~v6uaR~
    }                                                              //~v6uaR~
    if (reslen>0)                                                  //~v6uaR~
		rc|=UTFCVFDRC_OVF;   //buffser overflow                    //~v6uaR~
    outlen=(int)((ULPTR)pco-(ULPTR)Ppoutdata);                     //~v6uaR~
    if (Ppoutlen)                                                  //~v6uaR~
	    *Ppoutlen=outlen;                                          //~v6uaR~
UTRACED("out data",Ppoutdata,outlen);                              //~v6uaR~
UTRACED("out dbcs",Ppoutdbcs,outlen);                              //~v6uaR~
UTRACEP("%s rc=%d\n",UTT,rc);                                //~v6uaR~//~v6VmR~
    return rc;                                                     //~v6uaR~
}//utf162dd                                                        //~v6uaR~
//*******************************************************          //~v6BPI~
//*convert utf16 to ucs4                                           //~v6BPI~
//*rc:buff overflow                                                //~v6BPI~
//*******************************************************          //~v6BPI~
int utf162ucs4(int Popt,WUCS *Ppdata,int Pctr,UWUCS *Poutucs4,int Poutbuffsz,int *Ppchkctr,int *Ppoutctr)//~v6BPR~
{                                                                  //~v6BPI~
    int rc=0,reslen,outreslen;                                     //~v6BPR~
    UWUCS *pucs4;                                                  //~v6BPI~
    WUCS *pucs2,ucs2;                                              //~v6BPR~
//****************************                                     //~v6BPI~
UTRACED("input ucs2",Ppdata,ctr2szW(Pctr));                        //~v6BPI~
    pucs4=Poutucs4;                                                //~v6BPI~
    pucs2=Ppdata;                                                  //~v6BPI~
    for (reslen=Pctr,outreslen=Poutbuffsz/(int)sizeof(UWUCS);reslen>0 && outreslen>0;outreslen--,reslen--)//~v6BPR~
    {                                                              //~v6BPI~
    	ucs2=*pucs2++;                                             //~v6BPR~
		if (reslen>1 && IS_UTF16_PAIR(ucs2,*pucs2))                //~v6BPR~
        {                                                          //~v6BPI~
        	*pucs4++=(UWUCS)UTF16_TO_UCS4(ucs2,*pucs2);            //~v6BPR~
            pucs2++;                                               //~v6BPI~
            reslen--;                                              //~v6BPI~
        }                                                          //~v6BPI~
        else                                                       //~v6BPI~
            *pucs4++=(UWUCS)ucs2;                                  //~v6BPI~
        if (Popt & U162U4O_UCS1) //return by 1 ucs4                //~v6BPI~
            break;                                                 //~v6BPI~
    }                                                              //~v6BPI~
    if (reslen>0 && !outreslen)                                    //~v6BPR~
    	rc=4;                                                      //~v6BPI~
    if (Ppchkctr)                                                  //~v6BPI~
	    *Ppchkctr=PTRDIFF(pucs2,Ppdata)/(int)sizeof(WUCS);         //~v6BPI~
    if (Ppoutctr)                                                  //~v6BPI~
	    *Ppoutctr=PTRDIFF(pucs4,Poutucs4)/(int)sizeof(UWUCS);      //~v6BPR~
UTRACED("out data",Poutucs4,PTRDIFF(pucs4,Poutucs4));              //~v6BPI~
    return rc;                                                     //~v6BPI~
}//utf162ucs4                                                      //~v6BPI~
#endif	//W32UNICODE                                               //~v6uaR~
//**************************************************               //~v640I~
//*ddstr compare,char by char                                      //~v640I~
//*compare char by char                                            //~v640I~
//*Pdbcs2==0 means 2nd str is ascii                                //~v640I~
//* ex) str1:(d1)(s1)  str2:(s2)(d2),compare dbcs1 and sbcs2 the sbcs1 and dbcs2//~v640I~
//*     split dbcs or trans err is evaluated as is base            //~v640I~
//*ret:-1:0:1                                                      //~v640I~
//**************************************************               //~v640I~
int utfddcmp(int Popt,UCHAR *Ppdata1,UCHAR *Ppdbcs1,UCHAR *Ppdata2,UCHAR *Ppdbcs2,int Plen)//~v640R~
{                                                                  //~v640I~
#ifdef UTF8UTF16	                                               //~v6uBR~
	UWUCS ucs1,ucs2;                                               //~v6uBI~
#else                                                              //~v6uBI~
	WUCS ucs1,ucs2;                                                //~v640I~
#endif                                                             //~v6uBI~
	UCHAR *pdata1,*pdbcs1,*pdata2,*pdbcs2;                         //~v640R~
    int reslen1,reslen2,chsz1,chsz2,rc=0,dbcsid,swnocase;          //~v640R~
//******************                                               //~v640I~
UTRACED("utfddcmp inp data",Ppdata1,Plen);                         //~v640R~
UTRACED("utfddcmp inp dbcs",Ppdbcs1,Plen);                         //~v640R~
UTRACED("utfddcmp inp data",Ppdata2,Plen);                         //~v640R~
UTRACEDIFNZ("utfddcmp inp data",Ppdbcs2,Plen);                     //~v640R~
	swnocase=(Popt & UTFDDCMPO_NOCASE);                            //~v640R~
	pdata1=Ppdata1,pdbcs1=Ppdbcs1,pdata2=Ppdata2,pdbcs2=Ppdbcs2,reslen1=reslen2=Plen;//~v65gI~
//*left side                                                       //~v65gI~
	dbcsid=*Ppdbcs1;                                               //~v65gI~
    if (UDBCSCHK_DBCS2NDU(dbcsid))  //dbcs split                   //~v65gI~
    {                                                              //~v65gI~
    	if (Popt & UTFDDCMPO_SPLITINC0)                            //~v65gR~
            pdata1--,pdbcs1--,reslen1++;                           //~v65gI~
        else                                                       //~v65gI~
	    if (Popt & UTFDDCMPO_SPLITEXC)                             //~v65gR~
            pdata1++,pdbcs1++,reslen1--;                           //~v65gI~
    }                                                              //~v65gI~
    if (Ppdbcs2)                                                   //~v65gR~
    {                                                              //~v65gI~
        dbcsid=*Ppdbcs2;                                           //~v65gR~
        if (UDBCSCHK_DBCS2NDU(dbcsid))                             //~v65gR~
        {                                                          //~v65gR~
            if (Popt & UTFDDCMPO_SPLITINC0)                        //~v65gR~
                pdata2--,pdbcs2--,reslen2++;                       //~v65gR~
            else                                                   //~v65gR~
            if (Popt & UTFDDCMPO_SPLITEXC)                         //~v65gR~
                pdata2++,pdbcs2++,reslen2--;                       //~v65gR~
        }                                                          //~v65gR~
    }                                                              //~v65gI~
//*right side                                                      //~v65gI~
	dbcsid=*(Ppdbcs1+Plen-1);                                      //~v65gI~
    if (UDBCSCHK_DBCS1STU(dbcsid)) //dbcssplit                     //~v65gI~
    {                                                              //~v65gI~
    	if (Popt & UTFDDCMPO_SPLITINC1)                            //~v65gR~
            reslen1++;                                             //~v65gI~
        else                                                       //~v65gI~
	    if (Popt & UTFDDCMPO_SPLITEXC)                             //~v65gR~
            reslen1--;                                             //~v65gI~
    }                                                              //~v65gI~
    if (Ppdbcs2)                                                   //~v65gR~
    {                                                              //~v65gI~
        dbcsid=*(Ppdbcs2+Plen-1);                                  //~v65gR~
        if (UDBCSCHK_DBCS1STU(dbcsid)) //dbcssplit                 //~v65gR~
        {                                                          //~v65gR~
            if (Popt & UTFDDCMPO_SPLITINC2)                        //~v65gR~
                reslen2++;                                         //~v65gR~
            else                                                   //~v65gR~
            if (Popt & UTFDDCMPO_SPLITEXC)                         //~v65gR~
                reslen2--;                                         //~v65gR~
        }                                                          //~v65gR~
    }                                                              //~v65gI~
//  for (pdata1=Ppdata1,pdbcs1=Ppdbcs1,pdata2=Ppdata2,pdbcs2=Ppdbcs2,reslen1=reslen2=Plen;//~v65gR~
    for (;                                                         //~v65gI~
		reslen1>0 && reslen2>0;                                    //~v640R~
		pdata1+=chsz1,pdbcs1+=chsz1,pdata2+=chsz2,pdbcs2+=chsz2,reslen1-=chsz1,reslen2-=chsz2)//~v640R~
    {                                                              //~v640I~
        dbcsid=*pdbcs1;                                            //~v640I~
        chsz1=1;                                                   //~v640R~
		if (UDBCSCHK_ISUCSSBCS(dbcsid))                            //~v640I~
        	ucs1=(WUCS)UTF_GETUCSSBCS(pdata1,pdbcs1);              //~v640I~
        else                                                       //~v640I~
//  	if (reslen1>1 && UDBCSCHK_DBCS1STUCS2NWP(dbcsid))          //~v65gR~
    	if (UDBCSCHK_DBCS1STUCS2NWP(dbcsid))                       //~v65gI~
        {                                                          //~v640I~
          if (reslen1>1)                                           //~v65gR~
          {                                                        //~v65gI~
        	ucs1=UTF_GETUCSDBCS(pdata1);                           //~v640I~
            chsz1=2;                                               //~v640R~
          }                                                        //~v65gI~
          else                                                     //~v65gI~
//        if (Popt && UTFDDCMPO_SPLITSPACE)                        //~v65gR~//~v6K0R~
          if (Popt & UTFDDCMPO_SPLITSPACE)                         //~v6K0I~
          	ucs1=' ';                                              //~v65gI~
          else                                                     //~v65gI~
          	ucs1=*pdata1;   //anyway  2nd byte of ucs2             //~v65gI~
        }                                                          //~v640I~
        else                                                       //~v640I~
//#ifdef UTF8UCS4                                                    //~v65cI~//~v6uBR~
#ifdef UTF8UCS416                                                  //~v6uBI~
//  	if (reslen1>1 && UDBCSCHK_ISUCSOVF1ST(dbcsid))             //~v65gR~
    	if (UDBCSCHK_ISUCSOVF1ST(dbcsid))                          //~v65gI~
        {                                                          //~v65cI~
    	  if (reslen1>1)                                           //~v65gI~
          {                                                        //~v65gI~
            ucs1=UTF_GETUCSDBCSOVF(pdata1,pdbcs1);                 //~v65cI~
            chsz1=2;                                               //~v65cR~
          }                                                        //~v65gI~
          else                                                     //~v65gI~
//        if (Popt && UTFDDCMPO_SPLITSPACE)                        //~v65gR~//~v6K0R~
          if (Popt & UTFDDCMPO_SPLITSPACE)                         //~v6K0I~
          	ucs1=' ';                                              //~v65gI~
          else                                                     //~v65gI~
          	ucs1=((*pdbcs1 & UDBCSCHK_UCS4MASK1)<<8)|*pdata1;   //anyway  2nd byte of ucs2//~v65gI~
        }                                                          //~v65cI~
        else                                                       //~v65cI~
#endif                                                             //~v65cI~
        if (UDBCSCHK_DBCS2NDU(dbcsid))  //dbcs split               //~v65gI~
        {                                                          //~v65gI~
//        if (Popt && UTFDDCMPO_SPLITSPACE)                        //~v65gR~//~v6K0R~
          if (Popt & UTFDDCMPO_SPLITSPACE)                         //~v6K0I~
          	ucs1=' ';                                              //~v65gI~
          else                                                     //~v65gI~
//#ifdef UTF8UCS4                                                    //~v65gI~//~v6uBR~
#ifdef UTF8UCS416                                                  //~v6uBI~
          if (UDBCSCHK_ISUCSOVF2ND(dbcsid))                        //~v65gR~
          	ucs1=((*pdbcs1 & UDBCSCHK_UCS4MASK2)<<8)|*pdata1;   //anyway  2nd byte of ucs2//~v65gI~
          else                                                     //~v65gI~
#endif                                                             //~v65gI~
        	ucs1=*pdata1;                                          //~v65gI~
        }                                                          //~v65gI~
        else                                                       //~v65gI~
        	ucs1=*pdata1;                                          //~v640I~
//opd2                                                             //~v65gI~
        chsz2=1;                                                   //~v640I~
        if (Ppdbcs2)	//may be not ascii                         //~v640R~
        {                                                          //~v640I~
        	dbcsid=*pdbcs2;                                        //~v640I~
            if (UDBCSCHK_ISUCSSBCS(dbcsid))                        //~v640R~
                ucs2=(WUCS)UTF_GETUCSSBCS(pdata2,pdbcs2);          //~v640R~
            else                                                   //~v640R~
//          if (reslen2>1 && UDBCSCHK_DBCS1STUCS2NWP(dbcsid))      //~v65gR~
            if (UDBCSCHK_DBCS1STUCS2NWP(dbcsid))                   //~v65gI~
            {                                                      //~v640R~
              if (reslen2>1)                                       //~v65gI~
              {                                                    //~v65gI~
                ucs2=UTF_GETUCSDBCS(pdata2);                       //~v640R~
                chsz2=2;                                           //~v640R~
              }                                                    //~v65gI~
          	  else                                                 //~v65gI~
//            if (Popt && UTFDDCMPO_SPLITSPACE)                    //~v65gR~//~v6K0R~
              if (Popt & UTFDDCMPO_SPLITSPACE)                     //~v6K0I~
          	    ucs2=' ';                                          //~v65gI~
              else                                                 //~v65gI~
          	    ucs2=*pdata1;   //anyway  2nd byte of ucs2         //~v65gI~
            }                                                      //~v640R~
            else                                                   //~v640R~
//#ifdef UTF8UCS4                                                    //~v65cI~//~v6uBR~
#ifdef UTF8UCS416                                                  //~v6uBI~
//  		if (reslen2>1 && UDBCSCHK_ISUCSOVF1ST(dbcsid))         //~v65gR~
    		if (UDBCSCHK_ISUCSOVF1ST(dbcsid))                      //~v65gI~
        	{                                                      //~v65cI~
              if (reslen2>1)                                       //~v65gI~
              {                                                    //~v65gI~
            	ucs2=UTF_GETUCSDBCSOVF(pdata2,pdbcs2);             //~v65cI~
            	chsz2=2;                                           //~v65cR~
              }                                                    //~v65gI~
              else                                                 //~v65gI~
//            if (Popt && UTFDDCMPO_SPLITSPACE)                    //~v65gR~//~v6K0R~
              if (Popt & UTFDDCMPO_SPLITSPACE)                     //~v6K0I~
          	    ucs2=' ';                                          //~v65gI~
              else                                                 //~v65gI~
          	    ucs2=((*pdbcs2 & UDBCSCHK_UCS4MASK1)<<8)|*pdata2;   //anyway  2nd byte of ucs2//~v65gI~
        	}                                                      //~v65cI~
        	else                                                   //~v65cI~
#endif                                                             //~v65cI~
            if (UDBCSCHK_DBCS2NDU(dbcsid))  //dbcs split           //~v65gI~
            {                                                      //~v65gI~
//            if (Popt && UTFDDCMPO_SPLITSPACE)                    //~v65gR~//~v6K0R~
              if (Popt & UTFDDCMPO_SPLITSPACE)                     //~v6K0I~
          	    ucs2=' ';                                          //~v65gI~
//#ifdef UTF8UCS4                                                    //~v65gM~//~v6uBR~
#ifdef UTF8UCS416                                                  //~v6uBI~
              else                                                 //~v65gI~
              if (UDBCSCHK_ISUCSOVF2ND(dbcsid))                    //~v65gR~
          	    ucs2=((*pdbcs2 & UDBCSCHK_UCS4MASK2)<<8)|*pdata2;   //anyway  2nd byte of ucs2//~v65gI~
#endif                                                             //~v65gI~
              else                                                 //~v65gM~
        	    ucs2=*pdata2;                                      //~v65gR~
            }                                                      //~v65gM~
            else                                                   //~v65gR~
                ucs2=*pdata2;                                      //~v640R~
        }                                                          //~v640I~
        else                                                       //~v640I~
        	ucs2=*pdata2;                                          //~v640I~
                                                                   //~v640I~
        if (swnocase)                                              //~v640I~
        {                                                          //~v640I~
        	if (UTF8ISASCII(ucs1))                                 //~v640I~
            	ucs1=toupper(ucs1);                                //~v640I~
        	if (UTF8ISASCII(ucs2))                                 //~v640I~
            	ucs2=toupper(ucs2);                                //~v640R~
        }                                                          //~v640I~
        UTRACEP("ddcmp ucs1=%04x,ucs2=%04x\n",ucs1,ucs2);          //~v640I~
        if (ucs1>ucs2)                                             //~v640I~
        {                                                          //~v640I~
        	rc=1;                                                  //~v640I~
        	break;                                                 //~v640I~
        }                                                          //~v640I~
        else                                                       //~v640I~
        if (ucs1<ucs2)                                             //~v640I~
        {                                                          //~v640I~
        	rc=-1;                                                 //~v640I~
        	break;                                                 //~v640I~
        }                                                          //~v640I~
    }                                                              //~v640I~
    if (!rc)	//reached end of string                            //~v640I~
    {                                                              //~v640I~
    	if (reslen1>0)                                             //~v640I~
        	rc=1;                                                  //~v640I~
        else                                                       //~v640I~
    	if (reslen2>0)                                             //~v640I~
        	rc=-1;                                                 //~v640I~
    }                                                              //~v640I~
UTRACEP("utfddcmp opt=%x,rc=%d\n",Popt,rc);                        //~v640M~
    return rc;                                                     //~v640I~
}//utfddcmp                                                        //~v640I~
//*********************************************************************************//~v6umI~
//*ddstr compare,char by char ignorecase under the condition both has same length//~v6umI~
//*no high/low rc, return same=0 or unmatch=1                      //~v6umI~
//*********************************************************************************//~v6umI~
int utfddicmp(int Popt,UCHAR *Ppdata1,UCHAR *Ppdbcs1,UCHAR *Ppdata2,UCHAR *Ppdbcs2,int Plen)//~v6umI~
{                                                                  //~v6umI~
	UCHAR *pdata1,*pdbcs1,*pdata2,*pdbcs2;                         //~v6umI~
    int reslen,rc;                                                 //~v6umR~
//******************                                               //~v6umI~
UTRACED("inp data1",Ppdata1,Plen);                                 //~v6umI~
UTRACED("inp dbcs1",Ppdbcs1,Plen);                                 //~v6umI~
UTRACED("inp data2",Ppdata2,Plen);                                 //~v6umI~
UTRACED("inp dbcs2",Ppdbcs2,Plen);                                 //~v6umI~
    for (pdata1=Ppdata1,pdata2=Ppdata2,pdbcs1=Ppdbcs1,pdbcs2=Ppdbcs2,reslen=Plen;reslen>0;pdata1++,pdata2++,pdbcs1++,pdbcs2++,reslen--)//~v6umR~
    {                                                              //~v6umI~
        if (*pdbcs1!=*pdbcs2)                                      //~v6umI~
        	break;                                                 //~v6umI~
        if (*pdbcs1)	//not ascii                                //~v6umI~
        {                                                          //~v6umI~
	        if (*pdata1!=*pdata2)                                  //~v6umI~
    	    	break;                                             //~v6umI~
            continue;                                              //~v6umI~
        }                                                          //~v6umI~
        if (toupper(*pdata1)!=toupper(*pdata2))                    //~v6umI~
        	break;                                                 //~v6umI~
    }                                                              //~v6umI~
    rc=reslen!=0;                                                  //~v6umI~
UTRACEP("%s:rc=%d\n",UTT,rc);                                      //~v6umI~
    return rc;                                                     //~v6umI~
}//utfddicmp                                                       //~v6uLR~
//**************************************************               //~v640I~
//*get utf8 string from data/dbcs DDucs format                     //~v640R~
//*optionaly output dbcs by non ucs pattern                        //~v640I~
//*ret:1:ascii,2 loaderr data exist,4:split,8:dbcs seq err         //~v640R~
//**************************************************               //~v640I~
int utfcvdd2f(int Popt,UCHAR *Ppdata,int Plen,UCHAR *Ppdbcs,UCHAR *Ppout,int Pbuffsz,int *Ppoutlen,UCHAR *Ppoutdbcs)//~v640R~
{                                                                  //~v640I~
	UCHAR *pdata,*pdbcs,dbcsid,*pout,wku8[UTF8_MAXCHARSZMAX];      //~v640R~
	UCHAR *poutdbcs;                                               //~v640I~
    int reslen,chsz,rc=0,rc2,utf8len,outlen,resleno;               //~v640R~
    int errrepsw,errrepch;                                         //~v640I~
    ULONG ucs=0;                                                     //~v640I~//~v6h7R~
//  ULONG errucs;                                                  //~v65fI~//~v6b9R~
    int altch;                                                     //~v65iI~
//  int swdbcsspace;                                               //~v65mI~//~v6b9R~
#ifdef SSS                                                         //~v6DhI~
    int swdbcsspace;                                               //~v6DfI~
#endif                                                             //~v6DhI~
//******************                                               //~v640I~
UTRACED("utfcvdd2f inp data",Ppdata,Plen);                         //~v640R~
UTRACED("utfcvdd2f inp dbcs",Ppdbcs,Plen);                         //~v640R~
	errrepsw=Popt & UTFDD2FO_ERRREP;                               //~v640I~
    errrepch=Popt & UTFDD2FO_ERRREPCHMASK;                         //~v640I~
    if (!Ppout)                                                    //~v640I~
    	resleno=0xffff;                                            //~v640I~
    else                                                           //~v640I~
	if (Pbuffsz)                                                   //~v640I~
    	resleno=Pbuffsz;                                           //~v640I~
    else                                                           //~v640I~
    	resleno=0xffff;                                            //~v640I~
	for (pdata=Ppdata,pdbcs=Ppdbcs,pout=Ppout,reslen=Plen,poutdbcs=Ppoutdbcs;//~v640R~
		reslen>0 && resleno>0;                                     //~v640R~
		pdata+=chsz,pdbcs+=chsz,reslen-=chsz,poutdbcs+=chsz)       //~v640R~
    {                                                              //~v640I~
        chsz=1;                                                    //~v640I~
        dbcsid=*pdbcs;                                             //~v640I~
        rc2=0;                                                     //~v640I~
//      errucs=0;                                                  //~v65fI~//~v6b9R~
//      swdbcsspace=0;                                             //~v65mI~//~v6b9R~
#ifdef SSS                                                         //~v6DhI~
        swdbcsspace=0;                                             //~v6DfI~
#endif                                                             //~v6DhI~
    	if (UDBCSCHK_ISUCSSBCS(dbcsid))                            //~v640I~
        {                                                          //~v640I~
//      	ucs=(WUCS)UTF_GETUCSSBCS(pdata,pdbcs);                 //~v640I~//~v6B4R~
        	ucs=(ULONG)UTF_GETUCSSBCS(pdata,pdbcs);                //~v6B4I~
//*for windows all sbcs is ucs2                                    //~v6uBI~
        }                                                          //~v640I~
        else                                                       //~v640I~
        if (UDBCSCHK_ISUCSNP(dbcsid)                               //~v640I~
        &&  Popt & UTFDD2FO_VIO     //for vio,errdata              //~v640I~
    	)                                                          //~v640I~
        {                                                          //~v640I~
          ucs=*pdata; //errid                                      //~v65iI~
#ifdef AAA                                                         //~v6DbM~
          if (ucs<0x20)                                             //~v65iI~//~v65mR~
          {                                                        //~v65mI~
//  	  	if ((altch=UTF_GETALTCH_CTL(ucs))>0)                 //~v65iI~//~v65nR~//~v6B4R~
    	  	if ((altch=(int)UTF_GETALTCH_CTL((int)ucs))>0)         //~v6B4R~
//        		ucs=altch;                                             //~v65iI~//~v65mR~//~v6B4R~
          		ucs=(ULONG)altch;                                  //~v6B4I~
            chsz=1;                                                //~v65iI~
          }                                                        //~v65iI~
          else                                                     //~v65iI~
//        if (reslen>1                                             //~v65pR~
//        &&  UDBCSCHK_ISUCSNP1ST(dbcsid)                          //~v65pR~
//        &&  (errucs=UTF_GETUCSDBCS(pdata))==UC_DBCSSPACE         //~v65pR~
//        )                                                        //~v65pR~//~v6DbR~
          if (ucs==DEFAULT_ALTCH)                                  //~v65pI~
          {                                                        //~v65fI~
//          ucs=errucs;                                            //~v65pR~
//          chsz=2;                                                //~v65pI~
//          ucs=((altch=UTF_GETALTCH_DBCS())>0 ? altch:ucs);       //~v65pI~//~v6B4R~
            ucs=((altch=UTF_GETALTCH_DBCS())>0 ? (ULONG)altch:ucs);//~v6B4R~
            chsz=1;                                                //~v65pR~
          }                                                        //~v65fR~
#else                                                              //~v6DbI~
	#ifdef AAA                                                     //~v6DbI~
          if ((ucs==UDBCSCHK_ERRREPCH_NPUCS && UDBCSCHK_ISUCSNP1ST(dbcsid))//~v6DbI~
          ||  (ucs==UDBCSCHK_ERRREPCH_NPUCSW && UDBCSCHK_ISUCSNP2ND(dbcsid))//~v6DbI~
          )                                                        //~v6DbI~
          {                                                        //~v6DbI~
            UTRACEP("%s:vio ucsnp set by tabdisplay ucs=%04x,dbcsid=%02x\n",UTT,ucs,dbcsid);//~v6DbR~
          	chsz=1;                                                //~v6DbI~
          }                                                        //~v6DbI~
          else                                                     //~v6DbI~
          if ((altch=UTF_GETALTCH_SBCS(DEFAULT_UNPATTR))>0)        //~v6DbI~
          {                                                        //~v6DbI~
            UTRACEP("%s:vio ucsnp set altchar ucs=%04x,dbcsid=%02x,altch=%04x\n",UTT,ucs,dbcsid,altch);//~v6DbR~
            ucs=(ULONG)altch;	//errid                            //~v6DbR~
            chsz=1;                                                //~v6DbI~
          }                                                        //~v6DbI~
	#else                                                          //~v6DbI~
#ifdef SSS     //left ucs=ffff and dbcsid=()                       //~v6DhR~
      if (ucs==DEFAULT_ALTCH                                       //~v6DdI~
      &&  UDBCSCHK_ISUCSNP1ST(dbcsid)                              //~v6DdI~
      &&  reslen>1                                                 //~v6DdI~
      &&  *(pdata+1)==DEFAULT_ALTCH                                //~v6DdI~
      &&  UDBCSCHK_ISUCSNP2ND(*(pdbcs+1))                          //~v6DdI~
      &&  (altch=UTF_GETALTCH_DBCS())>0                            //~v6DdI~
      )                                                            //~v6DdI~
      {                                                            //~v6DdI~
#ifdef SSS                                                         //~v6DhI~
        swdbcsspace=1;                                             //~v6DfI~
#endif                                                             //~v6DhI~
        ucs=(ULONG)altch;                                          //~v6DdR~
        chsz=2;                                                    //~v6DdI~
      }                                                            //~v6DdI~
      else                                                         //~v6DdI~
#endif                                                             //~v6DhR~
      {                                                            //~v6DdI~
		ucs=utf22_setunpucsvio(0,ucs,dbcsid,0/*rc*/);              //~v6DbR~
        chsz=1;                                                    //~v6DbI~
      }                                                            //~v6DdI~
    #endif                                                         //~v6DbI~
#endif                                                             //~v6DbI~
	#ifdef AAA                                                     //~v6DbI~
          else                                                     //~v65fI~
          {                                                        //~v65fI~
            ucs=*pdata;	//errid                                    //~v640I~
            chsz=1;                                                //~v640I~
          }                                                        //~v65fR~
    #endif                                                         //~v6DbI~
        }                                                          //~v640I~
        else                                                       //~v640I~
    	if (UDBCSCHK_DBCS1STUCS2NWP(dbcsid))    //dbcs1st          //~v640R~
        {                                                          //~v640I~
        	if (reslen==1)	//split by EOL                         //~v640I~
                rc2=UTFDD2FRC_SPLITEOL;	                           //~v640R~
            else                                                   //~v640I~
            {                                                      //~v640I~
//      		ucs=UTF_GETUCSDBCS(pdata);                         //~v640I~//~v6B4R~
        		ucs=(ULONG)UTF_GETUCSDBCS(pdata);                  //~v6B4I~
            	chsz=2;                                            //~v640I~
#ifndef SSS     //left ucs=ffff and dbcsid=()                      //~v6DhR~
      			if (ucs==DBCSSPACE_ALT2                            //~v6DhI~
				&&  dbcsid==UDBCSCHK_DBCS1STUCS	//tabdisplay set ffff/() for dbcsspace//~v6DhI~
        		&&  Popt & UTFDD2FO_VIO     //for vio,errdata      //~v6DhI~
      			&&  (altch=UTF_GETALTCH_DBCS())>0                  //~v6DhI~
     			)                                                  //~v6DhI~
      			{                                                  //~v6DhI~
#ifdef SSS                                                         //~v6DhI~
        			swdbcsspace=1;                                 //~v6DhI~
#endif                                                             //~v6DhI~
        			ucs=(ULONG)altch;                              //~v6DhI~
      			}                                                  //~v6DhI~
#endif                                                             //~v6DhI~
            }                                                      //~v640I~
//#ifdef W32UNICODE                                                  //~4424R~//~v6uBR~
//            if (IS_UTF16_HIGH(ucs)                                 //~4424R~//~v6uBR~
//            &&  reslen>1                                           //~4424R~//~v6uBR~
//            &&  UDBCSCHK_DBCS1STUCS2NWP(*(pdbcs+2))    //dbcs1st   //~4424R~//~v6uBR~
//            )                                                      //~4424R~//~v6uBR~
//            {                                                      //~4424R~//~v6uBR~
//                UWCH u16L;                                         //~4424R~//~v6uBR~
//                u16L=UTF_GETUCSDBCS(pdata+2);                      //~4424R~//~v6uBR~
//                if (IS_UTF16_LOW(u16L))                            //~4424R~//~v6uBR~
//                {                                                  //~4424R~//~v6uBR~
//                    ucs=UTF16_TO_UCS4(ucs,u16L);                   //~4424R~//~v6uBR~
//                    chsz=4;                                        //~4424R~//~v6uBR~
//                }                                                  //~4424R~//~v6uBR~
//            }                                                      //~4424R~//~v6uBR~
//#endif                                                             //~4424R~//~v6uBR~
        }                                                          //~v640I~
        else                                                       //~v640I~
//#ifdef UTF8UCS4                                                    //~v65cI~//~v6uBR~
#ifdef UTF8UCS416                                                  //~v6uBI~
    	if (UDBCSCHK_ISUCSOVF1ST(dbcsid))                          //~v65cR~
        {                                                          //~v65cI~
        	if (reslen==1)	//split by EOL                         //~v65cI~
                rc2=UTFDD2FRC_SPLITEOL;                            //~v65cI~
            else                                                   //~v65cI~
            {                                                      //~v65cI~
//          	ucs=UTF_GETUCSDBCSOVF(pdata,pdbcs);                //~v65cI~//~v6B4R~
            	ucs=(ULONG)UTF_GETUCSDBCSOVF(pdata,pdbcs);         //~v6B4I~
        	  	if (Popt & UTFDD2FO_VIO)                           //~v6DbI~
					ucs=utf22_setunpucsvio(UT22SUUVO_OVF,ucs,dbcsid,0);//~v6DbR~
            	chsz=2;                                            //~v65cI~
            }                                                      //~v65cI~
        }                                                          //~v65cI~
        else                                                       //~v65cI~
#endif                                                             //~v65cI~
//#ifdef UTF8UCS4                                                    //~v65cI~//~v6uBR~
#ifdef UTF8UCS416                                                  //~v6uBI~
    	if (UDBCSCHK_DBCS2NDU(dbcsid))    //also for ucs2          //~v65cI~
#else                                                              //~v65cI~
    	if (UDBCSCHK_DBCS2NDUCS2NWP(dbcsid))    //dbcs split at TOL or invalid fmt//~v640I~
#endif                                                             //~v65cI~
        {                                                          //~v640I~
            if (pdata==Ppdata)                                     //~v640R~
    	    	rc2=UTFDD2FRC_SPLITTOL;                            //~v640I~
            else                                                   //~v640I~
	        	rc2=UTFDD2FRC_FMTERR;                              //~v640R~
        }                                                          //~v640I~
        else		//F2LERR or ascii                              //~v640I~
    	if (dbcsid==UDBCSCHK_F2LERR)                               //~v640R~
            rc2=UTFDD2FRC_F2LERR;                                  //~v640I~
        else                                                       //~v640I~
        {                                                          //~v65iI~
            rc2=UTFDD2FRC_ASCII;                                   //~v640I~
            ucs=*pdata; //errid                                    //~v65iI~
            if (!ucs &&  (Popt & UTFDD2FO_NULLALT))     //for gtkprint//~v6p2R~
            {                                                      //~v6p2I~
//  			if ((altch=UTF_GETALTCH_CTL(ucs))>0)               //~v6p2I~//~v6B4R~
    			if ((altch=(int)UTF_GETALTCH_CTL((int)ucs))>0)     //~v6B4R~
//              	ucs=altch;                                     //~v6p2I~//~v6B4R~
                	ucs=(ULONG)altch;                              //~v6B4I~
                else                                               //~v6p2I~
                	ucs='.';                                       //~v6p2I~
                rc2=0;                                             //~v6p2I~
            }                                                      //~v6p2I~
            else                                                   //~v6p2I~
            if (ucs<0x20)                                          //~v65iI~
            {                                                      //~v65iI~
//	        	if (Popt & UTFDD2UO_VIO)     //for screen write    //~v65iI~//~v6p2R~
  	        	if (Popt & UTFDD2FO_VIO)     //for screen write    //~v6p2I~
                {                                                  //~v6hpI~
                    if (!ucs)      //display space for null        //~v6hpI~
                    {                                              //~v6hpI~
                        ucs=' ';                                   //~v6hpI~
                        rc2=0;                                     //~v6hpI~
                    }                                              //~v6hpI~
                    else                                           //~v6hpI~
//  				if ((altch=UTF_GETALTCH_CTL(ucs))>0)           //~v65pR~//~v6B4R~
    				if ((altch=(int)UTF_GETALTCH_CTL((int)ucs))>0) //~v6B4R~
                    {                                              //~v65iI~
//                  	ucs=altch;                                 //~v65iI~//~v6B4R~
                    	ucs=(ULONG)altch;                          //~v6B4I~
                        rc2=0;  //translate to utf                 //~v65pR~
                    }                                              //~v65iI~
                }                                                  //~v6hpI~
            }                                                      //~v65iI~
        }                                                          //~v65iI~
                                                                   //~v640I~
        if (!rc2)                                                  //~v640I~
        {                                                          //~v640I~
//            utf8len=uccvucs2utf(ucs,wku8);                         //~v640R~//~v65mR~
//            resleno-=utf8len;                                      //~v640M~//~v65mR~
//            if (resleno<0)                                         //~v640R~//~v65mR~
//                break;                                             //~v640I~//~v65mR~
#ifdef AAA  //already processed                                    //~v65pI~
            if (ucs==UC_DBCSSPACE                                  //~v640I~
            &&  (Popt & UTFDD2FO_DBCSSPACEREP) //display dbcs space u3000 by alt char//~v640I~
			&&  (Guviomopt2 & UVIOMO2_PADON)                       //~v640I~
            )                                                      //~v640I~
            {                                                      //~v640I~
                if (Ppout)                                         //~v640I~
                {                                                  //~v640I~
//  			  if ((altch=utfgetvisiblealtch(0,Guviomoptstr[3]))>0)//~v65pR~
   			      if ((altch=Guviomoptstrucs[3])>0)                //~v65pR~
                  {                                                //~v65mI~
                  	ucs=altch;                                     //~v65mI~
					utf8len=uccvucs2utf(ucs,wku8);                 //~v65mI~
                	resleno-=utf8len+utf8len;                      //~v65mI~
                	if (resleno<0)                                 //~v65mI~
                    	break;                                     //~v65mI~
                    memcpy(pout,wku8,utf8len);                     //~v65mR~
                    pout+=utf8len;                                 //~v65mI~
                    memcpy(pout,wku8,utf8len);                     //~v65mI~
                    pout+=utf8len;                                 //~v65mI~
                  }                                                //~v65mI~
                  else                                             //~v65mI~
                  {                                                //~v65mI~
                	resleno-=2;                                    //~v65mI~
                	if (resleno<0)                                 //~v65mI~
                    	break;                                     //~v65mI~
                    *pout++=Guviomoptstr[3];                       //~v640I~
                    *pout++=Guviomoptstr[3];                       //~v640I~
                  }                                                //~v65mI~
                }                                                  //~v640I~
                if (Ppoutdbcs)                                     //~v640I~
                {                                                  //~v640I~
                	*poutdbcs=UDBCSCHK_HKDBCSERR;                  //~v640I~
                	*(poutdbcs+1)=UDBCSCHK_HKDBCSERR;              //~v640I~
                }                                                  //~v640I~
            }                                                      //~v640I~
            else                                                   //~v640I~
#endif                                                             //~v65pI~
            {                                                      //~v640I~
//              utf8len=uccvucs2utf(ucs,wku8);                     //~v65mI~//~v6BkR~
                utf8len=uccvucs2utf((UWUCS)ucs,wku8);              //~v6BkI~
                resleno-=utf8len;                                  //~v65mI~
                if (resleno<0)                                     //~v65mI~
                    break;                                         //~v65mI~
                if (Ppout)                                         //~v640R~
                    memcpy(pout,wku8,(UINT)utf8len);               //~v640R~
#ifdef SSS    //only 1 ucs is required for usetmonospace           //~v6DhI~
                if (swdbcsspace)                                   //~v6DfI~
                {                                                  //~v6DfI~
                	resleno-=utf8len;                              //~v6DfI~
                	if (resleno<0)                                 //~v6DfI~
                    	break;                                     //~v6DfI~
                    pout+=utf8len;                                 //~v6DfI~
	                if (Ppout)                                     //~v6DfI~
    	                memcpy(pout,wku8,(UINT)utf8len);           //~v6DfI~
                }                                                  //~v6DfI~
#endif                                                             //~v6DhI~
                if (Ppoutdbcs)                                     //~v640R~
                {                                                  //~v640R~
                    if (chsz==2)                                   //~v640R~
                    {                                              //~v640R~
                        *poutdbcs=UDBCSCHK_DBCS1ST;                //~v640R~
                        *(poutdbcs+1)=UDBCSCHK_DBCS2ND;            //~v640R~
                    }                                              //~v640R~
                    else                                           //~v640R~
                        *poutdbcs=0;                               //~v640R~
                }                                                  //~v640R~
                pout+=utf8len;                                     //~v640R~
                rc|=UTFDD2FRC_UCS;                                 //~v640R~
            }                                                      //~v640I~
        }                                                          //~v640I~
        else                                                       //~v640I~
        {                                                          //~v640I~
            if (Ppout)                                             //~v640I~
            {                                                      //~v640I~
        		if (rc2!=UTFDD2FRC_ASCII                           //~v640I~
                &&  errrepsw                                       //~v640R~
                &&  !(*pdata==UVIO_ERRREP && (Popt & UTFDD2FO_DUPREPCHK))//~v640I~
                )                                                  //~v640I~
//                  *pout++=errrepch;                              //~v640R~//~v6B3R~
                    *pout++=(UCHAR)errrepch;                       //~v6B3I~
                else                                               //~v640R~
                    *pout++=*pdata;                                //~v640R~
            }                                                      //~v640I~
            else                                                   //~v640I~
            	pout++;	//to calc outlength                        //~v640I~
            if (Ppoutdbcs)                                         //~v640R~
            {                                                      //~v640I~
        		if (rc2!=UTFDD2FRC_ASCII)                          //~v640R~
					*poutdbcs=UDBCSCHK_HKDBCSERR;                  //~v640R~
                else                                               //~v640I~
					*poutdbcs=0;                                   //~v640I~
            }                                                      //~v640I~
            resleno--;                                             //~v640I~
            rc|=rc2;                                               //~v640I~
        }                                                          //~v640I~
    }                                                              //~v640I~
//  outlen=(int)((ULONG)pout-(ULONG)Ppout);                        //~v640I~//~v6hhR~
    outlen=(int)((ULPTR)pout-(ULPTR)Ppout);                        //~v6hhI~
    *Ppoutlen=outlen;                                              //~v640I~
    if (resleno<0)                                                 //~v640I~
    	rc|=UTFDD2FRC_BUFFOVERFLOW;                                //~v640I~
    if (Popt & UTFDD2FO_OUTSTRZ) //      0x2000 //append null char //~v6E9I~
        if (Ppout)                                                 //~v6E9I~
            *(Ppout+outlen)=0;                                     //~v6E9I~
UTRACEDIFNZ("utfcvdd2f oututf8",Ppout,outlen);                     //~v640R~
UTRACEDIFNZ("utfcvdd2f outdbcs",Ppoutdbcs,Plen);                   //~v640R~
UTRACEP("utfcvdd2f rc=%d\n",rc);                                   //~v640I~
    return rc;                                                     //~v640I~
}//utfcvdd2f                                                       //~v640R~
//**************************************************               //~v640M~
//*chk source type                                                 //~v640M~
//*   utf8 file is ascii and ucs only, locale code file is locale code only//~v640M~
//*rc1:ucs data,0:locale data                                      //~v640M~
//**************************************************               //~v640M~
int utfchkdd(int Popt,UCHAR *Ppdbcs,int Plen)                      //~v640I~
{                                                                  //~v640M~
	UCHAR *pdbcs,dbcsid;                                           //~v640R~
    int reslen;                                                    //~v640M~
//******************                                               //~v640M~
UTRACED("utfchkdd dbcs",Ppdbcs,Plen);                              //~v640R~
	for (pdbcs=Ppdbcs,reslen=Plen;reslen>0;pdbcs++,reslen--)       //~v640M~
    {                                                              //~v640M~
    	dbcsid=*pdbcs;                                             //~v640I~
    	if (UDBCSCHK_ISUCSDBCST(dbcsid))                           //~v640R~
        {                                                          //~v65cI~
UTRACEP("utfchkdd rc=1 reslen=%d\n",reslen);                       //~v65cI~
        	return 1;                                              //~v640M~
        }                                                          //~v65cI~
    	if (UDBCSCHK_DBCSCHARS(dbcsid))//not dd fmt                //~v640R~
        {                                                          //~v65cI~
UTRACEP("utfchkdd rc=0 reslen=%d\n",reslen);                       //~v65cI~
        	return 0;                                              //~v640M~
        }                                                          //~v65cI~
    }                                                              //~v640M~
    return 0;	//no ucs2,all sbcs local string                    //~v640M~
}//utfchkdd                                                        //~v640I~
//**************************************************               //~v640I~
//*chk ddfmt/locale string is ascii                                //~v640I~
//*rc:1 allascii, -1:ddstr(option)                                 //~v640I~
//**************************************************               //~v640I~
int utfddisasciistr(int Popt,UCHAR *Pdata,UCHAR *Ppdbcs,int Plen)  //~v640R~
{                                                                  //~v640I~
	UCHAR *pdbcs,*pdata,dbcsid;                                    //~v640I~
    int reslen;                                                    //~v640I~
//******************                                               //~v640I~
	Sasciilen=0;                                                   //~v640I~
	for (pdata=Pdata,pdbcs=Ppdbcs,reslen=Plen;reslen>0;pdata++,pdbcs++,reslen--,Sasciilen++)//~v640R~
    {                                                              //~v640I~
        if (!UTF8ISASCII(*pdata))	//locale sbcs over 0x80        //~v640M~
          if (!(Popt & UTFDDIASO_M1RCIFDD))   //return -1 if ddstr //~v664I~
        	return 0;                                              //~v640M~
        if (Ppdbcs) //dbcs specified                               //~v640I~
        {                                                          //~v640I~
            dbcsid=*pdbcs;                                         //~v640R~
            if (UDBCSCHK_ISUCSDBCST(dbcsid))//ucs from utf8str     //~v640R~
            {                                                      //~v640R~
                if (Popt & UTFDDIASO_M1RCIFDD)   //return -1 if ddstr//~v640R~
                    return -1;                                     //~v640R~
                else                                               //~v640R~
                    return 0;                                      //~v640R~
            }                                                      //~v640R~
            if (UDBCSCHK_DBCSCHARS(dbcsid))//locale dbcs           //~v640R~
                return 0;                                          //~v640R~
        }                                                          //~v640I~
    }                                                              //~v640I~
    return 1;	//all ascii                                        //~v640I~
}//utfddisasciistr                                                 //~v640R~
//**************************************************               //~v667I~
//*chk ddfmt/locale string is ascii                                //~v667I~
//*rc:1 allascii, -1:ddstr(option)                                 //~v667I~
//**************************************************               //~v667I~
int utfddissbcsstr(int Popt,UCHAR *Pdata,UCHAR *Ppdbcs,int Plen)   //~v667I~
{                                                                  //~v667I~
	UCHAR *pdbcs,*pdata,dbcsid;                                    //~v667I~
    int reslen;                                                    //~v667I~
//******************                                               //~v667I~
	for (pdata=Pdata,pdbcs=Ppdbcs,reslen=Plen;reslen>0;pdata++,pdbcs++,reslen--)//~v667I~
    {                                                              //~v667I~
        dbcsid=*pdbcs;                                             //~v667I~
		if (dbcsid && !UDBCSCHK_ISUCSSBCS(dbcsid))//also for locale/ebc str//~v667R~
        	return 0;                                              //~v667I~
    }                                                              //~v667I~
    return 1;	//all ascii                                        //~v667I~
}//utfddissbcsstr                                                  //~v667R~
//**************************************************               //~v640I~
//*return ascii string length (no null term chk)                   //~v640I~
//**************************************************               //~v640I~
int utfddasciilen(int Popt,UCHAR *Pdata,UCHAR *Ppdbcs,int Plen)    //~v640I~
{                                                                  //~v640I~
//******************                                               //~v640I~
	utfddisasciistr(Popt,Pdata,Ppdbcs,Plen);                       //~v640I~
    return Sasciilen;                                              //~v640R~
}//utfddasciilen                                                   //~v640I~
//**************************************************               //~v640I~
//get hex offset for ddstr                                         //~v640I~
//rc:8:Ppos is out of range,4:eol,1:ucs split,0:ok                 //~v640R~
//**************************************************               //~v640I~
int utfddpos2offs(int Popt,char *Pdata,char *Pdbcs,int Plen,int Ppos,int *Ppoffs)//~v640I~
{                                                                  //~v640I~
    int pos,xoffs,xstep=0,cstep,rc;                                //~v6h4R~
    UCHAR *pc,*pdbcs,dbcsid;                                       //~v640R~
#ifdef UTF8UCS4                                                    //~v65cI~
//*all sbcs is UCS2(all UCS4 is OVF when UTF8UTF16)                //~v6uBI~
	WUCS ucs;                                                      //~v65cI~
#endif                                                             //~v65cI~
//****************************                                     //~v640I~
    for (pc=Pdata,pdbcs=Pdbcs,pos=xoffs=0;                         //~v640R~
			pos<Ppos && pos<Plen;                                  //~v640R~
			pos+=cstep,pdbcs+=cstep,pc+=cstep)                     //~v640R~
    {                                                              //~v640I~
    	dbcsid=*pdbcs;                                             //~v640I~
    	if (UDBCSCHK_ISUCSDBCST(dbcsid))	//not ascii,not f2l err//~v640R~
        {                                                          //~v640I~
//#ifdef UTF8UCS4                                                    //~v65cM~//~v6uBR~
#ifdef UTF8UCS416                                                  //~v6uBI~
	      if (UDBCSCHK_ISUCSOVF1ST(dbcsid))	//1byte on pdata       //~v65cI~
            xstep=3;                                               //~v65cI~
          else                                                     //~v65cI~
#endif                                                             //~v65cM~
        	xstep=2;                                               //~v640I~
	    	if (UDBCSCHK_ISUCSSBCS(dbcsid))	//1byte on pdata       //~v640R~
            {                                                      //~v65cI~
#ifdef UTF8UCS4                                                    //~v65cI~
//*all sbcs is UCS2(all UCS4 is OVF when UTF8UTF16)                //~v6uBI~
//        		ucs=UTF_GETUCSSBCS(pc,pdbcs);                      //~v65cI~//~v6B4R~
          		ucs=(WUCS)UTF_GETUCSSBCS(pc,pdbcs);                //~v6B4I~
            	if (ucs>>16)                                       //~v65cI~
		            xstep=3;                                       //~v65cI~
#endif                                                             //~v65cI~
            	cstep=1;                                           //~v640I~
            }                                                      //~v65cI~
            else                                                   //~v640I~
            	cstep=2;                                           //~v640I~
        }                                                          //~v640I~
        else                                                       //~v640I~
        	xstep=cstep=1;                                         //~v640I~
        xoffs+=xstep;                                              //~v640I~
    }                                                              //~v640I~
    if (pos>Ppos)                                                  //~v640R~
    {                                                              //~v640I~
    	rc=1;	//split ucs                                        //~v640I~
	  if (!(Popt & UTFDDP2OO_NEXT))    //if split apply next ucs   //~v6uLI~
        xoffs-=xstep;                                              //~v640I~
    }                                                              //~v640I~
    else                                                           //~v640I~
    	rc=0;                                                      //~v640I~
    if (Ppos>=Plen)                                                //~v640R~
    {                                                              //~v640I~
        xoffs+=Ppos-Plen;                                          //~v640R~
		if (Ppos>Plen)                                             //~v640I~
    	    rc=8;                                                  //~v640I~
        else                                                       //~v640I~
        	rc=4;                                                  //~v640I~
    }                                                              //~v640I~
    *Ppoffs=xoffs;                                                 //~v640I~
UTRACEP("utfddpos2offs rc=%d,pos=%d,offs=%d\n",rc,Ppos,xoffs);     //~v640I~
UTRACED("pdbcs",Pdbcs,Plen);                                       //~v640I~
    return rc;                                                     //~v640I~
}//utfddpos2offs                                                   //~v640I~
//**************************************************               //~v640I~
//get char position from hex offset for ddstr                      //~v640I~
//Plen:total                                                       //~v640I~
//Poffs:offs from initpos                                          //~v640I~
//rc:4:just lineend,8:outof range, 1:ucs split, 0:ok               //~v640R~
#ifdef UTF8UCS4                                                    //~v65cI~
//   2:point last byte of ucs4(3byte)                              //~v65cI~
#endif                                                             //~v65cI~
//**************************************************               //~v640I~
int utfddoffs2pos(int Popt,char *Pdata,char *Pdbcs,int Plen,int Poffs,int *Pppos)//~v640I~
{                                                                  //~v640I~
    int pos,xoffs,xstep,cstep,rc=0,offslimit,endpos;               //~v640R~
    UCHAR *pc,*pdbcs,dbcsid;                                       //~v640I~
#ifdef UTF8UCS4                                                    //~v65cI~
//*all sbcs is UCS2(all UCS4 is OVF when UTF8UTF16)                //~v6uBI~
    WUCS ucs;                                                      //~v65cI~
#endif                                                             //~v65cI~
//****************************                                     //~v640I~
    pc=Pdata;                                                      //~v640I~
	pdbcs=Pdbcs;                                                   //~v640I~
	pos=xoffs=0;                                                   //~v640I~
    offslimit=Poffs;                                               //~v640I~
    endpos=Plen;                                                   //~v640I~
	if (Popt & UTFDDO2PO_INITPOS)   //input start position on Pppos//~v640I~
    {                                                              //~v640I~
    	pos=*Pppos;                                                //~v640I~
        if (pos)                                                   //~v640I~
        {                                                          //~v640I~
            pc+=pos;                                               //~v640I~
            pdbcs+=pos;                                            //~v640I~
            dbcsid=*pdbcs;                                         //~v640I~
//#ifdef UTF8UCS4                                                    //~v65cI~//~v6uBR~
#ifdef UTF8UCS416                                                  //~v6uBI~
            if (UDBCSCHK_DBCS2NDU(dbcsid))   //also for ucs2       //~v65cI~
#else                                                              //~v65cI~
            if (UDBCSCHK_DBCS2NDUCS2NWP(dbcsid))   //left boundary is split ucs//~v640R~
#endif                                                             //~v65cI~
            {                                                      //~v640I~
                pc--;                                              //~v640I~
                pdbcs--;                                           //~v640I~
                offslimit++;                                       //~v640I~
                pos--;                                             //~v640I~
            }                                                      //~v640I~
        }                                                          //~v640I~
    }                                                              //~v640I~
    if (offslimit>0)                                               //~v640R~
        for (;pos<endpos;pos+=cstep,pdbcs+=cstep,pc+=cstep)        //~v640R~
        {                                                          //~v640R~
            dbcsid=*pdbcs;                                         //~v640R~
            if (UDBCSCHK_ISUCSDBCST(dbcsid))    //not ascii,not f2l err//~v640R~
            {                                                      //~v640R~
//#ifdef UTF8UCS4                                                    //~v65cM~//~v6uBR~
#ifdef UTF8UCS416                                                  //~v6uBI~
	    	  if (UDBCSCHK_ISUCSOVF1ST(dbcsid))	//1byte on pdata   //~v65cI~
            	xstep=3;                                           //~v65cI~
              else                                                 //~v65cI~
#endif                                                             //~v65cM~
                xstep=2;                                           //~v640R~
                if (UDBCSCHK_ISUCSSBCS(dbcsid)) //1byte on pdata   //~v640R~
                {                                                  //~v65cI~
#ifdef UTF8UCS4                                                    //~v65cI~
//*all sbcs is UCS2(all UCS4 is OVF when UTF8UTF16)                //~v6uBI~
//        			ucs=UTF_GETUCSSBCS(pc,pdbcs);                  //~v65cI~//~v6B4R~
          			ucs=(WUCS)UTF_GETUCSSBCS(pc,pdbcs);            //~v6B4I~
            		if (UTF_ISUCS4(ucs))                           //~v65cR~
		            	xstep=3;                                   //~v65cI~
#endif                                                             //~v65cI~
                    cstep=1;                                       //~v640R~
                }                                                  //~v65cI~
                else                                               //~v640R~
                    cstep=2;                                       //~v640R~
            }                                                      //~v640R~
            else                                                   //~v640R~
                xstep=cstep=1;                                     //~v640R~
            xoffs+=xstep;                                          //~v640R~
            if (xoffs<offslimit)                                   //~v640R~
                continue;                                          //~v640R~
            if (xoffs==offslimit)                                  //~v640R~
                pos+=cstep;                                        //~v640R~
            else                                                   //~v640R~
//#ifdef UTF8UCS4                                                    //~v65cI~//~v6uBR~
#ifdef UTF8UCS416                                                  //~v6uBI~
            if (xstep==3   //UCS4                                  //~v65cI~
            &&  (xoffs-1)==offslimit                               //~v65cI~
            )                                                      //~v65cI~
                rc=2;  //last byte of 3byte ucs4                   //~v65cI~
            else                                                   //~v65cI~
#endif                                                             //~v65cI~
                rc=1;   //split                                    //~v640R~
            break;                                                 //~v640R~
        }                                                          //~v640R~
    if (xoffs<offslimit)                                           //~v640R~
    {                                                              //~v640I~
        pos=endpos+offslimit-xoffs;                                //~v640I~
    	rc=8;	//out of range                                     //~v640R~
    }                                                              //~v640I~
    else                                                           //~v640I~
    if (pos==endpos)                                               //~v640I~
    	rc=4;                                                      //~v640I~
    *Pppos=pos;	//pos from 0                                       //~v640R~
UTRACEP("utfddxoffs2pos rc=%d,pos=%d<==xoffs=%d\n",rc,pos,Poffs);  //~v640I~
UTRACED("pdbcs",Pdbcs,Plen);                                       //~v640I~
    return rc;                                                     //~v640I~
}//utfddoffs2pos                                                   //~v640R~
//**************************************************               //~v640I~
//!chk punctuation for dd fmt                                      //~v640I~
//*ret  :1:puctuation,2:dbcs punctuation                           //~v640R~
//**************************************************               //~v640I~
int utfddispunct(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen)      //~v640I~
{                                                                  //~v640I~
    int rc=0,dbcsid,dbcssw;                                        //~v640R~
    WUCS ucs;                                                      //~v640I~
    UCHAR ucsbe[2];                                                //~v640I~
//*********************************                                //~v640I~
    UTRACED("utfddispunct data",Pdata,Plen);                       //~v640I~
    UTRACED("utfddispunct dbcs",Pdbcs,Plen);                       //~v640I~
    dbcsid=*Pdbcs;                                                 //~v640I~
    if(!dbcsid)	//ascii                                            //~v640I~
    {                                                              //~v640I~
        if (                                                       //~v640I~
		  uispunct(0,*Pdata)  //space is fales by ispunct,so uispunct//~v640R~
        )                                                          //~v640I~
        	rc=1;                                                  //~v640I~
    }                                                              //~v640I~
    else                                                           //~v68fI~
    if(*Pdata==' ' && (dbcsid==UDBCSCHK_TABCHAR||dbcsid==UDBCSCHK_TABPADCHAR))	//ascii//~v68fR~
    {                                                              //~v68fI~
        rc=1;                                                      //~v68fI~
    }                                                              //~v68fI~
    else                                                           //~v640I~
    {                                                              //~v640I~
        if (UDBCSCHK_ISUCSSBCS(dbcsid)) //                         //~v640I~
        {                                                          //~v640I~
            ucs=(WUCS)UTF_GETUCSSBCS(Pdata,Pdbcs);                 //~v640R~
	        UTF_SETUCSBESTR(ucs,ucsbe);                            //~v640I~
            dbcssw=0;                                              //~v640I~
        }                                                          //~v640I~
        else                                                       //~v640I~
        if (UDBCSCHK_DBCS1STUCS2NWP(dbcsid)) //dbcs 1st byte       //~v640I~
        {                                                          //~v640I~
            if (Plen<2)                                            //~v640I~
                return 0;                                          //~v640I~
            memcpy(ucsbe,Pdata,2);                                 //~v640R~
            dbcssw=1;                                              //~v640I~
        }                                                          //~v640I~
        else                                                       //~v640I~
//#ifdef UTF8UCS4                                                    //~v65cI~//~v6uBR~
#ifdef UTF8UCS416                                                  //~v6uBI~
    	if (UDBCSCHK_ISUCSOVF1ST(dbcsid))                          //~v65cR~
        	return 0;                                              //~v65cI~
        else                                                       //~v65cI~
#endif                                                             //~v65cI~
        if (*Pdata==' '||!*Pdata)                                  //~v640I~
        {                                                          //~v663I~
          	if (dbcsid)                                            //~v663I~
            	return 0;                                          //~v663I~
        	return 1;	         //may be TAB                      //~v640I~
        }                                                          //~v663I~
        else                                                       //~v640I~
        	return 0;                                              //~v640I~
        rc=uispunctdbcs(UISP_UCS2,ucsbe);                          //~v640R~
        if (rc)                                                    //~v640I~
        	rc+=dbcssw;                                            //~v640I~
    }                                                              //~v640I~
    UTRACEP("utfddispunct rc=%d\n",rc);                            //~v640I~
    return rc;                                                     //~v640I~
}//*utfddispunct                                                   //~v640I~
//***************************************************************  //~v640M~
//memspnc                                                          //~v640I~
// count continued char length                                     //~v640I~
//***************************************************************  //~v640I~
int utfddmemspnc(int Popt,char *Pdata,char *Pdbcs,int Pch,int Plen)//~v640I~
{                                                                  //~v640I~
    int ctr,reslen,dbcsid;                                         //~v640I~
    UCHAR *pc,*pcd;                                                //~v640I~
//****************************                                     //~v640I~
    for (pc=Pdata,pcd=Pdbcs,reslen=Plen,ctr=0;reslen>0;pc++,pcd++,reslen--,ctr++)//~v640I~
    {                                                              //~v640I~
    	dbcsid=*pcd;                                               //~v640I~
    	if (UDBCSCHK_ISUCSDBCST(dbcsid))	//not ascii,not f2l err//~v640I~
        	break;                                                 //~v640I~
        if (*pc!=Pch)                                              //~v640I~
        	break;                                                 //~v640I~
    }                                                              //~v640I~
    return ctr;                                                    //~v640I~
}//utfddmemspnc                                                    //~v640I~
//***************************************************************  //~v640I~
//memrspnc                                                         //~v640I~
// count continued char length                                     //~v640I~
//***************************************************************  //~v640I~
int utfddmemrspnc(int Popt,char *Pdata,char *Pdbcs,int Pch,int Plen)//~v640R~
{                                                                  //~v640I~
    int ctr,reslen,dbcsid;                                         //~v640R~
    UCHAR *pc,*pcd;                                                //~v640I~
//****************************                                     //~v640I~
    for (pc=Pdata+Plen-1,pcd=Pdbcs+Plen-1,reslen=Plen-1,ctr=0;reslen>=0;pc--,pcd--,reslen--,ctr++)//~v640R~
    {                                                              //~v640I~
    	dbcsid=*pcd;                                               //~v640I~
    	if (UDBCSCHK_ISUCSDBCST(dbcsid))	//not ascii,not f2l err//~v640I~
        	break;                                                 //~v640I~
        if (*pc!=Pch)                                              //~v640I~
        	break;                                                 //~v640I~
    }                                                              //~v640I~
    return ctr;                                                    //~v640I~
}//utfddmemrspnc                                                   //~v640R~
//*******************************************************          //~v640I~
//*strnlen                                                         //~v640I~
//* get length with max length                                     //~v640I~
//******************************************************           //~v640I~
int utfddstrnlen(int Popt,char *Pbuff,char *Pdbcs,int Plen)        //~v640I~
{                                                                  //~v640I~
	char *pc,*pc2;                                                 //~v640R~
	int  offs,reslen;                                              //~v640I~
//******************                                               //~v640I~
	for (pc=Pbuff;;)                                               //~v640I~
    {                                                              //~v640I~
//      reslen=Plen-((ULONG)pc-(ULONG)Pbuff);                      //~v640I~//~v6hhR~
//      reslen=Plen-((ULPTR)pc-(ULPTR)Pbuff);                      //~v6hhI~//~v6B4R~
        reslen=(int)((ULONG)Plen-((ULPTR)pc-(ULPTR)Pbuff));        //~v6B4I~
        if (reslen<=0)                                             //~v640I~
        	return Plen;                                           //~v640I~
//      offs=(ULONG)pc-(ULONG)Pbuff;                               //~v640I~//~v6hhR~
//      offs=(ULPTR)pc-(ULPTR)Pbuff;                               //~v6hhI~//~v6B4R~
        offs=(int)((ULPTR)pc-(ULPTR)Pbuff);                        //~v6B4I~
    	pc2=utfddmemchr(0,pc,Pdbcs+offs,0,reslen);                 //~v640R~
        if (!pc2)                                                  //~v640I~
        	return Plen;                                           //~v640I~
//      offs=(ULONG)pc2-(ULONG)Pbuff;                              //~v640I~//~v6hhR~
//      offs=(ULPTR)pc2-(ULPTR)Pbuff;                              //~v6hhI~//~v6B4R~
        offs=(int)((ULPTR)pc2-(ULPTR)Pbuff);                       //~v6B4I~
        if (!*(Pdbcs+offs))                                        //~v640I~
        	break;                                                 //~v640I~
        pc=pc2+1;                                                  //~v640I~
    }                                                              //~v640I~
    return offs;                                                   //~v640I~
}//utfddstrnlen                                                    //~v640I~
//*******************************************************          //~v640I~
//*strlen                                                          //~v640I~
//* get dd str length                                              //~v640I~
//******************************************************           //~v640I~
int utfddstrlen(int Popt,char *Pbuff,char *Pdbcs)                  //~v640I~
{                                                                  //~v640I~
	char *pc,*pcd;                                                 //~v640I~
	int  offs=0,pos;                                               //~v640I~
//******************                                               //~v640I~
	for (pc=Pbuff,pcd=Pdbcs;;pc++,pcd++)                           //~v640R~
    {                                                              //~v640I~
//  	pos=strlen(pc);                                            //~v640I~//~v6B4R~
    	pos=(int)strlen(pc);                                       //~v6B4I~
        pc+=pos;                                                   //~v640I~
        pcd+=pos;                                                  //~v640I~
        if (!*pcd)                                                 //~v640R~
        	break;                                                 //~v640I~
    }                                                              //~v640I~
//  offs=(ULONG)pc-(ULONG)Pbuff;                                   //~v640I~//~v6hhR~
//  offs=(ULPTR)pc-(ULPTR)Pbuff;                                   //~v6hhI~//~v6B4R~
    offs=(int)((ULPTR)pc-(ULPTR)Pbuff);                            //~v6B4I~
    return offs;                                                   //~v640I~
}//utfddstrlen                                                     //~v640I~
//*******************************************************          //~v640I~
//*ustrnspn                                                        //~v640I~
//* search first char which is not on parm2 string                 //~v640I~
//* return:offset to the last char,length if all match             //~v640I~
//******************************************************           //~v640I~
int utfddstrnspn(int Popt,char *Pbuff,char *Pdbcs,char *Pxstr,int Plen)//~v640I~
{                                                                  //~v640I~
//******************                                               //~v640I~
    if (Plen<=0)                                                   //~v640I~
    	return 0;                                                  //~v640I~
    Plen=utfddstrnlen(0,Pbuff,Pdbcs,Plen);                         //~v640R~
    if (!Plen)                                                     //~v640I~
    	return 0;                                                  //~v640I~
	return utfddmemspn(Popt,Pbuff,Pdbcs,Pxstr,Plen);               //~v640R~
}//utfddstrnspn                                                    //~v640I~
//*******************************************************          //~v640I~
//*umemspn                                                         //~v664R~
//* search first char which is not on parm2 string                 //~v640I~
//* return:offset to the last char,length if all match             //~v640I~
//******************************************************           //~v640I~
int utfddmemspn(int Popt,char *Pbuff,char *Pdbcs,char *Pxstr,int Plen)//~v640I~
{                                                                  //~v640I~
	char *pcb,*pcd;                                                //~v640I~
	int lenb,lenk,span=0,dbcsid;                                   //~v640I~
//******************                                               //~v640I~
    if (Plen<=0)                                                   //~v640R~
    	return 0;                                                  //~v640I~
//  lenk=strlen(Pxstr);                                            //~v640I~//~v6B4R~
    lenk=(int)strlen(Pxstr);                                       //~v6B4I~
    lenb=Plen;                                                     //~v640I~
	pcb=Pbuff;                                                     //~v640I~
	pcd=Pdbcs;                                                     //~v640I~
	while(lenb)                                                    //~v640I~
	{                                                              //~v640I~
    	dbcsid=*pcd;                                               //~v640I~
    	if (UDBCSCHK_ISUCSDBCST(dbcsid))	//not ascii,not f2l err//~v640I~
        	break;                                                 //~v640I~
//  	if (!memchr(Pxstr,*pcb,lenk))		//not found            //~v640I~//~v6B4R~
    	if (!memchr(Pxstr,*pcb,(size_t)lenk))		//not found    //~v6B4I~
			break;                                                 //~v640I~
		lenb--;                                                    //~v640I~
		pcb++;                                                     //~v640I~
		pcd++;                                                     //~v640I~
        span++;                                                    //~v640I~
	}                                                              //~v640I~
	return span;                                                   //~v640I~
}//utfddmemspn                                                     //~v640I~
//***************************************************************  //~v640I~
//memrspn                                                          //~v640I~
// search ascii char not on parm string by reverse direction       //~v640I~
//***************************************************************  //~v640I~
int utfddmemrspn(int Popt,char *Pbuff,char *Pdbcs,char *Pxstr,int Plen)//~v640I~
{                                                                  //~v640I~
	char *pcb,*pcd;                                                //~v640I~
	int lenb,lenk,span=0,dbcsid;                                   //~v640R~
//******************                                               //~v640I~
//  lenk=strlen(Pxstr);                                            //~v640I~//~v6B4R~
    lenk=(int)strlen(Pxstr);                                       //~v6B4I~
    lenb=Plen;                                                     //~v640I~
	pcb=Pbuff+lenb-1;		//last char                            //~v640I~
	pcd=Pdbcs+lenb-1;		//last char                            //~v640I~
	while(lenb)                                                    //~v640I~
	{                                                              //~v640I~
    	dbcsid=*pcd;                                               //~v640I~
    	if (UDBCSCHK_ISUCSDBCST(dbcsid))	//not ascii,not f2l err//~v640I~
        	break;                                                 //~v640I~
//  	if (!memchr(Pxstr,*pcb,lenk))		//not found            //~v640I~//~v6B4R~
    	if (!memchr(Pxstr,*pcb,(size_t)lenk))		//not found    //~v6B4I~
			break;                                                 //~v640I~
		lenb--;                                                    //~v640I~
		pcb--;                                                     //~v640I~
		pcd--;                                                     //~v640I~
        span++;                                                    //~v640I~
	}                                                              //~v640I~
	return span;                                                   //~v640I~
}//utfddmemrspn                                                    //~v640I~
//***************************************************************  //~v640I~
//memchr                                                           //~v640R~
// search ascii char                                               //~v640R~
//***************************************************************  //~v640I~
char *utfddmemchr(int Popt,char *Pdata,char *Pdbcs,int Pch,int Plen)//~v640R~
{                                                                  //~v640I~
    int span,reslen,dbcsid;                                        //~v640I~
    UCHAR *pc,*pcd,*pc2;                                           //~v640R~
//****************************                                     //~v640I~
    for (pc=Pdata,pcd=Pdbcs,reslen=Plen;reslen>=0;reslen-=span,pc+=span,pcd+=span)//~v640I~
    {                                                              //~v640I~
        pc2=memchr(pc,Pch,(UINT)reslen);                           //~v640I~
        if (!pc2)                                                  //~v640I~
            return 0;                                              //~v640R~
//      span=(int)((ULONG)pc2-(ULONG)pc);                          //~v640I~//~v6hhR~
        span=(int)((ULPTR)pc2-(ULPTR)pc);                          //~v6hhI~
        dbcsid=*(pcd+span);                                        //~v640I~
    	if (!UDBCSCHK_ISUCSDBCST(dbcsid))                          //~v640R~
        	return pc2;                                            //~v640R~
        span++;                                                    //~v640I~
    }                                                              //~v640I~
    return 0;                                                      //~v640R~
}//utfddmemchar                                                    //~v640R~
//***************************************************************  //~v667I~
//memchr                                                           //~v667I~
// search sbcs char                                                //~v667I~
//***************************************************************  //~v667I~
char *utfddmemchr_nonascii(int Popt,char *Pdata,char *Pdbcs,int Pch,int Pdbcsid,int Plen)//~v667I~
{                                                                  //~v667I~
    int span,reslen;                                               //~v667R~
    UCHAR *pc,*pcd,*pc2;                                           //~v667I~
//****************************                                     //~v667I~
    for (pc=Pdata,pcd=Pdbcs,reslen=Plen;reslen>=0;reslen-=span,pc+=span,pcd+=span)//~v667I~
    {                                                              //~v667I~
        pc2=memchr(pc,Pch,(UINT)reslen);                           //~v667I~
        if (!pc2)                                                  //~v667I~
            return 0;                                              //~v667I~
//      span=(int)((ULONG)pc2-(ULONG)pc);                          //~v667I~//~v6hhR~
        span=(int)((ULPTR)pc2-(ULPTR)pc);                          //~v6hhI~
        if (*(pcd+span)==Pdbcsid)                                  //~v667I~
        	return pc2;                                            //~v667I~
        span++;                                                    //~v667I~
    }                                                              //~v667I~
    return 0;                                                      //~v667I~
}//utfddmemchr_nonascii                                            //~v667I~
//***************************************************************  //~v640I~
//memrchr                                                          //~v640I~
// search ascii char reverse                                       //~v640I~
//***************************************************************  //~v640I~
char *utfddmemrchr(int Popt,char *Pdata,char *Pdbcs,int Pch,int Plen)//~v640I~
{                                                                  //~v640I~
    int dbcsid;                                                    //~v640I~
    UCHAR *pc;                                                     //~v640R~
//****************************                                     //~v640I~
	for (pc=Pdata+Plen-1;pc>=(UCHAR*)Pdata;pc--)                   //~v640I~
    {                                                              //~v640I~
    	if (*pc==Pch)                                              //~v640I~
        {                                                          //~v640I~
//      	dbcsid=*(Pdbcs+(ULONG)pc-(ULONG)Pdata);                //~v640I~//~v6hhR~
        	dbcsid=*(Pdbcs+(ULPTR)pc-(ULPTR)Pdata);                //~v6hhI~
    		if (!UDBCSCHK_ISUCSDBCST(dbcsid))                      //~v640I~
        		return pc;                                         //~v640I~
        }                                                          //~v640I~
	}                                                              //~v640I~
    return 0;                                                      //~v640I~
}//utfddmemrchr                                                    //~v667R~
//***************************************************************  //~v667I~
//memrchr                                                          //~v667I~
// search ascii char reverse                                       //~v667I~
//***************************************************************  //~v667I~
char *utfddmemrchr_nonascii(int Popt,char *Pdata,char *Pdbcs,int Pch,int Pdbcsid,int Plen)//~v667I~
{                                                                  //~v667I~
    int dbcsid;                                                    //~v667I~
    UCHAR *pc;                                                     //~v667I~
//****************************                                     //~v667I~
	for (pc=Pdata+Plen-1;pc>=(UCHAR*)Pdata;pc--)                   //~v667I~
    {                                                              //~v667I~
    	if (*pc==Pch)                                              //~v667I~
        {                                                          //~v667I~
//      	dbcsid=*(Pdbcs+(ULONG)pc-(ULONG)Pdata);                //~v667I~//~v6hhR~
        	dbcsid=*(Pdbcs+(ULPTR)pc-(ULPTR)Pdata);                //~v6hhI~
	        if (dbcsid==Pdbcsid)                                   //~v667I~
        		return pc;                                         //~v667I~
        }                                                          //~v667I~
	}                                                              //~v667I~
    return 0;                                                      //~v667I~
}//utfddmemrchr_nonascii                                           //~v667I~
//***************************************************************  //~v640I~
//mempbrk                                                          //~v640I~
// search any ascii char in the parmstr                            //~v640R~
//***************************************************************  //~v640I~
char *utfddmempbrk(int Popt,char *Pbuff,char *Pdbcs,char *Pstr,int Plen)//~v640I~
{                                                                  //~v640I~
	char *pcb,*pcs,*pcbn,*pco=0;                                   //~v640I~
    int len;                                                       //~v640I~
//******************                                               //~v640I~
	pcb=Pbuff;                                                     //~v640I~
    len=Plen;                                                      //~v640I~
    for (pcs=Pstr;len && *pcs;pcs++)                               //~v640I~
    {                                                              //~v640I~
    	if (pcbn=utfddmemchr(0,pcb,Pdbcs,*pcs,len),pcbn)           //~v640I~
        {                                                          //~v640I~
			pco=pcbn;                                              //~v640I~
            if (pcbn==pcb)  //found at top                         //~v664R~
            	break;                                             //~v640I~
//      	len=(ULONG)pco-(ULONG)pcb;                             //~v640I~//~v6hhR~
//      	len=(ULPTR)pco-(ULPTR)pcb;                             //~v6hhI~//~v6B4R~
        	len=(int)((ULPTR)pco-(ULPTR)pcb);                      //~v6B4R~
        }                                                          //~v640I~
	}                                                              //~v640I~
    return pco;                                                    //~v640I~
}//utfddmempbrk                                                    //~v640I~
//***************************************************************  //~v667I~
//mempbrk                                                          //~v667I~
// search any ascii char in the parmstr                            //~v667I~
//***************************************************************  //~v667I~
char *utfddmempbrk_nonascii(int Popt,char *Pbuff,char *Pdbcs,char *Pstr,char *Pstrdbcs,int Plen)//~v667I~
{                                                                  //~v667I~
	char *pcb,*pcs,*pcbn,*pco=0,*pcsd;                             //~v667I~
    int len;                                                       //~v667I~
//******************                                               //~v667I~
	pcb=Pbuff;                                                     //~v667I~
    len=Plen;                                                      //~v667I~
    for (pcs=Pstr,pcsd=Pstrdbcs;len && *pcs;pcs++,pcsd++)          //~v667I~
    {                                                              //~v667I~
    	if (pcbn=utfddmemchr_nonascii(0,pcb,Pdbcs,*pcs,*pcsd,len),pcbn)//~v667I~
        {                                                          //~v667I~
			pco=pcbn;                                              //~v667I~
            if (pcbn==pcb)  //found at top                         //~v667I~
            	break;                                             //~v667I~
//      	len=(ULONG)pco-(ULONG)pcb;                             //~v667I~//~v6hhR~
//      	len=(ULPTR)pco-(ULPTR)pcb;                             //~v6hhI~//~v6B4R~
        	len=(int)((ULPTR)pco-(ULPTR)pcb);                      //~v6B4I~
        }                                                          //~v667I~
	}                                                              //~v667I~
    return pco;                                                    //~v667I~
}//utfddmempbrk_nonascii                                           //~v667I~
//***************************************************************  //~v665I~
//memrpbrk                                                         //~v665I~
// reverse search any ascii char in the parmstr                    //~v665I~
//***************************************************************  //~v665I~
char *utfddmemrpbrk(int Popt,char *Pbuff,char *Pdbcs,char *Pstr,int Plen)//~v665I~
{                                                                  //~v665I~
	char *pcb,*pcs,*pcbn,*pco=0,*pce,*pcd;                         //~v665R~
    UINT len;                                                      //~v665I~
//******************                                               //~v665I~
	pcb=Pbuff;                                                     //~v665I~
    pce=pcb+Plen;		//end addr                                 //~v665I~
//  len=Plen;                                                      //~v665I~//~v6B4R~
    len=(UINT)Plen;                                                //~v6B4I~
    for (pcs=Pstr;len && *pcs;pcs++)                               //~v665I~
    {                                                              //~v665I~
    	pcd=UTF_PC2PCD(Pdbcs,pcb,Pbuff);                           //~v665I~
//  	if (pcbn=utfddmemrchr(0,pcb,pcd,*pcs,len),pcbn)            //~v665R~//~v6B4R~
    	if (pcbn=utfddmemrchr(0,pcb,pcd,*pcs,(int)len),pcbn)       //~v6B4I~
        {                                                          //~v665I~
			pco=pcbn;                                              //~v665I~
        	pcb=pcbn+1;                                            //~v665I~
//        	len=(ULONG)pce-(ULONG)pcb;                             //~v665I~//~v6hhR~
//      	len=(ULPTR)pce-(ULPTR)pcb;                             //~v6hhI~//~v6BxR~
        	len=(UINT)PTRDIFF(pce,pcb);                            //~v6BxI~
        }                                                          //~v665I~
	}                                                              //~v665I~
    return pco;                                                    //~v665I~
}//utfddmemrpbrk                                                   //~v665I~
//***************************************************************  //~v667I~
//memrpbrk                                                         //~v667I~
// reverse search sbcs char in the parmstr                         //~v667I~
//***************************************************************  //~v667I~
char *utfddmemrpbrk_nonascii(int Popt,char *Pbuff,char *Pdbcs,char *Pstr,char *Pstrdbcs,int Plen)//~v667I~
{                                                                  //~v667I~
	char *pcb,*pcs,*pcbn,*pco=0,*pce,*pcd,*pcsd;                   //~v667R~
    UINT len;                                                      //~v667I~
//******************                                               //~v667I~
	pcb=Pbuff;                                                     //~v667I~
    pce=pcb+Plen;		//end addr                                 //~v667I~
//  len=Plen;                                                      //~v667I~//~v6B4R~
    len=(UINT)Plen;                                                //~v6B4I~
    for (pcs=Pstr,pcsd=Pstrdbcs;len && *pcs;pcs++,pcsd++)          //~v667I~
    {                                                              //~v667I~
    	pcd=UTF_PC2PCD(Pdbcs,pcb,Pbuff);                           //~v667I~
//  	if (pcbn=utfddmemrchr_nonascii(0,pcb,pcd,*pcs,*pcsd,len),pcbn)//~v667I~//~v6B4R~
    	if (pcbn=utfddmemrchr_nonascii(0,pcb,pcd,*pcs,*pcsd,(int)len),pcbn)//~v6B4I~
        {                                                          //~v667I~
			pco=pcbn;                                              //~v667I~
        	pcb=pcbn+1;                                            //~v667I~
//        	len=(ULONG)pce-(ULONG)pcb;                             //~v667I~//~v6hhR~
//        	len=(ULPTR)pce-(ULPTR)pcb;                             //~v6hhI~//~v6BxR~
          	len=(UINT)PTRDIFF(pce,pcb);                            //~v6BxI~
        }                                                          //~v667I~
	}                                                              //~v667I~
    return pco;                                                    //~v667I~
}//utfddmemrpbrk                                                   //~v667I~
//**************************************************               //~va20R~//~v640I~
//*tabchk                                                          //~va20R~//~v640I~
//* tab compare                                                    //~va20R~//~v640I~
//4:unmatch, 0 match                                               //~va20R~//~v640I~
//**************************************************               //~va20R~//~v640I~
int utfddcmpdbcstab(int Popt,UCHAR *Pdbcs1,UCHAR *Pdbcs2,int Plen)    //~va20R~//~v640I~
{                                                                  //~va20R~//~v640I~
	UCHAR *pcd1,*pcd2;                                             //~va20R~//~v640I~
	int reslen,dbcsid1,dbcsid2;                                    //~va20R~//~v640I~
//****************************                                     //~va20R~//~v640I~
	for (reslen=Plen,pcd1=Pdbcs1,pcd2=Pdbcs2;reslen>0;reslen--)    //~va20R~//~v640I~
    {                                                              //~va20R~//~v640I~
        dbcsid1=*pcd1++;                                           //~va20I~//~v640I~
        dbcsid2=*pcd2++;                                           //~va20I~//~v640I~
        if (dbcsid1==dbcsid2)                                      //~va20I~//~v640I~
        	continue;                                              //~va20I~//~v640I~
    	if ((!dbcsid1 || dbcsid1==UDBCSCHK_TABCHAR || dbcsid1==UDBCSCHK_TABPADCHAR)  //~va20R~//~v640R~
    	&&  (!dbcsid2 || dbcsid2==UDBCSCHK_TABCHAR || dbcsid2==UDBCSCHK_TABPADCHAR)  //~va20I~//~v640R~
           )                                                       //~va20I~//~v640I~
            continue;                                              //~va20R~//~v640I~
        break;                                                     //~va20I~//~v640I~
    }                                                              //~va20R~//~v640I~
    if (reslen)                                                    //~va20I~//~v640I~
    	return 4;                                                  //~va20I~//~v640I~
    return 0;                                                      //~va20I~//~v640I~
}//utfddcmpdbcstab                                                 //~v640I~
//*******************************************************          //~v640I~
//*umemmem                                                         //~v640I~
//* search mem parm2 on mem parm1                                  //~v640I~
//******************************************************           //~v640I~
char *utfddmemmem(int Popt,char *Pbuff,char *Pdbcs,char *Pkey,char *Pkeydbcs,int Plen,int Plenk)//~v640I~
{                                                                  //~v640I~
	char *pc,*pce,top,*pcd,*pc2,*pc3,top2;                         //~v640R~
	int len,swtabunmatch,rc2,swnocase;                             //~v640R~
//******************                                               //~v640I~
UTRACED("memmem data",Pbuff,Plen);                                 //~v640I~
UTRACED("memmem dbcs",Pdbcs,Plen);                                 //~v640I~
UTRACED("memmem key ",Pkey,Plenk);                                 //~v640I~
UTRACEDIFNZ("memmem kdbc",Pkeydbcs,Plenk);                         //~v640R~
	if (Plenk<=0)                                                  //~v640R~
		return Pbuff;                                              //~v640I~
    top=*Pkey;                                                     //~v640R~
//  top2=toupper(top);                                             //~v640I~//~v6B3R~
    top2=(char)toupper(top);                                       //~v6B3I~
    if (top2==top)                                                 //~v640I~
//  	top2=tolower(top);                                         //~v640I~//~v6B3R~
    	top2=(char)tolower(top);                                   //~v6B3I~
    pc=Pbuff;                                                      //~v640R~
    pce=Pbuff+Plen;                                                //~v640R~
	swtabunmatch=(Popt & UTFDDMMO_TABUNMATCH);  //no ignore tab and tab padding(unmatch with space)//~v640I~
	swnocase=(Popt & UTFDDMMO_NOCASE);                             //~v640I~
    for (;;)                                                       //~v640R~
    {                                                              //~v640R~
//      len=((ULONG)pce-(ULONG)pc);                                //~v640R~//~v6hhR~
//      len=((ULPTR)pce-(ULPTR)pc);                                //~v6hhI~//~v6B4R~
        len=(int)((ULPTR)pce-(ULPTR)pc);                           //~v6B4I~
        pc2=pc;                                                    //~v640I~
        pc=memchr(pc2,top,(UINT)len);                              //~v640R~
		if (swnocase && top2!=top)                                 //~v640I~
        {                                                          //~v640I~
	        pc3=memchr(pc2,top2,(UINT)len);                        //~v640I~
            if (pc3 && (!pc||pc3<pc))                              //~v640I~
            	pc=pc3;                                            //~v640I~
        }                                                          //~v640I~
        if (!pc)                                                   //~v640R~
	    	break;                                                 //~v640R~
        if (pc+Plenk>pce)                                          //~v640R~
            return 0;                                              //~v640R~
            	                                                   //~v640I~
//      pcd=Pdbcs+(ULONG)pc-(ULONG)Pbuff;                          //~v640I~//~v6hhR~
        pcd=Pdbcs+(ULPTR)pc-(ULPTR)Pbuff;                          //~v6hhI~
		if (swnocase)                                              //~v640I~
			rc2=utfddcmp(UTFDDCMPO_NOCASE,pc,pcd,Pkey,Pkeydbcs,Plenk);//~v640I~
        else                                                       //~v640I~
	        rc2=memcmp(pc,Pkey,(UINT)Plenk);                       //~v640I~
        if (!rc2)                                                  //~v640R~
        {                                                          //~v640R~
            if (Pkeydbcs)                                          //~v640I~
            {                                                      //~v640I~
                if (!memcmp(pcd,Pkeydbcs,(UINT)Plenk))             //~v640I~
                    break;                                         //~v640I~
				if (!swtabunmatch)  //ignore tab and tab padding(unmatch with space)//~v640R~
					if (!utfddcmpdbcstab(0,pcd,Pkeydbcs,Plenk))    //~v640I~
                    	break;                                     //~v640I~
            }                                                      //~v640I~
            else                                                   //~v640I~
            {                                                      //~v640I~
            	if (!utfchkdd(0,pcd,Plenk))                        //~v640R~
                	break;                                         //~v640R~
            }                                                      //~v640I~
        }                                                          //~v640R~
        pc++;                                                      //~v640R~
    }                                                              //~v640R~
    return pc;                                                     //~v640R~
}//utfddmemmem                                                     //~v640R~
                                                                   //~v640I~
//*******************************************************          //~v640I~
//*utfddmemrmem                                                    //~v640I~
//* search mem parm2 on mem parm1                                  //~v640I~
//******************************************************           //~v640I~
char *utfddmemrmem(int Popt,char *Pbuff,char *Pdbcs,char *Pkey,char *Pkeydbcs,int Plen,int Plenk)//~v640I~
{                                                                  //~v640I~
	char *pc,*pce,*pcl,*pcd,*pcde;                                 //~v640I~
	int reslen;                                                    //~v640R~
//******************                                               //~v640I~
	if (Plenk<=0)                                                  //~v640R~
		return Pbuff;                                              //~v640I~
    pc=Pbuff;                                                      //~v640I~
    pce=pc+Plen;                                                   //~v640I~
    pcde=Pdbcs+Plen;                                               //~v640I~
    pcl=0;				//last found                               //~v640I~
    for (;;)                                                       //~v640I~
    {                                                              //~v640I~
//  	reslen=(ULONG)pce-(ULONG)pc;                               //~v640I~//~v6hhR~
//  	reslen=(ULPTR)pce-(ULPTR)pc;                               //~v6hhI~//~v6B4R~
    	reslen=(int)((ULPTR)pce-(ULPTR)pc);                        //~v6B4I~
        pcd=pcde-reslen;                                           //~v640I~
		pc=utfddmemmem(Popt,pc,pcd,Pkey,Pkeydbcs,reslen,Plenk);    //~v640I~
        if (!pc)                                                   //~v640I~
        	break;                                                 //~v640I~
        pcl=pc;                                                    //~v640I~
    	pc++;                                                      //~v640I~
	}                                                              //~v640I~
	return pcl;                                                    //~v640I~
}//utfddmemrmem                                                    //~v640I~
                                                                   //~v640I~
//*******************************************************          //~v640I~
//*unumlen                                                         //~v640I~
//* numric str length                                              //~v640I~
//******************************************************           //~v640I~
int utfddnumlen(int Popt,char *Pstr,char *Pdbcs,int Plen)          //~v640R~
{                                                                  //~v640I~
    int ii,hexopt,minusopt=0;                                      //~v640I~
    int octopt;                                                    //~v640I~
//******************                                               //~v640I~
    hexopt=(Popt & UNUMLEN_HEX);                                   //~v640I~
    octopt=(Popt & UNUMLEN_OCT);                                   //~v640I~
    ii=0;                                                          //~v640I~
    if (Popt & UNUMLEN_SPACE)                                      //~v640I~
        for (;ii<Plen && *Pstr;ii++,Pstr++,Pdbcs++)                //~v640I~
        {                                                          //~v640I~
            if (*Pstr!=' ')                                        //~v640I~
                break;                                             //~v640I~
            if (*Pdbcs)                                            //~v640I~
                break;                                             //~v640I~
        }                                                          //~v640I~
    if (UTFDD_ASCIIEQ(*Pstr,*Pdbcs,'+'))                           //~v640R~
    {                                                              //~v640I~
        Pstr++;                                                    //~v640I~
        Pdbcs++;                                                   //~v640I~
        ii++;                                                      //~v640I~
    }                                                              //~v640I~
    else                                                           //~v640I~
    if (UTFDD_ASCIIEQ(*Pstr,*Pdbcs,'-'))                           //~v640R~
    {                                                              //~v640I~
        Pstr++;                                                    //~v640I~
        Pdbcs++;                                                   //~v640I~
        ii++;                                                      //~v640I~
        if (ii>=Plen)                                              //~v640I~
            return 0;                                              //~v640I~
        minusopt=(Popt & UNUMLEN_MINUS);                           //~v640I~
    }                                                              //~v640I~
    for (;ii<Plen && *Pstr;ii++,Pstr++,Pdbcs++)                    //~v640I~
    {                                                              //~v640I~
    	if (*Pdbcs)                                                //~v640I~
        	break;                                                 //~v640I~
        if (octopt)                                                //~v640I~
        {                                                          //~v640I~
        	if (*Pstr>='0' && *Pstr <='7')                         //~v640I~
            	continue;                                          //~v640I~
            else                                                   //~v640I~
            	break;                                             //~v640I~
        }                                                          //~v640I~
        if (*Pstr>='0' && *Pstr <='9')                             //~v640I~
            continue;                                              //~v640I~
        if (!hexopt)                                               //~v640I~
            break;                                                 //~v640I~
        if (*Pstr>='a' && *Pstr <='f')                             //~v640I~
            continue;                                              //~v640I~
        if (*Pstr>='A' && *Pstr <='F')                             //~v640I~
            continue;                                              //~v640I~
        break;                                                     //~v640I~
    }                                                              //~v640I~
    if (minusopt)                                                  //~v640I~
        return -ii;                                                //~v640I~
    return ii;                                                     //~v640I~
}//utfddnumlen                                                     //~v640I~
#ifdef XXE                                                         //~v6uLR~
#ifdef AAA //csubddcombine has no user                             //~v6X5I~
//**************************************************************** //~v650I~
//*from wxecsub.c                                                  //~v6uBI~
//*chk width0 combination                                          //~v650I~
//*rc:0x01:ddfmt,0x02:combine data                                 //~v650I~
//**************************************************************** //~v650I~
int utfddcombine(int Popt,char *Pdata,char *Pdbcs,char *Pcombineid,int Plen,int *Ppstarterrctr,int *Ppendcombinectr)//~v650R~
{                                                                  //~v650I~
	int rc=0,chsz,combinectr=0,dbcsid,ii,combineok=0,starterrsw=1,starterrctr=0,combineid;//~v650R~
    char *pc,*pcd,*pcombid;                                        //~v650R~
#ifdef UTF8UTF16                                                   //~v6uBI~
    UWUCS ucs;                                                     //~v6uBI~
#else                                                              //~v6uBI~
    WUCS ucs;                                                      //~v650I~
#endif                                                             //~v6uBI~
//*********************                                            //~v650I~
	for (ii=0,pc=Pdata,pcd=Pdbcs,pcombid=Pcombineid;ii<Plen;pc+=chsz,pcd+=chsz,ii+=chsz,pcombid+=chsz)//~v650R~
    {                                                              //~v650I~
    	dbcsid=*pcd;                                               //~v650M~
        chsz=1;                                                    //~v650I~
    	if (UDBCSCHK_ISUCSDBCST(dbcsid))	//ucs sbcs/dbcs        //~v650R~
        {                                                          //~v650I~
			ucs=UTF_GETDDUCS1(pc,pcd,Plen-ii);                     //~v650I~
        	chsz+=UDBCSCHK_ISUCSDBCS(dbcsid);                      //~v650I~
            rc|=UTFDDCOMBRC_DDFMT;                                 //~v650R~
//#ifdef WWW                                                         //~v6BYI~//~v6BZR~
            if (UDBCSCHK_ISUCSWIDTH0(*pcd))   //width0             //~v650R~
//#else                                                              //~v6BYI~//~v6BZR~
//            if (UTF_ISUCSWIDTH0(ucs))   //width0                   //~v6BYI~//~v6BZR~
//#endif                                                             //~v6BYI~//~v6BZR~
            {                                                      //~v650R~
                rc|=UTFDDCOMBRC_COMBINE;                           //~v650I~
                if (UTF_COMBINEMODE()                              //~v650R~
				||  !(Popt & UTFDDCO_ERRIFNOCB)  //set err if not combinemode//~v650I~
                )                                                  //~v650I~
                {                                                  //~v650I~
                    if (combineok && combinectr<UVIOM_MAXCOMBINE)   //combine acceptable//~v650R~
                    {                                              //~v650R~
                        if (!combinectr)                           //~v650R~
                            *(pcombid-1)=UTFDDCOMBID_START;        //~v650R~
                        combinectr++;                              //~v650R~
                        combineid=UTFDDCOMBID_CONT;                //~v650R~
                    }                                              //~v650R~
                    else                                           //~v650R~
                    {                                              //~v650R~
                        combineid=UTFDDCOMBID_ERR;    //split at start or counter overflow//~v650R~
                        if (starterrsw)                            //~v650R~
                            starterrctr++;                         //~v650R~
                    }                                              //~v650R~
                }                                                  //~v650I~
                else                                               //~v650I~
                {                                                  //~v650I~
                    combineid=UTFDDCOMBID_ERR;    //split at start or counter overflow//~v650I~
                    if (starterrsw)                                //~v650I~
                        starterrctr++;                             //~v650I~
                }                                                  //~v650I~
//              *pcombid=combineid;                                //~v650R~//~v6C4R~
                *pcombid=(char)combineid;                          //~v6C4I~
                continue;                                          //~v650R~
            }                                                      //~v650R~
	    	combineok=UTF_COMBINABLE(ucs);                         //~v650I~
        }                                                          //~v650I~
        else                                                       //~v650I~
        {                                                          //~v650I~
            ucs=*pc;                                               //~v650I~
    		combineok=!dbcsid && UTF_COMBINABLE(ucs);              //~v650R~
        }                                                          //~v650I~
        *pcombid=0;                                                //~v650I~
        combinectr=0;                                              //~v650I~
        starterrsw=0;                                              //~v650I~
    }                                                              //~v650I~
    if (Ppstarterrctr)                                             //~v650I~
		*Ppstarterrctr=starterrctr;                                //~v650I~
    if (Ppendcombinectr)                                           //~v650I~
		*Ppendcombinectr=combinectr;                               //~v650I~
    UTRACEP("csubchkw0 rc=%d,starterr=%d,endcombine=%d\n",rc,starterrctr,combinectr);//~v650R~
    UTRACED("csubchkw0 combineid",Pcombineid,Plen);                //~v650I~
    return rc;                                                     //~v650R~
}//utfddcombine                                                    //~v650I~
#endif // AAA //csubddcombine has no user                          //~v6X5I~
#endif  //XXE                                                      //~v6uLR~
#ifdef AAA                      //no caller                        //~v6C2I~
//**************************************************************** //~v650I~
//*chk width0 combination                                          //~v650I~
//*Plen=substrlen                                                  //~v650I~
//*rc:0x01:sbcs starter,2:dbcs starter,0:no starter of combine data//~v650R~
//**************************************************************** //~v650I~
int utfddcombinegetsubstr(int Popt,char *Pdbcs,char *Pcombine,int Plen,int *Pplennormal,int *Pplencombine,int *Pplendrawn)//~v650R~
{                                                                  //~v650I~
	int rc=0,comblen=0,nocomblen=0,ii,dbcssw,combid,drawnctr=0;    //~v650R~
    int maxlen;                                                    //~v650I~
    char *pcd,*pcombid;                                            //~v650I~
//*********************                                            //~v650I~
	UTRACEP("combine substr opt=%x\n",Popt);                       //~v650R~
	UTRACED("combine substr pcomb",Pcombine,Plen);                 //~v650R~
	UTRACED("combine substr pdbcs",Pdbcs,Plen);                    //~v650R~
    if (Popt & UTFDDGSS_DRAWNCHK)                                  //~v650M~
    {                                                              //~v650M~
		for (ii=0,pcombid=Pcombine;ii<Plen && *pcombid==UTFDDCOMBID_DRAWN;ii++,pcombid++)//~v650I~
        	drawnctr++;                                            //~v650I~
    	maxlen=*Pplencombine;                                      //~v650I~
		for (ii=0,pcombid=Pcombine+Plen;ii<maxlen && *pcombid==UTFDDCOMBID_CONT;ii++,pcombid++)//~v650I~
            comblen++;	//count tail combine ctr                   //~v650M~
		*Pplencombine=comblen;                                     //~v650M~
		*Pplendrawn=drawnctr;                                      //~v650I~
    UTRACEP("combine getsubstr drawnchk tailcomb=%d,headdrawn=%d,maxlen=%d\n",rc,comblen,drawnctr,maxlen);//~v650R~
        return 0;                                                  //~v650I~
    }                                                              //~v650M~
	for (ii=0,pcd=Pdbcs,pcombid=Pcombine;ii<Plen && *pcombid==UTFDDCOMBID_DRAWN;pcd++,ii++,pcombid++)//~v650R~
        drawnctr++;                                                //~v650R~
                                                                   //~v650I~
	for (;ii<Plen;pcd++,ii++,pcombid++)                            //~v650R~
    {                                                              //~v650I~
        combid=*pcombid;                                           //~v650M~
    	if (Popt & UTFDDGSS_ERRBREAK)                              //~v650I~
            if (combid==UTFDDCOMBID_ERR)    //no combine mode or over max//~v650R~
            {                                                      //~v650R~
                if (!ii)    //start by err                         //~v650R~
                    nocomblen=1;            //write 1 char         //~v650R~
                break;                                             //~v650R~
            }                                                      //~v650R~
        dbcssw=(pcd>Pdbcs) && (*pcd==UDBCSCHK_DBCS2ND);            //~v650I~
    	if (comblen)	//started                                  //~v650I~
        {                                                          //~v650I~
        	if (combid==UTFDDCOMBID_CONT)                          //~v650I~
            {                                                      //~v650I~
                if (Popt & UTFDDGSS_SETDRAW)                       //~v650I~
                    *pcombid=UTFDDCOMBID_DRAWN;                    //~v650I~
            	comblen++;                                         //~v650I~
            }                                                      //~v650I~
            else                                                   //~v650I~
            	break;                                             //~v650I~
        }                                                          //~v650I~
        else                                                       //~v650I~
        {                                                          //~v650I~
        	if (combid==UTFDDCOMBID_START)                         //~v650I~
            {                                                      //~v650I~
        		rc=comblen=1+dbcssw;                               //~v650R~
                nocomblen-=dbcssw;                                 //~v650I~
            }                                                      //~v650I~
            else                                                   //~v650I~
            	nocomblen++;                                       //~v650I~
        }                                                          //~v650I~
    }                                                              //~v650I~
	*Pplennormal=nocomblen;                                        //~v650R~
	*Pplencombine=comblen;                                         //~v650R~
	*Pplendrawn=drawnctr;                                          //~v650I~
    UTRACEP("combine getsubstr rc=%d,nocomb=%d,comb=%d,drawn=%d\n",rc,nocomblen,comblen,drawnctr);//~v650R~
    return rc;                                                     //~v650I~
}//utfddcombinegetsubstr                                           //~v650I~
#endif                                                             //~v6C2I~
//**************************************************************** //~v650I~
//*get dbcs boundary                                               //~v650I~
//ret byte count                                                   //~v650I~
//**************************************************************** //~v650I~
int utfddgetdbcslr(int Popt,char *Pdbcs,int Plen,int Ppos)         //~v650I~
{                                                                  //~v650I~
	int ctr,reslen,rc=0;                                           //~v650R~
    char *pcd;                                                     //~v650I~
//**************************                                       //~v650I~
    pcd=Pdbcs+Ppos;                                                //~v650I~
    if (Popt & UTFDDGLRO_TOP)   //search DBCS1ST                   //~v650I~
    {                                                              //~v650I~
        for (ctr=0;pcd--,pcd>=Pdbcs && ctr<=MAX_MBCSLENLC;)        //~v650I~
        {                                                          //~v650I~
        	ctr++;                                                 //~v650I~
        	if (*pcd==UDBCSCHK_DBCS1ST)                            //~v650R~
            {                                                      //~v650I~
            	rc=ctr;                                            //~v650R~
            	break;                                             //~v650I~
            }                                                      //~v650I~
        }                                                          //~v650I~
    }                                                              //~v650I~
    else                                                           //~v650I~
    {                                                              //~v650I~
        for (ctr=0,reslen=Plen-Ppos;reslen>0 && ctr<=MAX_MBCSLENLC;reslen--,pcd++)//~v650I~
        {                                                          //~v650I~
        	ctr++;                                                 //~v650I~
        	if (*pcd==UDBCSCHK_DBCS2ND)                            //~v650R~
            {                                                      //~v650I~
            	rc=ctr;                                            //~v650R~
            	break;                                             //~v650I~
            }                                                      //~v650I~
        }                                                          //~v650I~
    }                                                              //~v650I~
    return rc;                                                     //~v650R~
}//utfddgetdbcslr                                                  //~v650I~
//**************************************************************** //~v650I~
//*get column of csr position-1 and +1 and +0                      //~v650I~
//**************************************************************** //~v650I~
int utfddgetcsrposbca(int Popt,char *Pdbcs,int Plen,int Ppos,int *Ppposb,int *Ppposc,int *Ppposa)//~v650I~
{                                                                  //~v650I~
	int posa=-1,posb=-1,posc=-1,dbcsid,rc=0;                       //~v650R~
    int len;                                                       //~v650I~
//**************************                                       //~v650I~
//get current col                                                  //~v650I~
	if (Ppos>=0 && Ppos<=Plen)                                     //~v650R~
    {                                                              //~v650I~
		posc=Ppos;                                                 //~v650I~
        if (Ppos<Plen)                                             //~v650I~
        {                                                          //~v650I~
            dbcsid=*(Pdbcs+posc);                                  //~v650R~
//#ifdef UTF8UCS4                                                    //~v65cI~//~v6uBR~
#ifdef UTF8UCS416                                                  //~v6uBI~
//          if (UDBCSCHK_DBCS2NDUCS2NWO(dbcsid))  //UCS DBCS2nd and UCS4 except NP ucs2//~v65cI~//~v65mR~
            if (UDBCSCHK_DBCS2NDU(dbcsid))  //UCS DBCS2nd and UCS4 includeing NP ucs2//~v65mI~
#else                                                              //~v65cI~
            if (UDBCSCHK_DBCS2NDUCS2NW(dbcsid))  //UCS DBCS2nd,except NP//~v650R~
#endif                                                             //~v65cI~
            {                                                      //~v650I~
                if (posc>0)                                        //~v650R~
                    posc--;                                        //~v650R~
            }                                                      //~v650I~
            else                                                   //~v650I~
			if (Popt & UTFDDGSP_ALSOLOCAL && posc>0)               //~v650I~
            {                                                      //~v650I~
	            if (UDBCSCHK_DBCSNOT1ST_L(dbcsid))  //local dbcs   //~v650I~
                {                                                  //~v650I~
					len=utfddgetdbcslr(UTFDDGLRO_TOP,Pdbcs,Plen,posc);//~v650I~
                    if (len)                                       //~v650I~
                    	posc=posc-len;                             //~v650I~
                }                                                  //~v650I~
            }                                                      //~v650I~
        }                                                          //~v650I~
//get cols 1 column before    It may be deleted by BackSpace       //~v650R~
        if (posc>0)                                                //~v650R~
        {                                                          //~v650R~
            posb=posc-1;                                           //~v650R~
            dbcsid=*(Pdbcs+posb);                                  //~v650R~
//#ifdef UTF8UCS4                                                    //~v65cI~//~v6uBR~
#ifdef UTF8UCS416                                                  //~v6uBI~
//          if (UDBCSCHK_DBCS2NDUCS2NWO(dbcsid))  //UCS DBCS2nd and UCS4 except NP ucs2//~v65cI~//~v65mR~
            if (UDBCSCHK_DBCS2NDU(dbcsid))  //UCS DBCS2nd and UCS4 includeing NP ucs2//~v65mI~
#else                                                              //~v65cI~
            if (UDBCSCHK_DBCS2NDUCS2NW(dbcsid))  //UCS DBCS2nd     //~v650R~
#endif                                                             //~v65cI~
            {                                                      //~v650I~
                if (posb>0)                                        //~v650R~
                    posb--;                                        //~v650R~
            }                                                      //~v650I~
            else                                                   //~v650I~
			if (Popt & UTFDDGSP_ALSOLOCAL && posb>0)               //~v650I~
            {                                                      //~v650I~
	            if (UDBCSCHK_DBCSNOT1ST_L(dbcsid))  //local dbcs   //~v650I~
                {                                                  //~v650I~
					len=utfddgetdbcslr(UTFDDGLRO_TOP,Pdbcs,Plen,posb);//~v650I~
                    if (len)                                       //~v650I~
                    	posb=posb-len;                             //~v650I~
                }                                                  //~v650I~
            }                                                      //~v650I~
        }                                                          //~v650R~
//get cols 1 column after    avoid combine with current pos        //~v650R~
        if (posc+1<=Plen)                                          //~v650R~
        {                                                          //~v650R~
            posa=posc+1;                                           //~v650I~
            dbcsid=*(Pdbcs+posc);                                  //~v650R~
//#ifdef UTF8UCS4                                                    //~v65cI~//~v6uBR~
#ifdef UTF8UCS416                                                  //~v6uBI~
//          if (UDBCSCHK_DBCS1STUCS2NWO(dbcsid))  //UCS DBCS1ST    //~v65cI~//~v65mR~
            if (UDBCSCHK_DBCS1STU(dbcsid))  //include also unprintable//~v65mI~
#else                                                              //~v65cI~
            if (UDBCSCHK_DBCS1STUCS2NW(dbcsid))  //UCS DBCS1ST     //~v650R~
#endif                                                             //~v65cI~
            {                                                      //~v650I~
		        if (posa+1<=Plen)                                  //~v650I~
                	posa++;                                        //~v650R~
            }                                                      //~v650I~
            else                                                   //~v650I~
			if (Popt & UTFDDGSP_ALSOLOCAL)                         //~v650I~
            {                                                      //~v650I~
	            if (UDBCSCHK_DBCSNOTEND_L(dbcsid))  //local dbcs   //~v650I~
                {                                                  //~v650I~
					len=utfddgetdbcslr(UTFDDGLRO_END,Pdbcs,Plen,posc);//~v650I~
                    if (len)                                       //~v650I~
                    	posa=posc+len;                             //~v650I~
                }                                                  //~v650I~
            }                                                      //~v650I~
        }                                                          //~v650R~
    }                                                              //~v650M~
    else                                                           //~v650M~
    	rc=4;                                                      //~v650M~
  if (Ppposa)                                                      //~v650I~
    *Ppposa=posa;                                                  //~v650I~
  if (Ppposb)                                                      //~v650I~
    *Ppposb=posb;                                                  //~v650I~
  if (Ppposc)                                                      //~v650I~
    *Ppposc=posc;                                                  //~v650I~
UTRACED("utfddgetcsrposbca dbcst",Pdbcs,Plen);                     //~v650R~
UTRACEP("utfddgetcsrposbca len=%d,pos=%d,b=%d,c=%d,a=%d\n",Plen,Ppos,posb,posc,posa);//~v650R~
    return rc;                                                     //~v650I~
}//utfddgetcsrposbca                                               //~v650I~
//**************************************************************** //~v65iI~
//*get visible altchar for ctl char                                //~v65iI~
//*Linux is basicaly english mode                                  //~v65pI~
//**************************************************************** //~v65iI~
int utfgetvisiblealtch(int Popt,int Pctlchar)                      //~v65iI~
{                                                                  //~v65iI~
static int Saltch[]={  //base is old ascii by Wiki CP437, and for xe, old Japanese//~v65iR~
//**                   http://en.wikipedia.org/wiki/Code_page_437  //~v65nI~
//0x0 No sbcs prepare for japanese mode except 0x1b                //~v65pR~
					0x25ab,0,     //0x00   XE,small empty square   //~v65iR~
					0x263a,0,     //0x01   face white              //~v65iR~
					0x263b,0,     //0x02   face black              //~v65iR~
    				0x2665,0,     //0x03 D heart black             //~v65nI~
					0x2666,0,     //0x04   diamond black           //~v65iR~
					0x2663,0,     //0x05 D club                    //~v65iR~
					0x2660,0,     //0x06 D spade                   //~v65iR~
					0x2022,0,     //0x07 D small ball black        //~v65iR~
					0x25d8,0,     //0x08   pin hall in black square//~v65iR~
					0x25cb,0,     //0x09 D white ball              //~v65iR~
					0x25d9,0,     //0x0a   white circle in black square//~v65iR~
					0x2642,0,     //0x0b D man                     //~v65iR~
					0x2640,0,     //0x0c D femail                  //~v65iR~
					0x266a,0,     //0x0d D music 1/4               //~v65iR~
                    0x266b,0,     //0x0e D music 1/8 *2            //~v65iR~
					0x263c,0,     //0x0f   sun                     //~v65iR~
//0x1_                                                             //~v65nI~
					0x25ba,0,     //0x10   triangle black right    //~v65iR~
					0x25c4,0,     //0x11   triangle black left     //~v65iR~
					0x2195,0,     //0x12   arrow up+down           //~v65iR~
					0x203c,0,     //0x13   !!                      //~v65iR~
                    0x00b6,0,     //0x14 D q                       //~v65iR~
					0x00a7,0,     //0x15 D chapter                 //~v65iR~
	 	   		  	0x25ac,0,     //0x16   bar                     //~v65iR~
//  				0x21ab,0,     //0x17   arrow up+down stand on plate//~v65pR~
    				0x21a8,0,     //0x17   arrow up+down stand on plate//~v65pI~
                    0x2191,0,     //0x18 D arrow up                //~v65pR~
                    0x2193,0,     //0x19 D arrow down              //~v65pR~
                    0x2192,0,     //0x1a D arrow right             //~v65pR~
                    0x2190,0x21bc,//0x1b D arrow left              //~v65nI~
                                  //0x1b XE us for 0x1b,conform SBCS//~v65nI~
                    0x221f,0,     //0x1c D left bottom corner      //~v65iR~
					0x2194,0,     //0x1d D arrow left+right        //~v65iR~
                    0x25b2,0,     //0x1e D trangle up              //~v65pR~
                    0x25bc,0      //0x1f D triangle down           //~v65pR~
    			};                                                 //~v65iI~
                                                                   //~v65iI~
#ifdef W32                                                         //~v65pR~
//*for japanese **********************************************     //~v65iR~
static int SaltchJ[]={  //base is old ascii by Wiki CP437, and for xe use old JapaneseDOS for compatibility//~v65pR~
//               {1st,2nd}if 1st is dbcs use 2nd                   //~v65iI~
					0x25ab,0,    //0x00   XE,small empty square    //~v65iR~
					-1    ,0,    //0x01   Japanese DOS line drawing//~v65iR~
					-1    ,0,    //0x02   Japanese DOS line drawing//~v65iR~
					-1    ,0,    //0x03   Japanese DOS line drawing//~v65iR~
					-1    ,0,    //0x04   Japanese DOS line drawing//~v65iR~
					-1    ,0,    //0x05   Japanese DOS line drawing//~v65iR~
					-1    ,0,    //0x06   Japanese DOS line drawing//~v65iR~
//  				0x2022,0,     //0x07 D small ball black        //~v65nR~
//                  0x2193,0x21a7,//0x07 D arrow down ==0x19(E),prepare SBCS//~v65nR~
                    0x07  ,0x21a7,//0x07 D arrow down ==0x19(E),prepare SBCS//~v65nI~
//  				0x25d8,0,     //0x08   pin hall in black square//~v65nR~
    				0x08  ,0,     //set    not defined,rep by "." if utfwcwidth!=1//~v65nR~
					0x09  ,0x25cb,//0x09 D white ball(==E)         //~v65nR~
#ifdef WXE                                                         //~v65nI~
    				0x25d9,0,     //0x0a   white circle in black square WXE base is English mode//~v65nR~
#else                                                              //~v65nI~
    				0x0a  ,0,     //0x0a   not defined             //~v65nR~
#endif                                                             //~v65nI~
//  				0x2642,0,     //0x0b D man                     //~v65nR~
    				0x0b  ,0x22a0,//0x0b                           //~v65nI~
#ifdef WXE                                                         //~v65nI~
    				0x2640,0,     //0x0c D femail,WXE base is Eng mode//~v65nR~
#else                                                              //~v65nI~
    				0x0c  ,0,     //0x0c   not defined             //~v65nR~
#endif                                                             //~v65nI~
#ifdef WXE                                                         //~v65nI~
    				0x266a,0,     //0x0d D music 1/4,WXE base is Eng mode//~v65nR~
#else                                                              //~v65nI~
    				0x0d  ,0,     //0x0d   not defined             //~v65nR~
#endif                                                             //~v65nI~
#ifdef WXE                                                         //~v65nI~
                    0x0e  ,0x266b,//0x0e XE small black sqaure;XE use as unprintable char display//~v65nI~
#else                                                              //~v65nI~
                    0x0e  ,0x25aa,//0x0e XE small black sqaure;XE use as unprintable char display//~v65nR~
#endif                                                             //~v65nI~
					0x0f  ,0x263c,//0x0f   sun                     //~v65nR~
					-1    ,0,     //0x10   Japanese DOS line drawing//~v65iR~
					0x11  ,0,     //0x11   not assigned            //~v65nR~
//  				0x2195,0,     //0x12   arrow up+down           //~v65nR~
    				0x12  ,0x2195,//0x12   arrow up+down           //~v65nI~
//  				0x203c,0,     //0x13   !!                      //~v65nR~
    				0x13  ,0,     //0x13   !!                      //~v65nI~
  					0x14  ,0,     //0x14 no unicode corresponding  //~v65nR~
					-1    ,0,     //0x15   Japanese DOS line drawing//~v65iR~
					-1    ,0,     //0x16   Japanese DOS line drawing//~v65iR~
					-1    ,0,     //0x17   Japanese DOS line drawing//~v65iR~
//                  0x2191,0x21be,//0x18 D arrow up                //~v65nR~
//                                //0x18   half arrow up,for XE tab(E) char//~v65nR~
//  				-1    ,0,     //0x18   not assigned            //~v65nR~
    				0x18  ,0,     //0x18   not assigned            //~v65nI~
					-1    ,0,     //0x19   Japanese DOS line drawing//~v65iR~
//                  0x2192,0x21c0,//0x1a D arrow right             //~v65nR~
//                                //0x1a   half arrow right,for XE tab padding(E) char//~v65nR~
//  				-1    ,0,     //0x1a                           //~v65nR~
    				0x1a  ,0,     //0x1a                           //~v65nR~
                    0x21b5,0,     //0x1b   XE use ReturnKey glyph  //~v65iR~
	#ifdef WXE                                                     //~v65nI~
                    0x221f,0,     //0x1c WXE Eng mode              //~v65nI~
    #else                                                          //~v65nI~
                    0x1c  ,0x2191,//0x1c up arrow on DOS/V-J       //~v65nI~
	#endif                                                         //~v65nI~
//                  0x250b,0,     //0x1d   vertical bar to draw line,old Japanese DOSs selected SBCS//~v65nR~
#ifdef WXE                                                         //~v65nI~
                    0x2194,0,     //0x1d   vertical bar to draw line//~v65nI~
#else                                                              //~v65nI~
                    0x1d  ,0x2502,//0x1d   vertical bar to draw line//~v65nR~
#endif                                                             //~v65nI~
#ifdef WXE                                                         //~v65nI~
                    0x25b2,0x25b4,//0x1e WXE eng mode              //~v65nR~
#else                                                              //~v65nI~
                    0x1e  ,0x2192,//0x1e left arrow on DOS/V-J     //~v65nI~
#endif                                                             //~v65nI~
//                  0x21bc,0      //0x1f   arrow left,old Japanese DOS but selcted SBCS//~v65nR~
#ifdef WXE                                                         //~v65nI~
                    0x25bc,0x25be,//0x1f   arrow left,Wxe Eng mode //~v65nR~
#else                                                              //~v65nI~
                    0x1f  ,0x2190 //0x1f   arrow left,old Japanese DOS but selcted SBCS//~v65nI~
#endif                                                             //~v65nI~
    			};                                                 //~v65iI~
#endif    //!XXE                                                   //~v65iI~
//** for data=0xff,dbcs=tab,tabpadd,dbcs space,unprintable         //~v65pI~
#define STABDDENT 3		//entry of dbcs+data of ddfmt              //~v65pM~
#define STABLCENT 4		//for xprint locale code eng+jpn           //~v65pI~
#define STABENTSZ 5		//ucs 1st candidate,2nd ucs,ascii candidate,dbcs+data for xprint//~v65pI~
//  static int Sinitsw;                                            //~v6F3R~
	int altch,*alttb,*ptb,ii,len,sbcsid;                           //~v65pR~
    UCHAR data[MAX_MBCSLEN],dbcs[MAX_MBCSLEN];                     //~v65pI~
#ifdef W32                                                         //~v65pI~
	int lc;                                                        //~v65pI~
#endif                                                             //~v65pI~
#define DEFAULT_ALTEOL '_'                                         //~v65pI~
//**************************                                       //~v65iI~
                                                                   //~v65iI~
//  if (Pctlchar==DBCSSPACE_ALT)	//0xff                         //~v65nR~
//  	return UC_DBCSSPACE_ALT;    //u2591                        //~v65nR~
//  if (Pctlchar>=0x20||Pctlchar<0)                                //~v65nR~
//  	return -1;                                                 //~v65nR~
#ifdef W32                                                         //~v65pR~
    if (UDBCSCHK_ISDBCSJ())                                        //~v65iI~
		alttb=SaltchJ;                                             //~v65iR~
    else                                                           //~v65iI~
#endif                                                             //~v65iI~
		alttb=Saltch;                                              //~v65iI~
	if (!Sinitsw)                                                  //~v65iI~
    {                                                              //~v65iI~
        UTRACED("visible tbl",alttb,32*8);                         //~v65iR~
    	Sinitsw=1;                                                 //~v65iI~
        for (ii=0,ptb=alttb;ii<32;ii++,ptb+=2)                     //~v65iI~
        {                                                          //~v65iI~
        	altch=*ptb;                                            //~v65iI~
            if (altch==-1)                                         //~v65iI~
            {                                                      //~v65nI~
//            if (utfwcwidth(0,ii,0/*flag*/)==1)	//not sbcs     //~v65nI~//~v6B4R~
              if (utfwcwidth(0,(ULONG)ii,0/*flag*/)==1)	//not sbcs //~v6B4I~
            	continue;                                          //~v65iI~
              *ptb='.';                                            //~v65nI~
            }                                                      //~v65nI~
//          if (utfwcwidth(0,altch,0/*flag*/)!=1)	//not sbcs     //~v65iR~//~v6B4R~
            if (utfwcwidth(0,(ULONG)altch,0/*flag*/)!=1)	//not sbcs//~v6B4I~
            {                                                      //~v65iI~
            	altch=*(ptb+1);                                    //~v65iI~
//          	if (altch && utfwcwidth(0,altch,0/*flag*/)==1)     //~v65iR~//~v6B4R~
            	if (altch && utfwcwidth(0,(ULONG)altch,0/*flag*/)==1)//~v6B4I~
                	*ptb=altch;                                    //~v65iI~
                else                                               //~v65iI~
                if (ii==0x1b)                                      //~v65pR~
                	*ptb=DEFAULT_ALTEOL;                           //~v65pI~
                else                                               //~v65pI~
                	*ptb='.';                                      //~v65iI~
            }                                                      //~v65iI~
        UTRACEP("visible tbl DBCSJ=%d,ii=%x,atch=%x,out=%x\n",UDBCSCHK_ISDBCSJ(),ii,altch,*ptb);//~v65nR~
        }                                                          //~v65iI~
        UTRACED("visible tbl",alttb,32*8);                         //~v65iR~
        UTRACED("visible tbl tab1",Stabs,sizeof(Stabs));           //~v65nI~
//*for SBCS                                                        //~v65pI~
        for (ii=0,ptb=Stabs;ii<UTFGVACO_CHMAX;ii++,ptb+=STABENTSZ) //~v65pR~
        {                                                          //~v65nI~
        	altch=*ptb;                                            //~v65nI~
//          if (utfwcwidth(0,altch,0/*flag*/)!=1)	//not sbcs     //~v65nI~//~v6B4R~
            if (utfwcwidth(0,(ULONG)altch,0/*flag*/)!=1)	//not sbcs//~v6B4I~
            {                                                      //~v65nI~
            	altch=*(ptb+1);                                    //~v65nI~
//          	if (altch && utfwcwidth(0,altch,0/*flag*/)==1)     //~v65nI~//~v6B4R~
            	if (altch && utfwcwidth(0,(ULONG)altch,0/*flag*/)==1)//~v6B4I~
                	*ptb=altch;                                    //~v65nI~
                else                                               //~v65nI~
                	altch=*ptb=*(ptb+2);	//finaly ascii char    //~v65pR~
            }                                                      //~v65nI~
            if (UTF8ISASCII(altch))                                //~v65pI~
            	sbcsid=altch;                                      //~v65pR~
            else                                                   //~v65pI~
            {                                                      //~v65pI~
				utfcvu2dd1(0,(WUCS)altch,data,dbcs,&len);          //~v65pI~
                if (len==1)                                        //~v65pI~
                	sbcsid=*data|(*dbcs<<8);                       //~v65pI~
                else                                               //~v65pI~
                	sbcsid=*(ptb+2);	//finaly ascii char        //~v65pI~
            }                                                      //~v65pI~
            *(ptb+3)=sbcsid;                                       //~v65pI~
#ifdef W32                                                         //~v65pI~
            lc=*(ptb+STABLCENT);                                   //~v65pI~
	    	if (UDBCSCHK_ISDBCSJ())                                //~v65pI~
            	lc&=0xff;                                          //~v65pR~
            else                                                   //~v65pI~
            	lc>>=8;                                            //~v65pI~
            *(ptb+STABLCENT)=lc;                                   //~v65pI~
#endif                                                             //~v65pI~
        }                                                          //~v65nI~
        UTRACED("visible tbl tab2",Stabs,sizeof(Stabs));           //~v65nI~
    }                                                              //~v65iI~
  if (Pctlchar==DEFAULT_ALTCH)	//0xff                             //~v65nI~
  {                                                                //~v65nI~
    ii=Popt & UTFGVACO_CHMASK;                                     //~v65nI~
    if (ii<UTFGVACO_CHMAX)                                         //~v65nI~
    {                                                              //~v65pI~
	  if (Popt & UTFGVACO_GETDD)                                   //~v65pI~
		altch=Stabs[ii*STABENTSZ+STABDDENT];                       //~v65pI~
      else                                                         //~v65pI~
	  if (Popt & UTFGVACO_GETLC)                                   //~v65pI~
		altch=Stabs[ii*STABENTSZ+STABLCENT];                       //~v65pI~
      else                                                         //~v65pI~
		altch=Stabs[ii*STABENTSZ];                                 //~v65pR~
    }                                                              //~v65pI~
    else                                                           //~v65nI~
    	altch=-1;                                                  //~v65nI~
  }                                                                //~v65nI~
  else                                                             //~v65nI~
  if (Pctlchar>=0x20||Pctlchar<0)                                  //~v65nI~
  	altch=-1;                                                      //~v65nI~
  else                                                             //~v65nI~
  {                                                                //~v65pI~
	altch=alttb[Pctlchar+Pctlchar];                                //~v65iR~
	if ((Popt & UTFGVACO_GETLC))                                   //~v65pI~
    	if (altch>=0x100)                                          //~v65pI~
        	altch='.';                                             //~v65pI~
  }                                                                //~v65pI~
    UTRACEP("utfgetvisiblealtch opt=%x,inp=%x,out=%x\n",Popt,Pctlchar,altch);//~v65nR~
    return altch;                                                  //~v65iI~
}//utfgetvisiblealtch                                              //~v65iI~
//**************************************************************** //~v65pI~
//*get visible altchar dd fmt                                      //~v65pI~
//*re dd fmt len                                                   //~v65pI~
//**************************************************************** //~v65pI~
int utfgetvisiblealtchprint(int Popt,int Pctlchar,UCHAR *Pdata,UCHAR *Pdbcs)//~v65pR~
{                                                                  //~v65pR~
	int altch,len,dbcs=0;                                          //~v6h4R~
//*************	                                                   //~v65pI~
	altch=utfgetvisiblealtch(Popt,Pctlchar);                       //~v65pR~
    if (altch>0)                                                   //~v65pI~
    {                                                              //~v65pI~
    	len=1;                                                     //~v65pI~
//		*Pdata=altch & 0xff;    //dbcs+data fmt                    //~v65pR~//~v6B4R~
  		*Pdata=(UCHAR)(altch & 0xff);    //dbcs+data fmt           //~v6B4I~
		dbcs=altch>>8;                                             //~v65pI~
        if (Pdbcs)                                                 //~v65pI~
//  		*Pdbcs=dbcs;                                           //~v65pR~//~v6B3R~
    		*Pdbcs=(UCHAR)dbcs;                                    //~v6B3I~
    }                                                              //~v65pI~
    else                                                           //~v65pI~
    	len=0;                                                     //~v65pI~
    UTRACEP("utfgetvisiblealtchprint opt=%x,outlen=%d,outch=%x,outdbcs=%x\n",Popt,len,*Pdata,dbcs);//~v65pR~
    return len;                                                    //~v65pI~
}//utfgetvisiblealtchprint                                         //~v65pR~
//**************************************************************** //~v66eI~
//*set dbcs errrep for f2l/dd2l trans err if dbcs available        //~v66eR~
//*ret ucs code                                                    //~v66eI~
//**************************************************************** //~v66eI~
int utf_setsubchar_dbcs(int Popt,UCHAR *Prepch)                    //~v66eR~
{                                                                  //~v66eI~
	static int Scandidateidx=-1;                                   //~v66eI~
	static int Srepchdbcs=0;                                       //~v66eR~
    static int Sucsrepchdbcs=0;    //default dbcs "?"              //~v66eR~
    #define MAX_CANDIDATE 3                                        //~v66eI~
    static int Sucscandidate[MAX_CANDIDATE]={0xff1f,0x30fb,0x3000};    //default uff1f:"?",u-3000:" ",u30fb:"."//~v66eR~
    UCHAR wkutf8[MAX_MBCSLEN];                                     //~v66eI~
//  UCHAR wklc[MAX_MBCSLEN];                                       //~v66eI~//~v6WvR~
    UCHAR wklc[32];                                                //~v6WvI~
    int utf8chsz,lcchsz,opt,rc;                                    //~v66eR~
    ULONG ucs;                                                     //~v66eI~
//*************                                                    //~v66eI~
	if (Scandidateidx<0)                                           //~v66eI~
    {                                                              //~v66eI~
    	for (Scandidateidx=0;Scandidateidx<MAX_CANDIDATE;Scandidateidx++)//~v66eR~
        {                                                          //~v66eI~
        	ucs=(ULONG)Sucscandidate[Scandidateidx];               //~v66eR~
//      	uccvucs2utf(ucs,wkutf8);                               //~v66eI~//~v6BkR~
        	uccvucs2utf((UWUCS)ucs,wkutf8);                        //~v6BkI~
        	utf8chsz=UTF8CHARLEN(wkutf8[0]);                       //~v66eI~
            UTRACEP("%s:ucs=%04x,utf8chsz=%d\n",UTT,ucs,utf8chsz); //~v6WuI~
            UTRACED("wku8",wkutf8,(int)sizeof(wkutf8));            //~v6WuR~
            opt=UTFCVO_ERRRET;                                     //~v66eI~
			rc=utfcvf2l(opt,wklc,wkutf8,utf8chsz,0/*chklen*/,&lcchsz,0/*chwidth*/);//~v66eR~
            UTRACEP("%s:rc=%d,utfcvf2l lcchsz=%d\n",UTT,rc,lcchsz);         //~v6WuI~//~v6WvR~
            UTRACED("wklc",wklc,lcchsz);                           //~v6WuR~
#ifdef W32                                                         //~v6WvI~
            if (!rc && lcchsz>MAX_MBCSLEN)                         //~v6WvI~
            {                                                      //~v6WvI~
                uerrexit("unsupported codepage:%d (char size may over %d)",0,//~v6WvI~
							udbcschk_getcp(),MAX_MBCSLEN);         //~v6WvI~
            }                                                      //~v6WvI~
#endif                                                             //~v6WvI~
            if (!rc && lcchsz==2)                                  //~v66eI~
            {                                                      //~v66eI~
	            Srepchdbcs=UTF_GETUCSDBCS(wklc);                   //~v66eI~
//              Sucsrepchdbcs=ucs;                                 //~v66eI~//~v6B4R~
                Sucsrepchdbcs=(int)ucs;                            //~v6B4I~
            	break;                                             //~v66eI~
            }                                                      //~v66eI~
        }                                                          //~v66eI~
        UTRACEP("subchardbcs=%x,ucs=%x\n",Srepchdbcs,Sucsrepchdbcs);//~v66eR~
    }                                                              //~v66eI~
	if (Scandidateidx>=MAX_CANDIDATE)                              //~v66eI~
    	return 0;	//may be sbcs env                              //~v66eI~
    if (Prepch)                                                    //~v66eI~
    	UTF_SETUCSBESTR(Srepchdbcs,Prepch);                        //~v66eR~
    return Sucsrepchdbcs;                                          //~v66eI~
}//utf_setsubchar_dbcs                                             //~v66eR~
//**************************************************************** //~v6ufI~
//*chk dbcs errrep and 2 sbcs err,under the condition 2 string is unmatch//~v6ufI~
//*ret 1:unmatch,0:match                                           //~v6ufI~
//**************************************************************** //~v6ufI~
int utf_subcharcmp(int Popt,int Psbcssubchar,char *Pstr1,char *Pstr2,int Plen)//~v6ufI~
{                                                                  //~v6ufI~
    char dbcssubchar[2];     //dbcs errrep BE str                  //~v6ufI~
    int rc=1;                                                      //~v6ufI~
//*************                                                    //~v6ufI~
	if (!utf_setsubchar_dbcs(0,dbcssubchar))//no dbcs subchar      //~v6ufI~
    	return 1;                                                  //~v6ufI~
	if (Plen>=2)                                                   //~v6ufR~
    {                                                              //~v6ufI~
		if (Pstr1[0]==dbcssubchar[0]                               //~v6ufI~
		&&  Pstr1[1]==dbcssubchar[1]                               //~v6ufR~
        &&  Pstr2[0]==Psbcssubchar                                 //~v6ufI~
        &&  Pstr2[1]==Psbcssubchar                                 //~v6ufI~
        )                                                          //~v6ufI~
            rc=0;   //match                                        //~v6ufI~
        else                                                       //~v6ufI~
		if (Pstr2[0]==dbcssubchar[0]                               //~v6ufI~
		&&  Pstr2[1]==dbcssubchar[1]                               //~v6ufR~
        &&  Pstr1[0]==Psbcssubchar                                 //~v6ufI~
        &&  Pstr1[1]==Psbcssubchar                                 //~v6ufI~
        )                                                          //~v6ufI~
            rc=0;   //match                                        //~v6ufI~
        else                                                       //~v6ufI~
        	return 1;                                              //~v6ufR~
	    if (Plen==4)                                               //~v6ufI~
    	    rc=utf_subcharcmp(Popt,Psbcssubchar,Pstr1+2,Pstr2+2,2);//~v6ufI~
    }                                                              //~v6ufI~
    return rc;                                                     //~v6ufI~
}//utf_subcharcmp                                                  //~v6ufI~
#endif	//UTF8UCS2                                                 //~v640R~
#ifdef W32UNICODE                                                  //~v6uaI~
//**************************************************************** //~v6u0I~//~v6uaI~
//strip ascii both side                                            //~v6u0I~//~v6uaI~
//**************************************************************** //~v6u0I~//~v6uaI~
int utf_trimascii(int Popt,UCHAR *Pstr,int Plen,UCHAR *Pout,int *Pppos)//~v6u0I~//~v6uaI~
{                                                                  //~v6u0I~//~v6uaI~
    UCHAR *pc,*pc2;                                                //~v6u0I~//~v6uaI~
    int pos,pos2,len,outlen;                                       //~v6u0R~//~v6uaI~
//***************************                                      //~v6u0I~//~v6uaI~
	if (!(len=Plen))                                               //~v6u0I~//~v6uaI~
    	len=strlen(Pstr);                                          //~v6u0I~//~v6uaI~
    for (pos=0,pc=Pstr;pos<len;pc++,pos++)                         //~v6u0I~//~v6uaI~
        if (!UTF8ISASCII(*pc))                                     //~v6u0I~//~v6uaI~
        	break;                                                 //~v6u0I~//~v6uaI~
    *Pppos=pos;                                                    //~v6u0I~//~v6uaI~
    if (pos==len)                                                  //~v6u0I~//~v6uaI~
    	outlen=0;                                                  //~v6u0I~//~v6uaI~
    else                                                           //~v6u0I~//~v6uaI~
    {                                                              //~v6u0I~//~v6uaI~
	    for (pos2=0,pc2=Pstr+len-1;pc2>pc;pc2--,pos2++)            //~v6u0I~//~v6uaI~
    	    if (!UTF8ISASCII(*pc2))                                //~v6u0R~//~v6uaI~
        		break;                                             //~v6u0I~//~v6uaI~
        outlen=len-pos-pos2;                                       //~v6u0I~//~v6uaI~
    }                                                              //~v6u0I~//~v6uaI~
    if (Pout)                                                      //~v6u0R~//~v6uaI~
    {                                                              //~v6u0I~//~v6uaI~
    	memcpy(Pout,Pstr+pos,outlen);                              //~v6u0I~//~v6uaI~
        if (Popt & UTTAO_STRZ)                                     //~v6u0I~//~v6uaI~
    		*(Pout+outlen)=0;                                      //~v6u0I~//~v6uaI~
    }                                                              //~v6u0I~//~v6uaI~
    return outlen;                                                 //~v6u0I~//~v6uaI~
}//utf_trimascii                                                   //~v6u0I~//~v6uaI~
#endif //W32UNICODE                                                //~v6uLR~
//**************************************************************** //~v6uaI~
// r-search ascii char on dd str                                   //~v6uaI~
//**************************************************************** //~v6uaI~
char *utfmemrchrDD(char *Pdddata,char *Pdddbcs,int Plen,int Psrch) //~v6uaI~
{                                                                  //~v6uaI~
	char *pc,*pcd;                                                 //~v6uaI~
    int len;                                                       //~v6uaI~
//*****************                                                //~v6uaI~
    for (len=Plen;;)//search precediong sepc                       //~v6uaI~
    {                                                              //~v6uaI~
//      pc=umemrchr(Pdddata,Psrch,len);                            //~v6uaI~//~v6B3R~
//      pc=umemrchr(Pdddata,(UCHAR)Psrch,len);                     //~v6B3I~//~v6B4R~
        pc=umemrchr(Pdddata,(UCHAR)Psrch,(size_t)len);             //~v6B4I~
        if (!pc)                                                   //~v6uaI~
            break;                                                 //~v6uaI~
        pcd=Pdddbcs+PTRDIFF(pc,Pdddata);                           //~v6uaI~
        if (!*pcd)  //sepc is not part of dbcs                     //~v6uaR~
            break;                                                 //~v6uaI~
        len=PTRDIFF(pc,Pdddata)-1;                                 //~v6uaI~
        if (!len)                                                  //~v6uaI~
        {                                                          //~v6uaI~
            pc=NULL;                                               //~v6uaI~
            break;                                                 //~v6uaI~
        }                                                          //~v6uaI~
    }                                                              //~v6uaI~
    return pc;                                                     //~v6uaI~
}//utfmemrchrDD                                                    //~v6uaI~
//*******************************************************          //~v6uaI~
// search ascii char on dd str                                     //~v6uaI~
//**************************************************************** //~v6uaI~
char *utfmemchrDD(char *Pdddata,char *Pdddbcs,int Plen,int Psrch)  //~v6uaI~
{                                                                  //~v6uaI~
	char *pc,*pc2,*pcd;                                            //~v6uaI~
    int len;                                                       //~v6uaI~
//*****************                                                //~v6uaI~
    for (pc=Pdddata,len=Plen;;)                                    //~v6uaI~
    {                                                              //~v6uaI~
//      pc2=memchr(pc,Psrch,len);                                  //~v6uaI~//~v6B4R~
        pc2=memchr(pc,Psrch,(size_t)len);                          //~v6B4I~
        if (!pc2)                                                  //~v6uaI~
            break;                                                 //~v6uaI~
        pcd=Pdddbcs+PTRDIFF(pc2,Pdddata);                          //~v6uaI~
        if (!*pcd)                                                 //~v6uaR~
            break;                                                 //~v6uaI~
        len=Plen-PTRDIFF(pc2,Pdddata)+1;                           //~v6uaI~
        if (!len)                                                  //~v6uaI~
        {                                                          //~v6uaI~
            pc2=NULL;                                              //~v6uaI~
            break;                                                 //~v6uaI~
        }                                                          //~v6uaI~
        pc=pc2+1;                                                  //~v6uaI~
    }                                                              //~v6uaI~
    return pc2;                                                    //~v6uaI~
}//utfmemchrDD                                                     //~v6uaI~
//*****************************************************************//~v6uaM~
//*string chk,0x00<=--<0x80                                        //~v6uaM~
//*****************************************************************//~v6uaM~
int isASCIIstr(char *Ppc)                                          //~v6uaM~
{                                                                  //~v6uaM~
    char *pc;                                                      //~v6uaM~
//*********************************                                //~v6uaM~
    for (pc=Ppc;*pc;pc++)                                          //~v6uaM~
    	if (!UTF8ISASCII(*pc))                                     //~v6uaM~
        	return 0;                                              //~v6uaM~
	return 1;                                                      //~v6uaM~
}//isASCIIstr                                                      //~v6uaM~
//*****************************************************************//~v6uaM~
//*string chk,0x20<=--<0x80                                        //~v6uaM~
//*****************************************************************//~v6uaM~
int isPrintableASCIIstr(char *Ppc)                                 //~v6uaM~
{                                                                  //~v6uaM~
    char *pc;                                                      //~v6uaM~
//*********************************                                //~v6uaM~
    for (pc=Ppc;*pc;pc++)                                          //~v6uaM~
    {                                                              //~v6uaM~
    	if (!UTF8ISASCII(*pc)||*pc<' ')                            //~v6uaM~
        	return 0;                                              //~v6uaM~
    }                                                              //~v6uaM~
	return 1;                                                      //~v6uaM~
}//isPrintableASCIIstr                                             //~v6uaM~
//*****************************************************************//~v6uaM~
//*string chk,0x20<=--<0x80                                        //~v6uaM~
//*****************************************************************//~v6uaM~
int isPrintableASCIImem(char *Ppc,int Plen)                        //~v6uaM~
{                                                                  //~v6uaM~
    char *pc;                                                      //~v6uaM~
    int ii;                                                        //~v6uaM~
//*********************************                                //~v6uaM~
    for (pc=Ppc,ii=Plen;ii>0;pc++,ii--)                            //~v6uaM~
    {                                                              //~v6uaM~
    	if (!UTF8ISASCII(*pc)||*pc<' ')                            //~v6uaM~
        	return 0;                                              //~v6uaM~
    }                                                              //~v6uaM~
	return 1;                                                      //~v6uaM~
}//isPrintableASCIImem                                             //~v6uaM~
////*****************************************************************//~v6BYI~//~v6BZR~
////*width0 for ucs                                                  //~v6BYR~//~v6BZR~
////*rc:1 width0,0:not width0                                        //~v6BYI~//~v6BZR~
////*****************************************************************//~v6BYI~//~v6BZR~
//int utf_isucswidth0(int Popt,UWUCS Pucs)                           //~v6BYR~//~v6BZR~
//{                                                                  //~v6BYI~//~v6BZR~
//    int rc,sbcsid;                                                 //~v6BYR~//~v6BZR~
////*********************************                                //~v6BYI~//~v6BZR~
//    if (Pucs>=UCS2DDMAP_ENTNO)                                     //~v6BYI~//~v6BZR~
//    {                                                              //~v6BYI~//~v6BZR~
//        rc=(utfwcwidth(0,Pucs,0/*flag*/)==1);                      //~v6BYR~//~v6BZR~
//    }                                                              //~v6BYI~//~v6BZR~
//    else                                                           //~v6BYR~//~v6BZR~
//    {                                                              //~v6BYI~//~v6BZR~
//        sbcsid=Gucs2ddmap[(int)Pucs].UCS2DDsbcsid;                 //~v6BYI~//~v6BZR~
//        rc=(sbcsid>=Gudbcschk_width0top);                          //~v6BYR~//~v6BZR~
//    }                                                              //~v6BYI~//~v6BZR~
//    UTRACEP("%s:rc=%d,ucs=%04x\n",UTT,rc,Pucs);                    //~v6BYI~//~v6BZR~
//    return rc;                                                     //~v6BYR~//~v6BZR~
//}//utf_isucswidth0                                                 //~v6BYR~//~v6BZR~
////*****************************************************************//~v6BYI~//~v6BZR~
////*width0 for ddfmt                                                //~v6BYI~//~v6BZR~
////*rc:1 width0,0:not width0                                        //~v6BYI~//~v6BZR~
////*****************************************************************//~v6BYI~//~v6BZR~
//int utf_isddwidth0(int Popt,char *Pdddata,char* Pdddbcs,int Plen,int *Ppddwidth)//~v6BYR~//~v6BZR~
//{                                                                  //~v6BYI~//~v6BZR~
//    int rc;                                                        //~v6BYR~//~v6BZR~
//    UWUCS ucs;                                                     //~v6BYI~//~v6BZR~
////*********************************                                //~v6BYI~//~v6BZR~
//    ucs=utfdd2u1chsz(0,Pdddata,Pdddbcs,Plen,Ppddwidth);            //~v6BYR~//~v6BZR~
//    rc=utf_isucswidth0(Popt,ucs);                                  //~v6BYI~//~v6BZR~
//    UTRACEP("%s:rc=%d,len=%d,ddwidth=%d,dddata=%02x-%02x,dddbcs=%02x-%02x\n",UTT,rc,Plen,Ppddwidth?*Ppddwidth:-1,*Pdddata,Plen>1?*(Pdddata+1):0,*Pdddbcs,Plen>1?*(Pdddbcs+1):0);//~v6BYR~//~v6BZR~
//    return rc;                                                     //~v6BYI~//~v6BZR~
//}//utf_isddwidth0                                                  //~v6BYR~//~v6BZR~
//*******************************************************          //~v6DbI~
//*setup ucs for for unprintable/overflow                          //~v6DbI~
//*ret  :1:unp,0:printable ovf                                     //~v6DbI~
//*******************************************************          //~v6DbI~
ULONG utf22_setunpucsvio(int Popt,ULONG Pucs,int Pdbcsid,int *Pprc)//~v6DbR~
{                                                                  //~v6DbI~
    int altch,rc=1;                                   //~v6DbR~    //~v6DcR~
    ULONG ucs;                                                     //~v6DbI~
#ifdef W32  //w32 missing wcwidth api                              //~v6DcI~
#else                                                              //~v6DcI~
	int apiwidth;                                                  //~v6DcI~
    int flag=0,optutfww=0;                                         //~v6V5I~
#endif                                                             //~v6DcI~
//************************                                         //~v6DbI~
    UTRACEP("%s:opt=%x,ucs=%04x\n",UTT,Popt,Pucs);                 //~v6DbI~
    ucs=Pucs;                                                      //~v6DbI~
	if (Popt & UT22SUUVO_OVF)                                      //~v6DbR~
    {                                                              //~v6DbI~
//* ISUCSOVF1ST=true                                               //~v6V5M~
#ifdef W32  //w32 missing wcwidth api                              //~v6DcI~
        ucs=UTF_UNPDBCS;	// DBCS square                         //~v6DcI~
#else                                                              //~v6DcI~
	    apiwidth=wcwidth((UWUCS)ucs);                              //~v6DcR~
        if (apiwidth==0 || utfwcwidth(optutfww,(ULONG)ucs,&flag)==0)//~v6V5R~
            rc=0;                                                  //~v6V5I~
        else                                                       //~v6V5I~
        if (apiwidth<=0)                                                //~v6DbI~//~v6DcR~
//          ucs=CHAR_UCS_DBCS_ERR;	// DBCS "?"                    //~v6DbI~//~v6DcR~
            ucs=UTF_UNPDBCS;	// DBCS square                     //~v6DcI~
        else                                                       //~v6DbI~
            rc=0;                                                  //~v6DbI~
        UTRACEP("%s:vio ucsnp ovf apiwidth=%d\n",UTT,apiwidth);       //~v6DbI~//~v6DcR~
#endif                                                             //~v6DcM~
    }                                                              //~v6DbI~
    else                                                           //~v6DbI~
    if ((Pucs==UDBCSCHK_ERRREPCH_NPUCS && UDBCSCHK_ISUCSNP1ST(Pdbcsid))   //by tabdisplay//~v6DbR~
    ||  (Pucs==UDBCSCHK_ERRREPCH_NPUCSW && UDBCSCHK_ISUCSNP2ND(Pdbcsid)))//~v6DbR~
    {                                                              //~v6DbI~
        UTRACEP("%s:vio ucsnp set by tabdisplay ucs=%04x,dbcsid=%02x\n",UTT,Pucs,Pdbcsid);//~v6DbI~//~v6DhR~
    }                                                              //~v6DbI~
    else                                                           //~v6DbI~
    {                                                              //~v6DbI~
    	altch=UTF_GETALTCH_SBCS(DEFAULT_UNPATTR);                  //~v6DbI~
        ucs=(ULONG)(altch>0?altch:'.');                            //~v6DbR~
        UTRACEP("%s:vio ucsnp altchar\n",UTT);                     //~v6DbI~
    }                                                              //~v6DbI~
    UTRACEP("%s:return rc=%d,out ucs=%04x\n",UTT,rc,ucs);          //~v6DbR~
    if (Pprc)                                                      //~v6DbI~
    	*Pprc=rc;                                                  //~v6DbR~
    return ucs;                                                    //~v6DbR~
}//uviom_setunpucsvio                                                 //~v6DbI~//~v6VaR~
//*******************************************************          //~v6DdI~
//*set altch for u3000/dbcs=()                                     //~v6DdI~
//*******************************************************          //~v6DdI~
int utf22_setdbcsspacealt(int Popt,UWUCS Pucs,char *Ppdbcs,int Preslen,int *Ppaltch)//~v6DeR~
{                                                                  //~v6DdI~
	int swdbcsspace=0,altch=0;	//dswbcsspace                      //~v6DdR~
//**********************                                           //~v6DdI~
	for (;;)                                                       //~v6DdI~
    {                                                              //~v6DdI~
		if (Pucs!=UC_DBCSSPACE)                                    //~v6DdI~
    		break;                                                 //~v6DdI~
		if (Preslen<=1)                                            //~v6DdI~
    		break;                                                 //~v6DdI~
        if (*Ppdbcs!=UDBCSCHK_DBCS1STUCS)                          //~v6DdI~
    		break;                                                 //~v6DdI~
        altch=UTF_GETALTCH_DBCS();                                 //~v6DdI~
        swdbcsspace=altch>0;                                       //~v6DdI~
        break;                                                     //~v6DdI~
	}                                                              //~v6DdI~
    if (Ppaltch)                                                   //~v6DdI~
    	*Ppaltch=altch;                                            //~v6DdR~
    UTRACEP("%s:swdbcsspace=%d,ucs=%04x,reslen=%d,dbcsid=%02x,altch=%04x\n",UTT,swdbcsspace,Pucs,Preslen,*Ppdbcs,altch);//~v6DdR~
    return swdbcsspace;                                            //~v6DdI~
}//utf22_setdbcsspace                                              //~v6DdI~
//**************************************************************** //~v6F3I~
//*set visible altchar for tab char                                //~v6F3I~
//*update ucs and dd fmt(leave lc entry)                           //~v6F3I~
//**************************************************************** //~v6F3I~
int utfsetvisiblealtch(int Popt,int Paltch)                        //~v6F3I~
{                                                                  //~v6F3I~
	int sbcsid,len,ii,*alttb;                                      //~v6F3R~
    char wkdata[4],wkdbcs[4];                                      //~v6F3R~
//**************************                                       //~v6F3I~
    if (!Sinitsw)                                                  //~v6F3I~
		utfgetvisiblealtch(UTFGVACO_TAB,DEFAULT_ALTCH); //setup Stabs//~v6F3I~
    if (utfwcwidth(0,(ULONG)Paltch,0/*flag*/)!=1     //not sbcs    //~v6F3R~
    ||  UTF_ISUCS4(Paltch)                                         //~v6F3I~
    ||  (utfcvu2dd1(0,(WUCS)Paltch,wkdata,wkdbcs,&len),len!=1))    //~v6F3I~
    {                                                              //~v6F3I~
    	uerrmsg("Err at set Tab altch(U-%04x), it should be UCS2-SBCS(char width==1).",//~v6F3R~
    	        "エラー(U-%04x), TAB\x95\\示文字は UCS2-SBCS でなければなりません",//~vc1cI~
        		Paltch);                                           //~v6F3I~
    	return 4;                                                  //~v6F3I~
    }                                                              //~v6F3I~
    if (UTF8ISASCII(Paltch))                                       //~v6F3I~
        sbcsid=Paltch;                                             //~v6F3I~
    else                                                           //~v6F3I~
    	sbcsid=*wkdata|(*wkdbcs<<8);                               //~v6F3I~
	alttb=Stabs;                                                   //~v6F3R~
    ii=Popt & UTFGVACO_CHMASK;                                     //~v6F3I~
	alttb[ii*STABENTSZ]=Paltch;    //if not sbcs,try +1 entry      //~v6F3R~
	alttb[ii*STABENTSZ+STABDDENT]=sbcsid;                          //~v6F3I~
    UTRACEP("utfsetvisiblealtch opt=%x,ii=%d,altch=%04x,ddent=%04x\n",Popt,ii,Paltch,sbcsid);//~v6F3I~
    return 0;                                                      //~v6F3R~
}//utfsetvisiblealtch                                              //~v6F3R~
#ifdef LNX                                                         //~v6VgI~
//****************************************************************************//~v6V5I~
//chk width0 for ucs>map_Entry)                                    //~v6V5I~
//not width0 but combining definition                              //~v6WmI~
//****************************************************************************//~v6V5I~
int utf22_iswidth0Ovf(int Popt,int Pch1,int Pch2,int Pdbcsid1,int Pdbcsid2,WUCS *Ppucs)//~v6V5I~
{                                                                  //~v6V5I~
	UCHAR dbcswk[4];                                               //~v6V5I~
    WUCS    ucs;                                                   //~v6V5I~
    int flag=0,optutfww=0;                                         //~v6V5I~
//******************                                               //~v6V5I~
	if (!UDBCSCHK_ISUCSOVF1ST(Pdbcsid1))                           //~v6V5I~
    	return 0;                                                  //~v6V5I~
    dbcswk[0]=(UCHAR)Pch1;                                         //~v6V5I~
    dbcswk[1]=(UCHAR)Pch2;                                         //~v6V5I~
    dbcswk[2]=(UCHAR)Pdbcsid1;                                     //~v6V5I~
    dbcswk[3]=(UCHAR)Pdbcsid2;                                     //~v6V5I~
    ucs=UTF_GETUCSDBCSOVF(dbcswk,dbcswk+2);                        //~v6V5I~
    *Ppucs=ucs;                                                    //~v6V5I~
//  if (wcwidth((UWUCS)ucs)==0 || utfwcwidth(optutfww,(ULONG)ucs,&flag)==0)//~v6V5I~//~v6WmR~
    utfwcwidth(optutfww,(ULONG)ucs,&flag);                         //~v6WmI~
    UTRACEP("%s:ucs=%06x flag=%x\n",UTT,ucs,flag);                 //~v6WmI~
    if (flag & UTFWWF_COMB)                                        //~v6WmI~
    {                                                              //~v6WmI~
        UTRACEP("%s:ucs=%06x is combining char,rc=2\n");           //~v6WmR~
    	return 2;                                                 //~v6V5I~//~v6WmR~
    }                                                              //~v6WmI~
    return 0;                                                      //~v6V5I~
}//utf22_iswidth0Ovf                                               //~v6V5I~
//****************************************************************************//~v6W9M~
//chk dbcs width0                                                  //~v6W9M~
//****************************************************************************//~v6W9M~
int utf22_iswidth0DBCS(int Popt,int Pch1,int Pch2,int Pdbcsid1,int Pdbcsid2,WUCS *Ppucs)//~v6W9M~
{                                                                  //~v6W9M~
	UCHAR dbcswk[2];                                               //~v6W9M~
    WUCS    ucs;                                                   //~v6W9M~
    int flag=0,optutfww=0;                                         //~v6W9M~
//******************                                               //~v6W9M~
	if (!UDBCSCHK_DBCS1STUCS2(Pdbcsid1))                           //~v6W9R~
    	return 0;                                                  //~v6W9M~
	if (!UDBCSCHK_DBCS2NDUCS2(Pdbcsid2))                           //~v6W9R~
    	return 0;                                                  //~v6W9M~
    dbcswk[0]=(UCHAR)Pch1;                                         //~v6W9M~
    dbcswk[1]=(UCHAR)Pch2;                                         //~v6W9M~
	ucs=UTF_GETUCSDBCS(dbcswk);                                    //~v6W9M~
    *Ppucs=ucs;                                                    //~v6W9M~
    if (wcwidth((UWUCS)ucs)==0 || utfwcwidth(optutfww,(ULONG)ucs,&flag)==0)//~v6W9M~
    	return 1;                                                  //~v6W9M~
    return 0;                                                      //~v6W9M~
}//utf22_iswidth0DBCS                                              //~v6W9M~
#else                                                              //~v6VgI~
//****************************************************************************//~v6VgI~
//chk width0 for ucs4 W32                                          //~v6VgI~
//****************************************************************************//~v6VgI~
//int utf22_iswidth0OvfW(int Popt,UWUCS Pucs4)                       //~v6VgI~//~v6W9R~
int utf22_iswidth0W(int Popt,UWUCS Pucs4)                          //~v6W9I~
{                                                                  //~v6VgI~
    int flag,optutfww=0;                                           //~v6VgI~
//******************                                               //~v6VgI~
    if (utfwcwidth(optutfww,(ULONG)Pucs4,&flag)==0)                //~v6VgI~
    	return 1;                                                  //~v6VgI~
    return 0;                                                      //~v6VgI~
}//utf22_iswidth0Ovf                                               //~v6VgI~
#endif                                                             //~v6VgI~
#ifdef W32UNICODE                                                  //~v6VmI~
//*******************************************************          //~v6VmI~
//*convert utf16 to utf8 str (surrogate pair err consideration)    //~v6VmR~
//*rc:buff overflow(0x20),1:utf8,2:dbcs,08:surrogate pair err,err(0x10)//~v6VmR~
//*******************************************************          //~v6VmI~
int utf162u8(int Popt,PUWCH Ppdata,int Pctr,UCHAR *Ppoutdata,int Poutbuffsz,int *Ppoutlen)//~v6VmI~
{                                                                  //~v6VmI~
    ULONG ulucs;                                                   //~v6VmI~
    UWCH  u16L,u16H;                                               //~v6VmI~
    int u8len,rc=0,reslen,outreslen,outlen,swerr;                  //~v6VmI~
    UCHAR *pco;                                                    //~v6VmR~
    UCHAR wku8[UTF8_MAXCHARSZ+1];                                  //~v6VmI~
    PWCH pucs;                                                     //~v6VmI~
//****************************                                     //~v6VmI~
UTRACED("utf162dd input   ",Ppdata,ctr2szW(Pctr));                 //~v6VmI~
    pco=Ppoutdata;                                                 //~v6VmI~
    pucs=Ppdata;                                                   //~v6VmI~
    for (reslen=Pctr,outreslen=Poutbuffsz;reslen>0 && outreslen>0;pucs++,reslen--)//~v6VmI~
    {                                                              //~v6VmI~
        u16H=*pucs;                                                //~v6VmI~
        u16L=0;                                                    //~v6VmI~
        ulucs=(ULONG)u16H;                                         //~v6VmI~
        swerr=1;                                                   //~v6VmI~
        if (IS_UTF16_HIGH(u16H))                                   //~v6VmI~
        {                                                          //~v6VmI~
            if (reslen>1)                                          //~v6VmR~
            {                                                      //~v6VmI~
                u16L=*(pucs+1);                                    //~v6VmI~
				if (IS_UTF16_LOW(u16L))                            //~v6VmI~
                {                                                  //~v6VmI~
                    ulucs=UTF16_TO_UCS4(u16H,u16L);                //~v6VmI~
                    reslen--;                                      //~v6VmI~
                    pucs++;                                        //~v6VmI~
                    swerr=0;                                       //~v6VmI~
                }                                                  //~v6VmI~
                else                                               //~v6VmI~
                    swerr=2;    //surrogate pair err               //~v6VmI~
            }                                                      //~v6VmI~
            else                                                   //~v6VmI~
                swerr=2;    //surrogate pair err                   //~v6VmI~
        }                                                          //~v6VmI~
        else                                                       //~v6VmI~
		if (!IS_UTF16_LOW(u16H))                                   //~v6VmI~
        	swerr=0;                                               //~v6VmI~
        else                                                       //~v6VmI~
            swerr=2;    //surrogate pair err                       //~v6VmI~
        if (swerr)                                                 //~v6VmI~
        {                                                          //~v6VmI~
        	ulucs='.';                                             //~v6VmI~
            if (Popt & U162DO_REPUCS)    //err rep to fffd         //~v6VmI~
        		ulucs=UDBCSCHK_SUBCHAR_DBCS;                       //~v6VmI~
            if (swerr==2)   //surrogate pair err                   //~v6VmI~
            {                                                      //~v6VmI~
                ulucs=u16H;                                        //~v6VmI~
    			rc|=UTFCVFDRC_UTF8ERR; //0x08   //invalid utf8 char,kept value//~v6VmR~
            }                                                      //~v6VmI~
            else                                                   //~v6VmI~
    			rc|=UTFCVFDRC_ERR;     //0x10                      //~v6VmR~
        }                                                          //~v6VmI~
        if (outreslen>UTF8_MAXCHARSZ)                              //~v6VmI~
        	u8len=uccvucs2utf(ulucs,pco);                          //~v6VmI~
        else                                                       //~v6VmI~
        {                                                          //~v6VmI~
        	u8len=uccvucs2utf(ulucs,wku8);                         //~v6VmI~
            if (u8len<outreslen)                                   //~v6VmI~
            	memcpy(pco,wku8,(size_t)u8len);                    //~v6VmR~
            else                                                   //~v6VmI~
            {                                                      //~v6VmI~
            	rc=UTFCVFDRC_OVF;                                  //~v6VmI~
                break;                                             //~v6VmI~
            }                                                      //~v6VmI~
        }                                                          //~v6VmI~
        pco+=u8len;                                                //~v6VmI~
        outreslen-=u8len;                                          //~v6VmI~
    }                                                              //~v6VmI~
    if (reslen>0)                                                  //~v6VmI~
		rc|=UTFCVFDRC_OVF;   //buffser overflow                    //~v6VmI~
    outlen=(int)((ULPTR)pco-(ULPTR)Ppoutdata);                     //~v6VmI~
    if (Ppoutlen)                                                  //~v6VmI~
	    *Ppoutlen=outlen;                                          //~v6VmI~
UTRACED("out data",Ppoutdata,outlen);                              //~v6VmI~
UTRACEP("%s rc=%d\n",UTT,rc);                                      //~v6VmI~
    return rc;                                                     //~v6VmI~
}//utf162u8(int Popt,PUWCH Ppdata,int Pctr,UCHAR *Ppoutdata,int Poutbuffsz,int *Ppoutlen)//~v6VmI~
#endif//W32UNICODE                                                 //~v6VmI~
//***************************************************************************//~v6VqI~
//UDBCSCHK_ISUCSWIDTH0 by ucs(support ucs4)                        //~v6VqI~
//rc:1:ucs2,2:ucs4,0:!width0                                       //~v6VqI~
//***************************************************************************//~v6VqI~
int utf_iswidth0(int Popt,int Pdbcsid,ULONG Pucs)                  //~v6VqR~
{                                                                  //~v6VqI~
	int rc=0,opt,flag;                                             //~v6VqR~
    UCHAR wkdddata[2],wkdddbcs[2];                                 //~v6VqI~
//**************************                                       //~v6VqI~
	if (Pucs>=UCS2DDMAP_ENTNO)                                     //~v6VqI~
    {                                                              //~v6VqI~
      	opt=UTFWWO_UTF8UCS2;     //do APICHK                       //~v6VqR~
		rc=utfwcwidth(opt,Pucs,&flag)==0 ? 2 : 0;                  //~v6VqR~
    }                                                              //~v6VqI~
    else                                                           //~v6VqI~
    {                                                              //~v6VqI~
    	if (Pdbcsid)                                               //~v6VqI~
            rc=UDBCSCHK_ISUCSWIDTH0(Pdbcsid);                      //~v6VqI~
        else	                                                   //~v6VqI~
        {                                                          //~v6VqI~
        	if (utfddsetsbcs(0,Pucs,wkdddata,wkdddbcs)==1)         //~v6VqR~
            	rc=UDBCSCHK_ISUCSWIDTH0(*wkdddbcs);                //~v6VqR~
        }                                                          //~v6VqI~
    }                                                              //~v6VqI~
    UTRACEP("%s:rc=%d,ucs=%04x,dbcsid=0x%x\n",UTT,rc,Pucs,Pdbcsid);//~v6VqR~
    return rc;                                                     //~v6VqI~
}//utf_iswidth0                                                    //~v6VqR~
//*****************************************************************//~v6VsR~
//UDBCSCHK_ISUCSWIDTH0 by ucs(support ucs4)                        //~v6VsR~
//rc:1:ucs2,2:ucs4,0:!width0                                       //~v6VsR~
//*****************************************************************//~v6VsR~
int utf_iscombinable(int Popt,ULONG Pucs)                          //~v6VsR~
{                                                                  //~v6VsR~
	int rc/*,flag,width,opt*/;                                         //~v6VsR~//~v79MR~
//**************************                                       //~v6VsR~
	if (UCSIS_NONCHARACTER(Pucs))                                  //~v6VsR~
    	rc=0;                                                      //~v6VsR~
    else                                                           //~v6VsR~
	if (Pucs==' ')                                                 //~v6W8I~
    {                                                              //~v6WuI~
//  	rc=1;   //allow space as combinable for OVF DBCS(if wcwidth=0, " " is padded)//~v6W8I~//~v6WuR~
    	rc=(Popt & UICAO_NOSPACE)==0;  //disallow space as combinable//~v6WuI~
    }                                                              //~v6WuI~
    else                                                           //~v6W8I~
	if (Pucs<0x0100)                                               //~v6VsR~
//    	rc=iswalpha((wint_t)Pucs);                                 //~v6VsR~//~v79LR~
      	rc=iswcntrl((wint_t)Pucs)==0;                              //~v79LR~
    else                                                           //~v6VsR~
    {                                                              //~v6VsR~
#ifdef AAA                                                         //~v79MI~
      	opt=UTFWWO_UTF8UCS2;     //do APICHK                       //~v6VsR~
		width=utfwcwidth(opt,Pucs,&flag);                          //~v6VsR~
        rc=(width==1||width==2);  //sbcs or dbcs,except -1(unp) and 0(width0)//~v6VsR~
#ifdef XXX                                                         //~v6WvI~
        if (width==2)                                              //~v6WtR~
			if (utf4_isSpacingCombiningMark(0,(UWUCS)Pucs))        //~v6WtR~
#else                                                              //~v6WvI~
        if (rc)      //width=0(combining) may COMBINE2SCM but both COMBINING & SCM is not combinable//~v6WvI~
			if (flag & UTFWWF_SCM)     //both SCM and COMB2SCM     //~v6WvI~
#endif                                                             //~v6WvI~
            	rc=0;                                              //~v6WtI~
#else                                                              //~v79MI~
		if (utf4_isFormat(0,(UWUCS)Pucs))                          //~v79MR~
        	rc=0;                                                  //~v79MI~
        else                                                       //~v79MI~
        	rc=1;                                                  //~v79MI~
#endif                                                             //~v79MI~
    }                                                              //~v6VsR~
    UTRACEP("%s:rc=%d,ucs=%04x\n",UTT,rc,Pucs);                    //~v6VsR~
    return rc;                                                     //~v6VsR~
}//utf_iscombinable                                                //~v6VsR~
//***************************************************************************//~v6WrI~
//chk combining by ucs                                             //~v6WrI~
//rc:0x01:sbcs,0x02:ucs4,0x04:SCM, else 0                              //~v6WrI~//~v6WtR~
//rc:0x08:COMB2SCM bt Popt & UICO_COMB2SCM_NOSCM                   //~v6X5I~
//***************************************************************************//~v6WrI~
int utf_iscombining(int Popt,int Pdbcsid,int Pucs)                 //~v6WrI~
{                                                                  //~v6WrI~
	int rc=0;                                                      //~v6WrR~
    int rc2;                                                       //~v6X5I~
//**************************                                       //~v6WrI~
//	if (utf4_isSpacingCombiningMark(0,(UWUCS)Pucs))                 //~vbk6R~//~vbmdI~//~v6WrR~//~v6X5R~
	if (rc2=utf4_isSpacingCombiningMark(0,(UWUCS)Pucs),rc2)        //~v6X5R~
    {                                                              //~v6WrI~
    	rc=UICRC_SCM;                                              //~v6WrI~
		if (Pucs>=UCS2DDMAP_ENTNO)                                 //~v6WrI~
	    	rc|=UICRC_OVF;                                         //~v6WrI~
      	if (rc2==2)	 //COMB2SCM                                    //~v6X5I~
      	{                                                          //~v6X5I~
			if (Popt & UICO_RCCOMB2SCM)    //set return COMB2SCM for cmb2scm//~v6X5R~
			    rc|=UICRC_COMB2SCM;                                //~v6X5R~
      	}                                                          //~v6X5I~
    }                                                              //~v6WrI~
    else                                                           //~v6WrI~
    {                                                              //~v6WrI~
		rc=utf_iswidth0(Popt,Pdbcsid,(ULONG)Pucs);                 //~v6WrI~
    }                                                              //~v6WrI~
    UTRACEP("%s:opt=%x,rc=%d,rc2=%d,ucs=%06x,dbcsid=0x%x\n",UTT,Popt,rc,rc2,Pucs,Pdbcsid);//~v6WrI~//~v6X5R~
    return rc;                                                     //~v6WrI~
}//utf_iscombining                                                 //~v6WrI~
