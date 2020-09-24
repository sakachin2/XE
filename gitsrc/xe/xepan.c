//*CID://+vbmiR~: update#=  338;                                   //~vbmiR~
//*************************************************************
//*xepan.c *
//************************************************************* //~5610I~
//vbmi:180807 (W32:Bug)top panel LC line is corrupted,use not OutputW but OutputCharacterW.(See v6C8)//~vbmiI~
//vb4h:160804 fnm list reverse len is short because strlen stop by 00 of dbcs unicode//~vb4hI~
//vb4f:160802 (ULIB:v6Ei)specify ligature on/off,combine on/of line by line(used for edit/filename  panel)//~vb4fI~
//vb4c:160730 display altch for also cmdline                       //~vb4cI~
//vb3g:160607 (W32)by vb3f attr input fld have to be not attrflag but attr fld to keep attrflag=0//~vb3gI~
//vb3e:160607 by ulib:v6D8, draw menu "LC : " line by NoLigature(ignore ligature mode)//~vb3eI~
//vb30:160411 (LNX)Compiler warning                                //~vb30I~
//vb2Z:160405 See ulib:v6c8;on chcp 54936,top menu "LC :" line leaves dbcs.//~vb2ZI~
//vb2Y:160405 by vb2U string remains on screen when split screen or exit xe if ligature mode ON//~vb2YI~
//vb2W:160404 W32 64 compiler warning                              //~vb2WI~
//vb2U:160404 (Win)wxe:invalid disply of lc name on top menu when /Czh_CN.54936//~vb2LI~
//vb2L:160314 (W32) display lang on top menu by ddfmt(for the case consolecp!=system cp,cpinfo is by system cp but display is by chcp code)//~vb2LI~
//vb2F:160229 W32 64 compiler warning                              //~vb2FI~
//vaz8:150109 C4244 except ULPTR and ULONG                         //~vaz8I~
//vaw3:140526 (Win:UNICODE)hex kbd for 3byte unicode               //~vaw3I~
//vaib:130528 Bug:when resize(wxe/gxe/Axe(orientation change)) cmd input line text disappears.//~vaibI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//vaar:120101 over vaap;not by padding but position for ddfmt also for locale dbcs(contains "d")//~vaarI~
//vaap:111231 (BUG)pansetcmdattr;if shrinked by l2dd codetbl shoukld be shrink//~vaapI~
//            so back to padding for csr positioning. if not mixed it is originary not shrinked//~vaapI~
//vaan:111230 another way of vaak;column positioning by ddfmt(USDdata and USDdbcs)//~vaanI~
//vaak:111229 (Bug)va5j: if traslated l2u for cmdline,coloumn pos changes. csrright will split local dbcs and rep to space.//~vaakI~
//vaa2:110917 (BUG)abend if screen hight is lower than ppd defined line//~vaa2I~
//va5j:100510 dispaly cmdline by dd fmt(more printable than locale code for Ctl+w(copy word to cmd lien).//~va5jI~
//va3K:100316 allow unicode hex input on cmdline                   //~va3KI~
//va1z:091112 help msg of "d" key on filename list                 //~va1zI~
//va1c:091030_merge GB18030 support                                //~va1cI~
//va11:091009_(BUG) cmdline display on not file panel;dbcs attr is split for boundary UTF8 code//~va11I~
//va10:091008!(XXE) treate input string as UTF8 or LOCALE for a line//~va10I~
//                      GUM2_KBDU2L,GUM2_KBDL2U-->GUM2_KBDUTF8 on/off//~va10I~
//va0x:090920!kbd mode change(A+u)                                 //~va0xI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          cmdline may be mixed of utf8 and locale code           //~va00I~
//          filename list is mixed of utf8 and locale code         //~va00I~
//v79z:080916 DBCS tbl for C and K of CJK                          //~v79zI~
//            (display locale on top menu)                         //~v79zI~
//v8@i:080619 TSO:"=6.TSOxx" support                               //~v8@iI~
//v77H:080204 (BUG)dirlist protected fld width dose not expand by resize//~v77HI~
//v77C:080129*english spell chk                                    //~v772I~
//v772:071121*(BUG)filenamelist curdir is not updated just after cd(.) cmd on dirlist//~v772I~
//v76v:070806 (BUG)cmd err reverse lenset err                      //~v76vI~
//v76m:070627 find support on =1/=2 filename list panel            //~v76mI~
//v76g:070620 utility panel(3.14:grep and 3.12:compare);f5:open dirlist, dlcmd "^":send//~v76gI~
//v730:061225 use UPLbuff for cmdline(to display as long as possible if del key used, and accept insert over screen width)//~v730I~
//v65c:050728 (XXE)8 color->16 color                               //~v658I~
//v658:050727 (LNX)console allow color change but gnome terminal dose not//~v658I~
//            so accept input the issue errmsg for pallette color change input//~v658I~
//v657:050727 (W32)del color palette change line because Win console dose not support palette change//~v64hI~
//            and color level is 2+intencity.                      //~v64hI~
//v64i:050619 (LNX)xxe support;scr width                           //~v64hI~
//v64h:050619 (LNX)xxe support;abondon v64g to share xe_save_ with non xxe version(Gpalette is saved and restored)//~v64hI~
//v64g:050619 (LNX)xxe support;color-no 8-->16                     //~v64gI~
//v64c:050619 (UNX:BUG)long host name is shortened                 //~v64cI~
//v61r:050302 keep edit or browse id on filename queue             //~v61rI~
//v59T:041207 dirlist resizeing                                    //~v59TI~
//v57G:040612 except DOSDOS;expand max lrecl 999-->9999(also gauge)//~v57GI~
//v557:040203 filename list multi-page support                     //~v557I~
//v54v:040114 display and select by cursor the driveid list.       //~v54vI~
//v51V:030808 v51A is for UNX;for WXE abend when scr size is shorten.//~v51VI~
//            (us Gscrbuffwidth for other than WXE)                //~v51VI~
//v51A:030711 abend when start screen size is narrow               //~v51AI~
//v500:020827 wxe support                                          //~v500I~
//     020922 upcbuff copy needed after resize init                //~v500I~
//            for scr resize(scrwidth/height buff and current)     //~v500I~
//     021116 dir plh length should not by scrwidth,fixed length   //~v500I~
//v48s:020507 (AIX)set title color to light-blue(GB) for dtterm    //~v48sI~
//v48f:020504 more key for macro function(not only PFn but also A+q,A+a and 1 byte char)//~v48fI~
//v42p:011008 hostname on also pannel 1/2(history file list)       //~v42pI~
//v41v:010908 UNX:hostname display                                 //~v41vI~
//v20y:001028 new function:filename selection on menu 1/2 name list//~v20yI~
//v20u:001022 LINUX support(drop drive line from filename panel)   //~v20uI~
//v20r:001015 protect color value input when color change not avail//~v20rI~
//v20q:001015 max color number display on panel 0.0                //~v20qI~
//v20p:001015 LINUX support(color panel max color=8)               //~v20pI~
//v11j:990718 display on menue 'a'-'c' shortID for '0.1'-'0.3'     //~v11jI~
//v0ja:980721 change define value by change opt start from 0.0     //~v0jaI~
//v0iw:980718 pfk cmd support(del 0.5,cmd change by ini only)      //~v0iwI~
//v0io:980702 pfk cmd support(opt 0.4)                             //~v0ioI~
//v0im:980625 pfk cmd support(optk1 and optk2)                     //~v0imI~
//v0if:980620 pfk cmd support                                      //~v0ifI~
//v0hc:980126 (BUG)word pallette-->palette                         //~v0hcI~
//v08b:961103:(BUG)when first split popupped,UCWpsd point 1st half of USD//~v08bI~
//                 but USDpfld etc is of 2nd half which disppeared.//~v08bI~
//                 for win95 it may be page freed cause c0000005.  //~v08bI~
//v085:961024:W95 VC                                               //~v085I~
//v07s:960825:new ulib.h/ulibdef.h(no need base def by os2.h)      //~v07sI~
//            to speed up compile,drop include(caused by WIN95 modify)//~v07sI~
//v07a:960615:allow dup key assign to differrent function for only on of assigned key//~v07aI~
//            color option-2                                       //~v07aI~
//              -field next value function for color register field//~v07aI~
//v079:960610:color option-2                                       //~v079I~
//            .display current RGB value                           //~v079I~
//            .(BUG)field full err when insert mode                //~v079I~
//v075:960608:color option                                         //~v075I~
//v06t:960406:cmd so screen:append cmd result                         //~v06tI~
//v04d:950930:malloc/calloc rc chk for dos                      //~v04dI~
//v03z:950903:attrib cmd                                        //~v03zI~
//*v039:950728:bug,setflddata need set dbcstbl also(getfldpos parm chng)//~v039I~
//*v032:950712:UFLD for each ppc                                //~v032I~
//*v030:950709:dir2                                             //~v030I~
//*950610 v020 dir support                                      //~v020R~
//*950616 v020 reverse err field                                //~v020I~
//*950628 v020 err reverse only data len                        //~v020I~
//*950708 v020 change dir support                               //~v020I~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifdef DOS
#else
//  #define INCL_BASE                                              //~v07sR~
//  #include <os2.h>                                               //~v07sR~
#endif
#ifdef W32                                                         //~vb4fI~
	#include <windows.h>                                           //~vb4fI~
#endif                                                             //~vb4fI~
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <uque.h>
#include <ufile.h>                                              //~5318R~
#include <ualloc.h>                                             //~5318I~
#include <utrace.h>                                                //~v79zI~
#include <udbcschk.h>                                              //~v79zI~
#ifdef UTF8SUPPH                                                   //~va00I~
	#include <utf.h>                                               //~va00I~//~va0xR~
	#include <utf22.h>                                             //~va5jI~
#endif                                                             //~va00I~
#define UVIOMDEFONLY	//for uviom.h                              //~vb4fI~
#include <uviom.h>                                                 //~vb4fI~
                                                                //~5318I~
#include "xe.h"
#include "xescr.h"
#include "xecsr.h"
#include "xepan.h"
#include "xepan2.h"                                             //~v020I~
#include "xefile.h"                                             //~5318I~
#include "xepan22.h"                                               //~v20yM~
#include "xechar.h"                                             //~5124I~
#include "xesub.h"                                              //~5318I~
#include "xesub2.h"                                                //~va1cR~
#include "xegbl.h"                                                 //~v20qI~
#include "xeopt.h"                                                 //~v79zI~
#ifdef UTF8SUPPH                                                   //~va00I~
	#include "xeutf.h"                                             //~va00I~
	#include "xeutf2.h"                                            //~va5jI~
#endif                                                             //~va00I~
                                                                //~5610I~
//*******************************************************       //~v032I~
//#ifdef WXE                                                       //~v64hR~
//    #define FIXEDLEN    80                                       //~v64hR~
////  #define FIXEDLENID  0x02                                     //~v64hR~
//#endif                                                           //~v64hR~
#define NULLINIT1  0,0,0
#define NULLINIT2    0,0
//*******************************************************
//*pannel definition                                            //~5610R~
//*first byte  is used as clear char(not data part) ***         //~5611R~
//*"\" break first and second half(second half is right justified)***//~v76gR~
//*\x01 is one of 0x00(to avoid to assumed as string terminator)   //~v20yR~
//*for prot data:0 mean protected field having no UFLE          //~5611R~
//*             :1 mean protected field start having UFLE(for set display data)//~v76gR~
//*              last  byte  is assume continue to end of line  //~5610I~
//*******************************************************       //~5610I~
                                                                //~5610I~
static UCHAR Sdelm[]="  ";		//space                         //~5611I~
                                                                //~5611I~
static UCHAR Spcmd[] ="0000 \\0";                               //~5611I~
static UCHAR Spcmd2[]="0000 \\00000    0";//prot 0x01           //~5611I~
                                                                //~5611I~
//*** PANNEL MENU 0
static UCHAR Sm0_0[]="--------------- MENU ";
static UCHAR Sm0_1[]="\0===>";	//initial null value
//atic UCHAR Sdelm[]="  ";		//space                         //~5611I~
//atic UCHAR Sdelm[]="  ";		//space                         //~5611I~
#ifdef UNX                                                         //~v41vI~
//static UCHAR Sm040[81]="                                                    hostname = ";//~v64cR~
static UCHAR Sm040[81]="                                     hostname = ";//~v64cR~
#else                                                              //~v41vI~
#endif                                                             //~v41vI~
static UCHAR Sm0_4[]="    0  PARM         - Parameter Change";
static UCHAR Sm041[]="       0.0 (0) COLOR    - Palette and Color";//~v11jR~
//static UCHAR Sm042[]="       0.1 (A) Fn-CMD   - Assing cmd-string to PFkey";//~v48fR~
static UCHAR Sm042[]="       0.1 (A) SC-CMD   - Assign cmd-string to Short-Cut key";//~v772R~
static UCHAR Sm043[]="       0.2 (B) FUNC-KEY - Change Key Assignment";//~v11jR~
static UCHAR Sm044[]="       0.3 (C) KEY-FUNC - Browse Key List";  //~v11jR~
//static UCHAR Sm045[]="       0.5  CMDVERB - Change command verb";//~v0iwR~
//static UCHAR Sm0_5[]="    1  BROWSE       - Display File(";      //~vbdqR~
static UCHAR Sm0_5[]="    1  BROWSE       - Display File (MRU list)";//~vbdqI~
//static UCHAR Sm0_6[]="    2  EDIT         - Edit/Create File";   //~vbdqR~
static UCHAR Sm0_6[]="    2  EDIT         - Edit File    (MRU list)";//~vbdqI~
static UCHAR Sm061[]="    3  UTILITY";                             //~v76gI~
static UCHAR Sm062[]="       3.12(F) COMPARE  - File/Directory Compare";//~v76gR~
static UCHAR Sm063[]="       3.14(G) SEARCH   - Grep Search";      //~v76gR~
static UCHAR Sm0_7[]="    6  COMMAND      - Edit Command Result";     //~v06tR~
#ifdef FTPSUPP                                                     //~v8@iM~
static UCHAR Sm071[]="       6.dest           - Open remote shell to the destination";//~v8@iR~
#endif                                                             //~v8@iM~
static UCHAR Sm0_8[]="    X  EXIT         - Save and Split End";//~5224R~
static UCHAR Sm0_9[]="    R  RETURN       - Save and Exit";     //~5503R~
static UCHAR Sm0_a[]="    Q  QUIT         - Quit and Exit";     //~5224R~
#define LOCALEPREFIX "LC : "                                       //~v79zI~
#ifdef WCSUPP                                                      //~v79zI~
static UCHAR Sm0_b[81]="          " LOCALEPREFIX ;                 //~v79zR~
#endif                                                             //~v79zI~

static UPANELD Smenu0[]={//data ptr,type,protdata,pfld
						{Sm0_0,USDF2PROT,NULL ,NULLINIT1},
					 	{Sm0_1,USDF2CMD ,Spcmd,NULLINIT1},
//  				 	{Sdelm,USDF2PROT,NULL ,0},                 //~v0ifR~
#ifdef UNX                                                         //~v41vI~
					 	{Sm040,USDF2PROT,NULL ,NULLINIT1},                 //~v41vI~
#else                                                              //~v41vI~
					 	{Sdelm,USDF2PROT,NULL ,NULLINIT1},              //~5611R~
#endif                                                             //~v41vI~
					 	{Sm0_4,USDF2PROT,NULL ,NULLINIT1},
					 	{Sm041,USDF2PROT,NULL ,NULLINIT1},                 //~v0ifI~
					 	{Sm042,USDF2PROT,NULL ,NULLINIT1},                 //~v0ifI~
					 	{Sm043,USDF2PROT,NULL ,NULLINIT1},                 //~v0imI~
					 	{Sm044,USDF2PROT,NULL ,NULLINIT1},                 //~v0ioI~
//  				 	{Sm045,USDF2PROT,NULL ,0},                 //~v0iwR~
					 	{Sm0_5,USDF2PROT,NULL ,NULLINIT1},
					 	{Sm0_6,USDF2PROT,NULL ,NULLINIT1},
					 	{Sm061,USDF2PROT,NULL ,NULLINIT1},         //~v76gI~
					 	{Sm062,USDF2PROT,NULL ,NULLINIT1},         //~v76gI~
					 	{Sm063,USDF2PROT,NULL ,NULLINIT1},         //~v76gI~
					 	{Sm0_7,USDF2PROT,NULL ,NULLINIT1},
#ifdef FTPSUPP                                                     //~v8@iI~
					 	{Sm071,USDF2PROT,NULL ,NULLINIT1},         //~v8@iI~
#endif                                                             //~v8@iI~
					 	{Sm0_8,USDF2PROT,NULL ,NULLINIT1},
					 	{Sm0_9,USDF2PROT,NULL ,NULLINIT1},              //~5224I~
					 	{Sm0_a,USDF2PROT,NULL ,NULLINIT1},              //~5224I~
#ifdef WCSUPP                                                      //~v79zI~
					 	{Sdelm,USDF2PROT,NULL ,NULLINIT1},         //~v79zI~
					 	{Sm0_b,USDF2PROT,NULL ,NULLINIT1},         //~v79zI~
#endif                                                             //~v79zI~
					 	{0,0,0,NULLINIT1}				//terminater
						};
                                                                //~5610I~
//*** PANNEL OPTION(COLOR)                                         //~v075I~
static UCHAR Sm1_0[]="-OPTION - 1 ---- COLOR ";                    //~v075R~
//atic UCHAR Sm1_1[]="\0===>";	//initial null value               //~v075R~
//atic UCHAR Sdelm[]="  ";		//space                            //~v075I~
static UCHAR Sm1_3[]="**Palette number assign (0 to 15) ";	//initial null value//~v0hcR~
static UCHAR Sm1_4[]="    Part of screen  palette no.             sample";//~v0hcR~
static UCHAR Sm1_5[]="                    FG / BG (curr.,default)";//~v075R~
#ifdef AIX                                                         //~v48sI~
static UCHAR Sm1_6[]="-   Title-Line      \x01\x01\x01/ \x01\x01\x01( 3/ 0,  3/ 0 ) ------- MENU ----------";//~v48sI~
#else                                                              //~v48sI~
static UCHAR Sm1_6[]="-   Title-Line      \x01\x01\x01/ \x01\x01\x01(15/ 1, 15/ 1 ) ------- MENU ----------";//~v079R~
#endif                                                             //~v48sI~
static UCHAR Sm1_7[]="    Panel-Frame     \x01\x01\x01/ \x01\x01\x01( 7/ 0,  7/ 0 ) ===>command line etc.";//~v079R~
static UCHAR Sm1_8[]="    Browse-Lineno   \x01\x01\x01/ \x01\x01\x01( 2/ 0,  2/ 0 ) 0001000| Browse  screen";//~v079R~
static UCHAR Sm1_9[]="    Browse-File     \x01\x01\x01/ \x01\x01\x01( 7/ 0,  7/ 0 )";//~v079R~
static UCHAR Sm1_a[]="    Edit-Lineno     \x01\x01\x01/ \x01\x01\x01( 2/ 0,  2/ 0 ) 0001000| Edit    screen";//~v079R~
static UCHAR Sm1_b[]="    Edit-File       \x01\x01\x01/ \x01\x01\x01(14/ 0, 14/ 0 )";//~v079R~
static UCHAR Sm1_c[]="    DirList-Linecmd \x01\x01\x01/ \x01\x01\x01(14/ 0, 14/ 0 ) _003|||. DIRLIST  EXE";//~v079R~
static UCHAR Sm1_d[]="    DirList-Lineno  \x01\x01\x01/ \x01\x01\x01( 2/ 0,  2/ 0 )";//~v079R~
static UCHAR Sm1_e[]="    DirList-File    \x01\x01\x01/ \x01\x01\x01( 7/ 0,  7/ 0 )";//~v079R~
static UCHAR Sm1_f[]="    CmdOut-Lineno   \x01\x01\x01/ \x01\x01\x01( 2/ 0,  2/ 0 ) 19:55 ===>> dir";//~v079R~
static UCHAR Sm1_g[]="    CmdOut-Result   \x01\x01\x01/ \x01\x01\x01(14/ 8, 14/ 8 )  Volume in drive G has no label.";//~v079R~
//                                        __ / __ (15/ 1, 15/ 1 )  //~v079I~
//atic UCHAR Sdelm[]="  ";		//space                            //~v075I~
//static UCHAR Sm1_i[]="**Palette color (0 to 3 for R G B each). ";//~v20qR~
static UCHAR Sm1_i[]="**Palette color (0 to 3 for R G B each). MAXCOLOR=% .";//edit maxcolor//~v20qI~
static UCHAR Sm1_j[]="    Palette  -->  0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15";//~v0hcR~
static UCHAR Sm1_k[]="    color    --> ";                          //~v075I~
#ifdef WINCON  //w32 console mode	//fixed palete i-r-g-b 4 bit for bg and fg//~v64hI~
static UCHAR Sm1_l[]="\0   RGB value-->000 002 020 022 200 202 220 222 111 003 030 033 300 303 330 333";//~v657R~
//                                     bla blu gre sky red pur yel whi gra blu gre sky red pur yel whi//~v657R~
#else                                                              //~v657R~
static UCHAR Sm1_l[]="\0   RGB value-->000";                       //~v079R~
static UCHAR Sm1_m[]="\0   current  -->";                          //~v079R~
static UCHAR Sm1_n[]="\0   standard -->";                          //~v079R~
#endif                                                             //~v657R~
                                                                   //~v075I~
static UCHAR Sppal[]= "0000000000000000000  000  00110110";	//pallet number//~v075R~
static UCHAR Sppas[]= "0000000000000000000  000  001101100000000001";	//pallet number//~v075R~
                                                                   //~v20pI~
#define COLOR_NUM_INPUT_POS 19     //start of pallet 1--7          //~v20rM~
#ifdef UNX                                                         //~v20pI~
  	#ifdef XXE                                                     //~v658R~
static UCHAR Spcol[]= "0000000000000001110   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0";//~v658R~
  	#else                                                          //~v658R~
static UCHAR Spcol[]= "0000000000000001110   0   0   0   0   0   0   011101110111011101110111011101110";//pal 0--7//~v20pR~
  	#endif                                                         //~v658R~
#else  //!UNX                                                      //~v20pI~
static UCHAR Spcol[]= "0000000000000001110   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0";//~v075R~
#endif //!UNX                                                      //~v20pI~
                                                                   //~v20pI~
static UCHAR Spccl[]= "0000000000000001110111011101110111011101110111011101110111011101110111011101110";//~v075R~
                                                                   //~v075I~
static UPANELD Smenu1[]={//data ptr,type,protdata,pfld             //~v075I~
						{Sm1_0,USDF2PROT,NULL ,NULLINIT1},                 //~v075I~
					 	{Sm0_1,USDF2CMD ,Spcmd,NULLINIT1},                 //~v075R~
					 	{Sdelm,USDF2PROT,NULL ,NULLINIT1},                 //~v075I~
					 	{Sm1_3,USDF2PROT,NULL ,NULLINIT1},                 //~v075I~
					 	{Sm1_4,USDF2PROT,NULL ,NULLINIT1},                 //~v075I~
					 	{Sm1_5,USDF2PROT,NULL ,NULLINIT1},                 //~v075I~
					 	{Sm1_6,0        ,Sppas,NULLINIT1},                 //~v075R~
					 	{Sm1_7,0        ,Sppas,NULLINIT1},                 //~v075R~
					 	{Sm1_8,0        ,Sppas,NULLINIT1},                 //~v075R~
					 	{Sm1_9,0        ,Sppal,NULLINIT1},                 //~v075I~
					 	{Sm1_a,0        ,Sppas,NULLINIT1},                 //~v075R~
					 	{Sm1_b,0        ,Sppal,NULLINIT1},                 //~v075I~
					 	{Sm1_c,0        ,Sppas,NULLINIT1},                 //~v075R~
					 	{Sm1_d,0        ,Sppal,NULLINIT1},                 //~v075I~
					 	{Sm1_e,0        ,Sppal,NULLINIT1},                 //~v075I~
					 	{Sm1_f,0        ,Sppas,NULLINIT1}, //15            //~v075R~
					 	{Sm1_g,0        ,Sppas,NULLINIT1}, //16            //~v075R~
					 	{Sdelm,USDF2PROT,NULL ,NULLINIT1}, //17            //~v075R~
					 	{Sm1_i,USDF2PROT,NULL ,NULLINIT1}, //18            //~v075R~
					 	{Sm1_j,USDF2PROT,NULL ,NULLINIT1}, //19            //~v075R~
					 	{Sm1_k,0        ,Spccl,NULLINIT1}, //20 color      //~v075I~
					 	{Sm1_l,0        ,Spcol,NULLINIT1}, //21 input      //~v075R~
#ifdef WINCON  //w32 console mode                                  //~v657I~
					 	{Sdelm,USDF2PROT,NULL ,NULLINIT1},         //~v657M~
					 	{Sdelm,USDF2PROT,NULL ,NULLINIT1},         //~v657M~
#else                                                              //~v657I~
					 	{Sm1_m,0        ,Spccl,NULLINIT1}, //22 current    //~v075R~
					 	{Sm1_n,0        ,Spccl,NULLINIT1}, //23 default    //~v075I~
#endif                                                             //~v657R~
					 	{0,0,0,NULLINIT1}				//terminater               //~v075I~
						};                                         //~v075I~
                                                                   //~v075I~
//**PANEL BROWSE ************
//static UCHAR Sm10_0[]="-BROWSE\\ xxx-(001)-xxx    ";             //~v57GR~
static UCHAR Sm10_0[]=  "-BROWSE\\ xxxx(0001)xxxx    ";            //~v57GR~
static UCHAR Sm10_1[]="\0===>\\\x01===>PAGE\x01"; //0x01 may repl by 0x00
static UCHAR Sm10_2[]=" ";
static UCHAR Spbrowse[]= "       00";	//prot data for browse line

static UPANELD Smenu10[]={
						{Sm10_0,USDF2PROT,NULL  ,	NULLINIT1},//hdr line
					 	{Sm10_1,USDF2CMD ,Spcmd2,	NULLINIT1},//cmd line
					 	{Sm10_2,0        ,Spbrowse,	NULLINIT1},//browse line
					 	{0,0,0,NULLINIT1}				//terminater
						};
                                                                //~5610I~
//**PANEL EDIT   ************
//static UCHAR Sm20_0[]="-EDIT--\\ xxx-(001)-xxx    ";             //~v57GR~
static UCHAR Sm20_0[]=  "-EDIT--\\ xxxx(0001)xxxx    ";            //~v57GR~
static UCHAR Sm20_1[]="\0===>\\\x01===>HALF\x01";
static UCHAR Sm20_2[]="\0";
static UCHAR Spedit[]=   "       0 ";	//prot data for edit line

static UPANELD Smenu20[]={
						{Sm20_0,USDF2PROT,NULL  ,NULLINIT1},
					 	{Sm20_1,USDF2CMD ,Spcmd2,NULLINIT1},
					 	{Sm20_2,0        ,Spedit,NULLINIT1},
					 	{0,0,0,NULLINIT1}				//terminater
						};
                                                                //~5610I~
//* file name input *********                                   //~5610I~
static UCHAR Sm30_0[]="-";                                      //~5611R~
static UCHAR Sm30_1[]="\0===>";	//initial null value            //~5611I~
//atic UCHAR Sdelm[]="  ";		//space                         //~5611I~
static UCHAR Sm30_3[]="\0   FILE NAME ===>\\\x01";              //~5611R~
//atic UCHAR Sdelm[]="  ";		//space                         //~5611I~
                                                                   //~v20uI~
#ifdef UNX                                                         //~v20uI~
#else  //!UNX                                                      //~v20uI~
static UCHAR Sm30_5[]="\0   DRIVE     ===>\x01:";               //~v020R~
#endif //!UNX                                                      //~v20uI~
                                                                   //~v20uI~
//atic UCHAR Sdelm[]="  ";		//space                         //~5611I~
static UCHAR Sm30_7[]="\0   DIRECTORY ===>\\\x01";              //~5611R~
//atic UCHAR Sdelm[]="  ";		//space                         //~5611I~
static UCHAR Sm30_9[]= "    Current   ---- ";                   //~5611R~
//static UCHAR Sm30_10[]="    Latest    ---- ";                      //~v557R~//~va1zR~
static UCHAR Sm30_10[]="    Latest    ----                     (line-cmd:\"?\"=help, \"d\":delete line)";//~va1zR~
//                      "00000000000000000011111111111111110";	//filename list entry count//~va1zI~
                                                                   //~v20yI~
static UCHAR Sm30_11[]="\0  ";                       //detail line //~v20yR~
                                                                   //~v20yI~
static UCHAR Spfhdr []= "1111110";		//browse/edit/file      //~5611R~
static UCHAR Spfname[]= "00000000000000000 \\0";	//filename  //~5611R~
                                                                   //~v20uI~
#ifdef UNX                                                         //~v20uI~
#else  //!UNX                                                      //~v20uI~
//static UCHAR Spdrive[]= "00000000000000000 0";	//drive        //~v54vR~
#ifdef AAA                                                         //~v54vM~
static UCHAR Spdrive[]= "00000000000000000 0"  \
	"0101010101010101010101010101010101010101010101010101";	//driveidlist fld(26fld)//~v54vR~
#else                                                              //~v54vI~
static UCHAR Spdrive[]= "00000000000000000 0"  \
	"01111111111111111111111111111111111111111111111111111";	//driveidlist fld(26byte)//~v54vR~
#endif                                                             //~v54vI~
#endif //!UNX                                                      //~v20uI~
                                                                   //~v20uI~
static UCHAR Spcurd []= "000000000000000001\\0";	//filename  //~5611R~
static UCHAR Sppgno []= "00000000000000000011111111111111110";	//filename list entry count//~v557R~
//                      "   Latest    ---- 111 - 111 of 111 ";     //~v557R~
                                                                   //~v20yI~
static UCHAR Spfnlist[]="0101\\0"; //1-byte input(initialy prot),1-byte prot,n-byte display fld//~v20yR~
                                                                //~5610I~
static UPANELD Smenu30[]={                                      //~5610I~
						{Sm30_0,USDF2PROTONLY,Spfhdr,NULLINIT1},        //~5611R~
					 	{Sm30_1,USDF2CMD ,Spcmd ,NULLINIT1},            //~5611R~
#ifdef UNX                                                         //~v42pI~
					 	{Sm040,USDF2PROT,NULL ,NULLINIT1},                 //~v42pI~
#else                                                              //~v42pI~
						{Sdelm ,USDF2PROT,NULL  ,NULLINIT1},            //~5611I~
#endif //!UNX                                                      //~v42pI~
					 	{Sm30_3,0        ,Spfname,NULLINIT1},           //~5611R~
//  					{Sdelm ,USDF2PROT,NULL  ,0},               //~v20yR~
#ifdef UNX                                                         //~v20uI~
#else  //!UNX                                                      //~v20uI~
					 	{Sm30_5,0        ,Spdrive,NULLINIT1},           //~5611R~
//  					{Sdelm ,USDF2PROT,NULL  ,0},               //~v20yR~
#endif //!UNX                                                      //~v20uI~
					 	{Sm30_7,0        ,Spfname,NULLINIT1},           //~5611R~
//  					{Sdelm ,USDF2PROT,NULL  ,0},               //~v20yR~
						{Sm30_9,USDF2PROTONLY,Spcurd,NULLINIT1},        //~5611R~
//  					{Sdelm ,USDF2PROT,NULL  ,NULLINIT1},       //~v557R~
						{Sm30_10,USDF2PROTONLY,Sppgno,NULLINIT1},  //~v557R~
						{Sm30_11,0       ,Spfnlist,NULLINIT1},//filename list//~v20yI~
					 	{0,0,0,NULLINIT1}				//terminater            //~5610I~
						};                                      //~5610I~
//* dir display     *********                                   //~v020I~
static UCHAR Sm31_0[]="-";                                      //~v020I~
//atic UCHAR Sm31_1[]="\0===>";	//initial null value            //~5628R~
static UCHAR Sm31_2[]="\0";                       //detail line //~v020I~
// top:clear char,0:const fld,1:initialy protected,' ':input fld   //~v51VI~
//                                1         2         3         4         5         6         7         8//~v51VI~
//                       12345678901234567890123456789012345678901234567890123456789012345678901234567890//~v51VI~
//*                      cnnnn|***********FILE-NAME***  ASHR  NEW=NAME//~v03zR~
#ifdef W32                                                         //~vb3gI~
static UCHAR Spdir  []= " 0000000000000000000000000000001111101                                         0"; //protect attrflag//~vb3gI~
#else                                                              //~vb3gI~
static UCHAR Spdir  []= " 0000000000000000000000000000011111101                                         0";//~v51VI~
#endif                                                             //~vb3gI~
//#ifdef WXE                                                       //~v51VR~
//static UCHAR Spdir  []= " 0000000000000000000000000000011111101\\\x02" "0";//~v51VR~
//#else                                                            //~v51VR~
//static UCHAR Spdir  []= " 0000000000000000000000000000011111101\\0";//~v51VR~
//#endif                                                           //~v51VR~
                                                                //~v020I~
static UPANELD Smenu31[]={                                      //~v020I~
						{Sm31_0,USDF2PROTONLY,Spfhdr,NULLINIT1},        //~v020I~
					 	{Sm10_1,USDF2CMD ,Spcmd2,NULLINIT1},            //~5628R~
					 	{Sm31_2,0        ,Spdir ,NULLINIT1},            //~v020I~
					 	{0,0,0,NULLINIT1}				//terminater            //~v020I~
						};                                      //~v020I~
//* Utility:Compare *********************************************  //~v76gI~
static UCHAR Sm62_0[]="------- File / Directory Compare ";         //~v76gR~
static UCHAR Sm62_1[]="\0===>";	//initial null value               //~v76gI~
static UCHAR Sm62_5[]="\0 Options  =>\\\x01";                      //~v76gR~
static UCHAR Sm62_2[]="\0 Curr Dir -- ";                           //~v76gR~
static UCHAR Sm62_3[]="\0 FileSpec1=>\\\x01";                      //~v76gR~
static UCHAR Sm62_4[]="\0 FileSpec2=>\\\x01";                      //~v76gR~
                                                                   //~v76gI~
static UCHAR Sucurd[]=  "000000000000 \\0";	//curdir               //~v76gR~
static UCHAR Sufnam[]=  "011111111100 \\0";	//filename             //~v76gR~
                                                                   //~v76gI~
static UPANELD Smenu62[]={                                         //~v76gI~
						{Sm62_0,USDF2PROTONLY,Spfhdr,NULLINIT1},   //~v76gI~
					 	{Sm62_1,USDF2CMD ,Spcmd ,NULLINIT1}, //cmd //~v76gR~
						{Sdelm ,USDF2PROT,NULL  ,NULLINIT1},       //~v76gI~
					 	{Sm62_5,0        ,Sufnam,NULLINIT1}, //opt //~v76gR~
						{Sdelm ,USDF2PROT,NULL  ,NULLINIT1},       //~v76gI~
						{Sm62_2,USDF2PROTONLY,Sucurd,NULLINIT1}, //cdir//~v76gR~
						{Sdelm ,USDF2PROT,NULL  ,NULLINIT1},       //~v76gI~
					 	{Sm62_3,0        ,Sufnam,NULLINIT1},//f1   //~v76gR~
						{Sdelm ,USDF2PROT,NULL  ,NULLINIT1},       //~v76gI~
					 	{Sm62_4,0        ,Sufnam,NULLINIT1},//f2   //~v76gR~
						{Sdelm ,USDF2PROT,NULL  ,NULLINIT1},       //~v76gI~
					 	{0,0,0,NULLINIT1}				//terminater//~v76gI~
						};                                         //~v76gI~
//* Utility:Search  *********************************************  //~v76gI~
static UCHAR Sm63_0[]="------- Grep Search ";                      //~v76gR~
static UCHAR Sm63_1[]="\0===>";	//initial null value               //~v76gI~
static UCHAR Sm63_2[]="\0 Options  =>\\\x01";                      //~v76gR~
static UCHAR Sm63_5[]="\0 Curr Dir -- ";                           //~v76gR~
static UCHAR Sm63a1[]="\0 FileSpec1=>\\\x01";                      //~v76gR~
static UCHAR Sm63a2[]="\0         2=>\\\x01";                      //~v76gR~
static UCHAR Sm63a3[]="\0         3=>\\\x01";                      //~v76gR~
static UCHAR Sm63a4[]="\0         4=>\\\x01";                      //~v76gR~
static UCHAR Sm63a5[]="\0         5=>\\\x01";                      //~v76gR~
static UCHAR Sm63a6[]="\0         6=>\\\x01";                      //~v76gR~
static UCHAR Sm63a7[]="\0         7=>\\\x01";                      //~v76gR~
static UCHAR Sm63a8[]="\0         8=>\\\x01";                      //~v76gR~
static UCHAR Sm63a9[]="\0         9=>\\\x01";                      //~v76gR~
static UCHAR Sm63aa[]="\0        10=>\\\x01";                      //~v76gI~
static UCHAR Sm63ab[]="\0        11=>\\\x01";                      //~v76gI~
static UCHAR Sm63ac[]="\0        12=>\\\x01";                      //~v76gI~
static UCHAR Sm63ad[]="\0        13=>\\\x01";                      //~v76gI~
static UCHAR Sm63ae[]="\0        14=>\\\x01";                      //~v76gI~
static UCHAR Sm63af[]="\0        15=>\\\x01";                      //~v76gI~
                                                                   //~v76gI~
static UPANELD Smenu63[]={                                         //~v76gI~
						{Sm63_0,USDF2PROTONLY,Spfhdr,NULLINIT1},   //~v76gI~
					 	{Sm63_1,USDF2CMD ,Spcmd ,NULLINIT1},  //cmd//~v76gR~
						{Sdelm ,USDF2PROT,NULL  ,NULLINIT1},       //~v76gI~
					 	{Sm63_2,0        ,Sufnam,NULLINIT1}, //opt //~v76gR~
						{Sdelm ,USDF2PROT,NULL  ,NULLINIT1},       //~v76gI~
					 	{Sm63_5,USDF2PROTONLY,Sucurd,NULLINIT1}, //cdir//~v76gR~
						{Sdelm ,USDF2PROT,NULL  ,NULLINIT1},       //~v76gI~
					 	{Sm63a1,0        ,Sufnam,NULLINIT1}, //file//~v76gR~
					 	{Sm63a2,0        ,Sufnam,NULLINIT1},       //~v76gR~
					 	{Sm63a3,0        ,Sufnam,NULLINIT1},       //~v76gR~
					 	{Sm63a4,0        ,Sufnam,NULLINIT1},       //~v76gR~
					 	{Sm63a5,0        ,Sufnam,NULLINIT1},       //~v76gR~
					 	{Sm63a6,0        ,Sufnam,NULLINIT1},       //~v76gR~
					 	{Sm63a7,0        ,Sufnam,NULLINIT1},       //~v76gR~
					 	{Sm63a8,0        ,Sufnam,NULLINIT1},       //~v76gR~
					 	{Sm63a9,0        ,Sufnam,NULLINIT1},       //~v76gR~
					 	{Sm63aa,0        ,Sufnam,NULLINIT1},       //~v76gI~
					 	{Sm63ab,0        ,Sufnam,NULLINIT1},       //~v76gI~
					 	{Sm63ac,0        ,Sufnam,NULLINIT1},       //~v76gI~
					 	{Sm63ad,0        ,Sufnam,NULLINIT1},       //~v76gI~
					 	{Sm63ae,0        ,Sufnam,NULLINIT1},       //~v76gI~
					 	{Sm63af,0        ,Sufnam,NULLINIT1},       //~v76gI~
					 	{0,0,0,NULLINIT1}				//terminater//~v76gI~
						};                                         //~v76gI~
//********
typedef struct _UPIDTBL {
						int    	UPIpid;
						int    	UPIlineno;
						UPANELD *UPIppd;
                        UCHAR   UPIflag;                        //~v032I~
#define UPIFEXPAND      0x01                //expand to screen height//~v032I~
#define UPIFFREE        0x02                //expanded,free required//~v032I~
                        int     UPIufldsz;  //UFLD size for copy malloc//~v032I~
                        PUFLD   UPIpfld;    //UFLD ptr          //~v032I~
						} UPIDTBL;
static UPIDTBL	Spidtbl[]={
							{PANTOPMENU  ,0,&Smenu0[0] ,0,NULLINIT2},
							{PANOPTCOLOR ,0,&Smenu1[0] ,0,NULLINIT2},   //color option//~v075I~
							{PANFBROWSE  ,0,&Smenu10[0],0,NULLINIT2},
							{PANFEDIT    ,0,&Smenu20[0],0,NULLINIT2},
//  						{PANFNAME    ,0,&Smenu30[0]},          //~v20yR~
    						{PANFNAME    ,0,&Smenu30[0],UPIFEXPAND,NULLINIT2},//repeat upto screen height//~v20yI~
							{PANDIR      ,0,&Smenu31[0],UPIFEXPAND,NULLINIT2},//~v032R~
							{PANUCOMP    ,0,&Smenu62[0],0,NULLINIT2},//~v76gI~
							{PANUGREP    ,0,&Smenu63[0],0,NULLINIT2},//~v76gI~
							{-1,0,0,0,NULLINIT2}
						};
static int Slf2ddpadding=0;		//0:by ddfmt positioning,1:padding //~vaarI~
//****************************************************************
int ppdinit(UPIDTBL *Pppi);                                     //~v032R~
void panppdfree(UPIDTBL *Pppi);                                 //~v04dI~
#ifdef WCSUPP                                                      //~v79zI~
	int pan000init(void);                                          //~v79zR~
#endif                                                             //~v79zI~
int pan000draw(int Popt,PUCLIENTWE Ppcw,PUSCRD Ppsd,int Prow);     //~vb2LI~
//****************************************************************//~v032I~
// paninit                                                      //~v032I~
//*init panel                                                   //~v032I~
//*parm   :none                                                 //~v032I~
//*return :none                                                 //~v032I~
//****************************************************************//~v032I~
void paninit(void)                                              //~v032I~
{                                                               //~v032I~
	PUPANELD   ppd,ppd0,ppdn;                                   //~v032R~
	UPIDTBL *ppi;                                               //~v032I~
	int lineno;                                                 //~v032R~
    UCHAR *pc,wk[8];                                               //~v20qI~
    int  ii;                                                       //~v20rI~
//**************************	                                //~v032I~
#ifdef WCSUPP                                                      //~v79zM~
	pan000init();//pfh init befor psd init to avoid re-call wakeup after edit_file2 call(psd is override for file panel)//~v79zR~
#endif                                                             //~v79zM~
//*display maxcolor                                                //~v20qI~
	if (pc=strchr(Sm1_i,'%'),pc)	//field of max color number    //~v20qR~
    {                                                              //~v20qI~
    	sprintf(wk,"%2d",Gmaxcolor);                               //~v20qR~
        memcpy(pc,wk,2);                                           //~v20qI~
    }                                                              //~v20qI~
#ifdef UNX                                                         //~v41vI~
    ii=(int)strlen(Sm040);                                         //~v41vR~
	sprintf(Sm040+ii,"%-*.*s",80-ii,80-ii,Ghostname);              //~v41vI~
#endif                                                             //~v41vI~
//*protect color number input fld                                  //~v20rI~
#ifndef LNX                                                        //~v658I~
	if (Gmaxcolor==2 || UCBITCHK(Gscrstatus,GSCRSEXTSG))//mono or color change N/A//~v20rI~
    {                                                              //~v20rI~
		pc=Spcol+COLOR_NUM_INPUT_POS;     //start of pallet 1--7   //~v20rR~
    	for (ii=1;ii<MAX_COLOR;ii++,pc+=4)                         //~v20rR~
        	memcpy(pc,"111",3);		//protect field id             //~v20rI~
    }                                                              //~v20rI~
#endif                                                             //~v658I~
                                                                   //~v20qI~
	for (ppi=Spidtbl;ppi->UPIpid!=-1;ppi++)                     //~v032I~
		if (UCBITCHK(ppi->UPIflag,UPIFEXPAND))                  //~v032R~
        {                                                       //~v032I~
//expand UPANELD upt scr height                                 //~v032I~
			ppd0=ppi->UPIppd;                                   //~v032I~
			for(ppd=ppd0,lineno=0;;ppd++,lineno++)//count lineno//~v032I~
				if (!ppd->UPDdatadef)			//end of line   //~v032I~
					break;                                      //~v032I~
//#ifdef WXE                                                       //~v64hR~
#ifdef WXEXXE                                                      //~v64hI~
            if (lineno<Gscrbuffheight)	//init max line            //~v500I~
#else                                                              //~v500I~
            if (lineno<Gscrheight)                              //~v032I~
#endif                                                             //~v500I~
            {                                                   //~v032I~
//#ifdef WXE                                                       //~v64hR~
#ifdef WXEXXE                                                      //~v64hI~
//          	ppdn=UALLOCM((UINT)(UPANELDSZ*(Gscrbuffheight+1)));//new ppd//~v500I~//~vb30R~
            	ppdn=UALLOCM(UPANELDSZ*(size_t)(Gscrbuffheight+1));//new ppd//~vb30I~
#else                                                              //~v500I~
//          	ppdn=UALLOCM((UINT)(UPANELDSZ*(Gscrheight+1)));//new ppd//~v04dR~//~vb30R~
            	ppdn=UALLOCM(UPANELDSZ*(size_t)(Gscrheight+1));//new ppd//~vb30I~
#endif                                                             //~v500I~
//              memcpy(ppdn,ppd0,(UINT)UPANELDSZ*lineno);       //~v032R~//~vb30R~
                memcpy(ppdn,ppd0,UPANELDSZ*(size_t)lineno);        //~vb30I~
                ppd0=ppd-1;		//last ppd                      //~v032I~
                ppd=ppdn+lineno;	//copy to                   //~v032I~
//#ifdef WXE                                                       //~v64hR~
#ifdef WXEXXE                                                      //~v64hI~
            	lineno=Gscrbuffheight-lineno;                      //~v500I~
#else                                                              //~v500I~
            	lineno=Gscrheight-lineno;                       //~v032I~
#endif                                                             //~v500I~
                for (;lineno;lineno--,ppd++)                    //~v032I~
                	memcpy(ppd,ppd0,UPANELDSZ);                 //~v032I~
                ppd->UPDdatadef=0;		//last id               //~v032I~
                ppi->UPIppd=ppdn;		//replace org           //~v032I~
				UCBITON(ppi->UPIflag,UPIFFREE);                 //~v032R~
			}//under height                                     //~v032I~
		}//expand required                                      //~v032I~
//*register top menu                                            //~v032M~
    panregist(PANTOPMENU);		//top menu setup;               //~v032M~
	                                                            //~v032I~
	return;                                                     //~v032I~
}//paninit                                                      //~v032I~
#ifdef WCSUPP                                                      //~v79zM~
//**************************************************************** //~v79zM~
//**************************************************************** //~v79zM~
//**************************************************************** //~v79zM~
int pan000init(void)                                               //~v79zR~
{                                                                  //~v79zM~
	int ii,len,len2;                                               //~v79zI~
    char *pc,*pc2,*pc0,lcwk[80];                                   //~v79zM~
//*******************                                              //~v79zM~
#ifdef LNX                                                         //~v79zM~
    if (UDBCSCHK_ISUTF8()) //locale is UTF8                        //~v79zM~
    {                                                              //~v79zM~
        pc=Gdefaultlocalecode;                                     //~v79zR~
        sprintf(lcwk,"UTF-8 (%s)",pc);                             //~v79zM~
                                                                   //~v79zM~
    }                                                              //~v79zM~
    else                                                           //~v79zM~
    {                                                              //~v79zM~
#endif                                                             //~v79zM~
        pc=Gdefaultlocalecode;                                     //~v79zR~
        sprintf(lcwk,"%s",pc);                                     //~v79zM~
#ifdef LNX                                                         //~v79zM~
    }                                                              //~v79zM~
#endif                                                             //~v79zM~
        if (!*pc)                                                  //~v79zM~
            pc="???";                                              //~v79zM~
        else                                                       //~v79zM~
        	pc=lcwk;                                               //~v79zM~
		pc0=Sm0_b;                                                 //~v79zR~
        if (pc2=strstr(pc0,LOCALEPREFIX),pc2)                      //~v79zM~
        {                                                          //~v79zM~
//        	ii=(ULONG)pc2-(ULONG)pc0+sizeof(LOCALEPREFIX)-1;       //~v79zM~//~vafkR~
//        	ii=(ULPTR)pc2-(ULPTR)pc0+sizeof(LOCALEPREFIX)-1;       //~vafkI~//~vb2FR~
          	ii=PTRDIFF(pc2,pc0)+(int)sizeof(LOCALEPREFIX)-1;       //~vb2FI~
        	len=80-ii-1;     //1:for sprintf set last strz         //~v79zM~
        	if (len>0)                                             //~v79zM~
            {                                                      //~v79zI~
//          	len2=strlen(lcwk);                                 //~v79zI~//~vb30R~
            	len2=(int)strlen(lcwk);                            //~vb30I~
                len2=min(len,len2);                                //~v79zI~
        		memcpy(pc0+ii,lcwk,(UINT)len2);                    //~v79zI~
            }                                                      //~v79zI~
        }                                                          //~v79zM~
	return 0;                                                      //~v79zM~
}//pan000init                                                      //~v79zM~
#endif                                                             //~v79zM~
                                                                   //~v79zM~
                                                                //~v032I~
//****************************************************************//~v032M~
// panterm                                                      //~v032M~
//*UPANELD free                                                 //~v032M~
//*return :none                                                 //~v032M~
//****************************************************************//~v032M~
void panterm(void)                                              //~v032M~
{                                                               //~v032M~
	UPIDTBL *ppi;                                               //~v032M~
//*********************************                             //~v032M~
	for (ppi=Spidtbl;ppi->UPIpid!=-1;ppi++)                     //~v032M~
	{                                                           //~v032M~
		panppdfree(ppi);                                        //~v04d
		if (UCBITCHK(ppi->UPIflag,UPIFFREE))	//copyed        //~v032I~
			ufree(ppi->UPIppd);		//free it                   //~v032I~
	}//all panel                                                //~v032M~
	pan300freestack();	//free file list of menu 1/2               //~v20yI~
	return;                                                     //~v032M~
}//panterm                                                      //~v032M~
                                                                //~v032M~
//****************************************************************//~v04dI~
// panppdfree                                                   //~v04dI~
//*free ppd alloc storage                                       //~v04dI~
//*parm1:ppi(pid tbl)                                           //~v04dI~
//*return :none                                                 //~v04dI~
//****************************************************************//~v04dI~
void panppdfree(UPIDTBL *Pppi)                                  //~v04dI~
{                                                               //~v04dI~
	int ii;                                                     //~v04dI~
	int lineno;                                                 //~v04dI~
	UPANELD *ppd;                                               //~v04dI~
//**************************	                                //~v04dI~
	lineno=Pppi->UPIlineno;                                     //~v04dI~
	ppd=Pppi->UPIppd;                                           //~v04dI~
	if (Pppi->UPIpfld)		//ufld                              //~v04dI~
		ufree(Pppi->UPIpfld);	//free original UFLD            //~v04dI~
	for(ii=0;ii<lineno;ppd++,ii++)		//all pre defined line  //~v04dI~
	{                                                           //~v04dI~
		UFREEIFNZ(ppd->UPDdata);		//full width expanded data//~v04dI~
		UFREEIFNZ(ppd->UPDdbcs);		//dbcs id tb            //~v04dI~
	}//loop lineno                                              //~v04dI~
}//panppdfree                                                   //~v04dI~
                                                                //~v04dI~
//****************************************************************
// panregist
//*menu setup and register to screen
//*parm1:menu id                                                //~v04dI~
//*return :pcw or 0 if memory shortage                          //~v04dR~
//****************************************************************
PUCLIENTWE panregist(int Pmenuid)                               //~5611R~
{
	PUCLIENTWE pcw;
	PUPANELC ppc;
//**************************	
	if (!(ppc=pangetpc(Pmenuid)))                               //~v04dR~
    	return 0;				//storage shortage              //~v04dI~
	pcw=scrregist(UCWTMENU,ppc);
    if (!pcw)                                                   //~v04dI~
    {                                                           //~v04dI~
        panfreepc(ppc);                                         //~v04dI~
    	return 0;				//storage shortage              //~v04dI~
    }                                                           //~v04dI~
	panwakeup(pcw);				//USCRD init
	csrhomepos(0);			//move csr to 1st fld of current active
	return pcw;	//v020                                          //~5611R~
}//panregist	

//****************************************************************
// panpopup
//*free current panel and popup previous client
//*return :rc=0
//****************************************************************
PUCLIENTWE panpopup(PUCLIENTWE Ppcw)
{
	PUPANELC ppc;
//**************************	
	ppc=Ppcw->UCWppc;			//client panel control
	panfreepc(ppc);				//free ppc
	return scrpopup(0,0);		//free top pcw,and popup old;   //~5228R~
}//panpopup 	                                                //~v04dR~
//****************************************************************
// pangetpc
//*get panel control
//*parm1: panel id                                              //~v04dI~
//*return :ppc or 0 if ualloc err                               //~v04dR~
//****************************************************************
PUPANELC pangetpc(int Ppanelid)
{
//****************
	int i;
	int width,lineno=0;                                         //~v032R~
    int  ppcsz;                                                 //~v032I~
	UCHAR *pc;
	UPANELD *ppd;
	PUPANELC ppc;
	UPIDTBL *ppi;
    PUFLD   pfldn,pfld0;                                        //~v032I~
//*********************************
	for (ppi=Spidtbl;ppi->UPIpid!=-1;ppi++)
		if (Ppanelid==ppi->UPIpid)
			break;
	
	if (ppi->UPIpid==-1)
		uerrexit("pangetpc:panel id parm(%d) err",0,Ppanelid);
//#ifdef WXE                                                       //~v64hR~
#ifdef WXEXXE                                                      //~v64hI~
	width=Gscrbuffwidth;	//init max buff size                   //~v500I~
#else                                                              //~v500I~
	width=Gscrwidth;
#endif                                                             //~v500I~

	if (!(lineno=ppi->UPIlineno))
    {                                                           //~v04dI~
        ppi->UPIlineno=                                         //~v04dI~
		lineno=ppdinit(ppi);                                    //~v032R~
        UALLOCCHK(lineno,0);	//return 0 if storage shortage  //~v04dI~
	}                                                           //~v04dI~

//  ppcsz=UPANELCSZ+(lineno-1)*UPANELLSZ;	//hdr and buff ptr  //~v032R~//~vb30R~
    ppcsz=(int)UPANELCSZ+(lineno-1)*(int)UPANELLSZ;	//hdr and buff ptr//~vb30I~
	ppc=UALLOCC(1,(UINT)(ppcsz+ppi->UPIufldsz));//ppc and ufld  //~v04dR~
    UALLOCCHK(ppc,0);    //return if malloc err                 //~v04dI~
    pfldn=(PVOID)((UCHAR*)(PVOID)ppc+ppcsz);	//ufld to ppc   //~v032R~
    memcpy(pfldn,pfld0=ppi->UPIpfld,(UINT)ppi->UPIufldsz);	//copy ufld//~v032R~
    memcpy(ppc->UPCcbid,UPCCBID,4);     //acronym               //~5105I~
	ppc->UPCid=Ppanelid;
	ppc->UPClineno=lineno;
	ppd=ppc->UPCppd=ppi->UPIppd;
#ifdef UTF8SUPPH                                                   //~va00I~
    pc=UALLOCC(1,UPCCMDFLDWKSZ*(1+1+1+1));  //data/dbcs/utf8/codetype                           //~v730I~//~va00I~
#else                                                              //~va00I~
    pc=UALLOCC(1,UPCCMDFLDWKSZ*(1+1));                             //~v730I~
#endif                                                             //~va00I~
    if (!pc)                                                       //~v730I~
    {                                                              //~v730I~
        panfreepc(ppc);    //return if malloc err                  //~v730I~
        return 0;                                                  //~v730I~
    }                                                              //~v730I~
    ppc->UPCcmddata=pc;                                            //~v730I~
    strcpy(pc,(ppd+CMDLINENO)->UPDdata);        //copy "===>"      //~v730I~
    ppc->UPCcmddbcs=pc+UPCCMDFLDWKSZ;                              //~v730I~
#ifdef UTF8SUPPH                                                   //~va00I~
    ppc->UPCcmddatabyutf8=ppc->UPCcmddbcs+UPCCMDFLDWKSZ;           //~va00I~
    ppc->UPCcmdcodetb=ppc->UPCcmddatabyutf8+UPCCMDFLDWKSZ;         //~va00I~
#endif                                                             //~va00I~
	for(i=0;i<lineno;ppd++,i++)		//all pre defined line
	{
		if  (i && ppd->UPDprottype==USDF2PROT)	//not full protected line
			continue;	//buff for first line,for csr mode/colomn etc 

		pc=ppc->UPCline[i].UPLbuff=UALLOCM((UINT)width);        //~v04dR~
        if (!pc)                                                //~v04dI~
        {                                                       //~v04dI~
	    	panfreepc(ppc);    //return if malloc err           //~v04dI~
            return 0;	                                        //~v04dI~
        }                                                       //~v04dI~
		memcpy(pc,ppd->UPDdata,(UINT)width);
		pc=ppc->UPCline[i].UPLdbcs=UALLOCM((UINT)width);        //~v04dR~
        if (!pc)                                                //~v04dI~
        {                                                       //~v04dI~
	    	panfreepc(ppc);    //return if malloc err           //~v04dI~
            return 0;	                                        //~v04dI~
        }                                                       //~v04dI~
		memcpy(pc,ppd->UPDdbcs,(UINT)width);
		if (ppd->UPDpfld)		//not first line                //~v032I~
			ppc->UPCline[i].UPLpfld=(PVOID)((UCHAR*)(PVOID)pfldn//~v032R~
//								+((ULONG)ppd->UPDpfld-(ULONG)pfld0));//~v032I~//~vafkR~
								+((ULPTR)ppd->UPDpfld-(ULPTR)pfld0));//~vafkI~
                                                                //~v032I~
	}//loop by lineno
	return ppc;

}//pangetpc

//****************************************************************
// panfreepc
//*free panel control
//*parm1:UPANELC ptr
//*return :rc=0
//****************************************************************
void panfreepc(PUPANELC Pppc)
{
	int lineno,i;
	PUPANELD ppd;
//*********************************
	lineno=Pppc->UPClineno;
	ppd=Pppc->UPCppd;
	UFREEIFNZ(Pppc->UPCcmddata);                                   //~v730I~
	UFREEIFNZ(Pppc->UPCpandata);    //additional data for the panelid//~v76gI~
	for(i=0;i<lineno;i++,ppd++)		//all pre defined line
	{
		if  (i && ppd->UPDprottype==USDF2PROT)	//full protected line
			continue;
		UFREEIFNZ(Pppc->UPCline[i].UPLbuff);                    //~v04dR~
		UFREEIFNZ(Pppc->UPCline[i].UPLdbcs);                    //~v04dR~
	}//loop by lineno

	ufree(Pppc);
	return;
}//panfreepc

//****************************************************************
// ppdinit
//*UPANELD initialize
//*parm   :UPIDTBL entry                                        //~v032I~
//*return :lineno or 0 if storage shortage                      //~v04dR~
//****************************************************************
int ppdinit(UPIDTBL *Pppi)                                      //~v032R~
{
	int i,j,k;                                                  //~v030R~
	int width,lineno=0;
	int len,fldsz=0;
    int exppos,explen;                                          //~v030I~
    int poss,pose,len1st;                                          //~v51VR~
	UCHAR *pc,*pcs,*pc2;
	UPANELD *ppd;
	UFLD  *pfl;
//****************
//#ifdef WXE                                                       //~v64hR~
#ifdef WXEXXE                                                      //~v64hI~
	width=Gscrbuffwidth;	//init max buff size                   //~v500I~
#else                                                              //~v500I~
	width=Gscrwidth;
#endif                                                             //~v500I~

	for(ppd=Pppi->UPIppd;;ppd++,lineno++)//count lineno         //~v032R~
		if (!ppd->UPDdatadef)			//end of line
			break;

//  Pppi->UPIlineno=lineno;			//                          //~v04dR~
	ppd=Pppi->UPIppd;				//pre defined line          //~v032R~
	for(i=0;i<lineno;ppd++,i++)		//all pre defined line
	{
		pc=ppd->UPDdata=UALLOCM((UINT)width);//full width expanded data//~v04dR~
        if (!pc)	//storage shortage                          //~v04dI~
        {                                                       //~v04dI~
        	panppdfree(Pppi);                                   //~v04dI~
            return 0;                                           //~v04dI~
        }                                                       //~v04dI~
		pcs=ppd->UPDdatadef;				//source data
		memset(pc,*pcs++,(UINT)width);//clear by first char
		if (pc2=strpbrk(pcs,"\\"),pc2)		//search break pt
		{
//  		memcpy(pc,pcs,(UINT)((ULONG)pc2-(ULONG)pcs));	//pre-half//~v51VR~
//          len1st=(int)((ULONG)pc2-(ULONG)pcs);	//pre-half     //~v57GR~//~vafkR~
            len1st=(int)((ULPTR)pc2-(ULPTR)pcs);	//pre-half     //~vafkI~
    		len1st=min(width,len1st);	//pre-half                 //~v51VI~
    		memcpy(pc,pcs,(UINT)len1st);	//pre-half             //~v51VI~
			len=(int)strlen(++pc2);
//#ifdef WXE                                                       //~v51VR~
//            if (*pc2==FIXEDLENID)                                //~v51VR~
//            {                                                    //~v51VR~
//                pc2++;                                           //~v51VR~
//                len--;                                           //~v51VR~
//            }                                                    //~v51VR~
//#endif                                                           //~v51VR~
          if (width-len1st>=len)     //full space for 2nd half     //~v51VI~
			memcpy(pc+width-len,pc2,(UINT)len);	//post half
		}
		else
        {                                                          //~v51AI~
//  		memcpy(pc,pcs,strlen(pcs));                            //~v51AR~
    		len=(int)strlen(pcs);                                  //~v51AI~
            if (len>width)                                         //~v51AI~
            	len=width;                                         //~v51AI~
    		memcpy(pc,pcs,(UINT)len);                              //~v51AI~
        }                                                          //~v51AI~
//*repl 0x01 by 0x00(field term data for successfull strlen)
		for (j=0,pc2=pc;j<width;j++,pc2++)
			if (*pc2==0x01)
				*pc2=0;

		pc2=ppd->UPDdbcs=UALLOCC(1,(UINT)width);//dbcs id tb    //~v04dR~
        if (!pc2)	//storage shortage                          //~v04dI~
        {                                                       //~v04dI~
        	panppdfree(Pppi);                                   //~v04dI~
            return 0;                                           //~v04dI~
        }                                                       //~v04dI~
		setdbcstbl(pc,pc2,width);				//dbcs id tbl init

		if  (ppd->UPDprottype==USDF2PROT)	//not full protected line
			continue;

//accum UFLD needed len
		if (ppd->UPDprotdef)		//protected field defined
		{
//  		fldsz+=(UFLDSZ-UFLESZ);                                //~vb30R~
    		fldsz+=(int)(UFLDSZ-UFLESZ);                           //~vb30I~
			pc=ppd->UPDprotdef;
			while(pc && *pc)
			{
				if (*pc=='0')		//protected field
					pc+=strspn(pc,"0");	//next non "0" fld offset
				else
				{
//  				fldsz+=UFLESZ;                                 //~vb30R~
    				fldsz+=(int)UFLESZ;                            //~vb30I~
					pc=strpbrk(pc,"0");//search "0" position
				}	
			}//loop prot data		
		}//prot data exist
		else
//  		fldsz+=UFLDSZ;			//1 entry                      //~vb30R~
    		fldsz+=(int)UFLDSZ;			//1 entry                  //~vb30I~
	}//loop lineno
//UFLD init****
	pfl=UALLOCC(1,(UINT)fldsz);	//UFLD area                     //~v04dR~
    if (!pfl)	//storage shortage                              //~v04dI~
    {                                                           //~v04dI~
       	panppdfree(Pppi);                                       //~v04dI~
        return 0;                                               //~v04dI~
    }                                                           //~v04dI~
    Pppi->UPIpfld=pfl;			//save top addr for copy/free   //~v032I~
    Pppi->UPIufldsz=fldsz;		//save for copy                 //~v032I~

	ppd=Pppi->UPIppd;				//pre defined line          //~v032R~
	for(i=0;i<lineno;ppd++,i++)		//all pre defined line
	{
		if  (ppd->UPDprottype==USDF2PROT)	//not full protected line
			continue;

		ppd->UPDpfld=pfl;			//UFLD ptr
	    memcpy(pfl->UFLcbid,UFLCBID,4);	//acronym               //~v032I~
		if (ppd->UPDprotdef)		//protected field defined
		{
			pc=ppd->UPDprotdef;
			j=0;					//fld count
			while(pc && *pc)
			{
				if (*pc=='0')
					pc+=strspn(pc,"0");	//next non "0" fld offset
				else
				{
					pfl->UFLentry[j].UFLfieldno=(UCHAR)j;	    //~v032I~
//  				pfl->UFLentry[j].UFLstart=(int)((ULONG)pc-(ULONG)ppd->UPDprotdef);//~v51VR~
//    				poss=(int)((ULONG)pc-(ULONG)ppd->UPDprotdef);  //~v51VI~//~vafkR~
    				poss=(int)((ULPTR)pc-(ULPTR)ppd->UPDprotdef);  //~vafkI~
                    poss=min(poss,width);                          //~v51VI~
    				pfl->UFLentry[j].UFLstart=poss;                //~v51VI~
                    if (*pc=='1')                               //~5611I~
						pfl->UFLentry[j].UFLflag=UFLEFPROT;//prot fld//~5611I~
					if (pc=strpbrk(pc,"0"),pc)	//search "0" pos
                    {                                              //~v51VI~
//  					pfl->UFLentry[j].UFLend=(int)((ULONG)pc-(ULONG)ppd->UPDprotdef);//~v51VR~
//    					pose=(int)((ULONG)pc-(ULONG)ppd->UPDprotdef);//~v51VI~//~vafkR~
    					pose=(int)((ULPTR)pc-(ULPTR)ppd->UPDprotdef);//~vafkI~
	                    pose=min(pose,width);                      //~v51VI~
    					pfl->UFLentry[j].UFLend=pose;              //~v51VI~
                    }                                              //~v51VI~
					else
						pfl->UFLentry[j].UFLend=width;
					pfl->UFLctr=++j;
				}	
			}//loop protdata		
			pc=ppd->UPDprotdef;
			if (pc=strpbrk(pc,"\\"),pc)
			{
//  			if (j>1)	//edit/browse has 2 field           //~v030R~
//  			{                                               //~v030R~
//  				pfl->UFLentry[j-2].UFLend=width-(int)strlen(pc+1);//~v030R~
//  				pc=strpbrk(pc," ");                         //~v030R~
//  				pfl->UFLentry[j-1].UFLstart=width-(int)strlen(pc);//~v030R~
//  			}                                               //~v030R~
//  			if (pc=strpbrk(pc,"0"),pc)	//search "0" pos    //~v030R~
//  				pfl->UFLentry[j-1].UFLend=width-(int)strlen(pc);//~v030R~
//  			else                                            //~v030R~
//  				pfl->UFLentry[j-1].UFLend=width;            //~v030R~
//              exppos=(int)((ULONG)pc-(ULONG)ppd->UPDprotdef);    //chk pos//~v030R~//~vafkR~
                exppos=(int)((ULPTR)pc-(ULPTR)ppd->UPDprotdef);    //chk pos//~vafkI~
                explen=width-(int)strlen(pc)-exppos;            //~v030R~
//#ifdef WXE                                                       //~v51VR~
//                if (*(pc+1)==FIXEDLENID)                         //~v51VR~
//                    explen++;                                    //~v51VR~
//#endif                                                           //~v51VR~
                for (k=0;k<j;k++)                               //~v030I~
                {                                                  //~v500I~
                	if (pfl->UFLentry[k].UFLstart>exppos)       //~v030I~
                    {                                           //~v030I~
                      if (explen<0)  //no space for 2nd part       //~v51VI~
                      {                                            //~v51VI~
    	  				pfl->UFLentry[k].UFLstart=width-1;	//length 0//~v51VR~
    	  				pfl->UFLentry[k].UFLend=width-1;           //~v51VR~
                      }                                            //~v51VI~
                      else                                         //~v51VI~
                      {                                            //~v51VI~
    	  				pfl->UFLentry[k].UFLstart+=explen;         //~v51VR~
    	  				pfl->UFLentry[k].UFLend+=explen;           //~v51VR~
                      }                                            //~v51VI~
                    }                                           //~v030I~
                    else                                        //~v030I~
	                	if (pfl->UFLentry[k].UFLend>exppos)     //~v030I~
                        {                                          //~v51VI~
                          if (explen<0)  //no space for 2nd part   //~v51VI~
                          {                                        //~v51VI~
  			  				pfl->UFLentry[k].UFLend=width-1;       //~v51VR~
                            if (pfl->UFLentry[k].UFLstart>=width)  //~v51VR~
                            	pfl->UFLentry[k].UFLstart=width-1; //~v51VR~
                          }                                        //~v51VI~
                          else                                     //~v51VI~
    		  				pfl->UFLentry[k].UFLend+=explen;       //~v51VR~
                        }                                          //~v51VI~
//#ifdef WXE                                                       //~v51VR~
//                    if (*(pc+1)==FIXEDLENID)                     //~v51VR~
//                    {                                            //~v51VR~
//                        if (pfl->UFLentry[k].UFLstart>FIXEDLEN)  //~v51VR~
//                            pfl->UFLentry[k].UFLstart=FIXEDLEN;  //~v51VR~
//                        if (pfl->UFLentry[k].UFLend  >FIXEDLEN)  //~v51VR~
//                            pfl->UFLentry[k].UFLend  =FIXEDLEN;  //~v51VR~
//                    }                                            //~v51VR~
//#endif                                                           //~v51VR~
            	}                                                  //~v500I~
			}
			pc=(PVOID)pfl;
//  		pc+=UFLDSZ+UFLESZ*(j-1);                               //~vb30R~
    		pc+=(int)UFLDSZ+(int)UFLESZ*(j-1);                     //~vb30I~
			pfl=(PVOID)pc;	//next UFLD addr
		}//fld def exist
		else		//no protdata
		{
			pfl->UFLctr=1;
			pfl->UFLentry[0].UFLstart=0;
			pfl->UFLentry[0].UFLend=width;
			pfl++;
		}
	}//loop by lineno
	return lineno;
}//ppdinit
//#ifdef WXE                                                       //~v64hR~
#ifdef WXEXXE                                                      //~v64hI~
//**************************************************************** //~v500I~
// ppdinit_resize                                                  //~v500I~
//*UPANELD initialize at resize                                    //~v500I~
//*parm   :pcw                                                     //~v500I~
//*return :0                                                       //~v500I~
//**************************************************************** //~v500I~
int ppdinit_resize(PUCLIENTWE Ppcw)                                //~v500I~
{                                                                  //~v500I~
	PUPANELC ppc;                                                  //~v500I~
	PUPANELD ppd,ppd0;                                             //~v500R~
	int line,width;                                                //~v500R~
	int i,j,k;                                                     //~v500I~
	int len;                                                       //~v64hR~
    int poss,pose;                                                 //~v51VI~
    int exppos,explen;                                             //~v500I~
    int len1st; //1st half len                                     //~v51VI~
	UCHAR *pc,*pcs,*pc2;                                           //~v500I~
	UFLD  *pfl;                                                    //~v500I~
//****************                                                 //~v500I~
	if (!UCBITCHK(Ppcw->UCWflag,UCWFRESIZE))                       //~v500I~
    	return 0;                                                  //~v500I~
	UCBITOFF(Ppcw->UCWflag,UCWFRESIZE);                            //~v500I~
                                                                   //~v500I~
	ppc=Ppcw->UCWppc;                                              //~v500I~
	UCBITON(ppc->UPCflag,UPCFRESIZE);                              //~v76gR~
	line=ppc->UPClineno;	//defined  line                        //~v500I~
    line=min(line,Gscrheight);                                     //~v51VI~
	ppd0=ppc->UPCppd;	//ppd top                                  //~v500I~
	width=Gscrwidth;                                               //~v500I~
	for(i=0,ppd=ppd0;i<line;ppd++,i++)		//hdr and cmd input line//~v500R~
	{                                                              //~v500I~
		pc=ppd->UPDdata;//full width expanded data                 //~v500I~
		pcs=ppd->UPDdatadef;				//source data          //~v500I~
		memset(pc,*pcs++,(UINT)width);//clear by first char        //~v500I~
		if (pc2=strpbrk(pcs,"\\"),pc2)		//search break pt      //~v500I~
		{                                                          //~v500I~
//  		memcpy(pc,pcs,(UINT)((ULONG)pc2-(ULONG)pcs));	//pre-half//~v51VR~
//          len1st=(ULONG)pc2-(ULONG)pcs;	//pre-half             //~v51VR~//~vafkR~
//          len1st=(ULPTR)pc2-(ULPTR)pcs;	//pre-half             //~vafkI~//~vb2WR~
            len1st=(int)((ULPTR)pc2-(ULPTR)pcs);	//pre-half     //~vb2WI~
            len1st=min(len1st,width);	//pre-half                 //~v51VI~
    		memcpy(pc,pcs,(UINT)len1st);	//pre-half             //~v51VR~
			len=(int)strlen(++pc2);                                //~v500I~
//            if (*pc2==FIXEDLENID)                                //~v51VR~
//            {                                                    //~v51VR~
//                pc2++;                                           //~v51VR~
//                len--;                                           //~v51VR~
//            }                                                    //~v51VR~
          if (width-len1st>=len)     //full space for 2nd half     //~v51VI~
			memcpy(pc+width-len,pc2,(UINT)len);	//post half        //~v500I~
		}                                                          //~v500I~
		else                                                       //~v500I~
			memcpy(pc,pcs,strlen(pcs));                            //~v500I~
//*repl 0x01 by 0x00(field term data for successfull strlen)       //~v500I~
		for (j=0,pc2=pc;j<width;j++,pc2++)                         //~v500I~
			if (*pc2==0x01)                                        //~v500I~
				*pc2=0;                                            //~v500I~
                                                                   //~v500I~
		pc2=ppd->UPDdbcs;//dbcs id tb                              //~v500I~
		setdbcstbl(pc,pc2,width);				//dbcs id tbl init //~v500I~
//copy to upc data                                                 //~v500I~
		if (ppc->UPCline[i].UPLbuff)	//not full prot line       //~v500R~
        {                                                          //~v500I~
			memcpy(ppc->UPCline[i].UPLbuff,pc,(UINT)width);        //~v500R~
			memcpy(ppc->UPCline[i].UPLdbcs,pc2,(UINT)width);       //~v500R~
        }                                                          //~v500I~
	}//loop lineno                                                 //~v500I~
//UFLD init****                                                    //~v500I~
	for(i=0,ppd=ppd0;i<line;ppd++,i++)		//all pre defined line //~v500R~
	{                                                              //~v500I~
		if  (ppd->UPDprottype==USDF2PROT)	//not full protected line//~v500I~
			continue;                                              //~v500I~
                                                                   //~v500I~
		pfl=ppc->UPCline[i].UPLpfld;                               //~v500R~
		if (ppd->UPDprotdef)		//protected field defined      //~v500I~
		{                                                          //~v500I~
			pc=ppd->UPDprotdef;                                    //~v500I~
			j=0;					//fld count                    //~v500I~
			while(pc && *pc)                                       //~v500I~
			{                                                      //~v500I~
				if (*pc=='0')                                      //~v500I~
					pc+=strspn(pc,"0");	//next non "0" fld offset  //~v500I~
				else                                               //~v500I~
				{                                                  //~v500I~
//  				pfl->UFLentry[j].UFLstart=(int)((ULONG)pc-(ULONG)ppd->UPDprotdef);//~v51VR~
//    				poss=(int)((ULONG)pc-(ULONG)ppd->UPDprotdef);  //~v51VI~//~vafkR~
     				poss=(int)((ULPTR)pc-(ULPTR)ppd->UPDprotdef);  //~vafkI~
                    poss=min(poss,width);                          //~v51VI~
    				pfl->UFLentry[j].UFLstart=poss;                //~v51VI~
					if (pc=strpbrk(pc,"0"),pc)	//search "0" pos   //~v500I~
                    {                                              //~v51VI~
//  					pfl->UFLentry[j].UFLend=(int)((ULONG)pc-(ULONG)ppd->UPDprotdef);//~v51VR~
//    					pose=(int)((ULONG)pc-(ULONG)ppd->UPDprotdef);//~v51VI~//~vafkR~
    					pose=(int)((ULPTR)pc-(ULPTR)ppd->UPDprotdef);//~vafkI~
	                    pose=min(pose,width);                      //~v51VI~
    					pfl->UFLentry[j].UFLend=pose;              //~v51VI~
                    }                                              //~v51VI~
					else                                           //~v500I~
						pfl->UFLentry[j].UFLend=width;             //~v500I~
					++j;                                           //~v500R~
				}                                                  //~v500I~
			}//loop protdata                                       //~v500I~
			pc=ppd->UPDprotdef;                                    //~v500I~
			if (pc=strpbrk(pc,"\\"),pc)                            //~v500I~
			{                                                      //~v500I~
//              exppos=(int)((ULONG)pc-(ULONG)ppd->UPDprotdef);    //chk pos//~v500I~//~vafkR~
                exppos=(int)((ULPTR)pc-(ULPTR)ppd->UPDprotdef);    //chk pos//~vafkI~
                explen=width-(int)strlen(pc)-exppos;               //~v500I~
//                if (*(pc+1)==FIXEDLENID)                         //~v51VR~
//                    explen++;                                    //~v51VR~
                for (k=0;k<j;k++)                                  //~v500I~
                {                                                  //~v500I~
                	if (pfl->UFLentry[k].UFLstart>exppos)          //~v500I~
                    {                                              //~v500I~
                      if (explen<0)  //no space for 2nd part       //~v51VI~
                      {                                            //~v51VI~
    	  				pfl->UFLentry[k].UFLstart=width-1;	//length 0//~v51VR~
    	  				pfl->UFLentry[k].UFLend=width-1;           //~v51VR~
                      }                                            //~v51VI~
                      else                                         //~v51VI~
                      {                                            //~v51VI~
    	  				pfl->UFLentry[k].UFLstart+=explen;         //~v51VR~
    	  				pfl->UFLentry[k].UFLend+=explen;           //~v51VR~
                      }                                            //~v51VI~
                    }                                              //~v500I~
                    else                                           //~v500I~
	                	if (pfl->UFLentry[k].UFLend>exppos)        //~v500I~
                        {                                          //~v51VI~
                          if (explen<0)  //no space for 2nd part   //~v51VI~
                          {                                        //~v51VI~
  			  				pfl->UFLentry[k].UFLend=width-1;       //~v51VR~
                            if (pfl->UFLentry[k].UFLstart>=width)  //~v51VR~
                            	pfl->UFLentry[k].UFLstart=width-1; //~v51VR~
                          }                                        //~v51VI~
                          else                                     //~v51VI~
  			  				pfl->UFLentry[k].UFLend+=explen;       //~v51VR~
                        }                                          //~v51VI~
//                    if (*(pc+1)==FIXEDLENID)                     //~v51VR~
//                    {                                            //~v51VR~
//                        if (pfl->UFLentry[k].UFLstart>FIXEDLEN)  //~v51VR~
//                            pfl->UFLentry[k].UFLstart=FIXEDLEN;  //~v51VR~
//                        if (pfl->UFLentry[k].UFLend  >FIXEDLEN)  //~v51VR~
//                            pfl->UFLentry[k].UFLend  =FIXEDLEN;  //~v51VR~
//                    }                                            //~v51VR~
                }                                                  //~v500I~
			}                                                      //~v500I~
			pc=(PVOID)pfl;                                         //~v500I~
//  		pc+=UFLDSZ+UFLESZ*(j-1);                               //~v500I~//~vb30R~
    		pc+=(int)UFLDSZ+(int)UFLESZ*(j-1);                     //~vb30I~
			pfl=(PVOID)pc;	//next UFLD addr                       //~v500I~
		}//fld def exist                                           //~v500I~
		else		//no protdata                                  //~v500I~
		{                                                          //~v500I~
			pfl->UFLentry[0].UFLend=width;                         //~v500I~
			pfl++;                                                 //~v500I~
		}                                                          //~v500I~
	}//loop by lineno                                              //~v500I~
	setflddatacmd(Ppcw,0);	//0:copy to UPLbuff only(from UPCcmddata/dbcs)//~vaibI~
	return 0;                                                      //~v500R~
}//ppdinit_resize                                                  //~v500I~
#endif                                                             //~v500I~
//**************************************************************** //~v59TI~
// pandirfldresize                                                 //~v59TI~
// dirlist fld pos ajust by expandlen                              //~v59TI~
//*return :0                                                       //~v59TI~
//**************************************************************** //~v59TI~
int pandirfldresize(PUCLIENTWE Ppcw,int Pexpandlen)                //~v59TI~
{                                                                  //~v59TI~
	PUPANELC ppc;                                                  //~v59TI~
	UFLD  *pfl;                                                    //~v59TI~
	int ii,line;                                                   //~v59TR~
//****************                                                 //~v59TI~
	ppc=Ppcw->UCWppc;                                              //~v59TI~
	line=ppc->UPClineno;	//defined  line                        //~v59TI~
    line=min(line,Gscrheight);                                     //~v59TI~
//UFLD ajust                                                       //~v59TI~
	for(ii=2;ii<line;ii++)	//all pre defined line                 //~v59TI~
	{                                                              //~v59TI~
		pfl=ppc->UPCline[ii].UPLpfld;                              //~v59TI~
    	pfl->UFLentry[PANL310ATTR].UFLstart  +=Pexpandlen;         //~v59TI~
    	pfl->UFLentry[PANL310ATTR].UFLend    +=Pexpandlen;         //~v59TI~
    	pfl->UFLentry[PANL310RENAME].UFLstart+=Pexpandlen;         //~v59TI~
    	pfl->UFLentry[PANL310RENAME].UFLend  +=Pexpandlen;         //~v59TI~
	}//loop by lineno                                              //~v59TI~
	return 0;                                                      //~v59TI~
}//pandirfldresize                                                 //~v59TI~
//****************************************************************
// panwakeup
//*USCRD init at nit and when became new active window
//*return :rc=0
//****************************************************************
int panwakeup(PUCLIENTWE Ppcw)
{
	PUPANELC ppc;
	PUPANELD ppd;
	PUSCRD psd;
	int line,maxline,width;
	int i,no;                                                      //~v079R~
	int menuid;                                                 //~v020R~
    char wkedit[4];                                                //~v075I~
    char *pc;                                                      //~v075R~
//**************************	
//#ifdef WXE                                                       //~v64hR~
#ifdef WXEXXE                                                      //~v64hI~
	ppdinit_resize(Ppcw);		//re-init cmd line,ufld            //~v500I~
#endif                                                             //~v500I~
	psd=Ppcw->UCWpsd;
	ppc=Ppcw->UCWppc;
    menuid=ppc->UPCid;                                          //~v020R~
    if (menuid==PANFNAME)                                          //~v76gI~
		pan300init(Ppcw);//pfh init befor psd init to avoid re-call wakeup after edit_file2 call(psd is override for file panel)//~v76gI~
	ppd=ppc->UPCppd;	//ppd top
	line=ppc->UPClineno;	//defined  line
//#ifdef WXE                                                       //~v64hR~
#ifdef WXEXXE                                                      //~v64hI~
	maxline=Gscrbuffheight;                                        //~v500I~
	width=Gscrbuffwidth;	//init max buff size                   //~v500I~
#else                                                              //~v500I~
	maxline=Gscrheight;
	width=Gscrwidth;
#endif                                                             //~v500I~
//    for (i=0;i<line;i++,psd++,ppd++)                             //~vaa2R~
    for (i=0;i<line && i<maxline ;i++,psd++,ppd++)                 //~vaa2I~
	{
		psd->USDppd=ppd;
		psd->USDbuffc=ppc->UPCline[i].UPLbuff;
		psd->USDpfld=ppc->UPCline[i].UPLpfld;	//UFLD malloced //~v032I~
		psd->USDflag2=(UCHAR)ppd->UPDprottype;
		psd->USDcell0len=0;
		psd->USDnattr0len=0;			//no attr data
		psd->USDnattr=Gattrtbl[COLOR_FRAME];
		if  (i && ppd->UPDprottype==USDF2PROT)	//full protected line
			memcpy(psd->USDdata,ppd->UPDdata,(UINT)width);

		memcpy(psd->USDdbcs,ppd->UPDdbcs,(UINT)width);//not changable
		if (i==CMDLINENO)
		{
			psd->USDnattr=Gattrtbl[COLOR_FRAME];
			psd->USDnattr0=Gattrtbl[COLOR_FRAME_R];
							//used when err with specifing USDnattr0len 
		}
	}
	for (;i<maxline;i++,psd++)
	{
		psd->USDflag2=USDF2PROT;
		psd->USDflag = USDFNCELL;
		psd->USDuvioo=0;    //noligature,no combine for other panel//~vb4fR~
		psd->USDcell0len=0;
		psd->USDnattr0len=0;		//no attr data
		*psd->USDcell=' ';
		*(psd->USDcell+1)=Gattrtbl[COLOR_FRAME];
	}
    switch(menuid)                                              //~v020M~
    {                                                           //~v020M~
    case PANOPTCOLOR:                                              //~v075I~
    	for (i=0,pc=Gpallassigntbl;i<PAL_MAXENTRY;i++)             //~v075R~
        {                                                          //~v075I~
        	sprintf(wkedit,"%2d",(int)*pc++);                      //~v075I~
		    setflddata(Ppcw,i+PANL10PAL,PANF10PALCFG,wkedit);      //~v075I~
        	sprintf(wkedit,"%2d",(int)*pc++);                      //~v075I~
		    setflddata(Ppcw,i+PANL10PAL,PANF10PALCBG,wkedit);      //~v075I~
		}                                                          //~v075I~
//  	for (i=0;i<16;i++)                                         //~v20pR~
    	for (i=0;i<MAX_COLOR;i++)                                  //~v20pI~
        {                                                          //~v075I~
        	panixtorgb((int)Gdefpallette[i],wkedit);               //~v07aR~
		    setflddata(Ppcw,PANL10COLD,i,wkedit);                  //~v075R~
        	if (Gpallette[i]==0xff)    //not changed               //~v079R~
        		no=(int)Gdefpallette[i];	   //same as defult    //~v079I~
			else                                                   //~v075M~
	        	no=(int)Gpallette[i];                              //~v079R~
        	panixtorgb(no,wkedit);                                 //~v07aR~
		    setflddata(Ppcw,PANL10COLC,i,wkedit);                  //~v075R~
		}                                                          //~v075I~
        break;                                                     //~v075I~
    case PANFNAME:                                              //~v020M~
		UCBITON((Ppcw->UCWpsd+PANL300CURRENT)->USDflag2,USDF2DRAW);//~v020I~
        			//req pandraw300,set cur dir                //~v020I~
      if (Ppcw->UCWmenuopt)		//skip at 1st time(call from panregist)//~v61rI~
		pan300updatelist(Ppcw,1);//update filename list on ppc,wakeup//~v20yI~
        break;                                                  //~v020M~
    case PANUCOMP:                                                 //~v76gI~
        pancompdraw(Ppcw,1);                                       //~v76gR~
        break;                                                     //~v76gI~
    case PANUGREP:                                                 //~v76gI~
        pangrepdraw(Ppcw,1);                                       //~v76gR~
        break;                                                     //~v76gI~
    }                                                           //~v020M~
	UCBITOFF(Ppcw->UCWflag,UCWFWAKEUP);                         //~v08bI~
	return 0;
}//panwakeup	
//**************************************************************** //~va3KI~
// draw hex input mode status                                      //~va3KI~
//**************************************************************** //~va3KI~
int pandrawxkbd(int Popt,PUCLIENTWE Ppcw,PUSCRD Ppsd)              //~va3KR~
{                                                                  //~va3KI~
	int  hexinputlen;                                              //~va3KI~
	UCHAR   hexeditwk[12];                                         //~va3KI~
//****************************                                     //~va3KI~
//#ifdef UTF8UCS4                                                    //~va3KI~//~vaw3R~
#ifdef UTF8UCS416                                                  //~vaw3I~
	if (Ghexctl[HEXCTL_MODE] & HEXCTL_MODE_UCS4)	//hex input mode//~va3KI~
		hexeditwk[0]='v';				//ucs4 id                  //~va3KI~
    else                                                           //~va3KI~
#endif                                                             //~va3KI~
	if (Ghexctl[HEXCTL_MODE] & HEXCTL_MODE_UCS2)	//hex input mode//~va3KI~
		hexeditwk[0]='u';				//x and u is u             //~va3KR~
    else                                                           //~va3KI~
		hexeditwk[0]='x';				//x and u is u             //~va3KI~
    hexinputlen=(int)Ghexctl[HEXCTL_LEN];	//input xdigit len     //~va3KI~
    memcpy(hexeditwk+1,Ghexctl+HEXCTL_DATA,(UINT)hexinputlen);     //~va3KR~
    hexeditwk[1+hexinputlen]='_';                                  //~va3KR~
	memcpy(Ppsd->USDdata,hexeditwk,(UINT)(hexinputlen+2));         //~va3KR~
    return 0;                                                      //~va3KI~
}//pandrawxkbd                                                     //~va3KI~
//****************************************************************
// menu_draw
//*setup screen line data
//*parm1:client work
//*parm2:file client work element
//*rc   :0
//****************************************************************
int func_draw_pan(PUCLIENTWE Ppcw)
{
	int     i,jj,kk;                                            //~v020R~
	int     len,line,maxline;
    int cmdlen=0,cmdfldlen;                                        //~vaf9R~
    ULONG   errflag,flag;                                       //~v020I~
	PUSCRD  psd;
	PUPANELC ppc;
	UFLDE  *pfle=0;                                                //~vaf9R~
    UCHAR *pc1,*pc2;                                            //~v020I~
    int swxkbd;                                                    //~va3KI~
//****************************
	if (UCBITCHK(Ppcw->UCWflag,UCWFWAKEUP))//now activated
//  {                                                              //~v08bR~
//  	UCBITOFF(Ppcw->UCWflag,UCWFWAKEUP);                        //~v08bR~
		panwakeup(Ppcw);				//USCRD init
//  }                                                              //~v08bR~
	ppc=Ppcw->UCWppc;					//UPANELC
    switch(ppc->UPCid)                                          //~v020I~
    {                                                           //~v020I~
    case PANFNAME:                                              //~v020I~
//    if (Ppcw==scrgetcw(0))	//active client                    //~v557I~,//~v772R~
		pandraw300(Ppcw);	//set curr dir,xepan2               //~v020I~
        break;                                                  //~v020I~
    case PANUCOMP:                                                 //~v76gI~
        pancompdraw(Ppcw,0);   //0:not wakeup                      //~v76gR~
        break;                                                     //~v76gI~
    case PANUGREP:                                                 //~v76gI~
        pangrepdraw(Ppcw,0);   //0:not wakeup                      //~v76gR~
        break;                                                     //~v76gI~
    }                                                           //~v020I~
	maxline=Ppcw->UCWheight;
	line=ppc->UPClineno;				//panel defined line
	psd=Ppcw->UCWpsd;
	len=Ppcw->UCWwidth;
    swxkbd=0;                                                      //~va3KI~
	for (i=0;i<line;i++,psd++)
	{
		if (i==maxline)		//screen width
			break;
        if (!i                                                     //~va3KI~
        &&  Ghexctl[HEXCTL_MODE]                                   //~va3KI~
        &&  Ppcw->UCWsplitid==Gscrcurclient	//active pcw           //~va3KI~
        )                                                          //~va3KI~
        {                                                          //~va3KI~
        	swxkbd=1;                                              //~va3KI~
			UCBITON(psd->USDflag2,USDF2DRAW);                      //~va3KI~
        }                                                          //~va3KI~
		if (!UCBITCHK(Ppcw->UCWflag,UCWFDRAW)
		&&  !(UCBITCHK(psd->USDflag2,USDF2DRAW)))
			continue; 
		if (i==CMDLINENO)	//command line                         //~v730I~
        {                                                          //~v730I~
			pfle=getuflde(Ppcw,CMDLINENO,0);                       //~v730I~
//  		cmdlen=(int)strlen(ppc->UPCcmddata);                   //~v730I~//~va11R~
    		cmdlen=(int)strlen(ppc->UPCline[CMDLINENO].UPLbuff);   //~va11I~
            cmdlen-=pfle->UFLstart;                                //~v76vR~
			cmdfldlen=pfle->UFLend-pfle->UFLstart;                 //~v730I~
            if (cmdlen>cmdfldlen)                                  //~v730R~
            	cmdlen=cmdfldlen;                                  //~v730I~
//  		memcpy(psd->USDdata,ppc->UPCcmddata,(UINT)len);//set data of screen width//~v730R~//~va11R~
//  		memcpy(psd->USDdbcs,ppc->UPCcmddbcs,(UINT)len);        //~v730R~//~va11R~
    		memcpy(psd->USDdata,ppc->UPCline[CMDLINENO].UPLbuff,(UINT)len);//set data of screen width//~va11I~
    		memcpy(psd->USDdbcs,ppc->UPCline[CMDLINENO].UPLdbcs,(UINT)len);//from display area//~va11I~
            UTRACED("USDdata",psd->USDdata,len);                   //~vaibI~
            UTRACED("USDdbcs",psd->USDdbcs,len);                   //~vaibI~
#ifdef UTF8SUPPH                                                    //~v913I~//~va0xI~
            pansetinputmode(Ppcw,psd);                             //~v916R~//~va0xI~
#endif                                                             //~v913I~//~va0xI~
        }                                                          //~v730I~
        else                                                       //~v730I~
		if (!i || !UCBITCHK(psd->USDflag2,USDF2PROT))	//input line
		{
			memcpy(psd->USDdata,psd->USDbuffc,(UINT)len);
			memcpy(psd->USDdbcs,ppc->UPCline[i].UPLdbcs,(UINT)len);//updatable
		}
		psd->USDlen=len;
		psd->USDoff=0;
		psd->USDflag=USDFCHARSTRATT;
		psd->USDuvioo=0;    //set no ligature/combine at once      //~vb4fR~
        if (!i && swxkbd)                                          //~va3KR~
        {                                                          //~va3KI~
        	pandrawxkbd(0,Ppcw,psd);                               //~va3KI~
        }                                                          //~va3KI~
        else                                                       //~va3KI~
		if (i==CMDLINENO)	//command line
        {                                                          //~v772I~
			if (UCBITCHK(Ppcw->UCWflag,UCWFCMDERR))
			{
//  			pfle=getuflde(Ppcw,CMDLINENO,0);                   //~v730R~
//  			psd->USDnattr0len=(int)strlen(psd->USDdata+pfle->UFLstart);//~v730R~
    			psd->USDnattr0len=cmdlen;                          //~v730I~
				psd->USDnattr0off=pfle->UFLstart;	//use USDnattr0
			}
			else
				psd->USDnattr0len=0;			//no attr data
#ifdef UTF8SUPPH                                                   //~va00I~
			pansetcmdcodeattr(0,Ppcw,psd,ppc);                     //~va00R~
#endif                                                             //~va00I~
        }                                                          //~v772I~
		else                                                    //~v020I~
#ifdef UTF8SUPPH                                                   //~va00I~
		{                                                          //~va00I~
#endif                                                             //~va00I~
			UTRACEP("%s:i=%d,errflag=0x%x\n",UTT,i,ppc->UPCline[i].UPLerrflag);//~vbdqR~
       		if (errflag=ppc->UPCline[i].UPLerrflag,errflag//err    //~v075R~
            ||  (ppc->UPCid==PANOPTCOLOR                           //~v075R~
				&& !UCBITCHK(psd->USDflag2,USDF2PROT))) //input line//~v075R~
            {                                                   //~v020I~
    			psd->USDlen+=psd->USDlen;	//double len        //~v020I~
				psd->USDflag=USDFCELLSTR;	//by cell data      //~v020I~
//*duplicated   psd->USDuvioo=0;                                   //~vb4fR~
				pc1=psd->USDbuffc;  //copyed                    //~v020R~
				pc2=psd->USDcell;                               //~v020R~
				for (jj=0;jj<len;jj++)                          //~v020I~
				{                                               //~v020I~
					*pc2++=*pc1++;			//copy data         //~v020I~
					*pc2++=Gattrtbl[COLOR_FRAME];	//browse fg //~v020I~
				}                                               //~v020I~
                if (errflag)                                       //~v075I~
            	for (jj=0,flag=0x80000000;jj<UPANLINEMAXFLD;jj++,flag>>=1)//~v020R~
	        	{                                               //~v020I~
                	if (errflag & flag)	//err                   //~v020I~
                    {                                           //~v020I~
						pfle=getuflde(Ppcw,i,jj);               //~v020I~
                        kk=getfldpos(Ppcw,i,jj,&pc2,0);         //~v039R~
//                      kk=min(kk,(int)strlen(pc2));//real data len//~vb4hR~
                        kk=min(kk,getfldstrlen(0,pc2,psd->USDdbcs+pfle->UFLstart,kk));//~vb4hR~
						pc2=psd->USDcell+pfle->UFLstart*2+1;    //~v020R~
						for (;kk;kk--,pc2++)                    //~v020R~
							*pc2++=Gattrtbl[COLOR_FRAME_R];	//browse fg//~v020I~
                	}                                           //~v020I~
    	    	}                                               //~v020I~
				if (ppc->UPCid==PANOPTCOLOR)                       //~v075I~
    	         	panattr10(Ppcw,i,psd);	//pan2                 //~v079R~
			}//err field exist                                  //~v020I~
#ifdef UTF8SUPPH                                                   //~va00I~
	        switch(ppc->UPCid)                                     //~v91mI~//~va00I~
        	{                                                      //~v91mI~//~va00I~
			case PANFNAME:                                         //~v91mR~//~va00I~
	    	    pan300attr(Ppcw,i,psd);	//filename list            //~v91mR~//~va00I~
	            break;                                             //~v91mI~//~va00I~
        	case PANUCOMP:                                         //~v91mI~//~va00I~
            	pancompdraw2(0,Ppcw,psd,i);                        //~v91mR~//~va00I~
            	break;                                             //~v91mI~//~va00I~
        	case PANUGREP:                                         //~v91mI~//~va00I~
            	pangrepdraw2(0,Ppcw,psd,i);                        //~v91mR~//~va00I~
            	break;                                             //~v91mI~//~va00I~
        	case PANTOPMENU:                                       //~vb2LI~
            	pan000draw(0,Ppcw,psd,i);                          //~vb2LI~
            	break;                                             //~vb2LI~
            }                                                      //~v91mI~//~va00I~
		}//!CMDLINENO                                              //~va00I~
#endif                                                             //~va00I~
	}
	if (UCBITCHK(Ppcw->UCWflag,UCWFDRAW))
		for (;i<maxline;i++,psd++)
			psd->USDlen=len;
	return 0;
}//func_draw_pan

//**************************************************            //~5611I~
//*panlinetopfld                                                   //~v075I~
//*search not protected top field of the line                   //~5611I~
//*parm :pfl                                                    //~5611I~
//*return:ufld index ,if protected return -1                    //~5611I~
//**************************************************            //~5611I~
int panlinetopfld(PUFLD Ppfl)                                   //~5611I~
{                                                               //~5611I~
	int ii,fldno;                                               //~5611I~
	UFLDE *pfle;                                                //~5611I~
//*************                                                 //~5611I~
	fldno=Ppfl->UFLctr;                                         //~5611R~
    pfle=Ppfl->UFLentry;                                        //~5611R~
	for (ii=0;ii<fldno;ii++,pfle++)                             //~5611I~
		if (!UCBITCHK(pfle->UFLflag,UFLEFPROT))                 //~5611I~
			return ii;                                          //~5611I~
	return -1;			//out of any fld                        //~5611I~
}//panlinetopfld                                                //~5611I~
                                                                //~5611I~
//**************************************************            //~v020I~
//*set field err flag                                           //~v020I~
//*parm1 :pcw                                                   //~v020I~
//*parm2 :lineno(if -1,use UCWrcsry)                            //~v020I~
//*parm3 :fldno                                                 //~v020I~
//*parm4 :0:err off,1:err on                                    //~v020I~
//*return:rc                                                    //~v020I~
//**************************************************            //~v020I~
int panflderr(PUCLIENTWE Ppcw,int Pline,int Pfldno,int Preq)    //~v020I~
{                                                               //~v020I~
	int lineno;                                                 //~v020I~
    PUPANELC ppc;                                               //~v020R~
	PUSCRD psd;                                                 //~v020I~
    ULONG flag;                                                 //~v020R~
    int swforce,swsetcsr;                                          //~v76gR~
//*************                                                 //~v020I~
    ppc=Ppcw->UCWppc;                                              //~v76gI~
    if (Preq & PANFEFORCE)	//set on req                           //~v76gI~
    {                                                              //~v76gI~
    	swforce=1;                                                 //~v76gI~
    	Preq &=~PANFEFORCE;	//set on req                           //~v76gI~
    }                                                              //~v76gI~
    else                                                           //~v76gI~
    	swforce=0;                                                 //~v76gI~
    if (Preq & PANFEKEEPCSR)	//set on req                       //~v76gR~
    {                                                              //~v76gI~
    	swsetcsr=0;                                                //~v76gI~
    	Preq &=~PANFEKEEPCSR;	//set on req                       //~v76gR~
    }                                                              //~v76gI~
    else                                                           //~v76gI~
    	swsetcsr=1;                                                //~v76gI~
	if ((lineno=Pline)<0)	//use                               //~v020I~
    	lineno=Ppcw->UCWrcsry;                                  //~v020I~
  if (swforce)  //beyond current screen                            //~v76gR~
  {                                                                //~v76gI~
    if (lineno>=ppc->UPClineno)                                    //~v76gI~
    	return 4;                                                  //~v76gI~
  }                                                                //~v76gI~
  else                                                             //~v76gI~
  {                                                                //~v76gI~
    if (lineno>=Ppcw->UCWmaxline)                               //~v020I~
    	return 4;                                               //~v020I~
  }                                                                //~v76gI~
    if (Pfldno<0 || Pfldno >=UPANLINEMAXFLD)                    //~v020I~
    	return 4;                                               //~v020I~
//  ppc=Ppcw->UCWppc;                                              //~v76gR~
    flag=0x80000000>>Pfldno;                                    //~v020I~
	psd=Ppcw->UCWpsd+lineno;                                    //~v020I~
	UCBITON(psd->USDflag2,USDF2DRAW);                           //~v020I~
    if (Preq==PANFESET)	//set on req                            //~v020I~
    {                                                           //~v020I~
      if (swsetcsr)	//set on but no move csr                       //~v76gI~
		csronthefld(Ppcw,lineno,Pfldno,0);//csr set             //~v020I~
        ppc->UPCline[lineno].UPLerrflag |= flag;                //~v020R~
    }                                                           //~v020I~
	else				//reset req                             //~v020I~
        ppc->UPCline[lineno].UPLerrflag &= ~flag;               //~v020R~
	return 0;                                                   //~v020I~
}//panflderr                                                    //~v020I~
                                                                //~v020I~
//**************************************************            //~v032I~
//*pandirprot                                                   //~v032I~
//*set/reset dir list protect field by input cmd                //~v032I~
//*parm1 :pfld                                                  //~v032I~
//*parm2 :option(0:SET PROTECT,1:attr input avail,2:new name input avail)//~v032I~
//*return:none                                                  //~v032I~
//**************************************************            //~v032I~
void pandirprot(PUFLD Ppfld,int Popt)                           //~v032I~
{                                                               //~v032I~
static int Sf2end=0;                                               //~v51AR~
//*************                                                 //~v032I~
	if (Popt==-1)	//resized,end value should be reset            //~v77HI~
    {                                                              //~v77HI~
    	Sf2end=0;                                                  //~v77HI~
        return;                                                    //~v77HI~
    }                                                              //~v77HI~
	if (!Sf2end)	//original len not saved                    //~v030R~
        Sf2end=Ppfld->UFLentry[PANL310RENAME].UFLend;           //~v030I~
	switch(Popt)                                                //~v032I~
    {                                                           //~v032I~
	case PANDPPROT:                                             //~v032I~
    	UCBITON (Ppfld->UFLentry[PANL310ATTR].UFLflag,UFLEFPROT);	//protect//~v030R~
    	UCBITON (Ppfld->UFLentry[PANL310RENAME].UFLflag,UFLEFPROT);	//protect//~v030R~
    	break;                                                  //~v032I~
	case PANDPINP1:	//attr input                                //~v030R~
    	UCBITOFF(Ppfld->UFLentry[PANL310ATTR].UFLflag,UFLEFPROT);	//protect reset//~v030R~
    	UCBITON (Ppfld->UFLentry[PANL310RENAME].UFLflag,UFLEFPROT);	//protect//~v030R~
    	break;                                                  //~v032I~
	case PANDPINP2: //filename input                            //~v030R~
    	UCBITON (Ppfld->UFLentry[PANL310ATTR].UFLflag,UFLEFPROT);	//protect//~v030R~
    	UCBITOFF(Ppfld->UFLentry[PANL310RENAME].UFLflag,UFLEFPROT);	//protect reset//~v030R~
	    Ppfld->UFLentry[PANL310RENAME].UFLend=Sf2end;           //~v030R~
    	break;                                                  //~v032I~
	case PANDPINP3: //file mask input                           //~v030I~
    	UCBITON (Ppfld->UFLentry[PANL310ATTR].UFLflag,UFLEFPROT);	//protect//~v030I~
    	UCBITOFF(Ppfld->UFLentry[PANL310RENAME].UFLflag,UFLEFPROT);	//protect reset//~v030I~
        Ppfld->UFLentry[PANL310RENAME].UFLend=                  //~v030I~
			Ppfld->UFLentry[PANL310RENAME].UFLstart+PANL310MASKLEN;//~v030I~
    	break;                                                  //~v030I~
	}                                                           //~v032I~
	return;                                                     //~v032I~
}//pandirprot                                                   //~v032I~
#ifdef UTF8SUPPH                                                //~v032I~//~va00R~
//**************************************************               //~v913I~//~va0xI~
//*set input mode(utf8/locale) on cmdline                          //~v913I~//~va0xI~
//**************************************************               //~v913I~//~va0xI~
void pansetinputmode(PUCLIENTWE Ppcw,PUSCRD Ppsd)                  //~v916R~//~va0xI~
{                                                                  //~v913I~//~va0xI~
	char *pc,id1='=',id2='=';                                      //~v913I~//~va0xI~
//*************                                                    //~v913I~//~va0xI~
#ifdef OLDA10                                                      //~va10I~
	if (Gutfmode2 & GUM2_KBDL2U)                                  //~v91sR~//~va0xI~
    {                                                              //~v913I~//~va0xI~
    	id1='2';                                                   //~v913I~//~va0xI~
    	id2=MODE_UTF8KBDID;                                        //~v913R~//~va0xI~
    }                                                              //~v913I~//~va0xI~
    else                                                           //~v916I~//~va0xI~
    if (Gutfmode2 & GUM2_KBDU2L)                                  //~v91sR~//~va0xI~
    {                                                              //~v913I~//~va0xI~
    	id2='2';                                                   //~v913R~//~va0xI~
    	id1=MODE_UTF8KBDID;                                        //~v913R~//~va0xI~
    }                                                              //~v913I~//~va0xI~
    else                                                           //~v913I~//~va0xI~
    if (XEUTF8MODE_ENV())                                             //~v913I~//~va0xI~
    {                                                              //~v913I~//~va0xI~
    	id2=MODE_UTF8KBDID;                                        //~v913I~//~va0xI~
    }                                                              //~v913I~//~va0xI~
#else //NEWA10                                                     //~va10I~
	if (Gutfmode2 & GUM2_KBDUTF8)                                  //~va10I~
    	id2=MODE_UTF8KBDID;                                        //~va10I~
#endif                                                             //~va10I~
	pc=Ppsd->USDdata;                                           //~v913R~//~va0xI~
    *pc=id1;                                                       //~v913I~//~va0xI~
    *(pc+1)=id2;                                                   //~v913I~//~va0xI~
    return;                                                        //~v913I~//~va0xI~
}//pansetinputmode                                                 //~v913I~//~va0xI~
//**************************************************               //~va5jI~
//*pancmdcvlf2dd                                                   //~va5jI~
//translate locale+utf8 mixed to dd fmt for cmdline psd            //~va5jI~
//rc:done to dd fmt,1:not done 4:err                               //~vaarI~
//**************************************************               //~va5jI~
//int pancmdlf2dd(int Popt,PUSCRD Ppsd,PUPANELC Pppc,UFLDE *Ppfle) //~vaarR~
int pancmdlf2dd(int Popt,PUSCRD Ppsd,PUPANELC Pppc,UFLDE *Ppfle,UCHAR *Pwkct,int Pwkctsz)//~vaarI~
{                                                                  //~va5jI~
	UCHAR *pct,*pu8,*pdata,*pdbcs,*pdddbcs,*pdddata;               //~va5jR~
    int len,outlen,fldposs,fldpose,u8len,lclen,fldw;               //~va5jR~
    int opt=0;                                                     //~vaakI~
	UCHAR *pcd;                                                    //~vaakI~
    UCHAR *plc;                                                    //~vaarI~
//**************************************************               //~va5jI~
	pdata=Ppsd->USDdata;                                           //~va5jI~
	pdbcs=Ppsd->USDdbcs;                                           //~va5jI~
   	pct=Pppc->UPCcmdcodetb;	//codetype tbl was setup               //~va5jI~
// 	pcd=Pppc->UPCcmddbcs;	//inpu dbcstblafter f2l,f2lerr is now not dbcs//~va5jR~
   	plc=Pppc->UPCcmddata;	//by locale code                       //~vaarI~
   	pcd=Pppc->UPCcmddbcs;	//input dbcstbl                        //~vaakI~
    pu8=Pppc->UPCcmddatabyutf8;	//mixed str                        //~va5jR~
	fldposs=Ppfle->UFLstart;                                       //~va5jI~
	fldpose=Ppfle->UFLend;                                         //~va5jI~
    pdata+=fldposs;                                                //~va5jI~
    pdbcs+=fldposs;                                                //~va5jI~
    pcd+=fldposs;                                                  //~vaakI~
    u8len=(int)strlen(pu8);                                        //~va5jI~
//  lclen=(int)strlen(Pppc->UPCline[CMDLINENO].UPLbuff)-fldposs;   //~va5jR~//~vaarR~
    lclen=(int)strlen(plc+fldposs);                                //~vaarR~
UTRACEP("pancmdlf2dd lclen=%d,u8len=%d\n",lclen,u8len);            //~vaanI~//~vaarM~//+vbmiR~
UTRACED("pancmdlf2dd cmddata",plc,lclen);                          //~vaarI~//+vbmiR~
UTRACED("pancmdlf2dd cmddatabyutf8",pu8,u8len);                              //~vaanI~//~vaarI~//+vbmiR~
UTRACED("pancmdlf2dd cmdcodetb",pct,lclen);                              //~vaanI~//~vaarI~//+vbmiR~
UTRACED("pancmdlf2dd cmddbcs",pcd,lclen);                          //~vaarI~//+vbmiR~
//  if (!memchr(pct,XEUTFCT_UTF8,lclen)) //contains utf8 code      //~vaarI~//~vb30R~
    if (!memchr(pct,XEUTFCT_UTF8,(size_t)lclen)) //contains utf8 code//~vb30I~
    {                                                              //~vaarI~
    	if (Slf2ddpadding		//0:by ddfmt positioning,1:padding //~vaarI~
//      ||  ( !memchr(pcd,UDBCSCHK_DBCSPAD,lclen)                  //~vaarR~//~vb30R~
        ||  ( !memchr(pcd,UDBCSCHK_DBCSPAD,(size_t)lclen)          //~vb30I~
#ifdef LNX                                                         //~vaarI~
           && !( (Gudbcschk_flag & UDBCSCHK_LANGEUC) && udbcschk_srchSS2(0,plc,pcd,lclen)>=0)//~vaarR~
#endif                                                             //~vaarI~
            )                                                      //~vaarI~
        )                                                          //~vaarI~
        {                                                          //~vaarI~
            UTRACEP("pancmdlf2dd rc=1");                           //~vaarI~
        	return 1;                                              //~vaarI~
        }                                                          //~vaarI~
    }                                                              //~vaarI~
    fldw=fldpose-fldposs;                                          //~va5jR~
//  if (xeutfcvlf2dd(0,pu8,u8len,0/*pdbcs*/,pct,lclen,&pdddata,&pdddbcs,fldw,&outlen)>4)//~vaakR~
//  opt=XEUTFLF2DO_PADDING;                                        //~vaanR~
//	memcpy(Pwkct,pct,min(Pwkctsz,lclen));                          //~vaarR~//~vb30R~
  	memcpy(Pwkct,pct,(size_t)min(Pwkctsz,lclen));                  //~vb30I~
  if (Slf2ddpadding)		//0:by ddfmt positioning,1:padding     //~vaarI~
  {                                                                //~vaarI~
    opt=XEUTFLF2DO_PADDING;                                        //~vaapI~
    if (xeutfcvlf2dd(opt,pu8,u8len,pcd,pct,lclen,&pdddata,&pdddbcs,fldw,&outlen)>4)//~vaakR~
    	return 4;                                                  //~va5jI~
  }                                                                //~vaarI~
  else                                                             //~vaarI~
  {                                                                //~vaarI~
    if (xeutfcvlf2dd_updatect(0,pu8,u8len,pcd,Pwkct,lclen,&pdddata,&pdddbcs,fldw,&outlen)>=4)//~vaarI~
    	return 4;                                                  //~vaarI~
  }                                                                //~vaarI~
//  memcpy(pdata,pdddata,outlen);   //ddstr                        //~va5jR~//~vb30R~
    memcpy(pdata,pdddata,(size_t)outlen);   //ddstr                //~vb30I~
//  memcpy(pdbcs,pdddbcs,outlen);   //ddstr                        //~va5jI~//~vb30R~
    memcpy(pdbcs,pdddbcs,(size_t)outlen);   //ddstr                //~vb30I~
    pdata+=outlen;                                                 //~va5jI~
    pdbcs+=outlen;                                                 //~va5jI~
    len=fldw-outlen;                                               //~va5jI~
    if (len>0)                                                     //~va5jI~
    {                                                              //~va5jI~
//  	memset(pdata,' ',len);                                     //~va5jI~//~vb30R~
    	memset(pdata,' ',(size_t)len);                             //~vb30I~
//  	memset(pdbcs,0,len);                                       //~va5jI~//~vb30R~
    	memset(pdbcs,0,(size_t)len);                               //~vb30I~
    }                                                              //~va5jI~
//  Ppsd->USDflag3|=USDF3DDFMT;	//ddfmt;positioning by Psd         //~vaanR~//~vaapR~
    Ppsd->USDddfldlen=min(outlen,fldw);                            //~vaanR~
    UTRACEP("pancmdlf2dd psd=%p,ddfldlen=%d\n",Ppsd,Ppsd->USDddfldlen);//~vaanR~
    return 0;                                                      //~va5jR~
}//pancmdlf2dd                                                     //~va5jI~
//**************************************************               //~v919I~//~va00I~
//*set input mode(utf8/locale) on cmdline                          //~v919I~//~va00I~
//**************************************************               //~v919I~//~va00I~
int pansetcmdcodeattr(int Popt,PUCLIENTWE Ppcw,PUSCRD Ppsd,PUPANELC Pppc)//~v919R~//~va00R~
{                                                                  //~v919I~//~va00I~
    int nattr0len,nattr0off,sdlen,ii,/*swutf8env,*/nattr0end,fgutf8;//~va00R~
    int fldposs,fldpose;                                           //~va00I~
    char *pcell,*pdata,*pdbcs,attr,nattr0,nattr,ch,*pct;           //~va00R~
	UFLDE  *pfle;                                                  //~va00I~
    int splitctr;                                                  //~va1cR~
    int swddfmt=0;                                                 //~va5jI~
    UCHAR wkct[MAXCOLUMN];                                         //~vaarR~
    UCHAR chtype;                                                  //~vb4cI~
//*****************                                                //~v919I~//~va00I~
//  swutf8env=XEUTF8MODE_ENV_FORCE();                              //~va00R~
//  if (!swutf8env)                                                //~va00R~
//  	return 0;                                                  //~va00R~
    nattr=Ppsd->USDnattr;                                          //~v919I~//~va00I~
    sdlen=Ppsd->USDlen;                                            //~va00I~
//*err attr                                                        //~va00I~
    nattr0=Ppsd->USDnattr0;                                        //~va00I~
    nattr0off=Ppsd->USDnattr0off;                                  //~va00I~
    nattr0len=Ppsd->USDnattr0len;                                  //~va00R~
    nattr0end=nattr0len+nattr0off;                                 //~va00I~
                                                                   //~va00I~
	pcell=Ppsd->USDcell;                                           //~v919I~//~va00I~
	pdata=Ppsd->USDdata;                                           //~va00I~
	pdbcs=Ppsd->USDdbcs;                                           //~va00I~
UTRACEP("pansetcmdcodeattr sdlen=%d\n",sdlen);                     //~va11I~
UTRACED("pansetcmdcodeattr pdata",pdata,sdlen);                    //~va11I~
   	pct=Pppc->UPCcmdcodetb;	//codetype tbl was setup               //~va00R~
	fgutf8=XEUTF_FG_UTF8;                                          //~va00R~
    pfle=getuflde(Ppcw,CMDLINENO,0);                               //~va00R~
	fldposs=pfle->UFLstart;                                        //~va00I~
	fldpose=pfle->UFLend;                                          //~va00I~
UTRACED("pansetcmdcodeattr codetb",pct,fldpose);                   //~vaa2I~
//  Ppsd->USDflag3&=~USDF3DDFMT;                                   //~vaanR~//~vaarR~
	UCBITOFF(Ppcw->UCWflag2,UCWF2CMDLINEDD);                       //~vaarI~
//    if (memchr(pct,XEUTFCT_UTF8,sdlen)) //contains utf8 code       //~va5jI~//~vaarR~
//    {                                                              //~va5jI~//~vaarR~
//        pancmdlf2dd(0,Ppsd,Pppc,pfle);  //lc+utf8-->ddfmt          //~va5jI~//~vaarR~
//        swddfmt=1;                                                 //~va5jI~//~vaarR~
//    }                                                              //~va5jI~//~vaarR~
    if (!pancmdlf2dd(0,Ppsd,Pppc,pfle,wkct,sizeof(wkct)))  //lc+utf8-->ddfmt//~vaarR~
    {                                                              //~vaarI~
  		if (!Slf2ddpadding)		//0:by ddfmt positioning,1:padding //~vaarI~
			UCBITON(Ppcw->UCWflag2,UCWF2CMDLINEDD);                //~vaarI~
		swddfmt=1;                                                 //~vaarI~
        pct=wkct;	//updated by locale to dd shift                //~vaarI~
    }                                                              //~vaarI~
    splitctr=XESUB_DBCSSPLITCTR_L(pdbcs,sdlen);                    //~va1cR~
	for (ii=0;ii<sdlen;ii++)                                       //~va00R~
    {                                                              //~va00I~
    	if (nattr0len)                                             //~va00I~
        	if (ii>=nattr0off && ii<nattr0end)                     //~va00R~
            	attr=nattr0;                                       //~va00R~
            else                                                   //~va00I~
				attr=nattr;                                        //~va00I~
        else                                                       //~va00I~
			attr=nattr;                                            //~va00I~
    	ch=*pdata++;                                               //~va00M~
//      if (pct && *pct++==XEUTFCT_UTF8)                           //~va00R~
//        if (ch && ii>=fldposs && ii<fldpose)                     //~va00R~
        if (pct && ii>=fldposs && ii<fldpose)                      //~va00I~
        {                                                          //~vb4cI~
//        if (*pct++==XEUTFCT_UTF8 && ch)                          //~va5jR~
//        if (*pct++==XEUTFCT_UTF8 && (ch||swddfmt))	//ddfmt dbcs has null value//~va5jI~//~vb4cR~
          chtype=*pct++;                                           //~vb4cI~
          if (chtype==XEUTFCT_UTF8)	//ddfmt dbcs has null value    //~vb4cI~
          {                                                        //~vb4cI~
           if (ch||swddfmt)	//ddfmt dbcs has null value            //~vb4cI~
//      	attr=(attr & 0xf0) | fgutf8;  //fg+bg                  //~vaz8R~
        	attr=(UCHAR)((attr & 0xf0) | fgutf8);  //fg+bg         //~vaz8I~
          }                                                        //~vb4cI~
          else                                                     //~vb4cI~
          if (!chtype)	//sbcs                                     //~vb4cR~
          {                                                        //~vb4cI~
        	if(ch>0 && Gunpdispchartbl[(int)ch])   	//unprintable except null(null is space)//~vb4cR~
            {                                                      //~vb4cI~
                UTRACEP("%s:%02x:unrintable,attr=%02x\n",UTT,ch,attr);//~vb4cI~
        		ch=XEUTF_ERRREPCH;	//displayable char             //~vb4cR~
	        	attr=(UCHAR)((attr & 0xf0) | fgutf8);  //fg+bg     //~vb4cI~
                UTRACEP("%s:altch=%02x,attr~%02x\n",UTT,ch,attr);  //~vb4cI~
            }                                                      //~vb4cI~
          }                                                        //~vb4cI~
        }                                                          //~vb4cI~
//*effective when vsplit                                           //~va1cR~
//      if (*pdbcs++==DBCS1STCHAR && ii+1==sdlen)                  //~va1cR~
        if (ii+splitctr>=sdlen)                                    //~va1cR~
        {                                                          //~va1cR~
UTRACEP("pansetcmdcodeattr dbcssplit ii=%d,splitctr=%d\n",ii,splitctr);//~va1cR~
        	ch=Gunpdispchar[0];                                    //~va00I~
        }                                                          //~va1cR~
    	*pcell++=ch;                                               //~va00I~
    	*pcell++=attr;                                             //~va00I~
    }                                                              //~va00I~
	Ppsd->USDlen=sdlen+sdlen;	//double len                       //~va00I~
	Ppsd->USDflag=USDFCELLSTR;	//by cell data                     //~va00I~
	Ppsd->USDuvioo=0;		//no ligature/combine for cmdline      //~vb4fR~
    Ppsd->USDnattr0len=0;                                          //~v919R~//~va00I~
	Ppsd->USDnattr0off=0;    //include in cell attr                //~v919R~//~va00I~
UTRACED("pansetcmdcodeattr out cell",Ppsd->USDcell,sdlen+sdlen);   //~va1cR~
    return 1;                                                      //~v919I~//~va00I~
}//pansetcmdcodeattr                                               //~v919I~//~va00I~
#endif                                                             //~v913I~//~va00I~
//**************************************************               //~vb2LI~
//*setup display lang info on top menu                             //~vb2LI~
//**************************************************               //~vb2LI~
int pan000draw(int Popt,PUCLIENTWE Ppcw,PUSCRD Ppsd,int Prow)      //~vb2LI~
{                                                                  //~vb2LI~
#ifdef W32                                                         //~vb2LI~
    char *plc,*pdddata,*pdddbcs;                                   //~vb2LR~
    int width,ddlen,opt,rc;                                        //~vb2LR~
    PUPANELC ppc;                                                  //~vb2LI~
	UPANELD *ppd;                                                  //~vb2LI~
//**********************************                               //~vb2LI~
	UTRACEP("%s:row=%d\n",UTT,Prow);                               //~vb2LI~
	ppc=Ppcw->UCWppc;                                              //~vb2LR~
	ppd=ppc->UPCppd;                                               //~vb2LI~
	if (Prow!=PANL00LC)                                            //~vb2LM~
    	return 0;                                                  //~vb2LM~
//  UCBITOFF(Ppsd->USDflag3,USDF3NOLIGATURE);                      //~vb2YI~//~vb2ZR~
//  if (!(Gudbcschk_flag & UDBCSCHK_CONSCP)) //ConsoleCP==SYSTEM Default//~vb2LR~//~vb2UR~
//  	return 0;                                                  //~vb2LR~//~vb2UR~
  if (!*Gparmlocalecode)                                           //~vb2ZI~
#ifndef WXE                                                        //~vb2ZI~
    if (!(Gudbcschk_flag & UDBCSCHK_CONSCP)) //ConsoleCP==SYSTEM Default//~vb2YI~
#endif                                                             //~vb2ZI~
    	return 0;                                                  //~vb2YI~
    ppd+=Prow;                                                     //~vb2LI~
    plc=ppd->UPDdata;                                              //~vb2LR~
#ifdef WXEXXE                                                      //~vb2LI~
	width=Gscrbuffwidth;	//init max buff size                   //~vb2LI~
#else                                                              //~vb2LI~
	width=Gscrwidth;                                               //~vb2LI~
#endif                                                             //~vb2LI~
    opt=0;                                                         //~vb2LI~
#ifdef WXE                                                         //~vb2YR~
	rc=xeutfcvl2dd_chcp(opt,plc,width,&pdddata,&pdddbcs,&ddlen);   //~vb2LR~
#else                                                              //~vb2YI~
//#ifdef AAA //@@@@test                                            //~vb2ZR~
//  rc=xeutfcvlchcp(opt,plc,width,&pdddata,&pdddbcs,&ddlen);       //~vb2YI~//~vb30R~//~vb3eR~
//#else                                                            //~vb2ZR~
//    rc=xeutfcvl2dd_chcp(opt,plc,width,&pdddata,&pdddbcs,&ddlen); //~vb2ZR~
//#endif                                                           //~vb2ZR~
#endif                                                             //~vb2ZI~
    rc=xeutfcvl2dd_chcp(opt,plc,width,&pdddata,&pdddbcs,&ddlen);//dd fmt//~vb3eI~
    if (!rc)                                                       //~vb2LI~
    {                                                              //~vb2LI~
        ddlen=min(ddlen,width);                                    //~vb2LI~
    	memcpy(Ppsd->USDdata,pdddata,ddlen);                       //~vb2LI~
    	memcpy(Ppsd->USDdbcs,pdddbcs,ddlen);                       //~vb2LI~
//  	UCBITON(Ppsd->USDflag3,USDF3NOLIGATURE);                   //~vb2YI~//~vb2ZR~
//  	UCBITON(Ppsd->USDflag3,USDF3NOLIGATURE);  //draw by NoLigature(viom OutputW all at once append space attr=0x00)//~vb4fR~
//  	Ppsd->USDuvioo|=UVIOO_LIGATURE2;  //draw by NoLigature(viom OutputW all at once append space attr=0x00)//~vb4fR~//~vb4hR~
    	Ppsd->USDuvioo|=UVIOO_LIGATURE2|UVIOO_MENULC;  //LC line,use OutputCharacterW//~vbmiR~
        UTRACEP("%s:USDuvioo=%x\n",UTT,Ppsd->USDuvioo);            //~vb4hR~
    	UTRACED("dddata",pdddata,ddlen);                           //~vb2LI~
    	UTRACED("dddbcs",pdddbcs,ddlen);                           //~vb2LI~
    }                                                              //~vb2LI~
    UTRACEP("%s:rc=%d\n",UTT,rc);                                  //~vb2LM~
    return rc;                                                     //~vb2LI~
#else                                                              //~vb2LI~
	return 0;                                                      //~vb2LI~
#endif                                                             //~vb2LI~
}//pan000draw                                                      //~vb2LI~
