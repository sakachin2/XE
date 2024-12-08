//*CID://+vbw0R~:                             update#=  335;       //~vbw0R~
//************************************************************
//* xekbd.c                                                     //~5501R~
//************************************************************  //~5423I~
//vbw0:221203 (Bug)Shift+ was ignored with Ctrl+/Alt               //~vbw0I~
//vbvz:221203 (Bug)=0.1;missing set string terminater null         //~vbvzI~
//vbvv:221203 =0.1 comment for user command, and comment support   //~vbvvI~
//vbvo:221201 show sample for sc cmd of =0.1                       //~vbvoI~
//vbv8:221123 (Bug)output same graphic char by Ctl+Pad1(locale assigned but utf8 not assigned) after Alt+Shift+1(UTF8 assigned by xelchwxe.ini).//~vbv8I~
//            A+S+1 output UTF8 string and next C+Pad1 also output same utf8 string.//~vbv8I~
//            Caused by missing clear UCWF2UTF7STR.                //~vbv8I~
//vbt4:201212 (WIN)apply -Nm on LC file only                       //~vbt4I~
//vbrk:200918 (AXE)first time scrgetcw fails, allow it             //~vbrkI~
//vbrf:200821 A+a/A+q(shortcut/query) repeat err(not alpnumeric stop repeat)//~vbrfI~
//vbr5:200721 (ARM)logcat hung at utrace output([0x1a..) , it may be Esc[//~vbr5I~
//vbr1:200615 ARM compiler warning                                 //~vbr1I~
//vbkm:180625 UTRACE;add option of ignore FORCE option             //~vbkmI~
//vb83:170206 (BUG)crash 64bit ptr size isckt was not cleared cmdptr//~vb83I~
//vb50:160827 accept S+A/C+extended key                            //~vb50I~
//vb31:160418 (LNX64)Compiler warning                              //~vb31I~
//vb30:160411 (LNX)Compiler warning                                //~vb30I~
//vaz8:150109 C4244 except ULPTR and ULONG                         //~vaz8I~
//vaxa:140628 (Axe)segfault at exit by quit cmd(uerrexit but axe continue process for popup errmsg)//~vaxaI~
//vaq3:131230 (Bug of v127E:van6)rctl is not effective             //~vaq3I~
//vanf:131209 alias cmd;support addtional parm;%*,%^ for filename,%@ all remaining//~vanfI~
//van9:131202 Issue warning to recover RCTL enter off-->on(if on "opt rctl ON" could not be enter)//~van9I~
//van6:131129 (LNX)compiler warning;dereferencing type-punned pointer//~van6I~
//vafm:120626 LLP64 changes infile size                            //~vafmI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vafc:120607 C4701 warning(used uninitialized variable) by VC6    //~vafcI~
//vaf8:120607 (WTL)Bug found by vs2010exp(used uninitialized variable)//~vaf8I~
//va90:110520 ANDROID porting                                      //~va90R~
//va70:000701 LP64 option support                                  //~va70I~
//va6V:100725 drop 0x1a from invalid char tbl for windows(no need for bin mode read)//~va6VI~
//va3D:100310 (WXE)Unicode direct input support(A+"+" and Uxxxx)   //~va3DI~
//va1c:091030_merge GB18030 support                                //~va1cI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          cmdline may be mixed of utf8 and locale code           //~va00I~
//v7aa:081106 (LNX:BUG)european lang generates 0xe0(scan=0x00)     //~v7aaI~
//v7a5:081027 (BUG)dbcs evaluation required when /N8 option specified//~v7a5I~
//v79R:081027 (BUG)dbcs evaluation required when graphic char input specification is by hex notation//~v79RI~
//v79z:080916 DBCS tbl for C and K of CJK                          //~v79zI~
//v8@Z:080715 3270:TSO keyboard mode by A+q                        //~v8@ZI~
//v793:080715 /Nrr option to reset RCT-newline                     //~v793I~
//v791:080714 (gxe:BUG) rctl option is not kept between session    //~v790I~
//v790:080709 RCTLNL cmd line parameter /yn                        //~v790I~
//v78Z:080708 (3270)sw key assignment by hot key                   //~v78ZI~
//v78N:080521 (LNXCON)rctl support                                 //~v78NR~
//v77x:080117 Bug report by M.J                                    //~V77xI~
//v777:071204*EUC hankana chk(2byte but 1 column)                  //~V777I~
//v76i:070622 more(key by key) allowance for duplicated function key assignment//~V768I~
//v768:070613 new RCTL option(Enter->Execute,Rctl->NewLine)        //~V768I~
//v71u:061022 (BUG of v69Y) A+= cause err at xe start because "=" is parsed as delimiter//~V70mI~
//v70m:060811 (!LNX Cons)change graph key input by Shift key not by opt linech on/off//~V70mI~
//v705:060727 graphic char setup by external file                  //~V705I~
//v69Y:060722 add A+"=" to virtical line for 101 keyboard (scancode=13, "^" on japanese kbd)//~V69YI~
//v69A:060609 (LNX:BUG)keyname euc conversion process should be done before before functable init//~V69AI~
//v67C:051228 support alias cmd(save in ini file using shortcut key table position ":")//~V67CI~
//v670:051224 cmd histry retrieve for each screen(A+F12)           //~V670I~
//v64a:050618 (LNX)xxe support                                     //~V64aI~
//v642:050616 (LNX)reset keyy-name to euc like as funcname         //~V642I~
//v58q:040923 (BUG)submit child shell dose not wait key enter      //~V58qI~
//            (as v142,Enter key genarate 0a1c after 0d1c)         //~V58qI~
//v55S:040319 (LNX:BUG)mouse event not ignored                     //~V55SI~
//v55j:040215 (LNX)use ctl+char as alternative of Shift+xx         //~V55jI~
//v55c:040208 (WXE)distingush L-CTL/R-CTL & report R-CTL           //~V55cI~
//v53G:031019 % parm support for shortcutkey cmd                   //~V53GI~
//v53m:030928 (LNX)mouse support                                   //~V53mI~
//v500:020827 wxe support                                          //~V500I~
//v48i:020505 (BUG)too many opd if short cut string has embedding space.//~V48iI~
//v48h:020505 (UNX:BUG)scancode=0 for unix,shortcut chk required after dbcschk fail//~V48hI~
//v48f:020504 more key for macro function(not only PFn but also A+q,A+a and 1 byte char)//~V48fI~
//v40b:010327 LINUX support:ajust after merge                      //~V40bI~
//v404:010309 LINUX support:no break key chk                       //~V404I~
//v20C:001103 LINUX support:0x1a input avail                       //~V20CI~
//v20i:001009 dupkey list order;on edit screen-->dirlist screen    //~v20iI~
//v20b:001001 chk xe assign not by pfk parm                        //~v20bI~
//v19i:000904 LINUX support(kbd io)                                //~v19iI~
//v198:000902 LINUX support(setrate/setstatus dropped)             //~v198I~
//v142:000131:(BUG:WIN)over v0hn;1c/0a follow 1c/0d not only on cmd line etc.//~v0jeI~
//            0x0a is set on file area by cmd+enter.               //~v0jeI~
//            reject 1c/0a when ctrl shift is off(Ctrl+Enter=1c/0a)//~v0jeI~
//v0je:980722 allow s+ for alternative of Shift+ for key assign in ini//~v0jeI~
//v0jc:980721 (BUG)keycmd cut if expanded by % edit                //~v0jcI~
//v0ja:980721 change define value by change opt start from 0.0     //~v0jaI~
//v0j5:980720 (BUG of v0ij)string terminator for no exec cmd       //~v0j5I~
//v0ix:980718 key assign by key press                              //~v0ixI~
//v0iv:980717 (BUG)keyname err,Left-allow-->Left-arrow             //~v0ivI~
//v0io:980702 pfk cmd support(opt 0.4)                             //~v0ioI~
//v0ij:980625 pfk cmd support(save to ini)                         //~v0ijI~
//v0ih:980621 pfk cmd support(pfk table)                           //~v0ihI~
//v0h5:980116 no kbd rate set when both parm is 0                  //~v0h5I~
//v0h2:980115 uget/usetconsolemode for std in/out each             //~v0h2I~
//v0ao:970713 input avail as default 0x00                          //~v0aoI~
//v0ak:970713 input avail as default 0x0a to cut long split line   //~v0akI~
//v09V:970628:change inhibit char table because upnprintable char can be//~v09VI~
//            displayable by v09U                                  //~v09VI~
//v09Q:970625:allow x'7f' to be input as default                   //~v09QI~
//v09t:970523:(BUG)need re-init kbd binary mode after child shell  //~v09tI~
//v096:970412:(DOS:BUG)under Win95,Enter and Pad-Enter generate 0x000d when IMe mode,//~v096R~
//            cause abend at funccall because invalid match with ckftrt.//~v096I~
//            the code is not on manual so treate as 1c0d.         //~v096I~
//            but xefunc chk also scancode==0 before ckftrt chk.   //~v096I~
//v095:970405:DPMI version                                         //~v095I~
//            -\ of dbcs 2nd byte                                  //~v095I~
//            -structure init type chk(need braces for sub structure/array)//~v095I~
//v08j:961112:(W95)save and restore console mode(at exit to dos prompt//~v08jI~
//            need echo mode)                                      //~v08jI~
//v085:961024:W95 VC                                               //~v085I~
//*v03r:950826:for dos accept ctrl+Pause(break=00/00) and uerrexit//~v03rI~
//*v01a:950705:kbd rate ini option(entry and exit value)        //~5705I~
//*v011:950610:double ESC chk(keyin ctr)                        //~5610I~
//************************************************************  //~5610I~
//*950513 eng char allow(not use int 10 but write to video buff)//~5513I~
//*950501 duplicated code 10key and                             //~5501I~
//*       bug,10key / not accepted                              //~5501I~
//************************************************************  //~5501I~
#include <time.h>
#include <stdio.h>
#include <stddef.h>	//offsetof                                     //~va70I~
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//*************************************************************
#ifdef DOS
    #include <dos.h>
#else
    #ifdef W32                                                     //~v085I~
//      #include <windows.h>                                       //~v085I~
    #else                                                          //~v085I~
    #define INCL_BASE
    #include <os2.h>
    #endif                                                         //~v085I~
#endif
#ifdef UNX                                                         //~V40bI~
  #ifndef XXE                                                      //~V64aI~
	#include <termios.h>                                           //~V40bI~
  #endif                                                           //~V64aI~
#endif                                                             //~V40bI~
//*******************************************************
#include <ulib.h>
#include <ualloc.h>                                                //~v0ihI~
#include <utrace.h>
#include <udbcschk.h>
#include <uque.h>
#include <ukbd.h>
#include <ufile.h>                                                 //~v0ioI~
#ifdef W32                                                         //~v0h2I~
    #include <ukbdw.h>                                             //~v0h2I~
#endif                                                             //~v0h2I~
#ifdef UNX                                                         //~v19iI~
 #ifndef XXE                                                       //~V64aI~
    #include <ukbdl.h>                                             //~v19iI~
    #include <ukbdlnxc.h>                                          //~v20bI~
  #ifdef LNX                                                       //~V53mI~
    #include <ukbdlnxm.h>                                          //~V53mI~
  #endif                                                           //~V53mI~
 #endif                                                            //~V64aI~
#endif                                                             //~v19iI~
#include <uerr.h>
#include <uedit.h>                                                 //~v0ijR~
#include <uparse.h>                                                //~V48iI~
#include <ustring.h>                                               //~V642I~
#ifdef FTPSUPP                                                     //~v78ZI~
	#include <uftp.h>                                              //~v78ZI~
#endif                                                             //~v78ZI~
                                                                   //~v0ijI~
#include "xe.h"
#include "xescr.h"
#include "xecsr.h"      //csronthefld                              //~v0ijI~
#include "xefunc.h"
#include "xefunc2.h"    //cmdstack                                 //~v0ijI~
                                                                   //~V48fI~
#define  XEKBD_GLOBAL   //for xekbd.h global extention             //~V48fI~
#include "xekbd.h"                                                 //~v0ihM~
                                                                   //~V48fI~
#include "xefunct.h"                                            //~5424I~
#include "xefile.h"                                                //~v0ijR~
#include "xefile7.h"                                               //~v0ijI~
#include "xepan.h"                                                 //~v0ixI~
#include "xemousel.h"                                              //~V53mR~
#include "xedir.h"                                                 //~v78ZI~
#ifdef XXE                                                         //~V64aI~
	#include <xxexei.h>                                            //~V64aI~
#endif                                                             //~V64aI~
#ifdef FTPSUPP                                                     //~v78ZI~
	#include "xetso.h"                                             //~v78ZR~
#endif                                                             //~v78ZI~
//************************************************
//** define available key conbination for function key
//************************************************
#define KTDEF(key)  {KEY_##key,KEY_S_##key,KEY_A_##key,KEY_C_##key}//~V55cR~
#define KTDEFNFLG(key)  {KEY_##key,KEY_S_##key,KEY_A_##key,KEY_C_##key},{0,0,0,0}//~V55cR~
#define KTDEFDUP(key,flag)  {KEY_##key,KEY_S_##key,KEY_A_##key,KEY_C_##key},{0,0,0,flag}//~v095R~
#define KTDEFDUPS(key,flags,flag)   {KEY_##key,KEY_S_##key,KEY_A_##key,KEY_C_##key},{0,flags,0,flag}//~v0ioI~
#define KTCHAR(key) {0,0,KEY_A_##key,KEY_C_##key},{0,0,KTCHARKEY,KTCHARKEY}//~v095R~
#define KTCHARDUP(key,flag1,flag2) {0,0,KEY_A_##key,KEY_C_##key},{0,0,KTCHARKEY|flag1,KTCHARKEY|flag2}//~V69YI~
static  KEYTBL Sfkeytbl[]=
{//  key-name(Eng),keyname(Jap),4 key value
    {"Esc"        ,"Esc"       ,KTDEF(ESC),  {0,KTSHIFTDUP,0,0}},  //~V55cR~
    {"Tab"        ,"タブ"      ,KTDEFNFLG(TAB)   },                //~V55cR~
    {"Backspace"  ,"後退"      ,KTDEF(BS),   {0,KTSHIFTDUP,0,0}},  //~V55cR~
    {"Enter"      ,"改行"      ,KTDEF(ENTER),{0,KTSHIFTDUP,0,0}},  //~V55cR~
    {"Insert"     ,"挿入"      ,KTDEFDUPS(INS,  KTSHIFTDUP,KTCTLDUP1)},//~v0ioR~
    {"Delete"     ,"削除"      ,KTDEFDUPS(DEL,  KTSHIFTDUP,KTCTLDUP1)},//~v0ioR~
    {"Home"       ,"Home"      ,KTDEFDUPS(HOME, KTSHIFTDUP,KTCTLDUP1)},//~v0ioR~
    {"End"        ,"End"       ,KTDEFDUPS(END,  KTSHIFTDUP,KTCTLDUP1)},//~v0ioR~
    {"Page-up"    ,"前ページ"  ,KTDEFDUPS(PGUP, KTSHIFTDUP,KTCTLDUP1)},//~v0ioR~
    {"Page-down"  ,"次ページ"  ,KTDEFDUPS(PGDN, KTSHIFTDUP,KTCTLDUP1)},//~v0ioR~
    {"Left-arrow" ,"左矢印"    ,KTDEFDUPS(LEFT, KTSHIFTDUP,KTCTLDUP1)},//~v0ivR~
    {"Right-arrow","右矢印"    ,KTDEFDUPS(RIGHT,KTSHIFTDUP,KTCTLDUP1)},//~v0ioR~
    {"Up-arrow"   ,"上矢印"    ,KTDEFDUPS(UP,   KTSHIFTDUP,KTCTLDUP1)},//~v0ioR~
    {"Down-arrow" ,"下矢印"    ,KTDEFDUPS(DOWN, KTSHIFTDUP,KTCTLDUP1)},//~v0ioR~
    {"F1"         ,"F1"        ,KTDEFNFLG(F1)    },                //~V55cR~
    {"F2"         ,"F2"        ,KTDEFNFLG(F2)    },                //~V55cR~
    {"F3"         ,"F3"        ,KTDEFNFLG(F3)    },                //~V55cR~
    {"F4"         ,"F4"        ,KTDEFNFLG(F4)    },                //~V55cR~
    {"F5"         ,"F5"        ,KTDEFNFLG(F5)    },                //~V55cR~
    {"F6"         ,"F6"        ,KTDEFNFLG(F6)    },                //~V55cR~
    {"F7"         ,"F7"        ,KTDEFNFLG(F7)    },                //~V55cR~
    {"F8"         ,"F8"        ,KTDEFNFLG(F8)    },                //~V55cR~
    {"F9"         ,"F9"        ,KTDEFNFLG(F9)    },                //~V55cR~
    {"F10"        ,"F10"       ,KTDEFNFLG(F10)   },                //~V55cR~
    {"F11"        ,"F11"       ,KTDEFNFLG(F11)   },                //~V55cR~
    {"F12"        ,"F12"       ,KTDEFNFLG(F12)   },                //~V55cR~
//*for alt+char key                                             //~5502R~
//*top line                                                     //~5502I~
    {"1"    ,"1"   ,KTCHAR(1)},                                 //~5506R~
    {"2"    ,"2"   ,KTCHAR(2)},                                 //~5506R~
    {"3"    ,"3"   ,KTCHAR(3)},                                 //~5506R~
    {"4"    ,"4"   ,KTCHAR(4)},                                 //~5506R~
    {"5"    ,"5"   ,KTCHAR(5)},                                 //~5506R~
    {"6"    ,"6"   ,KTCHAR(6)},                                 //~5506R~
    {"7"    ,"7"   ,KTCHAR(7)},                                 //~5506R~
    {"8"    ,"8"   ,KTCHAR(8)},                                 //~5506R~
    {"9"    ,"9"   ,KTCHAR(9)},                                 //~5506R~
    {"0"    ,"0"   ,KTCHAR(0)},                                 //~5506R~
    {"-"    ,"-"   ,KTCHAR(MINUS)},                             //~5506R~
//  {"^"    ,"^"   ,KTCHAR(HAT)},                                  //~V69YR~
//  {"^"    ,"^"   ,KTCHARDUP(HAT,KTALTDUP1,0)},                   //~V69YI~,//~V70mR~
//  {"="    ,"="   ,KTCHARDUP(EQUAL,KTALTDUP1,0)},  //0n 101,same as HAT on Japanese kbd//~V69YR~,//~V70mR~
    {"^"    ,"^"   ,KTCHAR(HAT)},       //rep by "=" when english mode//~V70mI~
    {"\\"    ,"\\" ,KTCHAR(YEN)},                               //~5506R~
//*2nd line                                                     //~5502I~
    {"q"    ,"q"   ,KTCHAR(q)},                                 //~5506R~
    {"w"    ,"w"   ,KTCHAR(w)},                                 //~5506R~
    {"e"    ,"e"   ,KTCHAR(e)},                                 //~5506R~
    {"r"    ,"r"   ,KTCHAR(r)},                                 //~5506R~
    {"t"    ,"t"   ,KTCHAR(t)},                                 //~5506R~
    {"y"    ,"y"   ,KTCHAR(y)},                                 //~5506R~
    {"u"    ,"u"   ,KTCHAR(u)},                                 //~5506R~
    {"i"    ,"i"   ,KTCHAR(i)},                                 //~5506R~
    {"o"    ,"o"   ,KTCHAR(o)},                                 //~5506R~
    {"p"    ,"p"   ,KTCHAR(p)},                                 //~5506R~
    {"@"    ,"@"   ,KTCHAR(ACCNT)},                             //~5506R~
    {"["    ,"["   ,KTCHAR(LMP)},//left middle parenthesis      //~5506R~
                                                                //~5502I~
//*3rd line                                                     //~5502I~
    {"a"    ,"a"   ,KTCHAR(a)},                                 //~5506R~
    {"s"    ,"s"   ,KTCHAR(s)},                                 //~5506R~
    {"d"    ,"d"   ,KTCHAR(d)},                                 //~5506R~
    {"f"    ,"f"   ,KTCHAR(f)},                                 //~5506R~
    {"g"    ,"g"   ,KTCHAR(g)},                                 //~5506R~
    {"h"    ,"h"   ,KTCHAR(h)},                                 //~5506R~
    {"j"    ,"j"   ,KTCHAR(j)},                                 //~5506R~
    {"k"    ,"k"   ,KTCHAR(k)},                                 //~5506R~
    {"l"    ,"l"   ,KTCHAR(l)},                                 //~5506R~
    {";"    ,";"   ,KTCHAR(SEMICOLON)},                         //~5506R~
    {":"    ,":"   ,KTCHAR(COLON)},                             //~5506R~
    {"]"    ,"]"   ,KTCHAR(RMP)},//right middle parenthesis     //~5506R~
                                                                //~5502I~
//*4th line                                                     //~5502I~
    {"z"    ,"z"   ,KTCHAR(z)},                                 //~5506R~
    {"x"    ,"x"   ,KTCHAR(x)},                                 //~5506R~
    {"c"    ,"c"   ,KTCHAR(c)},                                 //~5506R~
    {"v"    ,"v"   ,KTCHAR(v)},                                 //~5506R~
    {"b"    ,"b"   ,KTCHAR(b)},                                 //~5506R~
    {"n"    ,"n"   ,KTCHAR(n)},                                 //~5506R~
    {"m"    ,"m"   ,KTCHAR(m)},                                 //~5506R~
    {","    ,","   ,KTCHAR(COMMA)},                             //~5506R~
    {"."    ,"."   ,KTCHAR(PERIOD)},                            //~5506R~
    {"/"    ,"/"   ,KTCHAR(SLASH)},                             //~5506R~
    {"\x5c"    ,"\x5c",KTCHAR(BSLASH)},                         //~5506I~
                                                                //~5502I~
    {"10KEY-0"    ,"10KEY-0"   ,KTDEFDUP(P0,KTCTLDUP2)    },    //~5501R~
    {"10KEY-1"    ,"10KEY-1"   ,KTDEFDUP(P1,KTCTLDUP2)    },    //~5501R~
    {"10KEY-2"    ,"10KEY-2"   ,KTDEFDUP(P2,KTCTLDUP2)    },    //~5501R~
    {"10KEY-3"    ,"10KEY-3"   ,KTDEFDUP(P3,KTCTLDUP2)    },    //~5501R~
    {"10KEY-4"    ,"10KEY-4"   ,KTDEFDUP(P4,KTCTLDUP2)    },    //~5501R~
    {"10KEY-5"    ,"10KEY-5"   ,KTDEFNFLG(P5)    },                //~V55cR~
    {"10KEY-6"    ,"10KEY-6"   ,KTDEFDUP(P6,KTCTLDUP2)    },    //~5501R~
    {"10KEY-7"    ,"10KEY-7"   ,KTDEFDUP(P7,KTCTLDUP2)    },    //~5501R~
    {"10KEY-8"    ,"10KEY-8"   ,KTDEFDUP(P8,KTCTLDUP2)    },    //~5501R~
    {"10KEY-9"    ,"10KEY-9"   ,KTDEFDUP(P9,KTCTLDUP2)    },    //~5501R~
    {"10KEY-/"    ,"10KEY-/"   ,KTDEFNFLG(PDIVIDE)},               //~V55cR~
    {"10KEY-*"    ,"10KEY-*"   ,KTDEFNFLG(PMULTIPLY)},             //~V55cR~
    {"10KEY--"    ,"10KEY--"   ,KTDEFNFLG(PMINUS)},                //~V55cR~
    {"10KEY-+"    ,"10KEY-+"   ,KTDEFNFLG(PPLUS) },                //~V55cR~
    {"10KEY-."    ,"10KEY-."   ,KTDEFDUP(PPERIOD,KTCTLDUP2)},   //~5501R~
    {"10KEY-,"    ,"10KEY-,"   ,KTDEFNFLG(PCOMMA)},                //~V55cR~
    {"10KEY-Enter","10キー改行",KTDEF(PENTR),{0,KTSHIFTDUP,0,0}},  //~V55cR~
                                                                //~5216I~
    {"","",{0,0,0,0},{0,0,0,0}}//terminater                        //~V55cR~
};
static  KEYTBL Sfkeytbl101[]=                                      //~V70mR~
{                                                                  //~V70mI~
    {"="    ,"="   ,KTCHAR(EQUAL)},  //0n 101,same as HAT on Japanese kbd//~V69YR~,//~V70mI~
    {"","",{0,0,0,0},{0,0,0,0}} //terminater                       //~V70mR~
};                                                                 //~V70mR~
#ifdef UNX                                                         //~V20CI~
                                                                   //~V20CI~
	static UCHAR Sjpnchar[256]={                                   //~V20CI~
//*Ctrl+@ a b c d e f g h i j k l m n o p q r s t u v w x y z [ \ ] 6 -//~V20CI~
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//x00-1f//~V20CI~
        0};                                                        //~V20CI~
	static UCHAR Sengchar[256]={                                   //~V20CI~
//*Ctrl+@ a b c d e f g h i j k l m n o p q r s t u v w x y z [ \ ] 6 -//~V20CI~
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//x00-1f//~V20CI~
        0};                                                        //~V20CI~
                                                                   //~V20CI~
#else  //!UNX                                                      //~V20CI~
                                                                   //~V20CI~
//*acceptable char definition  1:invalid 0:valid                //~5506I~
static UCHAR Sjpnchar[256]={                                    //~5506I~
//*Ctrl+@ a b c d e f g h i j k l m n o p q r s t u v w x y z [ \ ] 6 -//~5506R~
//      1,0,0,0,0,0,0,0,1,0,1,0,1,1,0,0,0,1,0,1,0,0,0,0,1,0,1,0,0,0,0,0,//x00-1f//~v09VR~
//      1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,//x00-1f//~v0akR~
//      1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,//x00-1f//~v0aoR~
#ifdef AAA                                                         //~va6VI~
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,//x00-1f//~v0aoI~
#else                                                              //~va6VI~
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//x00-1f//~va6VI~
#endif                                                             //~va6VI~
        0};                                                        //~v09QI~
//      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//x20-3f//~v09QR~
//      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//x40-5f//~v09QR~
//      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};//x60-7f//~v09QR~
static UCHAR Sengchar[256]={                                    //~5506I~
//*Ctrl+@ a b c d e f g h i j k l m n o p q r s t u v w x y z [ \ ] 6 -//~5506R~
//      1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,//x00-1f//~v0akR~
//      1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,//x00-1f//~v0aoR~
#ifdef AAA                                                         //~va6VI~
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,//x00-1f//~v0aoI~
#else                                                              //~va6VI~
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//x00-1f//~va6VI~
#endif                                                             //~va6VI~
        0};                                                        //~v09QI~
//      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//x20-3f//~v09QR~
//      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//x40-5f//~v09QR~
//      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};//x60-7f//~v09QR~
#endif //!UNX                                                      //~V20CI~
static FUNCTBL *Spftdown,*Spftright;                            //~5423I~
static UCHAR *Skeyshiftname[]={"","Shift+","Alt+","Ctrl+"};     //~5501R~
static UINT Skeyshiftnamelen[4]={0,6,4,5};                      //~5429I~
#ifdef W32                                                         //~v08jI~
  	#ifndef WXE                                                    //~V500I~
static UINT Sw95consolemode_stdi;   //for restore console mode at entry//~v0h2R~
    #endif //!WXE                                                  //~V500I~
#endif                                                             //~v08jI~
//#ifndef UNX                                                      //~v78NR~
//#ifndef XXE                                                      //~vbr1R~
#ifndef ARMXXE                                                     //~vbr1I~
static  KBDINFO Skbdinfo={10,                   //cb:length        //~v09tM~
                          KEYBOARD_BINARY_MODE,     //fsMask:sysstate//~v09tM~
                          0,                        //chTurnAround //~v09tM~
                          0,                        //fsInterim    //~v09tM~
                          0};                   //fsState:shiftstate//~v09tM~
//#endif //!UNX                                                    //~v78NR~
#endif                                                             //~vbr1I~
static FKCTT Sfkctt;                                               //~v0ijR~
static UCHAR Sfkctindex[256];                                      //~v0ijI~
static UCHAR SfkctindexShift[256];                                 //~vbw0I~
static int   Sshortcutstatus=0;                                    //~V48fR~
#define      KBD_SC_PEND    0x0100                                 //~V48fR~
#define      KBD_SC_QUERY   0x0200  //query pending                //~V48fI~
#define      KBD_SC_SCMASK  0x00ff  //query pending,previous input //~V48fI~
static     FUNCTBL *Spftkeycmd=0;                                  //~V48fI~
//*******************************************************
int kbdfkcedit(PUCLIENTWE Ppcw,int Pindex);                        //~v0ijR~
void kbdfkctmerge(void);                                           //~v0ijI~
int kbdassignchng(PUCLIENTWE Ppcw,int Pextkeysw,KBDKEYINFO *Ppkeyinfo);//~v0ixI~
int kbdscedit(PUCLIENTWE Ppcw,char Psckey);                        //~V48fI~
int kbderrscna(void);                                              //~V48fI~
void kbdinit101(void);                                             //~V70mI~
//#ifdef LNX                                                       //~V69AR~
//	void kbdcvkeyname2euc(void);                                   //~V69AR~
//#endif                                                           //~V69AR~
//**************************************************
//*keyboard init
//*set typamaticrate and functable call
//*rc   :none
//**************************************************
int kbdinit(void)
{
#ifdef UNX                                                         //~v20bR~
  #ifndef XXE                                                      //~V64aI~
	void kbdukbdlintf(int Popt);                                   //~v20bI~
  #endif                                                           //~V64aI~
//#else                                                            //~v78NR~
#endif //!UNX                                                      //~v78NR~
#ifndef XXE                                                        //~v791I~
#ifndef AIX                                                        //~v791I~
    int rc;                                                     //~5104I~
#endif //!AIX                                                      //~v791I~
#endif //!XXE                                                      //~v791I~
//#endif //!UNX                                                    //~v78NR~
//**************************
//#ifdef LNX                                                       //~V69AR~
//    kbdcvkeyname2euc();    //save stdin consolemode at entry     //~V69AR~
//#endif                                                           //~V69AR~
#ifdef W32                                                         //~v08jI~
//  Sw95consolemode=ugetconsolemode();  //save consolemode at entry//~v0h2R~
  #ifndef WXE                                                      //~V500I~
    Sw95consolemode_stdi=ugetconsolemode(0);    //save stdin consolemode at entry//~v0h2I~
  #endif //!WXE                                                    //~V500I~
#endif                                                             //~v08jI~
    Gkeytbl=Sfkeytbl;                                           //~5429I~
    Gkeyshiftname=Skeyshiftname;                                //~5501R~
//  if (!UCBITCHK(Gscrstatus,GSCRSDBCS)                            //~v79zR~
    if (!XE_ISDBCSJ()                                              //~v79zR~
    ||   UCBITCHK(Guerropt,GBL_UERR_FORCEENG))                     //~V70mI~
        kbdinit101();                                              //~V70mI~
                                                                //~5429I~
//  Gkbdspeed=0x0200;   //speed(char/sec)                       //~5705R~
//  Gkbddelay=0x0010;   //delay(milisec)                        //~5705R~
#ifdef UNX                                                         //~v19iR~
  #ifndef XXE                                                      //~V64aI~
	kbdukbdlintf(Gkbdopt);                                         //~v20bI~
  #endif                                                           //~V64aI~
#else //!UNX                                                       //~v19iI~
  if (Gkbdspeed || Gkbddelay)                                      //~v0h5I~
    ukbdsetrate(Gkbddelay,Gkbdspeed);   //ulib                  //~5104R~
#endif //!UNX                                                      //~v198I~
                                                                //~5104I~
//#ifndef XXE                                                      //~v78NR~
#ifndef XXE                                                        //~v791I~
//#ifndef UNX                                                      //~v78NR~
#ifndef AIX                                                        //~v78NR~
    if (UCBITCHK(Gopt,GOPTRCTLENTER))   //use RCTL as enter     //~5104I~
        USBITON(Skbdinfo.fsMask,KEYBOARD_SHIFT_REPORT);         //~5110R~
    if (rc=ukbdsetstatus(&Skbdinfo),rc)                         //~5104R~
//#endif //!UNX                                                    //~v78NR~
#endif //!AIX                                                      //~v78NR~
        if (UCBITCHK(Gopt,GOPTRCTLENTER))   //use RCTL as enter //~5104I~
        {                                                       //~5104I~
            UCBITOFF(Gopt,GOPTRCTLENTER);   //reject use RCTL as enter//~5104I~
    		UCBITON(Gopt4,GOPT4RCTLCMD);    //write to ini to avoid warning each start time//~van9I~
    		funcchngeenter(0);		//restore enter key as executre//~v78NR~
#ifndef LNX //LNX issue errmsg in ukbdsetstatus                    //~v78NR~
            uerrexit("You cannot use Right Ctl as Enter key now",//~5104R~
                     "右Ctl を実行キーとして使えません");       //~5104R~
#endif                                                             //~v78NR~
        }                                                       //~5104I~
#ifndef UNX                                                        //~v198I~
        else                                                    //~5104I~
            uerrexit("You cannot use Ctl+P for char input now", //~5104R~
                     "Ctl+P は入力できません");                 //~5104R~
#endif //!UNX                                                      //~v198I~
//#endif //!XXE                                                    //~v78NR~
#endif //!XXE                                                      //~v791I~
    if (!(Spftdown=functblsrch(FUNCID_DOWN)))                   //~5423I~
        uerrexit("function:Cursor down is not defined",         //~5423I~
//                  "機能:下 が定義されていません");               //~v095R~
                    "機\x94\\:下 が定義されていません");           //~v095I~
                                                                //~5423I~
    if (!(Spftright=functblsrch(FUNCID_RIGHT)))                 //~5423I~
        uerrexit("function:Cursor right is not defined",        //~5423I~
//                  "機能:右 が定義されていません");               //~v095R~
                    "機\x94\\:右 が定義されていません");           //~v095I~
//*mearge ini and tbl from curent functbl                          //~v0ijI~
    kbdfkctmerge();                                                //~v0ijI~
	Spftkeycmd=functblsrch(FUNCID_KEY);	                           //~V48fI~
    if (!Spftkeycmd || !*Spftkeycmd->FTcmd)                        //~V48fI~
    {                                                              //~V48fI~
    	kbderrscna();                                              //~V48fI~
    	Spftkeycmd=0;                                              //~V48fR~
    }                                                              //~V48fI~
#ifdef FTPSUPP                                                     //~v78ZI~
	xetsosetup3270keymap();                                        //~v78ZR~
#endif                                                             //~v78ZI~
    return 0;                                                   //~5104R~
}//kbdinit
//**************************************************               //~V70mI~
//*101 keyboard init                                               //~V70mI~
//*parm :none                                                      //~V70mI~
//*rc   :none                                                      //~V70mI~
//**************************************************               //~V70mI~
void kbdinit101(void)                                              //~V70mI~
{                                                                  //~V70mI~
//***************                                                  //~V70mI~
    KEYTBL *pkt,*pktdup;                                           //~V70mI~
    int idx;                                                       //~V70mI~
//****************                                                 //~V70mI~
    for (pkt=Sfkeytbl101;*(pkt->KTnamee);pkt++)                    //~V70mI~
    {                                                              //~V70mI~
		idx=kbdsrchkt(pkt->KTkey[2],&pktdup);                      //~V70mR~
        if (pktdup && idx==2)	//same value for Alt+              //~V70mI~
        {	                                                       //~V70mI~
        	strcpy(pktdup->KTnamej,pkt->KTnamej);                  //~V70mR~
        	strcpy(pktdup->KTnamee,pkt->KTnamee);                  //~V70mR~
        }                                                          //~V70mI~
    }                                                              //~V70mI~
    return;                                                        //~V70mI~
}//kbdinit101                                                      //~V70mI~
//**************************************************               //~v0ijI~
//*mearge fkct saved on ini file and from functbl                 //~v0ijI~//~vbvvR~
//*parm :none                                                      //~v0ijI~
//*rc   :none                                                      //~v0ijI~
//**************************************************               //~v0ijI~
void kbdfkctmerge(void)                                            //~v0ijI~
{                                                                  //~v0ijI~
    FKCTT  fkcttini;                                               //~v0ijI~
    PFKCTT pfkcttnew;                                              //~v0ijI~
    PFKCT  pfkcti,pfkctn;                                          //~v0ijR~
    int ii,jj;                                                     //~v0ijI~
//*******************                                              //~v0ijI~
    fkcttini=Sfkctt;    //fctt from ini file                       //~v0ijI~
    memset(&Sfkctt,0,sizeof(Sfkctt));                              //~v0ijR~
    if (kbdgetfkct(&pfkcttnew)) //create from functbl              //~v0ijR~
        uerrexit("kbd fkct gen failed",0);                         //~v0ijR~
    for (ii=pfkcttnew->FKCTTentno,pfkctn=pfkcttnew->FKCTTpfkct;ii;ii--,pfkctn++)//~v0ijR~
    {                                                              //~v0ijI~
        if (!UCBITCHK(pfkctn->FKCTflag,FKCTFPFT|FKCTFNONPFK))   //func not ass to pfk//~v0ijI~
        {                                                          //~v0ijI~
            for (jj=fkcttini.FKCTTentno,pfkcti=fkcttini.FKCTTpfkct;jj;jj--,pfkcti++)//~v0ijI~
                if (pfkcti->FKCTkey==pfkctn->FKCTkey               //~v0ijR~
#ifndef KKK                                                        //~vb50I~
                &&  UCBITCHK(pfkcti->FKCTflag,FKCTFSHIFTAC)==UCBITCHK(pfkctn->FKCTflag,FKCTFSHIFTAC)	//S+A,S+C//~vb50I~
#endif                                                             //~vb50I~
                &&  pfkcti->FKCTshift==pfkctn->FKCTshift)   //same key//~v0ijI~
                {                                                  //~v0ijI~
                    UTRACEP("%s:match key and shift key=%04x,shift=%d,keyname=%s,FKCTflag=%02x(init)-%02x(new)\n",//~vb50I~
							UTT,pfkcti->FKCTkey,pfkcti->FKCTshift,(pfkcti->FKCTpkt?pfkcti->FKCTpkt->KTnamee:(UCHAR*)"pkt=NULL"),pfkcti->FKCTflag,pfkctn->FKCTflag);//~vb50R~
                    if (!UCBITCHK(pfkcti->FKCTflag,FKCTFPFT|FKCTFNONPFK))   //func not ass to pfk//~v0ijI~
                    {                                              //~v0ijI~
	                    UTRACEP("%s:!(FKCTFPFT|FKCTFNONPFK) cmdlen(i)=%d=%s,(n)=%d=%s\n",UTT,pfkcti->FKCTcmdlen,pfkcti->FKCTpft_pcmd,pfkctn->FKCTcmdlen,pfkctn->FKCTpft_pcmd);//~vb50R~
                        pfkctn->FKCTcmdlen=pfkcti->FKCTcmdlen;     //~v0ijR~
                        pfkctn->FKCTpft_pcmd=pfkcti->FKCTpft_pcmd;//cmd buff//~v0ijR~
                        pfkcti->FKCTpft_pcmd=0;//copyed avoid next free//~v0ijR~
                    }                                              //~v0ijI~
                    break;                                         //~v0ijI~
                }                                                  //~v0ijI~
                                                                   //~v0ijI~
        }//fkey not assigned                                       //~v0ijI~
    }//new tbl                                                     //~v0ijI~
//free old from ini                                                //~v0ijI~
    for (jj=fkcttini.FKCTTentno,pfkcti=fkcttini.FKCTTpfkct;jj;jj--,pfkcti++)//~v0ijI~
        if (!UCBITCHK(pfkcti->FKCTflag,FKCTFPFT|FKCTFNONPFK))   //func not ass to pfk//~v0ijI~
            if (pfkcti->FKCTpft_pcmd)                              //~v0ijI~
                ufree (pfkcti->FKCTpft_pcmd);//copyed avoid next free//~v0ijR~
    if (fkcttini.FKCTTpfkct)                                       //~v0ijR~
        ufree (fkcttini.FKCTTpfkct);                               //~v0ijI~
//setup ext key tbl                                                //~v0ijI~
    kbdsetfkcmd();                                                 //~v0ijI~
    return;                                                        //~v0ijI~
}//kbdfkctmerge                                                    //~v0ijI~
//**************************************************               //~v0ijI~
//*set to ext key tbl from cmd tbl                                 //~v0ijI~
//*parm :none                                                      //~v0ijI~
//*rc   :none                                                      //~v0ijI~
//**************************************************               //~v0ijI~
void kbdsetfkcmd(void)                                             //~v0ijI~
{                                                                  //~v0ijI~
    PFKCT  pfkct;                                                  //~v0ijI~
    int ii;                                                        //~v0ijI~
//*******************                                              //~v0ijI~
    memset(Sfkctindex,0,sizeof(Sfkctindex));                       //~v0ijI~
    memset(SfkctindexShift,0,sizeof(SfkctindexShift));             //~vbw0I~
    for (ii=0,pfkct=Sfkctt.FKCTTpfkct;ii<Sfkctt.FKCTTentno;ii++,pfkct++)//~v0ijR~
    {                                                              //~vbw0I~
        UTRACEP("%s:FKCTkey=x%x,FKCTflag=x%x\n",UTT,pfkct->FKCTkey,pfkct->FKCTflag);//~vbw0R~
        if (!UCBITCHK(pfkct->FKCTflag,FKCTFPFT|FKCTFNONPFK) //func not ass to pfk//~v0ijI~
        &&  pfkct->FKCTpft_pcmd)                                   //~v0ijI~
        {                                                          //~vbw0I~
          if (UCBITCHK(pfkct->FKCTflag,FKCTFSHIFTAC))             //S+A or S+C//~vbw0I~
          {                                                        //~vbw0I~
            SfkctindexShift[(int)(pfkct->FKCTkey>>8)]=(UCHAR)(ii+1); //PFn+//~vbw0I~
            UTRACEP("%s:shift ii=%d,FKCTkey=x%x,FKCTpft_pcmd=%s\n",UTT,ii,pfkct->FKCTkey,pfkct->FKCTpft_pcmd);//~vbw0I~
          }                                                        //~vbw0I~
          else                                                     //~vbw0I~
          {                                                        //~vbw0I~
            Sfkctindex[(int)(pfkct->FKCTkey>>8)]=(UCHAR)(ii+1); //avoid 0//~v0ijR~
            UTRACEP("%s:Not shift ii=%d,FKCTkey=x%x,FKCTpft_pcmd=%s\n",UTT,ii,pfkct->FKCTkey,pfkct->FKCTpft_pcmd);//~vbw0I~
          }                                                        //~vbw0I~
        }                                                          //~vbw0I~
    }                                                              //~vbw0I~
}//kbdsetfkcmd                                                     //~v0ijI~
//**************************************************               //~vbw0I~
int getIndexPFkeyCmd(PKBDKEYINFO Pkeyinf)                          //~vbw0R~
{                                                                  //~vbw0I~
	int idx;                                                       //~vbw0I~
	if (Pkeyinf->fsState & (KBDSTF_RIGHTSHIFT | KBDSTF_LEFTSHIFT))//  0x0003//~vbw0R~
		idx=(int)SfkctindexShift[Pkeyinf->chScan];                 //+vbw0R~
    else                                                           //~vbw0I~
		idx=(int)Sfkctindex[Pkeyinf->chScan];                      //~vbw0R~
    UTRACEP("%s:rc=%d,scan=x%x,fsState=x%x\n",UTT,idx,Pkeyinf->chScan,Pkeyinf->fsState);//~vbw0R~
    return idx;                                                    //~vbw0I~
}                                                                  //~vbw0I~
//**************************************************               //~v09tI~
//*keyboard re-init after child shell                              //~v09tI~
//*re-init kbd mode                                                //~v09tI~
//*rc   :0                                                         //~v09tI~
//**************************************************               //~v09tI~
int kbdreinit(void)                                                //~v09tI~
{                                                                  //~v09tI~
//**************************                                       //~v09tI~
//#ifdef UNX                                                       //~v78NR~
#ifdef AIX                                                         //~v78NR~
    return 0;                                                      //~v198I~
#else //!UNX                                                       //~v198I~
  #ifdef ARMXXE                                                    //~va90I~
    return 0;                                                      //~va90I~
  #else                                                            //~va90I~
    return ukbdsetstatus(&Skbdinfo);                               //~v09tI~
  #endif //ARMXXE                                                  //~va90I~
#endif //!UNX                                                      //~v198I~
}//kbdreinit                                                       //~v09tI~
                                                                   //~v09tI~
//**************************************************            //~v01aI~
//!keyboard term                                                //~v01aI~
//*set kbd rate at exit parm value                              //~v01aI~
//*rc   :none                                                   //~v01aI~
//**************************************************            //~v01aI~
int kbdterm(void)                                               //~v01aI~
{                                                               //~v01aI~
    PFKCT pfkct;                                                   //~v0ihI~
    PSCKT psckt;                                                   //~V48fI~
    int ii,cmdlen;                                                 //~V48fR~
//**************************                                    //~v01aI~
#ifdef UNX                                                         //~v19iR~
  #ifndef XXE                                                      //~V64aI~
    ukbdl_term();                                                  //~v19iI~
  #endif                                                           //~V64aI~
#else //!UNX                                                       //~v19iI~
  if (Gkbdspeed2 || Gkbddelay2)                                    //~v0h5I~
    ukbdsetrate(Gkbddelay2,Gkbdspeed2);                         //~v01aI~
#endif //!UNX                                                      //~v198I~
#ifdef W32                                                         //~v08jI~
//  usetconsolemode(Sw95consolemode);   //recover consolemode at entry//~v0h2R~
  #ifndef WXE                                                      //~V500I~
    usetconsolemode(0,Sw95consolemode_stdi);    //recover consolemode at entry//~v0h2I~
  #endif //!WXE                                                    //~V500I~
#endif                                                             //~v08jI~
    if (Sfkctt.FKCTTpfkct)                                         //~v0ijR~
    {                                                              //~v0ihI~
        pfkct=Sfkctt.FKCTTpfkct;                                   //~v0ijR~
        for (ii=0;ii<Sfkctt.FKCTTentno;ii++,pfkct++)               //~v0ijR~
            if (!UCBITCHK(pfkct->FKCTflag,FKCTFPFT|FKCTFNONPFK))    //fkey not assigned//~v0ijR~
                if (pfkct->FKCTpft_pcmd)        //for read err case//~v0ijR~
                    ufree(pfkct->FKCTpft_pcmd);                    //~v0ijR~
        ufree(Sfkctt.FKCTTpfkct);                                  //~v0ijR~
        memset(&Sfkctt,0,sizeof(Sfkctt));                          //~v0ijR~
    }                                                              //~v0ihI~
    for (ii=0,psckt=Gkbdsckt;ii<SCKTMAXNO;ii++,psckt++)            //~V48fI~
    {                                                              //~V48fI~
       	if (cmdlen=psckt->SCKTcmdlen,cmdlen)                       //~V48fI~
        {                                                          //~V48fI~
        	ufree(psckt->SCKTcmd);                                 //~V48fI~
        	psckt->SCKTcmd=0;                                      //~V48fI~
            psckt->SCKTcmdlen=0;                                   //~V48fI~
        }                                                          //~V48fI~
    }                                                              //~V48fI~
    file7term();    //free ALCT                                    //~V67CI~
    return 0;                                                   //~v01aI~
}//kbdterm                                                      //~v01aI~
                                                                //~v01aI~
//**************************************************
//*get keyboard input and call key function
//*rc   :rc from key function(-1 for quit)
//**************************************************
//scancode/charcode 
//      xx/yy:scan code/char code
//      00/yy:katakana,zenkaku                                     //~vbrkR~
//      xx/00:psude scancode
//      xx/e0:psude scancode
int kbdproc(void)
{
//**********************
    int rc;                                                     //~5110R~
    int keytype;
    KBDKEYINFO keyinf,keyinf2;
//#ifdef UTf8SUPPH                                                   //~vva1cI~//~vaf8R~
#ifdef UTF8SUPPH                                                   //~vva1cI~//~vaf8I~
//  UCHAR inputc[MAX_MBCSLENLC+1];                                 //~vva1cI~//~va1cR~//~vbr5R~
    UCHAR inputc[MAXSTRINPUT+1];                                 //~vva1cI~//~vbr5I~
#else                                                              //~vva1cI~//~va1cR~
    UCHAR inputc[3];
#endif                                                             //~vva1cI~//~va1cR~
    PUCLIENTWE pcw;
    int index;                                                     //~v0ijI~
    int cmdwoenter=0;                                              //~v0ijI~
    int keyasssw;       //on key assign change scr                 //~v0ixI~
    int shortcutmodesw;       //on key assign change scr           //~V48fI~
#ifdef WXE                                                         //~V500I~
    int wxekbdrc;                                                  //~V500I~
#endif                                                             //~V500I~
    int callbyfuncid=0;                                            //~V768I~
#ifdef FTPSUPP                                                     //~v78ZI~
    int idx3270key,internalright=0,rctlsw=0;                       //~v78ZR~
#endif                                                             //~v78ZI~
//*********************
//#ifdef UTf8SUPPH                                                   //~vva1cI~//~vaf8R~
#ifdef UTF8SUPPH                                                   //~vva1cI~//~vaf8I~
//  inputc[MAX_MBCSLENLC]=0;                                       //~vva1cI~//~va1cR~//~vbr5R~
    memset(inputc,0,sizeof(inputc));                               //~vbr5R~
    keyinf.bNlsShift=0;  //for getnextgc                           //~va1cR~
#else                                                              //~vva1cI~//~va1cR~
    inputc[2]=0;
#endif                                                             //~vva1cI~//~va1cR~
    keyinf.fsState=0;   //shift key status,also for the case grph char//~V77xI~

    pcw=scrgetcw(0);        //get current client                   //~v0ijI~
    if (!pcw)                                                      //~v0ijI~
    {                                                              //~vaxaI~
#ifndef ARM                                                        //~vbrkI~
        uerrexit("kbdproc:internal logic err,No work exits",0);    //~v0ijI~
#endif                                                             //~vbrkI~
#ifdef ARM                                                         //~vaxaI~
        return -1;                                                 //~vaxaI~
#endif                                                             //~vaxaI~
    }                                                              //~vaxaI~
    UCBITOFF(pcw->UCWflag3,UCWF3HEXKBDGC); 	//grapth char input by HEX notation//~v79RR~
    if (*Gcmdbuff)
    {                                                              //~vbkmI~
        keytype=UCWKTCMD;       //call func_cmd                 //~5225R~
	    inputc[0]=0;                                               //~vbkmI~
	    inputc[1]=0;                                               //~vbkmI~
    }                                                              //~vbkmI~
    else
    {
        if (UCBITCHK(Gprocstatus,GPROCSCSRDOWN|GPROCSCSRRIGHT)) //~5423I~
                {                                                       //~5423I~
//                  keyinf.fsState=0;   //shift key status         //~V77xR~
            keytype=UCWKTEXTKEY;                                //~5423I~
            inputc[1]=0;                                        //~5423I~
            if (UCBITCHK(Gprocstatus,GPROCSCSRDOWN))            //~5423R~
                inputc[0]=(UCHAR)(Spftdown->FTkey[0]>>8);       //~5423R~
            else                                                //~5423R~
                inputc[0]=(UCHAR)(Spftright->FTkey[0]>>8);      //~5423R~
            UCBITOFF(Gprocstatus,GPROCSCSRDOWN|GPROCSCSRRIGHT); //~5423I~
#ifdef FTPSUPP                                                     //~v78ZI~
    		internalright=1;                                       //~v78ZI~
#endif                                                             //~v78ZI~
            UTRACEP("xekbd csrright inputc=%c\n",inputc[0]);       //~van6I~
        }                                                       //~5423I~
        else                                                    //~5423I~
        {                                                       //~5423I~
            UTRACEP("%s:before clear UCWF2UTF8STR Gstrinputlen=%d,UCWflag2=x%x\n",UTT,Gstrinputlen,pcw->UCWflag2);//~vbt4R~//~vbv8R~
            UCBITOFF(pcw->UCWflag2,UCWF2UTF8STR);                  //~vbv8I~
         if (Gstrinputlen)                                         //~V705I~
         {                                                         //~V705I~
//         	keytype=funct2getnextinputgc(inputc);                  //~V705R~//~v79RR~
#ifdef UTF8SUPPH                                                   //~va1cR~
           	keytype=funct2getnextinputgc(pcw,inputc,&keyinf);	//get nls status for GB18030//~va1cR~
#else                                                              //~va1cR~
           	keytype=funct2getnextinputgc(pcw,inputc);              //~v79RI~
#endif                                                             //~va1cR~
            UTRACEP("%s:after funct2getnextinputgc UCWflag2=x%x,UCWkeydata_utf8str=%s\n",UTT,pcw->UCWflag2,pcw->UCWkeydata_utf8str);//~vbt4R~
         }//not string input                                       //~V705I~
         else                                                      //~V705I~
         {                                                         //~V705I~
            for (;;)                                            //~5423R~
            {                                                   //~5423R~
#ifdef XXE                                                         //~V64aI~
                if (!wxe_readkbd(&keyinf,IO_WAIT))	//exauted input event//~V64aR~
              		return XEKBD_RC_MORE;           //wait next kbd event//~V64aI~
#else                                                              //~V64aI~
#ifdef WXE                                                         //~V500I~
    		  wxekbdrc=                                            //~V500I~
#endif                                                             //~V500I~
                ukbdcharin(&keyinf,IO_WAIT);                    //~5423R~
#ifdef LNX                                                         //~V53mI~
  #ifndef XXE                                                      //~V64aI~
                if (keyinf.chScan==UKLM_MOUSEID)                   //~V53mI~
                {                                                  //~V53mI~
                    if (mousel_btnproc(&keyinf))	//continue process?//~V53mI~
                    	break;                                     //~V53mI~
                    else                                           //~V55SI~
                        continue;//bypass R-Ctrl chk logic         //~V55SI~
                }                                                  //~V53mI~
  #endif                                                           //~V64aI~
#endif                                                             //~V53mI~
#ifdef WXE                                                         //~V500I~
    		  if (!wxekbdrc)                                       //~V500I~
              	return XEKBD_RC_MORE;                              //~V500I~
#endif                                                             //~V500I~
#ifdef W32                                                         //~v142R~
  #ifndef WXE	//not required for WXE anymore                     //~V500I~
                if (keyinf.chChar==0x0a && keyinf.chScan==0x1c) //0x000d//~v142R~
                    if (!(keyinf.fsState & KBDSTF_CONTROL))        //~v142R~
                    {                                              //~v142R~
                        UTRACED("ukbdcharin2",&keyinf,sizeof(keyinf));//~v142R~
//                      ukbd_w95traceinit(KBD_UTRACE);             //~v142R~
                        continue;                                  //~v142R~
//                      ubell();                                   //~v142R~
                    }                                              //~v142R~
  #endif //!WXE                                                    //~V500I~
#endif                                                             //~v142R~
#endif //!XXE                                                      //~V64aI~
                if (!UCBITCHK(Gopt,GOPTRCTLENTER))  //use RCTL as enter//~5423R~
                    break;                                      //~5423R~
                if (!UCBITCHK(keyinf.fbStatus,KBDTRF_SHIFT_KEY_IN)) //shift report//~5423R~
                    break;                                      //~5423R~
                if (USBITCHK(keyinf.fsState,KBDSTF_RIGHTCONTROL))   //shift report//~5423R~
                {                                               //~5423R~
//                	if (Gotheropt & GOTHERO_RCTLNL)   //Rctl:NewLine,Enter:Execute//~v790R~
//                	if (Gotheropt & (GOTHERO_RCTLNL|GOTHERO_CLRCTLNL))   //Rctl:NewLine,Enter:Execute//~v793R~
                  	if (Gotheropt & GOTHERO_RCTLNL)   //Rctl:NewLine,Enter:Execute//~v793I~
                    {                                              //~v78ZI~
                    	callbyfuncid=FUNCID_NEXTLINE;              //~V768R~
#ifdef FTPSUPP                                                     //~v78ZI~
                        rctlsw=TI3KO_RCTLNEWLINE;      //rctl is nextline//~v78ZR~
#endif                                                             //~v78ZI~
                    }                                              //~v78ZI~
#ifdef FTPSUPP                                                     //~v78ZI~
                    else                                           //~v78ZI~
                        rctlsw=TI3KO_RCTLENTER;      //rctl is nextline//~v78ZI~
#endif                                                             //~v78ZI~
//                  *((USHORT*)(PVOID)(&keyinf.chChar))=KEY_PENTR;// 0xe00d force execute//~5423R~//~van6R~
//  		        keyinf.chChar=KEY_ENTER&0xff;// 0xe00d force execute//~vaq3R~
//  	    		keyinf.chScan=KEY_ENTER>>8;  // 0xe00d force execute//~vaq3R~
    		        keyinf.chChar=KEY_PENTR&0xff;// 0xe00d force execute//~vaq3I~
    	    		keyinf.chScan=KEY_PENTR>>8;  // 0xe00d force execute//~vaq3I~
                    break;                                      //~5423R~
                }                                               //~5423R~
            }                                                   //~5610R~
            UTRACED("ukbdcharin",&keyinf,sizeof(keyinf));       //~5423R~
            if (keyinf.chChar==0x0d && keyinf.chScan==0)    //0x000d//~v096R~
            {                                                      //~van6I~
//              *((USHORT*)(PVOID)(&keyinf.chChar))=KEY_ENTER;// 0xe00d force execute//~v096R~//~van6R~
		        keyinf.chChar=KEY_ENTER&0xff;// 0xe00d force execute//~van6I~
        		keyinf.chScan=KEY_ENTER>>8;  // 0xe00d force execute//~van6I~
            }                                                      //~van6I~
            Gkbdinpctr++;   //v011:for duplicate ESC chk        //~5610I~
#ifdef UNX                                                         //~V404R~
#else                                                              //~V404R~
            if (!keyinf.chChar && !keyinf.chScan)   //break     //~v03rI~
                uerrexit("Break Key accepted",                  //~v03rI~
                        "ブレーク キー");                       //~v03rI~
#endif                                                             //~V404R~
//conv e00d(PENTR) to 0c00.(xefunc registered so(extended key 0c00)//~V64aR~
//1c0d(ENTER) is regsiter by char func key and may shift to exec and crlf by rctlkey option//~V64aI~
            if (keyinf.chScan==KEY_PENTRID)                     //~5423R~
            {                                                   //~5423R~
                if (keyinf.chChar!=(KEY_PDIVIDE_CHK&255))//it char//~5501I~
                {                                               //~5501I~
                    keyinf.chScan=keyinf.chChar;                //~5501R~
                    keyinf.chChar=0;            //trate as ext key//~5501R~
                }                                               //~5501I~
            }                                                   //~5423R~
            keyasssw=0;                                            //~v0ixI~
    		shortcutmodesw=(Sshortcutstatus & KBD_SC_PEND);        //~V48fI~
    		Sshortcutstatus&=~KBD_SC_PEND; 		//reset after a key//~V48fI~
#ifdef LNX                                                         //~V53mI~
  #ifndef XXE                                                      //~V64aI~
          if (keyinf.chScan==UKLM_MOUSEID)                         //~V53mI~
          {                                                        //~V53mI~
                keytype=UCWKTMOUSE;                                //~V53mI~
                inputc[0]=keyinf.chMouseposx;    //column          //~V53mI~
                inputc[1]=keyinf.chMouseposy;    //row             //~V53mI~
                inputc[2]=keyinf.chChar;         //button status   //~V53mI~
          }                                                        //~V53mI~
          else//not mouse                                          //~V53mI~
          {   //not mouse                                          //~V53mI~
  #endif                                                           //~V64aI~
#endif                                                             //~V53mI~
            if (pcw->UCWmenuopt==PANMOPARMFK_FKEY)                 //~v0jaR~
                if (CSRONFILEDATA(pcw))                            //~v0ixR~
                    keyasssw=1;                                    //~v0ixI~
//          if (keyinf.chChar==0x00 || keyinf.chChar==0xe0) //0x00 or 0xE0//~5423R~//~v7aaR~
            if (keyinf.chChar==0x00                                //~v7aaI~
            ||  (keyinf.chChar==0xe0 && keyinf.chScan!=0)          //~v7aaI~
            )   //0x00 or 0xE0                                     //~v7aaI~
            {                                                   //~5423R~
                if (keyasssw)                                      //~v0ixI~
                    if ((rc=kbdassignchng(pcw,1,&keyinf))>=0)   //updated line//~v0ixR~
                        return rc;                      //re call kbdproc from xe.c after draw//~v0ixI~
//              if (index=(int)Sfkctindex[keyinf.chScan],index)    //~v0ijR~//~vbw0R~
                if (index=getIndexPFkeyCmd(&keyinf),index)         //~vbw0R~
                {                                                  //~v0ijI~
                    rc=kbdfkcedit(pcw,index-1);                    //~v0ijR~
                    if (rc==UALLOC_FAILED)                         //~v0ijI~
                        return rc;                                 //~v0ijI~
                }                                                  //~v0ijI~
                else                                               //~v0ijI~
                    rc=-1;                                         //~v0ijI~
              if (rc>=0)    //no err                               //~v0ijR~
              {                                                    //~v0ijI~
                cmdwoenter=!rc;         //set only                 //~v0ijR~
                keytype=UCWKTCMD;       //call func_cmd            //~v0ijM~
              }                                                    //~v0ijI~
              else                                                 //~v0ijI~
              {                                                    //~v0ijI~
                keytype=UCWKTEXTKEY;                            //~5423R~
                inputc[0]=keyinf.chScan;    //psude code        //~5423R~
                inputc[1]=0;                                    //~5423R~
              }                                                    //~v0ijI~
            }                                                   //~5423R~
            else                                                //~5423R~
            {                                                   //~5423R~
                keytype=UCWKTSBCS;                              //~5423R~
                inputc[0]=keyinf.chChar;    //char code         //~5423R~
                inputc[1]=keyinf.chScan;    //scan code         //~5423R~
#ifdef UTF8SUPPH                                                   //~va00I~
#ifdef WCSUPP                                                      //~va00I~
                if (keyinf.bNlsShift & (KBDNLS_F2L_DBCS1ST|KBDNLS_F2L_SBCS))	//utf8 str was set//~va00I~
                {                                                  //~va00I~
                	memcpy(pcw->UCWkeydata_utf8str,keyinf.u8str,sizeof(pcw->UCWkeydata_utf8str));//~va00R~
                    UCBITON(pcw->UCWflag2,UCWF2UTF8STR);           //~va00I~
                }                                                  //~va00I~
                else                                               //~va00I~
                    UCBITOFF(pcw->UCWflag2,UCWF2UTF8STR);          //~va00I~
                UTRACEP("%s:UCWflag2=x%x,UCWkeydata_utf8str=%s\n",UTT,pcw->UCWflag2,pcw->UCWkeydata_utf8str);
#endif                                                             //~va00I~
#endif                                                             //~va00I~
                if (!keyinf.chScan) //katakana,zenkaku             //~V768R~
                {                                               //~5423R~
#ifdef WCSUPP                                                      //~v8@ZI~
#ifdef AAA                                                         //~vbt4I~
				  if (Gotherstatus & GOTHERS_NOUTF8     //no utf8 option under utf env//~v7a5I~
                  &&  keyinf.chChar>=0x80)	//not ascii            //~v7a5I~
					UCBITON(pcw->UCWflag3,UCWF3HEXKBDGC); 	//grapth char input by HEX notation//~v7a5I~
                  else                                             //~v7a5I~
#endif //AAA                                                       //~vbt4I~
#ifdef UTF8SUPPH                                                   //~vva1cI~//~va1cR~
		          if (keyinf.bNlsShift & (KBDNLS_DBCS|KBDNLS_F2L_DBCS1ST))//dbcs or f2l dbcsno need to chk lead byte//~vva1cR~//~va1cR~
#else                                                              //~vva1cI~//~va1cR~
		          if (keyinf.bNlsShift & KBDNLS_F2L_DBCS1ST)//no need to chk lead byte//~v8@ZI~
#endif                                                             //~vva1cI~//~va1cR~
                  {                                                //~v8@ZI~
                        keytype=UCWKTDBCS;                         //~v8@ZI~
#ifdef UTF8SUPPH                                                   //~vva1cR~//~va1cR~
                   if (keyinf.bNlsShift & KBDNLS_F2L_DBCS2ND)//f2l 2 byte dbcs//~vva1cR~//~va1cR~
                    	inputc[1]=keyinf.mbstr[1];	//2nd byte     //~vva1cR~//~va1cR~
                   else                                            //~vva1cI~//~va1cR~
                   if (keyinf.bNlsShift & KBDNLS_SS3)//no need to chk lead byte//~vva1cI~//~va1cR~
                   		UmemcpyZ(inputc+1,keyinf.mbstr+1,2);       //~vva1cR~//~va1cR~
                   else                                            //~vva1cI~//~va1cR~
                   if (keyinf.bNlsShift & KBDNLS_GB4)//no need to chk lead byte//~vva1cI~//~va1cR~
                   		UmemcpyZ(inputc+1,keyinf.mbstr+1,3);       //~vva1cR~//~va1cR~
                   else                                            //~vva1cI~//~va1cR~
                   if (keyinf.bNlsShift & KBDNLS_DBCS)//locale 2 byte dbcs//~vva1cI~//~va1cR~
                    	inputc[1]=keyinf.mbstr[1];	//2nd byte     //~vva1cI~//~va1cR~
                   else                                            //~vva1cI~//~va1cR~
#endif                                                             //~vva1cI~//~va1cR~
                   {                                               //~vva1cI~//~va1cR~
#ifdef XXE                                                         //~v8@ZI~
                	if (!wxe_readkbd(&keyinf2,IO_WAIT))	//exauted input event//~v8@ZI~
              			return XEKBD_RC_MORE;           //wait next kbd event//~v8@ZI~
#else                                                              //~v8@ZI~
                    ukbdcharin(&keyinf2,IO_WAIT);                  //~v8@ZI~
#endif                                                             //~v8@ZI~
                    UTRACED("ukbdcharin MBDBCS",&keyinf2,sizeof(keyinf2));//~v8@ZI~
                    inputc[1]=keyinf2.chChar;       //2ndbyte      //~v8@ZI~
                   }                                               //~vva1cI~//~va1cR~
                    UTRACED("input DBCS",inputc,5);                //~vva1cR~//~va1cR~
                  }                                                //~v8@ZI~
                  else                                             //~v8@ZI~
                  {                                                //~v8@ZI~
#endif                                                             //~v8@ZI~
//                  if (udbcschk(keyinf.chChar))            //DBCS //~V777R~
#ifdef WXE                                                         //~va3DI~
        			if (UDBCSCHK_ISDBCS1ST(keyinf.chChar))	//same chk as wxexei//~va3DI~
#else                                                              //~va3DI~
                    if (udbcschk_hk(0,keyinf.chChar))  //DBCS dbcs or EUC-hankaku katakana//~V777I~
#endif                                                             //~va3DI~
                    {                                           //~5423R~
                        keytype=UCWKTDBCS;                      //~5423R~
#ifdef XXE                                                         //~V64aI~
                		if (!wxe_readkbd(&keyinf2,IO_WAIT))	//exauted input event//~V64aI~
              				return XEKBD_RC_MORE;           //wait next kbd event//~V64aI~
#else                                                              //~V64aI~
                        ukbdcharin(&keyinf2,IO_WAIT);           //~5423R~
#endif                                                             //~V64aI~
                        UTRACED("ukbdcharin DBCS",&keyinf2,sizeof(keyinf2));//~5423R~
                        inputc[1]=keyinf2.chChar;       //2ndbyte//~5423R~
                    }                                           //~5423R~
#ifdef WCSUPP                                                      //~v8@ZI~
                  }//unicode->mbsDBCS ?                            //~v8@ZI~
#endif                                                             //~v8@ZI~
                }                                               //~5423R~
#ifdef UNX                                                         //~V48hI~
                if (keytype==UCWKTSBCS)//dbcs chk failed           //~V48hI~
#else                                                              //~V48hI~
                else        //sbcs                                 //~v0ixI~
#endif                                                             //~V48hI~
                {                                                  //~V48fI~
                    if (keyasssw)                                  //~v0ixI~
                        if ((rc=kbdassignchng(pcw,0,&keyinf))>=0)   //updated line//~v0ixR~
                            return rc;                      //re call kbdproc from xe.c after draw//~v0ixI~
                    if (shortcutmodesw)                            //~V48fI~
                    {                                              //~V48fI~
                        rc=kbdscedit(pcw,*inputc);                 //~V48fR~
                        if (rc<0)                                  //~V48fR~
                        	return 4;      //not defined shortcut  //~V48fR~
                		cmdwoenter=!rc;         //set only         //~V48fI~
		                keytype=UCWKTCMD;       //call func_cmd    //~V48fI~
                    }                                              //~V48fI~
                }                                                  //~V48fI~
            }//char code                                        //~5423R~
#ifdef LNX                                                         //~V53mI~
  #ifndef XXE                                                      //~V64aI~
          }//not mouse                                             //~V53mI~
  #endif                                                           //~V64aI~
#endif                                                             //~V53mI~
         }//not string input                                       //~V705I~
        }//key move after draw                                  //~5423I~
    }//cmd or kbd

//  pcw=scrgetcw(0);        //get current client                   //~v0ijR~
//  if (!pcw)                                                      //~v0ijR~
//      uerrexit("kbdproc:internal logic err,No work exits",0);    //~v0ijR~

//  pcw->UCWrcsrx   =Gcsrposx-pcw->UCWorgx; //relative pos-x    //~5128R~
//  pcw->UCWrcsry   =Gcsrposy-pcw->UCWorgy; //relative pos-x    //~5128R~

    pcw->UCWkeyshift=keyinf.fsState;    //shift key status
#ifdef UTF8SUPPH                                                   //~vva1cI~//~va1cR~
    pcw->UCWnls=keyinf.bNlsShift;  //nls info                      //~vva1cI~//~va1cR~
#endif                                                             //~vva1cI~//~va1cR~

//printf("inputc=%x-%x\n",inputc[0],inputc[1]);                    //~V64aR~
  if (cmdwoenter)   //set only                                     //~v0ijI~
    rc=0;                                                          //~v0ijI~
  else                                                             //~v0ijI~
  {                                                                //~V768I~
  	if (callbyfuncid)                                              //~V768I~
    {                                                              //~V768I~
    	inputc[2]=(UCHAR)callbyfuncid;                             //~V768R~
        keytype=UCWKTFUNCID;                                       //~V768I~
    }                                                              //~V768I~
#ifdef FTPSUPP                                                     //~v78ZI~
    if (UCBITCHK(pcw->UCWflag3,UCWF33270KBD))	//hotkey ON        //~v78ZI~
    {                                                              //~v78ZI~
    	if (!internalright)                                        //~v78ZI~
            if (idx3270key=xetsois3270key(rctlsw,pcw,keytype,inputc),idx3270key) //key assigned to 3270kbd//~v78ZR~
            {                                                      //~v78ZR~
                if (idx3270key<0) //invalid for emulation mode     //~v8@ZI~
                {                                                  //~v8@ZI~
                    ubell();                                       //~v8@ZR~
                	return 4;                                      //~v8@ZI~
                }                                                  //~v8@ZI~
                keytype=UCWKT3270KBD;                              //~v78ZR~
//              inputc[2]=idx3270key; //parmt funccall             //~vaz8R~
                inputc[2]=(UCHAR)idx3270key; //parmt funccall      //~vaz8I~
            }                                                      //~v78ZR~
    }                                                              //~v78ZI~
#endif                                                             //~v78ZI~
UTRACEPF2("%s:funccall keytype=%d,key=%02x%02x\n",UTT,keytype,inputc[0],inputc[1]);//write to both .trc and .trc_kbd //~v79RI~//~vbkmR~
    rc=funccall(keytype,inputc,pcw);
  }                                                                //~V768I~

    return rc;
}//kbdproc
#ifndef XXE	//wait by "read" shellcmd                              //~va70I~
#ifndef WXE                                                        //~V58qR~
//*************************************************                //~V58qI~
//*wait until specified key input                                  //~V58qI~
//*return scan+char read                                           //~V58qI~
//*************************************************                //~V58qI~
int kbdwaitkey(int Pscanchar)                                      //~V58qR~
{                                                                  //~V58qI~
    KBDKEYINFO keyinf;                                             //~V58qI~
	int scanchar;                                                  //~V58qI~
//**************************                                       //~V58qI~
#ifdef W32                                                         //~V58qI~
//    for (;;)                                                     //~V58qR~
//    {                                                            //~V58qR~
//        scanchar=ukbdcharin(&keyinf,IO_NOWAIT);//read and ignore //~V58qR~
//UTRACEP("rc=%x\n",scanchar);                                     //~V58qR~
//UTRACED("waitkey peek",&keyinf,sizeof(keyinf));                  //~V58qR~
//        if (!scanchar)                                           //~V58qR~
//            break;                                               //~V58qR~
//    }                                                            //~V58qR~
#endif                                                             //~V58qI~
	for (;;)                                                       //~V58qI~
    {                                                              //~V58qI~
    	ukbdcharin(&keyinf,IO_WAIT);  //request new input          //~V58qR~
        scanchar=(int)(((UINT)(keyinf.chScan)<<8)+keyinf.chChar);  //~V58qR~
UTRACEP("scanchar=%x\n",scanchar);                                 //~V58qR~
UTRACED("ukbwaitkey2",&keyinf,sizeof(keyinf));                     //~V58qI~
        if (!Pscanchar) 	//wait anykey                          //~V58qI~
        {                                                          //~V58qI~
#ifdef W32                                                         //~V58qI~
        	if (scanchar==0x1c0a)	//win generate 1c0a after 1c0d //~V58qI~
        		if (!(keyinf.fsState & KBDSTF_CONTROL))            //~V58qI~
            	{                                                  //~V58qI~
            		UTRACED("ukbwaitkey2:continue",&keyinf,sizeof(keyinf));//~V58qR~
                	continue;                                      //~V58qI~
            	}                                                  //~V58qI~
#endif                                                             //~V58qI~
            if (scanchar & 255) //char !=0 :char key               //~V58qI~
        		break;                                             //~V58qR~
        }                                                          //~V58qI~
        if (scanchar==Pscanchar)                                   //~V58qI~
        	break;                                                 //~V58qI~
	}                                                              //~V58qI~
    return scanchar;                                               //~V58qI~
}//kbdwaitkey                                                      //~V58qR~
#endif	//!WXE                                                     //~V58qR~
#endif	//!XXE                                                     //~va70I~
//**************************************************************** //~v0ixI~
//* edit func key cmd                                              //~v0ixI~
//* parm1 :pcw                                                     //~v0ixI~
//* parm2 :extend key sw(1:ext key,0:char key)                     //~v0ixR~
//* parm3 :key inf addr                                            //~v0ixI~
//* retrn :-1:not avail for key assign 0:file updated 4:file update err//~v0ixI~
//**************************************************************** //~v0ixI~
int kbdassignchng(PUCLIENTWE Ppcw,int Pextkeysw,KBDKEYINFO *Ppkeyinfo)//~v0ixR~
{                                                                  //~v0ixI~
    USHORT   key;                                                  //~v0ixI~
    int shiftkey;                                                  //~v0ixR~
    int rc;                                                        //~v0ixI~
//********************                                             //~v0ixI~
    if (Pextkeysw)                                                 //~v0ixI~
        key=(USHORT)(Ppkeyinfo->chScan<<8);                        //~v0ixR~
    else                                                           //~v0ixI~
        key=(USHORT)((Ppkeyinfo->chScan<<8)|(Ppkeyinfo->chChar));  //~v0ixI~
    shiftkey=((Ppkeyinfo->fsState & (KBDSTF_RIGHTSHIFT|KBDSTF_LEFTSHIFT))!=0);//~v0ixI~
    rc=filesetassign(Ppcw,Pextkeysw,key,shiftkey);                 //~v0ixR~
    if (rc>0)                                                      //~v0ixI~
        ubell();                                                   //~v0ixI~
    return rc;                                                     //~v0ixI~
}//kbdassignchng                                                   //~v0ixI~
//**************************************************************** //~vanfI~
//* setup filename parm for ucmdparmedit                           //~vanfI~
//**************************************************************** //~vanfI~
void kbdsetmacrocmdfilenameparm(PUCLIENTWE Ppcw,char *Ppfnm)       //~vanfR~
{                                                                  //~vanfI~
    PUFILEH pfh;                                                   //~vanfI~
    PUCLIENTWE pcw2;                                               //~vanfI~
    char *pfnm;                                                    //~vanfI~
//*********************                                            //~vanfI~
	pfnm=Ppfnm;                                                    //~vanfI~
	if (Ppcw->UCWtype==UCWTFILE || Ppcw->UCWtype==UCWTDIR)         //~vanfI~
    {	                                                           //~vanfI~
       	pfh=UGETPFHFROMPCW(Ppcw);                                  //~vanfI~
		strcpy(pfnm,pfh->UFHfilename);                             //~vanfI~
        pfnm+=strlen(pfnm)+1;                                      //~vanfI~
    }                                                              //~vanfI~
    else                                                           //~vanfI~
    {                                                              //~vanfI~
    	*pfnm++=0;                                                 //~vanfI~
    }                                                              //~vanfI~
	pcw2=scrgetcw(-1);	//another screen                           //~vanfI~
    if (pcw2 &&  (pcw2->UCWtype==UCWTFILE || pcw2->UCWtype==UCWTDIR))//~vanfI~
    {                                                              //~vanfI~
       	pfh=UGETPFHFROMPCW(pcw2);                                  //~vanfI~
		strcpy(pfnm,pfh->UFHfilename);                             //~vanfI~
    }                                                              //~vanfI~
    else                                                           //~vanfI~
    {                                                              //~vanfI~
    	*pfnm++=0;                                                 //~vanfI~
    }                                                              //~vanfI~
}//kbdsetmacrocmdfilenameparm                                      //~vanfR~
//**************************************************************** //~v0ijI~
//* edit func key cmd                                              //~v0ijI~
//* parm1 :pcw                                                     //~v0ijR~
//* parm2 :fkct index                                              //~v0ijI~
//* retrn :-1:err, 1:execute, 0:cmd set on line only               //~v0ijR~
//**************************************************************** //~v0ijI~
int kbdfkcedit(PUCLIENTWE Ppcw,int Pindex)                         //~v0ijR~
{                                                                  //~v0ijI~
    PFKCT pfkct;                                                   //~v0ijI~
    int cmdlen,rc,datalen;                                         //~v0ijR~
    int execopt;                                                   //~v0ijR~
    char  *pcmd,*pcmd2;                                            //~v0j5R~
    UCHAR wkbuff[MAXCOLUMN+1];                                     //~v0ijI~
    UCHAR wkbuff2[MAXCOLUMN+1];                                    //~v0ijI~
    UCHAR wkedit3[MAXCOLUMN+1];                                    //~vbvvI~
    int opt;                                                       //~vanfI~
    char parmfnm[_MAX_PATH*2+2];                                   //~vanfR~
//********************                                             //~v0ijI~
    if (Pindex>=Sfkctt.FKCTTentno)                                 //~v0ijI~
        return -1;      //ignore                                   //~v0ijI~
    pfkct=Sfkctt.FKCTTpfkct+Pindex;                                //~v0ijI~
    if (!(cmdlen=pfkct->FKCTcmdlen))                               //~v0ijR~
        return -1;      //ignore                                   //~v0ijI~
    pcmd=pfkct->FKCTpft_pcmd;                                      //~v0ijR~
    UTRACEP("%s:original pcmd=%s\n",UTT,pcmd);                     //~vbvvR~
//  strcpy(wkedit3,pcmd);                                          //~vbvvI~//~vbvzR~
    UmemcpyZ(wkedit3,pcmd,(UINT)pfkct->FKCTcmdlen);                //~vbvzI~
	if (funcAliasDropComment(wkedit3))	//cmd dropped              //~vbvvI~
    {                                                              //~vbvvI~
    	pcmd=wkedit3;                                              //~vbvvI~
        cmdlen=(int)strlen(pcmd);                                  //~vbvvI~
		cmdlen-=(int)umemrspnc(pcmd,' ',(UINT)cmdlen);             //~vbvvI~
        *(pcmd+cmdlen)=0;                                          //~vbvvI~
	    UTRACEP("%s:drop cmt pcmd=%s\n",UTT,pcmd);                 //~vbvvR~
    }                                                              //~vbvvI~
    execopt=(*(pcmd+cmdlen-1)==';');    //execute last is ;        //~v0ijR~
    pcmd2=0;                            //edit malloced            //~v0ijI~
    if (memchr(pcmd,'%',(UINT)cmdlen))  //contain replacing char   //~v0ijI~
    {                                                              //~v0ijI~
        *wkbuff=0;                      //for no data              //~v0ijI~
#ifdef UTF8SUPPH                                                   //~va00I~
        BYUTF8_funcgetlongcmd(Ppcw,wkbuff);    //data on cmd line  //~va00R~
#else                                                              //~va00I~
        funcgetlongcmd(Ppcw,wkbuff);    //data on cmd line         //~v0ijI~
#endif                                                             //~va00I~
                                                                   //~va00I~
        memcpy(wkbuff2,pcmd,(UINT)cmdlen);                         //~v0ijR~
        *(wkbuff2+cmdlen)=0;            //parm to ucmdparmedit     //~v0ijI~
        opt=CPEO_APPEND|CPEO_FNMPARM;	                           //~vanfI~
		kbdsetmacrocmdfilenameparm(Ppcw,parmfnm);                  //~vanfR~
        pcmd2=parmfnm;                                             //~vanfR~
//      if (rc=ucmdparmedit(1,wkbuff2,wkbuff,0,&pcmd2),rc)         //~v0ijI~//~vanfR~
        if (rc=ucmdparmedit(opt,wkbuff2,wkbuff,0,&pcmd2),rc)       //~vanfI~
            return rc;                                             //~v0ijI~
        pcmd=pcmd2;                                                //~v0ijI~
        cmdlen=(int)strlen(pcmd);                                  //~v0jcR~
        if (cmdlen>MAXCOLUMN)                                      //~v0jcI~
            cmdlen=MAXCOLUMN;                                      //~v0jcI~
    }                                                              //~v0ijI~
//  funcsetlongcmd(Ppcw,execopt,pcmd,cmdlen,&datalen);             //~v0j5I~
    memcpy(wkbuff,pcmd,(UINT)cmdlen);                              //~v0j5I~
    wkbuff[cmdlen]=0;                                              //~v0j5I~
    funcsetlongcmd(Ppcw,execopt,wkbuff,cmdlen,&datalen);           //~v0j5R~
    if (execopt)                                                   //~v0ijR~
//      funccmdstack(Gcmdbuff,cmdlen);  //save for retrieve        //~V670R~
        funccmdstack(Gcmdbuff,cmdlen,Ppcw->UCWseqno);  //save for retrieve//~V670I~
    else                                                           //~v0ijI~
        csronthefld(Ppcw,CMDLINENO,0,datalen);                     //~v0ijI~
    if (pcmd2)                                                     //~v0ijI~
        ufree(pcmd2);                                              //~v0ijI~
    return execopt; //execute enter                                //~v0ijR~
}//kbdfkcedit                                                      //~v0ijI~
//**************************************************************** //~V48fI~
//* edit short cut key cmd                                         //~V48fI~
//* parm1 :pcw                                                     //~V48fI~
//* parm2 :fkct index                                              //~V48fI~
//* retrn :-1:err, 1:execute, 0:cmd set on line only               //~V48fI~
//**************************************************************** //~V48fI~
int kbdscedit(PUCLIENTWE Ppcw,char Psckey)                         //~V48fI~
{                                                                  //~V48fI~
    PSCKT psckt;                                                   //~V48fR~
    int cmdlen,datalen,len,execopt,querymodesw,prevsc,len2,rc;     //~V48iR~
    UCHAR wkbuff[MAXCOLUMN*2],*pcmd;                               //~V48iR~
//  UCHAR wkparm[MAXCOLUMN+1],wkpedit[MAXCOLUMN+1],*peditcmd=0;    //~V53GR~
    UCHAR wkparm[MAXCOLUMN+1],wkpedit[MAXCOLUMN+1];                //~V53GI~
    UCHAR wkedit2[MAXCOLUMN+1];                                    //~vbvoR~
    char *peditcmd=0;                                              //~V53GI~
    char parmfnm[_MAX_PATH*2+2];                                   //~vanfI~
    int opt;                                                       //~vanfI~
//********************                                             //~V48fI~
    if (querymodesw=(Sshortcutstatus & KBD_SC_QUERY),querymodesw)  //~V48fR~
	    Sshortcutstatus&=~KBD_SC_QUERY; 		//once clear       //~V48fI~
    if (!isalnum(Psckey))                                          //~V48fI~
    {                                                              //~V48fI~
    	uerrmsg("exit ShortCut key mode",0);                       //~V48fR~
        return -1;                                                 //~V48fR~
    }                                                              //~V48fI~
    psckt=Gkbdsckt+(Psckey-SCKTTOP);                               //~V48fI~
	pcmd=psckt->SCKTcmd;                                           //~V48iI~
    if (!(cmdlen=psckt->SCKTcmdlen))                               //~V48fI~
    {                                                              //~V48fI~
//  	Sshortcutstatus=(KBD_SC_PEND|querymodesw);	//accept retry //~V48fI~//~vbrfR~
//      uerrmsg("\"%c\" is not defined,retry",0,                   //~V48fI~//~vbrfR~
        uerrmsg("\"%c\" is not defined as Shortcut Key on =0.1 panel",//~vbrfI~
                "\"%c\" はショートカットキー定義(=0.1画面)されていません",//~vbrfI~
					Psckey);                                       //~V48fI~
        return -1;                                                 //~V48fR~
    }                                                              //~V48fI~
//  strcpy(wkedit2,pcmd);                                          //~vbvoI~//~vbvzR~
    UmemcpyZ(wkedit2,pcmd,(UINT)cmdlen);                           //~vbvzI~
	if (funcAliasDropComment(wkedit2))	//cmd dropped              //~vbvoI~
    	pcmd=wkedit2;                                              //~vbvoI~
    if (memchr(pcmd,'%',(UINT)cmdlen))  //contain replacing char   //~V53GI~
    {                                                              //~V53GI~
        *wkparm=0;                      //for no data              //~V53GI~
#ifdef UTF8SUPPH                                                   //~va00I~
        BYUTF8_funcgetlongcmd(Ppcw,wkparm);    //data on cmd line  //~va00R~
#else                                                              //~va00I~
        funcgetlongcmd(Ppcw,wkparm);    //data on cmd line         //~V53GI~
#endif                                                             //~va00I~
        memcpy(wkpedit,pcmd,(UINT)cmdlen);                         //~V53GI~
        *(wkpedit+cmdlen)=0;            //parm to ucmdparmedit     //~V53GI~
        opt=CPEO_APPEND|CPEO_FNMPARM;                              //~vanfI~
		kbdsetmacrocmdfilenameparm(Ppcw,parmfnm);                  //~vanfR~
        peditcmd=parmfnm;                                          //~vanfI~
//      if (rc=ucmdparmedit(1,wkpedit,wkparm,0,&peditcmd),rc)//1:strcat not used parm,0:no addr list fmt output//~V53GI~//~vanfR~
        if (rc=ucmdparmedit(opt,wkpedit,wkparm,0,&peditcmd),rc)//1:strcat not used parm,0:no addr list fmt output//~vanfI~
            return rc;                                             //~V53GI~
        pcmd=peditcmd;                                             //~V53GI~
        cmdlen=(int)strlen(pcmd);                                  //~V53GI~
        if (cmdlen>MAXCOLUMN)                                      //~V53GI~
            cmdlen=MAXCOLUMN;                                      //~V53GI~
    }                                                              //~V53GI~
    execopt=(Ppcw->UCWrcsry!=CMDLINENO);//set on ly if cmdline     //~V48fM~
    if (execopt)                                                   //~V48fI~
    {                                                              //~V48fI~
    	len=(int)strlen(Spftkeycmd->FTcmd);                        //~V48fR~
    	memcpy(wkbuff,Spftkeycmd->FTcmd,(UINT)len);                //~V48fR~
    	*(wkbuff+len++)=' ';                                       //~V48fR~
//      len2=sizeof(wkbuff)-len;    //out area len                 //~V48iR~//~vb30R~
        len2=(int)sizeof(wkbuff)-len;    //out area len            //~vb30I~
        rc=uparsein(pcmd,wkbuff+len,len2,",;",'\'');//set lastnull //~V48iR~
        switch(rc)                                                 //~V48iR~
        {                                                          //~V48iR~
        case 0:                                                    //~V48iR~
            len+=cmdlen;        //simple quatated                  //~V48iR~
            break;                                                 //~V48iR~
        case 1:                                                    //~V48iR~
            len+=cmdlen+2;      //simple quatated                  //~V48iR~
            break;                                                 //~V48iR~
        case 2:                                                    //~V48iR~
            len+=(int)strlen(wkbuff+len);                          //~V48iR~
            break;                                                 //~V48iR~
        default:                                                   //~V48iR~
	        if (peditcmd)                                          //~V53GI~
            	ufree(peditcmd);                                   //~V53GI~
            uerrmsg("ShortCut cmd fmt err(%s)",0,                  //~V48iR~
                    pcmd);                                         //~V48iR~
            return -1;                                             //~V48iR~
        }                                                          //~V48iR~
    }                                                              //~V48fI~
    else                                                           //~V48fI~
    {                                                              //~V48iI~
		strcpy(wkbuff,pcmd);                                       //~V48iR~
		len=cmdlen;                                                //~V48iI~
    }                                                              //~V48iI~
    if (querymodesw)     //querymode                               //~V48fR~
    {                                                              //~V48fI~
    	prevsc=Sshortcutstatus&KBD_SC_SCMASK; 		//previously displayed shortcut key//~V48fI~
        if (!prevsc||prevsc!=Psckey)	//1st time                 //~V48fI~
        {                                                          //~V48fI~
        	uerrmsg("sc,%c :%s",0,                                 //~V48fI~
            		Psckey,pcmd);                                  //~V48iR~
		    Sshortcutstatus=(KBD_SC_PEND|KBD_SC_QUERY|Psckey);	//accept retry//~V48fI~
	        if (peditcmd)                                          //~V53GI~
            	ufree(peditcmd);                                   //~V53GI~
            return -1;                                             //~V48fI~
        }                                                          //~V48fI~
    }                                                              //~V48fI~
    uerrmsg("sc,%c :",0,                                           //~V48iI~
            		Psckey);                                       //~V48iI~
    funcsetlongcmd(Ppcw,execopt,wkbuff,len,&datalen);//set to cmd buff//~V48fR~
    if (execopt)                                                   //~V48fI~
//  	funccmdstack(Gcmdbuff,len);  //save for retrieve           //~V670R~
    	funccmdstack(Gcmdbuff,len,Ppcw->UCWseqno);  //save for retrieve//~V670I~
    else                                                           //~V48fI~
        csronthefld(Ppcw,CMDLINENO,0,datalen);                     //~V48fI~
    if (peditcmd)                                                  //~V53GI~
        ufree(peditcmd);                                           //~V53GI~
    return execopt;                                                //~V48fR~
}//kbdscedit                                                       //~V48fI~
//**************************************************************** //~v0ihI~
//* assigned functbl search by key                                 //~v0ijR~
//* parm1 :KEYTBL addr                                             //~v0ihI~
//* parm2 :shift id                                                //~v0ihI~
//* parm3 :output key type                                         //~v0ijI~
//* retrn :FUNCTBL addr, -1:can not be used, 0:currentry not used  //~v0ihI~
//**************************************************************** //~v0ihI~
#ifndef KKK                                                        //~vb50I~
FUNCTBL *kbdftsrch(int Popt,KEYTBL *Ppkt,int Pshiftid,int *Pkeytype)//~vb50I~
#define  KFSO_FTSHIFT   0x01	//S+Alt/Ctrl                       //~vb50I~
#else                                                              //~vb50I~
FUNCTBL *kbdftsrch(KEYTBL *Ppkt,int Pshiftid,int *Pkeytype)        //~v0ijR~
#endif                                                             //~vb50I~
{                                                                  //~v0ihI~
    int   key,scan,ch,keytype;                                     //~v0ihR~
    int   shiftissamevalue=0;                                      //~v0ihI~
//*****************                                                //~v0ihI~
    key=(int)Ppkt->KTkey[Pshiftid];                                //~v0ihR~
//UTRACEP("%s: entry Pshiftid=%d,key=0x%x,name=%s\n",UTT,Pshiftid,key,Ppkt->KTnamee);//~vbvoR~
    if (key==KEY_NOTUSE)                                           //~v0ihI~
    {                                                              //~vbv8I~
		UTRACEP("%s: KEY_NOTUSE(0)\n",UTT);                        //~vbv8I~
        return (FUNCTBL*)(ULPTR)-1;                                       //~v0ihI~//~vafkR~
    }                                                              //~vbv8I~
    scan=(int)((UINT)key>>8);        //scan code                   //~V48iR~
    ch  =key&255;       //char code                                //~v0ihI~
//*determin key type like as kbdproc                               //~v0ihI~
    if (scan==KEY_PENTRID)                                         //~v0ijI~
    {                                                              //~v0ijI~
        if (ch!=(KEY_PDIVIDE_CHK&255))//it char                    //~v0ijR~
        {                                                          //~v0ijI~
            scan=ch;                                               //~v0ijR~
            ch=0;           //trate as ext key                     //~v0ijR~
        }                                                          //~v0ijI~
    }                                                              //~v0ijI~
    if (ch==0x00 || ch==0xe0) //0x00 or 0xE0                       //~v0ihI~
    {                                                              //~v0ihI~
        keytype=UCWKTEXTKEY;                                       //~v0ihI~
        key=scan;                                                  //~v0ihI~
    }                                                              //~v0ihI~
    else                                                           //~v0ihI~
        keytype=UCWKTSBCS;                                         //~v0ihI~
    *Pkeytype=keytype;                                             //~v0ijR~
#ifndef KKK                                                        //~vb50I~
  if (Popt & KFSO_FTSHIFT)	//S+Alt/Ctrl                           //~vb50R~
    shiftissamevalue=KTSHIFTDUP;                                   //~vb50I~
  else                                                             //~vb50I~
#endif                                                             //~vb50I~
    shiftissamevalue=UCBITCHK(Ppkt->KTflag[Pshiftid],KTSHIFTDUP);  //~v0ioI~
//UTRACEP("%s: keytype=%d,key=%04x,shiftsame=%d\n",UTT,keytype,key,shiftissamevalue);//~vbvoR~
    return funcftsrch(keytype,(USHORT)key,shiftissamevalue);       //~v0ihI~
}//kbdftsrch                                                       //~v0ijR~
#ifndef ARMXXE	//funcsleepsettimeup                               //~va90I~
//**************************************************
//*kbd peek and return 1(char input exist) or 0(not exist)
//**************************************************
int kbdchk(void)
{
    KBDKEYINFO keyinf;
    int rc; 
//****************
    rc=ukbdpeek(&keyinf);
    UTRACED("ukbdpeek",&keyinf,sizeof(keyinf));
    return rc;
}//kbdchk
#endif //ARMXXE                                                    //~va90I~
//**************************************************
//*function key definition chk
//*parm1:key
//*parm2:output key tbl addr(null if err)
//*return:keytbl scancode tbl index(4 if err)
//**************************************************
int kbdsrchkt(USHORT Pkey,KEYTBL **Ppkt)
{
    KEYTBL *pkt;
    int i=0;                                                       //~v19iR~
//****************
    for (pkt=Sfkeytbl;*(pkt->KTnamee);pkt++)
    {
        for (i=0;i<4;i++)
            if (Pkey==pkt->KTkey[i])
                break;
        if (i<4)    //found
            break;
    }   
    if (i==4)
        *Ppkt=0;
    else
        *Ppkt=pkt;
    UTRACEP("%s:rc=%d,Pkey=0x%x\n",UTT,i,Pkey);                    //~vbv8R~
    return i;
}//kbdsrchkt

//**************************************************            //~5501I~
//*search duplicated key entry(Ctrl+key)                        //~5501I~
//*parm1:pkt                                                    //~5501I~
//*return:pkt ,null if err                                      //~5501I~
//**************************************************            //~5501I~
//KEYTBL *kbdsrchdupkt(KEYTBL *Ppkt)                               //~V69YR~
KEYTBL *kbdsrchdupkt(KEYTBL *Ppkt,int Pshiftid)                    //~V69YI~
{                                                               //~5501I~
    KEYTBL *pkt;                                                //~5501I~
//****************                                              //~5501I~
    for (pkt=Ppkt+1;*(pkt->KTnamee);pkt++)                      //~5501I~
//      if (pkt->KTkey[3]==Ppkt->KTkey[3])  //same Ctrl+ key       //~V69YR~
        if (pkt->KTkey[Pshiftid]==Ppkt->KTkey[Pshiftid])  //same Ctrl+ key//~V69YI~
                break;                                          //~5501I~
    if (!*(pkt->KTnamee))                                       //~5501I~
        pkt=0;                                                  //~5501R~
    return pkt;                                                 //~5501I~
}//kbdsrchdupkt                                                 //~5501I~
                                                                //~5501I~
//**************************************************            //~5429I~
//*key tbl search by key name                                   //~5429I~
//*parm1:key name                                               //~5429I~
//*parm2:output key tbl addr(null if err)                       //~5429I~
//*return:keytbl scancode tbl index(4 if err)                   //~5429I~
//**************************************************            //~5429I~
int kbdsrchktbyname(UCHAR *Pkeyname,KEYTBL **Ppkt)              //~5429I~
{                                                               //~5429I~
    KEYTBL *pkt;                                                //~5429I~
    UCHAR *pc;                                                  //~5429I~
    int ii,rc;                                                  //~5429I~
    UCHAR shiftch;                                                 //~v0jeI~
//****************                                              //~5429I~
//*chk shift key prefix                                         //~5429I~
    shiftch=(UCHAR)toupper(*Pkeyname);                             //~v0jeI~
    for (ii=1;ii<4;ii++)                                        //~5429I~
    {                                                           //~5429I~
        if (*(Pkeyname+1)=='+'                                     //~v0jeI~
        &&  shiftch==*Skeyshiftname[ii])                           //~v0jeR~
            break;                                                 //~v0jeI~
        if (!memicmp(Pkeyname,Skeyshiftname[ii],Skeyshiftnamelen[ii]))//~5429I~
            break;                                              //~5429I~
    }                                                           //~5429I~
    if (ii<4)   //found                                         //~5429I~
    {                                                              //~v0jeI~
      if (*(Pkeyname+1)=='+')                                      //~v0jeI~
        pc=Pkeyname+2;                                             //~v0jeI~
      else                                                         //~v0jeI~
        pc=Pkeyname+Skeyshiftnamelen[ii];                       //~5429I~
    }                                                              //~v0jeI~
    else                                                        //~5429I~
    {                                                           //~5501I~
        pc=Pkeyname;                                            //~5429I~
        ii=0;   //no shift                                      //~5501I~
    }                                                           //~5501I~
    rc=ii;                                                      //~5429I~
//*chk key name                                                 //~5429I~
    for (pkt=Sfkeytbl;*(pkt->KTnamee);pkt++)                    //~5429I~
    {                                                           //~5429I~
        if (!stricmp(pc,pkt->KTnamee))                          //~5429R~
            break;                                              //~5429I~
    }                                                           //~5429I~
    if (*(pkt->KTnamee))                                        //~5429I~
        *Ppkt=pkt;                                              //~5429I~
    else                                                        //~5429I~
    {                                                              //~V70mI~
	  for (pkt=Sfkeytbl101;*(pkt->KTnamee);pkt++)                  //~V70mI~
      {                                                            //~V70mI~
        if (!stricmp(pc,pkt->KTnamee))                             //~V70mI~
            break;                                                 //~V70mI~
      }                                                            //~V70mI~
      if (*(pkt->KTnamee))                                         //~V70mI~
        *Ppkt=pkt;                                                 //~V70mI~
      else                                                         //~V70mI~
        *Ppkt=0;                                                //~5429I~
    }                                                              //~V70mI~
    UTRACEP("%s:Pkeyname=%s,rc=%d,pkt=%p\n",UTT,Pkeyname,rc,*Ppkt);//~vbv8R~
    return rc;                                                  //~5429I~
}//kbdsrchktbyname                                              //~5429I~
                                                                //~5429I~
//**************************************************
//*get key name string
//*parm1 :key
//*parm2 :SHIFT key option
//*retrn :string ptr
//**************************************************
UCHAR *kbdgetname(USHORT Pkey,int Pshift)
{
static UCHAR Skeyname[8+sizeof(Sfkeytbl[0].KTnamee)];
    KEYTBL *pkeytbl;
    int     kti;
//**********************
    if (kti=kbdsrchkt(Pkey,&pkeytbl),!pkeytbl)  //not found
        return "";

#ifndef KKK                                                        //~vb50M~
  if (kti>=2 && Pshift)	//S+alt/ctl                                //~vb50I~
  {                                                                //~vb50I~
    if (XE_ISDBCSJ())                                              //~vb50I~
		xekbdsetSAC(XEKBDSACO_JP,kti,pkeytbl,Skeyname);            //~vb50R~
    else                                                           //~vb50I~
		xekbdsetSAC(0,kti,pkeytbl,Skeyname);                       //~vb50I~
  }                                                                //~vb50I~
  else                                                             //~vb50I~
#endif                                                             //~vb50M~
  {                                                                //~vb50I~
    if (Pshift)
        strcpy(Skeyname,Skeyshiftname[1]);
    else
        strcpy(Skeyname,Skeyshiftname[kti]);

//  if (UCBITCHK(Gscrstatus,GSCRSDBCS))                            //~v79zR~
    if (XE_ISDBCSJ())                                              //~v79zI~
        strcat(Skeyname,pkeytbl->KTnamej);
    else
        strcat(Skeyname,pkeytbl->KTnamee);
  }                                                                //~vb50I~
    return Skeyname;
}//kbdgetname                                                   //~5506R~
#ifdef LNX                                                         //~V642I~
//**************************************************               //~V642I~
//*convert key name to euc                                         //~V642I~
//**************************************************               //~V642I~
void kbdcvkeyname2euc(void)                                        //~V642I~
{                                                                  //~V642I~
    KEYTBL *pkt;                                                   //~V642I~
    int     len;                                                   //~V642I~
static int Scvendsw=0;                                             //~V642I~
	char  *pc,euckeyname[sizeof(((KEYTBL*)0)->KTnamej)*2];         //~V642R~
//**********************                                           //~V642I~
	if (Scvendsw)	//avoid duplicate conv                         //~V642I~
    	return ;                                                   //~V642I~
	Scvendsw=1;                                                    //~V642I~
    for (pkt=Sfkeytbl;*(pkt->KTnamee);pkt++)                       //~V642I~
    {                                                              //~V642I~
        pc=pkt->KTnamej;                                           //~V642I~
        len=(int)ustrnlen(pc,sizeof(pkt->KTnamej));                //~V642I~
        if (len)                                                   //~V642I~
        {                                                          //~V642I~
            ushift2euc(pc,0,len,euckeyname,0,&len,0);  //no dbcstbl,no hankana//~V642I~
//          len=min(len,sizeof(pkt->KTnamej));                     //~V642R~//~vb30R~
            len=min(len,(int)sizeof(pkt->KTnamej));                //~vb30I~
            strncpy(pc,euckeyname,(UINT)len);                      //~V642I~
        }                                                          //~V642I~
    }                                                              //~V642I~
    return;                                                        //~V642I~
}//kbdcvkeyname2euc                                                //~V642I~
#endif                                                             //~V642R~
//**************************************************            //~5506I~
//*get valid char code tbl                                      //~5506I~
//*parm :option 0:tbl by J/E,1:English,2:Japanese               //~5506I~
//*retrn:table addr                                             //~5506I~
//**************************************************            //~5506I~
UCHAR *kbdgetchartbl(int Popt)                                  //~5506I~
{                                                               //~5506I~
    UCHAR *tbl=0;                                                  //~v19iR~
//**********************                                        //~5506I~
    switch(Popt)                                                //~5506I~
    {                                                           //~5506I~
    case 0:                                                     //~5506I~
//      if (UCBITCHK(Gscrstatus,GSCRSDBCS))                        //~v79zR~
        if (XE_ISDBCSJ())                                          //~v79zI~
            tbl=Sjpnchar;                                       //~5506R~
        else                                                    //~5506R~
            tbl=Sengchar;                                       //~5506R~
        break;                                                  //~5506I~
    case 1:                                                     //~5506I~
        tbl=Sengchar;                                           //~5506I~
        break;                                                  //~5506I~
    case 2:                                                     //~5506I~
        tbl=Sjpnchar;                                           //~5506I~
        break;                                                  //~5506I~
    }                                                           //~5506I~
    return tbl;                                                 //~5506I~
}//kbdgetchartbl                                                //~5506I~
                                                                //~5506I~
//**************************************************               //~v0ihI~
//*get key group start/end kft                                     //~v0ihI~
//*parm1:grpid  0:pfn,1:other ext key,2:10key,else char            //~v0ihR~
//*parm2:out first entry                                           //~v0ihI~
//*parm3:out last  entry                                           //~v0ihI~
//*retrn:1:start not foune,2:end not found,3:both not found        //~v0ihI~
//**************************************************               //~v0ihI~
int kbdgetktgrp(int Pgrp,KEYTBL **Ppkts,KEYTBL **Ppkte)            //~v0ihR~
{                                                                  //~v0ihI~
    USHORT key1,key2;                                              //~v0ihR~
//**********************                                           //~v0ihI~
    switch(Pgrp)                                                   //~v0ihI~
    {                                                              //~v0ihI~
    case 0:     //pfk                                              //~v0ihI~
        key1=KEY_F1;                                               //~v0ihI~
        key2=KEY_F12;                                              //~v0ihI~
        break;                                                     //~v0ihI~
    case 1:                                                        //~v0ihR~
        key1=KEY_ESC;                                              //~v0ihI~
        key2=KEY_DOWN;                                             //~v0ihI~
        break;                                                     //~v0ihI~
    case 2:                                                        //~v0ihI~
        key1=KEY_P0;                                               //~v0ihM~
        key2=KEY_PENTR;                                            //~v0ihM~
        break;                                                     //~v0ihM~
    default:                                                       //~v0ihI~
        key1=KEY_A_1;                                              //~v0ihI~
        key2=KEY_C_BSLASH;                                         //~v0ihI~
    }                                                              //~v0ihI~
    kbdsrchkt(key1,Ppkts);                                         //~v0ihI~
    kbdsrchkt(key2,Ppkte);                                         //~v0ihI~
    return (*Ppkts==0)+(*Ppkte==0)*2;                              //~v0ihI~
}//kbdgetchartbl                                                   //~v0ihI~
                                                                   //~v0ihI~
//**************************************************************** //~v0ihI~
//* get function key cmd table(init at first)                      //~v0ihR~
//* parm1 :out PFKCT ptr                                           //~v0ihR~
//* retrn:UALLOC_FAILED                                            //~v0ihR~
//**************************************************************** //~v0ihI~
int kbdgetfkct(PFKCTT *Ppfkctt)                                    //~v0ijR~
{                                                                  //~v0ihI~
    KEYTBL  *pkt,*pktfns,*pktfne;                                  //~v0ijR~
    PFKCT   pfkct=0;                                               //~v0ihI~
    FUNCTBL *pft;                                                  //~v0ihI~
//  PFUNCTBL pft1,pft2;                                            //~V76iR~
    PFUNCTBL pft0,pfttb[3];                                        //~V76iR~
    int dupkeycnt=0;                                                 //~V76iR~//~vafcR~
    int ii,jj,kk,ll,cnt=0,keytype;                                 //~v0ijR~
    USHORT key;                                                    //~v0ijI~
    int charsw;                                                    //~v0ijI~
//*****************                                                //~v0ihI~
    if (Sfkctt.FKCTTpfkct)                                         //~v0ijR~
    {                                                              //~v0ihI~
        *Ppfkctt=&Sfkctt;                                          //~v0ijR~
        return 0;                                                  //~v0ihR~
    }                                                              //~v0ihI~
    kbdgetktgrp(0,&pktfns,&pktfne);    //Fn key                    //~v0ijR~
    for (kk=0;kk<2;kk++)                                           //~v0ihR~
    {                                                              //~v0ihI~
        for (pkt=Sfkeytbl;*(pkt->KTnamee);pkt++)                   //~v0ijR~
        {                                                          //~v0ijR~
            charsw=UCBITCHK(pkt->KTflag[2],KTCHARKEY);             //~v0ijR~
            for (jj=0;jj<4;jj++)                                   //~v0ijR~
            {                                                      //~v0ijR~
//          	UTRACEP("%s:jj=%d,KTname=%s,KTkey=%04x,KTflag=%02x\n",UTT,jj,pkt->KTnamee,pkt->KTkey[jj],pkt->KTflag[jj]);//~vbvoR~
//              if (charsw && jj!=2)    //char key or not alt+     //~V55jR~
                if (charsw && jj<2)    //char key and not ctrl/alt //~V55jI~
                    continue;                                      //~v0ijI~
#ifndef KKK                                                        //~vb50I~
                pft=kbdftsrch(0,pkt,jj,&keytype);                  //~vb50I~
#else                                                              //~vb50I~
                pft=kbdftsrch(pkt,jj,&keytype);                    //~v0ijR~
#endif                                                             //~vb50I~
//          	UTRACEP("%s:kbdftsrch pft=%p\n",UTT,pft);          //~vbvoR~
                if (pft==(FUNCTBL*)(ULPTR)-1)  //NOT_USED key             //~v0ijR~//~vafkR~
                    continue;                                      //~v0ijR~
//print for dup key,edit then dirlist screen                       //~v20iI~
                if (pft)                                           //~v20iI~
                {                                                  //~v20iI~
            	UTRACEP("%s:kbdftsrch pft=%s,flag2=%02x,FTkey/FTkflag=(%04x,%02x),(%04x,%02x),(%04x,%02x),(%04x%02x)\n",UTT,pft->FTnamee,pft->FTflag2,//~vb50I~
                		pft->FTkey[0],pft->FTkflag[0],             //~vb50I~
                		pft->FTkey[1],pft->FTkflag[1],             //~vb50I~
                		pft->FTkey[2],pft->FTkflag[2],             //~vb50I~
                		pft->FTkey[3],pft->FTkflag[3]);            //~vb50I~
//                    if ((pft1=pft->FTdupnext)!=0)   //dup key assign//~V76iR~
//                        pft2=pft1->FTdupprev;                    //~V76iR~
//                    else                                         //~V76iR~
//                    if ((pft1=pft->FTdupprev)!=0)   //dup key assign//~V76iR~
//                        pft2=pft1->FTdupnext;                    //~V76iR~
//                    if (pft1)           //dup assign             //~V76iR~
//                    {                                            //~V76iR~
//                        for (ii=0;ii<UCWMAXTYPE;ii++)            //~V76iR~
//                            if (pft1->FTfunc[ii])   //next is edit scr//~V76iR~
//                            {                                    //~V76iR~
//                                pft=pft1;       //edit as first  //~V76iR~
//                                break;                           //~V76iR~
//                            }                                    //~V76iR~
//                            else                    //next is dirlist//~V76iR~
//                            if (pft2->FTfunc[ii])//screen type duplicated//~V76iR~
//                            {                                    //~V76iR~
//                                pft=pft2;                        //~V76iR~
//                                pft2=pft1;  //exchange sequence  //~V76iR~
//                                break;                           //~V76iR~
//                            }                                    //~V76iR~
//                    }//dupkey                                    //~V76iR~
                    if (UCBITCHK(pft->FTflag2,FTF2HASDUPKEY))//dupkey may defined//~V76iR~
                    {                                              //~V76iI~
                    	dupkeycnt=funcdupktsrch(0,pkt,jj,pfttb);   //~V76iR~
		            	UTRACEP("%s:FTF2HASDUPKEY,dupkeycnt=%d\n",UTT,dupkeycnt);//~vb50I~
                        if (dupkeycnt)	//not dupkey(pft contains another dup key)//~V76iI~
                        {                                          //~vb50I~
        	                pft=pfttb[0];                          //~V76iR~
			            	UTRACEP("%s:FTF2HASDUPKEY,pfttb=[0]=%s,[1]=%s\n",UTT,pft->FTnamee,(dupkeycnt>1?pfttb[1]->FTnamee:(UCHAR*)"None"));//~vb50R~
                        }                                          //~vb50I~
                    }                                              //~V76iI~
                    else                                           //~V76iI~
                    	dupkeycnt=0;                               //~V76iI~
                }//pft!=0                                          //~v20iI~
//              for (ii=0;ii<2;ii++)    //dup assign               //~V76iR~
				pft0=pft;                                          //~V76iI~
                for (ii=0;ii<3;ii++)    //UCWtype                  //~V76iI~
                {                                                  //~v0ijI~
                    if (kk)     //2nd loop                         //~v0ijR~
                    {                                              //~v0ijR~
                        if (pkt<pktfns || pkt>pktfne)   //PFn key  //~v0ijR~
                            UCBITON(pfkct->FKCTflag,FKCTFNONPFK);  //~v0ijR~
                        key=pfkct->FKCTkey=pkt->KTkey[jj];         //~v0ijR~
                        if (UCBITCHK(pkt->KTkey[jj],KTSHIFTDUP))   //~v0ioI~
                            UCBITON(pfkct->FKCTflag,FKCTFSHIFT);   //~v0ioI~
                        pfkct->FKCTshift=(UCHAR)jj;                //~v0ijR~
                        if (pft)                                   //~v0ijR~
                        {                                          //~v0ijI~
                            UCBITON(pfkct->FKCTflag,FKCTFPFT);     //~v0ijI~
UTRACEP("%s:FKCTFPFT on1  ii=%d,jj=%d,kk=%d,FKCTflag=0x%x,id=%d,pftnamej=%s,namee=%s\n",UTT,ii,jj,kk,pfkct->FKCTflag,pft->FTfuncid,pft->FTnamej,pft->FTnamee);                             //~V76iI~//~vbv8R~
                			if (pft->FTfuncid>FUNCID_GRAPHCHAR)    //~vbv8I~
								UTRACEP("%s:FKCTFPFT on  GRAPHCHAR\n",UTT);//~vbv8I~
                            pfkct->FKCTfuncid=pft->FTfuncid;       //~v0ijI~
                            for (ll=0;ll<FTMAXKEY;ll++)            //~v0ijI~
                                if (key==pft->FTkey[ll])           //~v0ijI~
                                {                                  //~v0ijI~
                                    if (jj!=1)  //not shift key    //~v0ijI~
                                        break;                     //~v0ijI~
                                    if (pft->FTkflag[ll] & FTSHIFT)//~v0ijI~
                                        break;                     //~v0ijI~
                                }                                  //~v0ijI~
                            if (ll<FTMAXKEY)                       //~v0ijI~
                                if (pft->FTkflag[ll] & FTFIX)      //~v0ijI~
                                    UCBITON(pfkct->FKCTflag,FKCTFFIX);//~v0ijI~
                        }                                          //~v0ijI~
                        pfkct->FKCTpft_pcmd=pft;                   //~v0ijR~
                        pfkct->FKCTpkt=pkt;                        //~v0ijR~
			            UTRACEP("%s:set pfkct pft=%s,jj=%d,FKCTkey=%04x,FKCTshift=%d,FKCTflag=%02x\n",UTT,pft->FTnamee,jj,pfkct->FKCTkey,pfkct->FKCTshift,pfkct->FKCTflag);//~vb50I~
                        pfkct++;                                   //~v0ijR~
                    }                                              //~v0ijR~
                    else                                           //~v0ijR~
                        cnt++;                                     //~v0ijR~
UTRACEP("%s:jj=%d,ii=%d,keyname=%s,pft=%p,FTname=%s,cnt=%d,pfkct=%p\n",UTT,jj,ii,pkt->KTnamej,pft,pft->FTnamee,cnt,pfkct);//~vb50R~
//                    if (!pft)                                    //~V76iR~
//                        break;                                   //~V76iR~
////                  pft=pft->FTdupnext;                          //~V76iR~
////                  if (!pft)                                    //~V76iR~
//                    if (!pft1)                                   //~vb50R~
//                        break;                                   //~V76iR~
//                    pft=pft2;                                    //~V76iR~
                    if (!pft0) 	//no any function defined          //~V76iI~
                        break;                                     //~V76iI~
                    if (!dupkeycnt)	//not dupkey loop              //~V76iI~
                        break;                                     //~V76iI~
                    pft=pfttb[ii+1];                               //~V76iI~
                    if (!pft) 	//end of dupkey                    //~V76iR~
                        break;                                     //~V76iI~
                }//dup assign                                      //~v0ijI~
            }//all shift                                           //~v0ijR~
#ifndef KKK                                                        //~vb50I~
//* for S+Alt and S+Ctrl                                           //~vb50I~
            key=pkt->KTkey[0];     //TO CHK EXTENDED KEY           //~vb50I~
          if (KBD_EXTENDED_KEY(key))  //not char key               //~vb50R~
          {                                                        //~vb50I~
            for (jj=2;jj<4;jj++)                                   //~vb50I~
            {                                                      //~vb50I~
                key=pkt->KTkey[jj];                                //~vb50I~
            	UTRACEP("%s:SAC;jj=%d,KTname=%s,KTkey=%04x,KTflag=%02x\n",UTT,jj,pkt->KTnamee,key,pkt->KTflag[jj]);//~vb50R~
//              if (charsw && jj<2)    //char key and not ctrl/alt //~vb50I~
//                  continue;                                      //~vb50I~
//              pft=kbdftsrch(pkt,jj,&keytype);                    //~vb50I~
                if (!KBD_EXTENDED_KEY(key))    //char key          //~vb50R~
                	continue;                                      //~vb50I~
                pft=kbdftsrch(KFSO_FTSHIFT,pkt,jj,&keytype);	//search func set with FTSHIFT//~vb50R~
                if (pft==(FUNCTBL*)(ULPTR)-1)  //NOT_USED key      //~vb50I~
                    continue;                                      //~vb50I~
                if (pft)                                           //~vb50I~
                {                                                  //~vb50I~
            	UTRACEP("%s:SAC;kbdftsrch pft=%s,flag2=%02x,FTkey/FTkflag=(%04x,%02x),(%04x,%02x),(%04x,%02x),(%04x%02x)\n",UTT,pft->FTnamee,pft->FTflag2,//~vb50I~
                		pft->FTkey[0],pft->FTkflag[0],             //~vb50I~
                		pft->FTkey[1],pft->FTkflag[1],             //~vb50I~
                		pft->FTkey[2],pft->FTkflag[2],             //~vb50I~
                		pft->FTkey[3],pft->FTkflag[3]);            //~vb50I~
                    if (UCBITCHK(pft->FTflag2,FTF2HASDUPKEY))//dupkey may defined//~vb50I~
                    {                                              //~vb50I~
                    	dupkeycnt=funcdupktsrch(FDKSO_FTSHIFT,pkt,jj,pfttb);//~vb50R~
		            	UTRACEP("%s:FTF2HASDUPKEY,dupkeycnt=%d\n",UTT,dupkeycnt);//~vb50I~
                        if (dupkeycnt)	//not dupkey(pft contains another dup key)//~vb50I~
                        {                                          //~vb50I~
        	                pft=pfttb[0];                          //~vb50I~
			            	UTRACEP("%s:SAC;FTF2HASDUPKEY,pfttb=[0]=%s,[1]=%s\n",UTT,pft->FTnamee,(dupkeycnt>1?pfttb[1]->FTnamee:(UCHAR*)"None"));//~vb50R~
                        }                                          //~vb50I~
                    }                                              //~vb50I~
                    else                                           //~vb50I~
                    	dupkeycnt=0;                               //~vb50I~
                }//pft!=0                                          //~vb50I~
				pft0=pft;                                          //~vb50I~
                for (ii=0;ii<3;ii++)    //UCWtype                  //~vb50I~
                {                                                  //~vb50I~
                    if (kk)     //2nd loop                         //~vb50I~
                    {                                              //~vb50I~
                        if (pkt<pktfns || pkt>pktfne)   //PFn key  //~vb50I~
                            UCBITON(pfkct->FKCTflag,FKCTFNONPFK);  //~vb50I~
                        key=pfkct->FKCTkey=pkt->KTkey[jj];         //~vb50I~
                        if (UCBITCHK(pkt->KTkey[jj],KTSHIFTDUP))   //~vb50I~
                            UCBITON(pfkct->FKCTflag,FKCTFSHIFT);   //~vb50I~
                        UCBITON(pfkct->FKCTflag,FKCTFSHIFTAC);     //~vb50I~
                        pfkct->FKCTshift=(UCHAR)jj;                //~vb50I~
                        if (pft)                                   //~vb50I~
                        {                                          //~vb50I~
                            UCBITON(pfkct->FKCTflag,FKCTFPFT);     //~vb50I~
UTRACEP("%s:FKCTFPFT  on2  ii=%d,jj=%d,kk=%d,FKCTflag=0x%x,id=%d,pftnamej=%s,namee=%s\n",UTT,ii,jj,kk,pfkct->FKCTflag,pft->FTfuncid,pft->FTnamej,pft->FTnamee);//~vbv8R~
                			if (pft->FTfuncid>FUNCID_GRAPHCHAR)    //~vbv8I~
								UTRACEP("%s:FKCTFPFT on  GRAPHCHAR\n",UTT);//~vbv8I~
							                                       //~vbv8I~
                            pfkct->FKCTfuncid=pft->FTfuncid;       //~vb50I~
//                            for (ll=0;ll<FTMAXKEY;ll++)          //~vb50I~
//                                if (key==pft->FTkey[ll])         //~vb50I~
//                                {                                //~vb50I~
//                                    if (jj!=1)  //not shift key  //~vb50I~
//                                        break;                   //~vb50I~
//                                    if (pft->FTkflag[ll] & FTSHIFT)//~vb50I~
//                                        break;                   //~vb50I~
//                                }                                //~vb50I~
//                            if (ll<FTMAXKEY)                     //~vb50I~
//                                if (pft->FTkflag[ll] & FTFIX)    //~vb50I~
//                                    UCBITON(pfkct->FKCTflag,FKCTFFIX);//~vb50I~
                        }                                          //~vb50I~
                        pfkct->FKCTpft_pcmd=pft;                   //~vb50I~
                        pfkct->FKCTpkt=pkt;                        //~vb50I~
			            UTRACEP("%s:SAC;set pfkct pft=%s,jj=%d,FKCTkey=%04x,FKCTshift=%d,FKCTflag=%02x\n",UTT,pft->FTnamee,jj,pfkct->FKCTkey,pfkct->FKCTshift,pfkct->FKCTflag);//~vb50R~
                        pfkct++;                                   //~vb50I~
                    }                                              //~vb50I~
                    else                                           //~vb50I~
                        cnt++;                                     //~vb50I~
UTRACEP("%s:SAC;jj=%d,ii=%d,keyname=%s,pft=%p,FTname=%s,cnt=%d,pfkct=%p\n",UTT,jj,ii,pkt->KTnamej,pft,pft->FTnamee,cnt,pfkct);//~vb50R~
                    if (!pft0) 	//no any function defined          //~vb50I~
                        break;                                     //~vb50I~
                    if (!dupkeycnt)	//not dupkey loop              //~vb50I~
                        break;                                     //~vb50I~
                    pft=pfttb[ii+1];                               //~vb50I~
                    if (!pft) 	//end of dupkey                    //~vb50I~
                        break;                                     //~vb50I~
                }//dup assign                                      //~vb50I~
            }//Alt and Ctrl                                        //~vb50I~
          }//extended key without modifier                         //~vb50I~
#endif //!KKK                                                      //~vb50R~
        }//all kt                                                  //~v0ijI~
        if (!kk)    //1st loop                                     //~v0ihI~
        {                                                          //~v0ihI~
            Sfkctt.FKCTTpfkct=pfkct=UALLOCC((UINT)(cnt),sizeof(FKCT));  //last is stopper//~v0ijI~
            UALLOCCHK(Sfkctt.FKCTTpfkct,UALLOC_FAILED);            //~v0ijR~
            Sfkctt.FKCTTentno=(USHORT)cnt;                         //~v0j5R~
        }                                                          //~v0ihI~
    }//1st time:count,2nd time:setup                               //~v0ihR~
    *Ppfkctt=&Sfkctt;                                              //~v0ijR~
    return 0;                                                      //~v0ihI~
}//kbdgetfkct                                                      //~v0ihI~
//**************************************************************** //~v0ijI~
//* search fkct entry by pkt and shift                             //~v0ijI~
//* parm1 :pkt                                                     //~v0ijI~
//* parm2 :shift id                                                //~v0ijI~
//* retrn :found index,-1 for not found                            //~v0ijI~
//**************************************************************** //~v0ijI~
#ifndef KKK                                                        //~vb50I~
int kbdfkctsrch(int Popt,KEYTBL *Ppkt,int Pshift)                  //~vb50I~
#else                                                              //~vb50I~
int kbdfkctsrch(KEYTBL *Ppkt,int Pshift)                           //~v0ijR~
#endif                                                             //~vb50I~
{                                                                  //~v0ijI~
    int ii;                                                        //~v0ijR~
    PFKCT pfkct;                                                   //~v0ijI~
//*****************                                                //~v0ijI~
    for (ii=0,pfkct=Sfkctt.FKCTTpfkct;ii<Sfkctt.FKCTTentno;ii++,pfkct++)//~v0ijI~
    {                                                              //~v0ijI~
#ifndef KKK                                                        //~vb50I~
      if (Popt & KFKCSO_SHIFTAC) //    0x01 //search S+A,S+C       //~vb50R~
      {                                                            //~vb50I~
        if (pfkct->FKCTpkt==Ppkt                                   //~vb50I~
        &&  (int)(pfkct->FKCTshift)==Pshift                        //~vb50I~
        &&  Pshift>=2                                              //~vb50I~
        &&  UCBITCHK(pfkct->FKCTflag,FKCTFSHIFTAC)                 //~vb50R~
        )                                                          //~vb50I~
            break;                                                 //~vb50I~
      }                                                            //~vb50I~
      else                                                         //~vb50I~
#endif                                                             //~vb50I~
        if (pfkct->FKCTpkt==Ppkt                                   //~v0ijR~
        &&  (int)(pfkct->FKCTshift)==Pshift)                       //~v0ijI~
            break;                                                 //~v0ijI~
    }                                                              //~v0ijI~
    if (ii>=Sfkctt.FKCTTentno)                                     //~v0ijI~
        ii=-1;                                                     //~v0ijI~
    UTRACEP("%s:rc=%d,Pshift=%d,KTnamee=%s,FKCTkey=x%x,FKCTshift=%d,FKCTflag=x%x\n",UTT,ii,Pshift,Ppkt->KTnamee,pfkct->FKCTkey,pfkct->FKCTshift,pfkct->FKCTflag);//~vbvvR~
    return ii;                                                     //~v0ijI~
}//kbdfkctsrch                                                    //~v0ijI~//~vbvvR~
//**************************************************************** //~v0ijI~
//* write fkct to ini                                              //~v0ijI~
//* parm1 :FILE*                                                   //~v0ijI~
//* retrn:read err rc                                              //~v0ijI~
//**************************************************************** //~v0ijI~
int kbdwfkct(FILE *Pfh)                                            //~v0ijR~
{                                                                  //~v0ijI~
    UCHAR wkbuff[FKF_MAXCMDLEN];                                   //~v0ijI~
    PFKCT pfkct;                                                   //~v0ijI~
    UINT len;                                                      //~v0ijI~
    UCHAR *pc;                                                     //~v0ijI~
    int ii,cmdlen;                                                 //~v0ijI~
//#ifdef ULIB64                                                      //~va70I~//~vafmR~
#if defined(ULIB64)||defined(ULIB64X)                              //~vafmI~
    PFKCT32 pfkct32,pfkct320;                                      //~va70I~
#endif                                                             //~va70I~
//*********************************                                //~v0ijI~
//  len=fwrite(&Sfkctt.FKCTTentno,sizeof(Sfkctt.FKCTTentno),1,Pfh);//entry no//~v0ijR~//~vb31R~
    len=(UINT)fwrite(&Sfkctt.FKCTTentno,sizeof(Sfkctt.FKCTTentno),1,Pfh);//entry no//~vb31I~
    if (!len)                                                      //~v0ijI~
        return 16;                                                 //~v0ijI~
    if (Sfkctt.FKCTTentno)                                         //~v0ijI~
    {                                                              //~v0ijI~
        pfkct=Sfkctt.FKCTTpfkct;                                   //~v0ijI~
//#ifdef ULIB64                                                      //~va70I~//~vafmR~
#if defined(ULIB64)||defined(ULIB64X)                              //~vafmI~
    	pfkct320=pfkct32=UALLOCC((UINT)(Sfkctt.FKCTTentno),sizeof(FKCT32));    //last is stopper//~va70I~
    	UALLOCCHK(pfkct32,UALLOC_FAILED);                          //~va70I~
    	for (ii=0;ii<Sfkctt.FKCTTentno;ii++,pfkct++,pfkct32++)     //~va70I~
    	{                                                          //~va70I~
        	pfkct32->FKCT32pft_pcmd=0;  //for read err case        //~va70I~
        	pfkct32->FKCT32pkt=0;                                  //~va70I~
			memcpy(&(pfkct32->FKCT32funcid),&(pfkct->FKCTfuncid),FKCT32FIDOFFSZ);//~va70I~
    	}                                                          //~va70I~
//      len=fwrite(pfkct320,(UINT)(sizeof(FKCT32)*Sfkctt.FKCTTentno),1,Pfh);//~va70I~//~vb31R~
        len=(UINT)fwrite(pfkct320,(UINT)(sizeof(FKCT32)*Sfkctt.FKCTTentno),1,Pfh);//~vb31I~
		ufree(pfkct320);                                           //~va70I~
        pfkct=Sfkctt.FKCTTpfkct;                                   //~va70I~
#else                                                              //~va70I~
        len=fwrite(pfkct,(UINT)(sizeof(FKCT)*Sfkctt.FKCTTentno),1,Pfh);//~v0ijR~
#endif                                                             //~va70I~
        if (!len)                                                  //~v0ijI~
            return 16;                                             //~v0ijI~
        for (ii=0;ii<Sfkctt.FKCTTentno;ii++,pfkct++)               //~v0ijR~
        {                                                          //~v0ijI~
            if (!UCBITCHK(pfkct->FKCTflag,FKCTFPFT|FKCTFNONPFK))    //func not ass to pfk//~v0ijI~
            {                                                      //~v0ijI~
                cmdlen=pfkct->FKCTcmdlen;                          //~v0ijR~
                pc=pfkct->FKCTpft_pcmd;                            //~v0ijI~
                if (cmdlen)                                        //~v0ijR~
                {                                                  //~v0ijI~
                    if (cmdlen>sizeof(wkbuff))                     //~v0ijI~
                        cmdlen=sizeof(wkbuff);                     //~v0ijI~
                    memset(wkbuff,0,sizeof(wkbuff));               //~v0ijI~
                    memcpy(wkbuff,pc,(UINT)cmdlen);                //~v0ijI~
//                  len=fwrite(wkbuff,sizeof(wkbuff),1,Pfh);       //~v0ijR~//~vb31R~
                    len=(UINT)fwrite(wkbuff,sizeof(wkbuff),1,Pfh); //~vb31I~
                    if (!len)                                      //~v0ijI~
                        return 16;                                 //~v0ijI~
                }                                                  //~v0ijI~
            }                                                      //~v0ijI~
        }                                                          //~v0ijI~
    }                                                              //~v0ijI~
    return 0;                                                      //~v0ijI~
}//kbdwfkct                                                        //~v0ijR~
                                                                   //~v0ijI~
//**************************************************************** //~v0ijI~
//* read  fkct from ini                                            //~v0ijI~
//* parm1 :FILE*                                                   //~v0ijI~
//* retrn:read err or UALLOC_FAILED                                //~v0ijI~
//**************************************************************** //~v0ijI~
int kbdrfkct(FILE *Pfh)                                            //~v0ijR~
{                                                                  //~v0ijI~
    PFKCT pfkct;                                                   //~v0ijI~
    UCHAR wkbuff[FKF_MAXCMDLEN];                                   //~v0ijI~
    UCHAR *pc;                                                     //~v0ijR~
    int ii,cmdlen;                                                 //~v0ijI~
//#ifdef ULIB64                                                      //~va70I~//~vafmR~
#if defined(ULIB64)||defined(ULIB64X)                              //~vafmI~
    PFKCT32 pfkct32,pfkct320;                                      //~va70I~
#endif                                                             //~va70I~
//*********************************                                //~v0ijI~
    if (!(fread(&Sfkctt.FKCTTentno,sizeof(Sfkctt.FKCTTentno),1,Pfh)))//~v0ijR~
        return 16;                                                 //~v0ijI~
    if (!Sfkctt.FKCTTentno)                                        //~v0ijI~
        return 0;                                                  //~v0ijI~
    Sfkctt.FKCTTpfkct=pfkct=UALLOCC((UINT)(Sfkctt.FKCTTentno),sizeof(FKCT));    //last is stopper//~v0ijI~
    UALLOCCHK(Sfkctt.FKCTTpfkct,UALLOC_FAILED);                    //~v0ijI~
//#ifdef ULIB64                                                      //~va70I~//~vafmR~
#if defined(ULIB64)||defined(ULIB64X)                              //~vafmI~
    pfkct320=pfkct32=UALLOCC((UINT)(Sfkctt.FKCTTentno),sizeof(FKCT32));    //last is stopper//~va70I~
    UALLOCCHK(pfkct32,UALLOC_FAILED);                              //~va70I~
    if (!fread(pfkct32,(UINT)(sizeof(FKCT32)*Sfkctt.FKCTTentno),1,Pfh))//~va70I~
#else                                                              //~va70I~
    if (!fread(pfkct,(UINT)(sizeof(FKCT)*Sfkctt.FKCTTentno),1,Pfh))//~v0ijR~
#endif                                                             //~va70I~
    {                                                              //~v0ijI~
        memset(pfkct,0,(UINT)(sizeof(FKCT)*Sfkctt.FKCTTentno)); //for ufree at term//~v0ijI~
//#ifdef ULIB64                                                      //~va70I~//~vafmR~
#if defined(ULIB64)||defined(ULIB64X)                              //~vafmI~
		ufree(pfkct320);                                           //~va70I~
#endif                                                             //~va70I~
        return 16;                                                 //~v0ijI~
    }                                                              //~v0ijI~
//init ptr clear for err case                                      //~v0ijI~
    for (ii=0;ii<Sfkctt.FKCTTentno;ii++,pfkct++)                   //~v0ijR~
    {                                                              //~va70I~
        pfkct->FKCTpft_pcmd=0;  //for read err case                //~v0ijR~
//#ifdef ULIB64                                                      //~va70I~//~vafmR~
#if defined(ULIB64)||defined(ULIB64X)                              //~vafmI~
        pfkct->FKCTpkt=0;                                          //~va70I~
		memcpy(&(pfkct->FKCTfuncid),&(pfkct32->FKCT32funcid),FKCT32FIDOFFSZ);//~va70I~
        UTRACEP("%s:FKCTkey=x%x,FKCTflag=x%x,FKCTshift=%d\n",UTT,pfkct->FKCTkey,pfkct->FKCTflag,pfkct->FKCTshift);//~vbvzR~
        pfkct32++;                                                 //~va70I~
#endif                                                             //~va70I~
    }                                                              //~va70I~
//#ifdef ULIB64                                                      //~va70I~//~vafmR~
#if defined(ULIB64)||defined(ULIB64X)                              //~vafmI~
	ufree(pfkct320);                                               //~va70I~
#endif                                                             //~va70I~
                                                                   //~v0ijI~
    pfkct=Sfkctt.FKCTTpfkct;                                       //~v0ijR~
    for (ii=0;ii<Sfkctt.FKCTTentno;ii++,pfkct++)                   //~v0ijR~
    {                                                              //~v0ijI~
        if (!UCBITCHK(pfkct->FKCTflag,FKCTFPFT|FKCTFNONPFK))    //func not ass to pfk//~v0ijI~
        {                                                          //~v0ijI~
            cmdlen=pfkct->FKCTcmdlen;                              //~v0ijI~
            if (cmdlen)                                            //~v0ijI~
            {                                                      //~v0ijI~
                if (!fread(wkbuff,sizeof(wkbuff),1,Pfh))           //~v0ijI~
                    return 16;                                     //~v0ijI~
                UTRACED("wkbuff",wkbuff,sizeof(wkbuff));           //~vbvzI~
                if (cmdlen>sizeof(wkbuff))                         //~v0ijR~
                    cmdlen=sizeof(wkbuff);                         //~v0ijI~
//              pc=UALLOCM((UINT)cmdlen);   //last is stopper      //~v0ijR~//~vbvzR~
                pc=UALLOCM((UINT)(cmdlen+1));   //last is stopper  //~vbvzI~
                UALLOCCHK(pc,UALLOC_FAILED);                       //~v0ijR~
                pfkct->FKCTpft_pcmd=pc;                            //~v0ijR~
                pfkct->FKCTcmdlen=(USHORT)cmdlen;                  //~v0ijR~
                memcpy(pc,wkbuff,(UINT)cmdlen);                    //~v0ijR~
                *(pc+cmdlen)=0;                                    //~vbvzI~
                UTRACEP("%s:FKCTcmdlen=%d,FKCTpft_pcmd=%s\n",UTT,cmdlen,pc);//~vbvvR~
       			UTRACEP("%s:FKCTkey=x%x,FKCTflag=x%x,FKCTshift=%d\n",UTT,pfkct->FKCTkey,pfkct->FKCTflag,pfkct->FKCTshift);//~vbvzI~
            }                                                      //~v0ijI~
        }                                                          //~v0ijI~
    }                                                              //~v0ijI~
    return 0;                                                      //~v0ijI~
}//kbdrfkct                                                        //~v0ijR~
                                                                   //~v20bI~
//**************************************************************** //~V48fI~
//* write shortcut key tbl to ini                                  //~V48fI~
//* parm1 :FILE*                                                   //~V48fI~
//* retrn:read err rc                                              //~V48fI~
//**************************************************************** //~V48fI~
int kbdwsckt(FILE *Pfh)                                            //~V48fI~
{                                                                  //~V48fI~
    UCHAR wkbuff[FKF_MAXCMDLEN];                                   //~V48fI~
    PSCKT psckt;                                                   //~V48fI~
    int ii,cmdlen,len;                                             //~V48fI~
//#ifdef ULIB64                                                      //~va70I~//~vafmR~
#if defined(ULIB64)||defined(ULIB64X)                              //~vafmI~
    PSCKT32 psckt32;                                               //~va70I~
    SCKT32 wsckt32[SCKTMAXNO];                                     //~va70I~
#endif                                                             //~va70I~
//*********************************                                //~V48fI~
//#ifdef ULIB64                                                      //~va70I~//~vafmR~
#if defined(ULIB64)||defined(ULIB64X)                              //~vafmI~
    for (ii=0,psckt=Gkbdsckt,psckt32=wsckt32;ii<SCKTMAXNO;ii++,psckt++,psckt32++)//~va70I~
    {                                                              //~va70I~
    	memcpy(psckt32,psckt,sizeof(SCKT32));                      //~va70I~
    }                                                              //~va70I~
    len=(int)fwrite(wsckt32,sizeof(wsckt32),1,Pfh);//ptr tbl       //~va70I~
#else                                                              //~va70I~
    len=(int)fwrite(&Gkbdsckt,sizeof(Gkbdsckt),1,Pfh);//ptr tbl    //~V48fI~
#endif                                                             //~va70I~
    if (!len)                                                      //~V48fI~
        return 16;                                                 //~V48fI~
    for (ii=0,psckt=Gkbdsckt;ii<SCKTMAXNO;ii++,psckt++)            //~V48fI~
    {                                                              //~V48fI~
       	if (cmdlen=psckt->SCKTcmdlen,cmdlen)                       //~V48fI~
        {                                                          //~V48fI~
          if (ii==SCKTALIAS-SCKTTOP     //for alias cmd entry      //~V67CI~
          &&  cmdlen>sizeof(wkbuff))    //long                     //~V67CI~
          {                                                        //~V67CI~
            len=(int)fwrite(psckt->SCKTcmd,(UINT)(cmdlen+1),1,Pfh);//~V705R~
          }                                                        //~V67CI~
          else                                                     //~V67CI~
          {                                                        //~V67CI~
            if (cmdlen>sizeof(wkbuff))                             //~V48fI~
                cmdlen=sizeof(wkbuff);                             //~V48fI~
            memset(wkbuff,0,sizeof(wkbuff));                       //~V48fI~
            memcpy(wkbuff,psckt->SCKTcmd,(UINT)cmdlen);            //~V48fI~
            len=(int)fwrite(wkbuff,sizeof(wkbuff),1,Pfh);          //~V48iR~
          }                                                        //~V67CI~
            if (!len)                                              //~V48fI~
                return 16;                                         //~V48fI~
        }                                                          //~V48fI~
    }                                                              //~V48fI~
    return 0;                                                      //~V48fI~
}//kbdwsckt                                                        //~V48fI~
//**************************************************************** //~V48fI~
//* read  shortcut key tbl                                         //~V48fI~
//* parm1 :FILE*                                                   //~V48fI~
//* retrn:read err or UALLOC_FAILED                                //~V48fI~
//**************************************************************** //~V48fI~
int kbdrsckt(FILE *Pfh)                                            //~V48fI~
{                                                                  //~V48fI~
    UCHAR wkbuff[FKF_MAXCMDLEN];                                   //~V48fI~
    UCHAR *pc;                                                     //~V48fI~
    int ii,cmdlen;                                                 //~V48fI~
    PSCKT psckt;                                                   //~V48fR~
    SCKT wsckt[SCKTMAXNO];                                         //~V48fI~
//#ifdef ULIB64                                                      //~va70I~//~vafmR~
#if defined(ULIB64)||defined(ULIB64X)                              //~vafmI~
    PSCKT32 psckt32;                                               //~va70I~
    SCKT32 wsckt32[SCKTMAXNO];                                     //~va70I~
#endif                                                             //~va70I~
//*********************************                                //~V48fI~
//#ifdef ULIB64                                                      //~va70I~//~vafmR~
#if defined(ULIB64)||defined(ULIB64X)                              //~vafmI~
    if (!(fread(&wsckt32,sizeof(wsckt32),1,Pfh)))                  //~va70I~
        return 16;                                                 //~va70I~
    for (ii=0,psckt=wsckt,psckt32=wsckt32;ii<SCKTMAXNO;ii++,psckt++,psckt32++)//~va70I~
    {                                                              //~va70I~
    	memcpy(psckt,psckt32,sizeof(SCKT32));                      //~va70I~
        psckt->SCKTcmd=0;       //8byte ptr                        //~vb83I~
    }                                                              //~va70I~
#else                                                              //~va70I~
    if (!(fread(&wsckt,sizeof(wsckt),1,Pfh)))                      //~V48fI~
        return 16;                                                 //~V48fI~
#endif                                                             //~va70I~
    for (ii=0,psckt=wsckt;ii<SCKTMAXNO;ii++,psckt++)               //~V48fI~
    {                                                              //~V48fI~
       	if (cmdlen=psckt->SCKTcmdlen,cmdlen)                       //~V48fI~
        {                                                          //~V48fI~
          if (ii==SCKTALIAS-SCKTTOP     //for alias cmd entry      //~V67CI~
          &&  cmdlen>sizeof(wkbuff))    //long                     //~V67CI~
          {                                                        //~V67CI~
            pc=UALLOCC(1,(UINT)cmdlen+1);   //last is stopper      //~V67CI~
            UALLOCCHK(pc,UALLOC_FAILED);                           //~V67CI~
        	if (!fread(pc,(UINT)(cmdlen+1),1,Pfh))                 //~V705R~
            	return 16;                                         //~V67CI~
            psckt->SCKTcmd=pc;                                     //~V67CI~
            psckt->SCKTcmdlen=(USHORT)cmdlen;                      //~V67CI~
          }                                                        //~V67CI~
          else                                                     //~V67CI~
          {                                                        //~V67CI~
        	if (!fread(wkbuff,sizeof(wkbuff),1,Pfh))               //~V48fI~
            	return 16;                                         //~V48fI~
            if (cmdlen>sizeof(wkbuff))                             //~V48fI~
            	cmdlen=sizeof(wkbuff);                             //~V48fI~
            pc=UALLOCC(1,(UINT)cmdlen+1);   //last is stopper      //~V48iR~
            UALLOCCHK(pc,UALLOC_FAILED);                           //~V48fI~
            psckt->SCKTcmd=pc;                                     //~V48fI~
            psckt->SCKTcmdlen=(USHORT)cmdlen;                      //~V48iR~
            memcpy(pc,wkbuff,(UINT)cmdlen);                        //~V48fI~
          }                                                        //~V67CI~
        }                                                          //~V48fI~
    }                                                              //~V48fI~
    memcpy(Gkbdsckt,wsckt,sizeof(Gkbdsckt));                       //~V48fI~
    filesetupalct();    //setup alias cmd tbl                      //~V67CM~
    return 0;                                                      //~V48fI~
}//kbdrsckt                                                        //~V48fI~
                                                                   //~V48fI~
#ifdef UNX                                                         //~v20bI~
  #ifndef XXE                                                      //~V64aI~
//**************************************************************** //~v20bI~
//* ukbdl_init interface                                           //~v20bI~
//* parm1 :exec option from xemainl                                //~v20bI~
//* retrn:none                                                     //~v20bI~
//**************************************************************** //~v20bI~
void kbdukbdlintf(int Popt)                                        //~v20bI~
{                                                                  //~v20bI~
    UCHAR usekey[MAXPFKNO][4];    //f1-f12,plain,shift,control,alt //~v20bI~
    KEYTBL  *pktfns,*pktfne;                                       //~v20bR~
    int keytype,ii,jj;                                             //~v20bI~
//*********************                                            //~v20bI~
//*get key assign info                                             //~v20bI~
    memset(usekey,0,sizeof(usekey));                               //~v20bI~
    kbdgetktgrp(0,&pktfns,&pktfne);    //Fn key start and end addr //~v20bI~
    for (ii=0;ii<MAXPFKNO;ii++,pktfns++)                           //~v20bI~
    	for (jj=0;jj<4;jj++)                                       //~v20bI~
#ifndef KKK                                                        //~vb50I~
    		if (kbdftsrch(0,pktfns,jj,&keytype)) //plain,shift,alt,ctl//~vb50I~
            	usekey[ii][jj]=1;	//used                         //~vb50I~
            else                                                   //~vb50I~
    		if (kbdftsrch(KFSO_FTSHIFT,pktfns,jj,&keytype)) //plain,shift,alt,ctl//~vb50I~
            	usekey[ii][jj]=1;	//used                         //~vb50I~
#else                                                              //~vb50I~
    		if (kbdftsrch(pktfns,jj,&keytype)) //plain,shift,alt,ctl//~v20bI~
            	usekey[ii][jj]=1;	//used                         //~v20bI~
#endif                                                             //~vb50I~
//*keyboard string assign                                          //~v20bI~
    ukbdl_init(Popt,(UCHAR*)usekey);                               //~v20bR~
    return;                                                        //~v20bI~
}//kbdukbdlintf                                                    //~v20bR~
  #endif                                                           //~V64aI~
//#else                                                            //~v78NR~
#endif //UNX                                                       //~v78NR~
#ifndef XXE	//from xeopt_rctl                                      //~va90I~
//**************************************************************** //~V55cR~
//kbdchngstatus                                                    //~V55cR~
// change rctl use status                                          //~V55cR~
//**************************************************************** //~V55cR~
void kbdchngstatus(int Popt)                                       //~V55cR~
{                                                                  //~V55cR~
//*********************                                            //~V55cR~
    if (Popt)   //rctl use                                         //~V55cI~
    	USBITON(Skbdinfo.fsMask,KEYBOARD_SHIFT_REPORT);            //~V55cR~
    else                                                           //~V55cI~
    	USBITOFF(Skbdinfo.fsMask,KEYBOARD_SHIFT_REPORT);           //~V55cI~
    ukbdsetstatus(&Skbdinfo);                                      //~V55cR~
    return;                                                        //~V55cR~
}//kbdchngstatus                                                   //~v78NR~
//#endif //!UNX                                                    //~v78NR~
#endif //XXE                                                       //~va90I~
//**************************************************               //~V48fI~
//*shortcut key prefix                                             //~V48fR~
//*parm1:pcw                                                       //~V48fI~
//*ret  :rc                                                        //~V48fI~
//**************************************************               //~V48fI~
int func_shortcut(PUCLIENTWE Ppcw)                                 //~V48fI~
{                                                                  //~V48fI~
//**********************                                           //~V48fI~
    if (!Spftkeycmd)                                               //~V48fR~
    	return kbderrscna();                                       //~V48fI~
	Sshortcutstatus=KBD_SC_PEND;                                   //~V48fR~
    uerrmsg("ShortCutKey input mode",0);                           //~V48fR~
	return 0;                                                      //~V48fI~
}//func_shortcut                                                   //~V48fI~
//**************************************************               //~V48fI~
//*display shortcut(accept when double hit of shortcut key)        //~V48fI~
//*parm1:pcw                                                       //~V48fI~
//*ret  :rc                                                        //~V48fI~
//**************************************************               //~V48fI~
int func_shortcutquery(PUCLIENTWE Ppcw)                            //~V48fI~
{                                                                  //~V48fI~
//**********************                                           //~V48fI~
    if (!Spftkeycmd)                                               //~V48fI~
    	return kbderrscna();                                       //~V48fI~
	Sshortcutstatus=(KBD_SC_PEND|KBD_SC_QUERY);                    //~V48fI~
    uerrmsg("ShortCutKey query mode",0);                           //~V48fI~
	return 0;                                                      //~V48fI~
}//func_shortcut                                                   //~V48fI~
//**************************************************               //~V48fI~
int kbderrscna(void)                                               //~V48fI~
{                                                                  //~V48fI~
    uerrmsg("KEY command is not defined,ShortCut function is not avail",0);//~V48fI~
	return 4;                                                      //~V48fI~
}//kbderrscna(void)                                                //~V48fI~
#ifndef KKK                                                        //~vb50M~
//**************************************************************** //~vb50M~
//*check key string S+A+ and S+C+                                  //~vb50M~
//*rc:1:S+A,S+C,0: other                                           //~vb50R~
//**************************************************************** //~vb50M~
int xekbdchkSAC(int Popt,char *Pstr,KEYTBL **Pppkt,int *Ppshiftid) //~vb50R~
{                                                                  //~vb50M~
	int rc=0;                                                      //~vb50I~
	int shiftid=0;                                                 //~vb50M~
    KEYTBL *pkt=0;                                                 //~vb50M~
//***********************                                          //~vb50M~
  	if (*(Pstr+1)=='+' && *(Pstr+3)=='+'	//2 modifier           //~vb50M~
  	&&  toupper(*Pstr)=='S')                                       //~vb50M~
  	{                                                              //~vb50M~
    	rc=1;                                                      //~vb50I~
		shiftid=kbdsrchktbyname(Pstr+2,&pkt);                      //~vb50M~
    	if (pkt && !KBD_EXTENDED_KEY(pkt->KTkey[0])) //not extended key//~vb50R~
    	{                                                          //~vb50M~
    		uerrmsg("err(%s), S+A or S+C is allowed to extended key only.",//~vb50M~
    				"エラー(%s), S+A と S+C は文字キーでない拡張キーにのみ指定できます",//~vb50M~
                	Pstr);                                         //~vb50M~
        	pkt=0;                                                 //~vb50M~
        }                                                          //~vb50M~
    }                                                              //~vb50M~
    else                                                           //~vb50I~
	if (Popt & XEKBDCKSACO_SRCHNONSAC) //       0x01 //search even if not SAC//~vb50I~
    {                                                              //~vb50I~
		shiftid=kbdsrchktbyname(Pstr,&pkt);                        //~vb50I~
    }                                                              //~vb50I~
    *Pppkt=pkt;                                                    //~vb50M~
    *Ppshiftid=shiftid;                                            //~vb50I~
    UTRACEP("%s:rc=%d,Pstr=%s,shiftid=%d,pkt=%p\n",UTT,rc,Pstr,shiftid,pkt);    //~vb50R~//~vbv8R~
    return rc;                                                     //~vb50R~
}//xekbdchkSAC                                                     //~vb50I~
//**************************************************************** //~vb50M~
//*set prefix S+A+ and S+C+                                        //~vb50M~
//*rc:fldlen                                                       //~vb50M~
//**************************************************************** //~vb50M~
int xekbdsetSAC(int Popt,int Pshiftid,KEYTBL *Ppkt,char *Pkeyname) //~vb50I~
{                                                                  //~vb50M~
    KEYTBL *pkt;                                                   //~vb50M~
    int len;                                                       //~vb50M~
//***********************                                          //~vb50M~
    pkt=Ppkt;                                                      //~vb50M~
	if (Popt & XEKBDSACO_NOSTRZ) //    0x01 //no output strz       //~vb50R~
    {                                                              //~vb50M~
    	sprintf(Pkeyname,"S+%c+",*Skeyshiftname[Pshiftid]);        //~vb50I~
		if (Popt & XEKBDSACO_JP) //                                //~vb50I~
        {                                                          //~vb50I~
	    	len=(int)strlen(pkt->KTnamej);                         //~vb50I~
        	memcpy(Pkeyname+4,pkt->KTnamej,(size_t)len);           //~vb50I~
        }                                                          //~vb50I~
        else                                                       //~vb50I~
        {                                                          //~vb50I~
	    	len=(int)strlen(pkt->KTnamee);                         //~vb50I~
        	memcpy(Pkeyname+4,pkt->KTnamee,(size_t)len);           //~vb50R~
        }                                                          //~vb50I~
        len+=4;                                                    //~vb50M~
    }                                                              //~vb50M~
    else                                                           //~vb50M~
    {                                                              //~vb50I~
		if (Popt & XEKBDSACO_JP) //                                //~vb50I~
    		len=sprintf(Pkeyname,"S+%c+%s",*Skeyshiftname[Pshiftid],pkt->KTnamej);//~vb50I~
        else                                                       //~vb50I~
    		len=sprintf(Pkeyname,"S+%c+%s",*Skeyshiftname[Pshiftid],pkt->KTnamee);//~vb50R~
    }                                                              //~vb50I~
    return len;                                                    //~vb50M~
}//xekbdsetSAC                                                     //~vb50I~
#endif                                                             //~vb50M~
