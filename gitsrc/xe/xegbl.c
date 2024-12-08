//*CID://+vbCBR~:                             update#=   85;       //~vbCBR~
//*************************************************************
//*xegbl.c*                                                        //~v09hR~
//*************************************************************
//vbCB:160820 Find cmd;add panel specific option                   //~vbCBI~
//vb3v:160620 (LNX)set xe-console printable for ctl-char same as xxe//~vb3vI~
//vb2D:160221 LNX compiler warning                                 //~vb2DI~
//vac7:120224 Axe force Glocalhostsw=1 (0 is for remote execution by ssh)//~vac7I~
//vac1:120204 (SMB)smb node support                                //~vac1I~
//vaa0:110705 wildcard member display on dirlist,but disallow delete lcmd//~vaa0I~
//va90:110520 ANDROID porting                                      //~va90I~
//va73:100805 (BUG:WXE)/n9 option ignored te on LP64               //~va73I~
//va6R:100722 update default unprintable tbl for wxe               //~va6RI~
//va47:100401 va46 for LNX                                         //~va47I~
//va46:100331 not use ctrl char for tab and tab padding,but use xff as default//~va46I~
//va0n:090905 drop localhost from hdr filename line                //~va0nI~
//v79X:081029 (XXE:BUG) unprintable table on in file have to be for WXE//~v79XI~
//v79z:080916 DBCS tbl for C and K of CJK                          //~v79zR~
//v76p:070628 compare remote file support                          //~v76pI~
//v76g:070620 utility panel(3.14:grep and 3.12:compare);f5:open dirlist, dlcmd "^":send//~v76gI~
//v71v:061022 not fixed(PAGE) scroll type for =0.1/2/3             //~v71vI~
//v64e:050619 (UNX)gethostid always return local,so avandon v64b   //~v64dI~
//v64d:050619 (UNX)cut hostname by "." on hdr filename             //~v64dI~
//v64b:050619 (LNX)to shorten hostname,chk local                   //~v64bI~
//v63z:050606 (UNX)set xprint default cmd name to "xprint.sh"      //~v63zR~
//v60m:050129 display different id from eolid for contline terminater.//~v60mI~
//v51D:030719 (LNX)RedHat9 <0x20 is not displayed normaly          //~v51DI~
//v50k:030101 cv cmd:free cp930work                                //~v50kI~
//v500:021003 (WXE:BUG)initial color is all black.                 //~v500I~
//v500:020929 (WXE)for charset change;exchange unp char,tabdisp char//~v500I~
//v500:020928 (WXE)Font:Terminal(app932.fon) allow same unprintable char for ctl char//~v500I~
//v500:020827 wxe support                                          //~v500I~
//     020923 unprintable display char                             //~v500I~
//v49j:020807 (BUG)ufileeditname dbcs support                      //~v49jI~
//v48s:020507 (AIX)set title color to light-blue(GB) for dtterm    //~v48sI~
//v48j:020507 (AIX)mdos floppy support                             //~v48jI~
//v47d:020223 opt eol char on/off;end of line char and attr specification cmd//~v47dI~
//v440:011125 browse hex                                           //~v440I~
//v43z:011124 7bit dump mode initial value is on for AIX           //~v43zI~
//v41v:010908 UNX:hostname display                                 //~v41vI~
//v40A:010707 LINUX:mdir support                                   //~v40AI~
//v40v:010618 UNX:change default to size display for dir list      //~v40vI~
//v40b:010327 LINUX support:ajust after merge                      //~v40bI~
//v305:001124 AIX support:tab disp char                            //~v305I~
//v304:001124 AIX support:unprintable char definition for teraterm //~v304I~
//v21i:010113 LINUX support:euc code dbcs support                  //~v21iI~
//v20s:001015 (BUG)err msg of color change N/A when XE!SAVE! not exist.//~v20sI~
//v20m:001015 LINUX support(xprint name change XPRINT.EXE-->xprint)//~v20mI~
//v20h:001015 LINUX support(unix like wild card proocess for ".")  //~v20hI~
//v20f:001001 LINUX support(uid/gid display on dirlist)            //~v19TI~
//v19T:000928 LINUX support(Global userid var;from now new grobal is on xegbl.h)//~v19TI~
//v19C:000924 LINUX support(move PALNO_xx gro xe.h to uvio.h fo uviol.c)//~v19CI~
//v19x:000923 LINUX support(another main for other parm by -- and external parm)//~v19xI~
//v19m:000915 LINUX support(unprintable char)                      //~v19mI~
//v19i:000904 LINUX support(kbd io)                                //~v19iI~
//v176:000430 default change for bin file line width from 999 to 72//~v176I~
//v174:000430 default change for bin file to hex lineno.           //~v174I~
//v0i1:980430 move version defi to gbl.h from gbl.c                //~v0hiI~
//v0hR:980429 version v099                                         //~v0hRI~
//v0hM:980419 version v098                                         //~v0hMI~
//v0g0:971207 strstr is ambiguous for xprint cmdf compare          //~v0g0I~
//            default set on gbl(if printcmd!=0 set off)           //~v0g0I~
//v0fz:971201 print/xprint cmd on .ini for each os                 //~v0fzI~
//v0fv:971116 set version                                          //~v0fvI~
//v0aw:970720 command result area FG color default change 14-->15(white)//~v0awI~
//v09X:970629:.ini tab display char parm                           //~v09XI~
//v09U:970628:display unprintable char by 0x0e(J) or 0x16(E)       //~v09UI~
//v09Z:970615:may release v094                                     //~v09EI~
//v09h:970428:relese v092                                          //~v09hI~
//v095:970405:DPMI version                                         //~v095I~
//            -type chk char * and UCHAR *                         //~v095I~
//v091:970104:v091 relese *******************************          //~v091I~
//v080:960906:v080 relese (xe085)                                  //~v080I~
//v07s:960825:new ulib.h/ulibdef.h(no need base def by os2.h)      //~v07sI~
//            to speed up compile,drop include(caused by WIN95 modify)//~v07sI~
//v075:960608:color option                                         //~v076I~
//v070:960526:v070                                                 //~v070I~
//v06n:960320:menu option 6(cmd) support                        //~v06nI~
//v069:960224:linenosz changeable for edit/browse(set default)  //~v069I~
//v063:960217:sub shell prompt                                  //~v063I~
//v060:960210:release v060                                      //~v060I~
//v05a:951104:xprint cmd string by ini file                     //~v05aI~
//v051:951014:print dlcmd                                       //~v051I~
//*v031:950712:new
//*************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <signal.h>
#include <time.h>                                                  //~vac1I~
//*************************************************************
#ifdef OS2                                                         //~v21iR~
    #define INCL_BASE                                              //~v21iR~
    #include <os2.h>                                               //~v21iR~
#endif
#ifdef UNX                                                         //~v40bI~
	#include <termios.h>                                           //~v40bI~
	#include <unistd.h>                                            //~v64bI~
#endif                                                             //~v40bI~
//*******************************************************
#include <ulib.h>
#include <uque.h>
#include <ualloc.h>                                             //~v051I~
#include <uerr.h>                                                  //~v500I~
#include <ucvucs.h>                                                //~v50kI~
#include <ufile.h>                                              //~v069I~
#include <uparse.h>                                                //~vbCBI~
                                                                   //~v19TI~
#include <uvio.h>                                                  //~v19TR~

#ifdef UNX                                                         //~v19dI~
	#include <ufile5.h>                                            //~v20hI~
	#include <uviol.h>                                             //~v19TR~
	#include <ukbdl.h>                                             //~v19TR~
	#include <uunxsub.h>	//ugetugid                             //~v19TI~
#endif                                                             //~v19dI~
#include <uftp.h>	                                               //~v76pI~
#include <utrace.h>                                                //~vb2DI~
                                                                //~v051I~
#include "xe.h"
                                                                   //~v19TI~
#define XEGBL_GLOBAL    //generate grobal var                      //~v19TI~
#include "xegbl.h"
                                                                   //~v19TI~
#include "xescr.h"                                              //~v031R~
#include "xepan.h"                                              //~v031I~
#include "xefile.h"                                             //~v069I~
#include "xeini2.h"                                                //~v0fzI~
#include "xeopt.h"                                                 //~v47dI~
#include "xedlcmd.h"                                               //~v76gR~
#include "xedlcmd6.h"                                              //~v76gI~
#include "xefcmd22.h"                                              //~vbCBI~
//*******************************************************
//*******************************************************       //~v05aI~
#ifdef UNX                                                         //~v20mI~
//static char *Sxprintcmd="xprint";                                //~v63zR~
static char *Sxprintcmd="xprint.sh";                               //~v63zI~
#else  //!UNX                                                      //~v20mI~
static char *Sxprintcmd="XPRINT.EXE";                           //~v05aR~
#endif //!UNX                                                      //~v20mI~
static char  Sshellicmd[]="prompt $p$l";                        //~v063R~
#define UP 1                                                       //~v09UI~
static UCHAR Sunpdispchartblj[256]={                               //~v09UI~
//      0  1  2  3  4  5  6  7   8  9  a  b  c  d  e  f            //~v09UM~
//#ifdef AIX                                                       //~v304R~
#ifdef UNX                                                         //~v304I~
	#ifdef AAA                                                     //~vb3vI~
        UP,UP,UP,UP,UP,UP,UP,UP, UP,UP,UP,UP,UP,UP,UP,UP, //00     //~v304I~
        UP,UP,UP,UP,UP,UP,UP,UP, UP,UP,UP,UP,UP,UP,UP,UP, //10     //~v304I~
	#else                                                          //~vb3vI~
        UP, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //00 UP:00//~vb3vI~
         0, 0,UP, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0,UP,UP, //10 12,1e,1f id utfwcwidth=2(avoid to rep to ".")//~vb3vR~
    #endif                                                         //~vb3vI~
#else                                                              //~v304I~
        UP, 0, 0, 0, 0, 0, 0, 0, UP, 0,UP, 0,UP,UP, 0, 0, //00     //~v09UR~
         0,UP, 0,UP, 0, 0, 0, 0, UP, 0, 0, 0, 0, 0, 0, 0, //10     //~v09UI~
#endif                                                             //~v304I~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //20     //~v09UI~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //30     //~v09UI~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //40     //~v09UI~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //50     //~v09UI~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //60     //~v09UI~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0,UP, //70  *  //~v09UI~
        UP, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //80  *  //~v09UI~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //90     //~v09UI~
        UP, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //a0     //~v09UI~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //b0     //~v09UI~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //c0     //~v09UI~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //d0     //~v09UI~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //e0     //~v09UI~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0,UP,UP,UP};//f0  *  //~v09UI~
static UCHAR Sunpdispchartble[256]={                               //~v09UI~
//      0  1  2  3  4  5  6  7   8  9  a  b  c  d  e  f            //~v09UI~
#ifdef UNX                                                         //~v304I~
//#ifdef LNX                                                       //~v51DR~
//        UP, 0, 0, 0, 0, 0, 0, 0, UP,UP,UP, 0,UP,UP,UP,UP, //00   //~v51DR~
//         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0,UP, 0, 0, 0, 0, //10   //~v51DR~
//#else                                                            //~v51DR~
	#ifdef AAA                                                     //~vb3vI~
        UP,UP,UP,UP,UP,UP,UP,UP, UP,UP,UP,UP,UP,UP,UP,UP, //00     //~v304R~
        UP,UP,UP,UP,UP,UP,UP,UP, UP,UP,UP,UP,UP,UP,UP,UP, //10     //~v304I~
	#else                                                          //~vb3vI~
        UP, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //00     //~vb3vI~
         0, 0,UP, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0,UP,UP, //10 12,1e,1f id utfwcwidth=2(avoid to rep to ".")//~vb3vI~
    #endif                                                         //~vb3vI~
//#endif                                                           //~v51DR~
#else                                                              //~v19mI~
        UP, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //00     //~v09UI~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //10     //~v09UI~
#endif                                                             //~v19mI~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //20     //~v09UI~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //30     //~v09UI~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //40     //~v09UI~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //50     //~v09UI~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //60     //~v09UI~
#ifdef UNX                                                         //~v304I~
#ifdef LNX                                                         //~v19mI~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0,UP, //70   7f=delete//~v19mI~
#else                                                              //~v304I~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0,UP, //70   7f=delete//~v304I~
#endif                                                             //~v304I~
#else                                                              //~v19mI~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //70     //~v09UI~
#endif                                                             //~v19mI~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //80     //~v09UI~
#ifdef UNX                                                         //~v304I~
#ifdef LNX                                                         //~v19mI~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0,UP, 0, 0, 0, 0, //90   9b=1b?//~v19mI~
#else                                                              //~v304I~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0,UP, 0, 0, 0, 0, //90   9b=1b?//~v304I~
#endif                                                             //~v304I~
#else                                                              //~v19mI~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //90     //~v09UI~
#endif                                                             //~v19mI~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //a0     //~v09UI~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //b0     //~v09UI~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //c0     //~v09UI~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //d0     //~v09UI~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //e0     //~v09UI~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0,UP};//f0  *  //~v09UI~
//** for wxe                                                       //~v500I~
static UCHAR Sunpdispchartblj_wxe[256]={                           //~v500I~
//jpn   0  1  2  3  4  5  6  7   8  9  a  b  c  d  e  f            //~v500I~
//      UP, 0, 0, 0, 0, 0, 0, 0, UP, 0,UP, 0,UP,UP, 0, 0, //00     //~v500I~//~va6RR~
#ifdef XXE                                                         //~va6RI~
        UP, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //00 UP:00//~va6RI~
#else                                                              //~va6RI~
        UP, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0,UP,UP, 0, 0, //00 UP:00,0c,0d//~va6RI~
#endif                                                             //~va6RI~
//       0,UP, 0,UP, 0, 0, 0, 0, UP, 0, 0, 0, 0, 0, 0, 0, //10     //~v500I~//~va6RR~
#ifdef XXE                                                         //~va6RI~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //10     //~va6RI~
#else                                                              //~va6RI~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0,UP, 0, 0, 0, //10 UP:1c//~va6RI~
#endif                                                             //~va6RI~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //20     //~v500I~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //30     //~v500I~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //40     //~v500I~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //50     //~v500I~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //60     //~v500I~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0,UP, //70  *  //~v500I~
        UP, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //80  *  //~v500I~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //90     //~v500I~
        UP, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //a0     //~v500I~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //b0     //~v500I~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //c0     //~v500I~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //d0     //~v500I~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //e0     //~v500I~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0,UP,UP,UP};//f0  *  //~v500I~
static UCHAR Sunpdispchartble_wxe[256]={                           //~v500I~
//eng   0  1  2  3  4  5  6  7   8  9  a  b  c  d  e  f            //~v500I~
        UP, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //00     //~v500I~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //10     //~v500I~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //20     //~v500I~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //30     //~v500I~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //40     //~v500I~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //50     //~v500I~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //60     //~v500I~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //70     //~v500I~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //80     //~v500I~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //90     //~v500I~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //a0     //~v500I~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //b0     //~v500I~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //c0     //~v500I~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //d0     //~v500I~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, //e0     //~v500I~
         0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0,UP};//f0  *  //~v500I~
#undef UP                                                          //~v09UI~
//*******************************************************
//*global init before parm/ini process                          //~v031R~
//*parm:none
//*ret :none
//*******************************************************
void gblinit(void)
{
#ifdef UNX                                                         //~v19TI~
	uid_t uid;                                                     //~v19TI~
	gid_t gid;                                                     //~v19TI~
//  long hostid;                                                   //~v64dR~
    char *pc;                                                      //~v64bI~
#endif//UNX                                                        //~v19TI~
//****************************
	Gversion=VER;
    Gverdate=__DATE__;
    Gcomparecmdf=umalloc(sizeof(COMPARETOOL));                     //~v76gI~
    strcpy(Gcomparecmdf,COMPARETOOL);   //default xfc              //~v76gI~
    Gcomparecmdd=umalloc(sizeof(COMPARETOOLDIR));                  //~v76gI~
    strcpy(Gcomparecmdd,COMPARETOOLDIR);    //default xdc          //~v76gI~
    Ggrepcmd=umalloc(sizeof(GREPTOOL));                            //~v76gI~
    strcpy(Ggrepcmd,GREPTOOL);    //default xdc                    //~v76gI~
                                                                   //~v19TI~
#ifdef UNX                                                         //~v19TI~
	ugetugid(&uid,&gid);	//get user-id                          //~v19TI~
//  Guserid=uid;                                                   //~v19TI~//~vb2DR~
    Guserid=(int)uid;                                              //~vb2DI~
//  Ggroupid=gid;                                                  //~v19TI~//~vb2DR~
    Ggroupid=(int)gid;                                             //~vb2DI~
	ugethostname(Ghostname,sizeof(Ghostname)-1);	//get hostname //~v41vI~
	strcpy(Ghostname2,Ghostname);		//to drop after "."        //~v64dI~
    if (pc=strchr(Ghostname2,'.'),pc)                              //~v64dR~
    	*pc=0;                                                     //~v64dR~
//  hostid=gethostid();                                            //~v64dR~
//  if ((hostid>>24)==127 || (hostid>>16)==127) //linux return 007f0100//~v64dR~
//  	Glocalhostsw=1;                                            //~v64dR~
//  UCBITON(Gscrstatus,GSCRSDIRUGNAME);	//username display as init //~v40vR~
#ifdef UTF8SUPPH                                                   //~va0nI~
  #ifndef ARMXXE                                                   //~va90I~
    if (!(ukbdl_gettermsim() & TERM_UNDERTN))                      //~va0nR~
  #endif //ARMXXE                                                  //~vac7I~
  		Glocalhostsw=1;                                            //~va0nI~
//#endif //ARMXXE                                                  //~va90I~//~vac7R~
#endif                                                             //~va0nI~
#endif//UNX                                                        //~v19TI~
    Gunpdispchartblj=Sunpdispchartblj;                             //~v09UI~
    Gunpdispchartble=Sunpdispchartble;                             //~v09UI~
    Gunpdispchartblj_wxe=Sunpdispchartblj_wxe;                     //~v500R~
    Gunpdispchartble_wxe=Sunpdispchartble_wxe;                     //~v500R~
    Gunpdispchar[1]=UNPCHARDISPXE;	//english mode                 //~v09UI~
    Gunpdispchar[2]=UNPCHARDISPXJ;  //japanese mode                //~v09UI~
#ifdef LNX                                                         //~v21iI~
//  Gunpdispchar[3]=DBCSSPACEDISP0; //dbcs space disp (jpn/euc only)//~v51DR~
    Gunpdispchar[3]=DBCSSPACEDISP;  //dbcs space disp (jpn only)   //~v51DI~
    Gufile_opt|=GFILEOPT_LNXMTOOL;  //disket support               //~v40AI~
#else                                                              //~v21iI~
    Gunpdispchar[3]=DBCSSPACEDISP;  //dbcs space disp (jpn only)   //~v09XI~
    Gufile_opt|=GFILEOPT_LNXMTOOL;  //disket support               //~v48jI~
#endif                                                             //~v21iI~
#ifdef UNX                                                         //~vaa0I~
    Gufile_opt|=GFILEOPT_WILDCARDNAMEOK;//udirlist accept wildcard member name//~vaa0M~
#endif//UNX                                                        //~vaa0I~
                                                                   //~v21iI~
#ifdef AIX                                                         //~v305I~
	gblkon(KON_TABDISP);                                           //~v305I~
#else                                                              //~v305I~
#ifdef LNX                                                         //~v51DI~
	gblkon(KON_TABDISP);                                           //~v51DI~
#else                                                              //~v51DI~
    Gtabdispchar[0]=TABCHARDISPX1E;	//english mode                 //~v09XR~
    Gtabdispchar[1]=TABCHARDISPX2E;	//english mode                 //~v09XR~
    Gtabdispchar[2]=TABCHARDISPX1J;	//english mode                 //~v09XR~
    Gtabdispchar[3]=TABCHARDISPX2J;	//english mode                 //~v09XR~
#endif                                                             //~v51DI~
#endif                                                             //~v305I~
//#ifdef WXE                                                         //~v500I~//~v79XR~
#ifdef WXEXXE                                                      //~v79XI~
//  if (UCBITCHK(Gscrstatus,GSCRSDBCS))                            //~v500I~//~v79XR~
    if (XE_ISDBCSJ())                                              //~v79XI~
    	Gunpdispchartbl=Gunpdispchartblj_wxe;                      //~v500I~
	else                                                           //~v500I~
    	Gunpdispchartbl=Gunpdispchartble_wxe;                      //~v500I~
#else                                                              //~v500I~
//  if (UCBITCHK(Gscrstatus,GSCRSDBCS))                            //~v79zR~
    if (XE_ISDBCSJ())                                              //~v79zR~
    	Gunpdispchartbl=Gunpdispchartblj;                          //~v09UR~
	else                                                           //~v09UI~
    	Gunpdispchartbl=Gunpdispchartble;                          //~v09UR~
#endif                                                             //~v500I~
	UTRACED("Gunpdispchartbl",Gunpdispchartbl,256);                //~vb2DI~
	UTRACED("Gunpdispchar",Gunpdispchar,4);                        //~vb2DI~
    strcpy(Gfixcidid,"CID:");                                   //~v031I~
    UCBITON(Gopt3,GOPT3DIRLISTINDENT    //dir indent listing    //~v05aR~
                 |GOPT3UNDELFREE); 		//delete mode free      //~v05aI~
    UCBITON(Gopt4,GOPT4XLINENO);	//lineno by hex for bin file   //~v174I~
#ifdef AIX                                                         //~v43zI~
    UCBITON(Gopt4,GOPT47BIT);		//initial 7bit mode for AIX    //~v43zI~
#endif                                                             //~v43zI~
                                                                   //~v174I~
    Ginitscroll[GSCROLLBROWSE]=UPCSCROLLHALF;                   //~v031R~
    Ginitscroll[GSCROLLEDIT  ]=UPCSCROLLHALF;                   //~v031I~
    Ginitscroll[GSCROLLDIR   ]=UPCSCROLLHALF;                   //~v031R~
    Ginitscroll[GSCROLLCMD   ]=UPCSCROLLHALF;                   //~v06nI~
    Ginitscroll[GSCROLLFKT   ]=UPCSCROLLHALF;                      //~v71vI~
//  UCBITON(Gopt,GOPTPOPUPERRMSG);	//not popup err msgsw       //~v031R~
	Gxprintcmd0=Gxprintcmd=Sxprintcmd;             //default print pgm//~v05aR~
    UCBITON(Gprocstatus,GPROCSXPRINT);//first time set default     //~v0g0I~
	Gprintcmd=0;                       //default print pgm      //~v051R~
    Gshellicmd=Gshellicmd0=Sshellicmd; //default sub shell init cmd//~v063R~
    Glinenosze=ULHLINENOSZ;                                     //~v069I~
    Glinenoszb=ULHLINENOSZ;                                     //~v069I~
    Glinenoszc=ULHLINENOSZ0; 	//cmd stdout                    //~v06nI~
                                                                   //~v176I~
    Gfhwidth=BINFILE_LINEWIDTH; //default width                    //~v176I~
    Gfhxwidth=BINFILE_HEXLINEWIDTH; //default width                //~v440I~
                                                                   //~v176I~
//*screen color pallette asign                                     //~v075R~
#ifdef AIX                                    //for dtterm,aixterm follow to dtterm//~v48sI~
	Gpallassigntbl[PAL_TITLEFG  ]= PALNO_GB;	//title fg         //~v48sI~
	Gpallassigntbl[PAL_TITLEBG  ]= PALNO_BLACK; //title bg         //~v48sI~
#else                                                              //~v48sI~
	Gpallassigntbl[PAL_TITLEFG  ]= PALNO_HRGB;	//title fg         //~v075R~
	Gpallassigntbl[PAL_TITLEBG  ]= PALNO_B;  	//title bg         //~v075R~
#endif                                                             //~v48sI~
	Gpallassigntbl[PAL_FRAMEFG  ]= PALNO_RGB;	//frame fg         //~v075R~
	Gpallassigntbl[PAL_FRAMEBG  ]= PALNO_BLACK;	//frame bg         //~v075R~
	Gpallassigntbl[PAL_BLINENOFG]= PALNO_G;  	//browse lineno fg //~v075R~
	Gpallassigntbl[PAL_BLINENOBG]= PALNO_BLACK;	//browse lineno bg //~v075R~
	Gpallassigntbl[PAL_BCLIENTFG]= PALNO_RGB;	//browse client fg //~v075R~
	Gpallassigntbl[PAL_BCLIENTBG]= PALNO_BLACK;	//browse client bg //~v075R~
	Gpallassigntbl[PAL_ELINENOFG]= PALNO_G;  	//edit   lineno fg //~v075R~
	Gpallassigntbl[PAL_ELINENOBG]= PALNO_BLACK;	//edit   lineno bg //~v075R~
    Gpallassigntbl[PAL_ECLIENTFG]= PALNO_HRG;	//edit   client fg (high yellow)//~v075R~
	Gpallassigntbl[PAL_ECLIENTBG]= PALNO_BLACK;	//edit   client bg //~v075R~
	Gpallassigntbl[PAL_DLINCMDFG]= PALNO_HRG;	//dirlist linecmd fg//~v075R~
	Gpallassigntbl[PAL_DLINCMDBG]= PALNO_BLACK;	//dirlist linecmd bg3//~v075R~
	Gpallassigntbl[PAL_DLINENOFG]= PALNO_G;  	//dirlist lineno fg//~v075R~
	Gpallassigntbl[PAL_DLINENOBG]= PALNO_BLACK;	//dirlist lineno bg//~v075R~
	Gpallassigntbl[PAL_DCLIENTFG]= PALNO_RGB;	//dirlist client fg//~v075R~
	Gpallassigntbl[PAL_DCLIENTBG]= PALNO_BLACK;	//dirlist client bg//~v075R~
	Gpallassigntbl[PAL_CLINENOFG]= PALNO_G;  	//cmd result lineno fg//~v075R~
	Gpallassigntbl[PAL_CLINENOBG]= PALNO_BLACK;	//cmd result lineno bg//~v075R~
//  Gpallassigntbl[PAL_CCLIENTFG]= PALNO_HRG;	//cmd result client fg (high yellow)//~v0awR~
    Gpallassigntbl[PAL_CCLIENTFG]= PALNO_HRGB;  //cmd result client fg (high white)//~v0awI~
	Gpallassigntbl[PAL_CCLIENTBG]= PALNO_HBLACK;//cmd result client bg//~v075R~
//*screen color pallette RGB(default for window mode)              //~v075R~
    Gdefpallette[ 0]=  0;              //0(black) 0                //~v075R~
    Gdefpallette[ 1]=  1;              //1(B)     1                //~v075R~
    Gdefpallette[ 2]=  2;              //2(G)     2                //~v075R~
    Gdefpallette[ 3]=  3;              //3(GB)    3                //~v075R~
    Gdefpallette[ 4]=  4;              //4(R)     4                //~v075R~
    Gdefpallette[ 5]=  5;              //5(RB)    5                //~v075R~
    Gdefpallette[ 6]=  20;             //6(RG)   20(brown)         //~v075R~
    Gdefpallette[ 7]=  7;              //7(RGB)   7                //~v075R~
    Gdefpallette[ 8]=  56;             //8(gray) 56(gray)          //~v075R~
    Gdefpallette[ 9]=  57;             //9(HB)   57                //~v075R~
    Gdefpallette[10]=  58;             //10(HG)  58                //~v075R~
    Gdefpallette[11]=  59;             //11(HGB) 59                //~v075R~
    Gdefpallette[12]=  60;             //12(HR)  60                //~v075R~
    Gdefpallette[13]=  61;             //13(HRB) 61                //~v075R~
    Gdefpallette[14]=  62;             //14(HRG) 62(light yellow)  //~v075R~
    Gdefpallette[15]=  63;             //15(HRGB)no change         //~v075R~
                                                                   //~v076I~
//*screen color pallette RGB                                       //~v075I~
//#ifdef WXE                                                       //~v500R~
//    memcpy(Gpallette,Gdefpallette,sizeof(Gpallette));//getstate is nop//~v500R~
//#else                                                            //~v500R~
    memset(Gpallette,0xff,16);                                     //~v075I~
    Gpallette[0]=  0;//black is fixed                              //~v20sI~
#ifndef XXE                                                        //~v64dI~
    Gpallette[14]=  0x06;//fullscreen only 14(HRG) 62(light yellow)->6(yellow)//~v075I~
#endif                                                             //~v64dI~
//#endif                                                           //~v500R~
                                                                   //~v20hI~
//#ifdef UNX                                                       //~v49jR~
//    udoseditnameopt(DEN_UNIX);//unix like wildcard process       //~v49jR~
//#endif //UNX                                                     //~v49jR~
		optsetdisplayeolid();	//default eolid display char       //~v47dI~
		optsetdisplayeolcontid();	//default eolid display char   //~v60mI~
    return;
}//gblinit
#ifdef UNX                                                         //~v19xI~
//*******************************************************          //~v19xI~
//*set keyboard option for linux                                   //~v19xI~
//*ret :none                                                       //~v19xI~
//*******************************************************          //~v19xI~
void xesetkbdopt(int Popt)                                         //~v19xI~
{                                                                  //~v19xI~
	Gkbdopt=Popt;                                                  //~v19xI~
    return;                                                        //~v19xI~
}//xesetkbdopt(int Popt)                                           //~v19xI~
//*******************************************************          //~v305I~
//*ajust printable for KON mode                                    //~v305I~
//*ret :none                                                       //~v305I~
//*******************************************************          //~v305I~
void gblkon(int Popt)                                              //~v305I~
{                                                                  //~v305I~
//******************                                               //~v305I~
	switch(Popt)                                                   //~v305I~
    {                                                              //~v305I~
    case KON_TABDISP:                                              //~v305R~
#ifdef LNX                                                         //~va47R~
	    Gtabdispchar[0]=DEFAULT_ALTDISPCH;           	//english mode//~va47R~
    	Gtabdispchar[1]=DEFAULT_ALTDISPCH;           	//english mode//~va47R~
   		Gtabdispchar[2]=DEFAULT_ALTDISPCH;           	//japaese TAB//~va47R~
    	Gtabdispchar[3]=DEFAULT_ALTDISPCH;           	//japanese TAB PADDING//~va47R~
#else                                                              //~va47R~
	    Gtabdispchar[0]='^';           	//english mode             //~v305I~
    	Gtabdispchar[1]=',';           	//english mode             //~v305I~
   		Gtabdispchar[2]='^';           	//english mode             //~v305I~
    	Gtabdispchar[3]=',';           	//english mode             //~v305I~
#endif                                                             //~va47R~
    	Gfiletabdisp1=Gtabdispchar[0];//eng1    file_init is before scr_init//~v304I~
    	Gfiletabdisp2=Gtabdispchar[1];//eng2                       //~v304I~
		break;                                                     //~v305R~
    case KON_UNPCHAR:                                              //~v304I~
#define UP 1                                                       //~v304I~
        memset(Gunpdispchartblj,UP,0x20);                          //~v304I~
        memset(Gunpdispchartble,UP,0x20);                          //~v304I~
#undef UP                                                          //~v304I~
        Gunpdispchar[0]=UNPCHARDISPXE0;  //english mode            //~v304R~
        Gunpdispchar[1]=UNPCHARDISPXE0;  //english mode            //~v304I~
        Gunpdispchar[2]=UNPCHARDISPXJ0;  //japanese mode           //~v304I~
        Gunpdispchar[3]=DBCSSPACEDISP0;  //dbcs space disp (jpn only)//~v304I~
		break;                                                     //~v304I~
    }                                                              //~v305I~
	optsetdisplayeolid();	//default eolid display char after kon detected//~v47dI~
	optsetdisplayeolcontid();	//default eolid display char after kon detected//~v60mI~
    return;                                                        //~v305I~
}//gblkon                                                          //~v47dR~
#endif                                                             //~v19xI~
#ifdef WXE                                                         //~v500I~
//*******************************************************          //~v500I~
//*global term from wxexei                                         //~v500I~//~vbCBR~
//   called from xe.c malloc chk                                   //~v500I~
//*parm:none                                                       //~v500I~
//*ret :none                                                       //~v500I~
//*******************************************************          //~v500I~
void gblcpchng(int Pjpnmode)                                       //~v500I~
{                                                                  //~v500I~
	int eopt;                                                      //~v500I~
//****************************                                     //~v500I~
	if (Pjpnmode)                                                  //~v500I~
      if (UCBITCHK(Gotherstatus,GOTHERS_N9PARM))                   //~va73I~
    	eopt=UERR_FORCE_ENGLISH;                                   //~va73I~
      else                                                         //~va73I~
    	eopt=0;                                                    //~v500I~
    else                                                           //~v500I~
    	eopt=UERR_FORCE_ENGLISH;                                   //~v500I~
    uerrmsg_init(0,0,eopt);                                        //~v500I~
                                                                   //~v500I~
    if (Pjpnmode)	//sbcs mode                                    //~v500I~
    {                                                              //~v500I~
	    UCBITON(Gscrstatus,GSCRSDBCS);                             //~v500I~
    	Gunpdispchartbl=Gunpdispchartblj_wxe;                      //~v500I~
    	Gfiletabdisp1=Gtabdispchar[2];//jpn1                       //~v500I~
    	Gfiletabdisp2=Gtabdispchar[3];//jpn2                       //~v500I~
	    Gunpdispchar[0]=Gunpdispchar[2];//english mode             //~v500I~
    }                                                              //~v500I~
    else                                                           //~v500I~
    {                                                              //~v500I~
	    UCBITOFF(Gscrstatus,GSCRSDBCS);                            //~v500I~
    	Gunpdispchartbl=Gunpdispchartble_wxe;                      //~v500I~
    	Gfiletabdisp1=Gtabdispchar[0];//eng1                       //~v500I~
    	Gfiletabdisp2=Gtabdispchar[1];//eng2                       //~v500I~
	    Gunpdispchar[0]=Gunpdispchar[1];//english mode             //~v500I~
    }                                                              //~v500I~
    UTRACEP("%s:Pjpnmode=%d,Gscrstatus=0x%04x\n",UTT,Pjpnmode,Gscrstatus);//+vbCBR~
}//gblcpchng                                                       //~v500I~
#endif                                                             //~v500I~
//*******************************************************       //~v051I~
//*global term                                                  //~v051I~
//   called from xe.c malloc chk                                //~v051I~
//*parm:none                                                    //~v051I~
//*ret :none                                                    //~v051I~
//*******************************************************       //~v051I~
void gblterm(void)                                              //~v051I~
{                                                               //~v051I~
//****************************                                  //~v051I~
	if (Gxprintcmd!=(UCHAR*)Sxprintcmd)          //ini specified   //~v095R~
    	ufree(Gxprintcmd);                                      //~v05aI~
	if (Gprintcmd)                       //default print pgm    //~v051R~
    	ufree(Gprintcmd);                                       //~v051R~
	if (Gshellicmd!=Gshellicmd0)                       //default print pgm//~v063I~
    	ufree(Gshellicmd);                                      //~v063I~
	ini2term();			//free print cmd string                    //~v0fzI~
#ifndef DOSDOS                                                     //~v50kI~
	ucp932term();                                                  //~v50kI~
#endif                                                             //~v50kI~
	fcmd2term();                                                   //~vbCBI~
    return;                                                     //~v051I~
}//gblterm                                                      //~v051I~
