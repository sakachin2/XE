//*CID://+vbi3R~:                             update#=  438;       //~vbi3R~
//***********************************************************
//* xescr.c                                                     //~5513I~
//***********************************************************   //~v016I~
//vbi3:180211 supprt command history list                          //~vbi3I~
//vbdn:171125 disable filemenu depending curent pcw type           //~vbdnI~
//vb7o:170119 (Bug)Errmsg top 2 byte corrupted when msg is over 2line(MAXCOL*2)//~vb7oI~
//vbCB:160820 Find cmd;add panel specific option                   //~vbCWI~
//vb4w:160814 (XXE bug)UNICOMB UNPR was ignore                     //~vb4wI~
//vb4u:160812 lineopt should be cleared when back to menu from file panel//~vb4uI~
//vb4t:160812 consider errmsg 2nd line for combine                 //~vb4tI~
//vb4k:160805 vb4f for LNX(specify ligature on/off,combine on/of line by line)//~vb4kI~
//vb4j:160806 (W32)OPT UNICOMP UNPR was effective only for file contents(chk at tabdisplay)//~vb4jI~
//vb4f:160802 (ULIB:v6Ei)specify ligature on/off,combine on/of line by line(used for edit/filename  panel)//~vb4fI~
//vb4e:160801 (W32)by vb3h buffmode revived,so force ligature on dirlist was lost when split//~vb4eI~
//vb4d:160731 (LNX) like W32(vb37), ligature on on dirlist         //~vb4dI~
//vb4c:160730 display altch for also cmdline/errmsg                //~vb4cI~
//vb48:160726 distingush NOLIGATURE for cmdline to set combine off //~vb48I~
//vb3h:160608 (W32)Bug of vb37. when vsplit and left:dir,right:menu. By f1 at dir display red(cdcd) on right because buffmode but buff was not set by left is dir//~vb3hI~
//vb39:160529 display unprintable for line1/2(hdr/errmsg,cmdline)  //~vb39I~
//vb37:160529 (BUG)u-c3bc(Hangle) was unprintable when ligature off(use WriteConsoleW one by one)//~vb37I~
//vb2Y:160405 by vb2U string remains on screen when split screen or exit xe if ligature mode ON//~vb2YI~
//vb2z:160212 LNX compiler warning                                 //~vb2zI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vafd:120612 (FC5)avoid uninitialized variable warning by gcc 4.1.1 on FC5(compile optio -Ox is required also)//~vafdI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//va5s:100514 display hdr line filename by dd fmt                  //~va5sI~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va3A:100309 (WINCON:BUG)"RGB value cannot be changed" err at enter on color panel//~va3AI~
//va3q:100219 (BUG)uviowrtcellstr len include vsplitline then override it.//~va3qI~
//            that is not valid for combined char enve refresh was issued.//~va3qI~
//va3p:100218 (BUG)missing update dbcstbl for vsplitline           //~va3pI~
//va3k:100210 (BUG:WIN-Console)vsplit line draw err                //~va3kI~
//va3j:100208 (LNX)try ligature for console version                //~va3jI~
//va3h:100207 try ligature for also win32 console version          //~va3hI~
//va21:091201 (BUG)draw invalid char after utf8 line draw          //~va21I~
//                 dbcs tbl should be cleared before uvio call     //~va21I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//va1C:091112 (UTF8)reffer pfh for filename codetype on errmsg     //~va1CI~
//va1q:091107 compchkm                                             //~va1qI~
//va1c:091030_merge GB18030 support                                //~va1cI~
//va10:091008!(XXE) treate input string as UTF8 or LOCALE for a line//~va10I~
//va0w:090919!assume locale if lognger than utf8 translation       //~va0wI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          locale/utf8 mixed errmsg                               //~va00I~
//          header line filename cv f2l                            //~va00I~
//v79T:081028 Gunxflag setup required for sedbcstbl from functinit;move to xe.c from xescr.c//~v79TI~
//v79F:081013 (XXE:BUG)unpdisp char of ini file is ignored         //~v79FM~
//v79B:081005 (LNX:BUG) vspli line disapper sometime               //~v79BI~
//v79z:080916 DBCS tbl for C and K of CJK                          //~v79zI~
//v780:080212 syntaxhighlight support                              //~v780I~
//v77m:080106*(BUG of v770)invalid dbcs tbl for header line INS/REP position//~v770I~
//v770:071114*(BUG)invalid dbcs tbl for header line INS/REP position//~v770I~
//v76v:070806 (BUG)cmd err reverse lenset err                      //~v76vI~
//v705:060727 graphic char setup by external file                  //~v705I~
//v69X:060720 (XXE)line-draw support also fo gxe when OPT LINECH ON.(v69M)//~v69XI~
//v69M:060713 (LNX)Change line drawing char effectiveness to optional. OPT LINECH [on|off]//~v69MI~
//            defaut is off because no code in iso8859 but in old IBM-PC Extended Char Set(ECS) only//~v69MI~
//v69F:060710 (LNX:BUG)box drawing not avail(use acs)              //~v69FI~
//v670:051224 cmd histry retrieve for each screen(A+F12)           //~v670I~
//v65c:050728 (XXE)8 color->16 color                               //~v65cI~
//v64a:050618 (LNX)xxe support                                     //~v64aI~
//v603:041220 multiline errmsg support(for find help msg)          //~v603I~
//v58b:040828 (Win:BUG)"Ins"/"Rep" is not re-written by ins toggle key.//~v58bI~
//            It may be caused by csr step up/down id is ctl char under windows xp.//~v58bI~
//v56p:040406 UCWFWAKEUP flag is cleared after filewakeup is called by scrpopup,//~v56pI~
//v55R:040319 (LNX)reset clearok after write,clearok remains effect after refresh?//~v55RI~
//v55L:040317 (UNX:BUG)xemainl flag is overriden by scrinit(parm ignored)//~v55LI~
//v51V:030808 v51A if for UNX;for WXE abend when scr size is shorten.//~v51VI~
//            (us Gscrbuffwidth for other than WXE)                //~v51VI~
//v51T:030808 Reverse write "INS" on hdr line because linux cursor type cannot be changed by ins/rep.//~v51TI~
//v51S:030808 (LNX) rh9 gnome-terminal support DBCS                //~v51SI~
//v51A:030711 abend when start screen size is narrow               //~v51AI~
//v519:030413 (LNX)chk terminal sim by new logic(ukbdl)            //~v519I~
//v500:021003 (WXE:BUG)initial color is all black.                 //~v500I~
//v500:020827 wxe support                                          //~v48rI~
//v48r:020601 (LNX)under X,clearok                                 //~v48rI~
//v47S:020403 (UNX) DBCS display corrupted when insert sbcs before DBCS//~v47SI~
//            because dbcs tbl already set by csrsetdbcstbl.       //~v47SI~
//v47r:020315 screen width  parm support(/Wnn)                     //~v47SI~
//v47r:020315 screen width  parm support(/Wnn)                     //~v47rI~
//v47m:020309 screen height parm support(/Hnn)                     //~v47mI~
//v479:020217 (UNX)use clearok only when dbcs line found           //~v479I~
//                 if not use clearok case,sbcs write,refresh and then dbcs write//~v479I~
//v478:020217 (UNX)use clearok if not splitted for redraw performance//~v478I~
//v45C:001227 (UNX)dbcs clear bypass if no line updated but fulldraw//~v45BI~
//v45B:001223 (LNX)kon abend why;onc clearok at first time then no abend//~v45BR~
//v45k:001215 UNX for hex mode,dbcs clear only when update,simple write when cursor move//~v45BR~
//v45i:011211 (AIX)default is to use clearok when fulldraw,it is fast.//~v45iI~
//v45h:011210 (UNX)dbcs line clear for errmsg                      //~v45hI~
//v45g:011210 (UNX)use clear_ok when full draw to fast screen draw //~v45fI~
//v45f:011209 (UNX)use v45e logic for alternative of clear at full draw//~v45fI~
//v45e:011209 (UNX)try once clear the csr line if containing dbcs line,//~v45eI~
//            actual write after refresh.                          //~v45eI~
//v45c:011209 (BUG)errmsg may override DBCS filename on hdr line   //~v45cI~
//v45b:011209 (BUG)long err msg overflow to another screen when vsplit case//~v45bI~
//v452:011208 (UNX)use dbcstbl of xe for csr attr write            //~v452I~
//			   because 2nd byte chk is also required but not avail.//~v452I~
//v43n:011101 display overflowed errmsg on the next line of hdr line//~v43nI~
//v424:010920 UNX:change scrclear for dbcs split to option (--c)   //~v424I~
//v41j:010820 UNX:dbcs err msg may be split by curse               //~v41jI~
//v41b:010718 AIX support:limit v40P to not dbcs mode              //~v41bI~
//v40Q:010720 LINUX:try v40P for linux kon                         //~v40PI~
//v40P:010718 AIX support:clear before refresh when full scr write //~v40PR~
//            (to avoid dbcs split by curses Escape sequence:csr move etc)//~v40PR~
//v40b:010327 LINUX support:ajust after merge                      //~v40bI~
//v401:010205 X support:kterm is dbcs like as kon                  //~v401I~
//v309:001205 AIX support:no highlight for dirlist lcmd field      //~v309I~
//v308:001130 AIX support:chtype format different(char is last 2 byte)//~v308I~
//v307:001129 AIX support:tate/yoko ID is unprintable              //~v307I~
//v305:001124 AIX support:tab disp char                            //~v305I~
//v21k:010113 LINUX support:dbcs ctl should be under kon even if euc//~v21kI~
//v20Z:001125 LINUX support:monocolor:err msg by reverse           //~v20ZI~
//v20y:001028 new function:filename selection on menu 1/2 name list//~v20yI~
//v20q:001015 max color number display on panel 0.0                //~v20qI~
//v20n:001015 LINUX support(fix max color=8)                       //~v20nI~
//v19z:000924 LINUX support(mono color support)                    //~v19zI~
//v19p:000917 LINUX support(max color=8(<--16))                    //~v19pI~
//v19f:000904 LINUX support(use curses)                            //~v19fI~
//v11N:990829 COL cmd support                                      //~v11NI~
//v11e:990710 (BUG) abend at scrdisp when other split side is gone by//~v11eI~
//            RE-edit/browse cmd(same file name).No pcw enqed by Gstatus remain//~v11eI~
//            as splitted.                                         //~v11eI~
//v11b:990626 (Win)redirect err msg(getconsolemode may ok,but err at setcurcor etc)//~v11bI~
//v10t:990404 csr restore after view split end                     //~v10tI~
//v105:981212 no csr restore at popup,it is better to move to home pos when menu//~v105R~
//v0jc:980721 W95-->WIN                                            //~v0jcI~
//v0i4:980503 try not PROCESS_OUTPUT for outputto chk strip onscreen trouble//~v0i4R~
//v0i3:980503 consolemode restore should be done at scrreset for abend case//~v0i3I~
//v0hi:980201 over v0hh,csr set is requierd for DOS                //~v0hiI~
//v0hh:980131 DOS under NT english,if setmode at term,printf msg is not displayed//~v0hhI~
//            until re-open dos box.-->avoid setmode but clear scr by space.//~v0hhI~
//            No problem if scrclear by space write;reason is unclear but.//~v0hhI~
//v0hg:980131 scr height for W95 english mode(set value included IME line,//~v0hgI~
//            caller chk english mode and count down.it is same as DOS)//~v0hgI~
//            W95 return lineno containning ime line               //~v0hgI~
//            is_win return 1 when W95 but 0 when WNT              //~v0hgI~
//            so use new function udosiswinnt for DOS.             //~v0hgI~
//            OS2 DOS session hight is 24 for win,25 for fullscr.  //~v0hgI~
//            win has ime on out of crient area,full scr has no ime line.//~v0hgI~
//            so return as DOS area,xescr ajust to 24 line both.   //~v0hgI~
//            fullscreen may have ime line with 24.-->no ajust.    //~v0hgI~
//v0h9:980118 performance tuning when vsplit                       //~v0h9I~
//            use buff write for active screen                     //~v0h9I~
//            split line write must before buffmode reset to write from buff next time//~v0h9I~
//v0h8:980118 (BUG)when vsplit,left screen boundary splitted DBCS effect to boundary char//~v0h8I~
//v0h7:980116 (BUG)inactdrawsw init clear missing;cause performance down whe vsplit//~v0h7I~
//v0h6:980116 performance tuning                                   //~v0h6I~
//            avoid double screen write by char and followed csr move//~v0h6I~
//            (func_char set GPROCSCSRRIGHT/GPROCSCSRDOWN by calling//~v0h6I~
//            csrcharright or filecharcsr(call csrcharright/csrchardown).//~v0h6I~
//            kbdproc simulate csr right/down input when flag on.  //~v0h6I~
//            so,if these flag on bypass scrdisp.screen will be written//~v0h6I~
//			  at this simulated key event)                         //~v0h6I~
//v0h4:980116 (W32)performance(wrice a once)                       //~v0h4I~
//v0h3:980116 (W32)NT support                                      //~v0h3I~
//                 for cell write required case(NT,english mode)   //~v0h3I~
//            xescr.c                                              //~v0h3I~
//v0h2:980115 uget/usetconsolemode for std in/out each             //~v0h2I~
//v09o:970519:rewrite vsplit line only for redraw line             //~v090I~
//            (errmsg cut by modification of v09m)                 //~v090I~
//v09n:970519:err msg must be displayed on old active pcw          //~v09nI~
//v095:970405:DPMI version                                         //~v095I~
//            -INS/REP-->ins/rep for DPMI                          //~v095I~
//            -not used variable                                   //~v095I~
//v08i:961109:(W95)draw performance(block write for cap block)     //~v08iI~
//v08g:961106:split uvio to uvio and uvio2                         //~v08gI~
//v08e:961104:(W95)performance up                                  //~v08cI~
//				  cell setup by char string and WORD attr table    //~v08cI~
//v08c:961104:(BUG)capreset must be executed before plh free       //~v08cI~
//                 must be call not from deqcw but from end/cancel //~v08cI~
//v08b:961103:(BUG)when first split popupped,UCWpsd point 1st half of USD//~v08bI~
//                 but USDpfld etc is of 2nd half which disppeared.//~v08bI~
//                 for win95 it may be page freed cause c0000005.  //~v08bI~
//v089:961102:(W95)write screen by once.                           //~v089I~
//            scr.c                                                //~v089I~
//v085:961024:W95 VC                                               //~v085I~
//            write white space at screen reset(same as os/2)      //~v085I~
//            cls by not scroll(scroll not effective whe fullscreen of w95)//~v085I~
//            screen height -1 for IMM line                        //~v085I~
//            pallette change not avail msg                        //~v085I~
//v079:960610:color option-2                                       //~v079I~
//            .(BUG)fullscreen pallette14(yellow)is hilight after windows mode end//~v079I~
//v075:960608:color option                                         //~v075I~
//v06v:960406:assign pallette no to dir,cmd                           //~v06vI~
//v061:960211:SHELL cmd(CMD,COM,>>)                             //~v061I~
//v04e:951001:initial malloc for uvio work(uvio.c) to avoid storage//~v04eI~
//            shortage at draw,so free at scrreset              //~v04eI~
//v04d:950930:malloc/calloc rc chk for dos                      //~v04dI~
//*v037:950723:pcw enq to target option to display FIFO seq for dir//~v037I~
//*v032:950712:UFLD for each ppc(move panregist first to paninit)//~v032I~
//v017:950701:dos/os2 id on hdr line(rep/ins) DOS upper,OS/2 lower//~v017I~
//            scrreset                                          //~v017I~
//v016:950627:for warp english version,clear scr at term        //~v016I~
//            scrreset                                          //~v016I~
//***********************************************************   //~5513I~
//*950513 english display mode 3,no more condideration for scroll up//~5513I~
//*       (uvio.c process by direct video buff write)           //~5513I~
//*950105 next/prev panel cmd                                   //~5105R~
//*941207 draw hdr line before err msg override                 //~5105I~
//***********************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifdef UNX                                                         //~v401I~
  #ifndef XXE                                                      //~v64aI~
	#include <termios.h>                                           //~v401R~
  #endif                                                           //~v64aI~
#endif                                                             //~v401I~
#ifdef DOS
#else
	#ifdef W32                                                     //~v085I~
//    #ifndef WXE                                                  //~v500R~//~va1cR~
	    #ifdef UTF8SUPPH                                           //~va1qI~
		#include <windows.h>                                       //~v085I~
        #endif                                                     //~va1qI~
//    #endif //!WXE                                                //~v500R~//~va1cR~
	#else                                                          //~v085I~
	#define INCL_BASE
	#include <os2.h>
	#endif                                                         //~v085I~
#endif
#ifdef UTF8SUPPH                                                   //~va1qI~
#ifdef LNX                                                         //~va1cR~
	#define _XOPEN_SOURCE_EXTENDED		//ncurses define           //~va1cR~
	#include <ucurses.h>	         //v1.3 add                    //~va1cR~
#endif                                                             //~va1cR~
#endif                                                             //~va1qI~
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <uque.h>
#include <uvio.h>
#include <uvio2.h>                                                 //~v08gI~
#include <ufile.h>                                              //~5318R~
#include <ualloc.h>                                             //~5318I~
#include <utrace.h>                                             //~5430I~
#include <udbcschk.h>                                              //~v21kR~
#ifdef UNX                                                         //~v19fI~
  #ifdef XXE                                                       //~v64aI~
	#include <uviol.h>                                             //~v69XI~
  #else                                                            //~v64aI~
	#include <uviol.h>                                             //~v19fI~
	#include <ukbdl.h>                                             //~v19zI~
  #endif //!XXE                                                    //~v64aI~
#else //!UNX                                                       //~v19fI~
#ifdef DOS                                                         //~v085I~
    #include <udos.h>                                              //~v085I~
#else                                                              //~v085I~
	#ifdef W32                                                     //~v0h2I~
    	#include <ukbd.h>                                          //~v0h2I~
    	#include <ukbdw.h>                                         //~v0h2I~
	#endif                                                         //~v0h2I~
#endif                                                             //~v085I~
#endif //!UNX                                                      //~v19fI~
#ifdef UTF8SUPPH                                                   //~va00I~
    #include <utf.h>                                               //~va00I~
    #include <uviom.h>                                             //~va1cR~
#endif                                                             //~va00I~
                                                                //~5318I~
#include "xe.h"
#define  XESCR_GLOBAL                                              //~v500I~
#include "xescr.h"
#include "xescr2.h"
#include "xecsr.h"
#include "xepan.h"
#include "xefile.h"
#include "xefile2.h"                                               //~v08bI~
#include "xefunc.h"
#include "xefunct.h"                                            //~5424I~
#include "xegbl.h"                                                 //~v20qI~
#include "xesub.h"                                                 //~v43nI~
#ifdef UTF8SUPPH                                                   //~va1qI~
#include "xesub2.h"                                                //~va1cR~
#endif                                                             //~va1qI~
#include "xedir.h"                                                 //~v56pI~
#include "xedir2.h"                                                //~v56pI~
#ifdef XXE                                                         //~v64aR~
	#include "xxexei.h"                                            //~v64aI~
#endif                                                             //~v64aI~
//#include "xecap.h"                                               //~v08cR~
#ifdef WXE                                                         //~v500I~
	#include "wxexei.h"                                            //~v500I~
#endif //!WXE                                                      //~v500I~
#include "xesyn.h"                                                 //~v780I~
#include "xeutf.h"                                                 //~v780I~//~va00I~
//*******************************************************          //~v45eI~
#define  DBCS_CLEAR_CHAR ' '	//clear dbcs char                  //~v45eR~
#define  INSWORDPOS_MIN          8   //=FILENAMEPOS   8            //~v51VI~
//*******************************************************
//*******************************************************          //~v500I~
static  PUSCRD Spuscrd;			//screen line table ptr
static  UCHAR  Sstepdownid;	//id of csr stepdown mode           //~5225I~
static  UCHAR  Ssteprightid;//id of csr stepright mode          //~5225I~
static	VIOMODEINFO Smodeinfo;
static  UCHAR Soldattrc;          //for setmode at return          //~v0hhR~
#ifdef W32                                                         //~v0i4I~
  #ifndef WXE                                                      //~v500R~
static UCHAR Sw95consolemode_chng;//consolemode changed sw         //~v0i3I~
  #endif //!WXE                                                    //~v500R~
#endif                                                             //~v0i4I~
static	UCHAR Svline[2]="|";	//char and attr
static  struct {VIOPALSTATE palstate;USHORT col1_15[15];}
#ifdef UNX                                                         //~v19pI~
    #ifdef XXE                                                     //~v65cI~
		Spalsave={{38,0,0}},Spalreq={{38,0,0}};//16:color pallette //~v65cI~
    #else                                                          //~v65cI~
		Spalsave={{22,0,0}},Spalreq={{22,0,0}};//color pallette    //~v19pI~
    #endif                                                         //~v65cI~
#else                                                              //~v19pI~
		Spalsave={{38,0,0}},Spalreq={{38,0,0}};//color pallette //~5430R~
#endif                                                             //~v19pI~
static  PVOID Spsdcelldata;
static  PVOID Spsddbcstbl;
                                                                   //~v08cI~
#ifdef  W32                                                        //~v08eR~
static	USHORT *Sw95attrtbl;	//win95 attr WORD table            //~v08eR~
  #ifndef WXE                                                      //~v500R~
static UINT Sw95consolemode_stdo;//for restore console mode at entry//~v0h2R~
  #endif //!WXE                                                    //~v500R~
#endif                                                             //~v08eR~
                                                                   //~v45eI~
#ifdef  UNX                                                        //~v45eI~
  #ifndef XXE                                                      //~v64aI~
	static	UCHAR *Sunxattrcleartbl=0;	//for clear dbcs line      //~v45eI~
	static	UCHAR *Sunxdbcscleartbl=0;	//for clear dbcs line      //~v47SI~
typedef struct _UCLSVT {                                           //~v45fR~
    				PUSCRD UCLSVTpsd;                              //~v45fI~
    				int    UCLSVTlen;                              //~v45fI~
    				int    UCLSVTy;                                //~v45fI~
					int    UCLSVTx;                                //~v45fI~
                } UCLSVT, *PUCLSVT;                                //~v45fR~
#define UCLSVTSZ (sizeof(UCLSVT))                                  //~v45fI~
	static	PUCLSVT Spuclsvt=0;	//for clear dbcs line              //~v45fR~
  #endif //!XXE                                                    //~v64aI~
#endif                                                             //~v45eI~
//*                                                             //~5430I~
//static UCHAR  *Sscrlinetype[]={                                  //~v095R~
//         "Title-Line(FG)" ,"Title-Line(BG)" ,                    //~v095R~
//         "Panel-Frame(FG)" ,"Panel-Frame(BG)" ,                  //~v095R~
//         "Browse-Lineno(FG)","Browse-Lineno(BG)",                //~v095R~
//         "Browse-File(FG)","Browse-File(BG)",                    //~v095R~
//         "Edit-Lineno(FG)","Edit-Lineno(BG)",                    //~v095R~
//         "Edit-File(FG)","Edit-File(BG)",                        //~v095R~
//         "DirList-Linecmd(FG)","DirList-Linecmd(BG)",            //~v095R~
//         "DirList-Lineno(FG)","DirList-Lineno(BG)",              //~v095R~
//         "DirList-File(FG)","DirList-File(BG)",                  //~v095R~
//         "CmdOut-Lineno(FG)","CmdOut-Lineno(BG)",                //~v095R~
//         "CmdOut-Result(FG)","CmdOut-Result(BG)",                //~v095R~
//		 0};                                                       //~v095R~
//*                                                             //~5430I~
static 	UQUEH Sclientwq[2];  //client work q
                                                                   //~v40bI~
#ifdef UNX                                                         //~v40bI~
  #ifndef XXE                                                      //~v64aI~
static  UCHAR Smonopalltbl[PAL_MAXENTRY*2];//pallette no assign tbl for mono color//~v19zI~
  #endif //!XXE                                                    //~v64aI~
#endif //!UNX                                                      //~v40bI~
//#ifdef WXE                                                       //~v64aR~
#ifdef WXEXXE                                                      //~v64aI~
    static int Sinitmaxcol=0,Sinitmaxrow=0;                        //~v500I~
#endif                                                             //~v500I~
static  UCHAR *Smultilineerrmsgtop=0;       //2nd line of multiline errmsg//~v603R~
static  UCHAR *Smultilineerrmsgnext=0;       //2nd line of multiline errmsg//~v603R~
static int Stermsw=0;                                              //~vb4uI~
                                                                   //~v40bI~
//***********
#ifdef UNX                                                         //~v40bI~
  #ifndef XXE                                                      //~v64aI~
UCHAR *scrsetmonopall(void);                                       //~v19zI~
int scrdbcslineclearerrmsg(int Pcol,int Prow,int Plen,UCHAR *Pstring,UCHAR *Ppdbcs);//~v45hI~
int scrdbcslineclear(int Pcol,int Prow,int Plen,UCHAR *Pcell,UCHAR *Ppdbcs);//~v45hR~
  #endif //!XXE                                                    //~v64aI~
#endif //!UNX                                                      //~v40bI~
//int scrdbcsoverwrite(int Pdest,int Pposx,int Pposy,char *Pattr); //~v45hR~
int scrsavemultilineerrmsg(UCHAR *Perrmsg);                        //~v603I~
int scrsetinsrepdbcs(PUCLIENTWE Ppcw,PUSCRD Ppsd);                 //~v770I~
#ifdef UTF8SUPPH                                                   //~va00I~
//	UINT xescrerrmsgbycell(char *Perrmsg,char *Pcodetype,int Plen,int Prow,int Pcol);//~vb4fR~
  	UINT xescrerrmsgbycell(int Popt,char *Perrmsg,char *Pcodetype,int Plen,int Prow,int Pcol);//~vb4fI~
	int scrcell2tocell(char *Pdata,char *Pcell,int Poffs,int Plen);//~va00R~
#endif                                                             //~va00I~
#ifdef WXEXXE                                                      //~vbdnI~
	int scrSetUpdateFileMenu(int Popt,PUCLIENTWE Ppcw);            //~vbdnR~
#endif                                                             //~vbdnI~
//****************************************************************
// scrinit 
//*screan header init
//*return :rc=0
//****************************************************************
//int scrinit(int Pheightparm)                                     //~v47rR~
int scrinit(int *Pscrparm)                                         //~v47rI~
{
	UINT rc;
	PUSCRD psd;
	UCHAR *pc,*pcd;
	UCHAR *ppall;                                                  //~v19zI~
	int i,j;
	int len;
static	VIOINTENSITY intensbgh={6,2,1};	//backbround highlight
#ifdef DOS                                                         //~v085I~
//#define  W95DOSBOXVER       7                                    //~v0hgR~
//#define  W95DOSBOXREVISION  0xff                                 //~v0hgR~
    int  mjv,mnv;	//dos version                                  //~v085R~
//  char rvn;			//dos revision                             //~v0hgR~
    int  mode;  		//win mode                                 //~v0hgI~
#endif                                                             //~v085I~
//#ifdef LNX                                                         //~v401I~ ,//~v79TR~
//  #ifndef XXE                                                      //~v64aI~ ,//~v79TR~
//    int termid;                                                    //~v401I~ ,//~v79TR~
//  #endif //!XXE                                                    //~v64aI~ ,//~v79TR~
//#endif                                                             //~v401I~ ,//~v79TR~
#ifdef UTF8SUPPH                                                   //~va1cR~
    int opt;                                                       //~va1cR~
//  char optch[3];                                                 //~va3jR~
    char optch[8];                                                 //~va3jI~
#endif                                                             //~va1cR~
//*********************************
//#ifdef W32                                                       //~v47rM~
//#if defined(W32) || defined(AIX)                                 //~v47rR~
#if defined(W32) || defined(UNX)                                   //~v47rI~
  #ifndef XXE                                                      //~v64aI~
//    uvio_initparm(Pheightparm,0);    //user screen height specification//~v47rM~
      uvio_initparm(Pscrparm);    //user screen height/width specification//~v47rM~
  #endif //!XXE                                                    //~v64aI~
#endif                                                             //~v47rM~
#ifdef UNX                                                         //~v19zI~
  #ifndef XXE                                                      //~v64aI~
//  rc=uviol_init(Gkbdopt);    //parm from xemainl.c-->xegbl.c-->  //~v47rR~//~vb2zR~
    rc=(UINT)uviol_init(Gkbdopt);    //parm from xemainl.c-->xegbl.c-->//~vb2zI~
    if (rc==2)  //heightparm err                                   //~v47rI~
        exit(2);                                                   //~v47rI~
  #endif //!XXE                                                    //~v64aI~
#endif                                                             //~v19zI~
	if ((rc=uviogetmode(&Smodeinfo),rc))
    {                                                              //~v401I~
      if (rc==1)                                                   //~v11bR~
		uerrexit("Win:STDOUT redirection not allowed ",            //~v11bR~
				 "Winで標準出力のリダイレクトはできません");       //~v11bR~
      else                                                         //~v11bI~
        if (rc==2)  //heightparm err                               //~v47mI~
            exit(2);                                               //~v47mI~
        else                                                       //~v47mI~
		uerrexit("xescr:vio init(modeget) failed,rc=%d",
				 "xescr:VIO 初期化(modeget)失敗,rc=%d",rc);
    }                                                              //~v401I~
    UTRACED("uviogetmode",&Smodeinfo,sizeof(Smodeinfo));           //~vafkI~
	if (Smodeinfo.attrib==3)	
	{
    	Soldattrc=Smodeinfo.attrib;                                //~v0hhI~
		Smodeinfo.attrib=1;
		if (rc=uviosetmode(&Smodeinfo),rc)
			uerrexit("xescr:vio init(modeset) failed,rc=%d",
					 "xescr:VIO 初期化(modeset)失敗,rc=%d",rc);
	}	
	csrinit(Smodeinfo.vres/Smodeinfo.row);		//pass pell
//*******************************************************
//*set color reg
//#ifdef WXE  //use default on xegbl Gpallette                     //~v500R~
//    scrsetpallette(Gpallette);  //set and save to Gpallette      //~v500R~
//#else                                                            //~v500R~
	rc=uviogetstate(&Spalsave);	//save pallette status
	if (rc==ERROR_VIO_EXTENDED_SG)	//not full screen           //~5430R~
    {                                                           //~5430I~
//    	uerrmsg("Extended segment(pallete reg setting not avail)",//~5527R~
//  			"ウィンドウモード(パレットのカラー設定は無効です)");//~5527R~
		UCBITON(Gscrstatus,GSCRSEXTSG);//bypass reset at termination
//      memset(Gpallette,0xff,16);	//clear current value          //~v079R~
    }                                                           //~5430I~
	else
	{
		if (rc)
			uerrexit("xescr:vio init(VioGetState) failed,rc=%d",
						 "xescr:VIO 初期化(VioGetState)失敗,rc=%d",rc);
//save os default                                                  //~v075M~
//  	for (i=0;i<16;i++)                                         //~v19pR~
    	for (i=0;i<MAX_COLOR;i++)                                  //~v19pI~
			Gdefpallette[i]=(UCHAR)Spalsave.palstate.acolor[i];    //~v075I~
//*enable backbround hilight(deney brink)
		rc=uviosetstate(&intensbgh);
		if (rc)			//err
      		uerrexit("xescr:vio init(VioSetState-set BG intensity) failed,rc=%d",
       				 "xescr:VIO 初期化(VioSetState-BG高輝度設定)失敗,rc=%d",rc);
//  	UTRACED("default pallette",&Spalsave,sizeof(Spalsave)); //~5430R~
		Spalreq=Spalsave;           //first time default           //~v075I~
		scrsetpallette(Gpallette);	//set and save to Gpallette    //~v075R~
	}
//#endif  //!WXE                                                   //~v500R~
//* color attr tbl
//  scrsetattrtbl(Gattrtbl,Gpallassigntbl);                        //~v19zI~
#ifdef UNX                                                         //~v40bI~
  #ifndef XXE                                                      //~v64aI~
	if (Smodeinfo.color==1)	//mono color	                       //~v19zI~
    	ppall=scrsetmonopall();                                    //~v19zR~
    else                                                           //~v19zI~
  #endif //!XXE                                                    //~v64aI~
#endif //!UNX                                                      //~v40bI~
    	ppall=Gpallassigntbl;                                      //~v19zI~
//set maxcolor for xepan                                           //~v20qI~
    Gmaxcolor=1;                                                   //~v20qI~
    for (i=0;i<Smodeinfo.color;i++)                                //~v20qI~
        Gmaxcolor<<=1;                                             //~v20qI~
                                                                   //~v20qI~
    scrsetattrtbl(Gattrtbl,ppall);                                 //~v19zI~
//**************************************************
	len=Gscrwidth=Smodeinfo.col;		//max column
    if (Gscrwidth<MINCOLUMN)                                       //~v51AI~
        uerrexit("screen width err (cur=%d < min=%d).",0,          //~v51AR~
					Gscrwidth,MINCOLUMN);                          //~v51AI~
	len=((len+3)/4)*4;					//boundary up
	Gscrheight=Smodeinfo.row;			//max row
//	if (!UCBITCHK(Gscrstatus,GSCRSDBCS))	//sbcs   mode       //~5513R~
//		Gscrheight--;						//avoid scroll up   //~5513R~
#ifdef DOS                                                         //~v085I~
//  udos_version(&mjv,&mnv,&rvn);                                  //~v0hgR~
//  if (mjv==W95DOSBOXVER && rvn==W95DOSBOXREVISION)               //~v0hgR~
  if (UCBITCHK(Gscrstatus,GSCRSDBCS))	//not englist mode         //~v0hgM~
    if (udosiswinnt() || uwin_version(&mjv,&mnv,&mode)) //nt or win//~v0hgR~
    	Gscrheight--;					//for imm line             //~v085I~
//    else                                                         //~v0hgR~
//        if (udosisos2())    //OS2                                //~v0hgR~
//            if (Gscrheight==25)   //fullscreen has no ime        //~v0hgR~
//                Gscrheight=24;   //no need consider ime line     //~v0hgR~
                                                                   //~v0hgI~
#else                                                              //~v085I~
#ifdef W32                                                         //~v085I~
  #ifndef WXE                                                      //~v500R~
  	if (UCBITCHK(Gscrstatus,GSCRSDBCS))	//not englist mode         //~v0hgI~
	Gscrheight--;						//imm line                 //~v085I~
  #endif //!WXE                                                    //~v500R~
#endif                                                             //~v085I~
#endif                                                             //~v085I~
//  psd=Spuscrd=UALLOCM((UINT)(USCRDSZ*Gscrheight*2));//data control tbl//~v04dR~//~vb2zR~
    psd=Spuscrd=UALLOCM((UINT)((int)USCRDSZ*Gscrheight*2));//data control tbl//~vb2zI~
//  memset(psd,0,(UINT)(USCRDSZ*Gscrheight*2));//clear flag3       //~v780I~//~vb2zR~
    memset(psd,0,(UINT)((int)USCRDSZ*Gscrheight*2));//clear flag3  //~vb2zI~
	Gscrdbcstbl=UALLOCM((UINT)(Gscrwidth * Gscrheight));        //~v04dR~
    memset(Gscrdbcstbl,0,(UINT)(Gscrwidth * Gscrheight));          //~v45BR~
#ifdef W32                                                         //~v08eR~
  #ifndef WXE                                                      //~v500R~
    Sw95consolemode_stdo=ugetconsolemode(1);//save stdout consolemode at entry//~v0h2R~
//  usetconsolemode(1,ENABLE_PROCESSED_OUTPUT);//recover consolemode at entry//~v0i4R~
  if (Sw95consolemode_stdo==0xffffffff)	//redirected               //~v11cI~
    Sw95consolemode_chng=0;     //need not restore at reset/term   //~v11cI~
  else                                                             //~v11cI~
  {                                                                //~v11cI~
    usetconsolemode(1,0);	//stdout;no processed_input/eol wrap   //~v0i4R~
    Sw95consolemode_chng=1;     //should be restore at reset/term  //~v0i3I~
  }                                                                //~v11cI~
  #endif //!WXE                                                    //~v500R~
	Sw95attrtbl=UALLOCC(1,(UINT)(Gscrwidth*sizeof(USHORT)));       //~v08eR~
#endif                                                             //~v08eR~
//  Spsdcelldata=pc=UALLOCM16((UINT)(len*3*Gscrheight*2));//cell(2)+data(1)//~v780R~
    Spsdcelldata=pc=UALLOCM16((UINT)(len*4*Gscrheight*2));//cell(2)+data(1)+style(1)//~v780R~
    memset(pc,0,(UINT)(len*4*Gscrheight*2));                       //~v780I~
	Spsddbcstbl=pcd=UALLOCC(1,(UINT)(len*Gscrheight*2));//dbcs id tbl//~v04dR~
	for (j=0;j<2;j++)
	{
		for (i=0;i<Gscrheight;i++,psd++)
		{
			memcpy(psd->USDcbid,USDCBID,4);	//acronym           //~5105I~
			psd->USDrow=i;			//line no
			psd->USDcell=pc;
			pc+=len*2;
			psd->USDdata=pc;
			pc+=len;
			psd->USDstyle=pc;                                      //~v780R~
			pc+=len;                                               //~v780I~
			psd->USDdbcs=pcd;
			pcd+=len;
		}//i
	}//j
	*(Svline+1)=Gattrtbl[COLOR_TITLE];	//virtical split line
#ifdef LNX                                                         //~v21kR~
  #ifdef XXE                                                       //~v64aI~
////  if (Gunxflag & GUNX_EUC)      //by udbcschkcp(LANG chk) at xe.c//~v79zR~  ,//~v79TR~
//    Gunxflag |= GUNX_KON;       //always dbcs avail                //~v79zI~  ,//~v79TR~
//    if ((Gunxflag & GUNX_EUC)      //by udbcschkcp(LANG chk) at xe.c//~v79zI~ ,//~v79TR~
//    ||   UDBCSCHK_ISUTF8J())       //EUC+UTF8                      //~v79zI~  ,//~v79TR~
//    {                                                              //~v64aI~  ,//~v79TR~
////      Gunxflag |= GUNX_KON;       //dbcs avail                   //+v79zR~  ,//~v79TR~
////      gblkon(KON_TABDISP);    //rest tab disp char               //+v79FR~  ,//~v79TR~
////      gblkon(KON_UNPCHAR);    //rest unprintable char            //+v79FR~  ,//~v79TR~
//    }                                                              //~v64aI~  ,//~v79TR~
  #else                                                            //~v64aI~
//  if (Gscrheight>25)						//may be con           //~v21kR~
//  if (uviol_konchk()) 					//may be con           //~v21kI~    ,//~v79TR~
    if (Gunxflag & GUNX_KONTERM)   //KON by uviol_konchk                        ,//~v79TI~
    {                                                              //~v305M~
//  	Gunxflag |= GUNX_KON;                                      //~v305M~    ,//~v79TR~
        gblkon(KON_TABDISP);    //rest tab disp char               //~v305M~
        gblkon(KON_UNPCHAR);    //rest unprintable char            //~v305M~
    }                                                              //~v305M~
    else                                                           //~v21kI~
    {                                                              //~v401I~
//      termid=ukbdl_gettermid();                                  //~v401I~    ,//~v79TR~
//     if (termid & TERM_SIMID) 	//term sim                     //~v519R~    ,//~v79TR~
//  		Gunxflag|=GUNX_UNDERX;                                 //~v519I~    ,//~v79TR~
//      if (termid & TERM_XTERM)	//xterm/kterm                  //~v519R~    ,//~v79TR~
//	    if ((termid & TERM_SIMID)==TERM_XTERMSIM)	//under xterm sim//~v519I~  ,//~v79TR~
  		if (Gunxflag & GUNX_XTERM)    //DBCS not avail on emulater xterm//~v79TI~
        {                                                          //~v401I~
	        gblkon(KON_TABDISP);    //rest tab disp char           //~v401I~
	        gblkon(KON_UNPCHAR);    //rest unprintable char        //~v401I~
//  		Gunxflag |= GUNX_UNDERX;                               //~v519R~
        }                                                          //~v401I~
//        else                                                       //~v519I~  ,//~v79TR~
////      if (termid==TERM_KTERM)                                    //~v519R~  ,//~v79TR~
////      if ((termid & TERM_SIMID)==TERM_KTERMSIM)   //under kterm sim//~v51SR~,//~v79TR~
//        if ((termid & TERM_SIMID))  //other sim under X            //~v51SI~  ,//~v79TR~
//        {                                                          //~v48rI~  ,//~v79TR~
////          Gunxflag |= GUNX_KON;                                  //~v48rR~  ,//~v79TR~
////          Gunxflag |=( GUNX_KON|GUNX_UNDERX);                    //~v519R~  ,//~v79TR~
//            Gunxflag |= GUNX_KON;                                  //~v519I~  ,//~v79TR~
////          Gkbdopt  |=UKBDL_CLEAR;  //clear  even if split        //~v55LR~  ,//~v79TR~
//        }                                                          //~v48rI~  ,//~v79TR~
//        else                                                       //~v519I~  ,//~v79TR~
//        if (termid & TERM_UNDERKON)     //under kon                //~v519R~  ,//~v79TR~
//        {                                                          //~v519I~  ,//~v79TR~
//            Gunxflag |= GUNX_KON;                                  //~v519I~  ,//~v79TR~
////          Gkbdopt  |=UKBDL_CLEAR;  //clear  even if split        //~v55LR~  ,//~v79TR~
//        }                                                          //~v519I~  ,//~v79TR~
//        else                                                       //~v401I~  ,//~v79TR~
  	  if (Gunxflag & GUNX_FENG)    //force english                 //~v79TI~
        udbcschk_forceenglish();    //clear dbcschk tbl            //~v21kI~
    }                                                              //~v401I~
  #endif //!XXE                                                    //~v64aI~
#endif                                                             //~v305M~
#ifdef UNX                                                         //~v307R~
    Sstepdownid='|';                                               //~v307I~
    Ssteprightid='=';                                              //~v307I~
//#ifndef XXE                                                      //~vb4wR~
    uviol_init2(Gscrdbcstbl);    //for csr write                   //~v452I~
  #ifndef XXE                                                      //~vb4wI~
//get clear line for kanji clear write                             //~v45eI~
  #ifdef AIX                                                       //~v45eI~
   	if (UCBITCHK(Gscrstatus,GSCRSDBCS))	//for lang=SJIS            //~v45eI~
  #else                                                            //~v45eI~
//  if (Gunxflag & GUNX_KON)                                       //~v79zR~
	if (XE_ISDBCSKON()) //CJK(J:EUC) and GUNX_KON                  //~v79BR~
  #endif                                                           //~v45eI~
   {                                                               //~v79zI~
    if (Gkbdopt & UKBDL_CLEARDBCS)	//dbcs clear mode option       //~v45kR~
//*** UKBDL_CLEARDBCS is never on when UTF8UCS2 (see xemainl.c)    //~va21I~
  	{                                                              //~v45fI~
//      Sunxattrcleartbl=UALLOCM((UINT)(Gscrwidth*sizeof(USHORT)));//~v45BR~
//      Sunxattrcleartbl=UALLOCM((UINT)(Gscrwidth*sizeof(USHORT))*2);//~v45BI~//~vb2zR~
        Sunxattrcleartbl=UALLOCM((UINT)(Gscrwidth*(int)sizeof(USHORT))*2);//~vb2zI~
        Sunxdbcscleartbl=UcALLOC((UINT)(Gscrwidth*Gscrheight));    //~v47SR~
//  	Spuclsvt=UALLOCM((UINT)(UCLSVTSZ*Gscrheight*2));//data control tbl//~v45fR~//~vb2zR~
    	Spuclsvt=UALLOCM((UINT)((int)UCLSVTSZ*Gscrheight*2));//data control tbl//~vb2zI~
    }                                                              //~v45fI~
  #ifdef LNX                                                       //~v79zI~
    else //--1 cmd line option deny default UKBDL_CLEARDBCS        //~v79zI~
        uvio_wcinit(UDCWCIO_VIOCLEARDBCS,0/*converter*/);  //clear then write if dbcsline//~v79zR~
  #endif                                                           //~v79zI~
   }                                                               //~v79zI~
  #endif //!XXE                                                    //~v64aI~
#else                                                              //~v307I~
  #ifdef WXE                                                       //~v500I~
    Sstepdownid='|';                                               //~v500I~
    Ssteprightid='=';                                              //~v500I~
    	uvio_init2(0,Gscrdbcstbl);    //for csr write              //~vb4jI~
  #else                                                            //~v500I~
//  Sstepdownid=functblsrch(FUNCID_GRAPHCHAR_VL)->FTchar;//get VL char//~v58bR~
//  Ssteprightid=functblsrch(FUNCID_GRAPHCHAR_HL)->FTchar;//get HL char//~v58bR~
    #ifdef W32                                                     //~v79zI~
    	uvio_init2(0,Gscrdbcstbl);    //for csr write              //~v79zR~
    #endif                                                         //~v79zI~
    Sstepdownid='|';                                               //~v58bI~
    Ssteprightid='=';                                              //~v58bI~
  #endif                                                           //~v500I~
#endif                                                             //~v307I~
//#ifdef WXE                                                       //~v51VR~
    Gscrbuffheight=Gscrheight;    //buff max size,row              //~v500R~
    Gscrbuffwidth=Gscrwidth;     //buff max size,col               //~v500R~
//#ifdef WXE                                                       //~v64aR~
#ifdef WXEXXE                                                      //~v64aI~
    Gscrheight=Sinitmaxrow;       // for paninit                   //~v500I~
    Gscrwidth =Sinitmaxcol;                                        //~v500I~
#endif                                                             //~v500I~
#ifdef LNX                                                         //~v69FI~
	scracssetup(Gopt5 & GOPT5ACS);	//now no acs mode              //~v69MR~
#endif    	                                                       //~v69FI~
#ifdef UTF8SUPPH                                                   //~va1cR~
    Gutfmode2|=GUM2_MIXEDWORDMODE;			//allow UTF8/LOCALE word by word//~va1cR~
    opt=UVIOMO2_PADON*(UCBITCHK(Gopt,GOPTTABDISPLAY)!=0);          //~va1cR~
    optch[0]=Gunpdispchar[0];   //alternative for unprintable      //~va1cR~
    optch[1]=Gfiletabdisp2;     //for dbcs padding                 //~va1cR~
    optch[2]=XEUTF_MIXEDFLDCOLOR;                                  //~va1cR~
#ifdef UTF8UCS2                                                    //~va20I~
    optch[3]=Gunpdispchar[3];   //dbcs space alt char              //~va20I~
#endif                                                             //~va20I~
    uviom_setopt2(opt,optch);                                      //~va1cR~
#endif                                                             //~va1cR~
	return 0;
}//scrinit
#ifdef LNX                                                         //~v79TI~
//**************************************************               //~v79TI~
//*set kon flag                                                    //~v79TI~
//*rc   : 0                                                        //~v79TI~
//**************************************************               //~v79TI~
int scrsetunxflag(int Popt)                                        //~v79TI~
{                                                                  //~v79TI~
#ifndef XXE                                                        //~v79TI~
	int termid;                                                    //~v79TI~
#endif //!XXE                                                      //~v79TI~
//*********************                                            //~v79TI~
  #ifdef XXE                                                       //~v79TI~
    Gunxflag |= GUNX_KON;		//always dbcs avail                //~v79TI~
  #else                                                            //~v79TI~
    if (uviol_konchk()) 					//may be con           //~v79TI~
    {                                                              //~v79TI~
    	Gunxflag |= GUNX_KON;                                      //~v79TI~
//      gblkon(KON_TABDISP);    //rest tab disp char               //~v79TI~
//      gblkon(KON_UNPCHAR);    //rest unprintable char            //~v79TI~
    	Gunxflag |= GUNX_KONTERM;   //KON by uviol_konchk          //~v79TI~
    }                                                              //~v79TI~
    else                                                           //~v79TI~
    {                                                              //~v79TI~
        termid=ukbdl_gettermid();                                  //~v79TI~
  	    if (termid & TERM_SIMID) 	//term sim                     //~v79TI~
			Gunxflag|=GUNX_UNDERX;                                 //~v79TI~
  	    if ((termid & TERM_SIMID)==TERM_XTERMSIM)	//under xterm sim//~v79TI~
        {                                                          //~v79TI~
//          gblkon(KON_TABDISP);    //rest tab disp char           //~v79TI~
//          gblkon(KON_UNPCHAR);    //rest unprintable char        //~v79TI~
  		  	Gunxflag |= GUNX_XTERM;    //DBCS not avail on emulater xterm//~v79TI~
        }                                                          //~v79TI~
        else                                                       //~v79TI~
        if ((termid & TERM_SIMID)) 	//other sim under X            //~v79TI~
  			Gunxflag |= GUNX_KON;                                  //~v79TI~
        else                                                       //~v79TI~
  	    if (termid & TERM_UNDERKON) 	//under kon                //~v79TI~
  			Gunxflag |= GUNX_KON;                                  //~v79TI~
        else                                                       //~v79TI~
  		  	Gunxflag |= GUNX_FENG;    //force english              //~v79TI~
    }                                                              //~v79TI~
  #endif //!XXE                                                    //~v79TI~
  	return 0;                                                      //~v79TI~
}//scrsetunxflag                                                   //~v79TI~
#endif   //LNX                                                     //~v79TI~

//**********************************************                   //~v075I~
//*scrsetpallette                                                  //~v075I~
//* collor attribute tbl set                                       //~v075I~
//* parm1 :output attr tbl                                         //~v075I~
//* parm2 :pallette no assign tbl                                  //~v085R~
//* return:rc                                                      //~v075R~
//**********************************************                   //~v075I~
int scrsetpallette(UCHAR *Ppallette)                               //~v075I~
{                                                                  //~v075I~
	int ii;                                                        //~v075I~
	UINT rc;                                                       //~v075I~
//*********************                                            //~v075I~
	if (UCBITCHK(Gscrstatus,GSCRSEXTSG))                           //~v075R~
    {                                                              //~v075I~
#ifdef UNX                                                         //~v19zI~
  #ifndef XXE                                                      //~v64aI~
		if (Gkbdopt & UKBDL_MONO)                                  //~v19zI~
  #endif //!XXE                                                    //~v64aI~
    		uerrmsg("Pallette RGB change is not avail under mono-color mode.",//~v19zI~
       				 "モノカラーモードではパレットRGB値を変更できません");//~v19zI~
  #ifndef XXE                                                      //~v64aI~
        else                                                       //~v19zI~
    		uerrmsg("Pallette RGB change is not avail on this TERM=%s.",//~v19zR~
       				 "この端末(TERM=%s)ではパレットRGB値を変更できません",//~v19zR~
					getenv("TERM"));                               //~v19zR~
  #endif //!XXE                                                    //~v64aI~
#else                                                              //~v19zI~
#ifdef W32                                                         //~v085I~
//  	uerrmsg("Pallette RGB value change is not avail for W95 version.",//~v0jcR~
//     			 "W95 バージョンではパレットRGB値を変更できません");//~v0jcR~
//  	uerrmsg("Pallette RGB value change is not avail for WIN version.",//~va3AR~
//     			 "WIN バージョンではパレットRGB値を変更できません");//~va3AR~
    	uerrmsg("Pallette RGB value change is not avail for W32 console version.",//~va3AI~
       			 "W32 コンソールバージョンではパレットRGB値を変更できません");//~va3AI~
#else                                                              //~v085I~
    	uerrmsg("Pallette RGB value change is not effective when OS/2 window mode.",//~v085R~
       			 "OS/2 ウィンドウモードではパレットRGB値の変更は無効です");//~v085R~
#endif                                                             //~v085I~
#endif                                                             //~v19zI~
	  	return 4;                                                  //~v075R~
	}                                                              //~v075I~
//  for (ii=0;ii<16;ii++)                                          //~v19pR~
    for (ii=0;ii<MAX_COLOR;ii++)                                   //~v19pI~
		if (Ppallette[ii]!=0xff)	//change required              //~v075I~
			Spalreq.palstate.acolor[ii]=(USHORT)Ppallette[ii];     //~v075R~
        else                                                       //~v075I~
			if (Gpallette[ii]!=0xff)  //not first time             //~v075R~
				Spalreq.palstate.acolor[ii]=(USHORT)Gpallette[ii]; //~v075I~
//UTRACED("setpallette Spalreq",&Spalreq,sizeof(Spalreq));         //~v079R~
    if (rc=uviosetstate(&Spalreq),rc)	//set pallette status      //~v075I~
    {                                                              //~v075I~
    	uerrmsg("vio init(VioSetState-set color reg) failed,rc=%d",//~v075I~
       			 "VIO 初期化(VioSetState-カラー設定)失敗,rc=%d",rc);//~v075I~
		return 4;                                                  //~v075I~
	}                                                              //~v075I~
//save to gbl                                                      //~v075I~
//  for (ii=0;ii<16;ii++)                                          //~v19pR~
    for (ii=0;ii<MAX_COLOR;ii++)                                   //~v19pI~
		Gpallette[ii]=(char)Spalreq.palstate.acolor[ii];           //~v075R~
//UTRACED("Gpallette",Gpallette,16);                               //~v079R~
	return 0;                                                      //~v075I~
}//scrsetpallette                                                  //~v075I~
//**********************************************
//*scrsetattrtbl                                                   //~v075R~
//* collor attribute tbl set
//* parm1 :output attr tbl                                         //~v075R~
//* parm2 :pallete no assign tbl                                   //~v075I~
//* return:none
//**********************************************
void scrsetattrtbl(UCHAR *Pattrtbl,UCHAR *Ppnotbl)                 //~v075R~
{
	int i,j;
//*********************
    Pattrtbl[COLOR_FRAME]	=                                      //~v075R~
		(UCHAR)((*(Ppnotbl+PAL_FRAMEBG)<<4)+*(Ppnotbl+PAL_FRAMEFG));
    Pattrtbl[COLOR_BCLIENT]	=                                      //~v075R~
		(UCHAR)((*(Ppnotbl+PAL_BCLIENTBG)<<4)+*(Ppnotbl+PAL_BCLIENTFG));//~5430R~
    Pattrtbl[COLOR_BLINENO]	=                                      //~v075R~
		(UCHAR)((*(Ppnotbl+PAL_BLINENOBG)<<4)+*(Ppnotbl+PAL_BLINENOFG));//~5430R~
    Pattrtbl[COLOR_ECLIENT]	=                                      //~v075R~
		(UCHAR)((*(Ppnotbl+PAL_ECLIENTBG)<<4)+*(Ppnotbl+PAL_ECLIENTFG));//~5430R~
    Pattrtbl[COLOR_ELINENO]	=                                      //~v075R~
		(UCHAR)((*(Ppnotbl+PAL_ELINENOBG)<<4)+*(Ppnotbl+PAL_ELINENOFG));//~5430R~
    Pattrtbl[COLOR_TITLE]	=                                      //~v075R~
		(UCHAR)((*(Ppnotbl+PAL_TITLEBG)<<4)+*(Ppnotbl+PAL_TITLEFG));
                                                                      //~v06vI~
    Pattrtbl[COLOR_DCLIENT]	=                                      //~v075R~
		(UCHAR)((*(Ppnotbl+PAL_DCLIENTBG)<<4)+*(Ppnotbl+PAL_DCLIENTFG));//~v06vI~
    Pattrtbl[COLOR_DLINCMD]	=                                      //~v075R~
		(UCHAR)((*(Ppnotbl+PAL_DLINCMDBG)<<4)+*(Ppnotbl+PAL_DLINCMDFG));//~v06vI~
    Pattrtbl[COLOR_DLINENO]	=                                      //~v075R~
		(UCHAR)((*(Ppnotbl+PAL_DLINENOBG)<<4)+*(Ppnotbl+PAL_DLINENOFG));//~v06vI~
    Pattrtbl[COLOR_CCLIENT]	=                                      //~v075R~
		(UCHAR)((*(Ppnotbl+PAL_CCLIENTBG)<<4)+*(Ppnotbl+PAL_CCLIENTFG));//~v06vI~
//UTRACEI("xescr    COLOR_CLIENT_R",COLOR_CCLIENT);                //~v06vR~
//UTRACED("xescr    Pattrtbl       ",Pattrtbl+COLOR_CCLIENT,1);    //~v075R~
    Pattrtbl[COLOR_CLINENO]	=                                      //~v075R~
		(UCHAR)((*(Ppnotbl+PAL_CLINENOBG)<<4)+*(Ppnotbl+PAL_CLINENOFG));//~v06vI~
//*reverse color(swap bg and fg color)
	for (i=0;i<COLOR_COUNT;i++)
	{
		j=Pattrtbl[i];                                             //~v075R~
//UTRACEI("xescr    j",j);                                         //~v06vR~
#ifdef UNX                                                         //~v40bI~
    	if (Gmaxcolor==2) //mono color                             //~v308I~
			Pattrtbl[COLOR_COUNT+i]=(UCHAR)((j & 0x0f)+HIGHLIGHT_BG);//~v308R~
				//keep fg highlight and set bg hilight(alternative of reverse)//~v308I~
        else                                                       //~v308I~
#endif //!UNX                                                      //~v40bI~
//		Pattrtbl[COLOR_COUNT+i]=(UCHAR)(((UINT)j>>4)+(j<<4));//no brink//~v45hR~//~vb2zR~
  		Pattrtbl[COLOR_COUNT+i]=(UCHAR)(((UINT)j>>4)+(UINT)(j<<4));//no brink//~vb2zI~
	}
//UTRACED("xescr    Pattrtbl       ",Pattrtbl,24);                 //~v075R~
	return;
}//setattrtbl
                                                                   //~v40bI~
#ifdef UNX                                                         //~v40bI~
  #ifndef XXE                                                      //~v64aI~
//**********************************************                   //~v19zI~
//*scrsetmonopall                                                  //~v19zI~
//* setup pallet for mono color                                    //~v19zI~
//* return:none                                                    //~v19zI~
//**********************************************                   //~v19zI~
UCHAR *scrsetmonopall(void)                                        //~v19zI~
{                                                                  //~v19zI~
//*screen color pallette asign                                     //~v19zI~
	Smonopalltbl[PAL_TITLEFG  ]= HIGHLIGHT_FG;	//title fg,highlight flag only//~v308R~
//  Smonopalltbl[PAL_TITLEBG  ]= PALNO_RGB;	//title bg             //~v20ZR~
    Smonopalltbl[PAL_TITLEBG  ]= PALNO_BLACK;	//title bg         //~v20ZI~
	Smonopalltbl[PAL_FRAMEFG  ]= PALNO_BLACK;//frame fg            //~v308R~
	Smonopalltbl[PAL_FRAMEBG  ]= PALNO_BLACK;	//frame bg         //~v19zI~
	Smonopalltbl[PAL_BLINENOFG]= PALNO_BLACK;	//browse lineno fg //~v308R~
	Smonopalltbl[PAL_BLINENOBG]= PALNO_BLACK;	//browse lineno bg //~v19zI~
	Smonopalltbl[PAL_BCLIENTFG]= PALNO_BLACK;	//browse client fg //~v308R~
	Smonopalltbl[PAL_BCLIENTBG]= PALNO_BLACK;	//browse client bg //~v19zI~
	Smonopalltbl[PAL_ELINENOFG]= PALNO_BLACK;	//edit   lineno fg //~v308R~
	Smonopalltbl[PAL_ELINENOBG]= PALNO_BLACK;	//edit   lineno bg //~v19zI~
    Smonopalltbl[PAL_ECLIENTFG]= PALNO_BLACK;	//edit   client fg (high yellow)//~v308R~
	Smonopalltbl[PAL_ECLIENTBG]= PALNO_BLACK;	//edit   client bg //~v19zI~
#ifdef LNX                                                         //~v309I~
	Smonopalltbl[PAL_DLINCMDFG]= HIGHLIGHT_FG;//dirlist linecmd fg    //~v308R~
#else                                                              //~v309I~
	Smonopalltbl[PAL_DLINCMDFG]= PALNO_BLACK;//dirlist linecmd fg=mono color//~v309I~
#endif                                                             //~v309I~
	Smonopalltbl[PAL_DLINCMDBG]= PALNO_BLACK;	//dirlist linecmd bg3//~v19zI~
	Smonopalltbl[PAL_DLINENOFG]= PALNO_BLACK;	//dirlist lineno fg//~v308R~
	Smonopalltbl[PAL_DLINENOBG]= PALNO_BLACK;	//dirlist lineno bg//~v19zI~
	Smonopalltbl[PAL_DCLIENTFG]= PALNO_BLACK;	//dirlist client fg//~v308R~
	Smonopalltbl[PAL_DCLIENTBG]= PALNO_BLACK;	//dirlist client bg//~v19zI~
	Smonopalltbl[PAL_CLINENOFG]= PALNO_BLACK;	//cmd result lineno fg//~v308R~
	Smonopalltbl[PAL_CLINENOBG]= PALNO_BLACK;	//cmd result lineno bg//~v19zI~
    Smonopalltbl[PAL_CCLIENTFG]= PALNO_BLACK;  //cmd result client fg (high white)//~v308R~
	Smonopalltbl[PAL_CCLIENTBG]= PALNO_BLACK; //cmd result client bg//~v19zR~
    return Smonopalltbl;                                           //~v19zR~
}//scrsetmonopall                                                  //~v19zI~
  #endif //!XXE                                                    //~v64aI~
#endif //!UNX                                                      //~v40bI~
                                                                   //~v40bI~
//****************************************************************
// scrterm 
//*recover screen status at start and free malloc area          //~4C23R~
//*return :0
//****************************************************************
int scrterm(void)
{
//static int Stermsw=0;                                            //~vb4uR~
//static	VIOINTENSITY intensbrink={6,2,0};	//brink            //~v095R~
//*********************************
	if (Stermsw)
		return 0;
	Stermsw=1;
	scrreset();			//restore screen status                 //~4C23R~
	csrterm();
	ufree16(Spsdcelldata);	//cell/data for psd
	ufree(Spsddbcstbl);		//dbcs tbl for psd
	ufree(Spuscrd);			//psd
	ufree(Gscrdbcstbl);
#ifdef W32                                                         //~v08eR~
//  usetconsolemode(1,Sw95consolemode_stdo);//recover consolemode at entry//~v0i3R~
	ufree(Sw95attrtbl);                                            //~v08eR~
#endif                                                             //~v08eR~
#ifdef UNX                                                         //~v45eI~
  #ifndef XXE                                                      //~v64aI~
    if (Sunxattrcleartbl)                                          //~v45eI~
		ufree(Sunxattrcleartbl);                                   //~v45eI~
    if (Sunxdbcscleartbl)                                          //~v47SI~
		ufree(Sunxdbcscleartbl);                                   //~v47SI~
    if (Spuclsvt)                                                  //~v45fR~
		ufree(Spuclsvt);                                           //~v45fR~
  #endif //!XXE                                                    //~v64aI~
#endif                                                             //~v45eI~
    if (Smultilineerrmsgtop)    //not multi                        //~v603I~
        ufree(Smultilineerrmsgtop);                                //~v603I~
	return 0;
}//scrterm
                                                                   //~v08eR~
#ifdef W32                                                         //~v08eR~
//**************************************************************** //~v08eR~
//*scrw95getattrtbl                                                //~v08eR~
//*get initialized attr table                                      //~v08eR~
//*parm1  :attr value                                              //~v08eR~
//*return :attr table addr                                         //~v08eR~
//**************************************************************** //~v08eR~
USHORT *scrw95getattrtbl(USHORT Pattr)                             //~v08eR~
{                                                                  //~v08eR~
    int ii;                                                        //~v08eI~
//*********************************                                //~v08eR~
	if (*Sw95attrtbl!=Pattr)                                       //~v08eR~
    {                                                              //~v08eI~
#ifdef WXE                                                         //~v500I~
    	for (ii=0;ii<Gscrbuffwidth;ii++)                           //~v500I~
#else                                                              //~v500I~
    	for (ii=0;ii<Gscrwidth;ii++)                               //~v08eR~
#endif                                                             //~v500I~
        	Sw95attrtbl[ii]=Pattr;                                 //~v08eR~
    }                                                              //~v08eI~
	return Sw95attrtbl;                                            //~v08eR~
}//scrw95getattrtbl(void)                                          //~v08eR~
#endif                                                             //~v08eR~

//****************************************************************//~4C23I~
// scrreset                                                     //~4C23I~
//*recover screen status at start                               //~4C23I~
//*return :0                                                    //~4C23I~
//****************************************************************//~4C23I~
int scrreset(void)                                              //~4C23R~
{                                                               //~4C23I~
static int Sresetsw=0;                                             //~v45hR~
static	VIOINTENSITY intensbrink={6,2,0};	//brink             //~4C23I~
//*********************************                             //~4C23I~
	if (Sresetsw)                                               //~4C23R~
		return 0;                                               //~4C23I~
	Sresetsw=1;                                                 //~4C23R~
  if (Soldattrc)                                                   //~v0hhR~
  {                                                                //~v0hhI~
	Smodeinfo.attrib=Soldattrc;                                    //~v0hhI~
	uviosetmode(&Smodeinfo);                                    //~4C23I~
  }	                                                               //~v0hhI~
//UTRACED("setmode",&Smodeinfo,sizeof(Smodeinfo));                 //~v0hhR~
	if (UCBITCHK(Gscrstatus,GSCRSEXTSG))//error,bypass reset    //~4C23I~
		scrcls(" \x07");	//space,whilte on black             //~v061R~
    else                                                        //~5222I~
	{                                                           //~4C23I~
#ifdef DOS                                                      //~v016I~
    	scrcls(" \x07");	//space,whilte on black                //~v0hhR~
#else                                                           //~v016I~
    #ifdef WXE                                                     //~vb4uI~
      if (!Stermsw)                                                //~vb4uI~
    #endif                                                         //~vb4uI~
		scrcls(" \x07");	//space,whilte on black             //~v061I~
#endif                                                          //~v016I~
		uviosetstate(&intensbrink);                             //~4C23I~
	    uviosetstate(&Spalsave);	//restore pallette status   //~4C23I~
	}                                                           //~4C23I~
#ifdef W32                                                         //~v0i3I~
  #ifndef WXE                                                      //~v500R~
    if (Sw95consolemode_chng)     //should be restore at reset/term//~v0i3I~
	    usetconsolemode(1,Sw95consolemode_stdo);//recover consolemode at entry//~v0i3I~
  #endif //!WXE                                                    //~v500R~
#endif                                                             //~v0i3I~
	uviosetmode(0);	//0 mean ufree vio work                     //~v04eI~
	return 0;                                                   //~4C23R~
}//scrreset                                                     //~4C23I~
                                                                //~4C23I~
//****************************************************************//~v061I~
// scrcls                                                       //~v061I~
//*clear screen                                                 //~v061I~
//*parm1 :cell(char and attr)                                   //~v061I~
//*return :0                                                    //~v061I~
//****************************************************************//~v061I~
int scrcls(char *Ppcell)                                        //~v061I~
{                                                               //~v061I~
#ifdef W32                                                         //~v085R~
	int rc;                                                        //~v085R~
    int lineopt=0;                                                 //~vb4uI~
#else                                                              //~v085I~
	int rc;                                                        //~v0hiI~
#endif                                                             //~v085I~
//*********************************                             //~v061I~
#ifdef UNX                                                         //~v19fI~
  #ifdef XXE                                                       //~v64aI~
  	rc=0;                                                          //~v64aI~
  #else                                                            //~v64aI~
    rc=uviol_clear();                                              //~v19fI~
  #endif                                                           //~v64aI~
    return rc;                                                     //~v19fI~
#else    //!UNX                                                    //~v19fI~
#ifdef W32                                                         //~v085I~
	if (Stermsw)                                                   //~vb4uI~
    	lineopt|=UVIOO_NOSAVE;                                     //~vb4uI~
  #ifdef WXE                                                       //~v500I~
//  rc =(int)uviowrtncell(Ppcell,Gscrbuffheight*Gscrbuffwidth,0,0);//len,row,col//~vb4uR~
    rc =(int)uviowrtncell(lineopt,Ppcell,Gscrbuffheight*Gscrbuffwidth,0,0);//len,row,col//~vb4uR~
  #else                                                            //~v500I~
//  rc =(int)uviowrtncell(Ppcell,Gscrheight*Gscrwidth,0,0);//len,row,col//~vb4uR~
    rc =(int)uviowrtncell(lineopt,Ppcell,Gscrheight*Gscrwidth,0,0);//len,row,col//~vb4uR~
  #endif                                                           //~v500I~
	rc+=(int)uviosetcurpos(0,0);		//row,col                  //~v085I~
    return rc;                                                     //~v085I~
#else                                                              //~v085I~
	rc=(int)uvioscrollup(0,0,Gscrheight-1,Gscrwidth-1,Gscrheight,  //~v0hiR~
                             Ppcell);//clear char and attr      //~v061R~
    rc+=(int)uviosetcurpos(0,0);		//row,col                  //~v452R~
    return rc;                                                     //~v0hiI~
#endif                                                             //~v085I~
#endif //!UNX                                                      //~v19fI~
}//scrcls                                                       //~v061I~
                                                                //~v061I~
//****************************************************************
// scrdisp
//*display screen line
//*rc   :0
//****************************************************************
int scrdisp(void)
{
#ifdef DOS                                                      //~v017I~
    #ifdef DPMI					//DPMI version                     //~v095I~
        static UCHAR *Srep=" rep";                                 //~v095I~
        static UCHAR *Sins=" ins";                                 //~v095I~
    #else                       //not DPMI                         //~v095I~
static UCHAR *Srep=" REP";                                      //~v017R~
static UCHAR *Sins=" INS";                                      //~v017R~
    #endif                      //DPMI or not                      //~v095I~
#else                                                           //~v017I~
static UCHAR *Srep=" Rep";                                      //~v017R~
static UCHAR *Sins=" Ins";                                      //~v017R~
#endif                                                          //~v017I~
                                                                //~v017I~
static int Serrwritesw=0;
	UINT uirc=0;                                                   //~v19fR~
	UCHAR *pc,*data,*errmsg=0;
	UCHAR *pdbcs;                                                  //~v0h6I~
#ifdef W32                                                         //~v089I~
    int buffuse;                                                   //~v089I~
    int blockstart,blockend;                                       //~v08iI~
    WORD *paw;		//attr word ptr                                //~v08cI~
#endif                                                             //~v089I~
	int fulldrawsw,inactdrawsw=0;                                  //~v0h7R~
//#ifdef AIX                                                       //~v40QR~
//#endif                                                           //~v40QR~
//#define MAXVLINE    50                                           //~v0h9R~
//    char drawvlinesw[MAXVLINE];                                  //~v0h9R~
#ifdef UTF8SUPPH                                                   //~va1cR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va3AI~//~va50R~
//  char errmsgdbcst[MAXCOLUMN*2*MAX_MBCSLEN];//expand by dbcssplit space insertion//~va3AI~//~va50R~//~vb7oR~
    char errmsgdbcst[MAXCOLUMN*2*MAX_MBCSLEN+2];//same as errmsglc //~vb7oI~
#else                                                              //~va3AI~//~va50R~
    char errmsgdbcst[MAXCOLUMN+2*MAX_MBCSLENLC];//expand by dbcssplit space insertion//~va1cR~
#endif //UTF8EBCD raw ebcdic file support                          //~va3AI~//~va50R~
    int dbcssplitctr;                                              //~va1cR~
#else                                                              //~va1cR~
    char errmsgdbcst[MAXCOLUMN+2];                                 //~v43nI~
#endif                                                             //~va1cR~
#ifdef UTF8SUPPH                                                   //~va00I~
//  char errmsglc[MAXCOLUMN*2+2];                                 //~v43nI~//~va1cR~
//  char errmsgcodetype[MAXCOLUMN*2+2];                                 //~v43nI~//~va1cR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50R~//~va3AI~//~va50R~
    char errmsglc[MAXCOLUMN*2*MAX_MBCSLEN+2];                      //~va3AI~//~va50R~
    char errmsgcodetype[MAXCOLUMN*2*MAX_MBCSLEN+2];                //~va3AI~//~va50R~
#else                                                              //~va3AI~//~va50R~
    char errmsglc[MAXCOLUMN*2*UTF8_F2LMAXRATE+2];                  //~va1cR~
    char errmsgcodetype[MAXCOLUMN*2*UTF8_F2LMAXRATE+2];            //~va1cR~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~//~va3AI~//~va50R~
    int  errmsgutf8sw=0,errmsglenlc;                               //~va00I~
    char *pattr;                                                   //~va00I~
    int opt;                                                       //~va10I~
#endif                                                             //~va00I~
	int i,j,rowend,colstart,x=0,y,len,attrlen,active,cell0len;     //~vaf9R~
	PUSCRD psd;
	PUCLIENTWE pcw,pcw1,pcw2;
	PUCLIENTWE pcwoldact;                                          //~v09nI~
    int ucwwidth=0,usdlen;                                         //~vaf9R~
    int vsplitsw,inactvsplit1stsw=0;                               //~v0h8R~
    int vsplitline;                                                //~v0h9I~
    int errmsglen,errmsglen1=0;                                      //~v43nR~//~vafdR~
    int orgx=0,orgy=0;                                                 //~v45cR~//~vafdR~
    int len2;                                                      //~v45hI~
    int insmodesw=0,inswordpos;                                    //~v51TI~
    int inswordlen;                                                //~v51VI~
#ifdef UNX                                                         //~v45eI~
  #ifndef XXE                                                      //~v64aI~
    int    doclearoksw=0;                                          //~v45fR~
    int    dbcssw,dbcsclearmode,dbcscleardone;                     //~v45kR~
    int    cleardbcssw,cleardbcsswerr1,cleardbcsswerr2;            //~v45hR~
    int    uclsvtsw[2];                                            //~v45fR~
    int    uclsvtstartline[2];                                     //~v45gI~
    UCLSVT *puclsvt=NULL;                                               //~v45fR~//~vafdR~
static int S1stclear=1;                                            //~v45BR~
  #endif //!XXE                                                    //~v64aI~
#endif                                                             //~v45eI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	int rc2;                                                       //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
#ifdef W32                                                         //~vb37I~
//#ifndef WXE                                                      //~vb3hR~
//    int swdir=0;                                                 //~vb3hR~
//#endif                                                           //~vb3hR~
#endif                                                             //~vb37I~
	int lineopt,linesplitopt=0,lineopt_insrep,lineopt_errmsg;      //~vb4fR~
//****************************
//determine current active client
	pcwoldact=			//before active change                     //~v09nI~
	pcw1=scrgetcw(0);	//active client
	pcw2=scrgetcw(-1);	//inactive client
	vsplitsw=(UCBITCHK(Gscrstatus,GSCRSSPLITV)!=0);	//1 if vsplit  //~v0h8I~
	if ((UCBITCHK(Gscrstatus,GSCRSSPLITH) && Gcsrposy >= Gscrsplith)//~v0h6R~
	||  (UCBITCHK(Gscrstatus,GSCRSSPLITV) && Gcsrposx >= Gscrsplitv))//~v0h6R~
			active=1;							//second client     //~5123I~
	else
		active=0;							//first client
	if (Gscrcurclient!=active)			//active changed
	{
		UCBITON(pcw1->UCWflag,UCWFDRAW);
		UCBITON(pcw2->UCWflag,UCWFDRAW);
		Gscrcurclient=active;			//curr client
		pcw=pcw1;
		pcw1=pcw2;
		pcw2=pcw;		//swap active
	}
//    #ifdef WXE                                                   //~v500R~
//        if (active) //2nd is active                              //~v500R~
//            wxe_scrsetsplit(vsplitsw,pcw2,pcw1);                 //~v500R~
//        else        //1st is active                              //~v500R~
//            wxe_scrsetsplit(vsplitsw,pcw1,pcw2);                 //~v500R~
//    #endif                                                       //~v500R~
#ifdef W32                                                         //~v089I~
//  if (UCBITCHK(Gscrstatus,GSCRSSPLITV)) //vsplit                 //~v0h9R~
//    if (UCBITCHK(pcw1->UCWflag,UCWFDRAW))                        //~v0h9R~
//    {                                                            //~v0h9R~
//        UCBITON(pcw2->UCWflag,UCWFDRAW);    //for draw performance//~v0h9R~
//        buffuse=1;                  //both full draw by buff     //~v0h9R~
//    }                                                            //~v0h9R~
//    else                                                         //~v0h9R~
//        if (UCBITCHK(pcw2->UCWflag,UCWFDRAW))   //full draw one of them//~v0h9R~
//        {                                                        //~v0h9R~
//            UCBITON(pcw1->UCWflag,UCWFDRAW);    //both full draw   //~v089I~//~v0h9R~
//            buffuse=1;                  //both full draw by buff //~v0h9R~
//        }                                                        //~v0h9R~
//        else                                                     //~v0h9R~
//            buffuse=0;                                           //~v0h9R~
//  else      //not vsplit                                         //~v0h9R~
//    if (UCBITCHK(Gscrstatus,GSCRSSPLITH)) //split                //~v0h9R~
  #ifdef WXE                                                       //~v500R~
    buffuse=1;	    	//xe always write to buff,wxe write from buff//~v500R~
  #else                                                            //~v500R~
    if (pcw2)             //split                                  //~v0h9I~
    {                                                              //~vb37I~
   		if (UCBITCHK(pcw1->UCWflag,UCWFDRAW)                       //~v08iI~
		&&  UCBITCHK(pcw2->UCWflag,UCWFDRAW)) 	//full draw one of them//~v08iI~
        {                                                          //~vb37I~
            buffuse=1;			//if full draw,use blockstart/blockend//~v08iI~
        }                                                          //~vb37I~
        else                                                       //~v08iI~
            buffuse=0;			//if full draw,use blockstart/blockend//~v08iR~
//#ifdef W32                                                       //~vb3hR~
//        if (pcw1->UCWtype==UCWTDIR                               //~vb3hR~
//        ||  pcw2->UCWtype==UCWTDIR)                              //~vb3hR~
//        {                                                        //~vb3hR~
//            buffuse=0;          //ligature on for no ascii,ignore cursor pos//~vb3hR~
//            swdir=1;                                             //~vb3hR~
//        }                                                        //~vb3hR~
//#endif                                                           //~vb3hR~
    }                                                              //~vb37I~
    else                                                           //~v08iI~
    {                                                              //~vb37I~
//#ifdef W32                                                       //~vb3hR~
//      if (pcw1->UCWtype==UCWTDIR)//dirlist                       //~vb3hR~
//      {                                                          //~vb3hR~
//         buffuse=0;         //ligature on for no ascii,ignore cursor pos//~vb3hR~
//         swdir=1;                                                //~vb3hR~
//      }                                                          //~vb3hR~
//      else                                                       //~vb3hR~
//#endif                                                           //~vb3hR~
       	buffuse=UCBITCHK(pcw1->UCWflag,UCWFDRAW);                  //~v08iR~
    }                                                              //~vb37I~
  #endif //!WXE                                                    //~v500R~
	uvio_w95buffmode(buffuse);	//set/reset buffer mode            //~v089M~
#endif                                                             //~v089I~
//create line
#ifdef WXEXXE                                                      //~vbdnR~
	scrSetUpdateFileMenu(0,pcw1);                                  //~vbdnI~
#endif                                                             //~vbdnI~
 	pc=Gattrtbl+COLOR_TITLE;
	for (i=0,pcw=pcw1;i<2;i++,pcw=pcw2)
	{
		if (!pcw)
			continue;
		funccall(UCWKTSCRDRAW,0,pcw);		//type 3(func_draw_xxxx)//~5225R~
		pcw->UCWpsd->USDnattr=*pc;
		pc=Gattrtbl+COLOR_FRAME;
	}
//bypass screen write for performace,write at after next csr move event//~v0h6I~
	if (UCBITCHK(Gprocstatus,GPROCSCSRDOWN|GPROCSCSRRIGHT))        //~v0h6I~
	{					//char input followed simulated csr move event//~v0h6I~
    	pcw=pcw1;		//active screen                            //~v0h6I~
		psd=pcw->UCWpsd+pcw->UCWrcsry;	//char input line          //~v0h6I~
                                                                   //~v0h6I~
        ucwwidth=pcw->UCWwidth;                                    //~v0h6I~
        usdlen=psd->USDlen;                                        //~v0h6I~
        pdbcs=psd->USDdbcs;                                        //~v0h6I~
		data=psd->USDdata;                                         //~v0h6I~
        x=pcw->UCWorgx;	//start of active screen                   //~v0h6M~
        y=pcw->UCWorgy+pcw->UCWrcsry;	//char input line grobal pos//~v0h6M~
        switch(psd->USDflag)                                       //~v0h6I~
        {                                                          //~v0h6I~
        case USDFCELLSTR:                                          //~v0h6I~
            len=min(usdlen,ucwwidth*2);                            //~v0h6I~
            csrsetdbcstbl(x,y,psd->USDcell,pdbcs,len/2,1);         //~v0h6I~
            break;                                                 //~v0h6I~
#ifdef UTF8SUPPH                                                   //~va00I~
        case USDFCELLSTR3:                                         //~va00I~
#endif                                                             //~va00I~
#ifdef W32                                                         //~v0h6I~
        case USDFCELLSTR2:                                         //~v0h6I~
            len=min(usdlen,ucwwidth); //USDlen is ctr              //~v0h6I~
            csrsetdbcstbl(x,y,data,pdbcs,len,0);//char not cell    //~v0h6I~
            break;                                                 //~v0h6I~
#else                                                              //~va00I~
#endif                                                             //~va00I~
        case USDFCHARSTR:                                          //~v0h6I~
            len=min(usdlen,ucwwidth-psd->USDoff);                  //~v0h6I~
            if (len)                                               //~v0h6I~
                csrsetdbcstbl(x,y,data,pdbcs,len,0);               //~v0h6I~
            break;                                                 //~v0h6I~
        case USDFCHARSTRATT:                                       //~v0h6I~
            len=min(usdlen,ucwwidth);                              //~v0h6I~
            csrsetdbcstbl(x,y,data,pdbcs,len,0);                   //~v0h6I~
            break;                                                 //~v0h6I~
        case USDFNCELL:                                            //~v0h6I~
            len=min(usdlen,ucwwidth);                              //~v0h6I~
            csrcleardbcstbl(x,y,len);                              //~v0h6I~
            break;                                                 //~v0h6I~
        case USDFNCHAR:                                            //~v0h6I~
            len=min(usdlen,ucwwidth);                              //~v0h6I~
            csrcleardbcstbl(x,y,len);                              //~v0h6I~
            break;                                                 //~v0h6I~
        }                                                          //~v0h6I~
    	return 0;                                                  //~v0h6I~
    }                                                              //~v0h6I~
//set Ins/Rep to top line
	if (UCBITCHK(Gscrstatus,GSCRSSPLITV))
    {                                                              //~v090I~
//      memset(drawvlinesw,0,sizeof(drawvlinesw));  //crear vline redraw//~v0h9R~
		pcw=scrgetcw(2);	//2nd client
    }                                                              //~v090I~
	else
		pcw=scrgetcw(1);	//first client
	psd=pcw->UCWpsd;
    lineopt_insrep=psd->USDuvioo;                                  //~vb4fI~
    inswordpos=pcw->UCWwidth-PANCSRMODEPOS;                        //~v51VI~
    if (inswordpos>=INSWORDPOS_MIN)   //          8   //=FILENAMEPOS   8//~v51VI~
    {                                                              //~v51VI~
    	inswordlen=PANCSRMODEPOS;                                  //~v51VI~
		inswordpos+=pcw->UCWorgx;//org pos                         //~v51VI~
    }                                                              //~v51VI~
    else                                                           //~v51VI~
    	inswordlen=0;   //skip insmode display                     //~v51VR~
  if (inswordlen)                                                  //~v51VI~
  {                                                                //~v51VI~
	if (UCBITCHK(Gscrstatus,GSCRSINS))
    {	                                                           //~v51TI~
    	insmodesw=1;                                               //~v51TI~
//  	inswordpos=pcw->UCWwidth-PANCSRMODEPOS+pcw->UCWorgx;//org pos//~v51VR~
    	memcpy(psd->USDdata+pcw->UCWwidth-PANCSRMODEPOS,Sins,4);   //~v51VR~
    }                                                              //~v51TI~
	else
    	memcpy(psd->USDdata+pcw->UCWwidth-PANCSRMODEPOS,Srep,4);   //~v51VR~
	if (UCBITCHK(Gscrstatus,GSCRSCSRDOWN))	//csr stepdown mode //~5225I~
		*(psd->USDdata+pcw->UCWwidth-PANCSRMODEPOS)=Sstepdownid;//~5225I~
    else                                                        //~5225I~
		*(psd->USDdata+pcw->UCWwidth-PANCSRMODEPOS)=Ssteprightid;//~5225I~
	scrsetinsrepdbcs(pcw,psd);                                     //~v770R~
  }                                                                //~v51VI~
//  	lineopt_errmsg=UVIOO_LIGATURE2|UVIOO_FORCELIGATURE|UVIOO_FORCECOMBINE; //errmsg//~vb4fR~
    	lineopt_errmsg=UVIOO_LIGATURE2|UVIOO_ERRMSG;               //~vb4uR~
//*re-write hdr line before errmsg override to clear previous err msg
    if (!UCBITCHK(Gopt,GOPTPOPUPERRMSG))	//popup err msgsw
    {                                                              //~v603I~
      	if (Gscropt & GSCROPT_MULTILINENEXTREQ    //2nd line display req by esc key//~v603R~
      	&&  Gscropt & GSCROPT_MULTILINEPENDING)   //2nd line display req by esc key//~v603I~
			errmsg=Smultilineerrmsgnext;	//uerrmsg called       //~v603R~
      	else                                                       //~v603I~
//  	if (errmsg=ugeterrmsg(),errmsg)	//uerrmsg called           //~v603R~
    		errmsg=ugeterrmsg();	//uerrmsg called               //~v603I~
    	if (errmsg)		//uerrmsg called                           //~v603I~
        {                                                          //~v603I~
//  		UCBITON(((PUSCRD)pcw1->UCWpsd)->USDflag2,USDF2DRAW);//redraw//~v09nR~
    		UCBITON(((PUSCRD)pcwoldact->UCWpsd)->USDflag2,USDF2DRAW);//redraw//~v09nI~
            scrsavemultilineerrmsg(errmsg);                        //~v603R~
      	}//errmsg exist                                            //~v603I~
      	Gscropt &= ~GSCROPT_MULTILINENEXTREQ;    //req processed   //~v603I~
    }//popup                                                       //~v603I~
//dilsplay all line
#ifdef UNX                                                         //~v45fI~
  #ifndef XXE                                                      //~v64aI~
    #ifdef AIX                                                     //~v45fI~
        if (UCBITCHK(Gscrstatus,GSCRSDBCS))   //for lang=SJIS      //~v45hR~
    #else                                                          //~v45fI~
//      if (Gunxflag & GUNX_KON)                                   //~v79zR~
		if (XE_ISDBCSKON()) //CJK(J:EUC) and GUNX_KON              //~v79BR~
    #endif                                                         //~v45fI~
    		dbcssw=1;                                              //~v45fI~
        else                                                       //~v45fI~
        	dbcssw=0;                                              //~v45fI~
//    #ifdef AIX                                                   //~v478R~
//        if (dbcssw && (Gkbdopt & UKBDL_CLEAR))                   //~v478R~
//    #else                                                        //~v478R~
//        if (dbcssw && (Gkbdopt & UKBDL_CLEAR))                   //~v478R~
//    #endif                                                       //~v478R~
      if (dbcssw)                                                  //~v478I~
      {                                                            //~v51SI~
//      if (Gkbdopt & UKBDL_CLEAR)                                 //~v478I~//~vb2zR~
        if ((UINT)Gkbdopt & UKBDL_CLEAR)                           //~vb2zI~
        {                                                          //~v45fR~
            if (pcw1)                                              //~v45fR~
                doclearoksw=UCBITCHK(pcw1->UCWflag,UCWFDRAW);//do clearok//~v45fR~
            if (pcw2)                                              //~v45fR~
                doclearoksw+=UCBITCHK(pcw2->UCWflag,UCWFDRAW);     //~v45gR~
        }                                                          //~v45fR~
        else                                                       //~v478I~
        {                                                          //~v478I~
          	if (Gkbdopt & UKBDL_CLEAR1)  //clearok when not splitted//~v478I~
            	if (!pcw2 && pcw1)                                 //~v478R~
                	doclearoksw=UCBITCHK(pcw1->UCWflag,UCWFDRAW);//do clearok//~v478R~
        }                                                          //~v478I~
      }//dbcssw                                                    //~v51SI~
//      dbcsclearmode=(Sunxattrcleartbl && !doclearoksw); //dbcs mode and not clearok case//~v479R~
//*** UKBDL_CLEARDBCS is never on so Sunxattrcleartbl is 0 when UTF8UCS2 (see xemainl.c)//~va21I~
        dbcsclearmode=(Sunxattrcleartbl!=0); //always write twice for dbcs line//~v479R~
    dbcscleardone=0;                                               //~v45kM~
  #endif //!XXE                                                    //~v64aI~
#endif                                                             //~v45fI~
	for (j=0,pcw=pcw1;j<2;j++,pcw=pcw2)	//2 client
	{	
#ifdef UNX                                                         //~v45eI~
  #ifndef XXE                                                      //~v64aI~
        uclsvtsw[j]=0;                                             //~v45fR~
  #endif //!XXE                                                    //~v64aI~
#endif                                                             //~v45eI~
		if (!pcw)
			continue;
		linesplitopt=0;                                            //~vb4fI~
		if (UCBITCHK(Gscrstatus,GSCRSSPLITV))                      //~vb4fI~
        {                                                          //~vb4fI~
        	if (pcw->UCWorgx)                                      //~vb4fI~
		    	linesplitopt=UVIOO_VSPLIT2ND;                      //~vb4fR~
        }                                                          //~vb4fI~
		rowend=pcw->UCWheight;
		colstart=pcw->UCWorgx;
		psd=pcw->UCWpsd;
    	fulldrawsw=UCBITCHK(pcw->UCWflag,UCWFDRAW);                //~v089R~
//#ifdef AIX                                                       //~v40QR~
//      fulldrawsw2+=fulldrawsw;                                   //~v45fR~
//#endif                                                           //~v40QR~
#ifdef W32                                                         //~v08iI~
//      uviom_notify(UVIOMNO_CSRPOS,Gcsrposx,Gcsrposy);//notify before lineput for ligature break//~va3hR~
		blockstart=blockend=0;                                     //~v08iI~
//      if (!buffuse	//not full buff use                        //~v0h9R~
//  	&&  !UCBITCHK(Gscrstatus,GSCRSSPLITV))	//not vsplit       //~v0h9R~
        if (!buffuse)   //block for each screen                    //~v0h9I~
//#ifndef WXE                                                      //~vb3hR~
//        if (!swdir)                                              //~vb3hR~
//#endif                                                           //~vb3hR~
        {                         //search block                   //~v08iI~
        	if (fulldrawsw)                                        //~v08iI~
            {                                                      //~v08iI~
                if (rowend>1)			//multiple line            //~v08iI~
					blockend=rowend;	//start is 0               //~v08iR~
			}                                                      //~v08iI~
			else                                                   //~v08iI~
            {                                                      //~v08iI~
    			for (i=FILEHDRLINENO,psd+=FILEHDRLINENO;i<rowend;i++,psd++)//~v08iR~
                {                                                  //~v08iR~
    				if (UCBITCHK(psd->USDflag2,USDF2DRAW))         //~v08iR~
                    {                                              //~v08iR~
                    	if (!blockstart)	//1st time             //~v08iR~
                        	blockstart=i;	//girst draw line      //~v08iR~
    				}                                              //~v08iR~
                    else                                           //~v08iR~
                		if (blockstart)	//draw line found          //~v08iR~
                        {                                          //~v08iR~
                            if (i==(blockstart+1))//single line block//~v08iR~
                            	blockstart=0;	//reset and retry  //~v08iR~
                            else				//multiple line    //~v08iR~
                            	break;                             //~v08iR~
    					}                                          //~v08iR~
    			}//all line                                        //~v08iR~
    			psd=pcw->UCWpsd;                                   //~v08iR~
            	if (blockstart)	//draw line exist                  //~v08iR~
                	if (i>(blockstart+1))//multiple line block     //~v08iR~
                    {                                              //~v08iR~
                    	blockend=i;     //next of block            //~v08iR~
                        if (blockstart==FILEHDRLINENO)	//from 1st clientline//~v08iR~
            				if (UCBITCHK((psd+FILEHDRLINENO-1)->USDflag2,USDF2DRAW))//~v08iR~
                            {                                      //~v08iR~
                            	blockstart--;                      //~v08iR~
            					if (UCBITCHK((psd+FILEHDRLINENO-2)->USDflag2,USDF2DRAW))//~v08iR~
            	                	blockstart--;                  //~v08iR~
            				}                                      //~v08iR~
    				}                                              //~v08iR~
			}//not full draw                                       //~v08iI~
        }//not vsplit not buffuse                                  //~v08iR~
#endif                                                             //~v08iI~
#ifdef UTF8UCS2                                                    //~va3hI~
//	#if defined(W32) && !defined(WXE)   //WXE get it by pcw chk    //~vb37I~//~vb4dR~
  	#ifndef WXEXXE   //WXE get it by pcw chk                       //~vb4dI~
      if (pcw->UCWtype==UCWTDIR)                                   //~vb37I~
//      uviom_notify(UVIOMNO_CSRPOS,-1,pcw->UCWorgy+pcw->UCWfilehdrlineno);//notify to use WriteConsoleW full string until space(ignore cursor pos)//~vb37R~//~vb4eR~
//      uviom_notify(UVIOMNO_FORCELIGATURE,j,pcw->UCWorgy+pcw->UCWfilehdrlineno);//notify to use WriteConsoleW full string until space(ignore cursor pos)//~vb4fR~
        ;                                                          //~vb4fI~
//    else                                                         //~vb37I~//~vb4eR~
	#endif                                                         //~vb37I~
        uviom_notify(UVIOMNO_CSRPOS,Gcsrposx,Gcsrposy);//notify before lineput for ligature break//~va3hI~
	#if defined(W32) && !defined(WXE)   //WXE get it by pcw chk    //~va3kR~
        uviom_notify(UVIOMNO_SPLITPOS,Gscrsplitv,0/*2ndparm*/);//notify before lineput for ligature break//~va3kI~
	#endif                                                         //~va3kI~
#endif                                                             //~va3hI~
      	vsplitline=Gscrsplitv-(active==1);//vsplitline column      //~v0h9I~
	  	inactdrawsw=(j && vsplitsw);	//vsplit inactive area     //~v0h9I~
        inactvsplit1stsw=(inactdrawsw && active);	//1st screen is inactive to be draw//~v0h8R~
		for (i=0;i<rowend;i++,psd++)	
		{
#ifdef UNX                                                         //~v45fI~
  #ifndef XXE                                                      //~v64aI~
            if (Spuclsvt)                                          //~v45fI~
            {                                                      //~v45fI~
            	puclsvt=Spuclsvt+Gscrheight*j+i;                   //~v45fR~
            	puclsvt->UCLSVTpsd=0;                 //save for later write//~v45fR~
            }                                                      //~v45fI~
  #endif //!XXE                                                    //~v64aI~
#endif                                                             //~v45fI~
			if (!fulldrawsw
			&&  !UCBITCHK(psd->USDflag2,USDF2DRAW))
				continue;
//            if (j)                                               //~v0h9R~
//            {                                                    //~v0h9R~
//                inactdrawsw=1;                                   //~v0h9R~
//                if (i<MAXVLINE)                                  //~v0h9R~
//                    drawvlinesw[i]=1;   //need vline redraw      //~v0h9R~
//            }                                                    //~v0h9R~
			if (Serrwritesw)	//once err write
				if (!i)
				{
					scrconfirmreset();//clear confirm when msg cleared//~v04eR~
					if (UCBITCHK(Gscrstatus,GSCRSSPLITV))
					{
//#ifdef WXE                                                       //~v64aR~
#ifdef WXEXXE                                                      //~v64aI~
						UCBITON((Spuscrd+Gscrbuffheight)->USDflag2,USDF2DRAW);//2nd pcw hdr psd//~v500I~
#else                                                              //~v500I~
						UCBITON((Spuscrd+Gscrheight)->USDflag2,USDF2DRAW);
#endif                                                             //~v500I~
						Serrwritesw=0;	//clear also second hdr
					}
				}

			UCBITOFF(psd->USDflag2,USDF2DRAW);
			x=pcw->UCWorgx;
			y=pcw->UCWorgy+i;
			data=psd->USDdata;
            ucwwidth=pcw->UCWwidth;                                //~v0h6I~
            usdlen=psd->USDlen;                                    //~v0h6I~
            pdbcs=psd->USDdbcs;                                    //~v0h6I~
            lineopt=linesplitopt | psd->USDuvioo;	//split and ligature option line by line//~vb4fM~
#ifdef W32                                                         //~v08iI~
            if (blockend                                           //~v08iI~
			&&  i>=blockstart && i<blockend)                       //~v08iR~
				uvio_w95buffmode(1);	//buff use for block       //~v08iI~
#ifndef WXE                                                        //~vb2YI~
//          if (UCBITCHK(psd->USDflag3,USDF3NOLIGATURE))           //~vb4fR~
//              uviom_notify(UVIOMNO_NOLIGATURE,1/*register*/,y);  //~vb4fR~
            if (i<=CMDLINENO)                                      //~vb39I~
            {                                                      //~vb48I~
    	      if (i==CMDLINENO)                                    //~vb48I~
//              uviom_notify(UVIOMNO_NOLIGATURE_CMDLINE,1/*register*/,y);//~vb4fR~
            	lineopt|=(UVIOO_CMDLINE|UVIOO_LIGATURE2);	//cmdline, split and ligature option line by line//~vb4fR~
              else                                                 //~vb48I~
//              uviom_notify(UVIOMNO_NOLIGATURE,1/*register*/,y);  //~vb4fR~
            	;	//FORCELIGATURE|COMBINE for file panel hdr     //~vb4fR~
            }                                                      //~vb48I~
#endif                                                             //~vb2YI~
#endif                                                             //~v08iI~
			if (!y)		//not relative top but org top hdrline write//~v51TI~
            	if (insmodesw)                                     //~v51TI~
                	insmodesw=2;		//hdr of "INS" is written  //~v51TI~
//partial attr write with NCHAR/CHARSTR
			switch(psd->USDflag)
			{
#ifdef UTF8SUPPH                                                   //~va00R~
			case USDFCELLSTR3:                                     //~va00R~
				len=min(usdlen,ucwwidth);	//USDlen is ctr        //~va00I~
				pattr=psd->USDcell;                                //~va00R~
                UTRACED("scrdisp STR3 data",data,len);             //~vafkI~
                UTRACED("scrdisp STR3 attr cell",pattr,len*2);       //~vafkI~//~vbCBR~
//  			scrcell2tocell(data,pattr,colstart,len);           //~va3kR~
    			scrcell2tocell(data,pattr,0/*colstart*/,len);   //colstart is orgx,sddata is relative offset 0//~va3kI~
                usdlen+=usdlen;                                    //~va00R~
                UTRACED("scrdisp STR3 attr cell after",pattr,len*2); //~vafkR~//~vbCBR~
#endif                                                             //~va00R~
			case USDFCELLSTR:
				len=min(usdlen,ucwwidth*2);                        //~v0h6R~
#ifdef UNX                                                         //~v45eI~
  #ifndef XXE                                                      //~v64aI~
				if (dbcsclearmode	//clear required mode          //~v45kR~
                && 	!UCBITCHK(psd->USDflag2,USDF2CSRLINE))//not draw by hex csr display reason//~v45kR~
                {                                                  //~v45eI~
                    cleardbcssw=scrdbcslineclear(colstart,y,len,psd->USDcell,pdbcs);	//dbcs cleared//~v45hR~
    				csrsetdbcstbl(x,y,psd->USDcell,pdbcs,len/2-inactvsplit1stsw,1);//~v45eI~
                    if (cleardbcssw)                               //~v45eR~
                	{                                              //~v45eI~
                        if (!uclsvtsw[j])  //first dbcs line       //~v45gI~
                        {                                          //~v45kI~
                        	dbcscleardone=1;                       //~v45kI~
	                        uclsvtstartline[j]=i;  //line count to be rewrite//~v45gI~
                        }                                          //~v45kI~
                        uclsvtsw[j]=i+1;  //line count to be rewrite//~v45fR~
                    	puclsvt->UCLSVTpsd=psd;                 //save for later write//~v45fR~
//                    	puclsvt->UCLSVTlen=len;                 //save for later write//~v79BR~
                      	puclsvt->UCLSVTlen=len-inactvsplit1stsw*2; //~v79BI~
                    	puclsvt->UCLSVTy  =y;                 //save for later write//~v45fR~
                    	puclsvt->UCLSVTx  =colstart;          //save for later write//~v45fR~
                	}                                              //~v45eI~
                	else                                           //~v45eI~
//  					uirc=uviowrtcellstr(psd->USDcell,(USHORT)len,//~v45eI~//~va3qR~
//  					uirc=uviowrtcellstr(psd->USDcell,(USHORT)(len-inactvsplit1stsw*2),//~vb4fR~
    					uirc=uviowrtcellstr(lineopt,psd->USDcell,(USHORT)(len-inactvsplit1stsw*2),//~vb4fI~
										(USHORT)y,(USHORT)colstart);//~v45eI~
                    break;                                         //~v45eI~
                }                                                  //~v45eI~
  #endif //!XXE                                                    //~v64aI~
#endif                                                             //~v45eI~
//  			csrsetdbcstbl(x,y,psd->USDcell,pdbcs,len/2,1);     //~v0h8R~
    			csrsetdbcstbl(x,y,psd->USDcell,pdbcs,len/2-inactvsplit1stsw,1);//~v0h8R~
//				uirc=uviowrtcellstr(psd->USDcell,(USHORT)len,      //~va3qR~
//				uirc=uviowrtcellstr(psd->USDcell,(USHORT)(len-inactvsplit1stsw*2),//~vb4fR~
  				uirc=uviowrtcellstr(lineopt,psd->USDcell,(USHORT)(len-inactvsplit1stsw*2),//~vb4fI~
					(USHORT)y,(USHORT)colstart);
				break;
#ifdef W32                                                         //~v08cI~
			case USDFCELLSTR2:                                     //~v08cI~
				len=min(usdlen,ucwwidth);	//USDlen is ctr        //~v0h6R~
//  			csrsetdbcstbl(x,y,data,pdbcs,len,0);//char not cell//~v0h8R~
    			csrsetdbcstbl(x,y,data,pdbcs,len-inactvsplit1stsw,0);//char not cell//~v0h8R~
//                uirc=uviowrtcharstr(data+psd->USDoff,(USHORT)len,//~v0h3R~
//                        (USHORT)y,(USHORT)colstart+psd->USDoff); //~v0h3R~
				paw=(WORD*)(void*)psd->USDcell;                    //~v08cI~
//                uirc=uviowrtattrstr(paw+psd->USDoff,(USHORT)len, //~v0h3R~
//                        (USHORT)y,(USHORT)colstart+psd->USDoff); //~v0h3R~
//              uirc=uvio_w95wrtcharstratt2(y,						//row//~vb4fR~
                uirc=uvio_w95wrtcharstratt2(lineopt,y,						//row//~vb4fI~
											colstart+psd->USDoff,	//col//~v0h3I~
											len,                   //~v0h3I~
											data+psd->USDoff,		//char str//~v0h3I~
											paw+psd->USDoff);        //attr str//~v0h3R~
				break;                                             //~v08cI~
#endif                                                             //~v08cI~
			case USDFCHARSTR:
				len=min(usdlen,ucwwidth-psd->USDoff);              //~v0h6R~
				if (len)
				{
//  				csrsetdbcstbl(x,y,data,pdbcs,len,0);           //~v0h8R~
    				csrsetdbcstbl(x,y,data,pdbcs,len-inactvsplit1stsw,0);//~v0h8R~
//					uirc=uviowrtcharstr(data+psd->USDoff,(USHORT)len,//~vb4fR~
  					uirc=uviowrtcharstr(lineopt,data+psd->USDoff,(USHORT)len, //no xe user//~vb4fI~
						(USHORT)y,(USHORT)colstart+psd->USDoff);
				}
				break;
			case USDFCHARSTRATT:
				len=min(usdlen,ucwwidth);                          //~v0h6R~
//  			csrsetdbcstbl(x,y,data,pdbcs,len,0);               //~v0h8R~
    			csrsetdbcstbl(x,y,data,pdbcs,len-inactvsplit1stsw,0);//~v0h8R~
//*avoid over write to avoid screen flush                       //~5127I~
			#ifdef W32                                             //~v0h4I~
				if (psd->USDnattr0len && !psd->USDnattr0off)//from data top//~v0h4I~
					attrlen=min(psd->USDnattr0len,ucwwidth);       //~v0h6R~
                else                                               //~v0h4R~
	                attrlen=0;                                     //~v0h4I~
				len=min(usdlen,ucwwidth);                          //~v0h6R~
				len-=psd->USDoff;                                  //~v0h4I~
				if (attrlen==psd->USDoff	//data cont            //~v0h4I~
                && attrlen					//both half exist      //~v0h4I~
                && len>0)					                       //~v0h4I~
                {                                                  //~v76vI~
//              	uirc=uvio_w95wrtcharstratt3(y,                 //~vb4fR~
                	uirc=uvio_w95wrtcharstratt3(lineopt,y,         //~vb4fI~
												colstart,          //~v0h4I~
                                                data,              //~v0h4I~
												attrlen,		//first half len//~v0h4I~
												psd->USDnattr0, //first half attr//~v0h4R~
												len,            //2nd half len//~v0h4I~
					                            psd->USDnattr); //2nd half attr//~v0h4I~
    	            psd->USDnattr0len=0;//processed                //~v76vI~
                }                                                  //~v76vI~
                else	//2 api                                    //~v0h4I~
                {                                                  //~v0h4I~
                    if (attrlen)                                   //~v0h4I~
                    {                                              //~v76vI~
//                      uirc=uviowrtcharstratt(data,(USHORT)attrlen,//~vb4fR~
                        uirc=uviowrtcharstratt(lineopt,data,(USHORT)attrlen,//~vb4fI~
                                (USHORT)y,(USHORT)colstart,&psd->USDnattr0);//~v0h4I~
		                psd->USDnattr0len=0;//processed            //~v76vI~
                    }                                              //~v76vI~
                    if (len>0)                                     //~v0h4I~
//                      uirc=uviowrtcharstratt(data+psd->USDoff,(USHORT)len,//~vb4fR~
                        uirc=uviowrtcharstratt(lineopt,data+psd->USDoff,(USHORT)len,//~vb4fI~
                            (USHORT)y,(USHORT)colstart+psd->USDoff,&psd->USDnattr);//~v0h4I~
                }//2 api                                           //~v0h4I~
//              psd->USDnattr0len=0;//processed                    //~v76vR~
            #else                                                  //~v0h4I~
				if (psd->USDnattr0len && !psd->USDnattr0off)//from data top//~5127I~
				{                                               //~5127I~
					attrlen=min(psd->USDnattr0len,ucwwidth);       //~v0h6R~
//  				uirc=uviowrtcharstratt(data,(USHORT)attrlen,   //~vb4fR~
    				uirc=uviowrtcharstratt(lineopt,data,(USHORT)attrlen,//~vb4fI~
							(USHORT)y,(USHORT)colstart,&psd->USDnattr0);//~5127I~
					psd->USDnattr0len=0;//processed             //~5127I~
                }                                               //~5127I~
				len=min(usdlen,ucwwidth);                          //~v0h6R~
				if ((len-=psd->USDoff)>0)                       //~5127I~
//  				uirc=uviowrtcharstratt(data+psd->USDoff,(USHORT)len,//~vb4fR~
    				uirc=uviowrtcharstratt(lineopt,data+psd->USDoff,(USHORT)len,//~vb4fI~
						(USHORT)y,(USHORT)colstart+psd->USDoff,&psd->USDnattr);//~5127R~
			#endif                                                 //~v0h4I~
				break;
			case USDFNATTR:
				len=min(usdlen,ucwwidth);                          //~v0h6R~
				uirc=uviowrtnattr(&psd->USDnattr,(USHORT)len,
					(USHORT)y,(USHORT)colstart);
				break;
			case USDFNCELL:
				len=min(usdlen,ucwwidth);                          //~v0h6R~
    			csrcleardbcstbl(x,y,len);                          //~va21I~
//  			uirc=uviowrtncell(psd->USDcell,(USHORT)len,        //~vb4uR~
    			uirc=uviowrtncell(lineopt,psd->USDcell,(USHORT)len,//~vb4uI~
					(USHORT)y,(USHORT)colstart);
//  			csrcleardbcstbl(x,y,len);                          //~va21R~
				break;
			case USDFNCHAR:
				len=min(usdlen,ucwwidth);                          //~v0h6R~
				csrcleardbcstbl(x,y,len);                          //~va21I~
				uirc=uviowrtnchar(data,(USHORT)len,
					(USHORT)y,(USHORT)colstart);
//  			csrcleardbcstbl(x,y,len);                          //~va21R~
				break;
			}
			attrlen=min(psd->USDnattr0len,pcw->UCWwidth-psd->USDnattr0off);
			attrlen=max(attrlen,0);
			if (attrlen)
				uirc=uviowrtnattr(&psd->USDnattr0,(USHORT)attrlen,
					(USHORT)y,(USHORT)colstart+psd->USDnattr0off);

			if (cell0len=psd->USDcell0len,cell0len)
			{
				cell0len=min(cell0len,pcw->UCWwidth*2);
//  			uirc=uviowrtcellstr(psd->USDcell,(USHORT)cell0len, //~vb4fR~
    			uirc=uviowrtcellstr(lineopt,psd->USDcell,(USHORT)cell0len,//~vb4fI~
					(USHORT)y,(USHORT)colstart);
			}
//draw vline                                                       //~v0h9I~
			if (inactdrawsw)	//vsplit inactive area             //~v0h9I~
            {                                                      //~v79zI~
                UTRACEP("scrdraw draw vsplit row=%d,col=%d\n",y,vsplitline);//~v79zI~
				csrcleardbcstbl(vsplitline,y,1);                   //~va3pR~
//  			uirc=uviowrtncell(Svline,1,(USHORT)y,(USHORT)vsplitline);//~vb4uR~
    			uirc=uviowrtncell(UVIOO_NOSAVE,Svline,1,(USHORT)y,(USHORT)vsplitline);//~vb4uI~
            }                                                      //~v79zI~
#ifdef W32                                                         //~v08iI~
            if (blockend                                           //~v08iI~
			&&  i>=blockstart && i<blockend)                       //~v08iR~
				uvio_w95buffmode(0);	//buff use rteset out of block//~v08iI~
#endif                                                             //~v08iI~
            IFDEF_WXEXXE(                                          //~v780R~
            				xesynsetgblstyletbl(0,pcw,psd,j,i,inactvsplit1stsw);//~v780R~
                        )                                          //~v780I~
		}//client row
#ifdef W32                                                         //~v08iI~
        if (blockend)                                              //~v08iI~
        {                                                          //~v08iI~
            UTRACEP("%s:call buffwrite j=%d,blockend=%d\n",UTT,j,blockend);//~vb4fR~
    		uvio_w95buffmode(1);	//write from buff              //~v08iI~
//  		uirc=uvio_w95buffwrite(pcw->UCWorgy+blockstart,0,(blockend-blockstart)*Gscrwidth);//~v0h9R~
//  		uirc=uvio_w95buffwrite(pcw->UCWorgy+blockstart,x,      //~vb4fR~
    		uirc=uvio_w95buffwrite(linesplitopt,pcw->UCWorgy+blockstart,x,//~vb4fR~
									((blockend-blockstart)<<16)|ucwwidth);//~v0h9I~
									//pos(x,y),rect=(height,width) //~v0h9R~
    		uvio_w95buffmode(0);	//reset for other rtn(cls etc) //~v08iI~
        }                                                          //~v08iI~
#endif                                                             //~v08iI~
		UCBITOFF(pcw->UCWflag,UCWFDRAW);
	}//j
//    if (inactdrawsw && UCBITCHK(Gscrstatus,GSCRSSPLITV))         //~v0h9R~
//    {       //inactive draw and vsplit                           //~v0h9R~
//        j=Gscrsplitv-(active==1);//                              //~v0h9R~
//        for (i=0;i<rowend;i++)                                   //~v0h9R~
//          if (i>=MAXVLINE || drawvlinesw[i])                     //~v0h9R~
//            uirc=uviowrtncell(Svline,1,(USHORT)i,(USHORT)j);     //~v0h9R~
//    }                                                            //~v0h9R~
#ifdef UNX                                                         //~v45hI~
  #ifndef XXE                                                      //~v64aI~
      cleardbcsswerr1=0;                                           //~v45hI~
      cleardbcsswerr2=0;                                           //~v45hI~
  #endif //!XXE                                                    //~v64aI~
#endif                                                             //~v45hI~
    if (insmodesw==2)		//hdr of "INS" is written              //~v51TI~
      if (inswordlen)                                              //~v51VR~
//  	uirc=uviowrtcharstratt(Sins+1,(USHORT)3,	//skip preceding 1 space,3:len//~v51VR~
//  	uirc=uviowrtcharstratt(Sins+1,(USHORT)(inswordlen-1),	//skip preceding 1 space,3:len//~vb4fR~
    	uirc=uviowrtcharstratt(lineopt_insrep,Sins+1,(USHORT)(inswordlen-1),	//skip preceding 1 space,3:len//~vb4fI~
                 (USHORT)0,(USHORT)inswordpos+1,	 //y:x         //~v51VR~
				 Gattrtbl+COLOR_TITLE_R);//reverse                 //~v51TI~
#ifdef W32                                                         //~va5sR~
  #ifndef WXE                                                      //~va5sR~
	if (buffuse)                                                   //~va5sR~
    {                                                              //~va5sR~
        UTRACEP("%s:call buffwrite\n",UTT);                        //~vb4fR~
//  	uirc=uvio_w95buffwrite(0,0,Gscrheight*Gscrwidth);	//pos(0,0),len//~vb4fR~
		lineopt=linesplitopt|UVIOO_FULLSCR;   //full scr write     //~vb4fR~
    	uirc=uvio_w95buffwrite(lineopt,0,0,Gscrheight*Gscrwidth);	//pos(0,0),len//~vb4fI~
		uvio_w95buffmode(0);	//reset for other rtn(cls etc)     //~va5sR~
	}                                                              //~va5sR~
//  uviom_notify(UVIOMNO_NOLIGATURE,0/*reset*/,0);                 //~vb2YR~//~vb39R~
  #endif //!WXE                                                    //~va5sR~
#endif                                                             //~va5sR~
    if (errmsg)	//not popup err msgsw
	{	
		scrconfirmset();//confirmation active                   //~v04eR~
		Serrwritesw=1;
//  	len=min((int)strlen(errmsg),Gscrwidth);                    //~v43nR~
    	errmsglen=(int)strlen(errmsg);                             //~v43nI~
#ifdef UTF8SUPPH                                                   //~va00I~
		opt=XEUTFGLSMO_STRZ|XEUTFGLSMO_ERRMSG;                     //~va10I~
//  	if (xeutf_getmixedstr(opt,errmsg,errmsglen,errmsglc,0/*dbcs*/,errmsgcodetype,sizeof(errmsglc),&errmsglenlc,//~va0wR~//~va10R~//~va1CR~
//  							0/*oututf8str*/,0/*oututf8buffsz*/,0/*out utf8len*/) & XEUTFGU8MRC_UTF8)	//contains utf8 str//~va00I~//~va1CR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50R~//~va3AI~//~va50R~
		if (rc2=xeutf_seterrmsgct(opt,errmsg,errmsglen,errmsglc,errmsgdbcst/*dd fmt output dbcs when contains utf8*/,errmsgcodetype,sizeof(errmsglc),&errmsglenlc),rc2)//~va3AI~//~va5sR~
#else                                                              //~va3AI~
		if (xeutf_seterrmsgct(opt,errmsg,errmsglen,errmsglc,errmsgcodetype,sizeof(errmsglc),&errmsglenlc))//~va1CI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~//~va3AI~
        {                                                          //~va00I~
        	errmsg=errmsglc;                                       //~va00I~
            errmsglen=errmsglenlc;                                 //~va00I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
          if (rc2==2)                                              //~va50I~
            errmsgutf8sw=2;        //ddfmt                         //~va50I~
          else                                                     //~va50I~
#endif                                                             //~va50I~
            errmsgutf8sw=1;                                        //~va00I~
        }                                                          //~va00I~
#endif                                                             //~va00I~
    	orgx=pcwoldact->UCWorgx;                                   //~v45cI~
		orgy=pcwoldact->UCWorgy;                                   //~v45cI~
        ucwwidth=pcwoldact->UCWwidth;                              //~v45bI~
//      if (errmsglen>Gscrwidth)                                   //~v45bR~
        if (errmsglen>ucwwidth)                                    //~v45bI~
        {                                                          //~v43nI~
//  		len=Gscrwidth;                                         //~v45bR~
    		len=ucwwidth;                                          //~v45bI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
          if (errmsgutf8sw==2)                                     //~va50I~
          {                                                        //~va50I~
	        if (UDBCSCHK_DBCS2NDU(*(errmsgdbcst+len)))	//split dbcs//~va50R~
            	len--;                                             //~va50I~
          }                                                        //~va50I~
          else                                                     //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
          {                                                        //~va50I~
#ifdef UTF8SUPPH                                                   //~va1cR~
        	setdbcstbl(errmsg,errmsgdbcst,min(len+MAX_MBCSLENLC-1,errmsglen));//~va1cR~
			len-=xesub_cleardbcssplit(XESUBCDSO_RIGHT|XESUBCDSO_GETCTR,0/*data*/,errmsgdbcst,len,0/*repct*/);//~va1cR~
#else                                                              //~va1cR~
        	setdbcstbl(errmsg,errmsgdbcst,len+1);                  //~v43nI~
	        if (*(errmsgdbcst+len)==DBCS2NDCHAR)	//split dbcs   //~v43nI~
            	len--;                                             //~v43nI~
#endif                                                             //~va1cR~
          }                                                        //~va50I~
        }                                                          //~v43nI~
        else                                                       //~v43nI~
        {                                                          //~v43nI~
        	len=errmsglen;                                         //~v43nI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
          if (errmsgutf8sw!=2)                                     //~va50I~
#endif                                                             //~va50I~
        	setdbcstbl(errmsg,errmsgdbcst,len);                    //~v43nI~
        }                                                          //~v43nI~
        if (len<ucwwidth)  //not full line                         //~v45hI~
#ifdef UTF8SUPPH                                                   //~va1cR~
			if ((dbcssplitctr=csrresetobdbcs(1,orgx+len,orgy))>0)	//half of prev dbcs ovewritten//~va1cR~
#else                                                              //~va1cR~
			if (csrresetobdbcs(1,orgx+len,orgy))	//half of prev dbcs ovewritten//~v45hI~
#endif                                                             //~va1cR~
            {                                                      //~v45hI~
                len2=errmsglen-len;                                //~v45hI~
#ifdef UTF8SUPPH                                                   //~va1cR~
                if (len2)                                          //~va1cR~
                	memmove(errmsg+len+dbcssplitctr,errmsg+len,(UINT)len2);//~va1cR~
                memset(errmsg+len,' ',(UINT)dbcssplitctr);  //overwrite previous dbcs filename split//~va1cR~
                memset(errmsgdbcst+len,0,(UINT)dbcssplitctr);      //~va1cR~
                errmsglen+=dbcssplitctr;                           //~va1cR~
            	len+=dbcssplitctr;                                 //~va1cR~
#else                                                              //~va1cR~
                if (len2)                                          //~v45hI~
                	memmove(errmsg+len+1,errmsg+len,(UINT)len2);   //~v47rR~
                *(errmsg+len)=' ';                                 //~v45hI~
                *(errmsgdbcst+len)=0;                              //~v45hR~
                errmsglen++;                                       //~v45hI~
            	len++;                                             //~v45hI~
#endif                                                             //~va1cR~
            }                                                      //~v45hI~
//  	csrsetdbcstbl(pcwoldact->UCWorgx,pcwoldact->UCWorgy,errmsg,errmsgdbcst,//~v45cR~
//  					len,0);                                    //~v45cI~
#ifdef UNX                                                         //~v45hI~
  #ifndef XXE                                                      //~v64aI~
		if (dbcsclearmode)	//clear required mode                  //~v45kR~
        	cleardbcsswerr1=scrdbcslineclearerrmsg(orgx,orgy,len,errmsg,errmsgdbcst);    //dbcs cleared//~v45hI~
  #endif //!XXE                                                    //~v64aI~
#endif                                                             //~v45hI~
    	csrsetdbcstbl(orgx,orgy,errmsg,errmsgdbcst,len,0);         //~v45cI~
#ifdef UNX                                                         //~v45hI~
  #ifndef XXE                                                      //~v64aI~
      if (cleardbcsswerr1)                                         //~v45hI~
      {                                                            //~v45kI~
        dbcscleardone=1;                                           //~v45kI~
      	cleardbcsswerr1=len;		//rewritelen                   //~v45hI~
      }                                                            //~v45kI~
      else                                                         //~v45hI~
  #endif //!XXE                                                    //~v64aI~
#endif                                                             //~v45hI~
      {                                                            //~va00I~
#ifdef UTF8SUPPH                                                   //~va00I~
        if (orgx)                 //2nd of vsplit                  //~vb4uI~
    		lineopt_errmsg|=UVIOO_VSPLIT2ND;                       //~vb4uI~
       if (errmsgutf8sw)                                           //~va00I~
//  	uirc=xescrerrmsgbycell(errmsg,errmsgcodetype,len,orgy,orgx);//~vb4fR~
    	uirc=xescrerrmsgbycell(lineopt_errmsg,errmsg,errmsgcodetype,len,orgy,orgx);//~vb4fI~
       else                                                        //~va00I~
#endif                                                             //~va00M~
//  	uirc=uviowrtcharstratt(errmsg,(USHORT)len,                 //~vb4fR~
    	uirc=uviowrtcharstratt(lineopt_errmsg,errmsg,(USHORT)len,  //~vb4fI~
//  			(USHORT)pcw1->UCWorgy,(USHORT)pcw1->UCWorgx,       //~v09nR~
//  			(USHORT)pcwoldact->UCWorgy,(USHORT)pcwoldact->UCWorgx,//~v45cR~
    			(USHORT)orgy,(USHORT)orgx,                         //~v45cI~
				 Gattrtbl+COLOR_TITLE_R);//errmsg on hdr line
      }                                                            //~va00I~
//        if (!orgx)  //not top                                    //~v45hR~
//            scrdbcsoverwrite(0,orgx-1,orgy,Gattrtbl+COLOR_TITLE);//write "." if split//~v45hR~
//        if (len<ucwwidth)  //not full line                       //~v45hR~
//            scrdbcsoverwrite(1,orgx+len,orgy,Gattrtbl+COLOR_TITLE);//write "." if split//~v45hR~
//      if (errmsglen>Gscrwidth                                    //~v45bR~
        if (errmsglen>ucwwidth                                     //~v45bI~
//      &&  (pcwoldact->UCWorgy+1)<Gscrheight)                     //~v45cR~
        &&  (orgy+1)<Gscrheight)                                   //~v45cR~
        {                                                          //~v43nI~
        	errmsglen1=len;                                        //~v43nI~
			len=errmsglen-len;		//overflow len                 //~v43nI~
//          if (len>Gscrwidth)                                     //~v45bR~
            if (len>ucwwidth)                                      //~v45bI~
            {                                                      //~v43nI~
//              len=Gscrwidth;                                     //~v45bR~
                len=ucwwidth;                                      //~v45bI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
              if (errmsgutf8sw==2)                                 //~va50I~
              {                                                    //~va50I~
                if (UDBCSCHK_DBCS2NDU(*(errmsgdbcst+len)))    //split dbcs//~va50R~
                    len--;                                         //~va50I~
//              memcpy(errmsgdbcst,errmsgdbcst+errmsglen1,len);    //~va50I~//~vb2zR~
                memcpy(errmsgdbcst,errmsgdbcst+errmsglen1,(size_t)len);//~vb2zI~
              }                                                    //~va50I~
              else                                                 //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
              {                                                    //~va50I~
#ifdef UTF8SUPPH                                                   //~va1cR~
                setdbcstbl(errmsg+errmsglen1,errmsgdbcst,min(len+MAX_MBCSLENLC-1,errmsglen-errmsglen1));//~va1cR~
				len-=xesub_cleardbcssplit(XESUBCDSO_RIGHT|XESUBCDSO_GETCTR,0/*data*/,errmsgdbcst,len,0/*repct*/);//~va1cR~
#else                                                              //~va1cR~
                setdbcstbl(errmsg+errmsglen1,errmsgdbcst,len+1);   //~v43nI~
                if (*(errmsgdbcst+len)==DBCS2NDCHAR)    //split dbcs//~v43nI~
                    len--;                                         //~v43nI~
#endif                                                             //~va1cR~
              }                                                    //~va50I~
            }                                                      //~v43nI~
            else                                                   //~v43nI~
            {                                                      //~va50I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
              if (errmsgutf8sw==2)                                 //~va50R~
//              memcpy(errmsgdbcst,errmsgdbcst+errmsglen1,len);    //~va50I~//~vb2zR~
                memcpy(errmsgdbcst,errmsgdbcst+errmsglen1,(size_t)len);//~vb2zI~
              else                                                 //~va50I~
#endif                                                             //~va50I~
                setdbcstbl(errmsg+errmsglen1,errmsgdbcst,len);     //~v45hR~
            }                                                      //~va50I~
        if (len<ucwwidth)  //not full line                         //~v45hI~
#ifdef UTF8SUPPH                                                   //~va1cR~
			if ((dbcssplitctr=csrresetobdbcs(1,orgx+len,orgy+1))>0)	//half of prev dbcs ovewritten//~va1cR~
#else                                                              //~va1cR~
			if (csrresetobdbcs(1,orgx+len,orgy+1))	//half of prev dbcs ovewritten//~v45hI~
#endif                                                             //~va1cR~
            {                                                      //~v45hI~
#ifdef UTF8SUPPH                                                   //~va1cR~
                memset(errmsg+errmsglen1+len,' ',(UINT)dbcssplitctr);//~va1cR~
                memset(errmsgdbcst+len,0,(UINT)dbcssplitctr);      //~va1cR~
            	len+=dbcssplitctr;                                 //~va1cR~
#else                                                              //~va1cR~
                *(errmsg+errmsglen1+len)=' ';                      //~v45hI~
                *(errmsgdbcst+len)=0;                              //~v45hR~
            	len++;                                             //~v45hI~
#endif                                                             //~va1cR~
            }                                                      //~v45hI~
//          csrsetdbcstbl(pcwoldact->UCWorgx,pcwoldact->UCWorgy+1,errmsg,errmsgdbcst,//~v45cR~
//                          len,0);                                //~v45cR~
#ifdef UNX                                                         //~v45hI~
  #ifndef XXE                                                      //~v64aI~
		if (dbcsclearmode)	//clear required mode                  //~v45kR~
        	cleardbcsswerr2=scrdbcslineclearerrmsg(orgx,orgy+1,len,errmsg+errmsglen1,errmsgdbcst);    //dbcs cleared//~v45hI~
  #endif //!XXE                                                    //~v64aI~
#endif                                                             //~v45hI~
            csrsetdbcstbl(orgx,orgy+1,errmsg+errmsglen1,errmsgdbcst,len,0);//~v45hR~
#ifdef UNX                                                         //~v45hI~
  #ifndef XXE                                                      //~v64aI~
        if (cleardbcsswerr2)                                       //~v45hI~
        {                                                          //~v45kI~
	        dbcscleardone=1;                                       //~v45kI~
        	cleardbcsswerr2=len;		//rewrite len              //~v45hR~
        }                                                          //~v45kI~
        else                                                       //~v45hI~
  #endif //!XXE                                                    //~v64aI~
#endif                                                             //~v45hI~
        {                                                          //~va00I~
#ifdef UTF8SUPPH                                                   //~va00I~
          if (errmsgutf8sw)                                        //~va00I~
//  		uirc=xescrerrmsgbycell(errmsg+errmsglen1,errmsgcodetype+errmsglen1,len,orgy+1,orgx);//~vb4fR~
//  		uirc=xescrerrmsgbycell(lineopt_errmsg,errmsg+errmsglen1,errmsgcodetype+errmsglen1,len,orgy+1,orgx);//~vb4tR~
    		uirc=xescrerrmsgbycell(lineopt_errmsg|UVIOO_ERRMSG2,errmsg+errmsglen1,errmsgcodetype+errmsglen1,len,orgy+1,orgx);//~vb4tI~
       	  else                                                     //~va00I~
#endif                                                             //~va00M~
//          uirc=uviowrtcharstratt(errmsg+errmsglen1,(USHORT)len,  //~vb4fR~
//          uirc=uviowrtcharstratt(lineopt_errmsg,errmsg+errmsglen1,(USHORT)len,//~vb4tR~
            uirc=uviowrtcharstratt(lineopt_errmsg|UVIOO_ERRMSG2,errmsg+errmsglen1,(USHORT)len,//~vb4tI~
//              (USHORT)pcwoldact->UCWorgy+1,(USHORT)pcwoldact->UCWorgx,//~v45cR~
                (USHORT)orgy+1,(USHORT)orgx,                       //~v45cI~
             	Gattrtbl+COLOR_TITLE_R);//errmsg on hdr line       //~v43nI~
        }                                                          //~va00I~
//            if (!orgx)  //not top                                //~v45hR~
//                scrdbcsoverwrite(0,orgx-1,orgy+1,Gattrtbl+COLOR_FRAME);//write "." if split//~v45hR~
//            if (len<ucwwidth)  //not full line                   //~v45hR~
//                scrdbcsoverwrite(1,orgx+len,orgy+1,Gattrtbl+COLOR_FRAME);//write "." if split//~v45hR~
    		UCBITON((((PUSCRD)pcwoldact->UCWpsd)+1)->USDflag2,USDF2DRAW);//redraw//~v43nI~
        }//2nd line overflow                                       //~v43nI~
	}
//#ifdef W32                                                       //~va5sR~
//  #ifndef WXE                                                    //~va5sR~
//    if (buffuse)                                                 //~va5sR~
//    {                                                            //~va5sR~
//        uirc=uvio_w95buffwrite(0,0,Gscrheight*Gscrwidth);   //pos(0,0),len//~va5sR~
//        uvio_w95buffmode(0);    //reset for other rtn(cls etc)   //~va5sR~
//    }                                                            //~va5sR~
//  #endif //!WXE                                                  //~va5sR~
//#endif                                                           //~va5sR~
                                                                   //~v089I~
#ifdef W32                                                         //~vb39I~
  #ifndef WXE                                                      //~vb39I~
//  uviom_notify(UVIOMNO_NOLIGATURE,0/*reset*/,0);                 //~vb4fR~
  #endif //!WXE                                                    //~vb39I~
#endif                                                             //~vb39I~
#ifdef UNX                                                         //~v45eI~
  #ifndef XXE                                                      //~v64aI~
UTRACEP("dbcscleardone=%d,doclearoksw=%d\n",dbcscleardone,doclearoksw); //write twice//~v79zI~
	if (dbcscleardone)	//line clear mode                          //~v45kR~
    {                                                              //~v45eI~
      if (!doclearoksw)  //write twice                             //~v479I~
      {                                                            //~v479I~
        csrwrite(pcw1);                                            //~v45kR~
UTRACEP("refresh1 before\n");                                      //~v79zR~
        uviol_refresh();    //refresh before redraw                //~v45kR~
//UTRACEP("refresh1 after \n");                                    //~v55RR~
      }                                                            //~v479I~
        for (j=0;j<2;j++)                                          //~v45kR~
        {                                                          //~v45kR~
            rowend=uclsvtsw[j];                                    //~v45kR~
            if (!rowend)                                           //~v45kI~
            	continue;                                          //~v45kI~
            i=uclsvtstartline[j];                                  //~v45kR~
            for (;i<rowend;i++)                                    //~v45kR~
            {                                                      //~v45kR~
                puclsvt=Spuclsvt+j*Gscrheight+i;                   //~v45kR~
                psd=puclsvt->UCLSVTpsd;    //dbcs line cleared     //~v45kR~
                if (!psd)                                          //~v45kR~
                    continue;                                      //~v45kR~
                lineopt=psd->USDuvioo;                             //~vb4kI~
                UTRACEP("scrdraw draw DBCS row=%d,col=%d,len=%d\n",puclsvt->UCLSVTy,puclsvt->UCLSVTx,puclsvt->UCLSVTlen);//~v79zI~
//              uviowrtcellstr(psd->USDcell,(USHORT)puclsvt->UCLSVTlen,//~v45kR~//~vb4kR~
                uviowrtcellstr(lineopt,psd->USDcell,(USHORT)puclsvt->UCLSVTlen,//~vb4kI~
                                    (USHORT)puclsvt->UCLSVTy,(USHORT)puclsvt->UCLSVTx);//~v45kR~
            }//i                                                   //~v45kR~
        }//j                                                       //~v45kR~
        if (cleardbcsswerr1)                                       //~v45hI~
        {                                                          //~va00I~
#ifdef UTF8SUPPH                                                   //~va00I~
      	  if (errmsgutf8sw)                                        //~va00I~
//  		xescrerrmsgbycell(errmsg,errmsgcodetype,cleardbcsswerr1,orgy,orgx);//~vb4fR~
    		xescrerrmsgbycell(lineopt_errmsg,errmsg,errmsgcodetype,cleardbcsswerr1,orgy,orgx);//~vb4fI~
       	  else                                                     //~va00I~
#endif                                                             //~va00I~
//  		uviowrtcharstratt(errmsg,(USHORT)cleardbcsswerr1,      //~v45hI~//~vb4kR~
    		uviowrtcharstratt(lineopt_errmsg,errmsg,(USHORT)cleardbcsswerr1,//~vb4kI~
    								(USHORT)orgy,(USHORT)orgx,     //~v45hI~
				 					Gattrtbl+COLOR_TITLE_R);//errmsg on hdr line//~v45hI~
        }                                                          //~va00I~
        if (cleardbcsswerr2)                                       //~v45hI~
        {                                                          //~va00I~
#ifdef UTF8SUPPH                                                   //~va00I~
      	  if (errmsgutf8sw)                                        //~va00I~
//  		xescrerrmsgbycell(errmsg+errmsglen1,errmsgcodetype+errmsglen1,cleardbcsswerr2,orgy+1,orgx);//~vb4fR~
//  		xescrerrmsgbycell(lineopt_errmsg,errmsg+errmsglen1,errmsgcodetype+errmsglen1,cleardbcsswerr2,orgy+1,orgx);//~vb4tR~
    		xescrerrmsgbycell(lineopt_errmsg|UVIOO_ERRMSG2,errmsg+errmsglen1,errmsgcodetype+errmsglen1,cleardbcsswerr2,orgy+1,orgx);//~vb4tI~
       	  else                                                     //~va00I~
#endif                                                             //~va00I~
//          uviowrtcharstratt(errmsg+errmsglen1,(USHORT)cleardbcsswerr2,//~v45hI~//~vb4kR~
//          uviowrtcharstratt(lineopt_errmsg,errmsg+errmsglen1,(USHORT)cleardbcsswerr2,//~vb4tR~
            uviowrtcharstratt(lineopt_errmsg|UVIOO_ERRMSG2,errmsg+errmsglen1,(USHORT)cleardbcsswerr2,//~vb4tI~
                					(USHORT)orgy+1,(USHORT)orgx,   //~v45hI~
             						Gattrtbl+COLOR_TITLE_R);//errmsg on hdr line//~v45hI~
        }                                                          //~va00I~
    }                                                              //~v45eI~
    else	//no dbcs line found                                   //~v479I~
#ifdef  LNX                                                        //~v48rI~
	  if (!(Gunxflag & GUNX_UNDERX))                               //~v48rR~
#endif                                                             //~v48rI~
    	doclearoksw=0;  //no need to use clearok                   //~v479I~
    	                                                           //~v479I~
  #endif //!XXE                                                    //~v64aI~
#endif                                                             //~v45eI~
//cursor and file client colomn set to line buff
	csrwrite(pcw1);
#ifdef UNX                                                         //~v19fI~
  #ifndef XXE                                                      //~v64aI~
//  if (Gkbdopt & UKBDL_CLEAR)                                     //~v45fR~
//    #ifdef AIX                                                   //~v45fR~
//        if (fulldrawsw2                                          //~v45fR~
//        ||  errmsg) //err msg over written                       //~v45fR~
//          if (UCBITCHK(Gscrstatus,GSCRSDBCS))   //for lang=SJIS  //~v45fR~
//            uviol_clearok(1);   //clear after refresh write to terminal//~v45fR~
//    #else                                                        //~v45fR~
//        if (fulldrawsw2                                          //~v45fR~
//        ||  errmsg) //err msg over written                       //~v45fR~
//            if (Gunxflag & GUNX_KON)                             //~v45fR~
//                uviol_clearok(1);   //clear after refresh write to terminal//~v45fR~
//    #endif                                                       //~v45fR~
    if (doclearoksw)  //--c and fulldraw                           //~v45hR~
//  ||  (errmsg && dbcssw)) //err msg over written                 //~v45hR~
        uviol_clearok(1);   //clear after refresh write to terminal//~v45fI~
    if (S1stclear)                                                 //~v45BR~
    {                                                              //~v45BR~
        S1stclear=0;                                               //~v45BR~
        uviol_clearok(1);   //clear after refresh write to terminal//~v45BR~
        doclearoksw=1;//to issue clearok(0) later                  //~v55RI~
    }                                                              //~v45BR~
UTRACEP("refresh2 before\n");                                      //~v79zR~
	uviol_refresh();                                               //~v19fI~
//UTRACEP("refresh2 after \n");                                    //~v55RR~
    if (doclearoksw)                                               //~v55RI~
        uviol_clearok(0);   //clear after refresh write to terminal//~v55RI~
  #endif //!XXE                                                    //~v64aI~
#endif                                                             //~v19fI~
	return (int)uirc;
}//scrdisp
#ifdef UTF8SUPPH                                                   //~va00I~
//**************************************************************** //~va00I~
//!set CELLSTR from CELLSTR2(data+cell)                            //~va00I~
//**************************************************************** //~va00I~
int scrcell2tocell(char *Pdata,char *Pcell,int Poffs,int Plen)     //~va00R~
{                                                                  //~va00I~
	int ii;                                                        //~va00I~
    char *pc,*pcell;                                               //~va00I~
//***********************                                          //~va00I~
    UTRACED("in pdata",Pdata+Poffs,Plen);                          //+vbi3I~
	for (ii=Plen,pc=Pdata+Poffs,pcell=Pcell+Poffs+Poffs;ii>0;ii--) //~va00R~
    {                                                              //~va00I~
    	*pcell++=*pc++;                                            //~va00R~
        pcell++;                                                   //~va00R~
    }                                                              //~va00I~
    UTRACED("out cell",Pcell+Poffs*2,Plen);                        //+vbi3I~
    return 0;                                                      //~va00I~
}//scrcell2tocell                                                  //~va00I~
#endif                                                             //~va00I~
#ifdef UNX                                                         //~v45kI~
  #ifndef XXE                                                      //~v64aI~
//**************************************************************** //~v45eI~
//!scrdbcslineclear                                                //~v45eI~
//clear csr line when dbcs containing                              //~v45eI~
//*parm1:absolute pos write x                                      //~v45eI~
//*parm2:absolute pos write y                                      //~v45eI~
//*parm3:cell string len                                           //~v45eI~
//*parm4:cell addr                                                 //~v45hR~
//*parm5:new dbcs tbl                                              //~v45hR~
//*return:0:not cleared  ;1:line cleared                           //~v45eI~
//**************************************************************** //~v45eI~
int scrdbcslineclear(int Pcol,int Prow,int Plen,UCHAR *Pcell,UCHAR *Ppdbcs)//~v45hR~
{                                                                  //~v45eI~
//  int ii,dbcslen,idxtop,idxend,dbcssw=0,len;                     //~v45BR~//~vafdR~
    int ii,dbcslen,idxtop=0,idxend=0,dbcssw=0,len;                 //~vafdI~
    UCHAR *pdbcso,*pdbcsn,*pcelli,*pcello;                         //~v45fR~
    UCHAR *pcellc;                                                 //~v45BI~
//*********************                                            //~v45eI~
//*** this function never be called when UTF8UCS2 (see xemainl.c)  //~va21I~
//  pdbcso=Gscrdbcstbl+Gscrwidth*Prow+Pcol;                        //~v47SR~
    pdbcso=Sunxdbcscleartbl+Gscrwidth*Prow+Pcol;                   //~v47SI~
	pdbcsn=Ppdbcs;                                                 //~v45eI~
//  dbcslen=(UINT)Plen>>1;                                         //~v45hR~//~vb2zR~
    dbcslen=(int)((UINT)Plen>>1);                                  //~vb2zI~
    pcelli=Pcell;                                                  //~v45eI~
    pcello=Sunxattrcleartbl;	//for clear dbcs line              //~v45eI~
    for (ii=0;ii<dbcslen;ii++)                                     //~v45fR~
    {                                                              //~v45eI~
#ifdef UTF8SUPPH                                                   //~va1cR~
    	if (UDBCSCHK_DBCSCHARS(*pdbcso) //previously dbcs written  //~va1cR~
    	||  UDBCSCHK_DBCSCHARS(*pdbcsn))//this time dbcs write     //~va1cR~
#else                                                              //~va1cR~
    	if (*pdbcso==DBCS1STCHAR||*pdbcso==DBCS2NDCHAR  //previously dbcs written//~v45eI~
    	||  *pdbcsn==DBCS1STCHAR||*pdbcsn==DBCS2NDCHAR)//this time dbcs write//~v45eI~
#endif                                                             //~va1cR~
        {                                                          //~v45eI~
        	if (!dbcssw)                                           //~v45gR~
            {                                                      //~v45gI~
            	dbcssw=1;                                          //~v45gI~
            	idxtop=ii;  	//start offset                     //~v45fR~
            }                                                      //~v45gI~
            idxend=ii;          //last offset                      //~v45fR~
        	*pcello++=DBCS_CLEAR_CHAR;	//clear dbcs char          //~v45eR~
	        pcelli++;                                              //~v45eI~
        }                                                          //~v45eI~
        else                                                       //~v45eI~
        	*pcello++=*pcelli++;   	//copy new data                //~v45eR~
        *pcello++=*pcelli++;        //copy attr                    //~v45eI~
        *pdbcso=*pdbcsn;			//set new dbcs id              //~v47SI~
        pdbcso++;                                                  //~v45eR~
        pdbcsn++;                                                  //~v45eR~
    }                                                              //~v45eI~
    if (!dbcssw)		//no dbcs found                            //~v45gR~
    	return 0;                                                  //~v45eI~
//  pcellc=Sunxattrcleartbl+Gscrwidth*sizeof(USHORT);	//read workfor clear dbcs line//~v45BR~//~vb2zR~
    pcellc=Sunxattrcleartbl+Gscrwidth*(int)sizeof(USHORT);	//read workfor clear dbcs line//~vb2zI~
	len=(idxend-idxtop+1)<<1;                                      //~v45BI~
	uvioreadcellstr(pcellc,&len,Prow,Pcol+idxtop);                 //~v45BR~
UTRACEP("readcell row=%d,col=%d\n",Prow,Pcol);                     //~v79BR~
UTRACED("read",pcellc,len);                                        //~v79BR~
UTRACED("comp",Pcell+idxtop*2,len);                                //~v79BR~
//UTRACED("parm",Pcell+(idxtop<<1),len);                           //~v45BR~
    if (!memcmp(pcellc,Pcell+(idxtop<<1),(UINT)len))               //~v45BR~
    {                                                              //~v79BI~
    	UTRACEP("read DBCS comp same\n");                          //~v79BI~
    	return 0;			//no change                            //~v45BI~
    }                                                              //~v79BI~
//  uviowrtcellstr(Sunxattrcleartbl+(idxtop<<1),(USHORT)((idxend-idxtop+1)<<1),//~v45BR~
//  				(USHORT)Prow,(USHORT)Pcol+idxtop);             //~v45BI~
//  uviowrtcellstr(Sunxattrcleartbl+(idxtop<<1),len,Prow,Pcol+idxtop);//~v45BR~//~vb4kR~
    uviowrtcellstr(0/*all space*/,Sunxattrcleartbl+(idxtop<<1),len,Prow,Pcol+idxtop);//~vb4kI~
//UTRACED("wrt ",Sunxattrcleartbl+(idxtop<<1),len);                //~v45BR~
    return 1;                                                      //~v45eI~
}//scrdbcslineclear                                                //~v45eI~
//**************************************************************** //~v45hI~
//!scrdbcslineclearerrmsg                                          //~v45hI~
//clear csr line when dbcs containing                              //~v45hI~
//*parm1:absolute pos write x                                      //~v45hI~
//*parm2:absolute pos write y                                      //~v45hI~
//*parm3:char string len                                           //~v45hI~
//*parm4:string addr                                               //~v45hI~
//*parm5:new dbcs tbl                                              //~v45hI~
//*return:0:not cleared  ;1:line cleared                           //~v45hI~
//**************************************************************** //~v45hI~
int scrdbcslineclearerrmsg(int Pcol,int Prow,int Plen,UCHAR *Pstring,UCHAR *Ppdbcs)//~v45hI~
{                                                                  //~v45hI~
//  int ii,idxtop,idxend,dbcssw=0;                                 //~v45hR~//~vafdR~
    int ii,idxtop=0,idxend=0,dbcssw=0;                             //~vafdI~
    UCHAR *pdbcso,*pdbcsn,*pci,*pco,attr;                          //~v45hR~
//*********************                                            //~v45hI~
	attr=*(Gattrtbl+COLOR_TITLE_R);                                //~v45hI~
//	pdbcso=Gscrdbcstbl+Gscrwidth*Prow+Pcol;                        //~v47SR~
    pdbcso=Sunxdbcscleartbl+Gscrwidth*Prow+Pcol;                   //~v47SI~
	pdbcsn=Ppdbcs;                                                 //~v45hI~
    pci=Pstring;                                                   //~v45hI~
    pco=Sunxattrcleartbl;	//for clear dbcs line                  //~v45hI~
    for (ii=0;ii<Plen;ii++)                                        //~v45hR~
    {                                                              //~v45hI~
#ifdef UTF8SUPPH                                                   //~va1cR~
    	if (UDBCSCHK_DBCSCHARS(*pdbcso) //previously dbcs written  //~va1cR~
    	||  UDBCSCHK_DBCSCHARS(*pdbcsn))//this time dbcs write     //~va1cR~
#else                                                              //~va1cR~
    	if (*pdbcso==DBCS1STCHAR||*pdbcso==DBCS2NDCHAR  //previously dbcs written//~v45hI~
    	||  *pdbcsn==DBCS1STCHAR||*pdbcsn==DBCS2NDCHAR)//this time dbcs write//~v45hI~
#endif                                                             //~va1cR~
        {                                                          //~v45hI~
        	if (!dbcssw)                                           //~v45hI~
            {                                                      //~v45hI~
            	dbcssw=1;                                          //~v45hI~
            	idxtop=ii;  	//start offset                     //~v45hI~
            }                                                      //~v45hI~
            idxend=ii;          //last offset                      //~v45hI~
        	*pco++=DBCS_CLEAR_CHAR;	//clear dbcs char              //~v45hI~
        }                                                          //~v45hI~
        else                                                       //~v45hI~
        	*pco++=*pci;                                           //~v45hR~
        pci++;                                                     //~v45hI~
        *pdbcso=*pdbcsn;			//set new dbcs id              //~v47SI~
        pdbcso++;                                                  //~v45hI~
        pdbcsn++;                                                  //~v45hI~
    }                                                              //~v45hI~
    if (!dbcssw)		//no dbcs found                            //~v45hI~
    	return 0;                                                  //~v45hI~
//  uviowrtcharstratt(Sunxattrcleartbl+idxtop,(USHORT)(idxend-idxtop+1),//~v45hI~//~vb4kR~
    uviowrtcharstratt(0/*lineopt*/,Sunxattrcleartbl+idxtop,(USHORT)(idxend-idxtop+1),//~vb4kR~
					(USHORT)Prow,(USHORT)Pcol,&attr);//errmsg on hdr line//~v45hI~
    return 1;                                                      //~v45hI~
}//scrdbcslineclearerrmsg                                          //~v45hI~
  #endif //!XXE                                                    //~v64aI~
#endif                                                             //~v45kI~
#ifdef UTF8SUPPH                                                   //~va00I~
//****************************************************************//~v45hR~//~va00I~
//errmsg write by cell for utf8 str                                //~va00I~
//****************************************************************//~v45hR~//~va00I~
//UINT xescrerrmsgbycell(char *Perrmsg,char *Pcodetype,int Plen,int Prow,int Pcol)//~vb4fR~
UINT xescrerrmsgbycell(int Popt,char *Perrmsg,char *Pcodetype,int Plen,int Prow,int Pcol)//~vb4fI~
{                                                                  //~va00I~
	UINT uirc=0;                                                   //~v19fR~//~va00I~
	int len,ctr,ii;                                                //~va00R~
	UCHAR attru8,attrlc;                                           //~va00I~
    char cellstr[MAXCOLUMN*2],*pci,*pco,*pcn;                      //~va00R~
    UCHAR ch;                                                      //~vb4cI~
//***********************************                              //~va00I~
    attru8=                                                        //~va00I~
    attrlc=Gattrtbl[COLOR_TITLE_R];                                //~va00I~
	attru8=Gattrtbl[COLOR_DLINENO];	//browse fg               //~v06vR~//~va00I~
//  attru8=(attrlc & 0xf0)|(attru8 & 0x0f); //bg+fg                //~va00I~//~vb2zR~
    attru8=(UCHAR)((attrlc & 0xf0)|(attru8 & 0x0f)); //bg+fg       //~vb2zI~
//  len=min(Plen+Plen,sizeof(cellstr));                            //~va00I~//~vb2zR~
    len=min(Plen+Plen,(int)sizeof(cellstr));                       //~vb2zI~
    ctr=len>>1;                                                    //~va00I~
    for (ii=0,pco=cellstr,pci=Perrmsg,pcn=Pcodetype;ii<ctr;ii++)   //~va00I~
    {                                                              //~va00I~
//  	*pco++=*pci++;                                             //~va00I~//~vb4cR~
    	ch=*pci++;                                                 //~vb4cI~
    	*pco++=ch;                                                 //~vb4cI~
        if (*pcn++==XEUTFCT_UTF8)                                  //~va00R~
        	*pco++=attru8;                                         //~va00I~
        else                                                       //~va00I~
        {                                                          //~vb4cI~
//for DBCS,errrep at xeutfcvl2dd. need for ctlchar(ascii)          //~vb4cR~
          if (!*(pcn-1)	//ascii                                    //~vb4cI~
          &&  ch>0 && Gunpdispchartbl[ch])   	//unprintable except null(null is space)//~vb4cI~
          {                                                        //~vb4cI~
            UTRACEP("%s:%02x:unrintable\n",UTT,ch);                //~vb4cI~
        	*(pco-1)=XEUTF_ERRREPCH;	//displayable char         //~vb4cI~
        	*pco++=attru8;                                         //~vb4cI~
          }                                                        //~vb4cI~
          else                                                     //~vb4cI~
        	*pco++=attrlc;                                         //~va00I~
        }                                                          //~vb4cI~
    }                                                              //~va00I~
//  uirc=uviowrtcellstr(cellstr,(USHORT)len,(USHORT)Prow,(USHORT)Pcol);//~vb4fR~
    uirc=uviowrtcellstr(Popt,cellstr,(USHORT)len,(USHORT)Prow,(USHORT)Pcol);//~vb4fR~
    return uirc;                                                   //~va00I~
}//xescrerrmsgbycell                                               //~va00I~
#endif   //UTF8SUPPH                                                          //~v45kI~//~va00I~
////****************************************************************//~v45hR~
////!scrdbcsoverwrite                                              //~v45hR~
////write "." for overwritten dbcs of hdr/cmd line                 //~v45hR~
////*parm1:dest:0:prev byte,1:next byte                            //~v45hR~
////*parm2:absolute csr posx                                       //~v45hR~
////*parm3:absolute csr posy                                       //~v45hR~
////*parm4:attr byte address                                       //~v45hR~
////*return:0:no overwrtten;1:overwrte issued                      //~v45hR~
////****************************************************************//~v45hR~
//int scrdbcsoverwrite(int Pdest,int Pposx,int Pposy,char *Pattr)  //~v45hR~
//{                                                                //~v45hR~
////*********************                                          //~v45hR~
//    if (!csrresetobdbcs(Pdest,Pposx,Pposy))                      //~v45hR~
//        return 0;                                                //~v45hR~
//    uviowrtcharstratt(".",1,(USHORT)Pposy,(USHORT)Pposx,Pattr);  //~v45hR~
//    return 1;                                                    //~v45hR~
//}//scrdbcsoverwrite                                              //~v45hR~
//****************************************************************
//!scrregist                                                    //~v04dR~
//*register client to screen
//*parm1:client type
//*parm2:control block ptr for each client type
//*return:client work elem or 0 if storage shortage             //~v04dR~
//****************************************************************
PUCLIENTWE scrregist(UCHAR Pclienttype,PVOID Ppanelc)
{
	PUCLIENTWE pcw;
static int Spcwseqno=0;                                            //~v670I~
//****************************
	pcw=UALLOCC(1,UCLIENTWESZ);                                 //~v04dR~
    UALLOCCHK(pcw,0);   //return 0 if storage shortage          //~v04dI~
	memcpy(pcw->UCWcbid,UCWCBID,4);	//acronym                   //~5105I~
        pcw->UCWseqno=++Spcwseqno;	//instanceid               //~v670I~
	pcw->UCWppc=Ppanelc;			//panel control
	pcw->UCWtype=Pclienttype;
	pcw->UCWflag=UCWFDRAW;
//#ifdef WXE                                                       //~v64aR~
#ifdef WXEXXE                                                      //~v64aI~
    UCBITON(pcw->UCWflag,UCWFRESIZE);   //re-init ufld by current scr size at first draw//~v55RR~
#endif                                                             //~v55RR~
	pcw->UCWfilehdrlineno=FILEHDRLINENO;    //at first 2,chnge to 3 by COL cmd//~v11NI~
//enq work element
	screnqcw(Gscrcurclient,pcw,UQUE_TOP,0);                     //~v037R~
	scrresize(pcw);
	return pcw;
}//scrregist                                                    //~4C30R~

//****************************************************************
// scrpopup
//*free current client work and popup previous
//*parm1 :req id 0:deq top then display prev                    //~5105R~
//*             -1:deq top and set to parm2 addr then display prev//~5228R~
//*              else(pcw):deq pcw the enq to top               //~5105R~
//*parm2 :deqed pcw store addr(req=-1 only),if 0 enq to last    //~5228I~
//*return:new client work elem if null no client-->mean quit
//****************************************************************
PUCLIENTWE scrpopup(PUCLIENTWE Ppcw,PUCLIENTWE *Pppcw)          //~5228R~
{
static 	FTFUNC *Sfuncwakeup[UCWMAXTYPE]                            //~v08bM~
//  		={panwakeup,filewakeup,filewakeup};                    //~v56pR~
    		={panwakeup,filewakeup,dirwakeup};                     //~v56pI~
	PUCLIENTWE pcw;
	PUFILEH    pfh;                                             //~5118I~
	int curi;
	int swapsw=0;                                               //~5118I~
//****************************
//  *Gcmdbuff=0;                                                //~5224R~
	curi=Gscrcurclient;
	if (!Ppcw)                                                  //~5105I~
	{                                                           //~5105I~
		scrdeqcw(curi,1,0);			//deq and free(top entry)   //~5105R~
		pcw=scrgetcw(0);	//under going client exist          //~5105R~
	}                                                           //~5105I~
	else                                                        //~5105I~
//		if ((LONG)Ppcw==-1)		//deq top and enq to end        //~5105I~//~vafkR~
 		if ((ULPTR)Ppcw==-1)		//deq top and enq to end       //~vafkI~
		{                                                       //~5105I~
			pcw=scrdeqcw(curi,0,0);	//deq and not free(top entry)//~5105R~
            if (Pppcw)              //parm specified            //~5228R~
            	*Pppcw=pcw;			//return dequed addr        //~5228I~
			else                                                //~5228I~
	            screnqcw(curi,pcw,UQUE_END,0);			//enq to end//~v037R~
			pcw=scrgetcw(0);	//new top current               //~5105I~
        }                                                       //~5105I~
        else	//popup pcw specified                           //~5105I~
		{                                                       //~5105I~
			pcw=Ppcw;                                           //~5105I~
			swapsw=(Ppcw->UCWsplitid!=curi);//split part swap   //~5118I~
			scrdeqcw(Ppcw->UCWsplitid,0,pcw);//from org split and not free//~5118R~
            screnqcw(curi,pcw,UQUE_TOP,0);			//enq to end//~v037R~
			if (swapsw)	//split part swap                       //~5118I~
				pcw=scrgetcw(-1);	//other client top draw at first//~5118R~
        }                                                       //~5105I~
	if (pcw)	//under going client exist                      //~5105R~
	{
		for (;;)                                                //~5118I~
		{                                                       //~5118I~
			(Sfuncwakeup[pcw->UCWtype])(pcw);                      //~v08bR~
			scrresize(pcw);		//re-scize client screen        //~5118R~
//  		csrrestore(pcw);	//restore previous cursor pos      //~v105I~
//        	if (pcw->UCWtype==UCWTMENU)                            //~v20yR~
          	if (pcw->UCWtype==UCWTMENU                             //~v20yI~
			&&  ((PUPANELC)(pcw->UCWppc))->UPCid==PANTOPMENU)      //~v20yR~
    			csrhomepos(0);		//reset to home pos            //~v105I~
          	else                                                   //~v105I~
    			csrrestore(pcw);	//restore previous cursor pos  //~v105R~
//  		UCBITON(pcw->UCWflag,UCWFWAKEUP+UCWFDRAW);	//int and draw//~v08bI~
    		UCBITON(pcw->UCWflag,UCWFDRAW);	//draw                 //~v08bI~
			if (!swapsw)                                        //~5118I~
				break;                                          //~5118I~
			pcw=Ppcw;                                           //~5118I~
			swapsw=0;	//next break                            //~5118I~
		}                                                       //~5118I~
	}
	else	//no undergoing client exist
	{
      if (swapsw)   //other side gone                              //~v11eI~
      {                                                            //~v11eI~
        pcw=Ppcw;       //resize itself                            //~v11eI~
		curi=!curi;     //another is gone                          //~v11eI~
      }                                                            //~v11eI~
      else                                                         //~v11eI~
		if (!(pcw=scrgetcw(-1)))	//no one exist
			return 0;
                                                                   //~v11eI~
		if (!curi)	//first is gone
		{				//second is now first
			while(pcw=scrdeqcw(1,0,0),pcw)//deq top from second client area,but not free//~5118R~
            {                                                   //~5118I~
				screnqcw(0,pcw,UQUE_END,0);//re enq,last to last//~v037R~
				if (pcw->UCWtype==UCWTFILE)//maint browse pcw ptr//~5118I~
				{                                               //~5118I~
					pfh=((PUFILEC)pcw->UCWpfc)->UFCpfh;         //~5118I~
					pfh->UFHbrowsepcw[0]=pfh->UFHbrowsepcw[1];  //~5118I~
					pfh->UFHbrowsepcw[1]=0;                     //~5118R~
				}                                               //~5118I~
            }                                                   //~5118I~
			pcw=scrgetcw(1);	//client1
		}//first is gone
		UCBITOFF(Gscrstatus,GSCRSSPLITV|GSCRSSPLITH);
		Gscrcurclient=0;
		Gscrsplitv=0;
		Gscrsplith=0;
		(Sfuncwakeup[pcw->UCWtype])(pcw);                          //~v08bR~
		scrresize(pcw);
//  	csrhomepos(0);			//move csr to 1st fld of current active//~v10tR~
//      if (pcw->UCWtype==UCWTMENU)                                //~v20yR~
        if (pcw->UCWtype==UCWTMENU                                 //~v20yI~
		&&  ((PUPANELC)(pcw->UCWppc))->UPCid==PANTOPMENU)          //~v20yI~
            csrhomepos(0);      //reset to home pos                //~v10tI~
        else                                                       //~v10tI~
            csrrestore(pcw);    //restore previous cursor pos      //~v10tI~
//  	UCBITON(pcw->UCWflag,UCWFWAKEUP+UCWFDRAW);	//int and draw //~v08bR~
    	UCBITON(pcw->UCWflag,UCWFDRAW);	//int and draw             //~v08bI~
	}
	return pcw;
}//scrpopup
//****************************************************************
// scrgetcw
//*get current client work element and set set relative csr pos
//*parm   :client id -- 0:current active client, -1:another client
//*       :3 split1 under top,4:spli2 under top                    //~vbi3I~
//*retuen :client work element
//****************************************************************
PUCLIENTWE scrgetcw(int Pclientid)
{
	int splitid;
//****************************
	switch (Pclientid)
	{
	case 0:								//req current
		splitid=Gscrcurclient;		//current active
		break;
	case 1:								//first
	case 2:								//second
		splitid=Pclientid-1;			//specified client
		break;
	case -1:							//another
		splitid=!Gscrcurclient;	//another client
		break;
	default:
		return 0;
	}
	return UGETQTOP(&Sclientwq[splitid]);//get client
}//scrgetcw

//****************************************************************
// screnqcw
//*enq clientwe and assign psd
//*parm1  :split part id
//*parm2  :client work element
//*parm3  :enq position                                         //~5105I~
//*parm4  :enq target position pcw for UQUE_BEF/UQUE_AFT        //~v037I~
//*retuen :none
//****************************************************************
void screnqcw(int Psplitid,PUCLIENTWE Ppcw,int Ppos,PUCLIENTWE Ppcwt)//~v037R~
{
//****************************
	if (Ppcwt)                                                  //~v037I~
		UENQENT(Ppos,Ppcwt,Ppcw);	//after/before target       //~v037I~
    else                                                        //~v037I~
		UENQ(Ppos,&Sclientwq[Psplitid],Ppcw);                   //~v037R~
	Ppcw->UCWsplitid=Psplitid;
//#ifdef WXE                                                       //~v64aR~
#ifdef WXEXXE                                                      //~v64aI~
	Ppcw->UCWpsd=Spuscrd+Psplitid*Gscrbuffheight;//assign screen area//~v500I~
#else                                                              //~v500I~
	Ppcw->UCWpsd=Spuscrd+Psplitid*Gscrheight;//assign screen area
#endif                                                             //~v500I~
	return;
}//screnqcw
//****************************************************************
// scrdeqcw
//*deq clientwe and free if requested
//*parm1  :split part id
//*parm2  :free id
//*parm3  :pcw,deq top if 0                                     //~5105I~
//*retuen :pcw
//****************************************************************
PUCLIENTWE scrdeqcw(int Psplitid,int Pfreereq,PUCLIENTWE Ppcw)  //~5105R~
{
	PUCLIENTWE pcw;
//****************************
	if (Ppcw)                                                   //~5105I~
		pcw=UDEQ(UQUE_ENT,&Sclientwq[Psplitid],Ppcw);           //~5105I~
	else                                                        //~5105I~
		pcw=UDEQ(UQUE_TOP,&Sclientwq[Psplitid],0);              //~5105R~
	if (Pfreereq && pcw)
//  {                                                              //~v08cR~
    {                                                              //~vbCBR~
//      if (pcw==Gcappcw)   //current block pcw                    //~v08cR~
//			capreset(0);    //crear Gcappcw                        //~v08cR~
//      if (pcw==Gcapcbpcw) //clipboard pcw                        //~v08cR~
//			Gcapcbpcw=0;    //crear hidden pcw                     //~v08cR~
        UFREEIFNZ(pcw->UCWfindcmd);                                //~vbCBR~
		ufree(pcw);
//   }                                                             //~v08cR~
     }                                                             //~vbCBR~
	return pcw;
}//scrdeqcw

//****************************************************************
// scrresize:setup client work
//****************************************************************
void scrresize(PUCLIENTWE Ppcw)
{
//********************
	if (!Ppcw->UCWsplitid)			//first client
	{
		Ppcw->UCWorgx	=0;							//screen origin
		Ppcw->UCWorgy 	=0;							//screen origin
		if (UCBITCHK(Gscrstatus,GSCRSSPLITV))
			Ppcw->UCWwidth 	=Gscrsplitv;	//client width
		else
			Ppcw->UCWwidth 	=Gscrwidth;			//client width

		if (UCBITCHK(Gscrstatus,GSCRSSPLITH))	//horizontal split
			Ppcw->UCWheight	=Gscrsplith;	//client height
		else
			Ppcw->UCWheight	=Gscrheight;		//client height
	}
	else			//second client
	{
		if (UCBITCHK(Gscrstatus,GSCRSSPLITH))	//horizontal split
		{
			Ppcw->UCWorgx	=0;					//screen origin
			Ppcw->UCWorgy 	=Gscrsplith;	//screen origin
			Ppcw->UCWwidth 	=Gscrwidth;			//client width	
			Ppcw->UCWheight	=Gscrheight-Gscrsplith; //client height
		}
		else	//vertical split
		{
			Ppcw->UCWorgx	=Gscrsplitv;		//screen origin
			Ppcw->UCWorgy 	=0;						//screen origin
			Ppcw->UCWwidth 	=Gscrwidth-Gscrsplitv;	//client width	
			Ppcw->UCWheight	=Gscrheight;		    //client height
		}
	}
	if (Ppcw->UCWtype==UCWTFILE)
		Ppcw->UCWmaxline=Ppcw->UCWheight;	//full line up to boundary
	else
		Ppcw->UCWmaxline
			=min(Ppcw->UCWheight,((PUPANELC)Ppcw->UCWppc)->UPClineno);
	return;
}//scrresize

//****************************************************************
// scrfulldraw
//*draw both screen
//*parm1  :cur pcw
//*retuen :other client pcw
//****************************************************************
PUCLIENTWE scrfulldraw(PUCLIENTWE Ppcw)
{
	PUCLIENTWE pcwo;
//****************************
	UCBITON(Ppcw->UCWflag,UCWFDRAW);	//redraw
	if (pcwo=scrgetcw(-1),pcwo)			//other client
		UCBITON(pcwo->UCWflag,UCWFDRAW);//redraw
	return pcwo;
}//scrfulldraw
                                                                //~5224I~
//**************************************************            //~5224I~
//*search pcw by pannel id                                      //~5224I~
//*parm1: split id: 0-current,1:split1,2:split2,-1:other client //~5224I~
//*parm2: panel id                                              //~5224I~
//*rc   : pcw or 0 if not found                                 //~5224I~
//**************************************************            //~5224I~
PUCLIENTWE scrsrchcw(int Psplitid,int Ppanid)                   //~5224I~
{                                                               //~5224I~
	PUCLIENTWE pcw;                                             //~5224R~
    int splitid;                                                //~5224I~
//************************************                          //~5224I~
	switch (Psplitid)                                           //~5224I~
	{                                                           //~5224I~
	case 0:								//req current           //~5224I~
		splitid=Gscrcurclient;		//current active            //~5224I~
		break;                                                  //~5224I~
	case 1:								//first                 //~5224I~
	case 2:								//second                //~5224I~
		splitid=Psplitid-1;			//specified client          //~5224R~
		break;                                                  //~5224I~
	case -1:							//another               //~5224I~
		splitid=!Gscrcurclient;	//another client                //~5224I~
		break;                                                  //~5224I~
	default:                                                    //~5224I~
		return 0;                                               //~5224I~
	}                                                           //~5224I~
	                                                            //~5224I~
	for (pcw=UGETQTOP(&Sclientwq[splitid]);pcw;pcw=UGETQNEXT(pcw))//~5224R~
	{                                                           //~5224I~
		if (((PUPANELC)pcw->UCWppc)->UPCid==Ppanid)             //~5224I~
			return pcw;                                         //~5224I~
	}                                                           //~5224I~
	return 0;                                                   //~5224I~
}//scrsrchcw                                                    //~5224I~
//**************************************************               //~vbi3I~
//*search cmd history list pcw                                     //~vbi3I~
//**************************************************               //~vbi3I~
PUCLIENTWE scrsrchcwchl(int Popt,int Psplitid)                     //~vbi3I~
{                                                                  //~vbi3I~
	PUCLIENTWE pcw;                                                //~vbi3I~
    PUFILEH pfh;                                                   //~vbi3I~
    PUFILEC pfc;                                                   //~vbi3I~
//************************************                             //~vbi3I~
	for (pcw=UGETQTOP(&Sclientwq[Psplitid]);pcw;pcw=UGETQNEXT(pcw))//~vbi3I~
	{                                                              //~vbi3I~
        pfc=pcw->UCWpfc;                                           //~vbi3I~
        if (pfc)                                                   //~vbi3I~
        {                                                          //~vbi3I~
        	pfh=pfc->UFCpfh;                                       //~vbi3I~
            if (pfh)                                               //~vbi3I~
            {                                                      //~vbi3I~
				if (pfh->UFHtype==UFHTCMDHIST)                     //~vbi3I~
					return pcw;                                    //~vbi3I~
            }                                                      //~vbi3I~
        }                                                          //~vbi3I~
	}                                                              //~vbi3I~
	return 0;                                                      //~vbi3I~
}//scrsrchcwchl                                                    //~vbi3I~
//#ifdef WXE                                                       //~v64aR~
#ifdef WXEXXE                                                      //~v64aR~
//**************************************************               //~v500I~
//*notify from wxe for current screen size                         //~v500I~
//*rc   : 0                                                        //~v500I~
//**************************************************               //~v500I~
int scronsize(int Prow,int Pcol,int Pcpchngsw)                     //~v500R~
{                                                                  //~v500I~
    int  ii;                                                       //~v500R~
	PUCLIENTWE pcw;                                                //~v500I~
//************************************                             //~v500I~
    if (!Prow || !Pcol)                                            //~v500I~
    	return 0;                                                  //~v500M~
	if (!Gscrbuffwidth)	//not yet scrinit  ended                   //~v500R~
    {                                                              //~v500I~
    	Sinitmaxcol=Pcol;                                          //~v500I~
    	Sinitmaxrow=Prow;                                          //~v500I~
    	return 0;                                                  //~v500I~
    }                                                              //~v500I~
    if (Gscrheight==Prow && Gscrwidth==Pcol && !Pcpchngsw)         //~v500R~
    	return 0;                                                  //~v500I~
    Gscrheight=Prow;                                               //~v500I~
    Gscrwidth=Pcol;                                                //~v500I~
    for (ii=0;ii<2;ii++)                                           //~v500I~
		for (pcw=UGETQTOP(&Sclientwq[ii]);pcw;pcw=UGETQNEXT(pcw))  //~v500I~
        {                                                          //~v500I~
	    	scrresize(pcw);                                        //~v500I~
			UCBITON(pcw->UCWflag,UCWFWAKEUP|UCWFRESIZE|UCWFDRAW);  //~v500R~
        }                                                          //~v500I~
	scrdisp();	//redraw                                           //~v500I~
	return 0;                                                      //~v500I~
}//scronsize                                                       //~v500I~
#endif                                                             //~v500I~
//**************************************************               //~v603I~
//*scrmultilineerrmsg                                              //~v603I~
//*process multiline(seperated by \n)                              //~v603I~
//*rc   : 0                                                        //~v603I~
//**************************************************               //~v603I~
int scrsavemultilineerrmsg(UCHAR *Perrmsg)                         //~v603R~
{                                                                  //~v603I~
    int lennext;                                                   //~v603I~
	UCHAR *pc;                                                     //~v603R~
//************************************                             //~v603I~
    Smultilineerrmsgnext=0;                                        //~v603I~
    if (pc=strchr(Perrmsg,'\n'),pc)    //multiline                 //~v603R~
    {                                                              //~v603R~
        *pc++=0;	//disply a line up to \n                       //~v603R~
        lennext=(int)strlen(pc);                                   //~v603R~
        if (lennext)    //not last line                            //~v603R~
        {                                                          //~v603I~
        	if (Perrmsg==Smultilineerrmsgnext)	//previously saved text//~v603I~
            	Smultilineerrmsgnext=pc;                           //~v603I~
            else                                                   //~v603I~
            {                                                      //~v603I~
            	if (Smultilineerrmsgtop)	//free previous        //~v603I~
		        	ufree(Smultilineerrmsgtop);                    //~v603I~
            	Smultilineerrmsgtop=umalloc((UINT)(lennext+1)); //alloc new//~v603R~
	            if (Smultilineerrmsgtop)//malloc ok                //~v603I~
                {                                                  //~v603I~
	            	Smultilineerrmsgnext=Smultilineerrmsgtop;      //~v603I~
		            strcpy(Smultilineerrmsgnext,pc);               //~v603I~
                }                                                  //~v603I~
            }                                                      //~v603I~
        }//not last line                                           //~v603I~
    }//has next                                                    //~v603I~
    if (Smultilineerrmsgnext)	//not multi                        //~v603I~
      	Gscropt|=GSCROPT_MULTILINEPENDING;  //multiline pending    //~v603R~
    else                                                           //~v603I~
      	Gscropt&=~GSCROPT_MULTILINEPENDING;  //multiline pending   //~v603R~
    return 0;                                                      //~v603I~
}//scrsavemultilineerrmsg                                          //~v603I~
#ifdef LNX                                                         //~v69FI~
//**************************************************               //~v69FI~
//*acssetup to draw box line                                       //~v69FI~
//*rc   : 0                                                        //~v69FI~
//**************************************************               //~v69FI~
int scracssetup(int Popt)                                          //~v69FI~
{                                                                  //~v69FI~
//#ifndef XXE                                                      //~v69XR~
static int Sacssetsw=0;                                            //~v69FI~
static UCHAR Sunpdispchartblsave[256];                             //~v69FI~
    int funcid,setreq,acscnt=0;                                      //~v69FR~//~vafdR~
    UCHAR acstbl[256],acsch;                                       //~v69FR~
//  FUNCTBL *pft;                                                  //~v705R~
//*****************                                                //~v69FI~
UTRACEP("scracssetup opt=%x\n",Popt);                              //~v69FI~
    memset(acstbl,0,sizeof(acstbl));                               //~v69FI~
	if (!(Popt & GOPT5ACS)) //acs reset req                        //~v69MR~
    {                                                              //~v69FI~
		if (!Sacssetsw)	//not previousely acs mode                 //~v69FI~
        	return 4;	//aready                                   //~v69FI~
        memcpy(Gunpdispchartbl,Sunpdispchartblsave,256);           //~v69FI~
		Sacssetsw=0;	//not previousely acs mode                 //~v69FI~
		UCBITOFF(Gopt5,GOPT5ACS);	//now no acs mode              //~v69MR~
        setreq=0;                                                  //~v69FI~
    }                                                              //~v69FI~
    else		//acs set req                                      //~v69FI~
    {                                                              //~v69FI~
		if (Sacssetsw)	//already previousely acs mode             //~v69FI~
        	return 4;	//aready                                   //~v69FI~
        memcpy(Sunpdispchartblsave,Gunpdispchartbl,256);	//save to reatore at reset//~v69FI~
		Sacssetsw=1;	//saved prev unp status                    //~v69FI~
		UCBITON(Gopt5,GOPT5ACS);	//now acs mode                 //~v69MR~
//create acs tbl(ALTCHAR on at addch)                              //~v69FI~
        for (acscnt=0,funcid=FUNCID_GRAPHCHAR+1;funcid<=FUNCID_GRAPHCHAR_VL;funcid++)//~v69FR~
        {                                                          //~v69FI~
//      	pft=functblsrch(funcid);                               //~v705R~
//          if (!pft)                                              //~v705R~
//              continue;                                          //~v705R~
//          acsch=pft->FTchar;                                     //~v705R~
//          acsch=funct2getacsch(funcid);                          //~v705R~//~vb2zR~
            acsch=(UCHAR)funct2getacsch(funcid);                   //~vb2zI~
	        *(Gunpdispchartbl+acsch)=0;		//reset unprintable sw //~v69FI~
            acstbl[acscnt++]=acsch;                                //~v69FI~
        }                                                          //~v69FI~
        setreq=1;                                                  //~v69FI~
    }                                                              //~v69FI~
UTRACED("old unp tbl",Sunpdispchartblsave,256);                    //~v69FR~
UTRACED("new unp tbl",Gunpdispchartbl,256);                        //~v69FI~
UTRACED("acs     tbl",acstbl,acscnt);                              //~v69FR~
 #ifdef XXE                                                        //~v69XI~
    xxe_acssetup(setreq,acscnt,acstbl);                            //~v69XI~
 #else                                                             //~v69XI~
    uviol_acssetup(setreq,acscnt,acstbl);                          //~v69FR~
 #endif                                                            //~v69XI~
//#endif //!XXE                                                    //~v69XR~
    return 0;                                                      //~v69FI~
}//scracssetup(void)                                               //~v69FI~
#endif                                                             //~v69FI~
//**************************************************               //~v770I~
//*for dbcs split at INS/REP position(top right corner)            //~va1cR~
//*rc   : 0                                                        //~v770I~
//**************************************************               //~v770I~
int scrsetinsrepdbcs(PUCLIENTWE Ppcw,PUSCRD Ppsd)                  //~v770I~
{                                                                  //~v770I~
//static UCHAR Sinsrepdbcs[4];	//all 0:sbcs                       //~v770R~
	int /*xx,yy,*/col;                                             //~v780R~
    char *pdata,*pdbcs;                                            //~v770R~
//***********************                                          //~v770I~
//  xx=Ppcw->UCWorgx;                                              //~v780R~
//  yy=Ppcw->UCWorgy;                                              //~v780R~
	col=Ppcw->UCWwidth-PANCSRMODEPOS,                              //~v770R~
	pdata=Ppsd->USDdata+col;                                       //~v770R~
	pdbcs=Ppsd->USDdbcs+col;                                       //~v770I~
//  csrresetobdbcs(0/*prev pos reset*/,xx+col-1,yy);	//reset if prev is dbcs1st//~v770R~
//  csrsetdbcstbl(xx+col,yy,pdata,Sinsrepdbcs,4,0);//char not cell //~v770R~
    memset(pdbcs,0,4);	//set also psd                             //~v770I~
#ifdef UTF8SUPPH                                                   //~va1cR~
	xesub_cleardbcssplit(XESUBCDSO_RIGHT,pdata-col,pdbcs-col,col,'.');//~va1cR~
#else                                                              //~va1cR~
    pdbcs--;                                                       //~v770I~
    if (*pdbcs==DBCS1STCHAR)                                       //~v770I~
    {                                                              //~v770M~
    	*(pdata-1)='.';                                            //~v770M~
    	*pdbcs=0;                                                  //~v770I~
    }                                                              //~v770M~
#endif                                                             //~va1cR~
    return 0;                                                      //~v770I~
}//scrsetinsrepdbcs                                                //~v770I~
#ifdef WXEXXE                                                      //~vbdnI~
//*********************************************************************//~vbdnI~
int scrSetUpdateFileMenu(int Popt,PUCLIENTWE Ppcw)                 //~vbdnI~
{                                                                  //~vbdnI~
	if (UCBITCHK(Ppcw->UCWflag,UCWFDRAW))  //current client may cahnged(poped or newly registered//~vbdnI~
    	Gwxestat|=GWXES_UPDATEMENU;                                //~vbdnM~
    return 0;                                                      //~vbdnI~
}//scrSetUpdateFileMenu                                            //~vbdnR~
#endif                                                             //~vbdnI~
