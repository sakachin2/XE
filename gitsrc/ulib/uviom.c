//*CID://+v7fsR~:                            update#= 2939;        //+v7fsR~
//*************************************************************    //~v6VdR~
//v7fs:251203 (WINCON)del v7fs; it show "=" for format even when combine mode//+v7fsI~
//v7fr:251203 (WINCON)If hcopy contains Format 202e(RtoL),202b(LtoR), remaining string shifts to right.//~v7frI~
//            exclude Format(except ZWJ) from getcombinctr         //~v7frI~
//v7fp:251129 (WINCON)combine mode on WindowsTerminal              //~v7fpI~
//v7fo:251126 (WINCON:BUG)when combinemode, spce line displayed before notcombineble+combining(revailed by v7fn)//~v7foI~
//v7fm:251119 (WINCON)on WindowsTerminal, combining char is show doubled. try clrarline like as nocombine//~v7fmI~
//v7fk:251118 (WINCON)on WindowsTerminal, combining char is show doubled. try to write space after it.//~v7fkI~
//v7fj:251116 (WINCON:bug)(ligOff)unicomb=comb; not green when csr is on combining char//~v7fjI~
//v7fi:251114 (WINCON:bug)(ligOff)unicomb=comb; dupricate write combining char. It cause on VT,display 4 combining char//~v7fiI~
//v7f8:251106 show not comb-unp(:) but altch(=/+/-) for w0-format when unicomb=UNP//~v7f8I~
//v7eA:250825 TRACE crash by null parm(TAB on cmd)                 //~v7eAI~
//v7ep:250802 v7ej for SCM(attr of data pos by vhex csr)           //~v7epI~
//v7ek:250724 (Bug:WINCON) Noligature+Comninemode;when vsplit screen line disappear on the left panel.//~v7ekI~
//v7ej:250722 (WINCON) attr of data line pos by vhex cursor. f23 set white but W0W reset to green//~v7ejI~
//v7ef:250717 (WINCON) show combining char of posa even combining mode like as wxe.//~v7efI~
//v7ed:250716 (Bug of v7bn(V1.30 hcopy)) Stoplineoffs is not 0 on conhost(0  for WinndowsTerminal). it cause 0c4 at uerrmsg if Stoplineoffs is not 0.//~v7edI~
//v7eb:250715 (W32)v7e9 has to consider surrogate pair.            //~v7ebI~
//v7ea:250711 (W32)SCM of just before csrposb was not green.       //~v7eaI~
//v7e9:250711 (W32)SCM of csrposb was not green.                   //~v7e8I~
//v7e8:250711 (W32)SCM split is not green but yellow.(Use 0xa0 as base). Some glyph may override the right character.//~v7e4I~
//v7e6:250707 (WINCON)4byte dbcs background color when revesed by find or Cut&Paste.//~v7e4I~
//v7e4:250702 Compile warning c4389 compared signed and unsigned   //~v7e4I~
//v7c4:240618 (Bug of v7bW) if rep ZWJ to altch,it becomes next combining base.(display doble "+")//~v7c4I~
//v7bW:240525 display category Cf by "+" as itself/shadow          //~v7bWI~
//v7bG:240425 split uviom.c to uvioml.c                            //~v7bGI~
//v7bF:240423 (LNXCON)redundant space was inserted for widesbc when lig off//~v7bFI~
//v7bE:240422 (LNXCON)SCM dose not combine even when combine mode if not ligature//~v7bEI~
//v7bD:240421 (LNXCON)Bug by v7bw; when Lig:On cursor pos and data pos is different//~v7bDI~
//v7bC:240420 (LNXCON)padding " " for wide sbcs disturb combining by ZWJ(200d).//~v7bCI~
//v7bB:240420 special for zwj(u-200d)/zwnj(u-200c) of width=0      //~v7bBR~
//v7bz:240419 (LNXCON)(BUG)lib:On+split shadow;dbcs+sbcs combine;miss 2nd char of dbcs shadow//~v7bzI~
//v7by:240418 (LNXCON)(BUG)after F2C1(' ' entry added), combining char is split from base char//~v7byI~
//v7bx:240418 (LNXCON)try read console by mvinnwstr(read ucs) for alternative of mvin_wchnstr(read cchar_t)//~v7bxI~
//v7bw:240416 (LNXCON)lig:on  combine mode,redundant space at line end//~v7bwI~
//v7bv:240416 (LNXCON)lig:off combine mode,sbcs was not combined   //~v7bvI~
//v7bu:240416 (LNXCON)sbcs+combining was not combined even when lig ON.//~v7buI~
//v7bt:240416 (LNXCON)color of combinemode padding/shadow by csrpos. yellow-->green//~v7btI~
//v7bs:240415 (LNXCON)show dbcscombining shadow                    //~v7bsI~
//v7br:240415 (LNXCON) redundant padding when shadow mode(sbcs and dbcs)//~v7brI~
//vbzP:240412 (LNXCON)support hardcopy function(also change key C+h-->A+@)//~vbzPI~
//v7bn:240406 (WINCON)hardcopy;errmsg is not write to buffer,use only readconsole except fffd is detected//~v7bnI~
//v7bm:240406 (WINCON)hardcopy function for vsplit(write from readConsole result+data/dbcs)//~v7bmI~
//v7bk:240406 (WINCON)avoid to write ucs4 by 2 utf16 split         //~v7bkI~
//vbzJ:240403 appendmode screen print to ::hp by Ctrl+h (hardcopy) //~vbzJI~
//v7bj:240405 (Bug)dbcs of sjis but ambigous(e.g. "(u201c=8167 )) show padding//~v7bjI~
//v7av:240317 apiwidth0 and overflow cut remaining of line by writing null char//~v7avI~
//v7at:240317 ambig chk set utfwcwidth=2 but uviom set cchar ucs+' ' if wcwidth=1, then ' ' disapper and column shift//~v7atI~
//            try to write ucs+' ' at once                         //~v7atI~
//v7ac:240229 (WINCON)on Windows Console,Font Mincho, confused ambiguous char display when /Yv; try write ambiguous char 1 by 1//~vbzPR~
//v7ab:240229 (WINCON)support narrow dbcs for v7a7                 //~v7a2I~
//v7a2:240222 WinCons:ambiguous char of wcwidth=2 by /Nv  misses intermediate padding char. ex) 0xa8a4+0xa8a2 on chcp54936(zh-CN) dbcstb:1212. use F2C1(WIDE) when wcw=2 by /Yv.//~v7a2I~
//v7a1:240222 (Bug)copy to locale file from utf8 fike. When u-25cf-->x819c(black circle), next sbcs was hidden on CPLC file.//~v7a1I~
//v700:200610 Axe:chtype not defined                               //~v700I~
//v6Xb:180822 gb18030:dbcs by gb18030 but display width=1, pos differ with hex line//~v6XbI~
//v6X8:180821 uviom_iscombining coding miss, effect is LNX only (swcombinable=0 by setting ucs=0)//~v6X8I~
//v6X5:180818 (LNX:xe)column shring COMB2SCM(036f+0390) even SPLIT mode,//~v6X5I~
//v6X2:180814 (Lnx)dbcs padding char(",") should be attr green for padding of combining (lig off column adjusting)//~v6X2I~
//v6X1:180814 (Bug:Win console)SCM was not combined                //~v6X1I~
//v6Wy:180807 (W32:Bug)on chcp=57008(Kannada), OutputCharacter could not show Wide char,use OutputCharacterW//~v6WyI~
//v6Wx:180807 (W32:Bug)chk fails of combine char over max          //~v6WxI~
//v6Ww:180807 (W32:Bug)top panel LC line is corrupted,use not OutputW but OutputCharacterW.//~v6WwI~
//v6Wu:180806 for also console version:set altch for SCM when COMBINE_NP,green if not adter combinable.//~v6WuI~
//v6Ws:180806 for performance COMBINABLE chk after Combining checked.//~v6WsI~
//v6Wr:180804 process SCM same as NSM(NonSpacing Mark)             //~v6WrI~
//v6We:180716 (Lnx:BUG)combining was not shown if it folloing unprintable(:;)//~v6WeI~
//v6Wb:180709 lig:on csr pos differ when wcwidth of ovf ucs(csr pos should shift to right by 1)//~v6WbI~
//v6Wa:180709 lig:off combine mode(shadow);2nd shadow base is space by prev shadow padding by the reason of v6W8 allowed space as combinable//~v6WaI~
//v6W9:180708 dbcs combining char such as u309a(u306f+u309a) exists.//~v6W9I~
//v6W8:180708 (LNX)try dbcs+combining                              //~v6W8I~
//v6W7:180708 (LNX)assing 2 column for shadow for ovf combining    //~v6W7I~
//v6W6:180708 (LNX:xe)try break to prev char of shadow to clear prev combining image//~v6W6I~
//v6W5:180706 (LNX:xe)Lig:off and combine mode;try combine char not to set base but to set u00a0 on next cell//~v6W5I~//~v7buR~
//v6W3:180603 (Bug)Addional to v6V6(Lnx&Console,Ligon+Combine mode, combine char was not shown) for the combine mode csrpos//~v6W3I~
//v6W2:180701 (LNX)Bug of v6V5;Lig:off and combine mode, combineing char disappears wghen csr is on the line//~v6W2I~
//v6W1:180701 (LNX)try u00a0 as combining base when split mode     //~v6W1I~
//v6W0:180629 (LNX)try SCM for console version-->did not work      //~v6W0I~
//v6Vh:180531 (Win:Bug) uviowrtcellW1_Errmsg; sumple loop ctrl miss//~v6VhI~
//v6Vg:180531 (Win) like as (LNX)v6V5, show org ucs for width0 ucs4(>=map entry)(W32 console version dose not support ligature:On)//~v6VgI~
//v6Vd:180613 (LNX:Bug)for ucs4(>u+ffff), ddcht2cchar set 1 cell unpritable. it causes column unmatch//~v6VdI~
//v6Vc:180613 (LNX:Bug)when Ligature:ON,Unicomb:Combine, Wide SBCS(ex u093b) was shown as 1cell//~v6VcR~
//v6V6:180603 (Bug)Lnx&Console,Ligon+Combine mode, combine char was not shown//~v6V6I~
//v6V5:180531 show org ucs for width0 ucs4(>=map entry)            //~v6V5I~
//v6V3:180530 ucs4(OVF) print as dbcs even when wcwidth=1 if utfwcwidth=2//~v6V3I~
//v6T5:180217 WCons:Cmdline,WriteConsoleOutputW/WriteConsoleOutputCharacterW shrink colomn. Use WriteConsoleOutputChar if avail(when successful cv to locale,also for altch)//~v6T5R~
//v6P0:171223 (Bug:WinConsole)errmsg corrupted when ddfmt contains <0x20//~v6P0I~
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
//*******************************************************
#ifndef XSUB                                                       //~v6hhI~
//*******************************************************
//#define COMBAINE_BASE_SPLIT_ITSELF 0xa0     //u00a0 base for combining char when split itself//~vbzPR~
#ifdef WCSUPP                                                      //~v5n8I~
  #ifdef W32                                                       //~v5n8I~
    HANDLE Shconout;                                               //~v5n8R~
    static  int     Stoplineoffs;   //console windows topline in buff//~v5n8M~
    static int Ssplitposx;                                         //~v652I~
   #ifndef WXE                                                     //~v6C7I~
    static int Sdbcsspacealt;                                      //~v6G0I~
    #define MAX_NOLIGATURELINE 8                                   //~v6C7I~
	static int Snoligature_linectr;                                //~v6C7R~
	static int SswLocalefile;	//parm to uviom_displaydbcspadCharacterW//~vbzJR~
   #endif                                                          //~v6C7I~
//  static int Sswligatureword;	//ligature mode eve if ligature option=ON for dirlist//~v6D6I~//~v6EcR~
  #endif                                                           //~v653I~
//  static int Sswligatureword;	//ligature mode eve if ligature option=ON for dirlist//~v6EiR~
  #ifdef W32                                                       //~v7bGI~
    static int Scsrposx,Scsrposy;                                  //~v652I~
    static int Svhexcsrposx,Svhexcsrposy;                          //~v658I~
    static int Sposcvhex;                                          //~v7ejI~
  #endif                                                           //~v7bGI~
//#endif                                                           //~v653R~
  #ifdef W32                                                       //~v7bGI~
    static  int     Sscrwidth;   	//scr line size                //~v5n8I~
    static  int     Sscrsize;   	//col*row                      //~v5n8I~
  #endif                                                           //~v7bGI~
#ifdef LNX                                                         //~v5n8I~
#else                                                              //~v5n8I~
    static  ULONG Scodepage;                                       //~v5n8R~
	#ifndef WXE                                                    //~v5n8M~
		int uviowrtcellW1(int Popt,PCHAR_INFO Ppchi,int Plen,UCHAR *Ppdbcs,COORD Psrcbox,COORD Psrcpos,SMALL_RECT *Ptgtrect);//~v5n8R~
	#endif                                                         //~v5n8R~
#endif                                                             //~v5n8I~
#ifdef UTF8UCS2                                                    //~v640M~
	int uvio_mdd2u(int Popt,UCHAR *Ppdata,UCHAR *Ppdbcs,int Plen,WUCS *Ppucs,int Poutbuffsz,int *Ppoutucsctr,int *Ppucsdbcsctr,int *Ppucssbcsctr);//~v640M~
    #define UVIOMD2UO_ERRREP   0xff                                //~v640I~
    #define UVIOMD2UO_VIO      0x0100                              //~v640I~
    #define UVIOM2UO_DDSTR     0x02  //source data/dbcs is ucs     //~v65mI~
    #define UVIOM2UO_MBCS      0x04  //source data is locale str   //~v65mI~
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
#ifdef W32                                                         //~v6D6I~
#ifndef WXE                                                        //~v6D6I~
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
#if defined(W32) && !defined(WXE)                                  //~v6T5I~
int uviowritelocale_ifavail(int Popt,WUCS *Ppucs,int Pucsctr,char *Ppdbcs,USHORT *Ppattr,int Plen,SMALL_RECT *Pptgtrect);//~v6T5I~
#endif                                                             //~v6T5I~
#ifdef LNX                                                         //~v6V5I~
	#ifndef XXE                                                    //~v700M~
int uviom_ISUCSWIDTH0(int Popt,chtype *Pcht,UCHAR *Ppdbcs,int Plen,WUCS *Ppucs4);
#define IUW0O_COMB2SCM_COMB    0x01    //comb2scm is combining     //~v6X5I~
#define IUW0O_NOZWJZWNJ        0x02    //return false for ZWJ(200d)/ZWNJ(200c)//~v7bBI~
int uviom_iscombining(int Popt,chtype *Ppcht,UCHAR *Ppdbcs,int Plen,WUCS *Ppucs4,int *Ppchsz);//~v6WuI~
	#endif                                                         //~v700I~
#else //W32                                                        //~v6VgI~
int uviom_ISUCSWIDTH0W(int Popt,WUCS *Ppucs,UCHAR *Ppdbcs,int Plen);//~v6VgI~
int uviom_iscombining(int Popt,WUCS *Ppucs,UCHAR *Ppdbcs,int Plen,int *Ppucs4,int *Ppchsz);//~v6WuI~
#define UVIOMICO_NOFMT 0x01   //exclude format                     //~v7frI~
int uviom_wrtW0W(int Popt,WUCS *Ppucs,USHORT *Ppattr,int Plen,COORD Ptgtpos,int *Ppwritelen);//~v6VgR~
int uviom_wrtSCMW(int Popt,int Pprevucs,int Pidx,int Pucs4,WUCS *Ppucs,USHORT *Ppattr,COORD Ptgtpos);//~v6WuI~
int uviowrtcellW1_cpu8file_NoLigatureCombinedString(int Popt,WUCS *Ppucs,int Pucsctr,USHORT *Ppattr,SMALL_RECT *Ptgtrect);//~v6VgI~
	#ifndef FFF                                                    //~v7frI~
		#ifndef WXE                                                //~v7frI~
			int uvio_getcombinectr(int Popt,WUCS *Ppucs,int Pchwidth,UCHAR *Ppdbcs,int Plen,int *Ppstrucsctr,int *Ppstrwidth);//~v7frI~
            #define GCCO_NOFMT    0x01  //exclude format except ZWJ(200d)//~v7frI~
		#endif                                                     //~v7frI~
	#endif                                                         //~v7frI~
#endif                                                             //~v6V5I~
//*********************************************************************//~v5n8I~
//* get scr info                                                   //~v5n8I~
//*   get dbcstbl addr from xe                                     //~v5n8I~
//*   opt is same as Gudbcschk_flagget dbcstbl addr from xe        //~v5n8I~
//*********************************************************************//~v5n8I~
//void uviom_init(int Popt,ULONG Phconout,int Pscrwidth,int Pscrsize,int Ptoplineoffs)//~v5n8R~//~v6hhR~
#ifdef W32  //copy is on uvioml.c for LNX                          //~v7bGI~.//~v7bGI~
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
    UTRACEP("%s:Stoplineoffs=%d\n",UTT,Stoplineoffs);              //~v7f8I~
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
#endif  //W32                                                      //~v7bGI~.//~v7bGI~
//*********************************************************************//~v62UR~
//set Guviomopt2: dbcs padding char display                        //~v62UR~
//dispchstr:unpdisp+tabdisp                                        //~v62UR~
//*********************************************************************//~v62UR~
//void uviom_setopt2(int Popt,unsigned char *Ppdispch)             //~v652R~
int uviom_setopt2(int Popt,unsigned char *Ppdispch)                //~v652I~
{                                                                  //~v62UR~
    int ch,altch;                                                  //~v65pI~
//*************************                                        //~v62UR~
	UTRACEP("%s:opt=%04x,dispch=%p\n",UTT,Popt,Ppdispch);          //~v7eAR~
	if (Popt & UVIOMO2_NOTIFY_DBCSSPACEALT) // 0x0100 //dbcsspacealt was changed//~v6FcI~
    {                                                              //~v6FcI~
		UTRACEP("%s:dispch=%02x\n",UTT,*Ppdispch);                 //~v7eAI~
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
        UTRACEP("%s:TABPADCHAR altch=%04x\n",UTT,altch);           //~v7efI~
    }                                                              //~v65pI~
    else                                                           //~v65pI~
    if (ch<0x20)                                                   //~v65pI~
    {                                                              //~v65pI~
    	if ((altch=UTF_GETALTCH_CTL(ch))>0)                        //~v65pI~
        	ch=altch;                                              //~v65pI~
        UTRACEP("%s:CTL altch=%04x\n",UTT,altch);                  //~v7efI~
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
#ifdef W32  //copy is on uvioml.c for LNX                          //~v7bGI~.//~v7bGI~
int uviom_notify(int Popt,int P1,int P2)                           //~v652I~
{                                                                  //~v652I~
//*************************                                        //~v652I~
    UTRACEP("%s:csrpos opt=%04x,p1=%d,p2=%d\n",UTT,Popt,P1,P2);    //~v7efI~
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
      #ifdef XXE                                                   //~vbzPR~
		Gutfcombaltch=(WUCS)P1;                                    //~v6EqI~
      #else                                                        //~vbzPR~
		Gutfcombaltch=(WUCS)P1;                                    //~vbzPI~
		Scombaltch=P1;                                             //~v658I~
#ifdef GGG                                                         //~v6W6R~
#else                                                              //~v6W6I~
	uviom_clearscr(0);                                             //~v6W6I~
#endif                                                             //~v6W6I~
    #endif                                                         //~v6EqI~
UTRACEP("%s:UVIOMNO_ALTCH opt=%x,p1=%x,p2=%x\n",UTT,Popt,P1,P2);   //~v6W2R~
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
#endif  //copy is on uvioml.c for LNX                          //~v7bGI~.//~v7bGI~
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
#ifdef W32  //copy is on uvioml.c for LNX                          //~v7bGI~.//~v7bGI~
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
#endif //W32                                                         //~v7bGI~.//~v7bGR~
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
    UTRACEP("%s:WriteConsoleOutputW rc=%d,written Top=%d,left=%d,bottom=%d,right=%d\n",UTT,rc,Ptgtrect->Top,Ptgtrect->Left,Ptgtrect->Bottom,Ptgtrect->Right);//~v656I~//~v7fmR~
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
//*****************************************************************//~v6T5I~
//*write by OutputCharW+OutputAttr                                 //~v6T5I~
//*****************************************************************//~v6T5I~
int uvioWriteConsoleOutputCharacterWwithAttr(int Popt,WUCS *Ppucs,int Pucsctr,COORD Ptgtpos,int *Ppwritelen,USHORT *Pattr,int Pattrlen)//~v6T5I~
{                                                                  //~v6T5I~
    int rc;                                                        //~v6T5I~
//********************                                             //~v6T5I~
    UTRACEP("%s:Popt=%x,attrlen=%d,ucsctr=%d,tgtpos=%d,ucs=%04x-%04x\n",UTT,Popt,Pattrlen,Pucsctr,Ptgtpos.X,*Ppucs);//~v6T5I~
    UTRACED("Ppucs",Ppucs,Pucsctr*(int)sizeof(WUCS));              //~v6T5I~
    UTRACED("Pattr",Pattr,Pattrlen*(int)sizeof(USHORT));           //~v6T5I~
    rc=uvioWriteConsoleOutputCharacterW(Shconout,Ppucs,Pucsctr,Ptgtpos,Ppwritelen); //len written//~v6T5I~
    rc+=WriteConsoleOutputAttribute(Shconout,Pattr,Pattrlen,Ptgtpos,Ppwritelen)==0;			//writelen//~v6T5R~
    UTRACEP("%s:WriteConsoleOutputAttribute rc=%d,len=%d,pos=X=%d,Y=%d\n",UTT,rc,Pattrlen,(int)Ptgtpos.X,(int)Ptgtpos.Y);//~v7fkR~
    UTRACED("WriteConsoleOutputAttribute",Pattr,Pattrlen*sizeof(USHORT));//~v7fkI~
    return rc;                                                     //~v6T5I~
}//uvioWriteConsoleOutputCharacterWwithAttr                        //~v6T5I~
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
    rc+=WriteConsoleOutputAttribute(Shconout,Pattr,Pchwidth,Ptgtpos,Ppwritelen)==0;			//writelen//~v6T5I~
    UTRACEP("%s:WriteConsoleOutputAttribute rc=%d,len=%d,pos=X=%d,Y=%d\n",UTT,rc,Pchwidth,(int)Ptgtpos.X,(int)Ptgtpos.Y);//~v7fkR~
    UTRACED("WriteConsoleOutputAttribute",Pattr,Pchwidth*sizeof(USHORT));//~v7fkI~
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
//#ifndef TEST2                                                    //~v7acR~
//    if (*Ppucs==0x25cf)                                          //~v7acR~
//    {                                                            //~v7acR~
//        WUCS tmp[2];                                             //~v7acR~
//        tmp[0]=*Ppucs;                                           //~v7acR~
//        tmp[1]='a'; //*Ppucs;                                    //~v7acR~
//        Ppucs=tmp;                                               //~v7acR~
//        Plen=2;                                                  //~v7acR~
//        UTRACEP("%s:tmp\n",UTT);                                 //~v7acR~
//        UTRACED("Ppucs",Ppucs,ctr2szW(Plen));                    //~v7acR~
//    }                                                            //~v7acR~
//#endif                                                           //~v7acR~
    rc=WriteConsoleOutputCharacterW(Phandle,                       //~v656I~
                                    	Ppucs,                     //~v656R~
//                                  	Plen,    //charcnt         //~v656I~//~v6hdR~
                                    	(DWORD)Plen,    //charcnt  //~v6hdI~
                                    	Ptgtpos, //pos write into  //~v656I~
//                                  	Ppwritelen);//len written  //~v656R~//~v6hdR~
                                    	&dwlen);//len written      //~v6hdI~
    UTRACEP("%s:WriteConsoleOutputCharacterW len=%d,posx=%d,posy=%d,ucs[0]=%04x\n",UTT,Plen,Ptgtpos.X,Ptgtpos.Y,*Ppucs);//~v7fkR~
    UTRACED("WriteConsoleOutputCharacterW Ppucs",Ppucs,ctr2szW(Plen));                          //~v6D6R~//~v7fkM~
    if (!rc)                                                       //~v656I~
    	uerrapi0("WriteConsoleOutputCharacterW",GetLastError());   //~v656I~
//#ifndef TEST2                                                    //~v7acR~
//    dwlen=1;                                                     //~v7acR~
//    Plen=1;                                                      //~v7acR~
//#endif                                                           //~v7acR~
    *Ppwritelen=dwlen;                                             //~v6hdI~
#ifdef CCC                                                         //~v7bmI~
	if (SswLocalefile)  //from uviowrtcellW1_localefile            //~vbzJM~
		uvioSaveCellDataLocalefileW(0,Ppucs,Plen,Ptgtpos.Y/*row*/,Ptgtpos.X/*col*/);//~vbzJR~
#endif                                                             //~v7bmI~
    UTRACEP("%s:rc=%d,outlen=%d,inplen=%d,posx=%d,posy=%d,ucs[0]=%04x\n",UTT,rc,dwlen,Plen,Ptgtpos.X,Ptgtpos.Y,*Ppucs);//~v6BXR~//~v6D7R~
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
    UTRACEP("%s:FillConsoleOutputCharacter char=%02x,rc=%d,len=%d,posX=%d,posY=%d\n",UTT,Pchar,rc,Plen,(int)Ptgtpos.X,(int)Ptgtpos.Y);//~v7fkR~
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
    UTRACEP("%s:FillConsoleOutputCharacterW ucs=%04x,rc=%d,len=%d,posX=%d,posY=%d\n",UTT,Pchar,rc,Plen,(int)Ptgtpos.X,(int)Ptgtpos.Y);//~v7fkR~
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
    UTRACED("uviowrtcellW Ppdbcs",Ppdbcs,(size_t)Plen);            //~v700R~
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
	    UTRACEP("%s:WriteConsoleOutputAttribute rc=%d,len=%d,pos=X=%d,Y=%d\n",UTT,rc,Plen,(int)Ptgtpos.X,(int)Ptgtpos.Y);//~v7fkR~
    	UTRACED("WriteConsoleOutputAttribute",Ppattr,Plen*sizeof(USHORT));//~v7fkR~
        writelen=(int)dwlen;                                       //~v6hdI~
        if (rc2)                                                   //~v659I~
        {                                                          //~v659I~
            uerrapi0("clearline WriteConsoleOutputAttribute",GetLastError());//~v659I~
            rc++;                                                  //~v659I~
        }                                                          //~v659I~
        UTRACEP("%s:writeattr rc2=%d,*attr=%02x,row=%d,col=%d,Plen=%d,writelen=%d\n",UTT,rc2,*Ppattr,Ptgtpos.Y,Ptgtpos.X,Plen,writelen);//~v7fkR~
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
        UTRACEP("%s:fillattr rc=%d,attr=%02x,pos=%d,len=%d,writelen=%d\n",UTT,rc2,*Ppattr,(int)Ptgtpos.X,Plen,writelen);//~v7fkR~
    }                                                              //~v65aI~
	rc2=uvioFillConsoleOutputCharacterW(Shconout,wucsspace,Plen,Ptgtpos,&writelen)==0;//~v659I~
    if (rc2)                                                       //~v659I~
        rc++;                                                      //~v659I~
    UTRACEP("%s:FillConsoleOutputChar ch=%02x,opt=%02x,rc2=%d,row=%d,col=%d,Plen=%d,writelen=%d\n",UTT,wucsspace,Popt,rc2,Ptgtpos.Y,Ptgtpos.X,Plen,writelen);//~v7fkR~
    return rc;                                                     //~v659I~
}//uviom_clearlineW                                                //~v659I~
#ifndef EEE                                                        //~v7fpI~
int uviom_clearlineW2(int Popt,PCHAR_INFO Ppchi,USHORT *Ppattr,int Plen,COORD Ptgtpos)//~v7fpI~
{                                                                  //~v7fpI~
//#define ATTR_PADDING_WINCON   BACKGROUND_INTENSITY     //0x0080 // background color is intensified.//~v7fpR~
#define ATTR_PADDING_WINCON   COMMON_LVB_UNDERSCORE    //0x8000 // DBCS: Underscore.//~v7fpR~
    WUCS wucsspace=' ';                                            //~v7fpI~
    int rc=0,rc2,writelen;                                         //~v7fpI~
    DWORD dwlen;                                                   //~v7fpI~
    USHORT attr;                                                   //~v7fpR~
    USHORT wkAttrPadding[UVIOM_MAXCOL];                            //~v7fpI~
//********************************                                 //~v7fpI~
    UTRACEP("%s:writeattr opt=%02x,*attr=%02x,row=%d,col=%d,Plen=%d\n",UTT,Popt,*Ppattr,Ptgtpos.Y,Ptgtpos.X,Plen);//~v7fpI~
	if (Popt & UVIOMCLO_ATTRSTR)                                   //~v7fpI~
    {                                                              //~v7fpI~
    	UTRACED("WriteConsoleOutputAttribute",Ppattr,Plen*sizeof(USHORT));//~v7fpR~
        for (int ii=0;ii<Plen;ii++)                                //~v7fpI~
        	wkAttrPadding[ii]=Ppattr[ii]|ATTR_PADDING_WINCON;      //~v7fpR~
    	UTRACED("WriteConsoleOutputAttribute",wkAttrPadding,Plen*sizeof(USHORT));//~v7fpI~
    	rc2=WriteConsoleOutputAttribute(Shconout,wkAttrPadding,(DWORD)Plen,Ptgtpos,&dwlen)==0;			//writelen//~v7fpI~
        writelen=(int)dwlen;                                       //~v7fpI~
        if (rc2)                                                   //~v7fpI~
        {                                                          //~v7fpI~
            uerrapi0("clearline WriteConsoleOutputAttribute",GetLastError());//~v7fpI~
            rc++;                                                  //~v7fpI~
        }                                                          //~v7fpI~
        UTRACEP("%s:ATTRSTR rc=%d,writelen=%d\n",UTT,rc2,writelen);//~v7fpI~
    }                                                              //~v7fpI~
	if (Popt & UVIOMCLO_ATTRFILL)                                  //~v7fpI~
    {                                                              //~v7fpI~
    	attr=*Ppattr;                                              //~v7fpR~
        attr|=ATTR_PADDING_WINCON;                                 //~v7fpI~
        rc2=FillConsoleOutputAttribute(Shconout,attr,(DWORD)Plen,Ptgtpos,&dwlen)==0;     //clear also attr(else remains previous attr after this times 0x1b)//~v7fpR~
        writelen=(int)dwlen;                                       //~v7fpI~
        if (rc2)                                                   //~v7fpI~
        {                                                          //~v7fpI~
            uerrapi0("clear line FillConsoleOutputAttribute",GetLastError());//~v7fpI~
            rc++;                                                  //~v7fpI~
        }                                                          //~v7fpI~
        UTRACEP("%s:fillattr rc=%d,writelen=%d\n",UTT,rc2,writelen);//~v7fpI~
    }                                                              //~v7fpI~
	rc2=uvioFillConsoleOutputCharacterW(Shconout,wucsspace,Plen,Ptgtpos,&writelen)==0;//~v7fpI~
    if (rc2)                                                       //~v7fpI~
        rc++;                                                      //~v7fpI~
    UTRACEP("%s:FillConsoleOutputChar ch=%02x,opt=%02x,rc2=%d,row=%d,col=%d,Plen=%d,writelen=%d\n",UTT,wucsspace,Popt,rc2,Ptgtpos.Y,Ptgtpos.X,Plen,writelen);//~v7fpI~
    return rc;                                                     //~v7fpI~
}//uviom_clearlineW                                                //~v7fpI~
#endif                                                             //~v7fpI~
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
        Sposcvhex=poscvhex;                                        //~v7ejI~
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
//    		&&  UTF_COMBINABLE(ucs)                                //~v6EgI~//~v6WsR~
        	&&  COMBINEMODE(Popt)                                  //~v6EiI~
	        &&  UDBCSCHK_ISUCSWIDTH0(*(pdbcs+1))	//next is combine char with different attr//~v6EgI~
      		&&  UTF_COMBINABLE(ucs)                                //~v6WsI~
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
//  CHAR_INFO wkcombinechi[(UVIOM_MAXCOMBINE+1)*2],*pwchi;         //~v650R~//~v6VgR~
//  USHORT attrcmb;                                                //~v650I~//~v6VgR~
//  WUCS   *pucscmb;                                               //~v650R~//~v6VgR~
//  WUCS   wkucscombine[UVIOM_MAXCOMBINE];                         //~v652R~
//  COORD  srcbufsz,posinsrcbuff;                                  //~v650I~//~v6VgR~
//  COORD tgtpospadding;                                           //~v652R~
	SMALL_RECT	targetrect;                                        //~v650I~
//  int chictr;                                                    //~v650I~//~v6VgR~
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
    int strucsctr,strwidth;                                        //~v6VgR~
    int combinecols;                                               //~v6VgI~
//************************                                         //~v5n8I~
    UTRACEP("%s:Popt=%04x,len=%d,src pos=%08x,box=%08x\n",UTT,Popt,Plen,Psrcpos,Psrcbox);//~v6EiR~
    UTRACEP("%s:Ptgtrect (%d,%d)-(%d,%d)\n",UTT,Ptgtrect->Left,Ptgtrect->Top,Ptgtrect->Right,Ptgtrect->Bottom);//~v7edR~
    UTRACED("writecellW1 Ppchi",Ppchi,sizeof(CHAR_INFO)*Plen);     //~v7ekR~
//  UTRACED("writecellW1 srcpos",&Psrcpos,sizeof(COORD));          //~v700R~
//  UTRACED("uviowrtcellW1 inp chibuff",Ppchi,Plen*sizeof(CHAR_INFO));//~v5n8I~//~v700R~
	if (!Sdbcsspacealt)                                            //~v6G0M~
    	Sdbcsspacealt=UTF_GETALTCH_DBCS();                         //~v6G0M~
	Sposcvhex=-1;	//parm to W0W                                  //~v7ejI~
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
          if (!m2uopt)	//of locale string                         //~v6P0R~
          {                                                        //~v6P0I~
//      	escsw=1;                                               //~v5n8I~//~v65iR~
        	escsw|=1;                                              //~v65iR~
          }                                                        //~v6P0I~
#ifdef UTF8UCS2                                                    //~v640I~
        if (!ch)                                                   //~v640I~
        	if (!*pdbcs)	//sbcs                                 //~v640I~
                ch=' ';                                            //~v640I~
#endif                                                             //~v640I~
//  	if (ch<0x20)                                               //~v65iM~//~v6P0R~
    	if (ch<0x20 && !m2uopt)	//of locale string                 //~v6P0R~
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
//    if (ch<0x20 && noligid)                                      //~v6EaR~//~v6P0R~
      if (ch<0x20 && noligid && !m2uopt)	//of locale string     //~v6P0R~
    	*pattr++=(pchi->Attributes & 0xf0)|ATTR_CTLCHAR_FG;        //~v6EaR~
      else                                                         //~v6EaR~
#endif                                                             //~v6EaR~
    	*pattr++=pchi->Attributes;                                 //~v5n8R~
        pdbcs++;                                                   //~v62BI~
    }                                                              //~v5n8I~
#ifdef UTF8UCS2                                                    //~v640I~
  if (m2uopt)                                                      //~v640I~
  {                                                                //~v7bnI~
	uvio_mdd2u(m2uopt,pdata0,Ppdbcs,Plen,pucs0,Plen*WUCSSZ,&ucsctr,0/*outdbcsucsctr*/,0/*outsbcsucsctr*/);//~v640R~
#ifdef WINCON   //WXE write errmsg to buffer                       //~v7bnI~
    if (Popt & (UVIOO_ERRMSG|UVIOO_ERRMSG2))     //        0x80/0x0400       //special for uerrmsg//~v7bnI~
//	    uvioSaveCellDataDD(Popt,pdata0,Ppdbcs,Plen,pucs0,ucsctr,Ptgtrect->Top,Ptgtrect->Left);//~v7edR~
  	    uvioSaveCellDataDD(Popt,pdata0,Ppdbcs,Plen,pucs0,ucsctr,Ptgtrect->Top-Stoplineoffs,Ptgtrect->Left);//~v7edI~
#endif                                                             //~v7bnI~
  }                                                                //~v7bnI~
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
UTRACEP("%s:row=%d len=%d,ucsctr=%d,shrinkctr=%d,swunprintable8859=%d\n",UTT,Ptgtrect->Top-Stoplineoffs,Plen,ucsctr,shrinkctr,sw8859unp);//~v7c4R~
UTRACED("pdata",pdata0,Plen);                        //~v5n8I~     //~v7c4R~
UTRACED("pdbcs",Ppdbcs,Plen);                        //~v5n8I~     //~v7c4R~
UTRACED("ucs",pucs0,ucsctr*WUCSSZ);                    //~v5n8R~//~v65mR~//~v7c4R~
UTRACED("attr",pattr0,Plen*2);                       //~v5n8I~     //~v7c4R~
UTRACEP("%s:Shconout=%p\n",UTT,Shconout);                          //~v700I~
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
    	UTRACEP("%s:tgtrect top=%d,toplineoffs=%d,Scsrposy=%d\n",UTT,Ptgtrect->Top,Stoplineoffs,Scsrposy);//~v7ekR~
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
   			if (tgtpos.Y==Scsrposy+Stoplineoffs)	//csr line     //~v7ejI~
    		{                                                      //~v7ejI~
        		UTRACEP("%s:csr line Y=%d X=%d,top=%d,csrY=%d\n",UTT,tgtpos.Y,tgtpos.X,Stoplineoffs,Scsrposy);//~v7ejI~
				utfddgetcsrposbca(0,Ppdbcs-tgtpos.X,Plen+tgtpos.X,Scsrposx,&posb,&posc,&posa);//~v7ejI~
    		}                                                      //~v7ejI~
   			if (tgtpos.Y==Svhexcsrposy+Stoplineoffs)	//csr line //~v7ejI~
    		{                                                      //~v7ejI~
        		UTRACEP("%s:vhexcsr line Y=%d X=%d,top=%d,csrY=%d\n",UTT,tgtpos.Y,tgtpos.X,Stoplineoffs,Svhexcsrposy);//~v7ejI~
				utfddgetcsrposbca(0,Ppdbcs-tgtpos.X,Plen+tgtpos.X,Svhexcsrposx,&posbvhex,&poscvhex,0/*after*/);//~v7ejI~
		        Sposcvhex=poscvhex;                                //~v7ejI~
    		}                                                      //~v7ejI~
            UTRACEP("%s:Gulibutfmode=%08x\n",UTT,Gulibutfmode);    //~v7f8I~
		if (COMBINEMODE(Popt))  //combine                          //~v6G0I~
			rc=uviowrtcellW1_cpu8file_NoLigatureCombine(Popt,pucs0,ucsctr,pdata0,Ppdbcs,pattr0,Plen,Ptgtrect);//~v6G0R~
        else                                                       //~v6G0I~
//  		rc=uviowrtcellW1_cpu8file_NoLigatureNoCombine(Popt,pucs0,ucsctr,pdata0,Ppdbcs,pattr0,Plen,Ptgtrect);//~v6G0R~//~v6WuR~
    		rc=uviowrtcellW1_cpu8file_NoLigatureNoCombine(Popt|UVIOO_COMBINEOFF,pucs0,ucsctr,pdata0,Ppdbcs,pattr0,Plen,Ptgtrect);//~v6WuI~
      }                                                            //~v6G0I~
      else                                                         //~v6G0I~
#endif                                                             //~v6G0I~
      {                                                            //~v652M~
//********************* utf8 data of not file panel(=1,dirlist) or ligaturemode on ***************************//~v6VgI~
//*!m2uopt :uviowrtcellW1_localefile                               //~v6VgI~
//*!shrinkctr=0(all ascii):uviowrtcellW1_NonLigatureLine || uvioWriteConsoleOutputCharacterW1withAttrN//~v6VgI~
//Popt & UVIOO_LIGATURE2(errmsg,cmdline,pan00-LC line):uviowrtcellW1_NonLigatureLine//~v6VgI~
//**** Popt & UVIOO_FORCELIGATURE(dirlist):uviowrtcellW1_ligature ===> FORCELIGATURE is not used now.//~v6VgI~
//LIGATUREMODE() && (Popt & UVIOO_CSRPOSCHK(file panel):uviowrtcellW1_ligature//~v6VgI~
//   LIGATUREMODE: UVIOO_LIGATURE1(file panel) && UTF_LIGATUREMODE(Gulibutfmode & GULIBUTFLIGATURE)//~v6VgI~
//Popt & UVIOO_CSRPOSCHK(file panel) && !LIGATUREMODE(Popt):       //~v6VgI~
//  COMBINEMODE(Popt):uviowrtcellW1_cpu8file_NoLigatureCombine     //~v6VgI~
//  else             :uviowrtcellW1_cpu8file_NoLigatureNoCombine   //~v6VgI~
//else                                                             //~v6VgI~
//  --> hdr, dirlist, =1, =2, =3.12, =3.14                         //~v6VgR~
//*****************************************************************//~v6VgI~
      	UTRACEP("%s:*** utf8 data of not file panel(=1,dirlist) or ligaturemode on; m2uopt=%x Popt=%x\n",UTT,m2uopt,Popt);//~v6VgI~
      	posa=posb=posc=-1;                                         //~v652I~
//      swcombinemode=(m2uopt && UTF_COMBINEMODE());//utf8 combine mode//~v6EiR~
        swcombinemode=(m2uopt && COMBINEMODE(Popt));//utf8 combine mode//~v6EiI~
        UTRACEP("%s:swcombinemode=%d\n",UTT,swcombinemode);        //~v7ekR~
     if (Popt & UVIOO_CSRPOSCHK)       // file data line,else no split of combining character//~v7ekI~
        if (swcombinemode) //ligature on                           //~v652I~
        {                                                          //~v658I~
   			if (tgtpos.Y==Scsrposy+Stoplineoffs)	//csr line     //~v652I~
    		{                                                      //~v652I~
        		UTRACEP("%s:csr line Y=%d X=%d,top=%d,csrY=%d\n",UTT,tgtpos.Y,tgtpos.X,Stoplineoffs,Scsrposy);//~v7ejR~
				utfddgetcsrposbca(0,Ppdbcs-tgtpos.X,Plen+tgtpos.X,Scsrposx,&posb,&posc,&posa);//~v652R~
    		}                                                      //~v652I~
   			if (tgtpos.Y==Svhexcsrposy+Stoplineoffs)	//csr line //~v658I~
    		{                                                      //~v658I~
        		UTRACEP("%s:vhex csr line Y=%d X=%d,top=%d,csrY=%d\n",UTT,tgtpos.Y,tgtpos.X,Stoplineoffs,Scsrposy);//~v7ejI~
				utfddgetcsrposbca(0,Ppdbcs-tgtpos.X,Plen+tgtpos.X,Svhexcsrposx,&posbvhex,&poscvhex,0/*after*/);//~v658I~
		        Sposcvhex=poscvhex;                                //~v7ejI~
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
//#ifdef UTF8UCS2                                                    //~v650I~//~v6VgR~
//        if (UTF_COMBINEMODE())                                   //~v652R~
#ifdef MMM                                                         //~v6VgI~
#ifdef UTF8UTF16                                                   //~v6uBI~
          if (swcombinemode && !swovf)//utf8 combine mode          //~v6uBI~
#else                                                              //~v6uBI~
          if (swcombinemode)//utf8 combine mode                    //~v652I~
#endif                                                             //~v6uBI~
#else                                                              //~v6VgI~
          if (swcombinemode)//utf8 combine mode ucs2 and ucs4      //~v6VgI~
#endif                                                             //~v6VgI~
          {                                                        //~v650I~
            strwidth=0; //for compiler warning                     //~v6XbI~
            strucsctr=0; //for compiler warning                    //~v6XbI~
	        attr=pattr0[col];                                      //~v653R~
//* after fill space and WriteConsoleOutputAttribute for the line  //~v650I~
//* write non space padding for combining char                     //~v650I~
//* then use WiriteConsoleOutput(char+attr) for base+combining char//~v650R~
#ifdef MMM                                                         //~v6VgI~
            if (combinectr)                                        //~v650I~
            {                                                      //~v650I~
                combinectr--;                                      //~v650I~
            }                                                      //~v650I~
            else                                                   //~v650I~
#endif                                                             //~v6VgI~
            {                                                      //~v650I~
                if (attr==attro)                                   //~v656I~
                {                                                  //~v656I~
//#ifdef WWW                                                         //~v6BYI~//~v6BZR~
//              	combinectr=uvio_getcombinectr(0,*pucs,chwidth,pdbcs,ucsctr-ii);//~v656R~//~v6VgR~
//              	combinectr=uvio_getcombinectr(0,pucs,chwidth,pdbcs,ucsctr-ii,&strucsctr,&strwidth);//~v7eaR~
                	combinectr=uvio_getcombinectr(0,pucs,chwidth,pdbcs,Plen-PTRDIFF(pdbcs,Ppdbcs),&strucsctr,&strwidth);//~v7eaI~
//#else                                                              //~v6BYI~//~v6BZR~
//                    combinectr=uvio_getcombinectrUCS(0,pucs,chwidth,pdbcs,ucsctr-ii);//~v6BYI~//~v6BZR~
//#endif                                                             //~v6BYI~//~v6BZR~
#ifdef MMM                                                         //~v6VgI~
                    if (combinectr)                                //~v656I~
                    {                                              //~v656I~
                		for (jj=1;jj<=combinectr;jj++)             //~v656R~
							if (attr!=pattr0[col+jj])              //~v656I~
                        	{                                      //~v656I~
                            	combinectr=jj-1;                   //~v656R~
                                break;                             //~v656I~
                            }                                      //~v656I~
                    }                                              //~v656I~
#endif //MMM                                                       //~v6VgI~
                }                                                  //~v656I~
                else                                               //~v656I~
                	combinectr=0;                                  //~v656I~
UTRACEP("combinectr=%d,atto=%d,attrn=%d,col=%d,rcol=%d\n",combinectr,attro,attr,tgtpos.X,col);//~v656M~
              if (Popt & UVIOO_CSRPOSCHK)         //file edit panel,will not reach to dis line//~v6VgI~
              {                                                    //~v6VgI~
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
              }//CSRPOSCHK                                         //~v6VgR~
                  if (combinectr) //acceptable combine             //~v656R~
                  {                                                //~v656R~
#ifndef MMM                                                        //~v6VgR~
						UTRACEP("%s:write combinedstr combinectr=%d,tgtposX=%d\n",UTT,combinectr,tgtpos.X);//~v6VgR~
                        targetrect=*Ptgtrect;                      //~v6VgI~
                        targetrect.Left=tgtpos.X;                  //~v6VgR~
                        targetrect.Right=tgtpos.X+(SHORT)(strwidth-1);//~v6VgR~
                		rc+=uviowrtcellW1_cpu8file_NoLigatureCombinedString(Popt,pucs,strucsctr,pattr0+tgtpos.X,&targetrect);//~v6VgR~
                        chwidth=strwidth;                          //~v6VgI~
                        pucs+=strucsctr-1;                         //~v6VgR~
                        ii+=strucsctr-1;                           //~v6VgI~
#else                                                              //~v6VgI~
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
#endif //MMM                                                       //~v6VgI~
                }                                                  //~v650I~
                else                                               //~v650I~
                {                                                  //~v650I~
                //*combinectr=0                                    //~v6VgI~
		   		  if (swovf) //ucs4                                //~v6VgI~
           		  {                                                //~v6VgI~
UTRACEP("%s: combinemodemode not combining char OVF ucs=%04x-%04x,col=%d,chwidth=%d\n",UTT,*pucs,*(pucs+1),tgtpos.X,chwidth);//~v6VgI~
            		if (!uvioWriteConsoleOutputCharacterW1withAttr1(0,Shconout,pucs,2,tgtpos,&writelen,Ptgtrect,pattr,chwidth)) //len written//~v6VgI~
		               	rc++;                                      //~v6VgI~
                    ii++;                                          //~v6VgI~
                    pucs++;                                        //~v6VgI~
                                                                   //~v6VgI~
           		  }                                                //~v6VgI~
                  else                                             //~v6VgI~
                  {                                                //~v6VgI~
//#ifdef DDD                                                         //~v6D7I~//~v6VgR~
//#ifdef AAA                                                         //~v6C8R~//~v6VgR~
//                    rc2=uvioWriteConsoleOutputCharacterW(Shconout,pucs,1,tgtpos,&writelen);//~v656I~//~v6VgR~
//#else                                                              //~v6C7I~//~v6VgR~
//#ifdef KKK                                                         //~v6D7I~//~v6VgR~
//                    rc2=uvioWriteConsoleOutputCharacterW1withAttr(Shconout,pucs,1,Ptgtrect,tgtpos,&writelen,pattr0[tgtpos.X]);//~v6C7R~//~v6C8R~//~v6VgR~
//#else                                                              //~v6D7I~//~v6VgR~
//                    rc2=uvioWriteConsoleOutputCharacterW1withAttrCHW(Shconout,pucs,1,chwidth,Ptgtrect,tgtpos,&writelen,pattr0[tgtpos.X]);//~v6D7I~//~v6VgR~
//#endif                                                             //~v6D7I~//~v6VgR~
//#endif                                                             //~v6C7I~//~v6VgR~
//#else  //!DDD                                                      //~v6D7I~//~v6VgR~
	#ifndef NNN                                                    //~v6F7R~
            	    rc2=uvioWriteConsoleOutputCharacterW1withAttr1(0,Shconout,pucs,1,tgtpos,&writelen,Ptgtrect,pattr,chwidth); //len written//~v6F7R~
	#else                                                          //~v6F7R~
            		rc2=uvioWriteConsoleOutputCharacterW(Shconout,pucs,1,tgtpos,&writelen);//~v6D7I~
	#endif                                                         //~v6F7R~
//#endif                                                             //~v6D7I~//~v6VgR~
                  }//!svovf                                        //~v6VgI~
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
//*not combinemode : swcombinemode=(m2uopt && COMBINEMODE(Popt));//utf8 combine mode//~v6VgR~
//#endif  //UTFUCS2                                                           //~v650I~//~v6VgR~
          {                                                        //~v650I~
#ifdef UTF8UTF16                                                   //~v6uBI~
#ifdef MMM                                                         //~v6VgM~
#else                                                              //~v6VgM~
           if (m2uopt              //dd fmt line                   //~v6VgI~
           &&  !COMBINEMODE(Popt)  //split/rep mode                //~v6VgI~
           &&  (combinecols=uviom_ISUCSWIDTH0W(0,pucs,pdbcs,ucsctr-ii),combinecols) //start from ucs2/ucs4 combining char//~v6VgI~
              )                                                    //~v6VgI~
           {                                                       //~v6VgI~
          		UTRACEP("%s:!combine mode Y=%d,X=%d, combinecols=%d,*pdbcs=%x\n",UTT,tgtpos.Y,tgtpos.X,combinecols,*pdbcs);//~v6VgM~
                rc+=uviom_wrtW0W(0,pucs,pattr+tgtpos.X,combinecols,tgtpos,&writelen);//~v6VgM~
                chwidth=combinecols;	//2 for ucs4               //~v6VgM~
		   		if (swovf) //ucs4                                  //~v6VgI~
           		{                                                  //~v6VgI~
            		ii++;    //vs. loop limit ucsctr               //~v6VgI~
            		pucs++; //printed 2 ucs2                       //~v6VgI~
                }                                                  //~v6VgI~
           }                                                       //~v6VgI~
		   else                                                    //~v6VgI~
#endif    //!MMM                                                   //~v6VgM~
		   if (swovf) //ucs4                                       //~v6uBI~
           {                                                       //~v6uBI~
//#ifdef DDD                                                         //~v6D7I~//~v6VgR~
//#ifdef AAA                                                         //~v6C8I~//~v6VgR~
//            if (!uvioWriteConsoleOutputCharacterW(Shconout,pucs,2,tgtpos,&writelen)) //len written//~v6uBI~//~v6VgR~
//#else                                                              //~v6C8I~//~v6VgR~
//#ifdef KKK                                                         //~v6D7I~//~v6VgR~
//            if (!uvioWriteConsoleOutputCharacterW1withAttr(Shconout,pucs,2,Ptgtrect,tgtpos,&writelen,pattr0[tgtpos.X])) //len written//~v6C8I~//~v6VgR~
//#else                                                              //~v6D7I~//~v6VgR~
//            if (!uvioWriteConsoleOutputCharacterW1withAttrCHW(Shconout,pucs,2,chwidth,Ptgtrect,tgtpos,&writelen,pattr0[tgtpos.X])) //len written//~v6D7I~//~v6VgR~
//#endif                                                             //~v6D7I~//~v6VgR~
//#endif                                                             //~v6C8I~//~v6VgR~
//#else    //!DDD                                                    //~v6D7I~//~v6VgR~
	#ifndef NNN                                                    //~v6F7R~
            if (!uvioWriteConsoleOutputCharacterW1withAttr1(0,Shconout,pucs,2,tgtpos,&writelen,Ptgtrect,pattr,chwidth)) //len written//~v6F7R~
	#else                                                          //~v6F7R~
            if (!uvioWriteConsoleOutputCharacterW(Shconout,pucs,2,tgtpos,&writelen)) //len written//~v6D7I~
	#endif                                                         //~v6F7R~
//#endif                                                             //~v6D7I~//~v6VgR~
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
//#ifdef DDD                                                         //~v6D7I~//~v6VgR~
//#ifdef AAA                                                         //~v6C8I~//~v6VgR~
//                if (!uvioWriteConsoleOutputCharacterW(Shconout,pucs,2,tgtpos,&writelen)) //len written//~v6BSR~//~v6VgR~
//#else                                                              //~v6C8I~//~v6VgR~
//#ifdef KKK                                                         //~v6D7I~//~v6VgR~
//                if (!uvioWriteConsoleOutputCharacterW1withAttr(Shconout,pucs,2,Ptgtrect,tgtpos,&writelen,pattr0[tgtpos.X])) //len written//~v6C8I~//~v6VgR~
//#else                                                              //~v6D7I~//~v6VgR~
//                if (!uvioWriteConsoleOutputCharacterW1withAttrCHW(Shconout,pucs,2,chwidth,Ptgtrect,tgtpos,&writelen,pattr0[tgtpos.X])) //len written//~v6D7I~//~v6VgR~
//#endif                                                             //~v6D7I~//~v6VgR~
//#endif                                                             //~v6C8I~//~v6VgR~
//#else    //!DDD                                                    //~v6D7I~//~v6VgR~
	#ifndef NNN                                                    //~v6F7R~
                if (!uvioWriteConsoleOutputCharacterW1withAttr1(0,Shconout,pucs,2,tgtpos,&writelen,Ptgtrect,pattr,chwidth)) //len written//~v6F7R~
	#else                                                          //~v6F7R~
            	if (!uvioWriteConsoleOutputCharacterW(Shconout,pucs,2,tgtpos,&writelen)) //len written//~v6D7I~
	#endif                                                         //~v6F7R~
//#endif                                                             //~v6D7I~//~v6VgR~
                	rc++;                                          //~v6BSI~
                ii++;                                              //~v6BSI~
                pucs++;                                            //~v6BSI~
            }                                                      //~v6BSI~
#ifdef MMM //moved up                                              //~v6VgI~
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
#endif //MMM                                                       //~v6VgI~
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
    UTRACEP("%s:WriteConsoleOutputCharacterW len=%d,posx=%d,posy=%d\n",UTT,Plen,coord.X,coord.Y);//~v7fkR~
    UTRACED("WriteConsoleOutputCharacterW Ppucs",Ppucs,ctr2szW(Plen));//~v7fkI~
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
//  UTRACED("uvio_m2us outucs",Ppucs,*Poutucsctr*WUCSSZ);          //~v700R~
    return rc;                                                     //~v5n8I~
}//uvio_m2us                                                       //~v5n8I~
#endif //!WXE                                                      //~v5n8I~
#endif  //W32                                                      //~v5n8M~
                                                                   //~v5n8I~
#endif //WCSUPP                                                    //~v5n8R~
                                                                   //~v640I~
#ifdef UTF8UCS2                                                    //~v640I~
#ifdef W32                                                         //~v640I~
//**************************************************               //~v640I~
//*get ucs2 string from data/dbcs                                  //~v640I~
//**************************************************               //~v640I~
int uvio_mdd2u(int Popt,UCHAR *Ppdata,UCHAR *Ppdbcs,int Plen,WUCS *Ppucs,int Poutbuffsz,int *Ppoutucsctr,int *Ppucsdbcsctr,int *Ppucssbcsctr)//~v640R~
{                                                                  //~v640I~
    int opt;                                                       //~v640I~
//******************                                               //~v640I~
	UTRACED("data",Ppdata,Plen);                                   //~v7bmI~
	UTRACED("dbcs",Ppdbcs,Plen);                                   //~v7bmI~
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
#ifdef LNX                                                         //~v6VgI~
#else //W32                                                        //~v6VgI~
#ifndef WXE                                                        //~v6X1I~
//**************************************************               //~v6VgI~
//*get combine ctr                                                 //~v6VgI~
//Ppucsctr:ucsctr from combinable (may contains surrogate)         //~v6VgI~
//**************************************************               //~v6VgI~
int uvio_getcombinectr(int Popt,WUCS *Ppucs,int Pchwidth,UCHAR *Ppdbcs,int Plen,int *Ppstrucsctr,int *Ppstrwidth)//~v6VgR~
{                                                                  //~v6VgI~
	int combinectr=0,ii;                                           //~v6VgR~
    UCHAR *pcd;                                                    //~v6VgI~
    int swcombine;                                                 //~v6VgR~
//  WUCS *pucs,ucs;                                                //~v6VgI~//~v6WsR~
    WUCS *pucs;                                                    //~v6WsI~
    int baseucs,utf16ctr;                                          //~v6WsI~
    int chsz;                                                      //~v6X1I~
//***********************                                          //~v6VgI~
	UTRACEP("%s:Pchwidth=%d,plen=%d,startUcs=%04x\n",UTT,Pchwidth,Plen,*Ppucs);//~v7eaR~
	UTRACED("Ppucs",Ppucs,Plen);                                   //~v7e9I~
    pcd=Ppdbcs;                                                    //~v6VgI~
//  ucs=*Ppucs;                                                    //~v6VgI~//~v6WsR~
//  pucs=Ppucs+1+IS_UTF16_HIGH(ucs);                               //~v6VgI~//~v6WsR~
    baseucs=STR_UTF16_TO_UCS4(Ppucs,Plen,&utf16ctr);               //~v6WsI~
    pucs=Ppucs+utf16ctr;                                           //~v6WsI~
//  if (UTF_COMBINABLE(ucs)                                        //~v6VgI~//~v6WsR~
//  && !uviom_ISUCSWIDTH0W(0,Ppucs,Ppdbcs,Plen))	//acceptable combine//~v6VgI~//~v6WsR~
    {                                                              //~v6VgI~
        for(pcd+=Pchwidth,ii=Pchwidth;ii<Plen && combinectr<UVIOM_MAXCOMBINE;ii++,pcd++,pucs++)//~v6VgI~
        {                                                          //~v6VgI~
UTRACEP("%s: chk dbcs=%x\n",UTT,*pcd);                             //~v6VgI~
//          swcombine=uviom_ISUCSWIDTH0W(0,pucs,pcd,Plen-ii);	//acceptable combine//~v6VgI~//~v6X1R~
//#ifndef FFF                                                      //+v7fsR~
#ifdef FFF                                                         //~v7frI~
          if (Popt & GCCO_NOFMT)//  0x01  //exclude format except ZWJ(200d)//~v7frR~
          {                                                        //~v7frI~
          	if (*pucs==ZWJ) //u-200d                               //~v7frI~
            	swcombine=1;                                       //~v7frI~
            else                                                   //~v7frI~
            {                                                      //~v7frI~
            	int optic=UVIOMICO_NOFMT;// 0x01   //exclude format//~v7frI~
	            swcombine=uviom_iscombining(optic,pucs,pcd,Plen-ii,0/*Ppucs4*/,&chsz);//~v7frI~
            }                                                      //~v7frI~
          }                                                        //~v7frI~
          else                                                     //~v7frI~
#endif                                                             //~v7frI~
            swcombine=uviom_iscombining(0,pucs,pcd,Plen-ii,0/*Ppucs4*/,&chsz);//~v6X1R~
            if (!swcombine)   //acceptable combine                 //~v6VgI~
                break;                                             //~v6VgI~
			if (!combinectr)	//top of combining                 //~v6WsR~
            {                                                      //~v6WsI~
				if (!UTF_COMBINABLE(baseucs)                       //~v6WsI~
		    	||  utf22_iswidth0W(0,baseucs))                    //~v6WsR~
        	        break;                                         //~v6WsR~
            }                                                      //~v6WsI~
            combinectr++;                                          //~v6VgI~
//          if (swcombine==2)                                      //~v6VgI~//~v6X1R~
            if (swcombine & UICRC_OVF)                             //~v6X1I~
            {                                                      //~v6VgI~
            	ii++,pcd++;                                        //~v6VgI~
				pucs++;                                            //~v6VgI~
			}                                                      //~v6VgI~
            else //sbcs or scm                                     //~v6X1I~
            if (swcombine>UICRC_SBCS)                              //~v6X1R~
            {                                                      //~v6X1I~
            	ii++,pcd++;                                        //~v6X1I~
			}                                                      //~v6X1I~
        }                                                          //~v6VgI~
    }                                                              //~v6VgI~
    *Ppstrucsctr=PTRDIFF(pucs,Ppucs)/sizeof(WUCS);                 //~v6VgR~
    *Ppstrwidth=PTRDIFF(pcd,Ppdbcs);                               //~v6VgR~
UTRACEP("%s:baseucs=%06x,utf16ctr=%d,dbcsid=x%x,ucs=%04x,combinectr=%d,strucsctr=%d,strwidth=%d\n",UTT,baseucs,utf16ctr,*Ppdbcs,*Ppucs,combinectr,*Ppstrucsctr,*Ppstrwidth);//~v6VgR~//~v6WsR~
    return combinectr;                                             //~v6VgI~
}//uvio_getcombinectr                                              //~v6VgI~
#endif //!WXE                                                      //~v6X1I~
//#endif //!XXE                                                      //~v6BYI~//~v6BZR~
//#endif //!LNX                                                      //~v6BYI~//~v6BZR~
#endif //!LNX                                                      //~v6VgI~
#ifdef W32                                                         //~v7bGI~
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
#endif //W32                                                       //~v7bGI~
#endif                                                             //~v640I~
#endif //XSUB                                                      //~v6hhI~
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
    if (uviowritelocale_ifavail(Popt,Ppucs,Pucsctr,Ppdbcs,Ppattr,Plen,Pptgtrect))//~v6T5I~
    	return 0;                                                  //~v6T5I~
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
	UTRACEP("%s:ucsctr=%d,len=%d\n",UTT,Pucsctr,Plen);             //~v6L4R~
	pattr=Ppattr;                                                  //~v6L4I~
	attr=*pattr++;                                                 //~v6L4I~
//  for (ii=1;ii<Plen;ii++)                                        //~v6L4I~//~v6VhR~
    for (ii=1;ii<Plen;ii++,pattr++)                                //~v6VhI~
    	if (*pattr!=attr)                                          //~v6L4I~
        	break;                                                 //~v6L4I~
    if (ii<Plen)                                                   //~v6L4I~
		return uviowrtcellW1_NonLigatureLineCmd(Popt,Ppucs,Pucsctr,Ppdbcs,Ppattr,Plen,Pptgtrect);//~v6L4I~
    tgtpos.X=Pptgtrect->Left;                                      //~v6L4I~
    tgtpos.Y=Pptgtrect->Top;                                       //~v6L4I~
    uviom_clearlineW(UVIOMCLO_ATTRFILL,0/*data*/,&attr,Plen,tgtpos);//~v6L4I~
	return uvioWriteConsoleOutputCharacterW(Shconout,Ppucs,Pucsctr,tgtpos,&wrtlen)==0;//~v6L4R~
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
  	if (Popt & UVIOO_MENULC)                                   //~v6WuI~//~v6WwR~
    {                                                              //~v6WwI~
    	int writelen;                                              //~v6WwI~
        UTRACEP("%s:LIGATURE2 len=%d,ucsctr=%d,x=%d,y=%d\n",UTT,Plen,Pucsctr,tgtpos.X,tgtpos.Y);//~v6WwI~
		return uvioWriteConsoleOutputCharacterWwithAttr(Popt,Ppucs,Pucsctr,tgtpos,&writelen,Ppattr,Plen);//~v6WwI~
	}                                                              //~v6WwI~
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
    UTRACED("%s:rc=%d\n",UTT,rc);                                  //~v6E8I~//~v6WwR~
    UTRACEP("%s:rc=%d\n",UTT,rc);                                  //~v6WwI~
    return rc;                                                     //~v6E8I~
}//uviowrtcellW1_NonLigatureLine                                   //~v6E8I~
#endif //W32                                                       //~v6D6I~
#endif //!WXE                                                      //~v6D6I~
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
    UTRACEP("%s:Popt=%04x,Prow=%d,Pcol=%d,Plineopt=%04x,rrow=%d,pos=%d,rc:opt=%04x,v2nd=%d\n",UTT,Popt,Prow,Pcol,Plineopt,row,pos,opt,swv2nd);//~v7f8R~
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
    UTRACEP("%s:Popt=%04x,Prow=%d,Pcol=%d,Plen=%d,Plineopt=%04x,pos=%d,lineopt=%04x,swv2nd=%d\n",UTT,Popt,Prow,Pcol,Plen,Plineopt,pos,lineopt,swv2nd);//~v7f8R~
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
    {                                                              //~v6WxI~
		rc=WriteConsoleOutputCharacter(Phandle,wkmb,mblen,Ptgtpos,Pwrtlen);//~v6G0R~
    	UTRACEP("%s:WriteConsoleOutputCharacter rc=%d,mblen=%d,tgtpos=(%d,%d)\n",UTT,rc,mblen,Ptgtpos.X,Ptgtpos.Y);//~v6G1R~//~v6WxR~//~v7fkR~
	    UTRACED("mb",wkmb,mblen);                                  //~v7fkM~
    }                                                              //~v6WxI~
    else                                                           //~v6G0I~
    {                                                              //~v6WyI~
		rc=WriteConsoleOutputCharacterW(Phandle,&Pucs,1,Ptgtpos,Pwrtlen);//~v6G0I~
	    UTRACEP("%s:WriteConsoleOutputCharacterW ucs=%04x,len=%d,posx=%d,posy=%d\n",UTT,Pucs,1,Ptgtpos.X,Ptgtpos.Y);//~v7fkR~
    }                                                              //~v6WyI~
    return rc;                                                     //~v6G0I~
}//uvioWriteConsoleOutputCharacterUCS1                             //~v6G0R~
//*******************************************************          //~v6G0I~
#define DDPCO_ATTRBG 0x0100 	//gb4 char attr                    //~v7e4I~
int uviom_displaydbcspadCharacterW(int Popt,COORD Ptgtpos,int Plen)//~v6G0I~
{                                                                  //~v6G0I~
	WUCS  wkucs[4];                                                //~v6G0I~
    int ucsctr,rc,wrtlen;                                          //~v6G0R~
//****************************                                     //~v6G0I~
	UTRACEP("%s:opt=%04x,tagtposX=%d,targetPosY=%d,len=%d\n",UTT,Popt,Ptgtpos.X,Ptgtpos.Y,Plen);//~v7e4R~
//  for (ucsctr=0;ucsctr<Plen && ucsctr<(int)sizeof(wkucs);ucsctr++)//~v6G0I~//~v6WxR~
    for (ucsctr=0;ucsctr<Plen && ucsctr<(int)(sizeof(wkucs)/sizeof(wkucs[0]));ucsctr++)//~v6WxI~
    	wkucs[ucsctr]=(WUCS)Guviomdbcspad;                         //~v6G0I~
  if (Popt & DDPCO_ATTRBG) // 0x0100 	//gb4 char attr            //~v7e4I~
  {                                                                //~v7e4I~
  	WORD attr=(WORD)((Popt & 0xff) | UVIOM_PADATTR);               //~v7e4R~
	UTRACEP("%s:BG=%04x\n",UTT,attr);                              //~v7e4I~
    rc=FillConsoleOutputAttribute(Shconout,attr,(DWORD)ucsctr,Ptgtpos,&wrtlen)==0;//~v7e4I~
    UTRACEP("%s:fillattr rc=%d,attr=%02x,pos=%d,len=%d,writelen=%d\n",UTT,rc,attr,(int)Ptgtpos.X,Plen,wrtlen);//~v7fkR~
  }                                                                //~v7e4I~
  else                                                             //~v7e4I~
  {                                                                //~v7fkI~
    rc=FillConsoleOutputAttribute(Shconout,UVIOM_PADATTR,(DWORD)ucsctr,Ptgtpos,&wrtlen)==0;//~v6G0R~
    UTRACEP("%s:fillattr rc=%d,attr=%02x,len=%d,posX=%d,posY=%d,wrtlen=%d\n",UTT,rc,UVIOM_PADATTR,ucsctr,(int)Ptgtpos.X,Plen,wrtlen);//~v7fkR~
  }                                                                //~v7fkI~
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
    int wcw,flag;                                                  //~v6XbR~
    int swSurrogate;                                               //~v7bkI~
    int wwDraw;                                                    //~vbzJI~
//*****************                                                //~v6G0I~
    UTRACEP("%s:ucsctr=%d,len=%d,tgtpos=(%d,%d),dbcsspacealt=%x\n",UTT,Pucsctr,Plen,Ptgtpos.X,Ptgtpos.Y,Sdbcsspacealt);//~v6G0R~
    UTRACED("ucs",Ppucs,Pucsctr*(int)sizeof(WUCS));                //~v6G0I~
    UTRACED("attr",Ppattr,Plen*(int)sizeof(USHORT));               //~v6G0I~
    UTRACED("data",Ppdata,Plen);     //lcdata                      //~v6G0I~//~v6T5R~
    UTRACED("dbcs",Ppdbcs,Plen);     //lcdbcs                      //~v6G0I~//~v6T5R~
#ifdef CCC                                                         //~v7bmI~
	SswLocalefile=1;//parm to uviom_displaydbcspadCharacterW       //~vbzJR~
#endif                                                             //~v7bmI~
    uviom_clearlineW(UVIOMCLO_ATTRSTR,0/*data*/,Ppattr,Plen,Ptgtpos);//~v6G0R~
#ifdef CCC                                                         //~v7bmI~
	uvioSaveCellDataLocalefileW(UVIOSCDLO_CLEAR,Ppucs,Pucsctr,Ptgtpos.Y/*row*/,Ptgtpos.X/*col*/);//~vbzJR~
#endif                                                             //~v7bmI~
//  rc=uvioWriteConsoleOutputCharacterW(Shconout,Ppucs,Pucsctr,Ptgtpos,&wrtlen);//~v6G0R~
    for (ii=0,len=0,pdatao=0,pdata=Ppdata,pdbcs=Ppdbcs,tgtpos=Ptgtpos,pucs=Ppucs;ii<Pucsctr;ii++,pdata++,pdbcs++,pucs++)//~v6G0R~
    {                                                              //~v6G0I~
    	if (!pdatao)                                               //~v6G0I~
        	pdatao=pdata;                                          //~v6G0I~
    	if (!pucso)                                                //~v6G0I~
        	pucso=pucs;                                            //~v6G0R~
        ucs2=*pucs;                                                //~v6G0I~
        UTRACEP("%s:ii=%d,pucs=%x,pdata=%x,pdbcs=%x,len=%d,ucsctr=%d\n",UTT,ii,*pucs,*pdata,*pdbcs,len,ucsctr);//~v6G0R~//~v700R~//~v7a1R~
        if (*pdbcs==UDBCSCHK_DBCS1ST)                              //~v6G0I~
			swsbcs=(ucs2==DBCSSPACE_ALT2||ucs2==Sdbcsspacealt)? 2 : 0;//~v6G0R~
        else                                                       //~v6G0I~
        	swsbcs=1;                                              //~v6G0I~
        ucs4=(UWUCS)ucs2;                                          //~v6G0R~
        swSurrogate=0;                                             //~v7bkI~
        if (IS_UTF16_HIGH(ucs4) && (ii+1)<Pucsctr && IS_UTF16_PAIR(ucs4,*(pucs+1)))//~v6G0R~
        {                                                          //~v6G0I~
            ucs4=UTF16_TO_UCS4(ucs4,*(pucs+1));                    //~v6G0I~
//            pucs++;                                                //~v6G0I~//~v7bkR~
//            ii++;                                                  //~v6G0I~//~v7bkR~
//            ucsctr++;                                              //~v6G0I~//~v7bkR~
			swSurrogate=1;                                         //~v7bkR~
        }                                                          //~v6G0I~
        UTRACEP("%s:ucs2=%04x,ucs4=%06x,*pdata=%02x,*pdbcs=%02x,swsbcs=%d,ucsctr=%d,swSurrogate=%d\n",UTT,ucs2,ucs4,*pdata,*pdbcs,swsbcs,ucsctr,swSurrogate);//~v700R~//~v7a1R~//~vbzJR~//~v7bkR~
        if (swsbcs)                                                //~v6G0I~
        {                                                          //~v6G0I~
//        	if (ucs4!=*pdata)          //tab,esc rep or unprintable//~v7e4R~
          	if ((int)ucs4!=*pdata)          //tab,esc rep or unprintable//~v7e4I~
            {                                                      //~v6G0I~
            	if (len)                                           //~v6G0I~
                {                                                  //~v6G0I~
#ifdef CCC                                                         //~v7bkR~
					if (Gudbcschk_flag & UDBCSCHK_DBCSJ)	//Japanese//~v6G0R~
                    {                                              //~vbzJI~
						rc+=uvioWriteConsoleOutputCharacter(Shconout,pdatao,len,tgtpos,&wrtlen)==0;//~v6G0R~
						uvioSaveCellDataLocalefileW(0,pucso,ucsctr,tgtpos.Y/*row*/,tgtpos.X/*col*/);//~vbzJI~
            		}                                              //~vbzJI~
					else                                           //~v6G0R~
#endif                                                             //~v7bkI~
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
        //sbcs off                                                 //~v7bkI~
            wcw=utfwcwidth(UTFWWO_UTF8UCS2,(ULONG)ucs4,&flag);     //~v6XbR~
            wwDraw=wcw;                                            //~vbzJR~
            if (!wcw)                                              //~v7bkI~
                wwDraw=uvioGetCursorWidth(0,ucs4);             //~v7bkI~//~vbzJR~
            UTRACEP("%s:wcw=%d,wwDraw=%d,ucs4=%04x\n",UTT,wcw,wwDraw,ucs4);          //~v6XbR~//~vbzJR~
            for (dbcssz=1;ii+dbcssz<Plen;dbcssz++)                 //~v6G0I~
            {                                                      //~v6G0M~
                if (*(pdbcs+dbcssz)==UDBCSCHK_DBCS2ND)             //~v6G0I~
                    break;                                         //~v6G0M~
            }                                                      //~v6G0M~
            pdata+=dbcssz;  //1                                    //~v6G0R~
           	pdbcs+=dbcssz;                                         //~v6G0R~
            ucsctr++;                                              //~v6G0I~
            len+=2;                                                //~v6G0I~
            dbcssz++;   //1-->2                                    //~v6G0I~
        	UTRACEP("%s:dbcssz=%d,wcw=%d,ucs4=0x%06x,flag=0x%04x\n",UTT,dbcssz,wcw,ucs4,flag);                  //~v6G0R~//~v7bjI~//~v7bkR~
//        if (wcw==2)                                              //~v6XbI~//~v7a2R~
          if (wcw==2                                               //~v7a2I~
//        &&  !(flag & UTFWWF_F2C1))		//need padding or Wide sbcs by /Nv//~v7a2R~
//        &&  !(flag & (UTFWWF_F2C1|UTFWWF_F1C1))		//need padding or Wide sbcs by /Nv//~v7a2R~//~v7acR~
          &&  !(flag & (UTFWWF_F2C1|UTFWWF_F1C1|UTFWWF_AMBDBCS))		//need padding or Wide sbcs by /Nv//~v7acI~
          )                                                        //~v7a2I~
          {                                                        //~v6XbI~
//          if (dbcssz>2) //write dbcs padding                     //~v6G0I~//~v7bkR~
            if (dbcssz>2 || swSurrogate) //write dbcs padding      //~v7bkI~
            {                                                      //~v6G0M~
	        	UTRACEP("%s:call charW dbcssz>2 or surrogate *pucso=0x%04x,swSurrogate=%d,dbcssz=%d\n",UTT,*pucso,swSurrogate,dbcssz);//~vbzJI~//~v7bkR~
//              rc+=uvioWriteConsoleOutputCharacterW(Shconout,pucso,ucsctr,tgtpos,&wrtlen)==0;//~v6G0R~//~v7bkR~
                rc+=uvioWriteConsoleOutputCharacterW(Shconout,pucso,ucsctr+swSurrogate,tgtpos,&wrtlen)==0;//~v7bkI~
                tgtpos.X+=(SHORT)len;                              //~v6G0I~
                padctr=dbcssz-2;                                   //~v6G0M~
              if (padctr>0)                                        //~v7a2I~
              {                                                    //~v7a2I~
	        	UTRACEP("%s:call displaytab padctr=%d\n",UTT,padctr);//~vbzJI~
//				rc+=uviom_displaydbcspadCharacterW(0,tgtpos,padctr);//~v7e4R~
				int tabopt=UVIOM_ATTRBG(*(Ppattr+tgtpos.X-1)) | DDPCO_ATTRBG;	// 0x0100 	//gb4 char attr//~v7e4R~
   				rc+=uviom_displaydbcspadCharacterW(tabopt,tgtpos,padctr);//~v7e4I~
              }                                                    //~v7a2I~
            	UTRACEP("%s:dbcssz>2 or F2C1 padctr=%d,dbcssz=%d,*pucs=0x%04x,wcw=%d\n",UTT,padctr,dbcssz,*(pucs),wcw);//~v7a2I~
                len=0;                                             //~v6G0M~
                ucsctr=0;                                          //~v6G0M~
                tgtpos.X+=(SHORT)padctr;                           //~v6G0M~
                pdatao=pdata+dbcssz;                               //~v6G0M~
//              pucso=pucs+1;                                      //~v6G0M~//~v7bkR~
                pucso=pucs+1+swSurrogate;                          //~v7bkI~
			}                                                      //~v6G0M~
            if (swSurrogate)                                       //~v7bkI~
            {                                                      //~v7bkI~
                ii++;                                              //~v7bkI~
                pucs++;                                            //~v7bkI~
            }                                                      //~v7bkI~
          }                                                        //~v6XbI~
          else                                                     //~v6XbI~
          {                                                        //~v6XbI~
	        	UTRACEP("%s:call charW for pucso by flag *pucso=0x%04x,len=%d,flag=0x%04x\n",UTT,*pucso,len,flag);//~vbzJI~//~v7bkR~
                rc+=uvioWriteConsoleOutputCharacterW(Shconout,pucso,ucsctr-1,tgtpos,&wrtlen)==0;//~v6XbI~
                tgtpos.X+=(SHORT)(len-2);                          //~v6XbI~
//              padctr=dbcssz;                                     //~v6XbI~//~v7a1R~
#ifdef AAA                                                         //~v7bjI~
                padctr=dbcssz-1;                                   //~v7a1I~
#else                                                              //~v7bjI~
	#ifdef BBB                                                     //~vbzJI~
                padctr=dbcssz-wcw;                                 //~v7bjR~
	#else                                                          //~vbzJI~
                padctr=dbcssz-wwDraw;                              //~vbzJR~
	#endif                                                         //~vbzJI~
#endif                                                             //~v7bjI~
#ifdef BBB                                                         //~vbzJI~
            if (wcw)	//not combining                            //~v7bkI~
            {                                                      //~v7bkI~
#endif                                                             //~vbzJI~
	        	UTRACEP("%s:call charW by flag itself ucsctr=%d,*pucso=0x%04x,padctr=%d\n",UTT,ucsctr,*(pucso+ucsctr-1),padctr);//~vbzJI~//~v7bkR~
//              rc+=uvioWriteConsoleOutputCharacterW(Shconout,pucso+ucsctr-1,1,tgtpos,&wrtlen)==0;//~v6XbI~//~v7bkR~
                rc+=uvioWriteConsoleOutputCharacterW(Shconout,pucso+ucsctr-1,1+swSurrogate,tgtpos,&wrtlen)==0;//~v7bkI~
//              tgtpos.X+=(SHORT)1;                                //~v6XbI~//~v7bkR~
                tgtpos.X+=(SHORT)wwDraw;                           //~v7bkI~//~vbzJR~
//  			rc+=uviom_displaydbcspadCharacterW(0,tgtpos,padctr-1);//~v6XbR~//~v7a1R~
              if (padctr>0)                                        //~v7a2I~
              {                                                    //~vbzJI~
	        	UTRACEP("%s:call dispalypad,padctr=%d,col=%d\n",UTT,padctr,tgtpos.X);//~vbzJR~
//  			rc+=uviom_displaydbcspadCharacterW(0,tgtpos,padctr);//~v7e4R~
				int tabopt=UVIOM_ATTRBG(*(Ppattr+tgtpos.X-1)) | DDPCO_ATTRBG;	// 0x0100 	//gb4 char attr//~v7e4I~
    			rc+=uviom_displaydbcspadCharacterW(tabopt,tgtpos,padctr);//~v7e4I~
              }                                                    //~vbzJI~
//              tgtpos.X+=(SHORT)(dbcssz-1);                       //~v6XbR~//~v7bkR~
                tgtpos.X+=(SHORT)padctr;                           //~v7bkI~
#ifdef BBB                                                         //~vbzJI~
            }                                                      //~v7bkI~
            else	//wcw=0;combining                              //~v7bkI~
            {                                                      //~v7bkI~
              if (padctr>0)                                        //~v7bkI~
              {                                                    //~v7bkI~
	        	UTRACEP("%s:combining;call dispalypad,padctr=%d,col=%d\n",UTT,padctr,tgtpos.X);//~v7bkI~
    			rc+=uviom_displaydbcspadCharacterW(0,tgtpos,padctr);//~v7bkI~
              }                                                    //~v7bkI~
	        	UTRACEP("%s:combining call charW by flag itself ucsctr=%d,*pucso=0x%04x,padctr=%d\n",UTT,ucsctr,*(pucso+ucsctr-1),padctr);//~v7bkI~
                rc+=uvioWriteConsoleOutputCharacterW(Shconout,pucso+ucsctr-1,1+swSurrogate,tgtpos,&wrtlen)==0;//~v7bkI~
                tgtpos.X+=(SHORT)padctr;                           //~v7bkM~
            }                                                      //~v7bkI~
#endif                                                             //~vbzJI~
                len=0;                                             //~v6XbI~
                ucsctr=0;                                          //~v6XbI~
                if (swSurrogate)                                   //~v7bkI~
                {                                                  //~v7bkI~
                	ii++;                                          //~v7bkI~
                    pucs++;                                        //~v7bkI~
                }                                                  //~v7bkI~
//              pdatao=pdata+dbcssz;                               //~v6XbI~//~v7a1R~
                pdatao=pdata+padctr;                               //~v7a1R~
                pucso=pucs+1;                                      //~v6XbI~
            	UTRACEP("%s:swSurrogate=%d,padctr=%d,dbcssz=%d,*pucs=0x%04x,pdatao=%p\n",UTT,swSurrogate,padctr,dbcssz,*(pucs),pdatao);//~v7a1R~//~v7bkR~
//          	UTRACED("pdata",pdata-padctr,dbcssz);              //~v7a1R~
//          	UTRACED("pdbcs",pdbcs-padctr,dbcssz);              //~v7a1R~
          }                                                        //~v6XbI~
          //flag off/onn                                           //~v7bkI~
        }                                                          //~v6G0I~
          //swsbcs off/on                                          //~v7bkI~
    }                                                              //~v6G0I~
    //loop ii                                                      //~v7bkI~
    if (len)                                                       //~v6G0I~
#ifdef CCC                                                         //~v7bkR~
		if (Gudbcschk_flag & UDBCSCHK_DBCSJ)	//Japanese         //~v6G0I~
        {                                                          //~vbzJI~
	        UTRACEP("%s:last dbcsj pdatao=%02x,col=%d\n",UTT,*pdatao,tgtpos.X);//~vbzJI~
			rc+=uvioWriteConsoleOutputCharacter(Shconout,pdatao,len,tgtpos,&wrtlen);//~v6G0R~
			uvioSaveCellDataLocalefileW(0,pucso,ucsctr,tgtpos.Y/*row*/,tgtpos.X/*col*/);//~vbzJI~
        }                                                          //~vbzJI~
        else                                                       //~v6G0I~
#endif                                                             //~v7bkI~
        {                                                          //~vbzJI~
	        UTRACEP("%s:last  pucso=%04xx,col=%d\n",UTT,*pucso,tgtpos.X);//~vbzJI~
			rc+=uvioWriteConsoleOutputCharacterW(Shconout,pucso,ucsctr,tgtpos,&wrtlen);//~v6G0R~
        }                                                          //~vbzJI~
#ifdef CCC                                                         //~v7bmI~
	SswLocalefile=0;                                               //~vbzJR~
#endif                                                             //~v7bmI~
    return rc;                                                     //~v6G0I~
}//uviowrtcellW1_localefile                                        //~v6G0I~
//*********************************************************************************//~v6T5I~
//use WriteConsoleOutputChar,Now write at once is OK because Windows10?//~v6T5I~
//return 1:done                                                    //~v6T5I~
//*********************************************************************************//~v6T5I~
int uviowritelocale_ifavail(int Popt,WUCS *Ppucs,int Pucsctr,char *Ppdbcs,USHORT *Ppattr,int Plen,SMALL_RECT *Pptgtrect)//~v6T5I~
{                                                                  //~v6T5I~
    COORD tgtpos;                                                  //~v6T5I~
    int writelen;                                                  //~v6T5I~
//***************************************************              //~v6T5I~
    UTRACEP("%s-2:ucsctr=%d,len=%d,tgtpos=(%d,%d)\n",UTT,Pucsctr,Plen,Pptgtrect->Left,Pptgtrect->Top);//~v6T5I~
    tgtpos.Y=Pptgtrect->Top;                                       //~v6T5I~
    tgtpos.X=Pptgtrect->Left;                                      //~v6T5I~
	uvioWriteConsoleOutputCharacterWwithAttr(0,Ppucs,Pucsctr,tgtpos,&writelen,Ppattr,Plen);//~v6T5I~
	return 1;                                                      //~v6T5I~
}//uviowritelocale_ifavail                                         //~v6T5I~
//*********************************************************************************//~v6G0I~
//WIN                                                              //~v7bDI~
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
//  USHORT attr;                                                   //~v6G0R~//~v6VgR~
    UCHAR *pdbcsend;                                               //~v6G0I~
    int swdbcsspaceutf8;                                           //~v6G0I~
    WUCS   wkaltch[2];                                             //~v6G0I~
    WUCS   ucs;                                                    //~v6G0I~
    int    ucs4,swcombine,baseucs=0;                               //~v6WuR~
//    int startTargetPosX;                                         //~v7ejR~
//********************************                                 //~v6G0I~
    UTRACEP("%s:opt=%x,ucsctr=%d,len=%d,x=%d,y=%d\n",UTT,Popt,Pucsctr,Plen,Ptgtrect->Left,Ptgtrect->Top);//~v6G0R~
    UTRACED("ucs",Ppucs,Pucsctr*(int)sizeof(WUCS));                //~v700R~//~v7a2R~
    UTRACED("data",Ppdata,Plen);                                   //~v700R~//~v7a2R~
    UTRACED("dbcs",Ppdbcs,Plen);                                   //~v700R~//~v7a2R~
    UTRACED("attr",Ppattr,(int)sizeof(USHORT)*Plen);               //~v700R~//~v7a2R~
    tgtpos.X=Ptgtrect->Left;                                       //~v6G0R~
    tgtpos.Y=Ptgtrect->Top;                                        //~v6G0R~
//  startTargetPosX=tgtpos.X;                                      //~v7ejR~
#ifdef EEE                                                         //~v7fpR~
  if (GutfTestUcs==5)                                              //~v7fpI~
    uviom_clearlineW2(UVIOMCLO_ATTRSTR,0/*data*/,Ppattr,Plen,tgtpos);//~v7fpM~
  else                                                             //~v7fpI~
#endif                                                             //~v7fpM~
    uviom_clearlineW(UVIOMCLO_ATTRSTR,0/*data*/,Ppattr,Plen,tgtpos);//~v6G0R~
    col=0;  //start col                                            //~v6G0R~
    pdata=Ppdata;                                                  //~v6G0R~
    pattr=Ppattr;                                                  //~v6G0R~
    pdbcsend=Ppdbcs+Plen;                                          //~v6G0R~
    for (rc=0,ii=0,pucs=Ppucs,pdbcs=Ppdbcs;ii<Pucsctr;ii++,pucs++) //~v6G0R~
    {                                                              //~v6G0R~
        ucs=*pucs;                                                 //~v6G0R~
//      UTRACEP("%s:ucs=%x,attrr=%x,dbcsid=%x,data=%x\n",UTT,*pucs,*pattr,*pdbcs,*pdata);//~v700R~
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
//UTRACEP("%s:write dbcsspaceutf8 ucs=%04x,col=%d\n",UTT,ucs,tgtpos.X);//~v700R~
            writelend+=writelen;                                   //~v6G0R~
            pdbcs+=chwidth;                                        //~v6G0R~
            pdata+=chwidth;                                        //~v6G0R~
            tgtpos.X+=(SHORT)chwidth;                              //~v6G0R~
            pattr+=chwidth;                                        //~v6G0R~
        }                                                          //~v6G0R~
        else                                                       //~v6G0R~
//*not dbcsspace                                                   //~v6G0R~
        {                                                          //~v6G0R~
            swcombine=uviom_iscombining(0,pucs,pdbcs,Pucsctr-ii,&ucs4,&chwidth);//~v6WuR~
            if (!swcombine)                                        //~v6WuI~
            	baseucs=ucs4;                                      //~v6WuI~
	        if (swcombine & UICRC_SCM)	//4                        //~v6WuI~//~v6X1R~
        	{                                                      //~v6WuI~
    			uviom_wrtSCMW(Popt,baseucs,ii,ucs4,pucs,pattr,tgtpos);//~v6WuR~
                if (UTF_ISUCS4(ucs4))                              //~v6WuI~
                	ii++,pucs++;                                   //~v6WuI~
        	}                                                      //~v6WuI~
            else                                                   //~v6WuI~
//          if (ii+1<Pucsctr && IS_UTF16_PAIR(*pucs,*(pucs+1)))    //~v6G0R~//~v6WuR~
            if (UTF_ISUCS4(ucs4))                                  //~v6WuI~
            {                                                      //~v6G0I~
//            if (uviom_ISUCSWIDTH0W(0,pucs,pdbcs,Pucsctr-ii))     //~v6VgI~//~v6WuR~
//            if (swcombine==UICRC_OVF)                            //~v6WuI~//~v6X1R~
              if (swcombine & UICRC_OVF)                           //~v6X1I~
                rc+=uviom_wrtW0W(0,pucs,pattr,2,tgtpos,&writelen); //~v6VgR~
              else                                                 //~v6VgI~
              {                                                    //~v6VgI~
//              if (!uvioWriteConsoleOutputCharacterW1withAttr1(0,Shconout,pucs,2,tgtpos,&writelen,Ptgtrect,pattr,chwidth)) //len written//~v6G0R~
//                  rc++;                                          //~v6G0R~
				rc+=uvioWriteConsoleOutputCharacterW(Shconout,pucs,2,tgtpos,&writelen)==0;//~v6G0R~
              }                                                    //~v6VgI~
                ii++;                                              //~v6G0I~
                pucs++;                                            //~v6G0I~
            }                                                      //~v6G0I~
            else                                                   //~v6G0I~
            if (                                                   //~v6G0R~
//              UDBCSCHK_ISUCSWIDTH0(*pdbcs)                       //~v6G0R~//~v6VgR~
//              uviom_ISUCSWIDTH0W(0,pucs,pdbcs,1)                 //~v6VgR~//~v6WuR~
              	swcombine==UICRC_SBCS                              //~v6WuI~
            )                                                      //~v6G0I~
            {                                                      //~v6G0I~
            //*width0 under no combinemode                         //~v6G0I~
#ifdef MMM                                                         //~v6VgI~
                UTRACEP("%s:write Gutfcombaltch=%04x\n",UTT,Gutfcombaltch);//~v6G0I~
                if (UTF_COMBINEMODE_NP() && Gutfcombaltch)         //~v6G0R~
                	ucs=(WUCS)Gutfcombaltch;                       //~v6G0R~
//              if (!uvioWriteConsoleOutputCharacterW1withAttr1(0,Shconout,&ucs,1,tgtpos,&writelen,Ptgtrect,pattr,chwidth)) //len written//~v6G0R~
//                  rc++;                                          //~v6G0R~
                attr=(Ppattr[tgtpos.X] & 0xf0)|ATTR_COMBINENP_FG;  //~v6G0R~
                rc+=WriteConsoleOutputAttribute(Shconout,&attr,1,tgtpos,&writelen)==0;          //writelen//~v6G0I~
				rc+=uvioWriteConsoleOutputCharacterUCS1(Shconout,ucs,tgtpos,&writelen)==0;//~v6G0I~
#else                                                              //~v6VgI~
//      #ifndef SSS //TODO test to avoid combine-->no effect       //~v7c4R~
//                WUCS wkshadow[2];                                //~v7c4R~
//                wkshadow[0]='a';                                 //~v7c4R~
//                wkshadow[1]=ucs;                                 //~v7c4R~
//                rc+=uvioWriteConsoleOutputCharacterW(Shconout,wkshadow,2,tgtpos,&writelen)==0;//~v7c4R~
////              writelen=1;                                      //~v7c4R~
//                tgtpos.X+=1;                                     //~v7c4R~
//      #else                                                      //~v7c4R~
//              rc+=uviom_wrtW0W(0,pucs,Ppattr+tgtpos.X,1,tgtpos,&writelen);//~v7ejR~
//              rc+=uviom_wrtW0W(0,pucs,Ppattr+tgtpos.X-startTargetPosX,1,tgtpos,&writelen);//~v7ejR~
                rc+=uviom_wrtW0W(0,pucs,pattr,1,tgtpos,&writelen); //~v7ejI~
//      #endif                                                     //~v7c4R~
//    #ifndef SSS //TODO test to avoid combine-->no effect         //~v7c4R~
//                if (UTF8ISASCII(*(pucs-1)))                      //~v7c4R~
//                {                                                //~v7c4R~
//                    COORD tgtposW=tgtpos;                        //~v7c4R~
//                    tgtposW.X-=1;                                //~v7c4R~
//                    char chascii=(char)(*(pucs-1));              //~v7c4R~
//                    UTRACEP("%s:write ascii after w0w char=%02x,posX=%d\n",UTT,chascii,tgtposW.X);//~v7c4R~
//                    rc+=uvioWriteConsoleOutputCharacter(Shconout,&chascii,1,tgtpos,&writelen)==0;//~v7c4R~
//                }                                                //~v7c4R~
//    #endif                                                       //~v7c4R~
#endif                                                             //~v6VgI~
            }                                                      //~v6G0I~
            else                                                   //~v6G0I~
//          if (!uvioWriteConsoleOutputCharacterW1withAttr1(0,Shconout,pucs,1,tgtpos,&writelen,Ptgtrect,pattr,chwidth)) //len written//~v6G0R~
//              rc++;                                              //~v6G0R~
#ifdef KKK                                                         //~v6WyI~
				rc+=uvioWriteConsoleOutputCharacterUCS1(Shconout,ucs,tgtpos,&writelen)==0;//~v6G0I~
#else                                                              //~v6WyI~
//  			rc+=WriteConsoleOutputCharacterW(Shconout,&ucs,1,tgtpos,&writelen)==0;//~v6WyR~//~v700R~
//    #ifndef SSS //TODO test to avoid combine-->no effect         //~v7c4R~
//            if (UTF8ISASCII(ucs))                                //~v7c4R~
//            {                                                    //~v7c4R~
//                char chascii=(char)ucs;                          //~v7c4R~
//                rc+=uvioWriteConsoleOutputCharacter(Shconout,&chascii,1,tgtpos,&writelen)==0;//~v7c4R~
//            }                                                    //~v7c4R~
//            else                                                 //~v7c4R~
//    #endif                                                       //~v7c4R~
				rc+=uvioWriteConsoleOutputCharacterW(Shconout,&ucs,1,tgtpos,&writelen)==0;//~v700I~
#endif                                                             //~v6WyI~
                                                                   //~v6G0I~
  UTRACEP("%s: not combinemode ucs=%04x,col=%d,chwidth=%d,writelen=%d\n",UTT,*pucs,tgtpos.X,chwidth,writelen);//~v700R~
            writelend+=writelen;                                   //~v6G0I~
            pdbcs+=chwidth;                                        //~v6G0I~
            pattr+=chwidth;                                        //~v6G0I~
            pdata+=chwidth;                                        //~v6G0I~
            tgtpos.X+=(SHORT)chwidth;                              //~v6G0R~
        }//not dbcsspace                                           //~v6G0R~
    }//for                                                         //~v6G0R~
    UTRACEP("%s:rc=%d\n",UTT,rc);                                  //~v700I~
    return rc;                                                     //~v6G0R~
}//uviowrtcellW1_cpu8file_NoLigatureNoCombine                     //~v6G0R~//~v6WxR~
//*********************************************************************************//~v6G0I~
//*lig:off display combined char under combinemode                 //~v6G0R~
//*********************************************************************************//~v6G0I~
int uviowrtcellW1_cpu8file_NoLigatureCombinedString(int Popt,WUCS *Ppucs,int Pucsctr,USHORT *Ppattr,SMALL_RECT *Ptgtrect)//~v6G0I~
{                                                                  //~v6G0I~
//  WUCS   wkucs[UVIOM_MAXCOMBINE];                                //~v6G0I~//~v6VgR~
    WUCS   wkucs[(UVIOM_MAXCOMBINE+1)*2];                          //~v6VgI~
    COORD  tgtpos;                                                 //~v6G0I~
//  int ii,wrtlen,rc=0,ucsctr,len;                                 //~v6G0R~//~v6X8R~
    int    wrtlen,rc=0,ucsctr,len;                                 //~v6X8I~
    USHORT attr;                                                   //~v6G0I~
//**************************************                           //~v6G0I~
	tgtpos.X=Ptgtrect->Left;                                       //~v6G0R~
	tgtpos.Y=Ptgtrect->Top;                                        //~v6G0R~
    len=Ptgtrect->Right-Ptgtrect->Left+1;                          //~v6G0I~
UTRACEP("%s:ucsctr=%d,X=%d,Y=%d,len=%d,Guviomdbcspad=%x\n",UTT,Pucsctr,tgtpos.X,tgtpos.Y,len,Guviomdbcspad);//~v7f8R~
UTRACED("Ppucs",Ppucs,sizeof(WUCS)*Pucsctr);                       //~v7fpR~
//  ucsctr=min((int)sizeof(wkucs),Pucsctr);                        //~v6G0I~//~v6WxR~
    ucsctr=min((int)(sizeof(wkucs)/sizeof(wkucs[0])),Pucsctr);     //~v6WxI~
	if (Guviomdbcspad!=' ')                                        //~v6G0I~
    {                                                              //~v6G0I~
//  	for (ii=0;ii<len;ii++)                                     //~v6G0R~//~v6X8R~
//  		wkucs[ii]=Guviomdbcspad;                               //~v6G0R~//~v6X8R~
        memsetW(wkucs,Guviomdbcspad,len);   //for performance      //~v6X8I~
        attr=(*Ppattr & 0xf0)/*bg*/|UVIOM_PADATTR/*fg*/;           //~v6G0I~
#ifdef EEE                                                         //~v7fpR~
  	if (GutfTestUcs==5)                                            //~v7fpI~
    	uviom_clearlineW2(UVIOMCLO_ATTRFILL,0/*data*/,&attr,len,tgtpos);//~v7fpI~
  	else                                                           //~v7fpI~
#endif                                                             //~v7fpI~
    	uviom_clearlineW(UVIOMCLO_ATTRFILL,0/*data*/,&attr,len,tgtpos);//~v6G0R~
		rc+=uvioWriteConsoleOutputCharacterW(Shconout,wkucs,len,tgtpos,&wrtlen)==0;//~v6G0R~
    }                                                              //~v6G0I~
#ifdef TEST                                                        //~v7fjR~
	uviom_clearlineW(UVIOMCLO_ATTRSTR,0/*data*/,Ppattr,1,tgtpos);  //~v7fjM~
#else                                                              //~v7fjM~
#ifdef EEE                                                         //~v7fpR~
  if (GutfTestUcs==5)                                              //~v7fpI~
	uviom_clearlineW2(UVIOMCLO_ATTRSTR,0/*data*/,Ppattr,len,tgtpos);//~v7fpI~
  else                                                             //~v7fpI~
#endif                                                             //~v7fpI~
	uviom_clearlineW(UVIOMCLO_ATTRSTR,0/*data*/,Ppattr,len,tgtpos);//~v6G0R~
#endif                                                             //~v7fjM~
//  rc+=uvioWriteConsoleOutputCharacterW(Shconout,Ppucs,ucsctr,tgtpos,&wrtlen)==0;//~v6G0R~//~v6VgM~
    rc+=uvioWriteConsoleOutputCharacterW(Shconout,Ppucs,Pucsctr,tgtpos,&wrtlen)==0;//~v6VgI~
    UTRACEP("%s:return rc=%d,writelen=%d\n",UTT,rc,wrtlen);                           //~v6G0R~//~v6VgR~
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
    int combinecols;   //1:ucs2,2:ucs4                             //~v6VgI~
    int strucsctr=0,strwidth=0,swcombinedstr;                      //~v6VgR~
//************************                                         //~v6G0I~
    left=Ptgtrect->Left;                                           //~v6G0R~
    UTRACEP("%s:ucsctr=%d,len=%d,xx=%d\n",UTT,Pucsctr,Plen,left);  //~v6G0I~
    UTRACEP("%s:tgtrect (%d,%d)-(%d,%d)\n",UTT,Ptgtrect->Left,Ptgtrect->Top,Ptgtrect->Right,Ptgtrect->Bottom);//~v7efR~
    UTRACED("ucs",Ppucs,Pucsctr*(int)sizeof(WUCS));                //~v6G0I~
    UTRACED("data",Ppdata,Plen);                                   //~v6G0I~
    UTRACED("dbcs",Ppdbcs,Plen);                                   //~v6G0I~
    UTRACED("attr",Ppattr,Plen*(int)sizeof(USHORT));               //~v6G0I~
    tgtrect=*Ptgtrect;                                             //~v6G0I~
   	for (ii=0,poso=-1,colo=0,col=0,pos=0,pucs=Ppucs,pdata=Ppdata,pdbcs=Ppdbcs;ii<Pucsctr;ii++,pucs++,pos++)//~v6G0R~
    {                                                              //~v6G0I~
        UTRACEP("%s:ii=%d,col=%d,ucs=%04x\n",UTT,ii,col,*pucs);    //~v7efI~
    	if (poso<0)                                                //~v6G0R~
        {                                                          //~v6G0I~
        	poso=pos;                                              //~v6G0I~
            colo=col;                                              //~v6G0I~
        }                                                          //~v6G0I~
        swcombinedstr=0;                                           //~v6VgI~
//      if (UDBCSCHK_ISUCSWIDTH0(*pdbcs))   //split at combining char//~v6G0R~//~v6VgR~
        if (combinecols=uviom_ISUCSWIDTH0W(0,pucs,pdbcs,Pucsctr-ii),combinecols)//start from combining char//~v6VgR~
        {                                                          //~v6G0I~
	   		UTRACEP("%s:cpos width0 col=%d,combinecols=%d\n",UTT,col,combinecols);            //~v6G0R~//~v6VgR~
#ifdef AAA                                                         //~v7fjI~
            tgtrect.Left=(SHORT)(left+col);                        //~v6G0R~
            tgtrect.Right=(SHORT)(left+col);                       //~v6G0R~
//  		rc+=uviowrtcellW1_cpu8file_NoLigatureCombinedString(Popt,pucs,1,Ppattr+col,&tgtrect);//~v6G0I~//~v6VgR~
    		rc+=uviowrtcellW1_cpu8file_NoLigatureCombinedString(Popt,pucs,combinecols,Ppattr+col,&tgtrect);//~v6VgI~
#else                                                              //~v7fjI~
    		int ucsctr2=pos-poso;                                  //~v7foI~
            UTRACEP("%s:before combining ucsctr2=%d,col=%d,colo=%d,pos=%d,poso=%d\n",UTT,ucsctr2,col,colo,pos,poso);//~v7foI~
            if (poso>=0 && ucsctr2>0)                              //~v7foR~
            {                                                      //~v7foI~
            	len=col-colo;                                      //~v7foI~
                tgtrect.Left=(SHORT)(left+colo);                   //~v7foI~
                tgtrect.Right=tgtrect.Left+(SHORT)len-1;           //~v7foI~
                rc+=uviowrtcellW1_cpu8file_NoLigatureNoCombine(Popt,Ppucs+poso,ucsctr2,Ppdata+colo,Ppdbcs+colo,Ppattr+colo,len,&tgtrect);//~v7foR~
            }                                                      //~v7foI~
			COORD poscomb;                                         //~v7fjI~
            poscomb.X=(SHORT)(left+col);                           //~v7fjR~
            poscomb.Y=(SHORT)tgtrect.Top;                          //~v7fjR~
            int writelen;                                          //~v7fjI~
            rc+=uviom_wrtW0W(0,pucs,Ppattr+col,combinecols,poscomb,&writelen);//~v7fjR~
#endif                                                             //~v7fjI~
//          chwidth=1;                                             //~v6G0I~//~v6VgR~
            chwidth=combinecols;                                   //~v6VgI~
            UTRACEP("%s:col=%d,chwidth=%d,poso=%d\n",UTT,col,chwidth,poso);//~v7fiR~
            poso=-1; //next is startof no comnining string(pass to NoligNocomb)//~v7fiI~
        }                                                          //~v6G0I~
        else                                                       //~v6G0I~
        {                                                          //~v6G0I~
            ucs2=*pucs;                                            //~v6G0R~
            chwidth=UDBCSCHK_DBCS1STUCS2NWO(*pdbcs)+1;             //~v6G0R~
            UTRACEP("%s:ucs2=%04x,col=%d,chwidth=%d\n",UTT,ucs2,col,chwidth);//~v7efR~
            if (ii+1<Pucsctr)                                      //~v6G0R~
            {                                                      //~v7frI~
//              combinectr=uvio_getcombinectr(0,ucs2,chwidth,pdbcs,Pucsctr-ii);//~v6G0R~//~v6VgR~
//              combinectr=uvio_getcombinectr(0,pucs,chwidth,pdbcs,Pucsctr-ii,&strucsctr,&strwidth);//~v7eaR~
#ifdef FFF                                                         //~v7frI~
                combinectr=uvio_getcombinectr(0,pucs,chwidth,pdbcs,Plen-PTRDIFF(pdbcs,Ppdbcs),&strucsctr,&strwidth);//~v7eaI~
#else                                                              //~v7frI~
            	int optgcc=GCCO_NOFMT; // 0x01  //exclude format except ZWJ(200d)//~v7frR~
                combinectr=uvio_getcombinectr(optgcc,pucs,chwidth,pdbcs,Plen-PTRDIFF(pdbcs,Ppdbcs),&strucsctr,&strwidth);//~v7frI~
#endif                                                             //~v7frI~
            }                                                      //~v7frI~
            else                                                   //~v6G0R~
                combinectr=0;                                      //~v6G0R~
            UTRACEP("%s:ucs=%04x,combinectr=%d,pdbcs=%p\n",UTT,ucs2,combinectr,pdbcs);//~v7e4R~
            if (ucs2==0x201c)                                      //~v700I~
            {                                                      //~v700I~
            	UTRACEP("%s:ucs=%x,combinectr=%d,pdbcs=%p\n",UTT,ucs2,combinectr,pdbcs);//~v700I~
            }                                                      //~v700I~
#ifdef AAA                                                         //~v7efI~
            if (swPosC)                                            //~v7efI~
            {                                                      //~v7efI~
                len=chwidth;     //str column                      //~v7efI~
                tgtrect.Left=(SHORT)(left+col);                    //~v7efI~
                tgtrect.Right=tgtrect.Left+(SHORT)(len-1);         //~v7efI~
                ucsctr=1;                                          //~v7efI~
                rc+=uviowrtcellW1_cpu8file_NoLigatureCombinedString(Popt,pucs,ucsctr,Ppattr+col,&tgtrect);//~v7efI~
                poso=-1;    //no ucs to write before posc ucs      //~v7efI~
                colo=0;                                            //~v7efI~
            }                                                      //~v7efI~
            else                                                   //~v7efI~
#endif                                                             //~v7efI~
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
#ifdef MMM                                                         //~v6VgI~
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
#else                                                              //~v6VgI~
                len=strwidth;     //str column                     //~v6VgI~
                tgtrect.Left=(SHORT)(left+col);                    //~v6VgI~
                tgtrect.Right=tgtrect.Left+(SHORT)(len-1);         //~v6VgI~
                ucsctr=strucsctr;                                  //~v6VgI~
                rc+=uviowrtcellW1_cpu8file_NoLigatureCombinedString(Popt,pucs,ucsctr,Ppattr+col,&tgtrect);//~v6VgI~
                poso=-1;                                           //~v6VgI~
                colo=0;                                            //~v6VgI~
                col+=strwidth-chwidth;  //colomn                   //~v6VgR~
    		    UTRACEP("%s:after CombinedString col=%d,+strwidth(%d)-chwidth(%d),combinectr=%d\n",UTT,col,strwidth,chwidth,combinectr);//~v7efI~
                pdbcs+=strwidth-chwidth;                           //~v6VgR~
                ii+=strucsctr-1;	//if top is ucs4, 1 will be added later//~v6VgI~
                pucs+=strucsctr-1;                                 //~v6VgI~
                pos+=strucsctr-1;                                  //~v6VgI~
        		swcombinedstr=1;                                   //~v6VgI~
#endif                                                             //~v6VgI~
            }                                                      //~v6G0R~
        }                                                          //~v6G0I~
        col+=chwidth;                                              //~v6G0R~
        pdbcs+=chwidth;                                            //~v6G0I~
        UTRACEP("%s:new col=%d,chwidth=%d\n",UTT,col,chwidth);     //~v7efI~
      if (!swcombinedstr)                                          //~v6VgI~
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
    UTRACEP("%s:exit tgtrect (%d,%d)-(%d,%d)\n",UTT,Ptgtrect->Left,Ptgtrect->Top,Ptgtrect->Right,Ptgtrect->Bottom);//~v7efR~
    UTRACEP("%s:return rc=%d\n",UTT,rc);                           //~v6G0R~
    return rc;                                                     //~v6G0I~
}//uviowrtcellW1_cpu8file_NoLigatureCombineColSplit                //~v6G0R~
//*********************************************************************************//~v6G0I~
//*lig:off and combine mode                                        //~v6G0I~
//*********************************************************************************//~v6G0I~
int uviowrtcellW1_cpu8file_NoLigatureCombine(int Popt,WUCS *Ppucs,int Pucsctr,UCHAR *Ppdata,UCHAR *Ppdbcs,USHORT *Ppattr,int Plen,SMALL_RECT *Ptgtrect)//~v6G0I~
{                                                                  //~v6G0I~
//  int posa,posb,posc=-1,posbvhex,poscvhex=-1,col,ii,chwidth,len,ucsctr,rc=0,xx,yy;//~v7e9R~
//  int posa,posb=-1,posc=-1,posbvhex=-1,poscvhex=-1,col,ii,chwidth,len,ucsctr,rc=0,xx,yy;//~v7efR~
    int posa=-1,posb=-1,posc=-1,posbvhex=-1,poscvhex=-1,posavhex=-1,col,ii,chwidth,len,ucsctr,rc=0,xx,yy;//~v7efR~
    UCHAR *pdbcs;                                                  //~v6G0I~
    SMALL_RECT tgtrect;                                            //~v6G0I~
    WUCS *pucs;                                                    //~v6G0I~
	COORD tgtpos;                                                  //~v7fmI~
//**************************************************               //~v6G0M~
    int startX=Ptgtrect->Left;                                     //~v7ekI~
    xx=Ptgtrect->Left;                                             //~v6G0I~
    yy=Ptgtrect->Top;                                              //~v6G0I~
    UTRACEP("%s:xx=%d,yy=%d,Scsrposx=%d,Svhexcsrposx=%d,Scsrposy=%d,Svhexcsrposy=%d,len=%d\n",UTT,xx,yy,Scsrposx,Svhexcsrposx,Scsrposy,Svhexcsrposy,Plen);//~v7ekR~
    UTRACED("Ppucs",Ppucs,Pucsctr*(int)sizeof(WUCS));              //~v7ekI~
    UTRACED("Ppdata",Ppdata,Plen);                                 //~v7ekI~
    UTRACED("Ppdbcs",Ppdbcs,Plen);                                 //~v7ekR~
    UTRACED("Ppattr",Ppattr,Plen*(int)sizeof(USHORT));             //~v7fmI~
//if (GutfTestUcs==5)                                              //~v7fmM~
  if (IS_ON_TERMINAL())                                            //~v7fmI~
  {                                                                //~v7fmI~
    tgtpos.X=Ptgtrect->Left;                                       //~v7fmI~
    tgtpos.Y=Ptgtrect->Top;                                        //~v7fmI~
#ifdef EEE                                                         //~v7fpR~
  if (GutfTestUcs==5)                                              //~v7fpI~
    uviom_clearlineW2(UVIOMCLO_ATTRSTR,0/*data*/,Ppattr,Plen,tgtpos);//~v7fpI~
  else                                                             //~v7fpI~
#endif                                                             //~v7fpI~
    uviom_clearlineW(UVIOMCLO_ATTRSTR,0/*data*/,Ppattr,Plen,tgtpos);//~v7fmI~
  }                                                                //~v7fmI~
    if (yy==Scsrposy+Stoplineoffs)    //csr line                   //~v6G0R~
    {                                                              //~v6G0I~
        utfddgetcsrposbca(0,Ppdbcs-xx,Plen+xx,Scsrposx,&posb,&posc,&posa);//~v6G0R~
        UTRACEP("%s:line Y=%d X=%d,top=%d,csrY=%d posb=%d,posc=%d,posa=%d\n",UTT,yy,xx,Stoplineoffs,Scsrposy,posb,posc,posa);//~v6G0R~
    }                                                              //~v6G0I~
    if (yy==Svhexcsrposy+Stoplineoffs)    //csr line               //~v6G0R~
    {                                                              //~v6G0I~
//      utfddgetcsrposbca(0,Ppdbcs-xx,Plen+xx,Svhexcsrposx,&posbvhex,&poscvhex,0/*after*/);//~v7efR~
        utfddgetcsrposbca(0,Ppdbcs-xx,Plen+xx,Svhexcsrposx,&posbvhex,&poscvhex,&posavhex);//~v7efI~
		Sposcvhex=poscvhex;                                        //~v7ejI~
        UTRACEP("%s:line yy=%d xx=%d,toplineoffs=%d,vhexcsrposy=%d vhexposb=%d,vhexposc=%d\n",UTT,yy,xx,Stoplineoffs,Scsrposy,posbvhex,poscvhex);//~v7efR~
    }                                                              //~v6G0I~
//  int swCpos=1;                                                  //~v7ekR~
	if (posc>=0 || poscvhex>=0)                                    //~v6G0R~
    {                                                              //~v6G0I~
    	for (ii=0,col=0,pucs=Ppucs,pdbcs=Ppdbcs;ii<Pucsctr;ii++,pucs++)//~v6G0R~
    	{                                                          //~v6G0I~
#ifndef TEST                                                       //~v7e8R~
//  		if (col==posb || col==posbvhex)                        //~v7ekR~
    		if (col+startX==posb || col+startX==posbvhex)          //~v7ekI~
            {                                                      //~v7ekI~
//            	swCpos=-1;	//posb;                                //~v7ekR~
            	break;                                             //~v7e9I~
            }                                                      //~v7ekI~
#endif                                                             //~v7e8I~
//  		if (col==posc || col==poscvhex)                        //~v7ekR~
    		if (col+startX==posc || col+startX==poscvhex)          //~v7ekI~
            {                                                      //~v7ekI~
//            	swCpos=0;	//posc;                                //~v7ekR~
            	break;                                             //~v6G0I~
            }                                                      //~v7ekI~
	        chwidth=UDBCSCHK_DBCS1STUCS2NWO(*pdbcs)+1;             //~v6G0I~
        	UTRACEP("%s:col=%d,startX=%d,chwidth=%d ucs=%04x dbcs=%x\n",UTT,col,startX,chwidth,*(Ppucs+ii),*pdbcs);//~v7ekR~
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
//          tgtrect.Right=(SHORT)col-1;                            //~v7ekR~
            tgtrect.Right=(SHORT)(col+startX-1);                   //~v7ekR~
			rc+=uviowrtcellW1_cpu8file_NoLigatureCombineColSplit(Popt,Ppucs,ucsctr,Ppdata,Ppdbcs,Ppattr,len,&tgtrect);//~v6G0R~
#ifndef TEST                                                       //~v7e8R~
//    		if (col==posb || col==posbvhex)	//write posb           //~v7ekR~
//    		if (swCpos==-1)	//write posb                           //~v7ekR~
      		if (col+startX==posb || col+startX==posbvhex)	//write posb//~v7ekI~
            {                                                      //~v7e9I~
//  	        ucsctr=1;                                          //~v7ebR~
    	        int swSurrogate=IS_UTF16_HIGH(*(Ppucs+ii))?1:0;    //~v7ebI~
    	        ucsctr=1+swSurrogate;                              //~v7ebI~
//      		len=(col==posb ? posc-posb : poscvhex-posbvhex);   //~v7ekR~
        		len=(col+startX==posb ? posc-posb : poscvhex-posbvhex);//~v7ekI~
        		tgtrect=*Ptgtrect;                                 //~v7e9I~
//      		tgtrect.Left=(SHORT)col;                           //~v7ekR~
        		tgtrect.Left=(SHORT)(col+startX);                  //~v7ekI~
//	            tgtrect.Right=(SHORT)(col+len);                    //~v7ekR~
  	            tgtrect.Right=(SHORT)(col+startX+len);             //~v7ekI~
                UTRACEP("%s:write posb ii=%d,len=%d,col=%d,startX=%d,ucs=%04x,surrogate=%d\n",UTT,ii,len,col,startX,*(Ppucs+ii),swSurrogate);//~v7ekR~
				rc+=uviowrtcellW1_cpu8file_NoLigatureCombineColSplit(Popt,Ppucs+ii,ucsctr,Ppdata+col,Ppdbcs+col,Ppattr+col,len,&tgtrect);//~v7e9I~
                ii++;                                              //~v7e9I~
                ii+=swSurrogate;                                   //~v7ebI~
                col+=len;                                          //~v7e9I~
            }                                                      //~v7e9I~
//    		if (col==posc || col==poscvhex)                        //~v7ekR~
//    		if (swCpos==0)	//write posb                           //~v7ekR~
      		if (col+startX==posc || col+startX==poscvhex)          //~v7ekI~
        	{                                                      //~v7efI~
        		UTRACEP("%s:col=%d,startX=%d is =posc or =poscvhex\n",UTT,col,startX);//~v7ekR~
    	        int swSurrogate=IS_UTF16_HIGH(*(Ppucs+ii))?1:0;    //~v7efI~
    	        ucsctr=1+swSurrogate;                              //~v7efI~
//      		len=(col==posc ? posa-posc : posavhex-poscvhex);   //~v7ekR~
        		len=(col+startX==posc ? posa-posc : posavhex-poscvhex);//~v7ekI~
        		tgtrect=*Ptgtrect;                                 //~v7efI~
//      		tgtrect.Left=(SHORT)col;                           //~v7ekR~
        		tgtrect.Left=(SHORT)(col+startX);                  //~v7ekR~
//              tgtrect.Right=(SHORT)(col+len);                    //~v7ekR~
                tgtrect.Right=(SHORT)(col+startX+len);             //~v7ekI~
                UTRACEP("%s:write posc ii=%d,len=%d,col=%d,stratX=%d,ucs=%04x,surrogate=%d\n",UTT,ii,len,col,startX,*(Ppucs+ii),swSurrogate);//~v7ekR~
				rc+=uviowrtcellW1_cpu8file_NoLigatureCombineColSplit(Popt,Ppucs+ii,ucsctr,Ppdata+col,Ppdbcs+col,Ppattr+col,len,&tgtrect);//~v7efI~
                ii++;                                              //~v7efI~
                ii+=swSurrogate;                                   //~v7efI~
                col+=len;                                          //~v7efI~
        	}                                                      //~v7efI~
#endif                                                             //~v7e8I~
        }                                                          //~v6G0I~
        ucsctr=Pucsctr-ii;                                         //~v6G0I~
        len=Plen-col;                                              //~v6G0I~
        tgtrect=*Ptgtrect;                                         //~v6G0I~
//      tgtrect.Left=(SHORT)col;                                   //~v7ekR~
        tgtrect.Left=(SHORT)(col+startX);                          //~v7ekI~
		rc+=uviowrtcellW1_cpu8file_NoLigatureCombineColSplit(Popt,Ppucs+ii,ucsctr,Ppdata+col,Ppdbcs+col,Ppattr+col,len,&tgtrect);//~v6G0R~
    }                                                              //~v6G0I~
    else                                                           //~v6G0I~
		rc+=uviowrtcellW1_cpu8file_NoLigatureCombineColSplit(Popt,Ppucs,Pucsctr,Ppdata,Ppdbcs,Ppattr,Plen,Ptgtrect);//~v6G0R~
    return rc;                                                     //~v6G0I~
}//uviowrtcellW1_cpu8file_NoLigatureCombine                        //~v6G0I~
#ifdef QQQ                                                         //~v6G0I~
//*********************************************************************************//~v6G0I~
//*lig:on display combined char on cursor                          //~v6G0R~
Not Used QQQ                                                       //~v7eaI~
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
Not Used QQQ                                                       //~v7eaI~
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
//              combinectr=uvio_getcombinectr(0,ucs2,chwidth,pdbcs,Pucsctr-ii);//~v6G0R~//~v6VgR~
                combinectr=uvio_getcombinectr(0,ucs2,,pucs,chwidth,pdbcs,Pucsctr-ii);//~v6VgR~
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
Not Used QQQ                                                       //~v7eaI~
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
Not Used QQQ                                                       //~v7eaI~
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
//                  combinectr=uvio_getcombinectr(0,ucs2,chwidth,pdbcs,Pucsctr-ii);//~v6G0R~//~v6VgR~
                    combinectr=uvio_getcombinectr(0,ucs2,pucs,chwidth,pdbcs,Pucsctr-ii);//~v6VgR~
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
#ifdef LNX                                                         //~v6V5I~
#else //W32                                                        //~v6VgI~
//***************************************************************************//~v6VgI~
//UDBCSCHK_ISUCSWIDTH0 for also ucs4                               //~v6VgI~
//rc:1:ucs2,2:ucs4,0:!width0                                       //~v6VgI~
//***************************************************************************//~v6VgI~
int uviom_ISUCSWIDTH0W(int Popt,WUCS *Ppucs,UCHAR *Ppdbcs,int Plen)//~v6VgR~
{                                                                  //~v6VgI~
    UWUCS ucs4;                                                    //~v6VgI~
	int rc=0;                                                      //~v6VgI~
//**************************                                       //~v6VgI~
	if (UDBCSCHK_ISUCSWIDTH0(*Ppdbcs))                             //~v6VgI~
    {                                                              //~v6VgI~
    	rc=1;                                                      //~v6VgI~
    }                                                              //~v6VgI~
    else                                                           //~v6VgI~
    if (Plen>1 && UDBCSCHK_ISUCSOVF1ST(*Ppdbcs))                   //~v6VgI~
    {                                                              //~v6VgI~
        ucs4=UTF16_TO_UCS4(*Ppucs,*(Ppucs+1));                     //~v6VgR~
//  	rc=utf22_iswidth0OvfW(0,ucs4);                             //~v6VgI~//~v6W9R~
    	rc=utf22_iswidth0W(0,ucs4);                                //~v6W9I~
        if (rc)                                                    //~v6VgI~
        	rc=2;                                                  //~v6VgI~
    	UTRACEP("%s:ucs4=0x%06x\n",UTT,rc,ucs4);                   //~v6VgI~
    }                                                              //~v6VgI~
//    else                                                           //~v6W9I~//~v6WeR~
//    if (Plen>1 && UDBCSCHK_DBCS1STUCS2(*Ppdbcs))                    //~v6W9R~//~v6WeR~
//    {                                                              //~v6W9I~//~v6WeR~
//        rc=utf22_iswidth0DBCS(0,*Ppucs);                           //~v6W9R~//~v6WeR~
//        if (rc)                                                    //~v6W9I~//~v6WeR~
//            rc=2;                                                  //~v6W9I~//~v6WeR~
//    }                                                              //~v6W9I~//~v6WeR~
    UTRACEP("%s:rc=%d,dbcsid=%02x\n",UTT,rc,*Ppdbcs);              //~v6VgI~
    return rc;                                                     //~v6VgI~
}//uviom_ISUCSWIDTH0W                                              //~v6VgI~
#ifndef WXE                                                        //~v6WuI~
//***************************************************************************//~v6WuI~
//chk combining(NSCM and SCM)                                      //~v6WuI~
//rc:1:ucs2,2:ucs4,0:!width0,4:SCM                                 //~v6WuI~
//***************************************************************************//~v6WuI~
int uviom_iscombining(int Popt,WUCS *Ppucs,UCHAR *Ppdbcs,int Plen,int *Ppucs4,int *Ppchsz)//~v6WuI~
{                                                                  //~v6WuI~
	int rc=0,dbcsid,chsz=1;                                        //~v6WuI~
    int ucs4;                                                      //~v6WuI~
//  UCHAR wkdddata[2];                                             //~v6WuI~//~v6X8R~
//**************************                                       //~v6WuI~
    ucs4=*Ppucs;                                                   //~v6WuI~
    dbcsid=*Ppdbcs;                                                //~v6WuI~
	if (dbcsid)	//>=0x80                                           //~v6WuI~
    {                                                              //~v6WuI~
    	if (UDBCSCHK_ISUCSSBCS(dbcsid))                            //~v6WuI~
        {                                                          //~v6WuI~
//      	ucs4=UTF_GETUCSSBCS(wkdddata,Ppdbcs);                  //~v6WuI~//~v6X8R~
			rc=UDBCSCHK_ISUCSWIDTH0(dbcsid);                       //~v6WuI~
    	}                                                          //~v6WuI~
    	else                                                       //~v6WuI~
        {                                                          //~v6WuI~
        	if (Plen>1 && IS_UTF16_PAIR(ucs4,*(Ppucs+1)))          //~v6WuI~
        		ucs4=UTF16_TO_UCS4(ucs4,*(Ppucs+1));               //~v6WuI~
            rc=utf_iscombining(0,dbcsid,(ULONG)ucs4);              //~v6WuI~
			if (UDBCSCHK_DBCS1STUCS2NWO(dbcsid)) //DBCS/WIDE/NARROW/OVERFLOW//~v6WuI~
            	if (Plen>1)                                        //~v6WuR~
	            	chsz=2;                                        //~v6WuI~
                else                                               //~v6WuI~
            		chsz=-1;	//err id                           //~v6WuI~
        }                                                          //~v6WuI~
    }                                                              //~v6WuI~
//  if (Ppucs)                                                     //~v6WuI~//~v6X1R~
    if (Ppucs4)                                                    //~v6X1I~
    	*Ppucs4=ucs4;                                              //~v6WuR~
    if (Ppchsz)                                                    //~v6WuI~
    	*Ppchsz=chsz;                                              //~v6WuI~
#ifndef FFF                                                        //~v7frI~
    if (rc && Popt & UVIOMICO_NOFMT)// 0x01   //exclude format     //~v7frI~
    {                                                              //~v7frI~
		if (utf4_isFormat(0,(UWUCS)ucs4))                          //~v7frI~
        {                                                          //~v7frI~
        	rc=0;                                                  //~v7frI~
		    UTRACEP("%s:reset rc:combining for format char by option\n",UTT);//~v7frI~
        }                                                          //~v7frI~
    }                                                              //~v7frI~
#endif                                                             //~v7frI~
    UTRACEP("%s:Popt=%02x,rc=%d,dbcsid=%02x,ucs=%06x,chsz=%d,Plen=%d,\n",UTT,Popt,rc,*Ppdbcs,ucs4,chsz,Plen);//~v7frR~
    return rc;                                                     //~v6WuI~
}//uviom_iscombining                                               //~v6WuI~
#endif                                                             //~v6WuI~
#ifndef WXE                                                        //~v6VgI~
//***************************************************************************//~v6VgI~
//Win:write width0                                                 //~v6VgI~
//***************************************************************************//~v6VgI~
int uviom_wrtW0W(int Popt,WUCS *Ppucs,USHORT *Ppattr,int Plen,COORD Ptgtpos,int *Ppwritelen)//~v6VgR~
{                                                                  //~v6VgI~
	WUCS ucss[3],*pucs;                                            //~v6VgR~
    int rc=0,writelen,len;                                         //~v6VgR~
    USHORT attr[3],attrnp;                                         //~v6VgI~
    int ucs4;                                                      //~v7f8I~
    int altch=0;                                                   //~v7fpI~
//***********************                                          //~v6VgI~
	UTRACEP("%s:len=%d,X=%d,Y=%d,*Ppucs=%04x,Gutfcombaltch=%04x,Sposcvhex=%d,Ppattr=%p,*Ppattr=%04x\n",UTT,Plen,Ptgtpos.X,Ptgtpos.Y,*Ppucs,Gutfcombaltch,Sposcvhex,Ppattr,*Ppattr);//~v7fpR~
  if (Sposcvhex==Ptgtpos.X)  //data col by vhex cursor, keep fg=0f(edit)/02(browse)//~v7ejR~
    attrnp=*Ppattr;                                                //~v7ejI~
  else                                                             //~v7ejI~
    attrnp=(*Ppattr & 0xf0)|ATTR_COMBINENP_FG;                     //~v6VgI~
#ifdef TEST                                                        //~v7fpR~
  if (GutfTestUcs==5)                                              //~v7fpI~
   	if (*Ppucs==0x200d)                                            //~v7fpI~
    	attrnp=0x7a;                                               //~v7fpI~
#endif                                                             //~v7fpI~
    attr[0]=attrnp;                                                //~v6VgI~
    attr[1]=attrnp;                                                //~v6VgI~
    attr[2]=attrnp;                                                //~v6VgI~
    rc+=WriteConsoleOutputAttribute(Shconout,attr,Plen,Ptgtpos,&writelen)==0;          //writelen//~v6VgI~
	UTRACEP("%s:WriteConsoleOutputAttribute rc=%d,len=%d,pos=X=%d,Y=%d\n",UTT,rc,Plen,(int)Ptgtpos.X,(int)Ptgtpos.Y);//~v7fkR~
    UTRACED("WriteConsoleOutputAttribute",attr,Plen*sizeof(USHORT));//~v7fkR~
	if (Plen==2)                                                   //~v7f8I~
		ucs4=UTF16_TO_UCS4(*Ppucs,*(Ppucs+1));                     //~v7f8I~
    else                                                           //~v7f8I~
    	ucs4=*Ppucs;                                               //~v7f8I~
	UTRACEP("%s:ucs4=%04x\n",UTT,ucs4);                            //~v7f8I~
//  if (UTF_COMBINEMODE_NP() && Gutfcombaltch)                     //~v7f8R~
    if (UTF_COMBINEMODE_NP() && Gutfcombaltch                      //~v7f8I~
    &&  !utf4_isFormat(0,(UWUCS)ucs4)                              //~v7f8I~
    )                                                              //~v7f8I~
    {                                                              //~v6VgI~
    	ucss[0]=(WUCS)Gutfcombaltch;                               //~v6VgR~
    	ucss[1]=UVIOM_COMBINE_ALTCH2; // '.' ,not written if Plen==1//~v6VgR~
        len=Plen;                                                  //~v6VgI~
    }                                                              //~v6VgI~
    else                                                           //~v6VgI~
    {                                                              //~v6VgI~
#ifndef SSS                                                        //~v7c4I~
//      int ucs4;                                                  //~v7f8R~
//		if (Plen==2)                                               //~v7f8R~
//			ucs4=UTF16_TO_UCS4(*Ppucs,*(Ppucs+1));                 //~v7f8R~
//      else                                                       //~v7f8R~
//        	ucs4=*Ppucs;                                           //~v7f8R~
//  	int altch=uviom_getAltFormat(0,ucs4,0/*Pdefault*/);        //~v7fpR~
    	altch=uviom_getAltFormat(0,ucs4,0/*Pdefault*/);            //~v7fpI~
     if (altch)                                                    //~v7c4I~
     {                                                             //~v7c4I~
	    ucss[0]=(WUCS)altch;    //ushort                           //~v7c4R~
        if (Plen==2)   //ucs4                                      //~v7c4I~
        {                                                          //~v7c4I~
    		ucss[1]=UVIOM_COMBINE_ALTCH2; // '.'   //ucs4 width0 glyph size may be 1//~v7c4I~
            len=2;                                                 //~v7c4I~
        }                                                          //~v7c4I~
        else                                                       //~v7c4I~
        {                                                          //~v7c4I~
            len=1;                                                 //~v7c4I~
        }                                                          //~v7c4I~
     }                                                             //~v7c4I~
     else                                                          //~v7c4I~
#endif                                                             //~v7c4I~
     {                                                             //~v7c4I~
	    ucss[0]=*Ppucs;                                            //~v6VgI~
        if (Plen==2)   //ucs4                                      //~v6VgI~
        {                                                          //~v6VgI~
	    	ucss[1]=*(Ppucs+1);                                    //~v6VgR~
    		ucss[2]=UVIOM_COMBINE_ALTCH2; // '.'   //ucs4 width0 glyph size may be 1//~v6VgR~
            len=3;                                                 //~v6VgI~
        }                                                          //~v6VgI~
        else                                                       //~v6VgI~
        {                                                          //~v6VgI~
            len=1;                                                 //~v6VgR~
        }                                                          //~v6VgI~
      }                                                            //~v7c4I~
    }                                                              //~v6VgI~
	UTRACEP("%s:GutfTestUcs=%d,IS_ON_TERMINAL=%d\n",UTT,GutfTestUcs,IS_ON_TERMINAL());//~v7fkM~
#ifdef EEE                                                         //~v7fkR~
	if (IS_ON_TERMINAL())                                          //~v7fkM~
    {                                                              //~v7fkM~
//  	rc+=WriteConsoleOutputAttribute(Shconout,attr,1,Ptgtpos,&writelen)==0;          //writelen//~v7fkI~
//  	UTRACEP("%s:write attr for combining for WindowsTerminal rc=%d,posX=%d,writelen=%d,attr=%02x\n",UTT,rc,(int)Ptgtpos.X,writelen,attr[0]);//~v7fkI~
//  	if (GutfTestUcs==1 || GutfTestUcs==2)                      //~v7fkR~
//  	{                                                          //~v7fkR~
			WUCS space[4]={' ',' ',' ',0};                         //~v7fkR~
            COORD posclear={Ptgtpos.X,Ptgtpos.Y};                  //~v7fkR~
//  		rc+=uvioWriteConsoleOutputCharacterW(Shconout,space,GutfTestUcs,posclear,&writelen)==0;//~v7fkR~
    		rc+=uvioWriteConsoleOutputCharacterW(Shconout,space,1          ,posclear,&writelen)==0;//~v7fkR~
			UTRACEP("%s:write space for WindowsTerminal rc=%d,posX=%d,writelen=%d\n",UTT,rc,(int)Ptgtpos.X,writelen);//~v7fkM~
//  	}                                                          //~v7fkR~
    }                                                              //~v7fkM~
#endif                                                             //~v7fkR~
    pucs=ucss;                                                     //~v6VgI~
	rc+=uvioWriteConsoleOutputCharacterW(Shconout,pucs,len,Ptgtpos,&writelen)==0;//~v6VgR~
	UTRACEP("%s:rc=%d,ucs=%04x,pos=%d,writelen=%d\n",UTT,rc,*pucs,(int)Ptgtpos.X,writelen);//~v7fkR~
#ifdef EEE                                                         //~v7fkR~
//    if (IS_ON_TERMINAL())                                        //~v7fkR~
//    {                                                            //~v7fkR~
//        if (GutfTestUcs==1 || GutfTestUcs==2)                    //~v7fkR~
//        {                                                        //~v7fkR~
//        rc+=WriteConsoleOutputAttribute(Shconout,attr,Plen,Ptgtpos,&writelen)==0;          //writelen//~v7fkR~
//        UTRACEP("%s:write attr=%02x,len=%d,pos=%d,writelen=%d\n",UTT,attrnp,Plen,(int)Ptgtpos.X,writelen);//~v7fkR~
//        }                                                        //~v7fkR~
//    }                                                            //~v7fkR~
#else                                                              //~v7fkI~
//if (GutfTestUcs<=2 || GutfTestUcs==5)                            //~v7fmR~
#ifdef EEE                                                         //~v7fpI~
  if (GutfTestUcs==5)                                              //~v7foI~
  {                                                                //~v7fpI~
#ifdef TEST                                                        //~v7fpR~
   if (altch!=0x02b)                                               //~v7fpR~
    *attr=0x7a;                                                    //~v7fpI~
#endif                                                             //~v7fpI~
    if (IS_ON_TERMINAL())                                          //~v7fkI~
    {                                                              //~v7fkI~
        rc+=WriteConsoleOutputAttribute(Shconout,attr,Plen,Ptgtpos,&writelen)==0;          //writelen//~v7fkI~
		UTRACEP("%s:WriteConsoleOutputAttribute rc=%d,len=%d,pos=X=%d,Y=%d\n",UTT,rc,Plen,(int)Ptgtpos.X,(int)Ptgtpos.Y);//~v7fkR~
    	UTRACED("WriteConsoleOutputAttribute",attr,Plen*sizeof(USHORT));//~v7fkI~
    }                                                              //~v7fkI~
  }                                                                //~v7fpI~
#endif                                                             //~v7fpI~
#endif                                                             //~v7fkI~
#ifdef EEE                                                         //~v7fmI~
  if (GutfTestUcs==2)                                              //~v7fkI~
	if (IS_ON_TERMINAL())                                          //~v7fkI~
    {                                                              //~v7fkI~
//  	rc+=WriteConsoleOutputAttribute(Shconout,attr,1,Ptgtpos,&writelen)==0;          //writelen//~v7fkI~
//  	UTRACEP("%s:write attr for combining for WindowsTerminal rc=%d,posX=%d,writelen=%d,attr=%02x\n",UTT,rc,(int)Ptgtpos.X,writelen,attr[0]);//~v7fkI~
//  	if (GutfTestUcs==1 || GutfTestUcs==2)                      //~v7fkI~
//  	{                                                          //~v7fkI~
			WUCS space[8]={' ',' ',' ',' ',0};                     //~v7fkR~
            COORD posclear={Ptgtpos.X+1,Ptgtpos.Y};                //~v7fkR~
    		rc+=uvioWriteConsoleOutputCharacterW(Shconout,space,GutfTestUcs,posclear,&writelen)==0;//~v7fkR~
//  		rc+=uvioWriteConsoleOutputCharacterW(Shconout,space,4          ,posclear,&writelen)==0;//~v7fkR~
			UTRACEP("%s:write space for WindowsTerminal rc=%d,posX=%d,writelen=%d\n",UTT,rc,(int)Ptgtpos.X,writelen);//~v7fkI~
//  	}                                                          //~v7fkI~
    }                                                              //~v7fkI~
#endif                                                             //~v7fmI~
    *Ppwritelen=writelen;                                          //~v6VgI~
	UTRACEP("%s:return rc=%d,posX=%d,writelen=%d\n",UTT,rc,(int)Ptgtpos.X,writelen);//~v7fkI~
    return rc;                                                     //~v6VgI~
}//uviom_wrtW0W                                                    //~v6VgI~
//***************************************************************************//~v6WuI~
//Win:write SCM                                                    //~v6WuI~
//***************************************************************************//~v6WuI~
int uviom_wrtSCMW(int Popt,int Pprevucs,int Pidx,int Pucs4,WUCS *Ppucs,USHORT *Ppattr,COORD Ptgtpos)//~v6WuI~
{                                                                  //~v6WuI~
	WUCS wkucs[2],*pucs,ucsalt;                                    //~v6WuI~
    int rc=0,writelen,len,swnp,swcombine;                          //~v6WuR~
    USHORT wkattr[2],attr;                                         //~v6WuI~
//***********************                                          //~v6WuI~
	UTRACEP("%s:Popt=%x,prevucs=%04x,idx=%d,ucs=%06x,X=%d,Y=%d\n",UTT,Popt,Pprevucs,Pidx,Pucs4,Ptgtpos.X,Ptgtpos.Y);//~v6WuI~
    ucsalt=0;	//for compiler warning                             //~v6XbI~
    swnp=UTF_COMBINEMODE_NP() && uviom_getcombaltchUcs(0,&ucsalt); //~v6WuR~
	swcombine=!swnp && Pidx && !(Popt & UVIOO_COMBINEOFF) && utf_iscombinable(UICAO_NOSPACE,(ULONG)Pprevucs);//~v6WuR~
    if (swcombine)                                                 //~v6WuI~
	    attr=*Ppattr;                                              //~v6WuI~
    else                                                           //~v6WuI~
	if (Sposcvhex==Ptgtpos.X)  //data col by vhex cursor, keep fg=06//~v7epI~
    	attr=*Ppattr;                                              //~v7epR~
  	else                                                           //~v7epI~
	    attr=(*Ppattr & 0xf0)|ATTR_COMBINENP_FG;                   //~v6WuI~
	UTRACEP("%s:swcombine=%d,swnp=%d,attr=%04x,*Ppattr=%04x,Spocvhex=%d\n",UTT,swcombine,swnp,attr,*Ppattr,Sposcvhex);//~v7epR~
    wkattr[0]=attr;                                                //~v6WuR~
    wkattr[1]=attr;                                                //~v6WuR~
    len=2;                                                         //~v6WuI~
    rc+=WriteConsoleOutputAttribute(Shconout,wkattr,len,Ptgtpos,&writelen)==0;          //writelen//~v6WuI~
	UTRACEP("%s:WriteConsoleOutputAttribute rc=%d,len=%d,pos=X=%d,Y=%d\n",UTT,rc,len,(int)Ptgtpos.X,(int)Ptgtpos.Y);//~v7fkR~
    UTRACED("WriteConsoleOutputAttribute",wkattr,len*sizeof(USHORT));//~v7fkI~
	len=1+UTF_ISUCS4(Pucs4);                                       //~v6WuI~
    if (swnp)                                                      //~v6WuI~
    {                                                              //~v6WuI~
    	wkucs[0]=ucsalt;                                           //~v6WuI~
    	wkucs[1]=UVIOM_COMBINE_ALTCH2; // '.' ,not written if Plen==1//~v6WuI~
        pucs=wkucs;                                                //~v6WuI~
        len=2;                                                     //~v6WuI~
    }                                                              //~v6WuI~
    else                                                           //~v6WuI~
    {                                                              //~v6WuI~
        if (len==1)                                                //~v6WuI~
        {                                                          //~v6WuI~
#ifndef TEST                                                       //~v7e8I~
      		wkucs[0]=*Ppucs;                                       //~v7e8R~
  	    	wkucs[1]=' ';                                          //~v7e8R~
#else                                                              //~v7e8I~
	    	wkucs[0]=0xa0;                                         //~v7e8R~
    		wkucs[1]=*Ppucs;                                       //~v7e8R~
#endif                                                             //~v7e8I~
	        pucs=wkucs;                                            //~v6WuI~
            len=2;                                                 //~v6WuI~
        }                                                          //~v6WuI~
        else                                                       //~v6WuI~
		    pucs=Ppucs;                                            //~v6WuI~
    }                                                              //~v6WuI~
	rc+=uvioWriteConsoleOutputCharacterW(Shconout,pucs,len,Ptgtpos,&writelen)==0;//~v6WuI~
	UTRACEP("%s:rc=%d,writelen=%d\n",UTT,rc,writelen);             //~v6WuI~
    return rc;                                                     //~v6WuI~
}//uviom_wrtSCMW                                                   //~v6WuI~//~v7c4R~
#endif //!WXE                                                      //~v6VgI~
#endif                                                             //~v6V5I~
//***************************************************************  //~v6WrI~
//*return ucs ctr                                                  //~v6WrI~
//!!! use only when COMBINE_NP
//***************************************************************  //~v6WrI~
#ifdef W32  //copy is also on uvioml.c                             //~v7bGI~.//~v7bGI~
int uviom_getcombaltchUcs(int Popt,WUCS *Ppucs)                    //~v6WrI~
{                                                                  //~v6WrI~
	int rc=1;                                                      //~v6WrI~
//*******************                                              //~v6WrI~
#if defined LNX && !defined XXE	//linux console
	*Ppucs=Scombaltch;
#else
	*Ppucs=Gutfcombaltch;                                          //~v6WrI~
#endif
    if (Popt & UVIOM_GCAC_2CELL)                                   //~v6WrI~
    {                                                              //~v6WrI~
    	*(Ppucs+1)=UVIOM_COMBINE_ALTCH2;                           //~v6WrI~
        rc=2;                                                      //~v6WrI~
    }                                                              //~v6WrI~
    if (*Ppucs<0x20)
        rc=0;
    UTRACEP("%s return rc=%d,ucs=%0x\n",UTT,rc,*Ppucs);
    return rc;                                                     //~v6WrI~
}//uviom_getcombaltchUcs                                           //~v6WrI~
#endif  //W32                                                      //~v7bGI~.//~v7bGI~
//**************************************************************   //~v7bWI~
int uviom_getAltFormat(int Popt,int Pucs,int Pdefault)             //~v7bWI~
{                                                                  //~v7bWI~
	int rc=Pdefault;                                               //~v7bWI~
  if (Popt & UVMGAFO_GETORGUCS)                                    //~v7c4I~
  {                                                                //~v7c4I~
    if (Pucs==UVIOM_ALTCH_ZWJ)                                     //~v7c4I~
    	rc=UCS_ZWJ;                                                //~v7c4I~
    else                                                           //~v7c4I~
    if (Pucs==UVIOM_ALTCH_ZWNJ)                                    //~v7c4I~
    	rc=UCS_ZWNJ;                                               //~v7c4I~
    else                                                           //~v7c4I~
    if (Pucs==UVIOM_ALTCH_FORMAT)                                  //~v7c4I~
    	rc=Pdefault;                                               //~v7c4I~
    else                                                           //~v7c4I~
    	rc=0;                                                      //~v7c4I~
  }                                                                //~v7c4I~
  else                                                             //~v7c4I~
  {                                                                //~v7c4I~
    if (Pucs==UCS_ZWJ)                                             //~v7bWI~
    	rc=UVIOM_ALTCH_ZWJ;                                        //~v7bWR~
    else                                                           //~v7bWI~
    if (Pucs==UCS_ZWNJ)                                            //~v7bWI~
    	rc=UVIOM_ALTCH_ZWNJ;                                       //~v7bWR~
    else                                                           //~v7bWI~
    if (utf4_isFormat(0,Pucs))                                     //~v7bWI~
    	rc=UVIOM_ALTCH_FORMAT;                                     //~v7bWR~
  }                                                                //~v7c4I~
    UTRACEP("%s return rc=0x%04x,ucs=0x%04x,default=0x%04x\n",UTT,rc,Pucs,Pdefault);//~v7bWR~
    return rc;                                                     //~v7bWI~
}                                                                  //~v7bWI~
