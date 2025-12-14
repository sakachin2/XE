//*CID://+vbEgR~:                            update#= 3194;        //~vbEgR~
//*************************************************************    //~v6VdR~
//vbEg:251112 (LNXCON)hcopy;save/get by dd str for utf8(shadow of combining generated double a+x300 and a and a+301)//~vbEgI~
//v7ff:251111 (LNXCON)did not filled cchar_t combining(up to not 4 but 3)//~v7ffI~
//v7fe:251110 (LNXCON)hcopy;drop inserted padding                  //~v7fdI~
//v7fd:251110 (LNXCON)set "+" for Format even PADDING              //~v7fdI~
//v7f5:251008 (LNX)treate ZWJ(u-200d) as combining when ligoff to avoid intermedeate colomn by 200d//~v7f5I~
//v7f4:251007 (LNX)by v7f1, w0 NoComb(including format)  was not displayed by altchFormat('='). ifndef JJJ//~v7f4I~
//v7f3:250926 (LNX bug)for ucs4 of wcwidth=0, set dbcs1 and dbcs2 for utcfwcwidth=2//~v7f3I~
//v7f1:250926 (LNX)avoid combining by Format char of wcwidth=0     //~v7f1I~
//v7ez:250809 set BG attr for wide sbcs 2nd cell                   //~v7ezI~
//v7ey:250809 errmsg missing break by color change                 //~v7eyI~
//v7ex:250807 ZWJ/ZWNJ vhex color is green                         //~v7exI~
//v7er:250804 (LNXCON)change padding char of ucs4 to space. It effect to next scm color of vhex csrpos.//~v7erI~
//v7eq:250802 (BUG:LNX)option padding for SCM was ignored and shown itself//~v7eqI~
//v7ep:250802 v7ej for SCM(attr of data pos by vhex csr)           //~v7epI~
//v7en:250802 (Bug:LNXCON) vhexcorpos show itself when both LIG ON/OFF.//~v7enI~
//v7em:250729 (Bug:LNXCON) data pos color was not corresponding to vhex line cpos//~v7emI~
//v7ei:250721 (LNXCON) ucs4+combining; it was combining to padding char.//~v7eiI~
//v7eh:250717 (LNXCON) show combining char of posa even combining mode like as gxe.//~v7ehI~
//v7c8:240626 (LNXCON:bug) Lig:Off,split shadow;ucs4+ZWJ write null entry and erase followings.//~v7c8I~
//v7c4:240618 (Bug of v7bW) if rep ZWJ to altch,it becomes next combining base.(display doble "+")//~v7c4I~
//v7c2:240611 (LNXCON:Bug)linenoCol separator should not be combine base//~v7c2I~
//v7bZ:240528 break by color (use bg)                              //~v7bZI~
//v7bY:240526 (Bug) if top col is combining, use '|' as combine base//~v7bYI~
//v7bX:240526 it should be set break at next of lineno fld         //~v7bXI~
//v7bW:240525 display category Cf by "+" as itself/shadow          //~v7bWI~
//v7bV:240523 category Cf(Format is wcwidth=0(52 chars) or 1(11 chars) but not combining(ie wcwidth=0 dose not means combining)//~v7bVI~
//v7bU:240522 (Bug)lig on,split mode, itself overrup widesbcs      //~v7bUI~
//v7bT:240520 (Bug)break by color prevent combining(tab display set green to combining)//~v7bTI~
//v7bS:240520 (Bug)DBCS combine shadow write "." afterr shadow     //~v7bSI~
//v7bR:240519 (Bug)avoid set break to line separator('|')          //~v7bRI~
//v7bQ:240518 (Bug)dbcsbase padding has to be 2 cell               //~v7bQI~
//v7bP:240518 keep space after widesbcs for also lig on            //~v7bPI~
//v7bN:240517 ZWJ is 2 pattern of combining and emoji mixing.      //~v7bNI~
//            The former is after of no-spacing character. Try not to set combining char in chars[n].//~v7bNI~
//            Because cat on gnome terminal display successfully partially.//~v7bNI~
//v7bM:240515 (Bug)LNX;2 combining case for wide sbcs. combining was set to padding.//~v7bMI~
//v7bL:240513 LNX;do not comnine with SCM break. it display shadow width 2 cell//~v7bLI~
//v7bK:240513 LNX;when opt combine padding, treate it as itself for SCM//~v7bKI~
//v7bJ:240427 need csrpos chk on continued combining chars         //~v7bJI~
//v7bH:240427 when Lig:ON, requires distance from WideSBCS         //~v7bHI~
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
	#define _XOPEN_SOURCE       //for wcwidth                      //~v6K7I~
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//*******************************************************
		#include <iconv.h>	         //v1.3 add                    //~v5n8I~
    #ifdef UTF8SUPPH                                               //~v62XM~
//  	#define __USE_XOPEN         //for wcwidth                  //~v62mM~//~v6K7R~
		#include <wchar.h>                                         //~v62mM~
    #endif                                                         //~v62XI~
#define _XOPEN_SOURCE_EXTENDED		//ncurses define               //~v5n8I~
		#include <ucurses.h>	         //v1.3 add                //~v5n8I~
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
#include <uviom.h>      //ukbd_w95init                             //~v5n8I~
	#define UVIOL_INTERNAL  //define uviol_cell2attr               //~v5n8I~
	#include <uviol.h>                                             //~v5n8I~
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
//  static int Sswligatureword;	//ligature mode eve if ligature option=ON for dirlist//~v6EiR~
    static int Scsrposx,Scsrposy;                                  //~v652I~
    static int Svhexcsrposx,Svhexcsrposy;                          //~v658I~
//#endif                                                           //~v653R~
    static  int     Sscrwidth;   	//scr line size                //~v5n8I~
    static  int     Sscrsize;   	//col*row                      //~v5n8I~
    static iconv_t *Sconverters;                                   //~v5n8I~
	#ifndef XXE                                                    //~v5n8I~
		static chtype  *Spspaceline;                               //~v5n8R~
		static cchar_t *Spspacelinew,*Spwkcchar;                   //~v5n8I~
		static chtype  *Spcellsv;        //for readcell str        //~v5n8I~
		static int     Scursesver;       //maj*100+Min             //~v656I~
        #define VER_COMBINE   507        //good combining support  //~v656I~
		static int     Scombaltch;                                 //~v658I~
		int uviom_setcombineJoiner(int Popt,int Plineopt,WUCS Pucs,chtype *Ppcht,cchar_t *Ppcchar);//~v7bBR~
	#endif                                                         //~v5n8I~
	int uviom_setcombineZWJ(int Popt,int PswBreak,PCCH  Ppcchar0,PCCH Ppcchar,int *Ppoutctr);//~v7bNI~
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
                                                                   //~v653I~
//  int uvio_ddcht2cchar_ligature(int Popt,chtype *Ppcht,UCHAR *Ppdbcs,int Plen,cchar_t *Ppcchar,int Prow,int Pcol,int *Ppoutctr);//~v653R~//~v6EmR~
    int uvio_ddcht2cchar_ligature(int Popt,int Plineopt,chtype *Ppcht,UCHAR *Ppdbcs,int Plen,cchar_t *Ppcchar,int Prow,int Pcol,int *Ppoutctr);//~v6EmI~
                                                                   //~v653I~
  #endif //CURSESW                                                 //~v5n8I~
// #define UVIOM_MAXCOMBINE (CCHARW_MAX-1)  //                     //~v653I~
#ifdef UTF8UCS2                                                    //~v640M~
	int uvio_mdd2u(int Popt,UCHAR *Ppdata,UCHAR *Ppdbcs,int Plen,WUCS *Ppucs,int Poutbuffsz,int *Ppoutucsctr,int *Ppucsdbcsctr,int *Ppucssbcsctr);//~v640M~
    #define UVIOMD2UO_ERRREP   0xff                                //~v640I~
    #define UVIOMD2UO_VIO      0x0100                              //~v640I~
    #define UVIOM2UO_DDSTR     0x02  //source data/dbcs is ucs     //~v65mI~
    #define UVIOM2UO_MBCS      0x04  //source data is locale str   //~v65mI~
   #ifndef XXE                                                     //~v640I~
//	int uvio_ddcht2cchar(int Popt,chtype *Ppcht,UCHAR *Ppdbcs,int Plen,cchar_t *Ppcchar,int *Ppoutctr);//~v640R~//~v653R~
//  	int uvio_ddcht2cchar(int Popt,chtype *Ppcht,UCHAR *Ppdbcs,int Plen,cchar_t *Ppcchar,int Prow,int Pcol,int *Ppoutctr);//~v653I~//~v6EmR~
    	int uvio_ddcht2cchar(int Popt,int Plineopt,chtype *Ppcht,UCHAR *Ppdbcs,int Plen,cchar_t *Ppcchar,int Prow,int Pcol,int *Ppoutctr);//~v6EmI~
//	int uviom_setcombine(int Popt,WUCS Pucs,chtype *Ppcht,cchar_t *Ppcchar0,cchar_t *Ppcchar,UCHAR *Ppdbcs,int Plen,int *Ppcombinectr,int *Ppwritectr);//~v653I~//~v6EmR~
//	int uviom_setcombine(int Popt,int Plineopt,WUCS Pucs,chtype *Ppcht,cchar_t *Ppcchar0,cchar_t *Ppcchar,UCHAR *Ppdbcs,int Plen,int *Ppcombinectr,int *Ppwritectr);//~v6EmI~//~v6V5R~
  	int uviom_setcombine(int Popt,int Plineopt,WUCS Pucs,chtype *Ppcht,cchar_t *Ppcchar0,cchar_t *Ppcchar,UCHAR *Ppdbcs,int Plen,int *Ppcombinectr,int *Ppwritectr,int *Ppmblen);//~v6V5I~
	#define UVIOMSCO_FORCEBREAK      0x01                          //~v653I~
//	#define UVIOMSCO_SETBREAKIFTOP   0x02                          //~v653I~//~v658R~
//  #define UVIOMSCO_SETATTR         0x04                          //~v656I~//~v658R~
    #define UVIOMSCO_NOSETATTR       0x08                          //~v658I~
    #define UVIOMSCO_BASEUNP         0x10                          //~v6WeI~
    #define UVIOMSCO_CSRLINE         0x20                          //~v7bEI~
    #define UVIOMSCO_WIDESBCS        0x40                          //~v7bJI~
    #define UVIOMSCO_COMB2SCM        0x80  //u3099,309a:dbcs       //~v7bQI~
#ifndef JJJ                                                        //~v7f4I~
    #define UVIOMSCO_W0NOCOMB      0x0100  //width=0 not combining char//~v7f4I~
#endif                                                             //~v7f4I~
   #endif                                                          //~v640I~
#endif                                                             //~v640M~
#define MAX_SCMCTR   10                                            //~v7bER~
#define ULHLINENOSZ_1 7                                            //~v7bJI~
#define SEP_LINENO   '|'                                           //~v7bJI~
#define SEP_LINENO2  '*'    //updateline                           //~v7bYI~
PCCH ScchTop;                                                      //~v7bJR~
int  SwidthLineno;                                                 //~v7bRI~
#ifdef LNXCON                                                      //~v7f4R~
#ifndef JJJ                                                        //~v7f4I~
static int SswComb1W0NOCOMB;	//parm to setcombine1              //~v7f4R~
#endif                                                             //~v7f4I~
#endif                                                             //~v7f4I~
int getTopCCH(int Plineopt,chtype *Ppcht,char *Ppdbcs,int Plen);   //~v7bJI~
void getcsrposbca(int Popt,char *Ppdbcs,int Pcol,int Pposx,int *Ppposb,int *Ppposc,int *ppposa);//~v7bRI~
int getBaseUCS(int Popt,cchar_t *Ppcch);                           //~v7c4I~
#ifndef JJJ                                                        //~v7f4I~
int uviom_setcombine_W0NOCOMB(int Popt,int Plineopt,WUCS Pucs,chtype *Ppcht,cchar_t *Ppcchar0,cchar_t *Ppcchar,UCHAR *Ppdbcs,int Plen,int *Ppcombinectr,int *Ppwritectr,int *Ppmblen);//~v7f4I~
#endif                                                             //~v7f4I~
//*******************************************************          //~v5n8I~
#ifndef XXE                                                        //~v6D9I~
int uviom_fillattrspace(int Popt,int Prow,int Pcol,attr_t Pattr,int Pctr);//~v6D9I~
attr_t uviom_set_padattr(int Popt,attr_t Pattr);                   //~v6D9R~
int uviom_setunpucs(int Popt,cchar_t *Ppcchar,int Pucs,int Perrrep,int Papiwidth);//~v6DaR~
#define UVMSUUO_OVF  0x01      //ucs4                              //~v6DaI~
#endif                                                             //~v6D9I~
#define ATTR_SPACEDELM   0x01                                        //~v6E6R~//~v6E8I~
#define ATTR_UCS         0x02                                      //~v6E8I~
#define ATTR_UCS_R       0x20                                      //~v6E8I~
#define ATTR_WHITE       0x07                                      //~v6E8I~
#define ATTR_WHITE_R     0x70                                      //~v6E8I~
                                                                   //~v6EiI~
#ifndef XXE                                                        //~v6H0I~
attr_t uviom_attr_itself(int Popt,chtype Pchtype);                 //~v6EnR~
#endif                                                             //~v6H0I~
#define DBCSJ_BA_COMBINE     0x3099                                //~v6G1I~
#define DBCSJ_BA_STANDALONE  0x309b                                //~v6G1I~
#define DBCSJ_PA_COMBINE     0x309a                                //~v6G1I~
#define DBCSJ_PA_STANDALONE  0x309c                                //~v6G1I~
	#ifndef XXE                                                    //~v700M~
int uviom_ISUCSWIDTH0(int Popt,chtype *Pcht,UCHAR *Ppdbcs,int Plen,WUCS *Ppucs4);
#define IUW0O_COMB2SCM_COMB    0x01    //comb2scm is combining     //~v6X5I~
//#define IUW0O_NOZWJZWNJ        0x02    //return false for ZWJ(200d)/ZWNJ(200c)//~v7bBI~//~v7bVR~
#define IUW0O_NOCOMB           0x02    //return false width=0 but not combining//~v7bVI~
int uviom_iscombining(int Popt,chtype *Ppcht,UCHAR *Ppdbcs,int Plen,WUCS *Ppucs4,int *Ppchsz);//~v6WuI~
//#define ICO_NOZWJZWNJ          0x01    //return false for ZWJ(200d)/ZWNJ(200c)//~v7bNI~//~v7bVR~
#ifndef JJJ                                                        //~v7f5I~
#define ICO_ZWJASCOMB            0x01    //treate ZWJ(u-200d) as combining char//~v7f5I~
#endif                                                             //~v7f5I~
#define ICO_NOFMT                0x02    //excluse format          //~v7bVI~
#define ICO_NOFMTRC              0x04    //set rc for format       //~v7bVI~
#define ICO_NOCOMB2SCMRC         0x08    //No set rc for COMB2SCM  //~v7bVR~
#define ICO_NOSCM                0x10    //exclude SCM             //~v7bVI~
	#endif                                                         //~v700I~
#ifndef XXE                                                        //~v6W6I~
void uviom_spaceclear(int Popt,int Prow,int Pcol,int Plinewidth);  //~v6W6I~
#define SCO_NOREFRESH   0x01                                       //~v6W6I~
void uviom_clearscr(int Popt);                                     //~v6W6I~
int uviom_setcombineSCM_ligature(int Popt,int Plineopt,int Pucs,chtype *Ppcht,cchar_t *Ppcchar0,cchar_t *Ppcchar,int PchszSCM,int *Ppwritelen);//~v7bER~
//int uviom_setcombineSCM_nonligature(int Popt,int Plineopt,int Pcol,int *Pposbreak,int Pucs,chtype *Ppcht,UCHAR *Ppdbcs,cchar_t *Ppcchar0,cchar_t *Ppcchar,int PchszSCM,int Plen,int *Ppwritelen,int *Ppstrsz);//~v7bER~//~v7bJR~
int uviom_setcombineSCM_nonligature(int Popt,int Plineopt,int Pucs,chtype *Ppcht,UCHAR *Ppdbcs,cchar_t *Ppcchar0,cchar_t *Ppcchar,int PchszSCM,int *Ppwritelen,int *Ppstrsz);//~v7bJR~
int getCombineCtrSCM(int Popt,cchar_t *Ppcchar,int Ppos,int Plen,int *Ppwidth);//~v7bER~//~v7bJR~
int getStringSCM(int Popt,int Pcol,int *Pposbreak,chtype *Ppcht,UCHAR *Ppdbcs,int Plen,cchar_t *Ppcchar,int *Ppstrsz);//~v7bER~//~v7bJR~
cchar_t * setBaseEntry(int Popt,cchar_t *Ptop,cchar_t *Pcur,int Pcolor,int Ppucs,int *Ppcombctr);//~v7bJR~
int setBaseEntrySCM(int Popt,cchar_t *Ppcchar0,cchar_t *Ppcchar,cchar_t **Pppbase);//~v7bJI~
#define   SBEO_2CELL      0x01          //combining is dbcs or widesbcs//~v7bJI~
int getCombinedStringWidth(int Popt,cchar_t *Ppbase,int *Ppctr);   //~v7bJR~
//int getCombinedSize(int Popt,cchar_t *Ppcch,cchar_t *Ppcche,int *Ppctr,int *Ppsz,);//~v7bJR~//~v7bPR~
int getCombinedSize(int Popt,cchar_t *Ppcch,cchar_t *Ppcche,int *Ppctr,int *Ppsz,int *Pcombsz,int *PpswWideSbcsCombBase);//~v7bPR~
PCCH getBaseSCM(int Popt,PCCH Ppcch0,PCCH Ppcch);                  //~v7bJI~
#define GBSO_SCM    0x01		//find break SCMBASE or SCM        //~v7bLR~
#endif //XXE                                                       //~v6W6I~
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
#ifdef LNXCON                                                      //+vbEgI~
  	if (Guviol_flag & UVIOL_DDHCOPY)	//always this              //~vbEgI~
    {                                                              //~vbEgI~
	    void *scrdata=UALLOCC(1,(UINT)(Sscrsize*((int)sizeof(chtype)+1)));//~vbEgR~
        Guvioscrddchtype=(chtype*)scrdata;                         //~vbEgR~
        Guvioscrdddbcs=(char*)(scrdata+Sscrsize*(int)sizeof(chtype));//~vbEgR~
    }                                                              //~vbEgI~
#endif                                                             //+vbEgI~
    return;                                                        //~v5n8I~
}//uviom_init                                                      //~v5n8I~
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
                                                                   //~v5n8I~
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
      UTRACEP("savecell row=%d,col=%d,len=%d\n",Prow,Pcol,Plen);     //~v5n8I~//~v6hhR~//~v7ffR~
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
  	UTRACED("uviom_savecell",pcht,Plen*CCTSZ);                     //~v5n8I~//~v6hhR~//~v7ffR~
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
//*******************************************************          //~vbzPI~
//read screen cchar_t                                              //~v7bxR~
//*******************************************************          //~vbzPI~
int uviom_readConsole(int Popt,int Prow,int Pcol,int Plen,cchar_t *Ppcchar)//~vbzPR~
{                                                                  //~vbzPI~
#ifdef AAA                                                         //~vbzPI~
	cchar_t *pcchar;                                               //~vbzPI~
    int ii;                                                        //~vbzPI~
#endif                                                             //~vbzPI~
    int pos,yy,xx;                                                 //~vbzPR~
//************************                                         //~vbzPI~
    UTRACEP("%s:row=%d,col=%d,len=%d\n",UTT,Prow,Pcol,Plen);       //~vbzPR~
	pos=Prow*Sscrwidth+Pcol;                                       //~vbzPI~
    if (pos+Plen>Sscrsize)                                         //~vbzPI~
    {                                                              //~vbzPI~
    	UTRACEP("%s:ERR uviom_readcell overflow scrsize=%d,row=%d,col=%d,len=%d\n",UTT,Sscrsize,Prow,Pcol,Plen);//~vbzPR~
    	return 4;                                                  //~vbzPI~
    }                                                              //~vbzPI~
    yy=Prow;                                                       //~vbzPI~
    xx=Pcol;                                                       //~vbzPI~
#ifdef AAA                                                         //~vbzPR~
    for (ii=0,pcchar=Ppcchar;ii<Plen;ii++,pcchar++,xx++)  //TODO test//~vbzPR~
    {                                                              //~vbzPI~
    	mvin_wch(yy,xx,pcchar);                                    //~vbzPI~
    }                                                              //~vbzPI~
	UTRACED("out cchar by wch",Ppcchar,Plen*(int)sizeof(cchar_t)); //~vbzPI~
#endif                                                             //~vbzPR~
    mvin_wchnstr(yy,xx,Ppcchar,Plen);                              //~vbzPI~
	UTRACED("out cchar by wchnstr",Ppcchar,Plen*(int)sizeof(cchar_t));//~vbzPR~
    return 0;                                                      //~vbzPI~
}//uviom_readConsole                                               //~vbzPI~
//*******************************************************          //~v7bxI~
//read screen ucs                                                  //~v7bxI~
//*******************************************************          //~v7bxI~
int uviom_readConsoleCchar(int Popt,int Prow,int Pcol,int Plen,UWCHART *Ppucs)//~v7feR~
{                                                                  //~v7feR~
	cchar_t wkcchart[UVIOM_MAXCOL]; //240                          //~v7feR~
    int ii,jj,ctrucs=0;                                            //~v7feR~
//************************                                         //~v7feR~
    mvin_wchnstr(Prow,Pcol,wkcchart,Plen);                         //~v7feR~
	UTRACED("mvin_wchnstr",wkcchart,Plen*(int)sizeof(cchar_t));    //~v7feR~
    cchar_t *pcchar=wkcchart;                                      //~v7feR~
    UWCHART *pucs=Ppucs,ucs;                                       //~v7feR~
    for (ii=0;ii<Plen;ii++,pcchar++)                               //~v7feR~
    {                                                              //~v7feR~
        if (pcchar->attr & UVIOMATTR_EXT_NOHCOPY)                  //~v7feR~
        {                                                          //~v7feR~
            UTRACEP("%s:NOHCOPY ucs=%04x\n",UTT,pcchar->chars[0]); //~v7feR~
            continue;                                              //~v7feR~
        }                                                          //~v7feR~
//      for (jj=0;jj<UVIOM_MAXCOMBINE;jj++)                        //~v7feR~//~v7ffR~
        for (jj=0;jj<=UVIOM_MAXCOMBINE;jj++)                       //~v7ffI~
        {                                                          //~v7feR~
            ucs=pcchar->chars[jj];                                 //~v7feR~
            if (!ucs)                                              //~v7feR~
                break;                                             //~v7feR~
    	    *pucs++=ucs;                                           //~v7feR~
            ctrucs++;                                              //~v7feR~
        }                                                          //~v7feR~
    }                                                              //~v7feR~
    for (ii=ctrucs;ii<Plen;ii++)                                   //~v7feR~
    {                                                              //~v7feR~
    	*pucs++=' ';                                               //~v7feR~
    }                                                              //~v7feR~
	UTRACEP("%s:Plen=%d,ctrucs=%d\n",UTT,Plen,ctrucs);             //~v7feR~
	UTRACED("out ucs",Ppucs,Plen*(int)sizeof(UWCHART));            //~v7feR~
    return 0;                                                      //~v7feR~
}                                                                  //~v7feR~
int uviom_readConsoleUcs(int Popt,int Prow,int Pcol,int Plen,UWCHART *Ppucs)//~v7bxI~
{                                                                  //~v7bxI~
#ifdef TEST                                                        //~v7feI~
    int pos,yy,xx;                                                 //~v7bxI~
#else                                                              //~v7feI~
    int pos;                                                       //~v7feI~
#endif                                                             //~v7feI~
//************************                                         //~v7bxI~
    UTRACEP("%s:row=%d,col=%d,len=%d\n",UTT,Prow,Pcol,Plen);       //~v7bxI~
	pos=Prow*Sscrwidth+Pcol;                                       //~v7bxI~
    if (pos+Plen>Sscrsize)                                         //~v7bxI~
    {                                                              //~v7bxI~
    	UTRACEP("%s:ERR uviom_readcell overflow scrsize=%d,row=%d,col=%d,len=%d\n",UTT,Sscrsize,Prow,Pcol,Plen);//~v7bxI~
    	return 4;                                                  //~v7bxI~
    }                                                              //~v7bxI~
#ifdef TEST                                                        //~v7feM~
    yy=Prow;                                                       //~v7bxI~
    xx=Pcol;                                                       //~v7bxI~
    mvinnwstr(yy,xx,Ppucs,Plen);                                  //~4413I~//~v7bxI~
	UTRACED("out ucs by mvinnwstr",Ppucs,Plen*(int)sizeof(UWCHART));//~v7bxI~
#else                                                              //~v7feR~
	uviom_readConsoleCchar(Popt,Prow,Pcol,Plen,Ppucs);             //~v7feR~
#endif                                                             //~v7feR~
    return 0;                                                      //~v7bxI~
}//uviom_readConsoleUcs                                            //~v7bxI~
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
    UTRACEP("%s:uvio_mvaddchnstrF opt=%x,len=%d,row=%d,col=%d\n",UTT,Popt,Plen,Prow,Pcol);//~v5n8R~//~v6hhR~//~v6V6R~
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
UTRACEP("%s:return rc=%d\n",UTT,rc);                    //~v5n8R~//~v6hhR~//~v6V6R~
    return rc;                                                     //~v5n8I~
}//uvio_mvaddchnstrF                                               //~v5n8R~
//*******************************************************          //~v7bJI~
void clearAttrFlags(cchar_t *Ppcchar,int Plen)                     //~v7bJI~
{                                                                  //~v7bJI~
	int ii;                                                        //~v7bJI~
    cchar_t *pch;                                                  //~v7bJR~
	for (ii=0,pch=Ppcchar;ii<Plen;ii++,pch++)                      //~v7bJI~
    {                                                              //~v7eiI~
		pch->attr &= UVIOMATTR_CURSESMASK;                         //~v7bJI~
#ifdef TEST      //not highlighten yellow but bold font            //~v7eiR~
		pch->attr |= A_BOLD;	//00200000                         //~v7eiI~
#endif                                                             //~v7eiI~
    }                                                              //~v7eiI~
    UTRACED("Ppcchar",Ppcchar,(int)sizeof(cchar_t)*Plen);          //~v7eiR~
}                                                                  //~v7bJI~
//*******************************************************          //~v7ezI~
int fillattrWideSbcs(int Popt,int Prow,int Pcol,cchar_t *Ppcchar,int Plen)//~v7ezI~
{                                                                  //~v7ezI~
	cchar_t *pcchar=Ppcchar;                                       //~v7ezI~
    int ii,col,ctr=0;                                              //~v7ezR~
    attr_t attr;                                                   //~v7ezR~
	cchar_t wkcch;                                                 //~v7ezI~
    UTRACEP("%s:row=%d,col=%d,len=%d,char[0]=%04x,attr=%08x\n",UTT,Prow,Pcol,Plen,Ppcchar->chars[0],Ppcchar->attr);//~v7ezR~
	for (ii=0,col=Pcol;ii<Plen;ii++,pcchar++,col++)                //~v7ezI~
    {                                                              //~v7ezI~
    	attr=pcchar->attr;                                         //~v7ezI~
    	if (attr & UVIOMATTR_EXT_WIDESBCS && attr & 0xf000)	//bg   //~v7ezR~
        {                                                          //~v7ezI~
        	ctr++;                                                 //~v7ezI~
        	col++;                                                 //~v7ezI~
        }                                                          //~v7ezI~
        else                                                       //~v7ezI~
    	if (attr & UVIOMATTR_DBCS1)                                //~v7ezI~
        	col++;                                                 //~v7ezI~
    }                                                              //~v7ezI~
    UTRACEP("%s:ctr=%d\n",UTT,ctr);                                //~v7ezI~
    if (!ctr)                                                      //~v7ezI~
    {                                                              //~v7ezI~
	    UTRACEP("%s:return by ctr=0\n",UTT);                       //~v7ezI~
    	return 0;                                                  //~v7ezR~
    }                                                              //~v7ezI~
    memset(&wkcch,0,sizeof(wkcch));                                //~v7ezR~
	wkcch.chars[0]=' ';                                            //~v7ezR~
	pcchar=Ppcchar;                                                //~v7ezI~
	for (ii=0,col=Pcol;ii<Plen;ii++,pcchar++,col++)                //~v7ezR~
    {                                                              //~v7ezI~
    	attr=pcchar->attr;                                         //~v7ezR~
    	if (attr & UVIOMATTR_EXT_WIDESBCS && attr & 0xf000)	//bg   //~v7ezI~
        {                                                          //~v7ezI~
            wkcch.attr=attr & (UVIOMATTR_COLORMASK);               //~v7ezR~
            move(Prow,col+1);    //mvaddchnstr miss current pos    //~v7ezR~
            add_wchnstr(&wkcch,1);                                 //~v7ezR~
            UTRACEP("%s:write space ii=%d,col=%d,attr=%08x\n",UTT,ii,col+1,wkcch.attr);//~v7ezR~
        }                                                          //~v7ezI~
        int len;                                                   //~v7ezI~
    	if (attr & UVIOMATTR_DBCS1)                                //~v7ezR~
        {                                                          //~v7ezI~
        	len=2;                                                 //~v7ezI~
        	pcchar->attr=attr & (UVIOMATTR_COLORMASK|UVIOMATTR_DBCS12);//~v7ezI~
        	(pcchar+1)->attr=attr & (UVIOMATTR_COLORMASK|UVIOMATTR_DBCS12);//~v7ezI~
        	move(Prow,col);    //mvaddchnstr miss current pos      //~v7ezI~
        }                                                          //~v7ezI~
        else                                                       //~v7ezI~
        {                                                          //~v7ezI~
        	len=1;                                                 //~v7ezI~
        	pcchar->attr=attr & (UVIOMATTR_COLORMASK|UVIOMATTR_DBCS12);//~v7ezR~
        	move(Prow,col);    //mvaddchnstr miss current pos      //~v7ezR~
	        add_wchnstr(pcchar,len);                               //~v7ezI~
        }                                                          //~v7ezI~
	    add_wchnstr(pcchar,len);                                   //~v7ezI~
        UTRACEP("%s:add_wchnstr ii=%d,col=%d,len=%d,char0=%04x,attr=%08x\n",UTT,ii,col,len,pcchar->chars[0],pcchar->attr);//~v7ezR~
    	if (attr & UVIOMATTR_DBCS1)                                //~v7ezI~
        {                                                          //~v7ezI~
        	ii++;                                                  //~v7ezI~
            pcchar++;                                              //~v7ezM~
            col++;                                                 //~v7ezM~
        }                                                          //~v7ezI~
    }                                                              //~v7ezI~
    UTRACEP("%s:rc=ctr=%d\n",UTT,ctr);                             //~v7ezI~
    return ctr;                                                    //~v7ezI~
}                                                                  //~v7ezI~
//*******************************************************          //~v5n8I~
//*uviom_mvaddwchnstr                                              //~v5n8I~
//*******************************************************          //~v5n8I~
int uviom_mvaddwchnstr(int Prow,int Pcol,cchar_t *Ppcchar,int Plen)//~v5n8R~
{                                                                  //~v5n8I~
	int rc;                                                        //~v5n8I~
//********************                                             //~v5n8I~
UTRACEP("%s:row=%d,col=%d,len=%d\n",UTT,Prow,Pcol,Plen);           //~v7ezR~
UTRACED("uviom_mvaddwchnstr add_wchnstr cchar",Ppcchar,Plen*CCHSZ);//~v7ezI~
	if (fillattrWideSbcs(0,Prow,Pcol,Ppcchar,Plen))	//detected widesbcs//~v7ezR~
    {                                                              //~v7ezI~
		UTRACEP("%s:fillWideSbcs return NONZERO row=%d,col=%d,len=%d\n",UTT,Prow,Pcol,Plen);//~v7ezI~
    	return 0;                                                  //~v7ezI~
    }                                                              //~v7ezI~
    clearAttrFlags(Ppcchar,Plen);                                  //~v7bJI~
  if (Pcol>=0)	                                                   //~v656R~
    move(Prow,Pcol);    //mvaddchnstr miss current pos             //~v5n8I~
	rc=add_wchnstr(Ppcchar,Plen);                                  //~v5n8I~
UTRACED("uviom_mvaddwchnstr add_wchnstr cchar",Ppcchar,Plen*CCHSZ);//~v7ezI~
UTRACEP("%s rc=%d\n",UTT,rc);//~v5n8I~//~v6hhR~//~v6uBR~//~v7c4R~  //~v7ezR~
	return rc;                                                     //~v5n8I~
}//uviom_mvaddwchnstr                                              //~v5n8I~
#ifdef KKK
//*******************************************************          //~v653I~
//*utf8 file output with ligature opption                          //~v653I~
//*ret  :rc                                                        //~v653I~
//*******************************************************          //~v653I~
int uvio_mvaddchnstrW_ligature(int Popt,cchar_t *Pcchar,int Pctr,int Pwidth,int Prow,int Pcol)//~v653R~
{                                                                  //~v653I~
	int rc=0,ii,swbreakch,ucsctr,strsz=0;                       //~v653R~//~v7bwR~
//  int col,chsz,attr,/*attrn,attro,*/dbcssw,dbcssz;                   //~v653R~//~v65bR~//~v6BhR~
    int col,chsz,dbcssw,dbcssz;                                    //~v6BhI~
    int ctrdbcscomb;                                               //~v7bDI~
    int swWideSbcs;	//F2C1                                         //~v7bDI~
    attr_t attr;                                                   //~v6BhI~
    int swshadow;                                                  //~v65bI~
    cchar_t *pch;                                                  //~v653I~
//  ULONG *pucs;                                                   //~v690R~
    int swpadding;                                                 //~v6V6I~
//#ifdef HHH                                                         //~v7bwI~//~v7bDR~
	int ovfctr;                                                    //~v6WbM~//~v7bwM~
    UWCHART *pucs;                                                 //~v690I~//~v7bwM~
	int jj;                                                        //~v7bwI~
//#endif                                                             //~v7bwI~//~v7bDR~
//    int swPrevWideSbcs=0;                                          //~v7bHR~//~v7bJR~
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
//      uviom_mvaddwchnstr(Prow,Pcol,Spspacelinew,Pwidth);         //~v653I~//~v6WbR~
    	uviom_spaceclear(0,Prow,Pcol,Pwidth);                      //~v6WbI~
        UTRACEP("%s:after space clear\n",UTT);                       //~v6WbR~//~v7bDR~
    }                                                              //~v653I~
//substr write                                                     //~v653I~
    col=Pcol;                                                      //~v653I~
    for (ii=0,ucsctr=0,pch=Pcchar;ii<Pctr;ii+=dbcssz,pch+=dbcssz)  //~v653R~
    {                                                              //~v653I~
        attr=pch->attr;                                            //~v65bM~
      	swbreakch=(attr & UVIOMATTR_BREAK);                        //~v653I~//~v65bR~
      	swshadow=attr & UVIOMATTR_SHADOW;                          //~v65bI~
//     	swpadding=attr & UVIOMATTR_EXT_PADDING;                    //~v6V6I~//~v6WbR~
      	swpadding=attr & UVIOMATTR_EXT_PADDING2; //ALTCH2 entry will follows//~v6WbI~
      	ctrdbcscomb=UVIOMATTR_GET_DBCSCOMBCTR(attr);               //~v7bDI~
        swWideSbcs=(attr & UVIOMATTR_EXT_WIDESBCS)!=0;// 0x800000, advance 1 col at mvadd//~v7bDR~
        UTRACEP("%s:ii=%d,col=%d,strsz=%d,swbreakch=%d,swWideSbcs=%d\n",UTT,ii,col,strsz,swbreakch,swWideSbcs);//~v7bHI~
#ifdef KKK     //keep space after widesbcs even if lig on                           //~v7bJI~//~v7bPR~
        UTRACEP("%s:prev widesbcs=%d,ucs=0x%04x\n",UTT,swPrevWideSbcs,pch->chars[0]);//~v7bNI~
        if (swPrevWideSbcs) //break after wide sbcs when ligature off( uvio_mvaddchnstrW_combine is called when Lig:off)//~v7bHI~
        {                                                          //~v7bHI~
        	if (attr & UVIOMATTR_EXT_SCM)	//SCM has no space between prev WideSBCS//~v7bHI~
            {                                                      //~v7bHI~
            	UTRACEP("%s:prev widesbcs and cur SCM,ucs=0x%04x\n",UTT,pch->chars[0]);//~v7bHI~
            }                                                      //~v7bHI~
            else                                                   //~v7bHI~
            {                                                      //~v7bHI~
            	swbreakch=1;                                       //~v7bHR~
            	UTRACEP("%s:prev widesbcs and cur Not SCM,set break,ucs=0x%04x\n",UTT,pch->chars[0]);//~v7bHI~
            }                                                      //~v7bHI~
        }                                                          //~v7bHI~
        swPrevWideSbcs=swWideSbcs;                                 //~v7bHI~
#endif                                                             //~v7bJI~//~v7bPR~
//     	attr&=(attr_t)(~UVIOMATTR_EXT_PADDING);                    //~v6V6R~//~v6WbR~
//    if (swpadding)                                               //~v6V6I~//~v6WbR~
//      chsz=1;                                                    //~v6V6I~//~v6WbR~
//    else                                                         //~v6V6I~//~v6WbR~
      if (swshadow)                                                //~v65bI~//~v6WbR~
      {                                                            //~v7bsI~
        chsz=1;                                                    //~v65bI~//~v6WbR~//~v7bJR~
		UTRACEP("%s:shadow chsz=%d,swWideSbcs=%d,ucs=0x%04x\n",UTT,chsz,swWideSbcs,pch->chars[0]);//~v7bsI~//~v7bJR~
	  }	                                                           //~v7bsI~
      else                                                         //~v65bI~
      {                                                            //~v65bI~
//#ifdef HHH                                                         //~v7bwI~//~v7bDR~
//  	pucs=(ULONG*)(pch->chars+1);                               //~v690R~
    	pucs=(UWCHART*)(pch->chars+1);                             //~v690I~
		ovfctr=0;                                                  //~v6WbI~
    	for (jj=0;jj<UVIOM_MAXCOMBINE;jj++)                        //~v653I~
        {                                                          //~v6WbI~
        	if (!(*pucs++))                                        //~v653I~
            	break;                                             //~v653I~
			if (UTF22_ISOVFUCS(*(pucs-1)))                         //~v6WbI~
				ovfctr++;                                          //~v6WbM~
#ifdef FFF                                                         //~v6X5I~
#else                                                              //~v6X5I~
            else                                                   //~v6X5I~
			if (mk_wcwidth_combining2SCM(0,*(pucs-1)))             //~v6X5I~
				ovfctr++;                                          //~v6X5I~
#endif                                                             //~v6X5I~
        }                                                          //~v6WbI~
        chsz=1+jj;                                                 //~v653I~
#ifdef UUU                                                         //~v6W5M~
#else                                                              //~v6W5M~
    	if (jj)                                                    //~v6W5M~
        {                                                          //~v6WbI~
//          if (!swpadding)                                        //~v6W5M~//~v6WbR~
//          if (swshadow|| (attr & UVIOMATTR_EXT_DMYBASE))         //~v6WbR~
//  	    	chsz--; //of A0 entry                              //~v6W5M~//~v6WbR~
            if (attr & UVIOMATTR_EXT_DMYBASE) //ITSELF entry       //~v6WbI~
            {                                                      //~v6WbI~
                chsz--; //of a0 entry                              //~v6WbI~
                chsz+=ovfctr; //2 cell for ovf                     //~v6WbI~
              	if (swpadding) //ALTCH2 folows                     //~v6WbI~
	                chsz--;  //of ALTCH2                           //~v6WbI~
            }                                                      //~v6WbI~
            chsz+=ctrdbcscomb;                                     //~v7bDR~
        }                                                          //~v6WbI~
#endif                                                             //~v6W5M~
//#else                                                              //~v7bwI~//~v7bDR~
//        chsz=1;                                                    //~v7bwI~//~v7bDR~
//#endif                                                             //~v7bwI~//~v7bDR~
      }                                                            //~v65bI~
    	dbcssw=(attr & UVIOMATTR_DBCS1)!=0;                        //~v653I~
        dbcssz=1+dbcssw;                                           //~v653I~
        chsz+=dbcssw;                                              //~v653I~
        chsz+=swWideSbcs;                                          //~v7bDI~
      	UTRACEP("%s:ii=%d,col=%d,swbreak=%d,chsz=%d,dbcssw=%d,ucs=%04x,attr=%x,swpadding=%d,swshadow=%d,swWideSbcs=%d\n",UTT,ii,col,swbreakch,chsz,dbcssw,pch->chars[0],attr,swpadding,swshadow,swWideSbcs);//~v6WbM~//~v6X5R~//~v7bwR~//~v7bDR~//~v7bJR~
//      attr &= ~UVIOMATTR_BREAK;                                  //~v653I~//~v65bR~
//      attr &= ~(UVIOMATTR_BREAK|UVIOMATTR_SHADOW);               //~v65bI~//~v6BhR~
//      attr &= (attr_t)(~(UVIOMATTR_BREAK|UVIOMATTR_SHADOW));     //~v6BhI~//~v6WbR~
//      pch->attr=attr;                                            //~v653I~//~v6WbR~
//      attrn=attr&~UVIOMATTR_DBCS12;                              //~v653R~//~v65bR~
        UTRACEP("%s:ii=%d,ucs=%x,swbreak=%d,chsz=%d\n",UTT,ii,pch->chars[0],swbreakch,chsz);//~v653I~//~v65bR~//~v7bJR~
        if (swbreakch                                              //~v653I~
//      ||  (ucsctr && attrn!=attro)                               //~v653I~//~v658R~
//      ||  (ii && attrn!=attro)                                   //~v658I~//~v65bR~
        )                                                          //~v653I~
        {                                                          //~v653I~
            if (ucsctr)                                            //~v653I~
            {                                                      //~v653I~
                UTRACEP("%s:ligature substr ucsctr=%d,col=%d,strsz=%d\n",UTT,ucsctr,col,strsz);//~v653I~//~v7bDR~
				uviom_mvaddwchnstr(Prow,col,pch-ucsctr,ucsctr);    //~v653R~
//	            if (strsz>ucsctr)                                  //~v6D9I~//~v6WbR~
//        	        uviom_fillattrspace(0,Prow,col+ucsctr,attr&UVIOMATTR_CURSESMASK,strsz-ucsctr);	//fill space shrinked by ligature//~v6D9I~//~v6WbR~
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
#endif //KKK                                                       //~v7bJR~
//*******************************************************          //~v7bPI~
//*keep space after widesbcs                                       //~v7bPI~
//*******************************************************          //~v7bPI~
void mvadd_WideSbcsString(int Popt,int Prow,int Pcol,PCCH Pcchs,int Pctr)//~v7bPR~
{                                                                  //~v7bPI~
	int ii,col,strctr=0;                                           //~v7bPI~
    CCH *pcch,*pcchs=0;                                            //~v7bPR~
    UTRACEP("%s:row=%d,col=%d,ctr=%d\n",UTT,Prow,Pcol,Pctr);       //~v7bPR~
    UTRACED("Pcchar",Pcchs,Pctr*CCHSZ);                            //~v7bPI~
    for (ii=0,col=Pcol,pcch=Pcchs;ii<Pctr;ii++,pcch++)             //~v7bPR~
    {                                                              //~v7bPI~
    	attr_t attr=pcch->attr;                                    //~v7bPI~
	    UTRACEP("%s:ii=%d,col=%d,strctr=%d,ucs=0x%04x,attr=0x%04x\n",UTT,ii,col,strctr,pcch->chars[0],pcch->attr);//~v7bPI~
        if (attr & UVIOMATTR_EXT_WIDESBCS                          //~v7bPR~
        &&  attr & UVIOMATTR_EXT_COMBBASE                          //~v7bPI~
		&&  !(attr & UVIOMATTR_EXT_SCMBASE)                        //~v7bPI~
        )                                                          //~v7bPI~
        {                                                          //~v7bPI~
        	if (pcchs)                                             //~v7bPI~
            {                                                      //~v7bPI~
				uviom_mvaddwchnstr(Prow,col,pcchs,strctr);         //~v7bPI~
                col+=strctr;                                       //~v7bPR~
                pcchs=0;                                           //~v7bPR~
                strctr=0;                                          //~v7bPI~
            }                                                      //~v7bPI~
			uviom_mvaddwchnstr(Prow,col,pcch,1);                   //~v7bPI~
            col+=2;                                                //~v7bPI~
        }                                                          //~v7bPI~
        else                                                       //~v7bPI~
        {                                                          //~v7bPI~
            if (!pcchs)                                            //~v7bPI~
            	pcchs=pcch;                                        //~v7bPI~
            strctr++;                                              //~v7bPI~
        }                                                          //~v7bPI~
    }                                                              //~v7bPI~
    if (pcchs)                                                     //~v7bPI~
    {                                                              //~v7bPI~
        uviom_mvaddwchnstr(Prow,col,pcchs,strctr);                 //~v7bPI~
    }                                                              //~v7bPI~
}                                                                  //~v7bPI~
//*******************************************************          //~v653I~
//*utf8 file output with ligature opption                          //~v653I~
//*ret  :rc                                                        //~v653I~
//*******************************************************          //~v653I~
int uvio_mvaddchnstrW_ligature(int Popt,cchar_t *Pcchar,int Pctr,int Pwidth,int Prow,int Pcol)//~v653R~
{                                                                  //~v653I~
	int rc=0,ii,swbreakch,ucsctr=0,strsz=0;                       //~v653R~//~v7bwR~//~v7bJR~
    int col,chsz,dbcssw;                                    //~v6BhI~//~v7bJR~
    int swWideSbcs;	//F2C1                                         //~v7bDI~
    attr_t attr;                                                   //~v6BhI~
    cchar_t *pch,*pche;                                            //~v653I~//~v7bJR~
//    int swPrevWideSbcs=0;                                        //~v7bPR~
    int swWideSbcsString=0;                                        //~v7bPI~
//**********************                                           //~v653I~
//*clear line                                                      //~v653I~
    UTRACEP("%s:opt=%x,ctr=%d,len=%d,row=%d,col=%d\n",UTT,Popt,Pctr,Pwidth,Prow,Pcol);//~v653I~//~v6hhR~//~v6D9R~
    UTRACED("Pcchar",Pcchar,Pctr*(int)sizeof(cchar_t));            //~v6D9R~
    uviom_spaceclear(0,Prow,Pcol,Pwidth);                      //~v6WbI~//~v7bJR~
    UTRACEP("%s:after space clear\n",UTT);                       //~v6WbR~//~v7bDR~//~v7bJR~
//substr write                                                     //~v653I~
    col=Pcol;                                                      //~v653I~
    pche=Pcchar+Pctr;                                              //~v7bJI~
    for (ii=0,pch=Pcchar;ii<Pctr;ii+=chsz,pch+=chsz)  //~v653R~    //~v7bJR~
    {                                                              //~v653I~
        attr=pch->attr;                                            //~v65bM~
      if (ii==SwidthLineno)                             //~v7bXI~//~v7bYR~//~v7bWR~
        swbreakch=1;                                               //~v7bXI~
      else                                                         //~v7bXI~
      	swbreakch=(attr & UVIOMATTR_BREAK);                        //~v653I~//~v65bR~
        swWideSbcs=(attr & UVIOMATTR_EXT_WIDESBCS)!=0;// 0x800000, advance 1 col at mvadd//~v7bJI~
        UTRACEP("%s:ii=%d,col=%d,ucs=0x%04x,attr=0x%04x,chsz=%d,strsz=%d,ucsctr=%d,swbreakch=%d,swWideSbcs=%d\n",UTT,ii,col,pch->chars[0],attr,chsz,strsz,ucsctr,swbreakch,swWideSbcs);//~v7bJR~//~v7bPR~
//        if (swPrevWideSbcs) //break after wide sbcs when ligature off( uvio_mvaddchnstrW_combine is called when Lig:off)//~v7bPR~
//        {                                                        //~v7bPR~
//            if (attr & UVIOMATTR_EXT_SCM)   //SCM has no space between prev WideSBCS//~v7bPR~
//            {                                                    //~v7bPR~
//                UTRACEP("%s:prev widesbcs and cur SCM,ucs=0x%04x\n",UTT,pch->chars[0]);//~v7bPR~
//            }                                                    //~v7bPR~
//            else                                                 //~v7bPR~
//            {                                                    //~v7bPR~
//                swbreakch=1;                                     //~v7bPR~
//                UTRACEP("%s:prev widesbcs and cur Not SCM,set break,ucs=0x%04x\n",UTT,pch->chars[0]);//~v7bPR~
//            }                                                    //~v7bPR~
//        }                                                        //~v7bPR~
//        swPrevWideSbcs=swWideSbcs;                               //~v7bPR~
        if (swbreakch)                                             //~v7bJI~
        {                                                          //~v7bJI~
        	if (ucsctr)                                            //~v7bJI~
            {                                                      //~v7bJI~
        		UTRACED("write by break",pch-ucsctr,ucsctr*CCHSZ); //~v7bJI~
              if (swWideSbcsString)                                //~v7bPI~
				mvadd_WideSbcsString(0,Prow,col,pch-ucsctr,ucsctr);//~v7bPI~
              else                                                 //~v7bPI~
				uviom_mvaddwchnstr(Prow,col,pch-ucsctr,ucsctr);    //~v7bJI~
                ucsctr=0;                                          //~v7bJI~
                col+=strsz;                                        //~v7bJI~
                strsz=0;                                           //~v7bJI~
                swWideSbcsString=0;                                //~v7bPI~
            }                                                      //~v7bJI~
        }                                                          //~v7bJI~
        int ctrString,szString;                                    //~v7bJR~
        int szComb,swWideSbcsCombBase;                             //~v7bPI~
//      int rc2=getCombinedSize(0,pch,pche,&ctrString,&szString);  //~v7bJR~//~v7bPR~
        int rc2=getCombinedSize(0,pch,pche,&ctrString,&szString,&szComb,&swWideSbcsCombBase);//~v7bPI~
        if (rc2)	//combined or SCMcombined                      //~v7bJI~
        {                                                          //~v7bJI~
		    UTRACEP("%s:comb or SCM swbreakch=%d,swWideSbcsCombbase=%d\n",UTT,swbreakch,swWideSbcsCombBase);//~v7bPI~
        	if (swWideSbcsCombBase)                                //~v7bPI~
            	swWideSbcsString=1;                                //~v7bPI~
//            if (!swbreakch && swWideSbcsCombBase)   //WideSbcs is not SCM base//~v7bPR~
//            {                                                    //~v7bPR~
//#ifdef AAA                                                       //~v7bPR~
//                if (ucsctr)   //write pending                    //~v7bPR~
//                {                                                //~v7bPR~
//                    UTRACED("write by wideSBCS",pch-ucsctr,ucsctr*CCHSZ);//~v7bPR~
//                    uviom_mvaddwchnstr(Prow,col,pch-ucsctr,ucsctr);//~v7bPR~
//                    ucsctr=0;                                    //~v7bPR~
//                    col+=strsz;                                  //~v7bPR~
//                    strsz=0;                                     //~v7bPR~
//                }                                                //~v7bPR~
//                uviom_mvaddwchnstr(Prow,col,pch,1); //write widesbcs combinedBase//~v7bPR~
//                ctrString--;                                     //~v7bPR~
//                szString-=szComb;                                //~v7bPR~
//                col+=szComb;                                     //~v7bPR~
//                ii++;                                            //~v7bPR~
//                pch++;                                           //~v7bPR~
//#else                                                            //~v7bPR~
//                uviom_mvaddwchnstr(Prow,col,pch-ucsctr,ucsctr+1);//~v7bPR~
//                col+=strsz+szComb;                               //~v7bPR~
//                ucsctr=0;                                        //~v7bPR~
//                strsz=0;                                         //~v7bPR~
//                chsz=1; //ii & pch                               //~v7bPR~
//                continue;                                        //~v7bPR~
//#endif                                                           //~v7bPR~
//            }                                                    //~v7bPR~
            ucsctr+=ctrString;                                     //~v7bJI~//~v7bPR~
            strsz+=szString;                                       //~v7bJR~//~v7bPR~
            chsz=ctrString; //ii and pch                           //~v7bJI~//~v7bPR~
            UTRACEP("%s:combined(SCM),ii=%d,col=%d,combined ucsctr=%d,chsz=%d\n",UTT,ii,col,ucsctr,chsz);//~v7bJR~//~v7bPR~
        }                                                          //~v7bJI~//~v7bPR~
        else                                                       //~v7bJI~//~v7bPR~
        {                                                          //~v7bJI~//~v7bPR~
        	//ii+=chsz,pcc+=chsz;                                  //~v7bJI~
    		dbcssw=(attr & UVIOMATTR_DBCS1)!=0;                    //~v7bJI~
            chsz=1+dbcssw+swWideSbcs;                              //~v7bJI~
            strsz+=chsz;	//col advance                          //~v7bJR~
            ucsctr+=1+dbcssw;                                      //~v7bJI~
            pch+=-chsz+1+dbcssw;                                   //~v7bJR~
        }                                                          //~v7bJI~//~v7bPR~
    }                                                              //~v653I~
    if (ucsctr)                                                    //~v653I~
    {                                                              //~v653I~
      if (swWideSbcsString)                                        //~v7bPI~
		mvadd_WideSbcsString(0,Prow,col,pch-ucsctr,ucsctr);        //~v7bPI~
      else                                                         //~v7bPI~
		uviom_mvaddwchnstr(Prow,col,pch-ucsctr,ucsctr);            //~v653R~
        UTRACED("ligature substr last",pch-ucsctr,ucsctr*(int)sizeof(cchar_t));//~v653R~//~v6BhR~
    }                                                              //~v653I~
	if (!UVIOM_NONSPACECOMBINEMODE()) //non spacing combining diacritical mark supported//~v656I~
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
    int rc=0,/*ch,*/ii,ccharlen,poss=0,pos;                              //~v656R~//~v6b9R~//~v6h9R~//~v7bER~
    int dbcssw;                                                    //~v656I~
    int /*paddingsw,*/breaksw;                                         //~v656I~//~v6b9R~
    cchar_t *pcchar,*pcchars;                                      //~v656I~
//  cchar_t *pchtw;                                                //~v656R~//~v7bJR~
    int combinectr,substrctr=0;                                    //~v656R~
//  int combinectrucs4;                                            //~v6V5I~//~v7bJR~
    int swcombbase/*,swa0*/;                                           //~v6W5R~//~v7bJR~
//  cchar_t *pccharbase;                                           //~v6W5R~//~v7bJR~
    int swshadow;                                                  //~v6W5R~
//  int swextpadding2;                                             //~v6W7I~//~v7bGR~
    int swWideSbcs;	//F2C1                                         //~v7bFI~
    int swSCMBase,swPrevWideSbcs=0,swSCM,combineSCMcol;            //~v7bER~//~v7bJR~
//************************                                         //~v656I~
//  UTRACEP("mvaddchnstrW_combine row=%d,ctr=%d,width=%d\n",Prow,Pctr,Pwidth);//~v656R~//~v6hhR~
//  uviom_mvaddwchnstr(Prow,Pcol,Spspacelinew,Pwidth);             //~v656I~//~v6W6R~
//  UTRACED("combinemode space clear",Spspacelinew,Pwidth*(int)sizeof(cchar_t));//~v656I~//~v6BhR~//~v6W6R~
    uviom_spaceclear(0,Prow,Pcol,Pwidth);                          //~v6W6R~
    UTRACED("Pcchar",Pcchar,Pctr*(int)sizeof(cchar_t));            //~v6EmI~
    for (pcchars=0,pcchar=Spwkcchar,pos=Pcol,ii=0;                 //~v656I~
			ii<Pctr;                                               //~v656R~
			ii+=ccharlen,pos+=ccharlen,pcchar+=ccharlen)           //~v656I~
    {                                                              //~v656I~
        UTRACEP("%s:ii=%d,col=%d,ucs=0x%04x,ccharlen=%d,attr=0x%04x\n",UTT,ii,pos,pcchar->chars[0],ccharlen,pcchar->attr);//~v7bEI~//~v7bJR~
//      ch=pcchar->chars[0];                                       //~v656I~//~v6b9R~
        ccharlen=1;                                                //~v656I~
//      paddingsw=0;                                               //~v656I~//~v6b9R~
        breaksw=0;                                                 //~v656I~
      	if (ii==SwidthLineno)                           //~v7bXR~//~v7bYR~//~v7bWR~
        	breaksw=1;                                             //~v7bXI~
        combineSCMcol=0;                                           //~v7bEI~
		swshadow=0;                                                //~v6W5I~
    	swcombbase=(pcchar->attr & UVIOMATTR_EXT_COMBBASE);   //ligature:off,combinemode,combin base//~v6W5I~//~v7bJR~
    	swSCM=0;                                                   //~v7bEI~//~v7bJR~
        pcchar->attr &= (attr_t)(~UVIOMATTR_EXT_PADDCOMB);         //~v7bJI~
        if (pcchar->attr & 	UVIOMATTR_EXT_SCM)    //shadow padding for overflowcombining//~v7bEI~
        {                                                          //~v7bEI~
        	pcchar->attr &= (attr_t)(~UVIOMATTR_EXT_SCM); //0x01000000     //scm comining//~v7bER~
            swSCM=1;                                               //~v7bEI~//~v7bJR~
        }                                                          //~v7bEI~
        swSCMBase=0;                                               //~v7bEI~
        if (pcchar->attr & 	UVIOMATTR_EXT_SCMBASE)    //shadow padding for overflowcombining//~v7bEI~
        {                                                          //~v7bEI~
    	    swSCMBase=1;                                           //~v7bEI~
            pcchar->attr &= (attr_t)(~UVIOMATTR_EXT_SCMBASE);      //~v7bEI~
        }                                                          //~v7bEI~
        if (swSCMBase)                                             //~v7bEI~
            breaksw=1;                                             //~v7bEM~
        swWideSbcs=0;                                              //~v7bFI~
        if (pcchar->attr & 	UVIOMATTR_EXT_WIDESBCS)    //shadow padding for overflowcombining//~v7bFI~
        {                                                          //~v7bFI~
    	    swWideSbcs=1;                                          //~v7bFI~
//          pcchar->attr &= (attr_t)(~UVIOMATTR_EXT_WIDESBCS);     //~v7bFI~//~v7ezR~
        }                                                          //~v7bFI~
//#ifdef KKK                                                       //~v7bJI~
//          	UTRACEP("%s:prev widesbcs and cur SCM,ucs=0x%04x\n",UTT,pcchar->chars[0]);//~v7bNI~//~v7emR~
        if (swPrevWideSbcs) //break after wide sbcs when ligature off( uvio_mvaddchnstrW_combine is called when Lig:off)//~v7bEI~
        {                                                          //~v7bEI~
            if (swSCM)                                             //~v7bEI~
            {                                                      //~v7bEI~
            	UTRACEP("%s:prev widesbcs and cur SCM,ucs=0x%04x\n",UTT,pcchar->chars[0]);//~v7bER~
            }                                                      //~v7bEI~
            else                                                   //~v7bEI~
            {                                                      //~v7bEI~
            	breaksw=1;                                         //~v7bEI~
            	UTRACEP("%s:prev widesbcs and cur Not SCM,set break,ucs=0x%04x\n",UTT,pcchar->chars[0]);//~v7bER~
            }                                                      //~v7bEI~
        }                                                          //~v7bEI~
        swPrevWideSbcs=swWideSbcs;                                 //~v7bEI~
//#endif //KKK                                                     //~v7bJR~
//      swextpadding2=0;                                           //~v6W7I~//~v7bGR~
        if (pcchar->attr & 	UVIOMATTR_EXT_PADDING2)    //shadow padding for overflowcombining//~v6W7I~
        {                                                          //~v6W7I~
//      	swextpadding2=1;                                       //~v6W7I~//~v7bGR~
            pcchar->attr &= (attr_t)(~UVIOMATTR_EXT_PADDING2);     //~v6W7I~
        }                                                          //~v6W7I~
        if (pcchar->attr & UVIOMATTR_SHADOW)                       //~v65bI~
        {                                                          //~v65bI~
            pcchar->attr &= (attr_t)(~UVIOMATTR_SHADOW);                     //~v65bI~//~v6BhR~
            breaksw=1;                                             //~v65bI~
			swshadow=1;                                            //~v6W5I~
            pcchar->attr &= (attr_t)(~UVIOMATTR_PADDING);          //~v6WaI~
        }                                                          //~v65bI~
//      paddingsw=(pcchar->attr & UVIOMATTR_PADDING);              //~v656R~//~v658R~
        if (pcchar->attr & UVIOMATTR_BREAK)                        //~v656R~
        {                                                          //~v656R~
//          pcchar->attr &= ~UVIOMATTR_BREAK;                      //~v656R~//~v6BhR~
            pcchar->attr &= (attr_t)(~UVIOMATTR_BREAK);            //~v6BhI~
            breaksw=1;                                             //~v656R~
        }                                                          //~v656R~
        else                                                       //~v656I~
		if (swcombbase)    //ligature:off,combinemode,combin base  //~v6W5R~
        {                                                          //~v6W5I~
			pcchar->attr &= (attr_t)(~UVIOMATTR_EXT_COMBBASE);   //ligature:off,combinemode,combin base//~v6W5R~
            breaksw=1;                                             //~v6W5I~
        }                                                          //~v6W5I~
        if (!breaksw)                                              //~v656R~
        {                                                          //~v656M~
        	if (!pcchars)   	//1st ascii                        //~v656M~
            {                                                      //~v656M~
            	pcchars=pcchar;                                    //~v656M~
                poss=pos;	//ascii start col                      //~v656M~
            }                                                      //~v656M~
            substrctr++;                                           //~v656I~
            if (swWideSbcs)                                        //~v7bEI~
            {                                                      //~v7bEI~
         		ccharlen=2;                                        //~v7bEI~
                pcchar--;	                                       //~v7bEI~
            }                                                      //~v7bEI~
            UTRACEP("%s:Not Break,swWideSbcs=%d,pos=%d,poss=%d,ccharlen=%d,substrctr=%d,ucs=0x%04x\n",UTT,swWideSbcs,pos,poss,ccharlen,substrctr,pcchar->chars[0]);//~v7bER~
        }                                                          //~v656M~
        else                                                       //~v656M~
        {                                                          //~v656I~
        	if (pcchars)//preceding asccii string                  //~v656I~
            {                                                      //~v656I~
				uviom_mvaddwchnstr(Prow,poss,pcchars,substrctr);   //~v656R~
	UTRACEP("%s:sbcs row=%d,colstart=%d,substrctr=%d\n",UTT,Prow,poss,substrctr);    //~v656R~//~v7bER~
    			pcchars=0;                                         //~v656I~
                substrctr=0;                                       //~v656I~
            }                                                      //~v656I~
         if (swshadow)	//split shadow                             //~v6W5R~
         {                                                         //~v6W5I~
//        if (!swextpadding2)                                      //~v7bsR~
          if (!(pcchar->attr & UVIOMATTR_DBCS1))//      0x01         //1:dbcs1st,2:DBCS2ND//~v7bsI~
          {                                                        //~v7brM~
         	ccharlen=1;                                            //~v7brM~
          }                                                        //~v7brM~
          else                                                     //~v7brM~
          {                                                        //~v7brM~
         	ccharlen=2;                                            //~v7brM~
          }                                                        //~v7brM~
			UTRACEP("%s:shadow ccharlen=%d,pos=%d\n",UTT,ccharlen,pos);//~v7brM~//~v7bGR~
         	uviom_mvaddwchnstr(Prow,pos,pcchar,ccharlen);          //~v7brM~
            if (swWideSbcs)                                        //~v7bEI~
            {                                                      //~v7bEI~
//          	pos++;                                             //~v7bEI~//~v7bJR~
            	ccharlen++;                                        //~v7bJR~
            	pcchar--;   //1 cchar entry for widesbcs           //~v7bJI~
				UTRACEP("%s:shadow widesbcs pos=%d\n",UTT,pos);    //~v7bEI~
            }                                                      //~v7bEI~
         }                                                         //~v6W5I~
         else                                                      //~v6W5I~
         {                                                         //~v6W5I~
//      UTRACEP("paddingsw=%d ch=%04x\n",paddingsw,ch);            //~v656I~//~v6b9R~
//        if (!(paddingsw && ch==Guviomdbcspad)) //write width0 when not combining(start from width0)//~v656I~//~v658R~
//        {                                                        //~v656I~//~v658R~
//        	if (paddingsw)                                         //~v656I~//~v658R~
//             pcchar->attr &= ~UVIOMATTR_PADDING;	//start from width0//~v656I~//~v658R~
//      	dbcssw=(pcchar->attr & 0x01);	//dbcs 1st             //~v656I~//~v6W9R~
        	dbcssw=(pcchar->attr & UVIOMATTR_DBCS1);//      0x01         //1:dbcs1st,2:DBCS2ND//~v6W9I~
            ccharlen+=dbcssw;                                      //~v656I~
	        ccharlen+=swWideSbcs;                                  //~v7bFI~
    		UTRACEP("%s:ucs=0x%04x,dbcssw=%d,swWideSbcs=%d,wcwidth=%d\n",UTT,pcchar->chars[0],dbcssw,swWideSbcs,wcwidth((wchar_t)pcchar->chars[0]));//~v656I~//~v6V6R~//~v7bFR~//~v7bER~
            combinectr=0;                                          //~v656I~
//          combinectrucs4=0;                                      //~v6V5I~//~v7bJR~
//			swa0=0;                                                //~v6W5I~//~v7bJR~
        	if (swSCMBase)                                         //~v7bEI~
            {                                                      //~v7bEI~
//          	pchtw=pcchar+1;                                    //~v7bEI~//~v7bJR~
				combinectr=getCombineCtrSCM(0,pcchar+1,ii+1,Pctr,&combineSCMcol);//~v7bER~
            }//swSCMBase                                           //~v7bEI~
#ifdef KKK                                                         //~v7bJI~
            else                                                   //~v7bEI~
			if  (swcombbase)    //ligature:off,combinemode,combin base//~v6W5I~
            {                                                      //~v7bJI~
//              if (UVIOM_COMBINEMODE())//combine mode or fc5      //~v656R~//~v658R~
                {                                                  //~v656I~
                    pchtw=pcchar+1;                                //~v656I~
//                  if (pcchar->attr & 0x01)  //dbcs               //~v656I~//~v6W9R~
                    if (dbcssw)                                    //~v6W9I~
                        pchtw++;                                   //~v656I~
					pccharbase=pcchar;                             //~v6W5I~
                    pcchar=pchtw;   //base="A0"                    //~v6W5I~
                  if (!dbcssw)  //no a0 entry for dbcs base        //~v6W9I~
                    pchtw++;		//padding start after A0       //~v6W5I~
                  if (dbcssw)   //no a0 entry;dbcs1+dbcs2+padding  //~v6W9I~
                  {                                                //~v6W9I~
                    for (combinectr=0;combinectr<UVIOM_MAXCOMBINE;combinectr++,pchtw++)//~v6W9I~
                    {                                              //~v6W9I~
                        if (!pccharbase->chars[1+combinectr]) //nomore combining//~v6W9I~
                            break;                                 //~v6W9I~
						if (UVIOM_NONSPACECOMBINEMODE()) //non spacing combining diacritical mark supported//~v6W9I~
                        {                                          //~v6W9I~
                        	if (!(pchtw->attr & UVIOMATTR_PADDING)) //not combine padding set at setcombine;may be for gb4//~v6W9I~
                            	break;                             //~v6W9I~
                        	pchtw->attr &= (attr_t)(~UVIOMATTR_PADDING);  //write width combine char//~v6W9I~
                        	if (pchtw->attr & UVIOMATTR_PADDING2) //ucs4 width0//~v6W9I~
                            {                                      //~v6W9I~
	                        	pchtw->attr &= (attr_t)(~UVIOMATTR_PADDING2);  //write width combine char//~v6W9I~
                                pchtw++;                           //~v6W9I~
	                        	pchtw->attr &= (attr_t)(~(UVIOMATTR_PADDING|UVIOMATTR_PADDING2));  //write width combine char//~v6W9I~
			                    combinectrucs4++;                  //~v6W9I~
                            }                                      //~v6W9I~
                        }                                          //~v6W9I~
                    }                                              //~v6W9I~
                  }                                                //~v6W9I~
                  else                                             //~v6W9I~
                  {                                                //~v6W9I~
                  //base sbcs                                      //~v7bEI~
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
                        	if (pchtw->attr & UVIOMATTR_PADDING2) //ucs4 width0//~v6V5I~
                            {                                      //~v6V5I~
	                        	pchtw->attr &= (attr_t)(~UVIOMATTR_PADDING2);  //write width combine char//~v6V5I~
                                pchtw++;                           //~v6V5I~
	                        	pchtw->attr &= (attr_t)(~(UVIOMATTR_PADDING|UVIOMATTR_PADDING2));  //write width combine char//~v6V5I~
			                    combinectrucs4++;                  //~v6V5I~
                            }                                      //~v6V5I~
                        }                                          //~v656I~
                    }                                              //~v656I~
                  }                                                //~v6W9I~
					pcchar=pccharbase;                             //~v6W5I~
                  if (!dbcssw)   //no a0 entry;dbcs1+dbcs2+padding //~v6W9I~
                    swa0=1;	                                       //~v6W5I~
                //*swcombbase                                      //~v7bEI~
                }                                                  //~v656I~
            }//swcombbase                                          //~v7bJI~
#endif //KKK                                                       //~v7bJI~
			UTRACEP("%s:nonascii ucs=0x%04x,row=%d,col=%d,len=%d,dbcssw=%d,combinectr=%d\n",UTT,pcchar->chars[0],Prow,pos,ccharlen,dbcssw,combinectr);//~v656I~//~v7bvR~//~v7bER~
		  	if (UVIOM_NONSPACECOMBINEMODE()) //non spacing combining diacritical mark supported//~v656R~
          	{                                                      //~v656R~
	          if (swSCMBase)                                       //~v7bEI~
              {                                                    //~v7bEM~
            	uviom_mvaddwchnstr(Prow,pos,pcchar,ccharlen-swWideSbcs+combinectr);//~v7bER~
                ccharlen+=combineSCMcol;                           //~v7bEI~
                ii-=ccharlen;                                      //~v7bEI~
                ii+=1+combinectr;                                  //~v7bEI~
                pcchar-=ccharlen;                                  //~v7bER~
                pcchar+=1+combinectr;                              //~v7bEI~
//              pos-=ccharlen;                                     //~v7bEI~//~v7bJR~
//              pos+=1+swWideSbcs;                                 //~v7bEI~//~v7bJR~
				UTRACEP("%s:SCMBase out ccharlen=%d, wideSbcs ucs-0x%04x\n",UTT,ccharlen,pcchar->chars[0]);//~v7bER~//~v7bJR~
              }                                                    //~v7bEM~
              else                                                 //~v7bEM~
              {                                                    //~v7bEI~
#ifdef KKK                                                         //~v7bJI~
            	combinectr+=combinectrucs4;                        //~v6V5I~
            	combinectr+=swa0;                                  //~v6W5I~
//            	uviom_mvaddwchnstr(Prow,pos,pcchar,ccharlen+combinectr);//~v656R~//~v7bER~
              	uviom_mvaddwchnstr(Prow,pos,pcchar,ccharlen+combinectr-swWideSbcs);//~v7bEI~
            	pos-=swa0;                                         //~v6W5R~
            	ccharlen+=combinectr;                              //~v656R~
                pcchar-=swWideSbcs;                                //~v7bEI~
#else  //!KKK                                                      //~v7bJI~
              	uviom_mvaddwchnstr(Prow,pos,pcchar,1+dbcssw);      //~v7bJI~
                pcchar-=swWideSbcs;                                //~v7bJI~
#endif                                                             //~v7bJI~
				UTRACEP("%s:widesbcs out swWideSbcs=%d,ccharlen=%d dbcssw=%d,ucs-0x%04x\n",UTT,swWideSbcs,ccharlen,dbcssw,pcchar->chars[0]);//~v7bEI~//~v7bJR~
              }                                                    //~v7bEI~
          	}                                                      //~v656R~
          	else                                                   //~v656R~
          	{                                                      //~v656R~
            	uviom_mvaddwchnstr(Prow,pos,pcchar,ccharlen);      //~v656R~
                uviol_refresh();                                   //~v656R~
              	pos+=combinectr;    //advance step                 //~v656R~
          	}                                                      //~v656R~
//        }//not padding char                                      //~v656I~//~v658R~
         }//!shadowsw                                              //~v6W5I~
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
    int swWideSbcs;                                                //~v7bEI~
//************************                                         //~v5n8I~
    UTRACEP("uvio_mvaddchnstrW opt=%x,len=%d,row=%d,col=%d\n",Popt,Plen,Prow,Pcol);//~v5n8I~//~v6hhR~//~v7c2R~
    UTRACED("chtype",Ppcht,Plen*CCTSZ);                            //~v5n8R~//~v6hhR~//~v7c2R~
//    UTRACED("dbcs",Ppdbcs,Plen);                                   //~v5n8I~//~v6hhR~
    linewidth=min(Plen,Sscrwidth);                                 //~v5n8I~
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
            uviom_spaceclear(0,Prow,Pcol,linewidth);               //~v6W6I~
        }                                                          //~v5n8I~
    }                                                              //~v5n8I~
    UTRACEP("cusrseW write row=%d\n",Prow);                        //~v656I~
    for (pcchars=0,pcchar=Spwkcchar,pos=Pcol,ii=0;                 //~v5n8I~
			ii<linewidth;                                          //~v5n8I~
			ii+=ccharlen,pos+=ccharlen,pcchar+=ccharlen)           //~v5n8I~
    {                                                              //~v5n8I~
    	swWideSbcs=0;                                              //~v7bEI~
    	if (pcchar->attr & UVIOMATTR_EXT_WIDESBCS)// 0x800000, advance 1 col at mvadd//~v7bEI~
        {                                                          //~v7bEI~
//      	pcchar->attr &=(attr_t)(~UVIOMATTR_EXT_WIDESBCS);// 0x800000, advance 1 col at mvadd//~v7bER~//~v7ezR~
        	swWideSbcs=1;                                          //~v7bEI~
        }                                                          //~v7bEI~
        ch=pcchar->chars[0];                                       //~v5n8I~
        UTRACEP("%s:ii=%d,pos=%d,ucs=0x%04x,attr=%08x\n",UTT,ii,pos,ch,pcchar->attr);     //~v7bEI~//~v7ezR~
        ccharlen=1;                                                //~v5n8I~
        if (ch>=0x80)                                              //~v5n8I~//~v650R~//~v656R~
        {                                                          //~v5n8I~
        	if (pcchars)//preceding asccii string                  //~v5n8I~
            {                                                      //~v5n8I~
				uviom_mvaddwchnstr(Prow,poss,pcchars,pos-poss);    //~v5n8R~
	UTRACEP("%s:sbcs row=%d,col=%d,len=%d\n",UTT,Prow,poss,pos-poss);     //~v62mR~//~v7c4R~
	UTRACED("sbcs        ",pcchars,(pos-poss)*CCHSZ);              //~v5n8R~
    			pcchars=0;                                         //~v5n8R~
            }                                                      //~v5n8I~
//some char is wcwidth=2 but displayed by single width             //~v5n8I~
//that cause vsplitline column shift,invalid update postion        //~v5n8I~
//but write 1 by 1 coluld not display those char. I accept it.     //~v5n8I~
	    	dbcssw=(pcchar->attr & 0x01);	//dbcs 1st             //~v5n8R~
            UTRACED("pcchar",pcchar,(int)sizeof(cchar_t)*(1+dbcssw));//~v7atI~
            ccharlen+=dbcssw;                                      //~v5n8I~
            if (dbcssw                                             //~v7atR~
            &&  !((pcchar+1)->attr & UVIOMATTR_DBCS2) //dummy dbcs flag by  dbcs by dbcstbl but wcwidthj()=1 at uvio_ddcht2cchar//~v7atR~
            &&  (pcchar+1)->chars[0]==' ')                         //~v7atI~
            {                                                      //~v7atI~
                dbcssw=0;                                          //~v7atI~
                ccharlen--;                                        //~v7atR~
		    	pcchar->attr &=(attr_t)(~UVIOMATTR_DBCS1);//       0x01         //1:dbcs1st,2:DBCS2ND//~v7atR~
            }                                                      //~v7atI~
            UTRACEP("%s:dbcssw=%d,swWideSbcs=%d,ccharlen=%d\n",UTT,dbcssw,swWideSbcs,ccharlen);//~v7atI~//~v7bER~
            UTRACED("pcchar",pcchar,(int)sizeof(cchar_t)*ccharlen);//~v7atR~
    		UTRACEP("%s:%x:dbcssw=%d,wcwidth=%d\n",UTT,pcchar->chars[0],dbcssw,wcwidth((wchar_t)pcchar->chars[0]));//~v62mM~//~v6V6R~//~v7bER~
    		uviom_mvaddwchnstr(Prow,pos,pcchar,ccharlen);          //~v653R~//~v656R~
            if (swWideSbcs)                                        //~v7bEI~
            {                                                      //~v7bEI~
                ccharlen=2;                                        //~v7bEI~
                pcchar--;                                          //~v7bEI~
//#ifdef SSS  //TODO test  //for 3cell glyph                       //~v7c4R~
//#else                                                            //~v7c4R~
//                ccharlen++;                                      //~v7c4R~
//                pcchar--;                                        //~v7c4R~
//#endif                                                           //~v7c4R~
            }                                                      //~v7bEI~
//#ifndef SSS  //TODO test  //for 3cell glyph                      //~v7c4R~
//            if (ch==0x06dd)                                      //~v7c4R~
//            {                                                    //~v7c4R~
//                UTRACEP("%s:TEST widen 0x%02x\n",UTT,pcchar->chars[0]);//~v7c4R~
//                ccharlen++;                                      //~v7c4R~
//                pcchar--;                                        //~v7c4R~
//            }                                                    //~v7c4R~
//#endif                                                           //~v7c4R~
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
    ScchTop=Ppcchar;                                               //~v7bJR~
    SwidthLineno=0;                                                //~v7bRI~
    if (utfchkdd(0,Ppdbcs,Plen))	//source is DD fmt             //~v640M~
    {                                                              //~v653I~
  	  	if (Guviol_flag & UVIOL_DDHCOPY)                           //~vbEgI~
        	uviolSaveDD(0,Prow,Pcol,Ppcht,Ppdbcs,Plen);//save for HCOPY//~vbEgR~
    	SwidthLineno=getTopCCH(Plineopt,Ppcht,Ppdbcs,Plen);            //~v7bJR~//~v7bRR~
    	ScchTop+=SwidthLineno;                                     //~v7bRI~
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
//                  	(pcchar+0)->attr|=1;                       //~v62UR~//~v6W8R~
                    	(pcchar+0)->attr|=UVIOMATTR_DBCS1;         //~v6W8I~
//                  	(pcchar+1)->attr|=2;                       //~v62UR~//~v6W8R~
                    	(pcchar+1)->attr|=UVIOMATTR_DBCS2;         //~v6W8I~
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
//                  	(pcchar+0)->attr|=1;                       //~v62UR~//~v6W8R~
                    	(pcchar+0)->attr|=UVIOMATTR_DBCS1;         //~v6W8I~
//                  	(pcchar+1)->attr|=2;                       //~v62UR~//~v6W8R~
                    	(pcchar+1)->attr|=UVIOMATTR_DBCS2;         //~v6W8I~
                    	(pcchar+2)->chars[0]=Guviomdbcspad;        //~v62UR~
        				(pcchar+2)->attr=attrdbcspad;              //~v62UR~
                    	*(pcchar+3)=*(pcchar+2);                   //~v62UR~
#else                                                              //~v631I~
                        //ucs1+ucs2+(..)+(.)                       //~v631I~
                    	pcchar->chars[0]=ucs;                      //~v631I~
                    	*(pcchar+1)=*pcchar;                       //~v631I~
//                    	(pcchar+0)->attr|=1;                       //~v631I~//~v6W8R~
                      	(pcchar+0)->attr|=UVIOMATTR_DBCS1;         //~v6W8I~
//                  	(pcchar+1)->attr|=2;                       //~v631I~//~v6W8R~
                    	(pcchar+1)->attr|=UVIOMATTR_DBCS2;         //~v6W8I~
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
//                  		(pcchar+0)->attr|=1;                   //~v631M~//~v6W8R~
                    		(pcchar+0)->attr|=UVIOMATTR_DBCS1;     //~v6W8I~
//                  		(pcchar+1)->attr|=2;                   //~v631M~//~v6W8R~
                    		(pcchar+1)->attr|=UVIOMATTR_DBCS2;     //~v6W8I~
                    		(pcchar+2)->chars[0]=Guviomdbcspad;    //~v631M~
                    		(pcchar+2)->chars[1]=Guviomdbcspad;    //~v631M~
                    		(pcchar+2)->attr=attrdbcspad;          //~v631M~
                    	}	//wcwidth==2                           //~v631M~
                   }                                               //~v62UR~
                   else                                            //~v62UR~
                   {                                               //~v62UR~
                    (pcchar+0)->chars[0]=ucs;    //uc1+ucs2+.      //~v62UR~
                    *(pcchar+1)=*(pcchar+0);                       //~v62UR~
//                  (pcchar+0)->attr|=1;                           //~v62UR~//~v6W8R~
                    (pcchar+0)->attr|=UVIOMATTR_DBCS1;             //~v6W8I~
//                  (pcchar+1)->attr|=2;                           //~v62UR~//~v6W8R~
                    (pcchar+1)->attr|=UVIOMATTR_DBCS2;             //~v6W8I~
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
//                      pcchar->attr|=1;    //1st of dbcs          //~v5n8I~//~v6W8R~
                        pcchar->attr|=UVIOMATTR_DBCS1;    //1st of dbcs//~v6W8I~
//                      (pcchar+1)->attr|=2;    //1st of dbcs      //~v5n8I~//~v6W8R~
                        (pcchar+1)->attr|=UVIOMATTR_DBCS2;    //1st of dbcs//~v6W8I~
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
  	if (Guviol_flag & UVIOL_DDHCOPY)                               //~vbEgI~
        uviolSavecchar(0,Prow,Pcol,Ppcchar,Ppdbcs,Plen);//save for HCOPY//~vbEgR~
UTRACED("inp cht",Ppcht,Plen*CCTSZ);                     //~v640R~//~v6hhR~//~v6D9R~
UTRACED("inp dbcs",Ppdbcs,Plen);                         //~v640R~//~v6hhR~//~v6D9R~
UTRACED("out cchar",Ppcchar,Plen*CCHSZ);                 //~v640R~//~v6hhR~//~v6D9R~
    return rc;                                                     //~v5n8I~
}//uviom_cht2cchar                                                 //~v640R~
#endif //CURSESW                                                   //~v5n8R~
#endif //!XXE                                                      //~v5n8I~
#endif //WCSUPP                                                    //~v5n8R~
                                                                   //~v640I~
#ifdef UTF8UCS2                                                    //~v640I~
#ifdef LNX                                                         //~v640I~
#ifndef XXE                                                        //~v640I~
//#ifdef AAA                                                       //~v653R~
//#else   //for performance ;called only whe combining char detected//~v653R~
//***************************************************************************//~v7bWI~
int setccharFormat(int Popt,WUCS Pucs,PCCH Ppcchar)                //~v7bWR~
{                                                                  //~v7bWI~
	cchar_t *pcchar;                                               //~v7bWI~
    attr_t attr;                                                   //~v7bWI~
//*******************                                              //~v7bWI~
	UTRACEP("%s:opt=0x%04x,Pucs=0x%04x\n",UTT,Popt,Pucs);          //~v7bWI~
//    if (!utf4_isFormat(0,Pucs))                                  //~v7bWR~
//    {                                                            //~v7bWR~
//        UTRACEP("%s:no format rc=0,Pucs=0x%04x\n",UTT,Pucs);     //~v7bWR~
//        return 0;                                                //~v7bWR~
//    }                                                            //~v7bWR~
	int altch=uviom_getAltFormat(0,Pucs,0/*default*/);             //~v7bWI~
    if (!altch)                                                    //~v7bWI~
		return 0;                                                  //~v7bWI~
    pcchar=Ppcchar;                                                //~v7bWI~
//  pcchar->chars[0]=UVIOM_ALTCH_FORMAT;                           //~v7bWR~
    pcchar->chars[0]=altch;//UVIOM_ALTCH_FORMAT;                   //~v7bWI~
  if (Popt & UVIOMATTR_SETATTR)                                    //~v7exI~
  {                                                                //~v7exI~
    attr=uviom_set_padattr(0,ATTR_COMBINE_FG_UCS4<<8);             //~v7bWI~
    UTRACEP("%s:attr=%04x by SETATTR on\n",UTT,attr);              //~v7exI~//~v7f4R~
  }                                                                //~v7exI~
  else                                                             //~v7exI~
  {                                                                //~v7exI~
    attr=pcchar->attr;                                             //~v7exI~
    UTRACEP("%S:attr=%04x is orginal by SETATTR off\n",UTT,attr);  //~v7exI~
  }                                                                //~v7exI~
    attr|=UVIOMATTR_BREAK;  //adjust column                        //~v7bWI~
    attr|=UVIOMATTR_EXT_ALTCH;  //could not be a combine base      //~v7c4I~
    pcchar->attr=attr;                                             //~v7bWI~
	UTRACEP("%s:format rc=1,Pucs=0x%04x\n",UTT,Pucs);              //~v7bWI~
	UTRACED("out cchar",Ppcchar,CCHSZ);                            //~v7bWI~
    return 1;                                                      //~v7bWI~
}//setccharFormat                                                  //~v7c2R~
//***************************************************************************//~v6V6I~
//*set a0*ucs                                                      //~v6WbI~
//***************************************************************************//~v6WbI~
void uviom_setcchar_itself(int Popt,WUCS Pucs,cchar_t *Ppcchar)    //~v6V6I~
{                                                                  //~v6V6I~
	UTRACEP("%s:opt=0x%04x,Pucs=0x%04x\n",UTT,Popt,Pucs);          //~v7brI~
    if (setccharFormat(Popt,Pucs,Ppcchar))                         //~v7bWI~
    	return;                                                    //~v7bWI~
#ifdef NNN                                                         //~v6W1I~//~v6W2R~//~v6W3R~
    Ppcchar->chars[0]=' ';      //combining char on space          //~v6V6I~
#else                   //u-00a0 cause disappear of combining char                                           //~v6W1I~//~v6W2R~
    Ppcchar->chars[0]=COMBAINE_BASE_SPLIT_ITSELF;     //u00a0 base for combining char when split itself//~v6W1M~
#endif                                                             //~v6W1I~
    Ppcchar->chars[1]=Pucs;     //combining char itself            //~v6V6I~
//  Ppcchar->attr|=A_REVERSE;                                      //~v6V6R~
//  Ppcchar->attr|=A_STANDOUT;                                     //~v6V6R~
//  Ppcchar->attr|=A_UNDERLINE;                                    //~v6V6R~
	if (Popt & UVIOMATTR_EXT_LIGATURE)//extended option, ligature  //~v6V6I~
    {                                                              //~v6WbI~
#ifdef DDD                                                         //~v6WbI~
		Ppcchar->attr|=UVIOMATTR_EXT_PADDING;                      //~v6V6I~
#else                                                              //~v6WbI~
  	  	if (Popt & UVIOMATTR_PADDING2)  //for the case ligature not combine mode//~v6WbI~
    		Ppcchar->attr|=UVIOMATTR_EXT_PADDING2;    //ALTCH2 will be follows//~v6WbR~
#endif                                                             //~v6WbI~
//  	Ppcchar->attr|=UVIOMATTR_EXT_DMYBASE;     //added "A0" entry for combining//~v6WbR~//~v7bJR~
    }                                                              //~v6WbI~
  	Ppcchar->attr|=UVIOMATTR_EXT_DMYBASE;     //added "A0" entry for combining//~v7bJI~
	UTRACED("cchar",Ppcchar,sizeof(cchar_t));                      //~v6V6I~//~v6W2R~
}//uviom_setcchar_itself                                           //~v6V6I~
//#ifndef VVV                                                        //~v6W5R~//~v7bJR~
//#else                                                              //~v6W5R~//~v7bJR~
////***************************************************************************//~v6W5I~//~v7bJR~
//void uviom_setcchar_shadow(int Popt,UWUCS Pucsbase,WUCS Pucs,cchar_t *Ppcchar)//~v6W5I~//~v7bJR~
//{                                                                  //~v6W5I~//~v7bJR~
//    cchar_t *pcchar;                                               //~v6W5I~//~v7bJR~
//    attr_t attr;                                                   //~v6W5I~//~v7bJR~
////*******************                                              //~v6W5I~//~v7bJR~
//    pcchar=Ppcchar;                                                //~v6W5I~//~v7bJR~
//    pcchar->chars[0]=Pucsbase;  //shadow base                      //~v6W5I~//~v7bJR~
//    attr=(attr_t)(pcchar->attr & UVIOMATTR_COLORMASK);             //~v6W5I~//~v7bJR~
//    pcchar->attr=(attr_t)(attr | UVIOMATTR_SHADOW); //write with   //~v6W5I~//~v7bJR~
//    pcchar++;                                                      //~v6W5I~//~v7bJR~
//    pcchar->chars[0]=COMBAINE_BASE_SPLIT_ITSELF;//a0     //u00a0 base for combining char when split itself//~v6W5I~//~v7bJR~
//    pcchar->chars[1]=Pucs;     //combining char                    //~v6W5I~//~v7bJR~
//    pcchar->attr=attr;                                             //~v6WbI~//~v7bJR~
////  if (Popt & UVIOMATTR_EXT_LIGATURE)//extended option, ligature  //~v6WbI~//~v7bJR~
//        pcchar->attr|=UVIOMATTR_EXT_DMYBASE;     //added "A0" entry for combining//~v6WbR~//~v7bJR~
//    UTRACEP("%s:base=0x%04x,ucs=0x%04x,attr=0x%04x\n",Pucsbase,Pucs,pcchar->attr);//~v7bJR~
//}//uviom_setcchar_shadow                                           //~v6W5I~//~v7bJR~
//#endif //VVV                                                       //~v6W5R~//~v7bJR~
#ifdef YYY                                                         //~v6W5I~
#else                                                              //~v6W5I~
//***************************************************************************//~v6W5I~
//*set a0*ucs                                                      //~v6WbI~
//***************************************************************************//~v6WbI~
//void uviom_setcchar_shadow(int Popt,UWUCS Pucsbase,WUCS Pucs,cchar_t *Ppcchar)//~v6W5I~//~v6W6R~
//void uviom_setcchar_shadow(int Popt,UWUCS Pucsbase,WUCS Pucs,cchar_t *Ppcchar,cchar_t *Ppcchar0)//~v6W6I~//~v7c8R~
int uviom_setcchar_shadow(int Popt,UWUCS Pucsbase,WUCS Pucs,cchar_t *Ppcchar,cchar_t *Ppcchar0)//~v7c8I~
{                                                                  //~v6W5I~
	cchar_t *pcchar;                                               //~v6W5I~
#ifndef GGG                                                        //~v6W6R~
#else                                                              //~v6W6I~
	cchar_t *pccprev;                                              //~v6W6I~
#endif                                                             //~v6W6I~
    attr_t attr;                                                   //~v6W5I~
//*******************                                              //~v6W5I~
	UTRACEP("%s:opt=0x%04x,ucsbase=0x%04x,Pucs=0x%04x,attr=0x%04x\n",UTT,Popt,Pucsbase,Pucs,Ppcchar->attr);//~v7brI~//~v7bJR~
    if (setccharFormat(Popt,Pucs,Ppcchar))                         //~v7bWI~
    {                                                              //~v7c8I~
//        if (Popt & UVIOMATTR_BASEDBCS) //base is dbcs            //~v7c8R~
//        {                                                        //~v7c8R~
//            *(Ppcchar+1)=*Ppcchar;                               //~v7c8R~
//            (Ppcchar+1)->chars[0]=Guviomdbcspad;                 //~v7c8R~
//        }                                                        //~v7c8R~
//    	return;                                                    //~v7bWI~//~v7c8R~
		UTRACEP("%s:set altch and ignored BASEDBCS return rc=0\n",UTT);//~v7c8I~
      	return 0;                                                  //~v7c8I~
    }                                                              //~v7c8I~
    pcchar=Ppcchar;                                                //~v6W5I~
    pcchar->chars[0]=Pucsbase;	//shadow base                      //~v6W5I~
    attr=(attr_t)(pcchar->attr & UVIOMATTR_COLORMASK);             //~v6W5I~
    attr|=UVIOMATTR_BREAK;  //adjust column                        //~v7bNR~
//	if (!(Popt & UVIOMATTR_EXT_LIGATURE))//extended option, ligature//~v6W5I~//~v6WbR~
    {                                                              //~v6W7I~
  	  if (Popt & UVIOMATTR_PADDING2)  //for the case ligature not combine mode//~v6W7I~
    	pcchar->attr=(attr_t)(attr | (UVIOMATTR_SHADOW | UVIOMATTR_EXT_PADDING2));    //shadow padding for overflowcombining//~v6W7I~
      else                                                         //~v6W7I~
    	pcchar->attr=(attr_t)(attr | UVIOMATTR_SHADOW); //write with//~v6W5R~
    }                                                              //~v6W7I~
//  else                                                           //~v6W5I~//~v6WbR~
//    	pcchar->attr=attr;                                         //~v6W5I~//~v6WbR~
#ifdef AAA                                                         //~v7bJI~
//*shadow is 2cell but combch is 1 cell                            //~v7bYI~
	if (Popt & UVIOMATTR_EXT_BASEWIDE)  //csr step follows combining char's dbcs//~v7bJR~
#else                                                              //~v7bJI~
	if (Popt & UVIOMATTR_EXT_WIDESBCS)                             //~v7bJI~
#endif                                                             //~v7bJI~//~v7bYR~
    	pcchar->attr|=UVIOMATTR_EXT_WIDESBCS;                      //~v7bJI~
	pcchar->chars[1]=Pucs;                                         //~v6W5I~
#ifndef GGG                                                        //~v6W6R~
#else                                                              //~v6W6I~
    pccprev=pcchar-1;                                              //~v6W6I~
//  if (pccprev>=Ppcchar0)                                         //~v6W6I~//~v7bJR~
    if (pccprev>=ScchTop)                                          //~v7bJR~
    {                                                              //~v6W6I~
//  	if (pccprev->attr & UVIOMATTR_DBCS12 && (pccprev-1>=Ppcchar0))//~v6W6I~//~v7bJR~
    	if (pccprev->attr & UVIOMATTR_DBCS12 && (pccprev-1>=ScchTop))//~v7bJR~
        	pccprev--;                                             //~v6W6I~
    	pccprev->attr=(attr_t)(pccprev->attr | UVIOMATTR_BREAK); //write 1 ucs to clear//~v6W6I~
    }                                                              //~v6W6I~
#endif                                                             //~v6W6I~
#ifdef HHH                                                         //~v7brM~
    pcchar++;                                                      //~v6W5I~
#ifndef ZZZ                                                        //~v6W5R~
	if (!(Popt & UVIOMATTR_EXT_LIGATURE))//extended option, ligature//~v6W5I~
    {                                                              //~v6W5I~
		pcchar->chars[0]=' ';                                      //~v6W5R~
//  	pcchar->attr=attr;                                         //~v6W5R~//~v6WaR~
    	pcchar->attr=(attr_t)(attr|UVIOMATTR_PADDING);             //~v6WaI~
    	pcchar++;                                                  //~v6W5I~
    }                                                              //~v6W5I~
#endif                                                             //~v7brI~
#else                                                              //~v7bsI~
	int rc=0; //1 cchar written                                    //~v7c8R~
  	if (Popt & UVIOMATTR_BASEDBCS) //base is dbcs                  //~v7bsI~
    {                                                              //~v7bsI~
    	*(pcchar+1)=*pcchar;                                       //~v7bsI~
    	pcchar->attr|=UVIOMATTR_DBCS1;                             //~v7bsR~
    	pcchar->attr&=(attr_t)(~UVIOMATTR_EXT_PADDING2);    //shadow padding for overflowcombining//~v7bsR~
    	(pcchar+1)->attr|=UVIOMATTR_DBCS2;                         //~v7bsR~
    	(pcchar+1)->attr&=(attr_t)(~(UVIOMATTR_SHADOW|UVIOMATTR_EXT_PADDING2));    //shadow padding for overflowcombining//~v7bsR~
    	pcchar++;                                                  //~v7bSI~
        rc=1;	//2 cchar written                                  //~v7c8I~
    }                                                              //~v7bsI~
#endif                                                             //~v6W5I~
	UTRACEP("%s:rc=%d\n",UTT,rc);                                  //~v7c8R~
	UTRACED("cchar",Ppcchar,(PTRDIFF(pcchar,Ppcchar)+1)*CCHSZ);    //~v7c8I~
    return rc;                                                     //~v7c8I~
}//uviom_setcchar_shadow                                           //~v6W5I~
#endif //YYY                                                       //~v6W5I~
//***********************************************************************//~v7bLI~
//*use a0 for base for split SCM(not combined to SCMBase by breaksw//~v7bLI~
//***********************************************************************//~v7bLI~
int chkBaseSplitSCM(int Popt,int Plineopt,int Pattropt,WUCS Pucsbase,WUCS Pucs,chtype *Ppcht,cchar_t *Ppcchar,cchar_t *Ppcchar0)//~v7bLR~
{                                                                  //~v7bLI~
	UTRACEP("%s:opt=0x%04x,lineopt=0x%04x,attropt=0x%04x,ucsbase=0x%04x,ucs=0x%04x\n",UTT,Popt,Plineopt,Pattropt,Pucsbase,Pucs);//~v7bLR~
	UTRACED("entry Ppcchar",Ppcchar,CCHSZ);                        //~v7bLI~
    int opt=Popt & ~UVIOMSCO_WIDESBCS;                             //~v7bLI~
//  if (Popt & UVIOMATTR_BREAK)//break, show itself or shadow      //~v7bLR~
//  {                                                              //~v7bLR~
//    UTRACEP("%s:Popt:break\n",UTT);                              //~v7bLR~
//  }                                                              //~v7bLR~
//  else                                                           //~v7bLR~
//  {                                                              //~v7bLR~
//    if (Popt & UVIOMATTR_EXT_LIGATURE)//extended option, ligature//~v7bLR~
//    {                                                            //~v7bLR~
//        UTRACEP("%s:rc=0 by LIGATURE mode\n",UTT);               //~v7bLR~
//        return 0;                                                //~v7bLR~
//    }                                                            //~v7bLR~
//    if (!utf4_isSpacingCombiningMark(0,Pucsbase))                //~v7bLR~
//    {                                                            //~v7bLR~
//        UTRACEP("%s:rc=0 by base is not scm\n",UTT);             //~v7bLR~
//        return 0;                                                //~v7bLR~
//    }                                                            //~v7bLR~
//  }                                                              //~v7bLR~
    int swSCM=0;                                                   //~v7bLI~
    int setBreak=0;                                                //~v7bLR~
    int swBreak=(Popt & UVIOMATTR_BREAK);                          //~v7bLI~
    PCCH prev=Ppcchar-1;                                           //~v7bLR~
    if (prev>=Ppcchar0)                                            //~v7bLI~
    {                                                              //~v7bLI~
		if (prev->attr & UVIOMATTR_EXT_SCM)                        //~v7bLI~
        {                                                          //~v7bLI~
			UTRACEP("%s:prev(0x%04x) is already SCM\n",UTT,prev->chars[0]);//~v7bLI~
        	swSCM=1;                                               //~v7bLI~
        }                                                          //~v7bLI~
        else                                                       //~v7bLI~
		if (prev->chars[1]==0 && utf4_isSpacingCombiningMark(0,prev->chars[0]))//~v7bLR~
        {                                                          //~v7bLI~
			UTRACEP("%s:prev(0x%04x) is SCM width no combining\n",UTT,prev->chars[0]);//~v7bLI~
        	swSCM=1;                                               //~v7bLI~
        }                                                          //~v7bLI~
		swBreak|=(prev->attr & UVIOMATTR_BREAK)!=0;                //~v7bLI~
    }                                                              //~v7bLI~
    if (!swSCM)                                                    //~v7bLI~
    {                                                              //~v7bLI~
        UTRACEP("%s:rc=0 by prev is not SCM\n",UTT);               //~v7bLI~
        return 0;                                                  //~v7bLI~
    }                                                              //~v7bLI~
    if (Popt & UVIOMATTR_EXT_LIGATURE)//extended option, ligature  //~v7bLI~
    {                                                              //~v7bLI~
        UTRACEP("%s:opt ligature\n",UTT);                          //~v7bLI~
        if (UTF_COMBINEMODE())  //split mode                       //~v7bLR~
        {                                                          //~v7bLR~
        	if (!swBreak)                                          //~v7bLR~
            {                                                      //~v7bLI~
            	UTRACEP("%s:rc=0 by ligature & combinemode & not Break\n",UTT);//~v7bLR~
            	return 0;                                          //~v7bLR~
            }                                                      //~v7bLI~
        }                                                          //~v7bLR~
        else                                                       //~v7bLI~
        	setBreak=1; //opt break is on when not combine mode for not ligature mode thru setcombine1<--setcombine//~v7bLI~
        	            //when ligature mode breake is on when csr break//~v7bLI~
    }                                                              //~v7bLI~
   	if (Scombaltch==UVIOM_ALTCHPADDING)                            //~v7bLI~
    {                                                              //~v7bLI~
		Ppcchar->chars[0]=Guviomdbcspad;                           //~v7bLI~
		if (setBreak)                                              //~v7bLR~
			Ppcchar->attr|=UVIOMATTR_BREAK;	//do not ligature      //~v7bLR~
    }                                                              //~v7bLI~
   	else                                                           //~v7bLI~
   	if (Scombaltch==UVIOM_ALTCHSHADOW)                             //~v7bLI~
   	{                                                              //~v7bLI~
//        if (Popt & UVIOMATTR_BASEDBCS) //base is dbcs            //~v7bLI~
//        {                                                        //~v7bLI~
//            uviom_setcchar_shadow(Popt,Pucsbase,Pucs,Ppcchar,Ppcchar0);//~v7bLI~
//            rc=1;   //added 1 cchar                              //~v7bLI~
//            swShadowDbcs=1;                                      //~v7bLI~
//        }                                                        //~v7bLI~
//        else                                                     //~v7bLI~
  		{                                                          //~v7bLI~
        	int dummybase=COMBAINE_BASE_SPLIT_ITSELF;  //0xa0     //u00a0 base for combining char when split itself//~v7bLI~
  			uviom_setcchar_shadow(opt,dummybase,Pucs,Ppcchar,Ppcchar0);//~v7bLI~
    		Ppcchar->attr|=(attr_t)Pattropt;                       //~v7bLI~
  		}//!dbcs                                                   //~v7bLI~
		if (setBreak)                                              //~v7bLI~
			Ppcchar->attr|=UVIOMATTR_BREAK;	//do not ligature      //~v7bLR~
	}                                                              //~v7bLI~
   	else                                                           //~v7bLI~
   	if (Scombaltch==UVIOM_ALTCHITSELF)                             //~v7bLI~
   	{                                                              //~v7bLI~
   		Ppcchar->chars[0]=Pucs;     //combining char itself        //~v7bLI~
   		if (!(Plineopt & UVIOO_CSRPOSCHK))       // file data line //~v7bLI~
    		Ppcchar->attr=uviom_attr_itself(Plineopt,*Ppcht)|(attr_t)Pattropt;//~v7bLR~
   		if (Plineopt & UVIOO_CSRPOSCHK)        // file data line   //~v7bLI~
    		uviom_setcchar_itself(Popt,Pucs,Ppcchar);              //~v7bLI~
		if (setBreak)                                              //~v7bLI~
			Ppcchar->attr|=UVIOMATTR_BREAK;	//do not ligature      //~v7bLR~
   	}                                                              //~v7bLI~
   	else                                                           //~v7bLI~
   	if (UTF_COMBINEMODE())   //entered to combine1 by lineopt,same as itself//~v7bLI~
   	{                                                              //~v7bLI~
   		UTRACEP("%s:UTF_COMBINEMODE\n",UTT);                       //~v7bLI~
    	Ppcchar->chars[0]=Pucs;     //combining char itself        //~v7bLI~
   		if (!(Plineopt & UVIOO_CSRPOSCHK))       // file data line //~v7bLI~
    		Ppcchar->attr=uviom_attr_itself(Plineopt,*Ppcht)|(attr_t)Pattropt;//~v7bLI~
   	}                                                              //~v7bLI~
   	else                                                           //~v7bLI~
   	{                                                              //~v7bLI~
    	Ppcchar->chars[0]=Scombaltch;     //combining char special parm//~v7bLI~
//        if (!(Popt & UVIOMATTR_PADDING2))  //Not ovf combine char(for the case ligature not combine mode)//~v7bLI~
//        {                                                        //~v7bLI~
    		if (Popt & UVIOMATTR_BREAK)   //not around csr column  //~v7bLI~
    			uviom_setcchar_itself(Popt,Pucs,Ppcchar);          //~v7bLI~
//        }                                                        //~v7bLI~
   	}                                                              //~v7bLI~
	UTRACED("exit Ppcchar",Ppcchar,CCHSZ);                         //~v7bLI~
    return 1;                                                      //~v7bLI~
}//chkBaseSplitSCM                                                 //~v7bLI~
//*******************************************************          //~v653I~
//*display combine char as it is; Ligature ON and OFF                                   //~v653I~//~v7epR~
//*called when not combinemode and cursor is around combining when combine mode//~v7brI~
//*rc:1: padding was added                                         //~v6W5I~
//*******************************************************          //~v653I~
//int uviom_setcombine1(int Popt,WUCS Pucs,WUCS Pucsbase,chtype *Ppcht,cchar_t *Ppcchar)//~v653I~//~v6EmR~
//int uviom_setcombine1(int Popt,int Plineopt,WUCS Pucs,WUCS Pucsbase,chtype *Ppcht,cchar_t *Ppcchar)//~v6EmI~//~v6W6R~
int uviom_setcombine1(int Popt,int Plineopt,WUCS Pucs,WUCS Pucsbase,chtype *Ppcht,cchar_t *Ppcchar,cchar_t *Ppcchar0)//~v6W6R~
{                                                                  //~v653I~
//  int attr,attropt;                                                      //~v653I~//~v656R~//~v6BhR~
    int attropt;                                                   //~v6BhI~
    attr_t attr;                                                   //~v6BhI~
#define UVIOM_DUMMYBASE  0xfeff //0x00a0 //0x200b                  //~v658R~
    int rc=0;                                                      //~v6V5R~
    cchar_t *pcchar_padding2;                                      //~v6V5I~
    int swShadowDbcs=0;                                            //~v7bsI~
//************************                                         //~v653I~
UTRACEP("%s:entry opt=0x%x,ucs=%04x,ucsbase=%04x,Scombaltch=%x\n",UTT,Popt,Pucs,Pucsbase,Scombaltch);     //~v6D9I~//~v6W2R~//~v6WbR~//~v7c8R~
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
#ifdef HHH                                                         //~v6W8I~
  if (Popt & UVIOMATTR_BASEDBCS) //base is dbcs                    //~v658I~
  {                                                                //~v658I~
    Ppcchar->chars[0]=Guviomdbcspad;                               //~v658I~
  }                                                                //~v658I~
  else                                                             //~v658I~
#endif                                                             //~v6W8I~
  if (!Pucsbase)                                                   //~v7bYI~
  {                                                                //~v7bYI~
//	if (Scombaltch==UVIOM_ALTCHPADDING)                            //~v7bYI~//~v7fdR~
  	if (Scombaltch==UVIOM_ALTCHPADDING                             //~v7fdI~
    && !SswComb1W0NOCOMB)   //not combining char                   //~v7fdI~
    	Ppcchar->chars[0]=Guviomdbcspad;                           //~v7bYI~
    else                                                           //~v7bYI~
    {                                                              //~v7bYI~
//      Ppcchar->attr=uviom_attr_itself(Plineopt,*Ppcht)|(attr_t)attropt;//~v7bYR~
        uviom_setcchar_itself(Popt,Pucs,Ppcchar);                  //~v7bYI~
    }                                                              //~v7bYI~
  }	//Pucsbacse=0                                                  //~v7bYI~
  else                                                             //~v7bYI~
  if (UTF_COMBINABLE(Pucsbase))                                    //~v656R~
  {                                                                //~v656I~
  if (!chkBaseSplitSCM(Popt,Plineopt,attropt,Pucsbase,Pucs,Ppcht,Ppcchar,Ppcchar0))//~v7bLI~
  {                                                                //~v7bLI~
//   if (!UVIOM_NONSPACECOMBINEMODE()) //fc5                       //~v658R~
   if (Scombaltch==UVIOM_ALTCHPADDING)                             //~v658I~
   {                                                               //~v7bWI~
//  Ppcchar->chars[0]=Guviomdbcspad;                               //~v658I~//~v7bWR~
    Ppcchar->chars[0]=uviom_getAltFormat(0,Pucs,Guviomdbcspad);    //~v7bWI~
    if (Ppcchar->chars[0]!=Guviomdbcspad)                          //~v7c4I~
    {                                                              //~v7c4I~
    	Ppcchar->attr|=UVIOMATTR_EXT_ALTCH;  //could not be a combine base//~v7c4I~
        UTRACEP("%s:ALTCH set EXT_ALTCH chars[0]=0x%04x,attr=0x%04x\n",UTT,Ppcchar->chars[0],Ppcchar->attr);//~v7c4I~//~v7c8R~
    }                                                              //~v7c4I~
//#ifndef SSS                                                      //~v7c4R~
//    Ppcchar->chars[0]=Guviomdbcspad;    //yet set padding char   //~v7c4R~
//#endif                                                           //~v7c4R~
   }                                                               //~v7bWI~
   else                                                            //~v658I~
   if (Scombaltch==UVIOM_ALTCHSHADOW)                              //~v658I~
   {                                                               //~v658I~
#ifdef HHH                                                         //~v6W8I~
#else                                                              //~v6W8I~
  if (Popt & UVIOMATTR_BASEDBCS) //base is dbcs                    //~v6W8I~
  {                                                                //~v6W8I~
#ifdef HHH                                                         //~v7bsI~
    	Ppcchar->chars[0]=Pucs;     //combining char itself        //~v6W8I~
   		if (!(Plineopt & UVIOO_CSRPOSCHK))       // file data line //~v6W8I~
    		Ppcchar->attr=uviom_attr_itself(Plineopt,*Ppcht)|(attr_t)attropt;//~v6W8I~
   		if (Plineopt & UVIOO_CSRPOSCHK)        // file data line   //~v6W8I~
    		uviom_setcchar_itself(Popt,Pucs,Ppcchar);              //~v6W8I~
#else                                                              //~v7bsI~
   int rc2=	//0:1 cell written, 1:2 cell written                   //~v7c8I~
  	uviom_setcchar_shadow(Popt,Pucsbase,Pucs,Ppcchar,Ppcchar0);    //~v7bsI~
   if (rc2)                                                        //~v7c8I~
   {                                                               //~v7c8I~
    rc=1;	//added 1 cchar                                        //~v7bsI~
    swShadowDbcs=1;                                                //~v7bsI~
   }                                                               //~v7c8I~
#endif                                                             //~v7bsI~
  }                                                                //~v6W8I~
  else                                                             //~v6W8I~
#endif                                                             //~v6W8I~
  {                                                                //~v6W8I~
//#ifdef VVV                                                       //~v6W5R~
#ifdef YYY                                                         //~v6W5I~
    Ppcchar->chars[0]=Pucsbase;	//shadow base                                         //~v653I~//~v652R~//~v656I~//~v658R~
//  Ppcchar->chars[0]=UVIOM_DUMMYBASE;                             //~v658R~
    Ppcchar->chars[1]=Pucs;     //combining char                                   //~v653I~//~v656I~
    Ppcchar->attr|=UVIOMATTR_SHADOW;                               //~v65bR~
#else                                                              //~v6W5I~
//	uviom_setcchar_shadow(Popt,Pucsbase,Pucs,Ppcchar);             //~v6W5I~//~v6W6R~
  	uviom_setcchar_shadow(Popt,Pucsbase,Pucs,Ppcchar,Ppcchar0);    //~v6W6I~
#ifdef HHH                                                         //~v7brI~
#ifndef ZZZ                                                        //~v6W5R~
	if (!(Popt & UVIOMATTR_EXT_LIGATURE))//extended option, ligature//~v6W5I~
    	rc=1;	//added 1 cchar                                    //~v6W5R~
#endif                                                             //~v6W5I~
#endif                                                             //~v7brI~
#endif //VVV                                                       //~v6W5I~
  }//!dbcs                                                         //~v6W8I~
   }                                                               //~v658I~
   else                                                            //~v658I~
   if (Scombaltch==UVIOM_ALTCHITSELF)                              //~v658R~
   {                                                               //~v6EmI~
    Ppcchar->chars[0]=Pucs;     //combining char itself            //~v658I~
   if (!(Plineopt & UVIOO_CSRPOSCHK))       // file data line      //~v6EnR~
    Ppcchar->attr=uviom_attr_itself(Plineopt,*Ppcht)|(attr_t)attropt;//~v6EnR~
   	if (Plineopt & UVIOO_CSRPOSCHK)        // file data line       //~v6V6R~
    	uviom_setcchar_itself(Popt,Pucs,Ppcchar);                  //~v6V6R~
   }                                                               //~v6EmI~
   else                                                            //~v658I~
   if (UTF_COMBINEMODE())   //entered to combine1 by lineopt,same as itself//~v6EnI~
   {                                                               //~v6EnI~
   	UTRACEP("%s:UTF_COMBINEMODE\n",UTT);                           //~v6W2I~
    Ppcchar->chars[0]=Pucs;     //combining char itself            //~v6EnI~
   if (!(Plineopt & UVIOO_CSRPOSCHK))       // file data line      //~v6EnR~
    Ppcchar->attr=uviom_attr_itself(Plineopt,*Ppcht)|(attr_t)attropt;//~v6EnI~
   }                                                               //~v6EnI~
   else                                                            //~v6EnI~
   {                                                               //~v6W3I~
    Ppcchar->chars[0]=Scombaltch;     //combining char special parm//~v658I~
      if (!(Popt & UVIOMATTR_PADDING2))  //Not ovf combine char(for the case ligature not combine mode)//~v6W3I~
      {                                                            //~v6W3I~
//    if (Popt & UVIOMATTR_BREAK)   //not around csr column          //~v6W3I~//~v7enR~
//        uviom_setcchar_itself(Popt,Pucs,Ppcchar);                  //~v6W3I~//~v7enR~
		UTRACEP("%s:Not combinemode and not padding2, set altch Pucs=%04x\n",UTT,Pucs);//~v7enR~
      }                                                            //~v6W3I~
   }                                                               //~v6W3I~
  }//bse is not splitSCM                                           //~v7bLI~
      }//combinable                                                            //~v656I~//~v7bLR~//~v7bYR~
  else                                                             //~v656I~
  if (Popt & UVIOMATTR_EXT_BASEUNP)//  0x200000     //base is unprintable//~v6WeI~
  {                                                                //~v6WeI~
  		if (Scombaltch==UVIOM_ALTCHPADDING)                        //~v6WeI~
		    Ppcchar->chars[0]=Guviomdbcspad;                       //~v6WeI~
   		else                                                       //~v6WeI~
   		if (Scombaltch==UVIOM_ALTCHITSELF                          //~v6WeR~
   		||  Scombaltch==UVIOM_ALTCHSHADOW                          //~v6WeI~
   		||  UTF_COMBINEMODE()    //entered to combine1 by lineopt,same as itself//~v6WeI~
        )                                                          //~v6WeI~
   		{                                                          //~v6WeI~
    		Ppcchar->chars[0]=Pucs;     //combining char itself    //~v6WeI~
// 			if (!(Plineopt & UVIOO_CSRPOSCHK))       // file data line//~v6WeR~
// 				Ppcchar->attr=uviom_attr_itself(Plineopt,*Ppcht)|(attr_t)attropt;//~v6WeR~
   			if (Plineopt & UVIOO_CSRPOSCHK)        // file data line//~v6WeI~
    			uviom_setcchar_itself(Popt,Pucs,Ppcchar);          //~v6WeI~
   		}                                                          //~v6WeI~
   		else                                                       //~v6WeI~
   		{                                                          //~v6WeI~
   			UTRACEP("%s:UNPR+combine:NP mode\n",UTT);              //~v6WeI~
    		Ppcchar->chars[0]=Scombaltch;     //combining char special parm//~v6WeI~
      		if (!(Popt & UVIOMATTR_PADDING2))  //Not ovf combine char(for the case ligature not combine mode)//~v6WeI~
      		{                                                      //~v6WeI~
    			if (Popt & UVIOMATTR_BREAK)   //not around csr column//~v6WeI~
    				uviom_setcchar_itself(Popt,Pucs,Ppcchar);      //~v6WeI~
      		}                                                      //~v6WeI~
   		}                                                          //~v6WeI~
  }                                                                //~v6WeI~
  else                                                             //~v6WeI~
  if (Pucsbase<0x80)    //not combinable ascii                     //~v656R~
  {                                                                //~v656I~
    Ppcchar->chars[0]=Guviomdbcspad;                               //~v656I~
  }                                                                //~v656I~
  else                                                             //~v656I~
    Ppcchar->chars[0]=Pucs;                                        //~v653M~
                                                                   //~v6V5I~
  if (!swShadowDbcs)                                               //~v7bsI~
  	if (Popt & UVIOMATTR_PADDING2)  //for the case ligature not combine mode//~v6V5R~
    {                                                              //~v6V5I~
        pcchar_padding2=Ppcchar+1;                                 //~v6V5R~
	    pcchar_padding2->chars[0]=UVIOM_COMBINE_ALTCH2;            //~v6V5R~
	    pcchar_padding2->attr=(ATTR_COMBINE_FG_UCS4<<8);           //~v6V5R~
	    pcchar_padding2->attr|=ATTR_COMBINE_PADDING_NOHCOPY;//   A_DIM //padding to be dropped from hcopy//~vbzPI~
        rc=1;                                                      //~v6V5I~
    }                                                              //~v6V5I~
UTRACEP("%s:single combine parm=%x,opt=%x,rc=%d,char ucs=%x,prevucs=%x,chtype=%x,swShadowDbcs=%d\n",UTT,Scombaltch,Popt,rc,Pucs,Pucsbase,*Ppcht,swShadowDbcs);//~v6V5R~//~v7bsR~//~v7bER~
UTRACED("out Ppcchar",Ppcchar,CCHSZ*(rc+1));                      //~v653R~//~v6BZR~//~v6V5R~
//  return 0;                                                      //~v653R~//~v6V5R~
    return rc;   //outctr=1/2                                      //~v6V5R~
}//uviom_setcombine1                                               //~v653I~
//#ifdef KKK                                                       //~v7bJR~
////*******************************************************          //~v653I~//~v7bJR~
////*process combining char                                          //~v653I~//~v7bJR~
////*ret  :rc 0x01 detected combining char                           //~v653I~//~v7bJR~
////*******************************************************          //~v653I~//~v7bJR~
////int uviom_setcombine(int Popt,WUCS Pucs,chtype *Ppcht,cchar_t *Ppcchar0,cchar_t *Ppcchar,UCHAR *Ppdbcs,int Plen,int *Ppcombinectr,int *Ppwritectr)//~v653R~//~v6EmR~//~v7bJR~
////int uviom_setcombine(int Popt,int Plineopt,WUCS Pucs,chtype *Ppcht,cchar_t *Ppcchar0,cchar_t *Ppcchar,UCHAR *Ppdbcs,int Plen,int *Ppcombinectr,int *Ppwritectr)//~v6EmI~//~v6V5R~//~v7bJR~
//int uviom_setcombine(int Popt,int Plineopt,WUCS Pucs,chtype *Ppcht,cchar_t *Ppcchar0,cchar_t *Ppcchar,UCHAR *Ppdbcs,int Plen,int *Ppcombinectr,int *Ppwritectr,int *Ppmblen)//~v6V5I~//~v7bJR~
//{                                                                  //~v653I~//~v7bJR~
////  int combinectr=0,ii,attr,rc=0,outctr=0,dbcssw=0,dbcssz,opt;    //~v653R~//~v6BhR~//~v7bJR~
//    int combinectr=0,ii,rc=0,outctr=0,dbcssw=0,opt;         //~v6BhI~//~v7bJR~
////  int attro,attrn;                                               //~v656I~//~v6BhR~//~v7bJR~
////    attr_t attro,attrn;                                       //~v6BhI~//~v7bJR~
//    int setbreak=0;                                                //~v656I~//~v7bJR~
////  UCHAR *pcd;                                                    //~v653I~//~v7bJR~
//    chtype  *pct;                                                  //~v653I~//~v7bJR~
//    cchar_t *pcc,*pccpadd,*pccprev;                                         //~v653R~//~v656R~//~v7bJR~
//    WUCS    ucs,prevucs=0;                                           //~v653I~//~v656R~//~v7bJR~
//#ifdef AAA                                                         //~v6V5I~//~v7bJR~
//    UCHAR ch;                                                      //~v653I~//~v7bJR~
//#endif                                                             //~v6V5I~//~v7bJR~
//    int swcombine,mblen=0;                                         //~v6V5I~//~v7bJR~
////**************************                                       //~v653I~//~v7bJR~
//UTRACEP("%s:entry opt=%x,len=%d,ucs=%04x,dbcsid=%x\n",UTT,Popt,Plen,Pucs,*Ppdbcs);//~v653R~//~v656R~//~v7bER~//~v7bJR~
//    pcc=Ppcchar;    //output                                       //~v653R~//~v7bJR~
//    pct=Ppcht;  //input                                            //~v653I~//~v7bJR~
////  pcd=Ppdbcs;                                                    //~v653I~//~v7bJR~
//    for (;;)                                                       //~v653I~//~v7bJR~
//    {                                                              //~v653I~//~v7bJR~
////      if (pcc==Ppcchar0                                          //~v656R~//~v7bJR~
//        ||  (Popt & UVIOMSCO_FORCEBREAK)                           //~v656I~//~v7bJR~
//        ||  ((pcc-1)->attr & UVIOMATTR_BREAK)   //prev is single combine//~v656I~//~v7bJR~
//        )                                                          //~v656I~//~v7bJR~
//        {                                                          //~v656I~//~v7bJR~
//            setbreak=1;                                            //~v656I~//~v7bJR~
//            break;                                                 //~v656I~//~v7bJR~
//        }                                                          //~v656I~//~v7bJR~
////      if (UVIOM_SPLITMODE())                                     //~v656M~//~v658R~//~v7bJR~
////      if (!UTF_COMBINEMODE()) //split mode                       //~v658I~//~v6EmR~//~v7bJR~
//        if (!COMBINEMODE(Plineopt)) //split mode                   //~v6EmI~//~v7bJR~
//        {                                                          //~v6EnI~//~v7bJR~
//            setbreak=1; //keep colomn for Altch especially ITSELF mode//~v6EnI~//~v7bJR~
//            break;                                                 //~v656M~//~v7bJR~
//        }                                                          //~v6EnI~//~v7bJR~
//#ifdef KKK                                                       //~v7bJR~
//        pcc--;                                                     //~v653I~//~v7bJR~
//        pct--;                                                     //~v653I~//~v7bJR~
//        pcd--;                                                     //~v653I~//~v7bJR~
//        dbcssw=((pcc->attr & UVIOMATTR_DBCS2)!=0);         //temporary padding flag//~v653I~//~v656R~//~v7bJR~
//        if (dbcssw)                                                //~v653I~//~v7bJR~
//        {                                                          //~v653I~//~v7bJR~
//            pcc--;                                                 //~v653I~//~v7bJR~
//            pct--;                                                 //~v653I~//~v7bJR~
//            pcd--;                                                 //~v653I~//~v7bJR~
//        }                                                          //~v653I~//~v7bJR~
//        dbcssz=1+dbcssw;                                           //~v653I~//~v7bJR~
//        prevucs=pcc->chars[0];                                     //~v653I~//~v7bJR~
//#ifdef LNX                                                         //~v6V5I~//~v7bJR~
//        combinectr=uvio_getcombinectr(0,prevucs,dbcssz,pct,pcd,Plen);//~v6V5I~//~v7bJR~
//#else                                                              //~v6V5I~//~v7bJR~
//        combinectr=uvio_getcombinectr(0,prevucs,dbcssz,pcd,Plen);//~v653I~//~v656R~//~v7bJR~
//#endif                                                             //~v6V5I~//~v7bJR~
//        attro=(*pct & (A_ATTRIBUTES));                             //~v656R~//~v7bJR~
//        for (pct=Ppcht,ii=0;ii<combinectr;ii++,pct++)              //~v656I~//~v7bJR~
//        {                                                          //~v656I~//~v7bJR~
//            attrn=(*pct & (A_ATTRIBUTES));                         //~v656R~//~v7bJR~
//UTRACEP("%s:combctr=%d,attro=%x,attrn=%x\n",UTT,ii,attro,attrn);//~v656I~//~v7bvR~//~v7bJR~
//            if (attrn!=attro)                                      //~v656R~//~v7bJR~
//            {                                                      //~v656I~//~v7bJR~
//                combinectr=ii;                                     //~v656R~//~v7bJR~
//                break;                                             //~v656I~//~v7bJR~
//            }                                                      //~v656I~//~v7bJR~
//        }                                                          //~v656I~//~v7bJR~
//        if (!combinectr)                                           //~v653I~//~v7bJR~
//            break;                                                 //~v653I~//~v7bJR~
////set combine to base char                                         //~v658I~//~v7bJR~
//      if (dbcssw)   //base is dbcs                                 //~v6W9I~//~v7bJR~
//      {                                                            //~v6W9I~//~v7bJR~
//        pcc->attr=(attr_t)(pcc->attr | UVIOMATTR_EXT_COMBBASE);   //ligature:off,combinemode,combin base//~v6W9I~//~v7bJR~
//        for (pct=Ppcht,pccpadd=Ppcchar,pcd=Ppdbcs,ii=1;ii<=combinectr;ii++,pcd++,pct++)//~v6W9I~//~v7bJR~
//        {                                                          //~v6W9I~//~v7bJR~
//#ifdef FFF                                                         //~v6X5I~//~v7bJR~
//            swcombine=uviom_ISUCSWIDTH0(0,pct,pcd,2/*confirmd enough length by getcombinectr()*/,&ucs);//~v6W9I~//~v7bJR~
//#else                                                              //~v6X5I~//~v7bJR~
//            swcombine=uviom_ISUCSWIDTH0(IUW0O_COMB2SCM_COMB,pct,pcd,2/*confirmd enough length by getcombinectr()*/,&ucs);//~v6X5R~//~v7bJR~
//#endif                                                             //~v6X5I~//~v7bJR~
//            pcc->chars[ii]=ucs;                                    //~v6W9I~//~v7bJR~
//            (pcc+1)->chars[ii]=ucs;                                //~v6W9I~//~v7bJR~
//          if (UVIOM_NONSPACECOMBINEMODE()) //non spacing combining diacritical mark supported//~v6W9I~//~v7bJR~
//          {                                                        //~v6W9I~//~v7bJR~
////          attr=(*pct & A_ATTRIBUTES);                            //~v7btR~//~v7bJR~
//            attr=uviom_set_padattr(0,ATTR_COMBINE_FG_UCS4<<8);     //~v7btI~//~v7bJR~
////          attr=uviom_set_padattr(0,attr);                        //~v6W9R~//~v7bJR~
//            attr|=UVIOMATTR_PADDING;         //temporary padding flag//~v6W9I~//~v7bJR~
//            if (swcombine==2)                                      //~v6W9I~//~v7bJR~
//                attr|=UVIOMATTR_PADDING2;    //2 padding char      //~v6W9I~//~v7bJR~
//            pccpadd->attr=attr; //padding attr                     //~v6W9I~//~v7bJR~
//            pccpadd->chars[0]=Guviomdbcspad; //PADDING             //~v6W9I~//~v7bJR~
//            pccpadd++;                                             //~v6W9I~//~v7bJR~
//            outctr++;                                              //~v6W9I~//~v7bJR~
//            if (swcombine==2)                                      //~v6W9I~//~v7bJR~
//            {                                                      //~v6W9I~//~v7bJR~
//                *pccpadd=*(pccpadd-1);                             //~v6W9I~//~v7bJR~
//                pccpadd->chars[0]=UVIOM_COMBINE_ALTCH2;            //~v6W9I~//~v7bJR~
//                pccpadd->attr=uviom_set_padattr(0,ATTR_COMBINE_FG_UCS4<<8);//~v6W9I~//~v7bJR~
//                pccpadd++;                                         //~v6W9I~//~v7bJR~
//                outctr++;                                          //~v6W9I~//~v7bJR~
//            }                                                      //~v6W9I~//~v7bJR~
//          }//fc5 need 1 column for nonspace char                   //~v6W9I~//~v7bJR~
//          mblen++;                                                 //~v6W9I~//~v7bJR~
//          if (swcombine==2)                                        //~v6W9I~//~v7bJR~
//            pcd++,pct++,mblen++;    //ucs4 width0                  //~v6W9I~//~v7bJR~
//        }                                                          //~v6W9I~//~v7bJR~
//      }//base dbcs                                                 //~v6W9I~//~v7bJR~
//      else                                                         //~v6W9I~//~v7bJR~
//      {                                                            //~v6W9I~//~v7bJR~
//        cchar_t *pccbase=pcc;                                      //~v7bvR~//~v7bJR~
//        pccbase->attr|=UVIOMATTR_EXT_COMBBASE;// 0x040000;    //ligature:off,combinemode,combin base//~v7bvI~//~v7bJR~
//        for (pct=Ppcht,pccpadd=Ppcchar,pcd=Ppdbcs,ii=1;ii<=combinectr;ii++,pcd++,pct++)//~v6W5I~//~v7bJR~
//        {                                                          //~v6W5I~//~v7bJR~
//#ifdef HHH                                                         //~v7bvI~//~v7bJR~
//            cchar_t *pccpadd0;                                     //~v6W5I~//~v7bJR~
//            attr_t attr0;                                          //~v6W5I~//~v7bJR~
//#endif                                                             //~v7bvM~//~v7bJR~
//            //*******************                                  //~v6W5I~//~v7bJR~
//#ifdef FFF                                                         //~v6X5I~//~v7bJR~
//            swcombine=uviom_ISUCSWIDTH0(0,pct,pcd,2/*confirmd enough length by getcombinectr()*/,&ucs);//~v6W5I~//~v7bJR~
//#else                                                              //~v6X5I~//~v7bJR~
//            swcombine=uviom_ISUCSWIDTH0(IUW0O_COMB2SCM_COMB,pct,pcd,2/*confirmd enough length by getcombinectr()*/,&ucs);//~v6X5I~//~v7bJR~
//#endif                                                             //~v6X5I~//~v7bJR~
////          pcc->attr|=UVIOMATTR_EXT_COMBBASE;// 0x040000;    //ligature:off,combinemode,combin base//~v6W5R~//~v7bvR~//~v7bJR~
//#ifdef HHH                                                         //~v7bvI~//~v7bJR~
//            if (ii==1)                                             //~v6W5I~//~v7bJR~
//            {                                                      //~v6W5I~//~v7bJR~
//                pccpadd0=pccpadd;                                  //~v6W5R~//~v7bJR~
//                attr0=attro;                                       //~v6W5R~//~v7bJR~
//                pccpadd0->attr=attr0;  //padding flag is for write with base//~v6W5R~//~v6WbR~//~v7bJR~
////              pccpadd0->attr=attr0|UVIOMATTR_EXT_DMYBASE; //setcombine() is not for ligature    //added "A0" entry for combining//~v6WbR~//~v7bJR~
//                pccpadd0->chars[0]=COMBAINE_BASE_SPLIT_ITSELF;  //0xa0     //u00a0 base for combining char when split itself//~v6W5I~//~v7bJR~
//                pccpadd++;                                         //~v6W5I~//~v7bJR~
//                outctr++;                                          //~v6W5I~//~v7bJR~
//                UTRACEP("%s:set dummy base-A0,ii=%d,outctr=%d,ucs=0x%04x\n",UTT,ii,outctr,ucs);//~vbzPI~//~v7bJR~
//                                                                   //~vbzPI~//~v7bJR~
//            }                                                      //~v6W5I~//~v7bJR~
//            pccpadd0->chars[ii]=ucs;                               //~v6W5R~//~v7bJR~
////          attr=attr0|UVIOMATTR_PADDING;         //temporary padding flag//~v6W5I~//~v6X2R~//~v7bJR~
//            attr=uviom_set_padattr(0,attr0)|UVIOMATTR_PADDING;     //~v6X2I~//~v7bJR~
//            if (swcombine==2)                                      //~v6W5I~//~v7bJR~
//                attr|=UVIOMATTR_PADDING2;    //2 padding char      //~v6W5I~//~v7bJR~
//            pccpadd->attr=attr; //padding attr                     //~v6W5I~//~v7bJR~
//            pccpadd->chars[0]=Guviomdbcspad; //PADDING             //~v6W5I~//~v7bJR~
//            pccpadd++;                                             //~v6W5I~//~v7bJR~
//            outctr++;                                              //~v6W5I~//~v7bJR~
//            if (swcombine==2)                                      //~v6W5I~//~v7bJR~
//            {                                                      //~v6W5I~//~v7bJR~
//                *pccpadd=*(pccpadd-1);                             //~v6W5I~//~v7bJR~
//#ifdef AAA  //write space                                          //~v6W5I~//~v7bJR~
//                pccpadd->chars[0]=UVIOM_COMBINE_ALTCH2;            //~v6W5I~//~v7bJR~
//#endif                                                             //~v6W5I~//~v7bJR~
//                pccpadd++;                                         //~v6W5I~//~v7bJR~
//                outctr++;                                          //~v6W5I~//~v7bJR~
//            }                                                      //~v6W5I~//~v7bJR~
//            mblen++;                                               //~v6W5R~//~v7bJR~
//            if (swcombine==2)                                      //~v6W5R~//~v7bJR~
//                pcd++,pct++,mblen++;    //ucs4 width0              //~v6W5R~//~v7bJR~
//#else //HHH                                                        //~v7bvI~//~v7bJR~
//            pccbase->chars[ii]=ucs;  //combining char to base      //~v7bvI~//~v7bJR~
//            pccbase->attr&=(attr_t)(~UVIOMATTR_EXT_COMBBASE);   //combined, not base ucs only//~v7bvI~//~v7bJR~
//            pccpadd->attr=uviom_set_padattr(0,ATTR_COMBINE_FG_UCS4<<8);//~v7bvI~//~v7bJR~
//            pccpadd->attr|=ATTR_COMBINE_PADDING_NOHCOPY;//   A_DIM //padding to be dropped from hcopy//~v7bvR~//~v7bJR~
//            pccpadd->chars[0]=Guviomdbcspad; //PADDING             //~v7bvI~//~v7bJR~
//            UTRACEP("%s:sbcs padding base=0x%04x,combinining=0x%04x\n",UTT,pccbase->chars[0],ucs);//~v7bvR~//~v7bJR~
//            pccpadd++;                                             //~v7bvI~//~v7bJR~
//            outctr++;                                              //~v7bvI~//~v7bJR~
//            pcd++,pct++,mblen++;                                   //~v7bvI~//~v7bJR~
//#endif                                                             //~v7bvI~//~v7bJR~
//        }                                                          //~v6W5I~//~v7bJR~
//      }//base ! dbcs                                               //~v6W9I~//~v7bJR~
//#else //KKK                                                      //~v7bJR~
//        int color=(*pct & UVIOMATTR_COLORMASK);//    0xFF00      //~v7bJR~
//        int opt2=0;                                              //~v7bJR~
//        if (UDBCSCHK_DBCS1STUCS2NWO(*Ppdbcs))                    //~v7bJR~
//            opt2|=SBEO_2CELL;                                    //~v7bJR~
//        cchar_t *pccbase=setBaseEntry(opt2,Ppcchar0,Ppcchar,color,Pucs,&combinectr);//~v7bJR~
//        if (!pccbase)                                            //~v7bJR~
//            break;                                               //~v7bJR~
//        mblen=0;                                                 //~v7bJR~
//#ifdef AAA                                                       //~v7bJR~
//        for (ii=0;ii<2;ii++)                                     //~v7bJR~
//        {                                                        //~v7bJR~
//            pccpadd=Ppcchar;                                     //~v7bJR~
//            pccpadd->chars[0]=Guviomdbcspad; //PADDING           //~v7bJR~
//            pccpadd->attr=uviom_set_padattr(0,ATTR_COMBINE_FG_UCS4<<8);//~v7bJR~
//            pccpadd->attr|=UVIOMATTR_EXT_PADDCOMB;  // 0x04000000     //padding beteen base and combining//~v7bJR~
//            pccpadd->attr|=ATTR_COMBINE_PADDING_NOHCOPY;//   A_DIM //padding to be dropped from hcopy//~v7bJR~
//            mblen++;                                             //~v7bJR~
//            UTRACEP("%s:padding base=0x%04x,combinining ucs=0x%04x,combinectr=%d\n",UTT,pccbase->chars[0],Pucs,combinectr);//~v7bJR~
//            if (!(Popt & UVIOMSCO_WIDESBCS))                     //~v7bJR~
//                break;                                           //~v7bJR~
//        }                                                        //~v7bJR~
//#endif                                                           //~v7bJR~
//        outctr=mblen;                                            //~v7bJR~
//UTRACED("setcombine",Ppcchar,outctr*(int)sizeof(cchar_t));//~v653R~//~v6BhR~//~v7bJR~
//#endif                                                           //~v7bJR~
//        rc=1;                                                      //~v653I~//~v7bJR~
//        break;                                                     //~v653I~//~v7bJR~
//    }                                                              //~v653I~//~v7bJR~
//    if (!rc)                                                       //~v653I~//~v7bJR~
////not combine, write                                             //~v7bJR~
//    {                                                              //~v653I~//~v7bJR~
//        opt=0;                                                     //~v653I~//~v7bJR~
//        if (setbreak)                                              //~v656R~//~v7bJR~
//            opt|=UVIOMATTR_BREAK;                                  //~v653I~//~v7bJR~
////      if (Popt & UVIOMSCO_SETATTR)                               //~v656I~//~v658R~//~v7bJR~
////      if (UTF_COMBINEMODE())  //f23 set green if split mode      //~v658I~//~v6EmR~//~v7bJR~
////      if (COMBINEMODE(Plineopt))  //f23 set green if split mode  //~v6EmR~//~v7bJR~
//          if (!(Popt & UVIOMSCO_NOSETATTR))                        //~v658I~//~v7bJR~
//            opt|=UVIOMATTR_SETATTR; //set fg:green                 //~v656M~//~v7bJR~
//#ifdef KKK                                                       //~v7bJR~
//        for (pccprev=Ppcchar-1;pccprev>=Ppcchar0;pccprev--)        //~v656I~//~v7bJR~
//        {                                                          //~v656I~//~v7bJR~
//            prevucs=pccprev->chars[0];                             //~v656I~//~v7bJR~
//          if (!(pccprev->attr & UVIOMATTR_PADDING)) //padding space//~v6WaR~//~v7bJR~
//            if (UTF_COMBINABLE(prevucs))                           //~v656R~//~v7bJR~
//            {                                                      //~v658I~//~v7bJR~
//                if (pccprev->attr & UVIOMATTR_DBCS12)  //dbcs      //~v658R~//~v7bJR~
//                    opt|=UVIOMATTR_BASEDBCS;                       //~v658I~//~v7bJR~
//                break;                                             //~v656I~//~v7bJR~
//            }                                                      //~v658I~//~v7bJR~
//            prevucs=0;                                             //~v656I~//~v7bJR~
//        }                                                          //~v656I~//~v7bJR~
//#else                                                            //~v7bJR~
//        int colorCombining=(*pct & UVIOMATTR_COLORMASK);//    0xFF00//~v7bJR~
//        int opt2=0;                                              //~v7bJR~
//        if (UDBCSCHK_DBCS1STUCS2NWO(*Ppdbcs))                    //~v7bJR~
//            opt2|=SBEO_2CELL;                                    //~v7bJR~
//        pccprev=setBaseEntry(opt2,Ppcchar0,Ppcchar,colorCombining,0/*Pucs=0:No set combining*/,0/*Ppcombctr*/);//~v7bJR~
//        if (pccprev)                                             //~v7bJR~
//        {                                                        //~v7bJR~
//            prevucs=pccprev->chars[0];                           //~v7bJR~
//            if (pccprev->attr & UVIOMATTR_DBCS12)  //dbcs        //~v7bJR~
//                opt|=UVIOMATTR_BASEDBCS;                         //~v7bJR~
//            if (pccprev->attr & UVIOMATTR_EXT_WIDESBCS)  //dbcs  //~v7bJR~
//                opt|=UVIOMATTR_EXT_BASEWIDE;                     //~v7bJR~
//        }                                                        //~v7bJR~
//#endif                                                           //~v7bJR~
////      swcombine=(UDBCSCHK_ISUCSWIDTH0(*Ppdbcs)?1:2);  //2 for ucs4 width0//~v6V5M~//~v7bBR~//~v7bJR~
//        swcombine=uviom_ISUCSWIDTH0(IUW0O_COMB2SCM_COMB,Ppcht,Ppdbcs,Plen/*confirmd enough length by getcombinectr()*/,&ucs);//~v7bBI~//~v7bJR~
//        if (swcombine==2)                                          //~v6V5I~//~v7bJR~
//            opt|=UVIOMATTR_PADDING2;//ucs4 width0                  //~v6V5I~//~v7bJR~
//        if (Popt & UVIOMSCO_BASEUNP) //base unprintable(":;")      //~v6WeM~//~v7bJR~
//            opt|=UVIOMATTR_EXT_BASEUNP;//base is inprintable       //~v6WeM~//~v7bJR~
//        if (Popt & UVIOMSCO_WIDESBCS)                            //~v7bJR~
//            opt|=UVIOMATTR_EXT_WIDESBCS;                         //~v7bJR~
////      uviom_setcombine1(opt,Pucs,prevucs,Ppcht,Ppcchar);                 //~v653R~//~v6EmR~//~v7bJR~
////ovf combine or shaddow generated                                 //~v6W5I~//~v7bJR~
//        outctr=1+                                                  //~v6V5I~//~v7bJR~
////      uviom_setcombine1(opt,Plineopt,Pucs,prevucs,Ppcht,Ppcchar);//~v6EmI~//~v6W6R~//~v7bJR~
//        uviom_setcombine1(opt,Plineopt,Pucs,prevucs,Ppcht,Ppcchar,Ppcchar0);//~v6W6I~//~v7bJR~
//        combinectr=1;   //loop ctr;                                //~v653R~//~v7bJR~
//        mblen=1+(swcombine==2); //2 for ucs4 width0                //~v6V5I~//~v7bJR~
////      outctr=1;                                                  //~v653I~//~v6V5R~//~v7bJR~
//        if (outctr>1) //non spacing combining diacritical mark supported//~v6V5R~//~v7bJR~
//            pccpadd++;                                             //~v6V5I~//~v7bJR~
//    }                                                              //~v653I~//~v7bJR~
//    *Ppcombinectr=combinectr;                                      //~v653R~//~v7bJR~
//    *Ppwritectr=outctr;                                            //~v653R~//~v7bJR~
//    *Ppmblen=mblen;                                                //~v6V5I~//~v7bJR~
//UTRACEP("setcombine rc=%d,len=%d,ucs=%04x,combinectr=%d,dbcssw=%d,outctr=%d,out mblen=%d\n",rc,Plen,Pucs,combinectr,dbcssw,outctr,mblen);//~v653R~//~v6V5R~//~v7bJR~
//    return rc;                                                     //~v653I~//~v7bJR~
//}//uviom_setcombine                                                //~v653I~//~v7bJR~
//#endif //KKK                                                     //~v7bJR~
//*******************************************************          //~v653I~
//*process combining char                                          //~v653I~
//*ret  :rc 0x01 detected combining char                           //~v653I~
//*******************************************************          //~v653I~
//int uviom_setcombine(int Popt,WUCS Pucs,chtype *Ppcht,cchar_t *Ppcchar0,cchar_t *Ppcchar,UCHAR *Ppdbcs,int Plen,int *Ppcombinectr,int *Ppwritectr)//~v653R~//~v6EmR~
//int uviom_setcombine(int Popt,int Plineopt,WUCS Pucs,chtype *Ppcht,cchar_t *Ppcchar0,cchar_t *Ppcchar,UCHAR *Ppdbcs,int Plen,int *Ppcombinectr,int *Ppwritectr)//~v6EmI~//~v6V5R~
int uviom_setcombine(int Popt,int Plineopt,WUCS Pucs,chtype *Ppcht,cchar_t *Ppcchar0,cchar_t *Ppcchar,UCHAR *Ppdbcs,int Plen,int *Ppcombinectr,int *Ppwritectr,int *Ppmblen)//~v6V5I~
{                                                                  //~v653I~
//  int combinectr=0,ii,attr,rc=0,outctr=0,dbcssw=0,dbcssz,opt;    //~v653R~//~v6BhR~
    int combinectr=0,ii,rc=0,outctr=0,opt;         //~v6BhI~//~v7bJR~//~v7bZR~
//  int attro,attrn;                                               //~v656I~//~v6BhR~
//    attr_t attro,attrn;                                       //~v6BhI~//~v7bJR~
    int setbreak=0;                                                //~v656I~
//  UCHAR *pcd;                                                    //~v653I~//~v7bJR~
    chtype  *pct;                                                  //~v653I~
    cchar_t *pcc,*pccpadd,*pccprev;                                         //~v653R~//~v656R~
    WUCS    /*ucs,*/prevucs=0;                                           //~v653I~//~v656R~//~v7bVR~
#ifdef AAA                                                         //~v6V5I~
    UCHAR ch;                                                      //~v653I~
#endif                                                             //~v6V5I~
	int /*swcombine,*/mblen=0;                                         //~v6V5I~//~v7bVR~
//**************************                                       //~v653I~
UTRACEP("%s:entry opt=%x,len=%d,ucs=%04x,dbcsid=%x\n",UTT,Popt,Plen,Pucs,*Ppdbcs);//~v653R~//~v656R~//~v7bER~
UTRACED("entry Pcchar",Ppcchar,CCHSZ);                             //~v7bJI~
	pcc=Ppcchar;	//output                                       //~v653R~
	pct=Ppcht;	//input                                            //~v653I~
//	pcd=Ppdbcs;                                                    //~v653I~//~v7bJR~
    for (;;)                                                       //~v653I~
    {                                                              //~v653I~
#ifndef JJJ    	                                                   //~v7f4I~
		if (Popt & UVIOMSCO_W0NOCOMB)//      0x0100  //width=0 not combining char//~v7f4I~
        {                                                          //~v7f4I~
        	setbreak=1;                                            //~v7f4I~
        	break;                                                 //~v7f4I~
        }                                                          //~v7f4I~
#endif                                                             //~v7f4I~
//  	if (pcc==Ppcchar0                                          //~v656R~//~v7bJR~
    	if (pcc==ScchTop                                           //~v7bJR~
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
	    int color=(*pct & UVIOMATTR_COLORMASK);//    0xFF00        //~v7bJI~
        int opt2=0;                                                //~v7bJI~
		if (UDBCSCHK_DBCS1STUCS2NWO(*Ppdbcs))                      //~v7bJI~
        	opt2|=SBEO_2CELL;                                      //~v7bJI~
        cchar_t *pccbase=setBaseEntry(opt2,Ppcchar0,Ppcchar,color,Pucs,&combinectr);//~v7bJR~
        if (!pccbase)                                              //~v7bJI~
        	break;                                                 //~v7bJR~
        mblen=0;                                                   //~v7bJR~
        pccpadd=Ppcchar;                                           //~v7bQI~
        for (ii=0;ii<2;ii++)                                       //~v7bJI~
        {                                                          //~v7bJI~
//          pccpadd=Ppcchar;                                       //~v7bJR~//~v7bQR~
            int swAltch=0;                                         //~v7c4I~
          if (ii==1)                                               //~v7bQI~
          {                                                        //~v7bWI~
            pccpadd->chars[0]=UVIOM_COMBINE_ALTCH2; //'.'          //~v7bQI~
          }                                                        //~v7bWI~
          else                                                     //~v7bQI~
          {                                                        //~v7bWR~
//          pccpadd->chars[0]=Guviomdbcspad; //PADDING             //~v7bJI~//~v7bWR~
            pccpadd->chars[0]=uviom_getAltFormat(0,Pucs,Guviomdbcspad);//~v7bWI~
            if (pccpadd->chars[0]!=Guviomdbcspad)                  //~v7c4R~
            	swAltch=1;	//ZWJ etc                              //~v7c4I~
          }                                                        //~v7bWR~
            pccpadd->attr=uviom_set_padattr(0,ATTR_COMBINE_FG_UCS4<<8);//~v7bJI~
            pccpadd->attr|=UVIOMATTR_EXT_PADDCOMB;	// 0x04000000     //padding beteen base and combining//~v7bJI~
            pccpadd->attr|=ATTR_COMBINE_PADDING_NOHCOPY;//   A_DIM //padding to be dropped from hcopy//~v7bJI~
            if (swAltch)	//ZWJ etc                              //~v7c4I~
            {                                                      //~v7c4I~
	            pccpadd->attr|=UVIOMATTR_EXT_ALTCH;	// 0x04000000     //padding beteen base and combining//~v7c4R~
        		UTRACEP("%s:ALTCH set EXT_ALTCH char[0]=0x%04x,attr=0x%04x\n",UTT,pccpadd->chars[0],pccpadd->attr);//~v7c4R~
        	}                                                      //~v7c4I~
        	UTRACEP("%s:PADDCOMB char[0]=0x%04x,attr=0x%04x\n",UTT,pccpadd->chars[0],pccpadd->attr);//~v7ehR~
            mblen++;                                               //~v7bJI~
            UTRACEP("%s:padding base=0x%04x,combinining ucs=0x%04x,combinectr=%d\n",UTT,pccbase->chars[0],Pucs,combinectr);//~v7bJR~
//	        if (!(Popt & UVIOMSCO_WIDESBCS))                       //~v7bJI~//~v7bQR~
//          if (!(pccbase->attr & UVIOMATTR_DBCS12))  //dbcs       //~v7bQR~
    		if (!(Popt & UVIOMSCO_COMB2SCM))//        0x80  //u3099,309a:dbcs//~v7bQR~
            	break;                                             //~v7bJI~
            pccpadd++;                                             //~v7bQI~
        }                                                          //~v7bJI~
        outctr=mblen;                                              //~v7bJI~
UTRACED("setcombine",Ppcchar,outctr*(int)sizeof(cchar_t));//~v653R~//~v6BhR~//~v7bJR~
        rc=1;                                                      //~v653I~
        break;                                                     //~v653I~
    }                                                              //~v653I~
    if (!rc)                                                       //~v653I~
//not combine, write                                               //~v7bJI~
    {                                                              //~v653I~
    	opt=0;                                                     //~v653I~
        if (setbreak)                                              //~v656R~
	        opt|=UVIOMATTR_BREAK;                                  //~v653I~
//      if (Popt & UVIOMSCO_SETATTR)                               //~v656I~//~v658R~
//      if (UTF_COMBINEMODE())	//f23 set green if split mode      //~v658I~//~v6EmR~
//      if (COMBINEMODE(Plineopt))	//f23 set green if split mode  //~v6EmR~
      	  if (!(Popt & UVIOMSCO_NOSETATTR))                        //~v658I~
	        opt|=UVIOMATTR_SETATTR;	//set fg:green                 //~v656M~
	    int colorCombining=(*pct & UVIOMATTR_COLORMASK);//    0xFF00//~v7bJR~
        int opt2=0;                                                //~v7bJI~
		if (UDBCSCHK_DBCS1STUCS2NWO(*Ppdbcs))	                   //~v7bJI~
        	opt2|=SBEO_2CELL;                                      //~v7bJI~
#ifndef JJJ                                                        //~v7f4I~
	  if (Popt & UVIOMSCO_W0NOCOMB)//      0x0100  //width=0 not combining char//~v7f4I~
      {                                                            //~v7f4I~
        	pccprev=0;                                             //~v7f4I~
            UTRACEP("%s:W0NOCOMB Pucs=%04x\n",UTT,Pucs);           //~v7f4I~
      }                                                            //~v7f4I~
      else                                                         //~v7f4I~
#endif                                                             //~v7f4I~
		pccprev=setBaseEntry(opt2,Ppcchar0,Ppcchar,colorCombining,0/*Pucs=0:No set combining*/,0/*Ppcombctr*/);//~v7bJR~
        if (pccprev)                                               //~v7bJI~
        {                                                          //~v7bJI~
//      	prevucs=pccprev->chars[0];                             //~v7bJI~//~v7c4R~
#ifdef NNN                                                         //~v7c4I~
        	prevucs=getBaseUCS(0,pccprev);                         //~v7c4I~
#else                                                              //~v7c4I~
        	prevucs=pccprev->chars[0];                             //~v7c4I~
#endif                                                             //~v7c4I~
            if (pccprev->attr & UVIOMATTR_DBCS12)  //dbcs          //~v7bJR~
                opt|=UVIOMATTR_BASEDBCS;                           //~v7bJR~
            if (pccprev->attr & UVIOMATTR_EXT_WIDESBCS)  //dbcs    //~v7bJR~
                opt|=UVIOMATTR_EXT_BASEWIDE;                       //~v7bJR~
        }                                                          //~v7bJI~
//      swcombine=(UDBCSCHK_ISUCSWIDTH0(*Ppdbcs)?1:2);	//2 for ucs4 width0//~v6V5M~//~v7bBR~
//  	swcombine=uviom_ISUCSWIDTH0(IUW0O_COMB2SCM_COMB,Ppcht,Ppdbcs,Plen/*confirmd enough length by getcombinectr()*/,&ucs);//~v7bBI~//~v7bVR~
//      if (swcombine==2)                                          //~v6V5I~//~v7bVR~
    	if (Popt & UVIOMSCO_COMB2SCM)//        0x80  //u3099,309a:dbcs//~v7bVI~
	        opt|=UVIOMATTR_PADDING2;//ucs4 width0                  //~v6V5I~
        if (Popt & UVIOMSCO_BASEUNP) //base unprintable(":;")      //~v6WeM~
	        opt|=UVIOMATTR_EXT_BASEUNP;//base is inprintable       //~v6WeM~
        if (Popt & UVIOMSCO_WIDESBCS)                              //~v7bJI~
	        opt|=UVIOMATTR_EXT_WIDESBCS;                           //~v7bJI~
//      uviom_setcombine1(opt,Pucs,prevucs,Ppcht,Ppcchar);                 //~v653R~//~v6EmR~
//ovf combine or shaddow generated                                 //~v6W5I~
#ifndef JJJ                                                        //~v7f4I~
	  	if (Popt & UVIOMSCO_W0NOCOMB)//      0x0100  //width=0 not combining char//~v7f4I~
      	{                                                          //~v7f4I~
        	SswComb1W0NOCOMB=1;	//parm to setcombine1              //~v7f4R~
      	}                                                          //~v7f4I~
#endif                                                             //~v7f4I~
        outctr=1+                                                  //~v6V5I~
//      uviom_setcombine1(opt,Plineopt,Pucs,prevucs,Ppcht,Ppcchar);//~v6EmI~//~v6W6R~
        uviom_setcombine1(opt,Plineopt,Pucs,prevucs,Ppcht,Ppcchar,Ppcchar0);//~v6W6I~
#ifndef JJJ                                                        //~v7f4I~
        SswComb1W0NOCOMB=0;	//parm to setcombine1                  //~v7f4R~
#endif                                                             //~v7f4I~
        combinectr=1;   //loop ctr;                                //~v653R~
//      mblen=1+(swcombine==2);	//2 for ucs4 width0                //~v6V5I~//~v7bVR~
        mblen=1+((Popt & UVIOMSCO_COMB2SCM)!=0);//        0x80  //u3099,309a:dbcs//~v7bVI~
//      outctr=1;                                                  //~v653I~//~v6V5R~
        if (outctr>1) //non spacing combining diacritical mark supported//~v6V5R~
            pccpadd++;                                             //~v6V5I~
    }                                                              //~v653I~
    *Ppcombinectr=combinectr;                                      //~v653R~
    *Ppwritectr=outctr;                                            //~v653R~
    *Ppmblen=mblen;                                                //~v6V5I~
UTRACEP("%s: rc=%d,len=%d,ucs=%04x,combinectr=%d,outctr=%d,out mblen=%d\n",UTT,rc,Plen,Pucs,combinectr,outctr,mblen);//~v653R~//~v6V5R~//~v7bZR~//~v7c8R~
    return rc;                                                     //~v653I~
}//uviom_setcombine                                                //~v653I~
//#endif                                                           //~v653R~
#ifdef RRR                                                         //~v6W0R~//~v6W2R~
//*******************************************************          //~v6W0I~
//*process SpacingCombiningMark                                    //~v6W0I~
//*ret  :rc 1/2 done and prev is sbcs or dbcs                      //~v6W0I~
//*******************************************************          //~v6W0I~
int uviom_setcombineSCM(int Popt,WUCS Pucs,cchar_t *Ppcchar0,cchar_t *Ppcchar,int *Ppwritelen)//~v6W0I~//~v6W2R~
{                                                                  //~v6W0I~
    int rc=0,dbcssw,backctr=1;                                     //~v6W0R~
    cchar_t *pcc;                                                  //~v6W0I~
    cchar_t *pccout;                                               //~v6W2I~
    WUCS    prevucs=0;                                             //~v6W0R~
    int writelen=0;                                                //~v6W2I~
//**************************                                       //~v6W0I~
	pcc=Ppcchar;	//output                                       //~v6W0I~
    rc=0;                                                          //~v6W0I~
    for (;;)                                                       //~v6W0I~
    {                                                              //~v6W0M~
// 		if (pcc<=Ppcchar0)                                         //~v6W0R~//~v7bJR~
   		if (pcc<=ScchTop)                                          //~v7bJR~
        	break;                                                 //~v6W0I~
        pccout=Ppcchar;                                            //~v6W2R~
    	pcc--;                                                     //~v6W0I~
        prevucs=pcc->chars[0];                                     //~v6W0I~
        if (prevucs==' ' && (pcc->attr & UVIOMATTR_PADDING)) //      0x08         //temporary padding flag//~v6W2R~//~v6W3R~//~v6WuR~
        {                                                          //~v6W0I~
            pccout=pcc;                                            //~v6W2M~
        	pcc--;                                                 //~v6W0I~
            backctr++;                                             //~v6W0I~
        }                                                          //~v6W0I~
// 		if (pcc<=Ppcchar0)                                         //~v6W0I~//~v7bJR~
   		if (pcc<=ScchTop)                                          //~v7bJR~
        	break;                                                 //~v6W0I~
        dbcssw=((pcc->attr & UVIOMATTR_DBCS2)!=0);         //temporary padding flag//~v6W0I~
        if (dbcssw)                                                //~v6W0I~
        {                                                          //~v6W0I~
        	pcc--;                                                 //~v6W0I~
            backctr++;                                             //~v6W0I~
        }                                                          //~v6W0I~
// 		if (pcc<=Ppcchar0)                                         //~v6W0I~//~v7bJR~
   		if (pcc<=ScchTop)                                          //~v7bJR~
        	break;                                                 //~v6W0I~
        prevucs=pcc->chars[0];                                     //~v6W0I~
#ifdef AAA                                                         //~v6W2I~
        if (UTF_COMBINABLE(prevucs) && !pcc->chars[1])             //~v6W0I~
        {                                                          //~v6W0I~
        	pcc->chars[1]=Pucs;                                    //~v6W0I~
	        if (dbcssw)                                            //~v6W0I~
            {                                                      //~v6W0I~
	        	pcc++;                                             //~v6W0I~
	        	pcc->chars[1]=Pucs;                                //~v6W0I~
            }                                                      //~v6W0I~
            rc=backctr;                                            //~v6W0R~
        }                                                          //~v6W0I~
#else                                                              //~v6W2I~
        if (UTF_COMBINABLE(prevucs))                               //~v6W2I~
        {                                                          //~v6W2I~
	        *pccout=*pcc;                                          //~v6W2R~
        	pccout->chars[0]=0x200d;                               //~v6W2R~
        	pccout->attr=(pccout->attr & UVIOMATTR_COLORMASK);         //temporary padding flag//~v6W2R~
            *(pccout+1)=*pccout;                                   //~v6W2R~
            pccout++;                                              //~v6W2R~
        	pccout->chars[0]=Pucs;                                 //~v6W2R~
            pccout++;                                              //~v6W2I~
            writelen=PTRDIFF(pccout,Ppcchar)/(int)sizeof(cchar_t); //~v6W2R~
        }                                                          //~v6W2I~
#endif                                                             //~v6W2I~
        break;                                                     //~v6W0I~
    }                                                              //~v6W0I~
    if (Ppwritelen)                                                //~v6W2I~
    	*Ppwritelen=writelen;                                      //~v6W2I~
UTRACEP("%s:rc=%d,writelen=%d,ucs=%04x,prevucs=%04x,dbcssw=%d,writelen=%d,Ppcchar0=%p,Ppcchar=%p\n",UTT,rc,backctr,Pucs,prevucs,dbcssw,writelen,Ppcchar0,Ppcchar);//~v6W0R~//~v6W2R~//~v7bER~
UTRACED("out cchar",Ppcchar,writelen*(int)sizeof(cchar_t));        //~v6WuI~
    return rc;                                                     //~v6W0I~
}//uviom_setcombineSCM                                             //~v6W0R~
#endif //RRR                                                       //~v6W0M~
//#ifdef RRR                                                       //~v6WuR~
//#ifdef FFF                                                         //~v6X5I~//~v7bJR~
////*******************************************************          //~v6X5I~//~v7bJR~
////*process COMB2SCM like as combining when prev is combinable UNOCMB:COM/SPLIT//~v6X5I~//~v7bJR~
////*Pswcombine:0:COMB, 1:SPLIT                                      //~v6X5I~//~v7bJR~
////*support only 1 comb2scm                                         //~v6X5I~//~v7bJR~
////*******************************************************          //~v6X5I~//~v7bJR~
//int uviom_setcombineSCM_COMB2SCM(int Popt,int Pswcombine,int Pucs,cchar_t *Ppcchar,int *Ppwritelen)//~v6X5R~//~v7bJR~
//{                                                                  //~v6X5I~//~v7bJR~
//    cchar_t *pcc;                                                  //~v6X5I~//~v7bJR~
//    int writelen=2,dbcssw,rc=0;                                    //~v6X5R~//~v7bJR~
////**************************                                       //~v6X5I~//~v7bJR~
//    pcc=Ppcchar;    //output                                       //~v6X5I~//~v7bJR~
//    if (!Pswcombine) //combinemode(not top of line)                //~v6X5I~//~v7bJR~
//    {                                                              //~v6X5I~//~v7bJR~
//        pcc--;                                                     //~v6X5I~//~v7bJR~
//        pcc->chars[1]=Pucs;                                        //~v6X5I~//~v7bJR~
//        dbcssw=pcc->attr & UVIOMATTR_DBCS2;   //1st of dbcs        //~v6X5I~//~v7bJR~
//        if (dbcssw)                                                //~v6X5I~//~v7bJR~
//        {                                                          //~v6X5I~//~v7bJR~
//            pcc--;                                                 //~v6X5I~//~v7bJR~
//            pcc->chars[1]=Pucs;                                    //~v6X5I~//~v7bJR~
//        }                                                          //~v6X5I~//~v7bJR~
//        Ppcchar->chars[0]=' ';                                     //~v6X5R~//~v7bJR~
//        *(Ppcchar+1)=*Ppcchar;                                     //~v6X5R~//~v7bJR~
//        UTRACED("out cchar",pcc,PTRDIFF(Ppcchar,pcc)+writelen*(int)sizeof(cchar_t));//~v6X5R~//~v7bJR~
//    }                                                              //~v6X5I~//~v7bJR~
//    else //split                                                   //~v6X5R~//~v7bJR~
//    {                                                              //~v6X5I~//~v7bJR~
//        pcc->chars[0]=COMBAINE_BASE_SPLIT_ITSELF;   //0xa0     //u00a0 base for combining char when split itself//~v6X5I~//~v7bJR~
//        pcc->chars[1]=Pucs;                                        //~v6X5I~//~v7bJR~
//        *(pcc+1)=*pcc;                                             //~v6X5I~//~v7bJR~
//        pcc++;                                                     //~v6X5I~//~v7bJR~
//#ifndef AAA                                                        //~v6X5R~//~v7bJR~
//        (pcc-1)->attr|=UVIOMATTR_DBCS1;    //1st of dbcs           //~v6X5R~//~v7bJR~
//        pcc->attr|=UVIOMATTR_DBCS2;   //1st of dbcs                //~v6X5R~//~v7bJR~
//#else                                                              //~v6X5I~//~v7bJR~
//        pcc->chars[1]=' ';                                         //~v6X5I~//~v7bJR~
//#endif                                                             //~v6X5I~//~v7bJR~
//        UTRACEP("%s:set dummy base-A0 ucs=0x%04x\n",UTT,Pucs);     //~vbzPI~//~v7bJR~
//        UTRACED("%s:out cchar",Ppcchar,writelen*(int)sizeof(cchar_t));//~v6X5R~//~vbzPR~//~v7bJR~
//    }                                                              //~v6X5I~//~v7bJR~
//    *Ppwritelen=writelen;                                          //~v6X5I~//~v7bJR~
//UTRACEP("%s: rc=%d,ucs=%06x,writelen=%d,swcombine=%d\n",UTT,rc,Pucs,writelen,Pswcombine);//~v6X5R~//~v7bJR~
//    return rc;                                                     //~v6X5I~//~v7bJR~
//}//uviom_setcombineSCM_COMB2SCM                                    //~v6X5I~//~v7bJR~
//#endif                                                             //~v6X5I~//~v7bJR~
//#ifdef JJJ                                                         //~v7bEI~//~v7bJR~
////*******************************************************          //~v6W0I~//~v7bJR~
////*process SpacingCombiningMark                                    //~v6W0I~//~v7bJR~
////*combinable prev is nor combining and combinable                 //~v6WuI~//~v7bJR~
////*ret  :1/2(NP):attr changed                                      //~v6WuR~//~v7bJR~
////*******************************************************          //~v6W0I~//~v7bJR~
////int uviom_setcombineSCM(int Plineopt,int Pprevucs,int Pucs,chtype *Ppcht,cchar_t *Ppcchar0,cchar_t *Ppcchar,int *Ppwritelen)//~v6W0I~//~v6W2R~//~v6WuR~//~v6X5R~//~v7bJR~
//int uviom_setcombineSCM(int Plineopt,int Pswcombine,int Pprevucs,int Pucs,chtype *Ppcht,cchar_t *Ppcchar0,cchar_t *Ppcchar,int *Ppwritelen)//~v6X5I~//~v7bJR~
//{                                                                  //~v6W0I~//~v7bJR~
//    cchar_t *pcc;                                               //~v6W2I~//~v6WuR~//~v7bJR~
//    int writelen=2,swcombinable,rc,apiwidth;                       //~v6WuR~//~v7bJR~
//    WUCS ucsalt;                                                   //~v6WuI~//~v7bJR~
//    attr_t attr;                                                   //~v6WuI~//~v7bJR~
////**************************                                       //~v6W0I~//~v7bJR~
//    pcc=Ppcchar;    //output                                       //~v6W0I~//~v7bJR~
//    attr=*Ppcht & ~(A_CHARTEXT);                                   //~v6WuI~//~v7bJR~
//    if (Ppcchar==Ppcchar0)                                         //~v6WuR~//~v7bJR~
//        swcombinable=0;                                            //~v6WuR~//~v7bJR~
//    else                                                           //~v6WuI~//~v7bJR~
//        swcombinable=utf_iscombinable(UICAO_NOSPACE,(ULONG)Pprevucs);//~v6WuR~//~v7bJR~
//    pcc->chars[0]=Pucs;                                            //~v6WuI~//~v7bJR~
//    if (swcombinable && COMBINEMODE(Plineopt))   //combine mode    //~v6WuI~//~v7bJR~
//    {                                                              //~v6WuI~//~v7bJR~
//        pcc->attr=attr|UVIOMATTR_EXT_WIDESBCS;// 0x800000, advance 1 col at mvadd//~v7bER~//~v7bJR~
//        writelen=1;                                                //~v7bEI~//~v7bJR~
//        rc=0;        //std                                         //~v6WuI~//~v7bJR~
//    }                                                              //~v6WuI~//~v7bJR~
//    else                                                           //~v6WuI~//~v7bJR~
//    {                                                              //~v6WuI~//~v7bJR~
//        attr=(attr_t)(uviol_repfg((int)*Ppcht,ATTR_COMBINENP_FG)<<8);//~v6WuI~//~v7bJR~
//        pcc->attr=attr;                                            //~v6WuI~//~v7bJR~
//        if (UTF_COMBINEMODE_NP() && uviom_getcombaltchUcs(0,&ucsalt))//~v6WuI~//~v7bJR~
//        {                                                          //~v6WuI~//~v7bJR~
//            rc=2;   //NP                                           //~v6WuI~//~v7bJR~
//            pcc->chars[0]=ucsalt;                                  //~v6WuI~//~v7bJR~
//        }                                                          //~v6WuI~//~v7bJR~
//        else                                                       //~v6WuI~//~v7bJR~
//            rc=1;   //split                                        //~v6WuI~//~v7bJR~
//    }                                                              //~v6WuI~//~v7bJR~
//#ifdef FFF                                                         //~v6X5I~//~v7bJR~
//  if (rc!=2 && Pswcombine & UICRC_COMB2SCM)                        //~v6X5R~//~v7bJR~
//  {                                                                //~v6X5I~//~v7bJR~
//    uviom_setcombineSCM_COMB2SCM(0,rc,Pucs,Ppcchar,&writelen);     //~v6X5R~//~v7bJR~
//  }                                                                //~v6X5I~//~v7bJR~
//  else                                                             //~v6X5I~//~v7bJR~
//#endif                                                             //~v6X5I~//~v7bJR~
//  if (rc)   //combine if rc=0                                      //~v7bEI~//~v7bJR~
//  {                                                                //~v6X5I~//~v7bJR~
//    *(pcc+1)=*pcc;                                                 //~v6WuI~//~v7bJR~
//    pcc++;                                                         //~v6WuI~//~v7bJR~
//    if (rc==2)  //NP                                               //~v6WuI~//~v7bJR~
//        pcc->chars[0]=UVIOM_COMBINE_ALTCH2; // '.' ,not written if Plen==1//~v6WuI~//~v7bJR~
//    else                                                           //~v6WuI~//~v7bJR~
//    {                                                              //~v6WuI~//~v7bJR~
//        apiwidth=wcwidth(Pucs); //curses expection                 //~v6WuI~//~v7bJR~
//        if (apiwidth==2)                                           //~v6WuI~//~v7bJR~
//        {                                                          //~v6WuI~//~v7bJR~
//            (pcc-1)->attr|=UVIOMATTR_DBCS1;    //1st of dbcs       //~v6WuR~//~v7bJR~
//            pcc->attr|=UVIOMATTR_DBCS2;   //1st of dbcs            //~v6WuR~//~v7bJR~
//        }                                                          //~v6WuI~//~v7bJR~
//        else                                                       //~v6WuI~//~v7bJR~
//        {                                                          //~v6WuI~//~v7bJR~
//            pcc->chars[0]=' ';  //widen to 2 cell                  //~v6WuI~//~v7bJR~
//        }                                                          //~v6WuI~//~v7bJR~
//    }                                                              //~v6WuI~//~v7bJR~
//  }                                                                //~v6X5I~//~v7bJR~
//    if (Ppwritelen)                                                //~v6W2I~//~v7bJR~
//        *Ppwritelen=writelen;                                      //~v6W2I~//~v7bJR~
//UTRACEP("%s: rc=%d,ucs=%06x,prevucs=%06x,attr=%0x,writelen=%d,swcombinable=%d,str_top=%d,modeNP=%d,altchNP=%0x\n",UTT,rc,Pucs,Pprevucs,attr,writelen,swcombinable,Ppcchar==Ppcchar0,UTF_COMBINEMODE_NP(),Gutfcombaltch);//~v6W0R~//~v6W2R~//~v6WuR~//~v7bJR~
//UTRACED("out cchar",Ppcchar,writelen*(int)sizeof(cchar_t));        //~v6WuI~//~v7bJR~
//    return rc;                                                     //~v6W0I~//~v7bJR~
//}//uviom_setcombineSCM                                             //~v6W0R~//~v7bJR~
//#endif //JJJ                                                       //~v7bEI~//~v7bJR~
//#ifdef JJJ                                                         //~v7bHI~//~v7bJR~
////*******************************************************          //~v7byI~//~v7bJR~
////*include next combine char                                       //~v7byI~//~v7bJR~
////*******************************************************          //~v7byI~//~v7bJR~
//int chkCombiningFollowing(int Popt,cchar_t *PpccharBase,chtype *PpchtNext,char *PpdbcsNext,int Plen)//~v7byI~//~v7bJR~
//{                                                                  //~v7byI~//~v7bJR~
//    UCHAR dbcswk[2],*pdbcs;;                                       //~v7byI~//~v7bJR~
//    chtype *pcht;                                                  //~v7byR~//~v7bJR~
//    int ucs,ii,swcombine,chsz,combinectr=0;                        //~v7byI~//~v7bJR~
//    UTRACEP("%s:base base ucs=0x%04x,chtype=0x%08x,dbcsid=0x%02x,Plen=%d\n",UTT,PpccharBase->chars[0],*PpchtNext,*PpdbcsNext,Plen);//~v7byR~//~v7bJR~
//    for (ii=Plen,pdbcs=PpdbcsNext,pcht=PpchtNext;ii>0;ii--,pcht++,pdbcs++)//~v7byI~//~v7bJR~
//    {                                                              //~v7byI~//~v7bJR~
//        UTRACEP("%s:ii=%d,pdbcs=0x%02x,pcht=0x%08x\n",UTT,ii,*pdbcs,*pcht);//~v7byR~//~v7bJR~
//        if (!UDBCSCHK_ISUCSSBCS(*pdbcs))                           //~v7byI~//~v7bJR~
//            break;                                                 //~v7byI~//~v7bJR~
//        dbcswk[0]=*pcht & A_CHARTEXT;                              //~v7byI~//~v7bJR~
//        ucs=(WUCS)UTF_GETUCSSBCS(dbcswk,PpdbcsNext);               //~v7byR~//~v7bJR~
//        swcombine=uviom_iscombining(0,pcht,pdbcs,ii,&ucs,&chsz);   //~v7byI~//~v7bJR~
//        if (!swcombine)                                            //~v7byI~//~v7bJR~
//            break;                                                 //~v7byI~//~v7bJR~
//        combinectr++;                                              //~v7byI~//~v7bJR~
//        PpccharBase->chars[combinectr]=ucs;                        //~v7byI~//~v7bJR~
//        UTRACEP("%s:combinectr=%d,ucs=0x%04x\n",UTT,combinectr,ucs);//~v7byI~//~v7bJR~
//    }                                                              //~v7byI~//~v7bJR~
//    UTRACEP("%s:rc=combinectr=%d\n",UTT,combinectr);               //~v7byI~//~v7bJR~
//    return combinectr;                                             //~v7byI~//~v7bJR~
//}                                                                  //~v7byI~//~v7bJR~
//#endif                                                             //~v7bHI~//~v7bJR~
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
    int posavhex=-1;                                               //~v7ehI~
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
    int swcombine,combinesz;                                              //~v6V3I~//~v6V5R~
    int chszSCM=0;                                                 //~v7bEI~
//#ifdef RRR                                                         //~v6W0R~//~v6W2R~//~v6WuR~
//    int swcombineSCM;   //do SpacingCombiningMark under combine mode//~v6W0I~//~v6WuR~
//#endif                                                             //~v6W0I~//~v6WuR~
//  int ucsbase=0;                                                 //~v6WuR~//~v7bER~
    int posbreak[6];                                               //~v7bER~
#ifndef JJJ                                                        //~v7f4I~
	int swlocalw0nocomb=0;                                         //~v7f4R~
#endif                                                             //~v7f4I~
//*********************************                                //~v640I~
    UTRACEP("%s:row=%d,csr=%d\n",UTT,Prow,Scsrposy);          //~v653I~//~v7atR~
UTRACED("cht2cchar inp cht",Ppcht,Plen*CCTSZ);                     //~v640I~//~v6DhM~
UTRACED("cht2cchar inp dbcs",Ppdbcs,Plen);                         //~v640I~//~v6DhM~
    memset(posbreak,0xff,sizeof(posbreak));                        //~v7bER~
  if (Plineopt & UVIOO_CSRPOSCHK)       // file data line          //~v6EnR~
  {                                                                //~v6EmI~
	if ((swcsrline=(Prow==Scsrposy))                               //~v653I~
    &&  (Scsrposx>=Pcol && Scsrposx<Pcol+Plen)	//csr line         //~v653I~
    )                                                              //~v653I~
    {                                                              //~v653I~
//  	utfddgetcsrposbca(0,Ppdbcs,Plen+Pcol,Scsrposx,&posb,&posc,&posa);//~v653R~//~v7bRR~
    	getcsrposbca(0,Ppdbcs,Plen+Pcol,Scsrposx,&posb,&posc,&posa);//~v7bRI~
        posbreak[0]=posb; posbreak[1]=posc; posbreak[2]=posa;      //~v7bEI~
    }                                                              //~v653I~
	if ((swvhexcsrline=(Prow==Svhexcsrposy))                       //~v658I~
    &&  (Svhexcsrposx>=Pcol && Svhexcsrposx<Pcol+Plen)	//csr line //~v658I~
    )                                                              //~v658I~
    {                                                              //~v658I~
//  	utfddgetcsrposbca(0,Ppdbcs,Plen+Pcol,Svhexcsrposx,&posbvhex,&poscvhex,0/*after*/);//~v658R~//~v7bRR~
//  	getcsrposbca(0,Ppdbcs,Plen+Pcol,Svhexcsrposx,&posbvhex,&poscvhex,0/*after*/);//~v7bRI~//~v7ehR~
    	getcsrposbca(0,Ppdbcs,Plen+Pcol,Svhexcsrposx,&posbvhex,&poscvhex,&posavhex);//~v7ehI~
        posbreak[3]=posbvhex; posbreak[4]=poscvhex;                //~v7bEI~
    }                                                              //~v658I~
    UTRACEP("%s:Scsrposx=%d,Svhexcsrposx=%d,swcsrline=%d,swvhexcsrline=%d,posb=%d,posbvhex=%d\n",UTT,Scsrposx,Svhexcsrposx,swcsrline,swvhexcsrline,posb,posbvhex);//~v7bER~
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
//#ifdef RRR                                                         //~v6W0R~//~v6W2R~//~v6WuR~
//        swcombineSCM=0;   //do SpacingCombiningMark under combine mode//~v6W0I~//~v6WuR~
//#endif                                                             //~v6W0I~//~v6WuR~
//      if (ii>1)                                                  //~v6V3I~//~v6V5R~
//  		swcombineOvf=utf22_iswidth0Ovf(0,c1h,*(pcht+1) & A_CHARTEXT,dbcsid,*(pdbcs+1),&ucs);//~v6V3I~//~v6V5R~//~v6WuR~
//    		swcombine=uviom_ISUCSWIDTH0(0,pcht,pdbcs,Plen-ii,&ucs);//~v6V5R~//~v6WuR~
//      else	                                                   //~v6V3I~//~v6V5R~
//      	swcombine=0;                                        //~v6V3I~//~v6V5R~
//		swcombine=uviom_iscombining(0,pcht,pdbcs,ii,&ucs,&chsz);   //~v6WuR~//~v7f1R~
		int optic=ICO_NOFMT;                                       //~v7f1I~
#ifndef JJJ                                                        //~v7f4I~
		optic|=ICO_NOFMTRC;		//              0x04    //set UICRC_NOCOMB for w0-no combine char//~v7f4I~
#endif                                                             //~v7f4I~
  		swcombine=uviom_iscombining(optic,pcht,pdbcs,ii,&ucs,&chsz);//~v7f1I~
#ifndef JJJ                                                        //~v7f4I~
		swlocalw0nocomb=(swcombine & UICRC_NOCOMB)!=0;//w0 not combining char//~v7f4I~
#endif                                                             //~v7f4I~
                                                                   //~v7f4I~
        chszSCM=chsz;                                              //~v7bEI~
        UTRACEP("%s:col=%d,mblen=%d,chsz=%d,ch=0x%0x,dbcsid=0x%02x,swcombine=%d\n",UTT,col,mblen,chsz,ch,dbcsid,swcombine);              //~v7atI~//~v7bER~//~v7bJR~
//      if (!swcombine)                                            //~v6WuI~//~v7bER~
//      	ucsbase=ucs;                                           //~v6WuI~//~v7bER~
//      if (swcombine==UICRC_SCM)	//4                            //~v6WuR~//~v6X5R~
        if (swcombine & UICRC_SCM)	//4                            //~v6X5I~
        {                                                          //~v7atI~
        	UTRACEP("%s:SCM chsz=%d,ch=0x%0x\n",UTT,chsz,ch);      //~v7atI~
            chsz=2;                                                //~v6WuI~
        }                                                          //~v7atI~
//      if (swcombine==2)                                          //~v6V3I~//~v6V5R~//~v6X1R~
        if (swcombine & UICRC_OVF)                                 //~v6X1I~
//*UICRC_OVF:2                                                     //~v7bDI~
        {                                                          //~v6V3I~
        	UTRACEP("%s:uviom_iscombining() rc=swcombine=%d\n",UTT,swcombine);            //~v6V3I~//~v7bDR~
        }                                                          //~v6V3I~
        else                                                       //~v6V3I~
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
	        	UTRACEP("%s:SUCS2NW chsz=%d,ch=0x%0x\n",UTT,chsz,ch);//~v7atI~
#ifndef SSS                                                        //~v6DhI~
    			if (ucs==DBCSSPACE_ALT2   //ffff                   //~v6DhI~
		        &&  dbcsid==UDBCSCHK_DBCS1STUCS)	//tabdisplay set ffff/() for dbcsspace//~v6DhI~
          		{                                                  //~v6DhI~
          			swdbcsspace=1;                                 //~v6DhI~
          			ucs=UTF_GETALTCH_DBCS();                       //~v6DhI~
            	}                                                  //~v6DhI~
#endif //SSS                                                       //~v6DhI~
//#ifdef RRR                                                         //~v6W0R~//~v6W2R~//~v6WuR~
//                if (COMBINEMODE(Plineopt))                         //~v6W0I~//~v6WuR~
//                    if (ii!=Plen)   //not top                      //~v6W0I~//~v6WuR~
//                        swcombineSCM=utf4_isSpacingCombiningMark(0,(UWUCS)ucs);//~v6W0R~//~v6WuR~
//#endif                                                             //~v6W0I~//~v6WuR~
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
	        	UTRACEP("%s:OVF1ST chsz=%d,ch=0x%0x\n",UTT,chsz,ch);//~v7atI~
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
	        UTRACEP("%s:BP1ST chsz=%d,ch=0x%0x\n",UTT,chsz,ch);    //~v7atI~
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
        if (chsz==2)                                               //~v7atI~
            UTRACEP("%s:set mblen=2\n",UTT);                       //~v7atI~
        if (chsz<0) //err data                                     //~v640I~
        {                                                          //~v640I~
            mblen=1;                                               //~v640I~
            ucs=errrep;    //display "."                           //~v640I~
        }                                                          //~v640I~
        ch=ucs;                                                    //~v640I~
        pcchar->attr=attr;                                         //~v640I~
        swbreak=(ii!=Plen && attr!=attro);                         //~v653I~//~v656R~
        UTRACEP("%s:ii=%d,col=%d,ucs=%x,attr=%x,attro=%x,swbreak=%d,swcombine=%d\n",UTT,ii,col,ch,attr,attro,swbreak,swcombine);//~v653R~//~v7bER~//~v7bJR~
        attro=attr;                                                //~v653I~
        if (!ch)                                                   //~v640I~
            pcchar->chars[0]=' ';    //null is used not only file area but anywhere//~v640I~
        else                                                       //~v640I~
//#ifdef RRR                                                         //~v6W0R~//~v6W2R~//~v6WuR~
//    	if (swcombineSCM)                                          //~v6W0R~//~v6WuR~
//    	if (swcombine==UICRC_SCM)                                  //~v6WuR~//~v6X1R~
      	if (swcombine & UICRC_SCM)                                 //~v6X1I~
        {                                                          //~v6W0I~
//  		uviom_setcombineSCM(0,ucs,Ppcchar,pcchar,&writectr);             //~v6W0R~//~v6W2R~//~v6WuR~
//    		uviom_setcombineSCM(Plineopt,ucsbase,ucs,pcht,Ppcchar,pcchar,&writectr);//~v6WuR~//~v6X5R~
//      	uviom_setcombineSCM(Plineopt,swcombine,ucsbase,ucs,pcht,Ppcchar,pcchar,&writectr);//~v6X5I~//~v7bER~
			opt=0;                                                 //~v7bEI~
            if (swcsrline||swvhexcsrline)                          //~v7bEI~
            {                                                      //~v7bEI~
            	opt|=UVIOMSCO_CSRLINE;                             //~v7bEI~
		    	if (col==posb||col==posc||col==posa)               //~v7bEI~
                	if (swcsrline)                                 //~v7bEI~
                    	swbreak=1;                                 //~v7bEI~
		        if (col==poscvhex||col==posbvhex)                  //~v7bEI~
					if (swvhexcsrline)                             //~v7bEI~
                    {                                              //~v7bEI~
				    	if (col==poscvhex)                         //~v7bEI~
	                    	opt|=UVIOMSCO_NOSETATTR;    //avoid set attr for vhex pos//~v7bEI~
                    }                                              //~v7bEI~
            	UTRACEP("%s:swbreak=%d,col=%d,swcsrline=%d,swvhexcsrline=%d,posb=%d,posc=%d,posa=posa,poscvhex=%d,posbvhex=%d\n",UTT,swbreak,col,swcsrline,swvhexcsrline,posb,posc,posa,poscvhex,posbvhex);//~v7bER~
            }                                                      //~v7bEI~
            UTRACEP("%s:swbreak=%d,swcsrline=%d,swvhexcsrline=%d,col=%d,posb=%d,posc=%d,posa=%d,poscvhex=%d,posbvhex=%d\n",//~v7bEI~
            	UTT,swbreak,swcsrline,swvhexcsrline,col,posb,posc,posa,poscvhex,posbvhex);//~v7bEI~
        	if (swbreak)                                           //~v7bEI~
            	opt|=UVIOMSCO_FORCEBREAK;                          //~v7bEI~
            reslen=ii;                                             //~v7bEI~
            int strsz;                                             //~v7bEI~
//      	uviom_setcombineSCM_nonligature(opt,Plineopt,col,posbreak,ucs,pcht,pdbcs,Ppcchar,pcchar,chszSCM,reslen,&writectr,&strsz/*of multiple scm after base*/);//~v7bER~//~v7bJR~
        	uviom_setcombineSCM_nonligature(opt,Plineopt,ucs,pcht,pdbcs,Ppcchar,pcchar,chszSCM,&writectr,&strsz);//~v7bJI~
            mblen=strsz;                                           //~v7bER~
            pcchar+=writectr-mblen; //advance more by writectr     //~v7bER~
//        	rc|=UVIOMCCRC_NONASCII;                                //~v6W2R~//~v6WuR~//~v7bER~
        	rc|=UVIOMCCRC_NONASCII|UVIOMCCRC_COMBINE; //call mvaddchnstrW_combine//~v7bEI~
        }                                                          //~v6W0I~
        else                                                       //~v6W0I~
//#endif                                                             //~v6W0I~//~v6WuR~
//     	if (uviom_setcombine(0,ucs,chsz,pcht,pcchar,pdbcs,ii,&combinectr))//~v653I~
//#ifdef WWW                                                         //~v6BYI~//~v6BZR~
//        if (UDBCSCHK_ISUCSWIDTH0(dbcsid))                          //~v653R~//~v6V3R~
//      if (UDBCSCHK_ISUCSWIDTH0(dbcsid)                           //~v6V3I~//~v6V5R~
        if (swcombine)                                           //~v6V3I~//~v6V5R~
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
            	int combinesz=0;                                   //~v7bEI~
            	for (combinectr=0;combinectr<UVIOM_MAXCOMBINE;combinectr++)//~v656R~
                {                                                  //~v656I~
//      			if (uviom_ISUCSWIDTH0(0,pcht+combinectr,pdbcs+combinectr,Plen-ii-combinectr,0/*out ucs*/))//~v6V5I~//~v6W2R~
//      			if (!uviom_ISUCSWIDTH0(0,pcht+combinectr,pdbcs+combinectr,Plen-ii-combinectr,0/*out ucs*/))//~v6W2I~//~v6WuR~
//      			if (!uviom_ISUCSWIDTH0(IUW0O_COMB2SCM_COMB,pcht+combinectr,pdbcs+combinectr,ii-combinectr,0/*out ucs*/))//~v6X5R~//~v7bBR~
                                                                   //~v7bBI~
//  	            int opt=IUW0O_COMB2SCM_COMB|IUW0O_NOZWJZWNJ;    //rc=0 for ZWJ/ZANJ//~v7bBI~//~v7bVR~
//      			if (!uviom_ISUCSWIDTH0(opt,pcht+combinectr,pdbcs+combinectr,ii-combinectr,0/*out ucs*/))//~v7bBR~//~v7bER~
//      			int rc3=uviom_ISUCSWIDTH0(opt,pcht+combinectr,pdbcs+combinectr,ii-combinectr,0/*out ucs*/);//~v7bEI~//~v7bVR~
//					int opt=0;	//accept format as combining       //~v7bVI~//~v7emR~
//        			int rc3=uviom_iscombining(opt,pcht+combinectr,pdbcs+combinectr,ii-combinectr,0/*out ucs*/,0/*out chsz*/);//~v7bVR~//~v7emR~
//					int opt2=0;	//accept format as combining       //~v7emI~//~v7f1R~
					int opt2=ICO_NOFMT;	//exculde Format width0    //~v7f1I~
#ifndef JJJ                                                        //~v7f4I~
					opt2|=ICO_NOFMTRC;		//              0x04    //set UICRC_NOCOMB for w0-no combine char//~v7f4I~
#endif                                                             //~v7f4I~
        			int rc3=uviom_iscombining(opt2,pcht+combinectr,pdbcs+combinectr,ii-combinectr,0/*out ucs*/,0/*out chsz*/);//~v7emI~
                    UTRACEP("%s:after iscombining rc3=%d,combinectr=%d,pcht=%04x,pcd=%02x\n",UTT,rc3,combinectr,*(pcht+combinectr),*(pdbcs+combinectr));//~v7ffR~
                    if (!rc3)                                      //~v7bEI~
                    	break;                                     //~v656I~
                    if (swcsrline)                                 //~v7ehI~
                    	if (col==posa)                             //~v7ehR~
                        {                                          //~v7ehI~
                        	UTRACEP("%s:csrline combining is posa(%d)\n",UTT,posa);//~v7ehR~
                        	break;                                 //~v7ehI~
                        }                                          //~v7ehI~
					if (swvhexcsrline)                             //~v7ehI~
                    	if (col==posavhex)                         //~v7ehI~
                        {                                          //~v7ehI~
                        	UTRACEP("%s:vhexcsrline combining is posavhex(%d)\n",UTT,posavhex);//~v7ehI~
                        	break;                                 //~v7ehI~
                        }                                          //~v7ehI~
//                  jj=col+combinectr;                             //~v656I~//~v7bER~
                    combinesz+=1+((rc3 & UICRC_OVF)!=0);           //~v7bEI~
                    jj=col+combinesz;                              //~v7bEI~
		            if (jj==posb||jj==posc||jj==posa)              //~v656R~
                      if (swcsrline)                               //~v658I~
                      {                                            //~v7emI~
                        UTRACEP("%s:csrline break col=%d,posc=%d,jj=%d\n",UTT,col,posc,jj);//~v7emI~
                    	break;                                     //~v656I~
                      }                                            //~v7emI~
#ifdef AAA                                                         //~v7emI~
		            if (jj==poscvhex||jj==posbvhex)                //~v658R~
						if (swvhexcsrline)                         //~v658I~
                        {                                          //~v658R~
				            if (jj==poscvhex)                      //~v658I~
	                            opt|=UVIOMSCO_NOSETATTR;    //avoid set attr for vhex pos//~v658R~
                            break;                                 //~v658R~
                        }                                          //~v658R~
#else                                                              //~v7emI~
                    if (swvhexcsrline)                             //~v7emI~
		    	        if (jj==poscvhex||jj==posbvhex||jj==posavhex)//~v7emR~
                        {                                          //~v7emI~
				            if (jj==posavhex)  //jj-chsz==posc     //~v7emI~
                            {                                      //~v7emI~
	                            opt|=UVIOMSCO_NOSETATTR;    //avoid set attr for vhex pos//~v7emI~
                                UTRACEP("%s:NOSETATTR by vhexcpos. col=%d,poscvhex=%d,jj=%d\n",UTT,col,poscvhex,jj);//~v7emR~
                            }                                      //~v7emI~
                            break;                                 //~v7emI~
                        }                                          //~v7emI~
#endif                                                             //~v7emI~
#ifndef JJJ                                                        //~v7f4M~
      				if (swlocalw0nocomb)	//w0 not combining char//~v7f4I~
                    {                                              //~v7f4M~
                    	UTRACEP("%s:swcombine is NOCOMB(w0 not combinig) ucs=%04x\n",UTT,ucs);//~v7f4M~
                    	break;                                     //~v7f4M~
                    }                                              //~v7f4M~
#endif                                                             //~v7f4M~
                }                                                  //~v656I~
                if (combinectr)                                    //~v656I~
//              	reslen=combinectr; //combine limit             //~v656I~//~v7bER~
                	reslen=combinesz; //combine limit              //~v7bEI~
                else                                               //~v656I~
                	swbreak=1;	//set FORCEBREAK;                  //~v656I~
            	UTRACEP("%s:csrbreakchk swbreak=%d,col=%d,combinectr=%d,combinesz=%d\n",UTT,swbreak,col,combinectr,combinesz);//~v656I~//~v7bER~//~v7bJR~
            }                                                      //~v656M~
        	if (swbreak)                                           //~v653R~
            	opt|=UVIOMSCO_FORCEBREAK;                          //~v656R~
//          else                                                   //~v656I~//~v658R~
//          	opt|=UVIOMSCO_SETATTR;	//by csr column            //~v656I~//~v658R~
//  		uviom_setcombine(opt,ucs,pcht,Ppcchar,pcchar,pdbcs,reslen,&combinectr,&writectr);//~v656R~//~v6EmR~
//  		uviom_setcombine(opt,Plineopt,ucs,pcht,Ppcchar,pcchar,pdbcs,reslen,&combinectr,&writectr);//~v6EmI~//~v6V5R~
            if (pdbcs>Ppdbcs &&  UDBCSCHK_ISUCSNP2ND(*(pdbcs-1)))  //~v6WeI~
            	opt|=UVIOMSCO_BASEUNP;                             //~v6WeI~
			if (chsz==2 &&  wcwidth(ucs)==1)                       //~v7bJI~
            	opt|=UVIOMSCO_WIDESBCS;                            //~v7bJI~
			if (swcombine & UICRC_OVF) //0x02      //2cell         //~v7bQI~
    			opt|=UVIOMSCO_COMB2SCM;//        0x80  //u3099,309a:dbcs//~v7bQI~
#ifndef JJJ                                                        //~v7f4I~
//        if (swcombine & UICRC_NOCOMB) //w0 not combining char    //~v7f4R~
//        {                                                        //~v7f4R~
//          uviom_setcombine_W0NOCOMB(opt,Plineopt,ucs,pcht,Ppcchar,pcchar,pdbcs,reslen,&combinectr,&writectr,&combinesz);//~v7f4R~
//        }                                                        //~v7f4R~
//        else                                                     //~v7f4R~
			if (swlocalw0nocomb) //0x02      //2cell               //~v7f4R~
    			opt|=UVIOMSCO_W0NOCOMB;//   0x0100  //width=0 not combining char//~v7f4R~
#endif                                                             //~v7f4M~
    		uviom_setcombine(opt,Plineopt,ucs,pcht,Ppcchar,pcchar,pdbcs,reslen,&combinectr,&writectr,&combinesz);//~v6V5I~
//      	mblen=combinectr;                                      //~v653R~//~v6V5R~
        	mblen=combinesz;      //consider ucs4                  //~v6V5I~
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
        	if (swbreak)                                           //~v7eyI~
            	pcchar->attr|=UVIOMATTR_BREAK;                     //~v7eyI~
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
        	if (swbreak)                                           //~v7eyI~
            	pcchar->attr|=UVIOMATTR_BREAK;                     //~v7eyI~
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
//#ifdef TTT                                                       //~v7avR~
            	apiwidth=wcwidth(ucs);	//curses expection         //~v640I~
//#else         //curses may follows wcwidth()                     //~v7avR~
//                int wcwflag;                                     //~v7avR~
//                apiwidth=utfwcwidth(0,(ULONG)ucs,&wcwflag); //test for FORMAT//~v7avR~
//#endif                                                           //~v7avR~
UTRACEP("%s:ucs=%x,apiwidth=%d\n",UTT,ucs,apiwidth);     //~v640I~//~v6b9R~//~v7avR~//~v7bJR~
                if (UDBCSCHK_ISUCS_DBCS1STW(dbcsid))   //wide sbcs //~v640R~
                {                                                  //~v640I~
                	if (apiwidth==2)     //(u1+' ')+(u2+' ')       //~v640R~
                    {                                              //~v640I~
			    	    pcchar->chars[0]=ch;                       //~v640I~
			    	    pcchar->chars[1]=' ';                      //~v640I~
                        *(pcchar+1)=*pcchar;                       //~v640I~
//                      pcchar->attr|=1;    //1st of dbcs          //~v640I~//~v6W8R~
                        pcchar->attr|=UVIOMATTR_DBCS1;    //1st of dbcs//~v6W8I~
//                      (pcchar+1)->attr|=2;    //1st of dbcs      //~v640I~//~v6W8R~
                        (pcchar+1)->attr|=UVIOMATTR_DBCS2;    //1st of dbcs//~v6W8I~
                    }                                              //~v640I~
                    else                 //u                       //~v640R~
                    {                                              //~v640I~
			    	    pcchar->chars[0]=ch;                       //~v640I~
#ifdef KKK                                                         //~v7bHI~//~v7bJR~
                        int cmbctr=chkCombiningFollowing(0,pcchar,pcht+2,pdbcs+2,ii-2);//~v7byR~
                        if (cmbctr)                                //~v7byI~
                        {                                          //~v7byI~
                        	ii-=cmbctr;                            //~v7byI~
                        	pcht+=cmbctr;                          //~v7byI~
                        	pdbcs+=cmbctr;                         //~v7byI~
        					rc|=UVIOMCCRC_COMBINE;	//call mvaddchnstrW_combine//~v7bHI~
                            UTRACEP("%s:F2C1,include following combining cmbctr=%d,ii=%d\n",UTT,cmbctr,ii);//~v7byI~
                        }                                          //~v7byI~
#endif                                                             //~v7bHI~
//  		    	    (pcchar+1)->chars[0]=' ';                  //~v640I~//~v7bFR~
//  		    	    (pcchar+1)->attr=attr;                     //~v640I~//~v7bFR~
//                      pcchar->attr|=UVIOMATTR_DBCS1;    //if next missing DBCS2, writhe both after reset DBCS1 at mvaddchnstrW//~v7atI~//~v7bFR~
                    	pcchar->attr|=UVIOMATTR_EXT_WIDESBCS;// 0x800000, advance 1 col at mvadd//~v7bFI~
						pcchar--;	//for loop,pcchar+=1+dbcssw==>pcchar++//~v7bFI~
						UTRACEP("%s:ucs=%x,WIDESBCS\n",UTT,ch);    //~v7bJI~
                    }                                              //~v640I~
                }                                                  //~v640I~
                else                                               //~v640I~
                if (UDBCSCHK_ISUCS_DBCS1STN(dbcsid))   //narrow Dbcs(also wcwidth=2)//~v640R~
                {                                                  //~v640I~
                    pcchar->chars[0]=ch;                           //~v640I~
                    pcchar->chars[1]=' ';//Guviomdbcspad;          //~v640R~
                    *(pcchar+1)=*pcchar;                           //~v640I~
//                  pcchar->attr|=1;    //1st of dbcs              //~v640I~//~v6W8R~
                    pcchar->attr|=UVIOMATTR_DBCS1;    //1st of dbcs//~v6W8I~
//                  (pcchar+1)->attr|=2;    //1st of dbcs          //~v640I~//~v6W8R~
                    (pcchar+1)->attr|=UVIOMATTR_DBCS2;    //1st of dbcs//~v6W8I~
                }                                                  //~v640I~
                else                                               //~v640I~
                if (UDBCSCHK_DBCS1STUCS2(dbcsid))   //usual DBCS(wcwidt=1/2)//~v640R~
                {                                                  //~v640R~
//#ifdef AAA //@@@@test                                            //~v6V6R~
                  if (apiwidth==2)                                 //~v6BgI~
//#endif                                                           //~v6V6R~
                  {                                                //~v6BgI~
                    pcchar->chars[0]=ch;                           //~v640I~
                    *(pcchar+1)=*pcchar;                           //~v640I~
//                  pcchar->attr|=1;    //1st of dbcs              //~v640I~//~v6W8R~
                    pcchar->attr|=UVIOMATTR_DBCS1;    //1st of dbcs//~v6W8I~
//                  (pcchar+1)->attr|=2;    //1st of dbcs          //~v640I~//~v6W8R~
                    (pcchar+1)->attr|=UVIOMATTR_DBCS2;    //1st of dbcs//~v6W8I~
                  }                                                //~v6BgI~
//#ifdef AAA                                                       //~v6V6R~
                  else                                             //~v6BgI~
                  {                                                //~v6BgI~
                    pcchar->chars[0]=ch;                           //~v6BgI~
                    *(pcchar+1)=*pcchar;                           //~v6BgI~
			    	(pcchar+1)->chars[0]=' ';                      //~v6BgI~
                    pcchar->attr|=UVIOMATTR_DBCS1;    //if next missing DBCS2, writhe both after reset DBCS1 at mvaddchnstrW//~v7atI~
                    UTRACEP("%s:apiwidth=1 for dbcsid=%c ucs=%x\n",UTT,dbcsid,ch);//~v6BgI~//~v6DdR~
                  }                                                //~v6BgI~
//#endif                                                           //~v6V6R~
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
UTRACEP("%s:return row=%d,col=%d,rc=%d,outctr=%d,inctr=%d\n",UTT,Prow,Pcol,rc,outctr,Plen);           //~v640I~//~v7bFR~//~v7c4R~
UTRACED("cht2cchar out cchar",Ppcchar,outctr*CCHSZ);               //~v640R~//~v7bJR~//~v7bLR~
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
#ifdef UUU                                                         //~v6W5I~
    cchar_t *pcchar_base=0,*pcchar_save;                           //~v6V5I~
#else                                                              //~v6W5I~
    cchar_t *pcchar_base=0;                                        //~v6W5I~
    cchar_t *pcchar_current;                                       //~v7bDI~
#endif                                                             //~v6W5I~
    chtype  *pcht;                                                 //~v653I~
    UCHAR *pdbcs;                                                  //~v653I~
    WUCS    ucs;                                                   //~v653I~
    WUCS    prevucs=0;                                             //~v656I~
    UCHAR dbcswk[2],dbcsid;                                        //~v653I~
	int rc=UVIOMCCRC_LIGATUREMODE,col;                             //~v653R~
    int posb=-1,posc=-1,posa=-1,swcombine,swbreak,swcsrline;//~v653R~//~v7bZR~
    int poscvhex=-1,posbvhex=-1,swvhexcsrline,swvhexcsrbreak;      //~v658R~
    int posavhex=-1;                                               //~v7ehI~
    int opt,swcsrbreak,swprevdbcs=0;                                            //~v656R~//~v658R~
//  int baseattr=0;                                                //~v65bI~//~v6BhR~
    attr_t baseattr=0;                                             //~v6BhI~
    int altch;                                                     //~v65iI~
    int swdbcsspace;                                               //~v65mI~
    int swaltsbcs;                                                 //~v68pI~
    int apiwidth;                                                  //~v6DaI~
    int chszSCM=0;                                                 //~v7bEI~
//#ifdef VVV                                                       //~v6W5R~
//#ifdef YYY                                                         //~v6W5I~//~v6W6R~
//#else                                                              //~v6W5I~//~v6W6R~
//    int rc2;                                                       //~v6W5I~//~v6W6R~
//#endif                                                             //~v6W5I~//~v6W6R~
#ifndef JJJ                                                        //~v7f4I~
int swlocalw0nocomb;                                               //~v7f4I~
#endif                                                             //~v7f4I~
//*********************************                                //~v653I~
    UTRACEP("%s:row=%d,csrline=%d,;ineopt=0x%x\n",UTT,Prow,Scsrposy,Plineopt);//~v653R~  //~v6DdR~//~v7bER~
UTRACED("cht2cchar inp cht",Ppcht,Plen*CCTSZ);                     //~v653I~//~v6DhM~
UTRACED("cht2cchar inp dbcs",Ppdbcs,Plen);                         //~v653I~//~v6DhM~
  if (Plineopt & UVIOO_CSRPOSCHK)       // file data line          //~v6EnR~
  {                                                                //~v6EmI~
	if ((swcsrline=(Prow==Scsrposy))                               //~v653I~
    &&  (Scsrposx>=Pcol && Scsrposx<Pcol+Plen)	//csr line         //~v653I~
    )                                                              //~v653I~
    {                                                              //~v653I~
//  	utfddgetcsrposbca(0,Ppdbcs,Plen+Pcol,Scsrposx,&posb,&posc,&posa);//~v653R~//~v7bRR~
    	getcsrposbca(0,Ppdbcs,Plen+Pcol,Scsrposx,&posb,&posc,&posa);//~v7bRI~
    }                                                              //~v653I~
	if ((swvhexcsrline=(Prow==Svhexcsrposy))                       //~v658I~
    &&  (Svhexcsrposx>=Pcol && Svhexcsrposx<Pcol+Plen)	//csr line //~v658I~
    )                                                              //~v658I~
    {                                                              //~v658I~
//  	utfddgetcsrposbca(0,Ppdbcs,Plen+Pcol,Svhexcsrposx,&posbvhex,&poscvhex,0/*after*/);//~v658R~//~v7bRR~
//  	getcsrposbca(0,Ppdbcs,Plen+Pcol,Svhexcsrposx,&posbvhex,&poscvhex,0/*after*/);//~v7bRI~//~v7ehR~
    	getcsrposbca(0,Ppdbcs,Plen+Pcol,Svhexcsrposx,&posbvhex,&poscvhex,&posavhex);//~v7ehI~
    }                                                              //~v658I~
    UTRACEP("%s:Scsrposx=%d,Svhexcsrposx=%d,swcsrline=%d,swvhexcsrline=%d,posb=%d,posbvhex=%d\n",UTT,Scsrposx,Svhexcsrposx,swcsrline,swvhexcsrline,posb,posbvhex);//~v7bEI~
  }                                                                //~v6EmI~
    errrep=UVIO_ERRREP;                                            //~v653I~
    for (pcchar=Ppcchar,ii=0,pdbcs=Ppdbcs,pcht=Ppcht,col=Pcol;     //~v653R~
    			ii<Plen;                                           //~v653I~
				ii+=mblen,pcht+=mblen,pdbcs+=mblen,pcchar+=1+dbcssw,col+=mblen)//~v653R~
    {                                                              //~v653I~
        pcchar_current=pcchar;                                     //~v7bDR~
	    ch=*pcht & A_CHARTEXT;                                     //~v653I~
        attr=*pcht & ~(A_CHARTEXT);                                //~v653I~
    	dbcssw=0;                                                  //~v653I~
        chsz=1;                                                    //~v653I~
        dbcsid=*pdbcs;                                             //~v653I~
    	UTRACEP("%s:ii=%d,col=%d,ch=0x%02x,attr=0x%04x,dbcsid=%02x,mblen=%d,dbcssw=%d\n",UTT,ii,col,ch,attr,dbcsid,mblen,dbcssw);//~v7bJR~
//      swcombine=0;                                               //~v653I~//~v6X1R~
        swdbcsspace=0;                                             //~v65mI~
        swaltsbcs=0;                                               //~v68pI~
// 	  	swcombine=uviom_ISUCSWIDTH0(0,pcht,pdbcs,Plen-ii,&ucs);    //~v6V5I~//~v6WuR~
//  	swcombine=uviom_iscombining(0,pcht,pdbcs,Plen-ii,&ucs,&chsz);//~v6WuI~//~v7f1R~
		int optic=ICO_NOFMT;                                       //~v7f1I~
#ifndef JJJ                                                        //~v7f4I~
		optic|=ICO_NOFMTRC;		//              0x04    //set UICRC_NOCOMB for w0-no combine char//~v7f4I~
#ifdef TEST                                                        //~v7f4I~
		optic|=ICO_ZWJASCOMB;   //              0x04    //set UICRC_NOCOMB for w0-no combine char//~v7f5I~
#endif                                                             //~v7f4I~
#endif                                                             //~v7f4I~
   		swcombine=uviom_iscombining(optic,pcht,pdbcs,Plen-ii,&ucs,&chsz);//~v7f1I~
#ifndef JJJ                                                        //~v7f4I~
		swlocalw0nocomb=(swcombine & UICRC_NOCOMB)!=0;//w0 not combining char//~v7f4I~
#endif                                                             //~v7f4I~
        chszSCM=chsz;                                              //~v7bEI~
//      if (swcombine==UICRC_SCM)	//4                            //~v6WuI~//~v6X1R~
        if (swcombine & UICRC_SCM)	//4                            //~v6X1I~
        	dbcssw=1;                                              //~v6WuR~
        else                                                       //~v6WuI~
    	if (UDBCSCHK_ISUCSSBCS(dbcsid))                            //~v653I~
        {                                                          //~v653I~
//      	dbcswk[0]=ch;                                          //~v653I~//~v6BhR~
        	dbcswk[0]=(UCHAR)ch;                                   //~v6BhI~
//        	ucs=UTF_GETUCSSBCS(dbcswk,pdbcs);                      //~v653I~//~v6BhR~
          	ucs=(WUCS)UTF_GETUCSSBCS(dbcswk,pdbcs);                //~v6BhI~
//#ifdef WWW                                                         //~v6BYI~//~v6BZR~
//        	swcombine=UDBCSCHK_ISUCSWIDTH0(dbcsid);                //~v653R~//~v6V5R~
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
          if (ii>=SwidthLineno)                                    //~v7c2I~
        	prevucs=ucs;	//base of combinechar is not combinemode//~v656I~
            UTRACEP("%s:!swcombine prevucs=%x,ii=%d,ucs=0x%04x\n",UTT,prevucs,ii,ucs);     //~v6X8I~//~v7c2R~
//        	swprevdbcs=(chsz==2);	//base of combinechar is not combinemode//~v658I~//~v7bER~
//        	swprevdbcs=(attr & UVIOMATTR_DBCS12)!=0;               //~v7bEI~//~v7bSR~
        	swprevdbcs=UDBCSCHK_DBCS1STUCS2(dbcsid);/*wide dbcs*/  //~v7bSM~
            baseattr=attr;                                         //~v65bI~
			pcchar_base=pcchar;	//base for multiple combine char   //~v6V5M~
        }                                                          //~v658I~
        pcchar->attr=attr;                                         //~v653I~
//      attrn=attr & ~UVIOMATTR_DBCS12;                            //~v653R~//~v6BhR~
        attrn=attr & (attr_t)(~UVIOMATTR_DBCS12);                  //~v6BhI~
        swbreak=0;                                                 //~v7bTI~
      if (!swcombine)                                              //~v7bTI~
//      swbreak=(ii>0 && attrn!=attro);                                    //~v653R~//~v656R~//~v7bZR~
        swbreak=(ii>SwidthLineno && attrn!=attro);                 //~v7bZR~
        if (ii>SwidthLineno)                                       //~v7bZR~
        {                                                          //~v7bZI~
            int attrnbg=PAIR2ATTR(attrn)>>4;                              //~v7bWR~//~v7bZR~
            int attrobg=PAIR2ATTR(attro)>>4;                              //~v7bWR~//~v7bZR~
            UTRACEP("%s:attrnbg=0x%02x,attrobg=0x%02x\n",UTT,attrnbg,attrobg);//~v7bWI~//~v7bZR~
            if (attrnbg!=attrobg)                                  //~v7bZR~
                swbreak=1;                                         //~v7bZR~
        }                                                          //~v7bZI~
        UTRACEP("%s:ucs=0x%04x,swbreak=%d,attrn=0x%04x,attro=0x%04x\n",UTT,ucs,swbreak,attrn,attro);//~v7bJI~//~v7bZM~
//    if (!UVIOM_NONSPACECOMBINEMODE())  //fc5                     //~v656R~//~v658R~
//      swcsrbreak=0;                                              //~v656I~//~v658R~
//    else                                                         //~v656I~//~v658R~
        swcsrbreak=(swcsrline && (col==posb||col==posc||col==posa));   //~v653I~//~v656R~
        UTRACEP("%s:swcsrbreak=%d,swcsrline=%d,col=%d,posb=%d,ucs=0x%04x\n",UTT,swcsrbreak,swcsrline,col,posb,ucs);//~v7bwI~//~v7bCR~
        swcsrbreak|=(swvhexcsrline && col==posbvhex);              //~v658I~
        swbreak|=swcsrbreak;                                       //~v656I~
//      swvhexcsrbreak=swvhexcsrline && col==poscvhex;             //~v658R~//~v7ehR~
        swvhexcsrbreak=swvhexcsrline && (col==poscvhex||col==posavhex);//~v7ehI~
        swbreak|=swvhexcsrbreak;                                   //~v658I~
        UTRACEP("%s:breaksw=%d ii=%d,col=%d,ucs=%x,dbcssw=%d,attrn=%x,attro=%x,mblen=%d,swcombine=%d\n",UTT,swbreak,ii,col,ch,dbcssw,attr,attro,mblen,swcombine);//~v653R~//~v7bER~
//#ifdef LLL                                                       //~v7bLR~
#ifndef JJJ                                                        //~v7f4I~
//        swbreak|=swlocalw0nocomb;                                //~v7f4R~
#endif                                                             //~v7f4I~
        if (swbreak)                                               //~v7bLI~
        {                                                          //~v7f4I~
          	if (swcombine & UICRC_SCM)	//SCM                      //~v7bLI~
            {                                                      //~v7bLI~
                UTRACEP("%s:swBreak and swcombine=SCM reset prevucs=0x%04x,ii=%d,ucs=0x%04x\n",UTT,prevucs,ii,ucs);//~v7bLR~//~v7c2R~
              if (ii>=SwidthLineno)                                //~v7c2I~
	        	prevucs=ucs;	//base of combinechar is not combinemode//~v7bLI~
	        	swprevdbcs=0;                                      //~v7bLI~
                baseattr=0;                                        //~v7bLI~
                pcchar_base=0; //do not set combining to base      //~v7bLR~
            }                                                      //~v7bLI~
        }//swbreak!=0                                              //~v7f4I~
#ifndef JJJ                                                        //~v7f4M~
        if (swlocalw0nocomb)                                       //~v7f4I~
        {                                                          //~v7f4I~
            UTRACEP("%s:swBreak and swcombine=W0NOCOMB ii=%d,ucs=0x%04x\n",UTT,ii,ucs);//~v7f4I~
            prevucs=0;  //base of combinechar is not combinemode   //~v7f4I~
            swprevdbcs=0;                                          //~v7f4I~
            baseattr=0;                                            //~v7f4I~
            pcchar_base=0; //do not set combining to base          //~v7f4I~
        }                                                          //~v7f4I~
#endif                                                             //~v7f4M~
//#endif //LLL                                                     //~v7bLR~
        attro=attrn;                                               //~v653I~
        int swSCM=0;                                               //~v7bEI~
#ifdef OOO                                                         //~v7bNR~
        if (UTF_ISZWJ(ucs))                                        //~v7bNI~
        {                                                          //~v7bNI~
    		UTRACEP("%s:ii=%d,col=%d,ucs=ZWJ\n",UTT,ii,col);       //~v7bNI~
            int outctrZWJ;                                         //~v7bNI~
            if (uviom_setcombineZWJ(0,swbreak,Ppcchar,pcchar,&outctrZWJ))//~v7bNI~
            {                                                      //~v7bNI~
            	pcchar+=outctrZWJ-1;                               //~v7bNI~
		        mblen=chsz;                                        //~v7bNI~
                continue;                                          //~v7bNI~
            }                                                      //~v7bNI~
        }                                                          //~v7bNI~
#endif                                                             //~v7bNI~
//        if (swbreak && UTF_ISZWJZWNJ(ucs))                         //~v7bBR~//~v7bWR~
//        {                                                          //~v7bBR~//~v7bWR~
//            uviom_setcombineJoiner(Popt,Plineopt,ucs,pcht,pcchar); //~v7bBR~//~v7bWR~
//            rc|=UVIOMCCRC_NONASCII;                                //~v7bBR~//~v7bWR~
//        }                                                          //~v7bBR~//~v7bWR~
//        else                                                       //~v7bCI~//~v7bWR~
        if (swcombine)//sbcs width0                                //~v653I~
        {                                                          //~v653I~
          if (swcombine & UICRC_SCM)	//4                        //~v7bEI~
          {                                                        //~v7bEI~
        	rc|=UVIOMCCRC_NONASCII;                                //~v7bEI~
			swSCM=1;                                               //~v7bEI~
          }                                                        //~v7bEI~
          else                                                     //~v7bEI~
          {                                                        //~v7bEI~
        	rc|=UVIOMCCRC_NONASCII|UVIOMCCRC_COMBINE;              //~v653I~
#ifdef KKK                                                         //~v7bJI~
           	if (pcchar==Ppcchar                                    //~v656I~
//         	||  (pcchar-1)->attr & UVIOMATTR_BREAK)                //~v656I~//~v6V6R~
//         	||  (combinectr>0 && pcchar-1!=pcchar_base)) //multiple combine char and was split//~v6V6I~//~v6W9R~
           	||  (combinectr>0 && pcchar-1-swprevdbcs!=pcchar_base)) //multiple combine char and was split//~v6W9I~
            {                                                      //~v6V6I~
            	swbreak=1;  //after single combine char            //~v656I~//~v7bzR~
                UTRACEP("%s:multi combine,set swbreak pcchar=%p,Ppcchar=%p,pcchar_base=%p,combinectr=%d\n",UTT,pcchar,Ppcchar,pcchar_base,combinectr);//~v6V6I~
            }                                                      //~v6V6I~
#endif //KKK                                                       //~v7bJI~
                                                                   //~v7bJI~
//        if (UVIOM_COMBINEMODE())   //combine mode or fc5                                //~v653I~//~v656R~//~v658R~
//        if (UTF_COMBINEMODE())   //combine mode or fc5           //~v658I~//~v6EmR~
          if (COMBINEMODE(Plineopt))   //combine mode or fc5       //~v6EmI~
          {                                                        //~v656I~
#ifdef KKK                                                         //~v7bJI~
        	if (!swbreak && combinectr<UVIOM_MAXCOMBINE)           //~v653R~
            {                                                      //~v653I~
#ifdef UUU                                                         //~v6W5I~
              if (pcchar_base)                                     //~v6V5I~
              {                                                    //~v6V5I~
                pcchar_save=pcchar;                                //~v6V5I~
                pcchar=pcchar_base;                                //~v6V5I~
              }                                                    //~v6V5I~
              else                                                 //~v6V5I~
            	pcchar--;                                          //~v653R~
                combinectr++;                                      //~v653I~
                pcchar->chars[combinectr]=ch;                      //~v653I~
                if (pcchar->attr & 0x02)	//dbcs2nd              //~v653I~
	                (pcchar-1)->chars[combinectr]=ch;              //~v653I~
        UTRACEP("combined pcchar_save=%p,pcchar_base=%p,pcchar=%p,combinectr=%d\n",pcchar_save,pcchar_base,pcchar,combinectr);//~v653I~//~v6V5R~
              	if (pcchar_base)                                   //~v6V5I~
                {                                                  //~v6V5I~
                	pcchar=pcchar_save-(1+dbcssw); //keep over next loop//~v6V5R~
                }                                                  //~v6V5I~
#else                                                              //~v6W5I~
              if (swprevdbcs)   //no A0 entry                      //~v6W9I~
              {                                                    //~v6W9I~
                combinectr++;                                      //~v6W9I~
                pcchar_base->chars[combinectr]=ch;                 //~v6W9I~
                if (dbcssw)                                        //~v7bDI~
                {                                                  //~v7bDI~
    				UVIOMATTR_ADD_DBCSCOMBCTR(pcchar_base);        //~v7bDI~
                    UTRACEP("%s:combinectr=%d,dbcs combining char=0x%04x for dbcs base=0x%04x,attr=0x%04x\n",UTT,combinectr,ch,pcchar_base->chars[0],pcchar_base->attr);//~v7bDR~
                }	                                               //~v7bDI~
               if (pcchar_base->attr & UVIOMATTR_DBCS1) //read dbcs(NOT widesbcs)//~v7byI~
                (pcchar_base+1)->chars[combinectr]=ch;             //~v6W9I~
        UTRACED("combined pcchar str",pcchar_base,2*(int)sizeof(cchar_t));//~v6W9I~
                pcchar-=(1+dbcssw); //keep over next loop          //~v6W9I~
              }                                                    //~v6W9I~
              else                                                 //~v6W9I~
              {                                                    //~v6W9I~
#ifdef HHH                                                         //~v7buI~
				if (!combinectr)                                   //~v6W5I~
                {                                                  //~v6W5I~
            		pcchar->chars[0]=COMBAINE_BASE_SPLIT_ITSELF;	//0xa0     //u00a0 base for combining char when split itself//~v6W5I~
//	            	pcchar->attr=(attr_t)(attrn & UVIOMATTR_COLORMASK);//~v6W5R~//~v6WbR~
  	            	pcchar->attr=(attr_t)((attrn & UVIOMATTR_COLORMASK)|UVIOMATTR_EXT_DMYBASE);     //added "A0" entry for combining//~v6WbI~
	                pcchar_base=pcchar;	//combine str top          //~v6W5R~
                    pcchar++;                                      //~v6W5I~
			        UTRACEP("%s:set dummy base-A0 ucs=0x%04x\n",UTT,ch);//~vbzPI~
                }                                                  //~v6W5I~
#endif                                                             //~v7buI~
                combinectr++;                                      //~v6W5I~
                pcchar_base->chars[combinectr]=ch;                 //~v6W5R~
        		UTRACED("prevdbcs OFF,combined pcchar str",pcchar_base,(int)sizeof(cchar_t));//~v6W5R~//~v7buR~
                pcchar-=(1+dbcssw); //keep over next loop          //~v6W5I~
              }                                                    //~v6W9I~
#endif                                                             //~v6W5I~
                continue;                                          //~v653I~
            }                                                      //~v653I~
           if (combinectr>=UVIOM_MAXCOMBINE)                       //~v6V6I~
            swbreak=1;  //overflow case                            //~v658I~
#else    //else KKK                                                //~v7bJR~
			UTRACEP("%s:combined ucs=0x%04x,swbreak=%d\n",UTT,ch,swbreak);//~v7bJI~
           if (!swbreak)                                           //~v7bJI~
           {                                                       //~v7bJI~
			int opt2=0;                                            //~v7bJI~
			if (UDBCSCHK_DBCS1STUCS2NWO(dbcsid))                   //~v7bJI~
        		opt2|=SBEO_2CELL;                                  //~v7bJI~
	    	int colorCombining=(*pcht & UVIOMATTR_COLORMASK);//    0xFF00//~v7bJR~
			pcchar_base=setBaseEntry(opt2,Ppcchar,pcchar,colorCombining,ch,0/*Ppcombctr*/);//~v7bJR~
        	if (pcchar_base)                                       //~v7bJI~
            {                                                      //~v7bJI~
                pcchar-=(1+dbcssw); //ucs is added to base,stay output pcchar position//~v7bJR~
            	continue;                                          //~v7bJI~
            }                                                      //~v7bJI~
            prevucs=0;                                             //~v7bYI~
            swbreak=1;  //cominingctr overflow, top is combining   //~v7bJI~
           }//!swbreak                                             //~v7bJI~
           else	//swbreak                                          //~v7bYI~
#ifndef JJJ                                                        //~v7f4I~
		   if (swlocalw0nocomb)                                    //~v7f4I~
           {                                                       //~v7f4I~
    			UTRACEP("%s:swbreak and swlocalw0nocomb ii=%d,col=%d,ucs=%04x\n",UTT,ii,col,ucs);//~v7f4I~
           		pcchar_base=0;                                     //~v7f4I~
	            prevucs=0;                                         //~v7f4I~
           }                                                       //~v7f4I~
		   else                                                    //~v7f4I~
#endif                                                             //~v7f4I~
           {                                                       //~v7bYI~
                int opt2=0;                                        //~v7bYI~
                if (UDBCSCHK_DBCS1STUCS2NWO(dbcsid))               //~v7bYI~
                    opt2|=SBEO_2CELL;                              //~v7bYI~
                int colorCombining=(*pcht & UVIOMATTR_COLORMASK);//    0xFF00//~v7bYI~
                pcchar_base=setBaseEntry(opt2,Ppcchar,pcchar,colorCombining,0/*ch=0,no set as combining */,0/*Ppcombctr*/);//~v7bYI~
                if (pcchar_base)                                   //~v7bYI~
                {                                                  //~v7c4I~
//                	prevucs=pcchar_base->chars[0];	//for shadow base//~v7bYR~//~v7c4R~
#ifdef NNN                                                         //~v7c4I~
                    prevucs=getBaseUCS(0,pcchar_base);             //~v7c4I~
#else                                                              //~v7c4I~
                	prevucs=pcchar_base->chars[0];	//for shadow base//~v7c4I~
#endif                                                             //~v7c4I~
				}                                                  //~v7c4I~
                else                                               //~v7bYI~
	                prevucs=0;                                     //~v7bYI~
           }                                                       //~v7bYI~
#endif   //else KKK                                                //~v7bJR~
          }                                                        //~v656I~
         }//!SCM                                                   //~v7bEI~
            opt=0;                                                 //~v656R~
        	if (!UTF_COMBINEMODE())  //split mode                  //~v7bUI~
        		swbreak=1; //opt break is on when not combine mode for also ligature mode by setcombine1//~v7bUR~
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
//      	if (swcombine==2)                                      //~v6V5I~//~v6X1R~
        	if (swcombine & UICRC_OVF)	//4                        //~v6X1I~
	        	opt|=UVIOMATTR_PADDING2;//ucs4 width0              //~v6V5I~
            if (pdbcs>Ppdbcs &&  UDBCSCHK_ISUCSNP2ND(*(pdbcs-1)))  //~v6WeI~
	        	opt|=UVIOMATTR_EXT_BASEUNP;//base is inprintable   //~v6WeI~
	        opt|=UVIOMATTR_EXT_LIGATURE;//extended option, ligature//~v6V6I~
//ovf combine or shaddow generated                                 //~v6W5I~
//#ifdef VVV                                                       //~v6W5R~
//#ifdef YYY                                                         //~v6W5I~//~v6W6R~
//#else                                                              //~v6W5I~//~v6W6R~
//          rc2=                                                     //~v6W5I~//~v6W6R~
//#endif                                                             //~v6W5I~//~v6W6R~
//			uviom_setcombine1(opt,Plineopt,(WUCS)ch,prevucs,pcht,pcchar);//~v6EmI~//~v6W6R~
		  if (swSCM)	                                           //~v7bEI~
          {                                                        //~v7bEI~
			int wrtlen;                                            //~v7bEI~
      		uviom_setcombineSCM_ligature(opt,Plineopt,ucs,pcht,Ppcchar,pcchar,chszSCM,&wrtlen);//~v7bER~
        	rc|=UVIOMCCRC_NONASCII;                                //~v7bEI~
            if (wrtlen==1)                                         //~v7bEI~
            	pcchar--;	//no advance pcchar by dbcssw          //~v7bEI~
            mblen=2;    //                                         //~v7bEI~
          }                                                        //~v7bEI~
          else                                                     //~v7bEI~
          {                                                        //~v7bEI~
			if (chsz==2 && wcwidth(ch)==1)	//curses expection     //~v7bJI~
		        opt|=UVIOMATTR_EXT_WIDESBCS;                       //~v7bJI~
			if (pcchar_base && pcchar_base->attr & UVIOMATTR_EXT_WIDESBCS)//~v7bJR~
		        opt|=UVIOMATTR_EXT_BASEWIDE;                       //~v7bJI~
#ifndef JJJ                                                        //~v7f4I~
	  	if (swlocalw0nocomb)//      0x0100  //width=0 not combining char//~v7f4I~
      	{                                                          //~v7f4I~
        	SswComb1W0NOCOMB=1;	//parm to setcombine1              //~v7f4R~
      	}                                                          //~v7f4I~
#endif                                                             //~v7f4I~
          int rc3=                                                 //~v7bzI~
  			uviom_setcombine1(opt,Plineopt,(WUCS)ch,prevucs,pcht,pcchar,Ppcchar);//~v6W6I~
#ifndef JJJ                                                        //~v7f4I~
        SswComb1W0NOCOMB=0;	//parm to setcombine1                  //~v7f4R~
#endif                                                             //~v7f4I~
            UTRACEP("combine ii=%d,ucs=%x,rc of setcombine1=%d,dbcssw=%d\n",ii,ch,rc3,dbcssw);//~v653I~//~v7bzR~//~v7bZR~
            if (rc3==1 && !dbcssw)                                 //~v7bzI~
            	pcchar++;                                          //~v7bzI~
          }                                                        //~v7bEI~
//#ifdef VVV                                                       //~v6W5R~
//#ifdef YYY                                                         //~v6W5I~//~v6W6R~
//#else                                                              //~v6W5I~//~v6W6R~
//          if (rc2==1)                                              //~v6W5I~//~v6W6R~
//            pcchar++;                                              //~v6W5I~//~v6W6R~
//#endif                                                             //~v6W5I~//~v6W6R~
        }                                                          //~v653I~
        else                                                       //~v653I~
        {//!swcombine                                               //~v656I~//~v7bER~
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
//  			  if (UDBCSCHK_ISUCS_DBCS1STW(dbcsid) && wcwidth(ucs)==2)	//WideDBCS but wcwidth=1//~v6VcR~
    			  if (wcwidth(ucs)==2)	//WideDBCS but wcwidth=1   //~v6VcI~
                  {                                                //~v6VcI~
                    pcchar->chars[0]=ch;                           //~v653I~
                    *(pcchar+1)=*pcchar;                           //~v653I~
//                  pcchar->attr|=1;    //1st of dbcs              //~v653I~//~v6W8R~
                    pcchar->attr|=UVIOMATTR_DBCS1;    //1st of dbcs//~v6W8I~
//                  (pcchar+1)->attr|=2;    //1st of dbcs          //~v653I~//~v6W8R~
                    (pcchar+1)->attr|=UVIOMATTR_DBCS2;    //1st of dbcs//~v6W8I~
                  }                                                //~v6VcI~
                  else                                             //~v6VcI~
                  {                                                //~v6VcI~
                    pcchar->chars[0]=ch;                           //~v6VcI~
                    pcchar->attr|=UVIOMATTR_EXT_WIDESBCS;// 0x800000, advance 1 col at mvadd//~v7bDI~
#ifdef HHH                                                         //~v7bCI~
                    *(pcchar+1)=*pcchar;                           //~v6VcI~
			    	(pcchar+1)->chars[0]=' ';                      //~v6VcI~
#else                                                              //~v7bCI~
					pcchar--;	//for loop,pcchar+=1+dbcssw==>pcchar++//~v7bCI~
#endif                                                             //~v7bCI~
                    UTRACEP("%s:apiwidth=1 for dbcsid=%c ucs=0x%04x\n",UTT,dbcsid,ch);//~v6VcI~//~v7bCR~
                  }                                                //~v6VcI~
                }                                                  //~v653I~
                else								//usial SBCS(also wcwidt=1)//~v653I~
                {                                                  //~v653I~
                    pcchar->chars[0]=ch;                           //~v653I~
                }                                                  //~v653I~
            }//errsw                                               //~v653I~
		}//not ascii                                               //~v653I~
        	if (swbreak)                                           //~v656I~
            {                                                      //~v7bDI~
//          	pcchar->attr|=UVIOMATTR_BREAK;	//substring breaker//~v656I~//~v7bDR~
            	pcchar_current->attr|=UVIOMATTR_BREAK;	//substring breaker//~v7bDI~
				UTRACED("set break",pcchar,CCHSZ);                 //~v7bDI~
				UTRACED("set break current",pcchar_current,CCHSZ);         //~v7bDI~//~v7bJR~
            }                                                      //~v7bDI~
        }//swcombine                                               //~v656I~
//      combinectr=0;                                              //~v653I~//~v7bZR~
    }//for                                                         //~v653I~
//  outctr=((ULONG)pcchar-(ULONG)Ppcchar)/CCHSZ;                   //~v653I~//~v6BhR~
    outctr=(int)((ULPTR)pcchar-(ULPTR)Ppcchar)/CCHSZ;              //~v6BhR~
    if (Ppoutctr)                                                  //~v653I~
    	*Ppoutctr=outctr;                                          //~v653I~
UTRACEP("%s: return row=%d,col=%d,outctr=%d,inctr=%d\n",UTT,Prow,Pcol,outctr,Plen);  //~v653I~//~v7c4R~
UTRACED("cht2cchar out cchar",Ppcchar,outctr*CCHSZ);               //~v653I~
    return rc;                                                     //~v653I~
}//uvio_ddcht2cchar_ligature                                       //~v653R~
#endif //!XXE                                                      //~v640I~
#endif //LNX                                                       //~v640I~
//#ifdef LNX                                                         //~v6BYI~//~v6BZR~
//#ifndef XXE                                                        //~v6BYI~//~v6BZR~
#ifndef XXE                                                        //~v6X5I~
#ifdef TTT //no caller                                             //~v7bUI~
//**************************************************               //~v650I~
//*get combine ctr                                                 //~v650I~
//*Not Used TTT                                                    //~v7c8I~
//**************************************************               //~v650I~
//int uvio_getcombinectr(int Popt,int Pucs,int Pchwidth,UCHAR *Ppdbcs,int Plen)//~v650R~//~v6BTR~
//#ifdef WWW                                                         //~v6BYI~//~v6BZR~
//#ifdef LNX                                                         //~v6V5I~//~v6VgR~
int uvio_getcombinectr(int Popt,WUCS Pucs,int Pchwidth,chtype *Ppcht,UCHAR *Ppdbcs,int Plen)//~v6V5I~
//#else                                                              //~v6V5I~//~v6VgR~
//int uvio_getcombinectr(int Popt,WUCS Pucs,int Pchwidth,UCHAR *Ppdbcs,int Plen)//~v6BTI~//~v6VgR~
//#endif                                                             //~v6V5I~//~v6VgR~
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
    int swcombine;                                                 //~v6V5I~
//***********************                                          //~v650I~
    pcd=Ppdbcs;                                                    //~v650R~
//  if (UTF_COMBINABLE(Pucs)                                       //~v650R~//~v6WsR~
//#ifdef WWW                                                         //~v6BYI~//~v6BZR~
//#ifdef LNX                                                         //~v6V5I~//~v6VgR~
//  && !uviom_ISUCSWIDTH0(0,Ppcht,Ppdbcs,Plen,0/*out ucs*/))	//acceptable combine//~v6V5I~//~v6WsR~
//#else                                                              //~v6V5I~//~v6VgR~
//  && !UDBCSCHK_ISUCSWIDTH0(*pcd))	//acceptable combine           //~v650I~//~v6VgR~
//#endif                                                             //~v6V5I~//~v6VgR~
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
#ifdef FFF                                                         //~v6X5I~
            swcombine=uviom_ISUCSWIDTH0(0,Ppcht+Pchwidth+ii,pcd,Plen-Pchwidth-ii,0/*out ucs*/);//~v6V5R~
#else                                                              //~v6X5I~
//          swcombine=uviom_ISUCSWIDTH0(IUW0O_COMB2SCM_COMB,Ppcht+Pchwidth+ii,pcd,Plen-Pchwidth-ii,0/*out ucs*/);//~v6X5I~//~v7bBR~
            int opt=IUW0O_COMB2SCM_COMB|IUW0O_NOZWJZWNJ;    //rc=0 for ZWJ/ZANJ//~v7bBI~
            swcombine=uviom_ISUCSWIDTH0(opt,Ppcht+Pchwidth+ii,pcd,Plen-Pchwidth-ii,0/*out ucs*/);//~v7bBI~
#endif                                                             //~v6X5I~
            if (!swcombine)   //acceptable combine                 //~v6V5I~
//#else                                                              //~v6BYI~//~v6BZR~
//            dbcswk[0]=(char)(*pcht & A_CHAR_TEXT);                 //~v6BYI~//~v6BZR~
//            if (!UTF_ISDDWIDTH0(dbcswk,pcd,1,0/*pddwidth*/))   //acceptable combine//~v6BYI~//~v6BZR~
//#endif                                                             //~v6BYI~//~v6BZR~
                break;                                             //~v650I~
            if (!combinectr)                                       //~v6WsI~
            {                                                      //~v6WsI~
				if (!UTF_COMBINABLE(Pucs)                          //~v6WsI~
#ifdef FFF                                                         //~v6X5I~
				||   uviom_ISUCSWIDTH0(0,Ppcht,Ppdbcs,Plen,0/*out ucs*/))	//acceptable combine//~v6WsI~
#else                                                              //~v6X5I~
				||   uviom_ISUCSWIDTH0(IUW0O_COMB2SCM_COMB,Ppcht,Ppdbcs,Plen,0/*out ucs*/))	//acceptable combine//~v6X5I~
#endif                                                             //~v6X5I~
        	        break;                                         //~v6WsI~
            }                                                      //~v6WsI~
            combinectr++;                                          //~v650I~
            if (swcombine==2)                                      //~v6V5I~
            {                                                      //~v6VgI~
            	ii++,pcd++;                                        //~v6V5R~
			}                                                      //~v6VgI~
        }                                                          //~v650I~
    }                                                              //~v650I~
UTRACEP("%s: ucs=%04x,rc=%d\n",UTT,Pucs,combinectr);                     //~v656I~//~v6BZR~//~v6VgR~
    return combinectr;                                             //~v650I~
}//uvio_getcombinectr                                              //~v650I~
#endif //TTT                                                       //~v7bUI~
#endif //!XXE                                                      //~v6X5I~
#endif                                                             //~v640I~
#endif //XSUB                                                      //~v6hhI~
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
    int flag=0,optutfww=0;                                         //~v6V3R~
    int utfww;                                                     //~v7f3I~
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
#ifdef AAA                                                         //~v7f3I~
        if (Popt & UVMSUUO_OVF                                     //~v6V3I~
        && (Papiwidth==0 || utfwcwidth(optutfww,(ULONG)Pucs,&flag)==0))//~v6V3R~
#else                                                              //~v7f3I~
        if (Papiwidth==0)                                          //~v7f3I~
#endif                                                             //~v7f3I~
        {                                                          //~v6V3I~
        	utfww=utfwcwidth(optutfww,(ULONG)Pucs,&flag);          //~v7f3I~
           	UTRACEP("%s:apiwidth=0,ucs=%04x,utfwcwidth=%d\n",UTT,(wchar_t)Pucs,utfww);       //~v6V3I~//~v7atR~//~v7f3R~
          if (utfww==2)                                            //~v7f3I~
          {                                                        //~v7f3I~
        	*(pcchar+1)=*pcchar;                                   //~v7f3I~
            pcchar->attr|=UVIOMATTR_DBCS1;    //1st of dbcs        //~v7f3I~
            pcchar++;                                              //~v7f3I~
            pcchar->attr|=UVIOMATTR_DBCS2;    //1st of dbcs        //~v7f3I~
          }                                                        //~v7f3I~
          else                                                     //~v7f3I~
          if (utfww==1)                                            //~v7f3I~
          {                                                        //~v7f3I~
        	*(pcchar+1)=*pcchar;                                   //~v7f3I~
            pcchar++;                                              //~v7f3I~
            pcchar->chars[0]=' ';                                  //~v7f3I~
          }                                                        //~v7f3I~
          else //utfwcwidth=0                                      //~v7f3I~
          {                                                        //~v7f3I~
           	UTRACEP("%s:apiwidth=0 and utfwcwidth=0,ucs=%04x\n",UTT,(wchar_t)Pucs);//~v7f3I~
          }                                                        //~v7f3I~
        }                                                          //~v6V3I~
        else                                                       //~v6V3I~
        if (Papiwidth==2)                                          //~v6DaR~
        {                                                          //~v6DaI~
        	*(pcchar+1)=*pcchar;                                   //~v6DaI~
//          pcchar->attr|=1;    //1st of dbcs                      //~v6DaI~//~v6W8R~
            pcchar->attr|=UVIOMATTR_DBCS1;    //1st of dbcs        //~v6W8I~
            pcchar++;                                              //~v6DaI~
//          pcchar->attr|=2;    //1st of dbcs                  //~v6DaI~//~v6DcR~//~v6W8R~
            pcchar->attr|=UVIOMATTR_DBCS2;    //1st of dbcs        //~v6W8I~
        }                                                          //~v6DaI~
        else                                                       //~v6DaI~
        if (Papiwidth==1)                                          //~v6DaR~
        {                                                          //~v6DaI~
	      if (Popt & UVMSUUO_OVF && utfwcwidth(optutfww,(ULONG)Pucs,&flag)==2)//~v6V3R~
          {                                                        //~v6V3I~
#ifdef AAA                                                         //~v6VdI~
        	*(pcchar+1)=*pcchar;                                   //~v6V3I~
//          pcchar->attr|=1;    //1st of dbcs                      //~v6V3I~//~v6W8R~
            pcchar->attr|=UVIOMATTR_DBCS1;    //1st of dbcs        //~v6W8I~
//          (pcchar+1)->attr|=2;    //1st of dbcs                  //~v6V3I~//~v6W8R~
            (pcchar+1)->attr|=UVIOMATTR_DBCS2;    //1st of dbcs    //~v6W8I~
            pcchar++;                                              //~v6V3I~
#else                                  //ucs + " "                 //~v6VdI~
        	*(pcchar+1)=*pcchar;                                   //~v6VdI~
            pcchar++;                                              //~v6VdI~
#ifdef AAA                                                         //~v7eqI~//~v7erR~
            pcchar->chars[0]=Guviomdbcspad;                        //~v6VdI~
#else                                                              //~v7eqI~
            pcchar->chars[0]=' ';                                  //~v7eqI~
            UTRACEP("%s:TEST set space\n",UTT);                    //~v7eqI~
#endif                                                             //~v7eqI~
           	pcchar->attr=uviom_set_padattr(0,pcchar->attr);        //~v7eiI~
            pcchar->attr|=UVIOMATTR_EXT_PADDCOMB;	// 0x20000000     //padding beteen base and combining//~v7eiI~
#endif                                                             //~v6VdI~
          }                                                        //~v6V3I~
          else                                                     //~v6V3I~
          {                                                        //~v6V3I~
                                                                   //~v6VdI~
        	*(pcchar+1)=*pcchar;                                   //~v6DaI~
            pcchar++;                                              //~v6DaI~
           	pcchar->chars[0]=errrep;                               //~v6DaR~
           	pcchar->attr=uviom_set_padattr(0,pcchar->attr);        //~v6DaI~
          }                                                        //~v6V3I~
        }                                                          //~v6DaI~
        else                                                       //~v6DaI~
        {                                                          //~v6DaI~
	      if (Popt & UVMSUUO_OVF)                                  //~v6DaR~
          {                                                        //~v6DaI~
//         	pcchar->chars[0]=CHAR_UCS_DBCS_ERR;                    //~v6DaI~//~v6DcR~
           	pcchar->chars[0]=UTF_UNPDBCS;   //square               //~v6DcI~
        	*(pcchar+1)=*pcchar;                                   //~v6DaI~
//          pcchar->attr|=1;    //1st of dbcs                      //~v6DaI~//~v6W8R~
            pcchar->attr|=UVIOMATTR_DBCS1;    //1st of dbcs        //~v6W8I~
//          (pcchar+1)->attr|=2;    //1st of dbcs                  //~v6DaM~//~v6W8R~
            (pcchar+1)->attr|=UVIOMATTR_DBCS2;    //1st of dbcs    //~v6W8I~
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
    UTRACEP("%s:bgfg=%08x,attrold=%04x\n",UTT,bgfg,attrold);              //~v6EnI~//~v6WuR~
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
//#ifdef W32                                                       //~v6EoR~
	#ifndef XXE                                                    //~v700I~
//***************************************************************************//~v6V5I~
//UDBCSCHK_ISUCSWIDTH0 for also ucs4                               //~v6V5I~
//rc:1:ucs2,2:dbcs/ucs4,0:!width0                                       //~v6V5I~//~v7bDR~
//***************************************************************************//~v6V5I~
#ifdef TTT //no caller                                             //~v7f1I~
int uviom_ISUCSWIDTH0(int Popt,chtype *Ppcht,UCHAR *Ppdbcs,int Plen,WUCS *Ppucs4)//~v6V5R~
{                                                                  //~v6V5I~
	int rc=0;                                                      //~v6V5R~
    WUCS ucs=0;                                                    //~v6V5I~
    UCHAR ch;                                                      //~v6V5I~
//**************************                                       //~v6V5I~
	if (UDBCSCHK_ISUCSWIDTH0(*Ppdbcs))                             //~v6V5I~
    {                                                              //~v6V5I~
		ch=*Ppcht & A_CHARTEXT;                                    //~v6V5I~
        ucs=(WUCS)UTF_GETUCSSBCS(&ch,Ppdbcs);                      //~v6V5I~
    	rc=1;                                                      //~v6V5I~
    }                                                              //~v6V5I~
    else                                                           //~v6V5I~
    if (Plen>1)                                                    //~v6V5I~
    {	                                                           //~v6V5I~
//      if (UDBCSCHK_DBCS1STUCS2(*Ppdbcs))                         //~v6W9R~
//        rc=utf22_iswidth0DBCS(0,*Ppcht & A_CHARTEXT,*(Ppcht+1) & A_CHARTEXT,*Ppdbcs,*(Ppdbcs+1),&ucs);//~v6W9R~
//       else                                                      //~v6W9R~
#ifdef FFF                                                         //~v6X5M~
#else                                                              //~v6X5M~
#ifndef XXE                                                        //~v6X5I~
	  if (Popt & IUW0O_COMB2SCM_COMB)                              //~v6X5I~
		rc=uviom_iscombining(0,Ppcht,Ppdbcs,Plen,&ucs,0/*Ppchsz*/);//~v6X5R~
      else                                                         //~v6X5I~
#endif                                                             //~v6X5I~
#endif                                                             //~v6X5M~
		rc=utf22_iswidth0Ovf(0,*Ppcht & A_CHARTEXT,*(Ppcht+1) & A_CHARTEXT,*Ppdbcs,*(Ppdbcs+1),&ucs);//~v6V5R~
        if (rc)                                                    //~v6V5I~
        	rc=2;                                                  //~v6V5I~
    }                                                              //~v6V5I~
    if (Ppucs4)                                                    //~v6V5R~
	    *Ppucs4=ucs;                                               //~v6V5R~
//    if (Popt & IUW0O_NOZWJZWNJ    //rc=0 for ZWJ/ZANJ              //~v7bBI~//~v7bVR~
//    &&  UTF_ISZWJZWNJ(ucs))                                        //~v7bBI~//~v7bVR~
    if (Popt & IUW0O_NOCOMB //          0x02    //return false width=0 but not combining//~v7bVI~
    &&  rc & UICRC_NOCOMB)	//not combining wcw=0                  //~v7bVI~
    {                                                              //~v7bBI~
        rc=0;                                                      //~v7bBI~
      	UTRACEP("%s:rc=0 byNOCOMB ucs=0x%04x\n",UTT,ucs);       //~v7bBR~//~v7bWR~
    }                                                              //~v7bBI~
    UTRACEP("%s:rc=%d,dbcsid=%02x,ucs=%04x\n",UTT,rc,*Ppdbcs,ucs); //~v6V5I~
    return rc;                                                     //~v6V5I~
}//uviom_ISUCSWIDTH0                                               //~v6V5I~
#endif //TTT                                                       //~v7f1I~
	#endif	//!XXE                                                 //~v700I~
#ifndef XXE                                                        //~v6WuI~
//***************************************************************************//~v6WuI~
//chk combining(NSCM and SCM)                                      //~v6WuI~
//rc=8(UIRC_NOCOMB) for wcw=0 but not combining(category Cf etc)   //~v7bVR~
//rc:1:ucs2,2:dbcs/ucs4,0:!width0,4:SCM                                 //~v6WuR~//~v7bDR~
//***************************************************************************//~v6WuI~
int uviom_iscombining(int Popt,chtype *Ppcht,UCHAR *Ppdbcs,int Plen,WUCS *Ppucs,int *Ppchsz)//~v6WuR~
{                                                                  //~v6WuI~
	int rc=0,dbcsid,chsz=1,opt4=0;                                        //~v6WuR~//~v7bVR~
    WUCS ucs;                                                      //~v6WuI~
    UCHAR wkdddata[2];                                             //~v6WuI~
//**************************                                       //~v6WuI~
  	if (Popt & ICO_NOFMT) //           0x02    //excluse scm(and comb2scm) and format//~v7bVI~
		opt4|=UICO_COMBONLY;	//exclude FMT                      //~v7bVI~
  	if (Popt & ICO_NOFMTRC) //           0x04    //excluse scm(and comb2scm) and format//~v7bVI~
		opt4|=UICO_RCNOCOMB;	//set rc:8 for FMT                 //~v7bVI~
  	if (!(Popt & ICO_NOCOMB2SCMRC)) //         0x08    //excluse scm(and comb2scm) and format//~v7bVR~
		opt4|=UICO_RCCOMB2SCM;  //set rc:8 for FMT                 //~v7bVI~
#ifndef JJJ                                                        //~v7f5R~
  	if (Popt & ICO_ZWJASCOMB) //         0x08    //excluse scm(and comb2scm) and format//~v7f5I~
		opt4|=UICO_ZWJASCOMB;   //              0x04    //set UICRC_NOCOMB for w0-no combine char//~v7f5R~
#endif                                                             //~v7f5I~
    UTRACEP("%s:opt=0x%02x,opt4=0x%02x\n",UTT,Popt,opt4);          //~v7bVI~
	ucs=*Ppcht & A_CHARTEXT;                                       //~v6WuI~
    dbcsid=*Ppdbcs;                                                //~v6WuR~
	if (dbcsid)	//>=0x80                                           //~v6WuR~
    {                                                              //~v6WuI~
    	if (UDBCSCHK_ISUCSSBCS(dbcsid))                            //~v6WuI~
        {                                                          //~v6WuI~
            wkdddata[0]=(UCHAR)ucs;                                //~v6X8I~
        	ucs=(WUCS)UTF_GETUCSSBCS(wkdddata,Ppdbcs);             //~v6WuI~
//			rc=UDBCSCHK_ISUCSWIDTH0(dbcsid);                       //~v6WuI~//~v7bVR~
            rc=utf_iscombining(opt4,dbcsid,(ULONG)ucs);            //~v7bVR~
    	}                                                          //~v6WuI~
    	else                                                       //~v6WuI~
		if (UDBCSCHK_DBCS1STUCS2NWO(dbcsid)) //DBCS/WIDE/NARROW/OVERFLOW//~v6WuR~
        {                                                          //~v6WuI~
            if (Plen>1)                                            //~v6WuI~
            {                                                      //~v6WuR~
                wkdddata[0]=(UCHAR)ucs;                            //~v6WuI~
                wkdddata[1]=(UCHAR)(*(Ppcht+1) & A_CHARTEXT);      //~v6WuI~
                ucs=utfdd2u1(0,wkdddata,Ppdbcs,2);                 //~v6WuI~
//              rc=utf_iscombining(0,dbcsid,(ULONG)ucs);           //~v6WuR~//~v6X5R~
//              rc=utf_iscombining(UICO_RCCOMB2SCM/*return COMB2SCM*/,dbcsid,(ULONG)ucs);//~v6X5R~//~v7bVR~
                rc=utf_iscombining(opt4,dbcsid,(ULONG)ucs);//rc=2 for comb2scm//~v7bVR~
                //*rc=0 for ZWNJ/ZWJ by categror Cf(Format)        //~v7bBR~
#ifdef FFF                                                         //~v6X5I~
#else                                                              //~v6X5I~
                if (rc & UICRC_COMB2SCM)                           //~v6X5R~
                {                                                  //~v7bBI~
      				UTRACEP("%s:rc=2 of utf_iscombining ucs=0x%04x\n",UTT,ucs);//~v7bBI~
                    rc=UICRC_OVF;      //2cell                     //~v6X5R~
                }                                                  //~v7bBI~
#endif                                                             //~v6X5I~
                chsz=2;                                            //~v6WuI~
            }                                                      //~v6WuR~
            else                                                   //~v6WuI~
            	chsz=-1;	//err id                               //~v6WuI~
        }                                                          //~v6WuI~
    }                                                              //~v6WuI~
//    if (UTF_ISZWJZWNJ(ucs))                                        //~v7bBI~//~v7bVR~
//    {                                                              //~v7bBI~//~v7bVR~
//      if (Popt & ICO_NOZWJZWNJ)  //      0x01    //return false for ZWJ(200d)/ZWNJ(200c)//~v7bNR~//~v7bVR~
//      {                                                            //~v7bNI~//~v7bVR~
//        rc=0;                                                      //~v7bBR~//~v7bVR~
//        UTRACEP("%s:rc=0,By option, Not combining for ZWJ/ZWNJ ucs=0x%04x\n",UTT,ucs);//~v7bBI~//~v7bNR~//~v7bVR~
//      }                                                            //~v7bNI~//~v7bVR~
//    }                                                              //~v7bBI~//~v7bVR~
	if (Popt & ICO_NOSCM) //           0x02    //excluse scm(and comb2scm) and format//~v7bVI~
    	if (rc & UICRC_SCM)                                        //~v7bVI~
        {                                                          //~v7bVI~
      		UTRACEP("%s:rc=0 for SCM by NOSCM option ucs=0x%04x\n",UTT,ucs);//~v7bVI~
        	rc=0;                                                  //~v7bVI~
        }                                                          //~v7bVI~
    if (Ppucs)                                                     //~v6WuI~
    	*Ppucs=ucs;                                                //~v6WuR~
    if (Ppchsz)                                                    //~v6WuI~
    	*Ppchsz=chsz;                                              //~v6WuR~
    UTRACEP("%s:rc=%d,dbcsid=%02x,ucs=%06x,chsz=%d,Plen=%d,\n",UTT,rc,*Ppdbcs,ucs,chsz,Plen);//~v6WuR~
    return rc;                                                     //~v6WuI~
}//uviom_iscombining                                               //~v6WuR~
#endif                                                             //~v6WuI~
#ifndef XXE                                                        //~v6W6I~
//***************************************************************  //~v6W6I~
void uviom_spaceclear(int Popt,int Prow,int Pcol,int Plinewidth)   //~v6W6I~
{                                                                  //~v6W6I~
	uviom_mvaddwchnstr(Prow,Pcol,Spspacelinew,Plinewidth);         //~v6W6I~
	UTRACEP("%s:space clear row=%d,col=%d,widthlen=%d\n",UTT,Prow,Pcol,Plinewidth);//~v6W6I~
	UTRACED("Spspacelinew[0]",Spspaceline,sizeof(Spspaceline[0])); //~v7ezR~
#ifdef GGG    	                                                   //~v6W6I~
#else                                                              //~v6W6I~
	if (!(Popt & SCO_NOREFRESH))                                   //~v6W6I~
    {                                                              //~v6W6I~
    	uviol_refresh();    //for virtical line draw column        //~v6W6R~
		UTRACEP("%s:refresh after space clear\n",UTT);             //~v6W6R~
    }                                                              //~v6W6I~
#endif                                                             //~v6W6I~
}//uviom_spaceclear                                                //~v6W6I~
//***************************************************************  //~v6W6I~
void uviom_clearscr(int Popt)                                      //~v6W6I~
{                                                                  //~v6W6I~
	int row,maxrow;                                                //~v6W6I~
//***************                                                  //~v6W6I~
    if (!Sscrsize)                                                 //~v6W6I~
    	return;		//not yet uviom_init                           //~v6W6I~
    maxrow=Sscrsize/Sscrwidth;                                     //~v6W6I~
	for (row=0;row<maxrow;row++)                                   //~v6W6I~
		uviom_spaceclear(SCO_NOREFRESH,row,0,Sscrwidth);           //~v6W6I~
    uviol_refresh();    //for virtical line draw column            //~v6W6I~
	UTRACEP("%s:refresh after all line clear row=%d,col=%d\n",UTT,maxrow,Sscrwidth);//~v6W6I~
}//uviom_spaceclear                                                //~v6W6I~
#endif //XXE                                                       //~v6W6I~
//***************************************************************  //~v6WrI~
//*return ucs ctr                                                  //~v6WrI~
//!!! use only when COMBINE_NP
//***************************************************************  //~v6WrI~
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
#ifdef XXE                                                         //~v7bGI~
//***************************************************************  //~v6WrI~
//*return utf8 srelen                                              //~v6WrI~
//*(altch is restricted to sbcs at xeopt2.c)                       //~v6WrI~
//!!! use only when COMBINE_NP
//!!! when Linux consol Gutfcombaltch=Goptcombaltch(it is not GoptcombaltchNP)//~v6WrI~
//***************************************************************  //~v6WrI~
int uviom_getcombaltchU8(int Popt,char *Pu8,char *Ppdddata,char *Ppdddbcs,int *Ppddlen)//~v6WrR~
{                                                                  //~v6WrI~
	int lenalt,ddlen;                                              //~v6WrR~
    static char Swku8[8];                                          //~v6WrR~
    static int Soldaltch,Slenalt,Sddlen;                           //~v6WrR~
    static UCHAR Swkdddata[8],Swkdddbcs[8];                        //~v6WrI~
    int altch;
//*******************                                              //~v6WrI~
#if defined LNX && !defined XXE	//linux console
	altch=Scombaltch;
#else
	altch=Gutfcombaltch;
#endif
//  if (Soldaltch!=Gutfcombaltch)                                  //~v6WrI~
    if (Soldaltch!=altch)
    {                                                              //~v6WrI~
    	UTRACED("%s Gutucombaltch=%04x\n",UTT,altch);      //~v6WrI~
//    if (Gutfcombaltch>=0x20)                                     //~v6WrI~
      if (altch>=0x20)
      {                                                            //~v6WrI~
//  	Soldaltch=Gutfcombaltch;                                   //~v6WrI~
    	Soldaltch=altch;
//    	Slenalt=uccvucs2utf(Gutfcombaltch,Swku8);                  //~v6WrR~
      	Slenalt=uccvucs2utf(Soldaltch,Swku8);
//      utfcvu2dd1(0,Gutfcombaltch,Swkdddata,Swkdddbcs,&Sddlen);   //~v6WrI~
        utfcvu2dd1(0,(WUCS)Soldaltch,Swkdddata,Swkdddbcs,&Sddlen); //~v6WuR~
      }                                                            //~v6WrI~
      else                                                         //~v6WrI~
      {                                                            //~v6WrI~
    	Soldaltch=':';                                             //~v6WrI~
    	Slenalt=1;                                                 //~v6WrI~
        Swku8[0]=(char)Soldaltch;                                  //~v6WrR~
        Swkdddata[0]=0;                                            //~v6WrI~
        Swkdddbcs[0]=0;                                            //~v6WrI~
      }                                                            //~v6WrI~
    }                                                              //~v6WrI~
    lenalt=Slenalt;                                                //~v6WrI~
    ddlen=Sddlen;                                                  //~v6WrI~
    if (Popt & UVIOM_GCAC_2CELL)                                   //~v6WrR~
    {                                                              //~v6WrI~
    	Swku8[lenalt++]=UVIOM_COMBINE_ALTCH2;                      //~v6WrR~
        Swkdddata[ddlen]=UVIOM_COMBINE_ALTCH2;                     //~v6WrI~
        Swkdddbcs[ddlen++]=0;                                      //~v6WrI~
    }                                                              //~v6WrI~
    memcpy(Pu8,Swku8,(size_t)lenalt);                              //~v6WrI~
    if (Ppdddata)                                                  //~v6WrI~
	    memcpy(Ppdddata,Swkdddata,(size_t)ddlen);                  //~v6WrR~
    if (Ppdddbcs)                                                  //~v6WrI~
	    memcpy(Ppdddbcs,Swkdddbcs,(size_t)ddlen);                  //~v6WrR~
    UTRACED("u8",Swku8,lenalt);                                    //~v6WrR~
    UTRACED("dddata",Swkdddata,ddlen);                             //~v6WrR~
    UTRACED("dddbcs",Swkdddbcs,ddlen);                             //~v6WrR~
    *Ppddlen=Sddlen;                                               //~v6WrI~
    UTRACEP("%s return ddlen=%d,u8len=%d\n",UTT,ddlen,lenalt);     //~v6WrR~
    return lenalt;                                                 //~v6WrI~
}//uviom_getcombaltchU8                                            //~v6WrR~
#endif                                                             //~v7bGI~
#ifdef LNXCON                                                      //~v7bBR~
//***************************************************************  //~v7bBR~
//*set for ZWJ(200d)/ZWNJ(200c)                                    //~v7bBR~
//***************************************************************  //~v7bBR~
int uviom_setcombineJoiner(int Popt,int Plineopt,WUCS Pucs,chtype *Ppcht,cchar_t *Ppcchar)//~v7bBR~
{                                                                  //~v7bBR~
    attr_t attr;                                                   //~v7bBR~
    int rc=0,ucsalt,ucs;                                           //~v7bBR~
//************************                                         //~v7bBR~
UTRACEP("%s:entry opt=%x,ucs=%04x,Scombaltch=%x\n",UTT,Popt,Pucs,Scombaltch);//~v7bBR~
	attr=(attr_t)(uviol_repfg((int)*Ppcht,ATTR_COMBINENP_FG)<<8);  //~v7bBI~
	attr|=UVIOMATTR_BREAK;                                         //~v7bBI~
    if (UTF_COMBINEMODE_NP() && uviom_getcombaltchUcs(0,&ucsalt))  //~v7bBI~
		ucs=ucsalt;                                                //~v7bBI~
   	else                                                           //~v7bBI~
   	if (Scombaltch==UVIOM_ALTCHPADDING)                            //~v7bBR~
		ucs=Guviomdbcspad;                                         //~v7bBR~
   	else                                                           //~v7bJI~
   	if (Scombaltch==UVIOM_ALTCHSHADOW)                             //~v7bJI~
    	ucs=Pucs;                                                  //~v7bJI~
   	else                                                           //~v7bJI~
   	if (Scombaltch==UVIOM_ALTCHITSELF)                             //~v7bJI~
    {                                                              //~v7bJI~
		ucs=COMBAINE_BASE_SPLIT_ITSELF;// 0xa0     //u00a0 base for combining char when split itself//~v7bJI~
    	Ppcchar->chars[1]=Pucs;                                    //~v7bJI~
    }                                                              //~v7bJI~
   	else                                                           //~v7bBR~
		ucs=UVIOM_COMBINE_ALTCH2;  //'.'                           //~v7bBI~
    Ppcchar->attr=attr;                                            //~v7bBI~
    Ppcchar->chars[0]=ucs;                                         //~v7bBI~
	UTRACEP("%s:attr=0x%04x,ucs=0x%04x\n",UTT,attr,ucs);           //~v7bBI~
	UTRACED("out Ppcchar",Ppcchar,CCHSZ);                          //~v7bBR~
    return rc;   //outctr=1/2                                      //~v7bBR~
}//uviom_setcombineJoiner                                          //~v7bBR~
//***************************************************************  //~v7bNI~
//*set for ZWJ(200d)                                               //~v7bNI~
//*NO caller                                                       //~v7bWI~
//***************************************************************  //~v7bNI~
int uviom_setcombineZWJ(int Popt,int PswBreak,PCCH  Ppcchar0,PCCH Ppcchar,int *Ppoutctr)//~v7bNI~
{                                                                  //~v7bNI~
    int combinectr;                                                //~v7bNR~
    PCCH base;                                                     //~v7bNI~
//  WUCS ucscombine;                                               //~v7bNI~//~v7bZR~
//************************                                         //~v7bNI~
UTRACEP("%s:entry opt=%x,swBreak=%d\n",UTT,Popt,PswBreak);         //~v7bNI~
	if (PswBreak)                                                  //~v7bNI~
    {                                                              //~v7bNI~
		UTRACEP("%s:return 0 by swBreak\n",UTT);                   //~v7bNI~
    	return 0;                                                  //~v7bNI~
    }                                                              //~v7bNI~
	base=setBaseEntry(0,Ppcchar0,Ppcchar,0/*Pcolor*/,0/*ucs=0:find base*/,0/*pcombctr*/);//~v7bNI~
    if (!base)                                                     //~v7bNI~
    {                                                              //~v7bNI~
		UTRACEP("%s:return 0 by base not found\n",UTT);            //~v7bNI~
    	return 0;                                                  //~v7bNI~
    }                                                              //~v7bNI~
    UTRACED("base",base,CCHSZ);                                    //~v7bNI~
    attr_t attr=base->attr;                                        //~v7bNI~
    if (!(attr & UVIOMATTR_EXT_COMBBASE)                           //~v7bNI~
    ||   (attr & UVIOMATTR_EXT_SCMBASE))                           //~v7bNI~
    {                                                              //~v7bNI~
		UTRACEP("%s:return 0 by base attr(0x%04x) is not combBase or is SCMbase\n",UTT,attr);//~v7bNI~
    	return 0;                                                  //~v7bNI~
    }                                                              //~v7bNI~
    for (combinectr=0;combinectr<UVIOM_MAXCOMBINE;combinectr++)    //~v7bNI~
    {                                                              //~v7bNI~
        if (!base->chars[combinectr])                              //~v7bNI~
            break;                                                 //~v7bNI~
    }                                                              //~v7bNI~
    combinectr--;                                                  //~v7bNI~
    if (combinectr<=0)                                             //~v7bNI~
    {                                                              //~v7bNI~
		UTRACEP("%s:return 0 by combinectr(%d)<=0\n",UTT,combinectr);//~v7bNI~
    	return 0;                                                  //~v7bNI~
    }                                                              //~v7bNI~
//  ucscombine=base->chars[combinectr];                            //~v7bNI~//~v7bZR~
    attr=(base->attr & UVIOMATTR_COLORMASK);                       //~v7bNR~
	UTRACEP("%s:attr=0x%04x\n",UTT,attr);//~v7bNI~                 //~v7bZR~
#ifdef AAA                                                         //~v7bNI~
//*write base+comb+ZWJ sequensially is no effect for ZWJ combine   //~v7bNI~
    Ppcchar->chars[0]=ucscombine;                                  //~v7bNR~
    Ppcchar->attr=attr;                                            //~v7bNR~
    *(Ppcchar+1)=*Ppcchar;                                         //~v7bNR~
    (Ppcchar+1)->chars[0]=ZWJ;	//200d                             //~v7bNR~
    *Ppoutctr=2;                                                   //~v7bNI~
                                                                   //~v7bNI~
    base->chars[combinectr]=0;                                     //~v7bNI~
    if (combinectr==1)                                             //~v7bNR~
    	base->attr &= (attr_t)(~UVIOMATTR_EXT_COMBBASE);           //~v7bNR~
#else                                                              //~v7bNR~
#ifdef AAA                                                         //~v7bNI~
//*add ZWJ entry                                                   //~v7bNI~
    Ppcchar->chars[0]=ZWJ;                                         //~v7bNR~
    Ppcchar->attr=attr;                                            //~v7bNI~
    *Ppoutctr=1;                                                   //~v7bNI~
#else                                                              //~v7bNI~
#ifdef AAA                                                         //~v7bNR~
//*add ZWJ as combining                                            //~v7bNI~
    if (combinectr==UVIOM_MAXCOMBINE)                              //~v7bNR~
    {                                                              //~v7bNI~
		UTRACEP("%s:return 0 by max combinectr(%d)<=0\n",UTT,combinectr);//~v7bNI~
    	return 0;                                                  //~v7bNI~
    }                                                              //~v7bNI~
    base->chars[combinectr+1]=ZWJ;                                 //~v7bNR~
    *Ppoutctr=0;                                                   //~v7bNI~
#else                                                              //~v7bNI~
    *Ppoutctr=0;                                                   //~v7bNI~
    if (1)                                                         //~v7bNI~
    {                                                              //~v7bNI~
		UTRACEP("%s:return 0 AAA\n",UTT);                          //~v7bNI~
        return 0;                                                  //~v7bNI~
    }                                                              //~v7bNI~
#endif                                                             //~v7bNI~
#endif                                                             //~v7bNI~
#endif                                                             //~v7bNI~
	UTRACEP("%s:return 1 outctr=%d\n",UTT,*Ppoutctr);              //~v7bNI~
    return 1;                                                      //~v7bNI~
}//uviom_setcombineZWJ                                             //~v7bNI~
#endif //LNXCON                                                    //~v7bBR~
#ifdef LNXCON                                                      //~v7bEI~
//***************************************************************************//~v7bEI~
void uviom_setccharSCM_itself(int Popt,WUCS Pucs,cchar_t *Ppcchar) //~v7bER~
{                                                                  //~v7bEI~
	UTRACEP("%s:opt=0x%04x,Pucs=0x%04x\n",UTT,Popt,Pucs);          //~v7bEI~
//  Ppcchar->chars[0]=COMBAINE_BASE_SPLIT_ITSELF;     //u00a0 base for combining char when split itself//~v7bEI~
//  Ppcchar->chars[1]=Pucs;     //combining char itself            //~v7bEI~
    Ppcchar->chars[0]=Pucs;     //combining char itself            //~v7bEI~
//  if (Popt & UVIOMATTR_EXT_LIGATURE)//extended option, ligature  //~v7bEI~
//  {                                                              //~v7bEI~
//	  	if (Popt & UVIOMATTR_PADDING2)  //for the case ligature not combine mode//~v7bEI~
//  		Ppcchar->attr|=UVIOMATTR_EXT_PADDING2;    //ALTCH2 will be follows//~v7bEI~
//  	Ppcchar->attr|=UVIOMATTR_EXT_DMYBASE;     //added "A0" entry for combining//~v7bEI~
//  }                                                              //~v7bEI~
	Ppcchar->attr|=UVIOMATTR_BREAK|UVIOMATTR_EXT_SCM;              //~v7bJI~
	UTRACED("cchar",Ppcchar,sizeof(cchar_t));                      //~v7bEI~
}//uviom_setccharSCM_itself                                           //~v7bEI~//~v7bGR~
//***************************************************************************//~v7bEI~
void uviom_setccharSCM_shadow(int Popt,WUCS Pucs,cchar_t *Ppcchar,cchar_t *Ppcchar0)//~v7bEI~
{                                                                  //~v7bEI~
	cchar_t *pcchar;                                               //~v7bEI~
    attr_t attr;                                                   //~v7bEI~
//*******************                                              //~v7bEI~
#ifdef KKK                                                         //~v7bJR~
	UTRACEP("%s:opt=0x%04x,Pucs=0x%04x\n",UTT,Popt,Pucs);          //~v7bER~
    pcchar=Ppcchar;                                                //~v7bEI~
//  pcchar->chars[0]=Pucsbase;	//shadow base                      //~v7bEI~
    pcchar->chars[0]=Pucs;	//shadow base                          //~v7bEI~
    attr=(attr_t)(pcchar->attr & UVIOMATTR_COLORMASK);             //~v7bEI~
    {                                                              //~v7bEI~
//	  if (Popt & UVIOMATTR_PADDING2)  //for the case ligature not combine mode//~v7bEI~
//  	pcchar->attr=(attr_t)(attr | (UVIOMATTR_SHADOW | UVIOMATTR_EXT_PADDING2));    //shadow padding for overflowcombining//~v7bEI~
//    else                                                         //~v7bEI~
    	pcchar->attr=(attr_t)(attr | UVIOMATTR_SHADOW); //write with//~v7bEI~
    }                                                              //~v7bEI~
	Ppcchar->attr|=UVIOMATTR_BREAK|UVIOMATTR_EXT_SCM;              //~v7bJR~
    pcchar++;                                                      //~v7bJI~
//  pcchar->chars[1]=Pucs;                                         //~v7bEI~
//	if (Popt & UVIOMATTR_BASEDBCS) //base is dbcs                  //~v7bEI~
//  {                                                              //~v7bEI~
//  	*(pcchar+1)=*pcchar;                                       //~v7bEI~
//  	pcchar->attr|=UVIOMATTR_DBCS1;                             //~v7bEI~
//  	pcchar->attr&=(attr_t)(~UVIOMATTR_EXT_PADDING2);    //shadow padding for overflowcombining//~v7bEI~
//  	(pcchar+1)->attr|=UVIOMATTR_DBCS2;                         //~v7bEI~
//  	(pcchar+1)->attr&=(attr_t)(~(UVIOMATTR_SHADOW|UVIOMATTR_EXT_PADDING2));    //shadow padding for overflowcombining//~v7bEI~
//  }                                                              //~v7bEI~
	UTRACED("cchar",Ppcchar,PTRDIFF(pcchar,Ppcchar)*CCHSZ);//~v7bEI~//~v7bJR~
#else //else KKK                                                   //~v7bJI~
#ifdef BBB                                                         //~v7bJI~
    pcchar=Ppcchar;                                                //~v7bJI~
	attr=uviom_set_padattr(0,pcchar->attr & UVIOMATTR_COLORMASK);  //~v7bJR~
	UTRACEP("%s:opt=0x%04x,Pucs=0x%04x,attr=0x%04x\n",UTT,Popt,Pucs,attr);//~v7bJM~
    PCCH base=getBaseSCM(0,Ppcchar0,Ppcchar);                      //~v7bJR~
    if (base)                                                      //~v7bJI~
    {                                                              //~v7bJI~
#ifdef AAA                                                         //~v7bJI~
		pcchar->chars[0]=base->chars[0];                           //~v7bJI~
    	pcchar->attr=attr;                                         //~v7bJI~
    	pcchar->attr|=(UVIOMATTR_SHADOW|UVIOMATTR_BREAK|UVIOMATTR_EXT_SCM);//~v7bJI~
        pcchar++;                                                  //~v7bJI~
	    pcchar->chars[0]=Pucs;	//shadow base                      //~v7bJI~
    	pcchar->attr|=(UVIOMATTR_SHADOW|UVIOMATTR_EXT_SCM);        //~v7bJR~
#else                                                              //~v7bJI~
		pcchar->chars[0]=base->chars[0];                           //~v7bJI~
    	attr|=(UVIOMATTR_SHADOW|UVIOMATTR_BREAK|UVIOMATTR_EXT_SCM);//~v7bJI~
    	pcchar->attr=attr;                                         //~v7bJI~
	    pcchar->chars[1]=Pucs;	//shadow base                      //~v7bJI~
#endif                                                             //~v7bJI~
    }                                                              //~v7bJI~
    else                                                           //~v7bJR~
    {                                                              //~v7bJI~
    	pcchar->chars[0]=Pucs;	//shadow base                      //~v7bJI~
    	pcchar->attr=attr;                                         //~v7bJI~
    	pcchar->attr|=(UVIOMATTR_SHADOW|UVIOMATTR_BREAK|UVIOMATTR_EXT_SCM);//~v7bJI~
    }                                                              //~v7bJI~
    pcchar++;                                                      //~v7bJI~
	UTRACED("cchar",Ppcchar,PTRDIFF(pcchar,Ppcchar)*CCHSZ);        //~v7bJI~
#else //else BBB                                                   //~v7bJI~
    pcchar=Ppcchar;                                                //~v7bJI~
  if (Popt & UVIOMATTR_SETATTR)   //for the case ligature not combine mode//~v7epI~
  {                                                                //~v7epI~
	attr=uviom_set_padattr(0,pcchar->attr & UVIOMATTR_COLORMASK);  //~v7bJI~
	UTRACEP("%s:opt=0x%04x,Pucs=0x%04x,attr=0x%04x\n",UTT,Popt,Pucs,attr);//~v7bJI~
    pcchar->attr=attr;                                             //~v7epI~
  }                                                                //~v7epI~
    pcchar->chars[0]=Pucs;	//shadow base                          //~v7bJI~
//  pcchar->attr=attr;                                             //~v7bJI~//~v7epR~
//  pcchar->attr|=(UVIOMATTR_SHADOW|UVIOMATTR_BREAK|UVIOMATTR_EXT_SCM);//~v7bJI~//~v7bLR~
    pcchar->attr|=(UVIOMATTR_BREAK|UVIOMATTR_EXT_SCM);	//not shadow but itself for SCM//~v7bLI~
    pcchar++;                                                      //~v7bJI~
	UTRACED("cchar",Ppcchar,PTRDIFF(pcchar,Ppcchar)*CCHSZ);        //~v7bJI~
#endif                                                             //~v7bJI~
#endif //KKK                                                       //~v7bJI~
}//uviom_setccharSCM_shadow                                           //~v7bEI~//~v7bGR~
//*******************************************************          //~v7bEI~
//*rc:1:1 more cchar_t written                                     //~v7bEI~
//*******************************************************          //~v7bEI~
int uviom_setcombineSCM1(int Popt,int Plineopt,WUCS Pucs,chtype *Ppcht,cchar_t *Ppcchar,cchar_t *Ppcchar0)//~v6W6R~//~v7bER~
{                                                                  //~v653I~//~v7bEI~
    int attropt;                                                   //~v6BhI~//~v7bEI~
    attr_t attr;                                                   //~v6BhI~//~v7bEI~
//#define UVIOM_DUMMYBASE  0xfeff //0x00a0 //0x200b                  //~v658R~//~v7bER~
    int rc=0;                                                      //~v6V5R~//~v7bEI~
//  cchar_t *pcchar_padding2;                                      //~v6V5I~//~v7bER~
//  int swShadowDbcs=0;                                            //~v7bsI~//~v7bER~
//	int ucsbase=COMBAINE_BASE_SPLIT_ITSELF; //a0     //u00a0 base for combining char when split itself//~v7bER~
//************************                                         //~v653I~//~v7bEI~
UTRACEP("%s:entry opt=%x,lineopt=0x%04x,ucs=%04x,Scombaltch=%x\n",UTT,Popt,Plineopt,Pucs,Scombaltch);     //~v6D9I~//~v6W2R~//~v6WbR~//~v7bER~
	attropt=Popt & UVIOMATTR_BREAK;                                //~v656I~//~v7bEI~
    if (Popt & UVIOMATTR_EXT_WIDESBCS)// 0x800000, advance 1 col at mvadd//~v7bEI~
	    attropt|=UVIOMATTR_EXT_WIDESBCS;// 0x800000, advance 1 col at mvadd//~v7bEI~
                                                                   //~v7bEI~
  	if (Popt & UVIOMATTR_SETATTR)   //for the case ligature not combine mode//~v656I~//~v7bEI~
  	{                                                                //~v656I~//~v7bEI~
   		if (COMBINEMODE(Plineopt))                                      //~v6EmI~//~v7bEI~
			attr=uviom_set_padattr(0,*Ppcht & A_COLOR)>>8;                 //~v6D9R~//~v7bEI~
   		else                                                            //~v6EmI~//~v7bEI~
   		{                                                               //~v6EmI~//~v7bEI~
    		attr=(attr_t)uviol_repfg((int)*Ppcht,ATTR_COMBINENP_FG);       //~v6EmR~//~v7bEI~
    		UTRACEP("%s:attr rep=%04x\n",UTT,attr);                        //~v6EmR~//~v7bEI~
   		}	                                                               //~v6EmI~//~v7bEI~
  	}                                                                //~v6EmM~//~v7bEI~
  	else                                                             //~v656I~=//~v7bEI~
    	attr=(*Ppcht & ~(A_CHARTEXT))>>8;                              //~v656I~//~v7bEI~
	UTRACEP("%s:attr=0x%04x\n",UTT,attr);                          //~v7bEI~
                                                                   //~v656I~//~v7bEI~
    Ppcchar->attr=(attr<<8);//break flag           //~v6BhI~       //~v7bER~
//    if (UTF_COMBINABLE(Pucsbase))                                    //~v656R~//~v7bER~
//    {                                                                //~v656I~//~v7bER~
//        if (Scombaltch==UVIOM_ALTCHPADDING)                             //~v658I~//~v7bEI~//~v7bKR~
//        {                                                          //~v7bGI~//~v7bKR~
//            Ppcchar->chars[0]=Guviomdbcspad;                               //~v658I~//~v7bEI~//~v7bKR~
//            UTRACEP("%s:ALTCHPADDING set 1 padding %02x\n",UTT,Guviomdbcspad);//~v7bGR~//~v7bKR~
//        }                                                          //~v7bGI~//~v7bKR~
//        else                                                            //~v658I~//~v7bEI~//~v7bKR~
   		if (Scombaltch==UVIOM_ALTCHSHADOW)                              //~v658I~//~v7bEI~
   		{                                                               //~v658I~//~v7bEI~
//			if (Popt & UVIOMATTR_BASEDBCS) //base is dbcs                    //~v6W8I~//~v7bER~
//			{                                                                //~v6W8I~//~v7bER~
//              uviom_setcchar_shadow(Popt,Pucsbase,Pucs,Ppcchar,Ppcchar0);    //~v7bsI~//~v7bER~
//  			rc=1;	//added 1 cchar                                        //~v7bsI~//~v7bER~
//  			swShadowDbcs=1;                                                //~v7bsI~//~v7bER~
//			}                                                                //~v6W8I~//~v7bER~
//			else                                                             //~v6W8I~//~v7bER~
//			{                                                                //~v6W8I~//~v7bER~
//  			uviom_setcchar_shadow(Popt,Pucsbase,Pucs,Ppcchar,Ppcchar0);    //~v6W6I~//~v7bER~
//   		}//!dbcs                                                         //~v6W8I~//~v7bER~
  			uviom_setccharSCM_shadow(Popt,Pucs,Ppcchar,Ppcchar0);  //~v7bEI~
   		}                                                               //~v658I~//~v7bEI~
   		else                                                            //~v658I~//~v7bEI~
//        if (Scombaltch==UVIOM_ALTCHITSELF)                              //~v658R~//~v7bEI~//~v7bKR~
        if (Scombaltch==UVIOM_ALTCHITSELF                          //~v7bKI~
//      ||  Scombaltch==UVIOM_ALTCHPADDING)                        //~v7bKI~//~v7eqR~
        )                                                          //~v7eqI~
   		{                                                               //~v6EmI~//~v7bEI~
            UTRACEP("%s:ITSELF Scombaltch=%d,ucs=0x%04x\n",UTT,Scombaltch,Pucs);//~v7bKI~//~v7eqR~
    		Ppcchar->chars[0]=Pucs;     //combining char itself            //~v658I~//~v7bEI~
   			if (!(Plineopt & UVIOO_CSRPOSCHK))       // file data line      //~v6EnR~//~v7bEI~
    			Ppcchar->attr=uviom_attr_itself(Plineopt,*Ppcht)|(attr_t)attropt;//~v6EnR~//~v7bEI~
   			if (Plineopt & UVIOO_CSRPOSCHK)        // file data line       //~v6V6R~//~v7bEI~
            {                                                      //~v7bEI~
    			uviom_setccharSCM_itself(Popt,Pucs,Ppcchar);                  //~v6V6R~//~v7bER~
            }                                                      //~v7bEI~
   		}                                                               //~v6EmI~//~v7bEI~
   		else                                                            //~v658I~//~v7bEI~
        if (Scombaltch==UVIOM_ALTCHPADDING)                        //~v7eqI~
   		{                                                          //~v7eqI~
            UTRACEP("%s:PADDING Scombaltch=%d,ucs=0x%04x\n",UTT,Scombaltch,Pucs);//~v7eqI~
    		Ppcchar->chars[0]=Guviomdbcspad;                       //~v7eqI~
   		}                                                          //~v7eqI~
   		else                                                       //~v7eqI~
   		if (UTF_COMBINEMODE())   //when break on,entered to combine1 by lineopt,same as itself//~v6EnI~//~v7bER~
   		{                                                               //~v6EnI~//~v7bEI~
   			UTRACEP("%s:UTF_COMBINEMODE\n",UTT);                           //~v6W2I~//~v7bEI~
    		Ppcchar->chars[0]=Pucs;     //combining char itself            //~v6EnI~//~v7bEI~
   			if (!(Plineopt & UVIOO_CSRPOSCHK))       // file data line      //~v6EnR~//~v7bEI~
    			Ppcchar->attr=uviom_attr_itself(Plineopt,*Ppcht)|(attr_t)attropt;//~v6EnI~//~v7bEI~
   		}                                                               //~v6EnI~//~v7bEI~
   		else                                                            //~v6EnI~//~v7bEI~
   		{                                                               //~v6W3I~//~v7bEI~
    		Ppcchar->chars[0]=Scombaltch;     //combining char special parm//~v658I~//~v7bEI~
//    		if (!(Popt & UVIOMATTR_PADDING2))  //Not ovf combine char(for the case ligature not combine mode)//~v6W3I~//~v7bER~
//    		{                                                            //~v6W3I~//~v7bER~
    			if (Popt & UVIOMATTR_BREAK)   //not around csr column          //~v6W3I~//~v7bEI~
                {                                                  //~v7bEI~
    				uviom_setccharSCM_itself(Popt,Pucs,Ppcchar);                  //~v6W3I~//~v7bER~
                }                                                  //~v7bEI~
//    		}                                                            //~v6W3I~//~v7bER~
   		}                                                               //~v6W3I~//~v7bEI~
		Ppcchar->attr|=(attr_t)attropt;//break flag                //~v7bEI~
//    }                                                                //~v656I~//~v7bER~
//    else                                                             //~v656I~//~v7bER~
//    if (Popt & UVIOMATTR_EXT_BASEUNP)//  0x200000     //base is unprintable//~v6WeI~//~v7bER~
//    {                                                                //~v6WeI~//~v7bER~
//        if (Scombaltch==UVIOM_ALTCHPADDING)                        //~v6WeI~//~v7bER~
//            Ppcchar->chars[0]=Guviomdbcspad;                       //~v6WeI~//~v7bER~
//        else                                                       //~v6WeI~//~v7bER~
//        if (Scombaltch==UVIOM_ALTCHITSELF                          //~v6WeR~//~v7bER~
//        ||  Scombaltch==UVIOM_ALTCHSHADOW                          //~v6WeI~//~v7bER~
//        ||  UTF_COMBINEMODE()    //entered to combine1 by lineopt,same as itself//~v6WeI~//~v7bER~
//        )                                                          //~v6WeI~//~v7bER~
//        {                                                          //~v6WeI~//~v7bER~
//            Ppcchar->chars[0]=Pucs;     //combining char itself    //~v6WeI~//~v7bER~
//            if (Plineopt & UVIOO_CSRPOSCHK)        // file data line//~v6WeI~//~v7bER~
//                uviom_setcchar_itself(Popt,Pucs,Ppcchar);          //~v6WeI~//~v7bER~
//        }                                                          //~v6WeI~//~v7bER~
//        else                                                       //~v6WeI~//~v7bER~
//        {                                                          //~v6WeI~//~v7bER~
//            UTRACEP("%s:UNPR+combine:NP mode\n",UTT);              //~v6WeI~//~v7bER~
//            Ppcchar->chars[0]=Scombaltch;     //combining char special parm//~v6WeI~//~v7bER~
//            if (!(Popt & UVIOMATTR_PADDING2))  //Not ovf combine char(for the case ligature not combine mode)//~v6WeI~//~v7bER~
//            {                                                      //~v6WeI~//~v7bER~
//                if (Popt & UVIOMATTR_BREAK)   //not around csr column//~v6WeI~//~v7bER~
//                    uviom_setcchar_itself(Popt,Pucs,Ppcchar);      //~v6WeI~//~v7bER~
//            }                                                      //~v6WeI~//~v7bER~
//        }                                                          //~v6WeI~//~v7bER~
//    }                                                                //~v6WeI~//~v7bER~
//    else                                                             //~v6WeI~//~v7bER~
//    if (Pucsbase<0x80)    //not combinable ascii                     //~v656R~//~v7bER~
//    {                                                                //~v656I~//~v7bER~
//        Ppcchar->chars[0]=Guviomdbcspad;                               //~v656I~//~v7bER~
//    }                                                                //~v656I~//~v7bER~
//    else                                                             //~v656I~//~v7bER~
//        Ppcchar->chars[0]=Pucs;                                        //~v653M~//~v7bER~
//	if (!swShadowDbcs)                                               //~v7bsI~//~v7bER~
//		if (Popt & UVIOMATTR_PADDING2)  //for the case ligature not combine mode//~v6V5R~//~v7bER~
//  	{                                                              //~v6V5I~//~v7bER~
//      	pcchar_padding2=Ppcchar+1;                                 //~v6V5R~//~v7bER~
//      	pcchar_padding2->chars[0]=UVIOM_COMBINE_ALTCH2;            //~v6V5R~//~v7bER~
//      	pcchar_padding2->attr=(ATTR_COMBINE_FG_UCS4<<8);           //~v6V5R~//~v7bER~
//      	pcchar_padding2->attr|=ATTR_COMBINE_PADDING_NOHCOPY;//   A_DIM //padding to be dropped from hcopy//~vbzPI~//~v7bER~
//      	rc=1;                                                      //~v6V5I~//~v7bER~
//  	}                                                              //~v6V5I~//~v7bER~
UTRACEP("%s:single combine parm=%x,opt=%x,rc=%d,char ucs=%x,chtype=%x,rc=%d\n",UTT,Scombaltch,Popt,rc,Pucs,*Ppcht,rc);//~v6V5R~//~v7bsR~//~v7bER~
UTRACED("out Ppcchar",Ppcchar,CCHSZ*(rc+1));                      //~v653R~//~v6BZR~//~v6V5R~//~v7bEI~
    return rc;   //additional outctr 0/1                           //~v6V5R~//~v7bER~
}//uviom_setcombineSCM1                                            //~v7bER~
//*******************************************************          //~v7bEI~
int uviom_setcombineSCM_ligature(int Popt,int Plineopt,int Pucs,chtype *Ppcht,cchar_t *Ppcchar0,cchar_t *Ppcchar,int PchszSCM,int *Ppwritelen)//~v7bER~
{                                                                  //~v7bEI~
    cchar_t *pcc;                                                  //~v7bEI~
    int writelen=1,rc,opt,opt2=0;                                         //~v7bER~//~v7bJR~
    attr_t attr;                                                   //~v7bEI~
//**************************                                       //~v7bEI~
	UTRACEP("%s:opt=0x%x,lineopt=0x%x,ucs=%04x,chszSCM=%d,\n",UTT,Popt,Plineopt,Pucs,PchszSCM);//~v7bER~
    opt=Popt & ~(UVIOMATTR_BASEDBCS|UVIOMATTR_EXT_BASEUNP);//base is inprintable//~v7bEI~
	pcc=Ppcchar;	//output                                       //~v7bEI~
	attr=*Ppcht & ~(A_CHARTEXT);                                   //~v7bEI~
//    if (Ppcchar==Ppcchar0)                                       //~v7bEI~
//        swcombinable=0;                                          //~v7bEI~
//    else                                                         //~v7bEI~
//        swcombinable=utf_iscombinable(UICAO_NOSPACE,(ULONG)Pprevucs);//~v7bEI~
    pcc->chars[0]=Pucs;                                            //~v7bEI~
//    if (swcombinable && COMBINEMODE(Plineopt))   //combine mode  //~v7bEI~
	if (PchszSCM==2 && wcwidth(Pucs)==1)                           //~v7bEI~
    {                                                              //~v7bEI~
    	opt|=UVIOMATTR_EXT_WIDESBCS;// 0x800000, advance 1 col at mvadd//~v7bER~
	    attr|=UVIOMATTR_EXT_WIDESBCS;// 0x800000, advance 1 col at mvadd//~v7bER~
        opt2|=SBEO_2CELL;                                          //~v7bJI~
    }                                                              //~v7bEI~
    if (COMBINEMODE(Plineopt) && !(Popt & UVIOMATTR_BREAK)) //       0x04         //temporary break ligature flag//~v7bER~
    {                                                              //~v7bEI~
    	cchar_t *pcchbase;                                         //~v7bJR~
	    pcc->attr=attr;                                            //~v7bER~//~v7bJM~
		setBaseEntrySCM(opt2,Ppcchar0,pcc,&pcchbase);              //~v7bJR~
        if (!pcchbase)                                             //~v7bJR~
		    pcc->attr|=UVIOMATTR_BREAK;                            //~v7bJI~
    	rc=0;        //std                                         //~v7bEI~
    }                                                              //~v7bEI~
    else                                                           //~v7bEI~
    {                                                              //~v7bEI~
    	int rc2=0;                                                 //~v7bER~
		rc2=uviom_setcombineSCM1(opt,Plineopt,Pucs,Ppcht,Ppcchar,Ppcchar0);//~v7bER~
        if (rc2)                                                   //~v7bEI~
        	writelen++;                                            //~v7bEI~
//        attr=(attr_t)(uviol_repfg((int)*Ppcht,ATTR_COMBINENP_FG)<<8);//~v7bER~
//        pcc->attr=attr;                                          //~v7bER~
//        if (UTF_COMBINEMODE_NP() && uviom_getcombaltchUcs(0,&ucsalt))//~v7bER~
//        {                                                        //~v7bER~
//            rc=2;   //NP                                         //~v7bER~
//            pcc->chars[0]=ucsalt;                                //~v7bER~
//        }                                                        //~v7bER~
//        else                                                     //~v7bER~
//            rc=1;   //split                                      //~v7bER~
//    }                                                            //~v7bER~
//    if (rc) //combine if rc=0                                    //~v7bER~
//    {                                                            //~v7bER~
//        *(pcc+1)=*pcc;                                           //~v7bER~
//        pcc++;                                                   //~v7bER~
//        if (rc==2)  //NP                                         //~v7bER~
//            pcc->chars[0]=UVIOM_COMBINE_ALTCH2; // '.' ,not written if Plen==1//~v7bER~
//        else                                                     //~v7bER~
//        {                                                        //~v7bER~
//            apiwidth=wcwidth(Pucs); //curses expection           //~v7bER~
//            if (apiwidth==2)                                     //~v7bER~
//            {                                                    //~v7bER~
//                (pcc-1)->attr|=UVIOMATTR_DBCS1;    //1st of dbcs //~v7bER~
//                pcc->attr|=UVIOMATTR_DBCS2;   //1st of dbcs      //~v7bER~
//            }                                                    //~v7bER~
//            else                                                 //~v7bER~
//            {                                                    //~v7bER~
//                pcc->chars[0]=' ';  //widen to 2 cell            //~v7bER~
//            }                                                    //~v7bER~
//        }                                                        //~v7bER~
    }                                                              //~v7bER~
    if (Ppwritelen)                                                //~v7bEI~
    	*Ppwritelen=writelen;                                      //~v7bEI~
UTRACEP("%s:rc=%d,ucs=%06x,attr=%0x,writelen=%d,str_top=%d,modeNP=%d,altchNP=%0x\n",UTT,rc,Pucs,attr,writelen,Ppcchar==Ppcchar0,UTF_COMBINEMODE_NP(),Gutfcombaltch);//~v7bER~
UTRACED("out cchar",Ppcchar,writelen*(int)sizeof(cchar_t));        //~v7bEI~
    return rc;                                                     //~v7bEI~
}//uviom_setcombineSCM_ligature                                    //~v7bER~
#ifdef KKK                                                         //~v7bJI~
//*******************************************************          //~v7bEI~
int uviom_setcombineSCM_nonligature(int Popt,int Plineopt,int Pcol,int *Pposbreak,int Pucs,chtype *Ppcht,UCHAR *Ppdbcs,cchar_t *Ppcchar0,cchar_t *Ppcchar,int PchszSCM,int Plen,int *Ppwritelen,int *Ppstrsz)//~v7bER~
{                                                                  //~v7bEI~
    int rc=0,outctr=1,opt=0,strsz;      //~v6BhI~                  //~v7bER~
    int setbreak=0,ii;                                                //~v656I~//~v7bER~
    UCHAR *pcd;                                                    //~v7bER~
    chtype *pct;                                                   //~v7bEI~
    cchar_t *pcc,*pccpadd;                                         //~v7bEI~
    cchar_t wkcchar[MAX_SCMCTR];                                   //~v7bEI~
//**************************                                       //~v653I~//~v7bEI~
UTRACEP("%s:entry opt=0x%04x,lineopt=0x%04x,ucs=%04x,chszSCM=%d\n",UTT,Popt,Plineopt,Pucs,PchszSCM);//~v653R~//~v656R~//~v7bER~
	pcc=Ppcchar;	//output                                       //~v653R~//~v7bEI~
    pct=Ppcht;	//input                                            //~v653I~//~v7bER~
  	pcd=Ppdbcs;                                                    //~v653I~//~v7bER~
	attr_t attrColor=*Ppcht & A_COLOR;                             //~v7bER~
    pcc->chars[0]=Pucs;                                            //~v7bEI~
    pcc->attr=attrColor;                                           //~v7bER~
    strsz=PchszSCM;                                                //~v7bER~
	if (PchszSCM==2 && wcwidth(Pucs)==1)                           //~v7bEI~
    {                                                              //~v7bEI~
    	opt|=UVIOMATTR_EXT_WIDESBCS;// 0x800000, advance 1 col at mvadd//~v7bEI~
	    pcc->attr|=UVIOMATTR_EXT_WIDESBCS;// 0x800000, advance 1 col at mvadd//~v7bEI~
    }                                                              //~v7bEI~
	pcc->attr|=UVIOMATTR_EXT_SCM;	//for chk who is base          //~v7bEI~
//  if (pcc>Ppcchar0)                                              //~v7bEI~//~v7bJR~
   	if (pcc>ScchTop)                                               //~v7bJR~
        if (!((pcc-1)->attr & UVIOMATTR_EXT_SCM)) //0x01000000     //scm comining//~v7bEI~
	        (pcc-1)->attr|=UVIOMATTR_EXT_SCMBASE; // 0x040000  //ligature:off,combinemode,combin base//~v7bER~
    for (;;)                                                       //~v653I~//~v7bEI~
    {                                                              //~v653I~//~v7bEI~
//    	if (pcc==Ppcchar0                                          //~v656R~//~v7bEI~//~v7bJR~
   		if (pcc==ScchTop                                           //~v7bJR~
        ||  (Popt & UVIOMSCO_FORCEBREAK)                           //~v656I~//~v7bEI~
        ||  ((pcc-1)->attr & UVIOMATTR_BREAK)   //prev is single combine//~v656I~//~v7bEI~
    	)                                                          //~v656I~//~v7bEI~
        {                                                          //~v656I~//~v7bEI~
        	setbreak=1;                                            //~v656I~//~v7bEI~
        	break;                                                 //~v656I~//~v7bEI~
        }                                                          //~v656I~//~v7bEI~
    	if (!COMBINEMODE(Plineopt))	//split mode                   //~v6EmI~//~v7bEI~
        {                                                          //~v6EnI~//~v7bEI~
        	setbreak=1;	//keep colomn for Altch especially ITSELF mode//~v6EnI~//~v7bEI~
        	break;                                                 //~v656M~//~v7bEI~
        }                                                          //~v6EnI~//~v7bEI~
//        pcc--;                                                     //~v653I~//~v7bER~
//        pct--;                                                     //~v653I~//~v7bER~
//        pcd--;                                                     //~v653I~//~v7bER~
//        dbcssw=((pcc->attr & UVIOMATTR_DBCS2)!=0);         //temporary padding flag//~v653I~//~v656R~//~v7bER~
//        if (dbcssw)                                                //~v653I~//~v7bER~
//        {                                                          //~v653I~//~v7bER~
//            pcc--;                                                 //~v653I~//~v7bER~
//            pct--;                                                 //~v653I~//~v7bER~
//            pcd--;                                                 //~v653I~//~v7bER~
//        }                                                          //~v653I~//~v7bER~
//        dbcssz=1+dbcssw;                                           //~v653I~//~v7bER~
//        prevucs=pcc->chars[0];                                     //~v653I~//~v7bER~
//#ifdef LNX                                                         //~v6V5I~//~v7bER~
//        combinectr=uvio_getcombinectr(0,prevucs,dbcssz,pct,pcd,Plen);//~v6V5I~//~v7bER~
//#else                                                              //~v6V5I~//~v7bER~
//        combinectr=uvio_getcombinectr(0,prevucs,dbcssz,pcd,Plen);//~v653I~//~v656R~//~v7bER~
//#endif                                                             //~v6V5I~//~v7bER~
//        attro=(*pct & (A_ATTRIBUTES));                             //~v656R~//~v7bER~
//        for (pct=Ppcht,ii=0;ii<combinectr;ii++,pct++)              //~v656I~//~v7bER~
//        {                                                          //~v656I~//~v7bER~
//            attrn=(*pct & (A_ATTRIBUTES));                         //~v656R~//~v7bER~
//            UTRACEP("%s:combctr=%d,attro=%x,attrn=%x\n",UTT,ii,attro,attrn);//~v656I~//~v7bvR~//~v7bER~
//            if (attrn!=attro)                                      //~v656R~//~v7bER~
//            {                                                      //~v656I~//~v7bER~
//                combinectr=ii;                                     //~v656R~//~v7bER~
//                break;                                             //~v656I~//~v7bER~
//            }                                                      //~v656I~//~v7bER~
//        }                                                          //~v656I~//~v7bER~
//        if (!combinectr)                                           //~v653I~//~v7bER~
//            break;                                                 //~v653I~//~v7bER~
//set combine to base char                                         //~v658I~//~v7bEI~
//        if (dbcssw) //base is dbcs                                 //~v6W9I~//~v7bER~
//        {                                                            //~v6W9I~//~v7bER~
//            pcc->attr=(attr_t)(pcc->attr | UVIOMATTR_EXT_COMBBASE);   //ligature:off,combinemode,combin base//~v6W9I~//~v7bER~
//            for (pct=Ppcht,pccpadd=Ppcchar,pcd=Ppdbcs,ii=1;ii<=combinectr;ii++,pcd++,pct++)//~v6W9I~//~v7bER~
//            {                                                          //~v6W9I~//~v7bER~
//                swcombine=uviom_ISUCSWIDTH0(IUW0O_COMB2SCM_COMB,pct,pcd,2/*confirmd enough length by getcombinectr()*/,&ucs);//~v6X5R~//~v7bER~
//                pcc->chars[ii]=ucs;                                    //~v6W9I~//~v7bER~
//                (pcc+1)->chars[ii]=ucs;                                //~v6W9I~//~v7bER~
//                if (UVIOM_NONSPACECOMBINEMODE()) //non spacing combining diacritical mark supported//~v6W9I~//~v7bER~
//                {                                                        //~v6W9I~//~v7bER~
//                    attr=uviom_set_padattr(0,ATTR_COMBINE_FG_UCS4<<8);     //~v7btI~//~v7bER~
//                    attr|=UVIOMATTR_PADDING;         //temporary padding flag//~v6W9I~//~v7bER~
//                    if (swcombine==2)                                      //~v6W9I~//~v7bER~
//                        attr|=UVIOMATTR_PADDING2;    //2 padding char      //~v6W9I~//~v7bER~
//                    pccpadd->attr=attr; //padding attr                     //~v6W9I~//~v7bER~
//                    pccpadd->chars[0]=Guviomdbcspad; //PADDING             //~v6W9I~//~v7bER~
//                    pccpadd++;                                             //~v6W9I~//~v7bER~
//                    outctr++;                                              //~v6W9I~//~v7bER~
//                    if (swcombine==2)                                      //~v6W9I~//~v7bER~
//                    {                                                      //~v6W9I~//~v7bER~
//                        *pccpadd=*(pccpadd-1);                             //~v6W9I~//~v7bER~
//                        pccpadd->chars[0]=UVIOM_COMBINE_ALTCH2;            //~v6W9I~//~v7bER~
//                        pccpadd->attr=uviom_set_padattr(0,ATTR_COMBINE_FG_UCS4<<8);//~v6W9I~//~v7bER~
//                        pccpadd++;                                         //~v6W9I~//~v7bER~
//                        outctr++;                                          //~v6W9I~//~v7bER~
//                    }                                                      //~v6W9I~//~v7bER~
//                }//fc5 need 1 column for nonspace char                   //~v6W9I~//~v7bER~
//                mblen++;                                                 //~v6W9I~//~v7bER~
//                if (swcombine==2)                                        //~v6W9I~//~v7bER~
//                    pcd++,pct++,mblen++;    //ucs4 width0                  //~v6W9I~//~v7bER~
//            }                                                          //~v6W9I~//~v7bER~
//        }//base dbcs                                                 //~v6W9I~//~v7bER~
//        else                                                         //~v6W9I~//~v7bER~
//        {                                                            //~v6W9I~//~v7bER~
//      	cchar_t *pccbase=pcc;                                      //~v7bvR~//~v7bER~
//			pccbase->attr|=UVIOMATTR_EXT_COMBBASE;// 0x040000;    //ligature:off,combinemode,combin base//~v7bvI~//~v7bER~
//            for (pct=Ppcht,pccpadd=Ppcchar,pcd=Ppdbcs,ii=1;ii<=combinectr;ii++,pcd++,pct++)//~v6W5I~//~v7bER~
//            {                                                          //~v6W5I~//~v7bER~
//            //*******************                                  //~v6W5I~//~v7bER~
//                swcombine=uviom_ISUCSWIDTH0(IUW0O_COMB2SCM_COMB,pct,pcd,2/*confirmd enough length by getcombinectr()*/,&ucs);//~v6X5I~//~v7bER~
//                pccbase->chars[ii]=ucs;  //combining char to base      //~v7bvI~//~v7bER~
//                pccbase->attr&=(attr_t)(~UVIOMATTR_EXT_COMBBASE);   //combined, not base ucs only//~v7bvI~//~v7bER~
//                pccpadd->attr=uviom_set_padattr(0,ATTR_COMBINE_FG_UCS4<<8);//~v7bvI~//~v7bER~
//                pccpadd->attr|=ATTR_COMBINE_PADDING_NOHCOPY;//   A_DIM //padding to be dropped from hcopy//~v7bvR~//~v7bER~
//                pccpadd->chars[0]=Guviomdbcspad; //PADDING             //~v7bvI~//~v7bER~
//                UTRACEP("%s:sbcs padding base=0x%04x,combinining=0x%04x\n",UTT,pccbase->chars[0],ucs);//~v7bvR~//~v7bER~
//                pccpadd++;                                             //~v7bvI~//~v7bER~
//                outctr++;                                              //~v7bvI~//~v7bER~
//                pcd++,pct++,mblen++;                                   //~v7bvI~//~v7bER~
//            }                                                          //~v6W5I~//~v7bER~
//        }//base ! dbcs                                               //~v6W9I~//~v7bER~
		pct+=PchszSCM;                                             //~v7bEI~
		pcd+=PchszSCM;                                             //~v7bEI~
        int combinectr=getStringSCM(Popt,Pcol+PchszSCM,Pposbreak,pct,pcd,Plen-PchszSCM,wkcchar,0);//~v7bER~
        attr_t attro=attrColor;                                    //~v7bER~
        pccpadd=pcc+1;                                             //~v7bEI~
        for (ii=0;ii<combinectr;ii++,pct++,pccpadd++)              //~v7bEI~
        {                                                          //~v7bEI~
            attr_t attrn=(*pct & (A_ATTRIBUTES));                  //~v7bER~
            UTRACEP("%s:ii=%d,attro=%x,attrn=%x\n",UTT,ii,attro,attrn);//~v7bEI~
            if (attrn!=attro)                                      //~v7bEI~
            {                                                      //~v7bEI~
                combinectr=ii;                                     //~v7bEI~
                break;                                             //~v7bEI~
            }                                                      //~v7bEI~
    		pccpadd->chars[0]=wkcchar[ii].chars[0];                //~v7bER~
    		pccpadd->attr=wkcchar->attr;                           //~v7bER~
            strsz++;                                               //~v7bEI~
    		if (pccpadd->attr  & UVIOMATTR_EXT_WIDESBCS)// 0x800000, advance 1 col at mvadd//~v7bEI~
                strsz++;                                           //~v7bEI~
            UTRACEP("%s:added ii=%d,strsz=%d,ucs=0x%04x,attr=0x%04x\n",UTT,ii,strsz,pccpadd->chars[0],pccpadd->attr);//~v7bER~
        }                                                          //~v7bER~
#ifdef AAA                                                         //~v7bJI~
        attr_t attrPadding=uviom_set_padattr(0,ATTR_COMBINE_FG_UCS4<<8);//~v7bER~
        pccpadd->attr=attrPadding;                                 //~v7bEI~
        pccpadd->attr|=(UVIOMATTR_EXT_NOHCOPY);                    //~v7bEI~
        if (PchszSCM>1)                                            //~v7bEI~
            pccpadd->attr|=UVIOMATTR_EXT_WIDESBCS;// 0x800000, advance 1 col at mvadd//~v7bEI~
        pccpadd->chars[0]=Guviomdbcspad; //PADDING for 1st SCM     //~v7bER~
        pccpadd++;                                                 //~v7bEI~
        for (ii=0;ii<combinectr;ii++,pccpadd++)                    //~v7bER~
        {                                                          //~v7bEI~
            pccpadd->attr|=attrPadding|(UVIOMATTR_EXT_NOHCOPY);    //~v7bER~
            if (wkcchar->attr & UVIOMATTR_EXT_WIDESBCS);// 0x800000, advance 1 col at mvadd//~v7bER~
	    		pccpadd->attr|=UVIOMATTR_EXT_WIDESBCS;// 0x800000, advance 1 col at mvadd//~v7bEI~
            pccpadd->chars[0]=Guviomdbcspad; //PADDING for following SCM//~v7bER~
        }                                                          //~v7bEI~
#endif                                                             //~v7bJI~
        outctr=PTRDIFF(pccpadd,Ppcchar)/CCHSZ;                     //~v7bEI~
		UTRACEP("%s:padding(%02x) added outctr=%d\n",UTT,Guviomdbcspad,outctr);//~v653R~//~v6BhR~//~v7bER~//~v7bGR~//~v7bER~
		UTRACED("normal",Ppcchar,CCHSZ*outctr);              //~v7bGI~//~v7bER~
        rc=1;                                                      //~v653I~//~v7bEI~
        break;                                                     //~v653I~//~v7bEI~
    }                                                              //~v653I~//~v7bEI~
    if (!rc)	//no following                                                       //~v653I~//~v7bER~
    {                                                              //~v653I~//~v7bEI~
        if (setbreak)                                              //~v656R~//~v7bEI~
	        opt|=UVIOMATTR_BREAK;                                  //~v653I~//~v7bEI~
      	if (!(Popt & UVIOMSCO_NOSETATTR))                        //~v658I~//~v7bEI~
	        opt|=UVIOMATTR_SETATTR;	//set fg:green                 //~v656M~//~v7bEI~
//        for (pccprev=Ppcchar-1;pccprev>=Ppcchar0;pccprev--)        //~v656I~//~v7bER~
//        {                                                          //~v656I~//~v7bER~
//            prevucs=pccprev->chars[0];                             //~v656I~//~v7bER~
//            if (!(pccprev->attr & UVIOMATTR_PADDING))   //padding space//~v6WaR~//~v7bER~
//                if (UTF_COMBINABLE(prevucs))                           //~v656R~//~v7bER~
//                {                                                      //~v658I~//~v7bER~
//                    if (pccprev->attr & UVIOMATTR_DBCS12)  //dbcs      //~v658R~//~v7bER~
//                        opt|=UVIOMATTR_BASEDBCS;                       //~v658I~//~v7bER~
//                    break;                                             //~v656I~//~v7bER~
//                }                                                      //~v658I~//~v7bER~
//                prevucs=0;                                             //~v656I~//~v7bER~
//        }                                                          //~v656I~//~v7bER~
//        swcombine=uviom_ISUCSWIDTH0(IUW0O_COMB2SCM_COMB,Ppcht,Ppdbcs,Plen/*confirmd enough length by getcombinectr()*/,&ucs);//~v7bBI~//~v7bER~
//        if (swcombine==2)                                          //~v6V5I~//~v7bER~
//            opt|=UVIOMATTR_PADDING2;//ucs4 width0                  //~v6V5I~//~v7bER~
//        if (Popt & UVIOMSCO_BASEUNP) //base unprintable(":;")      //~v6WeM~//~v7bER~
//            opt|=UVIOMATTR_EXT_BASEUNP;//base is inprintable       //~v6WeM~//~v7bER~
//      outctr=1+                                                  //~v6V5I~//~v7bER~
        uviom_setcombineSCM1(opt,Plineopt,Pucs,Ppcht,Ppcchar,Ppcchar0);//~v6W6I~//~v7bER~
//      combinectr=1;   //loop ctr;                                //~v653R~//~v7bER~
//      mblen=1+(swcombine==2);	//2 for ucs4 width0                //~v6V5I~//~v7bER~
//      if (outctr>1) //non spacing combining diacritical mark supported//~v6V5R~//~v7bER~
//          pccpadd++;                                             //~v6V5I~//~v7bER~
    }                                                              //~v653I~//~v7bEI~
//  *Ppcombinectr=combinectr;                                      //~v653R~//~v7bER~
    *Ppwritelen=outctr;                                            //~v653R~//~v7bER~
    if (Ppstrsz)                                                   //~v7bEI~
    	*Ppstrsz=strsz;                                            //~v7bER~
//  *Ppmblen=mblen;                                                //~v6V5I~//~v7bER~
UTRACEP("%s:rc=%d,ucs=%04x,outctr=%d,strsz=%d\n",UTT,rc,Pucs,outctr,strsz);//~v653R~//~v6V5R~//~v7bER~
    return rc;                                                     //~v653I~//~v7bEI~
}//uviom_setcombineSCM_nonligature                                 //~v7bEI~
#endif     //KKK                                                        //~v7bJI~//~v7bKR~
//*******************************************************          //~v7bJI~
int uviom_setcombineSCM_nonligature(int Popt,int Plineopt,int Pucs,chtype *Ppcht,UCHAR *Ppdbcs,cchar_t *Ppcchar0,cchar_t *Ppcchar,int PchszSCM,int *Ppwritelen,int *Ppstrsz)//~v7bJI~
{                                                                  //~v7bJI~
    int outctr=1,opt2=0;                                           //~v7bJR~
    int swbreak=0,strsz;                                           //~v7bJR~
    cchar_t *pcc,*pccbase;                                         //~v7bJR~
//**************************                                       //~v7bJI~
UTRACEP("%s:entry opt=0x%04x,lineopt=0x%04x,ucs=%04x,chszSCM=%d\n",UTT,Popt,Plineopt,Pucs,PchszSCM);//~v7bJI~
	pcc=Ppcchar;	//output                                       //~v7bJI~
	attr_t attrColor=*Ppcht & A_COLOR;                             //~v7bJI~
//  if (Scombaltch==UVIOM_ALTCHPADDING)                            //~v7bJR~
//    pcc->chars[0]=Guviomdbcspad;                                 //~v7bJR~
//  else                                                           //~v7bJR~
    pcc->chars[0]=Pucs;                                            //~v7bJI~
    pcc->attr=attrColor;                                           //~v7bJI~
    strsz=PchszSCM;                                                //~v7bJI~
	if (PchszSCM==2 && wcwidth(Pucs)==1)                           //~v7bJI~
    {                                                              //~v7bJI~
	    pcc->attr|=UVIOMATTR_EXT_WIDESBCS;// 0x800000, advance 1 col at mvadd//~v7bJI~
        opt2|=SBEO_2CELL;                                          //~v7bJI~
    }                                                              //~v7bJI~
    if (Popt & UVIOMSCO_FORCEBREAK)                                //~v7bJI~
    	swbreak=1;	//keep colomn for Altch especially ITSELF mode //~v7bJI~
    else                                                           //~v7bJI~
    if (!COMBINEMODE(Plineopt))	//split mode                       //~v7bJI~
    	swbreak=1;	//keep colomn for Altch especially ITSELF mode //~v7bJR~
    if (!swbreak)                                                  //~v7bJR~
    {                                                              //~v7bJI~
	    setBaseEntrySCM(opt2,Ppcchar0,pcc,&pccbase);               //~v7bJR~
    	if (!pccbase)                                              //~v7bJI~
    		swbreak=1;                                             //~v7bJI~
    }                                                              //~v7bJI~
    else                                                           //~v7bJR~
    {                                                              //~v7epI~
//	    pcc->attr=uviom_attr_itself(Plineopt,*Ppcht);              //~v7bJR~
      if (Popt & UVIOMSCO_NOSETATTR)                               //~v7epI~
      {                                                            //~v7epI~
		UTRACEP("%s:entry Popt=0x%04x bypass call uviom_set_paddatr by vhexdatapos\n",UTT);//~v7epR~
      }                                                            //~v7epI~
      else                                                         //~v7epI~
	    pcc->attr=uviom_set_padattr(0,attrColor)|((opt2 & SBEO_2CELL)!=0?UVIOMATTR_EXT_WIDESBCS:0);//~v7bJR~
        if (Scombaltch==UVIOM_ALTCHPADDING)                        //~v7eqI~
   		{                                                          //~v7eqI~
            UTRACEP("%s:PADDING Scombaltch=%d,ucs=0x%04x\n",UTT,Scombaltch,Pucs);//~v7eqI~
    		Ppcchar->chars[0]=Guviomdbcspad;                       //~v7eqI~
   		}                                                          //~v7eqI~
    }                                                              //~v7epI~
    if (swbreak)                                                   //~v7bJM~
		pcc->attr|=UVIOMATTR_BREAK;                                //~v7bJM~
    *Ppwritelen=outctr;                                            //~v7bJI~
    if (Ppstrsz)                                                   //~v7bJI~
    	*Ppstrsz=strsz;                                            //~v7bJI~
UTRACEP("%s:ucs=%04x,outctr=%d,strsz=%d,swbreak=%d\n",UTT,Pucs,outctr,strsz,swbreak); //~v7bJR~//~v7eqR~
    return 0;                                                      //~v7bJR~
}//uviom_setcombineSCM_nonligature                                 //~v7bJI~
//*******************************************************          //~v7bEI~
int getCombineCtrSCM(int Popt,cchar_t *Ppcchar,int Ppos,int Plen,int *Ppwidth)//~v7bER~
{                                                                  //~v7bEI~
	int pos;                                                       //~v7bEI~
	cchar_t *pchtw;                                                //~v7bER~
    pchtw=Ppcchar;                                                 //~v7bEI~
    int combinectr=0,width=0;                                      //~v7bEI~
    for (pos=Ppos;pos<Plen;pchtw++)                                //~v7bEI~
	{                                                              //~v7bER~
   		UTRACEP("%s:ucs=0x%04x,attr=0x%04x\n",UTT,pchtw->chars[0],pchtw->attr);//~v7bEI~
		if (!(pchtw->attr & UVIOMATTR_EXT_SCM))                    //~v7bEI~
           break;                                                  //~v7bEI~
		if (pchtw->attr & ( UVIOMATTR_BREAK                        //~v7bER~
//                      |UVIOMATTR_PADDING                         //~v7bEI~//~v7bJR~
						|UVIOMATTR_EXT_SCMBASE                     //~v7bEI~
                           )                                       //~v7bEI~
           )                                                       //~v7bEI~
           break;                                                  //~v7bER~
       combinectr++;                                               //~v7bEI~
       width+=1+((pchtw->attr & UVIOMATTR_EXT_WIDESBCS)!=0);       //~v7bER~
	}                                                              //~v7bER~
   	*Ppwidth=width;                                                //~v7bER~
   	UTRACEP("%s:combinectr=%d,width=%d,next ucs=0x%04x\n",UTT,combinectr,width,Ppcchar->chars[0]);//~v7bER~
   	return combinectr;                                             //~v7bER~
}                                                                  //~v7bEI~
#ifdef AAA                                                         //~v7bEI~
//*******************************************************          //~v7bEI~
int getCombineCtrSCMFollowing(int Popt,chtype *Ppcht,char *Ppdbcs,int Plen,cchar_t *Ppcchar)//~v7bEI~
{                                                                  //~v7bEI~
	int pos;                                                       //~v7bEI~
	cchar_t *pchtw;                                                //~v7bEI~
    pchtw=Ppcchar;                                                 //~v7bEI~
    int combinectr=0,width=0;                                      //~v7bEI~
    for (pos=Ppos;pos<Plen;pchtw++)                                //~v7bEI~
	{                                                              //~v7bEI~
   		UTRACEP("%s:ucs=0x%04x,attr=0x%04x\n",UTT,pchtw->chars[0],pchtw->attr);//~v7bEI~
		if (!(pchtw->attr & UVIOMATTR_EXT_SCM))                    //~v7bEI~
           break;                                                  //~v7bEI~
		if (pchtw->attr & ( UVIOMATTR_BREAK                        //~v7bEI~
                        |UVIOMATTR_PADDING                         //~v7bEI~
						|UVIOMATTR_EXT_SCMBASE                     //~v7bEI~
                           )                                       //~v7bEI~
           )                                                       //~v7bEI~
           break;                                                  //~v7bEI~
       combinectr++;                                               //~v7bEI~
       width+=1+((pchtw->attr & UVIOMATTR_EXT_WIDESBCS)!=0);       //~v7bEI~
	}                                                              //~v7bEI~
   	*Ppwidth=width;                                                //~v7bEI~
   	UTRACEP("%s:combinectr=%d,width=%d,next ucs=0x%04x\n",UTT,combinectr,width,Ppcchar->chars[0]);//~v7bEI~
   	return combinectr;                                             //~v7bEI~
}                                                                  //~v7bEI~
#endif                                                             //~v7bEI~
//*******************************************************          //~v7bEI~
int getStringSCM(int Popt,int Pcol,int *Pposbreak,chtype *Ppcht,UCHAR *Ppdbcs,int Plen,cchar_t *Ppcchar,int *Ppstrsz)//~v7bER~
{                                                                  //~v7bEI~
	int ucs,reslen,chsz,combinectr=0,strsz=0,col;                  //~v7bER~
	UCHAR *pdbcs;                                                  //~v7bEI~
    chtype *pcht;                                                  //~v7bEI~
    cchar_t *pcchar;                                               //~v7bER~
//**************	                                               //~v7bEI~
   	UTRACEP("%s:opt=0x%02x,col=%d,len=%d\n",UTT,Popt,Pcol,Plen);   //~v7bEI~
    col=Pcol;                                                      //~v7bEI~
	for (pcht=Ppcht,pdbcs=Ppdbcs,pcchar=Ppcchar,reslen=Plen;reslen>0;pcht+=chsz,pdbcs+=chsz,reslen-=chsz,pcchar++)//~v7bEI~
    {                                                              //~v7bEI~
//  	int swcombine=uviom_iscombining(0,pcht,pdbcs,reslen,&ucs,&chsz);//~v7bEI~//~v7f1R~
		int optic=ICO_NOFMT;                                       //~v7f1I~
    	int swcombine=uviom_iscombining(optic,pcht,pdbcs,reslen,&ucs,&chsz);//~v7f1I~
	   	UTRACEP("%s:swcombine=%d\n",UTT,swcombine);                //~v7bEI~
#ifdef KKK                                                         //~v7bEI~
        if (!(swcombine & UICRC_SCM))                              //~v7bEI~
#else                                                              //~v7bEI~
        if (!swcombine)     //accept combining char not SCM        //~v7bEI~
#endif                                                             //~v7bEI~
        	break;                                                 //~v7bEI~
        if (Popt & UVIOMSCO_CSRLINE)                               //~v7bEI~
        {                                                          //~v7bEI~
			UTRACEP("%s:ucs=0x%04x,col=%d,posbreak=%d,%d,%d,%d,%d,%d\n",UTT,ucs,col,Pposbreak[0],Pposbreak[1],Pposbreak[2],Pposbreak[3],Pposbreak[4],Pposbreak[5]);//~v7bER~
		    if (col==Pposbreak[0]/*before*/||col==Pposbreak[1]/*cpos*/||col==Pposbreak[2]/*after*///~v7bER~
		    ||  col==Pposbreak[3]/*vhexbefore*/||col==Pposbreak[4]/*vhex cpos*/)//~v7bEI~
            {                                                      //~v7bEI~
			   	UTRACEP("%s:CSRLINE combinectr=%d,col=%d\n",UTT,combinectr,col);//~v7bER~
            	break;                                             //~v7bEI~
            }                                                      //~v7bEI~
        }                                                          //~v7bEI~
        strsz+=chsz;                                               //~v7bEI~
        col+=chsz;                                                 //~v7bEI~
        combinectr++;                                              //~v7bER~
        pcchar->chars[0]=ucs;                                      //~v7bEI~
        pcchar->attr=*pcht & A_COLOR;                              //~v7bEI~
	    pcchar->attr|=UVIOMATTR_EXT_SCM;// 0x800000                //~v7bEI~
        if (chsz==2)                                               //~v7bEI~
        {                                                          //~v7bEI~
			if (wcwidth(ucs)==1)                                   //~v7bEI~
	        	pcchar->attr|=UVIOMATTR_EXT_WIDESBCS;// 0x800000   //~v7bEI~
        }                                                          //~v7bEI~
	   	UTRACEP("%s:combinectr=%d,ucs=0x%04x,chsz=%d\n",UTT,combinectr,ucs,chsz);//~v7bEI~
    }                                                              //~v7bEI~
    if (Ppstrsz)                                                   //~v7bEI~
	    *Ppstrsz=strsz;                                            //~v7bEI~
   	UTRACEP("%s:combinectr=%d,strsz=%d\n",UTT,combinectr,strsz);   //~v7bER~
    return combinectr;                                             //~v7bEM~
}//getStringSCM                                                    //~v7bEI~
//*******************************************************          //~v7bJI~
//*search base entry combining or scm                              //~v7bYI~
//*not found when scm with break flag deteted                      //~v7bYI~
//*not found when padcomb with break flag deteted                  //~v7bYI~
//*not found when ! combinable entry detected                      //~v7bYI~
//*not found when combining char overflow                          //~v7bYI~
//*******************************************************          //~v7bYI~
cchar_t *setBaseEntry(int Popt,cchar_t *Ptop,cchar_t *Pcur,int Pcolor,int Pucs,int *Ppcombctr)//~v7bJR~
{                                                                  //~v7bJI~
	cchar_t *pcc,*pccbase=0,*top;                                  //~v7bJR~
    int combinectr=0;                                              //~v7bJI~
    UTRACEP("%s:opt=%04x,cur ucs=0x%04x,color=0x%02x\n",UTT,Popt,Pucs,Pcolor);   //~v7bJR~//~v7eiR~
    top=ScchTop;                                                   //~v7bJR~
    if (!top)                                                      //~v7bJI~
    	top=Ptop;                                                  //~v7bJI~
    for (pcc=Pcur-1;pcc>=top;pcc--)                                //~v7bJR~
    {                                                              //~v7bJI~
        attr_t attr=pcc->attr;                                     //~v7bJI~
    	UTRACEP("%s:prev ucs=0x%04x,attr=%04x\n",UTT,pcc->chars[0],attr);//~v7bJI~
        if (attr & UVIOMATTR_EXT_ALTCH)         //ZWJ etc          //~v7c4I~
#ifdef NNN                                                         //~v7c4I~
            if (Pucs)                                              //~v7c4I~
#endif                                                             //~v7c4I~
            {                                                      //~v7c4I~
                UTRACEP("%s:base is ALTCH return null \n",UTT);    //~v7c4R~
                break;                                             //~v7c4I~
            }                                                      //~v7c4I~
        if ((attr & UVIOMATTR_DBCS2)!=0)         //temporary padding flag//~v7bJR~
            continue;                                              //~v7bJI~
        if (attr & (UVIOMATTR_EXT_COMBBASE|UVIOMATTR_EXT_SCMBASE)) //~v7bJR~
        {                                                          //~v7bJI~
    		UTRACEP("%s:reached base/scmbase ucs=0x%04x\n",UTT,pcc->chars[0]);//~v7bJR~
        	pccbase=pcc;                                           //~v7bJI~
        	break;                                                 //~v7bJI~
        }                                                          //~v7bJI~
        if (attr & UVIOMATTR_EXT_SCM)                              //~v7bJI~
        {                                                          //~v7bJI~
	        if (attr & UVIOMATTR_BREAK)                            //~v7bJI~
            {                                                      //~v7bJI~
    			UTRACEP("%s:ATTR_BREAK ucs=0x%04x\n",UTT,pcc->chars[0]);//~v7bJI~
    	        break;                                             //~v7bJI~
            }                                                      //~v7bJI~
            continue;                                              //~v7bJI~
        }                                                          //~v7bJI~
        if (attr & UVIOMATTR_EXT_PADDCOMB)                         //~v7bMI~
        {                                                          //~v7bMI~
#ifdef TEST                                                        //~v7ezI~
	        if (attr & UVIOMATTR_BREAK)                            //~v7bMI~
            {                                                      //~v7bMI~
    			UTRACEP("%s:ATTR_BREAK ucs=0x%04x\n",UTT,pcc->chars[0]);//~v7bMI~
    	        break;                                             //~v7bMI~
            }                                                      //~v7bMI~
#endif                                                             //~v7ezI~
    		UTRACEP("%s:ignore by PADDCOMB ucs=0x%04x\n",UTT,pcc->chars[0]);//~v7ehI~
            continue;                                              //~v7bMI~
        }                                                          //~v7bMI~
        if (!UTF_COMBINABLE(pcc->chars[0]))                        //~v7bJR~
        {                                                          //~v7bJI~
    		UTRACEP("%s:Not combinable BREAK ucs=0x%04x\n",UTT,pcc->chars[0]);//~v7bJR~
	    	break;                                                 //~v7bJI~
        }                                                          //~v7bJI~
#ifdef AAA  //xefile23 set lineattr for combining                  //~v7bJI~
		if ((int)(attr & UVIOMATTR_COLORMASK)!=Pcolor)             //~v7bJR~
        {                                                          //~v7bJI~
    		UTRACEP("%s:Color BREAK ucs=0x%04x\n",UTT,pcc->chars[0]);//~v7bJR~
	        break;                                                 //~v7bJI~
        }                                                          //~v7bJI~
#endif                                                             //~v7bJI~
        pccbase=pcc;                                               //~v7bJI~
        break;                                                     //~v7bJR~
    }                                                              //~v7bJI~
    if (pccbase)                                                   //~v7bJI~
    {                                                              //~v7bJI~
	    if (Pucs)	//set request                                  //~v7bJR~
        {                                                          //~v7bJI~
            for (combinectr=0;combinectr<UVIOM_MAXCOMBINE;combinectr++)//~v7bJI~
            {                                                      //~v7bJI~
//              if (pccbase->chars[combinectr])                    //~v7bJI~//~v7ffR~
                if (pccbase->chars[1+combinectr])                  //~v7ffI~
                    continue;                                      //~v7bJI~
//              pccbase->chars[combinectr]=Pucs;                   //~v7bJI~//~v7ffR~
                pccbase->chars[1+combinectr]=Pucs;                 //~v7ffI~
                break;                                             //~v7bJI~
            }                                                      //~v7bJI~
            if (combinectr>=UVIOM_MAXCOMBINE)                      //~v7bJI~
            	pccbase=0;                                         //~v7bJR~
            if (pccbase)                                           //~v7bJI~
            {                                                      //~v7bJI~
	        	pccbase->attr|=UVIOMATTR_EXT_COMBBASE;   //combined, not base ucs only//~v7bJI~
				if (Popt & SBEO_2CELL)	                           //~v7bJM~
    				UVIOMATTR_ADD_DBCSCOMBCTR(pccbase);	//calc culomn//~v7bJM~
			    UTRACEP("%s:Pucs=0x%04x,baseucs=0x%04x,baseattr=0x%04x,combinectr=%d\n",UTT,Pucs,pccbase->chars[0],pccbase->attr,combinectr);//~v7bJI~
		   		UTRACED("base",pccbase,CCHSZ);                     //~v7bJI~
            }                                                      //~v7bJI~
        }                                                          //~v7bJI~
    }                                                              //~v7bJI~
    if (Ppcombctr)                                                 //~v7bJR~
    	*Ppcombctr=combinectr;                                     //~v7bJR~
    UTRACEP("%s:return pccbase=%p,combinectr=%d\n",UTT,pccbase,combinectr);//~v7bJR~
    return pccbase;                                                //~v7bJR~
}//setBaseEntry                                                    //~v7bJR~
//*******************************************************          //~v7bJI~
int getCombinedStringWidth(int Popt,cchar_t *Ppbase,int *Ppctr)    //~v7bJR~
{                                                                  //~v7bJI~
	int combinectr;                                                //~v7bJR~
	int sz=UVIOMATTR_GET_DBCSCOMBCTR(Ppbase->attr); //2cell ctr    //~v7bJR~
    sz+=1+((Ppbase->attr & UVIOMATTR_EXT_WIDESBCS)!=0);            //~v7bJR~
    UTRACEP("%s:sz=%d from base ucs=0x%04x,attr=0x%04x\n",UTT,sz,Ppbase->chars[0],Ppbase->attr);//~v7bJR~
    for (combinectr=0;combinectr<UVIOM_MAXCOMBINE;combinectr++)    //~v7bJR~
    {                                                              //~v7bJI~
	    UTRACEP("%s:combiningctr=%d,ucs=0x%04x\n",UTT,combinectr,Ppbase->chars[combinectr+1]);//~v7bJR~
    	if (!Ppbase->chars[combinectr+1])                          //~v7bJR~
        	break;                                                 //~v7bJI~
        sz++;   //for each combining char                          //~v7bJR~
    }                                                              //~v7bJI~
    if (combinectr)                                                //~v7bYI~
        if (Ppbase->attr & UVIOMATTR_EXT_DMYBASE)                  //~v7bYR~
        {                                                          //~v7bYI~
            sz--;                                                  //~v7bYI~
	    	UTRACEP("%s:DMYBASE combiningctr=%d,sz=%d\n",UTT,combinectr,sz);//~v7bYI~
        }                                                          //~v7bYI~
    if (Ppctr)                                                     //~v7bJI~
	    *Ppctr=combinectr;                                         //~v7bJR~
    UTRACEP("%s:return base ucs=0x%04x,attr=0x%04x,combinectr=%d,sz=%d\n",UTT,Ppbase->chars[0],Ppbase->attr,combinectr,sz);//~v7bJR~
    return sz;                                                     //~v7bJI~
}//getCombinedStringWidth                                          //~v7bJR~
//*******************************************************          //~v7bJI~
//int getCombinedSize(int Popt,cchar_t *Ppcch,cchar_t *Ppcche,int *Ppctr,int *Ppsz)//~v7bJR~//~v7bPR~
int getCombinedSize(int Popt,cchar_t *Ppcch,cchar_t *Ppcche,int *Ppctr,int *Ppsz,int *PpszComb,int *PpswWideSbcsCombBase)//~v7bPI~
{                                                                  //~v7bJI~
	int sz=0,ctr,ii;                                               //~v7bJR~
	cchar_t *pcch;                                                 //~v7bJR~
    int ctrComb;                                                   //~v7bPI~
    int swWideSbcsCombBase=0; //for COMBBASE only                  //~v7bPI~
//********************                                             //~v7bJI~
	attr_t attr=Ppcch->attr;                                       //~v7bJR~
    *Ppctr=0;                                                      //~v7bJI~
    *Ppsz=0;                                                       //~v7bJI~
	if (!(attr & (UVIOMATTR_EXT_SCMBASE|UVIOMATTR_EXT_COMBBASE)))  //~v7bJR~
    {                                                              //~v7bJI~
    	UTRACEP("%s:return 0,Not combining(SCM) ucs=0x%04x,attr=0x%04x\n",UTT,Ppcch->chars[0],attr);//~v7bJR~
    	return 0;                                                  //~v7bJI~
    }                                                              //~v7bJI~
//  sz=getCombinedStringWidth(Popt,Ppcch,0/*Ppctr*/);	//except SCM//~v7bJR~//~v7bPR~
    sz=getCombinedStringWidth(Popt,Ppcch,&ctrComb);	//except SCM   //~v7bPI~
    *PpszComb=sz-ctrComb;   //2 for widesbcs                       //~v7bPI~
	if (attr & UVIOMATTR_EXT_SCMBASE)                              //~v7bJI~
    {                                                              //~v7bJI~
        ctr=1;                                                     //~v7bJI~
	    for (pcch=Ppcch+1,ii=0;ii<UVIOMATTR_MAXSCM && pcch<Ppcche;ii++,pcch++)//~v7bJR~
    	{                                                          //~v7bJI~
			attr=pcch->attr;                                       //~v7bJI~
	    	UTRACEP("%s:SCM ucs=0x%04x,attr=0x%04x\n",UTT,pcch->chars[0],attr);//~v7bJI~
			if (attr & UVIOMATTR_BREAK)                            //~v7bJR~
            	break;                                             //~v7bJR~
			if (!(attr & UVIOMATTR_EXT_SCM))                       //~v7bJR~
            	break;                                             //~v7bJR~
            ctr++;                                                 //~v7bJI~
            sz++;                                                  //~v7bJI~
	    	UTRACEP("%s:SCM ctr=%d,sz=%d,ucs=0x%04x\n",UTT,ctr,sz,pcch->chars[0]);//~v7bJR~
        }                                                          //~v7bJI~
    }                                                              //~v7bJI~
    else                                                           //~v7bJI~
    {                                                              //~v7bPI~
    	swWideSbcsCombBase=(attr & UVIOMATTR_EXT_WIDESBCS)!=0;     //~v7bPR~
        ctr=1;                                                     //~v7bJI~
    }                                                              //~v7bPI~
    *PpswWideSbcsCombBase=swWideSbcsCombBase;                      //~v7bPI~
    *Ppctr=ctr;                                                    //~v7bJI~
    *Ppsz=sz;                                                      //~v7bJI~
    UTRACEP("%s:return sz=%d,base ucs=0x%04x,ucsctr=%d,szComb=%d,swWideSbcsCombBase=%d\n",UTT,sz,Ppcch->chars[0],ctr,*PpszComb,swWideSbcsCombBase);//~v7bJR~//~v7bPR~
    return sz;                                                     //~v7bJI~
}                                                                  //~v7bJI~
//*******************************************************          //~v7bJM~
int setBaseEntrySCM(int Popt,cchar_t *Ppcchar0,cchar_t *Ppcchar,cchar_t **Pppbase)//~v7bJM~
{                                                                  //~v7bJM~
	int combinectr=0;                                              //~v7bJM~
	cchar_t *pcc,*pccbase=0,*top;                                  //~v7bJR~
   	UTRACEP("%s:opt=0x%02x\n",UTT,Popt);                           //~v7bJI~
	Ppcchar->attr|=UVIOMATTR_EXT_SCM;                              //~v7bJI~
    top=ScchTop;                                                   //~v7bJR~
    if (!top)                                                      //~v7bJI~
    	top=Ppcchar0;                                              //~v7bJI~
    for (pcc=Ppcchar-1;pcc>=top;pcc--)                             //~v7bJR~
	{                                                              //~v7bJM~
   		UTRACEP("%s:ucs=0x%04x,attr=0x%04x\n",UTT,pcc->chars[0],pcc->attr);//~v7bJM~
   		attr_t attr=pcc->attr;                                     //~v7bJR~
        if ((attr & UVIOMATTR_DBCS2)!=0)         //temporary padding flag//~v7bJI~
            continue;                                              //~v7bJI~
        if (attr & UVIOMATTR_EXT_SCMBASE)                          //~v7bJI~
        {                                                          //~v7bJI~
    		UTRACEP("%s:reached base ucs=0x%04x\n",UTT,pcc->chars[0]);//~v7bJI~
        	pccbase=pcc;                                           //~v7bJI~
        	break;                                                 //~v7bJI~
        }                                                          //~v7bJI~
		if (attr & UVIOMATTR_EXT_SCM)                              //~v7bJR~
        {                                                          //~v7bJM~
			if (attr & UVIOMATTR_BREAK)                            //~v7bJI~
            {                                                      //~v7bJI~
	    		UTRACEP("%s:intermediate SCM with break attr ucs=0x%04x\n",UTT,pcc->chars[0]);//~v7bJI~
    	    	break;                                             //~v7bJI~
            }                                                      //~v7bJI~
        	combinectr++;                                          //~v7bJM~
           	continue;                                              //~v7bJM~
        }                                                          //~v7bJM~
        if (!UTF_COMBINABLE(pcc->chars[0]))                        //~v7bJI~
        {                                                          //~v7bJI~
    		UTRACEP("%s:Not combinable BREAK ucs=0x%04x\n",UTT,pcc->chars[0]);//~v7bJI~
        	break;                                                 //~v7bJI~
        }                                                          //~v7bJI~
        pccbase=pcc;                                               //~v7bJM~
        break;                                                     //~v7bJM~
	}                                                              //~v7bJM~
    if (pccbase)                                                   //~v7bJI~
    {                                                              //~v7bJI~
		if (Popt & SBEO_2CELL)                                     //~v7bJI~
    		UVIOMATTR_ADD_DBCSCOMBCTR(pccbase);	//calc culomn      //~v7bJI~
		pccbase->attr|=UVIOMATTR_EXT_SCMBASE;                      //~v7bJI~
	   	UTRACEP("%s:combinectr=%d,baseucs=0x%04x,baseattr=0x%04x\n",UTT,combinectr,pccbase->chars[0],pccbase->attr);//~v7bJI~
   		UTRACED("base",pccbase,CCHSZ);                             //~v7bJI~
    }                                                              //~v7bJI~
    *Pppbase=pccbase;                                              //~v7bJM~
   	UTRACEP("%s:combinectr=%d,base=%p\n",UTT,combinectr,pccbase);  //~v7bJR~
   	return combinectr;                                             //~v7bJM~
}//setBaseEntrySCM                                                 //~v7bJR~
//*******************************************************          //~v7bJI~
//*search baseSCM beyond breaksw                                   //~v7bJI~
//*******************************************************          //~v7bJI~
PCCH getBaseSCM(int Popt,PCCH Ppcch0,PCCH Ppcch)                   //~v7bJI~
{                                                                  //~v7bJI~
	CCH *pcch,*pbase=0,*top;                                       //~v7bJR~
   	UTRACEP("%s:opt=0x%04x,ScchTop=%p,Ppcch0=%p\n",UTT,Popt,ScchTop,Ppcch);//~v7bLI~
    top=ScchTop;                                                   //~v7bJR~
//  if (!top)                                                      //~v7bJI~//~v7bLR~
    if (Ppcch0>top)                                                //~v7bLI~
    	top=Ppcch0;                                                //~v7bJI~
    for (pcch=Ppcch-1;pcch>=top;pcch--)                            //~v7bJR~
	{                                                              //~v7bJI~
   		UTRACEP("%s:ucs=0x%04x,attr=0x%04x\n",UTT,pcch->chars[0],pcch->attr);//~v7bJI~
   		attr_t attr=pcch->attr;                                    //~v7bJR~
        if ((attr & UVIOMATTR_DBCS2)!=0)         //temporary padding flag//~v7bJI~
            continue;                                              //~v7bJI~
        if (attr & UVIOMATTR_EXT_SCMBASE)                          //~v7bJI~
        {                                                          //~v7bJI~
    		UTRACEP("%s:reached base ucs=0x%04x\n",UTT,pcch->chars[0]);//~v7bJR~
        	pbase=pcch;                                            //~v7bJR~
        	break;                                                 //~v7bJI~
        }                                                          //~v7bJI~
		if (attr & UVIOMATTR_EXT_SCM)                              //~v7bJI~
        {                                                          //~v7bJI~
			if (Popt & GBSO_SCM)		//find break scm           //~v7bLR~
            {                                                      //~v7bLR~
                pbase=pcch;                                        //~v7bLR~
                UTRACEP("%s:found SCM ucs=0x%04x\n",UTT,pcch->chars[0]);//~v7bLR~
                break;                                             //~v7bLR~
            }                                                      //~v7bLR~
           	continue;                                              //~v7bJI~
        }                                                          //~v7bJI~
        else                                                       //~v7bLI~
		if (Popt & GBSO_SCM)		//find break scm               //~v7bLI~
        {                                                          //~v7bLI~
            UTRACEP("%s:Not fund SCM\n",UTT);                      //~v7bLI~
            break;                                                 //~v7bLI~
        }                                                          //~v7bLI~
        if (!UTF_COMBINABLE(pcch->chars[0]))                       //~v7bJI~
        {                                                          //~v7bJI~
    		UTRACEP("%s:Not combinable BREAK ucs=0x%04x\n",UTT,pcch->chars[0]);//~v7bJI~
        	break;                                                 //~v7bJI~
        }                                                          //~v7bJI~
    	UTRACEP("%s:found baseSCM ucs=0x%04x\n",UTT,pcch->chars[0]);//~v7bJI~
        pbase=pcch;                                                //~v7bJR~
        break;                                                     //~v7bJI~
	}                                                              //~v7bJI~
   	UTRACEP("%s:base=%p\n",UTT,pbase);                             //~v7bJR~
   	return pbase;                                                  //~v7bJR~
}//getBaseSCM                                                      //~v7bJI~
//*********************************************                    //~v7bJI~
//*set file data top column cch for search baseSCM,baseCombine     //~v7bJI~
//*********************************************                    //~v7bJI~
int getTopCCH(int Plineopt,chtype *Ppcht,char *Ppdbcs,int Plen)    //~v7bJI~
{                                                                  //~v7bJI~
	int ii,col=0;                                                  //~v7bJI~
    chtype *pct;                                                   //~v7bJR~
    char *pdbcs;                                                   //~v7bJI~
    if (Plineopt & UVIOO_CSRPOSCHK)                                //~v7bJI~
        for (pct=Ppcht,pdbcs=Ppdbcs,ii=0;ii<Plen && ii<ULHLINENOSZ_1;ii++,pct++,pdbcs++)//~v7bJI~
        {                                                          //~v7bJI~
        	if (!*pdbcs                                            //~v7bYR~
 			&&  ((*pct & A_CHARTEXT)==SEP_LINENO||(*pct & A_CHARTEXT)==SEP_LINENO2) //'|' or '*'//~v7bYI~
               )                                                   //~v7bYI~
            {                                                      //~v7bJI~
            	col=ii+1;                                          //~v7bJI~
                break;	                                           //~v7bJI~
            }                                                      //~v7bJI~
        }                                                          //~v7bJI~
    UTRACEP("%s:col=%d\n",UTT,col);                                //~v7bJR~
    return col;                                                    //~v7bJI~
}                                                                  //~v7bJI~
#endif //LNXCON                                                    //~v7bEM~
//*********************************************                    //~v7bRI~
void getcsrposbca(int Popt,char *Ppdbcs,int Pcol,int Pposx,int *Ppposb,int *Ppposc,int *Ppposa)//~v7bRR~
{                                                                  //~v7bRI~
	utfddgetcsrposbca(Popt,Ppdbcs,Pcol,Pposx,Ppposb,Ppposc,Ppposa);//~v7bRI~
    if (Ppposb && *Ppposb>0 && *Ppposb<=SwidthLineno)              //~v7bRR~
    	*Ppposb=-1;                                                //~v7bRI~
    if (Ppposc && *Ppposc>0 && *Ppposc<=SwidthLineno)              //~v7bRR~
    	*Ppposc=-1;                                                //~v7bRI~
    if (Ppposa && *Ppposa>0 && *Ppposa<=SwidthLineno)              //~v7bRR~
    	*Ppposa=-1;                                                //~v7bRI~
    UTRACEP("%s:posb=%d,posc=%d,posa=%d\n",UTT,(Ppposb!=0?*Ppposb:-1),(Ppposc!=0?*Ppposc:-1),(Ppposa!=0?*Ppposa:-1));//~v7bRI~
}                                                                  //~v7bRI~
//*********************************************                    //~v7c4I~
int getBaseUCS(int Popt,cchar_t *Ppcch)                            //~v7c4I~
{                                                                  //~v7c4I~
	int base=Ppcch->chars[0];                                      //~v7c4I~
    int rc=base;                                                   //~v7c4I~
    if (Ppcch->attr & UVIOMATTR_EXT_ALTCH)  //set altch            //~v7c4R~
    {                                                              //~v7c4I~
		int altbase=uviom_getAltFormat(UVMGAFO_GETORGUCS,base,0/*Pdefault for other Format char*/);//~v7c4R~
        if (altbase)                                               //~v7c4I~
//      	rc=altbase; //ZWJ or ZWNJ      TODO test               //~v7c4R~
			rc=COMBAINE_BASE_SPLIT_ITSELF;// 0xa0     //u00a0 base for combining char when split itself//~v7c4I~
    }                                                              //~v7c4I~
    return rc;                                                     //~v7c4I~
    UTRACEP("%s:rc=%d,baseUcs=%d\n",UTT,rc,base);                  //~v7c4I~
}                                                                  //~v7c4I~
#ifdef LNXCON                                                      //~v7f4I~
#ifndef JJJ                                                        //~v7f4I~
//***************************************************************************//~v7f4I~
void uviom_setcchar_itself_W0NOCOMB(int Popt,WUCS Pucs,cchar_t *Ppcchar)//~v7f4I~
{                                                                  //~v7f4I~
	UTRACEP("%s:opt=0x%04x,Pucs=0x%04x\n",UTT,Popt,Pucs);          //~v7f4I~
    if (setccharFormat(Popt,Pucs,Ppcchar))                         //~v7f4I~
    	return;                                                    //~v7f4I~
    Ppcchar->chars[0]=COMBAINE_BASE_SPLIT_ITSELF;     //u00a0 base for combining char when split itself//~v7f4I~
    Ppcchar->chars[1]=Pucs;     //combining char itself            //~v7f4I~
	if (Popt & UVIOMATTR_EXT_LIGATURE)//extended option, ligature  //~v7f4I~
    {                                                              //~v7f4I~
  	  	if (Popt & UVIOMATTR_PADDING2)  //for the case ligature not combine mode//~v7f4I~
    		Ppcchar->attr|=UVIOMATTR_EXT_PADDING2;    //ALTCH2 will be follows//~v7f4I~
    }                                                              //~v7f4I~
  	Ppcchar->attr|=UVIOMATTR_EXT_DMYBASE;     //added "A0" entry for combining//~v7f4I~
	UTRACED("cchar",Ppcchar,sizeof(cchar_t));                      //~v7f4I~
}//uviom_setcchar_itself                                           //~v7f4I~
//***************************************************************  //~v7f4I~
int uviom_setcombine1_W0NOCOMB(int Popt,int Plineopt,WUCS Pucs,WUCS Pucsbase,chtype *Ppcht,cchar_t *Ppcchar,cchar_t *Ppcchar0)//~v7f4I~
{                                                                  //~v7f4I~
//  int attr,attropt;                                              //~v7f4I~
    int attropt;                                                   //~v7f4I~
    attr_t attr;                                                   //~v7f4I~
#define UVIOM_DUMMYBASE  0xfeff //0x00a0 //0x200b                  //~v7f4I~
    int rc=0;                                                      //~v7f4I~
    cchar_t *pcchar_padding2;                                      //~v7f4I~
    int swShadowDbcs=0;                                            //~v7f4I~
//************************                                         //~v7f4I~
UTRACEP("%s:entry opt=0x%x,ucs=%04x,ucsbase=%04x,Scombaltch=%x,SswComb1W0NOCOMB\n",UTT,Popt,Pucs,Pucsbase,Scombaltch,SswComb1W0NOCOMB);//~v7f4I~//~v7f5R~
	attropt=Popt & UVIOMATTR_BREAK;                                //~v7f4I~
  if (Popt & UVIOMATTR_SETATTR)   //for the case ligature not combine mode//~v7f4I~
  {                                                                //~v7f4I~
   if (COMBINEMODE(Plineopt))                                      //~v7f4I~
	attr=uviom_set_padattr(0,*Ppcht & A_COLOR)>>8;                 //~v7f4I~
   else                                                            //~v7f4I~
   {                                                               //~v7f4I~
    attr=(attr_t)uviol_repfg((int)*Ppcht,ATTR_COMBINENP_FG);       //~v7f4I~
    UTRACEP("%s:attr rep=%04x\n",UTT,attr);                        //~v7f4I~
   }                                                               //~v7f4I~
  }                                                                //~v7f4I~
  else                                                             //~v656I~=//~v7f4I~
    attr=(*Ppcht & ~(A_CHARTEXT))>>8;                              //~v7f4I~
                                                                   //~v7f4I~
    Ppcchar->attr=(attr<<8)|(attr_t)attropt;//break flag           //~v7f4I~
//  if (!Pucsbase)                                                 //~v7f4I~
//  {                                                              //~v7f4I~
  	if (Scombaltch==UVIOM_ALTCHPADDING)                            //~v7f4I~
    	Ppcchar->chars[0]=Guviomdbcspad;                           //~v7f4I~
    else                                                           //~v7f4I~
    {                                                              //~v7f4I~
        uviom_setcchar_itself(Popt,Pucs,Ppcchar);                  //~v7f4I~
    }                                                              //~v7f4I~
//  } //Pucsbacse=0                                                //~v7f4I~
//  else                                                           //~v7f4I~
//  if (UTF_COMBINABLE(Pucsbase))                                  //~v7f4I~
//  {                                                              //~v7f4I~
//  if (!chkBaseSplitSCM(Popt,Plineopt,attropt,Pucsbase,Pucs,Ppcht,Ppcchar,Ppcchar0))//~v7f4I~
//  {                                                              //~v7f4I~
//   if (Scombaltch==UVIOM_ALTCHPADDING)                           //~v7f4I~
//   {                                                             //~v7f4I~
//    Ppcchar->chars[0]=uviom_getAltFormat(0,Pucs,Guviomdbcspad);  //~v7f4I~
//    if (Ppcchar->chars[0]!=Guviomdbcspad)                        //~v7f4I~
//    {                                                            //~v7f4I~
//        Ppcchar->attr|=UVIOMATTR_EXT_ALTCH;  //could not be a combine base//~v7f4I~
//        UTRACEP("%s:ALTCH set EXT_ALTCH chars[0]=0x%04x,attr=0x%04x\n",UTT,Ppcchar->chars[0],Ppcchar->attr);//~v7f4I~
//    }                                                            //~v7f4I~
//   }                                                             //~v7f4I~
//   else                                                          //~v7f4I~
//   if (Scombaltch==UVIOM_ALTCHSHADOW)                            //~v7f4I~
//   {                                                             //~v7f4I~
//  if (Popt & UVIOMATTR_BASEDBCS) //base is dbcs                  //~v7f4I~
//  {                                                              //~v7f4I~
//   int rc2= //0:1 cell written, 1:2 cell written                 //~v7f4I~
//    uviom_setcchar_shadow(Popt,Pucsbase,Pucs,Ppcchar,Ppcchar0);  //~v7f4I~
//   if (rc2)                                                      //~v7f4I~
//   {                                                             //~v7f4I~
//    rc=1;   //added 1 cchar                                      //~v7f4I~
//    swShadowDbcs=1;                                              //~v7f4I~
//   }                                                             //~v7f4I~
//  }                                                              //~v7f4I~
//  else                                                           //~v7f4I~
//  {                                                              //~v7f4I~
//    uviom_setcchar_shadow(Popt,Pucsbase,Pucs,Ppcchar,Ppcchar0);  //~v7f4I~
//  }//!dbcs                                                       //~v7f4I~
//   }                                                             //~v7f4I~
//   else                                                          //~v7f4I~
//   if (Scombaltch==UVIOM_ALTCHITSELF)                            //~v7f4I~
//   {                                                             //~v7f4I~
//    Ppcchar->chars[0]=Pucs;     //combining char itself          //~v7f4I~
//   if (!(Plineopt & UVIOO_CSRPOSCHK))       // file data line    //~v7f4I~
//    Ppcchar->attr=uviom_attr_itself(Plineopt,*Ppcht)|(attr_t)attropt;//~v7f4I~
//    if (Plineopt & UVIOO_CSRPOSCHK)        // file data line     //~v7f4I~
//        uviom_setcchar_itself(Popt,Pucs,Ppcchar);                //~v7f4I~
//   }                                                             //~v7f4I~
//   else                                                          //~v7f4I~
//   if (UTF_COMBINEMODE())   //entered to combine1 by lineopt,same as itself//~v7f4I~
//   {                                                             //~v7f4I~
//    UTRACEP("%s:UTF_COMBINEMODE\n",UTT);                         //~v7f4I~
//    Ppcchar->chars[0]=Pucs;     //combining char itself          //~v7f4I~
//   if (!(Plineopt & UVIOO_CSRPOSCHK))       // file data line    //~v7f4I~
//    Ppcchar->attr=uviom_attr_itself(Plineopt,*Ppcht)|(attr_t)attropt;//~v7f4I~
//   }                                                             //~v7f4I~
//   else                                                          //~v7f4I~
//   {                                                             //~v7f4I~
//    Ppcchar->chars[0]=Scombaltch;     //combining char special parm//~v7f4I~
//      if (!(Popt & UVIOMATTR_PADDING2))  //Not ovf combine char(for the case ligature not combine mode)//~v7f4I~
//      {                                                          //~v7f4I~
//        UTRACEP("%s:Not combinemode and not padding2, set altch Pucs=%04x\n",UTT,Pucs);//~v7f4I~
//      }                                                          //~v7f4I~
//   }                                                             //~v7f4I~
//  }//bse is not splitSCM                                         //~v7f4I~
//      }//combinable                                              //~v7f4I~
//  else                                                           //~v7f4I~
//  if (Popt & UVIOMATTR_EXT_BASEUNP)//  0x200000     //base is unprintable//~v7f4I~
//  {                                                              //~v7f4I~
//        if (Scombaltch==UVIOM_ALTCHPADDING)                      //~v7f4I~
//            Ppcchar->chars[0]=Guviomdbcspad;                     //~v7f4I~
//        else                                                     //~v7f4I~
//        if (Scombaltch==UVIOM_ALTCHITSELF                        //~v7f4I~
//        ||  Scombaltch==UVIOM_ALTCHSHADOW                        //~v7f4I~
//        ||  UTF_COMBINEMODE()    //entered to combine1 by lineopt,same as itself//~v7f4I~
//        )                                                        //~v7f4I~
//        {                                                        //~v7f4I~
//            Ppcchar->chars[0]=Pucs;     //combining char itself  //~v7f4I~
//            if (Plineopt & UVIOO_CSRPOSCHK)        // file data line//~v7f4I~
//                uviom_setcchar_itself(Popt,Pucs,Ppcchar);        //~v7f4I~
//        }                                                        //~v7f4I~
//        else                                                     //~v7f4I~
//        {                                                        //~v7f4I~
//            UTRACEP("%s:UNPR+combine:NP mode\n",UTT);            //~v7f4I~
//            Ppcchar->chars[0]=Scombaltch;     //combining char special parm//~v7f4I~
//            if (!(Popt & UVIOMATTR_PADDING2))  //Not ovf combine char(for the case ligature not combine mode)//~v7f4I~
//            {                                                    //~v7f4I~
//                if (Popt & UVIOMATTR_BREAK)   //not around csr column//~v7f4I~
//                    uviom_setcchar_itself(Popt,Pucs,Ppcchar);    //~v7f4I~
//            }                                                    //~v7f4I~
//        }                                                        //~v7f4I~
//  }                                                              //~v7f4I~
//  else                                                           //~v7f4I~
//  if (Pucsbase<0x80)    //not combinable ascii                   //~v7f4I~
//  {                                                              //~v7f4I~
//    Ppcchar->chars[0]=Guviomdbcspad;                             //~v7f4I~
//  }                                                              //~v7f4I~
//  else                                                           //~v7f4I~
//    Ppcchar->chars[0]=Pucs;                                      //~v7f4I~
                                                                   //~v7f4I~
  if (!swShadowDbcs)                                               //~v7f4I~
  	if (Popt & UVIOMATTR_PADDING2)  //for the case ligature not combine mode//~v7f4I~
    {                                                              //~v7f4I~
        pcchar_padding2=Ppcchar+1;                                 //~v7f4I~
	    pcchar_padding2->chars[0]=UVIOM_COMBINE_ALTCH2;            //~v7f4I~
	    pcchar_padding2->attr=(ATTR_COMBINE_FG_UCS4<<8);           //~v7f4I~
	    pcchar_padding2->attr|=ATTR_COMBINE_PADDING_NOHCOPY;//   A_DIM //padding to be dropped from hcopy//~v7f4I~
        rc=1;                                                      //~v7f4I~
    }                                                              //~v7f4I~
UTRACEP("%s:single combine parm=%x,opt=%x,rc=%d,char ucs=%x,prevucs=%x,chtype=%x,swShadowDbcs=%d\n",UTT,Scombaltch,Popt,rc,Pucs,Pucsbase,*Ppcht,swShadowDbcs);//~v7f4I~
UTRACED("out Ppcchar",Ppcchar,CCHSZ*(rc+1));                       //~v7f4I~
    return rc;   //outctr=1/2                                      //~v7f4I~
}//uviom_setcombine1                                               //~v7f4I~
//***************************************************************  //~v7f4I~
int uviom_setcombine_W0NOCOMB(int Popt,int Plineopt,WUCS Pucs,chtype *Ppcht,cchar_t *Ppcchar0,cchar_t *Ppcchar,UCHAR *Ppdbcs,int Plen,int *Ppcombinectr,int *Ppwritectr,int *Ppmblen)//~v7f4I~
{                                                                  //~v7f4I~
    int combinectr=0,/*ii,*/rc=0,outctr=0,opt;                     //~v7f4R~
//    int setbreak=0;                                              //~v7f4R~
//    chtype  *pct;                                                //~v7f4R~
//    cchar_t *pcc,*pccpadd,*pccprev;                              //~v7f4R~
    WUCS    /*ucs,*/prevucs=0;                                     //~v7f4I~
	int /*swcombine,*/mblen=0;                                     //~v7f4I~
//**************************                                       //~v7f4I~
UTRACEP("%s:entry opt=%x,len=%d,ucs=%04x,dbcsid=%x\n",UTT,Popt,Plen,Pucs,*Ppdbcs);//~v7f4I~
UTRACED("entry Pcchar",Ppcchar,CCHSZ);                             //~v7f4I~
//    pcc=Ppcchar;    //output                                     //~v7f4R~
//    pct=Ppcht;  //input                                          //~v7f4R~
//    for (;;)                                                     //~v7f4R~
//    {                                                            //~v7f4R~
//        if (pcc==ScchTop                                         //~v7f4R~
//        ||  (Popt & UVIOMSCO_FORCEBREAK)                         //~v7f4R~
//        ||  ((pcc-1)->attr & UVIOMATTR_BREAK)   //prev is single combine//~v7f4R~
//        )                                                        //~v7f4R~
//        {                                                        //~v7f4R~
//            setbreak=1;                                          //~v7f4R~
//            break;                                               //~v7f4R~
//        }                                                        //~v7f4R~
//        if (!COMBINEMODE(Plineopt)) //split mode                 //~v7f4I~
//        {                                                        //~v7f4I~
//            setbreak=1; //keep colomn for Altch especially ITSELF mode//~v7f4I~
//            break;                                               //~v7f4I~
//        }                                                        //~v7f4I~
//        int color=(*pct & UVIOMATTR_COLORMASK);//    0xFF00      //~v7f4I~
//        int opt2=0;                                              //~v7f4I~
//        if (UDBCSCHK_DBCS1STUCS2NWO(*Ppdbcs))                    //~v7f4I~
//            opt2|=SBEO_2CELL;                                    //~v7f4I~
//        cchar_t *pccbase=setBaseEntry(opt2,Ppcchar0,Ppcchar,color,Pucs,&combinectr);//~v7f4I~
//        if (!pccbase)                                            //~v7f4I~
//            break;                                               //~v7f4I~
//        mblen=0;                                                 //~v7f4I~
//        pccpadd=Ppcchar;                                         //~v7f4I~
//        for (ii=0;ii<2;ii++)                                     //~v7f4I~
//        {                                                        //~v7f4I~
//            int swAltch=0;                                       //~v7f4I~
//          if (ii==1)                                             //~v7f4I~
//          {                                                      //~v7f4I~
//            pccpadd->chars[0]=UVIOM_COMBINE_ALTCH2; //'.'        //~v7f4I~
//          }                                                      //~v7f4I~
//          else                                                   //~v7f4I~
//          {                                                      //~v7f4I~
//            pccpadd->chars[0]=uviom_getAltFormat(0,Pucs,Guviomdbcspad);//~v7f4I~
//            if (pccpadd->chars[0]!=Guviomdbcspad)                //~v7f4I~
//                swAltch=1;  //ZWJ etc                            //~v7f4I~
//          }                                                      //~v7f4I~
//            pccpadd->attr=uviom_set_padattr(0,ATTR_COMBINE_FG_UCS4<<8);//~v7f4I~
//            pccpadd->attr|=UVIOMATTR_EXT_PADDCOMB;  // 0x04000000     //padding beteen base and combining//~v7f4I~
//            pccpadd->attr|=ATTR_COMBINE_PADDING_NOHCOPY;//   A_DIM //padding to be dropped from hcopy//~v7f4I~
//            if (swAltch)    //ZWJ etc                            //~v7f4I~
//            {                                                    //~v7f4I~
//                pccpadd->attr|=UVIOMATTR_EXT_ALTCH; // 0x04000000     //padding beteen base and combining//~v7f4I~
//                UTRACEP("%s:ALTCH set EXT_ALTCH char[0]=0x%04x,attr=0x%04x\n",UTT,pccpadd->chars[0],pccpadd->attr);//~v7f4I~
//            }                                                    //~v7f4I~
//            UTRACEP("%s:PADDCOMB char[0]=0x%04x,attr=0x%04x\n",UTT,pccpadd->chars[0],pccpadd->attr);//~v7f4I~
//            mblen++;                                             //~v7f4I~
//            UTRACEP("%s:padding base=0x%04x,combinining ucs=0x%04x,combinectr=%d\n",UTT,pccbase->chars[0],Pucs,combinectr);//~v7f4I~
//            if (!(Popt & UVIOMSCO_COMB2SCM))//        0x80  //u3099,309a:dbcs//~v7f4I~
//                break;                                           //~v7f4I~
//            pccpadd++;                                           //~v7f4I~
//        }                                                        //~v7f4I~
//        outctr=mblen;                                            //~v7f4I~
//UTRACED("setcombine",Ppcchar,outctr*(int)sizeof(cchar_t));       //~v7f4I~
//        rc=1;                                                    //~v7f4I~
//        break;                                                   //~v7f4I~
//    }                                                            //~v7f4R~
//    if (!rc)                                                     //~v7f4R~
////not combine, write                                             //~v7f4R~
//    {                                                            //~v7f4R~
    	opt=0;                                                     //~v7f4I~
//        if (setbreak)                                            //~v7f4R~
	        opt|=UVIOMATTR_BREAK;                                  //~v7f4I~
      	  if (!(Popt & UVIOMSCO_NOSETATTR))                        //~v7f4I~
	        opt|=UVIOMATTR_SETATTR;	//set fg:green                 //~v7f4I~
//        int colorCombining=(*pct & UVIOMATTR_COLORMASK);//    0xFF00//~v7f4R~
        int opt2=0;                                                //~v7f4I~
		if (UDBCSCHK_DBCS1STUCS2NWO(*Ppdbcs))                      //~v7f4I~
        	opt2|=SBEO_2CELL;                                      //~v7f4I~
//        pccprev=setBaseEntry(opt2,Ppcchar0,Ppcchar,colorCombining,0/*Pucs=0:No set combining*/,0/*Ppcombctr*/);//~v7f4I~
//        if (pccprev)                                             //~v7f4I~
//        {                                                        //~v7f4I~
//            prevucs=pccprev->chars[0];                           //~v7f4I~
//            if (pccprev->attr & UVIOMATTR_DBCS12)  //dbcs        //~v7f4I~
//                opt|=UVIOMATTR_BASEDBCS;                         //~v7f4I~
//            if (pccprev->attr & UVIOMATTR_EXT_WIDESBCS)  //dbcs  //~v7f4I~
//                opt|=UVIOMATTR_EXT_BASEWIDE;                     //~v7f4I~
//        }                                                        //~v7f4I~
//        pccprev=0;                                               //~v7f4R~
//        if (Popt & UVIOMSCO_COMB2SCM)//        0x80  //u3099,309a:dbcs//~v7f4R~
//            opt|=UVIOMATTR_PADDING2;//ucs4 width0                //~v7f4R~
//        if (Popt & UVIOMSCO_BASEUNP) //base unprintable(":;")    //~v7f4R~
//            opt|=UVIOMATTR_EXT_BASEUNP;//base is inprintable     //~v7f4R~
        if (Popt & UVIOMSCO_WIDESBCS)                              //~v7f4I~
	        opt|=UVIOMATTR_EXT_WIDESBCS;                           //~v7f4I~
//ovf combine or shaddow generated                                 //~v7f4I~
        outctr=1+                                                  //~v7f4I~
        uviom_setcombine1_W0NOCOMB(opt,Plineopt,Pucs,prevucs,Ppcht,Ppcchar,Ppcchar0);//~v7f4I~
        combinectr=1;   //loop ctr;                                //~v7f4I~
//        mblen=1+((Popt & UVIOMSCO_COMB2SCM)!=0);//        0x80  //u3099,309a:dbcs//~v7f4R~
        mblen=1;                                                   //~v7f4I~
//        if (outctr>1) //non spacing combining diacritical mark supported//~v7f4R~
//            pccpadd++;                                           //~v7f4R~
//    }                                                            //~v7f4R~
    *Ppcombinectr=combinectr;                                      //~v7f4I~
    *Ppwritectr=outctr;                                            //~v7f4I~
    *Ppmblen=mblen;                                                //~v7f4I~
UTRACEP("%s: rc=%d,len=%d,ucs=%04x,combinectr=%d,outctr=%d,out mblen=%d\n",UTT,rc,Plen,Pucs,combinectr,outctr,mblen);//~v7f4I~
    return rc;                                                     //~v7f4I~
}//uviom_setcombine_W~NOCOMB                                       //~v7f4I~
#endif //ndef JJJ                                                  //~v7f4I~
#endif //LNXCON                                                    //~v7f4I~
